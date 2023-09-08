  //#include <QtWidgets>
#include "header.h"
#include "BitfieldRangeWriteIterator_for_UInt8.h"
#include "SerializationTemplates.h"

BitfieldRangeWriteIterator_for_UInt8 Null_in_BitfieldRangeWriteIterator_for_UInt8_static(void)
{
////    auto buffer = ser4cpp::wseq_t::empty();
  WSeq_for_Uint16_t buffer_t = empty_in_WSeq_for_Uint16_t_static();
////    return BitfieldRangeWriteIterator(0, buffer);
  BitfieldRangeWriteIterator_for_UInt8 bBitfieldRangeWriteIterator_for_UInt8;
  BitfieldRangeWriteIterator_for_UInt8_in_BitfieldRangeWriteIterator_for_UInt8(&bBitfieldRangeWriteIterator_for_UInt8, 0, &buffer_t);
  return bBitfieldRangeWriteIterator_for_UInt8;
}

void  BitfieldRangeWriteIterator_for_UInt8_in_BitfieldRangeWriteIterator_for_UInt8(BitfieldRangeWriteIterator_for_UInt8 *pBitfieldRangeWriteIterator_for_UInt8,
    uint8_t start_, WSeq_for_Uint16_t* position_)
{
  pBitfieldRangeWriteIterator_for_UInt8->start = start_;
  pBitfieldRangeWriteIterator_for_UInt8->count = 0;
  pBitfieldRangeWriteIterator_for_UInt8->maxCount = 0;
////      isValid(position_.length() >= (2 * IndexType::size)),
  pBitfieldRangeWriteIterator_for_UInt8->isValid = length_in_HasLength_for_Uint16_t(&(position_->hHasLength)) >= (2 * size_in_UInt8);
  pBitfieldRangeWriteIterator_for_UInt8->range = *position_;
  pBitfieldRangeWriteIterator_for_UInt8->pPosition = position_;

  if (pBitfieldRangeWriteIterator_for_UInt8->isValid)
  {
////        IndexType::write_to(range, start_);
    write_to_in_UInt8_static(&(pBitfieldRangeWriteIterator_for_UInt8->range), start_);
////        pPosition->advance(2 * IndexType::size);
    advance_in_WSeq_for_Uint16_t(pBitfieldRangeWriteIterator_for_UInt8->pPosition, 2 * size_in_UInt8);
////        maxCount = pPosition->length() * 8;
    pBitfieldRangeWriteIterator_for_UInt8->maxCount = length_in_HasLength_for_Uint16_t(&(pBitfieldRangeWriteIterator_for_UInt8->pPosition->hHasLength)) * 8;
  }
}

////    ~BitfieldRangeWriteIterator()
void BitfieldRangeWriteIterator_for_UInt8_destr_BitfieldRangeWriteIterator_for_UInt8(BitfieldRangeWriteIterator_for_UInt8 *pBitfieldRangeWriteIterator_for_UInt8)
{
////        if (isValid && count > 0)
  if (pBitfieldRangeWriteIterator_for_UInt8->isValid && pBitfieldRangeWriteIterator_for_UInt8->count > 0)
  {
////        typename IndexType::type_t stop = start + count - 1;
    uint8_t stop = pBitfieldRangeWriteIterator_for_UInt8->start + pBitfieldRangeWriteIterator_for_UInt8->count - 1;
////        IndexType::write_to(range, stop);
    write_to_in_UInt8_static(&(pBitfieldRangeWriteIterator_for_UInt8->range), stop);
    uint8_t num = pBitfieldRangeWriteIterator_for_UInt8->count / 8;

////            if ((count % 8) > 0)
    if ((pBitfieldRangeWriteIterator_for_UInt8->count % 8) > 0)
    {
      ++num;
    }

////        pPosition->advance(num);
    advance_in_WSeq_for_Uint16_t(pBitfieldRangeWriteIterator_for_UInt8->pPosition, num);
  }
}

boolean Write_in_BitfieldRangeWriteIterator_for_UInt8(BitfieldRangeWriteIterator_for_UInt8 *pBitfieldRangeWriteIterator_for_UInt8, boolean value)
{
  if (pBitfieldRangeWriteIterator_for_UInt8->isValid && pBitfieldRangeWriteIterator_for_UInt8->count < pBitfieldRangeWriteIterator_for_UInt8->maxCount)
  {
    uint8_t byte = pBitfieldRangeWriteIterator_for_UInt8->count / 8;
    uint8_t bit  = pBitfieldRangeWriteIterator_for_UInt8->count % 8;

    if (bit == 0)
    {
////            (*pPosition)[byte] = 0; // initialize byte to 0
      pBitfieldRangeWriteIterator_for_UInt8->pPosition->buffer_[byte] = 0; // initialize byte to 0
    }

    if (value)
    {
////            (*pPosition)[byte] = ((*pPosition)[byte] | (1 << bit));
      pBitfieldRangeWriteIterator_for_UInt8->pPosition->buffer_[byte] = (pBitfieldRangeWriteIterator_for_UInt8->pPosition->buffer_[byte] | (1 << bit));
    }

    ++(pBitfieldRangeWriteIterator_for_UInt8->count);
    return true;
  }
  else
  {
    return false;
  }
}

boolean IsValid_in_BitfieldRangeWriteIterator_for_UInt8(BitfieldRangeWriteIterator_for_UInt8 *pBitfieldRangeWriteIterator_for_UInt8)
{
  return pBitfieldRangeWriteIterator_for_UInt8->isValid;
}
