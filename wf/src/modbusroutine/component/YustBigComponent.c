#include "header.h"

//��������� ������� � ����� ������
#define BEGIN_ADR_REGISTER 61948
//�������� ������� � ����� ������
#define END_ADR_REGISTER 63472

int privateYustBigGetReg2(int adrReg);

int getYustBigModbusRegister(int);//�������� ���������� ��������
int getYustBigModbusBit(int);//�������� ���������� ����
int setYustBigModbusRegister(int, int);//�������� ���������� ��������
int setYustBigModbusBit(int, int);//�������� ���������� ����

int postYustBigWriteAction(void);//action ����� ������
int passwordImunitetRegYUSTBigComponent(int adrReg);

SRAM1 COMPONENT_OBJ *yustbigcomponent;

int upravlYust=-1;//���� ���������

/**************************************/
//���������� ���������� ���������
/**************************************/
void constructorYustBigComponent(COMPONENT_OBJ *yustbigcomp)
{
  yustbigcomponent = yustbigcomp;

  yustbigcomponent->getModbusRegister = getYustBigModbusRegister;//�������� ���������� ��������
  yustbigcomponent->getModbusBit      = getYustBigModbusBit;//�������� ���������� ����
  yustbigcomponent->setModbusRegister = setYustBigModbusRegister;//�������� ���������� ��������
  yustbigcomponent->setModbusBit      = setYustBigModbusBit;//�������� ���������� ����

  yustbigcomponent->postWriteAction = postYustBigWriteAction;//action ����� ������
}//prepareDVinConfig

int getYustBigModbusRegister(int adrReg)
{
  //�������� ���������� ��������
  if(privateYustBigGetReg2(adrReg)==MARKER_OUTPERIMETR) return MARKER_OUTPERIMETR;

  superSetOperativMarker(yustbigcomponent, adrReg);

  int offset = adrReg-BEGIN_ADR_REGISTER;
  if(offset==0) return MARKER_ERRORPERIMETR;//61948 ������ ��������� ������ ����������
  if(offset==19) return MARKER_ERRORPERIMETR;//61967 ���������� ���������

  switch(offset) {//������ �������� �����
  case 20:
  case 21:
  case 22:
  case 23:
  case 24:
  case 25:
  case 26:
    return (ustuvannja[offset-20]) &0xFFFF;

  case 52://62000
    return (current_settings_interfaces.number_iteration_el) &0xFFFF;//������������ ���������� ��������
  }//switch

  return 0;
}//getDOUTBigModbusRegister(int adrReg)
int getYustBigModbusBit(int x)
{
  //�������� ���������� ��������
  UNUSED(x);
  return MARKER_OUTPERIMETR;
}//getDOUTBigModbusRegister(int adrReg)
int setYustBigModbusRegister(int adrReg, int dataReg)
{
  //�������� ���������� ��������
  if(privateYustBigGetReg2(adrReg)==MARKER_OUTPERIMETR) return MARKER_OUTPERIMETR;

  if(yustbigcomponent->isActiveActualData) {
    edit_serial_number_dev = serial_number_dev;
    for(int i=0; i<NUMBER_ANALOG_CANALES; i++) edit_ustuvannja[i] = ustuvannja[i];
  //  for(int i=0; i<NUMBER_ANALOG_CANALES; i++) phi_edit_ustuvannja[i] = phi_ustuvannja[i];
  }//if
  yustbigcomponent->isActiveActualData = 0;

  superSetOperativMarker(yustbigcomponent, adrReg);
  superSetTempWriteArray(dataReg);//�������� � �����
  if(adrReg==62000)
    if(dataReg<1 || dataReg>32) return MARKER_ERRORDIAPAZON;

  return 0;
}//getDOUTBigModbusRegister(int adrReg)
int setYustBigModbusBit(int x, int y)
{
  UNUSED(x);
  UNUSED(y);
  //�������� ���������� bit
  return MARKER_OUTPERIMETR;
}//getDOUTBigModbusRegister(int adrReg)

