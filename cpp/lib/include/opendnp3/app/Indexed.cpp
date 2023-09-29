#include "header.h"
#include "Indexed.h"

//------------------------------------Indexed_for_AnalogOutputInt16---------------------------------------------------------
void Indexed_for_AnalogOutputInt16_in_Indexed_for_AnalogOutputInt16Over1(Indexed_for_AnalogOutputInt16 *pIndexed_for_AnalogOutputInt16)
{
  AnalogOutputInt16_in_AnalogOutputInt16Over1(&(pIndexed_for_AnalogOutputInt16->value));
  pIndexed_for_AnalogOutputInt16->index = 0;
}

void Indexed_for_AnalogOutputInt16_in_Indexed_for_AnalogOutputInt16Over2(Indexed_for_AnalogOutputInt16 *pIndexed_for_AnalogOutputInt16,
    AnalogOutputInt16* value_, uint16_t index_)
{
//  AnalogOutputInt16_in_AnalogOutputInt16Over2(value_, index_);
  pIndexed_for_AnalogOutputInt16->value = *value_;

//// : value(value_), index(index_) {}
//  pIndexed_for_AnalogOutputInt16->value = value_;
  pIndexed_for_AnalogOutputInt16->index = index_;
}

////template<class T> Indexed<T> WithIndex(const T& value, uint16_t index)
Indexed_for_AnalogOutputInt16 WithIndex_in_Indexed_for_AnalogOutputInt16(
  AnalogOutputInt16* value, uint16_t index)
{
  Indexed_for_AnalogOutputInt16 iIndexed_for_AnalogOutputInt16;
  Indexed_for_AnalogOutputInt16_in_Indexed_for_AnalogOutputInt16Over2(&iIndexed_for_AnalogOutputInt16,
      value, index);
////    return Indexed<T>(value, index);
  return iIndexed_for_AnalogOutputInt16;
}
//------------------------------------Indexed_for_AnalogOutputInt16---------------------------------------------------------
//------------------------------------Indexed_for_AnalogOutputInt32---------------------------------------------------------
void Indexed_for_AnalogOutputInt32_in_Indexed_for_AnalogOutputInt32Over1(Indexed_for_AnalogOutputInt32 *pIndexed_for_AnalogOutputInt32)
{
  AnalogOutputInt32_in_AnalogOutputInt32Over1(&(pIndexed_for_AnalogOutputInt32->value));
  pIndexed_for_AnalogOutputInt32->index = 0;
}

void Indexed_for_AnalogOutputInt32_in_Indexed_for_AnalogOutputInt32Over2(Indexed_for_AnalogOutputInt32 *pIndexed_for_AnalogOutputInt32,
    AnalogOutputInt32* value_, uint16_t index_)
{
//  AnalogOutputInt32_in_AnalogOutputInt32Over2(value_, index_);
  pIndexed_for_AnalogOutputInt32->value = *value_;

//// : value(value_), index(index_) {}
//  pIndexed_for_AnalogOutputInt32->value = value_;
  pIndexed_for_AnalogOutputInt32->index = index_;
}

////template<class T> Indexed<T> WithIndex(const T& value, uint16_t index)
Indexed_for_AnalogOutputInt32 WithIndex_in_Indexed_for_AnalogOutputInt32(
  AnalogOutputInt32* value, uint16_t index)
{
  Indexed_for_AnalogOutputInt32 iIndexed_for_AnalogOutputInt32;
  Indexed_for_AnalogOutputInt32_in_Indexed_for_AnalogOutputInt32Over2(&iIndexed_for_AnalogOutputInt32,
      value, index);
////    return Indexed<T>(value, index);
  return iIndexed_for_AnalogOutputInt32;
}
//------------------------------------Indexed_for_AnalogOutputInt32---------------------------------------------------------
//------------------------------------Indexed_for_AnalogOutputFloat32---------------------------------------------------------
void Indexed_for_AnalogOutputFloat32_in_Indexed_for_AnalogOutputFloat32Over1(Indexed_for_AnalogOutputFloat32 *pIndexed_for_AnalogOutputFloat32)
{
  AnalogOutputFloat32_in_AnalogOutputFloat32Over1(&(pIndexed_for_AnalogOutputFloat32->value));
  pIndexed_for_AnalogOutputFloat32->index = 0;
}

