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
#include <QApplication>
#include "header.h"
#include "CommandTask.h"

#include "APDUParser.h"
////#include "logging/LogMacros.h"
#include "CommandSetOps.h"
#include "ICommandHeader.h"

////#include "opendnp3/logging/LogLevels.h"

////#include <utility>

////namespace opendnp3
////{
void CommandTask_in_CommandTask(CommandTask *pCommandTask,
//                         const std::shared_ptr<TaskContext>& context,
                                CommandSet* commands,
                                IndexQualifierMode_uint8_t mode,
                                IMasterApplication* app,
                                CommandResultCallbackT callback,
                                Timestamp* startExpiration,
                                TaskConfig* config)
////                         const Logger& logger)
{
//TaskBehavior SingleExecutionNoRetry_in_TaskBehavior_static(void)
////    : IMasterTask(context, app, TaskBehavior::SingleExecutionNoRetry(startExpiration), logger, config),
  IMasterTask_in_IMasterTask(&(pCommandTask->iIMasterTask),
//                TaskContext* context,
                             app,
                             SingleExecutionNoRetry_in_TaskBehavior_staticOver2(startExpiration),
//                const Logger& logger,
                             *config);

  pCommandTask->statusResult = CommandStatus_UNDEFINED;
  pCommandTask->commandCallback = callback;
  pCommandTask->commands = *commands;
  pCommandTask->mode = mode;

  pCommandTask->iIMasterTask.pIsRecurring_in_IMasterTask = IsRecurring_in_CommandTask_override;
  pCommandTask->iIMasterTask.pBuildRequest_in_IMasterTask = BuildRequest_in_CommandTask_override;
  pCommandTask->iIMasterTask.pPriority_in_IMasterTask = Priority_in_CommandTask_override;
  pCommandTask->iIMasterTask.pGetTaskType_in_IMasterTask = GetTaskType_in_CommandTask_override;
  pCommandTask->iIMasterTask.pProcessResponse_in_IMasterTask = ProcessResponse_in_CommandTask_override;
  pCommandTask->iIMasterTask.pIsEnabled_in_IMasterTask = IsEnabled_in_CommandTask_override;
  pCommandTask->iIMasterTask.pBlocksLowerPriority_in_IMasterTask = BlocksLowerPriority_in_CommandTask_override;
  pCommandTask->iIMasterTask.pOnTaskComplete_in_IMasterTask = OnTaskComplete_in_CommandTask_override;
  pCommandTask->iIMasterTask.pInitialize_in_IMasterTask = Initialize_in_CommandTask_override;

  setParentPointer_in_IMasterTask(&(pCommandTask->iIMasterTask), pCommandTask);
}

static CommandTask cCommandTask;

////std::shared_ptr<IMasterTask> CommandTask::CreateDirectOperate(const std::shared_ptr<TaskContext>& context,
////                                                              CommandSet&& set,
////                                                              IndexQualifierMode mode,
////                                                              IMasterApplication& app,
////                                                              const CommandResultCallbackT& callback,
////                                                              const Timestamp& startExpiration,
////                                                              const TaskConfig& config,
////                                                              Logger logger)
IMasterTask* CreateDirectOperate_in_CommandTask_static(//const std::shared_ptr<TaskContext>& context,
  CommandSet* set,
  IndexQualifierMode_uint8_t mode,
  IMasterApplication* app,
  CommandResultCallbackT callback,
  Timestamp* startExpiration,
  TaskConfig* config)
{
//void CommandTask_in_CommandTask(CommandTask *pCommandTask,
//                         const std::shared_ptr<TaskContext>& context,
//                         CommandSet* commands,
//                         IndexQualifierMode_uint8_t mode,
//                         IMasterApplication* app,
//                         CommandResultCallbackT callback,
//                         Timestamp* startExpiration,
//                         TaskConfig* config)
////    auto task
////        = std::make_shared<CommandTask>(context, std::move(set), mode, app, callback, startExpiration, config, logger);
  CommandTask_in_CommandTask(&cCommandTask,
//                         const std::shared_ptr<TaskContext>& context,
                             set,
                             mode,
                             app,
                             callback,
                             startExpiration,
                             config);

//  void LoadDirectOperate_in_CommandTask(CommandTask *pCommandTask);
////    task->LoadDirectOperate();
  LoadDirectOperate_in_CommandTask(&cCommandTask);
///    return task;
  return &cCommandTask.iIMasterTask;
}

