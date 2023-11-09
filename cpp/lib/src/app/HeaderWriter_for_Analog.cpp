#include "header.h"
#include "HeaderWriter_for_Analog.h"

//---------------------------------------------IterateOverRange_for_UInt8_Analog_in_HeaderWriter--------------------------------------------
////template<class IndexType, class WriteType>
////RangeWriteIterator<IndexType, WriteType> HeaderWriter::IterateOverRange(QualifierCode qc,
////                                                                        const DNP3Serializer<WriteType>& serializer,
////                                                                        typename IndexType::type_t start)
RangeWriteIterator_for_UInt8_Analog IterateOverRange_for_UInt8_Analog_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc,
    DNP3Serializer_for_Analog *serializer,
    uint8_t start
                                                                                     )
{
//    const auto reserve_size = 2 * IndexType::size + serializer.get_size();
//     pRangeWriteIterator_for_UInt8_Analog->isValid = length_in_HasLength_for_Uint16_t(&(position->hHasLength)) >= 2 * size_in_UInt8;
  uint16_t reserve_size = 2 * size_in_UInt8 +
                          get_size_in_Serializer_for_Analog(&(serializer->sSerializer_for_Analog));

//    if (this->WriteHeaderWithReserve(serializer.ID(), qc, reserve_size))
//boolean WriteHeaderWithReserve_in_HeaderWriter(HeaderWriter *pHeaderWriter, GroupVariationID id, QualifierCode_uint8_t qc, uint16_t reserve)
//    GroupVariationID ID_in_DNP3Serializer_for_Analog(DNP3Serializer_for_Analog *pDNP3Serializer_for_Analog)
  if(WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter, ID_in_DNP3Serializer_for_Analog(serializer), qc, reserve_size))
  {
//        return RangeWriteIterator<IndexType, WriteType>(start, serializer, *position);
    RangeWriteIterator_for_UInt8_Analog rRangeWriteIterator_for_UInt8_Analog;
////    void RangeWriteIterator_for_UInt8_Analog_in_RangeWriteIterator_for_UInt8_AnalogOver2(RangeWriteIterator_for_UInt8_Analog *pRangeWriteIterator_for_UInt8_Analog,
//                   typename IndexType::type_t start_,
////                   uint8_t start_,
//                   const Serializer<WriteType>& serializer,
////                   Serializer_for_Analog*  serializer,
//                   ser4cpp::wseq_t& position)
////                   WSeq_for_Uint16_t* position);
    RangeWriteIterator_for_UInt8_Analog_in_RangeWriteIterator_for_UInt8_AnalogOver2(&rRangeWriteIterator_for_UInt8_Analog,
        start,
        &(serializer->sSerializer_for_Analog),
        pHeaderWriter->position
                                                                                   );
    return rRangeWriteIterator_for_UInt8_Analog;
  }
  else
  {
//        return RangeWriteIterator<IndexType, WriteType>::Null();
    return Null_in_RangeWriteIterator_for_UInt8_Analog_static();
  }
}
//---------------------------------------------IterateOverRange_for_UInt8_Analog_in_HeaderWriter--------------------------------------------
//---------------------------------------------IterateOverRange_for_UInt16_Analog_in_HeaderWriter--------------------------------------------
////template<class IndexType, class WriteType>
////RangeWriteIterator<IndexType, WriteType> HeaderWriter::IterateOverRange(QualifierCode qc,
////                                                                        const DNP3Serializer<WriteType>& serializer,
////                                                                        typename IndexType::type_t start)
RangeWriteIterator_for_UInt16_Analog IterateOverRange_for_UInt16_Analog_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc,
    DNP3Serializer_for_Analog *serializer,
    uint16_t start
                                                                                     )
{
//    const auto reserve_size = 2 * IndexType::size + serializer.get_size();
//     pRangeWriteIterator_for_UInt8_Analog->isValid = length_in_HasLength_for_Uint16_t(&(position->hHasLength)) >= 2 * size_in_UInt8;
  uint16_t reserve_size = 2 * size_in_UInt16 +
                          get_size_in_Serializer_for_Analog(&(serializer->sSerializer_for_Analog));

//    if (this->WriteHeaderWithReserve(serializer.ID(), qc, reserve_size))
//boolean WriteHeaderWithReserve_in_HeaderWriter(HeaderWriter *pHeaderWriter, GroupVariationID id, QualifierCode_uint8_t qc, uint16_t reserve)
//    GroupVariationID ID_in_DNP3Serializer_for_Analog(DNP3Serializer_for_Analog *pDNP3Serializer_for_Analog)
  if(WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter, ID_in_DNP3Serializer_for_Analog(serializer), qc, reserve_size))
  {
//        return RangeWriteIterator<IndexType, WriteType>(start, serializer, *position);
    RangeWriteIterator_for_UInt16_Analog rRangeWriteIterator_for_UInt16_Analog;
////    void RangeWriteIterator_for_UInt8_Analog_in_RangeWriteIterator_for_UInt8_AnalogOver2(RangeWriteIterator_for_UInt8_Analog *pRangeWriteIterator_for_UInt8_Analog,
//                   typename IndexType::type_t start_,
////                   uint8_t start_,
//                   const Serializer<WriteType>& serializer,
////                   Serializer_for_Analog*  serializer,
//                   ser4cpp::wseq_t& position)
////                   WSeq_for_Uint16_t* position);
    RangeWriteIterator_for_UInt16_Analog_in_RangeWriteIterator_for_UInt16_AnalogOver2(&rRangeWriteIterator_for_UInt16_Analog,
        start,
        &(serializer->sSerializer_for_Analog),
        pHeaderWriter->position
                                                                                   );
    return rRangeWriteIterator_for_UInt16_Analog;
  }
  else
  {
//        return RangeWriteIterator<IndexType, WriteType>::Null();
    return Null_in_RangeWriteIterator_for_UInt16_Analog_static();
  }
}
//---------------------------------------------IterateOverRange_for_UInt16_Analog_in_HeaderWriter--------------------------------------------
//---------------------------------------------IterateOverCount_for_UInt16_Analog_in_HeaderWriter--------------------------------------------

