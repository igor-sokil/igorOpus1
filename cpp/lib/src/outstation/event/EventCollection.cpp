#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
//#include <QtWidgets>
#include "header.h"
#include "EventCollection.h"

//---------------------------------Binary------------------------------------------
void  EventCollection_for_Binary_in_EventCollection_for_Binary(EventCollection_for_Binary *pEventCollection_for_Binary,
    Iterator_in_List_for_EventRecord* iteratorEv,
    EventClassCounters* counters,
    event_variation_t_in_BinaryInfo variation)
{
  pEventCollection_for_Binary->iteratorEv = iteratorEv;
  pEventCollection_for_Binary->counters = counters;
  pEventCollection_for_Binary->variation = variation;

  (pEventCollection_for_Binary->iIEventCollection_for_Binary).pWriteSome_in_IEventCollection_for_Binary =
    WriteSome_in_EventCollection_for_Binary_override;
  setParentPointer_in_IEventCollection_for_Binary(&(pEventCollection_for_Binary->iIEventCollection_for_Binary), pEventCollection_for_Binary);
}

////template<class T> uint16_t EventCollection<T>::WriteSome(IEventWriter<typename T::meas_t>& writer)
uint16_t WriteSome_in_EventCollection_for_Binary_override(void *pIEventCollection_for_Binary, IEventWriter_for_Binary* writer)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"WriteSome_in_EventCollection_for_Binary_override1"<<'\n';
#endif
  uint16_t num_written = 0;

  EventCollection_for_Binary *parent =
    (EventCollection_for_Binary*)getParentPointer_in_IEventCollection_for_Binary((IEventCollection_for_Binary*)pIEventCollection_for_Binary);

  while (WriteOne_in_EventCollection_for_Binary(parent, writer))
  {
    ++num_written;
  }

#ifdef  LOG_INFO
  decrement_stack_info();
#endif
  return num_written;
}

////template<class T> bool EventCollection<T>::WriteOne(IEventWriter<typename T::meas_t>& writer)
boolean WriteOne_in_EventCollection_for_Binary(EventCollection_for_Binary *pEventCollection_for_Binary, IEventWriter_for_Binary* writer)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"WriteOne_in_EventCollection_for_Binary1"<<'\n';
#endif
  // don't bother searching
  if (pEventCollection_for_Binary->counters->selected == 0)
{
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
    return false;
}

  // find the next event with the same type and variation
//    EventRecord* FindNextSelected_in_EventWriting_static(Iterator_in_List_for_EventRecord* iter, EventType_uint16_t type);
////    EventRecord* record = EventWriting::FindNextSelected(this->iterator, T::EventTypeEnum);
  EventRecord* record = FindNextSelected_in_EventWriting_static(pEventCollection_for_Binary->iteratorEv, EventType_Binary);

  // nothing left to write
  if (!record)
{
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
    return false;
}

//Node_TypedEventRecord_for_BinarySpec* Retrieve_in_TypedStorage_for_BinarySpec_static(EventRecord* record);
////    const auto data = TypedStorage<T>::Retrieve(*record);
  Node_TypedEventRecord_for_BinarySpec* data = Retrieve_in_TypedStorage_for_BinarySpec_static(record);

  // wrong variation
  if ((data->value).selectedVariation != pEventCollection_for_Binary->variation)
{
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
    return false;
}

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"WriteOne_in_EventCollection_for_Binary2"<<'\n';
  inspect_Binary(&((data->value).value));
#endif

  // unable to write
//  boolean Write_in_IEventWriter_for_Binary(IEventWriter_for_Binary*, Binary* meas, uint16_t index);
////    if (!writer.Write(data->value.value, record->index))
  if (!Write_in_IEventWriter_for_Binary(writer, &((data->value).value), record->index))
{
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
    return false;
}

  // success!
//void OnWrite_in_EventClassCounters(EventClassCounters *pEventClassCounters, EventClass_uint8_t clazz);
////    this->counters.OnWrite(record->clazz);
  OnWrite_in_EventClassCounters(pEventCollection_for_Binary->counters, record->clazz);
  record->state = EventState_written;
