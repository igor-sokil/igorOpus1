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
////#include "APDUHeaderParser.h"

////#include "app/APDUHeader.h"
////#include "logging/LogMacros.h"

////#include "opendnp3/logging/LogLevels.h"
////#include "opendnp3/util/Uncopyable.h"

////#include <ser4cpp/container/SequenceTypes.h>
#include <QtWidgets>
#include "header.h"
#include "APDUHeaderParser.h"

#include "APDUHeader.h"
#include "Rseq.h"
//#include "logging/LogMacros.h"

//#include "opendnp3/logging/LogLevels.h"
//#include "opendnp3/util/Uncopyable.h"

//#include <SequenceTypes.h>

////namespace opendnp3
////{

////APDUHeaderParser::Result<APDUHeader> APDUHeaderParser::ParseRequest(const ser4cpp::rseq_t& apdu, Logger* logger)
Result_for_APDUHeader_in_APDUHeaderParser ParseRequest_in_APDUHeaderParser_static(RSeq_for_Uint16_t *apdu)////, Logger* logger = nullptr);
{
qDebug()<<"";
qDebug()<<"ParseRequest_in_APDUHeaderParser_static1";
  if (length_in_HasLength_for_Uint16_t(&(apdu->hHasLength)) < APDUHeader_REQUEST_SIZE)
  {
////        FORMAT_LOGGER_BLOCK(logger, flags::WARN, "Request fragment  with insufficient size of %zu bytes",
////                            apdu.length());
qDebug()<<"ParseRequest_in_APDUHeaderParser_static2";
    return Error_in_Result_for_APDUHeader_static();
////Result<APDUHeader>::Error();
  }
qDebug()<<"ParseRequest_in_APDUHeaderParser_static3";

  AppControlField aAppControlField;
  AppControlField_in_AppControlFieldOver2(&aAppControlField, (apdu->buffer_)[0]);
  APDUHeader aAPDUHeader;
  APDUHeader_in_APDUHeaderOver2(&aAPDUHeader, &aAppControlField, from_type_in_FunctionCodeSpec((apdu->buffer_)[1]));
  RSeq_for_Uint16_t rRSeq = skip_in_RSeq_for_Uint16_t(apdu, APDUHeader_REQUEST_SIZE);

//Result_for_APDUHeader_in_APDUHeaderParser Ok_in_Result_for_APDUHeader_static(APDUHeader *header, RSeq_for_Uint16_t *objects);
  return Ok_in_Result_for_APDUHeader_static(&aAPDUHeader, &rRSeq);
////Result<APDUHeader>::Ok(APDUHeader(AppControlField(apdu[0]), FunctionCodeSpec::from_type(apdu[1])),
////                                  apdu.skip(APDUHeader::REQUEST_SIZE));
}

////APDUHeaderParser::Result<APDUResponseHeader> APDUHeaderParser::ParseResponse(const ser4cpp::rseq_t& apdu,
////                                                                             Logger* logger)
////    Result_for_APDUResponseHeader ParseResponse_in_APDUHeaderParser_static(RSeqSer4cpp *apdu)////, Logger* logger = nullptr);
Result_for_APDUResponseHeader_in_APDUHeaderParser ParseResponse_in_APDUHeaderParser_static(RSeq_for_Uint16_t *apdu)////, Logger* logger = nullptr);
{
  if (length_in_HasLength_for_Uint16_t(&(apdu->hHasLength)) < APDUHeader_RESPONSE_SIZE)
  {
////        FORMAT_LOGGER_BLOCK(logger, flags::WARN, "Response fragment  with insufficient size of %zu bytes",
////                            apdu.length());
    return Error_in_Result_for_APDUResponseHeader_static();
  }

////    return Result<APDUResponseHeader>::Ok(
////       APDUResponseHeader(AppControlField(apdu[0]), FunctionCodeSpec::from_type(apdu[1]), IINField(apdu[2], apdu[3])),
////        apdu.skip(APDUHeader::RESPONSE_SIZE));
  IINField iIINField;
  IINField_in_IINFieldOver3(&iIINField, (apdu->buffer_)[2], (apdu->buffer_)[3]);
  AppControlField aAppControlField;
  AppControlField_in_AppControlFieldOver2(&aAppControlField, (apdu->buffer_)[0]);

  APDUResponseHeader aAPDUResponseHeader;
  APDUResponseHeader_in_APDUResponseHeaderOver2(&aAPDUResponseHeader, &aAppControlField, from_type_in_FunctionCodeSpec((apdu->buffer_)[1]), &iIINField);
  RSeq_for_Uint16_t rRSeq = skip_in_RSeq_for_Uint16_t(apdu, APDUHeader_RESPONSE_SIZE);
  return Ok_in_Result_for_APDUResponseHeader_static(&aAPDUResponseHeader, &rRSeq);
}

