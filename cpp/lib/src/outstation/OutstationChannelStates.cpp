#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "OutstationChannelStates.h"

void Reset_in_OutstationSolState(OutstationSolState *pOutstationSolState)
{
  UNUSED(pOutstationSolState);
}

void Reset_in_OutstationUnsolState(OutstationUnsolState *pOutstationUnsolState)
{
  pOutstationUnsolState->completedNull = false;
}

void  OutstationSolState_in_OutstationSolState(OutstationSolState *pOutstationSolState, uint32_t maxTxSize)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{OutstationSolState_in_OutstationSolState1"<<'\n';
#endif
//  SequenceNum_for_uint8_Modulus16_in_SequenceNum_for_uint8_Modulus16Over1(&(pOutstationSolState->seq.num));
//  SequenceNum_for_uint8_Modulus16_in_SequenceNum_for_uint8_Modulus16Over1(&(pOutstationSolState->seq.confirmNum));
  OutstationSeqNum_in_OutstationSeqNum(&(pOutstationSolState->seq));
//// : tx(maxTxSize) {}
  TxBuffer_in_TxBuffer(&(pOutstationSolState->tx_in_OutstationSolState), maxTxSize);
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}OutstationSolState_in_OutstationSolState_"<<'\n';
  decrement_stack_info();
#endif
}

void OutstationUnsolState_in_OutstationUnsolState(OutstationUnsolState *pOutstationUnsolState, uint32_t maxTxSize)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{OutstationUnsolState_in_OutstationUnsolState1"<<'\n';
#endif
//  SequenceNum_for_uint8_Modulus16_in_SequenceNum_for_uint8_Modulus16Over1(&(pOutstationUnsolState->seq.num));
//  SequenceNum_for_uint8_Modulus16_in_SequenceNum_for_uint8_Modulus16Over1(&(pOutstationUnsolState->seq.confirmNum));
  OutstationSeqNum_in_OutstationSeqNum(&(pOutstationUnsolState->seq));

  pOutstationUnsolState->completedNull = false;
  TxBuffer_in_TxBuffer(&(pOutstationUnsolState->tx), maxTxSize);
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}OutstationUnsolState_in_OutstationUnsolState_"<<'\n';
  decrement_stack_info();
#endif
}
