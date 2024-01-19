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
#ifndef OPENDNP3_ITASKCALLBACK_H
#define OPENDNP3_ITASKCALLBACK_H

#include "TaskCompletion.h"

////namespace opendnp3
////{

/**
 * Callbacks for when a task starts and completes
* Обратные вызовы, когда задача запускается и завершается.
 */
////class ITaskCallback
typedef struct
{
public:
    // Called when the task starts running
// Вызывается, когда задача начинает выполняться
    void (*pOnStart_in_ITaskCallback)(void *);// = 0;

    // Called when the task succeeds or fails
// Вызывается, когда задача выполнена успешно или неудачно
    void (*pOnComplete_in_ITaskCallback)(void *, TaskCompletion_uint8_t result);// = 0;

    // Called when the task no longer exists and no more calls will be made to OnStart/OnComplete
// Вызывается, когда задача больше не существует и вызовы OnStart/OnComplete больше не выполняются
    void (*pOnDestroyed_in_ITaskCallback)(void *);// = 0;

  void* pParentPointer_in_ITaskCallback;

} ITaskCallback;

void OnStart_in_ITaskCallback(ITaskCallback* pITaskCallback);
void OnComplete_in_ITaskCallback(ITaskCallback* pITaskCallback, TaskCompletion_uint8_t result);
void OnDestroyed_in_ITaskCallback(ITaskCallback* pITaskCallback);

void* getParentPointer_in_ITaskCallback(ITaskCallback*);
void  setParentPointer_in_ITaskCallback(ITaskCallback*, void*);

////} // namespace opendnp3

#endif
