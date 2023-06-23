#include "header.h"
#include "PrefixedWriteIterator_for_Binary.h"
#include "SerializationTemplates.h"
#include <string.h>

//-------------------Uint16---------------------------------------------------

PrefixedWriteIterator_for_UInt16_Binary Null_in_PrefixedWriteIterator_for_UInt16_Binary_static(void)
{
  PrefixedWriteIterator_for_UInt16_Binary pPrefixedWriteIterator_for_UInt16_Binary;
////    return PrefixedWriteIterator();
  PrefixedWriteIterator_for_UInt16_Binary_in_PrefixedWriteIterator_for_UInt16_BinaryOver1(&pPrefixedWriteIterator_for_UInt16_Binary);
  return pPrefixedWriteIterator_for_UInt16_Binary;
}

void PrefixedWriteIterator_for_UInt16_Binary_in_PrefixedWriteIterator_for_UInt16_BinaryOver1(PrefixedWriteIterator_for_UInt16_Binary *pPrefixedWriteIterator_for_UInt16_Binary)
{
//// : sizeOfTypePlusIndex(0), count(0), isValid(false), pPosition(nullptr) {}
  pPrefixedWriteIterator_for_UInt16_Binary->sizeOfTypePlusIndex = 0;
  pPrefixedWriteIterator_for_UInt16_Binary->count = 0;
  pPrefixedWriteIterator_for_UInt16_Binary->isValid = false;
  pPrefixedWriteIterator_for_UInt16_Binary->pPosition = NULL;
}

void PrefixedWriteIterator_for_UInt16_Binary_in_PrefixedWriteIterator_for_UInt16_BinaryOver2(PrefixedWriteIterator_for_UInt16_Binary *pPrefixedWriteIterator_for_UInt16_Binary,
    Serializer_for_Binary* serializer, WSeq_for_Uint16_t* position)
{
  pPrefixedWriteIterator_for_UInt16_Binary->serializer = *serializer;
  pPrefixedWriteIterator_for_UInt16_Binary->sizeOfTypePlusIndex = get_size_in_Serializer_for_Binary(serializer) +////serializer.get_size() + PrefixType::size;
      size_in_UInt16;
  pPrefixedWriteIterator_for_UInt16_Binary->count = 0;
  ////isValid = position.length() >= PrefixType::size),
  pPrefixedWriteIterator_for_UInt16_Binary->isValid = length_in_HasLength_for_Uint16_t(&(position->hHasLength)) >= size_in_UInt16;
  pPrefixedWriteIterator_for_UInt16_Binary->countPosition = *position;
  pPrefixedWriteIterator_for_UInt16_Binary->pPosition = position;

  if (pPrefixedWriteIterator_for_UInt16_Binary->isValid)
  {
////        pPosition->advance(PrefixType::size);
    advance_in_WSeq_for_Uint16_t(position, size_in_UInt16);
  }
}

////    ~PrefixedWriteIterator()
void PrefixedWriteIterator_for_UInt16_Binary_destr_PrefixedWriteIterator_for_UInt16_Binary(PrefixedWriteIterator_for_UInt16_Binary *pPrefixedWriteIterator_for_UInt16_Binary)
{
  if (pPrefixedWriteIterator_for_UInt16_Binary->isValid)
  {
////        PrefixType::write_to(countPosition, count);
    write_to_in_UInt16_static(&(pPrefixedWriteIterator_for_UInt16_Binary->countPosition), pPrefixedWriteIterator_for_UInt16_Binary->count);
  }
}

boolean Write_in_PrefixedWriteIterator_for_UInt16_Binary(PrefixedWriteIterator_for_UInt16_Binary *pPrefixedWriteIterator_for_UInt16_Binary,
    Binary* value, uint16_t index)
{
////    if (isValid && (pPosition->length() >= sizeOfTypePlusIndex))
  if(pPrefixedWriteIterator_for_UInt16_Binary->isValid &&
      length_in_HasLength_for_Uint16_t(&(pPrefixedWriteIterator_for_UInt16_Binary->pPosition->hHasLength))
      >= pPrefixedWriteIterator_for_UInt16_Binary->sizeOfTypePlusIndex)
  {
////        PrefixType::write_to(*pPosition, index);
    write_to_in_UInt16_static(pPrefixedWriteIterator_for_UInt16_Binary->pPosition, index);
////        serializer.write(value, *pPosition);
    write_in_Serializer_for_Binary(&(pPrefixedWriteIterator_for_UInt16_Binary->serializer), value,
                                   pPrefixedWriteIterator_for_UInt16_Binary->pPosition);
    ++(pPrefixedWriteIterator_for_UInt16_Binary->count);
    return true;
  }
  else
  {
    return false;
  }
}

boolean IsValid_in_PrefixedWriteIterator_for_UInt16_Binary(PrefixedWriteIterator_for_UInt16_Binary *pPrefixedWriteIterator_for_UInt16_Binary)
{
  return pPrefixedWriteIterator_for_UInt16_Binary->isValid;
}
//-------------------Uint16---------------------------------------------------
