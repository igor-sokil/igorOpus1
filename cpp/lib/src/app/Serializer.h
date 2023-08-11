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
#ifndef OPENDNP3_SERIALIZER_H
#define OPENDNP3_SERIALIZER_H

#include "RSeq.h"
#include "WSeq.h"
#include "AnalogOutput.h"
#include "MeasurementTypes.h"
#include "OctetString.h"
#include "ControlRelayOutputBlock.h"
#include "BinaryCommandEvent.h"

////#include <ser4cpp/container/SequenceTypes.h>

////namespace opendnp3
////{
//------------------------Serializer_for_BinaryCommandEvent----------------------------------------------------

typedef boolean (*read_func_t_in_Serializer_for_BinaryCommandEvent) (RSeq_for_Uint16_t *buffer, BinaryCommandEvent *output);
typedef boolean (*write_func_t_in_Serializer_for_BinaryCommandEvent)(BinaryCommandEvent *value, WSeq_for_Uint16_t *buffer);

////template<class T> class Serializer
typedef struct
{
////public:
////    using read_func_t = bool (*)(ser4cpp::rseq_t& buffer, T& output);
////    using write_func_t = bool (*)(const T& value, ser4cpp::wseq_t& buffer);

////    Serializer() = default;

////    Serializer(size_t size, read_func_t read_func, write_func_t write_func)
////        : size(size), read_func(read_func), write_func(write_func)
////    {
////    }

  /**
   * @return The size (in bytes) required for every call to read/write
   */
////    size_t get_size() const
////    {
////        return size;
////    }

  /**
   * reads the value and advances the read buffer
   */
////    bool read(ser4cpp::rseq_t& buffer, T& output) const
////    {
////        return (*read_func)(buffer, output);
////    }

  /**
   * writes the value and advances the write buffer
   */
////    bool write(const T& value, ser4cpp::wseq_t& buffer) const
////    {
////        return (*write_func)(value, buffer);
////    }

////private:
  ////size_t size = 0;
////    read_func_t read_func = nullptr;
////    write_func_t write_func = nullptr;
  uint16_t size;
  read_func_t_in_Serializer_for_BinaryCommandEvent  read_func;
  write_func_t_in_Serializer_for_BinaryCommandEvent write_func;

} Serializer_for_BinaryCommandEvent;
////} // namespace opendnp3


uint16_t get_size_in_Serializer_for_BinaryCommandEvent(Serializer_for_BinaryCommandEvent *pSerializer_for_BinaryCommandEvent);
boolean read_in_Serializer_for_BinaryCommandEvent(Serializer_for_BinaryCommandEvent *pSerializer_for_BinaryCommandEvent, RSeq_for_Uint16_t *buffer, BinaryCommandEvent *output);
boolean write_in_Serializer_for_BinaryCommandEvent(Serializer_for_BinaryCommandEvent *pSerializer_for_BinaryCommandEvent, BinaryCommandEvent *value, WSeq_for_Uint16_t *buffer);

void Serializer_for_BinaryCommandEvent_in_Serializer_for_BinaryCommandEvent(Serializer_for_BinaryCommandEvent *pSerializer_for_BinaryCommandEvent,
    uint16_t size,
    read_func_t_in_Serializer_for_BinaryCommandEvent read_func,
    write_func_t_in_Serializer_for_BinaryCommandEvent write_func);


//------------------------Serializer_for_BinaryCommandEvent----------------------------------------------------
//------------------------Serializer_for_FrozenCounter----------------------------------------------------

typedef boolean (*read_func_t_in_Serializer_for_FrozenCounter) (RSeq_for_Uint16_t *buffer, FrozenCounter *output);
typedef boolean (*write_func_t_in_Serializer_for_FrozenCounter)(FrozenCounter *value, WSeq_for_Uint16_t *buffer);

////template<class T> class Serializer
typedef struct
{
////public:
////    using read_func_t = bool (*)(ser4cpp::rseq_t& buffer, T& output);
////    using write_func_t = bool (*)(const T& value, ser4cpp::wseq_t& buffer);

////    Serializer() = default;

////    Serializer(size_t size, read_func_t read_func, write_func_t write_func)
////        : size(size), read_func(read_func), write_func(write_func)
////    {
////    }

  /**
   * @return The size (in bytes) required for every call to read/write
   */
////    size_t get_size() const
////    {
////        return size;
////    }

  /**
   * reads the value and advances the read buffer
   */
////    bool read(ser4cpp::rseq_t& buffer, T& output) const
////    {
////        return (*read_func)(buffer, output);
////    }

  /**
   * writes the value and advances the write buffer
   */
////    bool write(const T& value, ser4cpp::wseq_t& buffer) const
////    {
////        return (*write_func)(value, buffer);
////    }

////private:
  ////size_t size = 0;
////    read_func_t read_func = nullptr;
////    write_func_t write_func = nullptr;
  uint16_t size;
  read_func_t_in_Serializer_for_FrozenCounter  read_func;
  write_func_t_in_Serializer_for_FrozenCounter write_func;

} Serializer_for_FrozenCounter;
////} // namespace opendnp3


uint16_t get_size_in_Serializer_for_FrozenCounter(Serializer_for_FrozenCounter *pSerializer_for_FrozenCounter);
boolean read_in_Serializer_for_FrozenCounter(Serializer_for_FrozenCounter *pSerializer_for_FrozenCounter, RSeq_for_Uint16_t *buffer, FrozenCounter *output);
boolean write_in_Serializer_for_FrozenCounter(Serializer_for_FrozenCounter *pSerializer_for_FrozenCounter, FrozenCounter *value, WSeq_for_Uint16_t *buffer);

