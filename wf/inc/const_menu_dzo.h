#ifndef __CONST_MENU_DZO__
#define __CONST_MENU_DZO__

#define EKRAN_SETPOINT_DZO_GROUP1   (EKRAN_SETPOINT_MTZ_GROUP4 + 1)
#define EKRAN_SETPOINT_DZO_GROUP2   (EKRAN_SETPOINT_DZ_GROUP1 + 1)
#define EKRAN_SETPOINT_DZO_GROUP3   (EKRAN_SETPOINT_DZ_GROUP2 + 1)
#define EKRAN_SETPOINT_DZO_GROUP4   (EKRAN_SETPOINT_DZ_GROUP3 + 1)
#define EKRAN_TIMEOUT_DZO_GROUP1    (EKRAN_TIMEOUT_MTZ_GROUP4 + 1)
#define EKRAN_TIMEOUT_DZO_GROUP2    (EKRAN_TIMEOUT_DZ_GROUP1  + 1)
#define EKRAN_TIMEOUT_DZO_GROUP3    (EKRAN_TIMEOUT_DZ_GROUP2  + 1)
#define EKRAN_TIMEOUT_DZO_GROUP4    (EKRAN_TIMEOUT_DZ_GROUP3  + 1)
#define EKRAN_CONTROL_DZO           (EKRAN_CONTROL_MTZ + 1)

enum _index_ml_stp_dzo
{
  INDEX_ML_STP_K_ICE_DZO = 0,
  
  INDEX_ML_STP_DZO1,
  INDEX_ML_STP_DZO1_AMTZ,
  INDEX_ML_STP_DZO1_I_BLK,
  
  INDEX_ML_STP_DZO2_ANGLE,
  INDEX_ML_STP_DZO2_DIR,
  INDEX_ML_STP_DZO2_INV,
  INDEX_ML_STP_DZO2_AMTZ,
  
  INDEX_ML_STP_DZO3_ANGLE_H,
  INDEX_ML_STP_DZO3_ANGLE_L,
  INDEX_ML_STP_DZO3_DIR,
  INDEX_ML_STP_DZO3_INV,
  INDEX_ML_STP_DZO3_AMTZ,
  
  
  INDEX_ML_STP_DZO4_Z0_DIR,
  INDEX_ML_STP_DZO4_X0_DIR,
  INDEX_ML_STP_DZO4_Z0_INV,
  INDEX_ML_STP_DZO4_X0_INV,
  INDEX_ML_STP_DZO4_AMTZ,
   
  MAX_ROW_FOR_SETPOINT_DZO
};

enum _index_ml_tmp_dzo
{
  INDEX_ML_TMO_DZO1 = 0,
  INDEX_ML_TMO_DZO1_AMTZ,
  
  INDEX_ML_TMO_DZO2_DIR,
  INDEX_ML_TMO_DZO2_DIR_PR,
  INDEX_ML_TMO_DZO2_INV,
  INDEX_ML_TMO_DZO2_INV_PR,
  INDEX_ML_TMO_DZO2_AMTZ,
  INDEX_ML_TMO_DZO2_AMTZ_PR,
  INDEX_ML_TMO_DZO2_VVID_PR,
  INDEX_ML_TMO_DZO2_AMTZ_VVID_PR,
  
  INDEX_ML_TMO_DZO3_DIR,
  INDEX_ML_TMO_DZO3_DIR_PR,
  INDEX_ML_TMO_DZO3_INV,
  INDEX_ML_TMO_DZO3_INV_PR,
  INDEX_ML_TMO_DZO3_AMTZ,
  INDEX_ML_TMO_DZO3_AMTZ_PR,
  INDEX_ML_TMO_DZO3_VVID_PR,
  INDEX_ML_TMO_DZO3_AMTZ_VVID_PR,
  
  INDEX_ML_TMO_DZO4_DIR,
  INDEX_ML_TMO_DZO4_INV,
  INDEX_ML_TMO_DZO4_AMTZ,


