#ifndef __GLOBAL_VARIABLES_H
#define __GLOBAL_VARIABLES_H

//Вимірювальна система
unsigned int semaphore_adc_irq;
unsigned int adc_DATA_VAL_read;
unsigned int adc_TEST_VAL_read;
unsigned int status_adc_read_work;
const unsigned int input_adc[NUMBER_INPUTs_ADCs][2]={
                                                     {1,0x8370},
                                                     {1,0x8770},
                                                     {1,0x8b70},
                                                     {1,0x8f70},
                                                     {1,0x9370},
                                                     {1,0x9770},
                                                     {1,0x9b70},
                                                     {1,0x9f70},
                                                     {1,0xa370},
                                                     {1,0xa770},
                                                     {1,0xab70},
                                                     {1,0xaf70},
                                                     {1,0xb370},
                                                     {1,0xb770},
                                                     {1,0xbb70},
                                                     {1,0xbf70}
                                                    };
EXTENDED_OUTPUT_DATA output_adc[NUMBER_INPUTs_ADCs];
ROZSHYRENA_VYBORKA rozshyrena_vyborka;

uint32_t tick_output_adc_p;
unsigned int command_word_adc, command_word_adc_work, active_index_command_word_adc;
unsigned int state_reading_ADCs = STATE_READING_ADCs_NONE;
unsigned int channel_request, channel_answer;

uint32_t step_timer_adc = TIM5_CCR1_2_VAL;
uint32_t penultimate_tick_DATA_VAL, previous_tick_DATA_VAL;

DATA_FOR_OSCYLOGRAPH data_for_oscylograph[MAX_INDEX_DATA_FOR_OSCYLOGRAPH];
unsigned int head_data_for_oscylograph;
unsigned int tail_data_for_oscylograph, DATA_VAL_tail_data_for_oscylograph;

VYBORKA_XY perechid_cherez_nul[MAX_INDEX_PhK][2];
unsigned int fix_perechid_cherez_nul[MAX_INDEX_PhK];
POPEREDNJY_PERECHID poperednij_perechid;

unsigned int maska_canaliv_fapch;
float frequency = -1;
float frequency_middle = -1;
unsigned int tick_period = (TIM5_CCR1_2_VAL*NUMBER_POINT), tick_period_work = (TIM5_CCR1_2_VAL*NUMBER_POINT);
unsigned int tick_c;

float freq_arr[N_F_AVER];
size_t index_freq_arr;
float sum_freq_arr;

float frequency_min = 50, frequency_max = 50;
unsigned int command_restart_monitoring_frequency;

const unsigned int index_VREF_ADC[NUMBER_VREF_ADC] = {C_VREF_ADC_1, C_VREF_ADC_2, C_VREF_ADC_3, C_VREF_ADC_4, C_VREF_ADC_5, C_VREF_ADC_6, C_VREF_ADC_7, C_VREF_ADC_8};
unsigned int vref_adc_moment_value[NUMBER_VREF_ADC][NUMBER_POINT];
unsigned int vref_adc_averange_sum[NUMBER_VREF_ADC];
unsigned int vref_adc_averange[NUMBER_VREF_ADC];
unsigned int vref_adc = VREF_NORMAL_VALUE;

unsigned int index_array_of_one_value;

EXTENDED_SAMPLE ADCs_data_raw[NUMBER_ANALOG_CANALES];
int ADCs_data[NUMBER_ANALOG_CANALES];

unsigned int changed_ustuvannja = CHANGED_ETAP_NONE; 
unsigned char crc_ustuvannja;
unsigned int ustuvannja_meas[NUMBER_ANALOG_CANALES] = {
                                                        DEFAULT_USTUVANNJA_VALUE,
                                                        DEFAULT_USTUVANNJA_VALUE,
                                                        DEFAULT_USTUVANNJA_VALUE,
                                                        DEFAULT_USTUVANNJA_VALUE
                                                      };
unsigned int ustuvannja[NUMBER_ANALOG_CANALES] = {
                                                        DEFAULT_USTUVANNJA_VALUE,
                                                        DEFAULT_USTUVANNJA_VALUE,
                                                        DEFAULT_USTUVANNJA_VALUE,
                                                        DEFAULT_USTUVANNJA_VALUE
                                                      };
SRAM1 unsigned int edit_ustuvannja[NUMBER_ANALOG_CANALES];
int phi_ustuvannja_meas[NUMBER_ANALOG_CANALES], phi_ustuvannja[NUMBER_ANALOG_CANALES];
SRAM1 int phi_edit_ustuvannja[NUMBER_ANALOG_CANALES];
float phi_ustuvannja_sin_cos_meas[2*NUMBER_ANALOG_CANALES] = {
                                                              0.0f, 1.0f,
                                                              0.0f, 1.0f,
                                                              0.0f, 1.0f,
                                                              0.0f, 1.0f
                                                             };
float phi_ustuvannja_sin_cos[2*NUMBER_ANALOG_CANALES] = {
                                                         0.0f, 1.0f,
                                                         0.0f, 1.0f,
                                                         0.0f, 1.0f,
                                                         0.0f, 1.0f
                                                        };
float phi_edit_ustuvannja_sin_cos[2*NUMBER_ANALOG_CANALES];

const float sin_data_f[NUMBER_POINT] = {
                                         0.000000000000000000000000000000f,
                                         0.195090322016128000000000000000f,
                                         0.382683432365090000000000000000f,
                                         0.555570233019602000000000000000f,
                                         0.707106781186547000000000000000f,
                                         0.831469612302545000000000000000f,
                                         0.923879532511287000000000000000f,
                                         0.980785280403230000000000000000f,
                                         1.000000000000000000000000000000f,
                                         0.980785280403230000000000000000f,
                                         0.923879532511287000000000000000f,
                                         0.831469612302545000000000000000f,
                                         0.707106781186548000000000000000f,
                                         0.555570233019602000000000000000f,
                                         0.382683432365090000000000000000f,
                                         0.195090322016129000000000000000f,
                                         0.000000000000000122514845490862f,
                                        -0.195090322016128000000000000000f,
                                        -0.382683432365090000000000000000f,
                                        -0.555570233019602000000000000000f,
                                        -0.707106781186547000000000000000f,
                                        -0.831469612302545000000000000000f,
                                        -0.923879532511287000000000000000f,
                                        -0.980785280403230000000000000000f,
                                        -1.000000000000000000000000000000f,
                                        -0.980785280403230000000000000000f,
                                        -0.923879532511287000000000000000f,
                                        -0.831469612302545000000000000000f,
                                        -0.707106781186548000000000000000f,
                                        -0.555570233019602000000000000000f,
                                        -0.382683432365090000000000000000f,
                                        -0.195090322016129000000000000000f
};

unsigned int index_period_array;
int data_sin[NUMBER_POINT][NUMBER_ANALOG_CANALES + 2];
int data_cos[NUMBER_POINT][NUMBER_ANALOG_CANALES + 2];
int ortogonal_irq[2*(NUMBER_ANALOG_CANALES + 2)];
int ortogonal[2*(NUMBER_ANALOG_CANALES + 2)][2];
unsigned int semaphore_measure_values_low;
unsigned int bank_ortogonal;


unsigned int semaphore_measure_values_low1;

unsigned int number_inputs_for_fix_one_second;
unsigned int number_inputs_for_fix_one_period;
unsigned int measurement[_NUMBER_IM]; 
unsigned int measurement_high[2][_NUMBER_IM], bank_measurement_high = 0; 
unsigned int measurement_middle[_NUMBER_IM]; 
SRAM1 unsigned int measurement_low[_NUMBER_IM]; 

const unsigned int index_converter[NUMBER_ANALOG_CANALES + 2]  = {FULL_ORT_Imn, FULL_ORT_Ibp , FULL_ORT_Umn , FULL_ORT_Ubp, FULL_ORT_3Imn, FULL_ORT_3Ibp};
int ortogonal_calc[2*FULL_ORT_MAX_TOTAL];
int ortogonal_calc_low[2*FULL_ORT_MAX_TOTAL];
int phi_angle[2][FULL_ORT_MAX];
uint32_t bank_for_calc_phi_angle, state_calc_phi_angle;
int base_index_for_angle = -1;

