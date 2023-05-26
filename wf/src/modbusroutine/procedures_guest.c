#include "header.h"

int configAnalogRegistrator(int recordNumber, int registerNumber, int recordLen);
int dataAnalogRegistrator(int recordNumber, int registerNumber, int recordLen);
int configDiskretRegistrator(int recordNumber, int registerNumber, int recordLen);
int dataDiskretRegistrator(int recordNumber, int registerNumber, int recordLen);
int recordNumberCase0Case1(int recordNumber, int registerNumber, int recordLen, int registrator);
int recordNumberCaseDiskret(int subObj, int registerNumber);
int recordNumberCaseOther(int subObj, int registerNumber, int recordLen, int registrator);

int openRegistratorRDS(void);//����������� ���������� ��������
int openRegistratorFunc20(int number_file);
int superReaderFunc20(int fileNumber, int recordNumber, int registerNumber, int recordLen);
int analogARegSource(int registerNumber, int recordLen);
int analogDRegSource(int registerNumber, int recordLen);

#define DISKRET_TOTAL TOTAL_SIGNAL_FOR_RNG_BIG
#define DISKRET_REGISTRATOR 0
#define ANALOG_REGISTRATOR  1
//����������� ��������� ������� ������������
#define REGISTERS_ACTIONREG 32

//��������������� ������ - 16 ASCII �������
//#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
//static const char idetyficator_rang[MAX_NAMBER_LANGUAGE][NUMBER_TOTAL_SIGNAL_FOR_RANG + (1 - N_IN_GOOSE)  + (1 - N_IN_MMS) + (1 - N_OUT_LAN) + (3 - NUMBER_UP_SIGNAL_FOR_RANG)][16] =
//#else
/*
static const char idetyficator_rang[MAX_NAMBER_LANGUAGE][TOTAL_SIGNAL_FOR_RNG_BIG - NUMBER_UP_SIGNAL_FOR_RANG + 3][16] =
//#endif
{
  {NAME_RANG_RU},
  {NAME_RANG_UA},
  {NAME_RANG_EN},
  {NAME_RANG_KZ}
};
*/
static const unsigned char idetyficator_rang[MAX_NAMBER_LANGUAGE][TOTAL_SIGNAL_FOR_RNG_BIG - TOTAL_UP_SIGNAL_FOR_RNG_BIG + 3][MAX_COL_LCD] = 
{
   {NAME_RANG_A01_RU},
   {NAME_RANG_A01_UA},
   {NAME_RANG_A01_EN},
   {NAME_RANG_A01_KZ},
};

/***********************************************************************************/
//������� ������ ������������ AR DR
/***********************************************************************************/
int openRegistratorFunc20(int number_file)
{
//  if(number_file==100) return openRegistratorRDS();//����������� ���������� ��������
//����� AR DR
  if (
    (
//      (number_file >= 4) &&
      ((number_file == FILENUMBER(FILEPERIF_ANLCONF1REGISTER20)) ||
       (number_file == FILENUMBER(FILEPERIF_ANLDATA1REGISTER20)) ||
       (number_file == FILENUMBER(FILEPERIF_ANLDATA2REGISTER20)) ||
       (number_file == FILENUMBER(FILEPERIF_ANLDATA3REGISTER20)) ||
       (number_file == FILENUMBER(FILEPERIF_ANLDATA4REGISTER20)) ||
       (number_file == FILENUMBER(FILEPERIF_ANLDATA5REGISTER20)) ||
       (number_file == FILENUMBER(FILEPERIF_ANLDATA6REGISTER20)) ||
       (number_file == FILENUMBER(FILEPERIF_ANLDATA7REGISTER20)) ||
       (number_file == FILENUMBER(FILEPERIF_ANLDATA8REGISTER20))
      ) &&
      (
        ((pointInterface == USB_RECUEST  ) && ((number_record_of_ar_for_USB   == -1) || (id_ar_record_for_USB[0]   == '\0'))) ||
        ((pointInterface == RS485_RECUEST) && ((number_record_of_ar_for_RS485 == -1) || (id_ar_record_for_RS485[0] == '\0')))
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
        ||
        ((pointInterface == LAN_RECUEST) && ((number_record_of_ar_for_LAN == -1) || (id_ar_record_for_LAN[0] == '\0')))
#endif
      )
    )
    ||
    (
//      (number_file >= 1) &&
//      (number_file <= 2) &&
      (number_file == FILENUMBER(FILEPERIF_DRCONF1REGISTER20)) &&
      (
        ((pointInterface == USB_RECUEST  ) && (number_record_of_dr_for_USB   == 0xffff)) ||
        ((pointInterface == RS485_RECUEST  ) && (number_record_of_dr_for_RS485 == 0xffff))
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
        ||
        ((pointInterface == LAN_RECUEST  ) && (number_record_of_dr_for_LAN == 0xffff))
#endif
      )
    )
  )
  {
    //������� ����� �����, ��� �� ������ ������� ����������� ���������� ������
    return -1;
  }
  else if (
//    (number_file >= 4) &&
    ((number_file == FILENUMBER(FILEPERIF_ANLCONF1REGISTER20)) ||
     (number_file == FILENUMBER(FILEPERIF_ANLDATA1REGISTER20)) ||
     (number_file == FILENUMBER(FILEPERIF_ANLDATA2REGISTER20)) ||
     (number_file == FILENUMBER(FILEPERIF_ANLDATA3REGISTER20)) ||
     (number_file == FILENUMBER(FILEPERIF_ANLDATA4REGISTER20)) ||
     (number_file == FILENUMBER(FILEPERIF_ANLDATA5REGISTER20)) ||
     (number_file == FILENUMBER(FILEPERIF_ANLDATA6REGISTER20)) ||
     (number_file == FILENUMBER(FILEPERIF_ANLDATA7REGISTER20)) ||
     (number_file == FILENUMBER(FILEPERIF_ANLDATA8REGISTER20))
    ) &&
    (
      (
        (state_ar_record_fatfs != STATE_AR_NONE_FATFS) &&
        (state_ar_record_fatfs != STATE_AR_MEMORY_FULL_FATFS) &&
        (state_ar_record_fatfs != STATE_AR_BLOCK_FATFS)
      )
      ||
      ((clean_rejestrators & CLEAN_AR) != 0)
      ||
      (
        (control_tasks_dataflash & (
           TASK_MAMORY_PART_PAGE_PROGRAM_THROUGH_BUFFER_DATAFLASH_FOR_FS |
           TASK_MAMORY_PAGE_PROGRAM_THROUGH_BUFFER_DATAFLASH_FOR_FS
         )
        ) != 0
      )
    )
  )
  {
    //����� ��� �������� ������/�������� ��� ���������� ����������, ��� ���� ������� ����� (������������ ����� ��������� 20 �), ���� ������� ����������� ���������� � ��������� ����������
    //error = ERROR_SLAVE_DEVICE_BUSY;
    return -2;
    /*
    ��� �� �� ���������� ����� �� ����������� �� TASK_MAMORY_READ_DATAFLASH_FOR_AR_INTERFACE,
    ��, �������, ������ � ����� � ����� ���� ����� ��������� �� �������, ��
    ��������� ������������ ���������� �� ������� �������. ����� ��������� ������� � �����, �� �����
    ���������� � ��������� dataFlash
    */
  }
  else if (
//    (number_file >= 1) &&
//    (number_file <= 2) &&
    (number_file == FILENUMBER(FILEPERIF_DRCONF1REGISTER20)) &&
    (
      (
        ((pointInterface == USB_RECUEST  ) && ((control_tasks_dataflash & TASK_MAMORY_READ_DATAFLASH_FOR_DR_USB  ) != 0)) ||
        ((pointInterface == RS485_RECUEST  ) && ((control_tasks_dataflash & TASK_MAMORY_READ_DATAFLASH_FOR_DR_RS485) != 0))
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
        ||
        ((pointInterface == LAN_RECUEST  ) && ((control_tasks_dataflash & TASK_MAMORY_READ_DATAFLASH_FOR_DR_LAN) != 0))
#endif
      )
      ||
      ((clean_rejestrators & CLEAN_DR) != 0)
    )
  )
  {
    //����� ��� ���������� ��� ���������� ������ ����������� ����������, ���� �� �������� � ��������� �����������
    //error = ERROR_SLAVE_DEVICE_BUSY;
    return -2;
  }//if

//������ DR
//  if(number_file<3)//
  if((number_file == FILENUMBER(FILEPERIF_DRCONF1REGISTER20)) ||
     (number_file == FILENUMBER(FILEPERIF_DRDATA1REGISTER20)) ||
     (number_file == FILENUMBER(FILEPERIF_DRDATA2REGISTER20))
    )
  {
    while (
      ((pointInterface == USB_RECUEST  ) && ((control_tasks_dataflash & TASK_MAMORY_READ_DATAFLASH_FOR_DR_USB  ) != 0)) ||
      ((pointInterface == RS485_RECUEST  ) && ((control_tasks_dataflash & TASK_MAMORY_READ_DATAFLASH_FOR_DR_RS485) != 0))
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
      ||
      ((pointInterface == LAN_RECUEST  ) && ((control_tasks_dataflash & TASK_MAMORY_READ_DATAFLASH_FOR_DR_LAN) != 0))
#endif
    )
    {
      //��� ������ ���� ������������� Watchdog, �� ��� ����� ���� ��������� ������� ������ � ���
      if (
        (control_spi1_taskes[0] != 0) ||
        (control_spi1_taskes[1] != 0) ||
        (state_execution_spi1 > 0)
      )
      {
        mutex_spi1 = true;
        if (driver_spi_df[number_chip_dataflsh_exchange].state_execution == TRANSACTION_EXECUTING_NONE)
        {
          main_routines_for_spi1();
        }
        mutex_spi1 = false;
      }
    }//while
  }//else

  return 0;
}//openRegistratorFunc20(int number_file)

