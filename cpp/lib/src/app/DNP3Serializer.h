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
#include "OctetStringSerializer.h"

////namespace opendnp3
////{
//-----------------------------DNP3Serializer_for_BinaryCommandEvent-------------------------------------------
////template<class T> class DNP3Serializer : public Serializer<T>
typedef struct
{
  Serializer_for_BinaryCommandEvent sSerializer_for_BinaryCommandEvent;
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
} DNP3Serializer_for_BinaryCommandEvent;
    GroupVariationID ID_in_DNP3Serializer_for_BinaryCommandEvent(DNP3Serializer_for_BinaryCommandEvent *pDNP3Serializer_for_BinaryCommandEvent);

    void DNP3Serializer_for_BinaryCommandEvent_in_DNP3Serializer_for_BinaryCommandEvent(DNP3Serializer_for_BinaryCommandEvent *pDNP3Serializer_for_BinaryCommandEvent,
                   GroupVariationID id,
                   uint16_t size,
////                   typename Serializer<T>::read_func_t read_func,
                    read_func_t_in_Serializer_for_BinaryCommandEvent read_func,
////                   typename Serializer<T>::write_func_t write_func)
                    write_func_t_in_Serializer_for_BinaryCommandEvent write_func);


//-----------------------------DNP3Serializer_for_BinaryCommandEvent-------------------------------------------
//-----------------------------DNP3Serializer_for_FrozenCounter-------------------------------------------
////template<class T> class DNP3Serializer : public Serializer<T>
typedef struct
{
  Serializer_for_FrozenCounter sSerializer_for_FrozenCounter;
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
} DNP3Serializer_for_FrozenCounter;
    GroupVariationID ID_in_DNP3Serializer_for_FrozenCounter(DNP3Serializer_for_FrozenCounter *pDNP3Serializer_for_FrozenCounter);

    void DNP3Serializer_for_FrozenCounter_in_DNP3Serializer_for_FrozenCounter(DNP3Serializer_for_FrozenCounter *pDNP3Serializer_for_FrozenCounter,
                   GroupVariationID id,
                   uint16_t size,
////                   typename Serializer<T>::read_func_t read_func,
                    read_func_t_in_Serializer_for_FrozenCounter read_func,
////                   typename Serializer<T>::write_func_t write_func)
                    write_func_t_in_Serializer_for_FrozenCounter write_func);


//-----------------------------DNP3Serializer_for_FrozenCounter-------------------------------------------
//-----------------------------DNP3Serializer_for_BinaryOutputStatus-------------------------------------------
////template<class T> class DNP3Serializer : public Serializer<T>
typedef struct
{
  Serializer_for_BinaryOutputStatus sSerializer_for_BinaryOutputStatus;
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
} DNP3Serializer_for_BinaryOutputStatus;
    GroupVariationID ID_in_DNP3Serializer_for_BinaryOutputStatus(DNP3Serializer_for_BinaryOutputStatus *pDNP3Serializer_for_BinaryOutputStatus);

    void DNP3Serializer_for_BinaryOutputStatus_in_DNP3Serializer_for_BinaryOutputStatus(DNP3Serializer_for_BinaryOutputStatus *pDNP3Serializer_for_BinaryOutputStatus,
                   GroupVariationID id,
                   uint16_t size,
////                   typename Serializer<T>::read_func_t read_func,
                    read_func_t_in_Serializer_for_BinaryOutputStatus read_func,// read_func_t_in_Serializer_for_Binary,
////                   typename Serializer<T>::write_func_t write_func)
                    write_func_t_in_Serializer_for_BinaryOutputStatus write_func);//write_func_t_in_Serializer_for_Binary);


//-----------------------------DNP3Serializer_for_BinaryOutputStatus-------------------------------------------
//-----------------------------DNP3Serializer_for_DoubleBitBinary-------------------------------------------
////template<class T> class DNP3Serializer : public Serializer<T>
typedef struct
{
  Serializer_for_DoubleBitBinary sSerializer_for_DoubleBitBinary;
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
} DNP3Serializer_for_DoubleBitBinary;
    GroupVariationID ID_in_DNP3Serializer_for_DoubleBitBinary(DNP3Serializer_for_DoubleBitBinary *pDNP3Serializer_for_DoubleBitBinary);

    void DNP3Serializer_for_DoubleBitBinary_in_DNP3Serializer_for_DoubleBitBinary(DNP3Serializer_for_DoubleBitBinary *pDNP3Serializer_for_DoubleBitBinary,
                   GroupVariationID id,
                   uint16_t size,
////                   typename Serializer<T>::read_func_t read_func,
                    read_func_t_in_Serializer_for_DoubleBitBinary read_func,// read_func_t_in_Serializer_for_Binary,
////                   typename Serializer<T>::write_func_t write_func)
                    write_func_t_in_Serializer_for_DoubleBitBinary write_func);//write_func_t_in_Serializer_for_Binary);


