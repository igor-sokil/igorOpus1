#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "RangeWriteIterator_for_Analog.h"
#include "SerializationTemplates.h"
#include <string.h>
//-------------------RangeWriteIterator_for_UInt8_Analog---------------------------------------------------
RangeWriteIterator_for_UInt8_Analog Null_in_RangeWriteIterator_for_UInt8_Analog_static(void)
{
  RangeWriteIterator_for_UInt8_Analog rRangeWriteIterator_for_UInt8_Analog;
  RangeWriteIterator_for_UInt8_Analog_in_RangeWriteIterator_for_UInt8_AnalogOver1(&rRangeWriteIterator_for_UInt8_Analog);
//    return RangeWriteIterator();
  return rRangeWriteIterator_for_UInt8_Analog;
}

////    RangeWriteIterator() : start(0), count(0), isValid(false), pPosition(nullptr) {}
void RangeWriteIterator_for_UInt8_Analog_in_RangeWriteIterator_for_UInt8_AnalogOver1(RangeWriteIterator_for_UInt8_Analog *pRangeWriteIterator_for_UInt8_Analog)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"RangeWriteIterator_for_UInt8_Analog_in_RangeWriteIterator_for_UInt8_AnalogOver1_1"<<'\n';
  decrement_stack_info();
#endif
  pRangeWriteIterator_for_UInt8_Analog->start = 0;
  pRangeWriteIterator_for_UInt8_Analog->count = 0;
  pRangeWriteIterator_for_UInt8_Analog->isValid = false;
  pRangeWriteIterator_for_UInt8_Analog->pPosition = NULL;
}

void RangeWriteIterator_for_UInt8_Analog_in_RangeWriteIterator_for_UInt8_AnalogOver2(RangeWriteIterator_for_UInt8_Analog *pRangeWriteIterator_for_UInt8_Analog,
//                   typename IndexType::type_t start_,
    uint8_t start_,
//                   const Serializer<WriteType>& serializer,
    Serializer_for_Analog*  serializer,
//                   ser4cpp::wseq_t& position)
    WSeq_for_Uint16_t* position)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"RangeWriteIterator_for_UInt8_Analog_in_RangeWriteIterator_for_UInt8_AnalogOver2_1"<<'\n';
  decrement_stack_info();
#endif
  pRangeWriteIterator_for_UInt8_Analog->start = start_;
  pRangeWriteIterator_for_UInt8_Analog->serializer = *serializer;
  pRangeWriteIterator_for_UInt8_Analog->count = 0;
//     isValid = position.length() >= 2 * IndexType::size),
  pRangeWriteIterator_for_UInt8_Analog->isValid = length_in_HasLength_for_Uint16_t(&(position->hHasLength)) >= 2 * size_in_UInt8;

  pRangeWriteIterator_for_UInt8_Analog->range = *position;
  pRangeWriteIterator_for_UInt8_Analog->pPosition = position;

  if (pRangeWriteIterator_for_UInt8_Analog->isValid)
  {
//        IndexType::write_to(range, start);
    write_to_in_UInt8_static(&(pRangeWriteIterator_for_UInt8_Analog->range), pRangeWriteIterator_for_UInt8_Analog->start);
//        pPosition->advance(2 * IndexType::size);
    advance_in_WSeq_for_Uint16_t(pRangeWriteIterator_for_UInt8_Analog->pPosition, 2 * size_in_UInt8);
  }
}

////    ~RangeWriteIterator()
void RangeWriteIterator_for_UInt8_Analog_destr_RangeWriteIterator_for_UInt8_Analog(RangeWriteIterator_for_UInt8_Analog *pRangeWriteIterator_for_UInt8_Analog)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"RangeWriteIterator_for_UInt8_Analog_destr_RangeWriteIterator_for_UInt8_Analog1"<<'\n';
  decrement_stack_info();
