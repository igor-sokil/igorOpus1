#include "header.h"

/*****************************************************/
//������� ����� ������-���
/*****************************************************/
void make_ekran_time(void)
{
  unsigned char name_string[MAX_ROW_FOR_EKRAN_TIME][MAX_COL_LCD] = 
  {
    "   XX-XX-20XX   ",
    "    XX:XX:XX    ",
    "                ",
    "      X XX      "
  };
  
  static const unsigned char calibrating[MAX_NAMBER_LANGUAGE][MAX_COL_LCD] = 
  {
    "   ����������   ",
    "  �����������  ",
    "  Calibration   ",
    "   ����������   "
  };
  
  int index_language = index_language_in_array(current_settings.language);
  for(int index_1 = 0; index_1 < MAX_COL_LCD; index_1++)
    name_string[2][index_1] = calibrating[index_language][index_1];
  
  unsigned int position_temp = current_ekran.index_position;
  unsigned int index_of_ekran;
  
  /******************************************/
  //���������� ���� ���������� �������
  /******************************************/
  if (current_ekran.edition == 0)
  {
    time_t time_dat_tmp;
    if (save_time_dat_l == 3) time_dat_tmp = time_dat_save_l;
    else
    { 
      copying_time_dat = 1;
      time_dat_tmp = time_dat_copy;
      copying_time_dat = 0;
    }

    struct tm *p;
    p = localtime(&time_dat_tmp);
    int field;
    
    //����
    field = p->tm_mday;
    name_string[ROW_Y_][COL_DY1] = (field / 10) + 0x30;
    name_string[ROW_Y_][COL_DY2] = (field % 10) + 0x30;

    //̳����
    field = p->tm_mon + 1;
    name_string[ROW_Y_][COL_MY1] = (field / 10) + 0x30;
    name_string[ROW_Y_][COL_MY2] = (field % 10) + 0x30;

    //г�
    field = p->tm_year - 100;
    name_string[ROW_Y_][COL_SY1] = (field / 10) + 0x30;
    name_string[ROW_Y_][COL_SY2] = (field % 10) + 0x30;

    //������
    field = p->tm_hour;
    name_string[ROW_T_][COL_HT1] = (field / 10) + 0x30;
    name_string[ROW_T_][COL_HT2] = (field % 10) + 0x30;

    //�������
    field = p->tm_min;
    name_string[ROW_T_][COL_MT1] = (field / 10) + 0x30;
    name_string[ROW_T_][COL_MT2] = (field % 10) + 0x30;

    //�������
    field = p->tm_sec;
    name_string[ROW_T_][COL_ST1] = (field / 10) + 0x30;
    name_string[ROW_T_][COL_ST2] = (field % 10) + 0x30;

    //���������
    if((calibration & (1<<5)) == 0) name_string[ROW_K_][COL_SK1] = '-';
    else name_string[ROW_K_][COL_SK1] = '+';
    
    name_string[ROW_K_][COL_VK2] =((calibration & 0x1f) % 10) + 0x30;
    name_string[ROW_K_][COL_VK1] =((calibration & 0x1f) / 10) + 0x30;
  }
  else
  {
    //����
    name_string[ROW_Y_][COL_DY1] = (time_edit[4] >>  4) + 0x30;
    name_string[ROW_Y_][COL_DY2] = (time_edit[4] & 0xf) + 0x30;

    //̳����
    name_string[ROW_Y_][COL_MY1] = (time_edit[5] >>  4) + 0x30;
    name_string[ROW_Y_][COL_MY2] = (time_edit[5] & 0xf) + 0x30;

    //г�
    name_string[ROW_Y_][COL_SY1] = (time_edit[6] >>  4) + 0x30;
    name_string[ROW_Y_][COL_SY2] = (time_edit[6] & 0xf) + 0x30;

    //������
    name_string[ROW_T_][COL_HT1] = (time_edit[3] >>  4) + 0x30;
    name_string[ROW_T_][COL_HT2] = (time_edit[3] & 0xf) + 0x30;

    //�������
    name_string[ROW_T_][COL_MT1] = (time_edit[2] >>  4) + 0x30;
    name_string[ROW_T_][COL_MT2] = (time_edit[2] & 0xf) + 0x30;

    //�������
    name_string[ROW_T_][COL_ST1] = (time_edit[1] >>  4) + 0x30;
    name_string[ROW_T_][COL_ST2] = (time_edit[1] & 0xf) + 0x30;

    //���������
    if((calibration_edit & (1<<5)) == 0) name_string[ROW_K_][COL_SK1] = '-';
    else name_string[ROW_K_][COL_SK1] = '+';

    name_string[ROW_K_][COL_VK2] =((calibration_edit & 0x1f) % 10) + 0x30;
    name_string[ROW_K_][COL_VK1] =((calibration_edit & 0x1f) / 10) + 0x30;
  }

  /******************************************/
  
  index_of_ekran = (position_temp >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;

  
  //�������  ����� � ������� �����
  for (unsigned int i=0; i< MAX_ROW_LCD; i++)
  {
    //������� ����� ����� ���������, �� �� ����� ����������
    if (index_of_ekran < MAX_ROW_FOR_EKRAN_TIME)
      for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_of_ekran][j];
    else
      for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = ' ';

    index_of_ekran++;
  }

  //³���������� ������ �� ��������
  current_ekran.position_cursor_y = position_temp & (MAX_ROW_LCD - 1);
  //�������� ������� ���� �����
  current_ekran.current_action = ACTION_WITH_CARRENT_EKRANE_FULL_UPDATE;
}
/*****************************************************/

