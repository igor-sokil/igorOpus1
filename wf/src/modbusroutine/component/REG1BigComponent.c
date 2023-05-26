//��������� ������� � ����� ������
#define BEGIN_ADR_REGISTER 3010
//�������� ������� � ����� ������
#define END_ADR_REGISTER 3011

#include "header.h"

int privateREG1BigGetReg2(int adrReg);

int getREG1BigModbusRegister(int);//�������� ���������� ��������
int getREG1BigModbusBit(int);//�������� ���������� ����
int setREG1BigModbusRegister(int, int);//�������� ���������� ��������
int setREG1BigModbusBit(int, int);//�������� ���������� ����

int  postREG1BigWriteAction(void);//action ����� ������
int passwordImunitetRegREG1BigComponent(int adrReg);

SRAM1 COMPONENT_OBJ *reg1bigcomponent;

/**************************************/
//���������� ���������� REGistrator
/**************************************/
void constructorREG1BigComponent(COMPONENT_OBJ *reg1bigcomp)
{
  reg1bigcomponent = reg1bigcomp;

  reg1bigcomponent->getModbusRegister = getREG1BigModbusRegister;//�������� ���������� ��������
  reg1bigcomponent->getModbusBit      = getREG1BigModbusBit;//�������� ���������� ����
  reg1bigcomponent->setModbusRegister = setREG1BigModbusRegister;//�������� ���������� ��������
  reg1bigcomponent->setModbusBit      = setREG1BigModbusBit;//�������� ���������� ����

  reg1bigcomponent->postWriteAction = postREG1BigWriteAction;//action ����� ������
}//prepareDVinConfig

int getREG1BigModbusRegister(int adrReg)
{
  //�������� ���������� ��������
  if(privateREG1BigGetReg2(adrReg)==MARKER_OUTPERIMETR) return MARKER_OUTPERIMETR;

  int offset = adrReg-BEGIN_ADR_REGISTER;

  switch(offset)
    {
#define IMUNITET_REG0 0
    case IMUNITET_REG0://������� ���������� �����������
      if(pointInterface==USB_RECUEST)//����� ���������� 0-USB 1-RS485 2-LAN
        return (number_record_of_ar_for_USB) &0xFFFF;
      else if(pointInterface==RS485_RECUEST)
        return (number_record_of_ar_for_RS485) &0xFFFF;
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
      else if(pointInterface==LAN_RECUEST)
        return (number_record_of_ar_for_LAN) &0xFFFF;
#endif  
      //���������� ���� ����� �� ���� � �������� �����
      else total_error_sw_fixed();

#define IMUNITET_REG1 1
    case IMUNITET_REG1://������� ���������� �����������
      if(pointInterface==USB_RECUEST)//����� ���������� 0-USB 1-RS485
        return (number_record_of_dr_for_USB) &0xFFFF;
      else if(pointInterface==RS485_RECUEST)
        return (number_record_of_dr_for_RS485) &0xFFFF;
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
      else if(pointInterface==LAN_RECUEST)
        return (number_record_of_dr_for_LAN) &0xFFFF;
#endif  
      //���������� ���� ����� �� ���� � �������� �����
      else total_error_sw_fixed();
    }//switch

  return 0;
}//getDOUTBigModbusRegister(int adrReg)
int getREG1BigModbusBit(int x)
{
  //�������� ���������� ��������
  UNUSED(x);
  return MARKER_OUTPERIMETR;
}//getDOUTBigModbusRegister(int adrReg)
int setREG1BigModbusRegister(int adrReg, int dataReg)
{
  //�������� ���������� ��������
  if(privateREG1BigGetReg2(adrReg)==MARKER_OUTPERIMETR) return MARKER_OUTPERIMETR;

  superSetOperativMarker(reg1bigcomponent, adrReg);
  superSetTempWriteArray(dataReg);//�������� � �����

  int offset = adrReg-BEGIN_ADR_REGISTER;

  switch(offset)
    {

    case 0://������� ���������� �����������
      {
        if (
            ((clean_rejestrators & CLEAN_AR) != 0) ||
            (
             (state_ar_record_fatfs != STATE_AR_NONE_FATFS) &&
             (state_ar_record_fatfs != STATE_AR_MEMORY_FULL_FATFS) &&
             (state_ar_record_fatfs != STATE_AR_BLOCK_FATFS)
            )
          ) return MARKER_ERRORDIAPAZON;

        unsigned int first_number = (info_rejestrator_ar.first_number < 0) ? 0 : (info_rejestrator_ar.first_number + 1);
        unsigned int last_number  = (info_rejestrator_ar.last_number  < 0) ? 0 : (info_rejestrator_ar.last_number + 1);
                
        unsigned int number_records;
        if (first_number == 0) number_records = 0;
        else if (first_number >= last_number) number_records = first_number - last_number + 1;
        else number_records = NUMBER_FATFS_NAME - last_number + first_number + 1;
                
        if(! ((unsigned int)dataReg < number_records)) return MARKER_ERRORDIAPAZON;

      }
      break;

    case 1://������� ���������� �����������
      if (
        ((clean_rejestrators & CLEAN_DR) != 0) ||
        (
          ((pointInterface == USB_RECUEST  ) && ((control_tasks_dataflash & TASK_MAMORY_READ_DATAFLASH_FOR_DR_USB  ) != 0)) ||
          ((pointInterface == RS485_RECUEST  ) && ((control_tasks_dataflash & TASK_MAMORY_READ_DATAFLASH_FOR_DR_RS485) != 0))
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
          ||
          ((pointInterface == LAN_RECUEST  ) && ((control_tasks_dataflash & TASK_MAMORY_READ_DATAFLASH_FOR_DR_LAN) != 0))
#endif
        )
      ) return MARKER_ERRORDIAPAZON;
      if(! ((unsigned int)dataReg < info_rejestrator_dr.number_records)) return MARKER_ERRORDIAPAZON;
      if(dataReg > MAX_NUMBER_RECORDS_INTO_DR) return MARKER_ERRORDIAPAZON;
      break;

    }//switch

  return 0;
}//getDOUTBigModbusRegister(int adrReg)
int setREG1BigModbusBit(int x, int y)
{
  UNUSED(x);
  UNUSED(y);
  //�������� ���������� ��������
  return MARKER_OUTPERIMETR;
}//getDOUTBigModbusRegister(int adrReg)

