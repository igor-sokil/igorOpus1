#include "header.h"

/*****************************************************/
//Формуємо екран відображення заголовків реєстраторів
/*****************************************************/
void make_ekran_list_registrators(void)
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_LIST_REGISTRATORS][MAX_COL_LCD] = 
  {
    {
      " Аналог.рег-р   ",
      " Дискр. рег-р   ",
      " Архив диагност."
    },
    {
      " Аналог.реєстр. ",
      " Дискр. реєстр. ",
      " Архів діагност."
    },
    {
      " Dst recorder   ",
      " Binary recorder",
      " Diag recorder  "
    },
    {
      " Аналог.рег-р   ",
      " Дискр. рег-р   ",
      " Архив диагност."
    }
  };

  int index_language = index_language_in_array(current_settings.language);
  
  unsigned int position_temp = current_ekran.index_position;
  unsigned int index_of_ekran;
  
  
  index_of_ekran = (position_temp >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;

  
  //Копіюємо  рядки у робочий екран
  for (unsigned int i=0; i< MAX_ROW_LCD; i++)
  {
    //Наступні рядки треба перевірити, чи їх требе відображати у текучій коффігурації
    if (index_of_ekran < MAX_ROW_FOR_LIST_REGISTRATORS)
      for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_language][index_of_ekran][j];
    else
      for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = ' ';

    index_of_ekran++;
  }

  //Курсор по горизонталі відображається на першій позиції
  current_ekran.position_cursor_x = 0;
  //Відображення курору по вертикалі
  current_ekran.position_cursor_y = position_temp & (MAX_ROW_LCD - 1);
  //Курсор видимий
  current_ekran.cursor_on = 1;
  //Курсор не мигає
  current_ekran.cursor_blinking_on = 0;
  //Обновити повністю весь екран
  current_ekran.current_action = ACTION_WITH_CARRENT_EKRANE_FULL_UPDATE;
}
/*****************************************************/

