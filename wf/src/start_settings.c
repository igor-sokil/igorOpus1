#include "header.h"


/**************************************/
//���������� �������� SRAM
/**************************************/
inline void test_external_SRAM(void)
{
  //���������� ������� ���������� ���
  unsigned int size_SRAM_word = (((unsigned int)__section_size("variables_RAM1")/*&__ICFEDIT_region_RAM1_size__*/) + 1) >> 1;
  
  //��������� �������� �� ������� �������� ���������� ���'��
   unsigned short int *point = ((unsigned short int *)__section_begin("variables_RAM1")/*&__ICFEDIT_region_RAM1_start__*/);
  
  //���������� ����� ������ ������� ���������� ���'�� �� �������
  for (unsigned int i = 0; i < size_SRAM_word; i++) *point++ = (unsigned short int)(i & 0xffff);
  
  //���������� �����������, �� � ��� ������� �������� � �����, �� �� ���������� ��������
  unsigned int error = 0, i = 0;
  point = ((unsigned short int *)__section_begin("variables_RAM1")/*&__ICFEDIT_region_RAM1_start__*/);
  while((i < size_SRAM_word) && (error == 0))
  {
    if ((*point) == ((unsigned short int)(i & 0xffff)))
    {
      //���� ���� ������ ������� �����
      i++;
      *point++ = 0;
    }
    else
    {
      //���� ���� ������ �� ������� �����
      
      error = 0xff;
      //����������� ����������� ��� ������� ����� ������� ���������� ���'��
      _SET_BIT(set_diagnostyka, ERROR_EXTERNAL_SRAM_BIT);
    }
  }
	
#ifdef EXT_SRAM_512  
  if (error == 0)
  {
    point = (unsigned short int *)(&__ICFEDIT_region_RAM1_start__);
    size_t size = (size_t)(&__ICFEDIT_region_RAM1_size__) + 1;
    uint16_t *pointTmp = point + (size >> 2); /*��� �����, ��� �������� �������� ���'��, � ������ ��� ���, ��  �������� ����� �� ��������� �����*/
    *point = 0x0;
    *pointTmp = 0xaa55;
    if (*point != 0x0) 
    {
      error = 0xff;
      //����������� ����������� ��� ������� ����� ������� ���������� ���'��
      _SET_BIT(set_diagnostyka, ERROR_EXTERNAL_SRAM_BIT);
    }
    else *pointTmp = 0;
  }
#endif
}
/**************************************/

/**************************************/
//�������� ����������� ������
/**************************************/
void global_vareiables_installation(void)
{
  /**************************/
  //����������� �������
  /**************************/
  
  for (unsigned int i = 0; i < NUMBER_VREF_ADC; i++)
  {
    for(unsigned int j = 0; j < NUMBER_POINT; j++)
    {
      vref_adc_moment_value[i][j] = VREF_NORMAL_VALUE;
    }
    vref_adc_averange_sum[i] = VREF_NORMAL_VALUE*NUMBER_POINT;
    vref_adc_averange[i] = VREF_NORMAL_VALUE;
  }
  vref_adc = VREF_NORMAL_VALUE;

  for (unsigned int i = 0; i < MAX_INDEX_DATA_FOR_OSCYLOGRAPH; i++)
  {
    data_for_oscylograph[i].state_ar_record = STATE_AR_NONE_M;
  }
  
  sector_1_mtz_tznp[0] = (int) (AMPLITUDA_SECTOR*/*cos*/arm_cos_f32(/*(double)*/(PI*((float)( 90 - SECTOR1_MTZ_TZNP - POPRAVKA_MTZ_TZNP))/180.0f)));
  sector_1_mtz_tznp[1] = (int) (AMPLITUDA_SECTOR*/*sin*/arm_sin_f32(/*(double)*/(PI*((float)( 90 - SECTOR1_MTZ_TZNP - POPRAVKA_MTZ_TZNP))/180.0f)));
  sector_1_mtz_tznp[2] = (int) (AMPLITUDA_SECTOR*/*cos*/arm_cos_f32(/*(double)*/(PI*((float)( 90 + SECTOR1_MTZ_TZNP - POPRAVKA_MTZ_TZNP))/180.0f)));
  sector_1_mtz_tznp[3] = (int) (AMPLITUDA_SECTOR*/*sin*/arm_sin_f32(/*(double)*/(PI*((float)( 90 + SECTOR1_MTZ_TZNP - POPRAVKA_MTZ_TZNP))/180.0f)));
  sector_1_mtz_tznp[4] = (int) (AMPLITUDA_SECTOR*/*cos*/arm_cos_f32(/*(double)*/(PI*((float)(-90 - SECTOR1_MTZ_TZNP - POPRAVKA_MTZ_TZNP))/180.0f)));
  sector_1_mtz_tznp[5] = (int) (AMPLITUDA_SECTOR*/*sin*/arm_sin_f32(/*(double)*/(PI*((float)(-90 - SECTOR1_MTZ_TZNP - POPRAVKA_MTZ_TZNP))/180.0f)));
  sector_1_mtz_tznp[6] = (int) (AMPLITUDA_SECTOR*/*cos*/arm_cos_f32(/*(double)*/(PI*((float)(-90 + SECTOR1_MTZ_TZNP - POPRAVKA_MTZ_TZNP))/180.0f)));
  sector_1_mtz_tznp[7] = (int) (AMPLITUDA_SECTOR*/*sin*/arm_sin_f32(/*(double)*/(PI*((float)(-90 + SECTOR1_MTZ_TZNP - POPRAVKA_MTZ_TZNP))/180.0f)));

  sector_2_mtz_tznp[0] = (int) (AMPLITUDA_SECTOR*/*cos*/arm_cos_f32(/*(double)*/(PI*((float)( 90 - SECTOR2_MTZ_TZNP - POPRAVKA_MTZ_TZNP))/180.0f)));
  sector_2_mtz_tznp[1] = (int) (AMPLITUDA_SECTOR*/*sin*/arm_sin_f32(/*(double)*/(PI*((float)( 90 - SECTOR2_MTZ_TZNP - POPRAVKA_MTZ_TZNP))/180.0f)));
  sector_2_mtz_tznp[2] = (int) (AMPLITUDA_SECTOR*/*cos*/arm_cos_f32(/*(double)*/(PI*((float)( 90 + SECTOR2_MTZ_TZNP - POPRAVKA_MTZ_TZNP))/180.0f)));
  sector_2_mtz_tznp[3] = (int) (AMPLITUDA_SECTOR*/*sin*/arm_sin_f32(/*(double)*/(PI*((float)( 90 + SECTOR2_MTZ_TZNP - POPRAVKA_MTZ_TZNP))/180.0f)));
  sector_2_mtz_tznp[4] = (int) (AMPLITUDA_SECTOR*/*cos*/arm_cos_f32(/*(double)*/(PI*((float)(-90 - SECTOR2_MTZ_TZNP - POPRAVKA_MTZ_TZNP))/180.0f)));
  sector_2_mtz_tznp[5] = (int) (AMPLITUDA_SECTOR*/*sin*/arm_sin_f32(/*(double)*/(PI*((float)(-90 - SECTOR2_MTZ_TZNP - POPRAVKA_MTZ_TZNP))/180.0f)));
  sector_2_mtz_tznp[6] = (int) (AMPLITUDA_SECTOR*/*cos*/arm_cos_f32(/*(double)*/(PI*((float)(-90 + SECTOR2_MTZ_TZNP - POPRAVKA_MTZ_TZNP))/180.0f)));
  sector_2_mtz_tznp[7] = (int) (AMPLITUDA_SECTOR*/*sin*/arm_sin_f32(/*(double)*/(PI*((float)(-90 + SECTOR2_MTZ_TZNP - POPRAVKA_MTZ_TZNP))/180.0f)));
  /**************************/

  /**************************/
  //����������� ���������� �������
  /**************************/
  for(int *p = global_timers; p != (global_timers + NEXT_TIMER); ++p) *p = -1;
  /**************************/

  /**************************/
  //����, �� ������ ��� ����������� ����������
  /**************************/
  for(unsigned int i = 0; i < SIZE_BUFFER_FOR_DR_RECORD; i++)
  {
    buffer_for_save_dr_record[i] = 0xff;
  }
  /**************************/
  
  for(unsigned int i = 0; i < MAX_ROW_LCD; i++)
  {
    for (unsigned int j = 0; j < MAX_COL_LCD; j++) working_ekran[i][j] = ' ';
  }
 
  for(unsigned int i=0; i<MAX_LEVEL_MENU; i++)
  {
    if ((i == EKRAN_LEVEL_PASSWORD) || 
        (i == EKRAN_LEVEL_SET_NEW_PASSWORD1) || 
        (i == EKRAN_LEVEL_SET_NEW_PASSWORD2) ||
        (i == EKRAN_LEVEL_SET_NEW_PASSWORD3) 
        ) position_in_current_level_menu[i] = INDEX_LINE_NUMBER_1_FOR_LEVEL_PASSWORD;
    else  position_in_current_level_menu[i] = 0;
    previous_level_in_current_level_menu[i] = -1;
  }
  
  //���������� ����������� ����� ������
  current_ekran.current_level = EKRAN_MAIN;
  current_ekran.index_position = position_in_current_level_menu[current_ekran.current_level];
  current_ekran.position_cursor_y = current_ekran.index_position;
  
  /**************************/
  //����������� ��������� ���������� ��������� I2C
  /**************************/
  //���� �����
  driver_i2c.state_execution = -1;
  //������������� ��������, � ���� ������������
  driver_i2c.device_id = -1;
  //��� ��������
  driver_i2c.action = -1;
  //�������� ����� ���� ���� �� ��� ��� 
  /**************************/
  
//  time_delta_watchdog_input_min = 0xffff*10;
//  time_delta_watchdog_output_min = 0xffff*10;
  
  number_record_of_ar_for_menu = -1;  
  number_record_of_ar_for_USB = -1;
  number_record_of_ar_for_RS485 = -1;
  
  current_language = LANGUAGE_ABSENT;
  
  //Modbus-RTU
  type_of_settings_changed = 0;
  
  //����������� �������� ���������� ������
  pointInterface = 0;
  
  extern int sizeOutputPacket;
  extern  unsigned char *inputPacket;
  extern  int *received_count;
  extern  int globalcntBit;//�-�� ���
  extern  int globalcntReg;//�-�� ���������
  extern  int globalbeginAdrReg;//����� ��� ��������
  extern  int globalbeginAdrBit;//����� ��� ���
  extern  int upravlSetting;//���� Setting
  extern  int upravlSchematic;//���� Shematic
  
  sizeOutputPacket = 0;
  globalcntBit  = 0;//�-�� ���
  globalcntReg  = 0;//�-�� ���������
  globalbeginAdrReg  = 0;//����� ��� ��������
  globalbeginAdrBit  = 0;//����� ��� ���
  upravlSetting=0;//���� Setting
  upravlSchematic=0;//���� Shematic
}
/**************************************/

/**************************************/
//�������� ����������� ������� ���������
/**************************************/
void start_settings_peripherals(void)
{
  /**********************/
  //������������ ��������������: ���� + �������
  /**********************/
  Set_System();
  /**********************/

  /**********************/
  //���������� DBG ������
  /**********************/
  DBGMCU_APB1PeriphConfig(DBGMCU_TIM2_STOP | DBGMCU_TIM5_STOP | DBGMCU_TIM4_STOP | DBGMCU_I2C1_SMBUS_TIMEOUT, ENABLE);
  /**********************/

  /**********************/
  //������������ ����������
  /**********************/
  Interrupts_Config();
  /**********************/

  /**********************/
  //������������ ������� ����
  /**********************/
  FSMC_SRAM_Init();
  _DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD31_DD34_DD35_DD37) = 0;
#if (                                   \
       (MODYFIKACIA_VERSII_PZ == 0) ||  \
       (MODYFIKACIA_VERSII_PZ == 3) ||  \
       (MODYFIKACIA_VERSII_PZ == 4) ||  \
       (MODYFIKACIA_VERSII_PZ == 5) ||  \
       (MODYFIKACIA_VERSII_PZ == 6) ||  \
       (MODYFIKACIA_VERSII_PZ == 10)||  \
       (MODYFIKACIA_VERSII_PZ == 13)||  \
       (MODYFIKACIA_VERSII_PZ == 14)||  \
       (MODYFIKACIA_VERSII_PZ == 15)||  \
       (MODYFIKACIA_VERSII_PZ == 23)||  \
       (MODYFIKACIA_VERSII_PZ == 24)||  \
       (MODYFIKACIA_VERSII_PZ == 26)||  \
       (MODYFIKACIA_VERSII_PZ == 33)||  \
       (MODYFIKACIA_VERSII_PZ == 34)    \
      )   
  _DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD28_DD30) = 0;
#endif
  /**********************/

  /**********************/
  //������������ ��� ���������
  /**********************/
  GPIO_InitTypeDef GPIO_InitStructure;

  /**************/
  //ϳ�� �� ����
  /**************/
  /* ϳ� ���������� Watchdog, �� Output push-pull */
  GPIO_InitStructure.GPIO_Pin = GPIO_PIN_EXTERNAL_WATCHDOG;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIO_EXTERNAL_WATCHDOG, &GPIO_InitStructure);
  /* ������ �� ���������� Watchdog */
  GPIO_SetBits(GPIO_EXTERNAL_WATCHDOG, GPIO_PIN_EXTERNAL_WATCHDOG);
  
  /*
  �������� �������� ����������� ������? � ���� ������� Watchdog
  ϳ��� ����� ���������� ��������� �������
  
  �� �������, ��� �������� ����������� �������
  */
  /**********************/
  //������� ������� SRAM
  /**********************/
  test_external_SRAM();
  /**********************/
  
  //������� ���� ��� ���������� Watchdog �� �����������
  GPIO_WriteBit(
                GPIO_EXTERNAL_WATCHDOG,
                GPIO_PIN_EXTERNAL_WATCHDOG,
                (BitAction)(1 - GPIO_ReadOutputDataBit(GPIO_EXTERNAL_WATCHDOG, GPIO_PIN_EXTERNAL_WATCHDOG))
               );
    
  /**********************/
  //�������� ����������� ������ � �������� � � ������� SRAM
  /**********************/
  global_vareiables_installation();
  /**********************/
    
  //������� ���� ��� ���������� Watchdog �� �����������
  GPIO_WriteBit(
                GPIO_EXTERNAL_WATCHDOG,
                GPIO_PIN_EXTERNAL_WATCHDOG,
                (BitAction)(1 - GPIO_ReadOutputDataBit(GPIO_EXTERNAL_WATCHDOG, GPIO_PIN_EXTERNAL_WATCHDOG))
               );
  /*****/ 

  /*
  ���������� ���������� ����������� �������  
  */
    
  /* ������������ ��� CON-L, �� Output push-pull */
  GPIO_InitStructure.GPIO_Pin = CON_L_PIN;
  GPIO_Init(CON_L, &GPIO_InitStructure);
  /* ������� �� CON-L, ��� ������ ��������� ��������������� �� ����� ����*/
  GPIO_ResetBits(CON_L, CON_L_PIN);

  /* ������������ ��� CON-OUTPUTS, �� Output push-pull */
  GPIO_InitStructure.GPIO_Pin = CON_1_OUTPUTS_PIN;
  GPIO_Init(CON_OUTPUTS, &GPIO_InitStructure);
  /* ����������� �� CON-OUTPUTS-1*/
  GPIO_SetBits(CON_OUTPUTS, CON_1_OUTPUTS_PIN);

  GPIO_InitStructure.GPIO_Pin = CON_2_OUTPUTS_PIN;
  GPIO_Init(CON_OUTPUTS, &GPIO_InitStructure);
  /* ������ �� CON-OUTPUTS-2*/
  GPIO_ResetBits(CON_OUTPUTS, CON_2_OUTPUTS_PIN);

  GPIO_InitStructure.GPIO_Pin = CON_3_OUTPUTS_PIN;
  GPIO_Init(CON_OUTPUTS, &GPIO_InitStructure);
  /* ����������� �� CON-OUTPUTS-3*/
  GPIO_SetBits(CON_OUTPUTS, CON_3_OUTPUTS_PIN);
  
  /***
  �������� �������� ��������� ���� (CON ��� ��� ������������)
  ***/
  _DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD39_DD40_DD47) = 0;
  uint32_t board_register_tmp = board_register = _DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD39_DD40_DD47);
#if   (                                 \
       (MODYFIKACIA_VERSII_PZ ==  0) || \
       (MODYFIKACIA_VERSII_PZ ==  3) || \
       (MODYFIKACIA_VERSII_PZ ==  5) || \
       (MODYFIKACIA_VERSII_PZ ==  6) || \
       (MODYFIKACIA_VERSII_PZ == 23) || \
       (MODYFIKACIA_VERSII_PZ == 26)    \
      )   
  if ((board_register_tmp & 0x17) != 0x17)
#elif (                                 \
       (MODYFIKACIA_VERSII_PZ == 1)     \
      )   
  if ((board_register_tmp & 0x07) != 0x07)
#elif (                                 \
       (MODYFIKACIA_VERSII_PZ == 2)     \
      )   
  if ((board_register_tmp & 0x03) != 0x03)
#elif (                                 \
       (MODYFIKACIA_VERSII_PZ ==  4) || \
       (MODYFIKACIA_VERSII_PZ == 24)    \
      )   
  if ((board_register_tmp & 0x13) != 0x13)
#elif (                                 \
       (MODYFIKACIA_VERSII_PZ == 10) || \
       (MODYFIKACIA_VERSII_PZ == 13) || \
       (MODYFIKACIA_VERSII_PZ == 15) || \
       (MODYFIKACIA_VERSII_PZ == 33)    \
      )   
  if ((board_register_tmp & 0x1F) != 0x1F)
#elif (                                 \
       (MODYFIKACIA_VERSII_PZ == 11)    \
      )   
  if ((board_register_tmp & 0x0F) != 0x0F)
#elif (                                 \
       (MODYFIKACIA_VERSII_PZ == 12)    \
      )   
  if ((board_register_tmp & 0x0B) != 0x0B)
#elif (                                 \
       (MODYFIKACIA_VERSII_PZ == 14) || \
       (MODYFIKACIA_VERSII_PZ == 34)    \
      )   
  if ((board_register_tmp & 0x1B) != 0x1B)
#else
 #error  "UDEFINED MODIFIKACIA"
#endif
  {
    if ((board_register_tmp &  0x01) !=  0x1) _SET_BIT(set_diagnostyka, ERROR_BA_1_FIX);
    if ((board_register_tmp &  0x02) !=  0x2) _SET_BIT(set_diagnostyka, ERROR_BDVV5_1_FIX);
    
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)   
    if ((board_register_tmp &  0x08) !=  0x8) _SET_BIT(set_diagnostyka, ERROR_CB_FIX);
#endif
    
