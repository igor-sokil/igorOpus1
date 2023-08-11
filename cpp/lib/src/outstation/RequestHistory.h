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
#ifndef OPENDNP3_REQUESTHISTORY_H
#define OPENDNP3_REQUESTHISTORY_H

#include "APDUHeader.h"
#include "RSeq.h"

////#include <ser4cpp/container/SequenceTypes.h>

////#include <cstdint>

////namespace opendnp3
////{

/// Tracks the state of the last request ASDU
////class RequestHistory
typedef struct
{
////public:
////    RequestHistory();

////    bool HasLastRequest() const
////    {
////        return hasLast;
////    }

////    void Reset();
////    void RecordLastProcessedRequest(const APDUHeader& header, const ser4cpp::rseq_t& objects);

////    APDUHeader GetLastHeader() const;
////    bool EqualsLastObjects(const ser4cpp::rseq_t& objects) const;
////    bool FullyEqualsLastRequest(const APDUHeader& header, const ser4cpp::rseq_t& objects) const;

////private:
  boolean hasLast;
  APDUHeader lastHeader;
  uint16_t lastDigest;
  uint16_t lastObjectsLength;
} RequestHistory;

void RequestHistory_in_RequestHistory(RequestHistory *pRequestHistory);
boolean HasLastRequest_in_RequestHistory(RequestHistory *pRequestHistory);

void Reset_in_RequestHistory(RequestHistory *pRequestHistory);
void RecordLastProcessedRequest_in_RequestHistory(RequestHistory *pRequestHistory, APDUHeader* header, RSeq_for_Uint16_t* objects);

APDUHeader GetLastHeader_in_RequestHistory(RequestHistory *pRequestHistory);
boolean EqualsLastObjects_in_RequestHistory(RequestHistory *pRequestHistory, RSeq_for_Uint16_t* objects);
boolean FullyEqualsLastRequest_in_RequestHistory(RequestHistory *pRequestHistory, APDUHeader* header, RSeq_for_Uint16_t* objects);

////} // namespace opendnp3

#endif