int P_plus[2][2];
int P_minus[2][2];
int Q_1q[2][2];
int Q_2q[2][2];
int Q_3q[2][2];
int Q_4q[2][2];
unsigned int lichylnyk_1s_po_20ms;
unsigned int bank_for_enegry;
int P[2][2], Q[2][2], cos_phi_x1000[2][2];
unsigned int S[2][2];
uint32_t bank_for_calc_power, state_calc_power;
double energy[2][MAX_NUMBER_INDEXES_ENERGY];
uint32_t state_calc_energy;
unsigned int clean_energy;
unsigned int information_about_clean_energy;

int resistance[MAX_NUMBER_INDEXES_RESISTANCE_FULL];
int resistance_middle[MAX_NUMBER_INDEXES_RESISTANCE];
SRAM1 int resistance_low[MAX_NUMBER_INDEXES_RESISTANCE];

int sector_1_mtz_tznp[8];
int sector_2_mtz_tznp[8];

//Конвертація "короткої" таблиці ранжування у "довгу"
const uint32_t small_big_rang[TOTAL_SIGNAL_FOR_RANG_SMALL_A01] =
{
RNG_BIG_BLOCK_VKL_VVO,
RNG_BIG_BLOCK_VKL_VVP,
RNG_BIG_RESET_LEDS,
RNG_BIG_RESET_RELES,
RNG_BIG_MISCEVE_DYSTANCIJNE,
RNG_BIG_STATE_VVR,
RNG_BIG_STATE_VVO,
RNG_BIG_VKL_VVO,
RNG_BIG_VKL_VVR,
RNG_BIG_CTRL_VKL_VVO,
RNG_BIG_CTRL_VKL_VVR,
RNG_BIG_OTKL_VV_VVO,
RNG_BIG_OTKL_VV_VVR,
RNG_BIG_CTRL_OTKL_VVO,
RNG_BIG_CTRL_OTKL_VVR,
RNG_BIG_1_GRUPA_USTAVOK,
RNG_BIG_2_GRUPA_USTAVOK,
RNG_BIG_3_GRUPA_USTAVOK,
RNG_BIG_4_GRUPA_USTAVOK,
RNG_BIG_RESET_BLOCK_READY_TU_VID_ZAHYSTIV, 

#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
RANG_BLOCK_IN_GOOSE1 + 0,
RANG_BLOCK_IN_GOOSE1 + 1,
RANG_BLOCK_IN_GOOSE1 + 2,
RANG_BLOCK_IN_GOOSE1 + 3,
RANG_BLOCK_IN_GOOSE1 + 4,
RANG_BLOCK_IN_GOOSE1 + 5,
RANG_BLOCK_IN_GOOSE1 + 6,
RANG_BLOCK_IN_GOOSE1 + 7,
RANG_BLOCK_IN_GOOSE1 + 8,
RANG_BLOCK_IN_GOOSE1 + 9,
RANG_BLOCK_IN_GOOSE1 + 10,
RANG_BLOCK_IN_GOOSE1 + 11,
RANG_BLOCK_IN_GOOSE1 + 12,
RANG_BLOCK_IN_GOOSE1 + 13,
RANG_BLOCK_IN_GOOSE1 + 14,
RANG_BLOCK_IN_GOOSE1 + 15,

RANG_BLOCK_IN_MMS1 + 0,
RANG_BLOCK_IN_MMS1 + 1,
RANG_BLOCK_IN_MMS1 + 2,
RANG_BLOCK_IN_MMS1 + 3,

RANG_BLOCK_OUT_LAN1 + 0,
RANG_BLOCK_OUT_LAN1 + 1,
RANG_BLOCK_OUT_LAN1 + 2,
RANG_BLOCK_OUT_LAN1 + 3,

#endif

RNG_BIG_ZVN_NESPR_DZO,
RNG_BIG_ZBR_BLOCK_DZO1_I_O_3G,
RNG_BIG_ZBR_BLOCK_DZO1_I_O,
RNG_BIG_BLOCK_DZO1,
    
RNG_BIG_BLOCK_PR_DZO2,
RNG_BIG_OP_PR_DZO2,
RNG_BIG_ZBR_BLOCK_DZO2_I_O_3G,
RNG_BIG_BLK_DZO2,
RNG_BIG_BLOCK_PR_DZO3,
RNG_BIG_OP_PR_DZO3,
RNG_BIG_ZBR_BLOCK_DZO3_I_O_3G,
RNG_BIG_BLK_DZO3,
RNG_BIG_ZBR_BLOCK_DZO4_I_O_3G,
RNG_BIG_BLK_DZO4,

RNG_BIG_BLOCK_ZDZ,
RNG_BIG_PUSK_ZDZ_VID_DV,

RNG_BIG_BLOCK_MCZO1,
RNG_BIG_BLOCK_MCZO2,
RNG_BIG_BLOCK_PR_MCZO2,
RNG_BIG_BLOCK_MCZO3,
RNG_BIG_BLOCK_MCZO4,
RNG_BIG_BLOCK_MCZR1,
RNG_BIG_BLOCK_MCZR2,

RNG_BIG_STAT_BLK_APV,

RNG_BIG_ACHR_CHAPV_VID_DV,
RNG_BIG_BLOCK_ACHR1,
RNG_BIG_BLOCK_ACHR2,

RNG_BIG_PUSK_UROV_VID_DV,

RNG_BIG_ZVN_NESPR_DZR,
RNG_BIG_ZBR_BLOCK_DZR1_I_R_3G,
RNG_BIG_ZBR_BLOCK_DZR1_I_R,
RNG_BIG_BLK_DZR1,
RNG_BIG_BLOCK_PR_DZR2,
RNG_BIG_OP_PR_DZR2,
RNG_BIG_ZBR_BLOCK_DZR2_I_R_3G,
RNG_BIG_BLK_DZR2,
RNG_BIG_BLOCK_PR_DZR3,
RNG_BIG_OP_PR_DZR3,
RNG_BIG_ZBR_BLOCK_DZR3_I_R_3G,
RNG_BIG_BLK_DZR3,

RNG_BIG_BLOCK_UMIN1,
RNG_BIG_START_UMIN1,
RNG_BIG_BLOCK_UMIN2,
RNG_BIG_START_UMIN2,

RNG_BIG_BLOCK_UMAX1,
RNG_BIG_BLOCK_UMAX2,

(RNG_BIG_BLOCK_UP1 + 3*0),
(RNG_BIG_BLOCK_UP1 + 3*1),
(RNG_BIG_BLOCK_UP1 + 3*2),
(RNG_BIG_BLOCK_UP1 + 3*3),
(RNG_BIG_BLOCK_UP1 + 3*4),
(RNG_BIG_BLOCK_UP1 + 3*5),
(RNG_BIG_BLOCK_UP1 + 3*6),
(RNG_BIG_BLOCK_UP1 + 3*7),

RNG_BIG_DF1_IN,
RNG_BIG_DF1_RST,
RNG_BIG_DF2_IN,
RNG_BIG_DF2_RST,
RNG_BIG_DF3_IN,
RNG_BIG_DF3_RST,
RNG_BIG_DF4_IN,
RNG_BIG_DF4_RST,
RNG_BIG_DF5_IN,
RNG_BIG_DF5_RST,
RNG_BIG_DF6_IN,
RNG_BIG_DF6_RST,
RNG_BIG_DF7_IN,
RNG_BIG_DF7_RST,
RNG_BIG_DF8_IN,
RNG_BIG_DF8_RST,
RNG_BIG_DF9_IN,
RNG_BIG_DF9_RST,
RNG_BIG_DF10_IN,
RNG_BIG_DF10_RST,
RNG_BIG_DF11_IN,
RNG_BIG_DF11_RST,
RNG_BIG_DF12_IN,
RNG_BIG_DF12_RST,
RNG_BIG_DF13_IN,
RNG_BIG_DF13_RST,
RNG_BIG_DF14_IN,
RNG_BIG_DF14_RST,
RNG_BIG_DF15_IN,
RNG_BIG_DF15_RST,
RNG_BIG_DF16_IN,
RNG_BIG_DF16_RST,
RNG_BIG_DT1_SET,
RNG_BIG_DT1_RESET,
RNG_BIG_DT2_SET,
RNG_BIG_DT2_RESET,
RNG_BIG_DT3_SET,
RNG_BIG_DT3_RESET,
RNG_BIG_DT4_SET,
RNG_BIG_DT4_RESET,
RNG_BIG_LF1,
RNG_BIG_LF2,
RNG_BIG_LF3,
RNG_BIG_LF4,
RNG_BIG_LF5,
RNG_BIG_LF6,
RNG_BIG_LF7,
RNG_BIG_LF8,
RNG_BIG_LF9,
RNG_BIG_LF10,
RNG_BIG_LF11,
RNG_BIG_LF12,
RNG_BIG_LF13,
RNG_BIG_LF14,
RNG_BIG_LF15,
RNG_BIG_LF16
};

