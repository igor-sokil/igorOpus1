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
#include <QApplication>
#include "header.h"
#include "LinkLayerMrzs.h"
#include "HexConversions.h"

void inspect_LogEntry(std::string &message);

////#include <ser4cpp/util/HexConversions.h>

////using namespace opendnp3;
////using namespace ser4cpp;
////LinkLayerMrzs::LinkLayerMrzs(const LinkConfig& config) : LinkLayerMrzs(LinkLayerConfig(config, false)) {}

////LinkLayerMrzs::LinkLayerMrzs(const LinkLayerConfig& config)
////    : exe(std::make_shared<exe4cpp::MockExecutor>()),
////      listener(std::make_shared<MockLinkListener>()),
////      upper(std::make_shared<MockTransportLayer>()),
////      link(log.logger, exe, upper, listener, config),
////      numTotalWrites(0)
////{
////    upper->SetLinkLayer(link);
////    link.SetRouter(*this);
////}

void  LinkLayerMrzs_in_LinkLayerMrzs(LinkLayerMrzs *pLinkLayerMrzs, LinkLayerConfig* config)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  std::cout<<"{LinkLayerMrzs_in_LinkLayerMrzs1"<<'\n';
#endif
  UNUSED(config);

  MockExecutor_in_MockExecutor(&(pLinkLayerMrzs->exe_in_LinkLayerMrzs));


  MockLinkListener_in_MockLinkListener(&(pLinkLayerMrzs->listener_in_LinkLayerMrzs));
  MockTransportLayer_in_MockTransportLayer(&(pLinkLayerMrzs->upper_in_LinkLayerMrzs));

//   void LinkLayer_in_LinkLayer(LinkLayer *pLinkLayer, ////const Logger& logger,
//              IExecutorExe4cpp*,
//              IUpperLayer* upper,
//              ILinkListener*,
//              LinkLayerConfig*);

  LinkLayer_in_LinkLayer(&(pLinkLayerMrzs->link), ////const Logger& logger,
                         &(pLinkLayerMrzs->exe_in_LinkLayerMrzs.iIExecutorExe4cpp),
                         &(pLinkLayerMrzs->upper_in_LinkLayerMrzs.iIUpperLayer),
                         &(pLinkLayerMrzs->listener_in_LinkLayerMrzs.iILinkListener),
                         config);

  pLinkLayerMrzs->numTotalWrites = 0;

////    upper->SetLinkLayer(link);
  SetLinkLayer_in_MockTransportLayer(&(pLinkLayerMrzs->upper_in_LinkLayerMrzs), &(pLinkLayerMrzs->link.iILinkLayer));//ILinkLayer* linkLayer);

//  void SetRouter_in_LinkLayer(LinkLayer *pLinkLayer, ILinkTx*);
////    link.SetRouter(*this);
  SetRouter_in_LinkLayer(&(pLinkLayerMrzs->link), &(pLinkLayerMrzs->iILinkTx));

  pLinkLayerMrzs->iILinkTx.pBeginTransmit_in_ILinkTx = BeginTransmit_in_LinkLayerMrzs_override;
  setParentPointer_in_ILinkTx(&(pLinkLayerMrzs->iILinkTx), pLinkLayerMrzs);
#ifdef  LOG_INFO
  std::cout<<"}LinkLayerMrzs_in_LinkLayerMrzs_"<<'\n';
#endif
}

boolean OnFrame_in_LinkLayerMrzs(LinkLayerMrzs *pLinkLayerMrzs,
                                 LinkFunction_uint8_t func,
                                 boolean isMaster,
                                 boolean fcb,
                                 boolean fcvdfc,
                                 uint16_t dest,
                                 uint16_t source,
                                 RSeq_for_Uint16_t* userdata)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  std::cout<<"{OnFrame_in_LinkLayerMrzs1"<<'\n';
#endif
//  void LinkHeaderFields_in_LinkHeaderFieldsOver2(LinkHeaderFields *pLinkHeaderFields, LinkFunction_uint8_t func, boolean isMaster, boolean fcb, boolean fcvdfc, Addresses addresses);
////    LinkHeaderFields fields(func, isMaster, fcb, fcvdfc, Addresses(source, dest));
  Addresses aAddresses;
  Addresses_in_AddressesOver2(&aAddresses, source, dest);
  LinkHeaderFields fields;
  LinkHeaderFields_in_LinkHeaderFieldsOver2(&fields, func, isMaster, fcb, fcvdfc, aAddresses);

