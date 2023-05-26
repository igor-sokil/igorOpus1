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

#ifndef OPENDNP3_FROZENCOUNTERQUALITY_H
#define OPENDNP3_FROZENCOUNTERQUALITY_H

////#include <cstdint>
////#include <string>

////namespace opendnp3 {

/**
  Quality field bitmask for frozen counter values
*/
////enum class FrozenCounterQuality : uint8_t
#define FrozenCounterQuality_uint8_t uint8_t
enum FrozenCounterQuality
{
  /// set when the data is "good", meaning that rest of the system can trust the value
  FrozenCounterQuality_ONLINE = 0x1,
  /// the quality all points get before we have established communication (or populated) the point
  FrozenCounterQuality_RESTART = 0x2,
  /// set if communication has been lost with the source of the data (after establishing contact)
  FrozenCounterQuality_COMM_LOST = 0x4,
  /// set if the value is being forced to a "fake" value somewhere in the system
  FrozenCounterQuality_REMOTE_FORCED = 0x8,
  /// set if the value is being forced to a "fake" value on the original device
  FrozenCounterQuality_LOCAL_FORCED = 0x10,
  /// Deprecated flag that indicates value has rolled over
  FrozenCounterQuality_ROLLOVER = 0x20,
  /// indicates an unusual change in value
  FrozenCounterQuality_DISCONTINUITY = 0x40,
  /// reserved bit
  FrozenCounterQuality_RESERVED = 0x80
};

////struct FrozenCounterQualitySpec
////{
////  using enum_type_t = FrozenCounterQuality;

////  static uint8_t to_type(FrozenCounterQuality arg);
////  static FrozenCounterQuality from_type(uint8_t arg);
////  static char const* to_string(FrozenCounterQuality arg);
////  static char const* to_human_string(FrozenCounterQuality arg);
////  static FrozenCounterQuality from_string(const std::string& arg);
////};

////}

#endif
