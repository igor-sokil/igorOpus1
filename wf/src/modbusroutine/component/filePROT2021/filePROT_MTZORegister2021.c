
#include "header.h"

int privateMTZOvalidRecordLen(int recordNumber, int recordLen);
int privateMTZOSelUstRecordNumber(int recordNumber);
int privateMTZOSelCountGroupBitRecordNumber(int recordNumber);
int getFileMTZORegister20(int recordNumber, int registerNumber, int recordLen);
int setFileMTZORegister21(int recordNumber, int recordLen, unsigned short *dataPacket);
int postFileMTZORegister21(int recordNumber, int recordLen, unsigned short *dataPacket);

int privateMTZOSelUstRecordNumber(int recordNumber)
{
  if(recordNumber == 2) return 1;
  if((recordNumber >= 5 && recordNumber <= 14)) return 1;
  if((recordNumber >= 105 && recordNumber <= 119)) return 1;

  if(recordNumber == 202) return 1;
  if((recordNumber >= 205 && recordNumber <= 214)) return 1;

  if(recordNumber == 302) return 1;
  if((recordNumber >= 305 && recordNumber <= 314)) return 1;
  return 0;
}//privateMTZOvalidRecordNumber

int privateMTZOvalidRecordLen(int recordNumber, int recordLen)
{
//валидация recordLen
  switch(recordNumber)
  {
  case 0:
  case 1:
  case 2:
  case 101:
  case 201: case 202:
  case 301: case 302:
    if(recordLen>2) return MARKER_ERRORPERIMETR;
    break;
  default:
    if(recordLen>5) return MARKER_ERRORPERIMETR;
  }//switch
  return 0;
}//privateMTZOvalidRecordLen

int privateMTZOSelCountGroupBitRecordNumber(int recordNumber)
{
  switch(recordNumber)
  {
   case 1:
   case 201:
    return 3;//к-сть Group біт
   case 101:
    return 5;//к-сть Group біт
   case 301:
    return 7;//к-сть Group біт
  }//switch
  return -1;
}//privateMTZOSelCountGroupBitRecordNumber
////-GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET-

int getFileMTZORegister20(int recordNumber, int registerNumber, int recordLen)
{
//валидация recordLen
  if(privateMTZOvalidRecordLen(recordNumber, recordLen) != 0) return MARKER_ERRORPERIMETR;
  if(registerNumber == 0) return 0;

  int  countGroupBit = privateMTZOSelCountGroupBitRecordNumber(recordNumber);//к-сть Group біт

  if(recordNumber == 0) return GET_UPR_REGISTER000FOR20(FILEPROT_MTZOREGISTER2021);

  else if(countGroupBit > 0)
  {
    return GET_GROUPUPR_REGISTER000FOR20(FILEPROT_MTZOREGISTER2021);
  }//if(countGroupBit>0)
  else if(privateMTZOSelUstRecordNumber(recordNumber))
  {
    return GET_UST_REGISTER000FOR20(FILEPROT_MTZOREGISTER2021);
  }

  return MARKER_ERRORPERIMETR;
}//getFileMTZORegister20

////-SET--SET--SET--SET--SET--SET--SET--SET--SET--SET--SET--SET-
int setFileMTZORegister21(int recordNumber, int recordLen, unsigned short *dataPacket)
{
//валидация recordLen
  if(privateMTZOvalidRecordLen(recordNumber, recordLen) != 0) return MARKER_ERRORPERIMETR;

  for(int registerNumber=0; registerNumber<recordLen; registerNumber++)
  {
    if(registerNumber == 0) continue;

    uint32_t value = (unsigned short) swapByteInShort(dataPacket[registerNumber]);
    int  countGroupBit = privateMTZOSelCountGroupBitRecordNumber(recordNumber);//к-сть Group біт

    if(recordNumber == 0)
    {
      if(SET_UPR_REGISTER000FOR21(FILEPROT_MTZOREGISTER2021) != 0) return MARKER_ERRORDIAPAZON;
    }//if

    else if(countGroupBit > 0)
    {
      if(SET_GROUPUPR_REGISTER000FOR21(FILEPROT_MTZOREGISTER2021) != 0) return MARKER_ERRORDIAPAZON;
    }//if(countGroupBit>0)

    else if(privateMTZOSelUstRecordNumber(recordNumber))
    {
      if(SET_UST_REGISTER000FOR21(FILEPROT_MTZOREGISTER2021) != 0) return MARKER_ERRORDIAPAZON;
    }//if
    else return MARKER_ERRORPERIMETR;

  }//for
  return 0;
}//setFileMTZORegister21

////-POST--POST--POST--POST--POST--POST--POST--POST--POST--POST--POST-
int postFileMTZORegister21(int recordNumber, int recordLen, unsigned short *dataPacket)
{
  extern int upravlSetting;//флаг Setting
  for(int registerNumber=0; registerNumber<recordLen; registerNumber++)
  {
    if(registerNumber == 0) continue;

    int  countGroupBit = privateMTZOSelCountGroupBitRecordNumber(recordNumber);//к-сть Group біт

    uint32_t value = (unsigned short) swapByteInShort(dataPacket[registerNumber]);

    if(recordNumber == 0)
    {
      int errorV = POST_UPR_REGISTER000FOR21(FILEPROT_MTZOREGISTER2021);
      if(errorV == 1) continue;
      if(errorV != 0) return errorV;
    }//if

    else if(countGroupBit>0)
    {
      int errorV = POST_GROUPUPR_REGISTER000FOR21(FILEPROT_MTZOREGISTER2021);
      if(errorV != 0) return errorV;
    }//if(countGroupBit>0)

    else if(privateMTZOSelUstRecordNumber(recordNumber))
    {
      int errorV = POST_UST_REGISTER000FOR21(FILEPROT_MTZOREGISTER2021);
      if(errorV == 1) continue;
    }//if
  }//for

  return 0;
}//postFileMTZORegister21
