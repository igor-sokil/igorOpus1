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
//#include "OutstationContext.h"
#include "DeferredRequest.h"

////namespace opendnp3
////{

void DeferredRequest_in_DeferredRequest(DeferredRequest *pDeferredRequest, uint32_t maxAPDUSize)
{
//// : isSet(false), buffer(maxAPDUSize) {}
 pDeferredRequest->isSet = false;
 BufferSer4_in_BufferSer4Over2(&(pDeferredRequest->buffer), maxAPDUSize);
}

void Reset_in_DeferredRequest(DeferredRequest* pDeferredRequest)
{
   pDeferredRequest->isSet = false;
}

boolean IsSet_in_DeferredRequest(DeferredRequest* pDeferredRequest) 
{
    return pDeferredRequest->isSet;
}

FunctionCode_uint8_t GetFunction_in_DeferredRequest(DeferredRequest* pDeferredRequest)
{
    return pDeferredRequest->header.function;
}

void Set_in_DeferredRequest(DeferredRequest* pDeferredRequest, ParsedRequest* request)
{
    pDeferredRequest->isSet = true;

    pDeferredRequest->addresses = request->addresses;
    pDeferredRequest->header = request->header;

//    WSeq_for_Uint16_t as_wslice_in_BufferSer4(BufferSer4 *pBufferSer4);
////    auto dest = buffer.as_wslice();
    WSeq_for_Uint16_t dest = as_wslice_in_BufferSer4(&(pDeferredRequest->buffer));
//    RSeq_for_Uint16_t copy_from_in_WSeq_for_Uint16_t(WSeq_for_Uint16_t *pWSeq_for_Uint16_t, RSeq_for_Uint16_t *src);
////    this->objects = dest.copy_from(request.objects);
    pDeferredRequest->objects = copy_from_in_WSeq_for_Uint16_t(&dest, &(request->objects));
}


////} // namespace opendnp3
