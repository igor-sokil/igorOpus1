#include "header.h"


/*****************************************************/
//Формуємо екран відображення уставок ДЗ
/*****************************************************/
void make_ekran_setpoint_dzo(unsigned int group)
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_SETPOINT_DZO][MAX_COL_LCD] = 
  {
    {
      "Кблк ДЗО гололед",
      "  Уставка ДЗO1  ",
      "  Уставка AМТЗO1",
      "Устав. ДЗO1 Іблк", 
      "   Угол  ДЗO2   ",
      "  Прямая  ДЗO2  ",
      "  Обратная ДЗO2 ",
      "  Уставка AМТЗO2",
      "ДЗO3 в.г.сектора",
      "ДЗO3 н.г.сектора",
      "  Прямая  ДЗO3  ",
      "  Обратная ДЗO3 ",
      "  Уставка AМТЗO3",
      "Zo Прямая ДЗO4  ",
      "Xo Прямая ДЗO4  ",
      "Zo Обратная ДЗO4",
      "Xo Обратная ДЗO4",
      "  Уставка AМТЗO4",
    },
    {
      "К блк ДЗО ожел. ",
      "  Уставка ДЗO1  ",
      "  Уставка AМСЗO1",
      "Уст.   ДЗO1 Іблк",
      "   Кут  ДЗO2    ",
      "  Пряма  ДЗO2   ",
      "  Зворотня ДЗO2 ",
      "  Уставка AМСЗO2",
      "ДЗO3 в.м.сектора",
      "ДЗO3 н.м.сектора",
      "  Пряма  ДЗO3   ",
      "  Зворотня ДЗO3 ",
      "  Уставка AМСЗO3",
      " Zo Пряма  ДЗO4 ",
      " Xo_Пряма  ДЗO4 ",
      " Zo Зворот. ДЗO4",
      " Xo Зворот. ДЗO4",
      "  Уставка AМСЗO4",
    },
    {
      "Eблк ДЗО гололед",
      "E Уставка ДЗO1  ",
      "E Уставка AМТЗO1",
      "Eстав. ДЗO1 Іблк", 
      "E  Угол  ДЗO2   ",
      "E Прямая  ДЗO2  ",
      "E Обратная ДЗO2 ",
      "E Уставка AМТЗO2",
      "EЗO3 в.г.сектора",
      "EЗO3 н.г.сектора",
      "E Прямая  ДЗO3  ",
      "E Обратная ДЗO3 ",
      "E Уставка AМТЗO3",

      "Eo Прямая ДЗO4  ",
      "Eo Прямая ДЗO4  ",
      "Eo Обратная ДЗO4",
      "Eo Обратная ДЗO4",
      "E Уставка AМТЗO4",
    },
    {
      "Кблк ДЗО гололед",
      "K Уставка ДЗO1  ",
      "K Уставка AМТЗO1",
      "Kстав. ДЗO1 Іблк", 
      "K  Угол  ДЗO2   ",
      "K Прямая  ДЗO2  ",
      "K Обратная ДЗO2 ",
      "K Уставка AМТЗO2",
      "KЗO3 в.г.сектора",
      "KЗO3 н.г.сектора",
      "K Прямая  ДЗO3  ",
      "K Обратная ДЗO3 ",
      "K Уставка AМТЗO3",
       
      "Ko Прямая ДЗO4  ",
      "Ko Прямая ДЗO4  ",
      "Ko Обратная ДЗO4",
      "Ko Обратная ДЗO4",
      "K Уставка AМТЗO4",
    },
  };
  int index_language = index_language_in_array(current_settings.language);
  
  unsigned int position_temp = current_ekran.index_position;
  unsigned int index_of_ekran;
  unsigned int vaga, value, first_symbol;
  unsigned int lValue;
  
  //Множення на два величини position_temp потрібне для того, бо наодн позицію ми використовуємо два рядки (назва + значення)
  index_of_ekran = ((position_temp<<1) >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;
  
  for (unsigned int i=0; i< MAX_ROW_LCD; i++)
  {
    unsigned int index_of_ekran_tmp = index_of_ekran >> 1;
    unsigned int view = (
                         (current_ekran.edition == 0) ||
                         (  
                          (position_temp != index_of_ekran_tmp) &&
                          !(
                            (index_of_ekran_tmp == INDEX_ML_STP_DZO3_ANGLE_H) && (position_temp == INDEX_ML_STP_DZO3_ANGLE_L) ||
                            (index_of_ekran_tmp == INDEX_ML_STP_DZO3_ANGLE_L) && (position_temp == INDEX_ML_STP_DZO3_ANGLE_H)
                           ) 
                         )   
                        );
    if (index_of_ekran_tmp < MAX_ROW_FOR_SETPOINT_DZO)//MAX_ROW_FOR_SETPOINT_DZ
    {
      if ((i & 0x1) == 0)
      {
        //У непарному номері рядку виводимо заголовок
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_language][index_of_ekran_tmp][j];
        if (index_of_ekran_tmp == INDEX_ML_STP_K_ICE_DZO)//INDEX_ML_STP_K_DZ
        {
          vaga = 1000; //максимальний ваговий коефіцієнт для вилілення старшого розряду
          if (view == true) value = current_settings.pickup_dzo_Io3g_Io1g[group]; //у змінну value поміщаємо значення уставки
          else value = edition_settings.pickup_dzo_Io3g_Io1g[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZO1)//INDEX_ML_STP_DZ1
        {
          vaga = 100000; //максимальний ваговий коефіцієнт для вилілення старшого розряду
          if (view == true) value = current_settings.pickup_dzo1[group]; //у змінну value поміщаємо значення уставки
          else value = edition_settings.pickup_dzo1[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZO1_AMTZ)//INDEX_ML_STP_DZ1_AMTZ
        {
          vaga = 100000; //максимальний ваговий коефіцієнт для вилілення старшого розряду
          if (view == true) value = current_settings.pickup_dzo1_amtz[group]; //у змінну value поміщаємо значення уставки
          else value = edition_settings.pickup_dzo1_amtz[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZO1_I_BLK)//INDEX_ML_STP_DZ2_ANGLE
        {
          vaga = 100000; //максимальний ваговий коефіцієнт для вилілення старшого розряду
          if (view == true) value = current_settings.pickup_dzo1_blkI[group]; //у змінну value поміщаємо значення уставки
          else value = edition_settings.pickup_dzo1_blkI[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZO2_ANGLE)//INDEX_ML_STP_DZ2_DIR
        {
          vaga = 10; //максимальний ваговий коефіцієнт для вилілення старшого розряду
          if (view == true) value = current_settings.pickup_dzo2_angle[group]; //у змінну value поміщаємо значення уставки
          else value = edition_settings.pickup_dzo2_angle[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZO2_DIR)//INDEX_ML_STP_DZ2_INV
        {
          vaga = 100000; //максимальний ваговий коефіцієнт для вилілення старшого розряду
          if (view == true) value = current_settings.pickup_dzo2_dir[group]; //у змінну value поміщаємо значення уставки
          else value = edition_settings.pickup_dzo2_dir[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZO2_INV)//INDEX_ML_STP_DZ2_AMTZ
        {
          vaga = 100000; //максимальний ваговий коефіцієнт для вилілення старшого розряду
          if (view == true) value = current_settings.pickup_dzo2_inv[group]; //у змінну value поміщаємо значення уставки
          else value = edition_settings.pickup_dzo2_inv[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZO2_AMTZ)//INDEX_ML_STP_DZ3_ANGLE
        {
          vaga = 100000; //максимальний ваговий коефіцієнт для вилілення старшого розряду
          if (view == true) value = current_settings.pickup_dzo2_amtz[group]; //у змінну value поміщаємо значення уставки
          else value = edition_settings.pickup_dzo2_amtz[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZO3_ANGLE_H)//INDEX_ML_STP_DZ3_DIR
        {
          vaga = 100; //максимальний ваговий коефіцієнт для вилілення старшого розряду
          if (view == true) value = current_settings.pickup_dzo3_angle_h[group]; //у змінну value поміщаємо значення уставки
          else value = edition_settings.pickup_dzo3_angle_h[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZO3_ANGLE_L)//INDEX_ML_STP_DZ3_INV
        {
          vaga = 100; //максимальний ваговий коефіцієнт для вилілення старшого розряду
          if (view == true) value = current_settings.pickup_dzo3_angle_l[group]; //у змінну value поміщаємо значення уставки
          else value = edition_settings.pickup_dzo3_angle_l[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZO3_DIR)//INDEX_ML_STP_DZ3_AMTZ
        {
          vaga = 100000; //максимальний ваговий коефіцієнт для вилілення старшого розряду
          if (view == true) value = current_settings.pickup_dzo3_dir[group]; //у змінну value поміщаємо значення уставки
          else value = edition_settings.pickup_dzo3_dir[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZO3_INV)//INDEX_ML_STP_DZ4_ANGLE
        {
          vaga = 100000; //максимальний ваговий коефіцієнт для вилілення старшого розряду
          if (view == true) value = current_settings.pickup_dzo3_inv[group]; //у змінну value поміщаємо значення уставки
          else value = edition_settings.pickup_dzo3_inv[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZO3_AMTZ)//INDEX_ML_STP_DZ4_DIR
        {
          vaga = 100000; //максимальний ваговий коефіцієнт для вилілення старшого розряду
          if (view == true) value = current_settings.pickup_dzo3_amtz[group]; //у змінну value поміщаємо значення уставки
          else value = edition_settings.pickup_dzo3_amtz[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZO4_Z0_DIR)//INDEX_ML_STP_DZ4_INV
        {
          vaga = 100000; //максимальний ваговий коефіцієнт для вилілення старшого розряду
          if (view == true) value = current_settings.pickup_dzo4_Zo_dir[group]; //у змінну value поміщаємо значення уставки
          else value = edition_settings.pickup_dzo4_Zo_dir[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZO4_X0_DIR)//INDEX_ML_STP_DZ4_AMTZ
        {
          vaga = 100000; //максимальний ваговий коефіцієнт для вилілення старшого розряду
          if (view == true) value = current_settings.pickup_dzo4_Xo_dir[group]; //у змінну value поміщаємо значення уставки
          else value = edition_settings.pickup_dzo4_Xo_dir[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZO4_Z0_INV)//INDEX_ML_STP_DZ4_AMTZ
        {
          vaga = 100000; //максимальний ваговий коефіцієнт для вилілення старшого розряду
          if (view == true) value = current_settings.pickup_dzo4_Zo_inv[group]; //у змінну value поміщаємо значення уставки
          else value = edition_settings.pickup_dzo4_Zo_inv[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZO4_X0_INV)//INDEX_ML_STP_DZ4_AMTZ
        {
          vaga = 100000; //максимальний ваговий коефіцієнт для вилілення старшого розряду
          if (view == true) value = current_settings.pickup_dzo4_Xo_inv[group]; //у змінну value поміщаємо значення уставки
          else value = edition_settings.pickup_dzo4_Xo_inv[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZO4_AMTZ)//INDEX_ML_STP_DZ4_AMTZ
        {
          vaga = 100000; //максимальний ваговий коефіцієнт для вилілення старшого розряду
          if (view == true) value = current_settings.pickup_dzo4_amtz[group]; //у змінну value поміщаємо значення уставки
          else value = edition_settings.pickup_dzo4_amtz[group];
        }
        
          lValue = value;
            if(lValue&0x8000000)
            {
             lValue = ~lValue;
             lValue++;
            }//if
        first_symbol = 0; //помічаємо, що ще ніодин значущий символ не виведений
      }
      else
      {
        //У парному номері рядку виводимо значення уставки
        for (unsigned int j = 0; j<MAX_COL_LCD; j++)
        {
          if (index_of_ekran_tmp == INDEX_ML_STP_K_ICE_DZO)//INDEX_ML_STP_K_DZ
          {
            if (
                ((j < COL_PICKUP_DZO_K_ICE_BEGIN) ||  (j > COL_PICKUP_DZO_K_ICE_END ))  &&
                (j != (COL_PICKUP_DZO_K_ICE_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZO_K_ICE_COMMA )working_ekran[i][j] = ',';
//            else if (j == (COL_PICKUP_DZ_K_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_A];
            else if (j == (COL_PICKUP_DZO_K_ICE_END + 2)) working_ekran[i][j] = ' ';
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZO_K_ICE_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZO1)//INDEX_ML_STP_DZ1
          {
            if (
                ((j < COL_PICKUP_DZO1_BEGIN) ||  (j > COL_PICKUP_DZO1_END ))  &&
                (j != (COL_PICKUP_DZO1_END + 2) && j != (COL_PICKUP_DZO1_END + 3))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZO1_COMMA )working_ekran[i][j] = ',';
            else if ((j >= (COL_PICKUP_DZ2_DIR_END + 2)) && (j <= (COL_PICKUP_DZ2_DIR_END + 2 + SIZE_R_DIMENSION - 1))) working_ekran[i][j] = resistance_dimension[index_language][j - (COL_PICKUP_DZ2_DIR_END + 2)];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZO1_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZO1_AMTZ)
          {
            if (
                ((j < COL_PICKUP_DZO1_AMTZ_BEGIN) ||  (j > COL_PICKUP_DZO1_AMTZ_END ))  &&
                (j != (COL_PICKUP_DZO1_AMTZ_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZO1_AMTZ_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_PICKUP_DZO1_AMTZ_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_A];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZO1_AMTZ_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZO1_I_BLK)
          {
            if (
                ((j < COL_PICKUP_DZO1_I_BLK_BEGIN) ||  (j > COL_PICKUP_DZO1_I_BLK_END ))  &&
                (j != (COL_PICKUP_DZO1_I_BLK_END + 2)) //&& j != (COL_PICKUP_DZO1_I_BLK_END + 3))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZO1_I_BLK_COMMA )working_ekran[i][j] = ',';
            else if ((j >= (COL_PICKUP_DZO1_I_BLK_END + 2)) && (j <= (COL_PICKUP_DZO1_I_BLK_END + 2 + SIZE_R_DIMENSION - 1))) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_A];//resistance_dimension[index_language][j - (COL_PICKUP_DZO1_I_BLK_END + 2)];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZO1_I_BLK_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZO2_ANGLE)
          {
            if(value&0x8000000)
            {
             working_ekran[i][COL_S_DZO2_ANGLE] = '-';//COL_SDZ2_ANGLE
            }
            else working_ekran[i][COL_S_DZO2_ANGLE] = '+';//COL_SDZ2_ANGLE
            if (
                ((j < COL_PICKUP_DZO2_ANGLE_BEGIN) ||  (j > COL_PICKUP_DZO2_ANGLE_END ))  &&
                (j != (COL_PICKUP_DZO2_ANGLE_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == (COL_PICKUP_DZO2_ANGLE_END + 2)) working_ekran[i][j] = '°';
            else
              calc_int_symbol_and_put_into_working_ekran((working_ekran[i] + j), &lValue, &vaga, &first_symbol, view);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZO2_DIR)
          {
            if (
                ((j < COL_PICKUP_DZO2_DIR_BEGIN) ||  (j > COL_PICKUP_DZO2_DIR_END ))  &&
                (j != (COL_PICKUP_DZO2_DIR_END + 2) && j != (COL_PICKUP_DZO2_DIR_END + 3))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZO2_DIR_COMMA )working_ekran[i][j] = ',';
            else if ((j >= (COL_PICKUP_DZO2_DIR_END + 2)) && (j <= (COL_PICKUP_DZO2_DIR_END + 2 + SIZE_R_DIMENSION - 1))) working_ekran[i][j] = resistance_dimension[index_language][j - (COL_PICKUP_DZO2_DIR_END + 2)];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZO2_DIR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZO2_INV)
          {
            if (
                ((j < COL_PICKUP_DZO2_INV_BEGIN) ||  (j > COL_PICKUP_DZO2_INV_END ))  &&
                (j != (COL_PICKUP_DZO2_INV_END + 2) && j != (COL_PICKUP_DZO2_INV_END + 3))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZO2_INV_COMMA )working_ekran[i][j] = ',';
            else if ((j >= (COL_PICKUP_DZO2_INV_END + 2)) && (j <= (COL_PICKUP_DZ2_DIR_END + 2 + SIZE_R_DIMENSION - 1))) working_ekran[i][j] = resistance_dimension[index_language][j - (COL_PICKUP_DZO2_INV_END + 2)];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZO2_INV_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZO2_AMTZ)
          {
            if (
                ((j < COL_PICKUP_DZO2_AMTZ_BEGIN) ||  (j > COL_PICKUP_DZO2_AMTZ_END ))  &&
                (j != (COL_PICKUP_DZO2_AMTZ_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZO2_AMTZ_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_PICKUP_DZO2_AMTZ_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_A];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZO2_AMTZ_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZO3_ANGLE_H)
          {
            if(value&0x8000000)
            {
             working_ekran[i][COL_DZO3_S_ANGLE_H] = '-';
            }
            else working_ekran[i][COL_DZO3_S_ANGLE_H] = '+';
            if (
                ((j < COL_PICKUP_DZO3_ANGLE_H_BEGIN) ||  (j > COL_PICKUP_DZO3_ANGLE_H_END ))  &&
                (j != (COL_PICKUP_DZO3_ANGLE_H_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == (COL_PICKUP_DZO3_ANGLE_H_END + 2)) working_ekran[i][j] = '°';
            else
            {
              calc_int_symbol_and_put_into_working_ekran((working_ekran[i] + j), &lValue, &vaga, &first_symbol, view);
            } 
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZO3_ANGLE_L)
          {
            if(value&0x8000000)
            {
             working_ekran[i][COL_DZO3_S_ANGLE_L] = '-';
            }
            else working_ekran[i][COL_DZO3_S_ANGLE_L] = '+';
            if (
                ((j < COL_PICKUP_DZO3_ANGLE_L_BEGIN) ||  (j > COL_PICKUP_DZO3_ANGLE_L_END ))  &&
                (j != (COL_PICKUP_DZO3_ANGLE_L_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == (COL_PICKUP_DZO3_ANGLE_L_END + 2)) working_ekran[i][j] = '°';
            else
            {
              calc_int_symbol_and_put_into_working_ekran((working_ekran[i] + j), &lValue, &vaga, &first_symbol, view);
            } 
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZO3_DIR)
          {
            if (
                ((j < COL_PICKUP_DZO3_DIR_BEGIN) ||  (j > COL_PICKUP_DZO3_DIR_END ))  &&
                (j != (COL_PICKUP_DZO3_DIR_END + 2) && j != (COL_PICKUP_DZO3_DIR_END + 3))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZO3_DIR_COMMA )working_ekran[i][j] = ',';
            else if ((j >= (COL_PICKUP_DZO3_DIR_END + 2)) && (j <= (COL_PICKUP_DZ2_DIR_END + 2 + SIZE_R_DIMENSION - 1))) working_ekran[i][j] = resistance_dimension[index_language][j - (COL_PICKUP_DZO3_DIR_END + 2)];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZO3_DIR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZO3_INV)
          {
            if (
                ((j < COL_PICKUP_DZO3_INV_BEGIN) ||  (j > COL_PICKUP_DZO3_INV_END ))  &&
                (j != (COL_PICKUP_DZO3_INV_END + 2) && j != (COL_PICKUP_DZO3_INV_END + 3))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZO3_INV_COMMA )working_ekran[i][j] = ',';
            else if ((j >= (COL_PICKUP_DZO3_INV_END + 2)) && (j <= (COL_PICKUP_DZ2_DIR_END + 2 + SIZE_R_DIMENSION - 1))) working_ekran[i][j] = resistance_dimension[index_language][j - (COL_PICKUP_DZO3_INV_END + 2)];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZO3_INV_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZO3_AMTZ)
          {
            if (
                ((j < COL_PICKUP_DZO3_AMTZ_BEGIN) ||  (j > COL_PICKUP_DZO3_AMTZ_END ))  &&
                (j != (COL_PICKUP_DZO3_AMTZ_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZO3_AMTZ_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_PICKUP_DZO3_AMTZ_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_A];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZO3_AMTZ_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZO4_Z0_DIR)
          {
            if (
                ((j < COL_PICKUP_DZO4_Z0_DIR_BEGIN) ||  (j > COL_PICKUP_DZO4_Z0_DIR_END ))  &&
                (j != (COL_PICKUP_DZO4_Z0_DIR_END + 2) && j != (COL_PICKUP_DZO4_Z0_DIR_END + 3))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZO4_Z0_DIR_COMMA )working_ekran[i][j] = ',';
            else if ((j >= (COL_PICKUP_DZO4_Z0_DIR_END + 2)) && (j <= (COL_PICKUP_DZ2_DIR_END + 2 + SIZE_R_DIMENSION - 1))) working_ekran[i][j] = resistance_dimension[index_language][j - (COL_PICKUP_DZO4_Z0_DIR_END + 2)];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZO4_Z0_DIR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZO4_X0_DIR)
          {
            if (
                ((j < COL_PICKUP_DZO4_X0_DIR_BEGIN) ||  (j > COL_PICKUP_DZO4_X0_DIR_END ))  &&
                (j != (COL_PICKUP_DZO4_X0_DIR_END + 2) && j != (COL_PICKUP_DZO4_X0_DIR_END + 3))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZO4_X0_DIR_COMMA  )working_ekran[i][j] = ',';
            else if ((j >= (COL_PICKUP_DZO4_X0_DIR_END + 2)) && (j <= (COL_PICKUP_DZ2_DIR_END + 2 + SIZE_R_DIMENSION - 1))) working_ekran[i][j] = resistance_dimension[index_language][j - (COL_PICKUP_DZO4_X0_DIR_END + 2)];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZO4_X0_DIR_COMMA , view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZO4_Z0_INV)
          {
            if (
                ((j < COL_PICKUP_DZO4_Z0_INV_BEGIN) ||  (j > COL_PICKUP_DZO4_Z0_INV_END ))  &&
                (j != (COL_PICKUP_DZO4_Z0_INV_END + 2) && j != (COL_PICKUP_DZO4_Z0_INV_END + 3))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZO4_Z0_INV_COMMA )working_ekran[i][j] = ',';
            else if ((j >= (COL_PICKUP_DZO4_Z0_INV_END + 2)) && (j <= (COL_PICKUP_DZ2_DIR_END + 2 + SIZE_R_DIMENSION - 1))) working_ekran[i][j] = resistance_dimension[index_language][j - (COL_PICKUP_DZO4_Z0_INV_END + 2)];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZO4_Z0_INV_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZO4_X0_INV)
          {
            if (
                ((j < COL_PICKUP_DZO4_X0_INV_BEGIN) ||  (j > COL_PICKUP_DZO4_X0_INV_END ))  &&
                (j != (COL_PICKUP_DZO4_X0_INV_END + 2) && j != (COL_PICKUP_DZO4_X0_INV_END + 3))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZO4_X0_INV_COMMA )working_ekran[i][j] = ',';
            else if ((j >= (COL_PICKUP_DZO4_X0_INV_END + 2)) && (j <= (COL_PICKUP_DZ2_DIR_END + 2 + SIZE_R_DIMENSION - 1))) working_ekran[i][j] = resistance_dimension[index_language][j - (COL_PICKUP_DZO4_X0_INV_END + 2)];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZO4_X0_INV_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZO4_AMTZ)
          {
            if (
                ((j < COL_PICKUP_DZO4_AMTZ_BEGIN) ||  (j > COL_PICKUP_DZO4_AMTZ_END ))  &&
                (j != (COL_PICKUP_DZO4_AMTZ_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZO4_AMTZ_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_PICKUP_DZO4_AMTZ_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_A];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZO4_AMTZ_COMMA, view, 0);
          }

        }
      }//
        
    }
    else
      for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = ' ';

    index_of_ekran++;
  }

  //Відображення курору по вертикалі і курсор завжди має бути у полі із значенням устаки
  current_ekran.position_cursor_y = ((position_temp<<1) + 1) & (MAX_ROW_LCD - 1);
  //Курсор по горизонталі відображається на першому символі у випадку, коли ми не в режимі редагування, інакше позиція буде визначена у функцї main_manu_function
  if (current_ekran.edition == 0)
  {
    int last_position_cursor_x = MAX_COL_LCD;
    if (current_ekran.index_position == INDEX_ML_STP_K_ICE_DZO)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZO_K_ICE_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZO_K_ICE_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZO1)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZO1_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZO1_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZO1_AMTZ)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZO1_AMTZ_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZO1_AMTZ_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZO1_I_BLK)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZO1_I_BLK_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZO1_I_BLK_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZO2_ANGLE)
    {
      current_ekran.position_cursor_x = COL_S_DZO2_ANGLE;//COL_PICKUP_DZ2_ANGLE_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZO2_ANGLE_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZO2_DIR)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZO2_DIR_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZO2_DIR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZO2_INV)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZO2_DIR_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZO2_DIR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZO2_AMTZ)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZO2_AMTZ_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZO2_AMTZ_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZO3_ANGLE_H)
    {
      current_ekran.position_cursor_x = COL_DZO3_S_ANGLE_H;//COL_PICKUP_DZ3_ANGLE_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZO3_ANGLE_H_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZO3_ANGLE_L)
    {
      current_ekran.position_cursor_x = COL_DZO3_S_ANGLE_L;//COL_PICKUP_DZ3_ANGLE_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZO3_ANGLE_L_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZO3_DIR)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZ3_DIR_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZ3_DIR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZO3_INV)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZO3_INV_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZO3_INV_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZO3_AMTZ)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZO3_AMTZ_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZO3_AMTZ_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZO4_Z0_DIR)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZO4_Z0_DIR_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZO4_Z0_DIR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZO4_X0_DIR)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZO4_X0_DIR_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZO4_X0_DIR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZO4_Z0_INV)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZO4_Z0_INV_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZO4_Z0_INV_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZO4_X0_INV)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZO4_X0_INV_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZO4_X0_INV_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZ4_AMTZ)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZO4_ANGLE_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZO4_ANGLE_END;
    }
    
    //Підтягуємо курсор до першого символу
    while (((working_ekran[current_ekran.position_cursor_y][current_ekran.position_cursor_x + 1]) == ' ') && 
           (current_ekran.position_cursor_x < (last_position_cursor_x -1))) current_ekran.position_cursor_x++;
    
    //Курсор ставимо так, щоб він був перед числом
    if (((working_ekran[current_ekran.position_cursor_y][current_ekran.position_cursor_x]) != ' ') && 
        (current_ekran.position_cursor_x > 0)) current_ekran.position_cursor_x--;
  }
  //Курсор видимий
  current_ekran.cursor_on = 1;
  //Курсор не мигає
  if(current_ekran.edition == 0)current_ekran.cursor_blinking_on = 0;
  else current_ekran.cursor_blinking_on = 1;
  //Обновити повністю весь екран
  current_ekran.current_action = ACTION_WITH_CARRENT_EKRANE_FULL_UPDATE;
}
/*****************************************************/

/*****************************************************/
//Формуємо екран відображення витримок ДЗ
/*****************************************************/
void make_ekran_timeout_dzo(unsigned int group)
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_TIMEOUT_DZO][MAX_COL_LCD] = 
  {
    {
      "  Выдержка ДЗO1 ",
      " Выдержка AМТЗO1",
      "Выдержка ДЗO2ПРМ",
      "  Ускор ДЗO2 ПРМ",
      "Выдержка ДЗO2ОБР",
      "  Ускор ДЗO2 ОБР",
      " Выдержка AМТЗO2",
      "   Ускор AМТЗO2 ",
      "Ввод ускор ДЗO2 ",
      "Ввод ускр AМТЗO2",
      "Выдержка ДЗO3ПРМ",
      "  Ускор ДЗO3 ПРМ",
      "Выдержка ДЗO3ОБР",
      "  Ускор ДЗO3 ОБР",
      " Выдержка AМТЗO3",
      "   Ускор AМТЗO3 ",
      "Ввод ускор ДЗO3 ",
      "Ввод ускр AМТЗO3",
      "Выдержка ДЗO4ПРМ",
      "Выдержка ДЗO4ОБР",
      " Выдержка AМТЗO4",
      "Выдержка ДЗО НЦН",
    },
    {
      " Витримка ДЗO1  ",
      " Витримка AМСЗO1",
      "Витримка ДЗO2ПРМ",
      " Прискор ДЗO2ПРМ",
      "Витримка ДЗO2ЗВР",
      " Прискор ДЗO2ЗВР",
      " Витримка AМСЗO2",
      " Прискор AМСЗO2 ",
      " Ввод приск ДЗO2",
      "Ввд приск AМСЗO2",
      "Витримка ДЗO3ПРМ",
      " Прискор ДЗO3ПРМ",
      "Витримка ДЗO3ЗВР",
      " Прискор ДЗO3ЗВР",
      " Витримка AМСЗO3",
      " Прискор AМСЗO3 ",
      " Ввод приск ДЗO3",
      "Ввод прск AМСЗO3",
      "Витримка ДЗO4ПРМ",
      "Витримка ДЗO4ЗВР",
      " Витримка AМСЗO4",
      " Витр. ДЗО НКН  ",
    },
    {
      "E  Выдержка ДЗO1",
      "EВыдержка AМТЗO1",
      "Eыдержка ДЗO2ПРМ",
      "E Ускор ДЗO2 ПРМ",
      "Eыдержка ДЗO2ОБР",
      "E Ускор ДЗO2 ОБР",
      "EВыдержка AМТЗO2",
      "E  Ускор AМТЗO2 ",
      "Eвод ускор ДЗO2 ",
      "Eвод ускр AМТЗO2",
      "Eыдержка ДЗO3ПРМ",
      "E Ускор ДЗO3 ПРМ",
      "Eыдержка ДЗO3ОБР",
      "E Ускор ДЗO3 ОБР",
      "EВыдержка AМТЗO3",
      "E  Ускор AМТЗO3 ",
      "Eвод ускор ДЗO3 ",
      "Eвод ускр AМТЗO3",
      "Eыдержка ДЗO4ПРМ",
      "Eыдержка ДЗO4ОБР",
      "EВыдержка AМТЗO4",
      "Eыдержка ДЗО НЦН",
    },
    {
      "K Выдержка ДЗO1 ",
      "KВыдержка AМТЗO1",
      "Kыдержка ДЗO2ПРМ",
      "K Ускор ДЗO2 ПРМ",
      "Kыдержка ДЗO2ОБР",
      "K Ускор ДЗO2 ОБР",
      "KВыдержка AМТЗO2",
      "K  Ускор AМТЗO2 ",
      "Kвод ускор ДЗO2 ",
      "Kвод ускр AМТЗO2",
      "Kыдержка ДЗO3ПРМ",
      "K Ускор ДЗO3 ПРМ",
      "Kыдержка ДЗO3ОБР",
      "K Ускор ДЗO3 ОБР",
      "KВыдержка AМТЗO3",
      "K  Ускор AМТЗO3 ",
      "Kвод ускор ДЗO3 ",
      "Kвод ускр AМТЗO3",
      "Kыдержка ДЗO4ПРМ",
      "Kыдержка ДЗO4ОБР",
      "KВыдержка AМТЗO4",
      "Kыдержка ДЗО НЦН",
    }
  };
  int index_language = index_language_in_array(current_settings.language);
 
  unsigned int position_temp = current_ekran.index_position;
  unsigned int index_of_ekran;
  unsigned int vaga, value, first_symbol;
  
  //Множення на два величини position_temp потрібне для того, бо на одну позицію ми використовуємо два рядки (назва + значення)
  index_of_ekran = ((position_temp<<1) >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;

  
  for (unsigned int i=0; i< MAX_ROW_LCD; i++)
  {
    unsigned int index_of_ekran_tmp = index_of_ekran >> 1;
    unsigned int view = ((current_ekran.edition == 0) || (position_temp != index_of_ekran_tmp));
    if (index_of_ekran_tmp < MAX_ROW_FOR_TIMEOUT_DZO)
    {
      if ((i & 0x1) == 0)
      {
        //У непарному номері рядку виводимо заголовок
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_language][index_of_ekran_tmp][j];

        if (index_of_ekran_tmp == INDEX_ML_TMO_DZO1)
        {
          vaga = 10000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
          if (view == true) value = current_settings.timeout_dzo1[group]; //у змінну value поміщаємо значення витримки
          else value = edition_settings.timeout_dzo1[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO1_AMTZ)
        {
          vaga = 10000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
          if (view == true) value = current_settings.timeout_dzo1_amtz[group]; //у змінну value поміщаємо значення витримки
          else value = edition_settings.timeout_dzo1_amtz[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO2_DIR)
        {
          vaga = 10000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
          if (view == true) value = current_settings.timeout_dzo2_dir[group]; //у змінну value поміщаємо значення витримки
          else value = edition_settings.timeout_dzo2_dir[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO2_DIR_PR)
        {
          vaga = 1000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
          if (view == true) value = current_settings.timeout_dzo2_dir_pr[group]; //у змінну value поміщаємо значення витримки
          else value = edition_settings.timeout_dzo2_dir_pr[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO2_INV)
        {
          vaga = 10000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
          if (view == true) value = current_settings.timeout_dzo2_inv[group]; //у змінну value поміщаємо значення витримки
          else value = edition_settings.timeout_dzo2_inv[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO2_INV_PR)
        {
          vaga = 1000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
          if (view == true) value = current_settings.timeout_dzo2_inv_pr[group]; //у змінну value поміщаємо значення витримки
          else value = edition_settings.timeout_dzo2_inv_pr[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO2_AMTZ)
        {
          vaga = 10000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
          if (view == true) value = current_settings.timeout_dzo2_amtz[group]; //у змінну value поміщаємо значення витримки
          else value = edition_settings.timeout_dzo2_amtz[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO2_AMTZ_PR)
        {
          vaga = 1000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
          if (view == true) value = current_settings.timeout_dzo2_amtz_pr[group]; //у змінну value поміщаємо значення витримки
          else value = edition_settings.timeout_dzo2_amtz_pr[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO2_VVID_PR)
        {
          vaga = 1000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
          if (view == true) value = current_settings.timeout_dzo2_vvid_pr[group]; //у змінну value поміщаємо значення витримки
          else value = edition_settings.timeout_dzo2_vvid_pr[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO2_AMTZ_VVID_PR)
        {
          vaga = 1000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
          if (view == true) value = current_settings.timeout_dzo2_amtz_vvid_pr[group]; //у змінну value поміщаємо значення витримки
          else value = edition_settings.timeout_dzo2_amtz_vvid_pr[group];
        }

        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO3_DIR)
        {
          vaga = 10000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
          if (view == true) value = current_settings.timeout_dzo3_dir[group]; //у змінну value поміщаємо значення витримки
          else value = edition_settings.timeout_dzo3_dir[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO3_DIR_PR)
        {
          vaga = 1000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
          if (view == true) value = current_settings.timeout_dzo3_dir_pr[group]; //у змінну value поміщаємо значення витримки
          else value = edition_settings.timeout_dzo3_dir_pr[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO3_INV)
        {
          vaga = 10000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
          if (view == true) value = current_settings.timeout_dzo3_inv[group]; //у змінну value поміщаємо значення витримки
          else value = edition_settings.timeout_dzo3_inv[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO3_INV_PR)
        {
          vaga = 1000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
          if (view == true) value = current_settings.timeout_dzo3_inv_pr[group]; //у змінну value поміщаємо значення витримки
          else value = edition_settings.timeout_dzo3_inv_pr[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO3_AMTZ)
        {
          vaga = 10000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
          if (view == true) value = current_settings.timeout_dzo3_amtz[group]; //у змінну value поміщаємо значення витримки
          else value = edition_settings.timeout_dzo3_amtz[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO3_AMTZ_PR)
        {
          vaga = 1000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
          if (view == true) value = current_settings.timeout_dzo3_amtz_pr[group]; //у змінну value поміщаємо значення витримки
          else value = edition_settings.timeout_dzo3_amtz_pr[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO3_VVID_PR)
        {
          vaga = 1000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
          if (view == true) value = current_settings.timeout_dzo3_vvid_pr[group]; //у змінну value поміщаємо значення витримки
          else value = edition_settings.timeout_dzo3_vvid_pr[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO3_AMTZ_VVID_PR)
        {
          vaga = 1000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
          if (view == true) value = current_settings.timeout_dzo3_amtz_vvid_pr[group]; //у змінну value поміщаємо значення витримки
          else value = edition_settings.timeout_dzo3_amtz_vvid_pr[group];
        }

        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO4_DIR)
        {
          vaga = 10000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
          if (view == true) value = current_settings.timeout_dzo4_dir[group]; //у змінну value поміщаємо значення витримки
          else value = edition_settings.timeout_dzo4_dir[group];
        }
        //else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ4_DIR_PR)
        //{
        //  vaga = 1000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
        //  if (view == true) value = current_settings.timeout_dz4_dir_pr[group]; //у змінну value поміщаємо значення витримки
        //  else value = edition_settings.timeout_dz4_dir_pr[group];
        //}
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO4_INV)
        {
          vaga = 10000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
          if (view == true) value = current_settings.timeout_dzo4_inv[group]; //у змінну value поміщаємо значення витримки
          else value = edition_settings.timeout_dzo4_inv[group];
        }
        //else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ4_INV_PR)
        //{
        //  vaga = 1000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
        //  if (view == true) value = current_settings.timeout_dz4_inv_pr[group]; //у змінну value поміщаємо значення витримки
        //  else value = edition_settings.timeout_dz4_inv_pr[group];
        //}
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO4_AMTZ)
        {
          vaga = 10000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
          if (view == true) value = current_settings.timeout_dzo4_amtz[group]; //у змінну value поміщаємо значення витримки
          else value = edition_settings.timeout_dzo4_amtz[group];
        }
        //else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ4_AMTZ_PR)
        //{
        //  vaga = 1000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
        //  if (view == true) value = current_settings.timeout_dz4_amtz_pr[group]; //у змінну value поміщаємо значення витримки
        //  else value = edition_settings.timeout_dz4_amtz_pr[group];
        //}
        //else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ4_VVID_PR)
        //{
        //  vaga = 1000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
        //  if (view == true) value = current_settings.timeout_dz4_vvid_pr[group]; //у змінну value поміщаємо значення витримки
        //  else value = edition_settings.timeout_dz4_vvid_pr[group];
        //}
        //else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ4_AMTZ_VVID_PR)
        //{
        //  vaga = 1000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
        //  if (view == true) value = current_settings.timeout_dz4_amtz_vvid_pr[group]; //у змінну value поміщаємо значення витримки
        //  else value = edition_settings.timeout_dz4_amtz_vvid_pr[group];
        //}
        else if (index_of_ekran_tmp == INDEX_ML_TMO_NKN_DZO)
        {
          vaga = 1000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
          if (view == true) value = current_settings.timeout_nkn_dzo[group]; //у змінну value поміщаємо значення витримки
          else value = edition_settings.timeout_nkn_dzo[group];
        }

        first_symbol = 0; //помічаємо, що ще ніодин значущий символ не виведений
      }
      else
      {
        //У парному номері рядку виводимо значення уставки
        for (unsigned int j = 0; j<MAX_COL_LCD; j++)
        {
          if (index_of_ekran_tmp == INDEX_ML_TMO_DZO1)
          {
            if (
                ((j < COL_TMO_DZO1_BEGIN) ||  (j > COL_TMO_DZO1_END )) &&
                (j != (COL_TMO_DZO1_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZO1_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZO1_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZO1_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO1_AMTZ)
          {
            if (
                ((j < COL_TMO_DZO1_AMTZ_BEGIN) ||  (j > COL_TMO_DZO1_AMTZ_END )) &&
                (j != (COL_TMO_DZO1_AMTZ_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZO1_AMTZ_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZO1_AMTZ_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZO1_AMTZ_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO2_DIR)
          {
            if (
                ((j < COL_TMO_DZO2_DIR_BEGIN) ||  (j > COL_TMO_DZO2_DIR_END )) &&
                (j != (COL_TMO_DZO2_DIR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZO2_DIR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZO2_DIR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZO2_DIR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO2_DIR_PR)
          {
            if (
                ((j < COL_TMO_DZO2_DIR_PR_BEGIN) ||  (j > COL_TMO_DZO2_DIR_PR_END )) &&
                (j != (COL_TMO_DZO2_DIR_PR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZO2_DIR_PR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZO2_DIR_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZO2_DIR_PR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO2_INV)
          {
            if (
                ((j < COL_TMO_DZO2_INV_BEGIN) ||  (j > COL_TMO_DZO2_INV_END )) &&
                (j != (COL_TMO_DZO2_INV_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZO2_INV_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZO2_INV_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZO2_INV_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO2_INV_PR)
          {
            if (
                ((j < COL_TMO_DZO2_INV_PR_BEGIN) ||  (j > COL_TMO_DZO2_INV_PR_END )) &&
                (j != (COL_TMO_DZO2_INV_PR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZO2_INV_PR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZO2_INV_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZO2_INV_PR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO2_AMTZ)
          {
            if (
                ((j < COL_TMO_DZO2_AMTZ_BEGIN) ||  (j > COL_TMO_DZO2_AMTZ_END )) &&
                (j != (COL_TMO_DZO2_AMTZ_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZO2_AMTZ_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZO2_AMTZ_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZO2_AMTZ_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO2_AMTZ_PR)
          {
            if (
                ((j < COL_TMO_DZO2_AMTZ_PR_BEGIN) ||  (j > COL_TMO_DZO2_AMTZ_PR_END )) &&
                (j != (COL_TMO_DZO2_AMTZ_PR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZO2_AMTZ_PR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZO2_AMTZ_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZO2_AMTZ_PR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO2_VVID_PR)
          {
            if (
                ((j < COL_TMO_DZO2_VVID_PR_BEGIN) ||  (j > COL_TMO_DZO2_VVID_PR_END )) &&
                (j != (COL_TMO_DZO2_VVID_PR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZO2_VVID_PR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZO2_VVID_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZO2_VVID_PR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO2_AMTZ_VVID_PR)
          {
            if (
                ((j < COL_TMO_DZO2_AMTZ_VVID_PR_BEGIN) ||  (j > COL_TMO_DZO2_AMTZ_VVID_PR_END )) &&
                (j != (COL_TMO_DZO2_AMTZ_VVID_PR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZO2_AMTZ_VVID_PR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZO2_AMTZ_VVID_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZO2_AMTZ_VVID_PR_COMMA, view, 0);
          }


          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO3_DIR)
          {
            if (
                ((j < COL_TMO_DZO3_DIR_BEGIN) ||  (j > COL_TMO_DZO3_DIR_END )) &&
                (j != (COL_TMO_DZO3_DIR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZO3_DIR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZO3_DIR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZO3_DIR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO3_DIR_PR)
          {
            if (
                ((j < COL_TMO_DZO3_DIR_PR_BEGIN) ||  (j > COL_TMO_DZO3_DIR_PR_END )) &&
                (j != (COL_TMO_DZO3_DIR_PR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZO3_DIR_PR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZO3_DIR_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZO3_DIR_PR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO3_INV)
          {
            if (
                ((j < COL_TMO_DZO3_INV_BEGIN) ||  (j > COL_TMO_DZO3_INV_END )) &&
                (j != (COL_TMO_DZO3_INV_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZO3_INV_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZO3_INV_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZO3_INV_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ3_INV_PR)
          {
            if (
                ((j < COL_TMO_DZO3_INV_PR_BEGIN) ||  (j > COL_TMO_DZO3_INV_PR_END )) &&
                (j != (COL_TMO_DZO3_INV_PR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZO3_INV_PR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZO3_INV_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZO3_INV_PR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO3_AMTZ)
          {
            if (
                ((j < COL_TMO_DZO3_AMTZ_BEGIN) ||  (j > COL_TMO_DZO3_AMTZ_END )) &&
                (j != (COL_TMO_DZO3_AMTZ_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZO3_AMTZ_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZO3_AMTZ_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZO3_AMTZ_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO3_AMTZ_PR)
          {
            if (
                ((j < COL_TMO_DZO3_AMTZ_PR_BEGIN) ||  (j > COL_TMO_DZO3_AMTZ_PR_END )) &&
                (j != (COL_TMO_DZO3_AMTZ_PR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZO3_AMTZ_PR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZO3_AMTZ_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZO3_AMTZ_PR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO3_VVID_PR)
          {
            if (
                ((j < COL_TMO_DZO3_VVID_PR_BEGIN) ||  (j > COL_TMO_DZO3_VVID_PR_END )) &&
                (j != (COL_TMO_DZO3_VVID_PR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZO3_VVID_PR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZO3_VVID_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZO3_VVID_PR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO3_AMTZ_VVID_PR)
          {
            if (
                ((j < COL_TMO_DZO3_AMTZ_VVID_PR_BEGIN) ||  (j > COL_TMO_DZO3_AMTZ_VVID_PR_END )) &&
                (j != (COL_TMO_DZO3_AMTZ_VVID_PR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZO3_AMTZ_VVID_PR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZO3_AMTZ_VVID_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZO3_AMTZ_VVID_PR_COMMA, view, 0);
          }


          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO4_DIR)
          {
            if (
                ((j < COL_TMO_DZO4_DIR_BEGIN) ||  (j > COL_TMO_DZO4_DIR_END )) &&
                (j != (COL_TMO_DZO4_DIR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZO4_DIR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZO4_DIR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZO4_DIR_COMMA, view, 0);
          }
          //else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ4_DIR_PR)
          //{
          //  if (
          //      ((j < COL_TMO_DZ4_DIR_PR_BEGIN) ||  (j > COL_TMO_DZ4_DIR_PR_END )) &&
          //      (j != (COL_TMO_DZ4_DIR_PR_END + 2))  
          //     )working_ekran[i][j] = ' ';
          //  else if (j == COL_TMO_DZ4_DIR_PR_COMMA )working_ekran[i][j] = ',';
          //  else if (j == (COL_TMO_DZ4_DIR_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
          //  else
          //    calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZ4_DIR_PR_COMMA, view, 0);
          //}
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO4_INV)
          {
            if (
                ((j < COL_TMO_DZO4_INV_BEGIN) ||  (j > COL_TMO_DZO4_INV_END )) &&
                (j != (COL_TMO_DZO4_INV_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZO4_INV_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZO4_INV_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZO4_INV_COMMA, view, 0);
          }
          //else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ4_INV_PR)
          //{
          //  if (
          //      ((j < COL_TMO_DZ4_INV_PR_BEGIN) ||  (j > COL_TMO_DZ4_INV_PR_END )) &&
          //      (j != (COL_TMO_DZ4_INV_PR_END + 2))  
          //     )working_ekran[i][j] = ' ';
          //  else if (j == COL_TMO_DZ4_INV_PR_COMMA )working_ekran[i][j] = ',';
          //  else if (j == (COL_TMO_DZ4_INV_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
          //  else
          //    calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZ4_INV_PR_COMMA, view, 0);
          //}
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO4_AMTZ)
          {
            if (
                ((j < COL_TMO_DZO4_AMTZ_BEGIN) ||  (j > COL_TMO_DZO4_AMTZ_END )) &&
                (j != (COL_TMO_DZO4_AMTZ_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZO4_AMTZ_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZO4_AMTZ_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZO4_AMTZ_COMMA, view, 0);
          }
          //else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ4_AMTZ_PR)
          //{
          //  if (
          //      ((j < COL_TMO_DZ4_AMTZ_PR_BEGIN) ||  (j > COL_TMO_DZ4_AMTZ_PR_END )) &&
          //      (j != (COL_TMO_DZ4_AMTZ_PR_END + 2))  
          //     )working_ekran[i][j] = ' ';
          //  else if (j == COL_TMO_DZ4_AMTZ_PR_COMMA )working_ekran[i][j] = ',';
          //  else if (j == (COL_TMO_DZ4_AMTZ_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
          //  else
          //    calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZ4_AMTZ_PR_COMMA, view, 0);
          //}
          //else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ4_VVID_PR)
          //{
          //  if (
          //      ((j < COL_TMO_DZ4_VVID_PR_BEGIN) ||  (j > COL_TMO_DZ4_VVID_PR_END )) &&
          //      (j != (COL_TMO_DZ4_VVID_PR_END + 2))  
          //     )working_ekran[i][j] = ' ';
          //  else if (j == COL_TMO_DZ4_VVID_PR_COMMA )working_ekran[i][j] = ',';
          //  else if (j == (COL_TMO_DZ4_VVID_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
          //  else
          //    calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZ4_VVID_PR_COMMA, view, 0);
          //}
          //else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ4_AMTZ_VVID_PR)
          //{
          //  if (
          //      ((j < COL_TMO_DZ4_AMTZ_VVID_PR_BEGIN) ||  (j > COL_TMO_DZ4_AMTZ_VVID_PR_END )) &&
          //      (j != (COL_TMO_DZ4_AMTZ_VVID_PR_END + 2))  
          //     )working_ekran[i][j] = ' ';
          //  else if (j == COL_TMO_DZ4_AMTZ_VVID_PR_COMMA )working_ekran[i][j] = ',';
          //  else if (j == (COL_TMO_DZ4_AMTZ_VVID_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
          //  else
          //    calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZ4_AMTZ_VVID_PR_COMMA, view, 0);
          //}

          else if (index_of_ekran_tmp == INDEX_ML_TMO_NKN_DZO)
          {
            if (
                ((j < COL_TMO_NKN_DZO_BEGIN) ||  (j > COL_TMO_NKN_DZO_END )) &&
                (j != (COL_TMO_NKN_DZO_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_NKN_DZO_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_NKN_DZO_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_NKN_DZO_COMMA, view, 0);
          }

        }
      }
        
    }
    else
      for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = ' ';

    index_of_ekran++;
  }

  //Відображення курору по вертикалі і курсор завжди має бути у полі із значенням устаки
  current_ekran.position_cursor_y = ((position_temp<<1) + 1) & (MAX_ROW_LCD - 1);
  //Курсор по горизонталі відображається на першому символі у випадку, коли ми не в режимі редагування, інакше позиція буде визначена у функцї main_manu_function
  if (current_ekran.edition == 0)
  {
    int last_position_cursor_x = MAX_COL_LCD;
    if (current_ekran.index_position == INDEX_ML_TMO_DZO1) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZO1_BEGIN;
      last_position_cursor_x = COL_TMO_DZO1_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZO1_AMTZ) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZO1_AMTZ_BEGIN;
      last_position_cursor_x = COL_TMO_DZO1_AMTZ_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZO2_DIR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZO2_DIR_BEGIN;
      last_position_cursor_x = COL_TMO_DZO2_DIR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZO2_DIR_PR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZO2_DIR_PR_BEGIN;
      last_position_cursor_x = COL_TMO_DZO2_DIR_PR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZO2_INV) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZO2_INV_BEGIN;
      last_position_cursor_x = COL_TMO_DZO2_INV_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZO2_INV_PR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZO2_INV_PR_BEGIN;
      last_position_cursor_x = COL_TMO_DZO2_INV_PR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZO2_AMTZ) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZO2_AMTZ_BEGIN;
      last_position_cursor_x = COL_TMO_DZO2_AMTZ_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZO2_AMTZ_PR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZO2_AMTZ_PR_BEGIN;
      last_position_cursor_x = COL_TMO_DZO2_AMTZ_PR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZO2_VVID_PR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZO2_VVID_PR_BEGIN;
      last_position_cursor_x = COL_TMO_DZO2_VVID_PR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZO2_AMTZ_VVID_PR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZO2_AMTZ_VVID_PR_BEGIN;
      last_position_cursor_x = COL_TMO_DZ2_AMTZ_VVID_PR_END;
    }

    else if (current_ekran.index_position == INDEX_ML_TMO_DZO3_DIR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZO3_DIR_BEGIN;
      last_position_cursor_x = COL_TMO_DZO3_DIR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZO3_DIR_PR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZO3_DIR_PR_BEGIN;
      last_position_cursor_x = COL_TMO_DZO3_DIR_PR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZO3_INV) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZO3_INV_BEGIN;
      last_position_cursor_x = COL_TMO_DZO3_INV_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZ3_INV_PR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZO3_INV_PR_BEGIN;
      last_position_cursor_x = COL_TMO_DZO3_INV_PR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZO3_AMTZ) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZO3_AMTZ_BEGIN;
      last_position_cursor_x = COL_TMO_DZO3_AMTZ_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZO3_AMTZ_PR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZO3_AMTZ_PR_BEGIN;
      last_position_cursor_x = COL_TMO_DZO3_AMTZ_PR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZO3_VVID_PR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZO3_VVID_PR_BEGIN;
      last_position_cursor_x = COL_TMO_DZO3_VVID_PR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZO3_AMTZ_VVID_PR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZO3_AMTZ_VVID_PR_BEGIN;
      last_position_cursor_x = COL_TMO_DZO3_AMTZ_VVID_PR_END;
    }

    else if (current_ekran.index_position == INDEX_ML_TMO_DZO4_DIR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZO4_DIR_BEGIN;
      last_position_cursor_x = COL_TMO_DZO4_DIR_END;
    }
    //else if (current_ekran.index_position == INDEX_ML_TMO_DZ4_DIR_PR) 
    //{
    //  current_ekran.position_cursor_x = COL_TMO_DZ4_DIR_PR_BEGIN;
    //  last_position_cursor_x = COL_TMO_DZ4_DIR_PR_END;
    //}
    else if (current_ekran.index_position == INDEX_ML_TMO_DZO4_INV) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZO4_INV_BEGIN;
      last_position_cursor_x = COL_TMO_DZO4_INV_END;
    }
    //else if (current_ekran.index_position == INDEX_ML_TMO_DZ4_INV_PR) 
    //{
    //  current_ekran.position_cursor_x = COL_TMO_DZ4_INV_PR_BEGIN;
    //  last_position_cursor_x = COL_TMO_DZ4_INV_PR_END;
    //}
    else if (current_ekran.index_position == INDEX_ML_TMO_DZO4_AMTZ) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZO4_AMTZ_BEGIN;
      last_position_cursor_x = COL_TMO_DZO4_AMTZ_END;
    }
    //else if (current_ekran.index_position == INDEX_ML_TMO_DZ4_AMTZ_PR) 
    //{
    //  current_ekran.position_cursor_x = COL_TMO_DZ4_AMTZ_PR_BEGIN;
    //  last_position_cursor_x = COL_TMO_DZ4_AMTZ_PR_END;
    //}
    //else if (current_ekran.index_position == INDEX_ML_TMO_DZ4_VVID_PR) 
    //{
    //  current_ekran.position_cursor_x = COL_TMO_DZ4_VVID_PR_BEGIN;
    //  last_position_cursor_x = COL_TMO_DZ4_VVID_PR_END;
    //}
    //else if (current_ekran.index_position == INDEX_ML_TMO_DZ4_AMTZ_VVID_PR) 
    //{
    //  current_ekran.position_cursor_x = COL_TMO_DZ4_AMTZ_VVID_PR_BEGIN;
    //  last_position_cursor_x = COL_TMO_DZ4_AMTZ_VVID_PR_END;
    //}

    else if (current_ekran.index_position == INDEX_ML_TMO_NKN_DZO) 
    {
      current_ekran.position_cursor_x = COL_TMO_NKN_DZO_BEGIN;
      last_position_cursor_x = COL_TMO_NKN_DZO_END;
    }

    //Підтягуємо курсор до першого символу
    while (((working_ekran[current_ekran.position_cursor_y][current_ekran.position_cursor_x + 1]) == ' ') && 
           (current_ekran.position_cursor_x < (last_position_cursor_x -1))) current_ekran.position_cursor_x++;

    //Курсор ставимо так, щоб він був перед числом
    if (((working_ekran[current_ekran.position_cursor_y][current_ekran.position_cursor_x]) != ' ') && 
        (current_ekran.position_cursor_x > 0)) current_ekran.position_cursor_x--;
  }
  //Курсор видимий
  current_ekran.cursor_on = 1;
  //Курсор не мигає
  if(current_ekran.edition == 0)current_ekran.cursor_blinking_on = 0;
  else current_ekran.cursor_blinking_on = 1;
  //Обновити повністю весь екран
  current_ekran.current_action = ACTION_WITH_CARRENT_EKRANE_FULL_UPDATE;
}
/*****************************************************/

/*****************************************************/
//Формуємо екран відображення значення управлінської інформації для DZ 
/*****************************************************/
void make_ekran_control_dzo(void)
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_CONTROL_DZO][MAX_COL_LCD] = 
  {
    {
      "Неиспр.Напр.ДЗО ",//1
      "Блк ДЗО1 Iосн 3Г",//2
      "Блк ДЗО1 Iосн   ",//3
      "АМTЗ ДЗО 1      ",//4
      "ДЗО 1           ",//5
      "Пост ускор.ДЗО2 ",//6
      "Уск ДЗО2 от  ВВO",//7
      "Блк ДЗО2 IOсн3Г ",//8
      "АМТЗ ДЗО2       ",//9
      "ДЗО 2           ",//10
      "ДЗО2 прям       ",//11
      "ДЗО2 обр        ",//12
      "Пост уск.  ДЗО3 ",//13
      "Уск ДЗО3 от  ВВO",//14
      "Блк ДЗО3 IOсн3Г ",//15
      "АМTЗ ДЗО3       ",//16
      "ДЗО3            ",//17
      "ДЗО3 прям       ",//18
      "ДЗО3 обр        ",//19
      "Блк ДЗО4 IOсн3Г ",//20
      "АМTЗ ДЗО4       ",//21
      "ДЗО4            ",//22
      "ДЗО4 прям       ",//23
      "ДЗО4 обр        " //24
    },
    {
      "Неспр.Напр.ДЗО  ",//1
      "Блк ДЗО1 Iосн 3Г",//2
      "Блк ДЗО1 Iосн   ",//3
      "АМСЗ ДЗО 1      ",//4
      "ДЗО 1           ",//5
      "Пост приск.ДЗО2 ",//6
      "Приск ДЗО2 ВВO  ",//7
      "Блк ДЗО2 IOсн3Г ",//8
      "АМСЗ ДЗО2       ",//9
      "ДЗО2            ",//10
      "ДЗО2 прям       ",//11
      "ДЗО2 звор       ",//12
      "Пост приск ДЗО3 ",//13
      "Приск ДЗО3 ВВO  ",//14
      "Блк ДЗО3 IOсн3Г ",//15
      "АМСЗ ДЗО3       ",//16
      "ДЗО3 : Увімкн   ",//17
      "ДЗО3 прям       ",//18
      "ДЗО3 звор       ",//19
      "Блк ДЗО4 IOсн3Г ",//20
      "АМСЗ ДЗО4       ",//21
      "ДЗО4            ",//22
      "ДЗО4 прям       ",//23
      "ДЗО4 звор       ",//24
    },
    {
      "Неиспр.Напр.ДЗОE",//
      "Блк ДЗО1 Iосн 3E",//
      "Блк ДЗО1 Iосн  E",//
      "АМСЗ ДЗО 1     E",//
      "ДЗО 1          E",//
      "Пост ускор.ДЗО2E",//
      "Уск ДЗО2 от  ВВE",//
      "Блк ДЗО2 IOсн3ГE",//
      "АМТЗ ДЗО2      E",//
      "ДЗО 2          E",//
      "ДЗО2 прям      E",//
      "ДЗО2 обр       E",//
      "Пост уск.  ДЗО3E",//
      "Уск ДЗО3 от  ВВE",//
      "Блк ДЗО3 IOсн3ГE",//
      "АМСЗ ДЗО3      E",//
      "ДЗО3           E",//
      "ДЗО3 прям      E",//
      "ДЗО3 обр       E",//
      "Блк ДЗО4 IOсн3ГE",//
      "АМСЗ ДЗО4      E",//
      "ДЗО4           E",//
      "ДЗО4 прям      E",//
      "ДЗО4 обр       E",//
    },
    {
      "Неиспр.Напр.ДЗОK",//1
      "Блк ДЗО1 Iосн 3K",//2
      "Блк ДЗО1 Iосн  K",//3
      "АМСЗ ДЗО 1     K",//4
      "ДЗО 1          K",//5
      "Пост ускор.ДЗО2K",//6
      "Уск ДЗО2 от  ВВK",//7
      "Блк ДЗО2 IOсн3ГK",//8
      "АМТЗ ДЗО2      K",//9
      "ДЗО 2          K",//10
      "ДЗО2 прям      K",//11
      "ДЗО2 обр       K",//12
      "Пост уск.  ДЗО3K",//13
      "Уск ДЗО3 от  ВВK",//14
      "Блк ДЗО3 IOсн3ГK",//15
      "АМСЗ ДЗО3      K",//16
      "ДЗО3           K",//17
      "ДЗО3 прям      K",//18
      "ДЗО3 обр       K",//19
      "Блк ДЗО4 IOсн3ГK",//20
      "АМСЗ ДЗО4      K",//21
      "ДЗО4           K",//22
      "ДЗО4 прям      K",//23
      "ДЗО4 обр       K",//24
    }
  };
  int index_language = index_language_in_array(current_settings.language);
  
  unsigned int position_temp = current_ekran.index_position;
  unsigned int index_of_ekran;
  
  //Множення на два величини position_temp потрібне для того, бо на одну позицію ми використовуємо два рядки (назва + значення)
  index_of_ekran = ((position_temp<<1) >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;

  
  for (unsigned int i=0; i< MAX_ROW_LCD; i++)
  {
    unsigned int index_of_ekran_tmp = index_of_ekran >> 1;
    if (index_of_ekran_tmp < MAX_ROW_FOR_CONTROL_DZO)
    {
      if ((i & 0x1) == 0)
      {
        //У непарному номері рядку виводимо заголовок
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_language][index_of_ekran_tmp][j];
      }
      else
      {
        //У парному номері рядку виводимо значення уставки
        unsigned int index_ctr = index_of_ekran_tmp;

        unsigned int temp_data;
          
        if(current_ekran.edition == 0) temp_data = current_settings.control_dzo;
        else temp_data = edition_settings.control_dzo;
          
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = information_off_on[index_language][(temp_data >> index_ctr) & 0x1][j];
        if (position_temp == index_of_ekran_tmp) current_ekran.position_cursor_x = cursor_x_off_on[index_language][(temp_data >> index_ctr) & 0x1];
      }
    }
    else
      for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = ' ';

    index_of_ekran++;
  }

  //Відображення курору по вертикалі і курсор завжди має бути у полі із значенням устаки
  current_ekran.position_cursor_y = ((position_temp<<1) + 1) & (MAX_ROW_LCD - 1);
  //Курсор видимий
  current_ekran.cursor_on = 1;
  //Курсор не мигає
  if(current_ekran.edition == 0)current_ekran.cursor_blinking_on = 0;
  else current_ekran.cursor_blinking_on = 1;
  //Обновити повністю весь екран
  current_ekran.current_action = ACTION_WITH_CARRENT_EKRANE_FULL_UPDATE;
}

/*****************************************************/

/*****************************************************/
//
/*****************************************************/
/*****************************************************/
