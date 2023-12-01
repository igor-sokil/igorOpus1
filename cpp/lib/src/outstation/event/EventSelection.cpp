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
#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "EventSelection.h"

////namespace opendnp3
////{

uint32_t SelectByClass_in_EventSelection_static(EventLists* lists, ClassField* clazz, uint32_t max)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"SelectByClass_in_EventSelection_static1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*uint32_t max= "<<(uint16_t)max<<'\n';
#endif

  uint32_t num_selected = 0;
//    auto iter = lists->events.Iterate();
  Iterator_in_List_for_EventRecord iter = Iterate_in_List_for_EventRecord(&(lists->events));//List_for_EventRecord *pList_for_EventRecord)

//boolean HasNext__in__Iterator_in_List_for_EventRecord(Iterator_in_List_for_EventRecord *pIterator_in_List_for_EventRecord);
////    while (iter.HasNext() && num_selected < max)
  while (HasNext__in__Iterator_in_List_for_EventRecord(&iter) && (num_selected < max))
  {
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"SelectByClass_in_EventSelection_static2"<<'\n';
#endif
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

#ifdef  LOG_INFO
  decrement_stack_info();
#endif
  return num_selected;
}

////} // namespace opendnp3
//----------------------------------BinarySpec-----------------------------------------------
boolean select__for__TypedEventRecord_for_BinarySpec_in_EventSelection(EventLists* lists,
    TypedEventRecord_for_BinarySpec* node,
    uint32_t maxEv,
    event_variation_t_in_BinaryInfo variation,
    boolean useDefaultVariation);

//boolean (*select__for__TypedEventRecord_for_BinarySpec_in_EventSelection)(EventLists* lists, TypedEventRecord_for_BinarySpec* node, uint32_t num_selected, uint32_t maxEv, event_variation_t_in_BinaryInfo variation)
boolean select__for__TypedEventRecord_for_BinarySpec_in_EventSelection(EventLists* lists,
    TypedEventRecord_for_BinarySpec* node,
    uint32_t maxEv,
    event_variation_t_in_BinaryInfo variation,
    boolean useDefaultVariation)
////    auto select = [&](TypedEventRecord<T>& node) -> bool {
{
  uint32_t* pnum_selected = (uint32_t*)pPointerGlobal1;

#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"select__for__TypedEventRecord_for_BinarySpec_in_EventSelection1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*uint32_t num_selected= "<<*pnum_selected<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*uint32_t maxEv= "<<maxEv<<'\n';
#endif

  if ((*pnum_selected) == maxEv)
{
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
    return false;
}

  if (node->record->value.state == EventState_unselected)
  {
    node->record->value.state = EventState_selected;
    node->selectedVariation = useDefaultVariation ? node->defaultVariation : variation;
////            lists.counters.OnSelect();
    OnSelect_in_EventClassCounters(&(lists->counters));
    ++(*pnum_selected);
  }

#ifdef  LOG_INFO
  decrement_stack_info();
#endif
  return true;
}

uint32_t SelectByTypeGeneric_for_BinarySpec_in_EventSelection_static(EventLists* lists,
    boolean useDefaultVariation,
    event_variation_t_in_BinaryInfo variation,
    uint32_t maxEv)
{
////    auto& list = lists.GetList<T>();
  List_TypedEventRecord_for_BinarySpec* listEv = GetList_for_BinarySpec_in_EventLists(lists);
////
  uint32_t num_selected = 0;

  pPointerGlobal1 = &num_selected;

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

////    list.ForeachWhile(select);
  ForeachWhile_in_List_TypedEventRecord_for_BinarySpec(listEv,
      lists,
      /*num_selected,*/  maxEv,
      variation,
      useDefaultVariation,
      select__for__TypedEventRecord_for_BinarySpec_in_EventSelection);

  return num_selected;
}

////    template<class T> static uint32_t SelectByType(EventLists& lists, uint32_t max)
uint32_t SelectByType_for_BinarySpec_in_EventSelection_staticOver1(EventLists* lists, uint32_t max)
{
////        return SelectByTypeGeneric<T>(lists, true, static_cast<typename T::event_variation_t>(0), max);
  return SelectByTypeGeneric_for_BinarySpec_in_EventSelection_static(lists,
         true,
////                                        typename T::event_variation_t variation,
         0,
         max);
}

