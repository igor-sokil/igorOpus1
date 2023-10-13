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
#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "SecLinkLayerStates.h"

#include "LinkLayer.h"
///#include "logging/LogMacros.h"

////#include "opendnp3/logging/LogLevels.h"

////namespace opendnp3
////{

////////////////////////////////////////
// SecStateBase
////////////////////////////////////////

static SecStateBase  instance_SecStateBase;

void SecStateBase_in_SecStateBase(SecStateBase *pSecStateBase)
{
  pSecStateBase->pOnResetLinkStates_in_SecStateBase = OnResetLinkStates_in_SecStateBase_override;
  pSecStateBase->pOnRequestLinkStatus_in_SecStateBase = OnRequestLinkStatus_in_SecStateBase_override;

  pSecStateBase->pOnTestLinkStatus_in_SecStateBase    = OnTestLinkStatus_in_SecStateBase_override;
  pSecStateBase->pOnConfirmedUserData_in_SecStateBase = OnConfirmedUserData_in_SecStateBase_override;

  pSecStateBase->pOnTxReady_in_SecStateBase           = OnTxReady_in_SecStateBase_override;

  setParentPointer_in_SecStateBase(pSecStateBase, pSecStateBase);
}

void* OnTxReady_in_SecStateBase_override(void *pSecStateBase, LinkContext* ctx)
{
  UNUSED(ctx);
////    FORMAT_LOG_BLOCK(ctx.logger, flags::ERR, "Invalid event for state: %s", this->Name());
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"FORMAT_LOG_BLOCK(ctx.logger, flags::ERR, 'Invalid event for state: %s', this->Name())"<<'\n';
  decrement_stack_info();
#endif
////    return *this;
  SecStateBase* parent = (SecStateBase*) getParentPointer_in_SecStateBase((SecStateBase*) pSecStateBase);
  SecStateBase_in_SecStateBase(parent);
  return &instance_SecStateBase;
}

///*
////template<class NextState>
void* OnResetLinkStates_in_SecStateBase_override(void *pSecStateBase, LinkContext* ctx, uint16_t source)
{
  UNUSED(ctx);
  UNUSED(source);
////    SIMPLE_LOG_BLOCK(ctx.logger, flags::WARN, "Ignoring link frame, remote is flooding");
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<getString_stack_info();
   std::cout<<"SIMPLE_LOG_BLOCK(ctx.logger, flags::WARN, 'Ignoring link frame, remote is flooding')"<<'\n';
  decrement_stack_info();
#endif
////    return *this;
  SecStateBase* parent = (SecStateBase*) getParentPointer_in_SecStateBase((SecStateBase*) pSecStateBase);
  SecStateBase_in_SecStateBase(parent);
  return &instance_SecStateBase;
}
//*/
///*
////template<class NextState>
void* OnRequestLinkStatus_in_SecStateBase_override(void *pSecStateBase, LinkContext* ctx, uint16_t source)
{
  UNUSED(ctx);
  UNUSED(source);
////    SIMPLE_LOG_BLOCK(ctx.logger, flags::WARN, "Ignoring link frame, remote is flooding");
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<getString_stack_info();
   std::cout<<"SIMPLE_LOG_BLOCK(ctx.logger, flags::WARN, 'Ignoring link frame, remote is flooding')"<<'\n';
  decrement_stack_info();
#endif
////    return *this;
  SecStateBase* parent = (SecStateBase*) getParentPointer_in_SecStateBase((SecStateBase*) pSecStateBase);
  SecStateBase_in_SecStateBase(parent);
  return &instance_SecStateBase;
}
//*/
///*
////template<class NextState>
void* OnTestLinkStatus_in_SecStateBase_override(void *pSecStateBase, LinkContext* ctx, uint16_t source, boolean fcb)
{
  UNUSED(ctx);
  UNUSED(source);
  UNUSED(fcb);
////    SIMPLE_LOG_BLOCK(ctx.logger, flags::WARN, "Ignoring link frame, remote is flooding");
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<getString_stack_info();
   std::cout<<"SIMPLE_LOG_BLOCK(ctx.logger, flags::WARN, 'Ignoring link frame, remote is flooding')"<<'\n';
  decrement_stack_info();
#endif
////    return *this;
  SecStateBase* parent = (SecStateBase*) getParentPointer_in_SecStateBase((SecStateBase*) pSecStateBase);
  SecStateBase_in_SecStateBase(parent);
  return &instance_SecStateBase;
}
//*/
///*
////template<class NextState>
void* OnConfirmedUserData_in_SecStateBase_override(void *pSecStateBase,
    LinkContext* ctx, uint16_t source, boolean fcb, boolean isBroadcast, Message* message)
{
  UNUSED(ctx);
  UNUSED(source);
  UNUSED(fcb);
  UNUSED(isBroadcast);
  UNUSED(message);
////    SIMPLE_LOG_BLOCK(ctx.logger, flags::WARN, "Ignoring link frame, remote is flooding");
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<getString_stack_info();
   std::cout<<"SIMPLE_LOG_BLOCK(ctx.logger, flags::WARN, 'Ignoring link frame, remote is flooding')"<<'\n';
  decrement_stack_info();
#endif
////    return *this;
  SecStateBase* parent = (SecStateBase*) getParentPointer_in_SecStateBase((SecStateBase*) pSecStateBase);
  SecStateBase_in_SecStateBase(parent);
  return &instance_SecStateBase;
}
//*/

