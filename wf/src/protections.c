#include "header.h"

int32_t p_rele_reprogram_command = -1;
int32_t p_rele_staff_command = -1;
int32_t timerWaitReprogram = -1;

unsigned int number_max_phase_o_dr;
unsigned int number_max_phase_r_dr;
unsigned int number_min_U_dr;
unsigned int number_max_U_dr;
unsigned int number_min_r_o_dr;
unsigned int number_min_r_r_dr;
unsigned int number_min_f_achr_dr;
unsigned int number_f_chapv_dr;

unsigned int state_current_monitoring;
unsigned int measurements_phase_o_max_dr[SIZE_ARRAY_FIX_MAX_MEASUREMENTS];
unsigned int measurements_phase_r_max_dr[SIZE_ARRAY_FIX_MAX_MEASUREMENTS];
unsigned int measurements_U_min_dr[SIZE_ARRAY_FIX_MAX_MEASUREMENTS];
unsigned int measurements_U_max_dr[SIZE_ARRAY_FIX_MAX_MEASUREMENTS];
unsigned int measurements_r_o_min_dr[SIZE_ARRAY_FIX_MAX_MEASUREMENTS];
unsigned int measurements_r_r_min_dr[SIZE_ARRAY_FIX_MAX_MEASUREMENTS];
unsigned int measurements_f_min_achr_dr[SIZE_ARRAY_FIX_MAX_MEASUREMENTS];
unsigned int measurements_f_chapv_dr[SIZE_ARRAY_FIX_MAX_MEASUREMENTS];

void copy_meas_for_dr(unsigned int* const);
void start_monitoring_max_phase_o_current(unsigned int);
void continue_monitoring_max_phase_o_current(unsigned int);
void start_monitoring_max_phase_r_current(unsigned int);
void continue_monitoring_max_phase_r_current(unsigned int);
void start_monitoring_min_U(unsigned int);
void continue_monitoring_min_U(unsigned int);
void start_monitoring_max_U(unsigned int);
void continue_monitoring_max_U(unsigned int);
void start_monitoring_min_r_o_current(unsigned int);
void continue_monitoring_min_r_o_current(unsigned int);
void start_monitoring_min_r_r_current(unsigned int);
void continue_monitoring_min_r_r_current(unsigned int);
void start_monitoring_min_f(unsigned int);
void continue_monitoring_min_f(unsigned int);

const __meas_to_d_meas im_to_idm[_SIZE_ARRAY_FIX_MAX_MEASUREMENTS_TMP] =
{
  {(void const *)measurement, IM_Imn},
  {(void const *)measurement, IM_Ibp},
  
  {(void const *)measurement, IM_Umn},
  {(void const *)measurement, IM_Ibp},
  
  {(void const *)measurement, IM_3Imn},
  {(void const *)measurement, IM_3Ibp},
  

  {(void const *)&frequency, 0},

  {(void const *)resistance, R_mn},
  {(void const *)resistance, X_mn},
  {(void const *)resistance, Z_mn},
  {(void const *)resistance, R_bp},
  {(void const *)resistance, X_bp},
  {(void const *)resistance, Z_bp}
};

/*****************************************************/
//Діагностика АЦП
/*****************************************************/
inline void diagnostyca_adc_execution(void)
{
  if ((vref_adc <0x709) || (vref_adc > 0x8f5)) _SET_BIT(set_diagnostyka, ERROR_VREF_ADC_TEST_BIT);
  else _SET_BIT(clear_diagnostyka,ERROR_VREF_ADC_TEST_BIT);
}
/*****************************************************/

#include "dz.c"

/*****************************************************/
//Модуль обробки дискретних входів
/*****************************************************/
inline void input_scan(void)
{
  unsigned int state_inputs_into_pin = 0; //Змінні у якій формуємо значення входів отримані із входів процесора (пінів)
  static unsigned int state_inputs_into_pin_trigger; //У цій змінній зберігається попередній стан піна, у випадку коли ми перевіряємо .чи утримається цей стан до кінця тактування таймера допуску

  /***************************/
  //У цій частині знімаємо стани входів процесора (пінів), які відповідають за дискретні входи
  /*
  -----------------------------
  значення поміщається у відпорвідні біти змінної state_inputs_into_pin
    "є     сигнал " - відповідає встановленому біту (1)
    "немає сигналу" - відповідає скинутому     біту (0)
  -----------------------------
  */
  state_inputs_into_pin |=  ( _DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD33_DD36)       & 0xffff)
#if (                                   \
     (MODYFIKACIA_VERSII_PZ == 0) ||    \
     (MODYFIKACIA_VERSII_PZ == 10)      \
    )                                   
                         | (((_DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD26_DD29) >>  8) & 0xf) << 16)
#elif (                                   \
       (MODYFIKACIA_VERSII_PZ == 5) ||    \
       (MODYFIKACIA_VERSII_PZ == 15)      \
      )                                   
                         | (((_DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD26_DD29) >> 12) & 0xf) << 16)
#endif
                        ;
  /***************************/
  
  /***************************/
  //Обробка таймерів допуску дискретних входів
  /***************************/
  for(unsigned int i = 0; i < NUMBER_INPUTS; i++)
  {
    unsigned int maska = 1<<i;
    int max_value_timer = current_settings_prt.dopusk_dv[i];

    if (global_timers[INDEX_TIMER_INPUT_START + i] < 0)
    {
      //Провірка на зміну стану дискретного входу здійснюється тільки тоді, коли величина таймере є від'ємною
      //Що означає що таймер не запущений у попередній момент
      
      //Перевіряємо чи таеперішній стан входу відповідає попердньомук стану
      if ((state_inputs_into_pin & maska) != (state_inputs & maska))
      {
        //Якщо стан входу змінився, то виконуємо дії по зміні стану

        //1-дія: Запям'ятовуємо текучий стан входу
        state_inputs_into_pin_trigger &= ~maska;
        state_inputs_into_pin_trigger |= (state_inputs_into_pin & maska);

        //2-дія: Запускаємо таймер допуску дискретного входу
        global_timers[INDEX_TIMER_INPUT_START + i] = 0;
      }
    }
    else
    {
      //Якщо таймер запущений виконуємо дії з таймером
      if (global_timers[INDEX_TIMER_INPUT_START + i] < max_value_timer)
      {
        //Якщо таймер ще не дійшов до свого макисмуму, то просто збільшуємо його величину
        global_timers[INDEX_TIMER_INPUT_START + i] += DELTA_TIME_FOR_TIMERS;
        
        //У випадку, якщо тип сигналу на вхід подається змінний
        //і ми перевіряємо чи не відбувся перехід "є сигнал"->"немає сигналу"
        //то поява сигналу під час тактування таймера допуску означає, що сигнал на вході є - 
        //а це означає, що треба зупинити nаймер, бо переходу "є сигнал"->"немає сигналу" на протязі тактування таймеру не зафіксовано 
        if ((current_settings_prt.type_of_input_signal & maska) != 0)
        {
           if ((state_inputs_into_pin_trigger & maska) == 0)
           {
             if ((state_inputs_into_pin & maska) != 0)
               global_timers[INDEX_TIMER_INPUT_START + i] = -1;
           }
        }
      }
    }
    
    //Якщо величина таймера допуска знаходиться у свому максимальному значенні, то перевіряємо, чи фактично змінився стано входу
    if (global_timers[INDEX_TIMER_INPUT_START + i] >= max_value_timer)
    {
      //Перевіряємо, чи стан піна змінився у порівнянні із станом, який був на момент запуску таймера допуску дискретного входу
      unsigned int state_1, state_2;
        
      state_1 = state_inputs_into_pin_trigger & maska;
      state_2 = state_inputs_into_pin  & maska;
        
      if (state_1 == state_2)
      {
        //Якщо два стани співпадають, то ми вважаємо, що відбулася зіна стану дискретного входу і формуємо новий стан входу
        //При цьому враховуємо що для прявого    входу 1 - це активний вхід, а 0 - це пасивний вхід
        //                        для інверсного входу 0 - це активний вхід, а 1 - це пасивний вхід
          state_inputs &=  ~maska;
          state_inputs |=   state_2;
      }
        
      //У будь-якому випадк, чи змінився стан входу, чи ні, а оскілька таймер допуску дотактував до кінця, то скидаємотаймер у висхідне від'ємне занчення
      global_timers[INDEX_TIMER_INPUT_START + i] = -1;
    }
  }
  /***************************/
  
  /***************************/
  //Визначаємо, який сигнал є зараз активним
  /***************************/
  active_inputs = (state_inputs ^ current_settings_prt.type_of_input);
  /***************************/
  
}
/*****************************************************/

/*****************************************************/
//Функція обробки таймерів
/*****************************************************/
inline void clocking_global_timers(void)
{
  //Опрацьовуємо дискретні входи
  input_scan();
  
  //опрацьовуємо всі решта таймери логіки
  for (int *p = (global_timers + (INDEX_TIMER_INPUT_START + NUMBER_INPUTS)); p != (global_timers + NEXT_TIMER); ++p)
  {
    if (*p >= 0)
    {
      //Першою умовою того, що таймер треба тактувати є той факт, що величина таймеру не від'ємна

      //Перевіряємо чи треба збільшувати величину таймеру, якщо він ще не досягнув свого максимуму
      if (*p <= (0x7fffffff - DELTA_TIME_FOR_TIMERS)) *p += DELTA_TIME_FOR_TIMERS;
    }
  }

  if ((POWER_CTRL->IDR & POWER_CTRL_PIN) != (uint32_t)Bit_RESET) 
  {
    timePowerDown_total = timePowerDown = -1;
  }
  else
  {
    if (timePowerDown < 0) timePowerDown = 0;
    else if (
             (timePowerDown >= 0) &&
             (timePowerDown <= (0x7fffffff - DELTA_TIME_FOR_TIMERS))  
            )
    {
      timePowerDown += DELTA_TIME_FOR_TIMERS;
    }

    if (timePowerDown_total < 0) timePowerDown_total = 0;
    else if (
             (timePowerDown_total >= 0) &&
             (timePowerDown_total <= (0x7fffffff - DELTA_TIME_FOR_TIMERS))  
            )
    {
      timePowerDown_total += DELTA_TIME_FOR_TIMERS;
    }
  }


  
  if (++timer_prt_signal_output_mode_2 >= PERIOD_SIGNAL_OUTPUT_MODE_2)
  {
    timer_prt_signal_output_mode_2 = 0;
    output_timer_prt_signal_output_mode_2 ^= true;
  }
  
  //Управління поляризованим реле для перепрограмування
  if (
      (p_rele_reprogram_command < 0) && 
      (p_rele_staff_command < 0)  
     )
  {
    if (_GET_STATE(reprogram_device, REPROGRAM_COMMAND))
    {
      p_rele_reprogram_command = 0;
      GPIO_REPROGRAM->BSRRL = GPIO_PIN_REPROGRAM;
    }

    if (_GET_STATE(reprogram_device, STAFF_COMMAND))
    {
      p_rele_staff_command = 0;
      GPIO_STAFF->BSRRL = GPIO_PIN_STAFF;
    }
  }
  else
  {
    int32_t * point_p_rele = NULL;
    if (p_rele_reprogram_command >= 0) point_p_rele = &p_rele_reprogram_command;
    else point_p_rele = &p_rele_staff_command;

    if (*point_p_rele < (0x7fffffff - DELTA_TIME_FOR_TIMERS)) *point_p_rele += DELTA_TIME_FOR_TIMERS;
    if (*point_p_rele >= TIMEOUT_IMPULSE_P_RELE_REPROGRAM_STAFF)
    {
      *point_p_rele = -1;
      
      if (point_p_rele == &p_rele_reprogram_command) 
      {
        _CLEAR_STATE(reprogram_device, REPROGRAM_COMMAND);
        GPIO_REPROGRAM->BSRRH = GPIO_PIN_REPROGRAM;
      }
      else if (point_p_rele == &p_rele_staff_command) 
      {
        _CLEAR_STATE(reprogram_device, STAFF_COMMAND);
        GPIO_STAFF->BSRRH = GPIO_PIN_STAFF;
      }
      else
      {
        //Теоретично цього ніколи не мало б бути
        total_error_sw_fixed();
      }
    }
  }
  
  if (p_rele_reprogram_command == 0) timerWaitReprogram = 0;
  else
  {
    if (timerWaitReprogram >= 0) 
    {
      if (++timerWaitReprogram > (2*TIMEOUT_IMPULSE_P_RELE_REPROGRAM_STAFF))
      {
        //Режим перепрограмування не підтримується
        timerWaitReprogram = -1;
        _SET_STATE(reprogram_device, UNSUPPORT_REPROGRAM);
          
      }
    }
  }
}
/*****************************************************/

/*****************************************************/
//Опрацювання Ориділювальних функцій - має запускатися після відкрпацювання блоків всіх захистів
/*****************************************************/
inline void df_handler(unsigned int *p_active_functions)
{
  unsigned int logic_df[NUMBER_DEFINED_FUNCTIONS];
  
  //Визначаємо, чи активовуються опреділювані функції через свої ранжовані функції-джерела
  for (size_t i = 0; i < NUMBER_DEFINED_FUNCTIONS; ++i)
  {
    unsigned int * const p_logic_df = (logic_df + i);
    *p_logic_df = 0;
    unsigned int const shift = 3*i;
    
    unsigned int const rang_df_in = RNG_BIG_DF1_IN + shift;
    unsigned int const number_byte_in = rang_df_in >> 5;
    unsigned int const number_bit_in = rang_df_in & 0x1f;

    /***
    Джерело активації ОФ-ії
    ***/
    *p_logic_df |= ((p_active_functions[number_byte_in] & (1 << number_bit_in) ) >> number_bit_in ) << 0;
    //Перевіряємо ще, чи не іде утимування активним джерела ОФ через таймер-утримування (для активації через кнопки або інтерфейс)
    if (global_timers[INDEX_TIMER_DF_PROLONG_SET_FOR_BUTTON_INTERFACE_START + i] >= 0)
    {
      //Таймер запущений, або вже зупинився
      //Факт запуску цього таймеру означає, що активація відбувалася через кнопку, або інтерфейс
      //Тому для забеспечення роботи логічної схеми до кінця роботи цього таймеру виставляємо, що джерело активації активне
      *p_logic_df |= (1 << 0);
      
      //Відмічаємо, джерело активації утримуємться у активному стані у масиві активуючих функцій
      p_active_functions[number_byte_in] |= (1 << number_bit_in);
      
      //У випадку, якщо таймер дійшов до свого макисального значення, то скидаємо роботу цього таймеру
      if (global_timers[INDEX_TIMER_DF_PROLONG_SET_FOR_BUTTON_INTERFACE_START + i] >= ((int)current_settings_prt.timeout_pause_df[i]))
        global_timers[INDEX_TIMER_DF_PROLONG_SET_FOR_BUTTON_INTERFACE_START + i] = -1;
    }
    /***/

    int flag=0;
    for(int m=0; m<N_BIG; m++) if( ( current_settings_prt.ranguvannja_df_source_plus[N_BIG*i    +m] & p_active_functions[m] ) != 0) {flag=1; break;}
    if(flag)
    {
      *p_logic_df |= (1 << 0);
    }

    flag=0;
    for(int m=0; m<N_BIG; m++) if( ( current_settings_prt.ranguvannja_df_source_minus[N_BIG*i    +m] & ((unsigned int)(~p_active_functions[m])) ) != 0 ) {flag=1;break;}
    if(flag)
    {
      *p_logic_df |= (1 << 0);
    }

    flag=1;
    for(int m=0; m<N_BIG; m++) if( ( current_settings_prt.ranguvannja_df_source_blk[N_BIG*i    +m] & p_active_functions[m] ) != 0 ) {flag=0; break;}
    if(flag)
    {
      *p_logic_df |= (1 << 1);
    }
    
    /***
    Виконуємо у цьому місці обробку логіки без встанвлення/скидання бітів про стан Визначуваної функції
    Щоб новий стан попередньої функції не був включений у стан наступної
    ***/
    *p_logic_df |= (_CHECK_SET_BIT(p_active_functions, (RNG_BIG_DF1_RST + shift)) != 0) << 5;
//    flag = 0;
//    for(size_t m = 0; m < N_BIG; ++m) if( ( current_settings_prt.ranguvannja_df_source_reset[N_BIG*i + m] & p_active_functions[m] ) != 0) {flag = 1; break;}
//    if(flag)
//    {
//      *p_logic_df |= (1u << 5);
//    }

		_INVERTOR((*p_logic_df), 5, (*p_logic_df), 6);
    _AND2((*p_logic_df), 0, (*p_logic_df), 6, (*p_logic_df), 7);
    
    _TIMER_T_0(INDEX_TIMER_DF_PAUSE_START + i, current_settings_prt.timeout_pause_df[i], (*p_logic_df), 7, (*p_logic_df), 2);
    
    if ((current_settings_prt.type_df & (1 << i)) == 0)
    {
      _TIMER_IMPULSE_R(INDEX_TIMER_DF_WORK_START + i, current_settings_prt.timeout_work_df[i], (*p_logic_df), 5, static_logic_df, i, (*p_logic_df), 2, (*p_logic_df), 3);
    }
    else
    {
      _TIMER_0_T_R    (INDEX_TIMER_DF_WORK_START + i, current_settings_prt.timeout_work_df[i], (*p_logic_df), 5,                     (*p_logic_df), 2, (*p_logic_df), 3);
      static_logic_df &= ~(1u << i);
    }
      
    _AND2((*p_logic_df), 3, (*p_logic_df), 1, (*p_logic_df), 4);
    /***/

    
  }
  
  //Установлюємо, або скидаємо ОФ у масиві функцій, які зараз будуть активовуватися
  /*
  Цей цикл і попередній не об'єднаі в один, а навпаки розєднані, бо у першому ми використовуємо
  масив p_active_functions у якому ще не встановлені виходи ОФ-ій, тому що інші ОФ-ії
  можуть бути джерелом активації, але джерелом активації може буте попереднє значення ОФ, а не те,
  що зараз встановлюється. А оскілдьки у другому масиві ми встановлюємо значення у масиві
  p_active_functions, які набувають зараз тільки ваги, то щоб не вийшло об'єднання попереднього значення
  і теперішнього то цикли роз'єднані (цикл аналізу джерел і логіки з циклом активації/деактивації)
  */
  for (size_t i = 0; i < NUMBER_DEFINED_FUNCTIONS; ++i)
  {
    //Установлюємо, або скидаємо ОФ
    unsigned int const index_df = RNG_BIG_DF1_OUT + 3*i;
      
    if ((logic_df[i] & (1u << 4)) != 0 ) _SET_BIT(p_active_functions, index_df);
    else _CLEAR_BIT(p_active_functions, index_df);
  }
}
/*****************************************************/

/*****************************************************/
//Опрацювання Ориділювальних триґерів - має запускатися після відкрпацювання опреділювальних функцій
/*****************************************************/
inline void dt_handler(unsigned int *p_active_functions)
{
  /*
  Попередній стан визначуваних триґерів формуємо у state_defined_triggers
  Джерела встановлення формуємо в source_set_dt
  Джерела скидання формуємо в source_reset_dt
  */
  unsigned int state_defined_triggers = 0, source_set_dt = 0, source_reset_dt = 0;
  for (size_t i = 0; i < NUMBER_DEFINED_TRIGGERS/*current_settings_prt.number_defined_dt*/; ++i)
  {
    unsigned int const shift = 3*i;

    unsigned int const rang_df_set   = RNG_BIG_DT1_SET + shift;
    unsigned int const number_byte_set = rang_df_set >> 5;
    unsigned int const number_bit_set  = rang_df_set & 0x1f;

    unsigned int const rang_df_reset = RNG_BIG_DT1_RESET + shift;
    unsigned int const number_byte_reset = rang_df_reset >> 5;
    unsigned int const number_bit_reset  = rang_df_reset & 0x1f;
    
    unsigned int const index_dt = RNG_BIG_DT1_OUT + shift;

    state_defined_triggers |= ( (p_active_functions[index_dt >> 5] & ( 1 << (index_dt & 0x1f) ) ) >> (index_dt & 0x1f) ) << i;
    /***
    Джерела встановлення і скидання ОТ
    ***/
    source_set_dt   |= ((p_active_functions[number_byte_set  ] & (1 << number_bit_set  ) ) >> number_bit_set   ) << i;
    source_reset_dt |= ((p_active_functions[number_byte_reset] & (1 << number_bit_reset) ) >> number_bit_reset ) << i;
    /***/
  }
  
  //Визначаємо, чи встановлюються/скидаються опреділювані триґери через свої ранжовані функції-джерела
  for (size_t i = 0; i < NUMBER_DEFINED_TRIGGERS/*current_settings_prt.number_defined_dt*/; ++i)
  {
    int flag=0;
    for(int m=0; m<N_BIG; m++) if(current_settings_prt.ranguvannja_set_dt_source_plus[N_BIG*i    +m] !=0) {flag=1; break;}
    if (flag)
    {
      //Випадок, якщо функції зранжовані на джерело прямих функцій
      flag=0;
      for(int m=0; m<N_BIG; m++) if(( current_settings_prt.ranguvannja_set_dt_source_plus[N_BIG*i    +m] & p_active_functions[m]) != 0) {flag=1; break;}
      if(flag)
      {
        source_set_dt |= (1 << i);
      }
    }

    flag=0;
    for(int m=0; m<N_BIG; m++) if(current_settings_prt.ranguvannja_set_dt_source_minus[N_BIG*i    +m] !=0) {flag=1; break;}
    if (flag)
    {
      //Випадок, якщо функції зранжовані на джерело інверсних функцій
      flag=0;
      for(int m=0; m<N_BIG; m++) if( ( current_settings_prt.ranguvannja_set_dt_source_minus[N_BIG*i    +m] & ((unsigned int)(~p_active_functions[m])) ) != 0 ) {flag=1; break;}
      if(flag)
      {
        source_set_dt |= (1<< i);
      }
    }

    flag=0;
    for(int m=0; m<N_BIG; m++) if(current_settings_prt.ranguvannja_reset_dt_source_plus[N_BIG*i    +m] !=0) {flag=1; break;}
    if (flag)
    {
      //Випадок, якщо функції зранжовані на джерело прямих функцій
      flag=0;
      for(int m=0; m<N_BIG; m++) if(( current_settings_prt.ranguvannja_reset_dt_source_plus[N_BIG*i    +m] & p_active_functions[m]) != 0) {flag=1; break;}
      if(flag)
      {
        source_reset_dt |= (1 << i);
      }
    }

    flag=0;
    for(int m=0; m<N_BIG; m++) if(current_settings_prt.ranguvannja_reset_dt_source_minus[N_BIG*i    +m] !=0) {flag=1; break;}
    if (flag)
    {
      //Випадок, якщо функції зранжовані на джерело інверсних функцій
      flag=0;
      for(int m=0; m<N_BIG; m++) if( ( current_settings_prt.ranguvannja_reset_dt_source_minus[N_BIG*i    +m] & ((unsigned int)(~p_active_functions[m])) ) != 0 ) {flag=1; break;}
      if(flag)
      {
        source_reset_dt |= (1<< i);
      }
    }

    //Запускаємо у роботу лоргічну схему роботи опреділюваного триґера (встановлення має пріоритет)
    if ((source_set_dt   & (1 << i)) != 0) state_defined_triggers |= (1 << i);
    if ((source_reset_dt & (1 << i)) != 0) state_defined_triggers &= (unsigned int)(~(1 << i));
  }

  //Установлюємо, або скидаємо ОТ у масиві функцій, які зараз будуть активовуватися
  /*
  Цей цикл і попередній не об'єднаі в один, а навпаки розєднані, бо у першому ми використовуємо
  масив p_active_functions у якому ще не встановлені нові значення виходыв ОТ-ів, тому що інші ОТ-и
  можуть бути джерелом встановлення/скидання, але джерелом встановлення/скидання може буте попереднє значення ОТ, а не те,
  що зараз встановлюється. А оскілдьки у ми встановлюємо значення у масиві
  p_active_functions, які набувають зараз тільки ваги, то щоб не вийшло об'єднання попереднього значення
  і теперішнього то цикли роз'єднані (цикл аналізу джерел і логіки з циклом встановлення/скидання)
  */
  for (unsigned int i = 0; i < NUMBER_DEFINED_TRIGGERS; i++)
  {
    //Установлюємо, або скидаємо ОТ
    unsigned int index_dt =  RNG_BIG_DT1_OUT + 3*i;
      
    if ((state_defined_triggers & (1 << i)) != 0 ) _SET_BIT(p_active_functions, index_dt);
    else _CLEAR_BIT(p_active_functions, index_dt);
  }
}
/*****************************************************/

/*****************************************************/
//Опрацювання визначуваних "І"
/*****************************************************/
inline void d_and_handler(unsigned int *p_active_functions)
{
  unsigned int state_defined_and = 0;

  //Визначаємо стан всіх визначуваних "І" (не виставляючи поки що їх у робочому масиві)
  for (unsigned int i = 0; i < NUMBER_DEFINED_AND/*current_settings_prt.number_defined_and*/; i++)
  {
    int flag=1;
    for(int m=0; m<N_BIG; m++) if((current_settings_prt.ranguvannja_d_and[N_BIG*i + m] & p_active_functions[m]) != current_settings_prt.ranguvannja_d_and[N_BIG*i + m]) {flag=0; break;}
    if (flag)
    {
      state_defined_and |= (1 << i);
    }
  }

  //Установлюємо, або скидаємо визначувані "І" у масиві функцій, які зараз будуть активовуватися
  /*
  Цей цикл і попередній не об'єднаі в один, а навпаки розєднані, бо у першому ми використовуємо
  масив p_active_functions у якому ще не встановлені нові значення виходів В-"І", тому що інші В-"І"
  можуть бути джерелом , але джерелом може буте попереднє значення В-"І", а не те,
  що зараз встановлюється. А оскілдьки ми встановлюємо значення у масиві
  p_active_functions, які набувають зараз тільки ваги, то щоб не вийшло об'єднання попереднього значення
  і теперішнього то цикли роз'єднані (цикл аналізу джерел і логіки з циклом встановлення/скидання)
  */
  for (size_t i = 0; i < NUMBER_DEFINED_AND; ++i)
  {
    //Установлюємо, або скидаємо В-"І"
    unsigned int const index_d_and = RNG_BIG_D_AND1 + i;
      
    if ((state_defined_and & (1 << i)) != 0 ) _SET_BIT(p_active_functions, index_d_and);
    else _CLEAR_BIT(p_active_functions, index_d_and);
  }
}
/*****************************************************/

/*****************************************************/
//Опрацювання визначуваних "АБО"
/*****************************************************/
inline void d_or_handler(unsigned int *p_active_functions)
{
  unsigned int state_defined_or = 0;

  //Визначаємо стан всіх визначуваних "АБО" (не виставляючи поки що їх у робочому масиві)
  for (size_t i = 0; i < NUMBER_DEFINED_OR/*current_settings_prt.number_defined_or*/; ++i)
  {
    int flag=0;
    for(int m=0; m<N_BIG; m++) if((current_settings_prt.ranguvannja_d_or[N_BIG*i + m] & p_active_functions[m]) != 0) {flag=1; break;}
    if (flag)
    {
      state_defined_or |= (1 << i);
    }
  }

  //Установлюємо, або скидаємо визначувані "АБО" у масиві функцій, які зараз будуть активовуватися
  /*
  Цей цикл і попередній не об'єднаі в один, а навпаки розєднані, бо у першому ми використовуємо
  масив p_active_functions у якому ще не встановлені нові значення виходів В-"АБО", тому що інші В-"АБО"
  можуть бути джерелом , але джерелом може буте попереднє значення В-"АБО", а не те,
  що зараз встановлюється. А оскілдьки ми встановлюємо значення у масиві
  p_active_functions, які набувають зараз тільки ваги, то щоб не вийшло об'єднання попереднього значення
  і теперішнього то цикли роз'єднані (цикл аналізу джерел і логіки з циклом встановлення/скидання)
  */
  for (size_t i = 0; i < NUMBER_DEFINED_OR; ++i)
  {
    //Установлюємо, або скидаємо В-"АБО"
    unsigned int const index_d_or = RNG_BIG_D_OR1 + i;
      
    if ((state_defined_or & (1 << i)) != 0 ) _SET_BIT(p_active_functions, index_d_or);
    else _CLEAR_BIT(p_active_functions, index_d_or);
  }
}
/*****************************************************/

/*****************************************************/
//Опрацювання визначуваних "Викл.АБО"
/*****************************************************/
inline void d_xor_handler(unsigned int *p_active_functions)
{
  unsigned int state_defined_xor = 0;

  //Визначаємо стан всіх визначуваних "Викл.АБО" (не виставляючи поки що їх у робочому масиві)
  for (size_t i = 0; i < NUMBER_DEFINED_XOR/*current_settings_prt.number_defined_xor*/; ++i)
  {
    unsigned int temp_array[N_BIG];
    for(int m=0; m<N_BIG; m++) temp_array[m] = current_settings_prt.ranguvannja_d_xor[N_BIG*i + m] & p_active_functions[m];
    
    int flag=0;
    for(int m=0; m<N_BIG; m++) if(temp_array[m] != 0) {flag=1; break;}
    if (flag)
    {
      unsigned int signals = 0;
      for (size_t j = 0; j < N_BIG; ++j)
      {
        if (temp_array[j] == 0) continue; 
        else
        {
          for (size_t k = 0; k < 32; ++k)
          {
            if ((temp_array[j] & (1 << k)) != 0) 
            {
              signals++;
              if (signals > 1) break;
            }
          }
          if (signals > 1) break;
        }
      }
      if (signals == 1) state_defined_xor |= (1 << i);
    }
  }

  //Установлюємо, або скидаємо визначувані "Викл.АБО" у масиві функцій, які зараз будуть активовуватися
  /*
  Цей цикл і попередній не об'єднаі в один, а навпаки розєднані, бо у першому ми використовуємо
  масив p_active_functions у якому ще не встановлені нові значення виходів В-"Викл.АБО", тому що інші В-"Викл.АБО"
  можуть бути джерелом , але джерелом може буте попереднє значення В-"Викл.АБО", а не те,
  що зараз встановлюється. А оскілдьки ми встановлюємо значення у масиві
  p_active_functions, які набувають зараз тільки ваги, то щоб не вийшло об'єднання попереднього значення
  і теперішнього то цикли роз'єднані (цикл аналізу джерел і логіки з циклом встановлення/скидання)
  */
  for (size_t i = 0; i < NUMBER_DEFINED_XOR; ++i)
  {
    //Установлюємо, або скидаємо В-"Викл.АБО"
    unsigned int const index_d_xor = RNG_BIG_D_XOR1 + i;
      
    if ((state_defined_xor & (1 << i)) != 0 ) _SET_BIT(p_active_functions, index_d_xor);
    else _CLEAR_BIT(p_active_functions, index_d_xor);
  }
}
/*****************************************************/

/*****************************************************/
//Опрацювання визначуваних "НЕ"
/*****************************************************/
inline void d_not_handler(unsigned int *p_active_functions)
{
  unsigned int state_defined_not = 0;

  //Визначаємо стан всіх визначуваних "НЕ" (не виставляючи поки що їх у робочому масиві)
  for (size_t i = 0; i < NUMBER_DEFINED_NOT/*current_settings_prt.number_defined_not*/; ++i)
  {
    int flag=1;
    for(int m=0; m<N_BIG; m++) if((current_settings_prt.ranguvannja_d_not[N_BIG*i + m] & p_active_functions[m]) != 0) {flag=0; break;}
    if (flag)
    {
      state_defined_not |= (1 << i);
    }
  }

  //Установлюємо, або скидаємо визначувані "НЕ" у масиві функцій, які зараз будуть активовуватися
  /*
  Цей цикл і попередній не об'єднаі в один, а навпаки розєднані, бо у першому ми використовуємо
  масив p_active_functions у якому ще не встановлені нові значення виходів В-"НЕ", тому що інші В-"НЕ"
  можуть бути джерелом , але джерелом може буте попереднє значення В-"НЕ", а не те,
  що зараз встановлюється. А оскілдьки ми встановлюємо значення у масиві
  p_active_functions, які набувають зараз тільки ваги, то щоб не вийшло об'єднання попереднього значення
  і теперішнього то цикли роз'єднані (цикл аналізу джерел і логіки з циклом встановлення/скидання)
  */
  for (size_t i = 0; i < NUMBER_DEFINED_NOT; ++i)
  {
    //Установлюємо, або скидаємо В-"НЕ"
    unsigned int const index_d_not = RNG_BIG_D_NOT1 + i;
      
    if ((state_defined_not & (1 << i)) != 0 ) _SET_BIT(p_active_functions, index_d_not);
    else _CLEAR_BIT(p_active_functions, index_d_not);
  }
}
/*****************************************************/

/*****************************************************/
//Опрацювання Передавальних функцій
/*****************************************************/
//#pragma optimize=none
inline void tf_handler(unsigned int *p_previous_active_functions, unsigned int *p_active_functions, unsigned int *p_active_inputs_grupa_ustavok)
{
  for (size_t i = 0; i < NUMBER_TRANSFER_FUNCTIONS; i++)
  {
    uint32_t value = current_settings_prt.ranguvannja_tf[i];
    uint32_t value_input = value & 0xffff;
    if (value_input > 0)
    {
      value_input--;
      if (value_input < TOTAL_SIGNAL_FOR_RNG_BIG)
      {
        if (_CHECK_SET_BIT(p_previous_active_functions, value_input) != 0)
        {
          uint32_t value_output = (value >> 16) & 0xffff;
          if (value_output > 0)
          {
            value_output--;
            if (value_output < TOTAL_SIGNAL_FOR_RANG_SMALL_A01)
            {
							uint32_t const small_big_rang_tmp = small_big_rang[value_output];
							if (
									(small_big_rang_tmp >= RNG_BIG_1_GRUPA_USTAVOK) &&
									(small_big_rang_tmp < (RNG_BIG_1_GRUPA_USTAVOK + NUMBER_GROUP_USTAVOK))
								 )
							{
					      *p_active_inputs_grupa_ustavok |= 1u << (small_big_rang_tmp - RNG_BIG_1_GRUPA_USTAVOK);
							}
							else
							{
              	_SET_BIT(p_active_functions, small_big_rang_tmp);
							}
            }
            else
            {
              //Відбулася невизначена помилка, тому треба піти на перезавантаження
              total_error_sw_fixed();
            }
          }
        }
      }
      else
      {
        //Відбулася невизначена помилка, тому треба піти на перезавантаження
        total_error_sw_fixed();
      }
    }
  }
}
/*****************************************************/

/*****************************************************/
//Вираховування часової витримки  для залежної МТЗ2 (універсальна формула)
/*
-------------------------------------------------
Т(c) = K*Tу/( ((I/Iу)^alpha) - 1 )
-------------------------------------------------
*/
/*****************************************************/
//#pragma optimize=none
inline int timeout_dependent_general(const unsigned int i, const uint32_t Iust, const int32_t time_out, const int32_t max_time_out, const int32_t type_mtz)
{
  int timeout_result = 0;
  
  if (
      (type_mtz >= TYPE_MTZ_DEPENDENT_A) &&
      (type_mtz <= TYPE_MTZ_DEPENDENT_RTV_I)
     )   
  {
    if (i > Iust)
    {
      register float timeout = (((float)time_out)/1000.0f);
      register float timeout_dependent = 0;
      
      if (
          (type_mtz >= TYPE_MTZ_DEPENDENT_A) &&
          (type_mtz <= TYPE_MTZ_DEPENDENT_C)
         )   
      {
        register float K = 0.0f;
        register float alpha = 0.0f;

        switch (type_mtz)
        {
        case TYPE_MTZ_DEPENDENT_A:
          {
            K = 0.14f;
            alpha = 0.02f;
            break;
          }
        case TYPE_MTZ_DEPENDENT_B:
          {
            K = 13.5f;
            alpha = 1.0f;
            break;
          }
        case TYPE_MTZ_DEPENDENT_C:
          {
            K = 80.0f;
            alpha = 2.0f;
            break;
          }
        default:
          {
            //Теоретично цього ніколи не мало б бути
            total_error_sw_fixed();
          }
        }
    
        register float I_div_Iusy = ((float)i)/((float)Iust);
        register float rising_to_power = powf(I_div_Iusy, alpha);
        if (
            (isnan(rising_to_power) != 0) || 
            (isinf(rising_to_power) != 0) ||
            (rising_to_power <= 1)
          )
        {
          //Теоретично цього ніколи не мало б бути
          total_error_sw_fixed();
        }
  
        timeout_dependent = K*timeout/(rising_to_power - 1);
      }
      else if (
               (type_mtz >= TYPE_MTZ_DEPENDENT_RT_80) &&
               (type_mtz <= TYPE_MTZ_DEPENDENT_RTV_I)
              )   
      {
        register float I_div_Iusy = ((float)i)/((float)Iust);
        I_div_Iusy = I_div_Iusy - 1.0f;

        register float K = 0.0f;
        register float alpha = 0.0f;

        switch (type_mtz)
        {
        case TYPE_MTZ_DEPENDENT_RT_80:
          {
            K = 20.0f;
            alpha = 1.8f;
          
            I_div_Iusy /= 6.0f;
            break;
          }
        case TYPE_MTZ_DEPENDENT_RTV_I:
          {
            K = 30.0f;
            alpha = 3.0f;
            break;
          } 
        default:
          {
            //Теоретично цього ніколи не мало б бути
            total_error_sw_fixed();
          }
        }
      
        register float rising_to_power = powf(I_div_Iusy, alpha);
        if (
            (isnan(rising_to_power) != 0) || 
            (isinf(rising_to_power) != 0) ||
            (rising_to_power <= 0)
           )
        {
          //Теоретично цього ніколи не мало б бути
          total_error_sw_fixed();
        }
      
        timeout_dependent = 1.0f/(K*rising_to_power)+ timeout;
      }

      int timeout_dependent_int = (int)timeout_dependent;
      if (timeout_dependent_int > (max_time_out/1000)) timeout_dependent = (max_time_out/1000);
      else if (timeout_dependent_int < 0) timeout_dependent = 0;
    
      timeout_result = (int)(timeout_dependent*1000.0f);
    }
    else timeout_result = max_time_out;
  }
  
  return timeout_result;
}
/*****************************************************/

/*****************************************************/
// ЗДЗ
/*****************************************************/
inline void zdz_handler(unsigned int *p_active_functions, unsigned int number_group_stp)
{
  
  uint32_t control_zdz_tmp = current_settings_prt.control_zdz;

#if (                                   \
       (MODYFIKACIA_VERSII_PZ == 0) ||  \
       (MODYFIKACIA_VERSII_PZ == 3) ||  \
       (MODYFIKACIA_VERSII_PZ == 4) ||  \
       (MODYFIKACIA_VERSII_PZ == 6) ||  \
       (MODYFIKACIA_VERSII_PZ == 10)||  \
       (MODYFIKACIA_VERSII_PZ == 13)||  \
       (MODYFIKACIA_VERSII_PZ == 14)    \
      )   

  static uint32_t test;
  static uint32_t swiched_on_OVD;
  static uint32_t new_OVD;

  uint32_t swiched_on_OVD_tmp = (control_zdz_tmp & ((1 << CTR_ZDZ_OVD1_STATE_BIT) | (1 << CTR_ZDZ_OVD2_STATE_BIT) | (1 << CTR_ZDZ_OVD3_STATE_BIT))) >> CTR_ZDZ_OVD1_STATE_BIT;

  new_OVD |= (swiched_on_OVD ^ swiched_on_OVD_tmp) & swiched_on_OVD_tmp;
  swiched_on_OVD = swiched_on_OVD_tmp;

  /***
  Перевірка, чи не вимкнутий зараз є канал по якому не проходи тест ОВД
  ***/
  {
    uint32_t temp_value = zdz_ovd_diagnostyka & (uint32_t)(~swiched_on_OVD);
    if (temp_value)
    {
      if (temp_value & (1 << 0))
      {
        zdz_ovd_diagnostyka &= (uint32_t)(~(1 << 0));
      
        _SET_BIT(clear_diagnostyka, TEST_OVD1);
      }
    
      if (temp_value & (1 << 1))
      {
        zdz_ovd_diagnostyka &= (uint32_t)(~(1 << 1));
      
        _SET_BIT(clear_diagnostyka, TEST_OVD2);
      }

      if (temp_value & (1 << 2))
      {
        zdz_ovd_diagnostyka &= (uint32_t)(~(1 << 2));
      
        _SET_BIT(clear_diagnostyka, TEST_OVD3);
      }
    }
  }
  /***/
   
  //Знімаємо стан з оптоприймача
  uint32_t light = (_DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD26_DD29) >> 12) & 0x7;

  /***
  Код програми, який відповідає за діагностику оптичної системи
  ***/
  if (test != 0)
  {
    //Стан діагностики
    zdz_ovd_diagnostyka = (light ^ test) & test;
    
    if (zdz_ovd_diagnostyka & (1 << 0)) _SET_BIT(set_diagnostyka, TEST_OVD1);
    else _SET_BIT(clear_diagnostyka, TEST_OVD1);
      
    if (zdz_ovd_diagnostyka & (1 << 1)) _SET_BIT(set_diagnostyka, TEST_OVD2);
    else _SET_BIT(clear_diagnostyka, TEST_OVD2);
      
    if (zdz_ovd_diagnostyka & (1 << 2)) _SET_BIT(set_diagnostyka, TEST_OVD3);
    else _SET_BIT(clear_diagnostyka, TEST_OVD3);
      
    //Так, як світло випромінювали ми своїм випромінювачем, то для логіки ми  його не приймаємо
    light &= (uint32_t)(~test);
    
    //Скидаємо тест
    test = 0;
  }
  
  //Відлік часу між послідовними запусками тестів ОВД
  delta_time_test += DELTA_TIME_FOR_TIMERS;
  
  //Фіксація початку нового тесту всіх ОВД
  if (
      (light == 0)
      &&  
      (
       (new_OVD) ||
       ( delta_time_test >= PERIOD_ZDZ_TEST)
      )   
     )   
  {
    new_OVD = 0; /*скидаємо фіксацію введення в роботу нового каналу*/
    delta_time_test = 0;
    
    //Починаємо тест
    test = swiched_on_OVD & 0x7;
  }

  if (test != 0) _DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD28_DD30) = (1 << 8) | ((test & 0xf) << 12);
  else _DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD28_DD30) = (((current_settings_prt.zdz_ovd_porig + 1) & 0xf) << 8);
  /***/

#endif  

  uint32_t logic_zdz_0 = 0;

  logic_zdz_0 |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_PUSK_ZDZ_VID_DV) != 0) << 0; //Пуск ЗДЗ от ДВ

  logic_zdz_0 |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_BLOCK_ZDZ) == 0) << 1; //Блок. ЗДЗ
  
  _AND2(control_zdz_tmp, CTR_ZDZ_STATE_BIT, logic_zdz_0, 1, logic_zdz_0, 2);
  _AND2(logic_zdz_0, 2, logic_zdz_0, 0, logic_zdz_0, 3);
  //"Св.ЗДЗ від ДВ"
  if (_GET_STATE(logic_zdz_0, 3))
    _SET_BIT(p_active_functions, RNG_BIG_LIGHT_ZDZ_FROM_DV);
  else
    _CLEAR_BIT(p_active_functions, RNG_BIG_LIGHT_ZDZ_FROM_DV);

#if (                                   \
       (MODYFIKACIA_VERSII_PZ == 0) ||  \
       (MODYFIKACIA_VERSII_PZ == 3) ||  \
       (MODYFIKACIA_VERSII_PZ == 4) ||  \
       (MODYFIKACIA_VERSII_PZ == 6) ||  \
       (MODYFIKACIA_VERSII_PZ == 10)||  \
       (MODYFIKACIA_VERSII_PZ == 13)||  \
       (MODYFIKACIA_VERSII_PZ == 14)    \
      ) 

  uint32_t zdz_ovd_diagnostyka_inv = (uint32_t)(~zdz_ovd_diagnostyka);
  _AND4(logic_zdz_0, 2, light, 0, zdz_ovd_diagnostyka_inv, 0, control_zdz_tmp, CTR_ZDZ_OVD1_STATE_BIT, logic_zdz_0, 4);
  //"Св.ЗДЗ від ОВД1"
  if (_GET_STATE(logic_zdz_0, 4))
    _SET_BIT(p_active_functions, RNG_BIG_LIGHT_ZDZ_FROM_OVD1);
  else
    _CLEAR_BIT(p_active_functions, RNG_BIG_LIGHT_ZDZ_FROM_OVD1);

  _AND4(logic_zdz_0, 2, light, 1, zdz_ovd_diagnostyka_inv, 1, control_zdz_tmp, CTR_ZDZ_OVD2_STATE_BIT, logic_zdz_0, 5);
  //"Св.ЗДЗ від ОВД2"
  if (_GET_STATE(logic_zdz_0, 5))
    _SET_BIT(p_active_functions, RNG_BIG_LIGHT_ZDZ_FROM_OVD2);
  else
    _CLEAR_BIT(p_active_functions, RNG_BIG_LIGHT_ZDZ_FROM_OVD2);

  _AND4(logic_zdz_0, 2, light, 2, zdz_ovd_diagnostyka_inv, 2, control_zdz_tmp, CTR_ZDZ_OVD3_STATE_BIT, logic_zdz_0, 6);
  //"Св.ЗДЗ від ОВД3"
  if (_GET_STATE(logic_zdz_0, 6))
    _SET_BIT(p_active_functions, RNG_BIG_LIGHT_ZDZ_FROM_OVD3);
  else
    _CLEAR_BIT(p_active_functions, RNG_BIG_LIGHT_ZDZ_FROM_OVD3);

  _OR4(logic_zdz_0, 3, logic_zdz_0, 4, logic_zdz_0, 5, logic_zdz_0, 6, logic_zdz_0, 7);
#else
  if (_GET_STATE(logic_zdz_0, 3)) _SET_STATE(logic_zdz_0, 7);
#endif
  
  uint32_t logic_zdz_rez = 0;
  if (current_settings_prt.ctrl_zdz_type == ZDZ_CTRL_NONE)
  {
    logic_zdz_rez |= _GET_STATE(logic_zdz_0, 7) << 0;
  }
  else if (current_settings_prt.ctrl_zdz_type < _ZDZ_CTRL_NUMBER)
  {
    if (
        (current_settings_prt.ctrl_zdz_type == ZDZ_CTRL_I) ||
        (current_settings_prt.ctrl_zdz_type == ZDZ_CTRL_I_OR_U) ||
        (current_settings_prt.ctrl_zdz_type == ZDZ_CTRL_I_AND_U)
       )   
    {
      if(
         (_GET_STATE(control_zdz_tmp, (CTR_ZDZ_STARTED_FROM_MTZ1_BIT - (_CTR_ZDZ_PART_III - _CTR_ZDZ_PART_II))))
         &&
         (
          (_CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_MCZO1        ) != 0) ||//!(_CHECK_SET_BIT(p_active_functions, RANG_PO_MTZ1) != 0) ||
          (_CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_MCZON1_VPERED) != 0) ||//!(_CHECK_SET_BIT(p_active_functions, RANG_PO_MTZN1_VPERED) != 0) ||
          (_CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_MCZON1_NAZAD ) != 0) ||//!(_CHECK_SET_BIT(p_active_functions, RANG_PO_MTZN1_NAZAD) != 0) ||
          (_CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_MCZOPN1      ) != 0)   //!(_CHECK_SET_BIT(p_active_functions, RANG_PO_MTZPN1) != 0)
         ) 
        )   
      {
        _SET_STATE(logic_zdz_0, 8);
      }

      if(
         (_GET_STATE(control_zdz_tmp, (CTR_ZDZ_STARTED_FROM_MTZ2_BIT - (_CTR_ZDZ_PART_III - _CTR_ZDZ_PART_II))))
         &&
         (
          (_CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_MCZO2        ) != 0) ||//!(_CHECK_SET_BIT(p_active_functions, RANG_PO_MTZ2) != 0) ||
          (_CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_MCZON2_VPERED) != 0) ||//!(_CHECK_SET_BIT(p_active_functions, RANG_PO_MTZN2_VPERED) != 0) ||
          (_CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_MCZON2_NAZAD ) != 0) ||//!(_CHECK_SET_BIT(p_active_functions, RANG_PO_MTZN2_NAZAD) != 0) ||
          (_CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_MCZOPN2      ) != 0)    //!(_CHECK_SET_BIT(p_active_functions, RANG_PO_MTZPN2) != 0)
         ) 
        )   
      {
        _SET_STATE(logic_zdz_0, 9);
      }

      if(
         (_GET_STATE(control_zdz_tmp, (CTR_ZDZ_STARTED_FROM_MTZ3_BIT - (_CTR_ZDZ_PART_III - _CTR_ZDZ_PART_II))))
         &&
         (
          (_CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_MCZO3        ) != 0) ||//!(_CHECK_SET_BIT(p_active_functions, RANG_PO_MTZ3) != 0) ||
          (_CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_MCZON3_VPERED) != 0) ||//!(_CHECK_SET_BIT(p_active_functions, RANG_PO_MTZN3_VPERED) != 0) ||
          (_CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_MCZON3_NAZAD ) != 0) ||//!(_CHECK_SET_BIT(p_active_functions, RANG_PO_MTZN3_NAZAD) != 0) ||
          (_CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_MCZOPN3      ) != 0)   //!(_CHECK_SET_BIT(p_active_functions, RANG_PO_MTZPN3) != 0)
         ) 
        )   
      {
        _SET_STATE(logic_zdz_0, 10);
      }

      if(
         (_GET_STATE(control_zdz_tmp, (CTR_ZDZ_STARTED_FROM_MTZ4_BIT - (_CTR_ZDZ_PART_III - _CTR_ZDZ_PART_II))))
         &&
         (
          (_CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_MCZO4           ) != 0) ||//!(_CHECK_SET_BIT(p_active_functions, RANG_PO_MTZ4) != 0) ||
          (_CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_MCZON4_VPERED   ) != 0) ||//!(_CHECK_SET_BIT(p_active_functions, RANG_PO_MTZN4_VPERED) != 0) ||
          (_CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_MCZON4_NAZAD    ) != 0) ||//!(_CHECK_SET_BIT(p_active_functions, RANG_PO_MTZN4_NAZAD) != 0) ||
          (_CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_MCZOPN4         ) != 0)   //!(_CHECK_SET_BIT(p_active_functions, RANG_PO_MTZPN4) != 0)
         ) 
        )   
      {
        _SET_STATE(logic_zdz_0, 11);
      }
      
      _OR4(logic_zdz_0, 8, logic_zdz_0, 9, logic_zdz_0, 10, logic_zdz_0, 11, logic_zdz_0, 12);
    }

    if (
        (current_settings_prt.ctrl_zdz_type == ZDZ_CTRL_U) ||
        (current_settings_prt.ctrl_zdz_type == ZDZ_CTRL_I_OR_U) ||
        (current_settings_prt.ctrl_zdz_type == ZDZ_CTRL_I_AND_U)
       )   
    {
      if(
         (_GET_STATE(control_zdz_tmp, (CTR_ZDZ_STARTED_FROM_UMIN1_BIT - (_CTR_ZDZ_PART_III - _CTR_ZDZ_PART_II)))) &&
         //!(_CHECK_SET_BIT(p_active_functions, RANG_PO_UMIN1) != 0)
         (_CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_UMIN1) != 0)
        )   
      {
        _SET_STATE(logic_zdz_0, 13);
      }
      
      if(
         (_GET_STATE(control_zdz_tmp, (CTR_ZDZ_STARTED_FROM_UMIN2_BIT - (_CTR_ZDZ_PART_III - _CTR_ZDZ_PART_II)))) &&
         //!(_CHECK_SET_BIT(p_active_functions, RANG_PO_UMIN2) != 0)
         (_CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_UMIN2) != 0)
        )   
      {
        _SET_STATE(logic_zdz_0, 14);
      }
      
      _OR2(logic_zdz_0, 13, logic_zdz_0, 14, logic_zdz_0, 15);
    }

    if (current_settings_prt.ctrl_zdz_type == ZDZ_CTRL_I)
    {
      _AND2(logic_zdz_0, 7, logic_zdz_0, 12, logic_zdz_rez, 0);
    }
    else if (current_settings_prt.ctrl_zdz_type == ZDZ_CTRL_U)
    {
      _AND2(logic_zdz_0, 7, logic_zdz_0, 15, logic_zdz_rez, 0);
    }
    else
    {
      if (current_settings_prt.ctrl_zdz_type == ZDZ_CTRL_I_OR_U)
      {
        _OR2(logic_zdz_0, 12, logic_zdz_0, 15, logic_zdz_0, 16);
      }
      else if (current_settings_prt.ctrl_zdz_type == ZDZ_CTRL_I_AND_U)
      {
        _AND2(logic_zdz_0, 12, logic_zdz_0, 15, logic_zdz_0, 16);
      }
      else
      {
        //Якщо сюди дійшла програма, значить відбулася недопустива помилка, тому треба зациклити програму, щоб вона пішла на перезагрузку
        total_error_sw_fixed();
      }

      _AND2(logic_zdz_0, 7, logic_zdz_0, 16, logic_zdz_rez, 0);
    }
  }
  else
  {
    //Якщо сюди дійшла програма, значить відбулася недопустива помилка, тому треба зациклити програму, щоб вона пішла на перезагрузку
    total_error_sw_fixed();
  }
  
  //"ПО ЗДЗ"
  if (_GET_STATE(logic_zdz_rez, 0))
    _SET_BIT(p_active_functions,RNG_BIG_PO_ZDZ);//_SET_BIT(p_active_functions, RANG_PO_ZDZ);
  else
    _CLEAR_BIT(p_active_functions,RNG_BIG_PO_ZDZ); //_CLEAR_BIT(p_active_functions, RANG_PO_ZDZ);
  
  _TIMER_T_0(INDEX_TIMER_ZDZ, current_settings_prt.timeout_zdz[number_group_stp], logic_zdz_rez, 0, logic_zdz_rez, 1);
  //"ЗДЗ"
  if (_GET_STATE(logic_zdz_rez, 1))
    _SET_BIT(p_active_functions,RNG_BIG_ZDZ); //_SET_BIT(p_active_functions, RANG_ZDZ);
  else
    _CLEAR_BIT(p_active_functions,RNG_BIG_ZDZ);//_CLEAR_BIT(p_active_functions, RANG_ZDZ);
}
/*****************************************************/

/*****************************************************/
// ЗНМИН1
/*****************************************************/
void umin1_handler(unsigned int *p_active_functions, unsigned int number_group_stp)
{
  _Bool previous_state_po_umin1 = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_UMIN1) > 0;
  _Bool previous_state_po_ublk_umin1 = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_UBLK_UMIN1) > 0;
  _Bool previous_state_po_iblk_umin1 = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_IBLK_UMIN1) > 0;
  
  unsigned int setpoint1 = previous_state_po_umin1 ?
          current_settings_prt.setpoint_Umin1[number_group_stp] * U_DOWN / 100 :
          current_settings_prt.setpoint_Umin1[number_group_stp];
  
  _Bool Umn_is_smaller_than_Umin1 = measurement[IM_Umn] <= setpoint1;
  
  unsigned int setpoint2 = previous_state_po_ublk_umin1 ?
          KOEF_MIN_UMIN * U_DOWN_1 / 100 : KOEF_MIN_UMIN;
          
  _Bool Umn_or_Ubp_is_smaller_than_250mV = (measurement[IM_Umn] <= setpoint2) ;
  
  unsigned int setpoint3 = previous_state_po_iblk_umin1 ?
          current_settings_prt.setpoint_Umin1_Iblk[number_group_stp] * KOEF_POVERNENNJA_GENERAL_DOWN / 100 :
          current_settings_prt.setpoint_Umin1_Iblk[number_group_stp];
  
  _Bool Imn_and_Ibp_is_smaller_than_Iust = (measurement[IM_Imn] <= setpoint3); 
  //М
  unsigned int tmp_value = ((current_settings_prt.control_transformator & MASKA_FOR_BIT(INDEX_ML_CTR_TRANSFORMATOR_PHASE_LINE)) == 0) << 0;
//  tmp_value |= ((current_settings_prt.control_Umin & CTR_EXTRA_SETTINGS_1_CTRL_PHASE_LINE) != 0)                                 << 1;
//  _INVERTOR(tmp_value, 1, tmp_value, 1);
  tmp_value |= ((current_settings_prt.control_Umin & CTR_UMIN1) != 0)                     << 2;
//@?  tmp_value |= ((current_settings_prt.control_Umin & CTR_PO_UMIN1_OR_AND) != 0)           << 3;
  tmp_value |= ((current_settings_prt.control_Umin & CTR_UMIN1_UBLK) != 0)                << 4;
  tmp_value |= ((current_settings_prt.control_Umin & CTR_UMIN1_IBLK) != 0)                << 5;
  
  //ДВ
  tmp_value |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_BLOCK_UMIN1) != 0)             << 6;
  _INVERTOR(tmp_value, 6, tmp_value, 6);
  tmp_value |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_START_UMIN1) != 0)             << 7;
  
//  _AND2(tmp_value, 0, tmp_value, 1, tmp_value, 8);
  
  tmp_value |= (_GET_STATE(Umn_is_smaller_than_Umin1, 0))<<9;
 //ПО Uблк. Umin1
    if (Umn_or_Ubp_is_smaller_than_250mV)
      _SET_BIT(p_active_functions, RNG_BIG_PO_UBLK_UMIN1);
    else
      _CLEAR_BIT(p_active_functions, RNG_BIG_PO_UBLK_UMIN1); 

  //ПО Iблк. Umin1
  if (Imn_and_Ibp_is_smaller_than_Iust)
    _SET_BIT(p_active_functions, RNG_BIG_PO_IBLK_UMIN1);
  else
    _CLEAR_BIT(p_active_functions, RNG_BIG_PO_IBLK_UMIN1);

  _AND2(tmp_value, 5, Imn_and_Ibp_is_smaller_than_Iust, 0, tmp_value, 12);
  _INVERTOR(tmp_value, 5, tmp_value, 5);
  _AND3(Umn_or_Ubp_is_smaller_than_250mV, 0, tmp_value, 4, tmp_value, 5, tmp_value, 13);

  _INVERTOR(tmp_value, 12, tmp_value, 12);
  _INVERTOR(tmp_value, 13, tmp_value, 13);
  _OR2(tmp_value, 7, tmp_value, 9,  tmp_value, 14);
  
  _AND5(tmp_value, 6, tmp_value, 2, tmp_value, 14, tmp_value, 13, tmp_value, 12, tmp_value, 15);
  

  
  //ПО Umin1
  if (_GET_STATE(tmp_value, 15))
    _SET_BIT(p_active_functions, RNG_BIG_PO_UMIN1);
  else
    _CLEAR_BIT(p_active_functions, RNG_BIG_PO_UMIN1);
  
  _TIMER_T_0(INDEX_TIMER_UMIN1, current_settings_prt.timeout_Umin1[number_group_stp], tmp_value, 15, tmp_value, 16);
  
  //Сраб. Umin1
  if (_GET_STATE(tmp_value, 16))
    _SET_BIT(p_active_functions, RNG_BIG_UMIN1);
  else
    _CLEAR_BIT(p_active_functions, RNG_BIG_UMIN1);
}
/*****************************************************/

/*****************************************************/
// ЗНМИН2
/*****************************************************/
void umin2_handler(unsigned int *p_active_functions, unsigned int number_group_stp)
{
  _Bool previous_state_po_umin2 = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_UMIN2) > 0;
  _Bool previous_state_po_ublk_umin2 = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_UBLK_UMIN2) > 0;
  _Bool previous_state_po_iblk_umin2 = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_IBLK_UMIN2) > 0;
  
  unsigned int setpoint1 = previous_state_po_umin2 ?
          current_settings_prt.setpoint_Umin2[number_group_stp] * U_DOWN / 100 :
          current_settings_prt.setpoint_Umin2[number_group_stp];
  
  _Bool Umn_is_smaller_than_Umin2 = measurement[IM_Umn] <= setpoint1;
//  _Bool Ubp_is_smaller_than_Umin2 = measurement[IM_Ubp] <= setpoint1;
  
  unsigned int setpoint2 = previous_state_po_ublk_umin2 ?
          KOEF_MIN_UMIN * U_DOWN_1 / 100 : KOEF_MIN_UMIN;
          
  _Bool Umn_or_Ubp_is_smaller_than_250mV = (measurement[IM_Umn] <= setpoint2);
  
  unsigned int setpoint3 = previous_state_po_iblk_umin2 ?
          current_settings_prt.setpoint_Umin2_Iblk[number_group_stp] * KOEF_POVERNENNJA_GENERAL_DOWN / 100 :
          current_settings_prt.setpoint_Umin2_Iblk[number_group_stp];
  
  _Bool Imn_and_Ibp_is_smaller_than_Iust = (measurement[IM_Imn] <= setpoint3) ;
                                         //&&(measurement[IM_Ibp] <= setpoint3);
  //М
  unsigned int tmp_value = ((current_settings_prt.control_transformator & MASKA_FOR_BIT(INDEX_ML_CTR_TRANSFORMATOR_PHASE_LINE)) == 0) << 0;
//  tmp_value |= ((current_settings_prt.control_Umin & CTR_EXTRA_SETTINGS_1_CTRL_PHASE_LINE) != 0)                                 << 1;
//  _INVERTOR(tmp_value, 1, tmp_value, 1);
  tmp_value |= ((current_settings_prt.control_Umin & CTR_UMIN2) != 0)                   << 2;
//@?  tmp_value |= ((current_settings_prt.control_Umin & CTR_PO_UMIN2_OR_AND) != 0)         << 3;
  tmp_value |= ((current_settings_prt.control_Umin & CTR_UMIN2_UBLK) != 0)              << 4;
  tmp_value |= ((current_settings_prt.control_Umin & CTR_UMIN2_IBLK) != 0)              << 5;
  
  //ДВ
  tmp_value |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_BLOCK_UMIN2) != 0)           << 6;
  _INVERTOR(tmp_value, 6, tmp_value, 6);
  tmp_value |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_START_UMIN2) != 0)           << 7;
  
//  _AND2(tmp_value, 0, tmp_value, 1, tmp_value, 8);
/*  
  if (_GET_STATE(tmp_value, 0))
  {
    //Фазные
    _AND3(Umn_is_smaller_than_Umin2, 0, Ubp_is_smaller_than_Umin2, 0, tmp_value, 3, tmp_value, 9);
    _OR2(Umn_is_smaller_than_Umin2, 0, Ubp_is_smaller_than_Umin2, 0, tmp_value, 10);
    _INVERTOR(tmp_value, 3, tmp_value, 3);
    _AND2(tmp_value, 10, tmp_value, 3, tmp_value, 11);
    _AND2(tmp_value, 5, Imn_and_Ibp_is_smaller_than_Iust, 0, tmp_value, 12);
    _INVERTOR(tmp_value, 5, tmp_value, 5);
    _AND3(Umn_or_Ubp_is_smaller_than_250mV, 0, tmp_value, 4, tmp_value, 5, tmp_value, 13);
    
    //ПО Uблк. Umin2
    if (Umn_or_Ubp_is_smaller_than_250mV)
      _SET_BIT(p_active_functions, RNG_BIG_PO_UBLK_UMIN2);
    else
      _CLEAR_BIT(p_active_functions, RNG_BIG_PO_UBLK_UMIN2);
    
  } 
  else 
  {
    //Линейные
    _AND3(Umn_is_smaller_than_Umin2, 0, Ubp_is_smaller_than_Umin2, 0, tmp_value, 3, tmp_value, 9);
    _OR2(Umn_is_smaller_than_Umin2, 0, Ubp_is_smaller_than_Umin2, 0, tmp_value, 10);
    _INVERTOR(tmp_value, 3, tmp_value, 3);
    _AND2(tmp_value, 10, tmp_value, 3, tmp_value, 11);
    _AND2(tmp_value, 5, Imn_and_Ibp_is_smaller_than_Iust, 0, tmp_value, 12);
    _INVERTOR(tmp_value, 5, tmp_value, 5);
    _AND3(Umn_or_Ubp_is_smaller_than_250mV, 0, tmp_value, 4, tmp_value, 5, tmp_value, 13);
    
    //ПО Uблк. Umin2
    if (Umn_or_Ubp_is_smaller_than_250mV)
      _SET_BIT(p_active_functions, RNG_BIG_PO_UBLK_UMIN2);
    else
      _CLEAR_BIT(p_active_functions, RNG_BIG_PO_UBLK_UMIN2);
  }*/

     tmp_value |= (_GET_STATE(Umn_is_smaller_than_Umin2, 0))<<9;
    //ПО Uблк. Umin2
    if (Umn_or_Ubp_is_smaller_than_250mV)
      _SET_BIT(p_active_functions, RNG_BIG_PO_UBLK_UMIN2);
    else
      _CLEAR_BIT(p_active_functions, RNG_BIG_PO_UBLK_UMIN2);
  
  //ПО Iблк. Umin2
  if (Imn_and_Ibp_is_smaller_than_Iust)
    _SET_BIT(p_active_functions, RNG_BIG_PO_IBLK_UMIN2);
  else
    _CLEAR_BIT(p_active_functions, RNG_BIG_PO_IBLK_UMIN2);

  _AND2(tmp_value, 5, Imn_and_Ibp_is_smaller_than_Iust, 0, tmp_value, 12);
  _INVERTOR(tmp_value, 5, tmp_value, 5);
  _AND3(Umn_or_Ubp_is_smaller_than_250mV, 0, tmp_value, 4, tmp_value, 5, tmp_value, 13);
  


  _INVERTOR(tmp_value, 12, tmp_value, 12);
  _INVERTOR(tmp_value, 13, tmp_value, 13);
  _OR2(tmp_value, 7, tmp_value, 9, tmp_value, 14);
  
  _AND5(tmp_value, 6, tmp_value, 2, tmp_value, 14, tmp_value, 13, tmp_value, 12, tmp_value, 15);

  //ПО Umin2
  if (_GET_STATE(tmp_value, 15))
    _SET_BIT(p_active_functions, RNG_BIG_PO_UMIN2);
  else
    _CLEAR_BIT(p_active_functions, RNG_BIG_PO_UMIN2);
  
  _TIMER_T_0(INDEX_TIMER_UMIN2, current_settings_prt.timeout_Umin2[number_group_stp], tmp_value, 15, tmp_value, 16);
  
  //Сраб. Umin2
  if (_GET_STATE(tmp_value, 16))
    _SET_BIT(p_active_functions, RNG_BIG_UMIN2);
  else
    _CLEAR_BIT(p_active_functions, RNG_BIG_UMIN2);
}
/*****************************************************/

/*****************************************************/
// ДЗ
/*****************************************************/
void dz_handler(unsigned int *p_active_functions, unsigned int number_group_stp)
{
	mf_of_handler(p_active_functions,number_group_stp);
	fault_U_handler(p_active_functions,number_group_stp);
	dz1_handler(p_active_functions,number_group_stp);
	dz2_handler(p_active_functions,number_group_stp);
	dz3_handler(p_active_functions,number_group_stp);
	dz4_handler(p_active_functions,number_group_stp);
}

/*****************************************************/
// ЗНМАКС1
/*****************************************************/
void umax1_handler(unsigned int *p_active_functions, unsigned int number_group_stp)
{
  _Bool previous_state_po_umax1 = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_UMAX1) > 0;
  
  unsigned int setpoint1 = previous_state_po_umax1 ?
          current_settings_prt.setpoint_Umax1[number_group_stp] * current_settings_prt.setpoint_kp_Umax[number_group_stp] / 100 :
          current_settings_prt.setpoint_Umax1[number_group_stp];
  
  _Bool Umn_is_larger_than_Umax1 = measurement[IM_Umn] >= setpoint1;
//  _Bool Ubp_is_larger_than_Umax1 = measurement[IM_Ubp] >= setpoint1;
  
  //М
  unsigned int tmp_value = ((current_settings_prt.control_transformator & MASKA_FOR_BIT(INDEX_ML_CTR_TRANSFORMATOR_PHASE_LINE)) == 0) << 0;
//  tmp_value |= ((current_settings_prt.control_Umax & CTR_EXTRA_SETTINGS_1_CTRL_PHASE_LINE) != 0)                                 << 1;
//  _INVERTOR(tmp_value, 1, tmp_value, 1);
//?  tmp_value |= ((current_settings_prt.control_Umax & CTR_PO_UMAX1_OR_AND) != 0)                             << 2;
  tmp_value |= ((current_settings_prt.control_Umax & CTR_UMAX1) != 0)                                       << 3;
  
  //ДВ
  tmp_value |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_BLOCK_UMAX1) != 0)                               << 4;
  
//  if (_GET_STATE(tmp_value, 0)) {
//    _AND3(Umn_is_larger_than_Umax1, 0, Ubp_is_larger_than_Umax1, 0, tmp_value, 2, tmp_value, 5);
//    _OR2(Umn_is_larger_than_Umax1, 0, Ubp_is_larger_than_Umax1, 0, tmp_value, 6);
//  } else {
//    _AND3(Umn_is_larger_than_Umax1, 0, Ubp_is_larger_than_Umax1, 0, tmp_value, 2, tmp_value, 5);
//    _OR2(Umn_is_larger_than_Umax1, 0, Ubp_is_larger_than_Umax1, 0, tmp_value, 6);
//  }
  
  _INVERTOR(tmp_value, 2, tmp_value, 2);
//  _AND2(tmp_value, 6, tmp_value, 2, tmp_value, 7);
//  _OR2(tmp_value, 5, tmp_value, 7, tmp_value, 8);

   tmp_value |= (_GET_STATE(Umn_is_larger_than_Umax1, 0))<<8;//_AND2(Umn_is_larger_than_Umax1, 0,Umn_is_larger_than_Umax1, 0, tmp_value, 8);
  _INVERTOR(tmp_value, 4, tmp_value, 4);  
  _AND3(tmp_value, 8, tmp_value, 4, tmp_value, 3, tmp_value, 9);
  
  //ПО Umax1
  if (_GET_STATE(tmp_value, 9))
    _SET_BIT(p_active_functions, RNG_BIG_PO_UMAX1);
  else
    _CLEAR_BIT(p_active_functions, RNG_BIG_PO_UMAX1);
  
  _TIMER_T_0(INDEX_TIMER_UMAX1, current_settings_prt.timeout_Umax1[number_group_stp], tmp_value, 9, tmp_value, 10);
  
  //Сраб. Umax1
  if (_GET_STATE(tmp_value, 10))
    _SET_BIT(p_active_functions, RNG_BIG_UMAX1);
  else
    _CLEAR_BIT(p_active_functions, RNG_BIG_UMAX1);
}
/*****************************************************/

/*****************************************************/
// ЗНМАКС2
/*****************************************************/
void umax2_handler(unsigned int *p_active_functions, unsigned int number_group_stp)
{
//  _Bool previous_state_po_umax2 = _CHECK_SET_BIT(p_active_functions, RANG_PO_UMAX2) > 0;
  _Bool previous_state_po_umax2 = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_UMAX2) > 0;
  
  unsigned int setpoint1 = previous_state_po_umax2 ?
          current_settings_prt.setpoint_Umax2[number_group_stp] * current_settings_prt.setpoint_kp_Umax[number_group_stp] / 100 :
          current_settings_prt.setpoint_Umax2[number_group_stp];
  
  _Bool Umn_is_larger_than_Umax2 = measurement[IM_Umn] >= setpoint1;
//  _Bool Ubp_is_larger_than_Umax2 = measurement[IM_Ubp] >= setpoint1;
  
  //М
  unsigned int tmp_value = ((current_settings_prt.control_transformator & MASKA_FOR_BIT(INDEX_ML_CTR_TRANSFORMATOR_PHASE_LINE)) == 0) << 0;
//  tmp_value |= ((current_settings_prt.control_Umax & CTR_EXTRA_SETTINGS_1_CTRL_PHASE_LINE) != 0)                                 << 1;
//  _INVERTOR(tmp_value, 1, tmp_value, 1);
//?  tmp_value |= ((current_settings_prt.control_Umax & CTR_PO_UMAX2_OR_AND) != 0)                               << 2;
  tmp_value |= ((current_settings_prt.control_Umax & CTR_UMAX2) != 0)                                         << 3;
  
  //ДВ
  //tmp_value |= (_CHECK_SET_BIT(p_active_functions, RANG_BLOCK_UMAX2) != 0)                                    << 4;
  tmp_value |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_BLOCK_UMAX2) != 0)                                    << 4;
  
//  if (_GET_STATE(tmp_value, 0)) {
//    _AND3(Umn_is_larger_than_Umax2, 0, Ubp_is_larger_than_Umax2, 0, tmp_value, 2, tmp_value, 5);
//    _OR2(Umn_is_larger_than_Umax2, 0, Ubp_is_larger_than_Umax2, 0, tmp_value, 6);
//  } else {
//    _AND3(Umn_is_larger_than_Umax2, 0, Ubp_is_larger_than_Umax2, 0, tmp_value, 2, tmp_value, 5);
//    _OR2(Umn_is_larger_than_Umax2, 0, Ubp_is_larger_than_Umax2, 0, tmp_value, 6);
//  }
  
  _INVERTOR(tmp_value, 2, tmp_value, 2);
//  _AND2(tmp_value, 6, tmp_value, 2, tmp_value, 7);
//  _OR2(tmp_value, 5, tmp_value, 7, tmp_value, 8);
  tmp_value |= (_GET_STATE(Umn_is_larger_than_Umax2, 0))<<8;//_AND2(Umn_is_larger_than_Umax2, 0,Umn_is_larger_than_Umax2, 0, tmp_value, 8);
  _INVERTOR(tmp_value, 4, tmp_value, 4);
  _AND3(tmp_value, 8, tmp_value, 4, tmp_value, 3, tmp_value, 9);
  
  //ПО Umax1
  if (_GET_STATE(tmp_value, 9))
    _SET_BIT(p_active_functions, RNG_BIG_PO_UMAX2);
  else
    _CLEAR_BIT(p_active_functions, RNG_BIG_PO_UMAX2);
  
  _TIMER_T_0(INDEX_TIMER_UMAX2, current_settings_prt.timeout_Umax2[number_group_stp], tmp_value, 9, tmp_value, 10);
  
  //Сраб. Umax2
  if (_GET_STATE(tmp_value, 10))
    _SET_BIT(p_active_functions, RNG_BIG_UMAX2);
  else
    _CLEAR_BIT(p_active_functions, RNG_BIG_UMAX2);
}
/*****************************************************/

/*****************************************************/
// АЧР ЧАПВ
/*****************************************************/
void achr_chapv_handler(unsigned int *p_active_functions, unsigned int number_group_stp)
{
//RANG_ACHR_CHAPV_VID_DV,
/*
  //пред сост ПО АЧР
  _Bool previous_state_po_f1_achr = _CHECK_SET_BIT(p_active_functions, RANG_PO_ACHR1);
  //пред сост ПО ЧАПВ
  _Bool previous_state_po_f1_chapv = _CHECK_SET_BIT(p_active_functions, RANG_PO_CHAPV1);
 // 
раздвоение
*/
  //пред сост ПО АЧР1
  _Bool previous_state_po_f1_achr1  = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_ACHR1);
  //пред сост ПО ЧАПВ1
  _Bool previous_state_po_f1_chapv1 = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_CHAPV1);
  //пред сост ПО АЧР2
  _Bool previous_state_po_f1_achr2  = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_ACHR2);
  //пред сост ПО ЧАПВ2
  _Bool previous_state_po_f1_chapv2 = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_CHAPV2);
//----------
/*
неизменно
*/

  unsigned int setpoint1 = previous_state_po_achr_chapv_umnf1 ?
          current_settings_prt.setpoint_achr_chapv_uf[number_group_stp] * U_UP / 100 :
          current_settings_prt.setpoint_achr_chapv_uf[number_group_stp];
          
  unsigned int setpoint2 = previous_state_po_achr_chapv_ubpf1 ?
          current_settings_prt.setpoint_achr_chapv_uf[number_group_stp] * U_UP / 100 :
          current_settings_prt.setpoint_achr_chapv_uf[number_group_stp];
  
  //Линейные
//  _Bool Uab_is_larger_than_UF1 = measurement[IM_UAB] >= setpoint1;
//  _Bool Ubc_is_larger_than_UF1 = measurement[IM_UBC] >= setpoint2;
//  _Bool Uca_is_larger_than_UF1 = measurement[IM_UCA] >= setpoint3;
  
  //Фазные
  _Bool Umn_is_larger_than_UF1 = measurement[IM_Umn] >= setpoint1;
  _Bool Ubp_is_larger_than_UF1 = measurement[IM_Ubp] >= setpoint2;
  
//  /*----------------Выбор фазные/линейные-------------------------------------*/
//  _Bool UF1_phase = ((current_settings_prt.control_extra_settings_1 & CTR_EXTRA_SETTINGS_1_CTRL_PHASE_LINE) == 0);
//  /*--------------------------------------------------------------------------*/
  
  _Bool timer1 = 0;
  _Bool UF1_is_larger_than_U_setpoint_F1 = 0;
//  _Bool UF1_is_smaller_than_U_setpoint_F1 = 0;
  //ПО ФАЗНЫЕ-ЛИНЕЙНЫЕ
//  if (UF1_phase)
//  {
    //ПО UAF1
    previous_state_po_achr_chapv_umnf1 = Umn_is_larger_than_UF1;
    //ПО UBF1
    previous_state_po_achr_chapv_ubpf1 = Ubp_is_larger_than_UF1;
    _AND2(Umn_is_larger_than_UF1, 0, Ubp_is_larger_than_UF1, 0, timer1, 0);
//  }
//  else 
//  {
//    //ПО UAF1
//    previous_state_po_achr_chapv_uaf1 = Uab_is_larger_than_UF1;
//    //ПО UBF1
//    previous_state_po_achr_chapv_ubf1 = Ubc_is_larger_than_UF1;
//    //ПО UCF1
//    previous_state_po_achr_chapv_ucf1 = Uca_is_larger_than_UF1;
//    _AND3(Uab_is_larger_than_UF1, 0, Ubc_is_larger_than_UF1, 0, Uca_is_larger_than_UF1, 0, timer1, 0);
//  }
  _TIMER_T_0(INDEX_TIMER_ACHR_CHAPV_100MS_1, TIMEOUT_ACHR_CHAPV_100MS, timer1, 0, UF1_is_larger_than_U_setpoint_F1, 0);
  //L1
//  UF1_is_smaller_than_U_setpoint_F1 = !UF1_is_larger_than_U_setpoint_F1;
 //L2, 3 
  int F1 = (int) (frequency * 100);
/*
  _Bool po_f1_achr_rab = F1 <= ((int)current_settings_prt.setpoint_achr1_f_rab[number_group_stp]);
  _Bool po_f1_chapv_rab = F1 >= ((int)current_settings_prt.setpoint_chapv1_f_rab[number_group_stp]);
  _Bool po_f1_achr = 0;
раздвоение
*/
  _Bool po_f1_achr1_rab = F1 <= ((int)current_settings_prt.setpoint_achr1_f_rab[number_group_stp]);
  _Bool po_f1_chapv1_rab = F1 >= ((int)current_settings_prt.setpoint_chapv1_f_rab[number_group_stp]);
  _Bool po_f1_achr1 = 0;
  _Bool po_f1_achr2_rab = F1 <= ((int)current_settings_prt.setpoint_achr2_f_rab[number_group_stp]);
  _Bool po_f1_chapv2_rab = F1 >= ((int)current_settings_prt.setpoint_chapv2_f_rab[number_group_stp]);
  _Bool po_f1_achr2 = 0;
//----------

/*  
  //ДВ
  unsigned int tmp_value = (_CHECK_SET_BIT(p_active_functions, RANG_BLOCK_ACHR1) != 0) << 0;
  //L5
  _INVERTOR(tmp_value, 0, tmp_value, 0);
раздвоение
*/
  //ДВ
  //!@unsigned int tmp_value1 = (_CHECK_SET_BIT(p_active_functions, @RANG_BLOCK_ACHR1) != 0) << 0;
  unsigned int tmp_value1 = (_CHECK_SET_BIT(p_active_functions, RNG_BIG_BLOCK_ACHR1) != 0) << 0;
  //L5.1
  _INVERTOR(tmp_value1, 0, tmp_value1, 0);
  //ДВ
  //!@unsigned int tmp_value2 = (_CHECK_SET_BIT(p_active_functions, @RANG_BLOCK_ACHR2) != 0) << 0;
  unsigned int tmp_value2 = (_CHECK_SET_BIT(p_active_functions, RNG_BIG_BLOCK_ACHR2) != 0) << 0;
  //L5
  _INVERTOR(tmp_value2, 0, tmp_value2, 0);
//----------

/*  
  //М
  tmp_value |= ((current_settings_prt.control_achr_chapv & CTR_ACHR1) != 0) << 1;
  //L4
  _AND3_INVERTOR(tmp_value, 0, tmp_value, 1, UF1_is_larger_than_U_setpoint_F1, 0, tmp_value, 3);
раздвоение
*/
  //М
  tmp_value1 |= ((current_settings_prt.control_achr_chapv & CTR_ACHR1) != 0) << 1;
  //L4.1
  _AND3_INVERTOR(tmp_value1, 0, tmp_value1, 1, UF1_is_larger_than_U_setpoint_F1, 0, tmp_value1, 3);
  //М
  tmp_value2 |= ((current_settings_prt.control_achr_chapv & CTR_ACHR2) != 0) << 1;
  //L4.2
  _AND3_INVERTOR(tmp_value2, 0, tmp_value2, 1, UF1_is_larger_than_U_setpoint_F1, 0, tmp_value2, 3);
//----------
/*
  //Reset канал L2
  if (!_GET_STATE(tmp_value, 3))
  {
    //ПО АЧР1
    if (previous_state_po_f1_achr) 
    {
      //отпускание АЧР
//  _Bool po_f1_chapv_rab = F1 >= ((int)current_settings_prt.setpoint_chapv1_f_rab[number_group_stp]);
      if (!po_f1_chapv_rab) 
      {
        //после сработки 1 будет держаться до тех пор пока не сработает po_f1_chapv_rab (условие отпускания)
        _SET_BIT(p_active_functions, RANG_PO_ACHR1);
        po_f1_achr = 1;
      }
    }
    else
    {
      //сработка
//  _Bool po_f1_achr_rab = F1 <= ((int)current_settings_prt.setpoint_achr1_f_rab[number_group_stp]);
      
      if (po_f1_achr_rab)
      {
        _SET_BIT(p_active_functions, RANG_PO_ACHR1);
        po_f1_achr = 1;
      }
    }
  }//if
раздвоение
*/
//---1----
  //Reset канал L2
  if (!_GET_STATE(tmp_value1, 3))
  {
    //ПО АЧР1
    if (previous_state_po_f1_achr1) 
    {
      //отпускание АЧР
//  _Bool po_f1_chapv_rab = F1 >= ((int)current_settings_prt.setpoint_chapv1_f_rab[number_group_stp]);
      if (!po_f1_chapv1_rab) 
      {
        //после сработки 1 будет держаться до тех пор пока не сработает po_f1_chapv_rab (условие отпускания)
        _SET_BIT(p_active_functions, RNG_BIG_PO_ACHR1);//!@_SET_BIT(p_active_functions, @RANG_PO_ACHR1);
        po_f1_achr1 = 1;
      }
      else _CLEAR_BIT(p_active_functions, RNG_BIG_PO_ACHR1);//!@_CLEAR_BIT(p_active_functions, @RANG_PO_ACHR1);
    }
    else
    {
      //сработка
//  _Bool po_f1_achr_rab = F1 <= ((int)current_settings_prt.setpoint_achr1_f_rab[number_group_stp]);
      
      if (po_f1_achr1_rab)
      {
        _SET_BIT(p_active_functions, RNG_BIG_PO_ACHR1);//!@_SET_BIT(p_active_functions, @RANG_PO_ACHR1);
        po_f1_achr1 = 1;
      }
      else _CLEAR_BIT(p_active_functions, RNG_BIG_PO_ACHR1);//!@_CLEAR_BIT(p_active_functions, @RANG_PO_ACHR1);
    }
  }//if
  else
  {
    _CLEAR_BIT(p_active_functions, RNG_BIG_PO_ACHR1);//!@_CLEAR_BIT(p_active_functions, @RANG_PO_ACHR1);
  }
//----2----
  //Reset канал L2
  if (!_GET_STATE(tmp_value2, 3))
  {
    //ПО АЧР1
    if (previous_state_po_f1_achr2) 
    {
      //отпускание АЧР
//  _Bool po_f1_chapv_rab = F1 >= ((int)current_settings_prt.setpoint_chapv1_f_rab[number_group_stp]);
      if (!po_f1_chapv2_rab) 
      {
        //после сработки 1 будет держаться до тех пор пока не сработает po_f1_chapv_rab (условие отпускания)
        _SET_BIT(p_active_functions, RNG_BIG_PO_ACHR2);//!@_SET_BIT(p_active_functions, @RANG_PO_ACHR2);
        po_f1_achr2 = 1;
      }
      else _CLEAR_BIT(p_active_functions, RNG_BIG_PO_ACHR2);//!@_CLEAR_BIT(p_active_functions, @RANG_PO_ACHR2);
    }
    else
    {
      //сработка
//  _Bool po_f1_achr_rab = F1 <= ((int)current_settings_prt.setpoint_achr1_f_rab[number_group_stp]);
      
      if (po_f1_achr2_rab)
      {
        _SET_BIT(p_active_functions, RNG_BIG_PO_ACHR2);//!@_SET_BIT(p_active_functions, @RANG_PO_ACHR2);
        po_f1_achr2 = 1;
      }
      else _CLEAR_BIT(p_active_functions, RNG_BIG_PO_ACHR2);//!@_CLEAR_BIT(p_active_functions, @RANG_PO_ACHR2);
    }
  }//if
  else
  {
    _CLEAR_BIT(p_active_functions, RNG_BIG_PO_ACHR2);//!@_CLEAR_BIT(p_active_functions, @RANG_PO_ACHR2);
  }
//--------------  
/*
  _TIMER_T_0(INDEX_TIMER_ACHR1, current_settings_prt.timeout_achr_1[number_group_stp], po_f1_achr, 0, tmp_value, 5);
раздвоение
*/
//---1---
  _TIMER_T_0(INDEX_TIMER_ACHR1, current_settings_prt.timeout_achr_1[number_group_stp], po_f1_achr1, 0, tmp_value1, 5);
//---2---
  _TIMER_T_0(INDEX_TIMER_ACHR2, current_settings_prt.timeout_achr_2[number_group_stp], po_f1_achr2, 0, tmp_value2, 5);
//-------
  
  //Разр ЧАПВ
  if (UF1_is_larger_than_U_setpoint_F1)
    _SET_BIT(p_active_functions, RNG_BIG_RAZR_CHAPV);//!@_SET_BIT(p_active_functions, @RANG_RAZR_CHAPV);
  else
    _CLEAR_BIT(p_active_functions, RNG_BIG_RAZR_CHAPV);//!@_CLEAR_BIT(p_active_functions, @RANG_RAZR_CHAPV);

/*  
  _Bool tmp1 = 0;
  do 
  {
    //L7
    _OR2(tmp_value, 3, !trigger_CHAPV1, 0, tmp_value, 30);
    
    //ПО ЧАПВ1
    _Bool po_f1_chapv = 0;
    if (previous_state_po_f1_chapv) 
    {
      po_f1_chapv = !po_f1_achr_rab;
    }
    else 
    {
      po_f1_chapv = po_f1_chapv_rab;
    }
    //L3
    _Bool po_f1_chapv_tmp = (!_GET_STATE(tmp_value, 30) && po_f1_chapv);
    if (po_f1_chapv_tmp) 
    {
      _SET_BIT(p_active_functions, RANG_PO_CHAPV1);
    }
    
    _TIMER_T_0(INDEX_TIMER_CHAPV1, current_settings_prt.timeout_chapv_1[number_group_stp], po_f1_chapv_tmp, 0, tmp_value, 6);
    //L8
    _AND2(po_f1_achr, 0, !po_f1_chapv_tmp, 0, tmp_value, 12);
    //L9
    _OR2(tmp_value, 5, tmp_value, 6, tmp_value, 13);

    _D_TRIGGER(_GET_STATE(tmp_value, 12), 0, _GET_STATE(UF1_is_smaller_than_U_setpoint_F1, 0), previous_states_CHAPV1, 0, tmp_value, 13, trigger_CHAPV1, 0);
    if (tmp1 == trigger_CHAPV1) break;
    
    tmp1 = trigger_CHAPV1;
  } 
  while(1);
раздвоение
*/
//----1----
  _Bool tmp1_1 = 0;
  do 
  {
    //L7_1
    _OR2(tmp_value1, 3, !trigger_CHAPV1, 0, tmp_value1, 30);
    
    //ПО ЧАПВ1
    _Bool po_f1_chapv1 = 0;
    if (previous_state_po_f1_chapv1) 
    {
      po_f1_chapv1 = !po_f1_achr1_rab;
    }
    else 
    {
      po_f1_chapv1 = po_f1_chapv1_rab;
    }
    //L3
    _Bool po_f1_chapv1_tmp = (!_GET_STATE(tmp_value1, 30) && po_f1_chapv1);
    if (po_f1_chapv1_tmp) 
      _SET_BIT(p_active_functions, RNG_BIG_PO_CHAPV1);//!@_SET_BIT(p_active_functions, @RANG_PO_CHAPV1);
    else
      _CLEAR_BIT(p_active_functions, RNG_BIG_PO_CHAPV1);//!@_CLEAR_BIT(p_active_functions, @RANG_PO_CHAPV1);
    
    _TIMER_T_0(INDEX_TIMER_CHAPV1, current_settings_prt.timeout_chapv_1[number_group_stp], po_f1_chapv1_tmp, 0, tmp_value1, 6);
    //L8
    _AND2(po_f1_achr1, 0, !po_f1_chapv1_tmp, 0, tmp_value1, 12);
    //L9
    _OR2(tmp_value1, 5, tmp_value1, 6, tmp_value1, 13);

    _D_TRIGGER(_GET_STATE(tmp_value1, 12), 0, _GET_STATE(tmp_value1, 3), previous_states_CHAPV1, 0, tmp_value1, 13, trigger_CHAPV1, 0);
    if (tmp1_1 == trigger_CHAPV1) break;
    
    tmp1_1 = trigger_CHAPV1;
  } 
  while(1);
//----2----
  _Bool tmp1_2 = 0;
  do 
  {
    //L7_2
    _OR2(tmp_value2, 3, !trigger_CHAPV2, 0, tmp_value2, 30);
    
    //ПО ЧАПВ2
    _Bool po_f1_chapv2 = 0;
    if (previous_state_po_f1_chapv2) 
    {
      po_f1_chapv2 = !po_f1_achr2_rab;
    }
    else 
    {
      po_f1_chapv2 = po_f1_chapv2_rab;
    }
    //L3_2
    _Bool po_f1_chapv2_tmp = (!_GET_STATE(tmp_value2, 30) && po_f1_chapv2);
    if (po_f1_chapv2_tmp) 
      _SET_BIT(p_active_functions, RNG_BIG_PO_CHAPV2);//!@_SET_BIT(p_active_functions, @RANG_PO_CHAPV2);
    else
      _CLEAR_BIT(p_active_functions, RNG_BIG_PO_CHAPV2);//!@_CLEAR_BIT(p_active_functions, @RANG_PO_CHAPV2);
    
    _TIMER_T_0(INDEX_TIMER_CHAPV2, current_settings_prt.timeout_chapv_2[number_group_stp], po_f1_chapv2_tmp, 0, tmp_value2, 6);
    //L8_2
    _AND2(po_f1_achr2, 0, !po_f1_chapv2_tmp, 0, tmp_value2, 12);
    //L9_2
    _OR2(tmp_value2, 5, tmp_value2, 6, tmp_value2, 13);

    _D_TRIGGER(_GET_STATE(tmp_value2, 12), 0, _GET_STATE(tmp_value2, 3), previous_states_CHAPV2, 0, tmp_value2, 13, trigger_CHAPV2, 0);
    if (tmp1_2 == trigger_CHAPV2) break;
    
    tmp1_2 = trigger_CHAPV2;
  } 
  while(1);
//---------
/*  
  //АЧР/ЧАПВ
  if (_GET_STATE(trigger_CHAPV1, 0)) 
  {
    _SET_BIT(p_active_functions, RANG_ACHR_CHAPV1);
  }
  
  _Bool chapv_timer_1ms = 0;
  _Bool razr_chapv_inv = 0;
  _TIMER_0_T(INDEX_TIMER_CHAPV_1MS, TIMEOUT_CHAPV_1MS, trigger_CHAPV1, 0, chapv_timer_1ms, 0);
  _INVERTOR(UF1_is_larger_than_U_setpoint_F1, 0, razr_chapv_inv, 0);
  _AND2(chapv_timer_1ms, 0, razr_chapv_inv, 0, tmp_value, 24);
  _TIMER_0_T(INDEX_TIMER_BLOCK_CHAPV_5MS, TIMEOUT_BLOCK_CHAPV_5MS, tmp_value, 24, tmp_value, 25);
раздвоение
*/
//----1----
  //АЧР/ЧАПВ
  if (_GET_STATE(trigger_CHAPV1, 0)) 
    _SET_BIT(p_active_functions, RNG_BIG_ACHR_CHAPV1);//!@_SET_BIT(p_active_functions, @RANG_ACHR_CHAPV1);
  else
    _CLEAR_BIT(p_active_functions, RNG_BIG_ACHR_CHAPV1);//!@_CLEAR_BIT(p_active_functions, @RANG_ACHR_CHAPV1);

//----2----
  //АЧР/ЧАПВ
  if (_GET_STATE(trigger_CHAPV2, 0)) 
    _SET_BIT(p_active_functions, RNG_BIG_ACHR_CHAPV2);//!@_SET_BIT(p_active_functions, @RANG_ACHR_CHAPV2);
  else
    _CLEAR_BIT(p_active_functions, RNG_BIG_ACHR_CHAPV2);//!@_CLEAR_BIT(p_active_functions, @RANG_ACHR_CHAPV2);

  //Блокування ЧАПВ
  unsigned int tmp_value_g = 0;
  _TIMER_0_T(INDEX_TIMER_CHAPV1_1MS, TIMEOUT_CHAPV_1MS, trigger_CHAPV1, 0, tmp_value_g, 0);
  _TIMER_0_T(INDEX_TIMER_CHAPV2_1MS, TIMEOUT_CHAPV_1MS, trigger_CHAPV2, 0, tmp_value_g, 1);
  
  _AND2(tmp_value_g, 0, tmp_value1, 3, tmp_value_g, 2);
  _AND2(tmp_value_g, 1, tmp_value2, 3, tmp_value_g, 3);
  
  _TIMER_0_T(INDEX_TIMER_BLOCK_CHAPV1_5MS, TIMEOUT_BLOCK_CHAPV_5MS, tmp_value_g, 2, tmp_value_g, 4);
  _TIMER_0_T(INDEX_TIMER_BLOCK_CHAPV2_5MS, TIMEOUT_BLOCK_CHAPV_5MS, tmp_value_g, 3, tmp_value_g, 5);
  
  _OR2(tmp_value_g, 4, tmp_value_g, 5, tmp_value_g, 6);

  if (_GET_STATE(tmp_value_g, 6))
      _SET_BIT(p_active_functions, RNG_BIG_VN_BLOCK_CHAPV);//!@_SET_BIT(p_active_functions, @RANG_VN_BLOCK_CHAPV);
  else
      _CLEAR_BIT(p_active_functions, RNG_BIG_VN_BLOCK_CHAPV);//!@_CLEAR_BIT(p_active_functions, @RANG_VN_BLOCK_CHAPV);
}

/*****************************************************/

/*****************************************************/
// Готовность к ТУ
/*****************************************************/
void ready_tu(unsigned int *p_active_functions)
{
  unsigned int tmp_value = (_CHECK_SET_BIT(p_active_functions, RNG_BIG_PRYVID_VVO) == 0)                  << 0;
  tmp_value |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_VIDKL_VID_ZAKHYSTIV_VVO) != 0)                 << 1;
  tmp_value |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_RESET_BLOCK_READY_TU_VID_ZAHYSTIV) != 0)      << 2;
  tmp_value |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_AVAR_DEFECT) == 0)                            << 3;
  tmp_value |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_MISCEVE_DYSTANCIJNE) == 0)                    << 6;
  
  _Bool ctrl_ready_tu = ((current_settings_prt.control_extra_settings_1 & CTR_EXTRA_SETTINGS_1_CTRL_READY_TU) == 0);
  
  if (!previous_states_ready_tu && _GET_STATE(tmp_value, 1)) {
    previous_states_ready_tu = 0;
  }
  
  _OR2(tmp_value, 2, ctrl_ready_tu, 0, tmp_value, 7);
  _D_TRIGGER(1, 0, _GET_STATE(tmp_value, 7), previous_states_ready_tu, 0, tmp_value, 1, trigger_ready_tu, 0);
  
  _AND4(tmp_value, 0, tmp_value, 3, !trigger_ready_tu, 0, tmp_value, 6, tmp_value, 5);
  
  //Готовность к ТУ
  if (_GET_STATE(tmp_value, 5))
    _SET_BIT(p_active_functions, RNG_BIG_READY_TU);
  else
    _CLEAR_BIT(p_active_functions, RNG_BIG_READY_TU);
}
/*****************************************************/

/*****************************************************/
// УРОВ
/*****************************************************/
inline void urov_handler(unsigned int *p_active_functions, unsigned int number_group_stp)
{
  /*******************************/
  //Визначаємо максимальний фазовий струм для УРОВ
  /*******************************/
  unsigned int max_faze_current = measurement[IM_Imn];
  //if (max_faze_current < measurement[IM_Ibp]) max_faze_current = measurement[IM_Ibp];
  /*******************************/
  
  /*******************************/
  uint32_t state_UROV = (( current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STATE)) != 0);
  uint32_t start_from_UP = false;
  if (
      (state_UROV != 0) &&
      ((current_settings_prt.control_urov & (((uint64_t)(MASKA_FOR_BIT(NUMBER_UP) - 1)) << INDEX_ML_CTRUROV_STARTED_FROM_UP1)) != 0)
     )   
  {
    //Налаштовано запуск ПРЗЗ від УЗ
    for (size_t n_UP = 0; n_UP < NUMBER_UP; n_UP++)
    {
      if ( 
          ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_UP1 + n_UP)) != 0) && 
          //(_CHECK_SET_BIT(p_active_functions, (RANG_UP1 + 3*n_UP)      ) != 0)
          (_CHECK_SET_BIT(p_active_functions, (RNG_BIG_UP1 + 3*n_UP)      ) != 0)
         )
      {
        start_from_UP = true;
      }
    }
  }
  
  if(
     (state_UROV != 0) &&
     (
      (start_from_UP == true) ||
      //(_CHECK_SET_BIT(p_active_functions, RANG_PUSK_UROV_VID_DV) != 0) ||
      (_CHECK_SET_BIT(p_active_functions, RNG_BIG_PUSK_UROV_VID_DV) != 0) ||
        
//      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_DZ1)    ) != 0) && (_CHECK_SET_BIT(p_active_functions, RANG_DZ1              ) != 0)) ||
//      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_AMTDZ1) ) != 0) && (_CHECK_SET_BIT(p_active_functions, RANG_AMTZ_DZ1         ) != 0)) ||
//      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_DZ2)    ) != 0) && (_CHECK_SET_BIT(p_active_functions, RANG_DZ2              ) != 0)) ||
//      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_AMTDZ2) ) != 0) && (_CHECK_SET_BIT(p_active_functions, RANG_AMTZ_DZ2         ) != 0)) ||
//      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_DZ3)    ) != 0) && (_CHECK_SET_BIT(p_active_functions, RANG_DZ3              ) != 0)) ||
//      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_AMTDZ3) ) != 0) && (_CHECK_SET_BIT(p_active_functions, RANG_AMTZ_DZ3         ) != 0)) ||
//      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_DZ4)    ) != 0) && (_CHECK_SET_BIT(p_active_functions, RANG_DZ4              ) != 0)) ||
//      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_AMTDZ4) ) != 0) && (_CHECK_SET_BIT(p_active_functions, RANG_AMTZ_DZ4         ) != 0)) ||
        
      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_DZ1)    ) != 0) && (_CHECK_SET_BIT(p_active_functions, RNG_BIG_DZO1              ) != 0)) ||
      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_AMTDZ1) ) != 0) && (_CHECK_SET_BIT(p_active_functions, RNG_BIG_AMCZ_DZO1         ) != 0)) ||
      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_DZ2)    ) != 0) && (_CHECK_SET_BIT(p_active_functions, RNG_BIG_DZO2              ) != 0)) ||
      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_AMTDZ2) ) != 0) && (_CHECK_SET_BIT(p_active_functions, RNG_BIG_AMCZ_DZO2         ) != 0)) ||
      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_DZ3)    ) != 0) && (_CHECK_SET_BIT(p_active_functions, RNG_BIG_DZO3              ) != 0)) ||
      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_AMTDZ3) ) != 0) && (_CHECK_SET_BIT(p_active_functions, RNG_BIG_AMCZ_DZO3         ) != 0)) ||
      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_DZ4)    ) != 0) && (_CHECK_SET_BIT(p_active_functions, RNG_BIG_DZO4              ) != 0)) ||
      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_AMTDZ4) ) != 0) && (_CHECK_SET_BIT(p_active_functions, RNG_BIG_AMCZ_DZO4         ) != 0)) ||
        
      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_MTZ1)   ) != 0) && (_CHECK_SET_BIT(p_active_functions, RNG_BIG_MCZO1             ) != 0)) ||
      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_MTZ2)   ) != 0) && (_CHECK_SET_BIT(p_active_functions, RNG_BIG_MCZO2             ) != 0)) ||
      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_MTZ3)   ) != 0) && (_CHECK_SET_BIT(p_active_functions, RNG_BIG_MCZO3             ) != 0)) ||
      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_MTZ4)   ) != 0) && (_CHECK_SET_BIT(p_active_functions, RNG_BIG_MCZO4             ) != 0)) ||
        
      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_ZDZ)    ) != 0) && (_CHECK_SET_BIT(p_active_functions, RNG_BIG_ZDZ              ) != 0)) ||
        
//      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_3I0)    ) != 0) && (_CHECK_SET_BIT(p_active_functions, RANG_3I0              ) != 0)) ||
//      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_3U0)    ) != 0) && (_CHECK_SET_BIT(p_active_functions, RANG_3U0              ) != 0)) ||
//      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_NZZ)    ) != 0) && (_CHECK_SET_BIT(p_active_functions, RANG_NZZ              ) != 0)) ||
        
//      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_TZNP1)  ) != 0) && (_CHECK_SET_BIT(p_active_functions, RANG_TZNP1            ) != 0)) ||
//      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_TZNP2)  ) != 0) && (_CHECK_SET_BIT(p_active_functions, RANG_TZNP2            ) != 0)) ||
//      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_TZNP3)  ) != 0) && (_CHECK_SET_BIT(p_active_functions, RANG_TZNP3            ) != 0)) ||
        
//      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_ZOP1)   ) != 0) && (_CHECK_SET_BIT(p_active_functions, RANG_ZOP              ) != 0)) ||
        
      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_UMIN1)  ) != 0) && (_CHECK_SET_BIT(p_active_functions, RNG_BIG_UMIN1            ) != 0)) ||
      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_UMIN2)  ) != 0) && (_CHECK_SET_BIT(p_active_functions, RNG_BIG_UMIN2            ) != 0)) ||
        
      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_UMAX1)  ) != 0) && (_CHECK_SET_BIT(p_active_functions, RNG_BIG_UMAX1            ) != 0)) ||
      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_UMAX2)  ) != 0) && (_CHECK_SET_BIT(p_active_functions, RNG_BIG_UMAX2            ) != 0)) ||
        
      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_ACHR1)  ) != 0) && (_CHECK_SET_BIT(p_active_functions, RNG_BIG_ACHR_CHAPV1      ) != 0)) ||
      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_ACHR2)  ) != 0) && (_CHECK_SET_BIT(p_active_functions, RNG_BIG_ACHR_CHAPV2      ) != 0))
     )     
    )
  {
    //Є умова запуску УРОВ
    
    unsigned int setpoint; //уставка - з якою зрівнюється вимірювальна величина
    unsigned int previous_state_po_urov;
    
    //Якщо ПО УРОВ ще не активне, то треба працювати по устаці спацювання - уставці, яка вводиться як основна з системи меню чи верхнього рівня
    //Якщо ПО УРОВ вже спрацювало, то треба працювати по уставці відпускання - береться процент від основної утанки по коефіцієнту повернення
    //if(( previous_state_po_urov = _CHECK_SET_BIT(p_active_functions, RANG_PO_UROV) ) ==0 )
    if(( previous_state_po_urov = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_UROV) ) ==0 )
    {
      //Працюємо по утавці спрацювання
      setpoint = current_settings_prt.setpoint_urov[number_group_stp];
    }
    else
    {
      //Працюємо по утавці відпускання
      setpoint = current_settings_prt.setpoint_urov[number_group_stp]*KOEF_POVERNENNJA_GENERAL_UP/100;
    }
    
    //Виставляємо, або скидаємо сигнал "ПО УРОВ"
    if (max_faze_current >= setpoint)
    {
      //Максимальний фазний стум перевищує свою уставку
      if(previous_state_po_urov == 0)
      {
        //Встановлюємо сигнал "ПО УРОВ"
        //_SET_BIT(p_active_functions, RANG_PO_UROV);
        _SET_BIT(p_active_functions, RNG_BIG_PO_UROV);
      
        //Запускаємо таймери УРОВ1 і УРОВ2, якщо вони ще не запущені
        global_timers[INDEX_TIMER_UROV1] = 0;
        global_timers[INDEX_TIMER_UROV2] = 0;
      }
    }
    else 
    {
      //Максимальний фазний стум нижче уставки
      if(previous_state_po_urov != 0)
      {
        //Скидаємо сигнал "ПО УРОВ"
        _CLEAR_BIT(p_active_functions, RNG_BIG_PO_UROV);//_CLEAR_BIT(p_active_functions, RANG_PO_UROV);
        //Це є умовою також скидання сигналів "Сраб. УРОВ1" і "Сраб. УРОВ2"
        _CLEAR_BIT(p_active_functions, RNG_BIG_UROV1);  //_CLEAR_BIT(p_active_functions, RANG_UROV1);
        _CLEAR_BIT(p_active_functions, RNG_BIG_UROV2);  //_CLEAR_BIT(p_active_functions, RANG_UROV2);
        //Якщо таймери ще не скинуті, то скидаємо їх
        if ( global_timers[INDEX_TIMER_UROV1] >=0) global_timers[INDEX_TIMER_UROV1] = -1;
        if ( global_timers[INDEX_TIMER_UROV2] >=0) global_timers[INDEX_TIMER_UROV2] = -1;
      }
    }
    
    //Перевіряємо чи таймер УРОВ1 досягнув значення своєї витримки
    if(global_timers[INDEX_TIMER_UROV1] >= current_settings_prt.timeout_urov_1[number_group_stp])
    {
      //Якщо витримана Витримка УРОВ1 то встановлюємо сигнал "Сраб. УРОВ1"
      _SET_BIT(p_active_functions, RNG_BIG_UROV1);//_SET_BIT(p_active_functions, RANG_UROV1);

      //Скидаємо таймер УРОВ1
      global_timers[INDEX_TIMER_UROV1] = -1;
    }

    //Перевіряємо чи таймер УРОВ2 досягнув значення своєї витримки
    if(global_timers[INDEX_TIMER_UROV2] >= current_settings_prt.timeout_urov_2[number_group_stp])
    {
      //Якщо витримана Витримка УРОВ2 то встановлюємо сигнал "Сраб. УРОВ2"
      _SET_BIT(p_active_functions, RNG_BIG_UROV2);//_SET_BIT(p_active_functions, RANG_UROV2);

      //Скидаємо таймер УРОВ2
      global_timers[INDEX_TIMER_UROV2] = -1;
    }
  }
  else
  {
    //Треба скинути всі таймери і сигнали, які за УРОВ відповідають
    _CLEAR_BIT(p_active_functions, RNG_BIG_PO_UROV);//_CLEAR_BIT(p_active_functions, RANG_PO_UROV);
    _CLEAR_BIT(p_active_functions, RNG_BIG_UROV1);  //_CLEAR_BIT(p_active_functions, RANG_UROV1);
    _CLEAR_BIT(p_active_functions, RNG_BIG_UROV2);  //_CLEAR_BIT(p_active_functions, RANG_UROV2);
    global_timers[INDEX_TIMER_UROV1] = -1;
    global_timers[INDEX_TIMER_UROV2] = -1;
  }  
}
  /*******************************/
/*****************************************************/

/*****************************************************/
//АПВ
/*****************************************************/
inline void apv_handler(unsigned int *p_active_functions, unsigned int number_group_stp)
{
  unsigned int logic_APV_0 = 0;
  unsigned int logic_APV_1 = 0;
  unsigned int logic_APV_2 = 0;
  unsigned int logic_APV_3 = 0;

  //Рестарт пристрою
  logic_APV_1 |= (start_restart != 0) << 19;
  //Очищаємо повідомлення про рестрат пристрою
  start_restart = 0;

  //"Стан вимикача"
  //logic_APV_0 |= (_CHECK_SET_BIT(p_active_functions, RANG_STATE_VV) != 0) << 21;
  logic_APV_0 |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_STATE_VVO) != 0) << 21;
  _TIMER_IMPULSE(INDEX_TIMER_APV_BLOCK_VID_VV, current_settings_prt.timeout_apv_block_vid_VV[number_group_stp], previous_states_APV_0, 0, logic_APV_0, 21, logic_APV_0, 22);

  //"Статичне блокування"
  //logic_APV_0 |= (_CHECK_SET_BIT(p_active_functions, RANG_STAT_BLK_APV) != 0) << 0;
  logic_APV_0 |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_STAT_BLK_APV) != 0) << 0;
  _INVERTOR(logic_APV_0, 0, logic_APV_0, 1);

  //М:"Пуск від МТЗ1"
  logic_APV_0 |= ((current_settings_prt.control_apv & CTR_APV_STARTED_FROM_MTZ1) != 0) << 2;
  //"МТЗ1"
  //logic_APV_0 |= (_CHECK_SET_BIT(p_active_functions, RANG_MTZ1) != 0) << 3;
  logic_APV_0 |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_MCZO1) != 0) << 3;
  _AND2(logic_APV_0, 2, logic_APV_0, 3, logic_APV_0, 4);

  //М:"Пуск від МТЗ2"
  logic_APV_0 |= ((current_settings_prt.control_apv & CTR_APV_STARTED_FROM_MTZ2) != 0) << 5;
  //"МТЗ2"
  //logic_APV_0 |= (_CHECK_SET_BIT(p_active_functions, RANG_MTZ2) != 0) << 6;
  logic_APV_0 |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_MCZO2) != 0) << 6;
  _AND2(logic_APV_0, 5, logic_APV_0, 6, logic_APV_0, 7);

  //М:"Пуск від МТЗ3"
  logic_APV_0 |= ((current_settings_prt.control_apv & CTR_APV_STARTED_FROM_MTZ3) != 0) << 8;
  //"МТЗ3"
  //logic_APV_0 |= (_CHECK_SET_BIT(p_active_functions, RANG_MTZ3) != 0) << 9;
  logic_APV_0 |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_MCZO3) != 0) << 9;
  _AND2(logic_APV_0, 8, logic_APV_0, 9, logic_APV_0, 10);

  //М:"Пуск від МТЗ4"
  logic_APV_0 |= ((current_settings_prt.control_apv & CTR_APV_STARTED_FROM_MTZ4) != 0) << 11;
  //"МТЗ4"
  //logic_APV_0 |= (_CHECK_SET_BIT(p_active_functions, RANG_MTZ4) != 0) << 12;
  logic_APV_0 |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_MCZO4) != 0) << 12;
  _AND2(logic_APV_0, 11, logic_APV_0, 12, logic_APV_0, 13);
  
  /***/

  //М:"Пуск від ДЗ1"
  logic_APV_1 |= ((current_settings_prt.control_apv & CTR_APV_STARTED_FROM_DZ1) != 0) << 30;
  //"ДЗ1"
  //logic_APV_1 |= (_CHECK_SET_BIT(p_active_functions, RANG_DZ1) != 0) << 31;
  logic_APV_1 |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_DZO1) != 0) << 31;
  _AND2(logic_APV_1, 30, logic_APV_1, 31, logic_APV_2, 20);

  //М:"Пуск від ДЗ2"
  logic_APV_2 |= ((current_settings_prt.control_apv & CTR_APV_STARTED_FROM_DZ2) != 0) << 0;
  //"ДЗ2"
  //logic_APV_2 |= (_CHECK_SET_BIT(p_active_functions, RANG_DZ2) != 0) << 1;
  logic_APV_2 |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_DZO2) != 0) << 1;
  _AND2(logic_APV_2, 0, logic_APV_2, 1, logic_APV_2, 21);

  //М:"Пуск від ДЗ3"
  logic_APV_2 |= ((current_settings_prt.control_apv & CTR_APV_STARTED_FROM_DZ3) != 0) << 2;
  //"ДЗ3"
  //logic_APV_2 |= (_CHECK_SET_BIT(p_active_functions, RANG_DZ3) != 0) << 3;
  logic_APV_2 |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_DZO3) != 0) << 3;
  _AND2(logic_APV_2, 2, logic_APV_2, 3, logic_APV_2, 22);

  //М:"Пуск від ДЗ4"
  logic_APV_2 |= ((current_settings_prt.control_apv & CTR_APV_STARTED_FROM_DZ4) != 0) << 4;
  //"ДЗ4"
  //logic_APV_2 |= (_CHECK_SET_BIT(p_active_functions, RANG_DZ4) != 0) << 5;
  logic_APV_2 |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_DZO4) != 0) << 5;
  _AND2(logic_APV_2, 4, logic_APV_2, 5, logic_APV_2, 23);

  _OR4(logic_APV_2, 20, logic_APV_2, 21, logic_APV_2, 22, logic_APV_2, 23, logic_APV_2, 31);

  //М:"Пуск від АМСЗ1"
  logic_APV_2 |= ((current_settings_prt.control_apv & CTR_APV_STARTED_FROM_AMTDZ1) != 0) << 6;
  //"АМСЗ1"
  //logic_APV_2 |= (_CHECK_SET_BIT(p_active_functions, RANG_AMTZ_DZ1) != 0) << 7;
  logic_APV_2 |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_AMCZ_DZO1) != 0) << 7;
  _AND2(logic_APV_2, 6, logic_APV_2, 7, logic_APV_2, 24);

  //М:"Пуск від АМСЗ2"
  logic_APV_2 |= ((current_settings_prt.control_apv & CTR_APV_STARTED_FROM_AMTDZ2) != 0) << 8;
  //"АМСЗ2"
  //logic_APV_2 |= (_CHECK_SET_BIT(p_active_functions, RANG_AMTZ_DZ2) != 0) << 9;
  logic_APV_2 |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_AMCZ_DZO2) != 0) << 9;
  _AND2(logic_APV_2, 8, logic_APV_2, 9, logic_APV_2, 25);

  //М:"Пуск від АМСЗ3"
  logic_APV_2 |= ((current_settings_prt.control_apv & CTR_APV_STARTED_FROM_AMTDZ3) != 0) << 10;
  //"АМСЗ3"
  //logic_APV_2 |= (_CHECK_SET_BIT(p_active_functions, RANG_AMTZ_DZ3) != 0) << 11;
  logic_APV_2 |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_AMCZ_DZO3) != 0) << 11;
  _AND2(logic_APV_2, 10, logic_APV_2, 11, logic_APV_2, 26);

  //М:"Пуск від АМСЗ4"
  logic_APV_2 |= ((current_settings_prt.control_apv & CTR_APV_STARTED_FROM_AMTDZ4) != 0) << 12;
  //"АМСЗ4"
  //logic_APV_2 |= (_CHECK_SET_BIT(p_active_functions, RANG_AMTZ_DZ4) != 0) << 13;
  logic_APV_2 |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_AMCZ_DZO4) != 0) << 13;
  _AND2(logic_APV_2, 12, logic_APV_2, 13, logic_APV_2, 27);

  _OR4(logic_APV_2, 24, logic_APV_2, 25, logic_APV_2, 26, logic_APV_2, 27, logic_APV_3, 0);

  //М:"Пуск від СЗНП1"
//  logic_APV_2 |= ((current_settings_prt.control_apv & CTR_APV_STARTED_FROM_TZNP1) != 0) << 14;
//  //"СЗНП1"
//  //logic_APV_2 |= (_CHECK_SET_BIT(p_active_functions, RANG_TZNP1) != 0) << 15;
//  logic_APV_2 |= (_CHECK_SET_BIT(p_active_functions, RANG_TZNP1) != 0) << 15;
//  _AND2(logic_APV_2, 14, logic_APV_2, 15, logic_APV_2, 28);

  //М:"Пуск від СЗНП2"
//  logic_APV_2 |= ((current_settings_prt.control_apv & CTR_APV_STARTED_FROM_TZNP2) != 0) << 16;
//  //"СЗНП2"
//  //logic_APV_2 |= (_CHECK_SET_BIT(p_active_functions, RANG_TZNP2) != 0) << 17;
//  logic_APV_2 |= (_CHECK_SET_BIT(p_active_functions, RANG_TZNP2) != 0) << 17;
//  _AND2(logic_APV_2, 16, logic_APV_2, 17, logic_APV_2, 29);

  //М:"Пуск від СЗНП3"
//  logic_APV_2 |= ((current_settings_prt.control_apv & CTR_APV_STARTED_FROM_TZNP3) != 0) << 18;
//  //"СЗНП3"
//  //logic_APV_2 |= (_CHECK_SET_BIT(p_active_functions, RANG_TZNP3) != 0) << 19;
//  logic_APV_2 |= (_CHECK_SET_BIT(p_active_functions, RANG_TZNP3) != 0) << 19;
//  _AND2(logic_APV_2, 18, logic_APV_2, 19, logic_APV_2, 30);
  
  _OR3(logic_APV_2, 28, logic_APV_2, 29, logic_APV_2, 30, logic_APV_3, 1);
  /***/
  
  _OR4(logic_APV_0,  4, logic_APV_0,  7, logic_APV_0, 10, logic_APV_0, 13, logic_APV_0, 14);
  _OR4(logic_APV_0, 14, logic_APV_2, 31, logic_APV_3,  0, logic_APV_3,  1, logic_APV_3,  2);

  //М:"Блок.контр.ст.ВВ"
  logic_APV_3 |= ((current_settings_prt.control_apv & CTR_APV_CTRAPV_BLK_CTRL_VV) != 0) << 11;
  _INVERTOR(logic_APV_3, 11, logic_APV_3, 12);
  _AND2(logic_APV_0, 21, logic_APV_3, 11, logic_APV_3, 13);
  _OR3(logic_APV_3, 13, logic_APV_3, 12, previous_states_APV_0, 9, logic_APV_3, 3);
  _AND2(logic_APV_3, 2, logic_APV_3, 3, previous_states_APV_0, 9);

  _TIMER_0_T(INDEX_TIMER_APV_TMP1, 1, previous_states_APV_0, 9, logic_APV_0, 15);

  //М:"ЧАПВ 1"
  logic_APV_0 |= ((current_settings_prt.control_achr_chapv & CTR_CHAPV1) != 0) << 16;
  //"АЧР/ЧАПВ 1"
  //logic_APV_1 |= (_CHECK_SET_BIT(p_active_functions, RANG_ACHR_CHAPV1) != 0) << 21;
  logic_APV_1 |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_ACHR_CHAPV1) != 0) << 21;
  //М:"ЧАПВ 2"
  logic_APV_1 |= ((current_settings_prt.control_achr_chapv & CTR_CHAPV2) != 0) << 27;
  //"АЧР/ЧАПВ 2"
  //logic_APV_1 |= (_CHECK_SET_BIT(p_active_functions, RANG_ACHR_CHAPV2) != 0) << 28;
  logic_APV_1 |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_ACHR_CHAPV2) != 0) << 28;
  //"Разр ЧАПВ"
  //logic_APV_1 |= (_CHECK_SET_BIT(p_active_functions, RANG_RAZR_CHAPV) != 0) << 20;
  logic_APV_1 |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_RAZR_CHAPV) != 0) << 20;

  //"АЧР/ЧАПВ від ДВ"
  //logic_APV_0 |= (_CHECK_SET_BIT(p_active_functions, RANG_ACHR_CHAPV_VID_DV) != 0) << 17;
  logic_APV_0 |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_ACHR_CHAPV_VID_DV) != 0) << 17;
  //М:"ЧАПВ від ДВ"
  logic_APV_1 |= ((current_settings_prt.control_achr_chapv & CTR_CHAPV_VID_DV) != 0) << 22;
  
  _AND3(logic_APV_0, 16, logic_APV_1, 21, logic_APV_1, 20, logic_APV_1, 23);
  _AND3(logic_APV_1, 27, logic_APV_1, 28, logic_APV_1, 20, logic_APV_1, 29);
  _AND2(logic_APV_0, 17, logic_APV_1, 22, logic_APV_1, 24);
  _OR3(logic_APV_1, 23, logic_APV_1, 29, logic_APV_1, 24, logic_APV_0, 18)

  //"Блок.ЧАПВ"
  //logic_APV_1 |= (_CHECK_SET_BIT(p_active_functions, RANG_VN_BLOCK_CHAPV) != 0) << 25;
  logic_APV_1 |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_VN_BLOCK_CHAPV) != 0) << 25;
  _OR2(logic_APV_0, 18, logic_APV_1, 25, logic_APV_1, 26);
    
  _TIMER_0_T(INDEX_TIMER_ACHR_CHAPV, MAX_VALUE_TIMER_FOR_COUNT_SIGNAL_ACHR_CHAPV, logic_APV_0, 18, logic_APV_0, 19);

  _OR2_INVERTOR(logic_APV_0, 15, logic_APV_0, 19, logic_APV_0, 20);

  //М:"АПВ"
  logic_APV_0 |= ((current_settings_prt.control_apv & CTR_APV_STAGE_1) != 0) << 23;
  _INVERTOR(logic_APV_0, 23, logic_APV_0, 24);

  //М:"АПВ2"
  logic_APV_0 |= ((current_settings_prt.control_apv & CTR_APV_STAGE_2) != 0) << 25;
  _INVERTOR(logic_APV_0, 25, logic_APV_0, 26);

  //М:"АПВ3"
  logic_APV_0 |= ((current_settings_prt.control_apv & CTR_APV_STAGE_3) != 0) << 27;
  _INVERTOR(logic_APV_0, 27, logic_APV_0, 28);

  //М:"АПВ4"
  logic_APV_0 |= ((current_settings_prt.control_apv & CTR_APV_STAGE_4) != 0) << 29;
  _INVERTOR(logic_APV_0, 29, logic_APV_0, 30);

  //Наступні операції виконуються ітераційно поки всі сигнали не встановляться у фіксований стан
  logic_APV_0 |= _GET_STATE(previous_states_APV_0, 1) << 31;
  logic_APV_1 |= _GET_STATE(previous_states_APV_0, 2) <<  0;
  logic_APV_1 |= _GET_STATE(previous_states_APV_0, 3) <<  1;
  logic_APV_1 |= _GET_STATE(previous_states_APV_0, 4) <<  2;
  
  //logic_APV_3 |= (_CHECK_SET_BIT(p_active_functions, RANG_UROV2) != 0) << 4;
  logic_APV_3 |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_UROV2) != 0) << 4;
  logic_APV_3 |= ((current_settings_prt.control_apv & CTR_APV_CTRAPV_BLK_CTRL_PRVV2) != 0) << 6;
  _AND2(logic_APV_3, 4, logic_APV_3, 6, logic_APV_3, 14);
  _TIMER_0_T(INDEX_TIMER_APV_TMP2, 40, logic_APV_3, 14, logic_APV_3, 5);

  unsigned int previous_trigger_APV_0;
  
  /*
  Скидаємо спочатку ці сигнали, бо у циклі do-while будемо їх виставляти,
  але після виставлення їх піде сигнал на очищення триґера, який і, фактично, буде
  означати очищення цих сигналів.
  Щоб зафіксувати спрацювання цих сигналів, ми їх очищуємо всіх перед циклом, а
  у циклі будемо тільки виставляти
  */
  _CLEAR_BIT(p_active_functions, RNG_BIG_APV1);//_CLEAR_BIT(p_active_functions, RANG_APV1);
  _CLEAR_BIT(p_active_functions, RNG_BIG_APV2);//_CLEAR_BIT(p_active_functions, RANG_APV2);
  _CLEAR_BIT(p_active_functions, RNG_BIG_APV3);//_CLEAR_BIT(p_active_functions, RANG_APV3);
  _CLEAR_BIT(p_active_functions, RNG_BIG_APV4);//_CLEAR_BIT(p_active_functions, RANG_APV4);
  do
  {
    /***
    Фіксуємо теперішній стан сигналів, які потім, можливо, зміняться і від зміни
    стану яких залежить завершення ітераційного процесу
    ***/
    _CLEAR_STATE(previous_states_APV_0, 1);
    previous_states_APV_0 |= _GET_STATE(logic_APV_0, 31) << 1;
    _CLEAR_STATE(previous_states_APV_0, 2);
    previous_states_APV_0 |= _GET_STATE(logic_APV_1,  0) << 2;
    _CLEAR_STATE(previous_states_APV_0, 3);
    previous_states_APV_0 |= _GET_STATE(logic_APV_1,  1) << 3;
    _CLEAR_STATE(previous_states_APV_0, 4);
    previous_states_APV_0 |= _GET_STATE(logic_APV_1,  2) << 4;
    
    previous_trigger_APV_0 = trigger_APV_0;
    /***/
    
    _OR2(logic_APV_1, 2, logic_APV_1, 1, logic_APV_1, 3);
    
    
    //АПВ1
    _OR6(logic_APV_1, 19, previous_states_APV_0, 9, trigger_APV_0, 1, trigger_APV_0, 2, trigger_APV_0, 3, logic_APV_0, 31, logic_APV_1, 4);
    _OR6(logic_APV_1, 26, logic_APV_0, 22, logic_APV_0, 24, logic_APV_1, 3, logic_APV_1, 0, logic_APV_1, 4, logic_APV_1, 8);
    _OR2(logic_APV_1, 8, logic_APV_3, 5, logic_APV_3, 7);
    _D_TRIGGER(_GET_STATE(logic_APV_0, 1),  0, _GET_STATE(logic_APV_3, 7), previous_states_APV_0, 5, logic_APV_0, 20, trigger_APV_0, 0);                 
    _TIMER_T_0(INDEX_TIMER_APV_1, current_settings_prt.timeout_apv_1[number_group_stp], trigger_APV_0, 0, logic_APV_1, 9);
    /*
    Цей сигнал встановлюмо в масив p_active_functions в циклі з післяумовою
    do-while, бо нас цікавить зафіксувати цей сигнал, а коли він виставиться, то
    піде сигнал на очистку триґера і цей сигнал очиститься. Але встановлення по АБО "0"
    після встановлення "1" не мало б зняти цей сигнал і ми його маємо зафіксувати до 
    наступної роботи системи захистів (скидання цих сигналів здійснюється перед
    циклом do-while).
    */
    if (_GET_STATE(logic_APV_1, 9)) _SET_BIT(p_active_functions, RNG_BIG_APV1);//_SET_BIT(p_active_functions, RANG_APV1);
    _TIMER_0_T(INDEX_TIMER_APV_BLOCK_VID_APV1, current_settings_prt.timeout_apv_block_vid_apv1[number_group_stp], logic_APV_1, 9, logic_APV_0, 31);

    //АПВ2
    _AND2_INVERTOR(logic_APV_0, 31, logic_APV_0, 15, logic_APV_1, 10);
    _OR6(logic_APV_1, 19, previous_states_APV_0, 9, trigger_APV_0, 0, trigger_APV_0, 2, trigger_APV_0, 3, logic_APV_1,  0, logic_APV_1, 5);
    _OR6(logic_APV_1, 26, logic_APV_0, 24, logic_APV_0, 26, logic_APV_1, 2, logic_APV_1, 1, logic_APV_1, 5, logic_APV_1, 11);
    _OR2(logic_APV_1, 11, logic_APV_3, 5, logic_APV_3, 8);
    _D_TRIGGER(1,  0, _GET_STATE(logic_APV_3, 8), previous_states_APV_0, 6, logic_APV_1, 10, trigger_APV_0, 1);    
    _TIMER_T_0(INDEX_TIMER_APV_2, current_settings_prt.timeout_apv_2[number_group_stp], trigger_APV_0, 1, logic_APV_1, 12);
    /*
    Цей сигнал встановлюмо в масив p_active_functions в циклі з післяумовою
    do-while, бо нас цікавить зафіксувати цей сигнал, а коли він виставиться, то
    піде сигнал на очистку триґера і цей сигнал очиститься. Але встановлення по АБО "0"
    після встановлення "1" не мало б зняти цей сигнал і ми його маємо зафіксувати до 
    наступної роботи системи захистів (скидання цих сигналів здійснюється перед
    циклом do-while).
    */
    if (_GET_STATE(logic_APV_1, 12)) _SET_BIT(p_active_functions, RNG_BIG_APV2);//_SET_BIT(p_active_functions, RANG_APV2);
    _TIMER_0_T(INDEX_TIMER_APV_BLOCK_VID_APV2, current_settings_prt.timeout_apv_block_vid_apv2[number_group_stp], logic_APV_1, 12, logic_APV_1, 0);

    //АПВ3
    _AND2_INVERTOR(logic_APV_1, 0, logic_APV_0, 15, logic_APV_1, 13);
    _OR6(logic_APV_1, 19, previous_states_APV_0, 9, trigger_APV_0, 0, trigger_APV_0, 1, trigger_APV_0, 3, logic_APV_1,  1, logic_APV_1, 6);
    _OR5(logic_APV_1, 26, logic_APV_0, 24, logic_APV_0, 28, logic_APV_1, 2, logic_APV_1, 6, logic_APV_1, 14);
    _OR2(logic_APV_1, 14, logic_APV_3, 5, logic_APV_3, 9);
    _D_TRIGGER(1,  0, _GET_STATE(logic_APV_3, 9), previous_states_APV_0, 7, logic_APV_1, 13, trigger_APV_0, 2);                 
    _TIMER_T_0(INDEX_TIMER_APV_3, current_settings_prt.timeout_apv_3[number_group_stp], trigger_APV_0, 2, logic_APV_1, 15);
    /*
    Цей сигнал встановлюмо в масив p_active_functions в циклі з післяумовою
    do-while, бо нас цікавить зафіксувати цей сигнал, а коли він виставиться, то
    піде сигнал на очистку триґера і цей сигнал очиститься. Але встановлення по АБО "0"
    після встановлення "1" не мало б зняти цей сигнал і ми його маємо зафіксувати до 
    наступної роботи системи захистів (скидання цих сигналів здійснюється перед
    циклом do-while).
    */
    if (_GET_STATE(logic_APV_1, 15)) _SET_BIT(p_active_functions, RNG_BIG_APV3);//_SET_BIT(p_active_functions, RANG_APV3);
    _TIMER_0_T(INDEX_TIMER_APV_BLOCK_VID_APV3, current_settings_prt.timeout_apv_block_vid_apv3[number_group_stp], logic_APV_1, 15, logic_APV_1, 1);

    //АПВ4
    _AND2_INVERTOR(logic_APV_1, 1, logic_APV_0, 15, logic_APV_1, 16);
    _OR6(logic_APV_1, 19, previous_states_APV_0, 9, trigger_APV_0, 0, trigger_APV_0, 1, trigger_APV_0, 2, logic_APV_1,  2, logic_APV_1, 7);
    _OR4(logic_APV_1, 26, logic_APV_0, 24, logic_APV_0, 30, logic_APV_1, 7, logic_APV_1, 17);
    _OR2(logic_APV_1, 17, logic_APV_3, 5, logic_APV_3, 10);
    _D_TRIGGER(1,  0, _GET_STATE(logic_APV_3, 10), previous_states_APV_0, 8, logic_APV_1, 16, trigger_APV_0, 3);                 
    _TIMER_T_0(INDEX_TIMER_APV_4, current_settings_prt.timeout_apv_4[number_group_stp], trigger_APV_0, 3, logic_APV_1, 18);
    /*
    Цей сигнал встановлюмо в масив p_active_functions в циклі з післяумовою
    do-while, бо нас цікавить зафіксувати цей сигнал, а коли він виставиться, то
    піде сигнал на очистку триґера і цей сигнал очиститься. Але встановлення по АБО "0"
    після встановлення "1" не мало б зняти цей сигнал і ми його маємо зафіксувати до 
    наступної роботи системи захистів (скидання цих сигналів здійснюється перед
    циклом do-while).
    */
    if (_GET_STATE(logic_APV_1, 18)) _SET_BIT(p_active_functions, RNG_BIG_APV4);//_SET_BIT(p_active_functions, RANG_APV4);
    _TIMER_0_T(INDEX_TIMER_APV_BLOCK_VID_APV4, current_settings_prt.timeout_apv_block_vid_apv4[number_group_stp], logic_APV_1, 18, logic_APV_1, 2);
  }
  while (
         (_GET_STATE(logic_APV_0, 31) != _GET_STATE(previous_states_APV_0, 1)) ||
         (_GET_STATE(logic_APV_1,  0) != _GET_STATE(previous_states_APV_0, 2)) ||
         (_GET_STATE(logic_APV_1,  1) != _GET_STATE(previous_states_APV_0, 3)) ||
         (_GET_STATE(logic_APV_1,  2) != _GET_STATE(previous_states_APV_0, 4)) ||
         ( trigger_APV_0                     !=  previous_trigger_APV_0                    )  
        );
  
  _Bool work_apv = 0;
  _OR4(trigger_APV_0, 0, trigger_APV_0, 1, trigger_APV_0, 2, trigger_APV_0, 3, work_apv, 0);
  
  //Работа АПВ
  if (work_apv) _SET_BIT(p_active_functions, RNG_BIG_APV_WORK);//!@_SET_BIT(p_active_functions, @RANG_APV_WORK);
  else  _CLEAR_BIT(p_active_functions, RNG_BIG_APV_WORK);//!@_CLEAR_BIT(p_active_functions, @RANG_APV_WORK);
  
}
/*****************************************************/

/*****************************************************/
//Визначення місця до пошкодження
/*****************************************************/
inline void vmp_handler(unsigned int p_active_functions[])
{
  //Перевіряємо чи стоїть фіксуються спрацювання від КЗ на фазних лініях
  if(
     ((p_active_functions[0 ] & MASKA_MONITOTYNG_PHASE_SIGNALES_KZ_0) != 0) ||
     ((p_active_functions[1 ] & MASKA_MONITOTYNG_PHASE_SIGNALES_KZ_1) != 0) ||
     ((p_active_functions[2 ] & MASKA_MONITOTYNG_PHASE_SIGNALES_KZ_2) != 0) || //!@сюди ДЗО
     ((p_active_functions[3 ] & MASKA_MONITOTYNG_PHASE_SIGNALES_KZ_3) != 0) ||
     ((p_active_functions[4 ] & MASKA_MONITOTYNG_PHASE_SIGNALES_KZ_4) != 0) ||
     ((p_active_functions[5 ] & MASKA_MONITOTYNG_PHASE_SIGNALES_KZ_5) != 0) ||
     ((p_active_functions[6 ] & MASKA_MONITOTYNG_PHASE_SIGNALES_KZ_6) != 0) ||
     ((p_active_functions[7 ] & MASKA_MONITOTYNG_PHASE_SIGNALES_KZ_7) != 0) ||
     ((p_active_functions[8 ] & MASKA_MONITOTYNG_PHASE_SIGNALES_KZ_8) != 0) ||
     ((p_active_functions[9 ] & MASKA_MONITOTYNG_PHASE_SIGNALES_KZ_9) != 0) ||
     ((p_active_functions[10] & MASKA_MONITOTYNG_PHASE_SIGNALES_KZ_10) != 0)||
     ((p_active_functions[11] & MASKA_MONITOTYNG_PHASE_SIGNALES_KZ_11) != 0)||
     ((p_active_functions[12] & MASKA_MONITOTYNG_PHASE_SIGNALES_KZ_12) != 0)
    )
  {
    //Є фазне КЗ
    VMP_last_KZ = UNDEF_VMP; /*Помічаємо, що визначення місця до пошкодження ще не визначене*/
    
    //Перевіряємо чи подається команда на вимкнення ВВ ("Робота БО")
    vymknennja_vid_KZ_prt |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_WORK_BO_VVO) != 0);

    int X_resistance = resistance[X_mn];
    if (((unsigned int)X_resistance) != ((unsigned int)UNDEF_RESISTANCE))
    {
      //Є реально розрахований опоір

      //Фіксуємо мінімальний реактивний опір при КЗ
      //Етап 1: Перший визначений опір помічаємо значення як найменше
      unsigned int min_interphase_X = (unsigned int)UNDEF_RESISTANCE;
      int R_KZ_tmp;
      if (((unsigned int)X_resistance) != ((unsigned int)UNDEF_RESISTANCE))
      {
        min_interphase_X = abs(X_resistance);
        R_KZ_tmp = resistance[R_mn];
      }
      else
      {
        //Теоретично цього ніколи не мало б бути
        total_error_sw_fixed();
      }
      
      //Етап 2: Перевіряємо чи мінімальний опір на цей момент не є мінімальним з початку виникнення КЗ
      if (
          (min_interphase_X != ((unsigned int)UNDEF_RESISTANCE))
          &&
          (
           (X_min_KZ_prt == ((unsigned int)UNDEF_RESISTANCE)) || /*Це є ознакою, що для даного КЗ ми перший раз фіксуємо мінімальний опір, тому і його значення помічаємо як мінімальне*/
           (X_min_KZ_prt > min_interphase_X)
          )   
         )
      {
        //Зафіксовано нове значення мінімального міжфазного опору при КЗ
        X_min_KZ_prt = min_interphase_X;
        R_KZ_prt = R_KZ_tmp; //Поки що це число потрібно тільки для визначення знаку (щоб визначити у якому напямку відбулося КЗ)
      }
    }
    else
    {
      X_min_KZ_prt = (unsigned int)UNDEF_RESISTANCE;
    }
  }
  else
  {
    //На даний момент немає КЗ
    if(
       (vymknennja_vid_KZ_prt != 0) &&  /*Умова, що відбувалося вимкнення під час останнього КЗ*/
       ((current_settings_prt.control_vmp & CTR_VMP_STATE) != 0) && /*ВМП увімкнено*/ 
       (X_min_KZ_prt != ((unsigned int)UNDEF_RESISTANCE)) /*Умова, що хоча б один міжфазний опір був визначений, а тому і є зафіксований мінімальний реактивний міжфазний опір*/
      )
    {
      //Визначаємо віддаль до місця пошкодження поки що без напрямку 
      unsigned int X_tmp = X_min_KZ_prt*current_settings_prt.TVoltage/current_settings_prt.Tmn; /*Перерозраховуємо опір на первинну обмотку. Значення залишаємо у мОм*/
      
      unsigned int forward_backward = (R_KZ_prt < 0);
      unsigned int lines_tmp = current_settings_prt.lines[forward_backward];
      unsigned int defined_VMP = false;
      unsigned int i = 0;
      int VMP_tmp = 0;
      while ((defined_VMP == false) && (i < lines_tmp))
      {
        unsigned int dovgyna_tmp = current_settings_prt.dovgyna[forward_backward][i];
        unsigned int opir_tmp = current_settings_prt.opir[forward_backward][i];
        unsigned int X_current_line = dovgyna_tmp*opir_tmp/1000; /*розмірності*[м]x[мОм/км] =  [м]x[мОм/1000м] =[мОм]/1000 */
        if (X_tmp <= X_current_line)
        {
          //На даній ділянці зафіксовано пошкодження
//          VMP_tmp += (int)(((unsigned long long)dovgyna_tmp)*((unsigned long long)X_tmp)/((unsigned long long)X_current_line));
          VMP_tmp += X_tmp*1000/opir_tmp;
          defined_VMP = true;
        }
        else
        {
          //На даній ділянці ще не зафіксовано пошкодження
          VMP_tmp += dovgyna_tmp;
          X_tmp -= X_current_line;
        }
          
        i++;
      }
      
      //Остаточно визначаємо ВМП
      equal_more_KZ = defined_VMP;
      if(forward_backward == 0) VMP_last_KZ = VMP_tmp;
      else VMP_last_KZ = -VMP_tmp;
    }

    /*
    Повертаємо пограмне забезпечення у стан очікування нового КЗ
    
    Цю операцію може б треба було виконувати тільки раз після попереднрього КЗ,
    але оскільки  я не фіксую наявнясть КЗ, а тільки вимкнення при КЗ (короткочасне КЗ
    може не привести до вимкнення, або якщо сигнали працювали на сигналізацію, а не
    на вимкнення) - то щоб не ускладнювати програму, я зробив ці операції постійними коли немає КЗ
    Я думаю, що їх не так багато і вони б не мали сильно знизити ресурс процесора
    */
    vymknennja_vid_KZ_prt = 0;
    X_min_KZ_prt = (unsigned int)UNDEF_RESISTANCE;
    R_KZ_prt = 0;
  }
      
}
/*****************************************************/

/*****************************************************/
//Контроль приводу вимикача
/*****************************************************/
void control_VV(unsigned int *p_active_functions)
{
  unsigned int logic_control_VV_0 = 0;

  //"Контроль Вкл."
  logic_control_VV_0 |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_CTRL_VKL_VVO ) != 0) << 0;
  //"Контроль Откл."
  logic_control_VV_0 |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_CTRL_OTKL_VVO) != 0) << 1;
  
  _XOR_INVERTOR(logic_control_VV_0, 0, logic_control_VV_0, 1, logic_control_VV_0, 2);

  _TIMER_T_0(INDEX_TIMER_PRYVOD_VVO, current_settings_prt.timeout_pryvoda_VV, logic_control_VV_0, 2, logic_control_VV_0, 3);

  //М:"Контроль ВВ"
  logic_control_VV_0 |= ((current_settings_prt.control_switch & CTR_PRYVOD_VV) != 0) << 4;
  
  _AND2(logic_control_VV_0, 3, logic_control_VV_0, 4, logic_control_VV_0, 5);
  
  if (_GET_STATE(logic_control_VV_0, 5))
    _SET_BIT(p_active_functions, RNG_BIG_PRYVID_VVO);
  else
    _CLEAR_BIT(p_active_functions, RNG_BIG_PRYVID_VVO);
}
/*****************************************************/
 /*****************************************************/
//Контроль приводу вимикача
/*****************************************************/
void control_VVR(unsigned int *p_active_functions)
{
  unsigned int logic_control_VVR_0 = 0;

  //"Контроль Вкл."
//
  logic_control_VVR_0 |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_CTRL_VKL_VVR ) != 0) << 0;
  //"Контроль Откл."
//
  logic_control_VVR_0 |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_CTRL_OTKL_VVR) != 0) << 1;
  
  _XOR_INVERTOR(logic_control_VVR_0, 0, logic_control_VVR_0, 1, logic_control_VVR_0, 2);

  _TIMER_T_0(INDEX_TIMER_PRYVOD_VVR, current_settings_prt.timeout_pryvoda_VV, logic_control_VVR_0, 2, logic_control_VVR_0, 3);

  //М:"Контроль ВВ"
  logic_control_VVR_0 |= ((current_settings_prt.control_switch & CTR_PRYVOD_VVR) != 0) << 4;
  
  _AND2(logic_control_VVR_0, 3, logic_control_VVR_0, 4, logic_control_VVR_0, 5);
  
  if (_GET_STATE(logic_control_VVR_0, 5))
    _SET_BIT(p_active_functions, RNG_BIG_PRYVID_VVR);//!@RANG_PRYVID_VV
  else
    _CLEAR_BIT(p_active_functions, RNG_BIG_PRYVID_VVR);//!@RANG_PRYVID_VV
}
/*****************************************************/
/*****************************************************/
//Розрахунок коефіцієнтрів для підрахунку ресурсу вимикача
/*****************************************************/
void make_koef_for_resurs(void)
{
  float tmp_1, tmp_2;
  
  tmp_1 = (float)current_settings.setpoint_r_kom_st_Inom/(float)current_settings.setpoint_r_kom_st_Inom_vymk;
  tmp_1  = log10f(tmp_1);

  tmp_2 = (float)current_settings.setpoint_Inom_vymk/(float)current_settings.setpoint_Inom;
  tmp_2  = log10f(tmp_2);
  
  //Помічаємо, що коефіцієнти для розрахунку ресурсу вимикача зараз будуть змінені
  koef_resurs_changed = CHANGED_ETAP_EXECUTION;

  K_resurs = tmp_1/tmp_2;
  
  //Помічаємо, що коефіцієнти для розрахунку ресурсу вимикача змінені і чекають на прийом системою захистів
  koef_resurs_changed = CHANGED_ETAP_ENDED;
}
/*****************************************************/

/*****************************************************/
//Лічильник ресурсу
/*****************************************************/
inline void resurs_vymykacha_handler(unsigned int *p_active_functions)
{
  static unsigned int previous_active_functions[N_BIG];
  
  if (restart_counter != 0)
  {
    //Треба подати команду очистки ресурсу вимикача
    resurs_vymykacha = current_settings_prt.setpoint_pochatkovyj_resurs;
    resurs_vidkljuchennja = current_settings_prt.setpoint_pochatkova_k_vymk;
    
     restart_counter = 0;

    //Запускаємо запис у EEPROM
    _SET_BIT(control_spi1_taskes, TASK_START_WRITE_RESURS_EEPROM_BIT);

    //Помічаємо, що відбулася очистка ресурсу вимикача
    information_about_restart_counter |= ((1 << USB_RECUEST)|(1 << RS485_RECUEST));
  }
  
  /*******************************/
  //Визначаємо максимальний фазовий струм під час роботи Блоку Вимкнення (БО)
  /*******************************/
  static unsigned int max_faze_current_vv;
//!  @if (_CHECK_SET_BIT(p_active_functions, @RANG_WORK_BO) != 0)
  if (_CHECK_SET_BIT(p_active_functions, RNG_BIG_WORK_BO_VVO) != 0)
  {
    unsigned int max_faze_current_tmp = measurement[IM_Imn];
    if (max_faze_current_tmp < measurement[IM_Ibp]) max_faze_current_tmp = measurement[IM_Ibp];
    max_faze_current_tmp = max_faze_current_tmp*current_settings_prt.Tmn/1000;
  
//!    @if (_CHECK_SET_BIT(previous_active_functions, @RANG_WORK_BO) == 0)
    if (_CHECK_SET_BIT(previous_active_functions, RNG_BIG_WORK_BO_VVO) == 0)
    {
      //Зафіксовано старт роботи БО
      max_faze_current_vv = max_faze_current_tmp;
    }
    else if (_CHECK_SET_BIT(previous_active_functions, RNG_BIG_WORK_BO_VVO) != 0)//!@RANG_WORK_BO
    {
      //БО продовжує свою роботу
      if (max_faze_current_vv < max_faze_current_tmp) max_faze_current_vv = max_faze_current_tmp;
    }
    
    if (max_faze_current_vv > current_settings_prt.setpoint_Inom_vymk) 
    {
      _SET_BIT(p_active_functions, RNG_BIG_PEREVYSHCHENNJA_I_NOM_VYMK);//!@RANG_PEREVYSHCHENNJA_Inom_VYMK
    }
    else
    {
      _CLEAR_BIT(p_active_functions, RNG_BIG_PEREVYSHCHENNJA_I_NOM_VYMK);//!@RANG_PEREVYSHCHENNJA_Inom_VYMK
    }
  }
  /*******************************/
  
  if (
      ((current_settings_prt.control_switch & CTR_RESURS_VV) != 0) &&
      (_CHECK_SET_BIT(previous_active_functions, RNG_BIG_WORK_BO_VVO) != 0) &&  //!@(_CHECK_SET_BIT(previous_active_functions, @RANG_WORK_BO) != 0)
      (_CHECK_SET_BIT(p_active_functions , RNG_BIG_WORK_BO_VVO) == 0)           //!@(_CHECK_SET_BIT(p_active_functions , @RANG_WORK_BO) == 0)      
     ) 
  {
    //Зафіксовано завершення "Робота БО"
    
    /*******************************/
    //Обчислюється ресурс вимикачa
    /*******************************/
    unsigned int N = 0;
    if (max_faze_current_vv >= current_settings_prt.setpoint_Inom_vymk) {
      N = (unsigned int) ceilf((float)current_settings_prt.setpoint_r_kom_st_Inom/(float)current_settings_prt.setpoint_r_kom_st_Inom_vymk);
    } else if (max_faze_current_vv <= current_settings_prt.setpoint_Inom) {
      N = 1;
    } else {
      float I_div_Inom = (float)max_faze_current_vv / (float)current_settings_prt.setpoint_Inom;
      float lg_I_div_Inom = log10f(I_div_Inom);
      float lg_N = K_resurs_prt * lg_I_div_Inom;
      float N_ = powf(10, lg_N);
      N = (unsigned int) ceilf(N_);
      if ((((float)N) - N_) >= 0.5f)
      {
        N--;
      }
      
    }
    
    if (resurs_vymykacha <= N) {
      resurs_vymykacha = 0;
    } else {
      resurs_vymykacha -= N;
    }
    
    //Загальне число переключень
    if ((0xffffffff - resurs_vidkljuchennja) >= 1)
    {
      //Додавання одиниці не викличе переповнення
      resurs_vidkljuchennja++;
    }

    //Запускаємо запис у EEPROM
    _SET_BIT(control_spi1_taskes, TASK_START_WRITE_RESURS_EEPROM_BIT);
  }
  
  if (resurs_vymykacha <= current_settings_prt.setpoint_krytychnyj_resurs) 
  {
    _SET_BIT(p_active_functions, RNG_BIG_KRYTYCHNYJ_RESURS_VVO);//!@RANG_KRYTYCHNYJ_RESURS_VYMYKACHA
  }
  else
  {
    _CLEAR_BIT(p_active_functions, RNG_BIG_KRYTYCHNYJ_RESURS_VVO);//!@RANG_KRYTYCHNYJ_RESURS_VYMYKACHA
  }

  if (resurs_vymykacha == 0) 
  {
    _SET_BIT(p_active_functions, RNG_BIG_VYCHERPANYJ_RESURS_VVO);//!@RANG_VYCHERPANYJ_RESURS_VYMYKACHA
  }
  else
  {
    _CLEAR_BIT(p_active_functions, RNG_BIG_VYCHERPANYJ_RESURS_VVO);//!@RANG_VYCHERPANYJ_RESURS_VYMYKACHA
  }
 

  /*********************/
  //Формуємо попереденій стан сигналів для функції увімкнення/вимкнення
  /*********************/
  for (unsigned int i = 0; i < N_BIG; i++) previous_active_functions[i] = p_active_functions[i];
  /*********************/
}
/*****************************************************/

/*****************************************************/
//Перевірка на необхідність завершення роботи аналогового/дискретного реєстраторів
/*****************************************************/
inline unsigned int stop_regisrator(unsigned int* carrent_active_functions, unsigned int* ranguvannja_registrator)
{
  if (global_timers[INDEX_TIMER_DR_WORK] < 0) global_timers[INDEX_TIMER_DR_WORK] = DELTA_TIME_FOR_TIMERS; /*вже, к мінімум з моменту запуску ДР процшло стільки мілісекунд*/
    
  int flag = 0;
  for(size_t m = 0; m < N_BIG; ++m) 
  {
    if((carrent_active_functions[m] & ranguvannja_registrator[m]) != 0) 
    {
      flag = (1u << 0);
      break;
    }
  }
  _TIMER_0_T(INDEX_TIMER_DR_WORK, current_settings_prt.timeout_prolongation_work_digital_registrator + DELTA_TIME_FOR_TIMERS, flag, 0, flag, 1);
  
  return (flag == 0);
}
/*****************************************************/

/*****************************************************/
//Зафіксована невизначена помилка роботи дискретного реєстратора
/*****************************************************/
void fix_undefined_error_dr(unsigned int* carrent_active_functions)
{
  //Виставляємо помилку з записом в дисретний реєстратор
  _SET_BIT(set_diagnostyka, ERROR_DR_UNDEFINED_BIT);
  _SET_BIT(carrent_active_functions, RNG_BIG_DEFECT);
  //Переводимо режим роботи з реєстратором у сатн "На даний момент ніких дій з дискретним реєстратором не виконується" 
  state_dr_record = STATE_DR_NO_RECORD;
  //Скидаєсо сигнал роботи дискретного реєстратора
  _CLEAR_BIT(carrent_active_functions, RNG_BIG_WORK_D_REJESTRATOR);
}
/*****************************************************/

/*****************************************************/
//Подача команди почати запис у DataFalsh
/*****************************************************/
inline void command_start_saving_record_dr_into_dataflash(void)
{
  //У структурі по інформації стану реєстраторів виставляємо повідомлення, що почався запис і ще не закінчився
  _SET_BIT(control_spi1_taskes, TASK_START_WRITE_INFO_REJESTRATOR_DR_EEPROM_BIT);
  info_rejestrator_dr.saving_execution = 1;
        
  //Виставляємо першу частину запису
  part_writing_dr_into_dataflash = 0;
  //Виставляємо команду запису у мікросхему DataFlash
  control_tasks_dataflash |= TASK_MAMORY_PAGE_PROGRAM_THROUGH_BUFFER_DATAFLASH_FOR_DR;
}
/*****************************************************/

/*****************************************************/
//Функція обробки черги зформованих записів дискретного реєстратора
/*****************************************************/
inline void routine_for_queue_dr(void)
{
  if(
     (state_dr_record == STATE_DR_MAKE_RECORD)            || /*Стоїть умова сформовані дані передати на запис у DataFlsh без повторного початку  нового запису, бо умова завершення запиу    досягнкта, а не стояла умова примусового завершення даного сформованого запису*/
     (state_dr_record == STATE_DR_CUT_RECORD)             || /*Стоїть умова сформовані дані передати на запис у DataFlsh   з повторним  початком нового запису, бо умова завершення запиу не досягнкта, а    стояла умова примусового завершення даного сформованого запису*/
     (number_records_dr_waiting_for_saving_operation != 0)  
    )
  {
    if ((control_tasks_dataflash & TASK_MAMORY_PAGE_PROGRAM_THROUGH_BUFFER_DATAFLASH_FOR_DR) == 0)
    {
      //На даний момент запису у Datafalsh не проводиться
      unsigned char *buffer_source, *buffer_target;
        
      if (number_records_dr_waiting_for_saving_operation == 0)
      {
        buffer_target = buffer_for_save_dr_record_level_2;
        buffer_source = buffer_for_save_dr_record;
        for(unsigned int i = 0; i < SIZE_BUFFER_FOR_DR_RECORD; i++)
        {
          *(buffer_target + i) = *(buffer_source + i);
          *(buffer_source + i) = 0xff;
        }
        number_records_dr_waiting_for_saving_operation = 0;
      }
      else if (number_records_dr_waiting_for_saving_operation == 1)
      {
        buffer_target = buffer_for_save_dr_record_level_2;
        buffer_source = buffer_for_save_dr_record_level_1;
        for(unsigned int i = 0; i < SIZE_BUFFER_FOR_DR_RECORD; i++) *(buffer_target +i ) = *(buffer_source + i);
        
        if((state_dr_record == STATE_DR_MAKE_RECORD) || (state_dr_record == STATE_DR_CUT_RECORD))
        {
          buffer_target = buffer_for_save_dr_record_level_1;
          buffer_source = buffer_for_save_dr_record;
          for(unsigned int i = 0; i < SIZE_BUFFER_FOR_DR_RECORD; i++) 
          {
            *(buffer_target + i) = *(buffer_source + i);
            *(buffer_source + i) = 0xff;
          }
          number_records_dr_waiting_for_saving_operation = 1;
        }
        else number_records_dr_waiting_for_saving_operation = 0;
      }
      else
      {
        buffer_target = buffer_for_save_dr_record_level_2;
        buffer_source = buffer_for_save_dr_record_level_1;
        for(unsigned int i = 0; i < SIZE_BUFFER_FOR_DR_RECORD; i++) *(buffer_target + i) = *(buffer_source + i);
        buffer_target = buffer_for_save_dr_record_level_1;
        buffer_source = buffer_for_save_dr_record;
        for(unsigned int i = 0; i < SIZE_BUFFER_FOR_DR_RECORD; i++) 
        {
          *(buffer_target + i) = *(buffer_source + i);
          *(buffer_source + i) = 0xff;
        }
        number_records_dr_waiting_for_saving_operation = 1;
      }
        
      //Подаємо команду почати запис у DataFalsh
      command_start_saving_record_dr_into_dataflash();
    }
    else
    {
      //На даний момент запису у Datafalsh проводиться
      //Треба наш теперішній запис поставити у чергу
      if (number_records_dr_waiting_for_saving_operation == 0)
      {
        //На даний момент крім того, буфера - з якого іде безпосередній запис у DataFalsh, більше ніяких записів у черзі немає
        //Переміщаємо текучий запис у буфер buffer_for_save_dr_record_level_1
        for(unsigned int i = 0; i < SIZE_BUFFER_FOR_DR_RECORD; i++) 
        {
          buffer_for_save_dr_record_level_1[i] = buffer_for_save_dr_record[i];
          buffer_for_save_dr_record[i] = 0xff;
        }
    
        //Помічаємо, що один запис очікує передау його на безпосередній запис у dataFalsh
        number_records_dr_waiting_for_saving_operation = 1;
      }
      else if (number_records_dr_waiting_for_saving_operation >= 1)
      {
         if((state_dr_record == STATE_DR_MAKE_RECORD) || (state_dr_record == STATE_DR_CUT_RECORD))
         {
          //На даний момент крім того, буфера - з якого іде безпосередній запис у DataFalsh, ще один сформований запис стоїть у буфері buffer_for_save_dr_record_level_1
          /*
          Тому даний запис залишаємо у цьому самому буфері buffer_for_save_dr_record, але збільшуємо кількість записів. які стоять у черзі
          і якщо буде спроба почати новий запис, то будемо фіксувати помилку втрати даних
          */
          number_records_dr_waiting_for_saving_operation = 2;
         }
      }
    }
    
    if (state_dr_record == STATE_DR_MAKE_RECORD)
    {
      //Помічаємо, що ми готові приймати наступний запис
      state_dr_record = STATE_DR_NO_RECORD;
    }
    else if (state_dr_record == STATE_DR_CUT_RECORD)
    {
      //Помічаємо, що треба примусово запустити новий запис
      state_dr_record = STATE_DR_FORCE_START_NEW_RECORD;
    }
      
  }
}
/*****************************************************/

/*****************************************************/
//Копіювання вимірювань у вказаний масив для ДР
/*****************************************************/
inline void copy_meas_for_dr(unsigned int * const arr)
{
    __meas_to_d_meas const * p_link = im_to_idm;
  for(size_t i = 0; i <_SIZE_ARRAY_FIX_MAX_MEASUREMENTS_TMP; ++i)
  {
		if (i < IDM_F)
		{
    	arr[i] = *((unsigned int const *)p_link->arr + p_link->ind);
		}
		else if (i == IDM_F)
		{
	  	float const frequency_tmp = *((float const *)p_link->arr + p_link->ind);
			arr[IDM_F] = (frequency_tmp >= 0) ? (int)roundf(frequency_tmp*1000.0f) : (int)frequency_tmp;
		}
		else
		{
    	arr[i] = *((int const *)p_link->arr + p_link->ind);
		}
		
		++p_link;
  }
}
/*****************************************************/

/*****************************************************/
//Початок моніторингу максимального фазного струму оснвної лінії 
/*****************************************************/
inline void start_monitoring_max_phase_o_current(unsigned int time_tmp)
{
  //Збільшуємо кількість фіксованих значень максимального фазного струму оснвної лінії
  ++number_max_phase_o_dr;
  
  //Помічаємо, що будем виходити з того, що зараз значення тільки починають моніторитися, тому приймаємо їх за найбільші
	copy_meas_for_dr(measurements_phase_o_max_dr);
  measurements_phase_o_max_dr[IDM_VMP] = (unsigned int)UNDEF_VMP;
  measurements_phase_o_max_dr[IDM_VMP_EQUAL_MORE] = 0;
  
  
  //Фіксуємо час з моменту початку аварійного запису
  measurements_phase_o_max_dr[IDM_TM_STAMPE] = time_tmp;

  //Помічаємо, що ми на стадії моніторингу максимального фазного струму оснвної лінії
  state_current_monitoring |= (1<<IDENTIFIER_BIT_ARRAY_MAX_CURRENT_PHASE_O);
}
/*****************************************************/

/*****************************************************/
//Продовження моніторингу максимального фазного струму оснвної лінії
/*****************************************************/
inline void continue_monitoring_max_phase_o_current(unsigned int time_tmp)
{
  //Перевірка, чи не є зарза досліджуваний струм основної лінії більший, ніж той що помічено максимальним
  if (measurements_phase_o_max_dr[IDM_Imn] < measurement[IM_Imn])
  {
    //Зафіксовано зріз при найбільшому досліджуваніому струмі основної лінії з моменту початку спостереження за ним
		copy_meas_for_dr(measurements_phase_o_max_dr);

    //Фіксуємо час з моменту початку аварійного запису
    measurements_phase_o_max_dr[IDM_TM_STAMPE] = time_tmp;
  }
}
/*****************************************************/

/*****************************************************/
//Початок моніторингу максимального фазного струму резервної лінії 
/*****************************************************/
inline void start_monitoring_max_phase_r_current(unsigned int time_tmp)
{
  //Збільшуємо кількість фіксованих значень максимального фазного струму резервної лінії
  ++number_max_phase_r_dr;
  
  //Помічаємо, що будем виходити з того, що зараз значення тільки починають моніторитися, тому приймаємо їх за найбільші
	copy_meas_for_dr(measurements_phase_r_max_dr);
  measurements_phase_r_max_dr[IDM_VMP] = (unsigned int)UNDEF_VMP;
  measurements_phase_r_max_dr[IDM_VMP_EQUAL_MORE] = 0;
  
  
  //Фіксуємо час з моменту початку аварійного запису
  measurements_phase_r_max_dr[IDM_TM_STAMPE] = time_tmp;

  //Помічаємо, що ми на стадії моніторингу максимального фазного струму резервної лінії
  state_current_monitoring |= (1<<IDENTIFIER_BIT_ARRAY_MAX_CURRENT_PHASE_R);
}
/*****************************************************/

/*****************************************************/
//Продовження моніторингу максимального фазного струму резервної лінії
/*****************************************************/
inline void continue_monitoring_max_phase_r_current(unsigned int time_tmp)
{
  //Перевірка, чи не є зарза досліджуваний струм резервної лінії більший, ніж той що помічено максимальним
  if (measurements_phase_r_max_dr[IDM_Ibp] < measurement[IM_Ibp])
  {
    //Зафіксовано зріз при найбільшому досліджуваніому струмі резервної лінії з моменту початку спостереження за ним
		copy_meas_for_dr(measurements_phase_r_max_dr);

    //Фіксуємо час з моменту початку аварійного запису
    measurements_phase_r_max_dr[IDM_TM_STAMPE] = time_tmp;
  }
}
/*****************************************************/

/*****************************************************/
//Початок моніторингу мінімальної лінійної напругии основного каналу 
/*****************************************************/
inline void start_monitoring_min_U(unsigned int time_tmp)
{
  //Збільшуємо кількість фіксованих значень мінімальної напруги
  number_min_U_dr++;
  
  //Помічаємо, що будем виходити з того, що зараз значення тільки починають моніторитися, тому приймаємо їх за найменші
	copy_meas_for_dr(measurements_U_min_dr);
  measurements_U_min_dr[IDM_VMP] = (unsigned int)UNDEF_VMP;
  measurements_U_min_dr[IDM_VMP_EQUAL_MORE] = 0;
  
  
  //Фіксуємо час з моменту початку аварійного запису
  measurements_U_min_dr[IDM_TM_STAMPE] = time_tmp;

  //Помічаємо, що ми на стадії моніторингу мінімальної лінійної напруги
  state_current_monitoring |= (1<<IDENTIFIER_BIT_ARRAY_MIN_VOLTAGE);
}
/*****************************************************/

/*****************************************************/
//Продовження моніторингу мінімальної лінійної напругии основного каналу
/*****************************************************/
inline void continue_monitoring_min_U(unsigned int time_tmp)
{
  //Перевірка, чи не є зарза досліджувана напуга менша, ніж та що помічена мінімальною
  if (measurements_U_min_dr[IDM_Umn] > measurement[IM_Umn])
  {
    //Зафіксовано зріз при найнижчій досліджуваній напрузі з моменту початку спостереження за нею
		copy_meas_for_dr(measurements_U_min_dr);

    //Фіксуємо час з моменту початку аварійного запису
    measurements_U_min_dr[IDM_TM_STAMPE] = time_tmp;
  }
}
/*****************************************************/

/*****************************************************/
//Початок моніторингу максимальної лінійної напруги основного каналу
/*****************************************************/
inline void start_monitoring_max_U(unsigned int time_tmp)
{
  //Збільшуємо кількість фіксованих значень максимальної лінійної напруги основного каналу
  ++number_max_U_dr;
  
  //Помічаємо, що будем виходити з того, що зараз значення тільки починають моніторитися, тому приймаємо їх за найбільші
	copy_meas_for_dr(measurements_U_max_dr);
  measurements_U_max_dr[IDM_VMP] = (unsigned int)UNDEF_VMP;
  measurements_U_max_dr[IDM_VMP_EQUAL_MORE] = 0;
  
  //Фіксуємо час з моменту початку аварійного запису
  measurements_U_max_dr[IDM_TM_STAMPE] = time_tmp;

  //Помічаємо, що ми на стадії моніторингу максимальної лінійної напруги
  state_current_monitoring |= (1<<IDENTIFIER_BIT_ARRAY_MAX_VOLTAGE);
}
/*****************************************************/

/*****************************************************/
//Продовження моніторингу максимальної лінійної напруги
/*****************************************************/
inline void continue_monitoring_max_U(unsigned int time_tmp)
{
  //Перевірка, чи не є зарза досліджувана напуга більша, ніж та що помічена максимальною
  if (measurements_U_max_dr[IDM_Umn] < measurement[IM_Umn])
  {
    //Зафіксовано зріз при найвищійу досліджуваній напрузі з моменту початку спостереження за нею
		copy_meas_for_dr(measurements_U_max_dr);

    //Фіксуємо час з моменту початку аварійного запису
    measurements_U_max_dr[IDM_TM_STAMPE] = time_tmp;
  }
}
/*****************************************************/

/*****************************************************/
//Початок моніторингу мінімального опору оснвної лінії 
/*****************************************************/
inline void start_monitoring_min_r_o_current(unsigned int time_tmp)
{
  //Збільшуємо кількість фіксованих значень мінімального опору оснвної лінії
  ++number_min_r_o_dr;
  
  //Помічаємо, що будем виходити з того, що зараз значення тільки починають моніторитися, тому приймаємо їх за найменші
	copy_meas_for_dr(measurements_r_o_min_dr);
  measurements_r_o_min_dr[IDM_VMP] = (unsigned int)UNDEF_VMP;
  measurements_r_o_min_dr[IDM_VMP_EQUAL_MORE] = 0;
  
  //Фіксуємо час з моменту початку аварійного запису
  measurements_r_o_min_dr[IDM_TM_STAMPE] = time_tmp;

  //Помічаємо, що ми на стадії моніторингу мінімального опору оснвної лінії
  state_current_monitoring |= (1<<IDENTIFIER_BIT_ARRAY_MIN_R_O);
}
/*****************************************************/

/*****************************************************/
//Продовження моніторингу мінімального опору оснвної лінії
/*****************************************************/
inline void continue_monitoring_min_r_o_current(unsigned int time_tmp)
{
  //Перевірка, чи не є зарза досліджуваний опір основної лінії менший, ніж той що помічено мінімальним
  if (measurements_U_min_dr[IDM_Z_mn] > (unsigned int)resistance[Z_mn])
  {
    //Зафіксовано зріз при найменшому досліджуваніому опорі основної лінії з моменту початку спостереження за ним
		copy_meas_for_dr(measurements_r_o_min_dr);

    //Фіксуємо час з моменту початку аварійного запису
    measurements_r_o_min_dr[IDM_TM_STAMPE] = time_tmp;
  }
}
/*****************************************************/

/*****************************************************/
//Початок моніторингу мінімального опору резервної лінії 
/*****************************************************/
inline void start_monitoring_min_r_r_current(unsigned int time_tmp)
{
  //Збільшуємо кількість фіксованих значень мінімального опору резервної лінії
  ++number_min_r_r_dr;
  
  //Помічаємо, що будем виходити з того, що зараз значення тільки починають моніторитися, тому приймаємо їх за найменші
	copy_meas_for_dr(measurements_r_r_min_dr);
  measurements_r_r_min_dr[IDM_VMP] = (unsigned int)UNDEF_VMP;
  measurements_r_r_min_dr[IDM_VMP_EQUAL_MORE] = 0;
  
  //Фіксуємо час з моменту початку аварійного запису
  measurements_r_r_min_dr[IDM_TM_STAMPE] = time_tmp;

  //Помічаємо, що ми на стадії моніторингу мінімального опору резервної лінії
  state_current_monitoring |= (1<<IDENTIFIER_BIT_ARRAY_MIN_R_R);
}
/*****************************************************/

/*****************************************************/
//Продовження моніторингу мінімального опору резервної лінії
/*****************************************************/
inline void continue_monitoring_min_r_r_current(unsigned int time_tmp)
{
  //Перевірка, чи не є зарза досліджуваний опір резервної лінії менший, ніж той що помічено мінімальним
  if (measurements_U_min_dr[IDM_Z_bp] > (unsigned int)resistance[Z_bp])
  {
    //Зафіксовано зріз при найменшому досліджуваніому опорі резервної лінії з моменту початку спостереження за ним
		copy_meas_for_dr(measurements_r_r_min_dr);

    //Фіксуємо час з моменту початку аварійного запису
    measurements_r_r_min_dr[IDM_TM_STAMPE] = time_tmp;
  }
}
/*****************************************************/

/*****************************************************/
//Початок моніторингу мінімальної частоти
/*****************************************************/
inline void start_monitoring_min_f(unsigned int time_tmp)
{
  //Збільшуємо кількість фіксованих значень мінімальної частоти
  ++number_min_f_achr_dr;
  
  //Помічаємо, що будем виходити з того, що зараз значення тільки починають моніторитися, тому приймаємо їх за найменші
	copy_meas_for_dr(measurements_f_min_achr_dr);
  
  //Фіксуємо час з моменту початку аварійного запису
  measurements_f_min_achr_dr[IDM_TM_STAMPE] = time_tmp;

  //Помічаємо, що ми на стадії моніторингу мінімальної частоти
  state_current_monitoring |= (1<<IDENTIFIER_BIT_ARRAY_MIN_FREQUENCY_ACHR);
}
/*****************************************************/

/*****************************************************/
//Продовження моніторингу мінімальної частоти
/*****************************************************/
inline void continue_monitoring_min_f(unsigned int time_tmp)
{
  if (((int)measurements_f_min_achr_dr[IDM_F]) != (-2)) /*Не зафіксовано, що частота була нижче порогу визначеного константою MIN_FREQUENCY - інакше далі моніторити мінімальну частоту немає сенсу*/
  {
    //Перевірка, чи не є зарза досліджувана частота менша, ніж та що помічена мінімальною
		int const frequency_int_tmp = (frequency >= 0) ? (int)(roundf(frequency*1000.0f)) : (int)(frequency);
  
    if(
       (frequency_int_tmp != (-1)) && /*Частота не визначена*/
       (frequency_int_tmp != (-3)) &&  /*Частота вище порогу визначеного константою MAX_FREQUENCY*/
       (
        (((int)measurements_f_min_achr_dr[IDM_F]) > frequency_int_tmp) ||
        (frequency_int_tmp == (-2)) /*Частота нижче порогу визначеного константою MIN_FREQUENCY - цю перевірку робимо, бо у попередній момент часу могло крім значення частоти бути ще числа -1 або -3*/
       )   
      )   
    {
      //Зафіксовано зріз при найнижчій досліджуваній частоті з моменту початку спостереження за нею
			copy_meas_for_dr(measurements_f_min_achr_dr);

      //Фіксуємо час з моменту початку аварійного запису
      measurements_f_min_achr_dr[IDM_TM_STAMPE] = time_tmp;
    }
  }
}
/*****************************************************/
/*****************************************************/
//Завершення моніторингу максимальних/мінімальих значень
/*****************************************************/
inline void end_monitoring_min_max_measurement(unsigned int type_current, unsigned int* carrent_active_functions)
{
  if(
     (type_current == IDENTIFIER_BIT_ARRAY_MAX_CURRENT_PHASE_O) ||
     (type_current == IDENTIFIER_BIT_ARRAY_MAX_CURRENT_PHASE_R) ||
     (type_current == IDENTIFIER_BIT_ARRAY_MIN_VOLTAGE        ) ||
     (type_current == IDENTIFIER_BIT_ARRAY_MAX_VOLTAGE        ) ||
     (type_current == IDENTIFIER_BIT_ARRAY_MIN_R_O            ) ||
     (type_current == IDENTIFIER_BIT_ARRAY_MIN_R_R            ) ||
     (type_current == IDENTIFIER_BIT_ARRAY_MIN_FREQUENCY_ACHR ) ||
     (type_current == IDENTIFIER_BIT_ARRAY_FREQUENCY_CHAPV    )
    )
  {

    int step = number_max_phase_o_dr + 
               number_max_phase_r_dr +
               number_min_U_dr       +
               number_max_U_dr       +
               number_min_r_o_dr     +
               number_min_r_r_dr     +
               number_min_f_achr_dr  +
               number_f_chapv_dr;
    
    //Перевірка на коректність роботи програмного забеспечення
    if(
       ( (number_max_phase_o_dr > 0) || ( (number_max_phase_o_dr == 0) && ((state_current_monitoring & (1<< IDENTIFIER_BIT_ARRAY_MAX_CURRENT_PHASE_O )) == 0) ) ) &&
       ( (number_max_phase_r_dr > 0) || ( (number_max_phase_r_dr == 0) && ((state_current_monitoring & (1<< IDENTIFIER_BIT_ARRAY_MAX_CURRENT_PHASE_R )) == 0) ) ) &&
       ( (number_min_U_dr       > 0) || ( (number_min_U_dr       == 0) && ((state_current_monitoring & (1<< IDENTIFIER_BIT_ARRAY_MIN_VOLTAGE         )) == 0) ) ) &&
       ( (number_max_U_dr       > 0) || ( (number_max_U_dr       == 0) && ((state_current_monitoring & (1<< IDENTIFIER_BIT_ARRAY_MAX_VOLTAGE         )) == 0) ) ) &&
       ( (number_min_r_o_dr     > 0) || ( (number_min_r_o_dr     == 0) && ((state_current_monitoring & (1<< IDENTIFIER_BIT_ARRAY_MIN_R_O             )) == 0) ) ) &&
       ( (number_min_r_r_dr     > 0) || ( (number_min_r_r_dr     == 0) && ((state_current_monitoring & (1<< IDENTIFIER_BIT_ARRAY_MIN_R_R             )) == 0) ) ) &&
       ( (number_min_f_achr_dr  > 0) || ( (number_min_f_achr_dr  == 0) && ((state_current_monitoring & (1<< IDENTIFIER_BIT_ARRAY_MIN_FREQUENCY_ACHR  )) == 0) ) ) &&
       ( (number_f_chapv_dr     > 0) || ( (number_f_chapv_dr     == 0) && ((state_current_monitoring & (1<< IDENTIFIER_BIT_ARRAY_FREQUENCY_CHAPV     )) == 0) ) ) &&
       ( (step > 0) && (step <= MAX_NUMBER_FIX_MAX_MEASUREMENTS)) 
      )
    {
      unsigned char *input_data_point = NULL, *output_data_point;
      
      //Визначаємо джерело звідки  будемо копіювати дані
      if(type_current == IDENTIFIER_BIT_ARRAY_MAX_CURRENT_PHASE_O)
      {
        measurements_phase_o_max_dr[IDM_VMP] = (unsigned int)VMP_last_KZ;
        measurements_phase_o_max_dr[IDM_VMP_EQUAL_MORE] = equal_more_KZ;
        input_data_point = (unsigned char *)(measurements_phase_o_max_dr);

        //Скидємо це визначення, щоб воно не попало при іншому процесі, поки воно не буде наново розраховане
        VMP_last_KZ = UNDEF_VMP;
        equal_more_KZ = 0;
      }
      else if(type_current == IDENTIFIER_BIT_ARRAY_MAX_CURRENT_PHASE_R)
      {
        input_data_point = (unsigned char *)(measurements_phase_r_max_dr);
      }
      else if(type_current == IDENTIFIER_BIT_ARRAY_MIN_VOLTAGE)
      {
        input_data_point = (unsigned char *)(measurements_U_min_dr);
      }
      else if(type_current == IDENTIFIER_BIT_ARRAY_MAX_VOLTAGE)
      {
        input_data_point = (unsigned char *)(measurements_U_max_dr);
      }
      else if(type_current == IDENTIFIER_BIT_ARRAY_MIN_R_O)
      {
        input_data_point = (unsigned char *)(measurements_r_o_min_dr);
      }
      else if(type_current == IDENTIFIER_BIT_ARRAY_MIN_R_R)
      {
        input_data_point = (unsigned char *)(measurements_r_r_min_dr);
      }
      else if(type_current == IDENTIFIER_BIT_ARRAY_MIN_FREQUENCY_ACHR)
      {
        input_data_point = (unsigned char *)(measurements_f_min_achr_dr);
      }
      else if(type_current == IDENTIFIER_BIT_ARRAY_FREQUENCY_CHAPV)
      {
        input_data_point = (unsigned char *)(measurements_f_chapv_dr);
      }
      
      //Визначаємо адресу киди дані треба копіювати
      step -= 1; //Тому що  нумерація починається з 0, а не з 1 (step гарантовано не менше 1(це перевірено вище), тому від'ємного числа не може бути)
      if(((state_current_monitoring & (1<< IDENTIFIER_BIT_ARRAY_MAX_CURRENT_PHASE_O )) != 0) && (type_current != IDENTIFIER_BIT_ARRAY_MAX_CURRENT_PHASE_O))
        step -= 1;
      if(((state_current_monitoring & (1<< IDENTIFIER_BIT_ARRAY_MAX_CURRENT_PHASE_R )) != 0) && (type_current != IDENTIFIER_BIT_ARRAY_MAX_CURRENT_PHASE_R))
        step -= 1;
      if(((state_current_monitoring & (1<< IDENTIFIER_BIT_ARRAY_MIN_VOLTAGE         )) != 0) && (type_current != IDENTIFIER_BIT_ARRAY_MIN_VOLTAGE        ))
        step -= 1;
      if(((state_current_monitoring & (1<< IDENTIFIER_BIT_ARRAY_MAX_VOLTAGE         )) != 0) && (type_current != IDENTIFIER_BIT_ARRAY_MAX_VOLTAGE        ))
        step -= 1;
      if(((state_current_monitoring & (1<< IDENTIFIER_BIT_ARRAY_MIN_R_O             )) != 0) && (type_current != IDENTIFIER_BIT_ARRAY_MIN_R_O            ))
        step -= 1;
      if(((state_current_monitoring & (1<< IDENTIFIER_BIT_ARRAY_MIN_R_R             )) != 0) && (type_current != IDENTIFIER_BIT_ARRAY_MIN_R_R            ))
        step -= 1;
      if(((state_current_monitoring & (1<< IDENTIFIER_BIT_ARRAY_MIN_FREQUENCY_ACHR  )) != 0) && (type_current != IDENTIFIER_BIT_ARRAY_MIN_FREQUENCY_ACHR ))
        step -= 1;
      if(((state_current_monitoring & (1<< IDENTIFIER_BIT_ARRAY_FREQUENCY_CHAPV     )) != 0) && (type_current != IDENTIFIER_BIT_ARRAY_FREQUENCY_CHAPV    ))
        step -= 1;
      
      if(step >= 0)
      {
        output_data_point = (buffer_for_save_dr_record + FIRST_INDEX_FIRST_BLOCK_DR +step*sizeof(unsigned int)*SIZE_ARRAY_FIX_MAX_MEASUREMENTS);
        
        for(unsigned int i = 0; i < (sizeof(unsigned int)*SIZE_ARRAY_FIX_MAX_MEASUREMENTS); i++)
        {
          if(i != (sizeof(unsigned int)*SIZE_ARRAY_FIX_MAX_MEASUREMENTS - 1))
          {
            *(output_data_point + i) = *(input_data_point + i);
          }
          else
          {
            //У останній байт масиву, що відповідає згідно з Little-endian формату старшову байту останнього елементу масиву, мітку типу струму, по якому фіксувався максимальний струм
            *(output_data_point + i) = type_current;
          }
        }

        //Знімаємо помітку, що ми на стадії моніторингу 
        state_current_monitoring &= ~(1<<type_current);
      }
      else
      {
        //Відбулася незрозуміла ситуація - сюди програма теоретично ніколи не мала б заходити
        fix_undefined_error_dr(carrent_active_functions);
      }
    }
    else
    {
      //Відбулася незрозуміла ситуація - сюди програма теоретично ніколи не мала б заходити
      fix_undefined_error_dr(carrent_active_functions);
    }
  }
  else
  {
    //Відбулася незрозуміла ситуація - сюди програма теоретично ніколи не мала б заходити
    fix_undefined_error_dr(carrent_active_functions);
  }
}
/*****************************************************/


/*****************************************************/
//Функція обробки логіки дискретного реєстратора
/*****************************************************/
inline void digital_registrator(unsigned int* carrent_active_functions)
{
  /***
  Стан оперативного живлення від якого залежить як Дискретний реєстратор буде працювати
  ***/
  enum _statePowerDown
  {
    STATE_POWER_DOWN_NONE = 0,
    STATE_POWER_DOWN_ETAP_BEFORE,
    STATE_POWER_DOWN_ETAP_CUT,
    STATE_POWER_DOWN_ETAP_CUT_CONFIRMED,
    STATE_POWER_DOWN_ETAP_AFTER
  };
  
  static enum _statePowerDown statePowerDown;
  if (((POWER_CTRL->IDR & POWER_CTRL_PIN) != (uint32_t)Bit_RESET)) statePowerDown = STATE_POWER_DOWN_NONE;
  else
  {
    if (timePowerDown < POWER_DOWN_TIME) statePowerDown = STATE_POWER_DOWN_ETAP_BEFORE;
    else
    {
      if (statePowerDown == STATE_POWER_DOWN_ETAP_BEFORE) statePowerDown = STATE_POWER_DOWN_ETAP_CUT;
      else if (statePowerDown == STATE_POWER_DOWN_ETAP_CUT_CONFIRMED) statePowerDown = STATE_POWER_DOWN_ETAP_AFTER;
    }
  }
  /***/
 

  static unsigned int previous_active_functions[N_BIG];
  
  static unsigned int number_items_dr;
  static unsigned int number_changes_into_dr_record;
  static unsigned int time_from_start_record_dr;
  static unsigned int blocking_continue_monitoring_min_U;
  
// DigRegUniqVarsAddreses  drUniqVarsAddreses = {
//	&number_items_dr,
//	&number_changes_into_dr_record,
//	&time_from_start_record_dr,
//	&blocking_continue_monitoring_min_U,
//	previous_active_functions,
//	carrent_active_functions
//};
  
  
//  TestStateNameSpaceFooBrrr((DigRegUniqVarsAddreses*)&drUniqVarsAddreses);
  //put_before_info_in_buf
  //CmdPlusTimeStampLogHundler(active_functions);
  static unsigned int const monitoring_phase_o_signals[N_BIG] =
  {
    MASKA_MONITOTYNG_PHASE_O_SIGNALES_0,
    MASKA_MONITOTYNG_PHASE_O_SIGNALES_1,
    MASKA_MONITOTYNG_PHASE_O_SIGNALES_2,
    MASKA_MONITOTYNG_PHASE_O_SIGNALES_3,
    MASKA_MONITOTYNG_PHASE_O_SIGNALES_4,
    MASKA_MONITOTYNG_PHASE_O_SIGNALES_5,
    MASKA_MONITOTYNG_PHASE_O_SIGNALES_6,
    MASKA_MONITOTYNG_PHASE_O_SIGNALES_7,
		MASKA_MONITOTYNG_PHASE_O_SIGNALES_8,
		MASKA_MONITOTYNG_PHASE_O_SIGNALES_9,
		MASKA_MONITOTYNG_PHASE_O_SIGNALES_10,
		MASKA_MONITOTYNG_PHASE_O_SIGNALES_11,
    MASKA_MONITOTYNG_PHASE_O_SIGNALES_12
  };
  static unsigned int const monitoring_phase_r_signals[N_BIG] =
  {
    MASKA_MONITOTYNG_PHASE_R_SIGNALES_0,
    MASKA_MONITOTYNG_PHASE_R_SIGNALES_1,
    MASKA_MONITOTYNG_PHASE_R_SIGNALES_2,
    MASKA_MONITOTYNG_PHASE_R_SIGNALES_3,
    MASKA_MONITOTYNG_PHASE_R_SIGNALES_4,
    MASKA_MONITOTYNG_PHASE_R_SIGNALES_5,
    MASKA_MONITOTYNG_PHASE_R_SIGNALES_6,
    MASKA_MONITOTYNG_PHASE_R_SIGNALES_7,
		MASKA_MONITOTYNG_PHASE_R_SIGNALES_8,
		MASKA_MONITOTYNG_PHASE_R_SIGNALES_9,
		MASKA_MONITOTYNG_PHASE_R_SIGNALES_10,
		MASKA_MONITOTYNG_PHASE_R_SIGNALES_11,
    MASKA_MONITOTYNG_PHASE_R_SIGNALES_12
  };
  static unsigned int const monitoring_Umin_signals[N_BIG] =
  {
    MASKA_MONITOTYNG_UMIN_SIGNALES_0,
    MASKA_MONITOTYNG_UMIN_SIGNALES_1,
    MASKA_MONITOTYNG_UMIN_SIGNALES_2,
    MASKA_MONITOTYNG_UMIN_SIGNALES_3,
    MASKA_MONITOTYNG_UMIN_SIGNALES_4,
    MASKA_MONITOTYNG_UMIN_SIGNALES_5,
    MASKA_MONITOTYNG_UMIN_SIGNALES_6,
    MASKA_MONITOTYNG_UMIN_SIGNALES_7,
		MASKA_MONITOTYNG_UMIN_SIGNALES_8,
		MASKA_MONITOTYNG_UMIN_SIGNALES_9,
		MASKA_MONITOTYNG_UMIN_SIGNALES_10,
		MASKA_MONITOTYNG_UMIN_SIGNALES_11,
    MASKA_MONITOTYNG_UMIN_SIGNALES_12
  };
  static unsigned int const monitoring_Umax_signals[N_BIG] =
  {
    MASKA_MONITOTYNG_UMAX_SIGNALES_0,
    MASKA_MONITOTYNG_UMAX_SIGNALES_1,
    MASKA_MONITOTYNG_UMAX_SIGNALES_2,
    MASKA_MONITOTYNG_UMAX_SIGNALES_3,
    MASKA_MONITOTYNG_UMAX_SIGNALES_4,
    MASKA_MONITOTYNG_UMAX_SIGNALES_5,
    MASKA_MONITOTYNG_UMAX_SIGNALES_6,
    MASKA_MONITOTYNG_UMAX_SIGNALES_7,
		MASKA_MONITOTYNG_UMAX_SIGNALES_8,
    MASKA_MONITOTYNG_UMAX_SIGNALES_9,
    MASKA_MONITOTYNG_UMAX_SIGNALES_10,
    MASKA_MONITOTYNG_UMAX_SIGNALES_11,
    MASKA_MONITOTYNG_UMAX_SIGNALES_12
  };
  static unsigned int const monitoring_r_o_signals[N_BIG] =
  {
    MASKA_MONITOTYNG_R_O_SIGNALES_0,
    MASKA_MONITOTYNG_R_O_SIGNALES_1,
    MASKA_MONITOTYNG_R_O_SIGNALES_2,
    MASKA_MONITOTYNG_R_O_SIGNALES_3,
    MASKA_MONITOTYNG_R_O_SIGNALES_4,
    MASKA_MONITOTYNG_R_O_SIGNALES_5,
    MASKA_MONITOTYNG_R_O_SIGNALES_6,
    MASKA_MONITOTYNG_R_O_SIGNALES_7,
		MASKA_MONITOTYNG_R_O_SIGNALES_8,
		MASKA_MONITOTYNG_R_O_SIGNALES_9,
		MASKA_MONITOTYNG_R_O_SIGNALES_10,
		MASKA_MONITOTYNG_R_O_SIGNALES_11,
    MASKA_MONITOTYNG_R_O_SIGNALES_12
  };
  static unsigned int const monitoring_r_r_signals[N_BIG] =
  {
    MASKA_MONITOTYNG_R_R_SIGNALES_0,
    MASKA_MONITOTYNG_R_R_SIGNALES_1,
    MASKA_MONITOTYNG_R_R_SIGNALES_2,
    MASKA_MONITOTYNG_R_R_SIGNALES_3,
    MASKA_MONITOTYNG_R_R_SIGNALES_4,
    MASKA_MONITOTYNG_R_R_SIGNALES_5,
    MASKA_MONITOTYNG_R_R_SIGNALES_6,
    MASKA_MONITOTYNG_R_R_SIGNALES_7,
		MASKA_MONITOTYNG_R_R_SIGNALES_8,
		MASKA_MONITOTYNG_R_R_SIGNALES_9,
		MASKA_MONITOTYNG_R_R_SIGNALES_10,
		MASKA_MONITOTYNG_R_R_SIGNALES_11,
    MASKA_MONITOTYNG_R_R_SIGNALES_12
  };
  static unsigned int const monitoring_f_min_achr_signals[N_BIG] =
  {
    MASKA_MONITOTYNG_F_MIN_ACHR_SIGNALES_0,
    MASKA_MONITOTYNG_F_MIN_ACHR_SIGNALES_1,
    MASKA_MONITOTYNG_F_MIN_ACHR_SIGNALES_2,
    MASKA_MONITOTYNG_F_MIN_ACHR_SIGNALES_3,
    MASKA_MONITOTYNG_F_MIN_ACHR_SIGNALES_4,
    MASKA_MONITOTYNG_F_MIN_ACHR_SIGNALES_5,
    MASKA_MONITOTYNG_F_MIN_ACHR_SIGNALES_6,
    MASKA_MONITOTYNG_F_MIN_ACHR_SIGNALES_7,
		MASKA_MONITOTYNG_F_MIN_ACHR_SIGNALES_8
      
#ifdef MASKA_MONITOTYNG_F_MIN_ACHR_SIGNALES_9
                                          ,
    MASKA_MONITOTYNG_F_MIN_ACHR_SIGNALES_9
#endif
  };
  
  //Цю перевірку виконуємо тільки у тому випадку, коли іде процес формування нового запису
  if(state_dr_record == STATE_DR_EXECUTING_RECORD)
  {
    //Перевіряємо чи не виникла умова, що зарараз буде перебір фіксації максимальних струмів
    unsigned int temp_value_for_max_min_fix_measurement = (
                                                            number_max_phase_o_dr + 
                                                            number_max_phase_r_dr + 
                                                            number_min_U_dr       +
                                                            number_max_U_dr       +
                                                            number_min_r_o_dr     + 
                                                            number_min_r_r_dr     + 
                                                            number_min_f_achr_dr  +
                                                            number_f_chapv_dr    
                                                      );
    if(temp_value_for_max_min_fix_measurement > MAX_NUMBER_FIX_MAX_MEASUREMENTS)
    {
      //Сюди, теоретично програма нікол не мала б заходити, але якщо зайшла, тоиреба перервати роботу дискретного реєстратора
      fix_undefined_error_dr(carrent_active_functions);

      /*
      Скидаємо сигнал роботи дискретного реєстратора у масиві попередніх активних функцій
      Це ми робимо для того, щоб у першому записі нового запису було зафіксовано активацію роботу дискретного реєстратора
      */
      _CLEAR_BIT(previous_active_functions, RNG_BIG_WORK_D_REJESTRATOR);
    }
    else
    {
      //Перевіряємо чи стоїть умова почати моніторити максимальний фазний струм основного каналу
      unsigned int comp = false;
      COMPARE_NOT_ZERO_OR(comp, carrent_active_functions, monitoring_phase_o_signals, N_BIG)
      if(comp)
      {
        if((state_current_monitoring & (1<<IDENTIFIER_BIT_ARRAY_MAX_CURRENT_PHASE_O)) == 0)
        {
          //Є умова почати новий моніторинг максимального фазного струму основного каналу
          temp_value_for_max_min_fix_measurement++;
        }
      }

      //Перевіряємо чи стоїть умова почати моніторити максимальний фазний струм резервного каналу
      COMPARE_NOT_ZERO_OR(comp, carrent_active_functions, monitoring_phase_r_signals, N_BIG)
      if(comp)
      {
        if((state_current_monitoring & (1<<IDENTIFIER_BIT_ARRAY_MAX_CURRENT_PHASE_R)) == 0)
        {
          //Є умова почати новий моніторинг максимального фазного струму резервного каналу
          temp_value_for_max_min_fix_measurement++;
        }
      }
      
      //Перевіряємо чи стоїть умова почати моніторити мінімальну напругу
      if (
          (blocking_continue_monitoring_min_U == 0) ||
          (_CHECK_SET_BIT(carrent_active_functions, RNG_BIG_WORK_BV_VVO) != 0)  
         )
      {
        COMPARE_NOT_ZERO_OR(comp, carrent_active_functions, monitoring_Umin_signals, N_BIG)
        if(comp)
        {
          if((state_current_monitoring & (1<<IDENTIFIER_BIT_ARRAY_MIN_VOLTAGE)) == 0)
          {
            //Є умова почати новий моніторинг мінімальну фазну напругу
            temp_value_for_max_min_fix_measurement++;
          }
        }
      }
      
      //Перевіряємо чи стоїть умова почати моніторити максимальну напругу
      COMPARE_NOT_ZERO_OR(comp, carrent_active_functions, monitoring_Umax_signals, N_BIG)
      if(comp)
      {
        if((state_current_monitoring & (1<<IDENTIFIER_BIT_ARRAY_MAX_VOLTAGE)) == 0)
        {
          //Є умова почати новий моніторинг максимальну фазну напругу
          temp_value_for_max_min_fix_measurement++;
        }
      }
      
      //Перевіряємо чи стоїть умова почати моніторити мінімального опору основного каналу
      COMPARE_NOT_ZERO_OR(comp, carrent_active_functions, monitoring_r_o_signals, N_BIG)
      if(comp)
      {
        if((state_current_monitoring & (1<<IDENTIFIER_BIT_ARRAY_MIN_R_O)) == 0)
        {
          //Є умова почати новий моніторинг мінімального опору основного каналу
          temp_value_for_max_min_fix_measurement++;
        }
      }
      
      //Перевіряємо чи стоїть умова почати моніторити мінімального опору резервного каналу
      COMPARE_NOT_ZERO_OR(comp, carrent_active_functions, monitoring_r_r_signals, N_BIG)
      if(comp)
      {
        if((state_current_monitoring & (1<<IDENTIFIER_BIT_ARRAY_MIN_R_R)) == 0)
        {
          //Є умова почати новий моніторинг мінімального опору резервного каналу
          temp_value_for_max_min_fix_measurement++;
        }
      }
    
      //Перевіряємо чи стоїть умова почати моніторити мінімальну частоту для АЧР
      COMPARE_NOT_ZERO_OR(comp, carrent_active_functions, monitoring_f_min_achr_signals, N_BIG)
      if(comp)
      {
        if((state_current_monitoring & (1<<IDENTIFIER_BIT_ARRAY_MIN_FREQUENCY_ACHR)) == 0)
        {
          //Є умова почати новий моніторинг мінімальну частоту
          temp_value_for_max_min_fix_measurement++;
        }
      }
      
      
      if (
          /*Є умова дозволу подачі команди ЧАПВ*/
          (_CHECK_SET_BIT(carrent_active_functions , RNG_BIG_VN_BLOCK_CHAPV) == 0)
          &&
          (
           (
            /*Умова зафіксувати частоту для зовнішнього ЧАПВ*/
            (_CHECK_SET_BIT(previous_active_functions, RNG_BIG_ACHR_CHAPV_VID_DV) != 0) &&
            (_CHECK_SET_BIT(carrent_active_functions , RNG_BIG_ACHR_CHAPV_VID_DV) == 0)
           )
           ||
           (
            /*Умова зафіксувати частоту від внутрішнього ЧАПВ*/
            (_CHECK_SET_BIT(carrent_active_functions , RNG_BIG_RAZR_CHAPV) != 0) 
            &&
            (
             (  
              (_CHECK_SET_BIT(previous_active_functions, RNG_BIG_ACHR_CHAPV1  ) != 0) &&
              (_CHECK_SET_BIT(carrent_active_functions , RNG_BIG_ACHR_CHAPV1  ) == 0)
             )   
             ||  
             (  
              (_CHECK_SET_BIT(previous_active_functions, RNG_BIG_ACHR_CHAPV2  ) != 0) &&
              (_CHECK_SET_BIT(carrent_active_functions , RNG_BIG_ACHR_CHAPV2  ) == 0)
             )   
            )           
           ) 
          )
         )   
      {
        //Є умова зафіксувати частоту від ЧАПВ
        temp_value_for_max_min_fix_measurement++;
      }
          
      
      if(temp_value_for_max_min_fix_measurement > MAX_NUMBER_FIX_MAX_MEASUREMENTS)
      {
        //Виникла ситуація, що зарараз буде перебір фіксації максимальних вимірювань
        //Треба примусово завершити текучий запис і почати наступний запис

        buffer_for_save_dr_record[FIRST_INDEX_NUMBER_ITEMS_DR      ] = number_items_dr;
        buffer_for_save_dr_record[FIRST_INDEX_NUMBER_CHANGES_DR    ] = number_changes_into_dr_record        & 0xff;
        buffer_for_save_dr_record[FIRST_INDEX_NUMBER_CHANGES_DR + 1] = (number_changes_into_dr_record >> 8) & 0xff;

        //Перевіряємо чи треба завершити моніторинг максимального фазного струму основного каналу
        if((state_current_monitoring & (1<<IDENTIFIER_BIT_ARRAY_MAX_CURRENT_PHASE_O)) != 0)
          end_monitoring_min_max_measurement(IDENTIFIER_BIT_ARRAY_MAX_CURRENT_PHASE_O, carrent_active_functions);

        //Перевіряємо чи треба завершити моніторинг максимального фазного струму резервного каналу
        if((state_current_monitoring & (1<<IDENTIFIER_BIT_ARRAY_MAX_CURRENT_PHASE_R)) != 0)
          end_monitoring_min_max_measurement(IDENTIFIER_BIT_ARRAY_MAX_CURRENT_PHASE_R, carrent_active_functions);

        //Перевіряємо чи треба завершити моніторинг мінімальної напруги
        if((state_current_monitoring & (1<<IDENTIFIER_BIT_ARRAY_MIN_VOLTAGE)) != 0)
          end_monitoring_min_max_measurement(IDENTIFIER_BIT_ARRAY_MIN_VOLTAGE, carrent_active_functions);

        //Перевіряємо чи треба завершити моніторинг максимальної напруги
        if((state_current_monitoring & (1<<IDENTIFIER_BIT_ARRAY_MAX_VOLTAGE)) != 0)
          end_monitoring_min_max_measurement(IDENTIFIER_BIT_ARRAY_MAX_VOLTAGE, carrent_active_functions);

        //Перевіряємо чи треба завершити моніторинг мінімального опору основного каналу
        if((state_current_monitoring & (1<<IDENTIFIER_BIT_ARRAY_MIN_R_O)) != 0)
          end_monitoring_min_max_measurement(IDENTIFIER_BIT_ARRAY_MIN_R_O, carrent_active_functions);

        //Перевіряємо чи треба завершити моніторинг мінімального опору резервного каналу
        if((state_current_monitoring & (1<<IDENTIFIER_BIT_ARRAY_MIN_R_R)) != 0)
          end_monitoring_min_max_measurement(IDENTIFIER_BIT_ARRAY_MIN_R_R, carrent_active_functions);
        
        //Перевіряємо чи треба завершити моніторинг мінімальної частоти для АЧР
        if((state_current_monitoring & (1<<IDENTIFIER_BIT_ARRAY_MIN_FREQUENCY_ACHR)) != 0)
          end_monitoring_min_max_measurement(IDENTIFIER_BIT_ARRAY_MIN_FREQUENCY_ACHR, carrent_active_functions);
        
        /*
        Ми не первіряємо чи треба завершити моніторинг фіксації частоти для ЧАПВ,
        бо коли фіксується ця частота, то зразу моніторинг припиняється (ми не
        шукаємо мінімальну чи максимальну частоту - а фікчуємо частоту при запуску АПВ
        від ЧАПВ)
        */

        //Дальші дії виконуємо тіьлки у тому випадку, якщо функція end_monitoring_min_max_measurement не зафіксувала помилку і не скинула state_dr_record у STATE_DR_NO_RECORD
        if(state_dr_record != STATE_DR_NO_RECORD)
        {
          //Записуємо кількість зафіксованих максимальних струмів всіх типів
          buffer_for_save_dr_record[FIRST_INDEX_NUMBER_MAX_PHASE_O_DR] = number_max_phase_o_dr;
          buffer_for_save_dr_record[FIRST_INDEX_NUMBER_MAX_PHASE_R_DR] = number_max_phase_r_dr;
          buffer_for_save_dr_record[FIRST_INDEX_NUMBER_MIN_U_DR      ] = number_min_U_dr;
          buffer_for_save_dr_record[FIRST_INDEX_NUMBER_MAX_U_DR      ] = number_max_U_dr;
          buffer_for_save_dr_record[FIRST_INDEX_NUMBER_MIN_R_O_DR    ] = number_min_r_o_dr;
          buffer_for_save_dr_record[FIRST_INDEX_NUMBER_MIN_R_R_DR    ] = number_min_r_r_dr;
          buffer_for_save_dr_record[FIRST_INDEX_NUMBER_MIN_F_ACHR_DR ] = number_min_f_achr_dr;
          buffer_for_save_dr_record[FIRST_INDEX_NUMBER_F_CHAPV_DR    ] = number_f_chapv_dr;

          //Помічаємо, що треба при першій же нагоді почати новий запис, бо попередній запис був примусово зупинений
          state_dr_record = STATE_DR_CUT_RECORD;
        
          //Скидаємо сигнал роботи дискретного реєстратора
          _CLEAR_BIT(carrent_active_functions, RNG_BIG_WORK_D_REJESTRATOR);
        
          //Сформований запис ставим в чергу для запису
          routine_for_queue_dr();
        }
        /*
        Скидаємо сигнал роботи дискретного реєстратора у масиві попередніх активних функцій
        Це ми робимо для того, щоб у першому записі нового запису було зафіксовано активацію роботу дискретного реєстратора
        */
        _CLEAR_BIT(previous_active_functions, RNG_BIG_WORK_D_REJESTRATOR);
        
      }
    }
  }
  
  switch (state_dr_record)
  {
  case STATE_DR_NO_RECORD:
  case STATE_DR_FORCE_START_NEW_RECORD:
    {
      //Попередньо скидаємо невизначену помилку  роботи дискретного реєстратора
      _SET_BIT(clear_diagnostyka, ERROR_DR_UNDEFINED_BIT);
      if(number_records_dr_waiting_for_saving_operation < (WIGHT_OF_DR_WAITING - 1))
      {
        //Ця ситуація означає, що як мінімум на один новий запис у нас є вільне місц, тому скидаємо сигналізацію про втрату даних
        _SET_BIT(clear_diagnostyka, ERROR_DR_TEMPORARY_BUSY_BIT);
      }
      
      //На початок аналізу покищо ще дискретний реєстратор не запущений
      
      //Аналізуємо, чи стоїть умова запуску дискретного реєстратора
      unsigned int cur_active_sources[N_BIG];
      for (size_t i = 0; i != N_BIG; ++i) 
      {
        cur_active_sources[i] = carrent_active_functions[i] & current_settings_prt.ranguvannja_digital_registrator[i];
      }
      unsigned int comp = false;
      NOT_ZERO_OR(comp, cur_active_sources, N_BIG)
      if (
          (comp) ||
          (state_dr_record == STATE_DR_FORCE_START_NEW_RECORD)
         )
      {
        //Є умова запуску дискретного реєстратора
        //global_timers[INDEX_TIMER_DR_WORK] = 0;//_TIMER_0_T(INDEX_TIMER_DR_WORK,current_settings_prt.timeout_prolongation_work_digital_registrator,1,1,0,0);
        //Перевіряємо, чи при початку нового запису ми не втратимо попередню інформацію
        if(number_records_dr_waiting_for_saving_operation < WIGHT_OF_DR_WAITING)
        {
          //Можна починати новий запис
          //.asm volatile(
          //.     "bkpt 1"
          //.     );
          //Переводимо режим роботи із дискретним реєстратором у стан "Іде процес запису реєстратора"
          state_dr_record = STATE_DR_EXECUTING_RECORD;
          //Виставляємо активну функцію
          _SET_BIT(carrent_active_functions, RNG_BIG_WORK_D_REJESTRATOR);
        
          //Записуємо мітку початку запису
          buffer_for_save_dr_record[FIRST_INDEX_START_START_RECORD_DR] = LABEL_START_RECORD_DR;
         
          //Записуємо час початку запису
          drDateTimeState = (realDateTime != 0) ? AVAT_DATE_TIMR_FIX_LEVEL2 : AVAR_DATE_TIME_NONE;

          for(size_t i = 0; i < sizeof(time_t); i++)  buffer_for_save_dr_record[FIRST_INDEX_DATA_TIME_DR + i] = *((unsigned char*)(&time_dat) + i);
          for(size_t i = 0; i < sizeof(int32_t); i++)  buffer_for_save_dr_record[FIRST_INDEX_DATA_TIME_DR + sizeof(time_t) + i] = *((unsigned char*)(&time_ms) + i);
          
           //І'мя комірки
          for(unsigned int i=0; i< MAX_CHAR_IN_NAME_OF_CELL; i++) 
            buffer_for_save_dr_record[FIRST_INDEX_NAME_OF_CELL_DR + i] = current_settings_prt.name_of_cell[i] & 0xff;
          
          //Коефіцієнти трансформації
          {
            unsigned char *ptr_target = buffer_for_save_dr_record + FIRST_INDEX_TC_O;
            unsigned char *ptr_source = (unsigned char *)(&current_settings_prt.Tmn);
            for(size_t i = 0; i < sizeof(current_settings_prt.Tmn); ++i) 
              *ptr_target++ = *ptr_source++;

            ptr_target = buffer_for_save_dr_record + FIRST_INDEX_TC_R;
            ptr_source = (unsigned char *)(&current_settings_prt.Tmn);
            for(size_t i = 0; i < sizeof(current_settings_prt.Tmn); ++i) 
              *ptr_target++ = *ptr_source++;

            ptr_target = buffer_for_save_dr_record + FIRST_INDEX_TV;
            ptr_source = (unsigned char *)(&current_settings_prt.TVoltage);
            for(size_t i = 0; i < sizeof(current_settings_prt.TVoltage); ++i) 
              *ptr_target++ = *ptr_source++;
          }
          

           //Джерела запуску
          for(unsigned int i = 0; i < NUMBER_BYTES_SAMPLE_DR; i++) 
            buffer_for_save_dr_record[FIRST_INDEX_SOURCE_DR + i] = *(((unsigned char*)cur_active_sources) + i);

//          put_before_info_in_buf_from_queue(&drUniqVarsAddreses);
          //put_before_info_in_buf(&drUniqVarsAddreses);FillBeforeBufinDirectOrder(&drUniqVarsAddreses);
          //Скидаємо кількість фіксацій максимальних струмів/напруг
          number_max_phase_o_dr = 0;
          number_max_phase_r_dr = 0;
          number_min_U_dr = 0;
          number_max_U_dr = 0;
          number_min_r_o_dr = 0;
          number_min_r_r_dr = 0;
          number_min_f_achr_dr = 0;
          number_f_chapv_dr = 0;
          
          //Знімаємо повідомлення про моніторинг максимальних струмів
          state_current_monitoring = 0;
          
          //Перевіряємо чи стоїть умова моніторити максимальний фазний струм основного каналу
          COMPARE_NOT_ZERO_OR(comp, carrent_active_functions, monitoring_phase_o_signals, N_BIG)
          if(comp)
          {
            start_monitoring_max_phase_o_current(time_from_start_record_dr);
          }

          //Перевіряємо чи стоїть умова моніторити максимальний фазний струм резервного каналу
          COMPARE_NOT_ZERO_OR(comp, carrent_active_functions, monitoring_phase_r_signals, N_BIG)
          if(comp)
          {
            start_monitoring_max_phase_r_current(time_from_start_record_dr);
          }

          //Знімаємо блокування моніторингу мінімальної напруги
          blocking_continue_monitoring_min_U = 0;
          //Перевіряємо чи стоїть умова моніторити мінімальну напругу
          COMPARE_NOT_ZERO_OR(comp, carrent_active_functions, monitoring_Umin_signals, N_BIG)
          if(comp)
          {
            start_monitoring_min_U(time_from_start_record_dr);
          }
          //Перевіряємо, чи стоїть умова припинити моніторинг мінімальної напруги після вимкнення вимикача
          if((state_current_monitoring & (1<<IDENTIFIER_BIT_ARRAY_MIN_VOLTAGE)) != 0)
          {
            if (_CHECK_SET_BIT(carrent_active_functions, RNG_BIG_WORK_BO_VVO) != 0)
            {
              blocking_continue_monitoring_min_U = 0xff;
              end_monitoring_min_max_measurement(IDENTIFIER_BIT_ARRAY_MIN_VOLTAGE, carrent_active_functions);
            }
          }

          //Перевіряємо чи стоїть умова моніторити максимальну напругу
          COMPARE_NOT_ZERO_OR(comp, carrent_active_functions, monitoring_Umax_signals, N_BIG)
          if(comp)
          {
            start_monitoring_max_U(time_from_start_record_dr);
          }

          //Перевіряємо чи стоїть умова моніторити мінімального опору основного каналу
          COMPARE_NOT_ZERO_OR(comp, carrent_active_functions, monitoring_r_o_signals, N_BIG)
          if(comp)
          {
            start_monitoring_min_r_o_current(time_from_start_record_dr);
          }

          //Перевіряємо чи стоїть умова моніторити мінімального опору резервного каналу
          COMPARE_NOT_ZERO_OR(comp, carrent_active_functions, monitoring_r_r_signals, N_BIG)
          if(comp)
          {
            start_monitoring_min_r_r_current(time_from_start_record_dr);
          }
      
          //Перевіряємо чи стоїть умова моніторити мінімальну частоту
          COMPARE_NOT_ZERO_OR(comp, carrent_active_functions, monitoring_f_min_achr_signals, N_BIG)
          if(comp)
          {
            start_monitoring_min_f(time_from_start_record_dr);
          }

          /*
          Перевірку необхідності запису фіксації вимірювань при роботі ЧАПВ здійснювати
          не потрібно, тому що ми тільки запустили дискретний реєстратор, а умова запису
          вимірювань при запуску ЧАПВ складається з двох зрізів у яких сигнал ЧАПВ
          здійснює перехід "Активний"->"Пасивний"
          */
        }
        else
        {
          //Виставляємо помилку, що є умова на роботу дискретного реєстратора тоді, як всі вільні буфери зайняті
          _SET_BIT(set_diagnostyka, ERROR_DR_TEMPORARY_BUSY_BIT);
          _SET_BIT(carrent_active_functions, RNG_BIG_DEFECT);
        }
      }
      else state_dr_record = STATE_DR_NO_RECORD;
      
      break;
    }
  case STATE_DR_EXECUTING_RECORD:
    {
      if (
          (drDateTimeState == AVAR_DATE_TIME_NONE) &&
          (realDateTime != 0)  
         )
      {
        drDateTimeState = AVAT_DATE_TIMR_FIX_LEVEL2;
        for(size_t i = 0; i < sizeof(time_t); i++)  buffer_for_save_dr_record[FIRST_INDEX_DATA_TIME_DR + i] = *((unsigned char*)(&time_dat) + i);
        for(size_t i = 0; i < sizeof(int32_t); i++)  buffer_for_save_dr_record[FIRST_INDEX_DATA_TIME_DR + sizeof(time_t) + i] = *((unsigned char*)(&time_ms) + i);
      }

      //Збільшуємо час з початку запуску запису
      time_from_start_record_dr += DELTA_TIME_FOR_TIMERS;

      //Включно до цього часу іде процес запису

      //Контроль-фіксація максимальних аналогових сигналів
      
      //Перевіряємо чи стоїть умова моніторити максимальний фазний струм основного каналу
      unsigned int comp = false;
      COMPARE_NOT_ZERO_OR(comp, carrent_active_functions, monitoring_phase_o_signals, N_BIG)
      if(comp)
      {
        if((state_current_monitoring & (1<<IDENTIFIER_BIT_ARRAY_MAX_CURRENT_PHASE_O)) != 0)
          continue_monitoring_max_phase_o_current(time_from_start_record_dr);
        else
          start_monitoring_max_phase_o_current(time_from_start_record_dr);
      }
      else
      {
        if((state_current_monitoring & (1<<IDENTIFIER_BIT_ARRAY_MAX_CURRENT_PHASE_O)) != 0)
          end_monitoring_min_max_measurement(IDENTIFIER_BIT_ARRAY_MAX_CURRENT_PHASE_O, carrent_active_functions);
      }

      //Перевіряємо чи стоїть умова моніторити максимальний фазний струм резервного каналу
      COMPARE_NOT_ZERO_OR(comp, carrent_active_functions, monitoring_phase_r_signals, N_BIG)
      if(comp)
      {
        if((state_current_monitoring & (1<<IDENTIFIER_BIT_ARRAY_MAX_CURRENT_PHASE_R)) != 0)
          continue_monitoring_max_phase_r_current(time_from_start_record_dr);
        else
          start_monitoring_max_phase_r_current(time_from_start_record_dr);
      }
      else
      {
        if((state_current_monitoring & (1<<IDENTIFIER_BIT_ARRAY_MAX_CURRENT_PHASE_R)) != 0)
          end_monitoring_min_max_measurement(IDENTIFIER_BIT_ARRAY_MAX_CURRENT_PHASE_R, carrent_active_functions);
      }

      //Перевіряємо чи стоїть умова відновити моніторинг мінімальної напруги
      if (_CHECK_SET_BIT(carrent_active_functions, RNG_BIG_WORK_BV_VVO) != 0)
      {
        //Знімаємо блокування моніторингу мінімальної напруги
        blocking_continue_monitoring_min_U = 0;
      }
      //Перевіряємо чи стоїть умова моніторити мінімальну напругу
      if (blocking_continue_monitoring_min_U == 0)
      {
        COMPARE_NOT_ZERO_OR(comp, carrent_active_functions, monitoring_Umin_signals, N_BIG)
        if(comp)
        {
          if((state_current_monitoring & (1<<IDENTIFIER_BIT_ARRAY_MIN_VOLTAGE)) != 0)
            continue_monitoring_min_U(time_from_start_record_dr);
          else
            start_monitoring_min_U(time_from_start_record_dr);
        }
        else
        {
          if((state_current_monitoring & (1<<IDENTIFIER_BIT_ARRAY_MIN_VOLTAGE)) != 0)
            end_monitoring_min_max_measurement(IDENTIFIER_BIT_ARRAY_MIN_VOLTAGE, carrent_active_functions);
        }
      }
      //Перевіряємо, чи стоїть умова припинити моніторинг мінімальної напруги після вимкнення вимикача
      if((state_current_monitoring & (1<<IDENTIFIER_BIT_ARRAY_MIN_VOLTAGE)) != 0)
      {
        if (_CHECK_SET_BIT(carrent_active_functions, RNG_BIG_WORK_BO_VVO) != 0)
        {
          blocking_continue_monitoring_min_U = 0xff;
          end_monitoring_min_max_measurement(IDENTIFIER_BIT_ARRAY_MIN_VOLTAGE, carrent_active_functions);
        }
      }
      
      //Перевіряємо чи стоїть умова моніторити максимальну напругу
      COMPARE_NOT_ZERO_OR(comp, carrent_active_functions, monitoring_Umax_signals, N_BIG)
      if(comp)
      {
        if((state_current_monitoring & (1<<IDENTIFIER_BIT_ARRAY_MAX_VOLTAGE)) != 0)
          continue_monitoring_max_U(time_from_start_record_dr);
        else
          start_monitoring_max_U(time_from_start_record_dr);
      }
      else
      {
        if((state_current_monitoring & (1<<IDENTIFIER_BIT_ARRAY_MAX_VOLTAGE)) != 0)
          end_monitoring_min_max_measurement(IDENTIFIER_BIT_ARRAY_MAX_VOLTAGE, carrent_active_functions);
      }
      
      //Перевіряємо чи стоїть умова моніторити мінімального опору основного каналу
      COMPARE_NOT_ZERO_OR(comp, carrent_active_functions, monitoring_r_o_signals, N_BIG)
      if(comp)
      {
        if((state_current_monitoring & (1<<IDENTIFIER_BIT_ARRAY_MIN_R_O)) != 0)
          continue_monitoring_min_r_o_current(time_from_start_record_dr);
        else
          start_monitoring_min_r_o_current(time_from_start_record_dr);
      }
      else
      {
        if((state_current_monitoring & (1<<IDENTIFIER_BIT_ARRAY_MIN_R_O)) != 0)
          end_monitoring_min_max_measurement(IDENTIFIER_BIT_ARRAY_MIN_R_O, carrent_active_functions);
      }
      
      //Перевіряємо чи стоїть умова моніторити мінімального опору резервного каналу
      COMPARE_NOT_ZERO_OR(comp, carrent_active_functions, monitoring_r_r_signals, N_BIG)
      if(comp)
      {
        if((state_current_monitoring & (1<<IDENTIFIER_BIT_ARRAY_MIN_R_R)) != 0)
          continue_monitoring_min_r_r_current(time_from_start_record_dr);
        else
          start_monitoring_min_r_r_current(time_from_start_record_dr);
      }
      else
      {
        if((state_current_monitoring & (1<<IDENTIFIER_BIT_ARRAY_MIN_R_R)) != 0)
          end_monitoring_min_max_measurement(IDENTIFIER_BIT_ARRAY_MIN_R_R, carrent_active_functions);
      }
      
      //Перевіряємо чи стоїть умова моніторити мінімальну частоту для АЧР
      COMPARE_NOT_ZERO_OR(comp, carrent_active_functions, monitoring_f_min_achr_signals, N_BIG)
      if(comp)
      {
        if((state_current_monitoring & (1<<IDENTIFIER_BIT_ARRAY_MIN_FREQUENCY_ACHR)) != 0)
          continue_monitoring_min_f(time_from_start_record_dr);
        else
          start_monitoring_min_f(time_from_start_record_dr);
      }
      else
      {
        if((state_current_monitoring & (1<<IDENTIFIER_BIT_ARRAY_MIN_FREQUENCY_ACHR)) != 0)
          end_monitoring_min_max_measurement(IDENTIFIER_BIT_ARRAY_MIN_FREQUENCY_ACHR, carrent_active_functions);
      }
      
      if (
          /*Є умова дозволу подачі команди ЧАПВ*/
          (_CHECK_SET_BIT(carrent_active_functions , RNG_BIG_VN_BLOCK_CHAPV) == 0)
          &&
          (
           (
            /*Умова зафіксувати частоту від зовнішнього ЧАПВ*/
            (_CHECK_SET_BIT(previous_active_functions, RNG_BIG_ACHR_CHAPV_VID_DV) != 0) &&
            (_CHECK_SET_BIT(carrent_active_functions , RNG_BIG_ACHR_CHAPV_VID_DV) == 0)
           )
           ||
           (
            /*Умова зафіксувати частоту від ЧАПВ*/
            (_CHECK_SET_BIT(carrent_active_functions , RNG_BIG_RAZR_CHAPV) != 0)
            &&
            (
             (
              (_CHECK_SET_BIT(previous_active_functions, RNG_BIG_ACHR_CHAPV1  ) != 0) &&
              (_CHECK_SET_BIT(carrent_active_functions , RNG_BIG_ACHR_CHAPV1  ) == 0)
             )   
             ||  
             (
              (_CHECK_SET_BIT(previous_active_functions, RNG_BIG_ACHR_CHAPV2  ) != 0) &&
              (_CHECK_SET_BIT(carrent_active_functions , RNG_BIG_ACHR_CHAPV2  ) == 0)
             )   
            ) 
           )
          ) 
         )   
      {
  	      //Збільшуємо кількість фіксованих значень частоти від ЧАПВ
    	    number_f_chapv_dr++;
  
      	  copy_meas_for_dr(measurements_f_chapv_dr);
  
        	//Фіксуємо час з моменту початку аварійного запису
        	measurements_f_chapv_dr[IDM_TM_STAMPE] = time_from_start_record_dr;
          measurements_f_chapv_dr[IDM_VMP] = (unsigned int)UNDEF_VMP;
          measurements_f_chapv_dr[IDM_VMP_EQUAL_MORE] = 0;

        	//Помічаємо, що ми фіксуємо чатоту від ЧАПВ
        	state_current_monitoring |= (1<<IDENTIFIER_BIT_ARRAY_FREQUENCY_CHAPV);
            
        	//Зразу цю подію фіксуємо у масив, який формує поточний запис
        	end_monitoring_min_max_measurement(IDENTIFIER_BIT_ARRAY_FREQUENCY_CHAPV, carrent_active_functions);
      }
      
      //Дальші дії виконуємо тіьлки у тому випадку, якщо функція end_monitoring_min_max_measurement не зафіксувала помилку і не скинула state_dr_record у STATE_DR_NO_RECORD
      if(state_dr_record != STATE_DR_NO_RECORD)
      {
        //Перевіряємо, чи ще існує умова продовження запису
        //Якщо такої умови немає - то скидаємо сигнал запущеного дискретного реєстратора, що це зафіксувати у змінених сигналах
        if (stop_regisrator(carrent_active_functions, current_settings_prt.ranguvannja_digital_registrator) != 0)
        {
          //Скидаємо сигнал роботи дискретного реєстратора
          _CLEAR_BIT(carrent_active_functions, RNG_BIG_WORK_D_REJESTRATOR);
           //.asm volatile(
           //.    "bkpt 1"
           //.    );
          //Переводимо режим роботи із дискретним реєстратором у стан "Виконується безпосередній запис у послідовну DataFlash"
          state_dr_record = STATE_DR_MAKE_RECORD;
        }
      
        //Перевіряємо чи відбуласа зміна сигналів у порівнянні із попереднім станом. Якщо така зміна є, то формуєм новий зріз сигналів у записі
        COMPARE_OR(comp, carrent_active_functions, previous_active_functions, N_BIG)
        if (comp)
        {
          //Теперішній стан сигналів не співпадає з попереднім станом сигналів

          //Збільшуємо на один кількість нових зрізів
          number_items_dr++;
      
          //Вираховуємо кількість змін сигналів
          unsigned int number_changes_into_current_item;
          _NUMBER_CHANGES_INTO_UNSIGNED_INT_ARRAY(previous_active_functions, carrent_active_functions, N_BIG, number_changes_into_current_item);
          number_changes_into_dr_record += number_changes_into_current_item;
      
          //Записуємо поточний cтан сигналів
          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR +  0] =  time_from_start_record_dr        & 0xff;
          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR +  1] = (time_from_start_record_dr >> 8 ) & 0xff;
          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR +  2] = (time_from_start_record_dr >> 16) & 0xff;

          for (size_t i = 0; i < NUMBER_BYTES_SAMPLE_DR; ++i)
          {
            size_t offset = i >> 2;
            size_t shift = 8*(i & ((1u << 2) - 1));
             
           buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 3 + i] = (carrent_active_functions[offset] >> shift) & 0xff;;
          }
          //Кількість змін сигналів у порівнянні із попереднім станом
          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 3 + NUMBER_BYTES_SAMPLE_DR + 0] = number_changes_into_current_item & 0xff;
          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 3 + NUMBER_BYTES_SAMPLE_DR + 1] = (number_changes_into_current_item >> 8) & 0xff;
        }
        
        //Перевіряємо, чи стоїть умова завершення запису
        if (
            (state_dr_record == STATE_DR_MAKE_RECORD) ||
            (time_from_start_record_dr >= (MAX_TIME_OFFSET_FROM_START - DELTA_TIME_FOR_TIMERS + 1))  ||
            ((number_items_dr + 1)     >= MAX_EVENTS_IN_ONE_RECORD  ) || 
            (statePowerDown == STATE_POWER_DOWN_ETAP_CUT)  
           )
        {
          //Підтверджуємо примусовий запис у енергонезалежну пам'ять через пропадання живлення
          if (statePowerDown == STATE_POWER_DOWN_ETAP_CUT) statePowerDown = STATE_POWER_DOWN_ETAP_CUT_CONFIRMED;
          
          //Немає умови продовження запису, або є умова завершення запису - завершуємо формування запису і подаємо команду на запис
          buffer_for_save_dr_record[FIRST_INDEX_NUMBER_ITEMS_DR      ] = number_items_dr;
          buffer_for_save_dr_record[FIRST_INDEX_NUMBER_CHANGES_DR    ] =  number_changes_into_dr_record       & 0xff;
          buffer_for_save_dr_record[FIRST_INDEX_NUMBER_CHANGES_DR + 1] = (number_changes_into_dr_record >> 8) & 0xff;

          //Перевіряємо чи треба завершити моніторинг максимального фазного струму основного каналу
          if((state_current_monitoring & (1<<IDENTIFIER_BIT_ARRAY_MAX_CURRENT_PHASE_O)) != 0)
            end_monitoring_min_max_measurement(IDENTIFIER_BIT_ARRAY_MAX_CURRENT_PHASE_O, carrent_active_functions);

          //Перевіряємо чи треба завершити моніторинг максимального фазного струму резервного каналу
          if((state_current_monitoring & (1<<IDENTIFIER_BIT_ARRAY_MAX_CURRENT_PHASE_R)) != 0)
            end_monitoring_min_max_measurement(IDENTIFIER_BIT_ARRAY_MAX_CURRENT_PHASE_R, carrent_active_functions);

          //Перевіряємо чи треба завершити моніторинг мінімальну напругу
          if((state_current_monitoring & (1<<IDENTIFIER_BIT_ARRAY_MIN_VOLTAGE)) != 0)
            end_monitoring_min_max_measurement(IDENTIFIER_BIT_ARRAY_MIN_VOLTAGE, carrent_active_functions);

          //Перевіряємо чи треба завершити моніторинг максимальну напругу
          if((state_current_monitoring & (1<<IDENTIFIER_BIT_ARRAY_MAX_VOLTAGE)) != 0)
            end_monitoring_min_max_measurement(IDENTIFIER_BIT_ARRAY_MAX_VOLTAGE, carrent_active_functions);

          //Перевіряємо чи треба завершити моніторинг мінімального опору основного каналу
          if((state_current_monitoring & (1<<IDENTIFIER_BIT_ARRAY_MIN_R_O)) != 0)
            end_monitoring_min_max_measurement(IDENTIFIER_BIT_ARRAY_MIN_R_O, carrent_active_functions);

          //Перевіряємо чи треба завершити моніторинг мінімального опору резервного каналу
          if((state_current_monitoring & (1<<IDENTIFIER_BIT_ARRAY_MIN_R_R)) != 0)
            end_monitoring_min_max_measurement(IDENTIFIER_BIT_ARRAY_MIN_R_R, carrent_active_functions);
        
          //Перевіряємо чи треба завершити моніторинг мінімальну частоту для АЧР
          if((state_current_monitoring & (1<<IDENTIFIER_BIT_ARRAY_MIN_FREQUENCY_ACHR)) != 0)
            end_monitoring_min_max_measurement(IDENTIFIER_BIT_ARRAY_MIN_FREQUENCY_ACHR, carrent_active_functions);

          /*
          Перевірку необхідності запису фіксація вимірювань при роботі ЧАПВ здійснювати
          не потрібно, тому що зараз іде перевірка чи треба примусово зупинити робити формування
          поточного запису. Якщо була ситуація запуску ЧАПВ, то ця подія мала б зафіксованою бути
          у місці програми, де аналізувалися блоки інтегральних величин
          */

          //Дальші дії виконуємо тіьлки у тому випадку, якщо функція end_monitoring_min_max_measurement не зафіксувала помилку і не скинула state_dr_record у STATE_DR_NO_RECORD
          if(state_dr_record != STATE_DR_NO_RECORD)
          {
            //Записуємо кількість зафіксованих максимальних вимірювань всіх типів
            buffer_for_save_dr_record[FIRST_INDEX_NUMBER_MAX_PHASE_O_DR] = number_max_phase_o_dr;
            buffer_for_save_dr_record[FIRST_INDEX_NUMBER_MAX_PHASE_R_DR] = number_max_phase_r_dr;
            buffer_for_save_dr_record[FIRST_INDEX_NUMBER_MIN_U_DR      ] = number_min_U_dr;
            buffer_for_save_dr_record[FIRST_INDEX_NUMBER_MAX_U_DR      ] = number_max_U_dr;
            buffer_for_save_dr_record[FIRST_INDEX_NUMBER_MIN_R_O_DR    ] = number_min_r_o_dr;
            buffer_for_save_dr_record[FIRST_INDEX_NUMBER_MIN_R_R_DR    ] = number_min_r_r_dr;
            buffer_for_save_dr_record[FIRST_INDEX_NUMBER_MIN_F_ACHR_DR ] = number_min_f_achr_dr;
            buffer_for_save_dr_record[FIRST_INDEX_NUMBER_F_CHAPV_DR    ] = number_f_chapv_dr;

            //Переводимо режим роботи із дискретним реєстратором у стан "Виконується безпосередній запис у DataFlash"
            if (state_dr_record != STATE_DR_MAKE_RECORD)
            {
              if (time_from_start_record_dr >= (MAX_TIME_OFFSET_FROM_START - DELTA_TIME_FOR_TIMERS + 1))
              {
                //Якщо відбулося перевищення по часу запису, то подаємо команду завершити запис без продовження потім цього запису у наступному записі
                state_dr_record = STATE_DR_MAKE_RECORD;
              }
              else
              {
                //Якщо відбулося перевищення по досягнкнні максимальної кількості зрізів (або іншої причини, яка покищо не оговорена, але може з'явитися у майбутньому), то подаємо команду завершити запис але на наступному проході почати новий запис
                state_dr_record = STATE_DR_CUT_RECORD;
              }
            }
          }
        
          //Скидаємо сигнал роботи дискретного реєстратора
          _CLEAR_BIT(carrent_active_functions, RNG_BIG_WORK_D_REJESTRATOR);
        }
      }

      break;
    }
  default:
    {
      //По ідеї сюди програма ніколи не мала б зайти
      fix_undefined_error_dr(carrent_active_functions);
      break;
    }
  }
  
  //Перевіряємо, чи стоїть умова сформований запис передати на запис у DataFlash
  routine_for_queue_dr();
//  PuCmdinRawBuf(carrent_active_functions);
  /*********************/
  //Формуємо попереденій стан сигналів для функції увімкнення/вимкнення
  /*********************/
  for (unsigned int i = 0; i < N_BIG; i++) previous_active_functions[i] = carrent_active_functions[i];
  /*********************/
}
/*****************************************************/

/*****************************************************/
//Функція обробки логіки дискретного реєстратора
/*****************************************************/
inline void analog_registrator(unsigned int* carrent_active_functions)
{
  static unsigned int prev_active_sources[N_BIG];
  unsigned int cur_active_sources[N_BIG];
  for(size_t i = 0; i < N_BIG; ++i) cur_active_sources[i] = carrent_active_functions[i] & current_settings_prt.ranguvannja_analog_registrator[i];

  int comp = true;
  
  if (forbidden_new_record_ar_mode_0 != 0)
  {
    /*
    Ця ситуація означає, що були активними джерела аналогового реєстратора, які запустили
    в роботу аналоговий реєстратор, і тепер для розблокування можливості запускати новий запис ми 
    чекаємо ситуації, що
    - всі джерела активації деактивуються 
    - появитьс новий сигнал запуску, якого не було раніше
    */
    ZERO_AND(comp, cur_active_sources, N_BIG)
    if(comp) 
    {
      //Перша умова розблокування можливості початку нового запису виконана
      forbidden_new_record_ar_mode_0 = 0;
    }
    else if ((current_settings_prt.control_ar & MASKA_FOR_BIT(INDEX_ML_CTR_AR_AVAR_STATE)) == 0)
    {
      //Попередній запис повністю записаний у DataFlash, але ще деякі джерела активації не деакттивувалися
      unsigned int diff_active_sources[N_BIG];
      for(size_t i = 0; i < N_BIG; ++i) diff_active_sources[i] = prev_active_sources[i] ^ cur_active_sources[i];

      COMPARE_NOT_ZERO_OR(comp, diff_active_sources, cur_active_sources, N_BIG)
      if(comp) 
      {
        //Друга умова розблокування можливості початку нового запису виконана
        forbidden_new_record_ar_mode_0 = 0;
      }
    }
  }


  static int prefault_number_periods_tmp;

  if (
      ((global_timers[INDEX_TIMER_FULL_AR_RECORD] >= MAX_TIME_FULL_AR_RECORD) && (_CHECK_SET_BIT(carrent_active_functions, RNG_BIG_WORK_A_REJESTRATOR) != 0)) ||
      (state_ar_record_m == STATE_AR_BLOCK_M) ||
      (state_ar_record_fatfs == STATE_AR_MEMORY_FULL_FATFS) ||
      (state_ar_record_fatfs == STATE_AR_BLOCK_FATFS)
     )   
  {
    if (global_timers[INDEX_TIMER_FULL_AR_RECORD] >= MAX_TIME_FULL_AR_RECORD) _SET_BIT(set_diagnostyka, ERROR_AR_TEMPORARY_BUSY_BIT);

    state_ar_record_prt = STATE_AR_BLOCK_PRT;
    global_timers[INDEX_TIMER_POSTFAULT] = -1;
    global_timers[INDEX_TIMER_FULL_AR_RECORD] = -1;
  }
  
  if (
      (arDateTimeState == AVAR_DATE_TIME_NONE) &&
      (state_ar_record_fatfs != STATE_AR_NONE_FATFS) &&
      (state_ar_record_fatfs != STATE_AR_BLOCK_FATFS) &&
      (realDateTime != 0)  
     )
  {
    arDateTimeState = AVAT_DATE_TIMR_FIX_LEVEL1;

    header_ar.time_dat = time_dat;
    header_ar.time_ms = time_ms;
  }
 
  switch (state_ar_record_prt)
  {
  case STATE_AR_NONE_PRT:
    {
      if (state_ar_record_fatfs == STATE_AR_NONE_FATFS)
      {
        global_timers[INDEX_TIMER_FULL_AR_RECORD] = -1;
        _SET_BIT(clear_diagnostyka, ERROR_AR_TEMPORARY_BUSY_BIT);
      }

      //Аналізуємо, чи стоїть умова запуску аналогового реєстратора
      NOT_ZERO_OR(comp, cur_active_sources, N_BIG)
      if (
          (
           (comp)
           &&  
           (forbidden_new_record_ar_mode_0 == 0) /*при попередній роботі ан.реєстротора (якщо така була) вже всі джерела активації були зняті і зароз вони знову виникли*/ 
          )
          ||
          (start_ar != 0) 
         )    
      {
        //Є умова запуску аналогового реєстратора

        if (state_ar_record_fatfs != STATE_AR_STOP_WRITE_FATFS)
        {
          //Переводимо режим роботи із аналоговим реєстратором у стан "Запуск нового запису"
          if (current_settings_prt.control_ar & MASKA_FOR_BIT(INDEX_ML_CTR_AR_AVAR_STATE))
          {
            state_ar_record_prt = STATE_AR_AVAR_PRT;
          }
          else
          {
            state_ar_record_prt = STATE_AR_POSTAVAR_PRT;
            global_timers[INDEX_TIMER_POSTFAULT] = 0; //Запускаємо таймер післяаварійного процесу
          }
        
          if (state_ar_record_fatfs == STATE_AR_NONE_FATFS)
          {
            //запис на рівні FATFs зараз не проводиться, тому треба підготувати інформацію про умову старту нового запису
          
            prefault_number_periods_tmp = ((POWER_CTRL->IDR & POWER_CTRL_PIN) != (uint32_t)Bit_RESET) ? current_settings_prt.prefault_number_periods : AR_TAIL_MIN_NUMBER_PERIOD;
            global_timers[INDEX_TIMER_FULL_AR_RECORD] =  20*prefault_number_periods_tmp; //Запускаємо таймер цілого запису  з врахуванням що буде доданий доаварійний масив

          
            //Записуємо мітку початку запису
            header_ar.label_start_record = LABEL_START_RECORD_AR;
            //Записуємо час початку запису
            arDateTimeState = (realDateTime != 0) ? AVAT_DATE_TIMR_FIX_LEVEL2 : AVAR_DATE_TIME_NONE;
            header_ar.time_dat = time_dat;
            header_ar.time_ms = time_ms;

            //Коефіцієнт трансформації T струму основної лінії
            header_ar.TCurrent_o = current_settings_prt.Tmn;
            //Коефіцієнт трансформації T струму резервної лінії
            header_ar.TCurrent_r = current_settings_prt.Tbp;
            //Коефіцієнт трансформації TН
            header_ar.TVoltage = current_settings_prt.TVoltage;
            
            //Час доаварійного масиву
            header_ar.prefault_number_periods = prefault_number_periods_tmp;

            //І'мя комірки
            for(unsigned int i=0; i<MAX_CHAR_IN_NAME_OF_CELL; i++)
              header_ar.name_of_cell[i] = current_settings_prt.name_of_cell[i] & 0xff;
            //Сигнали, які запустили в роботу Аналоговий реєстратор
            for (size_t i = 0; i < N_BIG; i++)
              header_ar.cur_active_sources[i] = (prev_active_sources[i] ^ cur_active_sources[i]) & cur_active_sources[i];
          }
        }
        else
        {
          _SET_BIT(set_diagnostyka, ERROR_AR_TEMPORARY_BUSY_BIT);
        }
      }

      break;
    }
  case STATE_AR_AVAR_PRT:
    {
      ZERO_AND(comp, cur_active_sources, N_BIG)
      if (
          (comp)
          || 
          ((current_settings_prt.control_ar & MASKA_FOR_BIT(INDEX_ML_CTR_AR_AVAR_STATE)) == 0) /*може статися хіба, коли під час роботи ан.реєстратора змінено це налаштування*/
         )
      {
        state_ar_record_prt = STATE_AR_POSTAVAR_PRT;
        global_timers[INDEX_TIMER_POSTFAULT] = 0; //Запускаємо таймер післяаварійного процесу
      }
      
      break;
    }
  case STATE_AR_POSTAVAR_PRT:
    {
      NOT_ZERO_OR(comp, cur_active_sources, N_BIG)
        
      if (
          ((current_settings_prt.control_ar & MASKA_FOR_BIT(INDEX_ML_CTR_AR_AVAR_STATE)) != 0) &&
          (comp)
         )
      {
        //Повертаємося до аварійного процесу
        state_ar_record_prt = STATE_AR_AVAR_PRT;
        global_timers[INDEX_TIMER_POSTFAULT] = -1; //Зупиняємо таймер післяаварійного процесу
      }
      else if (global_timers[INDEX_TIMER_POSTFAULT] >= (int)(20*current_settings_prt.postfault_number_periods))
      {
        //Завершився післяаварійний процес
        global_timers[INDEX_TIMER_POSTFAULT] = -1; //Зупиняємо таймер післяаварійного процесу
        state_ar_record_prt = STATE_AR_NONE_PRT;
        
        if (
            /*перевірку на те, що режим "Власнеаварійний процес" увімкнутий не треба, бо при умові активних джерел ми б попали у попередню умову де з післяаваріного процесу йде поворот до аварійного процесу*/
            (comp)
           )
        {
          forbidden_new_record_ar_mode_0 = 0xff; /*помічаємо будь-яким числом, що є активними деякі сигнали від попереднього записту*/
        }
      }
      
      break;
    }
  case STATE_AR_BLOCK_PRT:
    {
      //Аналізуємо чи немає умови почати новий запис поки ми не вийшли з блокованого стану
      if (
          (state_ar_record_fatfs == STATE_AR_NONE_FATFS) &&
          (state_ar_record_m == STATE_AR_NONE_M)
         )
      {
        state_ar_record_prt = STATE_AR_NONE_PRT;
       
        NOT_ZERO_OR(comp, cur_active_sources, N_BIG)
        if(comp)   
        {
          forbidden_new_record_ar_mode_0 = 0xff; /*помічаємо будь-яким числом, що є активними деякі сигнали від попереднього записту*/
        }
      }
      
      break;
    }
  default:
    {
      //Теоретично цього ніколи не мало б бути
      total_error_sw_fixed();
      break;
    }
  }
  
  //Виставляння/скидання функції Роботи Аналогового реєстратора
  if (
      (state_ar_record_prt == STATE_AR_AVAR_PRT) ||
      (state_ar_record_prt == STATE_AR_POSTAVAR_PRT)
     )
  {
    _SET_BIT(carrent_active_functions, RNG_BIG_WORK_A_REJESTRATOR);
    if (truncPrefault)
    {
      truncPrefault = false;
      int trunc = 20*(prefault_number_periods_tmp - AR_TAIL_MIN_NUMBER_PERIOD);
      if (
          (trunc > 0) && //перестраховка, бо завжди б так мало бути у цій ситуації
          (global_timers[INDEX_TIMER_FULL_AR_RECORD] >= trunc) //перестраховка, бо завжди б так мало бути у цій ситуації
         )   
      {
        global_timers[INDEX_TIMER_FULL_AR_RECORD] -= trunc;
      }
    }

  }
  else
  {
    _CLEAR_BIT(carrent_active_functions, RNG_BIG_WORK_A_REJESTRATOR);
  }

  for (size_t i = 0; i != N_BIG; ++i) prev_active_sources[i] = cur_active_sources[i];
  
  start_ar = 0;
}
/*****************************************************/


/*****************************************************/
//Функція захистів з якої здійснюються всі інші операції
/*****************************************************/
//#pragma optimize=none
inline void main_protection(void)
{
  copying_active_functions = 1; //Помічаємо, що зараз обновляємо значення активних функцій
  
  //Скижаємо ті сигнали, які відповідають за входи, кнопки і активацію з інтерфейсу
  static const unsigned int maska_input_signals[N_BIG] = 
  {
    (unsigned long) INPUT_SIGNALS_MASK_CMD_00,
    (unsigned long) INPUT_SIGNALS_MASK_CMD_01,
    (unsigned long) INPUT_SIGNALS_MASK_CMD_02,
    (unsigned long) INPUT_SIGNALS_MASK_CMD_03,
    (unsigned long) INPUT_SIGNALS_MASK_CMD_04,
    (unsigned long) INPUT_SIGNALS_MASK_CMD_05,
    (unsigned long) INPUT_SIGNALS_MASK_CMD_06,
    (unsigned long) INPUT_SIGNALS_MASK_CMD_07,
    (unsigned long) INPUT_SIGNALS_MASK_CMD_08,
    (unsigned long) INPUT_SIGNALS_MASK_CMD_09,
    (unsigned long) INPUT_SIGNALS_MASK_CMD_10,
	  (unsigned long) INPUT_SIGNALS_MASK_CMD_11,  
	  (unsigned long) INPUT_SIGNALS_MASK_CMD_12  
  };
  for (unsigned int i = 0; i < N_BIG; i++) active_functions[i] &= (unsigned int)(~maska_input_signals[i]);
  
  /**************************/
  //Перевірка, чи треба очистити трігерні функції
  /**************************/
  if (reset_trigger_function_from_interface !=0)
  {
    if ((reset_trigger_function_from_interface & (1 << USB_RECUEST)) != 0)
    {
      for (unsigned int i = 0; i < N_BIG; i++) trigger_functions_USB[i] = 0;
      
      information_about_restart_counter  &= (unsigned int)(~(1 << USB_RECUEST));
      information_about_clean_energy     &= (unsigned int)(~(1 << USB_RECUEST));
    }
    if ((reset_trigger_function_from_interface & (1 << RS485_RECUEST)) != 0)
    {
      for (unsigned int i = 0; i < N_BIG; i++) trigger_functions_RS485[i] = 0;
      
      information_about_restart_counter  &= (unsigned int)(~(1 << RS485_RECUEST));
      information_about_clean_energy     &= (unsigned int)(~(1 << RS485_RECUEST));
    }
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
    if ((reset_trigger_function_from_interface & (1 << LAN_RECUEST)) != 0)
    {
      for (unsigned int i = 0; i < N_BIG; i++) trigger_functions_LAN[i] = 0;
      
      information_about_restart_counter  &= (unsigned int)(~(1 << LAN_RECUEST));
    }
#endif
    
    //Помічаємо що ми виконали очистку по ВСІХ інтерфейсах
    reset_trigger_function_from_interface = 0;
  }
  /**************************/

  unsigned int active_inputs_grupa_ustavok = 0;
  /**************************/
  //Опрацьовуємо ФК, дискретні входи і верхній рівень
  /**************************/
  //Опрцьовуємо логіку натиснутих кнопок
  uint32_t pressed_buttons_tmp = 0;
  uint32_t buttons_mode_tmp = current_settings_prt.buttons_mode;
  if (
      (mutex_buttons == false) &&
      (pressed_buttons != 0)
     )   
  {
    pressed_buttons_tmp = pressed_buttons;
    //Очищаємо натиснуті кнопкb, інформацію про яких ми вже забрали у роботу (аде ще не опрацювали)
    pressed_buttons = 0;
  }
      
  uint32_t pressed_buttons_switcher = pressed_buttons_tmp & buttons_mode_tmp; /*натиснуті в даний момент кнопки-ключі*/
  pressed_buttons_tmp &= (uint32_t)(~buttons_mode_tmp); /*натиснуті в даний момент всі інші типи кнопок*/
      
  //Опрацьвуємо спочатку кнопки-ключі
  uint32_t fix_active_buttons_tmp = (fix_active_buttons ^ pressed_buttons_switcher) & buttons_mode_tmp;
  if (fix_active_buttons_tmp != fix_active_buttons) 
  {
    fix_active_buttons = fix_active_buttons_tmp;
    /*
    Змінилися стани кнопок-ключів
    */
    _SET_BIT(control_spi1_taskes, TASK_START_WRITE_TRG_FUNC_EEPROM_BIT);
  }
    
  //Формуємо стан натиснутих кнопок з урахуванням нового стану копок клічів і інших кнопок
  uint32_t pressed_buttons_united = pressed_buttons_tmp | fix_active_buttons_tmp;
  
  //Фікчсуємо стан ФК для передачі його на верхній рівнеь
  state_FK = pressed_buttons_united & ((1u << NUMBER_DEFINED_BUTTONS) - 1);

  //Світлова індикація натиснутих кнопок-ключів
  for (size_t i = 0; i < NUMBER_DEFINED_BUTTONS; i++)
  {
    uint32_t maska_yellow = ((1 << (i*NUMBER_LED_COLOR + LED_COLOR_RED_BIT)) | (1 << (i*NUMBER_LED_COLOR + LED_COLOR_GREEN_BIT)));
    if (((buttons_mode_tmp >> i) & 0x1) == BUTTON_MODE_SWITCHER)
    {
      if (((fix_active_buttons_tmp >> i) & 0x1) != 0) 
      {
#ifndef KEYBOARD_VER_2_1
        state_leds_Fx[0] &= (uint32_t)(~maska_yellow);
        state_leds_Fx[1] |= maska_yellow;
#else
        if (i != (4 - 1))
        {
          state_leds_Fx[0] &= (uint32_t)(~maska_yellow);
          state_leds_Fx[1] |= maska_yellow;
        }
        else
        {
          state_leds_Fx[1] &= (uint32_t)(~maska_yellow);
          state_leds_Fx[0] |= maska_yellow;
        }
#endif
      }    
      else
      {
#ifndef KEYBOARD_VER_2_1
        state_leds_Fx[1] &= (uint32_t)(~maska_yellow);
        state_leds_Fx[0] |= maska_yellow;
#else
        if (i != (4 - 1))
        {
          state_leds_Fx[1] &= (uint32_t)(~maska_yellow);
          state_leds_Fx[0] |= maska_yellow;
        }
        else
        {
          state_leds_Fx[0] &= (uint32_t)(~maska_yellow);
          state_leds_Fx[1] |= maska_yellow;
        }
#endif
      }    
    }
    else
    {
      state_leds_Fx[0] &= (uint32_t)(~maska_yellow);
      state_leds_Fx[1] &= (uint32_t)(~maska_yellow);
    }
  }

  //Перевіряємо чи є зараз активні входи
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
	int flagCommandKP = false;
	unsigned int command_from_KP[N_SMALL];
  for(size_t m = 0; m < N_SMALL; ++m) 
	{
		command_from_KP[m] = command_permitted_from_KP[m] & activation_function_from_KP[m] & ctrl_activation_function_from_KP[m];
		activation_function_from_KP[m] = 0;
		ctrl_activation_function_from_KP[m] = 0;
		
		if (command_from_KP[m] != 0)  flagCommandKP = true; 
	}
#endif

/*
  _CLEAR_BIT(active_functions, RNG_USB_ACTIVE);
  _CLEAR_BIT(active_functions, RNG_RS485_ACTIVE);
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
  _CLEAR_BIT(active_functions, RNG_LAN_ACTIVE);
#endif
  
  unsigned int active_functions_bi_small_tmp[N_SMALL];
  unsigned int active_functions_fc_small_tmp[N_SMALL];

#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
  unsigned int active_functions_goose_small_tmp[N_SMALL];
#endif
  for (size_t i = 0; i < N_SMALL; ++i)
  {
    active_functions_bi_small_tmp[i] = 0;
    active_functions_fc_small_tmp[i] = 0;

#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
    active_functions_goose_small_tmp[i] = 0;
#endif
  }
*/
      
  int flag=0;
  for(int m=0; m<N_SMALL; m++) if(activation_function_from_interface[m] != 0) {flag=1; break;}
  if (
      (pressed_buttons_united !=0)
      ||  
      (  
       (mutex_interface == false) &&
       (flag) /*&&
			 (dostup_z_VR) */
      )
      ||  
      (active_inputs !=0)
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
     /* якщо є активація виходів від Вх.GOOSE блоків і Вх.MMS блоків*/   
      || ((sLV.ch_amount_MmsSignal+sLV.ch_amount_GsSignal)>0)
			|| (flagCommandKP)	
#endif
     )   
  {
    unsigned int temp_value_for_activated_function_button_interface[N_SMALL];
    unsigned int temp_value_for_activated_function[N_SMALL];
    for(int m=0; m<N_SMALL; m++) 
    {
      temp_value_for_activated_function_button_interface[m]=0;
      temp_value_for_activated_function[m]=0;
		}

    //Активація з кнопуки
    if (pressed_buttons_united != 0)
    {
      for (unsigned int i = 0; i < NUMBER_DEFINED_BUTTONS; i++)
      {
        if ((pressed_buttons_united & (1 << i)) != 0)
        {
          unsigned int * const point_temp_value_for_activated_function = ((pressed_buttons_tmp & (1 << i)) != 0) ? temp_value_for_activated_function_button_interface : temp_value_for_activated_function;
          for (size_t j = 0; j < N_SMALL; ++j ) 
          {
            point_temp_value_for_activated_function[j] |= current_settings_prt.ranguvannja_buttons[N_SMALL*i + j];
//            active_functions_fc_small_tmp[j] |= current_settings_prt.ranguvannja_buttons[N_SMALL*i + j];
          }
        }
      }
      if ((pressed_buttons_united & (1 << (BIT_KEY_C - BIT_KEY_1))) != 0)
      {
        _SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_RESET_LEDS );
//        _SET_BIT(active_functions_fc_small_tmp, RANGE_SMALL_A01_RESET_LEDS);

        _SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_RESET_RELES);
//        _SET_BIT(active_functions_fc_small_tmp, RANGE_SMALL_A01_RESET_RELES);
      }
    }
    
    //Активація з Д.Входу
    if (active_inputs != 0)
    {
      for (unsigned int i = 0; i < NUMBER_INPUTS; i++)
      {
        if ((active_inputs & (1 << i)) != 0)
        {
          for (size_t j = 0; j < N_SMALL; ++j) 
          {
            temp_value_for_activated_function[j] |= current_settings_prt.ranguvannja_inputs[N_SMALL*i + j];
//            active_functions_bi_small_tmp[j] |= current_settings_prt.ranguvannja_inputs[N_SMALL*i + j];
          }
        }
      }
    }
    //Чи активний зараз місцевий режим від Д.Входу, або від ФК-Ключ
    unsigned int dystancijnyj = (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_MISCEVE_DYSTANCIJNE) == 0);
    
    //Активація з інтерфейсу
    if (
				(mutex_interface == false) &&
				(flag) /*&&
			  (dostup_z_VR) */
			 )		
    {
      for (size_t i = 0; i < N_SMALL; ++i)
      {
        if (dystancijnyj) temp_value_for_activated_function_button_interface[i] |= activation_function_from_interface[i];
        activation_function_from_interface[i] = 0;
      }

//			if (dystancijnyj)
//			{
//				if (_GET_STATE(dostup_z_VR, USB_RECUEST)  ) _SET_BIT(active_functions, RNG_USB_ACTIVE);
//				if (_GET_STATE(dostup_z_VR, RS485_RECUEST)) _SET_BIT(active_functions, RNG_RS485_ACTIVE);
//#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
//				if (_GET_STATE(dostup_z_VR, LAN_RECUEST)  ) _SET_BIT(active_functions, RNG_LAN_ACTIVE);
//#endif
//			}
//			dostup_z_VR = 0;
    }
		
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
    //Активація з КП
		if((flagCommandKP) && (dystancijnyj))
		{
      for (size_t i = 0; i < N_SMALL; ++i) temp_value_for_activated_function_button_interface[i] |= command_from_KP[i];
      _SET_BIT(active_functions, RNG_LAN_ACTIVE);
		}
#endif
    
    //Обєднуємо активації з кнопок (режим кнопка) + активації з інтерфейсу і кнопок (режим ключ) + кнопки фіксованого функціоналу
    for (size_t i = 0; i < N_SMALL; ++i) temp_value_for_activated_function[i] |= temp_value_for_activated_function_button_interface[i];

    //Опреділювані функції
    for (size_t i = 0; i != NUMBER_DEFINED_FUNCTIONS; ++i)
    {
      size_t index_big = RNG_BIG_DF1_IN + 3*i;
      size_t index_small = RANGE_SMALL_A01_DF1_IN + 2*i;
      active_functions[index_big >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, index_small) != 0) << (index_big & 0x1f);

      //Перевірка на необхідність пролонгації активації В-функції на час  таймеру павзи
      if (_CHECK_SET_BIT(temp_value_for_activated_function_button_interface, index_small) != 0)
      {
        //Зараз має активуватися В-ФункціяХ, тому треба запустити таймер її утримування,
        //для того, щоб потім час цей можна було зрівняти з часом таймера павзи
        if (global_timers[INDEX_TIMER_DF_PROLONG_SET_FOR_BUTTON_INTERFACE_START + i] < 0)
        {
          //Запускаємо таймер таймер утримування цієї функції в активному стані (емітація активного входу)
          //Запуск робимо тільки ту тому випадкук, якщо він ще не почався
          global_timers[INDEX_TIMER_DF_PROLONG_SET_FOR_BUTTON_INTERFACE_START + i] = 0;
        }
      }

      index_big = RNG_BIG_DF1_RST +3*i;
      index_small = RANGE_SMALL_A01_DF1_RST +2*i;
      active_functions[index_big >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, index_small) != 0) << (index_big & 0x1f);
    }

    //Опреділювані триґери
    for (size_t i = 0; i != NUMBER_DEFINED_TRIGGERS; ++i)
    {
      size_t index_big = RNG_BIG_DT1_SET + 3*i;
      size_t index_small = RANGE_SMALL_A01_DT1_SET + 2*i;
      active_functions[index_big >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, index_small) != 0) << (index_big & 0x1f);

      index_big = RNG_BIG_DT1_RESET +3*i;
      index_small = RANGE_SMALL_A01_DT1_RESET +2*i;
      active_functions[index_big >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, index_small) != 0) << (index_big & 0x1f);
    }

    
    //Функції зв'язку
    for (size_t i = 0; i < NUMBER_LINK_FUNCTIONS; ++i)
    {
      unsigned int index_big = RNG_BIG_LF1 +i;
      unsigned int index_small = RANG_SMALL_A01_LF1 +i;
      active_functions[index_big >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, index_small) != 0) << (index_big & 0x1f);
    }
      
    //Загальні функції (без ОФ-ій і функцій, які можуть блокуватися у місцевому управлінні)

    active_functions[RNG_BIG_BLOCK_VKL_VVO                     >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLOCK_VKL_VVO                    ) != 0) << (RNG_BIG_BLOCK_VKL_VVO                     & 0x1f);
    active_functions[RNG_BIG_RESET_LEDS                        >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_RESET_LEDS                       ) != 0) << (RNG_BIG_RESET_LEDS                        & 0x1f);
    active_functions[RNG_BIG_RESET_RELES                       >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_RESET_RELES                      ) != 0) << (RNG_BIG_RESET_RELES                       & 0x1f);
    active_functions[RNG_BIG_MISCEVE_DYSTANCIJNE               >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_MISCEVE_DYSTANCIJNE              ) != 0) << (RNG_BIG_MISCEVE_DYSTANCIJNE               & 0x1f);
    active_functions[RNG_BIG_STATE_VVO                         >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_STATE_VVO                        ) != 0) << (RNG_BIG_STATE_VVO                         & 0x1f);
    active_functions[RNG_BIG_CTRL_VKL_VVO                      >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_CTRL_VKL_VVO                     ) != 0) << (RNG_BIG_CTRL_VKL_VVO                      & 0x1f);
    active_functions[RNG_BIG_CTRL_OTKL_VVO                     >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_CTRL_OTKL_VVO                    ) != 0) << (RNG_BIG_CTRL_OTKL_VVO                     & 0x1f);
    active_functions[RNG_BIG_RESET_BLOCK_READY_TU_VID_ZAHYSTIV >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_RESET_BLOCK_READY_TU_VID_ZAHYSTIV) != 0) << (RNG_BIG_RESET_BLOCK_READY_TU_VID_ZAHYSTIV & 0x1f);

    active_inputs_grupa_ustavok |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_1_GRUPA_USTAVOK) != 0) << (RANGE_SMALL_A01_1_GRUPA_USTAVOK - RANGE_SMALL_A01_1_GRUPA_USTAVOK);
    active_inputs_grupa_ustavok |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_2_GRUPA_USTAVOK) != 0) << (RANGE_SMALL_A01_2_GRUPA_USTAVOK - RANGE_SMALL_A01_1_GRUPA_USTAVOK);
    active_inputs_grupa_ustavok |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_3_GRUPA_USTAVOK) != 0) << (RANGE_SMALL_A01_3_GRUPA_USTAVOK - RANGE_SMALL_A01_1_GRUPA_USTAVOK);
    active_inputs_grupa_ustavok |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_4_GRUPA_USTAVOK) != 0) << (RANGE_SMALL_A01_4_GRUPA_USTAVOK - RANGE_SMALL_A01_1_GRUPA_USTAVOK);
      
    //Увімкнення ВВ
    active_functions[RNG_BIG_VKL_VVO >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_VKL_VVO) != 0) << (RNG_BIG_VKL_VVO & 0x1f);

    //Вимкнення ВВ
    active_functions[RNG_BIG_OTKL_VV_VVO >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_CTRL_OTKL_VVO) != 0) << (RNG_BIG_OTKL_VV_VVO & 0x1f);

    //Блок для ДЗ
     active_functions[RNG_BIG_NKN_DZO               >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_NKN_DZO             ) != 0) << (RNG_BIG_NKN_DZO               & 0x1f);
     active_functions[RNG_BIG_ZBR_BLOCK_DZO1_I_O_3G >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_ZBR_BLK_DZO1_I_O_3G ) != 0) << (RNG_BIG_ZBR_BLOCK_DZO1_I_O_3G & 0x1f);
     active_functions[RNG_BIG_ZBR_BLOCK_DZO1_I_O    >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_ZBR_BLK_DZO1_I_O    ) != 0) << (RNG_BIG_ZBR_BLOCK_DZO1_I_O    & 0x1f);
     active_functions[RNG_BIG_BLOCK_DZO1            >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLK_DZO1            ) != 0) << (RNG_BIG_BLOCK_DZO1            & 0x1f);
     active_functions[RNG_BIG_BLOCK_PR_DZO2         >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLK_USK_DZO2        ) != 0) << (RNG_BIG_BLOCK_PR_DZO2         & 0x1f);
     active_functions[RNG_BIG_OP_PR_DZO2            >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_OP_USK_DZO2         ) != 0) << (RNG_BIG_OP_PR_DZO2            & 0x1f);
     active_functions[RNG_BIG_ZBR_BLOCK_DZO2_I_O_3G >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_ZBR_BLK_DZO2_I_O_3G ) != 0) << (RNG_BIG_ZBR_BLOCK_DZO2_I_O_3G & 0x1f);
     active_functions[RNG_BIG_BLOCK_DZO2            >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLK_DZO2            ) != 0) << (RNG_BIG_BLOCK_DZO2            & 0x1f);
     active_functions[RNG_BIG_BLOCK_PR_DZO3         >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLK_USK_DZO3        ) != 0) << (RNG_BIG_BLOCK_PR_DZO3         & 0x1f);
     active_functions[RNG_BIG_OP_PR_DZO3            >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_OP_USK_DZO3         ) != 0) << (RNG_BIG_OP_PR_DZO3            & 0x1f);
     active_functions[RNG_BIG_ZBR_BLOCK_DZO3_I_O_3G >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_ZBR_BLK_DZO3_I_O_3G ) != 0) << (RNG_BIG_ZBR_BLOCK_DZO3_I_O_3G & 0x1f);
     active_functions[RNG_BIG_BLOCK_DZO3            >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLK_DZO3            ) != 0) << (RNG_BIG_BLOCK_DZO3            & 0x1f);
     active_functions[RNG_BIG_ZBR_BLOCK_DZO4_I_O_3G >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_ZBR_BLK_DZO4_I_O_3G ) != 0) << (RNG_BIG_ZBR_BLOCK_DZO4_I_O_3G & 0x1f);
     active_functions[RNG_BIG_BLOCK_DZO4            >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLK_DZO4            ) != 0) << (RNG_BIG_BLOCK_DZO4            & 0x1f);

    active_functions[RNG_BIG_BLOCK_MCZO1    >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLK_MCZO1    ) != 0) << (RNG_BIG_BLOCK_MCZO1    & 0x1f);
    active_functions[RNG_BIG_BLOCK_MCZO2    >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLK_MCZO2    ) != 0) << (RNG_BIG_BLOCK_MCZO2    & 0x1f);
    active_functions[RNG_BIG_BLOCK_PR_MCZO2 >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLK_USK_MCZO2) != 0) << (RNG_BIG_BLOCK_PR_MCZO2 & 0x1f);
    active_functions[RNG_BIG_BLOCK_MCZO3    >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLK_MCZO3    ) != 0) << (RNG_BIG_BLOCK_MCZO3    & 0x1f);
    active_functions[RNG_BIG_BLOCK_MCZO4    >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLK_MCZO4    ) != 0) << (RNG_BIG_BLOCK_MCZO4    & 0x1f);

    active_functions[RNG_BIG_BLOCK_ZDZ       >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLOCK_ZDZ      ) != 0) << (RNG_BIG_BLOCK_ZDZ        & 0x1f);
    active_functions[RNG_BIG_PUSK_ZDZ_VID_DV >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_PUSK_ZDZ_VID_DV) != 0) << (RNG_BIG_PUSK_ZDZ_VID_DV  & 0x1f);

    
    active_functions[RNG_BIG_BLOCK_MCZR1 >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLK_MCZR1) != 0) << (RNG_BIG_BLOCK_MCZR1 & 0x1f);
    active_functions[RNG_BIG_BLOCK_MCZR2 >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLK_MCZR2) != 0) << (RNG_BIG_BLOCK_MCZR2 & 0x1f);

    //АПВ
    active_functions[RNG_BIG_STAT_BLK_APV >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_STAT_BLK_APV) != 0) << (RNG_BIG_STAT_BLK_APV & 0x1f);
      
    //ЧАПВ
    active_functions[RNG_BIG_ACHR_CHAPV_VID_DV  >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_ACHR_CHAPV_VID_DV ) != 0) << (RNG_BIG_ACHR_CHAPV_VID_DV  & 0x1f);
    active_functions[RNG_BIG_BLOCK_ACHR1        >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLOCK_ACHR1       ) != 0) << (RNG_BIG_BLOCK_ACHR1        & 0x1f);
    active_functions[RNG_BIG_BLOCK_ACHR2        >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLOCK_ACHR2       ) != 0) << (RNG_BIG_BLOCK_ACHR2        & 0x1f);

    //УРОВ
    active_functions[RNG_BIG_PUSK_UROV_VID_DV >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_PUSK_UROV_VID_DV) != 0) << (RNG_BIG_PUSK_UROV_VID_DV & 0x1f);

    //Блок ЗОП(КОФ) DZR_BIT_CONFIGURATION = ZOP_BIT_CONFIGURATION,
    active_functions[RNG_BIG_ZVN_NESPR_DZR         >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_ZOVN_NESPRN_DZR    ) != 0) << (RNG_BIG_ZVN_NESPR_DZR         & 0x1f);
    active_functions[RNG_BIG_ZBR_BLOCK_DZR1_I_R_3G >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_ZBR_BLK_DZR1_I_O_3G) != 0) << (RNG_BIG_ZBR_BLOCK_DZR1_I_R_3G & 0x1f);
    active_functions[RNG_BIG_ZBR_BLOCK_DZR1_I_R    >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_ZBR_BLK_DZR1_I_O   ) != 0) << (RNG_BIG_ZBR_BLOCK_DZR1_I_R    & 0x1f);
    active_functions[RNG_BIG_BLOCK_DZR1            >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLK_DZR1           ) != 0) << (RNG_BIG_BLOCK_DZR1            & 0x1f);
    active_functions[RNG_BIG_BLOCK_PR_DZR2         >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLK_USK_DZR2       ) != 0) << (RNG_BIG_BLOCK_PR_DZR2         & 0x1f);
    active_functions[RNG_BIG_OP_PR_DZR2            >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_OP_USK_DZR2        ) != 0) << (RNG_BIG_OP_PR_DZR2            & 0x1f);
    active_functions[RNG_BIG_ZBR_BLOCK_DZR2_I_R_3G >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_ZBR_BLK_DZR2_I_O_3G) != 0) << (RNG_BIG_ZBR_BLOCK_DZR2_I_R_3G & 0x1f);
    active_functions[RNG_BIG_BLOCK_DZR2            >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLK_DZR2           ) != 0) << (RNG_BIG_BLOCK_DZR2            & 0x1f);
    active_functions[RNG_BIG_BLOCK_PR_DZR3         >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLK_USK_DZR3       ) != 0) << (RNG_BIG_BLOCK_PR_DZR3         & 0x1f);
    active_functions[RNG_BIG_OP_PR_DZR3            >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_OP_USK_DZR3        ) != 0) << (RNG_BIG_OP_PR_DZR3            & 0x1f);
    active_functions[RNG_BIG_ZBR_BLOCK_DZR3_I_R_3G >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_ZBR_BLK_DZR3_I_O_3G) != 0) << (RNG_BIG_ZBR_BLOCK_DZR3_I_R_3G & 0x1f);
    active_functions[RNG_BIG_BLOCK_DZR3            >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLK_DZR3           ) != 0) << (RNG_BIG_BLOCK_DZR3            & 0x1f);

    //Блок для Umin
    active_functions[RNG_BIG_BLOCK_UMIN1 >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLOCK_UMIN1) != 0) << (RNG_BIG_BLOCK_UMIN1 & 0x1f);
    active_functions[RNG_BIG_START_UMIN1 >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_START_UMIN1) != 0) << (RNG_BIG_START_UMIN1 & 0x1f);
    active_functions[RNG_BIG_BLOCK_UMIN2 >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLOCK_UMIN2) != 0) << (RNG_BIG_BLOCK_UMIN2 & 0x1f);
    active_functions[RNG_BIG_START_UMIN2 >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_START_UMIN2) != 0) << (RNG_BIG_START_UMIN2 & 0x1f);
      
    //Блок для Umax
    active_functions[RNG_BIG_BLOCK_UMAX1 >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLOCK_UMAX1) != 0) << (RNG_BIG_BLOCK_UMAX1 & 0x1f);
    active_functions[RNG_BIG_BLOCK_UMAX2 >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLOCK_UMAX2) != 0) << (RNG_BIG_BLOCK_UMAX2 & 0x1f);

    //Блокування для УЗ
    for (size_t i = 0; i < NUMBER_UP; i++)
    {
      uint32_t rang_small_block_up = RANGE_SMALL_A01_BLOCK_UP1 + i;
      uint32_t rang_block_up = RNG_BIG_BLOCK_UP1 + 3*i;
      active_functions[rang_block_up >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, rang_small_block_up) != 0) << (rang_block_up & 0x1f);
    }
  }
  /**************************/
  
//#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
//  
//#define N_SOURCE  3
//  
//#else
//  
//#define N_SOURCE  2
//  
//#endif
//
//  for (size_t i = 0; i < N_SOURCE; ++i)
//  {
//    static unsigned int const command_signales[N_SMALL] = 
//    {
//      COMMAND_SIGNALES_0, 
//      COMMAND_SIGNALES_1, 
//      COMMAND_SIGNALES_2
//      
//#ifdef COMMAND_SIGNALES_3
//                        , 
//      COMMAND_SIGNALES_3 
//#endif
//    };
//  
//    static unsigned int prev_active_functions_small[N_SOURCE][N_SMALL];
//    
//    static enum __rang_big_u  const n_signal[N_SOURCE] = 
//    {
//      RNG_DI_ACTIVE, 
//      RNG_FK_ACTIVE
//
//#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
//                    , 
//      RNG_GOOSE_ACTIVE
//#endif
//    };
//    unsigned int const * const ref[N_SOURCE] = 
//    {
//      active_functions_bi_small_tmp, 
//      active_functions_fc_small_tmp
//
//#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
//                                      ,
//      active_functions_goose_small_tmp
//#endif
//    };
//    
//    _CLEAR_BIT(active_functions, n_signal[i]);
//    
//    unsigned int temp_activating_functions_small[N_SMALL];
//    for (unsigned int *p = temp_activating_functions_small; p < (temp_activating_functions_small + N_SMALL); ++p) *p = 0;
//    for (size_t j = 0; j < N_SMALL; ++j) 
//    {
//      //З масиву попередніх станів виділяємо тільки ті функції, якиї нас цікавить фронт змін і поміщаємо їх у тимчасовий масив
//      temp_activating_functions_small[j] = prev_active_functions_small[i][j] & command_signales[j];
//  
//      //У тимчасовому масиві виділяємо тільки ті функції, у яких зафіксовано або передній, або задній фронти
//      temp_activating_functions_small[j] ^= (ref[i][j] & command_signales[j]);
//  
//      //Тепер виділяємо у тимчасовому масиві тільки ті функції у яких зараз значення стоять рівні "1" (тобто відбувся перехід з "0" в "1")
//      temp_activating_functions_small[j] &= ref[i][j];
//
//      /*
//      Перед тим, як виділити ті функції, які у цьому циклі будуть відмічені як активні 
//      з урахуванням того, що деякі функції активоються по передньому фронті
//      копіюємо статичний стан функцій (без врахування фронтів) у тимчасовий масив
//      щоб при наступному аналізі мати попередній статичний стан активних функцій
//      */ 
//      prev_active_functions_small[i][j] = ref[i][j];
//    }
//    for (unsigned int *p = temp_activating_functions_small; p < (temp_activating_functions_small + N_SMALL); ++p)
//    {
//      if (*p != 0) 
//      {
//        _SET_BIT(active_functions, n_signal[i]);
//        break;
//      }
//    }
//  }
//
//#undef N_SOURCE
  
  /**************************/
  //Виконуємо фільтрацію переднього фронту для тих сигналів, які мають активуватися тільки по передньому фронтові
  /**************************/
  {
    static unsigned int previous_activating_functions[N_BIG];
    //Формуємо маску сигналів, які треба позначити, як активні тільки в момент переходу з "0" в "1"
    unsigned int temp_maska_filter_function[N_BIG];
    for(int i=0; i<N_BIG; i++) temp_maska_filter_function[i]=0;
    unsigned int temp_activating_functions[N_BIG];
    for(int i=0; i<N_BIG; i++) temp_activating_functions[i]=0;
  
    //Сигнал "Сблос индикации"
    _SET_BIT(temp_maska_filter_function, RNG_BIG_RESET_LEDS);
  
    //Сигнал "Сблос реле"
    _SET_BIT(temp_maska_filter_function, RNG_BIG_RESET_RELES);

    //Сигнал "Включить ВВ"
    _SET_BIT(temp_maska_filter_function, RNG_BIG_VKL_VVO);
    
    //Сигнал "Отключить ВВ"
    _SET_BIT(temp_maska_filter_function, RNG_BIG_OTKL_VV_VVO);

    //Сигнал "Скидання блокування готовності до ТУ"
    _SET_BIT(temp_maska_filter_function, RNG_BIG_RESET_BLOCK_READY_TU_VID_ZAHYSTIV);
  
    for (unsigned int i = 0; i < N_BIG; i++)
    {
      //З масиву попередніх станів виділяємо тільки ті функції, якиї нас цікавить фронт змін і поміщаємо їх у тимчасовий масив
      temp_activating_functions[i] = previous_activating_functions[i] & temp_maska_filter_function[i];
  
      //У тимчасовому масиві виділяємо тільки ті функції, у яких зафіксовано або передній, або задній фронти
      temp_activating_functions[i] ^= (active_functions[i] & temp_maska_filter_function[i]);
  
      //Тепер виділяємо у тимчасовому масиві тільки ті функції у яких зараз значення стоять рівні "1" (тобто відбувся перехід з "0" в "1")
      temp_activating_functions[i] &= active_functions[i];

      /*
      Перед тим, як виділити ті функції, які у цьому циклі будуть відмічені як активні 
      з урахуванням того, що деякі функції активоються по передньому фронті
      копіюємо статичний стан функцій (без врахування фронтів) у тимчасовий масив
      щоб при наступному аналізі мати попередній статичний стан активних функцій
      */ 
      previous_activating_functions[i] = active_functions[i];

      //Обновляємо масив функцій, які зараз активуються з врахуванням того, що серед виділених функцій маскою активними мають юути тільки ті, у яких перехід був з "0" в "1"
      active_functions[i] = (active_functions[i] & (~temp_maska_filter_function[i])) | temp_activating_functions[i];
    }
  }
  /**************************/
  
  /**************************
  Світлова індикація стану вимикача
  **************************/
  {
    uint32_t state_vv_dv = false;
    for (size_t i = 0; i < NUMBER_INPUTS; i++)
    {
      if (_CHECK_SET_BIT ((current_settings_prt.ranguvannja_inputs + N_SMALL*i), RANGE_SMALL_A01_STATE_VVO) != 0)
      {
        state_vv_dv = true;
        break;
      }
    }
    
    if (state_vv_dv)
    {
      if (_CHECK_SET_BIT(active_functions, RNG_BIG_STATE_VVO) !=0)
      {
        state_leds_ctrl &=  (uint32_t)(~((1 << LED_COLOR_GREEN_BIT) << ((uint32_t)NUMBER_LED_COLOR*(uint32_t)LED_CTRL_O)));
        state_leds_ctrl |=  (uint32_t)(  (1 << LED_COLOR_RED_BIT  ) << ((uint32_t)NUMBER_LED_COLOR*(uint32_t)LED_CTRL_I) );
      }
      else
      {
        state_leds_ctrl &=  (uint32_t)(~((1 << LED_COLOR_RED_BIT  ) << ((uint32_t)NUMBER_LED_COLOR*(uint32_t)LED_CTRL_I)));
        state_leds_ctrl |=  (uint32_t)(  (1 << LED_COLOR_GREEN_BIT) << ((uint32_t)NUMBER_LED_COLOR*(uint32_t)LED_CTRL_O) );
      }
    }
    else
    {
      state_leds_ctrl &=  (uint32_t)(~(((1 << LED_COLOR_GREEN_BIT) << ((uint32_t)NUMBER_LED_COLOR*(uint32_t)LED_CTRL_O)) | ((1 << LED_COLOR_RED_BIT) << ((uint32_t)NUMBER_LED_COLOR*(uint32_t)LED_CTRL_I))));
    }
  }
  /**************************/

  /**************************/
  /*Режим перепрограмування*/
  /**************************/
//#ifndef DEBUG_TEST  
  if ((GPIO_STAFF_REPROGRAM->IDR & GPIO_PIN_STAFF_REPROGRAM) != (uint32_t)Bit_RESET)
//#else
//  if (reprogram)
//#endif
  {
    _SET_BIT(set_diagnostyka, WARNING_REPROGRAM);
    timerWaitReprogram = -1;
  }
  else _SET_BIT(clear_diagnostyka, WARNING_REPROGRAM);
  /**************************/

//  //Діагностика справності раз на період
//  diagnostyca_adc_execution();
  
  /**************************/
  //Сигнал "Несправность Общая"
  /**************************/
  if (
      (_CHECK_SET_BIT(active_functions, RNG_BIG_RESET_LEDS ) != 0) ||
      (_CHECK_SET_BIT(active_functions, RNG_BIG_RESET_RELES) != 0)
     )
  {
    _SET_BIT(clear_diagnostyka, ERROR_DR_LOSS_INFORMATION_BIT);
    _SET_BIT(clear_diagnostyka, ERROR_PR_ERR_LOSS_INFORMATION_BIT);
  }
        
  unsigned int diagnostyka_tmp[N_DIAGN];
  for (size_t i = 0; i < N_DIAGN; i ++)
  {
    diagnostyka_tmp[i] = diagnostyka[i];

    diagnostyka_tmp[i] &= (unsigned int)(~clear_diagnostyka[i]); 
    diagnostyka_tmp[i] |= set_diagnostyka[i]; 
  }

  _CLEAR_BIT(diagnostyka_tmp, EVENT_START_SYSTEM_BIT);
  _CLEAR_BIT(diagnostyka_tmp, EVENT_SOFT_RESTART_SYSTEM_BIT);
  _CLEAR_BIT(diagnostyka_tmp, EVENT_DROP_POWER_BIT);
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
  _CLEAR_BIT(diagnostyka_tmp, EVENT_RESTART_CB_BIT);
#endif
  unsigned int not_null = false;
  for (size_t i = 0; i < N_DIAGN; i++) 
  {
    not_null |= (diagnostyka_tmp[i] != 0);
    if (not_null) break;
  }
              
  if (not_null)
  {
    _SET_BIT(active_functions, RNG_BIG_DEFECT);
    /**************************/
    //Сигнал "Несправность Аварийная"
    /**************************/
    static unsigned int const maska_avar_error[N_DIAGN] = 
		{
			MASKA_AVAR_ERROR_0,
			MASKA_AVAR_ERROR_1,
			MASKA_AVAR_ERROR_2,
			MASKA_AVAR_ERROR_3
		};

    not_null = false;
    for (size_t i = 0; i < N_DIAGN; i++) 
    {
      not_null |= ((diagnostyka_tmp[i] & maska_avar_error[i])  != 0);
      if (not_null) break;
    }
    if (not_null)
    {
      // _SET_BIT(active_functions, RNG_BIG_AVAR_DEFECT);
       #warning "No Avar Error"
    }
    else
    {
      _CLEAR_BIT(active_functions, RNG_BIG_AVAR_DEFECT);
    }
    /**************************/
  }
  else
  {
    _CLEAR_BIT(active_functions, RNG_BIG_DEFECT);
    _CLEAR_BIT(active_functions, RNG_BIG_AVAR_DEFECT);
  }
  /**************************/

  static unsigned int previous_active_functions[N_BIG];
  if (_CHECK_SET_BIT(active_functions, RNG_BIG_AVAR_DEFECT) == 0)
  {
    //Аварійна ситуація не зафіксована
    
    /**************************/
    //Обробка передавальних функцій
    /**************************/
    tf_handler(previous_active_functions, active_functions, &active_inputs_grupa_ustavok);
    /**************************/
	}
	
	/**************************/
  //Вибір групи уставок
  /**************************/
  for (size_t i = 0; i < NUMBER_GROUP_USTAVOK; i++)
  {
    if (active_inputs_grupa_ustavok & (1 << i)) 
    {
      _CLEAR_BIT(active_functions, RNG_BIG_INVERS_DV_GRUPA_USTAVOK);
      break;
    }
    else
    {
      if (i == (NUMBER_GROUP_USTAVOK - 1)) _SET_BIT(active_functions, RNG_BIG_INVERS_DV_GRUPA_USTAVOK);
    }
  }
  
  if (count_number_set_bit(&active_inputs_grupa_ustavok, NUMBER_GROUP_USTAVOK) > 1)
	{
    _SET_BIT(set_diagnostyka, ERROR_SELECT_GRUPY_USRAVOK);
		_SET_BIT(diagnostyka_tmp, ERROR_SELECT_GRUPY_USRAVOK);
		_SET_BIT(active_functions, RNG_BIG_DEFECT);
	}
  else
	{
    _SET_BIT(clear_diagnostyka, ERROR_SELECT_GRUPY_USRAVOK);
		_CLEAR_BIT(diagnostyka_tmp, ERROR_SELECT_GRUPY_USRAVOK);
		
		not_null = false;
		for (size_t i = 0; i < N_DIAGN; i++) 
		{
	    not_null |= (diagnostyka_tmp[i] != 0);
  	  if (not_null) break;
		}
	  if (not_null == false)
  	{
    	_CLEAR_BIT(active_functions, RNG_BIG_DEFECT);
		}
	}

  static unsigned int const maska_signals_for_lock_group[N_BIG] =
  {
    LOCK_GRUP_PKP_CMD_00,
    LOCK_GRUP_PKP_CMD_01,
    LOCK_GRUP_PKP_CMD_02,
    LOCK_GRUP_PKP_CMD_03,
    LOCK_GRUP_PKP_CMD_04,
    LOCK_GRUP_PKP_CMD_05,
    LOCK_GRUP_PKP_CMD_06,
		LOCK_GRUP_PKP_CMD_07,
		LOCK_GRUP_PKP_CMD_08,
		LOCK_GRUP_PKP_CMD_09,
		LOCK_GRUP_PKP_CMD_10,
		LOCK_GRUP_PKP_CMD_11,
		LOCK_GRUP_PKP_CMD_12
  };
  unsigned int comp = false;
  COMPARE_NOT_ZERO_OR(comp, active_functions, maska_signals_for_lock_group, N_BIG)
  if (comp)
  {
    //Іде блокування груп уставок - група уставок залишається тою, яка вибрана попередньо
    _SET_BIT(active_functions, RNG_BIG_BLK_GRUP_USTAVOK_VID_ZACHYSTIV);

    unsigned int number_group_stp_tmp = 0;
    if(( _CHECK_SET_BIT(active_functions, RNG_BIG_1_GRUPA_USTAVOK) ) !=0 ) number_group_stp_tmp++;
    if(( _CHECK_SET_BIT(active_functions, RNG_BIG_2_GRUPA_USTAVOK) ) !=0 ) number_group_stp_tmp++;
    if(( _CHECK_SET_BIT(active_functions, RNG_BIG_3_GRUPA_USTAVOK) ) !=0 ) number_group_stp_tmp++;
    if(( _CHECK_SET_BIT(active_functions, RNG_BIG_4_GRUPA_USTAVOK) ) !=0 ) number_group_stp_tmp++;
    
    if (number_group_stp_tmp != 1)
    {
      //Теоретично цього ніколи не мало б бути
      total_error_sw_fixed();
    }
  }
  else
  {
    //Можна вибирати групу уставок - захисти цю операцію не блокують
    _CLEAR_BIT(active_functions, RNG_BIG_BLK_GRUP_USTAVOK_VID_ZACHYSTIV);
    setpoints_selecting(active_functions, active_inputs_grupa_ustavok);
  }

  unsigned int number_group_stp = 0;
  if     (( _CHECK_SET_BIT(active_functions, RNG_BIG_1_GRUPA_USTAVOK) ) !=0 ) number_group_stp = 0;
  else if(( _CHECK_SET_BIT(active_functions, RNG_BIG_2_GRUPA_USTAVOK) ) !=0 ) number_group_stp = 1;
  else if(( _CHECK_SET_BIT(active_functions, RNG_BIG_3_GRUPA_USTAVOK) ) !=0 ) number_group_stp = 2;
  else if(( _CHECK_SET_BIT(active_functions, RNG_BIG_4_GRUPA_USTAVOK) ) !=0 ) number_group_stp = 3;
  else
  {
    //Теоретично цього ніколи не мало б бути
    total_error_sw_fixed();
  }
  /**************************/

  /***********************************************************/
  //Розрахунок вимірювань
  /***********************************************************/
  calc_measurement(number_group_stp);
  
  //Копіюємо вимірювання для низькопріоритетних і високопріоритетних завдань
  unsigned int bank_measurement_high_tmp = (bank_measurement_high ^ 0x1) & 0x1;
  if(semaphore_measure_values_low1 == 0)
  {
    for (unsigned int i = 0; i < _NUMBER_IM; i++) 
    {
      measurement_high[bank_measurement_high_tmp][i] = measurement_middle[i] = measurement[i];
    }
    frequency_middle = frequency;
    for (unsigned int i = 0; i < MAX_NUMBER_INDEXES_RESISTANCE; i++) resistance_middle[i] = resistance[i];
  }
  else
  {
    for (unsigned int i = 0; i < _NUMBER_IM; i++) 
    {
      measurement_high[bank_measurement_high_tmp][i] = measurement[i];
    }
  }
  bank_measurement_high = bank_measurement_high_tmp;
  /***********************************************************/
  
  //Логічні схеми мають працювати тільки у тому випадку, якщо немє сигналу "Аварийная неисправность"
  if (_CHECK_SET_BIT(active_functions, RNG_BIG_AVAR_DEFECT) == 0)
  {
    //Аварійна ситуація не зафіксована
    
    /**************************/
    //Контроль привода ВВ
    /**************************/
    control_VV(active_functions);
    control_VVR(active_functions);
    /**************************/

    /**************************/
    //ДЗO
    /**************************/
    if ((current_settings_prt.configuration & (1 << DZO_BIT_CONFIGURATION)) != 0)
    {
      dzo_handler(active_functions, number_group_stp);
    }
    else
    {
      //Очищуємо сигнали, які не можуть бути у даній конфігурації
      static const unsigned int maska_dzo_signals[N_BIG] = 
      {
        (unsigned int)DZO_CMD_00,
        (unsigned int)DZO_CMD_01,
        (unsigned int)DZO_CMD_02,
        (unsigned int)DZO_CMD_03,
        (unsigned int)DZO_CMD_04,
        (unsigned int)DZO_CMD_05,
        (unsigned int)DZO_CMD_06,
        (unsigned int)DZO_CMD_07,
        (unsigned int)DZO_CMD_08,
        (unsigned int)DZO_CMD_09,
        (unsigned int)DZO_CMD_10,
        (unsigned int)DZO_CMD_11,
        (unsigned int)DZO_CMD_12
      };
      for (unsigned int i = 0; i < N_BIG; i++) active_functions[i] &= (unsigned int)(~maska_dzo_signals[i]);
      
      global_timers[INDEX_TIMER_DZO1] = -1;
      global_timers[INDEX_TIMER_DZO1_AMTZ] = -1;
      global_timers[INDEX_TIMER_DZO2_DIR] = -1;
      global_timers[INDEX_TIMER_DZO2_DIR_PR] = -1;
      global_timers[INDEX_TIMER_DZO2_INV] = -1;
      global_timers[INDEX_TIMER_DZO2_INV_PR] = -1;
      global_timers[INDEX_TIMER_DZO2_AMTZ] = -1;
      global_timers[INDEX_TIMER_DZO2_AMTZ_PR] = -1;
      global_timers[INDEX_TIMER_DZO2_VVID_PR] = -1;
      global_timers[INDEX_TIMER_DZO2_AMTZ_VVID_PR] = -1;
      global_timers[INDEX_TIMER_DZO3_DIR] = -1;
      global_timers[INDEX_TIMER_DZO3_DIR_PR] = -1;
      global_timers[INDEX_TIMER_DZO3_INV] = -1;
      global_timers[INDEX_TIMER_DZO3_INV_PR] = -1;
      global_timers[INDEX_TIMER_DZO3_AMTZ] = -1;
      global_timers[INDEX_TIMER_DZO3_AMTZ_PR] = -1;
      global_timers[INDEX_TIMER_DZO3_VVID_PR] = -1;
      global_timers[INDEX_TIMER_DZO3_AMTZ_VVID_PR] = -1;
      global_timers[INDEX_TIMER_DZO4_DIR] = -1;
      //global_timers[INDEX_TIMER_DZO4_DIR_PR] = -1;
      global_timers[INDEX_TIMER_DZO4_INV] = -1;
      //global_timers[INDEX_TIMER_DZO4_INV_PR] = -1;
      global_timers[INDEX_TIMER_DZO4_AMTZ] = -1;
      //global_timers[INDEX_TIMER_DZO4_AMTZ_PR] = -1;
      //global_timers[INDEX_TIMER_DZO4_VVID_PR] = -1;
      //global_timers[INDEX_TIMER_DZO4_AMTZ_VVID_PR] = -1;
      global_timers[INDEX_TIMER_NKN_DZO] = -1;
    }
    /**************************/

    /**************************/
    //МТЗ
    /**************************/
    if ((current_settings_prt.configuration & (1 << MTZ1_BIT_CONFIGURATION)) != 0)
    {
    }
    else
    {
      //Очищуємо сигнали, які не можуть бути у даній конфігурації
      static const unsigned int maska_mtz_signals[N_BIG] = 
      {
        0,//MASKA_MTZ_SIGNALS_0,
        0,//MASKA_MTZ_SIGNALS_1,
        0,//MASKA_MTZ_SIGNALS_2, 
        0,//MASKA_MTZ_SIGNALS_3, 
        0,//MASKA_MTZ_SIGNALS_4, 
        0,//MASKA_MTZ_SIGNALS_5,
        0,//MASKA_MTZ_SIGNALS_6, 
        0,//MASKA_MTZ_SIGNALS_7, 
        0,//MASKA_MTZ_SIGNALS_8, 
        0,//MASKA_MTZ_SIGNALS_9,
        0,//MASKA_MTZ_SIGNALS_10
        0,//MASKA_MTZ_SIGNALS_11
        0,//MASKA_MTZ_SIGNALS_12
      };
      for (unsigned int i = 0; i < 1; i++) active_functions[i] &= (unsigned int)(~maska_mtz_signals[i]);
    }
    /**************************/
     /**************************/
    //МТЗO
    /**************************/
    if ((current_settings_prt.configuration & (1 << MCZO_BIT_CONFIGURATION)) != 0)
    {
	  mtzo_handler(active_functions, number_group_stp);//
    }
    else
    {
      //Очищуємо сигнали, які не можуть бути у даній конфігурації
      static const unsigned int maska_mtzo_signals[N_BIG] = 
      {
        (unsigned int)MCZO_CMD_00,
        (unsigned int)MCZO_CMD_01,
        (unsigned int)MCZO_CMD_02,
        (unsigned int)MCZO_CMD_03,
        (unsigned int)MCZO_CMD_04,
        (unsigned int)MCZO_CMD_05,
        (unsigned int)MCZO_CMD_06,
        (unsigned int)MCZO_CMD_07,
        (unsigned int)MCZO_CMD_08,
        (unsigned int)MCZO_CMD_09,
        (unsigned int)MCZO_CMD_10,
        (unsigned int)MCZO_CMD_11,
        (unsigned int)MCZO_CMD_12
      };
      for (unsigned int i = 0; i < N_BIG; i++) active_functions[i] &= (unsigned int)(~maska_mtzo_signals[i]);
      
      global_timers[INDEX_TIMER_MTZO1] = -1;
      global_timers[INDEX_TIMER_MTZO1_N_VPERED] = -1;
      global_timers[INDEX_TIMER_MTZO1_N_NAZAD] = -1;
      global_timers[INDEX_TIMER_MTZO1_PO_NAPRUZI] = -1;
      global_timers[INDEX_TIMER_MTZO2] = -1;
      global_timers[INDEX_TIMER_MTZO2_DEPENDENT] = -1;
      global_timers[INDEX_TIMER_MTZO2_PR] = -1;
      global_timers[INDEX_TIMER_MTZO2_N_VPERED] = -1;
      global_timers[INDEX_TIMER_MTZO2_N_VPERED_PR] = -1;
      global_timers[INDEX_TIMER_MTZO2_N_NAZAD] = -1;
      global_timers[INDEX_TIMER_MTZO2_N_NAZAD_PR] = -1;
      global_timers[INDEX_TIMER_MTZO2_PO_NAPRUZI] = -1;
      global_timers[INDEX_TIMER_MTZO2_PO_NAPRUZI_PR] = -1;
      global_timers[INDEX_TIMER_MTZO2_VVID_PR] = -1;
      global_timers[INDEX_TIMER_MTZO3] = -1;
      global_timers[INDEX_TIMER_MTZO3_N_VPERED] = -1;
      global_timers[INDEX_TIMER_MTZO3_N_NAZAD] = -1;
      global_timers[INDEX_TIMER_MTZO3_PO_NAPRUZI] = -1;
      global_timers[INDEX_TIMER_MTZO4] = -1;
      global_timers[INDEX_TIMER_MTZO4_N_VPERED] = -1;
      global_timers[INDEX_TIMER_MTZO4_N_NAZAD] = -1;
      global_timers[INDEX_TIMER_MTZO4_PO_NAPRUZI] = -1;
    }
    /**************************/
    /**************************/
    //МТЗP
    /**************************/
    if ((current_settings_prt.configuration & (1 << MCZR_BIT_CONFIGURATION)) != 0)
    {
      mtzr_handler(active_functions, number_group_stp);
    }
    else
    {
      //Очищуємо сигнали, які не можуть бути у даній конфігурації
      static const unsigned int maska_mtzr_signals[N_BIG] = 
      {
        (unsigned int)MCZR_CMD_00,
        (unsigned int)MCZR_CMD_01,
        (unsigned int)MCZR_CMD_02,
        (unsigned int)MCZR_CMD_03,
        (unsigned int)MCZR_CMD_04,
        (unsigned int)MCZR_CMD_05,
        (unsigned int)MCZR_CMD_06,
        (unsigned int)MCZR_CMD_07,
        (unsigned int)MCZR_CMD_08,
        (unsigned int)MCZR_CMD_09,
        (unsigned int)MCZR_CMD_10,
        (unsigned int)MCZR_CMD_11,
        (unsigned int)MCZR_CMD_12
      };
      for (unsigned int i = 0; i < N_BIG; i++) active_functions[i] &= (unsigned int)(~maska_mtzr_signals[i]);
      
      global_timers[INDEX_TIMER_MTZR1] = -1;
      global_timers[INDEX_TIMER_MTZR1_N_VPERED] = -1;
      global_timers[INDEX_TIMER_MTZR1_N_NAZAD] = -1;
      global_timers[INDEX_TIMER_MTZR1_PO_NAPRUZI] = -1;
      
      global_timers[INDEX_TIMER_MTZR2] = -1;
      global_timers[INDEX_TIMER_MTZR2_N_VPERED] = -1;
      global_timers[INDEX_TIMER_MTZR2_N_NAZAD] = -1;
      global_timers[INDEX_TIMER_MTZR2_PO_NAPRUZI] = -1;
      
    }
    /**************************/
	/**************************/
    //ДЗP
    /**************************/
    if ((current_settings_prt.configuration & (1 << DZR_BIT_CONFIGURATION)) != 0)
    {
      dzr_handler(active_functions, number_group_stp);
    }
    else
    {
      //Очищуємо сигнали, які не можуть бути у даній конфігурації
      static const unsigned int maska_dzr_signals[N_BIG] = 
      {
        (unsigned int)DZR_CMD_00,
        (unsigned int)DZR_CMD_01,
        (unsigned int)DZR_CMD_02,
        (unsigned int)DZR_CMD_03,
        (unsigned int)DZR_CMD_04,
        (unsigned int)DZR_CMD_05,
        (unsigned int)DZR_CMD_06,
        (unsigned int)DZR_CMD_07,
        (unsigned int)DZR_CMD_08,
        (unsigned int)DZR_CMD_09,
        (unsigned int)DZR_CMD_10,
        (unsigned int)DZR_CMD_11,
        (unsigned int)DZR_CMD_12
      };
      for (unsigned int i = 0; i < N_BIG; i++) active_functions[i] &= (unsigned int)(~maska_dzr_signals[i]);
      
      global_timers[INDEX_TIMER_DZR1] = -1;
      global_timers[INDEX_TIMER_DZR1_AMTZ] = -1;
      global_timers[INDEX_TIMER_DZR2_DIR] = -1;
      global_timers[INDEX_TIMER_DZR2_DIR_PR] = -1;
      global_timers[INDEX_TIMER_DZR2_INV] = -1;
      global_timers[INDEX_TIMER_DZR2_INV_PR] = -1;
      global_timers[INDEX_TIMER_DZR2_AMTZ] = -1;
      global_timers[INDEX_TIMER_DZR2_AMTZ_PR] = -1;
      global_timers[INDEX_TIMER_DZR2_VVID_PR] = -1;
      global_timers[INDEX_TIMER_DZR2_AMTZ_VVID_PR] = -1;
      global_timers[INDEX_TIMER_DZR3_DIR] = -1;
      global_timers[INDEX_TIMER_DZR3_DIR_PR] = -1;
      global_timers[INDEX_TIMER_DZR3_INV] = -1;
      global_timers[INDEX_TIMER_DZR3_INV_PR] = -1;
      global_timers[INDEX_TIMER_DZR3_AMTZ] = -1;
      global_timers[INDEX_TIMER_DZR3_AMTZ_PR] = -1;
      global_timers[INDEX_TIMER_DZR3_VVID_PR] = -1;
      global_timers[INDEX_TIMER_DZR3_AMTZ_VVID_PR] = -1;
      //global_timers[INDEX_TIMER_DZ4_DIR] = -1;
      //global_timers[INDEX_TIMER_DZ4_DIR_PR] = -1;
      //global_timers[INDEX_TIMER_DZ4_INV] = -1;
      //global_timers[INDEX_TIMER_DZ4_INV_PR] = -1;
      //global_timers[INDEX_TIMER_DZ4_AMTZ] = -1;
      //global_timers[INDEX_TIMER_DZ4_AMTZ_PR] = -1;
      //global_timers[INDEX_TIMER_DZ4_VVID_PR] = -1;
      //global_timers[INDEX_TIMER_DZ4_AMTZ_VVID_PR] = -1;
      global_timers[INDEX_TIMER_NKN_DZR] = -1;
    }
    /**************************/
    if ((current_settings_prt.configuration & (1 << UMIN_BIT_CONFIGURATION)) != 0) 
    {
      /**************************/
      //ЗНМИН1
      /**************************/
      umin1_handler(active_functions, number_group_stp);
      /**************************/
      
      /**************************/
      //ЗНМИН2
      /**************************/
      umin2_handler(active_functions, number_group_stp);
      /**************************/
    } 
    else 
    {
      //Очищуємо сигнали, які не можуть бути у даній конфігурації
      static const unsigned int maska_umin_signals[N_BIG] = 
      {
        (unsigned int)UMIN_CMD_00,
        (unsigned int)UMIN_CMD_01,
        (unsigned int)UMIN_CMD_02,
        (unsigned int)UMIN_CMD_03,
        (unsigned int)UMIN_CMD_04,
        (unsigned int)UMIN_CMD_05,
        (unsigned int)UMIN_CMD_06,
        (unsigned int)UMIN_CMD_07,
        (unsigned int)UMIN_CMD_08,
        (unsigned int)UMIN_CMD_09,
        (unsigned int)UMIN_CMD_10,
        (unsigned int)UMIN_CMD_11,
        (unsigned int)UMIN_CMD_12
      };
      for (unsigned int i = 0; i < N_BIG; i++) active_functions[i] &= (unsigned int)(~maska_umin_signals[i]);

      global_timers[INDEX_TIMER_UMIN1] = -1;
      global_timers[INDEX_TIMER_UMIN2] = -1;
    }
    
    if ((current_settings_prt.configuration & (1 << UMAX_BIT_CONFIGURATION)) != 0) 
    {
      /**************************/
      //ЗНМАКС1
      /**************************/
      umax1_handler(active_functions, number_group_stp);
      /**************************/
      
      /**************************/
      //ЗНМАКС2
      /**************************/
      umax2_handler(active_functions, number_group_stp);
      /**************************/
    } 
    else 
    {
      //Очищуємо сигнали, які не можуть бути у даній конфігурації
      static const unsigned int maska_umax_signals[N_BIG] = 
      {
        (unsigned int)UMAX_CMD_00,
        (unsigned int)UMAX_CMD_01,
        (unsigned int)UMAX_CMD_02,
        (unsigned int)UMAX_CMD_03,
        (unsigned int)UMAX_CMD_04,
        (unsigned int)UMAX_CMD_05,
        (unsigned int)UMAX_CMD_06,
        (unsigned int)UMAX_CMD_07,
        (unsigned int)UMAX_CMD_08,
        (unsigned int)UMAX_CMD_09,
        (unsigned int)UMAX_CMD_10,
        (unsigned int)UMAX_CMD_11,
        (unsigned int)UMAX_CMD_12
      };
      for (unsigned int i = 0; i < N_BIG; i++) active_functions[i] &= (unsigned int)(~maska_umax_signals[i]);

      global_timers[INDEX_TIMER_UMAX1] = -1;
      global_timers[INDEX_TIMER_UMAX2] = -1;
    }
    
    if ((current_settings_prt.configuration & (1 << ACHR_CHAPV_BIT_CONFIGURATION)) != 0)
    {
      /**************************/
      //АЧР ЧАПВ
      /**************************/
      achr_chapv_handler(active_functions, number_group_stp);
      /**************************/
    } 
    else 
    {
      //Очищуємо сигнали, які не можуть бути у даній конфігурації
      static const unsigned int maska_achr_chapv_signals[N_BIG] = 
      {
        (unsigned int)ACHR_CHAPV_CMD_00,
        (unsigned int)ACHR_CHAPV_CMD_01,
        (unsigned int)ACHR_CHAPV_CMD_02,
        (unsigned int)ACHR_CHAPV_CMD_03,
        (unsigned int)ACHR_CHAPV_CMD_04,
        (unsigned int)ACHR_CHAPV_CMD_05,
        (unsigned int)ACHR_CHAPV_CMD_06,
        (unsigned int)ACHR_CHAPV_CMD_07,
        (unsigned int)ACHR_CHAPV_CMD_08,
        (unsigned int)ACHR_CHAPV_CMD_09,
        (unsigned int)ACHR_CHAPV_CMD_10,
        (unsigned int)ACHR_CHAPV_CMD_11,
        (unsigned int)ACHR_CHAPV_CMD_12 
      };
      for (unsigned int i = 0; i < N_BIG; i++) active_functions[i] &= (unsigned int)(~maska_achr_chapv_signals[i]);

      global_timers[INDEX_TIMER_ACHR_CHAPV_100MS_1] = -1;
      global_timers[INDEX_TIMER_CHAPV1_1MS] = -1;
      global_timers[INDEX_TIMER_CHAPV2_1MS] = -1;
      global_timers[INDEX_TIMER_BLOCK_CHAPV1_5MS] = -1;
      global_timers[INDEX_TIMER_BLOCK_CHAPV2_5MS] = -1;
      global_timers[INDEX_TIMER_ACHR1] = -1;
      global_timers[INDEX_TIMER_CHAPV1] = -1;
      global_timers[INDEX_TIMER_ACHR2] = -1;
      global_timers[INDEX_TIMER_CHAPV2] = -1;

      previous_state_po_achr_chapv_umnf1 = 0;
      previous_state_po_achr_chapv_ubpf1 = 0;
      previous_states_CHAPV1 = 0;
      trigger_CHAPV1 = 0;
      previous_states_CHAPV2= 0;
      trigger_CHAPV2= 0;
    }
    
    /**************************/
    //ЗДЗ
    /**************************/
    if ((current_settings_prt.configuration & (1 << ZDZ_BIT_CONFIGURATION)) != 0)
    {
      zdz_handler(active_functions, number_group_stp);
    }
    else
    {
#if   (                                 \
       (MODYFIKACIA_VERSII_PZ == 0) ||  \
       (MODYFIKACIA_VERSII_PZ == 3) ||  \
       (MODYFIKACIA_VERSII_PZ == 4) ||  \
       (MODYFIKACIA_VERSII_PZ == 6) ||  \
       (MODYFIKACIA_VERSII_PZ == 10)||  \
       (MODYFIKACIA_VERSII_PZ == 13)||  \
       (MODYFIKACIA_VERSII_PZ == 14)    \
      )   
      //Вимикаємо можливий режим тестування оптоканалу
      _DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD28_DD30) = (((current_settings_prt.zdz_ovd_porig + 1) & 0xf) << 8) | (0 << 12);
      if (zdz_ovd_diagnostyka)
      {
        if (zdz_ovd_diagnostyka & (1 << 0)) _SET_BIT(clear_diagnostyka, TEST_OVD1);
        if (zdz_ovd_diagnostyka & (1 << 1)) _SET_BIT(clear_diagnostyka, TEST_OVD2);
        if (zdz_ovd_diagnostyka & (1 << 2)) _SET_BIT(clear_diagnostyka, TEST_OVD3);
        
        zdz_ovd_diagnostyka = 0;
      }
      delta_time_test = PERIOD_ZDZ_TEST;
#endif
      
      //Очищуємо сигнали, які не можуть бути у даній конфігурації
      static const unsigned int maska_zdz_signals[N_BIG] = 
      {
        (unsigned int) ZDZS_CMD_00,
        (unsigned int) ZDZS_CMD_01,
        (unsigned int) ZDZS_CMD_02,
        (unsigned int) ZDZS_CMD_03,
        (unsigned int) ZDZS_CMD_04,
        (unsigned int) ZDZS_CMD_05,
        (unsigned int) ZDZS_CMD_06,
        (unsigned int) ZDZS_CMD_07,
        (unsigned int) ZDZS_CMD_08,
        (unsigned int) ZDZS_CMD_09,
        (unsigned int) ZDZS_CMD_10,
        (unsigned int) ZDZS_CMD_11,
        (unsigned int) ZDZS_CMD_12 
      };
      for (unsigned int i = 0; i < N_BIG; i++) active_functions[i] &= (unsigned int)(~maska_zdz_signals[i]);

      global_timers[INDEX_TIMER_ZDZ] = -1;
    }
    /**************************/

    /**************************/
    //УРОВ
    /**************************/
    if ((current_settings_prt.configuration & (1 << UROV_BIT_CONFIGURATION)) != 0)
    {
      urov_handler(active_functions, number_group_stp);
    }
    else
    {
      //Очищуємо сигнали, які не можуть бути у даній конфігурації
      static const unsigned int maska_urov_signals[N_BIG] = 
      {
        UROV_CMD_00,
        UROV_CMD_01,
        UROV_CMD_02,
        UROV_CMD_03,
        UROV_CMD_04,
        UROV_CMD_05,
        UROV_CMD_06,
        UROV_CMD_07,
        UROV_CMD_08,
        UROV_CMD_09,
        UROV_CMD_10,
        UROV_CMD_11,
        UROV_CMD_12
      };
      for (unsigned int i = 0; i < N_BIG; i++) active_functions[i] &= (unsigned int)(~maska_urov_signals[i]);

      global_timers[INDEX_TIMER_UROV1] = -1;
      global_timers[INDEX_TIMER_UROV2] = -1;
    }
    /**************************/

    /**************************/
    //АПВ
    /**************************/
    if ((current_settings_prt.configuration & (1 << APV_BIT_CONFIGURATION)) != 0)
    {
      apv_handler(active_functions, number_group_stp);
    }
    else
    {
      //Очищуємо сигнали, які не можуть бути у даній конфігурації
      static const unsigned int maska_apv_signals[N_BIG] = 
      {
        APV_CMD_00,
        APV_CMD_01,
        APV_CMD_02,
        APV_CMD_03,
        APV_CMD_04,
        APV_CMD_05,
        APV_CMD_06,
        APV_CMD_07,
        APV_CMD_08,
        APV_CMD_09,
        APV_CMD_10,
        APV_CMD_11,
        APV_CMD_12
      };
      for (unsigned int i = 0; i < N_BIG; i++) active_functions[i] &= (unsigned int)(~maska_apv_signals[i]);

      global_timers[INDEX_TIMER_APV_1] = -1;
      global_timers[INDEX_TIMER_APV_2] = -1;
      global_timers[INDEX_TIMER_APV_3] = -1;
      global_timers[INDEX_TIMER_APV_4] = -1;
      global_timers[INDEX_TIMER_APV_BLOCK_VID_APV1] = -1;
      global_timers[INDEX_TIMER_APV_BLOCK_VID_APV2] = -1;
      global_timers[INDEX_TIMER_APV_BLOCK_VID_APV3] = -1;
      global_timers[INDEX_TIMER_APV_BLOCK_VID_APV4] = -1;
      global_timers[INDEX_TIMER_APV_BLOCK_VID_VV] = -1;
      global_timers[INDEX_TIMER_APV_TMP1] = -1;
      global_timers[INDEX_TIMER_ACHR_CHAPV] = -1;
      global_timers[INDEX_TIMER_APV_TMP2] = -1;

      previous_states_APV_0 = 0;
      trigger_APV_0 = 0;
    }
    /**************************/

    if ((current_settings_prt.configuration & (1 << UP_BIT_CONFIGURATION)) != 0) 
    {
      up_a01_handler(active_functions, number_group_stp);
    } 
    else 
    {
      //Очищуємо сигнали, які не можуть бути у даній конфігурації
      static const unsigned int maska_up_signals[N_BIG] = 
      {
        (unsigned int) UP_CMD_00,
        (unsigned int) UP_CMD_01,
        (unsigned int) UP_CMD_02,
        (unsigned int) UP_CMD_03,
        (unsigned int) UP_CMD_04,
        (unsigned int) UP_CMD_05,
        (unsigned int) UP_CMD_06,
        (unsigned int) UP_CMD_07,
        (unsigned int) UP_CMD_08,
        (unsigned int) UP_CMD_09,
        (unsigned int) UP_CMD_10,
        (unsigned int) UP_CMD_11,
        (unsigned int) UP_CMD_12
      };
      for (unsigned int i = 0; i < N_BIG; i++) active_functions[i] &= (unsigned int)(~maska_up_signals[i]);

      for (size_t i = 0; i < NUMBER_UP; i++) global_timers[INDEX_TIMER_UP1 + i] = -1;
    }
    
    /**************************/
    //Розширена логіка
    /**************************/
    if ((current_settings_prt.configuration & (1 << EL_BIT_CONFIGURATION)) != 0)
    {
      unsigned int active_functions_tmp[NUMBER_ITERATION_EL_MAX][N_BIG];
      unsigned int iteration = 0;
      unsigned int repeat_state = false;
      while (iteration < current_settings_prt.number_iteration_el)
      {
        if (iteration > 0)
        {
          //Перевірка на рівність поточного стану і попереднього
          COMPARE_AND(comp, active_functions_tmp[iteration - 1], active_functions, N_BIG)
          if (comp) break;
          
          //Пошук, чи вже був поточний стан зафіксований у попередніх ітераціях
          for (int i = (iteration - 2); ((repeat_state == false) && (i >= 0)); --i)
          {
            COMPARE_AND(repeat_state, active_functions_tmp[i], active_functions, N_BIG)
          }            
        }
        if (repeat_state) break;
        
        for (size_t i = 0; i != N_BIG; ++i) active_functions_tmp[iteration][i] = active_functions[i];

        d_and_handler(active_functions);
        d_or_handler(active_functions);
        d_xor_handler(active_functions);
        d_not_handler(active_functions);
        df_handler(active_functions);
        dt_handler(active_functions);
        
        ++iteration;
      }
      
      if (
          (repeat_state) ||
          (iteration >= current_settings_prt.number_iteration_el)
         )
      {
        _SET_BIT(active_functions, RNG_BIG_ERROR_CONF_EL);
      }
      else
      {
        _CLEAR_BIT(active_functions, RNG_BIG_ERROR_CONF_EL);
      }
    }
    else
    {
      //Очищуємо сигнали, які не можуть бути у даній конфігурації
      static const unsigned int maska_el_signals[N_BIG] = 
      {
        (unsigned int)EL_CMD_00,
        (unsigned int)EL_CMD_01,
        (unsigned int)EL_CMD_02,
        (unsigned int)EL_CMD_03,
        (unsigned int)EL_CMD_04,
        (unsigned int)EL_CMD_05,
        (unsigned int)EL_CMD_06,
        (unsigned int)EL_CMD_07,
        (unsigned int)EL_CMD_08,
        (unsigned int)EL_CMD_09,
        (unsigned int)EL_CMD_10,
        (unsigned int)EL_CMD_11,
        (unsigned int)EL_CMD_12 
      };
      for (size_t i = 0; i < N_BIG; ++i) active_functions[i] &= (unsigned int)(~maska_el_signals[i]);
      
      //Скидаємо всі таймери, які відповідають за розширену логіку
      for(unsigned int i = INDEX_TIMER_DF_PROLONG_SET_FOR_BUTTON_INTERFACE_START; i < (INDEX_TIMER_DF_WORK_START + NUMBER_DEFINED_FUNCTIONS); i++)
        global_timers[i] = -1;
      
      static_logic_df = 0;
    }
    /**************************/

    /**************************/
    //Включення-Відключення
    /**************************/
    on_off_vvo(active_functions);
    on_off_vvr(active_functions);
    /**************************/
    
    /**************************/
    //ВМП (завжди пісяля логіки Блоку вимикання)
    /**************************/
    vmp_handler(active_functions);
    /**************************/

    /**************************/
    //Готовность к ТУ
    /**************************/
    ready_tu(active_functions);
    /**************************/

    /**************************/
    //Ресурс вимикача (завжди пісяля логіки Блоку вимикання)
    /**************************/
    resurs_vymykacha_handler(active_functions);
    /**************************/
  }
  else
  {
    //Аварійна ситуація зафіксована
    
    //Скидаємо всі активні функції, крім інформативних
    active_functions[0]  &= INFO_CMD_00;
    active_functions[1]  &= INFO_CMD_01;
    active_functions[2]  &= INFO_CMD_02;
    active_functions[3]  &= INFO_CMD_03;
    active_functions[4]  &= INFO_CMD_04;
    active_functions[5]  &= INFO_CMD_05;
    active_functions[6]  &= INFO_CMD_06;
    active_functions[7]  &= INFO_CMD_07;
    active_functions[8]  &= INFO_CMD_08;
    active_functions[9]  &= INFO_CMD_09;
    active_functions[10] &= INFO_CMD_10;
    active_functions[11] &= INFO_CMD_11;
    active_functions[12] &= INFO_CMD_12;
    
    //Деактивовуємо всі реле
    state_outputs = 0;
#ifdef NUMBER_DS
    ds = 0;
#endif
    
    //Переводимо у початковий стан деякі глобальні змінні
    previous_states_APV_0 = 0;
    trigger_APV_0 = 0;
    previous_state_po_achr_chapv_umnf1 = 0;
    previous_state_po_achr_chapv_ubpf1 = 0;
    previous_states_CHAPV1 = 0;
    trigger_CHAPV1 = 0;
    previous_states_ready_tu = 0;
    trigger_ready_tu = 0;
    
    //Скидаємо всі таймери, які присутні у лозіці
    for (
         int *p = (global_timers + INDEX_TIMER_DF_PROLONG_SET_FOR_BUTTON_INTERFACE_START); 
         p != (global_timers + _MAX_NUMBER_GLOBAL_TIMERS_WITHOUT_REGS); 
         ++p
        ) *p = -1;

    static_logic_df = 0;
  }

  /**************************/
  //Обробка аналогового реєстратора
  /**************************/
  analog_registrator(active_functions);
  /**************************/

  /**************************/
  //Обробка дискретного реєстратора
  /**************************/
  digital_registrator(active_functions);
  /**************************/

  /**************************/
  //Робота з функціями, які мають записуватися у енергонезалежну пам'ять
  /**************************/
  static const unsigned int maska_trg_func_array[N_BIG] = {
                                                    (unsigned int)TRGO_CMD_00,
                                                    (unsigned int)TRGO_CMD_01,
                                                    (unsigned int)TRGO_CMD_02,
                                                    (unsigned int)TRGO_CMD_03,
                                                    (unsigned int)TRGO_CMD_04,
                                                    (unsigned int)TRGO_CMD_05,
                                                    (unsigned int)TRGO_CMD_06,
                                                    (unsigned int)TRGO_CMD_07,
                                                    (unsigned int)TRGO_CMD_08,
                                                    (unsigned int)TRGO_CMD_09,
                                                    (unsigned int)TRGO_CMD_10,
                                                    (unsigned int)TRGO_CMD_11,
                                                    (unsigned int)TRGO_CMD_12
                                                  };
  comp = true;
  for (size_t i = 0; i != N_BIG; ++i)
  {
    unsigned int tmp_data = active_functions[i] & maska_trg_func_array[i];
    if (trigger_active_functions[i] != tmp_data)
    {
      comp = false;
      trigger_active_functions[i] = tmp_data;
    }
  }
  if (comp != true)
  {
    /*
    Сигнали, значення яких записується у енергонезалежну пам'1ять змінилися.
    Подаємо команду на їх запис у енергонезалежну пам'ять
    */
    _SET_BIT(control_spi1_taskes, TASK_START_WRITE_TRG_FUNC_EEPROM_BIT);
  }
  /**************************/

  /**************************/
  //Перекидання інфомації у масиви активних і тригерних функцій
  /**************************/
  for (size_t i = 0; i != N_BIG; ++i)
  {
    unsigned int temp_data = active_functions[i];
    trigger_functions_USB[i]   |= temp_data;
    trigger_functions_RS485[i] |= temp_data;
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
    trigger_functions_LAN[i]   |= temp_data;
#endif
  }

  copying_active_functions = 0; //Помічаємо, що обновлення значення активних функцій завершене
  
  /*
  Робимо копію значення активних функцій для того, щоб коли ці знаення будуть
  обновлятися, то можна було б іншим модулям  (запис у об'єднаний аналоговий
  реєстратор) взяти попереднє, але достовірне значення
  */
  for (unsigned int i = 0; i < N_BIG; i++) 
  {
    unsigned int temp_data = active_functions[i];
    active_functions_copy[i] = temp_data;
    previous_active_functions[i] = temp_data;
  }
  /**************************/

  /**************************/
  //Вивід інформації на виходи
  /**************************/
  //Спочатку перевіряємо, чи не активовувалвся команда "Сблос реле" - і якщо так, то попередньо скидаємо всі реле
  if (_CHECK_SET_BIT(active_functions, RNG_BIG_RESET_RELES) !=0)
  {
    state_outputs = 0;
  }
  
  if (_CHECK_SET_BIT(active_functions, RNG_BIG_AVAR_DEFECT) == 0)
  {
    //Не зафіксовано аварійної ситуації, тому встановлювати реле можна
    
    //Визначаємо, які реле зараз мають бути замкнутими
    for (unsigned int i = 0; i < NUMBER_SIMPLE_OUTPUTS; i++)
    {
      //У тимчасовий масив поміщаємо ЛОГІЧНЕ І ранжування виходу, який індексується інедексом "i" і функцій, які зараз є активними
      unsigned int temp_array_of_outputs[N_BIG];
    
      for (unsigned int j = 0; j < N_BIG; j++) temp_array_of_outputs[j] = current_settings_prt.ranguvannja_outputs[N_BIG*i + j] & active_functions[j];

      //Сигнал "Аварійна несправність" працює у інверсному режимі: замикає реле на якому зранжована у випадку, коли даний сигнал не активинй
      if(_CHECK_SET_BIT((current_settings_prt.ranguvannja_outputs + N_BIG*i), RNG_BIG_AVAR_DEFECT) !=0)
      {
        //Сигнал "Aварийная неисправность"  справді зранжовано на даний вихід
        if (_CHECK_SET_BIT(temp_array_of_outputs, RNG_BIG_AVAR_DEFECT) == 0)
        {
          //Сигнал "Aварийная неисправность" не є активним
          //Приимусово встановлюємо його у активний стан у масиві, який є  ЛОГІЧНИМ І анжування виходу, який індексується інедексом "i" і функцій, які зараз є активними
          _SET_BIT(temp_array_of_outputs, RNG_BIG_AVAR_DEFECT);
        }
        else
        {
          //Сигнал "Aварийная неисправность" є активним
          //Приимусово переводимо його у пасивний стан у масиві, який є  ЛОГІЧНИМ І анжування виходу, який індексується інедексом "i" і функцій, які зараз є активними
          _CLEAR_BIT(temp_array_of_outputs,RNG_BIG_AVAR_DEFECT );
        }
      }
      
      //Сигнал "Загальна несправність" працює у інверсному режимі: замикає реле на якому зранжована у випадку, коли даний сигнал не активинй
      if(_CHECK_SET_BIT((current_settings_prt.ranguvannja_outputs + N_BIG*i), RNG_BIG_DEFECT) !=0)
      {
        //Сигнал "Загальна несправність"  справді зранжовано на даний вихід
        if (_CHECK_SET_BIT(temp_array_of_outputs, RNG_BIG_DEFECT) ==0)
        {
          //Сигнал "Загальна несправність" не є активним
          //Приимусово встановлюємо його у активний стан у масиві, який є  ЛОГІЧНИМ І анжування виходу, який індексується інедексом "i" і функцій, які зараз є активними
          _SET_BIT(temp_array_of_outputs, RNG_BIG_DEFECT);
        }
        else
        {
          //Сигнал "Загальна несправність" є активним
          //Приимусово переводимо його у пасивний стан у масиві, який є  ЛОГІЧНИМ І анжування виходу, який індексується інедексом "i" і функцій, які зараз є активними
          _CLEAR_BIT(temp_array_of_outputs, RNG_BIG_DEFECT);
        }
      }

      //Перевіряємо, чи є співпадіння між ранжованими функціями на цьому виході і функціями, які зараз є активними - умова активації виходу
      flag=0;
      for(int m=0; m<N_BIG; m++) if(temp_array_of_outputs[m] != 0) {flag=1; break;}
      if (flag)
      {
        //Для сигнального реле виконуємо його замикання, а для командного перевіряємо чи нема спроби активувати реле при умові що на нього заведено блок включення, причому він блокований
        if ((current_settings_prt.type_of_output & (1 << i)) != 0)
        {
          //Вихід сигнальний, тому у буль якому разі замикаємо реле
          //Відмічаємо, що даний вихід - ЗАМКНУТИЙ
          state_outputs |= (1 << i);
        }
        else
        {
          //Вихід командний, тому перевіряємо чи не йде спроба активувати реле, на яке заведено БВ, причому блок БВ з пеквних причин блокований (неактивний)
          if (
              (_CHECK_SET_BIT((current_settings_prt.ranguvannja_outputs + N_BIG*i), RNG_BIG_WORK_BV_VVO) == 0) &&
              (_CHECK_SET_BIT((current_settings_prt.ranguvannja_outputs + N_BIG*i), RNG_BIG_WORK_BV_VVR) == 0)
             )
          {
            //На дане реле не заводиться сигнал БВ (блок включення)
          
            //Відмічаємо, що даний вихід - ЗАМКНУТИЙ
            state_outputs |= (1 << i);
          }
          else
          {
            //На дане реле заводиться сигнал БВ (блок включення)
          
            //Відмічаємо, що даний вихід - ЗАМКНУТИЙ тільки тоді, коли функція БВ активна зараз
            if (
                ((_CHECK_SET_BIT((current_settings_prt.ranguvannja_outputs + N_BIG*i), RNG_BIG_WORK_BV_VVO) != 0) && (_CHECK_SET_BIT(active_functions, RNG_BIG_WORK_BV_VVO) !=0)) ||
                ((_CHECK_SET_BIT((current_settings_prt.ranguvannja_outputs + N_BIG*i), RNG_BIG_WORK_BV_VVR) != 0) && (_CHECK_SET_BIT(active_functions, RNG_BIG_WORK_BV_VVR) !=0))
               )   
              state_outputs |= (1 << i);
            else
              state_outputs &= ~(1 << i);
          }
        }
      }
      else
      {
        //Перевіряємо, чи вихід командний, чи сигнальний
        if ((current_settings_prt.type_of_output & (1 << i)) == 0)
        {
          //Вихід командний
        
          //Відмічаємо, що даний вихід - РОЗІМКНУТИЙ
          state_outputs &= ~(1 << i);
        }
      }
    }

#ifdef NUMBER_DS
    if ((current_settings_prt.configuration & (1 << DS_BIT_CONFIGURATION)) != 0)
    {
      for (size_t i = NUMBER_SIMPLE_OUTPUTS; i != NUMBER_OUTPUTS; ++i)
      {
        //У тимчасовий масив поміщаємо ЛОГІЧНЕ І ранжування виходу, який індексується інедексом "i" і функцій, які зараз є активними
        unsigned int temp_array_of_outputs[N_BIG];
    
        for (unsigned int j = 0; j < N_BIG; j++) temp_array_of_outputs[j] = current_settings_prt.ranguvannja_outputs[N_BIG*i + j] & active_functions[j];

        //Сигнал "Аварійна несправність" працює у інверсному режимі: замикає реле на якому зранжована у випадку, коли даний сигнал не активинй
        if(_CHECK_SET_BIT((current_settings_prt.ranguvannja_outputs + N_BIG*i), RANG_AVAR_DEFECT) !=0)
        {
          //Сигнал "Aварийная неисправность"  справді зранжовано на даний вихід
          if (_CHECK_SET_BIT(temp_array_of_outputs, RANG_AVAR_DEFECT) == 0)
          {
            //Сигнал "Aварийная неисправность" не є активним
            //Приимусово встановлюємо його у активний стан у масиві, який є  ЛОГІЧНИМ І анжування виходу, який індексується інедексом "i" і функцій, які зараз є активними
            _SET_BIT(temp_array_of_outputs, RANG_AVAR_DEFECT);
          }
          else
          {
            //Сигнал "Aварийная неисправность" є активним
            //Приимусово переводимо його у пасивний стан у масиві, який є  ЛОГІЧНИМ І анжування виходу, який індексується інедексом "i" і функцій, які зараз є активними
            _CLEAR_BIT(temp_array_of_outputs, RANG_AVAR_DEFECT);
          }
        }
      
        //Сигнал "Загальна несправність" працює у інверсному режимі: замикає реле на якому зранжована у випадку, коли даний сигнал не активинй
        if(_CHECK_SET_BIT((current_settings_prt.ranguvannja_outputs + N_BIG*i), RANG_DEFECT) !=0)
        {
          //Сигнал "Загальна несправність"  справді зранжовано на даний вихід
          if (_CHECK_SET_BIT(temp_array_of_outputs, RANG_DEFECT) ==0)
          {
            //Сигнал "Загальна несправність" не є активним
            //Приимусово встановлюємо його у активний стан у масиві, який є  ЛОГІЧНИМ І анжування виходу, який індексується інедексом "i" і функцій, які зараз є активними
            _SET_BIT(temp_array_of_outputs, RANG_DEFECT);
          }
          else
          {
            //Сигнал "Загальна несправність" є активним
            //Приимусово переводимо його у пасивний стан у масиві, який є  ЛОГІЧНИМ І анжування виходу, який індексується інедексом "i" і функцій, які зараз є активними
            _CLEAR_BIT(temp_array_of_outputs, RANG_DEFECT);
          }
        }

        //Перевіряємо, чи є співпадіння між ранжованими функціями на цьому виході і функціями, які зараз є активними - умова активації виходу
        NOT_ZERO_OR(comp, temp_array_of_outputs, N_BIG)
        if (comp)
        {
          if (
              (_CHECK_SET_BIT((current_settings_prt.ranguvannja_outputs + N_BIG*i), RNG_BIG_WORK_BV_VVO) == 0) &&
              (_CHECK_SET_BIT((current_settings_prt.ranguvannja_outputs + N_BIG*i), RNG_BIG_WORK_BV_VVR) == 0)
             )
          {
            //На дане реле не заводиться сигнал БВ (блок включення)
          
            //Відмічаємо, що даний вихід - ЗАМКНУТИЙ
            _SET_STATE(ds, (i - NUMBER_SIMPLE_OUTPUTS));
          }
          else
          {
            //На дане реле заводиться сигнал БВ (блок включення)
          
            //Відмічаємо, що даний вихід - ЗАМКНУТИЙ тільки тоді, коли функція БВ активна зараз
            if (
                ((_CHECK_SET_BIT((current_settings_prt.ranguvannja_outputs + N_BIG*i), RNG_BIG_WORK_BV_VVO) != 0) && (_CHECK_SET_BIT(active_functions, RNG_BIG_WORK_BV_VVO) !=0)) ||
                ((_CHECK_SET_BIT((current_settings_prt.ranguvannja_outputs + N_BIG*i), RNG_BIG_WORK_BV_VVR) != 0) && (_CHECK_SET_BIT(active_functions, RNG_BIG_WORK_BV_VVR) !=0))
               )   
              _SET_STATE(ds, (i - NUMBER_SIMPLE_OUTPUTS));
            else
              _CLEAR_STATE(ds, (i - NUMBER_SIMPLE_OUTPUTS));
          }
        }
        else
        {
          //Відмічаємо, що даний вихід - РОЗІМКНУТИЙ
          _CLEAR_STATE(ds, (i - NUMBER_SIMPLE_OUTPUTS));
        }
      }
    }
    else ds = 0;
#endif    
  }
  else
  {
    //Зафіксовано аварійнe ситуацію, тому деактивуємо всі реле!!!

    //Деактивовуємо всі реле
    state_outputs = 0;
#ifdef NUMBER_DS    
    ds = 0;
#endif
  }
  
  //Перевіряємо чи треба записувати стан сигнальних виходів у EEPROM
  if((state_outputs  & current_settings_prt.type_of_output) != state_signal_outputs)
  {
    state_signal_outputs = state_outputs  & current_settings_prt.type_of_output;
    //Виставляємо повідомлення про те, що в EEPROM треба записати нові значення сигнальних виходів і тригерних світлоіндикаторів
    _SET_BIT(control_spi1_taskes, TASK_START_WRITE_STATE_LEDS_OUTPUTS_EEPROM_BIT);
  }
  
  //Стан виходу з уразуванням імпульсного режиму роботи сигнальних виходів
  unsigned int output_signal_modif = (current_settings_prt.type_of_output_modif & current_settings_prt.type_of_output);
  state_outputs_raw = ( state_outputs & ((unsigned int)(~output_signal_modif)) ) | ((state_outputs & output_signal_modif)*output_timer_prt_signal_output_mode_2);
  
  _DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD31_DD34_DD35_DD37) = state_outputs_raw;
#if (                                   \
     (MODYFIKACIA_VERSII_PZ == 5) ||    \
     (MODYFIKACIA_VERSII_PZ == 15)      \
    )  

  _DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD28_DD30) = (state_outputs_raw >> 16)<< 8;

#else

#ifdef NUMBER_DS
  _DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD28_DD30) = (ds & (MASKA_FOR_BIT(NUMBER_DS) - 1)) << 8;
#endif
  
#endif

  TIM_PRT_write_tick = TIM2->CNT;
  /**************************/

  /**************************/
  //Вивід інформації на світлодіоди
  /**************************/
  //Спочатку перевіряємо, чи не активовувалвся команда "Сблос индикации" - і якщо так, то попередньо скидаємо всю індикацію
  if (_CHECK_SET_BIT(active_functions, RNG_BIG_RESET_LEDS) !=0)
  {
    state_leds = 0;
  }
  
  //Визначаємо, які світлоіндикатори зараз мають бути активними
  for (unsigned int i = 0; i < NUMBER_LEDS; i++)
  {
    //У тимчасовий масив копіюємо ранжування світлоіндикатора, який індексується інедексом "i"
    unsigned int temp_array_of_leds[N_BIG];
    
    //Перевіряємо, чи є співпадіння між ранжованими функціями на цьому світлоіндикаторі і функціями, які зараз є активними - умова активації виходу
    for (unsigned int j = 0; j < N_BIG; j++ ) temp_array_of_leds[j] = current_settings_prt.ranguvannja_leds[N_BIG*i + j] & active_functions[j];

    flag=0;
    for(int m=0; m<N_BIG; m++) if(temp_array_of_leds[m] != 0) {flag=1; break;}
    if (flag)
    {
      //Відмічаємо, що даний світлоіндикатор - ГОРИТЬ
      state_leds |= (1 << i);
    }
    else
    {
      //Перевіряємо, чи даний світлоіндикатор нормальний, чи тригерний
      if ((current_settings_prt.type_of_led & (1 << i)) == 0)
      {
        //Світлоіндикатор нормальний

        //Відмічаємо, що даний світлоіндикатор - ПОГАШЕНИЙ
        state_leds &= ~(1 << i);
      }
    }
  }
  //Перевіряємо чи треба записувати стан тригерних світлоіндикаторів у EEPROM
  if((state_leds  & current_settings_prt.type_of_led) != state_trigger_leds)
  {
    state_trigger_leds = state_leds  & current_settings_prt.type_of_led;
    //Виставляємо повідомлення про те, що в EEPROM треба записати нові значення сигнальних виходів і тригерних світлоіндикаторів
    _SET_BIT(control_spi1_taskes, TASK_START_WRITE_STATE_LEDS_OUTPUTS_EEPROM_BIT);
  }
  
  //Сервісні світлоіндикатори
  /*Run_Error*/
  if (_CHECK_SET_BIT(active_functions, RNG_BIG_AVAR_DEFECT) == 0) state_leds_ctrl |=  (1 << LED_COLOR_GREEN_BIT) << ((uint32_t)NUMBER_LED_COLOR*(uint32_t)LED_CTRL_R_E);
  else state_leds_ctrl &=  (uint32_t)(~((1 << LED_COLOR_GREEN_BIT) << ((uint32_t)NUMBER_LED_COLOR*(uint32_t)LED_CTRL_R_E)));
  if (
      (_CHECK_SET_BIT(active_functions, RNG_BIG_DEFECT     ) != 0) ||
      (_CHECK_SET_BIT(active_functions, RNG_BIG_AVAR_DEFECT) != 0)
     ) state_leds_ctrl |=  (1 << LED_COLOR_RED_BIT) << ((uint32_t)NUMBER_LED_COLOR*(uint32_t)LED_CTRL_R_E);
  else state_leds_ctrl &=  (uint32_t)(~((1 << LED_COLOR_RED_BIT) << ((uint32_t)NUMBER_LED_COLOR*(uint32_t)LED_CTRL_R_E)));
  
  static uint32_t state_leds_lock[2];
  static uint32_t state_leds_ctrl_lock[2];
  static uint32_t state_leds_Fx_lock[2][2];
  static size_t bank_lock;
  
  size_t bank_lock_tmp1 = bank_lock;
  size_t bank_lock_tmp2 = (bank_lock_tmp1 + 1) & 0x1;
  
  state_leds_lock[bank_lock_tmp2] |= state_leds;
  state_leds_ctrl_lock[bank_lock_tmp2] |= state_leds_ctrl;
  state_leds_Fx_lock[bank_lock_tmp2][0] |= state_leds_Fx[0];
  state_leds_Fx_lock[bank_lock_tmp2][1] |= state_leds_Fx[1];

  static uint32_t current_LED_N_COL;
  
  //Очищаємо попередню інформацію
  _DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD32_DD38) = ((1 << current_LED_N_COL) << LED_N_ROW) | ((uint32_t)(~0) & ((1 << LED_N_ROW) - 1));
  
  uint32_t state_leds_tmp = 0;
  
  switch (current_LED_N_COL)
  {
  case 0:
    {
      uint32_t state_leds_auto = state_leds_lock[bank_lock_tmp1];
      
      state_leds_tmp = (((state_leds_auto >>  0) & 0x1) << 0) |
                       (((state_leds_auto >>  2) & 0x1) << 1) |
                       (((state_leds_auto >>  4) & 0x1) << 2) |
                       (((state_leds_auto >>  6) & 0x1) << 3) |
                       (((state_leds_auto >>  8) & 0x1) << 4) |
                       (((state_leds_auto >> 10) & 0x1) << 5) |
                       (((state_leds_auto >> 12) & 0x1) << 6) |
                       (((state_leds_auto >> 14) & 0x1) << 7);
      break;
    }
  case 1:
    {
      uint32_t state_leds_auto = state_leds_lock[bank_lock_tmp1];
      uint32_t state_leds_ctrl_auto = state_leds_ctrl_lock[bank_lock_tmp1];
      
      state_leds_tmp = (((state_leds_auto >>  1) & 0x1) << 0) |
                       (((state_leds_auto >>  3) & 0x1) << 1) |
                       (((state_leds_auto >>  5) & 0x1) << 2) |
                       (((state_leds_auto >>  7) & 0x1) << 3) |
                       (((state_leds_auto >>  9) & 0x1) << 4) |
                       (((state_leds_auto >> 11) & 0x1) << 5) |
                       (((state_leds_auto >> 13) & 0x1) << 6) |
                       ((((state_leds_ctrl_auto >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)LED_CTRL_O)) & (1 << LED_COLOR_RED_BIT)) != 0) << 7);
      break;
    }
  case 2:
    {
      uint32_t state_leds_auto = state_leds_lock[bank_lock_tmp1];
      uint32_t state_leds_ctrl_auto = state_leds_ctrl_lock[bank_lock_tmp1];
      uint32_t state_leds_Fx0_auto = state_leds_Fx_lock[bank_lock_tmp1][0];

      state_leds_tmp = ((((state_leds_ctrl_auto >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)LED_CTRL_R_E  )) & (1 << LED_COLOR_RED_BIT)) != 0) << 0) |

                       (((state_leds_auto >> 15) & 0x1) << 1) |
                       (((state_leds_auto >> 16) & 0x1) << 2) |
      
                       ((((state_leds_Fx0_auto >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)(1 - 1))) & (1 << LED_COLOR_RED_BIT)) != 0) << 3) | 
                       ((((state_leds_Fx0_auto >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)(2 - 1))) & (1 << LED_COLOR_RED_BIT)) != 0) << 4) | 
                       ((((state_leds_Fx0_auto >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)(3 - 1))) & (1 << LED_COLOR_RED_BIT)) != 0) << 5) | 
                       ((((state_leds_Fx0_auto >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)(4 - 1))) & (1 << LED_COLOR_RED_BIT)) != 0) << 6) | 
                       ((((state_leds_Fx0_auto >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)(5 - 1))) & (1 << LED_COLOR_RED_BIT)) != 0) << 7);
      break;
    }
  case 3:
    {
      uint32_t state_leds_ctrl_auto = state_leds_ctrl_lock[bank_lock_tmp1];
      uint32_t state_leds_Fx0_auto = state_leds_Fx_lock[bank_lock_tmp1][0];

      state_leds_tmp = ((((state_leds_ctrl_auto >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)LED_CTRL_R_E  )) & (1 << LED_COLOR_GREEN_BIT)) != 0) << 0) |

                       ((((state_leds_Fx0_auto >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)(1 - 1))) & (1 << LED_COLOR_GREEN_BIT)) != 0) << 3) | 
                       ((((state_leds_Fx0_auto >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)(2 - 1))) & (1 << LED_COLOR_GREEN_BIT)) != 0) << 4) | 
                       ((((state_leds_Fx0_auto >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)(3 - 1))) & (1 << LED_COLOR_GREEN_BIT)) != 0) << 5) | 
                       ((((state_leds_Fx0_auto >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)(4 - 1))) & (1 << LED_COLOR_GREEN_BIT)) != 0) << 6) | 
                       ((((state_leds_Fx0_auto >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)(5 - 1))) & (1 << LED_COLOR_GREEN_BIT)) != 0) << 7);

      break;
    }
  case 4:
    {
      uint32_t state_leds_ctrl_auto = state_leds_ctrl_lock[bank_lock_tmp1];
      uint32_t state_leds_Fx0_auto = state_leds_Fx_lock[bank_lock_tmp1][0];
      uint32_t state_leds_Fx1_auto = state_leds_Fx_lock[bank_lock_tmp1][1];

      state_leds_tmp = ((((state_leds_Fx0_auto >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)(6 - 1))) & (1 << LED_COLOR_RED_BIT)) != 0) << 0) |
                       ((((state_leds_Fx1_auto >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)(1 - 1))) & (1 << LED_COLOR_RED_BIT)) != 0) << 1) |
                       ((((state_leds_Fx1_auto >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)(2 - 1))) & (1 << LED_COLOR_RED_BIT)) != 0) << 2) |
                       ((((state_leds_Fx1_auto >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)(3 - 1))) & (1 << LED_COLOR_RED_BIT)) != 0) << 3) |
                       ((((state_leds_Fx1_auto >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)(4 - 1))) & (1 << LED_COLOR_RED_BIT)) != 0) << 4) |
                       ((((state_leds_Fx1_auto >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)(5 - 1))) & (1 << LED_COLOR_RED_BIT)) != 0) << 5) |
                       ((((state_leds_Fx1_auto >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)(6 - 1))) & (1 << LED_COLOR_RED_BIT)) != 0) << 6) |
                       ((((state_leds_ctrl_auto >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)LED_CTRL_I)) & (1 << LED_COLOR_RED_BIT)) != 0) << 7);
      break;
    }
  case 5:
    {
      uint32_t state_leds_ctrl_auto = state_leds_ctrl_lock[bank_lock_tmp1];
      uint32_t state_leds_Fx0_auto = state_leds_Fx_lock[bank_lock_tmp1][0];
      uint32_t state_leds_Fx1_auto = state_leds_Fx_lock[bank_lock_tmp1][1];

      state_leds_tmp = ((((state_leds_Fx0_auto >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)(6 - 1))) & (1 << LED_COLOR_GREEN_BIT)) != 0) << 0) |
                       ((((state_leds_Fx1_auto >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)(1 - 1))) & (1 << LED_COLOR_GREEN_BIT)) != 0) << 1) |
                       ((((state_leds_Fx1_auto >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)(2 - 1))) & (1 << LED_COLOR_GREEN_BIT)) != 0) << 2) |
                       ((((state_leds_Fx1_auto >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)(3 - 1))) & (1 << LED_COLOR_GREEN_BIT)) != 0) << 3) |
                       ((((state_leds_Fx1_auto >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)(4 - 1))) & (1 << LED_COLOR_GREEN_BIT)) != 0) << 4) |
                       ((((state_leds_Fx1_auto >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)(5 - 1))) & (1 << LED_COLOR_GREEN_BIT)) != 0) << 5) |
                       ((((state_leds_Fx1_auto >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)(6 - 1))) & (1 << LED_COLOR_GREEN_BIT)) != 0) << 6) |
                       ((((state_leds_ctrl_auto >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)LED_CTRL_I)) & (1 << LED_COLOR_GREEN_BIT)) != 0) << 7);
      break;
    }
  case 6:
    {
      uint32_t state_leds_ctrl_auto = state_leds_ctrl_lock[bank_lock_tmp1];

      state_leds_tmp = ((((state_leds_ctrl_auto >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)LED_CTRL_O)) & (1 << LED_COLOR_GREEN_BIT)) != 0) << 7);
      break;
    }
  default:
    {
      //Теоретично цього ніколи не мало б бути
      total_error_sw_fixed();
    }
  }

  //Виводимо інформацію по світлоіндикаторах на світлодіоди
  _DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD32_DD38) = ((1 << current_LED_N_COL) << LED_N_ROW) | ((uint32_t)(~state_leds_tmp) & ((1 << LED_N_ROW) - 1));

  //Переходимо на наступний стовбець
  if (++current_LED_N_COL >= LED_N_COL) 
  {
    current_LED_N_COL = 0;
    bank_lock = bank_lock_tmp2;

    state_leds_lock[bank_lock_tmp1] = 0;
    state_leds_ctrl_lock[bank_lock_tmp1] = 0;
    state_leds_Fx_lock[bank_lock_tmp1][0] = 0;
    state_leds_Fx_lock[bank_lock_tmp1][1] = 0;
  }
  /**************************/
  
  /**************************/
  //
  /**************************/
  /**************************/
}
/*****************************************************/

/*****************************************************/
//Переривання від таймеру TIM2, який обслуговує систему захистів
/*****************************************************/
void TIM2_IRQHandler(void)
{
#ifdef SYSTEM_VIEWER_ENABLE
  SEGGER_SYSVIEW_RecordEnterISR();
#endif
  
  if (TIM_GetITStatus(TIM2, TIM_IT_CC1) != RESET)
  {
    /***********************************************************************************************/
    //Переривання відбулося вік каналу 1, який генерує переривання кожні 1 мс, для опраціьовування таймерів і систем захистів
    /***********************************************************************************************/
    TIM2->SR = (uint16_t)((~(uint32_t)TIM_IT_CC1) & 0xffff);
    uint32_t current_tick = TIM2->CCR1;
    
    /*************************************
    Управління чсом у UNIX-форматі
    *************************************/
    ++clk_count;

    if ( ++time_ms >= 1000) 
    {
      time_ms = 0;
      time_dat++;
    }
      
    if ((save_time_dat_h == 3) || (save_time_dat_l == 3))
    {
      //Процес запису нового часу
      if (save_time_dat_l == 3)
      {
        time_ms = time_ms_save_l;
        time_dat = time_dat_save_l;
        
        save_time_dat_l = 2;
      }
      if (save_time_dat_h == 3)
      {
        time_ms = time_ms_save_h;
        time_dat = time_dat_save_h;
        
        save_time_dat_h = 2;
      }
      
      if (copying_time_to_RTC == 1) copying_time_to_RTC = 0;
      realDateTime = true;
    }
    else 
    {
      //Перевірка чи не потрібно забрати час з RTC
      if (copying_time_to_RTC == 1)
      {
        int32_t diff_ms = time_ms - time_ms_RTC;
        time_t diff_s = time_dat - time_dat_RTC;
        if (diff_ms < 0) 
        {
          diff_ms += 1000;
          --diff_s;
        }
        if (llabs(diff_s*1000 + diff_ms) > 2000)
        {
          time_ms = time_ms_RTC;
          time_dat = time_dat_RTC;
        }
        copying_time_to_RTC = 0;
        realDateTime = true;
      }
    }
    
    
    if (!copying_time_dat)
    {
      time_ms_copy = time_ms;
      time_dat_copy = time_dat;
    }
    /*************************************/

    /***********************************************************/
    //Перевіряємо, чи відбувалися зміни настройок
    /***********************************************************/
    if (changed_settings == CHANGED_ETAP_ENDED) /*Це є умова, що нові дані підготовлені для передачі їх у роботу системою захистів (і при цьому зараз дані не змінюються)*/
    {
      //Копіюємо таблицю настройок у копію цієї таблиці але з якою працює (читає і змінює) тільки система захистів
      current_settings_prt = current_settings;
      
      //Помічаємо, що зміни прийняті системою захистів
      changed_settings = CHANGED_ETAP_NONE;
    }

    if (koef_resurs_changed == CHANGED_ETAP_ENDED)
    {
      //Коефіцієнти для підрахунку ресурсу вимикача
      K_resurs_prt = K_resurs;

      //Помічаємо, що зміни прийняті системою захистів
      koef_resurs_changed = CHANGED_ETAP_NONE;
    }
    /***********************************************************/

    /***********************************************************/
    //Перевіряємо необхідність очистки дискретного реєстраторів
    /***********************************************************/
    if (
        ((clean_rejestrators & CLEAN_DR) != 0)
        &&  
        (
         (control_tasks_dataflash & (
                                     TASK_MAMORY_PAGE_PROGRAM_THROUGH_BUFFER_DATAFLASH_FOR_DR           | 
                                     TASK_MAMORY_READ_DATAFLASH_FOR_DR_USB                              |
                                     TASK_MAMORY_READ_DATAFLASH_FOR_DR_RS485                            |
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
                                     TASK_MAMORY_READ_DATAFLASH_FOR_DR_LAN                              |
#endif  
                                     TASK_MAMORY_READ_DATAFLASH_FOR_DR_MENU                             |
                                     TASK_MAMORY_READ_DATAFLASH_FOR_DR_MENU_SHORT
                                    )
         ) == 0
        )
       )   
    {
      //Виставлено каманда очистити дискретного реєстратор

      //Виставляємо команду запису цієї структури у EEPROM
      _SET_BIT(control_spi1_taskes, TASK_START_WRITE_INFO_REJESTRATOR_DR_EEPROM_BIT);

      //Очищаємо структуру інформації по дискретному реєстраторі
      info_rejestrator_dr.next_address = MIN_ADDRESS_DR_AREA;
      info_rejestrator_dr.saving_execution = 0;
      info_rejestrator_dr.number_records = 0;

      //Помічаємо, що номер запису не вибраний
      number_record_of_dr_for_menu  = 0xffff;
      number_record_of_dr_for_USB   = 0xffff;
      number_record_of_dr_for_RS485 = 0xffff;
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
      number_record_of_dr_for_LAN = 0xffff;
#endif  

      //Знімаємо команду очистки дискретного реєстратора
      clean_rejestrators &= (unsigned int)(~CLEAN_DR);
    }
    /***********************************************************/

    /***********************************************************/
    //Опрцювання логічних тайменрів і дискретних входів тільки коли настройки успішно прочитані
    /***********************************************************/
    clocking_global_timers();
    /***********************************************************/
    
    /***********************************************************/
    //Опрцювання функцій захистів
    /***********************************************************/
    //Діагностика вузлів, яку треба проводити кожен раз перед початком опрацьовуванням логіки пристрою
    uint32_t TIM_PRT_read_tick = TIM2->CNT;

    uint64_t TIM_PRT_delta_write_read;
    if (TIM_PRT_read_tick < TIM_PRT_write_tick)
      TIM_PRT_delta_write_read = (uint64_t)TIM_PRT_read_tick + 0x100000000ull - (uint64_t)TIM_PRT_write_tick;
    else TIM_PRT_delta_write_read = TIM_PRT_read_tick - TIM_PRT_write_tick;
    if (TIM_PRT_delta_write_read > (TIM2_MIN_PERIOD_WRITE_READ + 1))
    {
#if (                                   \
     (MODYFIKACIA_VERSII_PZ == 5) ||    \
     (MODYFIKACIA_VERSII_PZ == 15)      \
    )                                   
      unsigned int control_state_outputs =    ((~((unsigned int)(_DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD31_DD34_DD35_DD37)     ))) & 0xffff)
                                           | (((~((unsigned int)(_DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD28_DD30          ) >> 8))) & 0xf   ) << 16);
#else
      unsigned int control_state_outputs = ((~((unsigned int)(_DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD31_DD34_DD35_DD37)))) & 0xffff);

#ifdef NUMBER_DS
      unsigned int control_ds =  (~((unsigned int)(_DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD28_DD30) >> 8))) & (MASKA_FOR_BIT(NUMBER_DS) - 1);
#endif
      
#endif
     

      static uint32_t error_rele[NUMBER_OUTPUTS];
      if (control_state_outputs != state_outputs_raw)
      {
        for (size_t index = 0; index < NUMBER_SIMPLE_OUTPUTS; ++index)
        {
          uint32_t maska = 1 << index;
        
          if ((control_state_outputs & maska) != (state_outputs_raw & maska))
          {
            if (error_rele[index] < 3) ++error_rele[index];
            if (error_rele[index] >= 3 ) _SET_BIT(set_diagnostyka, (ERROR_DIGITAL_OUTPUT_1_BIT + index));
          }
          else error_rele[index] = 0;
        }
      }
      else
      {
        for (size_t index = 0; index < NUMBER_SIMPLE_OUTPUTS; ++index) error_rele[index] = 0;
      }

#ifdef NUMBER_DS
      if (control_ds != ds)  
      {
        for (size_t index = 0; index < NUMBER_DS; ++index)
        {
          uint32_t maska = 1 << index;
        
          if ((control_ds & maska) != (ds & maska))
          {
            if (error_rele[NUMBER_SIMPLE_OUTPUTS + index] < 3) ++error_rele[NUMBER_SIMPLE_OUTPUTS + index];
            if (error_rele[NUMBER_SIMPLE_OUTPUTS + index] >= 3 ) _SET_BIT(set_diagnostyka, (ERROR_DS_OUTPUT_BIT + index));
          }
          else error_rele[NUMBER_SIMPLE_OUTPUTS + index] = 0;
        }
      }
      else
      {
        for (size_t index = 0; index < NUMBER_DS; ++index) error_rele[NUMBER_SIMPLE_OUTPUTS + index] = 0;
      }
#endif
    }
    
    //Діагностика необхідно-приєднаних плат
    {
      unsigned int diagnostyka_tmp[N_DIAGN];
      for (size_t i = 0; i < N_DIAGN; i ++)
      {
        diagnostyka_tmp[i] = diagnostyka[i];

        diagnostyka_tmp[i] &= (unsigned int)(~clear_diagnostyka[i]); 
        diagnostyka_tmp[i] |= set_diagnostyka[i]; 
      }
      
      uint32_t board_register_tmp = _DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD39_DD40_DD47);
      uint32_t board_register_diff = board_register_tmp ^ board_register;
      board_register = board_register_tmp;

      if ((board_register_tmp & 0x01) !=  0x1) _SET_BIT(set_diagnostyka, ERROR_BA_1_FIX);
      else if ((board_register_diff & 0x01) || _CHECK_SET_BIT(diagnostyka_tmp, ERROR_BA_1_CTLR))
      {
        _SET_BIT(clear_diagnostyka, ERROR_BA_1_FIX);
        _DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD39_DD40_DD47) = 0x1;
        if ((_DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD39_DD40_DD47) >> 8) != 0x11)  _SET_BIT(set_diagnostyka, ERROR_BA_1_CTLR);
        else _SET_BIT(clear_diagnostyka, ERROR_BA_1_CTLR);
        _DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD39_DD40_DD47) = 0x0;
      }
      
      if ((board_register_tmp & 0x02) !=  0x2) _SET_BIT(set_diagnostyka, ERROR_BDVV5_1_FIX);
      else if ((board_register_diff & 0x02) || _CHECK_SET_BIT(diagnostyka_tmp, ERROR_BDVV5_1_CTLR))
      {
        _SET_BIT(clear_diagnostyka, ERROR_BDVV5_1_FIX);
        _DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD39_DD40_DD47) = 0x2;
        if ((_DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD33_DD36) & 0xff) != 0x25)  _SET_BIT(set_diagnostyka, ERROR_BDVV5_1_CTLR);
        else _SET_BIT(clear_diagnostyka, ERROR_BDVV5_1_CTLR);
        _DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD39_DD40_DD47) = 0x0;
      }
      
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
      if ((board_register_tmp & 0x08) !=  0x8) _SET_BIT(set_diagnostyka, ERROR_CB_FIX);
      else if (board_register_diff & 0x08)
      {
        _SET_BIT(clear_diagnostyka, ERROR_CB_FIX);
      }
#endif

#if (                                \
     (MODYFIKACIA_VERSII_PZ == 0) || \
     (MODYFIKACIA_VERSII_PZ == 1) || \
     (MODYFIKACIA_VERSII_PZ == 3) || \
     (MODYFIKACIA_VERSII_PZ == 5) || \
     (MODYFIKACIA_VERSII_PZ == 10)|| \
     (MODYFIKACIA_VERSII_PZ == 11)|| \
     (MODYFIKACIA_VERSII_PZ == 13)|| \
     (MODYFIKACIA_VERSII_PZ == 15)|| \
     (MODYFIKACIA_VERSII_PZ == 23)|| \
     (MODYFIKACIA_VERSII_PZ == 33)   \
    )
      if ((board_register_tmp & 0x04) !=  0x4) _SET_BIT(set_diagnostyka, ERROR_BDVV5_2_FIX);
      else if ((board_register_diff & 0x04) || _CHECK_SET_BIT(diagnostyka_tmp, ERROR_BDVV5_2_CTLR))
      {
        _SET_BIT(clear_diagnostyka, ERROR_BDVV5_2_FIX);
        _DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD39_DD40_DD47) = 0x4;
        if ((_DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD33_DD36) >> 8) != 0x37)  _SET_BIT(set_diagnostyka, ERROR_BDVV5_2_CTLR);
        else _SET_BIT(clear_diagnostyka, ERROR_BDVV5_2_CTLR);
        _DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD39_DD40_DD47) = 0x0;
      }
#elif (                                \
       (MODYFIKACIA_VERSII_PZ == 6) || \
       (MODYFIKACIA_VERSII_PZ == 26)   \
      )
      if ((board_register_tmp & 0x04) !=  0x4) _SET_BIT(set_diagnostyka, ERROR_BDVV9_FIX);
      else if ((board_register_diff & 0x04) || _CHECK_SET_BIT(diagnostyka_tmp, ERROR_BDVV9_CTLR))
      {
        _SET_BIT(clear_diagnostyka, ERROR_BDVV9_FIX);
        _DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD39_DD40_DD47) = 0x4;
        if ((_DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD33_DD36) >> 8) != 0x29)  _SET_BIT(set_diagnostyka, ERROR_BDVV9_CTLR);
        else _SET_BIT(clear_diagnostyka, ERROR_BDVV9_CTLR);
        _DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD39_DD40_DD47) = 0x0;
      }
#endif

#if (                                   \
       (MODYFIKACIA_VERSII_PZ == 0) ||  \
       (MODYFIKACIA_VERSII_PZ == 3) ||  \
       (MODYFIKACIA_VERSII_PZ == 4) ||  \
       (MODYFIKACIA_VERSII_PZ == 5) ||  \
       (MODYFIKACIA_VERSII_PZ == 6) ||  \
       (MODYFIKACIA_VERSII_PZ == 10)||  \
       (MODYFIKACIA_VERSII_PZ == 13)||  \
       (MODYFIKACIA_VERSII_PZ == 14)||  \
       (MODYFIKACIA_VERSII_PZ == 15)||  \
       (MODYFIKACIA_VERSII_PZ == 23)||  \
       (MODYFIKACIA_VERSII_PZ == 24)||  \
       (MODYFIKACIA_VERSII_PZ == 26)||  \
       (MODYFIKACIA_VERSII_PZ == 33)||  \
       (MODYFIKACIA_VERSII_PZ == 34)    \
      )   
      if ((board_register_tmp & 0x010) != 0x10) 
      
#if (                                   \
     (MODYFIKACIA_VERSII_PZ == 0) ||    \
     (MODYFIKACIA_VERSII_PZ == 10)      \
    )    
        _SET_BIT(set_diagnostyka, ERROR_BDV_DZ_FIX);
#elif (                                 \
       (MODYFIKACIA_VERSII_PZ == 5) ||  \
       (MODYFIKACIA_VERSII_PZ == 15)    \
      )   
        _SET_BIT(set_diagnostyka, ERROR_BDVV6_FIX);
#elif (                                 \
       (MODYFIKACIA_VERSII_PZ == 3) ||  \
       (MODYFIKACIA_VERSII_PZ == 4) ||  \
       (MODYFIKACIA_VERSII_PZ == 6) ||  \
       (MODYFIKACIA_VERSII_PZ == 13)||  \
       (MODYFIKACIA_VERSII_PZ == 14)    \
      )
        _SET_BIT(set_diagnostyka, ERROR_BDZ_FIX);
#elif (                                 \
       (MODYFIKACIA_VERSII_PZ == 23) || \
       (MODYFIKACIA_VERSII_PZ == 24) || \
       (MODYFIKACIA_VERSII_PZ == 26) || \
       (MODYFIKACIA_VERSII_PZ == 33) || \
       (MODYFIKACIA_VERSII_PZ == 34)    \
      )
        _SET_BIT(set_diagnostyka, ERROR_BDSH_FIX);
#else
 #error  "UDEFINED MODIFIKACIA"
#endif
      else if (
               (board_register_diff & 0x10)
#if (                                   \
     (MODYFIKACIA_VERSII_PZ == 0) ||    \
     (MODYFIKACIA_VERSII_PZ == 10)      \
    )                                   
               || _CHECK_SET_BIT(diagnostyka_tmp, ERROR_BDV_DZ_CTLR)
              )
      {
        _SET_BIT(clear_diagnostyka, ERROR_BDV_DZ_FIX);
#elif (                                 \
       (MODYFIKACIA_VERSII_PZ == 5) ||  \
       (MODYFIKACIA_VERSII_PZ == 15)    \
      )   
               || _CHECK_SET_BIT(diagnostyka_tmp, ERROR_BDVV6_CTLR)
              )
      {
        _SET_BIT(clear_diagnostyka, ERROR_BDVV6_FIX);
#elif (                                 \
       (MODYFIKACIA_VERSII_PZ == 3) ||  \
       (MODYFIKACIA_VERSII_PZ == 4) ||  \
       (MODYFIKACIA_VERSII_PZ == 6) ||  \
       (MODYFIKACIA_VERSII_PZ == 13)||  \
       (MODYFIKACIA_VERSII_PZ == 14)    \
      )
               || _CHECK_SET_BIT(diagnostyka_tmp, ERROR_BDZ_CTLR)
              )
      {
        _SET_BIT(clear_diagnostyka, ERROR_BDZ_FIX);
#elif (                                 \
       (MODYFIKACIA_VERSII_PZ == 23) || \
       (MODYFIKACIA_VERSII_PZ == 24) || \
       (MODYFIKACIA_VERSII_PZ == 26) || \
       (MODYFIKACIA_VERSII_PZ == 33) || \
       (MODYFIKACIA_VERSII_PZ == 34)    \
      )
               || _CHECK_SET_BIT(diagnostyka_tmp, ERROR_BDSH_CTLR)
              )
      {
        _SET_BIT(clear_diagnostyka, ERROR_BDSH_FIX);
#else
              )
      {
 #error  "UDEFINED MODIFIKACIA"
#endif

        _DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD39_DD40_DD47) = 0x10;

#if (                                   \
     (MODYFIKACIA_VERSII_PZ == 0) ||    \
     (MODYFIKACIA_VERSII_PZ == 10)      \
    )                                   
        if ((_DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD26_DD29) >> 8) != 0x14)  _SET_BIT(set_diagnostyka, ERROR_BDV_DZ_CTLR);
        else _SET_BIT(clear_diagnostyka, ERROR_BDV_DZ_CTLR);
#elif (                                 \
       (MODYFIKACIA_VERSII_PZ == 5) ||  \
       (MODYFIKACIA_VERSII_PZ == 15)    \
      )   
        if ((_DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD26_DD29) >> 8) != 0x12)  _SET_BIT(set_diagnostyka, ERROR_BDVV6_CTLR);
        else _SET_BIT(clear_diagnostyka, ERROR_BDVV6_CTLR);
#elif (                                 \
       (MODYFIKACIA_VERSII_PZ == 3) ||  \
       (MODYFIKACIA_VERSII_PZ == 4) ||  \
       (MODYFIKACIA_VERSII_PZ == 6) ||  \
       (MODYFIKACIA_VERSII_PZ == 13)||  \
       (MODYFIKACIA_VERSII_PZ == 14)    \
      )
        if ((_DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD26_DD29) >> 8) != 0x18)  _SET_BIT(set_diagnostyka, ERROR_BDZ_CTLR);
        else _SET_BIT(clear_diagnostyka, ERROR_BDZ_CTLR);
#elif (                                 \
       (MODYFIKACIA_VERSII_PZ == 23)||  \
       (MODYFIKACIA_VERSII_PZ == 24)||  \
       (MODYFIKACIA_VERSII_PZ == 26)||  \
       (MODYFIKACIA_VERSII_PZ == 33)||  \
       (MODYFIKACIA_VERSII_PZ == 34)    \
      )
        if ((_DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD26_DD29) >> 8) != 0x13)  _SET_BIT(set_diagnostyka, ERROR_BDSH_CTLR);
        else _SET_BIT(clear_diagnostyka, ERROR_BDSH_CTLR);
#else
 #error  "UDEFINED MODIFIKACIA"
#endif

        _DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD39_DD40_DD47) = 0x0;
      }
#endif
    }

    //Функції захистів
    main_protection();
    
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
    /***
    Очікування, щоб попередній пакет гарантовано завершив передаватися
    ***/
//    while ((DMA_StreamCANAL1_MO_Tx->CR & DMA_IT_TC) != 0);
    while (DMA_StreamCANAL1_MO_Tx->NDTR != 0);

//    uint32_t tick_for_Canal_1_tmp = tick_for_Canal_1;
    uint32_t tick_for_Canal_1_tmp = TIM2->CNT;
    uint64_t delta_tmp = 0;
    do
    {
      uint32_t tick_tmp = TIM2->CNT;
      delta_tmp = (tick_tmp < tick_for_Canal_1_tmp) ? ((uint64_t)tick_tmp + 0x100000000llu - (uint64_t)tick_for_Canal_1_tmp) : (tick_tmp - tick_for_Canal_1_tmp);
    }
    while(delta_tmp < 2);
    /***/

    if (
        (_CHECK_SET_BIT(    diagnostyka, WARNING_REPROGRAM) == 0) &&
        (_CHECK_SET_BIT(set_diagnostyka, WARNING_REPROGRAM) == 0)
       )   
    {
      //Ініціюємо передачу даних по каналу CANAL1_MO у комунікаційну плату
      start_transmint_data_via_CANAL1_MO();
    }
#endif
    /***********************************************************/

    /***********************************************************/
    //Перевірка на необхідність зроботи резервні копії даних для самоконтролю
    /***********************************************************/
    //Триґерна інформація
    if (periodical_tasks_TEST_TRG_FUNC != 0)
    {
      //Стоїть у черзі активна задача зроботи резервні копії даних
      if ((state_spi1_task & STATE_TRG_FUNC_EEPROM_GOOD) != 0)
      {
        //Робимо копію тільки тоді, коли триґерна інформація успішно зчитана і сформована контрольна сума
        if (
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_WRITE_TRG_FUNC_EEPROM_BIT) == 0) &&
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_TRG_FUNC_EEPROM_BIT    ) == 0) &&
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_TRG_FUNC_EEPROM_BIT ) == 0) &&
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_TRG_FUNC_EEPROM_BIT    ) == 0)
           ) 
        {
          //На даний моммент не іде читання-запис триґерної інформації, тому можна здійснити копіювання
          fix_active_buttons_ctrl = fix_active_buttons;
          for (unsigned int i = 0; i < N_BIG; i++) trigger_active_functions_ctrl[i] = trigger_active_functions[i];
          crc_trg_func_ctrl = crc_trg_func;

          //Скидаємо активну задачу формування резервної копії 
          periodical_tasks_TEST_TRG_FUNC = false;
          //Виставляємо активну задачу контролю достовірності по резервній копії 
          periodical_tasks_TEST_TRG_FUNC_LOCK = true;
        }
      }
      else
      {
        //Скидаємо активну задачу формування резервної копії 
        periodical_tasks_TEST_TRG_FUNC = false;
      }
    }

    //Аналоговий реєстратор
    if (periodical_tasks_TEST_INFO_REJESTRATOR_AR != 0)
    {
      //Стоїть у черзі активна задача зроботи резервні копії даних
      if ((state_spi1_task & STATE_INFO_REJESTRATOR_AR_EEPROM_GOOD) != 0)
      {
        //Робимо копію тільки тоді, коли структура інформації реєстратора успішно зчитана і сформована контрольна сума
        if (
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_WRITE_INFO_REJESTRATOR_AR_EEPROM_BIT) == 0) &&
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_INFO_REJESTRATOR_AR_EEPROM_BIT    ) == 0) &&
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_INFO_REJESTRATOR_AR_EEPROM_BIT ) == 0) &&
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_INFO_REJESTRATOR_AR_EEPROM_BIT    ) == 0)
           ) 
        {
          //На даний моммент не іде читання-запис структури інформації реєстратора, тому можна здійснити копіювання
          info_rejestrator_ar_ctrl = info_rejestrator_ar;
          crc_info_rejestrator_ar_ctrl = crc_info_rejestrator_ar;

          //Скидаємо активну задачу формування резервної копії 
          periodical_tasks_TEST_INFO_REJESTRATOR_AR = false;
          //Виставляємо активну задачу контролю достовірності по резервній копії 
          periodical_tasks_TEST_INFO_REJESTRATOR_AR_LOCK = true;
        }
      }
      else
      {
        //Скидаємо активну задачу формування резервної копії 
        periodical_tasks_TEST_INFO_REJESTRATOR_AR = false;
      }
    }

    //Дискретний реєстратор
    if (periodical_tasks_TEST_INFO_REJESTRATOR_DR != 0)
    {
      //Стоїть у черзі активна задача зроботи резервні копії даних
      if ((state_spi1_task & STATE_INFO_REJESTRATOR_DR_EEPROM_GOOD) != 0)
      {
        //Робимо копію тільки тоді, коли структура інформації реєстратора успішно зчитана і сформована контрольна сума
        if (
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_WRITE_INFO_REJESTRATOR_DR_EEPROM_BIT) == 0) &&
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_INFO_REJESTRATOR_DR_EEPROM_BIT    ) == 0) &&
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_INFO_REJESTRATOR_DR_EEPROM_BIT ) == 0) &&
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_INFO_REJESTRATOR_DR_EEPROM_BIT    ) == 0)
           ) 
        {
          //На даний моммент не іде читання-запис структури інформації реєстратора, тому можна здійснити копіювання
          info_rejestrator_dr_ctrl = info_rejestrator_dr;
          crc_info_rejestrator_dr_ctrl = crc_info_rejestrator_dr;

          //Скидаємо активну задачу формування резервної копії 
          periodical_tasks_TEST_INFO_REJESTRATOR_DR = false;
          //Виставляємо активну задачу контролю достовірності по резервній копії 
          periodical_tasks_TEST_INFO_REJESTRATOR_DR_LOCK = true;
        }
      }
      else
      {
        //Скидаємо активну задачу формування резервної копії 
        periodical_tasks_TEST_INFO_REJESTRATOR_DR = false;
      }
    }
    /***********************************************************/

    //Лічильник ресурсу
    if (periodical_tasks_TEST_RESURS != 0)
    {
      //Стоїть у черзі активна задача зроботи резервні копії даних
      if ((state_spi1_task & STATE_RESURS_EEPROM_GOOD) != 0)
      {
        //Робимо копію тільки тоді, коли інформаціz успішно зчитана і сформована контрольна сума
        if (
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_WRITE_RESURS_EEPROM_BIT) == 0) &&
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_RESURS_EEPROM_BIT    ) == 0) &&
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_RESURS_EEPROM_BIT ) == 0) &&
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_RESURS_EEPROM_BIT    ) == 0)
           ) 
        {
          //На даний моммент не іде читання-запис ресурсу вимикача, тому можна здійснити копіювання
          resurs_vymykacha_ctrl = resurs_vymykacha;          
          resurs_vidkljuchennja_ctrl = resurs_vidkljuchennja;
          crc_resurs_ctrl = crc_resurs;

          //Скидаємо активну задачу формування резервної копії 
          periodical_tasks_TEST_RESURS = false;
          //Виставляємо активну задачу контролю достовірності по резервній копії 
          periodical_tasks_TEST_RESURS_LOCK = true;
        }
      }
      else
      {
        //Скидаємо активну задачу формування резервної копії 
        periodical_tasks_TEST_RESURS = false;
      }
    }

    /***********************************************************/
    //Встановлюємо "значення лічильника для наступного переривання"
    /***********************************************************/
    uint32_t capture_new;
    unsigned int delta;
    TIM2->CCR1 = (capture_new = (current_tick + (delta = TIM2_CCR1_VAL)));
    
    unsigned int repeat;
    unsigned int previous_tick = current_tick;
    do
    {
      repeat = 0;
      current_tick = TIM2->CNT;

      uint64_t delta_time = 0;
      if (capture_new < current_tick)
        delta_time = (uint64_t)capture_new + 0x100000000ull - (uint64_t)current_tick;
      else delta_time = capture_new - current_tick;

      if ((delta_time > delta) || (delta_time == 0))
      {
        if (TIM_GetITStatus(TIM2, TIM_IT_CC1) == RESET)
        {
          if (delta < TIM2_CCR1_VAL)
          {
            uint64_t delta_tick;
            if (current_tick < previous_tick)
              delta_tick = (uint64_t)current_tick + 0x100000000ull - (uint64_t)previous_tick;
            else delta_tick = current_tick - previous_tick;
              
            delta = delta_tick + 1;
          }
          else if (delta == TIM2_CCR1_VAL)
            delta = 1; /*Намагаємося, щоб нове переивання запустилося як омога скоріше*/
          else
          {
            //Теоретично цього ніколи не мало б бути
            total_error_sw_fixed();
          }
          TIM2->CCR1 = (capture_new = (TIM2->CNT +  delta));
          previous_tick = current_tick;
          repeat = 0xff;
        }
      }
    }
    while (repeat != 0);
    /***********************************************************/
    
    /***********************************************************/
    //Виставляємо повідомлення про те, система захисів праціює
    /***********************************************************/
    control_word_of_watchdog |= WATCHDOG_PROTECTION;
    /***********************************************************/
    /***********************************************************************************************/
  }
  else
  {
    total_error_sw_fixed();
  }
  
#ifdef SYSTEM_VIEWER_ENABLE
  SEGGER_SYSVIEW_RecordExitISR();
#endif
}
/*****************************************************/

/*****************************************************/
//Вибір групи уставок
/*****************************************************/
void setpoints_selecting(unsigned int *p_active_functions, unsigned int act_inp_gr_ustavok) {
  unsigned int grupa_ustavok = 0;
  act_inp_gr_ustavok &= 0xf;
  if (current_settings_prt.grupa_ustavok < SETPOINT_GRUPA_USTAVOK_MIN ||
      current_settings_prt.grupa_ustavok > SETPOINT_GRUPA_USTAVOK_MAX) {
    //Неопределенная ошибка
    while (1);
  } else {
    grupa_ustavok = 1 << (current_settings_prt.grupa_ustavok - 1);
  }
  
  if (_CHECK_SET_BIT(p_active_functions, RNG_BIG_INVERS_DV_GRUPA_USTAVOK)) _SET_STATE(act_inp_gr_ustavok, 4);
  
  _AND2(grupa_ustavok, 0, act_inp_gr_ustavok, 4, grupa_ustavok, 4);
  _AND2(grupa_ustavok, 1, act_inp_gr_ustavok, 4, grupa_ustavok, 5);
  _AND2(grupa_ustavok, 2, act_inp_gr_ustavok, 4, grupa_ustavok, 6);
  _AND2(grupa_ustavok, 3, act_inp_gr_ustavok, 4, grupa_ustavok, 7);
  
  unsigned int tmp = gr_ustavok_tmp;
  do {
    _AND4(act_inp_gr_ustavok, 0, gr_ustavok_tmp, 1, gr_ustavok_tmp, 2, gr_ustavok_tmp, 3, act_inp_gr_ustavok, 5);
    _INVERTOR(act_inp_gr_ustavok, 5, tmp, 0);
    
    _AND4(tmp, 0, act_inp_gr_ustavok, 1, tmp, 2, tmp, 3, act_inp_gr_ustavok, 6);
    _INVERTOR(act_inp_gr_ustavok, 6, tmp, 1);
    
    _AND4(tmp, 0, tmp, 1, act_inp_gr_ustavok, 2, tmp, 3, act_inp_gr_ustavok, 7);
    _INVERTOR(act_inp_gr_ustavok, 7, tmp, 2);
    
    _AND4(tmp, 0, tmp, 1, tmp, 2, act_inp_gr_ustavok, 3, act_inp_gr_ustavok, 8);
    _INVERTOR(act_inp_gr_ustavok, 8, tmp, 3);
    if (tmp == gr_ustavok_tmp) {
      break;
    }
    gr_ustavok_tmp = tmp;
  } while (1);
  
  _OR2(grupa_ustavok, 4, act_inp_gr_ustavok, 5, grupa_ustavok, 8);
  _OR2(grupa_ustavok, 5, act_inp_gr_ustavok, 6, grupa_ustavok, 9);
  _OR2(grupa_ustavok, 6, act_inp_gr_ustavok, 7, grupa_ustavok, 10);
  _OR2(grupa_ustavok, 7, act_inp_gr_ustavok, 8, grupa_ustavok, 11);
  
  if (_GET_STATE(grupa_ustavok, 8)) 
    _SET_BIT(p_active_functions, RNG_BIG_1_GRUPA_USTAVOK);
  else
    _CLEAR_BIT(p_active_functions, RNG_BIG_1_GRUPA_USTAVOK);

  if (_GET_STATE(grupa_ustavok, 9))
    _SET_BIT(p_active_functions, RNG_BIG_2_GRUPA_USTAVOK);
  else
    _CLEAR_BIT(p_active_functions, RNG_BIG_2_GRUPA_USTAVOK);

  if (_GET_STATE(grupa_ustavok, 10))
      _SET_BIT(p_active_functions, RNG_BIG_3_GRUPA_USTAVOK);
  else
    _CLEAR_BIT(p_active_functions, RNG_BIG_3_GRUPA_USTAVOK);

  if (_GET_STATE(grupa_ustavok, 11))
      _SET_BIT(p_active_functions, RNG_BIG_4_GRUPA_USTAVOK);
  else
    _CLEAR_BIT(p_active_functions, RNG_BIG_4_GRUPA_USTAVOK);
}
/*****************************************************/
#include "mtzo.c"
#include "dzo.c"
#include "mtzr.c"
#include "dzr.c"
#include "up.c"

/*****************************************************/
