#ifndef __CONST_LCD_AND_KEYBOARD__
#define __CONST_LCD_AND_KEYBOARD__

#define MAX_LEVEL_MENU          (274 + NUMBER_INPUTS + NUMBER_OUTPUTS + NUMBER_LEDS + 5*NUMBER_DEFINED_FUNCTIONS + 7*NUMBER_DEFINED_TRIGGERS + NUMBER_DEFINED_AND + NUMBER_DEFINED_OR + NUMBER_DEFINED_XOR + NUMBER_DEFINED_NOT + NUMBER_TRANSFER_FUNCTIONS + NUMBER_DEFINED_BUTTONS)   //Максимальна кількість допустимих вікон у системі меню
#define MAX_TIME_REWRITE_EKRAN  100 //x10 - Максимальний час у мс для автоматичного обновлення екранів меню, які треба обновляти

enum _index_viewing
{
  INDEX_VIEWING_DF = 0,
  INDEX_VIEWING_OUTPUT,
  INDEX_VIEWING_LED,
  INDEX_VIEWING_A_REG,
  INDEX_VIEWING_D_REG,
  INDEX_VIEWING_OFF_CB,
  INDEX_VIEWING_ON_CB,
  INDEX_VIEWING_DT,
  INDEX_VIEWING_D_AND,
  INDEX_VIEWING_D_OR,
  INDEX_VIEWING_D_XOR,
  INDEX_VIEWING_D_NOT,

  INDEX_VIEWING_BUTTON,
  INDEX_VIEWING_INPUT,
  INDEX_VIEWING_OFF_CB_H,
  INDEX_VIEWING_ON_CB_H,
  INDEX_VIEWING_OFF_CB_L,
  INDEX_VIEWING_ON_CB_L
};

#define LCD_BASE          Bank1_SRAM3_ADDR

#define POWER_MAX_COL_LCD       4
#define POWER_MAX_ROW_LCD       2
#define MAX_COL_LCD       (1<<POWER_MAX_COL_LCD)
#define MAX_ROW_LCD       (1<<POWER_MAX_ROW_LCD)

#define BF_BIT            7

#define NUMBER_KEY_KEYBOARD (4*4)
#define DEREVIACIA          8

#define BIT_KEY_ENTER           0
#define BIT_KEY_DOWN            1
#define BIT_KEY_RIGHT           2
#define BIT_KEY_ESC             3
#define BIT_KEY_LEFT            4
#define BIT_KEY_UP              5
#define BIT_KEY_1               6
#define BIT_KEY_2               7
#define BIT_KEY_3               8
#define BIT_KEY_4               9
#define BIT_KEY_5               10
#define BIT_KEY_6               11
#define BIT_KEY_C               12
#define BIT_KEY_I               13
#define BIT_KEY_O               14

#define BIT_REWRITE             30

#define ACTION_WITH_CARRENT_EKRANE_NONE                      0
#define ACTION_WITH_CARRENT_EKRANE_ONLY_CHANGE_CURSOR        1
#define ACTION_WITH_CARRENT_EKRANE_FULL_UPDATE   2

#endif
