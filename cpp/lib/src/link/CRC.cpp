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
#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "SerializationTemplates.h"
#include "CRC.h"

////#include <ser4cpp/serialization/LittleEndian.h>

////namespace opendnp3
////{

//static CRC cCRC;

uint16_t crcTable_in_CRC[256]
  = {0x0000, 0x365E, 0x6CBC, 0x5AE2, 0xD978, 0xEF26, 0xB5C4, 0x839A, 0xFF89, 0xC9D7, 0x9335, 0xA56B, 0x26F1, 0x10AF,
     0x4A4D, 0x7C13, 0xB26B, 0x8435, 0xDED7, 0xE889, 0x6B13, 0x5D4D, 0x07AF, 0x31F1, 0x4DE2, 0x7BBC, 0x215E, 0x1700,
     0x949A, 0xA2C4, 0xF826, 0xCE78, 0x29AF, 0x1FF1, 0x4513, 0x734D, 0xF0D7, 0xC689, 0x9C6B, 0xAA35, 0xD626, 0xE078,
     0xBA9A, 0x8CC4, 0x0F5E, 0x3900, 0x63E2, 0x55BC, 0x9BC4, 0xAD9A, 0xF778, 0xC126, 0x42BC, 0x74E2, 0x2E00, 0x185E,
     0x644D, 0x5213, 0x08F1, 0x3EAF, 0xBD35, 0x8B6B, 0xD189, 0xE7D7, 0x535E, 0x6500, 0x3FE2, 0x09BC, 0x8A26, 0xBC78,
     0xE69A, 0xD0C4, 0xACD7, 0x9A89, 0xC06B, 0xF635, 0x75AF, 0x43F1, 0x1913, 0x2F4D, 0xE135, 0xD76B, 0x8D89, 0xBBD7,
     0x384D, 0x0E13, 0x54F1, 0x62AF, 0x1EBC, 0x28E2, 0x7200, 0x445E, 0xC7C4, 0xF19A, 0xAB78, 0x9D26, 0x7AF1, 0x4CAF,
     0x164D, 0x2013, 0xA389, 0x95D7, 0xCF35, 0xF96B, 0x8578, 0xB326, 0xE9C4, 0xDF9A, 0x5C00, 0x6A5E, 0x30BC, 0x06E2,
     0xC89A, 0xFEC4, 0xA426, 0x9278, 0x11E2, 0x27BC, 0x7D5E, 0x4B00, 0x3713, 0x014D, 0x5BAF, 0x6DF1, 0xEE6B, 0xD835,
     0x82D7, 0xB489, 0xA6BC, 0x90E2, 0xCA00, 0xFC5E, 0x7FC4, 0x499A, 0x1378, 0x2526, 0x5935, 0x6F6B, 0x3589, 0x03D7,
     0x804D, 0xB613, 0xECF1, 0xDAAF, 0x14D7, 0x2289, 0x786B, 0x4E35, 0xCDAF, 0xFBF1, 0xA113, 0x974D, 0xEB5E, 0xDD00,
     0x87E2, 0xB1BC, 0x3226, 0x0478, 0x5E9A, 0x68C4, 0x8F13, 0xB94D, 0xE3AF, 0xD5F1, 0x566B, 0x6035, 0x3AD7, 0x0C89,
     0x709A, 0x46C4, 0x1C26, 0x2A78, 0xA9E2, 0x9FBC, 0xC55E, 0xF300, 0x3D78, 0x0B26, 0x51C4, 0x679A, 0xE400, 0xD25E,
     0x88BC, 0xBEE2, 0xC2F1, 0xF4AF, 0xAE4D, 0x9813, 0x1B89, 0x2DD7, 0x7735, 0x416B, 0xF5E2, 0xC3BC, 0x995E, 0xAF00,
     0x2C9A, 0x1AC4, 0x4026, 0x7678, 0x0A6B, 0x3C35, 0x66D7, 0x5089, 0xD313, 0xE54D, 0xBFAF, 0x89F1, 0x4789, 0x71D7,
     0x2B35, 0x1D6B, 0x9EF1, 0xA8AF, 0xF24D, 0xC413, 0xB800, 0x8E5E, 0xD4BC, 0xE2E2, 0x6178, 0x5726, 0x0DC4, 0x3B9A,
     0xDC4D, 0xEA13, 0xB0F1, 0x86AF, 0x0535, 0x336B, 0x6989, 0x5FD7, 0x23C4, 0x159A, 0x4F78, 0x7926, 0xFABC, 0xCCE2,
     0x9600, 0xA05E, 0x6E26, 0x5878, 0x029A, 0x34C4, 0xB75E, 0x8100, 0xDBE2, 0xEDBC, 0x91AF, 0xA7F1, 0xFD13, 0xCB4D,
     0x48D7, 0x7E89, 0x246B, 0x1235
    };

uint16_t CalcCrc_in_CRC_staticOver1(uint8_t* input1, uint16_t length)
{
  uint16_t CRC1 = 0;

  for (uint32_t i = 0; i < length; ++i)
  {
    uint8_t index = (CRC1 ^ input1[i]) & 0xFF;
    CRC1 = crcTable_in_CRC[index] ^ (CRC1 >> 8);
  }

  return ~(int)CRC1;
}

uint16_t CalcCrc_in_CRC_staticOver2(RSeq_for_Uint16_t* view)
{
  return CalcCrc_in_CRC_staticOver1(view->buffer_, length_in_HasLength_for_Uint16_t(&(view->hHasLength)));//view.length());
}

void AddCrc_in_CRC_static(uint8_t* input, uint16_t length)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"{AddCrc_in_CRC_static1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*uint16_t length ="<<length<<'\n';
#endif
  uint16_t crc = CalcCrc_in_CRC_staticOver1(input, length);

////    ser4cpp::wseq_t buffer(input + length, 2);
//    void WSeq_for_Uint16_t_in_WSeq_for_Uint16_tOver2(WSeq_for_Uint16_t *pWSeq_for_Uint16_t, uint8_t* buffer, uint16_t length);
  WSeq_for_Uint16_t buffer;
  WSeq_for_Uint16_t_in_WSeq_for_Uint16_tOver2(&buffer, input + length, 2);
////    ser4cpp::UInt16::write_to(buffer, crc);
  write_to_in_UInt16_static(&buffer, crc);
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}AddCrc_in_CRC_static_"<<'\n';
  decrement_stack_info();
#endif
}

boolean IsCorrectCRC_in_CRC_static(uint8_t* input, uint16_t length)
{
// This definition is automatically set when compiling for OSS-Fuzz.
// See https://llvm.org/docs/LibFuzzer.html#fuzzer-friendly-build-mode
////#ifdef FUZZING_BUILD_MODE_UNSAFE_FOR_PRODUCTION
////    return true;
////#else
////    ser4cpp::rseq_t buffer(input + length, 2);
  RSeq_for_Uint16_t buffer;
  RSeq_for_Uint16_t_in_RSeq_for_Uint16_tOver2(&buffer, input + length, 2);
  uint16_t crcValue;
////    ser4cpp::UInt16::read_from(buffer, crcValue);
  read_from_in_UInt16_static(&buffer, &crcValue);
  return CalcCrc_in_CRC_staticOver1(input, length) == crcValue;
////#endif
}

////} // namespace opendnp3
