
#include "header.h"

int privateDZRvalidRecordLen(int recordNumber, int recordLen);
int privateDZRSelUstRecordNumber(int recordNumber);
int privateDZRSelCountGroupBitRecordNumber(int recordNumber);
int getFileDZRRegister20(int recordNumber, int registerNumber, int recordLen);
int setFileDZRRegister21(int recordNumber, int recordLen, unsigned short *dataPacket);
int postFileDZRRegister21(int recordNumber, int recordLen, unsigned short *dataPacket);

int privateDZRSelUstRecordNumber(int recordNumber)
{
  if((recordNumber >= 5 && recordNumber <= 11)) return 1;
  if((recordNumber >= 105 && recordNumber <= 116)) return 1;
  if((recordNumber >= 205 && recordNumber <= 217)) return 1;
  return 0;
}//privateDZRvalidRecordNumber

int privateDZRvalidRecordLen(int recordNumber, int recordLen)
{
//��������� recordLen
  switch(recordNumber)
  {
  case 0:
  case 1:
  case 101:
  case 201:
    if(recordLen>2) return MARKER_ERRORPERIMETR;
    break;
  default:
    if(recordLen>5) return MARKER_ERRORPERIMETR;
  }//switch
  return 0;
}//privateDZRvalidRecordLen

int privateDZRSelCountGroupBitRecordNumber(int recordNumber)
{
  if(recordNumber == 1)
    return 5;//�-��� Group ��
  if((recordNumber == 101) || (recordNumber == 201))
    return 7;//�-��� Group ��
  return -1;
}//privateDZRSelCountGroupBitRecordNumber
////-GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET-

int getFileDZRRegister20(int recordNumber, int registerNumber, int recordLen)
{
//��������� recordLen
  if(privateDZRvalidRecordLen(recordNumber, recordLen) != 0) return MARKER_ERRORPERIMETR;
  if(registerNumber == 0) return 0;

  int  countGroupBit = privateDZRSelCountGroupBitRecordNumber(recordNumber);//�-��� Group ��

  if(recordNumber == 0) return GET_UPR_REGISTER000FOR20(FILEPROT_DZRREGISTER2021);

  else if(countGroupBit > 0)
  {
    return GET_GROUPUPR_REGISTER000FOR20(FILEPROT_DZRREGISTER2021);
  }//if(countGroupBit>0)
  else if(privateDZRSelUstRecordNumber(recordNumber))
    return GET_UST_REGISTER000FOR20(FILEPROT_DZRREGISTER2021);

  return MARKER_ERRORPERIMETR;
}//getFileDZRRegister20

////-SET--SET--SET--SET--SET--SET--SET--SET--SET--SET--SET--SET-
int setFileDZRRegister21(int recordNumber, int recordLen, unsigned short *dataPacket)
{
//��������� recordLen
  if(privateDZRvalidRecordLen(recordNumber, recordLen) != 0) return MARKER_ERRORPERIMETR;

  for(int registerNumber=0; registerNumber<recordLen; registerNumber++)
  {
    if(registerNumber == 0) continue;

    uint32_t value = (unsigned short) swapByteInShort(dataPacket[registerNumber]);
    int  countGroupBit = privateDZRSelCountGroupBitRecordNumber(recordNumber);//�-��� Group ��

    if(recordNumber == 0)
    {
      if(SET_UPR_REGISTER000FOR21(FILEPROT_DZRREGISTER2021) != 0) return MARKER_ERRORDIAPAZON;
    }//if

    else if(countGroupBit > 0)
    {
      if(SET_GROUPUPR_REGISTER000FOR21(FILEPROT_DZRREGISTER2021) != 0) return MARKER_ERRORDIAPAZON;
    }//if(countGroupBit>0)

    else if(privateDZRSelUstRecordNumber(recordNumber))
    {
      if(SET_UST_REGISTER000FOR21(FILEPROT_DZRREGISTER2021) != 0) return MARKER_ERRORDIAPAZON;
    }//if
    else return MARKER_ERRORPERIMETR;

  }//for
  return 0;
}//setFileDZRRegister21

////-POST--POST--POST--POST--POST--POST--POST--POST--POST--POST--POST-
int postFileDZRRegister21(int recordNumber, int recordLen, unsigned short *dataPacket)
{
  for(int registerNumber=0; registerNumber<recordLen; registerNumber++)
  {
    if(registerNumber == 0) continue;

    int  countGroupBit = privateDZRSelCountGroupBitRecordNumber(recordNumber);//�-��� Group ��

    uint32_t value = (unsigned short) swapByteInShort(dataPacket[registerNumber]);

    if(recordNumber == 0)
    {
      int errorV = POST_UPR_REGISTER000FOR21(FILEPROT_DZRREGISTER2021);
      if(errorV == 1) continue;
      if(errorV != 0) return errorV;
    }//if

    else if(countGroupBit > 0)
    {
      int errorV = POST_GROUPUPR_REGISTER000FOR21(FILEPROT_DZRREGISTER2021);
      if(errorV != 0) return errorV;
    }//if(countGroupBit>0)

    else if(privateDZRSelUstRecordNumber(recordNumber))
    {
      int errorV = POST_UST_REGISTER000FOR21(FILEPROT_DZRREGISTER2021);
      if(errorV == 1) continue;
    }//if
  }//for


  return 0;
}//postFileDZRRegister21