////////////////////////////////////////////////////////
//	Class SLLS_NotReset
////////////////////////////////////////////////////////
////SLLS_NotReset SLLS_NotReset::instance;

SecStateBase* Instance_in_SLLS_NotReset_static(void)
{
  SLLS_NotReset_in_SLLS_NotReset(&instance_SecStateBase);
  return &instance_SecStateBase;
}

SecStateBase* OnTestLinkStatus_in_SLLS_NotReset(SecStateBase *pSecStateBase, LinkContext* ctx, uint16_t source, boolean fcb)
{
  UNUSED(source);
  UNUSED(fcb);
  ++(ctx->statistics.numUnexpectedFrame);
////    SIMPLE_LOG_BLOCK(ctx.logger, flags::WARN, "TestLinkStatus ignored");
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<getString_stack_info();
   std::cout<<"SIMPLE_LOG_BLOCK(ctx.logger, flags::WARN, 'TestLinkStatus ignored')"<<'\n';
  decrement_stack_info();
#endif
////    return *this;
  SLLS_NotReset_in_SLLS_NotReset(pSecStateBase);
  return &instance_SecStateBase;
}

SecStateBase* OnConfirmedUserData_in_SLLS_NotReset(SecStateBase *pSecStateBase,
    LinkContext* ctx, uint16_t source, boolean fcb, boolean isBroadcast, Message* message)
{
  UNUSED(source);
  UNUSED(fcb);
  UNUSED(isBroadcast);
  UNUSED(message);
  ++(ctx->statistics.numUnexpectedFrame);
////    SIMPLE_LOG_BLOCK(ctx.logger, flags::WARN, "ConfirmedUserData ignored: secondary not reset");
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<getString_stack_info();
   std::cout<<"SIMPLE_LOG_BLOCK(ctx.logger, flags::WARN, 'ConfirmedUserData ignored: secondary not reset')"<<'\n';
  decrement_stack_info();
#endif
////    return *this;
  SLLS_NotReset_in_SLLS_NotReset(pSecStateBase);
  return &instance_SecStateBase;
}

SecStateBase* OnResetLinkStates_in_SLLS_NotReset(SecStateBase *pSecStateBase, LinkContext* ctx, uint16_t source)
{
//    void QueueAck(uint16_t destination);
////    ctx.QueueAck(source);
  QueueAck_in_LinkContext(ctx, source);
//    void ResetReadFCB()
////    ctx.ResetReadFCB();
  ResetReadFCB_in_LinkContext(ctx);
////    return SLLS_TransmitWaitReset::Instance();
//   SLLS_TransmitWaitReset_in_SLLS_TransmitWaitReset(pSecStateBase);
  SLLS_Reset_in_SLLS_Reset(pSecStateBase);
  return &instance_SecStateBase;
}

