#include "header.h"
#include "RangeWriteIterator_for_DoubleBitBinary.h"
#include "SerializationTemplates.h"
#include <string.h>

//-------------------Uint8---------------------------------------------------
RangeWriteIterator_for_UInt8_DoubleBitBinary Null_in_RangeWriteIterator_for_UInt8_DoubleBitBinary_static(void)
{
  RangeWriteIterator_for_UInt8_DoubleBitBinary rRangeWriteIterator_for_UInt8_DoubleBitBinary;
  RangeWriteIterator_for_UInt8_DoubleBitBinary_in_RangeWriteIterator_for_UInt8_DoubleBitBinaryOver1(&rRangeWriteIterator_for_UInt8_DoubleBitBinary);
//    return RangeWriteIterator();
  return rRangeWriteIterator_for_UInt8_DoubleBitBinary;
}

////    RangeWriteIterator() : start(0), count(0), isValid(false), pPosition(nullptr) {}
void RangeWriteIterator_for_UInt8_DoubleBitBinary_in_RangeWriteIterator_for_UInt8_DoubleBitBinaryOver1(RangeWriteIterator_for_UInt8_DoubleBitBinary *pRangeWriteIterator_for_UInt8_DoubleBitBinary)
{
  pRangeWriteIterator_for_UInt8_DoubleBitBinary->start = 0;
  pRangeWriteIterator_for_UInt8_DoubleBitBinary->count = 0;
  pRangeWriteIterator_for_UInt8_DoubleBitBinary->isValid = false;
  pRangeWriteIterator_for_UInt8_DoubleBitBinary->pPosition = NULL;
}

void RangeWriteIterator_for_UInt8_DoubleBitBinary_in_RangeWriteIterator_for_UInt8_DoubleBitBinaryOver2(RangeWriteIterator_for_UInt8_DoubleBitBinary *pRangeWriteIterator_for_UInt8_DoubleBitBinary,
//                   typename IndexType::type_t start_,
    uint8_t start_,
//                   const Serializer<WriteType>& serializer,
    Serializer_for_DoubleBitBinary*  serializer,
//                   ser4cpp::wseq_t& position)
    WSeq_for_Uint16_t* position)
{
  pRangeWriteIterator_for_UInt8_DoubleBitBinary->start = start_;
  pRangeWriteIterator_for_UInt8_DoubleBitBinary->serializer = *serializer;
  pRangeWriteIterator_for_UInt8_DoubleBitBinary->count = 0;
//     isValid = position.length() >= 2 * IndexType::size),
  pRangeWriteIterator_for_UInt8_DoubleBitBinary->isValid = length_in_HasLength_for_Uint16_t(&(position->hHasLength)) >= 2 * size_in_UInt8;

  pRangeWriteIterator_for_UInt8_DoubleBitBinary->range = *position;
  pRangeWriteIterator_for_UInt8_DoubleBitBinary->pPosition = position;

  if (pRangeWriteIterator_for_UInt8_DoubleBitBinary->isValid)
  {
//        IndexType::write_to(range, start);
    write_to_in_UInt8_static(&(pRangeWriteIterator_for_UInt8_DoubleBitBinary->range), pRangeWriteIterator_for_UInt8_DoubleBitBinary->start);
//        pPosition->advance(2 * IndexType::size);
    advance_in_WSeq_for_Uint16_t(pRangeWriteIterator_for_UInt8_DoubleBitBinary->pPosition, 2 * size_in_UInt8);
  }
}

////    ~RangeWriteIterator()
void RangeWriteIterator_for_UInt8_DoubleBitBinary_destr_RangeWriteIterator_for_UInt8_DoubleBitBinary(RangeWriteIterator_for_UInt8_DoubleBitBinary *pRangeWriteIterator_for_UInt8_DoubleBitBinary)
{
  if (pRangeWriteIterator_for_UInt8_DoubleBitBinary->isValid && pRangeWriteIterator_for_UInt8_DoubleBitBinary->count > 0)
  {
    uint32_t stop = pRangeWriteIterator_for_UInt8_DoubleBitBinary->start + pRangeWriteIterator_for_UInt8_DoubleBitBinary->count - 1;
//        IndexType::write_to(range, static_cast<typename IndexType::type_t>(stop));
    write_to_in_UInt8_static(&(pRangeWriteIterator_for_UInt8_DoubleBitBinary->range), (uint8_t)(stop));
  }
}

