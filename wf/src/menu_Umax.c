#include "header.h"

/*****************************************************/
//������� ����� ����������� ������� Umax
/*****************************************************/
void make_ekran_setpoint_Umax(unsigned int group)
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_SETPOINT_UMAX][MAX_COL_LCD] = 
  {
    {
      " ������� ������1",
      " ������� ������2",
      "   �� ������    "
    },
    {
      " ������� ������1",
      " ������� ������2",
      "   �� ������    "
    },
    {
      " ������� Umax1  ",
      " ������� Umax2  ",
      "    �� Umax     "
    },
    {
      " ������� ������1",
      " ������� ������2",
      "   �� ������    "
    }
  };
  int index_language = index_language_in_array(current_settings.language);
  
  unsigned int position_temp = current_ekran.index_position;
  unsigned int index_of_ekran;
  unsigned int vaga, value, first_symbol;
  
  //�������� �� ��� �������� position_temp ������� ��� ����, �� ����� ������� �� ������������� ��� ����� (����� + ��������)
  index_of_ekran = ((position_temp<<1) >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;
  
  for (unsigned int i=0; i< MAX_ROW_LCD; i++)
  {
    unsigned int index_of_ekran_tmp = index_of_ekran >> 1;
    unsigned int view = ((current_ekran.edition == 0) || (position_temp != index_of_ekran_tmp));
    if (index_of_ekran_tmp < MAX_ROW_FOR_SETPOINT_UMAX)
    {
      if ((i & 0x1) == 0)
      {
        //� ��������� ����� ����� �������� ���������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_language][index_of_ekran_tmp][j];
        if (index_of_ekran_tmp == INDEX_ML_STPUMAX1)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� ������� ��� ������� Umax1
          if (view == true) value = current_settings.setpoint_Umax1[group]; //� ����� value ������� �������� ������� Umax1
          else value = edition_settings.setpoint_Umax1[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STPUMAX2)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� ������� ��� ������� Umax2
          if (view == true) value = current_settings.setpoint_Umax2[group]; //� ����� value ������� �������� ������� Umax2
          else value = edition_settings.setpoint_Umax2[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_KP_UMAX)
        {
          vaga = 100; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.setpoint_kp_Umax[group]; //� ����� value ������� �������� �������
          else value = edition_settings.setpoint_kp_Umax[group];
        }
        first_symbol = 0; //�������, �� �� ����� �������� ������ �� ���������
      }
      else
      {
        //� ������� ����� ����� �������� �������� �������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++)
        {
          if (index_of_ekran_tmp == INDEX_ML_STPUMAX1)
          {
            if (
                ((j < COL_SETPOINT_UMAX1_BEGIN) ||  (j > COL_SETPOINT_UMAX1_END ))  &&
                (j != (COL_SETPOINT_UMAX1_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_SETPOINT_UMAX1_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_SETPOINT_UMAX1_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_V];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_SETPOINT_UMAX1_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STPUMAX2)
          {
            if (
                ((j < COL_SETPOINT_UMAX2_BEGIN) ||  (j > COL_SETPOINT_UMAX2_END ))  &&
                (j != (COL_SETPOINT_UMAX2_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_SETPOINT_UMAX2_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_SETPOINT_UMAX2_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_V];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_SETPOINT_UMAX2_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_KP_UMAX)
          {
            if ((j < COL_SETPOINT_KP_UMAX_BEGIN) ||  (j > COL_SETPOINT_KP_UMAX_END )) working_ekran[i][j] = ' ';
            else if (j == COL_SETPOINT_KP_UMAX_COMMA )working_ekran[i][j] = ',';
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_SETPOINT_KP_UMAX_COMMA, view, 0);
          }
        }
      }
        
    }
    else
      for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = ' ';

    index_of_ekran++;
  }

  //³���������� ������ �� �������� � ������ ������ �� ���� � ��� �� ��������� ������
  current_ekran.position_cursor_y = ((position_temp<<1) + 1) & (MAX_ROW_LCD - 1);
  //������ �� ���������� ������������ �� ������� ������ � �������, ���� �� �� � ����� �����������, ������ ������� ���� ��������� � ������ main_manu_function
  if (current_ekran.edition == 0)
  {
    int last_position_cursor_x = MAX_COL_LCD;
    if (current_ekran.index_position == INDEX_ML_STPUMAX1)
    {
      current_ekran.position_cursor_x = COL_SETPOINT_UMAX1_BEGIN;
      last_position_cursor_x = COL_SETPOINT_UMAX1_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STPUMAX2)
    {
      current_ekran.position_cursor_x = COL_SETPOINT_UMAX2_BEGIN;
      last_position_cursor_x = COL_SETPOINT_UMAX2_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_KP_UMAX)
    {
      current_ekran.position_cursor_x = COL_SETPOINT_KP_UMAX_BEGIN;
      last_position_cursor_x = COL_SETPOINT_KP_UMAX_END;
    }
    
    //ϳ������� ������ �� ������� �������
    while (((working_ekran[current_ekran.position_cursor_y][current_ekran.position_cursor_x + 1]) == ' ') && 
           (current_ekran.position_cursor_x < (last_position_cursor_x -1))) current_ekran.position_cursor_x++;
    
    //������ ������� ���, ��� �� ��� ����� ������
    if (((working_ekran[current_ekran.position_cursor_y][current_ekran.position_cursor_x]) != ' ') && 
        (current_ekran.position_cursor_x > 0)) current_ekran.position_cursor_x--;
  }
  //������ �������
  current_ekran.cursor_on = 1;
  //������ �� ����
  if(current_ekran.edition == 0)current_ekran.cursor_blinking_on = 0;
  else current_ekran.cursor_blinking_on = 1;
  //�������� ������� ���� �����
  current_ekran.current_action = ACTION_WITH_CARRENT_EKRANE_FULL_UPDATE;
}
/*****************************************************/

/*****************************************************/
//������� ����� ����������� �������� Umax
/*****************************************************/
void make_ekran_timeout_Umax(unsigned int group)
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_TIMEOUT_UMAX][MAX_COL_LCD] = 
  {
    {
      "�������� ������1",
      "�������� ������2"
    },
    {
      "�������� ������1",
      "�������� ������2"
    },
    {
      " �������� Umax1 ",
      " �������� Umax2 "
    },
    {
      "�������� ������1",
      "�������� ������2"
    }
  };
  int index_language = index_language_in_array(current_settings.language);
 
  unsigned int position_temp = current_ekran.index_position;
  unsigned int index_of_ekran;
  unsigned int vaga, value, first_symbol;
  
  //�������� �� ��� �������� position_temp ������� ��� ����, �� �� ���� ������� �� ������������� ��� ����� (����� + ��������)
  index_of_ekran = ((position_temp<<1) >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;

  
  for (unsigned int i=0; i< MAX_ROW_LCD; i++)
  {
    unsigned int index_of_ekran_tmp = index_of_ekran >> 1;
    unsigned int view = ((current_ekran.edition == 0) || (position_temp != index_of_ekran_tmp));
    if (index_of_ekran_tmp < MAX_ROW_FOR_TIMEOUT_UMAX)
    {
      if ((i & 0x1) == 0)
      {
        //� ��������� ����� ����� �������� ���������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_language][index_of_ekran_tmp][j];
        if (index_of_ekran_tmp == INDEX_ML_TMOUMAX1)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� ������� ��� �������� Umax1
          if (view == true) value = current_settings.timeout_Umax1[group]; //� ����� value ������� �������� �������� Umax1
          else value = edition_settings.timeout_Umax1[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMOUMAX2)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� ������� ��� �������� Umax2
          if (view == true) value = current_settings.timeout_Umax2[group]; //� ����� value ������� �������� �������� Umax2
          else value = edition_settings.timeout_Umax2[group];
        }
        first_symbol = 0; //�������, �� �� ����� �������� ������ �� ���������
      }
      else
      {
        //� ������� ����� ����� �������� �������� �������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++)
        {
          if (index_of_ekran_tmp == INDEX_ML_TMOUMAX1)
          {
            if (
                ((j < COL_TMO_UMAX1_BEGIN) ||  (j > COL_TMO_UMAX1_END )) &&
                (j != (COL_TMO_UMAX1_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_UMAX1_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_UMAX1_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_UMAX1_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMOUMAX2)
          {
            if (
                ((j < COL_TMO_UMAX2_BEGIN) ||  (j > COL_TMO_UMAX2_END )) &&
                (j != (COL_TMO_UMAX2_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_UMAX2_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_UMAX2_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_UMAX2_COMMA, view, 0);
          }
        }
      }
        
    }
    else
      for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = ' ';

    index_of_ekran++;
  }

  //³���������� ������ �� �������� � ������ ������ �� ���� � ��� �� ��������� ������
  current_ekran.position_cursor_y = ((position_temp<<1) + 1) & (MAX_ROW_LCD - 1);
  //������ �� ���������� ������������ �� ������� ������ � �������, ���� �� �� � ����� �����������, ������ ������� ���� ��������� � ������ main_manu_function
  if (current_ekran.edition == 0)
  {
    int last_position_cursor_x = MAX_COL_LCD;
    if (current_ekran.index_position == INDEX_ML_TMOUMAX1) 
    {
      current_ekran.position_cursor_x = COL_TMO_UMAX1_BEGIN;
      last_position_cursor_x = COL_TMO_UMAX1_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMOUMAX2) 
    {
      current_ekran.position_cursor_x = COL_TMO_UMAX2_BEGIN;
      last_position_cursor_x = COL_TMO_UMAX2_END;
    }

    //ϳ������� ������ �� ������� �������
    while (((working_ekran[current_ekran.position_cursor_y][current_ekran.position_cursor_x + 1]) == ' ') && 
           (current_ekran.position_cursor_x < (last_position_cursor_x -1))) current_ekran.position_cursor_x++;

    //������ ������� ���, ��� �� ��� ����� ������
    if (((working_ekran[current_ekran.position_cursor_y][current_ekran.position_cursor_x]) != ' ') && 
        (current_ekran.position_cursor_x > 0)) current_ekran.position_cursor_x--;
  }
  //������ �������
  current_ekran.cursor_on = 1;
  //������ �� ����
  if(current_ekran.edition == 0)current_ekran.cursor_blinking_on = 0;
  else current_ekran.cursor_blinking_on = 1;
  //�������� ������� ���� �����
  current_ekran.current_action = ACTION_WITH_CARRENT_EKRANE_FULL_UPDATE;
}
/*****************************************************/

/*****************************************************/
//������� ����� ����������� �������� ����������� ���������� ��� Umax
/*****************************************************/
void make_ekran_control_Umax()
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_CONTROL_UMAX][MAX_COL_LCD] = 
  {
    {
      "    ������1     ",
//      "   �� ������1   ",
      "    ������2     ",
//      "   �� ������2   "
    },
    {
      "    ������1     ",
//      "   �� ������1   ",
      "    ������2     ",
//      "   �� ������2   "
    },
    {
      "     Umax1      ",
//      "    �� Umax1    ",
      "     Umax2      ",
//      "    �� Umax2    "
    },
    {
      "    ������1     ",
//      "   �� ������1   ",
      "    ������2     ",
//      "   �� ������2   "
    }
  };
  int index_language = index_language_in_array(current_settings.language);

  int position_temp = current_ekran.index_position;
  int index_of_ekran;

  //�������� �� ��� �������� position_temp ������� ��� ����, �� �� ���� ������� �� ������������� ��� ����� (����� + ��������)
  index_of_ekran = ((position_temp<<1) >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;

  for (unsigned int i=0; i< MAX_ROW_LCD; i++)
  {
    unsigned int index_of_ekran_tmp = index_of_ekran >> 1;
    if (index_of_ekran_tmp < MAX_ROW_FOR_CONTROL_UMAX)
    {
      if ((i & 0x1) == 0)
      {
        //� ��������� ����� ����� �������� ���������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_language][index_of_ekran_tmp][j];
      }
      else
      {
        //� ������� ����� ����� �������� �������� �������
        static const unsigned char information[MAX_ROW_FOR_CONTROL_UMAX][MAX_NAMBER_LANGUAGE][2][MAX_COL_LCD] = 
        {
          {
            {"     ����.      ", "      ���.      "},
            {"     ����.      ", "     ����.     "},
            {"      Off       ", "       On       "},
            {"     њ��.      ", "     ����.      "}
          },
          //?{
          //?  {"      ���       ", "       �        "},
          //?  {"      ���       ", "       �        "},
          //?  {"       OR       ", "      AND       "},
          //?  {"      ���       ", "       �        "}
          //?},
          {
            {"     ����.      ", "      ���.      "},
            {"     ����.      ", "     ����.     "},
            {"      Off       ", "       On       "},
            {"     њ��.      ", "     ����.      "}
          },
          //?{
          //?  {"      ���       ", "       �        "},
          //?  {"      ���       ", "       �        "},
          //?  {"       OR       ", "      AND       "},
          //?  {"      ���       ", "       �        "}
          //?},
        };

        static const unsigned int cursor_x[MAX_ROW_FOR_CONTROL_UMAX][MAX_NAMBER_LANGUAGE][2] = 
        {
          {
            {4, 5},
            {4, 4},
            {5, 6},
            {4, 4}
          },
          //?{
          //?  {5, 6},
          //?  {5, 6},
          //?  {6, 5},
          //?  {5, 6}
          //?},
          {
            {4, 5},
            {4, 4},
            {5, 6},
            {4, 4}
          },
         //? {
         //?   {5, 6},
         //?   {5, 6},
         //?   {6, 5},
         //?   {5, 6}
         //?},
        };

        unsigned int index_ctr = index_of_ekran_tmp;

        unsigned int temp_data;
        if(current_ekran.edition == 0) temp_data = current_settings.control_Umax;
        else temp_data = edition_settings.control_Umax;
        
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = information[index_ctr][index_language][(temp_data >> index_ctr) & 0x1][j];
        if (position_temp == index_of_ekran_tmp) current_ekran.position_cursor_x = cursor_x[index_ctr][index_language][(temp_data >> index_ctr) & 0x1];
      }
    }
    else
      for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = ' ';

    index_of_ekran++;
  }

  //³���������� ������ �� �������� � ������ ������ �� ���� � ��� �� ��������� ������
  current_ekran.position_cursor_y = ((position_temp<<1) + 1) & (MAX_ROW_LCD - 1);
  //������ �������
  current_ekran.cursor_on = 1;
  //������ �� ����
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
