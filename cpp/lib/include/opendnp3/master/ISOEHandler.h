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
#ifndef OPENDNP3_ISOEHANDLER_H
#define OPENDNP3_ISOEHANDLER_H

#include "AnalogCommandEvent.h"
#include "BinaryCommandEvent.h"
#include "Indexed.h"
#include "MeasurementTypes.h"
#include "OctetString.h"
#include "ICollection.h"
#include "HeaderInfo.h"
#include "ResponseInfo.h"

////namespace opendnp3
////{

/**
 * An interface for Sequence-Of-Events (SOE) callbacks from a master stack to
 * the application layer.
 *
 * A call is made to the appropriate member method for every measurement value in an ASDU.
 * The HeaderInfo class provides information about the object header associated with the value.
* Интерфейс для обратных вызовов Sequence-Of-Events (SOE) из главного стека в
  * прикладной уровень.
  *
  * Вызов соответствующего метода-члена выполняется для каждого значения измерения в ASDU.
  * Класс HeaderInfo предоставляет информацию о заголовке объекта, связанном со значением.
 *
 */
////class ISOEHandler
typedef struct
{

////public:
////    virtual ~ISOEHandler() = default;

  void (*pBeginFragment_in_ISOEHandler)(void*, ResponseInfo* info);// = 0;
  void (*pEndFragment_in_ISOEHandler)(void*, ResponseInfo* info);// = 0;

  void (*pProcess_Indexed_for_Binary_in_ISOEHandler)(void*, HeaderInfo* info, ICollection_Indexed_for_Binary* values);// = 0;
  void (*pProcess_Indexed_for_DoubleBitBinary_in_ISOEHandler)(void*, HeaderInfo* info, ICollection_Indexed_for_DoubleBitBinary* values);// = 0;
  void (*pProcess_Indexed_for_Analog_in_ISOEHandler)(void*, HeaderInfo* info, ICollection_Indexed_for_Analog* values);// = 0;
  void (*pProcess_Indexed_for_Counter_in_ISOEHandler)(void*, HeaderInfo* info, ICollection_Indexed_for_Counter* values);// = 0;
  void (*pProcess_Indexed_for_FrozenCounter_in_ISOEHandler)(void*, HeaderInfo* info, ICollection_Indexed_for_FrozenCounter* values);// = 0;
  void (*pProcess_Indexed_for_BinaryOutputStatus_in_ISOEHandler)(void*, HeaderInfo* info, ICollection_Indexed_for_BinaryOutputStatus* values);// = 0;
  void (*pProcess_Indexed_for_AnalogOutputStatus_in_ISOEHandler)(void*, HeaderInfo* info, ICollection_Indexed_for_AnalogOutputStatus* values);// = 0;
  void (*pProcess_Indexed_for_OctetString_in_ISOEHandler)(void*, HeaderInfo* info, ICollection_Indexed_for_OctetString* values);// = 0;
  void (*pProcess_Indexed_for_TimeAndInterval_in_ISOEHandler)(void*, HeaderInfo* info, ICollection_Indexed_for_TimeAndInterval* values);// = 0;
  void (*pProcess_Indexed_for_BinaryCommandEvent_in_ISOEHandler)(void*, HeaderInfo* info, ICollection_Indexed_for_BinaryCommandEvent* values);// = 0;
  void (*pProcess_Indexed_for_AnalogCommandEvent_in_ISOEHandler)(void*, HeaderInfo* info, ICollection_Indexed_for_AnalogCommandEvent* values);// = 0;
  void (*pProcess_for_DNPTime_in_ISOEHandler)(void*, HeaderInfo* info, ICollection_for_DNPTime* values);// = 0;

  void* pParentPointer_in_ISOEHandler;
} ISOEHandler;

void BeginFragment_in_ISOEHandler(ISOEHandler* pISOEHandler, ResponseInfo* info);
void EndFragment_in_ISOEHandler(ISOEHandler* pISOEHandler, ResponseInfo* info);

void Process_Indexed_for_Binary_in_ISOEHandler(ISOEHandler* pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_Binary* values);
void Process_Indexed_for_DoubleBitBinary_in_ISOEHandler(ISOEHandler* pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_DoubleBitBinary* values);
void Process_Indexed_for_Analog_in_ISOEHandler(ISOEHandler* pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_Analog* values);
void Process_Indexed_for_Counter_in_ISOEHandler(ISOEHandler* pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_Counter* values);
void Process_Indexed_for_FrozenCounter_in_ISOEHandler(ISOEHandler* pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_FrozenCounter* values);
void Process_Indexed_for_BinaryOutputStatus_in_ISOEHandler(ISOEHandler* pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_BinaryOutputStatus* values);
void Process_Indexed_for_AnalogOutputStatus_in_ISOEHandler(ISOEHandler* pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_AnalogOutputStatus* values);
void Process_Indexed_for_OctetString_in_ISOEHandler(ISOEHandler* pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_OctetString* values);
void Process_Indexed_for_TimeAndInterval_in_ISOEHandler(ISOEHandler* pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_TimeAndInterval* values);
void Process_Indexed_for_BinaryCommandEvent_in_ISOEHandler(ISOEHandler* pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_BinaryCommandEvent* values);
void Process_Indexed_for_AnalogCommandEvent_in_ISOEHandler(ISOEHandler* pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_AnalogCommandEvent* values);
void Process_for_DNPTime_in_ISOEHandler(ISOEHandler* pISOEHandler, HeaderInfo* info, ICollection_for_DNPTime* values);

void* getParentPointer_in_ISOEHandler(ISOEHandler*);
void  setParentPointer_in_ISOEHandler(ISOEHandler*, void*);

////} // namespace opendnp3

#endif