void Indexed_for_AnalogOutputFloat32_in_Indexed_for_AnalogOutputFloat32Over2(Indexed_for_AnalogOutputFloat32 *pIndexed_for_AnalogOutputFloat32,
    AnalogOutputFloat32* value_, uint16_t index_)
{
//  AnalogOutputFloat32_in_AnalogOutputFloat32Over2(value_, index_);
  pIndexed_for_AnalogOutputFloat32->value = *value_;

//// : value(value_), index(index_) {}
//  pIndexed_for_AnalogOutputFloat32->value = value_;
  pIndexed_for_AnalogOutputFloat32->index = index_;
}

////template<class T> Indexed<T> WithIndex(const T& value, uint16_t index)
Indexed_for_AnalogOutputFloat32 WithIndex_in_Indexed_for_AnalogOutputFloat32(
  AnalogOutputFloat32* value, uint16_t index)
{
  Indexed_for_AnalogOutputFloat32 iIndexed_for_AnalogOutputFloat32;
  Indexed_for_AnalogOutputFloat32_in_Indexed_for_AnalogOutputFloat32Over2(&iIndexed_for_AnalogOutputFloat32,
      value, index);
////    return Indexed<T>(value, index);
  return iIndexed_for_AnalogOutputFloat32;
}
//------------------------------------Indexed_for_AnalogOutputFloat32---------------------------------------------------------
//------------------------------------Indexed_for_AnalogOutputDouble64---------------------------------------------------------
void Indexed_for_AnalogOutputDouble64_in_Indexed_for_AnalogOutputDouble64Over1(Indexed_for_AnalogOutputDouble64 *pIndexed_for_AnalogOutputDouble64)
{
  AnalogOutputDouble64_in_AnalogOutputDouble64Over1(&(pIndexed_for_AnalogOutputDouble64->value));
  pIndexed_for_AnalogOutputDouble64->index = 0;
}

void Indexed_for_AnalogOutputDouble64_in_Indexed_for_AnalogOutputDouble64Over2(Indexed_for_AnalogOutputDouble64 *pIndexed_for_AnalogOutputDouble64,
    AnalogOutputDouble64* value_, uint16_t index_)
{
//  AnalogOutputDouble64_in_AnalogOutputDouble64Over2(value_, index_);
  pIndexed_for_AnalogOutputDouble64->value = *value_;

//// : value(value_), index(index_) {}
//  pIndexed_for_AnalogOutputDouble64->value = value_;
  pIndexed_for_AnalogOutputDouble64->index = index_;
}

////template<class T> Indexed<T> WithIndex(const T& value, uint16_t index)
Indexed_for_AnalogOutputDouble64 WithIndex_in_Indexed_for_AnalogOutputDouble64(
  AnalogOutputDouble64* value, uint16_t index)
{
  Indexed_for_AnalogOutputDouble64 iIndexed_for_AnalogOutputDouble64;
  Indexed_for_AnalogOutputDouble64_in_Indexed_for_AnalogOutputDouble64Over2(&iIndexed_for_AnalogOutputDouble64,
      value, index);
////    return Indexed<T>(value, index);
  return iIndexed_for_AnalogOutputDouble64;
}
//------------------------------------Indexed_for_AnalogOutputDouble64---------------------------------------------------------
//------------------------------------Indexed_for_IINValue---------------------------------------------------------
void Indexed_for_IINValue_in_Indexed_for_IINValueOver1(Indexed_for_IINValue *pIndexed_for_IINValue)
{
  IINValue_in_IINValueOver1(&(pIndexed_for_IINValue->value));
  pIndexed_for_IINValue->index = 0;
}

