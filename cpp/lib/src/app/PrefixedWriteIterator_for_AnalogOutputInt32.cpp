#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "PrefixedWriteIterator_for_AnalogOutputInt32.h"
#include "SerializationTemplates.h"
#include <string.h>

//-------------------Uint8---------------------------------------------------
PrefixedWriteIterator_for_UInt8_AnalogOutputInt32 Null_in_PrefixedWriteIterator_for_UInt8_AnalogOutputInt32_static(void)
{
  PrefixedWriteIterator_for_UInt8_AnalogOutputInt32 pPrefixedWriteIterator_for_UInt8_AnalogOutputInt32;
////    return PrefixedWriteIterator();
  PrefixedWriteIterator_for_UInt8_AnalogOutputInt32_in_PrefixedWriteIterator_for_UInt8_AnalogOutputInt32Over1(&pPrefixedWriteIterator_for_UInt8_AnalogOutputInt32);
  return pPrefixedWriteIterator_for_UInt8_AnalogOutputInt32;
}

void PrefixedWriteIterator_for_UInt8_AnalogOutputInt32_in_PrefixedWriteIterator_for_UInt8_AnalogOutputInt32Over1(PrefixedWriteIterator_for_UInt8_AnalogOutputInt32 *pPrefixedWriteIterator_for_UInt8_AnalogOutputInt32)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"PrefixedWriteIterator_for_UInt8_AnalogOutputInt32_in_PrefixedWriteIterator_for_UInt8_AnalogOutputInt32Over1_1"<<'\n';
  decrement_stack_info();
#endif
//// : sizeOfTypePlusIndex(0), count(0), isValid(false), pPosition(nullptr) {}
  pPrefixedWriteIterator_for_UInt8_AnalogOutputInt32->sizeOfTypePlusIndex = 0;
  pPrefixedWriteIterator_for_UInt8_AnalogOutputInt32->count = 0;
  pPrefixedWriteIterator_for_UInt8_AnalogOutputInt32->isValid = false;
  pPrefixedWriteIterator_for_UInt8_AnalogOutputInt32->pPosition = NULL;
}

void PrefixedWriteIterator_for_UInt8_AnalogOutputInt32_in_PrefixedWriteIterator_for_UInt8_AnalogOutputInt32Over2(PrefixedWriteIterator_for_UInt8_AnalogOutputInt32 *pPrefixedWriteIterator_for_UInt8_AnalogOutputInt32,
    Serializer_for_AnalogOutputInt32* serializer, WSeq_for_Uint16_t* position)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"PrefixedWriteIterator_for_UInt8_AnalogOutputInt32_in_PrefixedWriteIterator_for_UInt8_AnalogOutputInt32Over2_1"<<'\n';
  decrement_stack_info();
#endif
  pPrefixedWriteIterator_for_UInt8_AnalogOutputInt32->serializer = *serializer;
  pPrefixedWriteIterator_for_UInt8_AnalogOutputInt32->sizeOfTypePlusIndex = get_size_in_Serializer_for_AnalogOutputInt32(serializer) +////serializer.get_size() + PrefixType::size;
      size_in_UInt8;
  pPrefixedWriteIterator_for_UInt8_AnalogOutputInt32->count = 0;
  ////isValid = position.length() >= PrefixType::size),
  pPrefixedWriteIterator_for_UInt8_AnalogOutputInt32->isValid = length_in_HasLength_for_Uint16_t(&(position->hHasLength)) >= size_in_UInt8;
  pPrefixedWriteIterator_for_UInt8_AnalogOutputInt32->countPosition = *position;
  pPrefixedWriteIterator_for_UInt8_AnalogOutputInt32->pPosition = position;

  if (pPrefixedWriteIterator_for_UInt8_AnalogOutputInt32->isValid)
  {
////        pPosition->advance(PrefixType::size);
    advance_in_WSeq_for_Uint16_t(position, size_in_UInt8);
  }
}

////    ~PrefixedWriteIterator()
void PrefixedWriteIterator_for_UInt8_AnalogOutputInt32_destr_PrefixedWriteIterator_for_UInt8_AnalogOutputInt32(PrefixedWriteIterator_for_UInt8_AnalogOutputInt32 *pPrefixedWriteIterator_for_UInt8_AnalogOutputInt32)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"PrefixedWriteIterator_for_UInt8_AnalogOutputInt32_destr_PrefixedWriteIterator_for_UInt8_AnalogOutputInt321"<<'\n';
  decrement_stack_info();
