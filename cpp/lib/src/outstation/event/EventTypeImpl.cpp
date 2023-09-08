#include <iostream>
#include "header.h"
#include "EventTypeImpl.h"

EventTypeImpl_TypedEventRecord_for_OctetStringSpec instance_in_EventTypeImpl_TypedEventRecord_for_OctetStringSpec;
EventTypeImpl_TypedEventRecord_for_AnalogOutputStatusSpec instance_in_EventTypeImpl_TypedEventRecord_for_AnalogOutputStatusSpec;
EventTypeImpl_TypedEventRecord_for_BinaryOutputStatusSpec instance_in_EventTypeImpl_TypedEventRecord_for_BinaryOutputStatusSpec;
EventTypeImpl_TypedEventRecord_for_FrozenCounterSpec instance_in_EventTypeImpl_TypedEventRecord_for_FrozenCounterSpec;
EventTypeImpl_TypedEventRecord_for_CounterSpec instance_in_EventTypeImpl_TypedEventRecord_for_CounterSpec;
EventTypeImpl_TypedEventRecord_for_AnalogSpec instance_in_EventTypeImpl_TypedEventRecord_for_AnalogSpec;
EventTypeImpl_TypedEventRecord_for_DoubleBitBinarySpec instance_in_EventTypeImpl_TypedEventRecord_for_DoubleBitBinarySpec;
EventTypeImpl_TypedEventRecord_for_BinarySpec instance_in_EventTypeImpl_TypedEventRecord_for_BinarySpec;

//----------------------------------Binary-------------------------------------------
IEventType* Instance_in_EventTypeImpl_TypedEventRecord_for_BinarySpec_static(void)
{
  std::cout<<"Instance_in_EventTypeImpl_TypedEventRecord_for_BinarySpec_static1"<<'\n';
  instance_in_EventTypeImpl_TypedEventRecord_for_BinarySpec.iIEventType.pSelectDefaultVariation_in_IEventType =
    SelectDefaultVariation_in_EventTypeImpl_TypedEventRecord_for_BinarySpec_override;
  instance_in_EventTypeImpl_TypedEventRecord_for_BinarySpec.iIEventType.pWriteSome_in_IEventType =
    WriteSome_in_EventTypeImpl_TypedEventRecord_for_BinarySpec_override;
  instance_in_EventTypeImpl_TypedEventRecord_for_BinarySpec.iIEventType.pRemoveTypeFromStorage_in_IEventType =
    RemoveTypeFromStorage_in_EventTypeImpl_TypedEventRecord_for_BinarySpec_override;
  return &(instance_in_EventTypeImpl_TypedEventRecord_for_BinarySpec.iIEventType);
}

void SelectDefaultVariation_in_EventTypeImpl_TypedEventRecord_for_BinarySpec_override(void *pIEventType, EventRecord* record)
{
  UNUSED(pIEventType);
//    Node_TypedEventRecord_for_BinarySpec* Retrieve_in_TypedStorage_for_BinarySpec_static(EventRecord* record);
////        auto node = TypedStorage<T>::Retrieve(record);
  Node_TypedEventRecord_for_BinarySpec* node = Retrieve_in_TypedStorage_for_BinarySpec_static(record);
  node->value.selectedVariation = node->value.defaultVariation;
}

////    virtual uint16_t WriteSome_in_EventTypeImpl_TypedEventRecord_for_BinarySpec(List<EventRecord>::Iterator& iterator,
////                               EventLists& lists,
////                               IEventWriteHandler& handler) const override
uint16_t WriteSome_in_EventTypeImpl_TypedEventRecord_for_BinarySpec_override(void *pIEventType,
    Iterator_in_List_for_EventRecord* iteratorEv,
    EventLists* lists,
    IEventWriteHandler* handler)
{
  std::cout<<""<<'\n';
  std::cout<<"WriteSome_in_EventTypeImpl_TypedEventRecord_for_BinarySpec_override1"<<'\n';

  UNUSED(pIEventType);
//EventRecord* CurrentValue__in__Iterator_in_List_for_EventRecord(Iterator_in_List_for_EventRecord *pIterator_in_List_for_EventRecord);
////        const auto pos = iterator.CurrentValue();
  EventRecord* pos = CurrentValue__in__Iterator_in_List_for_EventRecord(iteratorEv);
//    Node_TypedEventRecord_for_BinarySpec* Retrieve_in_TypedStorage_for_BinarySpec_static(EventRecord* record);
////        const auto type = TypedStorage<T>::Retrieve(*pos);
  Node_TypedEventRecord_for_BinarySpec* type = Retrieve_in_TypedStorage_for_BinarySpec_static(pos);
//
//void  EventCollection_for_Binary_in_EventCollection_for_Binary(EventCollection_for_Binary *pEventCollection_for_Binary,
//    Iterator_in_List_for_EventRecord* iteratorEv,
//    EventClassCounters* counters,
//    event_variation_t_in_BinaryInfo variation);
////        EventCollection<T> collection(iterator, lists.counters, type->value.selectedVariation);
  EventCollection_for_Binary collection;

  EventCollection_for_Binary_in_EventCollection_for_Binary(&collection,
      iteratorEv,
      &(lists->counters),
      (type->value).selectedVariation);

//uint16_t Write_for_Binary_in_IEventWriteHandler(IEventWriteHandler *, EventBinaryVariation_uint8_t variation, Binary* first, IEventCollection_for_Binary* items);//// = 0;
////        return handler.Write(type->value.selectedVariation, type->value.value, collection);
//  return handler->pWrite_EventBinary_in_IEventWriteHandler((type->value).selectedVariation,
//uint16_t Write_for_Binary_in_IEventWriteHandler(IEventWriteHandler *pIEventWriteHandler, EventBinaryVariation_uint8_t variation, Binary* first, IEventCollection_for_Binary* items)
  return Write_for_Binary_in_IEventWriteHandler(handler,
         (type->value).selectedVariation,
         &((type->value).value),
         &(collection.iIEventCollection_for_Binary));
}

