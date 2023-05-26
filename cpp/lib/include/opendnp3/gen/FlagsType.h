//
//  _   _         ______    _ _ _   _             _ _ _
// | \ | |       |  ____|  | (_) | (_)           | | | |
// |  \| | ___   | |__   __| |_| |_ _ _ __   __ _| | | |
// | . ` |/ _ \  |  __| / _` | | __| | '_ \ / _` | | | |
// | |\  | (_) | | |___| (_| | | |_| | | | | (_| |_|_|_|
// |_| \_|\___/  |______\__,_|_|\__|_|_| |_|\__, (_|_|_)
//                                           __/ |
//                                          |___/
// 
// This file is auto-generated. Do not edit manually
// 
// Copyright 2013-2022 Step Function I/O, LLC
// 
// Licensed to Green Energy Corp (www.greenenergycorp.com) and Step Function I/O
// LLC (https://stepfunc.io) under one or more contributor license agreements.
// See the NOTICE file distributed with this work for additional information
// regarding copyright ownership. Green Energy Corp and Step Function I/O LLC license
// this file to you under the Apache License, Version 2.0 (the "License"); you
// may not use this file except in compliance with the License. You may obtain
// a copy of the License at:
// 
//   http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#ifndef OPENDNP3_FLAGSTYPE_H
#define OPENDNP3_FLAGSTYPE_H

////#include <cstdint>
////#include <string>

////namespace opendnp3 {

/**
  enumerates all types that have flags
*/
//enum class FlagsType : uint8_t
#define  FlagsType_uint8_t uint8_t
enum FlagsType
{
  FlagsType_DoubleBinaryInput = 0x1,
  FlagsType_Counter = 0x2,
  FlagsType_FrozenCounter = 0x3,
  FlagsType_AnalogInput = 0x4,
  FlagsType_BinaryOutputStatus = 0x5,
  FlagsType_AnalogOutputStatus = 0x6,
  FlagsType_BinaryInput = 0x0
};

////struct FlagsTypeSpec
////{
////  using enum_type_t = FlagsType;

////  static uint8_t to_type(FlagsType arg);
////  static FlagsType from_type(uint8_t arg);
////  static char const* to_string(FlagsType arg);
////  static char const* to_human_string(FlagsType arg);
////  static FlagsType from_string(const std::string& arg);
////};

////}

#endif
