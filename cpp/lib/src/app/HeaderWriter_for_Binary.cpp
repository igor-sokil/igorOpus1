#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "HeaderWriter_for_Binary.h"

//---------------------------------------------IterateOverRange_for_UInt8_Binary_in_HeaderWriter--------------------------------------------
////template<class IndexType, class WriteType>
////RangeWriteIterator<IndexType, WriteType> HeaderWriter::IterateOverRange(QualifierCode qc,
////                                                                        const DNP3Serializer<WriteType>& serializer,
////                                                                        typename IndexType::type_t start)
RangeWriteIterator_for_UInt8_Binary IterateOverRange_for_UInt8_Binary_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc,
    DNP3Serializer_for_Binary *serializer,
    uint8_t start
                                                                                     )
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"IterateOverRange_for_UInt8_Binary_in_HeaderWriter1"<<'\n';
#endif
//    const auto reserve_size = 2 * IndexType::size + serializer.get_size();
//     pRangeWriteIterator_for_UInt8_Binary->isValid = length_in_HasLength_for_Uint16_t(&(position->hHasLength)) >= 2 * size_in_UInt8;
  uint16_t reserve_size = 2 * size_in_UInt8 +
                          get_size_in_Serializer_for_Binary(&(serializer->sSerializer_for_Binary));

//    if (this->WriteHeaderWithReserve(serializer.ID(), qc, reserve_size))
//boolean WriteHeaderWithReserve_in_HeaderWriter(HeaderWriter *pHeaderWriter, GroupVariationID id, QualifierCode_uint8_t qc, uint16_t reserve)
//    GroupVariationID ID_in_DNP3Serializer_for_Binary(DNP3Serializer_for_Binary *pDNP3Serializer_for_Binary)
  if(WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter, ID_in_DNP3Serializer_for_Binary(serializer), qc, reserve_size))
  {
//        return RangeWriteIterator<IndexType, WriteType>(start, serializer, *position);
    RangeWriteIterator_for_UInt8_Binary rRangeWriteIterator_for_UInt8_Binary;
////    void RangeWriteIterator_for_UInt8_Binary_in_RangeWriteIterator_for_UInt8_BinaryOver2(RangeWriteIterator_for_UInt8_Binary *pRangeWriteIterator_for_UInt8_Binary,
//                   typename IndexType::type_t start_,
////                   uint8_t start_,
//                   const Serializer<WriteType>& serializer,
////                   Serializer_for_Binary*  serializer,
//                   ser4cpp::wseq_t& position)
////                   WSeq_for_Uint16_t* position);
    RangeWriteIterator_for_UInt8_Binary_in_RangeWriteIterator_for_UInt8_BinaryOver2(&rRangeWriteIterator_for_UInt8_Binary,
        start,
        &(serializer->sSerializer_for_Binary),
        pHeaderWriter->position
                                                                                   );
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
    return rRangeWriteIterator_for_UInt8_Binary;
  }
  else
  {
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
//        return RangeWriteIterator<IndexType, WriteType>::Null();
    return Null_in_RangeWriteIterator_for_UInt8_Binary_static();
  }
}
//---------------------------------------------IterateOverRange_for_UInt8_Binary_in_HeaderWriter--------------------------------------------
//---------------------------------------------IterateOverRange_for_UInt16_Binary_in_HeaderWriter--------------------------------------------
////template<class IndexType, class WriteType>
////RangeWriteIterator<IndexType, WriteType> HeaderWriter::IterateOverRange(QualifierCode qc,
////                                                                        const DNP3Serializer<WriteType>& serializer,
////                                                                        typename IndexType::type_t start)
RangeWriteIterator_for_UInt16_Binary IterateOverRange_for_UInt16_Binary_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc,
    DNP3Serializer_for_Binary *serializer,
    uint16_t start
                                                                                     )
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"IterateOverRange_for_UInt16_Binary_in_HeaderWriter1"<<'\n';
#endif
//    const auto reserve_size = 2 * IndexType::size + serializer.get_size();
//     pRangeWriteIterator_for_UInt8_Binary->isValid = length_in_HasLength_for_Uint16_t(&(position->hHasLength)) >= 2 * size_in_UInt8;
  uint16_t reserve_size = 2 * size_in_UInt16 +
                          get_size_in_Serializer_for_Binary(&(serializer->sSerializer_for_Binary));