#if (                                \
     (MODYFIKACIA_VERSII_PZ == 0) || \
     (MODYFIKACIA_VERSII_PZ == 1) || \
     (MODYFIKACIA_VERSII_PZ == 3) || \
     (MODYFIKACIA_VERSII_PZ == 5) || \
     (MODYFIKACIA_VERSII_PZ == 10)|| \
     (MODYFIKACIA_VERSII_PZ == 11)|| \
     (MODYFIKACIA_VERSII_PZ == 13)|| \
     (MODYFIKACIA_VERSII_PZ == 15)|| \
     (MODYFIKACIA_VERSII_PZ == 23)|| \
     (MODYFIKACIA_VERSII_PZ == 33)   \
    )
    if ((board_register_tmp &  0x04) !=  0x4) _SET_BIT(set_diagnostyka, ERROR_BDVV5_2_FIX);
#elif (                                \
     (MODYFIKACIA_VERSII_PZ == 6) || \
     (MODYFIKACIA_VERSII_PZ == 26)   \
    )
    if ((board_register_tmp &  0x04) !=  0x4) _SET_BIT(set_diagnostyka, ERROR_BDVV9_FIX);
#endif

#if (                                   \
     (MODYFIKACIA_VERSII_PZ == 0) ||    \
     (MODYFIKACIA_VERSII_PZ == 3) ||    \
     (MODYFIKACIA_VERSII_PZ == 4) ||    \
     (MODYFIKACIA_VERSII_PZ == 5) ||    \
     (MODYFIKACIA_VERSII_PZ == 6) ||    \
     (MODYFIKACIA_VERSII_PZ == 10)||    \
     (MODYFIKACIA_VERSII_PZ == 13)||    \
     (MODYFIKACIA_VERSII_PZ == 14)||    \
     (MODYFIKACIA_VERSII_PZ == 15)||    \
     (MODYFIKACIA_VERSII_PZ == 23)||    \
     (MODYFIKACIA_VERSII_PZ == 24)||    \
     (MODYFIKACIA_VERSII_PZ == 26)||    \
     (MODYFIKACIA_VERSII_PZ == 33)||    \
     (MODYFIKACIA_VERSII_PZ == 34)      \
    )   
    if ((board_register_tmp & 0x010) != 0x10) 
      
#if (                                   \
     (MODYFIKACIA_VERSII_PZ == 0) ||    \
     (MODYFIKACIA_VERSII_PZ == 10)      \
    )                                   
      _SET_BIT(set_diagnostyka, ERROR_BDV_DZ_FIX);
#elif (                                 \
       (MODYFIKACIA_VERSII_PZ == 5) ||  \
       (MODYFIKACIA_VERSII_PZ == 15)    \
      )   
      _SET_BIT(set_diagnostyka, ERROR_BDVV6_FIX);
#elif (                                 \
       (MODYFIKACIA_VERSII_PZ == 3) ||  \
       (MODYFIKACIA_VERSII_PZ == 4) ||  \
       (MODYFIKACIA_VERSII_PZ == 6) ||  \
       (MODYFIKACIA_VERSII_PZ == 13)||  \
       (MODYFIKACIA_VERSII_PZ == 14)    \
      )
      _SET_BIT(set_diagnostyka, ERROR_BDZ_FIX);
#elif (                                 \
       (MODYFIKACIA_VERSII_PZ == 23) || \
       (MODYFIKACIA_VERSII_PZ == 24) || \
       (MODYFIKACIA_VERSII_PZ == 26) || \
       (MODYFIKACIA_VERSII_PZ == 33) || \
       (MODYFIKACIA_VERSII_PZ == 34)    \
      )
      _SET_BIT(set_diagnostyka, ERROR_BDSH_FIX);
#else
 #error  "UDEFINED MODIFIKACIA"
#endif
      
#endif
    
    
  }
  
  if ((board_register_tmp & 0x01) == 0x01)
  {
    _DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD39_DD40_DD47) = 0x1;
    if ((_DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD39_DD40_DD47) >> 8) != 0x11)  _SET_BIT(set_diagnostyka, ERROR_BA_1_CTLR);
  }
  if ((board_register_tmp & 0x02) == 0x02)
  {
    _DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD39_DD40_DD47) = 0x2;
    if ((_DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD33_DD36) & 0xff) != 0x25)  _SET_BIT(set_diagnostyka, ERROR_BDVV5_1_CTLR);
  }

#if (                                \
     (MODYFIKACIA_VERSII_PZ == 0) || \
     (MODYFIKACIA_VERSII_PZ == 1) || \
     (MODYFIKACIA_VERSII_PZ == 3) || \
     (MODYFIKACIA_VERSII_PZ == 10)|| \
     (MODYFIKACIA_VERSII_PZ == 11)|| \
     (MODYFIKACIA_VERSII_PZ == 13)|| \
     (MODYFIKACIA_VERSII_PZ == 23)|| \
     (MODYFIKACIA_VERSII_PZ == 33)   \
    )
  if ((board_register_tmp & 0x04) == 0x04)
  {
    _DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD39_DD40_DD47) = 0x4;
    if ((_DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD33_DD36) >> 8) != 0x37)  _SET_BIT(set_diagnostyka, ERROR_BDVV5_2_CTLR);
  }
#elif (                                \
       (MODYFIKACIA_VERSII_PZ == 6) || \
       (MODYFIKACIA_VERSII_PZ == 26)   \
      )
  if ((board_register_tmp & 0x04) == 0x04)
  {
    _DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD39_DD40_DD47) = 0x4;
    if ((_DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD33_DD36) >> 8) != 0x29)  _SET_BIT(set_diagnostyka, ERROR_BDVV9_CTLR);
  }
#endif
  
#if (                                   \
       (MODYFIKACIA_VERSII_PZ == 0) ||  \
       (MODYFIKACIA_VERSII_PZ == 3) ||  \
       (MODYFIKACIA_VERSII_PZ == 4) ||  \
       (MODYFIKACIA_VERSII_PZ == 5) ||  \
       (MODYFIKACIA_VERSII_PZ == 6) ||  \
       (MODYFIKACIA_VERSII_PZ == 10)||  \
       (MODYFIKACIA_VERSII_PZ == 13)||  \
       (MODYFIKACIA_VERSII_PZ == 14)||  \
       (MODYFIKACIA_VERSII_PZ == 15)||  \
       (MODYFIKACIA_VERSII_PZ == 23)||  \
       (MODYFIKACIA_VERSII_PZ == 24)||  \
       (MODYFIKACIA_VERSII_PZ == 26)||  \
       (MODYFIKACIA_VERSII_PZ == 33)||  \
       (MODYFIKACIA_VERSII_PZ == 34)    \
      )   
  if ((board_register_tmp & 0x10) == 0x10)
  {
    _DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD39_DD40_DD47) = 0x10;
#if (                                   \
     (MODYFIKACIA_VERSII_PZ == 0) ||    \
     (MODYFIKACIA_VERSII_PZ == 10)      \
    )                                   
    if ((_DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD26_DD29) >> 8) != 0x14)  _SET_BIT(set_diagnostyka, ERROR_BDV_DZ_CTLR);
#elif (                                 \
       (MODYFIKACIA_VERSII_PZ == 5) ||  \
       (MODYFIKACIA_VERSII_PZ == 15)    \
      )   
    if ((_DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD26_DD29) >> 8) != 0x12)  _SET_BIT(set_diagnostyka, ERROR_BDVV6_CTLR);
#elif (                                 \
       (MODYFIKACIA_VERSII_PZ == 3) ||  \
       (MODYFIKACIA_VERSII_PZ == 4) ||  \
       (MODYFIKACIA_VERSII_PZ == 6) ||  \
       (MODYFIKACIA_VERSII_PZ == 13)||  \
       (MODYFIKACIA_VERSII_PZ == 14)    \
      )
    if ((_DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD26_DD29) >> 8) != 0x18)  _SET_BIT(set_diagnostyka, ERROR_BDZ_CTLR);
#elif (                                 \
       (MODYFIKACIA_VERSII_PZ == 23)||  \
       (MODYFIKACIA_VERSII_PZ == 24)||  \
       (MODYFIKACIA_VERSII_PZ == 26)||  \
       (MODYFIKACIA_VERSII_PZ == 33)||  \
       (MODYFIKACIA_VERSII_PZ == 34)    \
      )
    if ((_DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD26_DD29) >> 8) != 0x13)  _SET_BIT(set_diagnostyka, ERROR_BDSH_CTLR);
#else
 #error  "UDEFINED MODIFIKACIA"
#endif
  }
#endif
  
  //�������� ���� ��� ���� ��� ���������� ��������
  _DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD39_DD40_DD47) = 0x0;
  /***/
  
  /* ������������ ��� LCD-BL, �� Output push-pull */
  GPIO_InitStructure.GPIO_Pin = LCD_BL_PIN;
  GPIO_Init(LCD_BL, &GPIO_InitStructure);
  /* ������ �� LCD-BL ��� ����, ��� �������� ������� LCD*/
  GPIO_ResetBits(LCD_BL, LCD_BL_PIN);

  /* ������������ ��� LCD-R/W, �� Output push-pull */
  GPIO_InitStructure.GPIO_Pin = LCD_RW_PIN;
  GPIO_Init(LCD_RW, &GPIO_InitStructure);
  /* ������ �� LCD-R/W*/
  GPIO_ResetBits(LCD_RW, LCD_RW_PIN);

  /* ������������ ��� LCD-RS, �� Output push-pull */
  GPIO_InitStructure.GPIO_Pin = LCD_RS_PIN;
  GPIO_Init(LCD_RS, &GPIO_InitStructure);
  /* ������ �� LCD-RS*/
  GPIO_ResetBits(LCD_RS, LCD_RS_PIN);

  /*SW_1 ��������� */
  GPIO_InitStructure.GPIO_Pin = KEYBOARD_SW_1_PIN;
  GPIO_Init(KEYBOARD, &GPIO_InitStructure);
  /* ����������� �� SW1*/
  GPIO_SetBits(KEYBOARD, KEYBOARD_SW_1_PIN);

  /*SW_2 ��������� */
  GPIO_InitStructure.GPIO_Pin = KEYBOARD_SW_2_PIN;
  GPIO_Init(KEYBOARD, &GPIO_InitStructure);
  /* ����������� �� SW2*/
  GPIO_SetBits(KEYBOARD, KEYBOARD_SW_2_PIN);

  /*SW_3 ��������� */
  GPIO_InitStructure.GPIO_Pin = KEYBOARD_SW_3_PIN;
  GPIO_Init(KEYBOARD, &GPIO_InitStructure);
  /*����������� �� SW3*/
  GPIO_SetBits(KEYBOARD, KEYBOARD_SW_3_PIN);

  /*SW_4 ��������� */
  GPIO_InitStructure.GPIO_Pin = KEYBOARD_SW_4_PIN;
  GPIO_Init(KEYBOARD, &GPIO_InitStructure);
  /*����������� �� SW4*/
  GPIO_SetBits(KEYBOARD, KEYBOARD_SW_4_PIN);

  /*���� ��� */
  GPIO_InitStructure.GPIO_Pin = GPIO_SELECTPin_ADC;
  GPIO_Init(GPIO_SELECT_ADC, &GPIO_InitStructure);
  GPIO_ResetBits(GPIO_SELECT_ADC, GPIO_SELECTPin_ADC);

  /*NSS_ADC ������ SPI_ADC */
  GPIO_InitStructure.GPIO_Pin = GPIO_NSSPin_ADC;
  GPIO_Init(GPIO_SPI_ADC, &GPIO_InitStructure);
  GPIO_SetBits(GPIO_SPI_ADC, GPIO_NSSPin_ADC);

  /*NSS_ADC ������ SPI_EDF */
  GPIO_InitStructure.GPIO_Pin = GPIO_NSSPin_EDF;
  GPIO_Init(GPIO_SPI_EDF, &GPIO_InitStructure);
  GPIO_SetBits(GPIO_SPI_EDF, GPIO_NSSPin_EDF);

  /*GPIO_SPI_EDF_A0 - ���� ��������� DataFlash*/
  GPIO_InitStructure.GPIO_Pin = GPIO_SPI_EDF_A0_Pin;
  GPIO_Init(GPIO_SPI_EDF_A0, &GPIO_InitStructure);
  //�������� EEPROM
  GPIO_SetBits(GPIO_SPI_EDF_A0, GPIO_SPI_EDF_A0_Pin);

  /*GPIO_SPI_EDF_A1 - ���� ��������� DataFlash*/
  GPIO_InitStructure.GPIO_Pin = GPIO_SPI_EDF_A1_Pin;
  GPIO_Init(GPIO_SPI_EDF_A1, &GPIO_InitStructure);
  //�������� EEPROM
  GPIO_SetBits(GPIO_SPI_EDF_A1, GPIO_SPI_EDF_A1_Pin);

  /* ϳ� 485DE*/
  GPIO_InitStructure.GPIO_Pin = GPIO_PIN_485DE;
  GPIO_Init(GPIO_485DE, &GPIO_InitStructure);
  /* ������ �� 485DE */
  GPIO_ResetBits(GPIO_485DE, GPIO_PIN_485DE);

#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
  /* Canal1_MO_Out1*/
  GPIO_InitStructure.GPIO_Pin = GPIO_PIN_CANAL1_MO_Out1;
  GPIO_Init(GPIO_CANAL1_MO_Out1, &GPIO_InitStructure);
  /* ������ �� Canal1_MO_Out */
  GPIO_ResetBits(GPIO_CANAL1_MO_Out1, GPIO_PIN_CANAL1_MO_Out1);

  /* KP_SOFT_RESET_Out1*/
  GPIO_InitStructure.GPIO_Pin = GPIO_PIN_KP_SOFT_RESET;
  GPIO_Init(GPIO_KP_SOFT_RESET, &GPIO_InitStructure);
  /* ������ �� KP_SOFT_RESET */
  GPIO_ResetBits(GPIO_KP_SOFT_RESET, GPIO_PIN_KP_SOFT_RESET);
#endif
  /**************/

  /* ϳ� �����������������*/
  GPIO_InitStructure.GPIO_Pin = GPIO_PIN_REPROGRAM;
  GPIO_Init(GPIO_REPROGRAM, &GPIO_InitStructure);
  /* ������ �� ����������������� */
  GPIO_ResetBits(GPIO_REPROGRAM, GPIO_PIN_REPROGRAM);

  /* ϳ� "������� �����"*/
  GPIO_InitStructure.GPIO_Pin = GPIO_PIN_STAFF;
  GPIO_Init(GPIO_STAFF, &GPIO_InitStructure);
  /* ������ �� "������� �����" */
  GPIO_ResetBits(GPIO_STAFF, GPIO_PIN_STAFF);

  /**************/
  //ϳ�� �� ���
  /**************/
  /*SW_A ��������� */
  GPIO_InitStructure.GPIO_Pin = KEYBOARD_SW_A_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(KEYBOARD_SW_A, &GPIO_InitStructure);

  /*SW_B ��������� */
  GPIO_InitStructure.GPIO_Pin = KEYBOARD_SW_B_PIN;
  GPIO_Init(KEYBOARD_SW_B, &GPIO_InitStructure);

  /*SW_C ��������� */
  GPIO_InitStructure.GPIO_Pin = KEYBOARD_SW_C_PIN;
  GPIO_Init(KEYBOARD_SW_C, &GPIO_InitStructure);

  /*�������� �������� */
  GPIO_InitStructure.GPIO_Pin = POWER_CTRL_PIN;
  GPIO_Init(POWER_CTRL, &GPIO_InitStructure);

  /*�������� �����������������/������� ����� */
  GPIO_InitStructure.GPIO_Pin = GPIO_PIN_STAFF_REPROGRAM;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
  GPIO_Init(GPIO_STAFF_REPROGRAM, &GPIO_InitStructure);
  /**************/

  /**************/
  //ϳ�� �������������� �������
  /**************/
  //���������� ��� PB13/SPI2_SCK, PB14/SPI2_MISO �  PB15/SPI2_MOSI
  GPIO_PinAFConfig(GPIO_SPI_ADC, GPIO_SCKPin_ADCSource, GPIO_AF_SPI_ADC);
  GPIO_PinAFConfig(GPIO_SPI_ADC, GPIO_MISOPin_ADCSource, GPIO_AF_SPI_ADC);
  GPIO_PinAFConfig(GPIO_SPI_ADC, GPIO_MOSIPin_ADCSource, GPIO_AF_SPI_ADC);

  /* Configure SPI_ADC SCK, MISO � MOSI */
  GPIO_InitStructure.GPIO_Pin = GPIO_SCKPin_ADC | GPIO_MISOPin_ADC | GPIO_MOSIPin_ADC;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIO_SPI_ADC, &GPIO_InitStructure);

  //���������� ��� PA5/SPI1_SCK, PA6/SPI1_MISO �  PA7/SPI1_MOSI
  GPIO_PinAFConfig(GPIO_SPI_EDF, GPIO_SCKPin_EDFSource, GPIO_AF_SPI_EDF);
  GPIO_PinAFConfig(GPIO_SPI_EDF, GPIO_MISOPin_EDFSource, GPIO_AF_SPI_EDF);
  GPIO_PinAFConfig(GPIO_SPI_EDF, GPIO_MOSIPin_EDFSource, GPIO_AF_SPI_EDF);

  /* Configure SPI_EDF SCK, MISO � MOSI */
  GPIO_InitStructure.GPIO_Pin = GPIO_SCKPin_EDF | GPIO_MISOPin_EDF | GPIO_MOSIPin_EDF;
  GPIO_Init(GPIO_SPI_EDF, &GPIO_InitStructure);

  //���������� ��� PA2/Tx_RS-485, PA3/Rx_RS-485
  GPIO_PinAFConfig(GPIO_USART_RS485, GPIO_TxPin_RS485Source, GPIO_AF_USART_RS_485);
  GPIO_PinAFConfig(GPIO_USART_RS485, GPIO_RxPin_RS485Source, GPIO_AF_USART_RS_485);

  /* Configure USART_RS485 Rx/Tx as alternate function push-pull */
  GPIO_InitStructure.GPIO_Pin = GPIO_TxPin_RS485 | GPIO_RxPin_RS485;
  GPIO_Init(GPIO_USART_RS485, &GPIO_InitStructure);

#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
  //���������� ��� PA9/Tx_CANAL1_MO, PA10/Rx_CANAL1_MO
  GPIO_PinAFConfig(GPIO_CANAL1_MO, GPIO_TxPin_CANAL1_MOSource, GPIO_AF_CANAL1_MO);
  GPIO_PinAFConfig(GPIO_CANAL1_MO, GPIO_RxPin_CANAL1_MOSource, GPIO_AF_CANAL1_MO);

  /* Configure CANAL1_MO Rx/Tx as alternate function push-pull */
  GPIO_InitStructure.GPIO_Pin = GPIO_TxPin_CANAL1_MO | GPIO_RxPin_CANAL1_MO;
  GPIO_Init(GPIO_CANAL1_MO, &GPIO_InitStructure);

  //���������� ��� PA9/Tx_CANAL2_MO, PA10/Rx_CANAL2_MO
  GPIO_PinAFConfig(GPIO_CANAL2_MO, GPIO_TxPin_CANAL2_MOSource, GPIO_AF_CANAL2_MO);
  GPIO_PinAFConfig(GPIO_CANAL2_MO, GPIO_RxPin_CANAL2_MOSource, GPIO_AF_CANAL2_MO);

  /* Configure CANAL2_MO Rx/Tx as alternate function push-pull */
  GPIO_InitStructure.GPIO_Pin = GPIO_TxPin_CANAL2_MO | GPIO_RxPin_CANAL2_MO;
  GPIO_Init(GPIO_CANAL2_MO, &GPIO_InitStructure);
