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
#ifndef OPENDNP3_IDNPTIMESOURCE_H
#define OPENDNP3_IDNPTIMESOURCE_H

////#include "opendnp3/app/DNPTime.h"
#include "DNPTime.h"

////namespace opendnp3
////{

/**
 *  Interface that defines a method to get DNPTime source
 */
////class IDnpTimeSource
typedef struct
{

  DNPTime (*pNow_in_IDnpTimeSource_static)(void*);
////public:
  /**
   * Returns a DNPTime of the current time.
   * This value is used when freezing counters.
   */
////    virtual DNPTime Now()
////    {
////        return DNPTime(0, TimestampQuality::INVALID);
////    }

  void* pParentPointer_in_IDnpTimeSource;
} IDnpTimeSource;

DNPTime Now_in_IDnpTimeSource_static(IDnpTimeSource*);
DNPTime Now_in_IDnpTimeSource_static_override(void*);
void IDnpTimeSource_in_IDnpTimeSource(IDnpTimeSource *pIDnpTimeSource);

void* getParentPointer_in_IDnpTimeSource(IDnpTimeSource*);
void  setParentPointer_in_IDnpTimeSource(IDnpTimeSource*, void*);


////} // namespace opendnp3

#endif
