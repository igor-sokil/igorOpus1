#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "RangeWriteIterator_for_BinaryOutputStatus.h"
#include "SerializationTemplates.h"
#include <string.h>
//-------------------RangeWriteIterator_for_UInt8_BinaryOutputStatus---------------------------------------------------
RangeWriteIterator_for_UInt8_BinaryOutputStatus Null_in_RangeWriteIterator_for_UInt8_BinaryOutputStatus_static(void)
{
  RangeWriteIterator_for_UInt8_BinaryOutputStatus rRangeWriteIterator_for_UInt8_BinaryOutputStatus;
  RangeWriteIterator_for_UInt8_BinaryOutputStatus_in_RangeWriteIterator_for_UInt8_BinaryOutputStatusOver1(&rRangeWriteIterator_for_UInt8_BinaryOutputStatus);
//    return RangeWriteIterator();
  return rRangeWriteIterator_for_UInt8_BinaryOutputStatus;
}

////    RangeWriteIterator() : start(0), count(0), isValid(false), pPosition(nullptr) {}
void RangeWriteIterator_for_UInt8_BinaryOutputStatus_in_RangeWriteIterator_for_UInt8_BinaryOutputStatusOver1(RangeWriteIterator_for_UInt8_BinaryOutputStatus *pRangeWriteIterator_for_UInt8_BinaryOutputStatus)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"RangeWriteIterator_for_UInt8_BinaryOutputStatus_in_RangeWriteIterator_for_UInt8_BinaryOutputStatusOver1_1"<<'\n';
  decrement_stack_info();
#endif
  pRangeWriteIterator_for_UInt8_BinaryOutputStatus->start = 0;
  pRangeWriteIterator_for_UInt8_BinaryOutputStatus->count = 0;
  pRangeWriteIterator_for_UInt8_BinaryOutputStatus->isValid = false;
  pRangeWriteIterator_for_UInt8_BinaryOutputStatus->pPosition = NULL;
}

void RangeWriteIterator_for_UInt8_BinaryOutputStatus_in_RangeWriteIterator_for_UInt8_BinaryOutputStatusOver2(RangeWriteIterator_for_UInt8_BinaryOutputStatus *pRangeWriteIterator_for_UInt8_BinaryOutputStatus,
//                   typename IndexType::type_t start_,
    uint8_t start_,
//                   const Serializer<WriteType>& serializer,
    Serializer_for_BinaryOutputStatus*  serializer,
//                   ser4cpp::wseq_t& position)
    WSeq_for_Uint16_t* position)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"RangeWriteIterator_for_UInt8_BinaryOutputStatus_in_RangeWriteIterator_for_UInt8_BinaryOutputStatusOver2_1"<<'\n';
  decrement_stack_info();
#endif
  pRangeWriteIterator_for_UInt8_BinaryOutputStatus->start = start_;
  pRangeWriteIterator_for_UInt8_BinaryOutputStatus->serializer = *serializer;
  pRangeWriteIterator_for_UInt8_BinaryOutputStatus->count = 0;
//     isValid = position.length() >= 2 * IndexType::size),
  pRangeWriteIterator_for_UInt8_BinaryOutputStatus->isValid = length_in_HasLength_for_Uint16_t(&(position->hHasLength)) >= 2 * size_in_UInt8;

  pRangeWriteIterator_for_UInt8_BinaryOutputStatus->range = *position;
  pRangeWriteIterator_for_UInt8_BinaryOutputStatus->pPosition = position;

  if (pRangeWriteIterator_for_UInt8_BinaryOutputStatus->isValid)
  {
//        IndexType::write_to(range, start);
    write_to_in_UInt8_static(&(pRangeWriteIterator_for_UInt8_BinaryOutputStatus->range), pRangeWriteIterator_for_UInt8_BinaryOutputStatus->start);
//        pPosition->advance(2 * IndexType::size);
    advance_in_WSeq_for_Uint16_t(pRangeWriteIterator_for_UInt8_BinaryOutputStatus->pPosition, 2 * size_in_UInt8);
  }
}

////    ~RangeWriteIterator()
void RangeWriteIterator_for_UInt8_BinaryOutputStatus_destr_RangeWriteIterator_for_UInt8_BinaryOutputStatus(RangeWriteIterator_for_UInt8_BinaryOutputStatus *pRangeWriteIterator_for_UInt8_BinaryOutputStatus)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"RangeWriteIterator_for_UInt8_BinaryOutputStatus_destr_RangeWriteIterator_for_UInt8_BinaryOutputStatus1"<<'\n';
  decrement_stack_info();
