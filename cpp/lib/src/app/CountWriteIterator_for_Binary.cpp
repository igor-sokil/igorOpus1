#include "header.h"
#include "CountWriteIterator_for_Binary.h"
#include "SerializationTemplates.h"
#include <string.h>

//-------------------Uint8---------------------------------------------------
CountWriteIterator_for_UInt8_Binary Null_in_CountWriteIterator_for_UInt8_Binary_static(void)
{
  CountWriteIterator_for_UInt8_Binary cCountWriteIterator_for_UInt8_Binary;
////    return CountWriteIterator();
  CountWriteIterator_for_UInt8_Binary_in_CountWriteIterator_for_UInt8_BinaryOver1(&cCountWriteIterator_for_UInt8_Binary);
  return cCountWriteIterator_for_UInt8_Binary;
}

////    CountWriteIterator() : count(0), isValid(false), pPosition(nullptr) {}
void CountWriteIterator_for_UInt8_Binary_in_CountWriteIterator_for_UInt8_BinaryOver1(CountWriteIterator_for_UInt8_Binary *pCountWriteIterator_for_UInt8_Binary)
{
  pCountWriteIterator_for_UInt8_Binary->count = 0;
  pCountWriteIterator_for_UInt8_Binary->isValid = false;
  pCountWriteIterator_for_UInt8_Binary->pPosition = NULL;
}

////    CountWriteIterator(const Serializer<WriteType>& serializer, ser4cpp::wseq_t& position)
void CountWriteIterator_for_UInt8_Binary_in_CountWriteIterator_for_UInt8_BinaryOver2(CountWriteIterator_for_UInt8_Binary *pCountWriteIterator_for_UInt8_Binary,
    Serializer_for_Binary *serializer, WSeq_for_Uint16_t *position)
{

  pCountWriteIterator_for_UInt8_Binary->count = 0;
  pCountWriteIterator_for_UInt8_Binary->serializer = *serializer;
  pCountWriteIterator_for_UInt8_Binary->isValid = length_in_HasLength_for_Uint16_t(&(pCountWriteIterator_for_UInt8_Binary->pPosition->hHasLength))////position.length()
      >= size_in_UInt8;////CountType::size),
  pCountWriteIterator_for_UInt8_Binary->countPosition = *position;
  pCountWriteIterator_for_UInt8_Binary->pPosition = position;

  if (pCountWriteIterator_for_UInt8_Binary->isValid)
  {
//        position.advance(CountType::size);
    advance_in_WSeq_for_Uint16_t(position, size_in_UInt8);
  }
}

////    ~CountWriteIterator()
void CountWriteIterator_for_UInt8_Binary_destr_CountWriteIterator_for_UInt8_Binary(CountWriteIterator_for_UInt8_Binary *pCountWriteIterator_for_UInt8_Binary)
{
  if (pCountWriteIterator_for_UInt8_Binary->isValid)
  {
////        CountType::write_to(countPosition, count);
    write_to_in_UInt8_static(&(pCountWriteIterator_for_UInt8_Binary->countPosition), pCountWriteIterator_for_UInt8_Binary->count);
  }
}

boolean Write_in_CountWriteIterator_for_UInt8_Binary(CountWriteIterator_for_UInt8_Binary *pCountWriteIterator_for_UInt8_Binary, Binary *value)////const WriteType& value)
{
////    if (isValid && (serializer.get_size() <= pPosition->length()) && (count < CountType::max_value))
  if(pCountWriteIterator_for_UInt8_Binary->isValid && (get_size_in_Serializer_for_Binary(&(pCountWriteIterator_for_UInt8_Binary->serializer)) <=
      length_in_HasLength_for_Uint16_t(&(pCountWriteIterator_for_UInt8_Binary->pPosition->hHasLength))
                                                      ) &&
      (pCountWriteIterator_for_UInt8_Binary->count < max_value_in_UInt8))
  {
////        serializer.write(value, *this->pPosition);
    write_in_Serializer_for_Binary(&(pCountWriteIterator_for_UInt8_Binary->serializer), value, pCountWriteIterator_for_UInt8_Binary->pPosition);
    ++(pCountWriteIterator_for_UInt8_Binary->count);
    return true;
  }
  else
  {
    return false;
  }
}

boolean IsValid_in_CountWriteIterator_for_UInt8_Binary(CountWriteIterator_for_UInt8_Binary *pCountWriteIterator_for_UInt8_Binary)
{
  return pCountWriteIterator_for_UInt8_Binary->isValid;
}
//-------------------Uint8---------------------------------------------------
