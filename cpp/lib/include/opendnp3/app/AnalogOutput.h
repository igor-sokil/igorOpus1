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
#ifndef OPENDNP3_ANALOGOUTPUT_H
#define OPENDNP3_ANALOGOUTPUT_H

////#include "opendnp3/gen/CommandStatus.h"
#include "CommandStatus.h"

////namespace opendnp3
////{

/**
 * The object to represent a setpoint request from the master. Think of
 * this like turning a dial on the front of a machine to desired setting.
 */
////template<class T> class AnalogOutput
typedef struct
{
////public:
////    AnalogOutput() : value(0), status(CommandStatus::SUCCESS) {}

////    AnalogOutput(T value_) : value(value_), status(CommandStatus::SUCCESS) {}

////    AnalogOutput(T value_, CommandStatus status_) : value(value_), status(status_) {}

////    bool ValuesEqual(const AnalogOutput<T>& lhs) const
////    {
////        return value == lhs.value;
////    }

////    T value;
    int16_t value;

    /**
     * The status value defaults to CS_SUCCESS for requests
     */
    CommandStatus_uint8_t status;
} AnalogOutput_for_Int16;

  void AnalogOutput_for_Int16_in_AnalogOutput_for_Int16Over1(AnalogOutput_for_Int16 *);
  void AnalogOutput_for_Int16_in_AnalogOutput_for_Int16Over2(AnalogOutput_for_Int16 *, int16_t value_);
  void AnalogOutput_for_Int16_in_AnalogOutput_for_Int16Over3(AnalogOutput_for_Int16 *, int16_t value_, CommandStatus_uint8_t status_);
  boolean ValuesEqual_in_AnalogOutput_for_Int16(AnalogOutput_for_Int16 *pAnalogOutput_for_Int16, AnalogOutput_for_Int16 * lhs);

////  boolean ValuesEqual_in_AnalogOutput_for_Int16(AnalogOutput_for_Int16 *pAnalogOutput_for_Int16, AnalogOutput_for_Int16 * lhs)
////{
////    return pAnalogOutput_for_Int16->value == lhs->value;
////}

typedef struct
{
////public:
////    AnalogOutput() : value(0), status(CommandStatus::SUCCESS) {}

////    AnalogOutput(T value_) : value(value_), status(CommandStatus::SUCCESS) {}

////    AnalogOutput(T value_, CommandStatus status_) : value(value_), status(status_) {}

////    bool ValuesEqual(const AnalogOutput<T>& lhs) const
////    {
////        return value == lhs.value;
////    }

////    T value;
    int32_t value;

    /**
     * The status value defaults to CS_SUCCESS for requests
     */
    CommandStatus_uint8_t status;
} AnalogOutput_for_Int32;

  void AnalogOutput_for_Int32_in_AnalogOutput_for_Int32Over1(AnalogOutput_for_Int32 *);
  void AnalogOutput_for_Int32_in_AnalogOutput_for_Int32Over2(AnalogOutput_for_Int32 *, int32_t value_);
  void AnalogOutput_for_Int32_in_AnalogOutput_for_Int32Over3(AnalogOutput_for_Int32 *, int32_t value_, CommandStatus_uint8_t status_);
  boolean ValuesEqual_in_AnalogOutput_for_Int32(AnalogOutput_for_Int32 *pAnalogOutput_for_Int32, AnalogOutput_for_Int32 *lhs) ;

////  boolean ValuesEqual_in_AnalogOutput_for_Int32(AnalogOutput_for_Int32 *pAnalogOutput_for_Int32, AnalogOutput_for_Int32 *lhs) 
////{
////    return pAnalogOutput_for_Int32->value == lhs->value;
////}

typedef struct
{
////public:
////    AnalogOutput() : value(0), status(CommandStatus::SUCCESS) {}

////    AnalogOutput(T value_) : value(value_), status(CommandStatus::SUCCESS) {}

////    AnalogOutput(T value_, CommandStatus status_) : value(value_), status(status_) {}

////    bool ValuesEqual(const AnalogOutput<T>& lhs) const
////    {
////        return value == lhs.value;
////    }

////    T value;
    float value;

    /**
     * The status value defaults to CS_SUCCESS for requests
     */
    CommandStatus_uint8_t status;
} AnalogOutput_for_Float32;

  void AnalogOutput_for_Float32_in_AnalogOutput_for_Float32Over1(AnalogOutput_for_Float32 *);
  void AnalogOutput_for_Float32_in_AnalogOutput_for_Float32Over2(AnalogOutput_for_Float32 *, float value_);
  void AnalogOutput_for_Float32_in_AnalogOutput_for_Float32Over3(AnalogOutput_for_Float32 *, float value_, CommandStatus_uint8_t status_);
  boolean ValuesEqual_in_AnalogOutput_for_Float32(AnalogOutput_for_Float32 *pAnalogOutput_for_Float32, AnalogOutput_for_Float32 *lhs);

////  boolean ValuesEqual_in_AnalogOutput_for_Float32(AnalogOutput_for_Float32 *pAnalogOutput_for_Float32, AnalogOutput_for_Float32 *lhs)
////{
////    return pAnalogOutput_for_Float32->value == lhs->value;
////}

