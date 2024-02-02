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
#ifndef OPENDNP3_UNITTESTS_MASTERTESTFIXTURE_H
#define OPENDNP3_UNITTESTS_MASTERTESTFIXTURE_H

////#include <opendnp3/logging/LogLevels.h>

////#include <exe4cpp/MockExecutor.h>
#include "MockExecutorExe4cpp.h"

////#include "dnp3mocks/MockLogHandler.h"
#include "MockLowerLayer.h"
#include "MockMasterApplication.h"
#include "MockSOEHandler.h"

#include "MasterContext.h"
#include "MasterSchedulerBackend.h"

////opendnp3::MasterParams NoStartupTasks();

////class MasterTestFixture
typedef struct
{
////public:
////    MasterTestFixture(const opendnp3::MasterParams& param,
////                      const opendnp3::Addresses& = opendnp3::Addresses(1, 1024),
////                      const std::string& id = "test",
////                      const std::shared_ptr<opendnp3::ILogHandler>& log = nullptr,
////                      const std::shared_ptr<exe4cpp::MockExecutor>& executor = nullptr,
////                      const std::shared_ptr<opendnp3::IMasterScheduler>& scheduler = nullptr);
////    virtual ~MasterTestFixture();

////    bool SendToMaster(const std::string& hex);

    Addresses addresses;

////    const std::shared_ptr<opendnp3::ILogHandler> log;
    MockExecutor exe;
    MockSOEHandler meas;
    MockLowerLayer lower;
    MockMasterApplication application;
    IMasterScheduler scheduler;
    MContext *context;
} MasterTestFixture;

   void MasterTestFixture_in_MasterTestFixture(MasterTestFixture *pMasterTestFixture,
                      MasterParams* param,
                      Addresses addresses,//& = opendnp3::Addresses(1, 1024),
                      //const std::string& id = "test",
                      //const std::shared_ptr<opendnp3::ILogHandler>& log = nullptr,
                      MockExecutor* executor,// = nullptr,
                      IMasterScheduler* scheduler);// = nullptr);

   boolean SendToMaster_in_MasterTestFixture(MasterTestFixture *pMasterTestFixture, std::string& hex);
MasterParams NoStartupTasks_static(void);

#endif
