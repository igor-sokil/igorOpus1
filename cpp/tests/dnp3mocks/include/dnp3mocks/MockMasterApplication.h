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
#ifndef OPENDNP3_UNITTESTS_MOCK_MASTER_APPLICATION_H
#define OPENDNP3_UNITTESTS_MOCK_MASTER_APPLICATION_H

#include "IMasterApplication.h"

#include <deque>
////#include <functional>
#include <vector>

#define State_in_MockMasterApplication_uint8_t uint8_t
enum //class State
{
  State_in_MockMasterApplication_OPEN,
  State_in_MockMasterApplication_CLOSED
};

////class MockMasterApplication final : public opendnp3::IMasterApplication
typedef struct
{
  IMasterApplication iIMasterApplication;

////public:
////    enum class State
////    {
////        OPEN,
////        CLOSED
////    };

////    MockMasterApplication() : time(0) {}

////    virtual opendnp3::UTCTimestamp Now() override
////    {
////        return opendnp3::UTCTimestamp(time);
////    }

////    virtual void OnReceiveIIN(const opendnp3::IINField& iin) override
////    {
////        rxIIN.push_back(iin);
////    }

////    virtual void OnTaskStart(opendnp3::MasterTaskType type, opendnp3::TaskId id) override
////    {
////        taskStartEvents.push_back(type);
////    }

////    virtual void OnTaskComplete(const opendnp3::TaskInfo& info) override
////    {
////        taskCompletionEvents.push_back(info);
////    }

////    virtual void OnOpen() override
////    {
////        this->stateChanges.push_back(State::OPEN);
////    }

////    virtual void OnClose() override
////    {
////        this->stateChanges.push_back(State::CLOSED);
////    }

////    virtual bool AssignClassDuringStartup() override
////    {
////        return !assignClassHeaders.empty();
////    }

////    virtual void ConfigureAssignClassRequest(const opendnp3::WriteHeaderFunT& fun) override
////    {
////        for (auto& header : assignClassHeaders)
////        {
////            fun(header);
////        }
////    }

  std::deque<State_in_MockMasterApplication_uint8_t> stateChanges;

  std::vector<Header> assignClassHeaders;

  std::vector<IINField> rxIIN;

  std::vector<MasterTaskType_uint8_t> taskStartEvents;
  std::vector<TaskInfo> taskCompletionEvents;

  uint64_t timeMasterApplication;
} MockMasterApplication;

void MockMasterApplication_in_MockMasterApplication(MockMasterApplication *pMockMasterApplication);

UTCTimestamp Now_in_MockMasterApplication(MockMasterApplication *pMockMasterApplication);
UTCTimestamp Now_in_MockMasterApplication_override(void *pIMasterApplication);

void OnReceiveIIN_in_MockMasterApplication(MockMasterApplication *pMockMasterApplication, IINField* iin);
void OnReceiveIIN_in_MockMasterApplication_override(void *pIMasterApplication, IINField* iin);

void OnTaskStart_in_MockMasterApplication(MockMasterApplication *pMockMasterApplication, MasterTaskType_uint8_t type, TaskId id);
void OnTaskStart_in_MockMasterApplication_override(void *pIMasterApplication, MasterTaskType_uint8_t type, TaskId id);

void OnTaskComplete_in_MockMasterApplication(MockMasterApplication *pMockMasterApplication, TaskInfo* info);
void OnTaskComplete_in_MockMasterApplication_override(void *pIMasterApplication, TaskInfo* info);

void OnOpen_in_MockMasterApplication(MockMasterApplication *pMockMasterApplication);
void OnOpen_in_MockMasterApplication_override(void *pIMasterApplication);

void OnClose_in_MockMasterApplication(MockMasterApplication *pMockMasterApplication);
void OnClose_in_MockMasterApplication_override(void *pIMasterApplication);

boolean AssignClassDuringStartup_in_MockMasterApplication(MockMasterApplication *pMockMasterApplication);
boolean AssignClassDuringStartup_in_MockMasterApplication_override(void *pIMasterApplication);

void ConfigureAssignClassRequest_in_MockMasterApplication(MockMasterApplication *pMockMasterApplication, WriteHeaderFunT fun);
void ConfigureAssignClassRequest_in_MockMasterApplication_override(void *pIMasterApplication, WriteHeaderFunT fun);


#endif