uint32_t SelectByType_for_BinarySpec_in_EventSelection_staticOver2(EventLists* lists, event_variation_t_in_BinaryInfo variation, uint32_t max)
{
  return SelectByTypeGeneric_for_BinarySpec_in_EventSelection_static(lists,
         false,
////                                        typename T::event_variation_t variation,
         variation,
         max);
}

//----------------------------------BinarySpec-----------------------------------------------
//----------------------------------DoubleBitBinarySpec-----------------------------------------------
boolean select__for__TypedEventRecord_for_DoubleBitBinarySpec_in_EventSelection(EventLists* lists,
    TypedEventRecord_for_DoubleBitBinarySpec* node,
    /*uint32_t num_selected,*/ uint32_t maxEv,
    event_variation_t_in_BinaryInfo variation,
    boolean useDefaultVariation);

//boolean (*select__for__TypedEventRecord_for_BinarySpec_in_EventSelection)(EventLists* lists, TypedEventRecord_for_BinarySpec* node, uint32_t num_selected, uint32_t maxEv, event_variation_t_in_BinaryInfo variation)
boolean select__for__TypedEventRecord_for_DoubleBitBinarySpec_in_EventSelection(EventLists* lists,
    TypedEventRecord_for_DoubleBitBinarySpec* node,
    /*uint32_t num_selected,*/ uint32_t maxEv,
    event_variation_t_in_DoubleBitBinaryInfo variation,
    boolean useDefaultVariation)
////    auto select = [&](TypedEventRecord<T>& node) -> bool {
{
  uint32_t* pnum_selected = (uint32_t*)pPointerGlobal1;

  if ((*pnum_selected) == maxEv)
    return false;

  if (node->record->value.state == EventState_unselected)
  {
    node->record->value.state = EventState_selected;
    node->selectedVariation = useDefaultVariation ? node->defaultVariation : variation;
////            lists.counters.OnSelect();
    OnSelect_in_EventClassCounters(&(lists->counters));
    ++(*pnum_selected);
  }

  return true;
}

uint32_t SelectByTypeGeneric_for_DoubleBitBinarySpec_in_EventSelection_static(EventLists* lists,
    boolean useDefaultVariation,
    event_variation_t_in_DoubleBitBinaryInfo variation,
    uint32_t maxEv)
{
////    auto& list = lists.GetList<T>();
  List_TypedEventRecord_for_DoubleBitBinarySpec* listEv = GetList_for_DoubleBitBinarySpec_in_EventLists(lists);
////
  uint32_t num_selected = 0;

  pPointerGlobal1 = &num_selected;

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
  ForeachWhile_in_List_TypedEventRecord_for_DoubleBitBinarySpec(listEv,
      lists,
      /*num_selected,*/  maxEv,
      variation,
      useDefaultVariation,
      select__for__TypedEventRecord_for_DoubleBitBinarySpec_in_EventSelection);

  return num_selected;
}

uint32_t SelectByType_for_DoubleBitBinarySpec_in_EventSelection_staticOver1(EventLists* lists, uint32_t max)
{
////        return SelectByTypeGeneric<T>(lists, true, static_cast<typename T::event_variation_t>(0), max);
  return SelectByTypeGeneric_for_DoubleBitBinarySpec_in_EventSelection_static(lists,
         true,
////                                        typename T::event_variation_t variation,
         0,
         max);
}

uint32_t SelectByType_for_DoubleBitBinarySpec_in_EventSelection_staticOver2(EventLists* lists, event_variation_t_in_DoubleBitBinaryInfo variation, uint32_t max)
{
  return SelectByTypeGeneric_for_DoubleBitBinarySpec_in_EventSelection_static(lists,
         false,
////                                        typename T::event_variation_t variation,
         variation,
         max);
}
//----------------------------------DoubleBitBinarySpec-----------------------------------------------
//----------------------------------AnalogSpec-----------------------------------------------
boolean select__for__TypedEventRecord_for_AnalogSpec_in_EventSelection(EventLists* lists,
    TypedEventRecord_for_AnalogSpec* node,
    /*uint32_t num_selected,*/ uint32_t maxEv,
    event_variation_t_in_AnalogInfo variation,
    boolean useDefaultVariation);

