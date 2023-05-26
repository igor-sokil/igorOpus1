#include "header.h"

/*****************************************************/
//������� ����� ����������� ����� �������
/*****************************************************/
void make_ekran_grupa_ustavok()
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_VIEW_GRUPA_USTAVOK][MAX_COL_LCD] = 
  {
    " ������ ������� ",
    " ����� �������  ",
    " Pick-up Set    ",
    " ������ ������� "
  };
  int index_language = index_language_in_array(current_settings.language);
  
  unsigned int position_temp = current_ekran.index_position;
  unsigned int index_of_ekran;
  
  //�������� �� ��� �������� position_temp ������� ��� ����, �� �� ���� ������� �� ������������� ��� ����� (����� + ��������)
  index_of_ekran = ((position_temp<<1) >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;

  
  for (unsigned int i=0; i< MAX_ROW_LCD; i++)
  {
    if (index_of_ekran < (MAX_ROW_FOR_VIEW_GRUPA_USTAVOK<<1))//�������� �� ��� ��������� MAX_ROW_FOR_VIEW_GRUPA_USTAVOK ������� ��� ����, �� �� ���� ������� �� ������������� ��� ����� (����� + ��������)
    {
      if ((i & 0x1) == 0)
      {
        //� ��������� ����� ����� �������� ���������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_language][index_of_ekran>>1][j];
      }
      else
      {
        //� ������� ����� ����� �������� �������� �������
        unsigned char information[MAX_NAMBER_LANGUAGE][MAX_COL_LCD] = 
        {
          "    ������ _    ",
          "    ����� _     ",
          "     Set _      ",
          "    ������ _    "
        };
        static const unsigned int cursor_x[MAX_NAMBER_LANGUAGE] = { 3,  3, 4,  3};
        static const unsigned int number_x[MAX_NAMBER_LANGUAGE] = {11, 10, 9, 11};

        unsigned int temp_data;
          
        if(current_ekran.edition == 0) temp_data = current_settings.grupa_ustavok ;
        else temp_data = edition_settings.grupa_ustavok;
          
        if ((temp_data >= SETPOINT_GRUPA_USTAVOK_MIN) && (temp_data <= SETPOINT_GRUPA_USTAVOK_MAX))
        {
          unsigned int number_x_tmp = number_x[index_language];
          for (unsigned int j = 0; j<MAX_COL_LCD; j++)
          {
            if (j != number_x_tmp)working_ekran[i][j] = information[index_language][j];
            else working_ekran[i][j] = temp_data + 0x30;
          }
          current_ekran.position_cursor_x = cursor_x[index_language];
        }
        else
        {
          static const unsigned char information_error[MAX_NAMBER_LANGUAGE][MAX_COL_LCD] = 
          {
            "     ������     ",
            "    �������     ",
            "     Error      ",
            "     ������     "
          };
          static const unsigned int cursor_x_error[MAX_NAMBER_LANGUAGE] = {4, 3, 4, 4};

          for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = information_error[index_language][j];
          current_ekran.position_cursor_x = cursor_x_error[index_language];
        }
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
