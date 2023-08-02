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
#ifndef OPENDNP3_ITRANSPORTSEGMENT_H
#define OPENDNP3_ITRANSPORTSEGMENT_H

////#include "opendnp3/link/Addresses.h"
#include "Addresses.h"

////#include <ser4cpp/container/SequenceTypes.h>
#include "RSeq.h"

////namespace opendnp3
////{

////class ITransportSegment
typedef struct
{

////public:
////    virtual ~ITransportSegment() {}

  Addresses* (*pGetAddresses_in_ITransportSegment)(void*);// const = 0;

  boolean (*pHasValue_in_ITransportSegment)(void*);// const = 0;

  // Read the current segment with a specified max size
  RSeq_for_Uint16_t (*pGetSegment_in_ITransportSegment)(void*);// = 0;

  // move to the next segment, true if more segments available
  boolean (*pAdvance_in_ITransportSegment)(void*);// = 0;

  void* pParentPointer_in_ITransportSegment;
} ITransportSegment;

Addresses* GetAddresses_in_ITransportSegment(ITransportSegment*);
boolean HasValue_in_ITransportSegment(ITransportSegment*);
RSeq_for_Uint16_t GetSegment_in_ITransportSegment(ITransportSegment*);
boolean Advance_in_ITransportSegment(ITransportSegment*);

void* getParentPointer_in_ITransportSegment(ITransportSegment*);
void  setParentPointer_in_ITransportSegment(ITransportSegment*, void*);

/////} // namespace opendnp3

#endif
