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
#ifndef OPENDNP3_SERIALTIMESYNCTASK_H
#define OPENDNP3_SERIALTIMESYNCTASK_H

#include "IMasterTask.h"
#include "TaskPriority.h"

////namespace opendnp3
////{

// Synchronizes the time on the outstation
////class SerialTimeSyncTask : public IMasterTask
typedef struct
{
  IMasterTask iIMasterTask;

////public:
////    SerialTimeSyncTask(const std::shared_ptr<TaskContext>& context, IMasterApplication& app, const Logger& logger);

////    virtual char const* Name() const override final
////    {
////        return "serial time sync";
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
////        return MasterTaskType::NON_LAN_TIME_SYNC;
////    }

////    virtual bool IsEnabled() const override final
////    {
////        return true;
////    }

////    virtual ResponseResult ProcessResponse(const APDUResponseHeader& response,
////                                           const ser4cpp::rseq_t& objects) override final;

////    ResponseResult OnResponseDelayMeas(const APDUResponseHeader& response, const ser4cpp::rseq_t& objects);

////    ResponseResult OnResponseWriteTime(const APDUResponseHeader& header, const ser4cpp::rseq_t& objects);

////    virtual void Initialize() override final;

  // < 0 implies the delay measure hasn't happened yet
// < 0 означает, что мера задержки еще не произошла
  int64_t delay;

  // what time we sent the delay meas
// в какое время мы отправили измерение задержки
  UTCTimestamp start;
} SerialTimeSyncTask;

void SerialTimeSyncTask_in_SerialTimeSyncTask(SerialTimeSyncTask *pSerialTimeSyncTask,
//                       const std::shared_ptr<TaskContext>& context,
    IMasterApplication* application);

boolean IsRecurring_in_SerialTimeSyncTask(SerialTimeSyncTask *pSerialTimeSyncTask);
boolean IsRecurring_in_SerialTimeSyncTask_override(void *pIMasterTask);

boolean BuildRequest_in_SerialTimeSyncTask(SerialTimeSyncTask *pSerialTimeSyncTask, APDURequest* request, uint8_t seq);
boolean BuildRequest_in_SerialTimeSyncTask_override(void *pIMasterTask, APDURequest* request, uint8_t seq);

int Priority_in_SerialTimeSyncTask(SerialTimeSyncTask *pSerialTimeSyncTask);
int Priority_in_SerialTimeSyncTask_override(void *pIMasterTask);

MasterTaskType_uint8_t GetTaskType_in_SerialTimeSyncTask(SerialTimeSyncTask *pSerialTimeSyncTask);
MasterTaskType_uint8_t GetTaskType_in_SerialTimeSyncTask_override(void *pIMasterTask);

boolean IsEnabled_in_SerialTimeSyncTask(SerialTimeSyncTask *pSerialTimeSyncTask);
boolean IsEnabled_in_SerialTimeSyncTask_override(void *pIMasterTask);

ResponseResult_in_IMasterTask_uint8_t ProcessResponse_in_SerialTimeSyncTask(SerialTimeSyncTask *pSerialTimeSyncTask,
    APDUResponseHeader* header, RSeq_for_Uint16_t* objects);
ResponseResult_in_IMasterTask_uint8_t ProcessResponse_in_SerialTimeSyncTask_override(void *pIMasterTask,
    APDUResponseHeader* header, RSeq_for_Uint16_t* objects);

void Initialize_in_SerialTimeSyncTask(SerialTimeSyncTask *pSerialTimeSyncTask);
void Initialize_in_SerialTimeSyncTask_override(void *pIMasterTask);

ResponseResult_in_IMasterTask_uint8_t OnResponseDelayMeas_in_SerialTimeSyncTask(SerialTimeSyncTask *pSerialTimeSyncTask,
    APDUResponseHeader* response, RSeq_for_Uint16_t* objects);

ResponseResult_in_IMasterTask_uint8_t OnResponseWriteTime_in_SerialTimeSyncTask(SerialTimeSyncTask *pSerialTimeSyncTask,
    APDUResponseHeader* header, RSeq_for_Uint16_t* objects);

char * Name_in_SerialTimeSyncTask(SerialTimeSyncTask *pSerialTimeSyncTask);
char * Name_in_SerialTimeSyncTask_override(void *pSerialTimeSyncTask);

////} // namespace opendnp3

#endif
