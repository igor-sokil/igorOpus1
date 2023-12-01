#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "EventWriters_for_Binary.h"
#include "HeaderWriter_for_Binary.h"

void BasicEventWriter_for_Binary_destr_BasicEventWriter_for_Binary(BasicEventWriter_for_Binary *pBasicEventWriter_for_Binary)
{
  PrefixedWriteIterator_for_UInt16_Binary_destr_PrefixedWriteIterator_for_UInt16_Binary(&(pBasicEventWriter_for_Binary->iterator));
}

////    template<class T>
uint16_t Write_for_Binary_in_EventWriters_static(HeaderWriter* writer, IEventCollection_for_Binary* items, DNP3Serializer_for_Binary* serializer)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"Write_for_Binary_in_EventWriters_static1"<<'\n';
#endif
//void BasicEventWriter_for_Binary_in_BasicEventWriter_for_Binary(BasicEventWriter_for_Binary *pBasicEventWriter_for_Binary,
//    HeaderWriter* writer, DNP3Serializer_for_Binary* serializer);
////  BasicEventWriter_for_Binary handler(writer, serializer);
  BasicEventWriter_for_Binary handler;
  BasicEventWriter_for_Binary_in_BasicEventWriter_for_Binary(&handler, writer, serializer);
//  uint16_t WriteSome_in_IEventCollection_for_Binary(IEventCollection_for_Binary *, IEventWriter_for_Binary* handler);
///        return items.WriteSome(handler);
  uint16_t temp = WriteSome_in_IEventCollection_for_Binary(items, &(handler.iIEventWriter_for_Binary));

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"Write_for_Binary_in_EventWriters_static2"<<'\n';
#endif

  BasicEventWriter_for_Binary_destr_BasicEventWriter_for_Binary(&handler);
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
  return temp;
}

////        BasicEventWriter(HeaderWriter& writer, const DNP3Serializer<T>& serializer)
////            : iterator(writer.IterateOverCountWithPrefix<ser4cpp::UInt16, T>(QualifierCode::UINT16_CNT_UINT16_INDEX,
////                                                                             serializer))
void BasicEventWriter_for_Binary_in_BasicEventWriter_for_Binary(BasicEventWriter_for_Binary *pBasicEventWriter_for_Binary,
    HeaderWriter* writer, DNP3Serializer_for_Binary* serializer)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"BasicEventWriter_for_Binary_in_BasicEventWriter_for_Binary1"<<'\n';
#endif
  PrefixedWriteIterator_for_UInt16_Binary temp = IterateOverCountWithPrefix_for_UInt16_Binary_in_HeaderWriter(writer, QualifierCode_UINT16_CNT_UINT16_INDEX, serializer);
  pBasicEventWriter_for_Binary->iterator = temp;

  (pBasicEventWriter_for_Binary->iIEventWriter_for_Binary).pWrite_in_IEventWriter_for_Binary = Write_in_BasicEventWriter_for_Binary_override;
  setParentPointer_in_IEventWriter_for_Binary(&(pBasicEventWriter_for_Binary->iIEventWriter_for_Binary), pBasicEventWriter_for_Binary);
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
}

////        virtual bool Write(const T& meas, uint16_t index) override
boolean Write_in_BasicEventWriter_for_Binary_override(void* pIEventWriter_for_Binary, Binary* meas, uint16_t index)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"Write_in_BasicEventWriter_for_Binary_override1"<<'\n';
#endif
  BasicEventWriter_for_Binary* parent = (BasicEventWriter_for_Binary*) getParentPointer_in_IEventWriter_for_Binary((IEventWriter_for_Binary*) pIEventWriter_for_Binary);
//    boolean IsValid_in_PrefixedWriteIterator_for_UInt16_Binary(PrefixedWriteIterator_for_UInt16_Binary *pPrefixedWriteIterator_for_UInt16_Binary);
////            return iterator.IsValid() ? iterator.Write(meas, index) : false;
  boolean tmp = IsValid_in_PrefixedWriteIterator_for_UInt16_Binary(&(parent->iterator)) ?
         Write_in_PrefixedWriteIterator_for_UInt16_Binary(&(parent->iterator), meas, index) : false;
