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
  ParseResult_OK,                         //0
  ParseResult_NOT_ON_WHITELIST,           //1
  ParseResult_NOT_ENOUGH_DATA_FOR_HEADER, //2
  ParseResult_NOT_ENOUGH_DATA_FOR_RANGE,  //3
  ParseResult_NOT_ENOUGH_DATA_FOR_OBJECTS,//4
  ParseResult_UNREASONABLE_OBJECT_COUNT,  //5
  ParseResult_UNKNOWN_OBJECT,             //6
  ParseResult_UNKNOWN_QUALIFIER,          //7
  ParseResult_INVALID_OBJECT_QUALIFIER,   //8
  ParseResult_INVALID_OBJECT,             //9
  ParseResult_BAD_START_STOP,             //10
  ParseResult_COUNT_OF_ZERO               //11
};

boolean IsSuccess_in_ParseResult(ParseResult_uint8_t result);
boolean IsFailure_in_ParseResult(ParseResult_uint8_t result);


////} // namespace opendnp3

#endif
