#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "RangeWriteIterator_for_AnalogOutputStatus.h"
#include "SerializationTemplates.h"
#include <string.h>
//-------------------RangeWriteIterator_for_UInt8_AnalogOutputStatus---------------------------------------------------
RangeWriteIterator_for_UInt8_AnalogOutputStatus Null_in_RangeWriteIterator_for_UInt8_AnalogOutputStatus_static(void)
{
  RangeWriteIterator_for_UInt8_AnalogOutputStatus rRangeWriteIterator_for_UInt8_AnalogOutputStatus;
  RangeWriteIterator_for_UInt8_AnalogOutputStatus_in_RangeWriteIterator_for_UInt8_AnalogOutputStatusOver1(&rRangeWriteIterator_for_UInt8_AnalogOutputStatus);
//    return RangeWriteIterator();
  return rRangeWriteIterator_for_UInt8_AnalogOutputStatus;
}

////    RangeWriteIterator() : start(0), count(0), isValid(false), pPosition(nullptr) {}
void RangeWriteIterator_for_UInt8_AnalogOutputStatus_in_RangeWriteIterator_for_UInt8_AnalogOutputStatusOver1(RangeWriteIterator_for_UInt8_AnalogOutputStatus *pRangeWriteIterator_for_UInt8_AnalogOutputStatus)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<""<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"RangeWriteIterator_for_UInt8_AnalogOutputStatus_in_RangeWriteIterator_for_UInt8_AnalogOutputStatusOver1_1"<<'\n';
  decrement_stack_info();
#endif
  pRangeWriteIterator_for_UInt8_AnalogOutputStatus->start = 0;
  pRangeWriteIterator_for_UInt8_AnalogOutputStatus->count = 0;
  pRangeWriteIterator_for_UInt8_AnalogOutputStatus->isValid = false;
  pRangeWriteIterator_for_UInt8_AnalogOutputStatus->pPosition = NULL;
}

void RangeWriteIterator_for_UInt8_AnalogOutputStatus_in_RangeWriteIterator_for_UInt8_AnalogOutputStatusOver2(RangeWriteIterator_for_UInt8_AnalogOutputStatus *pRangeWriteIterator_for_UInt8_AnalogOutputStatus,
//                   typename IndexType::type_t start_,
    uint8_t start_,
//                   const Serializer<WriteType>& serializer,
    Serializer_for_AnalogOutputStatus*  serializer,
//                   ser4cpp::wseq_t& position)
    WSeq_for_Uint16_t* position)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<""<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"RangeWriteIterator_for_UInt8_AnalogOutputStatus_in_RangeWriteIterator_for_UInt8_AnalogOutputStatusOver2_1"<<'\n';
  decrement_stack_info();
#endif
  pRangeWriteIterator_for_UInt8_AnalogOutputStatus->start = start_;
  pRangeWriteIterator_for_UInt8_AnalogOutputStatus->serializer = *serializer;
  pRangeWriteIterator_for_UInt8_AnalogOutputStatus->count = 0;
//     isValid = position.length() >= 2 * IndexType::size),
  pRangeWriteIterator_for_UInt8_AnalogOutputStatus->isValid = length_in_HasLength_for_Uint16_t(&(position->hHasLength)) >= 2 * size_in_UInt8;

  pRangeWriteIterator_for_UInt8_AnalogOutputStatus->range = *position;
  pRangeWriteIterator_for_UInt8_AnalogOutputStatus->pPosition = position;

  if (pRangeWriteIterator_for_UInt8_AnalogOutputStatus->isValid)
  {
//        IndexType::write_to(range, start);
    write_to_in_UInt8_static(&(pRangeWriteIterator_for_UInt8_AnalogOutputStatus->range), pRangeWriteIterator_for_UInt8_AnalogOutputStatus->start);
//        pPosition->advance(2 * IndexType::size);
    advance_in_WSeq_for_Uint16_t(pRangeWriteIterator_for_UInt8_AnalogOutputStatus->pPosition, 2 * size_in_UInt8);
  }
}

////    ~RangeWriteIterator()
void RangeWriteIterator_for_UInt8_AnalogOutputStatus_destr_RangeWriteIterator_for_UInt8_AnalogOutputStatus(RangeWriteIterator_for_UInt8_AnalogOutputStatus *pRangeWriteIterator_for_UInt8_AnalogOutputStatus)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<""<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"RangeWriteIterator_for_UInt8_AnalogOutputStatus_destr_RangeWriteIterator_for_UInt8_AnalogOutputStatus1"<<'\n';
  decrement_stack_info();
