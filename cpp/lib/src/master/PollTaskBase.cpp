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
#include <QApplication>
#include "header.h"
#include "PollTaskBase.h"

////#include "logging/LogMacros.h"
#include "MeasurementHandler.h"

////#include "opendnp3/logging/LogLevels.h"

////namespace opendnp3
////{

////PollTaskBase::PollTaskBase(const std::shared_ptr<TaskContext>& context,
////                           IMasterApplication& application,
////                           std::shared_ptr<ISOEHandler> handler,
////                           const TaskBehavior& behavior,
////                           const Logger& logger,
////                           TaskConfig config)

void PollTaskBase_in_PollTaskBase(PollTaskBase *pPollTaskBase,
//                 TaskContext* context,
                                  IMasterApplication* application,
                                  ISOEHandler* handler,
                                  TaskBehavior* behavior,
//                 const Logger& logger,
                                  TaskConfig config)
{
//void IMasterTask_in_IMasterTask(IMasterTask *pIMasterTask,
//                TaskContext* context,
//                                IMasterApplication* app,
//                                TaskBehavior behavior,
//                const Logger& logger,
//                                TaskConfig config);
////    : IMasterTask(context, application, behavior, logger, config), handler(std::move(handler))
  IMasterTask_in_IMasterTask(&(pPollTaskBase->iIMasterTask),
//                TaskContext* context,
                             application,
                             *behavior,
//                const Logger& logger,
                             config);
  pPollTaskBase->handler = handler;

  pPollTaskBase->rxCount = 0;

  pPollTaskBase->iIMasterTask.pInitialize_in_IMasterTask = Initialize_in_PollTaskBase_override;
  pPollTaskBase->iIMasterTask.pProcessResponse_in_IMasterTask = ProcessResponse_in_PollTaskBase_override;
  setParentPointer_in_IMasterTask(&(pPollTaskBase->iIMasterTask), pPollTaskBase);
}

////void PollTaskBase::Initialize()
void Initialize_in_PollTaskBase(PollTaskBase *pPollTaskBase)
{
  pPollTaskBase->rxCount = 0;
}
void Initialize_in_PollTaskBase_override(void *pIMasterTask)
{
  PollTaskBase* parent = (PollTaskBase*)getParentPointer_in_IMasterTask((IMasterTask*)pIMasterTask);
  Initialize_in_PollTaskBase(parent);
}

ResponseResult_in_IMasterTask_uint8_t ProcessResponse_in_PollTaskBase(PollTaskBase *pPollTaskBase, APDUResponseHeader* header,
    RSeq_for_Uint16_t* objects)
{
  if (header->aAPDUHeader.control.FIR)
  {
    if (pPollTaskBase->rxCount > 0)
    {
////            SIMPLE_LOG_BLOCK(logger, flags::WARN, "Ignoring unexpected FIR frame");
#ifdef  LOG_INFO
      increment_stack_info();
      std::cout<<getString_stack_info();
      std::cout<<"SIMPLE_LOG_BLOCK(logger, flags::WARN, 'Ignoring unexpected FIR frame')"<<'\n';
      decrement_stack_info();
#endif
      return ResponseResult_in_IMasterTask_ERROR_BAD_RESPONSE;
    }

//ResponseResult_in_IMasterTask_uint8_t ProcessMeasurements_in_PollTaskBase(PollTaskBase *pPollTaskBase, APDUResponseHeader* header,
//                                                              RSeq_for_Uint16_t* objects)
////        return ProcessMeasurements(header, objects);
    return ProcessMeasurements_in_PollTaskBase(pPollTaskBase, header, objects);
  }
  else
  {
    if (pPollTaskBase->rxCount > 0)
    {
////            return ProcessMeasurements(header, objects);
      return ProcessMeasurements_in_PollTaskBase(pPollTaskBase, header, objects);
    }

////        SIMPLE_LOG_BLOCK(logger, flags::WARN, "Ignoring unexpected non-FIR frame");
#ifdef  LOG_INFO
    increment_stack_info();
    std::cout<<getString_stack_info();
    std::cout<<"SIMPLE_LOG_BLOCK(logger, flags::WARN, 'Ignoring unexpected non-FIR frame')"<<'\n';
    decrement_stack_info();
#endif
    return ResponseResult_in_IMasterTask_ERROR_BAD_RESPONSE;
  }
}
ResponseResult_in_IMasterTask_uint8_t ProcessResponse_in_PollTaskBase_override(void *pIMasterTask, APDUResponseHeader* header,
    RSeq_for_Uint16_t* objects)
{
  PollTaskBase* parent = (PollTaskBase*)getParentPointer_in_IMasterTask((IMasterTask*)pIMasterTask);
  return ProcessResponse_in_PollTaskBase(parent, header, objects);
}

ResponseResult_in_IMasterTask_uint8_t ProcessMeasurements_in_PollTaskBase(PollTaskBase *pPollTaskBase, APDUResponseHeader* header,
    RSeq_for_Uint16_t* objects)
{
  ++(pPollTaskBase->rxCount);

//ResponseInfo as_response_info_in_APDUResponseHeader(APDUResponseHeader *pAPDUResponseHeader) 
//ParseResult_uint8_t ProcessMeasurements_in_MeasurementHandler_static(ResponseInfo info,
//    RSeq_for_Uint16_t* objects,
////                                           Logger& logger,
//    ISOEHandler* pHandler);
///    if (MeasurementHandler::ProcessMeasurements(header.as_response_info(), objects, logger, handler.get())
///        == ParseResult::OK)
  if (ProcessMeasurements_in_MeasurementHandler_static(as_response_info_in_APDUResponseHeader(header), objects,
////                                           Logger& logger,
      pPollTaskBase->handler) == ParseResult_OK)
  {
    return header->aAPDUHeader.control.FIN ? ResponseResult_in_IMasterTask_OK_FINAL : ResponseResult_in_IMasterTask_OK_CONTINUE;
  }

  return ResponseResult_in_IMasterTask_ERROR_BAD_RESPONSE;
}

////} // namespace opendnp3
