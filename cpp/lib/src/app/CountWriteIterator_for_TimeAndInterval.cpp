#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "CountWriteIterator_for_TimeAndInterval.h"
#include "SerializationTemplates.h"
#include <string.h>
//-------------------Uint8---------------------------------------------------

CountWriteIterator_for_UInt8_TimeAndInterval Null_in_CountWriteIterator_for_UInt8_TimeAndInterval_static(void)
{
  CountWriteIterator_for_UInt8_TimeAndInterval cCountWriteIterator_for_UInt8_TimeAndInterval;
////    return CountWriteIterator();
  CountWriteIterator_for_UInt8_TimeAndInterval_in_CountWriteIterator_for_UInt8_TimeAndIntervalOver1(&cCountWriteIterator_for_UInt8_TimeAndInterval);
  return cCountWriteIterator_for_UInt8_TimeAndInterval;
}

////    CountWriteIterator() : count(0), isValid(false), pPosition(nullptr) {}
void CountWriteIterator_for_UInt8_TimeAndInterval_in_CountWriteIterator_for_UInt8_TimeAndIntervalOver1(CountWriteIterator_for_UInt8_TimeAndInterval *pCountWriteIterator_for_UInt8_TimeAndInterval)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"CountWriteIterator_for_UInt8_TimeAndInterval_in_CountWriteIterator_for_UInt8_TimeAndIntervalOver1_1"<<'\n';
  decrement_stack_info();
#endif
  pCountWriteIterator_for_UInt8_TimeAndInterval->count = 0;
  pCountWriteIterator_for_UInt8_TimeAndInterval->isValid = false;
  pCountWriteIterator_for_UInt8_TimeAndInterval->pPosition = NULL;
}

////    CountWriteIterator(const Serializer<WriteType>& serializer, ser4cpp::wseq_t& position)
void CountWriteIterator_for_UInt8_TimeAndInterval_in_CountWriteIterator_for_UInt8_TimeAndIntervalOver2(CountWriteIterator_for_UInt8_TimeAndInterval *pCountWriteIterator_for_UInt8_TimeAndInterval,
    Serializer_for_TimeAndInterval *serializer, WSeq_for_Uint16_t *position)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"CountWriteIterator_for_UInt8_TimeAndInterval_in_CountWriteIterator_for_UInt8_TimeAndIntervalOver2_1"<<'\n';
  decrement_stack_info();
#endif

  pCountWriteIterator_for_UInt8_TimeAndInterval->count = 0;
  pCountWriteIterator_for_UInt8_TimeAndInterval->serializer = *serializer;
  pCountWriteIterator_for_UInt8_TimeAndInterval->isValid = length_in_HasLength_for_Uint16_t(&(pCountWriteIterator_for_UInt8_TimeAndInterval->pPosition->hHasLength))////position.length()
      >= size_in_UInt8;////CountType::size),
  pCountWriteIterator_for_UInt8_TimeAndInterval->countPosition = *position;
  pCountWriteIterator_for_UInt8_TimeAndInterval->pPosition = position;

  if (pCountWriteIterator_for_UInt8_TimeAndInterval->isValid)
  {
//        position.advance(CountType::size);
    advance_in_WSeq_for_Uint16_t(position, size_in_UInt8);
  }
}

////    ~CountWriteIterator()
void CountWriteIterator_for_UInt8_TimeAndInterval_destr_CountWriteIterator_for_UInt8_TimeAndInterval(CountWriteIterator_for_UInt8_TimeAndInterval *pCountWriteIterator_for_UInt8_TimeAndInterval)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"CountWriteIterator_for_UInt8_TimeAndInterval_destr_CountWriteIterator_for_UInt8_TimeAndInterval1"<<'\n';
  decrement_stack_info();
#endif
  if (pCountWriteIterator_for_UInt8_TimeAndInterval->isValid)
  {
////        CountType::write_to(countPosition, count);
    write_to_in_UInt8_static(&(pCountWriteIterator_for_UInt8_TimeAndInterval->countPosition), pCountWriteIterator_for_UInt8_TimeAndInterval->count);
  }
}

boolean Write_in_CountWriteIterator_for_UInt8_TimeAndInterval(CountWriteIterator_for_UInt8_TimeAndInterval *pCountWriteIterator_for_UInt8_TimeAndInterval, TimeAndInterval *value)////const WriteType& value)
{
////    if (isValid && (serializer.get_size() <= pPosition->length()) && (count < CountType::max_value))
  if(pCountWriteIterator_for_UInt8_TimeAndInterval->isValid && (get_size_in_Serializer_for_TimeAndInterval(&(pCountWriteIterator_for_UInt8_TimeAndInterval->serializer)) <=
      length_in_HasLength_for_Uint16_t(&(pCountWriteIterator_for_UInt8_TimeAndInterval->pPosition->hHasLength))
                                                      ) &&
      (pCountWriteIterator_for_UInt8_TimeAndInterval->count < max_value_in_UInt8))
  {
////        serializer.write(value, *this->pPosition);
    write_in_Serializer_for_TimeAndInterval(&(pCountWriteIterator_for_UInt8_TimeAndInterval->serializer), value, pCountWriteIterator_for_UInt8_TimeAndInterval->pPosition);
    ++(pCountWriteIterator_for_UInt8_TimeAndInterval->count);
    return true;
  }
  else
  {
    return false;
  }
}

