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
#ifndef OPENDNP3_APDUBUILDERS_H
#define OPENDNP3_APDUBUILDERS_H

#include "APDURequest.h"
#include "APDUResponse.h"

#include "ClassField.h"

////namespace opendnp3
////{
////namespace build
////{
// -------- requests -------------

void ClassRequest_in_APDUBuilders_static(APDURequest* request, FunctionCode_uint8_t fc, ClassField* classes, uint8_t seq);

boolean WriteClassHeaders_in_APDUBuilders_static(HeaderWriter* writer, ClassField* classes);

void ReadIntegrity_in_APDUBuilders_static(APDURequest* request, ClassField* classes, uint8_t seq);// = 0);

void ReadAllObjects_in_APDUBuilders_static(APDURequest& request, GroupVariationID gvId, uint8_t seq);// = 0);

void DisableUnsolicited_in_APDUBuilders_static(APDURequest* request, uint8_t seq);// = 0);

void EnableUnsolicited_in_APDUBuilders_static(APDURequest* request, ClassField* classes, uint8_t seq);// = 0);

void ClearRestartIIN_in_APDUBuilders_static(APDURequest* request, uint8_t seq);// = 0);

void MeasureDelay_in_APDUBuilders_static(APDURequest* request, uint8_t seq);// = 0);

void RecordCurrentTime_in_APDUBuilders_static(APDURequest* request, uint8_t seq);// = 0);

// -------- responses -------------

void NullUnsolicited_in_APDUBuilders_static(APDUResponse* response, uint8_t seq, IINField* iin);

////} // namespace build
////} // namespace opendnp3

#endif
