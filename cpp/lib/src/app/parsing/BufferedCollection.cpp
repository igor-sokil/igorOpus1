#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "BufferedCollection.h"

//-----------------------------------uint16---------------------------------------------------
////    BufferedCollection(const ser4cpp::rseq_t& buffer, size_t count, const ReadFunc& readFunc)
////        : buffer(buffer), COUNT(count), readFunc(readFunc)
void  BufferedCollection_uint16_in_BufferedCollection_uint16(
  BufferedCollection_uint16 *pBufferedCollection_uint16,
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_uint16 readFunc)
{
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"BufferedCollection_uint16_in_BufferedCollection_uint16_1"<<std::endl;
  decrement_stack_info();
#endif

  pBufferedCollection_uint16->buffer = *buffer;
  pBufferedCollection_uint16->COUNT = count;
  pBufferedCollection_uint16->readFunc = readFunc;

  pBufferedCollection_uint16->iICollection_for_uint16.pCount_in_ICollection_for_uint16 =
    Count_in_BufferedCollection_uint16_override;
  pBufferedCollection_uint16->iICollection_for_uint16.pForeach_in_ICollection_for_uint16 =
    Foreach_in_BufferedCollection_uint16_override;

  setParentPointer_in_ICollection_for_uint16(&(pBufferedCollection_uint16->iICollection_for_uint16), pBufferedCollection_uint16);
}

////template<class T, class ReadFunc>
////BufferedCollection<T, ReadFunc> CreateBufferedCollection(const ser4cpp::rseq_t& buffer,
////                                                         size_t count,
////                                                         const ReadFunc& readFunc)
BufferedCollection_uint16 CreateBufferedCollection_uint16_static(
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_uint16 readFunc)
{
////    return BufferedCollection<T, ReadFunc>(buffer, count, readFunc);
  BufferedCollection_uint16 bBufferedCollection_uint16;
  BufferedCollection_uint16_in_BufferedCollection_uint16(&bBufferedCollection_uint16,
      buffer,
      count, readFunc);
  return bBufferedCollection_uint16;
}

uint16_t Count_in_BufferedCollection_uint16(BufferedCollection_uint16 *pBufferedCollection_uint16)
{
  return pBufferedCollection_uint16->COUNT;
}

void Foreach_in_BufferedCollection_uint16(BufferedCollection_uint16 *pBufferedCollection_uint16,
    IVisitor__for__uint16* visitor)
{
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"Foreach_in_BufferedCollection_uint16_1"<<std::endl;
//  decrement_stack_info();
#endif

////        ser4cpp::rseq_t copy(buffer);
  RSeq_for_Uint16_t copy;
  copy = pBufferedCollection_uint16->buffer;

  for (uint32_t pos = 0; pos < pBufferedCollection_uint16->COUNT; ++pos)
  {
//void OnValue_in_IVisitor__for__uint16(IVisitor__for__uint16 *, uint16* );
////            visitor.OnValue(readFunc(copy, pos));
    uint16_t temp = pBufferedCollection_uint16->readFunc(&copy, pos);
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"Foreach_in_BufferedCollection_uint16_2"<<std::endl;
#endif
    OnValue_in_IVisitor__for__uint16(visitor, &temp );
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"Foreach_in_BufferedCollection_uint16_3"<<std::endl;
#endif
  }
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
}

uint16_t Count_in_BufferedCollection_uint16_override(void *pICollection_for_uint16)
{
  BufferedCollection_uint16* parent =
    (BufferedCollection_uint16*)getParentPointer_in_ICollection_for_uint16(
      (ICollection_for_uint16*)pICollection_for_uint16);
  return Count_in_BufferedCollection_uint16(parent);
}
void Foreach_in_BufferedCollection_uint16_override(void *pICollection_for_uint16,
    IVisitor__for__uint16* visitor)
{
  BufferedCollection_uint16* parent =
    (BufferedCollection_uint16*)getParentPointer_in_ICollection_for_uint16(
      (ICollection_for_uint16*)pICollection_for_uint16);
  Foreach_in_BufferedCollection_uint16(parent, visitor);
}
//-----------------------------------uint16---------------------------------------------------
//-----------------------------------Group50Var1---------------------------------------------------
////    BufferedCollection(const ser4cpp::rseq_t& buffer, size_t count, const ReadFunc& readFunc)
////        : buffer(buffer), COUNT(count), readFunc(readFunc)
void  BufferedCollection_Group50Var1_in_BufferedCollection_Group50Var1(
  BufferedCollection_Group50Var1 *pBufferedCollection_Group50Var1,
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Group50Var1 readFunc)
{
  pBufferedCollection_Group50Var1->buffer = *buffer;
  pBufferedCollection_Group50Var1->COUNT = count;
  pBufferedCollection_Group50Var1->readFunc = readFunc;

  pBufferedCollection_Group50Var1->iICollection_for_Group50Var1.pCount_in_ICollection_for_Group50Var1 =
    Count_in_BufferedCollection_Group50Var1_override;
  pBufferedCollection_Group50Var1->iICollection_for_Group50Var1.pForeach_in_ICollection_for_Group50Var1 =
    Foreach_in_BufferedCollection_Group50Var1_override;

  setParentPointer_in_ICollection_for_Group50Var1(&(pBufferedCollection_Group50Var1->iICollection_for_Group50Var1), pBufferedCollection_Group50Var1);
}

////template<class T, class ReadFunc>
////BufferedCollection<T, ReadFunc> CreateBufferedCollection(const ser4cpp::rseq_t& buffer,
////                                                         size_t count,
////                                                         const ReadFunc& readFunc)
BufferedCollection_Group50Var1 CreateBufferedCollection_Group50Var1_static(
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Group50Var1 readFunc)
{
////    return BufferedCollection<T, ReadFunc>(buffer, count, readFunc);
  BufferedCollection_Group50Var1 bBufferedCollection_Group50Var1;
  BufferedCollection_Group50Var1_in_BufferedCollection_Group50Var1(&bBufferedCollection_Group50Var1,
      buffer,
      count, readFunc);
  return bBufferedCollection_Group50Var1;
}

uint16_t Count_in_BufferedCollection_Group50Var1(BufferedCollection_Group50Var1 *pBufferedCollection_Group50Var1)
{
  return pBufferedCollection_Group50Var1->COUNT;
}

void Foreach_in_BufferedCollection_Group50Var1(BufferedCollection_Group50Var1 *pBufferedCollection_Group50Var1,
    IVisitor__for__Group50Var1* visitor)
{
////        ser4cpp::rseq_t copy(buffer);
  RSeq_for_Uint16_t copy;
  copy = pBufferedCollection_Group50Var1->buffer;

  for (uint32_t pos = 0; pos < pBufferedCollection_Group50Var1->COUNT; ++pos)
  {
//void OnValue_in_IVisitor__for__Group50Var1(IVisitor__for__Group50Var1 *, Group50Var1* );
////            visitor.OnValue(readFunc(copy, pos));
    Group50Var1 temp = pBufferedCollection_Group50Var1->readFunc(&copy, pos);
    OnValue_in_IVisitor__for__Group50Var1(visitor, &temp );
  }
}

uint16_t Count_in_BufferedCollection_Group50Var1_override(void *pICollection_for_Group50Var1)
{
  BufferedCollection_Group50Var1* parent =
    (BufferedCollection_Group50Var1*)getParentPointer_in_ICollection_for_Group50Var1(
      (ICollection_for_Group50Var1*)pICollection_for_Group50Var1);
  return Count_in_BufferedCollection_Group50Var1(parent);
}
void Foreach_in_BufferedCollection_Group50Var1_override(void *pICollection_for_Group50Var1,
    IVisitor__for__Group50Var1* visitor)
{
  BufferedCollection_Group50Var1* parent =
    (BufferedCollection_Group50Var1*)getParentPointer_in_ICollection_for_Group50Var1(
      (ICollection_for_Group50Var1*)pICollection_for_Group50Var1);
  Foreach_in_BufferedCollection_Group50Var1(parent, visitor);
}
//-----------------------------------Group50Var1---------------------------------------------------
//-----------------------------------Group50Var3---------------------------------------------------
////    BufferedCollection(const ser4cpp::rseq_t& buffer, size_t count, const ReadFunc& readFunc)
////        : buffer(buffer), COUNT(count), readFunc(readFunc)
void  BufferedCollection_Group50Var3_in_BufferedCollection_Group50Var3(
  BufferedCollection_Group50Var3 *pBufferedCollection_Group50Var3,
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Group50Var3 readFunc)
{
  pBufferedCollection_Group50Var3->buffer = *buffer;
  pBufferedCollection_Group50Var3->COUNT = count;
  pBufferedCollection_Group50Var3->readFunc = readFunc;

  pBufferedCollection_Group50Var3->iICollection_for_Group50Var3.pCount_in_ICollection_for_Group50Var3 =
    Count_in_BufferedCollection_Group50Var3_override;
  pBufferedCollection_Group50Var3->iICollection_for_Group50Var3.pForeach_in_ICollection_for_Group50Var3 =
    Foreach_in_BufferedCollection_Group50Var3_override;

  setParentPointer_in_ICollection_for_Group50Var3(&(pBufferedCollection_Group50Var3->iICollection_for_Group50Var3), pBufferedCollection_Group50Var3);
}

////template<class T, class ReadFunc>
////BufferedCollection<T, ReadFunc> CreateBufferedCollection(const ser4cpp::rseq_t& buffer,
////                                                         size_t count,
////                                                         const ReadFunc& readFunc)
BufferedCollection_Group50Var3 CreateBufferedCollection_Group50Var3_static(
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Group50Var3 readFunc)
{
////    return BufferedCollection<T, ReadFunc>(buffer, count, readFunc);
  BufferedCollection_Group50Var3 bBufferedCollection_Group50Var3;
  BufferedCollection_Group50Var3_in_BufferedCollection_Group50Var3(&bBufferedCollection_Group50Var3,
      buffer,
      count, readFunc);
  return bBufferedCollection_Group50Var3;
}

