
#include "header.h"

//��������� ������� � ����� ������
#define BEGIN_ADR_REGISTER 200
//��������� bit � ����� ������
#define BEGIN_ADR_BIT 20000

//�������� ������� � ����� ������
#define END_ADR_REGISTER 200
//�������� bit � ����� ������
#define END_ADR_BIT 20015


int privateDOUTSmallGetReg2(int adrReg);
int privateDOUTSmallGetBit2(int adrBit);

int getDOUTSmallModbusRegister(int);//�������� ���������� ��������
int getDOUTSmallModbusBit(int);//�������� ���������� ����
int setDOUTSmallModbusRegister(int, int);//�������� �������
int setDOUTSmallModbusBit(int, int);//�������� ���

int  postDOUTSmallWriteAction(void);//action ����� ������

SRAM1 COMPONENT_OBJ *doutsmallcomponent;

/**************************************/
//���������� ���������� ��
/**************************************/
void constructorDOUTSmallComponent(COMPONENT_OBJ *doutcomp)
{
  doutsmallcomponent = doutcomp;

  doutsmallcomponent->getModbusRegister = getDOUTSmallModbusRegister;//�������� ���������� ��������
  doutsmallcomponent->getModbusBit      = getDOUTSmallModbusBit;//�������� ���������� ����
  doutsmallcomponent->setModbusRegister = setDOUTSmallModbusRegister;// ��������
  doutsmallcomponent->setModbusBit      = setDOUTSmallModbusBit;// ����

  doutsmallcomponent->postWriteAction = postDOUTSmallWriteAction;//action ����� ������
}//constructorDOUTSmallComponent(COMPONENT_OBJ *doutcomp)

int getDOUTSmallModbusRegister(int adrReg) {
  //�������� ���������� ��������
  if(privateDOUTSmallGetReg2(adrReg)==MARKER_OUTPERIMETR) return MARKER_OUTPERIMETR;

  int tmp   = state_outputs_raw&((1<<NUMBER_SIMPLE_OUTPUTS)-1);
  switch(adrReg-BEGIN_ADR_REGISTER)
  {
   case 0: tmp &= 0xFFFF; break;
   default: tmp = 0;
  }//switch

  return tmp;
}//getDOUTModbusRegister(int adrReg)

int getDOUTSmallModbusBit(int adrBit) {
  //�������� ���������� bit
  if(privateDOUTSmallGetBit2(adrBit)==MARKER_OUTPERIMETR) return MARKER_OUTPERIMETR;

  int tmp = state_outputs_raw&((1<<NUMBER_SIMPLE_OUTPUTS)-1);
  int offset = adrBit-BEGIN_ADR_BIT;
  switch(offset/16)
  {
   case 0: tmp &= 0xFFFF; break;
   default: tmp = 0;
  }//switch

  int maska = 1<<((adrBit-BEGIN_ADR_BIT)%16);
  if(tmp&maska) return 1;
  return 0;
}//getDOUTModbusBit(int adrReg)
int setDOUTSmallModbusRegister(int x, int y) {
  UNUSED(x);
  UNUSED(y);
  //�������� ���������� ��������
  return MARKER_OUTPERIMETR;
}//getDOUTModbusRegister(int adrReg)
int setDOUTSmallModbusBit(int x, int y) {
  UNUSED(x);
  UNUSED(y);
  //�������� ���������� ��������
  return MARKER_OUTPERIMETR;
}//getDOUTModbusRegister(int adrReg)

int postDOUTSmallWriteAction(void) {
//action ����� ������
  return 0;
}//

int privateDOUTSmallGetReg2(int adrReg)
{
  //��������� ������� ��������
 return controlPerimetr(adrReg, BEGIN_ADR_REGISTER, END_ADR_REGISTER);
}//privateGetReg2(int adrReg)

int privateDOUTSmallGetBit2(int adrBit)
{
  //��������� ������� ��������
 return controlPerimetr(adrBit, BEGIN_ADR_BIT, END_ADR_BIT);
}//privateGetReg2(int adrReg)
