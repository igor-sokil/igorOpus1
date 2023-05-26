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
#include "APDURequest.h"

////namespace opendnp3
////{

//void APDURequest_in_APDURequestOver2(APDURequest *pAPDURequest, uint32_t *aBuffer_uint32_t)
  void APDURequest_in_APDURequestOver2(APDURequest *pAPDURequest, WSeq_for_Uint16_t *aBuffer)
{
  APDUWrapper_in_APDUWrapperOver2(&(pAPDURequest -> aAPDUWrapper), aBuffer);
////  : APDUWrapper(aBuffer) {}
}

void ConfigureHeader_in_APDURequest(APDURequest *pAPDURequest, FunctionCode_uint8_t code, uint8_t seq)
{
    UNUSED(code);
    SetFunction_in_APDUWrapper(&(pAPDURequest->aAPDUWrapper), FunctionCode_AUTH_REQUEST);
    SetControl_in_APDUWrapper(&(pAPDURequest->aAPDUWrapper), Request_in_AppControlField_static(seq));
}

////} // namespace opendnp3
