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
#ifndef OPENDNP3_IOUTSTATION_H
#define OPENDNP3_IOUTSTATION_H

////#include "opendnp3/IStack.h"
////#include "opendnp3/logging/LogLevels.h"
////#include "opendnp3/outstation/Updates.h"
//#include "opendnp3/IStack.h"
//#include "opendnp3/logging/LogLevels.h"
//#include "opendnp3/outstation/Updates.h"
#include "Updates.h"

////namespace opendnp3
////{

/**
 * Interface representing a running outstation.
 */
////class IOutstation : public IStack
typedef struct
{

////public:
/////    ~IOutstation() override = default;

  /**
   *  @param filters Adjust the filters to this value
   */
////    virtual void SetLogFilters(const opendnp3::LogLevels& filters) = 0;

  /**
   * Sets the restart IIN bit. Normally applications should not
   * touch this bit, but it is provided for simulating restarts.
* ������������� ��� IIN �����������. ������ ���������� �� ������
    * ��������� ����� ����, �� �� ������������ ��� �������� �����������.
   */
  void (*pSetRestartIIN_in_IOutstation)(void*);
////    virtual void SetRestartIIN() = 0;

  /**
   * Apply a set of measurement updates to the outstation
* ��������� ����� ���������� ��������� � ��������� �������.
   */
  void (*pApply_in_IOutstation)(void*, Updates* updates);
////    virtual void Apply(const Updates& updates) = 0;

  void* pParentPointer_in_IOutstation;
} IOutstation;

void SetRestartIIN_in_IOutstation(IOutstation*);
void Apply_in_IOutstation(IOutstation*, Updates* updates);

void* getParentPointer_in_IOutstation(IOutstation*);
void  setParentPointer_in_IOutstation(IOutstation*, void*);

////} // namespace opendnp3

#endif
