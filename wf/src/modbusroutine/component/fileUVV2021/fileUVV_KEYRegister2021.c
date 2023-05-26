
#include "header.h"

//к-во ранжир на одном key
#define REGISTERS_KEY 8

int privateKEYvalidRecordLen(int recordNumber, int recordLen);
int privateKEYSelUstRegisterNumber(int registerNumber);
int privateKEYSelRangRegisterNumber(int registerNumber);
int getFileKEYRegister20(int recordNumber, int registerNumber, int recordLen);
int setFileKEYRegister21(int recordNumber, int recordLen, unsigned short *dataPacket);
int postFileKEYRegister21(int recordNumber, int recordLen, unsigned short *dataPacket);

/**************************************/
//подготовка компонента KEY
/**************************************/

int privateKEYvalidRecordLen(int recordNumber, int recordLen)
{
//валидация recordNumber
  if(recordNumber == 0) return MARKER_ERRORPERIMETR;
  if(recordNumber > NUMBER_DEFINED_BUTTONS) return MARKER_ERRORPERIMETR;
//валидация recordLen
  if(recordLen > REGISTERS_KEY+5) return MARKER_ERRORPERIMETR;
  return 0;
}//privateKEYvalidRecordLen

int privateKEYSelUstRegisterNumber(int registerNumber)
{
  if(registerNumber == 1) return 1;
  return 0;
}//privateKEYSelUstRegisterNumber
int privateKEYSelRangRegisterNumber(int registerNumber)
{
  if(registerNumber >= 5) return 1;
  return 0;
}//privateKEYSelRangRegisterNumber

////-GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET-

int getFileKEYRegister20(int recordNumber, int registerNumber, int recordLen)
{
//валидация recordLen recordNumber
  if(privateKEYvalidRecordLen(recordNumber, recordLen) != 0) return MARKER_ERRORPERIMETR;
  if(registerNumber == 0) return 0;

  int item  = recordNumber - 1;

  if(privateKEYSelUstRegisterNumber(registerNumber))
  {
//- - - - - - - - - - - - - - - - - - - - - - - - - - -
    if(edition_settings.buttons_mode & (1<<item)) return 1;
    return 0;
//- - - - - - - - - - - - - - - - - - - - - - - - - - -
  }//if
  else if(privateKEYSelRangRegisterNumber(registerNumber))
  {
    //Ранжирование KEY
    return getRangN_SMALLModbusRegister2021(&current_settings_interfaces.ranguvannja_buttons[item*N_SMALL],
                                            registerNumber-5);
  }//if

  if(registerNumber < 5) return 0;
  return MARKER_ERRORPERIMETR;
}//getFileKEYRegister20