//Спрямований МСЗ
unsigned int sector_directional_mtz[4][2];

//ЗДЗ
#if (                                   \
     (MODYFIKACIA_VERSII_PZ == 0) ||    \
     (MODYFIKACIA_VERSII_PZ == 3)       \
    )   
uint32_t delta_time_test = PERIOD_ZDZ_TEST;
uint32_t zdz_ovd_diagnostyka;
#endif

//Спрямований ДЗ
__sector_dz sector_directional_dz[4 - 2][2] = {{SECTOR_DZ_NONE, SECTOR_DZ_NONE}, {SECTOR_DZ_NONE, SECTOR_DZ_NONE}};

uint32_t TIM_PRT_write_tick;

//Світлоіндикатори
unsigned int state_leds;
unsigned int state_trigger_leds;
uint32_t state_leds_Fx[2];
uint32_t state_leds_ctrl;

unsigned int state_inputs; //"є сигнал " - відповідає встановленому біту (1); "немає сигналу" - відповідає скинутому біту (0)
unsigned int active_inputs; //"вхід активний" - відповідає встановленому біту (1); "вхід пасивний" - відповідає скинутому біту (0)
unsigned int state_outputs;
unsigned int state_outputs_raw;
unsigned int state_signal_outputs;
#ifdef NUMBER_DS
unsigned int ds;
#endif
unsigned int active_functions[N_BIG];
unsigned int trigger_active_functions[N_BIG], trigger_active_functions_ctrl[N_BIG];
unsigned char crc_trg_func, crc_trg_func_ctrl;
unsigned int trigger_functions_USB[N_BIG];
unsigned int trigger_functions_RS485[N_BIG];
unsigned int copying_active_functions;
unsigned int active_functions_copy[N_BIG];
unsigned int active_functions_trg[N_BIG];
unsigned int mutex_buttons;
unsigned int pressed_buttons;
unsigned int fix_active_buttons, fix_active_buttons_ctrl;
unsigned int mutex_interface;
unsigned int state_FK;
unsigned int activation_function_from_interface[N_SMALL];
unsigned int reset_trigger_function_from_interface;
unsigned int diagnostyka_before[N_DIAGN];
volatile unsigned int diagnostyka[N_DIAGN];
unsigned int set_diagnostyka[N_DIAGN];
unsigned int clear_diagnostyka[N_DIAGN];

uint32_t board_register;

int global_timers[MAX_NUMBER_GLOBAL_TIMERS]; //Масив глобальних таймерів
unsigned int timer_prt_signal_output_mode_2;
unsigned int output_timer_prt_signal_output_mode_2;
unsigned int static_logic_df;

unsigned int previous_states_APV_0;
unsigned int trigger_APV_0;

_Bool previous_state_po_achr_chapv_umnf1;
_Bool previous_state_po_achr_chapv_ubpf1;
_Bool previous_states_CHAPV1;
_Bool previous_states_CHAPV2;
_Bool trigger_CHAPV1;
_Bool trigger_CHAPV2;

_Bool previous_states_ready_tu;
_Bool trigger_ready_tu;

unsigned int start_restart = 0xff;

SRAM1 unsigned char working_ekran[MAX_ROW_LCD][MAX_COL_LCD];
unsigned int rewrite_ekran_once_more;

volatile unsigned int new_state_keyboard;
unsigned int new_state_keyboard_for_db;
unsigned char time_set_keyboard[NUMBER_KEY_KEYBOARD];

unsigned int time_rewrite; //Час який пройшов після останнього обновлення
unsigned int reinit_LCD;

SRAM1 __CURRENT_EKRAN current_ekran;
SRAM1 int position_in_current_level_menu[MAX_LEVEL_MENU]; //Масив у якому збкрігається індекс текучоїпозиції
SRAM1 int previous_level_in_current_level_menu[MAX_LEVEL_MENU]; //Масив у якому збкрігається занчення попередніх екранів для даного рівня меню
const uint32_t buttons_mode[NUMBER_BUTTON_MODE][N_SMALL] = 
{
  {MASKA_BUTTON_MODE_0_SIGNALS_A01_0, MASKA_BUTTON_MODE_0_SIGNALS_A01_1, MASKA_BUTTON_MODE_0_SIGNALS_A01_2, MASKA_BUTTON_MODE_0_SIGNALS_A01_3},
  {MASKA_BUTTON_MODE_1_SIGNALS_A01_0, MASKA_BUTTON_MODE_1_SIGNALS_A01_1, MASKA_BUTTON_MODE_1_SIGNALS_A01_2, MASKA_BUTTON_MODE_1_SIGNALS_A01_3}
};
const uint32_t output_boards[N_OUTPUT_BOARDS][2] = 
{
  { 2, 1},
  { 9, 4}
#if (                                   \
     (MODYFIKACIA_VERSII_PZ == 0) ||    \
     (MODYFIKACIA_VERSII_PZ == 1) ||    \
     (MODYFIKACIA_VERSII_PZ == 3)       \
    )
  ,
  {16, 5}
#endif
};
const uint32_t input_boards[N_INPUT_BOARDS][2] = 
{
  { 8, 4}
#if (                                   \
     (MODYFIKACIA_VERSII_PZ == 0) ||    \
     (MODYFIKACIA_VERSII_PZ == 1) ||    \
     (MODYFIKACIA_VERSII_PZ == 3)       \
    )
  ,
  {16, 5}
#if (MODYFIKACIA_VERSII_PZ == 0)
  ,
  {20, 7}
#endif
#endif
};
const uint8_t OFF_ON_value[MAX_NAMBER_LANGUAGE][NUMBER_OFF_ON] =
{
  {'O', 'P'},
  {'O', 'P'},
  {'M', 'R'},
  {'O', 'P'}
};

unsigned int periodical_tasks_TEST_SETTINGS;
unsigned int periodical_tasks_TEST_USTUVANNJA;
unsigned int periodical_tasks_TEST_TRG_FUNC;
unsigned int periodical_tasks_TEST_TRG_FUNC_LOCK;
unsigned int periodical_tasks_TEST_INFO_REJESTRATOR_AR;
unsigned int periodical_tasks_TEST_INFO_REJESTRATOR_AR_LOCK;
unsigned int periodical_tasks_TEST_INFO_REJESTRATOR_DR;
unsigned int periodical_tasks_TEST_INFO_REJESTRATOR_DR_LOCK;
unsigned int periodical_tasks_TEST_INFO_REJESTRATOR_PR_ERR;
unsigned int periodical_tasks_TEST_INFO_REJESTRATOR_PR_ERR_LOCK;
unsigned int periodical_tasks_TEST_RESURS;
unsigned int periodical_tasks_TEST_RESURS_LOCK;
unsigned int periodical_tasks_TEST_FLASH_MEMORY;
unsigned int periodical_tasks_CALCULATION_ANGLE;
unsigned int periodical_tasks_CALC_ENERGY_DATA;

