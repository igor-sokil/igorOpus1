#ifndef __CONST_MENU_DIAGNOSTYKA__
#define __CONST_MENU_DIAGNOSTYKA__

#define EKRAN_DIAGNOSTYKA                    (EKRAN_POINT_TIME_RANGUVANNJA + 1)

enum _error_id 
{
ERROR_START_VIA_I2C_BIT = 0,
ERROR_SETTINGS_EEPROM_BIT,
ERROR_SETTINGS_EEPROM_EMPTY_BIT,
ERROR_SETTINGS_EEPROM_COMPARISON_BIT,
ERROR_SETTINGS_EEPROM_CONTROL_BIT,
ERROR_SETTINGS_EEPROM_DEVICE_ID_FAIL_BIT,
ERROR_USTUVANNJA_EEPROM_BIT,
ERROR_USTUVANNJA_EEPROM_EMPTY_BIT,
ERROR_USTUVANNJA_EEPROM_COMPARISON_BIT,
ERROR_USTUVANNJA_EEPROM_CONTROL_BIT,
ERROR_USTUVANNJA_EEPROM_ADJUSTMENT_ID_FAIL_BIT,
ERROR_STATE_LEDS_EEPROM_BIT,
ERROR_STATE_OUTPUTS_EEPROM_BIT,
ERROR_STATE_LEDS_OUTPUTS_EEPROM_EMPTY_BIT,
ERROR_STATE_LEDS_OUTPUTS_EEPROM_COMPARISON_BIT,
ERROR_TRG_FUNC_EEPROM_BIT,
ERROR_TRG_FUNC_EEPROM_EMPTY_BIT,
ERROR_TRG_FUNC_EEPROM_COMPARISON_BIT,
ERROR_TRG_FUNC_EEPROM_CONTROL_BIT,
ERROR_INFO_REJESTRATOR_AR_EEPROM_BIT,
ERROR_INFO_REJESTRATOR_AR_EEPROM_EMPTY_BIT,
ERROR_INFO_REJESTRATOR_AR_COMPARISON_BIT,
ERROR_INFO_REJESTRATOR_AR_CONTROL_BIT,
ERROR_INFO_REJESTRATOR_DR_EEPROM_BIT,
ERROR_INFO_REJESTRATOR_DR_EEPROM_EMPTY_BIT,
ERROR_INFO_REJESTRATOR_DR_COMPARISON_BIT,
ERROR_INFO_REJESTRATOR_DR_CONTROL_BIT,
ERROR_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT,
ERROR_INFO_REJESTRATOR_PR_ERR_EEPROM_EMPTY_BIT,
ERROR_INFO_REJESTRATOR_PR_ERR_COMPARISON_BIT,
ERROR_INFO_REJESTRATOR_PR_ERR_CONTROL_BIT,
ERROR_RESURS_EEPROM_BIT,
ERROR_RESURS_EEPROM_EMPTY_BIT,
ERROR_RESURS_EEPROM_COMPARISON_BIT,
ERROR_RESURS_EEPROM_CONTROL_BIT,
ERROR_ENERGY_EEPROM_BIT,
ERROR_ENERGY_EEPROM_EMPTY_BIT,
ERROR_ENERGY_EEPROM_COMPARISON_BIT,

RTC_BATTERY_LOW_BIT,
RTC_OSCILLATOR_STOPED_BIT,
RTC_OSCILLATOR_FAIL_BIT,
RTC_UPDATING_HALTED_BIT,
RTC_WORK_FIELD_NOT_SET_BIT,

ERROR_VREF_ADC_TEST_BIT,
ERROR_VREF_ADC_TEST_COARSE_BIT,

ERROR_SPI_ADC_BIT,

ERROR_OSCYLOJRAPH_OVERFLOW,

ERROR_DIGITAL_OUTPUT_1_BIT,

ERROR_DS_OUTPUT_BIT = ERROR_DIGITAL_OUTPUT_1_BIT + 16,

ERROR_AR_TEMPORARY_BUSY_BIT = ERROR_DS_OUTPUT_BIT + 1,
ERROR_AR_OVERLOAD_BUFFER_BIT,
ERROR_AR_MEMORY_FULL_BIT,
ERROR_AR_UNDEFINED_BIT,

ERROR_DR_TEMPORARY_BUSY_BIT,
ERROR_DR_UNDEFINED_BIT,
ERROR_DR_LOSS_INFORMATION_BIT,

ERROR_PR_ERR_OVERLOAD_BIT,
ERROR_PR_ERR_LOSS_INFORMATION_BIT,

EVENT_START_SYSTEM_BIT,
EVENT_RESTART_SYSTEM_BIT,
EVENT_SOFT_RESTART_SYSTEM_BIT,
EVENT_STOP_SYSTEM_BIT,
EVENT_DROP_POWER_BIT,

ERROR_LCD_BIT,
ERROR_SPI_EDF_BIT,
ERROR_EXTERNAL_SRAM_BIT,
ERROR_INTERNAL_FLASH_BIT,

ERROR_SELECT_GRUPY_USRAVOK,

LOSE_ENERGY_DATA,

TEST_OVD1,
TEST_OVD2,
TEST_OVD3,

ERROR_BA_1_FIX,
ERROR_BA_1_CTLR,
ERROR_BDVV5_1_FIX,
ERROR_BDVV5_1_CTLR,
ERROR_BDVV5_2_FIX,
ERROR_BDVV5_2_CTLR,
ERROR_BDV_DZ_FIX,
ERROR_BDV_DZ_CTLR,
ERROR_BDZ_FIX,
ERROR_BDZ_CTLR,

ERROR_FATFS,
WARNING_REPROGRAM,

MAX_ROW_FOR_DIAGNOSTYKA
};

