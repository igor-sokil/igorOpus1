
#include "header.h"

//��������� ������� � ����� ������
#define BEGIN_ADR_REGISTER 750
//��������� bit � ����� ������
#define BEGIN_ADR_BIT 29000

//�������� ������� � ����� ������
#define END_ADR_REGISTER 854
//�������� bit � ����� ������
#define END_ADR_BIT 30679
//#endif

int privateGCMDSmallGetReg2(int adrReg);
int privateGCMDSmallGetBit2(int adrBit);

int getGCMDSmallModbusRegister(int);//�������� ���������� ��������
int getGCMDSmallModbusBit(int);//�������� ���������� ����
int setGCMDSmallModbusRegister(int, int);//�������� �������
int setGCMDSmallModbusBit(int, int);//�������� ���

int  postGCMDSmallWriteAction(void);//action ����� ������
void loadACMDSmallActualDataBit(int cmdSwitch, int beginOffset, int endOffset);

SRAM1 COMPONENT_OBJ *gcmdsmallcomponent;
/**************************************/
//��������� ������� �������� � ����������� �������
/**************************************/
void constructorGCMDSmallComponent(COMPONENT_OBJ *gcmdcomp)
{
  gcmdsmallcomponent = gcmdcomp;

  gcmdsmallcomponent->getModbusRegister = getGCMDSmallModbusRegister;//�������� ���������� ��������
  gcmdsmallcomponent->getModbusBit      = getGCMDSmallModbusBit;//�������� ���������� ����
  gcmdsmallcomponent->setModbusRegister = setGCMDSmallModbusRegister;// ��������
  gcmdsmallcomponent->setModbusBit      = setGCMDSmallModbusBit;// ����

  gcmdsmallcomponent->postWriteAction = postGCMDSmallWriteAction;//action ����� ������
}//constructorGCMDSmallComponent(COMPONENT_OBJ *gcmdcomp)

int getGCMDSmallModbusRegister(int adrReg)
{
  extern int globalcntReg;//�-�� ��� ��� ������
  extern int globalbeginAdrReg;//����� ��� ���
  //�������� ���������� ��������
  if(privateGCMDSmallGetReg2(adrReg)==MARKER_OUTPERIMETR) return MARKER_OUTPERIMETR;
  if(gcmdsmallcomponent->isActiveActualData)
    {
    int begin = globalbeginAdrReg-BEGIN_ADR_REGISTER;
    if(begin<0) globalcntReg += begin;

    int beginOffset = (adrReg-BEGIN_ADR_REGISTER)*16;
    int endOffset   = beginOffset +globalcntReg*16;

      loadACMDSmallActualDataBit(1, beginOffset, endOffset); //ActualData GCMD
    }//if(gcmdsmallcomponent->isActiveActualData)
  gcmdsmallcomponent->isActiveActualData = 0;

  return tempReadArray[adrReg-BEGIN_ADR_REGISTER];
}//getDOUTModbusRegister(int adrReg)
int getGCMDSmallModbusBit(int adrBit)
{
  extern int globalcntBit;//�-�� ��� ��� ������
  extern int globalbeginAdrBit;//����� ��� ���
  //�������� ���������� bit
  if(privateGCMDSmallGetBit2(adrBit)==MARKER_OUTPERIMETR) return MARKER_OUTPERIMETR;

  int beginOffset = adrBit-BEGIN_ADR_BIT;
  if(gcmdsmallcomponent->isActiveActualData)
    {
      int begin = globalbeginAdrBit-BEGIN_ADR_BIT;
    if(begin<0) globalcntBit += begin;

      int endOffset   = beginOffset +globalcntBit;

      loadACMDSmallActualDataBit(1, beginOffset, endOffset); //ActualData GCMD
    }//if(gcmdsmallcomponent->isActiveActualData)
  gcmdsmallcomponent->isActiveActualData = 0;

  short tmp   = tempReadArray[beginOffset/16];
  short maska = 1<<(beginOffset%16);
  if(tmp&maska) return 1;
  return 0;
}//getGCMDSmallModbusBit(int adrBit)
int setGCMDSmallModbusRegister(int x, int y)
{
  UNUSED(x);
  UNUSED(y);
  //�������� ���������� ��������
  return MARKER_OUTPERIMETR;
}//getDOUTModbusRegister(int adrReg)
int setGCMDSmallModbusBit(int x, int y)
{
  UNUSED(x);
  UNUSED(y);
  //�������� ���������� ��������
  return MARKER_OUTPERIMETR;
}//getDOUTModbusRegister(int adrReg)

int postGCMDSmallWriteAction(void)
{
//action ����� ������
  return 0;
}//

int privateGCMDSmallGetReg2(int adrReg)
{
  //��������� ������� ��������
 return controlPerimetr(adrReg, BEGIN_ADR_REGISTER, END_ADR_REGISTER);
}//privateGetReg2(int adrReg)

int privateGCMDSmallGetBit2(int adrBit)
{
  //��������� ������� ��������
 return controlPerimetr(adrBit, BEGIN_ADR_BIT, END_ADR_BIT);
}//privateGetReg2(int adrReg)