#endif
  if (pRangeWriteIterator_for_UInt8_Analog->isValid && pRangeWriteIterator_for_UInt8_Analog->count > 0)
  {
    uint32_t stop = pRangeWriteIterator_for_UInt8_Analog->start + pRangeWriteIterator_for_UInt8_Analog->count - 1;
//        IndexType::write_to(range, static_cast<typename IndexType::type_t>(stop));
    write_to_in_UInt8_static(&(pRangeWriteIterator_for_UInt8_Analog->range), (uint8_t)(stop));
  }
}

//    bool Write(const WriteType& value)
boolean Write_in_RangeWriteIterator_for_UInt8_Analog(RangeWriteIterator_for_UInt8_Analog *pRangeWriteIterator_for_UInt8_Analog,
    Analog* value)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"Write_in_RangeWriteIterator_for_UInt8_Analog1"<<'\n';
  decrement_stack_info();
#endif
////    if (isValid && (pPosition->length() >= serializer.get_size()) && (count <= IndexType::max_value))
  if(pRangeWriteIterator_for_UInt8_Analog->isValid &&
      (length_in_HasLength_for_Uint16_t(&(pRangeWriteIterator_for_UInt8_Analog->pPosition->hHasLength)) >=
       get_size_in_Serializer_for_Analog(&(pRangeWriteIterator_for_UInt8_Analog->serializer)))  &&
      (pRangeWriteIterator_for_UInt8_Analog->count <= max_value_in_UInt8))
  {
////        serializer.write(value, *pPosition);
    write_in_Serializer_for_Analog(&(pRangeWriteIterator_for_UInt8_Analog->serializer), value, pRangeWriteIterator_for_UInt8_Analog->pPosition);
    ++(pRangeWriteIterator_for_UInt8_Analog->count);
    return true;
  }
  else
  {
    return false;
  }
}

boolean IsValid_in_RangeWriteIterator_for_UInt8_Analog(RangeWriteIterator_for_UInt8_Analog *pRangeWriteIterator_for_UInt8_Analog)
{
  return pRangeWriteIterator_for_UInt8_Analog->isValid;
}
//-------------------RangeWriteIterator_for_UInt8_Analog---------------------------------------------------
//-------------------RangeWriteIterator_for_UInt16_Analog---------------------------------------------------
RangeWriteIterator_for_UInt16_Analog Null_in_RangeWriteIterator_for_UInt16_Analog_static(void)
{
  RangeWriteIterator_for_UInt16_Analog rRangeWriteIterator_for_UInt16_Analog;
  RangeWriteIterator_for_UInt16_Analog_in_RangeWriteIterator_for_UInt16_AnalogOver1(&rRangeWriteIterator_for_UInt16_Analog);
//    return RangeWriteIterator();
  return rRangeWriteIterator_for_UInt16_Analog;
}

////    RangeWriteIterator() : start(0), count(0), isValid(false), pPosition(nullptr) {}
void RangeWriteIterator_for_UInt16_Analog_in_RangeWriteIterator_for_UInt16_AnalogOver1(RangeWriteIterator_for_UInt16_Analog *pRangeWriteIterator_for_UInt16_Analog)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"RangeWriteIterator_for_UInt16_Analog_in_RangeWriteIterator_for_UInt16_AnalogOver1_1"<<'\n';
  decrement_stack_info();
#endif
  pRangeWriteIterator_for_UInt16_Analog->start = 0;
  pRangeWriteIterator_for_UInt16_Analog->count = 0;
  pRangeWriteIterator_for_UInt16_Analog->isValid = false;
  pRangeWriteIterator_for_UInt16_Analog->pPosition = NULL;
}

void RangeWriteIterator_for_UInt16_Analog_in_RangeWriteIterator_for_UInt16_AnalogOver2(RangeWriteIterator_for_UInt16_Analog *pRangeWriteIterator_for_UInt16_Analog,
//                   typename IndexType::type_t start_,
    uint16_t start_,
//                   const Serializer<WriteType>& serializer,
    Serializer_for_Analog*  serializer,
//                   ser4cpp::wseq_t& position)
    WSeq_for_Uint16_t* position)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"RangeWriteIterator_for_UInt16_Analog_in_RangeWriteIterator_for_UInt16_AnalogOver2_1"<<'\n';
  decrement_stack_info();
