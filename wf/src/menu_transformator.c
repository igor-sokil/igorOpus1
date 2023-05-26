#include "header.h"

/*****************************************************/
//������������ ������ ������� � �������� ���� � ������� �����
/*****************************************************/
void calc_int_symbol_and_put_into_working_ekran(unsigned char* point_in_working_ekran, unsigned int* point_value, unsigned int* point_vaga, unsigned int* point_first_symbol, unsigned int view)
{
  unsigned int temp_data;
  temp_data = (*point_value) / (*point_vaga); //�������� �����, ��� ����� ����������� � ������ � �������� � ���� ������� ������
  *point_value %= *(point_vaga); //���������� ����� ��� �������, ���� �� ����� ������ �������� �� �����
  *point_vaga /=10; //�������� ������� ���������� � 10 ����
  if  (view == false) *point_in_working_ekran = temp_data + 0x30;
  else
  {
    //� �������, ���� �� �� � ����� �����������, �� ��� ����� ���������� �������� ������ ���������
    if ((temp_data !=0) || ((*point_first_symbol) != 0))
    {
      *point_in_working_ekran = temp_data + 0x30;
      if ((*point_first_symbol) == 0) *point_first_symbol = 1;
    }
    else
    {
      //���� �������� ����� � ���� �������, ���� �� � ������ ������� ����� (������ ���� ����� ���� 1)
      if ((*point_vaga) >= 1 ) *point_in_working_ekran = ' ';
      else
      {
        *point_in_working_ekran = temp_data + 0x30;
        if ((*point_first_symbol) == 0) *point_first_symbol = 1;
      }
    }
  }
}
/*****************************************************/

/*****************************************************/
//������� ����� ����������� ��������� ������������ �� � ������� � ���������
/*****************************************************/
void make_ekran_chose_setpoint_control_transformator(void)
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_CHOSE_SETTINGS_PROTECTION_WITH_SETPOINTS_CONTROL][MAX_COL_LCD] = 
  {
    {
      " �������        ",
      " ����������     "
    },
    {
      " �������        ",
      " ���������     "
    },
    {
      " Pickups        ",
      " Control        "
    },
    {
      " �������        ",
      " �������        "
    }
  };
  uint8_t name_string_tmp[MAX_ROW_FOR_CHOSE_SETTINGS_PROTECTION_WITH_SETPOINTS_CONTROL][MAX_COL_LCD];
  
  int index_language = index_language_in_array(current_settings.language);
  for(int index_1 = 0; index_1 < MAX_ROW_FOR_CHOSE_SETTINGS_PROTECTION_WITH_SETPOINTS_CONTROL; index_1++)
  {
    for(int index_2 = 0; index_2 < MAX_COL_LCD; index_2++)
      name_string_tmp[index_1][index_2] = name_string[index_language][index_1][index_2];
  }
  
  int position_temp = current_ekran.index_position;
  int index_of_ekran = (position_temp >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;

  //�������  ����� � ������� �����
  for (unsigned int i=0; i< MAX_ROW_LCD; i++)
  {
    if (index_of_ekran < MAX_ROW_FOR_CHOSE_SETTINGS_PROTECTION_WITH_SETPOINTS_CONTROL)
      for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string_tmp[index_of_ekran][j];
    else
      for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = ' ';

    index_of_ekran++;
  }

  //������ �� ���������� ������������ �� ������ �������
  current_ekran.position_cursor_x = 0;
  //³���������� ������ �� ��������
  current_ekran.position_cursor_y = position_temp & (MAX_ROW_LCD - 1);
  //������ �������
  current_ekran.cursor_on = 1;
  //������ �� ����
  current_ekran.cursor_blinking_on = 0;
  //�������� ������� ���� �����
  current_ekran.current_action = ACTION_WITH_CARRENT_EKRANE_FULL_UPDATE;
}
/*****************************************************/

