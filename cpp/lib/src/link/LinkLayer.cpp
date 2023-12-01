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
#include "header.h"
#include "LinkLayer.h"

////namespace opendnp3
////{

////LinkLayer::LinkLayer(const Logger& logger,
////                     const std::shared_ptr<exe4cpp::IExecutor>& executor,
////                     const std::shared_ptr<IUpperLayer>& upper,
////                     const std::shared_ptr<ILinkListener>& listener,
////                     const LinkLayerConfig& config)
void LinkLayer_in_LinkLayer(LinkLayer *pLinkLayer, ////const Logger& logger,
                            IExecutorExe4cpp* executor,
                            IUpperLayer* upper,
                            ILinkListener* listener,
                            LinkLayerConfig* config)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"{LinkLayer_in_LinkLayer1"<<'\n';
#endif

  setParentPointer_in_ILinkLayer(&(pLinkLayer->iILinkLayer), pLinkLayer);
  setParentPointer_in_ILinkSession(&(pLinkLayer->iILinkSession), pLinkLayer);
  setParentPointer_in_IFrameSink(&(pLinkLayer->iILinkSession.iIFrameSink), pLinkLayer);

  pLinkLayer->iILinkSession.pOnLowerLayerUp_in_ILinkSession = OnLowerLayerUp_in_LinkLayer_override;
  pLinkLayer->iILinkSession.pOnLowerLayerDown_in_ILinkSession = OnLowerLayerDown_in_LinkLayer_override;
  pLinkLayer->iILinkSession.pOnTxReady_in_ILinkSession = OnTxReady_in_LinkLayer_override;
  pLinkLayer->iILinkSession.iIFrameSink.pOnFrame_in_IFrameSink = OnFrame_in_LinkLayer_override;
  // ---- Events from above: ILinkLayer ----

  pLinkLayer->iILinkLayer.pSend_in_ILinkLayer = Send_in_LinkLayer_override;

//    LinkContext* Create_in_LinkContext_static( // const Logger& logger,
//                                               IExecutor*,
//                                               IUpperLayer*,
//                                               ILinkListener*,
//                                               ILinkSession* session,
//                                               LinkLayerConfig*);
///    : ctx(LinkContext::Create(logger, executor, upper, listener, *this, config))
  pLinkLayer->ctx = Create_in_LinkContext_static( // const Logger& logger,
                      executor,
                      upper,
                      listener,
                      &(pLinkLayer->iILinkSession),
                      config);

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}LinkLayer_in_LinkLayer_"<<'\n';
  decrement_stack_info();
#endif
}

////const StackStatistics::Link& LinkLayer::GetStatistics() const
Link_StackStatistics* GetStatistics_in_LinkLayer(LinkLayer *pLinkLayer)
{
////    return this->ctx->statistics;
  return &(pLinkLayer->ctx->statistics);
}

////void LinkLayer::SetRouter(ILinkTx& router)
void SetRouter_in_LinkLayer(LinkLayer *pLinkLayer, ILinkTx* router)
{
////    assert(!ctx->linktx);
////    ctx->linktx = &router;
  pLinkLayer->ctx->linktx = router;
}

////////////////////////////////
// ILowerLayer
////////////////////////////////

////bool LinkLayer::Send(ITransportSegment& segments)
boolean Send_in_LinkLayer(LinkLayer *pLinkLayer, ITransportSegment* segments)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"{Send_in_LinkLayer1"<<'\n';
#endif

  if (!pLinkLayer->ctx->isOnline)
  {
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"}Send_in_LinkLayer1_"<<'\n';
    decrement_stack_info();
#endif
    return false;
  }

//    boolean SetTxSegment_in_LinkContext(LinkContext *pLinkContext, ITransportSegment* segments);
////    if (ctx->SetTxSegment(segments))
  if (SetTxSegment_in_LinkContext(pLinkLayer->ctx, segments))
  {
//    void TryStartTransmission_in_LinkContext(LinkContext *pLinkContext);
////        ctx->TryStartTransmission();
    TryStartTransmission_in_LinkContext(pLinkLayer->ctx);
  }

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}Send_in_LinkLayer2_"<<'\n';
  decrement_stack_info();
#endif
  return true;
}