/**************************************/
//����������� �������� 20-� �������
/**************************************/
int superReaderFunc20(int fileNumber, int recordNumber, int registerNumber, int recordLen)
{
  switch (fileNumber)
  {
  case FILENUMBER(FILEPERIF_DRCONF1REGISTER20)://������������ ����������� ������������
  {
    if(recordNumber > 9999) return MARKER_ERRORPERIMETR;
    if(registerNumber == 0) return 0;
    registerNumber--;
    recordLen--;
    if(recordNumber == 0) return MARKER_ERRORPERIMETR;
    recordNumber--;
    return configDiskretRegistrator(recordNumber, registerNumber, recordLen);
  }//case

  case FILENUMBER(FILEPERIF_DRDATA1REGISTER20)://������ ����������� ������������ 1�����
   {
    if(recordNumber > 9999) return MARKER_ERRORPERIMETR;
    if(registerNumber == 0) return 0;
    registerNumber--;
    recordLen--;
    if(recordNumber == 0) return analogDRegSource(registerNumber, recordLen);
    recordNumber += 0;
    recordNumber--;
    return dataDiskretRegistrator(recordNumber, registerNumber, recordLen);
   }//case
  case FILENUMBER(FILEPERIF_DRDATA2REGISTER20)://������ ����������� ������������ 2�����
   {
    if(recordNumber > 9999) return MARKER_ERRORPERIMETR;
    recordNumber += 10000;
    recordNumber--;
    if(registerNumber == 0) return 0;
    registerNumber--;
    recordLen--;
    return dataDiskretRegistrator(recordNumber, registerNumber, recordLen);
   }//case

  case FILENUMBER(FILEPERIF_ANLCONF1REGISTER20)://������������ ����������� ������������
   {
    if(recordNumber > 9999) return MARKER_ERRORPERIMETR;
    if(registerNumber == 0) return 0;
    registerNumber--;
    recordLen--;
    if(recordNumber == 0) return MARKER_ERRORPERIMETR;
    recordNumber--;
    return configAnalogRegistrator(recordNumber, registerNumber, recordLen);
   }//case

  case FILENUMBER(FILEPERIF_ANLDATA1REGISTER20)://������ ����������� ������������ 1�����
   {
    if(recordNumber > 9999) return MARKER_ERRORPERIMETR;
    if(registerNumber == 0) return 0;
    registerNumber--;
    recordLen--;
    if(recordNumber == 0) return analogARegSource(registerNumber, recordLen);
    recordNumber += 0;
    recordNumber--;
    return dataAnalogRegistrator(recordNumber, registerNumber, recordLen);
   }//case

  case FILENUMBER(FILEPERIF_ANLDATA2REGISTER20)://������ ����������� ������������ 2�����
   {
    if(recordNumber > 9999) return MARKER_ERRORPERIMETR;
    recordNumber += 10000;
    recordNumber--;
    if(registerNumber == 0) return 0;
    registerNumber--;
    recordLen--;
    return dataAnalogRegistrator(recordNumber, registerNumber, recordLen);
   }//case

  case FILENUMBER(FILEPERIF_ANLDATA3REGISTER20)://������ ����������� ������������ 3�����
   {
    if(recordNumber > 9999) return MARKER_ERRORPERIMETR;
    recordNumber += 20000;
    recordNumber--;
    if(registerNumber == 0) return 0;
    registerNumber--;
    recordLen--;
    return dataAnalogRegistrator(recordNumber, registerNumber, recordLen);
   }//case

  case FILENUMBER(FILEPERIF_ANLDATA4REGISTER20)://������ ����������� ������������ 4�����
   {
    if(recordNumber > 9999) return MARKER_ERRORPERIMETR;
    recordNumber += 30000;
    recordNumber--;
    if(registerNumber == 0) return 0;
    registerNumber--;
    recordLen--;
    return dataAnalogRegistrator(recordNumber, registerNumber, recordLen);
   }//case

  case FILENUMBER(FILEPERIF_ANLDATA5REGISTER20)://������ ����������� ������������ 5�����
   {
    if(recordNumber > 9999) return MARKER_ERRORPERIMETR;
    recordNumber += 40000;
    recordNumber--;
    if(registerNumber == 0) return 0;
    registerNumber--;
    recordLen--;
    return dataAnalogRegistrator(recordNumber, registerNumber, recordLen);
   }//case

  case FILENUMBER(FILEPERIF_ANLDATA6REGISTER20)://������ ����������� ������������ 6�����
   {
    if(recordNumber > 9999) return MARKER_ERRORPERIMETR;
    recordNumber += 50000;
    recordNumber--;
    if(registerNumber == 0) return 0;
    registerNumber--;
    recordLen--;
    return dataAnalogRegistrator(recordNumber, registerNumber, recordLen);
   }//case

  case FILENUMBER(FILEPERIF_ANLDATA7REGISTER20)://������ ����������� ������������ 7�����
   {
    if(recordNumber > 9999) return MARKER_ERRORPERIMETR;
    recordNumber += 60000;
    recordNumber--;
    if(registerNumber == 0) return 0;
    registerNumber--;
    recordLen--;
    return dataAnalogRegistrator(recordNumber, registerNumber, recordLen);
   }//case

  case FILENUMBER(FILEPERIF_ANLDATA8REGISTER20)://������ ����������� ������������ 8�����
   {
    if(recordNumber > 9999) return MARKER_ERRORPERIMETR;
    recordNumber += 70000;
    recordNumber--;
    if(registerNumber == 0) return 0;
    registerNumber--;
    recordLen--;
    return dataAnalogRegistrator(recordNumber, registerNumber, recordLen);
   }//case

  }//switch

  return MARKER_ERRORPERIMETR;
}//superReaderFunc20