const unsigned char odynyci_vymirjuvannja[MAX_NAMBER_LANGUAGE][NUMBER_ODYNYCI_VYMIRJUVANNJA] =
{
  {'А', 'В', 'с'},
  {'А', 'В', 'с'},
  {'A', 'V', 's'},
  {'А', 'В', 'с'}
};

const unsigned int size_dimension_array[MAX_NAMBER_LANGUAGE] = {SIZE_R_DIMENSION, SIZE_R_DIMENSION, SIZE_R_DIMENSION - 1, SIZE_R_DIMENSION};
const unsigned char resistance_dimension[MAX_NAMBER_LANGUAGE][SIZE_R_DIMENSION] = {"Ом", "Ом", "Ї ", "Ом"}; /*Ї тут іде як замінник великої букви Омега для англійської розкладки*/

unsigned int realDateTime;

const uint32_t max_value_for_tf[1 + TOTAL_NUMBER_PROTECTION][MAX_ROW_LIST_SOURCE_TF] =
{
  {
    1 + TOTAL_GENERAL_SIGNAL_FOR_RNG_BIG,
    1 + TOTAL_GENERAL_SIGNAL_FOR_RANG_SMALL
  },
  {
    1 + TOTAL_GENERAL_SIGNAL_FOR_RNG_BIG + TOTAL_DZO_SIGNAL_FOR_RNG_BIG,
    1 + TOTAL_GENERAL_SIGNAL_FOR_RANG_SMALL + TOTAL_DZO_SIGNAL_FOR_RANG_SMALL
  },
  {
    1 + TOTAL_GENERAL_SIGNAL_FOR_RNG_BIG + TOTAL_DZO_SIGNAL_FOR_RNG_BIG + TOTAL_MTZ_STUB_SIGNAL_FOR_RNG_BIG,
    1 + TOTAL_GENERAL_SIGNAL_FOR_RANG_SMALL + TOTAL_DZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MTZ_STUB_SIGNAL_FOR_RANG_SMALL
  },
  {
    1 + TOTAL_GENERAL_SIGNAL_FOR_RNG_BIG + TOTAL_DZO_SIGNAL_FOR_RNG_BIG + TOTAL_MTZ_STUB_SIGNAL_FOR_RNG_BIG + TOTAL_ZDZ_SIGNAL_FOR_RNG_BIG,
    1 + TOTAL_GENERAL_SIGNAL_FOR_RANG_SMALL + TOTAL_DZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MTZ_STUB_SIGNAL_FOR_RANG_SMALL + TOTAL_ZDZ_SIGNAL_FOR_RANG_SMALL
  },
  {
    1 + TOTAL_GENERAL_SIGNAL_FOR_RNG_BIG + TOTAL_DZO_SIGNAL_FOR_RNG_BIG + TOTAL_MTZ_STUB_SIGNAL_FOR_RNG_BIG + TOTAL_ZDZ_SIGNAL_FOR_RNG_BIG + TOTAL_MCZO_SIGNAL_FOR_RNG_BIG,
    1 + TOTAL_GENERAL_SIGNAL_FOR_RANG_SMALL + TOTAL_DZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MTZ_STUB_SIGNAL_FOR_RANG_SMALL + TOTAL_ZDZ_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZO_SIGNAL_FOR_RANG_SMALL
  },
  {
    1 + TOTAL_GENERAL_SIGNAL_FOR_RNG_BIG + TOTAL_DZO_SIGNAL_FOR_RNG_BIG + TOTAL_MTZ_STUB_SIGNAL_FOR_RNG_BIG + TOTAL_ZDZ_SIGNAL_FOR_RNG_BIG + TOTAL_MCZO_SIGNAL_FOR_RNG_BIG + TOTAL_MCZR_SIGNAL_FOR_RNG_BIG,
    1 + TOTAL_GENERAL_SIGNAL_FOR_RANG_SMALL + TOTAL_DZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MTZ_STUB_SIGNAL_FOR_RANG_SMALL + TOTAL_ZDZ_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZR_SIGNAL_FOR_RANG_SMALL
  },
  {
    1 + TOTAL_GENERAL_SIGNAL_FOR_RNG_BIG + TOTAL_DZO_SIGNAL_FOR_RNG_BIG + TOTAL_MTZ_STUB_SIGNAL_FOR_RNG_BIG + TOTAL_ZDZ_SIGNAL_FOR_RNG_BIG + TOTAL_MCZO_SIGNAL_FOR_RNG_BIG + TOTAL_MCZR_SIGNAL_FOR_RNG_BIG + TOTAL_APV_SIGNAL_FOR_RNG_BIG,
    1 + TOTAL_GENERAL_SIGNAL_FOR_RANG_SMALL + TOTAL_DZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MTZ_STUB_SIGNAL_FOR_RANG_SMALL + TOTAL_ZDZ_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZR_SIGNAL_FOR_RANG_SMALL + TOTAL_APV_SIGNAL_FOR_RANG_SMALL
  },
  {
    1 + TOTAL_GENERAL_SIGNAL_FOR_RNG_BIG + TOTAL_DZO_SIGNAL_FOR_RNG_BIG + TOTAL_MTZ_STUB_SIGNAL_FOR_RNG_BIG + TOTAL_ZDZ_SIGNAL_FOR_RNG_BIG + TOTAL_MCZO_SIGNAL_FOR_RNG_BIG + TOTAL_MCZR_SIGNAL_FOR_RNG_BIG + TOTAL_APV_SIGNAL_FOR_RNG_BIG + TOTAL_ACHR_SIGNAL_FOR_RANG_SMALL,
    1 + TOTAL_GENERAL_SIGNAL_FOR_RANG_SMALL + TOTAL_DZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MTZ_STUB_SIGNAL_FOR_RANG_SMALL + TOTAL_ZDZ_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZR_SIGNAL_FOR_RANG_SMALL + TOTAL_APV_SIGNAL_FOR_RANG_SMALL + TOTAL_ACHR_SIGNAL_FOR_RANG_SMALL
  },
  {
    1 + TOTAL_GENERAL_SIGNAL_FOR_RNG_BIG + TOTAL_DZO_SIGNAL_FOR_RNG_BIG + TOTAL_MTZ_STUB_SIGNAL_FOR_RNG_BIG + TOTAL_ZDZ_SIGNAL_FOR_RNG_BIG + TOTAL_MCZO_SIGNAL_FOR_RNG_BIG + TOTAL_MCZR_SIGNAL_FOR_RNG_BIG + TOTAL_APV_SIGNAL_FOR_RNG_BIG + TOTAL_ACHR_CHAPV_SIGNAL_FOR_RNG_BIG + TOTAL_UROV_SIGNAL_FOR_RNG_BIG,
    1 + TOTAL_GENERAL_SIGNAL_FOR_RANG_SMALL + TOTAL_DZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MTZ_STUB_SIGNAL_FOR_RANG_SMALL + TOTAL_ZDZ_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZR_SIGNAL_FOR_RANG_SMALL + TOTAL_APV_SIGNAL_FOR_RANG_SMALL + TOTAL_ACHR_SIGNAL_FOR_RANG_SMALL + TOTAL_UROV_SIGNAL_FOR_RANG_SMALL
  },
  {
    1 + TOTAL_GENERAL_SIGNAL_FOR_RNG_BIG + TOTAL_DZO_SIGNAL_FOR_RNG_BIG + TOTAL_MTZ_STUB_SIGNAL_FOR_RNG_BIG + TOTAL_ZDZ_SIGNAL_FOR_RNG_BIG + TOTAL_MCZO_SIGNAL_FOR_RNG_BIG + TOTAL_MCZR_SIGNAL_FOR_RNG_BIG + TOTAL_APV_SIGNAL_FOR_RNG_BIG + TOTAL_ACHR_CHAPV_SIGNAL_FOR_RNG_BIG + TOTAL_UROV_SIGNAL_FOR_RNG_BIG + TOTAL_DZR_SIGNAL_FOR_RNG_BIG,
    1 + TOTAL_GENERAL_SIGNAL_FOR_RANG_SMALL + TOTAL_DZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MTZ_STUB_SIGNAL_FOR_RANG_SMALL + TOTAL_ZDZ_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZR_SIGNAL_FOR_RANG_SMALL + TOTAL_APV_SIGNAL_FOR_RANG_SMALL + TOTAL_ACHR_SIGNAL_FOR_RANG_SMALL + TOTAL_UROV_SIGNAL_FOR_RANG_SMALL + TOTAL_DZR_SIGNAL_FOR_RANG_SMALL
  },
  {
    1 + TOTAL_GENERAL_SIGNAL_FOR_RNG_BIG + TOTAL_DZO_SIGNAL_FOR_RNG_BIG + TOTAL_MTZ_STUB_SIGNAL_FOR_RNG_BIG + TOTAL_ZDZ_SIGNAL_FOR_RNG_BIG + TOTAL_MCZO_SIGNAL_FOR_RNG_BIG + TOTAL_MCZR_SIGNAL_FOR_RNG_BIG + TOTAL_APV_SIGNAL_FOR_RNG_BIG + TOTAL_ACHR_CHAPV_SIGNAL_FOR_RNG_BIG + TOTAL_UROV_SIGNAL_FOR_RNG_BIG + TOTAL_DZR_SIGNAL_FOR_RNG_BIG + TOTAL_UMIN_SIGNAL_FOR_RNG_BIG,
    1 + TOTAL_GENERAL_SIGNAL_FOR_RANG_SMALL + TOTAL_DZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MTZ_STUB_SIGNAL_FOR_RANG_SMALL + TOTAL_ZDZ_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZR_SIGNAL_FOR_RANG_SMALL + TOTAL_APV_SIGNAL_FOR_RANG_SMALL + TOTAL_ACHR_SIGNAL_FOR_RANG_SMALL + TOTAL_UROV_SIGNAL_FOR_RANG_SMALL + TOTAL_DZR_SIGNAL_FOR_RANG_SMALL + TOTAL_UMIN_SIGNAL_FOR_RANG_SMALL
  },
  {
    1 + TOTAL_GENERAL_SIGNAL_FOR_RNG_BIG + TOTAL_DZO_SIGNAL_FOR_RNG_BIG + TOTAL_MTZ_STUB_SIGNAL_FOR_RNG_BIG + TOTAL_ZDZ_SIGNAL_FOR_RNG_BIG + TOTAL_MCZO_SIGNAL_FOR_RNG_BIG + TOTAL_MCZR_SIGNAL_FOR_RNG_BIG + TOTAL_APV_SIGNAL_FOR_RNG_BIG + TOTAL_ACHR_CHAPV_SIGNAL_FOR_RNG_BIG + TOTAL_UROV_SIGNAL_FOR_RNG_BIG + TOTAL_DZR_SIGNAL_FOR_RNG_BIG + TOTAL_UMIN_SIGNAL_FOR_RNG_BIG + TOTAL_UMAX_SIGNAL_FOR_RNG_BIG,
    1 + TOTAL_GENERAL_SIGNAL_FOR_RANG_SMALL + TOTAL_DZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MTZ_STUB_SIGNAL_FOR_RANG_SMALL + TOTAL_ZDZ_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZR_SIGNAL_FOR_RANG_SMALL + TOTAL_APV_SIGNAL_FOR_RANG_SMALL + TOTAL_ACHR_SIGNAL_FOR_RANG_SMALL + TOTAL_UROV_SIGNAL_FOR_RANG_SMALL + TOTAL_DZR_SIGNAL_FOR_RANG_SMALL + TOTAL_UMIN_SIGNAL_FOR_RANG_SMALL + TOTAL_UMAX_SIGNAL_FOR_RANG_SMALL
  },
  {
    1 + TOTAL_GENERAL_SIGNAL_FOR_RNG_BIG + TOTAL_DZO_SIGNAL_FOR_RNG_BIG + TOTAL_MTZ_STUB_SIGNAL_FOR_RNG_BIG + TOTAL_ZDZ_SIGNAL_FOR_RNG_BIG + TOTAL_MCZO_SIGNAL_FOR_RNG_BIG + TOTAL_MCZR_SIGNAL_FOR_RNG_BIG + TOTAL_APV_SIGNAL_FOR_RNG_BIG + TOTAL_ACHR_CHAPV_SIGNAL_FOR_RNG_BIG + TOTAL_UROV_SIGNAL_FOR_RNG_BIG + TOTAL_DZR_SIGNAL_FOR_RNG_BIG + TOTAL_UMIN_SIGNAL_FOR_RNG_BIG + TOTAL_UMAX_SIGNAL_FOR_RNG_BIG + TOTAL_UP_SIGNAL_FOR_RNG_BIG,
    1 + TOTAL_GENERAL_SIGNAL_FOR_RANG_SMALL + TOTAL_DZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MTZ_STUB_SIGNAL_FOR_RANG_SMALL + TOTAL_ZDZ_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZR_SIGNAL_FOR_RANG_SMALL + TOTAL_APV_SIGNAL_FOR_RANG_SMALL + TOTAL_ACHR_SIGNAL_FOR_RANG_SMALL + TOTAL_UROV_SIGNAL_FOR_RANG_SMALL + TOTAL_DZR_SIGNAL_FOR_RANG_SMALL + TOTAL_UMIN_SIGNAL_FOR_RANG_SMALL + TOTAL_UMAX_SIGNAL_FOR_RANG_SMALL + TOTAL_UP_SIGNAL_FOR_RANG_SMALL
  },
  {
    1 + TOTAL_GENERAL_SIGNAL_FOR_RNG_BIG + TOTAL_DZO_SIGNAL_FOR_RNG_BIG + TOTAL_MTZ_STUB_SIGNAL_FOR_RNG_BIG + TOTAL_ZDZ_SIGNAL_FOR_RNG_BIG + TOTAL_MCZO_SIGNAL_FOR_RNG_BIG + TOTAL_MCZR_SIGNAL_FOR_RNG_BIG + TOTAL_APV_SIGNAL_FOR_RNG_BIG + TOTAL_ACHR_CHAPV_SIGNAL_FOR_RNG_BIG + TOTAL_UROV_SIGNAL_FOR_RNG_BIG + TOTAL_DZR_SIGNAL_FOR_RNG_BIG + TOTAL_UMIN_SIGNAL_FOR_RNG_BIG + TOTAL_UMAX_SIGNAL_FOR_RNG_BIG + TOTAL_UP_SIGNAL_FOR_RNG_BIG + TOTAL_VMP_SIGNAL_FOR_RNG_BIG,
    1 + TOTAL_GENERAL_SIGNAL_FOR_RANG_SMALL + TOTAL_DZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MTZ_STUB_SIGNAL_FOR_RANG_SMALL + TOTAL_ZDZ_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZR_SIGNAL_FOR_RANG_SMALL + TOTAL_APV_SIGNAL_FOR_RANG_SMALL + TOTAL_ACHR_SIGNAL_FOR_RANG_SMALL + TOTAL_UROV_SIGNAL_FOR_RANG_SMALL + TOTAL_DZR_SIGNAL_FOR_RANG_SMALL + TOTAL_UMIN_SIGNAL_FOR_RANG_SMALL + TOTAL_UMAX_SIGNAL_FOR_RANG_SMALL + TOTAL_UP_SIGNAL_FOR_RANG_SMALL + TOTAL_VMP_SIGNAL_FOR_RANG_SMALL
  },
  {
    1 + TOTAL_GENERAL_SIGNAL_FOR_RNG_BIG + TOTAL_DZO_SIGNAL_FOR_RNG_BIG + TOTAL_MTZ_STUB_SIGNAL_FOR_RNG_BIG + TOTAL_ZDZ_SIGNAL_FOR_RNG_BIG + TOTAL_MCZO_SIGNAL_FOR_RNG_BIG + TOTAL_MCZR_SIGNAL_FOR_RNG_BIG + TOTAL_APV_SIGNAL_FOR_RNG_BIG + TOTAL_ACHR_CHAPV_SIGNAL_FOR_RNG_BIG + TOTAL_UROV_SIGNAL_FOR_RNG_BIG + TOTAL_DZR_SIGNAL_FOR_RNG_BIG + TOTAL_UMIN_SIGNAL_FOR_RNG_BIG + TOTAL_UMAX_SIGNAL_FOR_RNG_BIG + TOTAL_UP_SIGNAL_FOR_RNG_BIG + TOTAL_VMP_SIGNAL_FOR_RNG_BIG + TOTAL_EL_SIGNAL_FOR_RNG_BIG,
    1 + TOTAL_GENERAL_SIGNAL_FOR_RANG_SMALL + TOTAL_DZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MTZ_STUB_SIGNAL_FOR_RANG_SMALL + TOTAL_ZDZ_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZO_SIGNAL_FOR_RANG_SMALL + TOTAL_MCZR_SIGNAL_FOR_RANG_SMALL + TOTAL_APV_SIGNAL_FOR_RANG_SMALL + TOTAL_ACHR_SIGNAL_FOR_RANG_SMALL + TOTAL_UROV_SIGNAL_FOR_RANG_SMALL + TOTAL_DZR_SIGNAL_FOR_RANG_SMALL + TOTAL_UMIN_SIGNAL_FOR_RANG_SMALL + TOTAL_UMAX_SIGNAL_FOR_RANG_SMALL + TOTAL_UP_SIGNAL_FOR_RANG_SMALL + TOTAL_VMP_SIGNAL_FOR_RANG_SMALL + TOTAL_EL_SIGNAL_FOR_RANG_SMALL
  }
};


 
unsigned char calibration;

