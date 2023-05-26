#ifndef __CONST_MENU_CHOSE_EXTRA_SETTINGS__
#define __CONST_MENU_CHOSE_EXTRA_SETTINGS__

#define EKRAN_CHOSE_EXTRA_SETTINGS        (EKRAN_LEVEL_SET_NEW_PASSWORD3 + 1)

#define MAX_ROW_FOR_CHOSE_EXTRA_SETTINGS  4

#define INDEX_ML_CTREXTRA_SETTINGS_1_CTRL_READY_TU       0          
#define CTR_EXTRA_SETTINGS_1_CTRL_READY_TU               (1 << INDEX_ML_CTREXTRA_SETTINGS_1_CTRL_READY_TU)   
#define INDEX_ML_CTREXTRA_SETTINGS_1_CTRL_FB_ACTIVATION  1          
#define CTR_EXTRA_SETTINGS_1_CTRL_FB_ACTIVATION          (1 << INDEX_ML_CTREXTRA_SETTINGS_1_CTRL_FB_ACTIVATION)

//#define INDEX_ML_CTREXTRA_SETTINGS_1_CTRL_WINDOW_OFF_CB  2          
//#define CTR_EXTRA_SETTINGS_1_CTRL_WINDOW_OFF_CB          (1 << INDEX_ML_CTREXTRA_SETTINGS_1_CTRL_WINDOW_OFF_CB)   
  
//#define INDEX_ML_CTREXTRA_SETTINGS_1_BLK_ON_CB_MISCEVE   3          
//#define CTR_EXTRA_SETTINGS_1_BLK_ON_CB_MISCEVE           (1 << INDEX_ML_CTREXTRA_SETTINGS_1_BLK_ON_CB_MISCEVE)   
//#define INDEX_ML_CTREXTRA_SETTINGS_1_BLK_OFF_CB_MISCEVE  4          
//#define CTR_EXTRA_SETTINGS_1_BLK_OFF_CB_MISCEVE          (1 << INDEX_ML_CTREXTRA_SETTINGS_1_BLK_OFF_CB_MISCEVE)   

#define INDEX_ML_CTREXTRA_SETTINGS_1_CTRL_MALFUNCTION_U_MN       2          
#define CTR_EXTRA_SETTINGS_1_CTRL_MALFUNCTION_U_MN               (1 << INDEX_ML_CTREXTRA_SETTINGS_1_CTRL_MALFUNCTION_U_MN)   
#define INDEX_ML_CTREXTRA_SETTINGS_1_CTRL_MALFUNCTION_U_BP  3          
#define CTR_EXTRA_SETTINGS_1_CTRL_MALFUNCTION_U_BP          (1 << INDEX_ML_CTREXTRA_SETTINGS_1_CTRL_MALFUNCTION_U_BP)




//!#define CTR_EXTRA_SETTINGS_1_MASKA                       (                                         \
//!                                                          CTR_EXTRA_SETTINGS_1_CTRL_READY_TU      |\
//!                                                          CTR_EXTRA_SETTINGS_1_CTRL_WINDOW_OFF_CB |\
//!                                                          CTR_EXTRA_SETTINGS_1_CTRL_FB_ACTIVATION |\
//!                                                          CTR_EXTRA_SETTINGS_1_BLK_ON_CB_MISCEVE  |\
//!                                                          CTR_EXTRA_SETTINGS_1_BLK_OFF_CB_MISCEVE  \
//!                                                         )
#define CTR_EXTRA_SETTINGS_1_MASKA                       (CTR_EXTRA_SETTINGS_1_CTRL_READY_TU         |\
                                                          CTR_EXTRA_SETTINGS_1_CTRL_FB_ACTIVATION    |\
                                                          CTR_EXTRA_SETTINGS_1_CTRL_MALFUNCTION_U_MN |\
                                                          CTR_EXTRA_SETTINGS_1_CTRL_MALFUNCTION_U_BP \
                                                         )

#endif
