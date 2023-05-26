#ifndef __CONST_MENU_MTZR__
#define __CONST_MENU_MTZR__

#define EKRAN_SETPOINT_MTZ_GROUP1   (EKRAN_CHOSE_SETTINGS + 1)
#define EKRAN_SETPOINT_MTZ_GROUP2   (EKRAN_SETPOINT_MTZ_GROUP1 + 1)
#define EKRAN_SETPOINT_MTZ_GROUP3   (EKRAN_SETPOINT_MTZ_GROUP2 + 1)
#define EKRAN_SETPOINT_MTZ_GROUP4   (EKRAN_SETPOINT_MTZ_GROUP3 + 1)
#define EKRAN_TIMEOUT_MTZ_GROUP1    (EKRAN_SETPOINT_UP_GROUP4 + 1)
#define EKRAN_TIMEOUT_MTZ_GROUP2    (EKRAN_TIMEOUT_MTZ_GROUP1  + 1)
#define EKRAN_TIMEOUT_MTZ_GROUP3    (EKRAN_TIMEOUT_MTZ_GROUP2  + 1)
#define EKRAN_TIMEOUT_MTZ_GROUP4    (EKRAN_TIMEOUT_MTZ_GROUP3  + 1)
#define EKRAN_CONTROL_MTZ           (EKRAN_TIMEOUT_UP_GROUP4 + 1)
enum _index_ml_stp_mtzr
{
  INDEX_ML_STPMTZR1 = 0,
  INDEX_ML_STPMTZR1_N_VPERED    ,
  INDEX_ML_STPMTZR1_N_NAZAD     ,
  INDEX_ML_STPMTZR1_ANGLE       ,
  INDEX_ML_STPMTZR1_PO_NAPRUZI  ,
  INDEX_ML_STPMTZR1_U           ,
  INDEX_ML_STPMTZR2             ,
  INDEX_ML_STPMTZR2_N_VPERED    ,
  INDEX_ML_STPMTZR2_N_NAZAD     ,
  INDEX_ML_STPMTZR2_ANGLE       ,
  INDEX_ML_STPMTZR2_PO_NAPRUZI  ,
  INDEX_ML_STPMTZR2_U           ,
//  INDEX_ML_STPMTZO3             ,
//  INDEX_ML_STPMTZO3_N_VPERED    ,
//  INDEX_ML_STPMTZO3_N_NAZAD     ,
//  INDEX_ML_STPMTZO3_ANGLE       ,
//  INDEX_ML_STPMTZO3_PO_NAPRUZI  ,
//  INDEX_ML_STPMTZO3_U           ,
//  INDEX_ML_STPMTZO4             ,
//  INDEX_ML_STPMTZO4_N_VPERED    ,
//  INDEX_ML_STPMTZO4_N_NAZAD     ,
//  INDEX_ML_STPMTZO4_ANGLE       ,
//  INDEX_ML_STPMTZO4_PO_NAPRUZI  ,
//  INDEX_ML_STPMTZO4_U           ,
  

  MAX_ROW_FOR_SETPOINT_MTZR
};

enum _index_ml_tmo_mtzr
{
 
  INDEX_ML_TMOMTZR1                  = 0,
  INDEX_ML_TMOMTZR1_N_VPERED        ,
  INDEX_ML_TMOMTZR1_N_NAZAD         ,
  INDEX_ML_TMOMTZR1_PO_NAPRUZI      ,
//  INDEX_ML_TMOMTZO2                 ,
//  INDEX_ML_TMOMTZO2_PR              ,
//  INDEX_ML_TMOMTZO2_N_VPERED        ,
//  INDEX_ML_TMOMTZO2_N_VPERED_PR     ,
//  INDEX_ML_TMOMTZO2_N_NAZAD         ,
//  INDEX_ML_TMOMTZO2_N_NAZAD_PR      ,
//  INDEX_ML_TMOMTZO2_PO_NAPRUZI      ,
//  INDEX_ML_TMOMTZO2_PO_NAPRUZI_PR   ,
//  INDEX_ML_TMOMTZO2_VVID_PR         ,
  INDEX_ML_TMOMTZR2                 ,
  INDEX_ML_TMOMTZR2_N_VPERED        ,
  INDEX_ML_TMOMTZR2_N_NAZAD         ,
  INDEX_ML_TMOMTZR2_PO_NAPRUZI      ,
//  INDEX_ML_TMOMTZO4                 ,
//  INDEX_ML_TMOMTZO4_N_VPERED        ,
//  INDEX_ML_TMOMTZO4_N_NAZAD         ,
//  INDEX_ML_TMOMTZO4_PO_NAPRUZI      ,

