#include "header.h"
#include "PrefixedWriteIterator_for_Counter.h"
#include "SerializationTemplates.h"
#include <string.h>

//-------------------Uint16---------------------------------------------------

PrefixedWriteIterator_for_UInt16_Counter Null_in_PrefixedWriteIterator_for_UInt16_Counter_static(void)
{
  PrefixedWriteIterator_for_UInt16_Counter pPrefixedWriteIterator_for_UInt16_Counter;
////    return PrefixedWriteIterator();
  PrefixedWriteIterator_for_UInt16_Counter_in_PrefixedWriteIterator_for_UInt16_CounterOver1(&pPrefixedWriteIterator_for_UInt16_Counter);
  return pPrefixedWriteIterator_for_UInt16_Counter;
}

void PrefixedWriteIterator_for_UInt16_Counter_in_PrefixedWriteIterator_for_UInt16_CounterOver1(PrefixedWriteIterator_for_UInt16_Counter *pPrefixedWriteIterator_for_UInt16_Counter)
{
//// : sizeOfTypePlusIndex(0), count(0), isValid(false), pPosition(nullptr) {}
  pPrefixedWriteIterator_for_UInt16_Counter->sizeOfTypePlusIndex = 0;
  pPrefixedWriteIterator_for_UInt16_Counter->count = 0;
  pPrefixedWriteIterator_for_UInt16_Counter->isValid = false;
  pPrefixedWriteIterator_for_UInt16_Counter->pPosition = NULL;
}

void PrefixedWriteIterator_for_UInt16_Counter_in_PrefixedWriteIterator_for_UInt16_CounterOver2(PrefixedWriteIterator_for_UInt16_Counter *pPrefixedWriteIterator_for_UInt16_Counter,
    Serializer_for_Counter* serializer, WSeq_for_Uint16_t* position)
{
  pPrefixedWriteIterator_for_UInt16_Counter->serializer = *serializer;
  pPrefixedWriteIterator_for_UInt16_Counter->sizeOfTypePlusIndex = get_size_in_Serializer_for_Counter(serializer) +////serializer.get_size() + PrefixType::size;
      size_in_UInt16;
  pPrefixedWriteIterator_for_UInt16_Counter->count = 0;
  ////isValid = position.length() >= PrefixType::size),
  pPrefixedWriteIterator_for_UInt16_Counter->isValid = length_in_HasLength_for_Uint16_t(&(position->hHasLength)) >= size_in_UInt16;
  pPrefixedWriteIterator_for_UInt16_Counter->countPosition = *position;
  pPrefixedWriteIterator_for_UInt16_Counter->pPosition = position;

  if (pPrefixedWriteIterator_for_UInt16_Counter->isValid)
  {
////        pPosition->advance(PrefixType::size);
    advance_in_WSeq_for_Uint16_t(position, size_in_UInt16);
  }
}

////    ~PrefixedWriteIterator()
void PrefixedWriteIterator_for_UInt16_Counter_destr_PrefixedWriteIterator_for_UInt16_Counter(PrefixedWriteIterator_for_UInt16_Counter *pPrefixedWriteIterator_for_UInt16_Counter)
{
  if (pPrefixedWriteIterator_for_UInt16_Counter->isValid)
  {
////        PrefixType::write_to(countPosition, count);
    write_to_in_UInt16_static(&(pPrefixedWriteIterator_for_UInt16_Counter->countPosition), pPrefixedWriteIterator_for_UInt16_Counter->count);
  }
}

boolean Write_in_PrefixedWriteIterator_for_UInt16_Counter(PrefixedWriteIterator_for_UInt16_Counter *pPrefixedWriteIterator_for_UInt16_Counter,
    Counter* value, uint16_t index)
{
////    if (isValid && (pPosition->length() >= sizeOfTypePlusIndex))
  if(pPrefixedWriteIterator_for_UInt16_Counter->isValid &&
      length_in_HasLength_for_Uint16_t(&(pPrefixedWriteIterator_for_UInt16_Counter->pPosition->hHasLength))
      >= pPrefixedWriteIterator_for_UInt16_Counter->sizeOfTypePlusIndex)
  {
////        PrefixType::write_to(*pPosition, index);
    write_to_in_UInt16_static(pPrefixedWriteIterator_for_UInt16_Counter->pPosition, index);
////        serializer.write(value, *pPosition);
    write_in_Serializer_for_Counter(&(pPrefixedWriteIterator_for_UInt16_Counter->serializer), value,
                                    pPrefixedWriteIterator_for_UInt16_Counter->pPosition);
    ++(pPrefixedWriteIterator_for_UInt16_Counter->count);
    return true;
  }
  else
  {
    return false;
  }
}

boolean IsValid_in_PrefixedWriteIterator_for_UInt16_Counter(PrefixedWriteIterator_for_UInt16_Counter *pPrefixedWriteIterator_for_UInt16_Counter)
{
  return pPrefixedWriteIterator_for_UInt16_Counter->isValid;
}
//-------------------Uint16---------------------------------------------------
