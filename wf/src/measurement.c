#include "header.h"

float frequency_tmp = NAN;
//float frequency_static = -1;
float frequency_irq = -1.0f;
float frequency_high = -1.0f;
unsigned int freq_mutex = false;


/*****************************************************/
//Пошук нового каналу для оцифровки
/*****************************************************/
inline void find_new_ADC_canal_to_read(unsigned int command_word_adc_diff, unsigned int *point_active_index_command_word_adc)
{
  unsigned int command_word_adc_diff_tmp = command_word_adc_diff;
  unsigned int command_word_adc_diff_fapch = command_word_adc_diff_tmp & maska_canaliv_fapch;
    
  if (
      ((status_adc_read_work & DATA_VAL_READ) != 0) &&
      (command_word_adc_diff_fapch != 0) 
     )  
  {
    command_word_adc_diff_tmp = command_word_adc_diff_fapch;
  }
  else
  {
    command_word_adc_diff_tmp &= (unsigned int)(~maska_canaliv_fapch);
  }
  
  while ((command_word_adc_diff_tmp & (1 << (*point_active_index_command_word_adc))) == 0)
  {
    /*
    Ще не знайдено каналу, який треба оцифровувати
    */
    *point_active_index_command_word_adc = (*point_active_index_command_word_adc + 1) % NUMBER_INPUTs_ADCs;
  }
}
/*****************************************************/

/*****************************************************/
//Управління читанням даних з АЦП
/*****************************************************/
void control_reading_ADCs(void)
{
  //Обновляємо робоче командне слово і вибираємо які канали треба оцифровувати
  if (adc_DATA_VAL_read != 0)
  {
    adc_DATA_VAL_read = false;
    status_adc_read_work |= DATA_VAL_READ;
      
    /*
    Канали по яких буде розраховуватися частота мають оцифровуватися як 
    омога ближче до спрацювання таймеру подачі команди оцифровки
    */
    command_word_adc      &= (unsigned int)(~maska_canaliv_fapch);
    command_word_adc_work &= (unsigned int)(~maska_canaliv_fapch);
        
    command_word_adc |= READ_DATA_VAL;
  }

  if (adc_TEST_VAL_read != 0) 
  {
    adc_TEST_VAL_read = false;
    status_adc_read_work |= TEST_VAL_READ;
      
    command_word_adc |= READ_TEST_VAL;
  }
  
  unsigned int command_word_adc_diff = command_word_adc ^ command_word_adc_work;
  if (command_word_adc_diff != 0)
  {
    /*
    Є канали, які чекають на оцифровку
    */
    find_new_ADC_canal_to_read(command_word_adc_diff, &active_index_command_word_adc);
      
    /*
    Зараз active_index_command_word_adc вказує у масиві input_adc на канал, 
    який треба оцифрувати
    */
      
    /*
    Визначаємо, який зараз активний АЦП
    */
    unsigned int active_adc_old = ((GPIO_SELECT_ADC->ODR & GPIO_SELECTPin_ADC) == 0) ? 1 : 2;

    /*
    Визначаємо, який зараз треба активовувати АЦП і які дані треба передати
    */
    unsigned int active_adc_new = input_adc[active_index_command_word_adc][0];
    unsigned int command_word = input_adc[active_index_command_word_adc][1];
    
    //Визначаємо наступний стан
    if (
        (state_reading_ADCs == STATE_READING_ADCs_NONE) ||
        (state_reading_ADCs == STATE_READING_READ     )
       )
    {
      state_reading_ADCs = STATE_READING_WRITE;
      /*
      Вибирваємо відповідний АЦП
      */
      switch (active_adc_new)
      {
      case 1:
        {
          //АЦП1
          GPIO_SELECT_ADC->BSRRH = GPIO_SELECTPin_ADC;
          break;
        }
        case 2:
        {
          //АЦП2
          GPIO_SELECT_ADC->BSRRL = GPIO_SELECTPin_ADC;
          break;
        }
      default:
        {
          //Якщо сюди дійшла програма, значить відбулася недопустива помилка, тому треба зациклити програму, щоб вона пішла на перезагрузку
          total_error_sw_fixed();
        } 
      }
    }
    else
    {
      if (active_adc_old == active_adc_new)
      {
        state_reading_ADCs = STATE_READING_WRITE_READ;
      }
      else
      {
        state_reading_ADCs = STATE_READING_READ;
        command_word = 0;
      }
    }
    
    if (command_word != 0)
    {
      /*
      Помічаємо, що зараз будемо нове командне слово передавати
      */
      command_word_adc_work |= (1 << active_index_command_word_adc);
    }

    //Передаємо командне слово
    while ((SPI_ADC->SR & SPI_I2S_FLAG_TXE) == RESET);      //Очікуємо, поки SPI стане вільним
		tick_output_adc_p = TIM5->CNT;													//Фіксуємо час початку оцифровки
    GPIO_SPI_ADC->BSRRH = GPIO_NSSPin_ADC;                  //Виставляємо chip_select
    SPI_ADC->DR = (uint16_t)command_word;                   //Відправляємо командне число
    
    channel_answer = channel_request;
    channel_request = (active_adc_new - 1)*NUMBER_CANALs_ADC + ((command_word >> 10) & 0xf);
  }
  else 
  {
    if (
        (state_reading_ADCs == STATE_READING_READ     ) ||
        (state_reading_ADCs == STATE_READING_ADCs_NONE)
       )
    {
      //Усі канали вже оцифровані
      state_reading_ADCs = STATE_READING_ADCs_NONE;

      command_word_adc = 0;
      command_word_adc_work = 0;
      active_index_command_word_adc = 0;
    }
    else
    {
      /*
      Треба ще отримати значення з останнього каналуна, який зараз тільки
      щоно оцифровувався
      */
      state_reading_ADCs = STATE_READING_READ;
      while ((SPI_ADC->SR & SPI_I2S_FLAG_TXE) == RESET);      //Очікуємо, поки SPI стане вільним
			tick_output_adc_p = TIM5->CNT;													//Фіксуємо час початку оцифровки
      GPIO_SPI_ADC->BSRRH = GPIO_NSSPin_ADC;                  //Виставляємо chip_select
      SPI_ADC->DR = 0;                                        //Відправляємо число (але так, щоб нове контрольне слово не записувалося)
    
      channel_answer = channel_request;
    }
  }
}
/*****************************************************/

/*************************************************************************
Опрацьовуємо інтеграільні величини
 *************************************************************************/
void operate_test_ADCs(void)
{
  /*******************************************************
  Вираховування середнього значення контрольних точок
  *******************************************************/
  unsigned int temp;

  //VREF для АЦП
  _SET_BIT(clear_diagnostyka, ERROR_VREF_ADC_TEST_COARSE_BIT);
  unsigned int vref_tmp = 0;
  for (unsigned int i = 0; i < NUMBER_VREF_ADC; i++)
  {
    temp = output_adc[index_VREF_ADC[i]].value;
    vref_adc_averange_sum[i] += temp;
    vref_adc_averange_sum[i] -= vref_adc_moment_value[i][index_array_of_one_value];
    vref_adc_moment_value[i][index_array_of_one_value] = temp;
    vref_tmp += vref_adc_averange[i] = vref_adc_averange_sum[i] >> VAGA_NUMBER_POINT;
    if ((temp < 0x614) || (temp > 0x9EB)) _SET_BIT(set_diagnostyka, ERROR_VREF_ADC_TEST_COARSE_BIT);
  }
  vref_adc = vref_tmp / NUMBER_VREF_ADC;
  
  //Всі масиви одної величини ми вже опрацювали  
  if((++index_array_of_one_value) == NUMBER_POINT)
    index_array_of_one_value = 0;
  else if (index_array_of_one_value > NUMBER_POINT)
  {
    //Якщо сюди дійшла програма, значить відбулася недопустива помилка, тому треба зациклити програму, щоб вона пішла на перезагрузку
    total_error_sw_fixed();
  }
  /*******************************************************/
}
/*************************************************************************/

/*************************************************************************
Опрацьовуємо дані для перетворення Фур'є
 *************************************************************************/
void Fourier(void)
{
  unsigned int index_period_array_tmp = index_period_array;
  int *p_data_sin = data_sin[index_period_array_tmp];
  int *p_data_cos = data_cos[index_period_array_tmp];

  unsigned int i_ort_tmp = 0;
  for (size_t i = 0; i < NUMBER_ANALOG_CANALES; ++i)
  {
    //Зчитуємо миттєве значення яке треба опрацювати
    int temp_value_1 = ADCs_data[i];
    
    static const uint32_t garm[2] = {1, 3};
    for (size_t j = 0; j < 2; j++)
    {
      int temp_value_2;

      //Ортогональні SIN
      ortogonal_irq[i_ort_tmp] -= *p_data_sin;
      temp_value_2 = (int)((float)temp_value_1*sin_data_f[(garm[j]*index_period_array_tmp) & 0x1f]);
      *p_data_sin = temp_value_2;
      p_data_sin++;
      ortogonal_irq[i_ort_tmp++] += temp_value_2;
    
      //Ортогональні COS
      ortogonal_irq[i_ort_tmp] -= *p_data_cos;
      temp_value_2 = (int)((float)temp_value_1*sin_data_f[(garm[j]*index_period_array_tmp + (NUMBER_POINT >> 2)) & 0x1f]);
      *p_data_cos = temp_value_2;
      p_data_cos++;
      ortogonal_irq[i_ort_tmp++] += temp_value_2;
      
      if ((i == I_Umn) || (i == I_Ubp)) break;
    }
  }
  if((++index_period_array_tmp) >= NUMBER_POINT) index_period_array_tmp = 0;
  index_period_array = index_period_array_tmp;

  //Копіювання для інших систем
  unsigned int bank_ortogonal_tmp = bank_ortogonal;
  for(unsigned int i = 0; i < (2*(NUMBER_ANALOG_CANALES + 2)); i++ ) ortogonal[i][bank_ortogonal_tmp] = ortogonal_irq[i];
}
/*************************************************************************/

