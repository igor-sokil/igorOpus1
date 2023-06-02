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
#ifndef OPENDNP3_EVENTSELECTION_H
#define OPENDNP3_EVENTSELECTION_H

////#include "EventLists.h"

////#include "opendnp3/app/ClassField.h"

#include "EventLists.h"

#include "ClassField.h"

////namespace opendnp3
////{

////struct EventSelection : private StaticOnly
////{
////    template<class T> static uint32_t SelectByType(EventLists& lists, uint32_t max)
////    {
////        return SelectByTypeGeneric<T>(lists, true, static_cast<typename T::event_variation_t>(0), max);
////    }

////    template<class T>
////    static uint32_t SelectByType(EventLists& lists, typename T::event_variation_t variation, uint32_t max)
////    {
////        return SelectByTypeGeneric<T>(lists, false, variation, max);
////    }
////
////    static uint32_t SelectByClass(EventLists& lists, const ClassField& clazz, uint32_t max);
////
////private:
////    template<class T>
////    static uint32_t SelectByTypeGeneric(EventLists& lists,
////                                        bool useDefaultVariation,
////                                        typename T::event_variation_t variation,
////                                        uint32_t max);
////};
uint32_t SelectByClass_in_EventSelection_static(EventLists* lists, ClassField* clazz, uint32_t max);

//----------------------------------BinarySpec-----------------------------------------------
////    template<class T>
uint32_t SelectByTypeGeneric_for_BinarySpec_in_EventSelection_static(EventLists* lists,
    boolean useDefaultVariation,
////                                        typename T::event_variation_t variation,
    event_variation_t_in_BinaryInfo variation,
    uint32_t max);
uint32_t SelectByType_for_BinarySpec_in_EventSelection_staticOver1(EventLists* lists, uint32_t max);
uint32_t SelectByType_for_BinarySpec_in_EventSelection_staticOver2(EventLists* lists, event_variation_t_in_BinaryInfo variation, uint32_t max);

//----------------------------------BinarySpec-----------------------------------------------
//----------------------------------DoubleBitBinarySpec-----------------------------------------------
////    template<class T>
uint32_t SelectByTypeGeneric_for_DoubleBitBinarySpec_in_EventSelection_static(EventLists* lists,
    boolean useDefaultVariation,
////                                        typename T::event_variation_t variation,
    event_variation_t_in_DoubleBitBinaryInfo variation,
    uint32_t max);
uint32_t SelectByType_for_DoubleBitBinarySpec_in_EventSelection_staticOver1(EventLists* lists, uint32_t max);
uint32_t SelectByType_for_DoubleBitBinarySpec_in_EventSelection_staticOver2(EventLists* lists, event_variation_t_in_DoubleBitBinaryInfo variation, uint32_t max);

//----------------------------------DoubleBitBinarySpec-----------------------------------------------
//----------------------------------AnalogSpec-----------------------------------------------
////    template<class T>
uint32_t SelectByTypeGeneric_for_AnalogSpec_in_EventSelection_static(EventLists* lists,
    boolean useDefaultVariation,
////                                        typename T::event_variation_t variation,
    event_variation_t_in_AnalogInfo variation,
    uint32_t max);
uint32_t SelectByType_for_AnalogSpec_in_EventSelection_staticOver1(EventLists* lists, uint32_t max);
uint32_t SelectByType_for_AnalogSpec_in_EventSelection_staticOver2(EventLists* lists, event_variation_t_in_AnalogInfo variation, uint32_t max);

//----------------------------------AnalogSpec-----------------------------------------------
//----------------------------------CounterSpec-----------------------------------------------
////    template<class T>
uint32_t SelectByTypeGeneric_for_CounterSpec_in_EventSelection_static(EventLists* lists,
    boolean useDefaultVariation,
////                                        typename T::event_variation_t variation,
    event_variation_t_in_CounterInfo variation,
    uint32_t max);
