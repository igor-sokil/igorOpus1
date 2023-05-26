#include "header.h"
  static const uint8_t name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_LIST_SOURCE_TF][MAX_COL_LCD] = 
  {
    {
      "      ����      ",
      "     �����      "
    },
    {
      "      ����      ",
      "     �����      "
    },
    {
      "     Input      ",
      "     Output     "
    },
    {
      "      ����      ",
      "     �����      "
    }
  };
   static const uint8_t input_signals[MAX_NAMBER_LANGUAGE][1 + TOTAL_SIGNAL_FOR_RNG_BIG - TOTAL_UP_SIGNAL_FOR_RNG_BIG + 3][MAX_COL_LCD] = 
  {
    {"     �����      ", NAME_RANG_A01_RU},
    {"     �����      ", NAME_RANG_A01_UA},
    {"     Empty      ", NAME_RANG_A01_EN},
    {"     �����      ", NAME_RANG_A01_KZ}
  };
  static const uint8_t output_signals[MAX_NAMBER_LANGUAGE][1 + TOTAL_SIGNAL_FOR_RANG_SMALL_A01 - TOTAL_UP_SIGNAL_FOR_RANG_SMALL + 1][MAX_COL_LCD] = 
  {
    {"     �����      ", NAME_RANG_SMALL_RU},
    {"     �����      ", NAME_RANG_SMALL_UA},
    {"     Empty      ", NAME_RANG_SMALL_EN},
    {"     �����      ", NAME_RANG_SMALL_KZ}
  };
  static const uint32_t index_number_UP[MAX_NAMBER_LANGUAGE][3] = 
  {
    {11, 10, 8}, 
    {11, 10, 8}, 
    { 6,  6, 9}, 
    {11, 10, 8} 
  };
    const unsigned char name_block_zz[MAX_NAMBER_LANGUAGE][MAX_COL_LCD] = 
   {
     "    ����.��     ",
     "    ����.��     ",
     "    ����.��     ",
     "    ����.��     "
   }; 
