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
  MockUpperLayer_in_MockUpperLayer(&(pTransportTestObject->upper));

  TransportLayer_in_TransportLayer(&(pTransportTestObject->transport), maxRxFragmentSize);

//void SetUpperLayer_in_HasUpperLayer(HasUpperLayer *pHasUpperLayer, IUpperLayer* upperLayer);
////    link.SetUpperLayer(transport);
  SetUpperLayer_in_HasUpperLayer(&(pTransportTestObject->link.hHasUpperLayer), &(pTransportTestObject->transport.iIUpperLayer));

//void SetLinkLayer_in_TransportLayer(TransportLayer *pTransportLayer, ILinkLayer* linkLayer);
////    transport.SetLinkLayer(link);
  SetLinkLayer_in_TransportLayer(&(pTransportTestObject->transport), &(pTransportTestObject->link.iILinkLayer));

//void SetLowerLayer_in_HasLowerLayer(HasLowerLayer *pHasLowerLayer, ILowerLayer* lowerLayer);
////    upper.SetLowerLayer(transport);
  SetLowerLayer_in_HasLowerLayer(&(pTransportTestObject->upper.hHasLowerLayer), &(pTransportTestObject->transport.iILowerLayer));

//void SetAppLayer_in_TransportLayer(TransportLayer *pTransportLayer, IUpperLayer* upperLayer);
////    transport.SetAppLayer(upper);
  SetAppLayer_in_TransportLayer(&(pTransportTestObject->transport), &(pTransportTestObject->upper.iIUpperLayer));

  if (openOnStart)
  {
//boolean OnLowerLayerUp_in_TransportLayer(TransportLayer *pTransportLayer);
////        transport.OnLowerLayerUp();
    OnLowerLayerUp_in_TransportLayer(&(pTransportTestObject->transport));
  }
}

////std::string TransportTestObject::GetData(const std::string& arHdr, uint8_t aSeed, uint32_t aLength)
std::string GetData_in_TransportTestObject(TransportTestObject *pTransportTestObject, std::string& arHdr, uint8_t aSeed,/* = 0,*/ uint32_t aLength)// = opendnp3::MAX_TPDU_PAYLOAD);
{
  UNUSED(pTransportTestObject);
//void ByteStr_in_ByteStrOver1(ByteStr *pByteStr, uint16_t length, uint8_t seed);// = 0);
////    ByteStr buff(aLength);
  ByteStr buff;
  ByteStr_in_ByteStrOver1(&buff, aLength, 0);

  uint8_t val = aSeed;
  for (uint16_t i = 0; i < aLength; ++i)
  {
///        buff[i] = val;
    buff.cCopyableBuffer.buffer[i] = val;
    ++val;
  }

  std::ostringstream oss;
  if (!arHdr.empty())
    oss << arHdr << " ";

//uint16_t Size_in_CopyableBuffer(CopyableBuffer *pCopyableBuffer);
//std::string to_hex_in_HexConversions(const uint8_t* buffer, size_t length, bool spaced = false);
////    oss << HexConversions::to_hex(buff, buff.Size(), true);
  oss << to_hex_in_HexConversions(buff.cCopyableBuffer.buffer, Size_in_CopyableBuffer(&(buff.cCopyableBuffer)), true);
  return oss.str();
}

///std::string TransportTestObject::GeneratePacketSequence(std::vector<std::string>& arVec,
///                                                        uint32_t aNumPackets,
///                                                        uint32_t aLastPacketLength)
std::string GeneratePacketSequence_in_TransportTestObject(TransportTestObject *pTransportTestObject, std::vector<std::string>&arVec, uint32_t aNumPackets, uint32_t aLastPacketLength)
{
  std::ostringstream oss;
  for (size_t i = 0; i < aNumPackets; ++i)
  {
    boolean fir = i == 0;
    boolean fin = i == (aNumPackets - 1);
    int seq = (int)(i % 64);

    uint32_t len = fin ? aLastPacketLength : MAX_TPDU_PAYLOAD;

//uint8_t ToByte_in_TransportHeader_static(boolean fir, boolean fin, uint8_t seq);
////        uint8_t hdr = TransportHeader::ToByte(fir, fin, seq);
    uint8_t hdr = ToByte_in_TransportHeader_static(fir, fin, seq);

// std::string GetData_in_TransportTestObject(TransportTestObject *pTransportTestObject, std::string& arHdr, uint8_t aSeed,/* = 0,*/ uint32_t aLength);// = opendnp3::MAX_TPDU_PAYLOAD);
////        std::string data = this->GetData("", 0, len); // raw data with no header
    std::string strtmp = "";
    std::string data = GetData_in_TransportTestObject(pTransportTestObject, strtmp, 0, len);

////        oss << ((i == 0) ? "" : " ") << data;         // cache the data in the string stream
    oss << ((i == 0) ? "" : " ") << data;         // cache the data in the string stream

//std::string to_hex_in_HexConversions(const uint8_t* buffer, size_t length, bool spaced = false);
////        arVec.push_back(HexConversions::to_hex(&hdr, 1, true) + " " + data);
    arVec.push_back(to_hex_in_HexConversions(&hdr, 1, true) + " " + data);
  }

  return oss.str();
}
