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
#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
//#include <QApplication>
#include "header.h"
#include "MockFrameSink.h"

////using namespace opendnp3;
////using namespace ser4cpp;

void MockFrameSink_in_MockFrameSink(MockFrameSink *pMockFrameSink)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  std::cout<<"{MockFrameSink_in_MockFrameSink1"<<'\n';
#endif
  LinkHeaderFields_in_LinkHeaderFieldsOver1(&(pMockFrameSink->m_last_header));

  pMockFrameSink->m_num_frames = 0;
  pMockFrameSink->mLowerOnline = false;

  pMockFrameSink->iILinkSession.pOnTxReady_in_ILinkSession = OnTxReady_in_MockFrameSink_override;
  pMockFrameSink->iILinkSession.pOnLowerLayerUp_in_ILinkSession = OnLowerLayerUp_in_MockFrameSink_override;
  pMockFrameSink->iILinkSession.pOnLowerLayerDown_in_ILinkSession = OnLowerLayerDown_in_MockFrameSink_override;

  pMockFrameSink->iILinkSession.iIFrameSink.pOnFrame_in_IFrameSink = OnFrame_in_MockFrameSink_override;

  setParentPointer_in_ILinkSession(&(pMockFrameSink->iILinkSession), pMockFrameSink);
  setParentPointer_in_IFrameSink(&(pMockFrameSink->iILinkSession.iIFrameSink), pMockFrameSink);
#ifdef  LOG_INFO
  std::cout<<'\n';
  std::cout<<"}MockFrameSink_in_MockFrameSink_"<<'\n';
#endif
}

boolean OnLowerLayerUp_in_MockFrameSink_override(void *pILinkSession)
{
  MockFrameSink* parent =  (MockFrameSink*) getParentPointer_in_ILinkSession((ILinkSession*) pILinkSession);
  return OnLowerLayerUp_in_MockFrameSink(parent);
}
boolean OnLowerLayerDown_in_MockFrameSink_override(void *pILinkSession)
{
  MockFrameSink* parent =  (MockFrameSink*) getParentPointer_in_ILinkSession((ILinkSession*) pILinkSession);
  return OnLowerLayerDown_in_MockFrameSink(parent);
}
boolean OnTxReady_in_MockFrameSink_override(void *pILinkSession)
{
  MockFrameSink* parent =  (MockFrameSink*) getParentPointer_in_ILinkSession((ILinkSession*) pILinkSession);
  return OnTxReady_in_MockFrameSink(parent);
}

boolean OnFrame_in_MockFrameSink_override(void* pIFrameSink, LinkHeaderFields* header, RSeq_for_Uint16_t* userdata)
{
  MockFrameSink* parent =  (MockFrameSink*) getParentPointer_in_IFrameSink((IFrameSink*) pIFrameSink);
  return OnFrame_in_MockFrameSink(parent, header, userdata);
}

////boolean MockFrameSink::OnLowerLayerUp()
boolean OnLowerLayerUp_in_MockFrameSink(MockFrameSink *pMockFrameSink)
{
  pMockFrameSink->mLowerOnline = true;
  return true;
}

////bool MockFrameSink::OnLowerLayerDown()
boolean OnLowerLayerDown_in_MockFrameSink(MockFrameSink *pMockFrameSink)
{
  pMockFrameSink->mLowerOnline = false;
  return true;
}

void Reset_in_MockFrameSink(MockFrameSink *pMockFrameSink)
{
//   void Clear_in_DataSink(DataSink *pDataSink);
////    this->received.Clear();
  Clear_in_DataSink(&(pMockFrameSink->received));
  pMockFrameSink->m_num_frames = 0;
}

boolean CheckLast_in_MockFrameSink(MockFrameSink *pMockFrameSink, LinkFunction_uint8_t func, boolean isMaster, uint16_t dest, uint16_t src)
{
  return (pMockFrameSink->m_last_header.func == func) && (isMaster == pMockFrameSink->m_last_header.isFromMaster)
         && (pMockFrameSink->m_last_header.addresses.source == src) && (pMockFrameSink->m_last_header.addresses.destination == dest);
}

boolean CheckLastWithFCB_in_MockFrameSink(MockFrameSink *pMockFrameSink, LinkFunction_uint8_t func, boolean isMaster, boolean aFcb, uint16_t dest, uint16_t src)
{
//boolean CheckLast_in_MockFrameSink(MockFrameSink *pMockFrameSink, LinkFunction_uint8_t func, boolean isMaster, uint16_t dest, uint16_t src)
  return (pMockFrameSink->m_last_header.fcb == aFcb) && CheckLast_in_MockFrameSink(pMockFrameSink, func, isMaster, dest, src);
}

boolean CheckLastWithDFC_in_MockFrameSink(MockFrameSink *pMockFrameSink, LinkFunction_uint8_t func, boolean isMaster, boolean aIsRcvBuffFull, uint16_t dest, uint16_t src)
{
  return (pMockFrameSink->m_last_header.fcvdfc == aIsRcvBuffFull) && CheckLast_in_MockFrameSink(pMockFrameSink, func, isMaster, dest, src);
}

////bool MockFrameSink::OnTxReady()
boolean OnTxReady_in_MockFrameSink(MockFrameSink *pMockFrameSink)
{
  UNUSED(pMockFrameSink);
  return true;
}

////bool MockFrameSink::OnFrame(const LinkHeaderFields& header, const rseq_t& userdata)
boolean OnFrame_in_MockFrameSink(MockFrameSink *pMockFrameSink, LinkHeaderFields* header, RSeq_for_Uint16_t* userdata)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  std::cout<<"{OnFrame_in_MockFrameSink1"<<'\n';
  inspect_RSeq(userdata);
#endif
  ++(pMockFrameSink->m_num_frames);

  pMockFrameSink->m_last_header = *header;

//    boolean is_not_empty_in_HasLength_for_Uint16_t(HasLength_for_Uint16_t *pHasLength);
////    if (userdata.is_not_empty())
  if (is_not_empty_in_HasLength_for_Uint16_t(&(userdata->hHasLength)))
  {
//    void Write_in_DataSink(DataSink *pDataSink, RSeq_for_Uint16_t* data);
////        this->received.Write(userdata);
    Write_in_DataSink(&(pMockFrameSink->received), userdata);
  }

#ifdef  LOG_INFO
  std::cout<<'\n';
  std::cout<<"}OnFrame_in_MockFrameSink_"<<'\n';
#endif
  return true;
}

void AddAction_in_MockFrameSink(MockFrameSink *pMockFrameSink, const std::function<void()>& fun)
{
  pMockFrameSink->m_actions.push_back(fun);
}

void ExecuteAction_in_MockFrameSink(MockFrameSink *pMockFrameSink)
{
  if (!pMockFrameSink->m_actions.empty())
  {
    auto f = pMockFrameSink->m_actions.front();
    pMockFrameSink->m_actions.pop_front();
    f();
  }
}