//    if (this->WriteHeaderWithReserve(serializer.ID(), qc, reserve_size))
//boolean WriteHeaderWithReserve_in_HeaderWriter(HeaderWriter *pHeaderWriter, GroupVariationID id, QualifierCode_uint8_t qc, uint16_t reserve)
//    GroupVariationID ID_in_DNP3Serializer_for_Binary(DNP3Serializer_for_Binary *pDNP3Serializer_for_Binary)
  if(WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter, ID_in_DNP3Serializer_for_Binary(serializer), qc, reserve_size))
  {
//        return RangeWriteIterator<IndexType, WriteType>(start, serializer, *position);
    RangeWriteIterator_for_UInt16_Binary rRangeWriteIterator_for_UInt16_Binary;
////    void RangeWriteIterator_for_UInt8_Binary_in_RangeWriteIterator_for_UInt8_BinaryOver2(RangeWriteIterator_for_UInt8_Binary *pRangeWriteIterator_for_UInt8_Binary,
//                   typename IndexType::type_t start_,
////                   uint8_t start_,
//                   const Serializer<WriteType>& serializer,
////                   Serializer_for_Binary*  serializer,
//                   ser4cpp::wseq_t& position)
////                   WSeq_for_Uint16_t* position);
    RangeWriteIterator_for_UInt16_Binary_in_RangeWriteIterator_for_UInt16_BinaryOver2(&rRangeWriteIterator_for_UInt16_Binary,
        start,
        &(serializer->sSerializer_for_Binary),
        pHeaderWriter->position
                                                                                   );
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
    return rRangeWriteIterator_for_UInt16_Binary;
  }
  else
  {
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
//        return RangeWriteIterator<IndexType, WriteType>::Null();
    return Null_in_RangeWriteIterator_for_UInt16_Binary_static();
  }
}
//---------------------------------------------IterateOverRange_for_UInt16_Binary_in_HeaderWriter--------------------------------------------

//---------------------------------------------IterateOverCount_for_UInt8_Binary_in_HeaderWriter--------------------------------------------

CountWriteIterator_for_UInt8_Binary IterateOverCount_for_UInt8_Binary_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc,
    DNP3Serializer_for_Binary* serializer)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"IterateOverCount_for_UInt8_Binary_in_HeaderWriter1"<<'\n';
#endif
////template<class CountType, class WriteType>
////CountWriteIterator<CountType, WriteType> HeaderWriter::IterateOverCount(QualifierCode qc,
////                                                                        const DNP3Serializer<WriteType>& serializer)
////{
////   uint16_t reserve_size = CountType::size + serializer.get_size();
  uint16_t reserve_size = size_in_UInt8 +
                          get_size_in_Serializer_for_Binary(&(serializer->sSerializer_for_Binary));
////    if (this->WriteHeaderWithReserve(serializer.ID(), qc, reserve_size))
  if(WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter, ID_in_DNP3Serializer_for_Binary(serializer), qc, reserve_size))
  {
////        return CountWriteIterator<CountType, WriteType>(serializer, *position);
    CountWriteIterator_for_UInt8_Binary cCountWriteIterator_for_UInt8_Binary;
    CountWriteIterator_for_UInt8_Binary_in_CountWriteIterator_for_UInt8_BinaryOver2(&cCountWriteIterator_for_UInt8_Binary,
        &(serializer->sSerializer_for_Binary),
        pHeaderWriter->position
                                                                                   );
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
    return cCountWriteIterator_for_UInt8_Binary;
  }
  else
  {
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
////        return CountWriteIterator<CountType, WriteType>::Null();
    return Null_in_CountWriteIterator_for_UInt8_Binary_static();
  }
////}
}
//---------------------------------------------IterateOverCount_for_UInt8_Binary_in_HeaderWriter--------------------------------------------
//------------------------------IterateOverCountWithPrefixAndCTO_for_UInt16_Binary_Group51Var1_in_HeaderWriter--------------------------------------------------------
////template<class PrefixType, class WriteType, class CTOType>
////PrefixedWriteIterator<PrefixType, WriteType> HeaderWriter::IterateOverCountWithPrefixAndCTO(
////    QualifierCode qc, const DNP3Serializer<WriteType>& serializer, const CTOType& cto)
PrefixedWriteIterator_for_UInt16_Binary IterateOverCountWithPrefixAndCTO_for_UInt16_Binary_Group51Var1_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc,
    DNP3Serializer_for_Binary* serializer,
    Group51Var1* cto)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"IterateOverCountWithPrefixAndCTO_for_UInt16_Binary_Group51Var1_in_HeaderWriter1"<<'\n';
#endif
////    this->Mark();
  Mark_in_HeaderWriter(pHeaderWriter);
