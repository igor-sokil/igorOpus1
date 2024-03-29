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
#ifndef OPENDNP3_UNITTESTS_BUFFERHELPERS_H
#define OPENDNP3_UNITTESTS_BUFFERHELPERS_H

#include "CopyableBuffer.h"

////#include <string>

////class ByteStr : public CopyableBuffer
typedef struct
{
  CopyableBuffer cCopyableBuffer;
////public:
////    ByteStr(size_t length, uint8_t seed = 0);
////    ByteStr(const uint8_t* data, size_t length);
////    bool operator==(const ByteStr& other) const;
////    std::string ToHex() const;
} ByteStr;

void ByteStr_in_ByteStrOver1(ByteStr *pByteStr, uint16_t length, uint8_t seed);// = 0);
void ByteStr_in_ByteStrOver2(ByteStr *pByteStr, uint8_t* data, uint16_t length);
////    bool operator==(const ByteStr& other) const;
std::string ToHex_in_ByteStr(ByteStr *pByteStr);

/**
 * A sequence of hex values in the form "01 02 03 04" that are stored as a ByteStr.
 */
////class HexSequence : public ByteStr
typedef struct
{
  ByteStr bByteStr;
////public:
////    HexSequence(const std::string& hex);

////    operator ser4cpp::rseq_t()
////    {
////        return this->ToRSeq();
////    }

////private:
////    std::string RemoveSpaces(const std::string& hex);
////    void RemoveSpacesInPlace(std::string& s);
////    static size_t Validate(const std::string& s);
} HexSequence;

void HexSequence_in_HexSequence(HexSequence *pHexSequence, std::string& hex);

std::string RemoveSpaces_in_HexSequence(HexSequence *pHexSequence, std::string& hex);
void RemoveSpacesInPlace_in_HexSequence(HexSequence *pHexSequence, std::string& s);
uint16_t Validate_in_HexSequence_static(std::string& s);

#endif