CountWriteIterator_for_UInt16_Analog IterateOverCount_for_UInt16_Analog_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc,
    DNP3Serializer_for_Analog* serializer)
{
////template<class CountType, class WriteType>
////CountWriteIterator<CountType, WriteType> HeaderWriter::IterateOverCount(QualifierCode qc,
////                                                                        const DNP3Serializer<WriteType>& serializer)
////{
////   uint16_t reserve_size = CountType::size + serializer.get_size();
  uint16_t reserve_size = size_in_UInt16 +
                          get_size_in_Serializer_for_Analog(&(serializer->sSerializer_for_Analog));
////    if (this->WriteHeaderWithReserve(serializer.ID(), qc, reserve_size))
  if(WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter, ID_in_DNP3Serializer_for_Analog(serializer), qc, reserve_size))
  {
////        return CountWriteIterator<CountType, WriteType>(serializer, *position);
    CountWriteIterator_for_UInt16_Analog cCountWriteIterator_for_UInt16_Analog;
    CountWriteIterator_for_UInt16_Analog_in_CountWriteIterator_for_UInt16_AnalogOver2(&cCountWriteIterator_for_UInt16_Analog,
        &(serializer->sSerializer_for_Analog),
        pHeaderWriter->position
                                                                                     );
    return cCountWriteIterator_for_UInt16_Analog;
  }
  else
  {
////        return CountWriteIterator<CountType, WriteType>::Null();
    return Null_in_CountWriteIterator_for_UInt16_Analog_static();
  }
////}
}
//---------------------------------------------IterateOverCount_for_UInt16_Analog_in_HeaderWriter--------------------------------------------
//---------------------------------------------IterateOverCount_for_UInt8_Analog_in_HeaderWriter--------------------------------------------

CountWriteIterator_for_UInt8_Analog IterateOverCount_for_UInt8_Analog_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc,
    DNP3Serializer_for_Analog* serializer)
{
////template<class CountType, class WriteType>
////CountWriteIterator<CountType, WriteType> HeaderWriter::IterateOverCount(QualifierCode qc,
////                                                                        const DNP3Serializer<WriteType>& serializer)
////{
////   uint16_t reserve_size = CountType::size + serializer.get_size();
  uint16_t reserve_size = size_in_UInt8 +
                          get_size_in_Serializer_for_Analog(&(serializer->sSerializer_for_Analog));
////    if (this->WriteHeaderWithReserve(serializer.ID(), qc, reserve_size))
  if(WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter, ID_in_DNP3Serializer_for_Analog(serializer), qc, reserve_size))
  {
////        return CountWriteIterator<CountType, WriteType>(serializer, *position);
    CountWriteIterator_for_UInt8_Analog cCountWriteIterator_for_UInt8_Analog;
    CountWriteIterator_for_UInt8_Analog_in_CountWriteIterator_for_UInt8_AnalogOver2(&cCountWriteIterator_for_UInt8_Analog,
        &(serializer->sSerializer_for_Analog),
        pHeaderWriter->position
                                                                                   );
    return cCountWriteIterator_for_UInt8_Analog;
  }
  else
  {
////        return CountWriteIterator<CountType, WriteType>::Null();
    return Null_in_CountWriteIterator_for_UInt8_Analog_static();
  }