//Node_for_EventRecord* Next__in__Iterator_in_List_for_EventRecord(Iterator_in_List_for_EventRecord *pIterator_in_List_for_EventRecord);
////    this->iterator.Next();
  Next__in__Iterator_in_List_for_EventRecord(pEventCollection_for_Binary->iteratorEv);
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"WriteOne_in_EventCollection_for_Binary3"<<'\n';
  decrement_stack_info();
#endif
  return true;
}
//---------------------------------Binary------------------------------------------
//---------------------------------DoubleBitBinary------------------------------------------

void  EventCollection_for_DoubleBitBinary_in_EventCollection_for_DoubleBitBinary(EventCollection_for_DoubleBitBinary *pEventCollection_for_DoubleBitBinary,
    Iterator_in_List_for_EventRecord* iteratorEv,
    EventClassCounters* counters,
    event_variation_t_in_DoubleBitBinaryInfo variation)
{
  pEventCollection_for_DoubleBitBinary->iteratorEv = iteratorEv;
  pEventCollection_for_DoubleBitBinary->counters = counters;
  pEventCollection_for_DoubleBitBinary->variation = variation;
  (pEventCollection_for_DoubleBitBinary->iIEventCollection_for_DoubleBitBinary).pWriteSome_in_IEventCollection_for_DoubleBitBinary =
    WriteSome_in_EventCollection_for_DoubleBitBinary_override;
  setParentPointer_in_IEventCollection_for_DoubleBitBinary(&(pEventCollection_for_DoubleBitBinary->iIEventCollection_for_DoubleBitBinary), pEventCollection_for_DoubleBitBinary);
}

//uint16_t WriteSome_in_IEventCollection_for_DoubleBitBinary_override(void *pIEventCollection_for_DoubleBitBinary, IEventWriter_for_DoubleBitBinary* writer);
////template<class T> uint16_t EventCollection<T>::WriteSome(IEventWriter<typename T::meas_t>& writer)
uint16_t WriteSome_in_EventCollection_for_DoubleBitBinary_override(void *pIEventCollection_for_DoubleBitBinary, IEventWriter_for_DoubleBitBinary* writer)
{
  uint16_t num_written = 0;

  EventCollection_for_DoubleBitBinary *parent =
    (EventCollection_for_DoubleBitBinary*)getParentPointer_in_IEventCollection_for_DoubleBitBinary((IEventCollection_for_DoubleBitBinary*)pIEventCollection_for_DoubleBitBinary);

  while (WriteOne_in_EventCollection_for_DoubleBitBinary(parent, writer))
  {
    ++num_written;
  }
  return num_written;
}

////template<class T> bool EventCollection<T>::WriteOne(IEventWriter<typename T::meas_t>& writer)
boolean WriteOne_in_EventCollection_for_DoubleBitBinary(EventCollection_for_DoubleBitBinary *pEventCollection_for_DoubleBitBinary, IEventWriter_for_DoubleBitBinary* writer)
{
  // don't bother searching
  if (pEventCollection_for_DoubleBitBinary->counters->selected == 0)
    return false;

  // find the next event with the same type and variation
//    EventRecord* FindNextSelected_in_EventWriting_static(Iterator_in_List_for_EventRecord* iter, EventType_uint16_t type);
////    EventRecord* record = EventWriting::FindNextSelected(this->iterator, T::EventTypeEnum);
  EventRecord* record = FindNextSelected_in_EventWriting_static(pEventCollection_for_DoubleBitBinary->iteratorEv, EventType_DoubleBitBinary);

  // nothing left to write
  if (!record)
    return false;

////    const auto data = TypedStorage<T>::Retrieve(*record);
  Node_TypedEventRecord_for_DoubleBitBinarySpec* data = Retrieve_in_TypedStorage_for_DoubleBitBinarySpec_static(record);

  // wrong variation
  if ((data->value).selectedVariation != pEventCollection_for_DoubleBitBinary->variation)
    return false;

  // unable to write
// boolean (*pWrite_in_IEventWriter_for_DoubleBitBinary)(DoubleBitBinary* meas, uint16_t index);// = 0;
////    if (!writer.Write(data->value.value, record->index))
//  if (!writer->pWrite_in_IEventWriter_for_DoubleBitBinary(&((data->value).value), record->index))
  if (!Write_in_IEventWriter_for_DoubleBitBinary(writer, &((data->value).value), record->index))
    return false;

  // success!
//void OnWrite_in_EventClassCounters(EventClassCounters *pEventClassCounters, EventClass_uint8_t clazz);
////    this->counters.OnWrite(record->clazz);
  OnWrite_in_EventClassCounters(pEventCollection_for_DoubleBitBinary->counters, record->clazz);
  record->state = EventState_written;
//Node_for_EventRecord* Next__in__Iterator_in_List_for_EventRecord(Iterator_in_List_for_EventRecord *pIterator_in_List_for_EventRecord);
////    this->iterator.Next();
  Next__in__Iterator_in_List_for_EventRecord(pEventCollection_for_DoubleBitBinary->iteratorEv);
  return true;
}