SecStateBase* OnRequestLinkStatus_in_SLLS_NotReset(SecStateBase *pSecStateBase, LinkContext* ctx, uint16_t source)
{
//    void QueueLinkStatus(uint16_t destination);
////    ctx.QueueLinkStatus(source);
  QueueLinkStatus_in_LinkContext(ctx, source);
////    return SLLS_TransmitWaitNotReset::Instance();
//   SLLS_TransmitWaitNotReset_in_SLLS_TransmitWaitNotReset(pSecStateBase);
  SLLS_NotReset_in_SLLS_NotReset(pSecStateBase);
  return &instance_SecStateBase;
}

////////////////////////////////////////////////////////
//	Class SLLS_Reset
////////////////////////////////////////////////////////
////SLLS_Reset SLLS_Reset::instance;

SecStateBase* Instance_in_SLLS_Reset_static(void)
{
  SLLS_Reset_in_SLLS_Reset(&instance_SecStateBase);
  return &instance_SecStateBase;
}

SecStateBase* OnTestLinkStatus_in_SLLS_Reset(SecStateBase *pSecStateBase, LinkContext* ctx, uint16_t source, boolean fcb)
{
  if (ctx->nextReadFCB == fcb)
  {
////        ctx.QueueAck(source);
    QueueAck_in_LinkContext(ctx, source);
//    void ToggleReadFCB()
////        ctx.ToggleReadFCB();
    ToggleReadFCB_in_LinkContext(ctx);
////        return SLLS_TransmitWaitReset::Instance();
    SLLS_Reset_in_SLLS_Reset(pSecStateBase);
    return &instance_SecStateBase;
  }

  // "Re-transmit most recent response that contained function code 0 (ACK) or 1 (NACK)."
  // This is a PITA implement
  // TODO - see if this function is deprecated or not
////    SIMPLE_LOG_BLOCK(ctx.logger, flags::WARN, "Received TestLinkStatus with invalid FCB");
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<getString_stack_info();
   std::cout<<"SIMPLE_LOG_BLOCK(ctx.logger, flags::WARN, 'Received TestLinkStatus with invalid FCB')"<<'\n';
  decrement_stack_info();
#endif
////    return *this;
  SLLS_Reset_in_SLLS_Reset(pSecStateBase);
  return &instance_SecStateBase;
}

SecStateBase* OnConfirmedUserData_in_SLLS_Reset(SecStateBase *pSecStateBase,
    LinkContext* ctx, uint16_t source, boolean fcb, boolean isBroadcast, Message* message)
{
  if (!isBroadcast)
  {
////        ctx.QueueAck(source);
    QueueAck_in_LinkContext(ctx, source);
  }

  if (ctx->nextReadFCB == fcb)
  {
////        ctx.ToggleReadFCB();
    ToggleReadFCB_in_LinkContext(ctx);
//    void PushDataUp(const Message& message);
////        ctx.PushDataUp(message);
    PushDataUp_in_LinkContext(ctx, message);
  }
  else
  {
////        SIMPLE_LOG_BLOCK(ctx.logger, flags::WARN, "ConfirmedUserData ignored: unexpected frame count bit (FCB)");
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<getString_stack_info();
    std::cout<<"SIMPLE_LOG_BLOCK(ctx.logger, flags::WARN, 'ConfirmedUserData ignored: unexpected frame count bit (FCB)')"<<'\n';
  decrement_stack_info();
#endif
  }

////    return SLLS_TransmitWaitReset::Instance();
  SLLS_Reset_in_SLLS_Reset(pSecStateBase);
  return &instance_SecStateBase;
}

