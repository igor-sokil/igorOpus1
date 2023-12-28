#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "PrefixedWriteIterator_for_AnalogOutputInt16.h"
#include "SerializationTemplates.h"
#include <string.h>

//-------------------Uint8---------------------------------------------------
PrefixedWriteIterator_for_UInt8_AnalogOutputInt16 Null_in_PrefixedWriteIterator_for_UInt8_AnalogOutputInt16_static(void)
{
  PrefixedWriteIterator_for_UInt8_AnalogOutputInt16 pPrefixedWriteIterator_for_UInt8_AnalogOutputInt16;
////    return PrefixedWriteIterator();
  PrefixedWriteIterator_for_UInt8_AnalogOutputInt16_in_PrefixedWriteIterator_for_UInt8_AnalogOutputInt16Over1(&pPrefixedWriteIterator_for_UInt8_AnalogOutputInt16);
  return pPrefixedWriteIterator_for_UInt8_AnalogOutputInt16;
}

void PrefixedWriteIterator_for_UInt8_AnalogOutputInt16_in_PrefixedWriteIterator_for_UInt8_AnalogOutputInt16Over1(PrefixedWriteIterator_for_UInt8_AnalogOutputInt16 *pPrefixedWriteIterator_for_UInt8_AnalogOutputInt16)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"PrefixedWriteIterator_for_UInt8_AnalogOutputInt16_in_PrefixedWriteIterator_for_UInt8_AnalogOutputInt16Over1_1"<<'\n';
  decrement_stack_info();
#endif
//// : sizeOfTypePlusIndex(0), count(0), isValid(false), pPosition(nullptr) {}
  pPrefixedWriteIterator_for_UInt8_AnalogOutputInt16->sizeOfTypePlusIndex = 0;
  pPrefixedWriteIterator_for_UInt8_AnalogOutputInt16->count = 0;
  pPrefixedWriteIterator_for_UInt8_AnalogOutputInt16->isValid = false;
  pPrefixedWriteIterator_for_UInt8_AnalogOutputInt16->pPosition = NULL;
}

void PrefixedWriteIterator_for_UInt8_AnalogOutputInt16_in_PrefixedWriteIterator_for_UInt8_AnalogOutputInt16Over2(PrefixedWriteIterator_for_UInt8_AnalogOutputInt16 *pPrefixedWriteIterator_for_UInt8_AnalogOutputInt16,
    Serializer_for_AnalogOutputInt16* serializer, WSeq_for_Uint16_t* position)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"PrefixedWriteIterator_for_UInt8_AnalogOutputInt16_in_PrefixedWriteIterator_for_UInt8_AnalogOutputInt16Over2_1"<<'\n';
  decrement_stack_info();
#endif
  pPrefixedWriteIterator_for_UInt8_AnalogOutputInt16->serializer = *serializer;
  pPrefixedWriteIterator_for_UInt8_AnalogOutputInt16->sizeOfTypePlusIndex = get_size_in_Serializer_for_AnalogOutputInt16(serializer) +////serializer.get_size() + PrefixType::size;
      size_in_UInt8;
  pPrefixedWriteIterator_for_UInt8_AnalogOutputInt16->count = 0;
  ////isValid = position.length() >= PrefixType::size),
  pPrefixedWriteIterator_for_UInt8_AnalogOutputInt16->isValid = length_in_HasLength_for_Uint16_t(&(position->hHasLength)) >= size_in_UInt8;
  pPrefixedWriteIterator_for_UInt8_AnalogOutputInt16->countPosition = *position;
  pPrefixedWriteIterator_for_UInt8_AnalogOutputInt16->pPosition = position;

  if (pPrefixedWriteIterator_for_UInt8_AnalogOutputInt16->isValid)
  {
////        pPosition->advance(PrefixType::size);
    advance_in_WSeq_for_Uint16_t(position, size_in_UInt8);
  }
}

////    ~PrefixedWriteIterator()
void PrefixedWriteIterator_for_UInt8_AnalogOutputInt16_destr_PrefixedWriteIterator_for_UInt8_AnalogOutputInt16(PrefixedWriteIterator_for_UInt8_AnalogOutputInt16 *pPrefixedWriteIterator_for_UInt8_AnalogOutputInt16)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"PrefixedWriteIterator_for_UInt8_AnalogOutputInt16_destr_PrefixedWriteIterator_for_UInt8_AnalogOutputInt161"<<'\n';
  decrement_stack_info();