void Indexed_for_IINValue_in_Indexed_for_IINValueOver2(Indexed_for_IINValue *pIndexed_for_IINValue,
    IINValue* value_, uint16_t index_)
{
//  IINValue_in_IINValueOver2(value_, index_);
  pIndexed_for_IINValue->value = *value_;

//// : value(value_), index(index_) {}
  pIndexed_for_IINValue->index = index_;
}

////template<class T> Indexed<T> WithIndex(const T& value, uint16_t index)
Indexed_for_IINValue WithIndex_in_Indexed_for_IINValue(
  IINValue* value, uint16_t index)
{
  Indexed_for_IINValue iIndexed_for_IINValue;
  Indexed_for_IINValue_in_Indexed_for_IINValueOver2(&iIndexed_for_IINValue,
      value, index);
////    return Indexed<T>(value, index);
  return iIndexed_for_IINValue;
}
//------------------------------------Indexed_for_IINValue---------------------------------------------------------
//------------------------------------Indexed_for_TimeAndInterval---------------------------------------------------------
void Indexed_for_TimeAndInterval_in_Indexed_for_TimeAndIntervalOver1(Indexed_for_TimeAndInterval *pIndexed_for_TimeAndInterval)
{
  TimeAndInterval_in_TimeAndIntervalOver1(&(pIndexed_for_TimeAndInterval->value));
  pIndexed_for_TimeAndInterval->index = 0;
}

void Indexed_for_TimeAndInterval_in_Indexed_for_TimeAndIntervalOver2(Indexed_for_TimeAndInterval *pIndexed_for_TimeAndInterval,
    TimeAndInterval* value_, uint16_t index_)
{
//  TimeAndInterval_in_TimeAndIntervalOver2(value_, index_);
  pIndexed_for_TimeAndInterval->value = *value_;

//// : value(value_), index(index_) {}
  pIndexed_for_TimeAndInterval->index = index_;
}

////template<class T> Indexed<T> WithIndex(const T& value, uint16_t index)
Indexed_for_TimeAndInterval WithIndex_in_Indexed_for_TimeAndInterval(
  TimeAndInterval* value, uint16_t index)
{
  Indexed_for_TimeAndInterval iIndexed_for_TimeAndInterval;
  Indexed_for_TimeAndInterval_in_Indexed_for_TimeAndIntervalOver2(&iIndexed_for_TimeAndInterval,
      value, index);
////    return Indexed<T>(value, index);
  return iIndexed_for_TimeAndInterval;
}
//------------------------------------Indexed_for_TimeAndInterval---------------------------------------------------------
//------------------------------------Indexed_for_ControlRelayOutputBlock---------------------------------------------------------
void Indexed_for_ControlRelayOutputBlock_in_Indexed_for_ControlRelayOutputBlockOver1(Indexed_for_ControlRelayOutputBlock *pIndexed_for_ControlRelayOutputBlock)
{
//   ControlRelayOutputBlock_in_ControlRelayOutputBlockOver1(&(pIndexed_for_ControlRelayOutputBlock->value));
  ControlRelayOutputBlock_in_ControlRelayOutputBlockOver1(&(pIndexed_for_ControlRelayOutputBlock->value),
      OperationType_LATCH_ON,
      TripCloseCode_NUL,
      false,
      1,
      100,
      100,
      CommandStatus_SUCCESS);
  pIndexed_for_ControlRelayOutputBlock->index = 0;
}

void Indexed_for_ControlRelayOutputBlock_in_Indexed_for_ControlRelayOutputBlockOver2(Indexed_for_ControlRelayOutputBlock *pIndexed_for_ControlRelayOutputBlock,
    ControlRelayOutputBlock* value_, uint16_t index_)
{
//  ControlRelayOutputBlock_in_ControlRelayOutputBlockOver2(value_, index_);
  pIndexed_for_ControlRelayOutputBlock->value = *value_;

//// : value(value_), index(index_) {}
  pIndexed_for_ControlRelayOutputBlock->index = index_;
}