////    virtual void RemoveTypeFromStorage(EventRecord& record, EventLists& lists) const override
void   RemoveTypeFromStorage_in_EventTypeImpl_TypedEventRecord_for_BinarySpec_override(void *pIEventType, EventRecord* record, EventLists* lists)
{
  UNUSED(pIEventType);
//    Node_TypedEventRecord_for_BinarySpec* Retrieve_in_TypedStorage_for_BinarySpec_static(EventRecord* record);
////        auto node = TypedStorage<T>::Retrieve(record);
  Node_TypedEventRecord_for_BinarySpec* node = Retrieve_in_TypedStorage_for_BinarySpec_static(record);
//  List_TypedEventRecord_for_BinarySpec*             GetList_for_BinarySpec_in_EventLists(EventLists *pEventLists);
////        lists.GetList<T>().Remove(node);
  List_TypedEventRecord_for_BinarySpec* temp = GetList_for_BinarySpec_in_EventLists(lists);
//void Remove_in_List_TypedEventRecord_for_BinarySpec(List_TypedEventRecord_for_BinarySpec *pList_TypedEventRecord_for_BinarySpec, Node_TypedEventRecord_for_BinarySpec* node);
  Remove_in_List_TypedEventRecord_for_BinarySpec(temp, node);
}
//----------------------------------Binary-------------------------------------------
//----------------------------------DoubleBitBinary-------------------------------------------

IEventType* Instance_in_EventTypeImpl_TypedEventRecord_for_DoubleBitBinarySpec_static(void)
{
  instance_in_EventTypeImpl_TypedEventRecord_for_DoubleBitBinarySpec.iIEventType.pSelectDefaultVariation_in_IEventType =
    SelectDefaultVariation_in_EventTypeImpl_TypedEventRecord_for_DoubleBitBinarySpec_override;
  instance_in_EventTypeImpl_TypedEventRecord_for_DoubleBitBinarySpec.iIEventType.pWriteSome_in_IEventType =
    WriteSome_in_EventTypeImpl_TypedEventRecord_for_DoubleBitBinarySpec_override;
  instance_in_EventTypeImpl_TypedEventRecord_for_DoubleBitBinarySpec.iIEventType.pRemoveTypeFromStorage_in_IEventType =
    RemoveTypeFromStorage_in_EventTypeImpl_TypedEventRecord_for_DoubleBitBinarySpec_override;
  return &(instance_in_EventTypeImpl_TypedEventRecord_for_DoubleBitBinarySpec.iIEventType);
}

void SelectDefaultVariation_in_EventTypeImpl_TypedEventRecord_for_DoubleBitBinarySpec_override(void *pIEventType, EventRecord* record)
{
  UNUSED(pIEventType);
//    Node_TypedEventRecord_for_DoubleBitBinarySpec* Retrieve_in_TypedStorage_for_DoubleBitBinarySpec_static(EventRecord* record);
////        auto node = TypedStorage<T>::Retrieve(record);
  Node_TypedEventRecord_for_DoubleBitBinarySpec* node = Retrieve_in_TypedStorage_for_DoubleBitBinarySpec_static(record);
  node->value.selectedVariation = node->value.defaultVariation;
}

////    virtual uint16_t WriteSome_in_EventTypeImpl_TypedEventRecord_for_DoubleBitBinarySpec(List<EventRecord>::Iterator& iterator,
////                               EventLists& lists,
////                               IEventWriteHandler& handler) const override
uint16_t WriteSome_in_EventTypeImpl_TypedEventRecord_for_DoubleBitBinarySpec_override(void *pIEventType, Iterator_in_List_for_EventRecord* iteratorEv,
    EventLists* lists,
    IEventWriteHandler* handler)
{
  UNUSED(pIEventType);
//EventRecord* CurrentValue__in__Iterator_in_List_for_EventRecord(Iterator_in_List_for_EventRecord *pIterator_in_List_for_EventRecord);
////        const auto pos = iterator.CurrentValue();
  EventRecord* pos = CurrentValue__in__Iterator_in_List_for_EventRecord(iteratorEv);
//    Node_TypedEventRecord_for_DoubleBitBinarySpec* Retrieve_in_TypedStorage_for_DoubleBitBinarySpec_static(EventRecord* record);
////        const auto type = TypedStorage<T>::Retrieve(*pos);
  Node_TypedEventRecord_for_DoubleBitBinarySpec* type = Retrieve_in_TypedStorage_for_DoubleBitBinarySpec_static(pos);
//
//void  EventCollection_for_DoubleBitBinary_in_EventCollection_for_DoubleBitBinary(EventCollection_for_DoubleBitBinary *pEventCollection_for_DoubleBitBinary,
//    Iterator_in_List_for_EventRecord* iteratorEv,
//    EventClassCounters* counters,
//    event_variation_t_in_DoubleBitBinaryInfo variation);
////        EventCollection<T> collection(iterator, lists.counters, type->value.selectedVariation);
  EventCollection_for_DoubleBitBinary collection;

  EventCollection_for_DoubleBitBinary_in_EventCollection_for_DoubleBitBinary(&collection,
      iteratorEv,
      &(lists->counters),
      (type->value).selectedVariation);

//     uint16_t (*pWrite_in_IEventWriteHandlerOver1)(EventDoubleBitBinaryVariation_uint8_t variation, DoubleBitBinary* first, IEventCollection_for_DoubleBitBinary* items);//// = 0;
//uint16_t Write_for_DoubleBinary_in_IEventWriteHandler(IEventWriteHandler *, EventDoubleBinaryVariation_uint8_t variation,
//    DoubleBitBinary* first,
//    IEventCollection_for_DoubleBitBinary* items);
////        return handler.Write(type->value.selectedVariation, type->value.value, collection);
  return Write_for_DoubleBitBinary_in_IEventWriteHandler(handler,//handler->pWrite_in_IEventWriteHandlerOver2((type->value).selectedVariation,
         (type->value).selectedVariation,
         &((type->value).value),
         &(collection.iIEventCollection_for_DoubleBitBinary));
}

