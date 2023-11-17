#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "PrefixedWriteIterator_for_Analog.h"
#include "SerializationTemplates.h"
#include <string.h>

//-------------------Uint8---------------------------------------------------
PrefixedWriteIterator_for_UInt8_Analog Null_in_PrefixedWriteIterator_for_UInt8_Analog_static(void)
{
  PrefixedWriteIterator_for_UInt8_Analog pPrefixedWriteIterator_for_UInt8_Analog;
////    return PrefixedWriteIterator();
  PrefixedWriteIterator_for_UInt8_Analog_in_PrefixedWriteIterator_for_UInt8_AnalogOver1(&pPrefixedWriteIterator_for_UInt8_Analog);
  return pPrefixedWriteIterator_for_UInt8_Analog;
}

void PrefixedWriteIterator_for_UInt8_Analog_in_PrefixedWriteIterator_for_UInt8_AnalogOver1(PrefixedWriteIterator_for_UInt8_Analog *pPrefixedWriteIterator_for_UInt8_Analog)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"PrefixedWriteIterator_for_UInt8_Analog_in_PrefixedWriteIterator_for_UInt8_AnalogOver1_1"<<'\n';
  decrement_stack_info();
#endif
//// : sizeOfTypePlusIndex(0), count(0), isValid(false), pPosition(nullptr) {}
  pPrefixedWriteIterator_for_UInt8_Analog->sizeOfTypePlusIndex = 0;
  pPrefixedWriteIterator_for_UInt8_Analog->count = 0;
  pPrefixedWriteIterator_for_UInt8_Analog->isValid = false;
  pPrefixedWriteIterator_for_UInt8_Analog->pPosition = NULL;
}

void PrefixedWriteIterator_for_UInt8_Analog_in_PrefixedWriteIterator_for_UInt8_AnalogOver2(PrefixedWriteIterator_for_UInt8_Analog *pPrefixedWriteIterator_for_UInt8_Analog,
    Serializer_for_Analog* serializer, WSeq_for_Uint16_t* position)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"PrefixedWriteIterator_for_UInt8_Analog_in_PrefixedWriteIterator_for_UInt8_AnalogOver2_1"<<'\n';
  decrement_stack_info();
#endif
  pPrefixedWriteIterator_for_UInt8_Analog->serializer = *serializer;
  pPrefixedWriteIterator_for_UInt8_Analog->sizeOfTypePlusIndex = get_size_in_Serializer_for_Analog(serializer) +////serializer.get_size() + PrefixType::size;
      size_in_UInt8;
  pPrefixedWriteIterator_for_UInt8_Analog->count = 0;
  ////isValid = position.length() >= PrefixType::size),
  pPrefixedWriteIterator_for_UInt8_Analog->isValid = length_in_HasLength_for_Uint16_t(&(position->hHasLength)) >= size_in_UInt8;
  pPrefixedWriteIterator_for_UInt8_Analog->countPosition = *position;
  pPrefixedWriteIterator_for_UInt8_Analog->pPosition = position;

  if (pPrefixedWriteIterator_for_UInt8_Analog->isValid)
  {
////        pPosition->advance(PrefixType::size);
    advance_in_WSeq_for_Uint16_t(position, size_in_UInt8);
  }
}

////    ~PrefixedWriteIterator()
void PrefixedWriteIterator_for_UInt8_Analog_destr_PrefixedWriteIterator_for_UInt8_Analog(PrefixedWriteIterator_for_UInt8_Analog *pPrefixedWriteIterator_for_UInt8_Analog)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"PrefixedWriteIterator_for_UInt8_Analog_destr_PrefixedWriteIterator_for_UInt8_Analog1"<<'\n';
  decrement_stack_info();
#endif
  if (pPrefixedWriteIterator_for_UInt8_Analog->isValid)
  {
////        PrefixType::write_to(countPosition, count);
    write_to_in_UInt8_static(&(pPrefixedWriteIterator_for_UInt8_Analog->countPosition), pPrefixedWriteIterator_for_UInt8_Analog->count);
  }
}

boolean Write_in_PrefixedWriteIterator_for_UInt8_Analog(PrefixedWriteIterator_for_UInt8_Analog *pPrefixedWriteIterator_for_UInt8_Analog,
    Analog* value, uint16_t index)
{
////    if (isValid && (pPosition->length() >= sizeOfTypePlusIndex))
  if(pPrefixedWriteIterator_for_UInt8_Analog->isValid &&
      length_in_HasLength_for_Uint16_t(&(pPrefixedWriteIterator_for_UInt8_Analog->pPosition->hHasLength))
      >= pPrefixedWriteIterator_for_UInt8_Analog->sizeOfTypePlusIndex)
  {
////        PrefixType::write_to(*pPosition, index);
    write_to_in_UInt8_static(pPrefixedWriteIterator_for_UInt8_Analog->pPosition, index);
////        serializer.write(value, *pPosition);
    write_in_Serializer_for_Analog(&(pPrefixedWriteIterator_for_UInt8_Analog->serializer), value,
                                   pPrefixedWriteIterator_for_UInt8_Analog->pPosition);
    ++(pPrefixedWriteIterator_for_UInt8_Analog->count);
    return true;
  }
  else
  {
    return false;
  }
}

