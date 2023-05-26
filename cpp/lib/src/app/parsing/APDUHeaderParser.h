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
#ifndef OPENDNP3_APDUHEADERPARSER_H
#define OPENDNP3_APDUHEADERPARSER_H

////#include "app/APDUHeader.h"

////#include "opendnp3/logging/Logger.h"
////#include "opendnp3/util/StaticOnly.h"

////#include <ser4cpp/container/SequenceTypes.h>

#include "APDUHeader.h"
#include "RSeq.h"

//#include "opendnp3/logging/Logger.h"
//#include "opendnp3/util/StaticOnly.h"

//#include <SequenceTypes.h>

////namespace opendnp3
////{

////class APDUHeaderParser : private StaticOnly
////{

////public:
////    template<class T> class Result

typedef struct
    {
////    public:
        boolean success;
        APDUHeader header;
        RSeq_for_Uint16_t objects;


////    private:

    } Result_for_APDUHeader_in_APDUHeaderParser;

        Result_for_APDUHeader_in_APDUHeaderParser Ok_in_Result_for_APDUHeader_static(APDUHeader *header, RSeq_for_Uint16_t *objects);
        Result_for_APDUHeader_in_APDUHeaderParser Error_in_Result_for_APDUHeader_static(void);
        void Result_for_APDUHeader_in_Result_for_APDUHeaderOver1(Result_for_APDUHeader_in_APDUHeaderParser *pResult_for_APDUHeader);
        void Result_for_APDUHeader_in_Result_for_APDUHeaderOver2(Result_for_APDUHeader_in_APDUHeaderParser *pResult_for_APDUHeader, 
                                                                 APDUHeader *header, RSeq_for_Uint16_t *objects);


typedef struct
    {
////    public:
        boolean success;
        APDUResponseHeader header;
        RSeq_for_Uint16_t objects;
    } Result_for_APDUResponseHeader_in_APDUHeaderParser;

        Result_for_APDUResponseHeader_in_APDUHeaderParser Ok_in_Result_for_APDUResponseHeader_static(APDUResponseHeader *header, RSeq_for_Uint16_t *objects);
        Result_for_APDUResponseHeader_in_APDUHeaderParser Error_in_Result_for_APDUResponseHeader_static(void);
        void Result_for_APDUResponseHeader_in_Result_for_APDUResponseHeaderOver1(Result_for_APDUResponseHeader_in_APDUHeaderParser *pResult_for_APDUResponseHeader);
        void Result_for_APDUResponseHeader_in_Result_for_APDUResponseHeaderOver2(Result_for_APDUResponseHeader_in_APDUHeaderParser *pResult_for_APDUResponseHeader, 
                                                                 APDUResponseHeader *header, RSeq_for_Uint16_t *objects);


    Result_for_APDUHeader_in_APDUHeaderParser         ParseRequest_in_APDUHeaderParser_static(RSeq_for_Uint16_t *apdu);////, Logger* logger = nullptr);
    Result_for_APDUResponseHeader_in_APDUHeaderParser ParseResponse_in_APDUHeaderParser_static(RSeq_for_Uint16_t *apdu);////, Logger* logger = nullptr);

////};

////} // namespace opendnp3

#endif