//boolean (*select__for__TypedEventRecord_for_BinarySpec_in_EventSelection)(EventLists* lists, TypedEventRecord_for_BinarySpec* node, uint32_t num_selected, uint32_t maxEv, event_variation_t_in_BinaryInfo variation)
boolean select__for__TypedEventRecord_for_AnalogSpec_in_EventSelection(EventLists* lists,
    TypedEventRecord_for_AnalogSpec* node,
    /*uint32_t num_selected,*/ uint32_t maxEv,
    event_variation_t_in_AnalogInfo variation,
    boolean useDefaultVariation)
////    auto select = [&](TypedEventRecord<T>& node) -> bool {
{
  uint32_t* pnum_selected = (uint32_t*)pPointerGlobal1;

#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"select__for__TypedEventRecord_for_AnalogSpec_in_EventSelection1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*uint32_t num_selected= "<<(uint16_t)*pnum_selected<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*uint32_t maxEv= "<<(uint16_t)maxEv<<'\n';

  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*boolean useDefaultVariation= "<<(uint16_t)useDefaultVariation<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*event_variation_t_in_AnalogInfo variation= "<<(uint16_t)variation<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*node->record->value.state= "<<(uint16_t)node->record->value.state<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*EventState_unselected= "<<(uint16_t)EventState_unselected<<'\n';
#endif

  if ((*pnum_selected) == maxEv)
{
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
    return false;
}

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"select__for__TypedEventRecord_for_AnalogSpec_in_EventSelection2"<<'\n';
#endif

  if (node->record->value.state == EventState_unselected)
  {
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*node->defaultVariation= "<<(uint16_t)node->defaultVariation<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"select__for__TypedEventRecord_for_AnalogSpec_in_EventSelection3"<<'\n';
#endif

    node->record->value.state = EventState_selected;
    node->selectedVariation = useDefaultVariation ? node->defaultVariation : variation;
////            lists.counters.OnSelect();
    OnSelect_in_EventClassCounters(&(lists->counters));
    ++(*pnum_selected);
  }

#ifdef  LOG_INFO
  decrement_stack_info();
#endif
  return true;
}

uint32_t SelectByTypeGeneric_for_AnalogSpec_in_EventSelection_static(EventLists* lists,
    boolean useDefaultVariation,
    event_variation_t_in_AnalogInfo variation,
    uint32_t maxEv)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"SelectByTypeGeneric_for_AnalogSpec_in_EventSelection_static1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*boolean useDefaultVariation= "<<(uint16_t)useDefaultVariation<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*event_variation_t_in_AnalogInfo variation= "<<(uint16_t)variation<<'\n';
#endif

////    auto& list = lists.GetList<T>();
  List_TypedEventRecord_for_AnalogSpec* listEv = GetList_for_AnalogSpec_in_EventLists(lists);
////
  uint32_t num_selected = 0;
  pPointerGlobal1 = &num_selected;

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
  ForeachWhile_in_List_TypedEventRecord_for_AnalogSpec(listEv,
      lists,
      /*num_selected,*/  maxEv,
      variation,
      useDefaultVariation,
      select__for__TypedEventRecord_for_AnalogSpec_in_EventSelection);

#ifdef  LOG_INFO
  decrement_stack_info();
#endif
  return num_selected;
}

uint32_t SelectByType_for_AnalogSpec_in_EventSelection_staticOver1(EventLists* lists, uint32_t max)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"SelectByType_for_AnalogSpec_in_EventSelection_staticOver1_1"<<'\n';
#endif
//uint32_t SelectByTypeGeneric_for_AnalogSpec_in_EventSelection_static(EventLists* lists,
//    boolean useDefaultVariation,
//    event_variation_t_in_AnalogInfo variation,
//    uint32_t maxEv)
////        return SelectByTypeGeneric<T>(lists, true, static_cast<typename T::event_variation_t>(0), max);
  uint32_t tmp = SelectByTypeGeneric_for_AnalogSpec_in_EventSelection_static(
         lists,
         true,
////                                        typename T::event_variation_t variation,
         0,
         max);
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
  return tmp;
}

