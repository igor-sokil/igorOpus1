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
#include "MockTransportSegment.h"

////#include <ser4cpp/util/HexConversions.h>

////#include <algorithm>
/////#include <cassert>
////#include <exception>
////#include <memory>
////#include <sstream>

////using namespace std;
////using namespace opendnp3;
////using namespace ser4cpp;

////MockTransportSegment::MockTransportSegment(size_t segmentSize, const std::string& hex, const Addresses& addresses)
////    : addresses(addresses), segmentSize(segmentSize), hs(hex), remainder(hs.ToRSeq())
void MockTransportSegment_in_MockTransportSegment(MockTransportSegment *pMockTransportSegment, uint16_t segmentSize, std::string& hex, Addresses* addresses)
{
  pMockTransportSegment->addresses = *addresses;
  pMockTransportSegment->segmentSize = segmentSize;
//  pMockTransportSegment->hs = hex;

  HexSequence_in_HexSequence(&(pMockTransportSegment->hs), hex);

//RSeq_for_Uint16_t ToRSeq_in_CopyableBuffer(CopyableBuffer *pCopyableBuffer);
//// remainder(hs.ToRSeq())
  pMockTransportSegment->remainder = ToRSeq_in_CopyableBuffer(&(pMockTransportSegment->hs.bByteStr.cCopyableBuffer));

  pMockTransportSegment->iITransportSegment.pHasValue_in_ITransportSegment =  HasValue_in_MockTransportSegment_override;
  pMockTransportSegment->iITransportSegment.pGetSegment_in_ITransportSegment = GetSegment_in_MockTransportSegment_override;
  pMockTransportSegment->iITransportSegment.pAdvance_in_ITransportSegment = Advance_in_MockTransportSegment_override;
  pMockTransportSegment->iITransportSegment.pGetAddresses_in_ITransportSegment = GetAddresses_in_MockTransportSegment_override;

  setParentPointer_in_ITransportSegment(&(pMockTransportSegment->iITransportSegment), pMockTransportSegment);
////    assert(segmentSize > 0);
}

void Reset_in_MockTransportSegment(MockTransportSegment *pMockTransportSegment)
{
////    remainder = hs.ToRSeq();
  pMockTransportSegment->remainder = ToRSeq_in_CopyableBuffer(&(pMockTransportSegment->hs.bByteStr.cCopyableBuffer));
}

boolean HasValue_in_MockTransportSegment(MockTransportSegment *pMockTransportSegment)
{
////    return remainder.length() > 0;
  return length_in_HasLength_for_Uint16_t(&(pMockTransportSegment->remainder.hHasLength)) > 0;
}

RSeq_for_Uint16_t GetSegment_in_MockTransportSegment(MockTransportSegment *pMockTransportSegment)
{
  auto size = std::min(pMockTransportSegment->segmentSize, length_in_HasLength_for_Uint16_t(&(pMockTransportSegment->remainder.hHasLength)));////remainder.length());

//    RSeq_for_Uint16_t take_in_RSeq_for_Uint16_t(RSeq_for_Uint16_t *pRSeq, uint16_t count);
////    auto chunk = remainder.take(size);
  RSeq_for_Uint16_t chunk = take_in_RSeq_for_Uint16_t(&(pMockTransportSegment->remainder), size);
  return chunk;
}

boolean Advance_in_MockTransportSegment(MockTransportSegment *pMockTransportSegment)
{
  auto size = std::min(pMockTransportSegment->segmentSize, length_in_HasLength_for_Uint16_t(&(pMockTransportSegment->remainder.hHasLength)));////remainder.length());

//    void advance_in_RSeq_for_Uint16_t(RSeq_for_Uint16_t *pRSeq, uint16_t count);
////    remainder.advance(size);
  advance_in_RSeq_for_Uint16_t(&(pMockTransportSegment->remainder), size);
//    boolean is_not_empty_in_HasLength_for_Uint16_t(HasLength_for_Uint16_t *pHasLength);
////    return remainder.is_not_empty();
  return is_not_empty_in_HasLength_for_Uint16_t(&(pMockTransportSegment->remainder.hHasLength));
}

Addresses* GetAddresses_in_MockTransportSegment(MockTransportSegment *pMockTransportSegment)
{
  return &(pMockTransportSegment->addresses);
}

boolean HasValue_in_MockTransportSegment_override(void *pITransportSegment)
{
  MockTransportSegment* parent = (MockTransportSegment*)getParentPointer_in_ITransportSegment((ITransportSegment *)pITransportSegment);
  return HasValue_in_MockTransportSegment(parent);
}
RSeq_for_Uint16_t GetSegment_in_MockTransportSegment_override(void *pITransportSegment)
{
  MockTransportSegment* parent = (MockTransportSegment*)getParentPointer_in_ITransportSegment((ITransportSegment *)pITransportSegment);
  return GetSegment_in_MockTransportSegment(parent);
}
boolean Advance_in_MockTransportSegment_override(void *pITransportSegment)
{
  MockTransportSegment* parent = (MockTransportSegment*)getParentPointer_in_ITransportSegment((ITransportSegment *)pITransportSegment);
  return Advance_in_MockTransportSegment(parent);
}
Addresses* GetAddresses_in_MockTransportSegment_override(void *pITransportSegment)
{
  MockTransportSegment* parent = (MockTransportSegment*)getParentPointer_in_ITransportSegment((ITransportSegment *)pITransportSegment);
  return GetAddresses_in_MockTransportSegment(parent);
}
