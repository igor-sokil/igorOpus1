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

////#include "opendnp3/app/BinaryCommandEvent.h"
#include "header.h"
#include "BinaryCommandEvent.h"

////namespace opendnp3
////{

////BinaryCommandEvent::BinaryCommandEvent() : value(false), status(CommandStatus::SUCCESS), time(0) {}
void BinaryCommandEvent_In_BinaryCommandEventOver1(BinaryCommandEvent *pBinaryCommandEvent)
{
  pBinaryCommandEvent->value = false;
  pBinaryCommandEvent->status = CommandStatus_SUCCESS;
  DNPTime_in_DNPTimeOver2(&(pBinaryCommandEvent->time_DNPTime), 0);
}

////BinaryCommandEvent::BinaryCommandEvent(Flags flags) : value(GetValueFromFlags(flags)), status(GetStatusFromFlags(flags))
void BinaryCommandEvent_In_BinaryCommandEventOver2(BinaryCommandEvent *pBinaryCommandEvent, Flags flags)
{
  pBinaryCommandEvent->value = GetValueFromFlags_In_BinaryCommandEvent_static(flags);
}

void BinaryCommandEvent_In_BinaryCommandEventOver3(BinaryCommandEvent *pBinaryCommandEvent, Flags flags, DNPTime time_DNPTime)
{
  pBinaryCommandEvent->value = GetValueFromFlags_In_BinaryCommandEvent_static(flags);
  pBinaryCommandEvent->status = GetStatusFromFlags_In_BinaryCommandEvent_static(flags);
  pBinaryCommandEvent->time_DNPTime = time_DNPTime;
}

void BinaryCommandEvent_In_BinaryCommandEventOver4(BinaryCommandEvent *pBinaryCommandEvent,
    boolean value, CommandStatus_uint8_t status)
{
  pBinaryCommandEvent->value = value;
  pBinaryCommandEvent->status = status;
}

void BinaryCommandEvent_In_BinaryCommandEventOver5(BinaryCommandEvent *pBinaryCommandEvent,
    boolean value, CommandStatus_uint8_t status, DNPTime time_DNPTime)
{
  pBinaryCommandEvent->value = value;
  pBinaryCommandEvent->status = status;
  pBinaryCommandEvent->time_DNPTime = time_DNPTime;
}

Flags GetFlags_in_BinaryCommandEvent(BinaryCommandEvent *pBinaryCommandEvent)
{
  Flags fFlags;
  Flags_In_FlagsOver2(&fFlags, (((uint8_t)pBinaryCommandEvent->value) << 7) | pBinaryCommandEvent->status);
  return fFlags;
}

boolean operatorEQ_in_BinaryCommandEvent(BinaryCommandEvent *pBinaryCommandEvent, BinaryCommandEvent *rhs)
{
  return pBinaryCommandEvent->value == rhs->value &&
         pBinaryCommandEvent->status == rhs->status &&
         operatorEQ_in_DNPTime(&(pBinaryCommandEvent->time_DNPTime), &(rhs->time_DNPTime));
}

boolean GetValueFromFlags_In_BinaryCommandEvent_static(Flags flags)
{
  return (flags.value & ValueMask_in_BinaryCommandEvent) == ValueMask_in_BinaryCommandEvent;
}

CommandStatus_uint8_t GetStatusFromFlags_In_BinaryCommandEvent_static(Flags flags)
{
  return flags.value & StatusMask_in_BinaryCommandEvent;
}

////} // namespace opendnp3