#define N_DIAGN                              ((MAX_ROW_FOR_DIAGNOSTYKA >> 5) + ((MAX_ROW_FOR_DIAGNOSTYKA & 0x1f) != 0))
#define N_DIAGN_BYTES                        ((MAX_ROW_FOR_DIAGNOSTYKA >> 3) + ((MAX_ROW_FOR_DIAGNOSTYKA & 0x07) != 0))

#define MASKA_AVAR_ERROR_0        (unsigned int)(               \
    (1 << (ERROR_SETTINGS_EEPROM_BIT))                          \
  | (1 << (ERROR_SETTINGS_EEPROM_EMPTY_BIT))                    \
  | (1 << (ERROR_SETTINGS_EEPROM_COMPARISON_BIT) )              \
  | (1 << (ERROR_SETTINGS_EEPROM_CONTROL_BIT))                  \
  | (1 << (ERROR_USTUVANNJA_EEPROM_BIT) )                       \
  | (1 << (ERROR_USTUVANNJA_EEPROM_EMPTY_BIT))                  \
  | (1 << (ERROR_USTUVANNJA_EEPROM_COMPARISON_BIT))             \
  | (1 << (ERROR_USTUVANNJA_EEPROM_CONTROL_BIT))                \
  | (1 << (ERROR_USTUVANNJA_EEPROM_ADJUSTMENT_ID_FAIL_BIT))     \
  | (1 << (ERROR_TRG_FUNC_EEPROM_BIT))                          \
  | (1 << (ERROR_TRG_FUNC_EEPROM_EMPTY_BIT))                    \
  | (1 << (ERROR_TRG_FUNC_EEPROM_COMPARISON_BIT))               \
  | (1 << (ERROR_TRG_FUNC_EEPROM_CONTROL_BIT))                  \
)

#define MASKA_AVAR_ERROR_1        (unsigned int)(               \
    (1 << (ERROR_VREF_ADC_TEST_BIT - 32))                       \
  | (1 << (ERROR_VREF_ADC_TEST_COARSE_BIT - 32))                \
  | (1 << (ERROR_SPI_ADC_BIT - 32))                             \
  | (1 << (ERROR_DIGITAL_OUTPUT_1_BIT +  0 - 32))               \
  | (1 << (ERROR_DIGITAL_OUTPUT_1_BIT +  1 - 32))               \
  | (1 << (ERROR_DIGITAL_OUTPUT_1_BIT +  2 - 32))               \
  | (1 << (ERROR_DIGITAL_OUTPUT_1_BIT +  3 - 32))               \
  | (1 << (ERROR_DIGITAL_OUTPUT_1_BIT +  4 - 32))               \
  | (1 << (ERROR_DIGITAL_OUTPUT_1_BIT +  5 - 32))               \
  | (1 << (ERROR_DIGITAL_OUTPUT_1_BIT +  6 - 32))               \
  | (1 << (ERROR_DIGITAL_OUTPUT_1_BIT +  7 - 32))               \
  | (1 << (ERROR_DIGITAL_OUTPUT_1_BIT +  8 - 32))               \
  | (1 << (ERROR_DIGITAL_OUTPUT_1_BIT +  9 - 32))               \
  | (1 << (ERROR_DIGITAL_OUTPUT_1_BIT + 10 - 32))               \
  | (1 << (ERROR_DIGITAL_OUTPUT_1_BIT + 11 - 32))               \
  | (1 << (ERROR_DIGITAL_OUTPUT_1_BIT + 12 - 32))               \
  | (1 << (ERROR_DIGITAL_OUTPUT_1_BIT + 13 - 32))               \
  | (1 << (ERROR_DIGITAL_OUTPUT_1_BIT + 14 - 32))               \
  | (1 << (ERROR_DIGITAL_OUTPUT_1_BIT + 15 - 32))               \
  | (1 << (ERROR_DS_OUTPUT_BIT - 32))                           \
)