  INDEX_ML_TMO_NKN_DZO,
  
  MAX_ROW_FOR_TIMEOUT_DZO
};

enum _index_ml_ctrl_dzo
{
  INDEX_CTR_FAULT_U_DZO = 0,
  INDEX_CTR_BLOCK_DZO1_I_OSN_3G,
  INDEX_CTR_BLOCK_DZO1_I_OSN,
  INDEX_CTR_DZO1_AMTZ, 
  INDEX_CTR_DZO1,
  
  INDEX_CTR_DZO2_CONST_PR,
  INDEX_CTR_DZO2_PR_VID_VVO,
  INDEX_CTR_BLOCK_DZO2_I_OSN_3G,
  INDEX_CTR_DZO2_AMTZ,
  INDEX_CTR_DZO2,
  INDEX_CTR_DZO2_DIR,
  INDEX_CTR_DZO2_INV,
  
  
  INDEX_CTR_DZO3_CONST_PR,
  INDEX_CTR_DZO3_PR_VID_VVO,
  INDEX_CTR_BLOCK_DZO3_I_OSN_3G,
  INDEX_CTR_DZO3_AMTZ,
  INDEX_CTR_DZO3,
  INDEX_CTR_DZO3_DIR,
  INDEX_CTR_DZO3_INV,
  
  INDEX_CTR_BLOCK_DZO4_I_OSN_3G,
  INDEX_CTR_DZO4_AMTZ,
  INDEX_CTR_DZO4,
  INDEX_CTR_DZO4_DIR,
  INDEX_CTR_DZO4_INV,
  

  
  
  
  //INDEX_CTR_NKN_DZO,
  
  MAX_ROW_FOR_CONTROL_DZO
};

#define COL_PICKUP_DZO_K_ICE_BEGIN                6
#define COL_PICKUP_DZO_K_ICE_COMMA                7
#define COL_PICKUP_DZO_K_ICE_END                  10

#define COL_PICKUP_DZO1_BEGIN                 3
#define COL_PICKUP_DZO1_COMMA                 6
#define COL_PICKUP_DZO1_END                   8

#define COL_PICKUP_DZO1_AMTZ_BEGIN            4
#define COL_PICKUP_DZO1_AMTZ_COMMA            7
#define COL_PICKUP_DZO1_AMTZ_END              9

#define COL_PICKUP_DZO1_I_BLK_BEGIN            4
#define COL_PICKUP_DZO1_I_BLK_COMMA            7
#define COL_PICKUP_DZO1_I_BLK_END              9

#define COL_S_DZO2_ANGLE                      6
#define COL_PICKUP_DZO2_ANGLE_BEGIN           7
#define COL_PICKUP_DZO2_ANGLE_END             8

#define COL_PICKUP_DZO2_DIR_BEGIN             3
#define COL_PICKUP_DZO2_DIR_COMMA             6
#define COL_PICKUP_DZO2_DIR_END               8

#define COL_PICKUP_DZO2_INV_BEGIN             3
#define COL_PICKUP_DZO2_INV_COMMA             6
#define COL_PICKUP_DZO2_INV_END               8

#define COL_PICKUP_DZO2_AMTZ_BEGIN            4
#define COL_PICKUP_DZO2_AMTZ_COMMA            7
#define COL_PICKUP_DZO2_AMTZ_END              9

#define COL_DZO3_S_ANGLE_H                    6
#define COL_PICKUP_DZO3_ANGLE_H_BEGIN         7
#define COL_PICKUP_DZO3_ANGLE_H_END           9

#define COL_DZO3_S_ANGLE_L                    6
#define COL_PICKUP_DZO3_ANGLE_L_BEGIN         7
#define COL_PICKUP_DZO3_ANGLE_L_END           9

#define COL_PICKUP_DZO3_DIR_BEGIN             3
#define COL_PICKUP_DZO3_DIR_COMMA             6
#define COL_PICKUP_DZO3_DIR_END               8

