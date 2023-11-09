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
#include "ObjectHeaderParser.h"

#include "GroupVariationRecord.h"
#include "SerializationTemplates.h"
////#include "logging/LogMacros.h"

////#include "opendnp3/logging/LogLevels.h"

////#include <ser4cpp/serialization/LittleEndian.h>

////namespace opendnp3
////{

void ObjectHeader_in_ObjectHeader(ObjectHeader *pObjectHeader)
{
  pObjectHeader->group = 0;
  pObjectHeader->variation = 0;
  pObjectHeader->qualifier = 0;
}

ParseResult_uint8_t ParseObjectHeader_in_ObjectHeaderParser_static(ObjectHeader* header, RSeq_for_Uint16_t* buffer)////, Logger* pLogger)
{
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"ParseObjectHeader_in_ObjectHeaderParser_static1"<<std::endl;
  inspect_RSeq(buffer);
#endif
////    if (buffer.length() < 3)
  if (length_in_HasLength_for_Uint16_t(&(buffer->hHasLength)) < 3)
  {
////        SIMPLE_LOGGER_BLOCK(pLogger, flags::WARN, "Not enough data for header");
#ifdef  LOG_INFO
    std::cout<<"+"<<getString_stack_info();
    std::cout<<"***SIMPLE_LOGGER_BLOCK(pLogger, flags::WARN, 'Not enough data for header')***"<<std::endl;
    decrement_stack_info();
#endif
    return ParseResult_NOT_ENOUGH_DATA_FOR_HEADER;
  }

//    boolean read_from_in_UInt8_static(RSeq_for_Uint16_t *input, uint8_t *out);
////    ser4cpp::UInt8::read_from(buffer, header.group);
////    ser4cpp::UInt8::read_from(buffer, header.variation);
////    ser4cpp::UInt8::read_from(buffer, header.qualifier);
  read_from_in_UInt8_static(buffer, &(header->group));
  read_from_in_UInt8_static(buffer, &(header->variation));
  read_from_in_UInt8_static(buffer, &(header->qualifier));

#ifdef  LOG_INFO
  decrement_stack_info();
#endif
  return ParseResult_OK;
}

boolean ReadFirstGroupVariation_in_ObjectHeaderParser_static(RSeq_for_Uint16_t* objects, GroupVariation_uint16_t* gv)
{
  RSeq_for_Uint16_t copy = *objects;
  ObjectHeader oheader;
//ParseResult_uint8_t ParseObjectHeader_in_ObjectHeaderParser_static(ObjectHeader* header, RSeq_for_Uint16_t* buffer)////, Logger* pLogger)
////    if (ObjectHeaderParser::ParseObjectHeader(oheader, copy, nullptr) != ParseResult::OK)
  if (ParseObjectHeader_in_ObjectHeaderParser_static(&oheader, &copy) != ParseResult_OK)////, Logger* pLogger)
  {
    return false;
  }

//    GroupVariationRecord GetRecord_in_GroupVariationRecord_static(uint8_t group, uint8_t variation);
////    gv = GroupVariationRecord::GetRecord(oheader.group, oheader.variation).enumeration;
  *gv = GetRecord_in_GroupVariationRecord_static(oheader.group, oheader.variation).enumeration;

  return true;
}

////} // namespace opendnp3
