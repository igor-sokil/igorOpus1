#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "HeaderWriter_for_FrozenCounter.h"

//---------------------------------------------IterateOverRange_for_UInt8_FrozenCounter_in_HeaderWriter--------------------------------------------
////template<class IndexType, class WriteType>
////RangeWriteIterator<IndexType, WriteType> HeaderWriter::IterateOverRange(QualifierCode qc,
////                                                                        const DNP3Serializer<WriteType>& serializer,
////                                                                        typename IndexType::type_t start)
RangeWriteIterator_for_UInt8_FrozenCounter IterateOverRange_for_UInt8_FrozenCounter_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc,
    DNP3Serializer_for_FrozenCounter *serializer,
    uint8_t start
                                                                                     )
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"{IterateOverRange_for_UInt8_FrozenCounter_in_HeaderWriter1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*QualifierCode_uint8_t qc= "<<(uint16_t)qc<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*uint8_t start= "<<(uint16_t)start<<'\n';
#endif
//    const auto reserve_size = 2 * IndexType::size + serializer.get_size();
//     pRangeWriteIterator_for_UInt8_FrozenCounter->isValid = length_in_HasLength_for_Uint16_t(&(position->hHasLength)) >= 2 * size_in_UInt8;
  uint16_t reserve_size = 2 * size_in_UInt8 +
                          get_size_in_Serializer_for_FrozenCounter(&(serializer->sSerializer_for_FrozenCounter));

//    if (this->WriteHeaderWithReserve(serializer.ID(), qc, reserve_size))
//boolean WriteHeaderWithReserve_in_HeaderWriter(HeaderWriter *pHeaderWriter, GroupVariationID id, QualifierCode_uint8_t qc, uint16_t reserve)
//    GroupVariationID ID_in_DNP3Serializer_for_FrozenCounter(DNP3Serializer_for_FrozenCounter *pDNP3Serializer_for_FrozenCounter)
  if(WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter, ID_in_DNP3Serializer_for_FrozenCounter(serializer), qc, reserve_size))
  {
//        return RangeWriteIterator<IndexType, WriteType>(start, serializer, *position);
    RangeWriteIterator_for_UInt8_FrozenCounter rRangeWriteIterator_for_UInt8_FrozenCounter;
////    void RangeWriteIterator_for_UInt8_FrozenCounter_in_RangeWriteIterator_for_UInt8_FrozenCounterOver2(RangeWriteIterator_for_UInt8_FrozenCounter *pRangeWriteIterator_for_UInt8_FrozenCounter,
//                   typename IndexType::type_t start_,
////                   uint8_t start_,
//                   const Serializer<WriteType>& serializer,
////                   Serializer_for_FrozenCounter*  serializer,
//                   ser4cpp::wseq_t& position)
////                   WSeq_for_Uint16_t* position);
    RangeWriteIterator_for_UInt8_FrozenCounter_in_RangeWriteIterator_for_UInt8_FrozenCounterOver2(&rRangeWriteIterator_for_UInt8_FrozenCounter,
        start,
        &(serializer->sSerializer_for_FrozenCounter),
        pHeaderWriter->position
                                                                                   );
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}IterateOverRange_for_UInt8_FrozenCounter_in_HeaderWriter1_"<<'\n';
  decrement_stack_info();
#endif
    return rRangeWriteIterator_for_UInt8_FrozenCounter;
  }
  else
  {
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}IterateOverRange_for_UInt8_FrozenCounter_in_HeaderWriter2_"<<'\n';
  decrement_stack_info();
