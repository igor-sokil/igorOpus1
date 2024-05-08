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

#ifndef OPENDNP3_LINKLAYERMRZS_H
#define OPENDNP3_LINKLAYERMRZS_H

////#include <opendnp3/logging/LogLevels.h>

////#include <exe4cpp/MockExecutor.h>
#include "MockExecutorExe4cpp.h"

////#include "dnp3mocks/MockLinkListener.h"
#include "MockLinkListener.h"
////#include "dnp3mocks/MockLogHandler.h"
////#include "dnp3mocks/MockTransportLayer.h"
#include "MockTransportLayer.h"

////#include <link/ILinkTx.h>
////#include <link/LinkLayer.h>

#include "ILinkTx.h"
#include "LinkLayer.h"

#include <queue>

////class LinkLayerTest : public opendnp3::ILinkTx
typedef struct
{
  ILinkTx iILinkTx;
////public:
////    LinkLayerTest(const opendnp3::LinkConfig& config);

////    LinkLayerTest(const opendnp3::LinkLayerConfig& config = DefaultConfig());

////    bool OnFrame(opendnp3::LinkFunction func,
////                 bool isMaster,
////                 bool fcb,
////                 bool fcvdfc,
////                 uint16_t dest,
////                 uint16_t source,
////                 const ser4cpp::rseq_t& userdata = ser4cpp::rseq_t::empty());

  // ILinkTx interface
////    void BeginTransmit(const ser4cpp::rseq_t& buffer, opendnp3::ILinkSession& context) final;

////    static opendnp3::LinkLayerConfig DefaultConfig();

////    MockLogHandler log;
////    std::shared_ptr<exe4cpp::MockExecutor> exe;
////    std::shared_ptr<MockLinkListener> listener;
////    std::shared_ptr<MockTransportLayer> upper;

  MockExecutor exe_in_LinkLayerMrzs;
  MockLinkListener   listener_in_LinkLayerMrzs;
  MockTransportLayer upper_in_LinkLayerMrzs;

  LinkLayer link;

////    std::string PopLastWriteAsHex();
////    uint32_t NumTotalWrites();

////private:
  uint32_t numTotalWrites;

////    std::deque<std::string> writeQueue;
  std::deque<std::string> writeQueue_in_LinkLayerMrzs;
} LinkLayerMrzs;

void  Reset_in_LinkLayerMrzs(LinkLayerMrzs *pLinkLayerMrzs);

void  LinkLayerMrzs_in_LinkLayerMrzs(LinkLayerMrzs *pLinkLayerMrzs, LinkLayerConfig* config);
LinkLayerConfig DefaultConfig_in_LinkLayerMrzs(LinkLayerMrzs *pLinkLayerMrzs);

////    LinkLayerTest(const opendnp3::LinkLayerConfig& config = DefaultConfig());

boolean OnFrame_in_LinkLayerMrzs(LinkLayerMrzs *pLinkLayerMrzs,
                                 LinkFunction_uint8_t func,
                                 boolean isMaster,
                                 boolean fcb,
                                 boolean fcvdfc,
                                 uint16_t dest,
                                 uint16_t source,
                                 RSeq_for_Uint16_t* userdata);//// = ser4cpp::rseq_t::empty());

//std::string PopLastWriteAsHex_in_LinkLayerTest(LinkLayerTest *pLinkLayerTest);

uint32_t NumTotalWrites_in_LinkLayerMrzs(LinkLayerMrzs *pLinkLayerMrzs);

// ILinkTx interface
void BeginTransmit_in_LinkLayerMrzs(LinkLayerMrzs *pLinkLayerMrzs, RSeq_for_Uint16_t* buffer, ILinkSession* context);
void BeginTransmit_in_LinkLayerMrzs_override(void *pILinkTx, RSeq_for_Uint16_t* buffer, ILinkSession* context);


#endif