//---------------------------------DoubleBitBinary------------------------------------------
//---------------------------------Analog------------------------------------------

void  EventCollection_for_Analog_in_EventCollection_for_Analog(EventCollection_for_Analog *pEventCollection_for_Analog,
    Iterator_in_List_for_EventRecord* iteratorEv,
    EventClassCounters* counters,
    event_variation_t_in_AnalogInfo variation)
{
  pEventCollection_for_Analog->iteratorEv = iteratorEv;
  pEventCollection_for_Analog->counters = counters;
  pEventCollection_for_Analog->variation = variation;
  (pEventCollection_for_Analog->iIEventCollection_for_Analog).pWriteSome_in_IEventCollection_for_Analog =
    WriteSome_in_EventCollection_for_Analog_override;
  setParentPointer_in_IEventCollection_for_Analog(&(pEventCollection_for_Analog->iIEventCollection_for_Analog), pEventCollection_for_Analog);
}

////template<class T> uint16_t EventCollection<T>::WriteSome(IEventWriter<typename T::meas_t>& writer)
uint16_t WriteSome_in_EventCollection_for_Analog_override(void *pIEventCollection_for_Analog, IEventWriter_for_Analog* writer)
{
  uint16_t num_written = 0;
  EventCollection_for_Analog *parent =
    (EventCollection_for_Analog*)getParentPointer_in_IEventCollection_for_Analog((IEventCollection_for_Analog*)pIEventCollection_for_Analog);

  while (WriteOne_in_EventCollection_for_Analog(parent, writer))
  {
    ++num_written;
  }
  return num_written;
}

////template<class T> bool EventCollection<T>::WriteOne(IEventWriter<typename T::meas_t>& writer)
boolean WriteOne_in_EventCollection_for_Analog(EventCollection_for_Analog *pEventCollection_for_Analog, IEventWriter_for_Analog* writer)
{
  // don't bother searching
  if (pEventCollection_for_Analog->counters->selected == 0)
    return false;

  // find the next event with the same type and variation
//    EventRecord* FindNextSelected_in_EventWriting_static(Iterator_in_List_for_EventRecord* iter, EventType_uint16_t type);
////    EventRecord* record = EventWriting::FindNextSelected(this->iterator, T::EventTypeEnum);
  EventRecord* record = FindNextSelected_in_EventWriting_static(pEventCollection_for_Analog->iteratorEv, EventType_Analog);

  // nothing left to write
  if (!record)
    return false;

////    const auto data = TypedStorage<T>::Retrieve(*record);
  Node_TypedEventRecord_for_AnalogSpec* data = Retrieve_in_TypedStorage_for_AnalogSpec_static(record);

  // wrong variation
  if ((data->value).selectedVariation != pEventCollection_for_Analog->variation)
    return false;

  // unable to write
// boolean (*pWrite_in_IEventWriter_for_Analog)(Analog* meas, uint16_t index);// = 0;
////    if (!writer.Write(data->value.value, record->index))
//  if (!writer->pWrite_in_IEventWriter_for_Analog(&((data->value).value), record->index))
  if (!Write_in_IEventWriter_for_Analog(writer, &((data->value).value), record->index))
    return false;

  // success!
//void OnWrite_in_EventClassCounters(EventClassCounters *pEventClassCounters, EventClass_uint8_t clazz);
////    this->counters.OnWrite(record->clazz);
  OnWrite_in_EventClassCounters(pEventCollection_for_Analog->counters, record->clazz);
  record->state = EventState_written;
//Node_for_EventRecord* Next__in__Iterator_in_List_for_EventRecord(Iterator_in_List_for_EventRecord *pIterator_in_List_for_EventRecord);
////    this->iterator.Next();
  Next__in__Iterator_in_List_for_EventRecord(pEventCollection_for_Analog->iteratorEv);
  return true;
}
//---------------------------------Analog------------------------------------------
//---------------------------------Counter------------------------------------------
void  EventCollection_for_Counter_in_EventCollection_for_Counter(EventCollection_for_Counter *pEventCollection_for_Counter,
    Iterator_in_List_for_EventRecord* iteratorEv,
    EventClassCounters* counters,
    event_variation_t_in_CounterInfo variation)
{
  pEventCollection_for_Counter->iteratorEv = iteratorEv;
  pEventCollection_for_Counter->counters = counters;
  pEventCollection_for_Counter->variation = variation;
  (pEventCollection_for_Counter->iIEventCollection_for_Counter).pWriteSome_in_IEventCollection_for_Counter =
    WriteSome_in_EventCollection_for_Counter_override;
  setParentPointer_in_IEventCollection_for_Counter(&(pEventCollection_for_Counter->iIEventCollection_for_Counter), pEventCollection_for_Counter);
}