////template<class T> Indexed<T> WithIndex(const T& value, uint16_t index)
Indexed_for_ControlRelayOutputBlock WithIndex_in_Indexed_for_ControlRelayOutputBlock(
  ControlRelayOutputBlock* value, uint16_t index)
{
  Indexed_for_ControlRelayOutputBlock iIndexed_for_ControlRelayOutputBlock;
  Indexed_for_ControlRelayOutputBlock_in_Indexed_for_ControlRelayOutputBlockOver2(&iIndexed_for_ControlRelayOutputBlock,
      value, index);
////    return Indexed<T>(value, index);
  return iIndexed_for_ControlRelayOutputBlock;
}
//------------------------------------Indexed_for_ControlRelayOutputBlock---------------------------------------------------------
//------------------------------------Indexed_for_Binary---------------------------------------------------------
void Indexed_for_Binary_in_Indexed_for_BinaryOver1(Indexed_for_Binary *pIndexed_for_Binary)
{
  Binary_in_BinaryOver1(&(pIndexed_for_Binary->value));
  pIndexed_for_Binary->index = 0;
}

void Indexed_for_Binary_in_Indexed_for_BinaryOver2(Indexed_for_Binary *pIndexed_for_Binary,
    Binary* value_, uint16_t index_)
{
//  Binary_in_BinaryOver2(value_, index_);
  pIndexed_for_Binary->value = *value_;

//// : value(value_), index(index_) {}
  pIndexed_for_Binary->index = index_;
}

////template<class T> Indexed<T> WithIndex(const T& value, uint16_t index)
Indexed_for_Binary WithIndex_in_Indexed_for_Binary(
  Binary* value, uint16_t index)
{
  Indexed_for_Binary iIndexed_for_Binary;
  Indexed_for_Binary_in_Indexed_for_BinaryOver2(&iIndexed_for_Binary,
      value, index);
////    return Indexed<T>(value, index);
  return iIndexed_for_Binary;
}
//------------------------------------Indexed_for_Binary---------------------------------------------------------
//------------------------------------Indexed_for_DoubleBitBinary---------------------------------------------------------
void Indexed_for_DoubleBitBinary_in_Indexed_for_DoubleBitBinaryOver1(Indexed_for_DoubleBitBinary *pIndexed_for_DoubleBitBinary)
{
  DoubleBitBinary_in_DoubleBitBinaryOver1(&(pIndexed_for_DoubleBitBinary->value));
  pIndexed_for_DoubleBitBinary->index = 0;
}

void Indexed_for_DoubleBitBinary_in_Indexed_for_DoubleBitBinaryOver2(Indexed_for_DoubleBitBinary *pIndexed_for_DoubleBitBinary,
    DoubleBitBinary* value_, uint16_t index_)
{
//  DoubleBitBinary_in_DoubleBitBinaryOver2(value_, index_);
  pIndexed_for_DoubleBitBinary->value = *value_;

//// : value(value_), index(index_) {}
  pIndexed_for_DoubleBitBinary->index = index_;
}

////template<class T> Indexed<T> WithIndex(const T& value, uint16_t index)
Indexed_for_DoubleBitBinary WithIndex_in_Indexed_for_DoubleBitBinary(
  DoubleBitBinary* value, uint16_t index)
{
  Indexed_for_DoubleBitBinary iIndexed_for_DoubleBitBinary;
  Indexed_for_DoubleBitBinary_in_Indexed_for_DoubleBitBinaryOver2(&iIndexed_for_DoubleBitBinary,
      value, index);
////    return Indexed<T>(value, index);
  return iIndexed_for_DoubleBitBinary;
}
//------------------------------------Indexed_for_DoubleBitBinary---------------------------------------------------------
//------------------------------------Indexed_for_BinaryOutputStatus---------------------------------------------------------
void Indexed_for_BinaryOutputStatus_in_Indexed_for_BinaryOutputStatusOver1(Indexed_for_BinaryOutputStatus *pIndexed_for_BinaryOutputStatus)
{
  BinaryOutputStatus_in_BinaryOutputStatusOver1(&(pIndexed_for_BinaryOutputStatus->value));
  pIndexed_for_BinaryOutputStatus->index = 0;
}

