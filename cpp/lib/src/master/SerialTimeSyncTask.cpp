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
#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "SerialTimeSyncTask.h"

#include "APDUBuilders.h"
#include "APDUParser.h"
#include "Group50.h"
#include "TimeSyncHandler.h"

////#include <ser4cpp/serialization/LittleEndian.h>

////namespace opendnp3
////{

////SerialTimeSyncTask::SerialTimeSyncTask(const std::shared_ptr<TaskContext>& context,
////                                       IMasterApplication& app,
////                                       const Logger& logger)
void SerialTimeSyncTask_in_SerialTimeSyncTask(SerialTimeSyncTask *pSerialTimeSyncTask,
//                       const std::shared_ptr<TaskContext>& context,
    IMasterApplication* application)
{
////    : IMasterTask(context, app, TaskBehavior::ReactsToIINOnly(), logger, TaskConfig::Default()), delay(-1)
  IMasterTask_in_IMasterTask(&(pSerialTimeSyncTask->iIMasterTask),
//                TaskContext* context,
                             application,
                             ReactsToIINOnly_in_TaskBehavior_static(),
//                const Logger& logger,
                             Default_in_TaskConfig_static());
  pSerialTimeSyncTask->delay = -1;

  pSerialTimeSyncTask->iIMasterTask.pIsRecurring_in_IMasterTask = IsRecurring_in_SerialTimeSyncTask_override;
  pSerialTimeSyncTask->iIMasterTask.pBuildRequest_in_IMasterTask = BuildRequest_in_SerialTimeSyncTask_override;
  pSerialTimeSyncTask->iIMasterTask.pPriority_in_IMasterTask = Priority_in_SerialTimeSyncTask_override;
  pSerialTimeSyncTask->iIMasterTask.pGetTaskType_in_IMasterTask = GetTaskType_in_SerialTimeSyncTask_override;
  pSerialTimeSyncTask->iIMasterTask.pProcessResponse_in_IMasterTask = ProcessResponse_in_SerialTimeSyncTask_override;
  pSerialTimeSyncTask->iIMasterTask.pIsEnabled_in_IMasterTask = IsEnabled_in_SerialTimeSyncTask_override;
  pSerialTimeSyncTask->iIMasterTask.pInitialize_in_IMasterTask = Initialize_in_SerialTimeSyncTask_override;
  pSerialTimeSyncTask->iIMasterTask.pName_in_IMasterTask = Name_in_SerialTimeSyncTask_override;

  setParentPointer_in_IMasterTask(&(pSerialTimeSyncTask->iIMasterTask), pSerialTimeSyncTask);
}

void Initialize_in_SerialTimeSyncTask(SerialTimeSyncTask *pSerialTimeSyncTask)
{
  pSerialTimeSyncTask->delay = -1;
}

boolean BuildRequest_in_SerialTimeSyncTask(SerialTimeSyncTask *pSerialTimeSyncTask, APDURequest* request, uint8_t seq)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{BuildRequest_in_SerialTimeSyncTask1"<<'\n';
#endif
  if (pSerialTimeSyncTask->delay < 0)
  {
//UTCTimestamp Now_in_IUTCTimeSource(IUTCTimeSource* pIUTCTimeSource);
////        start = this->application->Now();
    pSerialTimeSyncTask->start = Now_in_IUTCTimeSource(&(pSerialTimeSyncTask->iIMasterTask.application->iIUTCTimeSource));////this->application->Now();
//void MeasureDelay_in_APDUBuilders_static(APDURequest* request, uint8_t seq);// = 0);
////        build::MeasureDelay(request, seq);
    MeasureDelay_in_APDUBuilders_static(request, seq);
  }
  else
  {
//UTCTimestamp Now_in_IUTCTimeSource(IUTCTimeSource* pIUTCTimeSource);
////        auto now = this->application->Now();
    UTCTimestamp now = Now_in_IUTCTimeSource(&(pSerialTimeSyncTask->iIMasterTask.application->iIUTCTimeSource));////this->application->Now();

    Group50Var1 timeGroup50;
    Group50Var1_in_Group50Var1(&timeGroup50);

////        time.time = DNPTime(now.msSinceEpoch + delay);
    DNPTime dDNPTime;
    DNPTime_in_DNPTimeOver2(&dDNPTime, now.msSinceEpoch);
    timeGroup50.timeDNPTime = dDNPTime;

////        request.SetFunction(FunctionCode::WRITE);
    SetFunction_in_APDUWrapper(&(request->aAPDUWrapper), FunctionCode_WRITE);

////        request.SetControl(AppControlField::Request(seq));
    SetControl_in_APDUWrapper(&(request->aAPDUWrapper), Request_in_AppControlField_static(seq));

////        auto writer = request.GetWriter();
    HeaderWriter writer = GetWriter_in_APDUWrapper(&(request->aAPDUWrapper));

////        writer.WriteSingleValue<ser4cpp::UInt8, Group50Var1>(QualifierCode::UINT8_CNT, time);
    boolean tmp = WriteSingleValue_for_UInt8_Group50Var1_in_HeaderWriter(&writer,
           QualifierCode_UINT8_CNT, &timeGroup50);
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}BuildRequest_in_SerialTimeSyncTask1_"<<'\n';
  decrement_stack_info();
#endif
    return tmp;
  }

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}BuildRequest_in_SerialTimeSyncTask2_"<<'\n';
  decrement_stack_info();
