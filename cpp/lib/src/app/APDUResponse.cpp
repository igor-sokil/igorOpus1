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
#include "header.h"
#include "APDUResponse.h"

////#include <cassert>

////namespace opendnp3
////{

////void APDUResponse_in_APDUResponse(const ser4cpp::wseq_t& buffer) : APDUWrapper(buffer)
void APDUResponse_in_APDUResponse(APDUResponse *pAPDUResponse, WSeq_for_Uint16_t *buffer)
{
  APDUWrapper_in_APDUWrapperOver2(&(pAPDUResponse -> aAPDUWrapper), buffer);

////    : APDUWrapper(buffer)
////    assert(buffer.length() >= 4);
////    remaining.advance(2);
    advance_in_WSeq_for_Uint16_t(&(pAPDUResponse->aAPDUWrapper.remaining), 2);
}

void SetIIN_in_APDUResponse(APDUResponse *pAPDUResponse, IINField *indications)
{
    (pAPDUResponse -> aAPDUWrapper).buffer.buffer_[2] = indications->LSB;
    (pAPDUResponse -> aAPDUWrapper).buffer.buffer_[3] = indications->MSB;
}

IINField GetIIN_in_APDUResponse(APDUResponse *pAPDUResponse) 
{
    IINField iIINField;
    IINField_in_IINFieldOver3(&iIINField, (pAPDUResponse -> aAPDUWrapper).buffer.buffer_[2], (pAPDUResponse -> aAPDUWrapper).buffer.buffer_[3]);
    return iIINField;
}

////} // namespace opendnp3
