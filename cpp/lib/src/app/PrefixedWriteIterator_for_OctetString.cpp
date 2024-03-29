#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "PrefixedWriteIterator_for_OctetString.h"
#include "SerializationTemplates.h"
#include <string.h>

//-------------------Uint8---------------------------------------------------
PrefixedWriteIterator_for_UInt8_OctetString Null_in_PrefixedWriteIterator_for_UInt8_OctetString_static(void)
{
  PrefixedWriteIterator_for_UInt8_OctetString pPrefixedWriteIterator_for_UInt8_OctetString;
////    return PrefixedWriteIterator();
  PrefixedWriteIterator_for_UInt8_OctetString_in_PrefixedWriteIterator_for_UInt8_OctetStringOver1(&pPrefixedWriteIterator_for_UInt8_OctetString);
  return pPrefixedWriteIterator_for_UInt8_OctetString;
}

void PrefixedWriteIterator_for_UInt8_OctetString_in_PrefixedWriteIterator_for_UInt8_OctetStringOver1(PrefixedWriteIterator_for_UInt8_OctetString *pPrefixedWriteIterator_for_UInt8_OctetString)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"PrefixedWriteIterator_for_UInt8_OctetString_in_PrefixedWriteIterator_for_UInt8_OctetStringOver1_1"<<'\n';
  decrement_stack_info();
#endif
//// : sizeOfTypePlusIndex(0), count(0), isValid(false), pPosition(nullptr) {}
  pPrefixedWriteIterator_for_UInt8_OctetString->sizeOfTypePlusIndex = 0;
  pPrefixedWriteIterator_for_UInt8_OctetString->count = 0;
  pPrefixedWriteIterator_for_UInt8_OctetString->isValid = false;
  pPrefixedWriteIterator_for_UInt8_OctetString->pPosition = NULL;
}

void PrefixedWriteIterator_for_UInt8_OctetString_in_PrefixedWriteIterator_for_UInt8_OctetStringOver2(PrefixedWriteIterator_for_UInt8_OctetString *pPrefixedWriteIterator_for_UInt8_OctetString,
    Serializer_for_OctetString* serializer, WSeq_for_Uint16_t* position)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"PrefixedWriteIterator_for_UInt8_OctetString_in_PrefixedWriteIterator_for_UInt8_OctetStringOver2_1"<<'\n';
  decrement_stack_info();
#endif
  pPrefixedWriteIterator_for_UInt8_OctetString->serializer = *serializer;
  pPrefixedWriteIterator_for_UInt8_OctetString->sizeOfTypePlusIndex = get_size_in_Serializer_for_OctetString(serializer) +////serializer.get_size() + PrefixType::size;
      size_in_UInt8;
  pPrefixedWriteIterator_for_UInt8_OctetString->count = 0;
  ////isValid = position.length() >= PrefixType::size),
  pPrefixedWriteIterator_for_UInt8_OctetString->isValid = length_in_HasLength_for_Uint16_t(&(position->hHasLength)) >= size_in_UInt8;
  pPrefixedWriteIterator_for_UInt8_OctetString->countPosition = *position;
  pPrefixedWriteIterator_for_UInt8_OctetString->pPosition = position;

  if (pPrefixedWriteIterator_for_UInt8_OctetString->isValid)
  {
////        pPosition->advance(PrefixType::size);
    advance_in_WSeq_for_Uint16_t(position, size_in_UInt8);
  }
}

////    ~PrefixedWriteIterator()
void PrefixedWriteIterator_for_UInt8_OctetString_destr_PrefixedWriteIterator_for_UInt8_OctetString(PrefixedWriteIterator_for_UInt8_OctetString *pPrefixedWriteIterator_for_UInt8_OctetString)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"PrefixedWriteIterator_for_UInt8_OctetString_destr_PrefixedWriteIterator_for_UInt8_OctetString1"<<'\n';
  decrement_stack_info();
#endif
  if (pPrefixedWriteIterator_for_UInt8_OctetString->isValid)
  {
////        PrefixType::write_to(countPosition, count);
    write_to_in_UInt8_static(&(pPrefixedWriteIterator_for_UInt8_OctetString->countPosition), pPrefixedWriteIterator_for_UInt8_OctetString->count);
  }
}

boolean Write_in_PrefixedWriteIterator_for_UInt8_OctetString(PrefixedWriteIterator_for_UInt8_OctetString *pPrefixedWriteIterator_for_UInt8_OctetString,
    OctetString* value, uint16_t index)
{
////    if (isValid && (pPosition->length() >= sizeOfTypePlusIndex))
  if(pPrefixedWriteIterator_for_UInt8_OctetString->isValid &&
      length_in_HasLength_for_Uint16_t(&(pPrefixedWriteIterator_for_UInt8_OctetString->pPosition->hHasLength))
      >= pPrefixedWriteIterator_for_UInt8_OctetString->sizeOfTypePlusIndex)
  {
////        PrefixType::write_to(*pPosition, index);
    write_to_in_UInt8_static(pPrefixedWriteIterator_for_UInt8_OctetString->pPosition, index);
////        serializer.write(value, *pPosition);
    write_in_Serializer_for_OctetString(&(pPrefixedWriteIterator_for_UInt8_OctetString->serializer), value,
                                   pPrefixedWriteIterator_for_UInt8_OctetString->pPosition);
    ++(pPrefixedWriteIterator_for_UInt8_OctetString->count);
    return true;
  }
  else
  {
    return false;
  }
}

