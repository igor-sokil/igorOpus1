#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "PrefixedWriteIterator_for_AnalogOutputStatus.h"
#include "SerializationTemplates.h"
#include <string.h>

//-------------------Uint8---------------------------------------------------
PrefixedWriteIterator_for_UInt8_AnalogOutputStatus Null_in_PrefixedWriteIterator_for_UInt8_AnalogOutputStatus_static(void)
{
  PrefixedWriteIterator_for_UInt8_AnalogOutputStatus pPrefixedWriteIterator_for_UInt8_AnalogOutputStatus;
////    return PrefixedWriteIterator();
  PrefixedWriteIterator_for_UInt8_AnalogOutputStatus_in_PrefixedWriteIterator_for_UInt8_AnalogOutputStatusOver1(&pPrefixedWriteIterator_for_UInt8_AnalogOutputStatus);
  return pPrefixedWriteIterator_for_UInt8_AnalogOutputStatus;
}

void PrefixedWriteIterator_for_UInt8_AnalogOutputStatus_in_PrefixedWriteIterator_for_UInt8_AnalogOutputStatusOver1(PrefixedWriteIterator_for_UInt8_AnalogOutputStatus *pPrefixedWriteIterator_for_UInt8_AnalogOutputStatus)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"PrefixedWriteIterator_for_UInt8_AnalogOutputStatus_in_PrefixedWriteIterator_for_UInt8_AnalogOutputStatusOver1_1"<<'\n';
  decrement_stack_info();
#endif
//// : sizeOfTypePlusIndex(0), count(0), isValid(false), pPosition(nullptr) {}
  pPrefixedWriteIterator_for_UInt8_AnalogOutputStatus->sizeOfTypePlusIndex = 0;
  pPrefixedWriteIterator_for_UInt8_AnalogOutputStatus->count = 0;
  pPrefixedWriteIterator_for_UInt8_AnalogOutputStatus->isValid = false;
  pPrefixedWriteIterator_for_UInt8_AnalogOutputStatus->pPosition = NULL;
}

void PrefixedWriteIterator_for_UInt8_AnalogOutputStatus_in_PrefixedWriteIterator_for_UInt8_AnalogOutputStatusOver2(PrefixedWriteIterator_for_UInt8_AnalogOutputStatus *pPrefixedWriteIterator_for_UInt8_AnalogOutputStatus,
    Serializer_for_AnalogOutputStatus* serializer, WSeq_for_Uint16_t* position)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<""<<'\n';
  std::cout<<"PrefixedWriteIterator_for_UInt8_AnalogOutputStatus_in_PrefixedWriteIterator_for_UInt8_AnalogOutputStatusOver2_1"<<'\n';
  decrement_stack_info();
#endif
  pPrefixedWriteIterator_for_UInt8_AnalogOutputStatus->serializer = *serializer;
  pPrefixedWriteIterator_for_UInt8_AnalogOutputStatus->sizeOfTypePlusIndex = get_size_in_Serializer_for_AnalogOutputStatus(serializer) +////serializer.get_size() + PrefixType::size;
      size_in_UInt8;
  pPrefixedWriteIterator_for_UInt8_AnalogOutputStatus->count = 0;
  ////isValid = position.length() >= PrefixType::size),
  pPrefixedWriteIterator_for_UInt8_AnalogOutputStatus->isValid = length_in_HasLength_for_Uint16_t(&(position->hHasLength)) >= size_in_UInt8;
  pPrefixedWriteIterator_for_UInt8_AnalogOutputStatus->countPosition = *position;
  pPrefixedWriteIterator_for_UInt8_AnalogOutputStatus->pPosition = position;

  if (pPrefixedWriteIterator_for_UInt8_AnalogOutputStatus->isValid)
  {
////        pPosition->advance(PrefixType::size);
    advance_in_WSeq_for_Uint16_t(position, size_in_UInt8);
  }
}

////    ~PrefixedWriteIterator()
void PrefixedWriteIterator_for_UInt8_AnalogOutputStatus_destr_PrefixedWriteIterator_for_UInt8_AnalogOutputStatus(PrefixedWriteIterator_for_UInt8_AnalogOutputStatus *pPrefixedWriteIterator_for_UInt8_AnalogOutputStatus)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"PrefixedWriteIterator_for_UInt8_AnalogOutputStatus_destr_PrefixedWriteIterator_for_UInt8_AnalogOutputStatus1"<<'\n';
  decrement_stack_info();
