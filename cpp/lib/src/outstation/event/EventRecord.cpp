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
#include "header.h"
#include "EventRecord.h"

////namespace opendnp3
////{

void EventRecord_in_EventRecordOver2(EventRecord *pEventRecord, uint16_t index, EventClass_uint8_t clazz)
{
  EventRecord_in_EventRecordOver1(pEventRecord);

  pEventRecord->index = index;
  pEventRecord->clazz = clazz;
}

////} // namespace opendnp3

void EventRecord_in_EventRecordOver1(EventRecord *pEventRecord)
{
  pEventRecord->index = 0;
  pEventRecord->clazz = EventClass_EC1;
  pEventRecord->state = EventState_unselected;

  // always set as a unit
//    pEventRecord->type = NULL;
//    pEventRecord->storage_node = NULL;
}
