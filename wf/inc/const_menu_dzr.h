#ifndef __CONST_MENU_DZR__
#define __CONST_MENU_DZR__

#define EKRAN_SETPOINT_DZR_GROUP1   (EKRAN_SETPOINT_MTZ_GROUP4 + 1)
#define EKRAN_SETPOINT_DZR_GROUP2   (EKRAN_SETPOINT_DZ_GROUP1 + 1)
#define EKRAN_SETPOINT_DZR_GROUP3   (EKRAN_SETPOINT_DZ_GROUP2 + 1)
#define EKRAN_SETPOINT_DZR_GROUP4   (EKRAN_SETPOINT_DZ_GROUP3 + 1)
#define EKRAN_TIMEOUT_DZR_GROUP1    (EKRAN_TIMEOUT_MTZ_GROUP4 + 1)
#define EKRAN_TIMEOUT_DZR_GROUP2    (EKRAN_TIMEOUT_DZ_GROUP1  + 1)
#define EKRAN_TIMEOUT_DZR_GROUP3    (EKRAN_TIMEOUT_DZ_GROUP2  + 1)
#define EKRAN_TIMEOUT_DZR_GROUP4    (EKRAN_TIMEOUT_DZ_GROUP3  + 1)
#define EKRAN_CONTROL_DZR           (EKRAN_CONTROL_MTZ + 1)

enum _index_ml_stp_dzr
{
  INDEX_ML_STP_K_ICE_DZR = 0,
  
  INDEX_ML_STP_DZR1,
  INDEX_ML_STP_DZR1_AMTZ,
  INDEX_ML_STP_DZR1_I_BLK,
  
  INDEX_ML_STP_DZR2_ANGLE,
  INDEX_ML_STP_DZR2_DIR,
  INDEX_ML_STP_DZR2_INV,
  INDEX_ML_STP_DZR2_AMTZ,
  
  INDEX_ML_STP_DZR3_ANGLE_H,
  INDEX_ML_STP_DZR3_ANGLE_L,
  INDEX_ML_STP_DZR3_DIR,
  INDEX_ML_STP_DZR3_INV,
  INDEX_ML_STP_DZR3_AMTZ,
  
  MAX_ROW_FOR_SETPOINT_DZR
};

enum _index_ml_tmp_dzr
{
  INDEX_ML_TMO_DZR1 = 0,
  INDEX_ML_TMO_DZR1_AMTZ,
  
  INDEX_ML_TMO_DZR2_DIR,
  INDEX_ML_TMO_DZR2_DIR_PR,
  INDEX_ML_TMO_DZR2_INV,
  INDEX_ML_TMO_DZR2_INV_PR,
  INDEX_ML_TMO_DZR2_AMTZ,
  INDEX_ML_TMO_DZR2_AMTZ_PR,
  INDEX_ML_TMO_DZR2_VVID_PR,
  INDEX_ML_TMO_DZR2_AMTZ_VVID_PR,
  
  INDEX_ML_TMO_DZR3_DIR,
  INDEX_ML_TMO_DZR3_DIR_PR,
  INDEX_ML_TMO_DZR3_INV,
  INDEX_ML_TMO_DZR3_INV_PR,
  INDEX_ML_TMO_DZR3_AMTZ,
  INDEX_ML_TMO_DZR3_AMTZ_PR,
  INDEX_ML_TMO_DZR3_VVID_PR,
  INDEX_ML_TMO_DZR3_AMTZ_VVID_PR,



  INDEX_ML_TMO_NKN_DZR,
  
  MAX_ROW_FOR_TIMEOUT_DZR
};

enum _index_ml_ctrl_dzr
{
  INDEX_CTR_FAULT_U_DZR = 0,
  INDEX_CTR_BLOCK_DZR1_I_RSV_3G,
  INDEX_CTR_BLOCK_DZR1_I_RSV,
  INDEX_CTR_DZR1_AMTZ,
  INDEX_CTR_DZR1,
  
  INDEX_CTR_DZR2_CONST_PR,
  INDEX_CTR_DZR2_PR_VID_VVR,
  INDEX_CTR_BLOCK_DZR2_I_RSV_3G,
  INDEX_CTR_DZR2_AMTZ,
  INDEX_CTR_DZR2,
  INDEX_CTR_DZR2_DIR,
  INDEX_CTR_DZR2_INV,
  