uint32_t SelectByType_for_AnalogSpec_in_EventSelection_staticOver2(EventLists* lists, event_variation_t_in_AnalogInfo variation, uint32_t max)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"SelectByType_for_AnalogSpec_in_EventSelection_staticOver2_1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*event_variation_t_in_AnalogInfo variation= "<<(uint16_t)variation<<'\n';
#endif
  uint32_t tmp = SelectByTypeGeneric_for_AnalogSpec_in_EventSelection_static(lists,
         false,
////                                        typename T::event_variation_t variation,
         variation,
         max);
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
  return tmp;
}
//----------------------------------AnalogSpec-----------------------------------------------
//----------------------------------CounterSpec-----------------------------------------------
boolean select__for__TypedEventRecord_for_CounterSpec_in_EventSelection(EventLists* lists,
    TypedEventRecord_for_CounterSpec* node,
    /*uint32_t num_selected,*/ uint32_t maxEv,
    event_variation_t_in_CounterInfo variation,
    boolean useDefaultVariation);

//boolean (*select__for__TypedEventRecord_for_BinarySpec_in_EventSelection)(EventLists* lists, TypedEventRecord_for_BinarySpec* node, uint32_t num_selected, uint32_t maxEv, event_variation_t_in_BinaryInfo variation)
boolean select__for__TypedEventRecord_for_CounterSpec_in_EventSelection(EventLists* lists,
    TypedEventRecord_for_CounterSpec* node,
    /*uint32_t num_selected,*/ uint32_t maxEv,
    event_variation_t_in_CounterInfo variation,
    boolean useDefaultVariation)
////    auto select = [&](TypedEventRecord<T>& node) -> bool {
{
  uint32_t* pnum_selected = (uint32_t*)pPointerGlobal1;

#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"select__for__TypedEventRecord_for_CounterSpec_in_EventSelection1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*uint32_t num_selected= "<<(uint16_t)*pnum_selected<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*uint32_t maxEv= "<<(uint16_t)maxEv<<'\n';
#endif

  if ((*pnum_selected) == maxEv)
{
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
    return false;
}

  if (node->record->value.state == EventState_unselected)
  {
    node->record->value.state = EventState_selected;
    node->selectedVariation = useDefaultVariation ? node->defaultVariation : variation;
////            lists.counters.OnSelect();
    OnSelect_in_EventClassCounters(&(lists->counters));
    ++(*pnum_selected);
  }

#ifdef  LOG_INFO
  decrement_stack_info();
#endif
  return true;
}

uint32_t SelectByTypeGeneric_for_CounterSpec_in_EventSelection_static(EventLists* lists,
    boolean useDefaultVariation,
    event_variation_t_in_CounterInfo variation,
    uint32_t maxEv)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"SelectByTypeGeneric_for_CounterSpec_in_EventSelection_static1"<<'\n';
#endif

////    auto& list = lists.GetList<T>();
  List_TypedEventRecord_for_CounterSpec* listEv = GetList_for_CounterSpec_in_EventLists(lists);
////
  uint32_t num_selected = 0;
  pPointerGlobal1 = &num_selected;

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
  ForeachWhile_in_List_TypedEventRecord_for_CounterSpec(listEv,
      lists,
      /*num_selected,*/  maxEv,
      variation,
      useDefaultVariation,
      select__for__TypedEventRecord_for_CounterSpec_in_EventSelection);

#ifdef  LOG_INFO
  decrement_stack_info();
#endif
  return num_selected;
}

uint32_t SelectByType_for_CounterSpec_in_EventSelection_staticOver1(EventLists* lists, uint32_t max)
{
////        return SelectByTypeGeneric<T>(lists, true, static_cast<typename T::event_variation_t>(0), max);
  return SelectByTypeGeneric_for_CounterSpec_in_EventSelection_static(lists,
         true,
////                                        typename T::event_variation_t variation,
         0,
         max);
}

uint32_t SelectByType_for_CounterSpec_in_EventSelection_staticOver2(EventLists* lists, event_variation_t_in_CounterInfo variation, uint32_t max)
{
  return SelectByTypeGeneric_for_CounterSpec_in_EventSelection_static(lists,
         false,
////                                        typename T::event_variation_t variation,
         variation,
         max);
}
//----------------------------------CounterSpec-----------------------------------------------
//----------------------------------FrozenCounterSpec-----------------------------------------------
boolean select__for__TypedEventRecord_for_FrozenCounterSpec_in_EventSelection(EventLists* lists,
    TypedEventRecord_for_FrozenCounterSpec* node,
    /*uint32_t num_selected,*/ uint32_t maxEv,
    event_variation_t_in_FrozenCounterInfo variation,
    boolean useDefaultVariation);

