#include "header.h"

/*****************************************************/
//����������, ���� ��������� LCD ���� ������
/*****************************************************/
inline unsigned int wait_lcd_ready(void)
{
  uint16_t current_count_tim4, new_count_tim4;
  unsigned int delta;
  unsigned int error_LCD = 0;
  
  unsigned char temp_data;
  //����������� ��� LCD_RS = 0
  GPIO_ResetBits(LCD_RS, LCD_RS_PIN);

  //����������� ��� LCD_RW = 1
  GPIO_SetBits(LCD_RW, LCD_RW_PIN);
  
  /*
  ��������� ����� �������� 10,01 �� (�������� �������� ���� ����, ����� ������������, ������� ������� ��������)
  ���� ���� ���� �����������, �� �������� ��������� 10,01 �� - �� �� ������, LCD ���������
  */
  current_count_tim4 = ((uint16_t)TIM4->CNT);
  delta = 0;

  //������ IR-������ � ���� �� BF ���� ����� 0
  unsigned int count = 0;
  do
  {
    //�������� �� ������� �� 40 ��
    _DELAY_ABOUT_40NS();
    temp_data =  *((unsigned char *) LCD_BASE);
    //�������� �� ������� �� 10 ��
    _DELAY_ABOUT_10NS();

    new_count_tim4 = ((uint16_t)TIM4->CNT);
    if (new_count_tim4 >= current_count_tim4) delta = new_count_tim4 - current_count_tim4;
    else delta = (0x10000 - current_count_tim4) + new_count_tim4; //0x10000 - �� ������ ����� �������, �� �� �������� ���� ���������� �������� [0; 65535]
    
    if (delta >= 1001) //(1000 + 1)* 0,01(��) = 10,01(��)
    {
      error_LCD = 1; //������� ��� ����� 10,01 �� � � ���� LCD �� ��������� ��������
    }
    
    if ((temp_data & (1<<BF_BIT)) != 0) count = 0;
    else count++;
  }
  while (
         (count      < 2) &&
         (error_LCD == 0) 
        );
  
  return error_LCD;
  
}
/*****************************************************/

/*****************************************************/
//������� ����� � ���������� LCD
/*****************************************************/
inline unsigned int read_data_from_lcd(unsigned char *p_letter)
{
  //������� ���� LCD ���� ������
  unsigned int error_LCD = wait_lcd_ready();
  if (error_LCD == 0)
  {
    //����������� ��� LCD_RS = 1
    GPIO_SetBits(LCD_RS, LCD_RS_PIN);
    //����������� ��� LCD_RW = 1
    GPIO_SetBits(LCD_RW, LCD_RW_PIN);
    //�������� �� ������� �� 40 ��
    _DELAY_ABOUT_40NS();
    *p_letter = *((unsigned char *) LCD_BASE);
    //�������� �� ������� �� 10 ��
    _DELAY_ABOUT_10NS();
  }
  
  return error_LCD;
}
/*****************************************************/

/*****************************************************/
//����� ����� � ��������� LCD
/*****************************************************/
inline unsigned int write_data_to_lcd(unsigned char letter)
{
  //������� ���� LCD ���� ������
  unsigned int error_LCD = wait_lcd_ready();
  if (error_LCD == 0)
  {
    //����������� ��� LCD_RS = 1
    GPIO_SetBits(LCD_RS, LCD_RS_PIN);
    //����������� ��� LCD_RW = 0
    GPIO_ResetBits(LCD_RW, LCD_RW_PIN);
    //�������� �� ������� �� 40 ��
    _DELAY_ABOUT_40NS();
    *((unsigned char *) LCD_BASE) = letter;
    //�������� �� ������� �� 10 ��
    _DELAY_ABOUT_10NS();
  }
  
  return error_LCD;
}
/*****************************************************/


