#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "EventUpdate.h"

//----------------------------------BinarySpec-------------------------------------------
boolean Update_BinarySpec_in_EventUpdate_static(EventLists* lists, Event_for_BinarySpec* event)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"Update_BinarySpec_in_EventUpdate_static1"<<'\n';
#endif

////    auto& list = lists.GetList<T>();
  List_TypedEventRecord_for_BinarySpec*  listEv = GetList_for_BinarySpec_in_EventLists(lists);

  // lists with no capacity don't cause "buffer overflow"
//     uint32_t Capacity_in_List_TypedEventRecord_for_BinarySpec(List_TypedEventRecord_for_BinarySpec *pList_TypedEventRecord_for_BinarySpec)
////    if (list.Capacity() == 0)
  if(Capacity_in_List_TypedEventRecord_for_BinarySpec(listEv) == 0)
{
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
    return false;
}

  boolean overflow = false;

//boolean IsFullAndCapacityNotZero_in_List_TypedEventRecord_for_BinarySpec(List_TypedEventRecord_for_BinarySpec *pList_TypedEventRecord_for_BinarySpec)
////    if (list.IsFullAndCapacityNotZero())
  if(IsFullAndCapacityNotZero_in_List_TypedEventRecord_for_BinarySpec(listEv))
  {
    // we must make space

    overflow = true;
////        const auto first = list.Head();
    Node_TypedEventRecord_for_BinarySpec* first = Head_in_List_TypedEventRecord_for_BinarySpec(listEv);
////        const auto record_node = first->value.record;
    Node_for_EventRecord* record_node = (first->value).record;

    // remove the generic record
//void OnRemove_in_EventClassCounters(EventClassCounters *pEventClassCounters, EventClass_uint8_t clazz, EventState_uint8_t state);
////        lists.counters.OnRemove(record_node->value.clazz, record_node->value.state);
    OnRemove_in_EventClassCounters(&(lists->counters), record_node->value.clazz, record_node->value.state);
//   void Remove_in_List_for_EventRecord(List_for_EventRecord *pList_for_EventRecord, Node_for_EventRecord* node);
////        lists.events.Remove(first->value.record);
    Remove_in_List_for_EventRecord(&(lists->events), first->value.record);

    // remove the type specific record
//void Remove_in_List_TypedEventRecord_for_BinarySpec(List_TypedEventRecord_for_BinarySpec *pList_TypedEventRecord_for_BinarySpec, Node_TypedEventRecord_for_BinarySpec* node);
////        list.Remove(first);
    Remove_in_List_TypedEventRecord_for_BinarySpec(listEv, first);
  }

  // now that we know that space exists, create the generic record
//Node_for_EventRecord* Add_in_List_for_EventRecord(List_for_EventRecord *pList_for_EventRecord, EventRecord* value);
////    const auto record_node = lists.events.Add(EventRecord(event.index, event.clazz));
//void EventRecord_in_EventRecordOver2(EventRecord *pEventRecord, uint16_t index, EventClass_uint8_t clazz);
  EventRecord eEventRecord;
  EventRecord_in_EventRecordOver2(&eEventRecord, event->eEvented.index, event->eEvented.clazz);
  Node_for_EventRecord* record_node = Add_in_List_for_EventRecord(&(lists->events), &eEventRecord);

  // followed by the typed record
////    const auto typed_node = list.Add(TypedEventRecord<T>(event.value, event.variation, record_node));
  TypedEventRecord_for_BinarySpec tTypedEventRecord_for_BinarySpec;
  TypedEventRecord_for_BinarySpec_in_TypedEventRecord_for_BinarySpec(&tTypedEventRecord_for_BinarySpec,
      &(event->value),
      event->variation,
      record_node);
  Node_TypedEventRecord_for_BinarySpec* typed_node = Add_in_List_TypedEventRecord_for_BinarySpec(listEv,
      &tTypedEventRecord_for_BinarySpec);

  // configure the typed storage
//IEventType* Instance_in_EventTypeImpl_TypedEventRecord_for_BinarySpec_static(void);
////    record_node->value.type = EventTypeImpl<T>::Instance();
  (record_node->value).type = Instance_in_EventTypeImpl_TypedEventRecord_for_BinarySpec_static();

  record_node->value.storage_node = typed_node;

//void OnAdd_in_EventClassCounters(EventClassCounters *pEventClassCounters, EventClass_uint8_t clazz);
////    lists.counters.OnAdd(event.clazz);
  OnAdd_in_EventClassCounters(&(lists->counters), event->eEvented.clazz);

#ifdef  LOG_INFO
  decrement_stack_info();
#endif
  return overflow;
}
//----------------------------------BinarySpec-------------------------------------------
//----------------------------------DoubleBitBinarySpec-------------------------------------------

