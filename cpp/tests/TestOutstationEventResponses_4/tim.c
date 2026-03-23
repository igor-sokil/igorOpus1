
void timeout_RestartUnsolConfirmTimer_in_OContext(void)
{
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{timeout_RestartUnsolConfirmTimer_in_OContext1"<<std::endl;
#endif
////    auto timeout = [&]() {
////        this->state = &this->state->OnConfirmTimeout(*this);
////        this->CheckForTaskStart();
////    };
 OContext* pOContext = (OContext*)pPointerGlobal1;
 OutstationState* parent = (OutstationState*)getParentPointer_in_OutstationState(pOContext->state_in_OContext);
 pOContext->state_in_OContext = (OutstationState*) OnConfirmTimeout_in_OutstationState((OutstationState*) parent, ((OContext*)pPointerGlobal1));
 CheckForTaskStart_in_OContext(pOContext);
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}timeout_RestartUnsolConfirmTimer_in_OContext_"<<std::endl;
  decrement_stack_info();
#endif
}

void timeout_RestartSolConfirmTimer_in_OContext(void)
{
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{timeout_RestartSolConfirmTimer_in_OContext1"<<std::endl;
#endif
////    auto timeout = [&]() {
////        this->state = &this->state->OnConfirmTimeout(*this);
////        this->CheckForTaskStart();
////    };
 OContext* pOContext = (OContext*)pPointerGlobal1;
 OutstationState* parent = (OutstationState*)getParentPointer_in_OutstationState(pOContext->state_in_OContext);
 pOContext->state_in_OContext = (OutstationState*) OnConfirmTimeout_in_OutstationState((OutstationState*) parent, pOContext);
 CheckForTaskStart_in_OContext(pOContext);
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}timeout_RestartSolConfirmTimer_in_OContext_"<<std::endl;
  decrement_stack_info();
#endif
}

////bool OContext::ProcessDeferredRequest(const ParsedRequest& request)
boolean ProcessDeferredRequest_in_OContext(OContext *pOContext, ParsedRequest* request)
{
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{ProcessDeferredRequest_in_OContext1"<<std::endl;
#endif
  if (request->header.function == FunctionCode_CONFIRM)
  {
#ifdef  LOG_INFO
    std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*FunctionCode_CONFIRM"<<std::endl;
#endif
//    boolean ProcessConfirm_in_OContext(OContext *pOContext, ParsedRequest* request)
////        this->ProcessConfirm(request);
    ProcessConfirm_in_OContext(pOContext, request);

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}ProcessDeferredRequest_in_OContext1_"<<std::endl;
  decrement_stack_info();
#endif
    return true;
  }

  if (request->header.function == FunctionCode_READ)
  {
#ifdef  LOG_INFO
    std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*FunctionCode_READ"<<std::endl;
#endif
//     boolean IsIdle_in_OutstationState(OutstationState *);
////        if (this->state->IsIdle())
    if (IsIdle_in_OutstationState(pOContext->state_in_OContext))
    {
//    boolean ProcessRequest_in_OContext(OContext *pOContext, ParsedRequest* request)
////            this->ProcessRequest(request);
      ProcessRequest_in_OContext(pOContext, request);

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}ProcessDeferredRequest_in_OContext2_"<<std::endl;
  decrement_stack_info();
#endif
      return true;
    }

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}ProcessDeferredRequest_in_OContext3_"<<std::endl;
  decrement_stack_info();
#endif
    return false;
  }
  else
  {
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}ProcessDeferredRequest_in_OContext4_"<<std::endl;
  decrement_stack_info();
#endif
////        this->ProcessRequest(request);
    ProcessRequest_in_OContext(pOContext, request);
    return true;
  }
}

////bool OContext::ProcessConfirm(const ParsedRequest& request)
boolean ProcessConfirm_in_OContext(OContext *pOContext, ParsedRequest* request)
{
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{ProcessConfirm_in_OContext1"<<std::endl;
#endif
//    OutstationState* OnConfirm_in_OutstationState(OutstationState*, void* pOContext, ParsedRequest* request);
////    this->state = &this->state->OnConfirm(*this, request);
  pOContext->state_in_OContext = OnConfirm_in_OutstationState(pOContext->state_in_OContext, pOContext, request);
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}ProcessConfirm_in_OContext_"<<std::endl;
  decrement_stack_info();
#endif
  return true;
}