#endif
  /**********************/

  /* ϳ�'������� EXTI Line0 to POWER_CTRL_PIN ��� */
  SYSCFG_EXTILineConfig(EXTI_PortSource_POWER, EXTI_PinSource_POWER);  
  /**********************/

   /* �������������� EXTI Line0 */
  EXTI_InitTypeDef   EXTI_InitStructure;

  EXTI_InitStructure.EXTI_Line = EXTI_Line_POWER;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling;  
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);
  /**********************/

  /**********************/
  //������������ DMA ����������
  /**********************/
  DMA_InitTypeDef  DMA_InitStructure;

  /* DMA ���������� ��� ������� ����� �� I2C*/
  DMA_DeInit(DMA_StreamI2C_Rx);
  while (DMA_GetCmdStatus(DMA_StreamI2C_Rx) != DISABLE);
  
  DMA_InitStructure.DMA_Channel = DMA_ChannelI2C_Rx;
  DMA_InitStructure.DMA_PeripheralBaseAddr = I2C_DR_Address;
  DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)Temporaty_I2C_Buffer;
  DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory;
  DMA_InitStructure.DMA_BufferSize = MAX_NUMBER_REGISTERS_RTC + 2;
  DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
  DMA_InitStructure.DMA_PeripheralDataSize = DMA_MemoryDataSize_Byte;
  DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
  DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
  DMA_InitStructure.DMA_Priority = DMA_Priority_High;
  DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable;
  DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_HalfFull;
  DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;
  DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;
  DMA_Init(DMA_StreamI2C_Rx, &DMA_InitStructure);
  DMA_ClearFlag(DMA_StreamI2C_Rx, DMA_FLAG_TCI2C_Rx | DMA_FLAG_HTI2C_Rx | DMA_FLAG_TEII2C_Rx | DMA_FLAG_DMEII2C_Rx | DMA_FLAG_FEII2C_Rx);

  /* DMA ���������� ��� ����������� ����� �� I2C*/
  DMA_DeInit(DMA_StreamI2C_Tx);
  while (DMA_GetCmdStatus(DMA_StreamI2C_Tx) != DISABLE);
  
  DMA_InitStructure.DMA_Channel = DMA_ChannelI2C_Tx;
  DMA_InitStructure.DMA_PeripheralBaseAddr = I2C_DR_Address;
  DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)Temporaty_I2C_Buffer;
  DMA_InitStructure.DMA_DIR = DMA_DIR_MemoryToPeripheral;
  DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;
  DMA_Init(DMA_StreamI2C_Tx, &DMA_InitStructure);
  DMA_ClearFlag(DMA_StreamI2C_Tx, DMA_FLAG_TCI2C_Tx | DMA_FLAG_HTI2C_Tx | DMA_FLAG_TEII2C_Tx | DMA_FLAG_DMEII2C_Tx | DMA_FLAG_FEII2C_Tx);

  /* DMA ���������� ��� �������� ����� �� SPI_EDF*/
  DMA_DeInit(DMA_StreamSPI_EDF_Tx);
  while (DMA_GetCmdStatus(DMA_StreamSPI_EDF_Tx) != DISABLE);
  
  DMA_InitStructure.DMA_Channel = DMA_ChannelSPI_EDF_Tx;
  DMA_InitStructure.DMA_PeripheralBaseAddr = SPI_EDF_DR_Address;
  DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)TxBuffer_SPI_EDF;
  DMA_InitStructure.DMA_DIR = DMA_DIR_MemoryToPeripheral;
  DMA_InitStructure.DMA_BufferSize = SIZE_PAGE_DATAFLASH_MAX + 10;
  DMA_InitStructure.DMA_Priority = DMA_Priority_VeryHigh; /*��� �� � ������ DMA_StreamSPI_EDF_Tx > �� � ������ DMA_StreamSPI_EDF_Rx, �� DMA_StreamSPI_EDF_Rx �� ������� ��� DMA_StreamSPI_EDF_Tx ��� ���������� ����������� ��������*/
  DMA_Init(DMA_StreamSPI_EDF_Tx, &DMA_InitStructure);
  DMA_ClearFlag(DMA_StreamSPI_EDF_Tx, DMA_FLAG_TCSPI_EDF_Tx | DMA_FLAG_HTSPI_EDF_Tx | DMA_FLAG_TEISPI_EDF_Tx | DMA_FLAG_DMEISPI_EDF_Tx | DMA_FLAG_FEISPI_EDF_Tx);

  /* DMA ���������� ��� ������� ����� �� SPI_EDF*/
  DMA_DeInit(DMA_StreamSPI_EDF_Rx);
  while (DMA_GetCmdStatus(DMA_StreamSPI_EDF_Rx) != DISABLE);
  
  DMA_InitStructure.DMA_Channel = DMA_ChannelSPI_EDF_Rx;
  DMA_InitStructure.DMA_PeripheralBaseAddr = SPI_EDF_DR_Address;
  DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)RxBuffer_SPI_EDF;
  DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory;
  DMA_InitStructure.DMA_Priority = DMA_Priority_VeryHigh; /*��� �� � ������ DMA_StreamSPI_EDF_Tx > �� � ������ DMA_StreamSPI_EDF_Rx, �� DMA_StreamSPI_EDF_Rx �� ������� ��� DMA_StreamSPI_EDF_Tx ��� ���������� ����������� ��������*/
  DMA_Init(DMA_StreamSPI_EDF_Rx, &DMA_InitStructure);
  DMA_ClearFlag(DMA_StreamSPI_EDF_Rx, DMA_FLAG_TCSPI_EDF_Rx | DMA_FLAG_HTSPI_EDF_Rx | DMA_FLAG_TEISPI_EDF_Rx | DMA_FLAG_DMEISPI_EDF_Rx | DMA_FLAG_FEISPI_EDF_Rx);

  /* ������ �� RS-485*/
  DMA_DeInit(DMA_StreamRS485_Rx);
  while (DMA_GetCmdStatus(DMA_StreamRS485_Rx) != DISABLE);
  
  DMA_InitStructure.DMA_Channel = DMA_ChannelRS485_Rx;
  DMA_InitStructure.DMA_PeripheralBaseAddr = USARTRS485_DR_Base;
  DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)RxBuffer_RS485;
  DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory;
  DMA_InitStructure.DMA_BufferSize = BUFFER_RS485;
  DMA_InitStructure.DMA_Priority = DMA_Priority_Low;
  DMA_Init(DMA_StreamRS485_Rx, &DMA_InitStructure);
  DMA_ClearFlag(DMA_StreamRS485_Rx, DMA_FLAG_TCRS485_Rx | DMA_FLAG_HTRS485_Rx | DMA_FLAG_TEIRS485_Rx | DMA_FLAG_DMEIRS485_Rx | DMA_FLAG_FEIRS485_Rx);
  
  /* �������� �� RS-485*/
  DMA_DeInit(DMA_StreamRS485_Tx);
  while (DMA_GetCmdStatus(DMA_StreamRS485_Tx) != DISABLE);

  DMA_InitStructure.DMA_Channel = DMA_ChannelRS485_Tx;
  DMA_InitStructure.DMA_PeripheralBaseAddr = USARTRS485_DR_Base;
  DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)TxBuffer_RS485;
  DMA_InitStructure.DMA_DIR = DMA_DIR_MemoryToPeripheral;
  DMA_InitStructure.DMA_BufferSize = 0;
  DMA_InitStructure.DMA_Priority = DMA_Priority_Low;
  DMA_Init(DMA_StreamRS485_Tx, &DMA_InitStructure);
  DMA_ClearFlag(DMA_StreamRS485_Tx, DMA_FLAG_TCRS485_Tx | DMA_FLAG_HTRS485_Tx | DMA_FLAG_TEIRS485_Tx | DMA_FLAG_DMEIRS485_Tx | DMA_FLAG_FEIRS485_Tx);
  /**********************/

#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
  /* ������ �� CANAL1_MO*/
  DMA_DeInit(DMA_StreamCANAL1_MO_Rx);
  while (DMA_GetCmdStatus(DMA_StreamCANAL1_MO_Rx) != DISABLE);
  
  DMA_InitStructure.DMA_Channel = DMA_ChannelCANAL1_MO_Rx;
  DMA_InitStructure.DMA_PeripheralBaseAddr = CANAL1_MO_DR_Base;
  DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)Canal1_MO_Received;
  DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory;
  DMA_InitStructure.DMA_BufferSize = BUFFER_CANAL1_MO;
  DMA_InitStructure.DMA_Priority = DMA_Priority_VeryHigh; /*��� �� � ������ DMA_ChannelCANAL1_MO_Tx > �� � ������ DMA_ChannelCANAL1_MO_Rx, �� DMA_ChannelCANAL1_MO_Rx �� ������� ��� DMA_ChannelCANAL1_MO_Tx ��� ���������� ����������� ��������*/
  DMA_Init(DMA_StreamCANAL1_MO_Rx, &DMA_InitStructure);
  DMA_ClearFlag(DMA_StreamCANAL1_MO_Rx, DMA_FLAG_TCCANAL1_MO_Rx | DMA_FLAG_HTCANAL1_MO_Rx | DMA_FLAG_TEICANAL1_MO_Rx | DMA_FLAG_DMEICANAL1_MO_Rx | DMA_FLAG_FEICANAL1_MO_Rx);
  
  /* �������� �� CANAL1_MO*/
  DMA_DeInit(DMA_StreamCANAL1_MO_Tx);
  while (DMA_GetCmdStatus(DMA_StreamCANAL1_MO_Tx) != DISABLE);

  DMA_InitStructure.DMA_Channel = DMA_ChannelCANAL1_MO_Tx;
  DMA_InitStructure.DMA_PeripheralBaseAddr = CANAL1_MO_DR_Base;
  DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)Canal1_MO_Transmit;
  DMA_InitStructure.DMA_DIR = DMA_DIR_MemoryToPeripheral;
  DMA_InitStructure.DMA_BufferSize = 0;
  DMA_InitStructure.DMA_Priority = DMA_Priority_VeryHigh; /*��� �� � ������ DMA_ChannelCANAL1_MO_Tx > �� � ������ DMA_ChannelCANAL1_MO_Rx, �� DMA_ChannelCANAL1_MO_Rx �� ������� ��� DMA_ChannelCANAL1_MO_Tx ��� ���������� ����������� ��������*/;
  DMA_Init(DMA_StreamCANAL1_MO_Tx, &DMA_InitStructure);
  DMA_ClearFlag(DMA_StreamCANAL1_MO_Tx, DMA_FLAG_TCCANAL1_MO_Tx | DMA_FLAG_HTCANAL1_MO_Tx | DMA_FLAG_TEICANAL1_MO_Tx | DMA_FLAG_DMEICANAL1_MO_Tx | DMA_FLAG_FEICANAL1_MO_Tx);

  /* ������ �� CANAL2_MO*/
  DMA_DeInit(DMA_StreamCANAL2_MO_Rx);
  while (DMA_GetCmdStatus(DMA_StreamCANAL2_MO_Rx) != DISABLE);
  
  DMA_InitStructure.DMA_Channel = DMA_ChannelCANAL2_MO_Rx;
  DMA_InitStructure.DMA_PeripheralBaseAddr = CANAL2_MO_DR_Base;
  DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)Canal2_MO_Received;
  DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory;
  DMA_InitStructure.DMA_BufferSize = BUFFER_CANAL2_MO;
  DMA_InitStructure.DMA_Priority = DMA_Priority_VeryHigh; /*��� �� � ������ DMA_ChannelCANAL2_MO_Tx > �� � ������ DMA_ChannelCANAL2_MO_Rx, �� DMA_ChannelCANAL2_MO_Rx �� ������� ��� DMA_ChannelCANAL2_MO_Tx ��� ���������� ����������� ��������*/
  DMA_Init(DMA_StreamCANAL2_MO_Rx, &DMA_InitStructure);
  DMA_ClearFlag(DMA_StreamCANAL2_MO_Rx, DMA_FLAG_TCCANAL2_MO_Rx | DMA_FLAG_HTCANAL2_MO_Rx | DMA_FLAG_TEICANAL2_MO_Rx | DMA_FLAG_DMEICANAL2_MO_Rx | DMA_FLAG_FEICANAL2_MO_Rx);
  
  /* �������� �� CANAL2_MO*/
  DMA_DeInit(DMA_StreamCANAL2_MO_Tx);
  while (DMA_GetCmdStatus(DMA_StreamCANAL2_MO_Tx) != DISABLE);

  DMA_InitStructure.DMA_Channel = DMA_ChannelCANAL2_MO_Tx;
  DMA_InitStructure.DMA_PeripheralBaseAddr = CANAL2_MO_DR_Base;
  DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)Canal2_MO_Transmit;
  DMA_InitStructure.DMA_DIR = DMA_DIR_MemoryToPeripheral;
  DMA_InitStructure.DMA_BufferSize = 0;
  DMA_InitStructure.DMA_Priority = DMA_Priority_VeryHigh; /*��� �� � ������ DMA_ChannelCANAL2_MO_Tx > �� � ������ DMA_ChannelCANAL2_MO_Rx, �� DMA_ChannelCANAL2_MO_Rx �� ������� ��� DMA_ChannelCANAL2_MO_Tx ��� ���������� ����������� ��������*/;
  DMA_Init(DMA_StreamCANAL2_MO_Tx, &DMA_InitStructure);
  DMA_ClearFlag(DMA_StreamCANAL2_MO_Tx, DMA_FLAG_TCCANAL2_MO_Tx | DMA_FLAG_HTCANAL2_MO_Tx | DMA_FLAG_TEICANAL2_MO_Tx | DMA_FLAG_DMEICANAL2_MO_Tx | DMA_FLAG_FEICANAL2_MO_Tx); 
  /**********************/
