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

#ifndef OPENDNP3_MASTERTASKTYPE_H
#define OPENDNP3_MASTERTASKTYPE_H

////#include <cstdint>
////#include <string>

////namespace opendnp3 {

/**
  Enumeration of internal tasks
*/
//enum class MasterTaskType : uint8_t
#define MasterTaskType_uint8_t  uint8_t 
enum MasterTaskType
{
  MasterTaskType_CLEAR_RESTART = 0,
  MasterTaskType_DISABLE_UNSOLICITED = 1,
  MasterTaskType_ASSIGN_CLASS = 2,
  MasterTaskType_STARTUP_INTEGRITY_POLL = 3,
  MasterTaskType_NON_LAN_TIME_SYNC = 4,
  MasterTaskType_LAN_TIME_SYNC = 5,
  MasterTaskType_ENABLE_UNSOLICITED = 6,
  MasterTaskType_AUTO_EVENT_SCAN = 7,
  MasterTaskType_USER_TASK = 8
};

////struct MasterTaskTypeSpec
////{
////  using enum_type_t = MasterTaskType;

////  static uint8_t to_type(MasterTaskType arg);
////  static MasterTaskType from_type(uint8_t arg);
////  static char const* to_string(MasterTaskType arg);
////  static char const* to_human_string(MasterTaskType arg);
////  static MasterTaskType from_string(const std::string& arg);
////};

////}

#endif