////template<class T> uint16_t EventCollection<T>::WriteSome(IEventWriter<typename T::meas_t>& writer)
uint16_t WriteSome_in_EventCollection_for_Counter_override(void *pIEventCollection_for_Counter, IEventWriter_for_Counter* writer)
{
  uint16_t num_written = 0;
  EventCollection_for_Counter *parent =
    (EventCollection_for_Counter*)getParentPointer_in_IEventCollection_for_Counter((IEventCollection_for_Counter*)pIEventCollection_for_Counter);

  while (WriteOne_in_EventCollection_for_Counter(parent, writer))
  {
    ++num_written;
  }
  return num_written;
}

////template<class T> bool EventCollection<T>::WriteOne(IEventWriter<typename T::meas_t>& writer)
boolean WriteOne_in_EventCollection_for_Counter(EventCollection_for_Counter *pEventCollection_for_Counter, IEventWriter_for_Counter* writer)
{
  // don't bother searching
  if (pEventCollection_for_Counter->counters->selected == 0)
    return false;

  // find the next event with the same type and variation
//    EventRecord* FindNextSelected_in_EventWriting_static(Iterator_in_List_for_EventRecord* iter, EventType_uint16_t type);
////    EventRecord* record = EventWriting::FindNextSelected(this->iterator, T::EventTypeEnum);
  EventRecord* record = FindNextSelected_in_EventWriting_static(pEventCollection_for_Counter->iteratorEv, EventType_Counter);

  // nothing left to write
  if (!record)
    return false;

////    const auto data = TypedStorage<T>::Retrieve(*record);
  Node_TypedEventRecord_for_CounterSpec* data = Retrieve_in_TypedStorage_for_CounterSpec_static(record);

  // wrong variation
  if ((data->value).selectedVariation != pEventCollection_for_Counter->variation)
    return false;

  // unable to write
// boolean (*pWrite_in_IEventWriter_for_Counter)(Counter* meas, uint16_t index);// = 0;
////    if (!writer.Write(data->value.value, record->index))
//  if (!writer->pWrite_in_IEventWriter_for_Counter(&((data->value).value), record->index))
  if (!Write_in_IEventWriter_for_Counter(writer, &((data->value).value), record->index))
    return false;

  // success!
//void OnWrite_in_EventClassCounters(EventClassCounters *pEventClassCounters, EventClass_uint8_t clazz);
////    this->counters.OnWrite(record->clazz);
  OnWrite_in_EventClassCounters(pEventCollection_for_Counter->counters, record->clazz);
  record->state = EventState_written;
//Node_for_EventRecord* Next__in__Iterator_in_List_for_EventRecord(Iterator_in_List_for_EventRecord *pIterator_in_List_for_EventRecord);
////    this->iterator.Next();
  Next__in__Iterator_in_List_for_EventRecord(pEventCollection_for_Counter->iteratorEv);
  return true;
}

