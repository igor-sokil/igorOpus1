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
#ifndef OPENDNP3_SECLINKLAYERSTATES_H
#define OPENDNP3_SECLINKLAYERSTATES_H

#include "LinkContext.h"
////#include "link/Singleton.h"
////#include "logging/LogMacros.h"

////#include "opendnp3/logging/LogLevels.h"

////namespace opendnp3
////{

////class SecStateBase
typedef struct
{
////public:
  // Incoming messages to secondary station

  void* (*pOnResetLinkStates_in_SecStateBase)(void*, LinkContext*, uint16_t source);// = 0;
  void* (*pOnRequestLinkStatus_in_SecStateBase)(void*, LinkContext*, uint16_t source);// = 0;

  void* (*pOnTestLinkStatus_in_SecStateBase)(void*, LinkContext*, uint16_t source, boolean fcb);// = 0;
  void* (*pOnConfirmedUserData_in_SecStateBase)(void*,
      LinkContext*, uint16_t source, boolean fcb, boolean isBroadcast, Message* message);
//        = 0;

  void* (*pOnTxReady_in_SecStateBase)(void*, LinkContext* ctx);

  // every concrete state implements this for logging purposes

////    virtual char const* Name() const = 0;
  void* pParentPointer_in_SecStateBase;
} SecStateBase;

void SecStateBase_in_SecStateBase(SecStateBase *pSecStateBase);

void* OnResetLinkStates_in_SecStateBase_override(void*, LinkContext*, uint16_t source);
void* OnRequestLinkStatus_in_SecStateBase_override(void*, LinkContext*, uint16_t source);

void* OnTestLinkStatus_in_SecStateBase_override(void*, LinkContext*, uint16_t source, boolean fcb);
void* OnConfirmedUserData_in_SecStateBase_override(void*,
    LinkContext*, uint16_t source, boolean fcb, boolean isBroadcast, Message* message);

void* OnTxReady_in_SecStateBase_override(void*, LinkContext* ctx);

SecStateBase* OnResetLinkStates_in_SecStateBase(SecStateBase*, LinkContext*, uint16_t source);
SecStateBase* OnRequestLinkStatus_in_SecStateBase(SecStateBase*, LinkContext*, uint16_t source);

SecStateBase* OnTestLinkStatus_in_SecStateBase(SecStateBase*, LinkContext*, uint16_t source, boolean fcb);
SecStateBase* OnConfirmedUserData_in_SecStateBase(SecStateBase*,
    LinkContext*, uint16_t source, boolean fcb, boolean isBroadcast, Message* message);

SecStateBase* OnTxReady_in_SecStateBase(SecStateBase*, LinkContext* ctx);

void* getParentPointer_in_SecStateBase(SecStateBase*);
void  setParentPointer_in_SecStateBase(SecStateBase*, void*);


////////////////////////////////////////////////////////
//	Class SLLS_TransmitWait
////////////////////////////////////////////////////////
//-----------------------------------SLLS_Reset--------------------------------
////template<class NextState> class SLLS_TransmitWaitBase : public SecStateBase
//typedef struct
//{
//  SecStateBase sSecStateBase;

////protected:
////    SLLS_TransmitWaitBase() {}

////public:
////    virtual SecStateBase& OnTxReady(LinkContext& ctx) override final;
////    virtual SecStateBase& OnResetLinkStates(LinkContext&, uint16_t source) override final;
////    virtual SecStateBase& OnRequestLinkStatus(LinkContext&, uint16_t source) override final;
////    virtual SecStateBase& OnTestLinkStatus(LinkContext&, uint16_t source, bool fcb) override final;
////    virtual SecStateBase& OnConfirmedUserData(
////        LinkContext&, uint16_t source, bool fcb, bool isBroadcast, const Message& message) override final;
//} SLLS_TransmitWaitBase_SLLS_Reset;

void SLLS_Reset_in_SLLS_Reset(SecStateBase *pSecStateBase);
SecStateBase* Instance_in_SLLS_Reset_static(void);

SecStateBase* OnConfirmedUserData_in_SLLS_Reset(SecStateBase *pSecStateBase,
    LinkContext* ctx, uint16_t source, boolean fcb, boolean isBroadcast, Message* message);
SecStateBase* OnTestLinkStatus_in_SLLS_Reset(SecStateBase *pSecStateBase, LinkContext* ctx, uint16_t source, boolean fcb);
SecStateBase* OnRequestLinkStatus_in_SLLS_Reset(SecStateBase *pSecStateBase, LinkContext* ctx, uint16_t source);
SecStateBase* OnResetLinkStates_in_SLLS_Reset(SecStateBase *pSecStateBase, LinkContext* ctx, uint16_t source);
SecStateBase* OnTxReady_in_SLLS_Reset(SecStateBase *pSecStateBase, LinkContext* ctx);

void* OnConfirmedUserData_in_SLLS_Reset_override(void *pSecStateBase,
    LinkContext* ctx, uint16_t source, boolean fcb, boolean isBroadcast, Message* message);
