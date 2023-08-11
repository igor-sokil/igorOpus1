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
#include "header.h"
#include "RequestHistory.h"

#include "CRC.h"
////namespace opendnp3
////{

void RequestHistory_in_RequestHistory(RequestHistory *pRequestHistory)
{
  pRequestHistory->hasLast = false;
  pRequestHistory->lastDigest = 0;
  pRequestHistory->lastObjectsLength = 0;
}

void Reset_in_RequestHistory(RequestHistory *pRequestHistory)
{
  pRequestHistory->hasLast = false;
}

void RecordLastProcessedRequest_in_RequestHistory(RequestHistory *pRequestHistory, APDUHeader* header, RSeq_for_Uint16_t* objects)
{
  pRequestHistory->hasLast = true;
  pRequestHistory->lastHeader = *header;
//    uint16_t length_in_HasLength_for_Uint16_t(HasLength_for_Uint16_t *pHasLength);
  pRequestHistory->lastObjectsLength = length_in_HasLength_for_Uint16_t(&(objects->hHasLength));////objects.length();
// uint16_t CalcCrc_in_CRC_staticOver2(RSeq_for_Uint16_t* view);
  pRequestHistory->lastDigest = CalcCrc_in_CRC_staticOver2(objects);
}

boolean FullyEqualsLastRequest_in_RequestHistory(RequestHistory *pRequestHistory, APDUHeader* header, RSeq_for_Uint16_t* objects)
{
//   boolean Equals_in_APDUHeader(APDUHeader *pAPDUHeader, APDUHeader *header);
//   boolean EqualsLastObjects_in_RequestHistory(RequestHistory *pRequestHistory, RSeq_for_Uint16_t objects);
////    return lastHeader.Equals(header) && EqualsLastObjects(objects);
  return  Equals_in_APDUHeader(&(pRequestHistory->lastHeader), header) && EqualsLastObjects_in_RequestHistory(pRequestHistory, objects);
}

APDUHeader GetLastHeader_in_RequestHistory(RequestHistory *pRequestHistory)
{
//   void APDUHeader_in_APDUHeaderOver1(APDUHeader*);
////    return hasLast ? lastHeader : APDUHeader();
  APDUHeader aAPDUHeader;
  APDUHeader_in_APDUHeaderOver1(&aAPDUHeader);
  return pRequestHistory->hasLast ? pRequestHistory->lastHeader : aAPDUHeader;
}

boolean EqualsLastObjects_in_RequestHistory(RequestHistory *pRequestHistory, RSeq_for_Uint16_t* objects)
{
//    uint16_t length_in_HasLength_for_Uint16_t(HasLength_for_Uint16_t *pHasLength);
// uint16_t CalcCrc_in_CRC_staticOver2(RSeq_for_Uint16_t* view);
////    return hasLast && (lastObjectsLength == objects.length()) && (lastDigest == CRC::CalcCrc(objects));
  return pRequestHistory->hasLast &&
         (pRequestHistory->lastObjectsLength == length_in_HasLength_for_Uint16_t(&(objects->hHasLength))) &&
         (pRequestHistory->lastDigest == CalcCrc_in_CRC_staticOver2(objects));
}

////} // namespace opendnp3
boolean HasLastRequest_in_RequestHistory(RequestHistory *pRequestHistory)
{
  return pRequestHistory->hasLast;
}