#endif

  /**********************/
  //������������ SPI ���  ��� � ���������� ������������ ��
  /**********************/
  SPI_InitTypeDef  SPI_InitStructure;
  
  SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
  SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
  SPI_InitStructure.SPI_DataSize = SPI_DataSize_16b;
  SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;
  SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;
  SPI_InitStructure.SPI_NSS =  SPI_NSS_Soft;
  SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_2;/*30���/2 = 15 ���*/
  SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
  SPI_InitStructure.SPI_CRCPolynomial = 7;
  SPI_Init(SPI_ADC, &SPI_InitStructure);

  /* ���������� SPI_ADC */
  SPI_Cmd(SPI_ADC, ENABLE);
  
  //��������� ������ ���
  //������� �������� �������
  if  (SPI_I2S_GetFlagStatus(SPI_ADC, SPI_I2S_FLAG_RXNE) == SET) SPI_I2S_ReceiveData(SPI_ADC);
  while (SPI_I2S_GetFlagStatus(SPI_ADC, SPI_I2S_FLAG_OVR) == SET) SPI_I2S_ReceiveData(SPI_ADC);
      
  for (unsigned int i = 0; i < NUMBER_ADCs; i++)
  {
    if (i == 0) GPIO_SELECT_ADC->BSRRH = GPIO_SELECTPin_ADC;
    else GPIO_SELECT_ADC->BSRRL = GPIO_SELECTPin_ADC; 
    
    //�������� ����� ����� 0xffff
    while (SPI_I2S_GetFlagStatus(SPI_ADC, SPI_I2S_FLAG_TXE) == RESET);          //�������, ���� SPI ����� ������
		tick_output_adc_p = TIM5->CNT;																							//Գ����� ��� ������� ���������
    GPIO_ResetBits(GPIO_SPI_ADC, GPIO_NSSPin_ADC);                              //����������� chip_select
    SPI_I2S_SendData(SPI_ADC, 0xFFFF);                                          //³���������� ����� 0xffff
    while (SPI_I2S_GetFlagStatus(SPI_ADC, SPI_I2S_FLAG_RXNE) == RESET);         //������� ���������� ���������� �� �������� ����� �� MISO
    GPIO_SetBits(GPIO_SPI_ADC, GPIO_NSSPin_ADC);                                //������ chip_select
    SPI_I2S_ReceiveData(SPI_ADC);                                               //������ ������� ���

    //�������� ����� ����� 0xffff
    while (SPI_I2S_GetFlagStatus(SPI_ADC, SPI_I2S_FLAG_TXE) == RESET);          //�������, ���� SPI ����� ������
		tick_output_adc_p = TIM5->CNT;																							//Գ����� ��� ������� ���������
    GPIO_ResetBits(GPIO_SPI_ADC, GPIO_NSSPin_ADC);                              //����������� chip_select
    SPI_I2S_SendData(SPI_ADC, 0xFFFF);                                          //³���������� ����� 0xffff
    while (SPI_I2S_GetFlagStatus(SPI_ADC, SPI_I2S_FLAG_RXNE) == RESET);         //������� ���������� ���������� �� �������� ����� �� MISO
    GPIO_SetBits(GPIO_SPI_ADC, GPIO_NSSPin_ADC);                                //������ chip_select
    SPI_I2S_ReceiveData(SPI_ADC);                                               //������ ������� ���
  }
  
  //���������� ����������� �� ���������� ����� �� SPI
  SPI_I2S_ITConfig(SPI_ADC, SPI_I2S_IT_RXNE, ENABLE);
  /**********************/

  /**********************/
  //������������ TIM4 �� ��������� ���������� ���� 10 �� ��� ��������� � 1 �� ��� ����������������� �����
  /**********************/
  /* ���������� TIM4 */
  /* ---------------------------------------------------------------
  TIM4 ������������: Output Compare Timing Mode:
  TIM4CLK = (30*2) ���, Prescaler = 600, TIM4 counter clock = 100 ���
  CC1 update rate = TIM4 counter clock / CCR1_Val = 100 Hz
  CC2 update rate = TIM4 counter clock / CCR1_Val = 1000 Hz
  --------------------------------------------------------------- */
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
  TIM_OCInitTypeDef  TIM_OCInitStructure;

  TIM_TimeBaseStructure.TIM_Period = 65535;
  TIM_TimeBaseStructure.TIM_Prescaler = (600-1);
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);

  /* Output Compare Timing Mode ������������: �����:1 */
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_Timing;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Disable;
  TIM_OCInitStructure.TIM_Pulse = TIM4_CCR1_VAL;
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
  TIM_OC1Init(TIM4, &TIM_OCInitStructure);
  
  TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Disable);

  /* ���������� ����������� �� ������ 1 ������� 4*/
  TIM_ITConfig(TIM4, TIM_IT_CC1, ENABLE);

  /* ��������� ������ ������� */
  TIM_Cmd(TIM4, ENABLE);
  /**********************/

  /**********************/
  //������������ SPI ���  DataFlash � ���������� �������� , �� ��������� ��������� � �������� �����
  /**********************/
  SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
  SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
  SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
  SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;
  SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;
  SPI_InitStructure.SPI_NSS =  SPI_NSS_Soft;
  SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_8;
  SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
  SPI_InitStructure.SPI_CRCPolynomial = 7;
  SPI_Init(SPI_EDF, &SPI_InitStructure);

  /* ����������� SPI_EDF DMA Tx ������ */
  SPI_I2S_DMACmd(SPI_EDF, SPI_I2S_DMAReq_Tx, DISABLE);
  /* ����������� SPI_EDF DMA Rx ������ */
  SPI_I2S_DMACmd(SPI_EDF, SPI_I2S_DMAReq_Rx, DISABLE);

  //������� ���������, �� �������� ��� ���������� ������/�������� ����� ��� DMA �� ������ DMA_StreamSPI_EDF_Rx � DMA_StreamSPI_EDF_Tx
  DMA_ClearFlag(DMA_StreamSPI_EDF_Rx, DMA_FLAG_TCSPI_EDF_Rx | DMA_FLAG_HTSPI_EDF_Rx | DMA_FLAG_TEISPI_EDF_Rx | DMA_FLAG_DMEISPI_EDF_Rx | DMA_FLAG_FEISPI_EDF_Rx);
  DMA_ClearFlag(DMA_StreamSPI_EDF_Tx, DMA_FLAG_TCSPI_EDF_Tx | DMA_FLAG_HTSPI_EDF_Tx | DMA_FLAG_TEISPI_EDF_Tx | DMA_FLAG_DMEISPI_EDF_Tx | DMA_FLAG_FEISPI_EDF_Tx);

  //���������� ����������� �� ������� �� SPI_EDF
  SPI_I2S_ITConfig(SPI_EDF, SPI_I2S_IT_ERR, ENABLE);

  /* ���������� SPI_EDF */
  SPI_Cmd(SPI_EDF, ENABLE);
  /**********************/

  /**********************/
  //������ �������� ��� ������ � EEPROM
  /**********************/
  comparison_writing &= (unsigned int)(~COMPARISON_WRITING_ENERGY);/*����������, � �� ���������*/
  _SET_BIT(control_spi1_taskes, TASK_START_READ_ENERGY_EEPROM_BIT);
  while(
        (control_spi1_taskes[0]     != 0) ||
        (control_spi1_taskes[1]     != 0) ||
        (state_execution_spi1 > 0)
       )
  {
    //������ � watchdogs
    watchdog_routine(WATCHDOG_KYYBOARD);

    main_routines_for_spi1();
    changing_diagnostyka_state();//ϳ����������� ����� ���������� �������� ����� ��� ���������� ���������� ����
  }
  /**********************/

  /**********************/
  //������ �������� ��� ��������� � EEPROM
  /**********************/
  comparison_writing &= (unsigned int)(~COMPARISON_WRITING_SETTINGS);/*����������, � �� ���������*/
  _SET_BIT(control_spi1_taskes, TASK_START_READ_SETTINGS_EEPROM_BIT);
  while(
        (control_spi1_taskes[0]     != 0) ||
        (control_spi1_taskes[1]     != 0) ||
        (state_execution_spi1 > 0)
       )
  {
    //������ � watchdogs
   watchdog_routine(WATCHDOG_KYYBOARD);

    main_routines_for_spi1();
    changing_diagnostyka_state();//ϳ����������� ����� ���������� �������� ����� ��� ���������� ���������� ����
  }
  /**********************/

  /**********************/
  //������ �������� ��� ��������� � EEPROM
  /**********************/
  comparison_writing &= (unsigned int)(~COMPARISON_WRITING_USTUVANNJA);/*����������, � �� ���������*/
  _SET_BIT(control_spi1_taskes, TASK_START_READ_USTUVANNJA_EEPROM_BIT);
  while(
        (control_spi1_taskes[0]     != 0) ||
        (control_spi1_taskes[1]     != 0) ||
        (state_execution_spi1 > 0)
       )
  {
    //������ � watchdogs
    watchdog_routine(WATCHDOG_KYYBOARD);

    main_routines_for_spi1();
    changing_diagnostyka_state();//ϳ����������� ����� ���������� �������� ����� ��� ���������� ���������� ����
  }
  /**********************/

  /**********************/
  //������ �������� ��� ��� �������� ������ � ������� ���������
  /**********************/
  comparison_writing &= (unsigned int)(~COMPARISON_WRITING_STATE_LEDS_OUTPUTS);/*����������, � �� ���������*/
  _SET_BIT(control_spi1_taskes, TASK_START_READ_STATE_LEDS_OUTPUTS_EEPROM_BIT);
  while(
        (control_spi1_taskes[0]     != 0) ||
        (control_spi1_taskes[1]     != 0) ||
        (state_execution_spi1 > 0)
       )
  {
    //������ � watchdogs
    watchdog_routine(WATCHDOG_KYYBOARD);

    main_routines_for_spi1();
    changing_diagnostyka_state();//ϳ����������� ����� ���������� �������� ����� ��� ���������� ���������� ����
  }
  /**********************/
  
  /**********************/
  //������ �������� ��� ��� �������� ����������
  /**********************/
  comparison_writing &= (unsigned int)(~COMPARISON_WRITING_TRG_FUNC);/*����������, � �� ���������*/
  _SET_BIT(control_spi1_taskes, TASK_START_READ_TRG_FUNC_EEPROM_BIT);
  while(
        (control_spi1_taskes[0]     != 0) ||
        (control_spi1_taskes[1]     != 0) ||
        (state_execution_spi1 > 0)
       )
  {
    //������ � watchdogs
    watchdog_routine(WATCHDOG_KYYBOARD);

    main_routines_for_spi1();
    changing_diagnostyka_state();//ϳ����������� ����� ���������� �������� ����� ��� ���������� ���������� ����
  }
  /**********************/
  
  if((state_spi1_task & STATE_SETTINGS_EEPROM_GOOD) != 0)
  {
    /*
    ������� ��� ������ ����� ����������� ���������� ���� ������������
    ����������� ������� ������, ��� �������� �� ������ ����������� �
    ������������� ������, �� �� ������� ����� ���������� �����, ���� ��������
    ������ ���������� ���������.
    � ������� ��� ��������� ���������� �� ����������� ���������� �� ����
    �������� - ����� ��� ���������� �� ����������� ��������� ���� �������, ����
    �������� ������ ���������� �� ����������
    */
    /**********************/
    //������ �������� ��� ����������� ���������� � EEPROM
    /**********************/
    comparison_writing &= (unsigned int)(~COMPARISON_WRITING_INFO_REJESTRATOR_AR);/*����������, � �� ���������*/
    _SET_BIT(control_spi1_taskes, TASK_START_READ_INFO_REJESTRATOR_AR_EEPROM_BIT);
    while(
          (control_spi1_taskes[0]     != 0) ||
          (control_spi1_taskes[1]     != 0) ||
          (state_execution_spi1 > 0)
         )
    {
      //������ � watchdogs
      watchdog_routine(WATCHDOG_KYYBOARD);

      main_routines_for_spi1();
      changing_diagnostyka_state();//ϳ����������� ����� ���������� �������� ����� ��� ���������� ���������� ����
    }
    /**********************/
  }

  /**********************/
  //������ �������� ��� ����������� ���������� � EEPROM
  /**********************/
  comparison_writing &= (unsigned int)(~COMPARISON_WRITING_INFO_REJESTRATOR_DR);/*����������, � �� ���������*/
  _SET_BIT(control_spi1_taskes, TASK_START_READ_INFO_REJESTRATOR_DR_EEPROM_BIT);
  while(
        (control_spi1_taskes[0]     != 0) ||
        (control_spi1_taskes[1]     != 0) ||
        (state_execution_spi1 > 0)
       )
  {
    //������ � watchdogs
    watchdog_routine(WATCHDOG_KYYBOARD);

    main_routines_for_spi1();
    changing_diagnostyka_state();//ϳ����������� ����� ���������� �������� ����� ��� ���������� ���������� ����
  }
  /**********************/

  /**********************/
  //������ �������� ��� ���������� ���������� ���� � EEPROM
  /**********************/
  comparison_writing &= (unsigned int)(~COMPARISON_WRITING_INFO_REJESTRATOR_PR_ERR);/*����������, � �� ���������*/
  _SET_BIT(control_spi1_taskes, TASK_START_READ_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT);
  while(
        (control_spi1_taskes[0]     != 0) ||
        (control_spi1_taskes[1]     != 0) ||
        (state_execution_spi1 > 0)
       )
  {
    //������ � watchdogs
    watchdog_routine(WATCHDOG_KYYBOARD);

    main_routines_for_spi1();
    changing_diagnostyka_state();//ϳ����������� ����� ���������� �������� ����� ��� ���������� ���������� ����
  }
  /**********************/

  /**********************/
  //������ �������� ��� ������� ��������
  /**********************/
  comparison_writing &= (unsigned int)(~COMPARISON_WRITING_RESURS);/*����������, � �� ���������*/
  _SET_BIT(control_spi1_taskes, TASK_START_READ_RESURS_EEPROM_BIT);
  while(
        (control_spi1_taskes[0]     != 0) ||
        (control_spi1_taskes[1]     != 0) ||
        (state_execution_spi1 > 0)
       )
  {
    //������ � watchdogs
    watchdog_routine(WATCHDOG_KYYBOARD);

    main_routines_for_spi1();
    changing_diagnostyka_state();//ϳ����������� ����� ���������� �������� ����� ��� ���������� ���������� ����
  }
  /**********************/

#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
  /**********************/
  //����������� CANAL1_MO � CANAL2_MO: 6.75���/�, �������� �������, ���� ���� ��
  /**********************/
  USART_InitTypeDef USART_InitStructure;

  //���������� ���������
  USART_InitStructure.USART_BaudRate = 7500000;
  USART_InitStructure.USART_WordLength = USART_WordLength_9b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_Even;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
  
  //�������� ������������ CANAL1_MO
  USART_OverSampling8Cmd(CANAL1_MO, ENABLE);
  USART_Init(CANAL1_MO, &USART_InitStructure);
  //�������� ������������ CANAL2_MO
  USART_OverSampling8Cmd(CANAL2_MO, ENABLE);
  USART_Init(CANAL2_MO, &USART_InitStructure);

  //���������� �������� ����� DMA
  CANAL1_MO->CR3 |= USART_DMAReq_Rx;
  CANAL1_MO->CR3 |= USART_DMAReq_Tx;
  /*------------------------------*/
  CANAL2_MO->CR3 |= USART_DMAReq_Rx;
  CANAL2_MO->CR3 |= USART_DMAReq_Tx;

//  //���������� ����������� �� CANAL1_MO ��� �������� �������
//  USART_ITConfig(CANAL1_MO, USART_IT_IDLE, ENABLE);
//  USART_ITConfig(CANAL1_MO, USART_IT_LBD, ENABLE);
//  USART_ITConfig(CANAL1_MO, USART_IT_PE, ENABLE);
//  USART_ITConfig(CANAL1_MO, USART_IT_ERR, ENABLE);
//  //���������� ����������� �� CANAL2_MO ��� �������� �������
//  USART_ITConfig(CANAL2_MO, USART_IT_IDLE, ENABLE);
//  USART_ITConfig(CANAL2_MO, USART_IT_LBD, ENABLE);
//  USART_ITConfig(CANAL2_MO, USART_IT_PE, ENABLE);
//  USART_ITConfig(CANAL2_MO, USART_IT_ERR, ENABLE);

  //���������� CANAL1_MO
  CANAL1_MO->CR1 |= USART_CR1_UE;
  //���������� CANAL2_MO
  CANAL2_MO->CR1 |= USART_CR1_UE;
  
  //���������� ������ DMA  �� ���������
  DMA_StreamCANAL1_MO_Rx->CR |= (uint32_t)DMA_SxCR_EN;
  /*------------------------------*/
  DMA_StreamCANAL2_MO_Rx->CR |= (uint32_t)DMA_SxCR_EN;
  /**********************/
#endif

  /**********************/
  //������������ TIM2 �� ��������� ���������� ���� 1 �� ��� ������� �������
  /**********************/
  /* ���������� TIM2 */
  /* ---------------------------------------------------------------
  TIM2 ������������: Output Compare Timing Mode:
  TIM2CLK = 30*2 ���, Prescaler = 60, TIM2 counter clock = 1 ���
  CC1 update rate = TIM2 counter clock / CCR1_Val = 1000 Hz
  --------------------------------------------------------------- */
  TIM_TimeBaseStructure.TIM_Period = 0xffffffff;
  TIM_TimeBaseStructure.TIM_Prescaler = (60-1);
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

  /* Output Compare Timing Mode ������������: �����:1 */
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_Timing;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Disable;
  TIM_OCInitStructure.TIM_Pulse = TIM2_CCR1_VAL;
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
  TIM_OC1Init(TIM2, &TIM_OCInitStructure);
  
  TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Disable);

  /* ���������� ����������� �� ������ 1 ������� 2*/
  TIM_ITConfig(TIM2, TIM_IT_CC1, ENABLE);
  /**********************/

  /**********************/
  //������������ TIM5 �� ��������� ���������� ���� 0,625 ��
  /**********************/
  /* ���������� TIM5 */
  /* ---------------------------------------------------------------
  TIM5 ������������: Output Compare Timing Mode:
  TIM2CLK = 30*2 ���, Prescaler = 1, TIM5 counter clock = 60 ���
  CC1 update rate = TIM5 counter clock / CCR1_Val = 1600 Hz
  --------------------------------------------------------------- */
  TIM_TimeBaseStructure.TIM_Period = 0xffffffff;
  TIM_TimeBaseStructure.TIM_Prescaler = (1-1);
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBaseInit(TIM5, &TIM_TimeBaseStructure);

  /* Output Compare Timing Mode ������������: �����:1 */
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_Timing;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Disable;
  TIM_OCInitStructure.TIM_Pulse = step_timer_adc;
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
  TIM_OC1Init(TIM5, &TIM_OCInitStructure);
  TIM_OC1PreloadConfig(TIM5, TIM_OCPreload_Disable);

  TIM_OCInitStructure.TIM_Pulse = TIM5_CCR1_2_VAL;
  TIM_OC2Init(TIM5, &TIM_OCInitStructure);
  TIM_OC2PreloadConfig(TIM5, TIM_OCPreload_Disable);
  
  /* ���������� ����������� �� ������ 1 ������� 5*/
  TIM_ITConfig(TIM5, TIM_IT_CC1, ENABLE);
  /* ���������� ����������� �� ������ 2 ������� 5*/
  TIM_ITConfig(TIM5, TIM_IT_CC2, ENABLE);
  /**********************/

  //������ � watchdogs
  watchdog_routine(WATCHDOG_KYYBOARD);

//  /**********************/
//  //����������� USB
//  /**********************/
//  USBD_Init(&USB_OTG_dev,
//#ifdef USE_USB_OTG_HS 
//            USB_OTG_HS_CORE_ID,
//#else            
//            USB_OTG_FS_CORE_ID,
//#endif  
//            &USR_desc, 
//            &USBD_CDC_cb, 
//            &USR_cb);
//  /**********************/

//  //������ � watchdogs
//  if ((control_word_of_watchdog & WATCHDOG_KYYBOARD) == WATCHDOG_KYYBOARD)
//  {
//    //������� ���� ��� ���������� Watchdog �� �����������
//    GPIO_WriteBit(
//                  GPIO_EXTERNAL_WATCHDOG,
//                  GPIO_PIN_EXTERNAL_WATCHDOG,
//                  (BitAction)(1 - GPIO_ReadOutputDataBit(GPIO_EXTERNAL_WATCHDOG, GPIO_PIN_EXTERNAL_WATCHDOG))
//                 );
//    control_word_of_watchdog =  0;
//  }
}
/**************************************/