#endif
  return true;
}

////IMasterTask::ResponseResult SerialTimeSyncTask::ProcessResponse(const APDUResponseHeader& response,
////                                                                const ser4cpp::rseq_t& objects)
ResponseResult_in_IMasterTask_uint8_t ProcessResponse_in_SerialTimeSyncTask(SerialTimeSyncTask *pSerialTimeSyncTask,
    APDUResponseHeader* response, RSeq_for_Uint16_t* objects)
{
////    return (pSerialTimeSyncTask->delay < 0) ? OnResponseDelayMeas(response, objects) : OnResponseWriteTime(response, objects);
  return (pSerialTimeSyncTask->delay < 0) ?
         OnResponseDelayMeas_in_SerialTimeSyncTask(pSerialTimeSyncTask, response, objects)
         :OnResponseWriteTime_in_SerialTimeSyncTask(pSerialTimeSyncTask, response, objects);
}

////IMasterTask::ResponseResult SerialTimeSyncTask::OnResponseDelayMeas(const APDUResponseHeader& response,
////                                                                    const ser4cpp::rseq_t& objects)
ResponseResult_in_IMasterTask_uint8_t OnResponseDelayMeas_in_SerialTimeSyncTask(SerialTimeSyncTask *pSerialTimeSyncTask,
    APDUResponseHeader* response, RSeq_for_Uint16_t* objects)
{
////    if (ValidateSingleResponse(response))
  if (ValidateSingleResponse_in_IMasterTask(&(pSerialTimeSyncTask->iIMasterTask), response))
  {
    TimeSyncHandler handler;
    TimeSyncHandler_in_TimeSyncHandler(&handler);

//ParseResult_uint8_t Parse_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler *handler);
////        auto result = APDUParser::Parse(objects, handler, &logger);
    ParseResult_uint8_t result = Parse_in_APDUParser_static(objects, &(handler.iIAPDUHandler));
    if (result == ParseResult_OK)
    {
      uint16_t rtuTurnAroundTime;
//boolean GetTimeDelay_in_TimeSyncHandler(TimeSyncHandler *pTimeSyncHandler, uint16_t& time);
////            if (handler.GetTimeDelay(rtuTurnAroundTime))
      if (GetTimeDelay_in_TimeSyncHandler(&handler, &rtuTurnAroundTime))
      {
////                auto now = this->application->Now();
        UTCTimestamp now = Now_in_IUTCTimeSource(&(pSerialTimeSyncTask->iIMasterTask.application->iIUTCTimeSource));////this->application->Now();
////                auto sendReceiveTime = now.msSinceEpoch - start.msSinceEpoch;
        uint64_t  sendReceiveTime = now.msSinceEpoch - pSerialTimeSyncTask->start.msSinceEpoch;

        // The later shouldn't happen, but could cause a negative delay which would result in a weird time
        // setting
// ѕоследнее не должно произойти, но может вызвать отрицательную задержку, котора€ приведет к странному времени
        // параметр
        pSerialTimeSyncTask->delay = (sendReceiveTime >= rtuTurnAroundTime) ? (sendReceiveTime - rtuTurnAroundTime) / 2 : 0;

        return ResponseResult_in_IMasterTask_OK_REPEAT;
      }

      return ResponseResult_in_IMasterTask_ERROR_BAD_RESPONSE;
    }
    else
    {
      return ResponseResult_in_IMasterTask_ERROR_BAD_RESPONSE;
    }
  }
  else
  {
    return ResponseResult_in_IMasterTask_ERROR_BAD_RESPONSE;
  }
}