void Serializer_for_FrozenCounter_in_Serializer_for_FrozenCounter(Serializer_for_FrozenCounter *pSerializer_for_FrozenCounter,
    uint16_t size,
    read_func_t_in_Serializer_for_FrozenCounter read_func,
    write_func_t_in_Serializer_for_FrozenCounter write_func);


//------------------------Serializer_for_FrozenCounter----------------------------------------------------
//------------------------Serializer_for_BinaryOutputStatus----------------------------------------------------

typedef boolean (*read_func_t_in_Serializer_for_BinaryOutputStatus) (RSeq_for_Uint16_t *buffer, BinaryOutputStatus *output);
typedef boolean (*write_func_t_in_Serializer_for_BinaryOutputStatus)(BinaryOutputStatus *value, WSeq_for_Uint16_t *buffer);

////template<class T> class Serializer
typedef struct
{
////public:
////    using read_func_t = bool (*)(ser4cpp::rseq_t& buffer, T& output);
////    using write_func_t = bool (*)(const T& value, ser4cpp::wseq_t& buffer);

////    Serializer() = default;

////    Serializer(size_t size, read_func_t read_func, write_func_t write_func)
////        : size(size), read_func(read_func), write_func(write_func)
////    {
////    }

  /**
   * @return The size (in bytes) required for every call to read/write
   */
////    size_t get_size() const
////    {
////        return size;
////    }

  /**
   * reads the value and advances the read buffer
   */
////    bool read(ser4cpp::rseq_t& buffer, T& output) const
////    {
////        return (*read_func)(buffer, output);
////    }

  /**
   * writes the value and advances the write buffer
   */
////    bool write(const T& value, ser4cpp::wseq_t& buffer) const
////    {
////        return (*write_func)(value, buffer);
////    }

////private:
  ////size_t size = 0;
////    read_func_t read_func = nullptr;
////    write_func_t write_func = nullptr;
  uint16_t size;
  read_func_t_in_Serializer_for_BinaryOutputStatus  read_func;
  write_func_t_in_Serializer_for_BinaryOutputStatus write_func;

} Serializer_for_BinaryOutputStatus;
////} // namespace opendnp3


uint16_t get_size_in_Serializer_for_BinaryOutputStatus(Serializer_for_BinaryOutputStatus *pSerializer_for_BinaryOutputStatus);
boolean read_in_Serializer_for_BinaryOutputStatus(Serializer_for_BinaryOutputStatus *pSerializer_for_BinaryOutputStatus, RSeq_for_Uint16_t *buffer, BinaryOutputStatus *output);
boolean write_in_Serializer_for_BinaryOutputStatus(Serializer_for_BinaryOutputStatus *pSerializer_for_BinaryOutputStatus, BinaryOutputStatus *value, WSeq_for_Uint16_t *buffer);

void Serializer_for_BinaryOutputStatus_in_Serializer_for_BinaryOutputStatus(Serializer_for_BinaryOutputStatus *pSerializer_for_BinaryOutputStatus,
    uint16_t size,
    read_func_t_in_Serializer_for_BinaryOutputStatus read_func,
    write_func_t_in_Serializer_for_BinaryOutputStatus write_func);


//------------------------Serializer_for_BinaryOutputStatus----------------------------------------------------
//------------------------Serializer_for_DoubleBitBinary----------------------------------------------------

typedef boolean (*read_func_t_in_Serializer_for_DoubleBitBinary) (RSeq_for_Uint16_t *buffer, DoubleBitBinary *output);
typedef boolean (*write_func_t_in_Serializer_for_DoubleBitBinary)(DoubleBitBinary *value, WSeq_for_Uint16_t *buffer);

////template<class T> class Serializer
typedef struct
{
////public:
////    using read_func_t = bool (*)(ser4cpp::rseq_t& buffer, T& output);
////    using write_func_t = bool (*)(const T& value, ser4cpp::wseq_t& buffer);

////    Serializer() = default;

////    Serializer(size_t size, read_func_t read_func, write_func_t write_func)
////        : size(size), read_func(read_func), write_func(write_func)
////    {
////    }

  /**
   * @return The size (in bytes) required for every call to read/write
   */
////    size_t get_size() const
////    {
////        return size;
////    }

  /**
   * reads the value and advances the read buffer
   */
////    bool read(ser4cpp::rseq_t& buffer, T& output) const
////    {
////        return (*read_func)(buffer, output);
////    }

  /**
   * writes the value and advances the write buffer
   */
////    bool write(const T& value, ser4cpp::wseq_t& buffer) const
////    {
////        return (*write_func)(value, buffer);
////    }

////private:
  ////size_t size = 0;
////    read_func_t read_func = nullptr;
////    write_func_t write_func = nullptr;
  uint16_t size;
  read_func_t_in_Serializer_for_DoubleBitBinary  read_func;
  write_func_t_in_Serializer_for_DoubleBitBinary write_func;

} Serializer_for_DoubleBitBinary;
////} // namespace opendnp3


uint16_t get_size_in_Serializer_for_DoubleBitBinary(Serializer_for_DoubleBitBinary *pSerializer_for_DoubleBitBinary);
boolean read_in_Serializer_for_DoubleBitBinary(Serializer_for_DoubleBitBinary *pSerializer_for_DoubleBitBinary, RSeq_for_Uint16_t *buffer, DoubleBitBinary *output);
boolean write_in_Serializer_for_DoubleBitBinary(Serializer_for_DoubleBitBinary *pSerializer_for_DoubleBitBinary, DoubleBitBinary *value, WSeq_for_Uint16_t *buffer);

