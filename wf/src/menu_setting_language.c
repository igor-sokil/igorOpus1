#include "header.h"

/*****************************************************/
//������� ����� ����������� ���� ����
/*****************************************************/
void make_ekran_setting_language()
{
  static const unsigned char name_string[MAX_ROW_FOR_VIEW_SETTING_LANGUAGE][MAX_COL_LCD] = 
  {
    "    Language    "
  };
  
  unsigned int position_temp = current_ekran.index_position;
  unsigned int index_of_ekran;
  
  //�������� �� ��� �������� position_temp ������� ��� ����, �� �� ���� ������� �� ������������� ��� ����� (����� + ��������)
  index_of_ekran = ((position_temp<<1) >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;

  
  for (unsigned int i=0; i< MAX_ROW_LCD; i++)
  {
    if (index_of_ekran < (MAX_ROW_FOR_VIEW_SETTING_LANGUAGE<<1))//�������� �� ��� ��������� MAX_ROW_FOR_VIEW_SETTING_LANGUAGE ������� ��� ����, �� �� ���� ������� �� ������������� ��� ����� (����� + ��������)
    {
      if ((i & 0x1) == 0)
      {
        //� ��������� ����� ����� �������� ���������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_of_ekran>>1][j];
      }
      else
      {
        //� ������� ����� ����� �������� �������� �������
        unsigned char information[MAX_COL_LCD] = "                ";
        unsigned int temp_data;
          
        if(current_ekran.edition == 0) 
        {
          temp_data = current_settings.language;
          index_language_in_array(current_settings.language);
        }
        else
        {
          temp_data = edition_settings.language;
          index_language_in_array(edition_settings.language);
        }
          
        if (temp_data == LANGUAGE_RU)
        {
          information[ 4] = '�';
          information[ 5] = '�';
          information[ 6] = '�';
          information[ 7] = '�';
          information[ 8] = '�';
          information[ 9] = '�';
          information[10] = '�';
          current_ekran.position_cursor_x = 3;
        }
        else if (temp_data == LANGUAGE_UA)
        {
          information[ 3] = '�';
          information[ 4] = '�';
          information[ 5] = '�';
          information[ 6] = '�';
          information[ 7] = '�';
          information[ 8] = '�';
          information[ 9] = '�';
          information[10] = '�';
          information[11] = '�';
          information[12] = '�';
          current_ekran.position_cursor_x = 2;
        }
        else if (temp_data == LANGUAGE_EN)
        {
          information[ 4] = 'E';
          information[ 5] = 'n';
          information[ 6] = 'g';
          information[ 7] = 'l';
          information[ 8] = 'i';
          information[ 9] = 's';
          information[10] = 'h';
          current_ekran.position_cursor_x = 3;
        }
        else if (temp_data == LANGUAGE_KZ)
        {
          information[5 ] = '�';
          information[6 ] = '�';
          information[7 ] = '�';
          information[8 ] = '�';
          information[9 ] = '�';
          current_ekran.position_cursor_x = 4;
        }
        else
        {
          information[5 ] = 'E';
          information[6 ] = 'r';
          information[7 ] = 'r';
          information[8 ] = 'o';
          information[9 ] = 'r';
          current_ekran.position_cursor_x = 4;
        }
        
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = information[j];
      }
    }
    else
      for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = ' ';

    index_of_ekran++;
  }

  //³���������� ������ �� �������� � ������ ������ �� ���� � ��� �� ��������� ������
  current_ekran.position_cursor_y = ((position_temp<<1) + 1) & (MAX_ROW_LCD - 1);

  //������ �������, ���� �� � ����� �����������
  if (current_ekran.edition == 0) current_ekran.cursor_on = 0;
  else current_ekran.cursor_on = 1;

  //������ �� ����, ���� �� � ����� �����������
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