////-SET--SET--SET--SET--SET--SET--SET--SET--SET--SET--SET--SET-
int setFileKEYRegister21(int recordNumber, int recordLen, unsigned short *dataPacket)
{
//валидация recordLen recordNumber
  if(privateKEYvalidRecordLen(recordNumber, recordLen) != 0) return MARKER_ERRORPERIMETR;

  for(int registerNumber=0; registerNumber<recordLen; registerNumber++)
  {
    if(registerNumber == 0) continue;

    uint32_t value = (unsigned short) swapByteInShort(dataPacket[registerNumber]);

    if(privateKEYSelUstRegisterNumber(registerNumber))
    {
//- - - - - - - - - - - - - - - - - - - - - - - - - - -
      //проверкa ust
      if(value > 1) return MARKER_ERRORDIAPAZON;
//- - - - - - - - - - - - - - - - - - - - - - - - - - -
    }//if
    else if(privateKEYSelRangRegisterNumber(registerNumber))
    {
      //Ранжирование KEY
      if(validN_SMALLACMD(value) != 0) return MARKER_ERRORDIAPAZON;

      uint32_t maska = ((uint32_t)edition_settings.buttons_mode)&(1<<(recordNumber-1));
      //проверка на допустимость Режим «Кнопка»
      if(!maska)
      {
        switch((unsigned short)value)
        {
        case 25000://- 1-а гр.уставок    *
        case 25001://- 2-а гр.уставок     *
        case 25002://- 3-а гр.уставок     *
        case 25003://- 4-а гр.уставок     *
/*
        case 25176://-RNG_SMALL_U_BLOCK_ZDZ;
        case 25177://-RNG_SMALL_U_PUSK_ZDZ_VID_DV;

        case 25192://RNG_SMALL_U_BLOCK_ZZ_3U0_1;
        case 25208://RNG_SMALL_U_BLOCK_ZZ_3U0_2;

        case 25336://RNG_SMALL_U_BLOCK_ZZP_U2_1;
        case 25352://RNG_SMALL_U_BLOCK_ZZP_U2_2;

        case 25368://RNG_SMALL_U_BLOCK_UMIN_1;
        case 25384://RNG_SMALL_U_BLOCK_UMIN_2;
        case 25400://RNG_SMALL_U_BLOCK_UMIN_3;

        case 25432://RNG_SMALL_U_BLOCK_UMAX_1;
        case 25448://RNG_SMALL_U_BLOCK_UMAX_2;
        case 25464://RNG_SMALL_U_BLOCK_UMAX_3;

        case 25496://RNG_SMALL_U_BLOCK_UMAX_D;

        case 25544://RNG_SMALL_U_ROZBL_NKN_O;
        case 25545://RNG_SMALL_U_BLOCK_NKN_D;
        case 25546://RNG_SMALL_U_BLOCK_ZMN;

        case 25769://RNG_SMALL_U_BLOCK_ACHR_CHAPV_1;
        case 25784://RNG_SMALL_U_BLOCK_ACHR_CHAPV_2;
        case 25800://RNG_SMALL_U_BLOCK_ACHR_CHAPV_3;
        case 25816://RNG_SMALL_U_BLOCK_ACHR_CHAPV_4;
        case 25832://RNG_SMALL_U_BLOCK_CHAPV_1;
        case 25848://RNG_SMALL_U_BLOCK_CHAPV_2;
        case 25864://RNG_SMALL_U_BLOCK_CHAPV_3;
        case 25880://RNG_SMALL_U_BLOCK_CHAPV_4;

        case 25896://- Блок.УЗ1
        case 25899://- Блок.УЗ2
        case 25902://- Блок.УЗ3
        case 25905://- Блок.УЗ4
        case 25908://- Блок.УЗ5
        case 25911://- Блок.УЗ6
        case 25914://- Блок.УЗ7
        case 25917://- Блок.УЗ8

//        case 26298://RNG_SMALL_RESET_LEDS;
//        case 26299://RNG_SMALL_RESET_RELES;
        case 26304://RNG_SMALL_MISCEVE_DYSTANCIJNE;

        case 26664://RNG_SMALL_U_BLOCK_FVVA;
        case 26667://RNG_SMALL_U_AVTOMAT_TN;
*/
          return MARKER_ERRORPERIMETR; //не прошла валидация
        }//switch
//        if((value >= 26456) && (value <= 26511)) return MARKER_ERRORPERIMETR; //не прошла валидация
      }//if(!maska)
      else
        //проверка на допустимость Режим «Ключ
        switch((unsigned short)value)
        {
//        case 25000://- 1-а гр.уставок    *
//        case 25001://- 2-а гр.уставок     *
//        case 25002://- 3-а гр.уставок     *
//        case 25003://- 4-а гр.уставок     *

//        case 25176://-RNG_SMALL_U_BLOCK_ZDZ;
        case 25177://-RNG_SMALL_U_PUSK_ZDZ_VID_DV;

//        case 25192://RNG_SMALL_U_BLOCK_ZZ_3U0_1;
//        case 25208://RNG_SMALL_U_BLOCK_ZZ_3U0_2;

//        case 25336://RNG_SMALL_U_BLOCK_ZZP_U2_1;
//        case 25352://RNG_SMALL_U_BLOCK_ZZP_U2_2;

//        case 25368://RNG_SMALL_U_BLOCK_UMIN_1;
//        case 25384://RNG_SMALL_U_BLOCK_UMIN_2;
//        case 25400://RNG_SMALL_U_BLOCK_UMIN_3;

//        case 25432://RNG_SMALL_U_BLOCK_UMAX_1;
//        case 25448://RNG_SMALL_U_BLOCK_UMAX_2;
//        case 25464://RNG_SMALL_U_BLOCK_UMAX_3;

//        case 25496://RNG_SMALL_U_BLOCK_UMAX_D;

//        case 25544://RNG_SMALL_U_ROZBL_NKN_O;
//        case 25545://RNG_SMALL_U_BLOCK_NKN_D;
//        case 25546://RNG_SMALL_U_BLOCK_ZMN;

//        case 25769://RNG_SMALL_U_BLOCK_ACHR_CHAPV_1;
//        case 25784://RNG_SMALL_U_BLOCK_ACHR_CHAPV_2;
//        case 25800://RNG_SMALL_U_BLOCK_ACHR_CHAPV_3;
//        case 25816://RNG_SMALL_U_BLOCK_ACHR_CHAPV_4;
//        case 25832://RNG_SMALL_U_BLOCK_CHAPV_1;
//        case 25848://RNG_SMALL_U_BLOCK_CHAPV_2;
//        case 25864://RNG_SMALL_U_BLOCK_CHAPV_3;
//        case 25880://RNG_SMALL_U_BLOCK_CHAPV_4;

//        case 25896://- Блок.УЗ1
//        case 25899://- Блок.УЗ2
//        case 25902://- Блок.УЗ3
//        case 25905://- Блок.УЗ4
//        case 25908://- Блок.УЗ5
//        case 25911://- Блок.УЗ6
//        case 25914://- Блок.УЗ7
//        case 25917://- Блок.УЗ8

        case 26298://RNG_SMALL_RESET_LEDS;
        case 26299://RNG_SMALL_RESET_RELES;
//        case 26304://RNG_SMALL_MISCEVE_DYSTANCIJNE;

//        case 26664://RNG_SMALL_U_BLOCK_FVVA;
        case 26667://RNG_SMALL_U_AVTOMAT_TN;
          return MARKER_ERRORPERIMETR; //не прошла валидация
        }//switch

    }//if
  }//for
  return 0;
}//setFileKEYRegister21

