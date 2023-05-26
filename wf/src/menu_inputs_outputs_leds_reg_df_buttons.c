#include "header.h"

/*****************************************************/
//Формуємо екран вибору ДВ/ДВих/Св для ранжування
/* 
-------------------------------------------------------
Вхідний параметр
0  - входи
1  - виходи
2  - світодіоди
3  - опреділювальні функції
4  - функціональні кнопки
5  - опреділювальні триґери
6  - визначувані "І"
7  - визначувані "АБО"
8  - визначувані "Викл.АБО"
9  - визначувані "НЕ"
10 - Передавальні функції
11 - Вхідний GOOSE блок
12 - Вхідний MMS блок
13 - Вихідний мережевий блок
-------------------------------------------------------
*/
/*****************************************************/
void make_ekran_chose_of_inputs_outputs_leds_df_buttons_for_ranguvannja(__id_input_output type_of_window)
{
  static const unsigned char information[MAX_NAMBER_LANGUAGE][_MAX_ID_INPUT_OUPUT][MAX_COL_LCD] = 
  {
    {
      " Двх.           ",
      " Двых.          ",
      " Св             ",
      " О-функция      ",
      " F              ",
      " О-триггер      ",
      " О-И            ",
      " О-ИЛИ          ",
      " О-Искл.ИЛИ     ",
      " О-НЕ           ",
      " Пер.ф.         ",
      " Выключатель(x) "
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
      ,
      " Вх.GOOSE Блок  ",
      " Вх.MMS Блок    ",
      " ВМБ            "
#endif
    },
    {
      " Двх.           ",
      " Двих.          ",
      " Св             ",
      " В-функція      ",
      " F              ",
      " В-триґер       ",
      " В-І            ",
      " В-АБО          ",
      " В-Викл.АБО     ",
      " В-НЕ           ",
      " Пер.ф.         ",
      " Вимикач(x)     "
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
      , 
      " Вх.GOOSE Блок  ",
      " Вх.MMS Блок    ", 
      " ВМБ            "
#endif
    },
    {
      " BI.            ",
      " BO.            ",
      " LED            ",
      " UD-Function    ",
      " F              ",
      " UD-FF          ",
      " AND            ",
      " OR             ",
      " XOR            ",
      " NOT            ",
      " Transfer func  ",
      " CB(x)          "
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
      ,
      " GSERECEIVxx    ",
      " MMSRECEIVxx    ",
      " NETSENDxx      "
#endif
    },
    {
      " Двх.           ",
      " Двых.          ",
      " Св             ",
      " О-функция      ",
      " F              ",
      " О-триггер      ",
      " О-И            ",
      " О-ИЛИ          ",
      " О-Искл.ИЛИ     ",
      " О-НЕ           ",
      " Пер.ф.         ",
      " Выключатель(x) "
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
      ,
      " Вх.GOOSE Блок  ",
      " Вх.MMS Блок    ",
      " ВМБ            "
#endif
    }
  };

  static const unsigned int first_index_number[MAX_NAMBER_LANGUAGE][_MAX_ID_INPUT_OUPUT] = 
  {
    {5, 6, 3, 10, 2, 10, 4, 6, 11, 5, 7, 13
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
      , 14, 12, 4 
#endif
    },
    {5, 6, 3, 10, 2,  9, 4, 6, 11, 5, 7,  9
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
      , 14, 12, 4
#endif
    },
    {4, 4, 4, 12, 2, 13, 7, 6,  7, 6, 6,  4
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
      , 13, 13, 4
#endif
    },
    {5, 6, 3, 10, 2, 10, 4, 6, 11, 5, 7, 13
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
      , 14, 12, 4
#endif
    }
  };
  
  static const unsigned int max_row[_MAX_ID_INPUT_OUPUT] =
  {
    MAX_ROW_LIST_INPUTS_FOR_RANGUVANNJA,
    MAX_ROW_LIST_OUTPUTS_FOR_RANGUVANNJA,
    MAX_ROW_LIST_LEDS_FOR_RANGUVANNJA,
    MAX_ROW_FOR_LIST_DF,
    MAX_ROW_LIST_BUTTONS_FOR_RANGUVANNJA,
    MAX_ROW_FOR_LIST_DT,
    MAX_ROW_FOR_LIST_D_AND,
    MAX_ROW_FOR_LIST_D_OR,
    MAX_ROW_FOR_LIST_D_XOR,
    MAX_ROW_FOR_LIST_D_NOT,
    MAX_ROW_FOR_LIST_TF,
    NUMBER_OFF_ON
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)    
    ,
    N_IN_GOOSE,
    N_IN_MMS,
    N_OUT_LAN
#endif
  };
  int index_language = index_language_in_array(current_settings.language);
  unsigned int first_index_number_1 = first_index_number[index_language][type_of_window];
        
  unsigned int position_temp = current_ekran.index_position;
  unsigned int index_of_ekran = (position_temp >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;

  //Формуємо рядки  у робочий екран
  for (unsigned int i=0; i< MAX_ROW_LCD; i++)
  {
    //Наступні рядки треба перевірити, чи їх требе відображати у текучій кофігурації
    if (index_of_ekran < max_row[type_of_window])
    {
      unsigned int number = index_of_ekran + 1;
      
#ifdef NUMBER_DS
      if ((type_of_window == ID_OUTPUT) && (number > NUMBER_SIMPLE_OUTPUTS))
      {
        static unsigned char const ds_name[MAX_NAMBER_LANGUAGE][MAX_COL_LCD] = 
        {
          " ДШ             ",
          " ДШ             ",
          " DSh            ",
          " ДШ             "
        };
        for (size_t j = 0; j != MAX_COL_LCD; ++j) 
        {
          working_ekran[i][j] = ds_name[index_language][j];
        }
      }
      else
#endif
      {
        int tmp_1 = -1, tmp_2 = -1;
    
        if (type_of_window == ID_INPUT)
        {
          for (size_t j = 0; j < N_INPUT_BOARDS; j++)
          {
            if (number <= input_boards[j][0])
            {
              tmp_1 = input_boards[j][1];
              tmp_2 = (j == 0) ? number : number - input_boards[j - 1][0];
          
              break;
            }
          }
        }
        else if (type_of_window == ID_OUTPUT)
        {
          for (size_t j = 0; j < N_OUTPUT_BOARDS; j++)
          {
            if (number <= output_boards[j][0])
            {
              tmp_1 = output_boards[j][1];
              tmp_2 = (j == 0) ? number : number - output_boards[j - 1][0];
          
              break;
            }
          }
        }
        else
        {
          tmp_1 = (number / 10);
          tmp_2 = number - tmp_1*10;
        }

        for (size_t j = 0; j < MAX_COL_LCD; ++j)
        {
          if (type_of_window != ID_OFF_ON)
          {
            if (
                (type_of_window == ID_LED) && 
                (number > (NUMBER_LEDS - 2)) && 
                (j >= first_index_number_1) &&
                (j <  (first_index_number_1 + 6))
               )
            {
              char const leds_fix[2][6] = 
              {
               "-Start",
               "-Trip "
              };
              working_ekran[i][j] = leds_fix[(number == NUMBER_LEDS)][j - first_index_number_1];
           
            }
            else if ((j < first_index_number_1) || (j >= (first_index_number_1 + 3)))
              working_ekran[i][j] = information[index_language][type_of_window][j];
            else
            {
              if (j == (first_index_number_1 + 0))
              {
                if (tmp_1 < 0) working_ekran[i][j] = '?';
                else if (tmp_1 > 0 ) 
                {
                  if (
                      (type_of_window != ID_INPUT) &&
                      (type_of_window != ID_OUTPUT)
                     )  
                  {
                    working_ekran[i][j] = tmp_1 + 0x30;
                  }
                  else
                  {
                    working_ekran[i][j] = tmp_1 + 0x40;
                  }
                }
              }
              else if (
                       (j == (first_index_number_1 + 1)) &&
                       (
                        (type_of_window == ID_INPUT) ||
                        (type_of_window == ID_OUTPUT)
                       )    
                      )   
              {
                working_ekran[i][j] = '.';
              }
              else if (
                       (j == (first_index_number_1 + 1))
                       /*попередня перевірка вже перевірила, що якщо (j == (first_index_number_1 + 1)), то type_of_window != ID_INPUT і ID_OUTPUT*/  
                       ||
                       (
                        (j == (first_index_number_1 + 2)) &&
                        (
                         (type_of_window == ID_INPUT) ||
                         (type_of_window == ID_OUTPUT)
                        )   
                       ) 
                      )   
              {
                if (
                    (tmp_1 > 0) ||
                    (tmp_1 < 0)  
                   )   
                {
                  if (tmp_2 < 0) working_ekran[i][j] = '?';
                  else working_ekran[i][j] = tmp_2 + 0x30;
                }
                else
                {
                  if (tmp_2 < 0) working_ekran[i][j] = '?';
                  else
                  {
                    working_ekran[i][j - 1] = tmp_2 + 0x30;
                    working_ekran[i][j] = '.';
                  }
                }
              }
              else working_ekran[i][j] = ' ';
            }
          }
          else
          {
            if (j != first_index_number_1) working_ekran[i][j] = information[index_language][ID_OFF_ON][j];
            else
            {
              tmp_2 -= 1;
              if ((tmp_1 == 0) && (tmp_2 < NUMBER_OFF_ON))
              {
                working_ekran[i][j] = OFF_ON_value[index_language][tmp_2];
              }
              else working_ekran[i][j] = '?';
            }
          }
        }
      }
    }
    else
    {
      for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = ' ';
    }

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
//Формуємо екран відображення зранжованих сигналів на вибраний вхід
/*****************************************************/
void make_ekran_set_function_in_bi(unsigned int number_ekran, unsigned int type_ekran)
{
#define NUMBER_ROW_FOR_NOTHING_INFORMATION 2
  
  unsigned int state_viewing_input[N_SMALL];
  unsigned int max_row_ranguvannja = 0;
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][TOTAL_SIGNAL_FOR_RANG_SMALL_A01 - TOTAL_UP_SIGNAL_FOR_RANG_SMALL + 1 + NUMBER_ROW_FOR_NOTHING_INFORMATION][MAX_COL_LCD] = 
  {
    {
      "      Нет       ",
      "  ранжирования  ",
      NAME_RANG_SMALL_A01_RU //NAME_RANG_SMALL_RU
    },
    {
      "      Нема      ",
      "   ранжування   ",
      NAME_RANG_SMALL_A01_UA //NAME_RANG_SMALL_UA
    },
    {
      "       No       ",
      "    ranking     ",
      NAME_RANG_SMALL_A01_EN //NAME_RANG_SMALL_EN
    },
    {
      "      Нет       ",
      "  ранжирования  ",
      NAME_RANG_SMALL_A01_KZ //NAME_RANG_SMALL_KZ
    }
  };
  static const uint32_t index_number_UP[MAX_NAMBER_LANGUAGE][1] = 
  {
    {11}, 
    {11}, 
    { 6}, 
    {11}
  };
  
  unsigned char name_string_tmp[TOTAL_SIGNAL_FOR_RANG_SMALL_A01 + NUMBER_ROW_FOR_NOTHING_INFORMATION][MAX_COL_LCD];

  int index_language = index_language_in_array(current_settings.language);
  for(int index_1 = 0; index_1 < (TOTAL_SIGNAL_FOR_RANG_SMALL_A01 + NUMBER_ROW_FOR_NOTHING_INFORMATION); index_1++)
  {
    unsigned int index_row;
    if (index_1 < (TOTAL_SIGNAL_FOR_RANG_SMALL_A01 + NUMBER_ROW_FOR_NOTHING_INFORMATION - TOTAL_EL_SIGNAL_FOR_RANG_SMALL - TOTAL_VMP_SIGNAL_FOR_RANG_SMALL - TOTAL_UP_SIGNAL_FOR_RANG_SMALL)) 
    {
      index_row = index_1;
    }
    else if (index_1 < (TOTAL_SIGNAL_FOR_RANG_SMALL_A01 + NUMBER_ROW_FOR_NOTHING_INFORMATION - TOTAL_EL_SIGNAL_FOR_RANG_SMALL - TOTAL_VMP_SIGNAL_FOR_RANG_SMALL))
    {
      index_row = (TOTAL_SIGNAL_FOR_RANG_SMALL_A01 + NUMBER_ROW_FOR_NOTHING_INFORMATION - TOTAL_EL_SIGNAL_FOR_RANG_SMALL - TOTAL_VMP_SIGNAL_FOR_RANG_SMALL - TOTAL_UP_SIGNAL_FOR_RANG_SMALL) + ((index_1 - (TOTAL_SIGNAL_FOR_RANG_SMALL_A01 + NUMBER_ROW_FOR_NOTHING_INFORMATION - TOTAL_EL_SIGNAL_FOR_RANG_SMALL - TOTAL_VMP_SIGNAL_FOR_RANG_SMALL - TOTAL_UP_SIGNAL_FOR_RANG_SMALL)) % 1);
    }
    else
    {
      index_row = index_1 - TOTAL_UP_SIGNAL_FOR_RANG_SMALL + 1;
    }
      
    for(int index_2 = 0; index_2 < MAX_COL_LCD; index_2++)
    {
      if (
          (index_1 >= (TOTAL_SIGNAL_FOR_RANG_SMALL_A01 + NUMBER_ROW_FOR_NOTHING_INFORMATION - TOTAL_EL_SIGNAL_FOR_RANG_SMALL - TOTAL_VMP_SIGNAL_FOR_RANG_SMALL - TOTAL_UP_SIGNAL_FOR_RANG_SMALL))  &&
          (index_1 <  (TOTAL_SIGNAL_FOR_RANG_SMALL_A01 + NUMBER_ROW_FOR_NOTHING_INFORMATION - TOTAL_EL_SIGNAL_FOR_RANG_SMALL - TOTAL_VMP_SIGNAL_FOR_RANG_SMALL)) &&
          (index_2 == index_number_UP[index_language][(index_1 - (TOTAL_SIGNAL_FOR_RANG_SMALL_A01 + NUMBER_ROW_FOR_NOTHING_INFORMATION - TOTAL_EL_SIGNAL_FOR_RANG_SMALL - TOTAL_VMP_SIGNAL_FOR_RANG_SMALL - TOTAL_UP_SIGNAL_FOR_RANG_SMALL)) % 1]) 
         )
      {
        name_string_tmp[index_1][index_2] = 0x30 + ((index_1 - (TOTAL_SIGNAL_FOR_RANG_SMALL_A01 + NUMBER_ROW_FOR_NOTHING_INFORMATION - TOTAL_EL_SIGNAL_FOR_RANG_SMALL - TOTAL_VMP_SIGNAL_FOR_RANG_SMALL - TOTAL_UP_SIGNAL_FOR_RANG_SMALL)) / 1 + 1);
      }
      else name_string_tmp[index_1][index_2] = name_string[index_language][index_row][index_2];
    }
  }
  
  unsigned int not_null = false;
  if (type_ekran == INDEX_VIEWING_BUTTON)
  {
    if(current_ekran.edition == 0)
    {
      for (unsigned int i = 0; i < N_SMALL; i++)
      {
        state_viewing_input[i] = current_settings.ranguvannja_buttons[N_SMALL*(number_ekran - EKRAN_RANGUVANNJA_BUTTON_1) + i];
        not_null |= (state_viewing_input[i] != 0);
      }
    }
    else
    {
      for (unsigned int i = 0; i < N_SMALL; i++)
      {
        state_viewing_input[i] = edition_settings.ranguvannja_buttons[N_SMALL*(number_ekran - EKRAN_RANGUVANNJA_BUTTON_1) + i];
        not_null |= (state_viewing_input[i] != 0);
      }
    }
    max_row_ranguvannja = MAX_ROW_RANGUVANNJA_BUTTON;
  }
  else if (type_ekran == INDEX_VIEWING_INPUT)
  {
    if(current_ekran.edition == 0)
    {
      for (unsigned int i = 0; i < N_SMALL; i++)
      {
        state_viewing_input[i] = current_settings.ranguvannja_inputs[N_SMALL*(number_ekran - EKRAN_RANGUVANNJA_INPUT_1) + i];
        not_null |= (state_viewing_input[i] != 0);
      }
    }
    else
    {
      for (unsigned int i = 0; i < N_SMALL; i++)
      {
        state_viewing_input[i] = edition_settings.ranguvannja_inputs[N_SMALL*(number_ekran - EKRAN_RANGUVANNJA_INPUT_1) + i];
        not_null |= (state_viewing_input[i] != 0);
      }
    }
    max_row_ranguvannja = MAX_ROW_RANGUVANNJA_INPUT;
  }
  else total_error_sw_fixed();
  
  if(current_ekran.edition == 0)
  {
    //Випадок, коли ми продивляємося зранжовані функції на вході
    if (not_null == false)
    {
      //Це означає, що на даний вхід нічого не відранжовано
      
      //Текучу позицію в сипску переводимо на сам початок
      current_ekran.index_position = 0;
      position_in_current_level_menu[number_ekran] = 0;

      //Копіюємо  рядки у робочий екран
      for (unsigned int i=0; i< MAX_ROW_LCD; i++)
      {
        //Копіюємо в робочий екран інформацію, що нічого не відранжовано
        if (i < NUMBER_ROW_FOR_NOTHING_INFORMATION)
          for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string_tmp[i][j];
        else
          for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = ' ';
      }

      //Відображення курору по вертикалі
      current_ekran.position_cursor_y = 0;
      //Курсор невидимий
      current_ekran.cursor_on = 0;
    }
    else
    {
      /************************************************************/
      //Формуємо список із функцій, які реально відранжовані
      /************************************************************/
      unsigned int position_temp = current_ekran.index_position;
      unsigned int index_of_ekran;
      unsigned int i = 0, offset = 0;
      unsigned int state_current_bit;

      while ((i + offset) < max_row_ranguvannja)
      {
        state_current_bit = state_viewing_input[(i + offset)>>5] & (1<<((i + offset) & 0x1f));

        if (state_current_bit == 0)
        {
          for (unsigned int j = i; j < (max_row_ranguvannja - offset); j++)
          {
            if ((j + 1) < (max_row_ranguvannja - offset))
            {
              for (unsigned int k = 0; k<MAX_COL_LCD; k++)
                name_string_tmp[j + NUMBER_ROW_FOR_NOTHING_INFORMATION][k] = name_string_tmp[j + NUMBER_ROW_FOR_NOTHING_INFORMATION + 1][k];
            }
            else 
            {
              for (unsigned int k = 0; k<MAX_COL_LCD; k++)
                name_string_tmp[j + NUMBER_ROW_FOR_NOTHING_INFORMATION][k] = ' ';
            }
          }
          if (current_ekran.index_position >= ((int)(i + offset))) position_temp--;
          offset++;
        }
        else i++;
      }
      /************************************************************/

      index_of_ekran = (position_temp >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;
      
      //Копіюємо  рядки у робочий екран
      for (i=0; i< MAX_ROW_LCD; i++)
      {
        //Наступні рядки треба перевірити, чи їх требе відображати у текучій коффігурації
        if (index_of_ekran < max_row_ranguvannja)
        {
          for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string_tmp[index_of_ekran + NUMBER_ROW_FOR_NOTHING_INFORMATION][j];

          //Підтягуємо назву, щоб не було спереді багато пробілів
          unsigned int iteration = 0;
          while (
                 (working_ekran[i][0] == ' ') &&
                 (working_ekran[i][1] == ' ') &&
                 (iteration < (MAX_COL_LCD - 1 - 1))
                )
          {
            for (unsigned int j = 1; j < MAX_COL_LCD; j++)
            {
              if ((j + 1) < MAX_COL_LCD)
                working_ekran[i][j] = working_ekran[i][j + 1];
              else
                working_ekran[i][j] = ' ';
            }
            iteration++;
          }
        }
        else
          for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = ' ';

        index_of_ekran++;
      }
      //Відображення курору по вертикалі
      current_ekran.position_cursor_y = position_temp & (MAX_ROW_LCD - 1);
      //Курсор видимий
      current_ekran.cursor_on = 1;
    }
    
    //Курсор по горизонталі відображається на першій позиції
    current_ekran.position_cursor_x = 0;
    //Курсор не мигає
    current_ekran.cursor_blinking_on = 0;
  }
  else
  {
    unsigned int position_temp = current_ekran.index_position;
    unsigned int index_of_ekran;
    unsigned int i, offset = 0;
    int min_max_number[TOTAL_NUMBER_PROTECTION][2] =
    {
      {
       (TOTAL_GENERAL_SIGNAL_FOR_RANG_SMALL),
       (TOTAL_GENERAL_SIGNAL_FOR_RANG_SMALL + TOTAL_DZO_SIGNAL_FOR_RANG_SMALL - 1)
      },
      {
       (TOTAL_GENERAL_SIGNAL_FOR_RANG_SMALL + TOTAL_DZO_SIGNAL_FOR_RANG_SMALL),
       (TOTAL_GENERAL_SIGNAL_FOR_RANG_SMALL + TOTAL_DZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MTZ_STUB_SIGNAL_FOR_RANG_SMALL - 1)
      },
      {
       (TOTAL_GENERAL_SIGNAL_FOR_RANG_SMALL + TOTAL_DZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MTZ_STUB_SIGNAL_FOR_RANG_SMALL),
       (TOTAL_GENERAL_SIGNAL_FOR_RANG_SMALL + TOTAL_DZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MTZ_STUB_SIGNAL_FOR_RANG_SMALL + TOTAL_ZDZ_SIGNAL_FOR_RANG_SMALL - 1)
      },
      {
       (TOTAL_GENERAL_SIGNAL_FOR_RANG_SMALL + TOTAL_DZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MTZ_STUB_SIGNAL_FOR_RANG_SMALL + TOTAL_ZDZ_SIGNAL_FOR_RANG_SMALL),
       (TOTAL_GENERAL_SIGNAL_FOR_RANG_SMALL + TOTAL_DZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MTZ_STUB_SIGNAL_FOR_RANG_SMALL + TOTAL_ZDZ_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZO_SIGNAL_FOR_RANG_SMALL - 1)
      },
      {
       (TOTAL_GENERAL_SIGNAL_FOR_RANG_SMALL + TOTAL_DZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MTZ_STUB_SIGNAL_FOR_RANG_SMALL + TOTAL_ZDZ_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZO_SIGNAL_FOR_RANG_SMALL),
       (TOTAL_GENERAL_SIGNAL_FOR_RANG_SMALL + TOTAL_DZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MTZ_STUB_SIGNAL_FOR_RANG_SMALL + TOTAL_ZDZ_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZR_SIGNAL_FOR_RANG_SMALL - 1)
      },
      {
       (TOTAL_GENERAL_SIGNAL_FOR_RANG_SMALL + TOTAL_DZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MTZ_STUB_SIGNAL_FOR_RANG_SMALL + TOTAL_ZDZ_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZR_SIGNAL_FOR_RANG_SMALL),
       (TOTAL_GENERAL_SIGNAL_FOR_RANG_SMALL + TOTAL_DZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MTZ_STUB_SIGNAL_FOR_RANG_SMALL + TOTAL_ZDZ_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZR_SIGNAL_FOR_RANG_SMALL + TOTAL_APV_SIGNAL_FOR_RANG_SMALL - 1)
      },
      {
       (TOTAL_GENERAL_SIGNAL_FOR_RANG_SMALL + TOTAL_DZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MTZ_STUB_SIGNAL_FOR_RANG_SMALL + TOTAL_ZDZ_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZR_SIGNAL_FOR_RANG_SMALL + TOTAL_APV_SIGNAL_FOR_RANG_SMALL),
       (TOTAL_GENERAL_SIGNAL_FOR_RANG_SMALL + TOTAL_DZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MTZ_STUB_SIGNAL_FOR_RANG_SMALL + TOTAL_ZDZ_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZR_SIGNAL_FOR_RANG_SMALL + TOTAL_APV_SIGNAL_FOR_RANG_SMALL + TOTAL_ACHR_SIGNAL_FOR_RANG_SMALL - 1)
      },
      {
       (TOTAL_GENERAL_SIGNAL_FOR_RANG_SMALL + TOTAL_DZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MTZ_STUB_SIGNAL_FOR_RANG_SMALL + TOTAL_ZDZ_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZR_SIGNAL_FOR_RANG_SMALL + TOTAL_APV_SIGNAL_FOR_RANG_SMALL + TOTAL_ACHR_SIGNAL_FOR_RANG_SMALL),
       (TOTAL_GENERAL_SIGNAL_FOR_RANG_SMALL + TOTAL_DZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MTZ_STUB_SIGNAL_FOR_RANG_SMALL + TOTAL_ZDZ_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZR_SIGNAL_FOR_RANG_SMALL + TOTAL_APV_SIGNAL_FOR_RANG_SMALL + TOTAL_ACHR_SIGNAL_FOR_RANG_SMALL  + TOTAL_UROV_SIGNAL_FOR_RANG_SMALL - 1)
      },
      {
       (TOTAL_GENERAL_SIGNAL_FOR_RANG_SMALL + TOTAL_DZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MTZ_STUB_SIGNAL_FOR_RANG_SMALL + TOTAL_ZDZ_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZR_SIGNAL_FOR_RANG_SMALL + TOTAL_APV_SIGNAL_FOR_RANG_SMALL + TOTAL_ACHR_SIGNAL_FOR_RANG_SMALL  + TOTAL_UROV_SIGNAL_FOR_RANG_SMALL),
       (TOTAL_GENERAL_SIGNAL_FOR_RANG_SMALL + TOTAL_DZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MTZ_STUB_SIGNAL_FOR_RANG_SMALL + TOTAL_ZDZ_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZR_SIGNAL_FOR_RANG_SMALL + TOTAL_APV_SIGNAL_FOR_RANG_SMALL + TOTAL_ACHR_SIGNAL_FOR_RANG_SMALL  + TOTAL_UROV_SIGNAL_FOR_RANG_SMALL + TOTAL_DZR_SIGNAL_FOR_RANG_SMALL - 1)
      },
      {
       (TOTAL_GENERAL_SIGNAL_FOR_RANG_SMALL + TOTAL_DZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MTZ_STUB_SIGNAL_FOR_RANG_SMALL + TOTAL_ZDZ_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZR_SIGNAL_FOR_RANG_SMALL + TOTAL_APV_SIGNAL_FOR_RANG_SMALL + TOTAL_ACHR_SIGNAL_FOR_RANG_SMALL  + TOTAL_UROV_SIGNAL_FOR_RANG_SMALL + TOTAL_DZR_SIGNAL_FOR_RANG_SMALL),
       (TOTAL_GENERAL_SIGNAL_FOR_RANG_SMALL + TOTAL_DZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MTZ_STUB_SIGNAL_FOR_RANG_SMALL + TOTAL_ZDZ_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZR_SIGNAL_FOR_RANG_SMALL + TOTAL_APV_SIGNAL_FOR_RANG_SMALL + TOTAL_ACHR_SIGNAL_FOR_RANG_SMALL  + TOTAL_UROV_SIGNAL_FOR_RANG_SMALL + TOTAL_DZR_SIGNAL_FOR_RANG_SMALL + TOTAL_UMIN_SIGNAL_FOR_RANG_SMALL - 1)
      },
      {
       (TOTAL_GENERAL_SIGNAL_FOR_RANG_SMALL + TOTAL_DZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MTZ_STUB_SIGNAL_FOR_RANG_SMALL + TOTAL_ZDZ_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZR_SIGNAL_FOR_RANG_SMALL + TOTAL_APV_SIGNAL_FOR_RANG_SMALL + TOTAL_ACHR_SIGNAL_FOR_RANG_SMALL  + TOTAL_UROV_SIGNAL_FOR_RANG_SMALL + TOTAL_DZR_SIGNAL_FOR_RANG_SMALL + TOTAL_UMIN_SIGNAL_FOR_RANG_SMALL),
       (TOTAL_GENERAL_SIGNAL_FOR_RANG_SMALL + TOTAL_DZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MTZ_STUB_SIGNAL_FOR_RANG_SMALL + TOTAL_ZDZ_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZR_SIGNAL_FOR_RANG_SMALL + TOTAL_APV_SIGNAL_FOR_RANG_SMALL + TOTAL_ACHR_SIGNAL_FOR_RANG_SMALL  + TOTAL_UROV_SIGNAL_FOR_RANG_SMALL + TOTAL_DZR_SIGNAL_FOR_RANG_SMALL + TOTAL_UMIN_SIGNAL_FOR_RANG_SMALL + TOTAL_UMAX_SIGNAL_FOR_RANG_SMALL - 1)
      },
      {
       (TOTAL_GENERAL_SIGNAL_FOR_RANG_SMALL + TOTAL_DZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MTZ_STUB_SIGNAL_FOR_RANG_SMALL + TOTAL_ZDZ_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZR_SIGNAL_FOR_RANG_SMALL + TOTAL_APV_SIGNAL_FOR_RANG_SMALL + TOTAL_ACHR_SIGNAL_FOR_RANG_SMALL  + TOTAL_UROV_SIGNAL_FOR_RANG_SMALL + TOTAL_DZR_SIGNAL_FOR_RANG_SMALL + TOTAL_UMIN_SIGNAL_FOR_RANG_SMALL + TOTAL_UMAX_SIGNAL_FOR_RANG_SMALL),
       (TOTAL_GENERAL_SIGNAL_FOR_RANG_SMALL + TOTAL_DZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MTZ_STUB_SIGNAL_FOR_RANG_SMALL + TOTAL_ZDZ_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZR_SIGNAL_FOR_RANG_SMALL + TOTAL_APV_SIGNAL_FOR_RANG_SMALL + TOTAL_ACHR_SIGNAL_FOR_RANG_SMALL  + TOTAL_UROV_SIGNAL_FOR_RANG_SMALL + TOTAL_DZR_SIGNAL_FOR_RANG_SMALL + TOTAL_UMIN_SIGNAL_FOR_RANG_SMALL + TOTAL_UMAX_SIGNAL_FOR_RANG_SMALL + TOTAL_UP_SIGNAL_FOR_RANG_SMALL - 1)
      },
      {-1,-1},
      {
       (TOTAL_GENERAL_SIGNAL_FOR_RANG_SMALL + TOTAL_DZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MTZ_STUB_SIGNAL_FOR_RANG_SMALL + TOTAL_ZDZ_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZR_SIGNAL_FOR_RANG_SMALL + TOTAL_APV_SIGNAL_FOR_RANG_SMALL + TOTAL_ACHR_SIGNAL_FOR_RANG_SMALL + TOTAL_UROV_SIGNAL_FOR_RANG_SMALL + TOTAL_DZR_SIGNAL_FOR_RANG_SMALL + TOTAL_UMIN_SIGNAL_FOR_RANG_SMALL + TOTAL_UMAX_SIGNAL_FOR_RANG_SMALL + TOTAL_UP_SIGNAL_FOR_RANG_SMALL + TOTAL_VMP_SIGNAL_FOR_RANG_SMALL),
       (TOTAL_GENERAL_SIGNAL_FOR_RANG_SMALL + TOTAL_DZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MTZ_STUB_SIGNAL_FOR_RANG_SMALL + TOTAL_ZDZ_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZR_SIGNAL_FOR_RANG_SMALL + TOTAL_APV_SIGNAL_FOR_RANG_SMALL + TOTAL_ACHR_SIGNAL_FOR_RANG_SMALL + TOTAL_UROV_SIGNAL_FOR_RANG_SMALL + TOTAL_DZR_SIGNAL_FOR_RANG_SMALL + TOTAL_UMIN_SIGNAL_FOR_RANG_SMALL + TOTAL_UMAX_SIGNAL_FOR_RANG_SMALL + TOTAL_UP_SIGNAL_FOR_RANG_SMALL + TOTAL_VMP_SIGNAL_FOR_RANG_SMALL + TOTAL_EL_SIGNAL_FOR_RANG_SMALL - 1)
      }
    };
    
    /*************************************************************/
    //Фільтруємо сигнали, яких у даній конфігурації неприсутні
    /*************************************************************/
    if(type_ekran == INDEX_VIEWING_BUTTON)
    {
      /*************************************************************/
      //У випадку, якщо відображення здійснюється вікна функціональних кнопок
      /*************************************************************/
      uint32_t mode = (current_settings.buttons_mode >> (number_ekran - EKRAN_RANGUVANNJA_BUTTON_1)) & 0x1;

      for (unsigned int index_deleted_function = 0; index_deleted_function < TOTAL_GENERAL_SIGNAL_FOR_RANG_SMALL; index_deleted_function++)
      {
        if (_CHECK_SET_BIT(buttons_mode[mode], index_deleted_function) == 0)
        {
          /*************************************************************/
          //Відкидаємо ім'я даної функції і зміщаємо біти
          /*************************************************************/

          //Формуємо маску біт, які не треба переміщати при переміщенні імен полів
          unsigned int maska[N_SMALL];
          for (size_t k = 0; k < N_SMALL; ++k) maska[k] = 0;
          for (unsigned int j = 0; j < (index_deleted_function - offset); j++) _SET_BIT(maska, j);
          
          /***/
          //Зміщуємо біти стану реанжування функцій разом із їх назвами
          /***/
          unsigned int new_temp_data_1[N_SMALL], new_temp_data_2[N_SMALL];

          for (unsigned int k = 0; k < N_SMALL; k++)
          {
            new_temp_data_1[k] = state_viewing_input[k] & maska[k];

            new_temp_data_2[k] = state_viewing_input[k] & (~maska[k]);
          }

          for (unsigned int k = 0; k < (N_SMALL - 1); k++)
          {
            new_temp_data_2[k] = ( (new_temp_data_2[k] >> 1) | ((new_temp_data_2[k + 1] & 0x1) << 31) ) & (~maska[k]);
          }
          new_temp_data_2[N_SMALL - 1] =  (new_temp_data_2[N_SMALL - 1] >> 1) & (~maska[N_SMALL - 1]);
                
          for (unsigned int k = 0; k < N_SMALL; k++)
          {
            state_viewing_input[k] = new_temp_data_1[k] | new_temp_data_2[k];
          }
          /***/
          for (unsigned int j = (index_deleted_function - offset); j < (max_row_ranguvannja - offset); j++)
          {
            if ((j + 1) < (max_row_ranguvannja - offset))
            {
              for (unsigned int k = 0; k < MAX_COL_LCD; k++)
                name_string_tmp[j + NUMBER_ROW_FOR_NOTHING_INFORMATION][k] = name_string_tmp[j + NUMBER_ROW_FOR_NOTHING_INFORMATION + 1][k];
            }
            else 
            {
              for (unsigned int k = 0; k  <MAX_COL_LCD; k++)
                name_string_tmp[j + NUMBER_ROW_FOR_NOTHING_INFORMATION][k] = ' ';
            }
          }
          if (current_ekran.index_position >= ((int)index_deleted_function)) position_temp--;
          offset++;
          /*************************************************************/
        }
      }
      /*************************************************************/
    }

    //Функції загального призначення пропускаємо (вони знаходяться у початку списку), тому починаємо з першого захисту
    int index_in_list = TOTAL_GENERAL_SIGNAL_FOR_RANG_SMALL;
    
    for (i = 0; i < TOTAL_NUMBER_PROTECTION; i++)
    {
      
      if((current_settings.configuration & (1 << i)) != 0)
      {
        //Захист присутнійсть, тому функції фільтрувати не потрібно - переводимо індекс на наступні функції
        //Додаємо кількість функцій до поточного індексу, якщо для поточного захисту реально були присутні функції,
        //бо інкаше ми вже знаходимося на індексі наступного захисту
        if(min_max_number[i][0] >=0)
        {
          if(type_ekran == INDEX_VIEWING_BUTTON)
          {
            /*
            Випадок коли деякі сигнали треба відфільтрувати
            */
            uint32_t mode = (current_settings.buttons_mode >> (number_ekran - EKRAN_RANGUVANNJA_BUTTON_1)) & 0x1;

            //Відкидати імена функцій і зміщати біти треба тільки у тому випадку, якщо функції пристні у списку для ранжування для даного захисту
            //Формуємо маску біт, які не треба переміщати при переміщенні імен полів
            unsigned int maska[N_SMALL];
            for (size_t k = 0; k < N_SMALL; ++k) maska[k] = 0;
            unsigned int j1;
            for (j1 = 0; j1 < (min_max_number[i][0] - offset); j1++) _SET_BIT(maska, j1);
          
            //Відкидаємо назви функцій із списку, які є зайвими
            while(index_in_list <= min_max_number[i][1])
            {
              if (_CHECK_SET_BIT(buttons_mode[mode], index_in_list) == 0) 
              {
                /***/
                //Зміщуємо біти стану реанжування функцій разом із їх назвами
                /***/
                unsigned int new_temp_data_1[N_SMALL], new_temp_data_2[N_SMALL];

                for (unsigned int k = 0; k < N_SMALL; k++)
                {
                  new_temp_data_1[k] = state_viewing_input[k] & maska[k];

                  new_temp_data_2[k] = state_viewing_input[k] & (~maska[k]);
                }

                for (unsigned int k = 0; k < (N_SMALL - 1); k++)
                {
                  new_temp_data_2[k] = ( (new_temp_data_2[k] >> 1) | ((new_temp_data_2[k + 1] & 0x1) << 31) ) & (~maska[k]);
                }
                new_temp_data_2[N_SMALL - 1] =  (new_temp_data_2[N_SMALL - 1] >> 1) & (~maska[N_SMALL - 1]);
                
                for (unsigned int k = 0; k < N_SMALL; k++)
                {
                  state_viewing_input[k] = new_temp_data_1[k] | new_temp_data_2[k];
                }
                /***/
                for (unsigned int j = (index_in_list - offset); j < (max_row_ranguvannja - offset); j++)
                {
                  if ((j + 1) < (max_row_ranguvannja - offset))
                  {
                    for (unsigned int k = 0; k < MAX_COL_LCD; k++)
                      name_string_tmp[j + NUMBER_ROW_FOR_NOTHING_INFORMATION][k] = name_string_tmp[j + NUMBER_ROW_FOR_NOTHING_INFORMATION + 1][k];
                  }
                  else 
                  {
                    for (unsigned int k = 0; k<MAX_COL_LCD; k++)
                      name_string_tmp[j + NUMBER_ROW_FOR_NOTHING_INFORMATION][k] = ' ';
                  }
                }
                if (current_ekran.index_position >= index_in_list) position_temp--;
          
                offset++;
              }
              else
              {
                _SET_BIT(maska, j1);
                j1++;
              }
                
              index_in_list++;
            }
          }
          else
            index_in_list += ((min_max_number[i][1] - min_max_number[i][0]) + 1);
        }
      }
      else if (min_max_number[i][0] >=0)
      {
        //Відкидати імена функцій і зміщати біти треба тільки у тому випадку, якщо функції пристні у списку для ранжування для даного захисту
        //Формуємо маску біт, які не треба переміщати при переміщенні імен полів
        unsigned int maska[N_SMALL];
        for (size_t k = 0; k < N_SMALL; ++k) maska[k] = 0;
        for (unsigned int j = 0; j < (min_max_number[i][0] - offset); j++) _SET_BIT(maska, j);
          
        //Відкидаємо назви функцій із списку, які є зайвими
        while(index_in_list <= min_max_number[i][1])
        {
          /***/
          //Зміщуємо біти стану реанжування функцій разом із їх назвами
          /***/
          unsigned int new_temp_data_1[N_SMALL], new_temp_data_2[N_SMALL];

          for (unsigned int k = 0; k < N_SMALL; k++)
          {
            new_temp_data_1[k] = state_viewing_input[k] & maska[k];

            new_temp_data_2[k] = state_viewing_input[k] & (~maska[k]);
          }

          for (unsigned int k = 0; k < (N_SMALL - 1); k++)
          {
            new_temp_data_2[k] = ( (new_temp_data_2[k] >> 1) | ((new_temp_data_2[k + 1] & 0x1) << 31) ) & (~maska[k]);
          }
          new_temp_data_2[N_SMALL - 1] =  (new_temp_data_2[N_SMALL - 1] >> 1) & (~maska[N_SMALL - 1]);
          
          for (unsigned int k = 0; k < N_SMALL; k++)
          {
            state_viewing_input[k] = new_temp_data_1[k] | new_temp_data_2[k];
           }
          /***/
          for (unsigned int j = (index_in_list - offset); j < (max_row_ranguvannja - offset); j++)
          {
            if ((j + 1) < (max_row_ranguvannja - offset))
            {
              for (unsigned int k = 0; k<MAX_COL_LCD; k++)
                name_string_tmp[j + NUMBER_ROW_FOR_NOTHING_INFORMATION][k] = name_string_tmp[j + NUMBER_ROW_FOR_NOTHING_INFORMATION + 1][k];
            }
            else 
            {
              for (unsigned int k = 0; k<MAX_COL_LCD; k++)
                name_string_tmp[j + NUMBER_ROW_FOR_NOTHING_INFORMATION][k] = ' ';
            }
          }
          if (current_ekran.index_position >= index_in_list) position_temp--;
          
          offset++;
          index_in_list++;
        }
      }
    }
    /*************************************************************/
      
    //Множення на два величини position_temp потрібне для того, бо на одну позицію ми використовуємо два рядки (назва + значення)
    index_of_ekran = ((position_temp<<1) >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;

    for (i=0; i< MAX_ROW_LCD; i++)
    {
     if (index_of_ekran < ((max_row_ranguvannja - offset) <<1))//Множення на два константи  max_row_ranguvannja потрібне для того, бо на одну позицію ми використовуємо два рядки (назва + значення)
     {
       if ((i & 0x1) == 0)
       {
         //У непарному номері рядку виводимо заголовок
         for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string_tmp[(index_of_ekran>>1) + NUMBER_ROW_FOR_NOTHING_INFORMATION][j];
       }
       else
       {
         //У парному номері рядку виводимо стан функції
         static const unsigned char information[MAX_NAMBER_LANGUAGE][2][MAX_COL_LCD] = 
         {
           {"      ОТКЛ      ", "      ВКЛ       "},
           {"      ВИМК      ", "     УВІМК      "},
           {"      OFF       ", "       ON       "},
           {"      СЉНД      ", "      КОСУ      "}
        };
        unsigned int index_bit = index_of_ekran >> 1;
          
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = information[index_language][((state_viewing_input[index_bit >> 5] & ( 1<< (index_bit & 0x1f))) != 0)][j];
       }
     }
     else
      for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = ' ';

     index_of_ekran++;
    }
    
    static const unsigned int cursor_x[MAX_NAMBER_LANGUAGE][2] = 
    {
      {5, 5},
      {5, 4},
      {5, 6},
      {5, 5}
    };

    //Відображення курору по вертикалі і курсор завжди має бути у полі із значенням
    current_ekran.position_cursor_x =  cursor_x[index_language][((state_viewing_input[position_temp >> 5] & (1 << (position_temp & 0x1f))) != 0)];
    current_ekran.position_cursor_y = ((position_temp<<1) + 1) & (MAX_ROW_LCD - 1);
    
    //Курсор мигає
    current_ekran.cursor_blinking_on = 1;
    //Режим відображення у режимі редагування
  }

  //Обновити повністю весь екран
  current_ekran.current_action = ACTION_WITH_CARRENT_EKRANE_FULL_UPDATE;

#undef NUMBER_ROW_FOR_NOTHING_INFORMATION
}
/*****************************************************/


/*****************************************************/
//Формуємо екран відображення зранжованих сигналів на вибраний вихід-світлоіндикаторів-о-функцій-реєстраторів
/*****************************************************/
void make_ekran_set_function_in_output_led_df_dt_reg(unsigned int number_ekran, unsigned int type_ekran)
{
#define NUMBER_ROW_FOR_NOTHING_INFORMATION 2
  


static const unsigned char name_string[MAX_NAMBER_LANGUAGE][TOTAL_SIGNAL_FOR_RNG_BIG - TOTAL_UP_SIGNAL_FOR_RNG_BIG + 3 + NUMBER_ROW_FOR_NOTHING_INFORMATION][MAX_COL_LCD] = 
  {
    {
      "      Нет       ",
      "  ранжирования  ",
      NAME_RANG_A01_RU
    },
    {
      "      Нема      ",
      "   ранжування   ",
      NAME_RANG_A01_UA
    },
    {
      "       No       ",
      "    ranking     ",
      NAME_RANG_A01_EN
    },
    {
      "      Нет       ",
      "  ранжирования  ",
      NAME_RANG_A01_KZ
    }
  };
static const uint32_t index_number_UP[MAX_NAMBER_LANGUAGE][3] = 
  {
    {11, 10, 8}, 
    {11, 10, 8}, 
    { 6,  6, 9}, 
    {11, 10, 8} 
  };
  unsigned int state_viewing_input[N_BIG];
  unsigned int max_row_ranguvannja = 0;

 
  unsigned char name_string_tmp[TOTAL_SIGNAL_FOR_RNG_BIG + NUMBER_ROW_FOR_NOTHING_INFORMATION][MAX_COL_LCD];

  int index_language = index_language_in_array(current_settings.language);
  for(int index_1 = 0; index_1 < (TOTAL_SIGNAL_FOR_RNG_BIG + NUMBER_ROW_FOR_NOTHING_INFORMATION); index_1++)
  {
    unsigned int index_row;
    if (index_1 < (TOTAL_SIGNAL_FOR_RNG_BIG + NUMBER_ROW_FOR_NOTHING_INFORMATION - TOTAL_EL_SIGNAL_FOR_RNG_BIG - TOTAL_VMP_SIGNAL_FOR_RNG_BIG - TOTAL_UP_SIGNAL_FOR_RNG_BIG)) 
    {
      index_row = index_1;
    }
    else if (index_1 < (TOTAL_SIGNAL_FOR_RNG_BIG + NUMBER_ROW_FOR_NOTHING_INFORMATION - TOTAL_EL_SIGNAL_FOR_RNG_BIG - TOTAL_VMP_SIGNAL_FOR_RNG_BIG))
    {
      index_row = (TOTAL_SIGNAL_FOR_RNG_BIG + NUMBER_ROW_FOR_NOTHING_INFORMATION - TOTAL_EL_SIGNAL_FOR_RNG_BIG - TOTAL_VMP_SIGNAL_FOR_RNG_BIG - TOTAL_UP_SIGNAL_FOR_RNG_BIG) + ((index_1 - (TOTAL_SIGNAL_FOR_RNG_BIG + NUMBER_ROW_FOR_NOTHING_INFORMATION - TOTAL_EL_SIGNAL_FOR_RNG_BIG - TOTAL_VMP_SIGNAL_FOR_RNG_BIG - TOTAL_UP_SIGNAL_FOR_RNG_BIG)) % 3);
    }
    else
    {
      index_row = index_1 - TOTAL_UP_SIGNAL_FOR_RNG_BIG + 3;
    }
      
    for(int index_2 = 0; index_2 < MAX_COL_LCD; index_2++)
    {
      if (
          (index_1 >= (TOTAL_SIGNAL_FOR_RNG_BIG + NUMBER_ROW_FOR_NOTHING_INFORMATION - TOTAL_EL_SIGNAL_FOR_RNG_BIG - TOTAL_VMP_SIGNAL_FOR_RNG_BIG - TOTAL_UP_SIGNAL_FOR_RNG_BIG))  &&
          (index_1 <  (TOTAL_SIGNAL_FOR_RNG_BIG + NUMBER_ROW_FOR_NOTHING_INFORMATION - TOTAL_EL_SIGNAL_FOR_RNG_BIG - TOTAL_VMP_SIGNAL_FOR_RNG_BIG)) &&
          (index_2 == index_number_UP[index_language][(index_1 - (TOTAL_SIGNAL_FOR_RNG_BIG + NUMBER_ROW_FOR_NOTHING_INFORMATION - TOTAL_EL_SIGNAL_FOR_RNG_BIG - TOTAL_VMP_SIGNAL_FOR_RNG_BIG - TOTAL_UP_SIGNAL_FOR_RNG_BIG)) % 3]) 
         )
      {
        name_string_tmp[index_1][index_2] = 0x30 + ((index_1 - (TOTAL_SIGNAL_FOR_RNG_BIG + NUMBER_ROW_FOR_NOTHING_INFORMATION - TOTAL_EL_SIGNAL_FOR_RNG_BIG - TOTAL_VMP_SIGNAL_FOR_RNG_BIG - TOTAL_UP_SIGNAL_FOR_RNG_BIG)) / 3 + 1);
      }
      else name_string_tmp[index_1][index_2] = name_string[index_language][index_row][index_2];
    }
  }
  
  unsigned int not_null = false;
  if(type_ekran == INDEX_VIEWING_DF)
  {
    unsigned int index_in_ekran_list = number_ekran - EKRAN_RANGUVANNJA_DF1_PLUS;
    unsigned int type_source = index_in_ekran_list % 3;
    unsigned int index_of_df = index_in_ekran_list / 3;
    
    if(current_ekran.edition == 0)
    {
      if(type_source == 0)
      {
        for (unsigned int i = 0; i < N_BIG; i++)
        {
          state_viewing_input[i] = current_settings.ranguvannja_df_source_plus[N_BIG*index_of_df + i];
          not_null |= (state_viewing_input[i] != 0);
        }
      }
      else if(type_source == 1)
      {
        for (unsigned int i = 0; i < N_BIG; i++)
        {
          state_viewing_input[i] = current_settings.ranguvannja_df_source_minus[N_BIG*index_of_df + i];
          not_null |= (state_viewing_input[i] != 0);
        }
      }
      else
      {
        for (unsigned int i = 0; i < N_BIG; i++)
        {
          state_viewing_input[i] = current_settings.ranguvannja_df_source_blk[N_BIG*index_of_df + i];
          not_null |= (state_viewing_input[i] != 0);
        }
      }
    }
    else
    {
      if(type_source == 0)
      {
        for (unsigned int i = 0; i < N_BIG; i++)
        {
          state_viewing_input[i] = edition_settings.ranguvannja_df_source_plus[N_BIG*index_of_df + i];
          not_null |= (state_viewing_input[i] != 0);
        }
      }
      else if(type_source == 1)
      {
        for (unsigned int i = 0; i < N_BIG; i++)
        {
          state_viewing_input[i] = edition_settings.ranguvannja_df_source_minus[N_BIG*index_of_df + i];
          not_null |= (state_viewing_input[i] != 0);
        }
      }
      else
      {
        for (unsigned int i = 0; i < N_BIG; i++)
        {
          state_viewing_input[i] = edition_settings.ranguvannja_df_source_blk[N_BIG*index_of_df + i];
          not_null |= (state_viewing_input[i] != 0);
        }
      }
    }
    max_row_ranguvannja = MAX_ROW_RANGUVANNJA_DF;
  }
  else if(type_ekran == INDEX_VIEWING_DT)
  {
    unsigned int index_in_ekran_list = number_ekran - EKRAN_RANGUVANNJA_SET_DT1_PLUS;
    unsigned int type_source = index_in_ekran_list % 2;
    unsigned int type_of_action = (index_in_ekran_list / 2) & 0x1;
    unsigned int index_of_dt = index_in_ekran_list / 4;
    
    if(current_ekran.edition == 0)
    {
      if (type_of_action == INDEX_ML_SET_DT)
      {
        if(type_source == INDEX_ML_LIST_TYPE_SOURCE_PLUS_DT)
        {
          for (unsigned int i = 0; i < N_BIG; i++)
          {
            state_viewing_input[i] = current_settings.ranguvannja_set_dt_source_plus[N_BIG*index_of_dt + i];
            not_null |= (state_viewing_input[i] != 0);
          }
        }
        else
        {
          for (unsigned int i = 0; i < N_BIG; i++)
          {
            state_viewing_input[i] = current_settings.ranguvannja_set_dt_source_minus[N_BIG*index_of_dt + i];
            not_null |= (state_viewing_input[i] != 0);
          }
        }
      }
      else
      {
        if(type_source == INDEX_ML_LIST_TYPE_SOURCE_PLUS_DT)
        {
          for (unsigned int i = 0; i < N_BIG; i++)
          {
            state_viewing_input[i] = current_settings.ranguvannja_reset_dt_source_plus[N_BIG*index_of_dt + i];
            not_null |= (state_viewing_input[i] != 0);
          }
        }
        else
        {
          for (unsigned int i = 0; i < N_BIG; i++)
          {
            state_viewing_input[i] = current_settings.ranguvannja_reset_dt_source_minus[N_BIG*index_of_dt + i];
            not_null |= (state_viewing_input[i] != 0);
          }
        }
      }
    }
    else
    {
      if (type_of_action == INDEX_ML_SET_DT)
      {
        if(type_source == INDEX_ML_LIST_TYPE_SOURCE_PLUS_DT)
        {
          for (unsigned int i = 0; i < N_BIG; i++)
          {
            state_viewing_input[i] = edition_settings.ranguvannja_set_dt_source_plus[N_BIG*index_of_dt + i];
            not_null |= (state_viewing_input[i] != 0);
          }
        }
        else
        { 
          for (unsigned int i = 0; i < N_BIG; i++)
          {
            state_viewing_input[i] = edition_settings.ranguvannja_set_dt_source_minus[N_BIG*index_of_dt + i];
            not_null |= (state_viewing_input[i] != 0);
          }
        }
      }
      else
      {
        if(type_source == INDEX_ML_LIST_TYPE_SOURCE_PLUS_DT)
        {
          for (unsigned int i = 0; i < N_BIG; i++)
          {
            state_viewing_input[i] = edition_settings.ranguvannja_reset_dt_source_plus[N_BIG*index_of_dt + i];
            not_null |= (state_viewing_input[i] != 0);
          }
        }
        else
        { 
          for (unsigned int i = 0; i < N_BIG; i++)
          {
            state_viewing_input[i] = edition_settings.ranguvannja_reset_dt_source_minus[N_BIG*index_of_dt + i];
            not_null |= (state_viewing_input[i] != 0);
          }
        }
      }
    }
    max_row_ranguvannja = MAX_ROW_RANGUVANNJA_DT;
  }
  else if(type_ekran == INDEX_VIEWING_D_AND)
  {
    if(current_ekran.edition == 0)
    {
      for (unsigned int i = 0; i < N_BIG; i++)
      {
        state_viewing_input[i] = current_settings.ranguvannja_d_and[N_BIG*(number_ekran - EKRAN_RANGUVANNJA_D_AND1) + i];
        not_null |= (state_viewing_input[i] != 0);
      }
    }
    else
    {
      for (unsigned int i = 0; i < N_BIG; i++)
      {
        state_viewing_input[i] = edition_settings.ranguvannja_d_and[N_BIG*(number_ekran - EKRAN_RANGUVANNJA_D_AND1) + i];
        not_null |= (state_viewing_input[i] != 0);
      }
    }
    max_row_ranguvannja = MAX_ROW_RANGUVANNJA_D_AND;
  }
  else if(type_ekran == INDEX_VIEWING_D_OR)
  {
    if(current_ekran.edition == 0)
    {
      for (unsigned int i = 0; i < N_BIG; i++)
      {
        state_viewing_input[i] = current_settings.ranguvannja_d_or[N_BIG*(number_ekran - EKRAN_RANGUVANNJA_D_OR1) + i];
        not_null |= (state_viewing_input[i] != 0);
      }
    }
    else
    {
      for (unsigned int i = 0; i < N_BIG; i++)
      {
        state_viewing_input[i] = edition_settings.ranguvannja_d_or[N_BIG*(number_ekran - EKRAN_RANGUVANNJA_D_OR1) + i];
        not_null |= (state_viewing_input[i] != 0);
      }
    }
    max_row_ranguvannja = MAX_ROW_RANGUVANNJA_D_OR;
  }
  else if(type_ekran == INDEX_VIEWING_D_XOR)
  {
    if(current_ekran.edition == 0)
    {
      for (unsigned int i = 0; i < N_BIG; i++)
      {
        state_viewing_input[i] = current_settings.ranguvannja_d_xor[N_BIG*(number_ekran - EKRAN_RANGUVANNJA_D_XOR1) + i];
        not_null |= (state_viewing_input[i] != 0);
      }
    }
    else
    {
      for (unsigned int i = 0; i < N_BIG; i++)
      {
        state_viewing_input[i] = edition_settings.ranguvannja_d_xor[N_BIG*(number_ekran - EKRAN_RANGUVANNJA_D_XOR1) + i];
        not_null |= (state_viewing_input[i] != 0);
      }
    }
    max_row_ranguvannja = MAX_ROW_RANGUVANNJA_D_XOR;
  }
  else if(type_ekran == INDEX_VIEWING_D_NOT)
  {
    if(current_ekran.edition == 0)
    {
      for (unsigned int i = 0; i < N_BIG; i++)
      {
        state_viewing_input[i] = current_settings.ranguvannja_d_not[N_BIG*(number_ekran - EKRAN_RANGUVANNJA_D_NOT1) + i];
        not_null |= (state_viewing_input[i] != 0);
      }
    }
    else
    {
      for (unsigned int i = 0; i < N_BIG; i++)
      {
        state_viewing_input[i] = edition_settings.ranguvannja_d_not[N_BIG*(number_ekran - EKRAN_RANGUVANNJA_D_NOT1) + i];
        not_null |= (state_viewing_input[i] != 0);
      }
    }
    max_row_ranguvannja = MAX_ROW_RANGUVANNJA_D_NOT;
  }
  else if(type_ekran == INDEX_VIEWING_OUTPUT)
  {
    if(current_ekran.edition == 0)
    {
      for (unsigned int i = 0; i < N_BIG; i++)
      {
        state_viewing_input[i] = current_settings.ranguvannja_outputs[N_BIG*(number_ekran - EKRAN_RANGUVANNJA_OUTPUT_1) + i];
        not_null |= (state_viewing_input[i] != 0);
      }
    }
    else
    {
      for (unsigned int i = 0; i < N_BIG; i++)
      {
        state_viewing_input[i] = edition_settings.ranguvannja_outputs[N_BIG*(number_ekran - EKRAN_RANGUVANNJA_OUTPUT_1) + i];
        not_null |= (state_viewing_input[i] != 0);
      }
    }
    max_row_ranguvannja = MAX_ROW_RANGUVANNJA_OUTPUT;
  }
  else if(type_ekran == INDEX_VIEWING_LED)
  {
    if(current_ekran.edition == 0)
    {
      for (unsigned int i = 0; i < N_BIG; i++)
      {
        state_viewing_input[i] = current_settings.ranguvannja_leds[N_BIG*(number_ekran - EKRAN_RANGUVANNJA_LED_1) + i];
        not_null |= (state_viewing_input[i] != 0);
      }
    }
    else
    {
      for (unsigned int i = 0; i < N_BIG; i++)
      {
        state_viewing_input[i] = edition_settings.ranguvannja_leds[N_BIG*(number_ekran - EKRAN_RANGUVANNJA_LED_1) + i];
        not_null |= (state_viewing_input[i] != 0);
      }
    }
    max_row_ranguvannja = MAX_ROW_RANGUVANNJA_LED;
  }
  else if(type_ekran == INDEX_VIEWING_A_REG)
  {
    if(current_ekran.edition == 0)
    {
      for (unsigned int i = 0; i < N_BIG; i++)
      {
        state_viewing_input[i] = current_settings.ranguvannja_analog_registrator[i];
        not_null |= (state_viewing_input[i] != 0);
      }
    }
    else
    {
      for (unsigned int i = 0; i < N_BIG; i++)
      {
        state_viewing_input[i] = edition_settings.ranguvannja_analog_registrator[i];
        not_null |= (state_viewing_input[i] != 0);
      }
    }
    max_row_ranguvannja = MAX_ROW_RANGUVANNJA_ANALOG_REGISTRATOR;
  }
  else if(type_ekran == INDEX_VIEWING_D_REG)
  {
    if(current_ekran.edition == 0)
    {
      for (unsigned int i = 0; i < N_BIG; i++)
      {
        state_viewing_input[i] = current_settings.ranguvannja_digital_registrator[i];
        not_null |= (state_viewing_input[i] != 0);
      }
    }
    else
    {
      for (unsigned int i = 0; i < N_BIG; i++)
      {
        state_viewing_input[i] = edition_settings.ranguvannja_digital_registrator[i];
        not_null |= (state_viewing_input[i] != 0);
      }
    }
    max_row_ranguvannja = MAX_ROW_RANGUVANNJA_DIGITAL_REGISTRATOR;
  }
  else if(type_ekran == INDEX_VIEWING_OFF_CB)
  {
    if(current_ekran.edition == 0)
    {
      for (unsigned int i = 0; i < N_BIG; i++)
      {
        state_viewing_input[i] = current_settings.ranguvannja_off_cb[i];
        not_null |= (state_viewing_input[i] != 0);
      }
    }
    else
    {
      for (unsigned int i = 0; i < N_BIG; i++)
      {
        state_viewing_input[i] = edition_settings.ranguvannja_off_cb[i];
        not_null |= (state_viewing_input[i] != 0);
      }
    }
    max_row_ranguvannja = MAX_ROW_RANGUVANNJA_OFF_CB;
  }
  else if(type_ekran == INDEX_VIEWING_ON_CB)
  {
    if(current_ekran.edition == 0)
    {
      for (unsigned int i = 0; i < N_BIG; i++)
      {
        state_viewing_input[i] = current_settings.ranguvannja_on_cb[i];
        not_null |= (state_viewing_input[i] != 0);
      }
    }
    else
    {
      for (unsigned int i = 0; i < N_BIG; i++)
      {
        state_viewing_input[i] = edition_settings.ranguvannja_on_cb[i];
        not_null |= (state_viewing_input[i] != 0);
      }
    }
    max_row_ranguvannja = MAX_ROW_RANGUVANNJA_ON_CB;
  }
  else if(type_ekran == INDEX_VIEWING_OFF_CB_H)
  {
    if(current_ekran.edition == 0)
    {
      for (unsigned int i = 0; i < N_BIG; i++)
      {
        state_viewing_input[i] = current_settings.ranguvannja_off_cb_oh[i];
        not_null |= (state_viewing_input[i] != 0);
      }
    }
    else
    {
      for (unsigned int i = 0; i < N_BIG; i++)
      {
        state_viewing_input[i] = edition_settings.ranguvannja_off_cb_oh[i];
        not_null |= (state_viewing_input[i] != 0);
      }
    }
    max_row_ranguvannja = MAX_ROW_RANGUVANNJA_OFF_CB;
  }
   else if(type_ekran == INDEX_VIEWING_ON_CB_H)
  {
    if(current_ekran.edition == 0)
    {
      for (unsigned int i = 0; i < N_BIG; i++)
      {
        state_viewing_input[i] = current_settings.ranguvannja_on__cb_oh[i];
        not_null |= (state_viewing_input[i] != 0);
      }
    }
    else
    {
      for (unsigned int i = 0; i < N_BIG; i++)
      {
        state_viewing_input[i] = edition_settings.ranguvannja_on__cb_oh[i];
        not_null |= (state_viewing_input[i] != 0);
      }
    }
    max_row_ranguvannja = MAX_ROW_RANGUVANNJA_ON_CB;
  }
  else if(type_ekran == INDEX_VIEWING_OFF_CB_L)
  {
    if(current_ekran.edition == 0)
    {
      for (unsigned int i = 0; i < N_BIG; i++)
      {
        state_viewing_input[i] = current_settings.ranguvannja_off_cb_rl[i];
        not_null |= (state_viewing_input[i] != 0);
      }
    }
    else
    {
      for (unsigned int i = 0; i < N_BIG; i++)
      {
        state_viewing_input[i] = edition_settings.ranguvannja_off_cb_rl[i];
        not_null |= (state_viewing_input[i] != 0);
      }
    }
    max_row_ranguvannja = MAX_ROW_RANGUVANNJA_OFF_CB;
  }
  else if(type_ekran == INDEX_VIEWING_ON_CB_L)
  {
    if(current_ekran.edition == 0)
    {
      for (unsigned int i = 0; i < N_BIG; i++)
      {
        state_viewing_input[i] = current_settings.ranguvannja_on__cb_rl[i];
        not_null |= (state_viewing_input[i] != 0);
      }
    }
    else
    {
      for (unsigned int i = 0; i < N_BIG; i++)
      {
        state_viewing_input[i] = edition_settings.ranguvannja_on__cb_rl[i];
        not_null |= (state_viewing_input[i] != 0);
      }
    }
    max_row_ranguvannja = MAX_ROW_RANGUVANNJA_ON_CB;
  }
  else total_error_sw_fixed();

  if(current_ekran.edition == 0)
  {
    //Випадок, коли ми продивляємося зранжовані функції на вході
    if (not_null == false)
    {
      //Це означає, що на даний вхід нічого не відранжовано
      
      //Текучу позицію в сипску переводимо на сам початок
      current_ekran.index_position = 0;
      position_in_current_level_menu[number_ekran] = 0;

      //Копіюємо  рядки у робочий екран
      for (unsigned int i=0; i< MAX_ROW_LCD; i++)
      {
        //Копіюємо в робочий екран інформацію, що нічого не відранжовано
        if (i < NUMBER_ROW_FOR_NOTHING_INFORMATION)
          for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string_tmp[i][j];
        else
          for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = ' ';
      }

      //Відображення курсору по вертикалі
      current_ekran.position_cursor_y = 0;
      //Курсор невидимий
      current_ekran.cursor_on = 0;
    }
    else
    {
      /************************************************************/
      //Формуємо список із функцій, які реально відранжовані
      /************************************************************/
      unsigned int position_temp = current_ekran.index_position;
      unsigned int index_of_ekran;
      unsigned int i = 0, offset = 0;
      unsigned int state_current_bit;
      
      while ((i + offset) < max_row_ranguvannja)
      {
        state_current_bit = state_viewing_input[(i + offset)>>5] & (1<<((i + offset) & 0x1f));
          
        if (state_current_bit == 0)
        {
          for (unsigned int j = i; j < (max_row_ranguvannja - offset); j++)
          {
            if ((j + 1) < (max_row_ranguvannja - offset))
            {
              for (unsigned int k = 0; k<MAX_COL_LCD; k++)
                name_string_tmp[j + NUMBER_ROW_FOR_NOTHING_INFORMATION][k] = name_string_tmp[j + NUMBER_ROW_FOR_NOTHING_INFORMATION + 1][k];
            }
            else 
            {
              for (unsigned int k = 0; k<MAX_COL_LCD; k++)
                name_string_tmp[j + NUMBER_ROW_FOR_NOTHING_INFORMATION][k] = ' ';
            }
          }
          if (current_ekran.index_position >= ((int)(i + offset))) position_temp--;
          offset++;
          
          //Робота з Watchdog
          watchdog_routine(UNITED_BITS_WATCHDOG);
        }
        else i++;
      }
      /************************************************************/

      index_of_ekran = (position_temp >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;
      
      //Копіюємо  рядки у робочий екран
      for (i=0; i< MAX_ROW_LCD; i++)
      {
        //Наступні рядки треба перевірити, чи їх требе відображати у текучій кофігурації
        if (index_of_ekran < max_row_ranguvannja)
        {
          for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string_tmp[index_of_ekran + NUMBER_ROW_FOR_NOTHING_INFORMATION][j];

          //Підтягуємо назву, щоб не було спереді багато пробілів
          unsigned int iteration = 0;
          while (
                 (working_ekran[i][0] == ' ') &&
                 (working_ekran[i][1] == ' ') &&
                 (iteration < (MAX_COL_LCD - 1 - 1))
                )
          {
            for (unsigned int j = 1; j < MAX_COL_LCD; j++)
            {
              if ((j + 1) < MAX_COL_LCD)
                working_ekran[i][j] = working_ekran[i][j + 1];
              else
                working_ekran[i][j] = ' ';
            }
            iteration++;
          }
        }
        else
          for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = ' ';

        index_of_ekran++;
      }
      //Відображення курору по вертикалі
      current_ekran.position_cursor_y = position_temp & (MAX_ROW_LCD - 1);
      //Курсор видимий
      current_ekran.cursor_on = 1;
    }

    //Курсор по горизонталі відображається на першій позиції
    current_ekran.position_cursor_x = 0;
    //Курсор не мигає
    current_ekran.cursor_blinking_on = 0;
  }
  else
  {
    unsigned int position_temp = current_ekran.index_position;
    unsigned int index_of_ekran;
    unsigned int i, offset = 0;
    static const int min_max_number[TOTAL_NUMBER_PROTECTION][2] =
    {
      {
       (TOTAL_GENERAL_SIGNAL_FOR_RNG_BIG),
       (TOTAL_GENERAL_SIGNAL_FOR_RNG_BIG + TOTAL_DZO_SIGNAL_FOR_RNG_BIG - 1)
      },
      {
       (TOTAL_GENERAL_SIGNAL_FOR_RNG_BIG + TOTAL_DZO_SIGNAL_FOR_RNG_BIG),
       (TOTAL_GENERAL_SIGNAL_FOR_RNG_BIG + TOTAL_DZO_SIGNAL_FOR_RNG_BIG + TOTAL_MTZ_STUB_SIGNAL_FOR_RNG_BIG - 1)
      },
      {
       (TOTAL_GENERAL_SIGNAL_FOR_RNG_BIG + TOTAL_DZO_SIGNAL_FOR_RNG_BIG + TOTAL_MTZ_STUB_SIGNAL_FOR_RNG_BIG),
       (TOTAL_GENERAL_SIGNAL_FOR_RNG_BIG + TOTAL_DZO_SIGNAL_FOR_RNG_BIG + TOTAL_MTZ_STUB_SIGNAL_FOR_RNG_BIG + TOTAL_ZDZ_SIGNAL_FOR_RNG_BIG - 1)
      },
      {
       (TOTAL_GENERAL_SIGNAL_FOR_RNG_BIG + TOTAL_DZO_SIGNAL_FOR_RNG_BIG + TOTAL_MTZ_STUB_SIGNAL_FOR_RNG_BIG + TOTAL_ZDZ_SIGNAL_FOR_RNG_BIG),
       (TOTAL_GENERAL_SIGNAL_FOR_RNG_BIG + TOTAL_DZO_SIGNAL_FOR_RNG_BIG + TOTAL_MTZ_STUB_SIGNAL_FOR_RNG_BIG + TOTAL_ZDZ_SIGNAL_FOR_RNG_BIG + TOTAL_MCZO_SIGNAL_FOR_RNG_BIG - 1)
      },
      {
       (TOTAL_GENERAL_SIGNAL_FOR_RNG_BIG + TOTAL_DZO_SIGNAL_FOR_RNG_BIG + TOTAL_MTZ_STUB_SIGNAL_FOR_RNG_BIG + TOTAL_ZDZ_SIGNAL_FOR_RNG_BIG + TOTAL_MCZO_SIGNAL_FOR_RNG_BIG),
       (TOTAL_GENERAL_SIGNAL_FOR_RNG_BIG + TOTAL_DZO_SIGNAL_FOR_RNG_BIG + TOTAL_MTZ_STUB_SIGNAL_FOR_RNG_BIG + TOTAL_ZDZ_SIGNAL_FOR_RNG_BIG + TOTAL_MCZO_SIGNAL_FOR_RNG_BIG + TOTAL_MCZR_SIGNAL_FOR_RNG_BIG - 1)
      },
      {
       (TOTAL_GENERAL_SIGNAL_FOR_RNG_BIG + TOTAL_DZO_SIGNAL_FOR_RNG_BIG + TOTAL_MTZ_STUB_SIGNAL_FOR_RNG_BIG + TOTAL_ZDZ_SIGNAL_FOR_RNG_BIG + TOTAL_MCZO_SIGNAL_FOR_RNG_BIG + TOTAL_MCZR_SIGNAL_FOR_RNG_BIG),
       (TOTAL_GENERAL_SIGNAL_FOR_RNG_BIG + TOTAL_DZO_SIGNAL_FOR_RNG_BIG + TOTAL_MTZ_STUB_SIGNAL_FOR_RNG_BIG + TOTAL_ZDZ_SIGNAL_FOR_RNG_BIG + TOTAL_MCZO_SIGNAL_FOR_RNG_BIG + TOTAL_MCZR_SIGNAL_FOR_RNG_BIG + TOTAL_APV_SIGNAL_FOR_RNG_BIG - 1)
      },
      {
       (TOTAL_GENERAL_SIGNAL_FOR_RNG_BIG + TOTAL_DZO_SIGNAL_FOR_RNG_BIG + TOTAL_MTZ_STUB_SIGNAL_FOR_RNG_BIG + TOTAL_ZDZ_SIGNAL_FOR_RNG_BIG + TOTAL_MCZO_SIGNAL_FOR_RNG_BIG + TOTAL_MCZR_SIGNAL_FOR_RNG_BIG + TOTAL_APV_SIGNAL_FOR_RNG_BIG),
       (TOTAL_GENERAL_SIGNAL_FOR_RNG_BIG + TOTAL_DZO_SIGNAL_FOR_RNG_BIG + TOTAL_MTZ_STUB_SIGNAL_FOR_RNG_BIG + TOTAL_ZDZ_SIGNAL_FOR_RNG_BIG + TOTAL_MCZO_SIGNAL_FOR_RNG_BIG + TOTAL_MCZR_SIGNAL_FOR_RNG_BIG + TOTAL_APV_SIGNAL_FOR_RNG_BIG + TOTAL_ACHR_CHAPV_SIGNAL_FOR_RNG_BIG - 1)
      },
      {
       (TOTAL_GENERAL_SIGNAL_FOR_RNG_BIG + TOTAL_DZO_SIGNAL_FOR_RNG_BIG + TOTAL_MTZ_STUB_SIGNAL_FOR_RNG_BIG + TOTAL_ZDZ_SIGNAL_FOR_RNG_BIG + TOTAL_MCZO_SIGNAL_FOR_RNG_BIG + TOTAL_MCZR_SIGNAL_FOR_RNG_BIG + TOTAL_APV_SIGNAL_FOR_RNG_BIG + TOTAL_ACHR_CHAPV_SIGNAL_FOR_RNG_BIG),
       (TOTAL_GENERAL_SIGNAL_FOR_RNG_BIG + TOTAL_DZO_SIGNAL_FOR_RNG_BIG + TOTAL_MTZ_STUB_SIGNAL_FOR_RNG_BIG + TOTAL_ZDZ_SIGNAL_FOR_RNG_BIG + TOTAL_MCZO_SIGNAL_FOR_RNG_BIG + TOTAL_MCZR_SIGNAL_FOR_RNG_BIG + TOTAL_APV_SIGNAL_FOR_RNG_BIG + TOTAL_ACHR_CHAPV_SIGNAL_FOR_RNG_BIG  + TOTAL_UROV_SIGNAL_FOR_RNG_BIG - 1)
      },
      {
       (TOTAL_GENERAL_SIGNAL_FOR_RNG_BIG + TOTAL_DZO_SIGNAL_FOR_RNG_BIG + TOTAL_MTZ_STUB_SIGNAL_FOR_RNG_BIG + TOTAL_ZDZ_SIGNAL_FOR_RNG_BIG + TOTAL_MCZO_SIGNAL_FOR_RNG_BIG + TOTAL_MCZR_SIGNAL_FOR_RNG_BIG + TOTAL_APV_SIGNAL_FOR_RNG_BIG + TOTAL_ACHR_CHAPV_SIGNAL_FOR_RNG_BIG  + TOTAL_UROV_SIGNAL_FOR_RNG_BIG),
       (TOTAL_GENERAL_SIGNAL_FOR_RNG_BIG + TOTAL_DZO_SIGNAL_FOR_RNG_BIG + TOTAL_MTZ_STUB_SIGNAL_FOR_RNG_BIG + TOTAL_ZDZ_SIGNAL_FOR_RNG_BIG + TOTAL_MCZO_SIGNAL_FOR_RNG_BIG + TOTAL_MCZR_SIGNAL_FOR_RNG_BIG + TOTAL_APV_SIGNAL_FOR_RNG_BIG + TOTAL_ACHR_CHAPV_SIGNAL_FOR_RNG_BIG  + TOTAL_UROV_SIGNAL_FOR_RNG_BIG + TOTAL_DZR_SIGNAL_FOR_RNG_BIG - 1)
      },
      {
       (TOTAL_GENERAL_SIGNAL_FOR_RNG_BIG + TOTAL_DZO_SIGNAL_FOR_RNG_BIG + TOTAL_MTZ_STUB_SIGNAL_FOR_RNG_BIG + TOTAL_ZDZ_SIGNAL_FOR_RNG_BIG + TOTAL_MCZO_SIGNAL_FOR_RNG_BIG + TOTAL_MCZR_SIGNAL_FOR_RNG_BIG + TOTAL_APV_SIGNAL_FOR_RNG_BIG + TOTAL_ACHR_CHAPV_SIGNAL_FOR_RNG_BIG  + TOTAL_UROV_SIGNAL_FOR_RNG_BIG + TOTAL_DZR_SIGNAL_FOR_RNG_BIG),
       (TOTAL_GENERAL_SIGNAL_FOR_RNG_BIG + TOTAL_DZO_SIGNAL_FOR_RNG_BIG + TOTAL_MTZ_STUB_SIGNAL_FOR_RNG_BIG + TOTAL_ZDZ_SIGNAL_FOR_RNG_BIG + TOTAL_MCZO_SIGNAL_FOR_RNG_BIG + TOTAL_MCZR_SIGNAL_FOR_RNG_BIG + TOTAL_APV_SIGNAL_FOR_RNG_BIG + TOTAL_ACHR_CHAPV_SIGNAL_FOR_RNG_BIG  + TOTAL_UROV_SIGNAL_FOR_RNG_BIG + TOTAL_DZR_SIGNAL_FOR_RNG_BIG + TOTAL_UMIN_SIGNAL_FOR_RNG_BIG - 1)
      },
      {
       (TOTAL_GENERAL_SIGNAL_FOR_RNG_BIG + TOTAL_DZO_SIGNAL_FOR_RNG_BIG + TOTAL_MTZ_STUB_SIGNAL_FOR_RNG_BIG + TOTAL_ZDZ_SIGNAL_FOR_RNG_BIG + TOTAL_MCZO_SIGNAL_FOR_RNG_BIG + TOTAL_MCZR_SIGNAL_FOR_RNG_BIG + TOTAL_APV_SIGNAL_FOR_RNG_BIG + TOTAL_ACHR_CHAPV_SIGNAL_FOR_RNG_BIG  + TOTAL_UROV_SIGNAL_FOR_RNG_BIG + TOTAL_DZR_SIGNAL_FOR_RNG_BIG + TOTAL_UMIN_SIGNAL_FOR_RNG_BIG),
       (TOTAL_GENERAL_SIGNAL_FOR_RNG_BIG + TOTAL_DZO_SIGNAL_FOR_RNG_BIG + TOTAL_MTZ_STUB_SIGNAL_FOR_RNG_BIG + TOTAL_ZDZ_SIGNAL_FOR_RNG_BIG + TOTAL_MCZO_SIGNAL_FOR_RNG_BIG + TOTAL_MCZR_SIGNAL_FOR_RNG_BIG + TOTAL_APV_SIGNAL_FOR_RNG_BIG + TOTAL_ACHR_CHAPV_SIGNAL_FOR_RNG_BIG  + TOTAL_UROV_SIGNAL_FOR_RNG_BIG + TOTAL_DZR_SIGNAL_FOR_RNG_BIG + TOTAL_UMIN_SIGNAL_FOR_RNG_BIG + TOTAL_UMAX_SIGNAL_FOR_RNG_BIG - 1)
      },
      {
       (TOTAL_GENERAL_SIGNAL_FOR_RNG_BIG + TOTAL_DZO_SIGNAL_FOR_RNG_BIG + TOTAL_MTZ_STUB_SIGNAL_FOR_RNG_BIG + TOTAL_ZDZ_SIGNAL_FOR_RNG_BIG + TOTAL_MCZO_SIGNAL_FOR_RNG_BIG + TOTAL_MCZR_SIGNAL_FOR_RNG_BIG + TOTAL_APV_SIGNAL_FOR_RNG_BIG + TOTAL_ACHR_CHAPV_SIGNAL_FOR_RNG_BIG  + TOTAL_UROV_SIGNAL_FOR_RNG_BIG + TOTAL_DZR_SIGNAL_FOR_RNG_BIG + TOTAL_UMIN_SIGNAL_FOR_RNG_BIG + TOTAL_UMAX_SIGNAL_FOR_RNG_BIG),
       (TOTAL_GENERAL_SIGNAL_FOR_RNG_BIG + TOTAL_DZO_SIGNAL_FOR_RNG_BIG + TOTAL_MTZ_STUB_SIGNAL_FOR_RNG_BIG + TOTAL_ZDZ_SIGNAL_FOR_RNG_BIG + TOTAL_MCZO_SIGNAL_FOR_RNG_BIG + TOTAL_MCZR_SIGNAL_FOR_RNG_BIG + TOTAL_APV_SIGNAL_FOR_RNG_BIG + TOTAL_ACHR_CHAPV_SIGNAL_FOR_RNG_BIG  + TOTAL_UROV_SIGNAL_FOR_RNG_BIG + TOTAL_DZR_SIGNAL_FOR_RNG_BIG + TOTAL_UMIN_SIGNAL_FOR_RNG_BIG + TOTAL_UMAX_SIGNAL_FOR_RNG_BIG + TOTAL_UP_SIGNAL_FOR_RNG_BIG - 1)
      },
      {-1,-1},
      {
       (TOTAL_GENERAL_SIGNAL_FOR_RNG_BIG + TOTAL_DZO_SIGNAL_FOR_RNG_BIG + TOTAL_MTZ_STUB_SIGNAL_FOR_RNG_BIG + TOTAL_ZDZ_SIGNAL_FOR_RNG_BIG + TOTAL_MCZO_SIGNAL_FOR_RNG_BIG + TOTAL_MCZR_SIGNAL_FOR_RNG_BIG + TOTAL_APV_SIGNAL_FOR_RNG_BIG + TOTAL_ACHR_CHAPV_SIGNAL_FOR_RNG_BIG + TOTAL_UROV_SIGNAL_FOR_RNG_BIG + TOTAL_DZR_SIGNAL_FOR_RNG_BIG + TOTAL_UMIN_SIGNAL_FOR_RNG_BIG + TOTAL_UMAX_SIGNAL_FOR_RNG_BIG + TOTAL_UP_SIGNAL_FOR_RNG_BIG + TOTAL_VMP_SIGNAL_FOR_RNG_BIG),
       (TOTAL_GENERAL_SIGNAL_FOR_RNG_BIG + TOTAL_DZO_SIGNAL_FOR_RNG_BIG + TOTAL_MTZ_STUB_SIGNAL_FOR_RNG_BIG + TOTAL_ZDZ_SIGNAL_FOR_RNG_BIG + TOTAL_MCZO_SIGNAL_FOR_RNG_BIG + TOTAL_MCZR_SIGNAL_FOR_RNG_BIG + TOTAL_APV_SIGNAL_FOR_RNG_BIG + TOTAL_ACHR_CHAPV_SIGNAL_FOR_RNG_BIG + TOTAL_UROV_SIGNAL_FOR_RNG_BIG + TOTAL_DZR_SIGNAL_FOR_RNG_BIG + TOTAL_UMIN_SIGNAL_FOR_RNG_BIG + TOTAL_UMAX_SIGNAL_FOR_RNG_BIG + TOTAL_UP_SIGNAL_FOR_RNG_BIG + TOTAL_VMP_SIGNAL_FOR_RNG_BIG + TOTAL_EL_SIGNAL_FOR_RNG_BIG - 1)
      }
    };
    
    /*************************************************************/
    //Фільтруємо сигнали, яких у даній конфігурації неприсутні
    /*************************************************************/
    if(
       (type_ekran == INDEX_VIEWING_A_REG ) ||
       (type_ekran == INDEX_VIEWING_D_REG ) ||
       (type_ekran == INDEX_VIEWING_OFF_CB) ||
       (type_ekran == INDEX_VIEWING_ON_CB)  ||
	   (type_ekran == INDEX_VIEWING_OFF_CB_H) ||
	   (type_ekran == INDEX_VIEWING_ON_CB_H ) ||
	   (type_ekran == INDEX_VIEWING_OFF_CB_L) ||
	   (type_ekran == INDEX_VIEWING_ON_CB_L ) 
      )
    {
      /*************************************************************/
      //У випадку, якщо відображення здійснюється вікна аналогового реєстратора чи дискретного реєстратора, то відктдпємо ті функції, які не можуть бути джерелати
      /*************************************************************/
      unsigned int index_deleted_function = 0;
      
      if (type_ekran == INDEX_VIEWING_A_REG)
        index_deleted_function = RNG_BIG_WORK_A_REJESTRATOR;
      else if (type_ekran == INDEX_VIEWING_D_REG)
        index_deleted_function = RNG_BIG_WORK_D_REJESTRATOR;
      else if (type_ekran == INDEX_VIEWING_OFF_CB)
        index_deleted_function = RNG_BIG_WORK_BO_VVO;
      //else
      //  index_deleted_function = RNG_BIG_WORK_BV_VVO;
      else if (type_ekran == INDEX_VIEWING_ON_CB)
        index_deleted_function = RNG_BIG_WORK_BV_VVO;
      else if (type_ekran == INDEX_VIEWING_OFF_CB_H)
        index_deleted_function = RNG_BIG_WORK_BO_VVO;
      else if (type_ekran == INDEX_VIEWING_ON_CB_H)
        index_deleted_function = RNG_BIG_WORK_BV_VVO;
      else if (type_ekran == INDEX_VIEWING_OFF_CB_L)
        index_deleted_function = RNG_BIG_WORK_BO_VVR;
      else if (type_ekran == INDEX_VIEWING_ON_CB_L)
        index_deleted_function = RNG_BIG_WORK_BV_VVR;
      else total_error_sw_fixed();
      
      /*************************************************************/
      //Відкидаємо ім'я даної функції і зміщаємо біти
      /*************************************************************/

      //Формуємо маску біт, які не треба переміщати при переміщенні імен полів
      unsigned int maska[N_BIG];
      for (size_t k = 0; k < N_BIG; ++k) maska[k] = 0;
      for (unsigned int j = 0; j < (index_deleted_function - offset); j++) _SET_BIT(maska, j);
          
      /***/
      //Зміщуємо біти стану реанжування функцій разом із їх назвами
      /***/
      unsigned int new_temp_data_1[N_BIG], new_temp_data_2[N_BIG];

      for (unsigned int k = 0; k < N_BIG; k++)
      {
        new_temp_data_1[k] = state_viewing_input[k] & maska[k];

        new_temp_data_2[k] = state_viewing_input[k] & (~maska[k]);
      }

      for (unsigned int k = 0; k < (N_BIG - 1); k++)
      {
        new_temp_data_2[k] = ( (new_temp_data_2[k] >> 1) | ((new_temp_data_2[k + 1] & 0x1) << 31) ) & (~maska[k]);
      }
      new_temp_data_2[N_BIG - 1] =  (new_temp_data_2[N_BIG - 1] >> 1) & (~maska[N_BIG - 1]);
                
      for (unsigned int k = 0; k < N_BIG; k++)
      {
        state_viewing_input[k] = new_temp_data_1[k] | new_temp_data_2[k];
      }
      /***/
      for (unsigned int j = (index_deleted_function - offset); j < (max_row_ranguvannja - offset); j++)
      {
        if ((j + 1) < (max_row_ranguvannja - offset))
        {
          for (unsigned int k = 0; k<MAX_COL_LCD; k++)
            name_string_tmp[j + NUMBER_ROW_FOR_NOTHING_INFORMATION][k] = name_string_tmp[j + NUMBER_ROW_FOR_NOTHING_INFORMATION + 1][k];
        }
        else 
        {
          for (unsigned int k = 0; k<MAX_COL_LCD; k++)
            name_string_tmp[j + NUMBER_ROW_FOR_NOTHING_INFORMATION][k] = ' ';
        }
      }
      if (current_ekran.index_position >= ((int)index_deleted_function)) position_temp--;
      offset++;
      //Робота з Watchdog
      watchdog_routine(UNITED_BITS_WATCHDOG);
      /*************************************************************/

      /*************************************************************/
    }

    //Функції загального призначення пропускаємо (вони знаходяться у початку списку), тому починаємо з першого записту
    int index_in_list = TOTAL_GENERAL_SIGNAL_FOR_RNG_BIG;
    
    for (i = 0; i < TOTAL_NUMBER_PROTECTION; i++)
    {
      
      if((current_settings.configuration & (1 << i)) != 0)
      {
        //Захист присутнійсть, тому функції фільтрувати не потрібно - переводимо індекс на наступні функції
        //Додаємо кількість функцій до поточного індексу, якщо для поточного захисту реально були присутні функції,
        //бо інкаше ми вже знаходимося на індексі наступного захисту
        if(min_max_number[i][0] >=0)
        {
          if (i == EL_BIT_CONFIGURATION)
          {
            /*
            Випадок коли деякі сигнали розширеної логіки треба відфільтрувати
            */

            //Відкидати імена функцій і зміщати біти треба тільки у тому випадку, якщо функції пристні у списку для ранжування для даного захисту
            //Формуємо маску біт, які не треба переміщати при переміщенні імен полів
            unsigned int maska[N_BIG];
            for (size_t k = 0; k < N_BIG; ++k) maska[k] = 0;
            unsigned int j1;
            for (j1 = 0; j1 < (min_max_number[i][0] - offset); j1++) _SET_BIT(maska, j1);
          
            //Відкидаємо назви функцій із списку, які є зайвими
            while(index_in_list <= min_max_number[i][1])
            {
              if (
                  (
                   (
                    (type_ekran == INDEX_VIEWING_DF) &&
                    (
                     (index_in_list == (RNG_BIG_DF1_IN  + 3/*кількість сигналів*/*((number_ekran - EKRAN_RANGUVANNJA_DF1_PLUS) / MAX_ROW_LIST_TYPE_SOURCE_DF/*кількість типів вікон*/))) ||
                     (index_in_list == (RNG_BIG_DF1_RST + 3/*кількість сигналів*/*((number_ekran - EKRAN_RANGUVANNJA_DF1_PLUS) / MAX_ROW_LIST_TYPE_SOURCE_DF/*кількість типів вікон*/))) ||
                     (index_in_list == (RNG_BIG_DF1_OUT + 3/*кількість сигналів*/*((number_ekran - EKRAN_RANGUVANNJA_DF1_PLUS) / MAX_ROW_LIST_TYPE_SOURCE_DF/*кількість типів вікон*/)))
                    )  
                   )
                  )   
                  ||  
                  (
                   (
                    (type_ekran == INDEX_VIEWING_DT) &&
                    (
                     (index_in_list == (RNG_BIG_DT1_SET   + 3/*кількість сигналів*/*((number_ekran - EKRAN_RANGUVANNJA_SET_DT1_PLUS) / 4/*кількість типів вікон*/))) ||
                     (index_in_list == (RNG_BIG_DT1_RESET + 3/*кількість сигналів*/*((number_ekran - EKRAN_RANGUVANNJA_SET_DT1_PLUS) / 4/*кількість типів вікон*/))) ||
                     (index_in_list == (RNG_BIG_DT1_OUT   + 3/*кількість сигналів*/*((number_ekran - EKRAN_RANGUVANNJA_SET_DT1_PLUS) / 4/*кількість типів вікон*/)))
                    )  
                   ) 
                  )   
                  ||  
                  (
                   (
                    (type_ekran == INDEX_VIEWING_D_AND) &&
                    (index_in_list == (RNG_BIG_D_AND1 + (number_ekran - EKRAN_RANGUVANNJA_D_AND1)))
                   )   
                  )   
                  ||  
                  (
                   (
                    (type_ekran == INDEX_VIEWING_D_OR) &&
                    (index_in_list == (RNG_BIG_D_OR1 + (number_ekran - EKRAN_RANGUVANNJA_D_OR1)))
                   )   
                  )   
                  ||  
                  (
                   (
                    (type_ekran == INDEX_VIEWING_D_XOR) &&
                    (index_in_list == (RNG_BIG_D_XOR1 + (number_ekran - EKRAN_RANGUVANNJA_D_XOR1)))
                   )   
                  )   
                  ||  
                  (
                   (
                    (type_ekran == INDEX_VIEWING_D_NOT) &&
                    (index_in_list == (RNG_BIG_D_NOT1 + (number_ekran - EKRAN_RANGUVANNJA_D_NOT1)))
                   )   
                  )   
                 )
              {
                /***/
                //Зміщуємо біти стану реанжування функцій разом із їх назвами
                /***/
                unsigned int new_temp_data_1[N_BIG], new_temp_data_2[N_BIG];

                for (unsigned int k = 0; k < N_BIG; k++)
                {
                  new_temp_data_1[k] = state_viewing_input[k] & maska[k];

                  new_temp_data_2[k] = state_viewing_input[k] & (~maska[k]);
                }

                for (unsigned int k = 0; k < (N_BIG - 1); k++)
                {
                  new_temp_data_2[k] = ( (new_temp_data_2[k] >> 1) | ((new_temp_data_2[k + 1] & 0x1) << 31) ) & (~maska[k]);
                }
                new_temp_data_2[N_BIG - 1] =  (new_temp_data_2[N_BIG - 1] >> 1) & (~maska[N_BIG - 1]);
                
                for (unsigned int k = 0; k < N_BIG; k++)
                {
                  state_viewing_input[k] = new_temp_data_1[k] | new_temp_data_2[k];
                }
                /***/
                for (unsigned int j = (index_in_list - offset); j < (max_row_ranguvannja - offset); j++)
                {
                  if ((j + 1) < (max_row_ranguvannja - offset))
                  {
                    for (unsigned int k = 0; k < MAX_COL_LCD; k++)
                      name_string_tmp[j + NUMBER_ROW_FOR_NOTHING_INFORMATION][k] = name_string_tmp[j + NUMBER_ROW_FOR_NOTHING_INFORMATION + 1][k];
                  }
                  else 
                  {
                    for (unsigned int k = 0; k<MAX_COL_LCD; k++)
                      name_string_tmp[j + NUMBER_ROW_FOR_NOTHING_INFORMATION][k] = ' ';
                  }
                }
                if (current_ekran.index_position >= index_in_list) position_temp--;
          
                offset++;
                //Робота з Watchdog
                watchdog_routine(UNITED_BITS_WATCHDOG);
              }
              else
              {
                _SET_BIT(maska, j1);
                j1++;
              }
                
              index_in_list++;
            }
          }
          else
            index_in_list += ((min_max_number[i][1] - min_max_number[i][0]) + 1);
        }
      }
      else if (min_max_number[i][0] >=0)
      {
        //Відкидати імена функцій і зміщати біти треба тільки у тому випадку, якщо функції пристні у списку для ранжування для даного захисту
        //Формуємо маску біт, які не треба переміщати при переміщенні імен полів
        unsigned int maska[N_BIG];
        for (size_t k = 0; k < N_BIG; ++k) maska[k] = 0;
        for (unsigned int j = 0; j < (min_max_number[i][0] - offset); j++) _SET_BIT(maska, j);
          
        //Відкидаємо назви функцій із списку, які є зайвими
        while(index_in_list <= min_max_number[i][1])
        {
          /***/
          //Зміщуємо біти стану реанжування функцій разом із їх назвами
          /***/
          unsigned int new_temp_data_1[N_BIG], new_temp_data_2[N_BIG];

          for (unsigned int k = 0; k < N_BIG; k++)
          {
            new_temp_data_1[k] = state_viewing_input[k] & maska[k];

            new_temp_data_2[k] = state_viewing_input[k] & (~maska[k]);
          }

          for (unsigned int k = 0; k < (N_BIG - 1); k++)
          {
            new_temp_data_2[k] = ( (new_temp_data_2[k] >> 1) | ((new_temp_data_2[k + 1] & 0x1) << 31) ) & (~maska[k]);
          }
          new_temp_data_2[N_BIG - 1] =  (new_temp_data_2[N_BIG - 1] >> 1) & (~maska[N_BIG - 1]);
                
          for (unsigned int k = 0; k < N_BIG; k++)
          {
            state_viewing_input[k] = new_temp_data_1[k] | new_temp_data_2[k];
          }
          /***/
          for (unsigned int j = (index_in_list - offset); j < (max_row_ranguvannja - offset); j++)
          {
            if ((j + 1) < (max_row_ranguvannja - offset))
            {
              for (unsigned int k = 0; k<MAX_COL_LCD; k++)
                name_string_tmp[j + NUMBER_ROW_FOR_NOTHING_INFORMATION][k] = name_string_tmp[j + NUMBER_ROW_FOR_NOTHING_INFORMATION + 1][k];
            }
            else 
            {
              for (unsigned int k = 0; k<MAX_COL_LCD; k++)
                name_string_tmp[j + NUMBER_ROW_FOR_NOTHING_INFORMATION][k] = ' ';
            }
          }
          if (current_ekran.index_position >= index_in_list) position_temp--;
          
          offset++;
          index_in_list++;
          //Робота з Watchdog
          watchdog_routine(UNITED_BITS_WATCHDOG);
        }
      }

          
      //Робота з Watchdog
      watchdog_routine(UNITED_BITS_WATCHDOG);
    }
    /*************************************************************/

    //Множення на два величини position_temp потрібне для того, бо на одну позицію ми використовуємо два рядки (назва + значення)
    index_of_ekran = ((position_temp<<1) >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;

    for (i=0; i< MAX_ROW_LCD; i++)
    {
     if (index_of_ekran < ((max_row_ranguvannja - offset)<<1))//Множення на два константи  max_row_ranguvannja потрібне для того, бо на одну позицію ми використовуємо два рядки (назва + значення)
     {
       if ((i & 0x1) == 0)
       {
         //У непарному номері рядку виводимо заголовок
         for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string_tmp[(index_of_ekran>>1) + NUMBER_ROW_FOR_NOTHING_INFORMATION][j];
       }
       else
       {
         //У парному номері рядку виводимо стан функції
         static const unsigned char information[MAX_NAMBER_LANGUAGE][2][MAX_COL_LCD] = 
         {
           {"      ОТКЛ      ", "      ВКЛ       "},
           {"      ВИМК      ", "     УВІМК      "},
           {"      OFF       ", "       ON       "},
           {"      СЉНД      ", "      КОСУ      "}
         };
         unsigned int index_bit = index_of_ekran >> 1;
         
         for (unsigned int j = 0; j < MAX_COL_LCD; j++) working_ekran[i][j] = information[index_language][((state_viewing_input[index_bit >> 5] & ( 1<< (index_bit & 0x1f))) != 0)][j];
       }
     }
     else
     for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = ' ';

     index_of_ekran++;
    }
    
    static const unsigned int cursor_x[MAX_NAMBER_LANGUAGE][2] = 
    {
      {5, 5},
      {5, 4},
      {5, 6},
      {5, 5}
    };

    //Відображення курору по вертикалі і курсор завжди має бути у полі із значенням устаки
    current_ekran.position_cursor_x =  cursor_x[index_language][((state_viewing_input[position_temp >> 5] & (1 << (position_temp & 0x1f))) != 0)];
    current_ekran.position_cursor_y = ((position_temp<<1) + 1) & (MAX_ROW_LCD - 1);
    
    //Курсор мигає
    current_ekran.cursor_blinking_on = 1;
    //Режим відображення у режимі редагування
  }
  

  //Обновити повністю весь екран
  current_ekran.current_action = ACTION_WITH_CARRENT_EKRANE_FULL_UPDATE;

#undef NUMBER_ROW_FOR_NOTHING_INFORMATION
}
/*****************************************************/

/*****************************************************/
//Перевірка, чи текучий індекс вказує на функцію,
 //яка присутня у даній конфігурації
/*****************************************************/
void check_current_index_is_presented_in_configuration_a01(
                                                         unsigned int* found_new_index_tmp,
                                                                  /*int* add_filter_point,*/
                                                                  /*EL_FILTER_STRUCT el_filter[],*/
                                                                  int plus_minus,
                                                                  int number_general_function,
                                                                  int number_dzo_function,
                                                                  int number_rsvr_function,
                                                                  int number_zdz_vod_function,
                                                                  int number_mtzo_function,
                                                                  int number_mtzr_function,
                                                                  int number_apv_function,
                                                                  int number_achr_chapv_function,
                                                                  int number_urov_function,
                                                                  int number_dzr_function,
                                                                  int number_Umin_function,
                                                                  int number_Umax_function,
                                                                  int number_UP_function,
                                                                  int number_vmp_function,
                                                                  int number_el_function
                                                        )
{
  if(plus_minus == 1)
  {
    if (current_ekran.index_position < number_general_function) *found_new_index_tmp = 1;
    else
    {
      if (current_ekran.index_position < (number_general_function + number_dzo_function))
      {
        if ((current_settings.configuration & (1<<DZO_BIT_CONFIGURATION)) != 0) *found_new_index_tmp = 1;
        else current_ekran.index_position = number_general_function + number_dzo_function;
      }
      else if (current_ekran.index_position < (number_general_function + number_dzo_function + number_rsvr_function/*number_mtz_function*/))
      {
        if ((current_settings.configuration & (1<<MTZ1_BIT_CONFIGURATION)) != 0) *found_new_index_tmp = 1;
        else current_ekran.index_position = number_general_function + number_dzo_function + number_rsvr_function;
      }
      else if (current_ekran.index_position < (number_general_function + number_dzo_function + number_rsvr_function + number_zdz_vod_function))
      {
        if ((current_settings.configuration & (1<<ZDZ_VOD_BIT_CONFIGURATION)) != 0) *found_new_index_tmp = 1;
        else current_ekran.index_position = number_general_function + number_dzo_function + number_rsvr_function + number_zdz_vod_function;
      }
      else if (current_ekran.index_position < (number_general_function + number_dzo_function + number_rsvr_function + number_zdz_vod_function + number_mtzo_function))
      {
        if ((current_settings.configuration & (1<<MCZO_BIT_CONFIGURATION)) != 0) *found_new_index_tmp = 1;
        else current_ekran.index_position = number_general_function + number_dzo_function + number_rsvr_function + number_zdz_vod_function + number_mtzo_function;
      }
      else if (current_ekran.index_position < (number_general_function + number_dzo_function + number_rsvr_function + number_zdz_vod_function + number_mtzo_function + number_mtzr_function))
      {
        if ((current_settings.configuration & (1<<MCZR_BIT_CONFIGURATION)) != 0) *found_new_index_tmp = 1;
        else current_ekran.index_position = number_general_function + number_dzo_function + number_rsvr_function + number_zdz_vod_function + number_mtzo_function + number_mtzr_function;
      }
      else if (current_ekran.index_position < (number_general_function + number_dzo_function + number_rsvr_function + number_zdz_vod_function + number_mtzo_function + number_mtzr_function + number_apv_function))
      {
        if ((current_settings.configuration & (1<<APV_BIT_CONFIGURATION)) != 0) *found_new_index_tmp = 1;
        else current_ekran.index_position = number_general_function + number_dzo_function + number_rsvr_function + number_zdz_vod_function + number_mtzo_function + number_mtzr_function + number_apv_function;
      }
      else if (current_ekran.index_position < (number_general_function + number_dzo_function + number_rsvr_function + number_zdz_vod_function + number_mtzo_function + number_mtzr_function + number_apv_function + number_achr_chapv_function))
      {
        if ((current_settings.configuration & (1<<ACHR_CHAPV_BIT_CONFIGURATION)) != 0) *found_new_index_tmp = 1;
        else current_ekran.index_position = number_general_function + number_dzo_function + number_rsvr_function + number_zdz_vod_function + number_mtzo_function + number_mtzr_function + number_apv_function + number_achr_chapv_function;
      }
      else if (current_ekran.index_position < (number_general_function + number_dzo_function + number_rsvr_function + number_zdz_vod_function + number_mtzo_function + number_mtzr_function + number_apv_function + number_achr_chapv_function + number_urov_function))
      {
        if ((current_settings.configuration & (1<<UROV_BIT_CONFIGURATION)) != 0) *found_new_index_tmp = 1;
        else current_ekran.index_position = number_general_function + number_dzo_function + number_rsvr_function + number_zdz_vod_function + number_mtzo_function + number_mtzr_function + number_apv_function + number_achr_chapv_function + number_urov_function;
      }
      else if (current_ekran.index_position < (number_general_function + number_dzo_function + number_rsvr_function + number_zdz_vod_function + number_mtzo_function + number_mtzr_function + number_apv_function + number_achr_chapv_function + number_urov_function + number_dzr_function))
      {
        if ((current_settings.configuration & (1<<DZR_BIT_CONFIGURATION)) != 0) *found_new_index_tmp = 1;
        else current_ekran.index_position = number_general_function + number_dzo_function + number_rsvr_function + number_zdz_vod_function + number_mtzo_function + number_mtzr_function + number_apv_function + number_achr_chapv_function + number_urov_function + number_dzr_function;
      }
      else if (current_ekran.index_position < (number_general_function + number_dzo_function + number_rsvr_function + number_zdz_vod_function + number_mtzo_function + number_mtzr_function + number_apv_function + number_achr_chapv_function + number_urov_function + number_dzr_function + number_Umin_function))
      {
        if ((current_settings.configuration & (1<<UMIN_BIT_CONFIGURATION)) != 0) *found_new_index_tmp = 1;
        else current_ekran.index_position = number_general_function + number_dzo_function + number_rsvr_function + number_zdz_vod_function + number_mtzo_function + number_mtzr_function + number_apv_function + number_achr_chapv_function + number_urov_function + number_dzr_function + number_Umin_function;
      }
      else if (current_ekran.index_position < (number_general_function + number_dzo_function + number_rsvr_function + number_zdz_vod_function + number_mtzo_function + number_mtzr_function + number_apv_function + number_achr_chapv_function + number_urov_function + number_dzr_function + number_Umin_function + number_Umax_function))
      {
        if ((current_settings.configuration & (1<<UMAX_BIT_CONFIGURATION)) != 0) *found_new_index_tmp = 1;
        else current_ekran.index_position = number_general_function + number_dzo_function + number_rsvr_function + number_zdz_vod_function + number_mtzo_function + number_mtzr_function + number_apv_function + number_achr_chapv_function + number_urov_function + number_dzr_function + number_Umin_function + number_Umax_function;
      }
      else if (current_ekran.index_position < (number_general_function + number_dzo_function + number_rsvr_function + number_zdz_vod_function + number_mtzo_function + number_mtzr_function + number_apv_function + number_achr_chapv_function + number_urov_function + number_dzr_function + number_Umin_function + number_Umax_function + number_UP_function))
      {
        if ((current_settings.configuration & (1<<UP_BIT_CONFIGURATION)) != 0) *found_new_index_tmp = 1;
        else current_ekran.index_position = number_general_function + number_dzo_function + number_rsvr_function + number_zdz_vod_function + number_mtzo_function + number_mtzr_function + number_apv_function + number_achr_chapv_function + number_urov_function + number_dzr_function + number_Umin_function + number_Umax_function + number_UP_function;
      }
      else if (current_ekran.index_position < (number_general_function + number_dzo_function + number_rsvr_function + number_zdz_vod_function + number_mtzo_function + number_mtzr_function + number_apv_function + number_achr_chapv_function + number_urov_function + number_dzr_function + number_Umin_function + number_Umax_function + number_UP_function + number_vmp_function))
      {
        if ((current_settings.configuration & (1<<VMP_BIT_CONFIGURATION)) != 0) *found_new_index_tmp = 1;
        else current_ekran.index_position = number_general_function + number_dzo_function + number_rsvr_function + number_zdz_vod_function + number_mtzo_function + number_mtzr_function + number_apv_function + number_achr_chapv_function + number_urov_function + number_dzr_function + number_Umin_function + number_Umax_function + number_UP_function + number_vmp_function;
      }
      else if (current_ekran.index_position < (number_general_function + number_dzo_function + number_rsvr_function + number_zdz_vod_function + number_mtzo_function + number_mtzr_function + number_apv_function + number_achr_chapv_function + number_urov_function + number_dzr_function + number_Umin_function + number_Umax_function + number_UP_function + number_vmp_function + number_el_function))
      {
        if ((current_settings.configuration & (1<<EL_BIT_CONFIGURATION)) != 0) *found_new_index_tmp = 1;
        else current_ekran.index_position = number_general_function + number_dzo_function + number_rsvr_function + number_zdz_vod_function + number_mtzo_function + number_mtzr_function + number_apv_function + number_achr_chapv_function + number_urov_function + number_dzr_function + number_Umin_function + number_Umax_function + number_UP_function + number_vmp_function + number_el_function;
      }
    }
  }
  else
  {
    if (current_ekran.index_position < number_general_function) *found_new_index_tmp = 1;
    else
    {
      if (current_ekran.index_position < (number_general_function + number_dzo_function))
      {
        if ((current_settings.configuration & (1<<DZO_BIT_CONFIGURATION)) != 0) *found_new_index_tmp = 1;
        else current_ekran.index_position = number_general_function - 1;
      }
      else if (current_ekran.index_position < (number_general_function + number_dzo_function + number_rsvr_function))
      {
        if ((current_settings.configuration & (1<<MTZ1_BIT_CONFIGURATION)) != 0) *found_new_index_tmp = 1;
        else current_ekran.index_position = number_general_function + number_dzo_function - 1;
      }
      else if (current_ekran.index_position < (number_general_function + number_dzo_function + number_rsvr_function + number_zdz_vod_function))
      {
        if ((current_settings.configuration & (1<<ZDZ_VOD_BIT_CONFIGURATION)) != 0) *found_new_index_tmp = 1;
        else current_ekran.index_position = number_general_function + number_dzo_function + number_rsvr_function - 1;
      }
      else if (current_ekran.index_position < (number_general_function + number_dzo_function + number_rsvr_function + number_zdz_vod_function + number_mtzo_function))
      {
        if ((current_settings.configuration & (1<<MCZO_BIT_CONFIGURATION)) != 0) *found_new_index_tmp = 1;
        else current_ekran.index_position = number_general_function + number_dzo_function + number_rsvr_function + number_zdz_vod_function - 1;
      }
      else if (current_ekran.index_position < (number_general_function + number_dzo_function + number_rsvr_function + number_zdz_vod_function + number_mtzo_function + number_mtzr_function))
      {
        if ((current_settings.configuration & (1<<MCZR_BIT_CONFIGURATION)) != 0) *found_new_index_tmp = 1;
        else current_ekran.index_position = number_general_function + number_dzo_function + number_rsvr_function + number_zdz_vod_function + number_mtzo_function - 1;
      }
      else if (current_ekran.index_position < (number_general_function + number_dzo_function + number_rsvr_function + number_zdz_vod_function + number_mtzo_function + number_mtzr_function + number_apv_function))
      {
        if ((current_settings.configuration & (1<<APV_BIT_CONFIGURATION)) != 0) *found_new_index_tmp = 1;
        else current_ekran.index_position = number_general_function + number_dzo_function + number_rsvr_function + number_zdz_vod_function + number_mtzo_function + number_mtzr_function - 1;
      }
      else if (current_ekran.index_position < (number_general_function + number_dzo_function + number_rsvr_function + number_zdz_vod_function + number_mtzo_function + number_mtzr_function + number_apv_function + number_achr_chapv_function))
      {
        if ((current_settings.configuration & (1<<ACHR_CHAPV_BIT_CONFIGURATION)) != 0) *found_new_index_tmp = 1;
        else current_ekran.index_position = number_general_function + number_dzo_function + number_rsvr_function + number_zdz_vod_function + number_mtzo_function + number_mtzr_function + number_apv_function + - 1;
      }
      else if (current_ekran.index_position < (number_general_function + number_dzo_function + number_rsvr_function + number_zdz_vod_function + number_mtzo_function + number_mtzr_function + number_apv_function + number_achr_chapv_function + number_urov_function))
      {
        if ((current_settings.configuration & (1<<UROV_BIT_CONFIGURATION)) != 0) *found_new_index_tmp = 1;
        else current_ekran.index_position = number_general_function + number_dzo_function + number_rsvr_function + number_zdz_vod_function + number_mtzo_function + number_mtzr_function + number_apv_function + number_achr_chapv_function - 1;
      }
      else if (current_ekran.index_position < (number_general_function + number_dzo_function + number_rsvr_function + number_zdz_vod_function + number_mtzo_function + number_mtzr_function + number_apv_function + number_achr_chapv_function + number_urov_function + number_dzr_function))
      {
        if ((current_settings.configuration & (1<<DZR_BIT_CONFIGURATION)) != 0) *found_new_index_tmp = 1;
        else current_ekran.index_position = number_general_function + number_dzo_function + number_rsvr_function + number_zdz_vod_function + number_mtzo_function + number_mtzr_function + number_apv_function + number_achr_chapv_function + number_urov_function - 1;
      }
      else if (current_ekran.index_position < (number_general_function + number_dzo_function + number_rsvr_function + number_zdz_vod_function + number_mtzo_function + number_mtzr_function + number_apv_function + number_achr_chapv_function + number_urov_function + number_dzr_function + number_Umin_function))
      {
        if ((current_settings.configuration & (1<<UMIN_BIT_CONFIGURATION)) != 0) *found_new_index_tmp = 1;
        else current_ekran.index_position = number_general_function + number_dzo_function + number_rsvr_function + number_zdz_vod_function + number_mtzo_function + number_mtzr_function + number_apv_function + number_achr_chapv_function + number_urov_function + number_dzr_function - 1;
      }
      else if (current_ekran.index_position < (number_general_function + number_dzo_function + number_rsvr_function + number_zdz_vod_function + number_mtzo_function + number_mtzr_function + number_apv_function + number_achr_chapv_function + number_urov_function + number_dzr_function + number_Umin_function + number_Umax_function))
      {
        if ((current_settings.configuration & (1<<UMAX_BIT_CONFIGURATION)) != 0) *found_new_index_tmp = 1;
        else current_ekran.index_position = number_general_function + number_dzo_function + number_rsvr_function + number_zdz_vod_function + number_mtzo_function + number_mtzr_function + number_apv_function + number_achr_chapv_function + number_urov_function + number_dzr_function + number_Umin_function - 1;
      }
      else if (current_ekran.index_position < (number_general_function + number_dzo_function + number_rsvr_function + number_zdz_vod_function + number_mtzo_function + number_mtzr_function + number_apv_function + number_achr_chapv_function + number_urov_function + number_dzr_function + number_Umin_function + number_Umax_function + number_UP_function))
      {
        if ((current_settings.configuration & (1<<UP_BIT_CONFIGURATION)) != 0) *found_new_index_tmp = 1;
        else current_ekran.index_position = number_general_function + number_dzo_function + number_rsvr_function + number_zdz_vod_function + number_mtzo_function + number_mtzr_function + number_apv_function + number_achr_chapv_function + number_urov_function + number_dzr_function + number_Umin_function + number_Umax_function - 1;
      }
      else if (current_ekran.index_position < (number_general_function + number_dzo_function + number_rsvr_function + number_zdz_vod_function + number_mtzo_function + number_mtzr_function + number_apv_function + number_achr_chapv_function + number_urov_function + number_dzr_function + number_Umin_function + number_Umax_function + number_UP_function + number_vmp_function))
      {
        if ((current_settings.configuration & (1<<VMP_BIT_CONFIGURATION)) != 0) *found_new_index_tmp = 1;
        else current_ekran.index_position = number_general_function + number_dzo_function + number_rsvr_function + number_zdz_vod_function + number_mtzo_function + number_mtzr_function + number_apv_function + number_achr_chapv_function + number_urov_function + number_dzr_function + number_Umin_function + number_Umax_function + number_UP_function - 1;
      }
      else if (current_ekran.index_position < (number_general_function + number_dzo_function + number_rsvr_function + number_zdz_vod_function + number_mtzo_function + number_mtzr_function + number_apv_function + number_achr_chapv_function + number_urov_function + number_dzr_function + number_Umin_function + number_Umax_function + number_UP_function + number_vmp_function + number_el_function))
      {
        if ((current_settings.configuration & (1<<EL_BIT_CONFIGURATION)) != 0) *found_new_index_tmp = 1;
        else current_ekran.index_position = number_general_function + number_dzo_function + number_rsvr_function + number_zdz_vod_function + number_mtzo_function + number_mtzr_function + number_apv_function + number_achr_chapv_function + number_urov_function + number_dzr_function + number_Umin_function + number_Umax_function + number_UP_function + number_vmp_function - 1;
      }
    }
  }
}
/*****************************************************/
/*****************************************************/
//
/*****************************************************/
/*****************************************************/