#endif
  pRangeWriteIterator_for_UInt16_Analog->start = start_;
  pRangeWriteIterator_for_UInt16_Analog->serializer = *serializer;
  pRangeWriteIterator_for_UInt16_Analog->count = 0;
//     isValid = position.length() >= 2 * IndexType::size),
  pRangeWriteIterator_for_UInt16_Analog->isValid = length_in_HasLength_for_Uint16_t(&(position->hHasLength)) >= 2 * size_in_UInt16;

  pRangeWriteIterator_for_UInt16_Analog->range = *position;
  pRangeWriteIterator_for_UInt16_Analog->pPosition = position;

  if (pRangeWriteIterator_for_UInt16_Analog->isValid)
  {
//        IndexType::write_to(range, start);
    write_to_in_UInt16_static(&(pRangeWriteIterator_for_UInt16_Analog->range), pRangeWriteIterator_for_UInt16_Analog->start);
//        pPosition->advance(2 * IndexType::size);
    advance_in_WSeq_for_Uint16_t(pRangeWriteIterator_for_UInt16_Analog->pPosition, 2 * size_in_UInt16);
  }
}

////    ~RangeWriteIterator()
void RangeWriteIterator_for_UInt16_Analog_destr_RangeWriteIterator_for_UInt16_Analog(RangeWriteIterator_for_UInt16_Analog *pRangeWriteIterator_for_UInt16_Analog)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"RangeWriteIterator_for_UInt16_Analog_destr_RangeWriteIterator_for_UInt16_Analog1"<<'\n';
  decrement_stack_info();
#endif
  if (pRangeWriteIterator_for_UInt16_Analog->isValid && pRangeWriteIterator_for_UInt16_Analog->count > 0)
  {
    uint32_t stop = pRangeWriteIterator_for_UInt16_Analog->start + pRangeWriteIterator_for_UInt16_Analog->count - 1;
//        IndexType::write_to(range, static_cast<typename IndexType::type_t>(stop));
    write_to_in_UInt16_static(&(pRangeWriteIterator_for_UInt16_Analog->range), (uint16_t)(stop));
  }
}

//    bool Write(const WriteType& value)
boolean Write_in_RangeWriteIterator_for_UInt16_Analog(RangeWriteIterator_for_UInt16_Analog *pRangeWriteIterator_for_UInt16_Analog,
    Analog* value)
{
//    if (isValid && (pPosition->length() >= serializer.get_size()) && (count <= IndexType::max_value))
  if(pRangeWriteIterator_for_UInt16_Analog->isValid &&
      (length_in_HasLength_for_Uint16_t(&(pRangeWriteIterator_for_UInt16_Analog->pPosition->hHasLength)) >=
       get_size_in_Serializer_for_Analog(&(pRangeWriteIterator_for_UInt16_Analog->serializer)))  &&
      (pRangeWriteIterator_for_UInt16_Analog->count <= max_value_in_UInt16))
  {
//        serializer.write(value, *pPosition);
    write_in_Serializer_for_Analog(&(pRangeWriteIterator_for_UInt16_Analog->serializer), value, pRangeWriteIterator_for_UInt16_Analog->pPosition);
    ++(pRangeWriteIterator_for_UInt16_Analog->count);
    return true;
  }
  else
  {
    return false;
  }
}

boolean IsValid_in_RangeWriteIterator_for_UInt16_Analog(RangeWriteIterator_for_UInt16_Analog *pRangeWriteIterator_for_UInt16_Analog)
{
  return pRangeWriteIterator_for_UInt16_Analog->isValid;
}
//-------------------RangeWriteIterator_for_UInt16_Analog---------------------------------------------------