void Indexed_for_BinaryOutputStatus_in_Indexed_for_BinaryOutputStatusOver2(Indexed_for_BinaryOutputStatus *pIndexed_for_BinaryOutputStatus,
    BinaryOutputStatus* value_, uint16_t index_)
{
//  BinaryOutputStatus_in_BinaryOutputStatusOver2(value_, index_);
  pIndexed_for_BinaryOutputStatus->value = *value_;

//// : value(value_), index(index_) {}
  pIndexed_for_BinaryOutputStatus->index = index_;
}

////template<class T> Indexed<T> WithIndex(const T& value, uint16_t index)
Indexed_for_BinaryOutputStatus WithIndex_in_Indexed_for_BinaryOutputStatus(
  BinaryOutputStatus* value, uint16_t index)
{
  Indexed_for_BinaryOutputStatus iIndexed_for_BinaryOutputStatus;
  Indexed_for_BinaryOutputStatus_in_Indexed_for_BinaryOutputStatusOver2(&iIndexed_for_BinaryOutputStatus,
      value, index);
////    return Indexed<T>(value, index);
  return iIndexed_for_BinaryOutputStatus;
}
//------------------------------------Indexed_for_BinaryOutputStatus---------------------------------------------------------
//------------------------------------Indexed_for_Counter---------------------------------------------------------
void Indexed_for_Counter_in_Indexed_for_CounterOver1(Indexed_for_Counter *pIndexed_for_Counter)
{
  Counter_in_CounterOver1(&(pIndexed_for_Counter->value));
  pIndexed_for_Counter->index = 0;
}

void Indexed_for_Counter_in_Indexed_for_CounterOver2(Indexed_for_Counter *pIndexed_for_Counter,
    Counter* value_, uint16_t index_)
{
//  Counter_in_CounterOver2(value_, index_);
  pIndexed_for_Counter->value = *value_;

//// : value(value_), index(index_) {}
  pIndexed_for_Counter->index = index_;
}

////template<class T> Indexed<T> WithIndex(const T& value, uint16_t index)
Indexed_for_Counter WithIndex_in_Indexed_for_Counter(
  Counter* value, uint16_t index)
{
  Indexed_for_Counter iIndexed_for_Counter;
  Indexed_for_Counter_in_Indexed_for_CounterOver2(&iIndexed_for_Counter,
      value, index);
////    return Indexed<T>(value, index);
  return iIndexed_for_Counter;
}
//------------------------------------Indexed_for_Counter---------------------------------------------------------
//------------------------------------Indexed_for_FrozenCounter---------------------------------------------------------
void Indexed_for_FrozenCounter_in_Indexed_for_FrozenCounterOver1(Indexed_for_FrozenCounter *pIndexed_for_FrozenCounter)
{
  FrozenCounter_in_FrozenCounterOver1(&(pIndexed_for_FrozenCounter->value));
  pIndexed_for_FrozenCounter->index = 0;
}

void Indexed_for_FrozenCounter_in_Indexed_for_FrozenCounterOver2(Indexed_for_FrozenCounter *pIndexed_for_FrozenCounter,
    FrozenCounter* value_, uint16_t index_)
{
//  FrozenCounter_in_FrozenCounterOver2(value_, index_);
  pIndexed_for_FrozenCounter->value = *value_;

//// : value(value_), index(index_) {}
  pIndexed_for_FrozenCounter->index = index_;
}

