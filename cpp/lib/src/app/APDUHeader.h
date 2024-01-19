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
#ifndef OPENDNP3_APDUHEADER_H
#define OPENDNP3_APDUHEADER_H

////#include "app/AppControlField.h"
#include "AppControlField.h"

////#include "opendnp3/app/IINField.h"
////#include "opendnp3/gen/FunctionCode.h"
////#include "opendnp3/master/ResponseInfo.h"
#include "IINField.h"
#include "FunctionCode.h"
#include "ResponseInfo.h"

////namespace opendnp3
////{

const uint32_t APDUHeader_REQUEST_SIZE = 2;
const uint32_t APDUHeader_RESPONSE_SIZE = 4;

//struct APDUHeader
typedef struct
{

////    static APDUHeader SolicitedConfirm(uint8_t seq);
////    static APDUHeader UnsolicitedConfirm(uint8_t seq);
////    static APDUHeader Confirm(uint8_t seq, bool unsolicited);

////    APDUHeader() = default;

////    APDUHeader(const AppControlField& control, FunctionCode function) : control(control), function(function) {}

////    bool Equals(const APDUHeader& header) const
////    {
////        return (header.function == function) && (header.control.ToByte() == control.ToByte());
////    }

  AppControlField control;
  FunctionCode_uint8_t function;//// = FunctionCode::UNKNOWN;
} APDUHeader;

APDUHeader SolicitedConfirm_in_APDUHeader(uint8_t seq);
APDUHeader UnsolicitedConfirm_in_APDUHeader(uint8_t seq);
APDUHeader Confirm_in_APDUHeader(uint8_t seq, boolean unsolicited);

void APDUHeader_in_APDUHeaderOver1(APDUHeader*);
void APDUHeader_in_APDUHeaderOver2(APDUHeader *pAPDUHeader, AppControlField *control, FunctionCode_uint8_t function);
boolean Equals_in_APDUHeader(APDUHeader *pAPDUHeader, APDUHeader *header);

////struct APDUResponseHeader : public APDUHeader
typedef struct
{
////    APDUResponseHeader() = default;

////    APDUResponseHeader(const AppControlField& control, FunctionCode function, const IINField& IIN)
////        : APDUHeader(control, function), IIN(IIN)
////    {
////    }

////    ResponseInfo as_response_info() const
////    {
////        return ResponseInfo(this->function == FunctionCode::UNSOLICITED_RESPONSE, control.FIR, control.FIN);
////    }
  APDUHeader aAPDUHeader;

  IINField IIN;
} APDUResponseHeader;

void APDUResponseHeader_in_APDUResponseHeaderOver1(APDUResponseHeader *pAPDUResponseHeader);
void APDUResponseHeader_in_APDUResponseHeaderOver2(APDUResponseHeader *pAPDUResponseHeader,
    AppControlField *control,
    FunctionCode_uint8_t function,
    IINField *pIIN);

ResponseInfo as_response_info_in_APDUResponseHeader(APDUResponseHeader *pAPDUResponseHeader);

////} // namespace opendnp3

#endif