boolean Update_DoubleBitBinarySpec_in_EventUpdate_static(EventLists* lists, Event_for_DoubleBitBinarySpec* event)
{
////    auto& list = lists.GetList<T>();
  List_TypedEventRecord_for_DoubleBitBinarySpec*  listEv = GetList_for_DoubleBitBinarySpec_in_EventLists(lists);

  // lists with no capacity don't cause "buffer overflow"
//     uint32_t Capacity_in_List_TypedEventRecord_for_DoubleBitBinarySpec(List_TypedEventRecord_for_DoubleBitBinarySpec *pList_TypedEventRecord_for_DoubleBitBinarySpec)
////    if (list.Capacity() == 0)
  if(Capacity_in_List_TypedEventRecord_for_DoubleBitBinarySpec(listEv) == 0)
    return false;

  boolean overflow = false;

//boolean IsFullAndCapacityNotZero_in_List_TypedEventRecord_for_DoubleBitBinarySpec(List_TypedEventRecord_for_DoubleBitBinarySpec *pList_TypedEventRecord_for_DoubleBitBinarySpec)
////    if (list.IsFullAndCapacityNotZero())
  if(IsFullAndCapacityNotZero_in_List_TypedEventRecord_for_DoubleBitBinarySpec(listEv))
  {
    // we must make space

    overflow = true;
////        const auto first = list.Head();
    Node_TypedEventRecord_for_DoubleBitBinarySpec* first = Head_in_List_TypedEventRecord_for_DoubleBitBinarySpec(listEv);
////        const auto record_node = first->value.record;
    Node_for_EventRecord* record_node = (first->value).record;

    // remove the generic record
//void OnRemove_in_EventClassCounters(EventClassCounters *pEventClassCounters, EventClass_uint8_t clazz, EventState_uint8_t state);
////        lists.counters.OnRemove(record_node->value.clazz, record_node->value.state);
    OnRemove_in_EventClassCounters(&(lists->counters), record_node->value.clazz, record_node->value.state);
//   void Remove_in_List_for_EventRecord(List_for_EventRecord *pList_for_EventRecord, Node_for_EventRecord* node);
////        lists.events.Remove(first->value.record);
    Remove_in_List_for_EventRecord(&(lists->events), first->value.record);

    // remove the type specific record
//void Remove_in_List_TypedEventRecord_for_DoubleBitBinarySpec(List_TypedEventRecord_for_DoubleBitBinarySpec *pList_TypedEventRecord_for_DoubleBitBinarySpec, Node_TypedEventRecord_for_DoubleBitBinarySpec* node);
////        list.Remove(first);
    Remove_in_List_TypedEventRecord_for_DoubleBitBinarySpec(listEv, first);
  }

  // now that we know that space exists, create the generic record
//Node_for_EventRecord* Add_in_List_for_EventRecord(List_for_EventRecord *pList_for_EventRecord, EventRecord* value);
////    const auto record_node = lists.events.Add(EventRecord(event.index, event.clazz));
//void EventRecord_in_EventRecordOver2(EventRecord *pEventRecord, uint16_t index, EventClass_uint8_t clazz);
  EventRecord eEventRecord;
  EventRecord_in_EventRecordOver2(&eEventRecord, event->eEvented.index, event->eEvented.clazz);
  Node_for_EventRecord* record_node = Add_in_List_for_EventRecord(&(lists->events), &eEventRecord);

  // followed by the typed record
////    const auto typed_node = list.Add(TypedEventRecord<T>(event.value, event.variation, record_node));
  TypedEventRecord_for_DoubleBitBinarySpec tTypedEventRecord_for_DoubleBitBinarySpec;
  TypedEventRecord_for_DoubleBitBinarySpec_in_TypedEventRecord_for_DoubleBitBinarySpec(&tTypedEventRecord_for_DoubleBitBinarySpec,
      &(event->value),
      event->variation,
      record_node);
  Node_TypedEventRecord_for_DoubleBitBinarySpec* typed_node = Add_in_List_TypedEventRecord_for_DoubleBitBinarySpec(listEv,
      &tTypedEventRecord_for_DoubleBitBinarySpec);

  // configure the typed storage
//IEventType* Instance_in_EventTypeImpl_TypedEventRecord_for_DoubleBitBinarySpec_static(void);
////    record_node->value.type = EventTypeImpl<T>::Instance();
  (record_node->value).type = Instance_in_EventTypeImpl_TypedEventRecord_for_DoubleBitBinarySpec_static();

  record_node->value.storage_node = typed_node;

//void OnAdd_in_EventClassCounters(EventClassCounters *pEventClassCounters, EventClass_uint8_t clazz);
////    lists.counters.OnAdd(event.clazz);
  OnAdd_in_EventClassCounters(&(lists->counters), event->eEvented.clazz);

  return overflow;
}