/*************************************************************************
Детектор частоти для каналів групи 1
*************************************************************************/
//#pragma optimize=none
void fapch(void)
{
  unsigned int bank_measurement_high_tmp = bank_measurement_high;
  int index_1 = -1;
  unsigned int maska_canaliv_fapch_tmp = 0;
  
  /*****
  Шучаємо сигнал по якому будемо розраховувати частоту
  *****/  
  if (measurement_high[bank_measurement_high_tmp][IM_Umn] >= PORIG_FOR_FAPCH)
  {
    index_1 = INDEX_PhK_Umn;
    maska_canaliv_fapch_tmp = READ_Umn;
  }
  else if (measurement_high[bank_measurement_high_tmp][IM_Ubp] >= PORIG_FOR_FAPCH)
  {
    index_1 = INDEX_PhK_Ubp;
    maska_canaliv_fapch_tmp = READ_Ubp;
  }
  maska_canaliv_fapch = maska_canaliv_fapch_tmp;
  /*****/

  /*****/
  //Частота
  /*****/
  static uint32_t ind_freq;
  static size_t count;
  uint32_t step_timer_adc_tmp = step_timer_adc;
  if (
      (index_1 >= 0) &&
      (fix_perechid_cherez_nul[index_1] != 0)
     )   
  {
    count = 0;
    
    fix_perechid_cherez_nul[index_1] = 0;
    
    unsigned int delta_tick;
    long long tick_tmp;
    int delta_value;
    unsigned int tick_p, x1_tmp, x2_tmp;
      
    /*Знаходимо час переходу через 0 попереднього разу з врахуванням лінійної апроксимації*/
    delta_value = perechid_cherez_nul[index_1][0].y2 - perechid_cherez_nul[index_1][0].y1;
    x1_tmp = perechid_cherez_nul[index_1][0].x1;
    x2_tmp = perechid_cherez_nul[index_1][0].x2;
    if (x2_tmp > x1_tmp) delta_tick = x2_tmp - x1_tmp;
    else
    {
      long long delta_tick_64 = x2_tmp + 0x100000000 - x1_tmp;
      delta_tick = delta_tick_64;
    }
    tick_tmp = ((long long)perechid_cherez_nul[index_1][0].x1) - ((long long)perechid_cherez_nul[index_1][0].y1)*((long long)delta_tick)/((long long)delta_value);
    if (tick_tmp < 0) 
    {
      tick_tmp += 0x100000000;
      tick_p = (unsigned int)tick_tmp;
    }
    else
    {
      if (tick_tmp < 0x100000000) tick_p = (unsigned int)tick_tmp;
      else 
      {
        tick_tmp -= 0x100000000;
        tick_p = (unsigned int)tick_tmp;
      }
    }

    /*Знаходимо час переходу через 0 поточного разу з врахуванням лінійної апроксимації*/
    delta_value = perechid_cherez_nul[index_1][1].y2 - perechid_cherez_nul[index_1][1].y1;
    x1_tmp = perechid_cherez_nul[index_1][1].x1;
    x2_tmp = perechid_cherez_nul[index_1][1].x2;
    if (x2_tmp > x1_tmp) delta_tick = x2_tmp - x1_tmp;
    else
    {
      long long delta_tick_64 = x2_tmp + 0x100000000 - x1_tmp;
      delta_tick = delta_tick_64;
    }
    tick_tmp = ((long long)perechid_cherez_nul[index_1][1].x1) - ((long long)perechid_cherez_nul[index_1][1].y1)*((long long)delta_tick)/((long long)delta_value);
    if (tick_tmp < 0) 
    {
      tick_tmp += 0x100000000;
      tick_c = (unsigned int)tick_tmp;
    }
    else
    {
      if (tick_tmp < 0x100000000) tick_c = (unsigned int)tick_tmp;
      else 
      {
        tick_tmp -= 0x100000000;
        tick_c = (unsigned int)tick_tmp;
      }
    }
    /***/
      
    if (tick_c > tick_p) delta_tick = tick_c - tick_p;
    else
    {
      long long delta_tick_64 = tick_c + 0x100000000 - tick_p;
      delta_tick = delta_tick_64;
    }
    tick_period = delta_tick;
    
    /*****
    Розрахунок частоти
    *****/
    if (
        (tick_period <= MAX_TICK_PERIOD) &&
        (tick_period >= MIN_TICK_PERIOD)
       ) 
    {
      frequency_tmp = (float)MEASUREMENT_TIM_FREQUENCY/(float)tick_period;
			
			sum_freq_arr -= freq_arr[index_freq_arr];
			freq_arr[index_freq_arr] = frequency_tmp;
			sum_freq_arr += frequency_tmp;

			index_freq_arr = (index_freq_arr + 1) % N_F_AVER;

			if(freq_arr[index_freq_arr] > 0)
			{
				//Це означає, що весь масив для усереднення зкаповнений значеннями (немає випадку від'ємних чисел. щог означає, що частота тільки з'явилася)
        if (frequency_irq/*frequency_static*/ < 0) ++ind_freq;
				frequency_irq/*frequency_static*/ = sum_freq_arr / (float)N_F_AVER;
				unsigned int tick_period_tmp = (unsigned int)roundf((float)MEASUREMENT_TIM_FREQUENCY / frequency_irq/*frequency_static*/);
				
	      step_timer_adc_tmp = tick_period_tmp >> VAGA_NUMBER_POINT;
  	    if ((tick_period_tmp - (step_timer_adc_tmp << VAGA_NUMBER_POINT)) >= (1 << (VAGA_NUMBER_POINT - 1))) step_timer_adc_tmp++;
			}

    }
    else
    {
      step_timer_adc_tmp = TIM5_CCR1_2_VAL;
      if (tick_period > MAX_TICK_PERIOD) frequency_tmp = -2.0f; /*Частота нижче порогу визначеного константою MIN_FREQUENCY*/
      else frequency_tmp = -3.0f; /*Частота вище порогу визначеного константою MAX_FREQUENCY*/
      
      if (frequency_irq/*frequency_static*/ != frequency_tmp) ++ind_freq;
			frequency_irq/*frequency_static*/ = frequency_tmp;
    }
    /****/
  }
  else
  {
    if (index_1 < 0)
    {
      if (count == 0)
      {
        step_timer_adc_tmp = TIM5_CCR1_2_VAL;
        tick_c = TIM5->CNT;
        frequency_tmp = -1.0f; /*Частота не визначена*/
      
        if (frequency_irq/*frequency_static*/ != frequency_tmp) ++ind_freq;
        frequency_irq/*frequency_static*/ = frequency_tmp;
      }
      if (++count >= NUMBER_POINT) count = 0;
		}
    else count = 0;
  }
  if (ind_freq == 0) ind_freq = 1; /*нулем ідентифікатор бути не може, бо нуль означає, що частота не визначена*/
  /*****/
  
//  {
//    static unsigned int logic_f_0;
//    static int timer_count = -1;
//  
//    //Додаємо поточний тсан до попереднього
//    logic_f_0 |= (index_1 >= 0) << 0;
//  
//    if ((logic_f_0 & ((1u << 1) | (1u << 0))) == (1u << 0) /*01*/)
//    {
//      //Зафіксований перрехід 0->1
//      timer_count = 0;
//    }
//    if (timer_count >= 0)
//    {
//      if (++timer_count >= (5*NUMBER_POINT)) timer_count = -1;
//    }
//    if (timer_count < 0) frequency_irq = frequency_static;
//  
//    //Поточний стан переносимо у стан попередній для наступного проходу
//    logic_f_0 = (logic_f_0 & (1u << 0)) << 1;
//    
//  }
	
	if (!isnan(frequency_tmp))
	{
		//Нову вираховану частоту фіксуємо
		if (frequency_tmp < 0)
		{
			index_freq_arr = 0;
			for (size_t i = 0; i < N_F_AVER; ++i) freq_arr[i] = 0.0f;
			sum_freq_arr = 0;
		}
	
//		__f_ext const f_ext = {ind_freq*(frequency_irq >= 0), tick_c, frequency_irq}; 
//		f_ext_arr[index_f_ext] = f_ext;
//		if (++index_f_ext >= SIZE_F_EXT_ARR) index_f_ext = 0;
		
		frequency_tmp = NAN;
	}

  /*****/
  //ФАПЧ
  /*****/
  if (step_timer_adc != step_timer_adc_tmp)
  {
    //Треба змінити частоту дискретизації
    step_timer_adc = step_timer_adc_tmp;
  }
  
  if ((command_restart_monitoring_frequency & (1 << 0)) != 0)
  {
    frequency_min = 50;
    frequency_max = 50;
    
    command_restart_monitoring_frequency &= (unsigned int)(~(1 << 0));
  }
  else
  {
    if (frequency_irq>= 0)
    {
      if (frequency_irq > frequency_max) frequency_max = frequency_irq;
      if (frequency_irq < frequency_min) frequency_min = frequency_irq;
    }
  }
  /*****/
}
/*****************************************************/