////template<class T> Indexed<T> WithIndex(const T& value, uint16_t index)
Indexed_for_FrozenCounter WithIndex_in_Indexed_for_FrozenCounter(
  FrozenCounter* value, uint16_t index)
{
  Indexed_for_FrozenCounter iIndexed_for_FrozenCounter;
  Indexed_for_FrozenCounter_in_Indexed_for_FrozenCounterOver2(&iIndexed_for_FrozenCounter,
      value, index);
////    return Indexed<T>(value, index);
  return iIndexed_for_FrozenCounter;
}
//------------------------------------Indexed_for_FrozenCounter---------------------------------------------------------
//------------------------------------Indexed_for_Analog---------------------------------------------------------
void Indexed_for_Analog_in_Indexed_for_AnalogOver1(Indexed_for_Analog *pIndexed_for_Analog)
{
  Analog_in_AnalogOver1(&(pIndexed_for_Analog->value));
  pIndexed_for_Analog->index = 0;
}

void Indexed_for_Analog_in_Indexed_for_AnalogOver2(Indexed_for_Analog *pIndexed_for_Analog,
    Analog* value_, uint16_t index_)
{
//  Analog_in_AnalogOver2(value_, index_);
  pIndexed_for_Analog->value = *value_;

//// : value(value_), index(index_) {}
  pIndexed_for_Analog->index = index_;
}

////template<class T> Indexed<T> WithIndex(const T& value, uint16_t index)
Indexed_for_Analog WithIndex_in_Indexed_for_Analog(
  Analog* value, uint16_t index)
{
  Indexed_for_Analog iIndexed_for_Analog;
  Indexed_for_Analog_in_Indexed_for_AnalogOver2(&iIndexed_for_Analog,
      value, index);
////    return Indexed<T>(value, index);
  return iIndexed_for_Analog;
}
//------------------------------------Indexed_for_Analog---------------------------------------------------------
//------------------------------------Indexed_for_AnalogOutputStatus---------------------------------------------------------
void Indexed_for_AnalogOutputStatus_in_Indexed_for_AnalogOutputStatusOver1(Indexed_for_AnalogOutputStatus *pIndexed_for_AnalogOutputStatus)
{
  AnalogOutputStatus_in_AnalogOutputStatusOver1(&(pIndexed_for_AnalogOutputStatus->value));
  pIndexed_for_AnalogOutputStatus->index = 0;
}

void Indexed_for_AnalogOutputStatus_in_Indexed_for_AnalogOutputStatusOver2(Indexed_for_AnalogOutputStatus *pIndexed_for_AnalogOutputStatus,
    AnalogOutputStatus* value_, uint16_t index_)
{
//  AnalogOutputStatus_in_AnalogOutputStatusOver2(value_, index_);
  pIndexed_for_AnalogOutputStatus->value = *value_;

//// : value(value_), index(index_) {}
  pIndexed_for_AnalogOutputStatus->index = index_;
}

////template<class T> Indexed<T> WithIndex(const T& value, uint16_t index)
Indexed_for_AnalogOutputStatus WithIndex_in_Indexed_for_AnalogOutputStatus(
  AnalogOutputStatus* value, uint16_t index)
{
  Indexed_for_AnalogOutputStatus iIndexed_for_AnalogOutputStatus;
  Indexed_for_AnalogOutputStatus_in_Indexed_for_AnalogOutputStatusOver2(&iIndexed_for_AnalogOutputStatus,
      value, index);
////    return Indexed<T>(value, index);
  return iIndexed_for_AnalogOutputStatus;
}
//------------------------------------Indexed_for_AnalogOutputStatus---------------------------------------------------------
//------------------------------------Indexed_for_OctetString---------------------------------------------------------
void Indexed_for_OctetString_in_Indexed_for_OctetStringOver1(Indexed_for_OctetString *pIndexed_for_OctetString)
{
  OctetString_in_OctetStringOver1(&(pIndexed_for_OctetString->value));
  pIndexed_for_OctetString->index = 0;
}

