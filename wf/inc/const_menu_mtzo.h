#ifndef __CONST_MENU_MTZO__
#define __CONST_MENU_MTZO__

#define EKRAN_SETPOINT_MTZ_GROUP1   (EKRAN_CHOSE_SETTINGS + 1)
#define EKRAN_SETPOINT_MTZ_GROUP2   (EKRAN_SETPOINT_MTZ_GROUP1 + 1)
#define EKRAN_SETPOINT_MTZ_GROUP3   (EKRAN_SETPOINT_MTZ_GROUP2 + 1)
#define EKRAN_SETPOINT_MTZ_GROUP4   (EKRAN_SETPOINT_MTZ_GROUP3 + 1)
#define EKRAN_TIMEOUT_MTZ_GROUP1    (EKRAN_SETPOINT_UP_GROUP4 + 1)
#define EKRAN_TIMEOUT_MTZ_GROUP2    (EKRAN_TIMEOUT_MTZ_GROUP1  + 1)
#define EKRAN_TIMEOUT_MTZ_GROUP3    (EKRAN_TIMEOUT_MTZ_GROUP2  + 1)
#define EKRAN_TIMEOUT_MTZ_GROUP4    (EKRAN_TIMEOUT_MTZ_GROUP3  + 1)
#define EKRAN_CONTROL_MTZ           (EKRAN_TIMEOUT_UP_GROUP4 + 1)


enum _index_ml_stp_mtzo
{
  INDEX_ML_STPMTZO1 = 0,
  INDEX_ML_STPMTZO1_N_VPERED    ,
  INDEX_ML_STPMTZO1_N_NAZAD     ,
  INDEX_ML_STPMTZO1_ANGLE       ,
  INDEX_ML_STPMTZO1_PO_NAPRUZI  ,
  INDEX_ML_STPMTZO1_U           ,
  INDEX_ML_STPMTZO2             ,
  INDEX_ML_STPMTZO2_N_VPERED    ,
  INDEX_ML_STPMTZO2_N_NAZAD     ,
  INDEX_ML_STPMTZO2_ANGLE       ,
  INDEX_ML_STPMTZO2_PO_NAPRUZI  ,
  INDEX_ML_STPMTZO2_U           ,
  INDEX_ML_STPMTZO3             ,
  INDEX_ML_STPMTZO3_N_VPERED    ,
  INDEX_ML_STPMTZO3_N_NAZAD     ,
  INDEX_ML_STPMTZO3_ANGLE       ,
  INDEX_ML_STPMTZO3_PO_NAPRUZI  ,
  INDEX_ML_STPMTZO3_U           ,
  INDEX_ML_STPMTZO4             ,
  INDEX_ML_STPMTZO4_N_VPERED    ,
  INDEX_ML_STPMTZO4_N_NAZAD     ,
  INDEX_ML_STPMTZO4_ANGLE       ,
  INDEX_ML_STPMTZO4_PO_NAPRUZI  ,
  INDEX_ML_STPMTZO4_U           ,
  

  MAX_ROW_FOR_SETPOINT_MTZO
};

enum _index_ml_tmo_mtzo
{
 
  INDEX_ML_TMOMTZO1                  = 0,
  INDEX_ML_TMOMTZO1_N_VPERED        ,
  INDEX_ML_TMOMTZO1_N_NAZAD         ,
  INDEX_ML_TMOMTZO1_PO_NAPRUZI      ,
  INDEX_ML_TMOMTZO2                 ,
  INDEX_ML_TMOMTZO2_PR              ,
  INDEX_ML_TMOMTZO2_N_VPERED        ,
  INDEX_ML_TMOMTZO2_N_VPERED_PR     ,
  INDEX_ML_TMOMTZO2_N_NAZAD         ,
  INDEX_ML_TMOMTZO2_N_NAZAD_PR      ,
  INDEX_ML_TMOMTZO2_PO_NAPRUZI      ,
  INDEX_ML_TMOMTZO2_PO_NAPRUZI_PR   ,
  INDEX_ML_TMOMTZO2_VVID_PR         ,
  INDEX_ML_TMOMTZO3                 ,
  INDEX_ML_TMOMTZO3_N_VPERED        ,
  INDEX_ML_TMOMTZO3_N_NAZAD         ,
  INDEX_ML_TMOMTZO3_PO_NAPRUZI      ,
  INDEX_ML_TMOMTZO4                 ,
  INDEX_ML_TMOMTZO4_N_VPERED        ,
  INDEX_ML_TMOMTZO4_N_NAZAD         ,
  INDEX_ML_TMOMTZO4_PO_NAPRUZI      ,