/*****************************************************/
//Переривання від прийнятого байту по канаду SPI, який обслуговує вимірювальну систему
/*****************************************************/
void SPI_ADC_IRQHandler(void)
{
//#ifdef SYSTEM_VIEWER_ENABLE
//  SEGGER_SYSVIEW_RecordEnterISR();
//#endif

  //Фіксуємо вхід у переривання обробки даних від АЦП
  semaphore_adc_irq  = true;
  
  //На самому початку знімаємо chip_select
  GPIO_SPI_ADC->BSRRL = GPIO_NSSPin_ADC;
  uint16_t read_value = SPI_ADC->DR;

  /*
  Аналізуємо прийняті дані
  */
  if (
      (state_reading_ADCs == STATE_READING_WRITE_READ) ||
      (state_reading_ADCs == STATE_READING_READ)
     )
  {
    unsigned int shift = ((GPIO_SELECT_ADC->ODR & GPIO_SELECTPin_ADC) == 0) ? 0 : NUMBER_CANALs_ADC;
    unsigned int number_canal = shift + ((read_value >> 12) & 0xf);
    
    output_adc[number_canal].tick = tick_output_adc_p;
    
    static uint32_t error_spi_adc;
    if(channel_answer != number_canal) 
    {
      if (error_spi_adc < 3 ) error_spi_adc++;
      if (error_spi_adc >= 3 )_SET_BIT(set_diagnostyka, ERROR_SPI_ADC_BIT);
    }
    else 
    {
      error_spi_adc = 0;
      
      _SET_BIT(clear_diagnostyka, ERROR_SPI_ADC_BIT);
      output_adc[number_canal].value = read_value & 0xfff;
    }
  }
  /***/
  
  //Виконуємо операції з читання АЦП
  control_reading_ADCs();
  
  /*
  Подальші діх виконуємо тільки тоді, коли всі канали вже оцифровані
  */
  if (state_reading_ADCs == STATE_READING_ADCs_NONE)
  {
#ifdef SYSTEM_VIEWER_ENABLE
  SEGGER_SYSVIEW_RecordEnterISR();
#endif
  
    /*******************************************************/
    //Перевіряємо, чи відбувалися зміни юстування
    /*******************************************************/
    if (changed_ustuvannja == CHANGED_ETAP_ENDED) /*Це є умова, що нові дані підготовлені для передачі їх у роботу вимірювальною системою (і при цьому зараз дані не змінюються)*/
    {
      //Копіюємо масив юстування у копію цього масиву але з яким працює (читає і змінює) тільки вимірювальна захистема
      for(unsigned int k = 0; k < NUMBER_ANALOG_CANALES; k++) 
      {
        ustuvannja_meas[k] = ustuvannja[k];
      }
      
      //Помічаємо, що зміни прийняті вимірювальною системою, але ще треба прийняти системою захистів
      changed_ustuvannja = CHANGED_ETAP_ENDED_EXTRA_ETAP;
    }
    /*****************************************************/

    /*
    Формуємо значення оцифровуваних каналів
    */
    unsigned int command_word = 0;
    if ((status_adc_read_work & DATA_VAL_READ) != 0)
    {
      command_word |= (1 << I_Imn) | (1 << I_Ibp) |
                      (1 << I_Umn) | (1 << I_Ubp);
        
    }
      
    uint32_t _x1, _x2, _DX, _dx;
    int _y1, _y2;
    long long _y;
      
    uint32_t _x = previous_tick_DATA_VAL;
    /*****/
    //Формуємо значення Imn
    /*****/
    if ((command_word & (1 << I_Imn)) != 0)
    {
      _x1 = ADCs_data_raw[I_Imn].tick;
      _y1 = ADCs_data_raw[I_Imn].value;
        
      _y2 = output_adc[C_Imn_1].value - /*gnd_adc - */ vref_adc;
      if (abs(_y2) > 87)
      {
        _x2 = output_adc[C_Imn_1].tick;
        _y2 = (int)(_y2*ustuvannja_meas[I_Imn])>>(USTUVANNJA_VAGA - 4);
      }
      else
      {
        _y2 = output_adc[C_Imn_16].value - /*gnd_adc - */ vref_adc;

        _x2 = output_adc[C_Imn_16].tick;
        _y2 = (int)((-_y2)*ustuvannja_meas[I_Imn])>>(USTUVANNJA_VAGA);
      }
      
      if (_x2 > _x1) _DX = _x2 - _x1;
      else
      {
        uint64_t _DX_64 = _x2 + 0x100000000 - _x1;
        _DX = _DX_64;
      }
      if (_x >= _x1) _dx = _x - _x1;
      else
      {
        uint64_t _dx_64 = _x + 0x100000000 - _x1;
        _dx = _dx_64;
      }
      _y = ((long long)_y1) + ((long long)(_y2 - _y1))*((long long)_dx)/((long long)_DX);

      ADCs_data[I_Imn] = _y;
      
      ADCs_data_raw[I_Imn].tick = _x2;
      ADCs_data_raw[I_Imn].value = _y2;
    }
    /*****/

    /*****/
    //Формуємо значення Ibp
    /*****/
    if ((command_word & (1 << I_Ibp)) != 0)
    {
      _x1 = ADCs_data_raw[I_Ibp].tick;
      _y1 = ADCs_data_raw[I_Ibp].value;
        
      _y2 = output_adc[C_Ibp_1].value - /*gnd_adc - */ vref_adc;
      if (abs(_y2) > 87)
      {
        _x2 = output_adc[C_Ibp_1].tick;
        _y2 = (int)(_y2*ustuvannja_meas[I_Ibp])>>(USTUVANNJA_VAGA - 4);
      }
      else
      {
        _y2 = output_adc[C_Ibp_16].value - /*gnd_adc - */ vref_adc;

        _x2 = output_adc[C_Ibp_16].tick;
        _y2 = (int)((-_y2)*ustuvannja_meas[I_Ibp])>>(USTUVANNJA_VAGA);
      }
      
      if (_x2 > _x1) _DX = _x2 - _x1;
      else
      {
        uint64_t _DX_64 = _x2 + 0x100000000 - _x1;
        _DX = _DX_64;
      }
      if (_x >= _x1) _dx = _x - _x1;
      else
      {
        uint64_t _dx_64 = _x + 0x100000000 - _x1;
        _dx = _dx_64;
      }
      _y = ((long long)_y1) + ((long long)(_y2 - _y1))*((long long)_dx)/((long long)_DX);

      ADCs_data[I_Ibp] = _y;
      
      ADCs_data_raw[I_Ibp].tick = _x2;
      ADCs_data_raw[I_Ibp].value = _y2;
    }
    /*****/
    
    /*****/
    //Формуємо значення Umn
    /*****/
    if ((command_word & (1 << I_Umn)) != 0)
    {
      _x1 = ADCs_data_raw[I_Umn].tick;
      _y1 = ADCs_data_raw[I_Umn].value;
        
      _y2 = output_adc[C_Umn_1].value - /*gnd_adc - */ vref_adc;
      if (abs(_y2) > 87)
      {
        _x2 = output_adc[C_Umn_1].tick;
        _y2 = (int)(_y2*ustuvannja_meas[I_Umn])>>(USTUVANNJA_VAGA - 4);
      }
      else
      {
        _y2 = output_adc[C_Umn_16].value - /*gnd_adc - */ vref_adc;

        _x2 = output_adc[C_Umn_16].tick;
        _y2 = (int)((-_y2)*ustuvannja_meas[I_Umn])>>(USTUVANNJA_VAGA);
      }
      
      if (_x2 > _x1) _DX = _x2 - _x1;
      else
      {
        uint64_t _DX_64 = _x2 + 0x100000000 - _x1;
        _DX = _DX_64;
      }
      if (_x >= _x1) _dx = _x - _x1;
      else
      {
        uint64_t _dx_64 = _x + 0x100000000 - _x1;
        _dx = _dx_64;
      }
      _y = ((long long)_y1) + ((long long)(_y2 - _y1))*((long long)_dx)/((long long)_DX);
      
      if ((_y >= 0) && (ADCs_data[I_Umn] < 0))
      {
        /*
        Зафіксований перехід через нуль
        */
        //Попередній перехід
        perechid_cherez_nul[INDEX_PhK_Umn][0].x1 = poperednij_perechid.Umn_x1;
        perechid_cherez_nul[INDEX_PhK_Umn][0].y1 = poperednij_perechid.Umn_y1;
        perechid_cherez_nul[INDEX_PhK_Umn][0].x2 = poperednij_perechid.Umn_x2;
        perechid_cherez_nul[INDEX_PhK_Umn][0].y2 = poperednij_perechid.Umn_y2;
          
        //Поточний перехід
        poperednij_perechid.Umn_x1 = perechid_cherez_nul[INDEX_PhK_Umn][1].x1 = penultimate_tick_DATA_VAL;
        poperednij_perechid.Umn_y1 = perechid_cherez_nul[INDEX_PhK_Umn][1].y1 = ADCs_data[I_Umn];
        poperednij_perechid.Umn_x2 = perechid_cherez_nul[INDEX_PhK_Umn][1].x2 = _x;
        poperednij_perechid.Umn_y2 = perechid_cherez_nul[INDEX_PhK_Umn][1].y2 = _y;
          
        //Помічаємо, що перехід зафіксований
        fix_perechid_cherez_nul[INDEX_PhK_Umn] = 0xff;
      }
      ADCs_data[I_Umn] = _y;
      
      ADCs_data_raw[I_Umn].tick = _x2;
      ADCs_data_raw[I_Umn].value = _y2;
    }
    /*****/
    
    /*****/
    //Формуємо значення Ubp
    /*****/
    if ((command_word & (1 << I_Ubp)) != 0)
    {
      _x1 = ADCs_data_raw[I_Ubp].tick;
      _y1 = ADCs_data_raw[I_Ubp].value;
        
      _y2 = output_adc[C_Ubp_1].value - /*gnd_adc - */ vref_adc;
      if (abs(_y2) > 87)
      {
        _x2 = output_adc[C_Ubp_1].tick;
        _y2 = (int)(_y2*ustuvannja_meas[I_Ubp])>>(USTUVANNJA_VAGA - 4);
      }
      else
      {
        _y2 = output_adc[C_Ubp_16].value - /*gnd_adc - */ vref_adc;

        _x2 = output_adc[C_Ubp_16].tick;
        _y2 = (int)((-_y2)*ustuvannja_meas[I_Ubp])>>(USTUVANNJA_VAGA);
      }
      
      if (_x2 > _x1) _DX = _x2 - _x1;
      else
      {
        uint64_t _DX_64 = _x2 + 0x100000000 - _x1;
        _DX = _DX_64;
      }
      if (_x >= _x1) _dx = _x - _x1;
      else
      {
        uint64_t _dx_64 = _x + 0x100000000 - _x1;
        _dx = _dx_64;
      }
      _y = ((long long)_y1) + ((long long)(_y2 - _y1))*((long long)_dx)/((long long)_DX);
 
      if ((_y >= 0) && (ADCs_data[I_Ubp] < 0))
      {
        /*
        Зафіксований перехід через нуль
        */
        //Попередній перехід
        perechid_cherez_nul[INDEX_PhK_Ubp][0].x1 = poperednij_perechid.Ubp_x1;
        perechid_cherez_nul[INDEX_PhK_Ubp][0].y1 = poperednij_perechid.Ubp_y1;
        perechid_cherez_nul[INDEX_PhK_Ubp][0].x2 = poperednij_perechid.Ubp_x2;
        perechid_cherez_nul[INDEX_PhK_Ubp][0].y2 = poperednij_perechid.Ubp_y2;
          
        //Поточний перехід
        poperednij_perechid.Ubp_x1 = perechid_cherez_nul[INDEX_PhK_Ubp][1].x1 = penultimate_tick_DATA_VAL;
        poperednij_perechid.Ubp_y1 = perechid_cherez_nul[INDEX_PhK_Ubp][1].y1 = ADCs_data[I_Ubp];
        poperednij_perechid.Ubp_x2 = perechid_cherez_nul[INDEX_PhK_Ubp][1].x2 = _x;
        poperednij_perechid.Ubp_y2 = perechid_cherez_nul[INDEX_PhK_Ubp][1].y2 = _y;
          
        //Помічаємо, що перехід зафіксований
        fix_perechid_cherez_nul[INDEX_PhK_Ubp] = 0xff;
      }
      ADCs_data[I_Ubp] = _y;
      
      ADCs_data_raw[I_Ubp].tick = _x2;
      ADCs_data_raw[I_Ubp].value = _y2;
    }
    /*****/
    
    unsigned int head_data_for_oscylograph_tmp = head_data_for_oscylograph;
    unsigned int x2, x1, delta_x; 

    if ((status_adc_read_work & DATA_VAL_READ) != 0)
    {
      /*
      Необхідно опрацювати оцифровані дані для перетворення Фур'є
      */
      Fourier();
      
      /*
      Виконуємо операції по визначенню частоти і підстройці частоти
      */
      fapch();
      if (freq_mutex == false) frequency_high = frequency_irq;
    
      //Формуємо дані для розширеної виборки
      x1 = rozshyrena_vyborka.time_p = penultimate_tick_DATA_VAL;
      x2 = rozshyrena_vyborka.time_c = previous_tick_DATA_VAL;
      for (unsigned int i = 0; i < NUMBER_ANALOG_CANALES; i++) 
      {
        rozshyrena_vyborka.data_p[i] = rozshyrena_vyborka.data_c[i];
        rozshyrena_vyborka.frequency_p = rozshyrena_vyborka.frequency_c;
        rozshyrena_vyborka.data_c[i] = ADCs_data[i];
        rozshyrena_vyborka.frequency_c = frequency_irq;
      }

      /*******************************************************
      Формування апроксимованих значень
      *******************************************************/
      if (head_data_for_oscylograph_tmp != DATA_VAL_tail_data_for_oscylograph)
      {
        if (x2 > x1) delta_x = x2 - x1;
        else
        {
          long long delta_x_64 = x2 + 0x100000000 - x1;
          delta_x = delta_x_64;
        }

        while (head_data_for_oscylograph_tmp != DATA_VAL_tail_data_for_oscylograph)
        {
          unsigned int DATA_VAL_tail_data_for_oscylograph_tmp = DATA_VAL_tail_data_for_oscylograph;
    
          unsigned int x = data_for_oscylograph[DATA_VAL_tail_data_for_oscylograph_tmp].time_stemp;
        
          unsigned int dx;
          if (x >= x1) dx = x - x1;
          else
          {
            long long dx_64 = x + 0x100000000 - x1;
            dx = dx_64;
          }
          
          if (dx > delta_x) 
          {
            break;
          }

          for (unsigned int i = 0; i < NUMBER_ANALOG_CANALES; i++)
          {
            int y1 = rozshyrena_vyborka.data_p[i], y2 = rozshyrena_vyborka.data_c[i];
            long long y;
            if (dx <= delta_x)
            {
              y = ((long long)(y2 - y1))*((long long)dx)/((long long)delta_x) + ((long long)y1);
            }
            else
            {
              y = 0;
            }
            data_for_oscylograph[DATA_VAL_tail_data_for_oscylograph_tmp].data[I_Imn + i] = y;
          }
          //Частота
          {
            int const y1 = (int)(roundf(rozshyrena_vyborka.frequency_p* 100.0f));
            int const y2 = (int)(roundf(rozshyrena_vyborka.frequency_c* 100.0f));
            int y = 0x8000;
            if (
                (y1 > 0 ) &&
                (y2 > 0) &&
                (dx <= delta_x)
               )   
            {
              y = ((long long)(y2 - y1))*((long long)dx)/((long long)delta_x) + ((long long)y1);
            }
            data_for_oscylograph[DATA_VAL_tail_data_for_oscylograph_tmp].data[NUMBER_ANALOG_CANALES + 0] = y;
          }
          data_for_oscylograph[DATA_VAL_tail_data_for_oscylograph_tmp].DATA_fix = 0xff;

          if (++DATA_VAL_tail_data_for_oscylograph >= MAX_INDEX_DATA_FOR_OSCYLOGRAPH) DATA_VAL_tail_data_for_oscylograph = 0;
        }
      }
      /******************************************************/
      
      status_adc_read_work &= (unsigned int)(~DATA_VAL_READ);

      /**************************************************/
      //Виставляємо повідомлення про завершення оброки першої групи вимірювальних величин
      /**************************************************/
      control_word_of_watchdog |= WATCHDOG_MEASURE_STOP_DATA_VAL;
      /**************************************************/
    }
    
    /********************************************************
    Формуємо масив миттєвих значень і виконуємо операції для аналогового реєстратора
    ********************************************************/
    if (head_data_for_oscylograph_tmp != tail_data_for_oscylograph)
    {
      unsigned int working_ar = false; /*по замовчуванню ставимо, що Аналоговий реєстратор не працює*/
      unsigned int const index_array_ar_current_before = index_array_ar_current;
      while (
             (head_data_for_oscylograph_tmp != tail_data_for_oscylograph) &&
             (data_for_oscylograph[tail_data_for_oscylograph].DATA_fix != 0)
            )
      {
        unsigned int const tail_data_for_oscylograph_tmp = tail_data_for_oscylograph;

        if((prescaler_ar & MASKA_BIT_FOR_PRESCALER) == 0)
        {
          for (unsigned int i = 0; i < NUMBER_ANALOG_CANALES; i++)
          {
            int data_tmp = data_for_oscylograph[tail_data_for_oscylograph_tmp].data[i];
            //Масив миттєвих аналогових виборок для аналогового реєстратора
            AR_WRITE(index_array_ar_current, data_tmp);
          }
          //Частота
          int data_tmp = data_for_oscylograph[tail_data_for_oscylograph_tmp].data[NUMBER_ANALOG_CANALES + 0];
          AR_WRITE(index_array_ar_current, data_tmp);
        }

        //Масив дискретних сигналів для аналогового реєстратора
        unsigned int *label_to_active_functions_source = data_for_oscylograph[tail_data_for_oscylograph_tmp].active_functions;
        if((prescaler_ar & MASKA_BIT_FOR_PRESCALER) != 0)
        {
          for (unsigned int i = 0; i < N_BIG; i++)  active_functions_trg[i] = *(label_to_active_functions_source + i);
        }
        else
        {
          for (unsigned int i = 0; i < N_BIG; i++)  active_functions_trg[i] |= *(label_to_active_functions_source + i);

          unsigned short int *label_to_active_functions_trg = (unsigned short int*)active_functions_trg;
          for(unsigned int i = 0; i < NUMBER_WORD_DIGITAL_PART_AR; i++) 
          {
            AR_WRITE(index_array_ar_current, *(label_to_active_functions_trg + i));
          }
          //Індекс масиву об'єднаних виборок для аналогового реєстратора
          if (index_array_ar_current >= SIZE_BUFFER_FOR_AR) index_array_ar_current = 0;/*Умова мала б бути ==, але щоб перестахуватися на невизначену помилку я поставив >=*/

          unsigned int state_ar_record_m_tmp = data_for_oscylograph[tail_data_for_oscylograph_tmp].state_ar_record;
          if (
              (state_ar_record_m_tmp == STATE_AR_NONE_M) &&
              (
               (state_ar_record_fatfs == STATE_AR_NONE_FATFS) ||
               (state_ar_record_fatfs == STATE_AR_STOP_WRITE_FATFS) ||
               (state_ar_record_fatfs == STATE_AR_MEMORY_FULL_FATFS) ||
               (state_ar_record_fatfs == STATE_AR_BLOCK_FATFS)
              )/*умова, що на даний момент часу не ішов запис даних у енергонезалежну пам'ять*/
             )
          {
            working_ar = false;
            //Випадок, коли Аналоговий реєстратор не працює
            index_array_ar_tail = index_array_tail_min = index_array_ar_heat = index_array_ar_current;
            tail_to_heat = current_to_tail = false;
          }
          else
          {
            working_ar = true;
            
            if (state_ar_record_m_tmp == STATE_AR_WORK_M)
            {
              /*
              Вже новий зріз післяаварійного масиву доданий у масив
              */
              if (
                  (prev_state_ar_record_m == STATE_AR_NONE_M) &&
                  (state_ar_record_fatfs == STATE_AR_WAIT_TO_WRITE_FATFS)
                 )   
              {
                //Умова, що треба включити доаварійний масив для запису
              
                int difference;
                /*
                оскільки 1 післяаварійних зрізів доданио у масив,
                то для визначення першої мітки післяаварійного масиву від index_array_ar_current
                відняти кількість миттєвих значень у одному зрізі
                */
                /*
                Встановлюємо мітку першого миттєвого значееня післяаваріного масиву і 
                тимчасово помісчаємо її у змінну "вигрузки" для того, щоб дальша програма 
                мала "універсальний", тобто прстіший, вигляд
                */
                difference = index_array_ar_current - AR_TOTAL_NUMBER_CANALES;
                if (difference >= 0) index_array_ar_tail = difference;
                else index_array_ar_tail = difference + SIZE_BUFFER_FOR_AR;

                //Встановлюємо мітку "вигрузки"
//                difference = index_array_ar_tail - (current_settings_prt.prefault_number_periods << VAGA_NUMBER_POINT_AR)*AR_TOTAL_NUMBER_CANALES;

               //Встановлюємо мітку "вигрузки" в умовах холодного або близького КЗ з пропаданням оперативного живлення
                difference = index_array_ar_tail - (AR_TAIL_MIN_NUMBER_PERIOD << VAGA_NUMBER_POINT_AR)*AR_TOTAL_NUMBER_CANALES;
                if (difference >= 0) index_array_tail_min = difference;
                else index_array_tail_min = difference + SIZE_BUFFER_FOR_AR;

                //Встановлюємо мітку "вигрузки"
                difference = index_array_ar_tail - (header_ar.prefault_number_periods << VAGA_NUMBER_POINT_AR)*AR_TOTAL_NUMBER_CANALES;


                if (difference >= 0) index_array_ar_tail = difference;
                else index_array_ar_tail = difference + SIZE_BUFFER_FOR_AR;
              }

              index_array_ar_heat = index_array_ar_current;
              tail_to_heat = false;
            }
          }
          
          prev_state_ar_record_m = state_ar_record_m_tmp;
        
        }
        prescaler_ar++;
    
        data_for_oscylograph[tail_data_for_oscylograph_tmp].DATA_fix = 0;

        if (++tail_data_for_oscylograph >= MAX_INDEX_DATA_FOR_OSCYLOGRAPH) tail_data_for_oscylograph = 0;
      }

      /***
      Визначаємо, чи не відбулося переповнення      
      working_ar - значення у цьому місці відповідає останньому часовому зрізу, який доданий у буфер
      ***/
      
      if (working_ar != false)
      {
        /***
        Початок відділку беремо від index_array_ar_current_before;
        ***/
        
        int end_tmp = index_array_ar_current - index_array_ar_current_before;
        if (end_tmp < 0) end_tmp += SIZE_BUFFER_FOR_AR;
        
        int tail_tmp = index_array_ar_tail - index_array_ar_current_before;
        if (
            (tail_tmp < 0)
            ||
            (
             (tail_tmp == 0) &&
             (current_to_tail == false)
            ) 
           )
        {
          tail_tmp += SIZE_BUFFER_FOR_AR;
        }
        
        if (tail_tmp <= end_tmp)
        {
          current_to_tail = true;
          
          if (tail_tmp < end_tmp)
          {
            //Помилкова ситуація, яка викликана переповненням 
            _SET_BIT(set_diagnostyka, ERROR_AR_OVERLOAD_BUFFER_BIT);
        
            state_ar_record_m = STATE_AR_BLOCK_M;
          }
        }
        else current_to_tail = false;
        
        diff_index_heat_tail = tail_tmp - end_tmp;
      }
      else diff_index_heat_tail = -1;
      
      diff_index_heat_tail = index_array_ar_current - index_array_ar_tail;
      if (diff_index_heat_tail < 0) diff_index_heat_tail += SIZE_BUFFER_FOR_AR;
    }
    /*******************************************************/
    
    if ((status_adc_read_work & TEST_VAL_READ) != 0)
    {
      //Треба опрацювати інтегральні величини
      operate_test_ADCs();
    
      status_adc_read_work &= (unsigned int)(~TEST_VAL_READ);

      /**************************************************/
      //Виставляємо повідомлення про завершення тестових величин
      /**************************************************/
      control_word_of_watchdog |= WATCHDOG_MEASURE_STOP_TEST_VAL;
      /**************************************************/
    }
    
    /**************************************************/
    //Якщо зараз стоїть блокування то його знімаємо
    /**************************************************/
    if (_CHECK_SET_BIT(control_i2c_taskes, TASK_BLK_OPERATION_BIT) != 0)
    {
      //Повне роозблоковування обміну з мікросхемами для драйверу I2C
      _CLEAR_BIT(control_i2c_taskes, TASK_BLK_OPERATION_BIT);
    }
    /**************************************************/
  
#ifdef SYSTEM_VIEWER_ENABLE
  SEGGER_SYSVIEW_RecordExitISR();
#endif
  }

  if ((GPIO_SPI_ADC->ODR & GPIO_NSSPin_ADC) != 0)
  {
    //Новий обмін не почався функцією control_reading_ADCs
    
    /*
    Можливо з часу останнього виклику функції control_reading_ADCs до даного
    моментк переривання від таймера поставило нові задачі на оцифровку
    */
    
    /*
    Забороняємо генерацію переривань, щоб поки ми аналізуємо чяи немає нових даних
    на оцифровку ще новіші не появилися
    */
    __disable_interrupt();
    
    /*
    Аналізуємо, чи немає нових даних на оцифровку і якщо до даного моменту нових
    даних не появилося, то розблоковуємо можливість початку оцифровки з переривання
    таймеру ( chip select виставлений у 1)
    */
    if (
        (adc_DATA_VAL_read == false) &&
        (adc_TEST_VAL_read == false)
       )
    {
      semaphore_adc_irq  = false;
    }
    
    /*
    Дозволяємо генерацію переривань
    */
     __enable_interrupt();
  }
  else semaphore_adc_irq  = false;

  
  if (semaphore_adc_irq  != false)
  {
    /*
    Ця умова може бути тыльки у одному випадку: якщо при аналізі на нові дані на оцифровку
    з моменту отаннього запуску функції control_reading_ADCs до заборони переривань
    функцією __disable_interrupt дані всетаки появилися.
    
    Модемо і маємо запусти функцію control_reading_ADCs. Конфлікту не буде, бо
    chip_select покищо виставлений у високий стан (це дає остання перевірка 
    if ((GPIO_SPI_ADC->ODR & GPIO_NSSPin_ADC) != 0)) і змінна semaphore_adc_irq ще
    не рівна false, а тим чином блокує запуск оцифровки х переривання таймеру
    */
    
    control_reading_ADCs();
    
    /*
    Скидаємо прапорець. який сигналізує що ми у перериванні обробки оцифрованих даних, які прийшли по SPI
    інтерфейсу. Але цей прапорець вже нічого не блокує, бо запуск функції control_reading_ADCs
    при гарантованій умові, що дані на оцифровку "стоять у черзі"  мусить почати
    оцифровку - а це можливе тільки тоді, коли chip_select цією функцією буде вустановлено у низький рівень
    
    А встановиться chip_select назад у високий рівень тільки коли знову згенерується переривання від
    каналі SPI
    */
    semaphore_adc_irq  = false;
  }
  
//#ifdef SYSTEM_VIEWER_ENABLE
//  SEGGER_SYSVIEW_RecordExitISR();
//#endif
}
/*****************************************************/

