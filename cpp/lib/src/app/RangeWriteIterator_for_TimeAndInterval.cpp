#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "RangeWriteIterator_for_TimeAndInterval.h"
#include "SerializationTemplates.h"
#include <string.h>
//-------------------RangeWriteIterator_for_UInt8_TimeAndInterval---------------------------------------------------
RangeWriteIterator_for_UInt8_TimeAndInterval Null_in_RangeWriteIterator_for_UInt8_TimeAndInterval_static(void)
{
  RangeWriteIterator_for_UInt8_TimeAndInterval rRangeWriteIterator_for_UInt8_TimeAndInterval;
  RangeWriteIterator_for_UInt8_TimeAndInterval_in_RangeWriteIterator_for_UInt8_TimeAndIntervalOver1(&rRangeWriteIterator_for_UInt8_TimeAndInterval);
//    return RangeWriteIterator();
  return rRangeWriteIterator_for_UInt8_TimeAndInterval;
}

////    RangeWriteIterator() : start(0), count(0), isValid(false), pPosition(nullptr) {}
void RangeWriteIterator_for_UInt8_TimeAndInterval_in_RangeWriteIterator_for_UInt8_TimeAndIntervalOver1(RangeWriteIterator_for_UInt8_TimeAndInterval *pRangeWriteIterator_for_UInt8_TimeAndInterval)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"RangeWriteIterator_for_UInt8_TimeAndInterval_in_RangeWriteIterator_for_UInt8_TimeAndIntervalOver1_1"<<'\n';
  decrement_stack_info();
#endif
  pRangeWriteIterator_for_UInt8_TimeAndInterval->start = 0;
  pRangeWriteIterator_for_UInt8_TimeAndInterval->count = 0;
  pRangeWriteIterator_for_UInt8_TimeAndInterval->isValid = false;
  pRangeWriteIterator_for_UInt8_TimeAndInterval->pPosition = NULL;
}

void RangeWriteIterator_for_UInt8_TimeAndInterval_in_RangeWriteIterator_for_UInt8_TimeAndIntervalOver2(RangeWriteIterator_for_UInt8_TimeAndInterval *pRangeWriteIterator_for_UInt8_TimeAndInterval,
//                   typename IndexType::type_t start_,
    uint8_t start_,
//                   const Serializer<WriteType>& serializer,
    Serializer_for_TimeAndInterval*  serializer,
//                   ser4cpp::wseq_t& position)
    WSeq_for_Uint16_t* position)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"RangeWriteIterator_for_UInt8_TimeAndInterval_in_RangeWriteIterator_for_UInt8_TimeAndIntervalOver2_1"<<'\n';
  decrement_stack_info();
#endif
  pRangeWriteIterator_for_UInt8_TimeAndInterval->start = start_;
  pRangeWriteIterator_for_UInt8_TimeAndInterval->serializer = *serializer;
  pRangeWriteIterator_for_UInt8_TimeAndInterval->count = 0;
//     isValid = position.length() >= 2 * IndexType::size),
  pRangeWriteIterator_for_UInt8_TimeAndInterval->isValid = length_in_HasLength_for_Uint16_t(&(position->hHasLength)) >= 2 * size_in_UInt8;

  pRangeWriteIterator_for_UInt8_TimeAndInterval->range = *position;
  pRangeWriteIterator_for_UInt8_TimeAndInterval->pPosition = position;

  if (pRangeWriteIterator_for_UInt8_TimeAndInterval->isValid)
  {
//        IndexType::write_to(range, start);
    write_to_in_UInt8_static(&(pRangeWriteIterator_for_UInt8_TimeAndInterval->range), pRangeWriteIterator_for_UInt8_TimeAndInterval->start);
//        pPosition->advance(2 * IndexType::size);
    advance_in_WSeq_for_Uint16_t(pRangeWriteIterator_for_UInt8_TimeAndInterval->pPosition, 2 * size_in_UInt8);
  }
}

////    ~RangeWriteIterator()
void RangeWriteIterator_for_UInt8_TimeAndInterval_destr_RangeWriteIterator_for_UInt8_TimeAndInterval(RangeWriteIterator_for_UInt8_TimeAndInterval *pRangeWriteIterator_for_UInt8_TimeAndInterval)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"RangeWriteIterator_for_UInt8_TimeAndInterval_destr_RangeWriteIterator_for_UInt8_TimeAndInterval1"<<'\n';
  decrement_stack_info();
