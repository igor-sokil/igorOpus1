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
#ifndef OPENDNP3_LANTIMESYNCTASK_H
#define OPENDNP3_LANTIMESYNCTASK_H

#include "IMasterTask.h"
#include "TaskPriority.h"

////namespace opendnp3
////{

#define State_in_LANTimeSyncTask_uint8_t uint8_t
enum ///State
{
  State_in_LANTimeSyncTask_RECORD_CURRENT_TIME,
  State_in_LANTimeSyncTask_WRITE_TIME
};

// Synchronizes the time on the outstation
////class LANTimeSyncTask : public IMasterTask
typedef struct
{
  IMasterTask iIMasterTask;

////    enum State
////    {
////        RECORD_CURRENT_TIME,
////        WRITE_TIME
////    };

////public:
////    LANTimeSyncTask(const std::shared_ptr<TaskContext>& context, IMasterApplication& app, const Logger& logger);

////    virtual char const* Name() const override final
////    {
////        return "LAN time sync";
////    }

////    virtual int Priority() const override final
////    {
////        return priority::TIME_SYNC;
////    }

////    virtual bool BlocksLowerPriority() const override final
////    {
////        return true;
////    }

////    virtual bool IsRecurring() const override final
////    {
////        return true;
////    }

////    virtual bool BuildRequest(APDURequest& request, uint8_t seq) override final;

////private:
////    virtual MasterTaskType GetTaskType() const override final
////    {
////        return MasterTaskType::LAN_TIME_SYNC;
////    }

////    virtual bool IsEnabled() const override final
////    {
////        return true;
////    }

////    virtual ResponseResult ProcessResponse(const APDUResponseHeader& response,
////                                           const ser4cpp::rseq_t& objects) override final;

////    ResponseResult OnResponseRecordCurrentTime(const APDUResponseHeader& response, const ser4cpp::rseq_t& objects);

////    ResponseResult OnResponseWriteTime(const APDUResponseHeader& header, const ser4cpp::rseq_t& objects);

////    virtual void Initialize() override final;

  State_in_LANTimeSyncTask_uint8_t state;// = State::RECORD_CURRENT_TIME;

  // what time we sent the delay meas
// � ����� ����� �� ��������� ��������� ��������
  UTCTimestamp start;
} LANTimeSyncTask;

////} // namespace opendnp3

////    virtual int Priority() const override final
////    {
////        return priority::TIME_SYNC;
////    }

////    virtual bool BlocksLowerPriority() const override final
////    {
////        return true;
////    }

////    virtual bool IsRecurring() const override final
////    {
////        return true;
////    }

////    virtual bool BuildRequest(APDURequest& request, uint8_t seq) override final;

////private:
////    virtual MasterTaskType GetTaskType() const override final
////    {
////        return MasterTaskType::LAN_TIME_SYNC;
////    }

////    virtual bool IsEnabled() const override final
////    {
////        return true;
////    }

void LANTimeSyncTask_in_LANTimeSyncTask(LANTimeSyncTask *pLANTimeSyncTask,
//                       const std::shared_ptr<TaskContext>& context,
                                        IMasterApplication* application);

boolean IsRecurring_in_LANTimeSyncTask(LANTimeSyncTask *pLANTimeSyncTask);
boolean IsRecurring_in_LANTimeSyncTask_override(void *pIMasterTask);

boolean BuildRequest_in_LANTimeSyncTask(LANTimeSyncTask *pLANTimeSyncTask, APDURequest* request, uint8_t seq);
boolean BuildRequest_in_LANTimeSyncTask_override(void *pIMasterTask, APDURequest* request, uint8_t seq);

int Priority_in_LANTimeSyncTask(LANTimeSyncTask *pLANTimeSyncTask);
int Priority_in_LANTimeSyncTask_override(void *pIMasterTask);

MasterTaskType_uint8_t GetTaskType_in_LANTimeSyncTask(LANTimeSyncTask *pLANTimeSyncTask);
MasterTaskType_uint8_t GetTaskType_in_LANTimeSyncTask_override(void *pIMasterTask);

boolean IsEnabled_in_LANTimeSyncTask(LANTimeSyncTask *pLANTimeSyncTask);
boolean IsEnabled_in_LANTimeSyncTask_override(void *pIMasterTask);

ResponseResult_in_IMasterTask_uint8_t ProcessResponse_in_LANTimeSyncTask(LANTimeSyncTask *pLANTimeSyncTask,
    APDUResponseHeader* header, RSeq_for_Uint16_t* objects);
ResponseResult_in_IMasterTask_uint8_t ProcessResponse_in_LANTimeSyncTask_override(void *pIMasterTask,
    APDUResponseHeader* header, RSeq_for_Uint16_t* objects);

ResponseResult_in_IMasterTask_uint8_t OnResponseRecordCurrentTime_in_LANTimeSyncTask(LANTimeSyncTask *pLANTimeSyncTask,
    APDUResponseHeader* response, RSeq_for_Uint16_t* objects);

ResponseResult_in_IMasterTask_uint8_t OnResponseWriteTime_in_LANTimeSyncTask(LANTimeSyncTask *pLANTimeSyncTask, APDUResponseHeader* header, RSeq_for_Uint16_t* objects);

void Initialize_in_LANTimeSyncTask(LANTimeSyncTask *pLANTimeSyncTask);
void Initialize_in_LANTimeSyncTask_override(void *pIMasterTask);

char * Name_in_LANTimeSyncTask(LANTimeSyncTask *pLANTimeSyncTask);
char * Name_in_LANTimeSyncTask_override(void *pLANTimeSyncTask);

#endif