////    virtual void RemoveTypeFromStorage(EventRecord& record, EventLists& lists) const override
void   RemoveTypeFromStorage_in_EventTypeImpl_TypedEventRecord_for_DoubleBitBinarySpec_override(void *pIEventType, EventRecord* record, EventLists* lists)
{
  UNUSED(pIEventType);
//    Node_TypedEventRecord_for_DoubleBitBinarySpec* Retrieve_in_TypedStorage_for_DoubleBitBinarySpec_static(EventRecord* record);
////        auto node = TypedStorage<T>::Retrieve(record);
  Node_TypedEventRecord_for_DoubleBitBinarySpec* node = Retrieve_in_TypedStorage_for_DoubleBitBinarySpec_static(record);
//  List_TypedEventRecord_for_DoubleBitBinarySpec*             GetList_for_DoubleBitBinarySpec_in_EventLists(EventLists *pEventLists);
////        lists.GetList<T>().Remove(node);
  List_TypedEventRecord_for_DoubleBitBinarySpec* temp = GetList_for_DoubleBitBinarySpec_in_EventLists(lists);
//void Remove_in_List_TypedEventRecord_for_DoubleBitBinarySpec(List_TypedEventRecord_for_DoubleBitBinarySpec *pList_TypedEventRecord_for_DoubleBitBinarySpec, Node_TypedEventRecord_for_DoubleBitBinarySpec* node);
  Remove_in_List_TypedEventRecord_for_DoubleBitBinarySpec(temp, node);
}
//----------------------------------DoubleBitBinary-------------------------------------------
//----------------------------------Analog-------------------------------------------

IEventType* Instance_in_EventTypeImpl_TypedEventRecord_for_AnalogSpec_static(void)
{
  std::cout<<"Instance_in_EventTypeImpl_TypedEventRecord_for_AnalogSpec_static1"<<'\n';
  instance_in_EventTypeImpl_TypedEventRecord_for_AnalogSpec.iIEventType.pSelectDefaultVariation_in_IEventType =
    SelectDefaultVariation_in_EventTypeImpl_TypedEventRecord_for_AnalogSpec_override;
  instance_in_EventTypeImpl_TypedEventRecord_for_AnalogSpec.iIEventType.pWriteSome_in_IEventType =
    WriteSome_in_EventTypeImpl_TypedEventRecord_for_AnalogSpec_override;
  instance_in_EventTypeImpl_TypedEventRecord_for_AnalogSpec.iIEventType.pRemoveTypeFromStorage_in_IEventType =
    RemoveTypeFromStorage_in_EventTypeImpl_TypedEventRecord_for_AnalogSpec_override;
  return &(instance_in_EventTypeImpl_TypedEventRecord_for_AnalogSpec.iIEventType);
}

void SelectDefaultVariation_in_EventTypeImpl_TypedEventRecord_for_AnalogSpec_override(void *pIEventType, EventRecord* record)
{
  UNUSED(pIEventType);
//    Node_TypedEventRecord_for_AnalogSpec* Retrieve_in_TypedStorage_for_AnalogSpec_static(EventRecord* record);
////        auto node = TypedStorage<T>::Retrieve(record);
  Node_TypedEventRecord_for_AnalogSpec* node = Retrieve_in_TypedStorage_for_AnalogSpec_static(record);
  node->value.selectedVariation = node->value.defaultVariation;
}

////    virtual uint16_t WriteSome_in_EventTypeImpl_TypedEventRecord_for_AnalogSpec(List<EventRecord>::Iterator& iterator,
////                               EventLists& lists,
////                               IEventWriteHandler& handler) const override
uint16_t WriteSome_in_EventTypeImpl_TypedEventRecord_for_AnalogSpec_override(void *pIEventType, Iterator_in_List_for_EventRecord* iteratorEv,
    EventLists* lists,
    IEventWriteHandler* handler)
{
  std::cout<<""<<'\n';
  std::cout<<"WriteSome_in_EventTypeImpl_TypedEventRecord_for_AnalogSpec_override1"<<'\n';

  UNUSED(pIEventType);
//EventRecord* CurrentValue__in__Iterator_in_List_for_EventRecord(Iterator_in_List_for_EventRecord *pIterator_in_List_for_EventRecord);
////        const auto pos = iterator.CurrentValue();
  EventRecord* pos = CurrentValue__in__Iterator_in_List_for_EventRecord(iteratorEv);
//    Node_TypedEventRecord_for_AnalogSpec* Retrieve_in_TypedStorage_for_AnalogSpec_static(EventRecord* record);
////        const auto type = TypedStorage<T>::Retrieve(*pos);
  Node_TypedEventRecord_for_AnalogSpec* type = Retrieve_in_TypedStorage_for_AnalogSpec_static(pos);
//
//void  EventCollection_for_Analog_in_EventCollection_for_Analog(EventCollection_for_Analog *pEventCollection_for_Analog,
//    Iterator_in_List_for_EventRecord* iteratorEv,
//    EventClassCounters* counters,
//    event_variation_t_in_AnalogInfo variation);
////        EventCollection<T> collection(iterator, lists.counters, type->value.selectedVariation);
  EventCollection_for_Analog collection;

  EventCollection_for_Analog_in_EventCollection_for_Analog(&collection,
      iteratorEv,
      &(lists->counters),
      (type->value).selectedVariation);

//     uint16_t (*pWrite_in_IEventWriteHandlerOver1)(EventAnalogVariation_uint8_t variation, Analog* first, IEventCollection_for_Analog* items);//// = 0;
////        return handler.Write(type->value.selectedVariation, type->value.value, collection);
//  return handler->pWrite_in_IEventWriteHandlerOver5((type->value).selectedVariation,
  return Write_for_Analog_in_IEventWriteHandler(handler,
         (type->value).selectedVariation,
         &((type->value).value),
         &(collection.iIEventCollection_for_Analog));
}