/*****************************************************/
//������������ ASCII � ��� LCD
/*****************************************************/
inline unsigned int Win1251toHd44780 (unsigned int win1251Letter)
{ 
  if ( win1251Letter < 128 )
  return win1251Letter;

  //ϳ��� ���� ������� � ������������ ����������� ������ CGRAM
  for (unsigned int i = 0; i < 69; i ++ )
  {
    if ( letters [i] [0] == win1251Letter )
    return letters [i][1];
  }
  
  //ϳ��� ���� ������� � ���������� ������� � CGRAM
  if ((current_language >= LANGUAGE_RU) && (current_language <= LANGUAGE_KZ))
  {
    //�� ����� ���� � ������������ ������
    for (unsigned int i = 0; i < 12; i ++ )
    {
      if ( extra_letters [i][0] == win1251Letter )
      return extra_letters[i][current_language];
    }
  }

  return 0xff;
}
/*****************************************************/


/*****************************************************/
//����� ������� � ��������� LCD
/*****************************************************/
inline unsigned int write_command_to_lcd(unsigned char command)
{
  //������� ���� LCD ���� ������
  unsigned int error_LCD = wait_lcd_ready();
  if (error_LCD == 0)
  {
    //����������� ��� LCD_RS = 0
    GPIO_ResetBits(LCD_RS, LCD_RS_PIN);
    //����������� ��� LCD_RW = 0
    GPIO_ResetBits(LCD_RW, LCD_RW_PIN);
    //�������� �� ������� �� 40 ��
    _DELAY_ABOUT_40NS();
    *((unsigned char *) LCD_BASE) = command;
    //�������� �� ������� �� 10 ��
    _DELAY_ABOUT_10NS();
  }
  
  return error_LCD;
}
/*****************************************************/

/*****************************************************/
//�������� �����������
/*****************************************************/
void lcd_init(void)
{
  uint16_t current_count_tim4, new_count_tim4;
  unsigned int delta;
  //��������� ��� ����, �� TIM4 ����� � ������� 100��� - ����� 10��� = 0,01 ��
  
  //��������� ����� 15 ��
  current_count_tim4 = ((uint16_t)TIM4->CNT);
  delta = 0;
  while (delta < 1501) //(1500 + 1)* 0,01(��) = 15,01(��)
  {
    //������ � watchdogs
    watchdog_routine(WATCHDOG_KYYBOARD);
    
    new_count_tim4 = ((uint16_t)TIM4->CNT);
    if (new_count_tim4 >= current_count_tim4) delta = new_count_tim4 - current_count_tim4;
    else delta = (0x10000 - current_count_tim4) + new_count_tim4; //0x10000 - �� ������ ����� �������, �� �� �������� ���� ���������� �������� [0; 65535]
  }
  //�������� �� ������� �� 40 ��
  _DELAY_ABOUT_40NS();
  //������� � ��������� LCD ����� 0x3A (2 ����� � ����� ������ 5*7 � ������� ������� � ����������� ���������)
  *((unsigned char *) LCD_BASE) = 0x3A;
  //�������� �� ������� �� 10 ��
  _DELAY_ABOUT_10NS();

  //��������� ����� 4,1 ��
  current_count_tim4 = ((uint16_t)TIM4->CNT);
  delta = 0;
  while (delta < 411) //(410 + 1)* 0,01(��) = 4,11(��)
  {
    //������ � watchdogs
    watchdog_routine(WATCHDOG_KYYBOARD);
    new_count_tim4 = ((uint16_t)TIM4->CNT);
    if (new_count_tim4 >= current_count_tim4) delta = new_count_tim4 - current_count_tim4;
    else delta = (0x10000 - current_count_tim4) + new_count_tim4; //0x10000 - �� ������ ����� �������, �� �� �������� ���� ���������� �������� [0; 65535]
  }
  //�������� �� ������� �� 40 ��
  _DELAY_ABOUT_40NS();
  //�������� ������� � ��������� LCD ����� 0x3A (2 ����� � ����� ������ 5*7 � ������� ������� � ����������� ���������)
  *((unsigned char *) LCD_BASE) = 0x3A;
  //�������� �� ������� �� 10 ��
  _DELAY_ABOUT_10NS();

  //��������� ����� 100 ��� 
  current_count_tim4 = ((uint16_t)TIM4->CNT);
  delta = 0;
  while (delta < 11) //(10 + 1)* 10(���) = 110(���)
  {
    //������ � watchdogs
    watchdog_routine(WATCHDOG_KYYBOARD);
    new_count_tim4 = ((uint16_t)TIM4->CNT);
    if (new_count_tim4 >= current_count_tim4) delta = new_count_tim4 - current_count_tim4;
    else delta = (0x10000 - current_count_tim4) + new_count_tim4; //0x10000 - �� ������ ����� �������, �� �� �������� ���� ���������� �������� [0; 65535]
  }
  //�������� �� ������� �� 40 ��
  _DELAY_ABOUT_40NS();
  //����� ��� ������� � ��������� LCD ����� 0x3A (2 ����� � ����� ������ 5*7 � ������� ������� � ����������� ���������)
  *((unsigned char *) LCD_BASE) = 0x3A;
  //�������� �� ������� �� 10 ��
  _DELAY_ABOUT_10NS();

  //������ � watchdogs
  watchdog_routine(WATCHDOG_KYYBOARD);

  //������������ 2 ����� � ����� ������ 5*7 � ������� ������� � ����������� ���������
  unsigned int error_LCD = write_command_to_lcd(0x3A);

  //³�������� LCD
  if (error_LCD == 0) write_command_to_lcd(0x08);

  //������� LCD
  if (error_LCD == 0) write_command_to_lcd(0x01);

  //�������� ������� "Return Home"
  if (error_LCD == 0) write_command_to_lcd(0x02);

  //������������ ����� LCD: �������� ����������, ����� �� ��������
  if (error_LCD == 0) write_command_to_lcd(0x06);

  //³���������� ��������, ������ � � �� ����
  if (error_LCD == 0) write_command_to_lcd(0x0E);

  if (error_LCD != 0) 
  {
    //����������� ����������� ��� �� ����
    _SET_BIT(set_diagnostyka, ERROR_LCD_BIT);
  }
  
  //������ � watchdogs
  watchdog_routine(WATCHDOG_KYYBOARD);
}
/*****************************************************/


