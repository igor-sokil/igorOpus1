#include "header.h"

/*****************************************************/
//������� ����� ����������� ������ ���� ������������
/*****************************************************/
void make_ekran_chose_item_of_point_time_settings(void)
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_POINT_TIME_SETTINGS][MAX_COL_LCD] = 
  {
    {
      " ����� �������� ",
      " ����� ��������."
    },
    {
      " ̳��� ������.  ",
      " ̳��� ������.  "
    },
    {
      " Settings Mark  ",
      " Ranking  Mark  "
    },
    {
      " ����� �������� ",
      " ����� ��������."
    }
  };
  int index_language = index_language_in_array(current_settings.language);
  
  unsigned int position_temp = current_ekran.index_position;
  unsigned int index_of_ekran;
  
  index_of_ekran = (position_temp >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;

  
  //�������  ����� � ������� �����
  for (unsigned int i=0; i< MAX_ROW_LCD; i++)
  {
    //������� ����� ����� ���������, �� �� ����� ���������� � ������� ������������
    if (index_of_ekran < MAX_ROW_FOR_POINT_TIME_SETTINGS)
      for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_language][index_of_ekran][j];
    else
      for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = ' ';

    index_of_ekran++;
  }

  //������ �� ���������� ������������ �� ������ �������
  current_ekran.position_cursor_x = 0;
  //³���������� ������ �� ��������
  current_ekran.position_cursor_y = position_temp & (MAX_ROW_LCD - 1);
  //������ �������
  current_ekran.cursor_on = 1;
  //������ �� ����
  current_ekran.cursor_blinking_on = 0;
  //�������� ������� ���� �����
  current_ekran.current_action = ACTION_WITH_CARRENT_EKRANE_FULL_UPDATE;
}
/*****************************************************/