////////////////////////////////
// ILinkSession
////////////////////////////////

////bool LinkLayer::OnLowerLayerUp()
boolean  OnLowerLayerUp_in_LinkLayer(LinkLayer *pLinkLayer)
{
////    return ctx->OnLowerLayerUp();
  return OnLowerLayerUp_in_LinkContext(pLinkLayer->ctx);
}

////bool LinkLayer::OnLowerLayerDown()
boolean OnLowerLayerDown_in_LinkLayer(LinkLayer *pLinkLayer)
{
////    return ctx->OnLowerLayerDown();
  return OnLowerLayerDown_in_LinkContext(pLinkLayer->ctx);
}

////bool LinkLayer::OnTxReady()
boolean OnTxReady_in_LinkLayer(LinkLayer *pLinkLayer)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"{OnTxReady_in_LinkLayer1"<<'\n';
#endif
//    boolean OnTxReady_in_LinkContext(LinkContext *pLinkContext);
////    auto ret = ctx->OnTxReady();
  boolean ret = OnTxReady_in_LinkContext(pLinkLayer->ctx);

  if (ret)
  {
////        ctx->TryStartTransmission();
    TryStartTransmission_in_LinkContext(pLinkLayer->ctx);
  }

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}OnTxReady_in_LinkLayer_"<<'\n';
  decrement_stack_info();
#endif
  return true;
}

////////////////////////////////
// IFrameSink
////////////////////////////////

////bool LinkLayer::OnFrame(const LinkHeaderFields& header, const ser4cpp::rseq_t& userdata)
boolean OnFrame_in_LinkLayer(LinkLayer *pLinkLayer, LinkHeaderFields* header, RSeq_for_Uint16_t* userdata)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"{OnFrame_in_LinkLayer1"<<'\n';
#endif
//    boolean OnFrame_in_LinkContext(LinkContext *pLinkContext, LinkHeaderFields* header, RSeq_for_Uint16_t* userdata);
////    auto ret = this->ctx->OnFrame(header, userdata);
  boolean  ret = OnFrame_in_LinkContext(pLinkLayer->ctx, header, userdata);

  if (ret)
  {
////        this->ctx->TryStartTransmission();
    TryStartTransmission_in_LinkContext(pLinkLayer->ctx);
  }

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}OnFrame_in_LinkLayer_"<<'\n';
  decrement_stack_info();
#endif
  return ret;
}

////} // namespace opendnp3

boolean OnLowerLayerUp_in_LinkLayer_override(void *pILinkSession)
{
  LinkLayer* parent = (LinkLayer*) getParentPointer_in_ILinkSession((ILinkSession*) pILinkSession);
  return OnLowerLayerUp_in_LinkLayer(parent);
}
boolean OnLowerLayerDown_in_LinkLayer_override(void *pILinkSession)
{
  LinkLayer* parent = (LinkLayer*) getParentPointer_in_ILinkSession((ILinkSession*) pILinkSession);
  return OnLowerLayerDown_in_LinkLayer(parent);
}
boolean OnTxReady_in_LinkLayer_override(void *pILinkSession)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"{OnTxReady_in_LinkLayer_override1"<<'\n';
#endif
  LinkLayer* parent = (LinkLayer*) getParentPointer_in_ILinkSession((ILinkSession*) pILinkSession);
  boolean tmp = OnTxReady_in_LinkLayer(parent);
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"}OnTxReady_in_LinkLayer_override_"<<'\n';
#endif
  return tmp;
}
boolean OnFrame_in_LinkLayer_override(void *pIFrameSink, LinkHeaderFields* header, RSeq_for_Uint16_t* userdata)
{
  LinkLayer* parent = (LinkLayer*) getParentPointer_in_IFrameSink((IFrameSink*) pIFrameSink);
  return OnFrame_in_LinkLayer(parent, header, userdata);
}
// ---- Events from above: ILinkLayer ----
boolean Send_in_LinkLayer_override(void *pILinkLayer, ITransportSegment* segments)
{
  LinkLayer* parent = (LinkLayer*) getParentPointer_in_ILinkLayer((ILinkLayer*) pILinkLayer);
  return Send_in_LinkLayer(parent, segments);
}