//----------------------------------DoubleBitBinarySpec-------------------------------------------
//----------------------------------AnalogSpec-------------------------------------------
boolean Update_AnalogSpec_in_EventUpdate_static(EventLists* lists, Event_for_AnalogSpec* event)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"Update_AnalogSpec_in_EventUpdate_static1"<<'\n';
#endif
////    auto& list = lists.GetList<T>();
  List_TypedEventRecord_for_AnalogSpec*  listEv = GetList_for_AnalogSpec_in_EventLists(lists);

  // lists with no capacity don't cause "buffer overflow"
// списки без емкости не вызывают «переполнение буфера»
//     uint32_t Capacity_in_List_TypedEventRecord_for_AnalogSpec(List_TypedEventRecord_for_AnalogSpec *pList_TypedEventRecord_for_AnalogSpec)
////    if (list.Capacity() == 0)
  if(Capacity_in_List_TypedEventRecord_for_AnalogSpec(listEv) == 0)
    return false;

  boolean overflow = false;

//boolean IsFullAndCapacityNotZero_in_List_TypedEventRecord_for_AnalogSpec(List_TypedEventRecord_for_AnalogSpec *pList_TypedEventRecord_for_AnalogSpec)
////    if (list.IsFullAndCapacityNotZero())
  if(IsFullAndCapacityNotZero_in_List_TypedEventRecord_for_AnalogSpec(listEv))
  {
    // we must make space
// мы должны освободить место
    overflow = true;
////        const auto first = list.Head();
    Node_TypedEventRecord_for_AnalogSpec* first = Head_in_List_TypedEventRecord_for_AnalogSpec(listEv);
////        const auto record_node = first->value.record;
    Node_for_EventRecord* record_node = (first->value).record;

    // remove the generic record
// удаляем общую запись
//void OnRemove_in_EventClassCounters(EventClassCounters *pEventClassCounters, EventClass_uint8_t clazz, EventState_uint8_t state);
////        lists.counters.OnRemove(record_node->value.clazz, record_node->value.state);
    OnRemove_in_EventClassCounters(&(lists->counters), record_node->value.clazz, record_node->value.state);
//   void Remove_in_List_for_EventRecord(List_for_EventRecord *pList_for_EventRecord, Node_for_EventRecord* node);
////        lists.events.Remove(first->value.record);
    Remove_in_List_for_EventRecord(&(lists->events), first->value.record);

    // remove the type specific record
// удаляем запись определенного типа
//void Remove_in_List_TypedEventRecord_for_AnalogSpec(List_TypedEventRecord_for_AnalogSpec *pList_TypedEventRecord_for_AnalogSpec, Node_TypedEventRecord_for_AnalogSpec* node);
////        list.Remove(first);
    Remove_in_List_TypedEventRecord_for_AnalogSpec(listEv, first);
  }

  // now that we know that space exists, create the generic record
// теперь, когда мы знаем, что пространство существует, создаем общую запись
//Node_for_EventRecord* Add_in_List_for_EventRecord(List_for_EventRecord *pList_for_EventRecord, EventRecord* value);
////    const auto record_node = lists.events.Add(EventRecord(event.index, event.clazz));
//void EventRecord_in_EventRecordOver2(EventRecord *pEventRecord, uint16_t index, EventClass_uint8_t clazz);
  EventRecord eEventRecord;
  EventRecord_in_EventRecordOver2(&eEventRecord, event->eEvented.index, event->eEvented.clazz);
  Node_for_EventRecord* record_node = Add_in_List_for_EventRecord(&(lists->events), &eEventRecord);

  // followed by the typed record
////    const auto typed_node = list.Add(TypedEventRecord<T>(event.value, event.variation, record_node));
  TypedEventRecord_for_AnalogSpec tTypedEventRecord_for_AnalogSpec;
  TypedEventRecord_for_AnalogSpec_in_TypedEventRecord_for_AnalogSpec(&tTypedEventRecord_for_AnalogSpec,
      &(event->value),
      event->variation,
      record_node);
  Node_TypedEventRecord_for_AnalogSpec* typed_node = Add_in_List_TypedEventRecord_for_AnalogSpec(listEv,
      &tTypedEventRecord_for_AnalogSpec);

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"Update_AnalogSpec_in_EventUpdate_static2"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*(typed_node->value).selectedVariation= "<<(uint16_t)(typed_node->value).selectedVariation<<'\n';
#endif

  // configure the typed storage
//IEventType* Instance_in_EventTypeImpl_TypedEventRecord_for_AnalogSpec_static(void);
////    record_node->value.type = EventTypeImpl<T>::Instance();
  (record_node->value).type = Instance_in_EventTypeImpl_TypedEventRecord_for_AnalogSpec_static();

  record_node->value.storage_node = typed_node;

