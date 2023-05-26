#include "header.h"

/*****************************************************/
//������� ����� ������������
/*****************************************************/
void make_ekran_configuration(unsigned int configuration_edit_temp)
{
#define MAX_COL_LCD_PART1 10

  static const unsigned char name_string[MAX_NAMBER_LANGUAGE][MAX_ROW_FOR_EKRAN_CONFIGURATION][MAX_COL_LCD_PART1] = 
  {
    {
     "���       ",
     "���       ",
     "���       ",
     "����      ",
     "����      ",
     "���       ",
     "���-����  ",
     "����      ",
     "���       ",
     "�����     ",
     "������    ",
     "��        ",
     "���       ",
     "����.���. "
    },
    {
     "���       ",
     "���       ",
     "���       ",
     "����      ",
     "����      ",
     "���       ",
     "���-����  ",
     "����      ",
     "���       ",
     "����     ",
     "������    ",
     "��        ",
     "���       ",
     "����.���. "
    },
    {
     "���       ",
     "OCP       ",
     "���       ",
     "����      ",
     "����      ",
     "AR        ",
     "UFLS-FAR  ",
     "CBFP      ",
     "���      ",
     "Umin      ",
     "Umax      ",
     "UP        ",
     "���       ",
     "Ext.logic "
    },
    {
     "���       ",
     "��K       ",
     "���       ",
     "����      ",
     "����      ",
     "�KK       ",
     "���-��KK  ",
     "Ѳ��K     ",
     "���       ",
     "�����     ",
     "������    ",
     "��        ",
     "���       ",
     "����.���. "
    }
  };
  static const unsigned char name_nzz[MAX_NAMBER_LANGUAGE][2][MAX_COL_LCD_PART1] = 
  {                                //  {
      {"����      ", "����      "},  //    {"���       ", "��        "},
      {"����      ", "����      "},  //    {"���       ", "��        "},
      {"����      ", "����      "},  //    {"���       ", "SGFP      "},
      {"����      ", "����      "}   //    {"���       ", "��        "}
  };                               //  };
///*  static const unsigned char name_nzz[MAX_NAMBER_LANGUAGE][2][MAX_COL_LCD_PART1] = 
//  {
//    {"���       ", "��        "},
//    {"���       ", "��        "},
//    {"���       ", "SGFP      "},
//    {"���       ", "��        "}
//  };
//*/
  static const unsigned char information_on[MAX_NAMBER_LANGUAGE][MAX_COL_LCD - MAX_COL_LCD_PART1] = 
  {
    "���.  ",
    "����.",
    "On    ",
    "����. "
  };
  static const unsigned char information_off[MAX_NAMBER_LANGUAGE][MAX_COL_LCD - MAX_COL_LCD_PART1] = 
  {
    "����. ",
    "����. ",
    "Off   ",
    "њ��. "
  };
  
  unsigned char name_string_tmp[MAX_ROW_FOR_EKRAN_CONFIGURATION][MAX_COL_LCD];

  int index_language = index_language_in_array(current_settings.language);
  for(int index_1 = 0; index_1 < MAX_ROW_FOR_EKRAN_CONFIGURATION; index_1++)
  {
    unsigned char *point_target;
    unsigned int nzz_zz = ((current_settings.control_zz & CTR_ZZ1_TYPE) != 0);
    if (index_1 == ZZ_BIT_CONFIGURATION) point_target = (unsigned char *)name_nzz[index_language][nzz_zz];
    else point_target = (unsigned char *)name_string[index_language][index_1];
    if(index_1 == CHP)
        continue;//
        if (index_1 > CHP){ 
             for(int index_2 = 0; index_2 < MAX_COL_LCD_PART1; index_2++)
                 name_string_tmp[index_1-1][index_2] = *(point_target + index_2);
        }
    if(index_1 == EL_BIT_CONFIGURATION){
         for(int index_2 = 0; index_2 < MAX_COL_LCD; index_2++)
                 name_string_tmp[index_1][index_2] = ' ';
    }
    if (index_1 < CHP){ 
    for(int index_2 = 0; index_2 < MAX_COL_LCD_PART1; index_2++)
      name_string_tmp[index_1][index_2] = *(point_target + index_2);
    }
  }
  
  /*******************************************************/
  //������� ��������
  /*******************************************************/
  for(unsigned int i = 0; i< EL_BIT_CONFIGURATION; i++)//MAX_ROW_FOR_EKRAN_CONFIGURATION
  {
    unsigned int configuration_temp;
    unsigned long RU32_l;
    //���� �� �� � ����� �����������, �� ������ ��� �� �������� ������� ���������
    //������ ����� �� ��������� ��� �����������
    if(current_ekran.edition == 0){
        //configuration_temp = current_settings.configuration;
        RU32_l = current_settings.configuration;
        RU32_l >>= ZDZ_BIT_CONFIGURATION;
        RU32_l <<= CHP;
        RU32_l |= current_settings.configuration&(1<<DZO_BIT_CONFIGURATION);
        configuration_temp = RU32_l;
    }   
    else{
        //configuration_temp = configuration_edit_temp;
        RU32_l = configuration_edit_temp;
        RU32_l >>= ZDZ_BIT_CONFIGURATION;
        RU32_l <<= CHP;
        RU32_l |= configuration_edit_temp&(1<<DZO_BIT_CONFIGURATION);
        configuration_temp = RU32_l;
    }

    if ((configuration_temp & (1<<i)) == 0)
    {
      for (unsigned int j = MAX_COL_LCD_PART1; j < MAX_COL_LCD; j++)
        name_string_tmp[i][j] = information_off[index_language][j - MAX_COL_LCD_PART1];
    }
    else
    {
      for (unsigned int j = MAX_COL_LCD_PART1; j < MAX_COL_LCD; j++)
        name_string_tmp[i][j] = information_on[index_language][j - MAX_COL_LCD_PART1];
    }
  }
  /*******************************************************/
    
  int position_temp = current_ekran.index_position;//check specal case
  int index_of_ekran;

  index_of_ekran = (position_temp >> POWER_MAX_ROW_LCD) << POWER_MAX_ROW_LCD;
  
  //�������  ����� � ������� �����
  for (unsigned int i=0; i< MAX_ROW_LCD; i++)
  {
    //������� ����� ����� ���������, �� �� ����� ���������� � ������� ������������
    if (index_of_ekran < MAX_ROW_FOR_EKRAN_CONFIGURATION)
      for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string_tmp[index_of_ekran][j];
    else
      for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = ' ';

    index_of_ekran++;
  }

  //������ �� ���������� ������������ �� ������ �������
  current_ekran.position_cursor_x = (MAX_COL_LCD_PART1 - 1);
  //³���������� ������ �� ��������
  current_ekran.position_cursor_y = position_temp & (MAX_ROW_LCD - 1);
  //������ �������
  current_ekran.cursor_on = 1;
  //������ �� ����
  if (current_ekran.edition == 0)   current_ekran.cursor_blinking_on = 0;
  else   current_ekran.cursor_blinking_on = 1;

  //�������� ������� ���� �����
  current_ekran.current_action = ACTION_WITH_CARRENT_EKRANE_FULL_UPDATE;
  
#undef MAX_COL_LCD_PART1  
}
/*****************************************************/

/*****************************************************/
//
/*****************************************************/
/*****************************************************/