int postYustBigWriteAction(void) {
//action ����� ������
  int beginAdr = yustbigcomponent->operativMarker[0];
  if(beginAdr<0) return 0;//�� ���� ������
  int endAdr   = yustbigcomponent->operativMarker[1];
  int offsetTempWriteArray = superFindTempWriteArrayOffset(BEGIN_ADR_REGISTER);//����� �������� TempWriteArray
  int countAdr = endAdr-beginAdr+1;
  if(endAdr<0) countAdr = 1;

  int upravlMin=0;//���� min param
  //int upravlMinEnrg=0;//���� min Enrg
  int number_iteration_el=-1;

  for(int i=0; i<countAdr; i++) {
    int offset = i+beginAdr-BEGIN_ADR_REGISTER;
    switch(offset) {//������ �������� �����
    case 0://�������� �����
      edit_serial_number_dev = tempWriteArray[offsetTempWriteArray+i];
      break;
    case 19://���������� ���������
      upravlYust = tempWriteArray[offsetTempWriteArray+i];//���������
      break;
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
      edit_ustuvannja[offset-20] = tempWriteArray[offsetTempWriteArray+i];
      break;

    case 52://62000 number_iteration_el
      number_iteration_el = tempWriteArray[offsetTempWriteArray+i];//number_iteration_el
      break;
    case 152://62100
      upravlMin = tempWriteArray[offsetTempWriteArray+i];//���� min param
      break;
//    case 1053://63001
//      upravlMinEnrg = tempWriteArray[offsetTempWriteArray+i];//���� min Enrg
//      break;
#define  IMUNITET_REG472 63472
    case (IMUNITET_REG472 - BEGIN_ADR_REGISTER):
      test_watchdogs = (unsigned short)tempWriteArray[offsetTempWriteArray+i];//CMD_TEST_EXTERNAL_WATCHDOG;
      return 0;
    }//switch
  }//for

  if(number_iteration_el>0)
  {
    current_settings_interfaces.number_iteration_el = number_iteration_el;

    //³������� ���� ���������
    _SET_BIT(active_functions, RNG_BIG_SETTINGS_CHANGED);
    type_of_settings_changed |= (1 << SETTINGS_DATA_CHANGED_BIT);
    int typI = 2;
    if(pointInterface==RS485_RECUEST)//����� ���������� 0-USB 1-RS485
      typI = 3;
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
    else if(pointInterface==LAN_RECUEST) typI = 4;//����� ���������� 0-USB 1-RS485
#endif
    if(set_new_settings_from_interface(typI)) return ERROR_VALID2;//2-USB
    return 0;
  }//if(number_iteration_el>0)

  if(upravlYust==0x1978) {//���� ���������

    changed_ustuvannja = CHANGED_ETAP_EXECUTION;
    if (serial_number_dev != edit_serial_number_dev)
    {   
      serial_number_dev = edit_serial_number_dev;
      
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
      //�������, �� ����� ������������� ��
      _SET_STATE(queue_mo, STATE_QUEUE_MO_RESTART_KP);
#endif
    }
    for(int i=0; i<NUMBER_ANALOG_CANALES; i++) ustuvannja[i] = edit_ustuvannja[i];
//    for(int i=0; i<NUMBER_ANALOG_CANALES; i++) phi_ustuvannja[i] = phi_edit_ustuvannja[i];

    changed_ustuvannja = CHANGED_ETAP_ENDED;
    _SET_BIT(control_spi1_taskes, TASK_START_WRITE_USTUVANNJA_EEPROM_BIT);
  }//if
  else if(upravlYust==0) {//���� ���������
    upravlYust=-1;
  }//if
  else if(upravlMin==0x1111) {

    //������� ��������� � "������� �������� ��������"
    min_settings(&current_settings_interfaces);

    //³������� ���� ���������
    _SET_BIT(active_functions, RNG_BIG_SETTINGS_CHANGED);
    restart_timeout_idle_new_settings = true;
    type_of_settings_changed = (1 << DEFAULT_SETTINGS_SET_BIT);

    int typI = 2;
    if(pointInterface==RS485_RECUEST)//����� ���������� 0-USB 1-RS485
      typI = 3;
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
    else if(pointInterface==LAN_RECUEST) typI = 4;//����� ���������� 0-USB 1-RS485
#endif
    if(set_new_settings_from_interface(typI)) return ERROR_VALID2;
  }//if(upravlMin==0x1111)
//  else if(upravlMinEnrg==0x1234) {
      //��� �������� ������ ��������� ����� ������� ��������� ����� - ������ �����������, �� ���� ������ ������ �� ���� (���������� ����� ���������� �� ����������������� ���������� ����� ���'��)
//      clean_energy = 0xff;
//  }//if(upravlMinEnrg==0x1234)
  else return ERROR_VALID2;//���� ���������

  return 0;
}//

int privateYustBigGetReg2(int adrReg)
{
  //��������� ������� ��������
  return controlPerimetr(adrReg, BEGIN_ADR_REGISTER, END_ADR_REGISTER);
}//privateGetReg2(int adrReg)

int passwordImunitetRegYUSTBigComponent(int adrReg)
{
  //����������� � ������ ������ ��������� 0 - ���� ��������
  if(privateYustBigGetReg2(adrReg)==MARKER_OUTPERIMETR) return MARKER_OUTPERIMETR;
  if(adrReg < IMUNITET_REG472) return 0;//���� ��������
  return MARKER_OUTPERIMETR;
}//passwordImunitetRegYUSTBigComponent(int adrReg)