//-----------------------------DNP3Serializer_for_DoubleBitBinary-------------------------------------------
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
//-----------------------------DNP3Serializer_for_AnalogOutputStatus-------------------------------------------
////template<class T> class DNP3Serializer : public Serializer<T>
typedef struct
{
  Serializer_for_AnalogOutputStatus sSerializer_for_AnalogOutputStatus;
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
} DNP3Serializer_for_AnalogOutputStatus;
    GroupVariationID ID_in_DNP3Serializer_for_AnalogOutputStatus(DNP3Serializer_for_AnalogOutputStatus *pDNP3Serializer_for_AnalogOutputStatus);

    void DNP3Serializer_for_AnalogOutputStatus_in_DNP3Serializer_for_AnalogOutputStatus(DNP3Serializer_for_AnalogOutputStatus *pDNP3Serializer_for_AnalogOutputStatus,
                   GroupVariationID id,
                   uint16_t size,
////                   typename Serializer<T>::read_func_t read_func,
                    read_func_t_in_Serializer_for_AnalogOutputStatus read_func,// read_func_t_in_Serializer_for_Binary,
////                   typename Serializer<T>::write_func_t write_func)
                    write_func_t_in_Serializer_for_AnalogOutputStatus write_func);//write_func_t_in_Serializer_for_Binary);


//-----------------------------DNP3Serializer_for_AnalogOutputStatus-------------------------------------------
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
//-----------------------------DNP3Serializer_for_ControlRelayOutputBlock-------------------------------------------
////template<class T> class DNP3Serializer : public Serializer<T>
typedef struct
{
  Serializer_for_ControlRelayOutputBlock sSerializer_for_ControlRelayOutputBlock;
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
} DNP3Serializer_for_ControlRelayOutputBlock;
    GroupVariationID ID_in_DNP3Serializer_for_ControlRelayOutputBlock(DNP3Serializer_for_ControlRelayOutputBlock *pDNP3Serializer_for_ControlRelayOutputBlock);

    void DNP3Serializer_for_ControlRelayOutputBlock_in_DNP3Serializer_for_ControlRelayOutputBlock(DNP3Serializer_for_ControlRelayOutputBlock *pDNP3Serializer_for_ControlRelayOutputBlock,
                   GroupVariationID id,
                   uint16_t size,
////                   typename Serializer<T>::read_func_t read_func,
                    read_func_t_in_Serializer_for_ControlRelayOutputBlock read_func,
////                   typename Serializer<T>::write_func_t write_func)
                    write_func_t_in_Serializer_for_ControlRelayOutputBlock write_func);

//-----------------------------DNP3Serializer_for_ControlRelayOutputBlock-------------------------------------------
//-----------------------------DNP3Serializer_for_AnalogOutputInt16-------------------------------------------
////template<class T> class DNP3Serializer : public Serializer<T>
typedef struct
{
  Serializer_for_AnalogOutputInt16 sSerializer_for_AnalogOutputInt16;
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
} DNP3Serializer_for_AnalogOutputInt16;
    GroupVariationID ID_in_DNP3Serializer_for_AnalogOutputInt16(DNP3Serializer_for_AnalogOutputInt16 *pDNP3Serializer_for_AnalogOutputInt16);

    void DNP3Serializer_for_AnalogOutputInt16_in_DNP3Serializer_for_AnalogOutputInt16(DNP3Serializer_for_AnalogOutputInt16 *pDNP3Serializer_for_AnalogOutputInt16,
                   GroupVariationID id,
                   uint16_t size,
////                   typename Serializer<T>::read_func_t read_func,
                    read_func_t_in_Serializer_for_AnalogOutputInt16 read_func,// read_func_t_in_Serializer_for_Binary,
////                   typename Serializer<T>::write_func_t write_func)
                    write_func_t_in_Serializer_for_AnalogOutputInt16 write_func);//write_func_t_in_Serializer_for_Binary);