/*****************************************************/
//Формуємо екран відображення записів аналогового реєстратора
/*****************************************************/
void make_ekran_list_records_registrator_ar()
{
  int index_language = index_language_in_array(current_settings.language);
  
  unsigned int position_temp = current_ekran.index_position;

  unsigned int number_records;
  unsigned int first_number = (info_rejestrator_ar.first_number < 0) ? 0 : (info_rejestrator_ar.first_number + 1);
  unsigned int last_number  = (info_rejestrator_ar.last_number  < 0) ? 0 : (info_rejestrator_ar.last_number + 1);
                
  if (first_number == 0) number_records = 0;
  else if (first_number >= last_number) number_records = first_number - last_number + 1;
  else number_records = NUMBER_FATFS_NAME - last_number + first_number + 1;
  
  unsigned int error_reading = false;
  if(number_records == 0)
  {
    //Немає записів
    static const unsigned char information[MAX_NAMBER_LANGUAGE][2][MAX_COL_LCD] = 
    {
      {
        "      Нет       ",
        "    записей     "
      },
      {
        "     Нема       ",
        "    записів     "
      },
      {
        "    Records     ",
        "   are absent   "
      },
      {
        "      Нет       ",
        "    записей     "
      }
    };
    
    unsigned char const (*const pArr)[MAX_COL_LCD] = information[index_language];
    for (size_t i = 0; i != MAX_ROW_LCD; ++i)
    {
      for (size_t j = 0; j != MAX_COL_LCD; j++) working_ekran[i][j] = (i < 2) ? pArr[i][j] : ' ';
    }
    
    //Курсор не видимий
    current_ekran.cursor_on = 0;
    position_temp = 0;
  }
  else if (
            (state_ar_record_fatfs != STATE_AR_NONE_FATFS) &&
            (state_ar_record_fatfs != STATE_AR_MEMORY_FULL_FATFS) &&
            (state_ar_record_fatfs != STATE_AR_BLOCK_FATFS)
           )   
  {
    //Читання тимчасово  недоступне
    
    static const unsigned char information[MAX_NAMBER_LANGUAGE][2][MAX_COL_LCD] = 
    {
      {
        " Процесс чтения ",
        "  не завершен   "
      },
      {
        " Процес читання ",
        " не завершений  "
      },
      {
        "    Reading     ",
        "is not completed"
      },
      {
        " Процесс чтения ",
        "  не завершен   "
      }
    };
    
    unsigned char const (*const pArr)[MAX_COL_LCD] = information[index_language];
    for (size_t i = 0; i != MAX_ROW_LCD; ++i)
    {
      for (size_t j = 0; j != MAX_COL_LCD; j++) working_ekran[i][j] = (i < 2) ? pArr[i][j] : ' ';
    }

    //Курсор не видимий
    current_ekran.cursor_on = 0;
    position_temp = 0;
  }
  else if (current_ekran.index_position < ((int)number_records))
  {
    static unsigned char const template_string[2][MAX_COL_LCD] = 
    {
      "   XX-XX-20XX   ",
      "  XX:XX:XX.XXX  "
    };
    
    //Множення на два величини position_temp потрібне для того, бо на одну позицію ми використовуємо два рядки (назва + значення)
    unsigned int index_of_ekran = ((position_temp << 1) >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;

    unsigned int k = 0;
    unsigned int index_of_ekran_tmp = index_of_ekran >> 1;
    while ( ((index_of_ekran_tmp + k) < number_records) && (k < ( MAX_ROW_FOR_LIST_REGISTRATORS_RECORDS >> 1)) ) 
    {
      unsigned int n_record = index_of_ekran_tmp + k;
      time_t time_dat_tmp = 0;
      int32_t time_ms_tmp = 0;

      int record_name = info_rejestrator_ar.first_number - n_record;
      if (record_name < 0) record_name += NUMBER_FATFS_NAME;

      char str[8 + 1 + 3 + 1];
      int n = snprintf(str, (8 + 1), "%d", record_name);
      if (n > 8) n = 8; //Теоретично цього ніколи б не мало бути
      str[n++] = '.';
      str[n++] = 'd';
      str[n++] = 'a';
      str[n++] = 't';
      str[n++] = '\0';
        
      FIL fil;
      FRESULT res = f_open(&fil, str, FA_READ);
      if (res == FR_OK) 
      {
        res = f_lseek(&fil, 0);
        if (res == FR_OK)
        {
          unsigned int read_tmp;
          res = f_read(&fil, buffer_for_manu_read_record, sizeof(__HEADER_AR), &read_tmp);
          if (
              (res == FR_OK) &&
              (read_tmp == sizeof(__HEADER_AR))
               
             )
          {
            if (buffer_for_manu_read_record[0] == LABEL_START_RECORD_AR) 
            {
              __HEADER_AR header_ar_tmp;
              /*
              У перших байтах зчитаного буферу є заголовок аналоговог ореєстратора.
              Для зручності на цю адресу ставим структуру заголовку аналогового реєстратора
              щоб легше було можливість читати поля
              */
              header_ar_tmp = *((__HEADER_AR*)buffer_for_manu_read_record);
              time_dat_tmp = header_ar_tmp.time_dat;
              time_ms_tmp = header_ar_tmp.time_ms;
            }
            else
            {
              error_reading = true;
              break;
            }
          }
          else
          {
            //Невизначена ситуація, якої ніколи б не мало бути.
            _SET_BIT(set_diagnostyka, ERROR_AR_UNDEFINED_BIT);
            error_reading = true;
            break;
          }
        }
        else
        {
          //Невизначена ситуація, якої ніколи б не мало бути.
          _SET_BIT(set_diagnostyka, ERROR_AR_UNDEFINED_BIT);
          error_reading = true;
          break;
        }
          
              
        res = f_close(&fil);
        if (res != FR_OK) 
        {
          //Невизначена ситуація, якої ніколи б не мало бути.
          _SET_BIT(set_diagnostyka, ERROR_AR_UNDEFINED_BIT);
        }
      }
      else 
      {
        //Невизначена ситуація, якої ніколи б не мало бути.
        _SET_BIT(set_diagnostyka, ERROR_AR_UNDEFINED_BIT);
        error_reading = true;
        break;
      }
        

      //Копіюємо  рядки у робочий екран
      for (size_t i = 0; i != 2; ++i)
      {
          for (size_t j = 0; j != MAX_COL_LCD; ++j) working_ekran[2*k + i][j] = template_string[i][j];
      }
      if (time_dat_tmp != 0)
      {
        struct tm *p = localtime(&time_dat_tmp);
        int field;
      
        //День
        field = p->tm_mday;
        working_ekran[2*k + ROW_R_Y_][COL_DY1_R] = (field / 10) + 0x30;
        working_ekran[2*k + ROW_R_Y_][COL_DY2_R] = (field % 10) + 0x30;

        //Місяць
        field = p->tm_mon + 1;
        working_ekran[2*k + ROW_R_Y_][COL_MY1_R] = (field / 10) + 0x30;
        working_ekran[2*k + ROW_R_Y_][COL_MY2_R] = (field % 10) + 0x30;

        //Рік
        field = p->tm_year - 100;
        working_ekran[2*k + ROW_R_Y_][COL_SY1_R] = (field / 10) + 0x30;
        working_ekran[2*k + ROW_R_Y_][COL_SY2_R] = (field % 10) + 0x30;

        //Година
        field = p->tm_hour;
        working_ekran[2*k + ROW_R_T_][COL_HT1_R] = (field / 10) + 0x30;
        working_ekran[2*k + ROW_R_T_][COL_HT2_R] = (field % 10) + 0x30;

        //Хвилини
        field = p->tm_min;
        working_ekran[2*k + ROW_R_T_][COL_MT1_R] = (field / 10) + 0x30;
        working_ekran[2*k + ROW_R_T_][COL_MT2_R] = (field % 10) + 0x30;

        //Секунди
        field = p->tm_sec;
        working_ekran[2*k + ROW_R_T_][COL_ST1_R] = (field / 10) + 0x30;
        working_ekran[2*k + ROW_R_T_][COL_ST2_R] = (field % 10) + 0x30;

        //Тисячні секунд
        field = time_ms_tmp;
        working_ekran[2*k + ROW_R_T_][COL_HST1_R] = (field / 100) + 0x30;
        field %= 100;
      
        working_ekran[2*k + ROW_R_T_][COL_HST2_R] = (field / 10) + 0x30;
        field %= 10;
      
        working_ekran[2*k + ROW_R_T_][COL_HST3_R] = field + 0x30;
      }
      
      ++k;
    }

    if (error_reading == false)
    {
      for (size_t i = 2*k ; i < MAX_ROW_FOR_LIST_REGISTRATORS_RECORDS; ++i )
      {
        for (size_t j = 0; j != MAX_COL_LCD; ++j) working_ekran[i][j] = ' ';
      }

      //Курсор видимий
      current_ekran.cursor_on = 1;
    }
    
    _CLEAR_STATE(FATFS_command, FATFS_READ_DATA_FOR_MENU);
  }
  
  if (error_reading)
  {
    //Зафіксована помилкова ситуація
    
    static const unsigned char information[MAX_NAMBER_LANGUAGE][2][MAX_COL_LCD] = 
    {
      {
        "     Ошибка     ",
        "  отображения   "
      },
      {
        "    Помилка     ",
        "  відображення  "
      },
      {
        "    Display     ",
        "     error      "
      },
      {
        "     Ошибка     ",
        "  отображения   "
      }
    };
    
    unsigned char const (*const pArr)[MAX_COL_LCD] = information[index_language];
    for (size_t i = 0; i != MAX_ROW_LCD; ++i)
    {
      for (size_t j = 0; j != MAX_COL_LCD; j++) working_ekran[i][j] = (i < 2) ? pArr[i][j] : ' ';
    }

    //Курсор не видимий
    current_ekran.cursor_on = 0;
    position_temp = 0;
  }
  
  //Курсор по горизонталі відображається на першій позиції
  current_ekran.position_cursor_x = 0;
  //Відображення курору по вертикалі
  current_ekran.position_cursor_y = ((position_temp << 1) + 1) & (MAX_ROW_LCD - 1);
  //Курсор не мигає
  current_ekran.cursor_blinking_on = 0;
  //Обновити повністю весь екран
  current_ekran.current_action = ACTION_WITH_CARRENT_EKRANE_FULL_UPDATE;
}
/*****************************************************/

/*****************************************************/
//Формуємо екран відображення записів дискретного реєстратора
/*****************************************************/
void make_ekran_list_records_registrator(unsigned int type_registrator)
{
  int index_language = index_language_in_array(current_settings.language);
  
  unsigned int position_temp = current_ekran.index_position;

  unsigned int number_records = 0;
  if (type_registrator == INDEX_ML_DIGITAL_REGISTRATOR_INFO) number_records = info_rejestrator_dr.number_records;
  else if (type_registrator == INDEX_ML_PROGRAM_ERROE_REGISTRATOR_INFO) number_records = info_rejestrator_pr_err.number_records;
  else total_error_sw_fixed()/*number_records = holderCmdPlusTime.shTotalFixElem;//info_rejestrator_pr_err.number_records*/;
  
  unsigned int error_reading = false;
  if(number_records == 0)
  {
    //Немає записів
    static const unsigned char information[MAX_NAMBER_LANGUAGE][2][MAX_COL_LCD] = 
    {
      {
        "      Нет       ",
        "    записей     "
      },
      {
        "     Нема       ",
        "    записів     "
      },
      {
        "    Records     ",
        "   are absent   "
      },
      {
        "      Нет       ",
        "    записей     "
      }
    };
    
    unsigned char const (*const pArr)[MAX_COL_LCD] = information[index_language];
    for (size_t i = 0; i != MAX_ROW_LCD; ++i)
    {
      for (size_t j = 0; j != MAX_COL_LCD; j++) working_ekran[i][j] = (i < 2) ? pArr[i][j] : ' ';
    }
    
    //Курсор не видимий
    current_ekran.cursor_on = 0;
    position_temp = 0;
  }
  else if (current_ekran.index_position < ((int)number_records))
  {
    static unsigned char const template_string[2][MAX_COL_LCD] = 
    {
      "   XX-XX-20XX   ",
      "  XX:XX:XX.XXX  "
    };
    
    //Множення на два величини position_temp потрібне для того, бо на одну позицію ми використовуємо два рядки (назва + значення)
    unsigned int index_of_ekran = ((position_temp << 1) >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;

    unsigned int k = 0;
    unsigned int index_of_ekran_tmp = index_of_ekran >> 1;
    while ( ((index_of_ekran_tmp + k) < number_records) && (k < ( MAX_ROW_FOR_LIST_REGISTRATORS_RECORDS >> 1)) ) 
    {
      time_t time_dat_tmp = 0;
      int32_t time_ms_tmp = 0;
      
      if (type_registrator == INDEX_ML_DIGITAL_REGISTRATOR_INFO)
      {
        number_record_of_dr_for_menu = index_of_ekran_tmp + k;
        _SET_STATE(control_tasks_dataflash, TASK_MAMORY_READ_DATAFLASH_FOR_DR_MENU_SHORT_BIT);
        while (_GET_STATE(control_tasks_dataflash, TASK_MAMORY_READ_DATAFLASH_FOR_DR_MENU_SHORT_BIT))
        {
           periodical_operations(false);
        }
        
        if (buffer_for_manu_read_record[0] == LABEL_START_RECORD_DR) 
        {
          for(size_t i = 0; i < sizeof(time_t); i++) *((unsigned char*)(&time_dat_tmp) + i) =  buffer_for_manu_read_record[1 + i];
          for(size_t i = 0; i < sizeof(int32_t); i++) *((unsigned char*)(&time_ms_tmp) + i) = buffer_for_manu_read_record[1 + sizeof(time_t) + i];
        }
        else
        {
          error_reading = true;
          break;
        }
      }
      else if (type_registrator == INDEX_ML_PROGRAM_ERROE_REGISTRATOR_INFO)
      {
        number_record_of_pr_err_into_menu = index_of_ekran_tmp + k;
        _SET_STATE(control_tasks_dataflash, TASK_MAMORY_READ_DATAFLASH_FOR_PR_ERR_MENU_SHORT_BIT);
        while (_GET_STATE(control_tasks_dataflash, TASK_MAMORY_READ_DATAFLASH_FOR_PR_ERR_MENU_SHORT_BIT))
        {
           periodical_operations(false);
        }
        
        if (buffer_for_manu_read_record[0] == LABEL_START_RECORD_PR_ERR) 
        {
          for(size_t i = 0; i < sizeof(time_t); i++) *((unsigned char*)(&time_dat_tmp) + i) =  buffer_for_manu_read_record[1 + i];
          for(size_t i = 0; i < sizeof(int32_t); i++) *((unsigned char*)(&time_ms_tmp) + i) = buffer_for_manu_read_record[1 + sizeof(time_t) + i];
        }
        else
        {
          error_reading = true;
          break;
        }
      }

      //Копіюємо  рядки у робочий екран
      for (size_t i = 0; i != 2; ++i)
      {
          for (size_t j = 0; j != MAX_COL_LCD; ++j) working_ekran[2*k + i][j] = template_string[i][j];
      }
      if (time_dat_tmp != 0)
      {
        struct tm *p = localtime(&time_dat_tmp);
        int field;
      
        //День
        field = p->tm_mday;
        working_ekran[2*k + ROW_R_Y_][COL_DY1_R] = (field / 10) + 0x30;
        working_ekran[2*k + ROW_R_Y_][COL_DY2_R] = (field % 10) + 0x30;

        //Місяць
        field = p->tm_mon + 1;
        working_ekran[2*k + ROW_R_Y_][COL_MY1_R] = (field / 10) + 0x30;
        working_ekran[2*k + ROW_R_Y_][COL_MY2_R] = (field % 10) + 0x30;

        //Рік
        field = p->tm_year - 100;
        working_ekran[2*k + ROW_R_Y_][COL_SY1_R] = (field / 10) + 0x30;
        working_ekran[2*k + ROW_R_Y_][COL_SY2_R] = (field % 10) + 0x30;

        //Година
        field = p->tm_hour;
        working_ekran[2*k + ROW_R_T_][COL_HT1_R] = (field / 10) + 0x30;
        working_ekran[2*k + ROW_R_T_][COL_HT2_R] = (field % 10) + 0x30;

        //Хвилини
        field = p->tm_min;
        working_ekran[2*k + ROW_R_T_][COL_MT1_R] = (field / 10) + 0x30;
        working_ekran[2*k + ROW_R_T_][COL_MT2_R] = (field % 10) + 0x30;

        //Секунди
        field = p->tm_sec;
        working_ekran[2*k + ROW_R_T_][COL_ST1_R] = (field / 10) + 0x30;
        working_ekran[2*k + ROW_R_T_][COL_ST2_R] = (field % 10) + 0x30;

        //Тисячні секунд
        field = time_ms_tmp;
        working_ekran[2*k + ROW_R_T_][COL_HST1_R] = (field / 100) + 0x30;
        field %= 100;
      
        working_ekran[2*k + ROW_R_T_][COL_HST2_R] = (field / 10) + 0x30;
        field %= 10;
      
        working_ekran[2*k + ROW_R_T_][COL_HST3_R] = field + 0x30;
      }
      
      ++k;
    }

    if (error_reading == false)
    {
      for (size_t i = 2*k ; i < MAX_ROW_FOR_LIST_REGISTRATORS_RECORDS; ++i )
      {
        for (size_t j = 0; j != MAX_COL_LCD; ++j) working_ekran[i][j] = ' ';
      }

      //Курсор видимий
      current_ekran.cursor_on = 1;
    }
  }
  
  if (error_reading)
  {
    //Зафіксована помилкова ситуація
    
    static const unsigned char information[MAX_NAMBER_LANGUAGE][2][MAX_COL_LCD] = 
    {
      {
        "     Ошибка     ",
        "  отображения   "
      },
      {
        "    Помилка     ",
        "  відображення  "
      },
      {
        "    Display     ",
        "     error      "
      },
      {
        "     Ошибка     ",
        "  отображения   "
      }
    };
    
    unsigned char const (*const pArr)[MAX_COL_LCD] = information[index_language];
    for (size_t i = 0; i != MAX_ROW_LCD; ++i)
    {
      for (size_t j = 0; j != MAX_COL_LCD; j++) working_ekran[i][j] = (i < 2) ? pArr[i][j] : ' ';
    }

    //Курсор не видимий
    current_ekran.cursor_on = 0;
    position_temp = 0;
  }
  
  //Курсор по горизонталі відображається на першій позиції
  current_ekran.position_cursor_x = 0;
  //Відображення курору по вертикалі
  current_ekran.position_cursor_y = ((position_temp << 1) + 1) & (MAX_ROW_LCD - 1);
  //Курсор не мигає
  current_ekran.cursor_blinking_on = 0;
  //Обновити повністю весь екран
  current_ekran.current_action = ACTION_WITH_CARRENT_EKRANE_FULL_UPDATE;
}
/*****************************************************/

/*****************************************************/
//Формуємо екран відображення заголовків груп для запису дискретного реєстратора
/*****************************************************/
void make_ekran_list_titles_for_record_of_digital_registrator(void)
{
  int index_language = index_language_in_array(current_settings.language);

  if ((control_tasks_dataflash & TASK_MAMORY_READ_DATAFLASH_FOR_DR_MENU) == 0)
  {
    //Процес зчитування даних з DataFlash вже закінчився
    static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_TITLES_DIGITAL_REGISTRATOR][MAX_COL_LCD] = 
    {
      {
        " Изм.дискр.сигн.",
        " Изм.при м.ф. ос",
        " Изм.при м.ф. р.",
        " Изм.при U-min  ",
        " Изм.при U-max  ",
        " Изм.при м.с. ос",
        " Изм.при м.с. р.",
        " Изм.при f-min  ",
        " Изм.при f-ЧАПВ "
      },
      {
        " Зм.дискр.сигн. ",
        " Вим.при м.ф. ос",
        " Вим.при м.ф. р.",
        " Вим.при U-min  ",
        " Вим.при U-max  ",
        " Вим.при м.оп.ос",
        " Вим.при м.оп.р.",
        " Вим.при f-min  ",
        " Вим.при f-ЧАПВ "
      },
      {
        " Bin S Changes  ",
        " Изм.при м.ф. ос",
        " Изм.при м.ф. р.",
        " M at Min Vol   ",
        " M at Max Vol   ",
        " Изм.при м.с. ос",
        " Изм.при м.с. р.",
        " M at Min f     ",
        " M.at f -FAR    "
      },
      {
        " Изм.дискр.сигн.",
        " Изм.при м.ф. ос",
        " Изм.при м.ф. р.",
        " Изм.при U-min  ",
        " Изм.при U-max  ",
        " Изм.при м.с. ос",
        " Изм.при м.с. р.",
        " Изм.при f-min  ",
        " Изм.при f-ЧАПВ "
      }
    };

    unsigned int position = current_ekran.index_position;
    unsigned int position_temp = position;
    unsigned int shift[MAX_ROW_FOR_TITLES_DIGITAL_REGISTRATOR];
    for (unsigned int *pShift = shift; pShift < (shift + MAX_ROW_FOR_TITLES_DIGITAL_REGISTRATOR); ++pShift) *pShift = 0;

    {
      unsigned int *pShift = shift + INDEX_ML_TITLE_DR_CHANGES_SIGNALS + 1;
      unsigned int val_shift = 0;
      for (size_t i = (INDEX_ML_TITLE_DR_CHANGES_SIGNALS + 1); i < MAX_ROW_FOR_TITLES_DIGITAL_REGISTRATOR; ++i)
      {
        if (
            ((i == INDEX_ML_TITLE_DR_MAX_PHASE_O) && (buffer_for_manu_read_record[FIRST_INDEX_NUMBER_MAX_PHASE_O_DR] == 0)) ||
            ((i == INDEX_ML_TITLE_DR_MAX_PHASE_R) && (buffer_for_manu_read_record[FIRST_INDEX_NUMBER_MAX_PHASE_R_DR] == 0)) ||
            ((i == INDEX_ML_TITLE_DR_MIN_U      ) && (buffer_for_manu_read_record[FIRST_INDEX_NUMBER_MIN_U_DR      ] == 0)) ||
            ((i == INDEX_ML_TITLE_DR_MAX_U      ) && (buffer_for_manu_read_record[FIRST_INDEX_NUMBER_MAX_U_DR      ] == 0)) ||
            ((i == INDEX_ML_TITLE_DR_MIN_R_O    ) && (buffer_for_manu_read_record[FIRST_INDEX_NUMBER_MIN_R_O_DR    ] == 0)) ||
            ((i == INDEX_ML_TITLE_DR_MIN_R_R    ) && (buffer_for_manu_read_record[FIRST_INDEX_NUMBER_MIN_R_R_DR    ] == 0)) ||
            ((i == INDEX_ML_TITLE_DR_MIN_F1     ) && (buffer_for_manu_read_record[FIRST_INDEX_NUMBER_MIN_F_ACHR_DR ] == 0)) ||
            ((i == INDEX_ML_TITLE_DR_MIN_F2     ) && (buffer_for_manu_read_record[FIRST_INDEX_NUMBER_F_CHAPV_DR    ] == 0))
           )
        {
          if (i < position)
          {
            --position_temp;
          }
          *pShift = ++val_shift;
        }
        else
        {
          *(pShift++) = val_shift;
        }
      }
      while (pShift < (shift + MAX_ROW_FOR_TITLES_DIGITAL_REGISTRATOR)) *(pShift++) = val_shift;
    }
  
    unsigned int index_of_ekran = (position_temp >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;
  
    //Копіюємо  рядки у робочий екран
    for (size_t i = 0; i < MAX_ROW_LCD; ++i)
    {
      unsigned int const real_index = index_of_ekran + shift[index_of_ekran];
      //Наступні рядки треба перевірити, чи їх требе відображати у текучій коффігурації
      if (real_index < MAX_ROW_FOR_TITLES_DIGITAL_REGISTRATOR)
        for (size_t j = 0; j < MAX_COL_LCD; ++j) working_ekran[i][j] = name_string[index_language][real_index][j];
      else
        for (size_t j = 0; j < MAX_COL_LCD; ++j) working_ekran[i][j] = ' ';

      index_of_ekran++;
    }
  
    //Курсор видимий
    current_ekran.cursor_on = 1;
    //Відображення курору по вертикалі
    current_ekran.position_cursor_y = position_temp & (MAX_ROW_LCD - 1);
    
    //Позначаємо, що більше цей екран перерисовувати не треба
    rewrite_ekran_once_more = 0;
  }
  else
  {
    //Процес зчитування даних з DataFlash ще не закінчився
    static unsigned char const name_string[MAX_NAMBER_LANGUAGE][2][MAX_COL_LCD] = 
    {
      {
        " Процесс чтения ",
        "  не завершен   "
      },
      {
        " Процес читання ",
        " не завершений  "
      },
      {
        "    Reading     ",
        "is not completed"
      },
      {
        " Процесс чтения ",
        "  не завершен   "
      }
    };

    //Копіюємо  рядки у робочий екран
    for (size_t i = 0; i < MAX_ROW_LCD; ++i)
    {
      //Наступні рядки треба перевірити, чи їх требе відображати у текучій коффігурації
      if (i < 2)
        for (size_t j = 0; j < MAX_COL_LCD; ++j) working_ekran[i][j] = name_string[index_language][i][j];
      else
        for (size_t j = 0; j < MAX_COL_LCD; ++j) working_ekran[i][j] = ' ';
    }

    //Курсор не видимий
    current_ekran.cursor_on = 0;
    //Відображення курору по вертикалі
    current_ekran.position_cursor_y = 0;

    //Позначаємо, що цей екран треба перерисувати
    rewrite_ekran_once_more = 1;
  }

  //Курсор по горизонталі відображається на першій позиції
  current_ekran.position_cursor_x = 0;
  //Курсор не мигає
  current_ekran.cursor_blinking_on = 0;
  //Обновити повністю весь екран
  current_ekran.current_action = ACTION_WITH_CARRENT_EKRANE_FULL_UPDATE;
}
/*****************************************************/

/*****************************************************/
//Формуємо екран відображення діючих значень при фіксації максимальних/мінімальних вимірювань запису дискретного реєстратора
/*****************************************************/
void make_ekran_title_analog_value_records_digital_registrator(void)
{
  unsigned char name_string[MAX_ROW_FOR_TITLE_EKRAN_ANALOG_VALUES_DR][MAX_COL_LCD];
  for(int index_1 = 0; index_1 < MAX_ROW_LCD; index_1++)
  {
    for(int index_2 = 0; index_2 < MAX_COL_LCD; index_2++) name_string[index_1][index_2] = ' ';
  }
  int index_language = index_language_in_array(current_settings.language);
  
  unsigned int position_temp = current_ekran.index_position;
  unsigned int index_of_ekran;
  unsigned int number_info_records;
  
  number_info_records = buffer_for_manu_read_record[FIRST_INDEX_NUMBER_MAX_PHASE_O_DR + type_view_max_values_dr - IDENTIFIER_BIT_ARRAY_MAX_CURRENT_PHASE_O];
  
  index_of_ekran = (position_temp >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;

  index_cell_into_array_for_min_max_measurement_dr = -1; //Помічаємо, що ми покищо не знайшли індекс комірки, який відповідає першому блоку, який визначений курсором
  if(number_info_records == 0)
  {
    static const unsigned char information[MAX_NAMBER_LANGUAGE][2][MAX_COL_LCD] = 
    {
      {
        "      Нет       ",
        "    записей     "
      },
      {
        "     Нема       ",
        "    записів     "
      },
      {
        "    Records     ",
        "   are absent   "
      },
      {
        "      Нет       ",
        "    записей     "
      }
    };

    for(int index_1 = 0; index_1 < 2; index_1++)
    {
      for(int index_2 = 0; index_2 < MAX_COL_LCD; index_2++)
        name_string[index_1][index_2] = information[index_language][index_1][index_2];
    }

    //Курсор не видимий
    current_ekran.cursor_on = 0;
  }
  else if (current_ekran.index_position < ((int)number_info_records))
  {
    unsigned int k = 0;
    while (((index_of_ekran + k) < number_info_records) && (k < MAX_ROW_FOR_TITLE_EKRAN_ANALOG_VALUES_DR))
    {
      //Шукаємо блок, який відповідає заданому типу струму
      unsigned int number_finded_this_type_of_current = 0;
      unsigned int index_cell_into_array = (FIRST_INDEX_FIRST_BLOCK_DR + (sizeof(unsigned int)*SIZE_ARRAY_FIX_MAX_MEASUREMENTS - 1));//Індекс комірки пам'яті встановлюємо на байт першого блоку, який відображає тип струму по якому йшов моніторинг
      while ((number_finded_this_type_of_current != (index_of_ekran + k + 1)) && (index_cell_into_array < FIRST_INDEX_FIRST_DATA_DR))
      {
        if (buffer_for_manu_read_record[index_cell_into_array] == type_view_max_values_dr)
          number_finded_this_type_of_current++;
        if (number_finded_this_type_of_current != (index_of_ekran + k + 1))
          index_cell_into_array += (sizeof(unsigned int)*SIZE_ARRAY_FIX_MAX_MEASUREMENTS);
      }
      
      unsigned char information[MAX_COL_LCD] = "                ";
      static const unsigned char ms[MAX_NAMBER_LANGUAGE][3] = 
      {
        "мс.",
        "мс.",
        "ms ",
        "мс."
      };
      if ((number_finded_this_type_of_current == (index_of_ekran + k + 1)) && (index_cell_into_array < FIRST_INDEX_FIRST_DATA_DR))
      {
        //Ми знайшли потрібний блок
        //Якщо у цьому рядку ще і знаходиться курсор, то треба запам'ятати індекс першого елементу найденого блоку
        if (position_temp  == (index_of_ekran + k))
          index_cell_into_array_for_min_max_measurement_dr = index_cell_into_array - (sizeof(unsigned int)*SIZE_ARRAY_FIX_MAX_MEASUREMENTS - 1);

        //Визначаємо час зрізу
        index_cell_into_array -= 3; //Переводимо індекс на початок часової мітки
        unsigned char sring_of_time[8] = "        ";
        unsigned int time_of_slice = buffer_for_manu_read_record[index_cell_into_array] + (buffer_for_manu_read_record[index_cell_into_array + 1]<<8) + (buffer_for_manu_read_record[index_cell_into_array + 2]<<16);

        //Конвертуємо цей час у рядок
        unsigned int ost, local_index = 0;
        while ((time_of_slice >= 10) && (local_index < (8 - 1)))
        {
          ost = time_of_slice % 10;
          sring_of_time[7-local_index] = ost + 0x30;
          time_of_slice /= 10;
          local_index++;
        }
        sring_of_time[7-local_index] =  time_of_slice + 0x30;

        //Копіюємо цей рідок часу у наш робочий рядок
        local_index = 0;
        while ((sring_of_time[local_index] == ' ') && (local_index < 8)) local_index++;
        unsigned int local_index1 = 1;
        while (local_index < 8) information[local_index1++] = sring_of_time[local_index++];
        information[local_index1++] = ' ';
        information[local_index1++] = ms[index_language][0];
        information[local_index1++] = ms[index_language][1];
        information[local_index1++] = ms[index_language][2];
      }
      else
      {
        //теоретично ми сюди б не мали ніколи заходити, але якщо ми сюди зайшли, то виводимо сигналізацію про помилку на екран
        static const unsigned char error_meas[MAX_NAMBER_LANGUAGE][MAX_COL_LCD] = 
        {
          " Ошибка         ",
          " Помилка        ",
          " Error          ",
          " Ошибка         "
        };
        for (unsigned int i = 0; i < MAX_COL_LCD; i++) information[i] = error_meas[index_language][i];
      }

      for (unsigned int i = 0; i < MAX_COL_LCD; i++) name_string[k][i] = information[i];
      k++;
    }

    //Курсор видимий
    current_ekran.cursor_on = 1;
  }
  else
  {
    //Зафіксована помилкова ситуація
    static const unsigned char information[MAX_NAMBER_LANGUAGE][2][MAX_COL_LCD] = 
    {
      {
        "     Ошибка     ",
        "  отображения   "
      },
      {
        "    Помилка     ",
        "  відображення  "
      },
      {
        "    Display     ",
        "     error      "
      },
      {
        "     Ошибка     ",
        "  отображения   "
      }
    };

    for(int index_1 = 0; index_1 < 2; index_1++)
    {
      for(int index_2 = 0; index_2 < MAX_COL_LCD; index_2++)
        name_string[index_1][index_2] = information[index_language][index_1][index_2];
    }

    //Курсор не видимий
    current_ekran.cursor_on = 0;
  }
  
  //Копіюємо  рядки у робочий екран
  for (unsigned int i=0; i< MAX_ROW_LCD; i++)
  {
    for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[i][j];
  }

  //Курсор по горизонталі відображається на першій позиції
  current_ekran.position_cursor_x = 0;
  //Відображення курору по вертикалі
  current_ekran.position_cursor_y = position_temp & (MAX_ROW_LCD - 1);
  //Курсор не мигає
  current_ekran.cursor_blinking_on = 0;
  //Обновити повністю весь екран
  current_ekran.current_action = ACTION_WITH_CARRENT_EKRANE_FULL_UPDATE;
}
/*****************************************************/

/*****************************************************/
//Формуємо екран відображення діючих значень
/*****************************************************/
void make_ekran_analog_value_records_digital_registrator(unsigned int pervynna_vtorynna)
{
	int const index_language = index_language_in_array(current_settings.language);
  if (buffer_for_manu_read_record[FIRST_INDEX_START_START_RECORD_DR] == LABEL_START_RECORD_DR)
  {
    //Пеший байт сходиться із міткою початку запису - вважаємо, що у буфері достовірні дані
    unsigned char const name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_EKRAN_ANALOG_VALUES_DR][MAX_COL_LCD] = 
    {
			{
        " Impl =         ",
        " Ibpl =         ",
        " Umpl =         ",
        " Ubpl =         ",
        " Imp3 =         ",
        " Ibp3 =         ",
      	" f  =           ",
      	" Rmn            ",
      	" Xmn            ",
      	" Zmn            ",
      	" Rbp            ",
      	" Xbp            ",
      	" Zbp            ",
        "                "
			},
			{
        " Impl =         ",
        " Ibpl =         ",
        " Vmpl =         ",
        " Vbpl =         ",
        " Imp3 =         ",
        " Ibp3 =         ",
      	" f  =           ",
      	" Rmn            ",
      	" Xmn            ",
      	" Zmn            ",
      	" Rbp            ",
      	" Xbp            ",
      	" Zbp            ",
        "                "
			},
			{
        " Impl =         ",
        " Ibpl =         ",
        " Umpl =         ",
        " Ubpl =         ",
        " Imp3 =         ",
        " Ibp3 =         ",
      	" f  =           ",
      	" Rmn            ",
      	" Xmn            ",
      	" Zmn            ",
      	" Rbp            ",
      	" Xbp            ",
      	" Zbp            ",
        "                "
			},
			{
        " Impl =         ",
        " Ibpl =         ",
        " Umpl =         ",
        " Ubpl =         ",
        " Imp3 =         ",
        " Ibp3 =         ",
      	" f  =           ",
      	" Rmn            ",
      	" Xmn            ",
      	" Zmn            ",
      	" Rbp            ",
      	" Xbp            ",
      	" Zbp            ",
        "                "
			}
    };

    unsigned char name_string_tmp[MAX_ROW_FOR_EKRAN_ANALOG_VALUES_DR][MAX_COL_LCD];
		for (size_t i = 0; i < MAX_ROW_FOR_EKRAN_ANALOG_VALUES_DR; ++i)
		{
			unsigned char *p_target = name_string_tmp[i];
			unsigned char const *p_source = name_string[index_language][i];
			for (size_t j = 0; j < MAX_COL_LCD; ++j) *p_target++ = *p_source;
		}

		unsigned char *point_unsigned_char = (unsigned char *)(buffer_for_manu_read_record + index_cell_into_array_for_min_max_measurement_dr);
    unsigned int *point_unsigned_int = (unsigned int*)point_unsigned_char;
    
    unsigned int TC_o = 1;
    unsigned int TC_r = 1;
    unsigned int TV = 1;
    if (pervynna_vtorynna != 0)
    {
      unsigned char *ptr_target = (unsigned char *)&TC_o;
      unsigned char *ptr_source = (unsigned char *)(buffer_for_manu_read_record + FIRST_INDEX_TC_O);
      for(size_t i = 0; i < sizeof(TC_o); ++i) 
      *ptr_target++ = *ptr_source++;

      ptr_target = (unsigned char *)&TC_r;
      ptr_source = (unsigned char *)(buffer_for_manu_read_record + FIRST_INDEX_TC_R);
      for(size_t i = 0; i < sizeof(TC_r); ++i) 
      *ptr_target++ = *ptr_source++;

      ptr_target = (unsigned char *)&TV;
      ptr_source = (unsigned char *)(buffer_for_manu_read_record + FIRST_INDEX_TV);
      for(size_t i = 0; i < sizeof(TV); ++i) 
      *ptr_target++ = *ptr_source++;
    }

    for (size_t i = 0; i < MAX_ROW_FOR_EKRAN_ANALOG_VALUES_DR; ++i)
    {
			static size_t const redirect[MAX_ROW_FOR_EKRAN_ANALOG_VALUES_DR] = 
			{
        IDM_Imn,
        IDM_Ibp,
        IDM_Umn,
        IDM_Ubp,
  
        IDM_3Imn,
        IDM_3Ibp,
	
	      IDM_F,
	
        IDM_R_mn,
        IDM_X_mn,
        IDM_Z_mn,
        IDM_R_bp,
        IDM_X_bp,
        IDM_Z_bp,
        
        IDM_VMP
			};
			
			size_t const ind = redirect[i];
      if (ind < IDM_F)
      {
       //Струми і напруги

        unsigned int koef_mul = 1;
        if ((ind == IDM_Imn) || (ind == IDM_3Imn)) koef_mul = TC_o;
        else if ((ind == IDM_Ibp) || (ind == IDM_3Ibp)) koef_mul = TC_r;
        else koef_mul = TV;

        unsigned int temp_measurement = *(point_unsigned_int + ind);
        unsigned int const start_number_digit_after_point = 3;
        convert_and_insert_char_for_measurement(start_number_digit_after_point, temp_measurement, koef_mul, 1, name_string_tmp[i], 7);
      }
      else if (ind == IDM_F)
      {
        //Частота
        int temp_measurement = *(((int *)point_unsigned_int) + ind);
        if (temp_measurement < 0)
        {
          if (temp_measurement == (-2*1000))
          {
            /*Частота нижче порогу визначеного константою MIN_FREQUENCY*/
            name_string_tmp[i][4] = '<';
            temp_measurement = MIN_FREQUENCY*1000;
          }
          if (temp_measurement == (-3*1000))
          {
            /*Частота вище порогу визначеного константою MAX_FREQUENCY*/
            name_string_tmp[i][4] = '>';
            temp_measurement = MAX_FREQUENCY*1000;
          }       
        }
        convert_and_insert_char_for_frequency(temp_measurement, name_string_tmp[i]);
      }
      else if (ind < IDM_VMP)
      {
       //Опори
        static const unsigned int index_of_start_position_array[MAX_NAMBER_LANGUAGE] = {4, 4, 5, 4};

        unsigned int start_position = index_of_start_position_array[index_language];
        unsigned int size_dimension = size_dimension_array[index_language];
        for (unsigned int j = 0; j < size_dimension; j++)
        {
          name_string_tmp[i][MAX_COL_LCD - size_dimension + j] = resistance_dimension[index_language][j];
        }
        name_string_tmp[i][start_position] = '=';

        start_position++;

        int temp_measurement = *(point_unsigned_int + ind);
        if(((unsigned int)temp_measurement) != ((unsigned int)UNDEF_RESISTANCE))
        {
          /********************************/
          //Вводимо вимірювальні значення
          /********************************/
          if (temp_measurement < 0)
          {
            temp_measurement = -temp_measurement;
            name_string_tmp[i][start_position] = '-';
          }
          if (ind < IDM_R_bp)
            convert_and_insert_char_for_measurement(3, temp_measurement, TV, TC_o, name_string_tmp[i], (start_position + 1));
          else
            convert_and_insert_char_for_measurement(3, temp_measurement, TV, TC_r, name_string_tmp[i], (start_position + 1));

          unsigned int shift = 0;
          unsigned int start_position_to_shift = start_position + 1;
          while (
                 (name_string_tmp[i][start_position_to_shift] == ' ') &&
                 ((start_position_to_shift + shift) < MAX_COL_LCD)  
                ) 
          {
            for (unsigned int j = start_position_to_shift; j < (MAX_COL_LCD - 1); j++ ) name_string_tmp[i][j] = name_string_tmp[i][j + 1];
            name_string_tmp[i][MAX_COL_LCD - 1] = ' ';
            shift++;
          }
          /********************************/
        }
        else
        {
#define SIZE_UNDEF      9
          static const unsigned char undefined[MAX_NAMBER_LANGUAGE][SIZE_UNDEF] =
          {
            "Неопред. ",
            "Невизнач.",
            "Undef.   ",
            "Неопред. "  
          };
          for (unsigned int j = 0; j < size_dimension; j++) name_string_tmp[i][MAX_COL_LCD - size_dimension + j] = ' ';
          for (unsigned int j = 0; j < SIZE_UNDEF; j++) name_string_tmp[i][start_position + 1 + j] = undefined[index_language][j];
#undef SIZE_UNDEF
        }
      }
      else if ((ind == IDM_VMP) && (type_view_max_values_dr == IDENTIFIER_BIT_ARRAY_MIN_R_O))
      {
        //Місце пошкодження
#define SIZE_NAME_FIELD         2
        static const unsigned char name_field[MAX_NAMBER_LANGUAGE][SIZE_NAME_FIELD] = {"МП", "МП", "FD", "МП"};
        for (unsigned int j = 0; j < SIZE_NAME_FIELD; j++)
        {
          name_string_tmp[i][1 + j] = name_field[index_language][j];
        }
#undef SIZE_NAME_FIELD

#define INDEX_LESS_EQUAL_MORE   4
#define SIZE_L_DIMENSION        2

        static const unsigned char km[MAX_NAMBER_LANGUAGE][SIZE_L_DIMENSION] = {"км", "км", "km", "км"};
  
        for (unsigned int j = 0; j < SIZE_L_DIMENSION; j++)
        {
          name_string_tmp[i][INDEX_LESS_EQUAL_MORE + 2 + 7 + j] = km[index_language][j];
        }

        int temp_measurement_1 = *(point_unsigned_int + ind);
        int temp_measurement_2 = *(point_unsigned_int + IDM_VMP_EQUAL_MORE);
        if(((unsigned int)temp_measurement_1) != ((unsigned int)UNDEF_VMP))
        {
          if (temp_measurement_2 == true) name_string_tmp[i][INDEX_LESS_EQUAL_MORE] = '=';
          else name_string_tmp[i][INDEX_LESS_EQUAL_MORE] = '>';
          /********************************/
          //Вводимо вимірювальні значення
          /********************************/
          if (temp_measurement_1 < 0)
          {
            temp_measurement_1 = -temp_measurement_1;
            name_string_tmp[i][INDEX_LESS_EQUAL_MORE + 1] = '-';
          }
          convert_and_insert_char_for_measurement(3, temp_measurement_1, 1, 1, name_string_tmp[i], (INDEX_LESS_EQUAL_MORE + 2));
          
          //Є можливісьт між числом і розмірністю поставити один пробіл
          for (unsigned int j = 0; j < SIZE_L_DIMENSION; j++)
          {
            name_string_tmp[i][MAX_COL_LCD - 1 - j] = name_string_tmp[i][MAX_COL_LCD - 1 - j - 1];
          }
          name_string_tmp[i][MAX_COL_LCD - 1 - SIZE_L_DIMENSION] = ' ';

          unsigned int shift = 0;
          unsigned int start_position_to_shift = INDEX_LESS_EQUAL_MORE + 1 + 1;
          while (
                 (name_string_tmp[i][start_position_to_shift] == ' ') &&
                 ((start_position_to_shift + shift) < MAX_COL_LCD)  
                ) 
          {
            for (unsigned int j = start_position_to_shift; j < (MAX_COL_LCD - 1); j++ ) name_string_tmp[i][j] = name_string_tmp[i][j + 1];
            name_string_tmp[i][MAX_COL_LCD - 1] = ' ';
            shift++;
          }
          /********************************/
        }
        else
        {
          name_string_tmp[i][INDEX_LESS_EQUAL_MORE] = '=';
          
#define SIZE_UNDEF      9
          static const unsigned char undefined[MAX_NAMBER_LANGUAGE][SIZE_UNDEF] =
          {
            "Неопред. ",
            "Невизнач.",
            "Undef.   ",
            "Неопред. "  
          };
          for (unsigned int j = 0; j < SIZE_L_DIMENSION; j++) name_string_tmp[i][INDEX_LESS_EQUAL_MORE + 2 + 7 + j] = ' ';
          for (unsigned int j = 0; j < SIZE_UNDEF; j++) name_string_tmp[i][INDEX_LESS_EQUAL_MORE + 2 + j] = undefined[index_language][j];
#undef SIZE_UNDEF
        }
#undef SIZE_L_DIMENSION
#undef INDEX_LESS_EQUAL_MORE
      }
      
      if (
          ((ind == IDM_Imn) || (ind == IDM_3Imn)) ||
          ((ind == IDM_Ibp) || (ind == IDM_3Ibp))
         )
        name_string_tmp[i][MAX_COL_LCD - 1] = odynyci_vymirjuvannja[index_language][INDEX_A];
      else if (ind < IDM_F)
        name_string_tmp[i][MAX_COL_LCD - 1] = odynyci_vymirjuvannja[index_language][INDEX_V];
      else
      {
        //Герци і Оми ми вже вивели під час відображення значення
      }
    }
  
    int position_temp = current_ekran.index_position;
    
    /******************************************/
    //Виключаємо поля, які не треба відображати
    /******************************************/
    int additional_current = 0;
    
    if (type_view_max_values_dr != IDENTIFIER_BIT_ARRAY_MIN_R_O)
    {
      int shift_ind = (MAX_ROW_FOR_EKRAN_ANALOG_VALUES_DR - 1) - additional_current;
      if ((shift_ind + 1) <= position_temp) position_temp--;
      do  
      {
        for(size_t j = 0; j < MAX_COL_LCD; ++j)
        {
          if ((shift_ind + 1) < (MAX_ROW_FOR_EKRAN_ANALOG_VALUES_DR - additional_current)) name_string_tmp[shift_ind][j] = name_string_tmp[shift_ind + 1][j];
          else name_string_tmp[shift_ind][j] = ' ';
        }
        shift_ind++;
      }
      while (shift_ind < (MAX_ROW_FOR_EKRAN_ANALOG_VALUES_DR - additional_current));
      additional_current++;
    }
    /******************************************/
    
    unsigned int index_of_ekran = (position_temp >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;
  
    //Копіюємо  рядки у робочий екран
    for (size_t i = 0; i < MAX_ROW_LCD; ++i)
    {
      //Наступні рядки треба перевірити, чи їх требе відображати у текучій коффігурації
      unsigned char * p_target = working_ekran[i];
      
      if (((int)index_of_ekran) < (MAX_ROW_FOR_EKRAN_ANALOG_VALUES_DR - additional_current))
      {
        unsigned char const * p_source = name_string_tmp[index_of_ekran];
        for (size_t j = 0; j < MAX_COL_LCD; ++j) *p_target++ = *p_source++;
      }
      else
      {
        for (size_t j = 0; j < MAX_COL_LCD; ++j) *p_target++ = ' ';
      }

      ++index_of_ekran;
    }
  
    //Відображення курору по вертикалі
    current_ekran.position_cursor_y = position_temp & (MAX_ROW_LCD - 1);
    //Курсор видимий
    current_ekran.cursor_on = 1;
  }
  else
  {
    //Пеший байт не сходиться із міткою початку запису - робимо висновок, що у біфері не достовірні дані
    static const unsigned char name_string[MAX_NAMBER_LANGUAGE][2][MAX_COL_LCD] = 
    {
      {
        " Недостоверные  ",
        "     данные     "
      },
      {
        "  Недостовірні  ",
        "      дані      "
      },
      {
        "    Invalid     ",
        "      data      "
      },
      {
        " Недостоверные  ",
        "     данные     "
      }
    };

    //Копіюємо  рядки у робочий екран
    for (size_t i = 0; i < MAX_ROW_LCD; ++i)
    {
      unsigned char * p_target = working_ekran[i];
      //Наступні рядки треба перевірити, чи їх требе відображати у текучій коффігурації
      if (i < 2)
      {
        unsigned char const * p_source = name_string[index_language][i];
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) *p_target++ = *p_source++;
      }
      else
      {
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) *p_target++ = ' ';
      }
    }

    //Відображення курору по вертикалі
    current_ekran.position_cursor_y = 0;
    //Курсор не видимий
    current_ekran.cursor_on = 0;
  }


  //Курсор по горизонталі відображається на першій позиції
  current_ekran.position_cursor_x = 0;
  //Курсор не мигає
  current_ekran.cursor_blinking_on = 0;
  //Обновити повністю весь екран
  current_ekran.current_action = ACTION_WITH_CARRENT_EKRANE_FULL_UPDATE;
}
/*****************************************************/

/*****************************************************/
//Формуємо екран відображення змін дискретних сигналів з запису дискретного реєстратора
/*****************************************************/
void make_ekran_changing_signals_digital_registrator(void)
{
  int index_language = index_language_in_array(current_settings.language);

  if (buffer_for_manu_read_record[FIRST_INDEX_START_START_RECORD_DR] == LABEL_START_RECORD_DR)
  {
    //Пеший байт сходиться із міткою початку запису - вважаємо, що у буфері достовірні дані
    static const unsigned char name_string[MAX_NAMBER_LANGUAGE][TOTAL_SIGNAL_FOR_RNG_BIG - TOTAL_UP_SIGNAL_FOR_RNG_BIG + 3][MAX_COL_LCD] = 
    {
      {NAME_RANG_A01_RU},
      {NAME_RANG_A01_UA},
      {NAME_RANG_A01_EN},
      {NAME_RANG_A01_KZ},
    };
    static const uint32_t index_number_UP[MAX_NAMBER_LANGUAGE][3] = 
    {
      {11, 10, 8}, 
      {11, 10, 8}, 
      { 6,  6, 9}, 
      {11, 10, 8}
    };
    uint8_t name_string_tmp[TOTAL_SIGNAL_FOR_RNG_BIG][MAX_COL_LCD];
    for(int index_1 = 0; index_1 < TOTAL_SIGNAL_FOR_RNG_BIG; index_1++)
    {
      unsigned int index_row;
      if (index_1 < (TOTAL_SIGNAL_FOR_RNG_BIG - TOTAL_EL_SIGNAL_FOR_RNG_BIG - TOTAL_VMP_SIGNAL_FOR_RNG_BIG - TOTAL_UP_SIGNAL_FOR_RNG_BIG)) 
      {
        index_row = index_1;
      }
      else if (index_1 < (TOTAL_SIGNAL_FOR_RNG_BIG - TOTAL_EL_SIGNAL_FOR_RNG_BIG - TOTAL_VMP_SIGNAL_FOR_RNG_BIG))
      {
        index_row = (TOTAL_SIGNAL_FOR_RNG_BIG - TOTAL_EL_SIGNAL_FOR_RNG_BIG - TOTAL_VMP_SIGNAL_FOR_RNG_BIG - TOTAL_UP_SIGNAL_FOR_RNG_BIG) + ((index_1 - (TOTAL_UP_SIGNAL_FOR_RNG_BIG - TOTAL_EL_SIGNAL_FOR_RNG_BIG - TOTAL_VMP_SIGNAL_FOR_RNG_BIG - TOTAL_UP_SIGNAL_FOR_RNG_BIG)) % 3);
      }
      else
      {
        index_row = index_1 - TOTAL_UP_SIGNAL_FOR_RNG_BIG + 3;
      }
      
      for(int index_2 = 0; index_2 < MAX_COL_LCD; index_2++)
      {
        if (
            (index_1 >= (TOTAL_SIGNAL_FOR_RNG_BIG - TOTAL_EL_SIGNAL_FOR_RNG_BIG - TOTAL_VMP_SIGNAL_FOR_RNG_BIG - TOTAL_UP_SIGNAL_FOR_RNG_BIG))  &&
            (index_1 <  (TOTAL_SIGNAL_FOR_RNG_BIG - TOTAL_EL_SIGNAL_FOR_RNG_BIG - TOTAL_VMP_SIGNAL_FOR_RNG_BIG)) &&
            (index_2 == index_number_UP[index_language][(index_1 - (TOTAL_SIGNAL_FOR_RNG_BIG - TOTAL_EL_SIGNAL_FOR_RNG_BIG - TOTAL_VMP_SIGNAL_FOR_RNG_BIG - TOTAL_UP_SIGNAL_FOR_RNG_BIG)) % 3]) 
           )
        {
          name_string_tmp[index_1][index_2] = 0x30 + ((index_1 - (TOTAL_SIGNAL_FOR_RNG_BIG - TOTAL_EL_SIGNAL_FOR_RNG_BIG - TOTAL_VMP_SIGNAL_FOR_RNG_BIG - TOTAL_UP_SIGNAL_FOR_RNG_BIG)) / 3 + 1);
        }
        else name_string_tmp[index_1][index_2] = name_string[index_language][index_row][index_2];
      }
    }
  
    unsigned int max_number_changers_in_record = buffer_for_manu_read_record[FIRST_INDEX_NUMBER_CHANGES_DR] | (buffer_for_manu_read_record[FIRST_INDEX_NUMBER_CHANGES_DR + 1]<<8);
    unsigned int position_temp;
    unsigned int index_of_ekran;
    unsigned int array_old[N_BIG], array_new[N_BIG], array_changing[N_BIG];
    
    //Перевіряємо, чи ми не вийшли за границі
    if (current_ekran.index_position < 0) current_ekran.index_position = max_number_changers_in_record - 1;
    else if (current_ekran.index_position >= ((int)max_number_changers_in_record)) current_ekran.index_position = 0;
    current_ekran.index_position = (current_ekran.index_position >> (POWER_MAX_ROW_LCD - 1)) << (POWER_MAX_ROW_LCD - 1);
    position_in_current_level_menu[EKRAN_CHANGES_SIGNALS_DR] = current_ekran.index_position;

    position_temp = current_ekran.index_position;
    index_of_ekran = position_temp & (unsigned int)(~((1<<(POWER_MAX_ROW_LCD>>1)) - 1));
  
    //Копіюємо  рядки у робочий екран
    for (unsigned int i=0; i< (MAX_ROW_LCD>>1); i++)
    {
      //Наступні рядки треба перевірити, чи їх требе відображати у текучій кофігурації
      if (index_of_ekran < max_number_changers_in_record)
      {
        //Шукаємо масиви зрізів: попередній до вибраної зміни і у момент даної зміни
        unsigned int index_of_the_slice = 0; //починаємо з першого зрізу
        unsigned int current_number_changes = 0;
        while (
               ((current_number_changes + buffer_for_manu_read_record[FIRST_INDEX_FIRST_DATA_DR + SD_DR*(1 + index_of_the_slice) + (SD_DR - 2)] + (buffer_for_manu_read_record[FIRST_INDEX_FIRST_DATA_DR + SD_DR*(1 + index_of_the_slice) + (SD_DR - 1)] << 8)) < (index_of_ekran + 1)) &&
               (index_of_the_slice < MAX_EVENTS_IN_ONE_RECORD)  
              )
        {
          current_number_changes += (buffer_for_manu_read_record[FIRST_INDEX_FIRST_DATA_DR + SD_DR*(1 + index_of_the_slice) + (SD_DR - 2)] + (buffer_for_manu_read_record[FIRST_INDEX_FIRST_DATA_DR + SD_DR*(1 + index_of_the_slice) + (SD_DR - 1)] << 8));
          index_of_the_slice++;
        }
        
        for (size_t j = 0; j < ( N_BIG - ((TOTAL_SIGNAL_FOR_RNG_BIG % 32) != 0) ); ++j)
        {
          array_new[j] = buffer_for_manu_read_record[FIRST_INDEX_FIRST_DATA_DR + SD_DR*(1 + index_of_the_slice    ) +  3 + 4*j] + (buffer_for_manu_read_record[FIRST_INDEX_FIRST_DATA_DR + SD_DR*(1 + index_of_the_slice    ) +  4 + 4*j]<<8) + (buffer_for_manu_read_record[FIRST_INDEX_FIRST_DATA_DR + SD_DR*(1 + index_of_the_slice    ) +  5 + 4*j]<<16) + (buffer_for_manu_read_record[FIRST_INDEX_FIRST_DATA_DR + SD_DR*(1 + index_of_the_slice    ) +  6 + 4*j]<<24);

          array_old[j] = buffer_for_manu_read_record[FIRST_INDEX_FIRST_DATA_DR + SD_DR*(1 + index_of_the_slice - 1) +  3 + 4*j] + (buffer_for_manu_read_record[FIRST_INDEX_FIRST_DATA_DR + SD_DR*(1 + index_of_the_slice - 1) +  4 + 4*j]<<8) + (buffer_for_manu_read_record[FIRST_INDEX_FIRST_DATA_DR + SD_DR*(1 + index_of_the_slice - 1) +  5 + 4*j]<<16) + (buffer_for_manu_read_record[FIRST_INDEX_FIRST_DATA_DR + SD_DR*(1 + index_of_the_slice - 1) +  6 + 4*j]<<24);
        }
				if ((TOTAL_SIGNAL_FOR_RNG_BIG  % 32 ) != 0)
        {
          array_new[N_BIG - 1] = 0;
          array_old[N_BIG - 1] = 0;
          for (size_t j = 0; j <  (NUMBER_BYTES_SAMPLE_DR - 4*( TOTAL_SIGNAL_FOR_RNG_BIG / 32 )); ++j)
          {
            array_new[N_BIG - 1] += (buffer_for_manu_read_record[FIRST_INDEX_FIRST_DATA_DR + SD_DR*(1 + index_of_the_slice    ) +  (3 + j) + 4*(N_BIG - 1)] << (8*j));

            array_old[N_BIG - 1] += (buffer_for_manu_read_record[FIRST_INDEX_FIRST_DATA_DR + SD_DR*(1 + index_of_the_slice - 1) +  (3 + j) + 4*(N_BIG - 1)] << (8*j));
          }
        }
        
        //Визначаємо, які сигнали змінилися
        for (unsigned int j = 0; j < N_BIG; j++) array_changing[j] = array_new[j] ^ array_old[j];

        //Шукаємо функцію, яку треба зараз відобразити
        int index_of_function_in_the_slice = 0; //починаємо з першого зрізу
        do
        {
          if ((array_changing[index_of_function_in_the_slice >> 5] & (1 << (index_of_function_in_the_slice & ((1<<5)-1)))) != 0)
            current_number_changes++;
          if (current_number_changes  < (index_of_ekran + 1)) index_of_function_in_the_slice++;
        }
        while (
               (current_number_changes  < (index_of_ekran + 1)) &&
               (index_of_function_in_the_slice < TOTAL_SIGNAL_FOR_RNG_BIG)
               
              );
        
        
        if ((index_of_the_slice < MAX_EVENTS_IN_ONE_RECORD) && (index_of_function_in_the_slice < TOTAL_SIGNAL_FOR_RNG_BIG) )
        {
          for (unsigned int k = 0; k < 2; k++)
          {
            if (((i<<1)+k) < MAX_ROW_LCD)
            {
              if (k == 0)
              {
                //У першому рядку відображаємо назву сигналу, який змінився
                for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[(i<<1)+k][j] = name_string_tmp[index_of_function_in_the_slice][j];
              }
              else
              {
                //У другому рядку відображаємо час зміни і яке значення прийняв зараз сигнал
                unsigned char second_row[MAX_COL_LCD] = "                ";
                unsigned char sring_of_time[8] = "        ";
                static const unsigned char ms[MAX_NAMBER_LANGUAGE][3] = 
                {
                  "мс.",
                  "мс.",
                  "ms ",
                  "мс."
                };
                static const unsigned char passive_active[MAX_NAMBER_LANGUAGE][2][5] = 
                {
                  {"Пасс.", "Акт. "},
                  {"Пас. ", "Акт. "},
                  {"Pass ", "Act  "},
                  {"Пасс.", "Акт. "}
                };
                unsigned int time_of_slice = buffer_for_manu_read_record[FIRST_INDEX_FIRST_DATA_DR + SD_DR*(1 + index_of_the_slice) + 0] + (buffer_for_manu_read_record[FIRST_INDEX_FIRST_DATA_DR + SD_DR*(1 + index_of_the_slice) + 1]<<8) + (buffer_for_manu_read_record[FIRST_INDEX_FIRST_DATA_DR + SD_DR*(1 + index_of_the_slice) + 2]<<16);
                //...(buffer_for_manu_read_record[FIRST_INDEX_FIRST_DATA_DR + SD_DR*(1 + index_of_the_slice) + 3]<<24);
                long sign = (long)(time_of_slice&(1<<23))>>23; 
                if( sign!= 0){
                    time_of_slice |= 0xff000000; 
                    time_of_slice *= (unsigned int)(-1);
                  }
                //else{
                //    time_of_slice = (time_of_slice << 9)>>9;
                //                    
                //}
                 
                //Конвертуємо цей час у рядок
                unsigned int ost, local_index = 0;
                while ((time_of_slice >= 10) && (local_index < (8 - 1 - 1)))
                {
                  ost = time_of_slice % 10;
                  sring_of_time[7-local_index] = ost + 0x30;
                  time_of_slice /= 10;
                  local_index++;
                }
                sring_of_time[7-local_index] =  time_of_slice + 0x30;
                if( sign!= 0)
                     sring_of_time[6-local_index] = '-'; 
                
                //Копіюємо цей рідок часу у наш робочий рядок
                local_index = 0;
                while ((sring_of_time[local_index] == ' ') && (local_index < 8)) local_index++;
                unsigned int local_index1 = 1;
                while (local_index < 8) second_row[local_index1++] = sring_of_time[local_index++];
                if (local_index1 < 8) second_row[local_index1++] = ' ';
                second_row[local_index1++] = ms[index_language][0];
                second_row[local_index1++] = ms[index_language][1];
                second_row[local_index1++] = ms[index_language][2];
                
                //Визначаємо стан даного дискретного сигналу
                if ((array_new[index_of_function_in_the_slice >> 5] & (1 << (index_of_function_in_the_slice & ((1<<5)-1)))) != 0)
                {
                  //Сигнал перейшов у активний стан
                  for (local_index1 = 11; local_index1 < MAX_COL_LCD; local_index1++)
                    second_row[local_index1] = passive_active[index_language][1][local_index1 - 11];
                }
                else
                {
                  //Сигнал перейшов у пасивний стан
                  for (local_index1 = 11; local_index1 < MAX_COL_LCD; local_index1++)
                    second_row[local_index1] = passive_active[index_language][0][local_index1 - 11];
                }

                for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[(i<<1)+k][j] = second_row[j];
              }
            }
          }
        }
        else
        {
          unsigned char error_string[MAX_NAMBER_LANGUAGE][2][MAX_COL_LCD] = 
          {
            {
              " Неопределенная ",
              " ошибка отображ."
            },
            {
              "  Невизначена   ",
              " помилка відобр."
            },
            {
              "   Undefined    ",
              " display error  "
            },
            {
              " Неопределенная ",
              " ошибка отображ."
            }
          };
          for (unsigned int k = 0; k < 2; k++)
          {
            if (((i<<1)+k) < MAX_ROW_LCD)
              for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[(i<<1)+k][j] = error_string[index_language][k][j];
          }
        }
      }
      else
      {
        for (unsigned int k = 0; k < 2; k++)
        {
          if (((i<<1)+k) < MAX_ROW_LCD)
            for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[(i<<1)+k][j] = ' ';
        }
      }

      index_of_ekran++;
    }
  
    //Відображення курору по вертикалі
    current_ekran.position_cursor_y = (position_temp<<1) & (MAX_ROW_LCD - 1);
    //Курсор невидимий
    current_ekran.cursor_on = 0;
  }
  else
  {
    //Пеший байт не сходиться із міткою початку запису - робимо висновок, що у біфері не достовірні дані
    static const unsigned char name_string[MAX_NAMBER_LANGUAGE][2][MAX_COL_LCD] = 
    {
      {
        " Недостоверные  ",
        "     данные     "
      },
      {
        "  Недостовірні  ",
        "      дані      "
      },
      {
        "    Invalid     ",
        "      data      "
      },
      {
        " Недостоверные  ",
        "     данные     "
      }
    };

    //Копіюємо  рядки у робочий екран
    for (unsigned int i=0; i< MAX_ROW_LCD; i++)
    {
      //Наступні рядки треба перевірити, чи їх требе відображати у текучій коффігурації
      if (i < 2)
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_language][i][j];
      else
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = ' ';
    }

    //Відображення курору по вертикалі
    current_ekran.position_cursor_y = 0;
    //Курсор не видимий
    current_ekran.cursor_on = 0;
    
    current_ekran.index_position = 0;
  }


  //Курсор по горизонталі відображається на першій позиції
  current_ekran.position_cursor_x = 0;
  //Курсор не мигає
  current_ekran.cursor_blinking_on = 0;
  //Обновити повністю весь екран
  current_ekran.current_action = ACTION_WITH_CARRENT_EKRANE_FULL_UPDATE;
}
/*****************************************************/


