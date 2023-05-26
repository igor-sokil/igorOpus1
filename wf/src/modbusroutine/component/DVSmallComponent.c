
#include "header.h"

//��������� ������� � ����� ������
#define BEGIN_ADR_REGISTER 300
//��������� bit � ����� ������
#define BEGIN_ADR_BIT 21600

//�������� ������� � ����� ������
#define END_ADR_REGISTER 300
//�������� bit � ����� ������
#define END_ADR_BIT 21615

int privateDVSmallGetReg2(int adrReg);
int privateDVSmallGetBit2(int adrBit);

int getDVSmallModbusRegister(int);//�������� ���������� ��������
int getDVSmallModbusBit(int);//�������� ���������� ����
int setDVSmallModbusRegister(int, int);//�������� �������
int setDVSmallModbusBit(int, int);//�������� ���

int  postDVSmallWriteAction(void);//action ����� ������

SRAM1 COMPONENT_OBJ *dvsmallcomponent;

/**************************************/
//���������� ���������� ��
/**************************************/
void constructorDVSmallComponent(COMPONENT_OBJ *dvcomp)
{
  dvsmallcomponent = dvcomp;

  dvsmallcomponent->getModbusRegister = getDVSmallModbusRegister;//�������� ���������� ��������
  dvsmallcomponent->getModbusBit      = getDVSmallModbusBit;//�������� ���������� ����
  dvsmallcomponent->setModbusRegister = setDVSmallModbusRegister;// ��������
  dvsmallcomponent->setModbusBit      = setDVSmallModbusBit;// ����

  dvsmallcomponent->postWriteAction = postDVSmallWriteAction;//action ����� ������
}//constructorDVSmallComponent(COMPONENT_OBJ *DVcomp)

int getDVSmallModbusRegister(int adrReg) {
  //�������� ���������� ��������
  if(privateDVSmallGetReg2(adrReg)==MARKER_OUTPERIMETR) return MARKER_OUTPERIMETR;

  int tmp   = active_inputs&((1<<NUMBER_INPUTS)-1);
  switch(adrReg-BEGIN_ADR_REGISTER)
  {
   case 0: tmp &= 0xFFFF; break;
   case 1: tmp = (tmp>>16)&0xF; break;
   default: tmp = 0;
  }//switch

  return tmp;
}//getDVModbusRegister(int adrReg)
int getDVSmallModbusBit(int adrBit) {
  //�������� ���������� bit
  if(privateDVSmallGetBit2(adrBit)==MARKER_OUTPERIMETR) return MARKER_OUTPERIMETR;

  int tmp   = active_inputs&((1<<NUMBER_INPUTS)-1);
  int offset = adrBit-BEGIN_ADR_BIT;
  switch(offset/16)
  {
   case 0: tmp &= 0xFFFF; break;
   case 1: tmp = (tmp>>16)&0xF; break;
   default: tmp = 0;
  }//switch

  int maska = 1<<((adrBit-BEGIN_ADR_BIT)%16);
  if(tmp&maska) return 1;
  return 0;
}//getDVModbusBit(int adrReg)
int setDVSmallModbusRegister(int x, int y) {
  UNUSED(x);
  UNUSED(y);
  //�������� ���������� ��������
  return MARKER_OUTPERIMETR;
}//getDVModbusRegister(int adrReg)
int setDVSmallModbusBit(int x, int y) {
  UNUSED(x);
  UNUSED(y);
  //�������� ���������� ��������
  return MARKER_OUTPERIMETR;
}//getDVModbusRegister(int adrReg)

int postDVSmallWriteAction(void) {
//action ����� ������
  return 0;
}//

int privateDVSmallGetReg2(int adrReg)
{
  //��������� ������� ��������
 return controlPerimetr(adrReg, BEGIN_ADR_REGISTER, END_ADR_REGISTER);
}//privateGetReg2(int adrReg)

int privateDVSmallGetBit2(int adrBit)
{
  //��������� ������� ��������
 return controlPerimetr(adrBit, BEGIN_ADR_BIT, END_ADR_BIT);
}//privateGetReg2(int adrReg)