#endif
  if (pPrefixedWriteIterator_for_UInt8_AnalogOutputInt16->isValid)
  {
////        PrefixType::write_to(countPosition, count);
    write_to_in_UInt8_static(&(pPrefixedWriteIterator_for_UInt8_AnalogOutputInt16->countPosition), pPrefixedWriteIterator_for_UInt8_AnalogOutputInt16->count);
  }
}

boolean Write_in_PrefixedWriteIterator_for_UInt8_AnalogOutputInt16(PrefixedWriteIterator_for_UInt8_AnalogOutputInt16 *pPrefixedWriteIterator_for_UInt8_AnalogOutputInt16,
    AnalogOutputInt16* value, uint16_t index)
{
////    if (isValid && (pPosition->length() >= sizeOfTypePlusIndex))
  if(pPrefixedWriteIterator_for_UInt8_AnalogOutputInt16->isValid &&
      length_in_HasLength_for_Uint16_t(&(pPrefixedWriteIterator_for_UInt8_AnalogOutputInt16->pPosition->hHasLength))
      >= pPrefixedWriteIterator_for_UInt8_AnalogOutputInt16->sizeOfTypePlusIndex)
  {
////        PrefixType::write_to(*pPosition, index);
    write_to_in_UInt8_static(pPrefixedWriteIterator_for_UInt8_AnalogOutputInt16->pPosition, index);
////        serializer.write(value, *pPosition);
    write_in_Serializer_for_AnalogOutputInt16(&(pPrefixedWriteIterator_for_UInt8_AnalogOutputInt16->serializer), value,
                                   pPrefixedWriteIterator_for_UInt8_AnalogOutputInt16->pPosition);
    ++(pPrefixedWriteIterator_for_UInt8_AnalogOutputInt16->count);
    return true;
  }
  else
  {
    return false;
  }
}

boolean IsValid_in_PrefixedWriteIterator_for_UInt8_AnalogOutputInt16(PrefixedWriteIterator_for_UInt8_AnalogOutputInt16 *pPrefixedWriteIterator_for_UInt8_AnalogOutputInt16)
{
  return pPrefixedWriteIterator_for_UInt8_AnalogOutputInt16->isValid;
}
//-------------------Uint8---------------------------------------------------
//-------------------Uint16---------------------------------------------------
PrefixedWriteIterator_for_UInt16_AnalogOutputInt16 Null_in_PrefixedWriteIterator_for_UInt16_AnalogOutputInt16_static(void)
{
  PrefixedWriteIterator_for_UInt16_AnalogOutputInt16 pPrefixedWriteIterator_for_UInt16_AnalogOutputInt16;
////    return PrefixedWriteIterator();
  PrefixedWriteIterator_for_UInt16_AnalogOutputInt16_in_PrefixedWriteIterator_for_UInt16_AnalogOutputInt16Over1(&pPrefixedWriteIterator_for_UInt16_AnalogOutputInt16);
  return pPrefixedWriteIterator_for_UInt16_AnalogOutputInt16;
}

void PrefixedWriteIterator_for_UInt16_AnalogOutputInt16_in_PrefixedWriteIterator_for_UInt16_AnalogOutputInt16Over1(PrefixedWriteIterator_for_UInt16_AnalogOutputInt16 *pPrefixedWriteIterator_for_UInt16_AnalogOutputInt16)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"PrefixedWriteIterator_for_UInt16_AnalogOutputInt16_in_PrefixedWriteIterator_for_UInt16_AnalogOutputInt16Over1_1"<<'\n';
  decrement_stack_info();
#endif
//// : sizeOfTypePlusIndex(0), count(0), isValid(false), pPosition(nullptr) {}
  pPrefixedWriteIterator_for_UInt16_AnalogOutputInt16->sizeOfTypePlusIndex = 0;
  pPrefixedWriteIterator_for_UInt16_AnalogOutputInt16->count = 0;
  pPrefixedWriteIterator_for_UInt16_AnalogOutputInt16->isValid = false;
  pPrefixedWriteIterator_for_UInt16_AnalogOutputInt16->pPosition = NULL;
}

void PrefixedWriteIterator_for_UInt16_AnalogOutputInt16_in_PrefixedWriteIterator_for_UInt16_AnalogOutputInt16Over2(PrefixedWriteIterator_for_UInt16_AnalogOutputInt16 *pPrefixedWriteIterator_for_UInt16_AnalogOutputInt16,
    Serializer_for_AnalogOutputInt16* serializer, WSeq_for_Uint16_t* position)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"{PrefixedWriteIterator_for_UInt16_AnalogOutputInt16_in_PrefixedWriteIterator_for_UInt16_AnalogOutputInt16Over2_1"<<'\n';
