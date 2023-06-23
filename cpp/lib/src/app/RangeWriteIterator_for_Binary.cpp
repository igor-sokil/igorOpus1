#include "header.h"
#include "RangeWriteIterator_for_Binary.h"
#include "SerializationTemplates.h"
#include <string.h>
//-------------------Uint8---------------------------------------------------
RangeWriteIterator_for_UInt8_Binary Null_in_RangeWriteIterator_for_UInt8_Binary_static(void)
{
  RangeWriteIterator_for_UInt8_Binary rRangeWriteIterator_for_UInt8_Binary;
  RangeWriteIterator_for_UInt8_Binary_in_RangeWriteIterator_for_UInt8_BinaryOver1(&rRangeWriteIterator_for_UInt8_Binary);
//    return RangeWriteIterator();
  return rRangeWriteIterator_for_UInt8_Binary;
}

////    RangeWriteIterator() : start(0), count(0), isValid(false), pPosition(nullptr) {}
void RangeWriteIterator_for_UInt8_Binary_in_RangeWriteIterator_for_UInt8_BinaryOver1(RangeWriteIterator_for_UInt8_Binary *pRangeWriteIterator_for_UInt8_Binary)
{
  pRangeWriteIterator_for_UInt8_Binary->start = 0;
  pRangeWriteIterator_for_UInt8_Binary->count = 0;
  pRangeWriteIterator_for_UInt8_Binary->isValid = false;
  pRangeWriteIterator_for_UInt8_Binary->pPosition = NULL;
}

void RangeWriteIterator_for_UInt8_Binary_in_RangeWriteIterator_for_UInt8_BinaryOver2(RangeWriteIterator_for_UInt8_Binary *pRangeWriteIterator_for_UInt8_Binary,
//                   typename IndexType::type_t start_,
    uint8_t start_,
//                   const Serializer<WriteType>& serializer,
    Serializer_for_Binary*  serializer,
//                   ser4cpp::wseq_t& position)
    WSeq_for_Uint16_t* position)
{
  pRangeWriteIterator_for_UInt8_Binary->start = start_;
  pRangeWriteIterator_for_UInt8_Binary->serializer = *serializer;
  pRangeWriteIterator_for_UInt8_Binary->count = 0;
//     isValid = position.length() >= 2 * IndexType::size),
  pRangeWriteIterator_for_UInt8_Binary->isValid = length_in_HasLength_for_Uint16_t(&(position->hHasLength)) >= 2 * size_in_UInt8;

  pRangeWriteIterator_for_UInt8_Binary->range = *position;
  pRangeWriteIterator_for_UInt8_Binary->pPosition = position;

  if (pRangeWriteIterator_for_UInt8_Binary->isValid)
  {
//        IndexType::write_to(range, start);
    write_to_in_UInt8_static(&(pRangeWriteIterator_for_UInt8_Binary->range), pRangeWriteIterator_for_UInt8_Binary->start);
//        pPosition->advance(2 * IndexType::size);
    advance_in_WSeq_for_Uint16_t(pRangeWriteIterator_for_UInt8_Binary->pPosition, 2 * size_in_UInt8);
  }
}

////    ~RangeWriteIterator()
void RangeWriteIterator_for_UInt8_Binary_destr_RangeWriteIterator_for_UInt8_Binary(RangeWriteIterator_for_UInt8_Binary *pRangeWriteIterator_for_UInt8_Binary)
{
  if (pRangeWriteIterator_for_UInt8_Binary->isValid && pRangeWriteIterator_for_UInt8_Binary->count > 0)
  {
    uint32_t stop = pRangeWriteIterator_for_UInt8_Binary->start + pRangeWriteIterator_for_UInt8_Binary->count - 1;
//        IndexType::write_to(range, static_cast<typename IndexType::type_t>(stop));
    write_to_in_UInt8_static(&(pRangeWriteIterator_for_UInt8_Binary->range), (uint8_t)(stop));
  }
}

//    bool Write(const WriteType& value)
boolean Write_in_RangeWriteIterator_for_UInt8_Binary(RangeWriteIterator_for_UInt8_Binary *pRangeWriteIterator_for_UInt8_Binary,
    Binary* value)
{
//    if (isValid && (pPosition->length() >= serializer.get_size()) && (count <= IndexType::max_value))
  if(pRangeWriteIterator_for_UInt8_Binary->isValid &&
      (length_in_HasLength_for_Uint16_t(&(pRangeWriteIterator_for_UInt8_Binary->pPosition->hHasLength)) >=
       get_size_in_Serializer_for_Binary(&(pRangeWriteIterator_for_UInt8_Binary->serializer)))  &&
      (pRangeWriteIterator_for_UInt8_Binary->count <= max_value_in_UInt8))
  {
//        serializer.write(value, *pPosition);
    write_in_Serializer_for_Binary(&(pRangeWriteIterator_for_UInt8_Binary->serializer), value, pRangeWriteIterator_for_UInt8_Binary->pPosition);
    ++(pRangeWriteIterator_for_UInt8_Binary->count);
    return true;
  }
  else
  {
    return false;
  }
}

boolean IsValid_in_RangeWriteIterator_for_UInt8_Binary(RangeWriteIterator_for_UInt8_Binary *pRangeWriteIterator_for_UInt8_Binary)
{
  return pRangeWriteIterator_for_UInt8_Binary->isValid;
}
//-------------------Uint8---------------------------------------------------