/*****************************************************/
//Формуємо екран відображення змін діагностики у записі реєстратора програмних подій
/*****************************************************/
void make_ekran_changing_diagnostics_pr_err_registrator(void)
{
  int index_language = index_language_in_array(current_settings.language);

  while (_GET_STATE(control_tasks_dataflash, TASK_MAMORY_READ_DATAFLASH_FOR_PR_ERR_MENU_BIT))
  {
     periodical_operations(false);
  }
  
  if (buffer_for_manu_read_record[0] == LABEL_START_RECORD_PR_ERR)
  {
    //Пеший байт сходиться із міткою початку запису - вважаємо, що у буфері достовірні дані
    static unsigned char const name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_DIAGNOSTYKA][MAX_COL_LCD] = 
    {
      {
        NAME_DIAGN_RU
      },
      {
        NAME_DIAGN_UA
      },
      {
        NAME_DIAGN_EN
      },
      {
        NAME_DIAGN_KZ
      }
    };

    unsigned char name_string_tmp[MAX_ROW_FOR_DIAGNOSTYKA][MAX_COL_LCD];

    for(unsigned int index_1 = 0; index_1 < MAX_ROW_FOR_DIAGNOSTYKA; index_1++)
    {
      for(unsigned int index_2 = 0; index_2 < MAX_COL_LCD; index_2++)
        name_string_tmp[index_1][index_2] = name_string[index_language][index_1][index_2];
      
      if ((index_1 >= ERROR_DIGITAL_OUTPUT_1_BIT) && (index_1 < (ERROR_DIGITAL_OUTPUT_1_BIT + NUMBER_SIMPLE_OUTPUTS)))
      {
        uint32_t value = 0;
        uint32_t index_board = 0, index_number = 0;
        for(size_t index_2 = 0; index_2 < MAX_COL_LCD; index_2++)
        {
          if (name_string_tmp[index_1][index_2] == '?')
          {
            if (value == 0)
            {
              //Це є умовою фіксації слова
              index_board = index_2;
              value = (index_1 - ERROR_DIGITAL_OUTPUT_1_BIT) + 1;
            }
            else
            {
              //Це є умовою фіксації номеру на слоті
              index_number = index_2;
              break;
            }
          }
        }
        
        int tmp_1 = -1, tmp_2 = -1;
        for (size_t i = 0; i < N_OUTPUT_BOARDS; i++)
        {
          if (value <= output_boards[i][0])
          {
            tmp_1 = output_boards[i][1];
            tmp_2 = (i == 0) ? value : value - output_boards[i - 1][0];
          
            break;
          }
        }
        
        name_string_tmp[index_1][index_board]  = tmp_1 + 0x40;
        name_string_tmp[index_1][index_number] = tmp_2 + 0x30;
      }
    }
    
    unsigned int max_number_changers_in_record = buffer_for_manu_read_record[13];
    unsigned int position_temp;
    unsigned int index_of_ekran;
    unsigned int diagnostic_old[N_DIAGN], diagnostic_new[N_DIAGN], diagnostic_changing[N_DIAGN];

    for (size_t i = 0; i < N_DIAGN_BYTES; i ++)
    {
      size_t n_word = i >> 2;
      size_t n_byte = i & 0x3;
      if (n_byte == 0)
      {
        diagnostic_old[n_word] = 0;
        diagnostic_new[n_word] = 0;
      }
      diagnostic_old[n_word] |= buffer_for_manu_read_record[14                 + i] << (8*n_byte);
      diagnostic_new[n_word] |= buffer_for_manu_read_record[14 + N_DIAGN_BYTES + i] << (8*n_byte);
    }
        
    //Визначаємо, які сигнали змінилися
    for (size_t i = 0; i < N_DIAGN; i ++) diagnostic_changing[i] = diagnostic_new[i] ^ diagnostic_old[i];
    
    //Перевіряємо, чи ми не вийшли за границі
    if (current_ekran.index_position < 0) current_ekran.index_position = max_number_changers_in_record - 1;
    else if (current_ekran.index_position >= ((int)max_number_changers_in_record)) current_ekran.index_position = 0;
    position_in_current_level_menu[EKRAN_CHANGES_DIAGNOSTICS_PR_ERR] = current_ekran.index_position;

    position_temp = current_ekran.index_position;
    index_of_ekran = position_temp & (unsigned int)(~((1<<(POWER_MAX_ROW_LCD>>1)) - 1));
  
    //Копіюємо  рядки у робочий екран
    for (unsigned int i=0; i< (MAX_ROW_LCD>>1); i++)
    {
      //Наступні рядки треба перевірити, чи їх требе відображати у текучій кофігурації
      if (index_of_ekran < max_number_changers_in_record)
      {
        //Шукаємо функцію, яку треба зараз відобразити
        unsigned int current_number_changes = 0;
        unsigned int index_of_diagnostic_in_the_slice = 0; //починаємо з першої функції
        do
        {
          if (_CHECK_SET_BIT(diagnostic_changing, index_of_diagnostic_in_the_slice) != 0)
            current_number_changes++;
          if (current_number_changes  < (index_of_ekran + 1)) index_of_diagnostic_in_the_slice++;
        }
        while (
               (current_number_changes  < (index_of_ekran + 1)) &&
               (index_of_diagnostic_in_the_slice < MAX_ROW_FOR_DIAGNOSTYKA)  
              );
        
        
        if (index_of_diagnostic_in_the_slice < MAX_ROW_FOR_DIAGNOSTYKA)
        {
          for (unsigned int k = 0; k < 2; k++)
          {
            if (((i<<1)+k) < MAX_ROW_LCD)
            {
              if (k == 0)
              {
                //У першому рядку відображаємо назву діагностики, який змінився
                for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[(i<<1)+k][j] = name_string_tmp[index_of_diagnostic_in_the_slice][j];
              }
              else
              {
                //У другому рядку відображаємо яке значення прийняла зараз дана діагностика
                unsigned char second_row[MAX_COL_LCD] = "                ";

                static unsigned char const passive_active[MAX_NAMBER_LANGUAGE][2][5] = 
                {
                  {"Пасс.", "Акт. "},
                  {"Пас. ", "Акт. "},
                  {"Pass ", "Act  "},
                  {"Пасс.", "Акт. "}
                };

                //Визначаємо стан даного дискретного сигналу
                if (_CHECK_SET_BIT(diagnostic_new, index_of_diagnostic_in_the_slice) != 0)
                {
                  //Сигнал перейшов у активний стан
                  for (int j = 0; j < 4; j++)
                    second_row[1 + j] = passive_active[index_language][1][j];
                }
                else
                {
                  //Сигнал перейшов у пасивний стан
                  for (int j = 0; j < 4; j++)
                    second_row[1 + j] = passive_active[index_language][0][j];
                }

                for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[(i<<1)+k][j] = second_row[j];
              }
            }
          }
        }
        else
        {
          unsigned char error_string[MAX_NAMBER_LANGUAGE][2][MAX_COL_LCD] = 
          {
            {
              " Неопределенная ",
              " ошибка отображ."
            },
            {
              "  Невизначена   ",
              " помилка відобр."
            },
            {
              "   Undefined    ",
              " display error  "
            },
            {
              " Неопределенная ",
              " ошибка отображ."
            }
          };
          for (unsigned int k = 0; k < 2; k++)
          {
            if (((i<<1)+k) < MAX_ROW_LCD)
              for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[(i<<1)+k][j] = error_string[index_language][k][j];
          }
        }
      }
      else
      {
        for (unsigned int k = 0; k < 2; k++)
        {
          if (((i<<1)+k) < MAX_ROW_LCD)
            for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[(i<<1)+k][j] = ' ';
        }
      }

      index_of_ekran++;
    }
  
    //Відображення курору по вертикалі
    current_ekran.position_cursor_y = (position_temp<<1) & (MAX_ROW_LCD - 1);
    //Курсор видимий
    current_ekran.cursor_on = 1;
  }
  else
  {
    //Пеший байт не сходиться із міткою початку запису - робимо висновок, що у біфері не достовірні дані
    static unsigned char const name_string[MAX_NAMBER_LANGUAGE][2][MAX_COL_LCD] = 
    {
      {
        " Недостоверные  ",
        "     данные     "
      },
      {
        "  Недостовірні  ",
        "      дані      "
      },
      {
        "    Invalid     ",
        "      data      "
      },
      {
        " Недостоверные  ",
        "     данные     "
      }
    };

    //Копіюємо  рядки у робочий екран
    for (unsigned int i=0; i< MAX_ROW_LCD; i++)
    {
      //Наступні рядки треба перевірити, чи їх требе відображати у текучій коффігурації
      if (i < 2)
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_language][i][j];
      else
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = ' ';
    }

    //Відображення курору по вертикалі
    current_ekran.position_cursor_y = 0;
    //Курсор не видимий
    current_ekran.cursor_on = 0;
    
    current_ekran.index_position = 0;
  }


  //Курсор по горизонталі відображається на першій позиції
  current_ekran.position_cursor_x = 0;
  //Курсор не мигає
  current_ekran.cursor_blinking_on = 0;
  //Обновити повністю весь екран
  current_ekran.current_action = ACTION_WITH_CARRENT_EKRANE_FULL_UPDATE;
}
/*****************************************************/

/*****************************************************/
//
/*****************************************************/
/*****************************************************/