////} // namespace opendnp3

Result_for_APDUHeader_in_APDUHeaderParser Ok_in_Result_for_APDUHeader_static(APDUHeader *header, RSeq_for_Uint16_t *objects)
{
  Result_for_APDUHeader_in_APDUHeaderParser rResult_for_APDUHeader;
  Result_for_APDUHeader_in_Result_for_APDUHeaderOver2(&rResult_for_APDUHeader, header, objects);
  return rResult_for_APDUHeader;
}

Result_for_APDUHeader_in_APDUHeaderParser Error_in_Result_for_APDUHeader_static(void)
{
  Result_for_APDUHeader_in_APDUHeaderParser rResult_for_APDUHeader;
  Result_for_APDUHeader_in_Result_for_APDUHeaderOver1(&rResult_for_APDUHeader);
  return rResult_for_APDUHeader;
}

void Result_for_APDUHeader_in_Result_for_APDUHeaderOver2(Result_for_APDUHeader_in_APDUHeaderParser *pResult_for_APDUHeader,
    APDUHeader *header, RSeq_for_Uint16_t *objects)
{
  pResult_for_APDUHeader->success = true;
  pResult_for_APDUHeader->header = *header;
  pResult_for_APDUHeader->objects = *objects;
}

void Result_for_APDUHeader_in_Result_for_APDUHeaderOver1(Result_for_APDUHeader_in_APDUHeaderParser *pResult_for_APDUHeader)
{
  pResult_for_APDUHeader->success = false;
}

Result_for_APDUResponseHeader_in_APDUHeaderParser Ok_in_Result_for_APDUResponseHeader_static(APDUResponseHeader *header, RSeq_for_Uint16_t *objects)
{
  Result_for_APDUResponseHeader_in_APDUHeaderParser rResult_for_APDUResponseHeader;
  Result_for_APDUResponseHeader_in_Result_for_APDUResponseHeaderOver2(&rResult_for_APDUResponseHeader, header, objects);
  return rResult_for_APDUResponseHeader;
}

Result_for_APDUResponseHeader_in_APDUHeaderParser Error_in_Result_for_APDUResponseHeader_static(void)
{
  Result_for_APDUResponseHeader_in_APDUHeaderParser rResult_for_APDUResponseHeader;
  Result_for_APDUResponseHeader_in_Result_for_APDUResponseHeaderOver1(&rResult_for_APDUResponseHeader);
  return rResult_for_APDUResponseHeader;
}

void Result_for_APDUResponseHeader_in_Result_for_APDUResponseHeaderOver2(Result_for_APDUResponseHeader_in_APDUHeaderParser *pResult_for_APDUResponseHeader,
    APDUResponseHeader *header, RSeq_for_Uint16_t *objects)
{
  pResult_for_APDUResponseHeader->success = true;
  pResult_for_APDUResponseHeader->header = *header;
  pResult_for_APDUResponseHeader->objects = *objects;
}

void Result_for_APDUResponseHeader_in_Result_for_APDUResponseHeaderOver1(Result_for_APDUResponseHeader_in_APDUHeaderParser *pResult_for_APDUResponseHeader)
{
  pResult_for_APDUResponseHeader->success = false;
}