/*****************************************************/
//Визначенням кутів
/*****************************************************/
void calc_angle(void) 
{
  //Копіюємо вимірювання
  semaphore_measure_values_low1 = 1;
  for (unsigned int i = 0; i < _NUMBER_IM; i++ ) 
  {
    measurement_low[i] = measurement_middle[i];
  }
  semaphore_measure_values_low1 = 0;
              
  int ortogonal_low_tmp[2*FULL_ORT_MAX];
  
  //Виставляємо семафор заборони обновлення значень з системи захистів
  semaphore_measure_values_low = 1;
  for(unsigned int i = 0; i < (2*FULL_ORT_MAX); i++ )
  {
      ortogonal_low_tmp[i] = ortogonal_calc_low[i];
  } 
  //Знімаємо семафор заборони обновлення значень з системи захистів
  semaphore_measure_values_low = 0;
  
  state_calc_phi_angle = true;
  bank_for_calc_phi_angle = (bank_for_calc_phi_angle ^ 0x1) & 0x1;

  //Визначаємо, який вектор беремо за осному
  __full_ort_index index_base = FULL_ORT_Umn;

  /***
  Визначаємо, який останній вектор можна брати за основу
  ***/
  __full_ort_index index_last = FULL_ORT_Ubp;
  /***/
  
  int base_index_for_angle_tmp = -1;
  __full_ort_index index = index_base;
  while( index <= index_last)
  {
    unsigned int index_m = 0;
    switch (index)
    {
    case FULL_ORT_Umn:
      {
        index_m = IM_Umn;
        break;
      }
    case FULL_ORT_Ubp:
      {
        index_m = IM_Ubp;
        break;
      }
    default:
      {
        //Теоретично цього ніколи не мало б бути
        total_error_sw_fixed();
      }
    }
  
    if (measurement_low[index_m] >= PORIG_CHUTLYVOSTI_VOLTAGE_ANGLE)
    {
      base_index_for_angle_tmp = index;
      break; //Вихід із циклу while
    }
    index++;
  }
  base_index_for_angle = base_index_for_angle_tmp;
  
  if (base_index_for_angle_tmp >= 0)
  {
    //Координати базового вектору, відносно якого будемо шукати кути
    int ortogonal_base[2] = {ortogonal_low_tmp[2*base_index_for_angle_tmp], ortogonal_low_tmp[2*base_index_for_angle_tmp + 1]};
    
#define SIN_BASE   ortogonal_base[0]
#define COS_BASE   ortogonal_base[1]

    unsigned int amplituda_base = sqrt_64((unsigned long long)((long long)SIN_BASE*(long long)SIN_BASE) + (unsigned long long)((long long)COS_BASE*(long long)COS_BASE));
    if (amplituda_base != 0)
    {
      for (__full_ort_index index_tmp = index_base; index_tmp < FULL_ORT_MAX; index_tmp++)
      {
        if (index_tmp == index)
        {
          phi_angle[bank_for_calc_phi_angle][index_tmp] = 0;
          continue;
        }
        else
        {
          unsigned int porig_chutlyvosti = 0;
          unsigned int index_m = 0;
          switch (index_tmp)
          {
          case FULL_ORT_Umn:
            {
              porig_chutlyvosti = PORIG_CHUTLYVOSTI_VOLTAGE_ANGLE;
              index_m = IM_Umn;
              break;
            }
          case FULL_ORT_Ubp:
            {
              porig_chutlyvosti = PORIG_CHUTLYVOSTI_VOLTAGE_ANGLE;
              index_m = IM_Ubp;
              break;
            }
          case FULL_ORT_Imn:
            {
              porig_chutlyvosti = PORIG_CHUTLYVOSTI_CURRENT;
              index_m = IM_Imn;
              break;
            }
          case FULL_ORT_Ibp:
            {
              porig_chutlyvosti = PORIG_CHUTLYVOSTI_CURRENT;
              index_m = IM_Ibp;
              break;
            }
          default:
            {
              //Теоретично цього ніколи не мало б бути
              total_error_sw_fixed();
            }
          }
      
          if (measurement_low[index_m] >= porig_chutlyvosti)
          {
            //Розраховуємо кут
#define SIN_TARGET ortogonal_low_tmp[2*index_tmp]
#define COS_TARGET ortogonal_low_tmp[2*index_tmp + 1]

            unsigned int amplituda_target = sqrt_64((unsigned long long)((long long)SIN_TARGET*(long long)SIN_TARGET) + (unsigned long long)((long long)COS_TARGET*(long long)COS_TARGET));
      
            if (amplituda_target != 0)
            {
              //Вираховуємо COS і SIN кута різниці між векторами
              long long cos_fi = COS_TARGET*COS_BASE + SIN_TARGET*SIN_BASE;
              long long sin_fi = -(SIN_TARGET*COS_BASE - COS_TARGET*SIN_BASE);//З розділу: "Неймовірно, але факт", тобто що я не можу пояснити

#undef SIN_TARGET
#undef COS_TARGET
      
              float sin_fi_f = ( ((float)sin_fi) / ((float)amplituda_target) ) / ((float)amplituda_base);
              if (sin_fi_f > 1) sin_fi_f = 1;
              else if (sin_fi_f < -1) sin_fi_f = -1;
      
              float angle_f = asinf(sin_fi_f)*180 / PI;
              int angle_int = (int)(angle_f*10); //беремо точність до десятих
              if (angle_int < 0) angle_int = -angle_int;
      
              if ((sin_fi >= 0) && (cos_fi >= 0))
              {
                //1-ий квадрант
                //angle_int залишається без зміни
              }
              else if ((sin_fi >= 0) && (cos_fi <  0))
              {
                //2-ий квадрант
                angle_int = 1800 - angle_int;
              }
              else if ((sin_fi <  0) && (cos_fi <  0))
              {
                //3-ий квадрант
                angle_int = 1800 + angle_int;
              }
              else
              {
                //4-ий квадрант
                angle_int = 3600 - angle_int;
              }
    
              if (angle_int >= 3600) angle_int -= 3600;
              else if (angle_int < 0) angle_int += 3600;
      
              phi_angle[bank_for_calc_phi_angle][index_tmp] = angle_int;
      
            }
            else
            {
              phi_angle[bank_for_calc_phi_angle][index_tmp] = -1;
            }

          }
          else
          {
            //Модуль досліджуваного вектора менше порогу - кут невизначений
            phi_angle[bank_for_calc_phi_angle][index_tmp] = -1;
          }
        }
      }
    }
    else
    {
      //Амплітуда базового вектору вимірювання по незрозумілій для мене причини рівна 0 (я думаю, що сюди програма не мала б ніколи заходити). Це перестарховка.
      for (__full_ort_index index_tmp = FULL_ORT_Umn; index_tmp < FULL_ORT_MAX; index_tmp++) phi_angle[bank_for_calc_phi_angle][index_tmp] = -1;
    }

#undef SIN_BASE
#undef COS_BASE
    
  }
  else
  {
    //Не зафіксовано вектора вимірювання, відносно якого можна розраховувати кути
    for (__full_ort_index index_tmp = FULL_ORT_Umn; index_tmp < FULL_ORT_MAX; index_tmp++) phi_angle[bank_for_calc_phi_angle][index_tmp] = -1;
  }

  state_calc_phi_angle = false;
}

