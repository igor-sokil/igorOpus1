#include "header.h"


/*****************************************************/
//������� ����� ����������� ������� ��
/*****************************************************/
void make_ekran_setpoint_dz(unsigned int group)
{
  const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_SETPOINT_DZ][MAX_COL_LCD] = 
  {
    {
      " � �����������  ",
      "  ������� ��1   ",
      "  ������� A���1 ",
      "   ����  ��2    ",
      "  ������  ��2   ",
      "  �������� ��2  ",
      "  ������� A���2 ",
      "   ����  ��3    ",
      "  ������  ��3   ",
      "  �������� ��3  ",
      "  ������� A���3 ",
      "   ����  ��4    ",
      "  ������  ��4   ",
      "  �������� ��4  ",
      "  ������� A���4 ",
    },
    {
      " � �����������  ",
      "  ������� ��1   ",
      "  ������� A���1 ",
      "   ���  ��2     ",
      "  �����  ��2    ",
      "  �������� ��2  ",
      "  ������� A���2 ",
      "   ���  ��3     ",
      "  �����  ��3    ",
      "  �������� ��3  ",
      "  ������� A���3 ",
      "   ���  ��4     ",
      "  �����  ��4    ",
      "  �������� ��4  ",
      "  ������� A���4 ",
    },
    {
      " � �����������  ",
      "  ������� ��1   ",
      "  ������� A���1 ",
      "   ����  ��2    ",
      "  ������  ��2   ",
      "  �������� ��2  ",
      "  ������� A���2 ",
      "   ����  ��3    ",
      "  ������  ��3   ",
      "  �������� ��3  ",
      "  ������� A���3 ",
      "   ����  ��4    ",
      "  ������  ��4   ",
      "  �������� ��4  ",
      "  ������� A���4 ",
    },
    {
      " � �����������  ",
      "  ������� ��1   ",
      "  ������� A���1 ",
      "   ����  ��2    ",
      "  ������  ��2   ",
      "  �������� ��2  ",
      "  ������� A���2 ",
      "   ����  ��3    ",
      "  ������  ��3   ",
      "  �������� ��3  ",
      "  ������� A���3 ",
      "   ����  ��4    ",
      "  ������  ��4   ",
      "  �������� ��4  ",
      "  ������� A���4 ",
    }
  };
  int index_language = index_language_in_array(current_settings.language);
  
  unsigned int position_temp = current_ekran.index_position;
  unsigned int index_of_ekran;
  unsigned int vaga, value, first_symbol;
  unsigned int lValue;
  
  //�������� �� ��� �������� position_temp ������� ��� ����, �� ����� ������� �� ������������� ��� ����� (����� + ��������)
  index_of_ekran = ((position_temp<<1) >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;
  
  for (unsigned int i=0; i< MAX_ROW_LCD; i++)
  {
    unsigned int index_of_ekran_tmp = index_of_ekran >> 1;
    unsigned int view = ((current_ekran.edition == 0) || (position_temp != index_of_ekran_tmp));
    if (index_of_ekran_tmp < MAX_ROW_FOR_SETPOINT_DZ)
    {
      if ((i & 0x1) == 0)
      {
        //� ��������� ����� ����� �������� ���������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_language][index_of_ekran_tmp][j];
        if (index_of_ekran_tmp == INDEX_ML_STP_K_DZ)
        {
          vaga = 100; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.pickup_dz_k[group]; //� ����� value ������� �������� �������
          else value = edition_settings.pickup_dz_k[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZ1)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.pickup_dz1[group]; //� ����� value ������� �������� �������
          else value = edition_settings.pickup_dz1[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZ1_AMTZ)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.pickup_dz1_amtz[group]; //� ����� value ������� �������� �������
          else value = edition_settings.pickup_dz1_amtz[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZ2_ANGLE)
        {
          vaga = 10; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.pickup_dz2_angle[group]; //� ����� value ������� �������� �������
          else value = edition_settings.pickup_dz2_angle[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZ2_DIR)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.pickup_dz2_dir[group]; //� ����� value ������� �������� �������
          else value = edition_settings.pickup_dz2_dir[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZ2_INV)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.pickup_dz2_inv[group]; //� ����� value ������� �������� �������
          else value = edition_settings.pickup_dz2_inv[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZ2_AMTZ)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.pickup_dz2_amtz[group]; //� ����� value ������� �������� �������
          else value = edition_settings.pickup_dz2_amtz[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZ3_ANGLE)
        {
          vaga = 10; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.pickup_dz3_angle[group]; //� ����� value ������� �������� �������
          else value = edition_settings.pickup_dz3_angle[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZ3_DIR)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.pickup_dz3_dir[group]; //� ����� value ������� �������� �������
          else value = edition_settings.pickup_dz3_dir[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZ3_INV)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.pickup_dz3_inv[group]; //� ����� value ������� �������� �������
          else value = edition_settings.pickup_dz3_inv[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZ3_AMTZ)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.pickup_dz3_amtz[group]; //� ����� value ������� �������� �������
          else value = edition_settings.pickup_dz3_amtz[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZ4_ANGLE)
        {
          vaga = 10; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.pickup_dz4_angle[group]; //� ����� value ������� �������� �������
          else value = edition_settings.pickup_dz4_angle[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZ4_DIR)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.pickup_dz4_dir[group]; //� ����� value ������� �������� �������
          else value = edition_settings.pickup_dz4_dir[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZ4_INV)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.pickup_dz4_inv[group]; //� ����� value ������� �������� �������
          else value = edition_settings.pickup_dz4_inv[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZ4_AMTZ)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.pickup_dz4_amtz[group]; //� ����� value ������� �������� �������
          else value = edition_settings.pickup_dz4_amtz[group];
        }
        
          lValue = value;
            if(lValue&0x8000000)
            {
             lValue = ~lValue;
             lValue++;
            }//if
        first_symbol = 0; //�������, �� �� ����� �������� ������ �� ���������
      }
      else
      {
        //� ������� ����� ����� �������� �������� �������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++)
        {
          if (index_of_ekran_tmp == INDEX_ML_STP_K_DZ)
          {
            if (
                ((j < COL_PICKUP_DZ_K_BEGIN) ||  (j > COL_PICKUP_DZ_K_END ))  &&
                (j != (COL_PICKUP_DZ_K_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZ_K_COMMA )working_ekran[i][j] = ',';
//            else if (j == (COL_PICKUP_DZ_K_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_A];
            else if (j == (COL_PICKUP_DZ_K_END + 2)) working_ekran[i][j] = ' ';
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZ_K_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZ1)
          {
            if (
                ((j < COL_PICKUP_DZ1_BEGIN) ||  (j > COL_PICKUP_DZ1_END ))  &&
                (j != (COL_PICKUP_DZ1_END + 2) && j != (COL_PICKUP_DZ1_END + 3))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZ1_COMMA )working_ekran[i][j] = ',';
            else if ((j >= (COL_PICKUP_DZ2_DIR_END + 2)) && (j <= (COL_PICKUP_DZ2_DIR_END + 2 + SIZE_R_DIMENSION - 1))) working_ekran[i][j] = resistance_dimension[index_language][j - (COL_PICKUP_DZ2_DIR_END + 2)];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZ1_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZ1_AMTZ)
          {
            if (
                ((j < COL_PICKUP_DZ1_AMTZ_BEGIN) ||  (j > COL_PICKUP_DZ1_AMTZ_END ))  &&
                (j != (COL_PICKUP_DZ1_AMTZ_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZ1_AMTZ_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_PICKUP_DZ1_AMTZ_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_A];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZ1_AMTZ_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZ2_ANGLE)
          {
            if(value&0x8000000)
            {
             working_ekran[i][COL_SDZ2_ANGLE] = '-';
            }
            else working_ekran[i][COL_SDZ2_ANGLE] = '+';
            if (
                ((j < COL_PICKUP_DZ2_ANGLE_BEGIN) ||  (j > COL_PICKUP_DZ2_ANGLE_END ))  &&
                (j != (COL_PICKUP_DZ2_ANGLE_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == (COL_PICKUP_DZ2_ANGLE_END + 2)) working_ekran[i][j] = '�';
            else
              calc_int_symbol_and_put_into_working_ekran((working_ekran[i] + j), &lValue, &vaga, &first_symbol, view);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZ2_DIR)
          {
            if (
                ((j < COL_PICKUP_DZ2_DIR_BEGIN) ||  (j > COL_PICKUP_DZ2_DIR_END ))  &&
                (j != (COL_PICKUP_DZ2_DIR_END + 2) && j != (COL_PICKUP_DZ2_DIR_END + 3))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZ2_DIR_COMMA )working_ekran[i][j] = ',';
            else if ((j >= (COL_PICKUP_DZ2_DIR_END + 2)) && (j <= (COL_PICKUP_DZ2_DIR_END + 2 + SIZE_R_DIMENSION - 1))) working_ekran[i][j] = resistance_dimension[index_language][j - (COL_PICKUP_DZ2_DIR_END + 2)];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZ2_DIR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZ2_INV)
          {
            if (
                ((j < COL_PICKUP_DZ2_INV_BEGIN) ||  (j > COL_PICKUP_DZ2_INV_END ))  &&
                (j != (COL_PICKUP_DZ2_INV_END + 2) && j != (COL_PICKUP_DZ2_INV_END + 3))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZ2_INV_COMMA )working_ekran[i][j] = ',';
            else if ((j >= (COL_PICKUP_DZ2_INV_END + 2)) && (j <= (COL_PICKUP_DZ2_DIR_END + 2 + SIZE_R_DIMENSION - 1))) working_ekran[i][j] = resistance_dimension[index_language][j - (COL_PICKUP_DZ2_INV_END + 2)];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZ2_INV_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZ2_AMTZ)
          {
            if (
                ((j < COL_PICKUP_DZ2_AMTZ_BEGIN) ||  (j > COL_PICKUP_DZ2_AMTZ_END ))  &&
                (j != (COL_PICKUP_DZ2_AMTZ_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZ2_AMTZ_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_PICKUP_DZ2_AMTZ_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_A];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZ2_AMTZ_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZ3_ANGLE)
          {
            if(value&0x8000000)
            {
             working_ekran[i][COL_SDZ3_ANGLE] = '-';
            }
            else working_ekran[i][COL_SDZ3_ANGLE] = '+';
            if (
                ((j < COL_PICKUP_DZ3_ANGLE_BEGIN) ||  (j > COL_PICKUP_DZ3_ANGLE_END ))  &&
                (j != (COL_PICKUP_DZ3_ANGLE_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == (COL_PICKUP_DZ3_ANGLE_END + 2)) working_ekran[i][j] = '�';
            else
            {
              calc_int_symbol_and_put_into_working_ekran((working_ekran[i] + j), &lValue, &vaga, &first_symbol, view);
            } 
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZ3_DIR)
          {
            if (
                ((j < COL_PICKUP_DZ3_DIR_BEGIN) ||  (j > COL_PICKUP_DZ3_DIR_END ))  &&
                (j != (COL_PICKUP_DZ3_DIR_END + 2) && j != (COL_PICKUP_DZ3_DIR_END + 3))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZ3_DIR_COMMA )working_ekran[i][j] = ',';
            else if ((j >= (COL_PICKUP_DZ3_DIR_END + 2)) && (j <= (COL_PICKUP_DZ2_DIR_END + 2 + SIZE_R_DIMENSION - 1))) working_ekran[i][j] = resistance_dimension[index_language][j - (COL_PICKUP_DZ3_DIR_END + 2)];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZ3_DIR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZ3_INV)
          {
            if (
                ((j < COL_PICKUP_DZ3_INV_BEGIN) ||  (j > COL_PICKUP_DZ3_INV_END ))  &&
                (j != (COL_PICKUP_DZ3_INV_END + 2) && j != (COL_PICKUP_DZ3_INV_END + 3))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZ3_INV_COMMA )working_ekran[i][j] = ',';
            else if ((j >= (COL_PICKUP_DZ3_INV_END + 2)) && (j <= (COL_PICKUP_DZ2_DIR_END + 2 + SIZE_R_DIMENSION - 1))) working_ekran[i][j] = resistance_dimension[index_language][j - (COL_PICKUP_DZ3_INV_END + 2)];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZ3_INV_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZ3_AMTZ)
          {
            if (
                ((j < COL_PICKUP_DZ3_AMTZ_BEGIN) ||  (j > COL_PICKUP_DZ3_AMTZ_END ))  &&
                (j != (COL_PICKUP_DZ3_AMTZ_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZ3_AMTZ_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_PICKUP_DZ3_AMTZ_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_A];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZ3_AMTZ_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZ4_ANGLE)
          {
            if(value&0x8000000)
            {
             working_ekran[i][COL_SDZ4_ANGLE] = '-';
            }
            else working_ekran[i][COL_SDZ4_ANGLE] = '+';
            if (
                ((j < COL_PICKUP_DZ4_ANGLE_BEGIN) ||  (j > COL_PICKUP_DZ4_ANGLE_END ))  &&
                (j != (COL_PICKUP_DZ4_ANGLE_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == (COL_PICKUP_DZ4_ANGLE_END + 2)) working_ekran[i][j] = '�';
            else
              calc_int_symbol_and_put_into_working_ekran((working_ekran[i] + j), &lValue, &vaga, &first_symbol, view);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZ4_DIR)
          {
            if (
                ((j < COL_PICKUP_DZ4_DIR_BEGIN) ||  (j > COL_PICKUP_DZ4_DIR_END ))  &&
                (j != (COL_PICKUP_DZ4_DIR_END + 2) && j != (COL_PICKUP_DZ4_DIR_END + 3))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZ4_DIR_COMMA )working_ekran[i][j] = ',';
            else if ((j >= (COL_PICKUP_DZ4_DIR_END + 2)) && (j <= (COL_PICKUP_DZ2_DIR_END + 2 + SIZE_R_DIMENSION - 1))) working_ekran[i][j] = resistance_dimension[index_language][j - (COL_PICKUP_DZ4_DIR_END + 2)];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZ4_DIR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZ4_INV)
          {
            if (
                ((j < COL_PICKUP_DZ4_INV_BEGIN) ||  (j > COL_PICKUP_DZ4_INV_END ))  &&
                (j != (COL_PICKUP_DZ4_INV_END + 2) && j != (COL_PICKUP_DZ4_INV_END + 3))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZ4_INV_COMMA )working_ekran[i][j] = ',';
            else if ((j >= (COL_PICKUP_DZ4_INV_END + 2)) && (j <= (COL_PICKUP_DZ2_DIR_END + 2 + SIZE_R_DIMENSION - 1))) working_ekran[i][j] = resistance_dimension[index_language][j - (COL_PICKUP_DZ4_INV_END + 2)];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZ4_INV_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZ4_AMTZ)
          {
            if (
                ((j < COL_PICKUP_DZ4_AMTZ_BEGIN) ||  (j > COL_PICKUP_DZ4_AMTZ_END ))  &&
                (j != (COL_PICKUP_DZ4_AMTZ_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZ4_AMTZ_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_PICKUP_DZ4_AMTZ_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_A];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZ4_AMTZ_COMMA, view, 0);
          }

        }
      }//
        
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
    if (current_ekran.index_position == INDEX_ML_STP_K_DZ)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZ_K_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZ_K_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZ1)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZ1_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZ1_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZ1_AMTZ)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZ1_AMTZ_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZ1_AMTZ_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZ2_ANGLE)
    {
      current_ekran.position_cursor_x = COL_SDZ2_ANGLE;//COL_PICKUP_DZ2_ANGLE_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZ2_ANGLE_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZ2_DIR)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZ2_DIR_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZ2_DIR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZ2_INV)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZ2_INV_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZ2_INV_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZ2_AMTZ)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZ2_AMTZ_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZ2_AMTZ_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZ3_ANGLE)
    {
      current_ekran.position_cursor_x = COL_SDZ3_ANGLE;//COL_PICKUP_DZ3_ANGLE_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZ3_ANGLE_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZ3_DIR)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZ3_DIR_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZ3_DIR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZ3_INV)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZ3_INV_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZ3_INV_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZ3_AMTZ)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZ3_AMTZ_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZ3_AMTZ_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZ4_ANGLE)
    {
      current_ekran.position_cursor_x = COL_SDZ4_ANGLE;//COL_PICKUP_DZ4_ANGLE_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZ4_ANGLE_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZ4_DIR)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZ4_DIR_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZ4_DIR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZ4_INV)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZ4_INV_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZ4_INV_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZ4_AMTZ)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZ4_AMTZ_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZ4_AMTZ_END;
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
//������� ����� ����������� �������� ��
/*****************************************************/
void make_ekran_timeout_dz(unsigned int group)
{
  const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_TIMEOUT_DZ][MAX_COL_LCD] = 
  {
    {
      "  �������� ��1  ",
      "  �������� A���1",
      "�������� ��2 ���",
      "  ����� ��2 ��� ",
      "�������� ��2 ���",
      "  ����� ��2 ��� ",
      "  �������� A���2",
      "    ����� A���2 ",
      " ���� ����� ��2 ",
      "���� ����� A���2",
      "�������� ��3 ���",
      "  ����� ��3 ��� ",
      "�������� ��3 ���",
      "  ����� ��3 ��� ",
      "  �������� A���3",
      "    ����� A���3 ",
      " ���� ����� ��3 ",
      "���� ����� A���3",
      "�������� ��4 ���",
      "  ����� ��4 ��� ",
      "�������� ��4 ���",
      "  ����� ��4 ��� ",
      "  �������� A���4",
      "    ����� A���4 ",
      " ���� ����� ��4 ",
      "���� ����� A���4",
      "  �������� ���  ",
    },
    {
      "  �������� ��1  ",
      "  �������� A���1",
      "�������� ��2 ���",
      " ������� ��2 ���",
      "�������� ��2 ���",
      " ������� ��2 ���",
      "  �������� A���2",
      "  ������� A���2 ",
      " ���� ����� ��2 ",
      "���� ����� A���2",
      "�������� ��3 ���",
      " ������� ��3 ���",
      "�������� ��3 ���",
      " ������� ��3 ���",
      "  �������� A���3",
      "  ������� A���3 ",
      " ���� ����� ��3 ",
      "���� ����� A���3",
      "�������� ��4 ���",
      " ������� ��4 ���",
      "�������� ��4 ���",
      " ������� ��4 ���",
      "  �������� A���4",
      "  ������� A���4 ",
      " ���� ����� ��4 ",
      "���� ����� A���4",
      "  �������� ���  ",
    },
    {
      "  �������� ��1  ",
      "  �������� A���1",
      "�������� ��2 ���",
      "  ����� ��2 ��� ",
      "�������� ��2 ���",
      "  ����� ��2 ��� ",
      "  �������� A���2",
      "    ����� A���2 ",
      " ���� ����� ��2 ",
      "���� ����� A���2",
      "�������� ��3 ���",
      "  ����� ��3 ��� ",
      "�������� ��3 ���",
      "  ����� ��3 ��� ",
      "  �������� A���3",
      "    ����� A���3 ",
      " ���� ����� ��3 ",
      "���� ����� A���3",
      "�������� ��4 ���",
      "  ����� ��4 ��� ",
      "�������� ��4 ���",
      "  ����� ��4 ��� ",
      "  �������� A���4",
      "    ����� A���4 ",
      " ���� ����� ��4 ",
      "���� ����� A���4",
      "  �������� ���  ",
    },
    {
      "  �������� ��1  ",
      "  �������� A���1",
      "�������� ��2 ���",
      "  ����� ��2 ��� ",
      "�������� ��2 ���",
      "  ����� ��2 ��� ",
      "  �������� A���2",
      "    ����� A���2 ",
      " ���� ����� ��2 ",
      "���� ����� A���2",
      "�������� ��3 ���",
      "  ����� ��3 ��� ",
      "�������� ��3 ���",
      "  ����� ��3 ��� ",
      "  �������� A���3",
      "    ����� A���3 ",
      " ���� ����� ��3 ",
      "���� ����� A���3",
      "�������� ��4 ���",
      "  ����� ��4 ��� ",
      "�������� ��4 ���",
      "  ����� ��4 ��� ",
      "  �������� A���4",
      "    ����� A���4 ",
      " ���� ����� ��4 ",
      "���� ����� A���4",
      "  �������� ���  ",
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
    if (index_of_ekran_tmp < MAX_ROW_FOR_TIMEOUT_DZ)
    {
      if ((i & 0x1) == 0)
      {
        //� ��������� ����� ����� �������� ���������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_language][index_of_ekran_tmp][j];

        if (index_of_ekran_tmp == INDEX_ML_TMO_DZ1)
        {
          vaga = 10000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_dz1[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_dz1[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ1_AMTZ)
        {
          vaga = 10000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_dz1_amtz[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_dz1_amtz[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ2_DIR)
        {
          vaga = 10000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_dz2_dir[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_dz2_dir[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ2_DIR_PR)
        {
          vaga = 1000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_dz2_dir_pr[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_dz2_dir_pr[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ2_INV)
        {
          vaga = 10000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_dz2_inv[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_dz2_inv[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ2_INV_PR)
        {
          vaga = 1000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_dz2_inv_pr[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_dz2_inv_pr[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ2_AMTZ)
        {
          vaga = 10000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_dz2_amtz[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_dz2_amtz[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ2_AMTZ_PR)
        {
          vaga = 1000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_dz2_amtz_pr[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_dz2_amtz_pr[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ2_VVID_PR)
        {
          vaga = 1000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_dz2_vvid_pr[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_dz2_vvid_pr[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ2_AMTZ_VVID_PR)
        {
          vaga = 1000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_dz2_amtz_vvid_pr[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_dz2_amtz_vvid_pr[group];
        }

        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ3_DIR)
        {
          vaga = 10000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_dz3_dir[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_dz3_dir[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ3_DIR_PR)
        {
          vaga = 1000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_dz3_dir_pr[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_dz3_dir_pr[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ3_INV)
        {
          vaga = 10000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_dz3_inv[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_dz3_inv[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ3_INV_PR)
        {
          vaga = 1000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_dz3_inv_pr[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_dz3_inv_pr[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ3_AMTZ)
        {
          vaga = 10000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_dz3_amtz[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_dz3_amtz[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ3_AMTZ_PR)
        {
          vaga = 1000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_dz3_amtz_pr[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_dz3_amtz_pr[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ3_VVID_PR)
        {
          vaga = 1000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_dz3_vvid_pr[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_dz3_vvid_pr[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ3_AMTZ_VVID_PR)
        {
          vaga = 1000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_dz3_amtz_vvid_pr[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_dz3_amtz_vvid_pr[group];
        }

        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ4_DIR)
        {
          vaga = 10000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_dz4_dir[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_dz4_dir[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ4_DIR_PR)
        {
          vaga = 1000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_dz4_dir_pr[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_dz4_dir_pr[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ4_INV)
        {
          vaga = 10000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_dz4_inv[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_dz4_inv[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ4_INV_PR)
        {
          vaga = 1000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_dz4_inv_pr[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_dz4_inv_pr[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ4_AMTZ)
        {
          vaga = 10000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_dz4_amtz[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_dz4_amtz[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ4_AMTZ_PR)
        {
          vaga = 1000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_dz4_amtz_pr[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_dz4_amtz_pr[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ4_VVID_PR)
        {
          vaga = 1000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_dz4_vvid_pr[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_dz4_vvid_pr[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ4_AMTZ_VVID_PR)
        {
          vaga = 1000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_dz4_amtz_vvid_pr[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_dz4_amtz_vvid_pr[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_NKN_DZ)
        {
          vaga = 1000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_nkn_dz[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_nkn_dz[group];
        }

        first_symbol = 0; //�������, �� �� ����� �������� ������ �� ���������
      }
      else
      {
        //� ������� ����� ����� �������� �������� �������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++)
        {
          if (index_of_ekran_tmp == INDEX_ML_TMO_DZ1)
          {
            if (
                ((j < COL_TMO_DZ1_BEGIN) ||  (j > COL_TMO_DZ1_END )) &&
                (j != (COL_TMO_DZ1_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZ1_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZ1_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZ1_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ1_AMTZ)
          {
            if (
                ((j < COL_TMO_DZ1_AMTZ_BEGIN) ||  (j > COL_TMO_DZ1_AMTZ_END )) &&
                (j != (COL_TMO_DZ1_AMTZ_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZ1_AMTZ_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZ1_AMTZ_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZ1_AMTZ_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ2_DIR)
          {
            if (
                ((j < COL_TMO_DZ2_DIR_BEGIN) ||  (j > COL_TMO_DZ2_DIR_END )) &&
                (j != (COL_TMO_DZ2_DIR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZ2_DIR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZ2_DIR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZ2_DIR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ2_DIR_PR)
          {
            if (
                ((j < COL_TMO_DZ2_DIR_PR_BEGIN) ||  (j > COL_TMO_DZ2_DIR_PR_END )) &&
                (j != (COL_TMO_DZ2_DIR_PR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZ2_DIR_PR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZ2_DIR_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZ2_DIR_PR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ2_INV)
          {
            if (
                ((j < COL_TMO_DZ2_INV_BEGIN) ||  (j > COL_TMO_DZ2_INV_END )) &&
                (j != (COL_TMO_DZ2_INV_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZ2_INV_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZ2_INV_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZ2_INV_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ2_INV_PR)
          {
            if (
                ((j < COL_TMO_DZ2_INV_PR_BEGIN) ||  (j > COL_TMO_DZ2_INV_PR_END )) &&
                (j != (COL_TMO_DZ2_INV_PR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZ2_INV_PR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZ2_INV_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZ2_INV_PR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ2_AMTZ)
          {
            if (
                ((j < COL_TMO_DZ2_AMTZ_BEGIN) ||  (j > COL_TMO_DZ2_AMTZ_END )) &&
                (j != (COL_TMO_DZ2_AMTZ_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZ2_AMTZ_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZ2_AMTZ_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZ2_AMTZ_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ2_AMTZ_PR)
          {
            if (
                ((j < COL_TMO_DZ2_AMTZ_PR_BEGIN) ||  (j > COL_TMO_DZ2_AMTZ_PR_END )) &&
                (j != (COL_TMO_DZ2_AMTZ_PR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZ2_AMTZ_PR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZ2_AMTZ_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZ2_AMTZ_PR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ2_VVID_PR)
          {
            if (
                ((j < COL_TMO_DZ2_VVID_PR_BEGIN) ||  (j > COL_TMO_DZ2_VVID_PR_END )) &&
                (j != (COL_TMO_DZ2_VVID_PR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZ2_VVID_PR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZ2_VVID_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZ2_VVID_PR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ2_AMTZ_VVID_PR)
          {
            if (
                ((j < COL_TMO_DZ2_AMTZ_VVID_PR_BEGIN) ||  (j > COL_TMO_DZ2_AMTZ_VVID_PR_END )) &&
                (j != (COL_TMO_DZ2_AMTZ_VVID_PR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZ2_AMTZ_VVID_PR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZ2_AMTZ_VVID_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZ2_AMTZ_VVID_PR_COMMA, view, 0);
          }


          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ3_DIR)
          {
            if (
                ((j < COL_TMO_DZ3_DIR_BEGIN) ||  (j > COL_TMO_DZ3_DIR_END )) &&
                (j != (COL_TMO_DZ3_DIR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZ3_DIR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZ3_DIR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZ3_DIR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ3_DIR_PR)
          {
            if (
                ((j < COL_TMO_DZ3_DIR_PR_BEGIN) ||  (j > COL_TMO_DZ3_DIR_PR_END )) &&
                (j != (COL_TMO_DZ3_DIR_PR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZ3_DIR_PR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZ3_DIR_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZ3_DIR_PR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ3_INV)
          {
            if (
                ((j < COL_TMO_DZ3_INV_BEGIN) ||  (j > COL_TMO_DZ3_INV_END )) &&
                (j != (COL_TMO_DZ3_INV_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZ3_INV_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZ3_INV_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZ3_INV_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ3_INV_PR)
          {
            if (
                ((j < COL_TMO_DZ3_INV_PR_BEGIN) ||  (j > COL_TMO_DZ3_INV_PR_END )) &&
                (j != (COL_TMO_DZ3_INV_PR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZ3_INV_PR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZ3_INV_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZ3_INV_PR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ3_AMTZ)
          {
            if (
                ((j < COL_TMO_DZ3_AMTZ_BEGIN) ||  (j > COL_TMO_DZ3_AMTZ_END )) &&
                (j != (COL_TMO_DZ3_AMTZ_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZ3_AMTZ_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZ3_AMTZ_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZ3_AMTZ_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ3_AMTZ_PR)
          {
            if (
                ((j < COL_TMO_DZ3_AMTZ_PR_BEGIN) ||  (j > COL_TMO_DZ3_AMTZ_PR_END )) &&
                (j != (COL_TMO_DZ3_AMTZ_PR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZ3_AMTZ_PR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZ3_AMTZ_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZ3_AMTZ_PR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ3_VVID_PR)
          {
            if (
                ((j < COL_TMO_DZ3_VVID_PR_BEGIN) ||  (j > COL_TMO_DZ3_VVID_PR_END )) &&
                (j != (COL_TMO_DZ3_VVID_PR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZ3_VVID_PR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZ3_VVID_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZ3_VVID_PR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ3_AMTZ_VVID_PR)
          {
            if (
                ((j < COL_TMO_DZ3_AMTZ_VVID_PR_BEGIN) ||  (j > COL_TMO_DZ3_AMTZ_VVID_PR_END )) &&
                (j != (COL_TMO_DZ3_AMTZ_VVID_PR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZ3_AMTZ_VVID_PR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZ3_AMTZ_VVID_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZ3_AMTZ_VVID_PR_COMMA, view, 0);
          }


          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ4_DIR)
          {
            if (
                ((j < COL_TMO_DZ4_DIR_BEGIN) ||  (j > COL_TMO_DZ4_DIR_END )) &&
                (j != (COL_TMO_DZ4_DIR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZ4_DIR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZ4_DIR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZ4_DIR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ4_DIR_PR)
          {
            if (
                ((j < COL_TMO_DZ4_DIR_PR_BEGIN) ||  (j > COL_TMO_DZ4_DIR_PR_END )) &&
                (j != (COL_TMO_DZ4_DIR_PR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZ4_DIR_PR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZ4_DIR_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZ4_DIR_PR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ4_INV)
          {
            if (
                ((j < COL_TMO_DZ4_INV_BEGIN) ||  (j > COL_TMO_DZ4_INV_END )) &&
                (j != (COL_TMO_DZ4_INV_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZ4_INV_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZ4_INV_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZ4_INV_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ4_INV_PR)
          {
            if (
                ((j < COL_TMO_DZ4_INV_PR_BEGIN) ||  (j > COL_TMO_DZ4_INV_PR_END )) &&
                (j != (COL_TMO_DZ4_INV_PR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZ4_INV_PR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZ4_INV_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZ4_INV_PR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ4_AMTZ)
          {
            if (
                ((j < COL_TMO_DZ4_AMTZ_BEGIN) ||  (j > COL_TMO_DZ4_AMTZ_END )) &&
                (j != (COL_TMO_DZ4_AMTZ_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZ4_AMTZ_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZ4_AMTZ_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZ4_AMTZ_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ4_AMTZ_PR)
          {
            if (
                ((j < COL_TMO_DZ4_AMTZ_PR_BEGIN) ||  (j > COL_TMO_DZ4_AMTZ_PR_END )) &&
                (j != (COL_TMO_DZ4_AMTZ_PR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZ4_AMTZ_PR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZ4_AMTZ_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZ4_AMTZ_PR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ4_VVID_PR)
          {
            if (
                ((j < COL_TMO_DZ4_VVID_PR_BEGIN) ||  (j > COL_TMO_DZ4_VVID_PR_END )) &&
                (j != (COL_TMO_DZ4_VVID_PR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZ4_VVID_PR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZ4_VVID_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZ4_VVID_PR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ4_AMTZ_VVID_PR)
          {
            if (
                ((j < COL_TMO_DZ4_AMTZ_VVID_PR_BEGIN) ||  (j > COL_TMO_DZ4_AMTZ_VVID_PR_END )) &&
                (j != (COL_TMO_DZ4_AMTZ_VVID_PR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZ4_AMTZ_VVID_PR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZ4_AMTZ_VVID_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZ4_AMTZ_VVID_PR_COMMA, view, 0);
          }

          else if (index_of_ekran_tmp == INDEX_ML_TMO_NKN_DZ)
          {
            if (
                ((j < COL_TMO_NKN_DZ_BEGIN) ||  (j > COL_TMO_NKN_DZ_END )) &&
                (j != (COL_TMO_NKN_DZ_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_NKN_DZ_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_NKN_DZ_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_NKN_DZ_COMMA, view, 0);
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
    if (current_ekran.index_position == INDEX_ML_TMO_DZ1) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZ1_BEGIN;
      last_position_cursor_x = COL_TMO_DZ1_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZ1_AMTZ) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZ1_AMTZ_BEGIN;
      last_position_cursor_x = COL_TMO_DZ1_AMTZ_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZ2_DIR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZ2_DIR_BEGIN;
      last_position_cursor_x = COL_TMO_DZ2_DIR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZ2_DIR_PR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZ2_DIR_PR_BEGIN;
      last_position_cursor_x = COL_TMO_DZ2_DIR_PR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZ2_INV) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZ2_INV_BEGIN;
      last_position_cursor_x = COL_TMO_DZ2_INV_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZ2_INV_PR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZ2_INV_PR_BEGIN;
      last_position_cursor_x = COL_TMO_DZ2_INV_PR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZ2_AMTZ) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZ2_AMTZ_BEGIN;
      last_position_cursor_x = COL_TMO_DZ2_AMTZ_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZ2_AMTZ_PR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZ2_AMTZ_PR_BEGIN;
      last_position_cursor_x = COL_TMO_DZ2_AMTZ_PR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZ2_VVID_PR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZ2_VVID_PR_BEGIN;
      last_position_cursor_x = COL_TMO_DZ2_VVID_PR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZ2_AMTZ_VVID_PR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZ2_AMTZ_VVID_PR_BEGIN;
      last_position_cursor_x = COL_TMO_DZ2_AMTZ_VVID_PR_END;
    }

    else if (current_ekran.index_position == INDEX_ML_TMO_DZ3_DIR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZ3_DIR_BEGIN;
      last_position_cursor_x = COL_TMO_DZ3_DIR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZ3_DIR_PR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZ3_DIR_PR_BEGIN;
      last_position_cursor_x = COL_TMO_DZ3_DIR_PR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZ3_INV) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZ3_INV_BEGIN;
      last_position_cursor_x = COL_TMO_DZ3_INV_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZ3_INV_PR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZ3_INV_PR_BEGIN;
      last_position_cursor_x = COL_TMO_DZ3_INV_PR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZ3_AMTZ) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZ3_AMTZ_BEGIN;
      last_position_cursor_x = COL_TMO_DZ3_AMTZ_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZ3_AMTZ_PR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZ3_AMTZ_PR_BEGIN;
      last_position_cursor_x = COL_TMO_DZ3_AMTZ_PR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZ3_VVID_PR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZ3_VVID_PR_BEGIN;
      last_position_cursor_x = COL_TMO_DZ3_VVID_PR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZ3_AMTZ_VVID_PR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZ3_AMTZ_VVID_PR_BEGIN;
      last_position_cursor_x = COL_TMO_DZ3_AMTZ_VVID_PR_END;
    }

    else if (current_ekran.index_position == INDEX_ML_TMO_DZ4_DIR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZ4_DIR_BEGIN;
      last_position_cursor_x = COL_TMO_DZ4_DIR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZ4_DIR_PR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZ4_DIR_PR_BEGIN;
      last_position_cursor_x = COL_TMO_DZ4_DIR_PR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZ4_INV) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZ4_INV_BEGIN;
      last_position_cursor_x = COL_TMO_DZ4_INV_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZ4_INV_PR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZ4_INV_PR_BEGIN;
      last_position_cursor_x = COL_TMO_DZ4_INV_PR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZ4_AMTZ) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZ4_AMTZ_BEGIN;
      last_position_cursor_x = COL_TMO_DZ4_AMTZ_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZ4_AMTZ_PR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZ4_AMTZ_PR_BEGIN;
      last_position_cursor_x = COL_TMO_DZ4_AMTZ_PR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZ4_VVID_PR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZ4_VVID_PR_BEGIN;
      last_position_cursor_x = COL_TMO_DZ4_VVID_PR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZ4_AMTZ_VVID_PR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZ4_AMTZ_VVID_PR_BEGIN;
      last_position_cursor_x = COL_TMO_DZ4_AMTZ_VVID_PR_END;
    }

    else if (current_ekran.index_position == INDEX_ML_TMO_NKN_DZ) 
    {
      current_ekran.position_cursor_x = COL_TMO_NKN_DZ_BEGIN;
      last_position_cursor_x = COL_TMO_NKN_DZ_END;
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
//������� ����� ����������� �������� ����������� ���������� ��� DZ
/*****************************************************/
void make_ekran_control_dz(void)
{
  const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_CONTROL_DZ][MAX_COL_LCD] = 
  {
    {
      "      ��1       ",
      "     A���1      ",
      "      ��2       ",
      "   ��2 ������   ",
      "   ��2 �������� ",
      " ��� ��2 �� ��  ",
      " ��� ��2 �����  ",
      "     A���2      ",
      "      ��3       ",
      "   ��3 ������   ",
      "   ��3 �������� ",
      " ��� ��3 �� ��  ",
      " ��� ��3 �����  ",
      "     A���3      ",
      "      ��4       ",
      "   ��4 ������   ",
      "   ��4 �������� ",
      " ��� ��4 �� ��  ",
      " ��� ��4 �����  ",
      "     A���4      ",
      "      ���       ",
    },
    {
      "      ��1       ",
      "     A�C�1      ",
      "      ��2       ",
      "   ��2 �����    ",
      "   ��2 �������� ",
      "����� ��2 �� ��",
      "����� ��2 ����� ",
      "     A���2      ",
      "      ��3       ",
      "   ��3 �����    ",
      "   ��3 �������� ",
      "����� ��3 �� ��",
      "����� ��3 ����� ",
      "     A���3      ",
      "      ��4       ",
      "   ��4 �����    ",
      "   ��4 �������� ",
      "����� ��4 �� ��",
      "����� ��4 ����� ",
      "     A���4      ",
      "      ���       ",
    },
    {
      "      ��1       ",
      "     A���1      ",
      "      ��2       ",
      "   ��2 ������   ",
      "   ��2 �������� ",
      " ��� ��2 �� ��  ",
      " ��� ��2 �����  ",
      "     A���2      ",
      "      ��3       ",
      "   ��3 ������   ",
      "   ��3 �������� ",
      " ��� ��3 �� ��  ",
      " ��� ��3 �����  ",
      "     A���3      ",
      "      ��4       ",
      "   ��4 ������   ",
      "   ��4 �������� ",
      " ��� ��4 �� ��  ",
      " ��� ��4 �����  ",
      "     A���4      ",
      "      ���       ",
    },
    {
      "      ��1       ",
      "     A���1      ",
      "      ��2       ",
      "   ��2 ������   ",
      "   ��2 �������� ",
      " ��� ��2 �� ��  ",
      " ��� ��2 �����  ",
      "     A���2      ",
      "      ��3       ",
      "   ��3 ������   ",
      "   ��3 �������� ",
      " ��� ��3 �� ��  ",
      " ��� ��3 �����  ",
      "     A���3      ",
      "      ��4       ",
      "   ��4 ������   ",
      "   ��4 �������� ",
      " ��� ��4 �� ��  ",
      " ��� ��4 �����  ",
      "     A���4      ",
      "      ���       ",
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
    if (index_of_ekran_tmp < MAX_ROW_FOR_CONTROL_DZ)
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
          
        if(current_ekran.edition == 0) temp_data = current_settings.control_dz;
        else temp_data = edition_settings.control_dz;
          
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
