#include "header.h"
#include "EventWriters_for_AnalogOutputStatus.h"

void BasicEventWriter_for_AnalogOutputStatus_destr_BasicEventWriter_for_AnalogOutputStatus(BasicEventWriter_for_AnalogOutputStatus *pBasicEventWriter_for_AnalogOutputStatus)
{
  PrefixedWriteIterator_for_UInt16_AnalogOutputStatus_destr_PrefixedWriteIterator_for_UInt16_AnalogOutputStatus(&(pBasicEventWriter_for_AnalogOutputStatus->iterator));
}

////    template<class T>
uint16_t Write_for_AnalogOutputStatus_in_EventWriters_static(HeaderWriter* writer, IEventCollection_for_AnalogOutputStatus* items, DNP3Serializer_for_AnalogOutputStatus* serializer)
{
//void BasicEventWriter_for_AnalogOutputStatus_in_BasicEventWriter_for_AnalogOutputStatus(BasicEventWriter_for_AnalogOutputStatus *pBasicEventWriter_for_AnalogOutputStatus,
//    HeaderWriter* writer, DNP3Serializer_for_AnalogOutputStatus* serializer);
////  BasicEventWriter_for_AnalogOutputStatus handler(writer, serializer);
  BasicEventWriter_for_AnalogOutputStatus handler;
  BasicEventWriter_for_AnalogOutputStatus_in_BasicEventWriter_for_AnalogOutputStatus(&handler, writer, serializer);
//  uint16_t WriteSome_in_IEventCollection_for_AnalogOutputStatus(IEventCollection_for_AnalogOutputStatus *, IEventWriter_for_AnalogOutputStatus* handler);
///        return items.WriteSome(handler);
  uint16_t temp = WriteSome_in_IEventCollection_for_AnalogOutputStatus(items, &(handler.iIEventWriter_for_AnalogOutputStatus));
  BasicEventWriter_for_AnalogOutputStatus_destr_BasicEventWriter_for_AnalogOutputStatus(&handler);
  return temp;
}

////        BasicEventWriter(HeaderWriter& writer, const DNP3Serializer<T>& serializer)
////            : iterator(writer.IterateOverCountWithPrefix<ser4cpp::UInt16, T>(QualifierCode::UINT16_CNT_UINT16_INDEX,
////                                                                             serializer))
void BasicEventWriter_for_AnalogOutputStatus_in_BasicEventWriter_for_AnalogOutputStatus(BasicEventWriter_for_AnalogOutputStatus *pBasicEventWriter_for_AnalogOutputStatus,
    HeaderWriter* writer, DNP3Serializer_for_AnalogOutputStatus* serializer)
{
  PrefixedWriteIterator_for_UInt16_AnalogOutputStatus temp = IterateOverCountWithPrefix_for_UInt16_AnalogOutputStatus_in_HeaderWriter(writer, QualifierCode_UINT16_CNT_UINT16_INDEX, serializer);
  pBasicEventWriter_for_AnalogOutputStatus->iterator = temp;

  (pBasicEventWriter_for_AnalogOutputStatus->iIEventWriter_for_AnalogOutputStatus).pWrite_in_IEventWriter_for_AnalogOutputStatus = Write_in_BasicEventWriter_for_AnalogOutputStatus_override;
  setParentPointer_in_IEventWriter_for_AnalogOutputStatus(&(pBasicEventWriter_for_AnalogOutputStatus->iIEventWriter_for_AnalogOutputStatus), pBasicEventWriter_for_AnalogOutputStatus);
}

////        virtual bool Write(const T& meas, uint16_t index) override
boolean Write_in_BasicEventWriter_for_AnalogOutputStatus_override(void* pIEventWriter_for_AnalogOutputStatus, AnalogOutputStatus* meas, uint16_t index)
{
  BasicEventWriter_for_AnalogOutputStatus* parent = (BasicEventWriter_for_AnalogOutputStatus*) getParentPointer_in_IEventWriter_for_AnalogOutputStatus((IEventWriter_for_AnalogOutputStatus*) pIEventWriter_for_AnalogOutputStatus);
//    boolean IsValid_in_PrefixedWriteIterator_for_UInt16_AnalogOutputStatus(PrefixedWriteIterator_for_UInt16_AnalogOutputStatus *pPrefixedWriteIterator_for_UInt16_AnalogOutputStatus);
////            return iterator.IsValid() ? iterator.Write(meas, index) : false;
  return IsValid_in_PrefixedWriteIterator_for_UInt16_AnalogOutputStatus(&(parent->iterator)) ?
         Write_in_PrefixedWriteIterator_for_UInt16_AnalogOutputStatus(&(parent->iterator), meas, index) : false;
//    boolean Write_in_PrefixedWriteIterator_for_UInt16_AnalogOutputStatus(PrefixedWriteIterator_for_UInt16_AnalogOutputStatus *pPrefixedWriteIterator_for_UInt16_AnalogOutputStatus,
//                                                                  AnalogOutputStatus* value, uint16_t index);
}

