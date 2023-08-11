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
////#include "opendnp3/link/Addresses.h"

////#include "link/LinkLayerConstants.h"
#include "header.h"
#include "Addresses.h"

#include "LinkLayerConstants.h"

////namespace opendnp3
////{

boolean IsBroadcast_in_Addresses(Addresses *pAddresses)
{
  return pAddresses->destination == LinkBroadcastAddress_DontConfirm
         || pAddresses->destination == LinkBroadcastAddress_ShallConfirm
         || pAddresses->destination == LinkBroadcastAddress_OptionalConfirm;
}

////} // namespace opendnp3

void Addresses_in_AddressesOver1(Addresses *pAddresses)
{
  pAddresses->source = 0;
  pAddresses->destination = 0;
}

void Addresses_in_AddressesOver2(Addresses *pAddresses, uint16_t source, uint16_t destination)
{
  pAddresses->source = source;
  pAddresses->destination = destination;
}

Addresses Reverse_in_Addresses(Addresses *pAddresses)
{
  Addresses aAddresses;
////    return Addresses(this->destination, this->source);
  Addresses_in_AddressesOver2(&aAddresses, pAddresses->destination, pAddresses->source);
  return aAddresses;
}
