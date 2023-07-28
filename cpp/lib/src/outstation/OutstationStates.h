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

#ifndef OPENDNP3_OUTSTATIONSTATES_H
#define OPENDNP3_OUTSTATIONSTATES_H

////#include "outstation/ParsedRequest.h"

////#include "opendnp3/util/Uncopyable.h"

#include "ParsedRequest.h"

////namespace opendnp3
////{

////class OContext;

/**
 * Base class for the outstation states
 */
////class OutstationState : private Uncopyable
typedef struct
{
////public:
  boolean (*pIsIdle_in_OutstationState)(void *);
////    virtual bool IsIdle()
////    {
///        return false;
////    }

  char* (*pName_in_OutstationState)(void *);// = 0;

  void* (*pOnConfirm_in_OutstationState)(void*, void* pOContext, ParsedRequest* request);// = 0;

  void* (*pOnConfirmTimeout_in_OutstationState)(void*, void* pOContext);// = 0;

  void* (*pOnNewReadRequest_in_OutstationState)(void*, void* pOContext, ParsedRequest* request);// = 0;

  void* (*pOnNewNonReadRequest_in_OutstationState)(void*, void* pOContext, ParsedRequest* request);// = 0;

  void* (*pOnRepeatNonReadRequest_in_OutstationState)(void*, void* pOContext, ParsedRequest* request);// = 0;

  void* (*pOnRepeatReadRequest_in_OutstationState)(void*, void* pOContext, ParsedRequest* request);// = 0;

  void* (*pOnBroadcastMessage_in_OutstationState)(void*, void* pOContext, ParsedRequest* request);// = 0;

  void* pParentPointer_in_OutstationState;
} OutstationState;

void* getParentPointer_in_OutstationState(OutstationState*);
void  setParentPointer_in_OutstationState(OutstationState*, void*);

boolean IsIdle_in_OutstationState(OutstationState *);
boolean IsIdle_in_OutstationState_override(void *pOutstationState);

char* Name_in_OutstationState(OutstationState *);

OutstationState* OnConfirm_in_OutstationState(OutstationState*, void* pOContext, ParsedRequest* request);
OutstationState* OnConfirmTimeout_in_OutstationState(OutstationState*, void* pOContext);
OutstationState* OnNewReadRequest_in_OutstationState(OutstationState*, void* pOContext, ParsedRequest* request);
OutstationState* OnNewNonReadRequest_in_OutstationState(OutstationState*, void* pOContext, ParsedRequest* request);
OutstationState* OnRepeatNonReadRequest_in_OutstationState(OutstationState*, void* pOContext, ParsedRequest* request);
OutstationState* OnRepeatReadRequest_in_OutstationState(OutstationState*, void* pOContext, ParsedRequest* request);
OutstationState* OnBroadcastMessage_in_OutstationState(OutstationState*, void* pOContext, ParsedRequest* request);


void OutstationState_in_OutstationState(OutstationState *pOutstationState);


////class StateIdle final : public OutstationState
typedef struct
{
  OutstationState oOutstationState;

////public:
////    bool IsIdle() final
////    {
////        return true;
////    }

////    const char* Name() final
////    {
////        return "Idle";
////    }

////    inline static OutstationState& Inst()
////    {
////        return instance;
////    }

////    OutstationState& OnConfirm(OContext&, const ParsedRequest& request) final;

////    OutstationState& OnConfirmTimeout(OContext&) final;

////    OutstationState& OnNewReadRequest(OContext&, const ParsedRequest& request) final;

////    OutstationState& OnNewNonReadRequest(OContext&, const ParsedRequest& request) final;

////    OutstationState& OnRepeatNonReadRequest(OContext&, const ParsedRequest& request) final;

////    OutstationState& OnRepeatReadRequest(OContext&, const ParsedRequest& request) final;

////    OutstationState& OnBroadcastMessage(OContext&, const ParsedRequest& request) final;

////private:
////    static StateIdle instance;

////    StateIdle() {}
} StateIdle;
void StateIdle_in_StateIdle(StateIdle *pStateIdle);

