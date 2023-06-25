#include "header.h"
#include "CountWriteIterator_for_DoubleBitBinary.h"
#include "SerializationTemplates.h"
#include <string.h>

//-------------------Uint8---------------------------------------------------
    CountWriteIterator_for_UInt8_DoubleBitBinary Null_in_CountWriteIterator_for_UInt8_DoubleBitBinary_static(void)
{
    CountWriteIterator_for_UInt8_DoubleBitBinary cCountWriteIterator_for_UInt8_DoubleBitBinary;
////    return CountWriteIterator();
    CountWriteIterator_for_UInt8_DoubleBitBinary_in_CountWriteIterator_for_UInt8_DoubleBitBinaryOver1(&cCountWriteIterator_for_UInt8_DoubleBitBinary);
    return cCountWriteIterator_for_UInt8_DoubleBitBinary;
}

////    CountWriteIterator() : count(0), isValid(false), pPosition(nullptr) {}
    void CountWriteIterator_for_UInt8_DoubleBitBinary_in_CountWriteIterator_for_UInt8_DoubleBitBinaryOver1(CountWriteIterator_for_UInt8_DoubleBitBinary *pCountWriteIterator_for_UInt8_DoubleBitBinary)
{
   pCountWriteIterator_for_UInt8_DoubleBitBinary->count = 0;
   pCountWriteIterator_for_UInt8_DoubleBitBinary->isValid = false;
   pCountWriteIterator_for_UInt8_DoubleBitBinary->pPosition = NULL;
}

////    CountWriteIterator(const Serializer<WriteType>& serializer, ser4cpp::wseq_t& position)
    void CountWriteIterator_for_UInt8_DoubleBitBinary_in_CountWriteIterator_for_UInt8_DoubleBitBinaryOver2(CountWriteIterator_for_UInt8_DoubleBitBinary *pCountWriteIterator_for_UInt8_DoubleBitBinary,
                                            Serializer_for_DoubleBitBinary *serializer, WSeq_for_Uint16_t *position)
{

      pCountWriteIterator_for_UInt8_DoubleBitBinary->count = 0;
      pCountWriteIterator_for_UInt8_DoubleBitBinary->serializer = *serializer;
      pCountWriteIterator_for_UInt8_DoubleBitBinary->isValid = length_in_HasLength_for_Uint16_t(&(pCountWriteIterator_for_UInt8_DoubleBitBinary->pPosition->hHasLength))////position.length()
                                                    >= size_in_UInt8;////CountType::size),
      pCountWriteIterator_for_UInt8_DoubleBitBinary->countPosition = *position;
      pCountWriteIterator_for_UInt8_DoubleBitBinary->pPosition = position;

    if (pCountWriteIterator_for_UInt8_DoubleBitBinary->isValid)
    {
//        position.advance(CountType::size);
        advance_in_WSeq_for_Uint16_t(position, size_in_UInt8);
    }
}

////    ~CountWriteIterator()
    void CountWriteIterator_for_UInt8_DoubleBitBinary_destr_CountWriteIterator_for_UInt8_DoubleBitBinary(CountWriteIterator_for_UInt8_DoubleBitBinary *pCountWriteIterator_for_UInt8_DoubleBitBinary)
{
    if (pCountWriteIterator_for_UInt8_DoubleBitBinary->isValid)
    {
////        CountType::write_to(countPosition, count);
        write_to_in_UInt8_static(&(pCountWriteIterator_for_UInt8_DoubleBitBinary->countPosition), pCountWriteIterator_for_UInt8_DoubleBitBinary->count);
    }
}

    boolean Write_in_CountWriteIterator_for_UInt8_DoubleBitBinary(CountWriteIterator_for_UInt8_DoubleBitBinary *pCountWriteIterator_for_UInt8_DoubleBitBinary, DoubleBitBinary *value)////const WriteType& value)
{
////    if (isValid && (serializer.get_size() <= pPosition->length()) && (count < CountType::max_value))
    if(pCountWriteIterator_for_UInt8_DoubleBitBinary->isValid && (get_size_in_Serializer_for_DoubleBitBinary(&(pCountWriteIterator_for_UInt8_DoubleBitBinary->serializer)) <= 
                                                         length_in_HasLength_for_Uint16_t(&(pCountWriteIterator_for_UInt8_DoubleBitBinary->pPosition->hHasLength))
                                                        ) &&
                                                        (pCountWriteIterator_for_UInt8_DoubleBitBinary->count < max_value_in_UInt8))
    {
////        serializer.write(value, *this->pPosition);
        write_in_Serializer_for_DoubleBitBinary(&(pCountWriteIterator_for_UInt8_DoubleBitBinary->serializer), value, pCountWriteIterator_for_UInt8_DoubleBitBinary->pPosition);
        ++(pCountWriteIterator_for_UInt8_DoubleBitBinary->count);
        return true;
    }
    else
    {
        return false;
    }
}

    boolean IsValid_in_CountWriteIterator_for_UInt8_DoubleBitBinary(CountWriteIterator_for_UInt8_DoubleBitBinary *pCountWriteIterator_for_UInt8_DoubleBitBinary)
{
    return pCountWriteIterator_for_UInt8_DoubleBitBinary->isValid;
}
//-------------------Uint8---------------------------------------------------
