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
#ifndef OPENDNP3_DEFERREDREQUEST_H
#define OPENDNP3_DEFERREDREQUEST_H

#include "ParsedRequest.h"

////#include "opendnp3/util/Uncopyable.h"

#include "BufferSer4.h"

////namespace opendnp3
////{

/**
 * Records metadata about deferred requests
 */
////class DeferredRequest : private Uncopyable
typedef struct
{

////public:
////    explicit DeferredRequest(uint32_t maxAPDUSize);

////    void Reset();

////    bool IsSet() const;

////    FunctionCode GetFunction() const;

////    void Set(const ParsedRequest& request);

////    template<class Handler> bool Process(const Handler& handler);

////private:
////    DeferredRequest() = delete;

    boolean isSet;
    Addresses addresses;
    APDUHeader header;
    RSeq_for_Uint16_t objects;
    BufferSer4 buffer;
} DeferredRequest;

  void DeferredRequest_in_DeferredRequest(DeferredRequest *pDeferredRequest, uint32_t maxAPDUSize);

  void Reset_in_DeferredRequest(DeferredRequest *pDeferredRequest);

  boolean IsSet_in_DeferredRequest(DeferredRequest *pDeferredRequest);

  FunctionCode_uint8_t GetFunction_in_DeferredRequest(DeferredRequest *pDeferredRequest);

  void Set_in_DeferredRequest(DeferredRequest *pDeferredRequest, ParsedRequest* request);

  boolean  Process_for_handlerBooleanParsedRequest_in_DeferredRequest(DeferredRequest *pDeferredRequest, void*, boolean (*pHandlerBooleanParsedRequest)(ParsedRequest*));
////template<class Handler> bool DeferredRequest::Process(const Handler& handler)

////template<class Handler> bool DeferredRequest::Process(const Handler& handler)
////{
////    if (isSet)
////    {
////        bool processed = handler(ParsedRequest(this->addresses, this->header, this->objects));
////        isSet = !processed;
////        return processed;
////    }
////    else
////    {
////        return false;
////    }
////}

////} // namespace opendnp3

#endif