uint16_t Count_in_BufferedCollection_Group50Var3(BufferedCollection_Group50Var3 *pBufferedCollection_Group50Var3)
{
  return pBufferedCollection_Group50Var3->COUNT;
}

void Foreach_in_BufferedCollection_Group50Var3(BufferedCollection_Group50Var3 *pBufferedCollection_Group50Var3,
    IVisitor__for__Group50Var3* visitor)
{
////        ser4cpp::rseq_t copy(buffer);
  RSeq_for_Uint16_t copy;
  copy = pBufferedCollection_Group50Var3->buffer;

  for (uint32_t pos = 0; pos < pBufferedCollection_Group50Var3->COUNT; ++pos)
  {
//void OnValue_in_IVisitor__for__Group50Var3(IVisitor__for__Group50Var3 *, Group50Var3* );
////            visitor.OnValue(readFunc(copy, pos));
    Group50Var3 temp = pBufferedCollection_Group50Var3->readFunc(&copy, pos);
    OnValue_in_IVisitor__for__Group50Var3(visitor, &temp );
  }
}

uint16_t Count_in_BufferedCollection_Group50Var3_override(void *pICollection_for_Group50Var3)
{
  BufferedCollection_Group50Var3* parent =
    (BufferedCollection_Group50Var3*)getParentPointer_in_ICollection_for_Group50Var3(
      (ICollection_for_Group50Var3*)pICollection_for_Group50Var3);
  return Count_in_BufferedCollection_Group50Var3(parent);
}
void Foreach_in_BufferedCollection_Group50Var3_override(void *pICollection_for_Group50Var3,
    IVisitor__for__Group50Var3* visitor)
{
  BufferedCollection_Group50Var3* parent =
    (BufferedCollection_Group50Var3*)getParentPointer_in_ICollection_for_Group50Var3(
      (ICollection_for_Group50Var3*)pICollection_for_Group50Var3);
  Foreach_in_BufferedCollection_Group50Var3(parent, visitor);
}
//-----------------------------------Group50Var3---------------------------------------------------
//-----------------------------------Indexed_for_Binary---------------------------------------------------
////    BufferedCollection(const ser4cpp::rseq_t& buffer, size_t count, const ReadFunc& readFunc)
////        : buffer(buffer), COUNT(count), readFunc(readFunc)
void  BufferedCollection_Indexed_for_Binary_in_BufferedCollection_Indexed_for_Binary(
  BufferedCollection_Indexed_for_Binary *pBufferedCollection_Indexed_for_Binary,
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_Binary readFunc)
{
  pBufferedCollection_Indexed_for_Binary->buffer = *buffer;
  pBufferedCollection_Indexed_for_Binary->COUNT = count;
  pBufferedCollection_Indexed_for_Binary->readFunc = readFunc;

  pBufferedCollection_Indexed_for_Binary->iICollection_Indexed_for_Binary.pCount_in_ICollection_Indexed_for_Binary =
    Count_in_BufferedCollection_Indexed_for_Binary_override;
  pBufferedCollection_Indexed_for_Binary->iICollection_Indexed_for_Binary.pForeach_in_ICollection_Indexed_for_Binary =
    Foreach_in_BufferedCollection_Indexed_for_Binary_override;

  setParentPointer_in_ICollection_Indexed_for_Binary(&(pBufferedCollection_Indexed_for_Binary->iICollection_Indexed_for_Binary), pBufferedCollection_Indexed_for_Binary);
}

////template<class T, class ReadFunc>
////BufferedCollection<T, ReadFunc> CreateBufferedCollection(const ser4cpp::rseq_t& buffer,
////                                                         size_t count,
////                                                         const ReadFunc& readFunc)
BufferedCollection_Indexed_for_Binary CreateBufferedCollection_Indexed_for_Binary_static(
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_Binary readFunc)
{
////    return BufferedCollection<T, ReadFunc>(buffer, count, readFunc);
  BufferedCollection_Indexed_for_Binary bBufferedCollection_Indexed_for_Binary;
  BufferedCollection_Indexed_for_Binary_in_BufferedCollection_Indexed_for_Binary(&bBufferedCollection_Indexed_for_Binary,
      buffer,
      count, readFunc);
  return bBufferedCollection_Indexed_for_Binary;
}

uint16_t Count_in_BufferedCollection_Indexed_for_Binary(BufferedCollection_Indexed_for_Binary *pBufferedCollection_Indexed_for_Binary)
{
  return pBufferedCollection_Indexed_for_Binary->COUNT;
}

void Foreach_in_BufferedCollection_Indexed_for_Binary(BufferedCollection_Indexed_for_Binary *pBufferedCollection_Indexed_for_Binary,
    IVisitor__for__Indexed_for_Binary* visitor)
{
////        ser4cpp::rseq_t copy(buffer);
  RSeq_for_Uint16_t copy;
  copy = pBufferedCollection_Indexed_for_Binary->buffer;

  for (uint32_t pos = 0; pos < pBufferedCollection_Indexed_for_Binary->COUNT; ++pos)
  {
//void OnValue_in_IVisitor__for__Indexed_for_Binary(IVisitor__for__Indexed_for_Binary *, Indexed_for_Binary* );
////            visitor.OnValue(readFunc(copy, pos));
    Indexed_for_Binary temp = pBufferedCollection_Indexed_for_Binary->readFunc(&copy, pos);
    OnValue_in_IVisitor__for__Indexed_for_Binary(visitor, &temp );
  }
}

uint16_t Count_in_BufferedCollection_Indexed_for_Binary_override(void *pICollection_Indexed_for_Binary)
{
  BufferedCollection_Indexed_for_Binary* parent =
    (BufferedCollection_Indexed_for_Binary*)getParentPointer_in_ICollection_Indexed_for_Binary(
      (ICollection_Indexed_for_Binary*)pICollection_Indexed_for_Binary);
  return Count_in_BufferedCollection_Indexed_for_Binary(parent);
}
void Foreach_in_BufferedCollection_Indexed_for_Binary_override(void *pICollection_Indexed_for_Binary,
    IVisitor__for__Indexed_for_Binary* visitor)
{
  BufferedCollection_Indexed_for_Binary* parent =
    (BufferedCollection_Indexed_for_Binary*)getParentPointer_in_ICollection_Indexed_for_Binary(
      (ICollection_Indexed_for_Binary*)pICollection_Indexed_for_Binary);
  Foreach_in_BufferedCollection_Indexed_for_Binary(parent, visitor);
}
//-----------------------------------Indexed_for_Binary---------------------------------------------------
//-----------------------------------Indexed_for_OctetString---------------------------------------------------
////    BufferedCollection(const ser4cpp::rseq_t& buffer, size_t count, const ReadFunc& readFunc)
////        : buffer(buffer), COUNT(count), readFunc(readFunc)
void  BufferedCollection_Indexed_for_OctetString_in_BufferedCollection_Indexed_for_OctetString(
  BufferedCollection_Indexed_for_OctetString *pBufferedCollection_Indexed_for_OctetString,
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_OctetString readFunc)
{
  pBufferedCollection_Indexed_for_OctetString->buffer = *buffer;
  pBufferedCollection_Indexed_for_OctetString->COUNT = count;
  pBufferedCollection_Indexed_for_OctetString->readFunc = readFunc;

  pBufferedCollection_Indexed_for_OctetString->iICollection_Indexed_for_OctetString.pCount_in_ICollection_Indexed_for_OctetString =
    Count_in_BufferedCollection_Indexed_for_OctetString_override;
  pBufferedCollection_Indexed_for_OctetString->iICollection_Indexed_for_OctetString.pForeach_in_ICollection_Indexed_for_OctetString =
    Foreach_in_BufferedCollection_Indexed_for_OctetString_override;

  setParentPointer_in_ICollection_Indexed_for_OctetString(&(pBufferedCollection_Indexed_for_OctetString->iICollection_Indexed_for_OctetString), pBufferedCollection_Indexed_for_OctetString);
}

////template<class T, class ReadFunc>
////BufferedCollection<T, ReadFunc> CreateBufferedCollection(const ser4cpp::rseq_t& buffer,
////                                                         size_t count,
////                                                         const ReadFunc& readFunc)
BufferedCollection_Indexed_for_OctetString CreateBufferedCollection_Indexed_for_OctetString_static(
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_OctetString readFunc)
{
////    return BufferedCollection<T, ReadFunc>(buffer, count, readFunc);
  BufferedCollection_Indexed_for_OctetString bBufferedCollection_Indexed_for_OctetString;
  BufferedCollection_Indexed_for_OctetString_in_BufferedCollection_Indexed_for_OctetString(&bBufferedCollection_Indexed_for_OctetString,
      buffer,
      count, readFunc);
  return bBufferedCollection_Indexed_for_OctetString;
}

uint16_t Count_in_BufferedCollection_Indexed_for_OctetString(BufferedCollection_Indexed_for_OctetString *pBufferedCollection_Indexed_for_OctetString)
{
  return pBufferedCollection_Indexed_for_OctetString->COUNT;
}

void Foreach_in_BufferedCollection_Indexed_for_OctetString(BufferedCollection_Indexed_for_OctetString *pBufferedCollection_Indexed_for_OctetString,
    IVisitor__for__Indexed_for_OctetString* visitor)
{
////        ser4cpp::rseq_t copy(buffer);
  RSeq_for_Uint16_t copy;
  copy = pBufferedCollection_Indexed_for_OctetString->buffer;

  for (uint32_t pos = 0; pos < pBufferedCollection_Indexed_for_OctetString->COUNT; ++pos)
  {
//void OnValue_in_IVisitor__for__Indexed_for_OctetString(IVisitor__for__Indexed_for_OctetString *, Indexed_for_OctetString* );
////            visitor.OnValue(readFunc(copy, pos));
    Indexed_for_OctetString temp = pBufferedCollection_Indexed_for_OctetString->readFunc(&copy, pos);
    OnValue_in_IVisitor__for__Indexed_for_OctetString(visitor, &temp );
  }
}

