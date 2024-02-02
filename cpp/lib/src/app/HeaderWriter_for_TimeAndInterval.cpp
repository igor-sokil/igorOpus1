#include "header.h"
#include "HeaderWriter_for_TimeAndInterval.h"

////template<class CountType, class ValueType>
////bool HeaderWriter::WriteSingleIndexedValue(QualifierCode qc,
////                                           const DNP3Serializer<ValueType>& serializer,
////                                           const ValueType& value,
////                                           typename CountType::type_t index)
boolean WriteSingleIndexedValue_for_UInt16_TimeAndInterval_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc,
    DNP3Serializer_for_TimeAndInterval* serializer,
    TimeAndInterval* value,
    uint16_t index)
{
////    const auto reserve_size = 2 * CountType::size + serializer.get_size();
  uint16_t reserve_size = size_in_UInt16 +
                          get_size_in_Serializer_for_TimeAndInterval(&(serializer->sSerializer_for_TimeAndInterval));

////    if (this->WriteHeaderWithReserve(serializer.ID(), qc, reserve_size))
  if(WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter, ID_in_DNP3Serializer_for_TimeAndInterval(serializer), qc, reserve_size))
  {
//boolean write_to_in_UInt16_static(WSeq_for_Uint16_t *dest, uint16_t value);
////        CountType::write_to(*position, 1);     // write the count
    write_to_in_UInt16_static(pHeaderWriter->position, 1);     // write the count
////        CountType::write_to(*position, index); // write the index
    write_to_in_UInt16_static(pHeaderWriter->position, index); // write the index

//boolean write_in_Serializer_for_TimeAndInterval(Serializer_for_TimeAndInterval *pSerializer_for_TimeAndInterval, TimeAndInterval *value, WSeq_for_Uint16_t *buffer);
////        serializer.write(value, *position);
    write_in_Serializer_for_TimeAndInterval(&(serializer->sSerializer_for_TimeAndInterval), value, pHeaderWriter->position);
    return true;
  }
  else
    return false;
}
//---------------------------------------------IterateOverRange_for_UInt8_TimeAndInterval_in_HeaderWriter--------------------------------------------
////template<class IndexType, class WriteType>
////RangeWriteIterator<IndexType, WriteType> HeaderWriter::IterateOverRange(QualifierCode qc,
////                                                                        const DNP3Serializer<WriteType>& serializer,
////                                                                        typename IndexType::type_t start)
RangeWriteIterator_for_UInt8_TimeAndInterval IterateOverRange_for_UInt8_TimeAndInterval_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc,
    DNP3Serializer_for_TimeAndInterval *serializer,
    uint8_t start
                                                                                     )
{
//    const auto reserve_size = 2 * IndexType::size + serializer.get_size();
//     pRangeWriteIterator_for_UInt8_TimeAndInterval->isValid = length_in_HasLength_for_Uint16_t(&(position->hHasLength)) >= 2 * size_in_UInt8;
  uint16_t reserve_size = 2 * size_in_UInt8 +
                          get_size_in_Serializer_for_TimeAndInterval(&(serializer->sSerializer_for_TimeAndInterval));

//    if (this->WriteHeaderWithReserve(serializer.ID(), qc, reserve_size))
//boolean WriteHeaderWithReserve_in_HeaderWriter(HeaderWriter *pHeaderWriter, GroupVariationID id, QualifierCode_uint8_t qc, uint16_t reserve)
//    GroupVariationID ID_in_DNP3Serializer_for_TimeAndInterval(DNP3Serializer_for_TimeAndInterval *pDNP3Serializer_for_TimeAndInterval)
  if(WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter, ID_in_DNP3Serializer_for_TimeAndInterval(serializer), qc, reserve_size))
  {
//        return RangeWriteIterator<IndexType, WriteType>(start, serializer, *position);
    RangeWriteIterator_for_UInt8_TimeAndInterval rRangeWriteIterator_for_UInt8_TimeAndInterval;
////    void RangeWriteIterator_for_UInt8_TimeAndInterval_in_RangeWriteIterator_for_UInt8_TimeAndIntervalOver2(RangeWriteIterator_for_UInt8_TimeAndInterval *pRangeWriteIterator_for_UInt8_TimeAndInterval,
//                   typename IndexType::type_t start_,
////                   uint8_t start_,
//                   const Serializer<WriteType>& serializer,
////                   Serializer_for_TimeAndInterval*  serializer,
//                   ser4cpp::wseq_t& position)
////                   WSeq_for_Uint16_t* position);
    RangeWriteIterator_for_UInt8_TimeAndInterval_in_RangeWriteIterator_for_UInt8_TimeAndIntervalOver2(&rRangeWriteIterator_for_UInt8_TimeAndInterval,
        start,
        &(serializer->sSerializer_for_TimeAndInterval),
        pHeaderWriter->position
                                                                                   );
    return rRangeWriteIterator_for_UInt8_TimeAndInterval;
  }
  else
  {
//        return RangeWriteIterator<IndexType, WriteType>::Null();
    return Null_in_RangeWriteIterator_for_UInt8_TimeAndInterval_static();
  }
}
//---------------------------------------------IterateOverRange_for_UInt8_TimeAndInterval_in_HeaderWriter--------------------------------------------
//---------------------------------------------IterateOverRange_for_UInt16_TimeAndInterval_in_HeaderWriter--------------------------------------------
////template<class IndexType, class WriteType>
////RangeWriteIterator<IndexType, WriteType> HeaderWriter::IterateOverRange(QualifierCode qc,
////                                                                        const DNP3Serializer<WriteType>& serializer,
////                                                                        typename IndexType::type_t start)
RangeWriteIterator_for_UInt16_TimeAndInterval IterateOverRange_for_UInt16_TimeAndInterval_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc,
    DNP3Serializer_for_TimeAndInterval *serializer,
    uint16_t start
                                                                                     )
{
//    const auto reserve_size = 2 * IndexType::size + serializer.get_size();
//     pRangeWriteIterator_for_UInt8_TimeAndInterval->isValid = length_in_HasLength_for_Uint16_t(&(position->hHasLength)) >= 2 * size_in_UInt8;
  uint16_t reserve_size = 2 * size_in_UInt16 +
                          get_size_in_Serializer_for_TimeAndInterval(&(serializer->sSerializer_for_TimeAndInterval));

//    if (this->WriteHeaderWithReserve(serializer.ID(), qc, reserve_size))
//boolean WriteHeaderWithReserve_in_HeaderWriter(HeaderWriter *pHeaderWriter, GroupVariationID id, QualifierCode_uint8_t qc, uint16_t reserve)
//    GroupVariationID ID_in_DNP3Serializer_for_TimeAndInterval(DNP3Serializer_for_TimeAndInterval *pDNP3Serializer_for_TimeAndInterval)
  if(WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter, ID_in_DNP3Serializer_for_TimeAndInterval(serializer), qc, reserve_size))
  {
//        return RangeWriteIterator<IndexType, WriteType>(start, serializer, *position);
    RangeWriteIterator_for_UInt16_TimeAndInterval rRangeWriteIterator_for_UInt16_TimeAndInterval;
////    void RangeWriteIterator_for_UInt8_TimeAndInterval_in_RangeWriteIterator_for_UInt8_TimeAndIntervalOver2(RangeWriteIterator_for_UInt8_TimeAndInterval *pRangeWriteIterator_for_UInt8_TimeAndInterval,
//                   typename IndexType::type_t start_,
////                   uint8_t start_,
//                   const Serializer<WriteType>& serializer,
////                   Serializer_for_TimeAndInterval*  serializer,
//                   ser4cpp::wseq_t& position)
////                   WSeq_for_Uint16_t* position);
    RangeWriteIterator_for_UInt16_TimeAndInterval_in_RangeWriteIterator_for_UInt16_TimeAndIntervalOver2(&rRangeWriteIterator_for_UInt16_TimeAndInterval,
        start,
        &(serializer->sSerializer_for_TimeAndInterval),
        pHeaderWriter->position
                                                                                   );
    return rRangeWriteIterator_for_UInt16_TimeAndInterval;
  }
  else
  {
//        return RangeWriteIterator<IndexType, WriteType>::Null();
    return Null_in_RangeWriteIterator_for_UInt16_TimeAndInterval_static();
  }
}
//---------------------------------------------IterateOverRange_for_UInt16_TimeAndInterval_in_HeaderWriter--------------------------------------------
//---------------------------------------------IterateOverCount_for_UInt16_TimeAndInterval_in_HeaderWriter--------------------------------------------

