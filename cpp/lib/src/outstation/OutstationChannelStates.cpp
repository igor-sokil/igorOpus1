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
//// : tx(maxTxSize) {}
  TxBuffer_in_TxBuffer(&(pOutstationSolState->tx), maxTxSize);
}

void OutstationUnsolState_in_OutstationUnsolState(OutstationUnsolState *pOutstationUnsolState, uint32_t maxTxSize)
{
  pOutstationUnsolState->completedNull = false;
  TxBuffer_in_TxBuffer(&(pOutstationUnsolState->tx), maxTxSize);
}
