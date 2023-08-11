#include "header.h"
#include "HeaderWriter_for_ControlRelayOutputBlock.h"

//#include "SerializationTemplates.h"

//---------------------------------------------IterateOverCount_for_UInt16_ControlRelayOutputBlock_in_HeaderWriter--------------------------------------------

CountWriteIterator_for_UInt16_ControlRelayOutputBlock IterateOverCount_for_UInt16_ControlRelayOutputBlock_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc,
    DNP3Serializer_for_ControlRelayOutputBlock* serializer)
{
////template<class CountType, class WriteType>
////CountWriteIterator<CountType, WriteType> HeaderWriter::IterateOverCount(QualifierCode qc,
////                                                                        const DNP3Serializer<WriteType>& serializer)
////{
////   uint16_t reserve_size = CountType::size + serializer.get_size();
  uint16_t reserve_size = size_in_UInt16 +
                          get_size_in_Serializer_for_ControlRelayOutputBlock(&(serializer->sSerializer_for_ControlRelayOutputBlock));
////    if (this->WriteHeaderWithReserve(serializer.ID(), qc, reserve_size))
  if(WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter, ID_in_DNP3Serializer_for_ControlRelayOutputBlock(serializer), qc, reserve_size))
  {
////        return CountWriteIterator<CountType, WriteType>(serializer, *position);
    CountWriteIterator_for_UInt16_ControlRelayOutputBlock cCountWriteIterator_for_UInt16_ControlRelayOutputBlock;
    CountWriteIterator_for_UInt16_ControlRelayOutputBlock_in_CountWriteIterator_for_UInt16_ControlRelayOutputBlockOver2(&cCountWriteIterator_for_UInt16_ControlRelayOutputBlock,
        &(serializer->sSerializer_for_ControlRelayOutputBlock),
        pHeaderWriter->position
                                                                                                                       );
    return cCountWriteIterator_for_UInt16_ControlRelayOutputBlock;
  }
  else
  {
////        return CountWriteIterator<CountType, WriteType>::Null();
    return Null_in_CountWriteIterator_for_UInt16_ControlRelayOutputBlock_static();
  }
////}
}
//---------------------------------------------IterateOverCount_for_UInt16_ControlRelayOutputBlock_in_HeaderWriter--------------------------------------------
//---------------------------------------------IterateOverCount_for_UInt8_ControlRelayOutputBlock_in_HeaderWriter--------------------------------------------

CountWriteIterator_for_UInt8_ControlRelayOutputBlock IterateOverCount_for_UInt8_ControlRelayOutputBlock_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc,
    DNP3Serializer_for_ControlRelayOutputBlock* serializer)
{
////template<class CountType, class WriteType>
////CountWriteIterator<CountType, WriteType> HeaderWriter::IterateOverCount(QualifierCode qc,
////                                                                        const DNP3Serializer<WriteType>& serializer)
////{
////   uint16_t reserve_size = CountType::size + serializer.get_size();
  uint16_t reserve_size = size_in_UInt8 +
                          get_size_in_Serializer_for_ControlRelayOutputBlock(&(serializer->sSerializer_for_ControlRelayOutputBlock));
////    if (this->WriteHeaderWithReserve(serializer.ID(), qc, reserve_size))
  if(WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter, ID_in_DNP3Serializer_for_ControlRelayOutputBlock(serializer), qc, reserve_size))
  {
////        return CountWriteIterator<CountType, WriteType>(serializer, *position);
    CountWriteIterator_for_UInt8_ControlRelayOutputBlock cCountWriteIterator_for_UInt8_ControlRelayOutputBlock;
    CountWriteIterator_for_UInt8_ControlRelayOutputBlock_in_CountWriteIterator_for_UInt8_ControlRelayOutputBlockOver2(&cCountWriteIterator_for_UInt8_ControlRelayOutputBlock,
        &(serializer->sSerializer_for_ControlRelayOutputBlock),
        pHeaderWriter->position
                                                                                                                     );
    return cCountWriteIterator_for_UInt8_ControlRelayOutputBlock;
  }
  else
  {
////        return CountWriteIterator<CountType, WriteType>::Null();
    return Null_in_CountWriteIterator_for_UInt8_ControlRelayOutputBlock_static();
  }
