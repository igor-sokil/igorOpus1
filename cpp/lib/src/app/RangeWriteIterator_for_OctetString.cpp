#include "header.h"
#include "RangeWriteIterator_for_OctetString.h"
#include "SerializationTemplates.h"
#include <string.h>

//-------------------Uint16---------------------------------------------------
RangeWriteIterator_for_UInt16_OctetString Null_in_RangeWriteIterator_for_UInt16_OctetString_static(void)
{
  RangeWriteIterator_for_UInt16_OctetString rRangeWriteIterator_for_UInt16_OctetString;
  RangeWriteIterator_for_UInt16_OctetString_in_RangeWriteIterator_for_UInt16_OctetStringOver1(&rRangeWriteIterator_for_UInt16_OctetString);
//    return RangeWriteIterator();
  return rRangeWriteIterator_for_UInt16_OctetString;
}

////    RangeWriteIterator() : start(0), count(0), isValid(false), pPosition(nullptr) {}
void RangeWriteIterator_for_UInt16_OctetString_in_RangeWriteIterator_for_UInt16_OctetStringOver1(RangeWriteIterator_for_UInt16_OctetString *pRangeWriteIterator_for_UInt16_OctetString)
{
  pRangeWriteIterator_for_UInt16_OctetString->start = 0;
  pRangeWriteIterator_for_UInt16_OctetString->count = 0;
  pRangeWriteIterator_for_UInt16_OctetString->isValid = false;
  pRangeWriteIterator_for_UInt16_OctetString->pPosition = NULL;
}

void RangeWriteIterator_for_UInt16_OctetString_in_RangeWriteIterator_for_UInt16_OctetStringOver2(RangeWriteIterator_for_UInt16_OctetString *pRangeWriteIterator_for_UInt16_OctetString,
//                   typename IndexType::type_t start_,
    uint16_t start_,
//                   const Serializer<WriteType>& serializer,
    Serializer_for_OctetString*  serializer,
//                   ser4cpp::wseq_t& position)
    WSeq_for_Uint16_t* position)
{
  pRangeWriteIterator_for_UInt16_OctetString->start = start_;
  pRangeWriteIterator_for_UInt16_OctetString->serializer = *serializer;
  pRangeWriteIterator_for_UInt16_OctetString->count = 0;
//     isValid = position.length() >= 2 * IndexType::size),
  pRangeWriteIterator_for_UInt16_OctetString->isValid = length_in_HasLength_for_Uint16_t(&(position->hHasLength)) >= 2 * size_in_UInt8;

  pRangeWriteIterator_for_UInt16_OctetString->range = *position;
  pRangeWriteIterator_for_UInt16_OctetString->pPosition = position;

  if (pRangeWriteIterator_for_UInt16_OctetString->isValid)
  {
//        IndexType::write_to(range, start);
    write_to_in_UInt8_static(&(pRangeWriteIterator_for_UInt16_OctetString->range), pRangeWriteIterator_for_UInt16_OctetString->start);
//        pPosition->advance(2 * IndexType::size);
    advance_in_WSeq_for_Uint16_t(pRangeWriteIterator_for_UInt16_OctetString->pPosition, 2 * size_in_UInt8);
  }
}

////    ~RangeWriteIterator()
void RangeWriteIterator_for_UInt16_OctetString_destr_RangeWriteIterator_for_UInt16_OctetString(RangeWriteIterator_for_UInt16_OctetString *pRangeWriteIterator_for_UInt16_OctetString)
{
  if (pRangeWriteIterator_for_UInt16_OctetString->isValid && pRangeWriteIterator_for_UInt16_OctetString->count > 0)
  {
    uint32_t stop = pRangeWriteIterator_for_UInt16_OctetString->start + pRangeWriteIterator_for_UInt16_OctetString->count - 1;
//        IndexType::write_to(range, static_cast<typename IndexType::type_t>(stop));
    write_to_in_UInt8_static(&(pRangeWriteIterator_for_UInt16_OctetString->range), (uint8_t)(stop));
  }
}

//    bool Write(const WriteType& value)
boolean Write_in_RangeWriteIterator_for_UInt16_OctetString(RangeWriteIterator_for_UInt16_OctetString *pRangeWriteIterator_for_UInt16_OctetString,
    OctetString* value)
{
//    if (isValid && (pPosition->length() >= serializer.get_size()) && (count <= IndexType::max_value))
  if(pRangeWriteIterator_for_UInt16_OctetString->isValid &&
      (length_in_HasLength_for_Uint16_t(&(pRangeWriteIterator_for_UInt16_OctetString->pPosition->hHasLength)) >=
       get_size_in_Serializer_for_OctetString(&(pRangeWriteIterator_for_UInt16_OctetString->serializer)))  &&
      (pRangeWriteIterator_for_UInt16_OctetString->count <= max_value_in_UInt8))
  {
//        serializer.write(value, *pPosition);
    write_in_Serializer_for_OctetString(&(pRangeWriteIterator_for_UInt16_OctetString->serializer), value, pRangeWriteIterator_for_UInt16_OctetString->pPosition);
    ++(pRangeWriteIterator_for_UInt16_OctetString->count);
    return true;
  }
  else
  {
    return false;
  }
}

boolean IsValid_in_RangeWriteIterator_for_UInt16_OctetString(RangeWriteIterator_for_UInt16_OctetString *pRangeWriteIterator_for_UInt16_OctetString)
{
  return pRangeWriteIterator_for_UInt16_OctetString->isValid;
}
//-------------------Uint16---------------------------------------------------
