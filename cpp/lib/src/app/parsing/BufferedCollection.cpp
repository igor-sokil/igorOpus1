#include "header.h"
#include "BufferedCollection.h"

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