#endif
  if (pRangeWriteIterator_for_UInt8_AnalogOutputStatus->isValid && pRangeWriteIterator_for_UInt8_AnalogOutputStatus->count > 0)
  {
    uint32_t stop = pRangeWriteIterator_for_UInt8_AnalogOutputStatus->start + pRangeWriteIterator_for_UInt8_AnalogOutputStatus->count - 1;
//        IndexType::write_to(range, static_cast<typename IndexType::type_t>(stop));
    write_to_in_UInt8_static(&(pRangeWriteIterator_for_UInt8_AnalogOutputStatus->range), (uint8_t)(stop));
  }
}

//    bool Write(const WriteType& value)
boolean Write_in_RangeWriteIterator_for_UInt8_AnalogOutputStatus(RangeWriteIterator_for_UInt8_AnalogOutputStatus *pRangeWriteIterator_for_UInt8_AnalogOutputStatus,
    AnalogOutputStatus* value)
{
//    if (isValid && (pPosition->length() >= serializer.get_size()) && (count <= IndexType::max_value))
  if(pRangeWriteIterator_for_UInt8_AnalogOutputStatus->isValid &&
      (length_in_HasLength_for_Uint16_t(&(pRangeWriteIterator_for_UInt8_AnalogOutputStatus->pPosition->hHasLength)) >=
       get_size_in_Serializer_for_AnalogOutputStatus(&(pRangeWriteIterator_for_UInt8_AnalogOutputStatus->serializer)))  &&
      (pRangeWriteIterator_for_UInt8_AnalogOutputStatus->count <= max_value_in_UInt8))
  {
//        serializer.write(value, *pPosition);
    write_in_Serializer_for_AnalogOutputStatus(&(pRangeWriteIterator_for_UInt8_AnalogOutputStatus->serializer), value, pRangeWriteIterator_for_UInt8_AnalogOutputStatus->pPosition);
    ++(pRangeWriteIterator_for_UInt8_AnalogOutputStatus->count);
    return true;
  }
  else
  {
    return false;
  }
}

boolean IsValid_in_RangeWriteIterator_for_UInt8_AnalogOutputStatus(RangeWriteIterator_for_UInt8_AnalogOutputStatus *pRangeWriteIterator_for_UInt8_AnalogOutputStatus)
{
  return pRangeWriteIterator_for_UInt8_AnalogOutputStatus->isValid;
}
//-------------------RangeWriteIterator_for_UInt8_AnalogOutputStatus---------------------------------------------------
//-------------------RangeWriteIterator_for_UInt16_AnalogOutputStatus---------------------------------------------------
RangeWriteIterator_for_UInt16_AnalogOutputStatus Null_in_RangeWriteIterator_for_UInt16_AnalogOutputStatus_static(void)
{
  RangeWriteIterator_for_UInt16_AnalogOutputStatus rRangeWriteIterator_for_UInt16_AnalogOutputStatus;
  RangeWriteIterator_for_UInt16_AnalogOutputStatus_in_RangeWriteIterator_for_UInt16_AnalogOutputStatusOver1(&rRangeWriteIterator_for_UInt16_AnalogOutputStatus);
//    return RangeWriteIterator();
  return rRangeWriteIterator_for_UInt16_AnalogOutputStatus;
}

////    RangeWriteIterator() : start(0), count(0), isValid(false), pPosition(nullptr) {}
void RangeWriteIterator_for_UInt16_AnalogOutputStatus_in_RangeWriteIterator_for_UInt16_AnalogOutputStatusOver1(RangeWriteIterator_for_UInt16_AnalogOutputStatus *pRangeWriteIterator_for_UInt16_AnalogOutputStatus)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<""<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"RangeWriteIterator_for_UInt16_AnalogOutputStatus_in_RangeWriteIterator_for_UInt16_AnalogOutputStatusOver1_1"<<'\n';
  decrement_stack_info();
#endif
  pRangeWriteIterator_for_UInt16_AnalogOutputStatus->start = 0;
  pRangeWriteIterator_for_UInt16_AnalogOutputStatus->count = 0;
  pRangeWriteIterator_for_UInt16_AnalogOutputStatus->isValid = false;
  pRangeWriteIterator_for_UInt16_AnalogOutputStatus->pPosition = NULL;
}

void RangeWriteIterator_for_UInt16_AnalogOutputStatus_in_RangeWriteIterator_for_UInt16_AnalogOutputStatusOver2(RangeWriteIterator_for_UInt16_AnalogOutputStatus *pRangeWriteIterator_for_UInt16_AnalogOutputStatus,
//                   typename IndexType::type_t start_,
    uint16_t start_,
//                   const Serializer<WriteType>& serializer,
    Serializer_for_AnalogOutputStatus*  serializer,
//                   ser4cpp::wseq_t& position)
    WSeq_for_Uint16_t* position)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<""<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"RangeWriteIterator_for_UInt16_AnalogOutputStatus_in_RangeWriteIterator_for_UInt16_AnalogOutputStatusOver2_1"<<'\n';
  decrement_stack_info();
