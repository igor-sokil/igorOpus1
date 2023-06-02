#include "header.h"
#include "RangeWriteIterator_for_UInt8_Counter.h"
#include "SerializationTemplates.h"
#include <string.h>

RangeWriteIterator_for_UInt8_Counter Null_in_RangeWriteIterator_for_UInt8_Counter_static(void)
{
  RangeWriteIterator_for_UInt8_Counter rRangeWriteIterator_for_UInt8_Counter;
  RangeWriteIterator_for_UInt8_Counter_in_RangeWriteIterator_for_UInt8_CounterOver1(&rRangeWriteIterator_for_UInt8_Counter);
//    return RangeWriteIterator();
  return rRangeWriteIterator_for_UInt8_Counter;
}

////    RangeWriteIterator() : start(0), count(0), isValid(false), pPosition(nullptr) {}
void RangeWriteIterator_for_UInt8_Counter_in_RangeWriteIterator_for_UInt8_CounterOver1(RangeWriteIterator_for_UInt8_Counter *pRangeWriteIterator_for_UInt8_Counter)
{
  pRangeWriteIterator_for_UInt8_Counter->start = 0;
  pRangeWriteIterator_for_UInt8_Counter->count = 0;
  pRangeWriteIterator_for_UInt8_Counter->isValid = false;
  pRangeWriteIterator_for_UInt8_Counter->pPosition = NULL;
}

void RangeWriteIterator_for_UInt8_Counter_in_RangeWriteIterator_for_UInt8_CounterOver2(RangeWriteIterator_for_UInt8_Counter *pRangeWriteIterator_for_UInt8_Counter,
//                   typename IndexType::type_t start_,
    uint8_t start_,
//                   const Serializer<WriteType>& serializer,
    Serializer_for_Counter*  serializer,
//                   ser4cpp::wseq_t& position)
    WSeq_for_Uint16_t* position)
{
  pRangeWriteIterator_for_UInt8_Counter->start = start_;
  pRangeWriteIterator_for_UInt8_Counter->serializer = *serializer;
  pRangeWriteIterator_for_UInt8_Counter->count = 0;
//     isValid = position.length() >= 2 * IndexType::size),
  pRangeWriteIterator_for_UInt8_Counter->isValid = length_in_HasLength_for_Uint16_t(&(position->hHasLength)) >= 2 * size_in_UInt8;

  pRangeWriteIterator_for_UInt8_Counter->range = *position;
  pRangeWriteIterator_for_UInt8_Counter->pPosition = position;

  if (pRangeWriteIterator_for_UInt8_Counter->isValid)
  {
//        IndexType::write_to(range, start);
    write_to_in_UInt8_static(&(pRangeWriteIterator_for_UInt8_Counter->range), pRangeWriteIterator_for_UInt8_Counter->start);
//        pPosition->advance(2 * IndexType::size);
    advance_in_WSeq_for_Uint16_t(pRangeWriteIterator_for_UInt8_Counter->pPosition, 2 * size_in_UInt8);
  }
}

////    ~RangeWriteIterator()
void RangeWriteIterator_for_UInt8_Counter_destr_RangeWriteIterator_for_UInt8_Counter(RangeWriteIterator_for_UInt8_Counter *pRangeWriteIterator_for_UInt8_Counter)
{
  if (pRangeWriteIterator_for_UInt8_Counter->isValid && pRangeWriteIterator_for_UInt8_Counter->count > 0)
  {
    uint32_t stop = pRangeWriteIterator_for_UInt8_Counter->start + pRangeWriteIterator_for_UInt8_Counter->count - 1;
//        IndexType::write_to(range, static_cast<typename IndexType::type_t>(stop));
    write_to_in_UInt8_static(&(pRangeWriteIterator_for_UInt8_Counter->range), (uint8_t)(stop));
  }
}

//    bool Write(const WriteType& value)
boolean Write_in_RangeWriteIterator_for_UInt8_Counter(RangeWriteIterator_for_UInt8_Counter *pRangeWriteIterator_for_UInt8_Counter,
    Counter* value)
{
//    if (isValid && (pPosition->length() >= serializer.get_size()) && (count <= IndexType::max_value))
  if(pRangeWriteIterator_for_UInt8_Counter->isValid &&
      (length_in_HasLength_for_Uint16_t(&(pRangeWriteIterator_for_UInt8_Counter->pPosition->hHasLength)) >=
       get_size_in_Serializer_for_Counter(&(pRangeWriteIterator_for_UInt8_Counter->serializer)))  &&
      (pRangeWriteIterator_for_UInt8_Counter->count <= max_value_in_UInt8))
  {
//        serializer.write(value, *pPosition);
    write_in_Serializer_for_Counter(&(pRangeWriteIterator_for_UInt8_Counter->serializer), value, pRangeWriteIterator_for_UInt8_Counter->pPosition);
    ++(pRangeWriteIterator_for_UInt8_Counter->count);
    return true;
  }
  else
  {
    return false;
  }
}

boolean IsValid_in_RangeWriteIterator_for_UInt8_Counter(RangeWriteIterator_for_UInt8_Counter *pRangeWriteIterator_for_UInt8_Counter)
{
  return pRangeWriteIterator_for_UInt8_Counter->isValid;
}
