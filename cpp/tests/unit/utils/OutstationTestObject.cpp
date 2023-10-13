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
//#include <QtWidgets>
#include <QApplication>
#include "header.h"
#include "BufferHelpers.h"
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

void OutstationTestObject_in_OutstationTestObject(OutstationTestObject *pOutstationTestObject, OutstationConfig* config, DatabaseConfig* db_config)
{
////    : exe(std::make_shared<exe4cpp::MockExecutor>()),
  MockExecutor_in_MockExecutor(&(pOutstationTestObject->exe));

////      lower(std::make_shared<MockLowerLayer>()),
  MockLowerLayer_in_MockLowerLayer(&(pOutstationTestObject->lower));

////      cmdHandler(std::make_shared<MockCommandHandler>(CommandStatus::SUCCESS)),
  MockCommandHandler_in_MockCommandHandler(&(pOutstationTestObject->cmdHandler), CommandStatus_SUCCESS);

////      application(std::make_shared<MockOutstationApplication>()),
  MockOutstationApplication_in_MockOutstationApplication(&(pOutstationTestObject->application));

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
                       db_config,
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
  return run_many_in_MockExecutor(&(pOutstationTestObject->exe), 100);
}

////size_t OutstationTestObject::LowerLayerDown()
////{
////    context.OnLowerLayerDown();
////    return exe->run_many();
////}

////size_t OutstationTestObject::OnTxReady()
uint16_t OnTxReady_in_OutstationTestObject(OutstationTestObject *pOutstationTestObject)
{
//boolean OnTxReady_in_OContext(OContext* pOContext)
////    context.OnTxReady();
   OnTxReady_in_OContext(&(pOutstationTestObject->context));
////    return exe->run_many();
  return run_many_in_MockExecutor(&(pOutstationTestObject->exe), 100);
}

//Message mMessage1_global_in_OutstationTestObject;
////size_t OutstationTestObject::SendToOutstation(const std::string& hex)
uint16_t SendToOutstation_in_OutstationTestObject(OutstationTestObject *pOutstationTestObject, std::string& hex)
{
//   void HexSequence_in_HexSequence(HexSequence *pHexSequence, std::string& hex);
////    HexSequence hs(hex);
  HexSequence hs;
  HexSequence_in_HexSequence(&hs, hex);

//RSeq_for_Uint16_t ToRSeq_in_CopyableBuffer(CopyableBuffer *pCopyableBuffer);
//&(hs.bByteStr.cCopyableBuffer)
//boolean OnReceive_in_OContext(OContext*, Message* message);
//void  Message_in_Message(Message *pMessage, Addresses *addresses, RSeq_for_Uint16_t* payload);
////    context.OnReceive(Message(Addresses(), hs.ToRSeq()));
  RSeq_for_Uint16_t temp = ToRSeq_in_CopyableBuffer(&(hs.bByteStr.cCopyableBuffer));

  Addresses aAddresses;
  Addresses_in_AddressesOver1(&aAddresses);
  Message mMessage;
  Message_in_Message(&mMessage, &aAddresses, &temp);

  /*boolean tmp =*/ OnReceive_in_OContext(&(pOutstationTestObject->context), &mMessage);

////    return exe->run_many();
  return run_many_in_MockExecutor(&(pOutstationTestObject->exe), 100);
}

void Transaction_in_OutstationTestObject(OutstationTestObject *pOutstationTestObject, void (*apply)(IUpdateHandler*))//std::function<void(opendnp3::IUpdateHandler&)>& apply)
{
  // auto& handler = context.GetUpdateHandler();
//IUpdateHandler* GetUpdateHandler_in_OContext(OContext *pOContext);
////        apply(context.GetUpdateHandler());
  apply(GetUpdateHandler_in_OContext(&(pOutstationTestObject->context)));

//void HandleNewEvents_in_OContext(OContext *pOContext);
////        context.HandleNewEvents();
  HandleNewEvents_in_OContext(&(pOutstationTestObject->context));
}

////size_t OutstationTestObject::BroadcastToOutstation(LinkBroadcastAddress broadcast_address, const std::string& hex)
uint16_t BroadcastToOutstation_in_OutstationTestObject(OutstationTestObject *pOutstationTestObject, LinkBroadcastAddress_uint16_t broadcast_address, std::string& hex)
{
////    HexSequence hs(hex);
  HexSequence hs;
  HexSequence_in_HexSequence(&hs, hex);

//void Addresses_in_AddressesOver2(Addresses *pAddresses, uint16_t source, uint16_t destination);
////    context.OnReceive(Message(Addresses(0, broadcast_address), hs.ToRSeq()));
////    return exe->run_many();
  RSeq_for_Uint16_t temp = ToRSeq_in_CopyableBuffer(&(hs.bByteStr.cCopyableBuffer));
  Addresses aAddresses;
  Addresses_in_AddressesOver2(&aAddresses, 0, broadcast_address);
  Message mMessage;
  Message_in_Message(&mMessage, &aAddresses, &temp);
  /*boolean tmp = */OnReceive_in_OContext(&(pOutstationTestObject->context), &mMessage);

////    return exe->run_many();
  return run_many_in_MockExecutor(&(pOutstationTestObject->exe), 100);
}

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

uint16_t AdvanceTime_in_OutstationTestObject(OutstationTestObject *pOutstationTestObject, TimeDuration* td)
{
//uint16_t advance_time_in_MockExecutor(MockExecutor *pMockExecutor, uint32_t duration);
////    exe->advance_time(td.value);
  advance_time_in_MockExecutor(&(pOutstationTestObject->exe), td->duration_value);
////    return exe->run_many();
  return run_many_in_MockExecutor(&(pOutstationTestObject->exe), 100);
}