#endif
  if (pPrefixedWriteIterator_for_UInt8_AnalogOutputStatus->isValid)
  {
////        PrefixType::write_to(countPosition, count);
    write_to_in_UInt8_static(&(pPrefixedWriteIterator_for_UInt8_AnalogOutputStatus->countPosition), pPrefixedWriteIterator_for_UInt8_AnalogOutputStatus->count);
  }
}

boolean Write_in_PrefixedWriteIterator_for_UInt8_AnalogOutputStatus(PrefixedWriteIterator_for_UInt8_AnalogOutputStatus *pPrefixedWriteIterator_for_UInt8_AnalogOutputStatus,
    AnalogOutputStatus* value, uint16_t index)
{
////    if (isValid && (pPosition->length() >= sizeOfTypePlusIndex))
  if(pPrefixedWriteIterator_for_UInt8_AnalogOutputStatus->isValid &&
      length_in_HasLength_for_Uint16_t(&(pPrefixedWriteIterator_for_UInt8_AnalogOutputStatus->pPosition->hHasLength))
      >= pPrefixedWriteIterator_for_UInt8_AnalogOutputStatus->sizeOfTypePlusIndex)
  {
////        PrefixType::write_to(*pPosition, index);
    write_to_in_UInt8_static(pPrefixedWriteIterator_for_UInt8_AnalogOutputStatus->pPosition, index);
////        serializer.write(value, *pPosition);
    write_in_Serializer_for_AnalogOutputStatus(&(pPrefixedWriteIterator_for_UInt8_AnalogOutputStatus->serializer), value,
                                   pPrefixedWriteIterator_for_UInt8_AnalogOutputStatus->pPosition);
    ++(pPrefixedWriteIterator_for_UInt8_AnalogOutputStatus->count);
    return true;
  }
  else
  {
    return false;
  }
}

boolean IsValid_in_PrefixedWriteIterator_for_UInt8_AnalogOutputStatus(PrefixedWriteIterator_for_UInt8_AnalogOutputStatus *pPrefixedWriteIterator_for_UInt8_AnalogOutputStatus)
{
  return pPrefixedWriteIterator_for_UInt8_AnalogOutputStatus->isValid;
}
//-------------------Uint8---------------------------------------------------
//-------------------Uint16---------------------------------------------------
PrefixedWriteIterator_for_UInt16_AnalogOutputStatus Null_in_PrefixedWriteIterator_for_UInt16_AnalogOutputStatus_static(void)
{
  PrefixedWriteIterator_for_UInt16_AnalogOutputStatus pPrefixedWriteIterator_for_UInt16_AnalogOutputStatus;
////    return PrefixedWriteIterator();
  PrefixedWriteIterator_for_UInt16_AnalogOutputStatus_in_PrefixedWriteIterator_for_UInt16_AnalogOutputStatusOver1(&pPrefixedWriteIterator_for_UInt16_AnalogOutputStatus);
  return pPrefixedWriteIterator_for_UInt16_AnalogOutputStatus;
}

void PrefixedWriteIterator_for_UInt16_AnalogOutputStatus_in_PrefixedWriteIterator_for_UInt16_AnalogOutputStatusOver1(PrefixedWriteIterator_for_UInt16_AnalogOutputStatus *pPrefixedWriteIterator_for_UInt16_AnalogOutputStatus)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"PrefixedWriteIterator_for_UInt16_AnalogOutputStatus_in_PrefixedWriteIterator_for_UInt16_AnalogOutputStatusOver1_1"<<'\n';
  decrement_stack_info();
#endif
//// : sizeOfTypePlusIndex(0), count(0), isValid(false), pPosition(nullptr) {}
  pPrefixedWriteIterator_for_UInt16_AnalogOutputStatus->sizeOfTypePlusIndex = 0;
  pPrefixedWriteIterator_for_UInt16_AnalogOutputStatus->count = 0;
  pPrefixedWriteIterator_for_UInt16_AnalogOutputStatus->isValid = false;
  pPrefixedWriteIterator_for_UInt16_AnalogOutputStatus->pPosition = NULL;
}