#endif
  if (pRangeWriteIterator_for_UInt8_BinaryOutputStatus->isValid && pRangeWriteIterator_for_UInt8_BinaryOutputStatus->count > 0)
  {
    uint32_t stop = pRangeWriteIterator_for_UInt8_BinaryOutputStatus->start + pRangeWriteIterator_for_UInt8_BinaryOutputStatus->count - 1;
//        IndexType::write_to(range, static_cast<typename IndexType::type_t>(stop));
    write_to_in_UInt8_static(&(pRangeWriteIterator_for_UInt8_BinaryOutputStatus->range), (uint8_t)(stop));
  }
}

//    bool Write(const WriteType& value)
boolean Write_in_RangeWriteIterator_for_UInt8_BinaryOutputStatus(RangeWriteIterator_for_UInt8_BinaryOutputStatus *pRangeWriteIterator_for_UInt8_BinaryOutputStatus,
    BinaryOutputStatus* value)
{
//    if (isValid && (pPosition->length() >= serializer.get_size()) && (count <= IndexType::max_value))
  if(pRangeWriteIterator_for_UInt8_BinaryOutputStatus->isValid &&
      (length_in_HasLength_for_Uint16_t(&(pRangeWriteIterator_for_UInt8_BinaryOutputStatus->pPosition->hHasLength)) >=
       get_size_in_Serializer_for_BinaryOutputStatus(&(pRangeWriteIterator_for_UInt8_BinaryOutputStatus->serializer)))  &&
      (pRangeWriteIterator_for_UInt8_BinaryOutputStatus->count <= max_value_in_UInt8))
  {
//        serializer.write(value, *pPosition);
    write_in_Serializer_for_BinaryOutputStatus(&(pRangeWriteIterator_for_UInt8_BinaryOutputStatus->serializer), value, pRangeWriteIterator_for_UInt8_BinaryOutputStatus->pPosition);
    ++(pRangeWriteIterator_for_UInt8_BinaryOutputStatus->count);
    return true;
  }
  else
  {
    return false;
  }
}

boolean IsValid_in_RangeWriteIterator_for_UInt8_BinaryOutputStatus(RangeWriteIterator_for_UInt8_BinaryOutputStatus *pRangeWriteIterator_for_UInt8_BinaryOutputStatus)
{
  return pRangeWriteIterator_for_UInt8_BinaryOutputStatus->isValid;
}
//-------------------RangeWriteIterator_for_UInt8_BinaryOutputStatus---------------------------------------------------
//-------------------RangeWriteIterator_for_UInt16_BinaryOutputStatus---------------------------------------------------
RangeWriteIterator_for_UInt16_BinaryOutputStatus Null_in_RangeWriteIterator_for_UInt16_BinaryOutputStatus_static(void)
{
  RangeWriteIterator_for_UInt16_BinaryOutputStatus rRangeWriteIterator_for_UInt16_BinaryOutputStatus;
  RangeWriteIterator_for_UInt16_BinaryOutputStatus_in_RangeWriteIterator_for_UInt16_BinaryOutputStatusOver1(&rRangeWriteIterator_for_UInt16_BinaryOutputStatus);
//    return RangeWriteIterator();
  return rRangeWriteIterator_for_UInt16_BinaryOutputStatus;
}

////    RangeWriteIterator() : start(0), count(0), isValid(false), pPosition(nullptr) {}
void RangeWriteIterator_for_UInt16_BinaryOutputStatus_in_RangeWriteIterator_for_UInt16_BinaryOutputStatusOver1(RangeWriteIterator_for_UInt16_BinaryOutputStatus *pRangeWriteIterator_for_UInt16_BinaryOutputStatus)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"RangeWriteIterator_for_UInt16_BinaryOutputStatus_in_RangeWriteIterator_for_UInt16_BinaryOutputStatusOver1_1"<<'\n';
  decrement_stack_info();
#endif
  pRangeWriteIterator_for_UInt16_BinaryOutputStatus->start = 0;
  pRangeWriteIterator_for_UInt16_BinaryOutputStatus->count = 0;
  pRangeWriteIterator_for_UInt16_BinaryOutputStatus->isValid = false;
  pRangeWriteIterator_for_UInt16_BinaryOutputStatus->pPosition = NULL;
}

void RangeWriteIterator_for_UInt16_BinaryOutputStatus_in_RangeWriteIterator_for_UInt16_BinaryOutputStatusOver2(RangeWriteIterator_for_UInt16_BinaryOutputStatus *pRangeWriteIterator_for_UInt16_BinaryOutputStatus,
//                   typename IndexType::type_t start_,
    uint16_t start_,
//                   const Serializer<WriteType>& serializer,
    Serializer_for_BinaryOutputStatus*  serializer,
//                   ser4cpp::wseq_t& position)
    WSeq_for_Uint16_t* position)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"RangeWriteIterator_for_UInt16_BinaryOutputStatus_in_RangeWriteIterator_for_UInt16_BinaryOutputStatusOver2_1"<<'\n';
  decrement_stack_info();