/*****************************************************/
//������� LCD
/*****************************************************/
unsigned int clear_lcd(void)
{
  unsigned int error_LCD = write_command_to_lcd(0x1);
  
  return error_LCD;
}
/*****************************************************/

/*****************************************************/
//����� �����������
/*****************************************************/
unsigned int mode_viewing(unsigned int ecran_on, unsigned int cursor_on, unsigned int cursor_blinking)
{
  unsigned char temp_data = 0x8;

  //������� �������� �����
  if(ecran_on != 0) temp_data |= (1<<2);
  if(cursor_on != 0) temp_data |= (1<<1);
  if(cursor_blinking != 0) temp_data |= (1<<0);

  unsigned int error_LCD = write_command_to_lcd(temp_data);
  
  return error_LCD;
}
/*****************************************************/

/*****************************************************/
//���� ����� �� LCD
/*****************************************************/
unsigned int hd44780_puts (unsigned char *s, unsigned int len)
{
  unsigned int letter, error_LCD = 0;
  
  unsigned int i = 0;
  while(
        (i < len       ) &&
        (error_LCD == 0)  
       )
  { 
    letter = Win1251toHd44780 (s [i++]); // ���� �����
    error_LCD = write_data_to_lcd(letter);
  }
  
  return error_LCD;
} 
/*****************************************************/

/*****************************************************/
//���� ����������� ���������� ����� �� LCD
/*****************************************************/
unsigned int hd44780_test (unsigned char *s, unsigned int len)
{
  unsigned int letter, error_LCD = 0;
  
  unsigned int i = 0;
  while(
        (i < len       ) &&
        (error_LCD == 0)  
       )
  { 
    letter = Win1251toHd44780 (s [i++]); // ���� �����
    unsigned char letter_test;
    error_LCD = read_data_from_lcd(&letter_test);
    if (error_LCD == 0) error_LCD = (letter_test != letter);
  }
  
  return error_LCD;
} 
/*****************************************************/

