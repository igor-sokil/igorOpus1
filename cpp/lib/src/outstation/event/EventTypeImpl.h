/*
 * Copyright 2013-2022 Step Function I/O, LLC
 *
 * Licensed to Green Energy Corp (www.greenenergycorp.com) and Step Function I/O
 * LLC (https://stepfunc.io) under one or more contributor license agreements.
 * See the NOTICE file distributed with this work for additional information
 * regarding copyright ownership. Green Energy Corp and Step Function I/O LLC license
 * this file to you under the Apache License, Version 2.0 (the "License"); you
 * may not use this file except in compliance with the License. You may obtain
 * a copy of the License at:
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef OPENDNP3_EVENTTYPEIMPL_H
#define OPENDNP3_EVENTTYPEIMPL_H

////#include "EventCollection.h"
////#include "EventWriting.h"
////#include "IEventType.h"
////#include "TypedEventRecord.h"

#include "EventCollection.h"
#include "EventWriting.h"
#include "IEventType.h"
#include "TypedEventRecord.h"

////namespace opendnp3
////{

////template<class T> class EventTypeImpl final : public IEventType

//----------------------------------Binary-------------------------------------------
typedef struct
{

////private:
////    EventTypeImpl() : IEventType(T::EventTypeEnum) {}
////
////    static EventTypeImpl instance;
////
////public:
////    static IEventType* Instance()
////    {
////        return &instance;
////    }
////
////    virtual void SelectDefaultVariation(EventRecord& record) const override
////    {
////        auto node = TypedStorage<T>::Retrieve(record);
////        node->value.selectedVariation = node->value.defaultVariation;
////    }
////
////    virtual uint16_t WriteSome(List<EventRecord>::Iterator& iterator,
////                               EventLists& lists,
////                               IEventWriteHandler& handler) const override
////    {
////        const auto pos = iterator.CurrentValue();
////        const auto type = TypedStorage<T>::Retrieve(*pos);
////
////        EventCollection<T> collection(iterator, lists.counters, type->value.selectedVariation);
////
////        return handler.Write(type->value.selectedVariation, type->value.value, collection);
////    }
////
////    virtual void RemoveTypeFromStorage(EventRecord& record, EventLists& lists) const override
////    {
////        auto node = TypedStorage<T>::Retrieve(record);
////        lists.GetList<T>().Remove(node);
////    }

  IEventType iIEventType;
} EventTypeImpl_TypedEventRecord_for_BinarySpec;

////template<class T> EventTypeImpl<T> EventTypeImpl<T>::instance;
//EventTypeImpl_TypedEventRecord_for_BinarySpec instance_in_EventTypeImpl_TypedEventRecord_for_BinarySpec;
IEventType* Instance_in_EventTypeImpl_TypedEventRecord_for_BinarySpec_static(void);
void SelectDefaultVariation_in_EventTypeImpl_TypedEventRecord_for_BinarySpec_override(void *pIEventType, EventRecord* record);
uint16_t WriteSome_in_EventTypeImpl_TypedEventRecord_for_BinarySpec_override(void *pIEventType,
    Iterator_in_List_for_EventRecord* iteratorEv,
    EventLists* lists,
    IEventWriteHandler* handler);
void   RemoveTypeFromStorage_in_EventTypeImpl_TypedEventRecord_for_BinarySpec_override(void *pIEventType, EventRecord* record, EventLists* lists);
//----------------------------------Binary-------------------------------------------
//----------------------------------DoubleBitBinary-------------------------------------------
typedef struct
{

////private:
////    EventTypeImpl() : IEventType(T::EventTypeEnum) {}
////
////    static EventTypeImpl instance;
////
////public:
////    static IEventType* Instance()
////    {
////        return &instance;
////    }
////
////    virtual void SelectDefaultVariation(EventRecord& record) const override
////    {
////        auto node = TypedStorage<T>::Retrieve(record);
////        node->value.selectedVariation = node->value.defaultVariation;
////    }
////
////    virtual uint16_t WriteSome(List<EventRecord>::Iterator& iterator,
////                               EventLists& lists,
////                               IEventWriteHandler& handler) const override
////    {
////        const auto pos = iterator.CurrentValue();
////        const auto type = TypedStorage<T>::Retrieve(*pos);
////
////        EventCollection<T> collection(iterator, lists.counters, type->value.selectedVariation);
////
////        return handler.Write(type->value.selectedVariation, type->value.value, collection);
////    }
////
////    virtual void RemoveTypeFromStorage(EventRecord& record, EventLists& lists) const override
////    {
////        auto node = TypedStorage<T>::Retrieve(record);
////        lists.GetList<T>().Remove(node);
////    }

  IEventType iIEventType;
} EventTypeImpl_TypedEventRecord_for_DoubleBitBinarySpec;

////template<class T> EventTypeImpl<T> EventTypeImpl<T>::instance;
//EventTypeImpl_TypedEventRecord_for_DoubleBitBinarySpec instance_in_EventTypeImpl_TypedEventRecord_for_DoubleBitBinarySpec;
IEventType* Instance_in_EventTypeImpl_TypedEventRecord_for_DoubleBitBinarySpec_static(void);
void SelectDefaultVariation_in_EventTypeImpl_TypedEventRecord_for_DoubleBitBinarySpec_override(void *pIEventType, EventRecord* record);
uint16_t WriteSome_in_EventTypeImpl_TypedEventRecord_for_DoubleBitBinarySpec_override(void *pIEventType, Iterator_in_List_for_EventRecord* iteratorEv,
    EventLists* lists,
    IEventWriteHandler* handler);
void   RemoveTypeFromStorage_in_EventTypeImpl_TypedEventRecord_for_DoubleBitBinarySpec_override(void *pIEventType, EventRecord* record, EventLists* lists);
//----------------------------------DoubleBitBinary-------------------------------------------
//----------------------------------Analog-------------------------------------------
typedef struct
{

////private:
////    EventTypeImpl() : IEventType(T::EventTypeEnum) {}
////
////    static EventTypeImpl instance;
////
////public:
////    static IEventType* Instance()
////    {
////        return &instance;
////    }
////
////    virtual void SelectDefaultVariation(EventRecord& record) const override
////    {
////        auto node = TypedStorage<T>::Retrieve(record);
////        node->value.selectedVariation = node->value.defaultVariation;
////    }
////
////    virtual uint16_t WriteSome(List<EventRecord>::Iterator& iterator,
////                               EventLists& lists,
////                               IEventWriteHandler& handler) const override
////    {
////        const auto pos = iterator.CurrentValue();
////        const auto type = TypedStorage<T>::Retrieve(*pos);
////
////        EventCollection<T> collection(iterator, lists.counters, type->value.selectedVariation);
////
////        return handler.Write(type->value.selectedVariation, type->value.value, collection);
////    }
////
////    virtual void RemoveTypeFromStorage(EventRecord& record, EventLists& lists) const override
////    {
////        auto node = TypedStorage<T>::Retrieve(record);
////        lists.GetList<T>().Remove(node);
////    }

  IEventType iIEventType;
} EventTypeImpl_TypedEventRecord_for_AnalogSpec;

////template<class T> EventTypeImpl<T> EventTypeImpl<T>::instance;
//EventTypeImpl_TypedEventRecord_for_AnalogSpec instance_in_EventTypeImpl_TypedEventRecord_for_AnalogSpec;
IEventType* Instance_in_EventTypeImpl_TypedEventRecord_for_AnalogSpec_static(void);
void SelectDefaultVariation_in_EventTypeImpl_TypedEventRecord_for_AnalogSpec_override(void *pIEventType, EventRecord* record);
uint16_t WriteSome_in_EventTypeImpl_TypedEventRecord_for_AnalogSpec_override(void *pIEventType, Iterator_in_List_for_EventRecord* iteratorEv,
    EventLists* lists,
    IEventWriteHandler* handler);
void   RemoveTypeFromStorage_in_EventTypeImpl_TypedEventRecord_for_AnalogSpec_override(void *pIEventType, EventRecord* record, EventLists* lists);
//----------------------------------Analog-------------------------------------------
//----------------------------------Counter-------------------------------------------
typedef struct
{

////private:
////    EventTypeImpl() : IEventType(T::EventTypeEnum) {}
////
////    static EventTypeImpl instance;
////
////public:
////    static IEventType* Instance()
////    {
////        return &instance;
////    }
////
////    virtual void SelectDefaultVariation(EventRecord& record) const override
////    {
////        auto node = TypedStorage<T>::Retrieve(record);
////        node->value.selectedVariation = node->value.defaultVariation;
////    }
////
////    virtual uint16_t WriteSome(List<EventRecord>::Iterator& iterator,
////                               EventLists& lists,
////                               IEventWriteHandler& handler) const override
////    {
////        const auto pos = iterator.CurrentValue();
////        const auto type = TypedStorage<T>::Retrieve(*pos);
////
////        EventCollection<T> collection(iterator, lists.counters, type->value.selectedVariation);
////
////        return handler.Write(type->value.selectedVariation, type->value.value, collection);
////    }
////
////    virtual void RemoveTypeFromStorage(EventRecord& record, EventLists& lists) const override
////    {
////        auto node = TypedStorage<T>::Retrieve(record);
////        lists.GetList<T>().Remove(node);
////    }

  IEventType iIEventType;
} EventTypeImpl_TypedEventRecord_for_CounterSpec;

////template<class T> EventTypeImpl<T> EventTypeImpl<T>::instance;
//EventTypeImpl_TypedEventRecord_for_CounterSpec instance_in_EventTypeImpl_TypedEventRecord_for_CounterSpec;
IEventType* Instance_in_EventTypeImpl_TypedEventRecord_for_CounterSpec_static(void);
void SelectDefaultVariation_in_EventTypeImpl_TypedEventRecord_for_CounterSpec_override(void *pIEventType, EventRecord* record);
uint16_t WriteSome_in_EventTypeImpl_TypedEventRecord_for_CounterSpec_override(void *pIEventType, Iterator_in_List_for_EventRecord* iteratorEv,
    EventLists* lists,
    IEventWriteHandler* handler);
void   RemoveTypeFromStorage_in_EventTypeImpl_TypedEventRecord_for_CounterSpec_override(void *pIEventType, EventRecord* record, EventLists* lists);
//----------------------------------Counter-------------------------------------------
//----------------------------------FrozenCounter-------------------------------------------
typedef struct
{

////private:
////    EventTypeImpl() : IEventType(T::EventTypeEnum) {}
////
////    static EventTypeImpl instance;
////
////public:
////    static IEventType* Instance()
////    {
////        return &instance;
////    }
////
////    virtual void SelectDefaultVariation(EventRecord& record) const override
////    {
////        auto node = TypedStorage<T>::Retrieve(record);
////        node->value.selectedVariation = node->value.defaultVariation;
////    }
////
////    virtual uint16_t WriteSome(List<EventRecord>::Iterator& iterator,
////                               EventLists& lists,
////                               IEventWriteHandler& handler) const override
////    {
////        const auto pos = iterator.CurrentValue();
////        const auto type = TypedStorage<T>::Retrieve(*pos);
////
////        EventCollection<T> collection(iterator, lists.counters, type->value.selectedVariation);
////
////        return handler.Write(type->value.selectedVariation, type->value.value, collection);
////    }
////
////    virtual void RemoveTypeFromStorage(EventRecord& record, EventLists& lists) const override
////    {
////        auto node = TypedStorage<T>::Retrieve(record);
////        lists.GetList<T>().Remove(node);
////    }

  IEventType iIEventType;
} EventTypeImpl_TypedEventRecord_for_FrozenCounterSpec;

////template<class T> EventTypeImpl<T> EventTypeImpl<T>::instance;
//EventTypeImpl_TypedEventRecord_for_FrozenCounterSpec instance_in_EventTypeImpl_TypedEventRecord_for_FrozenCounterSpec;
IEventType* Instance_in_EventTypeImpl_TypedEventRecord_for_FrozenCounterSpec_static(void);
void SelectDefaultVariation_in_EventTypeImpl_TypedEventRecord_for_FrozenCounterSpec_override(void *pIEventType, EventRecord* record);
uint16_t WriteSome_in_EventTypeImpl_TypedEventRecord_for_FrozenCounterSpec_override(void *pIEventType, Iterator_in_List_for_EventRecord* iteratorEv,
    EventLists* lists,
    IEventWriteHandler* handler);
void   RemoveTypeFromStorage_in_EventTypeImpl_TypedEventRecord_for_FrozenCounterSpec_override(void *pIEventType, EventRecord* record, EventLists* lists);
//----------------------------------FrozenCounter-------------------------------------------
//----------------------------------BinaryOutputStatus-------------------------------------------
typedef struct
{

////private:
////    EventTypeImpl() : IEventType(T::EventTypeEnum) {}
////
////    static EventTypeImpl instance;
////
////public:
////    static IEventType* Instance()
////    {
////        return &instance;
////    }
////
////    virtual void SelectDefaultVariation(EventRecord& record) const override
////    {
////        auto node = TypedStorage<T>::Retrieve(record);
////        node->value.selectedVariation = node->value.defaultVariation;
////    }
////
////    virtual uint16_t WriteSome(List<EventRecord>::Iterator& iterator,
////                               EventLists& lists,
////                               IEventWriteHandler& handler) const override
////    {
////        const auto pos = iterator.CurrentValue();
////        const auto type = TypedStorage<T>::Retrieve(*pos);
////
////        EventCollection<T> collection(iterator, lists.counters, type->value.selectedVariation);
////
////        return handler.Write(type->value.selectedVariation, type->value.value, collection);
////    }
////
////    virtual void RemoveTypeFromStorage(EventRecord& record, EventLists& lists) const override
////    {
////        auto node = TypedStorage<T>::Retrieve(record);
////        lists.GetList<T>().Remove(node);
////    }

  IEventType iIEventType;
} EventTypeImpl_TypedEventRecord_for_BinaryOutputStatusSpec;

////template<class T> EventTypeImpl<T> EventTypeImpl<T>::instance;
//EventTypeImpl_TypedEventRecord_for_BinaryOutputStatusSpec instance_in_EventTypeImpl_TypedEventRecord_for_BinaryOutputStatusSpec;
IEventType* Instance_in_EventTypeImpl_TypedEventRecord_for_BinaryOutputStatusSpec_static(void);
void SelectDefaultVariation_in_EventTypeImpl_TypedEventRecord_for_BinaryOutputStatusSpec_override(void *pIEventType, EventRecord* record);
uint16_t WriteSome_in_EventTypeImpl_TypedEventRecord_for_BinaryOutputStatusSpec_override(void *pIEventType, Iterator_in_List_for_EventRecord* iteratorEv,
    EventLists* lists,
    IEventWriteHandler* handler);
void   RemoveTypeFromStorage_in_EventTypeImpl_TypedEventRecord_for_BinaryOutputStatusSpec_override(void *pIEventType, EventRecord* record, EventLists* lists);
//----------------------------------BinaryOutputStatus-------------------------------------------
//----------------------------------AnalogOutputStatus-------------------------------------------
typedef struct
{

////private:
////    EventTypeImpl() : IEventType(T::EventTypeEnum) {}
////
////    static EventTypeImpl instance;
////
////public:
////    static IEventType* Instance()
////    {
////        return &instance;
////    }
////
////    virtual void SelectDefaultVariation(EventRecord& record) const override
////    {
////        auto node = TypedStorage<T>::Retrieve(record);
////        node->value.selectedVariation = node->value.defaultVariation;
////    }
////
////    virtual uint16_t WriteSome(List<EventRecord>::Iterator& iterator,
////                               EventLists& lists,
////                               IEventWriteHandler& handler) const override
////    {
////        const auto pos = iterator.CurrentValue();
////        const auto type = TypedStorage<T>::Retrieve(*pos);
////
////        EventCollection<T> collection(iterator, lists.counters, type->value.selectedVariation);
////
////        return handler.Write(type->value.selectedVariation, type->value.value, collection);
////    }
////
////    virtual void RemoveTypeFromStorage(EventRecord& record, EventLists& lists) const override
////    {
////        auto node = TypedStorage<T>::Retrieve(record);
////        lists.GetList<T>().Remove(node);
////    }

  IEventType iIEventType;
} EventTypeImpl_TypedEventRecord_for_AnalogOutputStatusSpec;

////template<class T> EventTypeImpl<T> EventTypeImpl<T>::instance;
//EventTypeImpl_TypedEventRecord_for_AnalogOutputStatusSpec instance_in_EventTypeImpl_TypedEventRecord_for_AnalogOutputStatusSpec;
IEventType* Instance_in_EventTypeImpl_TypedEventRecord_for_AnalogOutputStatusSpec_static(void);
void SelectDefaultVariation_in_EventTypeImpl_TypedEventRecord_for_AnalogOutputStatusSpec_override(void *pIEventType, EventRecord* record);
uint16_t WriteSome_in_EventTypeImpl_TypedEventRecord_for_AnalogOutputStatusSpec_override(void *pIEventType, Iterator_in_List_for_EventRecord* iteratorEv,
    EventLists* lists,
    IEventWriteHandler* handler);
void   RemoveTypeFromStorage_in_EventTypeImpl_TypedEventRecord_for_AnalogOutputStatusSpec_override(void *pIEventType, EventRecord* record, EventLists* lists);
//----------------------------------AnalogOutputStatus-------------------------------------------
//----------------------------------OctetString-------------------------------------------
typedef struct
{

////private:
////    EventTypeImpl() : IEventType(T::EventTypeEnum) {}
////
////    static EventTypeImpl instance;
////
////public:
////    static IEventType* Instance()
////    {
////        return &instance;
////    }
////
////    virtual void SelectDefaultVariation(EventRecord& record) const override
////    {
////        auto node = TypedStorage<T>::Retrieve(record);
////        node->value.selectedVariation = node->value.defaultVariation;
////    }
////
////    virtual uint16_t WriteSome(List<EventRecord>::Iterator& iterator,
////                               EventLists& lists,
////                               IEventWriteHandler& handler) const override
////    {
////        const auto pos = iterator.CurrentValue();
////        const auto type = TypedStorage<T>::Retrieve(*pos);
////
////        EventCollection<T> collection(iterator, lists.counters, type->value.selectedVariation);
////
////        return handler.Write(type->value.selectedVariation, type->value.value, collection);
////    }
////
////    virtual void RemoveTypeFromStorage(EventRecord& record, EventLists& lists) const override
////    {
////        auto node = TypedStorage<T>::Retrieve(record);
////        lists.GetList<T>().Remove(node);
////    }

  IEventType iIEventType;
} EventTypeImpl_TypedEventRecord_for_OctetStringSpec;

////template<class T> EventTypeImpl<T> EventTypeImpl<T>::instance;
//EventTypeImpl_TypedEventRecord_for_OctetStringSpec instance_in_EventTypeImpl_TypedEventRecord_for_OctetStringSpec;
IEventType* Instance_in_EventTypeImpl_TypedEventRecord_for_OctetStringSpec_static(void);
void SelectDefaultVariation_in_EventTypeImpl_TypedEventRecord_for_OctetStringSpec_override(void *pIEventType, EventRecord* record);
uint16_t WriteSome_in_EventTypeImpl_TypedEventRecord_for_OctetStringSpec_override(void *pIEventType, Iterator_in_List_for_EventRecord* iteratorEv,
    EventLists* lists,
    IEventWriteHandler* handler);
void   RemoveTypeFromStorage_in_EventTypeImpl_TypedEventRecord_for_OctetStringSpec_override(void *pIEventType, EventRecord* record, EventLists* lists);
//----------------------------------OctetString-------------------------------------------

////} // namespace opendnp3

#endif
