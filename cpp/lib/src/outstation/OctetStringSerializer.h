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
#ifndef OPENDNP3_OCTETSTRINGSERIALIZER_H
#define OPENDNP3_OCTETSTRINGSERIALIZER_H

////#include "app/DNP3Serializer.h"

////#include "opendnp3/app/OctetString.h"

#include "DNP3Serializer.h"

#include "OctetString.h"

////namespace opendnp3
////{

////template<class T> class DNP3Serializer : public Serializer<T>
typedef struct
{
  Serializer_for_OctetString sSerializer_for_OctetString;
////public:
////    DNP3Serializer(GroupVariationID id,
////                   size_t size,
////                   typename Serializer<T>::read_func_t read_func,
////                   typename Serializer<T>::write_func_t write_func)
////        : Serializer<T>(size, read_func, write_func), id(id)
////    {
////    }

////    GroupVariationID ID() const
////    {
////        return id;
////    }

////private:
  GroupVariationID id;
} DNP3Serializer_for_OctetString;
GroupVariationID ID_in_DNP3Serializer_for_OctetString(DNP3Serializer_for_OctetString *pDNP3Serializer_for_OctetString);

void DNP3Serializer_for_OctetString_in_DNP3Serializer_for_OctetString(DNP3Serializer_for_OctetString *pDNP3Serializer_for_OctetString,
    GroupVariationID id,
    uint16_t size,
////                   typename Serializer<T>::read_func_t read_func,
    read_func_t_in_Serializer_for_OctetString read_func,
////                   typename Serializer<T>::write_func_t write_func)
    write_func_t_in_Serializer_for_OctetString write_func);


////struct OctetStringSerializer : public DNP3Serializer<OctetString>
typedef struct
{
  DNP3Serializer_for_OctetString dDNP3Serializer_for_OctetString;
////    OctetStringSerializer(bool isEvent, uint8_t size);

////    static bool Write(const OctetString& value, ser4cpp::wseq_t& buffer);
} OctetStringSerializer;

void OctetStringSerializer_in_OctetStringSerializer(boolean isEvent, uint8_t size);
boolean Write_in_OctetStringSerializer_static(OctetString* value, WSeq_for_Uint16_t* buffer);

////} // namespace opendnp3

#endif
