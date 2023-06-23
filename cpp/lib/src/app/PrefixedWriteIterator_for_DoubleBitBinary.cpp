#include "header.h"
#include "PrefixedWriteIterator_for_DoubleBitBinary.h"
#include "SerializationTemplates.h"
#include <string.h>

//-------------------Uint16---------------------------------------------------

PrefixedWriteIterator_for_UInt16_DoubleBitBinary Null_in_PrefixedWriteIterator_for_UInt16_DoubleBitBinary_static(void)
{
  PrefixedWriteIterator_for_UInt16_DoubleBitBinary pPrefixedWriteIterator_for_UInt16_DoubleBitBinary;
////    return PrefixedWriteIterator();
  PrefixedWriteIterator_for_UInt16_DoubleBitBinary_in_PrefixedWriteIterator_for_UInt16_DoubleBitBinaryOver1(&pPrefixedWriteIterator_for_UInt16_DoubleBitBinary);
  return pPrefixedWriteIterator_for_UInt16_DoubleBitBinary;
}

void PrefixedWriteIterator_for_UInt16_DoubleBitBinary_in_PrefixedWriteIterator_for_UInt16_DoubleBitBinaryOver1(PrefixedWriteIterator_for_UInt16_DoubleBitBinary *pPrefixedWriteIterator_for_UInt16_DoubleBitBinary)
{
//// : sizeOfTypePlusIndex(0), count(0), isValid(false), pPosition(nullptr) {}
  pPrefixedWriteIterator_for_UInt16_DoubleBitBinary->sizeOfTypePlusIndex = 0;
  pPrefixedWriteIterator_for_UInt16_DoubleBitBinary->count = 0;
  pPrefixedWriteIterator_for_UInt16_DoubleBitBinary->isValid = false;
  pPrefixedWriteIterator_for_UInt16_DoubleBitBinary->pPosition = NULL;
}

void PrefixedWriteIterator_for_UInt16_DoubleBitBinary_in_PrefixedWriteIterator_for_UInt16_DoubleBitBinaryOver2(PrefixedWriteIterator_for_UInt16_DoubleBitBinary *pPrefixedWriteIterator_for_UInt16_DoubleBitBinary,
    Serializer_for_DoubleBitBinary* serializer, WSeq_for_Uint16_t* position)
{
  pPrefixedWriteIterator_for_UInt16_DoubleBitBinary->serializer = *serializer;
  pPrefixedWriteIterator_for_UInt16_DoubleBitBinary->sizeOfTypePlusIndex = get_size_in_Serializer_for_DoubleBitBinary(serializer) +////serializer.get_size() + PrefixType::size;
      size_in_UInt16;
  pPrefixedWriteIterator_for_UInt16_DoubleBitBinary->count = 0;
  ////isValid = position.length() >= PrefixType::size),
  pPrefixedWriteIterator_for_UInt16_DoubleBitBinary->isValid = length_in_HasLength_for_Uint16_t(&(position->hHasLength)) >= size_in_UInt16;
  pPrefixedWriteIterator_for_UInt16_DoubleBitBinary->countPosition = *position;
  pPrefixedWriteIterator_for_UInt16_DoubleBitBinary->pPosition = position;

  if (pPrefixedWriteIterator_for_UInt16_DoubleBitBinary->isValid)
  {
////        pPosition->advance(PrefixType::size);
    advance_in_WSeq_for_Uint16_t(position, size_in_UInt16);
  }
}

////    ~PrefixedWriteIterator()
void PrefixedWriteIterator_for_UInt16_DoubleBitBinary_destr_PrefixedWriteIterator_for_UInt16_DoubleBitBinary(PrefixedWriteIterator_for_UInt16_DoubleBitBinary *pPrefixedWriteIterator_for_UInt16_DoubleBitBinary)
{
  if (pPrefixedWriteIterator_for_UInt16_DoubleBitBinary->isValid)
  {
////        PrefixType::write_to(countPosition, count);
    write_to_in_UInt16_static(&(pPrefixedWriteIterator_for_UInt16_DoubleBitBinary->countPosition), pPrefixedWriteIterator_for_UInt16_DoubleBitBinary->count);
  }
}

boolean Write_in_PrefixedWriteIterator_for_UInt16_DoubleBitBinary(PrefixedWriteIterator_for_UInt16_DoubleBitBinary *pPrefixedWriteIterator_for_UInt16_DoubleBitBinary,
    DoubleBitBinary* value, uint16_t index)
{
////    if (isValid && (pPosition->length() >= sizeOfTypePlusIndex))
  if(pPrefixedWriteIterator_for_UInt16_DoubleBitBinary->isValid &&
      length_in_HasLength_for_Uint16_t(&(pPrefixedWriteIterator_for_UInt16_DoubleBitBinary->pPosition->hHasLength))
      >= pPrefixedWriteIterator_for_UInt16_DoubleBitBinary->sizeOfTypePlusIndex)
  {
////        PrefixType::write_to(*pPosition, index);
    write_to_in_UInt16_static(pPrefixedWriteIterator_for_UInt16_DoubleBitBinary->pPosition, index);
////        serializer.write(value, *pPosition);
    write_in_Serializer_for_DoubleBitBinary(&(pPrefixedWriteIterator_for_UInt16_DoubleBitBinary->serializer), value,
                                   pPrefixedWriteIterator_for_UInt16_DoubleBitBinary->pPosition);
    ++(pPrefixedWriteIterator_for_UInt16_DoubleBitBinary->count);
    return true;
  }
  else
  {
    return false;
  }
}

boolean IsValid_in_PrefixedWriteIterator_for_UInt16_DoubleBitBinary(PrefixedWriteIterator_for_UInt16_DoubleBitBinary *pPrefixedWriteIterator_for_UInt16_DoubleBitBinary)
{
  return pPrefixedWriteIterator_for_UInt16_DoubleBitBinary->isValid;
}
//-------------------Uint16---------------------------------------------------
