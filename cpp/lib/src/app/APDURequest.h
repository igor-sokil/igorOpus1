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
#ifndef OPENDNP3_APDUREQUEST_H
#define OPENDNP3_APDUREQUEST_H

#include "APDUWrapper.h"
#include "HeaderWriter.h"

////namespace opendnp3
////{

// this is what the application layer sees from the master / outstation for transmission
////class APDURequest : public APDUWrapper
typedef struct
{
  APDUWrapper aAPDUWrapper;
////public:
////    explicit APDURequest(const ser4cpp::wseq_t& buffer);

////    void ConfigureHeader(FunctionCode code, uint8_t seq);

////    static APDUEquality Compare(const ser4cpp::rseq_t& lhs, const ser4cpp::rseq_t& rhs);

////private:
////    APDURequest();
} APDURequest;

void APDURequest_in_APDURequestOver1(APDURequest *pAPDURequest);
void APDURequest_in_APDURequestOver2(APDURequest *pAPDURequest, WSeq_for_Uint16_t *buffer);
//  void ConfigureHeader_in_APDURequest(FunctionCode_uint8_t code, uint8_t seq);
void ConfigureHeader_in_APDURequest(APDURequest *pAPDURequest, FunctionCode_uint8_t code, uint8_t seq);
APDUEquality_uint8_t Compare_in_APDURequest_static(RSeq_for_Uint16_t *lhs, RSeq_for_Uint16_t *rhs);

////} // namespace opendnp3

#endif