//    bool Write(const WriteType& value)
boolean Write_in_RangeWriteIterator_for_UInt8_DoubleBitBinary(RangeWriteIterator_for_UInt8_DoubleBitBinary *pRangeWriteIterator_for_UInt8_DoubleBitBinary,
    DoubleBitBinary* value)
{
//    if (isValid && (pPosition->length() >= serializer.get_size()) && (count <= IndexType::max_value))
  if(pRangeWriteIterator_for_UInt8_DoubleBitBinary->isValid &&
      (length_in_HasLength_for_Uint16_t(&(pRangeWriteIterator_for_UInt8_DoubleBitBinary->pPosition->hHasLength)) >=
       get_size_in_Serializer_for_DoubleBitBinary(&(pRangeWriteIterator_for_UInt8_DoubleBitBinary->serializer)))  &&
      (pRangeWriteIterator_for_UInt8_DoubleBitBinary->count <= max_value_in_UInt8))
  {
//        serializer.write(value, *pPosition);
    write_in_Serializer_for_DoubleBitBinary(&(pRangeWriteIterator_for_UInt8_DoubleBitBinary->serializer), value, pRangeWriteIterator_for_UInt8_DoubleBitBinary->pPosition);
    ++(pRangeWriteIterator_for_UInt8_DoubleBitBinary->count);
    return true;
  }
  else
  {
    return false;
  }
}

boolean IsValid_in_RangeWriteIterator_for_UInt8_DoubleBitBinary(RangeWriteIterator_for_UInt8_DoubleBitBinary *pRangeWriteIterator_for_UInt8_DoubleBitBinary)
{
  return pRangeWriteIterator_for_UInt8_DoubleBitBinary->isValid;
}
//-------------------Uint8---------------------------------------------------
//-------------------Uint16---------------------------------------------------
RangeWriteIterator_for_UInt16_DoubleBitBinary Null_in_RangeWriteIterator_for_UInt16_DoubleBitBinary_static(void)
{
  RangeWriteIterator_for_UInt16_DoubleBitBinary rRangeWriteIterator_for_UInt16_DoubleBitBinary;
  RangeWriteIterator_for_UInt16_DoubleBitBinary_in_RangeWriteIterator_for_UInt16_DoubleBitBinaryOver1(&rRangeWriteIterator_for_UInt16_DoubleBitBinary);
//    return RangeWriteIterator();
  return rRangeWriteIterator_for_UInt16_DoubleBitBinary;
}

////    RangeWriteIterator() : start(0), count(0), isValid(false), pPosition(nullptr) {}
void RangeWriteIterator_for_UInt16_DoubleBitBinary_in_RangeWriteIterator_for_UInt16_DoubleBitBinaryOver1(RangeWriteIterator_for_UInt16_DoubleBitBinary *pRangeWriteIterator_for_UInt16_DoubleBitBinary)
{
  pRangeWriteIterator_for_UInt16_DoubleBitBinary->start = 0;
  pRangeWriteIterator_for_UInt16_DoubleBitBinary->count = 0;
  pRangeWriteIterator_for_UInt16_DoubleBitBinary->isValid = false;
  pRangeWriteIterator_for_UInt16_DoubleBitBinary->pPosition = NULL;
}

