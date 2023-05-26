#include "header.h"

/*****************************************************/
//������� ����� ����������� ������� ���-����
/*****************************************************/
void make_ekran_setpoint_achr_chapv(unsigned int group)
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_SETPOINT_ACHR_CHAPV][MAX_COL_LCD] = 
  {
    {
      "    U���. UF    ",
      "   F���.���1    ",
      "  F���.����1    ",
      "   F���.���2    ",
      "  F���.����2    "
    },
    {
      "    U���. UF    ",
      "   F���.���1    ",
      "  F���.����1    ",
      "   F���.���2    ",
      "  F���.����2    "
    },
    {
      "    U���. UF    ",
      "   F���.���1    ",
      "  F���.����1    ",
      "   F���.���2    ",
      "  F���.����2    "
    },
    {
      "    U���. UF    ",
      "   F���.���1    ",
      "  F���.����1    ",
      "   F���.���2    ",
      "  F���.����2    "
    }
  };
  static const unsigned char hz[MAX_NAMBER_LANGUAGE][2] = {"��", "��", "Hz", "��"};

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
    if (index_of_ekran_tmp < MAX_ROW_FOR_SETPOINT_ACHR_CHAPV)
    {
      if ((i & 0x1) == 0)
      {
        //� ��������� ����� ����� �������� ���������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_language][index_of_ekran_tmp][j];
        if (index_of_ekran_tmp == INDEX_ML_STPACHR_CHAPV_UF)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� ������� ��� �������
          if (view == true) value = current_settings.setpoint_achr_chapv_uf[group]; //� ����� value ������� �������� �������
          else value = edition_settings.setpoint_achr_chapv_uf[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STPACHR1_F_RAB)
        {
          vaga = 1000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.setpoint_achr1_f_rab[group]; //� ����� value ������� �������� �������
          else value = edition_settings.setpoint_achr1_f_rab[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STPCHAPV1_F_RAB)
        {
          vaga = 1000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.setpoint_chapv1_f_rab[group]; //� ����� value ������� �������� �������
          else value = edition_settings.setpoint_chapv1_f_rab[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STPACHR2_F_RAB)
        {
          vaga = 1000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.setpoint_achr2_f_rab[group]; //� ����� value ������� �������� �������
          else value = edition_settings.setpoint_achr2_f_rab[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STPCHAPV2_F_RAB)
        {
          vaga = 1000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.setpoint_chapv2_f_rab[group]; //� ����� value ������� �������� �������
          else value = edition_settings.setpoint_chapv2_f_rab[group];
        }
        first_symbol = 0; //�������, �� �� ����� �������� ������ �� ���������
      }
      else
      {
        //� ������� ����� ����� �������� �������� �������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++)
        {
          if (index_of_ekran_tmp == INDEX_ML_STPACHR_CHAPV_UF)
          {
            if (
                ((j < COL_SETPOINT_ACHR_CHAPV_UF_BEGIN) ||  (j > COL_SETPOINT_ACHR_CHAPV_UF_END ))  &&
                (j != (COL_SETPOINT_ACHR_CHAPV_UF_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j ==COL_SETPOINT_ACHR_CHAPV_UF_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_SETPOINT_ACHR_CHAPV_UF_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_V];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_SETPOINT_ACHR_CHAPV_UF_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STPACHR1_F_RAB)
          {
            if (
                ((j < COL_SETPOINT_ACHR1_F_RAB_BEGIN) ||  (j > COL_SETPOINT_ACHR1_F_RAB_END )) &&
                (
                 !((j >= (COL_SETPOINT_ACHR1_F_RAB_END + 2)) && (j <= (COL_SETPOINT_ACHR1_F_RAB_END + 3)))
                )    
               )working_ekran[i][j] = ' ';
            else if (j == COL_SETPOINT_ACHR1_F_RAB_COMMA )working_ekran[i][j] = ',';
            else if ((j >= (COL_SETPOINT_ACHR1_F_RAB_END + 2)) && (j <= (COL_SETPOINT_ACHR1_F_RAB_END + 3)))
              working_ekran[i][j] = hz[index_language][j - (COL_SETPOINT_ACHR1_F_RAB_END + 2)];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_SETPOINT_ACHR1_F_RAB_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STPCHAPV1_F_RAB)
          {
            if (
                ((j < COL_SETPOINT_CHAPV1_F_RAB_BEGIN) ||  (j > COL_SETPOINT_CHAPV1_F_RAB_END )) &&
                (
                 !((j >= (COL_SETPOINT_CHAPV1_F_RAB_END + 2)) && (j <= (COL_SETPOINT_CHAPV1_F_RAB_END + 3)))
                )    
               )working_ekran[i][j] = ' ';
            else if (j == COL_SETPOINT_CHAPV1_F_RAB_COMMA )working_ekran[i][j] = ',';
            else if ((j >= (COL_SETPOINT_CHAPV1_F_RAB_END + 2)) && (j <= (COL_SETPOINT_CHAPV1_F_RAB_END + 3)))
              working_ekran[i][j] = hz[index_language][j - (COL_SETPOINT_CHAPV1_F_RAB_END + 2)];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_SETPOINT_CHAPV1_F_RAB_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STPACHR2_F_RAB)
          {
            if (
                ((j < COL_SETPOINT_ACHR2_F_RAB_BEGIN) ||  (j > COL_SETPOINT_ACHR2_F_RAB_END )) &&
                (
                 !((j >= (COL_SETPOINT_ACHR2_F_RAB_END + 2)) && (j <= (COL_SETPOINT_ACHR2_F_RAB_END + 3)))
                )    
               )working_ekran[i][j] = ' ';
            else if (j == COL_SETPOINT_ACHR2_F_RAB_COMMA )working_ekran[i][j] = ',';
            else if ((j >= (COL_SETPOINT_ACHR2_F_RAB_END + 2)) && (j <= (COL_SETPOINT_ACHR2_F_RAB_END + 3)))
              working_ekran[i][j] = hz[index_language][j - (COL_SETPOINT_ACHR2_F_RAB_END + 2)];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_SETPOINT_ACHR2_F_RAB_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STPCHAPV2_F_RAB)
          {
            if (
                ((j < COL_SETPOINT_CHAPV2_F_RAB_BEGIN) ||  (j > COL_SETPOINT_CHAPV2_F_RAB_END )) &&
                (
                 !((j >= (COL_SETPOINT_CHAPV2_F_RAB_END + 2)) && (j <= (COL_SETPOINT_CHAPV2_F_RAB_END + 3)))
                )    
               )working_ekran[i][j] = ' ';
            else if (j == COL_SETPOINT_CHAPV2_F_RAB_COMMA )working_ekran[i][j] = ',';
            else if ((j >= (COL_SETPOINT_CHAPV2_F_RAB_END + 2)) && (j <= (COL_SETPOINT_CHAPV2_F_RAB_END + 3)))
              working_ekran[i][j] = hz[index_language][j - (COL_SETPOINT_CHAPV2_F_RAB_END + 2)];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_SETPOINT_CHAPV2_F_RAB_COMMA, view, 0);
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
    if (current_ekran.index_position == INDEX_ML_STPACHR_CHAPV_UF)
    {
      current_ekran.position_cursor_x = COL_SETPOINT_ACHR_CHAPV_UF_BEGIN;
      last_position_cursor_x = COL_SETPOINT_ACHR_CHAPV_UF_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STPACHR1_F_RAB)
    {
      current_ekran.position_cursor_x = COL_SETPOINT_ACHR1_F_RAB_BEGIN;
      last_position_cursor_x = COL_SETPOINT_ACHR1_F_RAB_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STPCHAPV1_F_RAB)
    {
      current_ekran.position_cursor_x = COL_SETPOINT_CHAPV1_F_RAB_BEGIN;
      last_position_cursor_x = COL_SETPOINT_CHAPV1_F_RAB_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STPACHR2_F_RAB)
    {
      current_ekran.position_cursor_x = COL_SETPOINT_ACHR2_F_RAB_BEGIN;
      last_position_cursor_x = COL_SETPOINT_ACHR2_F_RAB_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STPCHAPV2_F_RAB)
    {
      current_ekran.position_cursor_x = COL_SETPOINT_CHAPV2_F_RAB_BEGIN;
      last_position_cursor_x = COL_SETPOINT_CHAPV2_F_RAB_END;
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
//������� ����� ����������� �������� ���-����
/*****************************************************/
void make_ekran_timeout_achr_chapv(unsigned int group)
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_TIMEOUT_ACHR_CHAPV][MAX_COL_LCD] = 
  {
    {
      " �������� ���1  ",
      " �������� ����1 ",
      " �������� ���2  ",
      " �������� ����2 "
    },
    {
      " �������� ���1  ",
      " �������� ����1 ",
      " �������� ���2  ",
      " �������� ����2 "
    },
    {
      " �������� ���1  ",
      " �������� ����1 ",
      " �������� ���2  ",
      " �������� ����2 "
    },
    {
      " �������� ���1  ",
      " �������� ����1 ",
      " �������� ���2  ",
      " �������� ����2 "
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
    if (index_of_ekran_tmp < MAX_ROW_FOR_TIMEOUT_ACHR_CHAPV)
    {
      if ((i & 0x1) == 0)
      {
        //� ��������� ����� ����� �������� ���������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_language][index_of_ekran_tmp][j];
        if (index_of_ekran_tmp == INDEX_ML_TMOACHR1)
        {
          vaga = 10000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_achr_1[group];
          else value = edition_settings.timeout_achr_1[group];
          first_symbol = 0; //�������, �� �� ����� �������� ������ �� ���������
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMOCHAPV1)
        {
          vaga = 10000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_chapv_1[group];
          else value = edition_settings.timeout_chapv_1[group];
          first_symbol = 0; //�������, �� �� ����� �������� ������ �� ���������
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMOACHR2)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_achr_2[group];
          else value = edition_settings.timeout_achr_2[group];
          first_symbol = 0; //�������, �� �� ����� �������� ������ �� ���������
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMOCHAPV2)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_chapv_2[group];
          else value = edition_settings.timeout_chapv_2[group];
          first_symbol = 0; //�������, �� �� ����� �������� ������ �� ���������
        }
      }
      else
      {
        //� ������� ����� ����� �������� ��������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++)
        {
          if (index_of_ekran_tmp == INDEX_ML_TMOACHR1)
          {
            if (
                ((j < COL_TMO_ACHR1_BEGIN) ||  (j > COL_TMO_ACHR1_END )) &&
                (j != (COL_TMO_ACHR1_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_ACHR1_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_ACHR1_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_ACHR1_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMOCHAPV1)
          {
            if (
                ((j < COL_TMO_CHAPV1_BEGIN) ||  (j > COL_TMO_CHAPV1_END )) &&
                (j != (COL_TMO_CHAPV1_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_CHAPV1_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_CHAPV1_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_CHAPV1_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMOACHR2)
          {
            if (
                ((j < COL_TMO_ACHR2_BEGIN) ||  (j > COL_TMO_ACHR2_END )) &&
                (j != (COL_TMO_ACHR2_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_ACHR2_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_ACHR2_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_ACHR2_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMOCHAPV2)
          {
            if (
                ((j < COL_TMO_CHAPV2_BEGIN) ||  (j > COL_TMO_CHAPV2_END )) &&
                (j != (COL_TMO_CHAPV2_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_CHAPV2_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_CHAPV2_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_CHAPV2_COMMA, view, 0);
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
    if (current_ekran.index_position == INDEX_ML_TMOACHR1)
    {
      current_ekran.position_cursor_x = COL_TMO_ACHR1_BEGIN;
      last_position_cursor_x = COL_TMO_ACHR1_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMOCHAPV1)
    {
      current_ekran.position_cursor_x = COL_TMO_CHAPV1_BEGIN;
      last_position_cursor_x = COL_TMO_CHAPV1_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMOACHR2)
    {
      current_ekran.position_cursor_x = COL_TMO_ACHR2_BEGIN;
      last_position_cursor_x = COL_TMO_ACHR2_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMOCHAPV2)
    {
      current_ekran.position_cursor_x = COL_TMO_CHAPV2_BEGIN;
      last_position_cursor_x = COL_TMO_CHAPV2_END;
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
//������� ����� ����������� �������� ����������� ���������� ��� ���-����
/*****************************************************/
void make_ekran_control_achr_chapv()
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_CONTROL_ACHR_CHAPV][MAX_COL_LCD] = 
  {
    {
      "   ���� �� ��   ",
      "      ���1      ",
      "     ����1      ",
      "      ���2      ",
      "     ����2      "
    },
    {
      "  ���� �� ��   ",
      "      ���1      ",
      "     ����1      ",
      "      ���2      ",
      "     ����2      "
    },
    {
      "   ���� �� ��   ",
      "     UFLS1      ",
      "      FAR1      ",
      "     UFLS2      ",
      "      FAR2      "
    },
    {
      "   ���� �� ��   ",
      "      ���1      ",
      "     ����1      ",
      "      ���2      ",
      "     ����2      "
    }
  };
  int index_language = index_language_in_array(current_settings.language);
  
  unsigned int position_temp = current_ekran.index_position;
  unsigned int index_of_ekran;
  
  //�������� �� ��� �������� position_temp ������� ��� ����, �� �� ���� ������� �� ������������� ��� ����� (����� + ��������)
  index_of_ekran = ((position_temp<<1) >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;

  
  for (unsigned int i=0; i< MAX_ROW_LCD; i++)
  {
    unsigned int index_of_ekran_tmp = index_of_ekran >> 1;
    if (index_of_ekran_tmp < MAX_ROW_FOR_CONTROL_ACHR_CHAPV)
    {
      if ((i & 0x1) == 0)
      {
        //� ��������� ����� ����� �������� ���������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_language][index_of_ekran_tmp][j];
      }
      else
      {
        //� ������� ����� ����� �������� �������� �������
        unsigned int index_ctr = index_of_ekran_tmp;

        unsigned int temp_data;
          
        if(current_ekran.edition == 0) temp_data = current_settings.control_achr_chapv;
        else temp_data = edition_settings.control_achr_chapv;
          
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = information_off_on[index_language][(temp_data >> index_ctr) & 0x1][j];
        if (position_temp == index_of_ekran_tmp) current_ekran.position_cursor_x = cursor_x_off_on[index_language][(temp_data >> index_ctr) & 0x1];
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