#define MASKA_AVAR_ERROR_2        (unsigned int)(               \
    (1 << (ERROR_INTERNAL_FLASH_BIT - 64))                      \
  | (1 << (ERROR_BA_1_FIX - 64))                                \
  | (1 << (ERROR_BA_1_CTLR - 64))                               \
  | (1 << (ERROR_BDVV5_1_FIX - 64))                             \
  | (1 << (ERROR_BDVV5_1_CTLR - 64))                            \
  | (1 << (ERROR_BDVV5_2_FIX - 64))                             \
  | (1 << (ERROR_BDVV5_2_CTLR - 64))                            \
  | (1 << (ERROR_BDV_DZ_FIX - 64))                              \
  | (1 << (ERROR_BDV_DZ_CTLR - 64))                             \
  | (1 << (ERROR_BDZ_FIX - 64))                                 \
)


#define MASKA_AVAR_ERROR_3        (unsigned int)(               \
    (1 << (ERROR_BDZ_CTLR - 96))                                \
  | (1 << (WARNING_REPROGRAM - 96))                             \
)


# define NAME_DIAGN_RU  \
  " ��.I2C         ",   \
  " ��.��������    ",   \
  " �������� ���   ",   \
  " ��.���.�����.  ",   \
  " ��.�����.�����.",   \
  " ��.���� �����. ",   \
  " ��.����������� ",   \
  " ����������� ���",   \
  " ��.���.�����.  ",   \
  " ��.�����.�����.",   \
  " ��.�����.������",   \
  " ��.��c��.��.�� ",   \
  " ��.��c��.�.��� ",   \
  "���.���./��.��� ",   \
  " ��.���.���./��.",   \
  "  ��.��.������� ",   \
  " ��.������� ��� ",   \
  " ��.�.��.�������",   \
  " ��.�.��.�������",   \
  " ��.���.��.���. ",   \
  " ���.��.���.��� ",   \
  "��.���.�.��.���.",   \
  "��.�����.��.���.",   \
  " ��.���.�.���.  ",   \
  " ���.�.���.���  ",   \
  " ��.���.�.�.���.",   \
  " ��.�����.�.���.",   \
  "��.���.���.��.�.",   \
  "���.���.��.�.���",   \
  "��.���.�.�.��.�.",   \
  "��.�����.�.��.�.",   \
  " ��.���.��.���. ",   \
  " ���.��.���.��� ",   \
  " ��.���.��.���. ",   \
  "��.�����.��.���.",   \
  " ��.�.�.������� ",   \
  " ������� ���    ",   \
  " ��.���.������� ",   \
  " ������� ������.",   \
  "��������� �����.",   \
  "����� ����������",   \
  " ���.������.RTC ",   \
  " �� ���.���� RTC",   \
  " ���� VREF ���  ",   \
  "���� VREF ��� ��",   \
  " ��. SPI ���    ",   \
  "�����.���.�.���.",   \
  " ��.���.���� ?.?",   \
  " ��.���.���� ?.?",   \
  " ��.���.���� ?.?",   \
  " ��.���.���� ?.?",   \
  " ��.���.���� ?.?",   \
  " ��.���.���� ?.?",   \
  " ��.���.���� ?.?",   \
  " ��.���.���� ?.?",   \
  " ��.���.���� ?.?",   \
  " ��.���.���� ?.?",   \
  " ��.���.���� ?.?",   \
  " ��.���.���� ?.?",   \
  " ��.���.���� ?.?",   \
  " ��.���.���� ?.?",   \
  " ��.���.���� ?.?",   \
  " ��.���.���� ?.?",   \
  " ��.���.��      ",   \
  "��.���.��.�����.",   \
  " ���.���.a�.���.",   \
  " �.a�.���.���.  ",   \
  "�����.��.��.���.",   \
  " �.���.��.�����.",   \
  " �����.��.�.���.",   \
  " ������ �.�.���.",   \
  "�����.���.��.��.",   \
  " ������ �.��.��.",   \
  " ����� ����.    ",   \
  " ������� ����.  ",   \
  "��.������� ����.",   \
  " �������.����.  ",   \
  " ������.������� ",   \
  " ����� ���      ",   \
  " ��.SPI_EDF     ",   \
  " ��.������� SRAM",   \
  " ��.�����.FLASH ",   \
  " ��.���.��.���. ",   \
  " ���.�.�������  ",   \
  " ���� ���1      ",   \
  " ���� ���2      ",   \
  " ���� ���3      ",   \
  " ��1 ��.        ",   \
  " ��1 �.         ",   \
  " ����5_1 ��.    ",   \
  " ����5_1 �.     ",   \
  " ����5_2 ��.    ",   \
  " ����5_2 �.     ",   \
  " ���-�� ��.     ",   \
  " ���-�� �.      ",   \
  " ��� ��.        ",   \
  " ��� �.         ",   \
  " ��.�.�.        ",   \
  "����� ���������."   