  MAX_ROW_FOR_TIMEOUT_MTZO
};


enum _index_ml_ctrl_mtzo
{
  INDEX_ML_CTRMTZO_1 = 0,
  INDEX_ML_CTRMTZO_1_TYPE          ,
  INDEX_ML_CTRMTZO_1_VPERED        ,
  INDEX_ML_CTRMTZO_1_NAZAD         ,
  INDEX_ML_CTRMTZO_2               ,
  INDEX_ML_CTRMTZO_2_TYPE          ,
  INDEX_ML_CTRMTZO_2_VPERED        ,
  INDEX_ML_CTRMTZO_2_NAZAD         ,
  INDEX_ML_CTRMTZO_2_PRYSKORENNJA  ,
  INDEX_ML_CTRMTZO_2_PRYSKORENA    ,
  INDEX_ML_CTRMTZO_3               ,
  INDEX_ML_CTRMTZO_3_TYPE          ,
  INDEX_ML_CTRMTZO_3_VPERED        ,
  INDEX_ML_CTRMTZO_3_NAZAD         ,
  INDEX_ML_CTRMTZO_4               ,
  INDEX_ML_CTRMTZO_4_TYPE          ,
  INDEX_ML_CTRMTZO_4_VPERED        ,
  INDEX_ML_CTRMTZO_4_NAZAD         ,
  INDEX_ML_CTRMTZO_NESPR_KIL_NAPR  ,
  
  MAX_ROW_FOR_CONTROL_MTZO
};
  
#define COL_SETPOINT_MTZO_1_BEGIN                3
#define COL_SETPOINT_MTZO_1_COMMA                6
#define COL_SETPOINT_MTZO_1_END                  8

#define COL_SETPOINT_MTZO_1_N_VPERED_BEGIN       3
#define COL_SETPOINT_MTZO_1_N_VPERED_COMMA       6
#define COL_SETPOINT_MTZO_1_N_VPERED_END         8

#define COL_SETPOINT_MTZO_1_N_NAZAD_BEGIN        3
#define COL_SETPOINT_MTZO_1_N_NAZAD_COMMA        6
#define COL_SETPOINT_MTZO_1_N_NAZAD_END          8

#define COL_SETPOINT_MTZO_1_ANGLE_BEGIN          6
#define COL_SETPOINT_MTZO_1_ANGLE_END            7

#define COL_SETPOINT_MTZO_1_PO_NAPRUZI_BEGIN     3
#define COL_SETPOINT_MTZO_1_PO_NAPRUZI_COMMA     6
#define COL_SETPOINT_MTZO_1_PO_NAPRUZI_END       8

#define COL_SETPOINT_MTZO_1_U_BEGIN              3
#define COL_SETPOINT_MTZO_1_U_COMMA              6
#define COL_SETPOINT_MTZO_1_U_END                8

#define COL_SETPOINT_MTZO_2_BEGIN                3
#define COL_SETPOINT_MTZO_2_COMMA                6
#define COL_SETPOINT_MTZO_2_END                  8

#define COL_SETPOINT_MTZO_2_N_VPERED_BEGIN       3
#define COL_SETPOINT_MTZO_2_N_VPERED_COMMA       6
#define COL_SETPOINT_MTZO_2_N_VPERED_END         8

#define COL_SETPOINT_MTZO_2_N_NAZAD_BEGIN        3
#define COL_SETPOINT_MTZO_2_N_NAZAD_COMMA        6
#define COL_SETPOINT_MTZO_2_N_NAZAD_END          8

#define COL_SETPOINT_MTZO_2_ANGLE_BEGIN          6
#define COL_SETPOINT_MTZO_2_ANGLE_END            7

#define COL_SETPOINT_MTZO_2_PO_NAPRUZI_BEGIN     3
#define COL_SETPOINT_MTZO_2_PO_NAPRUZI_COMMA     6
#define COL_SETPOINT_MTZO_2_PO_NAPRUZI_END       8

#define COL_SETPOINT_MTZO_2_U_BEGIN              3
#define COL_SETPOINT_MTZO_2_U_COMMA              6
#define COL_SETPOINT_MTZO_2_U_END                8

