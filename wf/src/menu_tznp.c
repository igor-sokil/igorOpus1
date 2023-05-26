#include "header.h"

/*****************************************************/
//������� ����� ����������� ������� ����
/*****************************************************/
void make_ekran_setpoint_tznp(unsigned int group)
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_SETPOINT_TZNP][MAX_COL_LCD] = 
  {
    {
      "3I0 ����1 ������",
      "3U0 ����1 ������",
      " 3I0 ����1 ���. ",
      " 3U0 ����1 ���. ",
      " ���� ���.����1 ",
      "3I0 ����2 ������",
      "3U0 ����2 ������",
      " 3I0 ����2 ���. ",
      " 3U0 ����2 ���. ",
      " ���� ���.����2 ",
      "3I0 ����3 ������",
      "3U0 ����3 ������",
      " 3I0 ����3 ���. ",
      " 3U0 ����3 ���. ",
      " ���� ���.����3 "
    },
    {
      "3I0 ����1 ������",
      "3U0 ����1 ������",
      " 3I0 ����1 ����.",
      " 3U0 ����1 ����.",
      " ��� ���.����1  ",
      "3I0 ����2 ������",
      "3U0 ����2 ������",
      " 3I0 ����2 ����.",
      " 3U0 ����2 ����.",
      " ��� ���.����2  ",
      "3I0 ����3 ������",
      "3U0 ����3 ������",
      " 3I0 ����3 ����.",
      " 3U0 ����3 ����.",
      " ��� ���.����3  "
    },
    {
      "3I0 ����1 ������",
      "3U0 ����1 ������",
      " 3I0 ����1 ���. ",
      " 3U0 ����1 ���. ",
      " ���� ���.����1 ",
      "3I0 ����2 ������",
      "3U0 ����2 ������",
      " 3I0 ����2 ���. ",
      " 3U0 ����2 ���. ",
      " ���� ���.����2 ",
      "3I0 ����3 ������",
      "3U0 ����3 ������",
      " 3I0 ����3 ���. ",
      " 3U0 ����3 ���. ",
      " ���� ���.����3 "
    },
    {
      "3I0 ����1 ������",
      "3U0 ����1 ������",
      " 3I0 ����1 ���. ",
      " 3U0 ����1 ���. ",
      " ���� ���.����1 ",
      "3I0 ����2 ������",
      "3U0 ����2 ������",
      " 3I0 ����2 ���. ",
      " 3U0 ����2 ���. ",
      " ���� ���.����2 ",
      "3I0 ����3 ������",
      "3U0 ����3 ������",
      " 3I0 ����3 ���. ",
      " 3U0 ����3 ���. ",
      " ���� ���.����3 "
    },
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
    if (index_of_ekran_tmp < MAX_ROW_FOR_SETPOINT_TZNP)
    {
      if ((i & 0x1) == 0)
      {
        //� ��������� ����� ����� �������� ���������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_language][index_of_ekran_tmp][j];
        if (index_of_ekran_tmp == INDEX_ML_STPTZNP1_3I0_VPERED)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.setpoint_tznp_1_3I0_vpered[group]; //� ����� value ������� �������� �������
          else value = edition_settings.setpoint_tznp_1_3I0_vpered[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STPTZNP1_3U0_VPERED)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.setpoint_tznp_1_3U0_vpered[group]; //� ����� value ������� �������� �������
          else value = edition_settings.setpoint_tznp_1_3U0_vpered[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STPTZNP1_3I0_NAZAD)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.setpoint_tznp_1_3I0_nazad[group]; //� ����� value ������� �������� �������
          else value = edition_settings.setpoint_tznp_1_3I0_nazad[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STPTZNP1_3U0_NAZAD)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.setpoint_tznp_1_3U0_nazad[group]; //� ����� value ������� �������� �������
          else value = edition_settings.setpoint_tznp_1_3U0_nazad[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STPTZNP1_ANGLE)
        {
          vaga = 10; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.setpoint_tznp_1_angle[group]; //� ����� value ������� �������� �������
          else value = edition_settings.setpoint_tznp_1_angle[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STPTZNP2_3I0_VPERED)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.setpoint_tznp_2_3I0_vpered[group]; //� ����� value ������� �������� �������
          else value = edition_settings.setpoint_tznp_2_3I0_vpered[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STPTZNP2_3U0_VPERED)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.setpoint_tznp_2_3U0_vpered[group]; //� ����� value ������� �������� �������
          else value = edition_settings.setpoint_tznp_2_3U0_vpered[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STPTZNP2_3I0_NAZAD)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.setpoint_tznp_2_3I0_nazad[group]; //� ����� value ������� �������� �������
          else value = edition_settings.setpoint_tznp_2_3I0_nazad[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STPTZNP2_3U0_NAZAD)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.setpoint_tznp_2_3U0_nazad[group]; //� ����� value ������� �������� �������
          else value = edition_settings.setpoint_tznp_2_3U0_nazad[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STPTZNP2_ANGLE)
        {
          vaga = 10; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.setpoint_tznp_2_angle[group]; //� ����� value ������� �������� �������
          else value = edition_settings.setpoint_tznp_2_angle[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STPTZNP3_3I0_VPERED)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.setpoint_tznp_3_3I0_vpered[group]; //� ����� value ������� �������� �������
          else value = edition_settings.setpoint_tznp_3_3I0_vpered[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STPTZNP3_3U0_VPERED)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.setpoint_tznp_3_3U0_vpered[group]; //� ����� value ������� �������� �������
          else value = edition_settings.setpoint_tznp_3_3U0_vpered[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STPTZNP3_3I0_NAZAD)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.setpoint_tznp_3_3I0_nazad[group]; //� ����� value ������� �������� �������
          else value = edition_settings.setpoint_tznp_3_3I0_nazad[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STPTZNP3_3U0_NAZAD)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.setpoint_tznp_3_3U0_nazad[group]; //� ����� value ������� �������� �������
          else value = edition_settings.setpoint_tznp_3_3U0_nazad[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STPTZNP3_ANGLE)
        {
          vaga = 10; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.setpoint_tznp_3_angle[group]; //� ����� value ������� �������� �������
          else value = edition_settings.setpoint_tznp_3_angle[group];
        }
        
        first_symbol = 0; //�������, �� �� ����� �������� ������ �� ���������
      }
      else
      {
        //� ������� ����� ����� �������� �������� �������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++)
        {
          if (index_of_ekran_tmp == INDEX_ML_STPTZNP1_3I0_VPERED)
          {
            if (
                ((j < COL_SETPOINT_TZNP1_3I0_VPERED_BEGIN) ||  (j > COL_SETPOINT_TZNP1_3I0_VPERED_END ))  &&
                (j != (COL_SETPOINT_TZNP1_3I0_VPERED_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_SETPOINT_TZNP1_3I0_VPERED_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_SETPOINT_TZNP1_3I0_VPERED_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_A];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_SETPOINT_TZNP1_3I0_VPERED_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STPTZNP1_3U0_VPERED)
          {
            if (
                ((j < COL_SETPOINT_TZNP1_3U0_VPERED_BEGIN) ||  (j > COL_SETPOINT_TZNP1_3U0_VPERED_END ))  &&
                (j != (COL_SETPOINT_TZNP1_3U0_VPERED_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_SETPOINT_TZNP1_3U0_VPERED_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_SETPOINT_TZNP1_3U0_VPERED_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_V];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_SETPOINT_TZNP1_3U0_VPERED_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STPTZNP1_3I0_NAZAD)
          {
            if (
                ((j < COL_SETPOINT_TZNP1_3I0_NAZAD_BEGIN) ||  (j > COL_SETPOINT_TZNP1_3I0_NAZAD_END ))  &&
                (j != (COL_SETPOINT_TZNP1_3I0_NAZAD_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_SETPOINT_TZNP1_3I0_NAZAD_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_SETPOINT_TZNP1_3I0_NAZAD_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_A];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_SETPOINT_TZNP1_3I0_NAZAD_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STPTZNP1_3U0_NAZAD)
          {
            if (
                ((j < COL_SETPOINT_TZNP1_3U0_NAZAD_BEGIN) ||  (j > COL_SETPOINT_TZNP1_3U0_NAZAD_END ))  &&
                (j != (COL_SETPOINT_TZNP1_3U0_NAZAD_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_SETPOINT_TZNP1_3U0_NAZAD_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_SETPOINT_TZNP1_3U0_NAZAD_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_V];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_SETPOINT_TZNP1_3U0_NAZAD_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STPTZNP1_ANGLE)
          {
            if (
                ((j < COL_SETPOINT_TZNP1_ANGLE_BEGIN) ||  (j > COL_SETPOINT_TZNP1_ANGLE_END ))  &&
                (j != (COL_SETPOINT_TZNP1_ANGLE_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == (COL_SETPOINT_TZNP1_ANGLE_END + 2)) working_ekran[i][j] = '�';
            else
              calc_int_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, view);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STPTZNP2_3I0_VPERED)
          {
            if (
                ((j < COL_SETPOINT_TZNP2_3I0_VPERED_BEGIN) ||  (j > COL_SETPOINT_TZNP2_3I0_VPERED_END ))  &&
                (j != (COL_SETPOINT_TZNP2_3I0_VPERED_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_SETPOINT_TZNP2_3I0_VPERED_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_SETPOINT_TZNP2_3I0_VPERED_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_A];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_SETPOINT_TZNP2_3I0_VPERED_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STPTZNP2_3U0_VPERED)
          {
            if (
                ((j < COL_SETPOINT_TZNP2_3U0_VPERED_BEGIN) ||  (j > COL_SETPOINT_TZNP2_3U0_VPERED_END ))  &&
                (j != (COL_SETPOINT_TZNP2_3U0_VPERED_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_SETPOINT_TZNP2_3U0_VPERED_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_SETPOINT_TZNP2_3U0_VPERED_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_V];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_SETPOINT_TZNP2_3U0_VPERED_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STPTZNP2_3I0_NAZAD)
          {
            if (
                ((j < COL_SETPOINT_TZNP2_3I0_NAZAD_BEGIN) ||  (j > COL_SETPOINT_TZNP2_3I0_NAZAD_END ))  &&
                (j != (COL_SETPOINT_TZNP2_3I0_NAZAD_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_SETPOINT_TZNP2_3I0_NAZAD_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_SETPOINT_TZNP2_3I0_NAZAD_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_A];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_SETPOINT_TZNP2_3I0_NAZAD_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STPTZNP2_3U0_NAZAD)
          {
            if (
                ((j < COL_SETPOINT_TZNP2_3U0_NAZAD_BEGIN) ||  (j > COL_SETPOINT_TZNP2_3U0_NAZAD_END ))  &&
                (j != (COL_SETPOINT_TZNP2_3U0_NAZAD_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_SETPOINT_TZNP2_3U0_NAZAD_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_SETPOINT_TZNP2_3U0_NAZAD_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_V];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_SETPOINT_TZNP2_3U0_NAZAD_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STPTZNP2_ANGLE)
          {
            if (
                ((j < COL_SETPOINT_TZNP2_ANGLE_BEGIN) ||  (j > COL_SETPOINT_TZNP2_ANGLE_END ))  &&
                (j != (COL_SETPOINT_TZNP2_ANGLE_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == (COL_SETPOINT_TZNP2_ANGLE_END + 2)) working_ekran[i][j] = '�';
            else
              calc_int_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, view);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STPTZNP3_3I0_VPERED)
          {
            if (
                ((j < COL_SETPOINT_TZNP3_3I0_VPERED_BEGIN) ||  (j > COL_SETPOINT_TZNP3_3I0_VPERED_END ))  &&
                (j != (COL_SETPOINT_TZNP3_3I0_VPERED_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_SETPOINT_TZNP3_3I0_VPERED_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_SETPOINT_TZNP3_3I0_VPERED_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_A];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_SETPOINT_TZNP3_3I0_VPERED_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STPTZNP3_3U0_VPERED)
          {
            if (
                ((j < COL_SETPOINT_TZNP3_3U0_VPERED_BEGIN) ||  (j > COL_SETPOINT_TZNP3_3U0_VPERED_END ))  &&
                (j != (COL_SETPOINT_TZNP3_3U0_VPERED_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_SETPOINT_TZNP3_3U0_VPERED_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_SETPOINT_TZNP3_3U0_VPERED_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_V];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_SETPOINT_TZNP3_3U0_VPERED_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STPTZNP3_3I0_NAZAD)
          {
            if (
                ((j < COL_SETPOINT_TZNP3_3I0_NAZAD_BEGIN) ||  (j > COL_SETPOINT_TZNP3_3I0_NAZAD_END ))  &&
                (j != (COL_SETPOINT_TZNP3_3I0_NAZAD_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_SETPOINT_TZNP3_3I0_NAZAD_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_SETPOINT_TZNP3_3I0_NAZAD_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_A];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_SETPOINT_TZNP3_3I0_NAZAD_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STPTZNP3_3U0_NAZAD)
          {
            if (
                ((j < COL_SETPOINT_TZNP3_3U0_NAZAD_BEGIN) ||  (j > COL_SETPOINT_TZNP3_3U0_NAZAD_END ))  &&
                (j != (COL_SETPOINT_TZNP3_3U0_NAZAD_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_SETPOINT_TZNP3_3U0_NAZAD_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_SETPOINT_TZNP3_3U0_NAZAD_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_V];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_SETPOINT_TZNP3_3U0_NAZAD_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STPTZNP3_ANGLE)
          {
            if (
                ((j < COL_SETPOINT_TZNP3_ANGLE_BEGIN) ||  (j > COL_SETPOINT_TZNP3_ANGLE_END ))  &&
                (j != (COL_SETPOINT_TZNP3_ANGLE_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == (COL_SETPOINT_TZNP3_ANGLE_END + 2)) working_ekran[i][j] = '�';
            else
              calc_int_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, view);
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
    if (current_ekran.index_position == INDEX_ML_STPTZNP1_3I0_VPERED)
    {
      current_ekran.position_cursor_x = COL_SETPOINT_TZNP1_3I0_VPERED_BEGIN;
      last_position_cursor_x = COL_SETPOINT_TZNP1_3I0_VPERED_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STPTZNP1_3U0_VPERED)
    {
      current_ekran.position_cursor_x = COL_SETPOINT_TZNP1_3U0_VPERED_BEGIN;
      last_position_cursor_x = COL_SETPOINT_TZNP1_3U0_VPERED_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STPTZNP1_3I0_NAZAD)
    {
      current_ekran.position_cursor_x = COL_SETPOINT_TZNP1_3I0_NAZAD_BEGIN;
      last_position_cursor_x = COL_SETPOINT_TZNP1_3I0_NAZAD_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STPTZNP1_3U0_NAZAD)
    {
      current_ekran.position_cursor_x = COL_SETPOINT_TZNP1_3U0_NAZAD_BEGIN;
      last_position_cursor_x = COL_SETPOINT_TZNP1_3U0_NAZAD_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STPTZNP1_ANGLE)
    {
      current_ekran.position_cursor_x = COL_SETPOINT_TZNP1_ANGLE_BEGIN;
      last_position_cursor_x = COL_SETPOINT_TZNP1_ANGLE_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STPTZNP2_3I0_VPERED)
    {
      current_ekran.position_cursor_x = COL_SETPOINT_TZNP2_3I0_VPERED_BEGIN;
      last_position_cursor_x = COL_SETPOINT_TZNP2_3I0_VPERED_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STPTZNP2_3U0_VPERED)
    {
      current_ekran.position_cursor_x = COL_SETPOINT_TZNP2_3U0_VPERED_BEGIN;
      last_position_cursor_x = COL_SETPOINT_TZNP2_3U0_VPERED_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STPTZNP2_3I0_NAZAD)
    {
      current_ekran.position_cursor_x = COL_SETPOINT_TZNP2_3I0_NAZAD_BEGIN;
      last_position_cursor_x = COL_SETPOINT_TZNP2_3I0_NAZAD_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STPTZNP2_3U0_NAZAD)
    {
      current_ekran.position_cursor_x = COL_SETPOINT_TZNP2_3U0_NAZAD_BEGIN;
      last_position_cursor_x = COL_SETPOINT_TZNP2_3U0_NAZAD_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STPTZNP2_ANGLE)
    {
      current_ekran.position_cursor_x = COL_SETPOINT_TZNP2_ANGLE_BEGIN;
      last_position_cursor_x = COL_SETPOINT_TZNP2_ANGLE_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STPTZNP3_3I0_VPERED)
    {
      current_ekran.position_cursor_x = COL_SETPOINT_TZNP3_3I0_VPERED_BEGIN;
      last_position_cursor_x = COL_SETPOINT_TZNP3_3I0_VPERED_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STPTZNP3_3U0_VPERED)
    {
      current_ekran.position_cursor_x = COL_SETPOINT_TZNP3_3U0_VPERED_BEGIN;
      last_position_cursor_x = COL_SETPOINT_TZNP3_3U0_VPERED_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STPTZNP3_3I0_NAZAD)
    {
      current_ekran.position_cursor_x = COL_SETPOINT_TZNP3_3I0_NAZAD_BEGIN;
      last_position_cursor_x = COL_SETPOINT_TZNP3_3I0_NAZAD_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STPTZNP3_3U0_NAZAD)
    {
      current_ekran.position_cursor_x = COL_SETPOINT_TZNP3_3U0_NAZAD_BEGIN;
      last_position_cursor_x = COL_SETPOINT_TZNP3_3U0_NAZAD_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STPTZNP3_ANGLE)
    {
      current_ekran.position_cursor_x = COL_SETPOINT_TZNP3_ANGLE_BEGIN;
      last_position_cursor_x = COL_SETPOINT_TZNP3_ANGLE_END;
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
//������� ����� ����������� �������� ����
/*****************************************************/
void make_ekran_timeout_tznp(unsigned int group)
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_TIMEOUT_TZNP][MAX_COL_LCD] = 
  {
    {
      "  ����1 ������  ",
      " ����1 �������� ",
      "  ����2 ������  ",
      " ����2 �������� ",
      "  ����3 ������  ",
      " ����3 �������� "
    },
    {
      "  ����1 ������  ",
      " ����1 ��������",
      "  ����2 ������  ",
      " ����2 ��������",
      "  ����3 ������  ",
      " ����3 ��������",
    },
    {
      "  ����1 ������  ",
      " ����1 �������� ",
      "  ����2 ������  ",
      " ����2 �������� ",
      "  ����3 ������  ",
      " ����3 �������� "
    },
    {
      "  ����1 ������  ",
      " ����1 �������� ",
      "  ����2 ������  ",
      " ����2 �������� ",
      "  ����3 ������  ",
      " ����3 �������� "
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
    if (index_of_ekran_tmp < MAX_ROW_FOR_TIMEOUT_TZNP)
    {
      if ((i & 0x1) == 0)
      {
        //� ��������� ����� ����� �������� ���������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_language][index_of_ekran_tmp][j];
        if (index_of_ekran_tmp == INDEX_ML_TMOTZNP1_VPERED)
        {
          vaga = 10000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_tznp_1_vpered[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_tznp_1_vpered[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMOTZNP1_NAZAD)
        {
          vaga = 10000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_tznp_1_nazad[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_tznp_1_nazad[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMOTZNP2_VPERED)
        {
          vaga = 10000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_tznp_2_vpered[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_tznp_2_vpered[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMOTZNP2_NAZAD)
        {
          vaga = 10000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_tznp_2_nazad[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_tznp_2_nazad[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMOTZNP3_VPERED)
        {
          vaga = 10000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_tznp_3_vpered[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_tznp_3_vpered[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMOTZNP3_NAZAD)
        {
          vaga = 10000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_tznp_3_nazad[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_tznp_3_nazad[group];
        }

        first_symbol = 0; //�������, �� �� ����� �������� ������ �� ���������
      }
      else
      {
        //� ������� ����� ����� �������� �������� �������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++)
        {
          if (index_of_ekran_tmp == INDEX_ML_TMOTZNP1_VPERED)
          {
            if (
                ((j < COL_TMO_TZNP1_VPERED_BEGIN) ||  (j > COL_TMO_TZNP1_VPERED_END )) &&
                (j != (COL_TMO_TZNP1_VPERED_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_TZNP1_VPERED_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_TZNP1_VPERED_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_TZNP1_VPERED_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMOTZNP1_NAZAD)
          {
            if (
                ((j < COL_TMO_TZNP1_NAZAD_BEGIN) ||  (j > COL_TMO_TZNP1_NAZAD_END )) &&
                (j != (COL_TMO_TZNP1_NAZAD_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_TZNP1_NAZAD_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_TZNP1_NAZAD_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_TZNP1_NAZAD_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMOTZNP2_VPERED)
          {
            if (
                ((j < COL_TMO_TZNP2_VPERED_BEGIN) ||  (j > COL_TMO_TZNP2_VPERED_END )) &&
                (j != (COL_TMO_TZNP2_VPERED_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_TZNP2_VPERED_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_TZNP2_VPERED_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_TZNP2_VPERED_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMOTZNP2_NAZAD)
          {
            if (
                ((j < COL_TMO_TZNP2_NAZAD_BEGIN) ||  (j > COL_TMO_TZNP2_NAZAD_END )) &&
                (j != (COL_TMO_TZNP2_NAZAD_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_TZNP2_NAZAD_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_TZNP2_NAZAD_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_TZNP2_NAZAD_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMOTZNP3_VPERED)
          {
            if (
                ((j < COL_TMO_TZNP3_VPERED_BEGIN) ||  (j > COL_TMO_TZNP3_VPERED_END )) &&
                (j != (COL_TMO_TZNP3_VPERED_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_TZNP3_VPERED_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_TZNP3_VPERED_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_TZNP3_VPERED_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMOTZNP3_NAZAD)
          {
            if (
                ((j < COL_TMO_TZNP3_NAZAD_BEGIN) ||  (j > COL_TMO_TZNP3_NAZAD_END )) &&
                (j != (COL_TMO_TZNP3_NAZAD_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_TZNP3_NAZAD_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_TZNP3_NAZAD_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_TZNP3_NAZAD_COMMA, view, 0);
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
    if (current_ekran.index_position == INDEX_ML_TMOTZNP1_VPERED) 
    {
      current_ekran.position_cursor_x = COL_TMO_TZNP1_VPERED_BEGIN;
      last_position_cursor_x = COL_TMO_TZNP1_VPERED_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMOTZNP1_NAZAD) 
    {
      current_ekran.position_cursor_x = COL_TMO_TZNP1_NAZAD_BEGIN;
      last_position_cursor_x = COL_TMO_TZNP1_NAZAD_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMOTZNP2_VPERED) 
    {
      current_ekran.position_cursor_x = COL_TMO_TZNP2_VPERED_BEGIN;
      last_position_cursor_x = COL_TMO_TZNP2_VPERED_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMOTZNP2_NAZAD) 
    {
      current_ekran.position_cursor_x = COL_TMO_TZNP2_NAZAD_BEGIN;
      last_position_cursor_x = COL_TMO_TZNP2_NAZAD_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMOTZNP3_VPERED) 
    {
      current_ekran.position_cursor_x = COL_TMO_TZNP3_VPERED_BEGIN;
      last_position_cursor_x = COL_TMO_TZNP3_VPERED_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMOTZNP3_NAZAD) 
    {
      current_ekran.position_cursor_x = COL_TMO_TZNP3_NAZAD_BEGIN;
      last_position_cursor_x = COL_TMO_TZNP3_NAZAD_END;
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
//������� ����� ����������� �������� ����������� ���������� ��� ����
/*****************************************************/
void make_ekran_control_tznp()
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_CONTROL_TZNP][MAX_COL_LCD] = 
  {
    {
      "     ����1      ",
      "  ����1 ������  ",
      " ����1 �������� ",
      "     ����2      ",
      "  ����2 ������  ",
      " ����2 �������� ",
      "     ����3      ",
      "  ����3 ������  ",
      " ����3 �������� "
    },
    {
      "     ����1      ",
      "  ����1 ������  ",
      " ����1 ��������",
      "     ����2      ",
      "  ����2 ������  ",
      " ����2 ��������",
      "     ����3      ",
      "  ����3 ������  ",
      " ����3 ��������"
    },
    {
      "     ����1      ",
      "  ����1 ������  ",
      " ����1 �������� ",
      "     ����2      ",
      "  ����2 ������  ",
      " ����2 �������� ",
      "     ����3      ",
      "  ����3 ������  ",
      " ����3 �������� "
    },
    {
      "     ����1      ",
      "  ����1 ������  ",
      " ����1 �������� ",
      "     ����2      ",
      "  ����2 ������  ",
      " ����2 �������� ",
      "     ����3      ",
      "  ����3 ������  ",
      " ����3 �������� "
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
    if (index_of_ekran_tmp < MAX_ROW_FOR_CONTROL_TZNP)
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
          
        if(current_ekran.edition == 0) temp_data = current_settings.control_tznp;
        else temp_data = edition_settings.control_tznp;
          
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