//boolean (*select__for__TypedEventRecord_for_BinarySpec_in_EventSelection)(EventLists* lists, TypedEventRecord_for_BinarySpec* node, uint32_t num_selected, uint32_t maxEv, event_variation_t_in_BinaryInfo variation)
boolean select__for__TypedEventRecord_for_FrozenCounterSpec_in_EventSelection(EventLists* lists,
    TypedEventRecord_for_FrozenCounterSpec* node,
    /*uint32_t num_selected,*/ uint32_t maxEv,
    event_variation_t_in_FrozenCounterInfo variation,
    boolean useDefaultVariation)
////    auto select = [&](TypedEventRecord<T>& node) -> bool {
{
  uint32_t* pnum_selected = (uint32_t*)pPointerGlobal1;

  if ((*pnum_selected) == maxEv)
    return false;

  if (node->record->value.state == EventState_unselected)
  {
    node->record->value.state = EventState_selected;
    node->selectedVariation = useDefaultVariation ? node->defaultVariation : variation;
////            lists.counters.OnSelect();
    OnSelect_in_EventClassCounters(&(lists->counters));
    ++(*pnum_selected);
  }

  return true;
}

uint32_t SelectByTypeGeneric_for_FrozenCounterSpec_in_EventSelection_static(EventLists* lists,
    boolean useDefaultVariation,
    event_variation_t_in_FrozenCounterInfo variation,
    uint32_t maxEv)
{
////    auto& list = lists.GetList<T>();
  List_TypedEventRecord_for_FrozenCounterSpec* listEv = GetList_for_FrozenCounterSpec_in_EventLists(lists);
////
  uint32_t num_selected = 0;
  pPointerGlobal1 = &num_selected;

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
  ForeachWhile_in_List_TypedEventRecord_for_FrozenCounterSpec(listEv,
      lists,
      /*num_selected,*/  maxEv,
      variation,
      useDefaultVariation,
      select__for__TypedEventRecord_for_FrozenCounterSpec_in_EventSelection);

  return num_selected;
}

uint32_t SelectByType_for_FrozenCounterSpec_in_EventSelection_staticOver1(EventLists* lists, uint32_t max)
{
////        return SelectByTypeGeneric<T>(lists, true, static_cast<typename T::event_variation_t>(0), max);
  return SelectByTypeGeneric_for_FrozenCounterSpec_in_EventSelection_static(lists,
         true,
////                                        typename T::event_variation_t variation,
         0,
         max);
}

uint32_t SelectByType_for_FrozenCounterSpec_in_EventSelection_staticOver2(EventLists* lists, event_variation_t_in_FrozenCounterInfo variation, uint32_t max)
{
  return SelectByTypeGeneric_for_FrozenCounterSpec_in_EventSelection_static(lists,
         false,
////                                        typename T::event_variation_t variation,
         variation,
         max);
}
//----------------------------------FrozenCounterSpec-----------------------------------------------
//----------------------------------BinaryOutputStatusSpec-----------------------------------------------
boolean select__for__TypedEventRecord_for_BinaryOutputStatusSpec_in_EventSelection(EventLists* lists,
    TypedEventRecord_for_BinaryOutputStatusSpec* node,
    /*uint32_t num_selected,*/ uint32_t maxEv,
    event_variation_t_in_BinaryOutputStatusInfo variation,
    boolean useDefaultVariation);

//boolean (*select__for__TypedEventRecord_for_BinarySpec_in_EventSelection)(EventLists* lists, TypedEventRecord_for_BinarySpec* node, uint32_t num_selected, uint32_t maxEv, event_variation_t_in_BinaryInfo variation)
boolean select__for__TypedEventRecord_for_BinaryOutputStatusSpec_in_EventSelection(EventLists* lists,
    TypedEventRecord_for_BinaryOutputStatusSpec* node,
    /*uint32_t num_selected,*/ uint32_t maxEv,
    event_variation_t_in_BinaryOutputStatusInfo variation,
    boolean useDefaultVariation)
////    auto select = [&](TypedEventRecord<T>& node) -> bool {
{
  uint32_t* pnum_selected = (uint32_t*)pPointerGlobal1;

  if ((*pnum_selected) == maxEv)
    return false;

  if (node->record->value.state == EventState_unselected)
  {
    node->record->value.state = EventState_selected;
    node->selectedVariation = useDefaultVariation ? node->defaultVariation : variation;
////            lists.counters.OnSelect();
    OnSelect_in_EventClassCounters(&(lists->counters));
    ++(*pnum_selected);
  }

  return true;
}