void Indexed_for_OctetString_in_Indexed_for_OctetStringOver2(Indexed_for_OctetString *pIndexed_for_OctetString,
    OctetString* value_, uint16_t index_)
{
//  OctetString_in_OctetStringOver2(value_, index_);
  pIndexed_for_OctetString->value = *value_;

//// : value(value_), index(index_) {}
  pIndexed_for_OctetString->index = index_;
}

////template<class T> Indexed<T> WithIndex(const T& value, uint16_t index)
Indexed_for_OctetString WithIndex_in_Indexed_for_OctetString(
  OctetString* value, uint16_t index)
{
  Indexed_for_OctetString iIndexed_for_OctetString;
  Indexed_for_OctetString_in_Indexed_for_OctetStringOver2(&iIndexed_for_OctetString,
      value, index);
////    return Indexed<T>(value, index);
  return iIndexed_for_OctetString;
}
//------------------------------------Indexed_for_OctetString---------------------------------------------------------
//------------------------------------Indexed_for_BinaryCommandEvent---------------------------------------------------------
void Indexed_for_BinaryCommandEvent_in_Indexed_for_BinaryCommandEventOver1(Indexed_for_BinaryCommandEvent *pIndexed_for_BinaryCommandEvent)
{
  BinaryCommandEvent_In_BinaryCommandEventOver1(&(pIndexed_for_BinaryCommandEvent->value));
  pIndexed_for_BinaryCommandEvent->index = 0;
}

void Indexed_for_BinaryCommandEvent_in_Indexed_for_BinaryCommandEventOver2(Indexed_for_BinaryCommandEvent *pIndexed_for_BinaryCommandEvent,
    BinaryCommandEvent* value_, uint16_t index_)
{
//  BinaryCommandEvent_in_BinaryCommandEventOver2(value_, index_);
  pIndexed_for_BinaryCommandEvent->value = *value_;

//// : value(value_), index(index_) {}
  pIndexed_for_BinaryCommandEvent->index = index_;
}

////template<class T> Indexed<T> WithIndex(const T& value, uint16_t index)
Indexed_for_BinaryCommandEvent WithIndex_in_Indexed_for_BinaryCommandEvent(
  BinaryCommandEvent* value, uint16_t index)
{
  Indexed_for_BinaryCommandEvent iIndexed_for_BinaryCommandEvent;
  Indexed_for_BinaryCommandEvent_in_Indexed_for_BinaryCommandEventOver2(&iIndexed_for_BinaryCommandEvent,
      value, index);
////    return Indexed<T>(value, index);
  return iIndexed_for_BinaryCommandEvent;
}
//------------------------------------Indexed_for_BinaryCommandEvent---------------------------------------------------------
//------------------------------------Indexed_for_AnalogCommandEvent---------------------------------------------------------
void Indexed_for_AnalogCommandEvent_in_Indexed_for_AnalogCommandEventOver1(Indexed_for_AnalogCommandEvent *pIndexed_for_AnalogCommandEvent)
{
  AnalogCommandEvent_in_AnalogCommandEventOver1(&(pIndexed_for_AnalogCommandEvent->value));
  pIndexed_for_AnalogCommandEvent->index = 0;
}

void Indexed_for_AnalogCommandEvent_in_Indexed_for_AnalogCommandEventOver2(Indexed_for_AnalogCommandEvent *pIndexed_for_AnalogCommandEvent,
    AnalogCommandEvent* value_, uint16_t index_)
{
//  AnalogCommandEvent_in_AnalogCommandEventOver2(value_, index_);
  pIndexed_for_AnalogCommandEvent->value = *value_;

//// : value(value_), index(index_) {}
  pIndexed_for_AnalogCommandEvent->index = index_;
}