#endif
//        return RangeWriteIterator<IndexType, WriteType>::Null();
    return Null_in_RangeWriteIterator_for_UInt8_FrozenCounter_static();
  }
}
//---------------------------------------------IterateOverRange_for_UInt8_FrozenCounter_in_HeaderWriter--------------------------------------------
//---------------------------------------------IterateOverRange_for_UInt16_FrozenCounter_in_HeaderWriter--------------------------------------------
////template<class IndexType, class WriteType>
////RangeWriteIterator<IndexType, WriteType> HeaderWriter::IterateOverRange(QualifierCode qc,
////                                                                        const DNP3Serializer<WriteType>& serializer,
////                                                                        typename IndexType::type_t start)
RangeWriteIterator_for_UInt16_FrozenCounter IterateOverRange_for_UInt16_FrozenCounter_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc,
    DNP3Serializer_for_FrozenCounter *serializer,
    uint16_t start
                                                                                     )
{
//    const auto reserve_size = 2 * IndexType::size + serializer.get_size();
//     pRangeWriteIterator_for_UInt8_FrozenCounter->isValid = length_in_HasLength_for_Uint16_t(&(position->hHasLength)) >= 2 * size_in_UInt8;
  uint16_t reserve_size = 2 * size_in_UInt16 +
                          get_size_in_Serializer_for_FrozenCounter(&(serializer->sSerializer_for_FrozenCounter));

//    if (this->WriteHeaderWithReserve(serializer.ID(), qc, reserve_size))
//boolean WriteHeaderWithReserve_in_HeaderWriter(HeaderWriter *pHeaderWriter, GroupVariationID id, QualifierCode_uint8_t qc, uint16_t reserve)
//    GroupVariationID ID_in_DNP3Serializer_for_FrozenCounter(DNP3Serializer_for_FrozenCounter *pDNP3Serializer_for_FrozenCounter)
  if(WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter, ID_in_DNP3Serializer_for_FrozenCounter(serializer), qc, reserve_size))
  {
//        return RangeWriteIterator<IndexType, WriteType>(start, serializer, *position);
    RangeWriteIterator_for_UInt16_FrozenCounter rRangeWriteIterator_for_UInt16_FrozenCounter;
////    void RangeWriteIterator_for_UInt8_FrozenCounter_in_RangeWriteIterator_for_UInt8_FrozenCounterOver2(RangeWriteIterator_for_UInt8_FrozenCounter *pRangeWriteIterator_for_UInt8_FrozenCounter,
//                   typename IndexType::type_t start_,
////                   uint8_t start_,
//                   const Serializer<WriteType>& serializer,
////                   Serializer_for_FrozenCounter*  serializer,
//                   ser4cpp::wseq_t& position)
////                   WSeq_for_Uint16_t* position);
    RangeWriteIterator_for_UInt16_FrozenCounter_in_RangeWriteIterator_for_UInt16_FrozenCounterOver2(&rRangeWriteIterator_for_UInt16_FrozenCounter,
        start,
        &(serializer->sSerializer_for_FrozenCounter),
        pHeaderWriter->position
                                                                                   );
    return rRangeWriteIterator_for_UInt16_FrozenCounter;
  }
  else
  {
//        return RangeWriteIterator<IndexType, WriteType>::Null();
    return Null_in_RangeWriteIterator_for_UInt16_FrozenCounter_static();
  }
}
//---------------------------------------------IterateOverRange_for_UInt16_FrozenCounter_in_HeaderWriter--------------------------------------------
//---------------------------------------------IterateOverCount_for_UInt16_FrozenCounter_in_HeaderWriter--------------------------------------------

CountWriteIterator_for_UInt16_FrozenCounter IterateOverCount_for_UInt16_FrozenCounter_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc,
    DNP3Serializer_for_FrozenCounter* serializer)
{
////template<class CountType, class WriteType>
////CountWriteIterator<CountType, WriteType> HeaderWriter::IterateOverCount(QualifierCode qc,
////                                                                        const DNP3Serializer<WriteType>& serializer)
////{
////   uint16_t reserve_size = CountType::size + serializer.get_size();
  uint16_t reserve_size = size_in_UInt16 +
                          get_size_in_Serializer_for_FrozenCounter(&(serializer->sSerializer_for_FrozenCounter));
////    if (this->WriteHeaderWithReserve(serializer.ID(), qc, reserve_size))
  if(WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter, ID_in_DNP3Serializer_for_FrozenCounter(serializer), qc, reserve_size))
  {
////        return CountWriteIterator<CountType, WriteType>(serializer, *position);
    CountWriteIterator_for_UInt16_FrozenCounter cCountWriteIterator_for_UInt16_FrozenCounter;
    CountWriteIterator_for_UInt16_FrozenCounter_in_CountWriteIterator_for_UInt16_FrozenCounterOver2(&cCountWriteIterator_for_UInt16_FrozenCounter,
        &(serializer->sSerializer_for_FrozenCounter),
        pHeaderWriter->position
                                                                                     );
    return cCountWriteIterator_for_UInt16_FrozenCounter;
  }
  else
  {
////        return CountWriteIterator<CountType, WriteType>::Null();
    return Null_in_CountWriteIterator_for_UInt16_FrozenCounter_static();
  }
