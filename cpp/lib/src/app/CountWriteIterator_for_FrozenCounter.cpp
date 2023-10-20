#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "CountWriteIterator_for_FrozenCounter.h"
#include "SerializationTemplates.h"
#include <string.h>
//-------------------Uint8---------------------------------------------------

CountWriteIterator_for_UInt8_FrozenCounter Null_in_CountWriteIterator_for_UInt8_FrozenCounter_static(void)
{
  CountWriteIterator_for_UInt8_FrozenCounter cCountWriteIterator_for_UInt8_FrozenCounter;
////    return CountWriteIterator();
  CountWriteIterator_for_UInt8_FrozenCounter_in_CountWriteIterator_for_UInt8_FrozenCounterOver1(&cCountWriteIterator_for_UInt8_FrozenCounter);
  return cCountWriteIterator_for_UInt8_FrozenCounter;
}

////    CountWriteIterator() : count(0), isValid(false), pPosition(nullptr) {}
void CountWriteIterator_for_UInt8_FrozenCounter_in_CountWriteIterator_for_UInt8_FrozenCounterOver1(CountWriteIterator_for_UInt8_FrozenCounter *pCountWriteIterator_for_UInt8_FrozenCounter)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<""<<'\n';
  std::cout<<"CountWriteIterator_for_UInt8_FrozenCounter_in_CountWriteIterator_for_UInt8_FrozenCounterOver1_1"<<'\n';
  decrement_stack_info();
#endif
  pCountWriteIterator_for_UInt8_FrozenCounter->count = 0;
  pCountWriteIterator_for_UInt8_FrozenCounter->isValid = false;
  pCountWriteIterator_for_UInt8_FrozenCounter->pPosition = NULL;
}

////    CountWriteIterator(const Serializer<WriteType>& serializer, ser4cpp::wseq_t& position)
void CountWriteIterator_for_UInt8_FrozenCounter_in_CountWriteIterator_for_UInt8_FrozenCounterOver2(CountWriteIterator_for_UInt8_FrozenCounter *pCountWriteIterator_for_UInt8_FrozenCounter,
    Serializer_for_FrozenCounter *serializer, WSeq_for_Uint16_t *position)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<""<<'\n';
  std::cout<<"CountWriteIterator_for_UInt8_FrozenCounter_in_CountWriteIterator_for_UInt8_FrozenCounterOver2_1"<<'\n';
  decrement_stack_info();
#endif

  pCountWriteIterator_for_UInt8_FrozenCounter->count = 0;
  pCountWriteIterator_for_UInt8_FrozenCounter->serializer = *serializer;
  pCountWriteIterator_for_UInt8_FrozenCounter->isValid = length_in_HasLength_for_Uint16_t(&(pCountWriteIterator_for_UInt8_FrozenCounter->pPosition->hHasLength))////position.length()
      >= size_in_UInt8;////CountType::size),
  pCountWriteIterator_for_UInt8_FrozenCounter->countPosition = *position;
  pCountWriteIterator_for_UInt8_FrozenCounter->pPosition = position;

  if (pCountWriteIterator_for_UInt8_FrozenCounter->isValid)
  {
//        position.advance(CountType::size);
    advance_in_WSeq_for_Uint16_t(position, size_in_UInt8);
  }
}

////    ~CountWriteIterator()
void CountWriteIterator_for_UInt8_FrozenCounter_destr_CountWriteIterator_for_UInt8_FrozenCounter(CountWriteIterator_for_UInt8_FrozenCounter *pCountWriteIterator_for_UInt8_FrozenCounter)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<""<<'\n';
  std::cout<<"CountWriteIterator_for_UInt8_FrozenCounter_destr_CountWriteIterator_for_UInt8_FrozenCounter1"<<'\n';
  decrement_stack_info();
#endif
  if (pCountWriteIterator_for_UInt8_FrozenCounter->isValid)
  {
////        CountType::write_to(countPosition, count);
    write_to_in_UInt8_static(&(pCountWriteIterator_for_UInt8_FrozenCounter->countPosition), pCountWriteIterator_for_UInt8_FrozenCounter->count);
  }
}

boolean Write_in_CountWriteIterator_for_UInt8_FrozenCounter(CountWriteIterator_for_UInt8_FrozenCounter *pCountWriteIterator_for_UInt8_FrozenCounter, FrozenCounter *value)////const WriteType& value)
{
////    if (isValid && (serializer.get_size() <= pPosition->length()) && (count < CountType::max_value))
  if(pCountWriteIterator_for_UInt8_FrozenCounter->isValid && (get_size_in_Serializer_for_FrozenCounter(&(pCountWriteIterator_for_UInt8_FrozenCounter->serializer)) <=
      length_in_HasLength_for_Uint16_t(&(pCountWriteIterator_for_UInt8_FrozenCounter->pPosition->hHasLength))
                                                      ) &&
      (pCountWriteIterator_for_UInt8_FrozenCounter->count < max_value_in_UInt8))
  {
////        serializer.write(value, *this->pPosition);
    write_in_Serializer_for_FrozenCounter(&(pCountWriteIterator_for_UInt8_FrozenCounter->serializer), value, pCountWriteIterator_for_UInt8_FrozenCounter->pPosition);
    ++(pCountWriteIterator_for_UInt8_FrozenCounter->count);
    return true;
  }
  else
  {
    return false;
  }
}

