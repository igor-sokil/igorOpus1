#include "header.h"

/*****************************************************/
//����������� � ����� � �������� � ����� ��� ����������� �� ����� ���������
/*****************************************************/
void convert_and_insert_char_for_measurement(unsigned int start_number_digit_after_point, unsigned int temp_meas, unsigned int koef_mul, unsigned int koef_div, unsigned char *name_string, unsigned int start_position)
{
  unsigned long long temp_value_long  = ((unsigned long long)temp_meas)*((unsigned long long)koef_mul)/((unsigned long long)koef_div);
  unsigned int temp_value = (unsigned int)temp_value_long;
  unsigned int number_digit_after_point = start_number_digit_after_point, error = 0, overflow = 0;
  
  //�������, �� ����� �� �� �� �������� � �� ����� ʲ�� � �� ����� ����
//  *(name_string + start_position + 7) = ' ';

  overflow = ((temp_value_long & 0xffffffff00000000ull) != 0);
  while (
         (
          (overflow != 0) ||
          (temp_value > 999999)
         )
         &&  
         (error == 0)  
        )   
  {
    //�� �� ���������� � �������� � ����� ���� � ����

    //³������� ������� ������� �����
    if (overflow != 0)
    {
      temp_value_long /= 10ull;
      overflow = ((temp_value_long & 0xffffffff00000000ull) != 0);
      if (overflow == 0)
        temp_value = temp_value_long;
    }
    else
      temp_value /=10;
    
    //������� ������� ��������� ���� �, ��� �������, ���������� �� ���� �����
    switch (number_digit_after_point)
    {
    case 1:
    case 2:
      {
        //���������� � ������� 1.5 �� 2.4 ��� � ������� 2.4 �� 3.3
        number_digit_after_point++;
        break;
      }
    case 3:
      {
        //���������� � ������� 3.3 �� 1.5 �� ������������� �������� ' '->'k' ��� 'k'->'M'
        number_digit_after_point = 1;
        if ((*(name_string + start_position + 7)) == ' ') 
        {
          if (current_settings.language == LANGUAGE_EN)
            *(name_string + start_position + 7) = 'k';
          else
            *(name_string + start_position + 7) = '�';
        }
        else if (
                 ((*(name_string + start_position + 7)) == '�') ||
                 ((*(name_string + start_position + 7)) == 'k')  
                )
        {
          *(name_string + start_position + 7) = '�';
        }
        else if ((*(name_string + start_position + 7)) == '�')
        {
          if (current_settings.language == LANGUAGE_EN)
            *(name_string + start_position + 7) = 'G';
          else
            *(name_string + start_position + 7) = '�';
        }
        else
        {
          /*
          ���������� ���� � �������� ����� ����� � ���� ��������:
          1) ������� � ����� ���� �� ���� �����, �� ��� ����� ������ �� �� ���� ����� � ����
          2) � 7-��� ������� ���� ����������� ������ - � �� � ��������� ��������, ��� � ����� ����� �� ���� ��������
          
          � ������ ��� ����� �������� ����������� ***.*** � ������ � 7-��� ������� ,���� ������ �� ���� ��������
          */
          error = 2;
        }
        break;
      }
    default:
      {
        /*
        ���������� ���� �������� ����� � ��  ���� �����
        
        � ������ ��� ����� �������� ����������� XXXXXXX
        */
        error = 1;
      }
    }
  }
  
  if (error == 0)
  {
    //��� �������� ����� �� ���������� ������� � �������� ����� ������� �� ���� �����������
    unsigned int first_symbol = 0, value, position = start_position; /*������� � ��� ��������� ��������� �������� - ���������� �����*/
    
    /*
    X?????
    */
    if (temp_value > 99999)
    {
      value = temp_value / 100000; 
      temp_value %= 100000;
      *(name_string + position) = value + 0x30;
      first_symbol = 1;
    }
    else
    {
      if (number_digit_after_point == 1)
      {
        *(name_string + position) = '0';
        first_symbol = 1;
      }
      else *(name_string + position) = ' ';
    }
    position++;

    if (number_digit_after_point == 1)
    {
      //��������� "����"
      *(name_string + position) = '.';
      position++;
    }

    /*
    *X????
    */
    if (temp_value > 9999)
    {
      value = temp_value / 10000; 
      temp_value %= 10000;
      *(name_string + position) = value + 0x30;
      first_symbol = 1;
    }
    else
    {
      if (
          (number_digit_after_point == 2) ||
          (first_symbol             != 0)  
         )   
      {
        *(name_string + position) = '0';
        first_symbol = 1;
      }
      else *(name_string + position) = ' ';
    }
    position++;

    if (number_digit_after_point == 2)
    {
      //��������� "����"
      *(name_string + position) = '.';
      position++;
    }
    
    /*
    **X???
    */
    value = temp_value / 1000; 
    temp_value %= 1000;
    *(name_string + position) = value + 0x30;
    position++;

    if (number_digit_after_point == 3)
    {
      //��������� "����"
      *(name_string + position) = '.';
      position++;
    }
    
    //� ����� ���� ����� position �� ����'������ ���� ����� (start_position + 4)
    if (position == (start_position + 4))
    {
      /*
      ***X??
      */
      value = temp_value / 100; 
      temp_value %= 100;
      *(name_string + (position++)) = value + 0x30;
  
      /*
      ****X?
      */
      value = temp_value / 10; 
      temp_value %= 10;
      *(name_string + (position++)) = value + 0x30;
  
      /*
      *****X
      */
      *(name_string + (position++)) = temp_value + 0x30;
    }
    else
    {
      //�������, ��� � ����� �� ���� �������� ������� �� ������� ������
      for (unsigned int i = 0; i < 7; i++) *(name_string + start_position + i) = '!';
      *(name_string + start_position + 7) = ' ';
    }
  }
  else if (error == 1)
  {
    //������� ������� ��� ����� ������������ �������
    for (unsigned int i = 0; i < 7; i++) *(name_string + start_position + i) = 'X';
    *(name_string + start_position + 7) = ' ';
  }
  else if (error == 2)
  {
    //������� ������� ��� ������� �� ���� �����
    for (unsigned int i = 0; i < 7; i++) *(name_string + start_position + i) = '*';
    *(name_string + start_position + 3) = '.';
  }
  else
  {
    //����������� �������
    for (unsigned int i = 0; i < 7; i++) *(name_string + start_position + i) = '?';
    *(name_string + start_position + 7) = ' ';
  }
}
/*****************************************************/