#endif
  if (pRangeWriteIterator_for_UInt8_TimeAndInterval->isValid && pRangeWriteIterator_for_UInt8_TimeAndInterval->count > 0)
  {
    uint32_t stop = pRangeWriteIterator_for_UInt8_TimeAndInterval->start + pRangeWriteIterator_for_UInt8_TimeAndInterval->count - 1;
//        IndexType::write_to(range, static_cast<typename IndexType::type_t>(stop));
    write_to_in_UInt8_static(&(pRangeWriteIterator_for_UInt8_TimeAndInterval->range), (uint8_t)(stop));
  }
}

//    bool Write(const WriteType& value)
boolean Write_in_RangeWriteIterator_for_UInt8_TimeAndInterval(RangeWriteIterator_for_UInt8_TimeAndInterval *pRangeWriteIterator_for_UInt8_TimeAndInterval,
    TimeAndInterval* value)
{
//    if (isValid && (pPosition->length() >= serializer.get_size()) && (count <= IndexType::max_value))
  if(pRangeWriteIterator_for_UInt8_TimeAndInterval->isValid &&
      (length_in_HasLength_for_Uint16_t(&(pRangeWriteIterator_for_UInt8_TimeAndInterval->pPosition->hHasLength)) >=
       get_size_in_Serializer_for_TimeAndInterval(&(pRangeWriteIterator_for_UInt8_TimeAndInterval->serializer)))  &&
      (pRangeWriteIterator_for_UInt8_TimeAndInterval->count <= max_value_in_UInt8))
  {
//        serializer.write(value, *pPosition);
    write_in_Serializer_for_TimeAndInterval(&(pRangeWriteIterator_for_UInt8_TimeAndInterval->serializer), value, pRangeWriteIterator_for_UInt8_TimeAndInterval->pPosition);
    ++(pRangeWriteIterator_for_UInt8_TimeAndInterval->count);
    return true;
  }
  else
  {
    return false;
  }
}

boolean IsValid_in_RangeWriteIterator_for_UInt8_TimeAndInterval(RangeWriteIterator_for_UInt8_TimeAndInterval *pRangeWriteIterator_for_UInt8_TimeAndInterval)
{
  return pRangeWriteIterator_for_UInt8_TimeAndInterval->isValid;
}
//-------------------RangeWriteIterator_for_UInt8_TimeAndInterval---------------------------------------------------
//-------------------RangeWriteIterator_for_UInt16_TimeAndInterval---------------------------------------------------
RangeWriteIterator_for_UInt16_TimeAndInterval Null_in_RangeWriteIterator_for_UInt16_TimeAndInterval_static(void)
{
  RangeWriteIterator_for_UInt16_TimeAndInterval rRangeWriteIterator_for_UInt16_TimeAndInterval;
  RangeWriteIterator_for_UInt16_TimeAndInterval_in_RangeWriteIterator_for_UInt16_TimeAndIntervalOver1(&rRangeWriteIterator_for_UInt16_TimeAndInterval);
//    return RangeWriteIterator();
  return rRangeWriteIterator_for_UInt16_TimeAndInterval;
}

////    RangeWriteIterator() : start(0), count(0), isValid(false), pPosition(nullptr) {}
void RangeWriteIterator_for_UInt16_TimeAndInterval_in_RangeWriteIterator_for_UInt16_TimeAndIntervalOver1(RangeWriteIterator_for_UInt16_TimeAndInterval *pRangeWriteIterator_for_UInt16_TimeAndInterval)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"RangeWriteIterator_for_UInt16_TimeAndInterval_in_RangeWriteIterator_for_UInt16_TimeAndIntervalOver1_1"<<'\n';
  decrement_stack_info();
#endif
  pRangeWriteIterator_for_UInt16_TimeAndInterval->start = 0;
  pRangeWriteIterator_for_UInt16_TimeAndInterval->count = 0;
  pRangeWriteIterator_for_UInt16_TimeAndInterval->isValid = false;
  pRangeWriteIterator_for_UInt16_TimeAndInterval->pPosition = NULL;
}

void RangeWriteIterator_for_UInt16_TimeAndInterval_in_RangeWriteIterator_for_UInt16_TimeAndIntervalOver2(RangeWriteIterator_for_UInt16_TimeAndInterval *pRangeWriteIterator_for_UInt16_TimeAndInterval,
//                   typename IndexType::type_t start_,
    uint16_t start_,
//                   const Serializer<WriteType>& serializer,
    Serializer_for_TimeAndInterval*  serializer,
//                   ser4cpp::wseq_t& position)
    WSeq_for_Uint16_t* position)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"RangeWriteIterator_for_UInt16_TimeAndInterval_in_RangeWriteIterator_for_UInt16_TimeAndIntervalOver2_1"<<'\n';
  decrement_stack_info();
