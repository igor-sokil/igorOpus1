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
#include <QtWidgets>
#include <QApplication>
#include "header.h"
#include "BufferHelpers.h"

#include "HexConversions.h"

////#include <algorithm>
////#include <cassert>
/////#include <exception>
////#include <memory>
////#include <sstream>
////#include <stdexcept>

////ByteStr::ByteStr(size_t length, uint8_t seed) : CopyableBuffer(length)
  void ByteStr_in_ByteStrOver1(ByteStr *pByteStr, uint16_t length, uint8_t seed)// = 0);
{
    for (uint16_t i = 0; i < length; ++i)
        pByteStr->cCopyableBuffer.buffer[i] = (uint8_t)((i + seed) % 256);
}

////ByteStr::ByteStr(const uint8_t* data, size_t length) : CopyableBuffer(data, length) {}
  void ByteStr_in_ByteStrOver2(ByteStr *pByteStr, uint8_t* data, uint16_t length)
{
//  void CopyableBuffer_in_CopyableBufferOver4(CopyableBuffer *pCopyableBuffer, uint8_t* data, uint16_t size);
   CopyableBuffer_in_CopyableBufferOver4(&(pByteStr->cCopyableBuffer), data, length);
}


////bool ByteStr::operator==(const ByteStr& other) const
////{
////    if (Size() != other.Size())
////        return false;
////
////    for (size_t i = 0; i < Size(); ++i)
////        if (this->buffer[i] != other[i])
////            return false;
////
////    return true;
////}

std::string ToHex_in_ByteStr(ByteStr *pByteStr)
{
//RSeq_for_Uint16_t ToRSeq_in_CopyableBuffer(CopyableBuffer *pCopyableBuffer);
//    std::string to_hex_in_HexConversionsOver2(RSeq_for_Uint16_t* buffer, bool spaced = true);
////    return ser4cpp::HexConversions::to_hex(ToRSeq());
RSeq_for_Uint16_t temp = ToRSeq_in_CopyableBuffer(&(pByteStr->cCopyableBuffer));
    return to_hex_in_HexConversionsOver2(&temp, true);
}

////HexSequence::HexSequence(const std::string& hex) : ByteStr(Validate(RemoveSpaces(hex)))
   void HexSequence_in_HexSequence(HexSequence *pHexSequence, std::string& hex)
{
//  uint16_t Validate_in_HexSequence_static(std::string& s);
//  std::string RemoveSpaces_in_HexSequence(HexSequence *pHexSequence, std::string& hex);
//  void ByteStr_in_ByteStrOver1(ByteStr *pByteStr, uint16_t length, uint8_t seed);// = 0);
  std::string tmp = RemoveSpaces_in_HexSequence(pHexSequence, hex);
  uint16_t temp = Validate_in_HexSequence_static(tmp);
  ByteStr_in_ByteStrOver1(&(pHexSequence->bByteStr), temp, 0);
////   ByteStr_in_ByteStrOver1(&(pHexSequence->bByteStr), Validate_in_HexSequence_static(RemoveSpaces_in_HexSequence(pHexSequence, hex)), 0);// = 0);

    std::string s = RemoveSpaces_in_HexSequence(pHexSequence, hex);

qDebug()<<"sizeof(cCopyableBuffer.buffer)= "<< sizeof(pHexSequence->bByteStr.cCopyableBuffer.buffer);

    uint16_t size = s.size();

qDebug()<<"size= "<<size;

    for (uint16_t index = 0, pos = 0; pos < size; ++index, pos += 2)
    {
        uint32_t val;
        std::stringstream ss;
        ss << std::hex << s.substr(pos, 2);
        if ((ss >> val).fail())
        {
////            throw std::invalid_argument(hex);
        }
        pHexSequence->bByteStr.cCopyableBuffer.buffer[index] = static_cast<uint8_t>(val);
    }
}

std::string RemoveSpaces_in_HexSequence(HexSequence *pHexSequence, std::string& hex)
{
    std::string copy(hex);
//  void RemoveSpacesInPlace_in_HexSequence(HexSequence *pHexSequence, std::string& s);
////    RemoveSpacesInPlace(copy);
   RemoveSpacesInPlace_in_HexSequence(pHexSequence, copy);
    return copy;
}

////void HexSequence::RemoveSpacesInPlace(std::string& s)
  void RemoveSpacesInPlace_in_HexSequence(HexSequence *pHexSequence, std::string& s)
{
    size_t pos = s.find_first_of(' ');
    if (pos != std::string::npos)
    {
        s.replace(pos, 1, "");
//  void RemoveSpacesInPlace_in_HexSequence(HexSequence *pHexSequence, std::string& s)
////        RemoveSpacesInPlace(s);
   RemoveSpacesInPlace_in_HexSequence(pHexSequence, s);
    }
}

uint16_t Validate_in_HexSequence_static(std::string& s)
{
    // annoying when you accidentally put an 'O' instead of zero '0'
    if (s.find_first_of("oO") != std::string::npos)
    {
////        throw std::invalid_argument("Sequence contains 'o' or 'O'");
    }

    if (s.size() % 2 != 0)
    {
////        throw std::invalid_argument(s);
    }

    return s.size() / 2;
}
