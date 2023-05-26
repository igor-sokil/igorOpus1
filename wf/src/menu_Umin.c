#include "header.h"

/*****************************************************/
//������� ����� ����������� ������� Umin
/*****************************************************/
void make_ekran_setpoint_Umin(unsigned int group)
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_SETPOINT_UMIN][MAX_COL_LCD] = 
  {
    {
      " ������� �����1 ",
      "����.�����1 �� I",
      " ������� �����2 ",
      "����.�����2 �� I"
    },
    {
      " ������� ����1 ",
      "����.����1 �� I",
      " ������� ����2 ",
      "����.����2 �� I"
    },
    {
      " ������� Umin1  ",
      " ����.Umin1 �� I",
      " ������� Umin2  ",
      " ����.Umin2 �� I"
    },
    {
      " ������� �����1 ",
      "����.�����1 �� I",
      " ������� �����2 ",
      "����.�����2 �� I"
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
    if (index_of_ekran_tmp < MAX_ROW_FOR_SETPOINT_UMIN)
    {
      if ((i & 0x1) == 0)
      {
        //� ��������� ����� ����� �������� ���������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_language][index_of_ekran_tmp][j];
        if (index_of_ekran_tmp == INDEX_ML_STPUMIN1)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� ������� ��� ������� Umin1
          if (view == true) value = current_settings.setpoint_Umin1[group]; //� ����� value ������� �������� ������� Umin1
          else value = edition_settings.setpoint_Umin1[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STPUMIN1_IBLK)
        {
          vaga = 1000; //������������ ������� ���������� ��� �������� �������� ������� ��� ������� ���������� Umin1 �� ������
          if (view == true) value = current_settings.setpoint_Umin1_Iblk[group]; //� ����� value ������� �������� ������� ���������� Umin1 �� ������
          else value = edition_settings.setpoint_Umin1_Iblk[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STPUMIN2)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� ������� ��� ������� Umin2
          if (view == true) value = current_settings.setpoint_Umin2[group]; //� ����� value ������� �������� ������� Umin2
          else value = edition_settings.setpoint_Umin2[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STPUMIN2_IBLK)
        {
          vaga = 1000; //������������ ������� ���������� ��� �������� �������� ������� ��� ������� ���������� Umin2 �� ������
          if (view == true) value = current_settings.setpoint_Umin2_Iblk[group]; //� ����� value ������� �������� ������� ���������� Umin2 �� ������
          else value = edition_settings.setpoint_Umin2_Iblk[group];
        }
        first_symbol = 0; //�������, �� �� ����� �������� ������ �� ���������
      }
      else
      {
        //� ������� ����� ����� �������� �������� �������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++)
        {
          if (index_of_ekran_tmp == INDEX_ML_STPUMIN1)
          {
            if (
                ((j < COL_SETPOINT_UMIN1_BEGIN) ||  (j > COL_SETPOINT_UMIN1_END ))  &&
                (j != (COL_SETPOINT_UMIN1_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_SETPOINT_UMIN1_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_SETPOINT_UMIN1_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_V];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_SETPOINT_UMIN1_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STPUMIN1_IBLK)
          {
            if (
                ((j < COL_SETPOINT_UMIN1_IBLK_BEGIN) ||  (j > COL_SETPOINT_UMIN1_IBLK_END ))  &&
                (j != (COL_SETPOINT_UMIN1_IBLK_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_SETPOINT_UMIN1_IBLK_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_SETPOINT_UMIN1_IBLK_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_A];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_SETPOINT_UMIN1_IBLK_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STPUMIN2)
          {
            if (
                ((j < COL_SETPOINT_UMIN2_BEGIN) ||  (j > COL_SETPOINT_UMIN2_END ))  &&
                (j != (COL_SETPOINT_UMIN2_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_SETPOINT_UMIN2_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_SETPOINT_UMIN2_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_V];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_SETPOINT_UMIN2_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STPUMIN2_IBLK)
          {
            if (
                ((j < COL_SETPOINT_UMIN2_IBLK_BEGIN) ||  (j > COL_SETPOINT_UMIN2_IBLK_END ))  &&
                (j != (COL_SETPOINT_UMIN2_IBLK_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_SETPOINT_UMIN2_IBLK_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_SETPOINT_UMIN2_IBLK_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_A];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_SETPOINT_UMIN2_IBLK_COMMA, view, 0);
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
    if (current_ekran.index_position == INDEX_ML_STPUMIN1)
    {
      current_ekran.position_cursor_x = COL_SETPOINT_UMIN1_BEGIN;
      last_position_cursor_x = COL_SETPOINT_UMIN1_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STPUMIN1_IBLK)
    {
      current_ekran.position_cursor_x = COL_SETPOINT_UMIN1_IBLK_BEGIN;
      last_position_cursor_x = COL_SETPOINT_UMIN1_IBLK_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STPUMIN2)
    {
      current_ekran.position_cursor_x = COL_SETPOINT_UMIN2_BEGIN;
      last_position_cursor_x = COL_SETPOINT_UMIN2_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STPUMIN2_IBLK)
    {
      current_ekran.position_cursor_x = COL_SETPOINT_UMIN2_IBLK_BEGIN;
      last_position_cursor_x = COL_SETPOINT_UMIN2_IBLK_END;
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
//������� ����� ����������� �������� Umin
/*****************************************************/
void make_ekran_timeout_Umin(unsigned int group)
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_TIMEOUT_UMIN][MAX_COL_LCD] = 
  {
    {
      " �������� �����1",
      " �������� �����2"
    },
    {
      " �������� ����1",
      " �������� ����2"
    },
    {
      " �������� Umin1 ",
      " �������� Umin2 "
    },
    {
      " �������� �����1",
      " �������� �����2"
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
    if (index_of_ekran_tmp < MAX_ROW_FOR_TIMEOUT_UMIN)
    {
      if ((i & 0x1) == 0)
      {
        //� ��������� ����� ����� �������� ���������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_language][index_of_ekran_tmp][j];
        if (index_of_ekran_tmp == INDEX_ML_TMOUMIN1)
        {
          vaga = 10000; //������������ ������� ���������� ��� �������� �������� ������� ��� �������� Umin1
          if (view == true) value = current_settings.timeout_Umin1[group]; //� ����� value ������� �������� �������� Umin1
          else value = edition_settings.timeout_Umin1[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMOUMIN2)
        {
          vaga = 10000; //������������ ������� ���������� ��� �������� �������� ������� ��� �������� Umin2
          if (view == true) value = current_settings.timeout_Umin2[group]; //� ����� value ������� �������� �������� Umin2
          else value = edition_settings.timeout_Umin2[group];
        }
        first_symbol = 0; //�������, �� �� ����� �������� ������ �� ���������
      }
      else
      {
        //� ������� ����� ����� �������� �������� �������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++)
        {
          if (index_of_ekran_tmp == INDEX_ML_TMOUMIN1)
          {
            if (
                ((j < COL_TMO_UMIN1_BEGIN) ||  (j > COL_TMO_UMIN1_END )) &&
                (j != (COL_TMO_UMIN1_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_UMIN1_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_UMIN1_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_UMIN1_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMOUMIN2)
          {
            if (
                ((j < COL_TMO_UMIN2_BEGIN) ||  (j > COL_TMO_UMIN2_END )) &&
                (j != (COL_TMO_UMIN2_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_UMIN2_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_UMIN2_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_UMIN2_COMMA, view, 0);
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
    if (current_ekran.index_position == INDEX_ML_TMOUMIN1) 
    {
      current_ekran.position_cursor_x = COL_TMO_UMIN1_BEGIN;
      last_position_cursor_x = COL_TMO_UMIN1_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMOUMIN2) 
    {
      current_ekran.position_cursor_x = COL_TMO_UMIN2_BEGIN;
      last_position_cursor_x = COL_TMO_UMIN2_END;
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
//������� ����� ����������� �������� ����������� ���������� ��� Umin
/*****************************************************/
void make_ekran_control_Umin()
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_CONTROL_UMIN][MAX_COL_LCD] = 
  {
    {
      "     �����1     ",
//      "   �� �����1    ",
      "����.�����1 �� U",
      "����.�����1 �� I",
      "     �����2     ",
//      "   �� �����2    ",
      "����.�����2 �� U",
      "����.�����2 �� I"
    },
    {
      "     ����1     ",
//      "   �� ����1    ",
      "����.����1 �� U",
      "����.����1 �� I",
      "     ����2     ",
//      "   �� ����2    ",
      "����.����2 �� U",
      "����.����2 �� I"
    },
    {
      "     Umin1      ",
//      "    �� Umin1    ",
      " ����.Umin1 �� U",
      " ����.Umin1 �� I",
      "     Umin2      ",
//      "    �� Umin2    ",
      " ����.Umin2 �� U",
      " ����.Umin2 �� I"
    },
    {
      "     �����1     ",
//      "   �� �����1    ",
      "����.�����1 �� U",
      "����.�����1 �� I",
      "     �����2     ",
//      "   �� �����2    ",
      "����.�����2 �� U",
      "����.�����2 �� I"
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
    if (index_of_ekran_tmp < MAX_ROW_FOR_CONTROL_UMIN)
    {
      if ((i & 0x1) == 0)
      {
        //� ��������� ����� ����� �������� ���������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_language][index_of_ekran_tmp][j];
      }
      else
      {
        //� ������� ����� ����� �������� �������� �������
        static const unsigned char information[MAX_ROW_FOR_CONTROL_UMIN][MAX_NAMBER_LANGUAGE][2][MAX_COL_LCD] = 
        {
          {
            {"     ����.      ", "      ���.      "},
            {"     ����.      ", "     ����.     "},
            {"      Off       ", "       On       "},
            {"     њ��.      ", "     ����.      "}
          },
          //{
          //  {"      ���       ", "       �        "},
          //  {"      ���       ", "       �        "},
          //  {"       OR       ", "      AND       "},
          //  {"      ���       ", "       �        "}
          //},
          {
            {"     ����.      ", "      ���.      "},
            {"     ����.      ", "     ����.     "},
            {"      Off       ", "       On       "},
            {"     њ��.      ", "     ����.      "}
          },
          {
            {"     ����.      ", "      ���.      "},
            {"     ����.      ", "     ����.     "},
            {"      Off       ", "       On       "},
            {"     њ��.      ", "     ����.      "}
          },
          {
            {"     ����.      ", "      ���.      "},
            {"     ����.      ", "     ����.     "},
            {"      Off       ", "       On       "},
            {"     њ��.      ", "     ����.      "}
          },
          //{
          //  {"      ���       ", "       �        "},
          //  {"      ���       ", "       �        "},
          //  {"       OR       ", "      AND       "},
          //  {"      ���       ", "       �        "}
          //},
          {
            {"     ����.      ", "      ���.      "},
            {"     ����.      ", "     ����.     "},
            {"      Off       ", "       On       "},
            {"     њ��.      ", "     ����.      "}
          },
          {
            {"     ����.      ", "      ���.      "},
            {"     ����.      ", "     ����.     "},
            {"      Off       ", "       On       "},
            {"     њ��.      ", "     ����.      "}
          }
        };
        static const unsigned int cursor_x[MAX_ROW_FOR_CONTROL_UMIN][MAX_NAMBER_LANGUAGE][2] = 
        {
          {
            {4, 5},
            {4, 4},
            {5, 6},
            {4, 4}
          },
          //{
          //  {5, 6},
          //  {5, 6},
          //  {6, 5},
          //  {5, 6}
          //},
          {
            {4, 5},
            {4, 4},
            {5, 6},
            {4, 4}
          },
          {
            {4, 5},
            {4, 4},
            {5, 6},
            {4, 4}
          },
          {
            {4, 5},
            {4, 4},
            {5, 6},
            {4, 4}
          },
          //{
          //  {5, 6},
          //  {5, 6},
          //  {6, 5},
          //  {5, 6}
          //},
          {
            {4, 5},
            {4, 4},
            {5, 6},
            {4, 4}
          },
          {
            {4, 5},
            {4, 4},
            {5, 6},
            {4, 4}
          }
        };

        unsigned int index_ctr = index_of_ekran_tmp;

        unsigned int temp_data;
        if(current_ekran.edition == 0) temp_data = current_settings.control_Umin;
        else temp_data = edition_settings.control_Umin;
  
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
#if INDEX_CTR_PO_UMIN1_OR_AND == INDEX_CTR_PO_UMIN2_OR_AND
#pragma message(" CHECK is PO_UMIN1_OR_AND&PO_UMIN2_OR_AND \
 are not removed from code! ")
#warning PO_UMIN1_OR_AND&PO_UMIN2_OR_AND still in code
#endif
/*****************************************************/
//
/*****************************************************/
/*****************************************************/