////IMasterTask::ResponseResult SerialTimeSyncTask::OnResponseWriteTime(const APDUResponseHeader& header,
////                                                                    const ser4cpp::rseq_t& objects)
ResponseResult_in_IMasterTask_uint8_t OnResponseWriteTime_in_SerialTimeSyncTask(SerialTimeSyncTask *pSerialTimeSyncTask,
    APDUResponseHeader* header, RSeq_for_Uint16_t* objects)
{
////    return ValidateNullResponse(header, objects) ? ResponseResult::OK_FINAL : ResponseResult::ERROR_BAD_RESPONSE;
  return ValidateNullResponse_in_IMasterTask(&(pSerialTimeSyncTask->iIMasterTask), header, objects) ?
         ResponseResult_in_IMasterTask_OK_FINAL :  ResponseResult_in_IMasterTask_ERROR_BAD_RESPONSE;
}

////} // namespace opendnp3
int Priority_in_SerialTimeSyncTask(SerialTimeSyncTask *pSerialTimeSyncTask)
{
  UNUSED(pSerialTimeSyncTask);
  return priority_TIME_SYNC;
}

boolean IsRecurring_in_SerialTimeSyncTask(SerialTimeSyncTask *pSerialTimeSyncTask)
{
  UNUSED(pSerialTimeSyncTask);
  return true;
}

MasterTaskType_uint8_t GetTaskType_in_SerialTimeSyncTask(SerialTimeSyncTask *pSerialTimeSyncTask)
{
  UNUSED(pSerialTimeSyncTask);
  return MasterTaskType_NON_LAN_TIME_SYNC;
}

boolean IsEnabled_in_SerialTimeSyncTask(SerialTimeSyncTask *pSerialTimeSyncTask)
{
  UNUSED(pSerialTimeSyncTask);
  return true;
}

boolean IsRecurring_in_SerialTimeSyncTask_override(void *pIMasterTask)
{
  SerialTimeSyncTask *parent = (SerialTimeSyncTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return IsRecurring_in_SerialTimeSyncTask(parent);
}

boolean BuildRequest_in_SerialTimeSyncTask_override(void *pIMasterTask, APDURequest* request, uint8_t seq)
{
  SerialTimeSyncTask *parent = (SerialTimeSyncTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return BuildRequest_in_SerialTimeSyncTask(parent, request, seq);
}

int Priority_in_SerialTimeSyncTask_override(void *pIMasterTask)
{
  SerialTimeSyncTask *parent = (SerialTimeSyncTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return Priority_in_SerialTimeSyncTask(parent);
}

MasterTaskType_uint8_t GetTaskType_in_SerialTimeSyncTask_override(void *pIMasterTask)
{
  SerialTimeSyncTask *parent = (SerialTimeSyncTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return GetTaskType_in_SerialTimeSyncTask(parent);
}

ResponseResult_in_IMasterTask_uint8_t ProcessResponse_in_SerialTimeSyncTask_override(void *pIMasterTask,
    SerialTimeSyncTask* header, RSeq_for_Uint16_t* objects)
{
  SerialTimeSyncTask *parent = (SerialTimeSyncTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return ProcessResponse_in_SerialTimeSyncTask_override(parent, header, objects);
}

boolean IsEnabled_in_SerialTimeSyncTask_override(void *pIMasterTask)
{
  SerialTimeSyncTask *parent = (SerialTimeSyncTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return IsEnabled_in_SerialTimeSyncTask(parent);
}

void Initialize_in_SerialTimeSyncTask_override(void *pIMasterTask)
{
  SerialTimeSyncTask *parent = (SerialTimeSyncTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  Initialize_in_SerialTimeSyncTask(parent);
}

ResponseResult_in_IMasterTask_uint8_t ProcessResponse_in_SerialTimeSyncTask_override(void *pIMasterTask,
    APDUResponseHeader* header, RSeq_for_Uint16_t* objects)
{
  SerialTimeSyncTask *parent = (SerialTimeSyncTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return ProcessResponse_in_SerialTimeSyncTask_override(parent, header, objects);
}

char * Name_in_SerialTimeSyncTask(SerialTimeSyncTask *pSerialTimeSyncTask)
{
   UNUSED(pSerialTimeSyncTask);
   return "SerialTimeSyncTask";
}
char * Name_in_SerialTimeSyncTask_override(void *pIMasterTask)
{
  SerialTimeSyncTask *parent = (SerialTimeSyncTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return Name_in_SerialTimeSyncTask(parent);
}