SecStateBase* OnResetLinkStates_in_SLLS_Reset(SecStateBase *pSecStateBase, LinkContext* ctx, uint16_t source)
{
////    ctx.QueueAck(source);
  QueueAck_in_LinkContext(ctx, source);
//    void ResetReadFCB()
////    ctx.ResetReadFCB();
  ResetReadFCB_in_LinkContext(ctx);
////    return SLLS_TransmitWaitReset::Instance();
  SLLS_Reset_in_SLLS_Reset(pSecStateBase);
  return &instance_SecStateBase;
}

SecStateBase* OnRequestLinkStatus_in_SLLS_Reset(SecStateBase *pSecStateBase, LinkContext* ctx, uint16_t source)
{
//    void QueueLinkStatus(uint16_t destination);
////    ctx.QueueLinkStatus(source);
  QueueLinkStatus_in_LinkContext(ctx, source);
////    return SLLS_TransmitWaitReset::Instance();
  SLLS_Reset_in_SLLS_Reset(pSecStateBase);
  return &instance_SecStateBase;
}

////////////////////////////////////////////////////////
//	Class SLLS_TransmitWaitReset
////////////////////////////////////////////////////////
////SLLS_TransmitWaitReset SLLS_TransmitWaitReset::instance;

////////////////////////////////////////////////////////
//	Class SLLS_TransmitWaitNotReset
////////////////////////////////////////////////////////
////SLLS_TransmitWaitNotReset SLLS_TransmitWaitNotReset::instance;

////} // namespace opendnp3
//-----------------------------------SLLS_Reset--------------------------------

void SLLS_Reset_in_SLLS_Reset(SecStateBase *pSecStateBase)
{
  SecStateBase_in_SecStateBase(pSecStateBase);

  pSecStateBase->pOnConfirmedUserData_in_SecStateBase = OnConfirmedUserData_in_SLLS_Reset_override;
  pSecStateBase->pOnTestLinkStatus_in_SecStateBase    = OnTestLinkStatus_in_SLLS_Reset_override;
  pSecStateBase->pOnRequestLinkStatus_in_SecStateBase = OnRequestLinkStatus_in_SLLS_Reset_override;
  pSecStateBase->pOnResetLinkStates_in_SecStateBase   = OnResetLinkStates_in_SLLS_Reset_override;
  pSecStateBase->pOnTxReady_in_SecStateBase           = OnTxReady_in_SLLS_Reset_override;

  setParentPointer_in_SecStateBase(pSecStateBase, pSecStateBase);
}

////template<class NextState>
SecStateBase* OnTxReady_in_SLLS_Reset(SecStateBase *pSecStateBase, LinkContext* ctx)
{
  UNUSED(ctx);
  SLLS_Reset_in_SLLS_Reset(pSecStateBase);
  return &instance_SecStateBase;////SLLS_Reset::Instance();
}

/*
////template<class NextState>
SecStateBase* OnResetLinkStates_in_SLLS_Reset(SecStateBase *pSecStateBase, LinkContext* ctx, uint16_t source)
{
////    SIMPLE_LOG_BLOCK(ctx.logger, flags::WARN, "Ignoring link frame, remote is flooding");
////    return *this;
  SLLS_Reset_in_SLLS_Reset(pSecStateBase);
  return &instance_SecStateBase;
}
*/
/*
////template<class NextState>
SecStateBase* OnRequestLinkStatus_in_SLLS_Reset(SecStateBase *pSecStateBase, LinkContext* ctx, uint16_t source)
{
////    SIMPLE_LOG_BLOCK(ctx.logger, flags::WARN, "Ignoring link frame, remote is flooding");
////    return *this;
  SLLS_Reset_in_SLLS_Reset(pSecStateBase);
  return &instance_SecStateBase;
}
*/
/*
////template<class NextState>
SecStateBase* OnTestLinkStatus_in_SLLS_Reset(SecStateBase *pSecStateBase, LinkContext* ctx, uint16_t source, boolean fcb)
{
////    SIMPLE_LOG_BLOCK(ctx.logger, flags::WARN, "Ignoring link frame, remote is flooding");
////    return *this;
  SLLS_Reset_in_SLLS_Reset(pSecStateBase);
  return &instance_SecStateBase;
}
*/
/*
////template<class NextState>
SecStateBase* OnConfirmedUserData_in_SLLS_Reset(SecStateBase *pSecStateBase,
    LinkContext* ctx, uint16_t source, boolean fcb, boolean isBroadcast, Message* message)
{
////    SIMPLE_LOG_BLOCK(ctx.logger, flags::WARN, "Ignoring link frame, remote is flooding");
////    return *this;
  SLLS_Reset_in_SLLS_Reset(pSecStateBase);
  return &instance_SecStateBase;
}
*/