//    boolean Write_in_PrefixedWriteIterator_for_UInt16_Binary(PrefixedWriteIterator_for_UInt16_Binary *pPrefixedWriteIterator_for_UInt16_Binary,
//                                                                  Binary* value, uint16_t index);
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
  return tmp;
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
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"CTOEventWriter_for_Binary_Group51Var1_in_CTOEventWriter_for_Binary_Group51Var1_1"<<'\n';
#endif

  pCTOEventWriter_for_Binary_Group51Var1->cto = cto->timeDNPTime;

  //PrefixedWriteIterator_for_UInt16_Binary temp
  pCTOEventWriter_for_Binary_Group51Var1->iterator = IterateOverCountWithPrefixAndCTO_for_UInt16_Binary_Group51Var1_in_HeaderWriter(
        writer,
        QualifierCode_UINT16_CNT_UINT16_INDEX,
        serializer,
        cto
      );
//  pCTOEventWriter_for_Binary_Group51Var1->iterator = temp;

  (pCTOEventWriter_for_Binary_Group51Var1->iIEventWriter_for_Binary).pWrite_in_IEventWriter_for_Binary = Write_in_CTOEventWriter_for_Binary_Group51Var1_override;
  setParentPointer_in_IEventWriter_for_Binary(&(pCTOEventWriter_for_Binary_Group51Var1->iIEventWriter_for_Binary), pCTOEventWriter_for_Binary_Group51Var1);
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
}

////        virtual bool Write(const T& meas, uint16_t index) override
boolean Write_in_CTOEventWriter_for_Binary_Group51Var1_override(void* pIEventWriter_for_Binary, Binary* meas, uint16_t index)
{
  CTOEventWriter_for_Binary_Group51Var1* parent = (CTOEventWriter_for_Binary_Group51Var1*) getParentPointer_in_IEventWriter_for_Binary((IEventWriter_for_Binary*) pIEventWriter_for_Binary);

#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"Write_in_CTOEventWriter_for_Binary_Group51Var1_override1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*(parent->cto).quality= "<<(uint16_t)(parent->cto).quality<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*TimestampQuality_SYNCHRONIZED= "<<(uint16_t)TimestampQuality_SYNCHRONIZED<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*TimestampQuality_UNSYNCHRONIZED= "<<(uint16_t)TimestampQuality_UNSYNCHRONIZED<<'\n';
#endif

//    boolean IsValid_in_PrefixedWriteIterator_for_UInt16_Binary(PrefixedWriteIterator_for_UInt16_Binary *pPrefixedWriteIterator_for_UInt16_Binary);
////            if (!this->iterator.IsValid())
  if(!IsValid_in_PrefixedWriteIterator_for_UInt16_Binary(&(parent->iterator)))
{
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"Write_in_CTOEventWriter_for_Binary_Group51Var1_override2"<<'\n';
  decrement_stack_info();
#endif
    return false;
}

  // Check that the quality of the measurement fits with the CTO variation
  if ((parent->cto).quality == TimestampQuality_SYNCHRONIZED)
  {
    if ((meas->tTypedMeasurement_for_Boolean).mMeasurement.timeDNPTime.quality != TimestampQuality_SYNCHRONIZED)
{
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"Write_in_CTOEventWriter_for_Binary_Group51Var1_override3"<<'\n';
  decrement_stack_info();
#endif
      return false;
}
  }
  else
  {
////                if (meas.time.quality == TimestampQuality::SYNCHRONIZED)
    if ((meas->tTypedMeasurement_for_Boolean).mMeasurement.timeDNPTime.quality == TimestampQuality_SYNCHRONIZED)
{
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"Write_in_CTOEventWriter_for_Binary_Group51Var1_override4"<<'\n';
  decrement_stack_info();
#endif
      return false;
}
  }

  // can't encode timestamps that go backwards
////            if (meas.time.value < this->cto.value)
  if ((meas->tTypedMeasurement_for_Boolean).mMeasurement.timeDNPTime.value < parent->cto.value)
{
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"Write_in_CTOEventWriter_for_Binary_Group51Var1_override5"<<'\n';
  decrement_stack_info();
#endif
    return false;
}

////            const auto diff = meas.time.value - this->cto.value;
  uint64_t diff = (meas->tTypedMeasurement_for_Boolean).mMeasurement.timeDNPTime.value - parent->cto.value;

  // can't encode timestamps where the diff is greater than uint16_t
////            if (diff > ser4cpp::UInt16::max_value)
  if(diff > 0xFFFF)
{
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"Write_in_CTOEventWriter_for_Binary_Group51Var1_override6"<<'\n';
  decrement_stack_info();
#endif
    return false;
}

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
  boolean tmp = Write_in_PrefixedWriteIterator_for_UInt16_Binary(&(parent->iterator), &copy, index);
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"Write_in_CTOEventWriter_for_Binary_Group51Var1_override7"<<'\n';
  inspect_Binary(&copy);
  decrement_stack_info();
#endif
  return tmp;
}

