
#include "header.h"

//�-�� ������ �� ����� ����
#define REGISTERS_OUTPUTS 16

int privateDOUTvalidRecordLen(int recordNumber, int recordLen);
int privateDOUTSelUprRegisterNumber(int registerNumber);
int privateDOUTSelRangRegisterNumber(int registerNumber);
int getFileDOUTRegister20(int recordNumber, int registerNumber, int recordLen);
int setFileDOUTRegister21(int recordNumber, int recordLen, unsigned short *dataPacket);
int postFileDOUTRegister21(int recordNumber, int recordLen, unsigned short *dataPacket);

/**************************************/
//���������� ���������� RELE
/**************************************/

int privateDOUTvalidRecordLen(int recordNumber, int recordLen)
{
 //��������� recordNumber
  if(recordNumber == 0) return MARKER_ERRORPERIMETR;
  if(recordNumber > NUMBER_OUTPUTS) return MARKER_ERRORPERIMETR;
 //��������� recordLen
  if(recordLen > REGISTERS_OUTPUTS+5) return MARKER_ERRORPERIMETR;
  return 0;
}//privateDOUTvalidRecordLen

int privateDOUTSelUprRegisterNumber(int registerNumber)
{
  if(registerNumber == 1 || registerNumber == 2) return 1;
  return 0;
}//privateDOUTSelUstRegisterNumber
int privateDOUTSelRangRegisterNumber(int registerNumber)
{
  if(registerNumber >= 5) return 1;
  return 0;
}//privateDOUTSelRangRegisterNumber

////-GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET-

int getFileDOUTRegister20(int recordNumber, int registerNumber, int recordLen)
{
 //��������� recordLen recordNumber
 if(privateDOUTvalidRecordLen(recordNumber, recordLen) != 0) return MARKER_ERRORPERIMETR;
 if(registerNumber == 0) return 0;

 if(privateDOUTSelUprRegisterNumber(registerNumber))
 {
  //��� ����. ��� ����. (�����.)
   return GET_UPR_REGISTER000FOR20(FILEUVV_DOUTREGISTER2021); 
 }//if
 else if(privateDOUTSelRangRegisterNumber(registerNumber))
 {
  //������������ ����.
  return getRangN_BIGModbusRegister2021(&current_settings_interfaces.ranguvannja_outputs[(recordNumber-1)*N_BIG],
                                         registerNumber-5);
 }//if

 if(registerNumber < 5) return 0;
 return MARKER_ERRORPERIMETR;
}//getFileDOUTRegister20

////-SET--SET--SET--SET--SET--SET--SET--SET--SET--SET--SET--SET-
int setFileDOUTRegister21(int recordNumber, int recordLen, unsigned short *dataPacket)
{
 //��������� recordLen recordNumber
 if(privateDOUTvalidRecordLen(recordNumber, recordLen) != 0) return MARKER_ERRORPERIMETR;

 for(int registerNumber=0; registerNumber<recordLen; registerNumber++)
 {
   if(registerNumber == 0) continue;

   uint32_t value = (unsigned short) swapByteInShort(dataPacket[registerNumber]);
   if(privateDOUTSelUprRegisterNumber(registerNumber))
   {
     //���������� ��������
      if(value > 1) return MARKER_ERRORDIAPAZON;
   }//if
   else if(privateDOUTSelRangRegisterNumber(registerNumber))
   {
    //������������1 ����.
     if(validN_BIGACMD(value) != 0) return MARKER_ERRORDIAPAZON;
   }//if
 }//for
 return 0;
}//setFileDOUTRegister21

////-POST--POST--POST--POST--POST--POST--POST--POST--POST--POST--POST-
int postFileDOUTRegister21(int recordNumber, int recordLen, unsigned short *dataPacket)
{
  extern int upravlSchematic;//���� Rang
 for(int registerNumber=0; registerNumber<recordLen; registerNumber++)//������ ���������
 {
   if(registerNumber == 0) continue;
   uint32_t value = (unsigned short) swapByteInShort(dataPacket[registerNumber]);

   if(privateDOUTSelUprRegisterNumber(registerNumber))
   {
    //��� ����.01 ��� ����.01 (�����.)
     int errorV = POST_UPR_REGISTER000FOR21(FILEUVV_DOUTREGISTER2021);

     if(errorV == 1) continue;
     if(errorV != 0) return errorV;
   }//if
 }//for

 if(recordLen>=5)
 {
   writeRangN_BIGModbusRegister2021(&edition_settings.ranguvannja_outputs[(recordNumber-1)*N_BIG], &dataPacket[5], recordLen-5);
   //��������� ������� - ���������
   upravlSchematic = 1;//���� Rang
 }//if

 return 0;
}//postFileDOUTRegister21