////    virtual void RemoveTypeFromStorage(EventRecord& record, EventLists& lists) const override
void   RemoveTypeFromStorage_in_EventTypeImpl_TypedEventRecord_for_AnalogSpec_override(void *pIEventType, EventRecord* record, EventLists* lists)
{
  UNUSED(pIEventType);
//    Node_TypedEventRecord_for_AnalogSpec* Retrieve_in_TypedStorage_for_AnalogSpec_static(EventRecord* record);
////        auto node = TypedStorage<T>::Retrieve(record);
  Node_TypedEventRecord_for_AnalogSpec* node = Retrieve_in_TypedStorage_for_AnalogSpec_static(record);
//  List_TypedEventRecord_for_AnalogSpec*             GetList_for_AnalogSpec_in_EventLists(EventLists *pEventLists);
////        lists.GetList<T>().Remove(node);
  List_TypedEventRecord_for_AnalogSpec* temp = GetList_for_AnalogSpec_in_EventLists(lists);
//void Remove_in_List_TypedEventRecord_for_AnalogSpec(List_TypedEventRecord_for_AnalogSpec *pList_TypedEventRecord_for_AnalogSpec, Node_TypedEventRecord_for_AnalogSpec* node);
  Remove_in_List_TypedEventRecord_for_AnalogSpec(temp, node);
}
//----------------------------------Analog-------------------------------------------
//----------------------------------Counter-------------------------------------------

IEventType* Instance_in_EventTypeImpl_TypedEventRecord_for_CounterSpec_static(void)
{
  instance_in_EventTypeImpl_TypedEventRecord_for_CounterSpec.iIEventType.pSelectDefaultVariation_in_IEventType =
    SelectDefaultVariation_in_EventTypeImpl_TypedEventRecord_for_CounterSpec_override;
  instance_in_EventTypeImpl_TypedEventRecord_for_CounterSpec.iIEventType.pWriteSome_in_IEventType =
    WriteSome_in_EventTypeImpl_TypedEventRecord_for_CounterSpec_override;
  instance_in_EventTypeImpl_TypedEventRecord_for_CounterSpec.iIEventType.pRemoveTypeFromStorage_in_IEventType =
    RemoveTypeFromStorage_in_EventTypeImpl_TypedEventRecord_for_CounterSpec_override;
  return &(instance_in_EventTypeImpl_TypedEventRecord_for_CounterSpec.iIEventType);
}

void SelectDefaultVariation_in_EventTypeImpl_TypedEventRecord_for_CounterSpec_override(void *pIEventType, EventRecord* record)
{
  UNUSED(pIEventType);
//    Node_TypedEventRecord_for_CounterSpec* Retrieve_in_TypedStorage_for_CounterSpec_static(EventRecord* record);
////        auto node = TypedStorage<T>::Retrieve(record);
  Node_TypedEventRecord_for_CounterSpec* node = Retrieve_in_TypedStorage_for_CounterSpec_static(record);
  node->value.selectedVariation = node->value.defaultVariation;
}

////    virtual uint16_t WriteSome_in_EventTypeImpl_TypedEventRecord_for_CounterSpec(List<EventRecord>::Iterator& iterator,
////                               EventLists& lists,
////                               IEventWriteHandler& handler) const override
uint16_t WriteSome_in_EventTypeImpl_TypedEventRecord_for_CounterSpec_override(void *pIEventType, Iterator_in_List_for_EventRecord* iteratorEv,
    EventLists* lists,
    IEventWriteHandler* handler)
{
  UNUSED(pIEventType);
//EventRecord* CurrentValue__in__Iterator_in_List_for_EventRecord(Iterator_in_List_for_EventRecord *pIterator_in_List_for_EventRecord);
////        const auto pos = iterator.CurrentValue();
  EventRecord* pos = CurrentValue__in__Iterator_in_List_for_EventRecord(iteratorEv);
//    Node_TypedEventRecord_for_CounterSpec* Retrieve_in_TypedStorage_for_CounterSpec_static(EventRecord* record);
////        const auto type = TypedStorage<T>::Retrieve(*pos);
  Node_TypedEventRecord_for_CounterSpec* type = Retrieve_in_TypedStorage_for_CounterSpec_static(pos);
//
//void  EventCollection_for_Counter_in_EventCollection_for_Counter(EventCollection_for_Counter *pEventCollection_for_Counter,
//    Iterator_in_List_for_EventRecord* iteratorEv,
//    EventClassCounters* counters,
//    event_variation_t_in_CounterInfo variation);
////        EventCollection<T> collection(iterator, lists.counters, type->value.selectedVariation);
  EventCollection_for_Counter collection;

  EventCollection_for_Counter_in_EventCollection_for_Counter(&collection,
      iteratorEv,
      &(lists->counters),
      (type->value).selectedVariation);

//     uint16_t (*pWrite_in_IEventWriteHandlerOver1)(EventCounterVariation_uint8_t variation, Counter* first, IEventCollection_for_Counter* items);//// = 0;
////        return handler.Write(type->value.selectedVariation, type->value.value, collection);
//  return handler->pWrite_in_IEventWriteHandlerOver3(
  return Write_for_Counter_in_IEventWriteHandler(handler,
         (type->value).selectedVariation,
         &((type->value).value),
         &(collection.iIEventCollection_for_Counter));
}

////    virtual void RemoveTypeFromStorage(EventRecord& record, EventLists& lists) const override
void   RemoveTypeFromStorage_in_EventTypeImpl_TypedEventRecord_for_CounterSpec_override(void *pIEventType, EventRecord* record, EventLists* lists)
{
  UNUSED(pIEventType);
//    Node_TypedEventRecord_for_CounterSpec* Retrieve_in_TypedStorage_for_CounterSpec_static(EventRecord* record);
////        auto node = TypedStorage<T>::Retrieve(record);
  Node_TypedEventRecord_for_CounterSpec* node = Retrieve_in_TypedStorage_for_CounterSpec_static(record);
//  List_TypedEventRecord_for_CounterSpec*             GetList_for_CounterSpec_in_EventLists(EventLists *pEventLists);
////        lists.GetList<T>().Remove(node);
  List_TypedEventRecord_for_CounterSpec* temp = GetList_for_CounterSpec_in_EventLists(lists);
//void Remove_in_List_TypedEventRecord_for_CounterSpec(List_TypedEventRecord_for_CounterSpec *pList_TypedEventRecord_for_CounterSpec, Node_TypedEventRecord_for_CounterSpec* node);
  Remove_in_List_TypedEventRecord_for_CounterSpec(temp, node);
}
//----------------------------------Counter-------------------------------------------
//----------------------------------FrozenCounter-------------------------------------------

