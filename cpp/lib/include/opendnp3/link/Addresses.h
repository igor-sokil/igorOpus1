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
#ifndef OPENDNP3_ADDRESSES_H
#define OPENDNP3_ADDRESSES_H

////#include <cstdint>

////namespace opendnp3
////{

////struct Addresses
typedef struct
{
////    Addresses() = default;

////    Addresses(uint16_t source, uint16_t destination) : source(source), destination(destination) {}

////    Addresses Reverse() const
////    {
////        return Addresses(this->destination, this->source);
////    }

////    inline bool operator==(const Addresses& other) const
////    {
////        return (this->source == other.source) && (this->destination == other.destination);
////    }

////    inline bool operator!=(const Addresses& other) const
////    {
////        return !((*this) == other);
////    }

////    bool IsBroadcast() const;

  uint16_t source;// = 0;
  uint16_t destination;// = 0;
} Addresses;

boolean IsBroadcast_in_Addresses(Addresses *pAddresses);
Addresses Reverse_in_Addresses(Addresses *pAddresses);
void Addresses_in_AddressesOver2(Addresses *pAddresses, uint16_t source, uint16_t destination);
void Addresses_in_AddressesOver1(Addresses *pAddresses);
boolean operatorNOTEQ_in_Addresses(Addresses *pAddresses, Addresses* other);
boolean operatorEQ_in_Addresses(Addresses *pAddresses, Addresses* other);



////} // namespace opendnp3

#endif