uint16_t Count_in_BufferedCollection_Indexed_for_OctetString_override(void *pICollection_Indexed_for_OctetString)
{
  BufferedCollection_Indexed_for_OctetString* parent =
    (BufferedCollection_Indexed_for_OctetString*)getParentPointer_in_ICollection_Indexed_for_OctetString(
      (ICollection_Indexed_for_OctetString*)pICollection_Indexed_for_OctetString);
  return Count_in_BufferedCollection_Indexed_for_OctetString(parent);
}
void Foreach_in_BufferedCollection_Indexed_for_OctetString_override(void *pICollection_Indexed_for_OctetString,
    IVisitor__for__Indexed_for_OctetString* visitor)
{
  BufferedCollection_Indexed_for_OctetString* parent =
    (BufferedCollection_Indexed_for_OctetString*)getParentPointer_in_ICollection_Indexed_for_OctetString(
      (ICollection_Indexed_for_OctetString*)pICollection_Indexed_for_OctetString);
  Foreach_in_BufferedCollection_Indexed_for_OctetString(parent, visitor);
}
//-----------------------------------Indexed_for_OctetString---------------------------------------------------
//-----------------------------------Indexed_for_BinaryOutputStatus---------------------------------------------------
////    BufferedCollection(const ser4cpp::rseq_t& buffer, size_t count, const ReadFunc& readFunc)
////        : buffer(buffer), COUNT(count), readFunc(readFunc)
void  BufferedCollection_Indexed_for_BinaryOutputStatus_in_BufferedCollection_Indexed_for_BinaryOutputStatus(
  BufferedCollection_Indexed_for_BinaryOutputStatus *pBufferedCollection_Indexed_for_BinaryOutputStatus,
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_BinaryOutputStatus readFunc)
{
  pBufferedCollection_Indexed_for_BinaryOutputStatus->buffer = *buffer;
  pBufferedCollection_Indexed_for_BinaryOutputStatus->COUNT = count;
  pBufferedCollection_Indexed_for_BinaryOutputStatus->readFunc = readFunc;

  pBufferedCollection_Indexed_for_BinaryOutputStatus->iICollection_Indexed_for_BinaryOutputStatus.pCount_in_ICollection_Indexed_for_BinaryOutputStatus =
    Count_in_BufferedCollection_Indexed_for_BinaryOutputStatus_override;
  pBufferedCollection_Indexed_for_BinaryOutputStatus->iICollection_Indexed_for_BinaryOutputStatus.pForeach_in_ICollection_Indexed_for_BinaryOutputStatus =
    Foreach_in_BufferedCollection_Indexed_for_BinaryOutputStatus_override;

  setParentPointer_in_ICollection_Indexed_for_BinaryOutputStatus(&(pBufferedCollection_Indexed_for_BinaryOutputStatus->iICollection_Indexed_for_BinaryOutputStatus), pBufferedCollection_Indexed_for_BinaryOutputStatus);
}

////template<class T, class ReadFunc>
////BufferedCollection<T, ReadFunc> CreateBufferedCollection(const ser4cpp::rseq_t& buffer,
////                                                         size_t count,
////                                                         const ReadFunc& readFunc)
BufferedCollection_Indexed_for_BinaryOutputStatus CreateBufferedCollection_Indexed_for_BinaryOutputStatus_static(
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_BinaryOutputStatus readFunc)
{
////    return BufferedCollection<T, ReadFunc>(buffer, count, readFunc);
  BufferedCollection_Indexed_for_BinaryOutputStatus bBufferedCollection_Indexed_for_BinaryOutputStatus;
  BufferedCollection_Indexed_for_BinaryOutputStatus_in_BufferedCollection_Indexed_for_BinaryOutputStatus(&bBufferedCollection_Indexed_for_BinaryOutputStatus,
      buffer,
      count, readFunc);
  return bBufferedCollection_Indexed_for_BinaryOutputStatus;
}

uint16_t Count_in_BufferedCollection_Indexed_for_BinaryOutputStatus(BufferedCollection_Indexed_for_BinaryOutputStatus *pBufferedCollection_Indexed_for_BinaryOutputStatus)
{
  return pBufferedCollection_Indexed_for_BinaryOutputStatus->COUNT;
}

void Foreach_in_BufferedCollection_Indexed_for_BinaryOutputStatus(BufferedCollection_Indexed_for_BinaryOutputStatus *pBufferedCollection_Indexed_for_BinaryOutputStatus,
    IVisitor__for__Indexed_for_BinaryOutputStatus* visitor)
{
////        ser4cpp::rseq_t copy(buffer);
  RSeq_for_Uint16_t copy;
  copy = pBufferedCollection_Indexed_for_BinaryOutputStatus->buffer;

  for (uint32_t pos = 0; pos < pBufferedCollection_Indexed_for_BinaryOutputStatus->COUNT; ++pos)
  {
//void OnValue_in_IVisitor__for__Indexed_for_BinaryOutputStatus(IVisitor__for__Indexed_for_BinaryOutputStatus *, Indexed_for_BinaryOutputStatus* );
////            visitor.OnValue(readFunc(copy, pos));
    Indexed_for_BinaryOutputStatus temp = pBufferedCollection_Indexed_for_BinaryOutputStatus->readFunc(&copy, pos);
    OnValue_in_IVisitor__for__Indexed_for_BinaryOutputStatus(visitor, &temp );
  }
}

uint16_t Count_in_BufferedCollection_Indexed_for_BinaryOutputStatus_override(void *pICollection_Indexed_for_BinaryOutputStatus)
{
  BufferedCollection_Indexed_for_BinaryOutputStatus* parent =
    (BufferedCollection_Indexed_for_BinaryOutputStatus*)getParentPointer_in_ICollection_Indexed_for_BinaryOutputStatus(
      (ICollection_Indexed_for_BinaryOutputStatus*)pICollection_Indexed_for_BinaryOutputStatus);
  return Count_in_BufferedCollection_Indexed_for_BinaryOutputStatus(parent);
}
void Foreach_in_BufferedCollection_Indexed_for_BinaryOutputStatus_override(void *pICollection_Indexed_for_BinaryOutputStatus,
    IVisitor__for__Indexed_for_BinaryOutputStatus* visitor)
{
  BufferedCollection_Indexed_for_BinaryOutputStatus* parent =
    (BufferedCollection_Indexed_for_BinaryOutputStatus*)getParentPointer_in_ICollection_Indexed_for_BinaryOutputStatus(
      (ICollection_Indexed_for_BinaryOutputStatus*)pICollection_Indexed_for_BinaryOutputStatus);
  Foreach_in_BufferedCollection_Indexed_for_BinaryOutputStatus(parent, visitor);
}
//-----------------------------------Indexed_for_BinaryOutputStatus---------------------------------------------------
//-----------------------------------Indexed_for_IINValue---------------------------------------------------
////    BufferedCollection(const ser4cpp::rseq_t& buffer, size_t count, const ReadFunc& readFunc)
////        : buffer(buffer), COUNT(count), readFunc(readFunc)
void  BufferedCollection_Indexed_for_IINValue_in_BufferedCollection_Indexed_for_IINValue(
  BufferedCollection_Indexed_for_IINValue *pBufferedCollection_Indexed_for_IINValue,
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_IINValue readFunc)
{
  pBufferedCollection_Indexed_for_IINValue->buffer = *buffer;
  pBufferedCollection_Indexed_for_IINValue->COUNT = count;
  pBufferedCollection_Indexed_for_IINValue->readFunc = readFunc;

  pBufferedCollection_Indexed_for_IINValue->iICollection_Indexed_for_IINValue.pCount_in_ICollection_Indexed_for_IINValue =
    Count_in_BufferedCollection_Indexed_for_IINValue_override;
  pBufferedCollection_Indexed_for_IINValue->iICollection_Indexed_for_IINValue.pForeach_in_ICollection_Indexed_for_IINValue =
    Foreach_in_BufferedCollection_Indexed_for_IINValue_override;

  setParentPointer_in_ICollection_Indexed_for_IINValue(&(pBufferedCollection_Indexed_for_IINValue->iICollection_Indexed_for_IINValue), pBufferedCollection_Indexed_for_IINValue);
}

////template<class T, class ReadFunc>
////BufferedCollection<T, ReadFunc> CreateBufferedCollection(const ser4cpp::rseq_t& buffer,
////                                                         size_t count,
////                                                         const ReadFunc& readFunc)
BufferedCollection_Indexed_for_IINValue CreateBufferedCollection_Indexed_for_IINValue_static(
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_IINValue readFunc)
{
////    return BufferedCollection<T, ReadFunc>(buffer, count, readFunc);
  BufferedCollection_Indexed_for_IINValue bBufferedCollection_Indexed_for_IINValue;
  BufferedCollection_Indexed_for_IINValue_in_BufferedCollection_Indexed_for_IINValue(&bBufferedCollection_Indexed_for_IINValue,
      buffer,
      count, readFunc);
  return bBufferedCollection_Indexed_for_IINValue;
}

uint16_t Count_in_BufferedCollection_Indexed_for_IINValue(BufferedCollection_Indexed_for_IINValue *pBufferedCollection_Indexed_for_IINValue)
{
  return pBufferedCollection_Indexed_for_IINValue->COUNT;
}