unsigned char time_edit[7]; 
unsigned char calibration_edit;

int etap_reset_of_bit = ETAP_CLEAR_OF_NONE;

char getzone_string[2][55];
size_t bank_getzone;
unsigned int lt_or_utc;
clock_t clk_count;
int32_t time_ms, time_ms_copy;
time_t time_dat, time_dat_copy;
unsigned int copying_time_to_RTC;
int32_t time_ms_RTC;
time_t time_dat_RTC;
unsigned int copying_time_dat;
int32_t time_ms_save_l, time_ms_save_h;
time_t time_dat_save_l, time_dat_save_h;
unsigned int save_time_dat_l, save_time_dat_h;

unsigned int changed_settings = CHANGED_ETAP_NONE; 
unsigned char crc_settings;
__SETTINGS current_settings_prt;
SRAM1 __SETTINGS current_settings, edition_settings, current_settings_interfaces;

//Визначення періодів у хвилину і більше
unsigned int number_seconds;
unsigned int number_minutes;

//Ресурс++
unsigned int restart_resurs_count;
unsigned int resurs_temp;
unsigned int resurs_global;
unsigned int resurs_global_min;
unsigned int resurs_global_max;

/* SRAM1 unsigned int restart_timing_watchdog;
SRAM1 unsigned int time_1_watchdog_input;
SRAM1 unsigned int time_2_watchdog_input;
SRAM1 unsigned int time_delta_watchdog_input;
SRAM1 unsigned int time_delta_watchdog_input_min;
SRAM1 unsigned int time_delta_watchdog_input_max;

SRAM1 unsigned int time_1_watchdog_output;
SRAM1 unsigned int time_2_watchdog_output;
SRAM1 unsigned int time_delta_watchdog_output;
SRAM1 unsigned int time_delta_watchdog_output_min;
SRAM1 unsigned int time_delta_watchdog_output_max; */