IEventType* Instance_in_EventTypeImpl_TypedEventRecord_for_FrozenCounterSpec_static(void)
{
  instance_in_EventTypeImpl_TypedEventRecord_for_FrozenCounterSpec.iIEventType.pSelectDefaultVariation_in_IEventType =
    SelectDefaultVariation_in_EventTypeImpl_TypedEventRecord_for_FrozenCounterSpec_override;
  instance_in_EventTypeImpl_TypedEventRecord_for_FrozenCounterSpec.iIEventType.pWriteSome_in_IEventType =
    WriteSome_in_EventTypeImpl_TypedEventRecord_for_FrozenCounterSpec_override;
  instance_in_EventTypeImpl_TypedEventRecord_for_FrozenCounterSpec.iIEventType.pRemoveTypeFromStorage_in_IEventType =
    RemoveTypeFromStorage_in_EventTypeImpl_TypedEventRecord_for_FrozenCounterSpec_override;
  return &(instance_in_EventTypeImpl_TypedEventRecord_for_FrozenCounterSpec.iIEventType);
}

void SelectDefaultVariation_in_EventTypeImpl_TypedEventRecord_for_FrozenCounterSpec_override(void *pIEventType, EventRecord* record)
{
  UNUSED(pIEventType);
//    Node_TypedEventRecord_for_FrozenCounterSpec* Retrieve_in_TypedStorage_for_FrozenCounterSpec_static(EventRecord* record);
////        auto node = TypedStorage<T>::Retrieve(record);
  Node_TypedEventRecord_for_FrozenCounterSpec* node = Retrieve_in_TypedStorage_for_FrozenCounterSpec_static(record);
  node->value.selectedVariation = node->value.defaultVariation;
}

////    virtual uint16_t WriteSome_in_EventTypeImpl_TypedEventRecord_for_FrozenCounterSpec(List<EventRecord>::Iterator& iterator,
////                               EventLists& lists,
////                               IEventWriteHandler& handler) const override
uint16_t WriteSome_in_EventTypeImpl_TypedEventRecord_for_FrozenCounterSpec_override(void *pIEventType, Iterator_in_List_for_EventRecord* iteratorEv,
    EventLists* lists,
    IEventWriteHandler* handler)
{
  UNUSED(pIEventType);
//EventRecord* CurrentValue__in__Iterator_in_List_for_EventRecord(Iterator_in_List_for_EventRecord *pIterator_in_List_for_EventRecord);
////        const auto pos = iterator.CurrentValue();
  EventRecord* pos = CurrentValue__in__Iterator_in_List_for_EventRecord(iteratorEv);
//    Node_TypedEventRecord_for_FrozenCounterSpec* Retrieve_in_TypedStorage_for_FrozenCounterSpec_static(EventRecord* record);
////        const auto type = TypedStorage<T>::Retrieve(*pos);
  Node_TypedEventRecord_for_FrozenCounterSpec* type = Retrieve_in_TypedStorage_for_FrozenCounterSpec_static(pos);
//
//void  EventCollection_for_FrozenCounter_in_EventCollection_for_FrozenCounter(EventCollection_for_FrozenCounter *pEventCollection_for_FrozenCounter,
//    Iterator_in_List_for_EventRecord* iteratorEv,
//    EventClassCounters* counters,
//    event_variation_t_in_FrozenCounterInfo variation);
////        EventCollection<T> collection(iterator, lists.counters, type->value.selectedVariation);
  EventCollection_for_FrozenCounter collection;

  EventCollection_for_FrozenCounter_in_EventCollection_for_FrozenCounter(&collection,
      iteratorEv,
      &(lists->counters),
      (type->value).selectedVariation);

//     uint16_t (*pWrite_in_IEventWriteHandlerOver1)(EventFrozenCounterVariation_uint8_t variation, FrozenCounter* first, IEventCollection_for_FrozenCounter* items);//// = 0;
////        return handler.Write(type->value.selectedVariation, type->value.value, collection);
//  return handler->pWrite_in_IEventWriteHandlerOver4(
  return Write_for_FrozenCounter_in_IEventWriteHandler(handler,
         (type->value).selectedVariation,
         &((type->value).value),
         &(collection.iIEventCollection_for_FrozenCounter));
}

////    virtual void RemoveTypeFromStorage(EventRecord& record, EventLists& lists) const override
void   RemoveTypeFromStorage_in_EventTypeImpl_TypedEventRecord_for_FrozenCounterSpec_override(void *pIEventType, EventRecord* record, EventLists* lists)
{
  UNUSED(pIEventType);
//    Node_TypedEventRecord_for_FrozenCounterSpec* Retrieve_in_TypedStorage_for_FrozenCounterSpec_static(EventRecord* record);
////        auto node = TypedStorage<T>::Retrieve(record);
  Node_TypedEventRecord_for_FrozenCounterSpec* node = Retrieve_in_TypedStorage_for_FrozenCounterSpec_static(record);
//  List_TypedEventRecord_for_FrozenCounterSpec*             GetList_for_FrozenCounterSpec_in_EventLists(EventLists *pEventLists);
////        lists.GetList<T>().Remove(node);
  List_TypedEventRecord_for_FrozenCounterSpec* temp = GetList_for_FrozenCounterSpec_in_EventLists(lists);
//void Remove_in_List_TypedEventRecord_for_FrozenCounterSpec(List_TypedEventRecord_for_FrozenCounterSpec *pList_TypedEventRecord_for_FrozenCounterSpec, Node_TypedEventRecord_for_FrozenCounterSpec* node);
  Remove_in_List_TypedEventRecord_for_FrozenCounterSpec(temp, node);
}
//----------------------------------FrozenCounter-------------------------------------------
//----------------------------------BinaryOutputStatus-------------------------------------------