//void OnAdd_in_EventClassCounters(EventClassCounters *pEventClassCounters, EventClass_uint8_t clazz);
////    lists.counters.OnAdd(event.clazz);
  OnAdd_in_EventClassCounters(&(lists->counters), event->eEvented.clazz);

  return overflow;
}
//----------------------------------AnalogSpec-------------------------------------------
//----------------------------------CounterSpec-------------------------------------------

boolean Update_CounterSpec_in_EventUpdate_static(EventLists* lists, Event_for_CounterSpec* event)
{
////    auto& list = lists.GetList<T>();
  List_TypedEventRecord_for_CounterSpec*  listEv = GetList_for_CounterSpec_in_EventLists(lists);

  // lists with no capacity don't cause "buffer overflow"
//     uint32_t Capacity_in_List_TypedEventRecord_for_CounterSpec(List_TypedEventRecord_for_CounterSpec *pList_TypedEventRecord_for_CounterSpec)
////    if (list.Capacity() == 0)
  if(Capacity_in_List_TypedEventRecord_for_CounterSpec(listEv) == 0)
    return false;

  boolean overflow = false;

//boolean IsFullAndCapacityNotZero_in_List_TypedEventRecord_for_CounterSpec(List_TypedEventRecord_for_CounterSpec *pList_TypedEventRecord_for_CounterSpec)
////    if (list.IsFullAndCapacityNotZero())
  if(IsFullAndCapacityNotZero_in_List_TypedEventRecord_for_CounterSpec(listEv))
  {
    // we must make space

    overflow = true;
////        const auto first = list.Head();
    Node_TypedEventRecord_for_CounterSpec* first = Head_in_List_TypedEventRecord_for_CounterSpec(listEv);
////        const auto record_node = first->value.record;
    Node_for_EventRecord* record_node = (first->value).record;

    // remove the generic record
//void OnRemove_in_EventClassCounters(EventClassCounters *pEventClassCounters, EventClass_uint8_t clazz, EventState_uint8_t state);
////        lists.counters.OnRemove(record_node->value.clazz, record_node->value.state);
    OnRemove_in_EventClassCounters(&(lists->counters), record_node->value.clazz, record_node->value.state);
//   void Remove_in_List_for_EventRecord(List_for_EventRecord *pList_for_EventRecord, Node_for_EventRecord* node);
////        lists.events.Remove(first->value.record);
    Remove_in_List_for_EventRecord(&(lists->events), first->value.record);

    // remove the type specific record
//void Remove_in_List_TypedEventRecord_for_CounterSpec(List_TypedEventRecord_for_CounterSpec *pList_TypedEventRecord_for_CounterSpec, Node_TypedEventRecord_for_CounterSpec* node);
////        list.Remove(first);
    Remove_in_List_TypedEventRecord_for_CounterSpec(listEv, first);
  }

  // now that we know that space exists, create the generic record
//Node_for_EventRecord* Add_in_List_for_EventRecord(List_for_EventRecord *pList_for_EventRecord, EventRecord* value);
////    const auto record_node = lists.events.Add(EventRecord(event.index, event.clazz));
//void EventRecord_in_EventRecordOver2(EventRecord *pEventRecord, uint16_t index, EventClass_uint8_t clazz);
  EventRecord eEventRecord;
  EventRecord_in_EventRecordOver2(&eEventRecord, event->eEvented.index, event->eEvented.clazz);
  Node_for_EventRecord* record_node = Add_in_List_for_EventRecord(&(lists->events), &eEventRecord);

  // followed by the typed record
////    const auto typed_node = list.Add(TypedEventRecord<T>(event.value, event.variation, record_node));
  TypedEventRecord_for_CounterSpec tTypedEventRecord_for_CounterSpec;
  TypedEventRecord_for_CounterSpec_in_TypedEventRecord_for_CounterSpec(&tTypedEventRecord_for_CounterSpec,
      &(event->value),
      event->variation,
      record_node);
  Node_TypedEventRecord_for_CounterSpec* typed_node = Add_in_List_TypedEventRecord_for_CounterSpec(listEv,
      &tTypedEventRecord_for_CounterSpec);

  // configure the typed storage
//IEventType* Instance_in_EventTypeImpl_TypedEventRecord_for_CounterSpec_static(void);
////    record_node->value.type = EventTypeImpl<T>::Instance();
  (record_node->value).type = Instance_in_EventTypeImpl_TypedEventRecord_for_CounterSpec_static();

  record_node->value.storage_node = typed_node;

//void OnAdd_in_EventClassCounters(EventClassCounters *pEventClassCounters, EventClass_uint8_t clazz);
////    lists.counters.OnAdd(event.clazz);
  OnAdd_in_EventClassCounters(&(lists->counters), event->eEvented.clazz);

  return overflow;
}

//----------------------------------CounterSpec-------------------------------------------
//----------------------------------FrozenCounterSpec-------------------------------------------