void Foreach_in_BufferedCollection_Indexed_for_IINValue(BufferedCollection_Indexed_for_IINValue *pBufferedCollection_Indexed_for_IINValue,
    IVisitor__for__Indexed_for_IINValue* visitor)
{
////        ser4cpp::rseq_t copy(buffer);
  RSeq_for_Uint16_t copy;
  copy = pBufferedCollection_Indexed_for_IINValue->buffer;

  for (uint32_t pos = 0; pos < pBufferedCollection_Indexed_for_IINValue->COUNT; ++pos)
  {
//void OnValue_in_IVisitor__for__Indexed_for_IINValue(IVisitor__for__Indexed_for_IINValue *, Indexed_for_IINValue* );
////            visitor.OnValue(readFunc(copy, pos));
    Indexed_for_IINValue temp = pBufferedCollection_Indexed_for_IINValue->readFunc(&copy, pos);
    OnValue_in_IVisitor__for__Indexed_for_IINValue(visitor, &temp );
  }
}

uint16_t Count_in_BufferedCollection_Indexed_for_IINValue_override(void *pICollection_Indexed_for_IINValue)
{
  BufferedCollection_Indexed_for_IINValue* parent =
    (BufferedCollection_Indexed_for_IINValue*)getParentPointer_in_ICollection_Indexed_for_IINValue(
      (ICollection_Indexed_for_IINValue*)pICollection_Indexed_for_IINValue);
  return Count_in_BufferedCollection_Indexed_for_IINValue(parent);
}
void Foreach_in_BufferedCollection_Indexed_for_IINValue_override(void *pICollection_Indexed_for_IINValue,
    IVisitor__for__Indexed_for_IINValue* visitor)
{
  BufferedCollection_Indexed_for_IINValue* parent =
    (BufferedCollection_Indexed_for_IINValue*)getParentPointer_in_ICollection_Indexed_for_IINValue(
      (ICollection_Indexed_for_IINValue*)pICollection_Indexed_for_IINValue);
  Foreach_in_BufferedCollection_Indexed_for_IINValue(parent, visitor);
}
//-----------------------------------Indexed_for_IINValue---------------------------------------------------
//-----------------------------------Indexed_for_ControlRelayOutputBlock---------------------------------------------------
////    BufferedCollection(const ser4cpp::rseq_t& buffer, size_t count, const ReadFunc& readFunc)
////        : buffer(buffer), COUNT(count), readFunc(readFunc)
void  BufferedCollection_Indexed_for_ControlRelayOutputBlock_in_BufferedCollection_Indexed_for_ControlRelayOutputBlock(
  BufferedCollection_Indexed_for_ControlRelayOutputBlock *pBufferedCollection_Indexed_for_ControlRelayOutputBlock,
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_ControlRelayOutputBlock readFunc)
{
  pBufferedCollection_Indexed_for_ControlRelayOutputBlock->buffer = *buffer;
  pBufferedCollection_Indexed_for_ControlRelayOutputBlock->COUNT = count;
  pBufferedCollection_Indexed_for_ControlRelayOutputBlock->readFunc = readFunc;

  pBufferedCollection_Indexed_for_ControlRelayOutputBlock->iICollection_Indexed_for_ControlRelayOutputBlock.pCount_in_ICollection_Indexed_for_ControlRelayOutputBlock =
    Count_in_BufferedCollection_Indexed_for_ControlRelayOutputBlock_override;
  pBufferedCollection_Indexed_for_ControlRelayOutputBlock->iICollection_Indexed_for_ControlRelayOutputBlock.pForeach_in_ICollection_Indexed_for_ControlRelayOutputBlock =
    Foreach_in_BufferedCollection_Indexed_for_ControlRelayOutputBlock_override;

  setParentPointer_in_ICollection_Indexed_for_ControlRelayOutputBlock(&(pBufferedCollection_Indexed_for_ControlRelayOutputBlock->iICollection_Indexed_for_ControlRelayOutputBlock), pBufferedCollection_Indexed_for_ControlRelayOutputBlock);
}

////template<class T, class ReadFunc>
////BufferedCollection<T, ReadFunc> CreateBufferedCollection(const ser4cpp::rseq_t& buffer,
////                                                         size_t count,
////                                                         const ReadFunc& readFunc)
BufferedCollection_Indexed_for_ControlRelayOutputBlock CreateBufferedCollection_Indexed_for_ControlRelayOutputBlock_static(
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_ControlRelayOutputBlock readFunc)
{
////    return BufferedCollection<T, ReadFunc>(buffer, count, readFunc);
  BufferedCollection_Indexed_for_ControlRelayOutputBlock bBufferedCollection_Indexed_for_ControlRelayOutputBlock;
  BufferedCollection_Indexed_for_ControlRelayOutputBlock_in_BufferedCollection_Indexed_for_ControlRelayOutputBlock(&bBufferedCollection_Indexed_for_ControlRelayOutputBlock,
      buffer,
      count, readFunc);
  return bBufferedCollection_Indexed_for_ControlRelayOutputBlock;
}

uint16_t Count_in_BufferedCollection_Indexed_for_ControlRelayOutputBlock(BufferedCollection_Indexed_for_ControlRelayOutputBlock *pBufferedCollection_Indexed_for_ControlRelayOutputBlock)
{
  return pBufferedCollection_Indexed_for_ControlRelayOutputBlock->COUNT;
}

void Foreach_in_BufferedCollection_Indexed_for_ControlRelayOutputBlock(BufferedCollection_Indexed_for_ControlRelayOutputBlock *pBufferedCollection_Indexed_for_ControlRelayOutputBlock,
    IVisitor__for__Indexed_for_ControlRelayOutputBlock* visitor)
{
////        ser4cpp::rseq_t copy(buffer);
  RSeq_for_Uint16_t copy;
  copy = pBufferedCollection_Indexed_for_ControlRelayOutputBlock->buffer;

  for (uint32_t pos = 0; pos < pBufferedCollection_Indexed_for_ControlRelayOutputBlock->COUNT; ++pos)
  {
//void OnValue_in_IVisitor__for__Indexed_for_ControlRelayOutputBlock(IVisitor__for__Indexed_for_ControlRelayOutputBlock *, Indexed_for_ControlRelayOutputBlock* );
////            visitor.OnValue(readFunc(copy, pos));
    Indexed_for_ControlRelayOutputBlock temp = pBufferedCollection_Indexed_for_ControlRelayOutputBlock->readFunc(&copy, pos);
    OnValue_in_IVisitor__for__Indexed_for_ControlRelayOutputBlock(visitor, &temp );
  }
}

uint16_t Count_in_BufferedCollection_Indexed_for_ControlRelayOutputBlock_override(void *pICollection_Indexed_for_ControlRelayOutputBlock)
{
  BufferedCollection_Indexed_for_ControlRelayOutputBlock* parent =
    (BufferedCollection_Indexed_for_ControlRelayOutputBlock*)getParentPointer_in_ICollection_Indexed_for_ControlRelayOutputBlock(
      (ICollection_Indexed_for_ControlRelayOutputBlock*)pICollection_Indexed_for_ControlRelayOutputBlock);
  return Count_in_BufferedCollection_Indexed_for_ControlRelayOutputBlock(parent);
}
void Foreach_in_BufferedCollection_Indexed_for_ControlRelayOutputBlock_override(void *pICollection_Indexed_for_ControlRelayOutputBlock,
    IVisitor__for__Indexed_for_ControlRelayOutputBlock* visitor)
{
  BufferedCollection_Indexed_for_ControlRelayOutputBlock* parent =
    (BufferedCollection_Indexed_for_ControlRelayOutputBlock*)getParentPointer_in_ICollection_Indexed_for_ControlRelayOutputBlock(
      (ICollection_Indexed_for_ControlRelayOutputBlock*)pICollection_Indexed_for_ControlRelayOutputBlock);
  Foreach_in_BufferedCollection_Indexed_for_ControlRelayOutputBlock(parent, visitor);
}
//-----------------------------------Indexed_for_ControlRelayOutputBlock---------------------------------------------------
//-----------------------------------Indexed_for_DoubleBitBinary---------------------------------------------------
////    BufferedCollection(const ser4cpp::rseq_t& buffer, size_t count, const ReadFunc& readFunc)
////        : buffer(buffer), COUNT(count), readFunc(readFunc)
void  BufferedCollection_Indexed_for_DoubleBitBinary_in_BufferedCollection_Indexed_for_DoubleBitBinary(
  BufferedCollection_Indexed_for_DoubleBitBinary *pBufferedCollection_Indexed_for_DoubleBitBinary,
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_DoubleBitBinary readFunc)
{
  pBufferedCollection_Indexed_for_DoubleBitBinary->buffer = *buffer;
  pBufferedCollection_Indexed_for_DoubleBitBinary->COUNT = count;
  pBufferedCollection_Indexed_for_DoubleBitBinary->readFunc = readFunc;

  pBufferedCollection_Indexed_for_DoubleBitBinary->iICollection_Indexed_for_DoubleBitBinary.pCount_in_ICollection_Indexed_for_DoubleBitBinary =
    Count_in_BufferedCollection_Indexed_for_DoubleBitBinary_override;
  pBufferedCollection_Indexed_for_DoubleBitBinary->iICollection_Indexed_for_DoubleBitBinary.pForeach_in_ICollection_Indexed_for_DoubleBitBinary =
    Foreach_in_BufferedCollection_Indexed_for_DoubleBitBinary_override;

  setParentPointer_in_ICollection_Indexed_for_DoubleBitBinary(&(pBufferedCollection_Indexed_for_DoubleBitBinary->iICollection_Indexed_for_DoubleBitBinary), pBufferedCollection_Indexed_for_DoubleBitBinary);
}

