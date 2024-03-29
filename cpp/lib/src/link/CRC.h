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
#ifndef OPENDNP3_CRC_H
#define OPENDNP3_CRC_H

//#include <ser4cpp/container/SequenceTypes.h>

//#include <cstdint>

#include "RSeq.h"
////namespace opendnp3
////{

////class CRC
////typedef struct
////{
////public:
////    static uint16_t CalcCrc_in_CRC_static(const uint8_t* input, size_t length);

////    static uint16_t CalcCrc_in_CRC_static(const ser4cpp::rseq_t& view);

////    static void AddCrc_in_CRC_static(uint8_t* input, size_t length);

////    static bool IsCorrectCRC_in_CRC_static(const uint8_t* input, size_t length);

////private:
///     uint16_t crcTable[256]; // Precomputed CRC lookup table
////} CRC;

uint16_t CalcCrc_in_CRC_staticOver1(uint8_t* input, uint16_t length);

uint16_t CalcCrc_in_CRC_staticOver2(RSeq_for_Uint16_t* view);

void AddCrc_in_CRC_static(uint8_t* input, uint16_t length);

boolean IsCorrectCRC_in_CRC_static(uint8_t* input, uint16_t length);

////} // namespace opendnp3

#endif