void PrefixedWriteIterator_for_UInt16_AnalogOutputStatus_in_PrefixedWriteIterator_for_UInt16_AnalogOutputStatusOver2(PrefixedWriteIterator_for_UInt16_AnalogOutputStatus *pPrefixedWriteIterator_for_UInt16_AnalogOutputStatus,
    Serializer_for_AnalogOutputStatus* serializer, WSeq_for_Uint16_t* position)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"PrefixedWriteIterator_for_UInt16_AnalogOutputStatus_in_PrefixedWriteIterator_for_UInt16_AnalogOutputStatusOver2_1"<<'\n';
  decrement_stack_info();
#endif
  pPrefixedWriteIterator_for_UInt16_AnalogOutputStatus->serializer = *serializer;
  pPrefixedWriteIterator_for_UInt16_AnalogOutputStatus->sizeOfTypePlusIndex = get_size_in_Serializer_for_AnalogOutputStatus(serializer) +////serializer.get_size() + PrefixType::size;
      size_in_UInt16;
  pPrefixedWriteIterator_for_UInt16_AnalogOutputStatus->count = 0;
  ////isValid = position.length() >= PrefixType::size),
  pPrefixedWriteIterator_for_UInt16_AnalogOutputStatus->isValid = length_in_HasLength_for_Uint16_t(&(position->hHasLength)) >= size_in_UInt16;
  pPrefixedWriteIterator_for_UInt16_AnalogOutputStatus->countPosition = *position;
  pPrefixedWriteIterator_for_UInt16_AnalogOutputStatus->pPosition = position;

  if (pPrefixedWriteIterator_for_UInt16_AnalogOutputStatus->isValid)
  {
////        pPosition->advance(PrefixType::size);
    advance_in_WSeq_for_Uint16_t(position, size_in_UInt16);
  }
}

////    ~PrefixedWriteIterator()
void PrefixedWriteIterator_for_UInt16_AnalogOutputStatus_destr_PrefixedWriteIterator_for_UInt16_AnalogOutputStatus(PrefixedWriteIterator_for_UInt16_AnalogOutputStatus *pPrefixedWriteIterator_for_UInt16_AnalogOutputStatus)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"PrefixedWriteIterator_for_UInt16_AnalogOutputStatus_destr_PrefixedWriteIterator_for_UInt16_AnalogOutputStatus1"<<'\n';
  decrement_stack_info();
#endif
  if (pPrefixedWriteIterator_for_UInt16_AnalogOutputStatus->isValid)
  {
////        PrefixType::write_to(countPosition, count);
    write_to_in_UInt16_static(&(pPrefixedWriteIterator_for_UInt16_AnalogOutputStatus->countPosition), pPrefixedWriteIterator_for_UInt16_AnalogOutputStatus->count);
  }
}

boolean Write_in_PrefixedWriteIterator_for_UInt16_AnalogOutputStatus(PrefixedWriteIterator_for_UInt16_AnalogOutputStatus *pPrefixedWriteIterator_for_UInt16_AnalogOutputStatus,
    AnalogOutputStatus* value, uint16_t index)
{
////    if (isValid && (pPosition->length() >= sizeOfTypePlusIndex))
  if(pPrefixedWriteIterator_for_UInt16_AnalogOutputStatus->isValid &&
      length_in_HasLength_for_Uint16_t(&(pPrefixedWriteIterator_for_UInt16_AnalogOutputStatus->pPosition->hHasLength))
      >= pPrefixedWriteIterator_for_UInt16_AnalogOutputStatus->sizeOfTypePlusIndex)
  {
////        PrefixType::write_to(*pPosition, index);
    write_to_in_UInt16_static(pPrefixedWriteIterator_for_UInt16_AnalogOutputStatus->pPosition, index);
////        serializer.write(value, *pPosition);
    write_in_Serializer_for_AnalogOutputStatus(&(pPrefixedWriteIterator_for_UInt16_AnalogOutputStatus->serializer), value,
                                   pPrefixedWriteIterator_for_UInt16_AnalogOutputStatus->pPosition);
    ++(pPrefixedWriteIterator_for_UInt16_AnalogOutputStatus->count);
    return true;
  }
  else
  {
    return false;
  }
}

boolean IsValid_in_PrefixedWriteIterator_for_UInt16_AnalogOutputStatus(PrefixedWriteIterator_for_UInt16_AnalogOutputStatus *pPrefixedWriteIterator_for_UInt16_AnalogOutputStatus)
{
  return pPrefixedWriteIterator_for_UInt16_AnalogOutputStatus->isValid;
}
//-------------------Uint16---------------------------------------------------
