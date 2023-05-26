
#include "header.h"

//��������� ������� � ����� ������
#define BEGIN_ADR_REGISTER 395
//��������� bit � ����� ������
#define BEGIN_ADR_BIT 23120

//�������� ������� � ����� ������
#define END_ADR_REGISTER 395
//�������� bit � ����� ������
#define END_ADR_BIT 23125

int privateKEYSmallGetReg2(int adrReg);
int privateKEYSmallGetBit2(int adrBit);

int getKEYSmallModbusRegister(int);//�������� ���������� ��������
int getKEYSmallModbusBit(int);//�������� ���������� ����
int setKEYSmallModbusRegister(int, int);//�������� �������
int setKEYSmallModbusBit(int, int);//�������� ���

int  postKEYSmallWriteAction(void);//action ����� ������

SRAM1 COMPONENT_OBJ *keysmallcomponent;

/**************************************/
//���������� ���������� KEY
/**************************************/
void constructorKEYSmallComponent(COMPONENT_OBJ *keycomp)
{
  keysmallcomponent = keycomp;

  keysmallcomponent->getModbusRegister = getKEYSmallModbusRegister;//�������� ���������� ��������
  keysmallcomponent->getModbusBit      = getKEYSmallModbusBit;//�������� ���������� ����
  keysmallcomponent->setModbusRegister = setKEYSmallModbusRegister;// ��������
  keysmallcomponent->setModbusBit      = setKEYSmallModbusBit;// ����

  keysmallcomponent->postWriteAction = postKEYSmallWriteAction;//action ����� ������
}//constructorKEYSmallComponent(COMPONENT_OBJ *KEYcomp)

int getKEYSmallModbusRegister(int adrReg) {
  //�������� ���������� ��������
  if(privateKEYSmallGetReg2(adrReg)==MARKER_OUTPERIMETR) return MARKER_OUTPERIMETR;

  int tmp   = state_FK & ((1<<NUMBER_DEFINED_BUTTONS)-1);

  switch(adrReg-BEGIN_ADR_REGISTER)
  {
   case 0:  tmp &= 0xFFFF; break;
   default: tmp = 0;
  }//switch

  return tmp;
}//getKEYModbusRegister(int adrReg)
int getKEYSmallModbusBit(int adrBit) {
  //�������� ���������� bit
  if(privateKEYSmallGetBit2(adrBit)==MARKER_OUTPERIMETR) return MARKER_OUTPERIMETR;

  int tmp   = state_FK & ((1<<NUMBER_DEFINED_BUTTONS)-1);

  int offset = adrBit-BEGIN_ADR_BIT;
  switch(offset/16)
  {
   case 0:  tmp &= 0xFFFF; break;
   default: tmp = 0;
  }//switch

  int maska = 1<<((adrBit-BEGIN_ADR_BIT)%16);
  if(tmp&maska) return 1;
  return 0;
}//getKEYModbusBit(int adrReg)
int setKEYSmallModbusRegister(int x, int y) {
  UNUSED(x);
  UNUSED(y);
  //�������� ���������� ��������
  return MARKER_OUTPERIMETR;
}//getKEYModbusRegister(int adrReg)
int setKEYSmallModbusBit(int x, int y) {
  UNUSED(x);
  UNUSED(y);
  //�������� ���������� ��������
  return MARKER_OUTPERIMETR;
}//getKEYModbusRegister(int adrReg)

int postKEYSmallWriteAction(void) {
//action ����� ������
  return 0;
}//

int privateKEYSmallGetReg2(int adrReg)
{
  //��������� ������� ��������
 return controlPerimetr(adrReg, BEGIN_ADR_REGISTER, END_ADR_REGISTER);
}//privateGetReg2(int adrReg)

int privateKEYSmallGetBit2(int adrBit)
{
  //��������� ������� ��������
 return controlPerimetr(adrBit, BEGIN_ADR_BIT, END_ADR_BIT);
}//privateGetReg2(int adrReg)