//I2C
unsigned char Temporaty_I2C_Buffer[MAX_NUMBER_REGISTERS_RTC + 2];
unsigned int number_busy_state;
unsigned int type_error_of_exchanging_via_i2c;
//unsigned int low_speed_i2c = 0;
__DRIVER_I2C driver_i2c;
unsigned int control_i2c_taskes[1];
unsigned int state_i2c_task = STATE_FIRST_READING_RTC;
unsigned char read_write_i2c_buffer[SIZE_BUFFER_FOR_I2C];

//Обмін через SPI1
unsigned char TxBuffer_SPI_EDF[SIZE_BUFFER_FOR_EDF];
unsigned char RxBuffer_SPI_EDF[SIZE_BUFFER_FOR_EDF];
int state_execution_spi1 = -1; //-1 - драйвер готовий до початку нових транзакцій; 0 - відбувається обмін; 1 - обмін завершений без помилок
unsigned int control_spi1_taskes[2];
unsigned int comparison_writing; /*очищений біт означає, що іде зчитування у робочий об'єкт, встановлений біт означає що іде порівняння записаної інформації після операції запису*/
unsigned int state_spi1_task;
int etap_eeprom_write_enable = -1;
unsigned int mutex_spi1;

//DataFlash
unsigned int number_bytes_transfer_spi_df;
unsigned int number_bytes_transfer_spi_df_copy;
unsigned char TxBuffer_SPI_DF_copy[SIZE_PAGE_DATAFLASH_MAX + 10];
unsigned int code_operation_copy;
int number_chip_dataflsh_exchange = -1;
__DRIVER_SPI_DF driver_spi_df[NUMBER_DATAFLASH_CHIP] = {
                                                        {TRANSACTION_EXECUTING_NONE, CODE_OPERATION_NONE},
                                                        {TRANSACTION_EXECUTING_NONE, CODE_OPERATION_NONE}
                                                       };
unsigned int error_into_spi_df;/*Ненульве значення означає, що зафіксована помилка при прийом/передачі через SPI_DF*/
unsigned int dataflash_not_busy;
volatile unsigned int control_tasks_dataflash;
SRAM1 unsigned char buffer_for_manu_read_record[SIZE_BUFFER_FOR_DR_RECORD];
SRAM1 unsigned char buffer_for_USB_read_record_ar[SIZE_PAGE_DATAFLASH_2];
SRAM1 unsigned char buffer_for_RS485_read_record_ar[SIZE_PAGE_DATAFLASH_2];
SRAM1 unsigned char buffer_for_USB_read_record_dr[SIZE_BUFFER_FOR_DR_RECORD];
SRAM1 unsigned char buffer_for_RS485_read_record_dr[SIZE_BUFFER_FOR_DR_RECORD];
SRAM1 unsigned char buffer_for_USB_read_record_pr_err[SIZE_ONE_RECORD_PR_ERR];
SRAM1 unsigned char buffer_for_RS485_read_record_pr_err[SIZE_ONE_RECORD_PR_ERR];

unsigned int what_we_are_reading_from_dataflash_1;

//FATFS
SRAM1 uint32_t FATFS_command;

