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

#ifndef OPENDNP3_TYPEDSTORAGE_H
#define OPENDNP3_TYPEDSTORAGE_H

////#include "List.h"
////#include "TypedEventRecord.h"

//#include "List_for_EventRecord.h"
#include "TypedEventRecord.h"
#include "Node_TypedEventRecord_for_BinarySpec.h"
#include "Node_TypedEventRecord_for_DoubleBitBinarySpec.h"
#include "Node_TypedEventRecord_for_AnalogSpec.h"
#include "Node_TypedEventRecord_for_CounterSpec.h"
#include "Node_TypedEventRecord_for_FrozenCounterSpec.h"
#include "Node_TypedEventRecord_for_BinaryOutputStatusSpec.h"
#include "Node_TypedEventRecord_for_AnalogOutputStatusSpec.h"
#include "Node_TypedEventRecord_for_OctetStringSpec.h"

////namespace opendnp3
////{

////template<class T> struct TypedStorage : private StaticOnly
////{

////    static inline Node<TypedEventRecord<T>>* Retrieve(EventRecord& record)
////    {
////        return reinterpret_cast<Node<TypedEventRecord<T>>*>(record.storage_node);
////    }
////};
//----------------------------------BinarySpec-----------------------------------------------

Node_TypedEventRecord_for_BinarySpec* Retrieve_in_TypedStorage_for_BinarySpec_static(EventRecord* record);
//----------------------------------BinarySpec-----------------------------------------------
//----------------------------------DoubleBitBinarySpec-----------------------------------------------

Node_TypedEventRecord_for_DoubleBitBinarySpec* Retrieve_in_TypedStorage_for_DoubleBitBinarySpec_static(EventRecord* record);
//----------------------------------DoubleBitBinarySpec-----------------------------------------------
//----------------------------------AnalogSpec-----------------------------------------------

Node_TypedEventRecord_for_AnalogSpec* Retrieve_in_TypedStorage_for_AnalogSpec_static(EventRecord* record);
//----------------------------------AnalogSpec-----------------------------------------------
//----------------------------------CounterSpec-----------------------------------------------

Node_TypedEventRecord_for_CounterSpec* Retrieve_in_TypedStorage_for_CounterSpec_static(EventRecord* record);
//----------------------------------CounterSpec-----------------------------------------------
//----------------------------------FrozenCounterSpec-----------------------------------------------

Node_TypedEventRecord_for_FrozenCounterSpec* Retrieve_in_TypedStorage_for_FrozenCounterSpec_static(EventRecord* record);
//----------------------------------FrozenCounterSpec-----------------------------------------------
//----------------------------------BinaryOutputStatusSpec-----------------------------------------------

Node_TypedEventRecord_for_BinaryOutputStatusSpec* Retrieve_in_TypedStorage_for_BinaryOutputStatusSpec_static(EventRecord* record);
//----------------------------------BinaryOutputStatusSpec-----------------------------------------------
//----------------------------------AnalogOutputStatusSpec-----------------------------------------------

Node_TypedEventRecord_for_AnalogOutputStatusSpec* Retrieve_in_TypedStorage_for_AnalogOutputStatusSpec_static(EventRecord* record);
//----------------------------------AnalogOutputStatusSpec-----------------------------------------------
//----------------------------------OctetStringSpec-----------------------------------------------

Node_TypedEventRecord_for_OctetStringSpec* Retrieve_in_TypedStorage_for_OctetStringSpec_static(EventRecord* record);
//----------------------------------OctetStringSpec-----------------------------------------------

////} // namespace opendnp3

#endif
