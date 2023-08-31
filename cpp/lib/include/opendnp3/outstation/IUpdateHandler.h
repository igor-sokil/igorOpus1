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
#ifndef OPENDNP3_IUPDATEHANDLER_H
#define OPENDNP3_IUPDATEHANDLER_H

////#include "opendnp3/app/MeasurementTypes.h"
////#include "opendnp3/app/OctetString.h"
////#include "opendnp3/gen/EventMode.h"
////#include "opendnp3/gen/FlagsType.h"

#include "MeasurementTypes.h"
#include "OctetString.h"
#include "EventMode.h"
#include "FlagsType.h"

////namespace opendnp3
////{

/**
 * An interface used to update measurement values.
 */
////class IUpdateHandler
typedef struct
{
////public:
  //virtual ~
  void (*pIUpdateHandler_destr_IUpdateHandler)(void*);

  /**
   * Update a Binary measurement
   * @param meas measurement to be processed
   * @param index index of the measurement
   * @param mode Describes how event generation is handled for this method
   * @return true if the value exists and it was updated
* Обновление двоичного измерения.
    * @param измеряет измерение, которое необходимо обработать
    * @param index индекс измерения
    * @param mode Описывает, как для этого метода обрабатывается генерация событий.
    * @return true, если значение существует и оно было обновлено
   */
  boolean (*pUpdate_Binary_in_IUpdateHandler)(void*, Binary* meas, uint16_t index, EventMode_uint8_t mode);// = EventMode::Detect) = 0;

  /**
   * Update a DoubleBitBinary measurement
   * @param meas measurement to be processed
   * @param index index of the measurement
   * @param mode Describes how event generation is handled for this method
   * @return true if the value exists and it was updated
* Обновление измерения DoubleBitBinary.
    * @param измеряет измерение, которое необходимо обработать
    * @param index индекс измерения
    * @param mode Описывает, как для этого метода обрабатывается генерация событий.
    * @return true, если значение существует и оно было обновлено
   */
  boolean (*pUpdate_DoubleBitBinary_in_IUpdateHandler)(void*, DoubleBitBinary* meas, uint16_t index, EventMode_uint8_t mode);// = EventMode::Detect) = 0;

  /**
   * Update an Analog measurement
   * @param meas measurement to be processed
   * @param index index of the measurement
   * @param mode Describes how event generation is handled for this method
   * @return true if the value exists and it was updated
   */
  boolean (*pUpdate_Analog_in_IUpdateHandler)(void*, Analog* meas, uint16_t index, EventMode_uint8_t mode);// = EventMode::Detect) = 0;

  /**
   * Update a Counter measurement
   * @param meas measurement to be processed
   * @param index index of the measurement
   * @param mode Describes how event generation is handled for this method
   * @return true if the value exists and it was updated
   */
  boolean (*pUpdate_Counter_in_IUpdateHandler)(void*, Counter* meas, uint16_t index, EventMode_uint8_t mode);// = EventMode::Detect) = 0;

  /**
   * Freeze a Counter measurement
   * @param index index of the measurement
   * @param clear clear the original counter
   * @param mode Describes how event generation is handled for this method
   * @return true if the value exists and it was updated
   */
  boolean (*pFreezeCounter_in_IUpdateHandler)(void*, uint16_t index, boolean clear, EventMode_uint8_t mode);//bool clear = false, EventMode mode = EventMode::Detect) = 0;

  /**
   * Update a BinaryOutputStatus measurement
   * @param meas measurement to be processed
   * @param index index of the measurement
   * @param mode Describes how event generation is handled for this method
   * @return true if the value exists and it was updated
   */
  boolean (*pUpdate_BinaryOutputStatus_in_IUpdateHandler)(void*, BinaryOutputStatus* meas, uint16_t index, EventMode_uint8_t mode);// = EventMode::Detect) = 0;

  /**
   * Update a AnalogOutputStatus measurement
   * @param meas measurement to be processed
   * @param index index of the measurement
   * @param mode Describes how event generation is handled for this method
   * @return true if the value exists and it was updated
   */
  boolean (*pUpdate_AnalogOutputStatus_in_IUpdateHandler)(void*, AnalogOutputStatus* meas, uint16_t index, EventMode_uint8_t mode);// = EventMode::Detect) = 0;

  /**
   * Update an octet string value
   * @param meas measurement to be processed
   * @param index index of the measurement
   * @param mode Describes how event generation is handled for this method
   * @return true if the value exists and it was updated
   */
  boolean (*pUpdate_OctetString_in_IUpdateHandler)(void*, OctetString* meas, uint16_t index, EventMode_uint8_t mode);// = EventMode::Detect) = 0;

  /**
   * Update a TimeAndInterval valueindex
   * @param meas measurement to be processed
   * @param index index of the measurement
   * @return true if the value exists and it was updated
   */
  boolean (*pUpdate_TimeAndInterval_in_IUpdateHandler)(void*, TimeAndInterval* meas, uint16_t index);// = 0;

  /**
   * Update the flags of a measurement without changing it's value
   * @param type enumeration specifiy the type to change
   * @param start the start index at which to begin changing flags
   * @param stop the stop index at which to end changing flags
   * @param flags the new value of the flags
   */
  boolean (*pModify_in_IUpdateHandler)(void*, FlagsType_uint8_t type, uint16_t start, uint16_t stop, uint8_t flags);// = 0;

  void* pParentPointer_in_IUpdateHandler;
} IUpdateHandler;

void IUpdateHandler_destr_IUpdateHandler(IUpdateHandler*);
boolean Update_Binary_in_IUpdateHandler(IUpdateHandler*, Binary* meas, uint16_t index, EventMode_uint8_t mode);// = EventMode::Detect) = 0;
boolean Update_DoubleBitBinary_in_IUpdateHandler(IUpdateHandler*, DoubleBitBinary* meas, uint16_t index, EventMode_uint8_t mode);// = EventMode::Detect) = 0;
boolean Update_Analog_in_IUpdateHandler(IUpdateHandler*, Analog* meas, uint16_t index, EventMode_uint8_t mode);// = EventMode::Detect) = 0;
boolean Update_Counter_in_IUpdateHandler(IUpdateHandler*, Counter* meas, uint16_t index, EventMode_uint8_t mode);// = EventMode::Detect) = 0;
boolean FreezeCounter_in_IUpdateHandler(IUpdateHandler*, uint16_t index, boolean clear, EventMode_uint8_t mode);//bool clear = false, EventMode mode = EventMode::Detect) = 0;
boolean Update_BinaryOutputStatus_in_IUpdateHandler(IUpdateHandler*, BinaryOutputStatus* meas, uint16_t index, EventMode_uint8_t mode);// = EventMode::Detect) = 0;
boolean Update_AnalogOutputStatus_in_IUpdateHandler(IUpdateHandler*, AnalogOutputStatus* meas, uint16_t index, EventMode_uint8_t mode);// = EventMode::Detect) = 0;
boolean Update_OctetString_in_IUpdateHandler(IUpdateHandler*, OctetString* meas, uint16_t index, EventMode_uint8_t mode);// = EventMode::Detect) = 0;
boolean Update_TimeAndInterval_in_IUpdateHandler(IUpdateHandler*, TimeAndInterval* meas, uint16_t index);// = 0;
boolean Modify_in_IUpdateHandler(IUpdateHandler*, FlagsType_uint8_t type, uint16_t start, uint16_t stop, uint8_t flags);// = 0;

void* getParentPointer_in_IUpdateHandler(IUpdateHandler*);
void  setParentPointer_in_IUpdateHandler(IUpdateHandler*, void*);

////} // namespace opendnp3

#endif