void Serializer_for_DoubleBitBinary_in_Serializer_for_DoubleBitBinary(Serializer_for_DoubleBitBinary *pSerializer_for_DoubleBitBinary,
    uint16_t size,
    read_func_t_in_Serializer_for_DoubleBitBinary read_func,
    write_func_t_in_Serializer_for_DoubleBitBinary write_func);


//------------------------Serializer_for_DoubleBitBinary----------------------------------------------------
//------------------------Serializer_for_Binary----------------------------------------------------

typedef boolean (*read_func_t_in_Serializer_for_Binary) (RSeq_for_Uint16_t *buffer, Binary *output);
typedef boolean (*write_func_t_in_Serializer_for_Binary)(Binary *value, WSeq_for_Uint16_t *buffer);
//#define POINTER_read_func_t_in_Serializer_for_Binary_FUNCTION(function)   (*(read_func_t_in_Serializer_for_Binary *)function)
//#define POINTER_write_func_t_in_Serializer_for_Binary_FUNCTION(function)  (*(write_func_t_in_Serializer_for_Binary *)function)

////template<class T> class Serializer
typedef struct
{
////public:
////    using read_func_t = bool (*)(ser4cpp::rseq_t& buffer, T& output);
////    using write_func_t = bool (*)(const T& value, ser4cpp::wseq_t& buffer);

////    Serializer() = default;

////    Serializer(size_t size, read_func_t read_func, write_func_t write_func)
////        : size(size), read_func(read_func), write_func(write_func)
////    {
////    }

  /**
   * @return The size (in bytes) required for every call to read/write
   */
////    size_t get_size() const
////    {
////        return size;
////    }

  /**
   * reads the value and advances the read buffer
   */
////    bool read(ser4cpp::rseq_t& buffer, T& output) const
////    {
////        return (*read_func)(buffer, output);
////    }

  /**
   * writes the value and advances the write buffer
   */
////    bool write(const T& value, ser4cpp::wseq_t& buffer) const
////    {
////        return (*write_func)(value, buffer);
////    }

////private:
  ////size_t size = 0;
////    read_func_t read_func = nullptr;
////    write_func_t write_func = nullptr;
  uint16_t size;
  read_func_t_in_Serializer_for_Binary  read_func;
  write_func_t_in_Serializer_for_Binary write_func;

} Serializer_for_Binary;
////} // namespace opendnp3


uint16_t get_size_in_Serializer_for_Binary(Serializer_for_Binary *pSerializer_for_Binary);
boolean read_in_Serializer_for_Binary(Serializer_for_Binary *pSerializer_for_Binary, RSeq_for_Uint16_t *buffer, Binary *output);
boolean write_in_Serializer_for_Binary(Serializer_for_Binary *pSerializer_for_Binary, Binary *value, WSeq_for_Uint16_t *buffer);

void Serializer_for_Binary_in_Serializer_for_Binary(Serializer_for_Binary *pSerializer_for_Binary,
    uint16_t size,
    read_func_t_in_Serializer_for_Binary read_func,
    write_func_t_in_Serializer_for_Binary write_func);


//------------------------Serializer_for_Binary----------------------------------------------------
//------------------------Serializer_for_OctetString----------------------------------------------------

typedef boolean (*read_func_t_in_Serializer_for_OctetString) (RSeq_for_Uint16_t *buffer, OctetString *output);
typedef boolean (*write_func_t_in_Serializer_for_OctetString)(OctetString *value, WSeq_for_Uint16_t *buffer);

////template<class T> class Serializer
typedef struct
{
////public:
////    using read_func_t = bool (*)(ser4cpp::rseq_t& buffer, T& output);
////    using write_func_t = bool (*)(const T& value, ser4cpp::wseq_t& buffer);

////    Serializer() = default;

////    Serializer(size_t size, read_func_t read_func, write_func_t write_func)
////        : size(size), read_func(read_func), write_func(write_func)
////    {
////    }

  /**
   * @return The size (in bytes) required for every call to read/write
   */
////    size_t get_size() const
////    {
////        return size;
////    }

  /**
   * reads the value and advances the read buffer
   */
////    bool read(ser4cpp::rseq_t& buffer, T& output) const
////    {
////        return (*read_func)(buffer, output);
////    }

  /**
   * writes the value and advances the write buffer
   */
////    bool write(const T& value, ser4cpp::wseq_t& buffer) const
////    {
////        return (*write_func)(value, buffer);
////    }

////private:
  ////size_t size = 0;
////    read_func_t read_func = nullptr;
////    write_func_t write_func = nullptr;
  uint16_t size;
  read_func_t_in_Serializer_for_OctetString  read_func;
  write_func_t_in_Serializer_for_OctetString write_func;

} Serializer_for_OctetString;
////} // namespace opendnp3


uint16_t get_size_in_Serializer_for_OctetString(Serializer_for_OctetString *pSerializer_for_OctetString);
boolean read_in_Serializer_for_OctetString(Serializer_for_OctetString *pSerializer_for_OctetString, RSeq_for_Uint16_t *buffer, OctetString *output);
boolean write_in_Serializer_for_OctetString(Serializer_for_OctetString *pSerializer_for_OctetString, OctetString *value, WSeq_for_Uint16_t *buffer);