////        CTOEventWriter(const U& cto, HeaderWriter& writer, const DNP3Serializer<T>& serializer)
////            : cto(cto.time),
////              iterator(writer.IterateOverCountWithPrefixAndCTO<ser4cpp::UInt16, T, U>(
////                  QualifierCode::UINT16_CNT_UINT16_INDEX, serializer, cto))
void CTOEventWriter_for_AnalogOutputStatus_Group51Var1_in_CTOEventWriter_for_AnalogOutputStatus_Group51Var1(CTOEventWriter_for_AnalogOutputStatus_Group51Var1 *pCTOEventWriter_for_AnalogOutputStatus_Group51Var1,
    Group51Var1* cto,
    HeaderWriter* writer,
    DNP3Serializer_for_AnalogOutputStatus* serializer)
{
  DNPTime_in_DNPTimeOver2(&(pCTOEventWriter_for_AnalogOutputStatus_Group51Var1->cto), (cto->timeDNPTime).value);

  //PrefixedWriteIterator_for_UInt16_AnalogOutputStatus temp 
  pCTOEventWriter_for_AnalogOutputStatus_Group51Var1->iterator = IterateOverCountWithPrefixAndCTO_for_UInt16_AnalogOutputStatus_Group51Var1_in_HeaderWriter(
        writer,
        QualifierCode_UINT16_CNT_UINT16_INDEX,
        serializer,
        cto
      );
//  pCTOEventWriter_for_AnalogOutputStatus_Group51Var1->iterator = temp;

  (pCTOEventWriter_for_AnalogOutputStatus_Group51Var1->iIEventWriter_for_AnalogOutputStatus).pWrite_in_IEventWriter_for_AnalogOutputStatus = Write_in_CTOEventWriter_for_AnalogOutputStatus_Group51Var1_override;
  setParentPointer_in_IEventWriter_for_AnalogOutputStatus(&(pCTOEventWriter_for_AnalogOutputStatus_Group51Var1->iIEventWriter_for_AnalogOutputStatus), pCTOEventWriter_for_AnalogOutputStatus_Group51Var1);
}

////        virtual bool Write(const T& meas, uint16_t index) override
boolean Write_in_CTOEventWriter_for_AnalogOutputStatus_Group51Var1_override(void* pIEventWriter_for_AnalogOutputStatus, AnalogOutputStatus* meas, uint16_t index)
{
  CTOEventWriter_for_AnalogOutputStatus_Group51Var1* parent = (CTOEventWriter_for_AnalogOutputStatus_Group51Var1*) getParentPointer_in_IEventWriter_for_AnalogOutputStatus((IEventWriter_for_AnalogOutputStatus*) pIEventWriter_for_AnalogOutputStatus);

//    boolean IsValid_in_PrefixedWriteIterator_for_UInt16_AnalogOutputStatus(PrefixedWriteIterator_for_UInt16_AnalogOutputStatus *pPrefixedWriteIterator_for_UInt16_AnalogOutputStatus);
////            if (!this->iterator.IsValid())
  if(!IsValid_in_PrefixedWriteIterator_for_UInt16_AnalogOutputStatus(&(parent->iterator)))
    return false;

  // Check that the quality of the measurement fits with the CTO variation
  if ((parent->cto).quality == TimestampQuality_SYNCHRONIZED)
  {
    if ((meas->tTypedMeasurement_for_Double64).mMeasurement.timeDNPTime.quality != TimestampQuality_SYNCHRONIZED)
      return false;
  }
  else
  {
////                if (meas.time.quality == TimestampQuality::SYNCHRONIZED)
    if ((meas->tTypedMeasurement_for_Double64).mMeasurement.timeDNPTime.quality == TimestampQuality_SYNCHRONIZED)
      return false;
  }

  // can't encode timestamps that go backwards
////            if (meas.time.value < this->cto.value)
  if ((meas->tTypedMeasurement_for_Double64).mMeasurement.timeDNPTime.value < parent->cto.value)
    return false;

////            const auto diff = meas.time.value - this->cto.value;
  uint64_t diff = (meas->tTypedMeasurement_for_Double64).mMeasurement.timeDNPTime.value - parent->cto.value;

  // can't encode timestamps where the diff is greater than uint16_t
////            if (diff > ser4cpp::UInt16::max_value)
  if(diff > 0xFFFF)
    return false;

////            auto copy = meas;
  AnalogOutputStatus copy = *meas;
//  void DNPTime_in_DNPTimeOver2(DNPTime *pDNPTime, uint64_t value);
  DNPTime dDNPTime;
  DNPTime_in_DNPTimeOver2(&dDNPTime, diff);
////            copy.time = DNPTime(diff);
  copy.tTypedMeasurement_for_Double64.mMeasurement.timeDNPTime = dDNPTime;

//    boolean Write_in_PrefixedWriteIterator_for_UInt16_AnalogOutputStatus(PrefixedWriteIterator_for_UInt16_AnalogOutputStatus *pPrefixedWriteIterator_for_UInt16_AnalogOutputStatus,
//                                                                  AnalogOutputStatus* value, uint16_t index);
////            return this->iterator.Write(copy, index);
  return Write_in_PrefixedWriteIterator_for_UInt16_AnalogOutputStatus(&(parent->iterator), &copy, index);
}

