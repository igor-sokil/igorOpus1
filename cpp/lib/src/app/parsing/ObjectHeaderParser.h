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
#ifndef OPENDNP3_OBJECTHEADERPARSER_H
#define OPENDNP3_OBJECTHEADERPARSER_H

////#include "app/parsing/ParseResult.h"

////#include "opendnp3/gen/GroupVariation.h"
////#include "opendnp3/logging/Logger.h"
////#include "opendnp3/util/StaticOnly.h"

////#include <ser4cpp/container/SequenceTypes.h>

#include "ParseResult.h"

#include "GroupVariation.h"
//#include "opendnp3/logging/Logger.h"
//#include "opendnp3/util/StaticOnly.h"

//#include <ser4cpp/container/SequenceTypes.h>
#include "RSeq.h"


////namespace opendnp3
////{

////class ObjectHeader
typedef struct
{
////public:
////    ObjectHeader();

    uint8_t group;
    uint8_t variation;
    uint8_t qualifier;
} ObjectHeader;

void ObjectHeader_in_ObjectHeader(ObjectHeader *pObjectHeader);

////class ObjectHeaderParser : private StaticOnly
////{
////public:
////    static ParseResult ParseObjectHeader(ObjectHeader& header, ser4cpp::rseq_t& buffer, Logger* pLogger);

    // Provides stateless inspection of the first object header, provided that it exists
    // return false on failure (e.g. < 3 bytes)
////    static bool ReadFirstGroupVariation(const ser4cpp::rseq_t& objects, GroupVariation& gv);
////};

    ParseResult_uint8_t ParseObjectHeader_in_ObjectHeaderParser_static(ObjectHeader *header, RSeq_for_Uint16_t *buffer);////, Logger* pLogger);
    boolean ReadFirstGroupVariation_in_ObjectHeaderParser_static(RSeq_for_Uint16_t *objects, GroupVariation *gv);

////} // namespace opendnp3

#endif