uint32_t SelectByType_for_CounterSpec_in_EventSelection_staticOver1(EventLists* lists, uint32_t max);
uint32_t SelectByType_for_CounterSpec_in_EventSelection_staticOver2(EventLists* lists, event_variation_t_in_CounterInfo variation, uint32_t max);

//----------------------------------CounterSpec-----------------------------------------------
//----------------------------------FrozenCounterSpec-----------------------------------------------
////    template<class T>
uint32_t SelectByTypeGeneric_for_FrozenCounterSpec_in_EventSelection_static(EventLists* lists,
    boolean useDefaultVariation,
////                                        typename T::event_variation_t variation,
    event_variation_t_in_FrozenCounterInfo variation,
    uint32_t max);
uint32_t SelectByType_for_FrozenCounterSpec_in_EventSelection_staticOver1(EventLists* lists, uint32_t max);
uint32_t SelectByType_for_FrozenCounterSpec_in_EventSelection_staticOver2(EventLists* lists, event_variation_t_in_FrozenCounterInfo variation, uint32_t max);

//----------------------------------FrozenCounterSpec-----------------------------------------------
//----------------------------------BinaryOutputStatusSpec-----------------------------------------------
////    template<class T>
uint32_t SelectByTypeGeneric_for_BinaryOutputStatusSpec_in_EventSelection_static(EventLists* lists,
    boolean useDefaultVariation,
////                                        typename T::event_variation_t variation,
    event_variation_t_in_BinaryOutputStatusInfo variation,
    uint32_t max);
uint32_t SelectByType_for_BinaryOutputStatusSpec_in_EventSelection_staticOver1(EventLists* lists, uint32_t max);
uint32_t SelectByType_for_BinaryOutputStatusSpec_in_EventSelection_staticOver2(EventLists* lists, event_variation_t_in_BinaryOutputStatusInfo variation, uint32_t max);

//----------------------------------BinaryOutputStatusSpec-----------------------------------------------
//----------------------------------AnalogOutputStatusSpec-----------------------------------------------
////    template<class T>
uint32_t SelectByTypeGeneric_for_AnalogOutputStatusSpec_in_EventSelection_static(EventLists* lists,
    boolean useDefaultVariation,
////                                        typename T::event_variation_t variation,
    event_variation_t_in_AnalogOutputStatusInfo variation,
    uint32_t max);
uint32_t SelectByType_for_AnalogOutputStatusSpec_in_EventSelection_staticOver1(EventLists* lists, uint32_t max);
uint32_t SelectByType_for_AnalogOutputStatusSpec_in_EventSelection_staticOver2(EventLists* lists, event_variation_t_in_AnalogOutputStatusInfo variation, uint32_t max);

//----------------------------------AnalogOutputStatusSpec-----------------------------------------------
//----------------------------------OctetStringSpec-----------------------------------------------
////    template<class T>
uint32_t SelectByTypeGeneric_for_OctetStringSpec_in_EventSelection_static(EventLists* lists,
    boolean useDefaultVariation,
////                                        typename T::event_variation_t variation,
    event_variation_t_in_OctetStringInfo variation,
    uint32_t max);
uint32_t SelectByType_for_OctetStringSpec_in_EventSelection_staticOver1(EventLists* lists, uint32_t max);
uint32_t SelectByType_for_OctetStringSpec_in_EventSelection_staticOver2(EventLists* lists, event_variation_t_in_OctetStringInfo variation, uint32_t max);

//----------------------------------OctetStringSpec-----------------------------------------------

////
////template<class T>
////uint32_t EventSelection::SelectByTypeGeneric(EventLists& lists,
////                                             bool useDefaultVariation,
////                                             typename T::event_variation_t variation,
////                                             uint32_t max)
////{
////    auto& list = lists.GetList<T>();
////
////    uint32_t num_selected = 0;
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
////    return num_selected;
////}
////
////} // namespace opendnp3

#endif
