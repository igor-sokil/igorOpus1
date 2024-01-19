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
#include "header.h"
#include "LANTimeSyncTask.h"

#include "APDUBuilders.h"
#include "Group50.h"

////#include <ser4cpp/serialization/LittleEndian.h>

////namespace opendnp3
////{

////LANTimeSyncTask::LANTimeSyncTask(const std::shared_ptr<TaskContext>& context,
////                                 IMasterApplication& app,
////                                 const Logger& logger)
////    : IMasterTask(context, app, TaskBehavior::ReactsToIINOnly(), logger, TaskConfig::Default())
void LANTimeSyncTask_in_LANTimeSyncTask(LANTimeSyncTask *pLANTimeSyncTask,
//                       const std::shared_ptr<TaskContext>& context,
                                        IMasterApplication* application)
{
  IMasterTask_in_IMasterTask(&(pLANTimeSyncTask->iIMasterTask),
//                TaskContext* context,
                             application,
                             ReactsToIINOnly_in_TaskBehavior_static(),
//                const Logger& logger,
                             Default_in_TaskConfig_static());

  pLANTimeSyncTask->state = State_in_LANTimeSyncTask_RECORD_CURRENT_TIME;

  pLANTimeSyncTask->iIMasterTask.pIsRecurring_in_IMasterTask = IsRecurring_in_LANTimeSyncTask_override;
  pLANTimeSyncTask->iIMasterTask.pBuildRequest_in_IMasterTask = BuildRequest_in_LANTimeSyncTask_override;
  pLANTimeSyncTask->iIMasterTask.pPriority_in_IMasterTask = Priority_in_LANTimeSyncTask_override;
  pLANTimeSyncTask->iIMasterTask.pGetTaskType_in_IMasterTask = GetTaskType_in_LANTimeSyncTask_override;
  pLANTimeSyncTask->iIMasterTask.pProcessResponse_in_IMasterTask = ProcessResponse_in_LANTimeSyncTask_override;
  pLANTimeSyncTask->iIMasterTask.pIsEnabled_in_IMasterTask = IsEnabled_in_LANTimeSyncTask_override;
  pLANTimeSyncTask->iIMasterTask.pInitialize_in_IMasterTask = Initialize_in_LANTimeSyncTask_override;

  setParentPointer_in_IMasterTask(&(pLANTimeSyncTask->iIMasterTask), pLANTimeSyncTask);
}

void Initialize_in_LANTimeSyncTask(LANTimeSyncTask *pLANTimeSyncTask)
{
  pLANTimeSyncTask->state = State_in_LANTimeSyncTask_RECORD_CURRENT_TIME;
}

////bool LANTimeSyncTask::BuildRequest(APDURequest& request, uint8_t seq)
boolean BuildRequest_in_LANTimeSyncTask(LANTimeSyncTask *pLANTimeSyncTask, APDURequest* request, uint8_t seq)
{
  if (pLANTimeSyncTask->state == State_in_LANTimeSyncTask_RECORD_CURRENT_TIME)
  {
//UTCTimestamp Now_in_IUTCTimeSource(IUTCTimeSource* pIUTCTimeSource);
    pLANTimeSyncTask->start = Now_in_IUTCTimeSource(&(pLANTimeSyncTask->iIMasterTask.application->iIUTCTimeSource));////this->application->Now();
//void RecordCurrentTime_in_APDUBuilders_static(APDURequest* request, uint8_t seq);// = 0);
////        build::RecordCurrentTime(request, seq);
    RecordCurrentTime_in_APDUBuilders_static(request, seq);// = 0);
    return true;
  }

  Group50Var3 timeGroup50;
  Group50Var3_in_Group50Var3(&timeGroup50);
//void DNPTime_in_DNPTimeOver2(DNPTime *pDNPTime, uint64_t value);
////    time.time = DNPTime(this->start.msSinceEpoch);
  DNPTime dDNPTime;
  DNPTime_in_DNPTimeOver2(&dDNPTime, pLANTimeSyncTask->start.msSinceEpoch);
  timeGroup50.timeDNPTime = dDNPTime;

////    request.SetFunction(FunctionCode::WRITE);
  SetFunction_in_APDUWrapper(&(request->aAPDUWrapper), FunctionCode_WRITE);

//AppControlField Request_in_AppControlField_static(uint8_t seq);
////    request.SetControl(AppControlField::Request(seq));
  SetControl_in_APDUWrapper(&(request->aAPDUWrapper), Request_in_AppControlField_static(seq));

////    auto writer = request.GetWriter();
  HeaderWriter writer = GetWriter_in_APDUWrapper(&(request->aAPDUWrapper));

//boolean WriteSingleValue_for_UInt8_Group50Var3_in_HeaderWriter(HeaderWriter *pHeaderWriter,
//    QualifierCode_uint8_t qc, Group50Var3*);
////    return writer.WriteSingleValue<ser4cpp::UInt8, Group50Var3>(QualifierCode::UINT8_CNT, time);
  return WriteSingleValue_for_UInt8_Group50Var3_in_HeaderWriter(&writer,
         QualifierCode_UINT8_CNT, &timeGroup50);
}

