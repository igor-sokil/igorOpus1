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
#ifndef OPENDNP3_EVENTUPDATE_H
#define OPENDNP3_EVENTUPDATE_H

////#include "EventLists.h"
////#include "EventTypeImpl.h"
////#include "outstation/Event.h"

#include "EventLists.h"
#include "EventTypeImpl.h"
#include "Event.h"

////namespace opendnp3
////{

////struct EventUpdate : private StaticOnly
////{
////    template<class T> static bool Update(EventLists& lists, const Event<T>& event);
////};

//----------------------------------BinarySpec-------------------------------------------
////template<class T> bool EventUpdate::Update(EventLists& lists, const Event<T>& event)
boolean Update_BinarySpec_in_EventUpdate_static(EventLists* lists, Event_for_BinarySpec* event);
//----------------------------------BinarySpec-------------------------------------------
//----------------------------------DoubleBitBinarySpec-------------------------------------------
////template<class T> bool EventUpdate::Update(EventLists& lists, const Event<T>& event)
boolean Update_DoubleBitBinarySpec_in_EventUpdate_static(EventLists* lists, Event_for_DoubleBitBinarySpec* event);
//----------------------------------DoubleBitBinarySpec-------------------------------------------
//----------------------------------AnalogSpec-------------------------------------------
////template<class T> bool EventUpdate::Update(EventLists& lists, const Event<T>& event)
boolean Update_AnalogSpec_in_EventUpdate_static(EventLists* lists, Event_for_AnalogSpec* event);
//----------------------------------AnalogSpec-------------------------------------------
//----------------------------------CounterSpec-------------------------------------------
////template<class T> bool EventUpdate::Update(EventLists& lists, const Event<T>& event)
boolean Update_CounterSpec_in_EventUpdate_static(EventLists* lists, Event_for_CounterSpec* event);
//----------------------------------CounterSpec-------------------------------------------
//----------------------------------FrozenCounterSpec-------------------------------------------
////template<class T> bool EventUpdate::Update(EventLists& lists, const Event<T>& event)
boolean Update_FrozenCounterSpec_in_EventUpdate_static(EventLists* lists, Event_for_FrozenCounterSpec* event);
//----------------------------------FrozenCounterSpec-------------------------------------------
//----------------------------------BinaryOutputStatusSpec-------------------------------------------
////template<class T> bool EventUpdate::Update(EventLists& lists, const Event<T>& event)
boolean Update_BinaryOutputStatusSpec_in_EventUpdate_static(EventLists* lists, Event_for_BinaryOutputStatusSpec* event);
//----------------------------------BinaryOutputStatusSpec-------------------------------------------
//----------------------------------AnalogOutputStatusSpec-------------------------------------------
////template<class T> bool EventUpdate::Update(EventLists& lists, const Event<T>& event)
boolean Update_AnalogOutputStatusSpec_in_EventUpdate_static(EventLists* lists, Event_for_AnalogOutputStatusSpec* event);
//----------------------------------AnalogOutputStatusSpec-------------------------------------------
//----------------------------------OctetStringSpec-------------------------------------------
////template<class T> bool EventUpdate::Update(EventLists& lists, const Event<T>& event)
boolean Update_OctetStringSpec_in_EventUpdate_static(EventLists* lists, Event_for_OctetStringSpec* event);
//----------------------------------OctetStringSpec-------------------------------------------

//} // namespace opendnp3

#endif