OutstationState* Inst_in_StateIdle_static(void);

boolean IsIdle_in_StateIdle_override(void* pOutstationState);
char* Name_in_StateIdle_override(void* pOutstationState);

void* OnConfirm_in_StateIdle_override(void* pOutstationState, void *pOContext, ParsedRequest* request);
void* OnConfirmTimeout_in_StateIdle_override(void* pOutstationState, void *pOContext);
void* OnNewReadRequest_in_StateIdle_override(void* pOutstationState, void *pOContext, ParsedRequest* request);
void* OnNewNonReadRequest_in_StateIdle_override(void* pOutstationState, void *pOContext, ParsedRequest* request);
void* OnRepeatNonReadRequest_in_StateIdle_override(void* pOutstationState, void *pOContext, ParsedRequest* request);
void* OnRepeatReadRequest_in_StateIdle_override(void* pOutstationState, void *pOContext, ParsedRequest* request);
void* OnBroadcastMessage_in_StateIdle_override(void* pOutstationState, void *pOContext, ParsedRequest* request);

/*
 * waiting for a confirm to a solicited read response
 */
////class StateSolicitedConfirmWait final : public OutstationState
typedef struct
{
  OutstationState oOutstationState;

////public:
////    inline static OutstationState& Inst()
////    {
////        return instance;
////    }
////
////    const char* Name() final
////    {
////        return "SolicitedConfirmWait";
////    }
////
////    OutstationState& OnConfirm(OContext&, const ParsedRequest& request) final;

////    OutstationState& OnConfirmTimeout(OContext&) final;
////
////    OutstationState& OnNewReadRequest(OContext&, const ParsedRequest& request) final;
////
////    OutstationState& OnNewNonReadRequest(OContext&, const ParsedRequest& request) final;
////
////    OutstationState& OnRepeatNonReadRequest(OContext&, const ParsedRequest& request) final;
////
////    OutstationState& OnRepeatReadRequest(OContext&, const ParsedRequest& request) final;
////
////    OutstationState& OnBroadcastMessage(OContext&, const ParsedRequest& request) final;
////
////private:
////    static StateSolicitedConfirmWait instance;

////    StateSolicitedConfirmWait() {}
} StateSolicitedConfirmWait;

void StateSolicitedConfirmWait_in_StateSolicitedConfirmWait(StateSolicitedConfirmWait *pStateSolicitedConfirmWait);

OutstationState* Inst_in_StateSolicitedConfirmWait_static(void);

//    boolean IsIdle_in_StateSolicitedConfirmWait_override(void* pOutstationState);
char* Name_in_StateSolicitedConfirmWait_override(void* pOutstationState);

void* OnConfirm_in_StateSolicitedConfirmWait_override(void* pOutstationState, void *pOContext, ParsedRequest* request);
void* OnConfirmTimeout_in_StateSolicitedConfirmWait_override(void* pOutstationState, void *pOContext);
void* OnNewReadRequest_in_StateSolicitedConfirmWait_override(void* pOutstationState, void *pOContext, ParsedRequest* request);
void* OnNewNonReadRequest_in_StateSolicitedConfirmWait_override(void* pOutstationState, void *pOContext, ParsedRequest* request);
void* OnRepeatNonReadRequest_in_StateSolicitedConfirmWait_override(void* pOutstationState, void *pOContext, ParsedRequest* request);
void* OnRepeatReadRequest_in_StateSolicitedConfirmWait_override(void* pOutstationState, void *pOContext, ParsedRequest* request);
void* OnBroadcastMessage_in_StateSolicitedConfirmWait_override(void* pOutstationState, void *pOContext, ParsedRequest* request);

/*
 * waiting for a confirm to an unsolicited read response
 */