////std::shared_ptr<IMasterTask> CommandTask::CreateSelectAndOperate(const std::shared_ptr<TaskContext>& context,
////                                                                 CommandSet&& set,
////                                                                 IndexQualifierMode mode,
////                                                                 IMasterApplication& app,
////                                                                 const CommandResultCallbackT& callback,
////                                                                 const Timestamp& startExpiration,
////                                                                 const TaskConfig& config,
////                                                                 Logger logger)
IMasterTask* CreateSelectAndOperate_in_CommandTask_static(//const std::shared_ptr<TaskContext>& context,
  CommandSet* set,
  IndexQualifierMode_uint8_t mode,
  IMasterApplication* app,
  CommandResultCallbackT callback,
  Timestamp* startExpiration,
  TaskConfig* config)
{
////    auto task
////        = std::make_shared<CommandTask>(context, std::move(set), mode, app, callback, startExpiration, config, logger);
  CommandTask_in_CommandTask(&cCommandTask,
//                         const std::shared_ptr<TaskContext>& context,
                             set,
                             mode,
                             app,
                             callback,
                             startExpiration,
                             config);

////    task->LoadSelectAndOperate();
  LoadSelectAndOperate_in_CommandTask(&cCommandTask);

////    return task;
  return &cCommandTask.iIMasterTask;
}

void LoadSelectAndOperate_in_CommandTask(CommandTask *pCommandTask)
{
  pCommandTask->functionCodes.clear();
  pCommandTask->functionCodes.push_back(FunctionCode_SELECT);
  pCommandTask->functionCodes.push_back(FunctionCode_OPERATE);
}

void LoadDirectOperate_in_CommandTask(CommandTask *pCommandTask)
{
  pCommandTask->functionCodes.clear();
  pCommandTask->functionCodes.push_back(FunctionCode_DIRECT_OPERATE);
}

////bool CommandTask::BuildRequest(APDURequest& request, uint8_t seq)
boolean BuildRequest_in_CommandTask(CommandTask *pCommandTask, APDURequest* request, uint8_t seq)
{
  if (!pCommandTask->functionCodes.empty())
  {
////        request.SetFunction(functionCodes.front());
    SetFunction_in_APDUWrapper(&(request->aAPDUWrapper), pCommandTask->functionCodes.front());

    pCommandTask->functionCodes.pop_front();

////        request.SetControl(AppControlField::Request(seq));
    SetControl_in_APDUWrapper(&(request->aAPDUWrapper), Request_in_AppControlField_static(seq));

////        auto writer = request.GetWriter();
    HeaderWriter writer = GetWriter_in_APDUWrapper(&(request->aAPDUWrapper));

////        return CommandSetOps::Write(commands, writer, this->mode);
    return Write_in_CommandSetOps_static(&(pCommandTask->commands), &writer, pCommandTask->mode);
  }

  return false;
}

////IMasterTask::ResponseResult CommandTask::ProcessResponse(const APDUResponseHeader& header,
////                                                         const ser4cpp::rseq_t& objects)
ResponseResult_in_IMasterTask_uint8_t ProcessResponse_in_CommandTask(CommandTask *pCommandTask,
    APDUResponseHeader* header, RSeq_for_Uint16_t* objects)
{
//   ResponseResult ProcessResponse_in_CommandTaskOver2(CommandTask *pCommandTask, RSeq_for_Uint16_t* objects);
////    return ValidateSingleResponse(header) ? ProcessResponse(objects) : ResponseResult::ERROR_BAD_RESPONSE;
  if(ValidateSingleResponse_in_IMasterTask(&(pCommandTask->iIMasterTask), header))
         return ProcessResponse_in_CommandTaskOver2(pCommandTask, objects);
  return ResponseResult_in_IMasterTask_ERROR_BAD_RESPONSE;
}

////void CommandTask::OnTaskComplete(TaskCompletion result, Timestamp /*now*/)
void OnTaskComplete_in_CommandTask(CommandTask *pCommandTask, TaskCompletion_uint8_t result, Timestamp now)
{
  UNUSED(now);
//  void InvokeCallback_in_CommandSetOps_static(CommandSet* set, TaskCompletion_uint8_t result, CommandResultCallbackT callback);
////    CommandSetOps::InvokeCallback(commands, result, this->commandCallback);
  InvokeCallback_in_CommandSetOps_static(&(pCommandTask->commands), result, pCommandTask->commandCallback);
}

////void CommandTask::Initialize()
void Initialize_in_CommandTask(CommandTask *pCommandTask)
{
  pCommandTask->statusResult = CommandStatus_UNDEFINED;
}