IEventType* Instance_in_EventTypeImpl_TypedEventRecord_for_BinaryOutputStatusSpec_static(void)
{
  instance_in_EventTypeImpl_TypedEventRecord_for_BinaryOutputStatusSpec.iIEventType.pSelectDefaultVariation_in_IEventType =
    SelectDefaultVariation_in_EventTypeImpl_TypedEventRecord_for_BinaryOutputStatusSpec_override;
  instance_in_EventTypeImpl_TypedEventRecord_for_BinaryOutputStatusSpec.iIEventType.pWriteSome_in_IEventType =
    WriteSome_in_EventTypeImpl_TypedEventRecord_for_BinaryOutputStatusSpec_override;
  instance_in_EventTypeImpl_TypedEventRecord_for_BinaryOutputStatusSpec.iIEventType.pRemoveTypeFromStorage_in_IEventType =
    RemoveTypeFromStorage_in_EventTypeImpl_TypedEventRecord_for_BinaryOutputStatusSpec_override;
  return &(instance_in_EventTypeImpl_TypedEventRecord_for_BinaryOutputStatusSpec.iIEventType);
}

void SelectDefaultVariation_in_EventTypeImpl_TypedEventRecord_for_BinaryOutputStatusSpec_override(void *pIEventType, EventRecord* record)
{
  UNUSED(pIEventType);
//    Node_TypedEventRecord_for_BinaryOutputStatusSpec* Retrieve_in_TypedStorage_for_BinaryOutputStatusSpec_static(EventRecord* record);
////        auto node = TypedStorage<T>::Retrieve(record);
  Node_TypedEventRecord_for_BinaryOutputStatusSpec* node = Retrieve_in_TypedStorage_for_BinaryOutputStatusSpec_static(record);
  node->value.selectedVariation = node->value.defaultVariation;
}

////    virtual uint16_t WriteSome_in_EventTypeImpl_TypedEventRecord_for_BinaryOutputStatusSpec(List<EventRecord>::Iterator& iterator,
////                               EventLists& lists,
////                               IEventWriteHandler& handler) const override
uint16_t WriteSome_in_EventTypeImpl_TypedEventRecord_for_BinaryOutputStatusSpec_override(void *pIEventType, Iterator_in_List_for_EventRecord* iteratorEv,
    EventLists* lists,
    IEventWriteHandler* handler)
{
  UNUSED(pIEventType);
//EventRecord* CurrentValue__in__Iterator_in_List_for_EventRecord(Iterator_in_List_for_EventRecord *pIterator_in_List_for_EventRecord);
////        const auto pos = iterator.CurrentValue();
  EventRecord* pos = CurrentValue__in__Iterator_in_List_for_EventRecord(iteratorEv);
//    Node_TypedEventRecord_for_BinaryOutputStatusSpec* Retrieve_in_TypedStorage_for_BinaryOutputStatusSpec_static(EventRecord* record);
////        const auto type = TypedStorage<T>::Retrieve(*pos);
  Node_TypedEventRecord_for_BinaryOutputStatusSpec* type = Retrieve_in_TypedStorage_for_BinaryOutputStatusSpec_static(pos);
//
//void  EventCollection_for_BinaryOutputStatus_in_EventCollection_for_BinaryOutputStatus(EventCollection_for_BinaryOutputStatus *pEventCollection_for_BinaryOutputStatus,
//    Iterator_in_List_for_EventRecord* iteratorEv,
//    EventClassCounters* counters,
//    event_variation_t_in_BinaryOutputStatusInfo variation);
////        EventCollection<T> collection(iterator, lists.counters, type->value.selectedVariation);
  EventCollection_for_BinaryOutputStatus collection;

  EventCollection_for_BinaryOutputStatus_in_EventCollection_for_BinaryOutputStatus(&collection,
      iteratorEv,
      &(lists->counters),
      (type->value).selectedVariation);

//     uint16_t (*pWrite_in_IEventWriteHandlerOver1)(EventBinaryOutputStatusVariation_uint8_t variation, BinaryOutputStatus* first, IEventCollection_for_BinaryOutputStatus* items);//// = 0;
////        return handler.Write(type->value.selectedVariation, type->value.value, collection);
//  return handler->pWrite_in_IEventWriteHandlerOver6(
  return Write_for_BinaryOutputStatus_in_IEventWriteHandler(handler,
         (type->value).selectedVariation,
         &((type->value).value),
         &(collection.iIEventCollection_for_BinaryOutputStatus));
}

////    virtual void RemoveTypeFromStorage(EventRecord& record, EventLists& lists) const override
void   RemoveTypeFromStorage_in_EventTypeImpl_TypedEventRecord_for_BinaryOutputStatusSpec_override(void *pIEventType, EventRecord* record, EventLists* lists)
{
  UNUSED(pIEventType);
//    Node_TypedEventRecord_for_BinaryOutputStatusSpec* Retrieve_in_TypedStorage_for_BinaryOutputStatusSpec_static(EventRecord* record);
////        auto node = TypedStorage<T>::Retrieve(record);
  Node_TypedEventRecord_for_BinaryOutputStatusSpec* node = Retrieve_in_TypedStorage_for_BinaryOutputStatusSpec_static(record);
//  List_TypedEventRecord_for_BinaryOutputStatusSpec*             GetList_for_BinaryOutputStatusSpec_in_EventLists(EventLists *pEventLists);
////        lists.GetList<T>().Remove(node);
  List_TypedEventRecord_for_BinaryOutputStatusSpec* temp = GetList_for_BinaryOutputStatusSpec_in_EventLists(lists);
//void Remove_in_List_TypedEventRecord_for_BinaryOutputStatusSpec(List_TypedEventRecord_for_BinaryOutputStatusSpec *pList_TypedEventRecord_for_BinaryOutputStatusSpec, Node_TypedEventRecord_for_BinaryOutputStatusSpec* node);
  Remove_in_List_TypedEventRecord_for_BinaryOutputStatusSpec(temp, node);
}
//----------------------------------BinaryOutputStatus-------------------------------------------
//----------------------------------AnalogOutputStatus-------------------------------------------