typedef struct
{
////public:
////    AnalogOutput() : value(0), status(CommandStatus::SUCCESS) {}

////    AnalogOutput(T value_) : value(value_), status(CommandStatus::SUCCESS) {}

////    AnalogOutput(T value_, CommandStatus status_) : value(value_), status(status_) {}

////    bool ValuesEqual(const AnalogOutput<T>& lhs) const
////    {
////        return value == lhs.value;
////    }

////    T value;
    double value;

    /**
     * The status value defaults to CS_SUCCESS for requests
     */
    CommandStatus_uint8_t status;
} AnalogOutput_for_Double64;

  void AnalogOutput_for_Double64_in_AnalogOutput_for_Double64Over1(AnalogOutput_for_Double64 *);
  void AnalogOutput_for_Double64_in_AnalogOutput_for_Double64Over2(AnalogOutput_for_Double64 *, double value_);
  void AnalogOutput_for_Double64_in_AnalogOutput_for_Double64Over3(AnalogOutput_for_Double64 *, double value_, CommandStatus_uint8_t status_);
  boolean ValuesEqual_in_AnalogOutput_for_Double64(AnalogOutput_for_Double64 *pAnalogOutput_for_Double64, AnalogOutput_for_Double64 *lhs);

////  boolean ValuesEqual_in_AnalogOutput_for_Double64(AnalogOutput_for_Double64 *pAnalogOutput_for_Double64, AnalogOutput_for_Double64 *lhs)
////{
////    return pAnalogOutput_for_Double64->value == lhs->value;
////}

/**
 *	16-bit signed integer analog output. The underlying serialization is Group41, Variation 2
 */
////class AnalogOutputInt16 : public AnalogOutput<int16_t>
typedef struct
{
////public:
////    AnalogOutputInt16();
////    AnalogOutputInt16(int16_t);
////    AnalogOutputInt16(int16_t, CommandStatus);
  AnalogOutput_for_Int16 AnalogOutput_for_Int16;

////    bool operator==(const AnalogOutputInt16& arRHS) const;

} AnalogOutputInt16;

  void AnalogOutputInt16_in_AnalogOutputInt16Over1(AnalogOutputInt16 *);
  void AnalogOutputInt16_in_AnalogOutputInt16Over2(AnalogOutputInt16 *, int16_t value_);
  void AnalogOutputInt16_in_AnalogOutputInt16Over3(AnalogOutputInt16 *, int16_t value_, CommandStatus_uint8_t status_);
  boolean operatorEQ_in_AnalogOutputInt16(AnalogOutputInt16 *, AnalogOutputInt16 *);

/**
 *	32-bit signed integer analog output. The underlying serialization is Group41, Variation 1
 */
//class AnalogOutputInt32 : public AnalogOutput<int32_t>
typedef struct
{
////public:
////    AnalogOutputInt32();
////    AnalogOutputInt32(int32_t);
////    AnalogOutputInt32(int32_t, CommandStatus);
  AnalogOutput_for_Int32 AnalogOutput_for_Int32;

////    bool operator==(const AnalogOutputInt32& arRHS) const;
} AnalogOutputInt32;

  void AnalogOutputInt32_in_AnalogOutputInt32Over1(AnalogOutputInt32 *);
  void AnalogOutputInt32_in_AnalogOutputInt32Over2(AnalogOutputInt32 *, int32_t value_);
  void AnalogOutputInt32_in_AnalogOutputInt32Over3(AnalogOutputInt32 *, int32_t value_, CommandStatus_uint8_t status_);
  boolean operatorEQ_in_AnalogOutputInt32(AnalogOutputInt32 *pAnalogOutputInt32, AnalogOutputInt32 *arRHS);

/**
 *	Single precision analog output. The underlying serialization is Group41, Variation 3
 */
//class AnalogOutputFloat32 : public AnalogOutput<float>
typedef struct
{
////public:
////    AnalogOutputFloat32();
////    AnalogOutputFloat32(float);
////    AnalogOutputFloat32(float, CommandStatus);
  AnalogOutput_for_Float32 AnalogOutput_for_Float32;

////    bool operator==(const AnalogOutputFloat32& arRHS) const;
} AnalogOutputFloat32;

  void AnalogOutputFloat32_in_AnalogOutputFloat32Over1(AnalogOutputFloat32 *);
  void AnalogOutputFloat32_in_AnalogOutputFloat32Over2(AnalogOutputFloat32 *, float value_);
  void AnalogOutputFloat32_in_AnalogOutputFloat32Over3(AnalogOutputFloat32 *, float value_, CommandStatus_uint8_t status_);
  boolean operatorEQ_in_AnalogOutputFloat32(AnalogOutputFloat32 *, AnalogOutputFloat32 *);

/**
 *	Double precision analog output. The underlying serialization is Group41, Variation 3
 */
////class AnalogOutputDouble64 : public AnalogOutput<double>
typedef struct
{
////public:
////    AnalogOutputDouble64();
////    AnalogOutputDouble64(double);
////    AnalogOutputDouble64(double, CommandStatus);
  AnalogOutput_for_Double64 AnalogOutput_for_Double64;

////    bool operator==(const AnalogOutputDouble64& arRHS) const;
} AnalogOutputDouble64;

  void AnalogOutputDouble64_in_AnalogOutputDouble64Over1(AnalogOutputDouble64 *);
  void AnalogOutputDouble64_in_AnalogOutputDouble64Over2(AnalogOutputDouble64 *, double value_);
  void AnalogOutputDouble64_in_AnalogOutputDouble64Over3(AnalogOutputDouble64 *, double value_, CommandStatus_uint8_t status_);
  boolean operatorEQ_in_AnalogOutputDouble64(AnalogOutputDouble64 *, AnalogOutputDouble64 *);


////} // namespace opendnp3

#endif
