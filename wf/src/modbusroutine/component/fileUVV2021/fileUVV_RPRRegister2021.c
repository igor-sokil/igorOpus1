
#include "header.h"

int privateRPRvalidRecordLen(int recordNumber, int recordLen);
int getFileRPRRegister20(int recordNumber, int registerNumber, int recordLen);
int setFileRPRRegister21(int recordNumber, int recordLen, unsigned short *dataPacket);
int postFileRPRRegister21(int recordNumber, int recordLen, unsigned short *dataPacket);

int getRPRSmallModbusBeginAdrRegister(void);
int getRPRSmallModbusEndAdrRegister(void);

//�-�� RPR
#define REGISTERS_RPR ((M_ADDRESS_LAST_USER_REGISTER_DATA - M_ADDRESS_FIRST_USER_REGISTER_DATA) + 1)

/**************************************/
//���������� ���������� ���������������� ��������
/**************************************/

int privateRPRvalidRecordLen(int recordNumber, int recordLen)
{
 //��������� recordNumber
  if(recordNumber == 0) return MARKER_ERRORPERIMETR;
  if(recordNumber > REGISTERS_RPR) return MARKER_ERRORPERIMETR;
 //��������� recordLen
  if(recordLen > 2) return MARKER_ERRORPERIMETR;
  return 0;
}//privateRPRvalidRecordLen

////-GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET-

int getFileRPRRegister20(int recordNumber, int registerNumber, int recordLen)
{
 //��������� recordLen recordNumber
 if(privateRPRvalidRecordLen(recordNumber, recordLen) != 0) return MARKER_ERRORPERIMETR;
 if(registerNumber == 0) return 0;

  return (current_settings_interfaces.user_register[recordNumber-1]) &0xFFFF;
}//getFileRPRRegister20

////-SET--SET--SET--SET--SET--SET--SET--SET--SET--SET--SET--SET-
int setFileRPRRegister21(int recordNumber, int recordLen, unsigned short *dataPacket)
{
 //��������� recordLen recordNumber
 if(privateRPRvalidRecordLen(recordNumber, recordLen) != 0) return MARKER_ERRORPERIMETR;

 for(int registerNumber=0; registerNumber<recordLen; registerNumber++)
 {
   if(registerNumber == 0) continue;
   uint32_t value = (unsigned short) swapByteInShort(dataPacket[registerNumber]);

//������ ���������� ������ small ����������
  if((value >= (uint32_t)getRPRSmallModbusBeginAdrRegister()) &&
     (value <= (uint32_t)getRPRSmallModbusEndAdrRegister()  )) return MARKER_ERRORDIAPAZON;

 }//for
 return 0;
}//setFileRPRRegister21

////-POST--POST--POST--POST--POST--POST--POST--POST--POST--POST--POST-
int postFileRPRRegister21(int recordNumber, int recordLen, unsigned short *dataPacket)
{
 extern int upravlSetting;
 for(int registerNumber=0; registerNumber<recordLen; registerNumber++)//������ ���������
 {
   if(registerNumber == 0) continue;
   uint32_t value = (unsigned short) swapByteInShort(dataPacket[registerNumber]);

    edition_settings.user_register[recordNumber-1] = value;//����� ��������
 }//for
  //��������� ������� - ���������
     upravlSetting = 2;//���� Setting
     type_of_settings_changed |= (1 << USER_REGISTRY_CHANGED_BIT);

 return 0;
}//postFileRPRRegister21
