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

#ifndef OPENDNP3_FUNCTIONCODE_H
#define OPENDNP3_FUNCTIONCODE_H

////#include <cstdint>
////#include <string>

////namespace opendnp3 {

/**
  Application layer function code enumeration
*/
//enum class FunctionCode : uint8_t
#define FunctionCode_uint8_t uint8_t
enum FunctionCode 
{
  /// Master sends this to an outstation to confirm the receipt of an Application Layer fragment
/// ������ ���������� ��� �� ��������� �������, ����� ����������� ��������� ��������� ����������� ������
  FunctionCode_CONFIRM = 0x0,
  /// Outstation shall return the data specified by the objects in the request
/// Outstation ������ ������, ��������� ��������� � �������
  FunctionCode_READ = 0x1,
  /// Outstation shall store the data specified by the objects in the request
/// Outstation ����� ������� ������, ��������� ��������� � �������
  FunctionCode_WRITE = 0x2,
  /// Outstation shall select (or arm) the output points specified by the objects in the request in preparation for a subsequent operate command
/// Outstation ������ ������� (��� ��������� �� ������) ����� ������, ��������� ��������� � �������, ��� ���������� � ����������� ������� ������������
  FunctionCode_SELECT = 0x3,
  /// Outstation shall activate the output points selected (or armed) by a previous select function code command
/// Outstation ���������� ����� ������, ��������� (��� ������������ �� ������) ���������� �������� ���� ������� ������.
  FunctionCode_OPERATE = 0x4,
  /// Outstation shall immediately actuate the output points specified by the objects in the request
/// Outstation ���������� ��������� ����� ������, ��������� ��������� � �������
  FunctionCode_DIRECT_OPERATE = 0x5,
  /// Same as DIRECT_OPERATE but outstation shall not send a response
/// �� ��, ��� � DIRECT_OPERATE, �� ��������� ������� �� ������ ���������� �����
  FunctionCode_DIRECT_OPERATE_NR = 0x6,
  /// Outstation shall copy the point data values specified by the objects in the request to a separate freeze buffer
/// Outstation ��������� �������� ������ �����, ��������� ��������� � �������, � ��������� �������������� �����
  FunctionCode_IMMED_FREEZE = 0x7,
  /// Same as IMMED_FREEZE but outstation shall not send a response
/// �� ��, ��� IMMED_FREEZE, �� ��������� ������� �� ����� ���������� �����
  FunctionCode_IMMED_FREEZE_NR = 0x8,
  /// Outstation shall copy the point data values specified by the objects in the request into a separate freeze buffer and then clear the values
/// Outstation ��������� �������� ������ �����, ��������� ��������� � �������, � ��������� �������������� �����, � ����� ������� ��������
  FunctionCode_FREEZE_CLEAR = 0x9,
  /// Same as FREEZE_CLEAR but outstation shall not send a response
/// �� ��, ��� � FREEZE_CLEAR, �� ������� ������� �� ����� ���������� �����
  FunctionCode_FREEZE_CLEAR_NR = 0xA,
  /// Outstation shall copy the point data values specified by the objects in the request to a separate freeze buffer at the time and/or time intervals specified in a special time data information object
/// Outstation �������� �������� ������ �����, ��������� ��������� � �������, � ��������� ����� �������� �� ����� �/��� ��������� �������, ��������� � ����������� �������������� ������� ������ �������.
  FunctionCode_FREEZE_AT_TIME = 0xB,
  /// Same as FREEZE_AT_TIME but outstation shall not send a response
/// �� ��, ��� � FREEZE_AT_TIME, �� ��������� ������� �� ����� ���������� �����
  FunctionCode_FREEZE_AT_TIME_NR = 0xC,
  /// Outstation shall perform a complete reset of all hardware and software in the device
/// Outstation �������� ������ ����� ����� ����������� � ������������ ����������� ����������.
  FunctionCode_COLD_RESTART = 0xD,
  /// Outstation shall reset only portions of the device
/// Outstation ����� ���������� ������ ����� ����������
  FunctionCode_WARM_RESTART = 0xE,
  /// Obsolete-Do not use for new designs
/// �������� � �� ������������ ��� ����� ��������
  FunctionCode_INITIALIZE_DATA = 0xF,
  /// Outstation shall place the applications specified by the objects in the request into the ready to run state
/// Outstation ��������� ����������, ��������� ��������� � �������, � ��������� ���������� � �������
  FunctionCode_INITIALIZE_APPLICATION = 0x10,
  /// Outstation shall start running the applications specified by the objects in the request
/// Outstation ������ ��������� ����������, ��������� ��������� � �������
  FunctionCode_START_APPLICATION = 0x11,
  /// Outstation shall stop running the applications specified by the objects in the request
/// Outstation ��������� ������ ����������, ��������� ��������� � �������
  FunctionCode_STOP_APPLICATION = 0x12,
  /// This code is deprecated-Do not use for new designs
/// ���� ��� �������. �� ����������� ��� ����� ��������.
  FunctionCode_SAVE_CONFIGURATION = 0x13,
  /// Enables outstation to initiate unsolicited responses from points specified by the objects in the request
/// ��������� ��������� ������� ������������ ������������� ������ �� �����, ��������� ��������� � �������
  FunctionCode_ENABLE_UNSOLICITED = 0x14,
  /// Prevents outstation from initiating unsolicited responses from points specified by the objects in the request
/// ������������� ��������� ������������� ������� ��������� �������� �� �����, ��������� ��������� � �������
  FunctionCode_DISABLE_UNSOLICITED = 0x15,
  /// Outstation shall assign the events generated by the points specified by the objects in the request to one of the classes
/// Outstation ������� �������, ������������ �������, ���������� ��������� � �������, � ������ �� �������
  FunctionCode_ASSIGN_CLASS = 0x16,
  /// Outstation shall report the time it takes to process and initiate the transmission of its response
/// Outstation ������� �����, ����������� ��� ��������� � ��������� �������� ������ ������.
  FunctionCode_DELAY_MEASURE = 0x17,
  /// Outstation shall save the time when the last octet of this message is received
/// Outstation �������� ����� ��������� ���������� ������ ����� ���������
  FunctionCode_RECORD_CURRENT_TIME = 0x18,
  /// Outstation shall open a file
/// Outstation ������� ����
  FunctionCode_OPEN_FILE = 0x19,
  /// Outstation shall close a file
/// Outstation ������� ����
  FunctionCode_CLOSE_FILE = 0x1A,
  /// Outstation shall delete a file
/// Outstation ������ ������� ����
  FunctionCode_DELETE_FILE = 0x1B,
  /// Outstation shall retrieve information about a file
/// Outstation ������� ���������� � �����
  FunctionCode_GET_FILE_INFO = 0x1C,
  /// Outstation shall return a file authentication key
/// Outstation ������ ���� �������������� �����
  FunctionCode_AUTHENTICATE_FILE = 0x1D,
  /// Outstation shall abort a file transfer operation
/// Outstation ������� �������� �������� ������
  FunctionCode_ABORT_FILE = 0x1E,
  /// The master uses this function code when sending authentication requests to the outstation
/// ������ ���������� ���� ��� ������� ��� �������� �������� �������������� �� ��������� �������
  FunctionCode_AUTH_REQUEST = 0x20,
  /// The master uses this function code when sending authentication requests to the outstation that do no require acknowledgement
/// ������ ���������� ���� ��� ������� ��� �������� �������� �������������� �� ��������� �������, ������� �� ������� �������������
  FunctionCode_AUTH_REQUEST_NO_ACK = 0x21,
  /// Master shall interpret this fragment as an Application Layer response to an ApplicationLayer request
/// ������ ������ ���������������� ���� �������� ��� ����� ������ ���������� �� ������ ������ ����������.
  FunctionCode_RESPONSE = 0x81,
  /// Master shall interpret this fragment as an unsolicited response that was not prompted by an explicit request
/// ������ ������ ���������������� ���� �������� ��� ������������� �����, ������� �� ��� ������ ����� ��������
  FunctionCode_UNSOLICITED_RESPONSE = 0x82,
  /// The outstation uses this function code to issue authentication messages to the master
/// ��������� ������� ���������� ���� ��� ������� ��� �������� ��������� �������������� �������
  FunctionCode_AUTH_RESPONSE = 0x83,
  /// Unknown function code. Used internally in opendnp3 to indicate the code didn't match anything known
/// ����������� ��� �������. ������������ ������ opendnp3, ����� �������, ��� ��� �� ������������� ������ ����������.
  FunctionCode_UNKNOWN = 0xFF
};

FunctionCode_uint8_t from_type_in_FunctionCodeSpec(uint8_t arg);

////struct FunctionCodeSpec
////{
////  using enum_type_t = FunctionCode;

////  static uint8_t to_type(FunctionCode arg);
////  static FunctionCode from_type(uint8_t arg);
////  static char const* to_string(FunctionCode arg);
////  static char const* to_human_string(FunctionCode arg);
////  static FunctionCode from_string(const std::string& arg);
////};

////}

#endif
