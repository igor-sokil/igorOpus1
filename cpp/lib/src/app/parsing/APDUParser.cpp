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
////#include "APDUParser.h"

////#include "app/GroupVariationRecord.h"
////#include "app/MeasurementFactory.h"
////#include "app/parsing/CountIndexParser.h"
////#include "app/parsing/CountParser.h"
////#include "app/parsing/ObjectHeaderParser.h"
////#include "app/parsing/RangeParser.h"
////#include "logging/LogMacros.h"

////#include "opendnp3/gen/QualifierCode.h"
////#include "opendnp3/logging/LogLevels.h"

#include <string.h>
#include "header.h"
#include "APDUParser.h"

#include "GroupVariationRecord.h"
#include "MeasurementFactory.h"
#include "CountIndexParser.h"
#include "erCountParser.h"
#include "ObjectHeaderParser.h"
#include "erRangeParser.h"
//#include "ing/LogMacros.h"

#include "QualifierCode.h"
//#include "opendnp3/logging/LogLevels.h"

////namespace opendnp3
////{

//ParseResult_uint8_t Parse_in_APDUParser_static(
//                              RSeq_for_Uint16_t *buffer,
//                              IAPDUHandler *handler)
//                              Logger& logger,
//                              ParserSettings settings)
//{
//    return Parse(buffer, handler, &logger, settings);
//}

ParseResult_uint8_t Parse_in_APDUParser_static(
                              RSeq_for_Uint16_t *buffer,
                              IAPDUHandler *handler)
//                              Logger* pLogger,
//                              ParserSettings settings)
{
    // do two state parsing process with logging and white-listing first but no handling on the first pass
    ParseResult_uint8_t result = ParseSinglePass(buffer, /*pLogger,*/ NULL, handler);//, settings);
    // if the first pass was successful, do a 2nd pass with the handler but no logging or white-list
    return (result == ParseResult_OK) ? ParseSinglePass(buffer, NULL, handler, NULL/*, settings*/) : result;
}

ParseResult_uint8_t ParseAndLogAll_in_APDUParser_static(RSeq_for_Uint16_t *buffer)//, Logger* pLogger, ParserSettings settings)
{
    return ParseSinglePass_in_APDUParser_static(buffer, /*pLogger,*/ NULL, NULL);//, settings);
}

ParseResult_uint8_t ParseSinglePass_in_APDUParser_static(
                                        RSeq_for_Uint16_t *buffer,
                                        //Logger* pLogger,
                                        IAPDUHandler* pHandler,
                                        IWhiteList* pWhiteList)
                                        //const ParserSettings& settings)
{
    uint32_t count = 0;
    RSeqTemplateUint8_t copy = *buffer;
//    RSeq_for_Uint16_t copy(buffer);
//    while (copy.length() > 0)
    while (length_in_HasLength_for_Uint16_t(&(copy.hHasLength)) > 0)
    {
        ParseResult_uint8_t result = ParseHeader_in_APDUParser_static(&copy, /*pLogger,*/ count, /*settings,*/ pHandler, pWhiteList);
        ++count;
        if (result != ParseResult_OK)
        {
            return result;
        }
    }
    return ParseResult_OK;
}

