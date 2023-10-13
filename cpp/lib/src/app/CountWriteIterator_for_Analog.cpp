#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "CountWriteIterator_for_Analog.h"
#include "SerializationTemplates.h"
#include <string.h>
//-------------------Uint8---------------------------------------------------

CountWriteIterator_for_UInt8_Analog Null_in_CountWriteIterator_for_UInt8_Analog_static(void)
{
  CountWriteIterator_for_UInt8_Analog cCountWriteIterator_for_UInt8_Analog;
////    return CountWriteIterator();
  CountWriteIterator_for_UInt8_Analog_in_CountWriteIterator_for_UInt8_AnalogOver1(&cCountWriteIterator_for_UInt8_Analog);
  return cCountWriteIterator_for_UInt8_Analog;
}

////    CountWriteIterator() : count(0), isValid(false), pPosition(nullptr) {}
void CountWriteIterator_for_UInt8_Analog_in_CountWriteIterator_for_UInt8_AnalogOver1(CountWriteIterator_for_UInt8_Analog *pCountWriteIterator_for_UInt8_Analog)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<""<<'\n';
  std::cout<<"CountWriteIterator_for_UInt8_Analog_in_CountWriteIterator_for_UInt8_AnalogOver1_1"<<'\n';
  decrement_stack_info();
#endif
  pCountWriteIterator_for_UInt8_Analog->count = 0;
  pCountWriteIterator_for_UInt8_Analog->isValid = false;
  pCountWriteIterator_for_UInt8_Analog->pPosition = NULL;
}

////    CountWriteIterator(const Serializer<WriteType>& serializer, ser4cpp::wseq_t& position)
void CountWriteIterator_for_UInt8_Analog_in_CountWriteIterator_for_UInt8_AnalogOver2(CountWriteIterator_for_UInt8_Analog *pCountWriteIterator_for_UInt8_Analog,
    Serializer_for_Analog *serializer, WSeq_for_Uint16_t *position)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<""<<'\n';
  std::cout<<"CountWriteIterator_for_UInt8_Analog_in_CountWriteIterator_for_UInt8_AnalogOver2_1"<<'\n';
  decrement_stack_info();
#endif

  pCountWriteIterator_for_UInt8_Analog->count = 0;
  pCountWriteIterator_for_UInt8_Analog->serializer = *serializer;
  pCountWriteIterator_for_UInt8_Analog->isValid = length_in_HasLength_for_Uint16_t(&(pCountWriteIterator_for_UInt8_Analog->pPosition->hHasLength))////position.length()
      >= size_in_UInt8;////CountType::size),
  pCountWriteIterator_for_UInt8_Analog->countPosition = *position;
  pCountWriteIterator_for_UInt8_Analog->pPosition = position;

  if (pCountWriteIterator_for_UInt8_Analog->isValid)
  {
//        position.advance(CountType::size);
    advance_in_WSeq_for_Uint16_t(position, size_in_UInt8);
  }
}

////    ~CountWriteIterator()
void CountWriteIterator_for_UInt8_Analog_destr_CountWriteIterator_for_UInt8_Analog(CountWriteIterator_for_UInt8_Analog *pCountWriteIterator_for_UInt8_Analog)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<""<<'\n';
  std::cout<<"CountWriteIterator_for_UInt8_Analog_destr_CountWriteIterator_for_UInt8_Analog1"<<'\n';
  decrement_stack_info();
#endif
  if (pCountWriteIterator_for_UInt8_Analog->isValid)
  {
////        CountType::write_to(countPosition, count);
    write_to_in_UInt8_static(&(pCountWriteIterator_for_UInt8_Analog->countPosition), pCountWriteIterator_for_UInt8_Analog->count);
  }
}

boolean Write_in_CountWriteIterator_for_UInt8_Analog(CountWriteIterator_for_UInt8_Analog *pCountWriteIterator_for_UInt8_Analog, Analog *value)////const WriteType& value)
{
////    if (isValid && (serializer.get_size() <= pPosition->length()) && (count < CountType::max_value))
  if(pCountWriteIterator_for_UInt8_Analog->isValid && (get_size_in_Serializer_for_Analog(&(pCountWriteIterator_for_UInt8_Analog->serializer)) <=
      length_in_HasLength_for_Uint16_t(&(pCountWriteIterator_for_UInt8_Analog->pPosition->hHasLength))
                                                      ) &&
      (pCountWriteIterator_for_UInt8_Analog->count < max_value_in_UInt8))
  {
////        serializer.write(value, *this->pPosition);
    write_in_Serializer_for_Analog(&(pCountWriteIterator_for_UInt8_Analog->serializer), value, pCountWriteIterator_for_UInt8_Analog->pPosition);
    ++(pCountWriteIterator_for_UInt8_Analog->count);
    return true;
  }
  else
  {
    return false;
  }
}

