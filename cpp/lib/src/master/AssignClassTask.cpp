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
#include "AssignClassTask.h"

#include "HeaderWriter.h"

#include "IMasterApplication.h"

////namespace opendnp3
////{

////AssignClassTask::AssignClassTask(const std::shared_ptr<TaskContext>& context,
////                                 IMasterApplication& application,
////                                 const TaskBehavior& behavior,
////                                 const Logger& logger)
void AssignClassTask_in_AssignClassTask(AssignClassTask *pAssignClassTask,
//                       const std::shared_ptr<TaskContext>& context,
                                        IMasterApplication* application,
                                        TaskBehavior* behavior)
{
//void IMasterTask_in_IMasterTask(IMasterTask *pIMasterTask,
//                TaskContext* context,
//                                IMasterApplication* app,
//                                TaskBehavior behavior,
//                const Logger& logger,
//                                TaskConfig config);
//TaskConfig Default_in_TaskConfig_static(void);
///    : IMasterTask(context, application, behavior, logger, TaskConfig::Default())
  IMasterTask_in_IMasterTask(&(pAssignClassTask->iIMasterTask),
//                TaskContext* context,
                             application,
                             *behavior,
//                const Logger& logger,
                             Default_in_TaskConfig_static());

  pAssignClassTask->iIMasterTask.pIsRecurring_in_IMasterTask = IsRecurring_in_AssignClassTask_override;
  pAssignClassTask->iIMasterTask.pBuildRequest_in_IMasterTask = BuildRequest_in_AssignClassTask_override;
  pAssignClassTask->iIMasterTask.pPriority_in_IMasterTask = Priority_in_AssignClassTask_override;
  pAssignClassTask->iIMasterTask.pGetTaskType_in_IMasterTask = GetTaskType_in_AssignClassTask_override;
  pAssignClassTask->iIMasterTask.pProcessResponse_in_IMasterTask = ProcessResponse_in_AssignClassTask_override;
  pAssignClassTask->iIMasterTask.pIsEnabled_in_IMasterTask = IsEnabled_in_AssignClassTask_override;
  pAssignClassTask->iIMasterTask.pName_in_IMasterTask = Name_in_AssignClassTask_override;

  setParentPointer_in_IMasterTask(&(pAssignClassTask->iIMasterTask), pAssignClassTask);
}

void writeFun_in_AssignClassTask(Header *pHeader);
void writeFun_in_AssignClassTask(Header *pHeader)
{
  boolean *success = (boolean *)pPointerGlobal1;
  HeaderWriter *writer = (HeaderWriter *)pPointerGlobal2;
//typedef void (*WriteHeaderFunT)(Header*);
//  boolean WriteTo_in_Header(Header *pHeader, HeaderWriter* writer);
////    auto writeFun = [&](const Header& header) { success &= header.WriteTo(writer); };
  (*success) &= WriteTo_in_Header(pHeader, writer);
}

////bool AssignClassTask::BuildRequest(APDURequest& request, uint8_t seq)
boolean BuildRequest_in_AssignClassTask(AssignClassTask *pAssignClassTask, APDURequest* request, uint8_t seq)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{BuildRequest_in_AssignClassTask1"<<'\n';
#endif
//void AppControlField_in_AppControlFieldOver4(AppControlField *, boolean fir, boolean fin, boolean con, boolean uns, uint8_t seq);
////    request.SetControl(AppControlField(true, true, false, false, seq));
  AppControlField aAppControlField;
  AppControlField_in_AppControlFieldOver4(&aAppControlField, true, true, false, false, seq);
  SetControl_in_APDUWrapper(&(request->aAPDUWrapper), aAppControlField);

////    request.SetFunction(FunctionCode::ASSIGN_CLASS);
  SetFunction_in_APDUWrapper(&(request->aAPDUWrapper), FunctionCode_ASSIGN_CLASS);

////    auto writer = request.GetWriter();
  HeaderWriter writer = GetWriter_in_APDUWrapper(&(request->aAPDUWrapper));

  boolean success = true;
//typedef void (*WriteHeaderFunT)(Header*);
//    auto writeFun = [&](const Header& header) { success &= header.WriteTo(writer); };
//writeFun_in_AssignClassTask
  pPointerGlobal1 = &success;
  pPointerGlobal2 = &writer;
//typedef void (*WriteHeaderFunT)(Header*);
//void ConfigureAssignClassRequest_in_IMasterApplication(IMasterApplication *pIMasterApplication, WriteHeaderFunT fun);
////    this->application->ConfigureAssignClassRequest(writeFun);
  ConfigureAssignClassRequest_in_IMasterApplication(pAssignClassTask->iIMasterTask.application, writeFun_in_AssignClassTask);

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}BuildRequest_in_AssignClassTask_"<<'\n';
  decrement_stack_info();
