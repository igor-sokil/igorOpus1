#include "header.h"
#include "PrefixedWriteIterator_for_BinaryOutputStatus.h"
#include "SerializationTemplates.h"
#include <string.h>

//-------------------Uint16---------------------------------------------------

PrefixedWriteIterator_for_UInt16_BinaryOutputStatus Null_in_PrefixedWriteIterator_for_UInt16_BinaryOutputStatus_static(void)
{
  PrefixedWriteIterator_for_UInt16_BinaryOutputStatus pPrefixedWriteIterator_for_UInt16_BinaryOutputStatus;
////    return PrefixedWriteIterator();
  PrefixedWriteIterator_for_UInt16_BinaryOutputStatus_in_PrefixedWriteIterator_for_UInt16_BinaryOutputStatusOver1(&pPrefixedWriteIterator_for_UInt16_BinaryOutputStatus);
  return pPrefixedWriteIterator_for_UInt16_BinaryOutputStatus;
}

void PrefixedWriteIterator_for_UInt16_BinaryOutputStatus_in_PrefixedWriteIterator_for_UInt16_BinaryOutputStatusOver1(PrefixedWriteIterator_for_UInt16_BinaryOutputStatus *pPrefixedWriteIterator_for_UInt16_BinaryOutputStatus)
{
//// : sizeOfTypePlusIndex(0), count(0), isValid(false), pPosition(nullptr) {}
  pPrefixedWriteIterator_for_UInt16_BinaryOutputStatus->sizeOfTypePlusIndex = 0;
  pPrefixedWriteIterator_for_UInt16_BinaryOutputStatus->count = 0;
  pPrefixedWriteIterator_for_UInt16_BinaryOutputStatus->isValid = false;
  pPrefixedWriteIterator_for_UInt16_BinaryOutputStatus->pPosition = NULL;
}

void PrefixedWriteIterator_for_UInt16_BinaryOutputStatus_in_PrefixedWriteIterator_for_UInt16_BinaryOutputStatusOver2(PrefixedWriteIterator_for_UInt16_BinaryOutputStatus *pPrefixedWriteIterator_for_UInt16_BinaryOutputStatus,
    Serializer_for_BinaryOutputStatus* serializer, WSeq_for_Uint16_t* position)
{
  pPrefixedWriteIterator_for_UInt16_BinaryOutputStatus->serializer = *serializer;
  pPrefixedWriteIterator_for_UInt16_BinaryOutputStatus->sizeOfTypePlusIndex = get_size_in_Serializer_for_BinaryOutputStatus(serializer) +////serializer.get_size() + PrefixType::size;
      size_in_UInt16;
  pPrefixedWriteIterator_for_UInt16_BinaryOutputStatus->count = 0;
  ////isValid = position.length() >= PrefixType::size),
  pPrefixedWriteIterator_for_UInt16_BinaryOutputStatus->isValid = length_in_HasLength_for_Uint16_t(&(position->hHasLength)) >= size_in_UInt16;
  pPrefixedWriteIterator_for_UInt16_BinaryOutputStatus->countPosition = *position;
  pPrefixedWriteIterator_for_UInt16_BinaryOutputStatus->pPosition = position;

  if (pPrefixedWriteIterator_for_UInt16_BinaryOutputStatus->isValid)
  {
////        pPosition->advance(PrefixType::size);
    advance_in_WSeq_for_Uint16_t(position, size_in_UInt16);
  }
}

////    ~PrefixedWriteIterator()
void PrefixedWriteIterator_for_UInt16_BinaryOutputStatus_destr_PrefixedWriteIterator_for_UInt16_BinaryOutputStatus(PrefixedWriteIterator_for_UInt16_BinaryOutputStatus *pPrefixedWriteIterator_for_UInt16_BinaryOutputStatus)
{
  if (pPrefixedWriteIterator_for_UInt16_BinaryOutputStatus->isValid)
  {
////        PrefixType::write_to(countPosition, count);
    write_to_in_UInt16_static(&(pPrefixedWriteIterator_for_UInt16_BinaryOutputStatus->countPosition), pPrefixedWriteIterator_for_UInt16_BinaryOutputStatus->count);
  }
}

boolean Write_in_PrefixedWriteIterator_for_UInt16_BinaryOutputStatus(PrefixedWriteIterator_for_UInt16_BinaryOutputStatus *pPrefixedWriteIterator_for_UInt16_BinaryOutputStatus,
    BinaryOutputStatus* value, uint16_t index)
{
////    if (isValid && (pPosition->length() >= sizeOfTypePlusIndex))
  if(pPrefixedWriteIterator_for_UInt16_BinaryOutputStatus->isValid &&
      length_in_HasLength_for_Uint16_t(&(pPrefixedWriteIterator_for_UInt16_BinaryOutputStatus->pPosition->hHasLength))
      >= pPrefixedWriteIterator_for_UInt16_BinaryOutputStatus->sizeOfTypePlusIndex)
  {
////        PrefixType::write_to(*pPosition, index);
    write_to_in_UInt16_static(pPrefixedWriteIterator_for_UInt16_BinaryOutputStatus->pPosition, index);
////        serializer.write(value, *pPosition);
    write_in_Serializer_for_BinaryOutputStatus(&(pPrefixedWriteIterator_for_UInt16_BinaryOutputStatus->serializer), value,
        pPrefixedWriteIterator_for_UInt16_BinaryOutputStatus->pPosition);
    ++(pPrefixedWriteIterator_for_UInt16_BinaryOutputStatus->count);
    return true;
  }
  else
  {
    return false;
  }
}

boolean IsValid_in_PrefixedWriteIterator_for_UInt16_BinaryOutputStatus(PrefixedWriteIterator_for_UInt16_BinaryOutputStatus *pPrefixedWriteIterator_for_UInt16_BinaryOutputStatus)
{
  return pPrefixedWriteIterator_for_UInt16_BinaryOutputStatus->isValid;
}
//-------------------Uint16---------------------------------------------------