////}
}
//---------------------------------------------IterateOverCount_for_UInt16_FrozenCounter_in_HeaderWriter--------------------------------------------
//---------------------------------------------IterateOverCount_for_UInt8_FrozenCounter_in_HeaderWriter--------------------------------------------

CountWriteIterator_for_UInt8_FrozenCounter IterateOverCount_for_UInt8_FrozenCounter_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc,
    DNP3Serializer_for_FrozenCounter* serializer)
{
////template<class CountType, class WriteType>
////CountWriteIterator<CountType, WriteType> HeaderWriter::IterateOverCount(QualifierCode qc,
////                                                                        const DNP3Serializer<WriteType>& serializer)
////{
////   uint16_t reserve_size = CountType::size + serializer.get_size();
  uint16_t reserve_size = size_in_UInt8 +
                          get_size_in_Serializer_for_FrozenCounter(&(serializer->sSerializer_for_FrozenCounter));
////    if (this->WriteHeaderWithReserve(serializer.ID(), qc, reserve_size))
  if(WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter, ID_in_DNP3Serializer_for_FrozenCounter(serializer), qc, reserve_size))
  {
////        return CountWriteIterator<CountType, WriteType>(serializer, *position);
    CountWriteIterator_for_UInt8_FrozenCounter cCountWriteIterator_for_UInt8_FrozenCounter;
    CountWriteIterator_for_UInt8_FrozenCounter_in_CountWriteIterator_for_UInt8_FrozenCounterOver2(&cCountWriteIterator_for_UInt8_FrozenCounter,
        &(serializer->sSerializer_for_FrozenCounter),
        pHeaderWriter->position
                                                                                   );
    return cCountWriteIterator_for_UInt8_FrozenCounter;
  }
  else
  {
////        return CountWriteIterator<CountType, WriteType>::Null();
    return Null_in_CountWriteIterator_for_UInt8_FrozenCounter_static();
  }
