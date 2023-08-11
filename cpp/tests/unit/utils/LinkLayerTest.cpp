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
//#include <QtWidgets>
#include <QApplication>
#include "header.h"
#include "LinkLayerTest.h"
#include "HexConversions.h"
////#include <ser4cpp/util/HexConversions.h>

////using namespace opendnp3;
////using namespace ser4cpp;
////LinkLayerTest::LinkLayerTest(const LinkConfig& config) : LinkLayerTest(LinkLayerConfig(config, false)) {}

////LinkLayerTest::LinkLayerTest(const LinkLayerConfig& config)
////    : exe(std::make_shared<exe4cpp::MockExecutor>()),
////      listener(std::make_shared<MockLinkListener>()),
////      upper(std::make_shared<MockTransportLayer>()),
////      link(log.logger, exe, upper, listener, config),
////      numTotalWrites(0)
////{
////    upper->SetLinkLayer(link);
////    link.SetRouter(*this);
////}

  void  LinkLayerTest_in_LinkLayerTest(LinkLayerTest *pLinkLayerTest, LinkLayerConfig* config)
{
UNUSED(config);
 MockExecutor_in_MockExecutor(&(pLinkLayerTest->exe));
 MockLinkListener_in_MockLinkListener(&(pLinkLayerTest->listener));
 MockTransportLayer_in_MockTransportLayer(&(pLinkLayerTest->upper));

 pLinkLayerTest->numTotalWrites = 0;

//   void LinkLayer_in_LinkLayer(LinkLayer *pLinkLayer, ////const Logger& logger,
//              IExecutorExe4cpp*,
//              IUpperLayer* upper,
//              ILinkListener*,
//              LinkLayerConfig*);

 LinkLayer_in_LinkLayer(&(pLinkLayerTest->link), ////const Logger& logger,
              &(pLinkLayerTest->exe.iIExecutorExe4cpp),
              &(pLinkLayerTest->upper.iIUpperLayer),
              &(pLinkLayerTest->listener.iILinkListener),
              config);

////    upper->SetLinkLayer(link);
  SetLinkLayer_in_MockTransportLayer(&(pLinkLayerTest->upper), &(pLinkLayerTest->link.iILinkLayer));//ILinkLayer* linkLayer);

//  void SetRouter_in_LinkLayer(LinkLayer *pLinkLayer, ILinkTx*);
////    link.SetRouter(*this);
  SetRouter_in_LinkLayer(&(pLinkLayerTest->link), &(pLinkLayerTest->iILinkTx));

  pLinkLayerTest->iILinkTx.pBeginTransmit_in_ILinkTx = BeginTransmit_in_LinkLayerTest_override;
  setParentPointer_in_ILinkTx(&(pLinkLayerTest->iILinkTx), pLinkLayerTest);
}

boolean OnFrame_in_LinkLayerTest(LinkLayerTest *pLinkLayerTest,
                            LinkFunction_uint8_t func,
                            boolean isMaster,
                            boolean fcb,
                            boolean fcvdfc,
                            uint16_t dest,
                            uint16_t source,
                            RSeq_for_Uint16_t* userdata)
{
//  void LinkHeaderFields_in_LinkHeaderFieldsOver2(LinkHeaderFields *pLinkHeaderFields, LinkFunction_uint8_t func, boolean isMaster, boolean fcb, boolean fcvdfc, Addresses addresses);
////    LinkHeaderFields fields(func, isMaster, fcb, fcvdfc, Addresses(source, dest));
   Addresses aAddresses;
   Addresses_in_AddressesOver2(&aAddresses, source, dest);
   LinkHeaderFields fields;
   LinkHeaderFields_in_LinkHeaderFieldsOver2(&fields, func, isMaster, fcb, fcvdfc, aAddresses);

//   boolean OnFrame_in_LinkLayer(LinkLayer *pLinkLayer, LinkHeaderFields* header, RSeq_for_Uint16_t* userdata);
////    return link.OnFrame(fields, userdata);
   return OnFrame_in_LinkLayer(&(pLinkLayerTest->link), &fields, userdata);
}

////std::string LinkLayerTest::PopLastWriteAsHex()
    std::string PopLastWriteAsHex_in_LinkLayerTest(LinkLayerTest *pLinkLayerTest)
{
    if (pLinkLayerTest->writeQueue.empty())
    {
        return "";
    }

    while (pLinkLayerTest->writeQueue.size() > 1)
    {
        pLinkLayerTest->writeQueue.pop_front();
    }

    std::string ret = pLinkLayerTest->writeQueue.front();
    pLinkLayerTest->writeQueue.pop_front();
    return ret;
}

uint32_t NumTotalWrites_in_LinkLayerTest(LinkLayerTest *pLinkLayerTest)
{
    return pLinkLayerTest->numTotalWrites;
}

void BeginTransmit_in_LinkLayerTest(LinkLayerTest *pLinkLayerTest, RSeq_for_Uint16_t* buffer, ILinkSession* context)
{
UNUSED(context);
    ++(pLinkLayerTest->numTotalWrites);
    pLinkLayerTest->writeQueue.push_back(to_hex_in_HexConversionsOver2(buffer));
}

LinkLayerConfig DefaultConfig_in_LinkLayerTest(LinkLayerTest *pLinkLayerTest)
{
UNUSED(pLinkLayerTest);
//void LinkLayerConfig_in_LinkLayerConfig(LinkLayerConfig *pLinkLayerConfig, LinkConfig* config, boolean respondToAnySource);
//void  LinkConfig_in_LinkConfig(LinkConfig *pLinkConfig, boolean isMaster);
////    return LinkLayerConfig(LinkConfig(true), false);
  LinkConfig lLinkConfig;
  LinkConfig_in_LinkConfig(&lLinkConfig, true);
  LinkLayerConfig lLinkLayerConfig;
  LinkLayerConfig_in_LinkLayerConfig(&lLinkLayerConfig, &lLinkConfig, false);
 return lLinkLayerConfig;
}

   void BeginTransmit_in_LinkLayerTest_override(void *pILinkTx, RSeq_for_Uint16_t* buffer, ILinkSession* context)
{
  LinkLayerTest* parent = (LinkLayerTest*) getParentPointer_in_ILinkTx((ILinkTx*) pILinkTx);
  BeginTransmit_in_LinkLayerTest(parent, buffer, context);
}