////template<class T, class ReadFunc>
////BufferedCollection<T, ReadFunc> CreateBufferedCollection(const ser4cpp::rseq_t& buffer,
////                                                         size_t count,
////                                                         const ReadFunc& readFunc)
BufferedCollection_Indexed_for_DoubleBitBinary CreateBufferedCollection_Indexed_for_DoubleBitBinary_static(
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_DoubleBitBinary readFunc)
{
////    return BufferedCollection<T, ReadFunc>(buffer, count, readFunc);
  BufferedCollection_Indexed_for_DoubleBitBinary bBufferedCollection_Indexed_for_DoubleBitBinary;
  BufferedCollection_Indexed_for_DoubleBitBinary_in_BufferedCollection_Indexed_for_DoubleBitBinary(&bBufferedCollection_Indexed_for_DoubleBitBinary,
      buffer,
      count, readFunc);
  return bBufferedCollection_Indexed_for_DoubleBitBinary;
}

uint16_t Count_in_BufferedCollection_Indexed_for_DoubleBitBinary(BufferedCollection_Indexed_for_DoubleBitBinary *pBufferedCollection_Indexed_for_DoubleBitBinary)
{
  return pBufferedCollection_Indexed_for_DoubleBitBinary->COUNT;
}

void Foreach_in_BufferedCollection_Indexed_for_DoubleBitBinary(BufferedCollection_Indexed_for_DoubleBitBinary *pBufferedCollection_Indexed_for_DoubleBitBinary,
    IVisitor__for__Indexed_for_DoubleBitBinary* visitor)
{
////        ser4cpp::rseq_t copy(buffer);
  RSeq_for_Uint16_t copy;
  copy = pBufferedCollection_Indexed_for_DoubleBitBinary->buffer;

  for (uint32_t pos = 0; pos < pBufferedCollection_Indexed_for_DoubleBitBinary->COUNT; ++pos)
  {
//void OnValue_in_IVisitor__for__Indexed_for_DoubleBitBinary(IVisitor__for__Indexed_for_DoubleBitBinary *, Indexed_for_DoubleBitBinary* );
////            visitor.OnValue(readFunc(copy, pos));
    Indexed_for_DoubleBitBinary temp = pBufferedCollection_Indexed_for_DoubleBitBinary->readFunc(&copy, pos);
    OnValue_in_IVisitor__for__Indexed_for_DoubleBitBinary(visitor, &temp );
  }
}

uint16_t Count_in_BufferedCollection_Indexed_for_DoubleBitBinary_override(void *pICollection_Indexed_for_DoubleBitBinary)
{
  BufferedCollection_Indexed_for_DoubleBitBinary* parent =
    (BufferedCollection_Indexed_for_DoubleBitBinary*)getParentPointer_in_ICollection_Indexed_for_DoubleBitBinary(
      (ICollection_Indexed_for_DoubleBitBinary*)pICollection_Indexed_for_DoubleBitBinary);
  return Count_in_BufferedCollection_Indexed_for_DoubleBitBinary(parent);
}
void Foreach_in_BufferedCollection_Indexed_for_DoubleBitBinary_override(void *pICollection_Indexed_for_DoubleBitBinary,
    IVisitor__for__Indexed_for_DoubleBitBinary* visitor)
{
  BufferedCollection_Indexed_for_DoubleBitBinary* parent =
    (BufferedCollection_Indexed_for_DoubleBitBinary*)getParentPointer_in_ICollection_Indexed_for_DoubleBitBinary(
      (ICollection_Indexed_for_DoubleBitBinary*)pICollection_Indexed_for_DoubleBitBinary);
  Foreach_in_BufferedCollection_Indexed_for_DoubleBitBinary(parent, visitor);
}
//-----------------------------------Indexed_for_DoubleBitBinary---------------------------------------------------
//-----------------------------------Indexed_for_BinaryCommandEvent---------------------------------------------------
////    BufferedCollection(const ser4cpp::rseq_t& buffer, size_t count, const ReadFunc& readFunc)
////        : buffer(buffer), COUNT(count), readFunc(readFunc)
void  BufferedCollection_Indexed_for_BinaryCommandEvent_in_BufferedCollection_Indexed_for_BinaryCommandEvent(
  BufferedCollection_Indexed_for_BinaryCommandEvent *pBufferedCollection_Indexed_for_BinaryCommandEvent,
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_BinaryCommandEvent readFunc)
{
  pBufferedCollection_Indexed_for_BinaryCommandEvent->buffer = *buffer;
  pBufferedCollection_Indexed_for_BinaryCommandEvent->COUNT = count;
  pBufferedCollection_Indexed_for_BinaryCommandEvent->readFunc = readFunc;

  pBufferedCollection_Indexed_for_BinaryCommandEvent->iICollection_Indexed_for_BinaryCommandEvent.pCount_in_ICollection_Indexed_for_BinaryCommandEvent =
    Count_in_BufferedCollection_Indexed_for_BinaryCommandEvent_override;
  pBufferedCollection_Indexed_for_BinaryCommandEvent->iICollection_Indexed_for_BinaryCommandEvent.pForeach_in_ICollection_Indexed_for_BinaryCommandEvent =
    Foreach_in_BufferedCollection_Indexed_for_BinaryCommandEvent_override;

  setParentPointer_in_ICollection_Indexed_for_BinaryCommandEvent(&(pBufferedCollection_Indexed_for_BinaryCommandEvent->iICollection_Indexed_for_BinaryCommandEvent), pBufferedCollection_Indexed_for_BinaryCommandEvent);
}

////template<class T, class ReadFunc>
////BufferedCollection<T, ReadFunc> CreateBufferedCollection(const ser4cpp::rseq_t& buffer,
////                                                         size_t count,
////                                                         const ReadFunc& readFunc)
BufferedCollection_Indexed_for_BinaryCommandEvent CreateBufferedCollection_Indexed_for_BinaryCommandEvent_static(
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_BinaryCommandEvent readFunc)
{
////    return BufferedCollection<T, ReadFunc>(buffer, count, readFunc);
  BufferedCollection_Indexed_for_BinaryCommandEvent bBufferedCollection_Indexed_for_BinaryCommandEvent;
  BufferedCollection_Indexed_for_BinaryCommandEvent_in_BufferedCollection_Indexed_for_BinaryCommandEvent(&bBufferedCollection_Indexed_for_BinaryCommandEvent,
      buffer,
      count, readFunc);
  return bBufferedCollection_Indexed_for_BinaryCommandEvent;
}

uint16_t Count_in_BufferedCollection_Indexed_for_BinaryCommandEvent(BufferedCollection_Indexed_for_BinaryCommandEvent *pBufferedCollection_Indexed_for_BinaryCommandEvent)
{
  return pBufferedCollection_Indexed_for_BinaryCommandEvent->COUNT;
}

void Foreach_in_BufferedCollection_Indexed_for_BinaryCommandEvent(BufferedCollection_Indexed_for_BinaryCommandEvent *pBufferedCollection_Indexed_for_BinaryCommandEvent,
    IVisitor__for__Indexed_for_BinaryCommandEvent* visitor)
{
////        ser4cpp::rseq_t copy(buffer);
  RSeq_for_Uint16_t copy;
  copy = pBufferedCollection_Indexed_for_BinaryCommandEvent->buffer;

  for (uint32_t pos = 0; pos < pBufferedCollection_Indexed_for_BinaryCommandEvent->COUNT; ++pos)
  {
//void OnValue_in_IVisitor__for__Indexed_for_BinaryCommandEvent(IVisitor__for__Indexed_for_BinaryCommandEvent *, Indexed_for_BinaryCommandEvent* );
////            visitor.OnValue(readFunc(copy, pos));
    Indexed_for_BinaryCommandEvent temp = pBufferedCollection_Indexed_for_BinaryCommandEvent->readFunc(&copy, pos);
    OnValue_in_IVisitor__for__Indexed_for_BinaryCommandEvent(visitor, &temp );
  }
}

uint16_t Count_in_BufferedCollection_Indexed_for_BinaryCommandEvent_override(void *pICollection_Indexed_for_BinaryCommandEvent)
{
  BufferedCollection_Indexed_for_BinaryCommandEvent* parent =
    (BufferedCollection_Indexed_for_BinaryCommandEvent*)getParentPointer_in_ICollection_Indexed_for_BinaryCommandEvent(
      (ICollection_Indexed_for_BinaryCommandEvent*)pICollection_Indexed_for_BinaryCommandEvent);
  return Count_in_BufferedCollection_Indexed_for_BinaryCommandEvent(parent);
}
void Foreach_in_BufferedCollection_Indexed_for_BinaryCommandEvent_override(void *pICollection_Indexed_for_BinaryCommandEvent,
    IVisitor__for__Indexed_for_BinaryCommandEvent* visitor)
{
  BufferedCollection_Indexed_for_BinaryCommandEvent* parent =
    (BufferedCollection_Indexed_for_BinaryCommandEvent*)getParentPointer_in_ICollection_Indexed_for_BinaryCommandEvent(
      (ICollection_Indexed_for_BinaryCommandEvent*)pICollection_Indexed_for_BinaryCommandEvent);
  Foreach_in_BufferedCollection_Indexed_for_BinaryCommandEvent(parent, visitor);
}
//-----------------------------------Indexed_for_BinaryCommandEvent---------------------------------------------------
//-----------------------------------Indexed_for_AnalogCommandEvent---------------------------------------------------
////    BufferedCollection(const ser4cpp::rseq_t& buffer, size_t count, const ReadFunc& readFunc)
////        : buffer(buffer), COUNT(count), readFunc(readFunc)
void  BufferedCollection_Indexed_for_AnalogCommandEvent_in_BufferedCollection_Indexed_for_AnalogCommandEvent(
  BufferedCollection_Indexed_for_AnalogCommandEvent *pBufferedCollection_Indexed_for_AnalogCommandEvent,
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_AnalogCommandEvent readFunc)
{
  pBufferedCollection_Indexed_for_AnalogCommandEvent->buffer = *buffer;
  pBufferedCollection_Indexed_for_AnalogCommandEvent->COUNT = count;
  pBufferedCollection_Indexed_for_AnalogCommandEvent->readFunc = readFunc;

  pBufferedCollection_Indexed_for_AnalogCommandEvent->iICollection_Indexed_for_AnalogCommandEvent.pCount_in_ICollection_Indexed_for_AnalogCommandEvent =
    Count_in_BufferedCollection_Indexed_for_AnalogCommandEvent_override;
  pBufferedCollection_Indexed_for_AnalogCommandEvent->iICollection_Indexed_for_AnalogCommandEvent.pForeach_in_ICollection_Indexed_for_AnalogCommandEvent =
    Foreach_in_BufferedCollection_Indexed_for_AnalogCommandEvent_override;

  setParentPointer_in_ICollection_Indexed_for_AnalogCommandEvent(&(pBufferedCollection_Indexed_for_AnalogCommandEvent->iICollection_Indexed_for_AnalogCommandEvent), pBufferedCollection_Indexed_for_AnalogCommandEvent);
}