# define NAME_DIAGN_UA  \
  " ���.I2C        ",   \
  " ���.�����������",   \
  "����������� ����",   \
  " ���.���.������.",   \
  "���.�����.������",   \
  " ���.���� ������",   \
  " ���.���������  ",   \
  " ��������� ���� ",   \
  " ���.���.���.   ",   \
  " ���.�����.���. ",   \
  " ���.���.������ ",   \
  " ���.���.��.��.",   \
  " ���.���.�.���.",   \
  "���.���./��.����",   \
  "���.���.���./��.",   \
  " ���.��.������� ",   \
  " ��.������� ����",   \
  "���.�.��.�������",   \
  "���.�.��.�������",   \
  " ���.���.��.�.  ",   \
  " ���.��.�.����  ",   \
  " ���.���.�.��.�.",   \
  " ���.�����.��.�.",   \
  " ���.���.�.�.   ",   \
  " ���.�.�.����   ",   \
  " ���.���.�.�.�. ",   \
  " ���.�����.�.�. ",   \
  " ���.���.�.��.�.",   \
  " ���.�.��.�.����",   \
  "���.���.�.�.��.�",   \
  "���.�����.�.��.�",   \
  " ���.���.��.�. ",   \
  " ���.��.�.���� ",   \
  " ���.���.��.�. ",   \
  "���.�����.��.�.",   \
  " ���.�.�.������",   \
  " ������ ����   ",   \
  " ���.���.������",   \
  "������� �������.",   \
  " ��������� ���. ",   \
  " ³��.����������",   \
  " ���.������.RTC ",   \
  " �� ���.���� RTC",   \
  " ���� VREF ���  ",   \
  "���� VREF ��� ��",   \
  " ���.SPI ���    ",   \
  "�����.���.�.���.",   \
  " ���.���.����?.?",   \
  " ���.���.����?.?",   \
  " ���.���.����?.?",   \
  " ���.���.����?.?",   \
  " ���.���.����?.?",   \
  " ���.���.����?.?",   \
  " ���.���.����?.?",   \
  " ���.���.����?.?",   \
  " ���.���.����?.?",   \
  " ���.���.����?.?",   \
  " ���.���.����?.?",   \
  " ���.���.����?.?",   \
  " ���.���.����?.?",   \
  " ���.���.����?.?",   \
  " ���.���.����?.?",   \
  " ���.���.����?.?",   \
  " ���.���.��     ",   \
  "��.�.����.������",   \
  " �����.���.a�.�.",   \
  " �.a�.���.���.  ",   \
  "������.���.��.�.",   \
  "�.�.����.������.",   \
  " ������.���.�.�.",   \
  " ������ �.�.�.  ",   \
  "�����.���.�.��.�",   \
  " ������ �.�.��.�",   \
  " ����� ������.  ",   \
  " ������� ������.",   \
  " ��.������� ��. ",   \
  " ���.������.    ",   \
  " ������.��������",   \
  " ³����� �ʲ    ",   \
  " ���.SPI_EDF    ",   \
  " ���.����.SRAM  ",   \
  " ���.�����.FLASH",   \
  " ���.���.��.���.",   \
  " ���.�.����㳿  ",   \
  " ���� ���1      ",   \
  " ���� ���2      ",   \
  " ���� ���3      ",   \
  " ��1 ��.       ",   \
  " ��1 �.         ",   \
  " ����5_1 ��.   ",   \
  " ����5_1 �.     ",   \
  " ����5_2 ��.   ",   \
  " ����5_2 �.     ",   \
  " ���-�� ��.    ",   \
  " ���-�� �.      ",   \
  " ��� ��.       ",   \
  " ��� �.         ",   \
  " ���.�.�.       ",   \
  "����� ���������."   