/**************************************/
//̳������� ������������
/**************************************/
void min_settings(__SETTINGS *target_label)
{
  target_label->device_id = ((VERSIA_PZ << 8) | (MODYFIKACIA_VERSII_PZ));
    
  target_label->type_of_input = 0x0;
  target_label->type_of_input_signal = 0x0;
  
  for(unsigned int i = 0; i < NUMBER_INPUTS; i++)
  {
    for (size_t j = 0; j < N_SMALL; ++j) target_label->ranguvannja_inputs[N_SMALL*i + j] = 0x0;
    
    if ((target_label->type_of_input_signal & (1<<i)) != 0)
    {
      target_label->dopusk_dv[i] = KOEF_DOPUSK_DV_ZMIN_MIN;
      if ((target_label->dopusk_dv[i] % 10) != 0)
      {
        target_label->dopusk_dv[i] = (target_label->dopusk_dv[i] / 10)*10;
      }
    }
    else
      target_label->dopusk_dv[i] = KOEF_DOPUSK_DV_POST_MIN;
  }

  target_label->type_of_output = 0x0;
  target_label->type_of_output_modif = 0x0;
  for(unsigned int i = 0; i < NUMBER_OUTPUTS; i++)
  {
    for (unsigned int j = 0; j < N_BIG; j++ ) target_label->ranguvannja_outputs[N_BIG*i+j] = 0x0;
  }

  target_label->type_of_led = 0x0;
  for(unsigned int i = 0; i < NUMBER_LEDS; i++)
  {
    for (unsigned int j = 0; j < N_BIG; j++ ) target_label->ranguvannja_leds[N_BIG*i+j] = 0x0;
  }

  for (unsigned int j = 0; j < N_BIG; j++ ) 
  {
    target_label->ranguvannja_analog_registrator[j]  = 0x0;
    target_label->ranguvannja_digital_registrator[j] = 0x0;

    target_label->ranguvannja_off_cb[j] = 0x0;
    target_label->ranguvannja_on_cb[j] = 0x0;
    target_label->ranguvannja_off_cb_oh[j] = 0x0;
    target_label->ranguvannja_on__cb_oh[j] = 0x0;
    target_label->ranguvannja_off_cb_rl[j] = 0x0;
    target_label->ranguvannja_on__cb_rl[j] = 0x0;
	
  }
  
  target_label->number_iteration_el = NUMBER_ITERATION_EL_MAX;
//  target_label->number_defined_df = NUMBER_DEFINED_FUNCTIONS_MAX;
//  target_label->number_defined_dt = NUMBER_DEFINED_TRIGGERS_MAX;
//  target_label->number_defined_and = NUMBER_DEFINED_AND_MAX;
//  target_label->number_defined_or = NUMBER_DEFINED_OR_MAX;
//  target_label->number_defined_xor = NUMBER_DEFINED_XOR_MAX;
//  target_label->number_defined_not = NUMBER_DEFINED_NOT_MAX;

  target_label->type_df = 0x0;
  
  for(unsigned int i = 0; i < NUMBER_DEFINED_FUNCTIONS; i++)
  {
    target_label->timeout_pause_df[i] = TIMEOUT_DF_PAUSE_MIN;
    target_label->timeout_work_df[i] = TIMEOUT_DF_WORK_MIN;

    for (unsigned int j = 0; j < N_BIG; j++ ) 
    {
      target_label->ranguvannja_df_source_plus[N_BIG*i+j]  = 0x0;
      target_label->ranguvannja_df_source_minus[N_BIG*i+j] = 0x0;
      target_label->ranguvannja_df_source_blk[N_BIG*i+j]   = 0x0;
    }
  }
  
  for(unsigned int i = 0; i < NUMBER_DEFINED_TRIGGERS; i++)
  {
    for (unsigned int j = 0; j < N_BIG; j++ ) 
    {
      target_label->ranguvannja_set_dt_source_plus[N_BIG*i+j]    = 0x0;
      target_label->ranguvannja_set_dt_source_minus[N_BIG*i+j]   = 0x0;
      target_label->ranguvannja_reset_dt_source_plus[N_BIG*i+j]  = 0x0;
      target_label->ranguvannja_reset_dt_source_minus[N_BIG*i+j] = 0x0;
    }
  }
  
  for(unsigned int i = 0; i < NUMBER_DEFINED_AND; i++)
  {
    for (unsigned int j = 0; j < N_BIG; j++ ) target_label->ranguvannja_d_and[N_BIG*i+j] = 0x0;
  }
  
  for(unsigned int i = 0; i < NUMBER_DEFINED_OR; i++)
  {
    for (unsigned int j = 0; j < N_BIG; j++ ) target_label->ranguvannja_d_or[N_BIG*i+j] = 0x0;
  }
  
  for(unsigned int i = 0; i < NUMBER_DEFINED_XOR; i++)
  {
    for (unsigned int j = 0; j < N_BIG; j++ ) target_label->ranguvannja_d_xor[N_BIG*i+j] = 0x0;
  }
  
  for(unsigned int i = 0; i < NUMBER_DEFINED_NOT; i++)
  {
    for (unsigned int j = 0; j < N_BIG; j++ ) target_label->ranguvannja_d_not[N_BIG*i+j] = 0x0;
  }
  
  for(unsigned int i = 0; i < NUMBER_TRANSFER_FUNCTIONS; i++) target_label->ranguvannja_tf[i] = 0x0;
  
  target_label->buttons_mode = 0;
  for(unsigned int i = 0; i < NUMBER_DEFINED_BUTTONS; i++)
  {
    for (size_t j = 0; j < N_SMALL; ++j) target_label->ranguvannja_buttons[N_SMALL*i + j] = 0x0;
  }

#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
  for(size_t i = 0; i < N_IN_GOOSE; i++)
  {
    for(size_t j = 0; j < N_IN_GOOSE_MMS_OUT; j++) 
    {
      for(size_t k = 0; k < N_SMALL; k++) target_label->ranguvannja_In_GOOSE[i][j][k] = 0;
    }
  }

  for(size_t i = 0; i < N_IN_MMS; i++)
  {
    for(size_t j = 0; j < N_IN_GOOSE_MMS_OUT; j++)
    {
      for(size_t k = 0; k < N_SMALL; k++) target_label->ranguvannja_In_MMS[i][j][k] = 0;
    }
  }

  for(size_t i = 0; i < N_OUT_LAN; i++)
  {
    for(size_t j = 0; j < N_OUT_LAN_IN; j++) 
    {
      for(size_t k = 0; k < MAX_FUNCTIONS_IN_OUT_LAN; k++) target_label->ranguvannja_Out_LAN[i][j][k] = 0;
    }
  }
#endif

  target_label->configuration = 0;
  
  target_label->ctrl_zdz_type = ZDZ_CTRL_MIN;
#if (                                   \
       (MODYFIKACIA_VERSII_PZ == 0) ||  \
       (MODYFIKACIA_VERSII_PZ == 3) ||  \
       (MODYFIKACIA_VERSII_PZ == 4) ||  \
       (MODYFIKACIA_VERSII_PZ == 6) ||  \
       (MODYFIKACIA_VERSII_PZ == 10)||  \
       (MODYFIKACIA_VERSII_PZ == 13)||  \
       (MODYFIKACIA_VERSII_PZ == 14)    \
      )   
  target_label->zdz_ovd_porig = 0;