////    if (this->WriteSingleValue<ser4cpp::UInt8, CTOType>(QualifierCode::UINT8_CNT, cto))
  if(WriteSingleValue_for_UInt8_Group51Var1_in_HeaderWriter(pHeaderWriter, QualifierCode_UINT8_CNT, cto))
  {
////        auto iter = IterateOverCountWithPrefix<PrefixType, WriteType>(qc, serializer);
    PrefixedWriteIterator_for_UInt16_Binary iter =
      IterateOverCountWithPrefix_for_UInt16_Binary_in_HeaderWriter(pHeaderWriter, qc, serializer);
////        if (!iter.IsValid())
    if (!IsValid_in_PrefixedWriteIterator_for_UInt16_Binary(&iter))
    {
      // remove the CTO header, if there's no space to write a value
////            this->Rollback();
      Rollback_in_HeaderWriter(pHeaderWriter);
    }
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"IterateOverCountWithPrefixAndCTO_for_UInt16_Binary_Group51Var1_in_HeaderWriter2"<<'\n';
  decrement_stack_info();
#endif
    return iter;
  }
  else
  {
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"IterateOverCountWithPrefixAndCTO_for_UInt16_Binary_Group51Var1_in_HeaderWriter3"<<'\n';
  decrement_stack_info();
#endif
////        return PrefixedWriteIterator<PrefixType, WriteType>::Null();
    return Null_in_PrefixedWriteIterator_for_UInt16_Binary_static();
  }
}
//--------------------------------IterateOverCountWithPrefixAndCTO_for_UInt16_Binary_Group51Var1_in_HeaderWriter--------------------------------------------------------
//------------------------------IterateOverCountWithPrefixAndCTO_for_UInt16_Binary_Group51Var2_in_HeaderWriter--------------------------------------------------------
////template<class PrefixType, class WriteType, class CTOType>
////PrefixedWriteIterator<PrefixType, WriteType> HeaderWriter::IterateOverCountWithPrefixAndCTO(
////    QualifierCode qc, const DNP3Serializer<WriteType>& serializer, const CTOType& cto)
PrefixedWriteIterator_for_UInt16_Binary IterateOverCountWithPrefixAndCTO_for_UInt16_Binary_Group51Var2_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc,
    DNP3Serializer_for_Binary* serializer,
    Group51Var2* cto)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"IterateOverCountWithPrefixAndCTO_for_UInt16_Binary_Group51Var2_in_HeaderWriter1"<<'\n';
#endif
////    this->Mark();
  Mark_in_HeaderWriter(pHeaderWriter);
////    if (this->WriteSingleValue<ser4cpp::UInt8, CTOType>(QualifierCode::UINT8_CNT, cto))
  if(WriteSingleValue_for_UInt8_Group51Var2_in_HeaderWriter(pHeaderWriter, QualifierCode_UINT8_CNT, cto))
  {
////        auto iter = IterateOverCountWithPrefix<PrefixType, WriteType>(qc, serializer);
    PrefixedWriteIterator_for_UInt16_Binary iter =
      IterateOverCountWithPrefix_for_UInt16_Binary_in_HeaderWriter(pHeaderWriter, qc, serializer);
////        if (!iter.IsValid())
    if (!IsValid_in_PrefixedWriteIterator_for_UInt16_Binary(&iter))
    {
      // remove the CTO header, if there's no space to write a value
////            this->Rollback();
      Rollback_in_HeaderWriter(pHeaderWriter);
    }
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
    return iter;
  }
  else
  {
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
////        return PrefixedWriteIterator<PrefixType, WriteType>::Null();
    return Null_in_PrefixedWriteIterator_for_UInt16_Binary_static();
  }
}
//------------------------------IterateOverCountWithPrefixAndCTO_for_UInt16_Binary_Group51Var2_in_HeaderWriter--------------------------------------------------------
//------------------------------IterateOverCountWithPrefix_for_UInt16_Binary_in_HeaderWriter--------------------------------------------------------
PrefixedWriteIterator_for_UInt16_Binary IterateOverCountWithPrefix_for_UInt16_Binary_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc, DNP3Serializer_for_Binary* serializer)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"IterateOverCountWithPrefix_for_UInt16_Binary_in_HeaderWriter1"<<'\n';
#endif
////    const auto reserve_size
  uint16_t reserve_size =
////        = 2 * PrefixType::size + serializer.get_size(); // enough space for the count, 1 prefix + object
    2*size_in_UInt16 +
    get_size_in_Serializer_for_Binary(&(serializer->sSerializer_for_Binary));//Serializer_for_Binary *pSerializer_for_Binary);
////    if (this->WriteHeaderWithReserve(serializer.ID(), qc, reserve_size))
  if(WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter,
      ID_in_DNP3Serializer_for_Binary(serializer), qc, reserve_size))
  {
    PrefixedWriteIterator_for_UInt16_Binary pPrefixedWriteIterator_for_UInt16_Binary;
    PrefixedWriteIterator_for_UInt16_Binary_in_PrefixedWriteIterator_for_UInt16_BinaryOver2(&pPrefixedWriteIterator_for_UInt16_Binary,
        &(serializer->sSerializer_for_Binary), pHeaderWriter->position);

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"IterateOverCountWithPrefix_for_UInt16_Binary_in_HeaderWriter2"<<'\n';
  decrement_stack_info();
#endif
//        return PrefixedWriteIterator<PrefixType, WriteType>(serializer, *position);
    return pPrefixedWriteIterator_for_UInt16_Binary;
  }
  else
  {
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"IterateOverCountWithPrefix_for_UInt16_Binary_in_HeaderWriter3"<<'\n';
  decrement_stack_info();
#endif
////        return PrefixedWriteIterator<PrefixType, WriteType>::Null();
    return Null_in_PrefixedWriteIterator_for_UInt16_Binary_static();
  }
}
//------------------------------IterateOverCountWithPrefix_for_UInt16_Binary_in_HeaderWriter--------------------------------------------------------

