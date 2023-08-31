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
#ifndef OPENDNP3_APDUPARSER_H
#define OPENDNP3_APDUPARSER_H

////#include "app/parsing/IAPDUHandler.h"
////#include "app/parsing/NumParser.h"
////#include "app/parsing/ParseResult.h"
////#include "app/parsing/ParserSettings.h"

////#include "opendnp3/util/StaticOnly.h"

////#include <ser4cpp/container/SequenceTypes.h>
#include "IAPDUHandler.h"
#include "NumParser.h"
#include "ParseResult.h"
//#include "ParserSettings.h"

//#include "opendnp3/util/StaticOnly.h"

//#include <ser4cpp/container/SequenceTypes.h>


////namespace opendnp3
////{

////class APDUParser : private StaticOnly
////typedef struct
////{
////public:
ParseResult_uint8_t Parse_in_APDUParser_static(
  RSeq_for_Uint16_t *buffer,
  IAPDUHandler *handler);
////                             Logger& logger,
////                             ParserSettings settings = ParserSettings::Default());

ParseResult_uint8_t ParseAndLogAll_in_APDUParser_static(
  RSeq_for_Uint16_t *buffer);
////                                      Logger* pLogger,
////                                      ParserSettings settings = ParserSettings::Default());

ParseResult_uint8_t ParseSinglePass_in_APDUParser_static(
  RSeq_for_Uint16_t *buffer,
//                                       Logger* pLogger,
  IAPDUHandler* pHandler,
  IWhiteList* pWhiteList);
//                                       const ParserSettings& settings);

////private:
////    static bool AllowAll(uint32_t headerCount, GroupVariation gv, QualifierCode qc)
////    {
////        return true;
////    }

ParseResult_uint8_t ParseHeaders_in_APDUParser_static(
  RSeq_for_Uint16_t *buffer,
//                                    Logger* pLogger,
//                                    const ParserSettings& settings,
  IAPDUHandler* pHandler);

ParseResult_uint8_t ParseHeader_in_APDUParser_static(
  RSeq_for_Uint16_t *buffer,
//                                   Logger* pLogger,
  uint32_t count,
//                                   const ParserSettings& settings,
  IAPDUHandler* pHandler,
  IWhiteList* pWhiteList);

ParseResult_uint8_t ParseQualifier_in_APDUParser_static(
  RSeq_for_Uint16_t *buffer,
//                                      Logger* pLogger,
  HeaderRecord *record,
//                                      const ParserSettings& settings,
  IAPDUHandler* pHandler);

ParseResult_uint8_t HandleAllObjectsHeader_in_APDUParser_static(//Logger* pLogger,
  HeaderRecord *record,
//                                              const ParserSettings& settings,
  IAPDUHandler* pHandler);

ParseResult_uint8_t ParseCountOfIndices_in_APDUParser_static(
  RSeq_for_Uint16_t *buffer,
  HeaderRecord *record,
  NumParser *numparser,
  uint16_t count,
//                                           Logger* pLogger,
  IAPDUHandler* pHandler);
////} APDUParser;

////} // namespace opendnp3

#endif