uint16_t WriteWithCTO_for_AnalogOutputStatus_in_EventWriters_static(DNPTime* cto,
    HeaderWriter* writer,
    IEventCollection_for_AnalogOutputStatus* items,
    DNP3Serializer_for_AnalogOutputStatus* serializer)
{
  if (cto->quality == TimestampQuality_SYNCHRONIZED)
  {
    Group51Var1 value;
    value.timeDNPTime = *cto;
//void CTOEventWriter_for_AnalogOutputStatus_Group51Var1_in_CTOEventWriter_for_AnalogOutputStatus_Group51Var1(CTOEventWriter_for_AnalogOutputStatus_Group51Var1 *pCTOEventWriter_for_AnalogOutputStatus_Group51Var1,
//    Group51Var1* cto,
//    HeaderWriter* writer,
//    DNP3Serializer_for_AnalogOutputStatus* serializer);
////            CTOEventWriter<T, Group51Var1> handler(value, writer, serializer);
    CTOEventWriter_for_AnalogOutputStatus_Group51Var1 handler;
    CTOEventWriter_for_AnalogOutputStatus_Group51Var1_in_CTOEventWriter_for_AnalogOutputStatus_Group51Var1(&handler,
        &value,
        writer,
        serializer);
//  uint16_t WriteSome_in_IEventCollection_for_AnalogOutputStatus(IEventCollection_for_AnalogOutputStatus *, IEventWriter_for_AnalogOutputStatus* handler);
////            return items.WriteSome(handler);
    return WriteSome_in_IEventCollection_for_AnalogOutputStatus(items, &(handler.iIEventWriter_for_AnalogOutputStatus));
  }
  else
  {
    Group51Var2 value;
////            value.time = cto;
    value.timeDNPTime = *cto;
////            CTOEventWriter<T, Group51Var2> handler(value, writer, serializer);
    CTOEventWriter_for_AnalogOutputStatus_Group51Var2 handler;
    CTOEventWriter_for_AnalogOutputStatus_Group51Var2_in_CTOEventWriter_for_AnalogOutputStatus_Group51Var2(&handler,
        &value,
        writer,
        serializer);
////            return items.WriteSome(handler);
    return WriteSome_in_IEventCollection_for_AnalogOutputStatus(items, &(handler.iIEventWriter_for_AnalogOutputStatus));
  }
}

