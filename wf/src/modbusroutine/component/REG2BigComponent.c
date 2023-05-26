//��������� ������� � ����� ������
#define BEGIN_ADR_REGISTER 1800
//�������� ������� � ����� ������
#define END_ADR_REGISTER 1802

#include "header.h"

int privateREG2BigGetReg2(int adrReg);

int getREG2BigModbusRegister(int);//�������� ���������� ��������
int getREG2BigModbusBit(int);//�������� ���������� ����
int setREG2BigModbusRegister(int, int);//�������� ���������� ��������
int setREG2BigModbusBit(int, int);//�������� ���������� ����

int  postREG2BigWriteAction(void);//action ����� ������
int passwordImunitetRegREG2BigComponent(int adrReg);

SRAM1 COMPONENT_OBJ *reg2bigcomponent;

/**************************************/
//���������� ���������� REGistrator
/**************************************/
void constructorREG2BigComponent(COMPONENT_OBJ *reg2bigcomp)
{
  reg2bigcomponent = reg2bigcomp;

  reg2bigcomponent->getModbusRegister = getREG2BigModbusRegister;//�������� ���������� ��������
  reg2bigcomponent->getModbusBit      = getREG2BigModbusBit;//�������� ���������� ����
  reg2bigcomponent->setModbusRegister = setREG2BigModbusRegister;//�������� ���������� ��������
  reg2bigcomponent->setModbusBit      = setREG2BigModbusBit;//�������� ���������� ����

  reg2bigcomponent->postWriteAction = postREG2BigWriteAction;//action ����� ������
}//constructorREGBigComponent

int getREG2BigModbusRegister(int adrReg)
{
  //�������� ���������� ��������
  if(privateREG2BigGetReg2(adrReg)==MARKER_OUTPERIMETR) return MARKER_OUTPERIMETR;

  int offset = adrReg-BEGIN_ADR_REGISTER;

  switch(offset)
    {
    case 0://���������� ���������� �������������
      {
        unsigned int first_number = (info_rejestrator_ar.first_number < 0) ? 0 : (info_rejestrator_ar.first_number + 1);
        unsigned int last_number  = (info_rejestrator_ar.last_number  < 0) ? 0 : (info_rejestrator_ar.last_number + 1);
      
        unsigned int number_records;
        if (first_number == 0) number_records = 0;
        else if (first_number >= last_number) number_records = first_number - last_number + 1;
        else number_records = NUMBER_FATFS_NAME - last_number + first_number + 1;
                
        return (number_records) & 0xFFFF;
      }

    case 1://���������� ���������� �������������
      return (info_rejestrator_dr.number_records) &0xFFFF;

    case 2://���������� ������� rds
      return  0;//GetAmountFixElem()&0xFFFF;
    }//switch

  return 0;
}//getDOUTBigModbusRegister(int adrReg)
int getREG2BigModbusBit(int x)
{
  //�������� ���������� ��������
  UNUSED(x);
  return MARKER_OUTPERIMETR;
}//getDOUTBigModbusRegister(int adrReg)
int setREG2BigModbusRegister(int adrReg, int dataReg)
{
  UNUSED(adrReg);
  UNUSED(dataReg);
  //�������� ���������� ��������
  return MARKER_OUTPERIMETR;
}//
int setREG2BigModbusBit(int x, int y)
{
  UNUSED(x);
  UNUSED(y);
  //�������� ���������� ��������
  return MARKER_OUTPERIMETR;
}//getDOUTBigModbusRegister(int adrReg)

int postREG2BigWriteAction(void)
{
  return 0;
}//

int privateREG2BigGetReg2(int adrReg)
{
  //��������� ������� ��������
  return controlPerimetr(adrReg, BEGIN_ADR_REGISTER, END_ADR_REGISTER);
}//privateGetReg2(int adrReg)

