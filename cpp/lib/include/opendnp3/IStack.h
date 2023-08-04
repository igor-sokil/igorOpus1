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
#ifndef OPENDNP3_ISTACK_H
#define OPENDNP3_ISTACK_H

#include "IResource.h"
#include "StackStatistics.h"

////namespace opendnp3
////{

/**
 * Base class for masters or outstations
 */
////class IStack : public IResource
typedef struct
{
IResource iIResource;
////public:
////    virtual ~IStack() {}

    /**
     * Synchronously enable communications
     */
    boolean (*pEnable_in_IStack)(void*);// = 0;

    /**
     * Synchronously disable communications
     */
    boolean (*pDisable_in_IStack)(void*);// = 0;

    /**
     * @return stack statistics counters
     */
    StackStatistics (*pGetStackStatistics_in_IStack)(void*);// = 0;

  void* pParentPointer_in_IStack;
} IStack;

void Enable_in_IStack(IStack* pIStack);
void Disable_in_IStack(IStack* pIStack);
void GetStackStatistics_in_IStack(IStack* pIStack);

void* getParentPointer_in_IStack(IStack*);
void  setParentPointer_in_IStack(IStack*, void*);

////} // namespace opendnp3

#endif