////}
}
//---------------------------------------------IterateOverCount_for_UInt8_Analog_in_HeaderWriter--------------------------------------------
//------------------------------IterateOverCountWithPrefix_for_UInt16_Analog_in_HeaderWriter--------------------------------------------------------
PrefixedWriteIterator_for_UInt16_Analog IterateOverCountWithPrefix_for_UInt16_Analog_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc, DNP3Serializer_for_Analog* serializer)
{
////    const auto reserve_size
  uint16_t reserve_size =
////        = 2 * PrefixType::size + serializer.get_size(); // enough space for the count, 1 prefix + object
    2*size_in_UInt16 +
    get_size_in_Serializer_for_Analog(&(serializer->sSerializer_for_Analog));
////    if (this->WriteHeaderWithReserve(serializer.ID(), qc, reserve_size))
  if(WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter,
      ID_in_DNP3Serializer_for_Analog(serializer), qc, reserve_size))
  {
    PrefixedWriteIterator_for_UInt16_Analog pPrefixedWriteIterator_for_UInt16_Analog;
    PrefixedWriteIterator_for_UInt16_Analog_in_PrefixedWriteIterator_for_UInt16_AnalogOver2(&pPrefixedWriteIterator_for_UInt16_Analog,
        &(serializer->sSerializer_for_Analog), pHeaderWriter->position);
//        return PrefixedWriteIterator<PrefixType, WriteType>(serializer, *position);
    return pPrefixedWriteIterator_for_UInt16_Analog;
  }
  else
  {
////        return PrefixedWriteIterator<PrefixType, WriteType>::Null();
    return Null_in_PrefixedWriteIterator_for_UInt16_Analog_static();
  }
}
//------------------------------IterateOverCountWithPrefix_for_UInt16_Analog_in_HeaderWriter--------------------------------------------------------
//------------------------------IterateOverCountWithPrefixAndCTO_for_UInt16_Analog_Group51Var1_in_HeaderWriter--------------------------------------------------------
////template<class PrefixType, class WriteType, class CTOType>
////PrefixedWriteIterator<PrefixType, WriteType> HeaderWriter::IterateOverCountWithPrefixAndCTO(
////    QualifierCode qc, const DNP3Serializer<WriteType>& serializer, const CTOType& cto)
PrefixedWriteIterator_for_UInt16_Analog IterateOverCountWithPrefixAndCTO_for_UInt16_Analog_Group51Var1_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc,
    DNP3Serializer_for_Analog* serializer,
    Group51Var1* cto)
{
////    this->Mark();
  Mark_in_HeaderWriter(pHeaderWriter);
////    if (this->WriteSingleValue<ser4cpp::UInt8, CTOType>(QualifierCode::UINT8_CNT, cto))
  if(WriteSingleValue_for_UInt8_Group51Var1_in_HeaderWriter(pHeaderWriter, QualifierCode_UINT8_CNT, cto))
  {
////        auto iter = IterateOverCountWithPrefix<PrefixType, WriteType>(qc, serializer);
    PrefixedWriteIterator_for_UInt16_Analog iter =
      IterateOverCountWithPrefix_for_UInt16_Analog_in_HeaderWriter(pHeaderWriter, qc, serializer);
////        if (!iter.IsValid())
    if (!IsValid_in_PrefixedWriteIterator_for_UInt16_Analog(&iter))
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
    return Null_in_PrefixedWriteIterator_for_UInt16_Analog_static();
  }
}
//--------------------------------IterateOverCountWithPrefixAndCTO_for_UInt16_Analog_Group51Var1_in_HeaderWriter--------------------------------------------------------
//------------------------------IterateOverCountWithPrefixAndCTO_for_UInt16_Analog_Group51Var2_in_HeaderWriter--------------------------------------------------------
////template<class PrefixType, class WriteType, class CTOType>
////PrefixedWriteIterator<PrefixType, WriteType> HeaderWriter::IterateOverCountWithPrefixAndCTO(
////    QualifierCode qc, const DNP3Serializer<WriteType>& serializer, const CTOType& cto)
PrefixedWriteIterator_for_UInt16_Analog IterateOverCountWithPrefixAndCTO_for_UInt16_Analog_Group51Var2_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc,
    DNP3Serializer_for_Analog* serializer,
    Group51Var2* cto)
{
////    this->Mark();
  Mark_in_HeaderWriter(pHeaderWriter);
////    if (this->WriteSingleValue<ser4cpp::UInt8, CTOType>(QualifierCode::UINT8_CNT, cto))
  if(WriteSingleValue_for_UInt8_Group51Var2_in_HeaderWriter(pHeaderWriter, QualifierCode_UINT8_CNT, cto))
  {
////        auto iter = IterateOverCountWithPrefix<PrefixType, WriteType>(qc, serializer);
    PrefixedWriteIterator_for_UInt16_Analog iter =
      IterateOverCountWithPrefix_for_UInt16_Analog_in_HeaderWriter(pHeaderWriter, qc, serializer);
////        if (!iter.IsValid())
    if (!IsValid_in_PrefixedWriteIterator_for_UInt16_Analog(&iter))
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
    return Null_in_PrefixedWriteIterator_for_UInt16_Analog_static();
  }
}
//------------------------------IterateOverCountWithPrefixAndCTO_for_UInt16_Analog_Group51Var2_in_HeaderWriter--------------------------------------------------------

