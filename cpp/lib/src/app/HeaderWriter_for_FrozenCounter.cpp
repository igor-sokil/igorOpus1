#include "header.h"
#include "HeaderWriter_for_FrozenCounter.h"

//---------------------------------------------IterateOverRange_for_UInt8_FrozenCounter_in_HeaderWriter--------------------------------------------
    RangeWriteIterator_for_UInt8_FrozenCounter IterateOverRange_for_UInt8_FrozenCounter_in_HeaderWriter(HeaderWriter *pHeaderWriter, 
                                                   QualifierCode_uint8_t qc,
                                                   DNP3Serializer_for_FrozenCounter *serializer,
                                                   uint8_t start
                                                  )
{
//    const auto reserve_size = 2 * IndexType::size + serializer.get_size();
//     pRangeWriteIterator_for_UInt8_Binary->isValid = length_in_HasLength_for_Uint16_t(&(position->hHasLength)) >= 2 * size_in_UInt8;
       uint16_t reserve_size = 2 * size_in_UInt8 +
        get_size_in_Serializer_for_FrozenCounter(&(serializer->sSerializer_for_FrozenCounter));

//    if (this->WriteHeaderWithReserve(serializer.ID(), qc, reserve_size))
//boolean WriteHeaderWithReserve_in_HeaderWriter(HeaderWriter *pHeaderWriter, GroupVariationID id, QualifierCode_uint8_t qc, uint16_t reserve)
//    GroupVariationID ID_in_DNP3Serializer_for_Binary(DNP3Serializer_for_Binary *pDNP3Serializer_for_Binary) 
    if(WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter, ID_in_DNP3Serializer_for_FrozenCounter(serializer), qc, reserve_size))
    {
//        return RangeWriteIterator<IndexType, WriteType>(start, serializer, *position);
       RangeWriteIterator_for_UInt8_FrozenCounter rRangeWriteIterator_for_UInt8_FrozenCounter;
////    void RangeWriteIterator_for_UInt8_Binary_in_RangeWriteIterator_for_UInt8_BinaryOver2(RangeWriteIterator_for_UInt8_Binary *pRangeWriteIterator_for_UInt8_Binary,
//                   typename IndexType::type_t start_,
////                   uint8_t start_,
//                   const Serializer<WriteType>& serializer,
////                   Serializer_for_Binary*  serializer,
//                   ser4cpp::wseq_t& position)
////                   WSeq_for_Uint16_t* position);
       RangeWriteIterator_for_UInt8_FrozenCounter_in_RangeWriteIterator_for_UInt8_FrozenCounterOver2(&rRangeWriteIterator_for_UInt8_FrozenCounter,
                                        start,
                                        &(serializer->sSerializer_for_FrozenCounter),
                                        pHeaderWriter->position
                                       );
       return rRangeWriteIterator_for_UInt8_FrozenCounter;
    }
    else
    {
//        return RangeWriteIterator<IndexType, WriteType>::Null();
       return Null_in_RangeWriteIterator_for_UInt8_FrozenCounter_static();
    }
}
//---------------------------------------------IterateOverRange_for_UInt8_FrozenCounter_in_HeaderWriter--------------------------------------------