/*****************************************************/
//����������� ���� � ������� ����
/*****************************************************
����� ���������
  0 - �������� ������ ����
  1 - ��������� ������ �����
����� ���������
  ����
*****************************************************/
void edit_time(unsigned int action)
{
  //������� ����� � �������� ����
  if(current_ekran.index_position == ROW_Y_)
  {
    if(current_ekran.position_cursor_x == COL_DY1)
    {
      unsigned int temp_value = time_edit[4] >> 4;
      inc_or_dec_value(&temp_value, action);
      
      time_edit[4] &= 0xf;
      time_edit[4] |= (temp_value << 4);
    }
    else if(current_ekran.position_cursor_x == COL_DY2)
    {
      unsigned int temp_value = time_edit[4] & 0xf;
      inc_or_dec_value(&temp_value, action);

      time_edit[4] &= 0xf0;
      time_edit[4] |= temp_value;
    }
    else if(current_ekran.position_cursor_x == COL_MY1)
    {
      unsigned int temp_value = time_edit[5] >> 4;
      inc_or_dec_value(&temp_value, action);

      time_edit[5] &= 0xf;
      time_edit[5] |= (temp_value << 4);
    }
    else if(current_ekran.position_cursor_x == COL_MY2)
    {
      unsigned int temp_value = time_edit[5] & 0xf;
      inc_or_dec_value(&temp_value, action);

      time_edit[5] &= 0xf0;
      time_edit[5] |= temp_value;
    }
    else if(current_ekran.position_cursor_x == COL_SY1)
    {
      unsigned int temp_value = time_edit[6] >> 4;
      inc_or_dec_value(&temp_value, action);

      time_edit[6] &= 0xf;
      time_edit[6] |= (temp_value << 4);
    }
    else if(current_ekran.position_cursor_x == COL_SY2)
    {
      unsigned int temp_value = time_edit[6] & 0xf;
      inc_or_dec_value(&temp_value, action);

      time_edit[6] &= 0xf0;
      time_edit[6] |= temp_value;
    }
  }
  else if(current_ekran.index_position == ROW_T_)
  {
    if(current_ekran.position_cursor_x == COL_HT1)
    {
      unsigned int temp_value = time_edit[3] >> 4;
      inc_or_dec_value(&temp_value, action);

      time_edit[3] &= 0xf;
      time_edit[3] |= (temp_value << 4);
    }
    else if(current_ekran.position_cursor_x == COL_HT2)
    {
      unsigned int temp_value = time_edit[3] & 0xf;
      inc_or_dec_value(&temp_value, action);

      time_edit[3] &= 0xf0;
      time_edit[3] |= temp_value;
    }
    else if(current_ekran.position_cursor_x == COL_MT1)
    {
      unsigned int temp_value = time_edit[2] >> 4;
      inc_or_dec_value(&temp_value, action);

      time_edit[2] &= 0xf;
      time_edit[2] |= (temp_value << 4);
    }
    else if(current_ekran.position_cursor_x == COL_MT2)
    {
      unsigned int temp_value = time_edit[2] & 0xf;
      inc_or_dec_value(&temp_value, action);

      time_edit[2] &= 0xf0;
      time_edit[2] |= temp_value;
    }
    else if(current_ekran.position_cursor_x == COL_ST1)
    {
      unsigned int temp_value = time_edit[1] >> 4;
      inc_or_dec_value(&temp_value, action);

      time_edit[1] &= 0xf;
      time_edit[1] |= (temp_value << 4);
    }
    else if(current_ekran.position_cursor_x == COL_ST2)
    {
      unsigned int temp_value = time_edit[1] & 0xf;
      inc_or_dec_value(&temp_value, action);

      time_edit[1] &= 0xf0;
      time_edit[1] |= temp_value;
    }
  }
  else if(current_ekran.index_position == ROW_K_)
  {
    if(current_ekran.position_cursor_x == COL_SK1) 
    {
      if ((calibration_edit & 0x20) != 0) calibration_edit &= 0x1f;
      else calibration_edit |= 0x20;
    }
    else if(current_ekran.position_cursor_x == COL_VK1)
    {
      unsigned char temp_1 = calibration_edit & 0x20, temp_2 = calibration_edit & 0x1f;
      unsigned int temp_value = temp_2 / 10;
      inc_or_dec_value(&temp_value, action);

      temp_2 %= 10;
      temp_2 += temp_value*10;
      if (temp_2 > 31) temp_2 = 31;
      calibration_edit = temp_1 | temp_2;
                
    }
    else if(current_ekran.position_cursor_x == COL_VK2)
    {
      unsigned char temp_1 = calibration_edit & 0x20, temp_2 = calibration_edit & 0x1f;
      unsigned int temp_value = temp_2 % 10;
      inc_or_dec_value(&temp_value, action);

      temp_2 = (temp_2 / 10) *10;
      temp_2 += temp_value;
      if (temp_2 > 31) temp_2 = 31;
      calibration_edit = temp_1 | temp_2;
     }
  }
}
/*****************************************************/

