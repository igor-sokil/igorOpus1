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
#include <iostream>
#include "header.h"
#include "BitReader.h"

////#include <cassert>

////namespace opendnp3
////{

////size_t NumBytesInBits(size_t numBits)
uint32_t NumBytesInBits_in_DoubleBit_static(uint32_t numBits)
{
    uint32_t numBytes = numBits / 8;
    return ((numBits % 8) == 0) ? numBytes : numBytes + 1;
}

////bool GetBit(const ser4cpp::rseq_t& buffer, size_t position)
boolean GetBit_in_DoubleBit_static(RSeq_for_Uint16_t* buffer, uint32_t position)
{
    uint32_t byte = position / 8;
    uint32_t bit = position % 8;
////    assert(byte < buffer.length());
    if(length_in_HasLength_for_Uint16_t(&(buffer->hHasLength)) < byte) std::cout<<"*assert(byte < buffer.length())"<<'\n';
////    return (buffer[byte] & (1 << bit)) != 0;
    return (buffer->buffer_[byte] & (1 << bit)) != 0;
}

////size_t NumBytesInDoubleBits(size_t numBits)
uint32_t NumBytesInDoubleBits_in_DoubleBit_static(uint32_t numBits)
{
    uint32_t numBytes = numBits / 4;
    return ((numBits % 4) == 0) ? numBytes : numBytes + 1;
}

////DoubleBit GetDoubleBit(const ser4cpp::rseq_t& buffer, size_t index)
DoubleBit_uint8_t GetDoubleBit_in_DoubleBit_static(RSeq_for_Uint16_t* buffer, uint32_t index)
{
    uint32_t byteNumber = index / 4;
////    assert(byteNumber < buffer.length());
    if(length_in_HasLength_for_Uint16_t(&(buffer->hHasLength)) < byteNumber) std::cout<<"*assert(byteNumber < buffer.length())"<<'\n';
    uint8_t byte = buffer->buffer_[byteNumber];////buffer[byteNumber];
    uint32_t bitshift = 2 * (index % 4);
//DoubleBit_uint8_t from_type_in_DoubleBitSpec(uint8_t arg);
////    return DoubleBitSpec::from_type((byte >> bitshift) & 0x03);
    return  from_type_in_DoubleBitSpec((byte >> bitshift) & 0x03);
}

////} // namespace opendnp3