IEventType* Instance_in_EventTypeImpl_TypedEventRecord_for_AnalogOutputStatusSpec_static(void)
{
  instance_in_EventTypeImpl_TypedEventRecord_for_AnalogOutputStatusSpec.iIEventType.pSelectDefaultVariation_in_IEventType =
    SelectDefaultVariation_in_EventTypeImpl_TypedEventRecord_for_AnalogOutputStatusSpec_override;
  instance_in_EventTypeImpl_TypedEventRecord_for_AnalogOutputStatusSpec.iIEventType.pWriteSome_in_IEventType =
    WriteSome_in_EventTypeImpl_TypedEventRecord_for_AnalogOutputStatusSpec_override;
  instance_in_EventTypeImpl_TypedEventRecord_for_AnalogOutputStatusSpec.iIEventType.pRemoveTypeFromStorage_in_IEventType =
    RemoveTypeFromStorage_in_EventTypeImpl_TypedEventRecord_for_AnalogOutputStatusSpec_override;
  return &(instance_in_EventTypeImpl_TypedEventRecord_for_AnalogOutputStatusSpec.iIEventType);
}

void SelectDefaultVariation_in_EventTypeImpl_TypedEventRecord_for_AnalogOutputStatusSpec_override(void *pIEventType, EventRecord* record)
{
  UNUSED(pIEventType);
//    Node_TypedEventRecord_for_AnalogOutputStatusSpec* Retrieve_in_TypedStorage_for_AnalogOutputStatusSpec_static(EventRecord* record);
////        auto node = TypedStorage<T>::Retrieve(record);
  Node_TypedEventRecord_for_AnalogOutputStatusSpec* node = Retrieve_in_TypedStorage_for_AnalogOutputStatusSpec_static(record);
  node->value.selectedVariation = node->value.defaultVariation;
}

////    virtual uint16_t WriteSome_in_EventTypeImpl_TypedEventRecord_for_AnalogOutputStatusSpec_override(List<EventRecord>::Iterator& iterator,
////                               EventLists& lists,
////                               IEventWriteHandler& handler) const override
uint16_t WriteSome_in_EventTypeImpl_TypedEventRecord_for_AnalogOutputStatusSpec_override(void *pIEventType, Iterator_in_List_for_EventRecord* iteratorEv,
    EventLists* lists,
    IEventWriteHandler* handler)
{
  UNUSED(pIEventType);
//EventRecord* CurrentValue__in__Iterator_in_List_for_EventRecord(Iterator_in_List_for_EventRecord *pIterator_in_List_for_EventRecord);
////        const auto pos = iterator.CurrentValue();
  EventRecord* pos = CurrentValue__in__Iterator_in_List_for_EventRecord(iteratorEv);
//    Node_TypedEventRecord_for_AnalogOutputStatusSpec* Retrieve_in_TypedStorage_for_AnalogOutputStatusSpec_static(EventRecord* record);
////        const auto type = TypedStorage<T>::Retrieve(*pos);
  Node_TypedEventRecord_for_AnalogOutputStatusSpec* type = Retrieve_in_TypedStorage_for_AnalogOutputStatusSpec_static(pos);
//
//void  EventCollection_for_AnalogOutputStatus_in_EventCollection_for_AnalogOutputStatus(EventCollection_for_AnalogOutputStatus *pEventCollection_for_AnalogOutputStatus,
//    Iterator_in_List_for_EventRecord* iteratorEv,
//    EventClassCounters* counters,
//    event_variation_t_in_AnalogOutputStatusInfo variation);
////        EventCollection<T> collection(iterator, lists.counters, type->value.selectedVariation);
  EventCollection_for_AnalogOutputStatus collection;

  EventCollection_for_AnalogOutputStatus_in_EventCollection_for_AnalogOutputStatus(&collection,
      iteratorEv,
      &(lists->counters),
      (type->value).selectedVariation);

//     uint16_t (*pWrite_in_IEventWriteHandlerOver1)(EventAnalogOutputStatusVariation_uint8_t variation, AnalogOutputStatus* first, IEventCollection_for_AnalogOutputStatus* items);//// = 0;
////        return handler.Write(type->value.selectedVariation, type->value.value, collection);
//  return handler->pWrite_in_IEventWriteHandlerOver7(
  return Write_for_AnalogOutputStatus_in_IEventWriteHandler(handler,
         (type->value).selectedVariation,
         &((type->value).value),
         &(collection.iIEventCollection_for_AnalogOutputStatus));
}

////    virtual void RemoveTypeFromStorage(EventRecord& record, EventLists& lists) const override
void   RemoveTypeFromStorage_in_EventTypeImpl_TypedEventRecord_for_AnalogOutputStatusSpec_override(void *pIEventType, EventRecord* record, EventLists* lists)
{
  UNUSED(pIEventType);
//    Node_TypedEventRecord_for_AnalogOutputStatusSpec* Retrieve_in_TypedStorage_for_AnalogOutputStatusSpec_static(EventRecord* record);
////        auto node = TypedStorage<T>::Retrieve(record);
  Node_TypedEventRecord_for_AnalogOutputStatusSpec* node = Retrieve_in_TypedStorage_for_AnalogOutputStatusSpec_static(record);
//  List_TypedEventRecord_for_AnalogOutputStatusSpec*             GetList_for_AnalogOutputStatusSpec_in_EventLists(EventLists *pEventLists);
////        lists.GetList<T>().Remove(node);
  List_TypedEventRecord_for_AnalogOutputStatusSpec* temp = GetList_for_AnalogOutputStatusSpec_in_EventLists(lists);
//void Remove_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(List_TypedEventRecord_for_AnalogOutputStatusSpec *pList_TypedEventRecord_for_AnalogOutputStatusSpec, Node_TypedEventRecord_for_AnalogOutputStatusSpec* node);
  Remove_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(temp, node);
}
//----------------------------------AnalogOutputStatus-------------------------------------------
//----------------------------------OctetString-------------------------------------------