uint16_t WriteWithCTO_for_Binary_in_EventWriters_static(DNPTime* cto,
    HeaderWriter* writer,
    IEventCollection_for_Binary* items,
    DNP3Serializer_for_Binary* serializer)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"WriteWithCTO_for_Binary_in_EventWriters_static1"<<'\n';
#endif

  if (cto->quality == TimestampQuality_SYNCHRONIZED)
  {
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"WriteWithCTO_for_Binary_in_EventWriters_static2"<<'\n';
#endif
    Group51Var1 value;
    value.timeDNPTime = *cto;
//void CTOEventWriter_for_Binary_Group51Var1_in_CTOEventWriter_for_Binary_Group51Var1(CTOEventWriter_for_Binary_Group51Var1 *pCTOEventWriter_for_Binary_Group51Var1,
//    Group51Var1* cto,
//    HeaderWriter* writer,
//    DNP3Serializer_for_Binary* serializer);
////            CTOEventWriter<T, Group51Var1> handler(value, writer, serializer);
    CTOEventWriter_for_Binary_Group51Var1 handler;
    CTOEventWriter_for_Binary_Group51Var1_in_CTOEventWriter_for_Binary_Group51Var1(&handler,
        &value,
        writer,
        serializer);
//  uint16_t WriteSome_in_IEventCollection_for_Binary(IEventCollection_for_Binary *, IEventWriter_for_Binary* handler);
////            return items.WriteSome(handler);
    uint16_t tmp = WriteSome_in_IEventCollection_for_Binary(items, &(handler.iIEventWriter_for_Binary));
    PrefixedWriteIterator_for_UInt16_Binary_destr_PrefixedWriteIterator_for_UInt16_Binary(&handler.iterator);
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"WriteWithCTO_for_Binary_in_EventWriters_static3"<<'\n';
  decrement_stack_info();
#endif
    return tmp;
  }
  else
  {
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"WriteWithCTO_for_Binary_in_EventWriters_static4"<<'\n';
#endif
    Group51Var2 value;
////            value.time = cto;
    value.timeDNPTime = *cto;
////            CTOEventWriter<T, Group51Var2> handler(value, writer, serializer);
    CTOEventWriter_for_Binary_Group51Var2 handler;
    CTOEventWriter_for_Binary_Group51Var2_in_CTOEventWriter_for_Binary_Group51Var2(&handler,
        &value,
        writer,
        serializer);
////            return items.WriteSome(handler);
    uint16_t tmp = WriteSome_in_IEventCollection_for_Binary(items, &(handler.iIEventWriter_for_Binary));
    PrefixedWriteIterator_for_UInt16_Binary_destr_PrefixedWriteIterator_for_UInt16_Binary(&handler.iterator);
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"WriteWithCTO_for_Binary_in_EventWriters_static5"<<'\n';
  decrement_stack_info();
#endif
    return tmp;
  }
}

////        CTOEventWriter(const U& cto, HeaderWriter& writer, const DNP3Serializer<T>& serializer)
////            : cto(cto.time),
////              iterator(writer.IterateOverCountWithPrefixAndCTO<ser4cpp::UInt16, T, U>(
////                  QualifierCode::UINT16_CNT_UINT16_INDEX, serializer, cto))
void CTOEventWriter_for_Binary_Group51Var2_in_CTOEventWriter_for_Binary_Group51Var2(CTOEventWriter_for_Binary_Group51Var2 *pCTOEventWriter_for_Binary_Group51Var2,
    Group51Var2* cto,
    HeaderWriter* writer,
    DNP3Serializer_for_Binary* serializer)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"CTOEventWriter_for_Binary_Group51Var2_in_CTOEventWriter_for_Binary_Group51Var2_1"<<'\n';