void Serializer_for_OctetString_in_Serializer_for_OctetString(Serializer_for_OctetString *pSerializer_for_OctetString,
    uint16_t size,
    read_func_t_in_Serializer_for_OctetString read_func,
    write_func_t_in_Serializer_for_OctetString write_func);


//------------------------Serializer_for_OctetString----------------------------------------------------
//------------------------Serializer_for_Counter----------------------------------------------------

typedef boolean (*read_func_t_in_Serializer_for_Counter) (RSeq_for_Uint16_t *buffer, Counter *output);
typedef boolean (*write_func_t_in_Serializer_for_Counter)(Counter *value, WSeq_for_Uint16_t *buffer);
//#define POINTER_read_func_t_in_Serializer_for_Binary_FUNCTION(function)   (*(read_func_t_in_Serializer_for_Binary *)function)
//#define POINTER_write_func_t_in_Serializer_for_Binary_FUNCTION(function)  (*(write_func_t_in_Serializer_for_Binary *)function)

////template<class T> class Serializer
typedef struct
{
////public:
////    using read_func_t = bool (*)(ser4cpp::rseq_t& buffer, T& output);
////    using write_func_t = bool (*)(const T& value, ser4cpp::wseq_t& buffer);

////    Serializer() = default;

////    Serializer(size_t size, read_func_t read_func, write_func_t write_func)
////        : size(size), read_func(read_func), write_func(write_func)
////    {
////    }

  /**
   * @return The size (in bytes) required for every call to read/write
   */
////    size_t get_size() const
////    {
////        return size;
////    }

  /**
   * reads the value and advances the read buffer
   */
////    bool read(ser4cpp::rseq_t& buffer, T& output) const
////    {
////        return (*read_func)(buffer, output);
////    }

  /**
   * writes the value and advances the write buffer
   */
////    bool write(const T& value, ser4cpp::wseq_t& buffer) const
////    {
////        return (*write_func)(value, buffer);
////    }

////private:
  ////size_t size = 0;
////    read_func_t read_func = nullptr;
////    write_func_t write_func = nullptr;
  uint16_t size;
  read_func_t_in_Serializer_for_Counter  read_func;
  write_func_t_in_Serializer_for_Counter write_func;

} Serializer_for_Counter;
////} // namespace opendnp3


uint16_t get_size_in_Serializer_for_Counter(Serializer_for_Counter *pSerializer_for_Counter);
boolean read_in_Serializer_for_Counter(Serializer_for_Counter *pSerializer_for_Counter, RSeq_for_Uint16_t *buffer, Counter *output);
boolean write_in_Serializer_for_Counter(Serializer_for_Counter *pSerializer_for_Counter, Counter *value, WSeq_for_Uint16_t *buffer);

void Serializer_for_Counter_in_Serializer_for_Counter(Serializer_for_Counter *pSerializer_for_Counter,
    uint16_t size,
    read_func_t_in_Serializer_for_Counter read_func,
    write_func_t_in_Serializer_for_Counter write_func);


//------------------------Serializer_for_Counter----------------------------------------------------
//------------------------Serializer_for_Analog----------------------------------------------------

typedef boolean (*read_func_t_in_Serializer_for_Analog) (RSeq_for_Uint16_t *buffer, Analog *output);
typedef boolean (*write_func_t_in_Serializer_for_Analog)(Analog *value, WSeq_for_Uint16_t *buffer);
//#define POINTER_read_func_t_in_Serializer_for_Binary_FUNCTION(function)   (*(read_func_t_in_Serializer_for_Binary *)function)
//#define POINTER_write_func_t_in_Serializer_for_Binary_FUNCTION(function)  (*(write_func_t_in_Serializer_for_Binary *)function)

////template<class T> class Serializer
typedef struct
{
////public:
////    using read_func_t = bool (*)(ser4cpp::rseq_t& buffer, T& output);
////    using write_func_t = bool (*)(const T& value, ser4cpp::wseq_t& buffer);

////    Serializer() = default;

////    Serializer(size_t size, read_func_t read_func, write_func_t write_func)
////        : size(size), read_func(read_func), write_func(write_func)
////    {
////    }

  /**
   * @return The size (in bytes) required for every call to read/write
   */
////    size_t get_size() const
////    {
////        return size;
////    }

  /**
   * reads the value and advances the read buffer
   */
////    bool read(ser4cpp::rseq_t& buffer, T& output) const
////    {
////        return (*read_func)(buffer, output);
////    }

  /**
   * writes the value and advances the write buffer
   */
////    bool write(const T& value, ser4cpp::wseq_t& buffer) const
////    {
////        return (*write_func)(value, buffer);
////    }

////private:
  ////size_t size = 0;
////    read_func_t read_func = nullptr;
////    write_func_t write_func = nullptr;
  uint16_t size;
  read_func_t_in_Serializer_for_Analog  read_func;
  write_func_t_in_Serializer_for_Analog write_func;

} Serializer_for_Analog;
////} // namespace opendnp3


uint16_t get_size_in_Serializer_for_Analog(Serializer_for_Analog *pSerializer_for_Analog);
boolean read_in_Serializer_for_Analog(Serializer_for_Analog *pSerializer_for_Analog, RSeq_for_Uint16_t *buffer, Analog *output);
boolean write_in_Serializer_for_Analog(Serializer_for_Analog *pSerializer_for_Analog, Analog *value, WSeq_for_Uint16_t *buffer);

void Serializer_for_Analog_in_Serializer_for_Analog(Serializer_for_Analog *pSerializer_for_Analog,
    uint16_t size,
    read_func_t_in_Serializer_for_Analog read_func,
    write_func_t_in_Serializer_for_Analog write_func);