boolean Update_FrozenCounterSpec_in_EventUpdate_static(EventLists* lists, Event_for_FrozenCounterSpec* event)
{
////    auto& list = lists.GetList<T>();
  List_TypedEventRecord_for_FrozenCounterSpec*  listEv = GetList_for_FrozenCounterSpec_in_EventLists(lists);

  // lists with no capacity don't cause "buffer overflow"
//     uint32_t Capacity_in_List_TypedEventRecord_for_FrozenCounterSpec(List_TypedEventRecord_for_FrozenCounterSpec *pList_TypedEventRecord_for_FrozenCounterSpec)
////    if (list.Capacity() == 0)
  if(Capacity_in_List_TypedEventRecord_for_FrozenCounterSpec(listEv) == 0)
    return false;

  boolean overflow = false;

//boolean IsFullAndCapacityNotZero_in_List_TypedEventRecord_for_FrozenCounterSpec(List_TypedEventRecord_for_FrozenCounterSpec *pList_TypedEventRecord_for_FrozenCounterSpec)
////    if (list.IsFullAndCapacityNotZero())
  if(IsFullAndCapacityNotZero_in_List_TypedEventRecord_for_FrozenCounterSpec(listEv))
  {
    // we must make space

    overflow = true;
////        const auto first = list.Head();
    Node_TypedEventRecord_for_FrozenCounterSpec* first = Head_in_List_TypedEventRecord_for_FrozenCounterSpec(listEv);
////        const auto record_node = first->value.record;
    Node_for_EventRecord* record_node = (first->value).record;

    // remove the generic record
//void OnRemove_in_EventClassCounters(EventClassCounters *pEventClassCounters, EventClass_uint8_t clazz, EventState_uint8_t state);
////        lists.counters.OnRemove(record_node->value.clazz, record_node->value.state);
    OnRemove_in_EventClassCounters(&(lists->counters), record_node->value.clazz, record_node->value.state);
//   void Remove_in_List_for_EventRecord(List_for_EventRecord *pList_for_EventRecord, Node_for_EventRecord* node);
////        lists.events.Remove(first->value.record);
    Remove_in_List_for_EventRecord(&(lists->events), first->value.record);

    // remove the type specific record
//void Remove_in_List_TypedEventRecord_for_FrozenCounterSpec(List_TypedEventRecord_for_FrozenCounterSpec *pList_TypedEventRecord_for_FrozenCounterSpec, Node_TypedEventRecord_for_FrozenCounterSpec* node);
////        list.Remove(first);
    Remove_in_List_TypedEventRecord_for_FrozenCounterSpec(listEv, first);
  }

  // now that we know that space exists, create the generic record
//Node_for_EventRecord* Add_in_List_for_EventRecord(List_for_EventRecord *pList_for_EventRecord, EventRecord* value);
////    const auto record_node = lists.events.Add(EventRecord(event.index, event.clazz));
//void EventRecord_in_EventRecordOver2(EventRecord *pEventRecord, uint16_t index, EventClass_uint8_t clazz);
  EventRecord eEventRecord;
  EventRecord_in_EventRecordOver2(&eEventRecord, event->eEvented.index, event->eEvented.clazz);
  Node_for_EventRecord* record_node = Add_in_List_for_EventRecord(&(lists->events), &eEventRecord);

  // followed by the typed record
////    const auto typed_node = list.Add(TypedEventRecord<T>(event.value, event.variation, record_node));
  TypedEventRecord_for_FrozenCounterSpec tTypedEventRecord_for_FrozenCounterSpec;
  TypedEventRecord_for_FrozenCounterSpec_in_TypedEventRecord_for_FrozenCounterSpec(&tTypedEventRecord_for_FrozenCounterSpec,
      &(event->value),
      event->variation,
      record_node);
  Node_TypedEventRecord_for_FrozenCounterSpec* typed_node = Add_in_List_TypedEventRecord_for_FrozenCounterSpec(listEv,
      &tTypedEventRecord_for_FrozenCounterSpec);

  // configure the typed storage
//IEventType* Instance_in_EventTypeImpl_TypedEventRecord_for_FrozenCounterSpec_static(void);
////    record_node->value.type = EventTypeImpl<T>::Instance();
  (record_node->value).type = Instance_in_EventTypeImpl_TypedEventRecord_for_FrozenCounterSpec_static();

  record_node->value.storage_node = typed_node;

//void OnAdd_in_EventClassCounters(EventClassCounters *pEventClassCounters, EventClass_uint8_t clazz);
////    lists.counters.OnAdd(event.clazz);
  OnAdd_in_EventClassCounters(&(lists->counters), event->eEvented.clazz);

  return overflow;
}

//----------------------------------FrozenCounterSpec-------------------------------------------
//----------------------------------BinaryOutputStatusSpec-------------------------------------------

