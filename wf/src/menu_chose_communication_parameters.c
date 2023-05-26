#include "header.h"

/*****************************************************/
//������� ����� ����������� ��������� ������������ ����������
/*****************************************************/
void make_ekran_chose_communication_parameters(void)
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_CHOSE_COMMUNICATION_PARAMETERS][MAX_COL_LCD] = 
  {
    {
      " ��� ������     ",
      " ����� ������   ",
      " �����.RS-485   "
    },
    {
      " ��'� ������   ",
      " ������ ������ ",
      " ������.RS-485  "
    },
    {
      " Bay name       ",
      " Bay Address    ",
      " RS-485 Settings"
    },
    {
      " ��� ������     ",
      " ����� ������   ",
      " �����.RS-485   "
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
    if (index_of_ekran < MAX_ROW_FOR_CHOSE_COMMUNICATION_PARAMETERS)
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
//������� ����� ����������� ���� ������
/*****************************************************/
void make_ekran_name_of_cell(void)
{
  //������� ����� ���� ������  ��� ������� ��� ��� ���� ���� ��������
  index_language_in_array(current_settings.language);
  
  unsigned int position_temp = current_ekran.index_position;
  unsigned int index_of_ekran;
  
  index_of_ekran = (position_temp >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;
  
  //�������  ����� � ������� �����
  for (unsigned int i=0; i< MAX_ROW_LCD; i++)
  {
    //������� ����� ����� ���������, �� �� ����� ���������� � ������� �����������
    if (index_of_ekran < MAX_ROW_FOR_VIEW_NAME_OF_CELL)
      for (unsigned int j = 0; j<MAX_COL_LCD; j++)
      {
        if (((index_of_ekran<<POWER_MAX_COL_LCD) + j) < MAX_CHAR_IN_NAME_OF_CELL) working_ekran[i][j] = current_settings.name_of_cell[(index_of_ekran<<POWER_MAX_COL_LCD) + j];
        else working_ekran[i][j] = ' ';
      }
    else
      for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = ' ';

    index_of_ekran++;
  }

  //������ �� ���������� ������������ �� ������ �������
  current_ekran.position_cursor_x = 0;
  //³���������� ������ �� ��������
  current_ekran.position_cursor_y = position_temp & (MAX_ROW_LCD - 1);
  //������  �� �������
  current_ekran.cursor_on = 0;
  //������ �� ����
  current_ekran.cursor_blinking_on = 0;
  //�������� ������� ���� �����
  current_ekran.current_action = ACTION_WITH_CARRENT_EKRANE_FULL_UPDATE;
}
/*****************************************************/

/*****************************************************/
//������� ����� ����������� ������ ��� ���������� � ������ �����
/*****************************************************/
void make_ekran_address()
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_ADDRESS][MAX_COL_LCD] = 
  {
    "     �����      ",
    "     ������     ",
    "    Address     ",
    "     �����      "
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
    if (index_of_ekran_tmp < MAX_ROW_FOR_ADDRESS)
    {
      if ((i & 0x1) == 0)
      {
        //� ��������� ����� ����� �������� ���������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_language][index_of_ekran_tmp][j];
        vaga = 100; //������������ ������� ���������� ��� ������
        if (view == true) value = current_settings.address; //� ����� value ������� �������� ������
        else value = edition_settings.address;
        first_symbol = 0; //�������, �� �� ����� �������� ������ �� ���������
      }
      else
      {
        //� ������� ����� ����� �������� �������� �������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++)
        {
          if ((j < COL_ADDRESS_BEGIN) ||  (j > COL_ADDRESS_END ))working_ekran[i][j] = ' ';
          else
            calc_int_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, view);
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
    current_ekran.position_cursor_x = COL_ADDRESS_BEGIN;
    int last_position_cursor_x = COL_ADDRESS_END;

    //ϳ������� ������ �� ������� �������
    while (((working_ekran[current_ekran.position_cursor_y][current_ekran.position_cursor_x + 1]) == ' ') && 
           (current_ekran.position_cursor_x < (last_position_cursor_x -1))) current_ekran.position_cursor_x++;

    //������ ������� ���, ��� �� ��� ����� ������
    if (((working_ekran[current_ekran.position_cursor_y][current_ekran.position_cursor_x]) != ' ') && 
        (current_ekran.position_cursor_x > 0)) current_ekran.position_cursor_x--;
  }
  //������ �������, ���� �� � ����� �����������
  if (current_ekran.edition == 0) current_ekran.cursor_on = 0;
  else current_ekran.cursor_on = 1;
  
  //������ �� ����
  if(current_ekran.edition == 0)current_ekran.cursor_blinking_on = 0;
  else current_ekran.cursor_blinking_on = 1;
  //�������� ������� ���� �����
  current_ekran.current_action = ACTION_WITH_CARRENT_EKRANE_FULL_UPDATE;
}
/*****************************************************/

/*****************************************************/
//������� ����� ����������� ��������� ������������ ����������
/*****************************************************/
void make_ekran_chose_setting_rs485(void)
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_CHOSE_SETTING_RS485][MAX_COL_LCD] = 
  {
    {
      " �������� ������",
      " �����.�������� ",
      " �����.����-��� ",
      " ����� �����   "
    },
    {
      " �������� ���. ",
      " �����.������� ",
      "ʳ���.����-��  ",
      "ʳ���� ���������"
    },
    {
      " Baud rate      ",
      " Parity         ",
      " Stop Bits      ",
      "End of Reception"
    },
    {
      " �������� ������",
      " �����.�������� ",
      " �����.����-��� ",
      " ����� �����   "
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
    if (index_of_ekran < MAX_ROW_FOR_CHOSE_SETTING_RS485)
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
//������� ����� ����������� ������������� ��� ����������
/*****************************************************/
void make_ekran_speed_interface()
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_VIEW_SPEED_INTERFACE][MAX_COL_LCD] = 
  {
    " �������� ������",
    " �������� ���. ",
    "   Baud rate    ",
    " �������� ������"
  };
  int index_language = index_language_in_array(current_settings.language);
  
  unsigned int position_temp = current_ekran.index_position;
  unsigned int index_of_ekran;
  
  //�������� �� ��� �������� position_temp ������� ��� ����, �� �� ���� ������� �� ������������� ��� ����� (����� + ��������)
  index_of_ekran = ((position_temp<<1) >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;

  
  for (unsigned int i=0; i< MAX_ROW_LCD; i++)
  {
    unsigned int index_of_ekran_tmp = index_of_ekran >> 1;
    if (index_of_ekran_tmp < MAX_ROW_FOR_VIEW_SPEED_INTERFACE)
    {
      if ((i & 0x1) == 0)
      {
        //� ��������� ����� ����� �������� ���������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_language][index_of_ekran_tmp][j];
      }
      else
      {
        //� ������� ����� ����� �������� �������� �������
        static const unsigned char information[MAX_NUMBER_SPEEDS_INTERFACE][MAX_COL_LCD] = 
        {
          "      9600      ",
          "     14400      ",
          "     19200      ",
          "     28800      ",
          "     38400      ",
          "     57600      ",
          "     115200     "
        };
        static const unsigned int cursor_x[MAX_NUMBER_SPEEDS_INTERFACE] = {5, 4, 4, 4, 4, 4, 4};

        unsigned int temp_data;
          
        if(current_ekran.edition == 0) temp_data = current_settings.speed_RS485;
        else temp_data = edition_settings.speed_RS485;
          
        if (temp_data < MAX_NUMBER_SPEEDS_INTERFACE)
        {
          for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = information[temp_data][j];
          current_ekran.position_cursor_x = cursor_x[temp_data];
        }
        else
        {
          static const unsigned char information_error[MAX_NAMBER_LANGUAGE][MAX_COL_LCD] = 
          {
            "     ������     ",
            "    �������     ",
            "     Error      ",
            "     ������     "
          };
          static const unsigned int cursor_x_error[MAX_NAMBER_LANGUAGE] = {4, 3, 4, 4};

          for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = information_error[index_language][j];
          current_ekran.position_cursor_x = cursor_x_error[index_language];
        }
      }
    }
    else
      for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = ' ';

    index_of_ekran++;
  }

  //³���������� ������ �� �������� � ������ ������ �� ���� � ��� �� ��������� ������
  current_ekran.position_cursor_y = ((position_temp<<1) + 1) & (MAX_ROW_LCD - 1);

  //������ �������, ���� �� � ����� �����������
  if (current_ekran.edition == 0) current_ekran.cursor_on = 0;
  else current_ekran.cursor_on = 1;

  //������ �� ����, ���� �� � ����� �����������
  if(current_ekran.edition == 0)current_ekran.cursor_blinking_on = 0;
  else current_ekran.cursor_blinking_on = 1;

  //�������� ������� ���� �����
  current_ekran.current_action = ACTION_WITH_CARRENT_EKRANE_FULL_UPDATE;
}
/*****************************************************/

/*****************************************************/
//������� ����� ����������� �������� ������� ��� ����������
/*****************************************************/
void make_ekran_pare_interface()
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_VIEW_PARE_INTERFACE][MAX_COL_LCD] = 
  {
    " �����.�������� ",
    " �����.������� ",
    "     Parity     ",
    " �����.�������� "
  };
  int index_language = index_language_in_array(current_settings.language);
  
  unsigned int position_temp = current_ekran.index_position;
  unsigned int index_of_ekran;
  
  //�������� �� ��� �������� position_temp ������� ��� ����, �� �� ���� ������� �� ������������� ��� ����� (����� + ��������)
  index_of_ekran = ((position_temp<<1) >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;

  
  for (unsigned int i=0; i< MAX_ROW_LCD; i++)
  {
    unsigned int index_of_ekran_tmp = index_of_ekran >> 1;
    if (index_of_ekran_tmp < MAX_ROW_FOR_VIEW_PARE_INTERFACE)
    {
      if ((i & 0x1) == 0)
      {
        //� ��������� ����� ����� �������� ���������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_language][index_of_ekran_tmp][j];
      }
      else
      {
        static const unsigned char information[MAX_NAMBER_LANGUAGE][MAX_NUMBER_PARE_INTERFACE + 1][MAX_COL_LCD] = 
        {
          {"      ���       ", "     �����.     ", "      ���.      ", "     ������     "},
          {"      ����      ", "    ������.     ", "      ����.     ", "    �������     "},
          {"      None      ", "      Odd       ", "      Even      ", "     Error      "},
          {"      ���       ", "     �����.     ", "      ���.      ", "     ������     "}
        };
        static const unsigned int cursor_x[MAX_NAMBER_LANGUAGE][MAX_NUMBER_PARE_INTERFACE + 1] = 
        {
          {5, 4, 5, 4},
          {5, 3, 5, 3},
          {5, 5, 5, 4},
          {5, 4, 5, 4}
        };

        unsigned int temp_data;
          
        if(current_ekran.edition == 0) temp_data = current_settings.pare_bit_RS485;
        else temp_data = edition_settings.pare_bit_RS485;

        if (temp_data < MAX_NUMBER_PARE_INTERFACE)
        {
          for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = information[index_language][temp_data][j];
          current_ekran.position_cursor_x = cursor_x[index_language][temp_data];
        }
        else
        {
          for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = information[index_language][MAX_NUMBER_PARE_INTERFACE][j];
          current_ekran.position_cursor_x = cursor_x[index_language][MAX_NUMBER_PARE_INTERFACE];
        }
      }
    }
    else
      for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = ' ';

    index_of_ekran++;
  }

  //³���������� ������ �� �������� � ������ ������ �� ���� � ��� �� ��������� ������
  current_ekran.position_cursor_y = ((position_temp<<1) + 1) & (MAX_ROW_LCD - 1);

  //������ �������, ���� �� � ����� �����������
  if (current_ekran.edition == 0) current_ekran.cursor_on = 0;
  else current_ekran.cursor_on = 1;

  //������ �� ����, ���� �� � ����� �����������
  if(current_ekran.edition == 0)current_ekran.cursor_blinking_on = 0;
  else current_ekran.cursor_blinking_on = 1;

  //�������� ������� ���� �����
  current_ekran.current_action = ACTION_WITH_CARRENT_EKRANE_FULL_UPDATE;
}
/*****************************************************/

/*****************************************************/
//������� ����� ����������� stop-bit ��� ����������
/*****************************************************/
void make_ekran_stopbits_interface()
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_VIEW_STOP_BITS_INTERFACE][MAX_COL_LCD] = 
  {
    " �����.����-��� ",
    "ʳ���.����-��  ",
    "   Stop Bits    ",
    " �����.����-��� "
  };
  int index_language = index_language_in_array(current_settings.language);
  
  unsigned int position_temp = current_ekran.index_position;
  unsigned int index_of_ekran;
  
  //�������� �� ��� �������� position_temp ������� ��� ����, �� �� ���� ������� �� ������������� ��� ����� (����� + ��������)
  index_of_ekran = ((position_temp<<1) >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;

  
  for (unsigned int i=0; i< MAX_ROW_LCD; i++)
  {
    unsigned int index_of_ekran_tmp = index_of_ekran >> 1;
    if (index_of_ekran_tmp < MAX_ROW_FOR_VIEW_STOP_BITS_INTERFACE)
    {
      if ((i & 0x1) == 0)
      {
        //� ��������� ����� ����� �������� ���������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_language][index_of_ekran_tmp][j];
      }
      else
      {
        static const unsigned char information[MAX_NAMBER_LANGUAGE][MAX_NUMBER_STOP_BITS_INTERFACE + 1][MAX_COL_LCD] = 
        {
          {"      ����      ", "      ���       ", "     ������     "},
          {"      ����      ", "      ���       ", "    �������     "},
          {"      One       ", "      Two       ", "     Error      "},
          {"      ����      ", "      ���       ", "     ������     "}
        };
        static const unsigned int cursor_x[MAX_NAMBER_LANGUAGE][MAX_NUMBER_STOP_BITS_INTERFACE + 1] = 
        {
          {5, 5, 4},
          {5, 5, 3},
          {5, 5, 4},
          {5, 5, 4}
        };

        unsigned int temp_data;
          
        if(current_ekran.edition == 0) temp_data = current_settings.number_stop_bit_RS485;
        else temp_data = edition_settings.number_stop_bit_RS485;
          
        if (temp_data < MAX_NUMBER_STOP_BITS_INTERFACE)
        {
          for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = information[index_language][temp_data][j];
          current_ekran.position_cursor_x = cursor_x[index_language][temp_data];
        }
        else
        {
          for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = information[index_language][MAX_NUMBER_STOP_BITS_INTERFACE][j];
          current_ekran.position_cursor_x = cursor_x[index_language][MAX_NUMBER_STOP_BITS_INTERFACE];
        }
      }
    }
    else
      for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = ' ';

    index_of_ekran++;
  }

  //³���������� ������ �� �������� � ������ ������ �� ���� � ��� �� ��������� ������
  current_ekran.position_cursor_y = ((position_temp<<1) + 1) & (MAX_ROW_LCD - 1);

  //������ �������, ���� �� � ����� �����������
  if (current_ekran.edition == 0) current_ekran.cursor_on = 0;
  else current_ekran.cursor_on = 1;

  //������ �� ����, ���� �� � ����� �����������
  if(current_ekran.edition == 0)current_ekran.cursor_blinking_on = 0;
  else current_ekran.cursor_blinking_on = 1;

  //�������� ������� ���� �����
  current_ekran.current_action = ACTION_WITH_CARRENT_EKRANE_FULL_UPDATE;
}
/*****************************************************/

/*****************************************************/
//������� ����� ����������� time-out ���������� ������� ��� ����������
/*****************************************************/
void make_ekran_timeout_interface()
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_VIEW_TIMEOUT_INTERFACE][MAX_COL_LCD] = 
  {
    "  ����� �����  ",
    "ʳ���� ���������",
    "End of Reception",
    "  ����� �����  "
  };
  static const unsigned char symbols[MAX_NAMBER_LANGUAGE][5] = {"����.", "����.", "symb.", "����."};
  int index_language = index_language_in_array(current_settings.language);
  
  unsigned int position_temp = current_ekran.index_position;
  unsigned int index_of_ekran;
  unsigned int vaga, value, first_symbol;
  
  //�������� �� ��� �������� position_temp ������� ��� ����, �� �� ���� ������� �� ������������� ��� ����� (����� + ��������)
  index_of_ekran = ((position_temp<<1) >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;

  
  for (unsigned int i=0; i< MAX_ROW_LCD; i++)
  {
    //������� ����� ����� ���������, �� �� ����� ���������� � ������� �����������
    unsigned int index_of_ekran_tmp = index_of_ekran >> 1;
    unsigned int view = ((current_ekran.edition == 0) || (position_temp != index_of_ekran_tmp));
    if (index_of_ekran_tmp < MAX_ROW_FOR_VIEW_TIMEOUT_INTERFACE)
    {
      if ((i & 0x1) == 0)
      {
        //� ��������� ����� ����� �������� ���������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_language][index_of_ekran_tmp][j];

        vaga = 100; //������������ ������� ���������� ��� �������� �������� �������
        if (view == true) value = current_settings.time_out_1_RS485; //� ����� value ������� �������� time-out ���������� ������� 
        else value = edition_settings.time_out_1_RS485;
        first_symbol = 0; //�������, �� �� ����� �������� ������ �� ���������
      }
      else
      {
        //� ������� ����� ����� �������� �������� �������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++)
        {
          if (
              ((j < COL_TIMEOUT_INTERFACE_BEGIN) ||  (j > COL_TIMEOUT_INTERFACE_END )) &&
              (
               !((j >= (COL_TIMEOUT_INTERFACE_END + 2)) && (j <= (COL_TIMEOUT_INTERFACE_END + 6)))
              )    
             )working_ekran[i][j] = ' ';
          else if (j == COL_TIMEOUT_INTERFACE_COMMA )working_ekran[i][j] = ',';
          else if ((j >= (COL_TIMEOUT_INTERFACE_END + 2)) && (j <= (COL_TIMEOUT_INTERFACE_END + 6)))
            working_ekran[i][j] = symbols[index_language][j - (COL_TIMEOUT_INTERFACE_END + 2)];
          else
            calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, COL_TIMEOUT_INTERFACE_COMMA, view, 0);
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
    current_ekran.position_cursor_x = COL_TIMEOUT_INTERFACE_BEGIN;
    int last_position_cursor_x = COL_TIMEOUT_INTERFACE_END;
    
    //ϳ������� ������ �� ������� �������
    while (((working_ekran[current_ekran.position_cursor_y][current_ekran.position_cursor_x + 1]) == ' ') && 
           (current_ekran.position_cursor_x < (last_position_cursor_x -1))) current_ekran.position_cursor_x++;

    //������ ������� ���, ��� �� ��� ����� ������
    if (((working_ekran[current_ekran.position_cursor_y][current_ekran.position_cursor_x]) != ' ') && 
        (current_ekran.position_cursor_x > 0)) current_ekran.position_cursor_x--;
  }
  //������ �������, ���� �� � ����� �����������
  if (current_ekran.edition == 0) current_ekran.cursor_on = 0;
  else current_ekran.cursor_on = 1;

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