int dataAnalogRegistrator(int recordNumber, int registerNumber, int recordLen)
{
//������ ����������� ������������
  unsigned int lenMax = (3 + AR_TOTAL_NUMBER_CANALES);
  if ((unsigned int)recordLen > lenMax) return MARKER_ERRORPERIMETR;//���� ���� ����������

  int *point_to_first_number_time_sample = NULL, *point_to_last_number_time_sample = NULL;
  char *point_id_ar_record = NULL;
  int *point_to_max_number_time_sample = NULL;
  unsigned char *point_to_Buffer = NULL;

  if (pointInterface == USB_RECUEST)
    {
      point_id_ar_record = id_ar_record_for_USB;
      point_to_first_number_time_sample = &first_number_time_sample_for_USB;
      point_to_last_number_time_sample  = &last_number_time_sample_for_USB;
      point_to_max_number_time_sample = &max_number_time_sample_USB;
          
      point_to_Buffer = buffer_for_USB_read_record_ar;
    }
  else if (pointInterface == RS485_RECUEST)
    {
      point_id_ar_record = id_ar_record_for_RS485;
      point_to_first_number_time_sample = &first_number_time_sample_for_RS485;
      point_to_last_number_time_sample  = &last_number_time_sample_for_RS485;
      point_to_max_number_time_sample = &max_number_time_sample_RS485;
          
      point_to_Buffer = buffer_for_RS485_read_record_ar;
    }
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
  else if (pointInterface == LAN_RECUEST)
    {
      point_id_ar_record = id_ar_record_for_LAN;
      point_to_first_number_time_sample = &first_number_time_sample_for_LAN;
      point_to_last_number_time_sample  = &last_number_time_sample_for_LAN;
      point_to_max_number_time_sample = &max_number_time_sample_LAN;
          
      point_to_Buffer = buffer_for_LAN_read_record_ar;
    }
#endif  
  else
  {
    //���������� ����� ����� �� ���� � ����
    total_error_sw_fixed();
  }

  if(recordNumber>*point_to_max_number_time_sample) return MARKER_ERRORPERIMETR;//���� ���� ����������

  //���������� �� ������� ��������� ����������� ����������
  if (
    (((int)recordNumber) < (*point_to_first_number_time_sample)) ||
    (((int)recordNumber) > (*point_to_last_number_time_sample ))
  )
    {
      //����������� ������� ��� �� � ��������
      FIL fil;
      FRESULT res = f_open(&fil, point_id_ar_record, FA_READ);
      if (res == FR_OK) 
      {
        //����������� ������� ��� ��������� ������ ������ ������ � ������������� ������ ���� � ������, ������ �������, ������� ���� 
        *point_to_first_number_time_sample = recordNumber;
        int last_number_time_sample_tmp = recordNumber + SIZE_PAGE_DATAFLASH_2/(AR_TOTAL_NUMBER_CANALES*sizeof(short int));
        int max_number_time_sample = *point_to_max_number_time_sample;
            
        if (last_number_time_sample_tmp <= max_number_time_sample)
        {
          *point_to_last_number_time_sample = last_number_time_sample_tmp - 1;//����� ���������� �������� ���� �������
        }
        else
        {
          *point_to_last_number_time_sample = max_number_time_sample - 1;
        }
              
        res = f_lseek(&fil, (sizeof(__HEADER_AR) + recordNumber*AR_TOTAL_NUMBER_CANALES*sizeof(short int)));
        if (res == FR_OK)
        {
          unsigned int read_tmp;
          UINT ByteToRead = ((unsigned int)(*point_to_last_number_time_sample) - recordNumber + 1)*AR_TOTAL_NUMBER_CANALES*sizeof(short int);
          res = f_read(&fil, point_to_Buffer, ByteToRead, &read_tmp);
          if ((res != FR_OK) || (read_tmp != ByteToRead)) return MARKER_ERRORPERIMETR/*�������� ������ ������ ������� ERROR_SLAVE_DEVICE_FAILURE*/;
        }
        else return MARKER_ERRORPERIMETR/*�������� ������ ������ ������� ERROR_SLAVE_DEVICE_FAILURE*/;

        res = f_close(&fil);
        if (res != FR_OK) 
        {
          //����������� ��������, ��� ����� � �� ���� ����.
          _SET_BIT(set_diagnostyka, ERROR_AR_UNDEFINED_BIT);
          return MARKER_ERRORPERIMETR/*�������� ������ ������ ������� ERROR_SLAVE_DEVICE_FAILURE*/;
        }
      }
      else return MARKER_ERRORPERIMETR/*�������� ������ ������ ������� ERROR_SLAVE_DEVICE_FAILURE*/;
    }

  //���� �� ���� �����, �� ������� �� ���������� ������� ������� � ����������� � ����� ������� ����������� ���������� ��� ����������

  //��������� ������ � ����� ������� � ����� ��������� �������� ��� ������� ���
  unsigned int index_time_sample;
  if((*point_to_first_number_time_sample) == -1)
    {
      index_time_sample = sizeof(__HEADER_AR) + recordNumber*
                          AR_TOTAL_NUMBER_CANALES*sizeof(short int);
    }
  else
    {
      index_time_sample = 0 + (recordNumber - (*point_to_first_number_time_sample))*
                          AR_TOTAL_NUMBER_CANALES*sizeof(short int);
    }

  switch(registerNumber)
    {
    case 0://���������� ����� �������
      return recordNumber + 1;
    case 1://����� ������� (ms)
      return recordNumber & 0xffff;
    case 2://����� ������� (ms)
      return recordNumber >> 16;
    }//switch

  unsigned char *point_to_buffer = NULL;
  if (pointInterface == USB_RECUEST)
    point_to_buffer = buffer_for_USB_read_record_ar;
  else if (pointInterface == RS485_RECUEST)
    point_to_buffer = buffer_for_RS485_read_record_ar;
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
  else if (pointInterface == LAN_RECUEST)
    point_to_buffer = buffer_for_LAN_read_record_ar;
#endif
  else
  {
    //���������� ����� ����� �� ���� � ����
    total_error_sw_fixed();
  }

  return (*(point_to_buffer + index_time_sample +2*(registerNumber-3))) + ((*(point_to_buffer +
         index_time_sample + 1 +2*(registerNumber-3))) << 8);
}//dataAnalogRegistrator

