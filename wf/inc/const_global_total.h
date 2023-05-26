#ifndef __CONST_GLOBAL_TOTAL__
#define __CONST_GLOBAL_TOTAL__

#define MAX_NUMBER_LINES_VMP            8

#define NUMBER_LEDS                     17
#define NUMBER_OFF_ON                   2
#define NUMBER_UP                       8

//#define NUMBER_DEFINED_ELEMENTS         6
#define NUMBER_DEFINED_FUNCTIONS        16
#define NUMBER_DEFINED_TRIGGERS         4
#define NUMBER_DEFINED_AND              8
#define NUMBER_DEFINED_OR               8
#define NUMBER_DEFINED_XOR              8
#define NUMBER_DEFINED_NOT              16
#define NUMBER_TRANSFER_FUNCTIONS       16
#define NUMBER_LINK_FUNCTIONS           16

#define NUMBER_DEFINED_BUTTONS          6

#define NUMBER_IN_AND                   8
#define NUMBER_IN_OR                    8

#define NUMBER_GROUP_USTAVOK            4

enum _configuration {
DZ_BIT_CONFIGURATION = 0,CHP,
//MTZ_BIT_CONFIGURATION = CHP,
MTZ1_BIT_CONFIGURATION = CHP,
MTZ2_BIT_CONFIGURATION = CHP,
ZDZ_BIT_CONFIGURATION,
ZZ_BIT_CONFIGURATION,
TZNP_BIT_CONFIGURATION,
APV_BIT_CONFIGURATION,
ACHR_CHAPV_BIT_CONFIGURATION,
UROV_BIT_CONFIGURATION,
ZOP_BIT_CONFIGURATION,
UMIN_BIT_CONFIGURATION,
UMAX_BIT_CONFIGURATION,
UP_BIT_CONFIGURATION,
VMP_BIT_CONFIGURATION,
EL_BIT_CONFIGURATION,

TOTAL_NUMBER_PROTECTION,
DZO_BIT_CONFIGURATION = DZ_BIT_CONFIGURATION,
DZR_BIT_CONFIGURATION = ZOP_BIT_CONFIGURATION,
MCZO_BIT_CONFIGURATION = ZZ_BIT_CONFIGURATION,
MCZR_BIT_CONFIGURATION = TZNP_BIT_CONFIGURATION,
ZDZ_VOD_BIT_CONFIGURATION = ZDZ_BIT_CONFIGURATION

};

/*****************************************/
//Відключення від захистів
/*****************************************/
typedef enum __vymknennja_vid_zakhystiv__
{
  VYMKNENNJA_VID_DZ_1,
  VYMKNENNJA_VID_AMTZ_DZ_1,
  VYMKNENNJA_VID_DZ_2,
  VYMKNENNJA_VID_AMTZ_DZ_2,
  VYMKNENNJA_VID_DZ_3,
  VYMKNENNJA_VID_AMTZ_DZ_3,
  VYMKNENNJA_VID_DZ_4,
  VYMKNENNJA_VID_AMTZ_DZ_4,
  
  VYMKNENNJA_VID_MTZ1,
  VYMKNENNJA_VID_MTZ2,
  VYMKNENNJA_VID_MTZ3,
  VYMKNENNJA_VID_MTZ4,
  
  VYMKNENNJA_VID_ZDZ,

  VYMKNENNJA_VID_3I0,
  VYMKNENNJA_VID_3U0,
  VYMKNENNJA_VID_NZZ,

  VYMKNENNJA_VID_TZNP1,
  VYMKNENNJA_VID_TZNP2,
  VYMKNENNJA_VID_TZNP3,

  VYMKNENNJA_VID_ACHR_CHAPV_VID_DV,
  VYMKNENNJA_VID_ACHR_CHAPV1,
  VYMKNENNJA_VID_ACHR_CHAPV2,

  VYMKNENNJA_VID_UROV1,
  VYMKNENNJA_VID_UROV2,

  VYMKNENNJA_VID_ZOP,

  VYMKNENNJA_VID_UMIN1,
  VYMKNENNJA_VID_UMIN2,

  VYMKNENNJA_VID_UMAX1,
  VYMKNENNJA_VID_UMAX2,

  VYMKNENNJA_VID_UP1,
  
  VYMKNENNJA_VID_ZOVNISHNIKH_ZAKHYSTIV = VYMKNENNJA_VID_UP1 + NUMBER_UP,
  
  VYMKNENNJA_VID_INSHYKH_SYGNALIV,
    
  VYMKNENNJA_VID_MAX_NUMBER  
  
}__vymknennja_vid_zakhystiv;
/*****************************************/

