#ifndef __CONST_MENU_REGISTRATORS__
#define __CONST_MENU_REGISTRATORS__

#define EKRAN_LIST_REGISTRATORS                       (EKRAN_VIEW_SETTING_LANGUAGE + 1)
#define EKRAN_LIST_ANALOG_REGISTRATOR_RECORDS         (EKRAN_LIST_REGISTRATORS + 1)
#define EKRAN_LIST_DIGITAL_REGISTRATOR_RECORDS        (EKRAN_LIST_ANALOG_REGISTRATOR_RECORDS + 1)
#define EKRAN_LIST_REGISTRATOR_PROGRAM_ERROR_RECORDS  (EKRAN_LIST_DIGITAL_REGISTRATOR_RECORDS + 1)

#define EKRAN_TITLES_DIGITAL_REGISTRATOR              (EKRAN_LIST_REGISTRATOR_PROGRAM_ERROR_RECORDS + 1)
#define EKRAN_CHANGES_SIGNALS_DR                      (EKRAN_TITLES_DIGITAL_REGISTRATOR + 1)
#define EKRAN_TITLE_MAX_VALUES                        (EKRAN_CHANGES_SIGNALS_DR + 1)
#define EKRAN_MAX_VALUES                              (EKRAN_TITLE_MAX_VALUES + 1)
#define EKRAN_CHANGES_DIAGNOSTICS_PR_ERR              (EKRAN_MAX_VALUES + 1)

#define MAX_ROW_FOR_LIST_REGISTRATORS                 3
#define MAX_ROW_FOR_LIST_REGISTRATORS_RECORDS         MAX_ROW_LCD
#define MAX_ROW_FOR_EKRAN_DATA_LABEL                  2
#define MAX_ROW_FOR_TITLE_EKRAN_ANALOG_VALUES_DR      MAX_ROW_LCD
#define MAX_ROW_FOR_EKRAN_ANALOG_VALUES_DR            (SIZE_ARRAY_FIX_MAX_MEASUREMENTS - 2)
#define MAX_ROW_FOR_TITLES_PR_ERR_REGISTRATOR         2

#define INDEX_ML_ANALOG_REGISTRATOR_INFO        0
#define INDEX_ML_DIGITAL_REGISTRATOR_INFO       1
#define INDEX_ML_PROGRAM_ERROE_REGISTRATOR_INFO 2

enum _index_title_dr
{
  INDEX_ML_TITLE_DR_CHANGES_SIGNALS = 0,
  INDEX_ML_TITLE_DR_MAX_PHASE_O,
  INDEX_ML_TITLE_DR_MAX_PHASE_R,
  INDEX_ML_TITLE_DR_MIN_U,
  INDEX_ML_TITLE_DR_MAX_U,
  INDEX_ML_TITLE_DR_MIN_R_O,
  INDEX_ML_TITLE_DR_MIN_R_R,
  INDEX_ML_TITLE_DR_MIN_F1,
  INDEX_ML_TITLE_DR_MIN_F2,
    
  MAX_ROW_FOR_TITLES_DIGITAL_REGISTRATOR
    
};

#define ROW_R_Y_                                  ROW_Y_
#define COL_DY1_R                                 COL_DY1
#define COL_DY2_R                                 COL_DY2

#define COL_MY1_R                                 COL_MY1
#define COL_MY2_R                                 COL_MY2

#define COL_SY1_R                                 COL_SY1
#define COL_SY2_R                                 COL_SY2

#define ROW_R_T_                                  ROW_T_
#define COL_HT1_R                                 2
#define COL_HT2_R                                 3

#define COL_MT1_R                                 5
#define COL_MT2_R                                 6

#define COL_ST1_R                                 8
#define COL_ST2_R                                 9

#define COL_HST1_R                                11
#define COL_HST2_R                                12
#define COL_HST3_R                                13


#endif