CountWriteIterator_for_UInt16_TimeAndInterval IterateOverCount_for_UInt16_TimeAndInterval_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc,
    DNP3Serializer_for_TimeAndInterval* serializer)
{
////template<class CountType, class WriteType>
////CountWriteIterator<CountType, WriteType> HeaderWriter::IterateOverCount(QualifierCode qc,
////                                                                        const DNP3Serializer<WriteType>& serializer)
////{
////   uint16_t reserve_size = CountType::size + serializer.get_size();
  uint16_t reserve_size = size_in_UInt16 +
                          get_size_in_Serializer_for_TimeAndInterval(&(serializer->sSerializer_for_TimeAndInterval));
////    if (this->WriteHeaderWithReserve(serializer.ID(), qc, reserve_size))
  if(WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter, ID_in_DNP3Serializer_for_TimeAndInterval(serializer), qc, reserve_size))
  {
////        return CountWriteIterator<CountType, WriteType>(serializer, *position);
    CountWriteIterator_for_UInt16_TimeAndInterval cCountWriteIterator_for_UInt16_TimeAndInterval;
    CountWriteIterator_for_UInt16_TimeAndInterval_in_CountWriteIterator_for_UInt16_TimeAndIntervalOver2(&cCountWriteIterator_for_UInt16_TimeAndInterval,
        &(serializer->sSerializer_for_TimeAndInterval),
        pHeaderWriter->position
                                                                                     );
    return cCountWriteIterator_for_UInt16_TimeAndInterval;
  }
  else
  {
////        return CountWriteIterator<CountType, WriteType>::Null();
    return Null_in_CountWriteIterator_for_UInt16_TimeAndInterval_static();
  }