////OutstationState& StateSolicitedConfirmWait::OnConfirm(OContext& ctx, const ParsedRequest& request)
void* OnConfirm_in_StateSolicitedConfirmWait_override(void* pOutstationState, void *ctx, ParsedRequest* request)
{
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{OnConfirm_in_StateSolicitedConfirmWait_override1"<<std::endl;
#endif
  StateSolicitedConfirmWait *parent =
    (StateSolicitedConfirmWait*)getParentPointer_in_OutstationState((OutstationState*)pOutstationState);

////    if (request.header.control.UNS)
  if ((request->header).control.UNS)
  {
////        FORMAT_LOG_BLOCK(ctx.logger, flags::WARN,
////                         "received unsolicited confirm while waiting for solicited confirm (seq: %u)",
////                         request.header.control.SEQ);
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*FORMAT_LOG_BLOCK(ctx.logger, flags::WARN,'received unsolicited confirm while waiting for solicited confirm (seq: %u)',"<<std::endl;
  std::cout<<getString_stack_info();
  std::cout<<"}OnConfirm_in_StateSolicitedConfirmWait_override1_"<<std::endl;
  decrement_stack_info();
#endif
////        return *this;
    return &(parent->oOutstationState);
  }

//boolean Equals_in_SequenceNum_for_uint8_Modulus16(SequenceNum_for_uint8_Modulus16 *pSequenceNum_for_uint8_Modulus16, uint8_t other);
////    if (!((OContext*)ctx)->sol.seq.confirmNum.Equals(request.header.control.SEQ))
  if (!Equals_in_SequenceNum_for_uint8_Modulus16(&(((OContext*)ctx)->sol_in_OContext.seq.confirmNum), (request->header).control.SEQ))
  {
////        FORMAT_LOG_BLOCK(ctx.logger, flags::WARN, "solicited confirm with wrong seq: %u, expected: %u",
////                         request.header.control.SEQ, ctx.sol.seq.confirmNum.Get());
////        return *this;
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*FORMAT_LOG_BLOCK(ctx.logger, flags::WARN, 'solicited confirm with wrong seq: %u, expected: %u'"<<std::endl;
  std::cout<<getString_stack_info();
  std::cout<<"}OnConfirm_in_StateSolicitedConfirmWait_override2_"<<std::endl;
  decrement_stack_info();
#endif
    return &(parent->oOutstationState);
  }

//   void Reset_in_RequestHistory(RequestHistory *pRequestHistory);
////    ctx.history.Reset(); // any time we get a confirm we can treat any request as a new request
  Reset_in_RequestHistory(&(((OContext*)ctx)->history_in_OContext));
//boolean cancel_in_TimerExe4cpp(TimerExe4cpp *pTimerExe4cpp);
////    ctx.confirmTimer.cancel();
  cancel_in_TimerExe4cpp(&(((OContext*)ctx)->confirmTimer_in_OContext));
////    ctx.eventBuffer.ClearWritten();
  ClearWritten_in_EventBuffer(&(((OContext*)ctx)->eventBuffer_in_OContext)); // called when a transmission succeeds
////    ctx.lastBroadcastMessageReceived.clear();
  clear_in_Settable_for_LinkBroadcastAddress(&(((OContext*)ctx)->lastBroadcastMessageReceived_in_OContext));

  // information the application about the confirm
//    void OnConfirmProcessed_in_IOutstationApplication(IOutstationApplication*, boolean is_unsolicited, uint32_t num_class1, uint32_t num_class2, uint32_t num_class3);
//    uint32_t NumEvents_in_EventBuffer(EventBuffer *pEventBuffer, EventClass_uint8_t ec);
////    ctx.application->OnConfirmProcessed(
////        false,
////        ctx.eventBuffer.NumEvents(EventClass::EC1),
////        ctx.eventBuffer.NumEvents(EventClass::EC2),
////        ctx.eventBuffer.NumEvents(EventClass::EC3)
////    );
  OnConfirmProcessed_in_IOutstationApplication((((OContext*)ctx)->application), false,
      NumEvents_in_EventBuffer(&(((OContext*)ctx)->eventBuffer_in_OContext), EventClass_EC1),
      NumEvents_in_EventBuffer(&(((OContext*)ctx)->eventBuffer_in_OContext), EventClass_EC2),
      NumEvents_in_EventBuffer(&(((OContext*)ctx)->eventBuffer_in_OContext), EventClass_EC3));

// boolean HasSelection_in_ResponseContext(ResponseContext *pResponseContext);
////    if (ctx.rspContext.HasSelection())
  if (HasSelection_in_ResponseContext(&(((OContext*)ctx)->rspContext_in_OContext)))
  {
//    OutstationState* ContinueMultiFragResponse_in_OContext(OContext *pOContext, Addresses* addresses, AppSeqNum* seq);
//void SequenceNum_for_uint8_Modulus16_in_SequenceNum_for_uint8_Modulus16Over2(SequenceNum_for_uint8_Modulus16 *pSequenceNum_for_uint8_Modulus16, uint8_t value);
//uint8_t Next_in_SequenceNum_for_uint8_Modulus16_staticOver2(uint8_t seq);
////        return ctx.ContinueMultiFragResponse(request.addresses, AppSeqNum(request.header.control.SEQ).Next());
    SequenceNum_for_uint8_Modulus16  sSequenceNum_for_uint8_Modulus16;
    SequenceNum_for_uint8_Modulus16_in_SequenceNum_for_uint8_Modulus16Over2(&sSequenceNum_for_uint8_Modulus16, (request->header).control.SEQ);
    sSequenceNum_for_uint8_Modulus16.seq = Next_in_SequenceNum_for_uint8_Modulus16_staticOver2(sSequenceNum_for_uint8_Modulus16.seq);
    void* tmp = ContinueMultiFragResponse_in_OContext((OContext*)ctx, &(request->addresses), &sSequenceNum_for_uint8_Modulus16);

    ((OContext*)ctx)->unexpectedConfirm = false;

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}OnConfirm_in_StateSolicitedConfirmWait_override3_"<<std::endl;
  std::cout<<getString_stack_info();
  std::cout<<"((OContext*)ctx)->unexpectedConfirm= "<<((OContext*)ctx)->unexpectedConfirm<<std::endl;
  decrement_stack_info();
#endif
    return tmp;
  }

//     OutstationState* Inst_in_StateIdle_static(void);
////    return StateIdle::Inst();
  void *tmp = Inst_in_StateIdle_static();
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}OnConfirm_in_StateSolicitedConfirmWait_override4_"<<std::endl;
  decrement_stack_info();
#endif
  return tmp;
}