#endif
  pCTOEventWriter_for_Binary_Group51Var2->cto = cto->timeDNPTime;

  //PrefixedWriteIterator_for_UInt16_Binary temp
  pCTOEventWriter_for_Binary_Group51Var2->iterator = IterateOverCountWithPrefixAndCTO_for_UInt16_Binary_Group51Var2_in_HeaderWriter(
        writer,
        QualifierCode_UINT16_CNT_UINT16_INDEX,
        serializer,
        cto
      );
//  pCTOEventWriter_for_Binary_Group51Var2->iterator = temp;

  (pCTOEventWriter_for_Binary_Group51Var2->iIEventWriter_for_Binary).pWrite_in_IEventWriter_for_Binary = Write_in_CTOEventWriter_for_Binary_Group51Var2_override;
  setParentPointer_in_IEventWriter_for_Binary(&(pCTOEventWriter_for_Binary_Group51Var2->iIEventWriter_for_Binary), pCTOEventWriter_for_Binary_Group51Var2);
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
}

////        virtual bool Write(const T& meas, uint16_t index) override
boolean Write_in_CTOEventWriter_for_Binary_Group51Var2_override(void* pIEventWriter_for_Binary, Binary* meas, uint16_t index)
{
  CTOEventWriter_for_Binary_Group51Var2* parent = (CTOEventWriter_for_Binary_Group51Var2*) getParentPointer_in_IEventWriter_for_Binary((IEventWriter_for_Binary*) pIEventWriter_for_Binary);

#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"Write_in_CTOEventWriter_for_Binary_Group51Var2_override1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*(parent->cto).quality= "<<(uint16_t)(parent->cto).quality<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*TimestampQuality_SYNCHRONIZED= "<<(uint16_t)TimestampQuality_SYNCHRONIZED<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*TimestampQuality_UNSYNCHRONIZED= "<<(uint16_t)TimestampQuality_UNSYNCHRONIZED<<'\n';
#endif

//    boolean IsValid_in_PrefixedWriteIterator_for_UInt16_Binary(PrefixedWriteIterator_for_UInt16_Binary *pPrefixedWriteIterator_for_UInt16_Binary);
////            if (!this->iterator.IsValid())
  if(!IsValid_in_PrefixedWriteIterator_for_UInt16_Binary(&(parent->iterator)))
{
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"Write_in_CTOEventWriter_for_Binary_Group51Var2_override2"<<'\n';
  decrement_stack_info();
#endif
    return false;
}

  // Check that the quality of the measurement fits with the CTO variation
  if ((parent->cto).quality == TimestampQuality_SYNCHRONIZED)
  {
    if ((meas->tTypedMeasurement_for_Boolean).mMeasurement.timeDNPTime.quality != TimestampQuality_SYNCHRONIZED)
{
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"Write_in_CTOEventWriter_for_Binary_Group51Var2_override3"<<'\n';
  decrement_stack_info();
#endif
      return false;
}
  }
  else
  {
////                if (meas.time.quality == TimestampQuality::SYNCHRONIZED)
    if ((meas->tTypedMeasurement_for_Boolean).mMeasurement.timeDNPTime.quality == TimestampQuality_SYNCHRONIZED)
{
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"Write_in_CTOEventWriter_for_Binary_Group51Var2_override4"<<'\n';
  decrement_stack_info();
#endif
      return false;
}
  }

  // can't encode timestamps that go backwards
////            if (meas.time.value < this->cto.value)
  if ((meas->tTypedMeasurement_for_Boolean).mMeasurement.timeDNPTime.value < parent->cto.value)
{
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"Write_in_CTOEventWriter_for_Binary_Group51Var2_override5"<<'\n';
  decrement_stack_info();
#endif
    return false;
}

////            const auto diff = meas.time.value - this->cto.value;
  uint64_t diff = (meas->tTypedMeasurement_for_Boolean).mMeasurement.timeDNPTime.value - parent->cto.value;

  // can't encode timestamps where the diff is greater than uint16_t
////            if (diff > ser4cpp::UInt16::max_value)
  if(diff > 0xFFFF)
{
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"Write_in_CTOEventWriter_for_Binary_Group51Var2_override6"<<'\n';
  decrement_stack_info();
#endif
    return false;
}

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
  boolean tmp = Write_in_PrefixedWriteIterator_for_UInt16_Binary(&(parent->iterator), &copy, index);
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"Write_in_CTOEventWriter_for_Binary_Group51Var2_override7"<<'\n';
  inspect_Binary(&copy);
  decrement_stack_info();
#endif
  return tmp;
}