int configAnalogRegistrator(int recordNumber, int registerNumber, int recordLen)
{
//������������ ����������� ������������
  switch(recordNumber)
    {
    case 0://��� ������� recordNumber
    case 1://���������� ������� recordNumber
      return recordNumberCase0Case1(recordNumber, registerNumber, recordLen, ANALOG_REGISTRATOR);
    }//switch

//���������� ������
  if(recordNumber>=2 && recordNumber<=(2+AR_NUMBER_ANALOG_CANALES-1))
    {
      if(recordLen>27) return MARKER_ERRORPERIMETR;
      int subObj = recordNumber-2;//������ ������
      __HEADER_AR *header_ar_tmp = NULL;

      if (pointInterface==USB_RECUEST)//����� ���������� 0-USB 1-RS485
        header_ar_tmp = (__HEADER_AR*)buffer_for_USB_read_record_ar;
      else if (pointInterface==RS485_RECUEST)
        header_ar_tmp = (__HEADER_AR*)buffer_for_RS485_read_record_ar;
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
      else if (pointInterface == LAN_RECUEST)
        header_ar_tmp = (__HEADER_AR*)buffer_for_LAN_read_record_ar;
#endif
      else
      {
        //���������� ����� ����� �� ���� � ����
        total_error_sw_fixed();
      }

      char idetyficator[AR_NUMBER_ANALOG_CANALES][16] =
      {
        "  I_Imn         ",
        "  I_Ibp         ",
        "  I_Umn         ",
        "  I_Ubp         ",
        "  f             "
      };

      switch(registerNumber)
        {
        case 0://���������� ����� ����������� ������ 
          return 1+subObj;
        case 1://������������� ������0 
          return idetyficator[subObj][0] | (idetyficator[subObj][1]<<8);
        case 2://������������� ������1 
          return idetyficator[subObj][2] | (idetyficator[subObj][3]<<8);
        case 3://������������� ������2 
          return idetyficator[subObj][4] | (idetyficator[subObj][5]<<8);
        case 4://������������� ������3 
          return idetyficator[subObj][6] | (idetyficator[subObj][7]<<8);
        case 5://������������� ������4 
          return idetyficator[subObj][8] | (idetyficator[subObj][9]<<8);
        case 6://������������� ������5 
          return idetyficator[subObj][10] | (idetyficator[subObj][11]<<8);
        case 7://������������� ������6 
          return idetyficator[subObj][12] | (idetyficator[subObj][13]<<8);
        case 8://������������� ������7 
          return idetyficator[subObj][14] | (idetyficator[subObj][15]<<8);
        case 9://���� ������ 
        {
          //���� ������ - 2 ASCII �������
          char phase[AR_NUMBER_ANALOG_CANALES][2] =
          {
            "U0",
            "A ",
            "B ",
            "C ",
            "  "
          };
          return phase[subObj][0] | (phase[subObj][1]<<8);
        }//case 9
        case 10://����������� ��������� ����0 
        case 11://����������� ��������� ����1 
        case 12://����������� ��������� ����2 
        case 13://����������� ��������� ����3 
        case 14://����������� ��������� ����4 
        case 15://����������� ��������� ����5 
        case 16://����������� ��������� ����6 
        case 17://����������� ��������� ����7 
        {
          //������������ ������� � ��� - 16 ASCII ������� - ����� ��� �� ��������, ���� � �� ���� ������� ' '
          return ((' ')<<8) | (' ');
        }//case 10-17
        case 18://������� ��������� 
        {
          //������� ���������� - 2 ASCII �������
          if (subObj < NUMBER_ANALOG_CANALES)
          {
            unsigned int const volt = ('V'|(' '<<8));
            return volt;
          }
          else
          {
            unsigned int const Hz_string = ('H'|('z'<<8));
            return Hz_string;
          }
        }//case 18
        case 19://����������� ������ 
        {
          //���������� ������
          switch(subObj)
          {  
          case I_Imn:
          case I_Ibp:
            return (1000*MNOGNYK_I) >> (VAGA_DILENNJA_I + 4);
          case I_Umn:
          case I_Ubp:
            return (1000*MNOGNYK_U) >> (VAGA_DILENNJA_U + 4);
          case NUMBER_ANALOG_CANALES: return (10000); //��� ��� ������ �� 1000000 �������� 0,01
            
          }//switch
        }//case 19
        case 20://���������� �������� 
          //��������� �������
          return 0;
        case 21://����� ������� ������ (�s) 
          //���� � ���
          return 0; //��� ����� ������� ������� ����������
        case 22://������ ������ �������� 
          //����� �������
          return -32767;
        case 23://������� ������ �������� 
          //������ �������
          return 32767;
        case 24://��������� ����. ������. 
        {
          //��������� ���������� �������������
          switch(subObj)
          {  
          case I_Imn:
            return header_ar_tmp->TCurrent_o;
          case I_Ibp:
            return header_ar_tmp->TCurrent_r;
          case I_Umn:
          case I_Ubp:
            return header_ar_tmp->TVoltage;
          case NUMBER_ANALOG_CANALES: return 1;
          }//switch
          return 0;
        }//case 24
        case 25://��������� ����. ������. 
          //��������� ���������� �������������
          return 1;
        case 26://��������� ��� ��������� ������������� 
          //��� ������ ������������ � �������� �������
          return 'S';
        }//switch
      return MARKER_ERRORPERIMETR;
    }//if(recordNumber>=2 && recordNumber<=(2+AR_NUMBER_ANALOG_CANALES))

//���������� ������
  if(recordNumber>=((2+AR_NUMBER_ANALOG_CANALES)) && recordNumber<=(((2+AR_NUMBER_ANALOG_CANALES)) +DISKRET_TOTAL)-1)
    {
      if(recordLen>19) return MARKER_ERRORPERIMETR;
      int subObj = recordNumber-((2+AR_NUMBER_ANALOG_CANALES));//������ ������
      return recordNumberCaseDiskret(subObj, registerNumber);

    }//if(recordNumber>=(2+AR_NUMBER_ANALOG_CANALES +1) && recordNumber<=(2+AR_NUMBER_ANALOG_CANALES +1 +100))

//���������
  if(recordNumber>=(((2+AR_NUMBER_ANALOG_CANALES)) +DISKRET_TOTAL) && recordNumber<=((((2+AR_NUMBER_ANALOG_CANALES)) +DISKRET_TOTAL) +7)-1)
    {
      int subObj = recordNumber-(((2+AR_NUMBER_ANALOG_CANALES)) +DISKRET_TOTAL);//������ ������
      return recordNumberCaseOther(subObj, registerNumber, recordLen, ANALOG_REGISTRATOR);

    }//if(recordNumber>=(2+AR_NUMBER_ANALOG_CANALES +1 +DISKRET_TOTAL +1) && recordNumber<=(2+AR_NUMBER_ANALOG_CANALES +1 +DISKRET_TOTAL +1 +7))
  return MARKER_ERRORPERIMETR;
}//configAnalogRegistrator

int configDiskretRegistrator(int recordNumber, int registerNumber, int recordLen)
{
//������������ ����������� ������������
  switch(recordNumber)
    {
    case 0://��� ������� recordNumber
    case 1://���������� ������� recordNumber
      return recordNumberCase0Case1(recordNumber, registerNumber, recordLen, DISKRET_REGISTRATOR);
    }//switch

//���������� ������
  if(recordNumber>=2 && recordNumber<=(2+DISKRET_TOTAL)-1)
    {
      if(recordLen>19) return MARKER_ERRORPERIMETR;
      int subObj = recordNumber-2;//������ ������
      return recordNumberCaseDiskret(subObj, registerNumber);

    }//if(recordNumber>=2 && recordNumber<=(2+DISKRET_TOTAL)-1)

//���������
  if(recordNumber>=((2+DISKRET_TOTAL)) && recordNumber<=(((2+DISKRET_TOTAL)) +7)-1)
    {
      int subObj = recordNumber-((2+DISKRET_TOTAL));//������ ������
      return recordNumberCaseOther(subObj, registerNumber, recordLen, DISKRET_REGISTRATOR);

    }//if(recordNumber>=((2+DISKRET_TOTAL)) && recordNumber<=(((2+DISKRET_TOTAL)) +7)-1)

  return MARKER_ERRORPERIMETR;
}//configDiskretRegistrator

int recordNumberCase0Case1(int recordNumber, int registerNumber, int recordLen, int registrator)
{
  //���� �� ���� �����, �� ������� �� ��������� ����������� ���������� ��� ��������
  __HEADER_AR *header_ar_tmp = NULL;

  if (pointInterface==USB_RECUEST)//����� ���������� 0-USB 1-RS485
    header_ar_tmp = (__HEADER_AR*)buffer_for_USB_read_record_ar;
  else if (pointInterface==RS485_RECUEST)
    header_ar_tmp = (__HEADER_AR*)buffer_for_RS485_read_record_ar;
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
  else if (pointInterface == LAN_RECUEST)
        header_ar_tmp = (__HEADER_AR*)buffer_for_LAN_read_record_ar;
#endif
  else
  {
    //���������� ����� ����� �� ���� � ����
    total_error_sw_fixed();
  }
  switch(recordNumber)
    {
    case 0://��� ������� recordNumber
    {

      if(recordLen>10) return MARKER_ERRORPERIMETR;
      if(registrator==ANALOG_REGISTRATOR)
        {
          switch(registerNumber)
            {
            case 0://��� ������� 
              return header_ar_tmp->name_of_cell[ 0] | (header_ar_tmp->name_of_cell[ 1]<<8);
            case 1://��� ������� 
              return header_ar_tmp->name_of_cell[ 2] | (header_ar_tmp->name_of_cell[ 3]<<8);
            case 2://��� ������� 
              return header_ar_tmp->name_of_cell[ 4] | (header_ar_tmp->name_of_cell[ 5]<<8);
            case 3://��� ������� 
              return header_ar_tmp->name_of_cell[ 6] | (header_ar_tmp->name_of_cell[ 7]<<8);
            case 4://��� ������� 
              return header_ar_tmp->name_of_cell[ 8] | (header_ar_tmp->name_of_cell[ 9]<<8);
            case 5://��� ������� 
              return header_ar_tmp->name_of_cell[ 10] | (header_ar_tmp->name_of_cell[ 11]<<8);
            case 6://��� ������� 
              return header_ar_tmp->name_of_cell[ 12] | (header_ar_tmp->name_of_cell[ 13]<<8);
            case 7://��� ������� 
              return header_ar_tmp->name_of_cell[ 14] | (header_ar_tmp->name_of_cell[ 15]<<8);
            case 8://�������. ����� ���������� 
              //������� ����� �������� ������ ���� � ��� ����� (�������������� �� �����-�����������), ���� � ���� �� ������� ��� ������ � DataFlash � ����� ��������� ����������� ����������
              return serial_number_dev & 0xffff;
            case 9://��� �������� ��������� (1999) 
              return 1999;

            }//switch
        }//if(registrator==ANALOG_REGISTRATOR)
      else
        {
          //if(registrator==DISKRET_REGISTRATOR)
          unsigned char *point_to_buffer = NULL;
          if (pointInterface==USB_RECUEST)//����� ���������� 0-USB 1-RS485
            point_to_buffer = buffer_for_USB_read_record_dr;
          else if (pointInterface==RS485_RECUEST) point_to_buffer = buffer_for_RS485_read_record_dr;
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
          else if (pointInterface == LAN_RECUEST) point_to_buffer = buffer_for_LAN_read_record_dr;
#endif
          else
          {
            //���������� ����� ����� �� ���� � ����
            total_error_sw_fixed();
          }

          if (registerNumber < 8)
            {
              unsigned int index_cell;

              index_cell =  (registerNumber - 0)<<1;
              return (*(point_to_buffer + FIRST_INDEX_NAME_OF_CELL_DR + index_cell)) | ((*(point_to_buffer + FIRST_INDEX_NAME_OF_CELL_DR + index_cell + 1))<<8);
            }
          else if (registerNumber == 8)
            {
              //������� ����� �������� ������ ���� � ��� ����� (�������������� �� �����-�����������), ���� � ���� �� ������� ��� ������ � DataFlash � ����� ��������� ����������� ����������
              return serial_number_dev & 0xffff;
            }
          else
            {
              return 1999;
            }
        }//else if(registrator==DISKRET_REGISTRATOR)
    }//case 0
    break;

    case 1://���������� ������� recordNumber
    {
      if(recordLen>3) return MARKER_ERRORPERIMETR;
      if(registrator==ANALOG_REGISTRATOR)
        {
          switch(registerNumber)
            {
            case 0://���������� ������� ����� 
              return (unsigned)AR_NUMBER_ANALOG_CANALES + (unsigned)TOTAL_SIGNAL_FOR_RNG_BIG;
            case 1://���������� ���������� ������� 
              return AR_NUMBER_ANALOG_CANALES;
            case 2://���������� ���������� ������� 
              return TOTAL_SIGNAL_FOR_RNG_BIG;
            }//switch
          return MARKER_ERRORPERIMETR;
        }// if(registrator==ANALOG_REGISTRATOR)
      else
        {
          //if(registrator==DISKRET_REGISTRATOR)
          switch(registerNumber)
            {
            case 0://���������� ������� ����� 
              return   0 + TOTAL_SIGNAL_FOR_RNG_BIG;
            case 1://���������� ���������� ������� 
              return 0;
            case 2://���������� ���������� ������� 
              return TOTAL_SIGNAL_FOR_RNG_BIG;
            }//switch

        }//else
    }
    break;

    }//switch
  return MARKER_ERRORPERIMETR;
}//recordNumberCase0Case1

    static const uint32_t index_number_UP[MAX_NAMBER_LANGUAGE][3] = 
    {
      {11, 10, 8}, 
      {11, 10, 8}, 
      { 6,  6, 9}, 
      {11, 10, 8}
    };