/*****************************************************/
//���������� ����������� �����
/*
���������
  1 - ��� ��������
  0 - ��� ����������
*/
/*****************************************************/
unsigned int check_data_for_data_time_menu(void)
{
  unsigned int temp_data_1, temp_data_2;
  
  /*******/
  //г�
  /*******/
  temp_data_1 = bcd_to_int(time_edit[6]);
  if( temp_data_1 > 99 ) return 0;

  /*******/
  //̳����
  /*******/
  temp_data_1 = bcd_to_int(time_edit[5]);
  if( (temp_data_1 == 0) || (temp_data_1 > 12)) return 0;
  
  /*******/
  //���� �����
  /*******/
  temp_data_2 = bcd_to_int(time_edit[4]);
  if((temp_data_2 == 0) || (temp_data_2 > 31)) return 0;
  //�������� �������� �� ����� � ����� � ����� 30 ���
  if (((temp_data_1 == 4) || (temp_data_1 == 6) || (temp_data_1 == 9) || (temp_data_1 == 11)) &&
      (temp_data_2 > 30)) return 0;

  //�������� �������� �� ����� ����� ����� � ���������� ���� ����������� �� �� �����������
  if((temp_data_1 == 2) && (temp_data_2 > 29)) return 0;
  else if ((temp_data_1 == 2) && (temp_data_2 == 29))
  {
    //����� temp_data_1 ���������, �� ����� ����, �� ��� ����� ����� ����� ��� �� ���� �������
    temp_data_1 = bcd_to_int(time_edit[6]);
    if ((temp_data_1 % 4) !=0) return 0;
  }
  /*******/

  /*******/
  //������
  /*******/
  temp_data_2 = bcd_to_int(time_edit[3]);
  if(temp_data_2 > 23) return 0;
  /*******/

  /*******/
  //�������
  /*******/
  temp_data_2 = bcd_to_int(time_edit[2]);
  if(temp_data_2 > 59) return 0;
  /*******/

  /*******/
  //�������
  /*******/
  temp_data_2 = bcd_to_int(time_edit[1]);
  if(temp_data_2 > 59) return 0;
  /*******/

  /*******/
  //��� �������
  /*******/
  temp_data_1 = bcd_to_int(time_edit[0]);
  if( temp_data_1 > 99 ) return 0;

  //����� � ������������, �� �� ��������� �  ����� �������
  return 1;
}
/*****************************************************/


/*****************************************************/
//������ ����� � ������� BCD � int 
/*****************************************************/
unsigned int bcd_to_int(unsigned char input)
{
  unsigned int output, temp_data;
  
  temp_data = input >> 4;
  output = temp_data*10;
  output +=input & 0xf;
  
  return output;
}
/*****************************************************/


/*****************************************************/
// 
/*****************************************************/
/*****************************************************/