////}
}
//---------------------------------------------IterateOverCount_for_UInt16_TimeAndInterval_in_HeaderWriter--------------------------------------------
//---------------------------------------------IterateOverCount_for_UInt8_TimeAndInterval_in_HeaderWriter--------------------------------------------

CountWriteIterator_for_UInt8_TimeAndInterval IterateOverCount_for_UInt8_TimeAndInterval_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc,
    DNP3Serializer_for_TimeAndInterval* serializer)
{
////template<class CountType, class WriteType>
////CountWriteIterator<CountType, WriteType> HeaderWriter::IterateOverCount(QualifierCode qc,
////                                                                        const DNP3Serializer<WriteType>& serializer)
////{
////   uint16_t reserve_size = CountType::size + serializer.get_size();
  uint16_t reserve_size = size_in_UInt8 +
                          get_size_in_Serializer_for_TimeAndInterval(&(serializer->sSerializer_for_TimeAndInterval));
////    if (this->WriteHeaderWithReserve(serializer.ID(), qc, reserve_size))
  if(WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter, ID_in_DNP3Serializer_for_TimeAndInterval(serializer), qc, reserve_size))
  {
////        return CountWriteIterator<CountType, WriteType>(serializer, *position);
    CountWriteIterator_for_UInt8_TimeAndInterval cCountWriteIterator_for_UInt8_TimeAndInterval;
    CountWriteIterator_for_UInt8_TimeAndInterval_in_CountWriteIterator_for_UInt8_TimeAndIntervalOver2(&cCountWriteIterator_for_UInt8_TimeAndInterval,
        &(serializer->sSerializer_for_TimeAndInterval),
        pHeaderWriter->position
                                                                                   );
    return cCountWriteIterator_for_UInt8_TimeAndInterval;
  }
  else
  {
////        return CountWriteIterator<CountType, WriteType>::Null();
    return Null_in_CountWriteIterator_for_UInt8_TimeAndInterval_static();
  }
