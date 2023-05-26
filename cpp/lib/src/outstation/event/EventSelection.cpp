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

#include "EventSelection.h"

////namespace opendnp3
////{

uint32_t SelectByClass_in_EventSelection_static(EventLists* lists, ClassField* clazz, uint32_t max)
{
  uint32_t num_selected = 0;
//    auto iter = lists->events.Iterate();
  Iterator_in_List_for_EventRecord iter = Iterate_in_List_for_EventRecord(&(lists->events));//List_for_EventRecord *pList_for_EventRecord)

//boolean HasNext__in__Iterator_in_List_for_EventRecord(Iterator_in_List_for_EventRecord *pIterator_in_List_for_EventRecord);
////    while (iter.HasNext() && num_selected < max)
  while (HasNext__in__Iterator_in_List_for_EventRecord(&iter) && (num_selected < max))
  {
//        auto node = iter.Next();
    Node_for_EventRecord* node = Next__in__Iterator_in_List_for_EventRecord(&iter);//Iterator_in_List_for_EventRecord *pIterator_in_List_for_EventRecord);
//  boolean HasEventType_in_ClassField(ClassField *pClassField, EventClass_uint8_t ec);
////        if (node->value.state == EventState_unselected && clazz.HasEventType(node->value.clazz))
    if (node->value.state == EventState_unselected &&  HasEventType_in_ClassField(clazz, node->value.clazz))
    {
      // if not previously selected
      node->value.state = EventState_selected;
      // TODO - set the storage to use the default variation
      // node->value.selectedVariation = useDefaultVariation ? node->value.defaultVariation : variation;
      ++num_selected;
//void OnSelect_in_EventClassCounters(EventClassCounters *pEventClassCounters);
////            lists.counters.OnSelect();
      OnSelect_in_EventClassCounters(&(lists->counters));
    }
  }

  return num_selected;
}

////} // namespace opendnp3
//----------------------------------BinarySpec-----------------------------------------------
uint32_t SelectByTypeGeneric_for_BinarySpec_in_EventSelection_static(EventLists* lists,
    boolean useDefaultVariation,
    event_variation_t_in_BinaryInfo variation,
    uint32_t max)
{
////    auto& list = lists.GetList<T>();
  List_TypedEventRecord_for_BinarySpec* list = GetList_for_BinarySpec_in_EventLists(lists);
////
  uint32_t num_selected = 0;
////
////    auto select = [&](TypedEventRecord<T>& node) -> bool {
////        if (num_selected == max)
////            return false;
////
////        if (node.record->value.state == EventState::unselected)
////        {
////            node.record->value.state = EventState::selected;
////            node.selectedVariation = useDefaultVariation ? node.defaultVariation : variation;
////            lists.counters.OnSelect();
////            ++num_selected;
////        }
////
////        return true;
////    };
////
////    list.ForeachWhile(select);
////
  return num_selected;
}

//----------------------------------BinarySpec-----------------------------------------------
//----------------------------------DoubleBitBinarySpec-----------------------------------------------
uint32_t SelectByTypeGeneric_for_DoubleBitBinarySpec_in_EventSelection_static(EventLists* lists,
    boolean useDefaultVariation,
    event_variation_t_in_DoubleBitBinaryInfo variation,
    uint32_t max)
{
////    auto& list = lists.GetList<T>();
  List_TypedEventRecord_for_DoubleBitBinarySpec* list = GetList_for_DoubleBitBinarySpec_in_EventLists(lists);
////
  uint32_t num_selected = 0;
////
////    auto select = [&](TypedEventRecord<T>& node) -> bool {
////        if (num_selected == max)
////            return false;
////
////        if (node.record->value.state == EventState::unselected)
////        {
////            node.record->value.state = EventState::selected;
////            node.selectedVariation = useDefaultVariation ? node.defaultVariation : variation;
////            lists.counters.OnSelect();
////            ++num_selected;
////        }
////
////        return true;
////    };
////
////    list.ForeachWhile(select);
////
  return num_selected;
}

//----------------------------------DoubleBitBinarySpec-----------------------------------------------
//----------------------------------AnalogSpec-----------------------------------------------
uint32_t SelectByTypeGeneric_for_AnalogSpec_in_EventSelection_static(EventLists* lists,
    boolean useDefaultVariation,
    event_variation_t_in_AnalogInfo variation,
    uint32_t max)
{
////    auto& list = lists.GetList<T>();
  List_TypedEventRecord_for_AnalogSpec* list = GetList_for_AnalogSpec_in_EventLists(lists);
////
  uint32_t num_selected = 0;
////
////    auto select = [&](TypedEventRecord<T>& node) -> bool {
////        if (num_selected == max)
////            return false;
////
////        if (node.record->value.state == EventState::unselected)
////        {
////            node.record->value.state = EventState::selected;
////            node.selectedVariation = useDefaultVariation ? node.defaultVariation : variation;
////            lists.counters.OnSelect();
////            ++num_selected;
////        }
////
////        return true;
////    };
////
////    list.ForeachWhile(select);
////
  return num_selected;
}

