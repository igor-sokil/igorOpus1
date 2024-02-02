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
#ifndef OPENDNP3_DEFAULTMASTERAPPLICATION_H
#define OPENDNP3_DEFAULTMASTERAPPLICATION_H

#include "IMasterApplication.h"

////#include <memory>

////namespace opendnp3
////{

////class DefaultMasterApplication final : public IMasterApplication
typedef struct
{
  IMasterApplication iIMasterApplication;

////public:
////    DefaultMasterApplication() {}

////    static std::shared_ptr<IMasterApplication> Create()
////    {
////        return std::make_shared<DefaultMasterApplication>();
////    }

////    virtual void OnReceiveIIN(const IINField& iin) final {}

////    virtual void OnTaskStart(MasterTaskType type, TaskId id) final {}

////    virtual void OnTaskComplete(const TaskInfo& info) final {}

////    virtual bool AssignClassDuringStartup() final
////    {
////        return false;
////    }

////    virtual void ConfigureAssignClassRequest(const WriteHeaderFunT& fun) final {}

////    virtual UTCTimestamp Now() final;

////    virtual void OnStateChange(LinkStatus value) final {}
} DefaultMasterApplication;

void DefaultMasterApplication_in_DefaultMasterApplication(DefaultMasterApplication *pDefaultMasterApplication);
IMasterApplication* Create_in_DefaultMasterApplication_static(void);

void OnReceiveIIN_in_DefaultMasterApplication(DefaultMasterApplication *pDefaultMasterApplication, IINField* iin);
void OnReceiveIIN_in_DefaultMasterApplication_override(void *pIMasterApplication, IINField* iin);

void OnTaskStart_in_DefaultMasterApplication(DefaultMasterApplication *pDefaultMasterApplication, MasterTaskType_uint8_t type, TaskId id);
void OnTaskStart_in_DefaultMasterApplication_override(void *pIMasterApplication, MasterTaskType_uint8_t type, TaskId id);

void OnTaskComplete_in_DefaultMasterApplication(DefaultMasterApplication *pDefaultMasterApplication, TaskInfo* info);
void OnTaskComplete_in_DefaultMasterApplication_override(void *pIMasterApplication, TaskInfo* info);

boolean AssignClassDuringStartup_in_DefaultMasterApplication(DefaultMasterApplication *pDefaultMasterApplication);
boolean AssignClassDuringStartup_in_DefaultMasterApplication_override(void *pIMasterApplication);

void ConfigureAssignClassRequest_in_DefaultMasterApplication(DefaultMasterApplication *pDefaultMasterApplication, WriteHeaderFunT fun);
void ConfigureAssignClassRequest_in_DefaultMasterApplication_override(void *pIMasterApplication, WriteHeaderFunT fun);

UTCTimestamp Now_in_DefaultMasterApplication(DefaultMasterApplication *pDefaultMasterApplication);
UTCTimestamp Now_in_DefaultMasterApplication_override(void *pIMasterApplication);

void OnStateChange_in_DefaultMasterApplication(DefaultMasterApplication *pDefaultMasterApplication, LinkStatus_uint8_t value);
void OnStateChange_in_DefaultMasterApplication_override(void *pILinkListener, LinkStatus_uint8_t value);


////} // namespace opendnp3

#endif
