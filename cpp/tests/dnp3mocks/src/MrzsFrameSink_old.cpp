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
#include "MrzsFrameSink.h"

////using namespace opendnp3;
////using namespace ser4cpp;

void MrzsFrameSink_in_MrzsFrameSink(MrzsFrameSink *pMrzsFrameSink)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  std::cout<<"{MrzsFrameSink_in_MrzsFrameSink1"<<'\n';
#endif
  LinkHeaderFields_in_LinkHeaderFieldsOver1(&(pMrzsFrameSink->m_last_header));

  pMrzsFrameSink->m_num_frames = 0;
  pMrzsFrameSink->mLowerOnline = false;

//  pMrzsFrameSink->iILinkSession.pOnTxReady_in_ILinkSession = OnTxReady_in_MrzsFrameSink_override;
//  pMrzsFrameSink->iILinkSession.pOnLowerLayerUp_in_ILinkSession = OnLowerLayerUp_in_MrzsFrameSink_override;
//  pMrzsFrameSink->iILinkSession.pOnLowerLayerDown_in_ILinkSession = OnLowerLayerDown_in_MrzsFrameSink_override;

  pMrzsFrameSink->iILinkSession.iIFrameSink.pOnFrame_in_IFrameSink = OnFrame_in_MrzsFrameSink_override;

  setParentPointer_in_ILinkSession(&(pMrzsFrameSink->iILinkSession), pMrzsFrameSink);
  setParentPointer_in_IFrameSink(&(pMrzsFrameSink->iILinkSession.iIFrameSink), pMrzsFrameSink);
#ifdef  LOG_INFO
  std::cout<<'\n';
  std::cout<<"}MrzsFrameSink_in_MrzsFrameSink_"<<'\n';
#endif
}

////boolean OnLowerLayerUp_in_MrzsFrameSink_override(void *pILinkSession)
////{
////  MrzsFrameSink* parent =  (MrzsFrameSink*) getParentPointer_in_ILinkSession((ILinkSession*) pILinkSession);
////  return OnLowerLayerUp_in_MrzsFrameSink(parent);
////}
////boolean OnLowerLayerDown_in_MrzsFrameSink_override(void *pILinkSession)
////{
////  MrzsFrameSink* parent =  (MrzsFrameSink*) getParentPointer_in_ILinkSession((ILinkSession*) pILinkSession);
////  return OnLowerLayerDown_in_MrzsFrameSink(parent);
////}
////boolean OnTxReady_in_MrzsFrameSink_override(void *pILinkSession)
////{
////  MrzsFrameSink* parent =  (MrzsFrameSink*) getParentPointer_in_ILinkSession((ILinkSession*) pILinkSession);
////  return OnTxReady_in_MrzsFrameSink(parent);
////}

boolean OnFrame_in_MrzsFrameSink_override(void* pIFrameSink, LinkHeaderFields* header, RSeq_for_Uint16_t* userdata)
{
  MrzsFrameSink* parent =  (MrzsFrameSink*) getParentPointer_in_IFrameSink((IFrameSink*) pIFrameSink);
  return OnFrame_in_MrzsFrameSink(parent, header, userdata);
}

////boolean MrzsFrameSink::OnLowerLayerUp()
////boolean OnLowerLayerUp_in_MrzsFrameSink(MrzsFrameSink *pMrzsFrameSink)
////{
////  pMrzsFrameSink->mLowerOnline = true;
////  return true;
////}

////bool MrzsFrameSink::OnLowerLayerDown()
////boolean OnLowerLayerDown_in_MrzsFrameSink(MrzsFrameSink *pMrzsFrameSink)
////{
////  pMrzsFrameSink->mLowerOnline = false;
////  return true;
////}

void Reset_in_MrzsFrameSink(MrzsFrameSink *pMrzsFrameSink)
{
//   void Clear_in_DataSink(DataSink *pDataSink);
////    this->received.Clear();
  Clear_in_DataSinkMrzs(&(pMrzsFrameSink->received_in_MrzsFrameSink));
  pMrzsFrameSink->m_num_frames = 0;
}