//Аналоговий реєстратор
unsigned int start_ar;
unsigned char crc_info_rejestrator_ar;
__INFO_AR_REJESTRATOR info_rejestrator_ar;
unsigned char crc_info_rejestrator_ar_ctrl;
__INFO_AR_REJESTRATOR info_rejestrator_ar_ctrl;
unsigned int forbidden_new_record_ar_mode_0 /*= 0*/; 
unsigned int state_ar_record_m = STATE_AR_NONE_M, state_ar_record_prt = STATE_AR_NONE_PRT, state_ar_record_fatfs = STATE_AR_NONE_FATFS;
unsigned int prev_state_ar_record_m = STATE_AR_NONE_M;
SRAM1_AR short int array_ar[SIZE_BUFFER_FOR_AR];
SRAM1 short int word_SRAM1;
unsigned int index_array_ar_current /*= 0*/;
unsigned int index_array_ar_heat;
unsigned int index_array_ar_tail;
unsigned char tail_to_heat, current_to_tail;
int diff_index_heat_tail; /*ця змінна поки використовується мною тільки для діагностики*/
unsigned int prescaler_ar /*= 0*/; //Потрібний для того, щоб з 32 виборок на секунду зробити 16 виборки на секунду
__HEADER_AR header_ar;
unsigned char buffer_for_fs[SIZE_PAGE_DATAFLASH_2];
unsigned int fs_temporary_address;
volatile unsigned int fs_count_to_transfer;
unsigned int etap_writing_part_page_fs_into_dataflash = ETAP_NONE;
SRAM1 int number_record_of_ar_for_menu; //Це число означає, що номер запису не вибраний
SRAM1 int number_record_of_ar_for_USB; //Це число означає, що номер запису не вибраний
SRAM1 char id_ar_record_for_USB[8 + 1 + 3 + 1];
SRAM1 int max_number_time_sample_USB;
SRAM1 int number_record_of_ar_for_RS485; //Це число означає, що номер запису не вибраний
SRAM1 int first_number_time_sample_for_USB;// -1 - заголовок запису ан.р.; 0 - перший часовий зріз доаварійного масиву і т.д.
SRAM1 int last_number_time_sample_for_USB;// -1 - заголовок запису ан.р.; 0 - перший часовий зріз доаварійного масиву і т.д.
SRAM1 int first_number_time_sample_for_RS485;// -1 - заголовок запису ан.р.; 0 - перший часовий зріз доаварійного масиву і т.д.
SRAM1 int last_number_time_sample_for_RS485;// -1 - заголовок запису ан.р.; 0 - перший часовий зріз доаварійного масиву і т.д.
SRAM1 char id_ar_record_for_RS485[8 + 1 + 3 + 1];
SRAM1 int max_number_time_sample_RS485;

int32_t timePowerDown = -1;
int32_t timePowerDown_total = -1;
unsigned int truncPrefault;
unsigned int index_array_tail_min;
enum _fix_date_time_avar arDateTimeState = AVAR_DATE_TIME_NONE;

//Дискретний реєстратор
unsigned char crc_info_rejestrator_dr;
 __INFO_REJESTRATOR info_rejestrator_dr;
unsigned char crc_info_rejestrator_dr_ctrl;
__INFO_REJESTRATOR info_rejestrator_dr_ctrl;
unsigned int state_dr_record = STATE_DR_NO_RECORD;
unsigned int number_records_dr_waiting_for_saving_operation;
unsigned char buffer_for_save_dr_record[SIZE_BUFFER_FOR_DR_RECORD];
unsigned char buffer_for_save_dr_record_level_1[SIZE_BUFFER_FOR_DR_RECORD];
unsigned char buffer_for_save_dr_record_level_2[SIZE_BUFFER_FOR_DR_RECORD];
unsigned int part_writing_dr_into_dataflash;
unsigned int number_record_of_dr_for_menu = 0xffff; //Це число означає, що номер запису не вибраний
unsigned int number_record_of_dr_for_USB = 0xffff; //Це число означає, що номер запису не вибраний
unsigned int number_record_of_dr_for_RS485 = 0xffff; //Це число означає, що номер запису не вибраний
unsigned int part_reading_dr_from_dataflash_for_menu;
unsigned int part_reading_dr_from_dataflash_for_USB;
unsigned int part_reading_dr_from_dataflash_for_RS485;
unsigned int type_view_max_values_dr;
int index_cell_into_array_for_min_max_measurement_dr;

enum _fix_date_time_avar drDateTimeState = AVAR_DATE_TIME_NONE;

//Реєстратор програмних помилок
unsigned char crc_info_rejestrator_pr_err;
__INFO_REJESTRATOR info_rejestrator_pr_err;
unsigned char crc_info_rejestrator_pr_err_ctrl;
__INFO_REJESTRATOR info_rejestrator_pr_err_ctrl;
unsigned char buffer_pr_err_records[SIZE_BUFFER_FOR_PR_ERR];
volatile unsigned int head_fifo_buffer_pr_err_records;
unsigned int tail_fifo_buffer_pr_err_records;
unsigned int temporary_block_writing_records_pr_err_into_DataFlash;
unsigned int etap_writing_pr_err_into_dataflash = ETAP_NONE;
unsigned int number_recods_writing_into_dataflash_now;
unsigned int number_record_of_pr_err_into_menu = 0xffff;
unsigned int number_record_of_pr_err_into_USB = 0xffff;
unsigned int number_record_of_pr_err_into_RS485 = 0xffff;

//Очистка інформації по реєстраторах
unsigned int clean_rejestrators;

//Лічильник ресурсу
unsigned int koef_resurs_changed = CHANGED_ETAP_NONE;
float K_resurs_prt, K_resurs;
unsigned int resurs_vymykacha, resurs_vymykacha_ctrl;
unsigned int resurs_vidkljuchennja, resurs_vidkljuchennja_ctrl;
unsigned char crc_resurs, crc_resurs_ctrl;
unsigned int restart_counter;

//Визначення місця до пошкодження
unsigned int vymknennja_vid_KZ_prt;
unsigned int X_min_KZ_prt = (unsigned int)UNDEF_RESISTANCE;
int R_KZ_prt;

int VMP_last_KZ = UNDEF_VMP;
unsigned int equal_more_KZ;

//Перепрограмування приладу
unsigned int reprogram_device;

//RS-485
SRAM1 unsigned char TxBuffer_RS485[BUFFER_RS485];
SRAM1 unsigned char RxBuffer_RS485[BUFFER_RS485];
SRAM1 int TxBuffer_RS485_count;
SRAM1 int RxBuffer_RS485_count;
SRAM1 int RxBuffer_RS485_count_previous;
SRAM1 unsigned int time_last_receive_byte_RS485;
SRAM1 unsigned int max_reaction_time_rs_485;
SRAM1 unsigned int make_reconfiguration_RS_485;
SRAM1 unsigned int number_bits_rs_485_waiting;
SRAM1 unsigned int mark_current_tick_RS_485;
SRAM1 unsigned int timeout_idle_RS485;

//Для UDP
int count_out /*= 0*/;
int count_out_previous /*= 0*/;
uint16_t previous_count_tim4_USB;
u8 buffer_USB_in[BUFFER_USB_IN];
int from_USB_ptr_in;
int from_USB_ptr_in_irq;
int from_USB_ptr_out_irq;
unsigned char usb_received[BUFFER_USB];
u8 buffer_USB_out[BUFFER_USB_OUT];
int to_USB_ptr_in_irq;
int to_USB_ptr_out;
unsigned char usb_transmiting[BUFFER_USB];
int usb_received_count /*= 0*/;
int usb_transmiting_count /*= 0*/;
unsigned char data_usb_transmiting /*= false*/;
unsigned char data_usb_transmiting_irq;
unsigned int timeout_idle_USB;

//uint32_t USB_Tx_begin;
//uint32_t USB_Tx_end;
//uint8_t USB_Tx_last_buffer[256];
//uint32_t USB_Tx_count;

extern uint8_t  USB_Tx_State;

#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
//MODBUS-TCP
SRAM1 unsigned char LAN_received[BUFFER_LAN];
int LAN_received_count;
SRAM1 unsigned char LAN_transmiting[BUFFER_LAN];
int LAN_transmiting_count;

SRAM1 unsigned int timeout_idle_LAN;
SRAM1 unsigned int password_set_LAN;

char id_ar_record_for_LAN[8 + 1 + 3 + 1];
unsigned int trigger_functions_LAN[N_BIG];

SRAM1 unsigned char buffer_for_LAN_read_record_dr[SIZE_BUFFER_FOR_DR_RECORD];
unsigned int number_record_of_dr_for_LAN = 0xffff; //Це число означає, що номер запису не вибраний
unsigned int part_reading_dr_from_dataflash_for_LAN;

SRAM1 unsigned char buffer_for_LAN_read_record_pr_err[SIZE_ONE_RECORD_PR_ERR];
unsigned int number_record_of_pr_err_into_LAN = 0xffff;