//   boolean OnFrame_in_LinkLayer(LinkLayer *pLinkLayer, LinkHeaderFields* header, RSeq_for_Uint16_t* userdata);
////    return link.OnFrame(fields, userdata);
  boolean tmp = OnFrame_in_LinkLayer(&(pLinkLayerMrzs->link), &fields, userdata);
#ifdef  LOG_INFO
  std::cout<<"}OnFrame_in_LinkLayerMrzs_"<<'\n';
#endif
  return tmp;
}

////std::string LinkLayerMrzs::PopLastWriteAsHex()
////std::string PopLastWriteAsHex_in_LinkLayerMrzs(LinkLayerMrzs *pLinkLayerMrzs)
////{
////  if (pLinkLayerMrzs->writeQueue_in_LinkLayerMrzs.empty())
////  {
////    return "";
////  }

////  while (pLinkLayerMrzs->writeQueue_in_LinkLayerMrzs.size() > 1)
////  {
////    pLinkLayerMrzs->writeQueue_in_LinkLayerMrzs.pop_front();
////  }

////  std::string ret = pLinkLayerMrzs->writeQueue_in_LinkLayerMrzs.front();
////  pLinkLayerMrzs->writeQueue_in_LinkLayerMrzs.pop_front();
////  return ret;
////}

uint32_t NumTotalWrites_in_LinkLayerMrzs(LinkLayerMrzs *pLinkLayerMrzs)
{
  return pLinkLayerMrzs->numTotalWrites;
}

void BeginTransmit_in_LinkLayerMrzs(LinkLayerMrzs *pLinkLayerMrzs, RSeq_for_Uint16_t* buffer, ILinkSession* context)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  std::cout<<"{BeginTransmit_in_LinkLayerMrzs1"<<'\n';
  std::cout<<"FinalDestination_in_LinkLayerMrzs:"<<'\n';
#endif
  UNUSED(context);
  ++(pLinkLayerMrzs->numTotalWrites);
  pLinkLayerMrzs->writeQueue_in_LinkLayerMrzs.push_back(to_hex_in_HexConversionsOver2(buffer));
#ifdef  LOG_INFO
  for(uint16_t i=0; i<pLinkLayerMrzs->writeQueue_in_LinkLayerMrzs.size(); i++)
  {
   std::string tt = pLinkLayerMrzs->writeQueue_in_LinkLayerMrzs[i];
   std::cout<<"tt= "<<tt<<'\n';

   std::string name2 = "R<- "+tt;
   inspect_LogEntry(name2);
  }
  std::cout<<"}BeginTransmit_in_LinkLayerMrzs_"<<'\n';
#endif
}

LinkLayerConfig DefaultConfig_in_LinkLayerMrzs(LinkLayerMrzs *pLinkLayerMrzs)
{
  UNUSED(pLinkLayerMrzs);
//void LinkLayerConfig_in_LinkLayerConfig(LinkLayerConfig *pLinkLayerConfig, LinkConfig* config, boolean respondToAnySource);
//void  LinkConfig_in_LinkConfig(LinkConfig *pLinkConfig, boolean isMaster);
////    return LinkLayerConfig(LinkConfig(true), false);
  LinkConfig lLinkConfig;
  LinkConfig_in_LinkConfig(&lLinkConfig, true);
  LinkLayerConfig lLinkLayerConfig;
  LinkLayerConfig_in_LinkLayerConfig(&lLinkLayerConfig, &lLinkConfig, false);
  return lLinkLayerConfig;
}

void BeginTransmit_in_LinkLayerMrzs_override(void *pILinkTx, RSeq_for_Uint16_t* buffer, ILinkSession* context)
{
  LinkLayerMrzs* parent = (LinkLayerMrzs*) getParentPointer_in_ILinkTx((ILinkTx*) pILinkTx);
  BeginTransmit_in_LinkLayerMrzs(parent, buffer, context);
}

void  Reset_in_LinkLayerMrzs(LinkLayerMrzs *pLinkLayerMrzs)
{
  pLinkLayerMrzs->writeQueue_in_LinkLayerMrzs.clear();
  pLinkLayerMrzs->numTotalWrites = 0;
}
