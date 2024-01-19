#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "HeaderWriter_for_OctetString.h"

PrefixedWriteIterator_for_UInt16_OctetString IterateOverCountWithPrefix_for_UInt16_OctetString_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc, DNP3Serializer_for_OctetString* serializer)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"IterateOverCountWithPrefix_for_UInt16_OctetString_in_HeaderWriter1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*qc= "<<(uint16_t)qc<<'\n';
  decrement_stack_info();
#endif
////    const auto reserve_size
  uint16_t reserve_size =
////        = 2 * PrefixType::size + serializer.get_size(); // enough space for the count, 1 prefix + object
    2*size_in_UInt16 +
    get_size_in_Serializer_for_OctetString(&(serializer->sSerializer_for_OctetString));
////    if (this->WriteHeaderWithReserve(serializer.ID(), qc, reserve_size))
  if(WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter, ID_in_DNP3Serializer_for_OctetString(serializer), qc, reserve_size))
  {
    PrefixedWriteIterator_for_UInt16_OctetString pPrefixedWriteIterator_for_UInt16_OctetString;
    PrefixedWriteIterator_for_UInt16_OctetString_in_PrefixedWriteIterator_for_UInt16_OctetStringOver2(&pPrefixedWriteIterator_for_UInt16_OctetString,
        &(serializer->sSerializer_for_OctetString), pHeaderWriter->position);
//        return PrefixedWriteIterator<PrefixType, WriteType>(serializer, *position);
    return pPrefixedWriteIterator_for_UInt16_OctetString;
  }
  else
  {
////        return PrefixedWriteIterator<PrefixType, WriteType>::Null();
    return Null_in_PrefixedWriteIterator_for_UInt16_OctetString_static();
  }
}
//---------------------------------------------IterateOverRange_for_UInt8_OctetString_in_HeaderWriter--------------------------------------------
////template<class IndexType, class WriteType>
////RangeWriteIterator<IndexType, WriteType> HeaderWriter::IterateOverRange(QualifierCode qc,
////                                                                        const DNP3Serializer<WriteType>& serializer,
////                                                                        typename IndexType::type_t start)
RangeWriteIterator_for_UInt8_OctetString IterateOverRange_for_UInt8_OctetString_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc,
    DNP3Serializer_for_OctetString *serializer,
    uint8_t start
                                                                                     )
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"IterateOverRange_for_UInt8_OctetString_in_HeaderWriter1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*qc= "<<(uint16_t)qc<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*start= "<<(uint16_t)start<<'\n';
  decrement_stack_info();
#endif
//    const auto reserve_size = 2 * IndexType::size + serializer.get_size();
//     pRangeWriteIterator_for_UInt8_OctetString->isValid = length_in_HasLength_for_Uint16_t(&(position->hHasLength)) >= 2 * size_in_UInt8;
  uint16_t reserve_size = 2 * size_in_UInt8 +
                          get_size_in_Serializer_for_OctetString(&(serializer->sSerializer_for_OctetString));