////IMasterTask::ResponseResult CommandTask::ProcessResponse(const ser4cpp::rseq_t& objects)
ResponseResult_in_IMasterTask_uint8_t ProcessResponse_in_CommandTaskOver2(CommandTask *pCommandTask, RSeq_for_Uint16_t* objects)
{
  if (pCommandTask->functionCodes.empty())
  {
//OperateResult_in_CommandSetOps_uint8_t ProcessOperateResponse_in_CommandSetOps_static(CommandSet* set, RSeq_for_Uint16_t* headers);//, Logger* logger);
////    auto result = CommandSetOps::ProcessOperateResponse(commands, objects, &logger);
    OperateResult_in_CommandSetOps_uint8_t result =
      ProcessOperateResponse_in_CommandSetOps_static(&(pCommandTask->commands), objects);//, Logger* logger);
    return (result == OperateResult_in_CommandSetOps_FAIL_PARSE) ? ResponseResult_in_IMasterTask_ERROR_BAD_RESPONSE
           : ResponseResult_in_IMasterTask_OK_FINAL;
  }

//SelectResult_in_CommandSetOps_uint8_t ProcessSelectResponse_in_CommandSetOps_static(CommandSet* set, RSeq_for_Uint16_t* headers);//, Logger* logger);
////  auto result = CommandSetOps::ProcessSelectResponse(commands, objects, &logger);
  SelectResult_in_CommandSetOps_uint8_t result =
    ProcessSelectResponse_in_CommandSetOps_static(&(pCommandTask->commands), objects);//, Logger* logger);

  switch (result)
  {
  case (SelectResult_in_CommandSetOps_OK):
    return ResponseResult_in_IMasterTask_OK_REPEAT; // proceed to OPERATE
  case (SelectResult_in_CommandSetOps_FAIL_SELECT):
    return ResponseResult_in_IMasterTask_OK_FINAL; // end the task, let the user examine each command point
//завершить задачу, дать пользователю возможность изучить каждую командную точку
  default:
    return ResponseResult_in_IMasterTask_ERROR_BAD_RESPONSE;
  }
}

////} // namespace opendnp3
boolean IsEnabled_in_CommandTask(CommandTask *pCommandTask)
{
  UNUSED(pCommandTask);
  return true;
}

int Priority_in_CommandTask(CommandTask *pCommandTask)
{
  UNUSED(pCommandTask);
  return priority_COMMAND;
}

boolean IsRecurring_in_CommandTask(CommandTask *pCommandTask)
{
  UNUSED(pCommandTask);
  return false;
}

boolean BlocksLowerPriority_in_CommandTask(CommandTask *pCommandTask)
{
  UNUSED(pCommandTask);
  return false;
}

MasterTaskType_uint8_t GetTaskType_in_CommandTask(CommandTask *pCommandTask)
{
  UNUSED(pCommandTask);
  return MasterTaskType_USER_TASK;
}

boolean BlocksLowerPriority_in_CommandTask_override(void *pIMasterTask)
{
  CommandTask *parent = (CommandTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return BlocksLowerPriority_in_CommandTask(parent);
}

boolean IsRecurring_in_CommandTask_override(void *pIMasterTask)
{
  CommandTask *parent = (CommandTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return IsRecurring_in_CommandTask(parent);
}

boolean BuildRequest_in_CommandTask_override(void *pIMasterTask, APDURequest* request, uint8_t seq)
{
  CommandTask *parent = (CommandTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return BuildRequest_in_CommandTask(parent, request, seq);
}

int Priority_in_CommandTask_override(void *pIMasterTask)
{
  CommandTask *parent = (CommandTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return Priority_in_CommandTask(parent);
}

MasterTaskType_uint8_t GetTaskType_in_CommandTask_override(void *pIMasterTask)
{
  CommandTask *parent = (CommandTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return GetTaskType_in_CommandTask(parent);
}

ResponseResult_in_IMasterTask_uint8_t ProcessResponse_in_CommandTask_override(void *pIMasterTask,
    APDUResponseHeader* header, RSeq_for_Uint16_t* objects)
{
  CommandTask *parent = (CommandTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return ProcessResponse_in_CommandTask_override(parent, header, objects);
}

boolean IsEnabled_in_CommandTask_override(void *pIMasterTask)
{
  CommandTask *parent = (CommandTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return IsEnabled_in_CommandTask(parent);
}

void OnTaskComplete_in_CommandTask_override(void *pIMasterTask, TaskCompletion_uint8_t result, Timestamp now)
{
  CommandTask *parent = (CommandTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return OnTaskComplete_in_CommandTask(parent, result, now);
}

void Initialize_in_CommandTask_override(void *pIMasterTask)
{
  CommandTask *parent = (CommandTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  Initialize_in_CommandTask(parent);
}
