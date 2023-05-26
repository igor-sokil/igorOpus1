
#include "header.h"

int privateJAPVvalidRecordLen(int recordNumber, int recordLen);
int privateJAPVSelCountGroupBitRecordNumber(int recordNumber);
int getFileJAPVRegister20(int recordNumber, int registerNumber, int recordLen);
int setFileJAPVRegister21(int recordNumber, int recordLen, unsigned short *dataPacket);
int postFileJAPVRegister21(int recordNumber, int recordLen, unsigned short *dataPacket);

int privateJAPVvalidRecordLen(int recordNumber, int recordLen)
{
//валидация recordLen
  UNUSED(recordNumber);
  if(recordLen > 2) return MARKER_ERRORPERIMETR;
  return 0;
}//privateJAPVvalidRecordLen

int privateJAPVSelCountGroupBitRecordNumber(int recordNumber)
{
  if((recordNumber == 1) || (recordNumber == 101))
    return 1;//к-сть Group біт
  return -1;
}//privateJAPVSelCountGroupBitRecordNumber
////-GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET-

int getFileJAPVRegister20(int recordNumber, int registerNumber, int recordLen)
{
//валидация recordLen
  if(privateJAPVvalidRecordLen(recordNumber, recordLen) != 0) return MARKER_ERRORPERIMETR;
  if(registerNumber == 0) return 0;

  int  countGroupBit = privateJAPVSelCountGroupBitRecordNumber(recordNumber);//к-сть Group біт

  if(countGroupBit > 0)
  {
    return GET_GROUPUPR_REGISTER000FOR20(FILEPROT_JAPVREGISTER2021);
  }//if(countGroupBit>0)

  return MARKER_ERRORPERIMETR;
}//getFileJAPVRegister20

////-SET--SET--SET--SET--SET--SET--SET--SET--SET--SET--SET--SET-
int setFileJAPVRegister21(int recordNumber, int recordLen, unsigned short *dataPacket)
{
//валидация recordLen
  if(privateJAPVvalidRecordLen(recordNumber, recordLen) != 0) return MARKER_ERRORPERIMETR;

  for(int registerNumber=0; registerNumber<recordLen; registerNumber++)
  {
    if(registerNumber == 0) continue;

    uint32_t value = (unsigned short) swapByteInShort(dataPacket[registerNumber]);
    int  countGroupBit = privateJAPVSelCountGroupBitRecordNumber(recordNumber);//к-сть Group біт

    if(recordNumber == 0)
    {
      if(SET_UPR_REGISTER000FOR21(FILEPROT_JAPVREGISTER2021) != 0) return MARKER_ERRORDIAPAZON;
    }//if

    else if(countGroupBit > 0)
    {
      if(SET_GROUPUPR_REGISTER000FOR21(FILEPROT_JAPVREGISTER2021) != 0) return MARKER_ERRORDIAPAZON;
    }//if(countGroupBit>0)

    else return MARKER_ERRORPERIMETR;

  }//for
  return 0;
}//setFileJAPVRegister21

////-POST--POST--POST--POST--POST--POST--POST--POST--POST--POST--POST-
int postFileJAPVRegister21(int recordNumber, int recordLen, unsigned short *dataPacket)
{
  for(int registerNumber=0; registerNumber<recordLen; registerNumber++)
  {
    if(registerNumber == 0) continue;

    int  countGroupBit = privateJAPVSelCountGroupBitRecordNumber(recordNumber);//к-сть Group біт

    uint32_t value = (unsigned short) swapByteInShort(dataPacket[registerNumber]);

    if(countGroupBit > 0)
    {
      int errorV = POST_GROUPUPR_REGISTER000FOR21(FILEPROT_JAPVREGISTER2021);
      if(errorV != 0) return errorV;
    }//if(countGroupBit>0)

  }//for


  return 0;
}//postFileJAPVRegister21
