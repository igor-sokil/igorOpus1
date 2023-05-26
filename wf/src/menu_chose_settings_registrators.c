#include "header.h"

/*****************************************************/
//������� ����� ����������� ����� ����������
/*****************************************************/
void make_ekran_chose_registrators(void)
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_LIST_OF_REGISTRATORS][MAX_COL_LCD] = 
  {
    {
      " �����. ���-�   ",
      " ������.���-�   "
    },
    {
      " �����. �����. ",
      " ������.�����. "
    },
    {
      " Binary recorder",
      "Disturb recorder"
    },
    {
      " �����. ���-�   ",
      " ������.���-�   "
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
//������� ����� ����������� ����� ��������� ����������� ����������
/*****************************************************/
void make_ekran_settings_analog_registrators(void)
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_SETTINGS_OF_ANALOG_REGISTRATOR][MAX_COL_LCD] = 
  {
    {
      " ���������      ",
      " ��������       ",
      " ����������     "
    },
    {
      " �������        ",
      " ��������       ",
      " ���������     "
    },
    {
      " Inputs         ",
      " Operate delay  ",
      " Control        "
    },
    {
      " ���������      ",
      " �y�����        ",
      " ������       "
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
    if (index_of_ekran < MAX_ROW_FOR_SETTINGS_OF_ANALOG_REGISTRATOR)
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
//������� ����� ����������� �������� �����������
/*****************************************************/
void make_ekran_timeout_analog_registrator(void)
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_TIMEOUT_ANALOG_REGISTRATOR][MAX_COL_LCD] = 
  {
    {
      "  T ��������.   ",
      "  T ���������.  "
    },
    {
      "  T ���������.  ",
      "  T ��������.  "
    },
    {
      " PreFault Time  ",
      " PostFault Time "
    },
    {
      "  T ��������.   ",
      "  T ���������.  "
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
    if (index_of_ekran_tmp < MAX_ROW_FOR_TIMEOUT_ANALOG_REGISTRATOR)
    {
      if ((i & 0x1) == 0)
      {
        //� ��������� ����� ����� �������� ���������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_language][index_of_ekran_tmp][j];
        if (index_of_ekran_tmp == INDEX_ML_TMOPREFAULT)
        {
          vaga = 1000; //������������ ������� ���������� ��� �������� �������� ������� ��� �������� "��� ����������� ������"
          if (view == true) value = current_settings.prefault_number_periods*20; //� ����� value ������� �������� �������� "��� ����������� ������" ��� �������� �� � �������, � � ����������
          else value = edition_settings.prefault_number_periods*20;
        }
        else if (index_of_ekran_tmp == INDEX_ML_TMOPOSTFAULT)
        {
          vaga = 10000; //������������ ������� ���������� ��� �������� �������� ������� ��� �������� "��� ������������� ������"
          if (view == true) value = current_settings.postfault_number_periods*20; //� ����� value ������� �������� �������� "��� ������������� ������" ��� �������� �� � �������, � � ����������
          else value = edition_settings.postfault_number_periods*20;
        }
        first_symbol = 0; //�������, �� �� ����� �������� ������ �� ���������
      }
      else
      {
        //� ������� ����� ����� �������� �������� �������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++)
        {
          if (index_of_ekran_tmp == INDEX_ML_TMOPREFAULT)
          {
            if (
                ((j < COL_TMO_PREFAULT_BEGIN) ||  (j > COL_TMO_PREFAULT_END )) &&
                (j != (COL_TMO_PREFAULT_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_PREFAULT_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_PREFAULT_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_PREFAULT_COMMA, view, 0);
          }
          else if (index_of_ekran_tmp == INDEX_ML_TMOPOSTFAULT)
          {
            if (
                ((j < COL_TMO_POSTFAULT_BEGIN) ||  (j > COL_TMO_POSTFAULT_END )) &&
                (j != (COL_TMO_POSTFAULT_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_POSTFAULT_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_POSTFAULT_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_POSTFAULT_COMMA, view, 0);
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
    if (current_ekran.index_position == INDEX_ML_TMOPREFAULT) 
    {
      current_ekran.position_cursor_x = COL_TMO_PREFAULT_BEGIN;
      last_position_cursor_x = COL_TMO_PREFAULT_END;
    }
    else if (current_ekran.index_position == INDEX_ML_TMOPOSTFAULT) 
    {
      current_ekran.position_cursor_x = COL_TMO_POSTFAULT_BEGIN;
      last_position_cursor_x = COL_TMO_POSTFAULT_END;
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
//������� ����� ����������� �������� ����������� ���������� ���  ����������� ����������
/*****************************************************/
void make_ekran_control_ar()
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_CONTROL_AR][MAX_COL_LCD] = 
  {
    {
      " ��������� ����."
    },
    {
      " �������� ����."
    },
    {
      " Fault process  "
    },
    {
      " ��������� ����."
    }
  };
  int index_language = index_language_in_array(current_settings.language);

  int position_temp = current_ekran.index_position;
  int index_of_ekran;

  //�������� �� ��� �������� position_temp ������� ��� ����, �� �� ���� ������� �� ������������� ��� ����� (����� + ��������)
  index_of_ekran = ((position_temp<<1) >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;

  for (unsigned int i=0; i< MAX_ROW_LCD; i++)
  {
    unsigned int index_of_ekran_tmp = index_of_ekran >> 1;
    if (index_of_ekran_tmp < MAX_ROW_FOR_CONTROL_AR)
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
          
        if(current_ekran.edition == 0) temp_data = current_settings.control_ar;
        else temp_data = edition_settings.control_ar;
          
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
//������� ����� ����������� �������� Bin Rec
/*****************************************************/
void make_ekran_timeout_digital_registrator(void)
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_TIMEOUT_DIGITAL_REGISTRATOR][MAX_COL_LCD] = 
  {
    {
//      "  T ��������.   ",
      "  T ���������.  "
    },
    {
//      "  T ���������.  ",
      "  T ��������.  "
    },
    {
//      " PreFault Time  ",
      " PostFault Time "
    },
    {
//      "  T ��������.   ",
      "  T ���������.  "
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
    if (index_of_ekran_tmp < MAX_ROW_FOR_TIMEOUT_DIGITAL_REGISTRATOR)
    {
      if ((i & 0x1) == 0)
      {
        //� ��������� ����� ����� �������� ���������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_language][index_of_ekran_tmp][j];
        //.if (index_of_ekran_tmp == INDEX_ML_TMOPREFAULT)
        //.{
        //.  vaga = 1000; //������������ ������� ���������� ��� �������� �������� ������� ��� �������� "��� ����������� ������"
        //.  if (view == true) value = current_settings.prefault_number_periods*20; //� ����� value ������� �������� �������� "��� ����������� ������" ��� �������� �� � �������, � � ����������
        //.  else value = edition_settings.prefault_number_periods*20;
        //.}
        //.else if (index_of_ekran_tmp == INDEX_ML_TMOPOSTFAULT)
        if (index_of_ekran_tmp == INDEX_ML_TMO_ELONGATION)
        {
          vaga = 100000; //������������ ������� ���������� ��� �������� �������� ������� ��� �������� "��� ������������� ������"
          if (view == true) value = current_settings.timeout_prolongation_work_digital_registrator; //� ����� value ������� �������� �������� "��� ������������� ������" ��� �������� �� � �������, � � ����������
          else value = edition_settings.timeout_prolongation_work_digital_registrator;
        }
        first_symbol = 0; //�������, �� �� ����� �������� ������ �� ���������
      }
      else
      {
        //� ������� ����� ����� �������� �������� �������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++)
        {
          //.if (index_of_ekran_tmp == INDEX_ML_TMOPREFAULT)
          //.{
          //.  if (
          //.      ((j < COL_TMO_PREFAULT_BEGIN) ||  (j > COL_TMO_PREFAULT_END )) &&
          //.      (j != (COL_TMO_PREFAULT_END + 2))  
          //.     )working_ekran[i][j] = ' ';
          //.  else if (j == COL_TMO_PREFAULT_COMMA )working_ekran[i][j] = ',';
          //.  else if (j == (COL_TMO_PREFAULT_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
          //.  else
          //.    calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_PREFAULT_COMMA, view, 0);
          //.}
          //.else if (index_of_ekran_tmp == INDEX_ML_TMOPOSTFAULT)
          if (index_of_ekran_tmp == INDEX_ML_TMO_ELONGATION)
          {
            if (
                ((j < COL_TMO_ELONGATION_BEGIN) ||  (j > COL_TMO_ELONGATION_END )) &&
                (j != (COL_TMO_ELONGATION_END + 2))  
               )working_ekran[i][j] = ' ';
            else if (j == COL_TMO_ELONGATION_COMMA )working_ekran[i][j] = ',';
            else if (j == (COL_TMO_ELONGATION_END + 2)) working_ekran[i][j] = odynyci_vymirjuvannja[index_language][INDEX_SECOND];
            else
              calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TMO_ELONGATION_COMMA, view, 0);
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
    //.if (current_ekran.index_position == INDEX_ML_TMOPREFAULT) 
    //.{
    //.  current_ekran.position_cursor_x = COL_TMO_PREFAULT_BEGIN;
    //.  last_position_cursor_x = COL_TMO_PREFAULT_END;
    //.}
    //.else if (current_ekran.index_position == INDEX_ML_TMOPOSTFAULT) 
    if (current_ekran.index_position == INDEX_ML_TMO_ELONGATION) 
    {
      current_ekran.position_cursor_x = COL_TMO_ELONGATION_BEGIN;
      last_position_cursor_x = COL_TMO_ELONGATION_END;
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
//������� ����� ����������� ����� ��������� bin ����������
/*****************************************************/
void make_ekran_settings_digital_registrators(void)
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_SETTINGS_OF_DIGITAL_REGISTRATOR][MAX_COL_LCD] = 
  {
    {
      " ���������      ",
      " ��������       ",

    },
    {
      " �������        ",
      " ��������       ",

    },
    {
      " Inputs         ",
      " Operate delay  ",

    },
    {
      " ���������      ",
      " �y�����        ",

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
    if (index_of_ekran < MAX_ROW_FOR_SETTINGS_OF_DIGITAL_REGISTRATOR)
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
//
/*****************************************************/
/*****************************************************/
