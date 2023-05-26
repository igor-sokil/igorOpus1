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
#ifndef OPENDNP3_RESPONSEINFO_H
#define OPENDNP3_RESPONSEINFO_H

////namespace opendnp3
////{

/**
 * provides basic information about an APDU response
 */
////struct ResponseInfo
typedef struct
{
////    ResponseInfo(bool unsolicited, bool fir, bool fin) : unsolicited(unsolicited), fir(fir), fin(fin) {}

    // true if the response is unsolicited
    boolean unsolicited;
    // true if this is the first fragment in a multi-fragment response
    boolean fir;
    // true if this is the final fragment in a multi-fragment response
    boolean fin;
} ResponseInfo;

 void ResponseInfo_in_ResponseInfo(ResponseInfo *pResponseInfo, boolean unsolicited, boolean fir, boolean fin);

////} // namespace opendnp3

#endif