//------------------------------IterateOverCountWithPrefix_for_UInt16_AnalogOutputInt16_in_HeaderWriter--------------------------------------------------------
PrefixedWriteIterator_for_UInt16_AnalogOutputInt16 IterateOverCountWithPrefix_for_UInt16_AnalogOutputInt16_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc, DNP3Serializer_for_AnalogOutputInt16* serializer)
{
////    const auto reserve_size
  uint16_t reserve_size =
////        = 2 * PrefixType::size + serializer.get_size(); // enough space for the count, 1 prefix + object
    2*size_in_UInt16 +
    get_size_in_Serializer_for_AnalogOutputInt16(&(serializer->sSerializer_for_AnalogOutputInt16));
////    if (this->WriteHeaderWithReserve(serializer.ID(), qc, reserve_size))
  if(WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter,
      ID_in_DNP3Serializer_for_AnalogOutputInt16(serializer), qc, reserve_size))
  {
    PrefixedWriteIterator_for_UInt16_AnalogOutputInt16 pPrefixedWriteIterator_for_UInt16_AnalogOutputInt16;
    PrefixedWriteIterator_for_UInt16_AnalogOutputInt16_in_PrefixedWriteIterator_for_UInt16_AnalogOutputInt16Over2(&pPrefixedWriteIterator_for_UInt16_AnalogOutputInt16,
        &(serializer->sSerializer_for_AnalogOutputInt16), pHeaderWriter->position);
//        return PrefixedWriteIterator<PrefixType, WriteType>(serializer, *position);
    return pPrefixedWriteIterator_for_UInt16_AnalogOutputInt16;
  }
  else
  {
////        return PrefixedWriteIterator<PrefixType, WriteType>::Null();
    return Null_in_PrefixedWriteIterator_for_UInt16_AnalogOutputInt16_static();
  }
}
//------------------------------IterateOverCountWithPrefix_for_UInt16_AnalogOutputInt16_in_HeaderWriter--------------------------------------------------------
//------------------------------IterateOverCountWithPrefix_for_UInt8_AnalogOutputInt16_in_HeaderWriter--------------------------------------------------------
PrefixedWriteIterator_for_UInt8_AnalogOutputInt16 IterateOverCountWithPrefix_for_UInt8_AnalogOutputInt16_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc, DNP3Serializer_for_AnalogOutputInt16* serializer)
{
////    const auto reserve_size
  uint16_t reserve_size =
////        = 2 * PrefixType::size + serializer.get_size(); // enough space for the count, 1 prefix + object
    2*size_in_UInt8 +
    get_size_in_Serializer_for_AnalogOutputInt16(&(serializer->sSerializer_for_AnalogOutputInt16));
////    if (this->WriteHeaderWithReserve(serializer.ID(), qc, reserve_size))
  if(WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter,
      ID_in_DNP3Serializer_for_AnalogOutputInt16(serializer), qc, reserve_size))
  {
    PrefixedWriteIterator_for_UInt8_AnalogOutputInt16 pPrefixedWriteIterator_for_UInt8_AnalogOutputInt16;
    PrefixedWriteIterator_for_UInt8_AnalogOutputInt16_in_PrefixedWriteIterator_for_UInt8_AnalogOutputInt16Over2(&pPrefixedWriteIterator_for_UInt8_AnalogOutputInt16,
        &(serializer->sSerializer_for_AnalogOutputInt16), pHeaderWriter->position);
//        return PrefixedWriteIterator<PrefixType, WriteType>(serializer, *position);
    return pPrefixedWriteIterator_for_UInt8_AnalogOutputInt16;
  }
  else
  {
////        return PrefixedWriteIterator<PrefixType, WriteType>::Null();
    return Null_in_PrefixedWriteIterator_for_UInt8_AnalogOutputInt16_static();
  }
}
//------------------------------IterateOverCountWithPrefix_for_UInt8_AnalogOutputInt16_in_HeaderWriter--------------------------------------------------------

