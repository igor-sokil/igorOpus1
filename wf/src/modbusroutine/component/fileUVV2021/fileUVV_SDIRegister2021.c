
#include "header.h"

//�-�� ������ �� ����� sdi
#define REGISTERS_SDI 8

int privateSDIvalidRecordLen(int recordNumber, int recordLen);
int privateSDISelUprRegisterNumber(int registerNumber);
int privateSDISelRangRegisterNumber(int registerNumber);
int getFileSDIRegister20(int recordNumber, int registerNumber, int recordLen);
int setFileSDIRegister21(int recordNumber, int recordLen, unsigned short *dataPacket);
int postFileSDIRegister21(int recordNumber, int recordLen, unsigned short *dataPacket);

/**************************************/
//���������� ���������� SDI
/**************************************/

int privateSDIvalidRecordLen(int recordNumber, int recordLen)
{
 //��������� recordNumber
  if(recordNumber == 0) return MARKER_ERRORPERIMETR;
  if(recordNumber > NUMBER_LEDS) return MARKER_ERRORPERIMETR;
 //��������� recordLen
  if(recordLen > REGISTERS_SDI+5) return MARKER_ERRORPERIMETR;
  return 0;
}//privateSDIvalidRecordLen

int privateSDISelUprRegisterNumber(int registerNumber)
{
  if(registerNumber == 1) return 1;
  return 0;
}//privateSDISelUstRegisterNumber
int privateSDISelRangRegisterNumber(int registerNumber)
{
  if(registerNumber >= 5) return 1;
  return 0;
}//privateSDISelRangRegisterNumber

////-GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET-

int getFileSDIRegister20(int recordNumber, int registerNumber, int recordLen)
{
 //��������� recordLen recordNumber
 if(privateSDIvalidRecordLen(recordNumber, recordLen) != 0) return MARKER_ERRORPERIMETR;
 if(registerNumber == 0) return 0;

 if(privateSDISelUprRegisterNumber(registerNumber))
 {
  //��� ��I
   return GET_UPR_REGISTER000FOR20(FILEUVV_SDIREGISTER2021); 
 }//if
 else if(privateSDISelRangRegisterNumber(registerNumber))
 {
  //������������ ��I.
  return getRangN_BIGModbusRegister2021(&current_settings_interfaces.ranguvannja_leds[(recordNumber-1)*N_BIG],
                                         registerNumber-5);
 }//if

 if(registerNumber < 5) return 0;
 return MARKER_ERRORPERIMETR;
}//getFileSDIRegister20

////-SET--SET--SET--SET--SET--SET--SET--SET--SET--SET--SET--SET-
int setFileSDIRegister21(int recordNumber, int recordLen, unsigned short *dataPacket)
{
 //��������� recordLen recordNumber
 if(privateSDIvalidRecordLen(recordNumber, recordLen) != 0) return MARKER_ERRORPERIMETR;

 for(int registerNumber=0; registerNumber<recordLen; registerNumber++)
 {
   if(registerNumber == 0) continue;
   uint32_t value = (unsigned short) swapByteInShort(dataPacket[registerNumber]);

   if(privateSDISelUprRegisterNumber(registerNumber))
   {
     //���������� ��������
     if(!(value==0 || value==1)) return MARKER_ERRORDIAPAZON;
   }//if
   else if(privateSDISelRangRegisterNumber(registerNumber))
   {
    //������������1 ��I.
     if(validN_BIGACMD(value) != 0) return MARKER_ERRORDIAPAZON;
   }//if
 }//for
 return 0;
}//setFileSDIRegister21

////-POST--POST--POST--POST--POST--POST--POST--POST--POST--POST--POST-
int postFileSDIRegister21(int recordNumber, int recordLen, unsigned short *dataPacket)
{
  extern int upravlSchematic;//���� Rang
 for(int registerNumber=0; registerNumber<recordLen; registerNumber++)//������ ���������
 {
   if(registerNumber == 0) continue;
   uint32_t value = (unsigned short) swapByteInShort(dataPacket[registerNumber]);

   if(privateSDISelUprRegisterNumber(registerNumber))
   {
    //��� ��I.
     int errorV = POST_UPR_REGISTER000FOR21(FILEUVV_SDIREGISTER2021);

     if(errorV == 1) continue;
     if(errorV != 0) return errorV;
   }//if
 }//for

 if(recordLen >= 5)
 {
   writeRangN_BIGModbusRegister2021(&edition_settings.ranguvannja_leds[(recordNumber-1)*N_BIG], &dataPacket[5], recordLen-5);
   //��������� ������� - ���������
   upravlSchematic = 1;//���� Rang
 }//if

 return 0;
}//postFileSDIRegister21