//---------------------------------Counter------------------------------------------
//---------------------------------FrozenCounter------------------------------------------
void  EventCollection_for_FrozenCounter_in_EventCollection_for_FrozenCounter(EventCollection_for_FrozenCounter *pEventCollection_for_FrozenCounter,
    Iterator_in_List_for_EventRecord* iteratorEv,
    EventClassCounters* counters,
    event_variation_t_in_FrozenCounterInfo variation)
{
  pEventCollection_for_FrozenCounter->iteratorEv = iteratorEv;
  pEventCollection_for_FrozenCounter->counters = counters;
  pEventCollection_for_FrozenCounter->variation = variation;
  (pEventCollection_for_FrozenCounter->iIEventCollection_for_FrozenCounter).pWriteSome_in_IEventCollection_for_FrozenCounter =
    WriteSome_in_EventCollection_for_FrozenCounter_override;
  setParentPointer_in_IEventCollection_for_FrozenCounter(&(pEventCollection_for_FrozenCounter->iIEventCollection_for_FrozenCounter), pEventCollection_for_FrozenCounter);
}

////template<class T> uint16_t EventCollection<T>::WriteSome(IEventWriter<typename T::meas_t>& writer)
uint16_t WriteSome_in_EventCollection_for_FrozenCounter_override(void *pIEventCollection_for_FrozenCounter, IEventWriter_for_FrozenCounter* writer)
{
  uint16_t num_written = 0;
  EventCollection_for_FrozenCounter *parent =
    (EventCollection_for_FrozenCounter*)getParentPointer_in_IEventCollection_for_FrozenCounter((IEventCollection_for_FrozenCounter*)pIEventCollection_for_FrozenCounter);

  while (WriteOne_in_EventCollection_for_FrozenCounter(parent, writer))
  {
    ++num_written;
  }
  return num_written;
}

////template<class T> bool EventCollection<T>::WriteOne(IEventWriter<typename T::meas_t>& writer)
boolean WriteOne_in_EventCollection_for_FrozenCounter(EventCollection_for_FrozenCounter *pEventCollection_for_FrozenCounter, IEventWriter_for_FrozenCounter* writer)
{
  // don't bother searching
  if (pEventCollection_for_FrozenCounter->counters->selected == 0)
    return false;

  // find the next event with the same type and variation
//    EventRecord* FindNextSelected_in_EventWriting_static(Iterator_in_List_for_EventRecord* iter, EventType_uint16_t type);
////    EventRecord* record = EventWriting::FindNextSelected(this->iterator, T::EventTypeEnum);
  EventRecord* record = FindNextSelected_in_EventWriting_static(pEventCollection_for_FrozenCounter->iteratorEv, EventType_FrozenCounter);

  // nothing left to write
  if (!record)
    return false;

////    const auto data = TypedStorage<T>::Retrieve(*record);
  Node_TypedEventRecord_for_FrozenCounterSpec* data = Retrieve_in_TypedStorage_for_FrozenCounterSpec_static(record);

  // wrong variation
  if ((data->value).selectedVariation != pEventCollection_for_FrozenCounter->variation)
    return false;

  // unable to write
// boolean (*pWrite_in_IEventWriter_for_FrozenCounter)(FrozenCounter* meas, uint16_t index);// = 0;
////    if (!writer.Write(data->value.value, record->index))
//  if (!writer->pWrite_in_IEventWriter_for_FrozenCounter(&((data->value).value), record->index))
  if (!Write_in_IEventWriter_for_FrozenCounter(writer, &((data->value).value), record->index))
    return false;

  // success!
//void OnWrite_in_EventClassCounters(EventClassCounters *pEventClassCounters, EventClass_uint8_t clazz);
////    this->counters.OnWrite(record->clazz);
  OnWrite_in_EventClassCounters(pEventCollection_for_FrozenCounter->counters, record->clazz);
  record->state = EventState_written;
//Node_for_EventRecord* Next__in__Iterator_in_List_for_EventRecord(Iterator_in_List_for_EventRecord *pIterator_in_List_for_EventRecord);
////    this->iterator.Next();
  Next__in__Iterator_in_List_for_EventRecord(pEventCollection_for_FrozenCounter->iteratorEv);
  return true;
}

