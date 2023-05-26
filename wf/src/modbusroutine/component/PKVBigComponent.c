#include "header.h"

//��������� ������� � ����� ������
#define BEGIN_ADR_REGISTER 3000
//�������� ������� � ����� ������
#define END_ADR_REGISTER 3006

int privatePKVBigGetReg2(int adrReg);

int getPKVBigModbusRegister(int);//�������� ���������� ��������
int getPKVBigModbusBit(int);//�������� ���������� ����
int setPKVBigModbusRegister(int, int);//�������� ���������� ��������
int setPKVBigModbusBit(int, int);//�������� ���������� ����

int  postPKVBigWriteAction(void);//action ����� ������
int PKVFunc000(int inOffset, int regPKV, uint32_t **editValue);
int passwordImunitetRegPKVBigComponent(int x);

SRAM1 COMPONENT_OBJ *pkvbigcomponent;
int PKVFunc000(int inOffset, int regPKV, uint32_t **editValue)
{
  UNUSED(regPKV);
  int diapazon = 1;

  switch(inOffset)
  {
#define IMUNITET_PKV1 6
  case IMUNITET_PKV1://��������/��������� ������
    switch(pointInterface)//����� ���������� 0-USB 1-RS485
    {
     case USB_RECUEST:
      (*editValue) = &edition_settings.password_interface_USB;
     break;
     case RS485_RECUEST:
      (*editValue) = &edition_settings.password_interface_RS485;
     break;
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
     case LAN_RECUEST:
      (*editValue) = &edition_settings.password_interface_LAN;
     break;
#endif
    }//switch
    break;
  }//switch

  return diapazon;
} //PKVFunc000(int inOffset, int regPKV, uint32_t **editValue)

/**************************************/
//���������� ���������� PKV
/**************************************/
void constructorPKVBigComponent(COMPONENT_OBJ *pkvbigcomp)
{
  pkvbigcomponent = pkvbigcomp;

  pkvbigcomponent->getModbusRegister = getPKVBigModbusRegister;//�������� ���������� ��������
  pkvbigcomponent->getModbusBit      = getPKVBigModbusBit;//�������� ���������� ����
  pkvbigcomponent->setModbusRegister = setPKVBigModbusRegister;//�������� ���������� ��������
  pkvbigcomponent->setModbusBit      = setPKVBigModbusBit;//�������� ���������� ����

  pkvbigcomponent->postWriteAction = postPKVBigWriteAction;//action ����� ������
}//prepareDVinConfig

int getPKVBigModbusRegister(int adrReg)
{
  //�������� ���������� ��������
  if(privatePKVBigGetReg2(adrReg)==MARKER_OUTPERIMETR) return MARKER_OUTPERIMETR;
  if(pkvbigcomponent->isActiveActualData)
  {
    edition_settings = current_settings_interfaces;//������ �����
  }//if(uprbigcomponent->isActiveActualData)
  superClearActiveActualData();

  time_t time_dat_tmp;
  int32_t time_ms_tmp;
  if (save_time_dat_l == 3) 
  {
    time_dat_tmp = time_dat_save_l;
    time_ms_tmp = time_ms_save_l;
  }
  else
  { 
    copying_time_dat = 1;
    time_dat_tmp = time_dat_copy;
    time_ms_tmp = time_ms_copy;
    copying_time_dat = 0;
  }

  int offset = adrReg-BEGIN_ADR_REGISTER;

  switch(offset)
  {
  case 6://��������/��������� ������
    return MARKER_ERRORPERIMETR;

  case 0:
  case 1:
  case 2:
  case 3:
    {
    uint16_t* tmp[4];
    tmp[0] = &((uint16_t*)&time_dat_tmp)[0];
    tmp[1] = &((uint16_t*)&time_dat_tmp)[1];
    tmp[2] = &((uint16_t*)&time_dat_tmp)[2];
    tmp[3] = &((uint16_t*)&time_dat_tmp)[3];
    return (*(tmp[offset-0]));
    }
  case 4:
  case 5:
    {
    uint16_t* tmp[2];
    tmp[0] = &((uint16_t*)&time_ms_tmp)[0];
    tmp[1] = &((uint16_t*)&time_ms_tmp)[1];
    return *(tmp[offset-4]);
    }
  }//switch

  return 0;
}//getDOUTBigModbusRegister(int adrReg)
int getPKVBigModbusBit(int x)
{
  //�������� ���������� ��������
  UNUSED(x);
  return MARKER_OUTPERIMETR;
}//getDOUTBigModbusRegister(int adrReg)
int setPKVBigModbusRegister(int adrReg, int dataReg)
{
  //�������� ���������� ��������
  if(privatePKVBigGetReg2(adrReg)==MARKER_OUTPERIMETR) return MARKER_OUTPERIMETR;
  if(pkvbigcomponent->isActiveActualData)
  {
    edition_settings = current_settings_interfaces;//������ �����
  }//if(uprbigcomponent->isActiveActualData)
  superClearActiveActualData();

  superSetOperativMarker(pkvbigcomponent, adrReg);
  superSetTempWriteArray(dataReg);//�������� � �����

  uint32_t *editValue=NULL;
  if(!PKVFunc000(adrReg-BEGIN_ADR_REGISTER, dataReg, &editValue)) return MARKER_ERRORDIAPAZON;

  return 0;
}//getDOUTBigModbusRegister(int adrReg)
int setPKVBigModbusBit(int x, int y)
{
  UNUSED(x);
  UNUSED(y);
  //�������� ���������� ��������
  return MARKER_OUTPERIMETR;
}//getDOUTBigModbusRegister(int adrReg)