/*****************************************************/

/*****************************************************/
//Визначенням миттєвої потужності
/*****************************************************/
//#pragma optimize=none
void calc_power_and_energy(void) 
{
  //Визначаємо банк із підготовленими даними для обробки
  unsigned int bank_for_enegry_tmp = (bank_for_enegry + 1) & 0x1;
  
  bank_for_calc_power = (bank_for_calc_power ^ 0x1) & 0x1;
  for (size_t line = 0; line < 2; ++line)
  {
    int P_tmp = P_plus[bank_for_enegry_tmp][line] - P_minus[bank_for_enegry_tmp][line];
    int Q_tmp = Q_1q[bank_for_enegry_tmp][line] + Q_2q[bank_for_enegry_tmp][line] - Q_3q[bank_for_enegry_tmp][line] - Q_4q[bank_for_enegry_tmp][line];

    float P_float = ((float)P_tmp)/((float)MAIN_FREQUENCY);
    float Q_float = ((float)Q_tmp)/((float)MAIN_FREQUENCY);
  
    state_calc_power = true;
    P[bank_for_calc_power][line] = P_tmp = (int)P_float;
    Q[bank_for_calc_power][line] = Q_tmp = (int)Q_float;
  
    //Повна потужність
    if ( (P_tmp != 0) || (Q_tmp != 0))
    {
      float in_square_root, S_float;
      in_square_root = P_float*P_float + Q_float*Q_float;
    
      if (arm_sqrt_f32(in_square_root, &S_float) == ARM_MATH_SUCCESS)
      {
        S[bank_for_calc_power][line] = (unsigned int)S_float;
      }
      else
      {
        //Якщо сюди дійшла програма, значить відбулася недопустива помилка, тому треба зациклити програму, щоб вона пішла на перезагрузку
        total_error_sw_fixed();
      }
    
      cos_phi_x1000[bank_for_calc_power][line] = (int)(1000.0f*P_float/S_float);
    }
    else
    {
      S[bank_for_calc_power][line] = 0;
      cos_phi_x1000[bank_for_calc_power][line] = 0;
    }
    state_calc_power = false;

    if (line != 0) continue;
    
    //Накопичення енергій
    unsigned int clean_energy_tmp = clean_energy;
    if (clean_energy_tmp != 0) 
    {
      clean_energy = 0;

      if ((POWER_CTRL->IDR & POWER_CTRL_PIN) != (uint32_t)Bit_RESET)
      {
        //Запускаємо запис у EEPROM
        _SET_BIT(control_spi1_taskes, TASK_START_WRITE_ENERGY_EEPROM_BIT);
      }
      else number_minutes = PERIOD_SAVE_ENERGY_IN_MINUTES; /*якщо живлення відновиться, щоб зразу була подана команда на запис*/

      //Помічаємо, що відбулася очистка лічильників енергій
      information_about_clean_energy |= ((1 << USB_RECUEST)|(1 << RS485_RECUEST));
    }
  
    state_calc_energy = true;
    for (__index_energy i = INDEX_EA_PLUS; i < MAX_NUMBER_INDEXES_ENERGY; i++)
    {
      if (clean_energy_tmp != 0) energy[0][i] = 0;
    
      int power_data = 0;
      switch (i)
      {
      case INDEX_EA_PLUS:
        {
          power_data = P_plus[bank_for_enegry_tmp][0];
          break;
        }
      case INDEX_EA_MINUS:
        {
          power_data = P_minus[bank_for_enegry_tmp][0];
          break;
        }
      case INDEX_ER_1:
        {
          power_data = Q_1q[bank_for_enegry_tmp][0];
          break;
        }
      case INDEX_ER_2:
        {
          power_data = Q_2q[bank_for_enegry_tmp][0];
          break;
        }
      case INDEX_ER_3:
        {
          power_data = Q_3q[bank_for_enegry_tmp][0];
          break;
        }
      case INDEX_ER_4:
        {
          power_data = Q_4q[bank_for_enegry_tmp][0];
          break;
        }
      default:
        {
          //Теоретично цього ніколи не мало б бути
          total_error_sw_fixed();
        }
      }
    
      if (power_data >= (PORIG_POWER_ENERGY*MAIN_FREQUENCY)) /*бо у power_data є сума миттєвих потужностей за 1с, які розраховувалися кожні 20мс*/
      {
        double power_quantum = ((double)power_data)/(((double)MAIN_FREQUENCY)*DIV_kWh);
        double erergy_tmp = energy[0][i] + power_quantum;
        if (erergy_tmp > 999999.999) erergy_tmp = erergy_tmp - 999999.999;
        energy[0][i] = erergy_tmp;
      }
    }
    state_calc_energy = false;
    for (__index_energy i = INDEX_EA_PLUS; i < MAX_NUMBER_INDEXES_ENERGY; i++) energy[1][i] = energy[0][i];
  
  }
  
}
/*****************************************************/

/*****************************************************/
//Пошук розрядності числа
/*****************************************************/
inline unsigned int norma_value(unsigned long long y)
{
  unsigned long long temp=y;
  unsigned int rezultat =0;
  if (temp == 0) return 0;

  while(temp !=0)
  {
    temp = temp>>1;
    rezultat++;
  }
  return rezultat-1;
}
/*****************************************************/

/*****************************************************/
//Пошук розрядності числа типу int
/*****************************************************/
//#pragma optimize=none
inline unsigned int get_order(int value)
{
  unsigned int i = 0;

  if (value == 0) return 1;
  else  if (value == 0x80000000) return 32;
  
  if (value < 0) value =-value;

  while ((value >> (++i)) != 0); 

  return i;    
}
/*****************************************************/

/*****************************************************/
//Розрахунок кореня квадратного методом половинного ділення  з прогнозуванням розрядності числа
/*****************************************************/
unsigned int sqrt_64(unsigned long long y)
{
   unsigned int b;
   unsigned int a;
   unsigned int c;
   unsigned int norma_rez;
   unsigned long long temp;
   
   norma_rez = norma_value(y)>>1;
   
   a = (1<<norma_rez) - 1;
   b = (1<<(norma_rez+1));
 
   do 
    {
     c = (a + b)>>1;
     temp = (unsigned long long)c*(unsigned long long)c; 
     if (temp != y)
       {
        if ( temp > y) b= c; else a= c;
       } 
     else return c;
    }
   while ((b-a)>1);

   c = (a + b)>>1;

   return c ;
}
/*****************************************************/

/*****************************************************/
//Розрахунок кореня квадратного методом половинного ділення  з прогнозуванням розрядності числа
/*****************************************************/
inline unsigned int sqrt_32(unsigned int y)
{
   unsigned int b;
   unsigned int a;
   unsigned int c;
   unsigned int norma_rez;
   unsigned int temp;
   
   norma_rez = norma_value(y)>>1;
   
   a = (1<<norma_rez) - 1;
   b = (1<<(norma_rez+1));
 
   do 
    {
     c = (a + b)>>1;
     temp = c*c; 
     if (temp != y)
       {
        if ( temp > y) b= c; else a= c;
       } 
     else return c;
    }
   while ((b-a)>1);

   c = (a + b)>>1;

   return c ;
}
/*****************************************************/