//----------------------------------AnalogSpec-----------------------------------------------
//----------------------------------CounterSpec-----------------------------------------------
uint32_t SelectByTypeGeneric_for_CounterSpec_in_EventSelection_static(EventLists* lists,
    boolean useDefaultVariation,
    event_variation_t_in_CounterInfo variation,
    uint32_t max)
{
////    auto& list = lists.GetList<T>();
  List_TypedEventRecord_for_CounterSpec* list = GetList_for_CounterSpec_in_EventLists(lists);
////
  uint32_t num_selected = 0;
////
////    auto select = [&](TypedEventRecord<T>& node) -> bool {
////        if (num_selected == max)
////            return false;
////
////        if (node.record->value.state == EventState::unselected)
////        {
////            node.record->value.state = EventState::selected;
////            node.selectedVariation = useDefaultVariation ? node.defaultVariation : variation;
////            lists.counters.OnSelect();
////            ++num_selected;
////        }
////
////        return true;
////    };
////
////    list.ForeachWhile(select);
////
  return num_selected;
}

//----------------------------------CounterSpec-----------------------------------------------
//----------------------------------FrozenCounterSpec-----------------------------------------------
uint32_t SelectByTypeGeneric_for_FrozenCounterSpec_in_EventSelection_static(EventLists* lists,
    boolean useDefaultVariation,
    event_variation_t_in_FrozenCounterInfo variation,
    uint32_t max)
{
////    auto& list = lists.GetList<T>();
  List_TypedEventRecord_for_FrozenCounterSpec* list = GetList_for_FrozenCounterSpec_in_EventLists(lists);
////
  uint32_t num_selected = 0;
////
////    auto select = [&](TypedEventRecord<T>& node) -> bool {
////        if (num_selected == max)
////            return false;
////
////        if (node.record->value.state == EventState::unselected)
////        {
////            node.record->value.state = EventState::selected;
////            node.selectedVariation = useDefaultVariation ? node.defaultVariation : variation;
////            lists.counters.OnSelect();
////            ++num_selected;
////        }
////
////        return true;
////    };
////
////    list.ForeachWhile(select);
////
  return num_selected;
}

//----------------------------------FrozenCounterSpec-----------------------------------------------
//----------------------------------BinaryOutputStatusSpec-----------------------------------------------
uint32_t SelectByTypeGeneric_for_BinaryOutputStatusSpec_in_EventSelection_static(EventLists* lists,
    boolean useDefaultVariation,
    event_variation_t_in_BinaryOutputStatusInfo variation,
    uint32_t max)
{
////    auto& list = lists.GetList<T>();
  List_TypedEventRecord_for_BinaryOutputStatusSpec* list = GetList_for_BinaryOutputStatusSpec_in_EventLists(lists);
////
  uint32_t num_selected = 0;
////
////    auto select = [&](TypedEventRecord<T>& node) -> bool {
////        if (num_selected == max)
////            return false;
////
////        if (node.record->value.state == EventState::unselected)
////        {
////            node.record->value.state = EventState::selected;
////            node.selectedVariation = useDefaultVariation ? node.defaultVariation : variation;
////            lists.counters.OnSelect();
////            ++num_selected;
////        }
////
////        return true;
////    };
////
////    list.ForeachWhile(select);
////
  return num_selected;
}

//----------------------------------BinaryOutputStatusSpec-----------------------------------------------
//----------------------------------AnalogOutputStatusSpec-----------------------------------------------
uint32_t SelectByTypeGeneric_for_AnalogOutputStatusSpec_in_EventSelection_static(EventLists* lists,
    boolean useDefaultVariation,
    event_variation_t_in_AnalogOutputStatusInfo variation,
    uint32_t max)
{
////    auto& list = lists.GetList<T>();
  List_TypedEventRecord_for_AnalogOutputStatusSpec* list = GetList_for_AnalogOutputStatusSpec_in_EventLists(lists);
////
  uint32_t num_selected = 0;
////
////    auto select = [&](TypedEventRecord<T>& node) -> bool {
////        if (num_selected == max)
////            return false;
////
////        if (node.record->value.state == EventState::unselected)
////        {
////            node.record->value.state = EventState::selected;
////            node.selectedVariation = useDefaultVariation ? node.defaultVariation : variation;
////            lists.counters.OnSelect();
////            ++num_selected;
////        }
////
////        return true;
////    };
////
////    list.ForeachWhile(select);
////
  return num_selected;
}

//----------------------------------AnalogOutputStatusSpec-----------------------------------------------
//----------------------------------OctetStringSpec-----------------------------------------------
uint32_t SelectByTypeGeneric_for_OctetStringSpec_in_EventSelection_static(EventLists* lists,
    boolean useDefaultVariation,
    event_variation_t_in_OctetStringInfo variation,
    uint32_t max)
{
////    auto& list = lists.GetList<T>();
  List_TypedEventRecord_for_OctetStringSpec* list = GetList_for_OctetStringSpec_in_EventLists(lists);
////
  uint32_t num_selected = 0;
////
////    auto select = [&](TypedEventRecord<T>& node) -> bool {
////        if (num_selected == max)
////            return false;
////
////        if (node.record->value.state == EventState::unselected)
////        {
////            node.record->value.state = EventState::selected;
////            node.selectedVariation = useDefaultVariation ? node.defaultVariation : variation;
////            lists.counters.OnSelect();
////            ++num_selected;
////        }
////
////        return true;
////    };
////
////    list.ForeachWhile(select);
////
  return num_selected;
}

//----------------------------------OctetStringSpec-----------------------------------------------
