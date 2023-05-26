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
#ifndef OPENDNP3_PARSERESULT_H
#define OPENDNP3_PARSERESULT_H

////#include <cstdint>

////namespace opendnp3
////{
#define ParseResult_uint8_t uint8_t
////enum class ParseResult : uint8_t
enum ParseResult 
{
    ParseResult_OK,
    ParseResult_NOT_ON_WHITELIST,
    ParseResult_NOT_ENOUGH_DATA_FOR_HEADER,
    ParseResult_NOT_ENOUGH_DATA_FOR_RANGE,
    ParseResult_NOT_ENOUGH_DATA_FOR_OBJECTS,
    ParseResult_UNREASONABLE_OBJECT_COUNT,
    ParseResult_UNKNOWN_OBJECT,
    ParseResult_UNKNOWN_QUALIFIER,
    ParseResult_INVALID_OBJECT_QUALIFIER,
    ParseResult_INVALID_OBJECT,
    ParseResult_BAD_START_STOP,
    ParseResult_COUNT_OF_ZERO
};

boolean IsSuccess_in_ParseResult(ParseResult_uint8_t result);
boolean IsFailure_in_ParseResult(ParseResult_uint8_t result);


////} // namespace opendnp3

#endif
