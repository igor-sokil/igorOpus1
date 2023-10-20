#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "PrefixedWriteIterator_for_TimeAndInterval.h"
#include "SerializationTemplates.h"
#include <string.h>
//-------------------Uint16---------------------------------------------------

PrefixedWriteIterator_for_UInt16_TimeAndInterval Null_in_PrefixedWriteIterator_for_UInt16_TimeAndInterval_static(void)
{
  PrefixedWriteIterator_for_UInt16_TimeAndInterval pPrefixedWriteIterator_for_UInt16_TimeAndInterval;
////    return PrefixedWriteIterator();
  PrefixedWriteIterator_for_UInt16_TimeAndInterval_in_PrefixedWriteIterator_for_UInt16_TimeAndIntervalOver1(&pPrefixedWriteIterator_for_UInt16_TimeAndInterval);
  return pPrefixedWriteIterator_for_UInt16_TimeAndInterval;
}

void PrefixedWriteIterator_for_UInt16_TimeAndInterval_in_PrefixedWriteIterator_for_UInt16_TimeAndIntervalOver1(PrefixedWriteIterator_for_UInt16_TimeAndInterval *pPrefixedWriteIterator_for_UInt16_TimeAndInterval)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<""<<'\n';
  std::cout<<"PrefixedWriteIterator_for_UInt16_TimeAndInterval_in_PrefixedWriteIterator_for_UInt16_TimeAndIntervalOver1_1"<<'\n';
  decrement_stack_info();
#endif
//// : sizeOfTypePlusIndex(0), count(0), isValid(false), pPosition(nullptr) {}
  pPrefixedWriteIterator_for_UInt16_TimeAndInterval->sizeOfTypePlusIndex = 0;
  pPrefixedWriteIterator_for_UInt16_TimeAndInterval->count = 0;
  pPrefixedWriteIterator_for_UInt16_TimeAndInterval->isValid = false;
  pPrefixedWriteIterator_for_UInt16_TimeAndInterval->pPosition = NULL;
}

void PrefixedWriteIterator_for_UInt16_TimeAndInterval_in_PrefixedWriteIterator_for_UInt16_TimeAndIntervalOver2(PrefixedWriteIterator_for_UInt16_TimeAndInterval *pPrefixedWriteIterator_for_UInt16_TimeAndInterval,
    Serializer_for_TimeAndInterval* serializer, WSeq_for_Uint16_t* position)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<""<<'\n';
  std::cout<<"PrefixedWriteIterator_for_UInt16_TimeAndInterval_in_PrefixedWriteIterator_for_UInt16_TimeAndIntervalOver2_1"<<'\n';
  decrement_stack_info();
#endif
  pPrefixedWriteIterator_for_UInt16_TimeAndInterval->serializer = *serializer;
  pPrefixedWriteIterator_for_UInt16_TimeAndInterval->sizeOfTypePlusIndex = get_size_in_Serializer_for_TimeAndInterval(serializer) +////serializer.get_size() + PrefixType::size;
      size_in_UInt16;
  pPrefixedWriteIterator_for_UInt16_TimeAndInterval->count = 0;
  ////isValid = position.length() >= PrefixType::size),
  pPrefixedWriteIterator_for_UInt16_TimeAndInterval->isValid = length_in_HasLength_for_Uint16_t(&(position->hHasLength)) >= size_in_UInt16;
  pPrefixedWriteIterator_for_UInt16_TimeAndInterval->countPosition = *position;
  pPrefixedWriteIterator_for_UInt16_TimeAndInterval->pPosition = position;

  if (pPrefixedWriteIterator_for_UInt16_TimeAndInterval->isValid)
  {
////        pPosition->advance(PrefixType::size);
    advance_in_WSeq_for_Uint16_t(position, size_in_UInt16);
  }
}

////    ~PrefixedWriteIterator()
void PrefixedWriteIterator_for_UInt16_TimeAndInterval_destr_PrefixedWriteIterator_for_UInt16_TimeAndInterval(PrefixedWriteIterator_for_UInt16_TimeAndInterval *pPrefixedWriteIterator_for_UInt16_TimeAndInterval)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<""<<'\n';
  std::cout<<"PrefixedWriteIterator_for_UInt16_TimeAndInterval_destr_PrefixedWriteIterator_for_UInt16_TimeAndInterval1"<<'\n';
  decrement_stack_info();
#endif
  if (pPrefixedWriteIterator_for_UInt16_TimeAndInterval->isValid)
  {
////        PrefixType::write_to(countPosition, count);
    write_to_in_UInt16_static(&(pPrefixedWriteIterator_for_UInt16_TimeAndInterval->countPosition), pPrefixedWriteIterator_for_UInt16_TimeAndInterval->count);
  }
}

boolean Write_in_PrefixedWriteIterator_for_UInt16_TimeAndInterval(PrefixedWriteIterator_for_UInt16_TimeAndInterval *pPrefixedWriteIterator_for_UInt16_TimeAndInterval,
    TimeAndInterval* value, uint16_t index)
{
////    if (isValid && (pPosition->length() >= sizeOfTypePlusIndex))
  if(pPrefixedWriteIterator_for_UInt16_TimeAndInterval->isValid &&
      length_in_HasLength_for_Uint16_t(&(pPrefixedWriteIterator_for_UInt16_TimeAndInterval->pPosition->hHasLength))
      >= pPrefixedWriteIterator_for_UInt16_TimeAndInterval->sizeOfTypePlusIndex)
  {
////        PrefixType::write_to(*pPosition, index);
    write_to_in_UInt16_static(pPrefixedWriteIterator_for_UInt16_TimeAndInterval->pPosition, index);
////        serializer.write(value, *pPosition);
    write_in_Serializer_for_TimeAndInterval(&(pPrefixedWriteIterator_for_UInt16_TimeAndInterval->serializer), value,
                                   pPrefixedWriteIterator_for_UInt16_TimeAndInterval->pPosition);
    ++(pPrefixedWriteIterator_for_UInt16_TimeAndInterval->count);
    return true;
  }
  else
  {
    return false;
  }
}

boolean IsValid_in_PrefixedWriteIterator_for_UInt16_TimeAndInterval(PrefixedWriteIterator_for_UInt16_TimeAndInterval *pPrefixedWriteIterator_for_UInt16_TimeAndInterval)
{
  return pPrefixedWriteIterator_for_UInt16_TimeAndInterval->isValid;
}
//-------------------Uint16---------------------------------------------------
