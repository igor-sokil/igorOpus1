
#include "header.h"

int privateMTZRvalidRecordLen(int recordNumber, int recordLen);
int privateMTZRSelUstRecordNumber(int recordNumber);
int privateMTZRSelCountGroupBitRecordNumber(int recordNumber);
int getFileMTZRRegister20(int recordNumber, int registerNumber, int recordLen);
int setFileMTZRRegister21(int recordNumber, int recordLen, unsigned short *dataPacket);
int postFileMTZRRegister21(int recordNumber, int recordLen, unsigned short *dataPacket);

int privateMTZRSelUstRecordNumber(int recordNumber)
{
  if(recordNumber == 2) return 1;
  if((recordNumber >= 5 && recordNumber <= 13)) return 1;
  if(recordNumber == 102) return 1;
  if((recordNumber >= 105 && recordNumber <= 113)) return 1;
  return 0;
}//privateMTZRvalidRecordNumber

int privateMTZRvalidRecordLen(int recordNumber, int recordLen)
{
//валидация recordLen
  switch(recordNumber)
  {
  case 0:
  case 1:
  case 2:
  case 101:
  case 102:
    if(recordLen>2) return MARKER_ERRORPERIMETR;
    break;
  default:
    if(recordLen>5) return MARKER_ERRORPERIMETR;
  }//switch
  return 0;
}//privateMTZRvalidRecordLen

int privateMTZRSelCountGroupBitRecordNumber(int recordNumber)
{
  switch(recordNumber)
  {
   case 1:
    return 3;//к-сть Group біт
   case 101:
    return 4;//к-сть Group біт
  }//switch
  return -1;
}//privateMTZRSelCountGroupBitRecordNumber
////-GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET-

int getFileMTZRRegister20(int recordNumber, int registerNumber, int recordLen)
{
//валидация recordLen
  if(privateMTZRvalidRecordLen(recordNumber, recordLen) != 0) return MARKER_ERRORPERIMETR;
  if(registerNumber == 0) return 0;

  int  countGroupBit = privateMTZRSelCountGroupBitRecordNumber(recordNumber);//к-сть Group біт

  if(recordNumber == 0) return GET_UPR_REGISTER000FOR20(FILEPROT_MTZRREGISTER2021);

  else if(countGroupBit > 0)
  {
    return GET_GROUPUPR_REGISTER000FOR20(FILEPROT_MTZRREGISTER2021);
  }//if(countGroupBit>0)
  else if(privateMTZRSelUstRecordNumber(recordNumber))
  {
    return GET_UST_REGISTER000FOR20(FILEPROT_MTZRREGISTER2021);
  }

  return MARKER_ERRORPERIMETR;
}//getFileMTZRRegister20

////-SET--SET--SET--SET--SET--SET--SET--SET--SET--SET--SET--SET-
int setFileMTZRRegister21(int recordNumber, int recordLen, unsigned short *dataPacket)
{
//валидация recordLen
  if(privateMTZRvalidRecordLen(recordNumber, recordLen) != 0) return MARKER_ERRORPERIMETR;

  for(int registerNumber=0; registerNumber<recordLen; registerNumber++)
  {
    if(registerNumber == 0) continue;

    uint32_t value = (unsigned short) swapByteInShort(dataPacket[registerNumber]);
    int  countGroupBit = privateMTZRSelCountGroupBitRecordNumber(recordNumber);//к-сть Group біт

    if(recordNumber == 0)
    {
      if(SET_UPR_REGISTER000FOR21(FILEPROT_MTZRREGISTER2021) != 0) return MARKER_ERRORDIAPAZON;
    }//if

    else if(countGroupBit > 0)
    {
      if(SET_GROUPUPR_REGISTER000FOR21(FILEPROT_MTZRREGISTER2021) != 0) return MARKER_ERRORDIAPAZON;
    }//if(countGroupBit>0)

    else if(privateMTZRSelUstRecordNumber(recordNumber))
    {
      if(SET_UST_REGISTER000FOR21(FILEPROT_MTZRREGISTER2021) != 0) return MARKER_ERRORDIAPAZON;
    }//if
    else return MARKER_ERRORPERIMETR;

  }//for
  return 0;
}//setFileMTZRRegister21

////-POST--POST--POST--POST--POST--POST--POST--POST--POST--POST--POST-
int postFileMTZRRegister21(int recordNumber, int recordLen, unsigned short *dataPacket)
{
  extern int upravlSetting;//флаг Setting
  for(int registerNumber=0; registerNumber<recordLen; registerNumber++)
  {
    if(registerNumber == 0) continue;

    int  countGroupBit = privateMTZRSelCountGroupBitRecordNumber(recordNumber);//к-сть Group біт

    uint32_t value = (unsigned short) swapByteInShort(dataPacket[registerNumber]);

    if(recordNumber == 0)
    {
      int errorV = POST_UPR_REGISTER000FOR21(FILEPROT_MTZRREGISTER2021);
      if(errorV == 1) continue;
      if(errorV != 0) return errorV;
    }//if

    else if(countGroupBit>0)
    {
      int errorV = POST_GROUPUPR_REGISTER000FOR21(FILEPROT_MTZRREGISTER2021);
      if(errorV != 0) return errorV;
    }//if(countGroupBit>0)

    else if(privateMTZRSelUstRecordNumber(recordNumber))
    {
      int errorV = POST_UST_REGISTER000FOR21(FILEPROT_MTZRREGISTER2021);
      if(errorV == 1) continue;
    }//if
  }//for

  return 0;
}//postFileMTZRRegister21
