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
#ifndef OPENDNP3_LINKLAYERCONSTANTS_H
#define OPENDNP3_LINKLAYERCONSTANTS_H

////#include <cstdint>

////namespace opendnp3
////{

const uint8_t LPDU_MIN_LENGTH = 5;
const uint8_t LPDU_MAX_LENGTH = 255;
const uint8_t LPDU_HEADER_SIZE = 10;
const uint8_t LPDU_DATA_BLOCK_SIZE = 16;
const uint8_t LPDU_CRC_SIZE = 2;
const uint8_t LPDU_DATA_PLUS_CRC_SIZE = 18;
const uint8_t LPDU_MAX_USER_DATA_SIZE = 250;
const uint16_t LPDU_MAX_FRAME_SIZE = 292; // 10(header) + 250 (user data) + 32 (block CRC's) = 292 frame bytes

// Broadcast addresses
#define LinkBroadcastAddress_uint16_t  uint16_t
enum LinkBroadcastAddress//// : uint16_t
{
  LinkBroadcastAddress_DontConfirm = 0xFFFD,
  LinkBroadcastAddress_ShallConfirm = 0xFFFE,
  LinkBroadcastAddress_OptionalConfirm = 0xFFFF,
};

/// Indices for use with buffers containing link headers
#define LinkHeaderIndex_uint8_t  uint8_t
enum LinkHeaderIndex //: uint8_t
{
  LinkHeaderIndex_LI_START_05 = 0,
  LinkHeaderIndex_LI_START_64 = 1,
  LinkHeaderIndex_LI_LENGTH = 2,
  LinkHeaderIndex_LI_CONTROL = 3,
  LinkHeaderIndex_LI_DESTINATION = 4,
  LinkHeaderIndex_LI_SOURCE = 6,
  LinkHeaderIndex_LI_CRC = 8
};

/// Masks for use with the CONTROL byte
#define ControlMask_uint8_t  uint8_t
enum ControlMask //: uint8_t
{
  ControlMask_MASK_DIR = 0x80,
  ControlMask_MASK_PRM = 0x40,
  ControlMask_MASK_FCB = 0x20,
  ControlMask_MASK_FCV = 0x10,
  ControlMask_MASK_FUNC = 0x0F,
  ControlMask_MASK_FUNC_OR_PRM = ControlMask_MASK_PRM | ControlMask_MASK_FUNC
};

////} // namespace opendnp3

#endif