  MAX_ROW_FOR_TIMEOUT_MTZR
};


enum _index_ml_ctrl_mtzr
{
  INDEX_ML_CTRMTZR_1 = 0,
  INDEX_ML_CTRMTZR_1_TYPE          ,
  INDEX_ML_CTRMTZR_1_VPERED        ,
  INDEX_ML_CTRMTZR_1_NAZAD         ,
//  INDEX_ML_CTRMTZO_2               ,
//  INDEX_ML_CTRMTZO_2_TYPE          ,
//  INDEX_ML_CTRMTZO_2_VPERED        ,
//  INDEX_ML_CTRMTZO_2_NAZAD         ,
//  INDEX_ML_CTRMTZO_2_PRYSKORENNJA  ,
//  INDEX_ML_CTRMTZO_2_PRYSKORENA    ,
  INDEX_ML_CTRMTZR_2               ,
  INDEX_ML_CTRMTZR_2_TYPE          ,
  INDEX_ML_CTRMTZR_2_VPERED        ,
  INDEX_ML_CTRMTZR_2_NAZAD         ,
//  INDEX_ML_CTRMTZO_4               ,
//  INDEX_ML_CTRMTZO_4_TYPE          ,
//  INDEX_ML_CTRMTZO_4_VPERED        ,
//  INDEX_ML_CTRMTZO_4_NAZAD         ,
  INDEX_ML_CTRMTZR_NESPR_KIL_NAPR  ,
  
  MAX_ROW_FOR_CONTROL_MTZR
};
  
#define COL_SETPOINT_MTZR_1_BEGIN                3
#define COL_SETPOINT_MTZR_1_COMMA                6
#define COL_SETPOINT_MTZR_1_END                  8

#define COL_SETPOINT_MTZR_1_N_VPERED_BEGIN       3
#define COL_SETPOINT_MTZR_1_N_VPERED_COMMA       6
#define COL_SETPOINT_MTZR_1_N_VPERED_END         8

#define COL_SETPOINT_MTZR_1_N_NAZAD_BEGIN        3
#define COL_SETPOINT_MTZR_1_N_NAZAD_COMMA        6
#define COL_SETPOINT_MTZR_1_N_NAZAD_END          8

#define COL_SETPOINT_MTZR_1_ANGLE_BEGIN          6
#define COL_SETPOINT_MTZR_1_ANGLE_END            7

#define COL_SETPOINT_MTZR_1_PO_NAPRUZI_BEGIN     3
#define COL_SETPOINT_MTZR_1_PO_NAPRUZI_COMMA     6
#define COL_SETPOINT_MTZR_1_PO_NAPRUZI_END       8

#define COL_SETPOINT_MTZR_1_U_BEGIN              3
#define COL_SETPOINT_MTZR_1_U_COMMA              6
#define COL_SETPOINT_MTZR_1_U_END                8

#define COL_SETPOINT_MTZR_2_BEGIN                3
#define COL_SETPOINT_MTZR_2_COMMA                6
#define COL_SETPOINT_MTZR_2_END                  8

#define COL_SETPOINT_MTZR_2_N_VPERED_BEGIN       3
#define COL_SETPOINT_MTZR_2_N_VPERED_COMMA       6
#define COL_SETPOINT_MTZR_2_N_VPERED_END         8

#define COL_SETPOINT_MTZR_2_N_NAZAD_BEGIN        3
#define COL_SETPOINT_MTZR_2_N_NAZAD_COMMA        6
#define COL_SETPOINT_MTZR_2_N_NAZAD_END          8

#define COL_SETPOINT_MTZR_2_ANGLE_BEGIN          6
#define COL_SETPOINT_MTZR_2_ANGLE_END            7

#define COL_SETPOINT_MTZR_2_PO_NAPRUZI_BEGIN     3
#define COL_SETPOINT_MTZR_2_PO_NAPRUZI_COMMA     6
#define COL_SETPOINT_MTZR_2_PO_NAPRUZI_END       8

#define COL_SETPOINT_MTZR_2_U_BEGIN              3
#define COL_SETPOINT_MTZR_2_U_COMMA              6
#define COL_SETPOINT_MTZR_2_U_END                8


#define COL_TMO_MTZR_1_BEGIN                     4
#define COL_TMO_MTZR_1_COMMA                     6
#define COL_TMO_MTZR_1_END                       8

#define COL_TMO_MTZR_1_N_VPERED_BEGIN            4
#define COL_TMO_MTZR_1_N_VPERED_COMMA            6
#define COL_TMO_MTZR_1_N_VPERED_END              8

