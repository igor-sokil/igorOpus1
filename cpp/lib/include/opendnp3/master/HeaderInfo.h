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
#ifndef OPENDNP3_HEADERINFO_H
#define OPENDNP3_HEADERINFO_H

////#include "opendnp3/gen/Attributes.h"
////#include "opendnp3/gen/GroupVariation.h"
////#include "opendnp3/gen/QualifierCode.h"
////#include "opendnp3/gen/TimestampQuality.h"

#include "Attributes.h"
#include "GroupVariation.h"
#include "QualifierCode.h"
#include "TimestampQuality.h"

////namespace opendnp3
////{

/**
 * Simple structure used in the ISOEHandler callbacks to return information
 * about the associated header.
 */
////class HeaderInfo
typedef struct
{
////public:
////    HeaderInfo()
////        : gv(GroupVariation::UNKNOWN),
////          qualifier(QualifierCode::UNDEFINED),
////          tsquality(TimestampQuality::INVALID),
////          isEventVariation(false),
////          flagsValid(false),
////          headerIndex(0)
////    {
////    }
////
////    HeaderInfo(GroupVariation gv_, QualifierCode qualifier_, TimestampQuality tsquality_, uint32_t headerIndex_)
////        : gv(gv_),
////          qualifier(qualifier_),
////          tsquality(tsquality_),
////          isEventVariation(IsEvent(gv_)),
////          flagsValid(HasFlags(gv_)),
////          headerIndex(headerIndex_)
////    {
////    }

    /// The group/variation enumeration for the header
    GroupVariation_uint16_t gv;
    /// The qualifier code enumeration for the header
    QualifierCode_uint8_t qualifier;
    /// Enumeration that provides information about the validity of timestamps on the associated objects
    TimestampQuality_uint8_t tsquality;
    /// True if the specfied variation is an event variation
    boolean isEventVariation;
    /// True if the flags on the value were present on underlying type, false if online is just assumed
    boolean flagsValid;
    /// The 0-based index of the header within the ASDU
    uint32_t headerIndex;
} HeaderInfo;

////} // namespace opendnp3

   void HeaderInfo_in_HeaderInfoOver2(HeaderInfo *pHeaderInfo, GroupVariation_uint16_t gv_, QualifierCode_uint8_t qualifier_,
              TimestampQuality_uint8_t tsquality_, uint32_t headerIndex_);
   void HeaderInfo_in_HeaderInfoOver1(HeaderInfo *pHeaderInfo);


#endif