//---------------------------------FrozenCounter------------------------------------------
//---------------------------------BinaryOutputStatus------------------------------------------
void  EventCollection_for_BinaryOutputStatus_in_EventCollection_for_BinaryOutputStatus(EventCollection_for_BinaryOutputStatus *pEventCollection_for_BinaryOutputStatus,
    Iterator_in_List_for_EventRecord* iteratorEv,
    EventClassCounters* counters,
    event_variation_t_in_BinaryOutputStatusInfo variation)
{
  pEventCollection_for_BinaryOutputStatus->iteratorEv = iteratorEv;
  pEventCollection_for_BinaryOutputStatus->counters = counters;
  pEventCollection_for_BinaryOutputStatus->variation = variation;
  (pEventCollection_for_BinaryOutputStatus->iIEventCollection_for_BinaryOutputStatus).pWriteSome_in_IEventCollection_for_BinaryOutputStatus =
    WriteSome_in_EventCollection_for_BinaryOutputStatus_override;
  setParentPointer_in_IEventCollection_for_BinaryOutputStatus(&(pEventCollection_for_BinaryOutputStatus->iIEventCollection_for_BinaryOutputStatus), pEventCollection_for_BinaryOutputStatus);
}

////template<class T> uint16_t EventCollection<T>::WriteSome(IEventWriter<typename T::meas_t>& writer)
uint16_t WriteSome_in_EventCollection_for_BinaryOutputStatus_override(void *pIEventCollection_for_BinaryOutputStatus, IEventWriter_for_BinaryOutputStatus* writer)
{
  uint16_t num_written = 0;
  EventCollection_for_BinaryOutputStatus *parent =
    (EventCollection_for_BinaryOutputStatus*)getParentPointer_in_IEventCollection_for_BinaryOutputStatus((IEventCollection_for_BinaryOutputStatus*)pIEventCollection_for_BinaryOutputStatus);

  while (WriteOne_in_EventCollection_for_BinaryOutputStatus(parent, writer))
  {
    ++num_written;
  }
  return num_written;
}

////template<class T> bool EventCollection<T>::WriteOne(IEventWriter<typename T::meas_t>& writer)
boolean WriteOne_in_EventCollection_for_BinaryOutputStatus(EventCollection_for_BinaryOutputStatus *pEventCollection_for_BinaryOutputStatus, IEventWriter_for_BinaryOutputStatus* writer)
{
  // don't bother searching
  if (pEventCollection_for_BinaryOutputStatus->counters->selected == 0)
    return false;

  // find the next event with the same type and variation
//    EventRecord* FindNextSelected_in_EventWriting_static(Iterator_in_List_for_EventRecord* iter, EventType_uint16_t type);
////    EventRecord* record = EventWriting::FindNextSelected(this->iterator, T::EventTypeEnum);
  EventRecord* record = FindNextSelected_in_EventWriting_static(pEventCollection_for_BinaryOutputStatus->iteratorEv, EventType_BinaryOutputStatus);

  // nothing left to write
  if (!record)
    return false;

////    const auto data = TypedStorage<T>::Retrieve(*record);
  Node_TypedEventRecord_for_BinaryOutputStatusSpec* data = Retrieve_in_TypedStorage_for_BinaryOutputStatusSpec_static(record);

  // wrong variation
  if ((data->value).selectedVariation != pEventCollection_for_BinaryOutputStatus->variation)
    return false;

  // unable to write
// boolean (*pWrite_in_IEventWriter_for_BinaryOutputStatus)(BinaryOutputStatus* meas, uint16_t index);// = 0;
////    if (!writer.Write(data->value.value, record->index))
//  if (!writer->pWrite_in_IEventWriter_for_BinaryOutputStatus(&((data->value).value), record->index))
  if (!Write_in_IEventWriter_for_BinaryOutputStatus(writer, &((data->value).value), record->index))
    return false;

  // success!
//void OnWrite_in_EventClassCounters(EventClassCounters *pEventClassCounters, EventClass_uint8_t clazz);
////    this->counters.OnWrite(record->clazz);
  OnWrite_in_EventClassCounters(pEventCollection_for_BinaryOutputStatus->counters, record->clazz);
  record->state = EventState_written;
//Node_for_EventRecord* Next__in__Iterator_in_List_for_EventRecord(Iterator_in_List_for_EventRecord *pIterator_in_List_for_EventRecord);
////    this->iterator.Next();
  Next__in__Iterator_in_List_for_EventRecord(pEventCollection_for_BinaryOutputStatus->iteratorEv);
  return true;
}