//------------------------Serializer_for_Analog----------------------------------------------------
//------------------------Serializer_for_AnalogOutputStatus----------------------------------------------------

typedef boolean (*read_func_t_in_Serializer_for_AnalogOutputStatus) (RSeq_for_Uint16_t *buffer, AnalogOutputStatus *output);
typedef boolean (*write_func_t_in_Serializer_for_AnalogOutputStatus)(AnalogOutputStatus *value, WSeq_for_Uint16_t *buffer);
//#define POINTER_read_func_t_in_Serializer_for_Binary_FUNCTION(function)   (*(read_func_t_in_Serializer_for_Binary *)function)
//#define POINTER_write_func_t_in_Serializer_for_Binary_FUNCTION(function)  (*(write_func_t_in_Serializer_for_Binary *)function)

////template<class T> class Serializer
typedef struct
{
////public:
////    using read_func_t = bool (*)(ser4cpp::rseq_t& buffer, T& output);
////    using write_func_t = bool (*)(const T& value, ser4cpp::wseq_t& buffer);

////    Serializer() = default;

////    Serializer(size_t size, read_func_t read_func, write_func_t write_func)
////        : size(size), read_func(read_func), write_func(write_func)
////    {
////    }

  /**
   * @return The size (in bytes) required for every call to read/write
   */
////    size_t get_size() const
////    {
////        return size;
////    }

  /**
   * reads the value and advances the read buffer
   */
////    bool read(ser4cpp::rseq_t& buffer, T& output) const
////    {
////        return (*read_func)(buffer, output);
////    }

  /**
   * writes the value and advances the write buffer
   */
////    bool write(const T& value, ser4cpp::wseq_t& buffer) const
////    {
////        return (*write_func)(value, buffer);
////    }

////private:
  ////size_t size = 0;
////    read_func_t read_func = nullptr;
////    write_func_t write_func = nullptr;
  uint16_t size;
  read_func_t_in_Serializer_for_AnalogOutputStatus  read_func;
  write_func_t_in_Serializer_for_AnalogOutputStatus write_func;

} Serializer_for_AnalogOutputStatus;
////} // namespace opendnp3


uint16_t get_size_in_Serializer_for_AnalogOutputStatus(Serializer_for_AnalogOutputStatus *pSerializer_for_AnalogOutputStatus);
boolean read_in_Serializer_for_AnalogOutputStatus(Serializer_for_AnalogOutputStatus *pSerializer_for_AnalogOutputStatus, RSeq_for_Uint16_t *buffer, AnalogOutputStatus *output);
boolean write_in_Serializer_for_AnalogOutputStatus(Serializer_for_AnalogOutputStatus *pSerializer_for_AnalogOutputStatus, AnalogOutputStatus *value, WSeq_for_Uint16_t *buffer);

void Serializer_for_AnalogOutputStatus_in_Serializer_for_AnalogOutputStatus(Serializer_for_AnalogOutputStatus *pSerializer_for_AnalogOutputStatus,
    uint16_t size,
    read_func_t_in_Serializer_for_AnalogOutputStatus read_func,
    write_func_t_in_Serializer_for_AnalogOutputStatus write_func);


//------------------------Serializer_for_AnalogOutputStatus----------------------------------------------------
//------------------------Serializer_for_TimeAndInterval----------------------------------------------------

typedef boolean (*read_func_t_in_Serializer_for_TimeAndInterval) (RSeq_for_Uint16_t *buffer, TimeAndInterval *output);
typedef boolean (*write_func_t_in_Serializer_for_TimeAndInterval)(TimeAndInterval *value, WSeq_for_Uint16_t *buffer);
//#define POINTER_read_func_t_in_Serializer_for_Binary_FUNCTION(function)   (*(read_func_t_in_Serializer_for_Binary *)function)
//#define POINTER_write_func_t_in_Serializer_for_Binary_FUNCTION(function)  (*(write_func_t_in_Serializer_for_Binary *)function)

////template<class T> class Serializer
typedef struct
{
////public:
////    using read_func_t = bool (*)(ser4cpp::rseq_t& buffer, T& output);
////    using write_func_t = bool (*)(const T& value, ser4cpp::wseq_t& buffer);

////    Serializer() = default;

////    Serializer(size_t size, read_func_t read_func, write_func_t write_func)
////        : size(size), read_func(read_func), write_func(write_func)
////    {
////    }

  /**
   * @return The size (in bytes) required for every call to read/write
   */
////    size_t get_size() const
////    {
////        return size;
////    }

  /**
   * reads the value and advances the read buffer
   */
////    bool read(ser4cpp::rseq_t& buffer, T& output) const
////    {
////        return (*read_func)(buffer, output);
////    }

  /**
   * writes the value and advances the write buffer
   */
////    bool write(const T& value, ser4cpp::wseq_t& buffer) const
////    {
////        return (*write_func)(value, buffer);
////    }

////private:
  ////size_t size = 0;
////    read_func_t read_func = nullptr;
////    write_func_t write_func = nullptr;
  uint16_t size;
  read_func_t_in_Serializer_for_TimeAndInterval  read_func;
  write_func_t_in_Serializer_for_TimeAndInterval write_func;

} Serializer_for_TimeAndInterval;
////} // namespace opendnp3