#endif
  pPrefixedWriteIterator_for_UInt16_AnalogOutputInt16->serializer = *serializer;
  pPrefixedWriteIterator_for_UInt16_AnalogOutputInt16->sizeOfTypePlusIndex = get_size_in_Serializer_for_AnalogOutputInt16(serializer) +////serializer.get_size() + PrefixType::size;
      size_in_UInt16;
  pPrefixedWriteIterator_for_UInt16_AnalogOutputInt16->count = 0;
  ////isValid = position.length() >= PrefixType::size),
  pPrefixedWriteIterator_for_UInt16_AnalogOutputInt16->isValid = length_in_HasLength_for_Uint16_t(&(position->hHasLength)) >= size_in_UInt16;
  pPrefixedWriteIterator_for_UInt16_AnalogOutputInt16->countPosition = *position;
  pPrefixedWriteIterator_for_UInt16_AnalogOutputInt16->pPosition = position;

  if (pPrefixedWriteIterator_for_UInt16_AnalogOutputInt16->isValid)
  {
////        pPosition->advance(PrefixType::size);
    advance_in_WSeq_for_Uint16_t(position, size_in_UInt16);
  }
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}PrefixedWriteIterator_for_UInt16_AnalogOutputInt16_in_PrefixedWriteIterator_for_UInt16_AnalogOutputInt16Over2__"<<'\n';
  decrement_stack_info();
#endif
}

////    ~PrefixedWriteIterator()
void PrefixedWriteIterator_for_UInt16_AnalogOutputInt16_destr_PrefixedWriteIterator_for_UInt16_AnalogOutputInt16(PrefixedWriteIterator_for_UInt16_AnalogOutputInt16 *pPrefixedWriteIterator_for_UInt16_AnalogOutputInt16)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"PrefixedWriteIterator_for_UInt16_AnalogOutputInt16_destr_PrefixedWriteIterator_for_UInt16_AnalogOutputInt161"<<'\n';
  decrement_stack_info();
#endif
  if (pPrefixedWriteIterator_for_UInt16_AnalogOutputInt16->isValid)
  {
////        PrefixType::write_to(countPosition, count);
    write_to_in_UInt16_static(&(pPrefixedWriteIterator_for_UInt16_AnalogOutputInt16->countPosition), pPrefixedWriteIterator_for_UInt16_AnalogOutputInt16->count);
  }
}

boolean Write_in_PrefixedWriteIterator_for_UInt16_AnalogOutputInt16(PrefixedWriteIterator_for_UInt16_AnalogOutputInt16 *pPrefixedWriteIterator_for_UInt16_AnalogOutputInt16,
    AnalogOutputInt16* value, uint16_t index)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"{Write_in_PrefixedWriteIterator_for_UInt16_AnalogOutputInt16_1"<<'\n';
#endif
////    if (isValid && (pPosition->length() >= sizeOfTypePlusIndex))
  if(pPrefixedWriteIterator_for_UInt16_AnalogOutputInt16->isValid &&
      length_in_HasLength_for_Uint16_t(&(pPrefixedWriteIterator_for_UInt16_AnalogOutputInt16->pPosition->hHasLength))
      >= pPrefixedWriteIterator_for_UInt16_AnalogOutputInt16->sizeOfTypePlusIndex)
  {
////        PrefixType::write_to(*pPosition, index);
    write_to_in_UInt16_static(pPrefixedWriteIterator_for_UInt16_AnalogOutputInt16->pPosition, index);
////        serializer.write(value, *pPosition);
    write_in_Serializer_for_AnalogOutputInt16(&(pPrefixedWriteIterator_for_UInt16_AnalogOutputInt16->serializer), value,
                                   pPrefixedWriteIterator_for_UInt16_AnalogOutputInt16->pPosition);
    ++(pPrefixedWriteIterator_for_UInt16_AnalogOutputInt16->count);

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}Write_in_PrefixedWriteIterator_for_UInt16_AnalogOutputInt16_1_"<<'\n';
  decrement_stack_info();
#endif
    return true;
  }
  else
  {
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}Write_in_PrefixedWriteIterator_for_UInt16_AnalogOutputInt16_2_"<<'\n';
  decrement_stack_info();
#endif
    return false;
  }
}

boolean IsValid_in_PrefixedWriteIterator_for_UInt16_AnalogOutputInt16(PrefixedWriteIterator_for_UInt16_AnalogOutputInt16 *pPrefixedWriteIterator_for_UInt16_AnalogOutputInt16)
{
  return pPrefixedWriteIterator_for_UInt16_AnalogOutputInt16->isValid;
}
//-------------------Uint16---------------------------------------------------