boolean IsValid_in_CountWriteIterator_for_UInt8_TimeAndInterval(CountWriteIterator_for_UInt8_TimeAndInterval *pCountWriteIterator_for_UInt8_TimeAndInterval)
{
  return pCountWriteIterator_for_UInt8_TimeAndInterval->isValid;
}
//-------------------Uint8---------------------------------------------------
//-------------------Uint16---------------------------------------------------
CountWriteIterator_for_UInt16_TimeAndInterval Null_in_CountWriteIterator_for_UInt16_TimeAndInterval_static(void)
{
  CountWriteIterator_for_UInt16_TimeAndInterval cCountWriteIterator_for_UInt16_TimeAndInterval;
////    return CountWriteIterator();
  CountWriteIterator_for_UInt16_TimeAndInterval_in_CountWriteIterator_for_UInt16_TimeAndIntervalOver1(&cCountWriteIterator_for_UInt16_TimeAndInterval);
  return cCountWriteIterator_for_UInt16_TimeAndInterval;
}

////    CountWriteIterator() : count(0), isValid(false), pPosition(nullptr) {}
void CountWriteIterator_for_UInt16_TimeAndInterval_in_CountWriteIterator_for_UInt16_TimeAndIntervalOver1(CountWriteIterator_for_UInt16_TimeAndInterval *pCountWriteIterator_for_UInt16_TimeAndInterval)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"CountWriteIterator_for_UInt16_TimeAndInterval_in_CountWriteIterator_for_UInt16_TimeAndIntervalOver1_1"<<'\n';
  decrement_stack_info();
#endif
  pCountWriteIterator_for_UInt16_TimeAndInterval->count = 0;
  pCountWriteIterator_for_UInt16_TimeAndInterval->isValid = false;
  pCountWriteIterator_for_UInt16_TimeAndInterval->pPosition = NULL;
}

////    CountWriteIterator(const Serializer<WriteType>& serializer, ser4cpp::wseq_t& position)
void CountWriteIterator_for_UInt16_TimeAndInterval_in_CountWriteIterator_for_UInt16_TimeAndIntervalOver2(CountWriteIterator_for_UInt16_TimeAndInterval *pCountWriteIterator_for_UInt16_TimeAndInterval,
    Serializer_for_TimeAndInterval *serializer, WSeq_for_Uint16_t *position)
{

  pCountWriteIterator_for_UInt16_TimeAndInterval->count = 0;
  pCountWriteIterator_for_UInt16_TimeAndInterval->serializer = *serializer;
  pCountWriteIterator_for_UInt16_TimeAndInterval->isValid = length_in_HasLength_for_Uint16_t(&(pCountWriteIterator_for_UInt16_TimeAndInterval->pPosition->hHasLength))////position.length()
      >= size_in_UInt16;////CountType::size),
  pCountWriteIterator_for_UInt16_TimeAndInterval->countPosition = *position;
  pCountWriteIterator_for_UInt16_TimeAndInterval->pPosition = position;

  if (pCountWriteIterator_for_UInt16_TimeAndInterval->isValid)
  {
//        position.advance(CountType::size);
    advance_in_WSeq_for_Uint16_t(position, size_in_UInt16);
  }
}

////    ~CountWriteIterator()
void CountWriteIterator_for_UInt16_TimeAndInterval_destr_CountWriteIterator_for_UInt16_TimeAndInterval(CountWriteIterator_for_UInt16_TimeAndInterval *pCountWriteIterator_for_UInt16_TimeAndInterval)
{
  if (pCountWriteIterator_for_UInt16_TimeAndInterval->isValid)
  {
////        CountType::write_to(countPosition, count);
    write_to_in_UInt16_static(&(pCountWriteIterator_for_UInt16_TimeAndInterval->countPosition), pCountWriteIterator_for_UInt16_TimeAndInterval->count);
  }
}

boolean Write_in_CountWriteIterator_for_UInt16_TimeAndInterval(CountWriteIterator_for_UInt16_TimeAndInterval *pCountWriteIterator_for_UInt16_TimeAndInterval, TimeAndInterval *value)////const WriteType& value)
{
////    if (isValid && (serializer.get_size() <= pPosition->length()) && (count < CountType::max_value))
  if(pCountWriteIterator_for_UInt16_TimeAndInterval->isValid && (get_size_in_Serializer_for_TimeAndInterval(&(pCountWriteIterator_for_UInt16_TimeAndInterval->serializer)) <=
      length_in_HasLength_for_Uint16_t(&(pCountWriteIterator_for_UInt16_TimeAndInterval->pPosition->hHasLength))
                                                       ) &&
      (pCountWriteIterator_for_UInt16_TimeAndInterval->count < max_value_in_UInt16))
  {
////        serializer.write(value, *this->pPosition);
    write_in_Serializer_for_TimeAndInterval(&(pCountWriteIterator_for_UInt16_TimeAndInterval->serializer), value, pCountWriteIterator_for_UInt16_TimeAndInterval->pPosition);
    ++(pCountWriteIterator_for_UInt16_TimeAndInterval->count);
    return true;
  }
  else
  {
    return false;
  }
}

boolean IsValid_in_CountWriteIterator_for_UInt16_TimeAndInterval(CountWriteIterator_for_UInt16_TimeAndInterval *pCountWriteIterator_for_UInt16_TimeAndInterval)
{
  return pCountWriteIterator_for_UInt16_TimeAndInterval->isValid;
}
//-------------------Uint16---------------------------------------------------