/*****************************************/
//Світлоіндикатори
/*****************************************/
//Нумерація  усправлінських світлоіндикаторів
enum _leds_ctrl
{
  LED_CTRL_R_E = 0,
  LED_CTRL_START,
  LED_CTRL_TRIP,
  LED_CTRL_I,
  LED_CTRL_O
};

enum _leds_colors
{
  LED_COLOR_RED_BIT = 0,
  LED_COLOR_GREEN_BIT,
  
  NUMBER_LED_COLOR
};

//Кількість управлінських стовпців
#define LED_N_COL       7
#define LED_N_ROW       8
/*****************************************/

/*****************************************/
//Максимальна кількість сигналів (функцій), які можуть бути зранжовані на входи/виходи/світлоіндикатори/д.реєстратор/оф
/*****************************************/
#define VAGA_MAX_FUNCTIONS_IN_INPUT             3
#define MAX_FUNCTIONS_IN_INPUT                  (1u << VAGA_MAX_FUNCTIONS_IN_INPUT)
#define VAGA_MAX_FUNCTIONS_IN_OUTPUT            4
#define MAX_FUNCTIONS_IN_OUTPUT                 (1u << VAGA_MAX_FUNCTIONS_IN_OUTPUT)
#define VAGA_MAX_FUNCTIONS_IN_LED               3
#define MAX_FUNCTIONS_IN_LED                    (1u << VAGA_MAX_FUNCTIONS_IN_LED)
#define VAGA_MAX_FUNCTIONS_IN_DF                4
#define MAX_FUNCTIONS_IN_DF                     (1u << VAGA_MAX_FUNCTIONS_IN_DF)
#define MAX_FUNCTIONS_IN_DT                     6
#define MAX_FUNCTIONS_IN_D_AND                  NUMBER_IN_AND
#define MAX_FUNCTIONS_IN_D_OR                   NUMBER_IN_OR
#define MAX_FUNCTIONS_IN_D_XOR                  2
#define MAX_FUNCTIONS_IN_D_NOT                  1
#define VAGA_MAX_FUNCTIONS_IN_DB                3
#define MAX_FUNCTIONS_IN_DB                     (1u << VAGA_MAX_FUNCTIONS_IN_DB)
#define VAGA_MAX_FUNCTIONS_IN_AREG              5
#define MAX_FUNCTIONS_IN_AREG                   (1u << VAGA_MAX_FUNCTIONS_IN_AREG)
#define VAGA_MAX_FUNCTIONS_IN_DREG              5
#define MAX_FUNCTIONS_IN_DREG                   (1u << VAGA_MAX_FUNCTIONS_IN_DREG)
#define VAGA_MAX_FUNCTIONS_IN_OFF_CB            5
#define MAX_FUNCTIONS_IN_OFF_CB                 (1u << VAGA_MAX_FUNCTIONS_IN_OFF_CB)
#define VAGA_MAX_FUNCTIONS_IN_ON_CB             5
#define MAX_FUNCTIONS_IN_ON_CB                  (1u << VAGA_MAX_FUNCTIONS_IN_ON_CB)
/*****************************************/

/*****************************************/
//Константи для пам'яті
/*****************************************/
#define EXT_SRAM_512
/*****************************************/


/*****************************************/
//Константи для комунікації
/*****************************************/
#define MAX_CHAR_IN_NAME_OF_CELL                              32
/*****************************************/

/*****************************************/
//Константи для фіксації зміни настройок
/*****************************************/
#define CHANGED_ETAP_NONE                                     0
#define CHANGED_ETAP_EXECUTION                                1
#define CHANGED_ETAP_ENDED                                    2
#define CHANGED_ETAP_ENDED_EXTRA_ETAP                         3
/*****************************************/

/*****************************************/
/*****************************************/
enum __odynyci_vymirjuvannja {
INDEX_A = 0,
INDEX_V,
INDEX_SECOND,

NUMBER_ODYNYCI_VYMIRJUVANNJA
};

#define SIZE_R_DIMENSION    2
/*****************************************/

/*****************************************/
//Індетифікатор типу набору юстуючих коефіцієнтів
/*****************************************/
//#define ADJUSTMENT_3I0_IA_IB_IC                             1
//#define ADJUSTMENT_3I0_IA_IC_3U0                            2
//#define ADJUSTMENT_3I0_IA_IB_IC_UA_UB_UC_UABTN2             3
//#define ADJUSTMENT_3I0_IA_IB_IC_UA_UB_UC_3U0                  4
#define ADJUSTMENT_IMN_IBP_UMN_UBP                            5
#define ADJUSTMENT_ID                                         ADJUSTMENT_IMN_IBP_UMN_UBP
/*****************************************/

/*****************************************/
//Версія універсальної карти памяті
/*****************************************/
#define VERSIA_GMM                                             9
#define MODYFIKACIA_VERSII_GMM                                 0
/*****************************************/
#endif