int recordNumberCaseDiskret(int subObj, int registerNumber)
{
  switch(registerNumber)
    {
    case 0://���������� ����� ����������� ������ 
      return 1+subObj;
    case 1://������������� ������0 
    case 2://������������� ������1 
    case 3://������������� ������2 
    case 4://������������� ������3 
    case 5://������������� ������4 
    case 6://������������� ������5 
    case 7://������������� ������6 
    case 8://������������� ������7 
    {
//      const uint32_t index_number_UP[MAX_NAMBER_LANGUAGE][3] =
//      {
//        {11, 10, 8},
//        {11, 10, 8},
//        {12,  7, 8},
//        {11, 10, 8},
//      };
//
      int index_language = index_language_in_array(current_settings.language);

      unsigned int index_cell =  (registerNumber - 1)<<1;
      unsigned int temp_data = 0;
      for (size_t sym = 0; sym < 2; sym++)
        {
          size_t index_row;
          if (subObj < TOTAL_SIGNAL_FOR_RNG_BIG) 
          {
/*            
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
            if (subObj < (NUMBER_GENERAL_SIGNAL_FOR_RANG - (N_IN_GOOSE + N_IN_MMS + N_OUT_LAN))) 
            {
              index_row = subObj;
            }
            else if (subObj < (NUMBER_GENERAL_SIGNAL_FOR_RANG - (N_IN_MMS + N_OUT_LAN))) 
            {
              index_row = RNG_BLOCK_IN_GOOSE1 + ((subObj - (NUMBER_GENERAL_SIGNAL_FOR_RANG - (N_IN_GOOSE + N_IN_MMS + N_OUT_LAN))) % 1);
            }
            else if (subObj < (NUMBER_GENERAL_SIGNAL_FOR_RANG - (N_OUT_LAN))) 
            {
              index_row = RNG_BLOCK_IN_MMS1 + (1 - N_IN_GOOSE) + ((subObj - (NUMBER_GENERAL_SIGNAL_FOR_RANG - (N_IN_MMS + N_OUT_LAN))) % 1);
            }
            else
            {
              index_row = RNG_BLOCK_OUT_LAN1 + (1 - N_IN_GOOSE) + (1 - N_IN_MMS) + ((subObj - (NUMBER_GENERAL_SIGNAL_FOR_RANG - (N_OUT_LAN))) % 1);
            }
#else
*/
            index_row = subObj;
//#endif        
          }
          else if (subObj < RNG_BIG_BLOCK_UP1) 
          {
            index_row = subObj
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
                         + 1 - N_IN_GOOSE + 1 - N_IN_MMS + 1 - N_OUT_LAN
#endif        
                         ;
          }
          else if (subObj < (RNG_BIG_BLOCK_UP1 + TOTAL_UP_SIGNAL_FOR_RNG_BIG))
          {
            index_row = RNG_BIG_BLOCK_UP1
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
                         + 1 - N_IN_GOOSE + 1 - N_IN_MMS + 1 - N_OUT_LAN
#endif
                         + ((subObj - RNG_BIG_BLOCK_UP1) % 3);
          }
          else
          {
            index_row = subObj 
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
                        + 1 - N_IN_GOOSE + 1 - N_IN_MMS + 1 - N_OUT_LAN
#endif        
                        + 3 - TOTAL_UP_SIGNAL_FOR_RNG_BIG;
          }
/*
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
          if (
              (subObj >= (NUMBER_GENERAL_SIGNAL_FOR_RANG - (N_IN_GOOSE + N_IN_MMS + N_OUT_LAN)))  &&
              (subObj <  (NUMBER_GENERAL_SIGNAL_FOR_RANG - (N_IN_MMS + N_OUT_LAN))) &&
              ((index_cell + sym) >=  index_n_In_GOOSE[index_language][(subObj - RNG_BLOCK_IN_GOOSE1) % 1]) &&
              ((index_cell + sym) <= (index_n_In_GOOSE[index_language][(subObj - RNG_BLOCK_IN_GOOSE1) % 1] + 1)) 
             )   
          {
            unsigned int n = subObj - RNG_BLOCK_IN_GOOSE1;
            if ((n + 1) < 10)
            {
              if ((index_cell + sym) == index_n_In_GOOSE[index_language][n % 1])
                temp_data |= (0x30 + (n + 1)) << (8*sym);
              else
                temp_data |= (' ') << (8*sym);
            }
            else
            {
              if ((index_cell + sym) == index_n_In_GOOSE[index_language][n % 1])
                temp_data |= (0x30 + (n / 1 + 1) / 10) << (8*sym);
              else
                temp_data |= (0x30 + (n / 1 + 1) % 10) << (8*sym);
            }
          }
          else if (
                   (subObj >= (NUMBER_GENERAL_SIGNAL_FOR_RANG - (N_IN_MMS + N_OUT_LAN)))  &&
                   (subObj <  (NUMBER_GENERAL_SIGNAL_FOR_RANG - (N_OUT_LAN))) &&
                   ((index_cell + sym) == index_n_In_MMS[index_language][(subObj - RNG_BLOCK_IN_MMS1) % 1]) 
                  )   
          {
            temp_data |= (0x30 + ((subObj - RNG_BLOCK_IN_MMS1) / 1 + 1)) << (8*sym);
          }
          else if (
                   (subObj >= (NUMBER_GENERAL_SIGNAL_FOR_RANG - (N_OUT_LAN)))  &&
                   (subObj <  (NUMBER_GENERAL_SIGNAL_FOR_RANG)) &&
                   ((index_cell + sym) == index_n_Out_LAN[index_language][(subObj - RNG_BLOCK_OUT_LAN1) % 1]) 
                  )   
          {
            temp_data |= (0x30 + ((subObj - RNG_BLOCK_OUT_LAN1) / 1 + 1)) << (8*sym);
          }
          else 
#endif
*/            
          {
            if (
                (subObj >=  RNG_BIG_BLOCK_UP1)  &&
                (subObj <  (RNG_BIG_BLOCK_UP1 + TOTAL_UP_SIGNAL_FOR_RNG_BIG)) &&
                ((index_cell + sym) == index_number_UP[index_language][(subObj - RNG_BIG_BLOCK_UP1) % 3]) 
               )   
            {
              temp_data |= (0x30 + ((subObj - RNG_BIG_BLOCK_UP1) / 3 + 1)) << (8*sym);
            }
            else temp_data |= (idetyficator_rang[index_language][index_row][(index_cell + sym)]) << (8*sym);
          }
        }
      return temp_data;
    }//case 1-8
    case 9://���� ������ 
      //���� ������ - 2 ASCII ������� - ����� �� ��������
      return (' '<<8) | ' ';
    case 10://����������� ��������� ����0 
    case 11://����������� ��������� ����1 
    case 12://����������� ��������� ����2 
    case 13://����������� ��������� ����3 
    case 14://����������� ��������� ����4 
    case 15://����������� ��������� ����5 
    case 16://����������� ��������� ����6 
    case 17://����������� ��������� ����7 
    {
      //������������ ������� � ��� - 16 ASCII �������- ����� �� ��������
      return (' '<<8) | ' ';
    }//case 10-18
    case 18://���������� ��������� 
      //���������� ����
      return 0;
    }//switch
  return MARKER_ERRORPERIMETR;
}//recordNumberCaseDiskret

