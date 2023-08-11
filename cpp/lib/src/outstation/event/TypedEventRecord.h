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
#ifndef OPENDNP3_TYPEDEVENTRECORD_H
#define OPENDNP3_TYPEDEVENTRECORD_H

//#include "EventRecord.h"
#include "MeasurementTypes.h"
#include "MeasurementInfo.h"
#include "Node_for_EventRecord.h"

////namespace opendnp3
////{

/**
 * Event details that vary by type
 */
////template<class T> struct TypedEventRecord
////{
////  TypedEventRecord() = default;
////
////  TypedEventRecord(const typename T::meas_t& value,
////                   typename T::event_variation_t defaultVariation,
////                   Node<EventRecord>* record)
////    : value(value), defaultVariation(defaultVariation), selectedVariation(defaultVariation), record(record)
////  {
////  }
////
////  typename T::meas_t value;
////  typename T::event_variation_t defaultVariation;
////  typename T::event_variation_t selectedVariation;
////  Node<EventRecord>* record = nullptr;
////};
////} // namespace opendnp3
//----------------------------------BinarySpec-----------------------------------------------
////template<class T> struct TypedEventRecord
typedef struct
{
////  TypedEventRecord() = default;
////
////
////  typename T::meas_t value;
  Binary value;
////  typename T::event_variation_t defaultVariation;
  event_variation_t_in_BinaryInfo  defaultVariation;
////  typename T::event_variation_t selectedVariation;
  event_variation_t_in_BinaryInfo  selectedVariation;
////  Node<EventRecord>* record = nullptr;
  Node_for_EventRecord* record;//// = nullptr;
} TypedEventRecord_for_BinarySpec;

void TypedEventRecord_for_BinarySpec_in_TypedEventRecord_for_BinarySpec(TypedEventRecord_for_BinarySpec *pTypedEventRecord_for_BinarySpec,
////                   const typename T::meas_t& value,
    Binary *value,
////                   typename T::event_variation_t defaultVariation,
    event_variation_t_in_BinaryInfo  defaultVariation,
    Node_for_EventRecord* record);

//----------------------------------BinarySpec-----------------------------------------------
//----------------------------------DoubleBitBinarySpec-----------------------------------------------
////template<class T> struct TypedEventRecord
typedef struct
{
////  TypedEventRecord() = default;
////
////
////  typename T::meas_t value;
  DoubleBitBinary value;
////  typename T::event_variation_t defaultVariation;
  event_variation_t_in_DoubleBitBinaryInfo  defaultVariation;
////  typename T::event_variation_t selectedVariation;
  event_variation_t_in_DoubleBitBinaryInfo  selectedVariation;
////  Node<EventRecord>* record = nullptr;
  Node_for_EventRecord* record;//// = nullptr;
} TypedEventRecord_for_DoubleBitBinarySpec;

void TypedEventRecord_for_DoubleBitBinarySpec_in_TypedEventRecord_for_DoubleBitBinarySpec(TypedEventRecord_for_DoubleBitBinarySpec *pTypedEventRecord_for_DoubleBitBinarySpec,
////                   const typename T::meas_t& value,
    DoubleBitBinary *value,
////                   typename T::event_variation_t defaultVariation,
    event_variation_t_in_DoubleBitBinaryInfo  defaultVariation,
    Node_for_EventRecord* record);

//----------------------------------DoubleBitBinarySpec-----------------------------------------------
//----------------------------------AnalogSpec-----------------------------------------------
////template<class T> struct TypedEventRecord
typedef struct
{
////  TypedEventRecord() = default;
////
////
////  typename T::meas_t value;
  Analog value;
////  typename T::event_variation_t defaultVariation;
  event_variation_t_in_AnalogInfo  defaultVariation;
////  typename T::event_variation_t selectedVariation;
  event_variation_t_in_AnalogInfo  selectedVariation;
////  Node<EventRecord>* record = nullptr;
  Node_for_EventRecord* record;//// = nullptr;
} TypedEventRecord_for_AnalogSpec;

void TypedEventRecord_for_AnalogSpec_in_TypedEventRecord_for_AnalogSpec(TypedEventRecord_for_AnalogSpec *pTypedEventRecord_for_AnalogSpec,
////                   const typename T::meas_t& value,
    Analog *value,
////                   typename T::event_variation_t defaultVariation,
    event_variation_t_in_AnalogInfo  defaultVariation,
    Node_for_EventRecord* record);

//----------------------------------AnalogSpec-----------------------------------------------
//----------------------------------CounterSpec-----------------------------------------------
////template<class T> struct TypedEventRecord
typedef struct
{
////  TypedEventRecord() = default;
////
////
////  typename T::meas_t value;
  Counter value;
////  typename T::event_variation_t defaultVariation;
  event_variation_t_in_CounterInfo  defaultVariation;
////  typename T::event_variation_t selectedVariation;
  event_variation_t_in_CounterInfo  selectedVariation;
////  Node<EventRecord>* record = nullptr;
  Node_for_EventRecord* record;//// = nullptr;
} TypedEventRecord_for_CounterSpec;