#endif
  pRangeWriteIterator_for_UInt16_BinaryOutputStatus->start = start_;
  pRangeWriteIterator_for_UInt16_BinaryOutputStatus->serializer = *serializer;
  pRangeWriteIterator_for_UInt16_BinaryOutputStatus->count = 0;
//     isValid = position.length() >= 2 * IndexType::size),
  pRangeWriteIterator_for_UInt16_BinaryOutputStatus->isValid = length_in_HasLength_for_Uint16_t(&(position->hHasLength)) >= 2 * size_in_UInt16;

  pRangeWriteIterator_for_UInt16_BinaryOutputStatus->range = *position;
  pRangeWriteIterator_for_UInt16_BinaryOutputStatus->pPosition = position;

  if (pRangeWriteIterator_for_UInt16_BinaryOutputStatus->isValid)
  {
//        IndexType::write_to(range, start);
    write_to_in_UInt16_static(&(pRangeWriteIterator_for_UInt16_BinaryOutputStatus->range), pRangeWriteIterator_for_UInt16_BinaryOutputStatus->start);
//        pPosition->advance(2 * IndexType::size);
    advance_in_WSeq_for_Uint16_t(pRangeWriteIterator_for_UInt16_BinaryOutputStatus->pPosition, 2 * size_in_UInt16);
  }
}

////    ~RangeWriteIterator()
void RangeWriteIterator_for_UInt16_BinaryOutputStatus_destr_RangeWriteIterator_for_UInt16_BinaryOutputStatus(RangeWriteIterator_for_UInt16_BinaryOutputStatus *pRangeWriteIterator_for_UInt16_BinaryOutputStatus)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"RangeWriteIterator_for_UInt16_BinaryOutputStatus_destr_RangeWriteIterator_for_UInt16_BinaryOutputStatus1"<<'\n';
  decrement_stack_info();
#endif
  if (pRangeWriteIterator_for_UInt16_BinaryOutputStatus->isValid && pRangeWriteIterator_for_UInt16_BinaryOutputStatus->count > 0)
  {
    uint32_t stop = pRangeWriteIterator_for_UInt16_BinaryOutputStatus->start + pRangeWriteIterator_for_UInt16_BinaryOutputStatus->count - 1;
//        IndexType::write_to(range, static_cast<typename IndexType::type_t>(stop));
    write_to_in_UInt16_static(&(pRangeWriteIterator_for_UInt16_BinaryOutputStatus->range), (uint16_t)(stop));
  }
}

//    bool Write(const WriteType& value)
boolean Write_in_RangeWriteIterator_for_UInt16_BinaryOutputStatus(RangeWriteIterator_for_UInt16_BinaryOutputStatus *pRangeWriteIterator_for_UInt16_BinaryOutputStatus,
    BinaryOutputStatus* value)
{
//    if (isValid && (pPosition->length() >= serializer.get_size()) && (count <= IndexType::max_value))
  if(pRangeWriteIterator_for_UInt16_BinaryOutputStatus->isValid &&
      (length_in_HasLength_for_Uint16_t(&(pRangeWriteIterator_for_UInt16_BinaryOutputStatus->pPosition->hHasLength)) >=
       get_size_in_Serializer_for_BinaryOutputStatus(&(pRangeWriteIterator_for_UInt16_BinaryOutputStatus->serializer)))  &&
      (pRangeWriteIterator_for_UInt16_BinaryOutputStatus->count <= max_value_in_UInt16))
  {
//        serializer.write(value, *pPosition);
    write_in_Serializer_for_BinaryOutputStatus(&(pRangeWriteIterator_for_UInt16_BinaryOutputStatus->serializer), value, pRangeWriteIterator_for_UInt16_BinaryOutputStatus->pPosition);
    ++(pRangeWriteIterator_for_UInt16_BinaryOutputStatus->count);
    return true;
  }
  else
  {
    return false;
  }
}

boolean IsValid_in_RangeWriteIterator_for_UInt16_BinaryOutputStatus(RangeWriteIterator_for_UInt16_BinaryOutputStatus *pRangeWriteIterator_for_UInt16_BinaryOutputStatus)
{
  return pRangeWriteIterator_for_UInt16_BinaryOutputStatus->isValid;
}
//-------------------RangeWriteIterator_for_UInt16_BinaryOutputStatus---------------------------------------------------