boolean Update_BinaryOutputStatusSpec_in_EventUpdate_static(EventLists* lists, Event_for_BinaryOutputStatusSpec* event)
{
////    auto& list = lists.GetList<T>();
  List_TypedEventRecord_for_BinaryOutputStatusSpec*  listEv = GetList_for_BinaryOutputStatusSpec_in_EventLists(lists);

  // lists with no capacity don't cause "buffer overflow"
//     uint32_t Capacity_in_List_TypedEventRecord_for_BinaryOutputStatusSpec(List_TypedEventRecord_for_BinaryOutputStatusSpec *pList_TypedEventRecord_for_BinaryOutputStatusSpec)
////    if (list.Capacity() == 0)
  if(Capacity_in_List_TypedEventRecord_for_BinaryOutputStatusSpec(listEv) == 0)
    return false;

  boolean overflow = false;

//boolean IsFullAndCapacityNotZero_in_List_TypedEventRecord_for_BinaryOutputStatusSpec(List_TypedEventRecord_for_BinaryOutputStatusSpec *pList_TypedEventRecord_for_BinaryOutputStatusSpec)
////    if (list.IsFullAndCapacityNotZero())
  if(IsFullAndCapacityNotZero_in_List_TypedEventRecord_for_BinaryOutputStatusSpec(listEv))
  {
    // we must make space

    overflow = true;
////        const auto first = list.Head();
    Node_TypedEventRecord_for_BinaryOutputStatusSpec* first = Head_in_List_TypedEventRecord_for_BinaryOutputStatusSpec(listEv);
////        const auto record_node = first->value.record;
    Node_for_EventRecord* record_node = (first->value).record;

    // remove the generic record
//void OnRemove_in_EventClassCounters(EventClassCounters *pEventClassCounters, EventClass_uint8_t clazz, EventState_uint8_t state);
////        lists.counters.OnRemove(record_node->value.clazz, record_node->value.state);
    OnRemove_in_EventClassCounters(&(lists->counters), record_node->value.clazz, record_node->value.state);
//   void Remove_in_List_for_EventRecord(List_for_EventRecord *pList_for_EventRecord, Node_for_EventRecord* node);
////        lists.events.Remove(first->value.record);
    Remove_in_List_for_EventRecord(&(lists->events), first->value.record);

    // remove the type specific record
//void Remove_in_List_TypedEventRecord_for_BinaryOutputStatusSpec(List_TypedEventRecord_for_BinaryOutputStatusSpec *pList_TypedEventRecord_for_BinaryOutputStatusSpec, Node_TypedEventRecord_for_BinaryOutputStatusSpec* node);
////        list.Remove(first);
    Remove_in_List_TypedEventRecord_for_BinaryOutputStatusSpec(listEv, first);
  }

  // now that we know that space exists, create the generic record
//Node_for_EventRecord* Add_in_List_for_EventRecord(List_for_EventRecord *pList_for_EventRecord, EventRecord* value);
////    const auto record_node = lists.events.Add(EventRecord(event.index, event.clazz));
//void EventRecord_in_EventRecordOver2(EventRecord *pEventRecord, uint16_t index, EventClass_uint8_t clazz);
  EventRecord eEventRecord;
  EventRecord_in_EventRecordOver2(&eEventRecord, event->eEvented.index, event->eEvented.clazz);
  Node_for_EventRecord* record_node = Add_in_List_for_EventRecord(&(lists->events), &eEventRecord);

  // followed by the typed record
////    const auto typed_node = list.Add(TypedEventRecord<T>(event.value, event.variation, record_node));
  TypedEventRecord_for_BinaryOutputStatusSpec tTypedEventRecord_for_BinaryOutputStatusSpec;
  TypedEventRecord_for_BinaryOutputStatusSpec_in_TypedEventRecord_for_BinaryOutputStatusSpec(&tTypedEventRecord_for_BinaryOutputStatusSpec,
      &(event->value),
      event->variation,
      record_node);
  Node_TypedEventRecord_for_BinaryOutputStatusSpec* typed_node = Add_in_List_TypedEventRecord_for_BinaryOutputStatusSpec(listEv,
      &tTypedEventRecord_for_BinaryOutputStatusSpec);

  // configure the typed storage
//IEventType* Instance_in_EventTypeImpl_TypedEventRecord_for_BinaryOutputStatusSpec_static(void);
////    record_node->value.type = EventTypeImpl<T>::Instance();
  (record_node->value).type = Instance_in_EventTypeImpl_TypedEventRecord_for_BinaryOutputStatusSpec_static();

  record_node->value.storage_node = typed_node;

//void OnAdd_in_EventClassCounters(EventClassCounters *pEventClassCounters, EventClass_uint8_t clazz);
////    lists.counters.OnAdd(event.clazz);
  OnAdd_in_EventClassCounters(&(lists->counters), event->eEvented.clazz);

  return overflow;
}