void TypedEventRecord_for_CounterSpec_in_TypedEventRecord_for_CounterSpec(TypedEventRecord_for_CounterSpec *pTypedEventRecord_for_CounterSpec,
////                   const typename T::meas_t& value,
    Counter *value,
////                   typename T::event_variation_t defaultVariation,
    event_variation_t_in_CounterInfo  defaultVariation,
    Node_for_EventRecord* record);

//----------------------------------CounterSpec-----------------------------------------------
//----------------------------------FrozenCounterSpec-----------------------------------------------
////template<class T> struct TypedEventRecord
typedef struct
{
////  TypedEventRecord() = default;
////
////
////  typename T::meas_t value;
  FrozenCounter value;
////  typename T::event_variation_t defaultVariation;
  event_variation_t_in_FrozenCounterInfo  defaultVariation;
////  typename T::event_variation_t selectedVariation;
  event_variation_t_in_FrozenCounterInfo  selectedVariation;
////  Node<EventRecord>* record = nullptr;
  Node_for_EventRecord* record;//// = nullptr;
} TypedEventRecord_for_FrozenCounterSpec;

void TypedEventRecord_for_FrozenCounterSpec_in_TypedEventRecord_for_FrozenCounterSpec(TypedEventRecord_for_FrozenCounterSpec *pTypedEventRecord_for_FrozenCounterSpec,
////                   const typename T::meas_t& value,
    FrozenCounter *value,
////                   typename T::event_variation_t defaultVariation,
    event_variation_t_in_FrozenCounterInfo  defaultVariation,
    Node_for_EventRecord* record);

//----------------------------------FrozenCounterSpec-----------------------------------------------
//----------------------------------BinaryOutputStatusSpec-----------------------------------------------
////template<class T> struct TypedEventRecord
typedef struct
{
////  TypedEventRecord() = default;
////
////
////  typename T::meas_t value;
  BinaryOutputStatus value;
////  typename T::event_variation_t defaultVariation;
  event_variation_t_in_BinaryOutputStatusInfo  defaultVariation;
////  typename T::event_variation_t selectedVariation;
  event_variation_t_in_BinaryOutputStatusInfo  selectedVariation;
////  Node<EventRecord>* record = nullptr;
  Node_for_EventRecord* record;//// = nullptr;
} TypedEventRecord_for_BinaryOutputStatusSpec;

void TypedEventRecord_for_BinaryOutputStatusSpec_in_TypedEventRecord_for_BinaryOutputStatusSpec(TypedEventRecord_for_BinaryOutputStatusSpec *pTypedEventRecord_for_BinaryOutputStatusSpec,
////                   const typename T::meas_t& value,
    BinaryOutputStatus *value,
////                   typename T::event_variation_t defaultVariation,
    event_variation_t_in_BinaryOutputStatusInfo  defaultVariation,
    Node_for_EventRecord* record);

//----------------------------------BinaryOutputStatusSpec-----------------------------------------------
//----------------------------------AnalogOutputStatusSpec-----------------------------------------------
////template<class T> struct TypedEventRecord
typedef struct
{
////  TypedEventRecord() = default;
////
////
////  typename T::meas_t value;
  AnalogOutputStatus value;
////  typename T::event_variation_t defaultVariation;
  event_variation_t_in_AnalogOutputStatusInfo  defaultVariation;
////  typename T::event_variation_t selectedVariation;
  event_variation_t_in_AnalogOutputStatusInfo  selectedVariation;
////  Node<EventRecord>* record = nullptr;
  Node_for_EventRecord* record;//// = nullptr;
} TypedEventRecord_for_AnalogOutputStatusSpec;

void TypedEventRecord_for_AnalogOutputStatusSpec_in_TypedEventRecord_for_AnalogOutputStatusSpec(TypedEventRecord_for_AnalogOutputStatusSpec *pTypedEventRecord_for_AnalogOutputStatusSpec,
////                   const typename T::meas_t& value,
    AnalogOutputStatus *value,
////                   typename T::event_variation_t defaultVariation,
    event_variation_t_in_AnalogOutputStatusInfo  defaultVariation,
    Node_for_EventRecord* record);

//----------------------------------AnalogOutputStatusSpec-----------------------------------------------
//----------------------------------OctetStringSpec-----------------------------------------------
////template<class T> struct TypedEventRecord
typedef struct
{
////  TypedEventRecord() = default;
////
////
////  typename T::meas_t value;
  OctetString value;
////  typename T::event_variation_t defaultVariation;
  event_variation_t_in_OctetStringInfo  defaultVariation;
////  typename T::event_variation_t selectedVariation;
  event_variation_t_in_OctetStringInfo  selectedVariation;
////  Node<EventRecord>* record = nullptr;
  Node_for_EventRecord* record;//// = nullptr;
} TypedEventRecord_for_OctetStringSpec;

void TypedEventRecord_for_OctetStringSpec_in_TypedEventRecord_for_OctetStringSpec(TypedEventRecord_for_OctetStringSpec *pTypedEventRecord_for_OctetStringSpec,
////                   const typename T::meas_t& value,
    OctetString *value,
////                   typename T::event_variation_t defaultVariation,
    event_variation_t_in_OctetStringInfo  defaultVariation,
    Node_for_EventRecord* record);

//----------------------------------OctetStringSpec-----------------------------------------------

#endif