uint16_t get_size_in_Serializer_for_TimeAndInterval(Serializer_for_TimeAndInterval *pSerializer_for_TimeAndInterval);
boolean read_in_Serializer_for_TimeAndInterval(Serializer_for_TimeAndInterval *pSerializer_for_TimeAndInterval, RSeq_for_Uint16_t *buffer, TimeAndInterval *output);
boolean write_in_Serializer_for_TimeAndInterval(Serializer_for_TimeAndInterval *pSerializer_for_TimeAndInterval, TimeAndInterval *value, WSeq_for_Uint16_t *buffer);

void Serializer_for_TimeAndInterval_in_Serializer_for_TimeAndInterval(Serializer_for_TimeAndInterval *pSerializer_for_TimeAndInterval,
    uint16_t size,
    read_func_t_in_Serializer_for_TimeAndInterval read_func,
    write_func_t_in_Serializer_for_TimeAndInterval write_func);


//------------------------Serializer_for_TimeAndInterval----------------------------------------------------
//------------------------Serializer_for_ControlRelayOutputBlock----------------------------------------------------

typedef boolean (*read_func_t_in_Serializer_for_ControlRelayOutputBlock) (RSeq_for_Uint16_t *buffer, ControlRelayOutputBlock *output);
typedef boolean (*write_func_t_in_Serializer_for_ControlRelayOutputBlock)(ControlRelayOutputBlock *value, WSeq_for_Uint16_t *buffer);

////template<class T> class Serializer
typedef struct
{
////public:
////    using read_func_t = bool (*)(ser4cpp::rseq_t& buffer, T& output);
////    using write_func_t = bool (*)(const T& value, ser4cpp::wseq_t& buffer);

////    Serializer() = default;

////    Serializer(size_t size, read_func_t read_func, write_func_t write_func)
////        : size(size), read_func(read_func), write_func(write_func)
////    {
////    }

  /**
   * @return The size (in bytes) required for every call to read/write
   */
////    size_t get_size() const
////    {
////        return size;
////    }

  /**
   * reads the value and advances the read buffer
   */
////    bool read(ser4cpp::rseq_t& buffer, T& output) const
////    {
////        return (*read_func)(buffer, output);
////    }

  /**
   * writes the value and advances the write buffer
   */
////    bool write(const T& value, ser4cpp::wseq_t& buffer) const
////    {
////        return (*write_func)(value, buffer);
////    }

////private:
  ////size_t size = 0;
////    read_func_t read_func = nullptr;
////    write_func_t write_func = nullptr;
  uint16_t size;
  read_func_t_in_Serializer_for_ControlRelayOutputBlock  read_func;
  write_func_t_in_Serializer_for_ControlRelayOutputBlock write_func;

} Serializer_for_ControlRelayOutputBlock;
////} // namespace opendnp3


uint16_t get_size_in_Serializer_for_ControlRelayOutputBlock(Serializer_for_ControlRelayOutputBlock *pSerializer_for_ControlRelayOutputBlock);
boolean read_in_Serializer_for_ControlRelayOutputBlock(Serializer_for_ControlRelayOutputBlock *pSerializer_for_ControlRelayOutputBlock, RSeq_for_Uint16_t *buffer, ControlRelayOutputBlock *output);
boolean write_in_Serializer_for_ControlRelayOutputBlock(Serializer_for_ControlRelayOutputBlock *pSerializer_for_ControlRelayOutputBlock, ControlRelayOutputBlock *value, WSeq_for_Uint16_t *buffer);

void Serializer_for_ControlRelayOutputBlock_in_Serializer_for_ControlRelayOutputBlock(Serializer_for_ControlRelayOutputBlock *pSerializer_for_ControlRelayOutputBlock,
    uint16_t size,
    read_func_t_in_Serializer_for_ControlRelayOutputBlock read_func,
    write_func_t_in_Serializer_for_ControlRelayOutputBlock write_func);


//------------------------Serializer_for_ControlRelayOutputBlock----------------------------------------------------
//------------------------Serializer_for_AnalogOutputInt16----------------------------------------------------

typedef boolean (*read_func_t_in_Serializer_for_AnalogOutputInt16) (RSeq_for_Uint16_t *buffer, AnalogOutputInt16 *output);
typedef boolean (*write_func_t_in_Serializer_for_AnalogOutputInt16)(AnalogOutputInt16 *value, WSeq_for_Uint16_t *buffer);
//#define POINTER_read_func_t_in_Serializer_for_Binary_FUNCTION(function)   (*(read_func_t_in_Serializer_for_Binary *)function)
//#define POINTER_write_func_t_in_Serializer_for_Binary_FUNCTION(function)  (*(write_func_t_in_Serializer_for_Binary *)function)

////template<class T> class Serializer
typedef struct
{
////public:
////    using read_func_t = bool (*)(ser4cpp::rseq_t& buffer, T& output);
////    using write_func_t = bool (*)(const T& value, ser4cpp::wseq_t& buffer);

////    Serializer() = default;

////    Serializer(size_t size, read_func_t read_func, write_func_t write_func)
////        : size(size), read_func(read_func), write_func(write_func)
////    {
////    }

  /**
   * @return The size (in bytes) required for every call to read/write
   */
////    size_t get_size() const
////    {
////        return size;
////    }

  /**
   * reads the value and advances the read buffer
   */
////    bool read(ser4cpp::rseq_t& buffer, T& output) const
////    {
////        return (*read_func)(buffer, output);
////    }

  /**
   * writes the value and advances the write buffer
   */
////    bool write(const T& value, ser4cpp::wseq_t& buffer) const
////    {
////        return (*write_func)(value, buffer);
////    }

////private:
  ////size_t size = 0;
////    read_func_t read_func = nullptr;
////    write_func_t write_func = nullptr;
  uint16_t size;
  read_func_t_in_Serializer_for_AnalogOutputInt16  read_func;
  write_func_t_in_Serializer_for_AnalogOutputInt16 write_func;

} Serializer_for_AnalogOutputInt16;
////} // namespace opendnp3


