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
#ifndef OPENDNP3_UNITTESTS_APDU_HEX_BUILDERS_H
#define OPENDNP3_UNITTESTS_APDU_HEX_BUILDERS_H

#include "ClassField.h"
#include "ControlRelayOutputBlock.h"
#include "DNPTime.h"
#include "IINField.h"
#include "FunctionCode.h"
#include "PointClass.h"

////#include <cstdint>
////#include <string>

////namespace hex
////{
// ----------- simple helpers --------

std::string repeat_in_APDUHexBuilders(uint8_t value, uint16_t count);

// ----------- requests --------------

std::string IntegrityPoll_in_APDUHexBuilders(uint8_t seq, ClassField* field);// = opendnp3::ClassField::AllClasses());

std::string ClassTask_in_APDUHexBuilders(FunctionCode_uint8_t fc,
    uint8_t seq,
    ClassField* field);// = opendnp3::ClassField::AllClasses());

std::string DisableUnsol_in_APDUHexBuilders(uint8_t seq, ClassField* field);// = opendnp3::ClassField::AllEventClasses());

std::string ClassPoll_in_APDUHexBuilders(uint8_t seq, PointClass_uint8_t pc);

std::string EventPoll_in_APDUHexBuilders(uint8_t seq, ClassField* field);// = opendnp3::ClassField::AllEventClasses());

std::string ClearRestartIIN_in_APDUHexBuilders(uint8_t seq);

std::string MeasureDelay_in_APDUHexBuilders(uint8_t seq);

std::string RecordCurrentTime_in_APDUHexBuilders(uint8_t seq);

std::string Control_in_APDUHexBuilders(FunctionCode_uint8_t code,
                                       uint8_t seq,
                                       ControlRelayOutputBlock* crob,
                                       uint16_t index);

// ----------- responses --------------

std::string EmptyResponse_in_APDUHexBuilders(uint8_t seq, IINField* iin);// = opendnp3::IINField::Empty());

std::string NullUnsolicited_in_APDUHexBuilders(uint8_t seq,
    IINField* iin);// = opendnp3::IINField(opendnp3::IINBit::DEVICE_RESTART));

// ----------- confirms --------------

std::string SolicitedConfirm_in_APDUHexBuilders(uint8_t seq);

std::string UnsolConfirm_in_APDUHexBuilders(uint8_t seq);

std::string Confirm_in_APDUHexBuilders(uint8_t seq, boolean unsol);

////} // namespace hex

#endif
