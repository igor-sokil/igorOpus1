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
#ifndef OPENDNP3_DNP3SERIALIZER_H
#define OPENDNP3_DNP3SERIALIZER_H

#include "Serializer.h"

////#include "opendnp3/app/GroupVariationID.h"
#include "GroupVariationID.h"

////namespace opendnp3
////{
//-----------------------------DNP3Serializer_for_Binary-------------------------------------------
////template<class T> class DNP3Serializer : public Serializer<T>
typedef struct
{
  Serializer_for_Binary sSerializer_for_Binary;
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
} DNP3Serializer_for_Binary;
    GroupVariationID ID_in_DNP3Serializer_for_Binary(DNP3Serializer_for_Binary *pDNP3Serializer_for_Binary);

    void DNP3Serializer_for_Binary_in_DNP3Serializer_for_Binary(DNP3Serializer_for_Binary *pDNP3Serializer_for_Binary,
                   GroupVariationID id,
                   uint16_t size,
////                   typename Serializer<T>::read_func_t read_func,
                    read_func_t_in_Serializer_for_Binary read_func,// read_func_t_in_Serializer_for_Binary,
////                   typename Serializer<T>::write_func_t write_func)
                    write_func_t_in_Serializer_for_Binary write_func);//write_func_t_in_Serializer_for_Binary);


//-----------------------------DNP3Serializer_for_Binary-------------------------------------------
//-----------------------------DNP3Serializer_for_Counter-------------------------------------------
////template<class T> class DNP3Serializer : public Serializer<T>
typedef struct
{
  Serializer_for_Counter sSerializer_for_Counter;
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
} DNP3Serializer_for_Counter;
    GroupVariationID ID_in_DNP3Serializer_for_Counter(DNP3Serializer_for_Counter *pDNP3Serializer_for_Counter);

    void DNP3Serializer_for_Counter_in_DNP3Serializer_for_Counter(DNP3Serializer_for_Counter *pDNP3Serializer_for_Counter,
                   GroupVariationID id,
                   uint16_t size,
////                   typename Serializer<T>::read_func_t read_func,
                    read_func_t_in_Serializer_for_Counter read_func,// read_func_t_in_Serializer_for_Binary,
////                   typename Serializer<T>::write_func_t write_func)
                    write_func_t_in_Serializer_for_Counter write_func);//write_func_t_in_Serializer_for_Binary);


//-----------------------------DNP3Serializer_for_Counter-------------------------------------------
//-----------------------------DNP3Serializer_for_Analog-------------------------------------------
////template<class T> class DNP3Serializer : public Serializer<T>
typedef struct
{
  Serializer_for_Analog sSerializer_for_Analog;
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
} DNP3Serializer_for_Analog;
    GroupVariationID ID_in_DNP3Serializer_for_Analog(DNP3Serializer_for_Analog *pDNP3Serializer_for_Analog);

    void DNP3Serializer_for_Analog_in_DNP3Serializer_for_Analog(DNP3Serializer_for_Analog *pDNP3Serializer_for_Analog,
                   GroupVariationID id,
                   uint16_t size,
////                   typename Serializer<T>::read_func_t read_func,
                    read_func_t_in_Serializer_for_Analog read_func,// read_func_t_in_Serializer_for_Binary,
////                   typename Serializer<T>::write_func_t write_func)
                    write_func_t_in_Serializer_for_Analog write_func);//write_func_t_in_Serializer_for_Binary);


//-----------------------------DNP3Serializer_for_Analog-------------------------------------------
//-----------------------------DNP3Serializer_for_TimeAndInterval-------------------------------------------
////template<class T> class DNP3Serializer : public Serializer<T>
typedef struct
{
  Serializer_for_TimeAndInterval sSerializer_for_TimeAndInterval;
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
} DNP3Serializer_for_TimeAndInterval;
    GroupVariationID ID_in_DNP3Serializer_for_TimeAndInterval(DNP3Serializer_for_TimeAndInterval *pDNP3Serializer_for_TimeAndInterval);

    void DNP3Serializer_for_TimeAndInterval_in_DNP3Serializer_for_TimeAndInterval(DNP3Serializer_for_TimeAndInterval *pDNP3Serializer_for_TimeAndInterval,
                   GroupVariationID id,
                   uint16_t size,
////                   typename Serializer<T>::read_func_t read_func,
                    read_func_t_in_Serializer_for_TimeAndInterval read_func,// read_func_t_in_Serializer_for_Binary,
////                   typename Serializer<T>::write_func_t write_func)
                    write_func_t_in_Serializer_for_TimeAndInterval write_func);//write_func_t_in_Serializer_for_Binary);


//-----------------------------DNP3Serializer_for_TimeAndInterval-------------------------------------------

////} // namespace opendnp3

#endif