////template<class T, class ReadFunc>
////BufferedCollection<T, ReadFunc> CreateBufferedCollection(const ser4cpp::rseq_t& buffer,
////                                                         size_t count,
////                                                         const ReadFunc& readFunc)
BufferedCollection_Indexed_for_AnalogCommandEvent CreateBufferedCollection_Indexed_for_AnalogCommandEvent_static(
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_AnalogCommandEvent readFunc)
{
////    return BufferedCollection<T, ReadFunc>(buffer, count, readFunc);
  BufferedCollection_Indexed_for_AnalogCommandEvent bBufferedCollection_Indexed_for_AnalogCommandEvent;
  BufferedCollection_Indexed_for_AnalogCommandEvent_in_BufferedCollection_Indexed_for_AnalogCommandEvent(&bBufferedCollection_Indexed_for_AnalogCommandEvent,
      buffer,
      count, readFunc);
  return bBufferedCollection_Indexed_for_AnalogCommandEvent;
}

uint16_t Count_in_BufferedCollection_Indexed_for_AnalogCommandEvent(BufferedCollection_Indexed_for_AnalogCommandEvent *pBufferedCollection_Indexed_for_AnalogCommandEvent)
{
  return pBufferedCollection_Indexed_for_AnalogCommandEvent->COUNT;
}

void Foreach_in_BufferedCollection_Indexed_for_AnalogCommandEvent(BufferedCollection_Indexed_for_AnalogCommandEvent *pBufferedCollection_Indexed_for_AnalogCommandEvent,
    IVisitor__for__Indexed_for_AnalogCommandEvent* visitor)
{
////        ser4cpp::rseq_t copy(buffer);
  RSeq_for_Uint16_t copy;
  copy = pBufferedCollection_Indexed_for_AnalogCommandEvent->buffer;

  for (uint32_t pos = 0; pos < pBufferedCollection_Indexed_for_AnalogCommandEvent->COUNT; ++pos)
  {
//void OnValue_in_IVisitor__for__Indexed_for_AnalogCommandEvent(IVisitor__for__Indexed_for_AnalogCommandEvent *, Indexed_for_AnalogCommandEvent* );
////            visitor.OnValue(readFunc(copy, pos));
    Indexed_for_AnalogCommandEvent temp = pBufferedCollection_Indexed_for_AnalogCommandEvent->readFunc(&copy, pos);
    OnValue_in_IVisitor__for__Indexed_for_AnalogCommandEvent(visitor, &temp );
  }
}

uint16_t Count_in_BufferedCollection_Indexed_for_AnalogCommandEvent_override(void *pICollection_Indexed_for_AnalogCommandEvent)
{
  BufferedCollection_Indexed_for_AnalogCommandEvent* parent =
    (BufferedCollection_Indexed_for_AnalogCommandEvent*)getParentPointer_in_ICollection_Indexed_for_AnalogCommandEvent(
      (ICollection_Indexed_for_AnalogCommandEvent*)pICollection_Indexed_for_AnalogCommandEvent);
  return Count_in_BufferedCollection_Indexed_for_AnalogCommandEvent(parent);
}
void Foreach_in_BufferedCollection_Indexed_for_AnalogCommandEvent_override(void *pICollection_Indexed_for_AnalogCommandEvent,
    IVisitor__for__Indexed_for_AnalogCommandEvent* visitor)
{
  BufferedCollection_Indexed_for_AnalogCommandEvent* parent =
    (BufferedCollection_Indexed_for_AnalogCommandEvent*)getParentPointer_in_ICollection_Indexed_for_AnalogCommandEvent(
      (ICollection_Indexed_for_AnalogCommandEvent*)pICollection_Indexed_for_AnalogCommandEvent);
  Foreach_in_BufferedCollection_Indexed_for_AnalogCommandEvent(parent, visitor);
}
//-----------------------------------Indexed_for_AnalogCommandEvent---------------------------------------------------
//-----------------------------------Indexed_for_TimeAndInterval---------------------------------------------------
////    BufferedCollection(const ser4cpp::rseq_t& buffer, size_t count, const ReadFunc& readFunc)
////        : buffer(buffer), COUNT(count), readFunc(readFunc)
void  BufferedCollection_Indexed_for_TimeAndInterval_in_BufferedCollection_Indexed_for_TimeAndInterval(
  BufferedCollection_Indexed_for_TimeAndInterval *pBufferedCollection_Indexed_for_TimeAndInterval,
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_TimeAndInterval readFunc)
{
  pBufferedCollection_Indexed_for_TimeAndInterval->buffer = *buffer;
  pBufferedCollection_Indexed_for_TimeAndInterval->COUNT = count;
  pBufferedCollection_Indexed_for_TimeAndInterval->readFunc = readFunc;

  pBufferedCollection_Indexed_for_TimeAndInterval->iICollection_Indexed_for_TimeAndInterval.pCount_in_ICollection_Indexed_for_TimeAndInterval =
    Count_in_BufferedCollection_Indexed_for_TimeAndInterval_override;
  pBufferedCollection_Indexed_for_TimeAndInterval->iICollection_Indexed_for_TimeAndInterval.pForeach_in_ICollection_Indexed_for_TimeAndInterval =
    Foreach_in_BufferedCollection_Indexed_for_TimeAndInterval_override;

  setParentPointer_in_ICollection_Indexed_for_TimeAndInterval(&(pBufferedCollection_Indexed_for_TimeAndInterval->iICollection_Indexed_for_TimeAndInterval), pBufferedCollection_Indexed_for_TimeAndInterval);
}

////template<class T, class ReadFunc>
////BufferedCollection<T, ReadFunc> CreateBufferedCollection(const ser4cpp::rseq_t& buffer,
////                                                         size_t count,
////                                                         const ReadFunc& readFunc)
BufferedCollection_Indexed_for_TimeAndInterval CreateBufferedCollection_Indexed_for_TimeAndInterval_static(
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_TimeAndInterval readFunc)
{
////    return BufferedCollection<T, ReadFunc>(buffer, count, readFunc);
  BufferedCollection_Indexed_for_TimeAndInterval bBufferedCollection_Indexed_for_TimeAndInterval;
  BufferedCollection_Indexed_for_TimeAndInterval_in_BufferedCollection_Indexed_for_TimeAndInterval(&bBufferedCollection_Indexed_for_TimeAndInterval,
      buffer,
      count, readFunc);
  return bBufferedCollection_Indexed_for_TimeAndInterval;
}

uint16_t Count_in_BufferedCollection_Indexed_for_TimeAndInterval(BufferedCollection_Indexed_for_TimeAndInterval *pBufferedCollection_Indexed_for_TimeAndInterval)
{
  return pBufferedCollection_Indexed_for_TimeAndInterval->COUNT;
}

void Foreach_in_BufferedCollection_Indexed_for_TimeAndInterval(BufferedCollection_Indexed_for_TimeAndInterval *pBufferedCollection_Indexed_for_TimeAndInterval,
    IVisitor__for__Indexed_for_TimeAndInterval* visitor)
{
////        ser4cpp::rseq_t copy(buffer);
  RSeq_for_Uint16_t copy;
  copy = pBufferedCollection_Indexed_for_TimeAndInterval->buffer;

  for (uint32_t pos = 0; pos < pBufferedCollection_Indexed_for_TimeAndInterval->COUNT; ++pos)
  {
//void OnValue_in_IVisitor__for__Indexed_for_TimeAndInterval(IVisitor__for__Indexed_for_TimeAndInterval *, Indexed_for_TimeAndInterval* );
////            visitor.OnValue(readFunc(copy, pos));
    Indexed_for_TimeAndInterval temp = pBufferedCollection_Indexed_for_TimeAndInterval->readFunc(&copy, pos);
    OnValue_in_IVisitor__for__Indexed_for_TimeAndInterval(visitor, &temp );
  }
}

