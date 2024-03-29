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

#ifndef OPENDNP3_LINKLAYER_H
#define OPENDNP3_LINKLAYER_H

#include "LinkContext.h"
#include "LinkLayerConfig.h"

////#include <memory>

////namespace opendnp3
////{

//	@section desc Implements the contextual state of DNP3 Data Link Layer
////class LinkLayer final : public ILinkLayer, public ILinkSession
typedef struct
{
  ILinkLayer   iILinkLayer;
  ILinkSession iILinkSession;

////public:
////    LinkLayer(const Logger& logger,
////              const std::shared_ptr<exe4cpp::IExecutor>&,
////              const std::shared_ptr<IUpperLayer>& upper,
////              const std::shared_ptr<ILinkListener>&,
////              const LinkLayerConfig&);

////    void SetRouter(ILinkTx&);

  // ---- Events from below: ILinkSession / IFrameSink  ----

////    virtual bool OnLowerLayerUp() override;
////    virtual bool OnLowerLayerDown() override;
////    virtual bool OnTxReady() override;
////    virtual bool OnFrame(const LinkHeaderFields& header, const ser4cpp::rseq_t& userdata) override;

  // ---- Events from above: ILinkLayer ----

////    virtual bool Send(ITransportSegment& segments) override;

////    const StackStatistics::Link& GetStatistics() const;

////private:
  // The full state
////    std::shared_ptr<LinkContext> ctx;
  LinkContext* ctx;
} LinkLayer;

void LinkLayer_in_LinkLayer(LinkLayer *pLinkLayer, ////const Logger& logger,
                            IExecutorExe4cpp*,
                            IUpperLayer* upper,
                            ILinkListener*,
                            LinkLayerConfig*);

void SetRouter_in_LinkLayer(LinkLayer *pLinkLayer, ILinkTx*);

Link_StackStatistics* GetStatistics_in_LinkLayer(LinkLayer *pLinkLayer);

// ---- Events from below: ILinkSession / IFrameSink  ----

boolean OnLowerLayerUp_in_LinkLayer(LinkLayer *pLinkLayer);
boolean OnLowerLayerDown_in_LinkLayer(LinkLayer *pLinkLayer);
boolean OnTxReady_in_LinkLayer(LinkLayer *pLinkLayer);
boolean OnFrame_in_LinkLayer(LinkLayer *pLinkLayer, LinkHeaderFields* header, RSeq_for_Uint16_t* userdata);

boolean OnLowerLayerUp_in_LinkLayer_override(void *pILinkSession);
boolean OnLowerLayerDown_in_LinkLayer_override(void *pILinkSession);
boolean OnTxReady_in_LinkLayer_override(void *pILinkSession);
boolean OnFrame_in_LinkLayer_override(void *pIFrameSink, LinkHeaderFields* header, RSeq_for_Uint16_t* userdata);
// ---- Events from above: ILinkLayer ----

boolean Send_in_LinkLayer(LinkLayer *pLinkLayer, ITransportSegment* segments);

boolean Send_in_LinkLayer_override(void *pILinkLayer, ITransportSegment* segments);

////} // namespace opendnp3

#endif