void RangeWriteIterator_for_UInt16_DoubleBitBinary_in_RangeWriteIterator_for_UInt16_DoubleBitBinaryOver2(RangeWriteIterator_for_UInt16_DoubleBitBinary *pRangeWriteIterator_for_UInt16_DoubleBitBinary,
//                   typename IndexType::type_t start_,
    uint16_t start_,
//                   const Serializer<WriteType>& serializer,
    Serializer_for_DoubleBitBinary*  serializer,
//                   ser4cpp::wseq_t& position)
    WSeq_for_Uint16_t* position)
{
  pRangeWriteIterator_for_UInt16_DoubleBitBinary->start = start_;
  pRangeWriteIterator_for_UInt16_DoubleBitBinary->serializer = *serializer;
  pRangeWriteIterator_for_UInt16_DoubleBitBinary->count = 0;
//     isValid = position.length() >= 2 * IndexType::size),
  pRangeWriteIterator_for_UInt16_DoubleBitBinary->isValid = length_in_HasLength_for_Uint16_t(&(position->hHasLength)) >= 2 * size_in_UInt16;

  pRangeWriteIterator_for_UInt16_DoubleBitBinary->range = *position;
  pRangeWriteIterator_for_UInt16_DoubleBitBinary->pPosition = position;

  if (pRangeWriteIterator_for_UInt16_DoubleBitBinary->isValid)
  {
//        IndexType::write_to(range, start);
    write_to_in_UInt16_static(&(pRangeWriteIterator_for_UInt16_DoubleBitBinary->range), pRangeWriteIterator_for_UInt16_DoubleBitBinary->start);
//        pPosition->advance(2 * IndexType::size);
    advance_in_WSeq_for_Uint16_t(pRangeWriteIterator_for_UInt16_DoubleBitBinary->pPosition, 2 * size_in_UInt16);
  }
}

////    ~RangeWriteIterator()
void RangeWriteIterator_for_UInt16_DoubleBitBinary_destr_RangeWriteIterator_for_UInt16_DoubleBitBinary(RangeWriteIterator_for_UInt16_DoubleBitBinary *pRangeWriteIterator_for_UInt16_DoubleBitBinary)
{
  if (pRangeWriteIterator_for_UInt16_DoubleBitBinary->isValid && pRangeWriteIterator_for_UInt16_DoubleBitBinary->count > 0)
  {
    uint32_t stop = pRangeWriteIterator_for_UInt16_DoubleBitBinary->start + pRangeWriteIterator_for_UInt16_DoubleBitBinary->count - 1;
//        IndexType::write_to(range, static_cast<typename IndexType::type_t>(stop));
    write_to_in_UInt16_static(&(pRangeWriteIterator_for_UInt16_DoubleBitBinary->range), (uint16_t)(stop));
  }
}

//    bool Write(const WriteType& value)
boolean Write_in_RangeWriteIterator_for_UInt16_DoubleBitBinary(RangeWriteIterator_for_UInt16_DoubleBitBinary *pRangeWriteIterator_for_UInt16_DoubleBitBinary,
    DoubleBitBinary* value)
{
//    if (isValid && (pPosition->length() >= serializer.get_size()) && (count <= IndexType::max_value))
  if(pRangeWriteIterator_for_UInt16_DoubleBitBinary->isValid &&
      (length_in_HasLength_for_Uint16_t(&(pRangeWriteIterator_for_UInt16_DoubleBitBinary->pPosition->hHasLength)) >=
       get_size_in_Serializer_for_DoubleBitBinary(&(pRangeWriteIterator_for_UInt16_DoubleBitBinary->serializer)))  &&
      (pRangeWriteIterator_for_UInt16_DoubleBitBinary->count <= max_value_in_UInt16))
  {
//        serializer.write(value, *pPosition);
    write_in_Serializer_for_DoubleBitBinary(&(pRangeWriteIterator_for_UInt16_DoubleBitBinary->serializer), value, pRangeWriteIterator_for_UInt16_DoubleBitBinary->pPosition);
    ++(pRangeWriteIterator_for_UInt16_DoubleBitBinary->count);
    return true;
  }
  else
  {
    return false;
  }
}

boolean IsValid_in_RangeWriteIterator_for_UInt16_DoubleBitBinary(RangeWriteIterator_for_UInt16_DoubleBitBinary *pRangeWriteIterator_for_UInt16_DoubleBitBinary)
{
  return pRangeWriteIterator_for_UInt16_DoubleBitBinary->isValid;
}
//-------------------Uint16---------------------------------------------------
