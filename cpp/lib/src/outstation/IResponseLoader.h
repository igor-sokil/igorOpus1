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
#ifndef OPENDNP3_IRESPONSELOADER_H
#define OPENDNP3_IRESPONSELOADER_H

////#include "app/HeaderWriter.h"
#include "HeaderWriter.h"

////namespace opendnp3
////{

////class IResponseLoader
typedef struct
{
////public:
  /**
   * @ return True if there is any data selected for reporting
   */
  boolean (*pHasAnySelection_in_IResponseLoader)(void*);// const = 0;

  /**
   * Loads static data into a response APDU
   *
   * @param writer The HeaderWriter instance used to place data in the APDU
   * @return True if all data was loaded, false if there is no more space
   */
  boolean (*pLoad_in_IResponseLoader)(void*, HeaderWriter* writer);// = 0;

  void* pParentPointer_in_IResponseLoader;
} IResponseLoader;

boolean HasAnySelection_in_IResponseLoader(IResponseLoader *);
boolean Load_in_IResponseLoader(IResponseLoader *, HeaderWriter* writer);

void* getParentPointer_in_IResponseLoader(IResponseLoader*);
void  setParentPointer_in_IResponseLoader(IResponseLoader*, void*);

////} // namespace opendnp3

#endif