void* OnTxReady_in_SLLS_Reset_override(void *pSecStateBase, LinkContext* ctx)
{
  SecStateBase* parent = (SecStateBase*) getParentPointer_in_SecStateBase((SecStateBase*) pSecStateBase);
  return OnTxReady_in_SLLS_Reset(parent, ctx);
}

////template<class NextState>
void* OnResetLinkStates_in_SLLS_Reset_override(void *pSecStateBase, LinkContext* ctx, uint16_t source)
{
  SecStateBase* parent = (SecStateBase*) getParentPointer_in_SecStateBase((SecStateBase*) pSecStateBase);
  return OnResetLinkStates_in_SLLS_Reset(parent, ctx, source);
}

////template<class NextState>
void* OnRequestLinkStatus_in_SLLS_Reset_override(void *pSecStateBase, LinkContext* ctx, uint16_t source)
{
  SecStateBase* parent = (SecStateBase*) getParentPointer_in_SecStateBase((SecStateBase*) pSecStateBase);
  return OnRequestLinkStatus_in_SLLS_Reset(parent, ctx, source);
}

////template<class NextState>
void* OnTestLinkStatus_in_SLLS_Reset_override(void *pSecStateBase, LinkContext* ctx, uint16_t source, boolean fcb)
{
  SecStateBase* parent = (SecStateBase*) getParentPointer_in_SecStateBase((SecStateBase*) pSecStateBase);
  return OnTestLinkStatus_in_SLLS_Reset(parent, ctx, source, fcb);
}

////template<class NextState>
void* OnConfirmedUserData_in_SLLS_Reset_override(void *pSecStateBase,
    LinkContext* ctx, uint16_t source, boolean fcb, boolean isBroadcast, Message* message)
{
  SecStateBase* parent = (SecStateBase*) getParentPointer_in_SecStateBase((SecStateBase*) pSecStateBase);
  return OnConfirmedUserData_in_SLLS_Reset(parent, ctx, source, fcb, isBroadcast, message);
}
//-----------------------------------SLLS_Reset--------------------------------
//-----------------------------------SLLS_NotReset--------------------------------

void SLLS_NotReset_in_SLLS_NotReset(SecStateBase *pSecStateBase)
{
  SecStateBase_in_SecStateBase(pSecStateBase);

  pSecStateBase->pOnConfirmedUserData_in_SecStateBase = OnConfirmedUserData_in_SLLS_NotReset_override;
  pSecStateBase->pOnTestLinkStatus_in_SecStateBase    = OnTestLinkStatus_in_SLLS_NotReset_override;
  pSecStateBase->pOnRequestLinkStatus_in_SecStateBase = OnRequestLinkStatus_in_SLLS_NotReset_override;
  pSecStateBase->pOnResetLinkStates_in_SecStateBase   = OnResetLinkStates_in_SLLS_NotReset_override;
  pSecStateBase->pOnTxReady_in_SecStateBase           = OnTxReady_in_SLLS_NotReset_override;

  setParentPointer_in_SecStateBase(pSecStateBase, pSecStateBase);
}

////template<class NextState>
SecStateBase* OnTxReady_in_SLLS_NotReset(SecStateBase *pSecStateBase, LinkContext* ctx)
{
  UNUSED(ctx);
  SLLS_NotReset_in_SLLS_NotReset(pSecStateBase);
  return &instance_SecStateBase;////SLLS_NotReset::Instance();
}

