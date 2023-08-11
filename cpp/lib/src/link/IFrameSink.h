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
#ifndef OPENDNP3_IFRAMESINK_H
#define OPENDNP3_IFRAMESINK_H

////#include "opendnp3/link/LinkHeaderFields.h"
#include "LinkHeaderFields.h"
#include "RSeq.h"
//#include "WSeq.h"

////#include <ser4cpp/container/SequenceTypes.h>

////#include <cstdint>
////namespace opendnp3
////{

// @section DESCRIPTION Interface that receives parsed FT3 frame information
////class IFrameSink
typedef struct
{
////public:
/////    virtual ~IFrameSink() {}

  boolean (*pOnFrame_in_IFrameSink)(void*, LinkHeaderFields* header, RSeq_for_Uint16_t* userdata);// = 0;

  void* pParentPointer_in_IFrameSink;
} IFrameSink;

void OnFrame_in_IFrameSink(IFrameSink*, LinkHeaderFields* header, RSeq_for_Uint16_t* userdata);

void* getParentPointer_in_IFrameSink(IFrameSink*);
void  setParentPointer_in_IFrameSink(IFrameSink*, void*);

/////} // namespace opendnp3

#endif
