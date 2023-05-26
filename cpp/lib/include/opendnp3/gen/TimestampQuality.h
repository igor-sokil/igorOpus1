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

#ifndef OPENDNP3_TIMESTAMPQUALITY_H
#define OPENDNP3_TIMESTAMPQUALITY_H

////#include <cstdint>
////#include <string>

////namespace opendnp3 {

/**
  Indicates the quality of timestamp values
*/
////enum class TimestampQuality : uint8_t
#define TimestampQuality_uint8_t   uint8_t
enum TimestampQuality 
{
  /// The timestamp is UTC synchronized at the remote device
  TimestampQuality_SYNCHRONIZED = 1,
  /// The device indicate the timestamp may be unsynchronized
  TimestampQuality_UNSYNCHRONIZED = 2,
  /// Timestamp is not valid, ignore the value and use a local timestamp
  TimestampQuality_INVALID = 0
};

////struct TimestampQualitySpec
////{
////  using enum_type_t = TimestampQuality;

////  static uint8_t to_type(TimestampQuality arg);
////  static TimestampQuality from_type(uint8_t arg);
////  static char const* to_string(TimestampQuality arg);
////  static char const* to_human_string(TimestampQuality arg);
////  static TimestampQuality from_string(const std::string& arg);
////};

////}

#endif