boolean CheckLast_in_MrzsFrameSink(MrzsFrameSink *pMrzsFrameSink, LinkFunction_uint8_t func, boolean isMaster, uint16_t dest, uint16_t src)
{
  return (pMrzsFrameSink->m_last_header.func == func) && (isMaster == pMrzsFrameSink->m_last_header.isFromMaster)
         && (pMrzsFrameSink->m_last_header.addresses.source == src) && (pMrzsFrameSink->m_last_header.addresses.destination == dest);
}

boolean CheckLastWithFCB_in_MrzsFrameSink(MrzsFrameSink *pMrzsFrameSink, LinkFunction_uint8_t func, boolean isMaster, boolean aFcb, uint16_t dest, uint16_t src)
{
//boolean CheckLast_in_MrzsFrameSink(MrzsFrameSink *pMrzsFrameSink, LinkFunction_uint8_t func, boolean isMaster, uint16_t dest, uint16_t src)
  return (pMrzsFrameSink->m_last_header.fcb == aFcb) && CheckLast_in_MrzsFrameSink(pMrzsFrameSink, func, isMaster, dest, src);
}

boolean CheckLastWithDFC_in_MrzsFrameSink(MrzsFrameSink *pMrzsFrameSink, LinkFunction_uint8_t func, boolean isMaster, boolean aIsRcvBuffFull, uint16_t dest, uint16_t src)
{
  return (pMrzsFrameSink->m_last_header.fcvdfc == aIsRcvBuffFull) && CheckLast_in_MrzsFrameSink(pMrzsFrameSink, func, isMaster, dest, src);
}

////bool MrzsFrameSink::OnTxReady()
/////boolean OnTxReady_in_MrzsFrameSink(MrzsFrameSink *pMrzsFrameSink)
////{
////  UNUSED(pMrzsFrameSink);
////  return true;
////}

////bool MrzsFrameSink::OnFrame(const LinkHeaderFields& header, const rseq_t& userdata)
boolean OnFrame_in_MrzsFrameSink(MrzsFrameSink *pMrzsFrameSink, LinkHeaderFields* header, RSeq_for_Uint16_t* userdata)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  std::cout<<"{OnFrame_in_MrzsFrameSink1"<<'\n';
  std::cout<<"FinalDestination_in_MrzsFrameSink:"<<'\n';
  inspect_LinkHeaderFields(header);
  inspect_RSeq(userdata);
#endif
  ++(pMrzsFrameSink->m_num_frames);

  pMrzsFrameSink->m_last_header = *header;

//    boolean is_not_empty_in_HasLength_for_Uint16_t(HasLength_for_Uint16_t *pHasLength);
////    if (userdata.is_not_empty())
  if (is_not_empty_in_HasLength_for_Uint16_t(&(userdata->hHasLength)))
  {
//    void Write_in_DataSink(DataSink *pDataSink, RSeq_for_Uint16_t* data);
////        this->received.Write(userdata);
    Write_in_DataSinkMrzs(&(pMrzsFrameSink->received_in_MrzsFrameSink), userdata);
  }

#ifdef  LOG_INFO
  std::cout<<'\n';
  std::cout<<"}OnFrame_in_MrzsFrameSink_"<<'\n';
#endif
  return true;
}

////void AddAction_in_MrzsFrameSink(MrzsFrameSink *pMrzsFrameSink, const std::function<void()>& fun)
////{
////  pMrzsFrameSink->m_actions.push_back(fun);
////}

////void ExecuteAction_in_MrzsFrameSink(MrzsFrameSink *pMrzsFrameSink)
////{
////  if (!pMrzsFrameSink->m_actions.empty())
////  {
////    auto f = pMrzsFrameSink->m_actions.front();
////    pMrzsFrameSink->m_actions.pop_front();
////    f();
////  }
////}