#define COL_SETPOINT_MTZO_3_BEGIN                3
#define COL_SETPOINT_MTZO_3_COMMA                6
#define COL_SETPOINT_MTZO_3_END                  8

#define COL_SETPOINT_MTZO_3_N_VPERED_BEGIN       3
#define COL_SETPOINT_MTZO_3_N_VPERED_COMMA       6
#define COL_SETPOINT_MTZO_3_N_VPERED_END         8

#define COL_SETPOINT_MTZO_3_N_NAZAD_BEGIN        3
#define COL_SETPOINT_MTZO_3_N_NAZAD_COMMA        6
#define COL_SETPOINT_MTZO_3_N_NAZAD_END          8

#define COL_SETPOINT_MTZO_3_ANGLE_BEGIN          6
#define COL_SETPOINT_MTZO_3_ANGLE_END            7

#define COL_SETPOINT_MTZO_3_PO_NAPRUZI_BEGIN     3
#define COL_SETPOINT_MTZO_3_PO_NAPRUZI_COMMA     6
#define COL_SETPOINT_MTZO_3_PO_NAPRUZI_END       8

#define COL_SETPOINT_MTZO_3_U_BEGIN              3
#define COL_SETPOINT_MTZO_3_U_COMMA              6
#define COL_SETPOINT_MTZO_3_U_END                8

#define COL_SETPOINT_MTZO_4_BEGIN                3
#define COL_SETPOINT_MTZO_4_COMMA                6
#define COL_SETPOINT_MTZO_4_END                  8

#define COL_SETPOINT_MTZO_4_N_VPERED_BEGIN       3
#define COL_SETPOINT_MTZO_4_N_VPERED_COMMA       6
#define COL_SETPOINT_MTZO_4_N_VPERED_END         8

#define COL_SETPOINT_MTZO_4_N_NAZAD_BEGIN        3
#define COL_SETPOINT_MTZO_4_N_NAZAD_COMMA        6
#define COL_SETPOINT_MTZO_4_N_NAZAD_END          8

#define COL_SETPOINT_MTZO_4_ANGLE_BEGIN          6
#define COL_SETPOINT_MTZO_4_ANGLE_END            7

#define COL_SETPOINT_MTZO_4_PO_NAPRUZI_BEGIN     3
#define COL_SETPOINT_MTZO_4_PO_NAPRUZI_COMMA     6
#define COL_SETPOINT_MTZO_4_PO_NAPRUZI_END       8

#define COL_SETPOINT_MTZO_4_U_BEGIN              3
#define COL_SETPOINT_MTZO_4_U_COMMA              6
#define COL_SETPOINT_MTZO_4_U_END                8

#define COL_TMO_MTZO_1_BEGIN                     4
#define COL_TMO_MTZO_1_COMMA                     6
#define COL_TMO_MTZO_1_END                       8

#define COL_TMO_MTZO_1_N_VPERED_BEGIN            4
#define COL_TMO_MTZO_1_N_VPERED_COMMA            6
#define COL_TMO_MTZO_1_N_VPERED_END              8

#define COL_TMO_MTZO_1_N_NAZAD_BEGIN             4
#define COL_TMO_MTZO_1_N_NAZAD_COMMA             6
#define COL_TMO_MTZO_1_N_NAZAD_END               8

#define COL_TMO_MTZO_1_PO_NAPRUZI_BEGIN          4
#define COL_TMO_MTZO_1_PO_NAPRUZI_COMMA          6
#define COL_TMO_MTZO_1_PO_NAPRUZI_END            8

#define COL_TMO_MTZO_2_BEGIN                     3
#define COL_TMO_MTZO_2_COMMA                     6
#define COL_TMO_MTZO_2_END                       8

#define COL_TMO_MTZO_2_PR_BEGIN                  5
#define COL_TMO_MTZO_2_PR_COMMA                  6
#define COL_TMO_MTZO_2_PR_END                    8

#define COL_TMO_MTZO_2_N_VPERED_BEGIN            3
#define COL_TMO_MTZO_2_N_VPERED_COMMA            6
#define COL_TMO_MTZO_2_N_VPERED_END              8

#define COL_TMO_MTZO_2_N_VPERED_PR_BEGIN         5
#define COL_TMO_MTZO_2_N_VPERED_PR_COMMA         6
#define COL_TMO_MTZO_2_N_VPERED_PR_END           8

