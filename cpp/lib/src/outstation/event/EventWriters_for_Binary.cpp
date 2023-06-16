#include "header.h"
#include "EventWriters_for_Binary.h"

void BasicEventWriter_for_Binary_destr_BasicEventWriter_for_Binary(BasicEventWriter_for_Binary *pBasicEventWriter_for_Binary)
{
  PrefixedWriteIterator_for_UInt16_Binary_destr_PrefixedWriteIterator_for_UInt16_Binary(&(pBasicEventWriter_for_Binary->iterator));
}

////    template<class T>
uint16_t Write_for_Binary_in_EventWriters_static(HeaderWriter* writer, IEventCollection_for_Binary* items, DNP3Serializer_for_Binary* serializer)
{
//void BasicEventWriter_for_Binary_in_BasicEventWriter_for_Binary(BasicEventWriter_for_Binary *pBasicEventWriter_for_Binary,
//    HeaderWriter* writer, DNP3Serializer_for_Binary* serializer);
////  BasicEventWriter_for_Binary handler(writer, serializer);
 BasicEventWriter_for_Binary handler;
 BasicEventWriter_for_Binary_in_BasicEventWriter_for_Binary(&handler, writer, serializer);
//  uint16_t WriteSome_in_IEventCollection_for_Binary(IEventCollection_for_Binary *, IEventWriter_for_Binary* handler);
///        return items.WriteSome(handler);
  uint16_t temp = WriteSome_in_IEventCollection_for_Binary(items, &(handler.iIEventWriter_for_Binary));
  BasicEventWriter_for_Binary_destr_BasicEventWriter_for_Binary(&handler);
  return temp;
}

////        BasicEventWriter(HeaderWriter& writer, const DNP3Serializer<T>& serializer)
////            : iterator(writer.IterateOverCountWithPrefix<ser4cpp::UInt16, T>(QualifierCode::UINT16_CNT_UINT16_INDEX,
////                                                                             serializer))
void BasicEventWriter_for_Binary_in_BasicEventWriter_for_Binary(BasicEventWriter_for_Binary *pBasicEventWriter_for_Binary,
    HeaderWriter* writer, DNP3Serializer_for_Binary* serializer)
{
  PrefixedWriteIterator_for_UInt16_Binary temp = IterateOverCountWithPrefix_for_UInt16_Binary_in_HeaderWriter(writer, QualifierCode_UINT16_CNT_UINT16_INDEX, serializer);
  pBasicEventWriter_for_Binary->iterator = temp;

  (pBasicEventWriter_for_Binary->iIEventWriter_for_Binary).pWrite_in_IEventWriter_for_Binary = Write_in_BasicEventWriter_for_Binary_override;
//  (pBasicEventWriter_for_Binary->iIEventWriter_for_Binary).pParentPointer_in_IEventWriter_for_Binary = pBasicEventWriter_for_Binary;
  setParentPointer_in_IEventWriter_for_Binary(&(pBasicEventWriter_for_Binary->iIEventWriter_for_Binary), pBasicEventWriter_for_Binary);
//  (pBasicEventWriter_for_Binary->iIEventWriter_for_Binary).parentType_in_IEventWriter_for_Binary = PARENTTYPE_BasicEventWriter_for_Binary;
  setParentType_in_IEventWriter_for_Binary(&(pBasicEventWriter_for_Binary->iIEventWriter_for_Binary), PARENTTYPE_BasicEventWriter_for_Binary);
}

////        virtual bool Write(const T& meas, uint16_t index) override
boolean Write_in_BasicEventWriter_for_Binary_override(void* pIEventWriter_for_Binary, Binary* meas, uint16_t index)
{
  if(getParentType_in_IEventWriter_for_Binary((IEventWriter_for_Binary*)pIEventWriter_for_Binary) == PARENTTYPE_BasicEventWriter_for_Binary)
  {
    BasicEventWriter_for_Binary* parent = (BasicEventWriter_for_Binary*) getParentPointer_in_IEventWriter_for_Binary((IEventWriter_for_Binary*) pIEventWriter_for_Binary);
//    boolean IsValid_in_PrefixedWriteIterator_for_UInt16_Binary(PrefixedWriteIterator_for_UInt16_Binary *pPrefixedWriteIterator_for_UInt16_Binary);
////            return iterator.IsValid() ? iterator.Write(meas, index) : false;
    return IsValid_in_PrefixedWriteIterator_for_UInt16_Binary(&(parent->iterator)) ?
           Write_in_PrefixedWriteIterator_for_UInt16_Binary(&(parent->iterator), meas, index) : false;
//    boolean Write_in_PrefixedWriteIterator_for_UInt16_Binary(PrefixedWriteIterator_for_UInt16_Binary *pPrefixedWriteIterator_for_UInt16_Binary,
//                                                                  Binary* value, uint16_t index);
  }
  return false;//ERROR!
}

