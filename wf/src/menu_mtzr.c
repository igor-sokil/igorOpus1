#include "header.h"

#ifdef MTZO_CALC_SYMBOL
/*****************************************************/
//������������ ������� � �������� ���� � ������� �����
/*****************************************************/
void calc_symbol_and_put_into_working_ekran(unsigned char* point_in_working_ekran, void* point_value, void* point_vaga, unsigned int* point_first_symbol, unsigned int current_position_x, unsigned int position_comma, unsigned int view, unsigned int v_32_64)
{
  unsigned int temp_data;
  if (v_32_64 == 0)
  {
    temp_data = (*((unsigned int*)point_value)) / (*((unsigned int*)point_vaga)); //�������� �����, ��� ����� ����������� � ������ � �������� � ���� ������� ������
    *((unsigned int*)point_value) %= *((unsigned int*)point_vaga); //���������� ����� ��� �������, ���� �� ����� ������ �������� �� �����
    *((unsigned int*)point_vaga) /=10; //�������� ������� ���������� � 10 ����
  }
  else
  {
    temp_data = (*((unsigned long long*)point_value)) / (*((unsigned long long*)point_vaga)); //�������� �����, ��� ����� ����������� � ������ � �������� � ���� ������� ������
    *((unsigned long long*)point_value) %= *((unsigned long long*)point_vaga); //���������� ����� ��� �������, ���� �� ����� ������ �������� �� �����
    *((unsigned long long*)point_vaga) /=10; //�������� ������� ���������� � 10 ����
  }
  
  if (view == false) *point_in_working_ekran = temp_data + 0x30;
  else
  {
    //� �������, ���� �� �� � ����� �����������, �� ��� ����� ����� (�� �������� ����������, ���� ����� �) ���������
    if ((temp_data !=0) || ((*point_first_symbol) != 0))
    {
      *point_in_working_ekran = temp_data + 0x30;
      if ((*point_first_symbol) == 0) *point_first_symbol = 1;
    }
    else
    {
      if (current_position_x < (position_comma - 1) ) *point_in_working_ekran = ' ';
      else
      {
        *point_in_working_ekran = temp_data + 0x30;
        if ((*point_first_symbol) == 0) *point_first_symbol = 1;
      }
    }
  }
}
/*****************************************************/
#endif
/*****************************************************/
//������� ����� ����������� ������� ���
/*****************************************************/
void make_ekran_setpoint_mtzr(unsigned int group)
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_SETPOINT_MTZR][MAX_COL_LCD] = 
  {
    {
      "      ����1     ",
      "  �����1 ������ ",
      " �����1 ��������",
      " ���� ���.�����1",
      "     ������1    ",
      " ����.�.������1 ",
      "      ����2     ",
      "  �����2 ������ ",
      " �����2 ��������",
      " ���� ���.�����2",
      "     ������2    ",

    },
    {
      "      ����1     ",
      "  �����1 ������ ",
      "  �����1 ����.  ",
      " ��� ���.�����1 ",
      "     ������1    ",
      " ����.�.������1 ",
      "      ����2     ",
      "  �����2 ������ ",
      "  �����2 ����.  ",
      " ��� ���.�����2 ",
      "     ������2    ",
      " ����.�.������2 ",

    },
    {
      "      OCP1      ",
      "  �����1 ������ ",
      " �����1 ��������",
      " ���� ���.�����1",
      "     ������1    ",
      " ����.�.������1 ",
      "      OCP2      ",
      "  �����2 ������ ",
      " �����2 ��������",
      " ���� ���.�����2",
      "     ������2    ",
      " ����.�.������2 ",

    },
    {
      "      ����1     ",
      "  �����1 ������ ",
      " �����1 ��������",
      " ���� ���.�����1",
      "     ������1    ",
      " ����.�.������1 ",
      "      ����2     ",
      "  �����2 ������ ",
      " �����2 ��������",
      " ���� ���.�����2",
      "     ������2    ",
      " ����.�.������2 ",

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
    if (index_of_ekran_tmp < MAX_ROW_FOR_SETPOINT_MTZR)
    {
      if ((i & 0x1) == 0)
      {
        //� ��������� ����� ����� �������� ���������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_language][index_of_ekran_tmp][j];
        if (index_of_ekran_tmp == INDEX_ML_STPMTZR1)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.setpoint_mtzr_1[group]; //� ����� value ������� �������� �������
          else value = edition_settings.setpoint_mtzr_1[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STPMTZR1_N_VPERED)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.setpoint_mtzr_1_n_vpered[group]; //� ����� value ������� �������� �������
          else value = edition_settings.setpoint_mtzr_1_n_vpered[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STPMTZR1_N_NAZAD)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.setpoint_mtzr_1_n_nazad[group]; //� ����� value ������� �������� �������
          else value = edition_settings.setpoint_mtzr_1_n_nazad[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STPMTZR1_ANGLE)
        {
          vaga = 10; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.setpoint_mtzr_1_angle[group]; //� ����� value ������� �������� �������
          else value = edition_settings.setpoint_mtzr_1_angle[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STPMTZR1_PO_NAPRUZI)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.setpoint_mtzr_1_po_napruzi[group]; //� ����� value ������� �������� �������
          else value = edition_settings.setpoint_mtzr_1_po_napruzi[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STPMTZR1_U)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.setpoint_mtzr_1_U[group]; //� ����� value ������� �������� �������
          else value = edition_settings.setpoint_mtzr_1_U[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STPMTZR2)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.setpoint_mtzr_2[group]; //� ����� value ������� �������� �������
          else value = edition_settings.setpoint_mtzr_2[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STPMTZR2_N_VPERED)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.setpoint_mtzr_2_n_vpered[group]; //� ����� value ������� �������� �������
          else value = edition_settings.setpoint_mtzr_2_n_vpered[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STPMTZR2_N_NAZAD)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.setpoint_mtzr_2_n_nazad[group]; //� ����� value ������� �������� �������
          else value = edition_settings.setpoint_mtzr_2_n_nazad[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STPMTZR2_ANGLE)
        {
          vaga = 10; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.setpoint_mtzr_2_angle[group]; //� ����� value ������� �������� �������
          else value = edition_settings.setpoint_mtzr_2_angle[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STPMTZR2_PO_NAPRUZI)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.setpoint_mtzr_2_po_napruzi[group]; //� ����� value ������� �������� �������
          else value = edition_settings.setpoint_mtzr_2_po_napruzi[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STPMTZR2_U)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.setpoint_mtzr_2_U[group]; //� ����� value ������� �������� �������
          else value = edition_settings.setpoint_mtzr_2_U[group];
        }
		#ifdef MTZR_34_STG
//        else if (index_of_ekran_tmp == INDEX_ML_STPMTZR3)
//        {
//          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
//          if (view == true) value = current_settings.setpoint_mtzo_3[group]; //� ����� value ������� �������� �������
//          else value = edition_settings.setpoint_mtzo_3[group];
//        }
//        else if (index_of_ekran_tmp == INDEX_ML_STPMTZR3_N_VPERED)
//        {
//          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
//          if (view == true) value = current_settings.setpoint_mtzo_3_n_vpered[group]; //� ����� value ������� �������� �������
//          else value = edition_settings.setpoint_mtzo_3_n_vpered[group];
//        }
//        else if (index_of_ekran_tmp == INDEX_ML_STPMTZR3_N_NAZAD)
//        {
//          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
//          if (view == true) value = current_settings.setpoint_mtzo_3_n_nazad[group]; //� ����� value ������� �������� �������
//          else value = edition_settings.setpoint_mtzo_3_n_nazad[group];
//        }
//        else if (index_of_ekran_tmp == INDEX_ML_STPMTZR3_ANGLE)
//        {
//          vaga = 10; //������������ ������� ���������� ��� �������� �������� �������
//          if (view == true) value = current_settings.setpoint_mtzo_3_angle[group]; //� ����� value ������� �������� �������
//          else value = edition_settings.setpoint_mtzo_3_angle[group];
//        }
//        else if (index_of_ekran_tmp == INDEX_ML_STPMTZR3_PO_NAPRUZI)
//        {
//          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
//          if (view == true) value = current_settings.setpoint_mtzo_3_po_napruzi[group]; //� ����� value ������� �������� �������
//          else value = edition_settings.setpoint_mtzo_3_po_napruzi[group];
//        }
//        else if (index_of_ekran_tmp == INDEX_ML_STPMTZR3_U)
//        {
//          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
//          if (view == true) value = current_settings.setpoint_mtzo_3_U[group]; //� ����� value ������� �������� �������
//          else value = edition_settings.setpoint_mtzo_3_U[group];
//        }
//        else if (index_of_ekran_tmp == INDEX_ML_STPMTZR4)
//        {
//          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
//          if (view == true) value = current_settings.setpoint_mtzo_4[group]; //� ����� value ������� �������� �������
//          else value = edition_settings.setpoint_mtzo_4[group];
//        }
//        else if (index_of_ekran_tmp == INDEX_ML_STPMTZR4_N_VPERED)
//        {
//          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
//          if (view == true) value = current_settings.setpoint_mtzo_4_n_vpered[group]; //� ����� value ������� �������� �������
//          else value = edition_settings.setpoint_mtzo_4_n_vpered[group];
//        }
//        else if (index_of_ekran_tmp == INDEX_ML_STPMTZR4_N_NAZAD)
//        {
//          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
//          if (view == true) value = current_settings.setpoint_mtzo_4_n_nazad[group]; //� ����� value ������� �������� �������
//          else value = edition_settings.setpoint_mtzo_4_n_nazad[group];
//        }
//        else if (index_of_ekran_tmp == INDEX_ML_STPMTZR4_ANGLE)
//        {
//          vaga = 10; //������������ ������� ���������� ��� �������� �������� �������
//          if (view == true) value = current_settings.setpoint_mtzo_4_angle[group]; //� ����� value ������� �������� �������
//          else value = edition_settings.setpoint_mtzo_4_angle[group];
//        }
//        else if (index_of_ekran_tmp == INDEX_ML_STPMTZR4_PO_NAPRUZI)
//        {
//          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
//          if (view == true) value = current_settings.setpoint_mtzo_4_po_napruzi[group]; //� ����� value ������� �������� �������
//          else value = edition_settings.setpoint_mtzo_4_po_napruzi[group];
//        }
//        else if (index_of_ekran_tmp == INDEX_ML_STPMTZR4_U)
//        {
//          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
//          if (view == true) value = current_settings.setpoint_mtzo_4_U[group]; //� ����� value ������� �������� �������
//          else value = edition_settings.setpoint_mtzo_4_U[group];
//        }
        #endif
        first_symbol = 0; //�������, �� �� ����� �������� ������ �� ���������
      }
      else
      {
        //� ������� ����� ����� �������� �������� �������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++)
        {
          if (index_of_ekran_tmp == INDEX_ML_STPMTZR1)
          {
            if (
                ((j < COL_SETPOINT_MTZR_1_BEGIN) ||  (j > COL_SETPOINT_MTZR_1_END ))  &&
                (j != (COL_SETPOINT_MTZR_1_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_SETPOINT_MTZR_1_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_SETPOINT_MTZR_1_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_A];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_SETPOINT_MTZR_1_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STPMTZR1_N_VPERED)
          {
            if (
                ((j < COL_SETPOINT_MTZR_1_N_VPERED_BEGIN) ||  (j > COL_SETPOINT_MTZR_1_N_VPERED_END ))  &&
                (j != (COL_SETPOINT_MTZR_1_N_VPERED_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_SETPOINT_MTZR_1_N_VPERED_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_SETPOINT_MTZR_1_N_VPERED_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_A];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_SETPOINT_MTZR_1_N_VPERED_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STPMTZR1_N_NAZAD)
          {
            if (
                ((j < COL_SETPOINT_MTZR_1_N_NAZAD_BEGIN) ||  (j > COL_SETPOINT_MTZR_1_N_NAZAD_END ))  &&
                (j != (COL_SETPOINT_MTZR_1_N_NAZAD_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_SETPOINT_MTZR_1_N_NAZAD_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_SETPOINT_MTZR_1_N_NAZAD_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_A];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_SETPOINT_MTZR_1_N_NAZAD_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STPMTZR1_ANGLE)
          {
            if (
                ((j < COL_SETPOINT_MTZR_1_ANGLE_BEGIN) ||  (j > COL_SETPOINT_MTZR_1_ANGLE_END ))  &&
                (j != (COL_SETPOINT_MTZR_1_ANGLE_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == (COL_SETPOINT_MTZR_1_ANGLE_END + 2)) working_ekran[i][j] = '�';
            else
              calc_int_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, view);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STPMTZR1_PO_NAPRUZI)
          {
            if (
                ((j < COL_SETPOINT_MTZR_1_PO_NAPRUZI_BEGIN) ||  (j > COL_SETPOINT_MTZR_1_PO_NAPRUZI_END ))  &&
                (j != (COL_SETPOINT_MTZR_1_PO_NAPRUZI_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_SETPOINT_MTZR_1_PO_NAPRUZI_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_SETPOINT_MTZR_1_PO_NAPRUZI_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_A];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_SETPOINT_MTZR_1_PO_NAPRUZI_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STPMTZR1_U)
          {
            if (
                ((j < COL_SETPOINT_MTZR_1_U_BEGIN) ||  (j > COL_SETPOINT_MTZR_1_U_END ))  &&
                (j != (COL_SETPOINT_MTZR_1_U_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_SETPOINT_MTZR_1_U_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_SETPOINT_MTZR_1_U_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_V];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_SETPOINT_MTZR_1_U_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STPMTZR2)
          {
            if (
                ((j < COL_SETPOINT_MTZR_2_BEGIN) ||  (j > COL_SETPOINT_MTZR_2_END ))  &&
                (j != (COL_SETPOINT_MTZR_2_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_SETPOINT_MTZR_2_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_SETPOINT_MTZR_2_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_A];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_SETPOINT_MTZR_2_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STPMTZR2_N_VPERED)
          {
            if (
                ((j < COL_SETPOINT_MTZR_2_N_VPERED_BEGIN) ||  (j > COL_SETPOINT_MTZR_2_N_VPERED_END ))  &&
                (j != (COL_SETPOINT_MTZR_2_N_VPERED_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_SETPOINT_MTZR_2_N_VPERED_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_SETPOINT_MTZR_2_N_VPERED_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_A];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_SETPOINT_MTZR_2_N_VPERED_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STPMTZR2_N_NAZAD)
          {
            if (
                ((j < COL_SETPOINT_MTZR_2_N_NAZAD_BEGIN) ||  (j > COL_SETPOINT_MTZR_2_N_NAZAD_END ))  &&
                (j != (COL_SETPOINT_MTZR_2_N_NAZAD_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_SETPOINT_MTZR_2_N_NAZAD_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_SETPOINT_MTZR_2_N_NAZAD_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_A];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_SETPOINT_MTZR_2_N_NAZAD_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STPMTZR2_ANGLE)
          {
            if (
                ((j < COL_SETPOINT_MTZR_2_ANGLE_BEGIN) ||  (j > COL_SETPOINT_MTZR_2_ANGLE_END ))  &&
                (j != (COL_SETPOINT_MTZR_2_ANGLE_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == (COL_SETPOINT_MTZR_2_ANGLE_END + 2)) working_ekran[i][j] = '�';
            else
              calc_int_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, view);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STPMTZR2_PO_NAPRUZI)
          {
            if (
                ((j < COL_SETPOINT_MTZR_2_PO_NAPRUZI_BEGIN) ||  (j > COL_SETPOINT_MTZR_2_PO_NAPRUZI_END ))  &&
                (j != (COL_SETPOINT_MTZR_2_PO_NAPRUZI_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_SETPOINT_MTZR_2_PO_NAPRUZI_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_SETPOINT_MTZR_2_PO_NAPRUZI_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_A];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_SETPOINT_MTZR_2_PO_NAPRUZI_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STPMTZR2_U)
          {
            if (
                ((j < COL_SETPOINT_MTZR_2_U_BEGIN) ||  (j > COL_SETPOINT_MTZR_2_U_END ))  &&
                (j != (COL_SETPOINT_MTZR_2_U_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_SETPOINT_MTZR_2_U_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_SETPOINT_MTZR_2_U_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_V];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_SETPOINT_MTZR_2_U_COMMA, view, 0);
          }
		  
		  #ifdef MTZR_34_STG
//          else if (index_of_ekran_tmp == INDEX_ML_STPMTZR3)
//          {
//            if (
//                ((j < COL_SETPOINT_MTZR_3_BEGIN) ||  (j > COL_SETPOINT_MTZR_3_END ))  &&
//                (j != (COL_SETPOINT_MTZR_3_END + 2))  
//               )working_ekran[i][j] = ' ';
//            else if (j == COL_SETPOINT_MTZR_3_COMMA )working_ekran[i][j] = ',';
//            else if (j == (COL_SETPOINT_MTZR_3_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_A];
//            else
//              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_SETPOINT_MTZR_3_COMMA, view, 0);
//          }
//          else if (index_of_ekran_tmp == INDEX_ML_STPMTZR3_N_VPERED)
//          {
//            if (
//                ((j < COL_SETPOINT_MTZR_3_N_VPERED_BEGIN) ||  (j > COL_SETPOINT_MTZR_3_N_VPERED_END ))  &&
//                (j != (COL_SETPOINT_MTZR_3_N_VPERED_END + 2))  
//               )working_ekran[i][j] = ' ';
//            else if (j == COL_SETPOINT_MTZR_3_N_VPERED_COMMA )working_ekran[i][j] = ',';
//            else if (j == (COL_SETPOINT_MTZR_3_N_VPERED_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_A];
//            else
//              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_SETPOINT_MTZR_3_N_VPERED_COMMA, view, 0);
//          }
//          else if (index_of_ekran_tmp == INDEX_ML_STPMTZR3_N_NAZAD)
//          {
//            if (
//                ((j < COL_SETPOINT_MTZR_3_N_NAZAD_BEGIN) ||  (j > COL_SETPOINT_MTZR_3_N_NAZAD_END ))  &&
//                (j != (COL_SETPOINT_MTZR_3_N_NAZAD_END + 2))  
//               )working_ekran[i][j] = ' ';
//            else if (j == COL_SETPOINT_MTZR_3_N_NAZAD_COMMA )working_ekran[i][j] = ',';
//            else if (j == (COL_SETPOINT_MTZR_3_N_NAZAD_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_A];
//            else
//              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_SETPOINT_MTZR_3_N_NAZAD_COMMA, view, 0);
//          }
//          else if (index_of_ekran_tmp == INDEX_ML_STPMTZR3_ANGLE)
//          {
//            if (
//                ((j < COL_SETPOINT_MTZR_3_ANGLE_BEGIN) ||  (j > COL_SETPOINT_MTZR_3_ANGLE_END ))  &&
//                (j != (COL_SETPOINT_MTZR_3_ANGLE_END + 2))  
//               )working_ekran[i][j] = ' ';
//            else if (j == (COL_SETPOINT_MTZR_3_ANGLE_END + 2)) working_ekran[i][j] = '�';
//            else
//              calc_int_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, view);
//          }
//          else if (index_of_ekran_tmp == INDEX_ML_STPMTZR3_PO_NAPRUZI)
//          {
//            if (
//                ((j < COL_SETPOINT_MTZR_3_PO_NAPRUZI_BEGIN) ||  (j > COL_SETPOINT_MTZR_3_PO_NAPRUZI_END ))  &&
//                (j != (COL_SETPOINT_MTZR_3_PO_NAPRUZI_END + 2))  
//               )working_ekran[i][j] = ' ';
//            else if (j == COL_SETPOINT_MTZR_3_PO_NAPRUZI_COMMA )working_ekran[i][j] = ',';
//            else if (j == (COL_SETPOINT_MTZR_3_PO_NAPRUZI_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_A];
//            else
//              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_SETPOINT_MTZR_3_PO_NAPRUZI_COMMA, view, 0);
//          }
//          else if (index_of_ekran_tmp == INDEX_ML_STPMTZR3_U)
//          {
//            if (
//                ((j < COL_SETPOINT_MTZR_3_U_BEGIN) ||  (j > COL_SETPOINT_MTZR_3_U_END ))  &&
//                (j != (COL_SETPOINT_MTZR_3_U_END + 2))  
//               )working_ekran[i][j] = ' ';
//            else if (j == COL_SETPOINT_MTZR_3_U_COMMA )working_ekran[i][j] = ',';
//            else if (j == (COL_SETPOINT_MTZR_3_U_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_V];
//            else
//              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_SETPOINT_MTZR_3_U_COMMA, view, 0);
//          }
//          else if (index_of_ekran_tmp == INDEX_ML_STPMTZR4)
//          {
//            if (
//                ((j < COL_SETPOINT_MTZR_4_BEGIN) ||  (j > COL_SETPOINT_MTZR_4_END ))  &&
//                (j != (COL_SETPOINT_MTZR_4_END + 2))  
//               )working_ekran[i][j] = ' ';
//            else if (j == COL_SETPOINT_MTZR_4_COMMA )working_ekran[i][j] = ',';
//            else if (j == (COL_SETPOINT_MTZR_4_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_A];
//            else
//              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_SETPOINT_MTZR_4_COMMA, view, 0);
//          }
//          else if (index_of_ekran_tmp == INDEX_ML_STPMTZR4_N_VPERED)
//          {
//            if (
//                ((j < COL_SETPOINT_MTZR_4_N_VPERED_BEGIN) ||  (j > COL_SETPOINT_MTZR_4_N_VPERED_END ))  &&
//                (j != (COL_SETPOINT_MTZR_4_N_VPERED_END + 2))  
//               )working_ekran[i][j] = ' ';
//            else if (j == COL_SETPOINT_MTZR_4_N_VPERED_COMMA )working_ekran[i][j] = ',';
//            else if (j == (COL_SETPOINT_MTZR_4_N_VPERED_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_A];
//            else
//              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_SETPOINT_MTZR_4_N_VPERED_COMMA, view, 0);
//          }
//          else if (index_of_ekran_tmp == INDEX_ML_STPMTZR4_N_NAZAD)
//          {
//            if (
//                ((j < COL_SETPOINT_MTZR_4_N_NAZAD_BEGIN) ||  (j > COL_SETPOINT_MTZR_4_N_NAZAD_END ))  &&
//                (j != (COL_SETPOINT_MTZR_4_N_NAZAD_END + 2))  
//               )working_ekran[i][j] = ' ';
//            else if (j == COL_SETPOINT_MTZR_4_N_NAZAD_COMMA )working_ekran[i][j] = ',';
//            else if (j == (COL_SETPOINT_MTZR_4_N_NAZAD_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_A];
//            else
//              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_SETPOINT_MTZR_4_N_NAZAD_COMMA, view, 0);
//          }
//          else if (index_of_ekran_tmp == INDEX_ML_STPMTZR4_ANGLE)
//          {
//            if (
//                ((j < COL_SETPOINT_MTZR_4_ANGLE_BEGIN) ||  (j > COL_SETPOINT_MTZR_4_ANGLE_END ))  &&
//                (j != (COL_SETPOINT_MTZR_4_ANGLE_END + 2))  
//               )working_ekran[i][j] = ' ';
//            else if (j == (COL_SETPOINT_MTZR_4_ANGLE_END + 2)) working_ekran[i][j] = '�';
//            else
//              calc_int_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, view);
//          }
//          else if (index_of_ekran_tmp == INDEX_ML_STPMTZR4_PO_NAPRUZI)
//          {
//            if (
//                ((j < COL_SETPOINT_MTZR_4_PO_NAPRUZI_BEGIN) ||  (j > COL_SETPOINT_MTZR_4_PO_NAPRUZI_END ))  &&
//                (j != (COL_SETPOINT_MTZR_4_PO_NAPRUZI_END + 2))  
//               )working_ekran[i][j] = ' ';
//            else if (j == COL_SETPOINT_MTZR_4_PO_NAPRUZI_COMMA )working_ekran[i][j] = ',';
//            else if (j == (COL_SETPOINT_MTZR_4_PO_NAPRUZI_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_A];
//            else
//              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_SETPOINT_MTZR_4_PO_NAPRUZI_COMMA, view, 0);
//          }
//          else if (index_of_ekran_tmp == INDEX_ML_STPMTZR4_U)
//          {
//            if (
//                ((j < COL_SETPOINT_MTZR_4_U_BEGIN) ||  (j > COL_SETPOINT_MTZR_4_U_END ))  &&
//                (j != (COL_SETPOINT_MTZR_4_U_END + 2))  
//               )working_ekran[i][j] = ' ';
//            else if (j == COL_SETPOINT_MTZR_4_U_COMMA )working_ekran[i][j] = ',';
//            else if (j == (COL_SETPOINT_MTZR_4_U_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_V];
//            else
//              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_SETPOINT_MTZR_4_U_COMMA, view, 0);
//          }
          #endif
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
    if (current_ekran.index_position == INDEX_ML_STPMTZR1)
    {
      current_ekran.position_cursor_x = COL_SETPOINT_MTZR_1_BEGIN;
      last_position_cursor_x = COL_SETPOINT_MTZR_1_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STPMTZR1_N_VPERED)
    {
      current_ekran.position_cursor_x = COL_SETPOINT_MTZR_1_N_VPERED_BEGIN;
      last_position_cursor_x = COL_SETPOINT_MTZR_1_N_VPERED_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STPMTZR1_N_NAZAD)
    {
      current_ekran.position_cursor_x = COL_SETPOINT_MTZR_1_N_NAZAD_BEGIN;
      last_position_cursor_x = COL_SETPOINT_MTZR_1_N_NAZAD_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STPMTZR1_ANGLE)
    {
      current_ekran.position_cursor_x = COL_SETPOINT_MTZR_1_ANGLE_BEGIN;
      last_position_cursor_x = COL_SETPOINT_MTZR_1_ANGLE_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STPMTZR1_PO_NAPRUZI)
    {
      current_ekran.position_cursor_x = COL_SETPOINT_MTZR_1_PO_NAPRUZI_BEGIN;
      last_position_cursor_x = COL_SETPOINT_MTZR_1_PO_NAPRUZI_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STPMTZR1_U)
    {
      current_ekran.position_cursor_x = COL_SETPOINT_MTZR_1_U_BEGIN;
      last_position_cursor_x = COL_SETPOINT_MTZR_1_U_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STPMTZR2)
    {
      current_ekran.position_cursor_x = COL_SETPOINT_MTZR_2_BEGIN;
      last_position_cursor_x = COL_SETPOINT_MTZR_2_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STPMTZR2_N_VPERED)
    {
      current_ekran.position_cursor_x = COL_SETPOINT_MTZR_2_N_VPERED_BEGIN;
      last_position_cursor_x = COL_SETPOINT_MTZR_2_N_VPERED_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STPMTZR2_N_NAZAD)
    {
      current_ekran.position_cursor_x = COL_SETPOINT_MTZR_2_N_NAZAD_BEGIN;
      last_position_cursor_x = COL_SETPOINT_MTZR_2_N_NAZAD_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STPMTZR2_ANGLE)
    {
      current_ekran.position_cursor_x = COL_SETPOINT_MTZR_2_ANGLE_BEGIN;
      last_position_cursor_x = COL_SETPOINT_MTZR_2_ANGLE_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STPMTZR2_PO_NAPRUZI)
    {
      current_ekran.position_cursor_x = COL_SETPOINT_MTZR_2_PO_NAPRUZI_BEGIN;
      last_position_cursor_x = COL_SETPOINT_MTZR_2_PO_NAPRUZI_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STPMTZR2_U)
    {
      current_ekran.position_cursor_x = COL_SETPOINT_MTZR_2_U_BEGIN;
      last_position_cursor_x = COL_SETPOINT_MTZR_2_U_END;
    }
	 #ifdef MTZR_34_STG
//    else if (current_ekran.index_position == INDEX_ML_STPMTZR3)
//    {
//      current_ekran.position_cursor_x = COL_SETPOINT_MTZR_3_BEGIN;
//      last_position_cursor_x = COL_SETPOINT_MTZR_3_END;
//    }
//    else if (current_ekran.index_position == INDEX_ML_STPMTZR3_N_VPERED)
//    {
//      current_ekran.position_cursor_x = COL_SETPOINT_MTZR_3_N_VPERED_BEGIN;
//      last_position_cursor_x = COL_SETPOINT_MTZR_3_N_VPERED_END;
//    }
//    else if (current_ekran.index_position == INDEX_ML_STPMTZR3_N_NAZAD)
//    {
//      current_ekran.position_cursor_x = COL_SETPOINT_MTZR_3_N_NAZAD_BEGIN;
//      last_position_cursor_x = COL_SETPOINT_MTZR_3_N_NAZAD_END;
//    }
//    else if (current_ekran.index_position == INDEX_ML_STPMTZR3_ANGLE)
//    {
//      current_ekran.position_cursor_x = COL_SETPOINT_MTZR_3_ANGLE_BEGIN;
//      last_position_cursor_x = COL_SETPOINT_MTZR_3_ANGLE_END;
//    }
//    else if (current_ekran.index_position == INDEX_ML_STPMTZR3_PO_NAPRUZI)
//    {
//      current_ekran.position_cursor_x = COL_SETPOINT_MTZR_3_PO_NAPRUZI_BEGIN;
//      last_position_cursor_x = COL_SETPOINT_MTZR_3_PO_NAPRUZI_END;
//    }
//    else if (current_ekran.index_position == INDEX_ML_STPMTZR3_U)
//    {
//      current_ekran.position_cursor_x = COL_SETPOINT_MTZR_3_U_BEGIN;
//      last_position_cursor_x = COL_SETPOINT_MTZR_3_U_END;
//    }
//    else if (current_ekran.index_position == INDEX_ML_STPMTZR4)
//    {
//      current_ekran.position_cursor_x = COL_SETPOINT_MTZR_4_BEGIN;
//      last_position_cursor_x = COL_SETPOINT_MTZR_4_END;
//    }
//    else if (current_ekran.index_position == INDEX_ML_STPMTZR4_N_VPERED)
//    {
//      current_ekran.position_cursor_x = COL_SETPOINT_MTZR_4_N_VPERED_BEGIN;
//      last_position_cursor_x = COL_SETPOINT_MTZR_4_N_VPERED_END;
//    }
//    else if (current_ekran.index_position == INDEX_ML_STPMTZR4_N_NAZAD)
//    {
//      current_ekran.position_cursor_x = COL_SETPOINT_MTZR_4_N_NAZAD_BEGIN;
//      last_position_cursor_x = COL_SETPOINT_MTZR_4_N_NAZAD_END;
//    }
//    else if (current_ekran.index_position == INDEX_ML_STPMTZR4_ANGLE)
//    {
//      current_ekran.position_cursor_x = COL_SETPOINT_MTZR_4_ANGLE_BEGIN;
//      last_position_cursor_x = COL_SETPOINT_MTZR_4_ANGLE_END;
//    }
//    else if (current_ekran.index_position == INDEX_ML_STPMTZR4_PO_NAPRUZI)
//    {
//      current_ekran.position_cursor_x = COL_SETPOINT_MTZR_4_PO_NAPRUZI_BEGIN;
//      last_position_cursor_x = COL_SETPOINT_MTZR_4_PO_NAPRUZI_END;
//    }
//    else if (current_ekran.index_position == INDEX_ML_STPMTZR4_U)
//    {
//      current_ekran.position_cursor_x = COL_SETPOINT_MTZR_4_U_BEGIN;
//      last_position_cursor_x = COL_SETPOINT_MTZR_4_U_END;
//    }
     #endif
    
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
//������� ����� ����������� �������� ���
/*****************************************************/
void make_ekran_timeout_mtzr(unsigned int group)
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_TIMEOUT_MTZR][MAX_COL_LCD] = 
  {
    {
      "      ����1     ",
      "  �����1 ������ ",
      "   �����1 ���.  ",
      "     ������1    ",
//      "      ����2     ",
//      "    ���.����2   ",
//      "  �����2 ������ ",
//      "���.�����2 �����",
//      "   �����2 ���.  ",
//      " ���.�����2 ���.",
//      "     ������2    ",
//      "   ���.������2  ",
//      " ���� ���.����2 ",
      "      ����2     ",
      "  �����2 ������ ",
      "   �����2 ���.  ",
      "     ������2    ",

    },
    {
      "      ����1     ",
      "  �����1 ������ ",
      "  �����1 ����.  ",
      "     ������1    ",
//      "      ����2     ",
//      "   �����.����2  ",
//      "  �����2 ������ ",
//      "�����.�����2 ��.",
//      "  �����2 ����.  ",
//      "�����.�����2 ���",
//      "     ������2    ",
//      "  �����.������2 ",
//      "��� �����.����2",
      "      ����2     ",
      "  �����2 ������ ",
      "  �����2 ����.  ",
      "     ������2    ",

    },
    {
      "      OCP1      ",
      "  �����1 ������ ",
      "   �����1 ���.  ",
      "     ������1    ",
//      "      OCP2      ",
//      "    ���.����2   ",
//      "  �����2 ������ ",
//      "���.�����2 �����",
//      "   �����2 ���.  ",
//      "���.�����2 ���. ",
//      "     ������2    ",
//      "   ���.������2  ",
//      " ���� ���.����2 ",
      "      OCP2      ",
      "  �����2 ������ ",
      "   �����2 ���.  ",
      "     ������2    ",

    },
    {
      "      ����1     ",
      "  �����1 ������ ",
      "   �����1 ���.  ",
      "     ������1    ",
//      "      ����2     ",
//      "    ���.����2   ",
//      "  �����2 ������ ",
//      "���.�����2 �����",
//      "   �����2 ���.  ",
//      " ���.�����2 ���.",
//      "     ������2    ",
//      "   ���.������2  ",
//      " ���� ���.����2 ",
      "      ����2     ",
      "  �����2 ������ ",
      "   �����2 ���.  ",
      "     ������2    ",

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
    if (index_of_ekran_tmp < MAX_ROW_FOR_TIMEOUT_MTZR)
    {
      if ((i & 0x1) == 0)
      {
        //� ��������� ����� ����� �������� ���������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_language][index_of_ekran_tmp][j];
        if (index_of_ekran_tmp == INDEX_ML_TMOMTZR1)
        {
          vaga = 10000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_mtzr_1[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_mtzr_1[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMOMTZR1_N_VPERED)
        {
          vaga = 10000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_mtzr_1_n_vpered[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_mtzr_1_n_vpered[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMOMTZR1_N_NAZAD)
        {
          vaga = 10000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_mtzr_1_n_nazad[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_mtzr_1_n_nazad[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMOMTZR1_PO_NAPRUZI)
        {
          vaga = 10000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_mtzr_1_po_napruzi[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_mtzr_1_po_napruzi[group];
        }
		 #ifdef MTZR_34_STG
//        else if (index_of_ekran_tmp == INDEX_ML_TMOMTZR2)
//        {
//          vaga = 100000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
//          if (view == true) value = current_settings.timeout_mtzo_2[group]; //� ����� value ������� �������� ��������
//          else value = edition_settings.timeout_mtzo_2[group];
//        }
//        else if (index_of_ekran_tmp == INDEX_ML_TMOMTZR2_PR)
//        {
//          vaga = 1000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
//          if (view == true) value = current_settings.timeout_mtzo_2_pr[group]; //� ����� value ������� �������� ��������
//          else value = edition_settings.timeout_mtzo_2_pr[group];
//        }
//        else if (index_of_ekran_tmp == INDEX_ML_TMOMTZR2_N_VPERED)
//        {
//          vaga = 100000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
//          if (view == true) value = current_settings.timeout_mtzo_2_n_vpered[group]; //� ����� value ������� �������� ��������
//          else value = edition_settings.timeout_mtzo_2_n_vpered[group];
//        }
//        else if (index_of_ekran_tmp == INDEX_ML_TMOMTZR2_N_VPERED_PR)
//        {
//          vaga = 1000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
//          if (view == true) value = current_settings.timeout_mtzo_2_n_vpered_pr[group]; //� ����� value ������� �������� ��������
//          else value = edition_settings.timeout_mtzo_2_n_vpered_pr[group];
//        }
//        else if (index_of_ekran_tmp == INDEX_ML_TMOMTZR2_N_NAZAD)
//        {
//          vaga = 100000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
//          if (view == true) value = current_settings.timeout_mtzo_2_n_nazad[group]; //� ����� value ������� �������� ��������
//          else value = edition_settings.timeout_mtzo_2_n_nazad[group];
//        }
//        else if (index_of_ekran_tmp == INDEX_ML_TMOMTZR2_N_NAZAD_PR)
//        {
//          vaga = 1000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
//          if (view == true) value = current_settings.timeout_mtzo_2_n_nazad_pr[group]; //� ����� value ������� �������� ��������
//          else value = edition_settings.timeout_mtzo_2_n_nazad_pr[group];
//        }
//        else if (index_of_ekran_tmp == INDEX_ML_TMOMTZR2_PO_NAPRUZI)
//        {
//          vaga = 100000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
//          if (view == true) value = current_settings.timeout_mtzo_2_po_napruzi[group]; //� ����� value ������� �������� ��������
//          else value = edition_settings.timeout_mtzo_2_po_napruzi[group];
//        }
//        else if (index_of_ekran_tmp == INDEX_ML_TMOMTZR2_PO_NAPRUZI_PR)
//        {
//          vaga = 1000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
//          if (view == true) value = current_settings.timeout_mtzo_2_po_napruzi_pr[group]; //� ����� value ������� �������� ��������
//          else value = edition_settings.timeout_mtzo_2_po_napruzi_pr[group];
//        }
//        else if (index_of_ekran_tmp == INDEX_ML_TMOMTZR2_VVID_PR)
//        {
//          vaga = 1000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
//          if (view == true) value = current_settings.timeout_mtzo_2_vvid_pr[group]; //� ����� value ������� �������� ��������
//          else value = edition_settings.timeout_mtzo_2_vvid_pr[group];
//        }
         #endif
        else if (index_of_ekran_tmp == INDEX_ML_TMOMTZR2)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_mtzr_2[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_mtzr_2[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMOMTZR2_N_VPERED)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_mtzr_2_n_vpered[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_mtzr_2_n_vpered[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMOMTZR2_N_NAZAD)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_mtzr_2_n_nazad[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_mtzr_2_n_nazad[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMOMTZR2_PO_NAPRUZI)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_mtzr_2_po_napruzi[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_mtzr_2_po_napruzi[group];
        }
		 #ifdef MTZR_34_STG
//        else if (index_of_ekran_tmp == INDEX_ML_TMOMTZR4)
//        {
//          vaga = 100000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
//          if (view == true) value = current_settings.timeout_mtzo_4[group]; //� ����� value ������� �������� ��������
//          else value = edition_settings.timeout_mtzo_4[group];
//        }
//        else if (index_of_ekran_tmp == INDEX_ML_TMOMTZR4_N_VPERED)
//        {
//          vaga = 100000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
//          if (view == true) value = current_settings.timeout_mtzo_4_n_vpered[group]; //� ����� value ������� �������� ��������
//          else value = edition_settings.timeout_mtzo_4_n_vpered[group];
//        }
//        else if (index_of_ekran_tmp == INDEX_ML_TMOMTZR4_N_NAZAD)
//        {
//          vaga = 100000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
//          if (view == true) value = current_settings.timeout_mtzo_4_n_nazad[group]; //� ����� value ������� �������� ��������
//          else value = edition_settings.timeout_mtzo_4_n_nazad[group];
//        }
//        else if (index_of_ekran_tmp == INDEX_ML_TMOMTZR4_PO_NAPRUZI)
//        {
//          vaga = 100000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
//          if (view == true) value = current_settings.timeout_mtzo_4_po_napruzi[group]; //� ����� value ������� �������� ��������
//          else value = edition_settings.timeout_mtzo_4_po_napruzi[group];
//        }
         #endif

        first_symbol = 0; //�������, �� �� ����� �������� ������ �� ���������
      }
      else
      {
        //� ������� ����� ����� �������� �������� �������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++)
        {
          if (index_of_ekran_tmp == INDEX_ML_TMOMTZR1)
          {
            if (
                ((j < COL_TMO_MTZR_1_BEGIN) ||  (j > COL_TMO_MTZR_1_END )) &&
                (j != (COL_TMO_MTZR_1_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_MTZR_1_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_MTZR_1_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_MTZR_1_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMOMTZR1_N_VPERED)
          {
            if (
                ((j < COL_TMO_MTZR_1_N_VPERED_BEGIN) ||  (j > COL_TMO_MTZR_1_N_VPERED_END )) &&
                (j != (COL_TMO_MTZR_1_N_VPERED_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_MTZR_1_N_VPERED_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_MTZR_1_N_VPERED_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_MTZR_1_N_VPERED_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMOMTZR1_N_NAZAD)
          {
            if (
                ((j < COL_TMO_MTZR_1_N_NAZAD_BEGIN) ||  (j > COL_TMO_MTZR_1_N_NAZAD_END )) &&
                (j != (COL_TMO_MTZR_1_N_NAZAD_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_MTZR_1_N_NAZAD_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_MTZR_1_N_NAZAD_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_MTZR_1_N_NAZAD_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMOMTZR1_PO_NAPRUZI)
          {
            if (
                ((j < COL_TMO_MTZR_1_PO_NAPRUZI_BEGIN) ||  (j > COL_TMO_MTZR_1_PO_NAPRUZI_END )) &&
                (j != (COL_TMO_MTZR_1_PO_NAPRUZI_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_MTZR_1_PO_NAPRUZI_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_MTZR_1_PO_NAPRUZI_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_MTZR_1_PO_NAPRUZI_COMMA, view, 0);
          }
           #ifdef MTZR_34_STG
//          else if (index_of_ekran_tmp == INDEX_ML_TMOMTZR2)
//          {
//            if (
//                ((j < COL_TMO_MTZR_2_BEGIN) ||  (j > COL_TMO_MTZR_2_END )) &&
//                (j != (COL_TMO_MTZR_2_END + 2))  
//               )working_ekran[i][j] = ' ';
//            else if (j == COL_TMO_MTZR_2_COMMA )working_ekran[i][j] = ',';
//            else if (j == (COL_TMO_MTZR_2_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
//            else
//              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_MTZR_2_COMMA, view, 0);
//          }
//          else if (index_of_ekran_tmp == INDEX_ML_TMOMTZR2_PR)
//          {
//            if (
//                ((j < COL_TMO_MTZR_2_PR_BEGIN) ||  (j > COL_TMO_MTZR_2_PR_END )) &&
//                (j != (COL_TMO_MTZR_2_PR_END + 2))  
//               )working_ekran[i][j] = ' ';
//            else if (j == COL_TMO_MTZR_2_PR_COMMA )working_ekran[i][j] = ',';
//            else if (j == (COL_TMO_MTZR_2_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
//            else
//              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_MTZR_2_PR_COMMA, view, 0);
//          }
//          else if (index_of_ekran_tmp == INDEX_ML_TMOMTZR2_N_VPERED)
//          {
//            if (
//                ((j < COL_TMO_MTZR_2_N_VPERED_BEGIN) ||  (j > COL_TMO_MTZR_2_N_VPERED_END )) &&
//                (j != (COL_TMO_MTZR_2_N_VPERED_END + 2))  
//               )working_ekran[i][j] = ' ';
//            else if (j == COL_TMO_MTZR_2_N_VPERED_COMMA )working_ekran[i][j] = ',';
//            else if (j == (COL_TMO_MTZR_2_N_VPERED_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
//            else
//              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_MTZR_2_N_VPERED_COMMA, view, 0);
//          }
//          else if (index_of_ekran_tmp == INDEX_ML_TMOMTZR2_N_VPERED_PR)
//          {
//            if (
//                ((j < COL_TMO_MTZR_2_N_VPERED_PR_BEGIN) ||  (j > COL_TMO_MTZR_2_N_VPERED_PR_END )) &&
//                (j != (COL_TMO_MTZR_2_N_VPERED_PR_END + 2))  
//               )working_ekran[i][j] = ' ';
//            else if (j == COL_TMO_MTZR_2_N_VPERED_PR_COMMA )working_ekran[i][j] = ',';
//            else if (j == (COL_TMO_MTZR_2_N_VPERED_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
//            else
//              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_MTZR_2_N_VPERED_PR_COMMA, view, 0);
//          }
//          else if (index_of_ekran_tmp == INDEX_ML_TMOMTZR2_N_NAZAD)
//          {
//            if (
//                ((j < COL_TMO_MTZR_2_N_NAZAD_BEGIN) ||  (j > COL_TMO_MTZR_2_N_NAZAD_END )) &&
//                (j != (COL_TMO_MTZR_2_N_NAZAD_END + 2))  
//               )working_ekran[i][j] = ' ';
//            else if (j == COL_TMO_MTZR_2_N_NAZAD_COMMA )working_ekran[i][j] = ',';
//            else if (j == (COL_TMO_MTZR_2_N_NAZAD_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
//            else
//              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_MTZR_2_N_NAZAD_COMMA, view, 0);
//          }
//          else if (index_of_ekran_tmp == INDEX_ML_TMOMTZR2_N_NAZAD_PR)
//          {
//            if (
//                ((j < COL_TMO_MTZR_2_N_NAZAD_PR_BEGIN) ||  (j > COL_TMO_MTZR_2_N_NAZAD_PR_END )) &&
//                (j != (COL_TMO_MTZR_2_N_NAZAD_PR_END + 2))  
//               )working_ekran[i][j] = ' ';
//            else if (j == COL_TMO_MTZR_2_N_NAZAD_PR_COMMA )working_ekran[i][j] = ',';
//            else if (j == (COL_TMO_MTZR_2_N_NAZAD_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
//            else
//              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_MTZR_2_N_NAZAD_PR_COMMA, view, 0);
//          }
//          else if (index_of_ekran_tmp == INDEX_ML_TMOMTZR2_PO_NAPRUZI)
//          {
//            if (
//                ((j < COL_TMO_MTZR_2_PO_NAPRUZI_BEGIN) ||  (j > COL_TMO_MTZR_2_PO_NAPRUZI_END )) &&
//                (j != (COL_TMO_MTZR_2_PO_NAPRUZI_END + 2))  
//               )working_ekran[i][j] = ' ';
//            else if (j == COL_TMO_MTZR_2_PO_NAPRUZI_COMMA )working_ekran[i][j] = ',';
//            else if (j == (COL_TMO_MTZR_2_PO_NAPRUZI_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
//            else
//              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_MTZR_2_PO_NAPRUZI_COMMA, view, 0);
//          }
//          else if (index_of_ekran_tmp == INDEX_ML_TMOMTZR2_PO_NAPRUZI_PR)
//          {
//            if (
//                ((j < COL_TMO_MTZR_2_PO_NAPRUZI_PR_BEGIN) ||  (j > COL_TMO_MTZR_2_PO_NAPRUZI_PR_END )) &&
//                (j != (COL_TMO_MTZR_2_PO_NAPRUZI_PR_END + 2))  
//               )working_ekran[i][j] = ' ';
//            else if (j == COL_TMO_MTZR_2_PO_NAPRUZI_PR_COMMA )working_ekran[i][j] = ',';
//            else if (j == (COL_TMO_MTZR_2_PO_NAPRUZI_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
//            else
//              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_MTZR_2_PO_NAPRUZI_PR_COMMA, view, 0);
//          }
//          else if (index_of_ekran_tmp == INDEX_ML_TMOMTZR2_VVID_PR)
//          {
//            if (
//                ((j < COL_TMO_MTZR_2_VVID_PR_BEGIN) ||  (j > COL_TMO_MTZR_2_VVID_PR_END )) &&
//                (j != (COL_TMO_MTZR_2_VVID_PR_END + 2))  
//               )working_ekran[i][j] = ' ';
//            else if (j == COL_TMO_MTZR_2_VVID_PR_COMMA )working_ekran[i][j] = ',';
//            else if (j == (COL_TMO_MTZR_2_VVID_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
//            else
//              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_MTZR_2_VVID_PR_COMMA, view, 0);
//          }
           #endif
          else if (index_of_ekran_tmp == INDEX_ML_TMOMTZR2)
          {
            if (
                ((j < COL_TMO_MTZR_2_BEGIN) ||  (j > COL_TMO_MTZR_2_END )) &&
                (j != (COL_TMO_MTZR_2_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_MTZR_2_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_MTZR_2_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_MTZR_2_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMOMTZR2_N_VPERED)
          {
            if (
                ((j < COL_TMO_MTZR_2_N_VPERED_BEGIN) ||  (j > COL_TMO_MTZR_2_N_VPERED_END )) &&
                (j != (COL_TMO_MTZR_2_N_VPERED_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_MTZR_2_N_VPERED_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_MTZR_2_N_VPERED_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_MTZR_2_N_VPERED_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMOMTZR2_N_NAZAD)
          {
            if (
                ((j < COL_TMO_MTZR_2_N_NAZAD_BEGIN) ||  (j > COL_TMO_MTZR_2_N_NAZAD_END )) &&
                (j != (COL_TMO_MTZR_2_N_NAZAD_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_MTZR_2_N_NAZAD_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_MTZR_2_N_NAZAD_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_MTZR_2_N_NAZAD_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMOMTZR2_PO_NAPRUZI)
          {
            if (
                ((j < COL_TMO_MTZR_2_PO_NAPRUZI_BEGIN) ||  (j > COL_TMO_MTZR_2_PO_NAPRUZI_END )) &&
                (j != (COL_TMO_MTZR_2_PO_NAPRUZI_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_MTZR_2_PO_NAPRUZI_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_MTZR_2_PO_NAPRUZI_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_MTZR_2_PO_NAPRUZI_COMMA, view, 0);
          }
           #ifdef MTZR_34_STG
//          else if (index_of_ekran_tmp == INDEX_ML_TMOMTZR4)
//          {
//            if (
//                ((j < COL_TMO_MTZR_4_BEGIN) ||  (j > COL_TMO_MTZR_4_END )) &&
//                (j != (COL_TMO_MTZR_4_END + 2))  
//               )working_ekran[i][j] = ' ';
//            else if (j == COL_TMO_MTZR_4_COMMA )working_ekran[i][j] = ',';
//            else if (j == (COL_TMO_MTZR_4_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
//            else
//              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_MTZR_4_COMMA, view, 0);
//          }
//          else if (index_of_ekran_tmp == INDEX_ML_TMOMTZR4_N_VPERED)
//          {
//            if (
//                ((j < COL_TMO_MTZR_4_N_VPERED_BEGIN) ||  (j > COL_TMO_MTZR_4_N_VPERED_END )) &&
//                (j != (COL_TMO_MTZR_4_N_VPERED_END + 2))  
//               )working_ekran[i][j] = ' ';
//            else if (j == COL_TMO_MTZR_4_N_VPERED_COMMA )working_ekran[i][j] = ',';
//            else if (j == (COL_TMO_MTZR_4_N_VPERED_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
//            else
//              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_MTZR_4_N_VPERED_COMMA, view, 0);
//          }
//          else if (index_of_ekran_tmp == INDEX_ML_TMOMTZR4_N_NAZAD)
//          {
//            if (
//                ((j < COL_TMO_MTZR_4_N_NAZAD_BEGIN) ||  (j > COL_TMO_MTZR_4_N_NAZAD_END )) &&
//                (j != (COL_TMO_MTZR_4_N_NAZAD_END + 2))  
//               )working_ekran[i][j] = ' ';
//            else if (j == COL_TMO_MTZR_4_N_NAZAD_COMMA )working_ekran[i][j] = ',';
//            else if (j == (COL_TMO_MTZR_4_N_NAZAD_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
//            else
//              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_MTZR_4_N_NAZAD_COMMA, view, 0);
//          }
//          else if (index_of_ekran_tmp == INDEX_ML_TMOMTZR4_PO_NAPRUZI)
//          {
//            if (
//                ((j < COL_TMO_MTZR_4_PO_NAPRUZI_BEGIN) ||  (j > COL_TMO_MTZR_4_PO_NAPRUZI_END )) &&
//                (j != (COL_TMO_MTZR_4_PO_NAPRUZI_END + 2))  
//               )working_ekran[i][j] = ' ';
//            else if (j == COL_TMO_MTZR_4_PO_NAPRUZI_COMMA )working_ekran[i][j] = ',';
//            else if (j == (COL_TMO_MTZR_4_PO_NAPRUZI_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
//            else
//              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_MTZR_4_PO_NAPRUZI_COMMA, view, 0);
//          }
           #endif
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
    if (current_ekran.index_position == INDEX_ML_TMOMTZR1) 
    {
      current_ekran.position_cursor_x = COL_TMO_MTZR_1_BEGIN;
      last_position_cursor_x = COL_TMO_MTZR_1_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMOMTZR1_N_VPERED) 
    {
      current_ekran.position_cursor_x = COL_TMO_MTZR_1_N_VPERED_BEGIN;
      last_position_cursor_x = COL_TMO_MTZR_1_N_VPERED_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMOMTZR1_N_NAZAD) 
    {
      current_ekran.position_cursor_x = COL_TMO_MTZR_1_N_NAZAD_BEGIN;
      last_position_cursor_x = COL_TMO_MTZR_1_N_NAZAD_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMOMTZR1_PO_NAPRUZI) 
    {
      current_ekran.position_cursor_x = COL_TMO_MTZR_1_PO_NAPRUZI_BEGIN;
      last_position_cursor_x = COL_TMO_MTZR_1_PO_NAPRUZI_END;
    }
     #ifdef MTZR_34_STG
//    else if (current_ekran.index_position == INDEX_ML_TMOMTZR2) 
//    {
//      current_ekran.position_cursor_x = COL_TMO_MTZR_2_BEGIN;
//      last_position_cursor_x = COL_TMO_MTZR_2_END;
//    }
//    else if (current_ekran.index_position == INDEX_ML_TMOMTZR2_PR) 
//    {
//      current_ekran.position_cursor_x = COL_TMO_MTZR_2_PR_BEGIN;
//      last_position_cursor_x = COL_TMO_MTZR_2_PR_END;
//    }
//    else if (current_ekran.index_position == INDEX_ML_TMOMTZR2_N_VPERED) 
//    {
//      current_ekran.position_cursor_x = COL_TMO_MTZR_2_N_VPERED_BEGIN;
//      last_position_cursor_x = COL_TMO_MTZR_2_N_VPERED_END;
//    }
//    else if (current_ekran.index_position == INDEX_ML_TMOMTZR2_N_VPERED_PR) 
//    {
//      current_ekran.position_cursor_x = COL_TMO_MTZR_2_N_VPERED_PR_BEGIN;
//      last_position_cursor_x = COL_TMO_MTZR_2_N_VPERED_PR_END;
//    }
//    else if (current_ekran.index_position == INDEX_ML_TMOMTZR2_N_NAZAD) 
//    {
//      current_ekran.position_cursor_x = COL_TMO_MTZR_2_N_NAZAD_BEGIN;
//      last_position_cursor_x = COL_TMO_MTZR_2_N_NAZAD_END;
//    }
//    else if (current_ekran.index_position == INDEX_ML_TMOMTZR2_N_NAZAD_PR) 
//    {
//      current_ekran.position_cursor_x = COL_TMO_MTZR_2_N_NAZAD_PR_BEGIN;
//      last_position_cursor_x = COL_TMO_MTZR_2_N_NAZAD_PR_END;
//    }
//    else if (current_ekran.index_position == INDEX_ML_TMOMTZR2_PO_NAPRUZI) 
//    {
//      current_ekran.position_cursor_x = COL_TMO_MTZR_2_PO_NAPRUZI_BEGIN;
//      last_position_cursor_x = COL_TMO_MTZR_2_PO_NAPRUZI_END;
//    }
//    else if (current_ekran.index_position == INDEX_ML_TMOMTZR2_PO_NAPRUZI_PR) 
//    {
//      current_ekran.position_cursor_x = COL_TMO_MTZR_2_PO_NAPRUZI_PR_BEGIN;
//      last_position_cursor_x = COL_TMO_MTZR_2_PO_NAPRUZI_PR_END;
//    }
//    else if (current_ekran.index_position == INDEX_ML_TMOMTZR2_VVID_PR) 
//    {
//      current_ekran.position_cursor_x = COL_TMO_MTZR_2_VVID_PR_BEGIN;
//      last_position_cursor_x = COL_TMO_MTZR_2_VVID_PR_END;
//    }
    #endif
     else if (current_ekran.index_position == INDEX_ML_TMOMTZR2) 
    {
      current_ekran.position_cursor_x = COL_TMO_MTZR_2_BEGIN;
      last_position_cursor_x = COL_TMO_MTZR_2_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMOMTZR2_N_VPERED) 
    {
      current_ekran.position_cursor_x = COL_TMO_MTZR_2_N_VPERED_BEGIN;
      last_position_cursor_x = COL_TMO_MTZR_2_N_VPERED_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMOMTZR2_N_NAZAD) 
    {
      current_ekran.position_cursor_x = COL_TMO_MTZR_2_N_NAZAD_BEGIN;
      last_position_cursor_x = COL_TMO_MTZR_2_N_NAZAD_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMOMTZR2_PO_NAPRUZI) 
    {
      current_ekran.position_cursor_x = COL_TMO_MTZR_2_PO_NAPRUZI_BEGIN;
      last_position_cursor_x = COL_TMO_MTZR_2_PO_NAPRUZI_END;
    }
     #ifdef MTZR_34_STG
//    else if (current_ekran.index_position == INDEX_ML_TMOMTZR4) 
//    {
//      current_ekran.position_cursor_x = COL_TMO_MTZR_4_BEGIN;
//      last_position_cursor_x = COL_TMO_MTZR_4_END;
//    }
//    else if (current_ekran.index_position == INDEX_ML_TMOMTZR4_N_VPERED) 
//    {
//      current_ekran.position_cursor_x = COL_TMO_MTZR_4_N_VPERED_BEGIN;
//      last_position_cursor_x = COL_TMO_MTZR_4_N_VPERED_END;
//    }
//    else if (current_ekran.index_position == INDEX_ML_TMOMTZR4_N_NAZAD) 
//    {
//      current_ekran.position_cursor_x = COL_TMO_MTZR_4_N_NAZAD_BEGIN;
//      last_position_cursor_x = COL_TMO_MTZR_4_N_NAZAD_END;
//    }
//    else if (current_ekran.index_position == INDEX_ML_TMOMTZR4_PO_NAPRUZI) 
//    {
//      current_ekran.position_cursor_x = COL_TMO_MTZR_4_PO_NAPRUZI_BEGIN;
//      last_position_cursor_x = COL_TMO_MTZR_4_PO_NAPRUZI_END;
//    }
     #endif

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
//������� ����� ����������� �������� ����������� ���������� ��� ���
/*****************************************************/
void make_ekran_control_mtzr()
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_CONTROL_MTZR][MAX_COL_LCD] = 
  {
    {
      "      ����1     ",
      "    ��� ����1   ",
      "  �����1 ������ ",
      " �����1 ��������",
//      "      ����2     ",
//      "    ��� ����2   ",
//      "  �����2 ������ ",
//      " �����2 ��������",
//      " ��������� ����2",
//      "���������� ����2",
      "      ����2     ",
      "    ��� ����2   ",
      "  �����2 ������ ",
      " �����2 ��������",
//      "      ����4     ",
//      "    ��� ����4   ",
//      "  �����4 ������ ",
//      " �����4 ��������",
      "    ���-���P    "
    },
    {
      "      ����1     ",
      "    ��� ����1   ",
      "  �����1 ������ ",
      "  �����1 ����.  ",
//      "      ����2     ",
//      "    ��� ����2   ",
//      "  �����2 ������ ",
//      "  �����2 ����.  ",
//      "�������.   ����2",
//      "���������������2",
      "      ����2     ",
      "    ��� ����2   ",
      "  �����2 ������ ",
      "  �����2 ����.  ",
//      "      ����4     ",
//      "    ��� ����4   ",
//      "  �����4 ������ ",
//      "  �����4 ����.  ",
      "    ���-����    "
    },
    {
      "  OCP Stage 1   ",
      " Option of OCP1 ",
      "  �����1 ������ ",
      " �����1 ��������",
//      "  OCP Stage 2   ",
//      " Option of OCP2 ",
//      "  �����2 ������ ",
//      " �����2 ��������",
//      "   OCP2 Acc.    ",
//      "Accelerated OCP2",
      "  OCP Stage 2   ",
      " Option of OCP2 ",
      "  �����2 ������ ",
      " �����2 ��������",
//      "  OCP Stage 4   ",
//      " Option of OCP4 ",
//      "  �����4 ������ ",
//      " �����4 ��������",
      "    ���-����    "
    },
    {
      "      ����1     ",
      "    ��� ����1   ",
      "  �����1 ������ ",
      " �����1 ��������",
//      "      ����2     ",
//      "    ��� ����2   ",
//      "  �����2 ������ ",
//      " �����2 ��������",
//      " ��������� ����2",
//      "���������� ����2",
      "      ����2     ",
      "    ��� ����2   ",
      "  �����2 ������ ",
      " �����2 ��������",
//      "      ����4     ",
//      "    ��� ����4   ",
//      "  �����4 ������ ",
//      " �����4 ��������",
      "    ���-����    "
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
    if (index_of_ekran_tmp < MAX_ROW_FOR_CONTROL_MTZR)
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

        __SETTINGS *point;
          if(current_ekran.edition == 0) point = &current_settings;
          else point = &edition_settings;

        if (
            (index_ctr == INDEX_ML_CTRMTZR_1_TYPE) ||
            (index_ctr == INDEX_ML_CTRMTZR_2_TYPE) //||  
            //(index_ctr == INDEX_ML_CTRMTZR_3_TYPE) || 
            //(index_ctr == INDEX_ML_CTRMTZR_4_TYPE)  
           )   
        {
          int value = 0;
          if (index_ctr == INDEX_ML_CTRMTZR_1_TYPE) value = point->type_mtzr1;
          else if (index_ctr == INDEX_ML_CTRMTZR_2_TYPE) value = point->type_mtzr2;
          //else if (index_ctr == INDEX_ML_CTRMTZR_3_TYPE) value = point->type_mtzo3;
          //else if (index_ctr == INDEX_ML_CTRMTZR_4_TYPE) value = point->type_mtzo4;
          else total_error_sw_fixed();

          static const unsigned char information[MAX_NAMBER_LANGUAGE][8][MAX_COL_LCD] = 
          {
            {"    �������     ", "  ������������  ", " � ������ �� U  ", " �����.(��� A)  ", " �����.(��� B)  ", " �����.(��� C)  ", " �����.(��-80)  ", " �����.(���-1)  "},
            {"    �������     ", "   �����������  ", " �� ������ �� U ", "�������� (��� A)", "�������� (��� B)", "�������� (��� C)", "�������� (��-80)", "�������� (���-1)"},
            {"    �������     ", "  ������������  ", " � ������ �� U  ", "  Dep.(Type A)  ", "  Dep.(Type B)  ", "  Dep.(Type C)  ", "  Dep.(RT-80)   ", "  Dep.(RTV-1)   "},
            {"    �������     ", "  ������������  ", " � ������ �� U  ", " �����.(��� A)  ", " �����.(��� B)  ", " �����.(��� C)  ", " �����.(��-80)  ", " �����.(���-1)  "}
          };
          static const unsigned int cursor_x[MAX_NAMBER_LANGUAGE][8] = 
          {
            {3, 1, 0, 0, 0, 0, 0, 0},
            {3, 2, 0, 0, 0, 0, 0, 0},
            {3, 1, 0, 1, 1, 1, 1, 1},
            {3, 1, 0, 0, 0, 0, 0, 0}
          };
          
          for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = information[index_language][value][j];
          if (position_temp == index_of_ekran_tmp) current_ekran.position_cursor_x = cursor_x[index_language][value];
        }
        else
        {
          unsigned int temp_data = point->control_mtzr;
          unsigned int n_bit = 0;
          
          //�������� ����� ���
          if      (index_ctr == INDEX_ML_CTRMTZR_1             ) n_bit = N_BIT_CTRMTZR_1;
          else if (index_ctr == INDEX_ML_CTRMTZR_1_VPERED      ) n_bit = N_BIT_CTRMTZR_1_VPERED;
          else if (index_ctr == INDEX_ML_CTRMTZR_1_NAZAD       ) n_bit = N_BIT_CTRMTZR_1_NAZAD;
          else if (index_ctr == INDEX_ML_CTRMTZR_2             ) n_bit = N_BIT_CTRMTZR_2;
          else if (index_ctr == INDEX_ML_CTRMTZR_2_VPERED      ) n_bit = N_BIT_CTRMTZR_2_VPERED;
          else if (index_ctr == INDEX_ML_CTRMTZR_2_NAZAD       ) n_bit = N_BIT_CTRMTZR_2_NAZAD;
//          else if (index_ctr == INDEX_ML_CTRMTZR_2_PRYSKORENNJA) n_bit = N_BIT_CTRMTZR_2_PRYSKORENNJA;
//          else if (index_ctr == INDEX_ML_CTRMTZR_2_PRYSKORENA  ) n_bit = N_BIT_CTRMTZR_2_PRYSKORENA;
//          else if (index_ctr == INDEX_ML_CTRMTZR_3             ) n_bit = N_BIT_CTRMTZR_3;
//          else if (index_ctr == INDEX_ML_CTRMTZR_3_VPERED      ) n_bit = N_BIT_CTRMTZR_3_VPERED;
//          else if (index_ctr == INDEX_ML_CTRMTZR_3_NAZAD       ) n_bit = N_BIT_CTRMTZR_3_NAZAD;
//          else if (index_ctr == INDEX_ML_CTRMTZR_4             ) n_bit = N_BIT_CTRMTZR_4;
//          else if (index_ctr == INDEX_ML_CTRMTZR_4_VPERED      ) n_bit = N_BIT_CTRMTZR_4_VPERED;
//          else if (index_ctr == INDEX_ML_CTRMTZR_4_NAZAD       ) n_bit = N_BIT_CTRMTZR_4_NAZAD;
          else if (index_ctr == INDEX_ML_CTRMTZR_NESPR_KIL_NAPR) n_bit = N_BIT_CTRMTZR_NESPR_KIL_NAPR;
          
          for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = information_off_on[index_language][(temp_data >> n_bit) & 0x1][j];
          if (position_temp == index_of_ekran_tmp) current_ekran.position_cursor_x = cursor_x_off_on[index_language][(temp_data >> n_bit) & 0x1];
        }
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