#define COL_TMO_MTZO_2_N_NAZAD_BEGIN             3
#define COL_TMO_MTZO_2_N_NAZAD_COMMA             6
#define COL_TMO_MTZO_2_N_NAZAD_END               8

#define COL_TMO_MTZO_2_N_NAZAD_PR_BEGIN          5
#define COL_TMO_MTZO_2_N_NAZAD_PR_COMMA          6
#define COL_TMO_MTZO_2_N_NAZAD_PR_END            8

#define COL_TMO_MTZO_2_PO_NAPRUZI_BEGIN          3
#define COL_TMO_MTZO_2_PO_NAPRUZI_COMMA          6
#define COL_TMO_MTZO_2_PO_NAPRUZI_END            8

#define COL_TMO_MTZO_2_PO_NAPRUZI_PR_BEGIN       5
#define COL_TMO_MTZO_2_PO_NAPRUZI_PR_COMMA       6
#define COL_TMO_MTZO_2_PO_NAPRUZI_PR_END         8

#define COL_TMO_MTZO_2_VVID_PR_BEGIN             5
#define COL_TMO_MTZO_2_VVID_PR_COMMA             6
#define COL_TMO_MTZO_2_VVID_PR_END               8

#define COL_TMO_MTZO_3_BEGIN                     3
#define COL_TMO_MTZO_3_COMMA                     6
#define COL_TMO_MTZO_3_END                       8

#define COL_TMO_MTZO_3_N_VPERED_BEGIN            3
#define COL_TMO_MTZO_3_N_VPERED_COMMA            6
#define COL_TMO_MTZO_3_N_VPERED_END              8

#define COL_TMO_MTZO_3_N_NAZAD_BEGIN             3
#define COL_TMO_MTZO_3_N_NAZAD_COMMA             6
#define COL_TMO_MTZO_3_N_NAZAD_END               8

#define COL_TMO_MTZO_3_PO_NAPRUZI_BEGIN          3
#define COL_TMO_MTZO_3_PO_NAPRUZI_COMMA          6
#define COL_TMO_MTZO_3_PO_NAPRUZI_END            8

#define COL_TMO_MTZO_4_BEGIN                     3
#define COL_TMO_MTZO_4_COMMA                     6
#define COL_TMO_MTZO_4_END                       8

#define COL_TMO_MTZO_4_N_VPERED_BEGIN            3
#define COL_TMO_MTZO_4_N_VPERED_COMMA            6
#define COL_TMO_MTZO_4_N_VPERED_END              8

#define COL_TMO_MTZO_4_N_NAZAD_BEGIN             3
#define COL_TMO_MTZO_4_N_NAZAD_COMMA             6
#define COL_TMO_MTZO_4_N_NAZAD_END               8

#define COL_TMO_MTZO_4_PO_NAPRUZI_BEGIN          3
#define COL_TMO_MTZO_4_PO_NAPRUZI_COMMA          6
#define COL_TMO_MTZO_4_PO_NAPRUZI_END            8

   

