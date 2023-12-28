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
#include <iostream>
//#endif
#include <QApplication>
#include "header.h"
#include "TransportTestObject.h"

#include "TransportHeader.h"
#include "BufferHelpers.h"

#include "AppConstants.h"

#include "HexConversions.h"

//#include <memory>
//#include <sstream>

////using namespace opendnp3;
////using namespace ser4cpp;

////TransportTestObject::TransportTestObject(bool openOnStart, uint32_t maxRxFragmentSize)
////    : transport(log.logger, maxRxFragmentSize)
 void TransportTestObject_in_TransportTestObject(TransportTestObject *pTransportTestObject, boolean openOnStart,/* = false,*/ uint32_t maxRxFragmentSize)// = opendnp3::DEFAULT_MAX_APDU_SIZE);
{
 MockExecutor_in_MockExecutor(&(pTransportTestObject->exe));
 MockLinkLayer_in_MockLinkLayer(&(pTransportTestObject->link));

    TransportLayer_in_TransportLayer(&(pTransportTestObject->transport), maxRxFragmentSize);

//void SetUpperLayer_in_HasUpperLayer(HasUpperLayer *pHasUpperLayer, IUpperLayer* upperLayer);
////    link.SetUpperLayer(transport);
 SetUpperLayer_in_HasUpperLayer(&(pTransportTestObject->link.hHasUpperLayer), &(transport.iIUpperLayer));

////    transport.SetLinkLayer(link);

    upper.SetLowerLayer(transport);
    transport.SetAppLayer(upper);

    if (openOnStart)
    {
        transport.OnLowerLayerUp();
    }
}

std::string TransportTestObject::GetData(const std::string& arHdr, uint8_t aSeed, uint32_t aLength)
{
    ByteStr buff(aLength);
    uint8_t val = aSeed;
    for (size_t i = 0; i < aLength; ++i)
    {
        buff[i] = val;
        ++val;
    }

    std::ostringstream oss;
    if (!arHdr.empty())
        oss << arHdr << " ";
    oss << HexConversions::to_hex(buff, buff.Size(), true);
    return oss.str();
}

std::string TransportTestObject::GeneratePacketSequence(std::vector<std::string>& arVec,
                                                        uint32_t aNumPackets,
                                                        uint32_t aLastPacketLength)
{
    std::ostringstream oss;
    for (size_t i = 0; i < aNumPackets; ++i)
    {
        bool fir = i == 0;
        bool fin = i == (aNumPackets - 1);
        int seq = static_cast<int>(i % 64);
        uint32_t len = fin ? aLastPacketLength : MAX_TPDU_PAYLOAD;
        uint8_t hdr = TransportHeader::ToByte(fir, fin, seq);
        std::string data = this->GetData("", 0, len); // raw data with no header
        oss << ((i == 0) ? "" : " ") << data;         // cache the data in the string stream
        arVec.push_back(HexConversions::to_hex(&hdr, 1, true) + " " + data);
    }

    return oss.str();
}