//----------------------------------BinaryOutputStatusSpec-------------------------------------------
//----------------------------------AnalogOutputStatusSpec-------------------------------------------

boolean Update_AnalogOutputStatusSpec_in_EventUpdate_static(EventLists* lists, Event_for_AnalogOutputStatusSpec* event)
{
////    auto& list = lists.GetList<T>();
  List_TypedEventRecord_for_AnalogOutputStatusSpec*  listEv = GetList_for_AnalogOutputStatusSpec_in_EventLists(lists);

  // lists with no capacity don't cause "buffer overflow"
//     uint32_t Capacity_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(List_TypedEventRecord_for_AnalogOutputStatusSpec *pList_TypedEventRecord_for_AnalogOutputStatusSpec)
////    if (list.Capacity() == 0)
  if(Capacity_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(listEv) == 0)
    return false;

  boolean overflow = false;

//boolean IsFullAndCapacityNotZero_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(List_TypedEventRecord_for_AnalogOutputStatusSpec *pList_TypedEventRecord_for_AnalogOutputStatusSpec)
////    if (list.IsFullAndCapacityNotZero())
  if(IsFullAndCapacityNotZero_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(listEv))
  {
    // we must make space

    overflow = true;
////        const auto first = list.Head();
    Node_TypedEventRecord_for_AnalogOutputStatusSpec* first = Head_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(listEv);
////        const auto record_node = first->value.record;
    Node_for_EventRecord* record_node = (first->value).record;

    // remove the generic record
//void OnRemove_in_EventClassCounters(EventClassCounters *pEventClassCounters, EventClass_uint8_t clazz, EventState_uint8_t state);
////        lists.counters.OnRemove(record_node->value.clazz, record_node->value.state);
    OnRemove_in_EventClassCounters(&(lists->counters), record_node->value.clazz, record_node->value.state);
//   void Remove_in_List_for_EventRecord(List_for_EventRecord *pList_for_EventRecord, Node_for_EventRecord* node);
////        lists.events.Remove(first->value.record);
    Remove_in_List_for_EventRecord(&(lists->events), first->value.record);

    // remove the type specific record
//void Remove_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(List_TypedEventRecord_for_AnalogOutputStatusSpec *pList_TypedEventRecord_for_AnalogOutputStatusSpec, Node_TypedEventRecord_for_AnalogOutputStatusSpec* node);
////        list.Remove(first);
    Remove_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(listEv, first);
  }

  // now that we know that space exists, create the generic record
//Node_for_EventRecord* Add_in_List_for_EventRecord(List_for_EventRecord *pList_for_EventRecord, EventRecord* value);
////    const auto record_node = lists.events.Add(EventRecord(event.index, event.clazz));
//void EventRecord_in_EventRecordOver2(EventRecord *pEventRecord, uint16_t index, EventClass_uint8_t clazz);
  EventRecord eEventRecord;
  EventRecord_in_EventRecordOver2(&eEventRecord, event->eEvented.index, event->eEvented.clazz);
  Node_for_EventRecord* record_node = Add_in_List_for_EventRecord(&(lists->events), &eEventRecord);

  // followed by the typed record
////    const auto typed_node = list.Add(TypedEventRecord<T>(event.value, event.variation, record_node));
  TypedEventRecord_for_AnalogOutputStatusSpec tTypedEventRecord_for_AnalogOutputStatusSpec;
  TypedEventRecord_for_AnalogOutputStatusSpec_in_TypedEventRecord_for_AnalogOutputStatusSpec(&tTypedEventRecord_for_AnalogOutputStatusSpec,
      &(event->value),
      event->variation,
      record_node);
  Node_TypedEventRecord_for_AnalogOutputStatusSpec* typed_node = Add_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(listEv,
      &tTypedEventRecord_for_AnalogOutputStatusSpec);

  // configure the typed storage
//IEventType* Instance_in_EventTypeImpl_TypedEventRecord_for_AnalogOutputStatusSpec_static(void);
////    record_node->value.type = EventTypeImpl<T>::Instance();
  (record_node->value).type = Instance_in_EventTypeImpl_TypedEventRecord_for_AnalogOutputStatusSpec_static();

  record_node->value.storage_node = typed_node;

//void OnAdd_in_EventClassCounters(EventClassCounters *pEventClassCounters, EventClass_uint8_t clazz);
////    lists.counters.OnAdd(event.clazz);
  OnAdd_in_EventClassCounters(&(lists->counters), event->eEvented.clazz);

  return overflow;
}

//----------------------------------AnalogOutputStatusSpec-------------------------------------------
//----------------------------------OctetStringSpec-------------------------------------------

