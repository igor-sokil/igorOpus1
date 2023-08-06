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

#ifndef OPENDNP3_BINARYCOMMANDEVENT_H
#define OPENDNP3_BINARYCOMMANDEVENT_H

////#include "opendnp3/app/DNPTime.h"
////#include "opendnp3/app/Flags.h"
////#include "opendnp3/gen/CommandStatus.h"
#include "DNPTime.h"
#include "Flags.h"
#include "CommandStatus.h"

////namespace opendnp3
////{

/**
Maps to Group13Var1/2
*/
////class BinaryCommandEvent
typedef struct
{
////public:
////    BinaryCommandEvent();

////    BinaryCommandEvent(Flags flags);

////    BinaryCommandEvent(Flags flags, DNPTime time);

////    BinaryCommandEvent(bool value, CommandStatus status);

////    BinaryCommandEvent(bool value, CommandStatus status, DNPTime time);

////    bool value;
////    CommandStatus status;
////    DNPTime time;
  boolean value;
  CommandStatus_uint8_t status;
  DNPTime timeDNPTime;

////    Flags GetFlags() const;

////    bool operator==(const BinaryCommandEvent& rhs) const;

////private:

////    static bool GetValueFromFlags(Flags flags);
////    static CommandStatus GetStatusFromFlags(Flags flags);
} BinaryCommandEvent;

const uint8_t ValueMask_in_BinaryCommandEvent = 0x80;
const uint8_t StatusMask_in_BinaryCommandEvent = 0x7F;

boolean GetValueFromFlags_In_BinaryCommandEvent_static(Flags flags);
CommandStatus_uint8_t GetStatusFromFlags_In_BinaryCommandEvent_static(Flags flags);

void BinaryCommandEvent_In_BinaryCommandEventOver1(BinaryCommandEvent *pBinaryCommandEvent);
void BinaryCommandEvent_In_BinaryCommandEventOver2(BinaryCommandEvent *pBinaryCommandEvent, Flags flags);
void BinaryCommandEvent_In_BinaryCommandEventOver3(BinaryCommandEvent *pBinaryCommandEvent, Flags flags, DNPTime timeDNPTime);
void BinaryCommandEvent_In_BinaryCommandEventOver4(BinaryCommandEvent *pBinaryCommandEvent, boolean value,
    CommandStatus_uint8_t status);
void BinaryCommandEvent_In_BinaryCommandEventOver5(BinaryCommandEvent *pBinaryCommandEvent, boolean value,
    CommandStatus_uint8_t status, DNPTime timeDNPTime);
boolean operatorEQ_in_BinaryCommandEvent(BinaryCommandEvent *pBinaryCommandEvent, BinaryCommandEvent *rhs);

Flags GetFlags_in_BinaryCommandEvent(BinaryCommandEvent *pBinaryCommandEvent);

////} // namespace opendnp3

#endif
