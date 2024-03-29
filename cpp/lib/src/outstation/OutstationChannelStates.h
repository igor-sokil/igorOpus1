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
#ifndef OPENDNP3_OUTSTATIONCHANNEL_STATES_H
#define OPENDNP3_OUTSTATIONCHANNEL_STATES_H

////#include "app/TxBuffer.h"
////#include "outstation/OutstationSeqNum.h"

////#include "opendnp3/util/Uncopyable.h"

#include "TxBuffer.h"
#include "OutstationSeqNum.h"

////namespace opendnp3
////{

////class OutstationSolState : private Uncopyable
typedef struct
{
////public:
////    OutstationSolState(uint32_t maxTxSize) : tx(maxTxSize) {}

////    void Reset() {}

  OutstationSeqNum seq;
  TxBuffer tx;
} OutstationSolState;

void  OutstationSolState_in_OutstationSolState(OutstationSolState *pOutstationSolState, uint32_t maxTxSize);

void Reset_in_OutstationSolState(OutstationSolState *pOutstationSolState);


////class OutstationUnsolState : private Uncopyable
typedef struct
{
////public:
////    OutstationUnsolState(uint32_t maxTxSize) : completedNull(false), tx(maxTxSize) {}

////    void Reset()
////    {
////        completedNull = false;
////    }

  boolean completedNull;
  OutstationSeqNum seq;
  TxBuffer tx;
} OutstationUnsolState;

void Reset_in_OutstationUnsolState(OutstationUnsolState *pOutstationUnsolState);
void OutstationUnsolState_in_OutstationUnsolState(OutstationUnsolState *pOutstationUnsolState, uint32_t maxTxSize);



////} // namespace opendnp3

#endif