#endif
  if (pPrefixedWriteIterator_for_UInt8_AnalogOutputInt32->isValid)
  {
////        PrefixType::write_to(countPosition, count);
    write_to_in_UInt8_static(&(pPrefixedWriteIterator_for_UInt8_AnalogOutputInt32->countPosition), pPrefixedWriteIterator_for_UInt8_AnalogOutputInt32->count);
  }
}

boolean Write_in_PrefixedWriteIterator_for_UInt8_AnalogOutputInt32(PrefixedWriteIterator_for_UInt8_AnalogOutputInt32 *pPrefixedWriteIterator_for_UInt8_AnalogOutputInt32,
    AnalogOutputInt32* value, uint16_t index)
{
////    if (isValid && (pPosition->length() >= sizeOfTypePlusIndex))
  if(pPrefixedWriteIterator_for_UInt8_AnalogOutputInt32->isValid &&
      length_in_HasLength_for_Uint16_t(&(pPrefixedWriteIterator_for_UInt8_AnalogOutputInt32->pPosition->hHasLength))
      >= pPrefixedWriteIterator_for_UInt8_AnalogOutputInt32->sizeOfTypePlusIndex)
  {
////        PrefixType::write_to(*pPosition, index);
    write_to_in_UInt8_static(pPrefixedWriteIterator_for_UInt8_AnalogOutputInt32->pPosition, index);
////        serializer.write(value, *pPosition);
    write_in_Serializer_for_AnalogOutputInt32(&(pPrefixedWriteIterator_for_UInt8_AnalogOutputInt32->serializer), value,
                                   pPrefixedWriteIterator_for_UInt8_AnalogOutputInt32->pPosition);
    ++(pPrefixedWriteIterator_for_UInt8_AnalogOutputInt32->count);
    return true;
  }
  else
  {
    return false;
  }
}

boolean IsValid_in_PrefixedWriteIterator_for_UInt8_AnalogOutputInt32(PrefixedWriteIterator_for_UInt8_AnalogOutputInt32 *pPrefixedWriteIterator_for_UInt8_AnalogOutputInt32)
{
  return pPrefixedWriteIterator_for_UInt8_AnalogOutputInt32->isValid;
}
//-------------------Uint8---------------------------------------------------
//-------------------Uint16---------------------------------------------------
PrefixedWriteIterator_for_UInt16_AnalogOutputInt32 Null_in_PrefixedWriteIterator_for_UInt16_AnalogOutputInt32_static(void)
{
  PrefixedWriteIterator_for_UInt16_AnalogOutputInt32 pPrefixedWriteIterator_for_UInt16_AnalogOutputInt32;
////    return PrefixedWriteIterator();
  PrefixedWriteIterator_for_UInt16_AnalogOutputInt32_in_PrefixedWriteIterator_for_UInt16_AnalogOutputInt32Over1(&pPrefixedWriteIterator_for_UInt16_AnalogOutputInt32);
  return pPrefixedWriteIterator_for_UInt16_AnalogOutputInt32;
}

void PrefixedWriteIterator_for_UInt16_AnalogOutputInt32_in_PrefixedWriteIterator_for_UInt16_AnalogOutputInt32Over1(PrefixedWriteIterator_for_UInt16_AnalogOutputInt32 *pPrefixedWriteIterator_for_UInt16_AnalogOutputInt32)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"PrefixedWriteIterator_for_UInt16_AnalogOutputInt32_in_PrefixedWriteIterator_for_UInt16_AnalogOutputInt32Over1_1"<<'\n';
  decrement_stack_info();
#endif
//// : sizeOfTypePlusIndex(0), count(0), isValid(false), pPosition(nullptr) {}
  pPrefixedWriteIterator_for_UInt16_AnalogOutputInt32->sizeOfTypePlusIndex = 0;
  pPrefixedWriteIterator_for_UInt16_AnalogOutputInt32->count = 0;
  pPrefixedWriteIterator_for_UInt16_AnalogOutputInt32->isValid = false;
  pPrefixedWriteIterator_for_UInt16_AnalogOutputInt32->pPosition = NULL;
}