#define COL_PICKUP_DZO3_INV_BEGIN             3
#define COL_PICKUP_DZO3_INV_COMMA             6
#define COL_PICKUP_DZO3_INV_END               8

#define COL_PICKUP_DZO3_AMTZ_BEGIN            4
#define COL_PICKUP_DZO3_AMTZ_COMMA            7
#define COL_PICKUP_DZO3_AMTZ_END              9



#define COL_PICKUP_DZO4_Z0_DIR_BEGIN          3
#define COL_PICKUP_DZO4_Z0_DIR_COMMA          6
#define COL_PICKUP_DZO4_Z0_DIR_END            8
#define COL_PICKUP_DZO4_X0_DIR_BEGIN          3
#define COL_PICKUP_DZO4_X0_DIR_COMMA          6
#define COL_PICKUP_DZO4_X0_DIR_END            8

#define COL_PICKUP_DZO4_Z0_INV_BEGIN          3
#define COL_PICKUP_DZO4_Z0_INV_COMMA          6
#define COL_PICKUP_DZO4_Z0_INV_END            8
#define COL_PICKUP_DZO4_X0_INV_BEGIN          3
#define COL_PICKUP_DZO4_X0_INV_COMMA          6
#define COL_PICKUP_DZO4_X0_INV_END            8

#define COL_PICKUP_DZO4_AMTZ_BEGIN            4
#define COL_PICKUP_DZO4_AMTZ_COMMA            7
#define COL_PICKUP_DZO4_AMTZ_END              9

#define COL_SDZO4_ANGLE                       6
#define COL_PICKUP_DZO4_ANGLE_BEGIN           7
#define COL_PICKUP_DZO4_ANGLE_END             8


#define COL_TMO_DZO1_BEGIN                    4
#define COL_TMO_DZO1_COMMA                    6
#define COL_TMO_DZO1_END                      8

#define COL_TMO_DZO1_AMTZ_BEGIN               4
#define COL_TMO_DZO1_AMTZ_COMMA               6
#define COL_TMO_DZO1_AMTZ_END                 8

#define COL_TMO_DZO2_DIR_BEGIN                4
#define COL_TMO_DZO2_DIR_COMMA                6
#define COL_TMO_DZO2_DIR_END                  8

#define COL_TMO_DZO2_DIR_PR_BEGIN             5
#define COL_TMO_DZO2_DIR_PR_COMMA             6
#define COL_TMO_DZO2_DIR_PR_END               8

#define COL_TMO_DZO2_INV_BEGIN                4
#define COL_TMO_DZO2_INV_COMMA                6
#define COL_TMO_DZO2_INV_END                  8

#define COL_TMO_DZO2_INV_PR_BEGIN             5
#define COL_TMO_DZO2_INV_PR_COMMA             6
#define COL_TMO_DZO2_INV_PR_END               8

#define COL_TMO_DZO2_AMTZ_BEGIN               4
#define COL_TMO_DZO2_AMTZ_COMMA               6
#define COL_TMO_DZO2_AMTZ_END                 8

#define COL_TMO_DZO2_AMTZ_PR_BEGIN            5
#define COL_TMO_DZO2_AMTZ_PR_COMMA            6
#define COL_TMO_DZO2_AMTZ_PR_END              8

#define COL_TMO_DZO2_VVID_PR_BEGIN            5
#define COL_TMO_DZO2_VVID_PR_COMMA            6
#define COL_TMO_DZO2_VVID_PR_END              8

#define COL_TMO_DZO2_AMTZ_VVID_PR_BEGIN       5
#define COL_TMO_DZO2_AMTZ_VVID_PR_COMMA       6
#define COL_TMO_DZO2_AMTZ_VVID_PR_END         8

#define COL_TMO_DZO3_DIR_BEGIN                4
#define COL_TMO_DZO3_DIR_COMMA                6
#define COL_TMO_DZO3_DIR_END                  8

#define COL_TMO_DZO3_DIR_PR_BEGIN             5
#define COL_TMO_DZO3_DIR_PR_COMMA             6
#define COL_TMO_DZO3_DIR_PR_END               8

