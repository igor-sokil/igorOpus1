
#include "header.h"

int privatePKV3validRecordLen(int recordNumber, int recordLen);
int privatePKV3SelUstRecordNumber(int recordNumber);
int getFilePKV3Register20(int recordNumber, int registerNumber, int recordLen);
int setFilePKV3Register21(int recordNumber, int recordLen, unsigned short *dataPacket);
int postFilePKV3Register21(int recordNumber, int recordLen, unsigned short *dataPacket);

int privatePKV3SelUstRecordNumber(int recordNumber)
{
  if((recordNumber >= 1) && (recordNumber <= 10)) return 1;
  return 0;
}//privatePKV3SelUstRecordNumber

int privatePKV3validRecordLen(int recordNumber, int recordLen)
{
//��������� recordLen
  if(recordNumber != 14)
  {
    if(recordLen > 2) return MARKER_ERRORPERIMETR;
  }//if
  else
  {
    if(recordLen > 3) return MARKER_ERRORPERIMETR;
  }//if
  return 0;
}//privatePKV3validRecordLen

////-GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET-

int getFilePKV3Register20(int recordNumber, int registerNumber, int recordLen)
{
//��������� recordLen
  if(privatePKV3validRecordLen(recordNumber, recordLen) != 0) return MARKER_ERRORPERIMETR;
  if(registerNumber == 0) return 0;

  if(privatePKV3SelUstRecordNumber(recordNumber))
  {
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    switch(recordNumber)
    {
    case 1://������� ����
      return (edition_settings.time_zone &0xFFFF)*60;
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    case 2://������� �� ������/������ �����
      return (edition_settings.dst & MASKA_FOR_BIT(N_BIT_TZ_DST)) ? 1 : 0;
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    case 3://����� �������� �� ������ �����
      return (edition_settings.dst_on_rule>>POS_MM)&((int)(pow(2,SHIFT_MM)-1));
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    case 4://������ ������ �������� �� ������ �����
      return (edition_settings.dst_on_rule>>POS_DOW)&((int)(pow(2,SHIFT_DOW)-1));
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    case 5://���� ������ �������� �� ������ �����
      return (edition_settings.dst_on_rule>>POS_WR)&((int)(pow(2,SHIFT_WR)-1));
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    case 6://��� ������ �������� �� ������ �����
      return (edition_settings.dst_on_rule>>POS_HH)&((int)(pow(2,SHIFT_HH)-1));
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    case 7://����� �������� �� ������ �����
      return (edition_settings.dst_off_rule>>POS_MM)&((int)(pow(2,SHIFT_MM)-1));
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    case 8://������ ������ �������� �� ������ �����
      return (edition_settings.dst_off_rule>>POS_DOW)&((int)(pow(2,SHIFT_DOW)-1));
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    case 9://���� ������ �������� �� ������ �����
      return (edition_settings.dst_off_rule>>POS_WR)&((int)(pow(2,SHIFT_WR)-1));
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    case 10://��� ������ �������� �� ������ �����
      return (edition_settings.dst_off_rule>>POS_HH)&((int)(pow(2,SHIFT_HH)-1));
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    }//switch
  }//if

  return MARKER_ERRORPERIMETR;
}//getFilePKV3Register20

////-SET--SET--SET--SET--SET--SET--SET--SET--SET--SET--SET--SET-
int setFilePKV3Register21(int recordNumber, int recordLen, unsigned short *dataPacket)
{
//��������� recordLen
  if(privatePKV3validRecordLen(recordNumber, recordLen) != 0) return MARKER_ERRORPERIMETR;

  for(int registerNumber=0; registerNumber<recordLen; registerNumber++)
  {
    if(registerNumber == 0) continue;

    uint32_t value = (unsigned short) swapByteInShort(dataPacket[registerNumber]);

    if(privatePKV3SelUstRecordNumber(recordNumber))
    {
//- - - - - - - - - - - - - - - - - - - - - - - - - - 
      if(recordNumber == 1)//(*editValue) = (uint32_t*)&edition_settings.time_zone;
      {
        //������� ����
        if(value>64000 && value<65536+(TIME_ZONE_MIN*60)) return MARKER_ERRORDIAPAZON;
        if(value<64000 && value>(TIME_ZONE_MAX*60)) return MARKER_ERRORDIAPAZON;
        continue;
      }//if
//- - - - - - - - - - - - - - - - - - - - - - - - - - 
    }//if

    else return MARKER_ERRORPERIMETR;

  }//for
  return 0;
}//setFilePKV3Register21

