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