#define COL_TMO_DZO3_INV_BEGIN                4
#define COL_TMO_DZO3_INV_COMMA                6
#define COL_TMO_DZO3_INV_END                  8

#define COL_TMO_DZO3_INV_PR_BEGIN             5
#define COL_TMO_DZO3_INV_PR_COMMA             6
#define COL_TMO_DZO3_INV_PR_END               8

#define COL_TMO_DZO3_AMTZ_BEGIN               4
#define COL_TMO_DZO3_AMTZ_COMMA               6
#define COL_TMO_DZO3_AMTZ_END                 8

#define COL_TMO_DZO3_AMTZ_PR_BEGIN            5
#define COL_TMO_DZO3_AMTZ_PR_COMMA            6
#define COL_TMO_DZO3_AMTZ_PR_END              8

#define COL_TMO_DZO3_VVID_PR_BEGIN            5
#define COL_TMO_DZO3_VVID_PR_COMMA            6
#define COL_TMO_DZO3_VVID_PR_END              8

#define COL_TMO_DZO3_AMTZ_VVID_PR_BEGIN       5
#define COL_TMO_DZO3_AMTZ_VVID_PR_COMMA       6
#define COL_TMO_DZO3_AMTZ_VVID_PR_END         8

#define COL_TMO_DZO4_DIR_BEGIN                4
#define COL_TMO_DZO4_DIR_COMMA                6
#define COL_TMO_DZO4_DIR_END                  8

#define COL_TMO_DZO4_DIR_PR_BEGIN             5
#define COL_TMO_DZO4_DIR_PR_COMMA             6
#define COL_TMO_DZO4_DIR_PR_END               8

#define COL_TMO_DZO4_INV_BEGIN                4
#define COL_TMO_DZO4_INV_COMMA                6
#define COL_TMO_DZO4_INV_END                  8

#define COL_TMO_DZO4_INV_PR_BEGIN             5
#define COL_TMO_DZO4_INV_PR_COMMA             6
#define COL_TMO_DZO4_INV_PR_END               8

#define COL_TMO_DZO4_AMTZ_BEGIN               4
#define COL_TMO_DZO4_AMTZ_COMMA               6
#define COL_TMO_DZO4_AMTZ_END                 8

#define COL_TMO_DZO4_AMTZ_PR_BEGIN            5
#define COL_TMO_DZO4_AMTZ_PR_COMMA            6
#define COL_TMO_DZO4_AMTZ_PR_END              8

#define COL_TMO_DZO4_VVID_PR_BEGIN            5
#define COL_TMO_DZO4_VVID_PR_COMMA            6
#define COL_TMO_DZO4_VVID_PR_END              8

#define COL_TMO_DZO4_AMTZ_VVID_PR_BEGIN       5
#define COL_TMO_DZO4_AMTZ_VVID_PR_COMMA       6
#define COL_TMO_DZO4_AMTZ_VVID_PR_END         8

#define COL_TMO_NKN_DZO_BEGIN                 5
#define COL_TMO_NKN_DZO_COMMA                 6
#define COL_TMO_NKN_DZO_END                   8

