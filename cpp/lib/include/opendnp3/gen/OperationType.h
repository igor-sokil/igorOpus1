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

#ifndef OPENDNP3_OPERATIONTYPE_H
#define OPENDNP3_OPERATIONTYPE_H

////#include <cstdint>
////#include <string>

////namespace opendnp3 {

/**
  Used in conjunction with Trip Close Code in a CROB to describe what action to perform
  Refer to section A.8.1 of IEEE 1815-2012 for a full description
������������ ������ � ����� �������� ���������� � CROB ��� �������� ����, ����� �������� ���������� ���������.
   ������ �������� ��. � ������� A.8.1 ��������� IEEE 1815-2012.
*/
//enum class OperationType : uint8_t
#define OperationType_uint8_t  uint8_t
enum OperationType 
{
  /// Do nothing.
  OperationType_NUL = 0x0,
  /// Set output to active for the duration of the On-time.
  OperationType_PULSE_ON = 0x1,
  /// Non-interoperable code. Do not use for new applications.
  OperationType_PULSE_OFF = 0x2,
  /// Set output to active.
  OperationType_LATCH_ON = 0x3,
  /// Set the output to inactive.
  OperationType_LATCH_OFF = 0x4,
  /// Undefined.
  OperationType_Undefined = 0xFF
};

OperationType_uint8_t from_type_in_OperationTypeSpec_static(uint8_t arg);
                      
////struct OperationTypeSpec
////{
////  using enum_type_t = OperationType;

////  static uint8_t to_type(OperationType arg);
////  static OperationType from_type(uint8_t arg);
////  static char const* to_string(OperationType arg);
////  static char const* to_human_string(OperationType arg);
////  static OperationType from_string(const std::string& arg);
////};

////}

#endif
