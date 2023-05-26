
#include "header.h"

int privateDZOvalidRecordLen(int recordNumber, int recordLen);
int privateDZOSelUstRecordNumber(int recordNumber);
int privateDZOSelCountGroupBitRecordNumber(int recordNumber);
int getFileDZORegister20(int recordNumber, int registerNumber, int recordLen);
int setFileDZORegister21(int recordNumber, int recordLen, unsigned short *dataPacket);
int postFileDZORegister21(int recordNumber, int recordLen, unsigned short *dataPacket);

int privateDZOSelUstRecordNumber(int recordNumber)
{
  if((recordNumber >= 6 && recordNumber <= 12)) return 1;
  if((recordNumber >= 105 && recordNumber <= 116)) return 1;
  if((recordNumber >= 205 && recordNumber <= 217)) return 1;
  if((recordNumber >= 306 && recordNumber <= 311)) return 1;
  if(recordNumber == 313) return 1;
  if(recordNumber == 315) return 1;
  return 0;
}//privateDZOvalidRecordNumber

int privateDZOvalidRecordLen(int recordNumber, int recordLen)
{
//валидация recordLen
  switch(recordNumber)
  {
  case 0:
  case 1:
  case 101:
  case 201:
  case 301:
    if(recordLen>2) return MARKER_ERRORPERIMETR;
    break;
  default:
    if(recordLen>5) return MARKER_ERRORPERIMETR;
  }//switch
  return 0;
}//privateDZOvalidRecordLen

int privateDZOSelCountGroupBitRecordNumber(int recordNumber)
{
  if(recordNumber == 1)
    return 5;//к-сть Group біт
  if((recordNumber == 101) || (recordNumber == 201) || (recordNumber == 301))
    return 7;//к-сть Group біт
  return -1;
}//privateDZOSelCountGroupBitRecordNumber
////-GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET-

int getFileDZORegister20(int recordNumber, int registerNumber, int recordLen)
{
//валидация recordLen
  if(privateDZOvalidRecordLen(recordNumber, recordLen) != 0) return MARKER_ERRORPERIMETR;
  if(registerNumber == 0) return 0;

  int  countGroupBit = privateDZOSelCountGroupBitRecordNumber(recordNumber);//к-сть Group біт

  if(recordNumber == 0) return GET_UPR_REGISTER000FOR20(FILEPROT_DZOREGISTER2021);

  else if(countGroupBit > 0)
  {
    return GET_GROUPUPR_REGISTER000FOR20(FILEPROT_DZOREGISTER2021);
  }//if(countGroupBit>0)
  else if(privateDZOSelUstRecordNumber(recordNumber))
    return GET_UST_REGISTER000FOR20(FILEPROT_DZOREGISTER2021);

  return MARKER_ERRORPERIMETR;
}//getFileDZORegister20

////-SET--SET--SET--SET--SET--SET--SET--SET--SET--SET--SET--SET-
int setFileDZORegister21(int recordNumber, int recordLen, unsigned short *dataPacket)
{
//валидация recordLen
  if(privateDZOvalidRecordLen(recordNumber, recordLen) != 0) return MARKER_ERRORPERIMETR;

  for(int registerNumber=0; registerNumber<recordLen; registerNumber++)
  {
    if(registerNumber == 0) continue;

    uint32_t value = (unsigned short) swapByteInShort(dataPacket[registerNumber]);
    int  countGroupBit = privateDZOSelCountGroupBitRecordNumber(recordNumber);//к-сть Group біт

    if(recordNumber == 0)
    {
      if(SET_UPR_REGISTER000FOR21(FILEPROT_DZOREGISTER2021) != 0) return MARKER_ERRORDIAPAZON;
    }//if

    else if(countGroupBit > 0)
    {
      if(SET_GROUPUPR_REGISTER000FOR21(FILEPROT_DZOREGISTER2021) != 0) return MARKER_ERRORDIAPAZON;
    }//if(countGroupBit>0)

    else if(privateDZOSelUstRecordNumber(recordNumber))
    {
      if(SET_UST_REGISTER000FOR21(FILEPROT_DZOREGISTER2021) != 0) return MARKER_ERRORDIAPAZON;
    }//if
    else return MARKER_ERRORPERIMETR;

  }//for
  return 0;
}//setFileDZORegister21

////-POST--POST--POST--POST--POST--POST--POST--POST--POST--POST--POST-
int postFileDZORegister21(int recordNumber, int recordLen, unsigned short *dataPacket)
{
  for(int registerNumber=0; registerNumber<recordLen; registerNumber++)
  {
    if(registerNumber == 0) continue;

    int  countGroupBit = privateDZOSelCountGroupBitRecordNumber(recordNumber);//к-сть Group біт

    uint32_t value = (unsigned short) swapByteInShort(dataPacket[registerNumber]);

    if(recordNumber == 0)
    {
      int errorV = POST_UPR_REGISTER000FOR21(FILEPROT_DZOREGISTER2021);
      if(errorV == 1) continue;
      if(errorV != 0) return errorV;
    }//if

    else if(countGroupBit > 0)
    {
      int errorV = POST_GROUPUPR_REGISTER000FOR21(FILEPROT_DZOREGISTER2021);
      if(errorV != 0) return errorV;
    }//if(countGroupBit>0)

    else if(privateDZOSelUstRecordNumber(recordNumber))
    {
      int errorV = POST_UST_REGISTER000FOR21(FILEPROT_DZOREGISTER2021);
      if(errorV == 1) continue;
    }//if
  }//for


  return 0;
}//postFileDZORegister21