boolean Update_OctetStringSpec_in_EventUpdate_static(EventLists* lists, Event_for_OctetStringSpec* event)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"Update_OctetStringSpec_in_EventUpdate_static1"<<'\n';
#endif
////    auto& list = lists.GetList<T>();
  List_TypedEventRecord_for_OctetStringSpec*  listEv = GetList_for_OctetStringSpec_in_EventLists(lists);

  // lists with no capacity don't cause "buffer overflow"
// списки без емкости не вызывают «переполнение буфера»
//     uint32_t Capacity_in_List_TypedEventRecord_for_OctetStringSpec(List_TypedEventRecord_for_OctetStringSpec *pList_TypedEventRecord_for_OctetStringSpec)
////    if (list.Capacity() == 0)
  if(Capacity_in_List_TypedEventRecord_for_OctetStringSpec(listEv) == 0)
{
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
  return false;
}

  boolean overflow = false;

//boolean IsFullAndCapacityNotZero_in_List_TypedEventRecord_for_OctetStringSpec(List_TypedEventRecord_for_OctetStringSpec *pList_TypedEventRecord_for_OctetStringSpec)
////    if (list.IsFullAndCapacityNotZero())
  if(IsFullAndCapacityNotZero_in_List_TypedEventRecord_for_OctetStringSpec(listEv))
  {
    // we must make space
// мы должны освободить место
    overflow = true;
////        const auto first = list.Head();
    Node_TypedEventRecord_for_OctetStringSpec* first = Head_in_List_TypedEventRecord_for_OctetStringSpec(listEv);
////        const auto record_node = first->value.record;
    Node_for_EventRecord* record_node = (first->value).record;

    // remove the generic record
//void OnRemove_in_EventClassCounters(EventClassCounters *pEventClassCounters, EventClass_uint8_t clazz, EventState_uint8_t state);
////        lists.counters.OnRemove(record_node->value.clazz, record_node->value.state);
    OnRemove_in_EventClassCounters(&(lists->counters), record_node->value.clazz, record_node->value.state);
//   void Remove_in_List_for_EventRecord(List_for_EventRecord *pList_for_EventRecord, Node_for_EventRecord* node);
////        lists.events.Remove(first->value.record);
    Remove_in_List_for_EventRecord(&(lists->events), first->value.record);

    // remove the type specific record
//void Remove_in_List_TypedEventRecord_for_OctetStringSpec(List_TypedEventRecord_for_OctetStringSpec *pList_TypedEventRecord_for_OctetStringSpec, Node_TypedEventRecord_for_OctetStringSpec* node);
////        list.Remove(first);
    Remove_in_List_TypedEventRecord_for_OctetStringSpec(listEv, first);
  }

  // now that we know that space exists, create the generic record
// теперь, когда мы знаем, что пространство существует, создаем общую запись
//Node_for_EventRecord* Add_in_List_for_EventRecord(List_for_EventRecord *pList_for_EventRecord, EventRecord* value);
////    const auto record_node = lists.events.Add(EventRecord(event.index, event.clazz));
//void EventRecord_in_EventRecordOver2(EventRecord *pEventRecord, uint16_t index, EventClass_uint8_t clazz);
  EventRecord eEventRecord;
  EventRecord_in_EventRecordOver2(&eEventRecord, event->eEvented.index, event->eEvented.clazz);
  Node_for_EventRecord* record_node = Add_in_List_for_EventRecord(&(lists->events), &eEventRecord);

  // followed by the typed record
////    const auto typed_node = list.Add(TypedEventRecord<T>(event.value, event.variation, record_node));
  TypedEventRecord_for_OctetStringSpec tTypedEventRecord_for_OctetStringSpec;
  TypedEventRecord_for_OctetStringSpec_in_TypedEventRecord_for_OctetStringSpec(&tTypedEventRecord_for_OctetStringSpec,
      &(event->value),
      event->variation,
      record_node);
  Node_TypedEventRecord_for_OctetStringSpec* typed_node = Add_in_List_TypedEventRecord_for_OctetStringSpec(listEv,
      &tTypedEventRecord_for_OctetStringSpec);

  // configure the typed storage
// настраиваем типизированное хранилище
//IEventType* Instance_in_EventTypeImpl_TypedEventRecord_for_OctetStringSpec_static(void);
////    record_node->value.type = EventTypeImpl<T>::Instance();
  (record_node->value).type = Instance_in_EventTypeImpl_TypedEventRecord_for_OctetStringSpec_static();

  record_node->value.storage_node = typed_node;

//void OnAdd_in_EventClassCounters(EventClassCounters *pEventClassCounters, EventClass_uint8_t clazz);
////    lists.counters.OnAdd(event.clazz);
  OnAdd_in_EventClassCounters(&(lists->counters), event->eEvented.clazz);

#ifdef  LOG_INFO
  decrement_stack_info();
#endif
  return overflow;
}

//----------------------------------OctetStringSpec-------------------------------------------
