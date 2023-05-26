#include "header.h"

/*****************************************************/
//������� ����� ����������� ������� ������������� �������
/*****************************************************/
void make_ekran_setpoint_UP(unsigned int group)
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_SETPOINT_UP][MAX_COL_LCD] = 
  {
    {
      "      ��x       ",
      "     �� ��x     "
    },
    {
      "      ��x       ",
      "     �� ��x     "
    },
    {
      "      MFPx      ",
      "    MFPx RR     "
    },
    {
      "      ��x       ",
      "     �� ��x     "
    },
  };
  static const uint32_t index_number[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_SETPOINT_UP] = 
  {
    {8, 10},
    {8, 10},
    {9,  7},
    {8, 10}
  };
  
  static const uint8_t string_W[MAX_NAMBER_LANGUAGE][2] = 
  {
    "��",
    "��",
    "W ",
    "��"
  };
  static const uint8_t string_VAR[MAX_NAMBER_LANGUAGE][3] = 
  {
    "���",
    "���",
    "var",
    "���"
  };

  static const uint8_t string_VA[MAX_NAMBER_LANGUAGE][3] = 
  {
    "��",
    "��",
    "VA",
    "��"
  };

  int index_language = index_language_in_array(current_settings.language);
  unsigned int position_temp = current_ekran.index_position;
  
  __vd vd[NUMBER_UP*MAX_ROW_FOR_SETPOINT_UP];
  uint32_t vaga_arr[NUMBER_UP*MAX_ROW_FOR_SETPOINT_UP];
  int32_t *p_value[NUMBER_UP*MAX_ROW_FOR_SETPOINT_UP]; 

  for (size_t i = 0; i < (NUMBER_UP*MAX_ROW_FOR_SETPOINT_UP); i++)
  {
    unsigned int view = ((current_ekran.edition == 0) || (position_temp != i));
    uint32_t _n_UP = i / MAX_ROW_FOR_SETPOINT_UP;
    uint32_t in_canal = current_settings.ctrl_UP_input[_n_UP];
    
    vd[i].sign = -1;
    switch (i)
    {
    case 0:
    case 2:
    case 4:
    case 6:
    case 8:
    case 10:
    case 12:
    case 14:
      {
        switch (in_canal)
        {
        case UP_CTRL_Ia_Ib_Ic:
        case UP_CTRL_Ia:
        case UP_CTRL_Ib:
        case UP_CTRL_Ic:
        case UP_CTRL_I1:
        case UP_CTRL_I2:
        case UP_CTRL_3I0_r:
          {
            vd[i].begin = COL_SETPOINT_UP_I_BEGIN;
            vd[i].comma = COL_SETPOINT_UP_I_COMMA;
            vd[i].end = COL_SETPOINT_UP_I_END;
            vd[i].u_begin = COL_SETPOINT_UP_I_END + 2;
            vd[i].u_end = COL_SETPOINT_UP_I_END + 2;
            vd[i].p_unit = &odynyci_vymirjuvannja[index_language][INDEX_A];
            
            vaga_arr[i] = 100000;
            
            break;
          }
        case UP_CTRL_3I0:
        case UP_CTRL_3I0_others:
          {
            vd[i].begin = COL_SETPOINT_UP_3I0_BEGIN;
            vd[i].comma = COL_SETPOINT_UP_3I0_COMMA;
            vd[i].end = COL_SETPOINT_UP_3I0_END;
            vd[i].u_begin = COL_SETPOINT_UP_3I0_END + 2;
            vd[i].u_end = COL_SETPOINT_UP_3I0_END + 2;
            vd[i].p_unit = &odynyci_vymirjuvannja[index_language][INDEX_A];
            
            vaga_arr[i] = 1000;
            
            break;
          }
        case UP_CTRL_Ua_Ub_Uc:
        case UP_CTRL_Uab_Ubc_Uca:
        case UP_CTRL_Ua:
        case UP_CTRL_Uab:
        case UP_CTRL_Ub:
        case UP_CTRL_Ubc:
        case UP_CTRL_Uc:
        case UP_CTRL_Uca:
        case UP_CTRL_U1:
        case UP_CTRL_U2:
        case UP_CTRL_3U0:
          {
            vd[i].begin = COL_SETPOINT_UP_U_BEGIN;
            vd[i].comma = COL_SETPOINT_UP_U_COMMA;
            vd[i].end = COL_SETPOINT_UP_U_END;
            vd[i].u_begin = COL_SETPOINT_UP_U_END + 2;
            vd[i].u_end = COL_SETPOINT_UP_U_END + 2;
            vd[i].p_unit = &odynyci_vymirjuvannja[index_language][INDEX_V];
            
            vaga_arr[i] = 100000;
            
            break;
          }
        case UP_CTRL_P:
        case UP_CTRL_Q:
          {
            vd[i].sign = COL_SETPOINT_UP_PQ_BEGIN - 1;
            vd[i].begin = COL_SETPOINT_UP_PQ_BEGIN;
            vd[i].comma = COL_SETPOINT_UP_PQ_COMMA;
            vd[i].end = COL_SETPOINT_UP_PQ_END;
            vd[i].u_begin = COL_SETPOINT_UP_PQ_END + 2;
            if (in_canal == UP_CTRL_P)
            {
              if (index_language == INDEX_LANGUAGE_EN) vd[i].u_end = COL_SETPOINT_UP_PQ_END + 2;
              else vd[i].u_end = COL_SETPOINT_UP_PQ_END + 3;
              vd[i].p_unit = &string_W[index_language][0];
            }
            else
            {
              vd[i].u_end = COL_SETPOINT_UP_PQ_END + 4;
              vd[i].p_unit = &string_VAR[index_language][0];
            }
            
            vaga_arr[i] = 1000000;
            
            break;
          }
        case UP_CTRL_S:
          {
            vd[i].begin = COL_SETPOINT_UP_S_BEGIN;
            vd[i].comma = COL_SETPOINT_UP_S_COMMA;
            vd[i].end = COL_SETPOINT_UP_S_END;
            vd[i].u_begin = COL_SETPOINT_UP_S_END + 2;
            vd[i].u_end = COL_SETPOINT_UP_S_END + 3;
            vd[i].p_unit = &string_VA[index_language][0];
            
            vaga_arr[i] = 1000000;
            
            break;
          }
        default:
          {
            //���������� ����� ����� �� ���� � ����
            total_error_sw_fixed();
            
            break;
          }
        }
        
        if (view == true) p_value[i] = current_settings.setpoint_UP[_n_UP][0]; //� ����� value ������� �������� �������
        else p_value[i] = edition_settings.setpoint_UP[_n_UP][0];
        
        break;
      }
    case 1:
    case 3:
    case 5:
    case 7:
    case 9:
    case 11:
    case 13:
    case 15:
      {
        vd[i].begin = COL_SETPOINT_UP_KP_BEGIN;
        vd[i].comma = COL_SETPOINT_UP_KP_COMMA;
        vd[i].end = COL_SETPOINT_UP_KP_END;
        vd[i].u_begin = COL_SETPOINT_UP_KP_END + 2;
        vd[i].u_end = COL_SETPOINT_UP_KP_END + 2;
        vd[i].p_unit = NULL;
            
        vaga_arr[i] = 100;
        
        if (view == true) p_value[i] = (int32_t *)current_settings.setpoint_UP_KP[_n_UP][0]; //� ����� value ������� �������� �������
        else p_value[i] = (int32_t *)edition_settings.setpoint_UP_KP[_n_UP][0];

        break;
      }
    default:
      {
        //���������� ����� ����� �� ���� � ����
        total_error_sw_fixed();
      }
    }
  }

  int index_of_ekran;
  unsigned int vaga, value, first_symbol;
  
  //�������� �� ��� �������� position_temp ������� ��� ����, �� ����� ������� �� ������������� ��� ����� (����� + ��������)
  index_of_ekran = ((position_temp << 1) >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;
  
  for (unsigned int i=0; i< MAX_ROW_LCD; i++)
  {
    if (index_of_ekran < ((NUMBER_UP*MAX_ROW_FOR_SETPOINT_UP) << 1))//�������� �� ��� ������� ��� ����, �� ����� ������� �� ������������� ��� ����� (����� + ��������)
    {
      unsigned int index_of_ekran_tmp = index_of_ekran >> 1;
      if ((i & 0x1) == 0) 
      {
        uint32_t _n_UP = index_of_ekran_tmp / MAX_ROW_FOR_SETPOINT_UP;
        uint32_t _n_index = index_of_ekran_tmp % MAX_ROW_FOR_SETPOINT_UP;
        //� ��������� ����� ����� �������� ���������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) 
        {
          working_ekran[i][j] = (j != index_number[index_language][_n_index]) ? name_string[index_language][_n_index][j] : (_n_UP + 1 + 0x30);
        }
        vaga = vaga_arr[index_of_ekran_tmp];
        value = abs(*(p_value[index_of_ekran_tmp] + group));
        
        first_symbol = 0; //�������, �� �� ����� �������� ������ �� ���������
      }
      else
      {
        //� ������� ����� ����� �������� �������� �������
        unsigned int view = ((current_ekran.edition == 0) || (position_temp != index_of_ekran_tmp));
        for (unsigned int j = 0; j<MAX_COL_LCD; j++)
        {
          if (j == vd[index_of_ekran_tmp].sign)
          {
            working_ekran[i][j] = (*(p_value[index_of_ekran_tmp] + group) < 0) ? '-' : ' ';
          }
          else if (
                   ((j < vd[index_of_ekran_tmp].begin) ||  (j > vd[index_of_ekran_tmp].end ))  &&
                    (
                     (vd[index_of_ekran_tmp].p_unit == NULL) ||
                     (!((j >= (vd[index_of_ekran_tmp].end + 2)) && (j <= (vd[index_of_ekran_tmp].end + 2 + vd[index_of_ekran_tmp].u_end - vd[index_of_ekran_tmp].u_begin))))
                   )    
                  )working_ekran[i][j] = ' ';
          else if (j == vd[index_of_ekran_tmp].comma )working_ekran[i][j] = ','; /*���� ���� �� �������, �� ����� ��� comma ���� ������ �� begin � ��� �� ��� ������� ���� �������� �� ����*/
          else if (
                   (vd[index_of_ekran_tmp].p_unit != NULL) &&
                   ((j >= (vd[index_of_ekran_tmp].end + 2)) && (j <= (vd[index_of_ekran_tmp].end + 2 + vd[index_of_ekran_tmp].u_end - vd[index_of_ekran_tmp].u_begin)))
                  )   
            working_ekran[i][j] = vd[index_of_ekran_tmp].p_unit[j - vd[index_of_ekran_tmp].u_begin];
          else
            calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, vd[index_of_ekran_tmp].comma, view, 0);
          
        }
        
        if (
            (vd[index_of_ekran_tmp].sign >= 0) &&
            (view == true)
           )   
        {
          //ϳ������� ���� �� ����� �����
          for (int32_t j = vd[index_of_ekran_tmp].sign; j < (int32_t)MAX_COL_LCD; j++)
          {
            if (((working_ekran[i][j + 1]) == ' ') && (j < ((int32_t)vd[index_of_ekran_tmp].end - 1)))
            {
              working_ekran[i][j + 1] = working_ekran[i][j];
              working_ekran[i][j] = ' ';
              vd[index_of_ekran_tmp].sign++;
            }
            else break;
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
    if (vd[current_ekran.index_position].sign < 0)
      current_ekran.position_cursor_x = vd[current_ekran.index_position].begin;
    else
      current_ekran.position_cursor_x = vd[current_ekran.index_position].sign;
    last_position_cursor_x = vd[current_ekran.index_position].end;
    
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
//������� ����� ����������� �������� ������������� �������
/*****************************************************/
void make_ekran_timeout_UP(unsigned int group)
{
  static const uint8_t name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_TIMEOUT_UP][MAX_COL_LCD] = 
  {
    {
      "      ��x       "
    },
    {
      "      ��x       "
    },
    {
      "   MFPx Delay   "
    },
    {
      "      ��x       "
    }
  };
  static const uint32_t index_number[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_TIMEOUT_UP] = 
  {
    {8},
    {8},
    {6},
    {8}
  };

  int index_language = index_language_in_array(current_settings.language);
  
  const __vd vd[MAX_ROW_FOR_TIMEOUT_UP] = 
  {
    {-1, COL_TMO_UP_BEGIN, COL_TMO_UP_COMMA, COL_TMO_UP_END, COL_TMO_UP_END + 2, COL_TMO_UP_END + 2, &odynyci_vymirjuvannja[index_language][INDEX_SECOND]}
  };
  static const uint32_t vaga_arr[MAX_ROW_FOR_TIMEOUT_UP] = 
  {
    100000
  };
  static int32_t (* const p_value_current[MAX_ROW_FOR_TIMEOUT_UP])[1][NUMBER_GROUP_USTAVOK] = 
  {
    current_settings.timeout_UP 
  };
  static int32_t (* const p_value_edit[MAX_ROW_FOR_TIMEOUT_UP])[1][NUMBER_GROUP_USTAVOK] = 
  {
    edition_settings.timeout_UP
  };

  unsigned int position_temp = current_ekran.index_position;

  int index_of_ekran;
  unsigned int vaga, value, first_symbol;
  
  //�������� �� ��� �������� position_temp ������� ��� ����, �� �� ���� ������� �� ������������� ��� ����� (����� + ��������)
  index_of_ekran = ((position_temp<<1) >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;

  
  for (unsigned int i=0; i< MAX_ROW_LCD; i++)
  {
    if (index_of_ekran < ((NUMBER_UP*MAX_ROW_FOR_TIMEOUT_UP) << 1))//�������� �� ��� ��������� ������� ��� ����, �� �� ���� ������� �� ������������� ��� ����� (����� + ��������)
    {
      unsigned int index_of_ekran_tmp = index_of_ekran >> 1;
      uint32_t _n_index = index_of_ekran_tmp % MAX_ROW_FOR_TIMEOUT_UP;
      unsigned int view = ((current_ekran.edition == 0) || (position_temp != index_of_ekran_tmp));
      if ((i & 0x1) == 0)
      {
        //� ��������� ����� ����� �������� ���������
        uint32_t _n_UP = index_of_ekran_tmp / MAX_ROW_FOR_TIMEOUT_UP;
        for (unsigned int j = 0; j < MAX_COL_LCD; j++) 
        {
          working_ekran[i][j] = (j != index_number[index_language][_n_index]) ? name_string[index_language][_n_index][j] : (_n_UP + 1 + 0x30);
        }
        
        vaga = vaga_arr[_n_index];
        if (view == true) value = p_value_current[_n_index][_n_UP][0][group]; //� ����� value ������� �������� ��������
        else value = p_value_edit[_n_index][_n_UP][0][group];

        first_symbol = 0; //�������, �� �� ����� �������� ������ �� ���������
      }
      else
      {
        //� ������� ����� ����� �������� �������� �������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++)
        {
          if (
              ((j < vd[_n_index].begin) ||  (j > vd[_n_index].end ))  &&
               (
                (vd[_n_index].p_unit == NULL) ||
                (!((j >= (vd[_n_index].end + 2)) && (j <= (vd[_n_index].end + 2 + vd[_n_index].u_end - vd[_n_index].u_begin))))
               )    
             )working_ekran[i][j] = ' ';
          else if (j == vd[_n_index].comma )working_ekran[i][j] = ','; /*���� ���� �� �������, �� ����� ��� comma ���� ������ �� begin � ��� �� ��� ������� ���� �������� �� ����*/
          else if (
                   (vd[_n_index].p_unit != NULL) &&
                   ((j >= (vd[_n_index].end + 2)) && (j <= (vd[_n_index].end + 2 + vd[_n_index].u_end - vd[_n_index].u_begin)))
                  )   
            working_ekran[i][j] = vd[_n_index].p_unit[j - vd[_n_index].u_begin];
          else
            calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, vd[_n_index].comma, view, 0);

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
    uint32_t _n_index = current_ekran.index_position % MAX_ROW_FOR_TIMEOUT_UP;
    
    int last_position_cursor_x = MAX_COL_LCD;
    current_ekran.position_cursor_x = vd[_n_index].begin;
    last_position_cursor_x = vd[_n_index].end;

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
//������� ����� ����������� �������� ����������� ���������� ��� ������������� �������
/*****************************************************/
void make_ekran_control_UP()
{
  static const uint8_t name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_CONTROL_UP][MAX_COL_LCD] = 
  {
    {
      "    ���� ��x    ",
      "      ��x       ",
      " ���/� ��� ��x  ",
      "  >/< ��� ��x   "
    },
    {
      "    ���� ��x    ",
      "      ��x       ",
      " ���/� ��� ��x  ",
      "  >/< ��� ��x   "
    },
    {
      "    MFPx AI     ",
      "      MFPx      ",
      " OR/AND for MFPx",
      "  >/< for MFPx  "
    },
    {
      "    ���� ��x    ",
      "      ��x       ",
      " ���/� ��� ��x  ",
      "  >/< ��� ��x   "
    },
  };
  static const uint32_t index_number[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_CONTROL_UP] = 
  {
    {11, 8, 13, 12},
    {11, 8, 13, 12},
    { 7, 9, 15, 13},
    {11, 8, 13, 12}
  };
  
  uint8_t information_2[_UP_CTRL_NUMBER][MAX_COL_LCD] = 
  {
    "    Ia/Ib/Ic    ",
    "       Ia       ",
    "       Ib       ",
    "       Ic       ",
    "       I1       ",
    "       I2       ",
    "      3I0-1     ",
    "       3I0      ",
    "      3I0**     ",
    "    Ua/Ub/Uc    ",
    "  Uab/Ubc/Uca   ",
    "       Ua       ",
    "      Uab       ",
    "       Ub       ",
    "      Ubc       ",
    "       Uc       ",
    "      Uca       ",
    "       U1       ",
    "       U2       ",
    "       3U0      ",
    "       P        ",
    "       Q        ",
    "       S        "
  };
  static const uint32_t cursor_x_2[_UP_CTRL_NUMBER] = {3, 6, 6, 6, 6, 6, 5, 6, 5, 3, 1, 6, 5, 6, 5, 6, 5, 6, 6, 6, 6, 6, 6};
  
  static const uint8_t information_3[MAX_NAMBER_LANGUAGE][2][MAX_COL_LCD] =
  {
    {"      ���       ", "       �        "},
    {"      ���       ", "       �        "},
    {"       OR       ", "      AND       "},
    {"      ���       ", "       �        "}
  };
  static const uint32_t cursor_x_3[MAX_NAMBER_LANGUAGE][2] = 
  {
    {5, 6},
    {5, 6},
    {6, 5},
    {5, 6}
  };
    
  static const uint8_t information_4[2][MAX_COL_LCD] = 
  {
    "       >        ",
    "       <        "
  };
  static const uint32_t cursor_x_4 = 6;
        
  int index_language = index_language_in_array(current_settings.language);

  __SETTINGS *point = (current_ekran.edition == 0) ? &current_settings : &edition_settings;
  
  __ctrl_info ctrl_info[NUMBER_UP*MAX_ROW_FOR_CONTROL_UP];
  for (size_t i = 0; i < (NUMBER_UP*MAX_ROW_FOR_CONTROL_UP); i++)
  {
    switch (i)
    {
    case 0:
    case 4:
    case 8:
    case 12:
    case 16:
    case 20:
    case 24:
    case 28:
      {
        uint32_t index = point->ctrl_UP_input[i / MAX_ROW_FOR_CONTROL_UP];
        ctrl_info[i].information = information_2[index];
        ctrl_info[i].cursor_x = cursor_x_2[index];
        break;
      }
    case 1:
    case 5:
    case 9:
    case 13:
    case 17:
    case 21:
    case 25:
    case 29:
      {
        uint32_t index = (point->control_UP >> ((i / MAX_ROW_FOR_CONTROL_UP)*(_CTR_UP_NEXT_BIT - (_CTR_UP_PART_II - _CTR_UP_PART_I) - _CTR_UP_PART_I) + CTR_UP_STATE_BIT - (_CTR_UP_PART_II - _CTR_UP_PART_I))) & 0x1;
        ctrl_info[i].information = information_off_on[index_language][index];
        ctrl_info[i].cursor_x = cursor_x_off_on[index_language][index];
        break;
      }
    case 2:
    case 6:
    case 10:
    case 14:
    case 18:
    case 22:
    case 26:
    case 30:
      {
        uint32_t index = (point->control_UP >> ((i / MAX_ROW_FOR_CONTROL_UP)*(_CTR_UP_NEXT_BIT - (_CTR_UP_PART_II - _CTR_UP_PART_I) - _CTR_UP_PART_I) + CTR_UP_OR_AND_BIT - (_CTR_UP_PART_II - _CTR_UP_PART_I))) & 0x1;
        ctrl_info[i].information = information_3[index_language][index];
        ctrl_info[i].cursor_x = cursor_x_3[index_language][index];
        break;
      }
    case 3:
    case 7:
    case 11:
    case 15:
    case 19:
    case 23:
    case 27:
    case 31:
      {
        uint32_t index = (point->control_UP >> ((i / MAX_ROW_FOR_CONTROL_UP)*(_CTR_UP_NEXT_BIT - (_CTR_UP_PART_II - _CTR_UP_PART_I) - _CTR_UP_PART_I) + CTR_UP_MORE_LESS_BIT - (_CTR_UP_PART_II - _CTR_UP_PART_I))) & 0x1;
        ctrl_info[i].information = information_4[index];
        ctrl_info[i].cursor_x = cursor_x_4;
        break;
      }
    default:
      {
        //���������� ����� ����� �� ���� � ����
        total_error_sw_fixed();
      }
    }
  }

  uint8_t name_string_tmp[NUMBER_UP*MAX_ROW_FOR_CONTROL_UP][MAX_COL_LCD];

  for(size_t index_1 = 0; index_1 < (NUMBER_UP*MAX_ROW_FOR_CONTROL_UP); index_1++)
  {
    uint32_t index_1_tmp = index_1 % MAX_ROW_FOR_CONTROL_UP;
    uint32_t index_number_tmp = index_number[index_language][index_1_tmp];
    for(size_t index_2 = 0; index_2 < MAX_COL_LCD; index_2++)
    {
      name_string_tmp[index_1][index_2] = (index_2 != index_number_tmp) ? name_string[index_language][index_1_tmp][index_2] : ((index_1 / MAX_ROW_FOR_CONTROL_UP) + 1 + 0x30);
    }
  }
  
  /******************************************/
  //��������� ����, �� �� ����� ����������
  /******************************************/
  int32_t additional_current = 0;
  int32_t position_temp = current_ekran.index_position;
  
  for (size_t current_index = 0; current_index < (NUMBER_UP*MAX_ROW_FOR_CONTROL_UP); current_index++ )
  {
    uint32_t ctrl_UP_input = point->ctrl_UP_input[current_index / (_CTR_UP_NEXT_BIT - _CTR_UP_PART_I)];
    if (
         ((current_index % (_CTR_UP_NEXT_BIT - _CTR_UP_PART_I)) == CTR_UP_OR_AND_BIT) &&
         (ctrl_UP_input != UP_CTRL_Ia_Ib_Ic) &&
         (ctrl_UP_input != UP_CTRL_Ua_Ub_Uc) &&
         (ctrl_UP_input != UP_CTRL_Uab_Ubc_Uca)
       )   
    {
      int i = current_index - additional_current;

      if ((i+1) <= position_temp) position_temp--;
      do
      {
        if ((i+1) < (NUMBER_UP*MAX_ROW_FOR_CONTROL_UP - additional_current))
        {
          ctrl_info[i] = ctrl_info[i + 1];
          for(unsigned int j = 0; j<MAX_COL_LCD; j++) name_string_tmp[i][j] = name_string_tmp[i + 1][j];
        }
        else 
        {
          for(unsigned int j = 0; j<MAX_COL_LCD; j++) name_string_tmp[i][j] = ' ';
        }
        i++;
      }
      while (i < (NUMBER_UP*MAX_ROW_FOR_CONTROL_UP - additional_current));
    
      additional_current++;
    }
  }
  /******************************************/
  
  //�������� �� ��� �������� position_temp ������� ��� ����, �� �� ���� ������� �� ������������� ��� ����� (����� + ��������)
  int32_t index_of_ekran = ((position_temp<<1) >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;
  
  for (size_t i=0; i< MAX_ROW_LCD; i++)
  {
    int32_t index_of_ekran_tmp = index_of_ekran >> 1;
    if (index_of_ekran_tmp < (NUMBER_UP*MAX_ROW_FOR_CONTROL_UP - additional_current))//�������� �� ��� ��������� ������� ��� ����, �� �� ���� ������� �� ������������� ��� ����� (����� + ��������)
    {
      if ((i & 0x1) == 0)
      {
        //� ��������� ����� ����� �������� ���������
        for (size_t j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string_tmp[index_of_ekran_tmp][j];
      }
      else
      {
        //� ������� ����� ����� �������� �������� �������

        for (size_t j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = ctrl_info[index_of_ekran_tmp].information[j];
        if (position_temp == index_of_ekran_tmp) current_ekran.position_cursor_x = ctrl_info[index_of_ekran_tmp].cursor_x;
      }
    }
    else
      for (size_t j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = ' ';

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
//������� ����� ����������� �������� ����������� ���������� ��� ������������� �������
/*****************************************************/
void make_ekran_control_UP_A01(void)
{
  static const uint8_t name_string_a01[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_CONTROL_A01_UP][MAX_COL_LCD] = 
  {
    {
      "    ���� ��x    ",//���� ��x x placed on 11
      "      ��x       ",// x placed on 8
      //?" ���/� ��� ��x  ",//x placed on 13
      "  >/< ��� ��x   " //x placed on 12
    },
    {
      "    ���� ��x    ",
      "      ��x       ",
      //?" ���/� ��� ��x  ",
      "  >/< ��� ��x   "
    },
    {
      "   UPx Input    ",
      "      UPx       ",
      //?" OR/AND for UPx ",
      "  >/< for UPx   "
    },
    {
      "    ���� ��x    ",
      "      ��x       ",
      //?" ���/� ��� ��x  ",
      "  >/< ��� ��x   "
    },
  };
  static const uint32_t index_number_a01[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_CONTROL_A01_UP] = 
  {
    {11, 8,    12}, //{11, 8, 13, 12},���� ��x x placed on 11 ��x
    {11, 8,    12}, //{11, 8, 13, 12},<- index in name_string where letter x placed
    { 5, 8,    12}, //{ 5, 8, 14, 12},
    {11, 8,    12}  //{11, 8, 13, 12}
  };
  
  uint8_t information_2_a01[_UP_CTRL_A01_NUMBER][MAX_COL_LCD] = 
  {
    
    "       Impl     ",//6
    "       Umpl     ",//6
    "       Ibpl     ",//6
    "       Ubpl     ",//6
//    "       Uc       ",
    "       Pmpl     ",//6
    "       Qmpl     ",//6
    "       Smpl     ",//6
    "       Pbpl     ",//6
    "       Qbpl     ",//6
    "       Sbpl     "
  };
  static const uint32_t cursor_x_2_a01[_UP_CTRL_A01_NUMBER] = { 6, 6, 6, 6, 6, 6, 6, 6, 6, 6};
  /*
  static const uint8_t information_3_[MAX_NAMBER_LANGUAGE][2][MAX_COL_LCD] =
  {
    {"      ���       ", "       �        "},//<- now not needed for compatibility only
    {"      ���       ", "       �        "},
    {"       OR       ", "      AND       "},
    {"      ���       ", "       �        "}
  };
  static const uint32_t cursor_x_3_a01[MAX_NAMBER_LANGUAGE][2] = 
  {
    {5, 6},//<- now not needed for compatibility only
    {5, 6},
    {6, 5},
    {5, 6}
  };
    */
  static const uint8_t information_4_a01[2][MAX_COL_LCD] = 
  {
    "       >        ",//<-
    "       <        "
  };
  static const uint32_t cursor_x_4_a01 = 6;//<-
        
  int index_language = index_language_in_array(current_settings.language);

  __SETTINGS *point = (current_ekran.edition == 0) ? &current_settings : &edition_settings;
  
  __ctrl_info ctrl_info[NUMBER_UP*MAX_ROW_FOR_CONTROL_A01_UP];
  for (size_t i = 0; i < (NUMBER_UP*MAX_ROW_FOR_CONTROL_A01_UP); i++)
  {
    switch (i)
    {
    case 0 :   //.case 0:
    case 3 :   //.case 4:
    case 6 :   //.case 8:
    case 9 :  //.case 12:
    case 12:  //.case 16:
    case 15:  //.case 20:
    case 18:  //.case 24:
    case 21:  //.case 28:
      {
        uint32_t index = point->ctrl_UP_input[i / MAX_ROW_FOR_CONTROL_A01_UP];
        ctrl_info[i].information = information_2_a01[index];
        ctrl_info[i].cursor_x = cursor_x_2_a01[index];
        break;
      }
    case 1 :
    case 4 :
    case 7 :
    case 10:
    case 13:
    case 16:
    case 19:
    case 22:
      {
        uint32_t index = (point->control_UP >> ((i / MAX_ROW_FOR_CONTROL_A01_UP)*(_CTR_A01_UP_NEXT_BIT - (_CTR_A01_UP_PART_II - _CTR_A01_UP_PART_I) - _CTR_A01_UP_PART_I) + CTR_A01_UP_STATE_BIT - (_CTR_A01_UP_PART_II - _CTR_A01_UP_PART_I))) & 0x1;
        ctrl_info[i].information = information_off_on[index_language][index];
        ctrl_info[i].cursor_x = cursor_x_off_on[index_language][index];
        break;
      }
    //?case 2:
    //?case 6:
    //?case 10:
    //?case 14:
    //?case 18:
    //?case 22:
    //?case 26:
    //?case 30:
    //?  {
    //?    uint32_t index = (point->control_UP >> ((i / MAX_ROW_FOR_CONTROL_A01_UP)*(_CTR_UP_NEXT_BIT - (_CTR_A01_UP_PART_II - _CTR_UP_PART_I) - _CTR_UP_PART_I) + CTR_UP_OR_AND_BIT - (_CTR_A01_UP_PART_II - _CTR_A01_UP_PART_I))) & 0x1;
    //?    ctrl_info[i].information = information_3_[index_language][index];
    //?    ctrl_info[i].cursor_x = cursor_x_3_a01[index_language][index];
    //?    break;
    //?  }
    case 2 :
    case 5 :
    case 8 :
    case 11:
    case 14:
    case 17:
    case 20:
    case 23:
      {
        uint32_t index = (point->control_UP >> ((i / MAX_ROW_FOR_CONTROL_A01_UP)*(_CTR_A01_UP_NEXT_BIT - (_CTR_A01_UP_PART_II - _CTR_A01_UP_PART_I) - _CTR_A01_UP_PART_I) + CTR_A01_UP_MORE_LESS_BIT - (_CTR_A01_UP_PART_II - _CTR_A01_UP_PART_I))) & 0x1;
        ctrl_info[i].information = information_4_a01[index];
        ctrl_info[i].cursor_x = cursor_x_4_a01;
        break;
      }
    default:
      {
        //���������� ����� ����� �� ���� � ����
        total_error_sw_fixed();
      }
    }
  }

  uint8_t name_string_tmp[NUMBER_UP*MAX_ROW_FOR_CONTROL_A01_UP][MAX_COL_LCD];

  for(size_t index_1 = 0; index_1 < (NUMBER_UP*MAX_ROW_FOR_CONTROL_A01_UP); index_1++)
  {
    uint32_t index_1_tmp = index_1 % MAX_ROW_FOR_CONTROL_A01_UP;
    uint32_t index_number_tmp = index_number_a01[index_language][index_1_tmp];
    for(size_t index_2 = 0; index_2 < MAX_COL_LCD; index_2++)
    {
      name_string_tmp[index_1][index_2] = (index_2 != index_number_tmp) 
	  ? name_string_a01[index_language][index_1_tmp][index_2] 
	  : ((index_1 / MAX_ROW_FOR_CONTROL_A01_UP) + 1 + 0x30);
    }
  }
  
  /******************************************/
  //��������� ����, �� �� ����� ����������
  /******************************************/
  int32_t additional_current = 0;
  int32_t position_temp = current_ekran.index_position;
  
  for (size_t current_index = 0; current_index < (NUMBER_UP*MAX_ROW_FOR_CONTROL_A01_UP); current_index++ )
  {
    //?uint32_t ctrl_UP_input = point->ctrl_UP_input[current_index / (_CTR_UP_NEXT_BIT - _CTR_UP_PART_I)];
    uint32_t ctrl_UP_input = point->ctrl_UP_input[current_index / (_CTR_A01_UP_NEXT_BIT - _CTR_A01_UP_PART_I)];
    //!if (
    //!     ((current_index % (_CTR_A01_UP_NEXT_BIT - _CTR_A01_UP_PART_I)) == CTR_UP_OR_AND_BIT) &&
    //!     (ctrl_UP_input != UP_CTRL_Ia_Ib_Ic) &&
    //!     (ctrl_UP_input != UP_CTRL_Ua_Ub_Uc) &&
    //!     (ctrl_UP_input != UP_CTRL_Uab_Ubc_Uca)
    //!   )   
    if (
         ((current_index % (_CTR_A01_UP_NEXT_BIT - _CTR_A01_UP_PART_I)) == (CTR_UP_OR_AND_BIT+3)) &&
         (ctrl_UP_input != UP_CTRL_Ia_Ib_Ic) &&
         (ctrl_UP_input != UP_CTRL_Ua_Ub_Uc) &&
         (ctrl_UP_input != UP_CTRL_Uab_Ubc_Uca)
       )   
    {
      int i = current_index - additional_current;

      if ((i+1) <= position_temp) position_temp--;
      do
      {
        if ((i+1) < (NUMBER_UP*MAX_ROW_FOR_CONTROL_A01_UP - additional_current))
        {
          ctrl_info[i] = ctrl_info[i + 1];
          for(unsigned int j = 0; j<MAX_COL_LCD; j++) name_string_tmp[i][j] = name_string_tmp[i + 1][j];
        }
        else 
        {
          for(unsigned int j = 0; j<MAX_COL_LCD; j++) name_string_tmp[i][j] = ' ';
        }
        i++;
      }
      while (i < (NUMBER_UP*MAX_ROW_FOR_CONTROL_A01_UP - additional_current));
    
      additional_current++;
    }
  }
  /******************************************/
  
  //�������� �� ��� �������� position_temp ������� ��� ����, �� �� ���� ������� �� ������������� ��� ����� (����� + ��������)
  int32_t index_of_ekran = ((position_temp<<1) >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;
  
  for (size_t i=0; i< MAX_ROW_LCD; i++)
  {
    int32_t index_of_ekran_tmp = index_of_ekran >> 1;
    if (index_of_ekran_tmp < (NUMBER_UP*MAX_ROW_FOR_CONTROL_A01_UP - additional_current))//�������� �� ��� ��������� ������� ��� ����, �� �� ���� ������� �� ������������� ��� ����� (����� + ��������)
    {
      if ((i & 0x1) == 0)
      {
        //� ��������� ����� ����� �������� ���������
        for (size_t j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string_tmp[index_of_ekran_tmp][j];
      }
      else
      {
        //� ������� ����� ����� �������� �������� �������

        for (size_t j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = ctrl_info[index_of_ekran_tmp].information[j];
        if (position_temp == index_of_ekran_tmp) current_ekran.position_cursor_x = ctrl_info[index_of_ekran_tmp].cursor_x;
      }
    }
    else
      for (size_t j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = ' ';

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
//������� ����� ����������� ������� ������������� �������
/*****************************************************/
void make_ekran_setpoint_UP_A01(unsigned int group)
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_SETPOINT_UP][MAX_COL_LCD] = 
  {
    {
      "      ��x       ",
      "     �� ��x     "
    },
    {
      "      ��x       ",
      "     �� ��x     "
    },
    {
      "      UPx       ",
      "     KB UPx     "
    },
    {
      "      ��x       ",
      "     �� ��x     "
    },
  };
  static const uint32_t index_number[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_SETPOINT_UP] = 
  {
    {8, 10},
    {8, 10},
    {8, 10},
    {8, 10}
  };
  
  static const uint8_t string_W[MAX_NAMBER_LANGUAGE][2] = 
  {
    "��",
    "��",
    "W ",
    "��"
  };
  static const uint8_t string_VAR[MAX_NAMBER_LANGUAGE][3] = 
  {
    "���",
    "���",
    "var",
    "���"
  };

  static const uint8_t string_VA[MAX_NAMBER_LANGUAGE][3] = 
  {
    "��",
    "��",
    "VA",
    "��"
  };

  int index_language = index_language_in_array(current_settings.language);
  unsigned int position_temp = current_ekran.index_position;
  
  __vd vd[NUMBER_UP*MAX_ROW_FOR_SETPOINT_UP];
  uint32_t vaga_arr[NUMBER_UP*MAX_ROW_FOR_SETPOINT_UP];
  int32_t *p_value[NUMBER_UP*MAX_ROW_FOR_SETPOINT_UP]; 

  for (size_t i = 0; i < (NUMBER_UP*MAX_ROW_FOR_SETPOINT_UP); i++)
  {
    unsigned int view = ((current_ekran.edition == 0) || (position_temp != i));
    uint32_t _n_UP = i / MAX_ROW_FOR_SETPOINT_UP;
    uint32_t in_canal = current_settings.ctrl_UP_input[_n_UP];
    
    vd[i].sign = -1;
    switch (i)
    {
    case 0:
    case 2:
    case 4:
    case 6:
    case 8:
    case 10:
    case 12:
    case 14:
      {
        switch (in_canal)
        {
        case UP_CTRL_A01_Io:
        case UP_CTRL_A01_Ir:

          {
            vd[i].begin = COL_SETPOINT_UP_I_BEGIN;
            vd[i].comma = COL_SETPOINT_UP_I_COMMA;
            vd[i].end = COL_SETPOINT_UP_I_END;
            vd[i].u_begin = COL_SETPOINT_UP_I_END + 2;
            vd[i].u_end = COL_SETPOINT_UP_I_END + 2;
            vd[i].p_unit = &odynyci_vymirjuvannja[index_language][INDEX_A];
            
            vaga_arr[i] = 100000;
            
            break;
          }

        case UP_CTRL_A01_Uo:
        case UP_CTRL_A01_Ur:
          {
            vd[i].begin = COL_SETPOINT_UP_U_BEGIN;
            vd[i].comma = COL_SETPOINT_UP_U_COMMA;
            vd[i].end = COL_SETPOINT_UP_U_END;
            vd[i].u_begin = COL_SETPOINT_UP_U_END + 2;
            vd[i].u_end = COL_SETPOINT_UP_U_END + 2;
            vd[i].p_unit = &odynyci_vymirjuvannja[index_language][INDEX_V];
            
            vaga_arr[i] = 100000;
            
            break;
          }
        case UP_CTRL_A01_Po:
        case UP_CTRL_A01_Pr:
        case UP_CTRL_A01_Qo:
        case UP_CTRL_A01_Qr:
          {
            vd[i].sign = COL_SETPOINT_UP_PQ_BEGIN - 1;
            vd[i].begin = COL_SETPOINT_UP_PQ_BEGIN;
            vd[i].comma = COL_SETPOINT_UP_PQ_COMMA;
            vd[i].end = COL_SETPOINT_UP_PQ_END;
            vd[i].u_begin = COL_SETPOINT_UP_PQ_END + 2;
            if (in_canal == UP_CTRL_A01_Po)
            {
              if (index_language == INDEX_LANGUAGE_EN) vd[i].u_end = COL_SETPOINT_UP_PQ_END + 2;
              else vd[i].u_end = COL_SETPOINT_UP_PQ_END + 3;
              vd[i].p_unit = &string_W[index_language][0];
            }
            else
            {
              vd[i].u_end = COL_SETPOINT_UP_PQ_END + 4;
              vd[i].p_unit = &string_VAR[index_language][0];
            }
            
            vaga_arr[i] = 1000000;
            
            break;
          }
        case UP_CTRL_A01_So:
        case UP_CTRL_A01_Sr:
          {
            vd[i].begin = COL_SETPOINT_UP_S_BEGIN;
            vd[i].comma = COL_SETPOINT_UP_S_COMMA;
            vd[i].end = COL_SETPOINT_UP_S_END;
            vd[i].u_begin = COL_SETPOINT_UP_S_END + 2;
            vd[i].u_end = COL_SETPOINT_UP_S_END + 3;
            vd[i].p_unit = &string_VA[index_language][0];
            
            vaga_arr[i] = 1000000;
            
            break;
          }
        default:
          {
            //���������� ����� ����� �� ���� � ����
            total_error_sw_fixed();
            
            break;
          }
        }
        
        if (view == true) p_value[i] = current_settings.setpoint_UP[_n_UP][0]; //� ����� value ������� �������� �������
        else p_value[i] = edition_settings.setpoint_UP[_n_UP][0];
        
        break;
      }
    case 1:
    case 3:
    case 5:
    case 7:
    case 9:
    case 11:
    case 13:
    case 15:
      {
        vd[i].begin = COL_SETPOINT_UP_KP_BEGIN;
        vd[i].comma = COL_SETPOINT_UP_KP_COMMA;
        vd[i].end = COL_SETPOINT_UP_KP_END;
        vd[i].u_begin = COL_SETPOINT_UP_KP_END + 2;
        vd[i].u_end = COL_SETPOINT_UP_KP_END + 2;
        vd[i].p_unit = NULL;
            
        vaga_arr[i] = 100;
        
        if (view == true) p_value[i] = (int32_t *)current_settings.setpoint_UP_KP[_n_UP][0]; //� ����� value ������� �������� �������
        else p_value[i] = (int32_t *)edition_settings.setpoint_UP_KP[_n_UP][0];

        break;
      }
    default:
      {
        //���������� ����� ����� �� ���� � ����
        total_error_sw_fixed();
      }
    }
  }

  int index_of_ekran;
  unsigned int vaga, value, first_symbol;
  
  //�������� �� ��� �������� position_temp ������� ��� ����, �� ����� ������� �� ������������� ��� ����� (����� + ��������)
  index_of_ekran = ((position_temp << 1) >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;
  
  for (unsigned int i=0; i< MAX_ROW_LCD; i++)
  {
    if (index_of_ekran < ((NUMBER_UP*MAX_ROW_FOR_SETPOINT_UP) << 1))//�������� �� ��� ������� ��� ����, �� ����� ������� �� ������������� ��� ����� (����� + ��������)
    {
      unsigned int index_of_ekran_tmp = index_of_ekran >> 1;
      if ((i & 0x1) == 0) 
      {
        uint32_t _n_UP = index_of_ekran_tmp / MAX_ROW_FOR_SETPOINT_UP;
        uint32_t _n_index = index_of_ekran_tmp % MAX_ROW_FOR_SETPOINT_UP;
        //� ��������� ����� ����� �������� ���������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) 
        {
          working_ekran[i][j] = (j != index_number[index_language][_n_index]) ? name_string[index_language][_n_index][j] : (_n_UP + 1 + 0x30);
        }
        vaga = vaga_arr[index_of_ekran_tmp];
        value = abs(*(p_value[index_of_ekran_tmp] + group));
        
        first_symbol = 0; //�������, �� �� ����� �������� ������ �� ���������
      }
      else
      {
        //� ������� ����� ����� �������� �������� �������
        unsigned int view = ((current_ekran.edition == 0) || (position_temp != index_of_ekran_tmp));
        for (unsigned int j = 0; j<MAX_COL_LCD; j++)
        {
          if (j == vd[index_of_ekran_tmp].sign)
          {
            working_ekran[i][j] = (*(p_value[index_of_ekran_tmp] + group) < 0) ? '-' : ' ';
          }
          else if (
                   ((j < vd[index_of_ekran_tmp].begin) ||  (j > vd[index_of_ekran_tmp].end ))  &&
                    (
                     (vd[index_of_ekran_tmp].p_unit == NULL) ||
                     (!((j >= (vd[index_of_ekran_tmp].end + 2)) && (j <= (vd[index_of_ekran_tmp].end + 2 + vd[index_of_ekran_tmp].u_end - vd[index_of_ekran_tmp].u_begin))))
                   )    
                  )working_ekran[i][j] = ' ';
          else if (j == vd[index_of_ekran_tmp].comma )working_ekran[i][j] = ','; /*���� ���� �� �������, �� ����� ��� comma ���� ������ �� begin � ��� �� ��� ������� ���� �������� �� ����*/
          else if (
                   (vd[index_of_ekran_tmp].p_unit != NULL) &&
                   ((j >= (vd[index_of_ekran_tmp].end + 2)) && (j <= (vd[index_of_ekran_tmp].end + 2 + vd[index_of_ekran_tmp].u_end - vd[index_of_ekran_tmp].u_begin)))
                  )   
            working_ekran[i][j] = vd[index_of_ekran_tmp].p_unit[j - vd[index_of_ekran_tmp].u_begin];
          else
            calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, vd[index_of_ekran_tmp].comma, view, 0);
          
        }
        
        if (
            (vd[index_of_ekran_tmp].sign >= 0) &&
            (view == true)
           )   
        {
          //ϳ������� ���� �� ����� �����
          for (int32_t j = vd[index_of_ekran_tmp].sign; j < (int32_t)MAX_COL_LCD; j++)
          {
            if (((working_ekran[i][j + 1]) == ' ') && (j < ((int32_t)vd[index_of_ekran_tmp].end - 1)))
            {
              working_ekran[i][j + 1] = working_ekran[i][j];
              working_ekran[i][j] = ' ';
              vd[index_of_ekran_tmp].sign++;
            }
            else break;
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
    if (vd[current_ekran.index_position].sign < 0)
      current_ekran.position_cursor_x = vd[current_ekran.index_position].begin;
    else
      current_ekran.position_cursor_x = vd[current_ekran.index_position].sign;
    last_position_cursor_x = vd[current_ekran.index_position].end;
    
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
//
/*****************************************************/
/*****************************************************/