////class StateUnsolicitedConfirmWait : public OutstationState
typedef struct
{
  OutstationState oOutstationState;

////public:
////    inline static OutstationState& Inst()
////    {
////        return instance;
////    }
////
////    virtual const char* Name() override
////    {
////        return "UnsolicitedConfirmWait";
////    }

////    virtual OutstationState& OnConfirm(OContext&, const ParsedRequest& request) override;

////    virtual OutstationState& OnConfirmTimeout(OContext&) override;

////    virtual OutstationState& OnNewReadRequest(OContext&, const ParsedRequest& request) override;

////    virtual OutstationState& OnNewNonReadRequest(OContext&, const ParsedRequest& request) override;

////    virtual OutstationState& OnRepeatNonReadRequest(OContext&, const ParsedRequest& request) override;

////    virtual OutstationState& OnRepeatReadRequest(OContext&, const ParsedRequest& request) override;

////    virtual OutstationState& OnBroadcastMessage(OContext&, const ParsedRequest& request) override;

////protected:
////    static StateUnsolicitedConfirmWait instance;

////    StateUnsolicitedConfirmWait() {}
} StateUnsolicitedConfirmWait;

void StateUnsolicitedConfirmWait_in_StateUnsolicitedConfirmWait(StateUnsolicitedConfirmWait *pStateUnsolicitedConfirmWait);

OutstationState* Inst_in_StateUnsolicitedConfirmWait_static(void);

//    boolean IsIdle_in_StateUnsolicitedConfirmWait_override(void* pOutstationState);
char* Name_in_StateUnsolicitedConfirmWait_override(void* pOutstationState);

void* OnConfirm_in_StateUnsolicitedConfirmWait_override(void* pOutstationState, void *pOContext, ParsedRequest* request);
void* OnConfirmTimeout_in_StateUnsolicitedConfirmWait_override(void* pOutstationState, void *pOContext);
void* OnNewReadRequest_in_StateUnsolicitedConfirmWait_override(void* pOutstationState, void *pOContext, ParsedRequest* request);
void* OnNewNonReadRequest_in_StateUnsolicitedConfirmWait_override(void* pOutstationState, void *pOContext, ParsedRequest* request);
void* OnRepeatNonReadRequest_in_StateUnsolicitedConfirmWait_override(void* pOutstationState, void *pOContext, ParsedRequest* request);
void* OnRepeatReadRequest_in_StateUnsolicitedConfirmWait_override(void* pOutstationState, void *pOContext, ParsedRequest* request);
void* OnBroadcastMessage_in_StateUnsolicitedConfirmWait_override(void* pOutstationState, void *pOContext, ParsedRequest* request);

/*
 * waiting for a confirm for an unsolicited NULL response (only used in the workaround)
 */
////class StateNullUnsolicitedConfirmWait final : public StateUnsolicitedConfirmWait
typedef struct
{
  StateUnsolicitedConfirmWait sStateUnsolicitedConfirmWait;
////public:
////    inline static OutstationState& Inst()
////    {
////        return instance;
////    }
////
////    const char* Name() final
////    {
////        return "NullUnsolicitedConfirmWait";
////    }

////    OutstationState& OnNewReadRequest(OContext&, const ParsedRequest& request) final;

////private:
////    static StateNullUnsolicitedConfirmWait instance;

////    StateNullUnsolicitedConfirmWait() {}
} StateNullUnsolicitedConfirmWait;

void StateNullUnsolicitedConfirmWait_in_StateNullUnsolicitedConfirmWait(StateNullUnsolicitedConfirmWait *pStateNullUnsolicitedConfirmWait);

OutstationState* Inst_in_StateNullUnsolicitedConfirmWait_static(void);

//    boolean IsIdle_in_StateNullUnsolicitedConfirmWait_override(void* pOutstationState);
char* Name_in_StateNullUnsolicitedConfirmWait_override(void* pOutstationState);

void* OnNewReadRequest_in_StateNullUnsolicitedConfirmWait_override(void* pOutstationState, void *pOContext, ParsedRequest* request);

/////} // namespace opendnp3

#endif