uint16_t Count_in_BufferedCollection_Indexed_for_TimeAndInterval_override(void *pICollection_Indexed_for_TimeAndInterval)
{
  BufferedCollection_Indexed_for_TimeAndInterval* parent =
    (BufferedCollection_Indexed_for_TimeAndInterval*)getParentPointer_in_ICollection_Indexed_for_TimeAndInterval(
      (ICollection_Indexed_for_TimeAndInterval*)pICollection_Indexed_for_TimeAndInterval);
  return Count_in_BufferedCollection_Indexed_for_TimeAndInterval(parent);
}
void Foreach_in_BufferedCollection_Indexed_for_TimeAndInterval_override(void *pICollection_Indexed_for_TimeAndInterval,
    IVisitor__for__Indexed_for_TimeAndInterval* visitor)
{
  BufferedCollection_Indexed_for_TimeAndInterval* parent =
    (BufferedCollection_Indexed_for_TimeAndInterval*)getParentPointer_in_ICollection_Indexed_for_TimeAndInterval(
      (ICollection_Indexed_for_TimeAndInterval*)pICollection_Indexed_for_TimeAndInterval);
  Foreach_in_BufferedCollection_Indexed_for_TimeAndInterval(parent, visitor);
}
//-----------------------------------Indexed_for_TimeAndInterval---------------------------------------------------
//-----------------------------------Indexed_for_Counter---------------------------------------------------
////    BufferedCollection(const ser4cpp::rseq_t& buffer, size_t count, const ReadFunc& readFunc)
////        : buffer(buffer), COUNT(count), readFunc(readFunc)
void  BufferedCollection_Indexed_for_Counter_in_BufferedCollection_Indexed_for_Counter(
  BufferedCollection_Indexed_for_Counter *pBufferedCollection_Indexed_for_Counter,
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_Counter readFunc)
{
  pBufferedCollection_Indexed_for_Counter->buffer = *buffer;
  pBufferedCollection_Indexed_for_Counter->COUNT = count;
  pBufferedCollection_Indexed_for_Counter->readFunc = readFunc;

  pBufferedCollection_Indexed_for_Counter->iICollection_Indexed_for_Counter.pCount_in_ICollection_Indexed_for_Counter =
    Count_in_BufferedCollection_Indexed_for_Counter_override;
  pBufferedCollection_Indexed_for_Counter->iICollection_Indexed_for_Counter.pForeach_in_ICollection_Indexed_for_Counter =
    Foreach_in_BufferedCollection_Indexed_for_Counter_override;

  setParentPointer_in_ICollection_Indexed_for_Counter(&(pBufferedCollection_Indexed_for_Counter->iICollection_Indexed_for_Counter), pBufferedCollection_Indexed_for_Counter);
}

////template<class T, class ReadFunc>
////BufferedCollection<T, ReadFunc> CreateBufferedCollection(const ser4cpp::rseq_t& buffer,
////                                                         size_t count,
////                                                         const ReadFunc& readFunc)
BufferedCollection_Indexed_for_Counter CreateBufferedCollection_Indexed_for_Counter_static(
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_Counter readFunc)
{
////    return BufferedCollection<T, ReadFunc>(buffer, count, readFunc);
  BufferedCollection_Indexed_for_Counter bBufferedCollection_Indexed_for_Counter;
  BufferedCollection_Indexed_for_Counter_in_BufferedCollection_Indexed_for_Counter(&bBufferedCollection_Indexed_for_Counter,
      buffer,
      count, readFunc);
  return bBufferedCollection_Indexed_for_Counter;
}

uint16_t Count_in_BufferedCollection_Indexed_for_Counter(BufferedCollection_Indexed_for_Counter *pBufferedCollection_Indexed_for_Counter)
{
  return pBufferedCollection_Indexed_for_Counter->COUNT;
}

void Foreach_in_BufferedCollection_Indexed_for_Counter(BufferedCollection_Indexed_for_Counter *pBufferedCollection_Indexed_for_Counter,
    IVisitor__for__Indexed_for_Counter* visitor)
{
////        ser4cpp::rseq_t copy(buffer);
  RSeq_for_Uint16_t copy;
  copy = pBufferedCollection_Indexed_for_Counter->buffer;

  for (uint32_t pos = 0; pos < pBufferedCollection_Indexed_for_Counter->COUNT; ++pos)
  {
//void OnValue_in_IVisitor__for__Indexed_for_Counter(IVisitor__for__Indexed_for_Counter *, Indexed_for_Counter* );
////            visitor.OnValue(readFunc(copy, pos));
    Indexed_for_Counter temp = pBufferedCollection_Indexed_for_Counter->readFunc(&copy, pos);
    OnValue_in_IVisitor__for__Indexed_for_Counter(visitor, &temp );
  }
}

uint16_t Count_in_BufferedCollection_Indexed_for_Counter_override(void *pICollection_Indexed_for_Counter)
{
  BufferedCollection_Indexed_for_Counter* parent =
    (BufferedCollection_Indexed_for_Counter*)getParentPointer_in_ICollection_Indexed_for_Counter(
      (ICollection_Indexed_for_Counter*)pICollection_Indexed_for_Counter);
  return Count_in_BufferedCollection_Indexed_for_Counter(parent);
}
void Foreach_in_BufferedCollection_Indexed_for_Counter_override(void *pICollection_Indexed_for_Counter,
    IVisitor__for__Indexed_for_Counter* visitor)
{
  BufferedCollection_Indexed_for_Counter* parent =
    (BufferedCollection_Indexed_for_Counter*)getParentPointer_in_ICollection_Indexed_for_Counter(
      (ICollection_Indexed_for_Counter*)pICollection_Indexed_for_Counter);
  Foreach_in_BufferedCollection_Indexed_for_Counter(parent, visitor);
}
//-----------------------------------Indexed_for_Counter---------------------------------------------------
//-----------------------------------Indexed_for_FrozenCounter---------------------------------------------------
////    BufferedCollection(const ser4cpp::rseq_t& buffer, size_t count, const ReadFunc& readFunc)
////        : buffer(buffer), COUNT(count), readFunc(readFunc)
void  BufferedCollection_Indexed_for_FrozenCounter_in_BufferedCollection_Indexed_for_FrozenCounter(
  BufferedCollection_Indexed_for_FrozenCounter *pBufferedCollection_Indexed_for_FrozenCounter,
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_FrozenCounter readFunc)
{
  pBufferedCollection_Indexed_for_FrozenCounter->buffer = *buffer;
  pBufferedCollection_Indexed_for_FrozenCounter->COUNT = count;
  pBufferedCollection_Indexed_for_FrozenCounter->readFunc = readFunc;

  pBufferedCollection_Indexed_for_FrozenCounter->iICollection_Indexed_for_FrozenCounter.pCount_in_ICollection_Indexed_for_FrozenCounter =
    Count_in_BufferedCollection_Indexed_for_FrozenCounter_override;
  pBufferedCollection_Indexed_for_FrozenCounter->iICollection_Indexed_for_FrozenCounter.pForeach_in_ICollection_Indexed_for_FrozenCounter =
    Foreach_in_BufferedCollection_Indexed_for_FrozenCounter_override;

  setParentPointer_in_ICollection_Indexed_for_FrozenCounter(&(pBufferedCollection_Indexed_for_FrozenCounter->iICollection_Indexed_for_FrozenCounter), pBufferedCollection_Indexed_for_FrozenCounter);
}

////template<class T, class ReadFunc>
////BufferedCollection<T, ReadFunc> CreateBufferedCollection(const ser4cpp::rseq_t& buffer,
////                                                         size_t count,
////                                                         const ReadFunc& readFunc)
BufferedCollection_Indexed_for_FrozenCounter CreateBufferedCollection_Indexed_for_FrozenCounter_static(
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_FrozenCounter readFunc)
{
////    return BufferedCollection<T, ReadFunc>(buffer, count, readFunc);
  BufferedCollection_Indexed_for_FrozenCounter bBufferedCollection_Indexed_for_FrozenCounter;
  BufferedCollection_Indexed_for_FrozenCounter_in_BufferedCollection_Indexed_for_FrozenCounter(&bBufferedCollection_Indexed_for_FrozenCounter,
      buffer,
      count, readFunc);
  return bBufferedCollection_Indexed_for_FrozenCounter;
}

uint16_t Count_in_BufferedCollection_Indexed_for_FrozenCounter(BufferedCollection_Indexed_for_FrozenCounter *pBufferedCollection_Indexed_for_FrozenCounter)
{
  return pBufferedCollection_Indexed_for_FrozenCounter->COUNT;
}

void Foreach_in_BufferedCollection_Indexed_for_FrozenCounter(BufferedCollection_Indexed_for_FrozenCounter *pBufferedCollection_Indexed_for_FrozenCounter,
    IVisitor__for__Indexed_for_FrozenCounter* visitor)
{
////        ser4cpp::rseq_t copy(buffer);
  RSeq_for_Uint16_t copy;
  copy = pBufferedCollection_Indexed_for_FrozenCounter->buffer;

  for (uint32_t pos = 0; pos < pBufferedCollection_Indexed_for_FrozenCounter->COUNT; ++pos)
  {
//void OnValue_in_IVisitor__for__Indexed_for_FrozenCounter(IVisitor__for__Indexed_for_FrozenCounter *, Indexed_for_FrozenCounter* );
////            visitor.OnValue(readFunc(copy, pos));
    Indexed_for_FrozenCounter temp = pBufferedCollection_Indexed_for_FrozenCounter->readFunc(&copy, pos);
    OnValue_in_IVisitor__for__Indexed_for_FrozenCounter(visitor, &temp );
  }
}

uint16_t Count_in_BufferedCollection_Indexed_for_FrozenCounter_override(void *pICollection_Indexed_for_FrozenCounter)
{
  BufferedCollection_Indexed_for_FrozenCounter* parent =
    (BufferedCollection_Indexed_for_FrozenCounter*)getParentPointer_in_ICollection_Indexed_for_FrozenCounter(
      (ICollection_Indexed_for_FrozenCounter*)pICollection_Indexed_for_FrozenCounter);
  return Count_in_BufferedCollection_Indexed_for_FrozenCounter(parent);
}
void Foreach_in_BufferedCollection_Indexed_for_FrozenCounter_override(void *pICollection_Indexed_for_FrozenCounter,
    IVisitor__for__Indexed_for_FrozenCounter* visitor)
{
  BufferedCollection_Indexed_for_FrozenCounter* parent =
    (BufferedCollection_Indexed_for_FrozenCounter*)getParentPointer_in_ICollection_Indexed_for_FrozenCounter(
      (ICollection_Indexed_for_FrozenCounter*)pICollection_Indexed_for_FrozenCounter);
  Foreach_in_BufferedCollection_Indexed_for_FrozenCounter(parent, visitor);
}
//-----------------------------------Indexed_for_FrozenCounter---------------------------------------------------
//-----------------------------------Indexed_for_Analog---------------------------------------------------
////    BufferedCollection(const ser4cpp::rseq_t& buffer, size_t count, const ReadFunc& readFunc)
////        : buffer(buffer), COUNT(count), readFunc(readFunc)
void  BufferedCollection_Indexed_for_Analog_in_BufferedCollection_Indexed_for_Analog(
  BufferedCollection_Indexed_for_Analog *pBufferedCollection_Indexed_for_Analog,
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_Analog readFunc)
{
  pBufferedCollection_Indexed_for_Analog->buffer = *buffer;
  pBufferedCollection_Indexed_for_Analog->COUNT = count;
  pBufferedCollection_Indexed_for_Analog->readFunc = readFunc;

  pBufferedCollection_Indexed_for_Analog->iICollection_Indexed_for_Analog.pCount_in_ICollection_Indexed_for_Analog =
    Count_in_BufferedCollection_Indexed_for_Analog_override;
  pBufferedCollection_Indexed_for_Analog->iICollection_Indexed_for_Analog.pForeach_in_ICollection_Indexed_for_Analog =
    Foreach_in_BufferedCollection_Indexed_for_Analog_override;

  setParentPointer_in_ICollection_Indexed_for_Analog(&(pBufferedCollection_Indexed_for_Analog->iICollection_Indexed_for_Analog), pBufferedCollection_Indexed_for_Analog);
}

