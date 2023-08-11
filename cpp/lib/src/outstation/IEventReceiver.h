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
#ifndef OPENDNP3_IEVENTRECEIVER_H
#define OPENDNP3_IEVENTRECEIVER_H

////#include "app/MeasurementTypeSpecs.h"
////#include "outstation/Event.h"

#include "MeasurementTypeSpecs.h"
#include "Event.h"

////namespace opendnp3
////{

/**
 * Transactional interface that receives events
 */
////class IEventReceiver
typedef struct
{
////public:
////    virtual ~IEventReceiver() {}

  void (*pUpdate_BinarySpec_in_IEventReceiver)(void*, Event_for_BinarySpec* evt);// = 0;

  void (*pUpdate_DoubleBitBinarySpec_in_IEventReceiver)(void*, Event_for_DoubleBitBinarySpec* evt);// = 0;

  void (*pUpdate_AnalogSpec_in_IEventReceiver)(void*, Event_for_AnalogSpec* evt);// = 0;

  void (*pUpdate_CounterSpec_in_IEventReceiver)(void*, Event_for_CounterSpec* evt);// = 0;

  void (*pUpdate_FrozenCounterSpec_in_IEventReceiver)(void*, Event_for_FrozenCounterSpec* evt);// = 0;

  void (*pUpdate_BinaryOutputStatusSpec_in_IEventReceiver)(void*, Event_for_BinaryOutputStatusSpec* evt);// = 0;

  void (*pUpdate_AnalogOutputStatusSpec_in_IEventReceiver)(void*, Event_for_AnalogOutputStatusSpec* evt);// = 0;

  void (*pUpdate_OctetStringSpec_in_IEventReceiver)(void*, Event_for_OctetStringSpec* evt);// = 0;

  void* pParentPointer_in_IEventReceiver;
} IEventReceiver;

void Update_BinarySpec_in_IEventReceiver(IEventReceiver *, Event_for_BinarySpec* evt);
void Update_DoubleBitBinarySpec_in_IEventReceiver(IEventReceiver *, Event_for_DoubleBitBinarySpec* evt);
void Update_AnalogSpec_in_IEventReceiver(IEventReceiver *, Event_for_AnalogSpec* evt);
void Update_CounterSpec_in_IEventReceiver(IEventReceiver *, Event_for_CounterSpec* evt);
void Update_FrozenCounterSpec_in_IEventReceiver(IEventReceiver *, Event_for_FrozenCounterSpec* evt);
void Update_BinaryOutputStatusSpec_in_IEventReceiver(IEventReceiver *, Event_for_BinaryOutputStatusSpec* evt);
void Update_AnalogOutputStatusSpec_in_IEventReceiver(IEventReceiver *, Event_for_AnalogOutputStatusSpec* evt);
void UpdateOctetStringSpec_in_IEventReceiver(IEventReceiver *, Event_for_OctetStringSpec* evt);

void* getParentPointer_in_IEventReceiver(IEventReceiver*);
void  setParentPointer_in_IEventReceiver(IEventReceiver*, void*);

////} // namespace opendnp3

#endif
