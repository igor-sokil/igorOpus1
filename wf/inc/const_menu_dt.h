#ifndef __CONSTANTS_DEFINED_TRIGGERS__
#define __CONSTANTS_DEFINED_TRIGGERS__

#define EKRAN_LIST_DT                           (EKRAN_RANGUVANNJA_DF16_BLK + 1)
#define EKRAN_SET_RESET_DT1                     (EKRAN_LIST_DT + 1)
#define EKRAN_SET_RESET_DT2                     (EKRAN_SET_RESET_DT1 + 1)
#define EKRAN_SET_RESET_DT3                     (EKRAN_SET_RESET_DT2 + 1)
#define EKRAN_SET_RESET_DT4                     (EKRAN_SET_RESET_DT3 + 1)
#define EKRAN_SET_DT1                           (EKRAN_SET_RESET_DT4 + 1)
#define EKRAN_RESET_DT1                         (EKRAN_SET_DT1 + 1)
#define EKRAN_SET_DT2                           (EKRAN_RESET_DT1 + 1)
#define EKRAN_RESET_DT2                         (EKRAN_SET_DT2 + 1)
#define EKRAN_SET_DT3                           (EKRAN_RESET_DT2 + 1)
#define EKRAN_RESET_DT3                         (EKRAN_SET_DT3 + 1)
#define EKRAN_SET_DT4                           (EKRAN_RESET_DT3 + 1)
#define EKRAN_RESET_DT4                         (EKRAN_SET_DT4 + 1)
#define EKRAN_RANGUVANNJA_SET_DT1_PLUS          (EKRAN_RESET_DT4 + 1)
#define EKRAN_RANGUVANNJA_SET_DT1_MINUS         (EKRAN_RANGUVANNJA_SET_DT1_PLUS + 1)
#define EKRAN_RANGUVANNJA_RESET_DT1_PLUS        (EKRAN_RANGUVANNJA_SET_DT1_MINUS + 1)
#define EKRAN_RANGUVANNJA_RESET_DT1_MINUS       (EKRAN_RANGUVANNJA_RESET_DT1_PLUS + 1)
#define EKRAN_RANGUVANNJA_SET_DT2_PLUS          (EKRAN_RANGUVANNJA_RESET_DT1_MINUS + 1)
#define EKRAN_RANGUVANNJA_SET_DT2_MINUS         (EKRAN_RANGUVANNJA_SET_DT2_PLUS + 1)
#define EKRAN_RANGUVANNJA_RESET_DT2_PLUS        (EKRAN_RANGUVANNJA_SET_DT2_MINUS + 1)
#define EKRAN_RANGUVANNJA_RESET_DT2_MINUS       (EKRAN_RANGUVANNJA_RESET_DT2_PLUS + 1)
#define EKRAN_RANGUVANNJA_SET_DT3_PLUS          (EKRAN_RANGUVANNJA_RESET_DT2_MINUS + 1)
#define EKRAN_RANGUVANNJA_SET_DT3_MINUS         (EKRAN_RANGUVANNJA_SET_DT3_PLUS + 1)
#define EKRAN_RANGUVANNJA_RESET_DT3_PLUS        (EKRAN_RANGUVANNJA_SET_DT3_MINUS + 1)
#define EKRAN_RANGUVANNJA_RESET_DT3_MINUS       (EKRAN_RANGUVANNJA_RESET_DT3_PLUS + 1)
#define EKRAN_RANGUVANNJA_SET_DT4_PLUS          (EKRAN_RANGUVANNJA_RESET_DT3_MINUS + 1)
#define EKRAN_RANGUVANNJA_SET_DT4_MINUS         (EKRAN_RANGUVANNJA_SET_DT4_PLUS + 1)
#define EKRAN_RANGUVANNJA_RESET_DT4_PLUS        (EKRAN_RANGUVANNJA_SET_DT4_MINUS + 1)
#define EKRAN_RANGUVANNJA_RESET_DT4_MINUS       (EKRAN_RANGUVANNJA_RESET_DT4_PLUS + 1)

#define MAX_ROW_FOR_LIST_DT                      NUMBER_DEFINED_TRIGGERS/*((int)current_settings.number_defined_dt)*/
#define MAX_ROW_FOR_LIST_SET_RESET_DT            2
#define MAX_ROW_LIST_TYPE_SOURCE_DT              2
#define MAX_ROW_RANGUVANNJA_DT                   TOTAL_SIGNAL_FOR_RNG_BIG

#define INDEX_ML_SET_DT                          0
#define INDEX_ML_RESET_DT                        1

#define INDEX_ML_LIST_TYPE_SOURCE_PLUS_DT        0
#define INDEX_ML_LIST_TYPE_SOURCE_MINUS_DT       1

#endif 