//#define CTR_DZ_MASKA                   (                                        \
//                                        MASKA_FOR_BIT(INDEX_CTR_DZ1)           |\
//                                        MASKA_FOR_BIT(INDEX_CTR_DZ1_AMTZ)      |\
//                                        MASKA_FOR_BIT(INDEX_CTR_DZ2)           |\
//                                        MASKA_FOR_BIT(INDEX_CTR_DZ2_DIR)       |\
//                                        MASKA_FOR_BIT(INDEX_CTR_DZ2_INV)       |\
//                                        MASKA_FOR_BIT(INDEX_CTR_DZ2_PR_VID_DV) |\
//                                        MASKA_FOR_BIT(INDEX_CTR_DZ2_CONST_PR)  |\
//                                        MASKA_FOR_BIT(INDEX_CTR_DZ2_AMTZ)      |\
//                                        MASKA_FOR_BIT(INDEX_CTR_DZ3)           |\
//                                        MASKA_FOR_BIT(INDEX_CTR_DZ3_DIR)       |\
//                                        MASKA_FOR_BIT(INDEX_CTR_DZ3_INV)       |\
//                                        MASKA_FOR_BIT(INDEX_CTR_DZ3_PR_VID_DV) |\
//                                        MASKA_FOR_BIT(INDEX_CTR_DZ3_CONST_PR)  |\
//                                        MASKA_FOR_BIT(INDEX_CTR_DZ3_AMTZ)      |\
//                                        MASKA_FOR_BIT(INDEX_CTR_DZ4)           |\
//                                        MASKA_FOR_BIT(INDEX_CTR_DZ4_DIR)       |\
//                                        MASKA_FOR_BIT(INDEX_CTR_DZ4_INV)       |\
//                                        MASKA_FOR_BIT(INDEX_CTR_DZ4_PR_VID_DV) |\
//                                        MASKA_FOR_BIT(INDEX_CTR_DZ4_CONST_PR)  |\
//                                        MASKA_FOR_BIT(INDEX_CTR_DZ4_AMTZ)      |\
//                                        MASKA_FOR_BIT(INDEX_CTR_NKN_DZ)         \
//                                       )
#define CTR_DZO_MASKA                   (                                                \
                                          MASKA_FOR_BIT(INDEX_CTR_FAULT_U_DZO           )  \
                                        | MASKA_FOR_BIT(INDEX_CTR_BLOCK_DZO1_I_OSN_3G    )  \
                                        | MASKA_FOR_BIT(INDEX_CTR_BLOCK_DZO1_I_OSN       )  \
                                        | MASKA_FOR_BIT(INDEX_CTR_DZO1_AMTZ              )  \
                                        | MASKA_FOR_BIT(INDEX_CTR_DZO1                   )  \
										| MASKA_FOR_BIT(INDEX_CTR_DZO2_CONST_PR          )  \
                                        | MASKA_FOR_BIT(INDEX_CTR_DZO2_PR_VID_VVO        )  \
                                        | MASKA_FOR_BIT(INDEX_CTR_BLOCK_DZO2_I_OSN_3G    )  \
                                        | MASKA_FOR_BIT(INDEX_CTR_DZO2_AMTZ              )  \
                                        | MASKA_FOR_BIT(INDEX_CTR_DZO2                   )  \
                                        | MASKA_FOR_BIT(INDEX_CTR_DZO2_DIR               )  \
                                        | MASKA_FOR_BIT(INDEX_CTR_DZO2_INV               )  \
                                        | MASKA_FOR_BIT(INDEX_CTR_DZO3_CONST_PR          )  \
                                        | MASKA_FOR_BIT(INDEX_CTR_DZO3_PR_VID_VVO        )  \
                                        | MASKA_FOR_BIT(INDEX_CTR_BLOCK_DZO3_I_OSN_3G    )  \
                                        | MASKA_FOR_BIT(INDEX_CTR_DZO3_AMTZ              )  \
                                        | MASKA_FOR_BIT(INDEX_CTR_DZO3                   )  \
                                        | MASKA_FOR_BIT(INDEX_CTR_DZO3_DIR               )  \
                                        | MASKA_FOR_BIT(INDEX_CTR_DZO3_INV               )  \
                                        | MASKA_FOR_BIT(INDEX_CTR_BLOCK_DZO4_I_OSN_3G    )  \
                                        | MASKA_FOR_BIT(INDEX_CTR_DZO4_AMTZ              )  \
                                        | MASKA_FOR_BIT(INDEX_CTR_DZO4                   )  \
                                        | MASKA_FOR_BIT(INDEX_CTR_DZO4_DIR               )  \
                                        | MASKA_FOR_BIT(INDEX_CTR_DZO4_INV               )  \
                                       )

#endif