int recordNumberCaseOther(int subObj, int registerNumber, int recordLen, int registrator)
{
  int *point_to_first_number_time_sample = NULL, *point_to_last_number_time_sample = NULL;
  char *point_id_ar_record = NULL;
  int *point_to_max_number_time_sample = NULL;
  unsigned char *point_to_Buffer = NULL;
  
  __HEADER_AR *header_ar_tmp = NULL;

  if(registrator == ANALOG_REGISTRATOR)
  {
    if (pointInterface == USB_RECUEST)
    {
      point_id_ar_record = id_ar_record_for_USB;
      point_to_first_number_time_sample = &first_number_time_sample_for_USB;
      point_to_last_number_time_sample  = &last_number_time_sample_for_USB;
      point_to_max_number_time_sample = &max_number_time_sample_USB;
          
      point_to_Buffer = buffer_for_USB_read_record_ar;
    }
    else if (pointInterface == RS485_RECUEST)
    {
      point_id_ar_record = id_ar_record_for_RS485;
      point_to_first_number_time_sample = &first_number_time_sample_for_RS485;
      point_to_last_number_time_sample  = &last_number_time_sample_for_RS485;
      point_to_max_number_time_sample = &max_number_time_sample_RS485;
          
      point_to_Buffer = buffer_for_RS485_read_record_ar;
    }
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
    else if (pointInterface == LAN_RECUEST)
    {
      point_id_ar_record = id_ar_record_for_LAN;
      point_to_first_number_time_sample = &first_number_time_sample_for_LAN;
      point_to_last_number_time_sample  = &last_number_time_sample_for_LAN;
      point_to_max_number_time_sample = &max_number_time_sample_LAN;
          
      point_to_Buffer = buffer_for_LAN_read_record_ar;
    }
#endif
    else
    {
      //���������� ����� ����� �� ���� � ����
      total_error_sw_fixed();
    }
  
    //���������� �� ������� ��������� ����������� ����������
    if ((*point_to_first_number_time_sample) != -1)
    {
      //����� �� ������������ ���������� ��������� ����������� ��������
              
      FIL fil;
      FRESULT res = f_open(&fil, point_id_ar_record, FA_READ);
      if (res == FR_OK) 
      {
        res = f_lseek(&fil, 0);
        if (res == FR_OK)
        {
          //����������� ������� ��������� ������ ������ ������ � ������, ������ �������, ������� ���� 
          *point_to_first_number_time_sample = -1;
          int last_number_time_sample_tmp = (SIZE_PAGE_DATAFLASH_2 - sizeof(__HEADER_AR))/(AR_TOTAL_NUMBER_CANALES*sizeof(short int));
          int max_number_time_sample = *point_to_max_number_time_sample = (f_size(&fil) - sizeof(__HEADER_AR))/(AR_TOTAL_NUMBER_CANALES*sizeof(short int));
            
          if (max_number_time_sample >= 0)
          {
            if (last_number_time_sample_tmp <= max_number_time_sample)
            {
              *point_to_last_number_time_sample = last_number_time_sample_tmp - 1;//����� ���������� �������� ���� �������
            }
            else
            {
              *point_to_last_number_time_sample = max_number_time_sample - 1;
            }
              
            unsigned int read_tmp;
            UINT ByteToRead = sizeof(__HEADER_AR) + ((unsigned int)(*point_to_last_number_time_sample) + 1)*AR_TOTAL_NUMBER_CANALES*sizeof(short int);
            res = f_read(&fil, point_to_Buffer, ByteToRead, &read_tmp);
            if ((res != FR_OK) || (read_tmp != ByteToRead)) return MARKER_ERRORPERIMETR;
          }
          else return MARKER_ERRORPERIMETR;
        }
        else return MARKER_ERRORPERIMETR;

        res = f_close(&fil);
        if (res != FR_OK) 
        {
          //����������� ��������, ��� ����� � �� ���� ����.
          _SET_BIT(set_diagnostyka, ERROR_AR_UNDEFINED_BIT);
          return MARKER_ERRORPERIMETR;
        }
      }
      else return MARKER_ERRORPERIMETR;
    }
              
    header_ar_tmp = (__HEADER_AR*)point_to_Buffer;
  }
  else if (registrator == DISKRET_REGISTRATOR)
  {
    if (pointInterface == USB_RECUEST) //����� ���������� 0-USB 1-RS485
      point_to_Buffer = buffer_for_USB_read_record_dr;
    else if (pointInterface == RS485_RECUEST)
      point_to_Buffer = buffer_for_RS485_read_record_dr;
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
    else if (pointInterface == LAN_RECUEST) point_to_Buffer = buffer_for_LAN_read_record_dr;
#endif
    else
    {
      //���������� ����� ����� �� ���� � ����
      total_error_sw_fixed();
    }
  }
  else return MARKER_ERRORPERIMETR;
    
  switch(subObj)
    {
    case 0://������� ����� (��) subObj
      if(recordLen>1) return MARKER_ERRORPERIMETR;
      return 5000;
    case 1://���-�� ������ ������������� subObj
      if(recordLen>1) return MARKER_ERRORPERIMETR;
      if(registrator==ANALOG_REGISTRATOR) return 1;
      else return 0;
    case 2://������� �������1 (��) subObj
    {
      if(recordLen>2) return MARKER_ERRORPERIMETR;
      switch(registerNumber)
        {
        case 0://������� �������1 (��) 
          if(registrator==ANALOG_REGISTRATOR) return ((50*1000)<<VAGA_NUMBER_POINT_AR)>>4; //��c����
          return 0;
        case 1://��������� ������� �� ���� ������� 
          if(registrator==ANALOG_REGISTRATOR) return *point_to_max_number_time_sample; //������� �������
          return *(point_to_Buffer + FIRST_INDEX_NUMBER_ITEMS_DR); //������� ������� �� ���� ����� ������������� ���� �������
        }//switch

      return MARKER_ERRORPERIMETR;
    }//case 2
    case 3://���� (���� � ����� ������ ������) subObj
    case 4://���� (���� � ����� �������) subObj
    {
      if(recordLen>7) return MARKER_ERRORPERIMETR;
      switch(registerNumber)
        {
        case 0://���� (���� � ����� ������ ������) 
        case 1://����� 
        case 2://��� 
        case 3://���� 
        case 4://������ 
        case 5://������� 
        case 6://������������ 
        {
          if(registrator==ANALOG_REGISTRATOR)
            {
              if (header_ar_tmp == NULL) total_error_sw_fixed();
              
              time_t time_dat_tmp = header_ar_tmp->time_dat;
              int32_t time_ms_tmp = header_ar_tmp->time_ms;

              struct tm *p;
              int temp_data;

              int max_time_milliseconds_before = (header_ar_tmp->prefault_number_periods)*20;
              int s, ds_ms;

              if(subObj==4)  goto m1;// return time_avar_analog[registerNumber];

              //ʳ������ ������
              s = max_time_milliseconds_before / 1000;
              //ʳ������ ��������
              ds_ms = max_time_milliseconds_before - s*1000;
              
              time_ms_tmp -= ds_ms;
              time_dat_tmp -= (time_t)s;

              if (time_ms_tmp < 0) 
              {
                time_ms_tmp += 1000;
                --time_dat_tmp;
              }

m1:
              p = localtime(&time_dat_tmp);
              switch(registerNumber)
                {
                case 0:
                  {
                    temp_data = p->tm_mday;
                    break;
                  }
                case 1:
                  {
                    temp_data = p->tm_mon + 1;
                    break;
                  }
                case 2:
                  {
                    temp_data = p->tm_year + 1900;
                    break;
                  }
                case 3:
                  {
                    temp_data = p->tm_hour;
                    break;
                  }
                case 4:
                  {
                    temp_data = p->tm_min;
                    break;
                  }
                case 5:
                  {
                    temp_data = p->tm_sec*100 + time_ms_tmp/10;
                    break;
                  }
                case 6:
                  {
                    temp_data = (time_ms_tmp % 10) * 1000;
                    break;
                  }
                default:
                  temp_data = 0;
                }//switch
              return temp_data;
            }//if(registrator==ANALOG_REGISTRATOR)
          else
            {
              //if(registrator==DISKRET_REGISTRATOR)
              //���������� ������ BCD � int
              time_t time_dat_tmp = 0;
              int32_t time_ms_tmp = 0;

              for (unsigned int i = 0; i < sizeof(time_t); i++) *((unsigned char *)(&time_dat_tmp) + i) = point_to_Buffer[FIRST_INDEX_DATA_TIME_DR + i];
              for (unsigned int i = 0; i < sizeof(int32_t); i++) *((unsigned char *)(&time_ms_tmp) + i) = point_to_Buffer[FIRST_INDEX_DATA_TIME_DR + sizeof(time_t) + i];

               if(subObj==3)
               {
                //(���� � ����� ������ ������)
             //������ Diskret ������������
               unsigned char *point_to_buffer = NULL;
               if (pointInterface==USB_RECUEST)//����� ���������� 0-USB 1-RS485
                 point_to_buffer = buffer_for_USB_read_record_dr;
               else if (pointInterface==RS485_RECUEST) point_to_buffer = buffer_for_RS485_read_record_dr;
             #if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
               else if (pointInterface == LAN_RECUEST) point_to_buffer = buffer_for_LAN_read_record_dr;
             #endif
               else
               {
                 //���������� ����� ����� �� ���� � ����
                 total_error_sw_fixed();
               }
               unsigned char time_before_dr = (*(point_to_buffer + FIRST_INDEX_NUMBER_BEFORE_ITEMS_DR));// ��������� ���������� ������

                 time_ms_tmp -= (int32_t)time_before_dr;
                 if(time_ms_tmp < 0)
                 {
                   time_ms_tmp += 1000;
                   --time_dat_tmp;
                 }//if
                }//if(subObj==3)
              struct tm *p = localtime(&time_dat_tmp);
              int temp_data;
              switch(registerNumber)
                {
                case 0:
                  {
                    temp_data = p->tm_mday;
                    break;
                  }
                case 1:
                  {
                    temp_data = p->tm_mon + 1;
                    break;
                  }
                case 2:
                  {
                    temp_data = p->tm_year + 1900;
                    break;
                  }
                case 3:
                  {
                    temp_data = p->tm_hour;
                    break;
                  }
                case 4:
                  {
                    temp_data = p->tm_min;
                    break;
                  }
                case 5:
                  {
                    temp_data = p->tm_sec*100 + time_ms_tmp/10;
                    break;
                  }
                case 6:
                  {
                    temp_data = (time_ms_tmp % 10) * 1000;
                    break;
                  }
                default:
                  temp_data = 0;
                }//switch
              return temp_data;
            } //else
        }//case 0-6
        }//switch
      return MARKER_ERRORPERIMETR;
    }//case 3 4
    case 5://��� ������ subObj
      if(recordLen>1) return MARKER_ERRORPERIMETR;
      //if(registrator==DISKRET_REGISTRATOR) 
      return 'B'; //��� - �� ����� �����
      //return (1000000 >> VAGA_NUMBER_POINT_AR)/50; //����� �������������
    case 6://����������� ��������� ����� subObj
      if(recordLen>1) return MARKER_ERRORPERIMETR;
    if(registrator==DISKRET_REGISTRATOR) return 1000;
    return (1000000 >> VAGA_NUMBER_POINT_AR)/50;
    }//switch

  return MARKER_ERRORPERIMETR;
}//