//---------------------------------BinaryOutputStatus------------------------------------------
//---------------------------------AnalogOutputStatus------------------------------------------
void  EventCollection_for_AnalogOutputStatus_in_EventCollection_for_AnalogOutputStatus(EventCollection_for_AnalogOutputStatus *pEventCollection_for_AnalogOutputStatus,
    Iterator_in_List_for_EventRecord* iteratorEv,
    EventClassCounters* counters,
    event_variation_t_in_AnalogOutputStatusInfo variation)
{
  pEventCollection_for_AnalogOutputStatus->iteratorEv = iteratorEv;
  pEventCollection_for_AnalogOutputStatus->counters = counters;
  pEventCollection_for_AnalogOutputStatus->variation = variation;
  (pEventCollection_for_AnalogOutputStatus->iIEventCollection_for_AnalogOutputStatus).pWriteSome_in_IEventCollection_for_AnalogOutputStatus =
    WriteSome_in_EventCollection_for_AnalogOutputStatus_override;
  setParentPointer_in_IEventCollection_for_AnalogOutputStatus(&(pEventCollection_for_AnalogOutputStatus->iIEventCollection_for_AnalogOutputStatus), pEventCollection_for_AnalogOutputStatus);
}

////template<class T> uint16_t EventCollection<T>::WriteSome(IEventWriter<typename T::meas_t>& writer)
uint16_t WriteSome_in_EventCollection_for_AnalogOutputStatus_override(void *pIEventCollection_for_AnalogOutputStatus, IEventWriter_for_AnalogOutputStatus* writer)
{
  uint16_t num_written = 0;
  EventCollection_for_AnalogOutputStatus *parent =
    (EventCollection_for_AnalogOutputStatus*)getParentPointer_in_IEventCollection_for_AnalogOutputStatus((IEventCollection_for_AnalogOutputStatus*)pIEventCollection_for_AnalogOutputStatus);

  while (WriteOne_in_EventCollection_for_AnalogOutputStatus(parent, writer))
  {
    ++num_written;
  }
  return num_written;
}

////template<class T> bool EventCollection<T>::WriteOne(IEventWriter<typename T::meas_t>& writer)
boolean WriteOne_in_EventCollection_for_AnalogOutputStatus(EventCollection_for_AnalogOutputStatus *pEventCollection_for_AnalogOutputStatus, IEventWriter_for_AnalogOutputStatus* writer)
{
  // don't bother searching
  if (pEventCollection_for_AnalogOutputStatus->counters->selected == 0)
    return false;

  // find the next event with the same type and variation
//    EventRecord* FindNextSelected_in_EventWriting_static(Iterator_in_List_for_EventRecord* iter, EventType_uint16_t type);
////    EventRecord* record = EventWriting::FindNextSelected(this->iterator, T::EventTypeEnum);
  EventRecord* record = FindNextSelected_in_EventWriting_static(pEventCollection_for_AnalogOutputStatus->iteratorEv, EventType_AnalogOutputStatus);

  // nothing left to write
  if (!record)
    return false;

////    const auto data = TypedStorage<T>::Retrieve(*record);
  Node_TypedEventRecord_for_AnalogOutputStatusSpec* data = Retrieve_in_TypedStorage_for_AnalogOutputStatusSpec_static(record);

  // wrong variation
  if ((data->value).selectedVariation != pEventCollection_for_AnalogOutputStatus->variation)
    return false;

  // unable to write
// boolean (*pWrite_in_IEventWriter_for_AnalogOutputStatus)(AnalogOutputStatus* meas, uint16_t index);// = 0;
////    if (!writer.Write(data->value.value, record->index))
//  if (!writer->pWrite_in_IEventWriter_for_AnalogOutputStatus(&((data->value).value), record->index))
  if (!Write_in_IEventWriter_for_AnalogOutputStatus(writer, &((data->value).value), record->index))
    return false;

  // success!
//void OnWrite_in_EventClassCounters(EventClassCounters *pEventClassCounters, EventClass_uint8_t clazz);
////    this->counters.OnWrite(record->clazz);
  OnWrite_in_EventClassCounters(pEventCollection_for_AnalogOutputStatus->counters, record->clazz);
  record->state = EventState_written;
//Node_for_EventRecord* Next__in__Iterator_in_List_for_EventRecord(Iterator_in_List_for_EventRecord *pIterator_in_List_for_EventRecord);
////    this->iterator.Next();
  Next__in__Iterator_in_List_for_EventRecord(pEventCollection_for_AnalogOutputStatus->iteratorEv);
  return true;
}

