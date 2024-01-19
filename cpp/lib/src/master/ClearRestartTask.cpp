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
#include "ClearRestartTask.h"

#include "APDUBuilders.h"
///#include "logging/LogMacros.h"
//#include "MasterTasks.h"

///#include "opendnp3/logging/LogLevels.h"

////namespace opendnp3
////{

////ClearRestartTask::ClearRestartTask(const std::shared_ptr<TaskContext>& context,
////                                   IMasterApplication& application,
////                                   const Logger& logger)
void ClearRestartTask_in_ClearRestartTask(ClearRestartTask *pClearRestartTask,
//                       const std::shared_ptr<TaskContext>& context,
    IMasterApplication* application)
{
//TaskBehavior ReactsToIINOnly_in_TaskBehavior_static(void);
////    : IMasterTask(context, application, TaskBehavior::ReactsToIINOnly(), logger, TaskConfig::Default())
  IMasterTask_in_IMasterTask(&(pClearRestartTask->iIMasterTask),
//                TaskContext* context,
                             application,
                             ReactsToIINOnly_in_TaskBehavior_static(),
//                const Logger& logger,
                             Default_in_TaskConfig_static());

  pClearRestartTask->iIMasterTask.pIsRecurring_in_IMasterTask = IsRecurring_in_ClearRestartTask_override;
  pClearRestartTask->iIMasterTask.pBuildRequest_in_IMasterTask = BuildRequest_in_ClearRestartTask_override;
  pClearRestartTask->iIMasterTask.pPriority_in_IMasterTask = Priority_in_ClearRestartTask_override;
  pClearRestartTask->iIMasterTask.pGetTaskType_in_IMasterTask = GetTaskType_in_ClearRestartTask_override;
  pClearRestartTask->iIMasterTask.pProcessResponse_in_IMasterTask = ProcessResponse_in_ClearRestartTask_override;
  pClearRestartTask->iIMasterTask.pIsEnabled_in_IMasterTask = IsEnabled_in_ClearRestartTask_override;

  setParentPointer_in_IMasterTask(&(pClearRestartTask->iIMasterTask), pClearRestartTask);
}

////bool ClearRestartTask::BuildRequest(APDURequest& request, uint8_t seq)
boolean BuildRequest_in_ClearRestartTask(ClearRestartTask *pClearRestartTask, APDURequest* request, uint8_t seq)
{
 UNUSED(pClearRestartTask);
//void ClearRestartIIN_in_APDUBuilders_static(APDURequest* request, uint8_t seq);// = 0);
////    build::ClearRestartIIN(request, seq);
  ClearRestartIIN_in_APDUBuilders_static(request, seq);// = 0);
  return true;
}

////IMasterTask::ResponseResult ClearRestartTask::ProcessResponse(const APDUResponseHeader& response,
///                                                              const ser4cpp::rseq_t& /*objects*/)
ResponseResult_in_IMasterTask_uint8_t ProcessResponse_in_ClearRestartTask(ClearRestartTask *pClearRestartTask,
    APDUResponseHeader* response, RSeq_for_Uint16_t* objects)
{
  UNUSED(objects);
//boolean ValidateSingleResponse_in_IMasterTask(IMasterTask *pIMasterTask, APDUResponseHeader* header);
  // we only care that the response to this has FIR/FIN
// нас волнует только то, чтобы ответ на это имел FIR/FIN
////    if (ValidateSingleResponse(response))
  if (ValidateSingleResponse_in_IMasterTask(&(pClearRestartTask->iIMasterTask), response))
  {
//boolean IsSet_in_IINField(IINField *, IINBit_uint8_t bit);
////        if (response.IIN.IsSet(IINBit::DEVICE_RESTART))
    if (IsSet_in_IINField(&(response->IIN), IINBit_DEVICE_RESTART))
    {
      // we tried to clear the restart, but the device responded with the restart still set
// мы попытались отменить перезагрузку, но устройство ответило, что перезагрузка все еще установлена
////            SIMPLE_LOG_BLOCK(logger, flags::ERR,
////                             "Clear restart task failed to clear restart bit, permanently disabling task");
#ifdef  LOG_INFO
      increment_stack_info();
      std::cout<<getString_stack_info();
      std::cout<<"*SIMPLE_LOG_BLOCK(logger, flags::ERR,'Clear restart task failed to clear restart bit, permanently disabling task')"<<'\n';
      decrement_stack_info();
#endif
      return ResponseResult_in_IMasterTask_ERROR_BAD_RESPONSE;
    }

    return ResponseResult_in_IMasterTask_OK_FINAL;
  }
  else
  {
    return ResponseResult_in_IMasterTask_ERROR_BAD_RESPONSE;
  }
}

int Priority_in_ClearRestartTask(ClearRestartTask *pClearRestartTask)
{
  UNUSED(pClearRestartTask);
  return priority_CLEAR_RESTART;
}

boolean IsRecurring_in_ClearRestartTask(ClearRestartTask *pClearRestartTask)
{
  UNUSED(pClearRestartTask);
  return true;
}

MasterTaskType_uint8_t GetTaskType_in_ClearRestartTask(ClearRestartTask *pClearRestartTask)
{
  UNUSED(pClearRestartTask);
  return MasterTaskType_CLEAR_RESTART;
}

boolean IsEnabled_in_ClearRestartTask(ClearRestartTask *pClearRestartTask)
{
  UNUSED(pClearRestartTask);
  return true;
}

boolean IsRecurring_in_ClearRestartTask_override(void *pIMasterTask)
{
  ClearRestartTask *parent = (ClearRestartTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return IsRecurring_in_ClearRestartTask(parent);
}

boolean BuildRequest_in_ClearRestartTask_override(void *pIMasterTask, APDURequest* request, uint8_t seq)
{
  ClearRestartTask *parent = (ClearRestartTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return BuildRequest_in_ClearRestartTask(parent, request, seq);
}

int Priority_in_ClearRestartTask_override(void *pIMasterTask)
{
  ClearRestartTask *parent = (ClearRestartTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return Priority_in_ClearRestartTask(parent);
}

MasterTaskType_uint8_t GetTaskType_in_ClearRestartTask_override(void *pIMasterTask)
{
  ClearRestartTask *parent = (ClearRestartTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return GetTaskType_in_ClearRestartTask(parent);
}

ResponseResult_in_IMasterTask_uint8_t ProcessResponse_in_ClearRestartTask_override(void *pIMasterTask,
    ClearRestartTask* header, RSeq_for_Uint16_t* objects)
{
  ClearRestartTask *parent = (ClearRestartTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return ProcessResponse_in_ClearRestartTask_override(parent, header, objects);
}

boolean IsEnabled_in_ClearRestartTask_override(void *pIMasterTask)
{
  ClearRestartTask *parent = (ClearRestartTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return IsEnabled_in_ClearRestartTask(parent);
}

ResponseResult_in_IMasterTask_uint8_t ProcessResponse_in_ClearRestartTask_override(void *pIMasterTask,
    APDUResponseHeader* header, RSeq_for_Uint16_t* objects)
{
  ClearRestartTask *parent = (ClearRestartTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return ProcessResponse_in_ClearRestartTask_override(parent, header, objects);
}


////} // namespace opendnp3
