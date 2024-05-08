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
//#include <QtWidgets>
#include <QApplication>
#include "header.h"
#include "BufferHelpers.h"
#include "OutstationObjectMrzs.h"

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

void OutstationObjectMrzs_in_OutstationObjectMrzs(OutstationObjectMrzs *pOutstationObjectMrzs, OutstationConfig* config, DatabaseConfig* db_config)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  std::cout<<"{OutstationObjectMrzs_in_OutstationObjectMrzs1"<<'\n';
#endif
////    : exe(std::make_shared<exe4cpp::MockExecutor>()),
  MockExecutor_in_MockExecutor(&(pOutstationObjectMrzs->exe));

////      lower(std::make_shared<MockLowerLayer>()),
  MrzsLowerLayer_in_MrzsLowerLayer(&(pOutstationObjectMrzs->lower_in_OutstationObjectMrzs));

////      cmdHandler(std::make_shared<MockCommandHandler>(CommandStatus::SUCCESS)),
  MockCommandHandler_in_MockCommandHandler(&(pOutstationObjectMrzs->cmdHandler), CommandStatus_SUCCESS);

////      application(std::make_shared<MockOutstationApplication>()),
  MockOutstationApplication_in_MockOutstationApplication(&(pOutstationObjectMrzs->application));

//  void Addresses_in_AddressesOver1(Addresses *pAddresses);
////      context(Addresses(), config, db_config, log.logger, exe, lower, cmdHandler, application)
  Addresses aAddresses;
  Addresses_in_AddressesOver1(&aAddresses);
  OContext_in_OContext(&(pOutstationObjectMrzs->context),
///             Addresses* addresses,
                       &aAddresses,
///             OutstationConfig* config,
                       config,
///             DatabaseConfig* db_config,
                       db_config,
//             const Logger& logger,
///             IExecutorExe4cpp* executor,
                       &(pOutstationObjectMrzs->exe.iIExecutorExe4cpp),
///             ILowerLayer* lower,
                       &(pOutstationObjectMrzs->lower_in_OutstationObjectMrzs.iILowerLayer),
///             ICommandHandler* commandHandler,
                       &(pOutstationObjectMrzs->cmdHandler.sSimpleCommandHandler.iICommandHandler),
///             IOutstationApplication* application);
                       &(pOutstationObjectMrzs->application.iIOutstationApplication));


//    void SetUpperLayer_in_HasUpperLayer(HasUpperLayer *pHasUpperLayer, IUpperLayer* upperLayer);
////    lower->SetUpperLayer(context);
  SetUpperLayer_in_HasUpperLayer(&(pOutstationObjectMrzs->lower_in_OutstationObjectMrzs.hHasUpperLayer), &(pOutstationObjectMrzs->context.iIUpperLayer));

#ifdef  LOG_INFO
  std::cout<<"}OutstationObjectMrzs_in_OutstationObjectMrzs_"<<'\n';
#endif
}

////size_t OutstationObjectMrzs::LowerLayerUp()
uint16_t LowerLayerUp_in_OutstationObjectMrzs(OutstationObjectMrzs *pOutstationObjectMrzs)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  std::cout<<"{LowerLayerUp_in_OutstationObjectMrzs1"<<'\n';
#endif
//boolean OnLowerLayerUp_in_OContext(OContext*);
////    context.OnLowerLayerUp();
  OnLowerLayerUp_in_OContext(&(pOutstationObjectMrzs->context));

#ifdef  LOG_INFO
  std::cout<<"}LowerLayerUp_in_OutstationObjectMrzs_"<<'\n';
#endif
////    return exe->run_many();
  return run_many_in_MockExecutor(&(pOutstationObjectMrzs->exe), 100);
}

////size_t OutstationObjectMrzs::LowerLayerDown()
////{
////    context.OnLowerLayerDown();
////    return exe->run_many();
////}
uint16_t LowerLayerDown_in_OutstationObjectMrzs(OutstationObjectMrzs *pOutstationObjectMrzs)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  std::cout<<"{LowerLayerDown_in_OutstationObjectMrzs1"<<'\n';
#endif
//boolean OnLowerLayerDown_in_OContext(OContext*);
////    context.OnLowerLayerDown();
  OnLowerLayerDown_in_OContext(&(pOutstationObjectMrzs->context));

#ifdef  LOG_INFO
  std::cout<<"}LowerLayerDown_in_OutstationObjectMrzs_"<<'\n';
#endif
////    return exe->run_many();
  return run_many_in_MockExecutor(&(pOutstationObjectMrzs->exe), 100);
}

////size_t OutstationObjectMrzs::OnTxReady()
uint16_t OnTxReady_in_OutstationObjectMrzs(OutstationObjectMrzs *pOutstationObjectMrzs)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  std::cout<<"{OnTxReady_in_OutstationObjectMrzs1"<<'\n';
#endif
//boolean OnTxReady_in_OContext(OContext* pOContext)
////    context.OnTxReady();
   OnTxReady_in_OContext(&(pOutstationObjectMrzs->context));
#ifdef  LOG_INFO
  std::cout<<"}OnTxReady_in_OutstationObjectMrzs_"<<'\n';
#endif
////    return exe->run_many();
  return run_many_in_MockExecutor(&(pOutstationObjectMrzs->exe), 100);
}

//Message mMessage1_global_in_OutstationObjectMrzs;
////size_t OutstationObjectMrzs::SendToOutstation(const std::string& hex)
uint16_t SendToOutstation_in_OutstationObjectMrzs(OutstationObjectMrzs *pOutstationObjectMrzs, std::string& hex)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  std::cout<<"{SendToOutstation_in_OutstationObjectMrzs1"<<'\n';
#endif
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

  /*boolean tmp =*/ OnReceive_in_OContext(&(pOutstationObjectMrzs->context), &mMessage);