#endif
  for (size_t i = 0; i < NUMBER_UP; i++) target_label->ctrl_UP_input[i] = UP_CTRL_Ia_Ib_Ic;

  //.target_label->control_dz = 0;
  target_label->control_dzo = 0;
  target_label->control_dzr = 0;
  target_label->control_mtz = 0;
  target_label->control_mtzo = 0;
  target_label->control_mtzr = 0;
  target_label->control_zdz = 0;
  target_label->control_zz = 0;
  target_label->control_tznp = 0;
  target_label->control_apv = 0;
  target_label->control_achr_chapv = 0;
  target_label->control_urov = 0;
  target_label->control_zop = 0;
  target_label->control_Umin = 0;
  target_label->control_Umax = 0;
  target_label->control_UP = 0;
  
  target_label->grupa_ustavok = SETPOINT_GRUPA_USTAVOK_MIN;
  
  target_label->type_mtz1 = TYPE_MTZ_SIMPLE;
  target_label->type_mtz2 = TYPE_MTZ_SIMPLE;
  target_label->type_mtz3 = TYPE_MTZ_SIMPLE;
  target_label->type_mtz4 = TYPE_MTZ_SIMPLE;
  
  target_label->type_mtzo1  = TYPE_MTZ_SIMPLE;
  target_label->type_mtzo2  = TYPE_MTZ_SIMPLE;
  target_label->type_mtzo3  = TYPE_MTZ_SIMPLE;
  target_label->type_mtzo4  = TYPE_MTZ_SIMPLE;
  target_label->type_mtzr1  = TYPE_MTZ_SIMPLE;
  target_label->type_mtzr2  = TYPE_MTZ_SIMPLE;
  
  
  for (unsigned int i = 0; i < NUMBER_GROUP_USTAVOK; i++)
  {
    int angle;
    float angle_f;
    
    //��
//.    target_label->pickup_dz_k[i] = PICKUP_DZ_K_MIN;
//.    
//.    target_label->pickup_dz1[i] = PICKUP_DZ1_MIN;
//.    target_label->pickup_dz1_amtz[i] = PICKUP_DZ1_AMTZ_MIN;
//.
//.    target_label->timeout_dz1[i] = TIMEOUT_DZ1_MIN;
//.    target_label->timeout_dz1_amtz[i] = TIMEOUT_DZ1_AMTZ_MIN;
//.    
//.    angle = PICKUP_DZ2_ANGLE_MIN;
//.    angle_f = (float)angle;
//.    target_label->pickup_dz2_angle[i] = angle;
//.    target_label->pickup_dz2_angle_cos1[i] = (int) (AMPLITUDA_SECTOR*/*cos*/arm_cos_f32(/*(double)*/(PI*angle_f/180.0f)));
//.    target_label->pickup_dz2_angle_sin1[i] = (int) (AMPLITUDA_SECTOR*/*sin*/arm_sin_f32(/*(double)*/(PI*angle_f/180.0f)));
//.    target_label->pickup_dz2_angle_cos2[i] = (int) (AMPLITUDA_SECTOR*/*cos*/arm_cos_f32(/*(double)*/(PI*(angle_f - DELTA_SECTOR_DZ)/180.0f)));
//.    target_label->pickup_dz2_angle_sin2[i] = (int) (AMPLITUDA_SECTOR*/*sin*/arm_sin_f32(/*(double)*/(PI*(angle_f - DELTA_SECTOR_DZ)/180.0f)));
//.    
//.    target_label->pickup_dz2_dir[i] = PICKUP_DZ2_DIR_MIN;
//.    target_label->pickup_dz2_inv[i] = PICKUP_DZ2_INV_MIN;
//.    target_label->pickup_dz2_amtz[i] = PICKUP_DZ2_AMTZ_MIN;
//.    
//.    target_label->timeout_dz2_dir[i] = TIMEOUT_DZ2_DIR_MIN;
//.    target_label->timeout_dz2_dir_pr[i] = TIMEOUT_DZ2_DIR_PR_MIN;
//.    target_label->timeout_dz2_inv[i] = TIMEOUT_DZ2_INV_MIN;
//.    target_label->timeout_dz2_inv_pr[i] = TIMEOUT_DZ2_INV_PR_MIN;
//.    target_label->timeout_dz2_amtz[i] = TIMEOUT_DZ2_AMTZ_MIN;
//.    target_label->timeout_dz2_amtz_pr[i] = TIMEOUT_DZ2_AMTZ_PR_MIN;
//.    target_label->timeout_dz2_vvid_pr[i] = TIMEOUT_DZ2_VVID_PR_MIN;
//.    target_label->timeout_dz2_amtz_vvid_pr[i] = TIMEOUT_DZ2_AMTZ_VVID_PR_MIN;
//.    
//.    angle = PICKUP_DZ3_ANGLE_MIN;
//.    angle_f = (float)angle;
//.    target_label->pickup_dz3_angle[i] = angle;
//.    target_label->pickup_dz3_angle_cos1[i] = (int) (AMPLITUDA_SECTOR*/*cos*/arm_cos_f32(/*(double)*/(PI*angle_f/180.0f)));
//.    target_label->pickup_dz3_angle_sin1[i] = (int) (AMPLITUDA_SECTOR*/*sin*/arm_sin_f32(/*(double)*/(PI*angle_f/180.0f)));
//.    target_label->pickup_dz3_angle_cos2[i] = (int) (AMPLITUDA_SECTOR*/*cos*/arm_cos_f32(/*(double)*/(PI*(angle_f - DELTA_SECTOR_DZ)/180.0f)));
//.    target_label->pickup_dz3_angle_sin2[i] = (int) (AMPLITUDA_SECTOR*/*sin*/arm_sin_f32(/*(double)*/(PI*(angle_f - DELTA_SECTOR_DZ)/180.0f)));
//.    
//.    target_label->pickup_dz3_dir[i] = PICKUP_DZ3_DIR_MIN;
//.    target_label->pickup_dz3_inv[i] = PICKUP_DZ3_INV_MIN;
//.    target_label->pickup_dz3_amtz[i] = PICKUP_DZ3_AMTZ_MIN;
//.    
//.    target_label->timeout_dz3_dir[i] = TIMEOUT_DZ3_DIR_MIN;
//.    target_label->timeout_dz3_dir_pr[i] = TIMEOUT_DZ3_DIR_PR_MIN;
//.    target_label->timeout_dz3_inv[i] = TIMEOUT_DZ3_INV_MIN;
//.    target_label->timeout_dz3_inv_pr[i] = TIMEOUT_DZ3_INV_PR_MIN;
//.    target_label->timeout_dz3_amtz[i] = TIMEOUT_DZ3_AMTZ_MIN;
//.    target_label->timeout_dz3_amtz_pr[i] = TIMEOUT_DZ3_AMTZ_PR_MIN;
//.    target_label->timeout_dz3_vvid_pr[i] = TIMEOUT_DZ3_VVID_PR_MIN;
//.    target_label->timeout_dz3_amtz_vvid_pr[i] = TIMEOUT_DZ3_AMTZ_VVID_PR_MIN;
//.
//.    angle = PICKUP_DZ4_ANGLE_MIN;
//.    angle_f = (float)angle;
//.    target_label->pickup_dz4_angle[i] = angle;
//.    target_label->pickup_dz4_angle_cos1[i] = (int) (AMPLITUDA_SECTOR*/*cos*/arm_cos_f32(/*(double)*/(PI*angle_f/180.0f)));
//.    target_label->pickup_dz4_angle_sin1[i] = (int) (AMPLITUDA_SECTOR*/*sin*/arm_sin_f32(/*(double)*/(PI*angle_f/180.0f)));
//.    target_label->pickup_dz4_angle_cos2[i] = (int) (AMPLITUDA_SECTOR*/*cos*/arm_cos_f32(/*(double)*/(PI*(angle_f - DELTA_SECTOR_DZ)/180.0f)));
//.    target_label->pickup_dz4_angle_sin2[i] = (int) (AMPLITUDA_SECTOR*/*sin*/arm_sin_f32(/*(double)*/(PI*(angle_f - DELTA_SECTOR_DZ)/180.0f)));
//.    
//.    target_label->pickup_dz4_dir[i] = PICKUP_DZ4_DIR_MIN;
//.    target_label->pickup_dz4_inv[i] = PICKUP_DZ4_INV_MIN;
//.    target_label->pickup_dz4_amtz[i] = PICKUP_DZ4_AMTZ_MIN;
//.
//.    target_label->timeout_dz4_dir[i] = TIMEOUT_DZ4_DIR_MIN;
//.    target_label->timeout_dz4_dir_pr[i] = TIMEOUT_DZ4_DIR_PR_MIN;
//.    target_label->timeout_dz4_inv[i] = TIMEOUT_DZ4_INV_MIN;
//.    target_label->timeout_dz4_inv_pr[i] = TIMEOUT_DZ4_INV_PR_MIN;
//.    target_label->timeout_dz4_amtz[i] = TIMEOUT_DZ4_AMTZ_MIN;
//.    target_label->timeout_dz4_amtz_pr[i] = TIMEOUT_DZ4_AMTZ_PR_MIN;
//.    target_label->timeout_dz4_vvid_pr[i] = TIMEOUT_DZ4_VVID_PR_MIN;
//.    target_label->timeout_dz4_amtz_vvid_pr[i] = TIMEOUT_DZ4_AMTZ_VVID_PR_MIN;
//.    
//.    target_label->timeout_nkn_dz[i] = TIMEOUT_NKN_DZ_MIN;
    
    //���
    target_label->setpoint_mtz_1[i] = SETPOINT_MTZ1_MIN;
    target_label->setpoint_mtz_1_n_vpered[i] = SETPOINT_MTZ1_N_VPERED_MIN;
    target_label->setpoint_mtz_1_n_nazad[i] = SETPOINT_MTZ1_N_NAZAD_MIN;
    
    angle = SETPOINT_MTZ1_ANGLE_MIN;
    angle_f = (float)angle;
    target_label->setpoint_mtz_1_angle[i] = angle;
    target_label->setpoint_mtz_1_angle_cos[i] = (int) (AMPLITUDA_FI*/*cos*/arm_cos_f32(/*(double)*/(PI*angle_f/180.0f)));
    target_label->setpoint_mtz_1_angle_sin[i] = (int) (AMPLITUDA_FI*/*sin*/arm_sin_f32(/*(double)*/(PI*angle_f/180.0f)));
    
    target_label->setpoint_mtz_1_po_napruzi[i] = SETPOINT_MTZ1_PO_NAPRUZI_MIN;
    target_label->setpoint_mtz_1_U[i] = SETPOINT_MTZ1_U_MIN;

    target_label->setpoint_mtz_2[i] = SETPOINT_MTZ2_MIN;
    target_label->setpoint_mtz_2_n_vpered[i] = SETPOINT_MTZ2_N_VPERED_MIN;
    target_label->setpoint_mtz_2_n_nazad[i] = SETPOINT_MTZ2_N_NAZAD_MIN;
    
    angle = SETPOINT_MTZ2_ANGLE_MIN;
    angle_f = (float)angle;
    target_label->setpoint_mtz_2_angle[i] = angle;
    target_label->setpoint_mtz_2_angle_cos[i] = (int) (AMPLITUDA_FI*/*cos*/arm_cos_f32(/*(double)*/(PI*angle_f/180.0f)));
    target_label->setpoint_mtz_2_angle_sin[i] = (int) (AMPLITUDA_FI*/*sin*/arm_sin_f32(/*(double)*/(PI*angle_f/180.0f)));
    
    target_label->setpoint_mtz_2_po_napruzi[i] = SETPOINT_MTZ2_PO_NAPRUZI_MIN;
    target_label->setpoint_mtz_2_U[i] = SETPOINT_MTZ2_U_MIN;

    target_label->setpoint_mtz_3[i] = SETPOINT_MTZ3_MIN;
    target_label->setpoint_mtz_3_n_vpered[i] = SETPOINT_MTZ3_N_VPERED_MIN;
    target_label->setpoint_mtz_3_n_nazad[i] = SETPOINT_MTZ3_N_NAZAD_MIN;
    
    angle = SETPOINT_MTZ3_ANGLE_MIN;
    angle_f = (float)angle;
    target_label->setpoint_mtz_3_angle[i] = angle;
    target_label->setpoint_mtz_3_angle_cos[i] = (int) (AMPLITUDA_FI*/*cos*/arm_cos_f32(/*(double)*/(PI*angle_f/180.0f)));
    target_label->setpoint_mtz_3_angle_sin[i] = (int) (AMPLITUDA_FI*/*sin*/arm_sin_f32(/*(double)*/(PI*angle_f/180.0f)));
    
    target_label->setpoint_mtz_3_po_napruzi[i] = SETPOINT_MTZ3_PO_NAPRUZI_MIN;
    target_label->setpoint_mtz_3_U[i] = SETPOINT_MTZ3_U_MIN;

    target_label->setpoint_mtz_4[i] = SETPOINT_MTZ4_MIN;
    target_label->setpoint_mtz_4_n_vpered[i] = SETPOINT_MTZ4_N_VPERED_MIN;
    target_label->setpoint_mtz_4_n_nazad[i] = SETPOINT_MTZ4_N_NAZAD_MIN;
    
    angle = SETPOINT_MTZ4_ANGLE_MIN;
    angle_f = (float)angle;
    target_label->setpoint_mtz_4_angle[i] = angle;
    target_label->setpoint_mtz_4_angle_cos[i] = (int) (AMPLITUDA_FI*/*cos*/arm_cos_f32(/*(double)*/(PI*angle_f/180.0f)));
    target_label->setpoint_mtz_4_angle_sin[i] = (int) (AMPLITUDA_FI*/*sin*/arm_sin_f32(/*(double)*/(PI*angle_f/180.0f)));
    
    target_label->setpoint_mtz_4_po_napruzi[i] = SETPOINT_MTZ4_PO_NAPRUZI_MIN;
    target_label->setpoint_mtz_4_U[i] = SETPOINT_MTZ4_U_MIN;
    
    target_label->timeout_mtz_1[i] = TIMEOUT_MTZ1_MIN; 
    target_label->timeout_mtz_1_n_vpered[i] = TIMEOUT_MTZ1_N_VPERED_MIN; 
    target_label->timeout_mtz_1_n_nazad[i] = TIMEOUT_MTZ1_N_NAZAD_MIN; 
    target_label->timeout_mtz_1_po_napruzi[i] = TIMEOUT_MTZ1_PO_NAPRUZI_MIN; 

    target_label->timeout_mtz_2[i] = TIMEOUT_MTZ2_MIN; 
    target_label->timeout_mtz_2_pr[i] = TIMEOUT_MTZ2_PR_MIN; 
    target_label->timeout_mtz_2_n_vpered[i] = TIMEOUT_MTZ2_N_VPERED_MIN; 
    target_label->timeout_mtz_2_n_vpered_pr[i] = TIMEOUT_MTZ2_N_VPERED_PR_MIN; 
    target_label->timeout_mtz_2_n_nazad[i] = TIMEOUT_MTZ2_N_NAZAD_MIN; 
    target_label->timeout_mtz_2_n_nazad_pr[i] = TIMEOUT_MTZ2_N_NAZAD_PR_MIN; 
    target_label->timeout_mtz_2_po_napruzi[i] = TIMEOUT_MTZ2_PO_NAPRUZI_MIN; 
    target_label->timeout_mtz_2_po_napruzi_pr[i] = TIMEOUT_MTZ2_PO_NAPRUZI_PR_MIN; 
    target_label->timeout_mtz_2_vvid_pr[i] = TIMEOUT_MTZ2_VVID_PR_MIN;

    target_label->timeout_mtz_3[i] = TIMEOUT_MTZ3_MIN; 
    target_label->timeout_mtz_3_n_vpered[i] = TIMEOUT_MTZ3_N_VPERED_MIN; 
    target_label->timeout_mtz_3_n_nazad[i] = TIMEOUT_MTZ3_N_NAZAD_MIN; 
    target_label->timeout_mtz_3_po_napruzi[i] = TIMEOUT_MTZ3_PO_NAPRUZI_MIN; 

    target_label->timeout_mtz_4[i] = TIMEOUT_MTZ4_MIN; 
    target_label->timeout_mtz_4_n_vpered[i] = TIMEOUT_MTZ4_N_VPERED_MIN; 
    target_label->timeout_mtz_4_n_nazad[i] = TIMEOUT_MTZ4_N_NAZAD_MIN; 
    target_label->timeout_mtz_4_po_napruzi[i] = TIMEOUT_MTZ4_PO_NAPRUZI_MIN; 

    target_label->timeout_zdz[i] = TIMEOUT_ZDZ_MIN;    

    target_label->setpoint_zz_3I0[i] = SETPOINT_ZZ_3I0_MIN;
    target_label->setpoint_zz_3U0[i] = SETPOINT_ZZ_3U0_MIN;
    target_label->timeout_zz_3I0[i]  = TIMEOUT_ZZ_3I0_MIN; 
    target_label->timeout_zz_3U0[i]  = TIMEOUT_ZZ_3U0_MIN; 
    target_label->timeout_nzz[i]     = TIMEOUT_NZZ_MIN; 

    target_label->setpoint_tznp_1_3I0_vpered[i] = SETPOINT_TZNP1_3I0_VPERED_MIN;
    target_label->setpoint_tznp_1_3U0_vpered[i] = SETPOINT_TZNP1_3U0_VPERED_MIN;
    target_label->setpoint_tznp_1_3I0_nazad[i] = SETPOINT_TZNP1_3I0_NAZAD_MIN;
    target_label->setpoint_tznp_1_3U0_nazad[i] = SETPOINT_TZNP1_3U0_NAZAD_MIN;
    
    angle = SETPOINT_TZNP1_ANGLE_MIN;
    angle_f = (float)angle;
    target_label->setpoint_tznp_1_angle[i] = angle;
    target_label->setpoint_tznp_1_angle_cos[i] = (int) (AMPLITUDA_FI*/*cos*/arm_cos_f32(/*(double)*/(PI*angle_f/180.0f)));
    target_label->setpoint_tznp_1_angle_sin[i] = (int) (AMPLITUDA_FI*/*sin*/arm_sin_f32(/*(double)*/(PI*angle_f/180.0f)));

    target_label->setpoint_tznp_2_3I0_vpered[i] = SETPOINT_TZNP2_3I0_VPERED_MIN;
    target_label->setpoint_tznp_2_3U0_vpered[i] = SETPOINT_TZNP2_3U0_VPERED_MIN;
    target_label->setpoint_tznp_2_3I0_nazad[i] = SETPOINT_TZNP2_3I0_NAZAD_MIN;
    target_label->setpoint_tznp_2_3U0_nazad[i] = SETPOINT_TZNP2_3U0_NAZAD_MIN;
    
    angle = SETPOINT_TZNP2_ANGLE_MIN;
    angle_f = (float)angle;
    target_label->setpoint_tznp_2_angle[i] = angle;
    target_label->setpoint_tznp_2_angle_cos[i] = (int) (AMPLITUDA_FI*/*cos*/arm_cos_f32(/*(double)*/(PI*angle_f/180.0f)));
    target_label->setpoint_tznp_2_angle_sin[i] = (int) (AMPLITUDA_FI*/*sin*/arm_sin_f32(/*(double)*/(PI*angle_f/180.0f)));

    target_label->setpoint_tznp_3_3I0_vpered[i] = SETPOINT_TZNP3_3I0_VPERED_MIN;
    target_label->setpoint_tznp_3_3U0_vpered[i] = SETPOINT_TZNP3_3U0_VPERED_MIN;
    target_label->setpoint_tznp_3_3I0_nazad[i] = SETPOINT_TZNP3_3I0_NAZAD_MIN;
    target_label->setpoint_tznp_3_3U0_nazad[i] = SETPOINT_TZNP3_3U0_NAZAD_MIN;
    
    angle = SETPOINT_TZNP3_ANGLE_MIN;
    angle_f = (float)angle;
    target_label->setpoint_tznp_3_angle[i] = angle;
    target_label->setpoint_tznp_3_angle_cos[i] = (int) (AMPLITUDA_FI*/*cos*/arm_cos_f32(/*(double)*/(PI*angle_f/180.0f)));
    target_label->setpoint_tznp_3_angle_sin[i] = (int) (AMPLITUDA_FI*/*sin*/arm_sin_f32(/*(double)*/(PI*angle_f/180.0f)));

    target_label->timeout_tznp_1_vpered[i] = TIMEOUT_TZNP1_VPERED_MIN; 
    target_label->timeout_tznp_1_nazad[i] = TIMEOUT_TZNP1_NAZAD_MIN; 
    target_label->timeout_tznp_2_vpered[i] = TIMEOUT_TZNP2_VPERED_MIN; 
    target_label->timeout_tznp_2_nazad[i] = TIMEOUT_TZNP2_NAZAD_MIN; 
    target_label->timeout_tznp_3_vpered[i] = TIMEOUT_TZNP3_VPERED_MIN; 
    target_label->timeout_tznp_3_nazad[i] = TIMEOUT_TZNP3_NAZAD_MIN; 

    target_label->pickup_dzo_Io3g_Io1g [i] = PICKUP_DZO_K_3G_DIV_1G_MIN;        
          
    target_label->pickup_dzo1          [i] = PICKUP_DZO1_MIN;                 
    target_label->pickup_dzo1_amtz     [i] = PICKUP_DZO1_AMTZ_MIN;            
    target_label->pickup_dzo1_blkI     [i] = PICKUP_DZO1_BLKI_MIN; 

    angle = PICKUP_DZO2_ANGLE_MIN;
     angle_f = (float)angle;     
    target_label->pickup_dzo2_angle     [i] = angle;            
    target_label->pickup_dzo2_angle_cos1[i] = (int) (AMPLITUDA_SECTOR*/*cos*/arm_cos_f32(/*(double)*/(PI*angle_f/180.0f)));       
    target_label->pickup_dzo2_angle_sin1[i] = (int) (AMPLITUDA_SECTOR*/*sin*/arm_sin_f32(/*(double)*/(PI*angle_f/180.0f)));       
    target_label->pickup_dzo2_angle_cos2[i] = (int) (AMPLITUDA_SECTOR*/*cos*/arm_cos_f32(/*(double)*/(PI*(angle_f - DELTA_SECTOR_DZ)/180.0f)));       
    target_label->pickup_dzo2_angle_sin2[i] = (int) (AMPLITUDA_SECTOR*/*sin*/arm_sin_f32(/*(double)*/(PI*(angle_f - DELTA_SECTOR_DZ)/180.0f)));       
    target_label->pickup_dzo2_dir       [i] = PICKUP_DZO2_DIR_MIN;             
    target_label->pickup_dzo2_inv       [i] = PICKUP_DZO2_INV_MIN;             
    target_label->pickup_dzo2_amtz      [i] = PICKUP_DZO2_AMTZ_MIN;
    angle = PICKUP_DZO3_ANGLE_H_MIN;
    angle_f = (float)angle;   
    target_label->pickup_dzo3_angle_h   [i] = angle;        
    target_label->pickup_dzo3_angle_cos1_l[i] = (int) (AMPLITUDA_SECTOR*/*cos*/arm_cos_f32(/*(double)*/(PI*angle_f/180.0f)));            
    target_label->pickup_dzo3_angle_sin1_l[i] = (int) (AMPLITUDA_SECTOR*/*sin*/arm_sin_f32(/*(double)*/(PI*angle_f/180.0f)));            
    target_label->pickup_dzo3_angle_cos2_l[i] = (int) (AMPLITUDA_SECTOR*/*cos*/arm_cos_f32(/*(double)*/(PI*(angle_f - DELTA_SECTOR_DZ)/180.0f)));     
    target_label->pickup_dzo3_angle_sin2_l[i] = (int) (AMPLITUDA_SECTOR*/*sin*/arm_sin_f32(/*(double)*/(PI*(angle_f - DELTA_SECTOR_DZ)/180.0f))); 
           
    angle = PICKUP_DZO3_ANGLE_L_MIN;angle_f = (float)angle; 
    target_label->pickup_dzo3_angle_l   [i] = angle;           
    target_label->pickup_dzo3_angle_cos1_h[i] = (int) (AMPLITUDA_SECTOR*/*cos*/arm_cos_f32(/*(double)*/(PI*angle_f/180.0f)));            
    target_label->pickup_dzo3_angle_sin1_h[i] = (int) (AMPLITUDA_SECTOR*/*sin*/arm_sin_f32(/*(double)*/(PI*angle_f/180.0f)));            
    target_label->pickup_dzo3_angle_cos2_h[i] = (int) (AMPLITUDA_SECTOR*/*cos*/arm_cos_f32(/*(double)*/(PI*(angle_f - DELTA_SECTOR_DZ)/180.0f)));     
    target_label->pickup_dzo3_angle_sin2_h[i] = (int) (AMPLITUDA_SECTOR*/*sin*/arm_sin_f32(/*(double)*/(PI*(angle_f - DELTA_SECTOR_DZ)/180.0f)));     
  
    target_label->pickup_dzo3_dir [i] = PICKUP_DZO3_DIR_MIN;             
    target_label->pickup_dzo3_inv [i] = PICKUP_DZO3_INV_MIN;             
    target_label->pickup_dzo3_amtz[i] = PICKUP_DZO3_AMTZ_MIN;            
         
         
    target_label->pickup_dzo4_Zo_dir[i] = PICKUP_DZO4_Z0_DIR_MIN;          
    target_label->pickup_dzo4_Xo_dir[i] = PICKUP_DZO4_X0_DIR_MIN;          
    target_label->pickup_dzo4_Zo_inv[i] = PICKUP_DZO4_Z0_INV_MIN;          
    target_label->pickup_dzo4_Xo_inv[i] = PICKUP_DZO4_X0_INV_MIN;          
    target_label->pickup_dzo4_amtz  [i] = PICKUP_DZO4_AMTZ_MIN;            
 
    target_label->timeout_dzo1     [i]  = TIMEOUT_DZO1_MIN;                 
    target_label->timeout_dzo1_amtz[i]  = TIMEOUT_DZO1_AMTZ_MIN;            
         
    target_label->timeout_dzo2_dir         [i] = TIMEOUT_DZO2_DIR_MIN    ;             
    target_label->timeout_dzo2_dir_pr      [i] = TIMEOUT_DZO2_DIR_PR_MIN ;          
    target_label->timeout_dzo2_inv         [i] = TIMEOUT_DZO2_INV_MIN    ;             
    target_label->timeout_dzo2_inv_pr      [i] = TIMEOUT_DZO2_INV_PR_MIN ;          
    target_label->timeout_dzo2_amtz        [i] = TIMEOUT_DZO2_AMTZ_MIN   ;            
    target_label->timeout_dzo2_amtz_pr     [i] = TIMEOUT_DZO2_AMTZ_PR_MIN;         
    target_label->timeout_dzo2_vvid_pr     [i] = TIMEOUT_DZO2_VVID_PR_MIN;         
    target_label->timeout_dzo2_amtz_vvid_pr[i] = TIMEOUT_DZO2_AMTZ_VVID_PR_MIN;    
         
    target_label->timeout_dzo3_dir         [i] = TIMEOUT_DZO3_DIR_MIN    ;             
    target_label->timeout_dzo3_dir_pr      [i] = TIMEOUT_DZO3_DIR_PR_MIN ;          
    target_label->timeout_dzo3_inv         [i] = TIMEOUT_DZO3_INV_MIN    ;             
    target_label->timeout_dzo3_inv_pr      [i] = TIMEOUT_DZO3_INV_PR_MIN ;          
    target_label->timeout_dzo3_amtz        [i] = TIMEOUT_DZO3_AMTZ_MIN   ;            
    target_label->timeout_dzo3_amtz_pr     [i] = TIMEOUT_DZO3_AMTZ_PR_MIN;         
    target_label->timeout_dzo3_vvid_pr     [i] = TIMEOUT_DZO3_VVID_PR_MIN     ;         
    target_label->timeout_dzo3_amtz_vvid_pr[i] = TIMEOUT_DZO3_AMTZ_VVID_PR_MIN;    

    target_label->timeout_dzo4_dir        [i] = TIMEOUT_DZO4_DIR_MIN;             
    target_label->timeout_dzo4_inv        [i] = TIMEOUT_DZO4_INV_MIN;             
    target_label->timeout_dzo4_amtz       [i] = TIMEOUT_DZO4_AMTZ_MIN;            
  
    target_label->timeout_nkn_dzo         [i] = TIMEOUT_NKN_DZO_MIN;              
       
    target_label->pickup_dzr_Io3g_Io1g    [i] = PICKUP_DZR_K_3G_DIV_1G_MIN;        
  
    target_label->pickup_dzr1             [i] = PICKUP_DZR1_MIN;                 
    target_label->pickup_dzr1_amtz        [i] = PICKUP_DZR1_AMTZ_MIN;            
    target_label->pickup_dzr1_blkI        [i] = PICKUP_DZR1_BLKI_MIN;

    angle = PICKUP_DZR2_ANGLE_MIN;
    angle_f = (float)angle;
    target_label->pickup_dzr2_angle       [i] = angle;            
    target_label->pickup_dzr2_angle_cos1  [i] = (int) (AMPLITUDA_SECTOR*/*cos*/arm_cos_f32(/*(double)*/(PI*angle_f/180.0f)));       
    target_label->pickup_dzr2_angle_sin1  [i] = (int) (AMPLITUDA_SECTOR*/*sin*/arm_sin_f32(/*(double)*/(PI*angle_f/180.0f)));       
    target_label->pickup_dzr2_angle_cos2  [i] = (int) (AMPLITUDA_SECTOR*/*cos*/arm_cos_f32(/*(double)*/(PI*(angle_f - DELTA_SECTOR_DZ)/180.0f)));       
    target_label->pickup_dzr2_angle_sin2  [i] = (int) (AMPLITUDA_SECTOR*/*sin*/arm_sin_f32(/*(double)*/(PI*(angle_f - DELTA_SECTOR_DZ)/180.0f)));       
  
    target_label->pickup_dzr2_dir         [i] = PICKUP_DZR2_DIR_MIN;             
    target_label->pickup_dzr2_inv         [i] = PICKUP_DZR2_INV_MIN;             
    target_label->pickup_dzr2_amtz        [i] = PICKUP_DZR2_AMTZ_MIN;            
    angle = PICKUP_DZR3_ANGLE_H_MIN;
    angle_f = (float)angle;

    target_label->pickup_dzr3_angle_h     [i] = angle; 
    target_label->pickup_dzr3_angle_cos1_h[i] = (int) (AMPLITUDA_SECTOR*/*cos*/arm_cos_f32(/*(double)*/(PI*angle_f/180.0f)));;     
    target_label->pickup_dzr3_angle_sin1_h[i] = (int) (AMPLITUDA_SECTOR*/*sin*/arm_sin_f32(/*(double)*/(PI*angle_f/180.0f)));;     
    target_label->pickup_dzr3_angle_cos2_h[i] = (int) (AMPLITUDA_SECTOR*/*cos*/arm_cos_f32(/*(double)*/(PI*(angle_f - DELTA_SECTOR_DZ)/180.0f)));;     
    target_label->pickup_dzr3_angle_sin2_h[i] = (int) (AMPLITUDA_SECTOR*/*sin*/arm_sin_f32(/*(double)*/(PI*(angle_f - DELTA_SECTOR_DZ)/180.0f)));;   
    angle = PICKUP_DZR3_ANGLE_L_MIN;
    angle_f = (float)angle;
    target_label->pickup_dzr3_angle_l     [i] = angle;
    target_label->pickup_dzr3_angle_cos1_l[i] = (int) (AMPLITUDA_SECTOR*/*cos*/arm_cos_f32(/*(double)*/(PI*angle_f/180.0f)));;     
    target_label->pickup_dzr3_angle_sin1_l[i] = (int) (AMPLITUDA_SECTOR*/*sin*/arm_sin_f32(/*(double)*/(PI*angle_f/180.0f)));;     
    target_label->pickup_dzr3_angle_cos2_l[i] = (int) (AMPLITUDA_SECTOR*/*cos*/arm_cos_f32(/*(double)*/(PI*(angle_f - DELTA_SECTOR_DZ)/180.0f)));;     
    target_label->pickup_dzr3_angle_sin2_l[i] = (int) (AMPLITUDA_SECTOR*/*sin*/arm_sin_f32(/*(double)*/(PI*(angle_f - DELTA_SECTOR_DZ)/180.0f)));;     

    target_label->pickup_dzr3_dir          [i] = PICKUP_DZR3_DIR_MIN;             
    target_label->pickup_dzr3_inv          [i] = PICKUP_DZR3_INV_MIN;             
    target_label->pickup_dzr3_amtz         [i] = PICKUP_DZR3_AMTZ_MIN;            
    
    target_label->timeout_dzr1             [i] = TIMEOUT_DZR1_MIN;                 
    target_label->timeout_dzr1_amtz        [i] = TIMEOUT_DZR1_AMTZ_MIN;            

    target_label->timeout_dzr2_dir         [i] = TIMEOUT_DZR2_DIR_MIN;             
    target_label->timeout_dzr2_dir_pr      [i] = TIMEOUT_DZR2_DIR_PR_MIN;          
    target_label->timeout_dzr2_inv         [i] = TIMEOUT_DZR2_INV_MIN;             
    target_label->timeout_dzr2_inv_pr      [i] = TIMEOUT_DZR2_INV_PR_MIN;          
    target_label->timeout_dzr2_amtz        [i] = TIMEOUT_DZR2_AMTZ_MIN;            
    target_label->timeout_dzr2_amtz_pr     [i] = TIMEOUT_DZR2_AMTZ_PR_MIN;         
    target_label->timeout_dzr2_vvid_pr     [i] = TIMEOUT_DZR2_VVID_PR_MIN;         
    target_label->timeout_dzr2_amtz_vvid_pr[i] = TIMEOUT_DZR2_AMTZ_VVID_PR_MIN;    

    target_label->timeout_dzr3_dir         [i] = TIMEOUT_DZR3_DIR_MIN;             
    target_label->timeout_dzr3_dir_pr      [i] = TIMEOUT_DZR3_DIR_PR_MIN;          
    target_label->timeout_dzr3_inv         [i] = TIMEOUT_DZR3_INV_MIN;             
    target_label->timeout_dzr3_inv_pr      [i] = TIMEOUT_DZR3_INV_PR_MIN;          
    target_label->timeout_dzr3_amtz        [i] = TIMEOUT_DZR3_AMTZ_MIN;            
    target_label->timeout_dzr3_amtz_pr     [i] = TIMEOUT_DZR3_AMTZ_PR_MIN;         
    target_label->timeout_dzr3_vvid_pr     [i] = TIMEOUT_DZR3_VVID_PR_MIN;         
    target_label->timeout_dzr3_amtz_vvid_pr[i] = TIMEOUT_DZR3_AMTZ_VVID_PR_MIN;    
 
    target_label->timeout_nkn_dzr[i] = TIMEOUT_NKN_DZR_MIN;              

    target_label->setpoint_mtzo_1           [i] = SETPOINT_MTZO1_MIN;            
    target_label->setpoint_mtzo_1_n_vpered  [i] = SETPOINT_MTZO1_N_VPERED_MIN;   
    target_label->setpoint_mtzo_1_n_nazad   [i] = SETPOINT_MTZO1_N_NAZAD_MIN;
        
    angle = SETPOINT_MTZO1_ANGLE_MIN;
    angle_f = (float)angle;    
    target_label->setpoint_mtzo_1_angle     [i] = angle;      
    target_label->setpoint_mtzo_1_angle_cos [i] = (int) (AMPLITUDA_FI*/*cos*/arm_cos_f32(/*(double)*/(PI*angle_f/180.0f)));  
    target_label->setpoint_mtzo_1_angle_sin [i] = (int) (AMPLITUDA_FI*/*sin*/arm_sin_f32(/*(double)*/(PI*angle_f/180.0f)));  
  
    target_label->setpoint_mtzo_1_po_napruzi[i] = SETPOINT_MTZO1_PO_NAPRUZI_MIN; 
    target_label->setpoint_mtzo_1_U         [i] = SETPOINT_MTZO1_U_MIN;          
                                         
    target_label->setpoint_mtzo_2           [i] = SETPOINT_MTZO2_MIN;            
    target_label->setpoint_mtzo_2_n_vpered  [i] = SETPOINT_MTZO2_N_VPERED_MIN;   
    target_label->setpoint_mtzo_2_n_nazad   [i] = SETPOINT_MTZO2_N_NAZAD_MIN;
            
    angle = SETPOINT_MTZO2_ANGLE_MIN;
    angle_f = (float)angle;      
    target_label->setpoint_mtzo_2_angle     [i] = angle;      
    target_label->setpoint_mtzo_2_angle_cos [i] = (int) (AMPLITUDA_FI*/*cos*/arm_cos_f32(/*(double)*/(PI*angle_f/180.0f)));  
    target_label->setpoint_mtzo_2_angle_sin [i] = (int) (AMPLITUDA_FI*/*sin*/arm_sin_f32(/*(double)*/(PI*angle_f/180.0f)));  
  
    target_label->setpoint_mtzo_2_po_napruzi[i] = SETPOINT_MTZO2_PO_NAPRUZI_MIN; 
    target_label->setpoint_mtzo_2_U         [i] = SETPOINT_MTZO2_U_MIN;          
                                       
    target_label->setpoint_mtzo_3           [i] = SETPOINT_MTZO3_MIN;            
    target_label->setpoint_mtzo_3_n_vpered  [i] = SETPOINT_MTZO3_N_VPERED_MIN;   
    target_label->setpoint_mtzo_3_n_nazad   [i] = SETPOINT_MTZO3_N_NAZAD_MIN;
                
    angle = SETPOINT_MTZO3_ANGLE_MIN;
    angle_f = (float)angle;     
    target_label->setpoint_mtzo_3_angle     [i] = angle;       
    target_label->setpoint_mtzo_3_angle_cos[i]  = (int) (AMPLITUDA_FI*/*cos*/arm_cos_f32(/*(double)*/(PI*angle_f/180.0f)));  
    target_label->setpoint_mtzo_3_angle_sin[i]  = (int) (AMPLITUDA_FI*/*sin*/arm_sin_f32(/*(double)*/(PI*angle_f/180.0f)));  
    target_label->setpoint_mtzo_3_po_napruzi[i] = SETPOINT_MTZO3_PO_NAPRUZI_MIN; 
    target_label->setpoint_mtzo_3_U         [i] = SETPOINT_MTZO3_U_MIN;          
                                     
    target_label->setpoint_mtzo_4           [i] = SETPOINT_MTZO4_MIN;            
    target_label->setpoint_mtzo_4_n_vpered  [i] = SETPOINT_MTZO4_N_VPERED_MIN;   
    target_label->setpoint_mtzo_4_n_nazad   [i] = SETPOINT_MTZO4_N_NAZAD_MIN;
                
    angle = SETPOINT_MTZO4_ANGLE_MIN;
    angle_f = (float)angle;     
    target_label->setpoint_mtzo_4_angle     [i] = angle;       
    target_label->setpoint_mtzo_4_angle_cos [i] = (int) (AMPLITUDA_FI*/*cos*/arm_cos_f32(/*(double)*/(PI*angle_f/180.0f)));  
    target_label->setpoint_mtzo_4_angle_sin [i] = (int) (AMPLITUDA_FI*/*sin*/arm_sin_f32(/*(double)*/(PI*angle_f/180.0f)));  
    target_label->setpoint_mtzo_4_po_napruzi[i] = SETPOINT_MTZO4_PO_NAPRUZI_MIN; 
    target_label->setpoint_mtzo_4_U         [i] = SETPOINT_MTZO4_U_MIN;          

    target_label->timeout_mtzo_1              [i] = TIMEOUT_MTZO1_MIN;                      
    target_label->timeout_mtzo_1_n_vpered     [i] = TIMEOUT_MTZO1_N_VPERED_MIN;             
    target_label->timeout_mtzo_1_n_nazad      [i] = TIMEOUT_MTZO1_N_NAZAD_MIN;              
    target_label->timeout_mtzo_1_po_napruzi   [i] = TIMEOUT_MTZO1_PO_NAPRUZI_MIN;           
    target_label->timeout_mtzo_2              [i] = TIMEOUT_MTZO2_MIN;                      
    target_label->timeout_mtzo_2_pr           [i] = TIMEOUT_MTZO2_PR_MIN;                   
    target_label->timeout_mtzo_2_n_vpered     [i] = TIMEOUT_MTZO2_N_VPERED_MIN;             
    target_label->timeout_mtzo_2_n_vpered_pr  [i] = TIMEOUT_MTZO2_N_VPERED_PR_MIN;          
    target_label->timeout_mtzo_2_n_nazad      [i] = TIMEOUT_MTZO2_N_NAZAD_MIN;              
    target_label->timeout_mtzo_2_n_nazad_pr   [i] = TIMEOUT_MTZO2_N_NAZAD_PR_MIN;           
    target_label->timeout_mtzo_2_po_napruzi   [i] = TIMEOUT_MTZO2_PO_NAPRUZI_MIN;           
    target_label->timeout_mtzo_2_po_napruzi_pr[i] = TIMEOUT_MTZO2_PO_NAPRUZI_PR_MIN;        
    target_label->timeout_mtzo_2_vvid_pr      [i] = TIMEOUT_MTZO2_VVID_PR_MIN;              
    target_label->timeout_mtzo_3              [i] = TIMEOUT_MTZO3_MIN;                      
    target_label->timeout_mtzo_3_n_vpered     [i] = TIMEOUT_MTZO3_N_VPERED_MIN;             
    target_label->timeout_mtzo_3_n_nazad      [i] = TIMEOUT_MTZO3_N_NAZAD_MIN;              
    target_label->timeout_mtzo_3_po_napruzi   [i] = TIMEOUT_MTZO3_PO_NAPRUZI_MIN;           
    target_label->timeout_mtzo_4              [i] = TIMEOUT_MTZO4_MIN;                      
    target_label->timeout_mtzo_4_n_vpered     [i] = TIMEOUT_MTZO4_N_VPERED_MIN;             
    target_label->timeout_mtzo_4_n_nazad      [i] = TIMEOUT_MTZO4_N_NAZAD_MIN;              
    target_label->timeout_mtzo_4_po_napruzi   [i] = TIMEOUT_MTZO4_PO_NAPRUZI_MIN;           
    target_label->setpoint_mtzr_1           [i] = SETPOINT_MTZR1_MIN;            
    target_label->setpoint_mtzr_1_n_vpered  [i] = SETPOINT_MTZR1_N_VPERED_MIN;   
    target_label->setpoint_mtzr_1_n_nazad   [i] = SETPOINT_MTZR1_N_NAZAD_MIN;    
    angle = SETPOINT_MTZR1_ANGLE_MIN;
    angle_f = (float)angle;
    target_label->setpoint_mtzr_1_angle     [i] = angle;      
    target_label->setpoint_mtzr_1_angle_cos [i] =  (int) (AMPLITUDA_FI*/*cos*/arm_cos_f32(/*(double)*/(PI*angle_f/180.0f)));  
    target_label->setpoint_mtzr_1_angle_sin [i] =  (int) (AMPLITUDA_FI*/*sin*/arm_sin_f32(/*(double)*/(PI*angle_f/180.0f)));  
    target_label->setpoint_mtzr_1_po_napruzi[i] = SETPOINT_MTZR1_PO_NAPRUZI_MIN; 
    target_label->setpoint_mtzr_1_U         [i] = SETPOINT_MTZR1_U_MIN;          
           ;                                                
    target_label->setpoint_mtzr_2           [i] = SETPOINT_MTZR2_MIN;            
    target_label->setpoint_mtzr_2_n_vpered  [i] = SETPOINT_MTZR2_N_VPERED_MIN;   
    target_label->setpoint_mtzr_2_n_nazad   [i] = SETPOINT_MTZR2_N_NAZAD_MIN;    
    angle = SETPOINT_MTZR2_ANGLE_MIN;
    angle_f = (float)angle;
    target_label->setpoint_mtzr_2_angle     [i] = angle;      
    target_label->setpoint_mtzr_2_angle_cos [i] =  (int) (AMPLITUDA_FI*/*cos*/arm_cos_f32(/*(double)*/(PI*angle_f/180.0f)));  
    target_label->setpoint_mtzr_2_angle_sin [i] =  (int) (AMPLITUDA_FI*/*sin*/arm_sin_f32(/*(double)*/(PI*angle_f/180.0f)));  
    target_label->setpoint_mtzr_2_po_napruzi[i] = SETPOINT_MTZR2_PO_NAPRUZI_MIN; 
    target_label->setpoint_mtzr_2_U         [i] = SETPOINT_MTZR2_U_MIN;                   

    target_label->timeout_mtzr_1             [i] = TIMEOUT_MTZR1_MIN;                      
    target_label->timeout_mtzr_1_n_vpered    [i] = TIMEOUT_MTZR1_N_VPERED_MIN;             
    target_label->timeout_mtzr_1_n_nazad     [i] = TIMEOUT_MTZR1_N_NAZAD_MIN;              
    target_label->timeout_mtzr_1_po_napruzi  [i] = TIMEOUT_MTZR1_PO_NAPRUZI_MIN;           
    target_label->timeout_mtzr_2             [i] = TIMEOUT_MTZR2_MIN;                      
    target_label->timeout_mtzr_2_n_vpered    [i] = TIMEOUT_MTZR2_N_VPERED_MIN;             
    target_label->timeout_mtzr_2_n_nazad     [i] = TIMEOUT_MTZR2_N_NAZAD_MIN;              
    target_label->timeout_mtzr_2_po_napruzi  [i] = TIMEOUT_MTZR2_PO_NAPRUZI_MIN;           
  
  

 


    target_label->timeout_apv_1[i] = TIMEOUT_APV1_MIN;    
    target_label->timeout_apv_2[i] = TIMEOUT_APV2_MIN;    
    target_label->timeout_apv_3[i] = TIMEOUT_APV3_MIN;    
    target_label->timeout_apv_4[i] = TIMEOUT_APV4_MIN;    
    target_label->timeout_apv_block_vid_apv1[i] = TIMEOUT_APV_BLOCK_VID_APV1_MIN;
    target_label->timeout_apv_block_vid_apv2[i] = TIMEOUT_APV_BLOCK_VID_APV2_MIN;
    target_label->timeout_apv_block_vid_apv3[i] = TIMEOUT_APV_BLOCK_VID_APV3_MIN;
    target_label->timeout_apv_block_vid_apv4[i] = TIMEOUT_APV_BLOCK_VID_APV4_MIN;
    target_label->timeout_apv_block_vid_VV[i] = TIMEOUT_APV_BLOCK_VID_VV_MIN;
    
    target_label->setpoint_achr_chapv_uf[i] = SETPOINT_ACHR_CHAPV_UF_MIN;
    target_label->setpoint_achr1_f_rab[i]  = SETPOINT_ACHR1_F_RAB_MIN;
    target_label->setpoint_chapv1_f_rab[i] = MAIN_FREQUENCY*100 - 30;
    target_label->setpoint_achr2_f_rab[i]  = SETPOINT_ACHR2_F_RAB_MIN;
    target_label->setpoint_chapv2_f_rab[i] = MAIN_FREQUENCY*100 - 30;
    
    target_label->timeout_achr_1[i] = TIMEOUT_ACHR1_MIN;
    target_label->timeout_chapv_1[i] = TIMEOUT_CHAPV1_MIN;
    target_label->timeout_achr_2[i] = TIMEOUT_ACHR2_MIN;
    target_label->timeout_chapv_2[i] = TIMEOUT_CHAPV2_MIN;
    
    target_label->setpoint_urov[i]  = SETPOINT_UROV_MIN;
    target_label->timeout_urov_1[i] = TIMEOUT_UROV1_MIN;
    target_label->timeout_urov_2[i] = TIMEOUT_UROV2_MIN;

    target_label->setpoint_zop[i] = SETPOINT_ZOP_MIN;
    target_label->timeout_zop[i] = TIMEOUT_ZOP_MIN; 

    target_label->setpoint_Umin1[i] = SETPOINT_UMIN1_MIN;
    target_label->setpoint_Umin1_Iblk[i] = SETPOINT_UMIN1_IBLK_MIN;
    target_label->setpoint_Umin2[i] = SETPOINT_UMIN2_MIN;
    target_label->setpoint_Umin2_Iblk[i] = SETPOINT_UMIN2_IBLK_MIN;
    target_label->timeout_Umin1[i] = TIMEOUT_UMIN1_MIN; 
    target_label->timeout_Umin2[i] = TIMEOUT_UMIN2_MIN;
    
    target_label->setpoint_Umax1[i] = SETPOINT_UMAX1_MIN;
    target_label->setpoint_Umax2[i] = SETPOINT_UMAX2_MIN;
    target_label->setpoint_kp_Umax[i] = SETPOINT_KP_UMAX_DEFAULT;
    target_label->timeout_Umax1[i] = TIMEOUT_UMAX1_MIN;
    target_label->timeout_Umax2[i] = TIMEOUT_UMAX2_MIN;
    
    for (size_t j = 0; j < NUMBER_UP; j++ )
    {
      def_pickup_timeout_UP(target_label, j, i);
    }
  }

  target_label->setpoint_Inom = SETPOINT_Inom_MIN;
  target_label->setpoint_r_kom_st_Inom = SETPOINT_RKS_Inom_MIN;
  target_label->setpoint_Inom_vymk = SETPOINT_Inom_vymk_MIN;
  target_label->setpoint_r_kom_st_Inom_vymk = SETPOINT_RKS_Inom_vymk_MIN;
  
  unsigned int chastka = target_label->setpoint_r_kom_st_Inom/target_label->setpoint_r_kom_st_Inom_vymk;
  target_label->setpoint_pochatkovyj_resurs = 2*chastka;
  target_label->setpoint_krytychnyj_resurs = chastka;
  target_label->setpoint_pochatkova_k_vymk = 0;
  
  target_label->timeout_swch_on = TIMEOUT_SWCH_ON_MIN;
  target_label->timeout_swch_off = TIMEOUT_SWCH_OFF_MIN;
  target_label->timeout_swch_udl_blk_on = TIMEOUT_SWCH_UDL_BLK_ON_MIN;
  target_label->timeout_pryvoda_VV = TIMEOUT_PRYVODA_VV_MIN;
  target_label->control_switch = 0;
  
  target_label->timeout_swch_on_[0]         = TIMEOUT_SWCH_ON_MIN;

  target_label->timeout_swch_off_[0]        = TIMEOUT_SWCH_OFF_MIN;
  target_label->timeout_swch_udl_blk_on_[0] = TIMEOUT_SWCH_UDL_BLK_ON_MIN;
  target_label->timeout_pryvoda_VV_[0]      = TIMEOUT_PRYVODA_VV_MIN;
  target_label-> control_switch_[0]         = 0;
  target_label->timeout_swch_on_[1]         = TIMEOUT_SWCH_ON_MIN;
  target_label->timeout_swch_off_[1]        = TIMEOUT_SWCH_OFF_MIN;
  target_label->timeout_swch_udl_blk_on_[1] = TIMEOUT_SWCH_UDL_BLK_ON_MIN;
  target_label->timeout_pryvoda_VV_[1]      = TIMEOUT_PRYVODA_VV_MIN;
  target_label-> control_switch_[1]         = 0;
  
  
  for (unsigned int i = 0; i < 2; i++)
  {
    if (i == 0) target_label->lines[0] = NUMBER_LINES_FORWARD_MIN;
    else target_label->lines[i] = NUMBER_LINES_BACKWARD_MIN;
    
    for (unsigned int j = 0; j < MAX_NUMBER_LINES_VMP; j++)
    {
      target_label->dovgyna[i][j] = SETPOINT_DOVGYNA_VMP_MIN;
      target_label->opir[i][j]    = SETPOINT_OPIR_VMP_MIN;
    }
  }
  target_label->control_vmp = 0;
  
  target_label->prefault_number_periods = TIMEOUT_PREFAULT_MIN / 20;
  target_label->postfault_number_periods = TIMEOUT_POSTFAULT_MIN / 20;
	target_label->control_ar = 0;
  
  target_label->timeout_prolongation_work_digital_registrator = TIMEOUT_DR_ELONGATION_MIN;

  target_label->password1 = 0;
  target_label->password2 = 1234;
  target_label->password3 = 4321;
  target_label->timeout_deactivation_password_interface_USB = TIMEOUT_DEACTIVATION_PASSWORD_MIN;
  target_label->password_interface_USB = 0;
  target_label->timeout_deactivation_password_interface_RS485 = TIMEOUT_DEACTIVATION_PASSWORD_MIN;
  target_label->password_interface_RS485 = 0;
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
  target_label->timeout_deactivation_password_interface_LAN = TIMEOUT_DEACTIVATION_PASSWORD_MIN;
  target_label->password_interface_LAN = 0;