# define NAME_DIAGN_EN  \
  " I2C Er         ",   \
  " Settings Er    ",   \
  " No settings    ",   \
  " Sett W Er      ",   \
  " Sett Ctl Er    ",   \
  " Sett Type Er   ",   \
  " Adjust Er      ",   \
  " No adjust      ",   \
  " Adjust W Er    ",   \
  "Adjust Ctl Er   ",   \
  " Adjust-Set Er  ",   \
  "Tr LED Rest Er  ",   \
  "Sign BO Rest Er ",   \
  " No BO/LED Inf  ",   \
  " BO/LED W Er    ",   \
  " Nvol LS Inf Er ",   \
  " No Nvol LS Inf ",   \
  "Nvol LS Inf W Er",   \
  "Nvol LS Inf C Er",   \
  " Dst Rec Er     ",   \
  " Dst Rec No info",   \
  " Dst Rec W Er   ",   \
  " Dst Rec Ctr Er ",   \
  " Bin Rec Er     ",   \
  " Bin Rec No info",   \
  " Bin Rec W Er   ",   \
  " Bin Rec Ctr Er ",   \
  " Diag Rec Er    ",   \
  "Diag Rec No info",   \
  " Diag Rec W Er  ",   \
  "Diag Rec Ctr Er ",   \
  " CB Res Coun Er ",   \
  "CB Res Ctr No In",   \
  " CB Res Ctr W Er",   \
  " CB R Cnt Ctr Er",   \
  " Energy calc Er ",   \
  " Energy calc Abs",   \
  "Energy calc W Er",   \
  " RTC:Battery low",   \
  " RTC:Osc stop   ",   \
  " RTC:Osc fail   ",   \
  " RTC:Halt update",   \
  "RTC:No def sett ",   \
  " ADC:VREF fail  ",   \
  " ADC:VREF Test R",   \
  " ADC SPI Er     ",   \
  "UnAp D Buf Ovrfl",   \
  " BO?.? Ctl Er   ",   \
  " BO?.? Ctl Er   ",   \
  " BO?.? Ctl Er   ",   \
  " BO?.? Ctl Er   ",   \
  " BO?.? Ctl Er   ",   \
  " BO?.? Ctl Er   ",   \
  " BO?.? Ctl Er   ",   \
  " BO?.? Ctl Er   ",   \
  " BO?.? Ctl Er   ",   \
  " BO?.? Ctl Er   ",   \
  " BO?.? Ctl Er   ",   \
  " BO?.? Ctl Er   ",   \
  " BO?.? Ctl Er   ",   \
  " BO?.? Ctl Er   ",   \
  " BO?.? Ctl Er   ",   \
  " BO?.? Ctl Er   ",   \
  " DSh outp. err. ",   \
  " Dst Rec Busy   ",   \
  " Dst Rec Buf Ovf",   \
  "Dst Rec Mem Full",   \
  "UnDef Dst Rec Er",   \
  " Bin Rec busy   ",   \
  "UnDef Bin Rec Er",   \
  "Bin Rec Dat Lost",   \
  "OVF of PER buff ",   \
  " PER Dat lost   ",   \
  " Device Start   ",   \
  " Device Restart ",   \
  " Device SFTRST  ",   \
  " Device Stop    ",   \
  " Power Outage   ",   \
  " LCD Fail       ",   \
  " EDF SPI Er     ",   \
  " Ext SRAM Er    ",   \
  " Flash Mem Er   ",   \
  " SP Gr Sel Er   ",   \
  " En Ctr Dat Lost",   \
  " Sensor1 Test   ",   \
  " Sensor2 Test   ",   \
  " Sensor3 Test   ",   \
  " AIU01 abs      ",   \
  " AIU01 ver      ",   \
  " BIOU05_X abs   ",   \
  " BIOU05_X ver   ",   \
  " BIOU05_Y abs   ",   \
  " BIOU05_Y ver   ",   \
  " BIASU01 abs    ",   \
  " BIASU01 ver    ",   \
  " ASU abs        ",   \
  " ASU ver        ",   \
  " Error of FS    ",   \
  " Reprogram Mode "   