////    return exe->run_many();
#ifdef  LOG_INFO
  std::cout<<"}SendToOutstation_in_OutstationObjectMrzs_"<<'\n';
#endif
  return run_many_in_MockExecutor(&(pOutstationObjectMrzs->exe), 100);
}

uint16_t SendToOutstation_in_OutstationObjectMrzsOver2(OutstationObjectMrzs *pOutstationObjectMrzs, RSeq_for_Uint16_t *inputAPDU)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  std::cout<<"{SendToOutstation_in_OutstationObjectMrzsOver2_1"<<'\n';
#endif
//   void HexSequence_in_HexSequence(HexSequence *pHexSequence, std::string& hex);
////    HexSequence hs(hex);
/*
  HexSequence hs;
  HexSequence_in_HexSequence(&hs, hex);

//RSeq_for_Uint16_t ToRSeq_in_CopyableBuffer(CopyableBuffer *pCopyableBuffer);
//&(hs.bByteStr.cCopyableBuffer)
//boolean OnReceive_in_OContext(OContext*, Message* message);
//void  Message_in_Message(Message *pMessage, Addresses *addresses, RSeq_for_Uint16_t* payload);
////    context.OnReceive(Message(Addresses(), hs.ToRSeq()));
  RSeq_for_Uint16_t temp = ToRSeq_in_CopyableBuffer(&(hs.bByteStr.cCopyableBuffer));
*/
  Addresses aAddresses;
  Addresses_in_AddressesOver1(&aAddresses);
  Message mMessage;
  Message_in_Message(&mMessage, &aAddresses, inputAPDU);//&temp);

  /*boolean tmp =*/ OnReceive_in_OContext(&(pOutstationObjectMrzs->context), &mMessage);

////    return exe->run_many();
#ifdef  LOG_INFO
  std::cout<<"}SendToOutstation_in_OutstationObjectMrzsOver2__"<<'\n';
#endif
  return run_many_in_MockExecutor(&(pOutstationObjectMrzs->exe), 100);
}

void Transaction_in_OutstationObjectMrzs(OutstationObjectMrzs *pOutstationObjectMrzs, void (*apply)(IUpdateHandler*))//std::function<void(opendnp3::IUpdateHandler&)>& apply)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  std::cout<<"{Transaction_in_OutstationObjectMrzs1"<<'\n';
#endif
  // auto& handler = context.GetUpdateHandler();
//IUpdateHandler* GetUpdateHandler_in_OContext(OContext *pOContext);
////        apply(context.GetUpdateHandler());
  apply(GetUpdateHandler_in_OContext(&(pOutstationObjectMrzs->context)));

//void HandleNewEvents_in_OContext(OContext *pOContext);
////        context.HandleNewEvents();
  HandleNewEvents_in_OContext(&(pOutstationObjectMrzs->context));
#ifdef  LOG_INFO
  std::cout<<"}Transaction_in_OutstationObjectMrzs_"<<'\n';
#endif
}

////size_t OutstationObjectMrzs::BroadcastToOutstation(LinkBroadcastAddress broadcast_address, const std::string& hex)
uint16_t BroadcastToOutstation_in_OutstationObjectMrzs(OutstationObjectMrzs *pOutstationObjectMrzs, LinkBroadcastAddress_uint16_t broadcast_address, std::string& hex)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  std::cout<<"{BroadcastToOutstation_in_OutstationObjectMrzs1"<<'\n';
#endif
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
  /*boolean tmp = */OnReceive_in_OContext(&(pOutstationObjectMrzs->context), &mMessage);

#ifdef  LOG_INFO
  std::cout<<"}BroadcastToOutstation_in_OutstationObjectMrzs_"<<'\n';
#endif
////    return exe->run_many();
  return run_many_in_MockExecutor(&(pOutstationObjectMrzs->exe), 100);
}

////size_t OutstationObjectMrzs::NumPendingTimers() const
////{
////    return exe->num_pending_timers();
////}

////bool OutstationObjectMrzs::AdvanceToNextTimer()
boolean AdvanceToNextTimer_in_OutstationObjectMrzs(OutstationObjectMrzs *pOutstationObjectMrzs)
{
UNUSED(pOutstationObjectMrzs);
////    if (exe->advance_to_next_timer())
////    {
////        return exe->run_many() > 0;
////    }

   return true;//false;
}

uint16_t AdvanceTime_in_OutstationObjectMrzs(OutstationObjectMrzs *pOutstationObjectMrzs, TimeDuration* td)
{
//uint16_t advance_time_in_MockExecutor(MockExecutor *pMockExecutor, uint32_t duration);
////    exe->advance_time(td.value);
  advance_time_in_MockExecutor(&(pOutstationObjectMrzs->exe), td->duration_value);
////    return exe->run_many();
  return run_many_in_MockExecutor(&(pOutstationObjectMrzs->exe), 100);
}

////size_t OutstationObjectMrzs::NumPendingTimers() const
uint16_t NumPendingTimers_in_OutstationObjectMrzs(OutstationObjectMrzs *pOutstationObjectMrzs)
{
//uint16_t num_pending_timers_in_MockExecutor(MockExecutor *pMockExecutor)
////    return exe->num_pending_timers();
  return num_pending_timers_in_MockExecutor(&(pOutstationObjectMrzs->exe));
}
