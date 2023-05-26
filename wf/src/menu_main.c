#include "header.h"

/*****************************************************/
//������� ����� ��������� ����
/*****************************************************/
void make_ekran_main(void)
{
  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_EKRAN_MAIN][MAX_COL_LCD] = 
  {
    {
     " ����           ",
     " ���������      ",
     " �.��.��.�����. ",
     " �����-������   ",
     " ������� �������",
     " ������������   ",
     " Language       ",
     " ���������      ",
     " �����������    ",
     " ������������   ",
     " ���            ",
     " ���            ",
     " ���            ",
     " �T��           ",
     " �T��           ",
     " ���            ",
     " ���-����       ",
     " ����           ",
     " ���            ",
     " �����          ",
     " ������         ",
     " ��             ",
     " ���            "
    },
    {
     " ��������       ",
     " ����������    ",
     " �.���.��.�����.",
     " �����-������   ",
     " ˳�.�������    ",
     " ����������    ",
     " Language       ",
     " ������������   ",
     " ĳ���������    ",
     " ������������   ",
     " ���            ",
     " ���            ",
     " ���            ",
     " ����           ",
     " ����           ",
     " ���            ",
     " ���-����       ",
     " ����           ",
     " ���            ",
     " ����          ",
     " ������         ",
     " ��             ",
     " ���            "
    },
    {
     " Clock          ",
     " Measurement    ",
     " �.��.��.�����. ",
     " Inputs-Outputs ",
     " Resource count.",
     " Recorders      ",
     " Language       ",
     " Settings       ",
     " Diagnostic     ",
     " Configuration  ",
     " ���            ",
     " OCP            ",
     " ���            ",
     " ����           ",
     " ����           ",
     " AR             ",
     " UFLS-FAR       ",
     " CBFP           ",
     " ���            ",
     " Umin           ",
     " Umax           ",
     " UP             ",
     " ���            "
    },
    {
     " ��f��          ",
     " �����          ",
     " �.��.��.�����. ",
     " ʳ��-��f��    ",
     " ������� �������",
     " ҳ��������    ",
     " Language       ",
     " �������       ",
     " �����������    ",
     " ���������������",
     " ���            ",
     " ��K            ",
     " ���            ",
     " ����           ",
     " ����           ",
     " �KK            ",
     " ���-��KK       ",
     " Ѳ��K          ",
     " ���            ",
     " �����          ",
     " ������         ",
     " ��             ",
     " ���            "
    }
  };
  static const unsigned char name_nzz[MAX_NAMBER_LANGUAGE][2][MAX_COL_LCD] = 
  {
      {" ����           ", " ����           "},
      {" ����           ", " ����           "},
      {" ����           ", " ����           "},
      {" ����           ", " ����           "}
  };
//static const unsigned char name_nzz[MAX_NAMBER_LANGUAGE][2][MAX_COL_LCD] =
//  {  
//    {" ���            ", " ��             "},
//    {" ���            ", " ��             "},  
//    {" ���            ", " SGFP           "},  
//    {" ���            ", " ��             "}
//  };
  unsigned char name_string_tmp[MAX_ROW_FOR_EKRAN_MAIN][MAX_COL_LCD];
  
  int index_language = index_language_in_array(current_settings.language);
  for(int index_1 = 0; index_1 < MAX_ROW_FOR_EKRAN_MAIN; index_1++)
  {    
    unsigned char *point_target;
    unsigned int nzz_zz = ((current_settings.control_zz & CTR_ZZ1_TYPE) != 0);
    if (index_1 == INDEX_ML1_NZZ) point_target = (unsigned char *)name_nzz[index_language][nzz_zz];
    else point_target = (unsigned char *)name_string[index_language][index_1];
      
    for(int index_2 = 0; index_2 < MAX_COL_LCD; index_2++)
    {
      name_string_tmp[index_1][index_2] = *(point_target + index_2);
    }
  }
  
  unsigned int additional_current = 0;
  unsigned int position_temp = current_ekran.index_position;
  unsigned int index_of_ekran;
  
  /******************************************/
  //��������� ����, �� �� ����� ����������
  /******************************************/
  for (unsigned int zachyst = 0; zachyst < (TOTAL_NUMBER_PROTECTION - 1); zachyst++) /*̳��� ���� - �� �������� �� ������� ����� ������������ "��������� �����"*/
  {
    if ((current_settings.configuration & (1 << zachyst)) == 0)
    {
      unsigned int i = INDEX_ML1_DZO + zachyst - additional_current;
    
      if ((i+1) <= position_temp) position_temp--;
      do
      {
        for(unsigned int j = 0; j < MAX_COL_LCD; j++)
        {
          if ((i+1) < (MAX_ROW_FOR_EKRAN_MAIN - additional_current)) name_string_tmp[i][j] = name_string_tmp[i + 1][j];
          else name_string_tmp[i][j] = ' ';
        }
        i++;
      }
      while (i< (MAX_ROW_FOR_EKRAN_MAIN - additional_current));
      additional_current++;
    }
  }
  /******************************************/
  
  index_of_ekran = (position_temp >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;

  
  //�������  ����� � ������� �����
  for (unsigned int i=0; i< MAX_ROW_LCD; i++)
  {
    //������� ����� ����� ���������, �� �� ����� ���������� � ������� ������������
    if (index_of_ekran < (MAX_ROW_FOR_EKRAN_MAIN - additional_current))
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