#endif
  pRangeWriteIterator_for_UInt16_AnalogOutputStatus->start = start_;
  pRangeWriteIterator_for_UInt16_AnalogOutputStatus->serializer = *serializer;
  pRangeWriteIterator_for_UInt16_AnalogOutputStatus->count = 0;
//     isValid = position.length() >= 2 * IndexType::size),
  pRangeWriteIterator_for_UInt16_AnalogOutputStatus->isValid = length_in_HasLength_for_Uint16_t(&(position->hHasLength)) >= 2 * size_in_UInt16;

  pRangeWriteIterator_for_UInt16_AnalogOutputStatus->range = *position;
  pRangeWriteIterator_for_UInt16_AnalogOutputStatus->pPosition = position;

  if (pRangeWriteIterator_for_UInt16_AnalogOutputStatus->isValid)
  {
//        IndexType::write_to(range, start);
    write_to_in_UInt16_static(&(pRangeWriteIterator_for_UInt16_AnalogOutputStatus->range), pRangeWriteIterator_for_UInt16_AnalogOutputStatus->start);
//        pPosition->advance(2 * IndexType::size);
    advance_in_WSeq_for_Uint16_t(pRangeWriteIterator_for_UInt16_AnalogOutputStatus->pPosition, 2 * size_in_UInt16);
  }
}

////    ~RangeWriteIterator()
void RangeWriteIterator_for_UInt16_AnalogOutputStatus_destr_RangeWriteIterator_for_UInt16_AnalogOutputStatus(RangeWriteIterator_for_UInt16_AnalogOutputStatus *pRangeWriteIterator_for_UInt16_AnalogOutputStatus)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<""<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"RangeWriteIterator_for_UInt16_AnalogOutputStatus_destr_RangeWriteIterator_for_UInt16_AnalogOutputStatus1"<<'\n';
  decrement_stack_info();
#endif
  if (pRangeWriteIterator_for_UInt16_AnalogOutputStatus->isValid && pRangeWriteIterator_for_UInt16_AnalogOutputStatus->count > 0)
  {
    uint32_t stop = pRangeWriteIterator_for_UInt16_AnalogOutputStatus->start + pRangeWriteIterator_for_UInt16_AnalogOutputStatus->count - 1;
//        IndexType::write_to(range, static_cast<typename IndexType::type_t>(stop));
    write_to_in_UInt16_static(&(pRangeWriteIterator_for_UInt16_AnalogOutputStatus->range), (uint16_t)(stop));
  }
}

//    bool Write(const WriteType& value)
boolean Write_in_RangeWriteIterator_for_UInt16_AnalogOutputStatus(RangeWriteIterator_for_UInt16_AnalogOutputStatus *pRangeWriteIterator_for_UInt16_AnalogOutputStatus,
    AnalogOutputStatus* value)
{
//    if (isValid && (pPosition->length() >= serializer.get_size()) && (count <= IndexType::max_value))
  if(pRangeWriteIterator_for_UInt16_AnalogOutputStatus->isValid &&
      (length_in_HasLength_for_Uint16_t(&(pRangeWriteIterator_for_UInt16_AnalogOutputStatus->pPosition->hHasLength)) >=
       get_size_in_Serializer_for_AnalogOutputStatus(&(pRangeWriteIterator_for_UInt16_AnalogOutputStatus->serializer)))  &&
      (pRangeWriteIterator_for_UInt16_AnalogOutputStatus->count <= max_value_in_UInt16))
  {
//        serializer.write(value, *pPosition);
    write_in_Serializer_for_AnalogOutputStatus(&(pRangeWriteIterator_for_UInt16_AnalogOutputStatus->serializer), value, pRangeWriteIterator_for_UInt16_AnalogOutputStatus->pPosition);
    ++(pRangeWriteIterator_for_UInt16_AnalogOutputStatus->count);
    return true;
  }
  else
  {
    return false;
  }
}

boolean IsValid_in_RangeWriteIterator_for_UInt16_AnalogOutputStatus(RangeWriteIterator_for_UInt16_AnalogOutputStatus *pRangeWriteIterator_for_UInt16_AnalogOutputStatus)
{
  return pRangeWriteIterator_for_UInt16_AnalogOutputStatus->isValid;
}
//-------------------RangeWriteIterator_for_UInt16_AnalogOutputStatus---------------------------------------------------