#define COL_TMO_MTZR_1_N_NAZAD_BEGIN             4
#define COL_TMO_MTZR_1_N_NAZAD_COMMA             6
#define COL_TMO_MTZR_1_N_NAZAD_END               8

#define COL_TMO_MTZR_1_PO_NAPRUZI_BEGIN          4
#define COL_TMO_MTZR_1_PO_NAPRUZI_COMMA          6
#define COL_TMO_MTZR_1_PO_NAPRUZI_END            8


#define COL_TMO_MTZR_2_BEGIN                     3
#define COL_TMO_MTZR_2_COMMA                     6
#define COL_TMO_MTZR_2_END                       8

#define COL_TMO_MTZR_2_N_VPERED_BEGIN            3
#define COL_TMO_MTZR_2_N_VPERED_COMMA            6
#define COL_TMO_MTZR_2_N_VPERED_END              8

#define COL_TMO_MTZR_2_N_NAZAD_BEGIN             3
#define COL_TMO_MTZR_2_N_NAZAD_COMMA             6
#define COL_TMO_MTZR_2_N_NAZAD_END               8

#define COL_TMO_MTZR_2_PO_NAPRUZI_BEGIN          3
#define COL_TMO_MTZR_2_PO_NAPRUZI_COMMA          6
#define COL_TMO_MTZR_2_PO_NAPRUZI_END            8

  

#define N_BIT_CTRMTZR_1                          (INDEX_ML_CTRMTZR_1 - 0)          
#define CTR_MTZR_1                               (1 << N_BIT_CTRMTZR_1)          
#define N_BIT_CTRMTZR_1_VPERED                   (INDEX_ML_CTRMTZR_1_VPERED - 1)          
#define CTR_MTZR_1_VPERED                        (1 << N_BIT_CTRMTZR_1_VPERED)          
#define N_BIT_CTRMTZR_1_NAZAD                    (INDEX_ML_CTRMTZR_1_NAZAD - 1)          
#define CTR_MTZR_1_NAZAD                         (1 << N_BIT_CTRMTZR_1_NAZAD)          
#define N_BIT_CTRMTZR_2                          (INDEX_ML_CTRMTZR_2 - 1)        
 
//#define N_BIT_CTRMTZ_3                          (INDEX_ML_CTRMTZ_3 - 2)         
#define CTR_MTZR_2                               (1 << N_BIT_CTRMTZR_2)          
#define N_BIT_CTRMTZR_2_VPERED                   (INDEX_ML_CTRMTZR_2_VPERED - 1)          
#define CTR_MTZR_2_VPERED                        (1 << N_BIT_CTRMTZR_2_VPERED)          
#define N_BIT_CTRMTZR_2_NAZAD                    (INDEX_ML_CTRMTZR_2_NAZAD - 1)          
#define CTR_MTZR_2_NAZAD                         (1 << N_BIT_CTRMTZR_2_NAZAD)          

#define N_BIT_CTRMTZR_NESPR_KIL_NAPR             (INDEX_ML_CTRMTZR_NESPR_KIL_NAPR-1)
#define CTR_MTZR_NESPR_KIL_NAPR                  (1 << N_BIT_CTRMTZR_NESPR_KIL_NAPR)          

enum {
  CTR_MTZR = 0,
  CTR_MTZR_VPERED,
  CTR_MTZR_NAZAD,
  /*************************************/
  MTZR_CONST_MENU_SETTINGS_LENGTH
};

#define CTR_MTZR_MASKA                   (                                \
                                         CTR_MTZR_1                      |\
                                         CTR_MTZR_1_VPERED               |\
                                         CTR_MTZR_1_NAZAD                |\
                                         CTR_MTZR_2                      |\
                                         CTR_MTZR_2_VPERED               |\
                                         CTR_MTZR_2_NAZAD                |\
										 CTR_MTZR_NESPR_KIL_NAPR           \
										 )
//                                         CTR_MTZR_2_PRYSKORENNJA         |\
//                                         CTR_MTZR_2_PRYSKORENA           |\
//                                         CTR_MTZ_3                      |\
//                                         CTR_MTZ_3_VPERED               |\
//                                         CTR_MTZ_3_NAZAD                |\
//                                         CTR_MTZ_4                      |\
//                                         CTR_MTZ_4_VPERED               |\
//                                         CTR_MTZ_4_NAZAD                |\
//                                         CTR_MTZ_NESPR_KIL_NAPR          \
//                                         )

#endif