/*****************************************************/
//����������� � ����� � �������� � ����� ��� ����������� �� ����� �������
/*****************************************************/
void convert_and_insert_char_for_frequency(int temp_meas_1000, unsigned char *name_string)
{
#define FIRST_POSITION_OF_NUMBER  5

  int temp_value = temp_meas_1000;

  int index_language = index_language_in_array(current_settings.language);
  if ((temp_value >= (MIN_FREQUENCY*1000)) && (temp_value <= ((MAX_FREQUENCY + 1)*1000)))
  {
    static const unsigned char Hz[MAX_NAMBER_LANGUAGE][2] = {"��", "��", "Hz", "��"};
    for (unsigned int i = 0; i < 2; i++)  
    {
       *(name_string + FIRST_POSITION_OF_NUMBER + 7 + i) = Hz[index_language][i];
    }

    unsigned int position = FIRST_POSITION_OF_NUMBER; /*������� � ��� ��������� ��������� �������� - ���������� �����*/
    int value;
    
    /*
    X????
    */
    if (temp_value > 9999)
    {
      value = temp_value / 10000; 
      temp_value %= 10000;
      *(name_string + position) = value + 0x30;
    }
    else
    {
      *(name_string + position) = ' ';
    }
    position++;

    /*
    *X???
    */
    value = temp_value / 1000; 
    temp_value %= 1000;
    *(name_string + position) = value + 0x30;
    position++;
    {
      //��������� "����"
      *(name_string + position) = '.';
      position++;
    }
    
    //� ����� ���� ����� position �� ����'������ ���� ����� (FIRST_POSITION_OF_NUMBER + 3)
    if (position == (FIRST_POSITION_OF_NUMBER + 3))
    {
      /*
      **X??
      */
      value = temp_value / 100; 
      temp_value %= 100;
      *(name_string + (position++)) = value + 0x30;
  
      /*
      ***X?
      */
      value = temp_value / 10; 
      temp_value %= 10;
      *(name_string + (position++)) = value + 0x30;
  
      /*
      ****X
      */
      *(name_string + (position++)) = temp_value + 0x30;
    }
    else
    {
      //�������, ��� � ����� �� ���� �������� ������� �� ������� ������
      for (unsigned int i = 0; i < 6; i++) *(name_string + FIRST_POSITION_OF_NUMBER + i) = '!';
    }
  }
  else if (temp_meas_1000 < 0)
  {
    static const unsigned char undefined[MAX_NAMBER_LANGUAGE][MAX_COL_LCD - FIRST_POSITION_OF_NUMBER] =
    {
      "�������.   ",
      "��������.  ",
      "Undef.     ",
      "�������.   "  
    };
    
    for (int i = 0; i < (MAX_COL_LCD - FIRST_POSITION_OF_NUMBER); i++) *(name_string + FIRST_POSITION_OF_NUMBER + i) = undefined[index_language][i];
  }
  else
  {
    //�������, ��� � ����� �� ���� �������� ������� �� ������� �������
    for (unsigned int i = 0; i < 6; i++) *(name_string + FIRST_POSITION_OF_NUMBER + i) = '?';
  }
#undef FIRST_POSITION_OF_NUMBER
}
/*****************************************************/