void* OnTxReady_in_SLLS_NotReset_override(void *pSecStateBase, LinkContext* ctx)
{
  SecStateBase* parent = (SecStateBase*) getParentPointer_in_SecStateBase((SecStateBase*) pSecStateBase);
  return OnTxReady_in_SLLS_NotReset(parent, ctx);
}

////template<class NextState>
void* OnResetLinkStates_in_SLLS_NotReset_override(void *pSecStateBase, LinkContext* ctx, uint16_t source)
{
  SecStateBase* parent = (SecStateBase*) getParentPointer_in_SecStateBase((SecStateBase*) pSecStateBase);
  return OnResetLinkStates_in_SLLS_NotReset(parent, ctx, source);
}

////template<class NextState>
void* OnRequestLinkStatus_in_SLLS_NotReset_override(void *pSecStateBase, LinkContext* ctx, uint16_t source)
{
  SecStateBase* parent = (SecStateBase*) getParentPointer_in_SecStateBase((SecStateBase*) pSecStateBase);
  return OnRequestLinkStatus_in_SLLS_NotReset(parent, ctx, source);
}

////template<class NextState>
void* OnTestLinkStatus_in_SLLS_NotReset_override(void *pSecStateBase, LinkContext* ctx, uint16_t source, boolean fcb)
{
  SecStateBase* parent = (SecStateBase*) getParentPointer_in_SecStateBase((SecStateBase*) pSecStateBase);
  return OnTestLinkStatus_in_SLLS_NotReset(parent, ctx, source, fcb);
}

////template<class NextState>
void* OnConfirmedUserData_in_SLLS_NotReset_override(void *pSecStateBase,
    LinkContext* ctx, uint16_t source, boolean fcb, boolean isBroadcast, Message* message)
{
  SecStateBase* parent = (SecStateBase*) getParentPointer_in_SecStateBase((SecStateBase*) pSecStateBase);
  return OnConfirmedUserData_in_SLLS_NotReset(parent, ctx, source, fcb, isBroadcast, message);
}
//-----------------------------------SLLS_NotReset--------------------------------

SecStateBase* OnResetLinkStates_in_SecStateBase(SecStateBase* pSecStateBase, LinkContext* pLinkContext, uint16_t source)
{
  return (SecStateBase*)(pSecStateBase->pOnResetLinkStates_in_SecStateBase)(pSecStateBase, pLinkContext, source);
}
SecStateBase* OnRequestLinkStatus_in_SecStateBase(SecStateBase* pSecStateBase, LinkContext* pLinkContext, uint16_t source)
{
  return (SecStateBase*)(pSecStateBase->pOnRequestLinkStatus_in_SecStateBase)(pSecStateBase,
         pLinkContext, source);
}

SecStateBase* OnTestLinkStatus_in_SecStateBase(SecStateBase* pSecStateBase, LinkContext* pLinkContext, uint16_t source, boolean fcb)
{
  return (SecStateBase*)(pSecStateBase->pOnTestLinkStatus_in_SecStateBase)(pSecStateBase,
         pLinkContext, source, fcb);
}
SecStateBase* OnConfirmedUserData_in_SecStateBase(SecStateBase* pSecStateBase,
    LinkContext* pLinkContext, uint16_t source, boolean fcb, boolean isBroadcast, Message* message)
{
  return (SecStateBase*)(pSecStateBase->pOnConfirmedUserData_in_SecStateBase)(pSecStateBase,
         pLinkContext, source, fcb, isBroadcast, message);
}

SecStateBase* OnTxReady_in_SecStateBase(SecStateBase* pSecStateBase, LinkContext* ctx)
{
  return (SecStateBase*)(pSecStateBase->pOnTxReady_in_SecStateBase)(pSecStateBase, ctx);
}

void* getParentPointer_in_SecStateBase(SecStateBase* pSecStateBase)
{
  return pSecStateBase->pParentPointer_in_SecStateBase;
}
void  setParentPointer_in_SecStateBase(SecStateBase* pSecStateBase, void* pParentPointer)
{
  pSecStateBase->pParentPointer_in_SecStateBase = pParentPointer;
}