boolean IsValid_in_PrefixedWriteIterator_for_UInt8_OctetString(PrefixedWriteIterator_for_UInt8_OctetString *pPrefixedWriteIterator_for_UInt8_OctetString)
{
  return pPrefixedWriteIterator_for_UInt8_OctetString->isValid;
}
//-------------------Uint8---------------------------------------------------
//-------------------Uint16---------------------------------------------------
PrefixedWriteIterator_for_UInt16_OctetString Null_in_PrefixedWriteIterator_for_UInt16_OctetString_static(void)
{
  PrefixedWriteIterator_for_UInt16_OctetString pPrefixedWriteIterator_for_UInt16_OctetString;
////    return PrefixedWriteIterator();
  PrefixedWriteIterator_for_UInt16_OctetString_in_PrefixedWriteIterator_for_UInt16_OctetStringOver1(&pPrefixedWriteIterator_for_UInt16_OctetString);
  return pPrefixedWriteIterator_for_UInt16_OctetString;
}

void PrefixedWriteIterator_for_UInt16_OctetString_in_PrefixedWriteIterator_for_UInt16_OctetStringOver1(PrefixedWriteIterator_for_UInt16_OctetString *pPrefixedWriteIterator_for_UInt16_OctetString)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"PrefixedWriteIterator_for_UInt16_OctetString_in_PrefixedWriteIterator_for_UInt16_OctetStringOver1_1"<<'\n';
  decrement_stack_info();
#endif
//// : sizeOfTypePlusIndex(0), count(0), isValid(false), pPosition(nullptr) {}
  pPrefixedWriteIterator_for_UInt16_OctetString->sizeOfTypePlusIndex = 0;
  pPrefixedWriteIterator_for_UInt16_OctetString->count = 0;
  pPrefixedWriteIterator_for_UInt16_OctetString->isValid = false;
  pPrefixedWriteIterator_for_UInt16_OctetString->pPosition = NULL;
}

void PrefixedWriteIterator_for_UInt16_OctetString_in_PrefixedWriteIterator_for_UInt16_OctetStringOver2(PrefixedWriteIterator_for_UInt16_OctetString *pPrefixedWriteIterator_for_UInt16_OctetString,
    Serializer_for_OctetString* serializer, WSeq_for_Uint16_t* position)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"PrefixedWriteIterator_for_UInt16_OctetString_in_PrefixedWriteIterator_for_UInt16_OctetStringOver2_1"<<'\n';
  decrement_stack_info();
#endif
  pPrefixedWriteIterator_for_UInt16_OctetString->serializer = *serializer;
  pPrefixedWriteIterator_for_UInt16_OctetString->sizeOfTypePlusIndex = get_size_in_Serializer_for_OctetString(serializer) +////serializer.get_size() + PrefixType::size;
      size_in_UInt16;
  pPrefixedWriteIterator_for_UInt16_OctetString->count = 0;
  ////isValid = position.length() >= PrefixType::size),
  pPrefixedWriteIterator_for_UInt16_OctetString->isValid = length_in_HasLength_for_Uint16_t(&(position->hHasLength)) >= size_in_UInt16;
  pPrefixedWriteIterator_for_UInt16_OctetString->countPosition = *position;
  pPrefixedWriteIterator_for_UInt16_OctetString->pPosition = position;

  if (pPrefixedWriteIterator_for_UInt16_OctetString->isValid)
  {
////        pPosition->advance(PrefixType::size);
    advance_in_WSeq_for_Uint16_t(position, size_in_UInt16);
  }
}

////    ~PrefixedWriteIterator()
void PrefixedWriteIterator_for_UInt16_OctetString_destr_PrefixedWriteIterator_for_UInt16_OctetString(PrefixedWriteIterator_for_UInt16_OctetString *pPrefixedWriteIterator_for_UInt16_OctetString)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"PrefixedWriteIterator_for_UInt16_OctetString_destr_PrefixedWriteIterator_for_UInt16_OctetString1"<<'\n';
  decrement_stack_info();
#endif
  if (pPrefixedWriteIterator_for_UInt16_OctetString->isValid)
  {
////        PrefixType::write_to(countPosition, count);
    write_to_in_UInt16_static(&(pPrefixedWriteIterator_for_UInt16_OctetString->countPosition), pPrefixedWriteIterator_for_UInt16_OctetString->count);
  }
}

boolean Write_in_PrefixedWriteIterator_for_UInt16_OctetString(PrefixedWriteIterator_for_UInt16_OctetString *pPrefixedWriteIterator_for_UInt16_OctetString,
    OctetString* value, uint16_t index)
{
////    if (isValid && (pPosition->length() >= sizeOfTypePlusIndex))
  if(pPrefixedWriteIterator_for_UInt16_OctetString->isValid &&
      length_in_HasLength_for_Uint16_t(&(pPrefixedWriteIterator_for_UInt16_OctetString->pPosition->hHasLength))
      >= pPrefixedWriteIterator_for_UInt16_OctetString->sizeOfTypePlusIndex)
  {
////        PrefixType::write_to(*pPosition, index);
    write_to_in_UInt16_static(pPrefixedWriteIterator_for_UInt16_OctetString->pPosition, index);
////        serializer.write(value, *pPosition);
    write_in_Serializer_for_OctetString(&(pPrefixedWriteIterator_for_UInt16_OctetString->serializer), value,
                                   pPrefixedWriteIterator_for_UInt16_OctetString->pPosition);
    ++(pPrefixedWriteIterator_for_UInt16_OctetString->count);
    return true;
  }
  else
  {
    return false;
  }
}

boolean IsValid_in_PrefixedWriteIterator_for_UInt16_OctetString(PrefixedWriteIterator_for_UInt16_OctetString *pPrefixedWriteIterator_for_UInt16_OctetString)
{
  return pPrefixedWriteIterator_for_UInt16_OctetString->isValid;
}
//-------------------Uint16---------------------------------------------------