int max_number_time_sample_LAN;
SRAM1 unsigned char buffer_for_LAN_read_record_ar[SIZE_PAGE_DATAFLASH_2];
int number_record_of_ar_for_LAN = -1; //Це число означає, що номер запису не вибраний
int first_number_time_sample_for_LAN;// -1 - заголовок запису ан.р.; 0 - перший часовий зріз доаварійного масиву і т.д.
int last_number_time_sample_for_LAN;// -1 - заголовок запису ан.р.; 0 - перший часовий зріз доаварійного масиву і т.д.
#endif

//MODBUS-RTU
SRAM1 unsigned int password_set_USB, password_set_RS485;
SRAM1 unsigned int password_changed;
SRAM1 unsigned int information_about_restart_counter;
SRAM1 unsigned int restart_timeout_interface;
SRAM1 unsigned int timeout_idle_new_settings;
SRAM1 unsigned int restart_timeout_idle_new_settings;
SRAM1 unsigned int type_of_settings_changed;

unsigned int serial_number_dev;                         //Заводський номер пристрою
SRAM1 unsigned int edit_serial_number_dev;

//Для відображення інформації про причину відключення
unsigned int info_vidkluchennja_vymykacha[2];
__info_vymk info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_MAX_NUMBER]; 

unsigned int  watchdog_l2;
unsigned int control_word_of_watchdog;
unsigned int test_watchdogs/* = 0*/;

/**************************************************************
 * Змінна використовується в функції вибору групи уставок:
 * protections.c --> setpoints_selecting()
 **************************************************************/
unsigned int gr_ustavok_tmp = 0xf;

#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
//Міжпроцесорний обмін
uint8_t Canal1_MO_Transmit[BUFFER_CANAL1_MO];
uint8_t Canal1_MO_Received[BUFFER_CANAL1_MO];
uint32_t confirm_diagnostyka_mo;
uint8_t Canal2_MO_Transmit[BUFFER_CANAL2_MO];
uint8_t Canal2_MO_Received[BUFFER_CANAL2_MO];
unsigned int Canal1, Canal2;
const uint8_t my_address_mo = 0;
uint32_t IEC_board_uncall = 500;
uint32_t IEC_board_address;
uint32_t queue_mo = (1u << STATE_QUEUE_MO_READ_FW_VERSION);
uint32_t queue_mo_irq;
unsigned int restart_KP_irq = 5;
uint32_t state_array_control_state;
uint8_t fwKP[4];
uint8_t fwDTKP[6];

uint8_t Input_In_GOOSE_block[N_IN_GOOSE];
uint8_t Input_ctrl_In_GOOSE_block[N_IN_GOOSE];

uint8_t Input_In_MMS_block[N_IN_MMS];
uint8_t Input_ctrl_In_MMS_block[N_IN_MMS];

uint8_t Output_Out_LAN_block[N_OUT_LAN];

unsigned int activation_function_from_KP[N_SMALL];
unsigned int ctrl_activation_function_from_KP[N_SMALL];

#endif

const unsigned char letters[69][2] =
{
{ 176, 223 },  //°
{ 178, 73  }, // І
{ 179, 105 }, // і
{ 192, 65  }, // А
{ 193, 160 }, // Б
{ 194, 66  }, // В
{ 195, 161 }, // Г
{ 196, 224 }, // Д
{ 197, 69  }, // Е
{ 168, 162 }, // Ё
{ 198, 163 }, // Ж
{ 199, 164 }, // З
{ 200, 165 }, // И
{ 201, 166 }, // Й
{ 202, 75  }, // К
{ 203, 167 }, // Л
{ 204, 77  }, // М
{ 205, 72  }, // Н
{ 206, 79  }, // О
{ 207, 168 }, // П
{ 208, 80  }, // Р
{ 209, 67  }, // С
{ 210, 84  }, // Т
{ 211, 169 }, // У
{ 212, 170 }, // Ф
{ 213, 88  }, // Х
{ 214, 225 }, // Ц
{ 215, 171 }, // Ч
{ 216, 172 }, // Ш
{ 217, 226 }, // Щ
{ 218, 173 }, // Ъ
{ 220, 98  }, // Ь
{ 219, 174 }, // Ы
{ 221, 175 }, // Э
{ 222, 176 }, // Ю
{ 223, 177 }, // Я
{ 224, 97  }, // а
{ 225, 178 }, // б
{ 226, 179 }, // в
{ 227, 180 }, // г
{ 228, 227 }, // д
{ 229, 101 }, // е
{ 184, 181 }, // ё
{ 230, 182 }, // ж
{ 231, 183 }, // з
{ 232, 184 }, // и
{ 233, 185 }, // й
{ 234, 186 }, // к
{ 235, 187 }, // л
{ 236, 188 }, // м
{ 237, 189 }, // н
{ 238, 111 }, // о
{ 239, 190 }, // п
{ 240, 112 }, // р
{ 241, 99  }, // с
{ 242, 191 }, // т
{ 243, 121 }, // у
{ 244, 228 }, // Ф
{ 245, 120 }, // х
{ 246, 229 }, // ц
{ 247, 192 }, // ч
{ 248, 193 }, // ш
{ 249, 230 }, // щ
{ 250, 194 }, // ъ
{ 252, 196 }, // ь
{ 251, 195 }, // ы
{ 253, 197 }, // э
{ 254, 198 }, // ю
{ 255, 199 } // я
};

const unsigned char extra_letters[12][1 + MAX_NAMBER_LANGUAGE] =
{
/*CODE   RU    UA    EN    KZ     */  
{ 0xAF, 0xFF, 0x00, 0x00, 0xFF}, // Ї або велика біква Омега для англійської розкладки клавіатури
{ 0xBF, 0xFF, 0x01, 0xFF, 0xFF}, // ї
{ 0xA5, 0xFF, 0x02, 0xFF, 0xFF}, // Ґ
{ 0xB4, 0xFF, 0x03, 0xFF, 0xFF}, // ґ
{ 0xAA, 0xFF, 0x04, 0xFF, 0xFF}, // Є
{ 0xBA, 0xFF, 0x05, 0xFF, 0xFF}, // є
{ 0x8A, 0xFF, 0xFF, 0xFF, 0x00}, // Љ - замінний символ з даним кодом для WIN1251
{ 0x9A, 0xFF, 0xFF, 0xFF, 0x01}, // љ - замінний символ з даним кодом для WIN1251
{ 0xBD, 0xFF, 0xFF, 0xFF, 0x02}, // Ѕ - замінний символ з даним кодом для WIN1251
{ 0xBE, 0xFF, 0xFF, 0xFF, 0x03}, // ѕ - замінний символ з даним кодом для WIN1251
{ 0x80, 0xFF, 0xFF, 0xFF, 0x04}, // Ђ - замінний символ з даним кодом для WIN1251
{ 0x90, 0xFF, 0xFF, 0xFF, 0x05}  // ђ - замінний символ з даним кодом для WIN1251
};

int current_language = LANGUAGE_ABSENT;

const uint8_t information_off_on[MAX_NAMBER_LANGUAGE][2][MAX_COL_LCD] = 
{
  {"     Откл.      ", "      Вкл.      "},
  {"     Вимк.      ", "     Увімк.     "},
  {"      Off       ", "       On       "},
  {"     Сљнд.      ", "     Косу.      "}
};
const uint32_t cursor_x_off_on[MAX_NAMBER_LANGUAGE][2] = 
{
 {4, 5},
 {4, 4},
 {5, 6},
 {4, 4}
};

extern unsigned short const __checksum;
extern unsigned int __checksum_begin;
extern unsigned int __checksum_end;

extern unsigned int __ICFEDIT_region_RAM1_start__;
extern unsigned int __ICFEDIT_region_RAM1_size__;

#ifdef DEBUG_TEST
//unsigned int time_1 = 0xffff0000, time_2 = 0xffff0000, max_delay = 0;

//Тимчасові змінні
//unsigned int temp_value_for_debbuging_1 = 0;
//unsigned int temp_value_for_debbuging_2 = 0;
//unsigned int temp_value_for_debbuging_3 = 0;


#endif



#endif
