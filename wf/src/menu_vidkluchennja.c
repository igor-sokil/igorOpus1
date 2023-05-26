#include "header.h"

/*****************************************************/
//������� ����� ����������� ���������� ��� ���������� �� �������
/*****************************************************/
void make_ekran_vidkluchenja(void)
{
  int index_language = index_language_in_array(current_settings.language);
  
  //������� ������� �����
  for (unsigned int i = 0; i < MAX_ROW_LCD; i++)
  {
    for (unsigned int j = 0; j < MAX_COL_LCD; j++) working_ekran[i][j] = ' ';
  }
  int32_t index_position_tmp = current_ekran.index_position;
  __info_vymk info_vymk = info_vidkluchennja_vymykachatime[index_position_tmp];

  time_t time_dat_tmp = info_vymk.time_dat;
  if (time_dat_tmp != 0)
  {
    struct tm *p = localtime(&info_vymk.time_dat);
    int field;

    //����
    field = p->tm_mday;
    working_ekran[VIDKL_ROW_Y_][VIDKL_COL_DY1] = (field / 10) + 0x30;
    working_ekran[VIDKL_ROW_Y_][VIDKL_COL_DY2] = (field % 10) + 0x30;
    working_ekran[VIDKL_ROW_Y_][VIDKL_COL_DY2 + 1] = '-';

    //̳����
    field = p->tm_mon + 1;
    working_ekran[VIDKL_ROW_Y_][VIDKL_COL_MY1] = (field / 10) + 0x30;
    working_ekran[VIDKL_ROW_Y_][VIDKL_COL_MY2] = (field % 10) + 0x30;
    working_ekran[VIDKL_ROW_Y_][VIDKL_COL_MY2 + 1] = '-';

    //г�
    field = p->tm_year - 100;
    working_ekran[VIDKL_ROW_Y_][VIDKL_COL_SY1] = (field / 10) + 0x30;
    working_ekran[VIDKL_ROW_Y_][VIDKL_COL_SY2] = (field % 10) + 0x30;

    //������
    field = p->tm_hour;
    working_ekran[VIDKL_ROW_T_][VIDKL_COL_HT1] = (field / 10) + 0x30;
    working_ekran[VIDKL_ROW_T_][VIDKL_COL_HT2] = (field % 10) + 0x30;
    working_ekran[VIDKL_ROW_T_][VIDKL_COL_HT2 + 1] = ':';

    //�������
    field = p->tm_min;
    working_ekran[VIDKL_ROW_T_][VIDKL_COL_MT1] = (field / 10) + 0x30;
    working_ekran[VIDKL_ROW_T_][VIDKL_COL_MT2] = (field % 10) + 0x30;
    working_ekran[VIDKL_ROW_T_][VIDKL_COL_MT2 + 1] = ':';

    //�������
    field = p->tm_sec;
    working_ekran[VIDKL_ROW_T_][VIDKL_COL_ST1] = (field / 10) + 0x30;
    working_ekran[VIDKL_ROW_T_][VIDKL_COL_ST2] = (field % 10) + 0x30;
    working_ekran[VIDKL_ROW_T_][VIDKL_COL_ST2 + 1] = '.';

    //������ ������
    field = info_vymk.time_ms;
    working_ekran[VIDKL_ROW_T_][VIDKL_COL_HST1] = (field / 100) + 0x30;
    field %= 100;
      
    working_ekran[VIDKL_ROW_T_][VIDKL_COL_HST2] = (field / 10) + 0x30;
    field %= 10;

    working_ekran[VIDKL_ROW_T_][VIDKL_COL_HST3] = field + 0x30;
  }
  else
  {
    //����
    working_ekran[VIDKL_ROW_Y_][VIDKL_COL_DY1] = 0x30;
    working_ekran[VIDKL_ROW_Y_][VIDKL_COL_DY2] = 0x30;
    working_ekran[VIDKL_ROW_Y_][VIDKL_COL_DY2 + 1] = '-';

    //̳����
    working_ekran[VIDKL_ROW_Y_][VIDKL_COL_MY1] = 0x30;
    working_ekran[VIDKL_ROW_Y_][VIDKL_COL_MY2] = 0x30;
    working_ekran[VIDKL_ROW_Y_][VIDKL_COL_MY2 + 1] = '-';

    //г�
    working_ekran[VIDKL_ROW_Y_][VIDKL_COL_SY1] = 0x30;
    working_ekran[VIDKL_ROW_Y_][VIDKL_COL_SY2] = 0x30;

    //������
    working_ekran[VIDKL_ROW_T_][VIDKL_COL_HT1] = 0x30;
    working_ekran[VIDKL_ROW_T_][VIDKL_COL_HT2] = 0x30;
    working_ekran[VIDKL_ROW_T_][VIDKL_COL_HT2 + 1] = ':';

    //�������
    working_ekran[VIDKL_ROW_T_][VIDKL_COL_MT1] = 0x30;
    working_ekran[VIDKL_ROW_T_][VIDKL_COL_MT2] = 0x30;
    working_ekran[VIDKL_ROW_T_][VIDKL_COL_MT2 + 1] = ':';

    //�������
    working_ekran[VIDKL_ROW_T_][VIDKL_COL_ST1] = 0x30;
    working_ekran[VIDKL_ROW_T_][VIDKL_COL_ST2] = 0x30;
    working_ekran[VIDKL_ROW_T_][VIDKL_COL_ST2 + 1] = '.';

    //������ ������
    working_ekran[VIDKL_ROW_T_][VIDKL_COL_HST1] = 0x30;
    working_ekran[VIDKL_ROW_T_][VIDKL_COL_HST2] = 0x30;
    working_ekran[VIDKL_ROW_T_][VIDKL_COL_HST3] = 0x30;
  }
  
  static const unsigned char information_1[MAX_NAMBER_LANGUAGE][VYMKNENNJA_VID_MAX_NUMBER - NUMBER_UP + 1][7] = 
  {
    {"    ��1", "   ����", "    ��2", "   ����", "   ��3", "   ����", "    ��4", "   ����", "   ���1", "   ���2", "   ���3", "   ���4", "   ���", "    3I0", "    3U0", "    ���", "  ����1", "  ����2", "  ����3", " ��� ��", "   ���1", "   ���2", "  ����1", "  ����2", "    ���", " �����1", " �����2", "�����c1", "�����c2", "    ��x", "    ���", " ������"},
    {"    ��1", "   ��C�", "    ��2", "   ��C�", "   ��3", "   ��C�", "    ��4", "   ��C�", "   �C�1", "   �C�2", "   �C�3", "   �C�4", "   ���", "    3I0", "    3U0", "    ���", "  ����1", "  ����2", "  ����3", " ��� �.", "   ���1", "   ���2", "  ����1", "  ����2", "    ���", " ����1", " ����2", "�����c1", "�����c2", "    ��x", "    ���", "   ����"},
    {"    ��1", "   �OCP", "    ��2", "   �OCP", "   ��3", "   �OCP", "    ��4", "   �OCP", "   OCP1", "   OCP2", "   OCP3", "   OCP4", "   ���", "    3I0", "    3U0", "    ���", "  ����1", "  ����2", "  ����3", " ��� f.", "   ���1", "   ���2", "  CBFP1", "  CBFP2", "   NPSP", "  Umin1", "  Umin2", "  Umax1", "  Umax2", "    ��x", "    ���", "  Other"},
    {"    ��1", "   ����", "    ��2", "   ����", "   ��3", "   ����", "    ��4", "   ����", "   ���1", "   ���2", "   ���3", "   ���4", "   ���", "    3I0", "    3U0", "    ���", "  ����1", "  ����2", "  ����3", " ��� ��", "   ���1", "   ���2", "  ����1", "  ����2", "    ���", " �����1", " �����2", "�����c1", "�����c2", "    ��x", "    ���", " ������"}
  };
  unsigned char const *point;
  if ((index_position_tmp < VYMKNENNJA_VID_UP1) || (index_position_tmp >= (VYMKNENNJA_VID_UP1 + NUMBER_UP)))
  {
    if (index_position_tmp < VYMKNENNJA_VID_UP1)
      point = information_1[index_language][index_position_tmp];
    else
      point = information_1[index_language][index_position_tmp - NUMBER_UP + 1];

    for (unsigned int i = 0; i < 7; i++) working_ekran[VIDKL_ROW_Y_][VIDKL_COL_SY2 + 2 + i] = *(point + i);
  }
  else
  {
    point = information_1[index_language][VYMKNENNJA_VID_UP1];

    for (unsigned int i = 0; i < 7; i++) 
    {
      working_ekran[VIDKL_ROW_Y_][VIDKL_COL_SY2 + 2 + i] = (i != (7 - 1)) ? *(point + i) : (index_position_tmp - VYMKNENNJA_VID_UP1 + 1 + 0x30);
    }
  }
    
  
  static const unsigned char information_2[MAX_NAMBER_LANGUAGE][VYMKNENNJA_VID_MAX_NUMBER - NUMBER_UP + 1][3] = 
  {
    {"   ", "��1", "   ", "��2", "   ", "��3", "   ", "��4", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", " ��", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   "},
    {"   ", "��1", "   ", "��2", "   ", "��3", "   ", "��4", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", " ��", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   "},
    {"   ", "��1", "   ", "��2", "   ", "��3", "   ", "��4", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", " DI", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   "},
    {"   ", "��1", "   ", "��2", "   ", "��3", "   ", "��4", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", " ��", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   "}
  };

  if (index_position_tmp < VYMKNENNJA_VID_UP1)
    point = information_2[index_language][index_position_tmp];
  else if (index_position_tmp >= (VYMKNENNJA_VID_UP1 + NUMBER_UP))
    point = information_2[index_language][index_position_tmp - NUMBER_UP + 1];
  else
    point = information_2[index_language][VYMKNENNJA_VID_UP1];
  for (unsigned int i = 0; i < 3; i++) working_ekran[VIDKL_ROW_T_][VIDKL_COL_HST2 + 2 + i] = *(point + i);

  //������ �� ���������� ������������ �� ������ �������
  current_ekran.position_cursor_x = 0;
  current_ekran.position_cursor_y = 0;
  //������ ���������
  current_ekran.cursor_on = 0;
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
