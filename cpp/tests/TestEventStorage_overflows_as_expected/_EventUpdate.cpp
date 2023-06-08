#include "header.h"
#include "EventUpdate.h"

boolean __Update_for_AnalogSpec_in_EventUpdate_static(EventLists* lists, Event_for_AnalogSpec* event);
Node_TypedEventRecord_for_AnalogSpec* __Add_in_List_TypedEventRecord_for_AnalogSpec(List_TypedEventRecord_for_AnalogSpec *pList_TypedEventRecord_for_AnalogSpec,
    TypedEventRecord_for_AnalogSpec* value);

boolean __Update_for_AnalogSpec_in_EventUpdate_static(EventLists* lists, Event_for_AnalogSpec* event)
{
////    auto& list = lists.GetList<T>();
  List_TypedEventRecord_for_AnalogSpec*  listEv = GetList_for_AnalogSpec_in_EventLists(lists);

  // lists with no capacity don't cause "buffer overflow"
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

    overflow = true;
////        const auto first = list.Head();
    Node_TypedEventRecord_for_AnalogSpec* first = Head_in_List_TypedEventRecord_for_AnalogSpec(listEv);
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
//void Remove_in_List_TypedEventRecord_for_AnalogSpec(List_TypedEventRecord_for_AnalogSpec *pList_TypedEventRecord_for_AnalogSpec, Node_TypedEventRecord_for_AnalogSpec* node);
////        list.Remove(first);
    Remove_in_List_TypedEventRecord_for_AnalogSpec(listEv, first);
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
  TypedEventRecord_for_AnalogSpec tTypedEventRecord_for_AnalogSpec;
  TypedEventRecord_for_AnalogSpec_in_TypedEventRecord_for_AnalogSpec(&tTypedEventRecord_for_AnalogSpec,
      &(event->value),
      event->variation,
      record_node);

  Node_TypedEventRecord_for_AnalogSpec* typed_node = __Add_in_List_TypedEventRecord_for_AnalogSpec(listEv,
      &tTypedEventRecord_for_AnalogSpec);

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