////-POST--POST--POST--POST--POST--POST--POST--POST--POST--POST--POST-
int postFilePKV3Register21(int recordNumber, int recordLen, unsigned short *dataPacket)
{
  extern int upravlSetting;
  for(int registerNumber=0; registerNumber<recordLen; registerNumber++)
  {
    if(registerNumber == 0) continue;

    uint32_t value = (unsigned short) swapByteInShort(dataPacket[registerNumber]);

    if(privatePKV3SelUstRecordNumber(recordNumber))
    {
////������ ������
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
      switch(recordNumber)
      {
      case 1://������� ����
      {
        if((value%60) >0) return ERROR_VALID2;//�������� ��������� 60
        edition_settings.time_zone = value/60;
        upravlSetting = 1;
        continue;
      }//
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
      case 2://������� �� ������/������ �����
      {
        if(value > 1) return ERROR_VALID2;
        edition_settings.dst &= (uint32_t)(~(1<<N_BIT_TZ_DST));
        edition_settings.dst |= (value<<N_BIT_TZ_DST);
        upravlSetting = 1;//���� Setting
        continue;
      }//
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
      case 3://����� �������� �� ������ �����
      {
        if(value > DST_RULE_MM_MAX) return ERROR_VALID2;
        if(value < DST_RULE_MM_MIN) return ERROR_VALID2;
        edition_settings.dst_on_rule &= (uint32_t)(~(((1 << SHIFT_MM) - 1)<<POS_MM));
        edition_settings.dst_on_rule |= (value<<POS_MM);
        upravlSetting = 1;//���� Setting
        continue;
      }//
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
      case 4://������ ������ �������� �� ������ �����
      {
        if(value > DST_RULE_DOW_MAX) return ERROR_VALID2;
        edition_settings.dst_on_rule &= (uint32_t)(~(((1 << SHIFT_DOW) - 1)<<POS_DOW));
        edition_settings.dst_on_rule |= (value<<POS_DOW);
        upravlSetting = 1;//���� Setting
        continue;
      }//
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
      case 5://����� ��� ������ ��������  �� ������ �����
      {
        if(value > DST_RULE_DR_MAX) return ERROR_VALID2;
        if(value < DST_RULE_DR_MIN) return ERROR_VALID2;
        edition_settings.dst_on_rule &= (uint32_t)(~(((1 << SHIFT_WR) - 1)<<POS_WR));
        edition_settings.dst_on_rule |= (value<<POS_WR);
        upravlSetting = 1;//���� Setting
        continue;
      }//
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
      case 6://��� ������ �������� �� ������ �����
      {
        if(value > DST_RULE_HH_MAX) return ERROR_VALID2;
        edition_settings.dst_on_rule &= (uint32_t)(~(((1 << SHIFT_HH) - 1)<<POS_HH));
        edition_settings.dst_on_rule |= (value<<POS_HH);
        upravlSetting = 1;//���� Setting
        continue;
      }//
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
      case 7://����� �������� �� ������ �����
      {
        if(value > DST_RULE_MM_MAX) return ERROR_VALID2;
        if(value < DST_RULE_MM_MIN) return ERROR_VALID2;
        edition_settings.dst_off_rule &= (uint32_t)(~(((1 << SHIFT_MM) - 1)<<POS_MM));
        edition_settings.dst_off_rule |= (value<<POS_MM);
        upravlSetting = 1;//���� Setting
        continue;
      }//
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
      case 8://������ ������ �������� �� ������ �����
      {
        if(value > DST_RULE_DOW_MAX) return ERROR_VALID2;
        edition_settings.dst_off_rule &= (uint32_t)(~(((1 << SHIFT_DOW) - 1)<<POS_DOW));
        edition_settings.dst_off_rule |= (value<<POS_DOW);
        upravlSetting = 1;//���� Setting
        continue;
      }//
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
      case 9://����� ��� ������ �������� �� ����������� �����
      {
        if(value > DST_RULE_DR_MAX) return ERROR_VALID2;
        if(value < DST_RULE_DR_MIN) return ERROR_VALID2;
        edition_settings.dst_off_rule &= (uint32_t)(~(((1 << SHIFT_WR) - 1)<<POS_WR));
        edition_settings.dst_off_rule |= (value<<POS_WR);
        upravlSetting = 1;//���� Setting
        continue;
      }//
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
      case 10://��� ������ �������� �� ������ �����
      {
        if(value > DST_RULE_HH_MAX) return ERROR_VALID2;
        edition_settings.dst_off_rule &= (uint32_t)(~(((1 << SHIFT_HH) - 1)<<POS_HH));
        edition_settings.dst_off_rule |= (value<<POS_HH);
        upravlSetting = 1;//���� Setting
        continue;
      }//

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
      }//switch
    }//if

  }//for

  return 0;
}//postFilePKV3Register21