boolean IsValid_in_CountWriteIterator_for_UInt8_Analog(CountWriteIterator_for_UInt8_Analog *pCountWriteIterator_for_UInt8_Analog)
{
  return pCountWriteIterator_for_UInt8_Analog->isValid;
}
//-------------------Uint8---------------------------------------------------
//-------------------Uint16---------------------------------------------------
CountWriteIterator_for_UInt16_Analog Null_in_CountWriteIterator_for_UInt16_Analog_static(void)
{
  CountWriteIterator_for_UInt16_Analog cCountWriteIterator_for_UInt16_Analog;
////    return CountWriteIterator();
  CountWriteIterator_for_UInt16_Analog_in_CountWriteIterator_for_UInt16_AnalogOver1(&cCountWriteIterator_for_UInt16_Analog);
  return cCountWriteIterator_for_UInt16_Analog;
}

////    CountWriteIterator() : count(0), isValid(false), pPosition(nullptr) {}
void CountWriteIterator_for_UInt16_Analog_in_CountWriteIterator_for_UInt16_AnalogOver1(CountWriteIterator_for_UInt16_Analog *pCountWriteIterator_for_UInt16_Analog)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<""<<'\n';
  std::cout<<"CountWriteIterator_for_UInt16_Analog_in_CountWriteIterator_for_UInt16_AnalogOver1_1"<<'\n';
  decrement_stack_info();
#endif
  pCountWriteIterator_for_UInt16_Analog->count = 0;
  pCountWriteIterator_for_UInt16_Analog->isValid = false;
  pCountWriteIterator_for_UInt16_Analog->pPosition = NULL;
}

////    CountWriteIterator(const Serializer<WriteType>& serializer, ser4cpp::wseq_t& position)
void CountWriteIterator_for_UInt16_Analog_in_CountWriteIterator_for_UInt16_AnalogOver2(CountWriteIterator_for_UInt16_Analog *pCountWriteIterator_for_UInt16_Analog,
    Serializer_for_Analog *serializer, WSeq_for_Uint16_t *position)
{

  pCountWriteIterator_for_UInt16_Analog->count = 0;
  pCountWriteIterator_for_UInt16_Analog->serializer = *serializer;
  pCountWriteIterator_for_UInt16_Analog->isValid = length_in_HasLength_for_Uint16_t(&(pCountWriteIterator_for_UInt16_Analog->pPosition->hHasLength))////position.length()
      >= size_in_UInt16;////CountType::size),
  pCountWriteIterator_for_UInt16_Analog->countPosition = *position;
  pCountWriteIterator_for_UInt16_Analog->pPosition = position;

  if (pCountWriteIterator_for_UInt16_Analog->isValid)
  {
//        position.advance(CountType::size);
    advance_in_WSeq_for_Uint16_t(position, size_in_UInt16);
  }
}

////    ~CountWriteIterator()
void CountWriteIterator_for_UInt16_Analog_destr_CountWriteIterator_for_UInt16_Analog(CountWriteIterator_for_UInt16_Analog *pCountWriteIterator_for_UInt16_Analog)
{
  if (pCountWriteIterator_for_UInt16_Analog->isValid)
  {
////        CountType::write_to(countPosition, count);
    write_to_in_UInt16_static(&(pCountWriteIterator_for_UInt16_Analog->countPosition), pCountWriteIterator_for_UInt16_Analog->count);
  }
}

boolean Write_in_CountWriteIterator_for_UInt16_Analog(CountWriteIterator_for_UInt16_Analog *pCountWriteIterator_for_UInt16_Analog, Analog *value)////const WriteType& value)
{
////    if (isValid && (serializer.get_size() <= pPosition->length()) && (count < CountType::max_value))
  if(pCountWriteIterator_for_UInt16_Analog->isValid && (get_size_in_Serializer_for_Analog(&(pCountWriteIterator_for_UInt16_Analog->serializer)) <=
      length_in_HasLength_for_Uint16_t(&(pCountWriteIterator_for_UInt16_Analog->pPosition->hHasLength))
                                                       ) &&
      (pCountWriteIterator_for_UInt16_Analog->count < max_value_in_UInt16))
  {
////        serializer.write(value, *this->pPosition);
    write_in_Serializer_for_Analog(&(pCountWriteIterator_for_UInt16_Analog->serializer), value, pCountWriteIterator_for_UInt16_Analog->pPosition);
    ++(pCountWriteIterator_for_UInt16_Analog->count);
    return true;
  }
  else
  {
    return false;
  }
}

boolean IsValid_in_CountWriteIterator_for_UInt16_Analog(CountWriteIterator_for_UInt16_Analog *pCountWriteIterator_for_UInt16_Analog)
{
  return pCountWriteIterator_for_UInt16_Analog->isValid;
}
//-------------------Uint16---------------------------------------------------