/*****************************************************/
//Направленість МТЗ з визначенням секторів
/*****************************************************/
inline void directional_mtz(int ortogonal_local_calc[], unsigned int number_group_stp) 
{
  for (unsigned int i = 0; i < 2; ++i)
  {
    static unsigned int const bit_configuration[2] = {MCZO_BIT_CONFIGURATION, MCZR_BIT_CONFIGURATION};
    static unsigned int Uxy_bilshe_porogu[2];
    static unsigned int Ix_bilshe_porogu[2];
    static unsigned int const amountArr[2] = {4, 2};
    
    unsigned int const amount = amountArr[i];
    if ((current_settings_prt.configuration & (1u << bit_configuration[i])) != 0)
    {
      static unsigned int const index_I[2] = {IM_Imn, IM_Ibp};
      static unsigned int const index_U[2] = {IM_Umn, IM_Ubp};
      
      unsigned int porig_Uxy;
      if (Uxy_bilshe_porogu[i] == 0) porig_Uxy = PORIG_CHUTLYVOSTI_VOLTAGE_ANGLE*KOEF_POVERNENNJA_SECTOR_BLK/100;
      else porig_Uxy = PORIG_CHUTLYVOSTI_VOLTAGE_ANGLE;
      Uxy_bilshe_porogu[i] = (measurement[index_U[i]] >= porig_Uxy);
      
      unsigned int porig_Ix;
      if (Ix_bilshe_porogu[i] == 0) porig_Ix = PORIG_CHUTLYVOSTI_CURRENT*KOEF_POVERNENNJA_SECTOR_BLK/100;
      else porig_Ix = PORIG_CHUTLYVOSTI_CURRENT;
      Ix_bilshe_porogu[i]  = (measurement[index_I[i]] >= porig_Ix );
      
      if (
          (Uxy_bilshe_porogu[i] != 0) &&
          (Ix_bilshe_porogu[i]  != 0)
         )
      {
        /***/
        for (unsigned int msz = 0; msz < amount; ++msz)
        {
          static int (* const mtz_angle_cos[4][2])[NUMBER_GROUP_USTAVOK] = {
                                                                            {&current_settings_prt.setpoint_mtzo_1_angle_cos,  &current_settings_prt.setpoint_mtzo_1_angle_cos},
                                                                            {&current_settings_prt.setpoint_mtzo_2_angle_cos,  &current_settings_prt.setpoint_mtzo_2_angle_cos},
                                                                            {&current_settings_prt.setpoint_mtzo_3_angle_cos,  &current_settings_prt.setpoint_mtzo_3_angle_cos},
                                                                            {&current_settings_prt.setpoint_mtzo_4_angle_cos,  &current_settings_prt.setpoint_mtzo_4_angle_cos}
                                                                           };
          static int (* const mtz_angle_sin[2][2])[NUMBER_GROUP_USTAVOK] = {
                                                                            {&current_settings_prt.setpoint_mtzr_1_angle_sin,  &current_settings_prt.setpoint_mtzr_1_angle_sin},
                                                                            {&current_settings_prt.setpoint_mtzr_2_angle_sin,  &current_settings_prt.setpoint_mtzr_2_angle_sin}
                                                                           };
        
          int a_cos_fi = (*mtz_angle_cos[msz][i])[number_group_stp];
          int a_sin_fi = (*mtz_angle_sin[msz][i])[number_group_stp];
          a_sin_fi = -a_sin_fi; //З розділу: "Неймовірно, але факт", тобто що я не можу пояснити

          //Робимо доповорот на встановлений кут
          /*
          За розрахунком описаним при розрахунку діючих значень наші ортогональні є у ворматі (15 біт + знак) = 16-розряжне число
          */
          int amp_cos_U_fi;
          int amp_sin_U_fi;
  
          static unsigned int const index_I_ort[2] = {FULL_ORT_Imn, FULL_ORT_Ibp};
          static unsigned int const index_U_ort[2] = {FULL_ORT_Umn, FULL_ORT_Ubp};

#define SIN_I   ortogonal_local_calc[2*index_I_ort[i]    ]
#define COS_I   ortogonal_local_calc[2*index_I_ort[i] + 1]
#define SIN_U   ortogonal_local_calc[2*index_U_ort[i]    ]
#define COS_U   ortogonal_local_calc[2*index_U_ort[i] + 1]

          amp_cos_U_fi = (COS_U*a_cos_fi - SIN_U*a_sin_fi) >> AMPLITUDA_FI_VAGA; //З поверненням до початкової розрядності ортогональних
          amp_sin_U_fi = (SIN_U*a_cos_fi + COS_U*a_sin_fi) >> AMPLITUDA_FI_VAGA; //З поверненням до початкової розрядності ортогональних

          //Вираховуємо COS і SIN кута різниці між (U[i]+fi) і I[i]
          int cos_fi, sin_fi;
          /*
          З наведених теоретичних роззрахунків у функції обрахунку діючих значень (calc_measurement())
          випливає, що максимальне значення ортогональних для струму може бути 0x6E51, для лінійної напруги 
          0x120FC, то добуток їх має дати 0x7C87B7BC  - 31 бітне число (плюс знак біту)
          Тобто ми акладаємося у тип int.
          */
          cos_fi = amp_cos_U_fi*COS_I + amp_sin_U_fi*SIN_I;
          sin_fi = -(amp_sin_U_fi*COS_I - amp_cos_U_fi*SIN_I);//З розділу: "Неймовірно, але факт", тобто що я не можу пояснити

#undef SIN_I
#undef COS_I
#undef SIN_U
#undef COS_U

          /*
          З вище наведених розрахункыв виходить, що COS і SIN різниці струму і напруги може бути 31-бітне число
          Векторні координати границь секторів задано 7-бінтими числами + знак
          Тоді щоб не отримати переповнення треба гарантувати, що розрядність різниці векторів
          COS і SIN буде = 31 - (7 + 1) = 23
          7 - це розрядність координат векторів границь секторів
          1 - це врахування що ми використовіємо формулу (ab+cd)
          */
          unsigned int order_cos, order_sin, max_order, shift = 0;
          order_cos = get_order(cos_fi);
          order_sin = get_order(sin_fi);
          if (order_cos > order_sin) max_order = order_cos; else max_order = order_sin;
          if (max_order > 23) shift = max_order - 23;
  
          /*
          Сам зсув я роблю після визначення квадранта - це хоч і втрата на розмірі програмного коду,
          але мало б підвищити точність визначення квадранту.
          Хоч може тут я перемудровую?..
          */

          //Визначення сектору
          int sin_fi1_minus_fi2;
          int *sector;
          if ((sin_fi >= 0) && (cos_fi >= 0))
          {
            //1-ий квадрант
            cos_fi = cos_fi >> shift;
            sin_fi = sin_fi >> shift;
          
            if (sector_directional_mtz[msz][i] != 1)
              sector = sector_1_mtz_tznp;
            else
              sector = sector_2_mtz_tznp;
          
#define COS_SECTOR sector[0]    
#define SIN_SECTOR sector[1]    

            sin_fi1_minus_fi2 = sin_fi*COS_SECTOR - cos_fi*SIN_SECTOR;
            sector_directional_mtz[msz][i] = (sin_fi1_minus_fi2 <= 0) ?  1 : 0;
    
#undef COS_SECTOR    
#undef SIN_SECTOR   
          }
          else if ((sin_fi >= 0) && (cos_fi < 0))
          {
            //2-ий квадрант
            cos_fi = cos_fi >> shift;
            sin_fi = sin_fi >> shift;

            if (sector_directional_mtz[msz][i] != 2)
              sector = sector_1_mtz_tznp;
            else
              sector = sector_2_mtz_tznp;

#define COS_SECTOR sector[2]    
#define SIN_SECTOR sector[3]    

            sin_fi1_minus_fi2 = sin_fi*COS_SECTOR - cos_fi*SIN_SECTOR;
            sector_directional_mtz[msz][i] = (sin_fi1_minus_fi2 >= 0) ?  2 : 0;
    
#undef COS_SECTOR    
#undef SIN_SECTOR    
          }
          else if ((sin_fi < 0) && (cos_fi < 0))
          {
            //3-ий квадрант
            cos_fi = cos_fi >> shift;
            sin_fi = sin_fi >> shift;

            if (sector_directional_mtz[msz][i] != 2)
              sector = sector_1_mtz_tznp;
            else
              sector = sector_2_mtz_tznp;

#define COS_SECTOR sector[4]    
#define SIN_SECTOR sector[5]    

            sin_fi1_minus_fi2 = sin_fi*COS_SECTOR - cos_fi*SIN_SECTOR;
            sector_directional_mtz[msz][i] = (sin_fi1_minus_fi2 <= 0) ?  2 : 0;
    
#undef COS_SECTOR    
#undef SIN_SECTOR    
          }
          else
          {
            //4-ий квадрант
            cos_fi = cos_fi >> shift;
            sin_fi = sin_fi >> shift;

            if (sector_directional_mtz[msz][i] != 1)
              sector = sector_1_mtz_tznp;
            else
              sector = sector_2_mtz_tznp;

#define COS_SECTOR sector[6]    
#define SIN_SECTOR sector[7]    

            sin_fi1_minus_fi2 = sin_fi*COS_SECTOR - cos_fi*SIN_SECTOR;
            sector_directional_mtz[msz][i] = (sin_fi1_minus_fi2 >= 0) ?  1 : 0;
    
#undef COS_SECTOR    
#undef SIN_SECTOR    
          }
        }
      }
      else
      {
        for (unsigned int msz = 0; msz < amount; ++msz) sector_directional_mtz[msz][i] = 0;
      }
      /***/
    }
    else
    {
      Uxy_bilshe_porogu[i] = 0;
      Ix_bilshe_porogu[i] = 0;
      for (size_t msz = 0; msz < amount; ++msz) sector_directional_mtz[msz][i] = 0;
    }
  }
      
}
/*****************************************************/

/*****************************************************/
//Визначенням опорів
/*****************************************************/
inline void calc_resistance(int ortogonal_local_calc[], int resistance_output[]) 
{
  static const unsigned int index_line_voltage[2] = {FULL_ORT_Umn, FULL_ORT_Ubp};
  static const unsigned int index_current[2]= {FULL_ORT_Imn , FULL_ORT_Ibp};
  
  static unsigned int Ix_bilshe_porogu_R[2];

  //Міжфазний опір
  for (unsigned int i = 0; i < 2; i++)
  {
#define _A1     ortogonal_local_calc[2*index_line_voltage[i] + 0]
#define _B1     ortogonal_local_calc[2*index_line_voltage[i] + 1]

#define _A2     ortogonal_local_calc[2*index_current[i] + 0]
#define _B2     ortogonal_local_calc[2*index_current[i] + 1]
    
    long long mod = (long long)_A2*(long long)_A2 + (long long)_B2*(long long)_B2;
    

    //Розраховуємо діюче значення струму Ix
    unsigned int Ix = ( MNOGNYK_I_DIJUCHE*(sqrt_64(mod)) ) >> (VAGA_DILENNJA_I_DIJUCHE + 4);
    unsigned int porig_Ix = (Ix_bilshe_porogu_R[i] == 0) ? (PORIG_Ix_FOR_R*U_DOWN/100) : PORIG_Ix_FOR_R;
    Ix_bilshe_porogu_R[i]  = (Ix >= porig_Ix );
    if (Ix_bilshe_porogu_R[i])
    {
      //Можна розраховувати міжфазний опір
      /*
       .
      Uxy   Re(Uxy) + iIm(Uxy)   a1 + ib1    (a1 + ib1)(a2 - ib2)    (a1a2 + b1b2) + i(a2b1 - a1b2)    a1a2 + b1b2      a2b1 - a1b2
      --- = ------------------ = --------- = --------------------- = ------------------------------ =  ------------ + i--------------
       .                                                                     2      2                     2      2         2      2
      Ix     Re(Ix) + iIm(Ix)    a2 + ib2    (a2 + ib2)(a2 - ib2)          a2   + b2                    a2   + b2        a2   + b2
      */
      
      float R = MNOGNYK_R_FLOAT*((float)((long long)_A1*(long long)_A2 + (long long)_B1*(long long)_B2))/((float)mod);
      float X = MNOGNYK_R_FLOAT*((float)((long long)_A2*(long long)_B1 - (long long)_A1*(long long)_B2))/((float)mod);
      resistance_output[R_mn + 3*i    ] = (int)R;
      resistance_output[R_mn + 3*i + 1] = (int)X;
      
      float Z;
      arm_status res = arm_sqrt_f32((R*R + X*X), &Z);
      resistance_output[R_mn + 3*i + 2] = (res == ARM_MATH_SUCCESS) ? (int)Z : UNDEF_RESISTANCE;

      resistance_output[Za_mn + i] = 1000*U_LINEAR_NOM/Ix; /*Ixy_max треба проініціалізувати нулем. бо може бути випадок, що три лінійні струми менші за поріг чутливості і це треба якось зафіксуватим*/
    }
    else
    {
      //Не можна розраховувати міжфазний опір
      resistance_output[R_mn + 3*i    ] = UNDEF_RESISTANCE;
      resistance_output[R_mn + 3*i + 1] = UNDEF_RESISTANCE;
      resistance_output[R_mn + 3*i + 2] = UNDEF_RESISTANCE;
      
      resistance_output[Za_mn + i] =  UNDEF_RESISTANCE;
    }
    
#undef _A2
#undef _B2
    
#undef _A1
#undef _B1
  }
}
/*****************************************************/