//-----------------------------DNP3Serializer_for_AnalogOutputInt16-------------------------------------------
//-----------------------------DNP3Serializer_for_AnalogOutputInt32-------------------------------------------
////template<class T> class DNP3Serializer : public Serializer<T>
typedef struct
{
  Serializer_for_AnalogOutputInt32 sSerializer_for_AnalogOutputInt32;
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
} DNP3Serializer_for_AnalogOutputInt32;
    GroupVariationID ID_in_DNP3Serializer_for_AnalogOutputInt32(DNP3Serializer_for_AnalogOutputInt32 *pDNP3Serializer_for_AnalogOutputInt32);

    void DNP3Serializer_for_AnalogOutputInt32_in_DNP3Serializer_for_AnalogOutputInt32(DNP3Serializer_for_AnalogOutputInt32 *pDNP3Serializer_for_AnalogOutputInt32,
                   GroupVariationID id,
                   uint16_t size,
////                   typename Serializer<T>::read_func_t read_func,
                    read_func_t_in_Serializer_for_AnalogOutputInt32 read_func,// read_func_t_in_Serializer_for_Binary,
////                   typename Serializer<T>::write_func_t write_func)
                    write_func_t_in_Serializer_for_AnalogOutputInt32 write_func);//write_func_t_in_Serializer_for_Binary);

//-----------------------------DNP3Serializer_for_AnalogOutputInt32-------------------------------------------
//-----------------------------DNP3Serializer_for_AnalogOutputFloat32-------------------------------------------
////template<class T> class DNP3Serializer : public Serializer<T>
typedef struct
{
  Serializer_for_AnalogOutputFloat32 sSerializer_for_AnalogOutputFloat32;
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
} DNP3Serializer_for_AnalogOutputFloat32;
    GroupVariationID ID_in_DNP3Serializer_for_AnalogOutputFloat32(DNP3Serializer_for_AnalogOutputFloat32 *pDNP3Serializer_for_AnalogOutputFloat32);

    void DNP3Serializer_for_AnalogOutputFloat32_in_DNP3Serializer_for_AnalogOutputFloat32(DNP3Serializer_for_AnalogOutputFloat32 *pDNP3Serializer_for_AnalogOutputFloat32,
                   GroupVariationID id,
                   uint16_t size,
////                   typename Serializer<T>::read_func_t read_func,
                    read_func_t_in_Serializer_for_AnalogOutputFloat32 read_func,// read_func_t_in_Serializer_for_Binary,
////                   typename Serializer<T>::write_func_t write_func)
                    write_func_t_in_Serializer_for_AnalogOutputFloat32 write_func);//write_func_t_in_Serializer_for_Binary);

//-----------------------------DNP3Serializer_for_AnalogOutputFloat32-------------------------------------------
//-----------------------------DNP3Serializer_for_AnalogOutputDouble64-------------------------------------------
////template<class T> class DNP3Serializer : public Serializer<T>
typedef struct
{
  Serializer_for_AnalogOutputDouble64 sSerializer_for_AnalogOutputDouble64;
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
} DNP3Serializer_for_AnalogOutputDouble64;
    GroupVariationID ID_in_DNP3Serializer_for_AnalogOutputDouble64(DNP3Serializer_for_AnalogOutputDouble64 *pDNP3Serializer_for_AnalogOutputDouble64);

    void DNP3Serializer_for_AnalogOutputDouble64_in_DNP3Serializer_for_AnalogOutputDouble64(DNP3Serializer_for_AnalogOutputDouble64 *pDNP3Serializer_for_AnalogOutputDouble64,
                   GroupVariationID id,
                   uint16_t size,
////                   typename Serializer<T>::read_func_t read_func,
                    read_func_t_in_Serializer_for_AnalogOutputDouble64 read_func,// read_func_t_in_Serializer_for_Binary,
////                   typename Serializer<T>::write_func_t write_func)
                    write_func_t_in_Serializer_for_AnalogOutputDouble64 write_func);//write_func_t_in_Serializer_for_Binary);

//-----------------------------DNP3Serializer_for_AnalogOutputDouble64-------------------------------------------

////} // namespace opendnp3

#endif