uint32_t SelectByTypeGeneric_for_BinaryOutputStatusSpec_in_EventSelection_static(EventLists* lists,
    boolean useDefaultVariation,
    event_variation_t_in_BinaryOutputStatusInfo variation,
    uint32_t maxEv)
{
////    auto& list = lists.GetList<T>();
  List_TypedEventRecord_for_BinaryOutputStatusSpec* listEv = GetList_for_BinaryOutputStatusSpec_in_EventLists(lists);
////
  uint32_t num_selected = 0;
  pPointerGlobal1 = &num_selected;

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
  ForeachWhile_in_List_TypedEventRecord_for_BinaryOutputStatusSpec(listEv,
      lists,
      /*num_selected,*/  maxEv,
      variation,
      useDefaultVariation,
      select__for__TypedEventRecord_for_BinaryOutputStatusSpec_in_EventSelection);

  return num_selected;
}

uint32_t SelectByType_for_BinaryOutputStatusSpec_in_EventSelection_staticOver1(EventLists* lists, uint32_t max)
{
////        return SelectByTypeGeneric<T>(lists, true, static_cast<typename T::event_variation_t>(0), max);
  return SelectByTypeGeneric_for_BinaryOutputStatusSpec_in_EventSelection_static(lists,
         true,
////                                        typename T::event_variation_t variation,
         0,
         max);
}

uint32_t SelectByType_for_BinaryOutputStatusSpec_in_EventSelection_staticOver2(EventLists* lists, event_variation_t_in_BinaryOutputStatusInfo variation, uint32_t max)
{
  return SelectByTypeGeneric_for_BinaryOutputStatusSpec_in_EventSelection_static(lists,
         false,
////                                        typename T::event_variation_t variation,
         variation,
         max);
}
//----------------------------------BinaryOutputStatusSpec-----------------------------------------------
//----------------------------------AnalogOutputStatusSpec-----------------------------------------------
boolean select__for__TypedEventRecord_for_AnalogOutputStatusSpec_in_EventSelection(EventLists* lists,
    TypedEventRecord_for_AnalogOutputStatusSpec* node,
    /*uint32_t num_selected,*/ uint32_t maxEv,
    event_variation_t_in_AnalogOutputStatusInfo variation,
    boolean useDefaultVariation);

//boolean (*select__for__TypedEventRecord_for_BinarySpec_in_EventSelection)(EventLists* lists, TypedEventRecord_for_BinarySpec* node, uint32_t num_selected, uint32_t maxEv, event_variation_t_in_BinaryInfo variation)
boolean select__for__TypedEventRecord_for_AnalogOutputStatusSpec_in_EventSelection(EventLists* lists,
    TypedEventRecord_for_AnalogOutputStatusSpec* node,
    /*uint32_t num_selected,*/ uint32_t maxEv,
    event_variation_t_in_AnalogOutputStatusInfo variation,
    boolean useDefaultVariation)
////    auto select = [&](TypedEventRecord<T>& node) -> bool {
{
  uint32_t* pnum_selected = (uint32_t*)pPointerGlobal1;

  if ((*pnum_selected) == maxEv)
    return false;

  if (node->record->value.state == EventState_unselected)
  {
    node->record->value.state = EventState_selected;
    node->selectedVariation = useDefaultVariation ? node->defaultVariation : variation;
////            lists.counters.OnSelect();
    OnSelect_in_EventClassCounters(&(lists->counters));
    ++(*pnum_selected);
  }

  return true;
}

uint32_t SelectByTypeGeneric_for_AnalogOutputStatusSpec_in_EventSelection_static(EventLists* lists,
    boolean useDefaultVariation,
    event_variation_t_in_AnalogOutputStatusInfo variation,
    uint32_t maxEv)
{
////    auto& list = lists.GetList<T>();
  List_TypedEventRecord_for_AnalogOutputStatusSpec* listEv = GetList_for_AnalogOutputStatusSpec_in_EventLists(lists);
////
  uint32_t num_selected = 0;
  pPointerGlobal1 = &num_selected;

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
  ForeachWhile_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(listEv,
      lists,
      /*num_selected,*/  maxEv,
      variation,
      useDefaultVariation,
      select__for__TypedEventRecord_for_AnalogOutputStatusSpec_in_EventSelection);

  return num_selected;
}