/*****************************************************/
//������� ����� ����������� ����������� �������������
/*****************************************************/
void make_ekran_transformator()
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_TRANSFORMATOR_INFO_SETPOINT][MAX_COL_LCD] = 
  {
    {
      "   �-�.��mn     ",
      "   �-�.��bp     ",
      "   �-�.��       "
    },
    {
      "   �-�.��mn     ",
      "   �-�.��bp     ",
      "   �-�.��       "
    },
    {
      "  Cmnl T Ratio  ",
      "  Cbpl T Ratio  ",
      "    VT Ratio    "
    },
    {
      "   �-�.��mn     ",
      "   �-�.��bp     ",
      "   �-�.��       "
    }
  };
  unsigned char name_string_tmp[MAX_ROW_FOR_TRANSFORMATOR_INFO_SETPOINT][MAX_COL_LCD];

  int index_language = index_language_in_array(current_settings.language);
  for(int index_1 = 0; index_1 < MAX_ROW_FOR_TRANSFORMATOR_INFO_SETPOINT; index_1++)
  {
    for(int index_2 = 0; index_2 < MAX_COL_LCD; index_2++)
      name_string_tmp[index_1][index_2] = name_string[index_language][index_1][index_2];
  }

  int position_temp = current_ekran.index_position;
  int index_of_ekran;

  unsigned int vaga, value, first_symbol;
  
  //�������� �� ��� �������� position_temp ������� ��� ����, �� ����� ������� �� ������������� ��� ����� (����� + ��������)
  index_of_ekran = ((position_temp<<1) >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;

  
  for (unsigned int i=0; i< MAX_ROW_LCD; i++)
  {
    int index_of_ekran_tmp = index_of_ekran >> 1;
    unsigned int view = ((current_ekran.edition == 0) || (position_temp != index_of_ekran_tmp));
    if (index_of_ekran_tmp < MAX_ROW_FOR_TRANSFORMATOR_INFO_SETPOINT)
    {
      if ((i & 0x1) == 0)
      {
        //� ��������� ����� ����� �������� ���������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string_tmp[index_of_ekran_tmp][j];
        if (index_of_ekran_tmp == INDEX_ML_T_MN)
        {
          vaga = 1000; //������������ ������� ���������� ��� ����������� ������������� T0
          if (view == true) value = current_settings.Tmn; //� ����� value ������� �������� ����������� ������������� T0
          else value = edition_settings.Tmn;
          first_symbol = 0; //�������, �� �� ����� �������� ������ �� ���������
        }
        else if (index_of_ekran_tmp == INDEX_ML_T_BP)
        {
          vaga = 1000; //������������ ������� ���������� ��� ����������� ������������� TT
          if (view == true) value = current_settings.Tbp; //� ����� value ������� �������� ����������� ������������� TT
          else value = edition_settings.Tbp;
          first_symbol = 0; //�������, �� �� ����� �������� ������ �� ���������
        }
        else if (index_of_ekran_tmp == INDEX_ML_TN)
        {
          vaga = 1000; //������������ ������� ���������� ��� ����������� ������������� T�
          if (view == true) value = current_settings.TVoltage; //� ����� value ������� �������� ����������� ������������� T�
          else value = edition_settings.TVoltage;
          first_symbol = 0; //�������, �� �� ����� �������� ������ �� ���������
        }
      }
      else 
      {
        //� ������� ����� ����� �������� �������� �������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++)
        {
          if (index_of_ekran_tmp == INDEX_ML_T_MN)
          {
            if ((j < COL_T_MN_BEGIN) ||  (j > COL_T_MN_END ))working_ekran[i][j] = ' ';
            else
              calc_int_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, view);
          }
          else if (index_of_ekran_tmp == INDEX_ML_T_BP)
          {
            if ((j < COL_T_BP_BEGIN) ||  (j > COL_T_BP_END ))working_ekran[i][j] = ' ';
            else
              calc_int_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, view);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TN)
          {
            if ((j < COL_TN_BEGIN) ||  (j > COL_TN_END ))working_ekran[i][j] = ' ';
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
    if (current_ekran.index_position == INDEX_ML_T_MN)
    {
      current_ekran.position_cursor_x = COL_T_MN_BEGIN;
      last_position_cursor_x = COL_T_MN_END;
    }
    else if (current_ekran.index_position == INDEX_ML_T_BP)
    {
      current_ekran.position_cursor_x = COL_T_BP_BEGIN ;
      last_position_cursor_x = COL_T_BP_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TN)
    {
      current_ekran.position_cursor_x = COL_TN_BEGIN;
      last_position_cursor_x = COL_TN_END;
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
//������� ����� ����������� ����������� ��� ��������������
/*****************************************************/
void make_ekran_transformator_control(void)
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_TRANSFORMATOR_INFO_CONTROL][MAX_COL_LCD] = 
  {
    {
      " ���.U ��� �����",
      "   ����������   "
    },
    {
      " ���.U ��� ���. ",
      "   �'�������    "
    },
    {
      " ���.U ��� �����",
      "   Connection   "
    },
    {
      " ���.U ��� �����",
      "   ����������   "
    }
  };
  int index_language = index_language_in_array(current_settings.language);
  
  unsigned int position_temp = current_ekran.index_position;
  unsigned int index_of_ekran;
  
  //�������� �� ��� �������� position_temp ������� ��� ����, �� �� ���� ������� �� ������������� ��� ����� (����� + ��������)
  index_of_ekran = ((position_temp<<1) >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;
  
  for (unsigned int i=0; i< MAX_ROW_LCD; i++)
  {
    if (index_of_ekran < (MAX_ROW_FOR_TRANSFORMATOR_INFO_CONTROL<<1))//�������� �� ��� ��������� MAX_ROW_FOR_TRANSFORMATOR_INFO_CONTROL ������� ��� ����, �� �� ���� ������� �� ������������� ��� ����� (����� + ��������)
    {
      if ((i & 0x1) == 0)
      {
        //� ��������� ����� ����� �������� ���������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_language][index_of_ekran>>1][j];
      }
      else
      {
        //� ������� ����� ����� �������� ����
        static const unsigned char information[MAX_ROW_FOR_TRANSFORMATOR_INFO_CONTROL][MAX_NAMBER_LANGUAGE][2][MAX_COL_LCD] = 
        {
          {
            {"     ������     ", "    ��������    "},
            {"     ����      ", "    ˳���     "},
            {"     ������     ", "    ��������    "},
            {"     ������     ", "    ��������    "}
          },
          {
            {"      3I0       ", "     3I0-1      "},
            {"      3I0       ", "     3I0-1      "},
            {"      3I0       ", "     3I0-1      "},
            {"      3I0       ", "     3I0-1      "}
          }
        };
        static const unsigned int cursor_x[MAX_ROW_FOR_TRANSFORMATOR_INFO_CONTROL][MAX_NAMBER_LANGUAGE][2] = 
        {
          {
            {3, 4},
            {3, 4},
            {3, 4},
            {3, 4}
          },
          {
            {5, 4},
            {5, 4},
            {5, 4},
            {5, 4}
          }
        };
      
        
        unsigned int index_ctr = (index_of_ekran>>1);

        unsigned int temp_data;
        if(current_ekran.edition == 0) temp_data = current_settings.control_transformator;
        else temp_data = edition_settings.control_transformator;
          
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = information[index_ctr][index_language][(temp_data >> index_ctr) & 0x1][j];
        current_ekran.position_cursor_x = cursor_x[index_ctr][index_language][(temp_data >> index_ctr) & 0x1];
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
//������� ����� ����������� ��������� ������������ �� � ������� 
/*****************************************************/
void make_ekran_chose_setpoint_transformator(void)
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_CHOSE_SETTINGS_PROTECTION_WITH_SETPOINTS_CONTROL][MAX_COL_LCD] = 
  {
    {
      " �������        ",
      
    },
    {
      " �������        ",
      
    },
    {
      " Pickups        ",
      
    },
    {
      " �������        ",
     
    }
  };
  uint8_t name_string_tmp[MAX_ROW_FOR_CHOSE_SETTINGS_TR_WITH_SETPOINTS_CONTROL][MAX_COL_LCD];
  
  int index_language = index_language_in_array(current_settings.language);
  for(int index_1 = 0; index_1 < MAX_ROW_FOR_CHOSE_SETTINGS_TR_WITH_SETPOINTS_CONTROL; index_1++)
  {
    for(int index_2 = 0; index_2 < MAX_COL_LCD; index_2++)
      name_string_tmp[index_1][index_2] = name_string[index_language][index_1][index_2];
  }
  
  int position_temp = current_ekran.index_position;
  int index_of_ekran = (position_temp >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;

  //�������  ����� � ������� �����
  for (unsigned int i=0; i< MAX_ROW_LCD; i++)
  {
    if (index_of_ekran < MAX_ROW_FOR_CHOSE_SETTINGS_TR_WITH_SETPOINTS_CONTROL)
      for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string_tmp[index_of_ekran][j];
    else
      for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = ' ';

    index_of_ekran++;
  }

  //������ �� ���������� ������������ �� ������ �������
  current_ekran.position_cursor_x = 0;
  //³���������� ������ �� ��������
  current_ekran.position_cursor_y = position_temp & (MAX_ROW_LCD - 1);
  //������ �������
  current_ekran.cursor_on = 1;
  //������ �� ����
  current_ekran.cursor_blinking_on = 0;
  //�������� ������� ���� �����
  current_ekran.current_action = ACTION_WITH_CARRENT_EKRANE_FULL_UPDATE;
}
/*****************************************************/


/*****************************************************/
//
/*****************************************************/
/*****************************************************/
