#include "header.h"

/*****************************************************/
//������� ����� ����������� ������� ����
/*****************************************************/
void make_ekran_setpoint_urov(unsigned int group)
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_SETPOINT_UROV][MAX_COL_LCD] = 
  {
    {
      "  ������� ����  "
    },
    {
      "  ������� ����  "
    },
    {
      "  CBFP Pickup   "
    },
    {
      "  ������� ����  "
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
    if (index_of_ekran_tmp < MAX_ROW_FOR_SETPOINT_UROV)
    {
      if ((i & 0x1) == 0)
      {
        //� ��������� ����� ����� �������� ���������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_language][index_of_ekran_tmp][j];

        vaga = 1000; //������������ ������� ���������� ��� �������� �������� ������� ��� ������� ����
        if (view == true) value = current_settings.setpoint_urov[group]; //� ����� value ������� �������� ������� ��
        else value = edition_settings.setpoint_urov[group];
        first_symbol = 0; //�������, �� �� ����� �������� ������ �� ���������
      }
      else
      {
        //� ������� ����� ����� �������� �������� �������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++)
        {
          if (
              ((j < COL_SETPOINT_UROV_BEGIN) ||  (j > COL_SETPOINT_UROV_END )) &&
              (j != (COL_SETPOINT_UROV_END + 2))  
             )working_ekran[i][j] = ' ';
          else if (j == COL_SETPOINT_UROV_COMMA )working_ekran[i][j] = ',';
          else if (j == (COL_SETPOINT_UROV_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_A];
          else
            calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_SETPOINT_UROV_COMMA, view, 0);
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
    current_ekran.position_cursor_x = COL_SETPOINT_UROV_BEGIN;
    int last_position_cursor_x = COL_SETPOINT_UROV_END;

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
void make_ekran_timeout_urov(unsigned int group)
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_TIMEOUT_UROV][MAX_COL_LCD] = 
  {
    {
      " 1 ������� ���� ",
      " 2 ������� ���� "
    },
    {
      " 1 ������ ���� ",
      " 2 ������ ���� "
    },
    {
      "  CBFP Stage 1  ",
      "  CBFP Stage 2  "
    },
    {
      " 1 ������� ���� ",
      " 2 ������� ���� "
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
    if (index_of_ekran_tmp < MAX_ROW_FOR_TIMEOUT_UROV)
    {
      if ((i & 0x1) == 0)
      {
        //� ��������� ����� ����� �������� ���������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_language][index_of_ekran_tmp][j];
        if (index_of_ekran_tmp == INDEX_ML_TMOUROV1)
        {
          vaga = 10000; //������������ ������� ���������� ��� �������� �������� ������� ��� �������� 1 ������ ����
          if (view == true) value = current_settings.timeout_urov_1[group]; //� ����� value ������� �������� �������� 1 ������ ����
          else value = edition_settings.timeout_urov_1[group];
          first_symbol = 0; //�������, �� �� ����� �������� ������ �� ���������
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMOUROV2)
        {
          vaga = 10000; //������������ ������� ���������� ��� �������� �������� ������� ��� �������� 2 ������ ����
          if (view == true) value = current_settings.timeout_urov_2[group]; //� ����� value ������� �������� �������� 2 ������ ����
          else value = edition_settings.timeout_urov_2[group];
          first_symbol = 0; //�������, �� �� ����� �������� ������ �� ���������
        }
      }
      else
      {
        //� ������� ����� ����� �������� �������� �������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++)
        {
          if (index_of_ekran_tmp == INDEX_ML_TMOUROV1)
          {
            if (
                ((j < COL_TMO_UROV_1_BEGIN) ||  (j > COL_TMO_UROV_1_END )) &&
                (j != (COL_TMO_UROV_1_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_UROV_1_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_UROV_1_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_UROV_1_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMOUROV2)
          {
            if (
                ((j < COL_TMO_UROV_2_BEGIN) ||  (j > COL_TMO_UROV_2_END )) &&
                (j != (COL_TMO_UROV_2_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_UROV_2_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_UROV_2_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_UROV_2_COMMA, view, 0);
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
    if (current_ekran.index_position == INDEX_ML_TMOUROV1)
    {
      current_ekran.position_cursor_x = COL_TMO_UROV_1_BEGIN;
      last_position_cursor_x = COL_TMO_UROV_1_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMOUROV2)
    {
      current_ekran.position_cursor_x = COL_TMO_UROV_2_BEGIN;
      last_position_cursor_x = COL_TMO_UROV_2_END;
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
void make_ekran_control_urov()
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_CONTROL_UROV - NUMBER_UP + 1][MAX_COL_LCD] = 
  {
    {
      "      ����      ",
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
      "  ���� �� ���   ",
//!      "  ���� �� 3I0   ",
//!      "  ���� �� 3U0   ",
//!      "  ���� �� ���   ",
//!      " ���� �� ����1  ",
//!      " ���� �� ����2  ",
//!      " ���� �� ����3  ",
//!      "���� �� ���(���)",
      " ���� �� �����1 ",
      " ���� �� �����2 ",
      " ���� �� ������1",
      " ���� �� ������2",
      "  ���� �� ���1  ",
      "  ���� �� ���2  ",
      "  ���� �� ���   "
    },
    {
      "      ����      ",
      "  ���� �� ��O1 ",
      "���� �� ����O1 ",
      "  ���� �� ��O2 ",
      "���� �� ����O2 ",
      "  ���� �� ��O3 ",
      "���� �� ����O3 ",
      "  ���� �� ��O4 ",
      "���� �� ����O4 ",
      " ���� �� ���O1 ",
      " ���� �� ���O2 ",
      " ���� �� ���O3 ",
      " ���� �� ���O4 ",
      "  ���� �� ���  ",
//!      "  ���� �� 3I0  ",
//!      "  ���� �� 3U0  ",
//!      "  ���� �� ���  ",
//!      " ���� �� ����1 ",
//!      " ���� �� ����2 ",
//!      " ���� �� ����3 ",
//!      " �.�� ���(���) ",
      " ���� �� ����1",
      " ���� �� ����2",
      "���� �� ������1",
      "���� �� ������2",
      " ���� �� ���1  ",
      " ���� �� ���2  ",
      "  ���� �� ��x  "
    },
    {
      "      CBFP      ",
      "EStart from ��1 ",
      "Etart from ����1",
      "EStart from ��2 ",
      "Etart from ����2",
      "EStart from ��3 ",
      "Etart from ����3",
      "EStart from ��4 ",
      "Etart from ����4",
      "EStart from OCP1",
      "EStart from OCP2",
      "EStart from OCP3",
      "EStart from OCP4",
      "  ���� �� ���   ",
//!      " Start from 3I0 ",
//!      " Start from 3U0 ",
//!      "  ���� �� ���   ",
//!      " ���� �� ����1  ",
//!      " ���� �� ����2  ",
//!      " ���� �� ����3  ",
//!      " Start from NPSP",
      "Start from Umin1",
      "Start from Umin2",
      "Start from Umax1",
      "Start from Umax2",
      "  ���� �� ���1  ",
      "  ���� �� ���2  ",
      "   MFPx Start   "
    },
    {
      "      ����      ",
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
      "  ���� �� ���   ",
//!      "  ���� �� 3I0   ",
//!      "  ���� �� 3U0   ",
//!      "  ���� �� ���   ",
//!      " ���� �� ����1  ",
//!      " ���� �� ����2  ",
//!      " ���� �� ����3  ",
//!      "���� �� ���(���)",
      " ���� �� �����1 ",
      " ���� �� �����2 ",
      " ���� �� ������1",
      " ���� �� ������2",
      "  ���� �� ���1  ",
      "  ���� �� ���2  ",
      "  ���� �� ���   "
    }
  };
  static const uint32_t index_number_UP[MAX_NAMBER_LANGUAGE] = {12, 13, 6, 12};//.index letter x 
  
  unsigned char name_string_tmp[MAX_ROW_FOR_CONTROL_UROV][MAX_COL_LCD];

  int index_language = index_language_in_array(current_settings.language);
  for(int index_1 = 0; index_1 < MAX_ROW_FOR_CONTROL_UROV; index_1++)
  {
    unsigned int index_row = (index_1 < (MAX_ROW_FOR_CONTROL_UROV - NUMBER_UP)) ? index_1 : (MAX_ROW_FOR_CONTROL_UROV - NUMBER_UP);
    for(int index_2 = 0; index_2 < MAX_COL_LCD; index_2++)
    {
      if (
          (index_1 >= (MAX_ROW_FOR_CONTROL_UROV - NUMBER_UP)) &&
          (index_2 == index_number_UP[index_language]) 
         )
      {
        name_string_tmp[index_1][index_2] = 0x30 + (index_1 - (MAX_ROW_FOR_CONTROL_UROV - NUMBER_UP) + 1);
      }
      else name_string_tmp[index_1][index_2] = name_string[index_language][index_row][index_2];
    }
  }
  
  uint64_t temp_data;
  if(current_ekran.edition == 0) temp_data = current_settings.control_urov;
  else temp_data = edition_settings.control_urov;
        
  /******************************************/
  //��������� ����, �� �� ����� ����������
  /******************************************/
  int additional_current_dz = 0, additional_current_mtz = 0, additional_current_zdz = 0;
  int additional_current_zz = 0, additional_current_tznp = 0, additional_current_zop = 0;
  int additional_current_Umin = 0, additional_current_Umax = 0, additional_current_achr = 0;
  int additional_current_up = 0;
  int position_temp = current_ekran.index_position;
  int index_of_ekran;

//!  int additional_current = additional_current_dz   + additional_current_mtz   + additional_current_zdz  + 
//!                           additional_current_zz   + additional_current_tznp  + additional_current_zop  + 
//!                           additional_current_Umin + additional_current_Umax  + additional_current_achr + 
//!                           additional_current_up;
  int additional_current = additional_current_dz      + additional_current_zdz  + 
                           additional_current_zz   +
                           additional_current_Umin + additional_current_Umax  + additional_current_achr + 
                           additional_current_up;
  for (int current_index = 0; current_index < MAX_ROW_FOR_CONTROL_UROV; current_index++ )
  {

    if (
        (  
         (
          (current_index >= INDEX_ML_CTRUROV_STARTED_FROM_DZ1) &&
          (current_index <= INDEX_ML_CTRUROV_STARTED_FROM_AMTDZ4)
         )   
         &&
         ((current_settings.configuration & (1<<DZ_BIT_CONFIGURATION)) == 0)//dzo
        )  
        ||
        (
         (
          (current_index == INDEX_ML_CTRUROV_STARTED_FROM_MTZ1) ||
          (current_index == INDEX_ML_CTRUROV_STARTED_FROM_MTZ2) ||
          (current_index == INDEX_ML_CTRUROV_STARTED_FROM_MTZ3) ||
          (current_index == INDEX_ML_CTRUROV_STARTED_FROM_MTZ4)
         )   
         &&
         //!((current_settings.configuration & (1<<MTZ1_BIT_CONFIGURATION)) == 0)
         ((current_settings.configuration & (1<<MCZO_BIT_CONFIGURATION)) == 0)
        )  
        ||
        (
         (
          (current_index == INDEX_ML_CTRUROV_STARTED_FROM_ZDZ)
         )   
         &&
         ((current_settings.configuration & (1<<ZDZ_BIT_CONFIGURATION)) == 0)
        )
        ||
        (
         (
          (current_index == INDEX_ML_CTRUROV_STARTED_FROM_UMIN1) ||
          (current_index == INDEX_ML_CTRUROV_STARTED_FROM_UMIN2)
         )   
         &&
         ((current_settings.configuration & (1<<UMIN_BIT_CONFIGURATION)) == 0)
        )  
        ||
        (
         (
          (current_index == INDEX_ML_CTRUROV_STARTED_FROM_UMAX1) ||
          (current_index == INDEX_ML_CTRUROV_STARTED_FROM_UMAX2)
         )   
         &&
         ((current_settings.configuration & (1<<UMAX_BIT_CONFIGURATION)) == 0)
        )  
        ||
        (
         (
          (current_index == INDEX_ML_CTRUROV_STARTED_FROM_ACHR1) ||
          (current_index == INDEX_ML_CTRUROV_STARTED_FROM_ACHR2)
         )   
         &&
         ((current_settings.configuration & (1<<ACHR_CHAPV_BIT_CONFIGURATION)) == 0)
        )
        ||
        (
         (
          (current_index >= INDEX_ML_CTRUROV_STARTED_FROM_UP1) &&
          (current_index <= INDEX_ML_CTRUROV_STARTED_FROM_UP1 + NUMBER_UP - 1)
         )   
         &&
         ((current_settings.configuration & (1<<UP_BIT_CONFIGURATION)) == 0)
        )
       )   
    {
      int i = current_index - additional_current;
      uint64_t maska_1, maska_2;
      maska_1 = (1 << i) - 1;
      maska_2 = (uint64_t)(~maska_1);
    
      if ((i+1) <= position_temp) position_temp--;
      do
      {
        for(unsigned int j = 0; j < MAX_COL_LCD; j++)
        {
          if ((i+1) < (MAX_ROW_FOR_CONTROL_UROV - additional_current)) name_string_tmp[i][j] = name_string_tmp[i + 1][j];
          else name_string_tmp[i][j] = ' ';
        }
        i++;
      }
      while (i < (MAX_ROW_FOR_CONTROL_UROV -  additional_current));
    
      uint64_t temp_data_1 = (temp_data >> 1) & maska_2;
      temp_data = (temp_data & maska_1) | temp_data_1;

      if (
          (current_index >= INDEX_ML_CTRUROV_STARTED_FROM_DZ1) &&
          (current_index <= INDEX_ML_CTRUROV_STARTED_FROM_AMTDZ4)
         )   
        additional_current_dz++;

      if (
          (current_index >= INDEX_ML_CTRUROV_STARTED_FROM_MTZ1) &&
          (current_index <= INDEX_ML_CTRUROV_STARTED_FROM_MTZ4)
         )   
        //!additional_current_mtz++;
        additional_current_zz++;

      if (
          (current_index == INDEX_ML_CTRUROV_STARTED_FROM_ZDZ)
         )   
        additional_current_zdz++;

      //!if (
      //!    (current_index == INDEX_ML_CTRUROV_STARTED_FROM_3I0) ||
      //!    (current_index == INDEX_ML_CTRUROV_STARTED_FROM_3U0) ||
      //!    (current_index == INDEX_ML_CTRUROV_STARTED_FROM_NZZ)
      //!   )   
      //!  additional_current_zz++;
	  //!
      //!if (
      //!    (current_index == INDEX_ML_CTRUROV_STARTED_FROM_TZNP1) ||
      //!    (current_index == INDEX_ML_CTRUROV_STARTED_FROM_TZNP2) ||
      //!    (current_index == INDEX_ML_CTRUROV_STARTED_FROM_TZNP3)
      //!   )   
      //!  additional_current_tznp++;
	  //!
      //!if (
      //!    (current_index == INDEX_ML_CTRUROV_STARTED_FROM_ZOP1)
      //!   )   
      //!  additional_current_zop++;

      if (
          (current_index == INDEX_ML_CTRUROV_STARTED_FROM_UMIN1) ||
          (current_index == INDEX_ML_CTRUROV_STARTED_FROM_UMIN2)
         )   
        additional_current_Umin++;

      if (
          (current_index == INDEX_ML_CTRUROV_STARTED_FROM_UMAX1) ||
          (current_index == INDEX_ML_CTRUROV_STARTED_FROM_UMAX2)
         )   
        additional_current_Umax++;

      if (
          (current_index == INDEX_ML_CTRUROV_STARTED_FROM_ACHR1) ||
          (current_index == INDEX_ML_CTRUROV_STARTED_FROM_ACHR2)
         )   
        additional_current_achr++;

      if (
          (current_index >= INDEX_ML_CTRUROV_STARTED_FROM_UP1) &&
          (current_index <= INDEX_ML_CTRUROV_STARTED_FROM_UP1 + NUMBER_UP - 1)
         )   
        additional_current_up++;
      
      additional_current = additional_current_dz   + additional_current_mtz   + additional_current_zdz  + 
                           additional_current_zz   + additional_current_tznp  + additional_current_zop  + 
                           additional_current_Umin + additional_current_Umax  + additional_current_achr +
                           additional_current_up;
    }
  }
  /******************************************/
  
  //�������� �� ��� �������� position_temp ������� ��� ����, �� �� ���� ������� �� ������������� ��� ����� (����� + ��������)
  index_of_ekran = ((position_temp<<1) >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;

  
  for (unsigned int i=0; i< MAX_ROW_LCD; i++)
  {
    int index_of_ekran_tmp = index_of_ekran >> 1;
    if (index_of_ekran_tmp < (MAX_ROW_FOR_CONTROL_UROV - additional_current))
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
