#include "header.h"

/*****************************************************/
//������� ����� ����������� �������� ���
/*****************************************************/
void make_ekran_timeout_apv(unsigned int group)
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_TIMEOUT_APV][MAX_COL_LCD] = 
  {
    {
      "   1 ���� ���   ",
      "   2 ���� ���   ",
      "   3 ���� ���   ",
      "   4 ���� ���   ",
      "    ���.���1    ",
      "    ���.���2    ",
      "    ���.���3    ",
      "    ���.���4    ",
      " ���.��� �� ��  "
    },
    {
      "   1 ���� ���   ",
      "   2 ���� ���   ",
      "   3 ���� ���   ",
      "   4 ���� ���   ",
      "    ��.���1     ",
      "    ��.���2     ",
      "    ��.���3     ",
      "    ��.���4     ",
      " ��.��� �� ��  "
    },
    {
      "   AR Shot 1    ",
      "   AR Shot 2    ",
      "   AR Shot 3    ",
      "   AR Shot 4    ",
      "  AR1 Blocking  ",
      "  AR2 Blocking  ",
      "  AR3 Blocking  ",
      "  AR4 Blocking  ",
      "AR Block from CB"
    },
    {
      "   1 ���� ���   ",
      "   2 ���� ���   ",
      "   3 ���� ���   ",
      "   4 ���� ���   ",
      "    ���.���1    ",
      "    ���.���2    ",
      "    ���.���3    ",
      "    ���.���4    ",
      " ���.��� �� ��  "
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
    if (index_of_ekran_tmp < MAX_ROW_FOR_TIMEOUT_APV)
    {
      if ((i & 0x1) == 0)
      {
        //� ��������� ����� ����� �������� ���������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_language][index_of_ekran_tmp][j];
        if (index_of_ekran_tmp == INDEX_ML_TMOAPV1)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� ������� ��� �������� 1 ����� ���
          if (view == true) value = current_settings.timeout_apv_1[group]; //� ����� value ������� �������� �������� 1 ����� ���
          else value = edition_settings.timeout_apv_1[group];
          first_symbol = 0; //�������, �� �� ����� �������� ������ �� ���������
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMOAPV2)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� ������� ��� �������� 2 ����� ���
          if (view == true) value = current_settings.timeout_apv_2[group]; //� ����� value ������� �������� �������� 2 ����� ���
          else value = edition_settings.timeout_apv_2[group];
          first_symbol = 0; //�������, �� �� ����� �������� ������ �� ���������
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMOAPV3)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� ������� ��� �������� 3 ����� ���
          if (view == true) value = current_settings.timeout_apv_3[group]; //� ����� value ������� �������� �������� 3 ����� ���
          else value = edition_settings.timeout_apv_3[group];
          first_symbol = 0; //�������, �� �� ����� �������� ������ �� ���������
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMOAPV4)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� ������� ��� �������� 4 ����� ���
          if (view == true) value = current_settings.timeout_apv_4[group]; //� ����� value ������� �������� �������� 4 ����� ���
          else value = edition_settings.timeout_apv_4[group];
          first_symbol = 0; //�������, �� �� ����� �������� ������ �� ���������
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMOAPV_BLOCK_VID_APV1)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� ������� ��� �������� ��� ��������� �� �������� ������
          if (view == true) value = current_settings.timeout_apv_block_vid_apv1[group]; //� ����� value ������� �������� �������� ��� ��������� �� �������� ������
          else value = edition_settings.timeout_apv_block_vid_apv1[group];
          first_symbol = 0; //�������, �� �� ����� �������� ������ �� ���������
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMOAPV_BLOCK_VID_APV2)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� ������� ��� �������� ��� ��������� �� �������� ������
          if (view == true) value = current_settings.timeout_apv_block_vid_apv2[group]; //� ����� value ������� �������� �������� ��� ��������� �� �������� ������
          else value = edition_settings.timeout_apv_block_vid_apv2[group];
          first_symbol = 0; //�������, �� �� ����� �������� ������ �� ���������
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMOAPV_BLOCK_VID_APV3)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� ������� ��� �������� ��� ��������� �� �������� ������
          if (view == true) value = current_settings.timeout_apv_block_vid_apv3[group]; //� ����� value ������� �������� �������� ��� ��������� �� �������� ������
          else value = edition_settings.timeout_apv_block_vid_apv3[group];
          first_symbol = 0; //�������, �� �� ����� �������� ������ �� ���������
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMOAPV_BLOCK_VID_APV4)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� ������� ��� �������� ��� ��������� �� �������� ������
          if (view == true) value = current_settings.timeout_apv_block_vid_apv4[group]; //� ����� value ������� �������� �������� ��� ��������� �� �������� ������
          else value = edition_settings.timeout_apv_block_vid_apv4[group];
          first_symbol = 0; //�������, �� �� ����� �������� ������ �� ���������
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMOAPV_BLOCK_VID_VV)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� ������� ��� �������� ��� ������ ��������� �������
          if (view == true) value = current_settings.timeout_apv_block_vid_VV[group]; //� ����� value ������� �������� ������� ��� ������ ��������� �������
          else value = edition_settings.timeout_apv_block_vid_VV[group];
          first_symbol = 0; //�������, �� �� ����� �������� ������ �� ���������
        }
      }
      else
      {
        //� ������� ����� ����� �������� �������� �������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++)
        {
          if (index_of_ekran_tmp == INDEX_ML_TMOAPV1)
          {
            if (
                ((j < COL_TMO_APV_1_BEGIN) ||  (j > COL_TMO_APV_1_END )) &&
                (j != (COL_TMO_APV_1_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_APV_1_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_APV_1_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_APV_1_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMOAPV2)
          {
            if (
                ((j < COL_TMO_APV_2_BEGIN) ||  (j > COL_TMO_APV_2_END )) &&
                (j != (COL_TMO_APV_2_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_APV_2_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_APV_2_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_APV_2_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMOAPV3)
          {
            if (
                ((j < COL_TMO_APV_3_BEGIN) ||  (j > COL_TMO_APV_3_END )) &&
                (j != (COL_TMO_APV_3_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_APV_3_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_APV_3_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_APV_3_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMOAPV4)
          {
            if (
                ((j < COL_TMO_APV_4_BEGIN) ||  (j > COL_TMO_APV_4_END )) &&
                (j != (COL_TMO_APV_4_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_APV_4_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_APV_4_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_APV_4_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMOAPV_BLOCK_VID_APV1)
          {
            if (
                ((j < COL_TMO_APV_BLOCK_VID_APV1_BEGIN) ||  (j > COL_TMO_APV_BLOCK_VID_APV1_END )) &&
                (j != (COL_TMO_APV_BLOCK_VID_APV1_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_APV_BLOCK_VID_APV1_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_APV_BLOCK_VID_APV1_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_APV_BLOCK_VID_APV1_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMOAPV_BLOCK_VID_APV2)
          {
            if (
                ((j < COL_TMO_APV_BLOCK_VID_APV2_BEGIN) ||  (j > COL_TMO_APV_BLOCK_VID_APV2_END )) &&
                (j != (COL_TMO_APV_BLOCK_VID_APV2_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_APV_BLOCK_VID_APV2_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_APV_BLOCK_VID_APV2_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_APV_BLOCK_VID_APV2_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMOAPV_BLOCK_VID_APV3)
          {
            if (
                ((j < COL_TMO_APV_BLOCK_VID_APV3_BEGIN) ||  (j > COL_TMO_APV_BLOCK_VID_APV3_END )) &&
                (j != (COL_TMO_APV_BLOCK_VID_APV3_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_APV_BLOCK_VID_APV3_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_APV_BLOCK_VID_APV3_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_APV_BLOCK_VID_APV3_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMOAPV_BLOCK_VID_APV4)
          {
            if (
                ((j < COL_TMO_APV_BLOCK_VID_APV4_BEGIN) ||  (j > COL_TMO_APV_BLOCK_VID_APV4_END )) &&
                (j != (COL_TMO_APV_BLOCK_VID_APV4_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_APV_BLOCK_VID_APV4_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_APV_BLOCK_VID_APV4_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_APV_BLOCK_VID_APV4_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMOAPV_BLOCK_VID_VV)
          {
            if (
                ((j < COL_TMO_APV_BLOCK_VID_VV_BEGIN) ||  (j > COL_TMO_APV_BLOCK_VID_VV_END )) &&
                (j != (COL_TMO_APV_BLOCK_VID_VV_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_APV_BLOCK_VID_VV_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_APV_BLOCK_VID_VV_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_APV_BLOCK_VID_VV_COMMA, view, 0);
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
    if (current_ekran.index_position == INDEX_ML_TMOAPV1) 
    {
      current_ekran.position_cursor_x = COL_TMO_APV_1_BEGIN;
      last_position_cursor_x = COL_TMO_APV_1_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMOAPV2) 
    {
      current_ekran.position_cursor_x = COL_TMO_APV_2_BEGIN;
      last_position_cursor_x = COL_TMO_APV_2_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMOAPV3) 
    {
      current_ekran.position_cursor_x = COL_TMO_APV_3_BEGIN;
      last_position_cursor_x = COL_TMO_APV_3_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMOAPV4) 
    {
      current_ekran.position_cursor_x = COL_TMO_APV_4_BEGIN;
      last_position_cursor_x = COL_TMO_APV_4_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMOAPV_BLOCK_VID_APV1) 
    {
      current_ekran.position_cursor_x = COL_TMO_APV_BLOCK_VID_APV1_BEGIN;
      last_position_cursor_x = COL_TMO_APV_BLOCK_VID_APV1_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMOAPV_BLOCK_VID_APV2) 
    {
      current_ekran.position_cursor_x = COL_TMO_APV_BLOCK_VID_APV2_BEGIN;
      last_position_cursor_x = COL_TMO_APV_BLOCK_VID_APV2_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMOAPV_BLOCK_VID_APV3) 
    {
      current_ekran.position_cursor_x = COL_TMO_APV_BLOCK_VID_APV3_BEGIN;
      last_position_cursor_x = COL_TMO_APV_BLOCK_VID_APV3_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMOAPV_BLOCK_VID_APV4) 
    {
      current_ekran.position_cursor_x = COL_TMO_APV_BLOCK_VID_APV4_BEGIN;
      last_position_cursor_x = COL_TMO_APV_BLOCK_VID_APV4_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMOAPV_BLOCK_VID_VV)
    {
      current_ekran.position_cursor_x = COL_TMO_APV_BLOCK_VID_VV_BEGIN;
      last_position_cursor_x = COL_TMO_APV_BLOCK_VID_VV_END;
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
//������� ����� ����������� �������� ����������� ���������� ��� ���
/*****************************************************/
void make_ekran_control_apv()
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_CONTROL_APV][MAX_COL_LCD] = 
  {
    {
      "      ���       ",
      "      ���2      ",
      "      ���3      ",
      "      ���4      ",
      "   ���� �� ��O1 ",
      " ���� �� ����O1 ",
      "   ���� �� ��O2 ",
      " ���� �� ����O2 ",
      "   ���� �� ��O3 ",
      " ���� �� ����O3 ",
      "   ���� �� ��O4 ",
      " ���� �� ����O4 ",
      "  ���� �� ���O1 ",
      "  ���� �� ���O2 ",
      "  ���� �� ���O3 ",
      "  ���� �� ���O4 ",
//!      " ���� �� ����1  ",
//!      " ���� �� ����2  ",
//!      " ���� �� ����3  ",
      "�.���.�� ��� ���",
      " ��.��� �� ����2"
    },
    {
      "      ���       ",
      "      ���2      ",
      "      ���3      ",
      "      ���4      ",
      "  ���� �� ��O1 ",
      " ���� �� ����O1",
      "  ���� �� ��O2 ",
      " ���� �� ����O2",
      "  ���� �� ��O3 ",
      " ���� �� ����O3",
      "  ���� �� ��OO4",
      " ���� �� ����O4",
      " ���� �� ���O1 ",
      " ���� �� ���O2 ",
      " ���� �� ���O3 ",
      " ���� �� ���O4 ",
//!      " ���� �� ����1 ",
//!      " ���� �� ����2 ",
//!      " ���� �� ����3 ",
      " �.��.�� ��� ���",
      "��.��� �� ����2"
    },
    {
      "       AR       ",
      "      AR2       ",
      "      AR3       ",
      "      AR4       ",
      " Start from ��O1",
      "Start from����O1",
      " Start from ��O2",
      "Start from����O2",
      " Start from ��O3",
      "Start from����O3",
      " Start from ��O4",
      "Start from����O4",
      " Start from OCP1",
      " Start from OCP2",
      " Start from OCP3",
      " Start from OCP4",
//!      " Start frm ����1",
//!      " Start frm ����2",
//!      " Start frm ����3",
      "�.���.�� ��� ���",
      " ��.��� �� ����2"
    },
    {
      "      ���       ",
      "      ���2      ",
      "      ���3      ",
      "      ���4      ",
      "   ���� �� ��O1 ",
      " ���� �� ����O1 ",
      "   ���� �� ��O2 ",
      " ���� �� ����O2 ",
      "   ���� �� ��O3 ",
      " ���� �� ����O3 ",
      "   ���� �� ��O4 ",
      " ���� �� ����O4 ",
      "  ���� �� ���O1 ",
      "  ���� �� ���O2 ",
      "  ���� �� ���O3 ",
      "  ���� �� ���O4 ",
//!      " ���� �� ����1  ",
//!      " ���� �� ����2  ",
//!      " ���� �� ����3  ",
      "�.���.�� ��� ���",
      " ��.��� �� ����2"
    }
  };
  unsigned char name_string_tmp[MAX_ROW_FOR_CONTROL_APV][MAX_COL_LCD];

  int index_language = index_language_in_array(current_settings.language);
  for(int index_1 = 0; index_1 < MAX_ROW_FOR_CONTROL_APV; index_1++)
  {
    for(int index_2 = 0; index_2 < MAX_COL_LCD; index_2++)
      name_string_tmp[index_1][index_2] = name_string[index_language][index_1][index_2];
  }
  
  unsigned int temp_data;
          
  if(current_ekran.edition == 0) temp_data = current_settings.control_apv;
  else temp_data = edition_settings.control_apv;
          
  /******************************************/
  //��������� ����, �� �� ����� ����������
  /******************************************/
  int position_temp = current_ekran.index_position;
  int index_of_ekran;

  int additional_current = 0;
  for (int current_index = 0; current_index < MAX_ROW_FOR_CONTROL_APV; current_index++ )
  {

    if (
        (  
         (
          (current_index >= INDEX_ML_CTRAPV_STARTED_FROM_DZ1) &&
          (current_index <= INDEX_ML_CTRAPV_STARTED_FROM_AMTDZ4)
         )   
         &&
         ((current_settings.configuration & (1<<DZ_BIT_CONFIGURATION)) == 0)
        )  
        ||
        (
         (
          (current_index >= INDEX_ML_CTRAPV_STARTED_FROM_MTZ1) &&
          (current_index <= INDEX_ML_CTRAPV_STARTED_FROM_MTZ4)
         )   
         &&
         //!((current_settings.configuration & (1<<MTZ1_BIT_CONFIGURATION)) == 0)
         ((current_settings.configuration & (1<<MCZO_BIT_CONFIGURATION)) == 0)
        )  
        //!||
        //!(
        //! (
        //!  (current_index >= INDEX_ML_CTRAPV_STARTED_FROM_TZNP1) &&
        //!  (current_index <= INDEX_ML_CTRAPV_STARTED_FROM_TZNP3)
        //! )   
        //! &&
        //! ((current_settings.configuration & (1<<TZNP_BIT_CONFIGURATION)) == 0)
        //!)  
        ||
        (
         (current_index == INDEX_ML_CTRAPV_BLK_CTRL_PRVV2)
         &&
         ((current_settings.configuration & (1<<UROV_BIT_CONFIGURATION)) == 0)
        )  
       )   
    {
      int i = current_index - additional_current;
      unsigned int maska_1, maska_2;
      maska_1 = (1 << i) - 1;
      maska_2 = (unsigned int)(~maska_1);
    
      if ((i+1) <= position_temp) position_temp--;
      do
      {
        for(unsigned int j = 0; j < MAX_COL_LCD; j++)
        {
          if ((i+1) < (MAX_ROW_FOR_CONTROL_APV - additional_current)) name_string_tmp[i][j] = name_string_tmp[i + 1][j];
          else name_string_tmp[i][j] = ' ';
        }
        i++;
      }
      while (i < (MAX_ROW_FOR_CONTROL_APV -  additional_current));
    
      unsigned int temp_data_1 = (temp_data >> 1) & maska_2;
      temp_data = (temp_data & maska_1) | temp_data_1;

      additional_current++;
    }
  }
  /******************************************/

  //�������� �� ��� �������� position_temp ������� ��� ����, �� �� ���� ������� �� ������������� ��� ����� (����� + ��������)
  index_of_ekran = ((position_temp<<1) >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;
  
  for (unsigned int i=0; i< MAX_ROW_LCD; i++)
  {
    int index_of_ekran_tmp = index_of_ekran >> 1;
    if (index_of_ekran_tmp < (MAX_ROW_FOR_CONTROL_APV - additional_current))
    {
      if ((i & 0x1) == 0)
      {
        //� ��������� ����� ����� �������� ���������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string_tmp[index_of_ekran_tmp][j];
      }
      else
      {
        //� ������� ����� ����� �������� �������� �������
        unsigned int index_ctr = index_of_ekran_tmp;

        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = information_off_on[index_language][(temp_data >> index_ctr) & 0x1][j];
        if (position_temp == index_of_ekran_tmp)current_ekran.position_cursor_x = cursor_x_off_on[index_language][(temp_data >> index_ctr) & 0x1];
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
