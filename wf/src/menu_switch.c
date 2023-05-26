#include "header.h"

/*****************************************************/
//������� ����� ����������� ������ ���������� �����./�����.
/*****************************************************/
void make_ekran_choose_CBOn_CBOff(void)
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_RANG_SWITCH][MAX_COL_LCD] = 
  {
    {
      " ��             ",
      " ��             "
    },
    {
      " �����.         ",
      " �����.        "
    },
    {
      " Off CB         ",
      " On CB          "
    },
    {
      " ��             ",
      " ��             "
    }
  };

  int index_language = index_language_in_array(current_settings.language);
  
  unsigned int position_temp = current_ekran.index_position;
  unsigned int index_of_ekran;
  
  index_of_ekran = (position_temp >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;
  
  //�������  ����� � ������� �����
  for (unsigned int i=0; i< MAX_ROW_LCD; i++)
  {
    //������� ����� ����� ���������, �� �� ����� ���������� � ������� ������������
    if (index_of_ekran < MAX_ROW_FOR_LIST_OF_REGISTRATORS)
      for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_language][index_of_ekran][j];
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
//������� ����� ����������� ������ ���������� �����./�����.
/*****************************************************/
void make_ekran_choose_CBOn_CBOff_(uint32_t on_off)
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_RANG_SWITCH][MAX_COL_LCD] = 
  {
    {
      " ��(x)          ",
      " ��(x)          "
    },
    {
      " �����. (x)     ",
      " �����.(x)     "
    },
    {
      " Off CB(x)      ",
      " On CB (x)      "
    },
    {
      " ��(x)          ",
      " ��(x)          "
    }
  };
  static const uint8_t ind_index[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_RANG_SWITCH] = 
  {
    {4, 4},
    {9, 9},
    {8, 8},
    {4, 4}
  };
  
  int index_language = index_language_in_array(current_settings.language);
  
  unsigned int position_temp = current_ekran.index_position;
  unsigned int index_of_ekran;
  
  index_of_ekran = (position_temp >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;
  
  //�������  ����� � ������� �����
  for (unsigned int i=0; i< MAX_ROW_LCD; i++)
  {
    //������� ����� ����� ���������, �� �� ����� ���������� � ������� ������������
    if (index_of_ekran < MAX_ROW_FOR_LIST_OF_REGISTRATORS)
    {	
      for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_language][index_of_ekran][j];
       working_ekran[i][ind_index[index_language][index_of_ekran]] = OFF_ON_value[index_language][on_off];
    }else
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
//������� ����� ����������� ������� ��������
/*****************************************************/
void make_ekran_setpoint_switch()
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_SETPOINT_SWITCH][MAX_COL_LCD] = 
  {
    {
      "     I ���.     ",
      " �.�.��.(I ���.)",
      "    I��.���.    ",
      "�.�.��.(I��.���)",
      "���.����.�������",
      "��������� ������",
      "���.����.�.����."
    },
    {
      "     I ���.     ",
      " �.�.��.(I ���.)",
      "    I�.���.     ",
      "�.�.��.(I�.���.)",
      "���.����.�������",
      "��������� ������",
      "���.����.�.����."
    },
    {
      "      CB Ir     ",
      "   CB Res Ir    ",
      "   CB Open Ir   ",
      " CB Res Open Ir ",
      " CB Res Balance ",
      "  CB Crit Res   ",
      "CB Comut balance"
    },
    {
      "     I ���.     ",
      " �.�.��.(I ���.)",
      "    I��.���.    ",
      "�.�.��.(I��.���)",
      "���.����.�������",
      "��������� ������",
      "���.����.�.����."
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
    if (index_of_ekran_tmp < MAX_ROW_FOR_SETPOINT_SWITCH)
    {
      if ((i & 0x1) == 0)
      {
        //� ��������� ����� ����� �������� ���������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_language][index_of_ekran_tmp][j];
        if (index_of_ekran_tmp == INDEX_ML_STPInom)
        {
          vaga = 10000; //������������ ������� ���������� ��� �������� �������� ������� ��� ������� ����������� ������
          if (view == true) value = current_settings.setpoint_Inom; //� ����� value ������� �������� ������� ����������� ������
          else value = edition_settings.setpoint_Inom;
          first_symbol = 0; //�������, �� �� ����� �������� ������ �� ���������
        }
        else if (index_of_ekran_tmp == INDEX_ML_STPRKS_Inom)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� ������� ������� ������������� ������� ��� ����������� �����
          if (view == true) value = current_settings.setpoint_r_kom_st_Inom; //� ����� value ������� �������� ������� ������� ������������� ������� ��� ����������� �����
          else value = edition_settings.setpoint_r_kom_st_Inom;
          first_symbol = 0; //�������, �� �� ����� �������� ������ �� ���������
        }
        else if (index_of_ekran_tmp == INDEX_ML_STPMInom_vymk)
        {
          vaga = 10000; //������������ ������� ���������� ��� �������� �������� ������� ��� ������� ����������� ������ ���������
          if (view == true) value = current_settings.setpoint_Inom_vymk; //� ����� value ������� �������� ������� ����������� ������ ���������
          else value = edition_settings.setpoint_Inom_vymk;
          first_symbol = 0; //�������, �� �� ����� �������� ������ �� ���������
        }
        else if (index_of_ekran_tmp == INDEX_ML_STPRKS_Inom_vymk)
        {
          vaga = 100; //������������ ������� ���������� ��� �������� �������� ������� ������� ������������� ������� ��� ����������� ����� ���������
          if (view == true) value = current_settings.setpoint_r_kom_st_Inom_vymk; //� ����� value ������� �������� ������� ������� ������������� ������� ��� ����������� ����� ���������
          else value = edition_settings.setpoint_r_kom_st_Inom_vymk;
          first_symbol = 0; //�������, �� �� ����� �������� ������ �� ���������
        }
        else if (index_of_ekran_tmp == INDEX_ML_STPPOCHATKOVYJ_RESURS)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� ������� ����������� ������� ��������
          if (view == true) value = current_settings.setpoint_pochatkovyj_resurs; //� ����� value ������� �������� ������� ����������� ������� ��������
          else value = edition_settings.setpoint_pochatkovyj_resurs;
          first_symbol = 0; //�������, �� �� ����� �������� ������ �� ���������
        }
        else if (index_of_ekran_tmp == INDEX_ML_STPKRYTYCHNYJ_RESURS)
        {
          vaga = 10000; //������������ ������� ���������� ��� �������� �������� ������� ���������� ������� ��������
          if (view == true) value = current_settings.setpoint_krytychnyj_resurs; //� ����� value ������� �������� ������� ���������� ������� ��������
          else value = edition_settings.setpoint_krytychnyj_resurs;
          first_symbol = 0; //�������, �� �� ����� �������� ������ �� ���������
        }
        else if (index_of_ekran_tmp == INDEX_ML_STPPOCHATKOVA_K_VYMK)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� ������� ������� ������������� ������� ��� ����������� �����
          if (view == true) value = current_settings.setpoint_pochatkova_k_vymk; //� ����� value ������� �������� ������� ������� ������������� ������� ��� ����������� �����
          else value = edition_settings.setpoint_pochatkova_k_vymk;
          first_symbol = 0; //�������, �� �� ����� �������� ������ �� ���������
        }
      }
      else
      {
        //� ������� ����� ����� �������� �������� �������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++)
        {
          if (index_of_ekran_tmp == INDEX_ML_STPInom)
          {
            if (
                ((j < COL_SETPOINT_Inom_BEGIN) ||  (j > COL_SETPOINT_Inom_END )) &&
                (j != (COL_SETPOINT_Inom_END + 2))
               )working_ekran[i][j] = ' ';
            else if (j == (COL_SETPOINT_Inom_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_A]; 
            else
              calc_int_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, view);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STPRKS_Inom)
          {
            if ((j < COL_SETPOINT_RKS_Inom_BEGIN) ||  (j > COL_SETPOINT_RKS_Inom_END ))
              working_ekran[i][j] = ' ';
            else
              calc_int_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, view);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STPMInom_vymk)
          {
            if (
                ((j < COL_SETPOINT_Inom_vymk_BEGIN) ||  (j > COL_SETPOINT_Inom_vymk_END )) &&
                (
                 !((j >= (COL_SETPOINT_Inom_vymk_END + 2)) && (j <= (COL_SETPOINT_Inom_vymk_END + 3)))
                )    
               )working_ekran[i][j] = ' ';
            else if (j == COL_SETPOINT_Inom_vymk_COMMA )working_ekran[i][j] = ',';
            else if ((j >= (COL_SETPOINT_Inom_vymk_END + 2)) && (j <= (COL_SETPOINT_Inom_vymk_END + 3))) 
            {
              static const unsigned char kA[MAX_NAMBER_LANGUAGE][2] = {"��", "��", "kA", "��"};
              
              working_ekran[i][j] = kA[index_language][j - (COL_SETPOINT_Inom_vymk_END + 2)];
            }
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_SETPOINT_Inom_vymk_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STPRKS_Inom_vymk)
          {
            if ((j < COL_SETPOINT_RKS_Inom_vymk_BEGIN) ||  (j > COL_SETPOINT_RKS_Inom_vymk_END ))
              working_ekran[i][j] = ' ';
            else
              calc_int_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, view);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STPPOCHATKOVYJ_RESURS)
          {
            if ((j < COL_SETPOINT_POCHATKOVYJ_RESURS_BEGIN) ||  (j > COL_SETPOINT_POCHATKOVYJ_RESURS_END ))
              working_ekran[i][j] = ' ';
            else
              calc_int_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, view);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STPKRYTYCHNYJ_RESURS)
          {
            if ((j < COL_SETPOINT_KRYTYCHNYJ_RESURS_BEGIN) ||  (j > COL_SETPOINT_KRYTYCHNYJ_RESURS_END ))
              working_ekran[i][j] = ' ';
            else
              calc_int_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, view);
          }
          else if (index_of_ekran_tmp == INDEX_ML_STPPOCHATKOVA_K_VYMK)
          {
            if ((j < COL_SETPOINT_POCHATKOVA_K_VYMK_BEGIN) ||  (j > COL_SETPOINT_POCHATKOVA_K_VYMK_END ))
              working_ekran[i][j] = ' ';
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
    if (current_ekran.index_position == INDEX_ML_STPInom)
    {
      current_ekran.position_cursor_x = COL_SETPOINT_Inom_BEGIN;
      last_position_cursor_x = COL_SETPOINT_Inom_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STPRKS_Inom) 
    {
      current_ekran.position_cursor_x = COL_SETPOINT_RKS_Inom_BEGIN;
      last_position_cursor_x = COL_SETPOINT_RKS_Inom_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STPMInom_vymk) 
    {
      current_ekran.position_cursor_x = COL_SETPOINT_Inom_vymk_BEGIN;
      last_position_cursor_x = COL_SETPOINT_Inom_vymk_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STPRKS_Inom_vymk) 
    {
      current_ekran.position_cursor_x = COL_SETPOINT_RKS_Inom_vymk_BEGIN;
      last_position_cursor_x = COL_SETPOINT_RKS_Inom_vymk_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STPPOCHATKOVYJ_RESURS) 
    {
      current_ekran.position_cursor_x = COL_SETPOINT_POCHATKOVYJ_RESURS_BEGIN;
      last_position_cursor_x = COL_SETPOINT_POCHATKOVYJ_RESURS_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STPKRYTYCHNYJ_RESURS) 
    {
      current_ekran.position_cursor_x = COL_SETPOINT_KRYTYCHNYJ_RESURS_BEGIN;
      last_position_cursor_x = COL_SETPOINT_KRYTYCHNYJ_RESURS_END;
    }
    else if (current_ekran.index_position == INDEX_ML_STPPOCHATKOVA_K_VYMK) 
    {
      current_ekran.position_cursor_x = COL_SETPOINT_POCHATKOVA_K_VYMK_BEGIN;
      last_position_cursor_x = COL_SETPOINT_POCHATKOVA_K_VYMK_END;
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
//������� ����� ����������� �������� �����������
/*****************************************************/
void make_ekran_timeout_switch()
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_TIMEOUT_SWITCH][MAX_COL_LCD] = 
  {
    {
      "     T ���.     ",
      "    T ����.     ",
      " T ���.���.���. ",
      "  T ������� ��  "
    },
    {
      "    T ����.    ",
      "    T ����.     ",
      "T ���.���.����.",
      "  T ������� ��  "
    },
    {
      "      On T      ",
      "     Off T      ",
      "ON Blc.Lengthen.",
      "CB Actuator Time"
    },
    {
      "     T ���.     ",
      "    T ����.     ",
      " T ���.���.���. ",
      "  T ������� ��  "
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
    if (index_of_ekran_tmp < MAX_ROW_FOR_TIMEOUT_SWITCH)
    {
      if ((i & 0x1) == 0)
      {
        //� ��������� ����� ����� �������� ���������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_language][index_of_ekran_tmp][j];
        if (index_of_ekran_tmp == INDEX_ML_TMOON)
        {
          vaga = 1000; //������������ ������� ���������� ��� �������� �������� ������� ��� �������� T ���.
          if (view == true) value = current_settings.timeout_swch_on; //� ����� value ������� �������� �������� T ���.
          else value = edition_settings.timeout_swch_on;
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMOOFF)
        {
          vaga = 1000; //������������ ������� ���������� ��� �������� �������� ������� ��� �������� T ����.
          if (view == true) value = current_settings.timeout_swch_off; //� ����� value ������� �������� �������� T ����.
          else value = edition_settings.timeout_swch_off;
        }
        else  if (index_of_ekran_tmp == INDEX_ML_TMOUDL_BLK_ON)
        {
          vaga = 10000; //������������ ������� ���������� ��� �������� �������� ������� ��� �������� T "��������� ������� ���������� ���������"
          if (view == true) value = current_settings.timeout_swch_udl_blk_on; //� ����� value ������� �������� ������� T "��������� ������� ���������� ���������"
          else value = edition_settings.timeout_swch_udl_blk_on;
        }
        else  if (index_of_ekran_tmp == INDEX_ML_TMOPRYVODA_VV)
        {
          vaga = 1000; //������������ ������� ���������� ��� �������� �������� ������� ��� �������� T "������� ��"
          if (view == true) value = current_settings.timeout_pryvoda_VV; //� ����� value ������� �������� ������� T "������� ��"
          else value = edition_settings.timeout_pryvoda_VV;
        }
        first_symbol = 0; //�������, �� �� ����� �������� ������ �� ���������
      }
      else
      {
        //� ������� ����� ����� �������� �������� �������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++)
        {
          if (index_of_ekran_tmp == INDEX_ML_TMOON)
          {
            if (
                ((j < COL_TMO_SWCH_ON_BEGIN) ||  (j > COL_TMO_SWCH_ON_END )) &&
                (j != (COL_TMO_SWCH_ON_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_SWCH_ON_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_SWCH_ON_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_SWCH_ON_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMOOFF)
          {
            if (
                ((j < COL_TMO_SWCH_OFF_BEGIN) ||  (j > COL_TMO_SWCH_OFF_END )) &&
                (j != (COL_TMO_SWCH_OFF_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_SWCH_OFF_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_SWCH_OFF_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_SWCH_OFF_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMOUDL_BLK_ON)
          {
            if (
                ((j < COL_TMO_SWCH_UDL_BLK_ON_BEGIN) ||  (j > COL_TMO_SWCH_UDL_BLK_ON_END )) &&
                (j != (COL_TMO_SWCH_UDL_BLK_ON_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_SWCH_UDL_BLK_ON_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_SWCH_UDL_BLK_ON_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_SWCH_UDL_BLK_ON_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMOPRYVODA_VV)
          {
            if (
                ((j < COL_TMO_PRYVODA_VV_BEGIN) ||  (j > COL_TMO_PRYVODA_VV_END )) &&
                (j != (COL_TMO_PRYVODA_VV_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_PRYVODA_VV_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_PRYVODA_VV_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j,COL_TMO_PRYVODA_VV_COMMA, view, 0);
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
    if (current_ekran.index_position == INDEX_ML_TMOON)
    {
      current_ekran.position_cursor_x = COL_TMO_SWCH_ON_BEGIN;
      last_position_cursor_x = COL_TMO_SWCH_ON_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMOOFF)
    {
      current_ekran.position_cursor_x = COL_TMO_SWCH_OFF_BEGIN;
      last_position_cursor_x = COL_TMO_SWCH_OFF_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMOUDL_BLK_ON)
    {
      current_ekran.position_cursor_x = COL_TMO_SWCH_UDL_BLK_ON_BEGIN;
      last_position_cursor_x = COL_TMO_SWCH_UDL_BLK_ON_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMOPRYVODA_VV)
    {
      current_ekran.position_cursor_x = COL_TMO_PRYVODA_VV_BEGIN;
      last_position_cursor_x = COL_TMO_PRYVODA_VV_END;
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
//������� ����� ����������� �������� �����������
/*****************************************************/
void make_ekran_timeout_switch_(uint32_t on_off)
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_TIMEOUT_SWITCH][MAX_COL_LCD] = 
  {
    {
      "     T ���.  (x)",
      "    T ����.  (x)",
      "T ��.���.���.(x)",
      "T ������� �� (x)"
    },
    {
      "    T ����. (x)",
      "    T ����.  (x)",
      "T ��.��.���.(x)",
      "T ������� �� (x)"
    },
    {
      "      On T  (x)",
      "     Off T  (x)",
      "ON Blc.L.   (x)",
      "CB Act Time (x)"
    },
    {
      "     T ���. (x)",
      "    T ����. (x)",
      "T ��.��.���.(x)",
      "T ������� ��(x)"
    }
  };
  static const uint8_t ind_index[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_TIMEOUT_SWITCH] = 
  {
    {14, 14, 14, 14},
    {14, 14, 14, 14},
    {13, 13, 13, 13},
    {14, 14, 14, 14}
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
    if (index_of_ekran_tmp < MAX_ROW_FOR_TIMEOUT_SWITCH)
    {
      if ((i & 0x1) == 0)
      {
        //� ��������� ����� ����� �������� ���������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_language][index_of_ekran_tmp][j];
        working_ekran[i][ind_index[index_language][index_of_ekran_tmp]] = OFF_ON_value[index_language][on_off];
        
		if (index_of_ekran_tmp == INDEX_ML_TMOON)
        {
          vaga = 1000; //������������ ������� ���������� ��� �������� �������� ������� ��� �������� T ���.
          if (view == true) value = current_settings.timeout_swch_on_[on_off]; //� ����� value ������� �������� �������� T ���.
          else value = edition_settings.timeout_swch_on_[on_off];
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMOOFF)
        {
          vaga = 1000; //������������ ������� ���������� ��� �������� �������� ������� ��� �������� T ����.
          if (view == true) value = current_settings.timeout_swch_off_[on_off]; //� ����� value ������� �������� �������� T ����.
          else value = edition_settings.timeout_swch_off_[on_off];
        }
        else  if (index_of_ekran_tmp == INDEX_ML_TMOUDL_BLK_ON)
        {
          vaga = 10000; //������������ ������� ���������� ��� �������� �������� ������� ��� �������� T "��������� ������� ���������� ���������"
          if (view == true) value = current_settings.timeout_swch_udl_blk_on_[on_off]; //� ����� value ������� �������� ������� T "��������� ������� ���������� ���������"
          else value = edition_settings.timeout_swch_udl_blk_on_[on_off];
        }
        else  if (index_of_ekran_tmp == INDEX_ML_TMOPRYVODA_VV)
        {
          vaga = 1000; //������������ ������� ���������� ��� �������� �������� ������� ��� �������� T "������� ��"
          if (view == true) value = current_settings.timeout_pryvoda_VV_[on_off]; //� ����� value ������� �������� ������� T "������� ��"
          else value = edition_settings.timeout_pryvoda_VV_[on_off];
        }
        first_symbol = 0; //�������, �� �� ����� �������� ������ �� ���������
      }
      else
      {
        //� ������� ����� ����� �������� �������� �������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++)
        {
          if (index_of_ekran_tmp == INDEX_ML_TMOON)
          {
            if (
                ((j < COL_TMO_SWCH_ON_BEGIN) ||  (j > COL_TMO_SWCH_ON_END )) &&
                (j != (COL_TMO_SWCH_ON_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_SWCH_ON_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_SWCH_ON_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_SWCH_ON_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMOOFF)
          {
            if (
                ((j < COL_TMO_SWCH_OFF_BEGIN) ||  (j > COL_TMO_SWCH_OFF_END )) &&
                (j != (COL_TMO_SWCH_OFF_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_SWCH_OFF_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_SWCH_OFF_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_SWCH_OFF_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMOUDL_BLK_ON)
          {
            if (
                ((j < COL_TMO_SWCH_UDL_BLK_ON_BEGIN) ||  (j > COL_TMO_SWCH_UDL_BLK_ON_END )) &&
                (j != (COL_TMO_SWCH_UDL_BLK_ON_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_SWCH_UDL_BLK_ON_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_SWCH_UDL_BLK_ON_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_SWCH_UDL_BLK_ON_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMOPRYVODA_VV)
          {
            if (
                ((j < COL_TMO_PRYVODA_VV_BEGIN) ||  (j > COL_TMO_PRYVODA_VV_END )) &&
                (j != (COL_TMO_PRYVODA_VV_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_PRYVODA_VV_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_PRYVODA_VV_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j,COL_TMO_PRYVODA_VV_COMMA, view, 0);
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
    if (current_ekran.index_position == INDEX_ML_TMOON)
    {
      current_ekran.position_cursor_x = COL_TMO_SWCH_ON_BEGIN;
      last_position_cursor_x = COL_TMO_SWCH_ON_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMOOFF)
    {
      current_ekran.position_cursor_x = COL_TMO_SWCH_OFF_BEGIN;
      last_position_cursor_x = COL_TMO_SWCH_OFF_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMOUDL_BLK_ON)
    {
      current_ekran.position_cursor_x = COL_TMO_SWCH_UDL_BLK_ON_BEGIN;
      last_position_cursor_x = COL_TMO_SWCH_UDL_BLK_ON_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMOPRYVODA_VV)
    {
      current_ekran.position_cursor_x = COL_TMO_PRYVODA_VV_BEGIN;
      last_position_cursor_x = COL_TMO_PRYVODA_VV_END;
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
//������� ����� ����������� �������� ����������� ���������� ��� ��������
/*****************************************************/
void make_ekran_control_switch()
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_CONTROL_SWITCH][MAX_COL_LCD] = 
  {
    {
      "  �������� ��   ",
      "   ������ ��    "
    },
    {
      "  �������� ��   ",
      "   ������ ��    "
    },
    {
      "   CB Control   ",
      "   ������ ��    "
    },
    {
      "  �������� ��   ",
      "   ������ ��    "
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
    if (index_of_ekran_tmp < MAX_ROW_FOR_CONTROL_SWITCH)
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
          
        if(current_ekran.edition == 0) temp_data = current_settings.control_switch;
        else temp_data = edition_settings.control_switch;
          
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
//������� ����� ����������� �������� ����������� ���������� ��� ��������
/*****************************************************/
void make_ekran_control_switch_(uint32_t on_off)
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_CONTROL_SWITCH][MAX_COL_LCD] = 
  {
    {
      " �������� ��(x) ",
      "   ������ ��(x) "
    },
    {
      " �������� ��(x) ",
      "   ������ ��(x) "
    },
    {
      "  CB Control(x) ",
      "   ������ ��(x) "
    },
    {
      " �������� ��(x) ",
      "   ������ ��(x) "
    }
  };
  static const uint8_t ind_index[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_CONTROL_SWITCH] = 
  {
    {13,13},
    {13,13},
    {12,12},
    {13,13}
  };
  
  
  int index_language = index_language_in_array(current_settings.language);
  
  unsigned int position_temp = current_ekran.index_position;
  unsigned int index_of_ekran;
  
  //�������� �� ��� �������� position_temp ������� ��� ����, �� �� ���� ������� �� ������������� ��� ����� (����� + ��������)
  index_of_ekran = ((position_temp<<1) >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;

  
  for (unsigned int i=0; i< MAX_ROW_LCD; i++)
  {
    unsigned int index_of_ekran_tmp = index_of_ekran >> 1;
    if (index_of_ekran_tmp < MAX_ROW_FOR_CONTROL_SWITCH)
    {
      if ((i & 0x1) == 0)
      {
        //� ��������� ����� ����� �������� ���������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_language][index_of_ekran_tmp][j];
		working_ekran[i][ind_index[index_language][index_of_ekran_tmp]] = OFF_ON_value[index_language][on_off];
      }
      else
      {
        //� ������� ����� ����� �������� �������� �������
        
        unsigned int index_ctr = index_of_ekran_tmp;

        unsigned int temp_data;
   
        if(current_ekran.edition == 0) temp_data = current_settings.control_switch_[on_off];
        else temp_data = edition_settings.control_switch_[on_off];
          
        //?for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = information_off_on[index_language][(temp_data >> index_ctr) & 0x1][j];
        //?if (position_temp == index_of_ekran_tmp) current_ekran.position_cursor_x = cursor_x_off_on[index_language][(temp_data >> index_ctr) & 0x1];
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
