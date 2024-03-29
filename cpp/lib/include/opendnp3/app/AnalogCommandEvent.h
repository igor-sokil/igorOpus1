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
#ifndef OPENDNP3_ANALOGCOMMANDEVENT_H
#define OPENDNP3_ANALOGCOMMANDEVENT_H

////#include "opendnp3/app/DNPTime.h"
////#include "opendnp3/gen/CommandStatus.h"

#include "DNPTime.h"
#include "CommandStatus.h"

////namespace opendnp3
////{

/**
 * Occurs when an outstation receives and analog command. Maps to Group43.
 */
////class AnalogCommandEvent
typedef struct
{
////public:
////    AnalogCommandEvent();

////    AnalogCommandEvent(double value, CommandStatus status);

////    AnalogCommandEvent(double value, CommandStatus status, DNPTime time);

  double value;
  CommandStatus_uint8_t status;
  DNPTime timeDNPTime;

////    bool operator==(const AnalogCommandEvent& rhs) const;
} AnalogCommandEvent;

void AnalogCommandEvent_in_AnalogCommandEventOver1(AnalogCommandEvent *pAnalogCommandEvent);
void AnalogCommandEvent_in_AnalogCommandEventOver2(AnalogCommandEvent *pAnalogCommandEvent, double value, CommandStatus_uint8_t status);
void AnalogCommandEvent_in_AnalogCommandEventOver3(AnalogCommandEvent *pAnalogCommandEvent, double value, CommandStatus_uint8_t status, DNPTime timeDNPTime);
boolean operatorEQ_in_AnalogCommandEvent(AnalogCommandEvent *pAnalogCommandEvent, AnalogCommandEvent *rhs);

////} // namespace opendnp3

#endif