#endif
  return success;
}

////bool AssignClassTask::IsEnabled() const
boolean IsEnabled_in_AssignClassTask(AssignClassTask *pAssignClassTask)
{
//boolean AssignClassDuringStartup_in_IMasterApplication(IMasterApplication *pIMasterApplication);
////    return this->application->AssignClassDuringStartup();
  return AssignClassDuringStartup_in_IMasterApplication(pAssignClassTask->iIMasterTask.application);
}

////IMasterTask::ResponseResult AssignClassTask::ProcessResponse(const APDUResponseHeader& header,
////                                                             const ser4cpp::rseq_t& objects)
ResponseResult_in_IMasterTask_uint8_t ProcessResponse_in_AssignClassTask(AssignClassTask *pAssignClassTask,
    APDUResponseHeader* header, RSeq_for_Uint16_t* objects)
{
//boolean ValidateNullResponse_in_IMasterTask(IMasterTask *pIMasterTask, APDUResponseHeader* header, RSeq_for_Uint16_t* objects);
////    return ValidateNullResponse(header, objects) ? ResponseResult::OK_FINAL : ResponseResult::ERROR_BAD_RESPONSE;
  return ValidateNullResponse_in_IMasterTask(&(pAssignClassTask->iIMasterTask), header, objects) ?
         ResponseResult_in_IMasterTask_OK_FINAL : ResponseResult_in_IMasterTask_ERROR_BAD_RESPONSE;
}

////} // namespace opendnp3
////    virtual bool IsRecurring() const override
////    virtual int Priority(void) const override
int Priority_in_AssignClassTask(AssignClassTask *pAssignClassTask)
{
  UNUSED(pAssignClassTask);
  return priority_ASSIGN_CLASS;
}

boolean IsRecurring_in_AssignClassTask(AssignClassTask *pAssignClassTask)
{
  UNUSED(pAssignClassTask);
  return true;
}

////    virtual bool BlocksLowerPriority() const override
////    {
////        return true;
////    }

MasterTaskType_uint8_t GetTaskType_in_AssignClassTask(AssignClassTask *pAssignClassTask)
{
  UNUSED(pAssignClassTask);
  return MasterTaskType_ASSIGN_CLASS;
}

boolean IsRecurring_in_AssignClassTask_override(void *pIMasterTask)
{
  AssignClassTask *parent = (AssignClassTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return IsRecurring_in_AssignClassTask(parent);
}

boolean BuildRequest_in_AssignClassTask_override(void *pIMasterTask, APDURequest* request, uint8_t seq)
{
  AssignClassTask *parent = (AssignClassTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return BuildRequest_in_AssignClassTask(parent, request, seq);
}

int Priority_in_AssignClassTask_override(void *pIMasterTask)
{
  AssignClassTask *parent = (AssignClassTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return Priority_in_AssignClassTask(parent);
}

MasterTaskType_uint8_t GetTaskType_in_AssignClassTask_override(void *pIMasterTask)
{
  AssignClassTask *parent = (AssignClassTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return GetTaskType_in_AssignClassTask(parent);
}

ResponseResult_in_IMasterTask_uint8_t ProcessResponse_in_AssignClassTask_override(void *pIMasterTask,
    APDUResponseHeader* header, RSeq_for_Uint16_t* objects)
{
  AssignClassTask *parent = (AssignClassTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return ProcessResponse_in_AssignClassTask_override(parent, header, objects);
}

boolean IsEnabled_in_AssignClassTask_override(void *pIMasterTask)
{
  AssignClassTask *parent = (AssignClassTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return IsEnabled_in_AssignClassTask(parent);
}

char * Name_in_AssignClassTask(AssignClassTask *pAssignClassTask)
{
   return (char*)"Assign Class";
}
char * Name_in_AssignClassTask_override(void *pIMasterTask)
{
  AssignClassTask *parent = (AssignClassTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return Name_in_AssignClassTask(parent);
}