boolean IsValid_in_CountWriteIterator_for_UInt8_FrozenCounter(CountWriteIterator_for_UInt8_FrozenCounter *pCountWriteIterator_for_UInt8_FrozenCounter)
{
  return pCountWriteIterator_for_UInt8_FrozenCounter->isValid;
}
//-------------------Uint8---------------------------------------------------
//-------------------Uint16---------------------------------------------------
CountWriteIterator_for_UInt16_FrozenCounter Null_in_CountWriteIterator_for_UInt16_FrozenCounter_static(void)
{
  CountWriteIterator_for_UInt16_FrozenCounter cCountWriteIterator_for_UInt16_FrozenCounter;
////    return CountWriteIterator();
  CountWriteIterator_for_UInt16_FrozenCounter_in_CountWriteIterator_for_UInt16_FrozenCounterOver1(&cCountWriteIterator_for_UInt16_FrozenCounter);
  return cCountWriteIterator_for_UInt16_FrozenCounter;
}

////    CountWriteIterator() : count(0), isValid(false), pPosition(nullptr) {}
void CountWriteIterator_for_UInt16_FrozenCounter_in_CountWriteIterator_for_UInt16_FrozenCounterOver1(CountWriteIterator_for_UInt16_FrozenCounter *pCountWriteIterator_for_UInt16_FrozenCounter)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<""<<'\n';
  std::cout<<"CountWriteIterator_for_UInt16_FrozenCounter_in_CountWriteIterator_for_UInt16_FrozenCounterOver1_1"<<'\n';
  decrement_stack_info();
#endif
  pCountWriteIterator_for_UInt16_FrozenCounter->count = 0;
  pCountWriteIterator_for_UInt16_FrozenCounter->isValid = false;
  pCountWriteIterator_for_UInt16_FrozenCounter->pPosition = NULL;
}

////    CountWriteIterator(const Serializer<WriteType>& serializer, ser4cpp::wseq_t& position)
void CountWriteIterator_for_UInt16_FrozenCounter_in_CountWriteIterator_for_UInt16_FrozenCounterOver2(CountWriteIterator_for_UInt16_FrozenCounter *pCountWriteIterator_for_UInt16_FrozenCounter,
    Serializer_for_FrozenCounter *serializer, WSeq_for_Uint16_t *position)
{

  pCountWriteIterator_for_UInt16_FrozenCounter->count = 0;
  pCountWriteIterator_for_UInt16_FrozenCounter->serializer = *serializer;
  pCountWriteIterator_for_UInt16_FrozenCounter->isValid = length_in_HasLength_for_Uint16_t(&(pCountWriteIterator_for_UInt16_FrozenCounter->pPosition->hHasLength))////position.length()
      >= size_in_UInt16;////CountType::size),
  pCountWriteIterator_for_UInt16_FrozenCounter->countPosition = *position;
  pCountWriteIterator_for_UInt16_FrozenCounter->pPosition = position;

  if (pCountWriteIterator_for_UInt16_FrozenCounter->isValid)
  {
//        position.advance(CountType::size);
    advance_in_WSeq_for_Uint16_t(position, size_in_UInt16);
  }
}

////    ~CountWriteIterator()
void CountWriteIterator_for_UInt16_FrozenCounter_destr_CountWriteIterator_for_UInt16_FrozenCounter(CountWriteIterator_for_UInt16_FrozenCounter *pCountWriteIterator_for_UInt16_FrozenCounter)
{
  if (pCountWriteIterator_for_UInt16_FrozenCounter->isValid)
  {
////        CountType::write_to(countPosition, count);
    write_to_in_UInt16_static(&(pCountWriteIterator_for_UInt16_FrozenCounter->countPosition), pCountWriteIterator_for_UInt16_FrozenCounter->count);
  }
}

boolean Write_in_CountWriteIterator_for_UInt16_FrozenCounter(CountWriteIterator_for_UInt16_FrozenCounter *pCountWriteIterator_for_UInt16_FrozenCounter, FrozenCounter *value)////const WriteType& value)
{
////    if (isValid && (serializer.get_size() <= pPosition->length()) && (count < CountType::max_value))
  if(pCountWriteIterator_for_UInt16_FrozenCounter->isValid && (get_size_in_Serializer_for_FrozenCounter(&(pCountWriteIterator_for_UInt16_FrozenCounter->serializer)) <=
      length_in_HasLength_for_Uint16_t(&(pCountWriteIterator_for_UInt16_FrozenCounter->pPosition->hHasLength))
                                                       ) &&
      (pCountWriteIterator_for_UInt16_FrozenCounter->count < max_value_in_UInt16))
  {
////        serializer.write(value, *this->pPosition);
    write_in_Serializer_for_FrozenCounter(&(pCountWriteIterator_for_UInt16_FrozenCounter->serializer), value, pCountWriteIterator_for_UInt16_FrozenCounter->pPosition);
    ++(pCountWriteIterator_for_UInt16_FrozenCounter->count);
    return true;
  }
  else
  {
    return false;
  }
}

boolean IsValid_in_CountWriteIterator_for_UInt16_FrozenCounter(CountWriteIterator_for_UInt16_FrozenCounter *pCountWriteIterator_for_UInt16_FrozenCounter)
{
  return pCountWriteIterator_for_UInt16_FrozenCounter->isValid;
}
//-------------------Uint16---------------------------------------------------