////-POST--POST--POST--POST--POST--POST--POST--POST--POST--POST--POST-
int postFileKEYRegister21(int recordNumber, int recordLen, unsigned short *dataPacket)
{
  extern int upravlSchematic;//флаг Rang
  extern int upravlSetting;//флаг Setting

  int item  = recordNumber - 1;
  for(int registerNumber=0; registerNumber<recordLen; registerNumber++)//номера регистров
  {
    uint32_t value = (unsigned short) swapByteInShort(dataPacket[registerNumber]);
    if(privateKEYSelUstRegisterNumber(registerNumber))
    {
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
      if(value) edition_settings.buttons_mode |= (1<<item);
      else  edition_settings.buttons_mode &= ~(1<<item);

      action_during_changing_button_mode(&current_settings_interfaces, &edition_settings);

      for (unsigned int i = 0; i < N_SMALL; i++)
      {
        edition_settings.ranguvannja_buttons[N_SMALL*item + i] =
          current_settings_interfaces.ranguvannja_buttons[N_SMALL*item + i];
      }//for
//- - - - - - - - - - - - - - - - - - - - - - - - - - -
      upravlSetting = 1;//флаг Setting
      upravlSchematic = 1;//флаг Rang
    }//if
  }//for

  if(recordLen >= 5)
  {
    writeRangN_SMALLModbusRegister2021(&edition_settings.ranguvannja_buttons[item * N_SMALL], &dataPacket[5], recordLen-5);
    //ВАЛИДАЦИЯ УСПЕШНА - УСТАНОВКА
    upravlSchematic = 1;//флаг Rang
  }//if

  return 0;
}//postFileKEYRegister21

