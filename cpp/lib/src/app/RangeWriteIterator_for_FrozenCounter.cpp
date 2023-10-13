#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "RangeWriteIterator_for_FrozenCounter.h"
#include "SerializationTemplates.h"
#include <string.h>

//-------------------Uint8---------------------------------------------------
RangeWriteIterator_for_UInt8_FrozenCounter Null_in_RangeWriteIterator_for_UInt8_FrozenCounter_static(void)
{
  RangeWriteIterator_for_UInt8_FrozenCounter rRangeWriteIterator_for_UInt8_FrozenCounter;
  RangeWriteIterator_for_UInt8_FrozenCounter_in_RangeWriteIterator_for_UInt8_FrozenCounterOver1(&rRangeWriteIterator_for_UInt8_FrozenCounter);
//    return RangeWriteIterator();
  return rRangeWriteIterator_for_UInt8_FrozenCounter;
}

////    RangeWriteIterator() : start(0), count(0), isValid(false), pPosition(nullptr) {}
void RangeWriteIterator_for_UInt8_FrozenCounter_in_RangeWriteIterator_for_UInt8_FrozenCounterOver1(RangeWriteIterator_for_UInt8_FrozenCounter *pRangeWriteIterator_for_UInt8_FrozenCounter)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<""<<'\n';
  std::cout<<"RangeWriteIterator_for_UInt8_FrozenCounter_in_RangeWriteIterator_for_UInt8_FrozenCounterOver1_1"<<'\n';
  decrement_stack_info();
#endif
  pRangeWriteIterator_for_UInt8_FrozenCounter->start = 0;
  pRangeWriteIterator_for_UInt8_FrozenCounter->count = 0;
  pRangeWriteIterator_for_UInt8_FrozenCounter->isValid = false;
  pRangeWriteIterator_for_UInt8_FrozenCounter->pPosition = NULL;
}

void RangeWriteIterator_for_UInt8_FrozenCounter_in_RangeWriteIterator_for_UInt8_FrozenCounterOver2(RangeWriteIterator_for_UInt8_FrozenCounter *pRangeWriteIterator_for_UInt8_FrozenCounter,
//                   typename IndexType::type_t start_,
    uint8_t start_,
//                   const Serializer<WriteType>& serializer,
    Serializer_for_FrozenCounter*  serializer,
//                   ser4cpp::wseq_t& position)
    WSeq_for_Uint16_t* position)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<""<<'\n';
  std::cout<<"RangeWriteIterator_for_UInt8_FrozenCounter_in_RangeWriteIterator_for_UInt8_FrozenCounterOver2_1"<<'\n';
  decrement_stack_info();
#endif
  pRangeWriteIterator_for_UInt8_FrozenCounter->start = start_;
  pRangeWriteIterator_for_UInt8_FrozenCounter->serializer = *serializer;
  pRangeWriteIterator_for_UInt8_FrozenCounter->count = 0;
//     isValid = position.length() >= 2 * IndexType::size),
  pRangeWriteIterator_for_UInt8_FrozenCounter->isValid = length_in_HasLength_for_Uint16_t(&(position->hHasLength)) >= 2 * size_in_UInt8;

  pRangeWriteIterator_for_UInt8_FrozenCounter->range = *position;
  pRangeWriteIterator_for_UInt8_FrozenCounter->pPosition = position;

  if (pRangeWriteIterator_for_UInt8_FrozenCounter->isValid)
  {
//        IndexType::write_to(range, start);
    write_to_in_UInt8_static(&(pRangeWriteIterator_for_UInt8_FrozenCounter->range), pRangeWriteIterator_for_UInt8_FrozenCounter->start);
//        pPosition->advance(2 * IndexType::size);
    advance_in_WSeq_for_Uint16_t(pRangeWriteIterator_for_UInt8_FrozenCounter->pPosition, 2 * size_in_UInt8);
  }
}

////    ~RangeWriteIterator()
void RangeWriteIterator_for_UInt8_FrozenCounter_destr_RangeWriteIterator_for_UInt8_FrozenCounter(RangeWriteIterator_for_UInt8_FrozenCounter *pRangeWriteIterator_for_UInt8_FrozenCounter)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<""<<'\n';
  std::cout<<"RangeWriteIterator_for_UInt8_FrozenCounter_destr_RangeWriteIterator_for_UInt8_FrozenCounter1"<<'\n';
  decrement_stack_info();
#endif
  if (pRangeWriteIterator_for_UInt8_FrozenCounter->isValid && pRangeWriteIterator_for_UInt8_FrozenCounter->count > 0)
  {
    uint32_t stop = pRangeWriteIterator_for_UInt8_FrozenCounter->start + pRangeWriteIterator_for_UInt8_FrozenCounter->count - 1;
//        IndexType::write_to(range, static_cast<typename IndexType::type_t>(stop));
    write_to_in_UInt8_static(&(pRangeWriteIterator_for_UInt8_FrozenCounter->range), (uint8_t)(stop));
  }
}

//    bool Write(const WriteType& value)
boolean Write_in_RangeWriteIterator_for_UInt8_FrozenCounter(RangeWriteIterator_for_UInt8_FrozenCounter *pRangeWriteIterator_for_UInt8_FrozenCounter,
    FrozenCounter* value)
{
//    if (isValid && (pPosition->length() >= serializer.get_size()) && (count <= IndexType::max_value))
  if(pRangeWriteIterator_for_UInt8_FrozenCounter->isValid &&
      (length_in_HasLength_for_Uint16_t(&(pRangeWriteIterator_for_UInt8_FrozenCounter->pPosition->hHasLength)) >=
       get_size_in_Serializer_for_FrozenCounter(&(pRangeWriteIterator_for_UInt8_FrozenCounter->serializer)))  &&
      (pRangeWriteIterator_for_UInt8_FrozenCounter->count <= max_value_in_UInt8))
  {
//        serializer.write(value, *pPosition);
    write_in_Serializer_for_FrozenCounter(&(pRangeWriteIterator_for_UInt8_FrozenCounter->serializer), value, pRangeWriteIterator_for_UInt8_FrozenCounter->pPosition);
    ++(pRangeWriteIterator_for_UInt8_FrozenCounter->count);
    return true;
  }
  else
  {
    return false;
  }
}

boolean IsValid_in_RangeWriteIterator_for_UInt8_FrozenCounter(RangeWriteIterator_for_UInt8_FrozenCounter *pRangeWriteIterator_for_UInt8_FrozenCounter)
{
  return pRangeWriteIterator_for_UInt8_FrozenCounter->isValid;
}
//-------------------Uint8---------------------------------------------------
