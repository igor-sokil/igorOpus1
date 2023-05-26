#include "header.h"

/*****************************************************/
//������� ����� ������
/*****************************************************/
void make_ekran_level_password(unsigned int password, unsigned int view)
{
  static const unsigned char name_string_1[MAX_NAMBER_LANGUAGE][MAX_COL_LCD] = 
  {
    " ������� ������:",
    " ������ ������:",
    " Enter password:",
    " ������� ������:"
  };

  static const unsigned char name_string_2[MAX_NAMBER_LANGUAGE][MAX_COL_LCD] = 
  {
    "  ����� ������: ",
    "  ����� ������: ",
    "  New password: ",
    "  ����� ������: "
  };

  //��������� � ���� ������� ������ ���������
  unsigned char *point_to_working_array;
  if (
      (current_ekran.current_level == EKRAN_LEVEL_SET_NEW_PASSWORD1) ||
      (current_ekran.current_level == EKRAN_LEVEL_SET_NEW_PASSWORD2) ||
      (current_ekran.current_level == EKRAN_LEVEL_SET_NEW_PASSWORD3)
     )   
    point_to_working_array = (unsigned char *)name_string_2;
  else
    point_to_working_array = (unsigned char *)name_string_1;

  unsigned char name_string_tmp[MAX_ROW_LCD][MAX_COL_LCD];

  int index_language = index_language_in_array(current_settings.language);
  for(int index_1 = 0; index_1 < MAX_ROW_LCD; index_1++)
  {
    for(int index_2 = 0; index_2 < MAX_COL_LCD; index_2++)
    {
      unsigned char copy_symbol;
      if (index_1 == INDEX_LINE_NUMBER_1_FOR_LEVEL_PASSWORD)
        copy_symbol = *(point_to_working_array + index_language*MAX_COL_LCD + index_2);
      else
        copy_symbol = ' ';
      
      name_string_tmp[index_1][index_2] = copy_symbol;
    }
  }
  
  if (view != 0)
  {
    unsigned int position_cursor = COL_NEW_PASSWORD_BEGIN;
    if (password != 0)
    {
      unsigned int temp_value_1,temp_value_2, temp_value_3, temp_value_4;
    
      temp_value_4 = password % 10;

      temp_value_3 = password / 10;
      temp_value_3 %=  10;
    
      temp_value_2 = password / 100;
      temp_value_2 %=  10;
    
      temp_value_1 = password / 1000;
      temp_value_1 %=  10;
    
      if(temp_value_1 != 0) name_string_tmp[INDEX_LINE_NUMBER_2_FOR_LEVEL_PASSWORD][position_cursor++] = temp_value_1 + 0x30;
      if(temp_value_2 != 0) name_string_tmp[INDEX_LINE_NUMBER_2_FOR_LEVEL_PASSWORD][position_cursor++] = temp_value_2 + 0x30;
      if(temp_value_3 != 0) name_string_tmp[INDEX_LINE_NUMBER_2_FOR_LEVEL_PASSWORD][position_cursor++] = temp_value_3 + 0x30;
      if(temp_value_4 != 0) name_string_tmp[INDEX_LINE_NUMBER_2_FOR_LEVEL_PASSWORD][position_cursor++] = temp_value_4 + 0x30;
    }
    else
    {
      unsigned char symbol = (current_ekran.current_level == EKRAN_LEVEL_SET_NEW_PASSWORD1) ? '0' : '?';
      name_string_tmp[INDEX_LINE_NUMBER_2_FOR_LEVEL_PASSWORD][position_cursor++] = symbol;
    }
  }

  //�������  ����� � ������� �����
  for (unsigned int i=0; i< MAX_ROW_LCD; i++)
  {
    for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string_tmp[i][j];
  }
  
  number_seconds = 0; //������, ��� �� ���� ������� �� ������������ ����������, ���� ��� �������� ������, �� �� ����� ����� � ���������, ���� ��������� ����������� ������� �� �� ��� ������� ����
  
  //³���������� ������ �� ��������
  current_ekran.position_cursor_y = 1;
  //�������� ������� ���� �����
  current_ekran.current_action = ACTION_WITH_CARRENT_EKRANE_FULL_UPDATE;
}
/*****************************************************/

/*****************************************************/
//������� ����� ����������� ��������� ���������
/*****************************************************/
void make_ekran_chose_passwords(void)
{
  static const unsigned char password_item[MAX_ROW_FOR_CHOOSE_PASSWORDS][MAX_NAMBER_LANGUAGE][2][MAX_COL_LCD] = 
  {
    {
      {" ����� ������ 1 ", " ���.������ 1   "},
      {" ���� ������ 1 ", " ���.������ 1   "},
      {" Pass 1 Change  ", " Password 1 Set "},
      {" ����� ������ 1 ", " ���.������ 1   "}
    },
    {
      {" ����� ������ 2 ", " ���.������ 2   "},
      {" ���� ������ 2 ", " ���.������ 2   "},
      {" Pass 2 Change  ", " Password 2 Set "},
      {" ����� ������ 2 ", " ���.������ 2   "}
    },
    {
      {" ����� ������ 3 ", " ���.������ 3   "},
      {" ���� ������ 3 ", " ���.������ 3   "},
      {" Pass.3 Change  ", " Password 3 Set "},
      {" ����� ������ 3 ", " ���.������ 3   "}
    }
  };
  int index_language = index_language_in_array(current_settings.language);
  
  unsigned int position_temp = current_ekran.index_position;
  unsigned int index_of_ekran;
  
  index_of_ekran = (position_temp >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;

  
  //�������  ����� � ������� �����
  for (unsigned int i=0; i< MAX_ROW_LCD; i++)
  {
    //������� ����� ����� ���������, �� �� ����� ���������� � ������� �����������
    if (index_of_ekran < MAX_ROW_FOR_CHOOSE_PASSWORDS)
    {
      unsigned int password;
      if (index_of_ekran == INDEX_OF_PASSWORD1)
        password = current_settings.password1;
      else if (index_of_ekran == INDEX_OF_PASSWORD2)
        password = current_settings.password2;
      else
        password = current_settings.password3;
      
      unsigned int index_of_information = ( password != 0) ? 0 : 1;
      for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = password_item[index_of_ekran][index_language][index_of_information][j];
    } 
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
// 
/*****************************************************/
/*****************************************************/