////}
}
//---------------------------------------------IterateOverCount_for_UInt8_ControlRelayOutputBlock_in_HeaderWriter--------------------------------------------
//------------------------------IterateOverCountWithPrefix_for_UInt16_ControlRelayOutputBlock_in_HeaderWriter--------------------------------------------------------
PrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock IterateOverCountWithPrefix_for_UInt16_ControlRelayOutputBlock_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc, DNP3Serializer_for_ControlRelayOutputBlock* serializer)
{
////    const auto reserve_size
  uint16_t reserve_size =
////        = 2 * PrefixType::size + serializer.get_size(); // enough space for the count, 1 prefix + object
    2*size_in_UInt16 +
    get_size_in_Serializer_for_ControlRelayOutputBlock(&(serializer->sSerializer_for_ControlRelayOutputBlock));
////    if (this->WriteHeaderWithReserve(serializer.ID(), qc, reserve_size))
  if(WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter,
      ID_in_DNP3Serializer_for_ControlRelayOutputBlock(serializer), qc, reserve_size))
  {
    PrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock pPrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock;
    PrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock_in_PrefixedWriteIterator_for_UInt16_ControlRelayOutputBlockOver2(&pPrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock,
        &(serializer->sSerializer_for_ControlRelayOutputBlock), pHeaderWriter->position);
//        return PrefixedWriteIterator<PrefixType, WriteType>(serializer, *position);
    return pPrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock;
  }
  else
  {
////        return PrefixedWriteIterator<PrefixType, WriteType>::Null();
    return Null_in_PrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock_static();
  }
}
//------------------------------IterateOverCountWithPrefix_for_UInt16_ControlRelayOutputBlock_in_HeaderWriter--------------------------------------------------------
//------------------------------IterateOverCountWithPrefixAndCTO_for_UInt16_ControlRelayOutputBlock_Group51Var1_in_HeaderWriter--------------------------------------------------------
////template<class PrefixType, class WriteType, class CTOType>
////PrefixedWriteIterator<PrefixType, WriteType> HeaderWriter::IterateOverCountWithPrefixAndCTO(
////    QualifierCode qc, const DNP3Serializer<WriteType>& serializer, const CTOType& cto)
PrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock IterateOverCountWithPrefixAndCTO_for_UInt16_ControlRelayOutputBlock_Group51Var1_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc,
    DNP3Serializer_for_ControlRelayOutputBlock* serializer,
    Group51Var1* cto)
{
////    this->Mark();
  Mark_in_HeaderWriter(pHeaderWriter);
////    if (this->WriteSingleValue<ser4cpp::UInt8, CTOType>(QualifierCode::UINT8_CNT, cto))
  if(WriteSingleValue_for_UInt8_Group51Var1_in_HeaderWriter(pHeaderWriter, QualifierCode_UINT8_CNT, cto))
  {
////        auto iter = IterateOverCountWithPrefix<PrefixType, WriteType>(qc, serializer);
    PrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock iter =
      IterateOverCountWithPrefix_for_UInt16_ControlRelayOutputBlock_in_HeaderWriter(pHeaderWriter, qc, serializer);
////        if (!iter.IsValid())
    if (!IsValid_in_PrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock(&iter))
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
    return Null_in_PrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock_static();
  }
}
//--------------------------------IterateOverCountWithPrefixAndCTO_for_UInt16_ControlRelayOutputBlock_Group51Var1_in_HeaderWriter--------------------------------------------------------
//------------------------------IterateOverCountWithPrefixAndCTO_for_UInt16_ControlRelayOutputBlock_Group51Var2_in_HeaderWriter--------------------------------------------------------
////template<class PrefixType, class WriteType, class CTOType>
////PrefixedWriteIterator<PrefixType, WriteType> HeaderWriter::IterateOverCountWithPrefixAndCTO(
////    QualifierCode qc, const DNP3Serializer<WriteType>& serializer, const CTOType& cto)
PrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock IterateOverCountWithPrefixAndCTO_for_UInt16_ControlRelayOutputBlock_Group51Var2_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc,
    DNP3Serializer_for_ControlRelayOutputBlock* serializer,
    Group51Var2* cto)
{
////    this->Mark();
  Mark_in_HeaderWriter(pHeaderWriter);
////    if (this->WriteSingleValue<ser4cpp::UInt8, CTOType>(QualifierCode::UINT8_CNT, cto))
  if(WriteSingleValue_for_UInt8_Group51Var2_in_HeaderWriter(pHeaderWriter, QualifierCode_UINT8_CNT, cto))
  {
////        auto iter = IterateOverCountWithPrefix<PrefixType, WriteType>(qc, serializer);
    PrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock iter =
      IterateOverCountWithPrefix_for_UInt16_ControlRelayOutputBlock_in_HeaderWriter(pHeaderWriter, qc, serializer);
////        if (!iter.IsValid())
    if (!IsValid_in_PrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock(&iter))
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
    return Null_in_PrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock_static();
  }
}
//------------------------------IterateOverCountWithPrefixAndCTO_for_UInt16_ControlRelayOutputBlock_Group51Var2_in_HeaderWriter--------------------------------------------------------