////        CTOEventWriter(const U& cto, HeaderWriter& writer, const DNP3Serializer<T>& serializer)
////            : cto(cto.time),
////              iterator(writer.IterateOverCountWithPrefixAndCTO<ser4cpp::UInt16, T, U>(
////                  QualifierCode::UINT16_CNT_UINT16_INDEX, serializer, cto))
void CTOEventWriter_for_Binary_Group51Var1_in_CTOEventWriter_for_Binary_Group51Var1(CTOEventWriter_for_Binary_Group51Var1 *pCTOEventWriter_for_Binary_Group51Var1,
    Group51Var1* cto,
    HeaderWriter* writer,
    DNP3Serializer_for_Binary* serializer)
{
  DNPTime_in_DNPTimeOver2(&(pCTOEventWriter_for_Binary_Group51Var1->cto), (cto->timeDNPTime).value);

  PrefixedWriteIterator_for_UInt16_Binary temp = IterateOverCountWithPrefixAndCTO_for_UInt16_Binary_Group51Var1_in_HeaderWriter(
        writer,
        QualifierCode_UINT16_CNT_UINT16_INDEX,
        serializer,
        cto
      );
  pCTOEventWriter_for_Binary_Group51Var1->iterator = temp;

  (pCTOEventWriter_for_Binary_Group51Var1->iIEventWriter_for_Binary).pWrite_in_IEventWriter_for_Binary = Write_in_CTOEventWriter_for_Binary_Group51Var1_override;
//  (pCTOEventWriter_for_Binary_Group51Var1->iIEventWriter_for_Binary).pParentPointer_in_IEventWriter_for_Binary = pCTOEventWriter_for_Binary_Group51Var1;
  setParentPointer_in_IEventWriter_for_Binary(&(pCTOEventWriter_for_Binary_Group51Var1->iIEventWriter_for_Binary), pCTOEventWriter_for_Binary_Group51Var1);
//  (pCTOEventWriter_for_Binary_Group51Var1->iIEventWriter_for_Binary).parentType_in_IEventWriter_for_Binary = PARENTTYPE_CTOEventWriter_for_Binary_Group51Var1;
  setParentType_in_IEventWriter_for_Binary(&(pCTOEventWriter_for_Binary_Group51Var1->iIEventWriter_for_Binary), PARENTTYPE_CTOEventWriter_for_Binary_Group51Var1);
}

////        virtual bool Write(const T& meas, uint16_t index) override
boolean Write_in_CTOEventWriter_for_Binary_Group51Var1_override(void* pIEventWriter_for_Binary, Binary* meas, uint16_t index)
{
//  if(((IEventWriter_for_Binary*)pIEventWriter_for_Binary)->parentType_in_IEventWriter_for_Binary == PARENTTYPE_CTOEventWriter_for_Binary_Group51Var1)
  if(getParentType_in_IEventWriter_for_Binary((IEventWriter_for_Binary*) pIEventWriter_for_Binary) == PARENTTYPE_BasicEventWriter_for_Binary)
  {
    CTOEventWriter_for_Binary_Group51Var1* parent = (CTOEventWriter_for_Binary_Group51Var1*) getParentPointer_in_IEventWriter_for_Binary((IEventWriter_for_Binary*) pIEventWriter_for_Binary);

//    boolean IsValid_in_PrefixedWriteIterator_for_UInt16_Binary(PrefixedWriteIterator_for_UInt16_Binary *pPrefixedWriteIterator_for_UInt16_Binary);
////            if (!this->iterator.IsValid())
    if(!IsValid_in_PrefixedWriteIterator_for_UInt16_Binary(&(parent->iterator)))
      return false;

    // Check that the quality of the measurement fits with the CTO variation
    if ((parent->cto).quality == TimestampQuality_SYNCHRONIZED)
    {
      if ((meas->tTypedMeasurement_for_Boolean).mMeasurement.timeDNPTime.quality != TimestampQuality_SYNCHRONIZED)
        return false;
    }
    else
    {
////                if (meas.time.quality == TimestampQuality::SYNCHRONIZED)
      if ((meas->tTypedMeasurement_for_Boolean).mMeasurement.timeDNPTime.quality == TimestampQuality_SYNCHRONIZED)
        return false;
    }

    // can't encode timestamps that go backwards
////            if (meas.time.value < this->cto.value)
    if ((meas->tTypedMeasurement_for_Boolean).mMeasurement.timeDNPTime.value < parent->cto.value)
      return false;

////            const auto diff = meas.time.value - this->cto.value;
    uint64_t diff = (meas->tTypedMeasurement_for_Boolean).mMeasurement.timeDNPTime.value - parent->cto.value;

    // can't encode timestamps where the diff is greater than uint16_t
////            if (diff > ser4cpp::UInt16::max_value)
    if(diff > 0xFFFF)
      return false;

////            auto copy = meas;
    Binary copy = *meas;
//  void DNPTime_in_DNPTimeOver2(DNPTime *pDNPTime, uint64_t value);
    DNPTime dDNPTime;
    DNPTime_in_DNPTimeOver2(&dDNPTime, diff);
////            copy.time = DNPTime(diff);
    copy.tTypedMeasurement_for_Boolean.mMeasurement.timeDNPTime = dDNPTime;

//    boolean Write_in_PrefixedWriteIterator_for_UInt16_Binary(PrefixedWriteIterator_for_UInt16_Binary *pPrefixedWriteIterator_for_UInt16_Binary,
//                                                                  Binary* value, uint16_t index);
////            return this->iterator.Write(copy, index);
    return Write_in_PrefixedWriteIterator_for_UInt16_Binary(&(parent->iterator), &copy, index);
  }
  return false;//ERROR!
}