/*****************************************************/
//Фазочутливий елемент  для опорів
/*****************************************************/
inline void directional_dz(int ortogonal_local_calc[], unsigned int number_group_stp) 
{
  for (size_t i = 0; i < 2; ++i)
  {
    static unsigned int const bit_configuration[2] = {DZO_BIT_CONFIGURATION, DZR_BIT_CONFIGURATION};
    static unsigned int Uxy_bilshe_porogu_dz[2];
    static unsigned int Ix_bilshe_porogu_dz[2];
    
    if ((current_settings_prt.configuration & (1u << bit_configuration[i])) != 0)
    {
      static unsigned int const index_I[2] = {IM_Imn, IM_Ibp};
      static unsigned int const index_U[2] = {IM_Umn, IM_Ubp};

      unsigned int porig_Uxy;
      if (Uxy_bilshe_porogu_dz[i] == 0) porig_Uxy = PORIG_CHUTLYVOSTI_VOLTAGE_ANGLE_DZ*KOEF_POVERNENNJA_SECTOR_BLK/100;
      else porig_Uxy = PORIG_CHUTLYVOSTI_VOLTAGE_ANGLE_DZ;
      Uxy_bilshe_porogu_dz[i] = (measurement[index_U[i]] >= porig_Uxy);
      
      unsigned int porig_Ix;
      if (Ix_bilshe_porogu_dz[i] == 0) porig_Ix = PORIG_CHUTLYVOSTI_CURRENT_ANGLE_DZ*KOEF_POVERNENNJA_SECTOR_BLK/100;
      else porig_Ix = PORIG_CHUTLYVOSTI_CURRENT_ANGLE_DZ;
      Ix_bilshe_porogu_dz[i]  = (measurement[index_I[i]] >= porig_Ix );

      if (
          (Uxy_bilshe_porogu_dz[i] != 0) &&
          (Ix_bilshe_porogu_dz[i]  != 0)
         )
      {
        static unsigned int const index_I_ort[2] = {FULL_ORT_Imn, FULL_ORT_Ibp};
        static unsigned int const index_U_ort[2] = {FULL_ORT_Umn, FULL_ORT_Ubp};

#define SIN_I   ortogonal_local_calc[2*index_I_ort[i]    ]
#define COS_I   ortogonal_local_calc[2*index_I_ort[i] + 1]
#define SIN_U   ortogonal_local_calc[2*index_U_ort[i]    ]
#define COS_U   ortogonal_local_calc[2*index_U_ort[i] + 1]

        //Вираховуємо COS і SIN кута різниці між U[i] і I[i]
        /*
        З наведених теоретичних роззрахунків у функції обрахунку діючих значень (calc_measurement())
        випливає, що максимальне значення ортогональних для струму може бути 0x6E51, для лінійної напруги 
        0x120FC, то добуток їх має дати 0x7C87B7BC  - 31 бітне число (плюс знак біту)
        Тобто ми вкладаємося у тип int.
        */
        int32_t sin_fi = -(SIN_I*COS_U - COS_I*SIN_U);//З розділу: "Неймовірно, але факт", тобто що я не можу пояснити
        int32_t cos_fi = COS_I*COS_U + SIN_I*SIN_U;

#undef SIN_I
#undef COS_I
#undef SIN_U
#undef COS_U

        /*
        З вище наведених розрахункыв виходить, що COS і SIN різниці струму і напруги може бути 31-бітне число
        Векторні координати границь секторів задано 7-бінтими числами + знак
        Тоді щоб не отримати переповнення треба гарантувати, що розрядність різниці векторів
        COS і SIN буде = 31 - (7 + 1) = 23
        7 - це розрядність координат векторів границь секторів
        1 - це врахування що ми використовіємо формулу (ab+cd)
        */
        uint32_t order_cos, order_sin, max_order, shift = 0;
        order_cos = get_order(cos_fi);
        order_sin = get_order(sin_fi);
        if (order_cos > order_sin) max_order = order_cos; else max_order = order_sin;
        if (max_order > 23) shift = max_order - 23;
        cos_fi = cos_fi >> shift;
        sin_fi = sin_fi >> shift;
  
        for (size_t dz = 0; dz < (4 - 2); ++dz)
        {
          /*
          За розрахунком описаним при розрахунку діючих значень наші ортогональні є у ворматі (15 біт + знак) = 16-розряжне число
          */
          /*
          const sector_LOW[A][B][C]
          A -> 0 - (4-2)
            [0] -> DZ2
            [1] -> DZ3

          B -> 0 - 2
            [0] -> Основна лінія
            [1] -> Резервна лінія

          C -> 0 - 2
            [0] -> сектор спрацювання
            [1] -> сектор відпускання

          D -> 0 - 2
            [0] -> SIN
            [1] -> COS
          */
          static int32_t (* const sector_LOW[4-2][2][2][2])[NUMBER_GROUP_USTAVOK] = {
                                                                                     {
                                                                                      {
                                                                                       {&current_settings_prt.pickup_dzo2_angle_sin1,  &current_settings_prt.pickup_dzo2_angle_cos1},
                                                                                       {&current_settings_prt.pickup_dzo2_angle_sin2,  &current_settings_prt.pickup_dzo2_angle_cos2}
                                                                                      },
                                                                                      {
                                                                                       {&current_settings_prt.pickup_dzr2_angle_sin1,  &current_settings_prt.pickup_dzr2_angle_cos1},
                                                                                       {&current_settings_prt.pickup_dzr2_angle_sin2,  &current_settings_prt.pickup_dzr2_angle_cos2}
                                                                                      },
                                                                                     },
                                                                                     {
                                                                                      {
                                                                                       {&current_settings_prt.pickup_dzo3_angle_sin1_l,  &current_settings_prt.pickup_dzo3_angle_cos1_l},
                                                                                       {&current_settings_prt.pickup_dzo3_angle_sin2_l,  &current_settings_prt.pickup_dzo3_angle_cos2_l}
                                                                                      }, 
                                                                                      {
                                                                                       {&current_settings_prt.pickup_dzr3_angle_sin1_l,  &current_settings_prt.pickup_dzr3_angle_cos1_l},
                                                                                       {&current_settings_prt.pickup_dzr3_angle_sin2_l,  &current_settings_prt.pickup_dzr3_angle_cos2_l}
                                                                                      }
                                                                                     }
                                                                                    };
          
          //Визначення сектору
          unsigned int v_zoni = (sector_directional_dz[dz][i] != SECTOR_DZ_NONE);
          
          int32_t const sector_L[2] = {
                                       (*sector_LOW[dz][i][v_zoni][0])[number_group_stp],
                                       (*sector_LOW[dz][i][v_zoni][1])[number_group_stp]
                                      };
          
          int32_t sector_H[2];
          if (dz == 0)
          {
            static const int32_t sector_HIGH[2][2] = {
                                                      {120, -44}, 
                                                      {115, -56}
                                                     };

            sector_H[0] = sector_HIGH[v_zoni][0];
            sector_H[1] = sector_HIGH[v_zoni][1];
          }
          else
          {
            static int32_t (* const sector_HIGH[2][2][2])[NUMBER_GROUP_USTAVOK] = {
                                                                                   { 
                                                                                    {&current_settings_prt.pickup_dzo3_angle_sin1_h,  &current_settings_prt.pickup_dzo3_angle_cos1_h},
                                                                                    {&current_settings_prt.pickup_dzo3_angle_sin2_h,  &current_settings_prt.pickup_dzo3_angle_cos2_h}
                                                                                   }, 
                                                                                   { 
                                                                                    {&current_settings_prt.pickup_dzr3_angle_sin1_h,  &current_settings_prt.pickup_dzr3_angle_cos1_h},
                                                                                    {&current_settings_prt.pickup_dzr3_angle_sin2_h,  &current_settings_prt.pickup_dzr3_angle_cos2_h}
                                                                                   }, 
                                                                                 };
            sector_H[0] = (*sector_HIGH[i][v_zoni][0])[number_group_stp];
            sector_H[1] = (*sector_HIGH[i][v_zoni][1])[number_group_stp];
          }
          
          int sin_fiH_minus_fi = sector_H[0]*cos_fi - sector_H[1]*sin_fi;
          int sin_fiL_minus_fi = sector_L[0]*cos_fi - sector_L[1]*sin_fi;
          
          if (sin_fiH_minus_fi >=0)
          {
            sector_directional_dz[dz][i] = (sin_fiL_minus_fi <=0) ? SECTOR_DZ_FORWARD : SECTOR_DZ_NONE;
          }
          else
          {
            sector_directional_dz[dz][i] = (sin_fiL_minus_fi >=0) ? SECTOR_DZ_BACKWARD : SECTOR_DZ_NONE;
          }
        }
      }
      else
      {
        for (size_t dz = 0; dz < (4 - 2); ++dz) sector_directional_dz[dz][i] = SECTOR_DZ_NONE;
      }
    }
    else
    {
      Uxy_bilshe_porogu_dz[i] = 0;
      Ix_bilshe_porogu_dz[i] = 0;
      for (size_t dz = 0; dz < (4 - 2); ++dz) sector_directional_dz[dz][i] = SECTOR_DZ_NONE;
    }
  }
}
/*****************************************************/

/*****************************************************/
//Визначенням миттєвої потужності
/*****************************************************/
inline void calc_power(int ortogonal_local_calc[]) 
{
  /*
  Розраховуємо дійсну і уявну частину потужності у компдексній площині
  
  .    . . 
  S = UaIa*
  */
  static const unsigned int index_line_voltage[2] = {FULL_ORT_Umn, FULL_ORT_Ubp};
  static const unsigned int index_current[2]= {FULL_ORT_Imn , FULL_ORT_Ibp};
  static const unsigned int index_meas_current[2] = {IM_Imn, IM_Ibp};
  
  unsigned int bank_for_enegry_tmp = bank_for_enegry;  
  for (size_t line = 0; line < 2; ++line)
  {
#define I_SIN          ortogonal_local_calc[2*index_current[line] + 1]
#define I_COS          ortogonal_local_calc[2*index_current[line] + 0]
#define U_SIN          ortogonal_local_calc[2*index_line_voltage[line] + 1]
#define U_COS          ortogonal_local_calc[2*index_line_voltage[line] + 0]
  
    long long P_adc_x16, Q_adc_x16; /*активнаф реактивна  потужності у поділках АЦП і з вхідними сигналами, які є підсилені у 16 разів*/
    if (measurement[index_meas_current[line]] >= PORIG_I_ENERGY)
    {
      P_adc_x16 = U_COS*I_COS + U_SIN*I_SIN;
      Q_adc_x16 = U_SIN*I_COS - U_COS*I_SIN;
    }
    else
    {
      P_adc_x16 = 0;
      Q_adc_x16 = 0;
    }

#undef I_SIN
#undef I_COS
#undef U_SIN
#undef U_COS
  
    /*
    Коли перемножимо на коефіцієнти MNOGNYK_I_DIJUCHE_FLOAT і MNOGNYK_U_DIJUCHE_FLOAT,
    а потім поділемо на 16x16 - то отримаємо мАхмВ = мкВт/мкВАр/мкВА
  
    Ми хочемо тримати число у мВт/мВАр/мВА. 
  
    Тоді треба поділити ще на 1000
    */
  
    //Активна потужність
    double P_float = ((double)P_adc_x16) * ((double)(MNOGNYK_I_DIJUCHE_DOUBLE*MNOGNYK_U_DIJUCHE_DOUBLE/(1000.0*16.0*16.0)));
    int P_tmp = (int)(P_float); // з точністю до мВт

    //Реактивна потужність
    double Q_float = ((double)Q_adc_x16) * ((double)(MNOGNYK_I_DIJUCHE_DOUBLE*MNOGNYK_U_DIJUCHE_DOUBLE/(1000.0*16.0*16.0)));
    int Q_tmp  = (int)(Q_float); // з точністю до мВАр

    int (*energy_array)[2];
  
    //Активна потужність
    if (P_tmp >= 0) energy_array = P_plus;
    else energy_array = P_minus;
    *(energy_array + bank_for_enegry_tmp)[line] += abs(P_tmp);
  
    //Реактивна потужність
    if     ((Q_tmp >= 0) && (P_tmp >= 0)) energy_array = Q_1q;
    else if((Q_tmp >= 0) && (P_tmp <  0)) energy_array = Q_2q;
    else if((Q_tmp <  0) && (P_tmp <  0)) energy_array = Q_3q;
    else                                  energy_array = Q_4q;
    *(energy_array + bank_for_enegry_tmp)[line] += abs(Q_tmp);
  }
  
  if (++lichylnyk_1s_po_20ms >= MAIN_FREQUENCY)
  {
    if (lichylnyk_1s_po_20ms > MAIN_FREQUENCY)
    {
      //Теоретично цього ніколи не мало б бути
      total_error_sw_fixed();
    }

    //Переключаємо банк для збереження нових даних s обнулюємо значення у новому банку
    bank_for_enegry = bank_for_enegry_tmp = (bank_for_enegry_tmp + 1) & 0x1;
    for (size_t line = 0; line < 2; ++line)
    {
      P_plus[bank_for_enegry_tmp][line] = 0;
      P_minus[bank_for_enegry_tmp][line] = 0;
      Q_1q[bank_for_enegry_tmp][line] = 0;
      Q_2q[bank_for_enegry_tmp][line] = 0;
      Q_3q[bank_for_enegry_tmp][line] = 0;
      Q_4q[bank_for_enegry_tmp][line] = 0;
    }
    
    lichylnyk_1s_po_20ms = 0;
    if (periodical_tasks_CALC_ENERGY_DATA == 0)
    {
      //Скидаємо повідомлення у слові діагностики
      _SET_BIT(clear_diagnostyka, LOSE_ENERGY_DATA);
    }
    else
    {
      //Виствляємо повідомлення у слові діагностики
      _SET_BIT(set_diagnostyka, LOSE_ENERGY_DATA);
    }
    periodical_tasks_CALC_ENERGY_DATA = true;
  }
  
}
/*****************************************************/

