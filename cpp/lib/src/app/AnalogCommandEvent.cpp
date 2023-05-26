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

////#include "opendnp3/app/AnalogCommandEvent.h"
#include "header.h"
#include "AnalogCommandEvent.h"

////namespace opendnp3
////{

void AnalogCommandEvent_in_AnalogCommandEventOver1(AnalogCommandEvent *pAnalogCommandEvent)
{
//// : value(0), status(CommandStatus::SUCCESS) {}
  pAnalogCommandEvent->value = 0;
  pAnalogCommandEvent->status = CommandStatus_SUCCESS;
}

void AnalogCommandEvent_in_AnalogCommandEventOver2(AnalogCommandEvent *pAnalogCommandEvent, double value_, CommandStatus_uint8_t status_)
{
//// : value(value_), status(status_) {}
  pAnalogCommandEvent->value = value_;
  pAnalogCommandEvent->status = status_;
}

void AnalogCommandEvent_in_AnalogCommandEventOver3(AnalogCommandEvent *pAnalogCommandEvent, double value_, CommandStatus_uint8_t status_, DNPTime time_)
{
////    : value(value_), status(status_), time(time_)
  pAnalogCommandEvent->value = value_;
  pAnalogCommandEvent->status = status_;
  pAnalogCommandEvent->timeDNPTime = time_;
}

//bool AnalogCommandEvent::operator==(const AnalogCommandEvent& rhs) const
boolean operatorEQ_in_AnalogCommandEvent(AnalogCommandEvent *pAnalogCommandEvent, AnalogCommandEvent *rhs)
{
  return (pAnalogCommandEvent->value == rhs->value) &&
         (pAnalogCommandEvent->status == rhs->status) &&
         (operatorEQ_in_DNPTime(&(pAnalogCommandEvent->timeDNPTime), &(rhs->timeDNPTime)));
}

////} // namespace opendnp3
