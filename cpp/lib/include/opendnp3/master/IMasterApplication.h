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
#ifndef OPENDNP3_IMASTERAPPLICATION_H
#define OPENDNP3_IMASTERAPPLICATION_H

#include "IINField.h"
#include "MasterTaskType.h"
#include "TaskCompletion.h"
#include "ILinkListener.h"
#include "HeaderTypes.h"
#include "IUTCTimeSource.h"
#include "TaskInfo.h"

////#include <functional>

////namespace opendnp3
////{

////typedef std::function<void(const Header&)> WriteHeaderFunT;
typedef void (*WriteHeaderFunT)(Header*);

/**
 * Interface for all master application callback info except for measurement values.
* »нтерфейс дл€ всей информации обратного вызова основного приложени€, за исключением значений измерений.
 */
////class IMasterApplication : public ILinkListener, public IUTCTimeSource
typedef struct
{
  ILinkListener iILinkListener;
  IUTCTimeSource  iIUTCTimeSource;

////public:
////    virtual ~IMasterApplication() {}

  /// Called when a response or unsolicited response is receive from the outstation
/// ¬ызываетс€ при получении ответа или незапрошенного ответа от удаленной станции
////    virtual void OnReceiveIIN(const IINField& iin) {}
  void (*pOnReceiveIIN_in_IMasterApplication)(void *, IINField* iin);

  /// Task start notification
////    virtual void OnTaskStart(MasterTaskType type, TaskId id) {}
  void (*pOnTaskStart_in_IMasterApplication)(void *, MasterTaskType_uint8_t type, TaskId* id);

  /// Task completion notification
////    virtual void OnTaskComplete(const TaskInfo& info) {}
  void (*pOnTaskComplete_in_IMasterApplication)(void *, TaskInfo* info);

  /// Called when the application layer is opened
////    virtual void OnOpen() {}
  void (*pOnOpen_in_IMasterApplication)(void *);

  /// Called when the application layer is closed
////    virtual void OnClose() {}
  void (*pOnClose_in_IMasterApplication)(void *);

  /// @return true if the master should do an assign class task during startup handshaking
/// @return true, если мастер должен выполнить задачу назначени€ класса во врем€ установлени€ св€зи при запуске
////    virtual bool AssignClassDuringStartup()
////    {
////        return false;
////    }
  boolean (*pAssignClassDuringStartup_in_IMasterApplication)(void *);
////    {
////        return false;
////    }

  /// Configure the request headers for assign class. Only called if
  /// "AssignClassDuringStartup" returns true
  /// The user only needs to call the function for each header type to be written
/// Ќастройте заголовки запроса дл€ назначени€ класса. «вонок только если
  /// "AssignClassDuringStartup" возвращает true
  /// ѕользователю нужно вызывать функцию только дл€ каждого типа заголовка, который нужно записать
////    virtual void ConfigureAssignClassRequest(const WriteHeaderFunT& fun) {}
  void (*pConfigureAssignClassRequest_in_IMasterApplication)(void *, WriteHeaderFunT fun);

  void* pParentPointer_in_IMasterApplication;

} IMasterApplication;

void IMasterApplication_in_IMasterApplication(IMasterApplication *pIMasterApplication);

void OnReceiveIIN_in_IMasterApplication(IMasterApplication *pIMasterApplication, IINField* iin);
void OnTaskStart_in_IMasterApplication(IMasterApplication *pIMasterApplication, MasterTaskType_uint8_t type, TaskId* id);
void OnTaskComplete_in_IMasterApplication(IMasterApplication* pIMasterApplication, TaskInfo* info);
void OnOpen_in_IMasterApplication(IMasterApplication* pIMasterApplication);
void OnClose_in_IMasterApplication(IMasterApplication *pIMasterApplication);
boolean AssignClassDuringStartup_in_IMasterApplication(IMasterApplication *pIMasterApplication);
void ConfigureAssignClassRequest_in_IMasterApplication(IMasterApplication *pIMasterApplication, WriteHeaderFunT fun);

void OnReceiveIIN_in_IMasterApplication_override(void *pIMasterApplication, IINField* iin);
void OnTaskStart_in_IMasterApplication_override(void *pIMasterApplication, MasterTaskType_uint8_t type, TaskId* id);
void OnTaskComplete_in_IMasterApplication_override(void* pIMasterApplication, TaskInfo* info);
void OnOpen_in_IMasterApplication_override(void* pIMasterApplication);
void OnClose_in_IMasterApplication_override(void *pIMasterApplication);
boolean AssignClassDuringStartup_in_IMasterApplication_override(void *pIMasterApplication);
void ConfigureAssignClassRequest_in_IMasterApplication_override(void *pIMasterApplication, WriteHeaderFunT fun);

void* getParentPointer_in_IMasterApplication(IMasterApplication*);
void  setParentPointer_in_IMasterApplication(IMasterApplication*, void*);

////} // namespace opendnp3

#endif