uint16_t get_size_in_Serializer_for_AnalogOutputInt16(Serializer_for_AnalogOutputInt16 *pSerializer_for_AnalogOutputInt16);
boolean read_in_Serializer_for_AnalogOutputInt16(Serializer_for_AnalogOutputInt16 *pSerializer_for_AnalogOutputInt16, RSeq_for_Uint16_t *buffer, AnalogOutputInt16 *output);
boolean write_in_Serializer_for_AnalogOutputInt16(Serializer_for_AnalogOutputInt16 *pSerializer_for_AnalogOutputInt16, AnalogOutputInt16 *value, WSeq_for_Uint16_t *buffer);

void Serializer_for_AnalogOutputInt16_in_Serializer_for_AnalogOutputInt16(Serializer_for_AnalogOutputInt16 *pSerializer_for_AnalogOutputInt16,
    uint16_t size,
    read_func_t_in_Serializer_for_AnalogOutputInt16 read_func,
    write_func_t_in_Serializer_for_AnalogOutputInt16 write_func);


//------------------------Serializer_for_AnalogOutputInt16----------------------------------------------------
//------------------------Serializer_for_AnalogOutputInt32----------------------------------------------------

typedef boolean (*read_func_t_in_Serializer_for_AnalogOutputInt32) (RSeq_for_Uint16_t *buffer, AnalogOutputInt32 *output);
typedef boolean (*write_func_t_in_Serializer_for_AnalogOutputInt32)(AnalogOutputInt32 *value, WSeq_for_Uint16_t *buffer);
//#define POINTER_read_func_t_in_Serializer_for_Binary_FUNCTION(function)   (*(read_func_t_in_Serializer_for_Binary *)function)
//#define POINTER_write_func_t_in_Serializer_for_Binary_FUNCTION(function)  (*(write_func_t_in_Serializer_for_Binary *)function)

////template<class T> class Serializer
typedef struct
{
////public:
////    using read_func_t = bool (*)(ser4cpp::rseq_t& buffer, T& output);
////    using write_func_t = bool (*)(const T& value, ser4cpp::wseq_t& buffer);

////    Serializer() = default;

////    Serializer(size_t size, read_func_t read_func, write_func_t write_func)
////        : size(size), read_func(read_func), write_func(write_func)
////    {
////    }

  /**
   * @return The size (in bytes) required for every call to read/write
   */
////    size_t get_size() const
////    {
////        return size;
////    }

  /**
   * reads the value and advances the read buffer
   */
////    bool read(ser4cpp::rseq_t& buffer, T& output) const
////    {
////        return (*read_func)(buffer, output);
////    }

  /**
   * writes the value and advances the write buffer
   */
////    bool write(const T& value, ser4cpp::wseq_t& buffer) const
////    {
////        return (*write_func)(value, buffer);
////    }

////private:
  ////size_t size = 0;
////    read_func_t read_func = nullptr;
////    write_func_t write_func = nullptr;
  uint16_t size;
  read_func_t_in_Serializer_for_AnalogOutputInt32  read_func;
  write_func_t_in_Serializer_for_AnalogOutputInt32 write_func;

} Serializer_for_AnalogOutputInt32;
////} // namespace opendnp3


uint16_t get_size_in_Serializer_for_AnalogOutputInt32(Serializer_for_AnalogOutputInt32 *pSerializer_for_AnalogOutputInt32);
boolean read_in_Serializer_for_AnalogOutputInt32(Serializer_for_AnalogOutputInt32 *pSerializer_for_AnalogOutputInt32, RSeq_for_Uint16_t *buffer, AnalogOutputInt32 *output);
boolean write_in_Serializer_for_AnalogOutputInt32(Serializer_for_AnalogOutputInt32 *pSerializer_for_AnalogOutputInt32, AnalogOutputInt32 *value, WSeq_for_Uint16_t *buffer);

void Serializer_for_AnalogOutputInt32_in_Serializer_for_AnalogOutputInt32(Serializer_for_AnalogOutputInt32 *pSerializer_for_AnalogOutputInt32,
    uint16_t size,
    read_func_t_in_Serializer_for_AnalogOutputInt32 read_func,
    write_func_t_in_Serializer_for_AnalogOutputInt32 write_func);


//------------------------Serializer_for_AnalogOutputInt32----------------------------------------------------
//------------------------Serializer_for_AnalogOutputFloat32----------------------------------------------------

typedef boolean (*read_func_t_in_Serializer_for_AnalogOutputFloat32) (RSeq_for_Uint16_t *buffer, AnalogOutputFloat32 *output);
typedef boolean (*write_func_t_in_Serializer_for_AnalogOutputFloat32)(AnalogOutputFloat32 *value, WSeq_for_Uint16_t *buffer);
//#define POINTER_read_func_t_in_Serializer_for_Binary_FUNCTION(function)   (*(read_func_t_in_Serializer_for_Binary *)function)
//#define POINTER_write_func_t_in_Serializer_for_Binary_FUNCTION(function)  (*(write_func_t_in_Serializer_for_Binary *)function)