////IMasterTask::ResponseResult LANTimeSyncTask::ProcessResponse(const APDUResponseHeader& response,
////                                                             const ser4cpp::rseq_t& objects)
ResponseResult_in_IMasterTask_uint8_t ProcessResponse_in_LANTimeSyncTask(LANTimeSyncTask *pLANTimeSyncTask,
    APDUResponseHeader* response, RSeq_for_Uint16_t* objects)
{
//ResponseResult_in_IMasterTask_uint8_t OnResponseWriteTime_in_LANTimeSyncTask(LANTimeSyncTask *pLANTimeSyncTask, APDUResponseHeader* header, RSeq_for_Uint16_t* objects);
//ResponseResult_in_IMasterTask_uint8_t OnResponseRecordCurrentTime_in_LANTimeSyncTask(LANTimeSyncTask *pLANTimeSyncTask,
//                                         APDUResponseHeader* response, RSeq_for_Uint16_t* objects);
  return (pLANTimeSyncTask->state == State_in_LANTimeSyncTask_RECORD_CURRENT_TIME) ?
////                                                 OnResponseRecordCurrentTime(response, objects)
////                                                 : OnResponseWriteTime(response, objects);
         OnResponseRecordCurrentTime_in_LANTimeSyncTask(pLANTimeSyncTask, response, objects)
         :OnResponseWriteTime_in_LANTimeSyncTask(pLANTimeSyncTask, response, objects);
}

////IMasterTask::ResponseResult LANTimeSyncTask::OnResponseRecordCurrentTime(const APDUResponseHeader& response,
////                                                                         const ser4cpp::rseq_t& objects)
ResponseResult_in_IMasterTask_uint8_t OnResponseRecordCurrentTime_in_LANTimeSyncTask(LANTimeSyncTask *pLANTimeSyncTask,
    APDUResponseHeader* response, RSeq_for_Uint16_t* objects)
{
////    if (!ValidateNullResponse(response, objects))
////        return ResponseResult::ERROR_BAD_RESPONSE;
  if (!ValidateNullResponse_in_IMasterTask(&(pLANTimeSyncTask->iIMasterTask), response, objects))
    return ResponseResult_in_IMasterTask_ERROR_BAD_RESPONSE;

  pLANTimeSyncTask->state = State_in_LANTimeSyncTask_WRITE_TIME;

  return ResponseResult_in_IMasterTask_OK_REPEAT;
}

////IMasterTask::ResponseResult LANTimeSyncTask::OnResponseWriteTime(const APDUResponseHeader& header,
////                                                                 const ser4cpp::rseq_t& objects)
ResponseResult_in_IMasterTask_uint8_t OnResponseWriteTime_in_LANTimeSyncTask(LANTimeSyncTask *pLANTimeSyncTask, APDUResponseHeader* header, RSeq_for_Uint16_t* objects)
{
////    return ValidateNullResponse(header, objects) ? ResponseResult::OK_FINAL : ResponseResult::ERROR_BAD_RESPONSE;
  return ValidateNullResponse_in_IMasterTask(&(pLANTimeSyncTask->iIMasterTask), header, objects) ?
         ResponseResult_in_IMasterTask_OK_FINAL : ResponseResult_in_IMasterTask_ERROR_BAD_RESPONSE;
}

////} // namespace opendnp3
int Priority_in_LANTimeSyncTask(LANTimeSyncTask *pLANTimeSyncTask)
{
  UNUSED(pLANTimeSyncTask);
  return priority_TIME_SYNC;
}

boolean IsRecurring_in_LANTimeSyncTask(LANTimeSyncTask *pLANTimeSyncTask)
{
  UNUSED(pLANTimeSyncTask);
  return true;
}

MasterTaskType_uint8_t GetTaskType_in_LANTimeSyncTask(LANTimeSyncTask *pLANTimeSyncTask)
{
  UNUSED(pLANTimeSyncTask);
  return MasterTaskType_LAN_TIME_SYNC;
}

boolean IsEnabled_in_LANTimeSyncTask(LANTimeSyncTask *pLANTimeSyncTask)
{
  UNUSED(pLANTimeSyncTask);
  return true;
}

boolean IsRecurring_in_LANTimeSyncTask_override(void *pIMasterTask)
{
  LANTimeSyncTask *parent = (LANTimeSyncTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return IsRecurring_in_LANTimeSyncTask(parent);
}

boolean BuildRequest_in_LANTimeSyncTask_override(void *pIMasterTask, APDURequest* request, uint8_t seq)
{
  LANTimeSyncTask *parent = (LANTimeSyncTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return BuildRequest_in_LANTimeSyncTask(parent, request, seq);
}

int Priority_in_LANTimeSyncTask_override(void *pIMasterTask)
{
  LANTimeSyncTask *parent = (LANTimeSyncTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return Priority_in_LANTimeSyncTask(parent);
}

MasterTaskType_uint8_t GetTaskType_in_LANTimeSyncTask_override(void *pIMasterTask)
{
  LANTimeSyncTask *parent = (LANTimeSyncTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return GetTaskType_in_LANTimeSyncTask(parent);
}

ResponseResult_in_IMasterTask_uint8_t ProcessResponse_in_LANTimeSyncTask_override(void *pIMasterTask,
    LANTimeSyncTask* header, RSeq_for_Uint16_t* objects)
{
  LANTimeSyncTask *parent = (LANTimeSyncTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return ProcessResponse_in_LANTimeSyncTask_override(parent, header, objects);
}

boolean IsEnabled_in_LANTimeSyncTask_override(void *pIMasterTask)
{
  LANTimeSyncTask *parent = (LANTimeSyncTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return IsEnabled_in_LANTimeSyncTask(parent);
}

ResponseResult_in_IMasterTask_uint8_t ProcessResponse_in_LANTimeSyncTask_override(void *pIMasterTask,
    APDUResponseHeader* header, RSeq_for_Uint16_t* objects)
{
  LANTimeSyncTask *parent = (LANTimeSyncTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return ProcessResponse_in_LANTimeSyncTask_override(parent, header, objects);
}

void Initialize_in_LANTimeSyncTask_override(void *pIMasterTask)
{
  LANTimeSyncTask *parent = (LANTimeSyncTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  Initialize_in_LANTimeSyncTask(parent);
}