int postPKVBigWriteAction(void)
{
  extern int upravlSetting;//���� Setting
//action ����� ������
  int beginAdr = pkvbigcomponent->operativMarker[0];
  if(beginAdr<0) return 0;//�� ���� ������
  int endAdr   = pkvbigcomponent->operativMarker[1];
  int offsetTempWriteArray = superFindTempWriteArrayOffset(BEGIN_ADR_REGISTER);//����� �������� TempWriteArray
  int countAdr = endAdr-beginAdr+1;
  if(endAdr<0) countAdr = 1;//�-�� ���������
  int flag_time_array = 0;
  int flag_ms_array = 0;

  //����������� ��������� ������ ������
  switch(beginAdr)
  {
   case 3001: case 3002: case 3003: case 3005: return ERROR_VALID2;
  }//switch
  //����������� �������� ������ ������
  switch(endAdr)
  {
   case 3000: case 3001: case 3002: case 3004: return ERROR_VALID2;
  }//switch
  unsigned short time_dat_frac[4];//������� ����� (��� 64-���)
  unsigned short time_ms_frac[2];//������� �����, ������������


  for(int i=0; i<countAdr; i++)
  {
    int offset = i+beginAdr-BEGIN_ADR_REGISTER;
    uint32_t *editValue=NULL;
    PKVFunc000(offset, 0, &editValue);
    unsigned short offsetWriteRegister = tempWriteArray[offsetTempWriteArray+i];//����� �������� ��������
    switch(offset)  //������ ��������
    {

    case 6://��������/��������� ������
      {
      int passwordS=-1;
      switch(pointInterface)//����� ���������� 0-USB 1-RS485
      {
       case USB_RECUEST:
        passwordS = password_set_USB;//������ ����������
       break;
       case RS485_RECUEST:
        passwordS = password_set_RS485;//������ ����������
       break;
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
       case LAN_RECUEST:
        passwordS = password_set_LAN;//������ ����������
       break;
#endif
      }//switch
      unsigned short new_parol = offsetWriteRegister;

      if(passwordS==1) //������ �� ����
      {
        //����� check parol
        if((*editValue) == new_parol)
        {
          //�������� ������ ������
          switch(pointInterface)//����� ���������� 0-USB 1-RS485
          {
           case USB_RECUEST:
            password_set_USB=0;//������ ����������
           break;
           case RS485_RECUEST:
            password_set_RS485=0;//������ ����������
           break;
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
           case LAN_RECUEST:
            password_set_LAN=0;//������ ����������
           break;
#endif
          }//switch
        }//if
        else return ERROR_VALID2;//������������ ������
        break;
      }//if(passwordS==1) //������ �� ����
      } break;

    case 0://����� (��� 64-���)
    case 1://����� (��� 64-���)
    case 2://����� (��� 64-���)
    case 3://����� (��� 64-���)
      if(countAdr == 1) return ERROR_VALID2;//�-�� ���������
      time_dat_frac[offset-0] = offsetWriteRegister;//������� ����� (��� 64-���)
      flag_time_array = 1;
      break;
    case 4://�����, ������������
    case 5://�����, ������������
      if(countAdr == 1) return ERROR_VALID2;//�-�� ���������
      time_ms_frac[offset-4] = offsetWriteRegister;//������� �����, ������������
      flag_ms_array = 1;
      break;
    }//switch
  }//for

  //������ ����� �������� �������
  copying_time_dat = 1;
  time_t time_dat_tmp = time_dat_copy;//time UNIX
  uint32_t time_ms_tmp = time_ms_copy;//milisec
  copying_time_dat = 0;
   uint16_t* tmp1 = &((uint16_t*)&time_dat_tmp)[0];
   uint16_t* tmp2 = &((uint16_t*)&time_dat_tmp)[1];
   uint16_t* tmp3 = &((uint16_t*)&time_dat_tmp)[2];
   uint16_t* tmp4 = &((uint16_t*)&time_dat_tmp)[3];
   uint16_t* tmp5 = &((uint16_t*)&time_ms_tmp)[0];
   uint16_t* tmp6 = &((uint16_t*)&time_ms_tmp)[1];
  if(flag_time_array)
  {
  (*tmp1) = time_dat_frac[0];
  (*tmp2) = time_dat_frac[1];
  (*tmp3) = time_dat_frac[2];
  (*tmp4) = time_dat_frac[3];
  }//if
  if(flag_ms_array)
  {
  (*tmp5) = time_ms_frac[0];
  (*tmp6) = time_ms_frac[1];
  if(time_ms_tmp>1000) return ERROR_VALID2;
  }//if

  if(flag_time_array || flag_ms_array)
  {
    time_dat_save_l = time_dat_tmp;
    time_ms_save_l = time_ms_tmp;
    save_time_dat_l = 3;
  }//if(flag_time_array || flag_ms_array)
  return 0;
}//

int privatePKVBigGetReg2(int adrReg)
{
  //��������� ������� ��������
  return controlPerimetr(adrReg, BEGIN_ADR_REGISTER, END_ADR_REGISTER);
}//privateGetReg2(int adrReg)

int passwordImunitetRegPKVBigComponent(int adrReg)
{
  //����������� � ������ ������ ��������� 0 - ���� ��������
  if(privatePKVBigGetReg2(adrReg)==MARKER_OUTPERIMETR) return MARKER_OUTPERIMETR;
  switch(adrReg)
  {
  case BEGIN_ADR_REGISTER+IMUNITET_PKV1://��������/��������� ������
    return 0;//���� ��������
  }//switch
  return MARKER_OUTPERIMETR;
}//passwordImunitetRegPKVBigComponent(int adrReg)