////template<class T> Indexed<T> WithIndex(const T& value, uint16_t index)
Indexed_for_AnalogCommandEvent WithIndex_in_Indexed_for_AnalogCommandEvent(
  AnalogCommandEvent* value, uint16_t index)
{
  Indexed_for_AnalogCommandEvent iIndexed_for_AnalogCommandEvent;
  Indexed_for_AnalogCommandEvent_in_Indexed_for_AnalogCommandEventOver2(&iIndexed_for_AnalogCommandEvent,
      value, index);
////    return Indexed<T>(value, index);
  return iIndexed_for_AnalogCommandEvent;
}
//------------------------------------Indexed_for_AnalogCommandEvent---------------------------------------------------------
//------------------------------------Indexed_for_Group2Var1---------------------------------------------------------
/*
void Indexed_for_Group2Var1_in_Indexed_for_Group2Var1Over1(Indexed_for_Group2Var1 *pIndexed_for_Group2Var1)
{
//   Group2Var1_in_Group2Var1Over1(&(pIndexed_for_Group2Var1->value));
  Group2Var1_in_Group2Var1(&(pIndexed_for_Group2Var1->value));
//                            OperationType_LATCH_ON,
//                            TripCloseCode_NUL,
//                            false,
//                             1,
//                             100,
//                             100,
//                             CommandStatus_SUCCESS);
  pIndexed_for_Group2Var1->index = 0;
}

void Indexed_for_Group2Var1_in_Indexed_for_Group2Var1Over2(Indexed_for_Group2Var1 *pIndexed_for_Group2Var1,
    Group2Var1* value_, uint16_t index_)
{
//  Group2Var1_in_Group2Var1Over2(value_, index_);
  pIndexed_for_Group2Var1->value = *value_;

//// : value(value_), index(index_) {}
  pIndexed_for_Group2Var1->index = index_;
}

////template<class T> Indexed<T> WithIndex(const T& value, uint16_t index)
Indexed_for_Group2Var1 WithIndex_in_Indexed_for_Group2Var1(
  Group2Var1* value, uint16_t index)
{
  Indexed_for_Group2Var1 iIndexed_for_Group2Var1;
  Indexed_for_Group2Var1_in_Indexed_for_Group2Var1Over2(&iIndexed_for_Group2Var1,
      value, index);
////    return Indexed<T>(value, index);
  return iIndexed_for_Group2Var1;
}
*/
//------------------------------------Indexed_for_Group2Var1---------------------------------------------------------
//------------------------------------Indexed_for_Group1Var2---------------------------------------------------------
/*
void Indexed_for_Group1Var2_in_Indexed_for_Group1Var2Over1(Indexed_for_Group1Var2 *pIndexed_for_Group1Var2)
{
//   Group1Var2_in_Group1Var2Over1(&(pIndexed_for_Group1Var2->value));
  Group1Var2_in_Group1Var2(&(pIndexed_for_Group1Var2->value));
//                            OperationType_LATCH_ON,
//                            TripCloseCode_NUL,
//                            false,
//                             1,
//                             100,
//                             100,
//                             CommandStatus_SUCCESS);
  pIndexed_for_Group1Var2->index = 0;
}

void Indexed_for_Group1Var2_in_Indexed_for_Group1Var2Over2(Indexed_for_Group1Var2 *pIndexed_for_Group1Var2,
    Group1Var2* value_, uint16_t index_)
{
//  Group1Var2_in_Group1Var2Over2(value_, index_);
  pIndexed_for_Group1Var2->value = *value_;

//// : value(value_), index(index_) {}
  pIndexed_for_Group1Var2->index = index_;
}

////template<class T> Indexed<T> WithIndex(const T& value, uint16_t index)
Indexed_for_Group1Var2 WithIndex_in_Indexed_for_Group1Var2(
  Group1Var2* value, uint16_t index)
{
  Indexed_for_Group1Var2 iIndexed_for_Group1Var2;
  Indexed_for_Group1Var2_in_Indexed_for_Group1Var2Over2(&iIndexed_for_Group1Var2,
      value, index);
////    return Indexed<T>(value, index);
  return iIndexed_for_Group1Var2;
}
*/
//------------------------------------Indexed_for_Group1Var2---------------------------------------------------------