#define N_BIT_CTRMTZO_1                          (INDEX_ML_CTRMTZO_1 - 0)          
#define CTR_MTZO_1                               (1 << N_BIT_CTRMTZO_1)          
#define N_BIT_CTRMTZO_1_VPERED                   (INDEX_ML_CTRMTZO_1_VPERED - 1)          
#define CTR_MTZO_1_VPERED                        (1 << N_BIT_CTRMTZO_1_VPERED)          
#define N_BIT_CTRMTZO_1_NAZAD                    (INDEX_ML_CTRMTZO_1_NAZAD - 1)          
#define CTR_MTZO_1_NAZAD                         (1 << N_BIT_CTRMTZO_1_NAZAD)          
#define N_BIT_CTRMTZO_2                          (INDEX_ML_CTRMTZO_2 - 1)        
#define CTR_MTZO_2                               (1 << N_BIT_CTRMTZO_2)          
#define N_BIT_CTRMTZO_2_VPERED                   (INDEX_ML_CTRMTZO_2_VPERED - 2)          
#define CTR_MTZO_2_VPERED                        (1 << N_BIT_CTRMTZO_2_VPERED)          
#define N_BIT_CTRMTZO_2_NAZAD                    (INDEX_ML_CTRMTZO_2_NAZAD - 2)          
#define CTR_MTZO_2_NAZAD                         (1 << N_BIT_CTRMTZO_2_NAZAD)          
#define N_BIT_CTRMTZO_2_PRYSKORENNJA             (INDEX_ML_CTRMTZO_2_PRYSKORENNJA - 2)         
#define CTR_MTZO_2_PRYSKORENNJA                  (1 << N_BIT_CTRMTZO_2_PRYSKORENNJA)      
#define N_BIT_CTRMTZO_2_PRYSKORENA               (INDEX_ML_CTRMTZO_2_PRYSKORENA - 2)          
#define CTR_MTZO_2_PRYSKORENA                    (1 << N_BIT_CTRMTZO_2_PRYSKORENA)          
#define N_BIT_CTRMTZO_3                          (INDEX_ML_CTRMTZO_3 - 2)         
#define CTR_MTZO_3                               (1 << N_BIT_CTRMTZO_3)          
#define N_BIT_CTRMTZO_3_VPERED                   (INDEX_ML_CTRMTZO_3_VPERED - 3)          
#define CTR_MTZO_3_VPERED                        (1 << N_BIT_CTRMTZO_3_VPERED)          
#define N_BIT_CTRMTZO_3_NAZAD                    (INDEX_ML_CTRMTZO_3_NAZAD - 3)          
#define CTR_MTZO_3_NAZAD                         (1 << N_BIT_CTRMTZO_3_NAZAD)          
#define N_BIT_CTRMTZO_4                          (INDEX_ML_CTRMTZO_4 - 3)         
#define CTR_MTZO_4                               (1 << N_BIT_CTRMTZO_4)          
#define N_BIT_CTRMTZO_4_VPERED                   (INDEX_ML_CTRMTZO_4_VPERED - 4)         
#define CTR_MTZO_4_VPERED                        (1 << N_BIT_CTRMTZO_4_VPERED)          
#define N_BIT_CTRMTZO_4_NAZAD                    (INDEX_ML_CTRMTZO_4_NAZAD - 4)         
#define CTR_MTZO_4_NAZAD                         (1 << N_BIT_CTRMTZO_4_NAZAD)          
#define N_BIT_CTRMTZO_NESPR_KIL_NAPR             (INDEX_ML_CTRMTZO_NESPR_KIL_NAPR - 4)      
#define CTR_MTZO_NESPR_KIL_NAPR                  (1 << N_BIT_CTRMTZO_NESPR_KIL_NAPR)          

enum {
  CTR_MTZO = 0,
  CTR_MTZO_VPERED,
  CTR_MTZO_NAZAD,
  /*************************************/
  MTZO_CONST_MENU_SETTINGS_LENGTH
};

//#define CTR_MTZ_MASKA                   (                                \
//                                         CTR_MTZ_1                      |\
//                                         CTR_MTZ_1_VPERED               |\
//                                         CTR_MTZ_1_NAZAD                |\
//                                         CTR_MTZ_2                      |\
//                                         CTR_MTZ_2_VPERED               |\
//                                         CTR_MTZ_2_NAZAD                |\
//                                         CTR_MTZ_2_PRYSKORENNJA         |\
//                                         CTR_MTZ_2_PRYSKORENA           |\
//                                         CTR_MTZ_3                      |\
//                                         CTR_MTZ_3_VPERED               |\
//                                         CTR_MTZ_3_NAZAD                |\
//                                         CTR_MTZ_4                      |\
//                                         CTR_MTZ_4_VPERED               |\
//                                         CTR_MTZ_4_NAZAD                |\
//                                         CTR_MTZ_NESPR_KIL_NAPR          \
//                                         )
#define CTR_MTZO_MASKA                   (                                \
                                         CTR_MTZO_1                      |\
                                         CTR_MTZO_1_VPERED               |\
                                         CTR_MTZO_1_NAZAD                |\
                                         CTR_MTZO_2                      |\
                                         CTR_MTZO_2_VPERED               |\
                                         CTR_MTZO_2_NAZAD                |\
                                         CTR_MTZO_2_PRYSKORENNJA         |\
                                         CTR_MTZO_2_PRYSKORENA           |\
                                         CTR_MTZO_3                      |\
                                         CTR_MTZO_3_VPERED               |\
                                         CTR_MTZO_3_NAZAD                |\
                                         CTR_MTZO_4                      |\
                                         CTR_MTZO_4_VPERED               |\
                                         CTR_MTZO_4_NAZAD                |\
                                         CTR_MTZO_NESPR_KIL_NAPR          \
                                         )

#endif