//------------------------------IterateOverCountWithPrefix_for_UInt16_AnalogOutputInt32_in_HeaderWriter--------------------------------------------------------
PrefixedWriteIterator_for_UInt16_AnalogOutputInt32 IterateOverCountWithPrefix_for_UInt16_AnalogOutputInt32_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc, DNP3Serializer_for_AnalogOutputInt32* serializer)
{
////    const auto reserve_size
  uint16_t reserve_size =
////        = 2 * PrefixType::size + serializer.get_size(); // enough space for the count, 1 prefix + object
    2*size_in_UInt16 +
    get_size_in_Serializer_for_AnalogOutputInt32(&(serializer->sSerializer_for_AnalogOutputInt32));
////    if (this->WriteHeaderWithReserve(serializer.ID(), qc, reserve_size))
  if(WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter,
      ID_in_DNP3Serializer_for_AnalogOutputInt32(serializer), qc, reserve_size))
  {
    PrefixedWriteIterator_for_UInt16_AnalogOutputInt32 pPrefixedWriteIterator_for_UInt16_AnalogOutputInt32;
    PrefixedWriteIterator_for_UInt16_AnalogOutputInt32_in_PrefixedWriteIterator_for_UInt16_AnalogOutputInt32Over2(&pPrefixedWriteIterator_for_UInt16_AnalogOutputInt32,
        &(serializer->sSerializer_for_AnalogOutputInt32), pHeaderWriter->position);
//        return PrefixedWriteIterator<PrefixType, WriteType>(serializer, *position);
    return pPrefixedWriteIterator_for_UInt16_AnalogOutputInt32;
  }
  else
  {
////        return PrefixedWriteIterator<PrefixType, WriteType>::Null();
    return Null_in_PrefixedWriteIterator_for_UInt16_AnalogOutputInt32_static();
  }
}
//------------------------------IterateOverCountWithPrefix_for_UInt16_AnalogOutputInt32_in_HeaderWriter--------------------------------------------------------
//------------------------------IterateOverCountWithPrefix_for_UInt8_AnalogOutputInt32_in_HeaderWriter--------------------------------------------------------
PrefixedWriteIterator_for_UInt8_AnalogOutputInt32 IterateOverCountWithPrefix_for_UInt8_AnalogOutputInt32_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc, DNP3Serializer_for_AnalogOutputInt32* serializer)
{
////    const auto reserve_size
  uint16_t reserve_size =
////        = 2 * PrefixType::size + serializer.get_size(); // enough space for the count, 1 prefix + object
    2*size_in_UInt8 +
    get_size_in_Serializer_for_AnalogOutputInt32(&(serializer->sSerializer_for_AnalogOutputInt32));
////    if (this->WriteHeaderWithReserve(serializer.ID(), qc, reserve_size))
  if(WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter,
      ID_in_DNP3Serializer_for_AnalogOutputInt32(serializer), qc, reserve_size))
  {
    PrefixedWriteIterator_for_UInt8_AnalogOutputInt32 pPrefixedWriteIterator_for_UInt8_AnalogOutputInt32;
    PrefixedWriteIterator_for_UInt8_AnalogOutputInt32_in_PrefixedWriteIterator_for_UInt8_AnalogOutputInt32Over2(&pPrefixedWriteIterator_for_UInt8_AnalogOutputInt32,
        &(serializer->sSerializer_for_AnalogOutputInt32), pHeaderWriter->position);
//        return PrefixedWriteIterator<PrefixType, WriteType>(serializer, *position);
    return pPrefixedWriteIterator_for_UInt8_AnalogOutputInt32;
  }
  else
  {
////        return PrefixedWriteIterator<PrefixType, WriteType>::Null();
    return Null_in_PrefixedWriteIterator_for_UInt8_AnalogOutputInt32_static();
  }
}
//------------------------------IterateOverCountWithPrefix_for_UInt8_AnalogOutputInt32_in_HeaderWriter--------------------------------------------------------

