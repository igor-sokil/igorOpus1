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
#include <QtWidgets>
#include <QApplication>
#include "header.h"
#include "OutstationTestObject.h"

////#include "utils/BufferHelpers.h"

////using namespace opendnp3;

///   void OContext_in_OContext(OContext *pOContext,
///             Addresses* addresses,
///             OutstationConfig* config,
///             DatabaseConfig* db_config,
//             const Logger& logger,
///             IExecutorExe4cpp* executor,
///             ILowerLayer* lower,
///             ICommandHandler* commandHandler,
///             IOutstationApplication* application);

void OutstationTestObject_in_OutstationTestObject(OutstationTestObject *pOutstationTestObject, OutstationConfig* config)////, const opendnp3::DatabaseConfig& db_config)
{
////    : exe(std::make_shared<exe4cpp::MockExecutor>()),
 MockExecutor_in_MockExecutor(&(pOutstationTestObject->exe));

////      lower(std::make_shared<MockLowerLayer>()),
 MockLowerLayer_in_MockLowerLayer(&(pOutstationTestObject->lower));

////      cmdHandler(std::make_shared<MockCommandHandler>(CommandStatus::SUCCESS)),
 MockCommandHandler_in_MockCommandHandler(&(pOutstationTestObject->cmdHandler), CommandStatus_SUCCESS);

////      application(std::make_shared<MockOutstationApplication>()),
 MockOutstationApplication_in_MockOutstationApplication(&(pOutstationTestObject->application));
qDebug()<<"OutstationTestObject_in_OutstationTestObject!!!";


//  void Addresses_in_AddressesOver1(Addresses *pAddresses);
////      context(Addresses(), config, db_config, log.logger, exe, lower, cmdHandler, application)
   Addresses aAddresses;
   Addresses_in_AddressesOver1(&aAddresses);
   OContext_in_OContext(&(pOutstationTestObject->context),
///             Addresses* addresses,
                &aAddresses,
///             OutstationConfig* config,
                config,
///             DatabaseConfig* db_config,
                NULL,
//             const Logger& logger,
///             IExecutorExe4cpp* executor,
                &(pOutstationTestObject->exe.iIExecutorExe4cpp),
///             ILowerLayer* lower,
                &(pOutstationTestObject->lower.iILowerLayer),
///             ICommandHandler* commandHandler,
                &(pOutstationTestObject->cmdHandler.sSimpleCommandHandler.iICommandHandler),
///             IOutstationApplication* application);
                &(pOutstationTestObject->application.iIOutstationApplication));


//    void SetUpperLayer_in_HasUpperLayer(HasUpperLayer *pHasUpperLayer, IUpperLayer* upperLayer);
////    lower->SetUpperLayer(context);
    SetUpperLayer_in_HasUpperLayer(&(pOutstationTestObject->lower.hHasUpperLayer), &(pOutstationTestObject->context.iIUpperLayer));

}

////size_t OutstationTestObject::LowerLayerUp()
   uint16_t LowerLayerUp_in_OutstationTestObject(OutstationTestObject *pOutstationTestObject)
{
//boolean OnLowerLayerUp_in_OContext(OContext*);
////    context.OnLowerLayerUp();
 OnLowerLayerUp_in_OContext(&(pOutstationTestObject->context));
////    return exe->run_many();
}

////size_t OutstationTestObject::LowerLayerDown()
////{
////    context.OnLowerLayerDown();
////    return exe->run_many();
////}

////size_t OutstationTestObject::OnTxReady()
////{
////    context.OnTxReady();
////    return exe->run_many();
////}

////size_t OutstationTestObject::SendToOutstation(const std::string& hex)
////{
////    HexSequence hs(hex);
////    context.OnReceive(Message(Addresses(), hs.ToRSeq()));
////    return exe->run_many();
////}

////size_t OutstationTestObject::BroadcastToOutstation(LinkBroadcastAddress broadcast_address, const std::string& hex)
////{
////    HexSequence hs(hex);
////    context.OnReceive(Message(Addresses(0, broadcast_address), hs.ToRSeq()));
////    return exe->run_many();
////}

////size_t OutstationTestObject::NumPendingTimers() const
////{
////    return exe->num_pending_timers();
////}

////bool OutstationTestObject::AdvanceToNextTimer()
////{
////    if (exe->advance_to_next_timer())
////    {
////        return exe->run_many() > 0;
////    }

////    return false;
////}

////size_t OutstationTestObject::AdvanceTime(const TimeDuration& td)
////{
////    exe->advance_time(td.value);
////    return exe->run_many();
////}
