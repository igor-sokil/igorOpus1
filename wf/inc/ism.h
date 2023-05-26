#ifndef LU_ISM_BIT_CONST_h
#define LU_ISM_BIT_CONST_h//Input Signal Mask

//#include "./a.01.c.d/const_global.h"
enum INPUT_SIGNALS_MASK{


IDX_U32_ISM_BLOCK_VKL_VVO                     = ( RNG_BIG_BLOCK_VKL_VVO                     )>>5,
IDX_U32_ISM_BLOCK_VKL_VVP                     = ( RNG_BIG_BLOCK_VKL_VVP                     )>>5,
IDX_U32_ISM_RESET_LEDS                        = ( RNG_BIG_RESET_LEDS                        )>>5,
IDX_U32_ISM_RESET_RELES                       = ( RNG_BIG_RESET_RELES                       )>>5,
IDX_U32_ISM_MISCEVE_DYSTANCIJNE               = ( RNG_BIG_MISCEVE_DYSTANCIJNE               )>>5,
IDX_U32_ISM_STATE_VVR                         = ( RNG_BIG_STATE_VVR                         )>>5,
IDX_U32_ISM_STATE_VVO                         = ( RNG_BIG_STATE_VVO                         )>>5,
IDX_U32_ISM_VKL_VVO                           = ( RNG_BIG_VKL_VVO                           )>>5,
IDX_U32_ISM_VKL_VVR                           = ( RNG_BIG_VKL_VVR                           )>>5,
IDX_U32_ISM_CTRL_VKL_VVO                      = ( RNG_BIG_CTRL_VKL_VVO                      )>>5,
IDX_U32_ISM_CTRL_VKL_VVR                      = ( RNG_BIG_CTRL_VKL_VVR                      )>>5,
IDX_U32_ISM_OTKL_VV_VVO                       = ( RNG_BIG_OTKL_VV_VVO                       )>>5,
IDX_U32_ISM_OTKL_VV_VVR                       = ( RNG_BIG_OTKL_VV_VVR                       )>>5,
IDX_U32_ISM_CTRL_OTKL_VVO                     = ( RNG_BIG_CTRL_OTKL_VVO                     )>>5,
IDX_U32_ISM_CTRL_OTKL_VVR                     = ( RNG_BIG_CTRL_OTKL_VVR                     )>>5,
//IDX_U32_ISM_1_GRUPA_USTAVOK                   = ( RNG_BIG_1_GRUPA_USTAVOK                   )>>5,
//IDX_U32_ISM_2_GRUPA_USTAVOK                   = ( RNG_BIG_2_GRUPA_USTAVOK                   )>>5,
//IDX_U32_ISM_3_GRUPA_USTAVOK                   = ( RNG_BIG_3_GRUPA_USTAVOK                   )>>5,
//IDX_U32_ISM_4_GRUPA_USTAVOK                   = ( RNG_BIG_4_GRUPA_USTAVOK                   )>>5,
IDX_U32_ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV = ( RNG_BIG_RESET_BLOCK_READY_TU_VID_ZAHYSTIV )>>5,
IDX_U32_ISM_ZVN_NESPR_DZO                     = ( RNG_BIG_ZVN_NESPR_DZO                     )>>5,
IDX_U32_ISM_ZBR_BLOCK_DZO1_I_O_3G             = ( RNG_BIG_ZBR_BLOCK_DZO1_I_O_3G             )>>5,
IDX_U32_ISM_ZBR_BLOCK_DZO1_I_O                = ( RNG_BIG_ZBR_BLOCK_DZO1_I_O                )>>5,
IDX_U32_ISM_BLOCK_DZO1                        = ( RNG_BIG_BLOCK_DZO1                        )>>5,
IDX_U32_ISM_BLOCK_PR_DZO2                     = ( RNG_BIG_BLOCK_PR_DZO2                     )>>5,
IDX_U32_ISM_OP_PR_DZO2                        = ( RNG_BIG_OP_PR_DZO2                        )>>5,
IDX_U32_ISM_ZBR_BLOCK_DZO2_I_O_3G             = ( RNG_BIG_ZBR_BLOCK_DZO2_I_O_3G             )>>5,
IDX_U32_ISM_BLOCK_DZO2                        = ( RNG_BIG_BLOCK_DZO2                        )>>5,
IDX_U32_ISM_BLOCK_PR_DZO3                     = ( RNG_BIG_BLOCK_PR_DZO3                     )>>5,
IDX_U32_ISM_OP_PR_DZO3                        = ( RNG_BIG_OP_PR_DZO3                        )>>5,
IDX_U32_ISM_ZBR_BLOCK_DZO3_I_O_3G             = ( RNG_BIG_ZBR_BLOCK_DZO3_I_O_3G             )>>5,
IDX_U32_ISM_BLOCK_DZO3                        = ( RNG_BIG_BLOCK_DZO3                        )>>5,
IDX_U32_ISM_ZBR_BLOCK_DZO4_I_O_3G             = ( RNG_BIG_ZBR_BLOCK_DZO4_I_O_3G             )>>5,
IDX_U32_ISM_BLOCK_DZO4                        = ( RNG_BIG_BLOCK_DZO4                        )>>5,
IDX_U32_ISM_BLOCK_ZDZ                         = ( RNG_BIG_BLOCK_ZDZ                         )>>5,
IDX_U32_ISM_PUSK_ZDZ_VID_DV                   = ( RNG_BIG_PUSK_ZDZ_VID_DV                   )>>5,
IDX_U32_ISM_BLOCK_MCZO1                       = ( RNG_BIG_BLOCK_MCZO1                       )>>5,
IDX_U32_ISM_BLOCK_MCZO2                       = ( RNG_BIG_BLOCK_MCZO2                       )>>5,
IDX_U32_ISM_BLOCK_PR_MCZO2                    = ( RNG_BIG_BLOCK_PR_MCZO2                    )>>5,
IDX_U32_ISM_BLOCK_MCZO3                       = ( RNG_BIG_BLOCK_MCZO3                       )>>5,
IDX_U32_ISM_BLOCK_MCZO4                       = ( RNG_BIG_BLOCK_MCZO4                       )>>5,
IDX_U32_ISM_BLOCK_MCZR1                       = ( RNG_BIG_BLOCK_MCZR1                       )>>5,
IDX_U32_ISM_BLOCK_MCZR2                       = ( RNG_BIG_BLOCK_MCZR2                       )>>5,
IDX_U32_ISM_STAT_BLK_APV                      = ( RNG_BIG_STAT_BLK_APV                      )>>5,
IDX_U32_ISM_ACHR_CHAPV_VID_DV                 = ( RNG_BIG_ACHR_CHAPV_VID_DV                 )>>5,
IDX_U32_ISM_BLOCK_ACHR1                       = ( RNG_BIG_BLOCK_ACHR1                       )>>5,
IDX_U32_ISM_BLOCK_ACHR2                       = ( RNG_BIG_BLOCK_ACHR2                       )>>5,
IDX_U32_ISM_PUSK_UROV_VID_DV                  = ( RNG_BIG_PUSK_UROV_VID_DV                  )>>5,
IDX_U32_ISM_ZVN_NESPR_DZR                     = ( RNG_BIG_ZVN_NESPR_DZR                     )>>5,
IDX_U32_ISM_ZBR_BLOCK_DZR1_I_R_3G             = ( RNG_BIG_ZBR_BLOCK_DZR1_I_R_3G             )>>5,
IDX_U32_ISM_ZBR_BLOCK_DZR1_I_R                = ( RNG_BIG_ZBR_BLOCK_DZR1_I_R                )>>5,
IDX_U32_ISM_BLOCK_DZR1                        = ( RNG_BIG_BLOCK_DZR1                        )>>5,
IDX_U32_ISM_BLOCK_PR_DZR2                     = ( RNG_BIG_BLOCK_PR_DZR2                     )>>5,
IDX_U32_ISM_OP_PR_DZR2                        = ( RNG_BIG_OP_PR_DZR2                        )>>5,
IDX_U32_ISM_ZBR_BLOCK_DZR2_I_R_3G             = ( RNG_BIG_ZBR_BLOCK_DZR2_I_R_3G             )>>5,
IDX_U32_ISM_BLOCK_DZR2                        = ( RNG_BIG_BLOCK_DZR2                        )>>5,
IDX_U32_ISM_BLOCK_PR_DZR3                     = ( RNG_BIG_BLOCK_PR_DZR3                     )>>5,
IDX_U32_ISM_OP_PR_DZR3                        = ( RNG_BIG_OP_PR_DZR3                        )>>5,
IDX_U32_ISM_ZBR_BLOCK_DZR3_I_R_3G             = ( RNG_BIG_ZBR_BLOCK_DZR3_I_R_3G             )>>5,
IDX_U32_ISM_BLOCK_DZR3                        = ( RNG_BIG_BLOCK_DZR3                        )>>5,
IDX_U32_ISM_BLOCK_UMIN1                       = ( RNG_BIG_BLOCK_UMIN1                       )>>5,
IDX_U32_ISM_START_UMIN1                       = ( RNG_BIG_START_UMIN1                       )>>5,
IDX_U32_ISM_BLOCK_UMIN2                       = ( RNG_BIG_BLOCK_UMIN2                       )>>5,
IDX_U32_ISM_START_UMIN2                       = ( RNG_BIG_START_UMIN2                       )>>5,
IDX_U32_ISM_BLOCK_UMAX1                       = ( RNG_BIG_BLOCK_UMAX1                       )>>5,
IDX_U32_ISM_BLOCK_UMAX2                       = ( RNG_BIG_BLOCK_UMAX2                       )>>5,
IDX_U32_ISM_BLOCK_UP1                         = ( RNG_BIG_BLOCK_UP1                         )>>5,  //BLOCK_UP_01
IDX_U32_ISM_BLOCK_UP2                         = ( (RNG_BIG_BLOCK_UP1 + 3*1)                 )>>5,  //BLOCK_UP_02 
IDX_U32_ISM_BLOCK_UP3                         = ( (RNG_BIG_BLOCK_UP1 + 3*2)                 )>>5,  //BLOCK_UP_03 
IDX_U32_ISM_BLOCK_UP4                         = ( (RNG_BIG_BLOCK_UP1 + 3*3)                 )>>5,  //BLOCK_UP_04 
IDX_U32_ISM_BLOCK_UP5                         = ( (RNG_BIG_BLOCK_UP1 + 3*4)                 )>>5,  //BLOCK_UP_05 
IDX_U32_ISM_BLOCK_UP6                         = ( (RNG_BIG_BLOCK_UP1 + 3*5)                 )>>5,  //BLOCK_UP_06 
IDX_U32_ISM_BLOCK_UP7                         = ( (RNG_BIG_BLOCK_UP1 + 3*6)                 )>>5,  //BLOCK_UP_07 
IDX_U32_ISM_BLOCK_UP8                         = ( (RNG_BIG_BLOCK_UP1 + 3*7)                 )>>5,  //BLOCK_UP_08 
IDX_U32_ISM_DF1_IN                            = ( RNG_BIG_DF1_IN                            )>>5,
IDX_U32_ISM_DF2_IN                            = ( RNG_BIG_DF2_IN                            )>>5,
IDX_U32_ISM_DF3_IN                            = ( RNG_BIG_DF3_IN                            )>>5,
IDX_U32_ISM_DF4_IN                            = ( RNG_BIG_DF4_IN                            )>>5,
IDX_U32_ISM_DF5_IN                            = ( RNG_BIG_DF5_IN                            )>>5,
IDX_U32_ISM_DF6_IN                            = ( RNG_BIG_DF6_IN                            )>>5,
IDX_U32_ISM_DF7_IN                            = ( RNG_BIG_DF7_IN                            )>>5,
IDX_U32_ISM_DF8_IN                            = ( RNG_BIG_DF8_IN                            )>>5,
IDX_U32_ISM_DF9_IN                            = ( RNG_BIG_DF9_IN                            )>>5,
IDX_U32_ISM_DF10_IN                           = ( RNG_BIG_DF10_IN                           )>>5,
IDX_U32_ISM_DF11_IN                           = ( RNG_BIG_DF11_IN                           )>>5,
IDX_U32_ISM_DF12_IN                           = ( RNG_BIG_DF12_IN                           )>>5,
IDX_U32_ISM_DF13_IN                           = ( RNG_BIG_DF13_IN                           )>>5,
IDX_U32_ISM_DF14_IN                           = ( RNG_BIG_DF14_IN                           )>>5,
IDX_U32_ISM_DF15_IN                           = ( RNG_BIG_DF15_IN                           )>>5,
IDX_U32_ISM_DF16_IN                           = ( RNG_BIG_DF16_IN                           )>>5,
IDX_U32_ISM_DT1_SET                           = ( RNG_BIG_DT1_SET                           )>>5,
IDX_U32_ISM_DT1_RESET                         = ( RNG_BIG_DT1_RESET                         )>>5,
IDX_U32_ISM_DT2_SET                           = ( RNG_BIG_DT2_SET                           )>>5,
IDX_U32_ISM_DT2_RESET                         = ( RNG_BIG_DT2_RESET                         )>>5,
IDX_U32_ISM_DT3_SET                           = ( RNG_BIG_DT3_SET                           )>>5,
IDX_U32_ISM_DT3_RESET                         = ( RNG_BIG_DT3_RESET                         )>>5,
IDX_U32_ISM_DT4_SET                           = ( RNG_BIG_DT4_SET                           )>>5,
IDX_U32_ISM_DT4_RESET                         = ( RNG_BIG_DT4_RESET                         )>>5,
IDX_U32_ISM_LF1                               = ( RNG_BIG_LF1                               )>>5,
IDX_U32_ISM_LF2                               = ( RNG_BIG_LF2                               )>>5,
IDX_U32_ISM_LF3                               = ( RNG_BIG_LF3                               )>>5,
IDX_U32_ISM_LF4                               = ( RNG_BIG_LF4                               )>>5,
IDX_U32_ISM_LF5                               = ( RNG_BIG_LF5                               )>>5,
IDX_U32_ISM_LF6                               = ( RNG_BIG_LF6                               )>>5,
IDX_U32_ISM_LF7                               = ( RNG_BIG_LF7                               )>>5,
IDX_U32_ISM_LF8                               = ( RNG_BIG_LF8                               )>>5,
IDX_U32_ISM_LF9                               = ( RNG_BIG_LF9                               )>>5,
IDX_U32_ISM_LF10                              = ( RNG_BIG_LF10                              )>>5,
IDX_U32_ISM_LF11                              = ( RNG_BIG_LF11                              )>>5,
IDX_U32_ISM_LF12                              = ( RNG_BIG_LF12                              )>>5,
IDX_U32_ISM_LF13                              = ( RNG_BIG_LF13                              )>>5,
IDX_U32_ISM_LF14                              = ( RNG_BIG_LF14                              )>>5,
IDX_U32_ISM_LF15                              = ( RNG_BIG_LF15                              )>>5,
IDX_U32_ISM_LF16                              = ( RNG_BIG_LF16                              )>>5,


MSK_U32_ISM_BLOCK_VKL_VVO                       = ( RNG_BIG_BLOCK_VKL_VVO                     )&0x1f,
MSK_U32_ISM_BLOCK_VKL_VVP                       = ( RNG_BIG_BLOCK_VKL_VVP                     )&0x1f,
MSK_U32_ISM_RESET_LEDS                          = ( RNG_BIG_RESET_LEDS                        )&0x1f,
MSK_U32_ISM_RESET_RELES                         = ( RNG_BIG_RESET_RELES                       )&0x1f,
MSK_U32_ISM_MISCEVE_DYSTANCIJNE                 = ( RNG_BIG_MISCEVE_DYSTANCIJNE               )&0x1f,
MSK_U32_ISM_STATE_VVR                           = ( RNG_BIG_STATE_VVR                         )&0x1f,
MSK_U32_ISM_STATE_VVO                           = ( RNG_BIG_STATE_VVO                         )&0x1f,
MSK_U32_ISM_VKL_VVO                             = ( RNG_BIG_VKL_VVO                           )&0x1f,
MSK_U32_ISM_VKL_VVR                             = ( RNG_BIG_VKL_VVR                           )&0x1f,
MSK_U32_ISM_CTRL_VKL_VVO                        = ( RNG_BIG_CTRL_VKL_VVO                      )&0x1f,
MSK_U32_ISM_CTRL_VKL_VVR                        = ( RNG_BIG_CTRL_VKL_VVR                      )&0x1f,
MSK_U32_ISM_OTKL_VV_VVO                         = ( RNG_BIG_OTKL_VV_VVO                       )&0x1f,
MSK_U32_ISM_OTKL_VV_VVR                         = ( RNG_BIG_OTKL_VV_VVR                       )&0x1f,
MSK_U32_ISM_CTRL_OTKL_VVO                       = ( RNG_BIG_CTRL_OTKL_VVO                     )&0x1f,
MSK_U32_ISM_CTRL_OTKL_VVR                       = ( RNG_BIG_CTRL_OTKL_VVR                     )&0x1f,
//MSK_U32_ISM_1_GRUPA_USTAVOK                     = ( RNG_BIG_1_GRUPA_USTAVOK                   )&0x1f,
//MSK_U32_ISM_2_GRUPA_USTAVOK                     = ( RNG_BIG_2_GRUPA_USTAVOK                   )&0x1f,
//MSK_U32_ISM_3_GRUPA_USTAVOK                     = ( RNG_BIG_3_GRUPA_USTAVOK                   )&0x1f,
//MSK_U32_ISM_4_GRUPA_USTAVOK                     = ( RNG_BIG_4_GRUPA_USTAVOK                   )&0x1f,
MSK_U32_ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV   = ( RNG_BIG_RESET_BLOCK_READY_TU_VID_ZAHYSTIV )&0x1f,
MSK_U32_ISM_ZVN_NESPR_DZO                       = ( RNG_BIG_ZVN_NESPR_DZO                     )&0x1f,
MSK_U32_ISM_ZBR_BLOCK_DZO1_I_O_3G               = ( RNG_BIG_ZBR_BLOCK_DZO1_I_O_3G             )&0x1f,
MSK_U32_ISM_ZBR_BLOCK_DZO1_I_O                  = ( RNG_BIG_ZBR_BLOCK_DZO1_I_O                )&0x1f,
MSK_U32_ISM_BLOCK_DZO1                          = ( RNG_BIG_BLOCK_DZO1                        )&0x1f,
MSK_U32_ISM_BLOCK_PR_DZO2                       = ( RNG_BIG_BLOCK_PR_DZO2                     )&0x1f,
MSK_U32_ISM_OP_PR_DZO2                          = ( RNG_BIG_OP_PR_DZO2                        )&0x1f,
MSK_U32_ISM_ZBR_BLOCK_DZO2_I_O_3G               = ( RNG_BIG_ZBR_BLOCK_DZO2_I_O_3G             )&0x1f,
MSK_U32_ISM_BLOCK_DZO2                          = ( RNG_BIG_BLOCK_DZO2                        )&0x1f,
MSK_U32_ISM_BLOCK_PR_DZO3                       = ( RNG_BIG_BLOCK_PR_DZO3                     )&0x1f,
MSK_U32_ISM_OP_PR_DZO3                          = ( RNG_BIG_OP_PR_DZO3                        )&0x1f,
MSK_U32_ISM_ZBR_BLOCK_DZO3_I_O_3G               = ( RNG_BIG_ZBR_BLOCK_DZO3_I_O_3G             )&0x1f,
MSK_U32_ISM_BLOCK_DZO3                          = ( RNG_BIG_BLOCK_DZO3                        )&0x1f,
MSK_U32_ISM_ZBR_BLOCK_DZO4_I_O_3G               = ( RNG_BIG_ZBR_BLOCK_DZO4_I_O_3G             )&0x1f,
MSK_U32_ISM_BLOCK_DZO4                          = ( RNG_BIG_BLOCK_DZO4                        )&0x1f,
MSK_U32_ISM_BLOCK_ZDZ                           = ( RNG_BIG_BLOCK_ZDZ                         )&0x1f,
MSK_U32_ISM_PUSK_ZDZ_VID_DV                     = ( RNG_BIG_PUSK_ZDZ_VID_DV                   )&0x1f,
MSK_U32_ISM_BLOCK_MCZO1                         = ( RNG_BIG_BLOCK_MCZO1                       )&0x1f,
MSK_U32_ISM_BLOCK_MCZO2                         = ( RNG_BIG_BLOCK_MCZO2                       )&0x1f,
MSK_U32_ISM_BLOCK_PR_MCZO2                      = ( RNG_BIG_BLOCK_PR_MCZO2                    )&0x1f,
MSK_U32_ISM_BLOCK_MCZO3                         = ( RNG_BIG_BLOCK_MCZO3                       )&0x1f,
MSK_U32_ISM_BLOCK_MCZO4                         = ( RNG_BIG_BLOCK_MCZO4                       )&0x1f,
MSK_U32_ISM_BLOCK_MCZR1                         = ( RNG_BIG_BLOCK_MCZR1                       )&0x1f,
MSK_U32_ISM_BLOCK_MCZR2                         = ( RNG_BIG_BLOCK_MCZR2                       )&0x1f,
MSK_U32_ISM_STAT_BLK_APV                        = ( RNG_BIG_STAT_BLK_APV                      )&0x1f,
MSK_U32_ISM_ACHR_CHAPV_VID_DV                   = ( RNG_BIG_ACHR_CHAPV_VID_DV                 )&0x1f,
MSK_U32_ISM_BLOCK_ACHR1                         = ( RNG_BIG_BLOCK_ACHR1                       )&0x1f,
MSK_U32_ISM_BLOCK_ACHR2                         = ( RNG_BIG_BLOCK_ACHR2                       )&0x1f,
MSK_U32_ISM_PUSK_UROV_VID_DV                    = ( RNG_BIG_PUSK_UROV_VID_DV                  )&0x1f,
MSK_U32_ISM_ZVN_NESPR_DZR                       = ( RNG_BIG_ZVN_NESPR_DZR                     )&0x1f,
MSK_U32_ISM_ZBR_BLOCK_DZR1_I_R_3G               = ( RNG_BIG_ZBR_BLOCK_DZR1_I_R_3G             )&0x1f,
MSK_U32_ISM_ZBR_BLOCK_DZR1_I_R                  = ( RNG_BIG_ZBR_BLOCK_DZR1_I_R                )&0x1f,
MSK_U32_ISM_BLOCK_DZR1                          = ( RNG_BIG_BLOCK_DZR1                        )&0x1f,
MSK_U32_ISM_BLOCK_PR_DZR2                       = ( RNG_BIG_BLOCK_PR_DZR2                     )&0x1f,
MSK_U32_ISM_OP_PR_DZR2                          = ( RNG_BIG_OP_PR_DZR2                        )&0x1f,
MSK_U32_ISM_ZBR_BLOCK_DZR2_I_R_3G               = ( RNG_BIG_ZBR_BLOCK_DZR2_I_R_3G             )&0x1f,
MSK_U32_ISM_BLOCK_DZR2                          = ( RNG_BIG_BLOCK_DZR2                        )&0x1f,
MSK_U32_ISM_BLOCK_PR_DZR3                       = ( RNG_BIG_BLOCK_PR_DZR3                     )&0x1f,
MSK_U32_ISM_OP_PR_DZR3                          = ( RNG_BIG_OP_PR_DZR3                        )&0x1f,
MSK_U32_ISM_ZBR_BLOCK_DZR3_I_R_3G               = ( RNG_BIG_ZBR_BLOCK_DZR3_I_R_3G             )&0x1f,
MSK_U32_ISM_BLOCK_DZR3                          = ( RNG_BIG_BLOCK_DZR3                        )&0x1f,
MSK_U32_ISM_BLOCK_UMIN1                         = ( RNG_BIG_BLOCK_UMIN1                       )&0x1f,
MSK_U32_ISM_START_UMIN1                         = ( RNG_BIG_START_UMIN1                       )&0x1f,
MSK_U32_ISM_BLOCK_UMIN2                         = ( RNG_BIG_BLOCK_UMIN2                       )&0x1f,
MSK_U32_ISM_START_UMIN2                         = ( RNG_BIG_START_UMIN2                       )&0x1f,
MSK_U32_ISM_BLOCK_UMAX1                         = ( RNG_BIG_BLOCK_UMAX1                       )&0x1f,
MSK_U32_ISM_BLOCK_UMAX2                         = ( RNG_BIG_BLOCK_UMAX2                       )&0x1f,
MSK_U32_ISM_BLOCK_UP1                           = ( RNG_BIG_BLOCK_UP1                         )&0x1f,  //BLOCK_UP_01
MSK_U32_ISM_BLOCK_UP2                           = ( (RNG_BIG_BLOCK_UP1 + 3*1)                 )&0x1f,  //BLOCK_UP_02 
MSK_U32_ISM_BLOCK_UP3                           = ( (RNG_BIG_BLOCK_UP1 + 3*2)                 )&0x1f,  //BLOCK_UP_03 
MSK_U32_ISM_BLOCK_UP4                           = ( (RNG_BIG_BLOCK_UP1 + 3*3)                 )&0x1f,  //BLOCK_UP_04 
MSK_U32_ISM_BLOCK_UP5                           = ( (RNG_BIG_BLOCK_UP1 + 3*4)                 )&0x1f,  //BLOCK_UP_05 
MSK_U32_ISM_BLOCK_UP6                           = ( (RNG_BIG_BLOCK_UP1 + 3*5)                 )&0x1f,  //BLOCK_UP_06 
MSK_U32_ISM_BLOCK_UP7                           = ( (RNG_BIG_BLOCK_UP1 + 3*6)                 )&0x1f,  //BLOCK_UP_07 
MSK_U32_ISM_BLOCK_UP8                           = ( (RNG_BIG_BLOCK_UP1 + 3*7)                 )&0x1f,  //BLOCK_UP_08 
MSK_U32_ISM_DF1_IN                              = ( RNG_BIG_DF1_IN                            )&0x1f,
MSK_U32_ISM_DF2_IN                              = ( RNG_BIG_DF2_IN                            )&0x1f,
MSK_U32_ISM_DF3_IN                              = ( RNG_BIG_DF3_IN                            )&0x1f,
MSK_U32_ISM_DF4_IN                              = ( RNG_BIG_DF4_IN                            )&0x1f,
MSK_U32_ISM_DF5_IN                              = ( RNG_BIG_DF5_IN                            )&0x1f,
MSK_U32_ISM_DF6_IN                              = ( RNG_BIG_DF6_IN                            )&0x1f,
MSK_U32_ISM_DF7_IN                              = ( RNG_BIG_DF7_IN                            )&0x1f,
MSK_U32_ISM_DF8_IN                              = ( RNG_BIG_DF8_IN                            )&0x1f,
MSK_U32_ISM_DF9_IN                              = ( RNG_BIG_DF9_IN                            )&0x1f,
MSK_U32_ISM_DF10_IN                             = ( RNG_BIG_DF10_IN                           )&0x1f,
MSK_U32_ISM_DF11_IN                             = ( RNG_BIG_DF11_IN                           )&0x1f,
MSK_U32_ISM_DF12_IN                             = ( RNG_BIG_DF12_IN                           )&0x1f,
MSK_U32_ISM_DF13_IN                             = ( RNG_BIG_DF13_IN                           )&0x1f,
MSK_U32_ISM_DF14_IN                             = ( RNG_BIG_DF14_IN                           )&0x1f,
MSK_U32_ISM_DF15_IN                             = ( RNG_BIG_DF15_IN                           )&0x1f,
MSK_U32_ISM_DF16_IN                             = ( RNG_BIG_DF16_IN                           )&0x1f,
MSK_U32_ISM_DT1_SET                             = ( RNG_BIG_DT1_SET                           )&0x1f,
MSK_U32_ISM_DT1_RESET                           = ( RNG_BIG_DT1_RESET                         )&0x1f,
MSK_U32_ISM_DT2_SET                             = ( RNG_BIG_DT2_SET                           )&0x1f,
MSK_U32_ISM_DT2_RESET                           = ( RNG_BIG_DT2_RESET                         )&0x1f,
MSK_U32_ISM_DT3_SET                             = ( RNG_BIG_DT3_SET                           )&0x1f,
MSK_U32_ISM_DT3_RESET                           = ( RNG_BIG_DT3_RESET                         )&0x1f,
MSK_U32_ISM_DT4_SET                             = ( RNG_BIG_DT4_SET                           )&0x1f,
MSK_U32_ISM_DT4_RESET                           = ( RNG_BIG_DT4_RESET                         )&0x1f,
MSK_U32_ISM_LF1                                 = ( RNG_BIG_LF1                               )&0x1f,
MSK_U32_ISM_LF2                                 = ( RNG_BIG_LF2                               )&0x1f,
MSK_U32_ISM_LF3                                 = ( RNG_BIG_LF3                               )&0x1f,
MSK_U32_ISM_LF4                                 = ( RNG_BIG_LF4                               )&0x1f,
MSK_U32_ISM_LF5                                 = ( RNG_BIG_LF5                               )&0x1f,
MSK_U32_ISM_LF6                                 = ( RNG_BIG_LF6                               )&0x1f,
MSK_U32_ISM_LF7                                 = ( RNG_BIG_LF7                               )&0x1f,
MSK_U32_ISM_LF8                                 = ( RNG_BIG_LF8                               )&0x1f,
MSK_U32_ISM_LF9                                 = ( RNG_BIG_LF9                               )&0x1f,
MSK_U32_ISM_LF10                                = ( RNG_BIG_LF10                              )&0x1f,
MSK_U32_ISM_LF11                                = ( RNG_BIG_LF11                              )&0x1f,
MSK_U32_ISM_LF12                                = ( RNG_BIG_LF12                              )&0x1f,
MSK_U32_ISM_LF13                                = ( RNG_BIG_LF13                              )&0x1f,
MSK_U32_ISM_LF14                                = ( RNG_BIG_LF14                              )&0x1f,
MSK_U32_ISM_LF15                                = ( RNG_BIG_LF15                              )&0x1f,
MSK_U32_ISM_LF16                                = ( RNG_BIG_LF16                              )&0x1f,

ISM_BLOCK_VKL_VVO_CMD_00 = ((IDX_U32_ISM_BLOCK_VKL_VVO ==  0)<< MSK_U32_ISM_BLOCK_VKL_VVO),
ISM_BLOCK_VKL_VVO_CMD_01 = ((IDX_U32_ISM_BLOCK_VKL_VVO ==  1)<< MSK_U32_ISM_BLOCK_VKL_VVO),
ISM_BLOCK_VKL_VVO_CMD_02 = ((IDX_U32_ISM_BLOCK_VKL_VVO ==  2)<< MSK_U32_ISM_BLOCK_VKL_VVO),
ISM_BLOCK_VKL_VVO_CMD_03 = ((IDX_U32_ISM_BLOCK_VKL_VVO ==  3)<< MSK_U32_ISM_BLOCK_VKL_VVO),
ISM_BLOCK_VKL_VVO_CMD_04 = ((IDX_U32_ISM_BLOCK_VKL_VVO ==  4)<< MSK_U32_ISM_BLOCK_VKL_VVO),
ISM_BLOCK_VKL_VVO_CMD_05 = ((IDX_U32_ISM_BLOCK_VKL_VVO ==  5)<< MSK_U32_ISM_BLOCK_VKL_VVO),
ISM_BLOCK_VKL_VVO_CMD_06 = ((IDX_U32_ISM_BLOCK_VKL_VVO ==  6)<< MSK_U32_ISM_BLOCK_VKL_VVO),
ISM_BLOCK_VKL_VVO_CMD_07 = ((IDX_U32_ISM_BLOCK_VKL_VVO ==  7)<< MSK_U32_ISM_BLOCK_VKL_VVO),
ISM_BLOCK_VKL_VVO_CMD_08 = ((IDX_U32_ISM_BLOCK_VKL_VVO ==  8)<< MSK_U32_ISM_BLOCK_VKL_VVO),
ISM_BLOCK_VKL_VVO_CMD_09 = ((IDX_U32_ISM_BLOCK_VKL_VVO ==  9)<< MSK_U32_ISM_BLOCK_VKL_VVO),
ISM_BLOCK_VKL_VVO_CMD_10 = ((IDX_U32_ISM_BLOCK_VKL_VVO == 10)<< MSK_U32_ISM_BLOCK_VKL_VVO),
ISM_BLOCK_VKL_VVO_CMD_11 = ((IDX_U32_ISM_BLOCK_VKL_VVO == 11)<< MSK_U32_ISM_BLOCK_VKL_VVO),
ISM_BLOCK_VKL_VVO_CMD_12 = ((IDX_U32_ISM_BLOCK_VKL_VVO == 12)<< MSK_U32_ISM_BLOCK_VKL_VVO),
                    
                    
ISM_BLOCK_VKL_VVP_CMD_00 = ((IDX_U32_ISM_BLOCK_VKL_VVP ==  0)<< MSK_U32_ISM_BLOCK_VKL_VVP),
ISM_BLOCK_VKL_VVP_CMD_01 = ((IDX_U32_ISM_BLOCK_VKL_VVP ==  1)<< MSK_U32_ISM_BLOCK_VKL_VVP),
ISM_BLOCK_VKL_VVP_CMD_02 = ((IDX_U32_ISM_BLOCK_VKL_VVP ==  2)<< MSK_U32_ISM_BLOCK_VKL_VVP),
ISM_BLOCK_VKL_VVP_CMD_03 = ((IDX_U32_ISM_BLOCK_VKL_VVP ==  3)<< MSK_U32_ISM_BLOCK_VKL_VVP),
ISM_BLOCK_VKL_VVP_CMD_04 = ((IDX_U32_ISM_BLOCK_VKL_VVP ==  4)<< MSK_U32_ISM_BLOCK_VKL_VVP),
ISM_BLOCK_VKL_VVP_CMD_05 = ((IDX_U32_ISM_BLOCK_VKL_VVP ==  5)<< MSK_U32_ISM_BLOCK_VKL_VVP),
ISM_BLOCK_VKL_VVP_CMD_06 = ((IDX_U32_ISM_BLOCK_VKL_VVP ==  6)<< MSK_U32_ISM_BLOCK_VKL_VVP),
ISM_BLOCK_VKL_VVP_CMD_07 = ((IDX_U32_ISM_BLOCK_VKL_VVP ==  7)<< MSK_U32_ISM_BLOCK_VKL_VVP),
ISM_BLOCK_VKL_VVP_CMD_08 = ((IDX_U32_ISM_BLOCK_VKL_VVP ==  8)<< MSK_U32_ISM_BLOCK_VKL_VVP),
ISM_BLOCK_VKL_VVP_CMD_09 = ((IDX_U32_ISM_BLOCK_VKL_VVP ==  9)<< MSK_U32_ISM_BLOCK_VKL_VVP),
ISM_BLOCK_VKL_VVP_CMD_10 = ((IDX_U32_ISM_BLOCK_VKL_VVP == 10)<< MSK_U32_ISM_BLOCK_VKL_VVP),
ISM_BLOCK_VKL_VVP_CMD_11 = ((IDX_U32_ISM_BLOCK_VKL_VVP == 11)<< MSK_U32_ISM_BLOCK_VKL_VVP),
ISM_BLOCK_VKL_VVP_CMD_12 = ((IDX_U32_ISM_BLOCK_VKL_VVP == 12)<< MSK_U32_ISM_BLOCK_VKL_VVP),
                    
                    
ISM_RESET_LEDS_CMD_00 = ((IDX_U32_ISM_RESET_LEDS ==  0)<< MSK_U32_ISM_RESET_LEDS),
ISM_RESET_LEDS_CMD_01 = ((IDX_U32_ISM_RESET_LEDS ==  1)<< MSK_U32_ISM_RESET_LEDS),
ISM_RESET_LEDS_CMD_02 = ((IDX_U32_ISM_RESET_LEDS ==  2)<< MSK_U32_ISM_RESET_LEDS),
ISM_RESET_LEDS_CMD_03 = ((IDX_U32_ISM_RESET_LEDS ==  3)<< MSK_U32_ISM_RESET_LEDS),
ISM_RESET_LEDS_CMD_04 = ((IDX_U32_ISM_RESET_LEDS ==  4)<< MSK_U32_ISM_RESET_LEDS),
ISM_RESET_LEDS_CMD_05 = ((IDX_U32_ISM_RESET_LEDS ==  5)<< MSK_U32_ISM_RESET_LEDS),
ISM_RESET_LEDS_CMD_06 = ((IDX_U32_ISM_RESET_LEDS ==  6)<< MSK_U32_ISM_RESET_LEDS),
ISM_RESET_LEDS_CMD_07 = ((IDX_U32_ISM_RESET_LEDS ==  7)<< MSK_U32_ISM_RESET_LEDS),
ISM_RESET_LEDS_CMD_08 = ((IDX_U32_ISM_RESET_LEDS ==  8)<< MSK_U32_ISM_RESET_LEDS),
ISM_RESET_LEDS_CMD_09 = ((IDX_U32_ISM_RESET_LEDS ==  9)<< MSK_U32_ISM_RESET_LEDS),
ISM_RESET_LEDS_CMD_10 = ((IDX_U32_ISM_RESET_LEDS == 10)<< MSK_U32_ISM_RESET_LEDS),
ISM_RESET_LEDS_CMD_11 = ((IDX_U32_ISM_RESET_LEDS == 11)<< MSK_U32_ISM_RESET_LEDS),
ISM_RESET_LEDS_CMD_12 = ((IDX_U32_ISM_RESET_LEDS == 12)<< MSK_U32_ISM_RESET_LEDS),
                    
                    
ISM_RESET_RELES_CMD_00 = ((IDX_U32_ISM_RESET_RELES  ==  0)<< MSK_U32_ISM_RESET_RELES ),
ISM_RESET_RELES_CMD_01 = ((IDX_U32_ISM_RESET_RELES  ==  1)<< MSK_U32_ISM_RESET_RELES ),
ISM_RESET_RELES_CMD_02 = ((IDX_U32_ISM_RESET_RELES  ==  2)<< MSK_U32_ISM_RESET_RELES ),
ISM_RESET_RELES_CMD_03 = ((IDX_U32_ISM_RESET_RELES  ==  3)<< MSK_U32_ISM_RESET_RELES ),
ISM_RESET_RELES_CMD_04 = ((IDX_U32_ISM_RESET_RELES  ==  4)<< MSK_U32_ISM_RESET_RELES ),
ISM_RESET_RELES_CMD_05 = ((IDX_U32_ISM_RESET_RELES  ==  5)<< MSK_U32_ISM_RESET_RELES ),
ISM_RESET_RELES_CMD_06 = ((IDX_U32_ISM_RESET_RELES  ==  6)<< MSK_U32_ISM_RESET_RELES ),
ISM_RESET_RELES_CMD_07 = ((IDX_U32_ISM_RESET_RELES  ==  7)<< MSK_U32_ISM_RESET_RELES ),
ISM_RESET_RELES_CMD_08 = ((IDX_U32_ISM_RESET_RELES  ==  8)<< MSK_U32_ISM_RESET_RELES ),
ISM_RESET_RELES_CMD_09 = ((IDX_U32_ISM_RESET_RELES  ==  9)<< MSK_U32_ISM_RESET_RELES ),
ISM_RESET_RELES_CMD_10 = ((IDX_U32_ISM_RESET_RELES  == 10)<< MSK_U32_ISM_RESET_RELES ),
ISM_RESET_RELES_CMD_11 = ((IDX_U32_ISM_RESET_RELES  == 11)<< MSK_U32_ISM_RESET_RELES ),
ISM_RESET_RELES_CMD_12 = ((IDX_U32_ISM_RESET_RELES  == 12)<< MSK_U32_ISM_RESET_RELES ),

ISM_MISCEVE_DYSTANCIJNE_CMD_00 = ((IDX_U32_ISM_MISCEVE_DYSTANCIJNE ==  0)<< MSK_U32_ISM_MISCEVE_DYSTANCIJNE),
ISM_MISCEVE_DYSTANCIJNE_CMD_01 = ((IDX_U32_ISM_MISCEVE_DYSTANCIJNE ==  1)<< MSK_U32_ISM_MISCEVE_DYSTANCIJNE),
ISM_MISCEVE_DYSTANCIJNE_CMD_02 = ((IDX_U32_ISM_MISCEVE_DYSTANCIJNE ==  2)<< MSK_U32_ISM_MISCEVE_DYSTANCIJNE),
ISM_MISCEVE_DYSTANCIJNE_CMD_03 = ((IDX_U32_ISM_MISCEVE_DYSTANCIJNE ==  3)<< MSK_U32_ISM_MISCEVE_DYSTANCIJNE),
ISM_MISCEVE_DYSTANCIJNE_CMD_04 = ((IDX_U32_ISM_MISCEVE_DYSTANCIJNE ==  4)<< MSK_U32_ISM_MISCEVE_DYSTANCIJNE),
ISM_MISCEVE_DYSTANCIJNE_CMD_05 = ((IDX_U32_ISM_MISCEVE_DYSTANCIJNE ==  5)<< MSK_U32_ISM_MISCEVE_DYSTANCIJNE),
ISM_MISCEVE_DYSTANCIJNE_CMD_06 = ((IDX_U32_ISM_MISCEVE_DYSTANCIJNE ==  6)<< MSK_U32_ISM_MISCEVE_DYSTANCIJNE),
ISM_MISCEVE_DYSTANCIJNE_CMD_07 = ((IDX_U32_ISM_MISCEVE_DYSTANCIJNE ==  7)<< MSK_U32_ISM_MISCEVE_DYSTANCIJNE),
ISM_MISCEVE_DYSTANCIJNE_CMD_08 = ((IDX_U32_ISM_MISCEVE_DYSTANCIJNE ==  8)<< MSK_U32_ISM_MISCEVE_DYSTANCIJNE),
ISM_MISCEVE_DYSTANCIJNE_CMD_09 = ((IDX_U32_ISM_MISCEVE_DYSTANCIJNE ==  9)<< MSK_U32_ISM_MISCEVE_DYSTANCIJNE),
ISM_MISCEVE_DYSTANCIJNE_CMD_10 = ((IDX_U32_ISM_MISCEVE_DYSTANCIJNE == 10)<< MSK_U32_ISM_MISCEVE_DYSTANCIJNE),
ISM_MISCEVE_DYSTANCIJNE_CMD_11 = ((IDX_U32_ISM_MISCEVE_DYSTANCIJNE == 11)<< MSK_U32_ISM_MISCEVE_DYSTANCIJNE),
ISM_MISCEVE_DYSTANCIJNE_CMD_12 = ((IDX_U32_ISM_MISCEVE_DYSTANCIJNE == 12)<< MSK_U32_ISM_MISCEVE_DYSTANCIJNE),
                    
                    
ISM_STATE_VVR_CMD_00 = ((IDX_U32_ISM_STATE_VVR ==  0)<< MSK_U32_ISM_STATE_VVR),
ISM_STATE_VVR_CMD_01 = ((IDX_U32_ISM_STATE_VVR ==  1)<< MSK_U32_ISM_STATE_VVR),
ISM_STATE_VVR_CMD_02 = ((IDX_U32_ISM_STATE_VVR ==  2)<< MSK_U32_ISM_STATE_VVR),
ISM_STATE_VVR_CMD_03 = ((IDX_U32_ISM_STATE_VVR ==  3)<< MSK_U32_ISM_STATE_VVR),
ISM_STATE_VVR_CMD_04 = ((IDX_U32_ISM_STATE_VVR ==  4)<< MSK_U32_ISM_STATE_VVR),
ISM_STATE_VVR_CMD_05 = ((IDX_U32_ISM_STATE_VVR ==  5)<< MSK_U32_ISM_STATE_VVR),
ISM_STATE_VVR_CMD_06 = ((IDX_U32_ISM_STATE_VVR ==  6)<< MSK_U32_ISM_STATE_VVR),
ISM_STATE_VVR_CMD_07 = ((IDX_U32_ISM_STATE_VVR ==  7)<< MSK_U32_ISM_STATE_VVR),
ISM_STATE_VVR_CMD_08 = ((IDX_U32_ISM_STATE_VVR ==  8)<< MSK_U32_ISM_STATE_VVR),
ISM_STATE_VVR_CMD_09 = ((IDX_U32_ISM_STATE_VVR ==  9)<< MSK_U32_ISM_STATE_VVR),
ISM_STATE_VVR_CMD_10 = ((IDX_U32_ISM_STATE_VVR == 10)<< MSK_U32_ISM_STATE_VVR),
ISM_STATE_VVR_CMD_11 = ((IDX_U32_ISM_STATE_VVR == 11)<< MSK_U32_ISM_STATE_VVR),
ISM_STATE_VVR_CMD_12 = ((IDX_U32_ISM_STATE_VVR == 12)<< MSK_U32_ISM_STATE_VVR),
                    
                    
ISM_STATE_VVO_CMD_00 = ((IDX_U32_ISM_STATE_VVO ==  0)<< MSK_U32_ISM_STATE_VVO),
ISM_STATE_VVO_CMD_01 = ((IDX_U32_ISM_STATE_VVO ==  1)<< MSK_U32_ISM_STATE_VVO),
ISM_STATE_VVO_CMD_02 = ((IDX_U32_ISM_STATE_VVO ==  2)<< MSK_U32_ISM_STATE_VVO),
ISM_STATE_VVO_CMD_03 = ((IDX_U32_ISM_STATE_VVO ==  3)<< MSK_U32_ISM_STATE_VVO),
ISM_STATE_VVO_CMD_04 = ((IDX_U32_ISM_STATE_VVO ==  4)<< MSK_U32_ISM_STATE_VVO),
ISM_STATE_VVO_CMD_05 = ((IDX_U32_ISM_STATE_VVO ==  5)<< MSK_U32_ISM_STATE_VVO),
ISM_STATE_VVO_CMD_06 = ((IDX_U32_ISM_STATE_VVO ==  6)<< MSK_U32_ISM_STATE_VVO),
ISM_STATE_VVO_CMD_07 = ((IDX_U32_ISM_STATE_VVO ==  7)<< MSK_U32_ISM_STATE_VVO),
ISM_STATE_VVO_CMD_08 = ((IDX_U32_ISM_STATE_VVO ==  8)<< MSK_U32_ISM_STATE_VVO),
ISM_STATE_VVO_CMD_09 = ((IDX_U32_ISM_STATE_VVO ==  9)<< MSK_U32_ISM_STATE_VVO),
ISM_STATE_VVO_CMD_10 = ((IDX_U32_ISM_STATE_VVO == 10)<< MSK_U32_ISM_STATE_VVO),
ISM_STATE_VVO_CMD_11 = ((IDX_U32_ISM_STATE_VVO == 11)<< MSK_U32_ISM_STATE_VVO),
ISM_STATE_VVO_CMD_12 = ((IDX_U32_ISM_STATE_VVO == 12)<< MSK_U32_ISM_STATE_VVO),
                    
                    
ISM_VKL_VVO_CMD_00 = ((IDX_U32_ISM_VKL_VVO ==  0)<< MSK_U32_ISM_VKL_VVO),
ISM_VKL_VVO_CMD_01 = ((IDX_U32_ISM_VKL_VVO ==  1)<< MSK_U32_ISM_VKL_VVO),
ISM_VKL_VVO_CMD_02 = ((IDX_U32_ISM_VKL_VVO ==  2)<< MSK_U32_ISM_VKL_VVO),
ISM_VKL_VVO_CMD_03 = ((IDX_U32_ISM_VKL_VVO ==  3)<< MSK_U32_ISM_VKL_VVO),
ISM_VKL_VVO_CMD_04 = ((IDX_U32_ISM_VKL_VVO ==  4)<< MSK_U32_ISM_VKL_VVO),
ISM_VKL_VVO_CMD_05 = ((IDX_U32_ISM_VKL_VVO ==  5)<< MSK_U32_ISM_VKL_VVO),
ISM_VKL_VVO_CMD_06 = ((IDX_U32_ISM_VKL_VVO ==  6)<< MSK_U32_ISM_VKL_VVO),
ISM_VKL_VVO_CMD_07 = ((IDX_U32_ISM_VKL_VVO ==  7)<< MSK_U32_ISM_VKL_VVO),
ISM_VKL_VVO_CMD_08 = ((IDX_U32_ISM_VKL_VVO ==  8)<< MSK_U32_ISM_VKL_VVO),
ISM_VKL_VVO_CMD_09 = ((IDX_U32_ISM_VKL_VVO ==  9)<< MSK_U32_ISM_VKL_VVO),
ISM_VKL_VVO_CMD_10 = ((IDX_U32_ISM_VKL_VVO == 10)<< MSK_U32_ISM_VKL_VVO),
ISM_VKL_VVO_CMD_11 = ((IDX_U32_ISM_VKL_VVO == 11)<< MSK_U32_ISM_VKL_VVO),
ISM_VKL_VVO_CMD_12 = ((IDX_U32_ISM_VKL_VVO == 12)<< MSK_U32_ISM_VKL_VVO),

ISM_VKL_VVR_CMD_00  = ((  IDX_U32_ISM_VKL_VVR  ==  0)<<   MSK_U32_ISM_VKL_VVR ),
ISM_VKL_VVR_CMD_01  = ((  IDX_U32_ISM_VKL_VVR  ==  1)<<   MSK_U32_ISM_VKL_VVR ),
ISM_VKL_VVR_CMD_02  = ((  IDX_U32_ISM_VKL_VVR  ==  2)<<   MSK_U32_ISM_VKL_VVR ),
ISM_VKL_VVR_CMD_03  = ((  IDX_U32_ISM_VKL_VVR  ==  3)<<   MSK_U32_ISM_VKL_VVR ),
ISM_VKL_VVR_CMD_04  = ((  IDX_U32_ISM_VKL_VVR  ==  4)<<   MSK_U32_ISM_VKL_VVR ),
ISM_VKL_VVR_CMD_05  = ((  IDX_U32_ISM_VKL_VVR  ==  5)<<   MSK_U32_ISM_VKL_VVR ),
ISM_VKL_VVR_CMD_06  = ((  IDX_U32_ISM_VKL_VVR  ==  6)<<   MSK_U32_ISM_VKL_VVR ),
ISM_VKL_VVR_CMD_07  = ((  IDX_U32_ISM_VKL_VVR  ==  7)<<   MSK_U32_ISM_VKL_VVR ),
ISM_VKL_VVR_CMD_08  = ((  IDX_U32_ISM_VKL_VVR  ==  8)<<   MSK_U32_ISM_VKL_VVR ),
ISM_VKL_VVR_CMD_09  = ((  IDX_U32_ISM_VKL_VVR  ==  9)<<   MSK_U32_ISM_VKL_VVR ),
ISM_VKL_VVR_CMD_10  = ((  IDX_U32_ISM_VKL_VVR  == 10)<<   MSK_U32_ISM_VKL_VVR ),
ISM_VKL_VVR_CMD_11  = ((  IDX_U32_ISM_VKL_VVR  == 11)<<   MSK_U32_ISM_VKL_VVR ),
ISM_VKL_VVR_CMD_12  = ((  IDX_U32_ISM_VKL_VVR  == 12)<<   MSK_U32_ISM_VKL_VVR ),
                    
                    
ISM_CTRL_VKL_VVO_CMD_00  = ((  IDX_U32_ISM_CTRL_VKL_VVO  ==  0)<<   MSK_U32_ISM_CTRL_VKL_VVO ),
ISM_CTRL_VKL_VVO_CMD_01  = ((  IDX_U32_ISM_CTRL_VKL_VVO  ==  1)<<   MSK_U32_ISM_CTRL_VKL_VVO ),
ISM_CTRL_VKL_VVO_CMD_02  = ((  IDX_U32_ISM_CTRL_VKL_VVO  ==  2)<<   MSK_U32_ISM_CTRL_VKL_VVO ),
ISM_CTRL_VKL_VVO_CMD_03  = ((  IDX_U32_ISM_CTRL_VKL_VVO  ==  3)<<   MSK_U32_ISM_CTRL_VKL_VVO ),
ISM_CTRL_VKL_VVO_CMD_04  = ((  IDX_U32_ISM_CTRL_VKL_VVO  ==  4)<<   MSK_U32_ISM_CTRL_VKL_VVO ),
ISM_CTRL_VKL_VVO_CMD_05  = ((  IDX_U32_ISM_CTRL_VKL_VVO  ==  5)<<   MSK_U32_ISM_CTRL_VKL_VVO ),
ISM_CTRL_VKL_VVO_CMD_06  = ((  IDX_U32_ISM_CTRL_VKL_VVO  ==  6)<<   MSK_U32_ISM_CTRL_VKL_VVO ),
ISM_CTRL_VKL_VVO_CMD_07  = ((  IDX_U32_ISM_CTRL_VKL_VVO  ==  7)<<   MSK_U32_ISM_CTRL_VKL_VVO ),
ISM_CTRL_VKL_VVO_CMD_08  = ((  IDX_U32_ISM_CTRL_VKL_VVO  ==  8)<<   MSK_U32_ISM_CTRL_VKL_VVO ),
ISM_CTRL_VKL_VVO_CMD_09  = ((  IDX_U32_ISM_CTRL_VKL_VVO  ==  9)<<   MSK_U32_ISM_CTRL_VKL_VVO ),
ISM_CTRL_VKL_VVO_CMD_10  = ((  IDX_U32_ISM_CTRL_VKL_VVO  == 10)<<   MSK_U32_ISM_CTRL_VKL_VVO ),
ISM_CTRL_VKL_VVO_CMD_11  = ((  IDX_U32_ISM_CTRL_VKL_VVO  == 11)<<   MSK_U32_ISM_CTRL_VKL_VVO ),
ISM_CTRL_VKL_VVO_CMD_12  = ((  IDX_U32_ISM_CTRL_VKL_VVO  == 12)<<   MSK_U32_ISM_CTRL_VKL_VVO ),
                    
                    
ISM_CTRL_VKL_VVR_CMD_00  = ((  IDX_U32_ISM_CTRL_VKL_VVR  ==  0)<<   MSK_U32_ISM_CTRL_VKL_VVR ),
ISM_CTRL_VKL_VVR_CMD_01  = ((  IDX_U32_ISM_CTRL_VKL_VVR  ==  1)<<   MSK_U32_ISM_CTRL_VKL_VVR ),
ISM_CTRL_VKL_VVR_CMD_02  = ((  IDX_U32_ISM_CTRL_VKL_VVR  ==  2)<<   MSK_U32_ISM_CTRL_VKL_VVR ),
ISM_CTRL_VKL_VVR_CMD_03  = ((  IDX_U32_ISM_CTRL_VKL_VVR  ==  3)<<   MSK_U32_ISM_CTRL_VKL_VVR ),
ISM_CTRL_VKL_VVR_CMD_04  = ((  IDX_U32_ISM_CTRL_VKL_VVR  ==  4)<<   MSK_U32_ISM_CTRL_VKL_VVR ),
ISM_CTRL_VKL_VVR_CMD_05  = ((  IDX_U32_ISM_CTRL_VKL_VVR  ==  5)<<   MSK_U32_ISM_CTRL_VKL_VVR ),
ISM_CTRL_VKL_VVR_CMD_06  = ((  IDX_U32_ISM_CTRL_VKL_VVR  ==  6)<<   MSK_U32_ISM_CTRL_VKL_VVR ),
ISM_CTRL_VKL_VVR_CMD_07  = ((  IDX_U32_ISM_CTRL_VKL_VVR  ==  7)<<   MSK_U32_ISM_CTRL_VKL_VVR ),
ISM_CTRL_VKL_VVR_CMD_08  = ((  IDX_U32_ISM_CTRL_VKL_VVR  ==  8)<<   MSK_U32_ISM_CTRL_VKL_VVR ),
ISM_CTRL_VKL_VVR_CMD_09  = ((  IDX_U32_ISM_CTRL_VKL_VVR  ==  9)<<   MSK_U32_ISM_CTRL_VKL_VVR ),
ISM_CTRL_VKL_VVR_CMD_10  = ((  IDX_U32_ISM_CTRL_VKL_VVR  == 10)<<   MSK_U32_ISM_CTRL_VKL_VVR ),
ISM_CTRL_VKL_VVR_CMD_11  = ((  IDX_U32_ISM_CTRL_VKL_VVR  == 11)<<   MSK_U32_ISM_CTRL_VKL_VVR ),
ISM_CTRL_VKL_VVR_CMD_12  = ((  IDX_U32_ISM_CTRL_VKL_VVR  == 12)<<   MSK_U32_ISM_CTRL_VKL_VVR ),
                    
                    
ISM_OTKL_VV_VVO_CMD_00  = ((  IDX_U32_ISM_OTKL_VV_VVO   ==  0)<<   MSK_U32_ISM_OTKL_VV_VVO  ),
ISM_OTKL_VV_VVO_CMD_01  = ((  IDX_U32_ISM_OTKL_VV_VVO   ==  1)<<   MSK_U32_ISM_OTKL_VV_VVO  ),
ISM_OTKL_VV_VVO_CMD_02  = ((  IDX_U32_ISM_OTKL_VV_VVO   ==  2)<<   MSK_U32_ISM_OTKL_VV_VVO  ),
ISM_OTKL_VV_VVO_CMD_03  = ((  IDX_U32_ISM_OTKL_VV_VVO   ==  3)<<   MSK_U32_ISM_OTKL_VV_VVO  ),
ISM_OTKL_VV_VVO_CMD_04  = ((  IDX_U32_ISM_OTKL_VV_VVO   ==  4)<<   MSK_U32_ISM_OTKL_VV_VVO  ),
ISM_OTKL_VV_VVO_CMD_05  = ((  IDX_U32_ISM_OTKL_VV_VVO   ==  5)<<   MSK_U32_ISM_OTKL_VV_VVO  ),
ISM_OTKL_VV_VVO_CMD_06  = ((  IDX_U32_ISM_OTKL_VV_VVO   ==  6)<<   MSK_U32_ISM_OTKL_VV_VVO  ),
ISM_OTKL_VV_VVO_CMD_07  = ((  IDX_U32_ISM_OTKL_VV_VVO   ==  7)<<   MSK_U32_ISM_OTKL_VV_VVO  ),
ISM_OTKL_VV_VVO_CMD_08  = ((  IDX_U32_ISM_OTKL_VV_VVO   ==  8)<<   MSK_U32_ISM_OTKL_VV_VVO  ),
ISM_OTKL_VV_VVO_CMD_09  = ((  IDX_U32_ISM_OTKL_VV_VVO   ==  9)<<   MSK_U32_ISM_OTKL_VV_VVO  ),
ISM_OTKL_VV_VVO_CMD_10  = ((  IDX_U32_ISM_OTKL_VV_VVO   == 10)<<   MSK_U32_ISM_OTKL_VV_VVO  ),
ISM_OTKL_VV_VVO_CMD_11  = ((  IDX_U32_ISM_OTKL_VV_VVO   == 11)<<   MSK_U32_ISM_OTKL_VV_VVO  ),
ISM_OTKL_VV_VVO_CMD_12  = ((  IDX_U32_ISM_OTKL_VV_VVO   == 12)<<   MSK_U32_ISM_OTKL_VV_VVO  ),

ISM_OTKL_VV_VVR_CMD_00  = ((IDX_U32_ISM_OTKL_VV_VVR ==  0)<< MSK_U32_ISM_OTKL_VV_VVR),
ISM_OTKL_VV_VVR_CMD_01  = ((IDX_U32_ISM_OTKL_VV_VVR ==  1)<< MSK_U32_ISM_OTKL_VV_VVR),
ISM_OTKL_VV_VVR_CMD_02  = ((IDX_U32_ISM_OTKL_VV_VVR ==  2)<< MSK_U32_ISM_OTKL_VV_VVR),
ISM_OTKL_VV_VVR_CMD_03  = ((IDX_U32_ISM_OTKL_VV_VVR ==  3)<< MSK_U32_ISM_OTKL_VV_VVR),
ISM_OTKL_VV_VVR_CMD_04  = ((IDX_U32_ISM_OTKL_VV_VVR ==  4)<< MSK_U32_ISM_OTKL_VV_VVR),
ISM_OTKL_VV_VVR_CMD_05  = ((IDX_U32_ISM_OTKL_VV_VVR ==  5)<< MSK_U32_ISM_OTKL_VV_VVR),
ISM_OTKL_VV_VVR_CMD_06  = ((IDX_U32_ISM_OTKL_VV_VVR ==  6)<< MSK_U32_ISM_OTKL_VV_VVR),
ISM_OTKL_VV_VVR_CMD_07  = ((IDX_U32_ISM_OTKL_VV_VVR ==  7)<< MSK_U32_ISM_OTKL_VV_VVR),
ISM_OTKL_VV_VVR_CMD_08  = ((IDX_U32_ISM_OTKL_VV_VVR ==  8)<< MSK_U32_ISM_OTKL_VV_VVR),
ISM_OTKL_VV_VVR_CMD_09  = ((IDX_U32_ISM_OTKL_VV_VVR ==  9)<< MSK_U32_ISM_OTKL_VV_VVR),
ISM_OTKL_VV_VVR_CMD_10  = ((IDX_U32_ISM_OTKL_VV_VVR == 10)<< MSK_U32_ISM_OTKL_VV_VVR),
ISM_OTKL_VV_VVR_CMD_11  = ((IDX_U32_ISM_OTKL_VV_VVR == 11)<< MSK_U32_ISM_OTKL_VV_VVR),
ISM_OTKL_VV_VVR_CMD_12  = ((IDX_U32_ISM_OTKL_VV_VVR == 12)<< MSK_U32_ISM_OTKL_VV_VVR),
                    
            
       
                    
                    
ISM_CTRL_OTKL_VVO_CMD_00 = ((IDX_U32_ISM_CTRL_OTKL_VVO ==  0)<< MSK_U32_ISM_CTRL_OTKL_VVO  ),
ISM_CTRL_OTKL_VVO_CMD_01 = ((IDX_U32_ISM_CTRL_OTKL_VVO ==  1)<< MSK_U32_ISM_CTRL_OTKL_VVO  ),
ISM_CTRL_OTKL_VVO_CMD_02 = ((IDX_U32_ISM_CTRL_OTKL_VVO ==  2)<< MSK_U32_ISM_CTRL_OTKL_VVO  ),
ISM_CTRL_OTKL_VVO_CMD_03 = ((IDX_U32_ISM_CTRL_OTKL_VVO ==  3)<< MSK_U32_ISM_CTRL_OTKL_VVO  ),
ISM_CTRL_OTKL_VVO_CMD_04 = ((IDX_U32_ISM_CTRL_OTKL_VVO ==  4)<< MSK_U32_ISM_CTRL_OTKL_VVO  ),
ISM_CTRL_OTKL_VVO_CMD_05 = ((IDX_U32_ISM_CTRL_OTKL_VVO ==  5)<< MSK_U32_ISM_CTRL_OTKL_VVO  ),
ISM_CTRL_OTKL_VVO_CMD_06 = ((IDX_U32_ISM_CTRL_OTKL_VVO ==  6)<< MSK_U32_ISM_CTRL_OTKL_VVO  ),
ISM_CTRL_OTKL_VVO_CMD_07 = ((IDX_U32_ISM_CTRL_OTKL_VVO ==  7)<< MSK_U32_ISM_CTRL_OTKL_VVO  ),
ISM_CTRL_OTKL_VVO_CMD_08 = ((IDX_U32_ISM_CTRL_OTKL_VVO ==  8)<< MSK_U32_ISM_CTRL_OTKL_VVO  ),
ISM_CTRL_OTKL_VVO_CMD_09 = ((IDX_U32_ISM_CTRL_OTKL_VVO ==  9)<< MSK_U32_ISM_CTRL_OTKL_VVO  ),
ISM_CTRL_OTKL_VVO_CMD_10 = ((IDX_U32_ISM_CTRL_OTKL_VVO == 10)<< MSK_U32_ISM_CTRL_OTKL_VVO  ),
ISM_CTRL_OTKL_VVO_CMD_11 = ((IDX_U32_ISM_CTRL_OTKL_VVO == 11)<< MSK_U32_ISM_CTRL_OTKL_VVO  ),
ISM_CTRL_OTKL_VVO_CMD_12 = ((IDX_U32_ISM_CTRL_OTKL_VVO == 12)<< MSK_U32_ISM_CTRL_OTKL_VVO  ),
                    
                    
ISM_CTRL_OTKL_VVR_CMD_00 = ((IDX_U32_ISM_CTRL_OTKL_VVR   ==  0)<< MSK_U32_ISM_CTRL_OTKL_VVR  ),
ISM_CTRL_OTKL_VVR_CMD_01 = ((IDX_U32_ISM_CTRL_OTKL_VVR   ==  1)<< MSK_U32_ISM_CTRL_OTKL_VVR  ),
ISM_CTRL_OTKL_VVR_CMD_02 = ((IDX_U32_ISM_CTRL_OTKL_VVR   ==  2)<< MSK_U32_ISM_CTRL_OTKL_VVR  ),
ISM_CTRL_OTKL_VVR_CMD_03 = ((IDX_U32_ISM_CTRL_OTKL_VVR   ==  3)<< MSK_U32_ISM_CTRL_OTKL_VVR  ),
ISM_CTRL_OTKL_VVR_CMD_04 = ((IDX_U32_ISM_CTRL_OTKL_VVR   ==  4)<< MSK_U32_ISM_CTRL_OTKL_VVR  ),
ISM_CTRL_OTKL_VVR_CMD_05 = ((IDX_U32_ISM_CTRL_OTKL_VVR   ==  5)<< MSK_U32_ISM_CTRL_OTKL_VVR  ),
ISM_CTRL_OTKL_VVR_CMD_06 = ((IDX_U32_ISM_CTRL_OTKL_VVR   ==  6)<< MSK_U32_ISM_CTRL_OTKL_VVR  ),
ISM_CTRL_OTKL_VVR_CMD_07 = ((IDX_U32_ISM_CTRL_OTKL_VVR   ==  7)<< MSK_U32_ISM_CTRL_OTKL_VVR  ),
ISM_CTRL_OTKL_VVR_CMD_08 = ((IDX_U32_ISM_CTRL_OTKL_VVR   ==  8)<< MSK_U32_ISM_CTRL_OTKL_VVR  ),
ISM_CTRL_OTKL_VVR_CMD_09 = ((IDX_U32_ISM_CTRL_OTKL_VVR   ==  9)<< MSK_U32_ISM_CTRL_OTKL_VVR  ),
ISM_CTRL_OTKL_VVR_CMD_10 = ((IDX_U32_ISM_CTRL_OTKL_VVR   == 10)<< MSK_U32_ISM_CTRL_OTKL_VVR  ),
ISM_CTRL_OTKL_VVR_CMD_11 = ((IDX_U32_ISM_CTRL_OTKL_VVR   == 11)<< MSK_U32_ISM_CTRL_OTKL_VVR  ),
ISM_CTRL_OTKL_VVR_CMD_12 = ((IDX_U32_ISM_CTRL_OTKL_VVR   == 12)<< MSK_U32_ISM_CTRL_OTKL_VVR  ),
                    
                    
//ISM_1_GRUPA_USTAVOK_CMD_00 = ((IDX_U32_ISM_1_GRUPA_USTAVOK ==  0)<< MSK_U32_ISM_1_GRUPA_USTAVOK),
//ISM_1_GRUPA_USTAVOK_CMD_01 = ((IDX_U32_ISM_1_GRUPA_USTAVOK ==  1)<< MSK_U32_ISM_1_GRUPA_USTAVOK),
//ISM_1_GRUPA_USTAVOK_CMD_02 = ((IDX_U32_ISM_1_GRUPA_USTAVOK ==  2)<< MSK_U32_ISM_1_GRUPA_USTAVOK),
//ISM_1_GRUPA_USTAVOK_CMD_03 = ((IDX_U32_ISM_1_GRUPA_USTAVOK ==  3)<< MSK_U32_ISM_1_GRUPA_USTAVOK),
//ISM_1_GRUPA_USTAVOK_CMD_04 = ((IDX_U32_ISM_1_GRUPA_USTAVOK ==  4)<< MSK_U32_ISM_1_GRUPA_USTAVOK),
//ISM_1_GRUPA_USTAVOK_CMD_05 = ((IDX_U32_ISM_1_GRUPA_USTAVOK ==  5)<< MSK_U32_ISM_1_GRUPA_USTAVOK),
//ISM_1_GRUPA_USTAVOK_CMD_06 = ((IDX_U32_ISM_1_GRUPA_USTAVOK ==  6)<< MSK_U32_ISM_1_GRUPA_USTAVOK),
//ISM_1_GRUPA_USTAVOK_CMD_07 = ((IDX_U32_ISM_1_GRUPA_USTAVOK ==  7)<< MSK_U32_ISM_1_GRUPA_USTAVOK),
//ISM_1_GRUPA_USTAVOK_CMD_08 = ((IDX_U32_ISM_1_GRUPA_USTAVOK ==  8)<< MSK_U32_ISM_1_GRUPA_USTAVOK),
//ISM_1_GRUPA_USTAVOK_CMD_09 = ((IDX_U32_ISM_1_GRUPA_USTAVOK ==  9)<< MSK_U32_ISM_1_GRUPA_USTAVOK),
//ISM_1_GRUPA_USTAVOK_CMD_10 = ((IDX_U32_ISM_1_GRUPA_USTAVOK == 10)<< MSK_U32_ISM_1_GRUPA_USTAVOK),
//ISM_1_GRUPA_USTAVOK_CMD_11 = ((IDX_U32_ISM_1_GRUPA_USTAVOK == 11)<< MSK_U32_ISM_1_GRUPA_USTAVOK),
//ISM_1_GRUPA_USTAVOK_CMD_12 = ((IDX_U32_ISM_1_GRUPA_USTAVOK == 12)<< MSK_U32_ISM_1_GRUPA_USTAVOK),

//ISM_2_GRUPA_USTAVOK_CMD_00 = (( IDX_U32_ISM_2_GRUPA_USTAVOK  ==  0)<< MSK_U32_ISM_2_GRUPA_USTAVOK ),
//ISM_2_GRUPA_USTAVOK_CMD_01 = (( IDX_U32_ISM_2_GRUPA_USTAVOK  ==  1)<< MSK_U32_ISM_2_GRUPA_USTAVOK ),
//ISM_2_GRUPA_USTAVOK_CMD_02 = (( IDX_U32_ISM_2_GRUPA_USTAVOK  ==  2)<< MSK_U32_ISM_2_GRUPA_USTAVOK ),
//ISM_2_GRUPA_USTAVOK_CMD_03 = (( IDX_U32_ISM_2_GRUPA_USTAVOK  ==  3)<< MSK_U32_ISM_2_GRUPA_USTAVOK ),
//ISM_2_GRUPA_USTAVOK_CMD_04 = (( IDX_U32_ISM_2_GRUPA_USTAVOK  ==  4)<< MSK_U32_ISM_2_GRUPA_USTAVOK ),
//ISM_2_GRUPA_USTAVOK_CMD_05 = (( IDX_U32_ISM_2_GRUPA_USTAVOK  ==  5)<< MSK_U32_ISM_2_GRUPA_USTAVOK ),
//ISM_2_GRUPA_USTAVOK_CMD_06 = (( IDX_U32_ISM_2_GRUPA_USTAVOK  ==  6)<< MSK_U32_ISM_2_GRUPA_USTAVOK ),
//ISM_2_GRUPA_USTAVOK_CMD_07 = (( IDX_U32_ISM_2_GRUPA_USTAVOK  ==  7)<< MSK_U32_ISM_2_GRUPA_USTAVOK ),
//ISM_2_GRUPA_USTAVOK_CMD_08 = (( IDX_U32_ISM_2_GRUPA_USTAVOK  ==  8)<< MSK_U32_ISM_2_GRUPA_USTAVOK ),
//ISM_2_GRUPA_USTAVOK_CMD_09 = (( IDX_U32_ISM_2_GRUPA_USTAVOK  ==  9)<< MSK_U32_ISM_2_GRUPA_USTAVOK ),
//ISM_2_GRUPA_USTAVOK_CMD_10 = (( IDX_U32_ISM_2_GRUPA_USTAVOK  == 10)<< MSK_U32_ISM_2_GRUPA_USTAVOK ),
//ISM_2_GRUPA_USTAVOK_CMD_11 = (( IDX_U32_ISM_2_GRUPA_USTAVOK  == 11)<< MSK_U32_ISM_2_GRUPA_USTAVOK ),
//ISM_2_GRUPA_USTAVOK_CMD_12 = (( IDX_U32_ISM_2_GRUPA_USTAVOK  == 12)<< MSK_U32_ISM_2_GRUPA_USTAVOK ),
                    
                    
//ISM_3_GRUPA_USTAVOK_CMD_00 = (( IDX_U32_ISM_3_GRUPA_USTAVOK ==  0)<< MSK_U32_ISM_3_GRUPA_USTAVOK ),
//ISM_3_GRUPA_USTAVOK_CMD_01 = (( IDX_U32_ISM_3_GRUPA_USTAVOK ==  1)<< MSK_U32_ISM_3_GRUPA_USTAVOK ),
//ISM_3_GRUPA_USTAVOK_CMD_02 = (( IDX_U32_ISM_3_GRUPA_USTAVOK ==  2)<< MSK_U32_ISM_3_GRUPA_USTAVOK ),
//ISM_3_GRUPA_USTAVOK_CMD_03 = (( IDX_U32_ISM_3_GRUPA_USTAVOK ==  3)<< MSK_U32_ISM_3_GRUPA_USTAVOK ),
//ISM_3_GRUPA_USTAVOK_CMD_04 = (( IDX_U32_ISM_3_GRUPA_USTAVOK ==  4)<< MSK_U32_ISM_3_GRUPA_USTAVOK ),
//ISM_3_GRUPA_USTAVOK_CMD_05 = (( IDX_U32_ISM_3_GRUPA_USTAVOK ==  5)<< MSK_U32_ISM_3_GRUPA_USTAVOK ),
//ISM_3_GRUPA_USTAVOK_CMD_06 = (( IDX_U32_ISM_3_GRUPA_USTAVOK ==  6)<< MSK_U32_ISM_3_GRUPA_USTAVOK ),
//ISM_3_GRUPA_USTAVOK_CMD_07 = (( IDX_U32_ISM_3_GRUPA_USTAVOK ==  7)<< MSK_U32_ISM_3_GRUPA_USTAVOK ),
//ISM_3_GRUPA_USTAVOK_CMD_08 = (( IDX_U32_ISM_3_GRUPA_USTAVOK ==  8)<< MSK_U32_ISM_3_GRUPA_USTAVOK ),
//ISM_3_GRUPA_USTAVOK_CMD_09 = (( IDX_U32_ISM_3_GRUPA_USTAVOK ==  9)<< MSK_U32_ISM_3_GRUPA_USTAVOK ),
//ISM_3_GRUPA_USTAVOK_CMD_10 = (( IDX_U32_ISM_3_GRUPA_USTAVOK == 10)<< MSK_U32_ISM_3_GRUPA_USTAVOK ),
//ISM_3_GRUPA_USTAVOK_CMD_11 = (( IDX_U32_ISM_3_GRUPA_USTAVOK == 11)<< MSK_U32_ISM_3_GRUPA_USTAVOK ),
//ISM_3_GRUPA_USTAVOK_CMD_12 = (( IDX_U32_ISM_3_GRUPA_USTAVOK == 12)<< MSK_U32_ISM_3_GRUPA_USTAVOK ),
                    
                    
//ISM_4_GRUPA_USTAVOK_CMD_00 = (( IDX_U32_ISM_4_GRUPA_USTAVOK ==  0)<< MSK_U32_ISM_4_GRUPA_USTAVOK ),
//ISM_4_GRUPA_USTAVOK_CMD_01 = (( IDX_U32_ISM_4_GRUPA_USTAVOK ==  1)<< MSK_U32_ISM_4_GRUPA_USTAVOK ),
//ISM_4_GRUPA_USTAVOK_CMD_02 = (( IDX_U32_ISM_4_GRUPA_USTAVOK ==  2)<< MSK_U32_ISM_4_GRUPA_USTAVOK ),
//ISM_4_GRUPA_USTAVOK_CMD_03 = (( IDX_U32_ISM_4_GRUPA_USTAVOK ==  3)<< MSK_U32_ISM_4_GRUPA_USTAVOK ),
//ISM_4_GRUPA_USTAVOK_CMD_04 = (( IDX_U32_ISM_4_GRUPA_USTAVOK ==  4)<< MSK_U32_ISM_4_GRUPA_USTAVOK ),
//ISM_4_GRUPA_USTAVOK_CMD_05 = (( IDX_U32_ISM_4_GRUPA_USTAVOK ==  5)<< MSK_U32_ISM_4_GRUPA_USTAVOK ),
//ISM_4_GRUPA_USTAVOK_CMD_06 = (( IDX_U32_ISM_4_GRUPA_USTAVOK ==  6)<< MSK_U32_ISM_4_GRUPA_USTAVOK ),
//ISM_4_GRUPA_USTAVOK_CMD_07 = (( IDX_U32_ISM_4_GRUPA_USTAVOK ==  7)<< MSK_U32_ISM_4_GRUPA_USTAVOK ),
//ISM_4_GRUPA_USTAVOK_CMD_08 = (( IDX_U32_ISM_4_GRUPA_USTAVOK ==  8)<< MSK_U32_ISM_4_GRUPA_USTAVOK ),
//ISM_4_GRUPA_USTAVOK_CMD_09 = (( IDX_U32_ISM_4_GRUPA_USTAVOK ==  9)<< MSK_U32_ISM_4_GRUPA_USTAVOK ),
//ISM_4_GRUPA_USTAVOK_CMD_10 = (( IDX_U32_ISM_4_GRUPA_USTAVOK == 10)<< MSK_U32_ISM_4_GRUPA_USTAVOK ),
//ISM_4_GRUPA_USTAVOK_CMD_11 = (( IDX_U32_ISM_4_GRUPA_USTAVOK == 11)<< MSK_U32_ISM_4_GRUPA_USTAVOK ),
//ISM_4_GRUPA_USTAVOK_CMD_12 = (( IDX_U32_ISM_4_GRUPA_USTAVOK == 12)<< MSK_U32_ISM_4_GRUPA_USTAVOK ),
                    
                    
ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV_CMD_00 = (( IDX_U32_ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV ==  0)<< MSK_U32_ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV ),
ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV_CMD_01 = (( IDX_U32_ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV ==  1)<< MSK_U32_ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV ),
ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV_CMD_02 = (( IDX_U32_ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV ==  2)<< MSK_U32_ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV ),
ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV_CMD_03 = (( IDX_U32_ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV ==  3)<< MSK_U32_ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV ),
ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV_CMD_04 = (( IDX_U32_ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV ==  4)<< MSK_U32_ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV ),
ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV_CMD_05 = (( IDX_U32_ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV ==  5)<< MSK_U32_ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV ),
ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV_CMD_06 = (( IDX_U32_ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV ==  6)<< MSK_U32_ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV ),
ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV_CMD_07 = (( IDX_U32_ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV ==  7)<< MSK_U32_ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV ),
ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV_CMD_08 = (( IDX_U32_ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV ==  8)<< MSK_U32_ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV ),
ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV_CMD_09 = (( IDX_U32_ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV ==  9)<< MSK_U32_ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV ),
ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV_CMD_10 = (( IDX_U32_ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV == 10)<< MSK_U32_ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV ),
ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV_CMD_11 = (( IDX_U32_ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV == 11)<< MSK_U32_ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV ),
ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV_CMD_12 = (( IDX_U32_ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV == 12)<< MSK_U32_ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV ),

ISM_ZVN_NESPR_DZO_CMD_00 = ((IDX_U32_ISM_ZVN_NESPR_DZO ==  0)<< MSK_U32_ISM_ZVN_NESPR_DZO),
ISM_ZVN_NESPR_DZO_CMD_01 = ((IDX_U32_ISM_ZVN_NESPR_DZO ==  1)<< MSK_U32_ISM_ZVN_NESPR_DZO),
ISM_ZVN_NESPR_DZO_CMD_02 = ((IDX_U32_ISM_ZVN_NESPR_DZO ==  2)<< MSK_U32_ISM_ZVN_NESPR_DZO),
ISM_ZVN_NESPR_DZO_CMD_03 = ((IDX_U32_ISM_ZVN_NESPR_DZO ==  3)<< MSK_U32_ISM_ZVN_NESPR_DZO),
ISM_ZVN_NESPR_DZO_CMD_04 = ((IDX_U32_ISM_ZVN_NESPR_DZO ==  4)<< MSK_U32_ISM_ZVN_NESPR_DZO),
ISM_ZVN_NESPR_DZO_CMD_05 = ((IDX_U32_ISM_ZVN_NESPR_DZO ==  5)<< MSK_U32_ISM_ZVN_NESPR_DZO),
ISM_ZVN_NESPR_DZO_CMD_06 = ((IDX_U32_ISM_ZVN_NESPR_DZO ==  6)<< MSK_U32_ISM_ZVN_NESPR_DZO),
ISM_ZVN_NESPR_DZO_CMD_07 = ((IDX_U32_ISM_ZVN_NESPR_DZO ==  7)<< MSK_U32_ISM_ZVN_NESPR_DZO),
ISM_ZVN_NESPR_DZO_CMD_08 = ((IDX_U32_ISM_ZVN_NESPR_DZO ==  8)<< MSK_U32_ISM_ZVN_NESPR_DZO),
ISM_ZVN_NESPR_DZO_CMD_09 = ((IDX_U32_ISM_ZVN_NESPR_DZO ==  9)<< MSK_U32_ISM_ZVN_NESPR_DZO),
ISM_ZVN_NESPR_DZO_CMD_10 = ((IDX_U32_ISM_ZVN_NESPR_DZO == 10)<< MSK_U32_ISM_ZVN_NESPR_DZO),
ISM_ZVN_NESPR_DZO_CMD_11 = ((IDX_U32_ISM_ZVN_NESPR_DZO == 11)<< MSK_U32_ISM_ZVN_NESPR_DZO),
ISM_ZVN_NESPR_DZO_CMD_12 = ((IDX_U32_ISM_ZVN_NESPR_DZO == 12)<< MSK_U32_ISM_ZVN_NESPR_DZO),
                    
                    
ISM_ZBR_BLOCK_DZO1_I_O_3G_CMD_00 = ((IDX_U32_ISM_ZBR_BLOCK_DZO1_I_O_3G ==  0)<< MSK_U32_ISM_ZBR_BLOCK_DZO1_I_O_3G),
ISM_ZBR_BLOCK_DZO1_I_O_3G_CMD_01 = ((IDX_U32_ISM_ZBR_BLOCK_DZO1_I_O_3G ==  1)<< MSK_U32_ISM_ZBR_BLOCK_DZO1_I_O_3G),
ISM_ZBR_BLOCK_DZO1_I_O_3G_CMD_02 = ((IDX_U32_ISM_ZBR_BLOCK_DZO1_I_O_3G ==  2)<< MSK_U32_ISM_ZBR_BLOCK_DZO1_I_O_3G),
ISM_ZBR_BLOCK_DZO1_I_O_3G_CMD_03 = ((IDX_U32_ISM_ZBR_BLOCK_DZO1_I_O_3G ==  3)<< MSK_U32_ISM_ZBR_BLOCK_DZO1_I_O_3G),
ISM_ZBR_BLOCK_DZO1_I_O_3G_CMD_04 = ((IDX_U32_ISM_ZBR_BLOCK_DZO1_I_O_3G ==  4)<< MSK_U32_ISM_ZBR_BLOCK_DZO1_I_O_3G),
ISM_ZBR_BLOCK_DZO1_I_O_3G_CMD_05 = ((IDX_U32_ISM_ZBR_BLOCK_DZO1_I_O_3G ==  5)<< MSK_U32_ISM_ZBR_BLOCK_DZO1_I_O_3G),
ISM_ZBR_BLOCK_DZO1_I_O_3G_CMD_06 = ((IDX_U32_ISM_ZBR_BLOCK_DZO1_I_O_3G ==  6)<< MSK_U32_ISM_ZBR_BLOCK_DZO1_I_O_3G),
ISM_ZBR_BLOCK_DZO1_I_O_3G_CMD_07 = ((IDX_U32_ISM_ZBR_BLOCK_DZO1_I_O_3G ==  7)<< MSK_U32_ISM_ZBR_BLOCK_DZO1_I_O_3G),
ISM_ZBR_BLOCK_DZO1_I_O_3G_CMD_08 = ((IDX_U32_ISM_ZBR_BLOCK_DZO1_I_O_3G ==  8)<< MSK_U32_ISM_ZBR_BLOCK_DZO1_I_O_3G),
ISM_ZBR_BLOCK_DZO1_I_O_3G_CMD_09 = ((IDX_U32_ISM_ZBR_BLOCK_DZO1_I_O_3G ==  9)<< MSK_U32_ISM_ZBR_BLOCK_DZO1_I_O_3G),
ISM_ZBR_BLOCK_DZO1_I_O_3G_CMD_10 = ((IDX_U32_ISM_ZBR_BLOCK_DZO1_I_O_3G == 10)<< MSK_U32_ISM_ZBR_BLOCK_DZO1_I_O_3G),
ISM_ZBR_BLOCK_DZO1_I_O_3G_CMD_11 = ((IDX_U32_ISM_ZBR_BLOCK_DZO1_I_O_3G == 11)<< MSK_U32_ISM_ZBR_BLOCK_DZO1_I_O_3G),
ISM_ZBR_BLOCK_DZO1_I_O_3G_CMD_12 = ((IDX_U32_ISM_ZBR_BLOCK_DZO1_I_O_3G == 12)<< MSK_U32_ISM_ZBR_BLOCK_DZO1_I_O_3G),
                    
                    
ISM_ZBR_BLOCK_DZO1_I_O_CMD_00 = ((IDX_U32_ISM_ZBR_BLOCK_DZO1_I_O ==  0)<< MSK_U32_ISM_ZBR_BLOCK_DZO1_I_O),
ISM_ZBR_BLOCK_DZO1_I_O_CMD_01 = ((IDX_U32_ISM_ZBR_BLOCK_DZO1_I_O ==  1)<< MSK_U32_ISM_ZBR_BLOCK_DZO1_I_O),
ISM_ZBR_BLOCK_DZO1_I_O_CMD_02 = ((IDX_U32_ISM_ZBR_BLOCK_DZO1_I_O ==  2)<< MSK_U32_ISM_ZBR_BLOCK_DZO1_I_O),
ISM_ZBR_BLOCK_DZO1_I_O_CMD_03 = ((IDX_U32_ISM_ZBR_BLOCK_DZO1_I_O ==  3)<< MSK_U32_ISM_ZBR_BLOCK_DZO1_I_O),
ISM_ZBR_BLOCK_DZO1_I_O_CMD_04 = ((IDX_U32_ISM_ZBR_BLOCK_DZO1_I_O ==  4)<< MSK_U32_ISM_ZBR_BLOCK_DZO1_I_O),
ISM_ZBR_BLOCK_DZO1_I_O_CMD_05 = ((IDX_U32_ISM_ZBR_BLOCK_DZO1_I_O ==  5)<< MSK_U32_ISM_ZBR_BLOCK_DZO1_I_O),
ISM_ZBR_BLOCK_DZO1_I_O_CMD_06 = ((IDX_U32_ISM_ZBR_BLOCK_DZO1_I_O ==  6)<< MSK_U32_ISM_ZBR_BLOCK_DZO1_I_O),
ISM_ZBR_BLOCK_DZO1_I_O_CMD_07 = ((IDX_U32_ISM_ZBR_BLOCK_DZO1_I_O ==  7)<< MSK_U32_ISM_ZBR_BLOCK_DZO1_I_O),
ISM_ZBR_BLOCK_DZO1_I_O_CMD_08 = ((IDX_U32_ISM_ZBR_BLOCK_DZO1_I_O ==  8)<< MSK_U32_ISM_ZBR_BLOCK_DZO1_I_O),
ISM_ZBR_BLOCK_DZO1_I_O_CMD_09 = ((IDX_U32_ISM_ZBR_BLOCK_DZO1_I_O ==  9)<< MSK_U32_ISM_ZBR_BLOCK_DZO1_I_O),
ISM_ZBR_BLOCK_DZO1_I_O_CMD_10 = ((IDX_U32_ISM_ZBR_BLOCK_DZO1_I_O == 10)<< MSK_U32_ISM_ZBR_BLOCK_DZO1_I_O),
ISM_ZBR_BLOCK_DZO1_I_O_CMD_11 = ((IDX_U32_ISM_ZBR_BLOCK_DZO1_I_O == 11)<< MSK_U32_ISM_ZBR_BLOCK_DZO1_I_O),
ISM_ZBR_BLOCK_DZO1_I_O_CMD_12 = ((IDX_U32_ISM_ZBR_BLOCK_DZO1_I_O == 12)<< MSK_U32_ISM_ZBR_BLOCK_DZO1_I_O),
                    
                    
ISM_BLOCK_DZO1_CMD_00 = ((IDX_U32_ISM_BLOCK_DZO1 ==  0)<< MSK_U32_ISM_BLOCK_DZO1),
ISM_BLOCK_DZO1_CMD_01 = ((IDX_U32_ISM_BLOCK_DZO1 ==  1)<< MSK_U32_ISM_BLOCK_DZO1),
ISM_BLOCK_DZO1_CMD_02 = ((IDX_U32_ISM_BLOCK_DZO1 ==  2)<< MSK_U32_ISM_BLOCK_DZO1),
ISM_BLOCK_DZO1_CMD_03 = ((IDX_U32_ISM_BLOCK_DZO1 ==  3)<< MSK_U32_ISM_BLOCK_DZO1),
ISM_BLOCK_DZO1_CMD_04 = ((IDX_U32_ISM_BLOCK_DZO1 ==  4)<< MSK_U32_ISM_BLOCK_DZO1),
ISM_BLOCK_DZO1_CMD_05 = ((IDX_U32_ISM_BLOCK_DZO1 ==  5)<< MSK_U32_ISM_BLOCK_DZO1),
ISM_BLOCK_DZO1_CMD_06 = ((IDX_U32_ISM_BLOCK_DZO1 ==  6)<< MSK_U32_ISM_BLOCK_DZO1),
ISM_BLOCK_DZO1_CMD_07 = ((IDX_U32_ISM_BLOCK_DZO1 ==  7)<< MSK_U32_ISM_BLOCK_DZO1),
ISM_BLOCK_DZO1_CMD_08 = ((IDX_U32_ISM_BLOCK_DZO1 ==  8)<< MSK_U32_ISM_BLOCK_DZO1),
ISM_BLOCK_DZO1_CMD_09 = ((IDX_U32_ISM_BLOCK_DZO1 ==  9)<< MSK_U32_ISM_BLOCK_DZO1),
ISM_BLOCK_DZO1_CMD_10 = ((IDX_U32_ISM_BLOCK_DZO1 == 10)<< MSK_U32_ISM_BLOCK_DZO1),
ISM_BLOCK_DZO1_CMD_11 = ((IDX_U32_ISM_BLOCK_DZO1 == 11)<< MSK_U32_ISM_BLOCK_DZO1),
ISM_BLOCK_DZO1_CMD_12 = ((IDX_U32_ISM_BLOCK_DZO1 == 12)<< MSK_U32_ISM_BLOCK_DZO1),

ISM_BLOCK_PR_DZO2_CMD_00 = ((IDX_U32_ISM_BLOCK_PR_DZO2 ==  0)<< MSK_U32_ISM_BLOCK_PR_DZO2),
ISM_BLOCK_PR_DZO2_CMD_01 = ((IDX_U32_ISM_BLOCK_PR_DZO2 ==  1)<< MSK_U32_ISM_BLOCK_PR_DZO2),
ISM_BLOCK_PR_DZO2_CMD_02 = ((IDX_U32_ISM_BLOCK_PR_DZO2 ==  2)<< MSK_U32_ISM_BLOCK_PR_DZO2),
ISM_BLOCK_PR_DZO2_CMD_03 = ((IDX_U32_ISM_BLOCK_PR_DZO2 ==  3)<< MSK_U32_ISM_BLOCK_PR_DZO2),
ISM_BLOCK_PR_DZO2_CMD_04 = ((IDX_U32_ISM_BLOCK_PR_DZO2 ==  4)<< MSK_U32_ISM_BLOCK_PR_DZO2),
ISM_BLOCK_PR_DZO2_CMD_05 = ((IDX_U32_ISM_BLOCK_PR_DZO2 ==  5)<< MSK_U32_ISM_BLOCK_PR_DZO2),
ISM_BLOCK_PR_DZO2_CMD_06 = ((IDX_U32_ISM_BLOCK_PR_DZO2 ==  6)<< MSK_U32_ISM_BLOCK_PR_DZO2),
ISM_BLOCK_PR_DZO2_CMD_07 = ((IDX_U32_ISM_BLOCK_PR_DZO2 ==  7)<< MSK_U32_ISM_BLOCK_PR_DZO2),
ISM_BLOCK_PR_DZO2_CMD_08 = ((IDX_U32_ISM_BLOCK_PR_DZO2 ==  8)<< MSK_U32_ISM_BLOCK_PR_DZO2),
ISM_BLOCK_PR_DZO2_CMD_09 = ((IDX_U32_ISM_BLOCK_PR_DZO2 ==  9)<< MSK_U32_ISM_BLOCK_PR_DZO2),
ISM_BLOCK_PR_DZO2_CMD_10 = ((IDX_U32_ISM_BLOCK_PR_DZO2 == 10)<< MSK_U32_ISM_BLOCK_PR_DZO2),
ISM_BLOCK_PR_DZO2_CMD_11 = ((IDX_U32_ISM_BLOCK_PR_DZO2 == 11)<< MSK_U32_ISM_BLOCK_PR_DZO2),
ISM_BLOCK_PR_DZO2_CMD_12 = ((IDX_U32_ISM_BLOCK_PR_DZO2 == 12)<< MSK_U32_ISM_BLOCK_PR_DZO2),
                    
                    
ISM_OP_PR_DZO2_CMD_00 = ((IDX_U32_ISM_OP_PR_DZO2 ==  0)<< MSK_U32_ISM_OP_PR_DZO2),
ISM_OP_PR_DZO2_CMD_01 = ((IDX_U32_ISM_OP_PR_DZO2 ==  1)<< MSK_U32_ISM_OP_PR_DZO2),
ISM_OP_PR_DZO2_CMD_02 = ((IDX_U32_ISM_OP_PR_DZO2 ==  2)<< MSK_U32_ISM_OP_PR_DZO2),
ISM_OP_PR_DZO2_CMD_03 = ((IDX_U32_ISM_OP_PR_DZO2 ==  3)<< MSK_U32_ISM_OP_PR_DZO2),
ISM_OP_PR_DZO2_CMD_04 = ((IDX_U32_ISM_OP_PR_DZO2 ==  4)<< MSK_U32_ISM_OP_PR_DZO2),
ISM_OP_PR_DZO2_CMD_05 = ((IDX_U32_ISM_OP_PR_DZO2 ==  5)<< MSK_U32_ISM_OP_PR_DZO2),
ISM_OP_PR_DZO2_CMD_06 = ((IDX_U32_ISM_OP_PR_DZO2 ==  6)<< MSK_U32_ISM_OP_PR_DZO2),
ISM_OP_PR_DZO2_CMD_07 = ((IDX_U32_ISM_OP_PR_DZO2 ==  7)<< MSK_U32_ISM_OP_PR_DZO2),
ISM_OP_PR_DZO2_CMD_08 = ((IDX_U32_ISM_OP_PR_DZO2 ==  8)<< MSK_U32_ISM_OP_PR_DZO2),
ISM_OP_PR_DZO2_CMD_09 = ((IDX_U32_ISM_OP_PR_DZO2 ==  9)<< MSK_U32_ISM_OP_PR_DZO2),
ISM_OP_PR_DZO2_CMD_10 = ((IDX_U32_ISM_OP_PR_DZO2 == 10)<< MSK_U32_ISM_OP_PR_DZO2),
ISM_OP_PR_DZO2_CMD_11 = ((IDX_U32_ISM_OP_PR_DZO2 == 11)<< MSK_U32_ISM_OP_PR_DZO2),
ISM_OP_PR_DZO2_CMD_12 = ((IDX_U32_ISM_OP_PR_DZO2 == 12)<< MSK_U32_ISM_OP_PR_DZO2),
                    
                    
ISM_ZBR_BLOCK_DZO2_I_O_3G_CMD_00 = ((IDX_U32_ISM_ZBR_BLOCK_DZO2_I_O_3G ==  0)<< MSK_U32_ISM_ZBR_BLOCK_DZO2_I_O_3G),
ISM_ZBR_BLOCK_DZO2_I_O_3G_CMD_01 = ((IDX_U32_ISM_ZBR_BLOCK_DZO2_I_O_3G ==  1)<< MSK_U32_ISM_ZBR_BLOCK_DZO2_I_O_3G),
ISM_ZBR_BLOCK_DZO2_I_O_3G_CMD_02 = ((IDX_U32_ISM_ZBR_BLOCK_DZO2_I_O_3G ==  2)<< MSK_U32_ISM_ZBR_BLOCK_DZO2_I_O_3G),
ISM_ZBR_BLOCK_DZO2_I_O_3G_CMD_03 = ((IDX_U32_ISM_ZBR_BLOCK_DZO2_I_O_3G ==  3)<< MSK_U32_ISM_ZBR_BLOCK_DZO2_I_O_3G),
ISM_ZBR_BLOCK_DZO2_I_O_3G_CMD_04 = ((IDX_U32_ISM_ZBR_BLOCK_DZO2_I_O_3G ==  4)<< MSK_U32_ISM_ZBR_BLOCK_DZO2_I_O_3G),
ISM_ZBR_BLOCK_DZO2_I_O_3G_CMD_05 = ((IDX_U32_ISM_ZBR_BLOCK_DZO2_I_O_3G ==  5)<< MSK_U32_ISM_ZBR_BLOCK_DZO2_I_O_3G),
ISM_ZBR_BLOCK_DZO2_I_O_3G_CMD_06 = ((IDX_U32_ISM_ZBR_BLOCK_DZO2_I_O_3G ==  6)<< MSK_U32_ISM_ZBR_BLOCK_DZO2_I_O_3G),
ISM_ZBR_BLOCK_DZO2_I_O_3G_CMD_07 = ((IDX_U32_ISM_ZBR_BLOCK_DZO2_I_O_3G ==  7)<< MSK_U32_ISM_ZBR_BLOCK_DZO2_I_O_3G),
ISM_ZBR_BLOCK_DZO2_I_O_3G_CMD_08 = ((IDX_U32_ISM_ZBR_BLOCK_DZO2_I_O_3G ==  8)<< MSK_U32_ISM_ZBR_BLOCK_DZO2_I_O_3G),
ISM_ZBR_BLOCK_DZO2_I_O_3G_CMD_09 = ((IDX_U32_ISM_ZBR_BLOCK_DZO2_I_O_3G ==  9)<< MSK_U32_ISM_ZBR_BLOCK_DZO2_I_O_3G),
ISM_ZBR_BLOCK_DZO2_I_O_3G_CMD_10 = ((IDX_U32_ISM_ZBR_BLOCK_DZO2_I_O_3G == 10)<< MSK_U32_ISM_ZBR_BLOCK_DZO2_I_O_3G),
ISM_ZBR_BLOCK_DZO2_I_O_3G_CMD_11 = ((IDX_U32_ISM_ZBR_BLOCK_DZO2_I_O_3G == 11)<< MSK_U32_ISM_ZBR_BLOCK_DZO2_I_O_3G),
ISM_ZBR_BLOCK_DZO2_I_O_3G_CMD_12 = ((IDX_U32_ISM_ZBR_BLOCK_DZO2_I_O_3G == 12)<< MSK_U32_ISM_ZBR_BLOCK_DZO2_I_O_3G),
                    
                    
ISM_BLOCK_DZO2_CMD_00 = ((IDX_U32_ISM_BLOCK_DZO2 ==  0)<< MSK_U32_ISM_BLOCK_DZO2),
ISM_BLOCK_DZO2_CMD_01 = ((IDX_U32_ISM_BLOCK_DZO2 ==  1)<< MSK_U32_ISM_BLOCK_DZO2),
ISM_BLOCK_DZO2_CMD_02 = ((IDX_U32_ISM_BLOCK_DZO2 ==  2)<< MSK_U32_ISM_BLOCK_DZO2),
ISM_BLOCK_DZO2_CMD_03 = ((IDX_U32_ISM_BLOCK_DZO2 ==  3)<< MSK_U32_ISM_BLOCK_DZO2),
ISM_BLOCK_DZO2_CMD_04 = ((IDX_U32_ISM_BLOCK_DZO2 ==  4)<< MSK_U32_ISM_BLOCK_DZO2),
ISM_BLOCK_DZO2_CMD_05 = ((IDX_U32_ISM_BLOCK_DZO2 ==  5)<< MSK_U32_ISM_BLOCK_DZO2),
ISM_BLOCK_DZO2_CMD_06 = ((IDX_U32_ISM_BLOCK_DZO2 ==  6)<< MSK_U32_ISM_BLOCK_DZO2),
ISM_BLOCK_DZO2_CMD_07 = ((IDX_U32_ISM_BLOCK_DZO2 ==  7)<< MSK_U32_ISM_BLOCK_DZO2),
ISM_BLOCK_DZO2_CMD_08 = ((IDX_U32_ISM_BLOCK_DZO2 ==  8)<< MSK_U32_ISM_BLOCK_DZO2),
ISM_BLOCK_DZO2_CMD_09 = ((IDX_U32_ISM_BLOCK_DZO2 ==  9)<< MSK_U32_ISM_BLOCK_DZO2),
ISM_BLOCK_DZO2_CMD_10 = ((IDX_U32_ISM_BLOCK_DZO2 == 10)<< MSK_U32_ISM_BLOCK_DZO2),
ISM_BLOCK_DZO2_CMD_11 = ((IDX_U32_ISM_BLOCK_DZO2 == 11)<< MSK_U32_ISM_BLOCK_DZO2),
ISM_BLOCK_DZO2_CMD_12 = ((IDX_U32_ISM_BLOCK_DZO2 == 12)<< MSK_U32_ISM_BLOCK_DZO2),

ISM_BLOCK_PR_DZO3_CMD_00 = ((IDX_U32_ISM_BLOCK_PR_DZO3 ==  0)<< MSK_U32_ISM_BLOCK_PR_DZO3),
ISM_BLOCK_PR_DZO3_CMD_01 = ((IDX_U32_ISM_BLOCK_PR_DZO3 ==  1)<< MSK_U32_ISM_BLOCK_PR_DZO3),
ISM_BLOCK_PR_DZO3_CMD_02 = ((IDX_U32_ISM_BLOCK_PR_DZO3 ==  2)<< MSK_U32_ISM_BLOCK_PR_DZO3),
ISM_BLOCK_PR_DZO3_CMD_03 = ((IDX_U32_ISM_BLOCK_PR_DZO3 ==  3)<< MSK_U32_ISM_BLOCK_PR_DZO3),
ISM_BLOCK_PR_DZO3_CMD_04 = ((IDX_U32_ISM_BLOCK_PR_DZO3 ==  4)<< MSK_U32_ISM_BLOCK_PR_DZO3),
ISM_BLOCK_PR_DZO3_CMD_05 = ((IDX_U32_ISM_BLOCK_PR_DZO3 ==  5)<< MSK_U32_ISM_BLOCK_PR_DZO3),
ISM_BLOCK_PR_DZO3_CMD_06 = ((IDX_U32_ISM_BLOCK_PR_DZO3 ==  6)<< MSK_U32_ISM_BLOCK_PR_DZO3),
ISM_BLOCK_PR_DZO3_CMD_07 = ((IDX_U32_ISM_BLOCK_PR_DZO3 ==  7)<< MSK_U32_ISM_BLOCK_PR_DZO3),
ISM_BLOCK_PR_DZO3_CMD_08 = ((IDX_U32_ISM_BLOCK_PR_DZO3 ==  8)<< MSK_U32_ISM_BLOCK_PR_DZO3),
ISM_BLOCK_PR_DZO3_CMD_09 = ((IDX_U32_ISM_BLOCK_PR_DZO3 ==  9)<< MSK_U32_ISM_BLOCK_PR_DZO3),
ISM_BLOCK_PR_DZO3_CMD_10 = ((IDX_U32_ISM_BLOCK_PR_DZO3 == 10)<< MSK_U32_ISM_BLOCK_PR_DZO3),
ISM_BLOCK_PR_DZO3_CMD_11 = ((IDX_U32_ISM_BLOCK_PR_DZO3 == 11)<< MSK_U32_ISM_BLOCK_PR_DZO3),
ISM_BLOCK_PR_DZO3_CMD_12 = ((IDX_U32_ISM_BLOCK_PR_DZO3 == 12)<< MSK_U32_ISM_BLOCK_PR_DZO3),
                    
                    
ISM_OP_PR_DZO3_CMD_00 = ((IDX_U32_ISM_OP_PR_DZO3 ==  0)<< MSK_U32_ISM_OP_PR_DZO3),
ISM_OP_PR_DZO3_CMD_01 = ((IDX_U32_ISM_OP_PR_DZO3 ==  1)<< MSK_U32_ISM_OP_PR_DZO3),
ISM_OP_PR_DZO3_CMD_02 = ((IDX_U32_ISM_OP_PR_DZO3 ==  2)<< MSK_U32_ISM_OP_PR_DZO3),
ISM_OP_PR_DZO3_CMD_03 = ((IDX_U32_ISM_OP_PR_DZO3 ==  3)<< MSK_U32_ISM_OP_PR_DZO3),
ISM_OP_PR_DZO3_CMD_04 = ((IDX_U32_ISM_OP_PR_DZO3 ==  4)<< MSK_U32_ISM_OP_PR_DZO3),
ISM_OP_PR_DZO3_CMD_05 = ((IDX_U32_ISM_OP_PR_DZO3 ==  5)<< MSK_U32_ISM_OP_PR_DZO3),
ISM_OP_PR_DZO3_CMD_06 = ((IDX_U32_ISM_OP_PR_DZO3 ==  6)<< MSK_U32_ISM_OP_PR_DZO3),
ISM_OP_PR_DZO3_CMD_07 = ((IDX_U32_ISM_OP_PR_DZO3 ==  7)<< MSK_U32_ISM_OP_PR_DZO3),
ISM_OP_PR_DZO3_CMD_08 = ((IDX_U32_ISM_OP_PR_DZO3 ==  8)<< MSK_U32_ISM_OP_PR_DZO3),
ISM_OP_PR_DZO3_CMD_09 = ((IDX_U32_ISM_OP_PR_DZO3 ==  9)<< MSK_U32_ISM_OP_PR_DZO3),
ISM_OP_PR_DZO3_CMD_10 = ((IDX_U32_ISM_OP_PR_DZO3 == 10)<< MSK_U32_ISM_OP_PR_DZO3),
ISM_OP_PR_DZO3_CMD_11 = ((IDX_U32_ISM_OP_PR_DZO3 == 11)<< MSK_U32_ISM_OP_PR_DZO3),
ISM_OP_PR_DZO3_CMD_12 = ((IDX_U32_ISM_OP_PR_DZO3 == 12)<< MSK_U32_ISM_OP_PR_DZO3),
                    
                    
ISM_ZBR_BLOCK_DZO3_I_O_3G_CMD_00 = ((IDX_U32_ISM_ZBR_BLOCK_DZO3_I_O_3G ==  0)<< MSK_U32_ISM_ZBR_BLOCK_DZO3_I_O_3G),
ISM_ZBR_BLOCK_DZO3_I_O_3G_CMD_01 = ((IDX_U32_ISM_ZBR_BLOCK_DZO3_I_O_3G ==  1)<< MSK_U32_ISM_ZBR_BLOCK_DZO3_I_O_3G),
ISM_ZBR_BLOCK_DZO3_I_O_3G_CMD_02 = ((IDX_U32_ISM_ZBR_BLOCK_DZO3_I_O_3G ==  2)<< MSK_U32_ISM_ZBR_BLOCK_DZO3_I_O_3G),
ISM_ZBR_BLOCK_DZO3_I_O_3G_CMD_03 = ((IDX_U32_ISM_ZBR_BLOCK_DZO3_I_O_3G ==  3)<< MSK_U32_ISM_ZBR_BLOCK_DZO3_I_O_3G),
ISM_ZBR_BLOCK_DZO3_I_O_3G_CMD_04 = ((IDX_U32_ISM_ZBR_BLOCK_DZO3_I_O_3G ==  4)<< MSK_U32_ISM_ZBR_BLOCK_DZO3_I_O_3G),
ISM_ZBR_BLOCK_DZO3_I_O_3G_CMD_05 = ((IDX_U32_ISM_ZBR_BLOCK_DZO3_I_O_3G ==  5)<< MSK_U32_ISM_ZBR_BLOCK_DZO3_I_O_3G),
ISM_ZBR_BLOCK_DZO3_I_O_3G_CMD_06 = ((IDX_U32_ISM_ZBR_BLOCK_DZO3_I_O_3G ==  6)<< MSK_U32_ISM_ZBR_BLOCK_DZO3_I_O_3G),
ISM_ZBR_BLOCK_DZO3_I_O_3G_CMD_07 = ((IDX_U32_ISM_ZBR_BLOCK_DZO3_I_O_3G ==  7)<< MSK_U32_ISM_ZBR_BLOCK_DZO3_I_O_3G),
ISM_ZBR_BLOCK_DZO3_I_O_3G_CMD_08 = ((IDX_U32_ISM_ZBR_BLOCK_DZO3_I_O_3G ==  8)<< MSK_U32_ISM_ZBR_BLOCK_DZO3_I_O_3G),
ISM_ZBR_BLOCK_DZO3_I_O_3G_CMD_09 = ((IDX_U32_ISM_ZBR_BLOCK_DZO3_I_O_3G ==  9)<< MSK_U32_ISM_ZBR_BLOCK_DZO3_I_O_3G),
ISM_ZBR_BLOCK_DZO3_I_O_3G_CMD_10 = ((IDX_U32_ISM_ZBR_BLOCK_DZO3_I_O_3G == 10)<< MSK_U32_ISM_ZBR_BLOCK_DZO3_I_O_3G),
ISM_ZBR_BLOCK_DZO3_I_O_3G_CMD_11 = ((IDX_U32_ISM_ZBR_BLOCK_DZO3_I_O_3G == 11)<< MSK_U32_ISM_ZBR_BLOCK_DZO3_I_O_3G),
ISM_ZBR_BLOCK_DZO3_I_O_3G_CMD_12 = ((IDX_U32_ISM_ZBR_BLOCK_DZO3_I_O_3G == 12)<< MSK_U32_ISM_ZBR_BLOCK_DZO3_I_O_3G),
                    
                    
ISM_BLOCK_DZO3_CMD_00 = ((IDX_U32_ISM_BLOCK_DZO3 ==  0)<< MSK_U32_ISM_BLOCK_DZO3),
ISM_BLOCK_DZO3_CMD_01 = ((IDX_U32_ISM_BLOCK_DZO3 ==  1)<< MSK_U32_ISM_BLOCK_DZO3),
ISM_BLOCK_DZO3_CMD_02 = ((IDX_U32_ISM_BLOCK_DZO3 ==  2)<< MSK_U32_ISM_BLOCK_DZO3),
ISM_BLOCK_DZO3_CMD_03 = ((IDX_U32_ISM_BLOCK_DZO3 ==  3)<< MSK_U32_ISM_BLOCK_DZO3),
ISM_BLOCK_DZO3_CMD_04 = ((IDX_U32_ISM_BLOCK_DZO3 ==  4)<< MSK_U32_ISM_BLOCK_DZO3),
ISM_BLOCK_DZO3_CMD_05 = ((IDX_U32_ISM_BLOCK_DZO3 ==  5)<< MSK_U32_ISM_BLOCK_DZO3),
ISM_BLOCK_DZO3_CMD_06 = ((IDX_U32_ISM_BLOCK_DZO3 ==  6)<< MSK_U32_ISM_BLOCK_DZO3),
ISM_BLOCK_DZO3_CMD_07 = ((IDX_U32_ISM_BLOCK_DZO3 ==  7)<< MSK_U32_ISM_BLOCK_DZO3),
ISM_BLOCK_DZO3_CMD_08 = ((IDX_U32_ISM_BLOCK_DZO3 ==  8)<< MSK_U32_ISM_BLOCK_DZO3),
ISM_BLOCK_DZO3_CMD_09 = ((IDX_U32_ISM_BLOCK_DZO3 ==  9)<< MSK_U32_ISM_BLOCK_DZO3),
ISM_BLOCK_DZO3_CMD_10 = ((IDX_U32_ISM_BLOCK_DZO3 == 10)<< MSK_U32_ISM_BLOCK_DZO3),
ISM_BLOCK_DZO3_CMD_11 = ((IDX_U32_ISM_BLOCK_DZO3 == 11)<< MSK_U32_ISM_BLOCK_DZO3),
ISM_BLOCK_DZO3_CMD_12 = ((IDX_U32_ISM_BLOCK_DZO3 == 12)<< MSK_U32_ISM_BLOCK_DZO3),

ISM_ZBR_BLOCK_DZO4_I_O_3G_CMD_00 = ((IDX_U32_ISM_ZBR_BLOCK_DZO4_I_O_3G ==  0)<< MSK_U32_ISM_ZBR_BLOCK_DZO4_I_O_3G),
ISM_ZBR_BLOCK_DZO4_I_O_3G_CMD_01 = ((IDX_U32_ISM_ZBR_BLOCK_DZO4_I_O_3G ==  1)<< MSK_U32_ISM_ZBR_BLOCK_DZO4_I_O_3G),
ISM_ZBR_BLOCK_DZO4_I_O_3G_CMD_02 = ((IDX_U32_ISM_ZBR_BLOCK_DZO4_I_O_3G ==  2)<< MSK_U32_ISM_ZBR_BLOCK_DZO4_I_O_3G),
ISM_ZBR_BLOCK_DZO4_I_O_3G_CMD_03 = ((IDX_U32_ISM_ZBR_BLOCK_DZO4_I_O_3G ==  3)<< MSK_U32_ISM_ZBR_BLOCK_DZO4_I_O_3G),
ISM_ZBR_BLOCK_DZO4_I_O_3G_CMD_04 = ((IDX_U32_ISM_ZBR_BLOCK_DZO4_I_O_3G ==  4)<< MSK_U32_ISM_ZBR_BLOCK_DZO4_I_O_3G),
ISM_ZBR_BLOCK_DZO4_I_O_3G_CMD_05 = ((IDX_U32_ISM_ZBR_BLOCK_DZO4_I_O_3G ==  5)<< MSK_U32_ISM_ZBR_BLOCK_DZO4_I_O_3G),
ISM_ZBR_BLOCK_DZO4_I_O_3G_CMD_06 = ((IDX_U32_ISM_ZBR_BLOCK_DZO4_I_O_3G ==  6)<< MSK_U32_ISM_ZBR_BLOCK_DZO4_I_O_3G),
ISM_ZBR_BLOCK_DZO4_I_O_3G_CMD_07 = ((IDX_U32_ISM_ZBR_BLOCK_DZO4_I_O_3G ==  7)<< MSK_U32_ISM_ZBR_BLOCK_DZO4_I_O_3G),
ISM_ZBR_BLOCK_DZO4_I_O_3G_CMD_08 = ((IDX_U32_ISM_ZBR_BLOCK_DZO4_I_O_3G ==  8)<< MSK_U32_ISM_ZBR_BLOCK_DZO4_I_O_3G),
ISM_ZBR_BLOCK_DZO4_I_O_3G_CMD_09 = ((IDX_U32_ISM_ZBR_BLOCK_DZO4_I_O_3G ==  9)<< MSK_U32_ISM_ZBR_BLOCK_DZO4_I_O_3G),
ISM_ZBR_BLOCK_DZO4_I_O_3G_CMD_10 = ((IDX_U32_ISM_ZBR_BLOCK_DZO4_I_O_3G == 10)<< MSK_U32_ISM_ZBR_BLOCK_DZO4_I_O_3G),
ISM_ZBR_BLOCK_DZO4_I_O_3G_CMD_11 = ((IDX_U32_ISM_ZBR_BLOCK_DZO4_I_O_3G == 11)<< MSK_U32_ISM_ZBR_BLOCK_DZO4_I_O_3G),
ISM_ZBR_BLOCK_DZO4_I_O_3G_CMD_12 = ((IDX_U32_ISM_ZBR_BLOCK_DZO4_I_O_3G == 12)<< MSK_U32_ISM_ZBR_BLOCK_DZO4_I_O_3G),
                    
                    
ISM_BLOCK_DZO4_CMD_00 = ((IDX_U32_ISM_BLOCK_DZO4 ==  0)<< MSK_U32_ISM_BLOCK_DZO4),
ISM_BLOCK_DZO4_CMD_01 = ((IDX_U32_ISM_BLOCK_DZO4 ==  1)<< MSK_U32_ISM_BLOCK_DZO4),
ISM_BLOCK_DZO4_CMD_02 = ((IDX_U32_ISM_BLOCK_DZO4 ==  2)<< MSK_U32_ISM_BLOCK_DZO4),
ISM_BLOCK_DZO4_CMD_03 = ((IDX_U32_ISM_BLOCK_DZO4 ==  3)<< MSK_U32_ISM_BLOCK_DZO4),
ISM_BLOCK_DZO4_CMD_04 = ((IDX_U32_ISM_BLOCK_DZO4 ==  4)<< MSK_U32_ISM_BLOCK_DZO4),
ISM_BLOCK_DZO4_CMD_05 = ((IDX_U32_ISM_BLOCK_DZO4 ==  5)<< MSK_U32_ISM_BLOCK_DZO4),
ISM_BLOCK_DZO4_CMD_06 = ((IDX_U32_ISM_BLOCK_DZO4 ==  6)<< MSK_U32_ISM_BLOCK_DZO4),
ISM_BLOCK_DZO4_CMD_07 = ((IDX_U32_ISM_BLOCK_DZO4 ==  7)<< MSK_U32_ISM_BLOCK_DZO4),
ISM_BLOCK_DZO4_CMD_08 = ((IDX_U32_ISM_BLOCK_DZO4 ==  8)<< MSK_U32_ISM_BLOCK_DZO4),
ISM_BLOCK_DZO4_CMD_09 = ((IDX_U32_ISM_BLOCK_DZO4 ==  9)<< MSK_U32_ISM_BLOCK_DZO4),
ISM_BLOCK_DZO4_CMD_10 = ((IDX_U32_ISM_BLOCK_DZO4 == 10)<< MSK_U32_ISM_BLOCK_DZO4),
ISM_BLOCK_DZO4_CMD_11 = ((IDX_U32_ISM_BLOCK_DZO4 == 11)<< MSK_U32_ISM_BLOCK_DZO4),
ISM_BLOCK_DZO4_CMD_12 = ((IDX_U32_ISM_BLOCK_DZO4 == 12)<< MSK_U32_ISM_BLOCK_DZO4),
                    
                    
ISM_BLOCK_ZDZ_CMD_00 = ((IDX_U32_ISM_BLOCK_ZDZ ==  0)<< MSK_U32_ISM_BLOCK_ZDZ),
ISM_BLOCK_ZDZ_CMD_01 = ((IDX_U32_ISM_BLOCK_ZDZ ==  1)<< MSK_U32_ISM_BLOCK_ZDZ),
ISM_BLOCK_ZDZ_CMD_02 = ((IDX_U32_ISM_BLOCK_ZDZ ==  2)<< MSK_U32_ISM_BLOCK_ZDZ),
ISM_BLOCK_ZDZ_CMD_03 = ((IDX_U32_ISM_BLOCK_ZDZ ==  3)<< MSK_U32_ISM_BLOCK_ZDZ),
ISM_BLOCK_ZDZ_CMD_04 = ((IDX_U32_ISM_BLOCK_ZDZ ==  4)<< MSK_U32_ISM_BLOCK_ZDZ),
ISM_BLOCK_ZDZ_CMD_05 = ((IDX_U32_ISM_BLOCK_ZDZ ==  5)<< MSK_U32_ISM_BLOCK_ZDZ),
ISM_BLOCK_ZDZ_CMD_06 = ((IDX_U32_ISM_BLOCK_ZDZ ==  6)<< MSK_U32_ISM_BLOCK_ZDZ),
ISM_BLOCK_ZDZ_CMD_07 = ((IDX_U32_ISM_BLOCK_ZDZ ==  7)<< MSK_U32_ISM_BLOCK_ZDZ),
ISM_BLOCK_ZDZ_CMD_08 = ((IDX_U32_ISM_BLOCK_ZDZ ==  8)<< MSK_U32_ISM_BLOCK_ZDZ),
ISM_BLOCK_ZDZ_CMD_09 = ((IDX_U32_ISM_BLOCK_ZDZ ==  9)<< MSK_U32_ISM_BLOCK_ZDZ),
ISM_BLOCK_ZDZ_CMD_10 = ((IDX_U32_ISM_BLOCK_ZDZ == 10)<< MSK_U32_ISM_BLOCK_ZDZ),
ISM_BLOCK_ZDZ_CMD_11 = ((IDX_U32_ISM_BLOCK_ZDZ == 11)<< MSK_U32_ISM_BLOCK_ZDZ),
ISM_BLOCK_ZDZ_CMD_12 = ((IDX_U32_ISM_BLOCK_ZDZ == 12)<< MSK_U32_ISM_BLOCK_ZDZ),
                    
                    
ISM_PUSK_ZDZ_VID_DV_CMD_00 = ((IDX_U32_ISM_PUSK_ZDZ_VID_DV ==  0)<< MSK_U32_ISM_PUSK_ZDZ_VID_DV),
ISM_PUSK_ZDZ_VID_DV_CMD_01 = ((IDX_U32_ISM_PUSK_ZDZ_VID_DV ==  1)<< MSK_U32_ISM_PUSK_ZDZ_VID_DV),
ISM_PUSK_ZDZ_VID_DV_CMD_02 = ((IDX_U32_ISM_PUSK_ZDZ_VID_DV ==  2)<< MSK_U32_ISM_PUSK_ZDZ_VID_DV),
ISM_PUSK_ZDZ_VID_DV_CMD_03 = ((IDX_U32_ISM_PUSK_ZDZ_VID_DV ==  3)<< MSK_U32_ISM_PUSK_ZDZ_VID_DV),
ISM_PUSK_ZDZ_VID_DV_CMD_04 = ((IDX_U32_ISM_PUSK_ZDZ_VID_DV ==  4)<< MSK_U32_ISM_PUSK_ZDZ_VID_DV),
ISM_PUSK_ZDZ_VID_DV_CMD_05 = ((IDX_U32_ISM_PUSK_ZDZ_VID_DV ==  5)<< MSK_U32_ISM_PUSK_ZDZ_VID_DV),
ISM_PUSK_ZDZ_VID_DV_CMD_06 = ((IDX_U32_ISM_PUSK_ZDZ_VID_DV ==  6)<< MSK_U32_ISM_PUSK_ZDZ_VID_DV),
ISM_PUSK_ZDZ_VID_DV_CMD_07 = ((IDX_U32_ISM_PUSK_ZDZ_VID_DV ==  7)<< MSK_U32_ISM_PUSK_ZDZ_VID_DV),
ISM_PUSK_ZDZ_VID_DV_CMD_08 = ((IDX_U32_ISM_PUSK_ZDZ_VID_DV ==  8)<< MSK_U32_ISM_PUSK_ZDZ_VID_DV),
ISM_PUSK_ZDZ_VID_DV_CMD_09 = ((IDX_U32_ISM_PUSK_ZDZ_VID_DV ==  9)<< MSK_U32_ISM_PUSK_ZDZ_VID_DV),
ISM_PUSK_ZDZ_VID_DV_CMD_10 = ((IDX_U32_ISM_PUSK_ZDZ_VID_DV == 10)<< MSK_U32_ISM_PUSK_ZDZ_VID_DV),
ISM_PUSK_ZDZ_VID_DV_CMD_11 = ((IDX_U32_ISM_PUSK_ZDZ_VID_DV == 11)<< MSK_U32_ISM_PUSK_ZDZ_VID_DV),
ISM_PUSK_ZDZ_VID_DV_CMD_12 = ((IDX_U32_ISM_PUSK_ZDZ_VID_DV == 12)<< MSK_U32_ISM_PUSK_ZDZ_VID_DV),

ISM_BLOCK_MCZO1_CMD_00 = ((IDX_U32_ISM_BLOCK_MCZO1 ==  0)<< MSK_U32_ISM_BLOCK_MCZO1),
ISM_BLOCK_MCZO1_CMD_01 = ((IDX_U32_ISM_BLOCK_MCZO1 ==  1)<< MSK_U32_ISM_BLOCK_MCZO1),
ISM_BLOCK_MCZO1_CMD_02 = ((IDX_U32_ISM_BLOCK_MCZO1 ==  2)<< MSK_U32_ISM_BLOCK_MCZO1),
ISM_BLOCK_MCZO1_CMD_03 = ((IDX_U32_ISM_BLOCK_MCZO1 ==  3)<< MSK_U32_ISM_BLOCK_MCZO1),
ISM_BLOCK_MCZO1_CMD_04 = ((IDX_U32_ISM_BLOCK_MCZO1 ==  4)<< MSK_U32_ISM_BLOCK_MCZO1),
ISM_BLOCK_MCZO1_CMD_05 = ((IDX_U32_ISM_BLOCK_MCZO1 ==  5)<< MSK_U32_ISM_BLOCK_MCZO1),
ISM_BLOCK_MCZO1_CMD_06 = ((IDX_U32_ISM_BLOCK_MCZO1 ==  6)<< MSK_U32_ISM_BLOCK_MCZO1),
ISM_BLOCK_MCZO1_CMD_07 = ((IDX_U32_ISM_BLOCK_MCZO1 ==  7)<< MSK_U32_ISM_BLOCK_MCZO1),
ISM_BLOCK_MCZO1_CMD_08 = ((IDX_U32_ISM_BLOCK_MCZO1 ==  8)<< MSK_U32_ISM_BLOCK_MCZO1),
ISM_BLOCK_MCZO1_CMD_09 = ((IDX_U32_ISM_BLOCK_MCZO1 ==  9)<< MSK_U32_ISM_BLOCK_MCZO1),
ISM_BLOCK_MCZO1_CMD_10 = ((IDX_U32_ISM_BLOCK_MCZO1 == 10)<< MSK_U32_ISM_BLOCK_MCZO1),
ISM_BLOCK_MCZO1_CMD_11 = ((IDX_U32_ISM_BLOCK_MCZO1 == 11)<< MSK_U32_ISM_BLOCK_MCZO1),
ISM_BLOCK_MCZO1_CMD_12 = ((IDX_U32_ISM_BLOCK_MCZO1 == 12)<< MSK_U32_ISM_BLOCK_MCZO1),
                    
                    
ISM_BLOCK_MCZO2_CMD_00 = ((IDX_U32_ISM_BLOCK_MCZO2 ==  0)<< MSK_U32_ISM_BLOCK_MCZO2),
ISM_BLOCK_MCZO2_CMD_01 = ((IDX_U32_ISM_BLOCK_MCZO2 ==  1)<< MSK_U32_ISM_BLOCK_MCZO2),
ISM_BLOCK_MCZO2_CMD_02 = ((IDX_U32_ISM_BLOCK_MCZO2 ==  2)<< MSK_U32_ISM_BLOCK_MCZO2),
ISM_BLOCK_MCZO2_CMD_03 = ((IDX_U32_ISM_BLOCK_MCZO2 ==  3)<< MSK_U32_ISM_BLOCK_MCZO2),
ISM_BLOCK_MCZO2_CMD_04 = ((IDX_U32_ISM_BLOCK_MCZO2 ==  4)<< MSK_U32_ISM_BLOCK_MCZO2),
ISM_BLOCK_MCZO2_CMD_05 = ((IDX_U32_ISM_BLOCK_MCZO2 ==  5)<< MSK_U32_ISM_BLOCK_MCZO2),
ISM_BLOCK_MCZO2_CMD_06 = ((IDX_U32_ISM_BLOCK_MCZO2 ==  6)<< MSK_U32_ISM_BLOCK_MCZO2),
ISM_BLOCK_MCZO2_CMD_07 = ((IDX_U32_ISM_BLOCK_MCZO2 ==  7)<< MSK_U32_ISM_BLOCK_MCZO2),
ISM_BLOCK_MCZO2_CMD_08 = ((IDX_U32_ISM_BLOCK_MCZO2 ==  8)<< MSK_U32_ISM_BLOCK_MCZO2),
ISM_BLOCK_MCZO2_CMD_09 = ((IDX_U32_ISM_BLOCK_MCZO2 ==  9)<< MSK_U32_ISM_BLOCK_MCZO2),
ISM_BLOCK_MCZO2_CMD_10 = ((IDX_U32_ISM_BLOCK_MCZO2 == 10)<< MSK_U32_ISM_BLOCK_MCZO2),
ISM_BLOCK_MCZO2_CMD_11 = ((IDX_U32_ISM_BLOCK_MCZO2 == 11)<< MSK_U32_ISM_BLOCK_MCZO2),
ISM_BLOCK_MCZO2_CMD_12 = ((IDX_U32_ISM_BLOCK_MCZO2 == 12)<< MSK_U32_ISM_BLOCK_MCZO2),
                    
                    
ISM_BLOCK_PR_MCZO2_CMD_00 = ((IDX_U32_ISM_BLOCK_PR_MCZO2 ==  0)<< MSK_U32_ISM_BLOCK_PR_MCZO2),
ISM_BLOCK_PR_MCZO2_CMD_01 = ((IDX_U32_ISM_BLOCK_PR_MCZO2 ==  1)<< MSK_U32_ISM_BLOCK_PR_MCZO2),
ISM_BLOCK_PR_MCZO2_CMD_02 = ((IDX_U32_ISM_BLOCK_PR_MCZO2 ==  2)<< MSK_U32_ISM_BLOCK_PR_MCZO2),
ISM_BLOCK_PR_MCZO2_CMD_03 = ((IDX_U32_ISM_BLOCK_PR_MCZO2 ==  3)<< MSK_U32_ISM_BLOCK_PR_MCZO2),
ISM_BLOCK_PR_MCZO2_CMD_04 = ((IDX_U32_ISM_BLOCK_PR_MCZO2 ==  4)<< MSK_U32_ISM_BLOCK_PR_MCZO2),
ISM_BLOCK_PR_MCZO2_CMD_05 = ((IDX_U32_ISM_BLOCK_PR_MCZO2 ==  5)<< MSK_U32_ISM_BLOCK_PR_MCZO2),
ISM_BLOCK_PR_MCZO2_CMD_06 = ((IDX_U32_ISM_BLOCK_PR_MCZO2 ==  6)<< MSK_U32_ISM_BLOCK_PR_MCZO2),
ISM_BLOCK_PR_MCZO2_CMD_07 = ((IDX_U32_ISM_BLOCK_PR_MCZO2 ==  7)<< MSK_U32_ISM_BLOCK_PR_MCZO2),
ISM_BLOCK_PR_MCZO2_CMD_08 = ((IDX_U32_ISM_BLOCK_PR_MCZO2 ==  8)<< MSK_U32_ISM_BLOCK_PR_MCZO2),
ISM_BLOCK_PR_MCZO2_CMD_09 = ((IDX_U32_ISM_BLOCK_PR_MCZO2 ==  9)<< MSK_U32_ISM_BLOCK_PR_MCZO2),
ISM_BLOCK_PR_MCZO2_CMD_10 = ((IDX_U32_ISM_BLOCK_PR_MCZO2 == 10)<< MSK_U32_ISM_BLOCK_PR_MCZO2),
ISM_BLOCK_PR_MCZO2_CMD_11 = ((IDX_U32_ISM_BLOCK_PR_MCZO2 == 11)<< MSK_U32_ISM_BLOCK_PR_MCZO2),
ISM_BLOCK_PR_MCZO2_CMD_12 = ((IDX_U32_ISM_BLOCK_PR_MCZO2 == 12)<< MSK_U32_ISM_BLOCK_PR_MCZO2),
                    
                    
ISM_BLOCK_MCZO3_CMD_00 = ((IDX_U32_ISM_BLOCK_MCZO3 ==  0)<< MSK_U32_ISM_BLOCK_MCZO3),
ISM_BLOCK_MCZO3_CMD_01 = ((IDX_U32_ISM_BLOCK_MCZO3 ==  1)<< MSK_U32_ISM_BLOCK_MCZO3),
ISM_BLOCK_MCZO3_CMD_02 = ((IDX_U32_ISM_BLOCK_MCZO3 ==  2)<< MSK_U32_ISM_BLOCK_MCZO3),
ISM_BLOCK_MCZO3_CMD_03 = ((IDX_U32_ISM_BLOCK_MCZO3 ==  3)<< MSK_U32_ISM_BLOCK_MCZO3),
ISM_BLOCK_MCZO3_CMD_04 = ((IDX_U32_ISM_BLOCK_MCZO3 ==  4)<< MSK_U32_ISM_BLOCK_MCZO3),
ISM_BLOCK_MCZO3_CMD_05 = ((IDX_U32_ISM_BLOCK_MCZO3 ==  5)<< MSK_U32_ISM_BLOCK_MCZO3),
ISM_BLOCK_MCZO3_CMD_06 = ((IDX_U32_ISM_BLOCK_MCZO3 ==  6)<< MSK_U32_ISM_BLOCK_MCZO3),
ISM_BLOCK_MCZO3_CMD_07 = ((IDX_U32_ISM_BLOCK_MCZO3 ==  7)<< MSK_U32_ISM_BLOCK_MCZO3),
ISM_BLOCK_MCZO3_CMD_08 = ((IDX_U32_ISM_BLOCK_MCZO3 ==  8)<< MSK_U32_ISM_BLOCK_MCZO3),
ISM_BLOCK_MCZO3_CMD_09 = ((IDX_U32_ISM_BLOCK_MCZO3 ==  9)<< MSK_U32_ISM_BLOCK_MCZO3),
ISM_BLOCK_MCZO3_CMD_10 = ((IDX_U32_ISM_BLOCK_MCZO3 == 10)<< MSK_U32_ISM_BLOCK_MCZO3),
ISM_BLOCK_MCZO3_CMD_11 = ((IDX_U32_ISM_BLOCK_MCZO3 == 11)<< MSK_U32_ISM_BLOCK_MCZO3),
ISM_BLOCK_MCZO3_CMD_12 = ((IDX_U32_ISM_BLOCK_MCZO3 == 12)<< MSK_U32_ISM_BLOCK_MCZO3),

ISM_BLOCK_MCZO4_CMD_00 = ((IDX_U32_ISM_BLOCK_MCZO4 ==  0)<< MSK_U32_ISM_BLOCK_MCZO4 ),
ISM_BLOCK_MCZO4_CMD_01 = ((IDX_U32_ISM_BLOCK_MCZO4 ==  1)<< MSK_U32_ISM_BLOCK_MCZO4 ),
ISM_BLOCK_MCZO4_CMD_02 = ((IDX_U32_ISM_BLOCK_MCZO4 ==  2)<< MSK_U32_ISM_BLOCK_MCZO4 ),
ISM_BLOCK_MCZO4_CMD_03 = ((IDX_U32_ISM_BLOCK_MCZO4 ==  3)<< MSK_U32_ISM_BLOCK_MCZO4 ),
ISM_BLOCK_MCZO4_CMD_04 = ((IDX_U32_ISM_BLOCK_MCZO4 ==  4)<< MSK_U32_ISM_BLOCK_MCZO4 ),
ISM_BLOCK_MCZO4_CMD_05 = ((IDX_U32_ISM_BLOCK_MCZO4 ==  5)<< MSK_U32_ISM_BLOCK_MCZO4 ),
ISM_BLOCK_MCZO4_CMD_06 = ((IDX_U32_ISM_BLOCK_MCZO4 ==  6)<< MSK_U32_ISM_BLOCK_MCZO4 ),
ISM_BLOCK_MCZO4_CMD_07 = ((IDX_U32_ISM_BLOCK_MCZO4 ==  7)<< MSK_U32_ISM_BLOCK_MCZO4 ),
ISM_BLOCK_MCZO4_CMD_08 = ((IDX_U32_ISM_BLOCK_MCZO4 ==  8)<< MSK_U32_ISM_BLOCK_MCZO4 ),
ISM_BLOCK_MCZO4_CMD_09 = ((IDX_U32_ISM_BLOCK_MCZO4 ==  9)<< MSK_U32_ISM_BLOCK_MCZO4 ),
ISM_BLOCK_MCZO4_CMD_10 = ((IDX_U32_ISM_BLOCK_MCZO4 == 10)<< MSK_U32_ISM_BLOCK_MCZO4 ),
ISM_BLOCK_MCZO4_CMD_11 = ((IDX_U32_ISM_BLOCK_MCZO4 == 11)<< MSK_U32_ISM_BLOCK_MCZO4 ),
ISM_BLOCK_MCZO4_CMD_12 = ((IDX_U32_ISM_BLOCK_MCZO4 == 12)<< MSK_U32_ISM_BLOCK_MCZO4 ),
                    
                    
ISM_BLOCK_MCZR1_CMD_00 = ((IDX_U32_ISM_BLOCK_MCZR1  ==  0)<< MSK_U32_ISM_BLOCK_MCZR1 ),
ISM_BLOCK_MCZR1_CMD_01 = ((IDX_U32_ISM_BLOCK_MCZR1  ==  1)<< MSK_U32_ISM_BLOCK_MCZR1 ),
ISM_BLOCK_MCZR1_CMD_02 = ((IDX_U32_ISM_BLOCK_MCZR1  ==  2)<< MSK_U32_ISM_BLOCK_MCZR1 ),
ISM_BLOCK_MCZR1_CMD_03 = ((IDX_U32_ISM_BLOCK_MCZR1  ==  3)<< MSK_U32_ISM_BLOCK_MCZR1 ),
ISM_BLOCK_MCZR1_CMD_04 = ((IDX_U32_ISM_BLOCK_MCZR1  ==  4)<< MSK_U32_ISM_BLOCK_MCZR1 ),
ISM_BLOCK_MCZR1_CMD_05 = ((IDX_U32_ISM_BLOCK_MCZR1  ==  5)<< MSK_U32_ISM_BLOCK_MCZR1 ),
ISM_BLOCK_MCZR1_CMD_06 = ((IDX_U32_ISM_BLOCK_MCZR1  ==  6)<< MSK_U32_ISM_BLOCK_MCZR1 ),
ISM_BLOCK_MCZR1_CMD_07 = ((IDX_U32_ISM_BLOCK_MCZR1  ==  7)<< MSK_U32_ISM_BLOCK_MCZR1 ),
ISM_BLOCK_MCZR1_CMD_08 = ((IDX_U32_ISM_BLOCK_MCZR1  ==  8)<< MSK_U32_ISM_BLOCK_MCZR1 ),
ISM_BLOCK_MCZR1_CMD_09 = ((IDX_U32_ISM_BLOCK_MCZR1  ==  9)<< MSK_U32_ISM_BLOCK_MCZR1 ),
ISM_BLOCK_MCZR1_CMD_10 = ((IDX_U32_ISM_BLOCK_MCZR1  == 10)<< MSK_U32_ISM_BLOCK_MCZR1 ),
ISM_BLOCK_MCZR1_CMD_11 = ((IDX_U32_ISM_BLOCK_MCZR1  == 11)<< MSK_U32_ISM_BLOCK_MCZR1 ),
ISM_BLOCK_MCZR1_CMD_12 = ((IDX_U32_ISM_BLOCK_MCZR1  == 12)<< MSK_U32_ISM_BLOCK_MCZR1 ),
                    
                    
ISM_BLOCK_MCZR2_CMD_00 = ((IDX_U32_ISM_BLOCK_MCZR2  ==  0)<< MSK_U32_ISM_BLOCK_MCZR2 ),
ISM_BLOCK_MCZR2_CMD_01 = ((IDX_U32_ISM_BLOCK_MCZR2  ==  1)<< MSK_U32_ISM_BLOCK_MCZR2 ),
ISM_BLOCK_MCZR2_CMD_02 = ((IDX_U32_ISM_BLOCK_MCZR2  ==  2)<< MSK_U32_ISM_BLOCK_MCZR2 ),
ISM_BLOCK_MCZR2_CMD_03 = ((IDX_U32_ISM_BLOCK_MCZR2  ==  3)<< MSK_U32_ISM_BLOCK_MCZR2 ),
ISM_BLOCK_MCZR2_CMD_04 = ((IDX_U32_ISM_BLOCK_MCZR2  ==  4)<< MSK_U32_ISM_BLOCK_MCZR2 ),
ISM_BLOCK_MCZR2_CMD_05 = ((IDX_U32_ISM_BLOCK_MCZR2  ==  5)<< MSK_U32_ISM_BLOCK_MCZR2 ),
ISM_BLOCK_MCZR2_CMD_06 = ((IDX_U32_ISM_BLOCK_MCZR2  ==  6)<< MSK_U32_ISM_BLOCK_MCZR2 ),
ISM_BLOCK_MCZR2_CMD_07 = ((IDX_U32_ISM_BLOCK_MCZR2  ==  7)<< MSK_U32_ISM_BLOCK_MCZR2 ),
ISM_BLOCK_MCZR2_CMD_08 = ((IDX_U32_ISM_BLOCK_MCZR2  ==  8)<< MSK_U32_ISM_BLOCK_MCZR2 ),
ISM_BLOCK_MCZR2_CMD_09 = ((IDX_U32_ISM_BLOCK_MCZR2  ==  9)<< MSK_U32_ISM_BLOCK_MCZR2 ),
ISM_BLOCK_MCZR2_CMD_10 = ((IDX_U32_ISM_BLOCK_MCZR2  == 10)<< MSK_U32_ISM_BLOCK_MCZR2 ),
ISM_BLOCK_MCZR2_CMD_11 = ((IDX_U32_ISM_BLOCK_MCZR2  == 11)<< MSK_U32_ISM_BLOCK_MCZR2 ),
ISM_BLOCK_MCZR2_CMD_12 = ((IDX_U32_ISM_BLOCK_MCZR2  == 12)<< MSK_U32_ISM_BLOCK_MCZR2 ),
                    
                    
ISM_STAT_BLK_APV_CMD_00 = ((IDX_U32_ISM_STAT_BLK_APV ==  0)<< MSK_U32_ISM_STAT_BLK_APV),
ISM_STAT_BLK_APV_CMD_01 = ((IDX_U32_ISM_STAT_BLK_APV ==  1)<< MSK_U32_ISM_STAT_BLK_APV),
ISM_STAT_BLK_APV_CMD_02 = ((IDX_U32_ISM_STAT_BLK_APV ==  2)<< MSK_U32_ISM_STAT_BLK_APV),
ISM_STAT_BLK_APV_CMD_03 = ((IDX_U32_ISM_STAT_BLK_APV ==  3)<< MSK_U32_ISM_STAT_BLK_APV),
ISM_STAT_BLK_APV_CMD_04 = ((IDX_U32_ISM_STAT_BLK_APV ==  4)<< MSK_U32_ISM_STAT_BLK_APV),
ISM_STAT_BLK_APV_CMD_05 = ((IDX_U32_ISM_STAT_BLK_APV ==  5)<< MSK_U32_ISM_STAT_BLK_APV),
ISM_STAT_BLK_APV_CMD_06 = ((IDX_U32_ISM_STAT_BLK_APV ==  6)<< MSK_U32_ISM_STAT_BLK_APV),
ISM_STAT_BLK_APV_CMD_07 = ((IDX_U32_ISM_STAT_BLK_APV ==  7)<< MSK_U32_ISM_STAT_BLK_APV),
ISM_STAT_BLK_APV_CMD_08 = ((IDX_U32_ISM_STAT_BLK_APV ==  8)<< MSK_U32_ISM_STAT_BLK_APV),
ISM_STAT_BLK_APV_CMD_09 = ((IDX_U32_ISM_STAT_BLK_APV ==  9)<< MSK_U32_ISM_STAT_BLK_APV),
ISM_STAT_BLK_APV_CMD_10 = ((IDX_U32_ISM_STAT_BLK_APV == 10)<< MSK_U32_ISM_STAT_BLK_APV),
ISM_STAT_BLK_APV_CMD_11 = ((IDX_U32_ISM_STAT_BLK_APV == 11)<< MSK_U32_ISM_STAT_BLK_APV),
ISM_STAT_BLK_APV_CMD_12 = ((IDX_U32_ISM_STAT_BLK_APV == 12)<< MSK_U32_ISM_STAT_BLK_APV),


ISM_ACHR_CHAPV_VID_DV_CMD_00 = ((IDX_U32_ISM_ACHR_CHAPV_VID_DV ==  0)<< MSK_U32_ISM_ACHR_CHAPV_VID_DV),
ISM_ACHR_CHAPV_VID_DV_CMD_01 = ((IDX_U32_ISM_ACHR_CHAPV_VID_DV ==  1)<< MSK_U32_ISM_ACHR_CHAPV_VID_DV),
ISM_ACHR_CHAPV_VID_DV_CMD_02 = ((IDX_U32_ISM_ACHR_CHAPV_VID_DV ==  2)<< MSK_U32_ISM_ACHR_CHAPV_VID_DV),
ISM_ACHR_CHAPV_VID_DV_CMD_03 = ((IDX_U32_ISM_ACHR_CHAPV_VID_DV ==  3)<< MSK_U32_ISM_ACHR_CHAPV_VID_DV),
ISM_ACHR_CHAPV_VID_DV_CMD_04 = ((IDX_U32_ISM_ACHR_CHAPV_VID_DV ==  4)<< MSK_U32_ISM_ACHR_CHAPV_VID_DV),
ISM_ACHR_CHAPV_VID_DV_CMD_05 = ((IDX_U32_ISM_ACHR_CHAPV_VID_DV ==  5)<< MSK_U32_ISM_ACHR_CHAPV_VID_DV),
ISM_ACHR_CHAPV_VID_DV_CMD_06 = ((IDX_U32_ISM_ACHR_CHAPV_VID_DV ==  6)<< MSK_U32_ISM_ACHR_CHAPV_VID_DV),
ISM_ACHR_CHAPV_VID_DV_CMD_07 = ((IDX_U32_ISM_ACHR_CHAPV_VID_DV ==  7)<< MSK_U32_ISM_ACHR_CHAPV_VID_DV),
ISM_ACHR_CHAPV_VID_DV_CMD_08 = ((IDX_U32_ISM_ACHR_CHAPV_VID_DV ==  8)<< MSK_U32_ISM_ACHR_CHAPV_VID_DV),
ISM_ACHR_CHAPV_VID_DV_CMD_09 = ((IDX_U32_ISM_ACHR_CHAPV_VID_DV ==  9)<< MSK_U32_ISM_ACHR_CHAPV_VID_DV),
ISM_ACHR_CHAPV_VID_DV_CMD_10 = ((IDX_U32_ISM_ACHR_CHAPV_VID_DV == 10)<< MSK_U32_ISM_ACHR_CHAPV_VID_DV),
ISM_ACHR_CHAPV_VID_DV_CMD_11 = ((IDX_U32_ISM_ACHR_CHAPV_VID_DV == 11)<< MSK_U32_ISM_ACHR_CHAPV_VID_DV),
ISM_ACHR_CHAPV_VID_DV_CMD_12 = ((IDX_U32_ISM_ACHR_CHAPV_VID_DV == 12)<< MSK_U32_ISM_ACHR_CHAPV_VID_DV),
                    
                    
ISM_BLOCK_ACHR1_CMD_00 = ((IDX_U32_ISM_BLOCK_ACHR1 ==  0)<< MSK_U32_ISM_BLOCK_ACHR1),
ISM_BLOCK_ACHR1_CMD_01 = ((IDX_U32_ISM_BLOCK_ACHR1 ==  1)<< MSK_U32_ISM_BLOCK_ACHR1),
ISM_BLOCK_ACHR1_CMD_02 = ((IDX_U32_ISM_BLOCK_ACHR1 ==  2)<< MSK_U32_ISM_BLOCK_ACHR1),
ISM_BLOCK_ACHR1_CMD_03 = ((IDX_U32_ISM_BLOCK_ACHR1 ==  3)<< MSK_U32_ISM_BLOCK_ACHR1),
ISM_BLOCK_ACHR1_CMD_04 = ((IDX_U32_ISM_BLOCK_ACHR1 ==  4)<< MSK_U32_ISM_BLOCK_ACHR1),
ISM_BLOCK_ACHR1_CMD_05 = ((IDX_U32_ISM_BLOCK_ACHR1 ==  5)<< MSK_U32_ISM_BLOCK_ACHR1),
ISM_BLOCK_ACHR1_CMD_06 = ((IDX_U32_ISM_BLOCK_ACHR1 ==  6)<< MSK_U32_ISM_BLOCK_ACHR1),
ISM_BLOCK_ACHR1_CMD_07 = ((IDX_U32_ISM_BLOCK_ACHR1 ==  7)<< MSK_U32_ISM_BLOCK_ACHR1),
ISM_BLOCK_ACHR1_CMD_08 = ((IDX_U32_ISM_BLOCK_ACHR1 ==  8)<< MSK_U32_ISM_BLOCK_ACHR1),
ISM_BLOCK_ACHR1_CMD_09 = ((IDX_U32_ISM_BLOCK_ACHR1 ==  9)<< MSK_U32_ISM_BLOCK_ACHR1),
ISM_BLOCK_ACHR1_CMD_10 = ((IDX_U32_ISM_BLOCK_ACHR1 == 10)<< MSK_U32_ISM_BLOCK_ACHR1),
ISM_BLOCK_ACHR1_CMD_11 = ((IDX_U32_ISM_BLOCK_ACHR1 == 11)<< MSK_U32_ISM_BLOCK_ACHR1),
ISM_BLOCK_ACHR1_CMD_12 = ((IDX_U32_ISM_BLOCK_ACHR1 == 12)<< MSK_U32_ISM_BLOCK_ACHR1),
                    
                    
ISM_BLOCK_ACHR2_CMD_00 = ((IDX_U32_ISM_BLOCK_ACHR2 ==  0)<< MSK_U32_ISM_BLOCK_ACHR2),
ISM_BLOCK_ACHR2_CMD_01 = ((IDX_U32_ISM_BLOCK_ACHR2 ==  1)<< MSK_U32_ISM_BLOCK_ACHR2),
ISM_BLOCK_ACHR2_CMD_02 = ((IDX_U32_ISM_BLOCK_ACHR2 ==  2)<< MSK_U32_ISM_BLOCK_ACHR2),
ISM_BLOCK_ACHR2_CMD_03 = ((IDX_U32_ISM_BLOCK_ACHR2 ==  3)<< MSK_U32_ISM_BLOCK_ACHR2),
ISM_BLOCK_ACHR2_CMD_04 = ((IDX_U32_ISM_BLOCK_ACHR2 ==  4)<< MSK_U32_ISM_BLOCK_ACHR2),
ISM_BLOCK_ACHR2_CMD_05 = ((IDX_U32_ISM_BLOCK_ACHR2 ==  5)<< MSK_U32_ISM_BLOCK_ACHR2),
ISM_BLOCK_ACHR2_CMD_06 = ((IDX_U32_ISM_BLOCK_ACHR2 ==  6)<< MSK_U32_ISM_BLOCK_ACHR2),
ISM_BLOCK_ACHR2_CMD_07 = ((IDX_U32_ISM_BLOCK_ACHR2 ==  7)<< MSK_U32_ISM_BLOCK_ACHR2),
ISM_BLOCK_ACHR2_CMD_08 = ((IDX_U32_ISM_BLOCK_ACHR2 ==  8)<< MSK_U32_ISM_BLOCK_ACHR2),
ISM_BLOCK_ACHR2_CMD_09 = ((IDX_U32_ISM_BLOCK_ACHR2 ==  9)<< MSK_U32_ISM_BLOCK_ACHR2),
ISM_BLOCK_ACHR2_CMD_10 = ((IDX_U32_ISM_BLOCK_ACHR2 == 10)<< MSK_U32_ISM_BLOCK_ACHR2),
ISM_BLOCK_ACHR2_CMD_11 = ((IDX_U32_ISM_BLOCK_ACHR2 == 11)<< MSK_U32_ISM_BLOCK_ACHR2),
ISM_BLOCK_ACHR2_CMD_12 = ((IDX_U32_ISM_BLOCK_ACHR2 == 12)<< MSK_U32_ISM_BLOCK_ACHR2),
                    
                    
ISM_PUSK_UROV_VID_DV_CMD_00 = ((IDX_U32_ISM_PUSK_UROV_VID_DV  ==  0)<< MSK_U32_ISM_PUSK_UROV_VID_DV ),
ISM_PUSK_UROV_VID_DV_CMD_01 = ((IDX_U32_ISM_PUSK_UROV_VID_DV  ==  1)<< MSK_U32_ISM_PUSK_UROV_VID_DV ),
ISM_PUSK_UROV_VID_DV_CMD_02 = ((IDX_U32_ISM_PUSK_UROV_VID_DV  ==  2)<< MSK_U32_ISM_PUSK_UROV_VID_DV ),
ISM_PUSK_UROV_VID_DV_CMD_03 = ((IDX_U32_ISM_PUSK_UROV_VID_DV  ==  3)<< MSK_U32_ISM_PUSK_UROV_VID_DV ),
ISM_PUSK_UROV_VID_DV_CMD_04 = ((IDX_U32_ISM_PUSK_UROV_VID_DV  ==  4)<< MSK_U32_ISM_PUSK_UROV_VID_DV ),
ISM_PUSK_UROV_VID_DV_CMD_05 = ((IDX_U32_ISM_PUSK_UROV_VID_DV  ==  5)<< MSK_U32_ISM_PUSK_UROV_VID_DV ),
ISM_PUSK_UROV_VID_DV_CMD_06 = ((IDX_U32_ISM_PUSK_UROV_VID_DV  ==  6)<< MSK_U32_ISM_PUSK_UROV_VID_DV ),
ISM_PUSK_UROV_VID_DV_CMD_07 = ((IDX_U32_ISM_PUSK_UROV_VID_DV  ==  7)<< MSK_U32_ISM_PUSK_UROV_VID_DV ),
ISM_PUSK_UROV_VID_DV_CMD_08 = ((IDX_U32_ISM_PUSK_UROV_VID_DV  ==  8)<< MSK_U32_ISM_PUSK_UROV_VID_DV ),
ISM_PUSK_UROV_VID_DV_CMD_09 = ((IDX_U32_ISM_PUSK_UROV_VID_DV  ==  9)<< MSK_U32_ISM_PUSK_UROV_VID_DV ),
ISM_PUSK_UROV_VID_DV_CMD_10 = ((IDX_U32_ISM_PUSK_UROV_VID_DV  == 10)<< MSK_U32_ISM_PUSK_UROV_VID_DV ),
ISM_PUSK_UROV_VID_DV_CMD_11 = ((IDX_U32_ISM_PUSK_UROV_VID_DV  == 11)<< MSK_U32_ISM_PUSK_UROV_VID_DV ),
ISM_PUSK_UROV_VID_DV_CMD_12 = ((IDX_U32_ISM_PUSK_UROV_VID_DV  == 12)<< MSK_U32_ISM_PUSK_UROV_VID_DV ),

ISM_ZVN_NESPR_DZR_CMD_00 = ((IDX_U32_ISM_ZVN_NESPR_DZR ==  0)<< MSK_U32_ISM_ZVN_NESPR_DZR),
ISM_ZVN_NESPR_DZR_CMD_01 = ((IDX_U32_ISM_ZVN_NESPR_DZR ==  1)<< MSK_U32_ISM_ZVN_NESPR_DZR),
ISM_ZVN_NESPR_DZR_CMD_02 = ((IDX_U32_ISM_ZVN_NESPR_DZR ==  2)<< MSK_U32_ISM_ZVN_NESPR_DZR),
ISM_ZVN_NESPR_DZR_CMD_03 = ((IDX_U32_ISM_ZVN_NESPR_DZR ==  3)<< MSK_U32_ISM_ZVN_NESPR_DZR),
ISM_ZVN_NESPR_DZR_CMD_04 = ((IDX_U32_ISM_ZVN_NESPR_DZR ==  4)<< MSK_U32_ISM_ZVN_NESPR_DZR),
ISM_ZVN_NESPR_DZR_CMD_05 = ((IDX_U32_ISM_ZVN_NESPR_DZR ==  5)<< MSK_U32_ISM_ZVN_NESPR_DZR),
ISM_ZVN_NESPR_DZR_CMD_06 = ((IDX_U32_ISM_ZVN_NESPR_DZR ==  6)<< MSK_U32_ISM_ZVN_NESPR_DZR),
ISM_ZVN_NESPR_DZR_CMD_07 = ((IDX_U32_ISM_ZVN_NESPR_DZR ==  7)<< MSK_U32_ISM_ZVN_NESPR_DZR),
ISM_ZVN_NESPR_DZR_CMD_08 = ((IDX_U32_ISM_ZVN_NESPR_DZR ==  8)<< MSK_U32_ISM_ZVN_NESPR_DZR),
ISM_ZVN_NESPR_DZR_CMD_09 = ((IDX_U32_ISM_ZVN_NESPR_DZR ==  9)<< MSK_U32_ISM_ZVN_NESPR_DZR),
ISM_ZVN_NESPR_DZR_CMD_10 = ((IDX_U32_ISM_ZVN_NESPR_DZR == 10)<< MSK_U32_ISM_ZVN_NESPR_DZR),
ISM_ZVN_NESPR_DZR_CMD_11 = ((IDX_U32_ISM_ZVN_NESPR_DZR == 11)<< MSK_U32_ISM_ZVN_NESPR_DZR),
ISM_ZVN_NESPR_DZR_CMD_12 = ((IDX_U32_ISM_ZVN_NESPR_DZR == 12)<< MSK_U32_ISM_ZVN_NESPR_DZR),
                    
                    
ISM_ZBR_BLOCK_DZR1_I_R_3G_CMD_00 = ((IDX_U32_ISM_ZBR_BLOCK_DZR1_I_R_3G ==  0)<< MSK_U32_ISM_ZBR_BLOCK_DZR1_I_R_3G),
ISM_ZBR_BLOCK_DZR1_I_R_3G_CMD_01 = ((IDX_U32_ISM_ZBR_BLOCK_DZR1_I_R_3G ==  1)<< MSK_U32_ISM_ZBR_BLOCK_DZR1_I_R_3G),
ISM_ZBR_BLOCK_DZR1_I_R_3G_CMD_02 = ((IDX_U32_ISM_ZBR_BLOCK_DZR1_I_R_3G ==  2)<< MSK_U32_ISM_ZBR_BLOCK_DZR1_I_R_3G),
ISM_ZBR_BLOCK_DZR1_I_R_3G_CMD_03 = ((IDX_U32_ISM_ZBR_BLOCK_DZR1_I_R_3G ==  3)<< MSK_U32_ISM_ZBR_BLOCK_DZR1_I_R_3G),
ISM_ZBR_BLOCK_DZR1_I_R_3G_CMD_04 = ((IDX_U32_ISM_ZBR_BLOCK_DZR1_I_R_3G ==  4)<< MSK_U32_ISM_ZBR_BLOCK_DZR1_I_R_3G),
ISM_ZBR_BLOCK_DZR1_I_R_3G_CMD_05 = ((IDX_U32_ISM_ZBR_BLOCK_DZR1_I_R_3G ==  5)<< MSK_U32_ISM_ZBR_BLOCK_DZR1_I_R_3G),
ISM_ZBR_BLOCK_DZR1_I_R_3G_CMD_06 = ((IDX_U32_ISM_ZBR_BLOCK_DZR1_I_R_3G ==  6)<< MSK_U32_ISM_ZBR_BLOCK_DZR1_I_R_3G),
ISM_ZBR_BLOCK_DZR1_I_R_3G_CMD_07 = ((IDX_U32_ISM_ZBR_BLOCK_DZR1_I_R_3G ==  7)<< MSK_U32_ISM_ZBR_BLOCK_DZR1_I_R_3G),
ISM_ZBR_BLOCK_DZR1_I_R_3G_CMD_08 = ((IDX_U32_ISM_ZBR_BLOCK_DZR1_I_R_3G ==  8)<< MSK_U32_ISM_ZBR_BLOCK_DZR1_I_R_3G),
ISM_ZBR_BLOCK_DZR1_I_R_3G_CMD_09 = ((IDX_U32_ISM_ZBR_BLOCK_DZR1_I_R_3G ==  9)<< MSK_U32_ISM_ZBR_BLOCK_DZR1_I_R_3G),
ISM_ZBR_BLOCK_DZR1_I_R_3G_CMD_10 = ((IDX_U32_ISM_ZBR_BLOCK_DZR1_I_R_3G == 10)<< MSK_U32_ISM_ZBR_BLOCK_DZR1_I_R_3G),
ISM_ZBR_BLOCK_DZR1_I_R_3G_CMD_11 = ((IDX_U32_ISM_ZBR_BLOCK_DZR1_I_R_3G == 11)<< MSK_U32_ISM_ZBR_BLOCK_DZR1_I_R_3G),
ISM_ZBR_BLOCK_DZR1_I_R_3G_CMD_12 = ((IDX_U32_ISM_ZBR_BLOCK_DZR1_I_R_3G == 12)<< MSK_U32_ISM_ZBR_BLOCK_DZR1_I_R_3G),
                    
                    
ISM_ZBR_BLOCK_DZR1_I_R_CMD_00 = ((IDX_U32_ISM_ZBR_BLOCK_DZR1_I_R ==  0)<< MSK_U32_ISM_ZBR_BLOCK_DZR1_I_R),
ISM_ZBR_BLOCK_DZR1_I_R_CMD_01 = ((IDX_U32_ISM_ZBR_BLOCK_DZR1_I_R ==  1)<< MSK_U32_ISM_ZBR_BLOCK_DZR1_I_R),
ISM_ZBR_BLOCK_DZR1_I_R_CMD_02 = ((IDX_U32_ISM_ZBR_BLOCK_DZR1_I_R ==  2)<< MSK_U32_ISM_ZBR_BLOCK_DZR1_I_R),
ISM_ZBR_BLOCK_DZR1_I_R_CMD_03 = ((IDX_U32_ISM_ZBR_BLOCK_DZR1_I_R ==  3)<< MSK_U32_ISM_ZBR_BLOCK_DZR1_I_R),
ISM_ZBR_BLOCK_DZR1_I_R_CMD_04 = ((IDX_U32_ISM_ZBR_BLOCK_DZR1_I_R ==  4)<< MSK_U32_ISM_ZBR_BLOCK_DZR1_I_R),
ISM_ZBR_BLOCK_DZR1_I_R_CMD_05 = ((IDX_U32_ISM_ZBR_BLOCK_DZR1_I_R ==  5)<< MSK_U32_ISM_ZBR_BLOCK_DZR1_I_R),
ISM_ZBR_BLOCK_DZR1_I_R_CMD_06 = ((IDX_U32_ISM_ZBR_BLOCK_DZR1_I_R ==  6)<< MSK_U32_ISM_ZBR_BLOCK_DZR1_I_R),
ISM_ZBR_BLOCK_DZR1_I_R_CMD_07 = ((IDX_U32_ISM_ZBR_BLOCK_DZR1_I_R ==  7)<< MSK_U32_ISM_ZBR_BLOCK_DZR1_I_R),
ISM_ZBR_BLOCK_DZR1_I_R_CMD_08 = ((IDX_U32_ISM_ZBR_BLOCK_DZR1_I_R ==  8)<< MSK_U32_ISM_ZBR_BLOCK_DZR1_I_R),
ISM_ZBR_BLOCK_DZR1_I_R_CMD_09 = ((IDX_U32_ISM_ZBR_BLOCK_DZR1_I_R ==  9)<< MSK_U32_ISM_ZBR_BLOCK_DZR1_I_R),
ISM_ZBR_BLOCK_DZR1_I_R_CMD_10 = ((IDX_U32_ISM_ZBR_BLOCK_DZR1_I_R == 10)<< MSK_U32_ISM_ZBR_BLOCK_DZR1_I_R),
ISM_ZBR_BLOCK_DZR1_I_R_CMD_11 = ((IDX_U32_ISM_ZBR_BLOCK_DZR1_I_R == 11)<< MSK_U32_ISM_ZBR_BLOCK_DZR1_I_R),
ISM_ZBR_BLOCK_DZR1_I_R_CMD_12 = ((IDX_U32_ISM_ZBR_BLOCK_DZR1_I_R == 12)<< MSK_U32_ISM_ZBR_BLOCK_DZR1_I_R),
                    
                    
ISM_BLOCK_DZR1_CMD_00 = ((IDX_U32_ISM_BLOCK_DZR1 ==  0)<< MSK_U32_ISM_BLOCK_DZR1),
ISM_BLOCK_DZR1_CMD_01 = ((IDX_U32_ISM_BLOCK_DZR1 ==  1)<< MSK_U32_ISM_BLOCK_DZR1),
ISM_BLOCK_DZR1_CMD_02 = ((IDX_U32_ISM_BLOCK_DZR1 ==  2)<< MSK_U32_ISM_BLOCK_DZR1),
ISM_BLOCK_DZR1_CMD_03 = ((IDX_U32_ISM_BLOCK_DZR1 ==  3)<< MSK_U32_ISM_BLOCK_DZR1),
ISM_BLOCK_DZR1_CMD_04 = ((IDX_U32_ISM_BLOCK_DZR1 ==  4)<< MSK_U32_ISM_BLOCK_DZR1),
ISM_BLOCK_DZR1_CMD_05 = ((IDX_U32_ISM_BLOCK_DZR1 ==  5)<< MSK_U32_ISM_BLOCK_DZR1),
ISM_BLOCK_DZR1_CMD_06 = ((IDX_U32_ISM_BLOCK_DZR1 ==  6)<< MSK_U32_ISM_BLOCK_DZR1),
ISM_BLOCK_DZR1_CMD_07 = ((IDX_U32_ISM_BLOCK_DZR1 ==  7)<< MSK_U32_ISM_BLOCK_DZR1),
ISM_BLOCK_DZR1_CMD_08 = ((IDX_U32_ISM_BLOCK_DZR1 ==  8)<< MSK_U32_ISM_BLOCK_DZR1),
ISM_BLOCK_DZR1_CMD_09 = ((IDX_U32_ISM_BLOCK_DZR1 ==  9)<< MSK_U32_ISM_BLOCK_DZR1),
ISM_BLOCK_DZR1_CMD_10 = ((IDX_U32_ISM_BLOCK_DZR1 == 10)<< MSK_U32_ISM_BLOCK_DZR1),
ISM_BLOCK_DZR1_CMD_11 = ((IDX_U32_ISM_BLOCK_DZR1 == 11)<< MSK_U32_ISM_BLOCK_DZR1),
ISM_BLOCK_DZR1_CMD_12 = ((IDX_U32_ISM_BLOCK_DZR1 == 12)<< MSK_U32_ISM_BLOCK_DZR1),

ISM_BLOCK_PR_DZR2_CMD_00 = ((IDX_U32_ISM_BLOCK_PR_DZR2 ==  0)<< MSK_U32_ISM_BLOCK_PR_DZR2),
ISM_BLOCK_PR_DZR2_CMD_01 = ((IDX_U32_ISM_BLOCK_PR_DZR2 ==  1)<< MSK_U32_ISM_BLOCK_PR_DZR2),
ISM_BLOCK_PR_DZR2_CMD_02 = ((IDX_U32_ISM_BLOCK_PR_DZR2 ==  2)<< MSK_U32_ISM_BLOCK_PR_DZR2),
ISM_BLOCK_PR_DZR2_CMD_03 = ((IDX_U32_ISM_BLOCK_PR_DZR2 ==  3)<< MSK_U32_ISM_BLOCK_PR_DZR2),
ISM_BLOCK_PR_DZR2_CMD_04 = ((IDX_U32_ISM_BLOCK_PR_DZR2 ==  4)<< MSK_U32_ISM_BLOCK_PR_DZR2),
ISM_BLOCK_PR_DZR2_CMD_05 = ((IDX_U32_ISM_BLOCK_PR_DZR2 ==  5)<< MSK_U32_ISM_BLOCK_PR_DZR2),
ISM_BLOCK_PR_DZR2_CMD_06 = ((IDX_U32_ISM_BLOCK_PR_DZR2 ==  6)<< MSK_U32_ISM_BLOCK_PR_DZR2),
ISM_BLOCK_PR_DZR2_CMD_07 = ((IDX_U32_ISM_BLOCK_PR_DZR2 ==  7)<< MSK_U32_ISM_BLOCK_PR_DZR2),
ISM_BLOCK_PR_DZR2_CMD_08 = ((IDX_U32_ISM_BLOCK_PR_DZR2 ==  8)<< MSK_U32_ISM_BLOCK_PR_DZR2),
ISM_BLOCK_PR_DZR2_CMD_09 = ((IDX_U32_ISM_BLOCK_PR_DZR2 ==  9)<< MSK_U32_ISM_BLOCK_PR_DZR2),
ISM_BLOCK_PR_DZR2_CMD_10 = ((IDX_U32_ISM_BLOCK_PR_DZR2 == 10)<< MSK_U32_ISM_BLOCK_PR_DZR2),
ISM_BLOCK_PR_DZR2_CMD_11 = ((IDX_U32_ISM_BLOCK_PR_DZR2 == 11)<< MSK_U32_ISM_BLOCK_PR_DZR2),
ISM_BLOCK_PR_DZR2_CMD_12 = ((IDX_U32_ISM_BLOCK_PR_DZR2 == 12)<< MSK_U32_ISM_BLOCK_PR_DZR2),
                    
                    
ISM_OP_PR_DZR2_CMD_00 = ((IDX_U32_ISM_OP_PR_DZR2 ==  0)<< MSK_U32_ISM_OP_PR_DZR2),
ISM_OP_PR_DZR2_CMD_01 = ((IDX_U32_ISM_OP_PR_DZR2 ==  1)<< MSK_U32_ISM_OP_PR_DZR2),
ISM_OP_PR_DZR2_CMD_02 = ((IDX_U32_ISM_OP_PR_DZR2 ==  2)<< MSK_U32_ISM_OP_PR_DZR2),
ISM_OP_PR_DZR2_CMD_03 = ((IDX_U32_ISM_OP_PR_DZR2 ==  3)<< MSK_U32_ISM_OP_PR_DZR2),
ISM_OP_PR_DZR2_CMD_04 = ((IDX_U32_ISM_OP_PR_DZR2 ==  4)<< MSK_U32_ISM_OP_PR_DZR2),
ISM_OP_PR_DZR2_CMD_05 = ((IDX_U32_ISM_OP_PR_DZR2 ==  5)<< MSK_U32_ISM_OP_PR_DZR2),
ISM_OP_PR_DZR2_CMD_06 = ((IDX_U32_ISM_OP_PR_DZR2 ==  6)<< MSK_U32_ISM_OP_PR_DZR2),
ISM_OP_PR_DZR2_CMD_07 = ((IDX_U32_ISM_OP_PR_DZR2 ==  7)<< MSK_U32_ISM_OP_PR_DZR2),
ISM_OP_PR_DZR2_CMD_08 = ((IDX_U32_ISM_OP_PR_DZR2 ==  8)<< MSK_U32_ISM_OP_PR_DZR2),
ISM_OP_PR_DZR2_CMD_09 = ((IDX_U32_ISM_OP_PR_DZR2 ==  9)<< MSK_U32_ISM_OP_PR_DZR2),
ISM_OP_PR_DZR2_CMD_10 = ((IDX_U32_ISM_OP_PR_DZR2 == 10)<< MSK_U32_ISM_OP_PR_DZR2),
ISM_OP_PR_DZR2_CMD_11 = ((IDX_U32_ISM_OP_PR_DZR2 == 11)<< MSK_U32_ISM_OP_PR_DZR2),
ISM_OP_PR_DZR2_CMD_12 = ((IDX_U32_ISM_OP_PR_DZR2 == 12)<< MSK_U32_ISM_OP_PR_DZR2),
                    
                    
ISM_ZBR_BLOCK_DZR2_I_R_3G_CMD_00 = ((IDX_U32_ISM_ZBR_BLOCK_DZR2_I_R_3G ==  0)<< MSK_U32_ISM_ZBR_BLOCK_DZR2_I_R_3G),
ISM_ZBR_BLOCK_DZR2_I_R_3G_CMD_01 = ((IDX_U32_ISM_ZBR_BLOCK_DZR2_I_R_3G ==  1)<< MSK_U32_ISM_ZBR_BLOCK_DZR2_I_R_3G),
ISM_ZBR_BLOCK_DZR2_I_R_3G_CMD_02 = ((IDX_U32_ISM_ZBR_BLOCK_DZR2_I_R_3G ==  2)<< MSK_U32_ISM_ZBR_BLOCK_DZR2_I_R_3G),
ISM_ZBR_BLOCK_DZR2_I_R_3G_CMD_03 = ((IDX_U32_ISM_ZBR_BLOCK_DZR2_I_R_3G ==  3)<< MSK_U32_ISM_ZBR_BLOCK_DZR2_I_R_3G),
ISM_ZBR_BLOCK_DZR2_I_R_3G_CMD_04 = ((IDX_U32_ISM_ZBR_BLOCK_DZR2_I_R_3G ==  4)<< MSK_U32_ISM_ZBR_BLOCK_DZR2_I_R_3G),
ISM_ZBR_BLOCK_DZR2_I_R_3G_CMD_05 = ((IDX_U32_ISM_ZBR_BLOCK_DZR2_I_R_3G ==  5)<< MSK_U32_ISM_ZBR_BLOCK_DZR2_I_R_3G),
ISM_ZBR_BLOCK_DZR2_I_R_3G_CMD_06 = ((IDX_U32_ISM_ZBR_BLOCK_DZR2_I_R_3G ==  6)<< MSK_U32_ISM_ZBR_BLOCK_DZR2_I_R_3G),
ISM_ZBR_BLOCK_DZR2_I_R_3G_CMD_07 = ((IDX_U32_ISM_ZBR_BLOCK_DZR2_I_R_3G ==  7)<< MSK_U32_ISM_ZBR_BLOCK_DZR2_I_R_3G),
ISM_ZBR_BLOCK_DZR2_I_R_3G_CMD_08 = ((IDX_U32_ISM_ZBR_BLOCK_DZR2_I_R_3G ==  8)<< MSK_U32_ISM_ZBR_BLOCK_DZR2_I_R_3G),
ISM_ZBR_BLOCK_DZR2_I_R_3G_CMD_09 = ((IDX_U32_ISM_ZBR_BLOCK_DZR2_I_R_3G ==  9)<< MSK_U32_ISM_ZBR_BLOCK_DZR2_I_R_3G),
ISM_ZBR_BLOCK_DZR2_I_R_3G_CMD_10 = ((IDX_U32_ISM_ZBR_BLOCK_DZR2_I_R_3G == 10)<< MSK_U32_ISM_ZBR_BLOCK_DZR2_I_R_3G),
ISM_ZBR_BLOCK_DZR2_I_R_3G_CMD_11 = ((IDX_U32_ISM_ZBR_BLOCK_DZR2_I_R_3G == 11)<< MSK_U32_ISM_ZBR_BLOCK_DZR2_I_R_3G),
ISM_ZBR_BLOCK_DZR2_I_R_3G_CMD_12 = ((IDX_U32_ISM_ZBR_BLOCK_DZR2_I_R_3G == 12)<< MSK_U32_ISM_ZBR_BLOCK_DZR2_I_R_3G),
                    
                    
ISM_BLOCK_DZR2_CMD_00 = ((IDX_U32_ISM_BLOCK_DZR2 ==  0)<< MSK_U32_ISM_BLOCK_DZR2),
ISM_BLOCK_DZR2_CMD_01 = ((IDX_U32_ISM_BLOCK_DZR2 ==  1)<< MSK_U32_ISM_BLOCK_DZR2),
ISM_BLOCK_DZR2_CMD_02 = ((IDX_U32_ISM_BLOCK_DZR2 ==  2)<< MSK_U32_ISM_BLOCK_DZR2),
ISM_BLOCK_DZR2_CMD_03 = ((IDX_U32_ISM_BLOCK_DZR2 ==  3)<< MSK_U32_ISM_BLOCK_DZR2),
ISM_BLOCK_DZR2_CMD_04 = ((IDX_U32_ISM_BLOCK_DZR2 ==  4)<< MSK_U32_ISM_BLOCK_DZR2),
ISM_BLOCK_DZR2_CMD_05 = ((IDX_U32_ISM_BLOCK_DZR2 ==  5)<< MSK_U32_ISM_BLOCK_DZR2),
ISM_BLOCK_DZR2_CMD_06 = ((IDX_U32_ISM_BLOCK_DZR2 ==  6)<< MSK_U32_ISM_BLOCK_DZR2),
ISM_BLOCK_DZR2_CMD_07 = ((IDX_U32_ISM_BLOCK_DZR2 ==  7)<< MSK_U32_ISM_BLOCK_DZR2),
ISM_BLOCK_DZR2_CMD_08 = ((IDX_U32_ISM_BLOCK_DZR2 ==  8)<< MSK_U32_ISM_BLOCK_DZR2),
ISM_BLOCK_DZR2_CMD_09 = ((IDX_U32_ISM_BLOCK_DZR2 ==  9)<< MSK_U32_ISM_BLOCK_DZR2),
ISM_BLOCK_DZR2_CMD_10 = ((IDX_U32_ISM_BLOCK_DZR2 == 10)<< MSK_U32_ISM_BLOCK_DZR2),
ISM_BLOCK_DZR2_CMD_11 = ((IDX_U32_ISM_BLOCK_DZR2 == 11)<< MSK_U32_ISM_BLOCK_DZR2),
ISM_BLOCK_DZR2_CMD_12 = ((IDX_U32_ISM_BLOCK_DZR2 == 12)<< MSK_U32_ISM_BLOCK_DZR2),

ISM_BLOCK_PR_DZR3_CMD_00 = ((IDX_U32_ISM_BLOCK_PR_DZR3 ==  0)<< MSK_U32_ISM_BLOCK_PR_DZR3),
ISM_BLOCK_PR_DZR3_CMD_01 = ((IDX_U32_ISM_BLOCK_PR_DZR3 ==  1)<< MSK_U32_ISM_BLOCK_PR_DZR3),
ISM_BLOCK_PR_DZR3_CMD_02 = ((IDX_U32_ISM_BLOCK_PR_DZR3 ==  2)<< MSK_U32_ISM_BLOCK_PR_DZR3),
ISM_BLOCK_PR_DZR3_CMD_03 = ((IDX_U32_ISM_BLOCK_PR_DZR3 ==  3)<< MSK_U32_ISM_BLOCK_PR_DZR3),
ISM_BLOCK_PR_DZR3_CMD_04 = ((IDX_U32_ISM_BLOCK_PR_DZR3 ==  4)<< MSK_U32_ISM_BLOCK_PR_DZR3),
ISM_BLOCK_PR_DZR3_CMD_05 = ((IDX_U32_ISM_BLOCK_PR_DZR3 ==  5)<< MSK_U32_ISM_BLOCK_PR_DZR3),
ISM_BLOCK_PR_DZR3_CMD_06 = ((IDX_U32_ISM_BLOCK_PR_DZR3 ==  6)<< MSK_U32_ISM_BLOCK_PR_DZR3),
ISM_BLOCK_PR_DZR3_CMD_07 = ((IDX_U32_ISM_BLOCK_PR_DZR3 ==  7)<< MSK_U32_ISM_BLOCK_PR_DZR3),
ISM_BLOCK_PR_DZR3_CMD_08 = ((IDX_U32_ISM_BLOCK_PR_DZR3 ==  8)<< MSK_U32_ISM_BLOCK_PR_DZR3),
ISM_BLOCK_PR_DZR3_CMD_09 = ((IDX_U32_ISM_BLOCK_PR_DZR3 ==  9)<< MSK_U32_ISM_BLOCK_PR_DZR3),
ISM_BLOCK_PR_DZR3_CMD_10 = ((IDX_U32_ISM_BLOCK_PR_DZR3 == 10)<< MSK_U32_ISM_BLOCK_PR_DZR3),
ISM_BLOCK_PR_DZR3_CMD_11 = ((IDX_U32_ISM_BLOCK_PR_DZR3 == 11)<< MSK_U32_ISM_BLOCK_PR_DZR3),
ISM_BLOCK_PR_DZR3_CMD_12 = ((IDX_U32_ISM_BLOCK_PR_DZR3 == 12)<< MSK_U32_ISM_BLOCK_PR_DZR3),
                    
                    
ISM_OP_PR_DZR3_CMD_00 = ((IDX_U32_ISM_OP_PR_DZR3 ==  0)<< MSK_U32_ISM_OP_PR_DZR3),
ISM_OP_PR_DZR3_CMD_01 = ((IDX_U32_ISM_OP_PR_DZR3 ==  1)<< MSK_U32_ISM_OP_PR_DZR3),
ISM_OP_PR_DZR3_CMD_02 = ((IDX_U32_ISM_OP_PR_DZR3 ==  2)<< MSK_U32_ISM_OP_PR_DZR3),
ISM_OP_PR_DZR3_CMD_03 = ((IDX_U32_ISM_OP_PR_DZR3 ==  3)<< MSK_U32_ISM_OP_PR_DZR3),
ISM_OP_PR_DZR3_CMD_04 = ((IDX_U32_ISM_OP_PR_DZR3 ==  4)<< MSK_U32_ISM_OP_PR_DZR3),
ISM_OP_PR_DZR3_CMD_05 = ((IDX_U32_ISM_OP_PR_DZR3 ==  5)<< MSK_U32_ISM_OP_PR_DZR3),
ISM_OP_PR_DZR3_CMD_06 = ((IDX_U32_ISM_OP_PR_DZR3 ==  6)<< MSK_U32_ISM_OP_PR_DZR3),
ISM_OP_PR_DZR3_CMD_07 = ((IDX_U32_ISM_OP_PR_DZR3 ==  7)<< MSK_U32_ISM_OP_PR_DZR3),
ISM_OP_PR_DZR3_CMD_08 = ((IDX_U32_ISM_OP_PR_DZR3 ==  8)<< MSK_U32_ISM_OP_PR_DZR3),
ISM_OP_PR_DZR3_CMD_09 = ((IDX_U32_ISM_OP_PR_DZR3 ==  9)<< MSK_U32_ISM_OP_PR_DZR3),
ISM_OP_PR_DZR3_CMD_10 = ((IDX_U32_ISM_OP_PR_DZR3 == 10)<< MSK_U32_ISM_OP_PR_DZR3),
ISM_OP_PR_DZR3_CMD_11 = ((IDX_U32_ISM_OP_PR_DZR3 == 11)<< MSK_U32_ISM_OP_PR_DZR3),
ISM_OP_PR_DZR3_CMD_12 = ((IDX_U32_ISM_OP_PR_DZR3 == 12)<< MSK_U32_ISM_OP_PR_DZR3),
                    
                    
ISM_ZBR_BLOCK_DZR3_I_R_3G_CMD_00 = ((IDX_U32_ISM_ZBR_BLOCK_DZR3_I_R_3G ==  0)<< MSK_U32_ISM_ZBR_BLOCK_DZR3_I_R_3G),
ISM_ZBR_BLOCK_DZR3_I_R_3G_CMD_01 = ((IDX_U32_ISM_ZBR_BLOCK_DZR3_I_R_3G ==  1)<< MSK_U32_ISM_ZBR_BLOCK_DZR3_I_R_3G),
ISM_ZBR_BLOCK_DZR3_I_R_3G_CMD_02 = ((IDX_U32_ISM_ZBR_BLOCK_DZR3_I_R_3G ==  2)<< MSK_U32_ISM_ZBR_BLOCK_DZR3_I_R_3G),
ISM_ZBR_BLOCK_DZR3_I_R_3G_CMD_03 = ((IDX_U32_ISM_ZBR_BLOCK_DZR3_I_R_3G ==  3)<< MSK_U32_ISM_ZBR_BLOCK_DZR3_I_R_3G),
ISM_ZBR_BLOCK_DZR3_I_R_3G_CMD_04 = ((IDX_U32_ISM_ZBR_BLOCK_DZR3_I_R_3G ==  4)<< MSK_U32_ISM_ZBR_BLOCK_DZR3_I_R_3G),
ISM_ZBR_BLOCK_DZR3_I_R_3G_CMD_05 = ((IDX_U32_ISM_ZBR_BLOCK_DZR3_I_R_3G ==  5)<< MSK_U32_ISM_ZBR_BLOCK_DZR3_I_R_3G),
ISM_ZBR_BLOCK_DZR3_I_R_3G_CMD_06 = ((IDX_U32_ISM_ZBR_BLOCK_DZR3_I_R_3G ==  6)<< MSK_U32_ISM_ZBR_BLOCK_DZR3_I_R_3G),
ISM_ZBR_BLOCK_DZR3_I_R_3G_CMD_07 = ((IDX_U32_ISM_ZBR_BLOCK_DZR3_I_R_3G ==  7)<< MSK_U32_ISM_ZBR_BLOCK_DZR3_I_R_3G),
ISM_ZBR_BLOCK_DZR3_I_R_3G_CMD_08 = ((IDX_U32_ISM_ZBR_BLOCK_DZR3_I_R_3G ==  8)<< MSK_U32_ISM_ZBR_BLOCK_DZR3_I_R_3G),
ISM_ZBR_BLOCK_DZR3_I_R_3G_CMD_09 = ((IDX_U32_ISM_ZBR_BLOCK_DZR3_I_R_3G ==  9)<< MSK_U32_ISM_ZBR_BLOCK_DZR3_I_R_3G),
ISM_ZBR_BLOCK_DZR3_I_R_3G_CMD_10 = ((IDX_U32_ISM_ZBR_BLOCK_DZR3_I_R_3G == 10)<< MSK_U32_ISM_ZBR_BLOCK_DZR3_I_R_3G),
ISM_ZBR_BLOCK_DZR3_I_R_3G_CMD_11 = ((IDX_U32_ISM_ZBR_BLOCK_DZR3_I_R_3G == 11)<< MSK_U32_ISM_ZBR_BLOCK_DZR3_I_R_3G),
ISM_ZBR_BLOCK_DZR3_I_R_3G_CMD_12 = ((IDX_U32_ISM_ZBR_BLOCK_DZR3_I_R_3G == 12)<< MSK_U32_ISM_ZBR_BLOCK_DZR3_I_R_3G),
                    
                    
ISM_BLOCK_DZR3_CMD_00 = ((IDX_U32_ISM_BLOCK_DZR3 ==  0)<< MSK_U32_ISM_BLOCK_DZR3),
ISM_BLOCK_DZR3_CMD_01 = ((IDX_U32_ISM_BLOCK_DZR3 ==  1)<< MSK_U32_ISM_BLOCK_DZR3),
ISM_BLOCK_DZR3_CMD_02 = ((IDX_U32_ISM_BLOCK_DZR3 ==  2)<< MSK_U32_ISM_BLOCK_DZR3),
ISM_BLOCK_DZR3_CMD_03 = ((IDX_U32_ISM_BLOCK_DZR3 ==  3)<< MSK_U32_ISM_BLOCK_DZR3),
ISM_BLOCK_DZR3_CMD_04 = ((IDX_U32_ISM_BLOCK_DZR3 ==  4)<< MSK_U32_ISM_BLOCK_DZR3),
ISM_BLOCK_DZR3_CMD_05 = ((IDX_U32_ISM_BLOCK_DZR3 ==  5)<< MSK_U32_ISM_BLOCK_DZR3),
ISM_BLOCK_DZR3_CMD_06 = ((IDX_U32_ISM_BLOCK_DZR3 ==  6)<< MSK_U32_ISM_BLOCK_DZR3),
ISM_BLOCK_DZR3_CMD_07 = ((IDX_U32_ISM_BLOCK_DZR3 ==  7)<< MSK_U32_ISM_BLOCK_DZR3),
ISM_BLOCK_DZR3_CMD_08 = ((IDX_U32_ISM_BLOCK_DZR3 ==  8)<< MSK_U32_ISM_BLOCK_DZR3),
ISM_BLOCK_DZR3_CMD_09 = ((IDX_U32_ISM_BLOCK_DZR3 ==  9)<< MSK_U32_ISM_BLOCK_DZR3),
ISM_BLOCK_DZR3_CMD_10 = ((IDX_U32_ISM_BLOCK_DZR3 == 10)<< MSK_U32_ISM_BLOCK_DZR3),
ISM_BLOCK_DZR3_CMD_11 = ((IDX_U32_ISM_BLOCK_DZR3 == 11)<< MSK_U32_ISM_BLOCK_DZR3),
ISM_BLOCK_DZR3_CMD_12 = ((IDX_U32_ISM_BLOCK_DZR3 == 12)<< MSK_U32_ISM_BLOCK_DZR3),

ISM_BLOCK_UMIN1_CMD_00 = ((IDX_U32_ISM_BLOCK_UMIN1 ==  0)<< MSK_U32_ISM_BLOCK_UMIN1),
ISM_BLOCK_UMIN1_CMD_01 = ((IDX_U32_ISM_BLOCK_UMIN1 ==  1)<< MSK_U32_ISM_BLOCK_UMIN1),
ISM_BLOCK_UMIN1_CMD_02 = ((IDX_U32_ISM_BLOCK_UMIN1 ==  2)<< MSK_U32_ISM_BLOCK_UMIN1),
ISM_BLOCK_UMIN1_CMD_03 = ((IDX_U32_ISM_BLOCK_UMIN1 ==  3)<< MSK_U32_ISM_BLOCK_UMIN1),
ISM_BLOCK_UMIN1_CMD_04 = ((IDX_U32_ISM_BLOCK_UMIN1 ==  4)<< MSK_U32_ISM_BLOCK_UMIN1),
ISM_BLOCK_UMIN1_CMD_05 = ((IDX_U32_ISM_BLOCK_UMIN1 ==  5)<< MSK_U32_ISM_BLOCK_UMIN1),
ISM_BLOCK_UMIN1_CMD_06 = ((IDX_U32_ISM_BLOCK_UMIN1 ==  6)<< MSK_U32_ISM_BLOCK_UMIN1),
ISM_BLOCK_UMIN1_CMD_07 = ((IDX_U32_ISM_BLOCK_UMIN1 ==  7)<< MSK_U32_ISM_BLOCK_UMIN1),
ISM_BLOCK_UMIN1_CMD_08 = ((IDX_U32_ISM_BLOCK_UMIN1 ==  8)<< MSK_U32_ISM_BLOCK_UMIN1),
ISM_BLOCK_UMIN1_CMD_09 = ((IDX_U32_ISM_BLOCK_UMIN1 ==  9)<< MSK_U32_ISM_BLOCK_UMIN1),
ISM_BLOCK_UMIN1_CMD_10 = ((IDX_U32_ISM_BLOCK_UMIN1 == 10)<< MSK_U32_ISM_BLOCK_UMIN1),
ISM_BLOCK_UMIN1_CMD_11 = ((IDX_U32_ISM_BLOCK_UMIN1 == 11)<< MSK_U32_ISM_BLOCK_UMIN1),
ISM_BLOCK_UMIN1_CMD_12 = ((IDX_U32_ISM_BLOCK_UMIN1 == 12)<< MSK_U32_ISM_BLOCK_UMIN1),
                    
                    
ISM_START_UMIN1_CMD_00 = ((IDX_U32_ISM_START_UMIN1 ==  0)<< MSK_U32_ISM_START_UMIN1),
ISM_START_UMIN1_CMD_01 = ((IDX_U32_ISM_START_UMIN1 ==  1)<< MSK_U32_ISM_START_UMIN1),
ISM_START_UMIN1_CMD_02 = ((IDX_U32_ISM_START_UMIN1 ==  2)<< MSK_U32_ISM_START_UMIN1),
ISM_START_UMIN1_CMD_03 = ((IDX_U32_ISM_START_UMIN1 ==  3)<< MSK_U32_ISM_START_UMIN1),
ISM_START_UMIN1_CMD_04 = ((IDX_U32_ISM_START_UMIN1 ==  4)<< MSK_U32_ISM_START_UMIN1),
ISM_START_UMIN1_CMD_05 = ((IDX_U32_ISM_START_UMIN1 ==  5)<< MSK_U32_ISM_START_UMIN1),
ISM_START_UMIN1_CMD_06 = ((IDX_U32_ISM_START_UMIN1 ==  6)<< MSK_U32_ISM_START_UMIN1),
ISM_START_UMIN1_CMD_07 = ((IDX_U32_ISM_START_UMIN1 ==  7)<< MSK_U32_ISM_START_UMIN1),
ISM_START_UMIN1_CMD_08 = ((IDX_U32_ISM_START_UMIN1 ==  8)<< MSK_U32_ISM_START_UMIN1),
ISM_START_UMIN1_CMD_09 = ((IDX_U32_ISM_START_UMIN1 ==  9)<< MSK_U32_ISM_START_UMIN1),
ISM_START_UMIN1_CMD_10 = ((IDX_U32_ISM_START_UMIN1 == 10)<< MSK_U32_ISM_START_UMIN1),
ISM_START_UMIN1_CMD_11 = ((IDX_U32_ISM_START_UMIN1 == 11)<< MSK_U32_ISM_START_UMIN1),
ISM_START_UMIN1_CMD_12 = ((IDX_U32_ISM_START_UMIN1 == 12)<< MSK_U32_ISM_START_UMIN1),
                    
                    
ISM_BLOCK_UMIN2_CMD_00 = ((IDX_U32_ISM_BLOCK_UMIN2 ==  0)<< MSK_U32_ISM_BLOCK_UMIN2),
ISM_BLOCK_UMIN2_CMD_01 = ((IDX_U32_ISM_BLOCK_UMIN2 ==  1)<< MSK_U32_ISM_BLOCK_UMIN2),
ISM_BLOCK_UMIN2_CMD_02 = ((IDX_U32_ISM_BLOCK_UMIN2 ==  2)<< MSK_U32_ISM_BLOCK_UMIN2),
ISM_BLOCK_UMIN2_CMD_03 = ((IDX_U32_ISM_BLOCK_UMIN2 ==  3)<< MSK_U32_ISM_BLOCK_UMIN2),
ISM_BLOCK_UMIN2_CMD_04 = ((IDX_U32_ISM_BLOCK_UMIN2 ==  4)<< MSK_U32_ISM_BLOCK_UMIN2),
ISM_BLOCK_UMIN2_CMD_05 = ((IDX_U32_ISM_BLOCK_UMIN2 ==  5)<< MSK_U32_ISM_BLOCK_UMIN2),
ISM_BLOCK_UMIN2_CMD_06 = ((IDX_U32_ISM_BLOCK_UMIN2 ==  6)<< MSK_U32_ISM_BLOCK_UMIN2),
ISM_BLOCK_UMIN2_CMD_07 = ((IDX_U32_ISM_BLOCK_UMIN2 ==  7)<< MSK_U32_ISM_BLOCK_UMIN2),
ISM_BLOCK_UMIN2_CMD_08 = ((IDX_U32_ISM_BLOCK_UMIN2 ==  8)<< MSK_U32_ISM_BLOCK_UMIN2),
ISM_BLOCK_UMIN2_CMD_09 = ((IDX_U32_ISM_BLOCK_UMIN2 ==  9)<< MSK_U32_ISM_BLOCK_UMIN2),
ISM_BLOCK_UMIN2_CMD_10 = ((IDX_U32_ISM_BLOCK_UMIN2 == 10)<< MSK_U32_ISM_BLOCK_UMIN2),
ISM_BLOCK_UMIN2_CMD_11 = ((IDX_U32_ISM_BLOCK_UMIN2 == 11)<< MSK_U32_ISM_BLOCK_UMIN2),
ISM_BLOCK_UMIN2_CMD_12 = ((IDX_U32_ISM_BLOCK_UMIN2 == 12)<< MSK_U32_ISM_BLOCK_UMIN2),
                    
                    
ISM_START_UMIN2_CMD_00 = ((IDX_U32_ISM_START_UMIN2 ==  0)<< MSK_U32_ISM_START_UMIN2),
ISM_START_UMIN2_CMD_01 = ((IDX_U32_ISM_START_UMIN2 ==  1)<< MSK_U32_ISM_START_UMIN2),
ISM_START_UMIN2_CMD_02 = ((IDX_U32_ISM_START_UMIN2 ==  2)<< MSK_U32_ISM_START_UMIN2),
ISM_START_UMIN2_CMD_03 = ((IDX_U32_ISM_START_UMIN2 ==  3)<< MSK_U32_ISM_START_UMIN2),
ISM_START_UMIN2_CMD_04 = ((IDX_U32_ISM_START_UMIN2 ==  4)<< MSK_U32_ISM_START_UMIN2),
ISM_START_UMIN2_CMD_05 = ((IDX_U32_ISM_START_UMIN2 ==  5)<< MSK_U32_ISM_START_UMIN2),
ISM_START_UMIN2_CMD_06 = ((IDX_U32_ISM_START_UMIN2 ==  6)<< MSK_U32_ISM_START_UMIN2),
ISM_START_UMIN2_CMD_07 = ((IDX_U32_ISM_START_UMIN2 ==  7)<< MSK_U32_ISM_START_UMIN2),
ISM_START_UMIN2_CMD_08 = ((IDX_U32_ISM_START_UMIN2 ==  8)<< MSK_U32_ISM_START_UMIN2),
ISM_START_UMIN2_CMD_09 = ((IDX_U32_ISM_START_UMIN2 ==  9)<< MSK_U32_ISM_START_UMIN2),
ISM_START_UMIN2_CMD_10 = ((IDX_U32_ISM_START_UMIN2 == 10)<< MSK_U32_ISM_START_UMIN2),
ISM_START_UMIN2_CMD_11 = ((IDX_U32_ISM_START_UMIN2 == 11)<< MSK_U32_ISM_START_UMIN2),
ISM_START_UMIN2_CMD_12 = ((IDX_U32_ISM_START_UMIN2 == 12)<< MSK_U32_ISM_START_UMIN2),

ISM_BLOCK_UMAX1_CMD_00 = ((IDX_U32_ISM_BLOCK_UMAX1 ==  0)<< MSK_U32_ISM_BLOCK_UMAX1),
ISM_BLOCK_UMAX1_CMD_01 = ((IDX_U32_ISM_BLOCK_UMAX1 ==  1)<< MSK_U32_ISM_BLOCK_UMAX1),
ISM_BLOCK_UMAX1_CMD_02 = ((IDX_U32_ISM_BLOCK_UMAX1 ==  2)<< MSK_U32_ISM_BLOCK_UMAX1),
ISM_BLOCK_UMAX1_CMD_03 = ((IDX_U32_ISM_BLOCK_UMAX1 ==  3)<< MSK_U32_ISM_BLOCK_UMAX1),
ISM_BLOCK_UMAX1_CMD_04 = ((IDX_U32_ISM_BLOCK_UMAX1 ==  4)<< MSK_U32_ISM_BLOCK_UMAX1),
ISM_BLOCK_UMAX1_CMD_05 = ((IDX_U32_ISM_BLOCK_UMAX1 ==  5)<< MSK_U32_ISM_BLOCK_UMAX1),
ISM_BLOCK_UMAX1_CMD_06 = ((IDX_U32_ISM_BLOCK_UMAX1 ==  6)<< MSK_U32_ISM_BLOCK_UMAX1),
ISM_BLOCK_UMAX1_CMD_07 = ((IDX_U32_ISM_BLOCK_UMAX1 ==  7)<< MSK_U32_ISM_BLOCK_UMAX1),
ISM_BLOCK_UMAX1_CMD_08 = ((IDX_U32_ISM_BLOCK_UMAX1 ==  8)<< MSK_U32_ISM_BLOCK_UMAX1),
ISM_BLOCK_UMAX1_CMD_09 = ((IDX_U32_ISM_BLOCK_UMAX1 ==  9)<< MSK_U32_ISM_BLOCK_UMAX1),
ISM_BLOCK_UMAX1_CMD_10 = ((IDX_U32_ISM_BLOCK_UMAX1 == 10)<< MSK_U32_ISM_BLOCK_UMAX1),
ISM_BLOCK_UMAX1_CMD_11 = ((IDX_U32_ISM_BLOCK_UMAX1 == 11)<< MSK_U32_ISM_BLOCK_UMAX1),
ISM_BLOCK_UMAX1_CMD_12 = ((IDX_U32_ISM_BLOCK_UMAX1 == 12)<< MSK_U32_ISM_BLOCK_UMAX1),
                    
                    
ISM_BLOCK_UMAX2_CMD_00 = ((IDX_U32_ISM_BLOCK_UMAX2 ==  0)<< MSK_U32_ISM_BLOCK_UMAX2),
ISM_BLOCK_UMAX2_CMD_01 = ((IDX_U32_ISM_BLOCK_UMAX2 ==  1)<< MSK_U32_ISM_BLOCK_UMAX2),
ISM_BLOCK_UMAX2_CMD_02 = ((IDX_U32_ISM_BLOCK_UMAX2 ==  2)<< MSK_U32_ISM_BLOCK_UMAX2),
ISM_BLOCK_UMAX2_CMD_03 = ((IDX_U32_ISM_BLOCK_UMAX2 ==  3)<< MSK_U32_ISM_BLOCK_UMAX2),
ISM_BLOCK_UMAX2_CMD_04 = ((IDX_U32_ISM_BLOCK_UMAX2 ==  4)<< MSK_U32_ISM_BLOCK_UMAX2),
ISM_BLOCK_UMAX2_CMD_05 = ((IDX_U32_ISM_BLOCK_UMAX2 ==  5)<< MSK_U32_ISM_BLOCK_UMAX2),
ISM_BLOCK_UMAX2_CMD_06 = ((IDX_U32_ISM_BLOCK_UMAX2 ==  6)<< MSK_U32_ISM_BLOCK_UMAX2),
ISM_BLOCK_UMAX2_CMD_07 = ((IDX_U32_ISM_BLOCK_UMAX2 ==  7)<< MSK_U32_ISM_BLOCK_UMAX2),
ISM_BLOCK_UMAX2_CMD_08 = ((IDX_U32_ISM_BLOCK_UMAX2 ==  8)<< MSK_U32_ISM_BLOCK_UMAX2),
ISM_BLOCK_UMAX2_CMD_09 = ((IDX_U32_ISM_BLOCK_UMAX2 ==  9)<< MSK_U32_ISM_BLOCK_UMAX2),
ISM_BLOCK_UMAX2_CMD_10 = ((IDX_U32_ISM_BLOCK_UMAX2 == 10)<< MSK_U32_ISM_BLOCK_UMAX2),
ISM_BLOCK_UMAX2_CMD_11 = ((IDX_U32_ISM_BLOCK_UMAX2 == 11)<< MSK_U32_ISM_BLOCK_UMAX2),
ISM_BLOCK_UMAX2_CMD_12 = ((IDX_U32_ISM_BLOCK_UMAX2 == 12)<< MSK_U32_ISM_BLOCK_UMAX2),
                    
                    
ISM_BLOCK_UP1_CMD_00 = ((IDX_U32_ISM_BLOCK_UP1  ==  0)<< MSK_U32_ISM_BLOCK_UP1  ),
ISM_BLOCK_UP1_CMD_01 = ((IDX_U32_ISM_BLOCK_UP1  ==  1)<< MSK_U32_ISM_BLOCK_UP1  ),
ISM_BLOCK_UP1_CMD_02 = ((IDX_U32_ISM_BLOCK_UP1  ==  2)<< MSK_U32_ISM_BLOCK_UP1  ),
ISM_BLOCK_UP1_CMD_03 = ((IDX_U32_ISM_BLOCK_UP1  ==  3)<< MSK_U32_ISM_BLOCK_UP1  ),
ISM_BLOCK_UP1_CMD_04 = ((IDX_U32_ISM_BLOCK_UP1  ==  4)<< MSK_U32_ISM_BLOCK_UP1  ),
ISM_BLOCK_UP1_CMD_05 = ((IDX_U32_ISM_BLOCK_UP1  ==  5)<< MSK_U32_ISM_BLOCK_UP1  ),
ISM_BLOCK_UP1_CMD_06 = ((IDX_U32_ISM_BLOCK_UP1  ==  6)<< MSK_U32_ISM_BLOCK_UP1  ),
ISM_BLOCK_UP1_CMD_07 = ((IDX_U32_ISM_BLOCK_UP1  ==  7)<< MSK_U32_ISM_BLOCK_UP1  ),
ISM_BLOCK_UP1_CMD_08 = ((IDX_U32_ISM_BLOCK_UP1  ==  8)<< MSK_U32_ISM_BLOCK_UP1  ),
ISM_BLOCK_UP1_CMD_09 = ((IDX_U32_ISM_BLOCK_UP1  ==  9)<< MSK_U32_ISM_BLOCK_UP1  ),
ISM_BLOCK_UP1_CMD_10 = ((IDX_U32_ISM_BLOCK_UP1  == 10)<< MSK_U32_ISM_BLOCK_UP1  ),
ISM_BLOCK_UP1_CMD_11 = ((IDX_U32_ISM_BLOCK_UP1  == 11)<< MSK_U32_ISM_BLOCK_UP1  ),
ISM_BLOCK_UP1_CMD_12 = ((IDX_U32_ISM_BLOCK_UP1  == 12)<< MSK_U32_ISM_BLOCK_UP1  ),
                    
                    
ISM_BLOCK_UP2_CMD_00 = ((IDX_U32_ISM_BLOCK_UP2   ==  0)<< MSK_U32_ISM_BLOCK_UP2  ),
ISM_BLOCK_UP2_CMD_01 = ((IDX_U32_ISM_BLOCK_UP2   ==  1)<< MSK_U32_ISM_BLOCK_UP2  ),
ISM_BLOCK_UP2_CMD_02 = ((IDX_U32_ISM_BLOCK_UP2   ==  2)<< MSK_U32_ISM_BLOCK_UP2  ),
ISM_BLOCK_UP2_CMD_03 = ((IDX_U32_ISM_BLOCK_UP2   ==  3)<< MSK_U32_ISM_BLOCK_UP2  ),
ISM_BLOCK_UP2_CMD_04 = ((IDX_U32_ISM_BLOCK_UP2   ==  4)<< MSK_U32_ISM_BLOCK_UP2  ),
ISM_BLOCK_UP2_CMD_05 = ((IDX_U32_ISM_BLOCK_UP2   ==  5)<< MSK_U32_ISM_BLOCK_UP2  ),
ISM_BLOCK_UP2_CMD_06 = ((IDX_U32_ISM_BLOCK_UP2   ==  6)<< MSK_U32_ISM_BLOCK_UP2  ),
ISM_BLOCK_UP2_CMD_07 = ((IDX_U32_ISM_BLOCK_UP2   ==  7)<< MSK_U32_ISM_BLOCK_UP2  ),
ISM_BLOCK_UP2_CMD_08 = ((IDX_U32_ISM_BLOCK_UP2   ==  8)<< MSK_U32_ISM_BLOCK_UP2  ),
ISM_BLOCK_UP2_CMD_09 = ((IDX_U32_ISM_BLOCK_UP2   ==  9)<< MSK_U32_ISM_BLOCK_UP2  ),
ISM_BLOCK_UP2_CMD_10 = ((IDX_U32_ISM_BLOCK_UP2   == 10)<< MSK_U32_ISM_BLOCK_UP2  ),
ISM_BLOCK_UP2_CMD_11 = ((IDX_U32_ISM_BLOCK_UP2   == 11)<< MSK_U32_ISM_BLOCK_UP2  ),
ISM_BLOCK_UP2_CMD_12 = ((IDX_U32_ISM_BLOCK_UP2   == 12)<< MSK_U32_ISM_BLOCK_UP2  ),

ISM_BLOCK_UP3_CMD_00 = ((IDX_U32_ISM_BLOCK_UP3 ==  0)<< MSK_U32_ISM_BLOCK_UP3),
ISM_BLOCK_UP3_CMD_01 = ((IDX_U32_ISM_BLOCK_UP3 ==  1)<< MSK_U32_ISM_BLOCK_UP3),
ISM_BLOCK_UP3_CMD_02 = ((IDX_U32_ISM_BLOCK_UP3 ==  2)<< MSK_U32_ISM_BLOCK_UP3),
ISM_BLOCK_UP3_CMD_03 = ((IDX_U32_ISM_BLOCK_UP3 ==  3)<< MSK_U32_ISM_BLOCK_UP3),
ISM_BLOCK_UP3_CMD_04 = ((IDX_U32_ISM_BLOCK_UP3 ==  4)<< MSK_U32_ISM_BLOCK_UP3),
ISM_BLOCK_UP3_CMD_05 = ((IDX_U32_ISM_BLOCK_UP3 ==  5)<< MSK_U32_ISM_BLOCK_UP3),
ISM_BLOCK_UP3_CMD_06 = ((IDX_U32_ISM_BLOCK_UP3 ==  6)<< MSK_U32_ISM_BLOCK_UP3),
ISM_BLOCK_UP3_CMD_07 = ((IDX_U32_ISM_BLOCK_UP3 ==  7)<< MSK_U32_ISM_BLOCK_UP3),
ISM_BLOCK_UP3_CMD_08 = ((IDX_U32_ISM_BLOCK_UP3 ==  8)<< MSK_U32_ISM_BLOCK_UP3),
ISM_BLOCK_UP3_CMD_09 = ((IDX_U32_ISM_BLOCK_UP3 ==  9)<< MSK_U32_ISM_BLOCK_UP3),
ISM_BLOCK_UP3_CMD_10 = ((IDX_U32_ISM_BLOCK_UP3 == 10)<< MSK_U32_ISM_BLOCK_UP3),
ISM_BLOCK_UP3_CMD_11 = ((IDX_U32_ISM_BLOCK_UP3 == 11)<< MSK_U32_ISM_BLOCK_UP3),
ISM_BLOCK_UP3_CMD_12 = ((IDX_U32_ISM_BLOCK_UP3 == 12)<< MSK_U32_ISM_BLOCK_UP3),
                    
                    
ISM_BLOCK_UP4_CMD_00 = ((IDX_U32_ISM_BLOCK_UP4 ==  0)<< MSK_U32_ISM_BLOCK_UP4),
ISM_BLOCK_UP4_CMD_01 = ((IDX_U32_ISM_BLOCK_UP4 ==  1)<< MSK_U32_ISM_BLOCK_UP4),
ISM_BLOCK_UP4_CMD_02 = ((IDX_U32_ISM_BLOCK_UP4 ==  2)<< MSK_U32_ISM_BLOCK_UP4),
ISM_BLOCK_UP4_CMD_03 = ((IDX_U32_ISM_BLOCK_UP4 ==  3)<< MSK_U32_ISM_BLOCK_UP4),
ISM_BLOCK_UP4_CMD_04 = ((IDX_U32_ISM_BLOCK_UP4 ==  4)<< MSK_U32_ISM_BLOCK_UP4),
ISM_BLOCK_UP4_CMD_05 = ((IDX_U32_ISM_BLOCK_UP4 ==  5)<< MSK_U32_ISM_BLOCK_UP4),
ISM_BLOCK_UP4_CMD_06 = ((IDX_U32_ISM_BLOCK_UP4 ==  6)<< MSK_U32_ISM_BLOCK_UP4),
ISM_BLOCK_UP4_CMD_07 = ((IDX_U32_ISM_BLOCK_UP4 ==  7)<< MSK_U32_ISM_BLOCK_UP4),
ISM_BLOCK_UP4_CMD_08 = ((IDX_U32_ISM_BLOCK_UP4 ==  8)<< MSK_U32_ISM_BLOCK_UP4),
ISM_BLOCK_UP4_CMD_09 = ((IDX_U32_ISM_BLOCK_UP4 ==  9)<< MSK_U32_ISM_BLOCK_UP4),
ISM_BLOCK_UP4_CMD_10 = ((IDX_U32_ISM_BLOCK_UP4 == 10)<< MSK_U32_ISM_BLOCK_UP4),
ISM_BLOCK_UP4_CMD_11 = ((IDX_U32_ISM_BLOCK_UP4 == 11)<< MSK_U32_ISM_BLOCK_UP4),
                    
                    
ISM_BLOCK_UP5_CMD_00 = ((IDX_U32_ISM_BLOCK_UP5 ==  0)<< MSK_U32_ISM_BLOCK_UP5),
ISM_BLOCK_UP5_CMD_01 = ((IDX_U32_ISM_BLOCK_UP5 ==  1)<< MSK_U32_ISM_BLOCK_UP5),
ISM_BLOCK_UP5_CMD_02 = ((IDX_U32_ISM_BLOCK_UP5 ==  2)<< MSK_U32_ISM_BLOCK_UP5),
ISM_BLOCK_UP5_CMD_03 = ((IDX_U32_ISM_BLOCK_UP5 ==  3)<< MSK_U32_ISM_BLOCK_UP5),
ISM_BLOCK_UP5_CMD_04 = ((IDX_U32_ISM_BLOCK_UP5 ==  4)<< MSK_U32_ISM_BLOCK_UP5),
ISM_BLOCK_UP5_CMD_05 = ((IDX_U32_ISM_BLOCK_UP5 ==  5)<< MSK_U32_ISM_BLOCK_UP5),
ISM_BLOCK_UP5_CMD_06 = ((IDX_U32_ISM_BLOCK_UP5 ==  6)<< MSK_U32_ISM_BLOCK_UP5),
ISM_BLOCK_UP5_CMD_07 = ((IDX_U32_ISM_BLOCK_UP5 ==  7)<< MSK_U32_ISM_BLOCK_UP5),
ISM_BLOCK_UP5_CMD_08 = ((IDX_U32_ISM_BLOCK_UP5 ==  8)<< MSK_U32_ISM_BLOCK_UP5),
ISM_BLOCK_UP5_CMD_09 = ((IDX_U32_ISM_BLOCK_UP5 ==  9)<< MSK_U32_ISM_BLOCK_UP5),
ISM_BLOCK_UP5_CMD_10 = ((IDX_U32_ISM_BLOCK_UP5 == 10)<< MSK_U32_ISM_BLOCK_UP5),
ISM_BLOCK_UP5_CMD_11 = ((IDX_U32_ISM_BLOCK_UP5 == 11)<< MSK_U32_ISM_BLOCK_UP5),
                    
                    
ISM_BLOCK_UP6_CMD_00 = ((IDX_U32_ISM_BLOCK_UP6 ==  0)<< MSK_U32_ISM_BLOCK_UP6),
ISM_BLOCK_UP6_CMD_01 = ((IDX_U32_ISM_BLOCK_UP6 ==  1)<< MSK_U32_ISM_BLOCK_UP6),
ISM_BLOCK_UP6_CMD_02 = ((IDX_U32_ISM_BLOCK_UP6 ==  2)<< MSK_U32_ISM_BLOCK_UP6),
ISM_BLOCK_UP6_CMD_03 = ((IDX_U32_ISM_BLOCK_UP6 ==  3)<< MSK_U32_ISM_BLOCK_UP6),
ISM_BLOCK_UP6_CMD_04 = ((IDX_U32_ISM_BLOCK_UP6 ==  4)<< MSK_U32_ISM_BLOCK_UP6),
ISM_BLOCK_UP6_CMD_05 = ((IDX_U32_ISM_BLOCK_UP6 ==  5)<< MSK_U32_ISM_BLOCK_UP6),
ISM_BLOCK_UP6_CMD_06 = ((IDX_U32_ISM_BLOCK_UP6 ==  6)<< MSK_U32_ISM_BLOCK_UP6),
ISM_BLOCK_UP6_CMD_07 = ((IDX_U32_ISM_BLOCK_UP6 ==  7)<< MSK_U32_ISM_BLOCK_UP6),
ISM_BLOCK_UP6_CMD_08 = ((IDX_U32_ISM_BLOCK_UP6 ==  8)<< MSK_U32_ISM_BLOCK_UP6),
ISM_BLOCK_UP6_CMD_09 = ((IDX_U32_ISM_BLOCK_UP6 ==  9)<< MSK_U32_ISM_BLOCK_UP6),
ISM_BLOCK_UP6_CMD_10 = ((IDX_U32_ISM_BLOCK_UP6 == 10)<< MSK_U32_ISM_BLOCK_UP6),
ISM_BLOCK_UP6_CMD_11 = ((IDX_U32_ISM_BLOCK_UP6 == 11)<< MSK_U32_ISM_BLOCK_UP6),

ISM_BLOCK_UP7_CMD_00 = ((IDX_U32_ISM_BLOCK_UP7  ==  0)<< MSK_U32_ISM_BLOCK_UP7),
ISM_BLOCK_UP7_CMD_01 = ((IDX_U32_ISM_BLOCK_UP7  ==  1)<< MSK_U32_ISM_BLOCK_UP7),
ISM_BLOCK_UP7_CMD_02 = ((IDX_U32_ISM_BLOCK_UP7  ==  2)<< MSK_U32_ISM_BLOCK_UP7),
ISM_BLOCK_UP7_CMD_03 = ((IDX_U32_ISM_BLOCK_UP7  ==  3)<< MSK_U32_ISM_BLOCK_UP7),
ISM_BLOCK_UP7_CMD_04 = ((IDX_U32_ISM_BLOCK_UP7  ==  4)<< MSK_U32_ISM_BLOCK_UP7),
ISM_BLOCK_UP7_CMD_05 = ((IDX_U32_ISM_BLOCK_UP7  ==  5)<< MSK_U32_ISM_BLOCK_UP7),
ISM_BLOCK_UP7_CMD_06 = ((IDX_U32_ISM_BLOCK_UP7  ==  6)<< MSK_U32_ISM_BLOCK_UP7),
ISM_BLOCK_UP7_CMD_07 = ((IDX_U32_ISM_BLOCK_UP7  ==  7)<< MSK_U32_ISM_BLOCK_UP7),
ISM_BLOCK_UP7_CMD_08 = ((IDX_U32_ISM_BLOCK_UP7  ==  8)<< MSK_U32_ISM_BLOCK_UP7),
ISM_BLOCK_UP7_CMD_09 = ((IDX_U32_ISM_BLOCK_UP7  ==  9)<< MSK_U32_ISM_BLOCK_UP7),
ISM_BLOCK_UP7_CMD_10 = ((IDX_U32_ISM_BLOCK_UP7  == 10)<< MSK_U32_ISM_BLOCK_UP7),
ISM_BLOCK_UP7_CMD_11 = ((IDX_U32_ISM_BLOCK_UP7  == 11)<< MSK_U32_ISM_BLOCK_UP7),
                    
                    
ISM_BLOCK_UP8_CMD_00 = ((IDX_U32_ISM_BLOCK_UP8 ==  0)<< MSK_U32_ISM_BLOCK_UP8),
ISM_BLOCK_UP8_CMD_01 = ((IDX_U32_ISM_BLOCK_UP8 ==  1)<< MSK_U32_ISM_BLOCK_UP8),
ISM_BLOCK_UP8_CMD_02 = ((IDX_U32_ISM_BLOCK_UP8 ==  2)<< MSK_U32_ISM_BLOCK_UP8),
ISM_BLOCK_UP8_CMD_03 = ((IDX_U32_ISM_BLOCK_UP8 ==  3)<< MSK_U32_ISM_BLOCK_UP8),
ISM_BLOCK_UP8_CMD_04 = ((IDX_U32_ISM_BLOCK_UP8 ==  4)<< MSK_U32_ISM_BLOCK_UP8),
ISM_BLOCK_UP8_CMD_05 = ((IDX_U32_ISM_BLOCK_UP8 ==  5)<< MSK_U32_ISM_BLOCK_UP8),
ISM_BLOCK_UP8_CMD_06 = ((IDX_U32_ISM_BLOCK_UP8 ==  6)<< MSK_U32_ISM_BLOCK_UP8),
ISM_BLOCK_UP8_CMD_07 = ((IDX_U32_ISM_BLOCK_UP8 ==  7)<< MSK_U32_ISM_BLOCK_UP8),
ISM_BLOCK_UP8_CMD_08 = ((IDX_U32_ISM_BLOCK_UP8 ==  8)<< MSK_U32_ISM_BLOCK_UP8),
ISM_BLOCK_UP8_CMD_09 = ((IDX_U32_ISM_BLOCK_UP8 ==  9)<< MSK_U32_ISM_BLOCK_UP8),
ISM_BLOCK_UP8_CMD_10 = ((IDX_U32_ISM_BLOCK_UP8 == 10)<< MSK_U32_ISM_BLOCK_UP8),
ISM_BLOCK_UP8_CMD_11 = ((IDX_U32_ISM_BLOCK_UP8 == 11)<< MSK_U32_ISM_BLOCK_UP8),
                    
                    
ISM_DF1_IN_CMD_00 = ((IDX_U32_ISM_DF1_IN ==  0)<< MSK_U32_ISM_DF1_IN  ),
ISM_DF1_IN_CMD_01 = ((IDX_U32_ISM_DF1_IN ==  1)<< MSK_U32_ISM_DF1_IN  ),
ISM_DF1_IN_CMD_02 = ((IDX_U32_ISM_DF1_IN ==  2)<< MSK_U32_ISM_DF1_IN  ),
ISM_DF1_IN_CMD_03 = ((IDX_U32_ISM_DF1_IN ==  3)<< MSK_U32_ISM_DF1_IN  ),
ISM_DF1_IN_CMD_04 = ((IDX_U32_ISM_DF1_IN ==  4)<< MSK_U32_ISM_DF1_IN  ),
ISM_DF1_IN_CMD_05 = ((IDX_U32_ISM_DF1_IN ==  5)<< MSK_U32_ISM_DF1_IN  ),
ISM_DF1_IN_CMD_06 = ((IDX_U32_ISM_DF1_IN ==  6)<< MSK_U32_ISM_DF1_IN  ),
ISM_DF1_IN_CMD_07 = ((IDX_U32_ISM_DF1_IN ==  7)<< MSK_U32_ISM_DF1_IN  ),
ISM_DF1_IN_CMD_08 = ((IDX_U32_ISM_DF1_IN ==  8)<< MSK_U32_ISM_DF1_IN  ),
ISM_DF1_IN_CMD_09 = ((IDX_U32_ISM_DF1_IN ==  9)<< MSK_U32_ISM_DF1_IN  ),
ISM_DF1_IN_CMD_10 = ((IDX_U32_ISM_DF1_IN == 10)<< MSK_U32_ISM_DF1_IN  ),
ISM_DF1_IN_CMD_11 = ((IDX_U32_ISM_DF1_IN == 11)<< MSK_U32_ISM_DF1_IN  ),
                    
                    
ISM_DF2_IN_CMD_00 = ((IDX_U32_ISM_DF2_IN  ==  0)<< MSK_U32_ISM_DF2_IN  ),
ISM_DF2_IN_CMD_01 = ((IDX_U32_ISM_DF2_IN  ==  1)<< MSK_U32_ISM_DF2_IN  ),
ISM_DF2_IN_CMD_02 = ((IDX_U32_ISM_DF2_IN  ==  2)<< MSK_U32_ISM_DF2_IN  ),
ISM_DF2_IN_CMD_03 = ((IDX_U32_ISM_DF2_IN  ==  3)<< MSK_U32_ISM_DF2_IN  ),
ISM_DF2_IN_CMD_04 = ((IDX_U32_ISM_DF2_IN  ==  4)<< MSK_U32_ISM_DF2_IN  ),
ISM_DF2_IN_CMD_05 = ((IDX_U32_ISM_DF2_IN  ==  5)<< MSK_U32_ISM_DF2_IN  ),
ISM_DF2_IN_CMD_06 = ((IDX_U32_ISM_DF2_IN  ==  6)<< MSK_U32_ISM_DF2_IN  ),
ISM_DF2_IN_CMD_07 = ((IDX_U32_ISM_DF2_IN  ==  7)<< MSK_U32_ISM_DF2_IN  ),
ISM_DF2_IN_CMD_08 = ((IDX_U32_ISM_DF2_IN  ==  8)<< MSK_U32_ISM_DF2_IN  ),
ISM_DF2_IN_CMD_09 = ((IDX_U32_ISM_DF2_IN  ==  9)<< MSK_U32_ISM_DF2_IN  ),
ISM_DF2_IN_CMD_10 = ((IDX_U32_ISM_DF2_IN  == 10)<< MSK_U32_ISM_DF2_IN  ),
ISM_DF2_IN_CMD_11 = ((IDX_U32_ISM_DF2_IN  == 11)<< MSK_U32_ISM_DF2_IN  ),

ISM_DF3_IN_CMD_00 = ((IDX_U32_ISM_DF3_IN ==  0)<< MSK_U32_ISM_DF3_IN),
ISM_DF3_IN_CMD_01 = ((IDX_U32_ISM_DF3_IN ==  1)<< MSK_U32_ISM_DF3_IN),
ISM_DF3_IN_CMD_02 = ((IDX_U32_ISM_DF3_IN ==  2)<< MSK_U32_ISM_DF3_IN),
ISM_DF3_IN_CMD_03 = ((IDX_U32_ISM_DF3_IN ==  3)<< MSK_U32_ISM_DF3_IN),
ISM_DF3_IN_CMD_04 = ((IDX_U32_ISM_DF3_IN ==  4)<< MSK_U32_ISM_DF3_IN),
ISM_DF3_IN_CMD_05 = ((IDX_U32_ISM_DF3_IN ==  5)<< MSK_U32_ISM_DF3_IN),
ISM_DF3_IN_CMD_06 = ((IDX_U32_ISM_DF3_IN ==  6)<< MSK_U32_ISM_DF3_IN),
ISM_DF3_IN_CMD_07 = ((IDX_U32_ISM_DF3_IN ==  7)<< MSK_U32_ISM_DF3_IN),
ISM_DF3_IN_CMD_08 = ((IDX_U32_ISM_DF3_IN ==  8)<< MSK_U32_ISM_DF3_IN),
ISM_DF3_IN_CMD_09 = ((IDX_U32_ISM_DF3_IN ==  9)<< MSK_U32_ISM_DF3_IN),
ISM_DF3_IN_CMD_10 = ((IDX_U32_ISM_DF3_IN == 10)<< MSK_U32_ISM_DF3_IN),
ISM_DF3_IN_CMD_11 = ((IDX_U32_ISM_DF3_IN == 11)<< MSK_U32_ISM_DF3_IN),
                    
                    
ISM_DF4_IN_CMD_00 = ((IDX_U32_ISM_DF4_IN ==  0)<< MSK_U32_ISM_DF4_IN),
ISM_DF4_IN_CMD_01 = ((IDX_U32_ISM_DF4_IN ==  1)<< MSK_U32_ISM_DF4_IN),
ISM_DF4_IN_CMD_02 = ((IDX_U32_ISM_DF4_IN ==  2)<< MSK_U32_ISM_DF4_IN),
ISM_DF4_IN_CMD_03 = ((IDX_U32_ISM_DF4_IN ==  3)<< MSK_U32_ISM_DF4_IN),
ISM_DF4_IN_CMD_04 = ((IDX_U32_ISM_DF4_IN ==  4)<< MSK_U32_ISM_DF4_IN),
ISM_DF4_IN_CMD_05 = ((IDX_U32_ISM_DF4_IN ==  5)<< MSK_U32_ISM_DF4_IN),
ISM_DF4_IN_CMD_06 = ((IDX_U32_ISM_DF4_IN ==  6)<< MSK_U32_ISM_DF4_IN),
ISM_DF4_IN_CMD_07 = ((IDX_U32_ISM_DF4_IN ==  7)<< MSK_U32_ISM_DF4_IN),
ISM_DF4_IN_CMD_08 = ((IDX_U32_ISM_DF4_IN ==  8)<< MSK_U32_ISM_DF4_IN),
ISM_DF4_IN_CMD_09 = ((IDX_U32_ISM_DF4_IN ==  9)<< MSK_U32_ISM_DF4_IN),
ISM_DF4_IN_CMD_10 = ((IDX_U32_ISM_DF4_IN == 10)<< MSK_U32_ISM_DF4_IN),
ISM_DF4_IN_CMD_11 = ((IDX_U32_ISM_DF4_IN == 11)<< MSK_U32_ISM_DF4_IN),
                    
                    
ISM_DF5_IN_CMD_00 = ((IDX_U32_ISM_DF5_IN ==  0)<< MSK_U32_ISM_DF5_IN),
ISM_DF5_IN_CMD_01 = ((IDX_U32_ISM_DF5_IN ==  1)<< MSK_U32_ISM_DF5_IN),
ISM_DF5_IN_CMD_02 = ((IDX_U32_ISM_DF5_IN ==  2)<< MSK_U32_ISM_DF5_IN),
ISM_DF5_IN_CMD_03 = ((IDX_U32_ISM_DF5_IN ==  3)<< MSK_U32_ISM_DF5_IN),
ISM_DF5_IN_CMD_04 = ((IDX_U32_ISM_DF5_IN ==  4)<< MSK_U32_ISM_DF5_IN),
ISM_DF5_IN_CMD_05 = ((IDX_U32_ISM_DF5_IN ==  5)<< MSK_U32_ISM_DF5_IN),
ISM_DF5_IN_CMD_06 = ((IDX_U32_ISM_DF5_IN ==  6)<< MSK_U32_ISM_DF5_IN),
ISM_DF5_IN_CMD_07 = ((IDX_U32_ISM_DF5_IN ==  7)<< MSK_U32_ISM_DF5_IN),
ISM_DF5_IN_CMD_08 = ((IDX_U32_ISM_DF5_IN ==  8)<< MSK_U32_ISM_DF5_IN),
ISM_DF5_IN_CMD_09 = ((IDX_U32_ISM_DF5_IN ==  9)<< MSK_U32_ISM_DF5_IN),
ISM_DF5_IN_CMD_10 = ((IDX_U32_ISM_DF5_IN == 10)<< MSK_U32_ISM_DF5_IN),
ISM_DF5_IN_CMD_11 = ((IDX_U32_ISM_DF5_IN == 11)<< MSK_U32_ISM_DF5_IN),
                    
                    
ISM_DF6_IN_CMD_00 = ((IDX_U32_ISM_DF6_IN ==  0)<< MSK_U32_ISM_DF6_IN),
ISM_DF6_IN_CMD_01 = ((IDX_U32_ISM_DF6_IN ==  1)<< MSK_U32_ISM_DF6_IN),
ISM_DF6_IN_CMD_02 = ((IDX_U32_ISM_DF6_IN ==  2)<< MSK_U32_ISM_DF6_IN),
ISM_DF6_IN_CMD_03 = ((IDX_U32_ISM_DF6_IN ==  3)<< MSK_U32_ISM_DF6_IN),
ISM_DF6_IN_CMD_04 = ((IDX_U32_ISM_DF6_IN ==  4)<< MSK_U32_ISM_DF6_IN),
ISM_DF6_IN_CMD_05 = ((IDX_U32_ISM_DF6_IN ==  5)<< MSK_U32_ISM_DF6_IN),
ISM_DF6_IN_CMD_06 = ((IDX_U32_ISM_DF6_IN ==  6)<< MSK_U32_ISM_DF6_IN),
ISM_DF6_IN_CMD_07 = ((IDX_U32_ISM_DF6_IN ==  7)<< MSK_U32_ISM_DF6_IN),
ISM_DF6_IN_CMD_08 = ((IDX_U32_ISM_DF6_IN ==  8)<< MSK_U32_ISM_DF6_IN),
ISM_DF6_IN_CMD_09 = ((IDX_U32_ISM_DF6_IN ==  9)<< MSK_U32_ISM_DF6_IN),
ISM_DF6_IN_CMD_10 = ((IDX_U32_ISM_DF6_IN == 10)<< MSK_U32_ISM_DF6_IN),
ISM_DF6_IN_CMD_11 = ((IDX_U32_ISM_DF6_IN == 11)<< MSK_U32_ISM_DF6_IN),

ISM_DF7_IN_CMD_00 = ((IDX_U32_ISM_DF7_IN  ==  0)<< MSK_U32_ISM_DF7_IN ),
ISM_DF7_IN_CMD_01 = ((IDX_U32_ISM_DF7_IN  ==  1)<< MSK_U32_ISM_DF7_IN ),
ISM_DF7_IN_CMD_02 = ((IDX_U32_ISM_DF7_IN  ==  2)<< MSK_U32_ISM_DF7_IN ),
ISM_DF7_IN_CMD_03 = ((IDX_U32_ISM_DF7_IN  ==  3)<< MSK_U32_ISM_DF7_IN ),
ISM_DF7_IN_CMD_04 = ((IDX_U32_ISM_DF7_IN  ==  4)<< MSK_U32_ISM_DF7_IN ),
ISM_DF7_IN_CMD_05 = ((IDX_U32_ISM_DF7_IN  ==  5)<< MSK_U32_ISM_DF7_IN ),
ISM_DF7_IN_CMD_06 = ((IDX_U32_ISM_DF7_IN  ==  6)<< MSK_U32_ISM_DF7_IN ),
ISM_DF7_IN_CMD_07 = ((IDX_U32_ISM_DF7_IN  ==  7)<< MSK_U32_ISM_DF7_IN ),
ISM_DF7_IN_CMD_08 = ((IDX_U32_ISM_DF7_IN  ==  8)<< MSK_U32_ISM_DF7_IN ),
ISM_DF7_IN_CMD_09 = ((IDX_U32_ISM_DF7_IN  ==  9)<< MSK_U32_ISM_DF7_IN ),
ISM_DF7_IN_CMD_10 = ((IDX_U32_ISM_DF7_IN  == 10)<< MSK_U32_ISM_DF7_IN ),
ISM_DF7_IN_CMD_11 = ((IDX_U32_ISM_DF7_IN  == 11)<< MSK_U32_ISM_DF7_IN ),
                    
                    
ISM_DF8_IN_CMD_00 = ((IDX_U32_ISM_DF8_IN  ==  0)<< MSK_U32_ISM_DF8_IN ),
ISM_DF8_IN_CMD_01 = ((IDX_U32_ISM_DF8_IN  ==  1)<< MSK_U32_ISM_DF8_IN ),
ISM_DF8_IN_CMD_02 = ((IDX_U32_ISM_DF8_IN  ==  2)<< MSK_U32_ISM_DF8_IN ),
ISM_DF8_IN_CMD_03 = ((IDX_U32_ISM_DF8_IN  ==  3)<< MSK_U32_ISM_DF8_IN ),
ISM_DF8_IN_CMD_04 = ((IDX_U32_ISM_DF8_IN  ==  4)<< MSK_U32_ISM_DF8_IN ),
ISM_DF8_IN_CMD_05 = ((IDX_U32_ISM_DF8_IN  ==  5)<< MSK_U32_ISM_DF8_IN ),
ISM_DF8_IN_CMD_06 = ((IDX_U32_ISM_DF8_IN  ==  6)<< MSK_U32_ISM_DF8_IN ),
ISM_DF8_IN_CMD_07 = ((IDX_U32_ISM_DF8_IN  ==  7)<< MSK_U32_ISM_DF8_IN ),
ISM_DF8_IN_CMD_08 = ((IDX_U32_ISM_DF8_IN  ==  8)<< MSK_U32_ISM_DF8_IN ),
ISM_DF8_IN_CMD_09 = ((IDX_U32_ISM_DF8_IN  ==  9)<< MSK_U32_ISM_DF8_IN ),
ISM_DF8_IN_CMD_10 = ((IDX_U32_ISM_DF8_IN  == 10)<< MSK_U32_ISM_DF8_IN ),
ISM_DF8_IN_CMD_11 = ((IDX_U32_ISM_DF8_IN  == 11)<< MSK_U32_ISM_DF8_IN ),
                    
                    
ISM_DF9_IN_CMD_00 = ((IDX_U32_ISM_DF9_IN ==  0)<< MSK_U32_ISM_DF9_IN ),
ISM_DF9_IN_CMD_01 = ((IDX_U32_ISM_DF9_IN ==  1)<< MSK_U32_ISM_DF9_IN ),
ISM_DF9_IN_CMD_02 = ((IDX_U32_ISM_DF9_IN ==  2)<< MSK_U32_ISM_DF9_IN ),
ISM_DF9_IN_CMD_03 = ((IDX_U32_ISM_DF9_IN ==  3)<< MSK_U32_ISM_DF9_IN ),
ISM_DF9_IN_CMD_04 = ((IDX_U32_ISM_DF9_IN ==  4)<< MSK_U32_ISM_DF9_IN ),
ISM_DF9_IN_CMD_05 = ((IDX_U32_ISM_DF9_IN ==  5)<< MSK_U32_ISM_DF9_IN ),
ISM_DF9_IN_CMD_06 = ((IDX_U32_ISM_DF9_IN ==  6)<< MSK_U32_ISM_DF9_IN ),
ISM_DF9_IN_CMD_07 = ((IDX_U32_ISM_DF9_IN ==  7)<< MSK_U32_ISM_DF9_IN ),
ISM_DF9_IN_CMD_08 = ((IDX_U32_ISM_DF9_IN ==  8)<< MSK_U32_ISM_DF9_IN ),
ISM_DF9_IN_CMD_09 = ((IDX_U32_ISM_DF9_IN ==  9)<< MSK_U32_ISM_DF9_IN ),
ISM_DF9_IN_CMD_10 = ((IDX_U32_ISM_DF9_IN == 10)<< MSK_U32_ISM_DF9_IN ),
ISM_DF9_IN_CMD_11 = ((IDX_U32_ISM_DF9_IN == 11)<< MSK_U32_ISM_DF9_IN ),
                    
                    
ISM_DF10_IN_CMD_00 = ((IDX_U32_ISM_DF10_IN ==  0)<< MSK_U32_ISM_DF10_IN),
ISM_DF10_IN_CMD_01 = ((IDX_U32_ISM_DF10_IN ==  1)<< MSK_U32_ISM_DF10_IN),
ISM_DF10_IN_CMD_02 = ((IDX_U32_ISM_DF10_IN ==  2)<< MSK_U32_ISM_DF10_IN),
ISM_DF10_IN_CMD_03 = ((IDX_U32_ISM_DF10_IN ==  3)<< MSK_U32_ISM_DF10_IN),
ISM_DF10_IN_CMD_04 = ((IDX_U32_ISM_DF10_IN ==  4)<< MSK_U32_ISM_DF10_IN),
ISM_DF10_IN_CMD_05 = ((IDX_U32_ISM_DF10_IN ==  5)<< MSK_U32_ISM_DF10_IN),
ISM_DF10_IN_CMD_06 = ((IDX_U32_ISM_DF10_IN ==  6)<< MSK_U32_ISM_DF10_IN),
ISM_DF10_IN_CMD_07 = ((IDX_U32_ISM_DF10_IN ==  7)<< MSK_U32_ISM_DF10_IN),
ISM_DF10_IN_CMD_08 = ((IDX_U32_ISM_DF10_IN ==  8)<< MSK_U32_ISM_DF10_IN),
ISM_DF10_IN_CMD_09 = ((IDX_U32_ISM_DF10_IN ==  9)<< MSK_U32_ISM_DF10_IN),
ISM_DF10_IN_CMD_10 = ((IDX_U32_ISM_DF10_IN == 10)<< MSK_U32_ISM_DF10_IN),
ISM_DF10_IN_CMD_11 = ((IDX_U32_ISM_DF10_IN == 11)<< MSK_U32_ISM_DF10_IN),

ISM_DF11_IN_CMD_00 = ((IDX_U32_ISM_DF11_IN ==  0)<< MSK_U32_ISM_DF11_IN ),
ISM_DF11_IN_CMD_01 = ((IDX_U32_ISM_DF11_IN ==  1)<< MSK_U32_ISM_DF11_IN ),
ISM_DF11_IN_CMD_02 = ((IDX_U32_ISM_DF11_IN ==  2)<< MSK_U32_ISM_DF11_IN ),
ISM_DF11_IN_CMD_03 = ((IDX_U32_ISM_DF11_IN ==  3)<< MSK_U32_ISM_DF11_IN ),
ISM_DF11_IN_CMD_04 = ((IDX_U32_ISM_DF11_IN ==  4)<< MSK_U32_ISM_DF11_IN ),
ISM_DF11_IN_CMD_05 = ((IDX_U32_ISM_DF11_IN ==  5)<< MSK_U32_ISM_DF11_IN ),
ISM_DF11_IN_CMD_06 = ((IDX_U32_ISM_DF11_IN ==  6)<< MSK_U32_ISM_DF11_IN ),
ISM_DF11_IN_CMD_07 = ((IDX_U32_ISM_DF11_IN ==  7)<< MSK_U32_ISM_DF11_IN ),
ISM_DF11_IN_CMD_08 = ((IDX_U32_ISM_DF11_IN ==  8)<< MSK_U32_ISM_DF11_IN ),
ISM_DF11_IN_CMD_09 = ((IDX_U32_ISM_DF11_IN ==  9)<< MSK_U32_ISM_DF11_IN ),
ISM_DF11_IN_CMD_10 = ((IDX_U32_ISM_DF11_IN == 10)<< MSK_U32_ISM_DF11_IN ),
ISM_DF11_IN_CMD_11 = ((IDX_U32_ISM_DF11_IN == 11)<< MSK_U32_ISM_DF11_IN ),
                    
                    
ISM_DF12_IN_CMD_00 = ((IDX_U32_ISM_DF12_IN ==  0)<< MSK_U32_ISM_DF12_IN ),
ISM_DF12_IN_CMD_01 = ((IDX_U32_ISM_DF12_IN ==  1)<< MSK_U32_ISM_DF12_IN ),
ISM_DF12_IN_CMD_02 = ((IDX_U32_ISM_DF12_IN ==  2)<< MSK_U32_ISM_DF12_IN ),
ISM_DF12_IN_CMD_03 = ((IDX_U32_ISM_DF12_IN ==  3)<< MSK_U32_ISM_DF12_IN ),
ISM_DF12_IN_CMD_04 = ((IDX_U32_ISM_DF12_IN ==  4)<< MSK_U32_ISM_DF12_IN ),
ISM_DF12_IN_CMD_05 = ((IDX_U32_ISM_DF12_IN ==  5)<< MSK_U32_ISM_DF12_IN ),
ISM_DF12_IN_CMD_06 = ((IDX_U32_ISM_DF12_IN ==  6)<< MSK_U32_ISM_DF12_IN ),
ISM_DF12_IN_CMD_07 = ((IDX_U32_ISM_DF12_IN ==  7)<< MSK_U32_ISM_DF12_IN ),
ISM_DF12_IN_CMD_08 = ((IDX_U32_ISM_DF12_IN ==  8)<< MSK_U32_ISM_DF12_IN ),
ISM_DF12_IN_CMD_09 = ((IDX_U32_ISM_DF12_IN ==  9)<< MSK_U32_ISM_DF12_IN ),
ISM_DF12_IN_CMD_10 = ((IDX_U32_ISM_DF12_IN == 10)<< MSK_U32_ISM_DF12_IN ),
ISM_DF12_IN_CMD_11 = ((IDX_U32_ISM_DF12_IN == 11)<< MSK_U32_ISM_DF12_IN ),
                    
                    
ISM_DF13_IN_CMD_00 = ((IDX_U32_ISM_DF13_IN ==  0)<< MSK_U32_ISM_DF13_IN ),
ISM_DF13_IN_CMD_01 = ((IDX_U32_ISM_DF13_IN ==  1)<< MSK_U32_ISM_DF13_IN ),
ISM_DF13_IN_CMD_02 = ((IDX_U32_ISM_DF13_IN ==  2)<< MSK_U32_ISM_DF13_IN ),
ISM_DF13_IN_CMD_03 = ((IDX_U32_ISM_DF13_IN ==  3)<< MSK_U32_ISM_DF13_IN ),
ISM_DF13_IN_CMD_04 = ((IDX_U32_ISM_DF13_IN ==  4)<< MSK_U32_ISM_DF13_IN ),
ISM_DF13_IN_CMD_05 = ((IDX_U32_ISM_DF13_IN ==  5)<< MSK_U32_ISM_DF13_IN ),
ISM_DF13_IN_CMD_06 = ((IDX_U32_ISM_DF13_IN ==  6)<< MSK_U32_ISM_DF13_IN ),
ISM_DF13_IN_CMD_07 = ((IDX_U32_ISM_DF13_IN ==  7)<< MSK_U32_ISM_DF13_IN ),
ISM_DF13_IN_CMD_08 = ((IDX_U32_ISM_DF13_IN ==  8)<< MSK_U32_ISM_DF13_IN ),
ISM_DF13_IN_CMD_09 = ((IDX_U32_ISM_DF13_IN ==  9)<< MSK_U32_ISM_DF13_IN ),
ISM_DF13_IN_CMD_10 = ((IDX_U32_ISM_DF13_IN == 10)<< MSK_U32_ISM_DF13_IN ),
ISM_DF13_IN_CMD_11 = ((IDX_U32_ISM_DF13_IN == 11)<< MSK_U32_ISM_DF13_IN ),
                    
                    
ISM_DF14_IN_CMD_00 = ((IDX_U32_ISM_DF14_IN ==  0)<< MSK_U32_ISM_DF14_IN ),
ISM_DF14_IN_CMD_01 = ((IDX_U32_ISM_DF14_IN ==  1)<< MSK_U32_ISM_DF14_IN ),
ISM_DF14_IN_CMD_02 = ((IDX_U32_ISM_DF14_IN ==  2)<< MSK_U32_ISM_DF14_IN ),
ISM_DF14_IN_CMD_03 = ((IDX_U32_ISM_DF14_IN ==  3)<< MSK_U32_ISM_DF14_IN ),
ISM_DF14_IN_CMD_04 = ((IDX_U32_ISM_DF14_IN ==  4)<< MSK_U32_ISM_DF14_IN ),
ISM_DF14_IN_CMD_05 = ((IDX_U32_ISM_DF14_IN ==  5)<< MSK_U32_ISM_DF14_IN ),
ISM_DF14_IN_CMD_06 = ((IDX_U32_ISM_DF14_IN ==  6)<< MSK_U32_ISM_DF14_IN ),
ISM_DF14_IN_CMD_07 = ((IDX_U32_ISM_DF14_IN ==  7)<< MSK_U32_ISM_DF14_IN ),
ISM_DF14_IN_CMD_08 = ((IDX_U32_ISM_DF14_IN ==  8)<< MSK_U32_ISM_DF14_IN ),
ISM_DF14_IN_CMD_09 = ((IDX_U32_ISM_DF14_IN ==  9)<< MSK_U32_ISM_DF14_IN ),
ISM_DF14_IN_CMD_10 = ((IDX_U32_ISM_DF14_IN == 10)<< MSK_U32_ISM_DF14_IN ),
ISM_DF14_IN_CMD_11 = ((IDX_U32_ISM_DF14_IN == 11)<< MSK_U32_ISM_DF14_IN ),

ISM_DF15_IN_CMD_00 = ((IDX_U32_ISM_DF15_IN ==  0)<< MSK_U32_ISM_DF15_IN  ),
ISM_DF15_IN_CMD_01 = ((IDX_U32_ISM_DF15_IN ==  1)<< MSK_U32_ISM_DF15_IN  ),
ISM_DF15_IN_CMD_02 = ((IDX_U32_ISM_DF15_IN ==  2)<< MSK_U32_ISM_DF15_IN  ),
ISM_DF15_IN_CMD_03 = ((IDX_U32_ISM_DF15_IN ==  3)<< MSK_U32_ISM_DF15_IN  ),
ISM_DF15_IN_CMD_04 = ((IDX_U32_ISM_DF15_IN ==  4)<< MSK_U32_ISM_DF15_IN  ),
ISM_DF15_IN_CMD_05 = ((IDX_U32_ISM_DF15_IN ==  5)<< MSK_U32_ISM_DF15_IN  ),
ISM_DF15_IN_CMD_06 = ((IDX_U32_ISM_DF15_IN ==  6)<< MSK_U32_ISM_DF15_IN  ),
ISM_DF15_IN_CMD_07 = ((IDX_U32_ISM_DF15_IN ==  7)<< MSK_U32_ISM_DF15_IN  ),
ISM_DF15_IN_CMD_08 = ((IDX_U32_ISM_DF15_IN ==  8)<< MSK_U32_ISM_DF15_IN  ),
ISM_DF15_IN_CMD_09 = ((IDX_U32_ISM_DF15_IN ==  9)<< MSK_U32_ISM_DF15_IN  ),
ISM_DF15_IN_CMD_10 = ((IDX_U32_ISM_DF15_IN == 10)<< MSK_U32_ISM_DF15_IN  ),
ISM_DF15_IN_CMD_11 = ((IDX_U32_ISM_DF15_IN == 11)<< MSK_U32_ISM_DF15_IN  ),
                    
                    
ISM_DF16_IN_CMD_00 = ((IDX_U32_ISM_DF16_IN   ==  0)<< MSK_U32_ISM_DF16_IN  ),
ISM_DF16_IN_CMD_01 = ((IDX_U32_ISM_DF16_IN   ==  1)<< MSK_U32_ISM_DF16_IN  ),
ISM_DF16_IN_CMD_02 = ((IDX_U32_ISM_DF16_IN   ==  2)<< MSK_U32_ISM_DF16_IN  ),
ISM_DF16_IN_CMD_03 = ((IDX_U32_ISM_DF16_IN   ==  3)<< MSK_U32_ISM_DF16_IN  ),
ISM_DF16_IN_CMD_04 = ((IDX_U32_ISM_DF16_IN   ==  4)<< MSK_U32_ISM_DF16_IN  ),
ISM_DF16_IN_CMD_05 = ((IDX_U32_ISM_DF16_IN   ==  5)<< MSK_U32_ISM_DF16_IN  ),
ISM_DF16_IN_CMD_06 = ((IDX_U32_ISM_DF16_IN   ==  6)<< MSK_U32_ISM_DF16_IN  ),
ISM_DF16_IN_CMD_07 = ((IDX_U32_ISM_DF16_IN   ==  7)<< MSK_U32_ISM_DF16_IN  ),
ISM_DF16_IN_CMD_08 = ((IDX_U32_ISM_DF16_IN   ==  8)<< MSK_U32_ISM_DF16_IN  ),
ISM_DF16_IN_CMD_09 = ((IDX_U32_ISM_DF16_IN   ==  9)<< MSK_U32_ISM_DF16_IN  ),
ISM_DF16_IN_CMD_10 = ((IDX_U32_ISM_DF16_IN   == 10)<< MSK_U32_ISM_DF16_IN  ),
ISM_DF16_IN_CMD_11 = ((IDX_U32_ISM_DF16_IN   == 11)<< MSK_U32_ISM_DF16_IN  ),
                    
                    
ISM_DT1_SET_CMD_00 = ((IDX_U32_ISM_DT1_SET   ==  0)<< MSK_U32_ISM_DT1_SET  ),
ISM_DT1_SET_CMD_01 = ((IDX_U32_ISM_DT1_SET   ==  1)<< MSK_U32_ISM_DT1_SET  ),
ISM_DT1_SET_CMD_02 = ((IDX_U32_ISM_DT1_SET   ==  2)<< MSK_U32_ISM_DT1_SET  ),
ISM_DT1_SET_CMD_03 = ((IDX_U32_ISM_DT1_SET   ==  3)<< MSK_U32_ISM_DT1_SET  ),
ISM_DT1_SET_CMD_04 = ((IDX_U32_ISM_DT1_SET   ==  4)<< MSK_U32_ISM_DT1_SET  ),
ISM_DT1_SET_CMD_05 = ((IDX_U32_ISM_DT1_SET   ==  5)<< MSK_U32_ISM_DT1_SET  ),
ISM_DT1_SET_CMD_06 = ((IDX_U32_ISM_DT1_SET   ==  6)<< MSK_U32_ISM_DT1_SET  ),
ISM_DT1_SET_CMD_07 = ((IDX_U32_ISM_DT1_SET   ==  7)<< MSK_U32_ISM_DT1_SET  ),
ISM_DT1_SET_CMD_08 = ((IDX_U32_ISM_DT1_SET   ==  8)<< MSK_U32_ISM_DT1_SET  ),
ISM_DT1_SET_CMD_09 = ((IDX_U32_ISM_DT1_SET   ==  9)<< MSK_U32_ISM_DT1_SET  ),
ISM_DT1_SET_CMD_10 = ((IDX_U32_ISM_DT1_SET   == 10)<< MSK_U32_ISM_DT1_SET  ),
ISM_DT1_SET_CMD_11 = ((IDX_U32_ISM_DT1_SET   == 11)<< MSK_U32_ISM_DT1_SET  ),
                    
                    
ISM_DT1_RESET_CMD_00 = ((IDX_U32_ISM_DT1_RESET ==  0)<< MSK_U32_ISM_DT1_RESET),
ISM_DT1_RESET_CMD_01 = ((IDX_U32_ISM_DT1_RESET ==  1)<< MSK_U32_ISM_DT1_RESET),
ISM_DT1_RESET_CMD_02 = ((IDX_U32_ISM_DT1_RESET ==  2)<< MSK_U32_ISM_DT1_RESET),
ISM_DT1_RESET_CMD_03 = ((IDX_U32_ISM_DT1_RESET ==  3)<< MSK_U32_ISM_DT1_RESET),
ISM_DT1_RESET_CMD_04 = ((IDX_U32_ISM_DT1_RESET ==  4)<< MSK_U32_ISM_DT1_RESET),
ISM_DT1_RESET_CMD_05 = ((IDX_U32_ISM_DT1_RESET ==  5)<< MSK_U32_ISM_DT1_RESET),
ISM_DT1_RESET_CMD_06 = ((IDX_U32_ISM_DT1_RESET ==  6)<< MSK_U32_ISM_DT1_RESET),
ISM_DT1_RESET_CMD_07 = ((IDX_U32_ISM_DT1_RESET ==  7)<< MSK_U32_ISM_DT1_RESET),
ISM_DT1_RESET_CMD_08 = ((IDX_U32_ISM_DT1_RESET ==  8)<< MSK_U32_ISM_DT1_RESET),
ISM_DT1_RESET_CMD_09 = ((IDX_U32_ISM_DT1_RESET ==  9)<< MSK_U32_ISM_DT1_RESET),
ISM_DT1_RESET_CMD_10 = ((IDX_U32_ISM_DT1_RESET == 10)<< MSK_U32_ISM_DT1_RESET),
ISM_DT1_RESET_CMD_11 = ((IDX_U32_ISM_DT1_RESET == 11)<< MSK_U32_ISM_DT1_RESET),

ISM_DT2_SET_CMD_00 = ((IDX_U32_ISM_DT2_SET  ==  0)<< MSK_U32_ISM_DT2_SET  ),
ISM_DT2_SET_CMD_01 = ((IDX_U32_ISM_DT2_SET  ==  1)<< MSK_U32_ISM_DT2_SET  ),
ISM_DT2_SET_CMD_02 = ((IDX_U32_ISM_DT2_SET  ==  2)<< MSK_U32_ISM_DT2_SET  ),
ISM_DT2_SET_CMD_03 = ((IDX_U32_ISM_DT2_SET  ==  3)<< MSK_U32_ISM_DT2_SET  ),
ISM_DT2_SET_CMD_04 = ((IDX_U32_ISM_DT2_SET  ==  4)<< MSK_U32_ISM_DT2_SET  ),
ISM_DT2_SET_CMD_05 = ((IDX_U32_ISM_DT2_SET  ==  5)<< MSK_U32_ISM_DT2_SET  ),
ISM_DT2_SET_CMD_06 = ((IDX_U32_ISM_DT2_SET  ==  6)<< MSK_U32_ISM_DT2_SET  ),
ISM_DT2_SET_CMD_07 = ((IDX_U32_ISM_DT2_SET  ==  7)<< MSK_U32_ISM_DT2_SET  ),
ISM_DT2_SET_CMD_08 = ((IDX_U32_ISM_DT2_SET  ==  8)<< MSK_U32_ISM_DT2_SET  ),
ISM_DT2_SET_CMD_09 = ((IDX_U32_ISM_DT2_SET  ==  9)<< MSK_U32_ISM_DT2_SET  ),
ISM_DT2_SET_CMD_10 = ((IDX_U32_ISM_DT2_SET  == 10)<< MSK_U32_ISM_DT2_SET  ),
ISM_DT2_SET_CMD_11 = ((IDX_U32_ISM_DT2_SET  == 11)<< MSK_U32_ISM_DT2_SET  ),
                    
                    
ISM_DT2_RESET_CMD_00 = ((IDX_U32_ISM_DT2_RESET ==  0)<< MSK_U32_ISM_DT2_RESET),
ISM_DT2_RESET_CMD_01 = ((IDX_U32_ISM_DT2_RESET ==  1)<< MSK_U32_ISM_DT2_RESET),
ISM_DT2_RESET_CMD_02 = ((IDX_U32_ISM_DT2_RESET ==  2)<< MSK_U32_ISM_DT2_RESET),
ISM_DT2_RESET_CMD_03 = ((IDX_U32_ISM_DT2_RESET ==  3)<< MSK_U32_ISM_DT2_RESET),
ISM_DT2_RESET_CMD_04 = ((IDX_U32_ISM_DT2_RESET ==  4)<< MSK_U32_ISM_DT2_RESET),
ISM_DT2_RESET_CMD_05 = ((IDX_U32_ISM_DT2_RESET ==  5)<< MSK_U32_ISM_DT2_RESET),
ISM_DT2_RESET_CMD_06 = ((IDX_U32_ISM_DT2_RESET ==  6)<< MSK_U32_ISM_DT2_RESET),
ISM_DT2_RESET_CMD_07 = ((IDX_U32_ISM_DT2_RESET ==  7)<< MSK_U32_ISM_DT2_RESET),
ISM_DT2_RESET_CMD_08 = ((IDX_U32_ISM_DT2_RESET ==  8)<< MSK_U32_ISM_DT2_RESET),
ISM_DT2_RESET_CMD_09 = ((IDX_U32_ISM_DT2_RESET ==  9)<< MSK_U32_ISM_DT2_RESET),
ISM_DT2_RESET_CMD_10 = ((IDX_U32_ISM_DT2_RESET == 10)<< MSK_U32_ISM_DT2_RESET),
ISM_DT2_RESET_CMD_11 = ((IDX_U32_ISM_DT2_RESET == 11)<< MSK_U32_ISM_DT2_RESET),
                    
                    
ISM_DT3_SET_CMD_00 = ((IDX_U32_ISM_DT3_SET  ==  0)<< MSK_U32_ISM_DT3_SET ),
ISM_DT3_SET_CMD_01 = ((IDX_U32_ISM_DT3_SET  ==  1)<< MSK_U32_ISM_DT3_SET ),
ISM_DT3_SET_CMD_02 = ((IDX_U32_ISM_DT3_SET  ==  2)<< MSK_U32_ISM_DT3_SET ),
ISM_DT3_SET_CMD_03 = ((IDX_U32_ISM_DT3_SET  ==  3)<< MSK_U32_ISM_DT3_SET ),
ISM_DT3_SET_CMD_04 = ((IDX_U32_ISM_DT3_SET  ==  4)<< MSK_U32_ISM_DT3_SET ),
ISM_DT3_SET_CMD_05 = ((IDX_U32_ISM_DT3_SET  ==  5)<< MSK_U32_ISM_DT3_SET ),
ISM_DT3_SET_CMD_06 = ((IDX_U32_ISM_DT3_SET  ==  6)<< MSK_U32_ISM_DT3_SET ),
ISM_DT3_SET_CMD_07 = ((IDX_U32_ISM_DT3_SET  ==  7)<< MSK_U32_ISM_DT3_SET ),
ISM_DT3_SET_CMD_08 = ((IDX_U32_ISM_DT3_SET  ==  8)<< MSK_U32_ISM_DT3_SET ),
ISM_DT3_SET_CMD_09 = ((IDX_U32_ISM_DT3_SET  ==  9)<< MSK_U32_ISM_DT3_SET ),
ISM_DT3_SET_CMD_10 = ((IDX_U32_ISM_DT3_SET  == 10)<< MSK_U32_ISM_DT3_SET ),
ISM_DT3_SET_CMD_11 = ((IDX_U32_ISM_DT3_SET  == 11)<< MSK_U32_ISM_DT3_SET ),
                    
                  
ISM_DT3_RESET_CMD_00 = ((IDX_U32_ISM_DT3_RESET ==  0)<< MSK_U32_ISM_DT3_RESET),
ISM_DT3_RESET_CMD_01 = ((IDX_U32_ISM_DT3_RESET ==  1)<< MSK_U32_ISM_DT3_RESET),
ISM_DT3_RESET_CMD_02 = ((IDX_U32_ISM_DT3_RESET ==  2)<< MSK_U32_ISM_DT3_RESET),
ISM_DT3_RESET_CMD_03 = ((IDX_U32_ISM_DT3_RESET ==  3)<< MSK_U32_ISM_DT3_RESET),
ISM_DT3_RESET_CMD_04 = ((IDX_U32_ISM_DT3_RESET ==  4)<< MSK_U32_ISM_DT3_RESET),
ISM_DT3_RESET_CMD_05 = ((IDX_U32_ISM_DT3_RESET ==  5)<< MSK_U32_ISM_DT3_RESET),
ISM_DT3_RESET_CMD_06 = ((IDX_U32_ISM_DT3_RESET ==  6)<< MSK_U32_ISM_DT3_RESET),
ISM_DT3_RESET_CMD_07 = ((IDX_U32_ISM_DT3_RESET ==  7)<< MSK_U32_ISM_DT3_RESET),
ISM_DT3_RESET_CMD_08 = ((IDX_U32_ISM_DT3_RESET ==  8)<< MSK_U32_ISM_DT3_RESET),
ISM_DT3_RESET_CMD_09 = ((IDX_U32_ISM_DT3_RESET ==  9)<< MSK_U32_ISM_DT3_RESET),
ISM_DT3_RESET_CMD_10 = ((IDX_U32_ISM_DT3_RESET == 10)<< MSK_U32_ISM_DT3_RESET),
ISM_DT3_RESET_CMD_11 = ((IDX_U32_ISM_DT3_RESET == 11)<< MSK_U32_ISM_DT3_RESET),

ISM_DT4_SET_CMD_00 = ((IDX_U32_ISM_DT4_SET  ==  0)<< MSK_U32_ISM_DT4_SET  ),
ISM_DT4_SET_CMD_01 = ((IDX_U32_ISM_DT4_SET  ==  1)<< MSK_U32_ISM_DT4_SET  ),
ISM_DT4_SET_CMD_02 = ((IDX_U32_ISM_DT4_SET  ==  2)<< MSK_U32_ISM_DT4_SET  ),
ISM_DT4_SET_CMD_03 = ((IDX_U32_ISM_DT4_SET  ==  3)<< MSK_U32_ISM_DT4_SET  ),
ISM_DT4_SET_CMD_04 = ((IDX_U32_ISM_DT4_SET  ==  4)<< MSK_U32_ISM_DT4_SET  ),
ISM_DT4_SET_CMD_05 = ((IDX_U32_ISM_DT4_SET  ==  5)<< MSK_U32_ISM_DT4_SET  ),
ISM_DT4_SET_CMD_06 = ((IDX_U32_ISM_DT4_SET  ==  6)<< MSK_U32_ISM_DT4_SET  ),
ISM_DT4_SET_CMD_07 = ((IDX_U32_ISM_DT4_SET  ==  7)<< MSK_U32_ISM_DT4_SET  ),
ISM_DT4_SET_CMD_08 = ((IDX_U32_ISM_DT4_SET  ==  8)<< MSK_U32_ISM_DT4_SET  ),
ISM_DT4_SET_CMD_09 = ((IDX_U32_ISM_DT4_SET  ==  9)<< MSK_U32_ISM_DT4_SET  ),
ISM_DT4_SET_CMD_10 = ((IDX_U32_ISM_DT4_SET  == 10)<< MSK_U32_ISM_DT4_SET  ),
ISM_DT4_SET_CMD_11 = ((IDX_U32_ISM_DT4_SET  == 11)<< MSK_U32_ISM_DT4_SET  ),
                    
                    
ISM_DT4_RESET_CMD_00 = ((IDX_U32_ISM_DT4_RESET ==  0)<< MSK_U32_ISM_DT4_RESET),
ISM_DT4_RESET_CMD_01 = ((IDX_U32_ISM_DT4_RESET ==  1)<< MSK_U32_ISM_DT4_RESET),
ISM_DT4_RESET_CMD_02 = ((IDX_U32_ISM_DT4_RESET ==  2)<< MSK_U32_ISM_DT4_RESET),
ISM_DT4_RESET_CMD_03 = ((IDX_U32_ISM_DT4_RESET ==  3)<< MSK_U32_ISM_DT4_RESET),
ISM_DT4_RESET_CMD_04 = ((IDX_U32_ISM_DT4_RESET ==  4)<< MSK_U32_ISM_DT4_RESET),
ISM_DT4_RESET_CMD_05 = ((IDX_U32_ISM_DT4_RESET ==  5)<< MSK_U32_ISM_DT4_RESET),
ISM_DT4_RESET_CMD_06 = ((IDX_U32_ISM_DT4_RESET ==  6)<< MSK_U32_ISM_DT4_RESET),
ISM_DT4_RESET_CMD_07 = ((IDX_U32_ISM_DT4_RESET ==  7)<< MSK_U32_ISM_DT4_RESET),
ISM_DT4_RESET_CMD_08 = ((IDX_U32_ISM_DT4_RESET ==  8)<< MSK_U32_ISM_DT4_RESET),
ISM_DT4_RESET_CMD_09 = ((IDX_U32_ISM_DT4_RESET ==  9)<< MSK_U32_ISM_DT4_RESET),
ISM_DT4_RESET_CMD_10 = ((IDX_U32_ISM_DT4_RESET == 10)<< MSK_U32_ISM_DT4_RESET),
ISM_DT4_RESET_CMD_11 = ((IDX_U32_ISM_DT4_RESET == 11)<< MSK_U32_ISM_DT4_RESET),
                    
                    
ISM_LF1_CMD_00 = ((IDX_U32_ISM_LF1 ==  0)<< MSK_U32_ISM_LF1),
ISM_LF1_CMD_01 = ((IDX_U32_ISM_LF1 ==  1)<< MSK_U32_ISM_LF1),
ISM_LF1_CMD_02 = ((IDX_U32_ISM_LF1 ==  2)<< MSK_U32_ISM_LF1),
ISM_LF1_CMD_03 = ((IDX_U32_ISM_LF1 ==  3)<< MSK_U32_ISM_LF1),
ISM_LF1_CMD_04 = ((IDX_U32_ISM_LF1 ==  4)<< MSK_U32_ISM_LF1),
ISM_LF1_CMD_05 = ((IDX_U32_ISM_LF1 ==  5)<< MSK_U32_ISM_LF1),
ISM_LF1_CMD_06 = ((IDX_U32_ISM_LF1 ==  6)<< MSK_U32_ISM_LF1),
ISM_LF1_CMD_07 = ((IDX_U32_ISM_LF1 ==  7)<< MSK_U32_ISM_LF1),
ISM_LF1_CMD_08 = ((IDX_U32_ISM_LF1 ==  8)<< MSK_U32_ISM_LF1),
ISM_LF1_CMD_09 = ((IDX_U32_ISM_LF1 ==  9)<< MSK_U32_ISM_LF1),
ISM_LF1_CMD_10 = ((IDX_U32_ISM_LF1 == 10)<< MSK_U32_ISM_LF1),
ISM_LF1_CMD_11 = ((IDX_U32_ISM_LF1 == 11)<< MSK_U32_ISM_LF1),
                    
                    
ISM_LF2_CMD_00 = ((IDX_U32_ISM_LF2 ==  0)<< MSK_U32_ISM_LF2),
ISM_LF2_CMD_01 = ((IDX_U32_ISM_LF2 ==  1)<< MSK_U32_ISM_LF2),
ISM_LF2_CMD_02 = ((IDX_U32_ISM_LF2 ==  2)<< MSK_U32_ISM_LF2),
ISM_LF2_CMD_03 = ((IDX_U32_ISM_LF2 ==  3)<< MSK_U32_ISM_LF2),
ISM_LF2_CMD_04 = ((IDX_U32_ISM_LF2 ==  4)<< MSK_U32_ISM_LF2),
ISM_LF2_CMD_05 = ((IDX_U32_ISM_LF2 ==  5)<< MSK_U32_ISM_LF2),
ISM_LF2_CMD_06 = ((IDX_U32_ISM_LF2 ==  6)<< MSK_U32_ISM_LF2),
ISM_LF2_CMD_07 = ((IDX_U32_ISM_LF2 ==  7)<< MSK_U32_ISM_LF2),
ISM_LF2_CMD_08 = ((IDX_U32_ISM_LF2 ==  8)<< MSK_U32_ISM_LF2),
ISM_LF2_CMD_09 = ((IDX_U32_ISM_LF2 ==  9)<< MSK_U32_ISM_LF2),
ISM_LF2_CMD_10 = ((IDX_U32_ISM_LF2 == 10)<< MSK_U32_ISM_LF2),
ISM_LF2_CMD_11 = ((IDX_U32_ISM_LF2 == 11)<< MSK_U32_ISM_LF2),
ISM_LF2_CMD_12 = ((IDX_U32_ISM_LF2 == 12)<< MSK_U32_ISM_LF2),

ISM_LF3_CMD_00 = ((IDX_U32_ISM_LF3 ==  0)<< MSK_U32_ISM_LF3),
ISM_LF3_CMD_01 = ((IDX_U32_ISM_LF3 ==  1)<< MSK_U32_ISM_LF3),
ISM_LF3_CMD_02 = ((IDX_U32_ISM_LF3 ==  2)<< MSK_U32_ISM_LF3),
ISM_LF3_CMD_03 = ((IDX_U32_ISM_LF3 ==  3)<< MSK_U32_ISM_LF3),
ISM_LF3_CMD_04 = ((IDX_U32_ISM_LF3 ==  4)<< MSK_U32_ISM_LF3),
ISM_LF3_CMD_05 = ((IDX_U32_ISM_LF3 ==  5)<< MSK_U32_ISM_LF3),
ISM_LF3_CMD_06 = ((IDX_U32_ISM_LF3 ==  6)<< MSK_U32_ISM_LF3),
ISM_LF3_CMD_07 = ((IDX_U32_ISM_LF3 ==  7)<< MSK_U32_ISM_LF3),
ISM_LF3_CMD_08 = ((IDX_U32_ISM_LF3 ==  8)<< MSK_U32_ISM_LF3),
ISM_LF3_CMD_09 = ((IDX_U32_ISM_LF3 ==  9)<< MSK_U32_ISM_LF3),
ISM_LF3_CMD_10 = ((IDX_U32_ISM_LF3 == 10)<< MSK_U32_ISM_LF3),
ISM_LF3_CMD_11 = ((IDX_U32_ISM_LF3 == 11)<< MSK_U32_ISM_LF3),
ISM_LF3_CMD_12 = ((IDX_U32_ISM_LF3 == 12)<< MSK_U32_ISM_LF3),
                    
                    
ISM_LF4_CMD_00 = ((IDX_U32_ISM_LF4 ==  0)<< MSK_U32_ISM_LF4),
ISM_LF4_CMD_01 = ((IDX_U32_ISM_LF4 ==  1)<< MSK_U32_ISM_LF4),
ISM_LF4_CMD_02 = ((IDX_U32_ISM_LF4 ==  2)<< MSK_U32_ISM_LF4),
ISM_LF4_CMD_03 = ((IDX_U32_ISM_LF4 ==  3)<< MSK_U32_ISM_LF4),
ISM_LF4_CMD_04 = ((IDX_U32_ISM_LF4 ==  4)<< MSK_U32_ISM_LF4),
ISM_LF4_CMD_05 = ((IDX_U32_ISM_LF4 ==  5)<< MSK_U32_ISM_LF4),
ISM_LF4_CMD_06 = ((IDX_U32_ISM_LF4 ==  6)<< MSK_U32_ISM_LF4),
ISM_LF4_CMD_07 = ((IDX_U32_ISM_LF4 ==  7)<< MSK_U32_ISM_LF4),
ISM_LF4_CMD_08 = ((IDX_U32_ISM_LF4 ==  8)<< MSK_U32_ISM_LF4),
ISM_LF4_CMD_09 = ((IDX_U32_ISM_LF4 ==  9)<< MSK_U32_ISM_LF4),
ISM_LF4_CMD_10 = ((IDX_U32_ISM_LF4 == 10)<< MSK_U32_ISM_LF4),
ISM_LF4_CMD_11 = ((IDX_U32_ISM_LF4 == 11)<< MSK_U32_ISM_LF4),
ISM_LF4_CMD_12 = ((IDX_U32_ISM_LF4 == 12)<< MSK_U32_ISM_LF4),
                    
                    
ISM_LF5_CMD_00 = ((IDX_U32_ISM_LF5 ==  0)<< MSK_U32_ISM_LF5),
ISM_LF5_CMD_01 = ((IDX_U32_ISM_LF5 ==  1)<< MSK_U32_ISM_LF5),
ISM_LF5_CMD_02 = ((IDX_U32_ISM_LF5 ==  2)<< MSK_U32_ISM_LF5),
ISM_LF5_CMD_03 = ((IDX_U32_ISM_LF5 ==  3)<< MSK_U32_ISM_LF5),
ISM_LF5_CMD_04 = ((IDX_U32_ISM_LF5 ==  4)<< MSK_U32_ISM_LF5),
ISM_LF5_CMD_05 = ((IDX_U32_ISM_LF5 ==  5)<< MSK_U32_ISM_LF5),
ISM_LF5_CMD_06 = ((IDX_U32_ISM_LF5 ==  6)<< MSK_U32_ISM_LF5),
ISM_LF5_CMD_07 = ((IDX_U32_ISM_LF5 ==  7)<< MSK_U32_ISM_LF5),
ISM_LF5_CMD_08 = ((IDX_U32_ISM_LF5 ==  8)<< MSK_U32_ISM_LF5),
ISM_LF5_CMD_09 = ((IDX_U32_ISM_LF5 ==  9)<< MSK_U32_ISM_LF5),
ISM_LF5_CMD_10 = ((IDX_U32_ISM_LF5 == 10)<< MSK_U32_ISM_LF5),
ISM_LF5_CMD_11 = ((IDX_U32_ISM_LF5 == 11)<< MSK_U32_ISM_LF5),
ISM_LF5_CMD_12 = ((IDX_U32_ISM_LF5 == 12)<< MSK_U32_ISM_LF5),
                    
                    
ISM_LF6_CMD_00 = ((IDX_U32_ISM_LF6 ==  0)<< MSK_U32_ISM_LF6),
ISM_LF6_CMD_01 = ((IDX_U32_ISM_LF6 ==  1)<< MSK_U32_ISM_LF6),
ISM_LF6_CMD_02 = ((IDX_U32_ISM_LF6 ==  2)<< MSK_U32_ISM_LF6),
ISM_LF6_CMD_03 = ((IDX_U32_ISM_LF6 ==  3)<< MSK_U32_ISM_LF6),
ISM_LF6_CMD_04 = ((IDX_U32_ISM_LF6 ==  4)<< MSK_U32_ISM_LF6),
ISM_LF6_CMD_05 = ((IDX_U32_ISM_LF6 ==  5)<< MSK_U32_ISM_LF6),
ISM_LF6_CMD_06 = ((IDX_U32_ISM_LF6 ==  6)<< MSK_U32_ISM_LF6),
ISM_LF6_CMD_07 = ((IDX_U32_ISM_LF6 ==  7)<< MSK_U32_ISM_LF6),
ISM_LF6_CMD_08 = ((IDX_U32_ISM_LF6 ==  8)<< MSK_U32_ISM_LF6),
ISM_LF6_CMD_09 = ((IDX_U32_ISM_LF6 ==  9)<< MSK_U32_ISM_LF6),
ISM_LF6_CMD_10 = ((IDX_U32_ISM_LF6 == 10)<< MSK_U32_ISM_LF6),
ISM_LF6_CMD_11 = ((IDX_U32_ISM_LF6 == 11)<< MSK_U32_ISM_LF6),
ISM_LF6_CMD_12 = ((IDX_U32_ISM_LF6 == 12)<< MSK_U32_ISM_LF6),

ISM_LF7_CMD_00 = ((IDX_U32_ISM_LF7  ==  0)<< MSK_U32_ISM_LF7 ),
ISM_LF7_CMD_01 = ((IDX_U32_ISM_LF7  ==  1)<< MSK_U32_ISM_LF7 ),
ISM_LF7_CMD_02 = ((IDX_U32_ISM_LF7  ==  2)<< MSK_U32_ISM_LF7 ),
ISM_LF7_CMD_03 = ((IDX_U32_ISM_LF7  ==  3)<< MSK_U32_ISM_LF7 ),
ISM_LF7_CMD_04 = ((IDX_U32_ISM_LF7  ==  4)<< MSK_U32_ISM_LF7 ),
ISM_LF7_CMD_05 = ((IDX_U32_ISM_LF7  ==  5)<< MSK_U32_ISM_LF7 ),
ISM_LF7_CMD_06 = ((IDX_U32_ISM_LF7  ==  6)<< MSK_U32_ISM_LF7 ),
ISM_LF7_CMD_07 = ((IDX_U32_ISM_LF7  ==  7)<< MSK_U32_ISM_LF7 ),
ISM_LF7_CMD_08 = ((IDX_U32_ISM_LF7  ==  8)<< MSK_U32_ISM_LF7 ),
ISM_LF7_CMD_09 = ((IDX_U32_ISM_LF7  ==  9)<< MSK_U32_ISM_LF7 ),
ISM_LF7_CMD_10 = ((IDX_U32_ISM_LF7  == 10)<< MSK_U32_ISM_LF7 ),
ISM_LF7_CMD_11 = ((IDX_U32_ISM_LF7  == 11)<< MSK_U32_ISM_LF7 ),
ISM_LF7_CMD_12 = ((IDX_U32_ISM_LF7  == 12)<< MSK_U32_ISM_LF7 ),
                    
                    
ISM_LF8_CMD_00 = ((IDX_U32_ISM_LF8  ==  0)<< MSK_U32_ISM_LF8 ),
ISM_LF8_CMD_01 = ((IDX_U32_ISM_LF8  ==  1)<< MSK_U32_ISM_LF8 ),
ISM_LF8_CMD_02 = ((IDX_U32_ISM_LF8  ==  2)<< MSK_U32_ISM_LF8 ),
ISM_LF8_CMD_03 = ((IDX_U32_ISM_LF8  ==  3)<< MSK_U32_ISM_LF8 ),
ISM_LF8_CMD_04 = ((IDX_U32_ISM_LF8  ==  4)<< MSK_U32_ISM_LF8 ),
ISM_LF8_CMD_05 = ((IDX_U32_ISM_LF8  ==  5)<< MSK_U32_ISM_LF8 ),
ISM_LF8_CMD_06 = ((IDX_U32_ISM_LF8  ==  6)<< MSK_U32_ISM_LF8 ),
ISM_LF8_CMD_07 = ((IDX_U32_ISM_LF8  ==  7)<< MSK_U32_ISM_LF8 ),
ISM_LF8_CMD_08 = ((IDX_U32_ISM_LF8  ==  8)<< MSK_U32_ISM_LF8 ),
ISM_LF8_CMD_09 = ((IDX_U32_ISM_LF8  ==  9)<< MSK_U32_ISM_LF8 ),
ISM_LF8_CMD_10 = ((IDX_U32_ISM_LF8  == 10)<< MSK_U32_ISM_LF8 ),
ISM_LF8_CMD_11 = ((IDX_U32_ISM_LF8  == 11)<< MSK_U32_ISM_LF8 ),
ISM_LF8_CMD_12 = ((IDX_U32_ISM_LF8  == 12)<< MSK_U32_ISM_LF8 ),
                    
                    
ISM_LF9_CMD_00 = ((IDX_U32_ISM_LF9 ==  0)<< MSK_U32_ISM_LF9 ),
ISM_LF9_CMD_01 = ((IDX_U32_ISM_LF9 ==  1)<< MSK_U32_ISM_LF9 ),
ISM_LF9_CMD_02 = ((IDX_U32_ISM_LF9 ==  2)<< MSK_U32_ISM_LF9 ),
ISM_LF9_CMD_03 = ((IDX_U32_ISM_LF9 ==  3)<< MSK_U32_ISM_LF9 ),
ISM_LF9_CMD_04 = ((IDX_U32_ISM_LF9 ==  4)<< MSK_U32_ISM_LF9 ),
ISM_LF9_CMD_05 = ((IDX_U32_ISM_LF9 ==  5)<< MSK_U32_ISM_LF9 ),
ISM_LF9_CMD_06 = ((IDX_U32_ISM_LF9 ==  6)<< MSK_U32_ISM_LF9 ),
ISM_LF9_CMD_07 = ((IDX_U32_ISM_LF9 ==  7)<< MSK_U32_ISM_LF9 ),
ISM_LF9_CMD_08 = ((IDX_U32_ISM_LF9 ==  8)<< MSK_U32_ISM_LF9 ),
ISM_LF9_CMD_09 = ((IDX_U32_ISM_LF9 ==  9)<< MSK_U32_ISM_LF9 ),
ISM_LF9_CMD_10 = ((IDX_U32_ISM_LF9 == 10)<< MSK_U32_ISM_LF9 ),
ISM_LF9_CMD_11 = ((IDX_U32_ISM_LF9 == 11)<< MSK_U32_ISM_LF9 ),
ISM_LF9_CMD_12 = ((IDX_U32_ISM_LF9 == 12)<< MSK_U32_ISM_LF9 ),
                    
                    
ISM_LF10_CMD_00 = ((IDX_U32_ISM_LF10 ==  0)<< MSK_U32_ISM_LF10),
ISM_LF10_CMD_01 = ((IDX_U32_ISM_LF10 ==  1)<< MSK_U32_ISM_LF10),
ISM_LF10_CMD_02 = ((IDX_U32_ISM_LF10 ==  2)<< MSK_U32_ISM_LF10),
ISM_LF10_CMD_03 = ((IDX_U32_ISM_LF10 ==  3)<< MSK_U32_ISM_LF10),
ISM_LF10_CMD_04 = ((IDX_U32_ISM_LF10 ==  4)<< MSK_U32_ISM_LF10),
ISM_LF10_CMD_05 = ((IDX_U32_ISM_LF10 ==  5)<< MSK_U32_ISM_LF10),
ISM_LF10_CMD_06 = ((IDX_U32_ISM_LF10 ==  6)<< MSK_U32_ISM_LF10),
ISM_LF10_CMD_07 = ((IDX_U32_ISM_LF10 ==  7)<< MSK_U32_ISM_LF10),
ISM_LF10_CMD_08 = ((IDX_U32_ISM_LF10 ==  8)<< MSK_U32_ISM_LF10),
ISM_LF10_CMD_09 = ((IDX_U32_ISM_LF10 ==  9)<< MSK_U32_ISM_LF10),
ISM_LF10_CMD_10 = ((IDX_U32_ISM_LF10 == 10)<< MSK_U32_ISM_LF10),
ISM_LF10_CMD_11 = ((IDX_U32_ISM_LF10 == 11)<< MSK_U32_ISM_LF10),
ISM_LF10_CMD_12 = ((IDX_U32_ISM_LF10 == 12)<< MSK_U32_ISM_LF10),

ISM_LF11_CMD_00 = ((IDX_U32_ISM_LF11 ==  0)<< MSK_U32_ISM_LF11),
ISM_LF11_CMD_01 = ((IDX_U32_ISM_LF11 ==  1)<< MSK_U32_ISM_LF11),
ISM_LF11_CMD_02 = ((IDX_U32_ISM_LF11 ==  2)<< MSK_U32_ISM_LF11),
ISM_LF11_CMD_03 = ((IDX_U32_ISM_LF11 ==  3)<< MSK_U32_ISM_LF11),
ISM_LF11_CMD_04 = ((IDX_U32_ISM_LF11 ==  4)<< MSK_U32_ISM_LF11),
ISM_LF11_CMD_05 = ((IDX_U32_ISM_LF11 ==  5)<< MSK_U32_ISM_LF11),
ISM_LF11_CMD_06 = ((IDX_U32_ISM_LF11 ==  6)<< MSK_U32_ISM_LF11),
ISM_LF11_CMD_07 = ((IDX_U32_ISM_LF11 ==  7)<< MSK_U32_ISM_LF11),
ISM_LF11_CMD_08 = ((IDX_U32_ISM_LF11 ==  8)<< MSK_U32_ISM_LF11),
ISM_LF11_CMD_09 = ((IDX_U32_ISM_LF11 ==  9)<< MSK_U32_ISM_LF11),
ISM_LF11_CMD_10 = ((IDX_U32_ISM_LF11 == 10)<< MSK_U32_ISM_LF11),
ISM_LF11_CMD_11 = ((IDX_U32_ISM_LF11 == 11)<< MSK_U32_ISM_LF11),
ISM_LF11_CMD_12 = ((IDX_U32_ISM_LF11 == 12)<< MSK_U32_ISM_LF11),
                    
                    
ISM_LF12_CMD_00 = ((IDX_U32_ISM_LF12 ==  0)<< MSK_U32_ISM_LF12),
ISM_LF12_CMD_01 = ((IDX_U32_ISM_LF12 ==  1)<< MSK_U32_ISM_LF12),
ISM_LF12_CMD_02 = ((IDX_U32_ISM_LF12 ==  2)<< MSK_U32_ISM_LF12),
ISM_LF12_CMD_03 = ((IDX_U32_ISM_LF12 ==  3)<< MSK_U32_ISM_LF12),
ISM_LF12_CMD_04 = ((IDX_U32_ISM_LF12 ==  4)<< MSK_U32_ISM_LF12),
ISM_LF12_CMD_05 = ((IDX_U32_ISM_LF12 ==  5)<< MSK_U32_ISM_LF12),
ISM_LF12_CMD_06 = ((IDX_U32_ISM_LF12 ==  6)<< MSK_U32_ISM_LF12),
ISM_LF12_CMD_07 = ((IDX_U32_ISM_LF12 ==  7)<< MSK_U32_ISM_LF12),
ISM_LF12_CMD_08 = ((IDX_U32_ISM_LF12 ==  8)<< MSK_U32_ISM_LF12),
ISM_LF12_CMD_09 = ((IDX_U32_ISM_LF12 ==  9)<< MSK_U32_ISM_LF12),
ISM_LF12_CMD_10 = ((IDX_U32_ISM_LF12 == 10)<< MSK_U32_ISM_LF12),
ISM_LF12_CMD_11 = ((IDX_U32_ISM_LF12 == 11)<< MSK_U32_ISM_LF12),
ISM_LF12_CMD_12 = ((IDX_U32_ISM_LF12 == 12)<< MSK_U32_ISM_LF12),
                    
                    
ISM_LF13_CMD_00 = ((IDX_U32_ISM_LF13 ==  0)<< MSK_U32_ISM_LF13),
ISM_LF13_CMD_01 = ((IDX_U32_ISM_LF13 ==  1)<< MSK_U32_ISM_LF13),
ISM_LF13_CMD_02 = ((IDX_U32_ISM_LF13 ==  2)<< MSK_U32_ISM_LF13),
ISM_LF13_CMD_03 = ((IDX_U32_ISM_LF13 ==  3)<< MSK_U32_ISM_LF13),
ISM_LF13_CMD_04 = ((IDX_U32_ISM_LF13 ==  4)<< MSK_U32_ISM_LF13),
ISM_LF13_CMD_05 = ((IDX_U32_ISM_LF13 ==  5)<< MSK_U32_ISM_LF13),
ISM_LF13_CMD_06 = ((IDX_U32_ISM_LF13 ==  6)<< MSK_U32_ISM_LF13),
ISM_LF13_CMD_07 = ((IDX_U32_ISM_LF13 ==  7)<< MSK_U32_ISM_LF13),
ISM_LF13_CMD_08 = ((IDX_U32_ISM_LF13 ==  8)<< MSK_U32_ISM_LF13),
ISM_LF13_CMD_09 = ((IDX_U32_ISM_LF13 ==  9)<< MSK_U32_ISM_LF13),
ISM_LF13_CMD_10 = ((IDX_U32_ISM_LF13 == 10)<< MSK_U32_ISM_LF13),
ISM_LF13_CMD_11 = ((IDX_U32_ISM_LF13 == 11)<< MSK_U32_ISM_LF13),
ISM_LF13_CMD_12 = ((IDX_U32_ISM_LF13 == 12)<< MSK_U32_ISM_LF13),
                    
                    
ISM_LF14_CMD_00 = ((IDX_U32_ISM_LF14 ==  0)<< MSK_U32_ISM_LF14),
ISM_LF14_CMD_01 = ((IDX_U32_ISM_LF14 ==  1)<< MSK_U32_ISM_LF14),
ISM_LF14_CMD_02 = ((IDX_U32_ISM_LF14 ==  2)<< MSK_U32_ISM_LF14),
ISM_LF14_CMD_03 = ((IDX_U32_ISM_LF14 ==  3)<< MSK_U32_ISM_LF14),
ISM_LF14_CMD_04 = ((IDX_U32_ISM_LF14 ==  4)<< MSK_U32_ISM_LF14),
ISM_LF14_CMD_05 = ((IDX_U32_ISM_LF14 ==  5)<< MSK_U32_ISM_LF14),
ISM_LF14_CMD_06 = ((IDX_U32_ISM_LF14 ==  6)<< MSK_U32_ISM_LF14),
ISM_LF14_CMD_07 = ((IDX_U32_ISM_LF14 ==  7)<< MSK_U32_ISM_LF14),
ISM_LF14_CMD_08 = ((IDX_U32_ISM_LF14 ==  8)<< MSK_U32_ISM_LF14),
ISM_LF14_CMD_09 = ((IDX_U32_ISM_LF14 ==  9)<< MSK_U32_ISM_LF14),
ISM_LF14_CMD_10 = ((IDX_U32_ISM_LF14 == 10)<< MSK_U32_ISM_LF14),
ISM_LF14_CMD_11 = ((IDX_U32_ISM_LF14 == 11)<< MSK_U32_ISM_LF14),
ISM_LF14_CMD_12 = ((IDX_U32_ISM_LF14 == 12)<< MSK_U32_ISM_LF14),

ISM_LF15_CMD_00 = ((IDX_U32_ISM_LF15 ==  0)<< MSK_U32_ISM_LF15),
ISM_LF15_CMD_01 = ((IDX_U32_ISM_LF15 ==  1)<< MSK_U32_ISM_LF15),
ISM_LF15_CMD_02 = ((IDX_U32_ISM_LF15 ==  2)<< MSK_U32_ISM_LF15),
ISM_LF15_CMD_03 = ((IDX_U32_ISM_LF15 ==  3)<< MSK_U32_ISM_LF15),
ISM_LF15_CMD_04 = ((IDX_U32_ISM_LF15 ==  4)<< MSK_U32_ISM_LF15),
ISM_LF15_CMD_05 = ((IDX_U32_ISM_LF15 ==  5)<< MSK_U32_ISM_LF15),
ISM_LF15_CMD_06 = ((IDX_U32_ISM_LF15 ==  6)<< MSK_U32_ISM_LF15),
ISM_LF15_CMD_07 = ((IDX_U32_ISM_LF15 ==  7)<< MSK_U32_ISM_LF15),
ISM_LF15_CMD_08 = ((IDX_U32_ISM_LF15 ==  8)<< MSK_U32_ISM_LF15),
ISM_LF15_CMD_09 = ((IDX_U32_ISM_LF15 ==  9)<< MSK_U32_ISM_LF15),
ISM_LF15_CMD_10 = ((IDX_U32_ISM_LF15 == 10)<< MSK_U32_ISM_LF15),
ISM_LF15_CMD_11 = ((IDX_U32_ISM_LF15 == 11)<< MSK_U32_ISM_LF15),
ISM_LF15_CMD_12 = ((IDX_U32_ISM_LF15 == 12)<< MSK_U32_ISM_LF15),
                    
                   
ISM_LF16_CMD_00 = ((IDX_U32_ISM_LF16 ==  0)<< MSK_U32_ISM_LF16),
ISM_LF16_CMD_01 = ((IDX_U32_ISM_LF16 ==  1)<< MSK_U32_ISM_LF16),
ISM_LF16_CMD_02 = ((IDX_U32_ISM_LF16 ==  2)<< MSK_U32_ISM_LF16),
ISM_LF16_CMD_03 = ((IDX_U32_ISM_LF16 ==  3)<< MSK_U32_ISM_LF16),
ISM_LF16_CMD_04 = ((IDX_U32_ISM_LF16 ==  4)<< MSK_U32_ISM_LF16),
ISM_LF16_CMD_05 = ((IDX_U32_ISM_LF16 ==  5)<< MSK_U32_ISM_LF16),
ISM_LF16_CMD_06 = ((IDX_U32_ISM_LF16 ==  6)<< MSK_U32_ISM_LF16),
ISM_LF16_CMD_07 = ((IDX_U32_ISM_LF16 ==  7)<< MSK_U32_ISM_LF16),
ISM_LF16_CMD_08 = ((IDX_U32_ISM_LF16 ==  8)<< MSK_U32_ISM_LF16),
ISM_LF16_CMD_09 = ((IDX_U32_ISM_LF16 ==  9)<< MSK_U32_ISM_LF16),
ISM_LF16_CMD_10 = ((IDX_U32_ISM_LF16 == 10)<< MSK_U32_ISM_LF16),
ISM_LF16_CMD_11 = ((IDX_U32_ISM_LF16 == 11)<< MSK_U32_ISM_LF16),
ISM_LF16_CMD_12 = ((IDX_U32_ISM_LF16 == 12)<< MSK_U32_ISM_LF16),

INPUT_SIGNALS_MASK_CMD_00 = (
ISM_BLOCK_VKL_VVO_CMD_01
|ISM_BLOCK_VKL_VVP_CMD_01
|ISM_RESET_LEDS_CMD_01
|ISM_RESET_RELES_CMD_01
|ISM_MISCEVE_DYSTANCIJNE_CMD_01
|ISM_STATE_VVR_CMD_01
|ISM_STATE_VVO_CMD_01
|ISM_VKL_VVO_CMD_01
|ISM_VKL_VVR_CMD_01
|ISM_CTRL_VKL_VVO_CMD_01
|ISM_CTRL_VKL_VVR_CMD_01
|ISM_OTKL_VV_VVO_CMD_01
|ISM_OTKL_VV_VVR_CMD_01
|ISM_CTRL_OTKL_VVO_CMD_01
|ISM_CTRL_OTKL_VVR_CMD_01
//|ISM_1_GRUPA_USTAVOK_CMD_01
//|ISM_2_GRUPA_USTAVOK_CMD_01
//|ISM_3_GRUPA_USTAVOK_CMD_01
//|ISM_4_GRUPA_USTAVOK_CMD_01
|ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV_CMD_01
|ISM_ZVN_NESPR_DZO_CMD_01
|ISM_ZBR_BLOCK_DZO1_I_O_3G_CMD_01
|ISM_ZBR_BLOCK_DZO1_I_O_CMD_01
|ISM_BLOCK_DZO1_CMD_01
|ISM_BLOCK_PR_DZO2_CMD_01
|ISM_OP_PR_DZO2_CMD_01
|ISM_ZBR_BLOCK_DZO2_I_O_3G_CMD_01
|ISM_BLOCK_DZO2_CMD_01
|ISM_BLOCK_PR_DZO3_CMD_01
|ISM_OP_PR_DZO3_CMD_01
|ISM_ZBR_BLOCK_DZO3_I_O_3G_CMD_01
|ISM_BLOCK_DZO3_CMD_01
|ISM_ZBR_BLOCK_DZO4_I_O_3G_CMD_01
|ISM_BLOCK_DZO4_CMD_01
|ISM_BLOCK_ZDZ_CMD_01
|ISM_PUSK_ZDZ_VID_DV_CMD_01
|ISM_BLOCK_MCZO1_CMD_01
|ISM_BLOCK_MCZO2_CMD_01
|ISM_BLOCK_PR_MCZO2_CMD_01
|ISM_BLOCK_MCZO3_CMD_01
|ISM_BLOCK_MCZO4_CMD_01
|ISM_BLOCK_MCZR1_CMD_01
|ISM_BLOCK_MCZR2_CMD_01
|ISM_STAT_BLK_APV_CMD_01
|ISM_ACHR_CHAPV_VID_DV_CMD_01
|ISM_BLOCK_ACHR1_CMD_01
|ISM_BLOCK_ACHR2_CMD_01
|ISM_PUSK_UROV_VID_DV_CMD_01
|ISM_ZVN_NESPR_DZR_CMD_01
|ISM_ZBR_BLOCK_DZR1_I_R_3G_CMD_01
|ISM_ZBR_BLOCK_DZR1_I_R_CMD_01
|ISM_BLOCK_DZR1_CMD_01
|ISM_BLOCK_PR_DZR2_CMD_01
|ISM_OP_PR_DZR2_CMD_01
|ISM_ZBR_BLOCK_DZR2_I_R_3G_CMD_01
|ISM_BLOCK_DZR2_CMD_01
|ISM_BLOCK_PR_DZR3_CMD_01
|ISM_OP_PR_DZR3_CMD_01
|ISM_ZBR_BLOCK_DZR3_I_R_3G_CMD_01
|ISM_BLOCK_DZR3_CMD_01
|ISM_BLOCK_UMIN1_CMD_01
|ISM_START_UMIN1_CMD_01
|ISM_BLOCK_UMIN2_CMD_01
|ISM_START_UMIN2_CMD_01
|ISM_BLOCK_UMAX1_CMD_01
|ISM_BLOCK_UMAX2_CMD_01
|ISM_BLOCK_UP1_CMD_01
|ISM_BLOCK_UP2_CMD_01
|ISM_BLOCK_UP3_CMD_01
|ISM_BLOCK_UP4_CMD_01
|ISM_BLOCK_UP5_CMD_01
|ISM_BLOCK_UP6_CMD_01
|ISM_BLOCK_UP7_CMD_01
|ISM_BLOCK_UP8_CMD_01
|ISM_DF1_IN_CMD_01
|ISM_DF2_IN_CMD_01
|ISM_DF3_IN_CMD_01
|ISM_DF4_IN_CMD_01
|ISM_DF5_IN_CMD_01
|ISM_DF6_IN_CMD_01
|ISM_DF7_IN_CMD_01
|ISM_DF8_IN_CMD_01
|ISM_DF9_IN_CMD_01
|ISM_DF10_IN_CMD_01
|ISM_DF11_IN_CMD_01
|ISM_DF12_IN_CMD_01
|ISM_DF13_IN_CMD_01
|ISM_DF14_IN_CMD_01
|ISM_DF15_IN_CMD_01
|ISM_DF16_IN_CMD_01
|ISM_DT1_SET_CMD_01
|ISM_DT1_RESET_CMD_01
|ISM_DT2_SET_CMD_01
|ISM_DT2_RESET_CMD_01
|ISM_DT3_SET_CMD_01
|ISM_DT3_RESET_CMD_01
|ISM_DT4_SET_CMD_01
|ISM_DT4_RESET_CMD_01
|ISM_LF1_CMD_01
|ISM_LF2_CMD_01
|ISM_LF3_CMD_01
|ISM_LF4_CMD_01
|ISM_LF5_CMD_01
|ISM_LF6_CMD_01
|ISM_LF7_CMD_01
|ISM_LF8_CMD_01
|ISM_LF9_CMD_01
|ISM_LF10_CMD_01
|ISM_LF11_CMD_01
|ISM_LF12_CMD_01
|ISM_LF13_CMD_01
|ISM_LF14_CMD_01
|ISM_LF15_CMD_01
|ISM_LF16_CMD_01

),

INPUT_SIGNALS_MASK_CMD_01 = (
ISM_BLOCK_VKL_VVO_CMD_01
|ISM_BLOCK_VKL_VVP_CMD_01
|ISM_RESET_LEDS_CMD_01
|ISM_RESET_RELES_CMD_01
|ISM_MISCEVE_DYSTANCIJNE_CMD_01
|ISM_STATE_VVR_CMD_01
|ISM_STATE_VVO_CMD_01
|ISM_VKL_VVO_CMD_01
|ISM_VKL_VVR_CMD_01
|ISM_CTRL_VKL_VVO_CMD_01
|ISM_CTRL_VKL_VVR_CMD_01
|ISM_OTKL_VV_VVO_CMD_01
|ISM_OTKL_VV_VVR_CMD_01
|ISM_CTRL_OTKL_VVO_CMD_01
|ISM_CTRL_OTKL_VVR_CMD_01
//|ISM_1_GRUPA_USTAVOK_CMD_01
//|ISM_2_GRUPA_USTAVOK_CMD_01
//|ISM_3_GRUPA_USTAVOK_CMD_01
//|ISM_4_GRUPA_USTAVOK_CMD_01
|ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV_CMD_01
|ISM_ZVN_NESPR_DZO_CMD_01
|ISM_ZBR_BLOCK_DZO1_I_O_3G_CMD_01
|ISM_ZBR_BLOCK_DZO1_I_O_CMD_01
|ISM_BLOCK_DZO1_CMD_01
|ISM_BLOCK_PR_DZO2_CMD_01
|ISM_OP_PR_DZO2_CMD_01
|ISM_ZBR_BLOCK_DZO2_I_O_3G_CMD_01
|ISM_BLOCK_DZO2_CMD_01
|ISM_BLOCK_PR_DZO3_CMD_01
|ISM_OP_PR_DZO3_CMD_01
|ISM_ZBR_BLOCK_DZO3_I_O_3G_CMD_01
|ISM_BLOCK_DZO3_CMD_01
|ISM_ZBR_BLOCK_DZO4_I_O_3G_CMD_01
|ISM_BLOCK_DZO4_CMD_01
|ISM_BLOCK_ZDZ_CMD_01
|ISM_PUSK_ZDZ_VID_DV_CMD_01
|ISM_BLOCK_MCZO1_CMD_01
|ISM_BLOCK_MCZO2_CMD_01
|ISM_BLOCK_PR_MCZO2_CMD_01
|ISM_BLOCK_MCZO3_CMD_01
|ISM_BLOCK_MCZO4_CMD_01
|ISM_BLOCK_MCZR1_CMD_01
|ISM_BLOCK_MCZR2_CMD_01
|ISM_STAT_BLK_APV_CMD_01
|ISM_ACHR_CHAPV_VID_DV_CMD_01
|ISM_BLOCK_ACHR1_CMD_01
|ISM_BLOCK_ACHR2_CMD_01
|ISM_PUSK_UROV_VID_DV_CMD_01
|ISM_ZVN_NESPR_DZR_CMD_01
|ISM_ZBR_BLOCK_DZR1_I_R_3G_CMD_01
|ISM_ZBR_BLOCK_DZR1_I_R_CMD_01
|ISM_BLOCK_DZR1_CMD_01
|ISM_BLOCK_PR_DZR2_CMD_01
|ISM_OP_PR_DZR2_CMD_01
|ISM_ZBR_BLOCK_DZR2_I_R_3G_CMD_01
|ISM_BLOCK_DZR2_CMD_01
|ISM_BLOCK_PR_DZR3_CMD_01
|ISM_OP_PR_DZR3_CMD_01
|ISM_ZBR_BLOCK_DZR3_I_R_3G_CMD_01
|ISM_BLOCK_DZR3_CMD_01
|ISM_BLOCK_UMIN1_CMD_01
|ISM_START_UMIN1_CMD_01
|ISM_BLOCK_UMIN2_CMD_01
|ISM_START_UMIN2_CMD_01
|ISM_BLOCK_UMAX1_CMD_01
|ISM_BLOCK_UMAX2_CMD_01
|ISM_BLOCK_UP1_CMD_01
|ISM_BLOCK_UP2_CMD_01
|ISM_BLOCK_UP3_CMD_01
|ISM_BLOCK_UP4_CMD_01
|ISM_BLOCK_UP5_CMD_01
|ISM_BLOCK_UP6_CMD_01
|ISM_BLOCK_UP7_CMD_01
|ISM_BLOCK_UP8_CMD_01
|ISM_DF1_IN_CMD_01
|ISM_DF2_IN_CMD_01
|ISM_DF3_IN_CMD_01
|ISM_DF4_IN_CMD_01
|ISM_DF5_IN_CMD_01
|ISM_DF6_IN_CMD_01
|ISM_DF7_IN_CMD_01
|ISM_DF8_IN_CMD_01
|ISM_DF9_IN_CMD_01
|ISM_DF10_IN_CMD_01
|ISM_DF11_IN_CMD_01
|ISM_DF12_IN_CMD_01
|ISM_DF13_IN_CMD_01
|ISM_DF14_IN_CMD_01
|ISM_DF15_IN_CMD_01
|ISM_DF16_IN_CMD_01
|ISM_DT1_SET_CMD_01
|ISM_DT1_RESET_CMD_01
|ISM_DT2_SET_CMD_01
|ISM_DT2_RESET_CMD_01
|ISM_DT3_SET_CMD_01
|ISM_DT3_RESET_CMD_01
|ISM_DT4_SET_CMD_01
|ISM_DT4_RESET_CMD_01
|ISM_LF1_CMD_01
|ISM_LF2_CMD_01
|ISM_LF3_CMD_01
|ISM_LF4_CMD_01
|ISM_LF5_CMD_01
|ISM_LF6_CMD_01
|ISM_LF7_CMD_01
|ISM_LF8_CMD_01
|ISM_LF9_CMD_01
|ISM_LF10_CMD_01
|ISM_LF11_CMD_01
|ISM_LF12_CMD_01
|ISM_LF13_CMD_01
|ISM_LF14_CMD_01
|ISM_LF15_CMD_01
|ISM_LF16_CMD_01

),
INPUT_SIGNALS_MASK_CMD_02 = (
ISM_BLOCK_VKL_VVO_CMD_02
|ISM_BLOCK_VKL_VVP_CMD_02
|ISM_RESET_LEDS_CMD_02
|ISM_RESET_RELES_CMD_02
|ISM_MISCEVE_DYSTANCIJNE_CMD_02
|ISM_STATE_VVR_CMD_02
|ISM_STATE_VVO_CMD_02
|ISM_VKL_VVO_CMD_02
|ISM_VKL_VVR_CMD_02
|ISM_CTRL_VKL_VVO_CMD_02
|ISM_CTRL_VKL_VVR_CMD_02
|ISM_OTKL_VV_VVO_CMD_02
|ISM_OTKL_VV_VVR_CMD_02
|ISM_CTRL_OTKL_VVO_CMD_02
|ISM_CTRL_OTKL_VVR_CMD_02
//|ISM_1_GRUPA_USTAVOK_CMD_02
//|ISM_2_GRUPA_USTAVOK_CMD_02
//|ISM_3_GRUPA_USTAVOK_CMD_02
//|ISM_4_GRUPA_USTAVOK_CMD_02
|ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV_CMD_02
|ISM_ZVN_NESPR_DZO_CMD_02
|ISM_ZBR_BLOCK_DZO1_I_O_3G_CMD_02
|ISM_ZBR_BLOCK_DZO1_I_O_CMD_02
|ISM_BLOCK_DZO1_CMD_02
|ISM_BLOCK_PR_DZO2_CMD_02
|ISM_OP_PR_DZO2_CMD_02
|ISM_ZBR_BLOCK_DZO2_I_O_3G_CMD_02
|ISM_BLOCK_DZO2_CMD_02
|ISM_BLOCK_PR_DZO3_CMD_02
|ISM_OP_PR_DZO3_CMD_02
|ISM_ZBR_BLOCK_DZO3_I_O_3G_CMD_02
|ISM_BLOCK_DZO3_CMD_02
|ISM_ZBR_BLOCK_DZO4_I_O_3G_CMD_02
|ISM_BLOCK_DZO4_CMD_02
|ISM_BLOCK_ZDZ_CMD_02
|ISM_PUSK_ZDZ_VID_DV_CMD_02
|ISM_BLOCK_MCZO1_CMD_02
|ISM_BLOCK_MCZO2_CMD_02
|ISM_BLOCK_PR_MCZO2_CMD_02
|ISM_BLOCK_MCZO3_CMD_02
|ISM_BLOCK_MCZO4_CMD_02
|ISM_BLOCK_MCZR1_CMD_02
|ISM_BLOCK_MCZR2_CMD_02
|ISM_STAT_BLK_APV_CMD_02
|ISM_ACHR_CHAPV_VID_DV_CMD_02
|ISM_BLOCK_ACHR1_CMD_02
|ISM_BLOCK_ACHR2_CMD_02
|ISM_PUSK_UROV_VID_DV_CMD_02
|ISM_ZVN_NESPR_DZR_CMD_02
|ISM_ZBR_BLOCK_DZR1_I_R_3G_CMD_02
|ISM_ZBR_BLOCK_DZR1_I_R_CMD_02
|ISM_BLOCK_DZR1_CMD_02
|ISM_BLOCK_PR_DZR2_CMD_02
|ISM_OP_PR_DZR2_CMD_02
|ISM_ZBR_BLOCK_DZR2_I_R_3G_CMD_02
|ISM_BLOCK_DZR2_CMD_02
|ISM_BLOCK_PR_DZR3_CMD_02
|ISM_OP_PR_DZR3_CMD_02
|ISM_ZBR_BLOCK_DZR3_I_R_3G_CMD_02
|ISM_BLOCK_DZR3_CMD_02
|ISM_BLOCK_UMIN1_CMD_02
|ISM_START_UMIN1_CMD_02
|ISM_BLOCK_UMIN2_CMD_02
|ISM_START_UMIN2_CMD_02
|ISM_BLOCK_UMAX1_CMD_02
|ISM_BLOCK_UMAX2_CMD_02
|ISM_BLOCK_UP1_CMD_02
|ISM_BLOCK_UP2_CMD_02
|ISM_BLOCK_UP3_CMD_02
|ISM_BLOCK_UP4_CMD_02
|ISM_BLOCK_UP5_CMD_02
|ISM_BLOCK_UP6_CMD_02
|ISM_BLOCK_UP7_CMD_02
|ISM_BLOCK_UP8_CMD_02
|ISM_DF1_IN_CMD_02
|ISM_DF2_IN_CMD_02
|ISM_DF3_IN_CMD_02
|ISM_DF4_IN_CMD_02
|ISM_DF5_IN_CMD_02
|ISM_DF6_IN_CMD_02
|ISM_DF7_IN_CMD_02
|ISM_DF8_IN_CMD_02
|ISM_DF9_IN_CMD_02
|ISM_DF10_IN_CMD_02
|ISM_DF11_IN_CMD_02
|ISM_DF12_IN_CMD_02
|ISM_DF13_IN_CMD_02
|ISM_DF14_IN_CMD_02
|ISM_DF15_IN_CMD_02
|ISM_DF16_IN_CMD_02
|ISM_DT1_SET_CMD_02
|ISM_DT1_RESET_CMD_02
|ISM_DT2_SET_CMD_02
|ISM_DT2_RESET_CMD_02
|ISM_DT3_SET_CMD_02
|ISM_DT3_RESET_CMD_02
|ISM_DT4_SET_CMD_02
|ISM_DT4_RESET_CMD_02
|ISM_LF1_CMD_02
|ISM_LF2_CMD_02
|ISM_LF3_CMD_02
|ISM_LF4_CMD_02
|ISM_LF5_CMD_02
|ISM_LF6_CMD_02
|ISM_LF7_CMD_02
|ISM_LF8_CMD_02
|ISM_LF9_CMD_02
|ISM_LF10_CMD_02
|ISM_LF11_CMD_02
|ISM_LF12_CMD_02
|ISM_LF13_CMD_02
|ISM_LF14_CMD_02
|ISM_LF15_CMD_02
|ISM_LF16_CMD_02

),

INPUT_SIGNALS_MASK_CMD_03 = (
ISM_BLOCK_VKL_VVO_CMD_03
|ISM_BLOCK_VKL_VVP_CMD_03
|ISM_RESET_LEDS_CMD_03
|ISM_RESET_RELES_CMD_03
|ISM_MISCEVE_DYSTANCIJNE_CMD_03
|ISM_STATE_VVR_CMD_03
|ISM_STATE_VVO_CMD_03
|ISM_VKL_VVO_CMD_03
|ISM_VKL_VVR_CMD_03
|ISM_CTRL_VKL_VVO_CMD_03
|ISM_CTRL_VKL_VVR_CMD_03
|ISM_OTKL_VV_VVO_CMD_03
|ISM_OTKL_VV_VVR_CMD_03
|ISM_CTRL_OTKL_VVO_CMD_03
|ISM_CTRL_OTKL_VVR_CMD_03
//|ISM_1_GRUPA_USTAVOK_CMD_03
//|ISM_2_GRUPA_USTAVOK_CMD_03
//|ISM_3_GRUPA_USTAVOK_CMD_03
//|ISM_4_GRUPA_USTAVOK_CMD_03
|ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV_CMD_03
|ISM_ZVN_NESPR_DZO_CMD_03
|ISM_ZBR_BLOCK_DZO1_I_O_3G_CMD_03
|ISM_ZBR_BLOCK_DZO1_I_O_CMD_03
|ISM_BLOCK_DZO1_CMD_03
|ISM_BLOCK_PR_DZO2_CMD_03
|ISM_OP_PR_DZO2_CMD_03
|ISM_ZBR_BLOCK_DZO2_I_O_3G_CMD_03
|ISM_BLOCK_DZO2_CMD_03
|ISM_BLOCK_PR_DZO3_CMD_03
|ISM_OP_PR_DZO3_CMD_03
|ISM_ZBR_BLOCK_DZO3_I_O_3G_CMD_03
|ISM_BLOCK_DZO3_CMD_03
|ISM_ZBR_BLOCK_DZO4_I_O_3G_CMD_03
|ISM_BLOCK_DZO4_CMD_03
|ISM_BLOCK_ZDZ_CMD_03
|ISM_PUSK_ZDZ_VID_DV_CMD_03
|ISM_BLOCK_MCZO1_CMD_03
|ISM_BLOCK_MCZO2_CMD_03
|ISM_BLOCK_PR_MCZO2_CMD_03
|ISM_BLOCK_MCZO3_CMD_03
|ISM_BLOCK_MCZO4_CMD_03
|ISM_BLOCK_MCZR1_CMD_03
|ISM_BLOCK_MCZR2_CMD_03
|ISM_STAT_BLK_APV_CMD_03
|ISM_ACHR_CHAPV_VID_DV_CMD_03
|ISM_BLOCK_ACHR1_CMD_03
|ISM_BLOCK_ACHR2_CMD_03
|ISM_PUSK_UROV_VID_DV_CMD_03
|ISM_ZVN_NESPR_DZR_CMD_03
|ISM_ZBR_BLOCK_DZR1_I_R_3G_CMD_03
|ISM_ZBR_BLOCK_DZR1_I_R_CMD_03
|ISM_BLOCK_DZR1_CMD_03
|ISM_BLOCK_PR_DZR2_CMD_03
|ISM_OP_PR_DZR2_CMD_03
|ISM_ZBR_BLOCK_DZR2_I_R_3G_CMD_03
|ISM_BLOCK_DZR2_CMD_03
|ISM_BLOCK_PR_DZR3_CMD_03
|ISM_OP_PR_DZR3_CMD_03
|ISM_ZBR_BLOCK_DZR3_I_R_3G_CMD_03
|ISM_BLOCK_DZR3_CMD_03
|ISM_BLOCK_UMIN1_CMD_03
|ISM_START_UMIN1_CMD_03
|ISM_BLOCK_UMIN2_CMD_03
|ISM_START_UMIN2_CMD_03
|ISM_BLOCK_UMAX1_CMD_03
|ISM_BLOCK_UMAX2_CMD_03
|ISM_BLOCK_UP1_CMD_03
|ISM_BLOCK_UP2_CMD_03
|ISM_BLOCK_UP3_CMD_03
|ISM_BLOCK_UP4_CMD_03
|ISM_BLOCK_UP5_CMD_03
|ISM_BLOCK_UP6_CMD_03
|ISM_BLOCK_UP7_CMD_03
|ISM_BLOCK_UP8_CMD_03
|ISM_DF1_IN_CMD_03
|ISM_DF2_IN_CMD_03
|ISM_DF3_IN_CMD_03
|ISM_DF4_IN_CMD_03
|ISM_DF5_IN_CMD_03
|ISM_DF6_IN_CMD_03
|ISM_DF7_IN_CMD_03
|ISM_DF8_IN_CMD_03
|ISM_DF9_IN_CMD_03
|ISM_DF10_IN_CMD_03
|ISM_DF11_IN_CMD_03
|ISM_DF12_IN_CMD_03
|ISM_DF13_IN_CMD_03
|ISM_DF14_IN_CMD_03
|ISM_DF15_IN_CMD_03
|ISM_DF16_IN_CMD_03
|ISM_DT1_SET_CMD_03
|ISM_DT1_RESET_CMD_03
|ISM_DT2_SET_CMD_03
|ISM_DT2_RESET_CMD_03
|ISM_DT3_SET_CMD_03
|ISM_DT3_RESET_CMD_03
|ISM_DT4_SET_CMD_03
|ISM_DT4_RESET_CMD_03
|ISM_LF1_CMD_03
|ISM_LF2_CMD_03
|ISM_LF3_CMD_03
|ISM_LF4_CMD_03
|ISM_LF5_CMD_03
|ISM_LF6_CMD_03
|ISM_LF7_CMD_03
|ISM_LF8_CMD_03
|ISM_LF9_CMD_03
|ISM_LF10_CMD_03
|ISM_LF11_CMD_03
|ISM_LF12_CMD_03
|ISM_LF13_CMD_03
|ISM_LF14_CMD_03
|ISM_LF15_CMD_03
|ISM_LF16_CMD_03

),
INPUT_SIGNALS_MASK_CMD_04 = (
ISM_BLOCK_VKL_VVO_CMD_04
|ISM_BLOCK_VKL_VVP_CMD_04
|ISM_RESET_LEDS_CMD_04
|ISM_RESET_RELES_CMD_04
|ISM_MISCEVE_DYSTANCIJNE_CMD_04
|ISM_STATE_VVR_CMD_04
|ISM_STATE_VVO_CMD_04
|ISM_VKL_VVO_CMD_04
|ISM_VKL_VVR_CMD_04
|ISM_CTRL_VKL_VVO_CMD_04
|ISM_CTRL_VKL_VVR_CMD_04
|ISM_OTKL_VV_VVO_CMD_04
|ISM_OTKL_VV_VVR_CMD_04
|ISM_CTRL_OTKL_VVO_CMD_04
|ISM_CTRL_OTKL_VVR_CMD_04
//|ISM_1_GRUPA_USTAVOK_CMD_04
//|ISM_2_GRUPA_USTAVOK_CMD_04
//|ISM_3_GRUPA_USTAVOK_CMD_04
//|ISM_4_GRUPA_USTAVOK_CMD_04
|ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV_CMD_04
|ISM_ZVN_NESPR_DZO_CMD_04
|ISM_ZBR_BLOCK_DZO1_I_O_3G_CMD_04
|ISM_ZBR_BLOCK_DZO1_I_O_CMD_04
|ISM_BLOCK_DZO1_CMD_04
|ISM_BLOCK_PR_DZO2_CMD_04
|ISM_OP_PR_DZO2_CMD_04
|ISM_ZBR_BLOCK_DZO2_I_O_3G_CMD_04
|ISM_BLOCK_DZO2_CMD_04
|ISM_BLOCK_PR_DZO3_CMD_04
|ISM_OP_PR_DZO3_CMD_04
|ISM_ZBR_BLOCK_DZO3_I_O_3G_CMD_04
|ISM_BLOCK_DZO3_CMD_04
|ISM_ZBR_BLOCK_DZO4_I_O_3G_CMD_04
|ISM_BLOCK_DZO4_CMD_04
|ISM_BLOCK_ZDZ_CMD_04
|ISM_PUSK_ZDZ_VID_DV_CMD_04
|ISM_BLOCK_MCZO1_CMD_04
|ISM_BLOCK_MCZO2_CMD_04
|ISM_BLOCK_PR_MCZO2_CMD_04
|ISM_BLOCK_MCZO3_CMD_04
|ISM_BLOCK_MCZO4_CMD_04
|ISM_BLOCK_MCZR1_CMD_04
|ISM_BLOCK_MCZR2_CMD_04
|ISM_STAT_BLK_APV_CMD_04
|ISM_ACHR_CHAPV_VID_DV_CMD_04
|ISM_BLOCK_ACHR1_CMD_04
|ISM_BLOCK_ACHR2_CMD_04
|ISM_PUSK_UROV_VID_DV_CMD_04
|ISM_ZVN_NESPR_DZR_CMD_04
|ISM_ZBR_BLOCK_DZR1_I_R_3G_CMD_04
|ISM_ZBR_BLOCK_DZR1_I_R_CMD_04
|ISM_BLOCK_DZR1_CMD_04
|ISM_BLOCK_PR_DZR2_CMD_04
|ISM_OP_PR_DZR2_CMD_04
|ISM_ZBR_BLOCK_DZR2_I_R_3G_CMD_04
|ISM_BLOCK_DZR2_CMD_04
|ISM_BLOCK_PR_DZR3_CMD_04
|ISM_OP_PR_DZR3_CMD_04
|ISM_ZBR_BLOCK_DZR3_I_R_3G_CMD_04
|ISM_BLOCK_DZR3_CMD_04
|ISM_BLOCK_UMIN1_CMD_04
|ISM_START_UMIN1_CMD_04
|ISM_BLOCK_UMIN2_CMD_04
|ISM_START_UMIN2_CMD_04
|ISM_BLOCK_UMAX1_CMD_04
|ISM_BLOCK_UMAX2_CMD_04
|ISM_BLOCK_UP1_CMD_04
|ISM_BLOCK_UP2_CMD_04
|ISM_BLOCK_UP3_CMD_04
|ISM_BLOCK_UP4_CMD_04
|ISM_BLOCK_UP5_CMD_04
|ISM_BLOCK_UP6_CMD_04
|ISM_BLOCK_UP7_CMD_04
|ISM_BLOCK_UP8_CMD_04
|ISM_DF1_IN_CMD_04
|ISM_DF2_IN_CMD_04
|ISM_DF3_IN_CMD_04
|ISM_DF4_IN_CMD_04
|ISM_DF5_IN_CMD_04
|ISM_DF6_IN_CMD_04
|ISM_DF7_IN_CMD_04
|ISM_DF8_IN_CMD_04
|ISM_DF9_IN_CMD_04
|ISM_DF10_IN_CMD_04
|ISM_DF11_IN_CMD_04
|ISM_DF12_IN_CMD_04
|ISM_DF13_IN_CMD_04
|ISM_DF14_IN_CMD_04
|ISM_DF15_IN_CMD_04
|ISM_DF16_IN_CMD_04
|ISM_DT1_SET_CMD_04
|ISM_DT1_RESET_CMD_04
|ISM_DT2_SET_CMD_04
|ISM_DT2_RESET_CMD_04
|ISM_DT3_SET_CMD_04
|ISM_DT3_RESET_CMD_04
|ISM_DT4_SET_CMD_04
|ISM_DT4_RESET_CMD_04
|ISM_LF1_CMD_04
|ISM_LF2_CMD_04
|ISM_LF3_CMD_04
|ISM_LF4_CMD_04
|ISM_LF5_CMD_04
|ISM_LF6_CMD_04
|ISM_LF7_CMD_04
|ISM_LF8_CMD_04
|ISM_LF9_CMD_04
|ISM_LF10_CMD_04
|ISM_LF11_CMD_04
|ISM_LF12_CMD_04
|ISM_LF13_CMD_04
|ISM_LF14_CMD_04
|ISM_LF15_CMD_04
|ISM_LF16_CMD_04

),

INPUT_SIGNALS_MASK_CMD_05 = (
ISM_BLOCK_VKL_VVO_CMD_05
|ISM_BLOCK_VKL_VVP_CMD_05
|ISM_RESET_LEDS_CMD_05
|ISM_RESET_RELES_CMD_05
|ISM_MISCEVE_DYSTANCIJNE_CMD_05
|ISM_STATE_VVR_CMD_05
|ISM_STATE_VVO_CMD_05
|ISM_VKL_VVO_CMD_05
|ISM_VKL_VVR_CMD_05
|ISM_CTRL_VKL_VVO_CMD_05
|ISM_CTRL_VKL_VVR_CMD_05
|ISM_OTKL_VV_VVO_CMD_05
|ISM_OTKL_VV_VVR_CMD_05
|ISM_CTRL_OTKL_VVO_CMD_05
|ISM_CTRL_OTKL_VVR_CMD_05
//|ISM_1_GRUPA_USTAVOK_CMD_05
//|ISM_2_GRUPA_USTAVOK_CMD_05
//|ISM_3_GRUPA_USTAVOK_CMD_05
//|ISM_4_GRUPA_USTAVOK_CMD_05
|ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV_CMD_05
|ISM_ZVN_NESPR_DZO_CMD_05
|ISM_ZBR_BLOCK_DZO1_I_O_3G_CMD_05
|ISM_ZBR_BLOCK_DZO1_I_O_CMD_05
|ISM_BLOCK_DZO1_CMD_05
|ISM_BLOCK_PR_DZO2_CMD_05
|ISM_OP_PR_DZO2_CMD_05
|ISM_ZBR_BLOCK_DZO2_I_O_3G_CMD_05
|ISM_BLOCK_DZO2_CMD_05
|ISM_BLOCK_PR_DZO3_CMD_05
|ISM_OP_PR_DZO3_CMD_05
|ISM_ZBR_BLOCK_DZO3_I_O_3G_CMD_05
|ISM_BLOCK_DZO3_CMD_05
|ISM_ZBR_BLOCK_DZO4_I_O_3G_CMD_05
|ISM_BLOCK_DZO4_CMD_05
|ISM_BLOCK_ZDZ_CMD_05
|ISM_PUSK_ZDZ_VID_DV_CMD_05
|ISM_BLOCK_MCZO1_CMD_05
|ISM_BLOCK_MCZO2_CMD_05
|ISM_BLOCK_PR_MCZO2_CMD_05
|ISM_BLOCK_MCZO3_CMD_05
|ISM_BLOCK_MCZO4_CMD_05
|ISM_BLOCK_MCZR1_CMD_05
|ISM_BLOCK_MCZR2_CMD_05
|ISM_STAT_BLK_APV_CMD_05
|ISM_ACHR_CHAPV_VID_DV_CMD_05
|ISM_BLOCK_ACHR1_CMD_05
|ISM_BLOCK_ACHR2_CMD_05
|ISM_PUSK_UROV_VID_DV_CMD_05
|ISM_ZVN_NESPR_DZR_CMD_05
|ISM_ZBR_BLOCK_DZR1_I_R_3G_CMD_05
|ISM_ZBR_BLOCK_DZR1_I_R_CMD_05
|ISM_BLOCK_DZR1_CMD_05
|ISM_BLOCK_PR_DZR2_CMD_05
|ISM_OP_PR_DZR2_CMD_05
|ISM_ZBR_BLOCK_DZR2_I_R_3G_CMD_05
|ISM_BLOCK_DZR2_CMD_05
|ISM_BLOCK_PR_DZR3_CMD_05
|ISM_OP_PR_DZR3_CMD_05
|ISM_ZBR_BLOCK_DZR3_I_R_3G_CMD_05
|ISM_BLOCK_DZR3_CMD_05
|ISM_BLOCK_UMIN1_CMD_05
|ISM_START_UMIN1_CMD_05
|ISM_BLOCK_UMIN2_CMD_05
|ISM_START_UMIN2_CMD_05
|ISM_BLOCK_UMAX1_CMD_05
|ISM_BLOCK_UMAX2_CMD_05
|ISM_BLOCK_UP1_CMD_05
|ISM_BLOCK_UP2_CMD_05
|ISM_BLOCK_UP3_CMD_05
|ISM_BLOCK_UP4_CMD_05
|ISM_BLOCK_UP5_CMD_05
|ISM_BLOCK_UP6_CMD_05
|ISM_BLOCK_UP7_CMD_05
|ISM_BLOCK_UP8_CMD_05
|ISM_DF1_IN_CMD_05
|ISM_DF2_IN_CMD_05
|ISM_DF3_IN_CMD_05
|ISM_DF4_IN_CMD_05
|ISM_DF5_IN_CMD_05
|ISM_DF6_IN_CMD_05
|ISM_DF7_IN_CMD_05
|ISM_DF8_IN_CMD_05
|ISM_DF9_IN_CMD_05
|ISM_DF10_IN_CMD_05
|ISM_DF11_IN_CMD_05
|ISM_DF12_IN_CMD_05
|ISM_DF13_IN_CMD_05
|ISM_DF14_IN_CMD_05
|ISM_DF15_IN_CMD_05
|ISM_DF16_IN_CMD_05
|ISM_DT1_SET_CMD_05
|ISM_DT1_RESET_CMD_05
|ISM_DT2_SET_CMD_05
|ISM_DT2_RESET_CMD_05
|ISM_DT3_SET_CMD_05
|ISM_DT3_RESET_CMD_05
|ISM_DT4_SET_CMD_05
|ISM_DT4_RESET_CMD_05
|ISM_LF1_CMD_05
|ISM_LF2_CMD_05
|ISM_LF3_CMD_05
|ISM_LF4_CMD_05
|ISM_LF5_CMD_05
|ISM_LF6_CMD_05
|ISM_LF7_CMD_05
|ISM_LF8_CMD_05
|ISM_LF9_CMD_05
|ISM_LF10_CMD_05
|ISM_LF11_CMD_05
|ISM_LF12_CMD_05
|ISM_LF13_CMD_05
|ISM_LF14_CMD_05
|ISM_LF15_CMD_05
|ISM_LF16_CMD_05

),

INPUT_SIGNALS_MASK_CMD_06 = (
ISM_BLOCK_VKL_VVO_CMD_06
|ISM_BLOCK_VKL_VVP_CMD_06
|ISM_RESET_LEDS_CMD_06
|ISM_RESET_RELES_CMD_06
|ISM_MISCEVE_DYSTANCIJNE_CMD_06
|ISM_STATE_VVR_CMD_06
|ISM_STATE_VVO_CMD_06
|ISM_VKL_VVO_CMD_06
|ISM_VKL_VVR_CMD_06
|ISM_CTRL_VKL_VVO_CMD_06
|ISM_CTRL_VKL_VVR_CMD_06
|ISM_OTKL_VV_VVO_CMD_06
|ISM_OTKL_VV_VVR_CMD_06
|ISM_CTRL_OTKL_VVO_CMD_06
|ISM_CTRL_OTKL_VVR_CMD_06
//|ISM_1_GRUPA_USTAVOK_CMD_06
//|ISM_2_GRUPA_USTAVOK_CMD_06
//|ISM_3_GRUPA_USTAVOK_CMD_06
//|ISM_4_GRUPA_USTAVOK_CMD_06
|ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV_CMD_06
|ISM_ZVN_NESPR_DZO_CMD_06
|ISM_ZBR_BLOCK_DZO1_I_O_3G_CMD_06
|ISM_ZBR_BLOCK_DZO1_I_O_CMD_06
|ISM_BLOCK_DZO1_CMD_06
|ISM_BLOCK_PR_DZO2_CMD_06
|ISM_OP_PR_DZO2_CMD_06
|ISM_ZBR_BLOCK_DZO2_I_O_3G_CMD_06
|ISM_BLOCK_DZO2_CMD_06
|ISM_BLOCK_PR_DZO3_CMD_06
|ISM_OP_PR_DZO3_CMD_06
|ISM_ZBR_BLOCK_DZO3_I_O_3G_CMD_06
|ISM_BLOCK_DZO3_CMD_06
|ISM_ZBR_BLOCK_DZO4_I_O_3G_CMD_06
|ISM_BLOCK_DZO4_CMD_06
|ISM_BLOCK_ZDZ_CMD_06
|ISM_PUSK_ZDZ_VID_DV_CMD_06
|ISM_BLOCK_MCZO1_CMD_06
|ISM_BLOCK_MCZO2_CMD_06
|ISM_BLOCK_PR_MCZO2_CMD_06
|ISM_BLOCK_MCZO3_CMD_06
|ISM_BLOCK_MCZO4_CMD_06
|ISM_BLOCK_MCZR1_CMD_06
|ISM_BLOCK_MCZR2_CMD_06
|ISM_STAT_BLK_APV_CMD_06
|ISM_ACHR_CHAPV_VID_DV_CMD_06
|ISM_BLOCK_ACHR1_CMD_06
|ISM_BLOCK_ACHR2_CMD_06
|ISM_PUSK_UROV_VID_DV_CMD_06
|ISM_ZVN_NESPR_DZR_CMD_06
|ISM_ZBR_BLOCK_DZR1_I_R_3G_CMD_06
|ISM_ZBR_BLOCK_DZR1_I_R_CMD_06
|ISM_BLOCK_DZR1_CMD_06
|ISM_BLOCK_PR_DZR2_CMD_06
|ISM_OP_PR_DZR2_CMD_06
|ISM_ZBR_BLOCK_DZR2_I_R_3G_CMD_06
|ISM_BLOCK_DZR2_CMD_06
|ISM_BLOCK_PR_DZR3_CMD_06
|ISM_OP_PR_DZR3_CMD_06
|ISM_ZBR_BLOCK_DZR3_I_R_3G_CMD_06
|ISM_BLOCK_DZR3_CMD_06
|ISM_BLOCK_UMIN1_CMD_06
|ISM_START_UMIN1_CMD_06
|ISM_BLOCK_UMIN2_CMD_06
|ISM_START_UMIN2_CMD_06
|ISM_BLOCK_UMAX1_CMD_06
|ISM_BLOCK_UMAX2_CMD_06
|ISM_BLOCK_UP1_CMD_06
|ISM_BLOCK_UP2_CMD_06
|ISM_BLOCK_UP3_CMD_06
|ISM_BLOCK_UP4_CMD_06
|ISM_BLOCK_UP5_CMD_06
|ISM_BLOCK_UP6_CMD_06
|ISM_BLOCK_UP7_CMD_06
|ISM_BLOCK_UP8_CMD_06
|ISM_DF1_IN_CMD_06
|ISM_DF2_IN_CMD_06
|ISM_DF3_IN_CMD_06
|ISM_DF4_IN_CMD_06
|ISM_DF5_IN_CMD_06
|ISM_DF6_IN_CMD_06
|ISM_DF7_IN_CMD_06
|ISM_DF8_IN_CMD_06
|ISM_DF9_IN_CMD_06
|ISM_DF10_IN_CMD_06
|ISM_DF11_IN_CMD_06
|ISM_DF12_IN_CMD_06
|ISM_DF13_IN_CMD_06
|ISM_DF14_IN_CMD_06
|ISM_DF15_IN_CMD_06
|ISM_DF16_IN_CMD_06
|ISM_DT1_SET_CMD_06
|ISM_DT1_RESET_CMD_06
|ISM_DT2_SET_CMD_06
|ISM_DT2_RESET_CMD_06
|ISM_DT3_SET_CMD_06
|ISM_DT3_RESET_CMD_06
|ISM_DT4_SET_CMD_06
|ISM_DT4_RESET_CMD_06
|ISM_LF1_CMD_06
|ISM_LF2_CMD_06
|ISM_LF3_CMD_06
|ISM_LF4_CMD_06
|ISM_LF5_CMD_06
|ISM_LF6_CMD_06
|ISM_LF7_CMD_06
|ISM_LF8_CMD_06
|ISM_LF9_CMD_06
|ISM_LF10_CMD_06
|ISM_LF11_CMD_06
|ISM_LF12_CMD_06
|ISM_LF13_CMD_06
|ISM_LF14_CMD_06
|ISM_LF15_CMD_06
|ISM_LF16_CMD_06

),

INPUT_SIGNALS_MASK_CMD_07 = (
ISM_BLOCK_VKL_VVO_CMD_07
|ISM_BLOCK_VKL_VVP_CMD_07
|ISM_RESET_LEDS_CMD_07
|ISM_RESET_RELES_CMD_07
|ISM_MISCEVE_DYSTANCIJNE_CMD_07
|ISM_STATE_VVR_CMD_07
|ISM_STATE_VVO_CMD_07
|ISM_VKL_VVO_CMD_07
|ISM_VKL_VVR_CMD_07
|ISM_CTRL_VKL_VVO_CMD_07
|ISM_CTRL_VKL_VVR_CMD_07
|ISM_OTKL_VV_VVO_CMD_07
|ISM_OTKL_VV_VVR_CMD_07
|ISM_CTRL_OTKL_VVO_CMD_07
|ISM_CTRL_OTKL_VVR_CMD_07
//|ISM_1_GRUPA_USTAVOK_CMD_07
//|ISM_2_GRUPA_USTAVOK_CMD_07
//|ISM_3_GRUPA_USTAVOK_CMD_07
//|ISM_4_GRUPA_USTAVOK_CMD_07
|ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV_CMD_07
|ISM_ZVN_NESPR_DZO_CMD_07
|ISM_ZBR_BLOCK_DZO1_I_O_3G_CMD_07
|ISM_ZBR_BLOCK_DZO1_I_O_CMD_07
|ISM_BLOCK_DZO1_CMD_07
|ISM_BLOCK_PR_DZO2_CMD_07
|ISM_OP_PR_DZO2_CMD_07
|ISM_ZBR_BLOCK_DZO2_I_O_3G_CMD_07
|ISM_BLOCK_DZO2_CMD_07
|ISM_BLOCK_PR_DZO3_CMD_07
|ISM_OP_PR_DZO3_CMD_07
|ISM_ZBR_BLOCK_DZO3_I_O_3G_CMD_07
|ISM_BLOCK_DZO3_CMD_07
|ISM_ZBR_BLOCK_DZO4_I_O_3G_CMD_07
|ISM_BLOCK_DZO4_CMD_07
|ISM_BLOCK_ZDZ_CMD_07
|ISM_PUSK_ZDZ_VID_DV_CMD_07
|ISM_BLOCK_MCZO1_CMD_07
|ISM_BLOCK_MCZO2_CMD_07
|ISM_BLOCK_PR_MCZO2_CMD_07
|ISM_BLOCK_MCZO3_CMD_07
|ISM_BLOCK_MCZO4_CMD_07
|ISM_BLOCK_MCZR1_CMD_07
|ISM_BLOCK_MCZR2_CMD_07
|ISM_STAT_BLK_APV_CMD_07
|ISM_ACHR_CHAPV_VID_DV_CMD_07
|ISM_BLOCK_ACHR1_CMD_07
|ISM_BLOCK_ACHR2_CMD_07
|ISM_PUSK_UROV_VID_DV_CMD_07
|ISM_ZVN_NESPR_DZR_CMD_07
|ISM_ZBR_BLOCK_DZR1_I_R_3G_CMD_07
|ISM_ZBR_BLOCK_DZR1_I_R_CMD_07
|ISM_BLOCK_DZR1_CMD_07
|ISM_BLOCK_PR_DZR2_CMD_07
|ISM_OP_PR_DZR2_CMD_07
|ISM_ZBR_BLOCK_DZR2_I_R_3G_CMD_07
|ISM_BLOCK_DZR2_CMD_07
|ISM_BLOCK_PR_DZR3_CMD_07
|ISM_OP_PR_DZR3_CMD_07
|ISM_ZBR_BLOCK_DZR3_I_R_3G_CMD_07
|ISM_BLOCK_DZR3_CMD_07
|ISM_BLOCK_UMIN1_CMD_07
|ISM_START_UMIN1_CMD_07
|ISM_BLOCK_UMIN2_CMD_07
|ISM_START_UMIN2_CMD_07
|ISM_BLOCK_UMAX1_CMD_07
|ISM_BLOCK_UMAX2_CMD_07
|ISM_BLOCK_UP1_CMD_07
|ISM_BLOCK_UP2_CMD_07
|ISM_BLOCK_UP3_CMD_07
|ISM_BLOCK_UP4_CMD_07
|ISM_BLOCK_UP5_CMD_07
|ISM_BLOCK_UP6_CMD_07
|ISM_BLOCK_UP7_CMD_07
|ISM_BLOCK_UP8_CMD_07
|ISM_DF1_IN_CMD_07
|ISM_DF2_IN_CMD_07
|ISM_DF3_IN_CMD_07
|ISM_DF4_IN_CMD_07
|ISM_DF5_IN_CMD_07
|ISM_DF6_IN_CMD_07
|ISM_DF7_IN_CMD_07
|ISM_DF8_IN_CMD_07
|ISM_DF9_IN_CMD_07
|ISM_DF10_IN_CMD_07
|ISM_DF11_IN_CMD_07
|ISM_DF12_IN_CMD_07
|ISM_DF13_IN_CMD_07
|ISM_DF14_IN_CMD_07
|ISM_DF15_IN_CMD_07
|ISM_DF16_IN_CMD_07
|ISM_DT1_SET_CMD_07
|ISM_DT1_RESET_CMD_07
|ISM_DT2_SET_CMD_07
|ISM_DT2_RESET_CMD_07
|ISM_DT3_SET_CMD_07
|ISM_DT3_RESET_CMD_07
|ISM_DT4_SET_CMD_07
|ISM_DT4_RESET_CMD_07
|ISM_LF1_CMD_07
|ISM_LF2_CMD_07
|ISM_LF3_CMD_07
|ISM_LF4_CMD_07
|ISM_LF5_CMD_07
|ISM_LF6_CMD_07
|ISM_LF7_CMD_07
|ISM_LF8_CMD_07
|ISM_LF9_CMD_07
|ISM_LF10_CMD_07
|ISM_LF11_CMD_07
|ISM_LF12_CMD_07
|ISM_LF13_CMD_07
|ISM_LF14_CMD_07
|ISM_LF15_CMD_07
|ISM_LF16_CMD_07

),
INPUT_SIGNALS_MASK_CMD_08 = (
ISM_BLOCK_VKL_VVO_CMD_08
|ISM_BLOCK_VKL_VVP_CMD_08
|ISM_RESET_LEDS_CMD_08
|ISM_RESET_RELES_CMD_08
|ISM_MISCEVE_DYSTANCIJNE_CMD_08
|ISM_STATE_VVR_CMD_08
|ISM_STATE_VVO_CMD_08
|ISM_VKL_VVO_CMD_08
|ISM_VKL_VVR_CMD_08
|ISM_CTRL_VKL_VVO_CMD_08
|ISM_CTRL_VKL_VVR_CMD_08
|ISM_OTKL_VV_VVO_CMD_08
|ISM_OTKL_VV_VVR_CMD_08
|ISM_CTRL_OTKL_VVO_CMD_08
|ISM_CTRL_OTKL_VVR_CMD_08
//|ISM_1_GRUPA_USTAVOK_CMD_08
//|ISM_2_GRUPA_USTAVOK_CMD_08
//|ISM_3_GRUPA_USTAVOK_CMD_08
//|ISM_4_GRUPA_USTAVOK_CMD_08
|ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV_CMD_08
|ISM_ZVN_NESPR_DZO_CMD_08
|ISM_ZBR_BLOCK_DZO1_I_O_3G_CMD_08
|ISM_ZBR_BLOCK_DZO1_I_O_CMD_08
|ISM_BLOCK_DZO1_CMD_08
|ISM_BLOCK_PR_DZO2_CMD_08
|ISM_OP_PR_DZO2_CMD_08
|ISM_ZBR_BLOCK_DZO2_I_O_3G_CMD_08
|ISM_BLOCK_DZO2_CMD_08
|ISM_BLOCK_PR_DZO3_CMD_08
|ISM_OP_PR_DZO3_CMD_08
|ISM_ZBR_BLOCK_DZO3_I_O_3G_CMD_08
|ISM_BLOCK_DZO3_CMD_08
|ISM_ZBR_BLOCK_DZO4_I_O_3G_CMD_08
|ISM_BLOCK_DZO4_CMD_08
|ISM_BLOCK_ZDZ_CMD_08
|ISM_PUSK_ZDZ_VID_DV_CMD_08
|ISM_BLOCK_MCZO1_CMD_08
|ISM_BLOCK_MCZO2_CMD_08
|ISM_BLOCK_PR_MCZO2_CMD_08
|ISM_BLOCK_MCZO3_CMD_08
|ISM_BLOCK_MCZO4_CMD_08
|ISM_BLOCK_MCZR1_CMD_08
|ISM_BLOCK_MCZR2_CMD_08
|ISM_STAT_BLK_APV_CMD_08
|ISM_ACHR_CHAPV_VID_DV_CMD_08
|ISM_BLOCK_ACHR1_CMD_08
|ISM_BLOCK_ACHR2_CMD_08
|ISM_PUSK_UROV_VID_DV_CMD_08
|ISM_ZVN_NESPR_DZR_CMD_08
|ISM_ZBR_BLOCK_DZR1_I_R_3G_CMD_08
|ISM_ZBR_BLOCK_DZR1_I_R_CMD_08
|ISM_BLOCK_DZR1_CMD_08
|ISM_BLOCK_PR_DZR2_CMD_08
|ISM_OP_PR_DZR2_CMD_08
|ISM_ZBR_BLOCK_DZR2_I_R_3G_CMD_08
|ISM_BLOCK_DZR2_CMD_08
|ISM_BLOCK_PR_DZR3_CMD_08
|ISM_OP_PR_DZR3_CMD_08
|ISM_ZBR_BLOCK_DZR3_I_R_3G_CMD_08
|ISM_BLOCK_DZR3_CMD_08
|ISM_BLOCK_UMIN1_CMD_08
|ISM_START_UMIN1_CMD_08
|ISM_BLOCK_UMIN2_CMD_08
|ISM_START_UMIN2_CMD_08
|ISM_BLOCK_UMAX1_CMD_08
|ISM_BLOCK_UMAX2_CMD_08
|ISM_BLOCK_UP1_CMD_08
|ISM_BLOCK_UP2_CMD_08
|ISM_BLOCK_UP3_CMD_08
|ISM_BLOCK_UP4_CMD_08
|ISM_BLOCK_UP5_CMD_08
|ISM_BLOCK_UP6_CMD_08
|ISM_BLOCK_UP7_CMD_08
|ISM_BLOCK_UP8_CMD_08
|ISM_DF1_IN_CMD_08
|ISM_DF2_IN_CMD_08
|ISM_DF3_IN_CMD_08
|ISM_DF4_IN_CMD_08
|ISM_DF5_IN_CMD_08
|ISM_DF6_IN_CMD_08
|ISM_DF7_IN_CMD_08
|ISM_DF8_IN_CMD_08
|ISM_DF9_IN_CMD_08
|ISM_DF10_IN_CMD_08
|ISM_DF11_IN_CMD_08
|ISM_DF12_IN_CMD_08
|ISM_DF13_IN_CMD_08
|ISM_DF14_IN_CMD_08
|ISM_DF15_IN_CMD_08
|ISM_DF16_IN_CMD_08
|ISM_DT1_SET_CMD_08
|ISM_DT1_RESET_CMD_08
|ISM_DT2_SET_CMD_08
|ISM_DT2_RESET_CMD_08
|ISM_DT3_SET_CMD_08
|ISM_DT3_RESET_CMD_08
|ISM_DT4_SET_CMD_08
|ISM_DT4_RESET_CMD_08
|ISM_LF1_CMD_08
|ISM_LF2_CMD_08
|ISM_LF3_CMD_08
|ISM_LF4_CMD_08
|ISM_LF5_CMD_08
|ISM_LF6_CMD_08
|ISM_LF7_CMD_08
|ISM_LF8_CMD_08
|ISM_LF9_CMD_08
|ISM_LF10_CMD_08
|ISM_LF11_CMD_08
|ISM_LF12_CMD_08
|ISM_LF13_CMD_08
|ISM_LF14_CMD_08
|ISM_LF15_CMD_08
|ISM_LF16_CMD_08

),
INPUT_SIGNALS_MASK_CMD_09 = (
ISM_BLOCK_VKL_VVO_CMD_09
|ISM_BLOCK_VKL_VVP_CMD_09
|ISM_RESET_LEDS_CMD_09
|ISM_RESET_RELES_CMD_09
|ISM_MISCEVE_DYSTANCIJNE_CMD_09
|ISM_STATE_VVR_CMD_09
|ISM_STATE_VVO_CMD_09
|ISM_VKL_VVO_CMD_09
|ISM_VKL_VVR_CMD_09
|ISM_CTRL_VKL_VVO_CMD_09
|ISM_CTRL_VKL_VVR_CMD_09
|ISM_OTKL_VV_VVO_CMD_09
|ISM_OTKL_VV_VVR_CMD_09
|ISM_CTRL_OTKL_VVO_CMD_09
|ISM_CTRL_OTKL_VVR_CMD_09
//|ISM_1_GRUPA_USTAVOK_CMD_09
//|ISM_2_GRUPA_USTAVOK_CMD_09
//|ISM_3_GRUPA_USTAVOK_CMD_09
//|ISM_4_GRUPA_USTAVOK_CMD_09
|ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV_CMD_09
|ISM_ZVN_NESPR_DZO_CMD_09
|ISM_ZBR_BLOCK_DZO1_I_O_3G_CMD_09
|ISM_ZBR_BLOCK_DZO1_I_O_CMD_09
|ISM_BLOCK_DZO1_CMD_09
|ISM_BLOCK_PR_DZO2_CMD_09
|ISM_OP_PR_DZO2_CMD_09
|ISM_ZBR_BLOCK_DZO2_I_O_3G_CMD_09
|ISM_BLOCK_DZO2_CMD_09
|ISM_BLOCK_PR_DZO3_CMD_09
|ISM_OP_PR_DZO3_CMD_09
|ISM_ZBR_BLOCK_DZO3_I_O_3G_CMD_09
|ISM_BLOCK_DZO3_CMD_09
|ISM_ZBR_BLOCK_DZO4_I_O_3G_CMD_09
|ISM_BLOCK_DZO4_CMD_09
|ISM_BLOCK_ZDZ_CMD_09
|ISM_PUSK_ZDZ_VID_DV_CMD_09
|ISM_BLOCK_MCZO1_CMD_09
|ISM_BLOCK_MCZO2_CMD_09
|ISM_BLOCK_PR_MCZO2_CMD_09
|ISM_BLOCK_MCZO3_CMD_09
|ISM_BLOCK_MCZO4_CMD_09
|ISM_BLOCK_MCZR1_CMD_09
|ISM_BLOCK_MCZR2_CMD_09
|ISM_STAT_BLK_APV_CMD_09
|ISM_ACHR_CHAPV_VID_DV_CMD_09
|ISM_BLOCK_ACHR1_CMD_09
|ISM_BLOCK_ACHR2_CMD_09
|ISM_PUSK_UROV_VID_DV_CMD_09
|ISM_ZVN_NESPR_DZR_CMD_09
|ISM_ZBR_BLOCK_DZR1_I_R_3G_CMD_09
|ISM_ZBR_BLOCK_DZR1_I_R_CMD_09
|ISM_BLOCK_DZR1_CMD_09
|ISM_BLOCK_PR_DZR2_CMD_09
|ISM_OP_PR_DZR2_CMD_09
|ISM_ZBR_BLOCK_DZR2_I_R_3G_CMD_09
|ISM_BLOCK_DZR2_CMD_09
|ISM_BLOCK_PR_DZR3_CMD_09
|ISM_OP_PR_DZR3_CMD_09
|ISM_ZBR_BLOCK_DZR3_I_R_3G_CMD_09
|ISM_BLOCK_DZR3_CMD_09
|ISM_BLOCK_UMIN1_CMD_09
|ISM_START_UMIN1_CMD_09
|ISM_BLOCK_UMIN2_CMD_09
|ISM_START_UMIN2_CMD_09
|ISM_BLOCK_UMAX1_CMD_09
|ISM_BLOCK_UMAX2_CMD_09
|ISM_BLOCK_UP1_CMD_09
|ISM_BLOCK_UP2_CMD_09
|ISM_BLOCK_UP3_CMD_09
|ISM_BLOCK_UP4_CMD_09
|ISM_BLOCK_UP5_CMD_09
|ISM_BLOCK_UP6_CMD_09
|ISM_BLOCK_UP7_CMD_09
|ISM_BLOCK_UP8_CMD_09
|ISM_DF1_IN_CMD_09
|ISM_DF2_IN_CMD_09
|ISM_DF3_IN_CMD_09
|ISM_DF4_IN_CMD_09
|ISM_DF5_IN_CMD_09
|ISM_DF6_IN_CMD_09
|ISM_DF7_IN_CMD_09
|ISM_DF8_IN_CMD_09
|ISM_DF9_IN_CMD_09
|ISM_DF10_IN_CMD_09
|ISM_DF11_IN_CMD_09
|ISM_DF12_IN_CMD_09
|ISM_DF13_IN_CMD_09
|ISM_DF14_IN_CMD_09
|ISM_DF15_IN_CMD_09
|ISM_DF16_IN_CMD_09
|ISM_DT1_SET_CMD_09
|ISM_DT1_RESET_CMD_09
|ISM_DT2_SET_CMD_09
|ISM_DT2_RESET_CMD_09
|ISM_DT3_SET_CMD_09
|ISM_DT3_RESET_CMD_09
|ISM_DT4_SET_CMD_09
|ISM_DT4_RESET_CMD_09
|ISM_LF1_CMD_09
|ISM_LF2_CMD_09
|ISM_LF3_CMD_09
|ISM_LF4_CMD_09
|ISM_LF5_CMD_09
|ISM_LF6_CMD_09
|ISM_LF7_CMD_09
|ISM_LF8_CMD_09
|ISM_LF9_CMD_09
|ISM_LF10_CMD_09
|ISM_LF11_CMD_09
|ISM_LF12_CMD_09
|ISM_LF13_CMD_09
|ISM_LF14_CMD_09
|ISM_LF15_CMD_09
|ISM_LF16_CMD_09

),
INPUT_SIGNALS_MASK_CMD_10 = (
ISM_BLOCK_VKL_VVO_CMD_10
|ISM_BLOCK_VKL_VVP_CMD_10
|ISM_RESET_LEDS_CMD_10
|ISM_RESET_RELES_CMD_10
|ISM_MISCEVE_DYSTANCIJNE_CMD_10
|ISM_STATE_VVR_CMD_10
|ISM_STATE_VVO_CMD_10
|ISM_VKL_VVO_CMD_10
|ISM_VKL_VVR_CMD_10
|ISM_CTRL_VKL_VVO_CMD_10
|ISM_CTRL_VKL_VVR_CMD_10
|ISM_OTKL_VV_VVO_CMD_10
|ISM_OTKL_VV_VVR_CMD_10
|ISM_CTRL_OTKL_VVO_CMD_10
|ISM_CTRL_OTKL_VVR_CMD_10
//|ISM_1_GRUPA_USTAVOK_CMD_10
//|ISM_2_GRUPA_USTAVOK_CMD_10
//|ISM_3_GRUPA_USTAVOK_CMD_10
//|ISM_4_GRUPA_USTAVOK_CMD_10
|ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV_CMD_10
|ISM_ZVN_NESPR_DZO_CMD_10
|ISM_ZBR_BLOCK_DZO1_I_O_3G_CMD_10
|ISM_ZBR_BLOCK_DZO1_I_O_CMD_10
|ISM_BLOCK_DZO1_CMD_10
|ISM_BLOCK_PR_DZO2_CMD_10
|ISM_OP_PR_DZO2_CMD_10
|ISM_ZBR_BLOCK_DZO2_I_O_3G_CMD_10
|ISM_BLOCK_DZO2_CMD_10
|ISM_BLOCK_PR_DZO3_CMD_10
|ISM_OP_PR_DZO3_CMD_10
|ISM_ZBR_BLOCK_DZO3_I_O_3G_CMD_10
|ISM_BLOCK_DZO3_CMD_10
|ISM_ZBR_BLOCK_DZO4_I_O_3G_CMD_10
|ISM_BLOCK_DZO4_CMD_10
|ISM_BLOCK_ZDZ_CMD_10
|ISM_PUSK_ZDZ_VID_DV_CMD_10
|ISM_BLOCK_MCZO1_CMD_10
|ISM_BLOCK_MCZO2_CMD_10
|ISM_BLOCK_PR_MCZO2_CMD_10
|ISM_BLOCK_MCZO3_CMD_10
|ISM_BLOCK_MCZO4_CMD_10
|ISM_BLOCK_MCZR1_CMD_10
|ISM_BLOCK_MCZR2_CMD_10
|ISM_STAT_BLK_APV_CMD_10
|ISM_ACHR_CHAPV_VID_DV_CMD_10
|ISM_BLOCK_ACHR1_CMD_10
|ISM_BLOCK_ACHR2_CMD_10
|ISM_PUSK_UROV_VID_DV_CMD_10
|ISM_ZVN_NESPR_DZR_CMD_10
|ISM_ZBR_BLOCK_DZR1_I_R_3G_CMD_10
|ISM_ZBR_BLOCK_DZR1_I_R_CMD_10
|ISM_BLOCK_DZR1_CMD_10
|ISM_BLOCK_PR_DZR2_CMD_10
|ISM_OP_PR_DZR2_CMD_10
|ISM_ZBR_BLOCK_DZR2_I_R_3G_CMD_10
|ISM_BLOCK_DZR2_CMD_10
|ISM_BLOCK_PR_DZR3_CMD_10
|ISM_OP_PR_DZR3_CMD_10
|ISM_ZBR_BLOCK_DZR3_I_R_3G_CMD_10
|ISM_BLOCK_DZR3_CMD_10
|ISM_BLOCK_UMIN1_CMD_10
|ISM_START_UMIN1_CMD_10
|ISM_BLOCK_UMIN2_CMD_10
|ISM_START_UMIN2_CMD_10
|ISM_BLOCK_UMAX1_CMD_10
|ISM_BLOCK_UMAX2_CMD_10
|ISM_BLOCK_UP1_CMD_10
|ISM_BLOCK_UP2_CMD_10
|ISM_BLOCK_UP3_CMD_10
|ISM_BLOCK_UP4_CMD_10
|ISM_BLOCK_UP5_CMD_10
|ISM_BLOCK_UP6_CMD_10
|ISM_BLOCK_UP7_CMD_10
|ISM_BLOCK_UP8_CMD_10
|ISM_DF1_IN_CMD_10
|ISM_DF2_IN_CMD_10
|ISM_DF3_IN_CMD_10
|ISM_DF4_IN_CMD_10
|ISM_DF5_IN_CMD_10
|ISM_DF6_IN_CMD_10
|ISM_DF7_IN_CMD_10
|ISM_DF8_IN_CMD_10
|ISM_DF9_IN_CMD_10
|ISM_DF10_IN_CMD_10
|ISM_DF11_IN_CMD_10
|ISM_DF12_IN_CMD_10
|ISM_DF13_IN_CMD_10
|ISM_DF14_IN_CMD_10
|ISM_DF15_IN_CMD_10
|ISM_DF16_IN_CMD_10
|ISM_DT1_SET_CMD_10
|ISM_DT1_RESET_CMD_10
|ISM_DT2_SET_CMD_10
|ISM_DT2_RESET_CMD_10
|ISM_DT3_SET_CMD_10
|ISM_DT3_RESET_CMD_10
|ISM_DT4_SET_CMD_10
|ISM_DT4_RESET_CMD_10
|ISM_LF1_CMD_10
|ISM_LF2_CMD_10
|ISM_LF3_CMD_10
|ISM_LF4_CMD_10
|ISM_LF5_CMD_10
|ISM_LF6_CMD_10
|ISM_LF7_CMD_10
|ISM_LF8_CMD_10
|ISM_LF9_CMD_10
|ISM_LF10_CMD_10
|ISM_LF11_CMD_10
|ISM_LF12_CMD_10
|ISM_LF13_CMD_10
|ISM_LF14_CMD_10
|ISM_LF15_CMD_10
|ISM_LF16_CMD_10

),

INPUT_SIGNALS_MASK_CMD_11 = (
ISM_BLOCK_VKL_VVO_CMD_11
|ISM_BLOCK_VKL_VVP_CMD_11
|ISM_RESET_LEDS_CMD_11
|ISM_RESET_RELES_CMD_11
|ISM_MISCEVE_DYSTANCIJNE_CMD_11
|ISM_STATE_VVR_CMD_11
|ISM_STATE_VVO_CMD_11
|ISM_VKL_VVO_CMD_11
|ISM_VKL_VVR_CMD_11
|ISM_CTRL_VKL_VVO_CMD_11
|ISM_CTRL_VKL_VVR_CMD_11
|ISM_OTKL_VV_VVO_CMD_11
|ISM_OTKL_VV_VVR_CMD_11
|ISM_CTRL_OTKL_VVO_CMD_11
|ISM_CTRL_OTKL_VVR_CMD_11
//|ISM_1_GRUPA_USTAVOK_CMD_11
//|ISM_2_GRUPA_USTAVOK_CMD_11
//|ISM_3_GRUPA_USTAVOK_CMD_11
//|ISM_4_GRUPA_USTAVOK_CMD_11
|ISM_RESET_BLOCK_READY_TU_VID_ZAHYSTIV_CMD_11
|ISM_ZVN_NESPR_DZO_CMD_11
|ISM_ZBR_BLOCK_DZO1_I_O_3G_CMD_11
|ISM_ZBR_BLOCK_DZO1_I_O_CMD_11
|ISM_BLOCK_DZO1_CMD_11
|ISM_BLOCK_PR_DZO2_CMD_11
|ISM_OP_PR_DZO2_CMD_11
|ISM_ZBR_BLOCK_DZO2_I_O_3G_CMD_11
|ISM_BLOCK_DZO2_CMD_11
|ISM_BLOCK_PR_DZO3_CMD_11
|ISM_OP_PR_DZO3_CMD_11
|ISM_ZBR_BLOCK_DZO3_I_O_3G_CMD_11
|ISM_BLOCK_DZO3_CMD_11
|ISM_ZBR_BLOCK_DZO4_I_O_3G_CMD_11
|ISM_BLOCK_DZO4_CMD_11
|ISM_BLOCK_ZDZ_CMD_11
|ISM_PUSK_ZDZ_VID_DV_CMD_11
|ISM_BLOCK_MCZO1_CMD_11
|ISM_BLOCK_MCZO2_CMD_11
|ISM_BLOCK_PR_MCZO2_CMD_11
|ISM_BLOCK_MCZO3_CMD_11
|ISM_BLOCK_MCZO4_CMD_11
|ISM_BLOCK_MCZR1_CMD_11
|ISM_BLOCK_MCZR2_CMD_11
|ISM_STAT_BLK_APV_CMD_11
|ISM_ACHR_CHAPV_VID_DV_CMD_11
|ISM_BLOCK_ACHR1_CMD_11
|ISM_BLOCK_ACHR2_CMD_11
|ISM_PUSK_UROV_VID_DV_CMD_11
|ISM_ZVN_NESPR_DZR_CMD_11
|ISM_ZBR_BLOCK_DZR1_I_R_3G_CMD_11
|ISM_ZBR_BLOCK_DZR1_I_R_CMD_11
|ISM_BLOCK_DZR1_CMD_11
|ISM_BLOCK_PR_DZR2_CMD_11
|ISM_OP_PR_DZR2_CMD_11
|ISM_ZBR_BLOCK_DZR2_I_R_3G_CMD_11
|ISM_BLOCK_DZR2_CMD_11
|ISM_BLOCK_PR_DZR3_CMD_11
|ISM_OP_PR_DZR3_CMD_11
|ISM_ZBR_BLOCK_DZR3_I_R_3G_CMD_11
|ISM_BLOCK_DZR3_CMD_11
|ISM_BLOCK_UMIN1_CMD_11
|ISM_START_UMIN1_CMD_11
|ISM_BLOCK_UMIN2_CMD_11
|ISM_START_UMIN2_CMD_11
|ISM_BLOCK_UMAX1_CMD_11
|ISM_BLOCK_UMAX2_CMD_11
|ISM_BLOCK_UP1_CMD_11
|ISM_BLOCK_UP2_CMD_11
|ISM_BLOCK_UP3_CMD_11
|ISM_BLOCK_UP4_CMD_11
|ISM_BLOCK_UP5_CMD_11
|ISM_BLOCK_UP6_CMD_11
|ISM_BLOCK_UP7_CMD_11
|ISM_BLOCK_UP8_CMD_11
|ISM_DF1_IN_CMD_11
|ISM_DF2_IN_CMD_11
|ISM_DF3_IN_CMD_11
|ISM_DF4_IN_CMD_11
|ISM_DF5_IN_CMD_11
|ISM_DF6_IN_CMD_11
|ISM_DF7_IN_CMD_11
|ISM_DF8_IN_CMD_11
|ISM_DF9_IN_CMD_11
|ISM_DF10_IN_CMD_11
|ISM_DF11_IN_CMD_11
|ISM_DF12_IN_CMD_11
|ISM_DF13_IN_CMD_11
|ISM_DF14_IN_CMD_11
|ISM_DF15_IN_CMD_11
|ISM_DF16_IN_CMD_11
|ISM_DT1_SET_CMD_11
|ISM_DT1_RESET_CMD_11
|ISM_DT2_SET_CMD_11
|ISM_DT2_RESET_CMD_11
|ISM_DT3_SET_CMD_11
|ISM_DT3_RESET_CMD_11
|ISM_DT4_SET_CMD_11
|ISM_DT4_RESET_CMD_11
|ISM_LF1_CMD_11
|ISM_LF2_CMD_11
|ISM_LF3_CMD_11
|ISM_LF4_CMD_11
|ISM_LF5_CMD_11
|ISM_LF6_CMD_11
|ISM_LF7_CMD_11
|ISM_LF8_CMD_11
|ISM_LF9_CMD_11
|ISM_LF10_CMD_11
|ISM_LF11_CMD_11
|ISM_LF12_CMD_11
|ISM_LF13_CMD_11
|ISM_LF14_CMD_11
|ISM_LF15_CMD_11
|ISM_LF16_CMD_11

),

INPUT_SIGNALS_MASK_CMD_12 = (
ISM_LF2_CMD_12
|ISM_LF3_CMD_12
|ISM_LF4_CMD_12
|ISM_LF5_CMD_12
|ISM_LF6_CMD_12
|ISM_LF7_CMD_12
|ISM_LF8_CMD_12
|ISM_LF9_CMD_12
|ISM_LF10_CMD_12
|ISM_LF11_CMD_12
|ISM_LF12_CMD_12
|ISM_LF13_CMD_12
|ISM_LF14_CMD_12
|ISM_LF15_CMD_12
|ISM_LF16_CMD_12
),

	
};	


#endif

