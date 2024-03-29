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
#ifndef OPENDNP3_POLLTASKBASE_H
#define OPENDNP3_POLLTASKBASE_H

#include "IMasterTask.h"
#include "ISOEHandler.h"

////#include <memory>
////#include <string>

////namespace opendnp3
////{

////class ISOEHandler;

/**
 * Base class for measurement polls
 */
////class PollTaskBase : public IMasterTask
typedef struct
{
  IMasterTask iIMasterTask;
////public:
////    PollTaskBase(const std::shared_ptr<TaskContext>& context,
////                 IMasterApplication& application,
////                 std::shared_ptr<ISOEHandler> handler,
////                 const TaskBehavior& behavior,
////                 const Logger& logger,
////                 TaskConfig config);

////    virtual const char* Name() const override
////    {
////        return "Application Poll";
////    };

////protected:
////    virtual ResponseResult ProcessResponse(const APDUResponseHeader& header,
////                                           const ser4cpp::rseq_t& objects) override final;

////    ResponseResult ProcessMeasurements(const APDUResponseHeader& header, const ser4cpp::rseq_t& objects);

////    virtual void Initialize() override final;

  uint32_t rxCount;// = 0;
  ISOEHandler* handler;
} PollTaskBase;

void PollTaskBase_in_PollTaskBase(PollTaskBase *pPollTaskBase,
//                 TaskContext* context,
                                  IMasterApplication* application,
                                  ISOEHandler* handler,
                                  TaskBehavior* behavior,
//                 const Logger& logger,
                                  TaskConfig config);

void Initialize_in_PollTaskBase(PollTaskBase *pPollTaskBase);
void Initialize_in_PollTaskBase_override(void *pIMasterTask);

ResponseResult_in_IMasterTask_uint8_t ProcessResponse_in_PollTaskBase(PollTaskBase *pPollTaskBase, APDUResponseHeader* header,
    RSeq_for_Uint16_t* objects);
ResponseResult_in_IMasterTask_uint8_t ProcessResponse_in_PollTaskBase_override(void *pIMasterTask, APDUResponseHeader* header,
    RSeq_for_Uint16_t* objects);

ResponseResult_in_IMasterTask_uint8_t ProcessMeasurements_in_PollTaskBase(PollTaskBase *pPollTaskBase, APDUResponseHeader* header,
    RSeq_for_Uint16_t* objects);

////} // namespace opendnp3

#endif