int dataDiskretRegistrator(int recordNumber, int registerNumber, int recordLen)
{
//������ Diskret ������������
  unsigned char *point_to_buffer = NULL;
  if (pointInterface==USB_RECUEST)//����� ���������� 0-USB 1-RS485
    point_to_buffer = buffer_for_USB_read_record_dr;
  else if (pointInterface==RS485_RECUEST) point_to_buffer = buffer_for_RS485_read_record_dr;
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
  else if (pointInterface == LAN_RECUEST) point_to_buffer = buffer_for_LAN_read_record_dr;
#endif
  else
  {
    //���������� ����� ����� �� ���� � ����
    total_error_sw_fixed();
  }

  unsigned int max_number_two_bytes = (TOTAL_SIGNAL_FOR_RNG_BIG >> 4);
  if ((max_number_two_bytes << 4) != TOTAL_SIGNAL_FOR_RNG_BIG)  max_number_two_bytes++;

  unsigned int lenMax = (3 + max_number_two_bytes);
  if ((unsigned int)recordLen > lenMax) return MARKER_ERRORPERIMETR;//���� ���� ����������

  if(recordNumber>(*(point_to_buffer + FIRST_INDEX_NUMBER_ITEMS_DR))) return MARKER_ERRORPERIMETR;//���� ���� ����������

  int const time_before_dr = point_to_buffer[FIRST_INDEX_NUMBER_BEFORE_ITEMS_DR];// ��������� ���������� ������
  unsigned int const offset = FIRST_INDEX_FIRST_DATA_DR + (recordNumber + 1)*SD_DR; //�� ��������� ����� ������ �������� �������� (�� �������� ������� ������ ����������� ����������)

	int time_marker_dr = (int)(
														 (unsigned int)(point_to_buffer[offset + 0]      ) + 
														 (unsigned int)(point_to_buffer[offset + 1] <<  8) + 
														 (unsigned int)(point_to_buffer[offset + 2] << 16) + 
														               ((point_to_buffer[offset + 2] & 0x80) ? 0xff000000u : 0x0u) 
													  );
  time_marker_dr += time_before_dr;

  switch(registerNumber)
    {
    case 0://���������� ����� �������
      return recordNumber + 1;
    case 1://����� ������� (ms)
      return time_marker_dr&0xFFFF;//(*(point_to_buffer + offset + 0)) + ((*(point_to_buffer + offset + 1)) << 8 );
    case 2://����� ������� (ms)
      return (time_marker_dr>>16)&0xFFFF;//*(point_to_buffer + offset + 2);
    }//switch

  return (*(point_to_buffer + offset + 3 + (registerNumber - 3)*2)) + ((*(point_to_buffer + offset + 4 + (registerNumber - 3)*2)) << 8);
}//dataDiskretRegistrator

