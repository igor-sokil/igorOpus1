
#include "header.h"

//�-�� ������ �� ����� dv
#define REGISTERS_DV 8

int privateDVvalidRecordLen(int recordNumber, int recordLen);
int privateDVSelUprRegisterNumber(int registerNumber);
int privateDVSelUstRegisterNumber(int registerNumber);
int privateDVSelRangRegisterNumber(int registerNumber);
int getFileDVRegister20(int recordNumber, int registerNumber, int recordLen);
int setFileDVRegister21(int recordNumber, int recordLen, unsigned short *dataPacket);
int postFileDVRegister21(int recordNumber, int recordLen, unsigned short *dataPacket);

/**************************************/
//���������� ���������� DV
/**************************************/

int privateDVvalidRecordLen(int recordNumber, int recordLen)
{
 //��������� recordNumber
  if(recordNumber == 0) return MARKER_ERRORPERIMETR;
  if(recordNumber > NUMBER_INPUTS) return MARKER_ERRORPERIMETR;
 //��������� recordLen
  if(recordLen > REGISTERS_DV+5) return MARKER_ERRORPERIMETR;
  return 0;
}//privateDVvalidRecordLen

int privateDVSelUprRegisterNumber(int registerNumber)
{
  if(registerNumber == 1 || registerNumber == 2) return 1;
  return 0;
}//privateDVSelUprRegisterNumber
int privateDVSelUstRegisterNumber(int registerNumber)
{
  if(registerNumber == 3) return 1;
  return 0;
}//privateDVSelUstRegisterNumber
int privateDVSelRangRegisterNumber(int registerNumber)
{
  if(registerNumber >= 5) return 1;
  return 0;
}//privateDVSelRangRegisterNumber

////-GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET-

int getFileDVRegister20(int recordNumber, int registerNumber, int recordLen)
{
 //��������� recordLen recordNumber
 if(privateDVvalidRecordLen(recordNumber, recordLen) != 0) return MARKER_ERRORPERIMETR;
 if(registerNumber == 0) return 0;

 if(privateDVSelUprRegisterNumber(registerNumber))
 {
  //��� ���. ��� ���
   return GET_UPR_REGISTER000FOR20(FILEUVV_DVREGISTER2021); 
 }//if
 else if(privateDVSelUstRegisterNumber(registerNumber))
 {
  //������ ���
   return GET_UST_REGISTER000FOR20(FILEUVV_DVREGISTER2021); 
 }//if
 else if(privateDVSelRangRegisterNumber(registerNumber))
 {
  //������������ ���.
  return getRangN_SMALLModbusRegister2021(&current_settings_interfaces.ranguvannja_inputs[(recordNumber-1)*N_SMALL],
                                         registerNumber-5);
 }//if

 if(registerNumber < 5) return 0;
 return MARKER_ERRORPERIMETR;
}//getFileDVRegister20

////-SET--SET--SET--SET--SET--SET--SET--SET--SET--SET--SET--SET-
int setFileDVRegister21(int recordNumber, int recordLen, unsigned short *dataPacket)
{
 //��������� recordLen recordNumber
 if(privateDVvalidRecordLen(recordNumber, recordLen) != 0) return MARKER_ERRORPERIMETR;

 for(int registerNumber=0; registerNumber<recordLen; registerNumber++)
 {
   if(registerNumber == 0) continue;

   uint32_t value = (unsigned short) swapByteInShort(dataPacket[registerNumber]);

   if(privateDVSelUprRegisterNumber(registerNumber))
   {
     //���������� ��������
      if(value > 1) return MARKER_ERRORDIAPAZON;
   }//if
   else if(privateDVSelRangRegisterNumber(registerNumber))
   {
    //������������1 ���.
     if(validN_SMALLACMD(value) != 0) return MARKER_ERRORDIAPAZON;
   }//if
 }//for
 return 0;
}//setFileDVRegister21

////-POST--POST--POST--POST--POST--POST--POST--POST--POST--POST--POST-
int postFileDVRegister21(int recordNumber, int recordLen, unsigned short *dataPacket)
{
  extern int upravlSetting;//���� Setting
  extern int upravlSchematic;//���� Rang
 for(int registerNumber=0; registerNumber<recordLen; registerNumber++)//������ ���������
 {
   if(registerNumber == 0) continue;
   uint32_t value = (unsigned short) swapByteInShort(dataPacket[registerNumber]);

   if(privateDVSelUprRegisterNumber(registerNumber))
   {
    //��� ���.01 
     int errorV = POST_UPR_REGISTER000FOR21(FILEUVV_DVREGISTER2021);

     if(errorV == 1) continue;
     if(errorV != 0) return errorV;
   }//if
   else if(privateDVSelUstRegisterNumber(registerNumber))
   {
    //������ ���
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
////������ ��������
    int item = recordNumber-1;
    if(value > KOEF_DOPUSK_DV_MAX) return ERROR_VALID2;
    if(!((edition_settings.type_of_input_signal)&(1<<item)))
    {
      //������ ��� ���������
    }//if
    else
    {
      //������ ��� ���������
      if(value < KOEF_DOPUSK_DV_ZMIN_MIN) return ERROR_VALID2;//�� ������ 10 ��
      if((value%10) != 0) return ERROR_VALID2;//����� 10
    }
    upravlSetting = 1;//���� Setting
    edition_settings.dopusk_dv[item] = value;
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

   }//if
   else return MARKER_ERRORPERIMETR;
 }//for

 if(recordLen >= 5)
 {
   writeRangN_SMALLModbusRegister2021(&edition_settings.ranguvannja_inputs[(recordNumber-1)*N_SMALL], &dataPacket[5], recordLen-5);
   //��������� ������� - ���������
   upravlSchematic = 1;//���� Rang
 }//if

 return 0;
}//postFileDVRegister21
