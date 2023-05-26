#include "header.h"


/*****************************************************/
//������� ����� ����������� ������� ��
/*****************************************************/
void make_ekran_setpoint_dzo(unsigned int group)
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_SETPOINT_DZO][MAX_COL_LCD] = 
  {
    {
      "���� ��� �������",
      "  ������� ��O1  ",
      "  ������� A���O1",
      "�����. ��O1 ����", 
      "   ����  ��O2   ",
      "  ������  ��O2  ",
      "  �������� ��O2 ",
      "  ������� A���O2",
      "��O3 �.�.�������",
      "��O3 �.�.�������",
      "  ������  ��O3  ",
      "  �������� ��O3 ",
      "  ������� A���O3",
      "Zo ������ ��O4  ",
      "Xo ������ ��O4  ",
      "Zo �������� ��O4",
      "Xo �������� ��O4",
      "  ������� A���O4",
    },
    {
      "� ��� ��� ����. ",
      "  ������� ��O1  ",
      "  ������� A���O1",
      "���.   ��O1 ����",
      "   ���  ��O2    ",
      "  �����  ��O2   ",
      "  �������� ��O2 ",
      "  ������� A���O2",
      "��O3 �.�.�������",
      "��O3 �.�.�������",
      "  �����  ��O3   ",
      "  �������� ��O3 ",
      "  ������� A���O3",
      " Zo �����  ��O4 ",
      " Xo_�����  ��O4 ",
      " Zo ������. ��O4",
      " Xo ������. ��O4",
      "  ������� A���O4",
    },
    {
      "E��� ��� �������",
      "E ������� ��O1  ",
      "E ������� A���O1",
      "E����. ��O1 ����", 
      "E  ����  ��O2   ",
      "E ������  ��O2  ",
      "E �������� ��O2 ",
      "E ������� A���O2",
      "E�O3 �.�.�������",
      "E�O3 �.�.�������",
      "E ������  ��O3  ",
      "E �������� ��O3 ",
      "E ������� A���O3",

      "Eo ������ ��O4  ",
      "Eo ������ ��O4  ",
      "Eo �������� ��O4",
      "Eo �������� ��O4",
      "E ������� A���O4",
    },
    {
      "���� ��� �������",
      "K ������� ��O1  ",
      "K ������� A���O1",
      "K����. ��O1 ����", 
      "K  ����  ��O2   ",
      "K ������  ��O2  ",
      "K �������� ��O2 ",
      "K ������� A���O2",
      "K�O3 �.�.�������",
      "K�O3 �.�.�������",
      "K ������  ��O3  ",
      "K �������� ��O3 ",
      "K ������� A���O3",
       
      "Ko ������ ��O4  ",
      "Ko ������ ��O4  ",
      "Ko �������� ��O4",
      "Ko �������� ��O4",
      "K ������� A���O4",
    },
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
    unsigned int view = (
                         (current_ekran.edition == 0) ||
                         (  
                          (position_temp != index_of_ekran_tmp) &&
                          !(
                            (index_of_ekran_tmp == INDEX_ML_STP_DZO3_ANGLE_H) && (position_temp == INDEX_ML_STP_DZO3_ANGLE_L) ||
                            (index_of_ekran_tmp == INDEX_ML_STP_DZO3_ANGLE_L) && (position_temp == INDEX_ML_STP_DZO3_ANGLE_H)
                           ) 
                         )   
                        );
    if (index_of_ekran_tmp < MAX_ROW_FOR_SETPOINT_DZO)//MAX_ROW_FOR_SETPOINT_DZ
    {
      if ((i & 0x1) == 0)
      {
        //� ��������� ����� ����� �������� ���������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_language][index_of_ekran_tmp][j];
        if (index_of_ekran_tmp == INDEX_ML_STP_K_ICE_DZO)//INDEX_ML_STP_K_DZ
        {
          vaga = 1000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.pickup_dzo_Io3g_Io1g[group]; //� ����� value ������� �������� �������
          else value = edition_settings.pickup_dzo_Io3g_Io1g[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZO1)//INDEX_ML_STP_DZ1
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.pickup_dzo1[group]; //� ����� value ������� �������� �������
          else value = edition_settings.pickup_dzo1[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZO1_AMTZ)//INDEX_ML_STP_DZ1_AMTZ
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.pickup_dzo1_amtz[group]; //� ����� value ������� �������� �������
          else value = edition_settings.pickup_dzo1_amtz[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZO1_I_BLK)//INDEX_ML_STP_DZ2_ANGLE
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.pickup_dzo1_blkI[group]; //� ����� value ������� �������� �������
          else value = edition_settings.pickup_dzo1_blkI[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZO2_ANGLE)//INDEX_ML_STP_DZ2_DIR
        {
          vaga = 10; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.pickup_dzo2_angle[group]; //� ����� value ������� �������� �������
          else value = edition_settings.pickup_dzo2_angle[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZO2_DIR)//INDEX_ML_STP_DZ2_INV
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.pickup_dzo2_dir[group]; //� ����� value ������� �������� �������
          else value = edition_settings.pickup_dzo2_dir[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZO2_INV)//INDEX_ML_STP_DZ2_AMTZ
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.pickup_dzo2_inv[group]; //� ����� value ������� �������� �������
          else value = edition_settings.pickup_dzo2_inv[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZO2_AMTZ)//INDEX_ML_STP_DZ3_ANGLE
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.pickup_dzo2_amtz[group]; //� ����� value ������� �������� �������
          else value = edition_settings.pickup_dzo2_amtz[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZO3_ANGLE_H)//INDEX_ML_STP_DZ3_DIR
        {
          vaga = 100; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.pickup_dzo3_angle_h[group]; //� ����� value ������� �������� �������
          else value = edition_settings.pickup_dzo3_angle_h[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZO3_ANGLE_L)//INDEX_ML_STP_DZ3_INV
        {
          vaga = 100; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.pickup_dzo3_angle_l[group]; //� ����� value ������� �������� �������
          else value = edition_settings.pickup_dzo3_angle_l[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZO3_DIR)//INDEX_ML_STP_DZ3_AMTZ
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.pickup_dzo3_dir[group]; //� ����� value ������� �������� �������
          else value = edition_settings.pickup_dzo3_dir[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZO3_INV)//INDEX_ML_STP_DZ4_ANGLE
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.pickup_dzo3_inv[group]; //� ����� value ������� �������� �������
          else value = edition_settings.pickup_dzo3_inv[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZO3_AMTZ)//INDEX_ML_STP_DZ4_DIR
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.pickup_dzo3_amtz[group]; //� ����� value ������� �������� �������
          else value = edition_settings.pickup_dzo3_amtz[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZO4_Z0_DIR)//INDEX_ML_STP_DZ4_INV
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.pickup_dzo4_Zo_dir[group]; //� ����� value ������� �������� �������
          else value = edition_settings.pickup_dzo4_Zo_dir[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZO4_X0_DIR)//INDEX_ML_STP_DZ4_AMTZ
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.pickup_dzo4_Xo_dir[group]; //� ����� value ������� �������� �������
          else value = edition_settings.pickup_dzo4_Xo_dir[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZO4_Z0_INV)//INDEX_ML_STP_DZ4_AMTZ
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.pickup_dzo4_Zo_inv[group]; //� ����� value ������� �������� �������
          else value = edition_settings.pickup_dzo4_Zo_inv[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZO4_X0_INV)//INDEX_ML_STP_DZ4_AMTZ
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.pickup_dzo4_Xo_inv[group]; //� ����� value ������� �������� �������
          else value = edition_settings.pickup_dzo4_Xo_inv[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_STP_DZO4_AMTZ)//INDEX_ML_STP_DZ4_AMTZ
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� �������
          if (view == true) value = current_settings.pickup_dzo4_amtz[group]; //� ����� value ������� �������� �������
          else value = edition_settings.pickup_dzo4_amtz[group];
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
          if (index_of_ekran_tmp == INDEX_ML_STP_K_ICE_DZO)//INDEX_ML_STP_K_DZ
          {
            if (
                ((j < COL_PICKUP_DZO_K_ICE_BEGIN) ||  (j > COL_PICKUP_DZO_K_ICE_END ))  &&
                (j != (COL_PICKUP_DZO_K_ICE_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZO_K_ICE_COMMA )working_ekran[i][j] = ',';
//            else if (j == (COL_PICKUP_DZ_K_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_A];
            else if (j == (COL_PICKUP_DZO_K_ICE_END + 2)) working_ekran[i][j] = ' ';
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZO_K_ICE_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZO1)//INDEX_ML_STP_DZ1
          {
            if (
                ((j < COL_PICKUP_DZO1_BEGIN) ||  (j > COL_PICKUP_DZO1_END ))  &&
                (j != (COL_PICKUP_DZO1_END + 2) && j != (COL_PICKUP_DZO1_END + 3))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZO1_COMMA )working_ekran[i][j] = ',';
            else if ((j >= (COL_PICKUP_DZ2_DIR_END + 2)) && (j <= (COL_PICKUP_DZ2_DIR_END + 2 + SIZE_R_DIMENSION - 1))) working_ekran[i][j] = resistance_dimension[index_language][j - (COL_PICKUP_DZ2_DIR_END + 2)];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZO1_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZO1_AMTZ)
          {
            if (
                ((j < COL_PICKUP_DZO1_AMTZ_BEGIN) ||  (j > COL_PICKUP_DZO1_AMTZ_END ))  &&
                (j != (COL_PICKUP_DZO1_AMTZ_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZO1_AMTZ_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_PICKUP_DZO1_AMTZ_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_A];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZO1_AMTZ_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZO1_I_BLK)
          {
            if (
                ((j < COL_PICKUP_DZO1_I_BLK_BEGIN) ||  (j > COL_PICKUP_DZO1_I_BLK_END ))  &&
                (j != (COL_PICKUP_DZO1_I_BLK_END + 2)) //&& j != (COL_PICKUP_DZO1_I_BLK_END + 3))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZO1_I_BLK_COMMA )working_ekran[i][j] = ',';
            else if ((j >= (COL_PICKUP_DZO1_I_BLK_END + 2)) && (j <= (COL_PICKUP_DZO1_I_BLK_END + 2 + SIZE_R_DIMENSION - 1))) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_A];//resistance_dimension[index_language][j - (COL_PICKUP_DZO1_I_BLK_END + 2)];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZO1_I_BLK_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZO2_ANGLE)
          {
            if(value&0x8000000)
            {
             working_ekran[i][COL_S_DZO2_ANGLE] = '-';//COL_SDZ2_ANGLE
            }
            else working_ekran[i][COL_S_DZO2_ANGLE] = '+';//COL_SDZ2_ANGLE
            if (
                ((j < COL_PICKUP_DZO2_ANGLE_BEGIN) ||  (j > COL_PICKUP_DZO2_ANGLE_END ))  &&
                (j != (COL_PICKUP_DZO2_ANGLE_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == (COL_PICKUP_DZO2_ANGLE_END + 2)) working_ekran[i][j] = '�';
            else
              calc_int_symbol_and_put_into_working_ekran((working_ekran[i] + j), &lValue, &vaga, &first_symbol, view);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZO2_DIR)
          {
            if (
                ((j < COL_PICKUP_DZO2_DIR_BEGIN) ||  (j > COL_PICKUP_DZO2_DIR_END ))  &&
                (j != (COL_PICKUP_DZO2_DIR_END + 2) && j != (COL_PICKUP_DZO2_DIR_END + 3))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZO2_DIR_COMMA )working_ekran[i][j] = ',';
            else if ((j >= (COL_PICKUP_DZO2_DIR_END + 2)) && (j <= (COL_PICKUP_DZO2_DIR_END + 2 + SIZE_R_DIMENSION - 1))) working_ekran[i][j] = resistance_dimension[index_language][j - (COL_PICKUP_DZO2_DIR_END + 2)];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZO2_DIR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZO2_INV)
          {
            if (
                ((j < COL_PICKUP_DZO2_INV_BEGIN) ||  (j > COL_PICKUP_DZO2_INV_END ))  &&
                (j != (COL_PICKUP_DZO2_INV_END + 2) && j != (COL_PICKUP_DZO2_INV_END + 3))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZO2_INV_COMMA )working_ekran[i][j] = ',';
            else if ((j >= (COL_PICKUP_DZO2_INV_END + 2)) && (j <= (COL_PICKUP_DZ2_DIR_END + 2 + SIZE_R_DIMENSION - 1))) working_ekran[i][j] = resistance_dimension[index_language][j - (COL_PICKUP_DZO2_INV_END + 2)];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZO2_INV_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZO2_AMTZ)
          {
            if (
                ((j < COL_PICKUP_DZO2_AMTZ_BEGIN) ||  (j > COL_PICKUP_DZO2_AMTZ_END ))  &&
                (j != (COL_PICKUP_DZO2_AMTZ_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZO2_AMTZ_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_PICKUP_DZO2_AMTZ_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_A];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZO2_AMTZ_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZO3_ANGLE_H)
          {
            if(value&0x8000000)
            {
             working_ekran[i][COL_DZO3_S_ANGLE_H] = '-';
            }
            else working_ekran[i][COL_DZO3_S_ANGLE_H] = '+';
            if (
                ((j < COL_PICKUP_DZO3_ANGLE_H_BEGIN) ||  (j > COL_PICKUP_DZO3_ANGLE_H_END ))  &&
                (j != (COL_PICKUP_DZO3_ANGLE_H_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == (COL_PICKUP_DZO3_ANGLE_H_END + 2)) working_ekran[i][j] = '�';
            else
            {
              calc_int_symbol_and_put_into_working_ekran((working_ekran[i] + j), &lValue, &vaga, &first_symbol, view);
            } 
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZO3_ANGLE_L)
          {
            if(value&0x8000000)
            {
             working_ekran[i][COL_DZO3_S_ANGLE_L] = '-';
            }
            else working_ekran[i][COL_DZO3_S_ANGLE_L] = '+';
            if (
                ((j < COL_PICKUP_DZO3_ANGLE_L_BEGIN) ||  (j > COL_PICKUP_DZO3_ANGLE_L_END ))  &&
                (j != (COL_PICKUP_DZO3_ANGLE_L_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == (COL_PICKUP_DZO3_ANGLE_L_END + 2)) working_ekran[i][j] = '�';
            else
            {
              calc_int_symbol_and_put_into_working_ekran((working_ekran[i] + j), &lValue, &vaga, &first_symbol, view);
            } 
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZO3_DIR)
          {
            if (
                ((j < COL_PICKUP_DZO3_DIR_BEGIN) ||  (j > COL_PICKUP_DZO3_DIR_END ))  &&
                (j != (COL_PICKUP_DZO3_DIR_END + 2) && j != (COL_PICKUP_DZO3_DIR_END + 3))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZO3_DIR_COMMA )working_ekran[i][j] = ',';
            else if ((j >= (COL_PICKUP_DZO3_DIR_END + 2)) && (j <= (COL_PICKUP_DZ2_DIR_END + 2 + SIZE_R_DIMENSION - 1))) working_ekran[i][j] = resistance_dimension[index_language][j - (COL_PICKUP_DZO3_DIR_END + 2)];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZO3_DIR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZO3_INV)
          {
            if (
                ((j < COL_PICKUP_DZO3_INV_BEGIN) ||  (j > COL_PICKUP_DZO3_INV_END ))  &&
                (j != (COL_PICKUP_DZO3_INV_END + 2) && j != (COL_PICKUP_DZO3_INV_END + 3))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZO3_INV_COMMA )working_ekran[i][j] = ',';
            else if ((j >= (COL_PICKUP_DZO3_INV_END + 2)) && (j <= (COL_PICKUP_DZ2_DIR_END + 2 + SIZE_R_DIMENSION - 1))) working_ekran[i][j] = resistance_dimension[index_language][j - (COL_PICKUP_DZO3_INV_END + 2)];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZO3_INV_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZO3_AMTZ)
          {
            if (
                ((j < COL_PICKUP_DZO3_AMTZ_BEGIN) ||  (j > COL_PICKUP_DZO3_AMTZ_END ))  &&
                (j != (COL_PICKUP_DZO3_AMTZ_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZO3_AMTZ_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_PICKUP_DZO3_AMTZ_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_A];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZO3_AMTZ_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZO4_Z0_DIR)
          {
            if (
                ((j < COL_PICKUP_DZO4_Z0_DIR_BEGIN) ||  (j > COL_PICKUP_DZO4_Z0_DIR_END ))  &&
                (j != (COL_PICKUP_DZO4_Z0_DIR_END + 2) && j != (COL_PICKUP_DZO4_Z0_DIR_END + 3))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZO4_Z0_DIR_COMMA )working_ekran[i][j] = ',';
            else if ((j >= (COL_PICKUP_DZO4_Z0_DIR_END + 2)) && (j <= (COL_PICKUP_DZ2_DIR_END + 2 + SIZE_R_DIMENSION - 1))) working_ekran[i][j] = resistance_dimension[index_language][j - (COL_PICKUP_DZO4_Z0_DIR_END + 2)];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZO4_Z0_DIR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZO4_X0_DIR)
          {
            if (
                ((j < COL_PICKUP_DZO4_X0_DIR_BEGIN) ||  (j > COL_PICKUP_DZO4_X0_DIR_END ))  &&
                (j != (COL_PICKUP_DZO4_X0_DIR_END + 2) && j != (COL_PICKUP_DZO4_X0_DIR_END + 3))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZO4_X0_DIR_COMMA  )working_ekran[i][j] = ',';
            else if ((j >= (COL_PICKUP_DZO4_X0_DIR_END + 2)) && (j <= (COL_PICKUP_DZ2_DIR_END + 2 + SIZE_R_DIMENSION - 1))) working_ekran[i][j] = resistance_dimension[index_language][j - (COL_PICKUP_DZO4_X0_DIR_END + 2)];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZO4_X0_DIR_COMMA , view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZO4_Z0_INV)
          {
            if (
                ((j < COL_PICKUP_DZO4_Z0_INV_BEGIN) ||  (j > COL_PICKUP_DZO4_Z0_INV_END ))  &&
                (j != (COL_PICKUP_DZO4_Z0_INV_END + 2) && j != (COL_PICKUP_DZO4_Z0_INV_END + 3))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZO4_Z0_INV_COMMA )working_ekran[i][j] = ',';
            else if ((j >= (COL_PICKUP_DZO4_Z0_INV_END + 2)) && (j <= (COL_PICKUP_DZ2_DIR_END + 2 + SIZE_R_DIMENSION - 1))) working_ekran[i][j] = resistance_dimension[index_language][j - (COL_PICKUP_DZO4_Z0_INV_END + 2)];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZO4_Z0_INV_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZO4_X0_INV)
          {
            if (
                ((j < COL_PICKUP_DZO4_X0_INV_BEGIN) ||  (j > COL_PICKUP_DZO4_X0_INV_END ))  &&
                (j != (COL_PICKUP_DZO4_X0_INV_END + 2) && j != (COL_PICKUP_DZO4_X0_INV_END + 3))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZO4_X0_INV_COMMA )working_ekran[i][j] = ',';
            else if ((j >= (COL_PICKUP_DZO4_X0_INV_END + 2)) && (j <= (COL_PICKUP_DZ2_DIR_END + 2 + SIZE_R_DIMENSION - 1))) working_ekran[i][j] = resistance_dimension[index_language][j - (COL_PICKUP_DZO4_X0_INV_END + 2)];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZO4_X0_INV_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STP_DZO4_AMTZ)
          {
            if (
                ((j < COL_PICKUP_DZO4_AMTZ_BEGIN) ||  (j > COL_PICKUP_DZO4_AMTZ_END ))  &&
                (j != (COL_PICKUP_DZO4_AMTZ_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_PICKUP_DZO4_AMTZ_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_PICKUP_DZO4_AMTZ_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_A];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_PICKUP_DZO4_AMTZ_COMMA, view, 0);
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
    if (current_ekran.index_position == INDEX_ML_STP_K_ICE_DZO)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZO_K_ICE_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZO_K_ICE_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZO1)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZO1_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZO1_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZO1_AMTZ)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZO1_AMTZ_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZO1_AMTZ_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZO1_I_BLK)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZO1_I_BLK_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZO1_I_BLK_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZO2_ANGLE)
    {
      current_ekran.position_cursor_x = COL_S_DZO2_ANGLE;//COL_PICKUP_DZ2_ANGLE_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZO2_ANGLE_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZO2_DIR)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZO2_DIR_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZO2_DIR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZO2_INV)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZO2_DIR_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZO2_DIR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZO2_AMTZ)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZO2_AMTZ_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZO2_AMTZ_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZO3_ANGLE_H)
    {
      current_ekran.position_cursor_x = COL_DZO3_S_ANGLE_H;//COL_PICKUP_DZ3_ANGLE_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZO3_ANGLE_H_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZO3_ANGLE_L)
    {
      current_ekran.position_cursor_x = COL_DZO3_S_ANGLE_L;//COL_PICKUP_DZ3_ANGLE_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZO3_ANGLE_L_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZO3_DIR)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZ3_DIR_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZ3_DIR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZO3_INV)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZO3_INV_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZO3_INV_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZO3_AMTZ)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZO3_AMTZ_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZO3_AMTZ_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZO4_Z0_DIR)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZO4_Z0_DIR_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZO4_Z0_DIR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZO4_X0_DIR)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZO4_X0_DIR_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZO4_X0_DIR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZO4_Z0_INV)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZO4_Z0_INV_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZO4_Z0_INV_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZO4_X0_INV)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZO4_X0_INV_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZO4_X0_INV_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STP_DZ4_AMTZ)
    {
      current_ekran.position_cursor_x = COL_PICKUP_DZO4_ANGLE_BEGIN;
      last_position_cursor_x = COL_PICKUP_DZO4_ANGLE_END;
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
void make_ekran_timeout_dzo(unsigned int group)
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_TIMEOUT_DZO][MAX_COL_LCD] = 
  {
    {
      "  �������� ��O1 ",
      " �������� A���O1",
      "�������� ��O2���",
      "  ����� ��O2 ���",
      "�������� ��O2���",
      "  ����� ��O2 ���",
      " �������� A���O2",
      "   ����� A���O2 ",
      "���� ����� ��O2 ",
      "���� ���� A���O2",
      "�������� ��O3���",
      "  ����� ��O3 ���",
      "�������� ��O3���",
      "  ����� ��O3 ���",
      " �������� A���O3",
      "   ����� A���O3 ",
      "���� ����� ��O3 ",
      "���� ���� A���O3",
      "�������� ��O4���",
      "�������� ��O4���",
      " �������� A���O4",
      "�������� ��� ���",
    },
    {
      " �������� ��O1  ",
      " �������� A���O1",
      "�������� ��O2���",
      " ������� ��O2���",
      "�������� ��O2���",
      " ������� ��O2���",
      " �������� A���O2",
      " ������� A���O2 ",
      " ���� ����� ��O2",
      "��� ����� A���O2",
      "�������� ��O3���",
      " ������� ��O3���",
      "�������� ��O3���",
      " ������� ��O3���",
      " �������� A���O3",
      " ������� A���O3 ",
      " ���� ����� ��O3",
      "���� ���� A���O3",
      "�������� ��O4���",
      "�������� ��O4���",
      " �������� A���O4",
      " ����. ��� ���  ",
    },
    {
      "E  �������� ��O1",
      "E�������� A���O1",
      "E������� ��O2���",
      "E ����� ��O2 ���",
      "E������� ��O2���",
      "E ����� ��O2 ���",
      "E�������� A���O2",
      "E  ����� A���O2 ",
      "E��� ����� ��O2 ",
      "E��� ���� A���O2",
      "E������� ��O3���",
      "E ����� ��O3 ���",
      "E������� ��O3���",
      "E ����� ��O3 ���",
      "E�������� A���O3",
      "E  ����� A���O3 ",
      "E��� ����� ��O3 ",
      "E��� ���� A���O3",
      "E������� ��O4���",
      "E������� ��O4���",
      "E�������� A���O4",
      "E������� ��� ���",
    },
    {
      "K �������� ��O1 ",
      "K�������� A���O1",
      "K������� ��O2���",
      "K ����� ��O2 ���",
      "K������� ��O2���",
      "K ����� ��O2 ���",
      "K�������� A���O2",
      "K  ����� A���O2 ",
      "K��� ����� ��O2 ",
      "K��� ���� A���O2",
      "K������� ��O3���",
      "K ����� ��O3 ���",
      "K������� ��O3���",
      "K ����� ��O3 ���",
      "K�������� A���O3",
      "K  ����� A���O3 ",
      "K��� ����� ��O3 ",
      "K��� ���� A���O3",
      "K������� ��O4���",
      "K������� ��O4���",
      "K�������� A���O4",
      "K������� ��� ���",
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
    if (index_of_ekran_tmp < MAX_ROW_FOR_TIMEOUT_DZO)
    {
      if ((i & 0x1) == 0)
      {
        //� ��������� ����� ����� �������� ���������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_language][index_of_ekran_tmp][j];

        if (index_of_ekran_tmp == INDEX_ML_TMO_DZO1)
        {
          vaga = 10000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_dzo1[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_dzo1[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO1_AMTZ)
        {
          vaga = 10000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_dzo1_amtz[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_dzo1_amtz[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO2_DIR)
        {
          vaga = 10000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_dzo2_dir[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_dzo2_dir[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO2_DIR_PR)
        {
          vaga = 1000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_dzo2_dir_pr[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_dzo2_dir_pr[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO2_INV)
        {
          vaga = 10000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_dzo2_inv[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_dzo2_inv[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO2_INV_PR)
        {
          vaga = 1000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_dzo2_inv_pr[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_dzo2_inv_pr[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO2_AMTZ)
        {
          vaga = 10000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_dzo2_amtz[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_dzo2_amtz[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO2_AMTZ_PR)
        {
          vaga = 1000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_dzo2_amtz_pr[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_dzo2_amtz_pr[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO2_VVID_PR)
        {
          vaga = 1000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_dzo2_vvid_pr[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_dzo2_vvid_pr[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO2_AMTZ_VVID_PR)
        {
          vaga = 1000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_dzo2_amtz_vvid_pr[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_dzo2_amtz_vvid_pr[group];
        }

        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO3_DIR)
        {
          vaga = 10000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_dzo3_dir[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_dzo3_dir[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO3_DIR_PR)
        {
          vaga = 1000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_dzo3_dir_pr[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_dzo3_dir_pr[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO3_INV)
        {
          vaga = 10000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_dzo3_inv[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_dzo3_inv[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO3_INV_PR)
        {
          vaga = 1000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_dzo3_inv_pr[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_dzo3_inv_pr[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO3_AMTZ)
        {
          vaga = 10000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_dzo3_amtz[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_dzo3_amtz[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO3_AMTZ_PR)
        {
          vaga = 1000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_dzo3_amtz_pr[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_dzo3_amtz_pr[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO3_VVID_PR)
        {
          vaga = 1000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_dzo3_vvid_pr[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_dzo3_vvid_pr[group];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO3_AMTZ_VVID_PR)
        {
          vaga = 1000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_dzo3_amtz_vvid_pr[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_dzo3_amtz_vvid_pr[group];
        }

        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO4_DIR)
        {
          vaga = 10000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_dzo4_dir[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_dzo4_dir[group];
        }
        //else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ4_DIR_PR)
        //{
        //  vaga = 1000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
        //  if (view == true) value = current_settings.timeout_dz4_dir_pr[group]; //� ����� value ������� �������� ��������
        //  else value = edition_settings.timeout_dz4_dir_pr[group];
        //}
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO4_INV)
        {
          vaga = 10000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_dzo4_inv[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_dzo4_inv[group];
        }
        //else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ4_INV_PR)
        //{
        //  vaga = 1000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
        //  if (view == true) value = current_settings.timeout_dz4_inv_pr[group]; //� ����� value ������� �������� ��������
        //  else value = edition_settings.timeout_dz4_inv_pr[group];
        //}
        else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO4_AMTZ)
        {
          vaga = 10000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_dzo4_amtz[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_dzo4_amtz[group];
        }
        //else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ4_AMTZ_PR)
        //{
        //  vaga = 1000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
        //  if (view == true) value = current_settings.timeout_dz4_amtz_pr[group]; //� ����� value ������� �������� ��������
        //  else value = edition_settings.timeout_dz4_amtz_pr[group];
        //}
        //else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ4_VVID_PR)
        //{
        //  vaga = 1000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
        //  if (view == true) value = current_settings.timeout_dz4_vvid_pr[group]; //� ����� value ������� �������� ��������
        //  else value = edition_settings.timeout_dz4_vvid_pr[group];
        //}
        //else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ4_AMTZ_VVID_PR)
        //{
        //  vaga = 1000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
        //  if (view == true) value = current_settings.timeout_dz4_amtz_vvid_pr[group]; //� ����� value ������� �������� ��������
        //  else value = edition_settings.timeout_dz4_amtz_vvid_pr[group];
        //}
        else if (index_of_ekran_tmp == INDEX_ML_TMO_NKN_DZO)
        {
          vaga = 1000; //������������ ������� ���������� ��� �������� �������� ������� ��� ��������
          if (view == true) value = current_settings.timeout_nkn_dzo[group]; //� ����� value ������� �������� ��������
          else value = edition_settings.timeout_nkn_dzo[group];
        }

        first_symbol = 0; //�������, �� �� ����� �������� ������ �� ���������
      }
      else
      {
        //� ������� ����� ����� �������� �������� �������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++)
        {
          if (index_of_ekran_tmp == INDEX_ML_TMO_DZO1)
          {
            if (
                ((j < COL_TMO_DZO1_BEGIN) ||  (j > COL_TMO_DZO1_END )) &&
                (j != (COL_TMO_DZO1_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZO1_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZO1_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZO1_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO1_AMTZ)
          {
            if (
                ((j < COL_TMO_DZO1_AMTZ_BEGIN) ||  (j > COL_TMO_DZO1_AMTZ_END )) &&
                (j != (COL_TMO_DZO1_AMTZ_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZO1_AMTZ_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZO1_AMTZ_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZO1_AMTZ_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO2_DIR)
          {
            if (
                ((j < COL_TMO_DZO2_DIR_BEGIN) ||  (j > COL_TMO_DZO2_DIR_END )) &&
                (j != (COL_TMO_DZO2_DIR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZO2_DIR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZO2_DIR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZO2_DIR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO2_DIR_PR)
          {
            if (
                ((j < COL_TMO_DZO2_DIR_PR_BEGIN) ||  (j > COL_TMO_DZO2_DIR_PR_END )) &&
                (j != (COL_TMO_DZO2_DIR_PR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZO2_DIR_PR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZO2_DIR_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZO2_DIR_PR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO2_INV)
          {
            if (
                ((j < COL_TMO_DZO2_INV_BEGIN) ||  (j > COL_TMO_DZO2_INV_END )) &&
                (j != (COL_TMO_DZO2_INV_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZO2_INV_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZO2_INV_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZO2_INV_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO2_INV_PR)
          {
            if (
                ((j < COL_TMO_DZO2_INV_PR_BEGIN) ||  (j > COL_TMO_DZO2_INV_PR_END )) &&
                (j != (COL_TMO_DZO2_INV_PR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZO2_INV_PR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZO2_INV_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZO2_INV_PR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO2_AMTZ)
          {
            if (
                ((j < COL_TMO_DZO2_AMTZ_BEGIN) ||  (j > COL_TMO_DZO2_AMTZ_END )) &&
                (j != (COL_TMO_DZO2_AMTZ_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZO2_AMTZ_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZO2_AMTZ_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZO2_AMTZ_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO2_AMTZ_PR)
          {
            if (
                ((j < COL_TMO_DZO2_AMTZ_PR_BEGIN) ||  (j > COL_TMO_DZO2_AMTZ_PR_END )) &&
                (j != (COL_TMO_DZO2_AMTZ_PR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZO2_AMTZ_PR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZO2_AMTZ_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZO2_AMTZ_PR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO2_VVID_PR)
          {
            if (
                ((j < COL_TMO_DZO2_VVID_PR_BEGIN) ||  (j > COL_TMO_DZO2_VVID_PR_END )) &&
                (j != (COL_TMO_DZO2_VVID_PR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZO2_VVID_PR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZO2_VVID_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZO2_VVID_PR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO2_AMTZ_VVID_PR)
          {
            if (
                ((j < COL_TMO_DZO2_AMTZ_VVID_PR_BEGIN) ||  (j > COL_TMO_DZO2_AMTZ_VVID_PR_END )) &&
                (j != (COL_TMO_DZO2_AMTZ_VVID_PR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZO2_AMTZ_VVID_PR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZO2_AMTZ_VVID_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZO2_AMTZ_VVID_PR_COMMA, view, 0);
          }


          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO3_DIR)
          {
            if (
                ((j < COL_TMO_DZO3_DIR_BEGIN) ||  (j > COL_TMO_DZO3_DIR_END )) &&
                (j != (COL_TMO_DZO3_DIR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZO3_DIR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZO3_DIR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZO3_DIR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO3_DIR_PR)
          {
            if (
                ((j < COL_TMO_DZO3_DIR_PR_BEGIN) ||  (j > COL_TMO_DZO3_DIR_PR_END )) &&
                (j != (COL_TMO_DZO3_DIR_PR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZO3_DIR_PR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZO3_DIR_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZO3_DIR_PR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO3_INV)
          {
            if (
                ((j < COL_TMO_DZO3_INV_BEGIN) ||  (j > COL_TMO_DZO3_INV_END )) &&
                (j != (COL_TMO_DZO3_INV_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZO3_INV_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZO3_INV_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZO3_INV_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ3_INV_PR)
          {
            if (
                ((j < COL_TMO_DZO3_INV_PR_BEGIN) ||  (j > COL_TMO_DZO3_INV_PR_END )) &&
                (j != (COL_TMO_DZO3_INV_PR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZO3_INV_PR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZO3_INV_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZO3_INV_PR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO3_AMTZ)
          {
            if (
                ((j < COL_TMO_DZO3_AMTZ_BEGIN) ||  (j > COL_TMO_DZO3_AMTZ_END )) &&
                (j != (COL_TMO_DZO3_AMTZ_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZO3_AMTZ_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZO3_AMTZ_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZO3_AMTZ_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO3_AMTZ_PR)
          {
            if (
                ((j < COL_TMO_DZO3_AMTZ_PR_BEGIN) ||  (j > COL_TMO_DZO3_AMTZ_PR_END )) &&
                (j != (COL_TMO_DZO3_AMTZ_PR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZO3_AMTZ_PR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZO3_AMTZ_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZO3_AMTZ_PR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO3_VVID_PR)
          {
            if (
                ((j < COL_TMO_DZO3_VVID_PR_BEGIN) ||  (j > COL_TMO_DZO3_VVID_PR_END )) &&
                (j != (COL_TMO_DZO3_VVID_PR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZO3_VVID_PR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZO3_VVID_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZO3_VVID_PR_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO3_AMTZ_VVID_PR)
          {
            if (
                ((j < COL_TMO_DZO3_AMTZ_VVID_PR_BEGIN) ||  (j > COL_TMO_DZO3_AMTZ_VVID_PR_END )) &&
                (j != (COL_TMO_DZO3_AMTZ_VVID_PR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZO3_AMTZ_VVID_PR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZO3_AMTZ_VVID_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZO3_AMTZ_VVID_PR_COMMA, view, 0);
          }


          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO4_DIR)
          {
            if (
                ((j < COL_TMO_DZO4_DIR_BEGIN) ||  (j > COL_TMO_DZO4_DIR_END )) &&
                (j != (COL_TMO_DZO4_DIR_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZO4_DIR_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZO4_DIR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZO4_DIR_COMMA, view, 0);
          }
          //else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ4_DIR_PR)
          //{
          //  if (
          //      ((j < COL_TMO_DZ4_DIR_PR_BEGIN) ||  (j > COL_TMO_DZ4_DIR_PR_END )) &&
          //      (j != (COL_TMO_DZ4_DIR_PR_END + 2))  
          //     )working_ekran[i][j] = ' ';
          //  else if (j == COL_TMO_DZ4_DIR_PR_COMMA )working_ekran[i][j] = ',';
          //  else if (j == (COL_TMO_DZ4_DIR_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
          //  else
          //    calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZ4_DIR_PR_COMMA, view, 0);
          //}
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO4_INV)
          {
            if (
                ((j < COL_TMO_DZO4_INV_BEGIN) ||  (j > COL_TMO_DZO4_INV_END )) &&
                (j != (COL_TMO_DZO4_INV_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZO4_INV_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZO4_INV_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZO4_INV_COMMA, view, 0);
          }
          //else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ4_INV_PR)
          //{
          //  if (
          //      ((j < COL_TMO_DZ4_INV_PR_BEGIN) ||  (j > COL_TMO_DZ4_INV_PR_END )) &&
          //      (j != (COL_TMO_DZ4_INV_PR_END + 2))  
          //     )working_ekran[i][j] = ' ';
          //  else if (j == COL_TMO_DZ4_INV_PR_COMMA )working_ekran[i][j] = ',';
          //  else if (j == (COL_TMO_DZ4_INV_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
          //  else
          //    calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZ4_INV_PR_COMMA, view, 0);
          //}
          else if (index_of_ekran_tmp == INDEX_ML_TMO_DZO4_AMTZ)
          {
            if (
                ((j < COL_TMO_DZO4_AMTZ_BEGIN) ||  (j > COL_TMO_DZO4_AMTZ_END )) &&
                (j != (COL_TMO_DZO4_AMTZ_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_DZO4_AMTZ_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_DZO4_AMTZ_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZO4_AMTZ_COMMA, view, 0);
          }
          //else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ4_AMTZ_PR)
          //{
          //  if (
          //      ((j < COL_TMO_DZ4_AMTZ_PR_BEGIN) ||  (j > COL_TMO_DZ4_AMTZ_PR_END )) &&
          //      (j != (COL_TMO_DZ4_AMTZ_PR_END + 2))  
          //     )working_ekran[i][j] = ' ';
          //  else if (j == COL_TMO_DZ4_AMTZ_PR_COMMA )working_ekran[i][j] = ',';
          //  else if (j == (COL_TMO_DZ4_AMTZ_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
          //  else
          //    calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZ4_AMTZ_PR_COMMA, view, 0);
          //}
          //else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ4_VVID_PR)
          //{
          //  if (
          //      ((j < COL_TMO_DZ4_VVID_PR_BEGIN) ||  (j > COL_TMO_DZ4_VVID_PR_END )) &&
          //      (j != (COL_TMO_DZ4_VVID_PR_END + 2))  
          //     )working_ekran[i][j] = ' ';
          //  else if (j == COL_TMO_DZ4_VVID_PR_COMMA )working_ekran[i][j] = ',';
          //  else if (j == (COL_TMO_DZ4_VVID_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
          //  else
          //    calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZ4_VVID_PR_COMMA, view, 0);
          //}
          //else if (index_of_ekran_tmp == INDEX_ML_TMO_DZ4_AMTZ_VVID_PR)
          //{
          //  if (
          //      ((j < COL_TMO_DZ4_AMTZ_VVID_PR_BEGIN) ||  (j > COL_TMO_DZ4_AMTZ_VVID_PR_END )) &&
          //      (j != (COL_TMO_DZ4_AMTZ_VVID_PR_END + 2))  
          //     )working_ekran[i][j] = ' ';
          //  else if (j == COL_TMO_DZ4_AMTZ_VVID_PR_COMMA )working_ekran[i][j] = ',';
          //  else if (j == (COL_TMO_DZ4_AMTZ_VVID_PR_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
          //  else
          //    calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_DZ4_AMTZ_VVID_PR_COMMA, view, 0);
          //}

          else if (index_of_ekran_tmp == INDEX_ML_TMO_NKN_DZO)
          {
            if (
                ((j < COL_TMO_NKN_DZO_BEGIN) ||  (j > COL_TMO_NKN_DZO_END )) &&
                (j != (COL_TMO_NKN_DZO_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_NKN_DZO_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_NKN_DZO_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_NKN_DZO_COMMA, view, 0);
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
    if (current_ekran.index_position == INDEX_ML_TMO_DZO1) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZO1_BEGIN;
      last_position_cursor_x = COL_TMO_DZO1_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZO1_AMTZ) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZO1_AMTZ_BEGIN;
      last_position_cursor_x = COL_TMO_DZO1_AMTZ_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZO2_DIR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZO2_DIR_BEGIN;
      last_position_cursor_x = COL_TMO_DZO2_DIR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZO2_DIR_PR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZO2_DIR_PR_BEGIN;
      last_position_cursor_x = COL_TMO_DZO2_DIR_PR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZO2_INV) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZO2_INV_BEGIN;
      last_position_cursor_x = COL_TMO_DZO2_INV_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZO2_INV_PR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZO2_INV_PR_BEGIN;
      last_position_cursor_x = COL_TMO_DZO2_INV_PR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZO2_AMTZ) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZO2_AMTZ_BEGIN;
      last_position_cursor_x = COL_TMO_DZO2_AMTZ_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZO2_AMTZ_PR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZO2_AMTZ_PR_BEGIN;
      last_position_cursor_x = COL_TMO_DZO2_AMTZ_PR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZO2_VVID_PR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZO2_VVID_PR_BEGIN;
      last_position_cursor_x = COL_TMO_DZO2_VVID_PR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZO2_AMTZ_VVID_PR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZO2_AMTZ_VVID_PR_BEGIN;
      last_position_cursor_x = COL_TMO_DZ2_AMTZ_VVID_PR_END;
    }

    else if (current_ekran.index_position == INDEX_ML_TMO_DZO3_DIR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZO3_DIR_BEGIN;
      last_position_cursor_x = COL_TMO_DZO3_DIR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZO3_DIR_PR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZO3_DIR_PR_BEGIN;
      last_position_cursor_x = COL_TMO_DZO3_DIR_PR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZO3_INV) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZO3_INV_BEGIN;
      last_position_cursor_x = COL_TMO_DZO3_INV_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZ3_INV_PR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZO3_INV_PR_BEGIN;
      last_position_cursor_x = COL_TMO_DZO3_INV_PR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZO3_AMTZ) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZO3_AMTZ_BEGIN;
      last_position_cursor_x = COL_TMO_DZO3_AMTZ_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZO3_AMTZ_PR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZO3_AMTZ_PR_BEGIN;
      last_position_cursor_x = COL_TMO_DZO3_AMTZ_PR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZO3_VVID_PR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZO3_VVID_PR_BEGIN;
      last_position_cursor_x = COL_TMO_DZO3_VVID_PR_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMO_DZO3_AMTZ_VVID_PR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZO3_AMTZ_VVID_PR_BEGIN;
      last_position_cursor_x = COL_TMO_DZO3_AMTZ_VVID_PR_END;
    }

    else if (current_ekran.index_position == INDEX_ML_TMO_DZO4_DIR) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZO4_DIR_BEGIN;
      last_position_cursor_x = COL_TMO_DZO4_DIR_END;
    }
    //else if (current_ekran.index_position == INDEX_ML_TMO_DZ4_DIR_PR) 
    //{
    //  current_ekran.position_cursor_x = COL_TMO_DZ4_DIR_PR_BEGIN;
    //  last_position_cursor_x = COL_TMO_DZ4_DIR_PR_END;
    //}
    else if (current_ekran.index_position == INDEX_ML_TMO_DZO4_INV) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZO4_INV_BEGIN;
      last_position_cursor_x = COL_TMO_DZO4_INV_END;
    }
    //else if (current_ekran.index_position == INDEX_ML_TMO_DZ4_INV_PR) 
    //{
    //  current_ekran.position_cursor_x = COL_TMO_DZ4_INV_PR_BEGIN;
    //  last_position_cursor_x = COL_TMO_DZ4_INV_PR_END;
    //}
    else if (current_ekran.index_position == INDEX_ML_TMO_DZO4_AMTZ) 
    {
      current_ekran.position_cursor_x = COL_TMO_DZO4_AMTZ_BEGIN;
      last_position_cursor_x = COL_TMO_DZO4_AMTZ_END;
    }
    //else if (current_ekran.index_position == INDEX_ML_TMO_DZ4_AMTZ_PR) 
    //{
    //  current_ekran.position_cursor_x = COL_TMO_DZ4_AMTZ_PR_BEGIN;
    //  last_position_cursor_x = COL_TMO_DZ4_AMTZ_PR_END;
    //}
    //else if (current_ekran.index_position == INDEX_ML_TMO_DZ4_VVID_PR) 
    //{
    //  current_ekran.position_cursor_x = COL_TMO_DZ4_VVID_PR_BEGIN;
    //  last_position_cursor_x = COL_TMO_DZ4_VVID_PR_END;
    //}
    //else if (current_ekran.index_position == INDEX_ML_TMO_DZ4_AMTZ_VVID_PR) 
    //{
    //  current_ekran.position_cursor_x = COL_TMO_DZ4_AMTZ_VVID_PR_BEGIN;
    //  last_position_cursor_x = COL_TMO_DZ4_AMTZ_VVID_PR_END;
    //}

    else if (current_ekran.index_position == INDEX_ML_TMO_NKN_DZO) 
    {
      current_ekran.position_cursor_x = COL_TMO_NKN_DZO_BEGIN;
      last_position_cursor_x = COL_TMO_NKN_DZO_END;
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
void make_ekran_control_dzo(void)
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_CONTROL_DZO][MAX_COL_LCD] = 
  {
    {
      "������.����.��� ",//1
      "��� ���1 I��� 3�",//2
      "��� ���1 I���   ",//3
      "��T� ��� 1      ",//4
      "��� 1           ",//5
      "���� �����.���2 ",//6
      "��� ���2 ��  ��O",//7
      "��� ���2 IO��3� ",//8
      "���� ���2       ",//9
      "��� 2           ",//10
      "���2 ����       ",//11
      "���2 ���        ",//12
      "���� ���.  ���3 ",//13
      "��� ���3 ��  ��O",//14
      "��� ���3 IO��3� ",//15
      "��T� ���3       ",//16
      "���3            ",//17
      "���3 ����       ",//18
      "���3 ���        ",//19
      "��� ���4 IO��3� ",//20
      "��T� ���4       ",//21
      "���4            ",//22
      "���4 ����       ",//23
      "���4 ���        " //24
    },
    {
      "�����.����.���  ",//1
      "��� ���1 I��� 3�",//2
      "��� ���1 I���   ",//3
      "���� ��� 1      ",//4
      "��� 1           ",//5
      "���� �����.���2 ",//6
      "����� ���2 ��O  ",//7
      "��� ���2 IO��3� ",//8
      "���� ���2       ",//9
      "���2            ",//10
      "���2 ����       ",//11
      "���2 ����       ",//12
      "���� ����� ���3 ",//13
      "����� ���3 ��O  ",//14
      "��� ���3 IO��3� ",//15
      "���� ���3       ",//16
      "���3 : �����   ",//17
      "���3 ����       ",//18
      "���3 ����       ",//19
      "��� ���4 IO��3� ",//20
      "���� ���4       ",//21
      "���4            ",//22
      "���4 ����       ",//23
      "���4 ����       ",//24
    },
    {
      "������.����.���E",//
      "��� ���1 I��� 3E",//
      "��� ���1 I���  E",//
      "���� ��� 1     E",//
      "��� 1          E",//
      "���� �����.���2E",//
      "��� ���2 ��  ��E",//
      "��� ���2 IO��3�E",//
      "���� ���2      E",//
      "��� 2          E",//
      "���2 ����      E",//
      "���2 ���       E",//
      "���� ���.  ���3E",//
      "��� ���3 ��  ��E",//
      "��� ���3 IO��3�E",//
      "���� ���3      E",//
      "���3           E",//
      "���3 ����      E",//
      "���3 ���       E",//
      "��� ���4 IO��3�E",//
      "���� ���4      E",//
      "���4           E",//
      "���4 ����      E",//
      "���4 ���       E",//
    },
    {
      "������.����.���K",//1
      "��� ���1 I��� 3K",//2
      "��� ���1 I���  K",//3
      "���� ��� 1     K",//4
      "��� 1          K",//5
      "���� �����.���2K",//6
      "��� ���2 ��  ��K",//7
      "��� ���2 IO��3�K",//8
      "���� ���2      K",//9
      "��� 2          K",//10
      "���2 ����      K",//11
      "���2 ���       K",//12
      "���� ���.  ���3K",//13
      "��� ���3 ��  ��K",//14
      "��� ���3 IO��3�K",//15
      "���� ���3      K",//16
      "���3           K",//17
      "���3 ����      K",//18
      "���3 ���       K",//19
      "��� ���4 IO��3�K",//20
      "���� ���4      K",//21
      "���4           K",//22
      "���4 ����      K",//23
      "���4 ���       K",//24
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
    if (index_of_ekran_tmp < MAX_ROW_FOR_CONTROL_DZO)
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
          
        if(current_ekran.edition == 0) temp_data = current_settings.control_dzo;
        else temp_data = edition_settings.control_dzo;
          
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
