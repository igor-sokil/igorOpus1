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

#ifndef OPENDNP3_UNITTESTS_MOCKFRAMESINK_H
#define OPENDNP3_UNITTESTS_MOCKFRAMESINK_H

////#include <opendnp3/gen/LinkFunction.h>

////#include "dnp3mocks/DataSink.h"

////#include <link/ILinkSession.h>
////#include <link/LinkLayerConstants.h>

#include "LinkFunction.h"

#include "DataSink.h"

#include "ILinkSession.h"
#include "LinkLayerConstants.h"

#include <functional>
#include <queue>

////class MockFrameSink : public opendnp3::ILinkSession
typedef struct
{
  ILinkSession iILinkSession;

////public:
////    MockFrameSink();

  // ILinkSession members
////    bool OnLowerLayerUp() override;
////    bool OnLowerLayerDown() override;
////    bool OnTxReady() override;

////    bool OnFrame(const opendnp3::LinkHeaderFields& header, const ser4cpp::rseq_t& userdata) final;

////    void Reset();

////    bool CheckLast(opendnp3::LinkFunction func, bool aIsMaster, uint16_t aDest, uint16_t aSrc);
////    bool CheckLastWithFCB(opendnp3::LinkFunction func, bool aIsMaster, bool aFcb, uint16_t aDest, uint16_t aSrc);
////    bool CheckLastWithDFC(
////        opendnp3::LinkFunction func, bool aIsMaster, bool aIsRcvBuffFull, uint16_t aDest, uint16_t aSrc);

  // Last frame information
  uint16_t m_num_frames;
  LinkHeaderFields m_last_header;

  boolean mLowerOnline;

  // Add a function to execute the next time a frame is received
  // This allows us to test re-entrant behaviors
// Добавляем функцию, которая будет выполняться при следующем получении кадра
   // Это позволяет нам тестировать поведение повторного входа
////    void AddAction(const std::function<void()>& fun);

  DataSink received;

////private:
  // Executes one action, if one is available
////    void ExecuteAction();

  std::deque<std::function<void()>> m_actions;

////    void Update(opendnp3::LinkFunction aCode, bool aIsMaster, uint16_t aSrc, uint16_t aDest);
} MockFrameSink;

void MockFrameSink_in_MockFrameSink(MockFrameSink *pMockFrameSink);

boolean OnLowerLayerUp_in_MockFrameSink_override(void *pILinkSession);
boolean OnLowerLayerDown_in_MockFrameSink_override(void *pILinkSession);
boolean OnTxReady_in_MockFrameSink_override(void *pILinkSession);

boolean OnFrame_in_MockFrameSink_override(void* pIFrameSink, LinkHeaderFields* header, RSeq_for_Uint16_t* userdata);

boolean OnLowerLayerUp_in_MockFrameSink(MockFrameSink *pMockFrameSink);
boolean OnLowerLayerDown_in_MockFrameSink(MockFrameSink *pMockFrameSink);
boolean OnTxReady_in_MockFrameSink(MockFrameSink *pMockFrameSink);

boolean OnFrame_in_MockFrameSink(MockFrameSink *pMockFrameSink, LinkHeaderFields* header, RSeq_for_Uint16_t* userdata);

void Update_in_MockFrameSink(MockFrameSink *pMockFrameSink, LinkFunction_uint8_t aCode, boolean aIsMaster, uint16_t aSrc, uint16_t aDest);
void AddAction_in_MockFrameSink(MockFrameSink *pMockFrameSink, const std::function<void()>& fun);

boolean CheckLast_in_MockFrameSink(MockFrameSink *pMockFrameSink, LinkFunction_uint8_t func, boolean aIsMaster, uint16_t aDest, uint16_t aSrc);
boolean CheckLastWithFCB_in_MockFrameSink(MockFrameSink *pMockFrameSink, LinkFunction_uint8_t func, boolean aIsMaster, boolean aFcb, uint16_t aDest, uint16_t aSrc);
boolean CheckLastWithDFC_in_MockFrameSink(MockFrameSink *pMockFrameSink,
    LinkFunction_uint8_t func, boolean aIsMaster, boolean aIsRcvBuffFull, uint16_t aDest, uint16_t aSrc);

#endif