#endif
  pRangeWriteIterator_for_UInt16_TimeAndInterval->start = start_;
  pRangeWriteIterator_for_UInt16_TimeAndInterval->serializer = *serializer;
  pRangeWriteIterator_for_UInt16_TimeAndInterval->count = 0;
//     isValid = position.length() >= 2 * IndexType::size),
  pRangeWriteIterator_for_UInt16_TimeAndInterval->isValid = length_in_HasLength_for_Uint16_t(&(position->hHasLength)) >= 2 * size_in_UInt16;

  pRangeWriteIterator_for_UInt16_TimeAndInterval->range = *position;
  pRangeWriteIterator_for_UInt16_TimeAndInterval->pPosition = position;

  if (pRangeWriteIterator_for_UInt16_TimeAndInterval->isValid)
  {
//        IndexType::write_to(range, start);
    write_to_in_UInt16_static(&(pRangeWriteIterator_for_UInt16_TimeAndInterval->range), pRangeWriteIterator_for_UInt16_TimeAndInterval->start);
//        pPosition->advance(2 * IndexType::size);
    advance_in_WSeq_for_Uint16_t(pRangeWriteIterator_for_UInt16_TimeAndInterval->pPosition, 2 * size_in_UInt16);
  }
}

////    ~RangeWriteIterator()
void RangeWriteIterator_for_UInt16_TimeAndInterval_destr_RangeWriteIterator_for_UInt16_TimeAndInterval(RangeWriteIterator_for_UInt16_TimeAndInterval *pRangeWriteIterator_for_UInt16_TimeAndInterval)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"RangeWriteIterator_for_UInt16_TimeAndInterval_destr_RangeWriteIterator_for_UInt16_TimeAndInterval1"<<'\n';
  decrement_stack_info();
#endif
  if (pRangeWriteIterator_for_UInt16_TimeAndInterval->isValid && pRangeWriteIterator_for_UInt16_TimeAndInterval->count > 0)
  {
    uint32_t stop = pRangeWriteIterator_for_UInt16_TimeAndInterval->start + pRangeWriteIterator_for_UInt16_TimeAndInterval->count - 1;
//        IndexType::write_to(range, static_cast<typename IndexType::type_t>(stop));
    write_to_in_UInt16_static(&(pRangeWriteIterator_for_UInt16_TimeAndInterval->range), (uint16_t)(stop));
  }
}

//    bool Write(const WriteType& value)
boolean Write_in_RangeWriteIterator_for_UInt16_TimeAndInterval(RangeWriteIterator_for_UInt16_TimeAndInterval *pRangeWriteIterator_for_UInt16_TimeAndInterval,
    TimeAndInterval* value)
{
//    if (isValid && (pPosition->length() >= serializer.get_size()) && (count <= IndexType::max_value))
  if(pRangeWriteIterator_for_UInt16_TimeAndInterval->isValid &&
      (length_in_HasLength_for_Uint16_t(&(pRangeWriteIterator_for_UInt16_TimeAndInterval->pPosition->hHasLength)) >=
       get_size_in_Serializer_for_TimeAndInterval(&(pRangeWriteIterator_for_UInt16_TimeAndInterval->serializer)))  &&
      (pRangeWriteIterator_for_UInt16_TimeAndInterval->count <= max_value_in_UInt16))
  {
//        serializer.write(value, *pPosition);
    write_in_Serializer_for_TimeAndInterval(&(pRangeWriteIterator_for_UInt16_TimeAndInterval->serializer), value, pRangeWriteIterator_for_UInt16_TimeAndInterval->pPosition);
    ++(pRangeWriteIterator_for_UInt16_TimeAndInterval->count);
    return true;
  }
  else
  {
    return false;
  }
}

boolean IsValid_in_RangeWriteIterator_for_UInt16_TimeAndInterval(RangeWriteIterator_for_UInt16_TimeAndInterval *pRangeWriteIterator_for_UInt16_TimeAndInterval)
{
  return pRangeWriteIterator_for_UInt16_TimeAndInterval->isValid;
}
//-------------------RangeWriteIterator_for_UInt16_TimeAndInterval---------------------------------------------------
