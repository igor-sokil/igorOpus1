#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "PrefixedWriteIterator_for_FrozenCounter.h"
#include "SerializationTemplates.h"
#include <string.h>

//-------------------Uint8---------------------------------------------------
PrefixedWriteIterator_for_UInt8_FrozenCounter Null_in_PrefixedWriteIterator_for_UInt8_FrozenCounter_static(void)
{
  PrefixedWriteIterator_for_UInt8_FrozenCounter pPrefixedWriteIterator_for_UInt8_FrozenCounter;
////    return PrefixedWriteIterator();
  PrefixedWriteIterator_for_UInt8_FrozenCounter_in_PrefixedWriteIterator_for_UInt8_FrozenCounterOver1(&pPrefixedWriteIterator_for_UInt8_FrozenCounter);
  return pPrefixedWriteIterator_for_UInt8_FrozenCounter;
}

void PrefixedWriteIterator_for_UInt8_FrozenCounter_in_PrefixedWriteIterator_for_UInt8_FrozenCounterOver1(PrefixedWriteIterator_for_UInt8_FrozenCounter *pPrefixedWriteIterator_for_UInt8_FrozenCounter)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<""<<'\n';
  std::cout<<"PrefixedWriteIterator_for_UInt8_FrozenCounter_in_PrefixedWriteIterator_for_UInt8_FrozenCounterOver1_1"<<'\n';
  decrement_stack_info();
#endif
//// : sizeOfTypePlusIndex(0), count(0), isValid(false), pPosition(nullptr) {}
  pPrefixedWriteIterator_for_UInt8_FrozenCounter->sizeOfTypePlusIndex = 0;
  pPrefixedWriteIterator_for_UInt8_FrozenCounter->count = 0;
  pPrefixedWriteIterator_for_UInt8_FrozenCounter->isValid = false;
  pPrefixedWriteIterator_for_UInt8_FrozenCounter->pPosition = NULL;
}

void PrefixedWriteIterator_for_UInt8_FrozenCounter_in_PrefixedWriteIterator_for_UInt8_FrozenCounterOver2(PrefixedWriteIterator_for_UInt8_FrozenCounter *pPrefixedWriteIterator_for_UInt8_FrozenCounter,
    Serializer_for_FrozenCounter* serializer, WSeq_for_Uint16_t* position)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<""<<'\n';
  std::cout<<"PrefixedWriteIterator_for_UInt8_FrozenCounter_in_PrefixedWriteIterator_for_UInt8_FrozenCounterOver2_1"<<'\n';
  decrement_stack_info();
#endif
  pPrefixedWriteIterator_for_UInt8_FrozenCounter->serializer = *serializer;
  pPrefixedWriteIterator_for_UInt8_FrozenCounter->sizeOfTypePlusIndex = get_size_in_Serializer_for_FrozenCounter(serializer) +////serializer.get_size() + PrefixType::size;
      size_in_UInt8;
  pPrefixedWriteIterator_for_UInt8_FrozenCounter->count = 0;
  ////isValid = position.length() >= PrefixType::size),
  pPrefixedWriteIterator_for_UInt8_FrozenCounter->isValid = length_in_HasLength_for_Uint16_t(&(position->hHasLength)) >= size_in_UInt8;
  pPrefixedWriteIterator_for_UInt8_FrozenCounter->countPosition = *position;
  pPrefixedWriteIterator_for_UInt8_FrozenCounter->pPosition = position;

  if (pPrefixedWriteIterator_for_UInt8_FrozenCounter->isValid)
  {
////        pPosition->advance(PrefixType::size);
    advance_in_WSeq_for_Uint16_t(position, size_in_UInt8);
  }
}

////    ~PrefixedWriteIterator()
void PrefixedWriteIterator_for_UInt8_FrozenCounter_destr_PrefixedWriteIterator_for_UInt8_FrozenCounter(PrefixedWriteIterator_for_UInt8_FrozenCounter *pPrefixedWriteIterator_for_UInt8_FrozenCounter)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<""<<'\n';
  std::cout<<"PrefixedWriteIterator_for_UInt8_FrozenCounter_destr_PrefixedWriteIterator_for_UInt8_FrozenCounter1"<<'\n';
  decrement_stack_info();
