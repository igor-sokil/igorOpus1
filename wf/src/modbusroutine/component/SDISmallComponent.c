
#include "header.h"

//��������� ������� � ����� ������
#define BEGIN_ADR_REGISTER 390
//��������� bit � ����� ������
#define BEGIN_ADR_BIT 23040

//�������� ������� � ����� ������
#define END_ADR_REGISTER 391
//�������� bit � ����� ������
#define END_ADR_BIT 23056

int privateSDISmallGetReg2(int adrReg);
int privateSDISmallGetBit2(int adrBit);

int getSDISmallModbusRegister(int);//�������� ���������� ��������
int getSDISmallModbusBit(int);//�������� ���������� ����
int setSDISmallModbusRegister(int, int);//�������� �������
int setSDISmallModbusBit(int, int);//�������� ���

int  postSDISmallWriteAction(void);//action ����� ������

SRAM1 COMPONENT_OBJ *sdismallcomponent;

/**************************************/
//���������� ���������� ��
/**************************************/
void constructorSDISmallComponent(COMPONENT_OBJ *sdicomp)
{
  sdismallcomponent = sdicomp;

  sdismallcomponent->getModbusRegister = getSDISmallModbusRegister;//�������� ���������� ��������
  sdismallcomponent->getModbusBit      = getSDISmallModbusBit;//�������� ���������� ����
  sdismallcomponent->setModbusRegister = setSDISmallModbusRegister;// ��������
  sdismallcomponent->setModbusBit      = setSDISmallModbusBit;// ����

  sdismallcomponent->postWriteAction = postSDISmallWriteAction;//action ����� ������
}//constructorSDISmallComponent(COMPONENT_OBJ *SDIcomp)

int getSDISmallModbusRegister(int adrReg) {
  //�������� ���������� ��������
  if(privateSDISmallGetReg2(adrReg)==MARKER_OUTPERIMETR) return MARKER_OUTPERIMETR;

  switch(adrReg-BEGIN_ADR_REGISTER)
  {
    case 0:
    return (state_leds) &0xFFFF;
    case 1:
    return (state_leds>>16)&0x1;
  }//switch

  return 0;
}//getSDIModbusRegister(int adrReg)
int getSDISmallModbusBit(int adrBit) {
  //�������� ���������� bit
  if(privateSDISmallGetBit2(adrBit)==MARKER_OUTPERIMETR) return MARKER_OUTPERIMETR;

  //state_leds = 0x10001;
  short tmp = state_leds &0xFFFF;
  if((adrBit-BEGIN_ADR_BIT)>=16) tmp = (state_leds>>16)&0x1;
  short maska = 1<<((adrBit-BEGIN_ADR_BIT)%16);
  if(tmp&maska) return 1;
  return 0;
}//getSDIModbusBit(int adrReg)
int setSDISmallModbusRegister(int x, int y) {
  UNUSED(x);
  UNUSED(y);
  //�������� ���������� ��������
  return MARKER_OUTPERIMETR;
}//getSDIModbusRegister(int adrReg)
int setSDISmallModbusBit(int x, int y) {
  UNUSED(x);
  UNUSED(y);
  //�������� ���������� ��������
  return MARKER_OUTPERIMETR;
}//getSDIModbusRegister(int adrReg)

int postSDISmallWriteAction(void) {
//action ����� ������
  return 0;
}//

int privateSDISmallGetReg2(int adrReg)
{
  //��������� ������� ��������
 return controlPerimetr(adrReg, BEGIN_ADR_REGISTER, END_ADR_REGISTER);
}//privateGetReg2(int adrReg)

int privateSDISmallGetBit2(int adrBit)
{
  //��������� ������� ��������
 return controlPerimetr(adrBit, BEGIN_ADR_BIT, END_ADR_BIT);
}//privateGetReg2(int adrReg)