////        CTOEventWriter(const U& cto, HeaderWriter& writer, const DNP3Serializer<T>& serializer)
////            : cto(cto.time),
////              iterator(writer.IterateOverCountWithPrefixAndCTO<ser4cpp::UInt16, T, U>(
////                  QualifierCode::UINT16_CNT_UINT16_INDEX, serializer, cto))
void CTOEventWriter_for_AnalogOutputStatus_Group51Var2_in_CTOEventWriter_for_AnalogOutputStatus_Group51Var2(CTOEventWriter_for_AnalogOutputStatus_Group51Var2 *pCTOEventWriter_for_AnalogOutputStatus_Group51Var2,
    Group51Var2* cto,
    HeaderWriter* writer,
    DNP3Serializer_for_AnalogOutputStatus* serializer)
{
  DNPTime_in_DNPTimeOver2(&(pCTOEventWriter_for_AnalogOutputStatus_Group51Var2->cto), (cto->timeDNPTime).value);

  //PrefixedWriteIterator_for_UInt16_AnalogOutputStatus temp 
  pCTOEventWriter_for_AnalogOutputStatus_Group51Var2->iterator = IterateOverCountWithPrefixAndCTO_for_UInt16_AnalogOutputStatus_Group51Var2_in_HeaderWriter(
        writer,
        QualifierCode_UINT16_CNT_UINT16_INDEX,
        serializer,
        cto
      );
//  pCTOEventWriter_for_AnalogOutputStatus_Group51Var2->iterator = temp;

  (pCTOEventWriter_for_AnalogOutputStatus_Group51Var2->iIEventWriter_for_AnalogOutputStatus).pWrite_in_IEventWriter_for_AnalogOutputStatus = Write_in_CTOEventWriter_for_AnalogOutputStatus_Group51Var2_override;
  setParentPointer_in_IEventWriter_for_AnalogOutputStatus(&(pCTOEventWriter_for_AnalogOutputStatus_Group51Var2->iIEventWriter_for_AnalogOutputStatus), pCTOEventWriter_for_AnalogOutputStatus_Group51Var2);
}

////        virtual bool Write(const T& meas, uint16_t index) override
boolean Write_in_CTOEventWriter_for_AnalogOutputStatus_Group51Var2_override(void* pIEventWriter_for_AnalogOutputStatus, AnalogOutputStatus* meas, uint16_t index)
{
  CTOEventWriter_for_AnalogOutputStatus_Group51Var2* parent = (CTOEventWriter_for_AnalogOutputStatus_Group51Var2*) getParentPointer_in_IEventWriter_for_AnalogOutputStatus((IEventWriter_for_AnalogOutputStatus*) pIEventWriter_for_AnalogOutputStatus);

//    boolean IsValid_in_PrefixedWriteIterator_for_UInt16_AnalogOutputStatus(PrefixedWriteIterator_for_UInt16_AnalogOutputStatus *pPrefixedWriteIterator_for_UInt16_AnalogOutputStatus);
////            if (!this->iterator.IsValid())
  if(!IsValid_in_PrefixedWriteIterator_for_UInt16_AnalogOutputStatus(&(parent->iterator)))
    return false;

  // Check that the quality of the measurement fits with the CTO variation
  if ((parent->cto).quality == TimestampQuality_SYNCHRONIZED)
  {
    if ((meas->tTypedMeasurement_for_Double64).mMeasurement.timeDNPTime.quality != TimestampQuality_SYNCHRONIZED)
      return false;
  }
  else
  {
////                if (meas.time.quality == TimestampQuality::SYNCHRONIZED)
    if ((meas->tTypedMeasurement_for_Double64).mMeasurement.timeDNPTime.quality == TimestampQuality_SYNCHRONIZED)
      return false;
  }

  // can't encode timestamps that go backwards
////            if (meas.time.value < this->cto.value)
  if ((meas->tTypedMeasurement_for_Double64).mMeasurement.timeDNPTime.value < parent->cto.value)
    return false;

////            const auto diff = meas.time.value - this->cto.value;
  uint64_t diff = (meas->tTypedMeasurement_for_Double64).mMeasurement.timeDNPTime.value - parent->cto.value;

  // can't encode timestamps where the diff is greater than uint16_t
////            if (diff > ser4cpp::UInt16::max_value)
  if(diff > 0xFFFF)
    return false;

////            auto copy = meas;
  AnalogOutputStatus copy = *meas;
//  void DNPTime_in_DNPTimeOver2(DNPTime *pDNPTime, uint64_t value);
  DNPTime dDNPTime;
  DNPTime_in_DNPTimeOver2(&dDNPTime, diff);
////            copy.time = DNPTime(diff);
  copy.tTypedMeasurement_for_Double64.mMeasurement.timeDNPTime = dDNPTime;

//    boolean Write_in_PrefixedWriteIterator_for_UInt16_AnalogOutputStatus(PrefixedWriteIterator_for_UInt16_AnalogOutputStatus *pPrefixedWriteIterator_for_UInt16_AnalogOutputStatus,
//                                                                  AnalogOutputStatus* value, uint16_t index);
////            return this->iterator.Write(copy, index);
  return Write_in_PrefixedWriteIterator_for_UInt16_AnalogOutputStatus(&(parent->iterator), &copy, index);
}