//---------------------------------AnalogOutputStatus------------------------------------------
//---------------------------------OctetString------------------------------------------
void  EventCollection_for_OctetString_in_EventCollection_for_OctetString(EventCollection_for_OctetString *pEventCollection_for_OctetString,
    Iterator_in_List_for_EventRecord* iteratorEv,
    EventClassCounters* counters,
    event_variation_t_in_OctetStringInfo variation)
{
  pEventCollection_for_OctetString->iteratorEv = iteratorEv;
  pEventCollection_for_OctetString->counters = counters;
  pEventCollection_for_OctetString->variation = variation;
  (pEventCollection_for_OctetString->iIEventCollection_for_OctetString).pWriteSome_in_IEventCollection_for_OctetString =
    WriteSome_in_EventCollection_for_OctetString_override;
  setParentPointer_in_IEventCollection_for_OctetString(&(pEventCollection_for_OctetString->iIEventCollection_for_OctetString), pEventCollection_for_OctetString);
}

////template<class T> uint16_t EventCollection<T>::WriteSome(IEventWriter<typename T::meas_t>& writer)
uint16_t WriteSome_in_EventCollection_for_OctetString_override(void *pIEventCollection_for_OctetString, IEventWriter_for_OctetString* writer)
{
  uint16_t num_written = 0;
  EventCollection_for_OctetString *parent =
    (EventCollection_for_OctetString*)getParentPointer_in_IEventCollection_for_OctetString((IEventCollection_for_OctetString*)pIEventCollection_for_OctetString);

  while (WriteOne_in_EventCollection_for_OctetString(parent, writer))
  {
    ++num_written;
  }
  return num_written;
}

////template<class T> bool EventCollection<T>::WriteOne(IEventWriter<typename T::meas_t>& writer)
boolean WriteOne_in_EventCollection_for_OctetString(EventCollection_for_OctetString *pEventCollection_for_OctetString, IEventWriter_for_OctetString* writer)
{
  // don't bother searching
  if (pEventCollection_for_OctetString->counters->selected == 0)
    return false;

  // find the next event with the same type and variation
//    EventRecord* FindNextSelected_in_EventWriting_static(Iterator_in_List_for_EventRecord* iter, EventType_uint16_t type);
////    EventRecord* record = EventWriting::FindNextSelected(this->iterator, T::EventTypeEnum);
  EventRecord* record = FindNextSelected_in_EventWriting_static(pEventCollection_for_OctetString->iteratorEv, EventType_OctetString);

  // nothing left to write
  if (!record)
    return false;

////    const auto data = TypedStorage<T>::Retrieve(*record);
  Node_TypedEventRecord_for_OctetStringSpec* data = Retrieve_in_TypedStorage_for_OctetStringSpec_static(record);

  // wrong variation
  if ((data->value).selectedVariation != pEventCollection_for_OctetString->variation)
    return false;

  // unable to write
// boolean (*pWrite_in_IEventWriter_for_OctetString)(OctetString* meas, uint16_t index);// = 0;
////    if (!writer.Write(data->value.value, record->index))
//  if (!writer->pWrite_in_IEventWriter_for_OctetString(&((data->value).value), record->index))
  if (!Write_in_IEventWriter_for_OctetString(writer, &((data->value).value), record->index))
    return false;

  // success!
//void OnWrite_in_EventClassCounters(EventClassCounters *pEventClassCounters, EventClass_uint8_t clazz);
////    this->counters.OnWrite(record->clazz);
  OnWrite_in_EventClassCounters(pEventCollection_for_OctetString->counters, record->clazz);
  record->state = EventState_written;
//Node_for_EventRecord* Next__in__Iterator_in_List_for_EventRecord(Iterator_in_List_for_EventRecord *pIterator_in_List_for_EventRecord);
////    this->iterator.Next();
  Next__in__Iterator_in_List_for_EventRecord(pEventCollection_for_OctetString->iteratorEv);
  return true;
}

//---------------------------------OctetString------------------------------------------
