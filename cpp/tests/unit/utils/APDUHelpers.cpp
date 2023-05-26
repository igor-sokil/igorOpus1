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
////#include "utils/APDUHelpers.h"
#include "header.h"
#include "APDUHelpers.h"

////uint8_t APDUHelpers::fixedBuffer[SIZE];
    static uint8_t fixedBuffer_in_APDUHelpers[SIZE_in_APDUHelpers];
/*
    APDURequest  Request_in_APDUHelpers_static(FunctionCode_uint8_t code, uint32_t size);// = SIZE);

    APDUResponse Response_in_APDUHelpers_static(uint32_t size);// = SIZE);
*/
APDURequest Request_in_APDUHelpers_static(FunctionCode_uint8_t code, uint32_t size)
{
////    assert(size <= SIZE);
////    ser4cpp::wseq_t buffer(fixedBuffer, size);
    WSeq_for_Uint16_t buffer;
    WSeq_for_Uint16_t_in_WSeq_for_Uint16_tOver2(&buffer, fixedBuffer_in_APDUHelpers, size);
////    opendnp3::APDURequest request(buffer);
    APDURequest request;
    APDURequest_in_APDURequestOver2(&request, &buffer);

////    request.SetFunction(code);
    SetFunction_in_APDUWrapper(&request.aAPDUWrapper, code);

////    request.SetControl(opendnp3::AppControlField(true, true, false, false, 0));
    AppControlField aAppControlField;
    AppControlField_in_AppControlFieldOver4(&aAppControlField, true, true, false, false, 0);
    SetControl_in_APDUWrapper(&request.aAPDUWrapper, aAppControlField);

    return request;
}

APDUResponse Response_in_APDUHelpers_static(uint32_t size)
{
////    assert(size <= SIZE);
////    ser4cpp::wseq_t buffer(fixedBuffer, size);
    WSeq_for_Uint16_t buffer;
    WSeq_for_Uint16_t_in_WSeq_for_Uint16_tOver2(&buffer, fixedBuffer_in_APDUHelpers, size);

////    opendnp3::APDUResponse response(buffer);
    APDUResponse response;
    APDUResponse_in_APDUResponse(&response, &buffer);

////    response.SetFunction(opendnp3::FunctionCode::RESPONSE);
    SetFunction_in_APDUWrapper(&response.aAPDUWrapper, FunctionCode_RESPONSE);

////    response.SetControl(opendnp3::AppControlField(true, true, false, false, 0));
    AppControlField aAppControlField;
    AppControlField_in_AppControlFieldOver4(&aAppControlField, true, true, false, false, 0);
    SetControl_in_APDUWrapper(&response.aAPDUWrapper, aAppControlField);

////    response.SetIIN(opendnp3::IINField::Empty());
    IINField iIINField = Empty_in_IINField_static();
    SetIIN_in_APDUResponse(&response, &iIINField);

    return response;
}