#endif
  if (pPrefixedWriteIterator_for_UInt8_FrozenCounter->isValid)
  {
////        PrefixType::write_to(countPosition, count);
    write_to_in_UInt8_static(&(pPrefixedWriteIterator_for_UInt8_FrozenCounter->countPosition), pPrefixedWriteIterator_for_UInt8_FrozenCounter->count);
  }
}

boolean Write_in_PrefixedWriteIterator_for_UInt8_FrozenCounter(PrefixedWriteIterator_for_UInt8_FrozenCounter *pPrefixedWriteIterator_for_UInt8_FrozenCounter,
    FrozenCounter* value, uint16_t index)
{
////    if (isValid && (pPosition->length() >= sizeOfTypePlusIndex))
  if(pPrefixedWriteIterator_for_UInt8_FrozenCounter->isValid &&
      length_in_HasLength_for_Uint16_t(&(pPrefixedWriteIterator_for_UInt8_FrozenCounter->pPosition->hHasLength))
      >= pPrefixedWriteIterator_for_UInt8_FrozenCounter->sizeOfTypePlusIndex)
  {
////        PrefixType::write_to(*pPosition, index);
    write_to_in_UInt8_static(pPrefixedWriteIterator_for_UInt8_FrozenCounter->pPosition, index);
////        serializer.write(value, *pPosition);
    write_in_Serializer_for_FrozenCounter(&(pPrefixedWriteIterator_for_UInt8_FrozenCounter->serializer), value,
                                   pPrefixedWriteIterator_for_UInt8_FrozenCounter->pPosition);
    ++(pPrefixedWriteIterator_for_UInt8_FrozenCounter->count);
    return true;
  }
  else
  {
    return false;
  }
}

boolean IsValid_in_PrefixedWriteIterator_for_UInt8_FrozenCounter(PrefixedWriteIterator_for_UInt8_FrozenCounter *pPrefixedWriteIterator_for_UInt8_FrozenCounter)
{
  return pPrefixedWriteIterator_for_UInt8_FrozenCounter->isValid;
}
//-------------------Uint8---------------------------------------------------
//-------------------Uint16---------------------------------------------------
PrefixedWriteIterator_for_UInt16_FrozenCounter Null_in_PrefixedWriteIterator_for_UInt16_FrozenCounter_static(void)
{
  PrefixedWriteIterator_for_UInt16_FrozenCounter pPrefixedWriteIterator_for_UInt16_FrozenCounter;
////    return PrefixedWriteIterator();
  PrefixedWriteIterator_for_UInt16_FrozenCounter_in_PrefixedWriteIterator_for_UInt16_FrozenCounterOver1(&pPrefixedWriteIterator_for_UInt16_FrozenCounter);
  return pPrefixedWriteIterator_for_UInt16_FrozenCounter;
}

void PrefixedWriteIterator_for_UInt16_FrozenCounter_in_PrefixedWriteIterator_for_UInt16_FrozenCounterOver1(PrefixedWriteIterator_for_UInt16_FrozenCounter *pPrefixedWriteIterator_for_UInt16_FrozenCounter)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<""<<'\n';
  std::cout<<"PrefixedWriteIterator_for_UInt16_FrozenCounter_in_PrefixedWriteIterator_for_UInt16_FrozenCounterOver1_1"<<'\n';
  decrement_stack_info();
#endif
//// : sizeOfTypePlusIndex(0), count(0), isValid(false), pPosition(nullptr) {}
  pPrefixedWriteIterator_for_UInt16_FrozenCounter->sizeOfTypePlusIndex = 0;
  pPrefixedWriteIterator_for_UInt16_FrozenCounter->count = 0;
  pPrefixedWriteIterator_for_UInt16_FrozenCounter->isValid = false;
  pPrefixedWriteIterator_for_UInt16_FrozenCounter->pPosition = NULL;
}