/*****************************************************/
//������� ����� ����������� ������ ���������
/*****************************************************/
void make_ekran_measurement(void)
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_MEASURMENT][MAX_COL_LCD] = 
  {
    {
     " ����           ",
     " ����������     ",
     " �������        ",
     " ����           ",
     " ��������       ",
     " �������������  "
    },
    {
     " ������         ",
     " �������        ",
     " �������        ",
     " ����           ",
     " ���������     ",
     " �����          "
    },
    {
     " Currents       ",
     " Voltages       ",
     " Frequencies    ",
     " Angles         ",
     " Power          ",
     " Resistances    "
    },
    {
     " ����           ",
     " ����������     ",
     " �������        ",
     " ����           ",
     " ��������       ",
     " �������������  "
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
    if (index_of_ekran < MAX_ROW_FOR_MEASURMENT)
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
//������� ����� ����������� ������
/*****************************************************/
void make_ekran_current(unsigned int pervynna_vtorynna)
{
  
  unsigned char name_string[MAX_ROW_FOR_MEASURMENT_CURRENT][MAX_COL_LCD] = 
  {
    " Imnl =         ",
    " Ibpl =         ",
    " I3mnl=         ",//3rd order harmonic
    " I3bpl=         "//3rd order harmonic
  };
  unsigned int index_array[MAX_ROW_FOR_MEASURMENT_CURRENT] = 
  {
    IM_Imn,
    IM_Ibp,
    IM_3Imn,
    IM_3Ibp
  };
  
  //������� ���������� �� ������ ��� �����������
  semaphore_measure_values_low1 = 1;
  for (unsigned int i = 0; i < MAX_ROW_FOR_MEASURMENT_CURRENT; i++ ) 
  {
    unsigned int index_to_copy = index_array[i];
    measurement_low[index_to_copy] = measurement_middle[index_to_copy];
  }
  semaphore_measure_values_low1 = 0;

  int index_language = index_language_in_array(current_settings.language);
  for (unsigned int i = 0; i < MAX_ROW_FOR_MEASURMENT_CURRENT; i++)
  {
    name_string[i][MAX_COL_LCD - 1] = odynyci_vymirjuvannja[index_language][INDEX_A];
  }
  
  int position_temp = current_ekran.index_position;
  int index_of_ekran;
  index_of_ekran = (position_temp >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;
  
  //�������  ����� � ������� �����
  for (unsigned int i=0; i< MAX_ROW_LCD; i++)
  {
    //������� ����� ����� ���������, �� �� ����� ���������� � ������� �����������
    if (index_of_ekran < MAX_ROW_FOR_MEASURMENT_CURRENT)
    {
      /********************************/
      //������� ���������� ��������  
      unsigned int index = index_array[index_of_ekran];
      if (index != 255)
      {
        unsigned int start_number_digit_after_point = 3;

        unsigned int koef_mul = 1;
        if (pervynna_vtorynna != 0)
        {
          koef_mul = current_settings.Tmn;
        }
        convert_and_insert_char_for_measurement(start_number_digit_after_point, measurement_low[index], koef_mul, 1, name_string[index_of_ekran], 7);
      }
      /********************************/

      for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_of_ekran][j];
    }
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
//������� ����� ����������� ������ ������ 
/*****************************************************/
void make_ekran_voltage_line(unsigned int pervynna_vtorynna)
{
  unsigned char name_string[MAX_ROW_FOR_MEASURMENT_VOLTAGE_LINE][MAX_COL_LCD] = 
  {
    " Umnl =         ",
    " Ubpl =         "
  };
  unsigned int index_array[MAX_ROW_FOR_MEASURMENT_VOLTAGE_LINE] = {IM_Umn, IM_Ubp};
  unsigned int row = 2;
  
  //������� ���������� �� ������ ��� �����������
  semaphore_measure_values_low1 = 1;
  for (unsigned int i = 0; i < row; i++ ) 
  {
    unsigned int index_to_copy = index_array[i];
    measurement_low[index_to_copy] = measurement_middle[index_to_copy];
  }
  semaphore_measure_values_low1 = 0;

  int index_language = index_language_in_array(current_settings.language);
  for (unsigned int i = 0; i < row; i++)
  {
    name_string[i][MAX_COL_LCD - 1] = odynyci_vymirjuvannja[index_language][INDEX_V];
  }
  
  unsigned int position_temp = current_ekran.index_position;
  unsigned int index_of_ekran;
  
  index_of_ekran = (position_temp >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;
  
  //�������  ����� � ������� �����
  for (unsigned int i=0; i< MAX_ROW_LCD; i++)
  {
    //������� ����� ����� ���������, �� �� ����� ���������� � ������� �����������
    if (index_of_ekran < row)
    {
      /********************************/
      //������� ���������� ��������  
      unsigned int start_number_digit_after_point = 3;

      unsigned int index = index_array[index_of_ekran];
      if (index != 255)
      {
        if (pervynna_vtorynna == 0) convert_and_insert_char_for_measurement(start_number_digit_after_point, measurement_low[index], 1, 1, name_string[index_of_ekran], 7);
        else
        {
          //˳��� �������
          convert_and_insert_char_for_measurement(start_number_digit_after_point, measurement_low[index], current_settings.TVoltage, 1, name_string[index_of_ekran], 7);
        }
      }
      /********************************/

      for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_of_ekran][j];
    }
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
//������� ����� ����������� ������
/*****************************************************/
void make_ekran_frequency(void)
{
  unsigned char name_string[MAX_ROW_FOR_MEASURMENT_FREQUENCY][MAX_COL_LCD] = 
  {
    " f =            "
  };
  semaphore_measure_values_low1 = 1;
  int measurement_fequency = (int)(frequency_middle*1000);
  semaphore_measure_values_low1 = 0;
  
  unsigned int position_temp = current_ekran.index_position;
  unsigned int index_of_ekran;
  
  index_of_ekran = (position_temp >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;
  
  //�������  ����� � ������� �����
  for (unsigned int i=0; i< MAX_ROW_LCD; i++)
  {
    //������� ����� ����� ���������, �� �� ����� ���������� � ������� �����������
    if (index_of_ekran < MAX_ROW_FOR_MEASURMENT_FREQUENCY)
    {
      /********************************/
      //������� ���������� ��������
      if (measurement_fequency < 0)
      {
        if (measurement_fequency == (-2*1000))
        {
          /*������� ����� ������ ����������� ���������� MIN_FREQUENCY*/
          name_string[index_of_ekran][3] = '<';
          measurement_fequency = MIN_FREQUENCY*1000;
        }
        if (measurement_fequency == (-3*1000))
        {
          /*������� ���� ������ ����������� ���������� MAX_FREQUENCY*/
          name_string[index_of_ekran][3] = '>';
          measurement_fequency = MAX_FREQUENCY*1000;
        }
      }
      
      convert_and_insert_char_for_frequency(measurement_fequency, name_string[index_of_ekran]);
      /********************************/

      for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_of_ekran][j];
    }
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
//������� ����� ����������� ����
/*****************************************************/
void make_ekran_angle(void)
{
  int index_language = index_language_in_array(current_settings.language);
  if (base_index_for_angle < 0)
  {
    //��������� ��������� ����
    static const unsigned char information[MAX_NAMBER_LANGUAGE][2][MAX_COL_LCD] = 
    {
      {
        "  ����������    ",
        " ���������� ����"
      },
      {
        "   ���������    ",
        " ��������� ���� "
      },
      {
        "   Impossibly   ",
        "to define angles"
      },
      {
        "  ����������    ",
        " ���������� ����"
      }
    };

    for(int index_1 = 0; index_1 < MAX_ROW_LCD; index_1++)
    {
      for(int index_2 = 0; index_2 < MAX_COL_LCD; index_2++)
        working_ekran[index_1][index_2] = (index_1 < 2) ? information[index_language][index_1][index_2] : ' ';
    }

    //³���������� ������ �� ��������
    current_ekran.position_cursor_y = 0;
    //������ �� �������
    current_ekran.cursor_on = 0;
  }
  else
  {
//.    unsigned char name_string[MAX_ROW_FOR_MEASURMENT_ANGLE][MAX_COL_LCD] = 
//.    {
//.      " Umn -          ",
//.      " Ubp -          ",
//.      " Imn -          ",
//.      " Ibp -          "
//.    };
    unsigned char name_string[MAX_ROW_FOR_MEASURMENT_ANGLE][MAX_COL_LCD] = 
    {
      " Imnl - Umnl    ",
      " Ibpl - Ubpl    "
    };
#define SIZE_UNDEF      6
    static const unsigned char undefined[MAX_NAMBER_LANGUAGE][SIZE_UNDEF] =
    {
      "�����.",
      "���.  ",
      "Undef.",
      "�����."  
    };
    static const unsigned char number_chars_for_undef[MAX_NAMBER_LANGUAGE] = {SIZE_UNDEF, 4, SIZE_UNDEF, SIZE_UNDEF};
#undef SIZE_UNDEF
    
    int number_charts_for_undef_tmp = number_chars_for_undef[index_language];
    
    /*************
    ��������� ���������� ���� ����
    *************/

#define SIZE_NAME_ANALOG_CANAL   5
//    for (int index_1 = 0; index_1 < MAX_ROW_FOR_MEASURMENT_ANGLE; index_1++) 
//    {
//      for (int index_2 = 0; index_2 < SIZE_NAME_ANALOG_CANAL; index_2++) 
//      name_string[index_1][SIZE_NAME_ANALOG_CANAL + 1 + index_2] = name_string[base_index_for_angle][index_2];
//    }
#undef SIZE_NAME_ANALOG_CANAL
    /*************/
        
    unsigned int position_temp = current_ekran.index_position;
    unsigned int index_of_ekran;
    index_of_ekran = (position_temp >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;
  
    //�������  ����� � ������� �����
    for (unsigned int i=0; i< MAX_ROW_LCD; i++)
    {
      //������� ����� ����� ���������, �� �� ����� ���������� � ������� �����������
      if (index_of_ekran < MAX_ROW_FOR_MEASURMENT_ANGLE)
      {
        static enum _full_ort_index  const pair[MAX_ROW_FOR_MEASURMENT_ANGLE][2] =
        {
          {FULL_ORT_Imn, FULL_ORT_Umn},
          {FULL_ORT_Ibp, FULL_ORT_Ubp}
        };

        int value = -1;
        unsigned int bank_for_calc_phi_angle_tmp = bank_for_calc_phi_angle;
        int phi_I = phi_angle[bank_for_calc_phi_angle_tmp][pair[index_of_ekran][0]];
        int phi_U = phi_angle[bank_for_calc_phi_angle_tmp][pair[index_of_ekran][1]];
        if((phi_I >= 0) && (phi_U >= 0))
        {
          value = phi_I - phi_U;
          if (value < 0)
            value += 3600;
        }
        else
        {
            value = -1;
        }
        
        

#define LAST_POSITION_OF_TITLE  10
        
        //��������� ���� ������ � �� ��������� ��������� ����� ������ �� ���������� ��� �������
        int shift = 0;
        for (int index_1 = 1; index_1 <= LAST_POSITION_OF_TITLE; index_1++)
        {
          if (name_string[index_of_ekran][index_1 - shift] == ' ')
          {
            //ϳ������� �������, ��� �� ���� ������ ������
            for (int index_2 = (index_1 - shift); index_2 <= (LAST_POSITION_OF_TITLE - shift); index_2++)
            {
              name_string[index_of_ekran][index_2] = name_string[index_of_ekran][index_2 + 1];
            }
            shift++;
          }
        }
        if (
            (name_string[index_of_ekran][0] != ' ') && 
            (shift > 0) && 
            (
             ((value >= 0 /*0.0�*/) && (value <= 999 /*99.9�*/)) ||
             (
              (value < 0) &&
              (number_charts_for_undef_tmp < (MAX_COL_LCD - LAST_POSITION_OF_TITLE - 1 - 1))  
             )  
            )
           )
        {
          for (int index_1 = (LAST_POSITION_OF_TITLE - shift); index_1 >= 0 ; index_1--)
            name_string[index_of_ekran][index_1 + 1] = name_string[index_of_ekran][index_1];
          name_string[index_of_ekran][0] = ' ';
          shift--;
        }

        int position = LAST_POSITION_OF_TITLE - shift + 1;

#undef LAST_POSITION_OF_TITLE
        
        if (value >= 0)
        {
          int number_charts_for_value = 4; /*����� �� ����, ��������� ����, ���� � ���� "�"*/
          if (value > 999 /*99.9�*/) number_charts_for_value += 2;
          else if (value > 99 /*9.9�*/) number_charts_for_value += 1;
          
          int free_position = MAX_COL_LCD - position - number_charts_for_value;
          if (free_position >= 3)
          {
            name_string[index_of_ekran][position    ] = ' ';
            name_string[index_of_ekran][position + 1] = '=';
            name_string[index_of_ekran][position + 2] = ' ';
            position += 3;
          }
          else if (free_position == 2)
          {
            name_string[index_of_ekran][position    ] = ' ';
            name_string[index_of_ekran][position + 1] = '=';
            position += 2;
          }
          else
          {
            name_string[index_of_ekran][position    ] = '=';
            position += 1;
          }
          
          //��� �� ������ �������� � ������ ������� (� ������� �� �������)
          int vaga = 1000, first_symbol = 0;
      
          while (vaga > 0)
          {
            int temp_data;
            temp_data = value / vaga; //�������� �����, ��� ����� ����������� � ������ � �������� � ���� ������� ������
            value %= vaga; //���������� ����� ��� �������, ���� �� ����� ������ �������� �� �����
            vaga /=10; //�������� ������� ���������� � 10 ����
            
            if (vaga == 0) name_string[index_of_ekran][position++] = '.'; //��������� ����

            //� �������, ���� �� �� � ����� �����������, �� ��� ����� ���������� �������� ������ ���������
            if ((temp_data != 0) || (first_symbol != 0))
            {
              name_string[index_of_ekran][position] = temp_data + 0x30;
              if (first_symbol == 0) first_symbol = 1;
            }
            else
            {
              //���� �������� ����� � ���� �������, ���� �� � ������ ������� ����� (������ ���� ����� ���� 1)
              if (vaga > 1 ) name_string[index_of_ekran][position] = ' ';
              else
              {
                name_string[index_of_ekran][position] = temp_data + 0x30;
                if (first_symbol == 0) first_symbol = 1;
              }
            }
            if (name_string[index_of_ekran][position] != ' ') position++;
          }
          name_string[index_of_ekran][position] = '�';
        }
        else
        {
          int free_position = MAX_COL_LCD - position - number_charts_for_undef_tmp;
          if (free_position >= 3)
          {
            name_string[index_of_ekran][position    ] = ' ';
            name_string[index_of_ekran][position + 1] = '=';
            name_string[index_of_ekran][position + 2] = ' ';
            position += 3;
          }
          else if (free_position == 2)
          {
            name_string[index_of_ekran][position    ] = ' ';
            name_string[index_of_ekran][position + 1] = '=';
            position += 2;
          }
          else
          {
            name_string[index_of_ekran][position    ] = '=';
            position += 1;
          }
          
          for (int j = 0; j < number_charts_for_undef_tmp; j++) name_string[index_of_ekran][position + j] = undefined[index_language][j];
        }
        
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_of_ekran][j];
      }
      else
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = ' ';

      index_of_ekran++;
    }

    //³���������� ������ �� ��������
    current_ekran.position_cursor_y = position_temp & (MAX_ROW_LCD - 1);
    //������ �������
    current_ekran.cursor_on = 1;
  }

  //������ �� ���������� ������������ �� ������ �������
  current_ekran.position_cursor_x = 0;
  //������ �� ����
  current_ekran.cursor_blinking_on = 0;
  //�������� ������� ���� �����
  current_ekran.current_action = ACTION_WITH_CARRENT_EKRANE_FULL_UPDATE;
}
/*****************************************************/

/*****************************************************/
//������� ����� ����������� �����������
/*****************************************************/
void make_ekran_power(unsigned int pervynna_vtorynna)
{
  
  unsigned char name_string[MAX_ROW_FOR_MEASURMENT_POWER][MAX_COL_LCD] = 
  {
    "Pmn=            ",
    "Qmn=            ",
    "Smn=            ",
    " cos(phi)=      ",
    "Pbp=            ",
    "Qbp=            ",
    "Sbp=            "
  };
  static const unsigned int index_of_start_position[MAX_ROW_FOR_MEASURMENT_POWER] = {5, 5, 5, 11,5, 5, 5};

#define SIZE_POWER_DIMENSION    3
  static const unsigned char power_dimension[MAX_ROW_FOR_MEASURMENT_POWER - 1][MAX_NAMBER_LANGUAGE][SIZE_POWER_DIMENSION] = 
  {
    {"�� ", "�� ", "W  ", "�� "},
    {"���", "���", "VAr", "���"},
    {"�� ", "�� ", "VA ", "�� "}
  };
  
  int index_language = index_language_in_array(current_settings.language);
  
  // ..for (unsigned int i = 0; i < (MAX_ROW_FOR_MEASURMENT_POWER - 1); i++)
  for (unsigned int i = 0; i < (INDEX_ML_COS_PHI); i++)
  
  {
    for (unsigned int j = 0; j < SIZE_POWER_DIMENSION; j++)
    name_string[i][MAX_COL_LCD - SIZE_POWER_DIMENSION + j] = power_dimension[i][index_language][j];
  }
  
  
  // ..for (unsigned int i = 0; i < (MAX_ROW_FOR_MEASURMENT_POWER - 1); i++)
  for (unsigned int i = INDEX_ML_Pbp; i < (INDEX_ML_Sbp + 1); i++)
  {
    for (unsigned int j = 0; j < SIZE_POWER_DIMENSION; j++)
    name_string[i][MAX_COL_LCD - SIZE_POWER_DIMENSION + j] = power_dimension[(i - INDEX_ML_Pbp)] [index_language][j];
  }
#undef SIZE_POWER_DIMENSION
  
  unsigned int position_temp = current_ekran.index_position;
  unsigned int index_of_ekran;
  
  index_of_ekran = (position_temp >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;
  
  //�������  ����� � ������� �����
  for (unsigned int i=0; i< MAX_ROW_LCD; i++)
  {
    //������� ����� ����� ���������, �� �� ����� ���������� � ������� �����������
    if (index_of_ekran < MAX_ROW_FOR_MEASURMENT_POWER)
    {
      unsigned int start_position = index_of_start_position[index_of_ekran];
      /********************************/
      //������� ���������� ��������  
      int temp_value = 0;
      switch (index_of_ekran)
      {
      case INDEX_ML_Pmn:
        {
          temp_value = P[bank_for_calc_power][0];
          break;
        }
      case INDEX_ML_Qmn:
        {
          temp_value = Q[bank_for_calc_power][0];
          break;
        }
      case INDEX_ML_Smn:
        {
          temp_value = S[bank_for_calc_power][0];
          break;
        }
      case INDEX_ML_COS_PHI:
        {
          temp_value = cos_phi_x1000[bank_for_calc_power][0];
          break;
        }
        
        
        case INDEX_ML_Pbp:
        {
          temp_value = P[bank_for_calc_power][1];// � ��� �� 
          break;
        }
      case INDEX_ML_Qbp:
        {
          temp_value = Q[bank_for_calc_power][1];// � ��� �� 
          break;
        }
      case INDEX_ML_Sbp:
        {
          temp_value = S[bank_for_calc_power][1];// � ��� �� 
          break;
        }
        
        
        
        
        
        
      default:
        {
          //���������� ����� ����� �� ���� � ����
          total_error_sw_fixed();
        }
      }
      
      
      if (temp_value < 0)
      {
        temp_value = -temp_value;
        name_string[index_of_ekran][start_position - 1] = '-';
      }

      if (index_of_ekran != INDEX_ML_COS_PHI)
      {
        if (pervynna_vtorynna == 0 ) 
          convert_and_insert_char_for_measurement(3, (unsigned int)temp_value, 1, 1, name_string[index_of_ekran], start_position);
        else if( (pervynna_vtorynna != 0) && (index_of_ekran < INDEX_ML_COS_PHI) )
          convert_and_insert_char_for_measurement(3, (unsigned int)temp_value, current_settings.TVoltage*current_settings.Tmn, 1, name_string[index_of_ekran], start_position);
        else if( (pervynna_vtorynna != 0) && (index_of_ekran > INDEX_ML_COS_PHI) )
          convert_and_insert_char_for_measurement(3, (unsigned int)temp_value, current_settings.TVoltage*current_settings.Tbp, 1, name_string[index_of_ekran], start_position);
        
      }
      else
      {
        unsigned int position = start_position;
        if (S[bank_for_calc_power][0] != 0)
        {
          unsigned int dilnyk = 1000;
          for (unsigned int j = 0; j < 4; j++)
          {
            int value;

            value = temp_value / dilnyk; 
            temp_value %= dilnyk;
            name_string[index_of_ekran][position++] = value + 0x30;
            if (j == 0)
            {
              //��������� "����"
              name_string[index_of_ekran][position++] = '.';
            }
            dilnyk /= 10;
          }
        }
        else
        {
#define SIZE_UNDEF      6
          static const unsigned char undefined[MAX_NAMBER_LANGUAGE][SIZE_UNDEF] =
          {
            "�����.",
            "���.  ",
            "Undef.",
            "�����."  
          };
        
          position -= 1;
          for (unsigned int j = 0; j < SIZE_UNDEF; j++) name_string[index_of_ekran][position + j] = undefined[index_language][j];
#undef SIZE_UNDEF
        }
      }
      
      unsigned int shift = 0;
      while (
             (name_string[index_of_ekran][start_position] == ' ') &&
             ((start_position + shift) < MAX_COL_LCD)  
            ) 
      {
        for (unsigned int j = start_position; j < (MAX_COL_LCD - 1); j++ ) name_string[index_of_ekran][j] = name_string[index_of_ekran][j + 1];
        name_string[index_of_ekran][MAX_COL_LCD - 1] = ' ';
        shift++;
      }
      /********************************/

      for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_of_ekran][j];
    }
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
//������� ����� ����������� �����
/*****************************************************/
void make_ekran_resistance(unsigned int pervynna_vtorynna)
{
  unsigned char name_string[MAX_ROW_FOR_MEASURMENT_RESISTANCE][MAX_COL_LCD] = 
  {
    " Rmn            ",
    " Xmn            ",
    " Zmn            ",
    " Rbp            ",
    " Xbp            ",
    " Zbp            "
  };
  static const unsigned int index_of_start_position_array[MAX_NAMBER_LANGUAGE] = {4, 4, 5, 4};

  int index_language = index_language_in_array(current_settings.language);
  unsigned int start_position = index_of_start_position_array[index_language];
  unsigned int size_dimension = size_dimension_array[index_language];
  
  for (unsigned int i = 0; i < size_dimension; i++)
  {
    unsigned char letter = resistance_dimension[index_language][i];
    for (unsigned int j = 0; j < MAX_ROW_FOR_MEASURMENT_RESISTANCE; j++)
    {
      name_string[j][MAX_COL_LCD - size_dimension + i] = letter;
      name_string[j][start_position] = '=';
    }
  }
  start_position++;
  
  
  unsigned int position_temp = current_ekran.index_position;
  unsigned int index_of_ekran;
  
  index_of_ekran = (position_temp >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;

  //������� ���������� �� ������ ��� �����������
  semaphore_measure_values_low1 = 1;
  for (unsigned int i = 0; i < MAX_NUMBER_INDEXES_RESISTANCE; i++ ) 
  {
    resistance_low[i] =resistance_middle[i];
  }
  semaphore_measure_values_low1 = 0;
  
  //�������  ����� � ������� �����
  for (unsigned int i=0; i< MAX_ROW_LCD; i++)
  {
    //������� ����� ����� ���������, �� �� ����� ���������� � ������� �����������
    if (index_of_ekran < MAX_ROW_FOR_MEASURMENT_RESISTANCE)
    {
      int temp_value = resistance_low[index_of_ekran];
      if(((unsigned int)temp_value) != ((unsigned int)UNDEF_RESISTANCE))
      {
        /********************************/
        //������� ���������� ��������
        /********************************/
        if (temp_value < 0)
        {
          temp_value = -temp_value;
          name_string[index_of_ekran][start_position] = '-';
        }
        if (pervynna_vtorynna == 0)
          convert_and_insert_char_for_measurement(3, temp_value, 1, 1, name_string[index_of_ekran], (start_position + 1));
        else
          convert_and_insert_char_for_measurement(3, temp_value, current_settings.TVoltage, current_settings.Tmn, name_string[index_of_ekran], (start_position + 1));

        unsigned int shift = 0;
        unsigned int start_position_to_shift = start_position + 1;
        while (
               (name_string[index_of_ekran][start_position_to_shift] == ' ') &&
               ((start_position_to_shift + shift) < MAX_COL_LCD)  
              ) 
        {
          for (unsigned int j = start_position_to_shift; j < (MAX_COL_LCD - 1); j++ ) name_string[index_of_ekran][j] = name_string[index_of_ekran][j + 1];
          name_string[index_of_ekran][MAX_COL_LCD - 1] = ' ';
          shift++;
        }
        /********************************/
      }
      else
      {
#define SIZE_UNDEF      9
        static const unsigned char undefined[MAX_NAMBER_LANGUAGE][SIZE_UNDEF] =
        {
          "�������. ",
          "��������.",
          "Undef.   ",
          "�������. "  
        };
        for (unsigned int j = 0; j < size_dimension; j++) name_string[index_of_ekran][MAX_COL_LCD - size_dimension + j] = ' ';
        for (unsigned int j = 0; j < SIZE_UNDEF; j++) name_string[index_of_ekran][start_position + 1 + j] = undefined[index_language][j];
#undef SIZE_UNDEF
      }

      for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_of_ekran][j];
    }
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