uint32_t SelectByType_for_AnalogOutputStatusSpec_in_EventSelection_staticOver1(EventLists* lists, uint32_t max)
{
////        return SelectByTypeGeneric<T>(lists, true, static_cast<typename T::event_variation_t>(0), max);
  return SelectByTypeGeneric_for_AnalogOutputStatusSpec_in_EventSelection_static(lists,
         true,
////                                        typename T::event_variation_t variation,
         0,
         max);
}

uint32_t SelectByType_for_AnalogOutputStatusSpec_in_EventSelection_staticOver2(EventLists* lists, event_variation_t_in_AnalogOutputStatusInfo variation, uint32_t max)
{
  return SelectByTypeGeneric_for_AnalogOutputStatusSpec_in_EventSelection_static(lists,
         false,
////                                        typename T::event_variation_t variation,
         variation,
         max);
}
//----------------------------------AnalogOutputStatusSpec-----------------------------------------------
//----------------------------------OctetStringSpec-----------------------------------------------
boolean select__for__TypedEventRecord_for_OctetStringSpec_in_EventSelection(EventLists* lists,
    TypedEventRecord_for_OctetStringSpec* node,
    /*uint32_t num_selected,*/ uint32_t maxEv,
    event_variation_t_in_OctetStringInfo variation,
    boolean useDefaultVariation);

//boolean (*select__for__TypedEventRecord_for_BinarySpec_in_EventSelection)(EventLists* lists, TypedEventRecord_for_BinarySpec* node, uint32_t num_selected, uint32_t maxEv, event_variation_t_in_BinaryInfo variation)
boolean select__for__TypedEventRecord_for_OctetStringSpec_in_EventSelection(EventLists* lists,
    TypedEventRecord_for_OctetStringSpec* node,
    /*uint32_t num_selected,*/ uint32_t maxEv,
    event_variation_t_in_OctetStringInfo variation,
    boolean useDefaultVariation)
////    auto select = [&](TypedEventRecord<T>& node) -> bool {
{
  uint32_t* pnum_selected = (uint32_t*)pPointerGlobal1;

  if ((*pnum_selected) == maxEv)
    return false;

  if (node->record->value.state == EventState_unselected)
  {
    node->record->value.state = EventState_selected;
    node->selectedVariation = useDefaultVariation ? node->defaultVariation : variation;
////            lists.counters.OnSelect();
    OnSelect_in_EventClassCounters(&(lists->counters));
    ++(*pnum_selected);
  }

  return true;
}

uint32_t SelectByTypeGeneric_for_OctetStringSpec_in_EventSelection_static(EventLists* lists,
    boolean useDefaultVariation,
    event_variation_t_in_OctetStringInfo variation,
    uint32_t maxEv)
{
////    auto& list = lists.GetList<T>();
  List_TypedEventRecord_for_OctetStringSpec* listEv = GetList_for_OctetStringSpec_in_EventLists(lists);
////
  uint32_t num_selected = 0;
  pPointerGlobal1 = &num_selected;

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
  ForeachWhile_in_List_TypedEventRecord_for_OctetStringSpec(listEv,
      lists,
      /*num_selected,*/  maxEv,
      variation,
      useDefaultVariation,
      select__for__TypedEventRecord_for_OctetStringSpec_in_EventSelection);

  return num_selected;
}

uint32_t SelectByType_for_OctetStringSpec_in_EventSelection_staticOver1(EventLists* lists, uint32_t max)
{
////        return SelectByTypeGeneric<T>(lists, true, static_cast<typename T::event_variation_t>(0), max);
  return SelectByTypeGeneric_for_OctetStringSpec_in_EventSelection_static(lists,
         true,
////                                        typename T::event_variation_t variation,
         0,
         max);
}

uint32_t SelectByType_for_OctetStringSpec_in_EventSelection_staticOver2(EventLists* lists, event_variation_t_in_OctetStringInfo variation, uint32_t max)
{
  return SelectByTypeGeneric_for_OctetStringSpec_in_EventSelection_static(lists,
         false,
////                                        typename T::event_variation_t variation,
         variation,
         max);
}
//----------------------------------OctetStringSpec-----------------------------------------------