IEventType* Instance_in_EventTypeImpl_TypedEventRecord_for_OctetStringSpec_static(void)
{
  instance_in_EventTypeImpl_TypedEventRecord_for_OctetStringSpec.iIEventType.pSelectDefaultVariation_in_IEventType =
    SelectDefaultVariation_in_EventTypeImpl_TypedEventRecord_for_OctetStringSpec_override;
  instance_in_EventTypeImpl_TypedEventRecord_for_OctetStringSpec.iIEventType.pWriteSome_in_IEventType =
    WriteSome_in_EventTypeImpl_TypedEventRecord_for_OctetStringSpec_override;
  instance_in_EventTypeImpl_TypedEventRecord_for_OctetStringSpec.iIEventType.pRemoveTypeFromStorage_in_IEventType =
    RemoveTypeFromStorage_in_EventTypeImpl_TypedEventRecord_for_OctetStringSpec_override;
  return &(instance_in_EventTypeImpl_TypedEventRecord_for_OctetStringSpec.iIEventType);
}

void SelectDefaultVariation_in_EventTypeImpl_TypedEventRecord_for_OctetStringSpec_override(void *pIEventType, EventRecord* record)
{
  UNUSED(pIEventType);
//    Node_TypedEventRecord_for_OctetStringSpec* Retrieve_in_TypedStorage_for_OctetStringSpec_static(EventRecord* record);
////        auto node = TypedStorage<T>::Retrieve(record);
  Node_TypedEventRecord_for_OctetStringSpec* node = Retrieve_in_TypedStorage_for_OctetStringSpec_static(record);
  node->value.selectedVariation = node->value.defaultVariation;
}

////    virtual uint16_t WriteSome_in_EventTypeImpl_TypedEventRecord_for_OctetStringSpec(List<EventRecord>::Iterator& iterator,
////                               EventLists& lists,
////                               IEventWriteHandler& handler) const override
uint16_t WriteSome_in_EventTypeImpl_TypedEventRecord_for_OctetStringSpec_override(void *pIEventType, Iterator_in_List_for_EventRecord* iteratorEv,
    EventLists* lists,
    IEventWriteHandler* handler)
{
  UNUSED(pIEventType);
//EventRecord* CurrentValue__in__Iterator_in_List_for_EventRecord(Iterator_in_List_for_EventRecord *pIterator_in_List_for_EventRecord);
////        const auto pos = iterator.CurrentValue();
  EventRecord* pos = CurrentValue__in__Iterator_in_List_for_EventRecord(iteratorEv);
//    Node_TypedEventRecord_for_OctetStringSpec* Retrieve_in_TypedStorage_for_OctetStringSpec_static(EventRecord* record);
////        const auto type = TypedStorage<T>::Retrieve(*pos);
  Node_TypedEventRecord_for_OctetStringSpec* type = Retrieve_in_TypedStorage_for_OctetStringSpec_static(pos);
//
//void  EventCollection_for_OctetString_in_EventCollection_for_OctetString(EventCollection_for_OctetString *pEventCollection_for_OctetString,
//    Iterator_in_List_for_EventRecord* iteratorEv,
//    EventClassCounters* counters,
//    event_variation_t_in_OctetStringInfo variation);
////        EventCollection<T> collection(iterator, lists.counters, type->value.selectedVariation);
  EventCollection_for_OctetString collection;

  EventCollection_for_OctetString_in_EventCollection_for_OctetString(&collection,
      iteratorEv,
      &(lists->counters),
      (type->value).selectedVariation);

//     uint16_t (*pWrite_in_IEventWriteHandlerOver1)(EventOctetStringVariation_uint8_t variation, OctetString* first, IEventCollection_for_OctetString* items);//// = 0;
////        return handler.Write(type->value.selectedVariation, type->value.value, collection);
//  return handler->pWrite_in_IEventWriteHandlerOver8(
  return Write_for_OctetString_in_IEventWriteHandler(handler,
         (type->value).selectedVariation,
         &((type->value).value),
         &(collection.iIEventCollection_for_OctetString));
}

////    virtual void RemoveTypeFromStorage(EventRecord& record, EventLists& lists) const override
void   RemoveTypeFromStorage_in_EventTypeImpl_TypedEventRecord_for_OctetStringSpec_override(void *pIEventType, EventRecord* record, EventLists* lists)
{
  UNUSED(pIEventType);
//    Node_TypedEventRecord_for_OctetStringSpec* Retrieve_in_TypedStorage_for_OctetStringSpec_static(EventRecord* record);
////        auto node = TypedStorage<T>::Retrieve(record);
  Node_TypedEventRecord_for_OctetStringSpec* node = Retrieve_in_TypedStorage_for_OctetStringSpec_static(record);
//  List_TypedEventRecord_for_OctetStringSpec*             GetList_for_OctetStringSpec_in_EventLists(EventLists *pEventLists);
////        lists.GetList<T>().Remove(node);
  List_TypedEventRecord_for_OctetStringSpec* temp = GetList_for_OctetStringSpec_in_EventLists(lists);
//void Remove_in_List_TypedEventRecord_for_OctetStringSpec(List_TypedEventRecord_for_OctetStringSpec *pList_TypedEventRecord_for_OctetStringSpec, Node_TypedEventRecord_for_OctetStringSpec* node);
  Remove_in_List_TypedEventRecord_for_OctetStringSpec(temp, node);
}
//----------------------------------OctetString-------------------------------------------