int analogDRegSource(int registerNumber, int recordLen) 
{
  if ((unsigned int)recordLen > REGISTERS_ACTIONREG) return MARKER_ERRORPERIMETR;//���� ���� ����������
   //���������� ����������
          if (
            //�� ������ ����������������� ����������� ���������� ������ ����������� ����������
            //pointInterface=0 ����� ���������� 0-USB 1-RS485
            ((pointInterface == USB_RECUEST  ) && (number_record_of_dr_for_USB == 0xffff)) ||
            ((pointInterface == RS485_RECUEST) && (number_record_of_dr_for_RS485 == 0xffff))
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
            ||
            ((pointInterface == LAN_RECUEST) && (number_record_of_dr_for_LAN == 0xffff))
#endif
          ) return MARKER_ERRORPERIMETR;
         if (
              (
               ((pointInterface == USB_RECUEST  ) && ((control_tasks_dataflash & TASK_MAMORY_READ_DATAFLASH_FOR_DR_USB  ) != 0)) ||
               ((pointInterface == RS485_RECUEST) && ((control_tasks_dataflash & TASK_MAMORY_READ_DATAFLASH_FOR_DR_RS485) != 0))
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
            ||
               ((pointInterface == LAN_RECUEST) && ((control_tasks_dataflash & TASK_MAMORY_READ_DATAFLASH_FOR_DR_LAN) != 0))
#endif
              ) 
              ||  
              ((clean_rejestrators & CLEAN_DR) != 0)
            )  
           
    {
     //����� ��� ���������� ��� ���������� ������ ����������� ����������, ���� �� �������� � ��������� �����������
      return MARKER_ERRORPERIMETR;
    }

      //����� ������ ���
      unsigned char *point_to_buffer = NULL;
      if (pointInterface == USB_RECUEST) point_to_buffer = buffer_for_USB_read_record_dr;
      else if (pointInterface == RS485_RECUEST) point_to_buffer = buffer_for_RS485_read_record_dr;
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
      else if (pointInterface == LAN_RECUEST) point_to_buffer = buffer_for_LAN_read_record_dr;
#endif
      else
      {
        //���������� ����� ����� �� ���� � ����
        total_error_sw_fixed();
      }
      
      //���� �� ���� �����, �� ������� �� ��������� ����������� ���������� ��� ��������
      //���������, �� ������� ��������� ����������
      unsigned int *activeNBIG_dr = (unsigned int*)(&point_to_buffer[FIRST_INDEX_SOURCE_DR+0]);//��������� �� N_BIG ������ �������� ������ ������� �����
//      return getRangN_BIGModbusRegister(activeNBIG_dr, REGISTERS_ACTIONREG, offset-108 );
      return getRangN_BIGModbusRegister2021(activeNBIG_dr, registerNumber);
}//analogDRegSource(int registerNumber, int recordLen) 

int analogARegSource(int registerNumber, int recordLen) 
{
//����������� ��������� ������� �������� ����������� ������������
  if ((unsigned int)recordLen > REGISTERS_ACTIONREG) return MARKER_ERRORPERIMETR;//���� ���� ����������

   //���������� ����������
   if(
      (
       !(
         ((pointInterface == USB_RECUEST  ) && ((number_record_of_ar_for_USB   != -1) && (id_ar_record_for_USB[0]   != '\0'))) ||
         ((pointInterface == RS485_RECUEST) && ((number_record_of_ar_for_RS485 != -1) && (id_ar_record_for_RS485[0] != '\0')))
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
         ||
         ((pointInterface == LAN_RECUEST) && ((number_record_of_ar_for_LAN != -1) && (id_ar_record_for_LAN[0] != '\0')))
#endif
        )               
      )
      ||
      (
       (
        (state_ar_record_fatfs != STATE_AR_NONE_FATFS) &&
        (state_ar_record_fatfs != STATE_AR_MEMORY_FULL_FATFS) &&
        (state_ar_record_fatfs != STATE_AR_BLOCK_FATFS)
       )
       ||
       ((clean_rejestrators & CLEAN_AR) != 0)  
       ||  
       (
        (control_tasks_dataflash & (
                                    TASK_MAMORY_PART_PAGE_PROGRAM_THROUGH_BUFFER_DATAFLASH_FOR_FS |
                                    TASK_MAMORY_PAGE_PROGRAM_THROUGH_BUFFER_DATAFLASH_FOR_FS
                                   )
        ) != 0
       )
      )
     )
    {
      //����� ��� �������� ������/�������� ��� ���������� ����������, ��� ���� ������� ����� (������������ ����� ��������� 20 �), ���� ������� ����������� ���������� � ��������� ����������
      return MARKER_ERRORPERIMETR;
    }

      //����� ������ ���
      int *point_to_first_number_time_sample = NULL, *point_to_last_number_time_sample = NULL;
      char *point_id_ar_record = NULL;
      int *point_to_max_number_time_sample = NULL;
      unsigned char *point_to_buffer = NULL;

      if (pointInterface == USB_RECUEST)
      {
        point_id_ar_record = id_ar_record_for_USB;
        point_to_first_number_time_sample = &first_number_time_sample_for_USB;
        point_to_last_number_time_sample  = &last_number_time_sample_for_USB;
        point_to_max_number_time_sample = &max_number_time_sample_USB;
          
        point_to_buffer = buffer_for_USB_read_record_ar;
      }
      else if (pointInterface == RS485_RECUEST)
      {
        point_id_ar_record = id_ar_record_for_RS485;
        point_to_first_number_time_sample = &first_number_time_sample_for_RS485;
        point_to_last_number_time_sample  = &last_number_time_sample_for_RS485;
        point_to_max_number_time_sample = &max_number_time_sample_RS485;
        
        point_to_buffer = buffer_for_RS485_read_record_ar;
      }
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
      else if (pointInterface == LAN_RECUEST)
      {
        point_id_ar_record = id_ar_record_for_LAN;
        point_to_first_number_time_sample = &first_number_time_sample_for_LAN;
        point_to_last_number_time_sample  = &last_number_time_sample_for_LAN;
        point_to_max_number_time_sample = &max_number_time_sample_LAN;
        
        point_to_buffer = buffer_for_LAN_read_record_ar;
      }
#endif
      else
      {
        //���������� ����� ����� �� ���� � ����
        total_error_sw_fixed();
      }

      if ((*point_to_first_number_time_sample) != -1)
      {
        //����� �� ������������ ���������� ��������� ����������� ��������
              
        FIL fil;
        FRESULT res = f_open(&fil, point_id_ar_record, FA_READ);
        if (res == FR_OK) 
        {
          res = f_lseek(&fil, 0);
          if (res == FR_OK)
          {
            //����������� ������� ��������� ������ ������ ������ � ������, ������ �������, ������� ���� 
            *point_to_first_number_time_sample = -1;
            int last_number_time_sample_tmp = (SIZE_PAGE_DATAFLASH_2 - sizeof(__HEADER_AR))/(AR_TOTAL_NUMBER_CANALES*sizeof(short int));
            int max_number_time_sample = *point_to_max_number_time_sample = (f_size(&fil) - sizeof(__HEADER_AR))/(AR_TOTAL_NUMBER_CANALES*sizeof(short int));
            
            if (max_number_time_sample >= 0)
            {
              if (last_number_time_sample_tmp <= max_number_time_sample)
              {
                *point_to_last_number_time_sample = last_number_time_sample_tmp - 1;//����� ���������� �������� ���� �������
              }
              else
              {
                *point_to_last_number_time_sample = max_number_time_sample - 1;
              }
              
              unsigned int read_tmp;
              UINT ByteToRead = sizeof(__HEADER_AR) + ((unsigned int)(*point_to_last_number_time_sample) + 1)*AR_TOTAL_NUMBER_CANALES*sizeof(short int);
              res = f_read(&fil, point_to_buffer, ByteToRead, &read_tmp);
              if ((res != FR_OK) || (read_tmp != ByteToRead)) return MARKER_ERRORPERIMETR;
            }
            else return MARKER_ERRORPERIMETR;
          }
          else return MARKER_ERRORPERIMETR;

          res = f_close(&fil);
          if (res != FR_OK) 
          {
            //����������� ��������, ��� ����� � �� ���� ����.
            _SET_BIT(set_diagnostyka, ERROR_AR_UNDEFINED_BIT);
            return MARKER_ERRORPERIMETR;
          }
        }
        else return MARKER_ERRORPERIMETR;
      }

      //���� �� ���� �����, �� ������� �� ��������� ����������� ���������� ��� ��������
      __HEADER_AR *p_header_ar = (__HEADER_AR*)point_to_buffer;
      return getRangN_BIGModbusRegister2021(p_header_ar->cur_active_sources, registerNumber);
}//analogARegSource