  INDEX_CTR_DZR3_CONST_PR,
  INDEX_CTR_DZR3_PR_VID_VVR,
  INDEX_CTR_BLOCK_DZR3_I_RSV_3G,
  INDEX_CTR_DZR3_AMTZ,
  INDEX_CTR_DZR3,
  INDEX_CTR_DZR3_DIR,
  INDEX_CTR_DZR3_INV,
  
  MAX_ROW_FOR_CONTROL_DZR
};

#define COL_PICKUP_DZR_K_ICE_BEGIN                6
#define COL_PICKUP_DZR_K_ICE_COMMA                7
#define COL_PICKUP_DZR_K_ICE_END                  10

#define COL_PICKUP_DZR1_BEGIN                 3
#define COL_PICKUP_DZR1_COMMA                 6
#define COL_PICKUP_DZR1_END                   8

#define COL_PICKUP_DZR1_AMTZ_BEGIN            4
#define COL_PICKUP_DZR1_AMTZ_COMMA            7
#define COL_PICKUP_DZR1_AMTZ_END              9

#define COL_PICKUP_DZR1_I_BLK_BEGIN            4
#define COL_PICKUP_DZR1_I_BLK_COMMA            7
#define COL_PICKUP_DZR1_I_BLK_END              9

#define COL_S_DZR2_ANGLE                      6
#define COL_PICKUP_DZR2_ANGLE_BEGIN           7
#define COL_PICKUP_DZR2_ANGLE_END             8

#define COL_PICKUP_DZR2_DIR_BEGIN             3
#define COL_PICKUP_DZR2_DIR_COMMA             6
#define COL_PICKUP_DZR2_DIR_END               8

#define COL_PICKUP_DZR2_INV_BEGIN             3
#define COL_PICKUP_DZR2_INV_COMMA             6
#define COL_PICKUP_DZR2_INV_END               8

#define COL_PICKUP_DZR2_AMTZ_BEGIN            4
#define COL_PICKUP_DZR2_AMTZ_COMMA            7
#define COL_PICKUP_DZR2_AMTZ_END              9

#define COL_DZR3_S_ANGLE_H                    6
#define COL_PICKUP_DZR3_ANGLE_H_BEGIN         7
#define COL_PICKUP_DZR3_ANGLE_H_END           9

#define COL_DZR3_S_ANGLE_L                    6
#define COL_PICKUP_DZR3_ANGLE_L_BEGIN         7
#define COL_PICKUP_DZR3_ANGLE_L_END           9

#define COL_PICKUP_DZR3_DIR_BEGIN             3
#define COL_PICKUP_DZR3_DIR_COMMA             6
#define COL_PICKUP_DZR3_DIR_END               8

#define COL_PICKUP_DZR3_INV_BEGIN             3
#define COL_PICKUP_DZR3_INV_COMMA             6
#define COL_PICKUP_DZR3_INV_END               8

#define COL_PICKUP_DZR3_AMTZ_BEGIN            4
#define COL_PICKUP_DZR3_AMTZ_COMMA            7
#define COL_PICKUP_DZR3_AMTZ_END              9






#define COL_TMO_DZR1_BEGIN                    4
#define COL_TMO_DZR1_COMMA                    6
#define COL_TMO_DZR1_END                      8

#define COL_TMO_DZR1_AMTZ_BEGIN               4
#define COL_TMO_DZR1_AMTZ_COMMA               6
#define COL_TMO_DZR1_AMTZ_END                 8

#define COL_TMO_DZR2_DIR_BEGIN                4
#define COL_TMO_DZR2_DIR_COMMA                6
#define COL_TMO_DZR2_DIR_END                  8

#define COL_TMO_DZR2_DIR_PR_BEGIN             5
#define COL_TMO_DZR2_DIR_PR_COMMA             6
#define COL_TMO_DZR2_DIR_PR_END               8

#define COL_TMO_DZR2_INV_BEGIN                4
#define COL_TMO_DZR2_INV_COMMA                6
#define COL_TMO_DZR2_INV_END                  8

#define COL_TMO_DZR2_INV_PR_BEGIN             5
#define COL_TMO_DZR2_INV_PR_COMMA             6
#define COL_TMO_DZR2_INV_PR_END               8

#define COL_TMO_DZR2_AMTZ_BEGIN               4
#define COL_TMO_DZR2_AMTZ_COMMA               6
#define COL_TMO_DZR2_AMTZ_END                 8

#define COL_TMO_DZR2_AMTZ_PR_BEGIN            5
#define COL_TMO_DZR2_AMTZ_PR_COMMA            6
#define COL_TMO_DZR2_AMTZ_PR_END              8