# define NAME_DIAGN_KZ  \
  " ��.I2C         ",   \
  " ��.��������    ",   \
  " �������� ���   ",   \
  " ��.���.�����.  ",   \
  " ��.�����.�����.",   \
  " ��.���� �����. ",   \
  " ��.����������� ",   \
  " ����������� ���",   \
  " ��.���.�����.  ",   \
  " ��.�����.�����.",   \
  " ��.�����.������",   \
  " ��.��c��.��.�� ",   \
  " ��.��c��.�.��� ",   \
  "���.���./��.��� ",   \
  " ��.���.���./��.",   \
  "  ��.��.������� ",   \
  " ��.������� ��� ",   \
  " ��.�.��.�������",   \
  " ��.�.��.�������",   \
  " ��.���.��.���. ",   \
  " ���.��.���.��� ",   \
  "��.���.�.��.���.",   \
  "��.�����.��.���.",   \
  " ��.���.�.���.  ",   \
  " ���.�.���.���  ",   \
  " ��.���.�.�.���.",   \
  " ��.�����.�.���.",   \
  "��.���.���.��.�.",   \
  "���.���.��.�.���",   \
  "��.���.�.�.��.�.",   \
  "��.�����.�.��.�.",   \
  " ��.���.��.���. ",   \
  " ���.��.���.��� ",   \
  " ��.���.��.���. ",   \
  "��.�����.��.���.",   \
  " ��.�.�.������� ",   \
  " ������� ���    ",   \
  " ��.���.������� ",   \
  " ������� ������.",   \
  "��������� �����.",   \
  "����� ����������",   \
  " ���.������.RTC ",   \
  " �� ���.���� RTC",   \
  " ���� VREF ���  ",   \
  "���� VREF ��� ��",   \
  " ��.SPI ���     ",   \
  "�����.���.�.���.",   \
  " ��.���.���� ?.?",   \
  " ��.���.���� ?.?",   \
  " ��.���.���� ?.?",   \
  " ��.���.���� ?.?",   \
  " ��.���.���� ?.?",   \
  " ��.���.���� ?.?",   \
  " ��.���.���� ?.?",   \
  " ��.���.���� ?.?",   \
  " ��.���.���� ?.?",   \
  " ��.���.���� ?.?",   \
  " ��.���.���� ?.?",   \
  " ��.���.���� ?.?",   \
  " ��.���.���� ?.?",   \
  " ��.���.���� ?.?",   \
  " ��.���.���� ?.?",   \
  " ��.���.���� ?.?",   \
  " ��.���.��      ",   \
  "��.���.��.�����.",   \
  " ���.���.a�.���.",   \
  " �.a�.���.���.  ",   \
  "�����.��.��.���.",   \
  " �.���.��.�����.",   \
  " �����.��.�.���.",   \
  " ������ �.�.���.",   \
  "�����.���.��.��.",   \
  " ������ �.��.��.",   \
  " ����� ����.    ",   \
  " ������� ����.  ",   \
  "��.������� ����.",   \
  " �������.����.  ",   \
  " ������.������� ",   \
  " ����� ���      ",   \
  " ��.SPI_EDF     ",   \
  " ��.������� SRAM",   \
  " ��.�����.FLASH ",   \
  " ��.���.��.���. ",   \
  " ���.�.�������  ",   \
  " ���� ���1      ",   \
  " ���� ���2      ",   \
  " ���� ���3      ",   \
  " ��1 ��.        ",   \
  " ��1 �.         ",   \
  " ����5_1 ��.    ",   \
  " ����5_1 �.     ",   \
  " ����5_2 ��.    ",   \
  " ����5_2 �.     ",   \
  " ���-�� ��.     ",   \
  " ���-�� �.      ",   \
  " ��� ��.        ",   \
  " ��� �.         ",   \
  " ��.�.�.        ",   \
  "����� ���������."
    
#endif
