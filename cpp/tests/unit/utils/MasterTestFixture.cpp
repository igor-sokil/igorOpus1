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
#include "MasterTestFixture.h"

#include "BufferHelpers.h"

#include "DefaultMasterApplication.h"

////using namespace opendnp3;

MasterParams NoStartupTasks_static(void)
{
  MasterParams params;
  params.disableUnsolOnStartup = false;
  params.startupIntegrityClassMask = None_in_ClassField_static();
  params.unsolClassMask = None_in_ClassField_static();
  return params;
}

static MasterSchedulerBackend mMasterSchedulerBackend;

void* getMasterScheduler_in_MasterTestFixture(void)
{
  return &mMasterSchedulerBackend;
}

////MasterTestFixture::MasterTestFixture(const MasterParams& params,
////                                     const Addresses& addresses,
////                                     const std::string& id,
////                                     const std::shared_ptr<ILogHandler>& log,
////                                     const std::shared_ptr<exe4cpp::MockExecutor>& executor,
////                                     const std::shared_ptr<IMasterScheduler>& scheduler)
void MasterTestFixture_in_MasterTestFixture(MasterTestFixture *pMasterTestFixture,
    MasterParams* params,
    Addresses addresses,//& = opendnp3::Addresses(1, 1024),
    //const std::string& id = "test",
    //const std::shared_ptr<opendnp3::ILogHandler>& log = nullptr,
    MockExecutor* executor,// = nullptr,
    IMasterScheduler* scheduler)// = nullptr);
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  std::cout<<"{MasterTestFixture_in_MasterTestFixture1"<<'\n';
#endif
  pMasterTestFixture->addresses = addresses;
////      log(log),
///      exe(executor ? executor : std::make_shared<exe4cpp::MockExecutor>()),
  if(executor)
  {
    pMasterTestFixture->exe = *executor;
  }
  else MockExecutor_in_MockExecutor(&(pMasterTestFixture->exe));

////      meas(std::make_shared<MockSOEHandler>()),
  MockSOEHandler_in_MockSOEHandler(&(pMasterTestFixture->meas));

////      lower(std::make_shared<MockLowerLayer>()),
  MockLowerLayer_in_MockLowerLayer(&(pMasterTestFixture->lower));

////      application(std::make_shared<MockMasterApplication>()),
  MockMasterApplication_in_MockMasterApplication(&(pMasterTestFixture->application));

////      scheduler(scheduler ? scheduler : std::make_shared<MasterSchedulerBackend>(exe)),
  if(scheduler)
  {
    pMasterTestFixture->scheduler = *scheduler;
  }
  else
  {
    MasterSchedulerBackend_in_MasterSchedulerBackend(&mMasterSchedulerBackend, &(pMasterTestFixture->exe.iIExecutorExe4cpp));
    pMasterTestFixture->scheduler = mMasterSchedulerBackend.iIMasterScheduler;
  }

//MContext* Create_in_MContext_static(
//  Addresses* addresses,
////        const Logger& logger,
//  IExecutorExe4cpp* executor,
//  ILowerLayer* lower,
//  ISOEHandler* SOEHandler,
//  IMasterApplication* application,
//  IMasterScheduler* scheduler,
//  MasterParams* params
//);
////      context(MContext::Create(addresses,
////                               Logger(log, ModuleId(), id, LogLevels::everything()),
////                               exe,
////                               lower,
////                               meas,
////                               application,
////                               this->scheduler,
///                               params))
  pMasterTestFixture->context = Create_in_MContext_static(
                                  &addresses,
////        const Logger& logger,
                                  &(pMasterTestFixture->exe.iIExecutorExe4cpp),
                                  &(pMasterTestFixture->lower.iILowerLayer),
                                  &(pMasterTestFixture->meas.iISOEHandler),
                                  &(pMasterTestFixture->application.iIMasterApplication),
                                  &(pMasterTestFixture->scheduler),
                                  params
                                );
#ifdef  LOG_INFO
  std::cout<<'\n';
  std::cout<<"}MasterTestFixture_in_MasterTestFixture_"<<'\n';
#endif
}

////MasterTestFixture::~MasterTestFixture()
////{
////    this->scheduler->Shutdown();
////}

////bool MasterTestFixture::SendToMaster(const std::string& hex)
boolean SendToMaster_in_MasterTestFixture(MasterTestFixture *pMasterTestFixture, std::string& hex)
{
////    HexSequence hs(hex);
  HexSequence hs;
  HexSequence_in_HexSequence(&hs, hex);

//void  Message_in_Message(Message *pMessage, Addresses *addresses, RSeq_for_Uint16_t* payload);
//Addresses Reverse_in_Addresses(Addresses *pAddresses);
//boolean OnReceive_in_MContext(MContext *pMContext, Message* message);
////    return context->OnReceive(Message(this->addresses.Reverse(), hs.ToRSeq()));
  RSeq_for_Uint16_t temp = ToRSeq_in_CopyableBuffer(&(hs.bByteStr.cCopyableBuffer));
  Addresses atmp = Reverse_in_Addresses(&(pMasterTestFixture->addresses));
  Message mMessage;
  Message_in_Message(&mMessage, &atmp, &temp);
  return OnReceive_in_MContext(pMasterTestFixture->context, &mMessage);
}