void PrefixedWriteIterator_for_UInt16_AnalogOutputInt32_in_PrefixedWriteIterator_for_UInt16_AnalogOutputInt32Over2(PrefixedWriteIterator_for_UInt16_AnalogOutputInt32 *pPrefixedWriteIterator_for_UInt16_AnalogOutputInt32,
    Serializer_for_AnalogOutputInt32* serializer, WSeq_for_Uint16_t* position)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"PrefixedWriteIterator_for_UInt16_AnalogOutputInt32_in_PrefixedWriteIterator_for_UInt16_AnalogOutputInt32Over2_1"<<'\n';
  decrement_stack_info();
#endif
  pPrefixedWriteIterator_for_UInt16_AnalogOutputInt32->serializer = *serializer;
  pPrefixedWriteIterator_for_UInt16_AnalogOutputInt32->sizeOfTypePlusIndex = get_size_in_Serializer_for_AnalogOutputInt32(serializer) +////serializer.get_size() + PrefixType::size;
      size_in_UInt16;
  pPrefixedWriteIterator_for_UInt16_AnalogOutputInt32->count = 0;
  ////isValid = position.length() >= PrefixType::size),
  pPrefixedWriteIterator_for_UInt16_AnalogOutputInt32->isValid = length_in_HasLength_for_Uint16_t(&(position->hHasLength)) >= size_in_UInt16;
  pPrefixedWriteIterator_for_UInt16_AnalogOutputInt32->countPosition = *position;
  pPrefixedWriteIterator_for_UInt16_AnalogOutputInt32->pPosition = position;

  if (pPrefixedWriteIterator_for_UInt16_AnalogOutputInt32->isValid)
  {
////        pPosition->advance(PrefixType::size);
    advance_in_WSeq_for_Uint16_t(position, size_in_UInt16);
  }
}

////    ~PrefixedWriteIterator()
void PrefixedWriteIterator_for_UInt16_AnalogOutputInt32_destr_PrefixedWriteIterator_for_UInt16_AnalogOutputInt32(PrefixedWriteIterator_for_UInt16_AnalogOutputInt32 *pPrefixedWriteIterator_for_UInt16_AnalogOutputInt32)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"PrefixedWriteIterator_for_UInt16_AnalogOutputInt32_destr_PrefixedWriteIterator_for_UInt16_AnalogOutputInt321"<<'\n';
  decrement_stack_info();
#endif
  if (pPrefixedWriteIterator_for_UInt16_AnalogOutputInt32->isValid)
  {
////        PrefixType::write_to(countPosition, count);
    write_to_in_UInt16_static(&(pPrefixedWriteIterator_for_UInt16_AnalogOutputInt32->countPosition), pPrefixedWriteIterator_for_UInt16_AnalogOutputInt32->count);
  }
}

boolean Write_in_PrefixedWriteIterator_for_UInt16_AnalogOutputInt32(PrefixedWriteIterator_for_UInt16_AnalogOutputInt32 *pPrefixedWriteIterator_for_UInt16_AnalogOutputInt32,
    AnalogOutputInt32* value, uint16_t index)
{
////    if (isValid && (pPosition->length() >= sizeOfTypePlusIndex))
  if(pPrefixedWriteIterator_for_UInt16_AnalogOutputInt32->isValid &&
      length_in_HasLength_for_Uint16_t(&(pPrefixedWriteIterator_for_UInt16_AnalogOutputInt32->pPosition->hHasLength))
      >= pPrefixedWriteIterator_for_UInt16_AnalogOutputInt32->sizeOfTypePlusIndex)
  {
////        PrefixType::write_to(*pPosition, index);
    write_to_in_UInt16_static(pPrefixedWriteIterator_for_UInt16_AnalogOutputInt32->pPosition, index);
////        serializer.write(value, *pPosition);
    write_in_Serializer_for_AnalogOutputInt32(&(pPrefixedWriteIterator_for_UInt16_AnalogOutputInt32->serializer), value,
                                   pPrefixedWriteIterator_for_UInt16_AnalogOutputInt32->pPosition);
    ++(pPrefixedWriteIterator_for_UInt16_AnalogOutputInt32->count);
    return true;
  }
  else
  {
    return false;
  }
}

boolean IsValid_in_PrefixedWriteIterator_for_UInt16_AnalogOutputInt32(PrefixedWriteIterator_for_UInt16_AnalogOutputInt32 *pPrefixedWriteIterator_for_UInt16_AnalogOutputInt32)
{
  return pPrefixedWriteIterator_for_UInt16_AnalogOutputInt32->isValid;
}
//-------------------Uint16---------------------------------------------------