/*****************************************************/
//Розрахунки віимірювань
/*****************************************************/
void calc_measurement(unsigned int number_group_stp)
{
  int ortogonal_local[2*(NUMBER_ANALOG_CANALES + 2)];

  //Виставляємо семафор заборони обновлення значень з вимірювальної системи
//  semaphore_measure_values = 1;

  //Копіюємо вхідні велечини у локальні змінні
  /*
  оскільки для дискретного перетворення Фурє коефіцієнти діляться на число виборок і множиться на 2 (еквівалент 2/Т),
  то це ми можемо зробити зміщенням
  */
  /*
  Проведені мною розрахунки показують, що якщо просумувати добуток миттєвих значень на синус/косинус за період,
  а потім результат поділити на 2/Т (зробити це відповідним зсуваом, про який я писав вище),
  то максимана розрядність резутьтату буде рівна макисальній розрядності вхідного сигналу
  Тобто для 3I0            - це 19 біт + знак = ((11 біт + знак)*16*16)
        для фазних струмів - це 15 біт + знак = ((11 біт + знак)*16   )
  оскільки нам ще треба це число піднімати до квадрату а аж потім добувати корінь квадратний з суми квадратів, то
  фазний струм можна підносити до кваррату - переповнення не буде, бо (15 біт *2) = 30 біт Бо 32 біт unsigned int
  А аж потім забрати множенння на 16, щоб збільшити точність вимірювання
  
  Для 3I0 можливе переповнення - тому треба або:
  1.  
  Перше 16-кратне підсилення забрати прямо з ортогональних для 3I0,
  тоді ортогоанльні стануть не більше 15-розрядного числа + знак.
  Друге 16-кратне підсилення забрати вже в остаточному результаті
    
  2.Використати 64-бітну арифметику.
    
  До 17 листопада 2014 року використовуввся перший метод.
  Але виникала похибка при розрахунку стуму вищих гармонік. Припускаю, що могло бути
  зв'язане з тим, що коли відкидадися молодші розряди - то струм першої гармоніки ставав
  трохи меншим за ремальне значення - а тоді виростав струм вищих гармонік
    
  Тому пробую використати другий метод з 17 листопада 2014 року  
  
  Для покращення точності з 18 листопада 2014 року я забираю амплітуду sin/cos вже
  перед самими розрахунками
  */
  
  unsigned int bank_ortogonal_tmp = (bank_ortogonal + 1) & 0x1;
  for(unsigned int i=0; i<(2*(NUMBER_ANALOG_CANALES + 2)); i++ )
  {
    ortogonal_local[i] = ortogonal[i][bank_ortogonal_tmp];
  }
  bank_ortogonal = bank_ortogonal_tmp;
  
  freq_mutex = true;
  frequency = frequency_high;
  freq_mutex = false;

  
  /*******************************************************/
  //Перевіряємо, чи відбувалися зміни юстування
  /*******************************************************/
  if (changed_ustuvannja == CHANGED_ETAP_ENDED_EXTRA_ETAP) /*Це є умова, що нові дані підготовлені для передачі їх у роботу системою захистів(і при цьому зараз дані не змінюються)*/
  {
    //Копіюємо масив юстування у копію цього масиву але з яким працює (читає і змінює) тільки вимірювальна захистема
    for(unsigned int i = 0; i < NUMBER_ANALOG_CANALES; i++) 
    {
      phi_ustuvannja_meas[i] = phi_ustuvannja[i];
      phi_ustuvannja_sin_cos_meas[2*i    ] = phi_ustuvannja_sin_cos[2*i    ];
      phi_ustuvannja_sin_cos_meas[2*i + 1] = phi_ustuvannja_sin_cos[2*i + 1];
    }
      
    //Помічаємо, що зміни прийняті системою захистів
    changed_ustuvannja = CHANGED_ETAP_NONE;
  }
  /*****************************************************/

  /***
  Довертаємо кути і копіюємо ортогональні для низькопріоритетних задач
  ***/
  static const unsigned int index_input_arr[NUMBER_ANALOG_CANALES]  = {I_Imn, I_Ibp + 1, I_Umn  + 2, I_Ubp + 2};
  for (unsigned int i = 0; i < NUMBER_ANALOG_CANALES; i++)
  {
    size_t index_input = index_input_arr[i];
    float sin_alpha = ((float)ortogonal_local[2*index_input    ])/((float)((1 << (VAGA_NUMBER_POINT - 1))));
    float cos_alpha = ((float)ortogonal_local[2*index_input + 1])/((float)((1 << (VAGA_NUMBER_POINT - 1))));
    
    float sin_beta =  phi_ustuvannja_sin_cos_meas[2*i    ];
    float cos_beta =  phi_ustuvannja_sin_cos_meas[2*i + 1];
    
    unsigned int new_index = index_converter[i];
    ortogonal_calc[2*new_index    ] = (int)(sin_alpha*cos_beta + cos_alpha*sin_beta);
    ortogonal_calc[2*new_index + 1] = (int)(cos_alpha*cos_beta - sin_alpha*sin_beta);
  }
  
  static const unsigned int index_input_other_arr[2] = {I_Imn + 1, I_Ibp + 2};
  for (size_t i = NUMBER_ANALOG_CANALES; i < (NUMBER_ANALOG_CANALES + 2); i++)
  {
    size_t index_input = index_input_other_arr[i - NUMBER_ANALOG_CANALES];
    size_t new_index = index_converter[i];
    ortogonal_calc[2*new_index    ] = ortogonal_local[2*index_input    ] >> (VAGA_NUMBER_POINT - 1);
    ortogonal_calc[2*new_index + 1] = ortogonal_local[2*index_input + 1] >> (VAGA_NUMBER_POINT - 1);
  }


  /***
  Копіюємо ортогональні для низькопріоритетних задач
  ***/
  if (semaphore_measure_values_low == 0)
  {
    for (size_t i = 0; i < (2*FULL_ORT_MAX_TOTAL); i++) ortogonal_calc_low[i] = ortogonal_calc[i];
  }   
/***/
  
  
  /*
  ---------------------------------------------------------------------------------------------------------
  150А (150 000мА) - максимальний фазний струм
  Коефіцієнст переведення в мА  - Koef_1 = 84,978173543997808495193432804655 для фазних струмів (5439/64 = 84,984375)
  
  Тоді для 150А максимально можливе значення ортогональних може бути
  150000/Koef_1 = 1765,0303364589078874793160507446
  Якщо врахувати, що сигнал є підсиленим у 16 раз, то максимальне значення ортогональних може бути
  16*150000/Koef_1 = 28240,485383342526199669056811914 < 28241(0x6E51) це є 15 бітне число (+ можливий знак)
  ---------------------------------------------------------------------------------------------------------

  ---------------------------------------------------------------------------------------------------------
  150В (150 000мВ) - максимальна фазна напруга
  Коефіцієнст переведення в мВ  - Koef_1 = 64,883134509545420915167731259667 для фазних напруг (4152/64 = 64,875)
  
  Тоді для 150В максимально можливе значення ортогональних може бути
  150000/Koef_1 = 2311,848851536795430557291797995
  Якщо врахувати, що сигнал є підсиленим у 16 раз, то максимальне значення ортогональних може бути
  16*150000/Koef_1 = 36989,581624588726888916668767919 < 36990(0x907E) це є 16 бітне число (+ можливий знак) - тобто число виходить 17-бітне
  
  Якщо з фазної напруги розраховується лінійна напруга, то, якзо припустити що вектори розврнуті у різні сторони, то  максимальне
  значення ортогональних може бути
  2*16*150000/Koef_1 = 73979,163249177453777833337535838 < 73980(0x120FC) це є 17 бітне число (+ можливий знак) - тобто число виходить 18-бітне
  ---------------------------------------------------------------------------------------------------------
  */
  
  /***/
  //Розраховуємо діюче значення через перетворення Фур'є
  /***/
  for(size_t i = 0; i < _NUMBER_IM; i++)
  {
    if ((i <= IM_Ibp) || (i >= IM_3Imn))
    {
      unsigned int index_ort = 0;
      switch (i)
      {
      case IM_Imn:
        {
          index_ort = FULL_ORT_Imn;
          break;
        }
      case IM_Ibp:
        {
          index_ort = FULL_ORT_Ibp;
          break;
        }
      case IM_3Imn:
        {
          index_ort = FULL_ORT_3Imn;
          break;
        }
      case IM_3Ibp:
        {
          index_ort = FULL_ORT_3Ibp;
          break;
        }
      default:
        {
          //Теоретично цього ніколи не мало б бути
          total_error_sw_fixed();
        }
      }
      
      measurement[i] = ( MNOGNYK_I_DIJUCHE*(sqrt_32((unsigned int)(ortogonal_calc[2*index_ort]*ortogonal_calc[2*index_ort]) + (unsigned int)(ortogonal_calc[2*index_ort+1]*ortogonal_calc[2*index_ort+1]))) ) >> (VAGA_DILENNJA_I_DIJUCHE + 4);
    }
    else
    {
      unsigned int index_ort = 0;
      switch (i)
      {
      case IM_Umn:
        {
          index_ort = FULL_ORT_Umn;
          break;
        }
      case IM_Ubp:
        {
          index_ort = FULL_ORT_Ubp;
          break;
        }
      default:
        {
          //Теоретично цього ніколи не мало б бути
          total_error_sw_fixed();
        }
      }
      
      measurement[i] = ( MNOGNYK_U_DIJUCHE*(sqrt_32((unsigned int)(ortogonal_calc[2*index_ort]*ortogonal_calc[2*index_ort]) + (unsigned int)(ortogonal_calc[2*index_ort+1]*ortogonal_calc[2*index_ort+1]))) ) >> (VAGA_DILENNJA_U_DIJUCHE + 4);
    }
    
  }
  /***/

  /***/
  //Фазочутливий елемент для ДЗ (всіх ступенів)
  /***/
  directional_dz(ortogonal_calc, number_group_stp);
  /***/

  /***/
  //Фазочутливий елемент для МТЗ (всіх ступенів)
  /***/
  directional_mtz(ortogonal_calc, number_group_stp);
  /***/

  /***/
  //Розраховуємо опори
  /***/
  calc_resistance(ortogonal_calc, resistance);
  /***/

  if(++number_inputs_for_fix_one_period >= 20)
  {
    /***/
    //Розрахунок миттєвих потужностей (раз на 20мс)
    /***/
    calc_power(ortogonal_calc);
    /***/
    
    number_inputs_for_fix_one_period = 0;
  }
}
/*****************************************************/

/*****************************************************/
//
/*****************************************************/
/*****************************************************/