////template<class T> class Serializer
typedef struct
{
////public:
////    using read_func_t = bool (*)(ser4cpp::rseq_t& buffer, T& output);
////    using write_func_t = bool (*)(const T& value, ser4cpp::wseq_t& buffer);

////    Serializer() = default;

////    Serializer(size_t size, read_func_t read_func, write_func_t write_func)
////        : size(size), read_func(read_func), write_func(write_func)
////    {
////    }

  /**
   * @return The size (in bytes) required for every call to read/write
   */
////    size_t get_size() const
////    {
////        return size;
////    }

  /**
   * reads the value and advances the read buffer
   */
////    bool read(ser4cpp::rseq_t& buffer, T& output) const
////    {
////        return (*read_func)(buffer, output);
////    }

  /**
   * writes the value and advances the write buffer
   */
////    bool write(const T& value, ser4cpp::wseq_t& buffer) const
////    {
////        return (*write_func)(value, buffer);
////    }

////private:
  ////size_t size = 0;
////    read_func_t read_func = nullptr;
////    write_func_t write_func = nullptr;
  uint16_t size;
  read_func_t_in_Serializer_for_AnalogOutputFloat32  read_func;
  write_func_t_in_Serializer_for_AnalogOutputFloat32 write_func;

} Serializer_for_AnalogOutputFloat32;
////} // namespace opendnp3


uint16_t get_size_in_Serializer_for_AnalogOutputFloat32(Serializer_for_AnalogOutputFloat32 *pSerializer_for_AnalogOutputFloat32);
boolean read_in_Serializer_for_AnalogOutputFloat32(Serializer_for_AnalogOutputFloat32 *pSerializer_for_AnalogOutputFloat32, RSeq_for_Uint16_t *buffer, AnalogOutputFloat32 *output);
boolean write_in_Serializer_for_AnalogOutputFloat32(Serializer_for_AnalogOutputFloat32 *pSerializer_for_AnalogOutputFloat32, AnalogOutputFloat32 *value, WSeq_for_Uint16_t *buffer);

void Serializer_for_AnalogOutputFloat32_in_Serializer_for_AnalogOutputFloat32(Serializer_for_AnalogOutputFloat32 *pSerializer_for_AnalogOutputFloat32,
    uint16_t size,
    read_func_t_in_Serializer_for_AnalogOutputFloat32 read_func,
    write_func_t_in_Serializer_for_AnalogOutputFloat32 write_func);


//------------------------Serializer_for_AnalogOutputFloat32----------------------------------------------------
//------------------------Serializer_for_AnalogOutputDouble64----------------------------------------------------

typedef boolean (*read_func_t_in_Serializer_for_AnalogOutputDouble64) (RSeq_for_Uint16_t *buffer, AnalogOutputDouble64 *output);
typedef boolean (*write_func_t_in_Serializer_for_AnalogOutputDouble64)(AnalogOutputDouble64 *value, WSeq_for_Uint16_t *buffer);
//#define POINTER_read_func_t_in_Serializer_for_Binary_FUNCTION(function)   (*(read_func_t_in_Serializer_for_Binary *)function)
//#define POINTER_write_func_t_in_Serializer_for_Binary_FUNCTION(function)  (*(write_func_t_in_Serializer_for_Binary *)function)

////template<class T> class Serializer
typedef struct
{
////public:
////    using read_func_t = bool (*)(ser4cpp::rseq_t& buffer, T& output);
////    using write_func_t = bool (*)(const T& value, ser4cpp::wseq_t& buffer);

////    Serializer() = default;

////    Serializer(size_t size, read_func_t read_func, write_func_t write_func)
////        : size(size), read_func(read_func), write_func(write_func)
////    {
////    }

  /**
   * @return The size (in bytes) required for every call to read/write
   */
////    size_t get_size() const
////    {
////        return size;
////    }

  /**
   * reads the value and advances the read buffer
   */
////    bool read(ser4cpp::rseq_t& buffer, T& output) const
////    {
////        return (*read_func)(buffer, output);
////    }

  /**
   * writes the value and advances the write buffer
   */
////    bool write(const T& value, ser4cpp::wseq_t& buffer) const
////    {
////        return (*write_func)(value, buffer);
////    }

////private:
  ////size_t size = 0;
////    read_func_t read_func = nullptr;
////    write_func_t write_func = nullptr;
  uint16_t size;
  read_func_t_in_Serializer_for_AnalogOutputDouble64  read_func;
  write_func_t_in_Serializer_for_AnalogOutputDouble64 write_func;

} Serializer_for_AnalogOutputDouble64;
////} // namespace opendnp3


uint16_t get_size_in_Serializer_for_AnalogOutputDouble64(Serializer_for_AnalogOutputDouble64 *pSerializer_for_AnalogOutputDouble64);
boolean read_in_Serializer_for_AnalogOutputDouble64(Serializer_for_AnalogOutputDouble64 *pSerializer_for_AnalogOutputDouble64, RSeq_for_Uint16_t *buffer, AnalogOutputDouble64 *output);
boolean write_in_Serializer_for_AnalogOutputDouble64(Serializer_for_AnalogOutputDouble64 *pSerializer_for_AnalogOutputDouble64, AnalogOutputDouble64 *value, WSeq_for_Uint16_t *buffer);

void Serializer_for_AnalogOutputDouble64_in_Serializer_for_AnalogOutputDouble64(Serializer_for_AnalogOutputDouble64 *pSerializer_for_AnalogOutputDouble64,
    uint16_t size,
    read_func_t_in_Serializer_for_AnalogOutputDouble64 read_func,
    write_func_t_in_Serializer_for_AnalogOutputDouble64 write_func);


//------------------------Serializer_for_AnalogOutputDouble64----------------------------------------------------

#endif
