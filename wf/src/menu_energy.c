#include "header.h"

/*****************************************************/
//������� ����� ����������� ��������� ����� �����������㳿
/*****************************************************/
void make_ekran_energy(unsigned int pervynna_vtorynna)
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_EKRAN_ENERGY][MAX_COL_LCD] = 
  {
    {
      "   Ea+ (���*�)  ",
      "   Ea- (���*�)  ",
      "  Er1 (����*�)  ",
      "  Er2 (����*�)  ",
      "  Er3 (����*�)  ",
      "  Er4 (����*�)  "
    },
    {
      "  Ea+ (���*���) ",
      "  Ea- (���*���) ",
      " Er1 (����*���) ",
      " Er2 (����*���) ",
      " Er3 (����*���) ",
      " Er4 (����*���) "
    },
    {
      "   Ea+ (kW*h)   ",
      "   Ea- (kW*h)   ",
      "  Er1 (kVAr*h)  ",
      "  Er2 (kVAr*h)  ",
      "  Er3 (kVAr*h)  ",
      "  Er4 (kVAr*h)  "
    },
    {
      "   Ea+ (���*�)  ",
      "   Ea- (���*�)  ",
      "  Er1 (����*�)  ",
      "  Er2 (����*�)  ",
      "  Er3 (����*�)  ",
      "  Er4 (����*�)  "
    }
  };
  static const unsigned int energy_k_M[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_EKRAN_ENERGY] = 
  {
    {8, 8, 7, 7, 7, 7},
    {7, 7, 6, 6, 6, 6},
    {8, 8, 7, 7, 7, 7},
    {8, 8, 7, 7, 7, 7}
  };
  int index_language = index_language_in_array(current_settings.language);
  
  unsigned int position_temp = current_ekran.index_position;
  unsigned int index_of_ekran;
  
  //�������� �� ��� �������� position_temp ������� ��� ����, �� ����� ������� �� ������������� ��� ����� (����� + ��������)
  index_of_ekran = ((position_temp<<1) >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;

  unsigned int col_begin = 0, col_end = MAX_COL_LCD - 1, col_comma = 0;
  for (unsigned int i=0; i< MAX_ROW_LCD; i++)
  {
    unsigned int index_of_ekran_tmp = index_of_ekran >> 1;
    if (index_of_ekran_tmp < MAX_ROW_FOR_EKRAN_ENERGY)
    {
      if ((i & 0x1) == 0)
      {
        //� ��������� ����� ����� �������� ���������
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) 
        {
          if (
              (pervynna_vtorynna == 0) ||
              (j != energy_k_M[index_language][index_of_ekran_tmp])  
             )
          {
            working_ekran[i][j] = name_string[index_language][index_of_ekran_tmp][j];
          }
          else
          {
            working_ekran[i][j] = 'M';
          }
        }
      }
      else
      {
        //� ������� ����� ����� �������� ��������
        double value_double = energy[0][index_of_ekran_tmp];
        if (pervynna_vtorynna == 0) 
          value_double *= 1000.0;
        else
          value_double *= (double)(current_settings.TVoltage*current_settings.Tmn); /*�� 1000 �� �������, �� ����� ��������� ����� � ���*��� �� ���*���*/
        unsigned long long value = (unsigned long long)(value_double);

        unsigned long long vaga = 1; //���������� ������� ����������
        unsigned int number_digits = 1; //��������� ������� �������
        unsigned int first_symbol = 0; //�������, �� �� � ���� �������� ������ �� ���������

        //���������� ������� �������� �����
        unsigned long long divisor = 10;
        unsigned long long value_tmp = value;
        do
        {
          value_tmp /= divisor;
          if (value_tmp != 0)
          {
            number_digits++;
            vaga *= 10;
          }
        }
        while (value_tmp != 0 );

        if (number_digits < 4) 
        {
          number_digits = 4; /*�� ����� ���������� ����� ����'������ ����� ��������� ����� � ���� ���� ����� ��������� ��� �����*/
          vaga = 1000;
        }
        number_digits++; /*�� �� ���� �� ��������� ����*/

        col_begin = (MAX_COL_LCD - number_digits) >> 1;
        col_end = col_begin +  number_digits - 1;
        col_comma = col_end - 3;

        value_tmp = value;
        for (unsigned int j = 0; j<MAX_COL_LCD; j++)
        {
          if ((j < col_begin) ||  (j > col_end )) working_ekran[i][j] = ' ';
          else if (j == col_comma )working_ekran[i][j] = ',';
          else
            calc_symbol_and_put_into_working_ekran((working_ekran[i] + j), &value, &vaga, &first_symbol, j, col_comma, 1, 1);
        }
      }
    }
    else
      for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = ' ';

    index_of_ekran++;
  }

  //³���������� ������ �� �������� � ������ ������ �� ���� � ��� �� ���������
  current_ekran.position_cursor_y = ((position_temp<<1) + 1) & (MAX_ROW_LCD - 1);
  //������ �� ���������� ������������ �� ������� ������ � �������, ���� �� �� � ����� �����������, ������ ������� ���� ��������� � ������ main_manu_function
  if (current_ekran.edition == 0)
  {
    int last_position_cursor_x = col_end;
    current_ekran.position_cursor_x = col_begin;

    //ϳ������� ������ �� ������� �������
    while (((working_ekran[current_ekran.position_cursor_y][current_ekran.position_cursor_x + 1]) == ' ') && 
           (current_ekran.position_cursor_x < (last_position_cursor_x -1))) current_ekran.position_cursor_x++;
    
    //������ ������� ���, ��� �� ��� ����� ������
    if (((working_ekran[current_ekran.position_cursor_y][current_ekran.position_cursor_x]) != ' ') && 
        (current_ekran.position_cursor_x > 0)) current_ekran.position_cursor_x--;
  }
  //������ ���������
  current_ekran.cursor_on = 0;
  //������ �� ����
  /*if(current_ekran.edition == 0)*/current_ekran.cursor_blinking_on = 0;
  /*else current_ekran.cursor_blinking_on = 1;*/
  //�������� ������� ���� �����
  current_ekran.current_action = ACTION_WITH_CARRENT_EKRANE_FULL_UPDATE;
}
/*****************************************************/


/*****************************************************/
//
/*****************************************************/
/*****************************************************/
