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
#ifndef OPENDNP3_UNITTESTS_MOCK_TRANSPORT_SEGMENT_H
#define OPENDNP3_UNITTESTS_MOCK_TRANSPORT_SEGMENT_H

#include "BufferHelpers.h"

#include "ITransportSegment.h"
#include "RSeq.h"

////#include <string>

////class MockTransportSegment final : public opendnp3::ITransportSegment
typedef struct
{
  ITransportSegment iITransportSegment;

////public:
////    MockTransportSegment(size_t segmentSize, const std::string& hex, const opendnp3::Addresses& addresses);

////    const opendnp3::Addresses& GetAddresses() const override
////    {
////        return this->addresses;
////    }

////    bool HasValue() const override;

////    ser4cpp::rseq_t GetSegment() override;

////    bool Advance() override;

////    void Reset();

////private:
  Addresses addresses;
  uint16_t segmentSize;
  HexSequence hs;
  RSeq_for_Uint16_t remainder;
} MockTransportSegment;

void MockTransportSegment_in_MockTransportSegment(MockTransportSegment *pMockTransportSegment, uint16_t segmentSize, std::string& hex, Addresses* addresses);

void Reset_in_MockTransportSegment(MockTransportSegment *pMockTransportSegment);

boolean HasValue_in_MockTransportSegment(MockTransportSegment *pMockTransportSegment);
RSeq_for_Uint16_t GetSegment_in_MockTransportSegment(MockTransportSegment *pMockTransportSegment);
boolean Advance_in_MockTransportSegment(MockTransportSegment *pMockTransportSegment);
Addresses* GetAddresses_in_MockTransportSegment(MockTransportSegment *pMockTransportSegment);

boolean HasValue_in_MockTransportSegment_override(void *pITransportSegment);
RSeq_for_Uint16_t GetSegment_in_MockTransportSegment_override(void *pITransportSegment);
boolean Advance_in_MockTransportSegment_override(void *pITransportSegment);
Addresses* GetAddresses_in_MockTransportSegment_override(void *pITransportSegment);




#endif