////}
}
//---------------------------------------------IterateOverCount_for_UInt8_TimeAndInterval_in_HeaderWriter--------------------------------------------
//------------------------------IterateOverCountWithPrefix_for_UInt16_TimeAndInterval_in_HeaderWriter--------------------------------------------------------
PrefixedWriteIterator_for_UInt16_TimeAndInterval IterateOverCountWithPrefix_for_UInt16_TimeAndInterval_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc, DNP3Serializer_for_TimeAndInterval* serializer)
{
////    const auto reserve_size
  uint16_t reserve_size =
////        = 2 * PrefixType::size + serializer.get_size(); // enough space for the count, 1 prefix + object
    2*size_in_UInt16 +
    get_size_in_Serializer_for_TimeAndInterval(&(serializer->sSerializer_for_TimeAndInterval));
////    if (this->WriteHeaderWithReserve(serializer.ID(), qc, reserve_size))
  if(WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter,
      ID_in_DNP3Serializer_for_TimeAndInterval(serializer), qc, reserve_size))
  {
    PrefixedWriteIterator_for_UInt16_TimeAndInterval pPrefixedWriteIterator_for_UInt16_TimeAndInterval;
    PrefixedWriteIterator_for_UInt16_TimeAndInterval_in_PrefixedWriteIterator_for_UInt16_TimeAndIntervalOver2(&pPrefixedWriteIterator_for_UInt16_TimeAndInterval,
        &(serializer->sSerializer_for_TimeAndInterval), pHeaderWriter->position);
//        return PrefixedWriteIterator<PrefixType, WriteType>(serializer, *position);
    return pPrefixedWriteIterator_for_UInt16_TimeAndInterval;
  }
  else
  {
////        return PrefixedWriteIterator<PrefixType, WriteType>::Null();
    return Null_in_PrefixedWriteIterator_for_UInt16_TimeAndInterval_static();
  }
}
//------------------------------IterateOverCountWithPrefix_for_UInt16_TimeAndInterval_in_HeaderWriter--------------------------------------------------------
//------------------------------IterateOverCountWithPrefixAndCTO_for_UInt16_TimeAndInterval_Group51Var1_in_HeaderWriter--------------------------------------------------------
////template<class PrefixType, class WriteType, class CTOType>
////PrefixedWriteIterator<PrefixType, WriteType> HeaderWriter::IterateOverCountWithPrefixAndCTO(
////    QualifierCode qc, const DNP3Serializer<WriteType>& serializer, const CTOType& cto)
PrefixedWriteIterator_for_UInt16_TimeAndInterval IterateOverCountWithPrefixAndCTO_for_UInt16_TimeAndInterval_Group51Var1_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc,
    DNP3Serializer_for_TimeAndInterval* serializer,
    Group51Var1* cto)
{
////    this->Mark();
  Mark_in_HeaderWriter(pHeaderWriter);
////    if (this->WriteSingleValue<ser4cpp::UInt8, CTOType>(QualifierCode::UINT8_CNT, cto))
  if(WriteSingleValue_for_UInt8_Group51Var1_in_HeaderWriter(pHeaderWriter, QualifierCode_UINT8_CNT, cto))
  {
////        auto iter = IterateOverCountWithPrefix<PrefixType, WriteType>(qc, serializer);
    PrefixedWriteIterator_for_UInt16_TimeAndInterval iter =
      IterateOverCountWithPrefix_for_UInt16_TimeAndInterval_in_HeaderWriter(pHeaderWriter, qc, serializer);
////        if (!iter.IsValid())
    if (!IsValid_in_PrefixedWriteIterator_for_UInt16_TimeAndInterval(&iter))
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
    return Null_in_PrefixedWriteIterator_for_UInt16_TimeAndInterval_static();
  }
}
//--------------------------------IterateOverCountWithPrefixAndCTO_for_UInt16_TimeAndInterval_Group51Var1_in_HeaderWriter--------------------------------------------------------
//------------------------------IterateOverCountWithPrefixAndCTO_for_UInt16_TimeAndInterval_Group51Var2_in_HeaderWriter--------------------------------------------------------
////template<class PrefixType, class WriteType, class CTOType>
////PrefixedWriteIterator<PrefixType, WriteType> HeaderWriter::IterateOverCountWithPrefixAndCTO(
////    QualifierCode qc, const DNP3Serializer<WriteType>& serializer, const CTOType& cto)
PrefixedWriteIterator_for_UInt16_TimeAndInterval IterateOverCountWithPrefixAndCTO_for_UInt16_TimeAndInterval_Group51Var2_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc,
    DNP3Serializer_for_TimeAndInterval* serializer,
    Group51Var2* cto)
{
////    this->Mark();
  Mark_in_HeaderWriter(pHeaderWriter);
////    if (this->WriteSingleValue<ser4cpp::UInt8, CTOType>(QualifierCode::UINT8_CNT, cto))
  if(WriteSingleValue_for_UInt8_Group51Var2_in_HeaderWriter(pHeaderWriter, QualifierCode_UINT8_CNT, cto))
  {
////        auto iter = IterateOverCountWithPrefix<PrefixType, WriteType>(qc, serializer);
    PrefixedWriteIterator_for_UInt16_TimeAndInterval iter =
      IterateOverCountWithPrefix_for_UInt16_TimeAndInterval_in_HeaderWriter(pHeaderWriter, qc, serializer);
////        if (!iter.IsValid())
    if (!IsValid_in_PrefixedWriteIterator_for_UInt16_TimeAndInterval(&iter))
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
    return Null_in_PrefixedWriteIterator_for_UInt16_TimeAndInterval_static();
  }
}
//------------------------------IterateOverCountWithPrefixAndCTO_for_UInt16_TimeAndInterval_Group51Var2_in_HeaderWriter--------------------------------------------------------
