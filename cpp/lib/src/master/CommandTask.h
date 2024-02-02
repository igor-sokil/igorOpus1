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
#ifndef OPENDNP3_COMMANDTASK_H
#define OPENDNP3_COMMANDTASK_H

#include "IMasterTask.h"
#include "TaskPriority.h"

#include "FunctionCode.h"
#include "IndexQualifierMode.h"
////#include "opendnp3/logging/Logger.h"
#include "CommandSet.h"
#include "ICommandProcessor.h"
#include "ITaskCallback.h"

////#include <assert.h>

#include <deque>
////#include <memory>

////namespace opendnp3
////{

// Base class with machinery for performing command operations
// Базовый класс с механизмом выполнения командных операций
////class CommandTask : public IMasterTask
typedef struct
{
  IMasterTask iIMasterTask;

////public:
////    CommandTask(const std::shared_ptr<TaskContext>& context,
////                CommandSet&& commands,
////                IndexQualifierMode mode,
////                IMasterApplication& app,
////                CommandResultCallbackT callback,
////                const Timestamp& startExpiration,
////                const TaskConfig& config,
////                const Logger& logger);

////    static std::shared_ptr<IMasterTask> CreateDirectOperate(const std::shared_ptr<TaskContext>& context,
////                                                            CommandSet&& set,
////                                                            IndexQualifierMode mode,
////                                                            IMasterApplication& app,
////                                                            const CommandResultCallbackT& callback,
////                                                            const Timestamp& startExpiration,
////                                                            const TaskConfig& config,
////                                                            Logger logger);
////    static std::shared_ptr<IMasterTask> CreateSelectAndOperate(const std::shared_ptr<TaskContext>& context,
////                                                               CommandSet&& set,
////                                                               IndexQualifierMode mode,
////                                                               IMasterApplication& app,
////                                                               const CommandResultCallbackT& callback,
////                                                               const Timestamp& startExpiration,
////                                                               const TaskConfig& config,
////                                                               Logger logger);

////    virtual char const* Name() const override final
////    {
////        return "Command Task";
////    }

////    virtual int Priority() const override final
////    {
////        return priority::COMMAND;
////    }

////    virtual bool BlocksLowerPriority() const override final
////    {
////        return false;
////    }

////    virtual bool IsRecurring() const override final
////    {
////        return false;
////    }

////    virtual bool BuildRequest(APDURequest& request, uint8_t seq) override final;

////private:
////    virtual bool IsEnabled() const override final
////    {
////        return true;
////    }

////    virtual MasterTaskType GetTaskType() const override final
////    {
////        return MasterTaskType::USER_TASK;
////    }

////    virtual void Initialize() override final;

////    virtual ResponseResult ProcessResponse(const APDUResponseHeader& header,
////                                           const ser4cpp::rseq_t& objects) override final;

////    virtual void OnTaskComplete(TaskCompletion result, Timestamp now) override final;

////    ResponseResult ProcessResponse(const ser4cpp::rseq_t& objects);

////    void LoadSelectAndOperate();
////    void LoadDirectOperate();

  std::deque<FunctionCode_uint8_t> functionCodes;

  CommandStatus_uint8_t statusResult;
  CommandResultCallbackT commandCallback;
  CommandSet commands;
  IndexQualifierMode_uint8_t mode;
} CommandTask;

IMasterTask* CreateDirectOperate_in_CommandTask_static(//const std::shared_ptr<TaskContext>& context,
  CommandSet* set,
  IndexQualifierMode_uint8_t mode,
  IMasterApplication* app,
  CommandResultCallbackT callback,
  Timestamp* startExpiration,
  TaskConfig* config);
////                                                            Logger logger);
IMasterTask* CreateSelectAndOperate_in_CommandTask_static(//const std::shared_ptr<TaskContext>& context,
  CommandSet* set,
  IndexQualifierMode_uint8_t mode,
  IMasterApplication* app,
  CommandResultCallbackT callback,
  Timestamp* startExpiration,
  TaskConfig* config);
///                                                               Logger logger);

void LoadSelectAndOperate_in_CommandTask(CommandTask *pCommandTask);
void LoadDirectOperate_in_CommandTask(CommandTask *pCommandTask);
ResponseResult_in_IMasterTask_uint8_t ProcessResponse_in_CommandTaskOver2(CommandTask *pCommandTask, RSeq_for_Uint16_t* objects);

boolean IsRecurring_in_CommandTask(CommandTask *pCommandTask);
boolean IsRecurring_in_CommandTask_override(void *pIMasterTask);

boolean BlocksLowerPriority_in_CommandTask(CommandTask *pCommandTask);
boolean BlocksLowerPriority_in_CommandTask_override(void *pIMasterTask);

boolean BuildRequest_in_CommandTask(CommandTask *pCommandTask, APDURequest* request, uint8_t seq);
boolean BuildRequest_in_CommandTask_override(void *pIMasterTask, APDURequest* request, uint8_t seq);

int Priority_in_CommandTask(CommandTask *pCommandTask);
int Priority_in_CommandTask_override(void *pIMasterTask);

MasterTaskType_uint8_t GetTaskType_in_CommandTask(CommandTask *pCommandTask);
MasterTaskType_uint8_t GetTaskType_in_CommandTask_override(void *pIMasterTask);

void Initialize_in_CommandTask(CommandTask *pCommandTask);
void Initialize_in_CommandTask_override(void *pIMasterTask);

ResponseResult_in_IMasterTask_uint8_t ProcessResponse_in_CommandTask(CommandTask *pCommandTask,
    APDUResponseHeader* header, RSeq_for_Uint16_t* objects);
ResponseResult_in_IMasterTask_uint8_t ProcessResponse_in_CommandTask_override(void *pIMasterTask,
    APDUResponseHeader* header, RSeq_for_Uint16_t* objects);

boolean IsEnabled_in_CommandTask(CommandTask *pCommandTask);
boolean IsEnabled_in_CommandTask_override(void *pIMasterTask);

void OnTaskComplete_in_CommandTask(CommandTask *pCommandTask, TaskCompletion_uint8_t result, Timestamp now);
void OnTaskComplete_in_CommandTask_override(void *pIMasterTask, TaskCompletion_uint8_t result, Timestamp now);

////} // namespace opendnp3

#endif