/*****************************************************/
//������� ������� � ������� �������
/*****************************************************/
unsigned int hd44780_gotoxy(unsigned char x, unsigned char y)
{
  unsigned char address, writeValue;

  address = 0; // default
  switch (y)
  { 
#if POWER_MAX_ROW_LCD == 1
    
  case 0: // 0-�� �����
      { 
        address = 0x00;
        break;
      }

    case 1: // 1-�� �����
      {
        address = 0x40;
        break;
      }
#elif POWER_MAX_ROW_LCD == 2
      
  case 0: // 0-�� �����
      { 
        address = 0x00;
        break;
      }
    case 1: // 1-�� �����
      {
        address = 0x40;
        break;
      }
    case 2: // 2-�� �����
      { 
        address = 0x10;
        break;
      }

    case 3: // 3-�� �����
      {
        address = 0x50;
        break;
      }
#endif
  }

  // ������ ��������
  if ( x < MAX_COL_LCD ) address += x; 

  //ʳ����� �������
  writeValue = 0x80 | ( address & 0x7F );

  unsigned int error_LCD = write_command_to_lcd(writeValue);
  
  return error_LCD;
}
/*****************************************************/

/*****************************************************/
//���� ����� � ������� �������
/*****************************************************/
unsigned int hd44780_puts_xy (unsigned char x, unsigned char y, unsigned char *s)
{
  unsigned int error_LCD = hd44780_gotoxy (x,y);
  if (error_LCD == 0) error_LCD = hd44780_puts (s, MAX_COL_LCD);
  if (error_LCD == 0)
  {
    error_LCD = hd44780_gotoxy (x,y);
    if (error_LCD == 0) error_LCD = hd44780_test (s, MAX_COL_LCD);
  }
  
  return error_LCD;
}
/*****************************************************/

/*****************************************************/
//³���������� ������ ������
/*****************************************************/
void view_whole_ekran(void)
{
  if (current_ekran.current_action != ACTION_WITH_CARRENT_EKRANE_NONE)
  {
    if (
        (_CHECK_SET_BIT(    diagnostyka, ERROR_LCD_BIT) == 0) &&
        (_CHECK_SET_BIT(set_diagnostyka, ERROR_LCD_BIT) == 0)
       )   
    {
      unsigned int error_LCD = 0;
      
      if(current_ekran.current_action == ACTION_WITH_CARRENT_EKRANE_FULL_UPDATE)
      {
        //�������� ����������
        unsigned int i = 0;
        while (
               (i < MAX_ROW_LCD) &&
               (error_LCD == 0 )  
              )
        {
          error_LCD = hd44780_puts_xy(0,i, working_ekran[i]); 
          i++;
        }
      }
    
      //���������� ������ � ������� ������
      if (error_LCD == 0) error_LCD = hd44780_gotoxy ((current_ekran.position_cursor_x & (MAX_COL_LCD -1)),(current_ekran.position_cursor_y & (MAX_ROW_LCD -1)));
      //����������� ���� �������: ��������-���������; ����- �� ����
      if (error_LCD == 0) error_LCD = mode_viewing(1, current_ekran.cursor_on, current_ekran.cursor_blinking_on);

      if (error_LCD != 0) 
      {
        //����������� ����������� ��� �� ����
        _SET_BIT(set_diagnostyka, ERROR_LCD_BIT);
      }
    }
    
    //������ �����������, �� ����� ����� ����� ��������
    current_ekran.current_action = ACTION_WITH_CARRENT_EKRANE_NONE;
  }
}
/*****************************************************/