////}
}
//---------------------------------------------IterateOverCount_for_UInt8_FrozenCounter_in_HeaderWriter--------------------------------------------
//------------------------------IterateOverCountWithPrefix_for_UInt16_FrozenCounter_in_HeaderWriter--------------------------------------------------------
PrefixedWriteIterator_for_UInt16_FrozenCounter IterateOverCountWithPrefix_for_UInt16_FrozenCounter_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc, DNP3Serializer_for_FrozenCounter* serializer)
{
////    const auto reserve_size
  uint16_t reserve_size =
////        = 2 * PrefixType::size + serializer.get_size(); // enough space for the count, 1 prefix + object
    2*size_in_UInt16 +
    get_size_in_Serializer_for_FrozenCounter(&(serializer->sSerializer_for_FrozenCounter));
////    if (this->WriteHeaderWithReserve(serializer.ID(), qc, reserve_size))
  if(WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter,
      ID_in_DNP3Serializer_for_FrozenCounter(serializer), qc, reserve_size))
  {
    PrefixedWriteIterator_for_UInt16_FrozenCounter pPrefixedWriteIterator_for_UInt16_FrozenCounter;
    PrefixedWriteIterator_for_UInt16_FrozenCounter_in_PrefixedWriteIterator_for_UInt16_FrozenCounterOver2(&pPrefixedWriteIterator_for_UInt16_FrozenCounter,
        &(serializer->sSerializer_for_FrozenCounter), pHeaderWriter->position);
//        return PrefixedWriteIterator<PrefixType, WriteType>(serializer, *position);
    return pPrefixedWriteIterator_for_UInt16_FrozenCounter;
  }
  else
  {
////        return PrefixedWriteIterator<PrefixType, WriteType>::Null();
    return Null_in_PrefixedWriteIterator_for_UInt16_FrozenCounter_static();
  }
}
//------------------------------IterateOverCountWithPrefix_for_UInt16_FrozenCounter_in_HeaderWriter--------------------------------------------------------
//------------------------------IterateOverCountWithPrefixAndCTO_for_UInt16_FrozenCounter_Group51Var1_in_HeaderWriter--------------------------------------------------------
////template<class PrefixType, class WriteType, class CTOType>
////PrefixedWriteIterator<PrefixType, WriteType> HeaderWriter::IterateOverCountWithPrefixAndCTO(
////    QualifierCode qc, const DNP3Serializer<WriteType>& serializer, const CTOType& cto)
PrefixedWriteIterator_for_UInt16_FrozenCounter IterateOverCountWithPrefixAndCTO_for_UInt16_FrozenCounter_Group51Var1_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc,
    DNP3Serializer_for_FrozenCounter* serializer,
    Group51Var1* cto)
{
////    this->Mark();
  Mark_in_HeaderWriter(pHeaderWriter);
////    if (this->WriteSingleValue<ser4cpp::UInt8, CTOType>(QualifierCode::UINT8_CNT, cto))
  if(WriteSingleValue_for_UInt8_Group51Var1_in_HeaderWriter(pHeaderWriter, QualifierCode_UINT8_CNT, cto))
  {
////        auto iter = IterateOverCountWithPrefix<PrefixType, WriteType>(qc, serializer);
    PrefixedWriteIterator_for_UInt16_FrozenCounter iter =
      IterateOverCountWithPrefix_for_UInt16_FrozenCounter_in_HeaderWriter(pHeaderWriter, qc, serializer);
////        if (!iter.IsValid())
    if (!IsValid_in_PrefixedWriteIterator_for_UInt16_FrozenCounter(&iter))
    {
      // remove the CTO header, if there's no space to write a value
////            this->Rollback();
      Rollback_in_HeaderWriter(pHeaderWriter);
    }
    return iter;
  }
  else
  {
////        return PrefixedWriteIterator<PrefixType, WriteType>::Null();
    return Null_in_PrefixedWriteIterator_for_UInt16_FrozenCounter_static();
  }
}
//--------------------------------IterateOverCountWithPrefixAndCTO_for_UInt16_FrozenCounter_Group51Var1_in_HeaderWriter--------------------------------------------------------
//------------------------------IterateOverCountWithPrefixAndCTO_for_UInt16_FrozenCounter_Group51Var2_in_HeaderWriter--------------------------------------------------------
////template<class PrefixType, class WriteType, class CTOType>
////PrefixedWriteIterator<PrefixType, WriteType> HeaderWriter::IterateOverCountWithPrefixAndCTO(
////    QualifierCode qc, const DNP3Serializer<WriteType>& serializer, const CTOType& cto)
PrefixedWriteIterator_for_UInt16_FrozenCounter IterateOverCountWithPrefixAndCTO_for_UInt16_FrozenCounter_Group51Var2_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc,
    DNP3Serializer_for_FrozenCounter* serializer,
    Group51Var2* cto)
{
////    this->Mark();
  Mark_in_HeaderWriter(pHeaderWriter);
////    if (this->WriteSingleValue<ser4cpp::UInt8, CTOType>(QualifierCode::UINT8_CNT, cto))
  if(WriteSingleValue_for_UInt8_Group51Var2_in_HeaderWriter(pHeaderWriter, QualifierCode_UINT8_CNT, cto))
  {
////        auto iter = IterateOverCountWithPrefix<PrefixType, WriteType>(qc, serializer);
    PrefixedWriteIterator_for_UInt16_FrozenCounter iter =
      IterateOverCountWithPrefix_for_UInt16_FrozenCounter_in_HeaderWriter(pHeaderWriter, qc, serializer);
////        if (!iter.IsValid())
    if (!IsValid_in_PrefixedWriteIterator_for_UInt16_FrozenCounter(&iter))
    {
      // remove the CTO header, if there's no space to write a value
////            this->Rollback();
      Rollback_in_HeaderWriter(pHeaderWriter);
    }
    return iter;
  }
  else
  {
////        return PrefixedWriteIterator<PrefixType, WriteType>::Null();
    return Null_in_PrefixedWriteIterator_for_UInt16_FrozenCounter_static();
  }
}
//------------------------------IterateOverCountWithPrefixAndCTO_for_UInt16_FrozenCounter_Group51Var2_in_HeaderWriter--------------------------------------------------------