#endif
  
  target_label->timeout_idle_new_settings = TIMEOUT_NEW_SETTINGS_MIN;
  
  target_label->Tbp      = 1;//KOEF_TO_MIN;
  target_label->Tmn      = 1;//KOEF_TT_MIN;
  target_label->TVoltage = 1;//KOEF_TN_MIN;
  target_label->control_transformator = MASKA_FOR_BIT(INDEX_ML_CTR_TRANSFORMATOR_PHASE_LINE);

  for(unsigned int i=0; i< ((M_ADDRESS_LAST_USER_REGISTER_DATA - M_ADDRESS_FIRST_USER_REGISTER_DATA) + 1); i++) target_label->user_register[i] = 0;

  for(unsigned int i=0; i<MAX_CHAR_IN_NAME_OF_CELL; i++) target_label->name_of_cell[i] = ' ';
  target_label->name_of_cell[4 ] = '�';
  target_label->name_of_cell[5 ] = '�';
  target_label->name_of_cell[6 ] = '�';
  target_label->name_of_cell[8 ] = '�';
  target_label->name_of_cell[9 ] = '�';
  target_label->name_of_cell[10] = '�';
  target_label->name_of_cell[11] = '�';
  target_label->name_of_cell[12] = '�';
  
  target_label->address = KOEF_ADDRESS_MIN;
  target_label->speed_RS485 = VALUE_SPEED_INTERFACE_MIN;
  target_label->pare_bit_RS485 = VALUE_PARE_INTERFACE_MAX; //������ ���������� �������� ������� �� ���� � EVEN - � �� ����� ������� VALUE_PARE_INTERFACE_MAX
  target_label->number_stop_bit_RS485 = VALUE_STOP_BITS_INTERFACE_MIN;
  target_label->time_out_1_RS485 = VALUE_TIME_OUT_1_INTERFACE_MIN;
  
  target_label->language = LANGUAGE_EN;
  
  target_label->control_extra_settings_1 = 0;
  
  target_label->time_zone = 2;
  target_label->dst = MASKA_FOR_BIT(N_BIT_TZ_DST);
  target_label->dst_on_rule = (_Mar << POS_MM) | (_NL << POS_WR) | (_Sun << POS_DOW) | (3 << POS_HH);
  target_label->dst_off_rule = (_Oct << POS_MM) | (_NL << POS_WR) | (_Sun << POS_DOW) | (3 << POS_HH);

