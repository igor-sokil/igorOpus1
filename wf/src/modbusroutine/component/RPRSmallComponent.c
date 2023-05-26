#include "header.h"

//��������� ������� � ����� ������
#define BEGIN_ADR_REGISTER M_ADDRESS_FIRST_USER_REGISTER_DATA
//�������� ������� � ����� ������
#define END_ADR_REGISTER M_ADDRESS_LAST_USER_REGISTER_DATA

int privateRPRSmallGetReg2(int adrReg);

int getRPRSmallModbusRegister(int);//�������� ���������� ��������
int getRPRSmallModbusBit(int);//�������� ���������� ����
int setRPRSmallModbusRegister(int, int);//�������� ���������� ��������
int setRPRSmallModbusBit(int, int);//�������� ���������� ����

int  postRPRSmallWriteAction(void);//action ����� ������
int getRPRSmallModbusBeginAdrRegister(void);
int getRPRSmallModbusEndAdrRegister(void);

SRAM1 COMPONENT_OBJ *rprsmallcomponent;

int getRPRSmallModbusBeginAdrRegister(void)
{
  //�������� ����� ��� ��������
 return BEGIN_ADR_REGISTER;
}//getRPRSmallModbusBeginAdrRegister
int getRPRSmallModbusEndAdrRegister(void)
{
  //�������� ����� end ��������
 return END_ADR_REGISTER;
}//getRPRSmallModbusEndAdrRegister

/**************************************/
//���������� ���������� ������������ ���������������� ���������
/**************************************/
void constructorRPRSmallComponent(COMPONENT_OBJ *rprsmallcomp)
{
  rprsmallcomponent = rprsmallcomp;

  rprsmallcomponent->getModbusRegister = getRPRSmallModbusRegister;//�������� ���������� ��������
  rprsmallcomponent->getModbusBit      = getRPRSmallModbusBit;//�������� ���������� ����
  rprsmallcomponent->setModbusRegister = setRPRSmallModbusRegister;//�������� ���������� ��������
  rprsmallcomponent->setModbusBit      = setRPRSmallModbusBit;//�������� ���������� ����

  rprsmallcomponent->postWriteAction = postRPRSmallWriteAction;//action ����� ������
}//prepareDVinConfig

int getRPRSmallModbusRegister(int adrReg)
{
  //�������� ���������� ��������
  if(privateRPRSmallGetReg2(adrReg)==MARKER_OUTPERIMETR) return MARKER_OUTPERIMETR;

  int result = superReaderRegister(current_settings_interfaces.user_register[adrReg-BEGIN_ADR_REGISTER]);
  if(result&0xffff0000) return 0;

  return (result) &0xFFFF;
}//getDOUTModbusRegister(int adrReg)
int getRPRSmallModbusBit(int x)
{
  //�������� ���������� bit
  UNUSED(x);
  return MARKER_OUTPERIMETR;
}//getDOUTBigModbusRegister(int adrReg)
int setRPRSmallModbusRegister(int x, int y)
{
  UNUSED(x);
  UNUSED(y);
  //�������� ���������� ��������
  return MARKER_OUTPERIMETR;
}//getDOUTBigModbusRegister(int adrReg)
int setRPRSmallModbusBit(int x, int y)
{
  UNUSED(x);
  UNUSED(y);
  //�������� ���������� bit
  return MARKER_OUTPERIMETR;
}//getDOUTBigModbusRegister(int adrReg)

int postRPRSmallWriteAction(void) {
//action ����� ������
  return 0;
}//

int privateRPRSmallGetReg2(int adrReg)
{
  //��������� ������� ��������
 return controlPerimetr(adrReg, BEGIN_ADR_REGISTER, END_ADR_REGISTER);
}//privateGetReg2(int adrReg)
