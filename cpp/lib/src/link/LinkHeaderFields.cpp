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
#include "LinkHeaderFields.h"

////namespace opendnp3
////{
////LinkHeaderFields::LinkHeaderFields()
////    : func(LinkFunction::INVALID), isFromMaster(false), fcb(false), fcvdfc(false), addresses(Addresses())
  void LinkHeaderFields_in_LinkHeaderFieldsOver1(LinkHeaderFields *pLinkHeaderFields)
{
   pLinkHeaderFields->func = LinkFunction_INVALID;
   pLinkHeaderFields->isFromMaster = false;
   pLinkHeaderFields->fcb = false;
   pLinkHeaderFields->fcvdfc = false;
//  void Addresses_in_AddressesOver1(Addresses *pAddresses);
//// addresses(Addresses())
   Addresses_in_AddressesOver1(&(pLinkHeaderFields->addresses));
}

////LinkHeaderFields::LinkHeaderFields(LinkFunction func_, bool isMaster_, bool fcb_, bool fcvdfc_, Addresses addresses_)
////    : func(func_), isFromMaster(isMaster_), fcb(fcb_), fcvdfc(fcvdfc_), addresses(addresses_)
  void LinkHeaderFields_in_LinkHeaderFieldsOver2(LinkHeaderFields *pLinkHeaderFields, LinkFunction_uint8_t func_, boolean isMaster_, boolean fcb_, boolean fcvdfc_, Addresses addresses_)
{
   pLinkHeaderFields->func = func_; 
   pLinkHeaderFields->isFromMaster = isMaster_;
   pLinkHeaderFields->fcb = fcb_;
   pLinkHeaderFields->fcvdfc = fcvdfc_;
   pLinkHeaderFields->addresses = addresses_;
}

////} // namespace opendnp3
