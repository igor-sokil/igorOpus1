#ifndef __CONST_MENU_CHOSE_SETTINGS_REGISTRATORS__
#define __CONST_MENU_CHOSE_SETTINGS_REGISTRATORS__

#define EKRAN_VIEW_LIST_OF_REGISTRATORS             (_EKRAN_DATA_TIME_LAST + 1)
#define EKRAN_VIEW_SETTINGS_OF_DIGITAL_REGISTRATORS (EKRAN_VIEW_LIST_OF_REGISTRATORS + 1)
#define EKRAN_RANGUVANNJA_DIGITAL_REGISTRATOR       (EKRAN_VIEW_SETTINGS_OF_DIGITAL_REGISTRATORS + 1)
#define EKRAN_TIMEOUT_DIGITAL_REGISTRATOR           (EKRAN_RANGUVANNJA_DIGITAL_REGISTRATOR  + 1)

#define EKRAN_VIEW_SETTINGS_OF_ANALOG_REGISTRATORS  (EKRAN_TIMEOUT_DIGITAL_REGISTRATOR + 1)
#define EKRAN_RANGUVANNJA_ANALOG_REGISTRATOR        (EKRAN_VIEW_SETTINGS_OF_ANALOG_REGISTRATORS + 1)
#define EKRAN_TIMEOUT_ANALOG_REGISTRATOR            (EKRAN_RANGUVANNJA_ANALOG_REGISTRATOR  + 1)

#define EKRAN_CONTROL_AR                            (EKRAN_TIMEOUT_ANALOG_REGISTRATOR + 1)




#define MAX_ROW_RANGUVANNJA_DIGITAL_REGISTRATOR      TOTAL_SIGNAL_FOR_RNG_BIG
#define MAX_ROW_RANGUVANNJA_ANALOG_REGISTRATOR       TOTAL_SIGNAL_FOR_RNG_BIG


enum _index_ml_list_registrators
{
  INDEX_ML_DIGITAL_REGISTRATOR = 0,
  INDEX_ML_ANALOG_REGISTRATOR,
  
  MAX_ROW_FOR_LIST_OF_REGISTRATORS
};

enum _index_ml_settings_ar
{
  INDEX_ML_SOURCE_ANALOG_REGISTRATOR = 0,
  INDEX_ML_TIMEOUT_ANALOG_REGISTRATOR,
  INDEX_ML_CONTROL_ANALOG_REGISTRATOR,
  
  MAX_ROW_FOR_SETTINGS_OF_ANALOG_REGISTRATOR
};

enum _index_ml_tmo_ar
{
  INDEX_ML_TMOPREFAULT = 0,
  INDEX_ML_TMOPOSTFAULT,
  
  MAX_ROW_FOR_TIMEOUT_ANALOG_REGISTRATOR
};
  
enum _index_ml_ctr_ar
{
  INDEX_ML_CTR_AR_AVAR_STATE = 0,
  
  MAX_ROW_FOR_CONTROL_AR	
};


#define COL_TMO_PREFAULT_BEGIN                       5
#define COL_TMO_PREFAULT_COMMA                       6
#define COL_TMO_PREFAULT_END                         8

#define COL_TMO_POSTFAULT_BEGIN                      4
#define COL_TMO_POSTFAULT_COMMA                      6
#define COL_TMO_POSTFAULT_END                        8


#define CTR_AR_MASKA                               (MASKA_FOR_BIT(MAX_ROW_FOR_CONTROL_AR) - 1)


enum _index_ml_settings_drec
{
  INDEX_ML_SOURCE_DIGITAL_REGISTRATOR = 0,
  INDEX_ML_TIMEOUT_DIGITAL_REGISTRATOR,
  
  
  MAX_ROW_FOR_SETTINGS_OF_DIGITAL_REGISTRATOR
};

enum _index_ml_tmo_drec
{
  INDEX_ML_TMO_ELONGATION = 0,
  
  
  MAX_ROW_FOR_TIMEOUT_DIGITAL_REGISTRATOR
};
  
#define COL_TMO_ELONGATION_BEGIN                      3
#define COL_TMO_ELONGATION_COMMA                      6
#define COL_TMO_ELONGATION_END                        8


#endif
