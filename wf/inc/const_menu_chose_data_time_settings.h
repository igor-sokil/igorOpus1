#ifndef __CONST_MENU_CHOSE_DATA_TIME_SETTINGS__
#define __CONST_MENU_CHOSE_DATA_TIME_SETTINGS__

#define EKRAN_CHOSE_DATA_TIME                    (_EKRAN_COMMUNICATION_PARAMETERS_LAST + 1)
#define EKRAN_TIME_ZONE                          (EKRAN_CHOSE_DATA_TIME + 1)
#define EKRAN_DST_RULE                           (EKRAN_TIME_ZONE + 1)

#define _EKRAN_DATA_TIME_LAST                     EKRAN_DST_RULE


enum _index_ml_data_time_settings
{
  INDEX_ML_CHDT_TIME_ZONE = 0,
  INDEX_ML_CHDT_DST_ON,
  INDEX_ML_CHDT_DST_OFF,

  MAX_ROW_FOR_CHOSE_DATA_TIME_SETTINGS
};

enum _index_ml_timezone_settings
{
  INDEX_ML_TIME_ZONE = 0,
  INDEX_ML_DST,

  MAX_ROW_FOR_TIMEZONE_SETTINGS
  
};

enum _index_ml_dst_rule
{
  INDEX_ML_DST_MM = 0,
  INDEX_ML_DST_DOW,
  INDEX_ML_DST_WR,
  INDEX_ML_DST_HH,
  
  MAX_ROW_FOR_DST_RULE
};

enum _index_mm
{
  _Jan = 1,
  _Feb,
  _Mar,
  _Apr,
  _May,
  _Jun,
  _Jul,
  _Aug,
  _Sept,
  _Oct,
  _Nov,
  _Dec
};

enum _index_dow
{
  _Sun = 0,
  _Mon,
  _Tues,
  _Wed,
  _Thurs,
  _Fri,
  _Sat
};

enum _index_dr
{
  _N1 = 1,
  _N2,
  _N3,
  _N4,
  _NL
};

#define N_BIT_TZ_DST                   (INDEX_ML_DST - INDEX_ML_DST)          

#define CTR_TZ_MASKA                   (                                \
                                        MASKA_FOR_BIT(N_BIT_TZ_DST)     \
                                       )

#define POS_HH          0
#define SHIFT_HH        5

#define POS_DOW         (POS_HH + SHIFT_HH)
#define SHIFT_DOW       3

#define POS_WR          (POS_DOW + SHIFT_DOW)
#define SHIFT_WR        3

#define POS_MM          (POS_WR + SHIFT_WR)
#define SHIFT_MM        4

#endif