ParseResult_uint8_t ParseHeader_in_APDUParser_static(
                                    RSeq_for_Uint16_t *buffer,
//                                    Logger* pLogger,
                                    uint32_t count,
//                                    const ParserSettings& settings,
                                    IAPDUHandler* pHandler,
                                    IWhiteList* pWhiteList)
{
    ObjectHeader header;
    ParseResult_uint8_t result = ParseObjectHeader_in_ObjectHeaderParser_static(header, buffer);//, pLogger);
    if (result != ParseResult_OK)
    {
        return result;
    }

    GroupVariationRecord GV = GetRecord_in_GroupVariationRecord_static(header.group, header.variation);

    if (GV.enumeration == GroupVariation_UNKNOWN)
    {
////        FORMAT_LOGGER_BLOCK(pLogger, flags::WARN, "Unknown object %i / %i", GV.group, GV.variation);
        return ParseResult::UNKNOWN_OBJECT;
    }

    // if a white-list is defined and it doesn't validate, exit early
////    if (pWhiteList && !pWhiteList->IsAllowed(count, GV.enumeration, QualifierCodeSpec::from_type(header.qualifier)))
     if(pWhiteList && !IsAllowed_in_IWhiteList(pWhiteList, count, GV.enumeration, from_type_in_QualifierCodeSpec(header.qualifier)))
    {
////        FORMAT_LOGGER_BLOCK(pLogger, flags::WARN, "Header (%i) w/ Object (%i,%i) and qualifier (%i) failed whitelist",
////                            count, header.group, header.variation, header.qualifier);

        return ParseResult_NOT_ON_WHITELIST;
    }

    HeaderRecord hHeaderRecord;
    HeaderRecord_in_HeaderRecordOver2(&hHeaderRecord, 
                                      &GV,
                                      header.qualifier, count);
    return ParseQualifier_in_APDUParser_static(buffer, /*pLogger,*/ &hHeaderRecord/*HeaderRecord(GV, header.qualifier, count)*/, /*settings,*/ pHandler);
}

ParseResult_uint8_t ParseQualifier_in_APDUParser_static(
                                    RSeq_for_Uint16_t *buffer,
//                                       Logger* pLogger,
                                    HeaderRecord *record,
//                                       const ParserSettings& settings,
                                    IAPDUHandler* pHandler)
{
    switch (GetQualifierCode_in_HeaderRecord(record))////record.GetQualifierCode())
    {
    case (QualifierCode_ALL_OBJECTS):
        return HandleAllObjectsHeader_in_APDUParser_static(/*pLogger,*/ record, /*settings,*/ pHandler);

    case (QualifierCode_UINT8_CNT):
        return ParseHeader_in_CountParser_static(buffer, OneByte_in_NumParser_static(), /*settings,*/ record, /*pLogger,*/ pHandler);

    case (QualifierCode_UINT16_CNT):
        return ParseHeader_in_CountParser_static(buffer, TwoByte_in_NumParser_static(), /*settings,*/ record, /*pLogger,*/ pHandler);

    case (QualifierCode_UINT8_START_STOP):
        return ParseHeader_in_RangeParser_static(buffer, OneByte_in_NumParser_static(), /*settings,*/ record, /*pLogger,*/ pHandler);

    case (QualifierCode_UINT16_START_STOP):
        return ParseHeader_in_RangeParser_static(buffer, TwoByte_in_NumParser_static(), /*settings,*/ record, /*pLogger,*/ pHandler);

    case (QualifierCode_UINT8_CNT_UINT8_INDEX):
        return ParseHeader_in_CountIndexParser_static(buffer, OneByte_in_NumParser_static(), /*settings,*/ record, /*pLogger,*/ pHandler);

    case (QualifierCode_UINT16_CNT_UINT16_INDEX):
        return ParseHeader_in_CountIndexParser_static(buffer, TwoByte_in_NumParser_static(), /*settings,*/ record, /*pLogger,*/ pHandler);

    default:
////        FORMAT_LOGGER_BLOCK(pLogger, flags::WARN, "Unknown qualifier %x", record.qualifier);
        return ParseResult_UNKNOWN_QUALIFIER;
    }
}

ParseResult_uint8_t HandleAllObjectsHeader_in_APDUParser_static(//Logger* pLogger,
                                               HeaderRecord *record,
//                                               const ParserSettings& settings,
                                               IAPDUHandler* pHandler)
{
////    FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), "%03u,%03u - %s - %s", record.group, record.variation,
////                        GroupVariationSpec::to_human_string(record.enumeration),
////                        QualifierCodeSpec::to_human_string(QualifierCode::ALL_OBJECTS));

    if (pHandler)
    {
        AllObjectsHeader aAllObjectsHeader;
        AllObjectsHeader_in_AllObjectsHeader(&aAllObjectsHeader, record);
////        pHandler->OnHeader(AllObjectsHeader(record));
        pHandler->OnHeader(&aAllObjectsHeader);//AllObjectsHeader(record));
    }

    return ParseResult_OK;
}

////} // namespace opendnp3