/*****************************************************/
//������� ����� ����������� ���� ������ ���������� ������������� �������
/*****************************************************/
void make_ekran_list_source_tf(void)
{


  int index_language = index_language_in_array(current_settings.language);
  
  uint8_t input_signals_tmp[1 + TOTAL_SIGNAL_FOR_RNG_BIG][MAX_COL_LCD];
  for(int index_1 = 0; index_1 < (1 + TOTAL_SIGNAL_FOR_RNG_BIG); index_1++)
  {
    unsigned int index_row;
    if (index_1 < (1 + TOTAL_SIGNAL_FOR_RNG_BIG - TOTAL_EL_SIGNAL_FOR_RNG_BIG - TOTAL_VMP_SIGNAL_FOR_RNG_BIG - TOTAL_UP_SIGNAL_FOR_RNG_BIG)) 
    {
      index_row = index_1;
    }
    else if (index_1 < (1 + TOTAL_SIGNAL_FOR_RNG_BIG - TOTAL_EL_SIGNAL_FOR_RNG_BIG - TOTAL_VMP_SIGNAL_FOR_RNG_BIG))
    {
      index_row = (1 + TOTAL_SIGNAL_FOR_RNG_BIG - TOTAL_EL_SIGNAL_FOR_RNG_BIG - TOTAL_VMP_SIGNAL_FOR_RNG_BIG - TOTAL_UP_SIGNAL_FOR_RNG_BIG) + ((index_1 - (1 + TOTAL_SIGNAL_FOR_RNG_BIG - TOTAL_EL_SIGNAL_FOR_RNG_BIG - TOTAL_VMP_SIGNAL_FOR_RNG_BIG - TOTAL_UP_SIGNAL_FOR_RNG_BIG )) % 3);
    }
    else
    {
      index_row = index_1 - TOTAL_SIGNAL_FOR_RNG_BIG + 3;
    }
      
    for(int index_2 = 0; index_2 < MAX_COL_LCD; index_2++)
    {
      if (
          (index_1 >= (1 + TOTAL_SIGNAL_FOR_RNG_BIG - TOTAL_EL_SIGNAL_FOR_RNG_BIG - TOTAL_VMP_SIGNAL_FOR_RNG_BIG - TOTAL_UP_SIGNAL_FOR_RNG_BIG))  &&
          (index_1 <  (1 + TOTAL_SIGNAL_FOR_RNG_BIG - TOTAL_EL_SIGNAL_FOR_RNG_BIG - TOTAL_VMP_SIGNAL_FOR_RNG_BIG)) &&
          (index_2 == index_number_UP[index_language][(index_1 - (1 + TOTAL_SIGNAL_FOR_RNG_BIG - TOTAL_EL_SIGNAL_FOR_RNG_BIG - TOTAL_VMP_SIGNAL_FOR_RNG_BIG - TOTAL_UP_SIGNAL_FOR_RNG_BIG)) % 3]) 
         )
      {
        input_signals_tmp[index_1][index_2] = 0x30 + ((index_1 - (1 + TOTAL_SIGNAL_FOR_RNG_BIG - TOTAL_EL_SIGNAL_FOR_RNG_BIG - TOTAL_VMP_SIGNAL_FOR_RNG_BIG - TOTAL_UP_SIGNAL_FOR_RNG_BIG)) / 3 + 1);
      }
      else input_signals_tmp[index_1][index_2] = input_signals[index_language][index_row][index_2];
    }
  }

   uint8_t output_signals_tmp[1 + TOTAL_SIGNAL_FOR_RANG_SMALL_A01][MAX_COL_LCD];
   //uint8_t output_signals_tmp[1 ][1];
  for(int index_1 = 0; index_1 < (1 + TOTAL_SIGNAL_FOR_RANG_SMALL_A01); index_1++)
  {
    unsigned int index_row;
    if (index_1 < (1 + TOTAL_SIGNAL_FOR_RANG_SMALL_A01 - TOTAL_EL_SIGNAL_FOR_RANG_SMALL - TOTAL_VMP_SIGNAL_FOR_RANG_SMALL - TOTAL_UP_SIGNAL_FOR_RANG_SMALL)) 
    {
      index_row = index_1;
    }
    else if (index_1 < (1 + TOTAL_SIGNAL_FOR_RANG_SMALL_A01 - TOTAL_EL_SIGNAL_FOR_RANG_SMALL - TOTAL_VMP_SIGNAL_FOR_RANG_SMALL))
    {
      index_row = (1 + TOTAL_SIGNAL_FOR_RANG_SMALL_A01 - TOTAL_EL_SIGNAL_FOR_RANG_SMALL - TOTAL_VMP_SIGNAL_FOR_RANG_SMALL - TOTAL_UP_SIGNAL_FOR_RANG_SMALL) + ((index_1 - (1 + TOTAL_SIGNAL_FOR_RANG_SMALL_A01 - TOTAL_EL_SIGNAL_FOR_RANG_SMALL - TOTAL_VMP_SIGNAL_FOR_RANG_SMALL - TOTAL_UP_SIGNAL_FOR_RANG_SMALL)) % 1);
    }
    else
    {
      index_row = index_1 - TOTAL_UP_SIGNAL_FOR_RANG_SMALL + 1;
    }
      
    for(int index_2 = 0; index_2 < MAX_COL_LCD; index_2++)
    {
      if (
          (index_1 >= (1 + TOTAL_SIGNAL_FOR_RANG_SMALL_A01 - TOTAL_EL_SIGNAL_FOR_RANG_SMALL - TOTAL_VMP_SIGNAL_FOR_RANG_SMALL - TOTAL_UP_SIGNAL_FOR_RANG_SMALL))  &&
          (index_1 <  (1 + TOTAL_SIGNAL_FOR_RANG_SMALL_A01 - TOTAL_EL_SIGNAL_FOR_RANG_SMALL - TOTAL_VMP_SIGNAL_FOR_RANG_SMALL)) &&
          (index_2 == index_number_UP[index_language][(index_1 - (1 + TOTAL_SIGNAL_FOR_RANG_SMALL_A01 - TOTAL_EL_SIGNAL_FOR_RANG_SMALL - TOTAL_VMP_SIGNAL_FOR_RANG_SMALL - TOTAL_UP_SIGNAL_FOR_RANG_SMALL)) % 1]) 
         )
      {
        output_signals_tmp[index_1][index_2] = 0x30 + ((index_1 - (1 + TOTAL_SIGNAL_FOR_RANG_SMALL_A01 - TOTAL_EL_SIGNAL_FOR_RANG_SMALL - TOTAL_VMP_SIGNAL_FOR_RANG_SMALL - TOTAL_UP_SIGNAL_FOR_RANG_SMALL)) / 1 + 1);
      }
      else output_signals_tmp[index_1][index_2] = output_signals[index_language][index_row][index_2];
    }
  }

  uint32_t position_temp = current_ekran.index_position;
  uint32_t index_of_ekran = ((position_temp << 1) >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;
  
        uint32_t value = 0;
        if(current_ekran.edition == 0){
	      value = current_settings.ranguvannja_tf[current_ekran.current_level - EKRAN_LIST_SOURCE_TF1];
        }else{
	      value = edition_settings.ranguvannja_tf[current_ekran.current_level - EKRAN_LIST_SOURCE_TF1];
        }
  //!uint32_t value = ((current_ekran.edition == 0) ? current_settings : edition_settings).ranguvannja_tf[current_ekran.current_level - EKRAN_LIST_SOURCE_TF1];
  //�������  ����� � ������� �����
  for (size_t i =0; i < MAX_ROW_LCD; i++)
  {
    int32_t index_of_ekran_tmp = index_of_ekran >> 1;
    if (index_of_ekran_tmp < MAX_ROW_LIST_SOURCE_TF)//�������� �� ��� ��������� ������� ��� ����, �� �� ���� ������� �� ������������� ��� ����� (����� + ��������)
    {
      if ((i & 0x1) == 0)
      {
        //� ��������� ����� ����� �������� ���������
        for (size_t j = 0; j<MAX_COL_LCD; j++) 
			working_ekran[i][j] = name_string[index_language][index_of_ekran_tmp][j];
      }
      else
      {
        //� ������� ����� ����� �������� ��������
        //for (size_t j = 0; j < MAX_COL_LCD; j++) working_ekran[i][j] = ((index_of_ekran_tmp == INDEX_ML_LIST_SOURCE_INPUT_TF) ? input_signals_tmp : output_signals_tmp)[(value >> (16*index_of_ekran_tmp)) & 0xffff][j];
        for (size_t j = 0; j < MAX_COL_LCD; j++){
			if( index_of_ekran_tmp == INDEX_ML_LIST_SOURCE_INPUT_TF ){
				working_ekran[i][j] = input_signals_tmp[(value >> (16*index_of_ekran_tmp)) & 0xffff][j];
			}else{
				working_ekran[i][j] = output_signals_tmp[(value >> (16*index_of_ekran_tmp)) & 0xffff][j];
			}
		}
		
        if (position_temp == index_of_ekran_tmp) 
        {
          current_ekran.position_cursor_x = 0;
          while (
                 (current_ekran.position_cursor_x < (MAX_COL_LCD - 1)) &&
                 (working_ekran[i][current_ekran.position_cursor_x + 1] == ' ')  
                )
          {
            current_ekran.position_cursor_x++;
          }
        }
      }
    }
    else
      for (size_t j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = ' ';

    index_of_ekran++;
  }

  //³���������� ������ �� �������� � ������ ������ �� ���� � ��� �� ��������� ������
  current_ekran.position_cursor_y = ((position_temp << 1) + 1) & (MAX_ROW_LCD - 1);
  //������ �������
  current_ekran.cursor_on = 1;

  if(current_ekran.edition == 0)current_ekran.cursor_blinking_on = 0;
  else current_ekran.cursor_blinking_on = 1;

  //�������� ������� ���� �����
  current_ekran.current_action = ACTION_WITH_CARRENT_EKRANE_FULL_UPDATE;
}
/*****************************************************/

/*****************************************************/
//
/*****************************************************/
/*****************************************************/