boolean IsValid_in_PrefixedWriteIterator_for_UInt8_Analog(PrefixedWriteIterator_for_UInt8_Analog *pPrefixedWriteIterator_for_UInt8_Analog)
{
  return pPrefixedWriteIterator_for_UInt8_Analog->isValid;
}
//-------------------Uint8---------------------------------------------------
//-------------------Uint16---------------------------------------------------
PrefixedWriteIterator_for_UInt16_Analog Null_in_PrefixedWriteIterator_for_UInt16_Analog_static(void)
{
  PrefixedWriteIterator_for_UInt16_Analog pPrefixedWriteIterator_for_UInt16_Analog;
////    return PrefixedWriteIterator();
  PrefixedWriteIterator_for_UInt16_Analog_in_PrefixedWriteIterator_for_UInt16_AnalogOver1(&pPrefixedWriteIterator_for_UInt16_Analog);
  return pPrefixedWriteIterator_for_UInt16_Analog;
}

void PrefixedWriteIterator_for_UInt16_Analog_in_PrefixedWriteIterator_for_UInt16_AnalogOver1(PrefixedWriteIterator_for_UInt16_Analog *pPrefixedWriteIterator_for_UInt16_Analog)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"PrefixedWriteIterator_for_UInt16_Analog_in_PrefixedWriteIterator_for_UInt16_AnalogOver1_1"<<'\n';
  decrement_stack_info();
#endif
//// : sizeOfTypePlusIndex(0), count(0), isValid(false), pPosition(nullptr) {}
  pPrefixedWriteIterator_for_UInt16_Analog->sizeOfTypePlusIndex = 0;
  pPrefixedWriteIterator_for_UInt16_Analog->count = 0;
  pPrefixedWriteIterator_for_UInt16_Analog->isValid = false;
  pPrefixedWriteIterator_for_UInt16_Analog->pPosition = NULL;
}

void PrefixedWriteIterator_for_UInt16_Analog_in_PrefixedWriteIterator_for_UInt16_AnalogOver2(PrefixedWriteIterator_for_UInt16_Analog *pPrefixedWriteIterator_for_UInt16_Analog,
    Serializer_for_Analog* serializer, WSeq_for_Uint16_t* position)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"PrefixedWriteIterator_for_UInt16_Analog_in_PrefixedWriteIterator_for_UInt16_AnalogOver2_1"<<'\n';
  decrement_stack_info();
#endif
  pPrefixedWriteIterator_for_UInt16_Analog->serializer = *serializer;
  pPrefixedWriteIterator_for_UInt16_Analog->sizeOfTypePlusIndex = get_size_in_Serializer_for_Analog(serializer) +////serializer.get_size() + PrefixType::size;
      size_in_UInt16;
  pPrefixedWriteIterator_for_UInt16_Analog->count = 0;
  ////isValid = position.length() >= PrefixType::size),
  pPrefixedWriteIterator_for_UInt16_Analog->isValid = length_in_HasLength_for_Uint16_t(&(position->hHasLength)) >= size_in_UInt16;
  pPrefixedWriteIterator_for_UInt16_Analog->countPosition = *position;
  pPrefixedWriteIterator_for_UInt16_Analog->pPosition = position;

  if (pPrefixedWriteIterator_for_UInt16_Analog->isValid)
  {
////        pPosition->advance(PrefixType::size);
    advance_in_WSeq_for_Uint16_t(position, size_in_UInt16);
  }
}

////    ~PrefixedWriteIterator()
void PrefixedWriteIterator_for_UInt16_Analog_destr_PrefixedWriteIterator_for_UInt16_Analog(PrefixedWriteIterator_for_UInt16_Analog *pPrefixedWriteIterator_for_UInt16_Analog)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"PrefixedWriteIterator_for_UInt16_Analog_destr_PrefixedWriteIterator_for_UInt16_Analog1"<<'\n';
  decrement_stack_info();
#endif
  if (pPrefixedWriteIterator_for_UInt16_Analog->isValid)
  {
////        PrefixType::write_to(countPosition, count);
    write_to_in_UInt16_static(&(pPrefixedWriteIterator_for_UInt16_Analog->countPosition), pPrefixedWriteIterator_for_UInt16_Analog->count);
  }
}

boolean Write_in_PrefixedWriteIterator_for_UInt16_Analog(PrefixedWriteIterator_for_UInt16_Analog *pPrefixedWriteIterator_for_UInt16_Analog,
    Analog* value, uint16_t index)
{
////    if (isValid && (pPosition->length() >= sizeOfTypePlusIndex))
  if(pPrefixedWriteIterator_for_UInt16_Analog->isValid &&
      length_in_HasLength_for_Uint16_t(&(pPrefixedWriteIterator_for_UInt16_Analog->pPosition->hHasLength))
      >= pPrefixedWriteIterator_for_UInt16_Analog->sizeOfTypePlusIndex)
  {
////        PrefixType::write_to(*pPosition, index);
    write_to_in_UInt16_static(pPrefixedWriteIterator_for_UInt16_Analog->pPosition, index);
////        serializer.write(value, *pPosition);
    write_in_Serializer_for_Analog(&(pPrefixedWriteIterator_for_UInt16_Analog->serializer), value,
                                   pPrefixedWriteIterator_for_UInt16_Analog->pPosition);
    ++(pPrefixedWriteIterator_for_UInt16_Analog->count);
    return true;
  }
  else
  {
    return false;
  }
}

boolean IsValid_in_PrefixedWriteIterator_for_UInt16_Analog(PrefixedWriteIterator_for_UInt16_Analog *pPrefixedWriteIterator_for_UInt16_Analog)
{
  return pPrefixedWriteIterator_for_UInt16_Analog->isValid;
}
//-------------------Uint16---------------------------------------------------