//------------------------------IterateOverCountWithPrefix_for_UInt16_AnalogOutputFloat32_in_HeaderWriter--------------------------------------------------------
PrefixedWriteIterator_for_UInt16_AnalogOutputFloat32 IterateOverCountWithPrefix_for_UInt16_AnalogOutputFloat32_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc, DNP3Serializer_for_AnalogOutputFloat32* serializer)
{
////    const auto reserve_size
  uint16_t reserve_size =
////        = 2 * PrefixType::size + serializer.get_size(); // enough space for the count, 1 prefix + object
    2*size_in_UInt16 +
    get_size_in_Serializer_for_AnalogOutputFloat32(&(serializer->sSerializer_for_AnalogOutputFloat32));
////    if (this->WriteHeaderWithReserve(serializer.ID(), qc, reserve_size))
  if(WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter,
      ID_in_DNP3Serializer_for_AnalogOutputFloat32(serializer), qc, reserve_size))
  {
    PrefixedWriteIterator_for_UInt16_AnalogOutputFloat32 pPrefixedWriteIterator_for_UInt16_AnalogOutputFloat32;
    PrefixedWriteIterator_for_UInt16_AnalogOutputFloat32_in_PrefixedWriteIterator_for_UInt16_AnalogOutputFloat32Over2(&pPrefixedWriteIterator_for_UInt16_AnalogOutputFloat32,
        &(serializer->sSerializer_for_AnalogOutputFloat32), pHeaderWriter->position);
//        return PrefixedWriteIterator<PrefixType, WriteType>(serializer, *position);
    return pPrefixedWriteIterator_for_UInt16_AnalogOutputFloat32;
  }
  else
  {
////        return PrefixedWriteIterator<PrefixType, WriteType>::Null();
    return Null_in_PrefixedWriteIterator_for_UInt16_AnalogOutputFloat32_static();
  }
}
//------------------------------IterateOverCountWithPrefix_for_UInt16_AnalogOutputFloat32_in_HeaderWriter--------------------------------------------------------
//------------------------------IterateOverCountWithPrefix_for_UInt8_AnalogOutputFloat32_in_HeaderWriter--------------------------------------------------------
PrefixedWriteIterator_for_UInt8_AnalogOutputFloat32 IterateOverCountWithPrefix_for_UInt8_AnalogOutputFloat32_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc, DNP3Serializer_for_AnalogOutputFloat32* serializer)
{
////    const auto reserve_size
  uint16_t reserve_size =
////        = 2 * PrefixType::size + serializer.get_size(); // enough space for the count, 1 prefix + object
    2*size_in_UInt8 +
    get_size_in_Serializer_for_AnalogOutputFloat32(&(serializer->sSerializer_for_AnalogOutputFloat32));
////    if (this->WriteHeaderWithReserve(serializer.ID(), qc, reserve_size))
  if(WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter,
      ID_in_DNP3Serializer_for_AnalogOutputFloat32(serializer), qc, reserve_size))
  {
    PrefixedWriteIterator_for_UInt8_AnalogOutputFloat32 pPrefixedWriteIterator_for_UInt8_AnalogOutputFloat32;
    PrefixedWriteIterator_for_UInt8_AnalogOutputFloat32_in_PrefixedWriteIterator_for_UInt8_AnalogOutputFloat32Over2(&pPrefixedWriteIterator_for_UInt8_AnalogOutputFloat32,
        &(serializer->sSerializer_for_AnalogOutputFloat32), pHeaderWriter->position);
//        return PrefixedWriteIterator<PrefixType, WriteType>(serializer, *position);
    return pPrefixedWriteIterator_for_UInt8_AnalogOutputFloat32;
  }
  else
  {
////        return PrefixedWriteIterator<PrefixType, WriteType>::Null();
    return Null_in_PrefixedWriteIterator_for_UInt8_AnalogOutputFloat32_static();
  }
}
//------------------------------IterateOverCountWithPrefix_for_UInt8_AnalogOutputFloat32_in_HeaderWriter--------------------------------------------------------