#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
  
  target_label->IP4[0] = 192;
  target_label->IP4[1] = 168;
  target_label->IP4[2] = 0;
  target_label->IP4[3] = 11;

  target_label->mask = NETWORK_MASK_DEFAULT;

  target_label->gateway[0] = 0;
  target_label->gateway[1] = 0;
  target_label->gateway[2] = 0;
  target_label->gateway[3] = 0;

  target_label->IP_time_server[0] = 192;
  target_label->IP_time_server[1] = 168;
  target_label->IP_time_server[2] = 100;
  target_label->IP_time_server[3] = 10;
  
  target_label->port_time_server = 123;

  target_label->period_sync = 300;
    
#endif  

  target_label->time_setpoints = target_label->time_ranguvannja = 0;
  target_label->source_setpoints = target_label->source_ranguvannja = 0;

}
/**************************************/

/**************************************/
//�������� ����������� ��� ��, �� ��������� �� ������ ������
/**************************************/
void error_reading_with_eeprom()
{
  static unsigned char const string_info[MAX_NAMBER_LANGUAGE][4][MAX_COL_LCD] = 
  {
    {
      "  �������� ���  ",
      " ��.�.�.�����.  ",
      " ��.������� ��� ",
      "  ��.��.������� "
    },
    {
      "����������� ����",
      " ���.�.�.�����. ",
      " ��.������� ����",
      " ���.��.������� "
    },
    {
      "Param are absent",
      "Error Param chks",
      " No Nvol LS Inf ",
      " Nvol LS Inf Er "
    },
    {
      "  �������� ���  ",
      " ��.�.�.�����.  ",
      " ��.������� ��� ",
      "  ��.��.������� "
    } 
  };
  static unsigned char const string_action[MAX_NAMBER_LANGUAGE][2][MAX_COL_LCD] =
  {
    {
      "���.�����.:Enter",
      " ��������: Enter"
    },
    {
      "̳�.�����.:Enter",
      " �������: Enter "
    },
    {
      "Min.param :Enter",
      "  Reset: Enter  "
    },
    {
      "���.�����.:Enter",
      " ��������: Enter"
    }
  };
  
  int index_language;
  if ((state_spi1_task & STATE_SETTINGS_EEPROM_GOOD) == 0) index_language = index_language_in_array(LANGUAGE_ABSENT);
  else index_language = index_language_in_array(current_settings.language);

  if (
      ((state_spi1_task & (STATE_SETTINGS_EEPROM_EMPTY | STATE_SETTINGS_EEPROM_FAIL) ) != 0) ||
      ((state_spi1_task & (STATE_TRG_FUNC_EEPROM_EMPTY | STATE_TRG_FUNC_EEPROM_FAIL) ) != 0)
     )   
  {
    //������ � watchdogs
   watchdog_routine(WATCHDOG_KYYBOARD);
    
    unsigned int index_info = 0, index_action = 0, information_type = 0;
    if((state_spi1_task & STATE_SETTINGS_EEPROM_EMPTY) != 0)
    {
      index_info = 0;
      index_action = 0;
      information_type = 1;
    }
    else if((state_spi1_task & STATE_SETTINGS_EEPROM_FAIL) != 0)
    {
      index_info = 1;
      index_action = 0;
      information_type = 1;
    }
    else if((state_spi1_task & STATE_TRG_FUNC_EEPROM_EMPTY) != 0)
    {
      index_info = 2;
      index_action = 1;
      information_type = 2;
    }
    else if((state_spi1_task & STATE_TRG_FUNC_EEPROM_FAIL) != 0)
    {
      index_info = 3;
      index_action = 1;
      information_type = 2;
    }
    else
    {
      //���������� ����� ����� �� ���� � ����
      total_error_sw_fixed();
    }

    //�������  ����� � ������� �����
    for (unsigned int i=0; i< MAX_ROW_LCD; i++)
    {
      for (unsigned int j = 0; j<MAX_COL_LCD; j++) 
      {
        if (i == 0) working_ekran[i][j] = string_info[index_language][index_info][j];
        else if (i == 1) working_ekran[i][j] = string_action[index_language][index_action][j];
        else working_ekran[i][j] = ' ';
      }
    }
  
    //�������� ������� ���� �����
    current_ekran.current_action = ACTION_WITH_CARRENT_EKRANE_FULL_UPDATE;

    //���������� ���������� �� �����
    view_whole_ekran();
    
    //������ ���� �� ���� ��������� ������ ENTER
    while ((new_state_keyboard & (1<<BIT_KEY_ENTER)) ==0)
    {
      //������ � watchdogs
      watchdog_routine(WATCHDOG_KYYBOARD);
    }

    new_state_keyboard = 0;
    
    if (information_type == 1)
    {
      //�������, �� ������� ����� ���� �������� � �� ����� ���� � ������� ������� ��������� � ������� � ���� ������ ������� �������
      changed_settings = CHANGED_ETAP_EXECUTION;
      //���������� �������� ������������
      min_settings(&current_settings);
      current_settings_interfaces = current_settings;
      
      //�������� �������� ������������
      _SET_BIT(control_spi1_taskes, TASK_START_WRITE_SETTINGS_EEPROM_BIT);

      //�������, �� ������� �������� � �� ����� ���� � ������� ������� ��������� � ������� � ���� ������ ������� �������
      changed_settings = CHANGED_ETAP_ENDED;
    }
    else if (information_type == 2)
    {
      fix_active_buttons = 0;
      for (unsigned int i = 0; i < N_BIG; i++) trigger_active_functions[i] = 0x0;

      //�������� ������� ������� ����������
      _SET_BIT(control_spi1_taskes, TASK_START_WRITE_TRG_FUNC_EEPROM_BIT);
    }
    
    //������ ���������� ������
    while(
          (control_spi1_taskes[0]     != 0) ||
          (control_spi1_taskes[1]     != 0) ||
          (state_execution_spi1 > 0)
         )
    {
      //������ � watchdogs
      watchdog_routine(WATCHDOG_KYYBOARD);

      main_routines_for_spi1();
      changing_diagnostyka_state();//ϳ����������� ����� ���������� �������� ����� ��� ���������� ���������� ����
      //������� �� ����� ����������� ������� �� ���������, �� �� �������� ����� ������ ���
    }

    if (information_type == 1)
    {
      //��������� ������� ������������
      comparison_writing &= (unsigned int)(~COMPARISON_WRITING_SETTINGS);/*����������, � �� ���������*/
      _SET_BIT(control_spi1_taskes, TASK_START_READ_SETTINGS_EEPROM_BIT);
    }
    else if (information_type == 2)
    {
      //��������� ������� ������� ����������
      comparison_writing &= (unsigned int)(~COMPARISON_WRITING_TRG_FUNC);/*����������, � �� ���������*/
      _SET_BIT(control_spi1_taskes, TASK_START_READ_TRG_FUNC_EEPROM_BIT);
    }

    //������ ���������� �������
    while(
          (control_spi1_taskes[0]     != 0) ||
          (control_spi1_taskes[1]     != 0) ||
          (state_execution_spi1 > 0)
         )
    {
      //������ � watchdogs
      watchdog_routine(WATCHDOG_KYYBOARD);
      
      main_routines_for_spi1();
      changing_diagnostyka_state();//ϳ����������� ����� ���������� �������� ����� ��� ���������� ���������� ����
      //������� �� ����� ����������� ������� �� ���������, �� �� �������� ����� ������ ���
    }
  }
}  
/**************************************/

/**************************************/
//�������� �������� (� ��� ����������� ������������� �� ������ ���������) DataFlash
/**************************************/
void start_checking_dataflash(void)
{
  //������ ������� ��������� 1
  unsigned char page_size_256, page_size_256_total = 1;
  unsigned int ready_busy;
  number_chip_dataflsh_exchange = INDEX_DATAFLASH_1;
  
  for (unsigned int i = 0; i < NUMBER_DATAFLASH_CHIP; i++)
  {
    page_size_256 = 1;
    dataflash_status_read(number_chip_dataflsh_exchange);
    while (driver_spi_df[number_chip_dataflsh_exchange].state_execution != TRANSACTION_EXECUTED_WAIT_ANALIZE)
    {
      if (driver_spi_df[number_chip_dataflsh_exchange].state_execution == TRANSACTION_EXECUTING_NONE)
      {
        /*
        �� �������� ����� ��������� ����� � ������ ������� - ���� � ������ ������/��������
        ���������� ���� ������� � SPI_EDF, ���� �������� �������� ������ ������� ������� �������
        */
        dataflash_status_read(number_chip_dataflsh_exchange);
      }
      
      //������ � watchdogs
      watchdog_routine(WATCHDOG_KYYBOARD);
    }
    page_size_256 &= RxBuffer_SPI_EDF[1] & (1<< 0); 
    ready_busy = RxBuffer_SPI_EDF[1] & (1<< 7);
    driver_spi_df[number_chip_dataflsh_exchange].state_execution = TRANSACTION_EXECUTING_NONE;
    driver_spi_df[number_chip_dataflsh_exchange].code_operation = CODE_OPERATION_NONE;
    if (page_size_256 == 0)
    {
      //����� ������ ������� �� ������ ��������� � ������� ������� 256 ����
      
      //����������, �� ��������� ����� � ������ �� ��� Ready/Busy
      while (ready_busy == 0)/*������ ��� �� ready/busy ������ � ���������� �������� ������� ������� �������*/
      {
        dataflash_status_read(number_chip_dataflsh_exchange);
        while (driver_spi_df[number_chip_dataflsh_exchange].state_execution != TRANSACTION_EXECUTED_WAIT_ANALIZE)
        {
          if (driver_spi_df[number_chip_dataflsh_exchange].state_execution == TRANSACTION_EXECUTING_NONE)
          {
            /*
            �� �������� ����� ��������� ����� � ������ ������� - ���� � ������ ������/��������
            ���������� ���� ������� � SPI_EDF, ���� �������� �������� ������ ������� ������� �������
            */
            dataflash_status_read(number_chip_dataflsh_exchange);
          }
          
          //������ � watchdogs
          watchdog_routine(WATCHDOG_KYYBOARD);
        }
        ready_busy = RxBuffer_SPI_EDF[1] & (1<< 7);
        driver_spi_df[number_chip_dataflsh_exchange].state_execution = TRANSACTION_EXECUTING_NONE;
        driver_spi_df[number_chip_dataflsh_exchange].code_operation = CODE_OPERATION_NONE;
      }
      
      //������ ������� �� ���������������� DataFlash
      dataflash_set_pagesize_256(number_chip_dataflsh_exchange);
      while (driver_spi_df[number_chip_dataflsh_exchange].state_execution != TRANSACTION_EXECUTED_WAIT_ANALIZE)
      {
        /*
        ��� � ������ �� ���������� ������� ����, �� ���� ��������� ���� ��������
        ����� ���� ����� ���� � �������� ������ (������� ������ ������ �� ���� �� �����), 
        ���� � ������ ������� ��������� �����, �� ���� �� �� ���������� �� ������� ������ �������
        */
        
        //������ � watchdogs
        watchdog_routine(WATCHDOG_KYYBOARD);
      }
      driver_spi_df[number_chip_dataflsh_exchange].state_execution = TRANSACTION_EXECUTING_NONE;
      driver_spi_df[number_chip_dataflsh_exchange].code_operation = CODE_OPERATION_NONE;
      
      //�������, ���� �������� ������� ���������������� ��������� ����������
      do
      {
        dataflash_status_read(number_chip_dataflsh_exchange);
        while (driver_spi_df[number_chip_dataflsh_exchange].state_execution != TRANSACTION_EXECUTED_WAIT_ANALIZE)
        {
          if (driver_spi_df[number_chip_dataflsh_exchange].state_execution == TRANSACTION_EXECUTING_NONE)
          {
            /*
            �� �������� ����� ��������� ����� � ������ ������� - ���� � ������ ������/��������
            ���������� ���� ������� � SPI_EDF, ���� �������� �������� ������ ������� ������� �������
            */
            dataflash_status_read(number_chip_dataflsh_exchange);
          }
      
          //������ � watchdogs
          watchdog_routine(WATCHDOG_KYYBOARD);
        }
        ready_busy = RxBuffer_SPI_EDF[1] & (1<< 7);
        driver_spi_df[number_chip_dataflsh_exchange].state_execution = TRANSACTION_EXECUTING_NONE;
        driver_spi_df[number_chip_dataflsh_exchange].code_operation = CODE_OPERATION_NONE;
      }
      while (ready_busy == 0);/*�� ready/busy ������ � �������� �������� ������� ������� �������, � � ���� �������� ������� ������� ��������*/
      
    }

    page_size_256_total &=  page_size_256;
    number_chip_dataflsh_exchange = (number_chip_dataflsh_exchange + 1) & (NUMBER_DATAFLASH_CHIP - 1);
  }
  
  if (error_into_spi_df != 0)
  {
    /*
    ���� ���� ����������� ������� �� ��� �������� �� ������ ������� 256 ����
    (�� ��� ������� ������� ������� ����� error_into_spi_df �� ��������������
    � ��������� ��������), �� ������ ���������� ���������� � ��������� �����������
    (� ����������, ���� ������� �) watchdog-�
    */
    while(1);
  }
  
  if (page_size_256_total == 0)
  {
    static unsigned char const name_string[MAX_NAMBER_LANGUAGE][2][MAX_COL_LCD] = 
    {
      {
        " �������������  ",
        "   ����������   "
      },
      {
        " ������������  ",
        "    �������    "
      },
      {
        "     Reset      ",
        "     Device     "
      },
      {
        " �������������  ",
        "   ����������   "
      }
    };

    int index_language = index_language_in_array(current_settings.language);
    
    //������ � watchdogs
    watchdog_routine(WATCHDOG_KYYBOARD);

    //�������  ����� � ������� �����
    for (unsigned int i=0; i< MAX_ROW_LCD; i++)
    {
      if (i < 2)
      {
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = name_string[index_language][i][j];
      }
      else
      {
        for (unsigned int j = 0; j<MAX_COL_LCD; j++) working_ekran[i][j] = ' ';
      }
    }
  
    //�������� ������� ���� �����
    current_ekran.current_action = ACTION_WITH_CARRENT_EKRANE_FULL_UPDATE;

    //���������� ���������� �� �����
    view_whole_ekran();
    
    //������, ���� ������� ���� �������������
    while(1)
    {
      //������ � watchdogs
      watchdog_routine(WATCHDOG_KYYBOARD);
    }
  }
}
/**************************************/

/**************************************/
//��������� ����� 2 ������� 4 �� ��������� ���������� ����� 1 ��
/**************************************/
void start_tim4_canal2_for_interrupt_1mc(void)
{
  TIM_OCInitTypeDef  TIM_OCInitStructure;

  /* Output Compare Timing Mode ������������: �����:2 */
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_Timing;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Disable;
  TIM_OCInitStructure.TIM_Pulse = ((uint16_t)TIM4->CNT) + TIM4_CCR2_VAL;
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
  TIM_OC2Init(TIM4, &TIM_OCInitStructure);
  
  TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Disable);

  /* ���������� ����������� �� ������ 2 ������� 4*/
  TIM_ITConfig(TIM4, TIM_IT_CC2, ENABLE);

//  //���������� ����� ��� ������� �����������
//  TIM4->CCR2 = ((uint16_t)TIM4->CNT) + TIM4_CCR2_VAL;
}
/**************************************/

/**************************************/
//��������� ����� 3 ������� 4 �� ��������� ���������� �� ����� 10 ���
/**************************************/
void start_tim4_canal3_for_interrupt_10mkc(void)
{
  TIM_OCInitTypeDef  TIM_OCInitStructure;
  
  if (number_bits_rs_485_waiting < 10) calculate_namber_bit_waiting_for_rs_485();

  /* Output Compare Timing Mode ������������: �����:2 */
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_Timing;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Disable;
  unsigned int delta = TIM4_CCR3_VAL*number_bits_rs_485_waiting;
  TIM_OCInitStructure.TIM_Pulse = ((uint16_t)TIM4->CNT) + delta;
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
  TIM_OC3Init(TIM4, &TIM_OCInitStructure);
  
  TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Disable);

  /* ���������� ����������� �� ������ 3 ������� 4*/
  TIM_ITConfig(TIM4, TIM_IT_CC3, ENABLE);
}
/**************************************/

/**************************************/
//
/**************************************/
/**************************************/
