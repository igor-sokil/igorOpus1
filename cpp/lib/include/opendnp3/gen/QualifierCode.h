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

#ifndef OPENDNP3_QUALIFIERCODE_H
#define OPENDNP3_QUALIFIERCODE_H

////#include <cstdint>
////#include <string>

////namespace opendnp3 {

/**
  Object header range/prefix as a single enumeration
*/
//enum class QualifierCode : uint8_t
#define QualifierCode_uint8_t uint8_t
enum QualifierCode 
{
  QualifierCode_UINT8_START_STOP = 0x0,
  QualifierCode_UINT16_START_STOP = 0x1,
  QualifierCode_ALL_OBJECTS = 0x6,
  QualifierCode_UINT8_CNT = 0x7,
  QualifierCode_UINT16_CNT = 0x8,
  QualifierCode_UINT8_CNT_UINT8_INDEX = 0x17,
  QualifierCode_UINT16_CNT_UINT16_INDEX = 0x28,
  QualifierCode_UNDEFINED = 0xFF
};

////struct QualifierCodeSpec
////{
////  using enum_type_t = QualifierCode;

////  static uint8_t to_type(QualifierCode arg);
////  static QualifierCode from_type(uint8_t arg);
////  static char const* to_string(QualifierCode arg);
////  static char const* to_human_string(QualifierCode arg);
////  static QualifierCode from_string(const std::string& arg);
////};

////}

#endif