void* OnTestLinkStatus_in_SLLS_Reset_override(void *pSecStateBase, LinkContext* ctx, uint16_t source, boolean fcb);
void* OnRequestLinkStatus_in_SLLS_Reset_override(void *pSecStateBase, LinkContext* ctx, uint16_t source);
void* OnResetLinkStates_in_SLLS_Reset_override(void *pSecStateBase, LinkContext* ctx, uint16_t source);
void* OnTxReady_in_SLLS_Reset_override(void *pSecStateBase, LinkContext* ctx);

//-----------------------------------SLLS_Reset--------------------------------
//-----------------------------------SLLS_NotReset--------------------------------
////template<class NextState> class SLLS_TransmitWaitBase : public SecStateBase
//typedef struct
//{
//  SecStateBase sSecStateBase;

////protected:
////    SLLS_TransmitWaitBase() {}

////public:
////    virtual SecStateBase& OnTxReady(LinkContext& ctx) override final;
////    virtual SecStateBase& OnResetLinkStates(LinkContext&, uint16_t source) override final;
////    virtual SecStateBase& OnRequestLinkStatus(LinkContext&, uint16_t source) override final;
////    virtual SecStateBase& OnTestLinkStatus(LinkContext&, uint16_t source, bool fcb) override final;
////    virtual SecStateBase& OnConfirmedUserData(
////        LinkContext&, uint16_t source, bool fcb, bool isBroadcast, const Message& message) override final;
//} SLLS_TransmitWaitBase_SLLS_NotReset;

void SLLS_NotReset_in_SLLS_NotReset(SecStateBase *pSecStateBase);
SecStateBase* Instance_in_SLLS_NotReset_static(void);

SecStateBase* OnConfirmedUserData_in_SLLS_NotReset(SecStateBase *pSecStateBase,
    LinkContext* ctx, uint16_t source, boolean fcb, boolean isBroadcast, Message* message);
SecStateBase* OnTestLinkStatus_in_SLLS_NotReset(SecStateBase *pSecStateBase, LinkContext* ctx, uint16_t source, boolean fcb);
SecStateBase* OnRequestLinkStatus_in_SLLS_NotReset(SecStateBase *pSecStateBase, LinkContext* ctx, uint16_t source);
SecStateBase* OnResetLinkStates_in_SLLS_NotReset(SecStateBase *pSecStateBase, LinkContext* ctx, uint16_t source);
SecStateBase* OnTxReady_in_SLLS_NotReset(SecStateBase *pSecStateBase, LinkContext* ctx);

void* OnConfirmedUserData_in_SLLS_NotReset_override(void *pSecStateBase,
    LinkContext* ctx, uint16_t source, boolean fcb, boolean isBroadcast, Message* message);
void* OnTestLinkStatus_in_SLLS_NotReset_override(void *pSecStateBase, LinkContext* ctx, uint16_t source, boolean fcb);
void* OnRequestLinkStatus_in_SLLS_NotReset_override(void *pSecStateBase, LinkContext* ctx, uint16_t source);
void* OnResetLinkStates_in_SLLS_NotReset_override(void *pSecStateBase, LinkContext* ctx, uint16_t source);
void* OnTxReady_in_SLLS_NotReset_override(void *pSecStateBase, LinkContext* ctx);

//-----------------------------------SLLS_NotReset--------------------------------

////////////////////////////////////////////////////////
//	Class SLLS_UnReset
////////////////////////////////////////////////////////
////class SLLS_NotReset final : public SecStateBase
////{
////public:
////    MACRO_STATE_SINGLETON_INSTANCE(SLLS_NotReset);

////    virtual SecStateBase& OnConfirmedUserData(
////        LinkContext&, uint16_t source, bool fcb, bool isBroadcast, const Message& message) override;
////    virtual SecStateBase& OnResetLinkStates(LinkContext&, uint16_t source) override;
////    virtual SecStateBase& OnRequestLinkStatus(LinkContext&, uint16_t source) override;
////    virtual SecStateBase& OnTestLinkStatus(LinkContext&, uint16_t source, bool fcb) override;
////};

////////////////////////////////////////////////////////
//	Class SLLS_Reset
////////////////////////////////////////////////////////
////class SLLS_Reset final : public SecStateBase
////{
////    MACRO_STATE_SINGLETON_INSTANCE(SLLS_Reset);
////
////    virtual SecStateBase& OnConfirmedUserData(
////        LinkContext&, uint16_t source, bool fcb, bool isBroadcast, const Message& message) override;
////    virtual SecStateBase& OnResetLinkStates(LinkContext&, uint16_t source) override;
////    virtual SecStateBase& OnRequestLinkStatus(LinkContext&, uint16_t source) override;
////    virtual SecStateBase& OnTestLinkStatus(LinkContext&, uint16_t source, bool fcb) override;
////};

////class SLLS_TransmitWaitReset : public SLLS_TransmitWaitBase<SLLS_Reset>
////{
////    MACRO_STATE_SINGLETON_INSTANCE(SLLS_TransmitWaitReset);
////};

////class SLLS_TransmitWaitNotReset : public SLLS_TransmitWaitBase<SLLS_NotReset>
////{
////    MACRO_STATE_SINGLETON_INSTANCE(SLLS_TransmitWaitNotReset);
////};

////} // namespace opendnp3

#endif
