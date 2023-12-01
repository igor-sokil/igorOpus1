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
  SequenceNum_for_uint8_Modulus16_in_SequenceNum_for_uint8_Modulus16Over1(&(pOutstationSolState->seq.num));
  SequenceNum_for_uint8_Modulus16_in_SequenceNum_for_uint8_Modulus16Over1(&(pOutstationSolState->seq.confirmNum));
//// : tx(maxTxSize) {}
  TxBuffer_in_TxBuffer(&(pOutstationSolState->tx), maxTxSize);
}

void OutstationUnsolState_in_OutstationUnsolState(OutstationUnsolState *pOutstationUnsolState, uint32_t maxTxSize)
{
  SequenceNum_for_uint8_Modulus16_in_SequenceNum_for_uint8_Modulus16Over1(&(pOutstationUnsolState->seq.num));
  SequenceNum_for_uint8_Modulus16_in_SequenceNum_for_uint8_Modulus16Over1(&(pOutstationUnsolState->seq.confirmNum));
  pOutstationUnsolState->completedNull = false;
  TxBuffer_in_TxBuffer(&(pOutstationUnsolState->tx), maxTxSize);
}
