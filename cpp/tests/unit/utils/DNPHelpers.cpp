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

//#include "utils/BufferHelpers.h"

//#include <ser4cpp/util/HexConversions.h>

//#include <catch.hpp>
#include <QtWidgets>
#include <QApplication>
#include "header.h"
#include "CRC.h"
#include "HexConversions.h"
#include "BufferHelpers.h"
#include "DNPHelpers.h"
///#include <link/LinkFrame.h>

////using namespace opendnp3;
////using namespace ser4cpp;

////std::string RepairCRC(const std::string& arData)
std::string RepairCRC_in_DNPHelpers(std::string& arData)
{
////    HexSequence hs(arData);
  HexSequence hs;
  HexSequence_in_HexSequence(&hs, arData);

  // validate the size of the data
//uint16_t Size_in_CopyableBuffer(CopyableBuffer *pCopyableBuffer);
////    REQUIRE(hs.Size() >= 10);
  uint16_t sz = Size_in_CopyableBuffer(&(hs.bByteStr.cCopyableBuffer));
  qDebug()<<"Size_in_CopyableBuffer= "<<sz;

////    REQUIRE(hs.Size() <= 292);
  qDebug()<<"REQUIRE(hs.Size() >= 10)";
  qDebug()<<"REQUIRE(hs.Size() <= 292)";

  // first determine how much user data is present
  uint16_t full_blocks = (/*hs.Size()*/sz - 10) / 18;
  uint16_t partial_size = (/*hs.Size()*/sz - 10) % 18;

  // can't have a partial size < 3 since even 1 byte requires 2 CRC bytes
  if (partial_size > 0)
  {
////        REQUIRE(partial_size >= 3);
    qDebug()<<"REQUIRE(partial_size >= 3)";
    qDebug()<<"partial_size= "<<partial_size;
  }

  // repair the header crc
//void AddCrc_in_CRC_static(uint8_t* input, uint16_t length);
////    CRC::AddCrc(hs, 8);
  AddCrc_in_CRC_static(hs.bByteStr.cCopyableBuffer.buffer, 8);

////    uint8_t* ptr = hs + 10;
  uint8_t* ptr = hs.bByteStr.cCopyableBuffer.buffer + 10;

  // repair the full blocks
  for (uint16_t i = 0; i < full_blocks; i++)
  {
////        CRC::AddCrc(ptr, 16);
    AddCrc_in_CRC_static(ptr, 16);
    ptr += 18;
  }

  // repair the partial block
  if (partial_size > 0)
////        CRC::AddCrc(ptr, partial_size - 2);
    AddCrc_in_CRC_static(ptr, partial_size - 2);

//RSeq_for_Uint16_t ToRSeq_in_CopyableBuffer(CopyableBuffer *pCopyableBuffer);
////    return HexConversions::to_hex(hs.ToRSeq(), true);
  RSeq_for_Uint16_t rseq = ToRSeq_in_CopyableBuffer(&(hs.bByteStr.cCopyableBuffer));
  return to_hex_in_HexConversionsOver2(&rseq, true);
}
