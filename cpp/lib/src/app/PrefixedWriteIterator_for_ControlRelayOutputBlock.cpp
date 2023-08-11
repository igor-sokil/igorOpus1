#include "header.h"
#include "PrefixedWriteIterator_for_ControlRelayOutputBlock.h"
#include "SerializationTemplates.h"
#include <string.h>
//-------------------Uint16---------------------------------------------------

PrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock Null_in_PrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock_static(void)
{
  PrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock pPrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock;
////    return PrefixedWriteIterator();
  PrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock_in_PrefixedWriteIterator_for_UInt16_ControlRelayOutputBlockOver1(&pPrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock);
  return pPrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock;
}

void PrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock_in_PrefixedWriteIterator_for_UInt16_ControlRelayOutputBlockOver1(PrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock *pPrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock)
{
//// : sizeOfTypePlusIndex(0), count(0), isValid(false), pPosition(nullptr) {}
  pPrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock->sizeOfTypePlusIndex = 0;
  pPrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock->count = 0;
  pPrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock->isValid = false;
  pPrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock->pPosition = NULL;
}

void PrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock_in_PrefixedWriteIterator_for_UInt16_ControlRelayOutputBlockOver2(PrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock *pPrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock,
    Serializer_for_ControlRelayOutputBlock* serializer, WSeq_for_Uint16_t* position)
{
  pPrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock->serializer = *serializer;
  pPrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock->sizeOfTypePlusIndex = get_size_in_Serializer_for_ControlRelayOutputBlock(serializer) +////serializer.get_size() + PrefixType::size;
      size_in_UInt16;
  pPrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock->count = 0;
  ////isValid = position.length() >= PrefixType::size),
  pPrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock->isValid = length_in_HasLength_for_Uint16_t(&(position->hHasLength)) >= size_in_UInt16;
  pPrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock->countPosition = *position;
  pPrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock->pPosition = position;

  if (pPrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock->isValid)
  {
////        pPosition->advance(PrefixType::size);
    advance_in_WSeq_for_Uint16_t(position, size_in_UInt16);
  }
}

////    ~PrefixedWriteIterator()
void PrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock_destr_PrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock(PrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock *pPrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock)
{
  if (pPrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock->isValid)
  {
////        PrefixType::write_to(countPosition, count);
    write_to_in_UInt16_static(&(pPrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock->countPosition), pPrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock->count);
  }
}

boolean Write_in_PrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock(PrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock *pPrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock,
    ControlRelayOutputBlock* value, uint16_t index)
{
////    if (isValid && (pPosition->length() >= sizeOfTypePlusIndex))
  if(pPrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock->isValid &&
      length_in_HasLength_for_Uint16_t(&(pPrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock->pPosition->hHasLength))
      >= pPrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock->sizeOfTypePlusIndex)
  {
////        PrefixType::write_to(*pPosition, index);
    write_to_in_UInt16_static(pPrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock->pPosition, index);
////        serializer.write(value, *pPosition);
    write_in_Serializer_for_ControlRelayOutputBlock(&(pPrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock->serializer), value,
        pPrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock->pPosition);
    ++(pPrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock->count);
    return true;
  }
  else
  {
    return false;
  }
}

boolean IsValid_in_PrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock(PrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock *pPrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock)
{
  return pPrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock->isValid;
}
//-------------------Uint16---------------------------------------------------