////template<class T, class ReadFunc>
////BufferedCollection<T, ReadFunc> CreateBufferedCollection(const ser4cpp::rseq_t& buffer,
////                                                         size_t count,
////                                                         const ReadFunc& readFunc)
BufferedCollection_Indexed_for_Analog CreateBufferedCollection_Indexed_for_Analog_static(
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_Analog readFunc)
{
////    return BufferedCollection<T, ReadFunc>(buffer, count, readFunc);
  BufferedCollection_Indexed_for_Analog bBufferedCollection_Indexed_for_Analog;
  BufferedCollection_Indexed_for_Analog_in_BufferedCollection_Indexed_for_Analog(&bBufferedCollection_Indexed_for_Analog,
      buffer,
      count, readFunc);
  return bBufferedCollection_Indexed_for_Analog;
}

uint16_t Count_in_BufferedCollection_Indexed_for_Analog(BufferedCollection_Indexed_for_Analog *pBufferedCollection_Indexed_for_Analog)
{
  return pBufferedCollection_Indexed_for_Analog->COUNT;
}

void Foreach_in_BufferedCollection_Indexed_for_Analog(BufferedCollection_Indexed_for_Analog *pBufferedCollection_Indexed_for_Analog,
    IVisitor__for__Indexed_for_Analog* visitor)
{
////        ser4cpp::rseq_t copy(buffer);
  RSeq_for_Uint16_t copy;
  copy = pBufferedCollection_Indexed_for_Analog->buffer;

  for (uint32_t pos = 0; pos < pBufferedCollection_Indexed_for_Analog->COUNT; ++pos)
  {
//void OnValue_in_IVisitor__for__Indexed_for_Analog(IVisitor__for__Indexed_for_Analog *, Indexed_for_Analog* );
////            visitor.OnValue(readFunc(copy, pos));
    Indexed_for_Analog temp = pBufferedCollection_Indexed_for_Analog->readFunc(&copy, pos);
    OnValue_in_IVisitor__for__Indexed_for_Analog(visitor, &temp );
  }
}

uint16_t Count_in_BufferedCollection_Indexed_for_Analog_override(void *pICollection_Indexed_for_Analog)
{
  BufferedCollection_Indexed_for_Analog* parent =
    (BufferedCollection_Indexed_for_Analog*)getParentPointer_in_ICollection_Indexed_for_Analog(
      (ICollection_Indexed_for_Analog*)pICollection_Indexed_for_Analog);
  return Count_in_BufferedCollection_Indexed_for_Analog(parent);
}
void Foreach_in_BufferedCollection_Indexed_for_Analog_override(void *pICollection_Indexed_for_Analog,
    IVisitor__for__Indexed_for_Analog* visitor)
{
  BufferedCollection_Indexed_for_Analog* parent =
    (BufferedCollection_Indexed_for_Analog*)getParentPointer_in_ICollection_Indexed_for_Analog(
      (ICollection_Indexed_for_Analog*)pICollection_Indexed_for_Analog);
  Foreach_in_BufferedCollection_Indexed_for_Analog(parent, visitor);
}
//-----------------------------------Indexed_for_Analog---------------------------------------------------
//-----------------------------------Indexed_for_AnalogOutputStatus---------------------------------------------------
////    BufferedCollection(const ser4cpp::rseq_t& buffer, size_t count, const ReadFunc& readFunc)
////        : buffer(buffer), COUNT(count), readFunc(readFunc)
void  BufferedCollection_Indexed_for_AnalogOutputStatus_in_BufferedCollection_Indexed_for_AnalogOutputStatus(
  BufferedCollection_Indexed_for_AnalogOutputStatus *pBufferedCollection_Indexed_for_AnalogOutputStatus,
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_AnalogOutputStatus readFunc)
{
  pBufferedCollection_Indexed_for_AnalogOutputStatus->buffer = *buffer;
  pBufferedCollection_Indexed_for_AnalogOutputStatus->COUNT = count;
  pBufferedCollection_Indexed_for_AnalogOutputStatus->readFunc = readFunc;

  pBufferedCollection_Indexed_for_AnalogOutputStatus->iICollection_Indexed_for_AnalogOutputStatus.pCount_in_ICollection_Indexed_for_AnalogOutputStatus =
    Count_in_BufferedCollection_Indexed_for_AnalogOutputStatus_override;
  pBufferedCollection_Indexed_for_AnalogOutputStatus->iICollection_Indexed_for_AnalogOutputStatus.pForeach_in_ICollection_Indexed_for_AnalogOutputStatus =
    Foreach_in_BufferedCollection_Indexed_for_AnalogOutputStatus_override;

  setParentPointer_in_ICollection_Indexed_for_AnalogOutputStatus(&(pBufferedCollection_Indexed_for_AnalogOutputStatus->iICollection_Indexed_for_AnalogOutputStatus), pBufferedCollection_Indexed_for_AnalogOutputStatus);
}

////template<class T, class ReadFunc>
////BufferedCollection<T, ReadFunc> CreateBufferedCollection(const ser4cpp::rseq_t& buffer,
////                                                         size_t count,
////                                                         const ReadFunc& readFunc)
BufferedCollection_Indexed_for_AnalogOutputStatus CreateBufferedCollection_Indexed_for_AnalogOutputStatus_static(
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_AnalogOutputStatus readFunc)
{
////    return BufferedCollection<T, ReadFunc>(buffer, count, readFunc);
  BufferedCollection_Indexed_for_AnalogOutputStatus bBufferedCollection_Indexed_for_AnalogOutputStatus;
  BufferedCollection_Indexed_for_AnalogOutputStatus_in_BufferedCollection_Indexed_for_AnalogOutputStatus(&bBufferedCollection_Indexed_for_AnalogOutputStatus,
      buffer,
      count, readFunc);
  return bBufferedCollection_Indexed_for_AnalogOutputStatus;
}

uint16_t Count_in_BufferedCollection_Indexed_for_AnalogOutputStatus(BufferedCollection_Indexed_for_AnalogOutputStatus *pBufferedCollection_Indexed_for_AnalogOutputStatus)
{
  return pBufferedCollection_Indexed_for_AnalogOutputStatus->COUNT;
}

void Foreach_in_BufferedCollection_Indexed_for_AnalogOutputStatus(BufferedCollection_Indexed_for_AnalogOutputStatus *pBufferedCollection_Indexed_for_AnalogOutputStatus,
    IVisitor__for__Indexed_for_AnalogOutputStatus* visitor)
{
////        ser4cpp::rseq_t copy(buffer);
  RSeq_for_Uint16_t copy;
  copy = pBufferedCollection_Indexed_for_AnalogOutputStatus->buffer;

  for (uint32_t pos = 0; pos < pBufferedCollection_Indexed_for_AnalogOutputStatus->COUNT; ++pos)
  {
//void OnValue_in_IVisitor__for__Indexed_for_AnalogOutputStatus(IVisitor__for__Indexed_for_AnalogOutputStatus *, Indexed_for_AnalogOutputStatus* );
////            visitor.OnValue(readFunc(copy, pos));
    Indexed_for_AnalogOutputStatus temp = pBufferedCollection_Indexed_for_AnalogOutputStatus->readFunc(&copy, pos);
    OnValue_in_IVisitor__for__Indexed_for_AnalogOutputStatus(visitor, &temp );
  }
}

uint16_t Count_in_BufferedCollection_Indexed_for_AnalogOutputStatus_override(void *pICollection_Indexed_for_AnalogOutputStatus)
{
  BufferedCollection_Indexed_for_AnalogOutputStatus* parent =
    (BufferedCollection_Indexed_for_AnalogOutputStatus*)getParentPointer_in_ICollection_Indexed_for_AnalogOutputStatus(
      (ICollection_Indexed_for_AnalogOutputStatus*)pICollection_Indexed_for_AnalogOutputStatus);
  return Count_in_BufferedCollection_Indexed_for_AnalogOutputStatus(parent);
}
void Foreach_in_BufferedCollection_Indexed_for_AnalogOutputStatus_override(void *pICollection_Indexed_for_AnalogOutputStatus,
    IVisitor__for__Indexed_for_AnalogOutputStatus* visitor)
{
  BufferedCollection_Indexed_for_AnalogOutputStatus* parent =
    (BufferedCollection_Indexed_for_AnalogOutputStatus*)getParentPointer_in_ICollection_Indexed_for_AnalogOutputStatus(
      (ICollection_Indexed_for_AnalogOutputStatus*)pICollection_Indexed_for_AnalogOutputStatus);
  Foreach_in_BufferedCollection_Indexed_for_AnalogOutputStatus(parent, visitor);
}
//-----------------------------------Indexed_for_AnalogOutputStatus---------------------------------------------------
