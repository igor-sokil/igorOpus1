#include "header.h"
#include "OutstationSeqNum.h"

void OutstationSeqNum_in_OutstationSeqNum(OutstationSeqNum *pOutstationSeqNum)
{
 SequenceNum_for_uint8_Modulus16_in_SequenceNum_for_uint8_Modulus16Over1(&(pOutstationSeqNum->num));
 SequenceNum_for_uint8_Modulus16_in_SequenceNum_for_uint8_Modulus16Over1(&(pOutstationSeqNum->confirmNum));
}
