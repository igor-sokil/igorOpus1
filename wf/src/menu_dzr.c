#include "header.h"


/*****************************************************/
//Формуємо екран відображення уставок ДЗP
/*****************************************************/
void make_ekran_setpoint_dzr(unsigned int group)
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_SETPOINT_DZR][MAX_COL_LCD] = 
  {
    {
      "Кблк ДЗР гололед",
      "  Уставка ДЗР1  ",
      "  Уставка AМТЗР1",
      "Устав. ДЗР1 Іблк", 
      "   Угол  ДЗР2   ",
      "  Прямая  ДЗР2  ",
      "  Обратная ДЗР2 ",
      "  Уставка AМТЗР2",
      "ДЗР3 в.г.сектора",
      "ДЗР3 н.г.сектора",
      "  Прямая  ДЗР3  ",
      "  Обратная ДЗР3 ",
      "  Уставка AМТЗР3",
    },
    {
      "К блк ДЗР ожел. ",
      "  Уставка ДЗР1  ",
      "  Уставка AМСЗР1",
      "Уст.   ДЗР1 Іблк",
      "   Кут  ДЗР2    ",
      "  Пряма  ДЗР2   ",
      "  Зворотня ДЗР2 ",
      "  Уставка AМСЗР2",
      "ДЗР3 в.м.сектора",
      "ДЗР3 н.м.сектора",
      "  Пряма  ДЗР3   ",
      "  Зворотня ДЗР3 ",
      "  Уставка AМСЗР3",
      
    },
    {
      "Eблк ДЗР гололед",
      "E Уставка ДЗр1  ",
      "E Уставка AМТЗр1",
      "Eстав. ДЗР1 Іблк", 
      "E  Угол  ДЗр2   ",
      "E Прямая  ДЗР2  ",
      "E Обратная ДЗР2 ",
      "E Уставка AМТЗР2",
      "EЗР3 в.г.сектора",
      "EЗР3 н.г.сектора",
      "E Прямая  ДЗР3  ",
      "E Обратная ДЗр3 ",
      "E Уставка AМТЗР3",

    },
    {
      "Кблк ДЗР гололед",
      "K Уставка ДЗР1  ",
      "K Уставка AМТЗР1",
      "Kстав. ДЗР1 Іблк", 
      "K  Угол  ДЗр2   ",
      "K Прямая  ДЗР2  ",
      "K Обратная ДЗР2 ",
      "K Уставка AМТЗР2",
      "KЗР3 в.г.сектора",
      "KЗР3 н.г.сектора",
      "K Прямая  ДЗР3  ",
      "K Обратная ДЗР3 ",
      "K Уставка AМТЗР3",
       
 
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
                            (index_of_ekran_tmp == INDEX_ML_STP_DZR3_ANGLE_H) && (position_temp == INDEX_ML_STP_DZR3_ANGLE_L) ||
                            (index_of_ekran_tmp == INDEX_ML_STP_DZR3_ANGLE_L) && (position_temp == INDEX_ML_STP_DZR3_ANGLE_H)
                           ) 
                         )   
                        );
    if (index_of_ekran_tmp < MAX_ROW_FOR_SETPOINT_DZR)//MAX_ROW_FOR_SETPOINT_DZ
    {
      if ((i & 0x1) == 0)
      {
        //У непарному номері рядку виводимо заголовок
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_language][index_of_ekran_tmp][j];
        if (index_of_ekran_tmp == INDEX_ML_STP_K_ICE_DZR)//INDEX_ML_STP_K_DZ
        {
          vaga = 1000; //максимальний ваговий коефіцієнт для вилілення старшого розряду
          if (view == true) value = current_settings.pickup_dzr_Io3g_Io1g[group]; //у змінну value поміщаємо значення уставки
          else value = edition_settings.pickup_dzr_Io3g_Io1g[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZR1)//INDEX_ML_STP_DZ1
        {
          vaga = 100000; //максимальний ваговий коефіцієнт для вилілення старшого розряду
          if (view == true) value = current_settings.pickup_dzr1[group]; //у змінну value поміщаємо значення уставки
          else value = edition_settings.pickup_dzr1[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZR1_AMTZ)//INDEX_ML_STP_DZ1_AMTZ
        {
          vaga = 100000; //максимальний ваговий коефіцієнт для вилілення старшого розряду
          if (view == true) value = current_settings.pickup_dzr1_amtz[group]; //у змінну value поміщаємо значення уставки
          else value = edition_settings.pickup_dzr1_amtz[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZR1_I_BLK)//INDEX_ML_STP_DZ2_ANGLE
        {
          vaga = 100000; //максимальний ваговий коефіцієнт для вилілення старшого розряду
          if (view == true) value = current_settings.pickup_dzr1_blkI[group]; //у змінну value поміщаємо значення уставки
          else value = edition_settings.pickup_dzr1_blkI[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZR2_ANGLE)//INDEX_ML_STP_DZ2_DIR
        {
          vaga = 10; //максимальний ваговий коефіцієнт для вилілення старшого розряду
          if (view == true) value = current_settings.pickup_dzr2_angle[group]; //у змінну value поміщаємо значення уставки
          else value = edition_settings.pickup_dzr2_angle[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZR2_DIR)//INDEX_ML_STP_DZ2_INV
        {
          vaga = 100000; //максимальний ваговий коефіцієнт для вилілення старшого розряду
          if (view == true) value = current_settings.pickup_dzr2_dir[group]; //у змінну value поміщаємо значення уставки
          else value = edition_settings.pickup_dzr2_dir[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZR2_INV)//INDEX_ML_STP_DZ2_AMTZ
        {
          vaga = 100000; //максимальний ваговий коефіцієнт для вилілення старшого розряду
          if (view == true) value = current_settings.pickup_dzr2_inv[group]; //у змінну value поміщаємо значення уставки
          else value = edition_settings.pickup_dzr2_inv[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZR2_AMTZ)//INDEX_ML_STP_DZ3_ANGLE
        {
          vaga = 100000; //максимальний ваговий коефіцієнт для вилілення старшого розряду
          if (view == true) value = current_settings.pickup_dzr2_amtz[group]; //у змінну value поміщаємо значення уставки
          else value = edition_settings.pickup_dzr2_amtz[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZR3_ANGLE_H)//INDEX_ML_STP_DZ3_DIR
        {
          vaga = 100; //максимальний ваговий коефіцієнт для вилілення старшого розряду
          if (view == true) value = current_settings.pickup_dzr3_angle_h[group]; //у змінну value поміщаємо значення уставки
          else value = edition_settings.pickup_dzr3_angle_h[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZR3_ANGLE_L)//INDEX_ML_STP_DZ3_INV
        {
          vaga = 100; //максимальний ваговий коефіцієнт для вилілення старшого розряду
          if (view == true) value = current_settings.pickup_dzr3_angle_l[group]; //у змінну value поміщаємо значення уставки
          else value = edition_settings.pickup_dzr3_angle_l[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZR3_DIR)//INDEX_ML_STP_DZ3_AMTZ
        {
          vaga = 100000; //максимальний ваговий коефіцієнт для вилілення старшого розряду
          if (view == true) value = current_settings.pickup_dzr3_dir[group]; //у змінну value поміщаємо значення уставки
          else value = edition_settings.pickup_dzr3_dir[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZR3_INV)//INDEX_ML_STP_DZ4_ANGLE
        {
          vaga = 100000; //максимальний ваговий коефіцієнт для вилілення старшого розряду
          if (view == true) value = current_settings.pickup_dzr3_inv[group]; //у змінну value поміщаємо значення уставки
          else value = edition_settings.pickup_dzr3_inv[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZR3_AMTZ)//INDEX_ML_STP_DZ4_DIR
        {
          vaga = 100000; //максимальний ваговий коефіцієнт для вилілення старшого розряду
          if (view == true) value = current_settings.pickup_dzr3_amtz[group]; //у змінну value поміщаємо значення уставки
          else value = edition_settings.pickup_dzr3_amtz[group];
        }
//        else if (index_of_ekran_tmp == INDEX_ML_STP_DZR4_Z0_DIR)//INDEX_ML_STP_DZ4_INV
//        {
//          vaga = 100000; //максимальний ваговий коефіцієнт для вилілення старшого розряду
//          if (view == true) value = current_settings.pickup_dzr4_Zo_dir[group]; //у змінну value поміщаємо значення уставки
//          else value = edition_settings.pickup_dzr4_Zo_dir[group];
//        }
//        else if (index_of_ekran_tmp == INDEX_ML_STP_DZR4_X0_DIR)//INDEX_ML_STP_DZ4_AMTZ
//        {
//          vaga = 100000; //максимальний ваговий коефіцієнт для вилілення старшого розряду
//          if (view == true) value = current_settings.pickup_dzr4_Xo_dir[group]; //у змінну value поміщаємо значення уставки
//          else value = edition_settings.pickup_dzr4_Xo_dir[group];
//        }
//        else if (index_of_ekran_tmp == INDEX_ML_STP_DZR4_Z0_INV)//INDEX_ML_STP_DZ4_AMTZ
//        {
//          vaga = 100000; //максимальний ваговий коефіцієнт для вилілення старшого розряду
//          if (view == true) value = current_settings.pickup_dzr4_Zo_inv[group]; //у змінну value поміщаємо значення уставки
//          else value = edition_settings.pickup_dzr4_Zo_inv[group];
//        }
//        else if (index_of_ekran_tmp == INDEX_ML_STP_DZR4_X0_INV)//INDEX_ML_STP_DZ4_AMTZ
//        {
//          vaga = 100000; //максимальний ваговий коефіцієнт для вилілення старшого розряду
//          if (view == true) value = current_settings.pickup_dzr4_Xo_inv[group]; //у змінну value поміщаємо значення уставки
//          else value = edition_settings.pickup_dzr4_Xo_inv[group];
//        }
//        else if (index_of_ekran_tmp == INDEX_ML_STP_DZR4_AMTZ)//INDEX_ML_STP_DZ4_AMTZ
//        {
//          vaga = 100000; //максимальний ваговий коефіцієнт для вилілення старшого розряду
//          if (view == true) value = current_settings.pickup_dzr4_amtz[group]; //у змінну value поміщаємо значення уставки
//          else value = edition_settings.pickup_dzr4_amtz[group];
//        }
        
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
          if (index_of_ekran_tmp == INDEX_ML_STP_K_ICE_DZR)//INDEX_ML_STP_K_DZ
          {
            if (
                ((j < COL_PICKUP_DZR_K_ICE_BEGIN) ||  (j > COL_PICKUP_DZR_K_ICE_END ))  &&
                (j != (COL_PICKUP_DZR_K_ICE_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZR_K_ICE_COMMA )working_ekran[i][j] = ',';
//            else if (j == (COL_PICKUP_DZ_K_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_A];
            else if (j == (COL_PICKUP_DZR_K_ICE_END + 2)) working_ekran[i][j] = ' ';
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZR_K_ICE_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZR1)//INDEX_ML_STP_DZ1
          {
            if (
                ((j < COL_PICKUP_DZR1_BEGIN) ||  (j > COL_PICKUP_DZR1_END ))  &&
                (j != (COL_PICKUP_DZR1_END + 2) && j != (COL_PICKUP_DZR1_END + 3))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZR1_COMMA )working_ekran[i][j] = ',';
            else if ((j >= (COL_PICKUP_DZ2_DIR_END + 2)) && (j <= (COL_PICKUP_DZ2_DIR_END + 2 + SIZE_R_DIMENSION - 1))) working_ekran[i][j] = resistance_dimension[index_language][j - (COL_PICKUP_DZ2_DIR_END + 2)];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZR1_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZR1_AMTZ)
          {
            if (
                ((j < COL_PICKUP_DZR1_AMTZ_BEGIN) ||  (j > COL_PICKUP_DZR1_AMTZ_END ))  &&
                (j != (COL_PICKUP_DZR1_AMTZ_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZR1_AMTZ_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_PICKUP_DZR1_AMTZ_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_A];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZR1_AMTZ_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZR1_I_BLK)
          {
            if (
                ((j < COL_PICKUP_DZR1_I_BLK_BEGIN) ||  (j > COL_PICKUP_DZR1_I_BLK_END ))  &&
                (j != (COL_PICKUP_DZR1_I_BLK_END + 2)) //&& j != (COL_PICKUP_DZR1_I_BLK_END + 3))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZR1_I_BLK_COMMA )working_ekran[i][j] = ',';
            else if ((j >= (COL_PICKUP_DZR1_I_BLK_END + 2)) && (j <= (COL_PICKUP_DZR1_I_BLK_END + 2 + SIZE_R_DIMENSION - 1))) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_A];//resistance_dimension[index_language][j - (COL_PICKUP_DZO1_I_BLK_END + 2)];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZR1_I_BLK_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZR2_ANGLE)
          {
            if(value&0x8000000)
            {
             working_ekran[i][COL_S_DZR2_ANGLE] = '-';//COL_SDZ2_ANGLE
            }
            else working_ekran[i][COL_S_DZR2_ANGLE] = '+';//COL_SDZ2_ANGLE
            if (
                ((j < COL_PICKUP_DZR2_ANGLE_BEGIN) ||  (j > COL_PICKUP_DZR2_ANGLE_END ))  &&
                (j != (COL_PICKUP_DZR2_ANGLE_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == (COL_PICKUP_DZR2_ANGLE_END + 2)) working_ekran[i][j] = '°';
            else
              calc_int_symbol_and_put_into_working_ekran((working_ekran[i] + j), &lValue, &vaga, &first_symbol, view);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZR2_DIR)
          {
            if (
                ((j < COL_PICKUP_DZR2_DIR_BEGIN) ||  (j > COL_PICKUP_DZR2_DIR_END ))  &&
                (j != (COL_PICKUP_DZR2_DIR_END + 2) && j != (COL_PICKUP_DZR2_DIR_END + 3))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZR2_DIR_COMMA )working_ekran[i][j] = ',';
            else if ((j >= (COL_PICKUP_DZR2_DIR_END + 2)) && (j <= (COL_PICKUP_DZR2_DIR_END + 2 + SIZE_R_DIMENSION - 1))) working_ekran[i][j] = resistance_dimension[index_language][j - (COL_PICKUP_DZR2_DIR_END + 2)];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZR2_DIR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZR2_INV)
          {
            if (
                ((j < COL_PICKUP_DZR2_INV_BEGIN) ||  (j > COL_PICKUP_DZR2_INV_END ))  &&
                (j != (COL_PICKUP_DZR2_INV_END + 2) && j != (COL_PICKUP_DZR2_INV_END + 3))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZR2_INV_COMMA )working_ekran[i][j] = ',';
            else if ((j >= (COL_PICKUP_DZR2_INV_END + 2)) && (j <= (COL_PICKUP_DZ2_DIR_END + 2 + SIZE_R_DIMENSION - 1))) working_ekran[i][j] = resistance_dimension[index_language][j - (COL_PICKUP_DZR2_INV_END + 2)];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZR2_INV_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZR2_AMTZ)
          {
            if (
                ((j < COL_PICKUP_DZR2_AMTZ_BEGIN) ||  (j > COL_PICKUP_DZR2_AMTZ_END ))  &&
                (j != (COL_PICKUP_DZR2_AMTZ_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZR2_AMTZ_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_PICKUP_DZR2_AMTZ_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_A];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZR2_AMTZ_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZR3_ANGLE_H)
          {
            if(value&0x8000000)
            {
             working_ekran[i][COL_DZR3_S_ANGLE_H] = '-';
            }
            else working_ekran[i][COL_DZR3_S_ANGLE_H] = '+';
            if (
                ((j < COL_PICKUP_DZR3_ANGLE_H_BEGIN) ||  (j > COL_PICKUP_DZR3_ANGLE_H_END ))  &&
                (j != (COL_PICKUP_DZR3_ANGLE_H_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == (COL_PICKUP_DZR3_ANGLE_H_END + 2)) working_ekran[i][j] = '°';
            else
            {
              calc_int_symbol_and_put_into_working_ekran((working_ekran[i] + j), &lValue, &vaga, &first_symbol, view);
            } 
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZR3_ANGLE_L)
          {
            if(value&0x8000000)
            {
             working_ekran[i][COL_DZR3_S_ANGLE_L] = '-';
            }
            else working_ekran[i][COL_DZR3_S_ANGLE_L] = '+';
            if (
                ((j < COL_PICKUP_DZR3_ANGLE_L_BEGIN) ||  (j > COL_PICKUP_DZR3_ANGLE_L_END ))  &&
                (j != (COL_PICKUP_DZR3_ANGLE_L_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == (COL_PICKUP_DZR3_ANGLE_L_END + 2)) working_ekran[i][j] = '°';
            else
            {
              calc_int_symbol_and_put_into_working_ekran((working_ekran[i] + j), &lValue, &vaga, &first_symbol, view);
            } 
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZR3_DIR)
          {
            if (
                ((j < COL_PICKUP_DZR3_DIR_BEGIN) ||  (j > COL_PICKUP_DZR3_DIR_END ))  &&
                (j != (COL_PICKUP_DZR3_DIR_END + 2) && j != (COL_PICKUP_DZR3_DIR_END + 3))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZR3_DIR_COMMA )working_ekran[i][j] = ',';
            else if ((j >= (COL_PICKUP_DZR3_DIR_END + 2)) && (j <= (COL_PICKUP_DZ2_DIR_END + 2 + SIZE_R_DIMENSION - 1))) working_ekran[i][j] = resistance_dimension[index_language][j - (COL_PICKUP_DZR3_DIR_END + 2)];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZR3_DIR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZR3_INV)
          {
            if (
                ((j < COL_PICKUP_DZR3_INV_BEGIN) ||  (j > COL_PICKUP_DZR3_INV_END ))  &&
                (j != (COL_PICKUP_DZR3_INV_END + 2) && j != (COL_PICKUP_DZR3_INV_END + 3))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZR3_INV_COMMA )working_ekran[i][j] = ',';
            else if ((j >= (COL_PICKUP_DZR3_INV_END + 2)) && (j <= (COL_PICKUP_DZ2_DIR_END + 2 + SIZE_R_DIMENSION - 1))) working_ekran[i][j] = resistance_dimension[index_language][j - (COL_PICKUP_DZR3_INV_END + 2)];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZR3_INV_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZR3_AMTZ)
          {
            if (
                ((j < COL_PICKUP_DZR3_AMTZ_BEGIN) ||  (j > COL_PICKUP_DZR3_AMTZ_END ))  &&
                (j != (COL_PICKUP_DZR3_AMTZ_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZR3_AMTZ_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_PICKUP_DZR3_AMTZ_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_A];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZR3_AMTZ_COMMA, view, 0);
          }
//          else if (index_of_ekran_tmp == INDEX_ML_STP_DZR4_Z0_DIR)
//          {
//            if (
//                ((j < COL_PICKUP_DZR4_Z0_DIR_BEGIN) ||  (j > COL_PICKUP_DZR4_Z0_DIR_END ))  &&
//                (j != (COL_PICKUP_DZR4_Z0_DIR_END + 2) && j != (COL_PICKUP_DZR4_Z0_DIR_END + 3))  
//               )working_ekran[i][j] = ' ';
//            else if (j == COL_PICKUP_DZR4_Z0_DIR_COMMA )working_ekran[i][j] = ',';
//            else if ((j >= (COL_PICKUP_DZR4_Z0_DIR_END + 2)) && (j <= (COL_PICKUP_DZ2_DIR_END + 2 + SIZE_R_DIMENSION - 1))) working_ekran[i][j] = resistance_dimension[index_language][j - (COL_PICKUP_DZR4_Z0_DIR_END + 2)];
//            else
//              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZR4_Z0_DIR_COMMA, view, 0);
//          }
//          else if (index_of_ekran_tmp == INDEX_ML_STP_DZR4_X0_DIR)
//          {
//            if (
//                ((j < COL_PICKUP_DZR4_X0_DIR_BEGIN) ||  (j > COL_PICKUP_DZR4_X0_DIR_END ))  &&
//                (j != (COL_PICKUP_DZR4_X0_DIR_END + 2) && j != (COL_PICKUP_DZR4_X0_DIR_END + 3))  
//               )working_ekran[i][j] = ' ';
//            else if (j == COL_PICKUP_DZR4_X0_DIR_COMMA  )working_ekran[i][j] = ',';
//            else if ((j >= (COL_PICKUP_DZR4_X0_DIR_END + 2)) && (j <= (COL_PICKUP_DZ2_DIR_END + 2 + SIZE_R_DIMENSION - 1))) working_ekran[i][j] = resistance_dimension[index_language][j - (COL_PICKUP_DZR4_X0_DIR_END + 2)];
//            else
//              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZR4_X0_DIR_COMMA , view, 0);
//          }
//          else if (index_of_ekran_tmp == INDEX_ML_STP_DZR4_Z0_INV)
//          {
//            if (
//                ((j < COL_PICKUP_DZR4_Z0_INV_BEGIN) ||  (j > COL_PICKUP_DZR4_Z0_INV_END ))  &&
//                (j != (COL_PICKUP_DZR4_Z0_INV_END + 2) && j != (COL_PICKUP_DZR4_Z0_INV_END + 3))  
//               )working_ekran[i][j] = ' ';
//            else if (j == COL_PICKUP_DZR4_Z0_INV_COMMA )working_ekran[i][j] = ',';
//            else if ((j >= (COL_PICKUP_DZR4_Z0_INV_END + 2)) && (j <= (COL_PICKUP_DZ2_DIR_END + 2 + SIZE_R_DIMENSION - 1))) working_ekran[i][j] = resistance_dimension[index_language][j - (COL_PICKUP_DZR4_Z0_INV_END + 2)];
//            else
//              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZR4_Z0_INV_COMMA, view, 0);
//          }
//          else if (index_of_ekran_tmp == INDEX_ML_STP_DZR4_X0_INV)
//          {
//            if (
//                ((j < COL_PICKUP_DZR4_X0_INV_BEGIN) ||  (j > COL_PICKUP_DZR4_X0_INV_END ))  &&
//                (j != (COL_PICKUP_DZR4_X0_INV_END + 2) && j != (COL_PICKUP_DZR4_X0_INV_END + 3))  
//               )working_ekran[i][j] = ' ';
//            else if (j == COL_PICKUP_DZR4_X0_INV_COMMA )working_ekran[i][j] = ',';
//            else if ((j >= (COL_PICKUP_DZR4_X0_INV_END + 2)) && (j <= (COL_PICKUP_DZ2_DIR_END + 2 + SIZE_R_DIMENSION - 1))) working_ekran[i][j] = resistance_dimension[index_language][j - (COL_PICKUP_DZR4_X0_INV_END + 2)];
//            else
//              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZR4_X0_INV_COMMA, view, 0);
//          }
//          else if (index_of_ekran_tmp == INDEX_ML_STP_DZR4_AMTZ)
//          {
//            if (
//                ((j < COL_PICKUP_DZR4_AMTZ_BEGIN) ||  (j > COL_PICKUP_DZR4_AMTZ_END ))  &&
//                (j != (COL_PICKUP_DZR4_AMTZ_END + 2))  
//               )working_ekran[i][j] = ' ';
//            else if (j == COL_PICKUP_DZR4_AMTZ_COMMA )working_ekran[i][j] = ',';
//            else if (j == (COL_PICKUP_DZR4_AMTZ_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_A];
//            else
//              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZR4_AMTZ_COMMA, view, 0);
//          }

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
    if (current_ekran.index_position == INDEX_ML_STP_K_ICE_DZR)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZR_K_ICE_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZR_K_ICE_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZR1)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZR1_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZR1_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZR1_AMTZ)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZR1_AMTZ_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZR1_AMTZ_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZR1_I_BLK)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZR1_I_BLK_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZR1_I_BLK_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZR2_ANGLE)
    {
      current_ekran.position_cursor_x = COL_S_DZR2_ANGLE;//COL_PICKUP_DZ2_ANGLE_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZR2_ANGLE_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZR2_DIR)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZR2_DIR_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZR2_DIR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZR2_INV)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZR2_DIR_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZR2_DIR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZR2_AMTZ)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZR2_AMTZ_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZR2_AMTZ_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZR3_ANGLE_H)
    {
      current_ekran.position_cursor_x = COL_DZR3_S_ANGLE_H;//COL_PICKUP_DZ3_ANGLE_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZR3_ANGLE_H_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZR3_ANGLE_L)
    {
      current_ekran.position_cursor_x = COL_DZR3_S_ANGLE_L;//COL_PICKUP_DZ3_ANGLE_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZR3_ANGLE_L_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZR3_DIR)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZ3_DIR_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZ3_DIR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZR3_INV)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZR3_INV_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZR3_INV_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZR3_AMTZ)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZR3_AMTZ_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZR3_AMTZ_END;
    }
//    else if (current_ekran.index_position == INDEX_ML_STP_DZR4_Z0_DIR)
//    {
//      current_ekran.position_cursor_x = COL_PICKUP_DZR4_Z0_DIR_BEGIN;
//      last_position_cursor_x = COL_PICKUP_DZR4_Z0_DIR_END;
//    }
//    else if (current_ekran.index_position == INDEX_ML_STP_DZR4_X0_DIR)
//    {
//      current_ekran.position_cursor_x = COL_PICKUP_DZR4_X0_DIR_BEGIN;
//      last_position_cursor_x = COL_PICKUP_DZR4_X0_DIR_END;
//    }
//    else if (current_ekran.index_position == INDEX_ML_STP_DZR4_Z0_INV)
//    {
//      current_ekran.position_cursor_x = COL_PICKUP_DZR4_Z0_INV_BEGIN;
//      last_position_cursor_x = COL_PICKUP_DZR4_Z0_INV_END;
//    }
//    else if (current_ekran.index_position == INDEX_ML_STP_DZR4_X0_INV)
//    {
//      current_ekran.position_cursor_x = COL_PICKUP_DZR4_X0_INV_BEGIN;
//      last_position_cursor_x = COL_PICKUP_DZR4_X0_INV_END;
//    }
//    else if (current_ekran.index_position == INDEX_ML_STP_DZ4_AMTZ)
//    {
//      current_ekran.position_cursor_x = COL_PICKUP_DZR4_ANGLE_BEGIN;
//      last_position_cursor_x = COL_PICKUP_DZR4_ANGLE_END;
//    }
    
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
//Формуємо екран відображення витримок ДЗP
/*****************************************************/
void make_ekran_timeout_dzr(unsigned int group)
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_TIMEOUT_DZR][MAX_COL_LCD] = 
  {
    {
      "  Выдержка ДЗР1 ",
      " Выдержка AМТЗР1",
      "Выдержка ДЗР2ПРМ",
      "  Ускор ДЗР2 ПРМ",
      "Выдержка ДЗР2ОБР",
      "  Ускор ДЗР2 ОБР",
      " Выдержка AМТЗР2",
      "   Ускор AМТЗР2 ",
      "Ввод ускор ДЗР2 ",
      "Ввод ускр AМТЗР2",
      "Выдержка ДЗР3ПРМ",
      "  Ускор ДЗР3 ПРМ",
      "Выдержка ДЗР3ОБР",
      "  Ускор ДЗР3 ОБР",
      " Выдержка AМТЗР3",
      "   Ускор AМТЗР3 ",
      "Ввод ускор ДЗР3 ",
      "Ввод ускр AМТЗР3",
//      "Выдержка ДЗР4ПРМ",
//      "Выдержка ДЗР4ОБР",
//      " Выдержка AМТЗР4",
      "Выдержка ДЗР НЦН",
    },
    {
      " Витримка ДЗР1  ",
      " Витримка AМСЗР1",
      "Витримка ДЗР2ПРМ",
      " Прискор ДЗР2ПРМ",
      "Витримка ДЗР2ЗВР",
      " Прискор ДЗР2ЗВР",
      " Витримка AМСЗР2",
      " Прискор AМСЗР2 ",
      " Ввод приск ДЗР2",
      "Ввд приск AМСЗР2",
      "Витримка ДЗР3ПРМ",
      " Прискор ДЗР3ПРМ",
      "Витримка ДЗР3ЗВР",
      " Прискор ДЗР3ЗВР",
      " Витримка AМСЗР3",
      " Прискор AМСЗР3 ",
      " Ввод приск ДЗР3",
      "Ввод прск AМСЗР3",
//      "Витримка ДЗР4ПРМ",
//      "Витримка ДЗР4ЗВР",
//      " Витримка AМСЗР4",
      " Витр. ДЗР НКН  ",
    },
    {
      "E  Выдержка ДЗР1",
      "EВыдержка AМТЗР1",
      "Eыдержка ДЗР2ПРМ",
      "E Ускор ДЗР2 ПРМ",
      "Eыдержка ДЗР2ОБР",
      "E Ускор ДЗР2 ОБР",
      "EВыдержка AМТЗР2",
      "E  Ускор AМТЗР2 ",
      "Eвод ускор ДЗР2 ",
      "Eвод ускр AМТЗР2",
      "Eыдержка ДЗР3ПРМ",
      "E Ускор ДЗР3 ПРМ",
      "Eыдержка ДЗР3ОБР",
      "E Ускор ДЗР3 ОБР",
      "EВыдержка AМТЗР3",
      "E  Ускор AМТЗР3 ",
      "Eвод ускор ДЗР3 ",
      "Eвод ускр AМТЗР3",
//      "Eыдержка ДЗР4ПРМ",
//      "Eыдержка ДЗР4ОБР",
//      "EВыдержка AМТЗР4",
      "Eыдержка ДЗР НЦН",
    },
    {
      "K Выдержка ДЗР1 ",
      "KВыдержка AМТЗР1",
      "Kыдержка ДЗР2ПРМ",
      "K Ускор ДЗР2 ПРМ",
      "Kыдержка ДЗР2ОБР",
      "K Ускор ДЗР2 ОБР",
      "KВыдержка AМТЗР2",
      "K  Ускор AМТЗР2 ",
      "Kвод ускор ДЗР2 ",
      "Kвод ускр AМТЗР2",
      "Kыдержка ДЗР3ПРМ",
      "K Ускор ДЗР3 ПРМ",
      "Kыдержка ДЗР3ОБР",
      "K Ускор ДЗР3 ОБР",
      "KВыдержка AМТЗР3",
      "K  Ускор AМТЗР3 ",
      "Kвод ускор ДЗР3 ",
      "Kвод ускр AМТЗР3",
//      "Kыдержка ДЗР4ПРМ",
//      "Kыдержка ДЗР4ОБР",
//      "KВыдержка AМТЗР4",
      "Kыдержка ДЗР НЦН",
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
    if (index_of_ekran_tmp < MAX_ROW_FOR_TIMEOUT_DZR)
    {
      if ((i & 0x1) == 0)
      {
        //У непарному номері рядку виводимо заголовок
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_language][index_of_ekran_tmp][j];

        if (index_of_ekran_tmp == INDEX_ML_TMO_DZR1)
        {
          vaga = 10000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
          if (view == true) value = current_settings.timeout_dzr1[group]; //у змінну value поміщаємо значення витримки
          else value = edition_settings.timeout_dzr1[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZR1_AMTZ)
        {
          vaga = 10000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
          if (view == true) value = current_settings.timeout_dzr1_amtz[group]; //у змінну value поміщаємо значення витримки
          else value = edition_settings.timeout_dzr1_amtz[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZR2_DIR)
        {
          vaga = 10000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
          if (view == true) value = current_settings.timeout_dzr2_dir[group]; //у змінну value поміщаємо значення витримки
          else value = edition_settings.timeout_dzr2_dir[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZR2_DIR_PR)
        {
          vaga = 1000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
          if (view == true) value = current_settings.timeout_dzr2_dir_pr[group]; //у змінну value поміщаємо значення витримки
          else value = edition_settings.timeout_dzr2_dir_pr[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZR2_INV)
        {
          vaga = 10000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
          if (view == true) value = current_settings.timeout_dzr2_inv[group]; //у змінну value поміщаємо значення витримки
          else value = edition_settings.timeout_dzr2_inv[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZR2_INV_PR)
        {
          vaga = 1000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
          if (view == true) value = current_settings.timeout_dzr2_inv_pr[group]; //у змінну value поміщаємо значення витримки
          else value = edition_settings.timeout_dzr2_inv_pr[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZR2_AMTZ)
        {
          vaga = 10000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
          if (view == true) value = current_settings.timeout_dzr2_amtz[group]; //у змінну value поміщаємо значення витримки
          else value = edition_settings.timeout_dzr2_amtz[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZR2_AMTZ_PR)
        {
          vaga = 1000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
          if (view == true) value = current_settings.timeout_dzr2_amtz_pr[group]; //у змінну value поміщаємо значення витримки
          else value = edition_settings.timeout_dzr2_amtz_pr[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZR2_VVID_PR)
        {
          vaga = 1000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
          if (view == true) value = current_settings.timeout_dzr2_vvid_pr[group]; //у змінну value поміщаємо значення витримки
          else value = edition_settings.timeout_dzr2_vvid_pr[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZR2_AMTZ_VVID_PR)
        {
          vaga = 1000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
          if (view == true) value = current_settings.timeout_dzr2_amtz_vvid_pr[group]; //у змінну value поміщаємо значення витримки
          else value = edition_settings.timeout_dzr2_amtz_vvid_pr[group];
        }

        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZR3_DIR)
        {
          vaga = 10000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
          if (view == true) value = current_settings.timeout_dzr3_dir[group]; //у змінну value поміщаємо значення витримки
          else value = edition_settings.timeout_dzr3_dir[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZR3_DIR_PR)
        {
          vaga = 1000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
          if (view == true) value = current_settings.timeout_dzr3_dir_pr[group]; //у змінну value поміщаємо значення витримки
          else value = edition_settings.timeout_dzr3_dir_pr[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZR3_INV)
        {
          vaga = 10000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
          if (view == true) value = current_settings.timeout_dzr3_inv[group]; //у змінну value поміщаємо значення витримки
          else value = edition_settings.timeout_dzr3_inv[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZR3_INV_PR)
        {
          vaga = 1000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
          if (view == true) value = current_settings.timeout_dzr3_inv_pr[group]; //у змінну value поміщаємо значення витримки
          else value = edition_settings.timeout_dzr3_inv_pr[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZR3_AMTZ)
        {
          vaga = 10000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
          if (view == true) value = current_settings.timeout_dzr3_amtz[group]; //у змінну value поміщаємо значення витримки
          else value = edition_settings.timeout_dzr3_amtz[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZR3_AMTZ_PR)
        {
          vaga = 1000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
          if (view == true) value = current_settings.timeout_dzr3_amtz_pr[group]; //у змінну value поміщаємо значення витримки
          else value = edition_settings.timeout_dzr3_amtz_pr[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZR3_VVID_PR)
        {
          vaga = 1000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
          if (view == true) value = current_settings.timeout_dzr3_vvid_pr[group]; //у змінну value поміщаємо значення витримки
          else value = edition_settings.timeout_dzr3_vvid_pr[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZR3_AMTZ_VVID_PR)
        {
          vaga = 1000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
          if (view == true) value = current_settings.timeout_dzr3_amtz_vvid_pr[group]; //у змінну value поміщаємо значення витримки
          else value = edition_settings.timeout_dzr3_amtz_vvid_pr[group];
        }

        //else if (index_of_ekran_tmp == INDEX_ML_TMO_DZR4_DIR)
        //{
        //  vaga = 10000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
        //  if (view == true) value = current_settings.timeout_dzr4_dir[group]; //у змінну value поміщаємо значення витримки
        //  else value = edition_settings.timeout_dzr4_dir[group];
        //}
        //else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ4_DIR_PR)
        //{
        //  vaga = 1000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
        //  if (view == true) value = current_settings.timeout_dz4_dir_pr[group]; //у змінну value поміщаємо значення витримки
        //  else value = edition_settings.timeout_dz4_dir_pr[group];
        //}
        //else if (index_of_ekran_tmp == INDEX_ML_TMO_DZR4_INV)
        //{
        //  vaga = 10000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
        //  if (view == true) value = current_settings.timeout_dzr4_inv[group]; //у змінну value поміщаємо значення витримки
        //  else value = edition_settings.timeout_dzr4_inv[group];
        //}
        //else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ4_INV_PR)
        //{
        //  vaga = 1000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
        //  if (view == true) value = current_settings.timeout_dz4_inv_pr[group]; //у змінну value поміщаємо значення витримки
        //  else value = edition_settings.timeout_dz4_inv_pr[group];
        //}
        //else if (index_of_ekran_tmp == INDEX_ML_TMO_DZR4_AMTZ)
        //{
        //  vaga = 10000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
        //  if (view == true) value = current_settings.timeout_dzr4_amtz[group]; //у змінну value поміщаємо значення витримки
        //  else value = edition_settings.timeout_dzr4_amtz[group];
        //}
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
        else if (index_of_ekran_tmp == INDEX_ML_TMO_NKN_DZR)
        {
          vaga = 1000; //максимальний ваговий коефіцієнт для вилілення старшого розряду для витримки
          if (view == true) value = current_settings.timeout_nkn_dzr[group]; //у змінну value поміщаємо значення витримки
          else value = edition_settings.timeout_nkn_dzr[group];
        }

        first_symbol = 0; //помічаємо, що ще ніодин значущий символ не виведений
      }
      else
      {
        //У парному номері рядку виводимо значення уставки
        for (unsigned int j = 0; j<MAX_COL_LCD; j++)
        {
          if (index_of_ekran_tmp == INDEX_ML_TMO_DZR1)
          {
            if (
                ((j < COL_TMO_DZR1_BEGIN) ||  (j > COL_TMO_DZR1_END )) &&
                (j != (COL_TMO_DZR1_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZR1_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZR1_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZR1_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZR1_AMTZ)
          {
            if (
                ((j < COL_TMO_DZR1_AMTZ_BEGIN) ||  (j > COL_TMO_DZR1_AMTZ_END )) &&
                (j != (COL_TMO_DZR1_AMTZ_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZR1_AMTZ_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZR1_AMTZ_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZR1_AMTZ_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZR2_DIR)
          {
            if (
                ((j < COL_TMO_DZR2_DIR_BEGIN) ||  (j > COL_TMO_DZR2_DIR_END )) &&
                (j != (COL_TMO_DZR2_DIR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZR2_DIR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZR2_DIR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZR2_DIR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZR2_DIR_PR)
          {
            if (
                ((j < COL_TMO_DZR2_DIR_PR_BEGIN) ||  (j > COL_TMO_DZR2_DIR_PR_END )) &&
                (j != (COL_TMO_DZR2_DIR_PR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZR2_DIR_PR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZR2_DIR_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZR2_DIR_PR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZR2_INV)
          {
            if (
                ((j < COL_TMO_DZR2_INV_BEGIN) ||  (j > COL_TMO_DZR2_INV_END )) &&
                (j != (COL_TMO_DZR2_INV_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZR2_INV_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZR2_INV_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZR2_INV_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZR2_INV_PR)
          {
            if (
                ((j < COL_TMO_DZR2_INV_PR_BEGIN) ||  (j > COL_TMO_DZR2_INV_PR_END )) &&
                (j != (COL_TMO_DZR2_INV_PR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZR2_INV_PR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZR2_INV_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZR2_INV_PR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZR2_AMTZ)
          {
            if (
                ((j < COL_TMO_DZR2_AMTZ_BEGIN) ||  (j > COL_TMO_DZR2_AMTZ_END )) &&
                (j != (COL_TMO_DZR2_AMTZ_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZR2_AMTZ_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZR2_AMTZ_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZR2_AMTZ_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZR2_AMTZ_PR)
          {
            if (
                ((j < COL_TMO_DZR2_AMTZ_PR_BEGIN) ||  (j > COL_TMO_DZR2_AMTZ_PR_END )) &&
                (j != (COL_TMO_DZR2_AMTZ_PR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZR2_AMTZ_PR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZR2_AMTZ_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZR2_AMTZ_PR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZR2_VVID_PR)
          {
            if (
                ((j < COL_TMO_DZR2_VVID_PR_BEGIN) ||  (j > COL_TMO_DZR2_VVID_PR_END )) &&
                (j != (COL_TMO_DZR2_VVID_PR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZR2_VVID_PR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZR2_VVID_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZR2_VVID_PR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZR2_AMTZ_VVID_PR)
          {
            if (
                ((j < COL_TMO_DZR2_AMTZ_VVID_PR_BEGIN) ||  (j > COL_TMO_DZR2_AMTZ_VVID_PR_END )) &&
                (j != (COL_TMO_DZR2_AMTZ_VVID_PR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZR2_AMTZ_VVID_PR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZR2_AMTZ_VVID_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZR2_AMTZ_VVID_PR_COMMA, view, 0);
          }


          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZR3_DIR)
          {
            if (
                ((j < COL_TMO_DZR3_DIR_BEGIN) ||  (j > COL_TMO_DZR3_DIR_END )) &&
                (j != (COL_TMO_DZR3_DIR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZR3_DIR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZR3_DIR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZR3_DIR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZR3_DIR_PR)
          {
            if (
                ((j < COL_TMO_DZR3_DIR_PR_BEGIN) ||  (j > COL_TMO_DZR3_DIR_PR_END )) &&
                (j != (COL_TMO_DZR3_DIR_PR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZR3_DIR_PR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZR3_DIR_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZR3_DIR_PR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZR3_INV)
          {
            if (
                ((j < COL_TMO_DZR3_INV_BEGIN) ||  (j > COL_TMO_DZR3_INV_END )) &&
                (j != (COL_TMO_DZR3_INV_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZR3_INV_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZR3_INV_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZR3_INV_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ3_INV_PR)
          {
            if (
                ((j < COL_TMO_DZR3_INV_PR_BEGIN) ||  (j > COL_TMO_DZR3_INV_PR_END )) &&
                (j != (COL_TMO_DZR3_INV_PR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZR3_INV_PR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZR3_INV_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZR3_INV_PR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZR3_AMTZ)
          {
            if (
                ((j < COL_TMO_DZR3_AMTZ_BEGIN) ||  (j > COL_TMO_DZR3_AMTZ_END )) &&
                (j != (COL_TMO_DZR3_AMTZ_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZR3_AMTZ_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZR3_AMTZ_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZR3_AMTZ_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZR3_AMTZ_PR)
          {
            if (
                ((j < COL_TMO_DZR3_AMTZ_PR_BEGIN) ||  (j > COL_TMO_DZR3_AMTZ_PR_END )) &&
                (j != (COL_TMO_DZR3_AMTZ_PR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZR3_AMTZ_PR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZR3_AMTZ_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZR3_AMTZ_PR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZR3_VVID_PR)
          {
            if (
                ((j < COL_TMO_DZR3_VVID_PR_BEGIN) ||  (j > COL_TMO_DZR3_VVID_PR_END )) &&
                (j != (COL_TMO_DZR3_VVID_PR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZR3_VVID_PR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZR3_VVID_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZR3_VVID_PR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZR3_AMTZ_VVID_PR)
          {
            if (
                ((j < COL_TMO_DZR3_AMTZ_VVID_PR_BEGIN) ||  (j > COL_TMO_DZR3_AMTZ_VVID_PR_END )) &&
                (j != (COL_TMO_DZR3_AMTZ_VVID_PR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZR3_AMTZ_VVID_PR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZR3_AMTZ_VVID_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZR3_AMTZ_VVID_PR_COMMA, view, 0);
          }


          //else if (index_of_ekran_tmp == INDEX_ML_TMO_DZR4_DIR)
          //{
          //  if (
          //      ((j < COL_TMO_DZR4_DIR_BEGIN) ||  (j > COL_TMO_DZR4_DIR_END )) &&
          //      (j != (COL_TMO_DZR4_DIR_END + 2))  
          //     )working_ekran[i][j] = ' ';
          //  else if (j == COL_TMO_DZR4_DIR_COMMA )working_ekran[i][j] = ',';
          //  else if (j == (COL_TMO_DZR4_DIR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
          //  else
          //    calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZR4_DIR_COMMA, view, 0);
          //}
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
          //else if (index_of_ekran_tmp == INDEX_ML_TMO_DZR4_INV)
          //{
          //  if (
          //      ((j < COL_TMO_DZR4_INV_BEGIN) ||  (j > COL_TMO_DZR4_INV_END )) &&
          //      (j != (COL_TMO_DZR4_INV_END + 2))  
          //     )working_ekran[i][j] = ' ';
          //  else if (j == COL_TMO_DZR4_INV_COMMA )working_ekran[i][j] = ',';
          //  else if (j == (COL_TMO_DZR4_INV_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
          //  else
          //    calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZR4_INV_COMMA, view, 0);
          //}
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
          //else if (index_of_ekran_tmp == INDEX_ML_TMO_DZR4_AMTZ)
          //{
          //  if (
          //      ((j < COL_TMO_DZR4_AMTZ_BEGIN) ||  (j > COL_TMO_DZR4_AMTZ_END )) &&
          //      (j != (COL_TMO_DZR4_AMTZ_END + 2))  
          //     )working_ekran[i][j] = ' ';
          //  else if (j == COL_TMO_DZR4_AMTZ_COMMA )working_ekran[i][j] = ',';
          //  else if (j == (COL_TMO_DZR4_AMTZ_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
          //  else
          //    calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZR4_AMTZ_COMMA, view, 0);
          //}
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

          else if (index_of_ekran_tmp == INDEX_ML_TMO_NKN_DZR)
          {
            if (
                ((j < COL_TMO_NKN_DZR_BEGIN) ||  (j > COL_TMO_NKN_DZR_END )) &&
                (j != (COL_TMO_NKN_DZR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_NKN_DZR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_NKN_DZR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_NKN_DZR_COMMA, view, 0);
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
    if (current_ekran.index_position == INDEX_ML_TMO_DZR1) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZR1_BEGIN;
      last_position_cursor_x = COL_TMO_DZR1_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZR1_AMTZ) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZR1_AMTZ_BEGIN;
      last_position_cursor_x = COL_TMO_DZR1_AMTZ_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZR2_DIR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZR2_DIR_BEGIN;
      last_position_cursor_x = COL_TMO_DZR2_DIR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZR2_DIR_PR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZR2_DIR_PR_BEGIN;
      last_position_cursor_x = COL_TMO_DZR2_DIR_PR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZR2_INV) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZR2_INV_BEGIN;
      last_position_cursor_x = COL_TMO_DZR2_INV_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZR2_INV_PR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZR2_INV_PR_BEGIN;
      last_position_cursor_x = COL_TMO_DZR2_INV_PR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZR2_AMTZ) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZR2_AMTZ_BEGIN;
      last_position_cursor_x = COL_TMO_DZR2_AMTZ_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZR2_AMTZ_PR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZR2_AMTZ_PR_BEGIN;
      last_position_cursor_x = COL_TMO_DZR2_AMTZ_PR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZR2_VVID_PR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZR2_VVID_PR_BEGIN;
      last_position_cursor_x = COL_TMO_DZR2_VVID_PR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZR2_AMTZ_VVID_PR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZR2_AMTZ_VVID_PR_BEGIN;
      last_position_cursor_x = COL_TMO_DZ2_AMTZ_VVID_PR_END;
    }

    else if (current_ekran.index_position == INDEX_ML_TMO_DZR3_DIR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZR3_DIR_BEGIN;
      last_position_cursor_x = COL_TMO_DZR3_DIR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZR3_DIR_PR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZR3_DIR_PR_BEGIN;
      last_position_cursor_x = COL_TMO_DZR3_DIR_PR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZR3_INV) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZR3_INV_BEGIN;
      last_position_cursor_x = COL_TMO_DZR3_INV_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZ3_INV_PR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZR3_INV_PR_BEGIN;
      last_position_cursor_x = COL_TMO_DZR3_INV_PR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZR3_AMTZ) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZR3_AMTZ_BEGIN;
      last_position_cursor_x = COL_TMO_DZR3_AMTZ_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZR3_AMTZ_PR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZR3_AMTZ_PR_BEGIN;
      last_position_cursor_x = COL_TMO_DZR3_AMTZ_PR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZR3_VVID_PR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZR3_VVID_PR_BEGIN;
      last_position_cursor_x = COL_TMO_DZR3_VVID_PR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZR3_AMTZ_VVID_PR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZR3_AMTZ_VVID_PR_BEGIN;
      last_position_cursor_x = COL_TMO_DZR3_AMTZ_VVID_PR_END;
    }

    //else if (current_ekran.index_position == INDEX_ML_TMO_DZR4_DIR) 
    //{
    //  current_ekran.position_cursor_x = COL_TMO_DZR4_DIR_BEGIN;
    //  last_position_cursor_x = COL_TMO_DZR4_DIR_END;
    //}
    //else if (current_ekran.index_position == INDEX_ML_TMO_DZ4_DIR_PR) 
    //{
    //  current_ekran.position_cursor_x = COL_TMO_DZ4_DIR_PR_BEGIN;
    //  last_position_cursor_x = COL_TMO_DZ4_DIR_PR_END;
    //}
    //else if (current_ekran.index_position == INDEX_ML_TMO_DZR4_INV) 
    //{
    //  current_ekran.position_cursor_x = COL_TMO_DZR4_INV_BEGIN;
    //  last_position_cursor_x = COL_TMO_DZR4_INV_END;
    //}
    //else if (current_ekran.index_position == INDEX_ML_TMO_DZ4_INV_PR) 
    //{
    //  current_ekran.position_cursor_x = COL_TMO_DZ4_INV_PR_BEGIN;
    //  last_position_cursor_x = COL_TMO_DZ4_INV_PR_END;
    //}
    //else if (current_ekran.index_position == INDEX_ML_TMO_DZR4_AMTZ) 
    //{
    //  current_ekran.position_cursor_x = COL_TMO_DZR4_AMTZ_BEGIN;
    //  last_position_cursor_x = COL_TMO_DZR4_AMTZ_END;
    //}
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

    else if (current_ekran.index_position == INDEX_ML_TMO_NKN_DZR) 
    {
      current_ekran.position_cursor_x = COL_TMO_NKN_DZR_BEGIN;
      last_position_cursor_x = COL_TMO_NKN_DZR_END;
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
//Формуємо екран відображення значення управлінської інформації для DZR
/*****************************************************/
void make_ekran_control_dzr(void)
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_CONTROL_DZR][MAX_COL_LCD] = 
  {
    {
      "Неиспр.Напр.ДЗР ",//1
      "Блк ДЗР1 Iрез 3Г",//2
      "Блк ДЗР1 Iрез   ",//3
      "АМТЗ ДЗР 1      ",//4
      "ДЗР 1           ",//5
      "Пост ускор.ДЗР2 ",//6
      "Уск ДЗР2 от  ВВР",//7
      "Блк ДЗР2 Iрез 3Г",//8
      "АМТЗ ДЗР2       ",//9
      "ДЗР 2           ",//10
      "ДЗР2 прям       ",//11
      "ДЗР2 обр        ",//12
      "Пост уск.  ДЗР3 ",//13
      "Уск ДЗР3 от  ВВР",//14
      "Блк ДЗР3 Iрез 3Г",//15
      "АМТЗ ДЗР3       ",//16
      "ДЗР3            ",//17
      "ДЗР3 прям       ",//18
      "ДЗР3 обр        ",//19

    },
    {
      "Неспр.Напр.ДЗР  ",//1
      "Блк ДЗР1 Iрез 3Г",//2
      "Блк ДЗР1 Iрез   ",//3
      "АМСЗ ДЗР 1      ",//4
	  "ДЗР 1           ",//5
      "Пост приск.ДЗр2 ",//6
      "Приск ДЗР2 ВВР  ",//7
      "Блк ДЗР2 Iрез3Г ",//8
      "АМСЗ ДЗР2       ",//9
      "ДЗР 2           ",//10
      "ДЗР2 прям       ",//11
      "ДЗР2 обр        ",//12
      "Пост приск ДЗР3 ",//13
      "Приск ДЗР3 ВВР  ",//14
      "Блк ДЗР3 Iрез 3Г",//15
      "АМСЗ ДЗР3       ",//16
      "ДЗР3            ",//17
      "ДЗР3 прям       ",//18
      "ДЗР3 обр        ",//19

    },
    {
      "Неиспр.Напр.ДЗРE",//",1
      "Блк ДЗР1 Iрез 3E",//",2
      "Блк ДЗР1 Iрез  E",//",3
      "АМТЗ ДЗР 1     E",//",4
      "ДЗР 1          E",//",5
      "Пост ускор.ДЗР2E",//",6
      "Уск ДЗР2 от  ВВE",//",7
      "Блк ДЗР2 Iрез 3E",//",8
      "АМТЗ ДЗР2      E",//",9
      "ДЗР 2          E",//",10
      "ДЗР2 прям      E",//",11
      "ДЗР2 обр       E",//",12
      "Пост уск.  ДЗР3E",//",13
      "Уск ДЗР3 от  ВВE",//",14
      "Блк ДЗР3 Iрез 3E",//",15
      "АМТЗ ДЗР3      E",//",16
      "ДЗР3           E",//",17
      "ДЗР3 прям      E",//",18
      "ДЗР3 обр       E",//",19
	  

    },
    {
      "Неиспр.Напр.ДЗРK",//1
      "Блк ДЗР1 Iрез 3K",//2
      "Блк ДЗР1 Iрез  K",//3
      "АМТЗ ДЗР 1     K",//4
      "ДЗР 1          K",//5
      "Пост ускор.ДЗР2K",//6
      "Уск ДЗР2 от  ВВK",//7
      "Блк ДЗР2 Iрез 3K",//8
      "АМТЗ ДЗР2      K",//9
      "ДЗР 2          K",//10
      "ДЗР2 прям      K",//11
      "ДЗР2 обр       K",//12
      "Пост уск.  ДЗР3K",//13
      "Уск ДЗР3 от  ВВK",//14
      "Блк ДЗР3 Iрез 3K",//15
      "АМТЗ ДЗР3      K",//16
      "ДЗР3           K",//17
      "ДЗР3 прям      K",//18
      "ДЗР3 обр       K",//19


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
    if (index_of_ekran_tmp < MAX_ROW_FOR_CONTROL_DZR)
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
          
        if(current_ekran.edition == 0) temp_data = current_settings.control_dzr;
        else temp_data = edition_settings.control_dzr;
          
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