#define COL_TMO_DZR2_VVID_PR_BEGIN            5
#define COL_TMO_DZR2_VVID_PR_COMMA            6
#define COL_TMO_DZR2_VVID_PR_END              8

#define COL_TMO_DZR2_AMTZ_VVID_PR_BEGIN       5
#define COL_TMO_DZR2_AMTZ_VVID_PR_COMMA       6
#define COL_TMO_DZR2_AMTZ_VVID_PR_END         8

#define COL_TMO_DZR3_DIR_BEGIN                4
#define COL_TMO_DZR3_DIR_COMMA                6
#define COL_TMO_DZR3_DIR_END                  8

#define COL_TMO_DZR3_DIR_PR_BEGIN             5
#define COL_TMO_DZR3_DIR_PR_COMMA             6
#define COL_TMO_DZR3_DIR_PR_END               8

#define COL_TMO_DZR3_INV_BEGIN                4
#define COL_TMO_DZR3_INV_COMMA                6
#define COL_TMO_DZR3_INV_END                  8

#define COL_TMO_DZR3_INV_PR_BEGIN             5
#define COL_TMO_DZR3_INV_PR_COMMA             6
#define COL_TMO_DZR3_INV_PR_END               8

#define COL_TMO_DZR3_AMTZ_BEGIN               4
#define COL_TMO_DZR3_AMTZ_COMMA               6
#define COL_TMO_DZR3_AMTZ_END                 8

#define COL_TMO_DZR3_AMTZ_PR_BEGIN            5
#define COL_TMO_DZR3_AMTZ_PR_COMMA            6
#define COL_TMO_DZR3_AMTZ_PR_END              8

#define COL_TMO_DZR3_VVID_PR_BEGIN            5
#define COL_TMO_DZR3_VVID_PR_COMMA            6
#define COL_TMO_DZR3_VVID_PR_END              8

#define COL_TMO_DZR3_AMTZ_VVID_PR_BEGIN       5
#define COL_TMO_DZR3_AMTZ_VVID_PR_COMMA       6
#define COL_TMO_DZR3_AMTZ_VVID_PR_END         8



#define COL_TMO_NKN_DZR_BEGIN                 5
#define COL_TMO_NKN_DZR_COMMA                 6
#define COL_TMO_NKN_DZR_END                   8
                   
#define CTR_DZR_MASKA                   (                                                \
                                          MASKA_FOR_BIT(INDEX_CTR_FAULT_U_DZR           )  \
                                        | MASKA_FOR_BIT(INDEX_CTR_BLOCK_DZR1_I_RSV_3G )  \
                                        | MASKA_FOR_BIT(INDEX_CTR_BLOCK_DZR1_I_RSV    )  \
                                        | MASKA_FOR_BIT(INDEX_CTR_DZR1_AMTZ           )  \
                                        | MASKA_FOR_BIT(INDEX_CTR_DZR2_CONST_PR       )  \
                                        | MASKA_FOR_BIT(INDEX_CTR_DZR2_PR_VID_VVR     )  \
                                        | MASKA_FOR_BIT(INDEX_CTR_BLOCK_DZR2_I_RSV_3G )  \
                                        | MASKA_FOR_BIT(INDEX_CTR_DZR2                )  \
                                        | MASKA_FOR_BIT(INDEX_CTR_DZR2_DIR            )  \
                                        | MASKA_FOR_BIT(INDEX_CTR_DZR2_INV            )  \
                                        | MASKA_FOR_BIT(INDEX_CTR_DZR2_AMTZ           )  \
                                        | MASKA_FOR_BIT(INDEX_CTR_DZR3_CONST_PR       )  \
                                        | MASKA_FOR_BIT(INDEX_CTR_DZR3_PR_VID_VVR     )  \
                                        | MASKA_FOR_BIT(INDEX_CTR_DZR3                )  \
                                        | MASKA_FOR_BIT(INDEX_CTR_DZR3_DIR            )  \
                                        | MASKA_FOR_BIT(INDEX_CTR_DZR3_INV            )  \
                                        | MASKA_FOR_BIT(INDEX_CTR_DZR3_AMTZ           )  \
                                        | MASKA_FOR_BIT(INDEX_CTR_BLOCK_DZR3_I_RSV_3G )  \
                                        | MASKA_FOR_BIT(INDEX_CTR_DZR1                )  \
                                       )


#endif