//    if (this->WriteHeaderWithReserve(serializer.ID(), qc, reserve_size))
//boolean WriteHeaderWithReserve_in_HeaderWriter(HeaderWriter *pHeaderWriter, GroupVariationID id, QualifierCode_uint8_t qc, uint16_t reserve)
//    GroupVariationID ID_in_DNP3Serializer_for_OctetString(DNP3Serializer_for_OctetString *pDNP3Serializer_for_OctetString)
  if(WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter, ID_in_DNP3Serializer_for_OctetString(serializer), qc, reserve_size))
  {
//        return RangeWriteIterator<IndexType, WriteType>(start, serializer, *position);
    RangeWriteIterator_for_UInt8_OctetString rRangeWriteIterator_for_UInt8_OctetString;
////    void RangeWriteIterator_for_UInt8_OctetString_in_RangeWriteIterator_for_UInt8_OctetStringOver2(RangeWriteIterator_for_UInt8_OctetString *pRangeWriteIterator_for_UInt8_OctetString,
//                   typename IndexType::type_t start_,
////                   uint8_t start_,
//                   const Serializer<WriteType>& serializer,
////                   Serializer_for_OctetString*  serializer,
//                   ser4cpp::wseq_t& position)
////                   WSeq_for_Uint16_t* position);
    RangeWriteIterator_for_UInt8_OctetString_in_RangeWriteIterator_for_UInt8_OctetStringOver2(&rRangeWriteIterator_for_UInt8_OctetString,
        start,
        &(serializer->sSerializer_for_OctetString),
        pHeaderWriter->position
                                                                                   );
    return rRangeWriteIterator_for_UInt8_OctetString;
  }
  else
  {
//        return RangeWriteIterator<IndexType, WriteType>::Null();
    return Null_in_RangeWriteIterator_for_UInt8_OctetString_static();
  }
}
//---------------------------------------------IterateOverRange_for_UInt8_OctetString_in_HeaderWriter--------------------------------------------
//---------------------------------------------IterateOverRange_for_UInt16_OctetString_in_HeaderWriter--------------------------------------------
////template<class IndexType, class WriteType>
////RangeWriteIterator<IndexType, WriteType> HeaderWriter::IterateOverRange(QualifierCode qc,
////                                                                        const DNP3Serializer<WriteType>& serializer,
////                                                                        typename IndexType::type_t start)
RangeWriteIterator_for_UInt16_OctetString IterateOverRange_for_UInt16_OctetString_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc,
    DNP3Serializer_for_OctetString *serializer,
    uint16_t start
                                                                                     )
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"IterateOverRange_for_UInt16_OctetString_in_HeaderWriter1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*qc= "<<(uint16_t)qc<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*start= "<<(uint16_t)start<<'\n';
  decrement_stack_info();
#endif
//    const auto reserve_size = 2 * IndexType::size + serializer.get_size();
//     pRangeWriteIterator_for_UInt8_OctetString->isValid = length_in_HasLength_for_Uint16_t(&(position->hHasLength)) >= 2 * size_in_UInt8;
  uint16_t reserve_size = 2 * size_in_UInt16 +
                          get_size_in_Serializer_for_OctetString(&(serializer->sSerializer_for_OctetString));

//    if (this->WriteHeaderWithReserve(serializer.ID(), qc, reserve_size))
//boolean WriteHeaderWithReserve_in_HeaderWriter(HeaderWriter *pHeaderWriter, GroupVariationID id, QualifierCode_uint8_t qc, uint16_t reserve)
//    GroupVariationID ID_in_DNP3Serializer_for_OctetString(DNP3Serializer_for_OctetString *pDNP3Serializer_for_OctetString)
  if(WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter, ID_in_DNP3Serializer_for_OctetString(serializer), qc, reserve_size))
  {
//        return RangeWriteIterator<IndexType, WriteType>(start, serializer, *position);
    RangeWriteIterator_for_UInt16_OctetString rRangeWriteIterator_for_UInt16_OctetString;
////    void RangeWriteIterator_for_UInt8_OctetString_in_RangeWriteIterator_for_UInt8_OctetStringOver2(RangeWriteIterator_for_UInt8_OctetString *pRangeWriteIterator_for_UInt8_OctetString,
//                   typename IndexType::type_t start_,
////                   uint8_t start_,
//                   const Serializer<WriteType>& serializer,
////                   Serializer_for_OctetString*  serializer,
//                   ser4cpp::wseq_t& position)
////                   WSeq_for_Uint16_t* position);
    RangeWriteIterator_for_UInt16_OctetString_in_RangeWriteIterator_for_UInt16_OctetStringOver2(&rRangeWriteIterator_for_UInt16_OctetString,
        start,
        &(serializer->sSerializer_for_OctetString),
        pHeaderWriter->position
                                                                                   );
    return rRangeWriteIterator_for_UInt16_OctetString;
  }
  else
  {
//        return RangeWriteIterator<IndexType, WriteType>::Null();
    return Null_in_RangeWriteIterator_for_UInt16_OctetString_static();
  }
}
//---------------------------------------------IterateOverRange_for_UInt16_OctetString_in_HeaderWriter--------------------------------------------