/*****************************************************/
//���� ������� ��� ������� ����
/*****************************************************/
int index_language_in_array(int language)
{
  int language_tmp = language, result;
  
  if ((language_tmp < LANGUAGE_ABSENT) || (language_tmp > LANGUAGE_KZ))
  {
    language_tmp = LANGUAGE_ABSENT;
  }
    
  switch (language_tmp)
  {
    case LANGUAGE_RU:
      {
        result = INDEX_LANGUAGE_RU;
        break;
      }
    case LANGUAGE_UA:
      {
        result = INDEX_LANGUAGE_UA;
        break;
      }
    case LANGUAGE_EN:
      {
        result = INDEX_LANGUAGE_EN;
        break;
      }
    case LANGUAGE_KZ:
      {
        result = INDEX_LANGUAGE_KZ;
        break;
      }
  default:
    {
      result = INDEX_LANGUAGE_EN;
      break;
    }
  }

        
  //���������� �� �� ����� ��������� ������� ������� �������� ����
  if (
      (current_language == LANGUAGE_ABSENT) ||
      (current_language != language_tmp   )
     )
  {
    unsigned int error_LCD = 0;
    //������� �����
    error_LCD = clear_lcd();

    current_language = language_tmp;
          
    if (
        (error_LCD == 0) &&
        (  
         (current_language == LANGUAGE_EN) ||
         (current_language == LANGUAGE_UA) ||
         (current_language == LANGUAGE_KZ)
        )
       )
    {
      static const unsigned char matrix[13][8] = {
                                           {0x0A, 0x00, 0x0E, 0x04, 0x04, 0x04, 0x0E, 0x00}, // �
                                           {0x00, 0x0A, 0x00, 0x0C, 0x04, 0x04, 0x0E, 0x00}, // �
                                           {0x01, 0x1F, 0x10, 0x10, 0x10, 0x10, 0x10, 0x00}, // �
                                           {0x00, 0x00, 0x01, 0x1F, 0x10, 0x10, 0x10, 0x00}, // �
                                           {0x0E, 0x11, 0x10, 0x1C, 0x10, 0x11, 0x0E, 0x00}, // �
                                           {0x00, 0x00, 0x0E, 0x11, 0x1C, 0x11, 0x0E, 0x00}, // �
                                           {0x0E, 0x11, 0x11, 0x1F, 0x11, 0x11, 0x0E, 0x00}, // � - ������� ������ � ����� ����� ��� WIN1251 ��� ��������� ����
                                           {0x00, 0x00, 0x0E, 0x11, 0x1F, 0x11, 0x0E, 0x00}, // � - ������� ������ � ����� ����� ��� WIN1251 ��� ��������� ����
                                           {0x0E, 0x11, 0x01, 0x1F, 0x11, 0x11, 0x0E, 0x00}, // � - ������� ������ � ����� ����� ��� WIN1251 ��� ��������� ����
                                           {0x00, 0x00, 0x0E, 0x01, 0x1F, 0x11, 0x0E, 0x00}, // � - ������� ������ � ����� ����� ��� WIN1251 ��� ��������� ����
                                           {0x11, 0x11, 0x0A, 0x04, 0x1F, 0x04, 0x04, 0x00}, // � - ������� ������ � ����� ����� ��� WIN1251 ��� ��������� ����
                                           {0x00, 0x00, 0x11, 0x0A, 0x04, 0x1F, 0x04, 0x04},  // � - ������� ������ � ����� ����� ��� WIN1251 ��� ��������� ����
                                           {0x0E, 0x11, 0x11, 0x11, 0x11, 0x0A, 0x1B, 0x00}  // �, �� ��������  ������� ����� ����� ��� ��������� ��������� ���������
                                          }; 
            
      unsigned int number_new_extra_symbols, index_for_symbol;
            
      if (current_language == LANGUAGE_EN)
      {
        number_new_extra_symbols = 1;
        index_for_symbol = 12;
      }
      else if (current_language == LANGUAGE_UA)
      {
        number_new_extra_symbols = 3*2;
        index_for_symbol = 0;
      }
      else
      {
        number_new_extra_symbols = 3*2;
        index_for_symbol = 6;
      }
                                 
      //������������ ������ AC � 0x00 CGRAM
      error_LCD = write_command_to_lcd(0x40 | 0x00);
  
      if (error_LCD == 0)
      {
        //�������� �������� �������
        unsigned int i = 0, j = index_for_symbol, k = 0;
        while(
              (i < number_new_extra_symbols) &&
              (error_LCD == 0)  
             )
        { 
          error_LCD = write_data_to_lcd(matrix[j][k++]);
          if (k >= 8)
          {
            k = 0;
            j++;
            i++;
          }
        }
      }
    }

    if (error_LCD != 0) 
    {
      //����������� ����������� ��� �� ����
      _SET_BIT(set_diagnostyka, ERROR_LCD_BIT);
    }
  }
  
  return result;
}
/*****************************************************/

/*****************************************************/
/*****************************************************/
/*****************************************************/