int postREG1BigWriteAction(void)
{
//action ����� ������
  int beginAdr = reg1bigcomponent->operativMarker[0];
  if(beginAdr<0) return 0;//�� ���� ������
  int endAdr   = reg1bigcomponent->operativMarker[1];
  int countAdr = endAdr-beginAdr+1;
  if(endAdr<0) countAdr = 1;
  int offsetTempWriteArray = superFindTempWriteArrayOffset(BEGIN_ADR_REGISTER);//����� �������� TempWriteArray

  for(int i=0; i<countAdr; i++)
    {
      int offset = beginAdr-BEGIN_ADR_REGISTER+i;

      switch(offset)
        {
        case 0://������� ���������� �����������
        {
          int *point_to_number_record_of_ar = NULL;
          int *point_to_first_number_time_sample= NULL, *point_to_last_number_time_sample = NULL;
          char *point_id_ar_record = NULL;
          int *point_to_max_number_time_sample = NULL;
          unsigned char *point_to_Buffer = NULL;

          if (pointInterface == USB_RECUEST)
            {
              point_to_number_record_of_ar = &number_record_of_ar_for_USB;
              point_id_ar_record = id_ar_record_for_USB;
              point_to_first_number_time_sample = &first_number_time_sample_for_USB;
              point_to_last_number_time_sample = &last_number_time_sample_for_USB;
              point_to_max_number_time_sample = &max_number_time_sample_USB;
          
              point_to_Buffer = buffer_for_USB_read_record_ar;
            }
          else if (pointInterface == RS485_RECUEST)
            {
              point_to_number_record_of_ar = &number_record_of_ar_for_RS485;
              point_id_ar_record = id_ar_record_for_RS485;
              point_to_first_number_time_sample = &first_number_time_sample_for_RS485;
              point_to_last_number_time_sample = &last_number_time_sample_for_RS485;
              point_to_max_number_time_sample = &max_number_time_sample_RS485;
          
              point_to_Buffer = buffer_for_RS485_read_record_ar;
            }
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
          else if (pointInterface == LAN_RECUEST)
            {
              point_to_number_record_of_ar = &number_record_of_ar_for_LAN;
              point_id_ar_record = id_ar_record_for_LAN;
              point_to_first_number_time_sample = &first_number_time_sample_for_LAN;
              point_to_last_number_time_sample = &last_number_time_sample_for_LAN;
              point_to_max_number_time_sample = &max_number_time_sample_LAN;
          
              point_to_Buffer = buffer_for_LAN_read_record_ar;
            }
#endif
          else
            {
              //���������� ����� ����� �� ���� � ����
              total_error_sw_fixed();
            }

          unsigned short int data = tempWriteArray[offsetTempWriteArray+i];
        
          int record_name = info_rejestrator_ar.first_number - data;
          if (record_name < 0) record_name += NUMBER_FATFS_NAME;

          int n = snprintf(point_id_ar_record, (8 + 1), "%d", record_name);
          if (n > 8) n = 8; //���������� ����� ����� � �� ���� ����
          point_id_ar_record[n++] = '.';
          point_id_ar_record[n++] = 'd';
          point_id_ar_record[n++] = 'a';
          point_id_ar_record[n++] = 't';
          point_id_ar_record[n++] = '\0';
        
          unsigned int error = 0;
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
                if ((res != FR_OK) || (read_tmp != ByteToRead)) error = ERROR_SLAVE_DEVICE_FAILURE;
              }
              else error = ERROR_SLAVE_DEVICE_FAILURE;
            }
            else error = ERROR_SLAVE_DEVICE_FAILURE;

            res = f_close(&fil);
            if (res != FR_OK) 
            {
              //����������� ��������, ��� ����� � �� ���� ����.
              _SET_BIT(set_diagnostyka, ERROR_AR_UNDEFINED_BIT);
              error = ERROR_SLAVE_DEVICE_FAILURE;
            }
          }
          else error = ERROR_SLAVE_DEVICE_FAILURE;
        
          if (error == 0)
          {
            //������������ ����� ������ ����������� ���������� ��� �������
            *point_to_number_record_of_ar = data;
          }
          else
          {
            //�������, �� ���� ������� ���� ��� �������
            *point_to_number_record_of_ar = -1;
            point_id_ar_record[0] = '\0';
            return ERROR_VALID2;
          }
        }
        break;//case 35

        case 1://������� ���������� �����������

          if(pointInterface==USB_RECUEST)//����� ���������� 0-USB 1-RS485
            {
              number_record_of_dr_for_USB = tempWriteArray[offsetTempWriteArray+i];
              //������ ������� ������� ����������� ���������� ��� ���������� USB

              //����������� ����� ������� ������
              part_reading_dr_from_dataflash_for_USB = 0;
              //������ ������� ������� ��� � ����� ���'��
              control_tasks_dataflash |= TASK_MAMORY_READ_DATAFLASH_FOR_DR_USB;
            }//if
          else if(pointInterface==RS485_RECUEST)
            {
              number_record_of_dr_for_RS485 = tempWriteArray[offsetTempWriteArray+i];
              //������ ������� ������� ����������� ���������� ��� ���������� RS-485

              //����������� ����� ������� ������
              part_reading_dr_from_dataflash_for_RS485 = 0;
              //������ ������� ������� ��� � ����� ���'��
              control_tasks_dataflash |= TASK_MAMORY_READ_DATAFLASH_FOR_DR_RS485;
            }
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
          else if(pointInterface==LAN_RECUEST)
            {
              number_record_of_dr_for_LAN = tempWriteArray[offsetTempWriteArray+i];
              //������ ������� ������� ����������� ���������� ��� ���������� LAN

              //����������� ����� ������� ������
              part_reading_dr_from_dataflash_for_LAN = 0;
              //������ ������� ������� ��� � ����� ���'��
              control_tasks_dataflash |= TASK_MAMORY_READ_DATAFLASH_FOR_DR_LAN;
            }
#endif  
            else
            {
              //���������� ����� ����� �� ���� � ����
              total_error_sw_fixed();
            }

          break;
        }//switch
    }//for

  return 0;
}//

int privateREG1BigGetReg2(int adrReg)
{
  //��������� ������� ��������
  return controlPerimetr(adrReg, BEGIN_ADR_REGISTER, END_ADR_REGISTER);
}//privateGetReg2(int adrReg)

int passwordImunitetRegREG1BigComponent(int adrReg)
{
  //����������� � ������ ������ ��������� 0 - ���� ��������
  if(privateREG1BigGetReg2(adrReg)==MARKER_OUTPERIMETR) return MARKER_OUTPERIMETR;
  switch(adrReg)
  {
  case BEGIN_ADR_REGISTER+IMUNITET_REG0://������� ���������� �����������
  case BEGIN_ADR_REGISTER+IMUNITET_REG1://������� ���������� �����������
    return 0;//���� ��������
  }//switch
  return MARKER_OUTPERIMETR;
}//passwordImunitetRegREGBigComponent(int adrReg)