/*****************************************************/
//������� ����� ���� ���� ������� ��� � �����������
/*
-------------------------------------------------------
������� ���������:
kind
      0 - ���� �������-��������-����������� ����������
      1 - ���� ����������
-------------------------------------------------------
*/
/*****************************************************/
void make_ekran_time_settings(unsigned int kind)
{
  unsigned char name_string[2*MAX_ROW_FOR_POINT_TIME_SETPOINT_RANGUVANNJA][MAX_COL_LCD] = 
  {
    "00-00-2000      ",
    "00:00:00 XXXXXXX"
  };
  
  unsigned int position_temp = current_ekran.index_position;
  unsigned int index_of_ekran;
  time_t time_target = (kind == 0) ? current_settings.time_setpoints : current_settings.time_ranguvannja;
  unsigned char source_target = (kind == 0) ? current_settings.source_setpoints : current_settings.source_ranguvannja;
  
  index_of_ekran = (position_temp >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;

  /******************************************/
  //���������� ���� ���������� �������
  /******************************************/
   if (time_target != 0)
   {
      struct tm *p = localtime(&time_target);
      int field;
      
      //����
      field = p->tm_mday;
      name_string[0][0 ] = (field / 10) + 0x30;
      name_string[0][1 ] = (field % 10) + 0x30;

      //̳����
      field = p->tm_mon + 1;
      name_string[0][3 ] = (field / 10) + 0x30;
      name_string[0][4 ] = (field % 10) + 0x30;

      //г�
      field = p->tm_year - 100;
      name_string[0][8 ] = (field / 10) + 0x30;
      name_string[0][9 ] = (field % 10) + 0x30;

      //������
      field = p->tm_hour;
      name_string[1][0 ] = (field / 10) + 0x30;
      name_string[1][1 ] = (field % 10) + 0x30;

      //�������
      field = p->tm_min;
      name_string[1][3 ] = (field / 10) + 0x30;
      name_string[1][4 ] = (field % 10) + 0x30;

      //�������
      field = p->tm_sec;
      name_string[1][6 ] = (field / 10) + 0x30;
      name_string[1][7 ] = (field % 10) + 0x30;
   }

  //����������� ��� ������� ���
  if(source_target == 0)
  {
    name_string[ROW_T_][MAX_COL_LCD - 7] = ' ';
    name_string[ROW_T_][MAX_COL_LCD - 6] = ' ';
    name_string[ROW_T_][MAX_COL_LCD - 5] = ' ';
    name_string[ROW_T_][MAX_COL_LCD - 4] = ' ';
    name_string[ROW_T_][MAX_COL_LCD - 3] = ' ';
    name_string[ROW_T_][MAX_COL_LCD - 2] = ' ';
    name_string[ROW_T_][MAX_COL_LCD - 1] = '0';
  }
  else if(source_target == 1)
  {
    name_string[ROW_T_][MAX_COL_LCD - 7] = ' ';
    name_string[ROW_T_][MAX_COL_LCD - 6] = ' ';
    name_string[ROW_T_][MAX_COL_LCD - 5] = ' ';
    name_string[ROW_T_][MAX_COL_LCD - 4] = ' ';
    name_string[ROW_T_][MAX_COL_LCD - 3] = ' ';
    name_string[ROW_T_][MAX_COL_LCD - 2] = ' ';
    name_string[ROW_T_][MAX_COL_LCD - 1] = 'K';
  }
  else if(source_target == 2)
  {
    name_string[ROW_T_][MAX_COL_LCD - 7] = ' ';
    name_string[ROW_T_][MAX_COL_LCD - 6] = ' ';
    name_string[ROW_T_][MAX_COL_LCD - 5] = ' ';
    name_string[ROW_T_][MAX_COL_LCD - 4] = ' ';
    name_string[ROW_T_][MAX_COL_LCD - 3] = 'U';
    name_string[ROW_T_][MAX_COL_LCD - 2] = 'S';
    name_string[ROW_T_][MAX_COL_LCD - 1] = 'B';
  }
  else if(source_target == 3)
  {
    name_string[ROW_T_][MAX_COL_LCD - 7] = ' ';
    name_string[ROW_T_][MAX_COL_LCD - 6] = 'R';
    name_string[ROW_T_][MAX_COL_LCD - 5] = 'S';
    name_string[ROW_T_][MAX_COL_LCD - 4] = '-';
    name_string[ROW_T_][MAX_COL_LCD - 3] = '4';
    name_string[ROW_T_][MAX_COL_LCD - 2] = '8';
    name_string[ROW_T_][MAX_COL_LCD - 1] = '5';
  }
  else
  {
    //���������� �� ���� � �� ���� ����� ��������, ��� ���� �� ���� ������, �� �������� ����������� ��� ������� �� �����
    static const unsigned char error_meas[MAX_NAMBER_LANGUAGE][7] = 
    {
      " ������",
      "�������",
      "  Error",
      " ������"
    };
    int index_language = index_language_in_array(current_settings.language);
      
    for (unsigned int i = 0; i < 7; i++) name_string[ROW_T_][9 + i] = error_meas[index_language][i];
  }
  
  /******************************************/
  
  //�������  ����� � ������� �����
  for (unsigned int i=0; i< MAX_ROW_LCD; i++)
  {
    //������� ����� ����� ���������, �� �� ����� ����������
    if (index_of_ekran < (2*MAX_ROW_FOR_POINT_TIME_SETPOINT_RANGUVANNJA))
      for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_of_ekran][j];
    else
      for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = ' ';

    index_of_ekran++;
  }

  //������ �� ���������� ������� �� ������ �������
  current_ekran.position_cursor_x = 0;
  //³���������� ������ �� �������� � 0
  current_ekran.position_cursor_y = 0;
  //������ �� �������
  current_ekran.cursor_on = 0;
  //������ �� ����
  current_ekran.cursor_blinking_on = 0;
  //�������� ������� ���� �����
  current_ekran.current_action = ACTION_WITH_CARRENT_EKRANE_FULL_UPDATE;
}
/*****************************************************/

/*****************************************************/
//
/*****************************************************/
/*****************************************************/