void PrefixedWriteIterator_for_UInt16_FrozenCounter_in_PrefixedWriteIterator_for_UInt16_FrozenCounterOver2(PrefixedWriteIterator_for_UInt16_FrozenCounter *pPrefixedWriteIterator_for_UInt16_FrozenCounter,
    Serializer_for_FrozenCounter* serializer, WSeq_for_Uint16_t* position)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<""<<'\n';
  std::cout<<"PrefixedWriteIterator_for_UInt16_FrozenCounter_in_PrefixedWriteIterator_for_UInt16_FrozenCounterOver2_1"<<'\n';
  decrement_stack_info();
#endif
  pPrefixedWriteIterator_for_UInt16_FrozenCounter->serializer = *serializer;
  pPrefixedWriteIterator_for_UInt16_FrozenCounter->sizeOfTypePlusIndex = get_size_in_Serializer_for_FrozenCounter(serializer) +////serializer.get_size() + PrefixType::size;
      size_in_UInt16;
  pPrefixedWriteIterator_for_UInt16_FrozenCounter->count = 0;
  ////isValid = position.length() >= PrefixType::size),
  pPrefixedWriteIterator_for_UInt16_FrozenCounter->isValid = length_in_HasLength_for_Uint16_t(&(position->hHasLength)) >= size_in_UInt16;
  pPrefixedWriteIterator_for_UInt16_FrozenCounter->countPosition = *position;
  pPrefixedWriteIterator_for_UInt16_FrozenCounter->pPosition = position;

  if (pPrefixedWriteIterator_for_UInt16_FrozenCounter->isValid)
  {
////        pPosition->advance(PrefixType::size);
    advance_in_WSeq_for_Uint16_t(position, size_in_UInt16);
  }
}

////    ~PrefixedWriteIterator()
void PrefixedWriteIterator_for_UInt16_FrozenCounter_destr_PrefixedWriteIterator_for_UInt16_FrozenCounter(PrefixedWriteIterator_for_UInt16_FrozenCounter *pPrefixedWriteIterator_for_UInt16_FrozenCounter)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<""<<'\n';
  std::cout<<"PrefixedWriteIterator_for_UInt16_FrozenCounter_destr_PrefixedWriteIterator_for_UInt16_FrozenCounter1"<<'\n';
  decrement_stack_info();
#endif
  if (pPrefixedWriteIterator_for_UInt16_FrozenCounter->isValid)
  {
////        PrefixType::write_to(countPosition, count);
    write_to_in_UInt16_static(&(pPrefixedWriteIterator_for_UInt16_FrozenCounter->countPosition), pPrefixedWriteIterator_for_UInt16_FrozenCounter->count);
  }
}

boolean Write_in_PrefixedWriteIterator_for_UInt16_FrozenCounter(PrefixedWriteIterator_for_UInt16_FrozenCounter *pPrefixedWriteIterator_for_UInt16_FrozenCounter,
    FrozenCounter* value, uint16_t index)
{
////    if (isValid && (pPosition->length() >= sizeOfTypePlusIndex))
  if(pPrefixedWriteIterator_for_UInt16_FrozenCounter->isValid &&
      length_in_HasLength_for_Uint16_t(&(pPrefixedWriteIterator_for_UInt16_FrozenCounter->pPosition->hHasLength))
      >= pPrefixedWriteIterator_for_UInt16_FrozenCounter->sizeOfTypePlusIndex)
  {
////        PrefixType::write_to(*pPosition, index);
    write_to_in_UInt16_static(pPrefixedWriteIterator_for_UInt16_FrozenCounter->pPosition, index);
////        serializer.write(value, *pPosition);
    write_in_Serializer_for_FrozenCounter(&(pPrefixedWriteIterator_for_UInt16_FrozenCounter->serializer), value,
                                   pPrefixedWriteIterator_for_UInt16_FrozenCounter->pPosition);
    ++(pPrefixedWriteIterator_for_UInt16_FrozenCounter->count);
    return true;
  }
  else
  {
    return false;
  }
}

boolean IsValid_in_PrefixedWriteIterator_for_UInt16_FrozenCounter(PrefixedWriteIterator_for_UInt16_FrozenCounter *pPrefixedWriteIterator_for_UInt16_FrozenCounter)
{
  return pPrefixedWriteIterator_for_UInt16_FrozenCounter->isValid;
}
//-------------------Uint16---------------------------------------------------
