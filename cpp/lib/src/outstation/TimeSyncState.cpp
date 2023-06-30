#include "header.h"
#include "TimeSyncState.h"

void TimeSyncState_in_TimeSyncState(TimeSyncState *pTimeSyncState)
{
  pTimeSyncState->valid = false;
}
void RecordCurrentTime_in_TimeSyncState(TimeSyncState *pTimeSyncState, AppSeqNum* seq, Timestamp* now)
{
  pTimeSyncState->valid = true;
  pTimeSyncState->timeTimestamp = *now;
//uint8_t Next_in_SequenceNum_for_uint8_Modulus16_staticOver2(uint8_t seq);
//void SequenceNum_for_uint8_Modulus16_in_SequenceNum_for_uint8_Modulus16Over2(SequenceNum_for_uint8_Modulus16 *pSequenceNum_for_uint8_Modulus16, uint8_t value);
////        expectedSeqNum = seq.Next();
  SequenceNum_for_uint8_Modulus16_in_SequenceNum_for_uint8_Modulus16Over2(&(pTimeSyncState->expectedSeqNum),
      Next_in_SequenceNum_for_uint8_Modulus16_staticOver2(seq->seq));////uint8_t value);
}

boolean CalcTimeDifference_in_TimeSyncState(TimeSyncState *pTimeSyncState, AppSeqNum* seq, Timestamp* now)
{
  if (!pTimeSyncState->valid)
    return false;
//boolean Equals_in_SequenceNum_for_uint8_Modulus16(SequenceNum_for_uint8_Modulus16 *pSequenceNum_for_uint8_Modulus16, uint8_t other);
////        if (!expectedSeqNum.Equals(seq))
  if(!Equals_in_SequenceNum_for_uint8_Modulus16(&(pTimeSyncState->expectedSeqNum), seq->seq))
    return false;
//boolean  operatorLT_in_Timestamp(Timestamp* pTimestamp, Timestamp* other)
////  if (now < pTimeSyncState->timeTimestamp)
 if(operatorLT_in_Timestamp(now, &(pTimeSyncState->timeTimestamp)))
    return false;

// void TimeDuration_in_TimeDuration(TimeDuration *pTimeDuration, uint64_t value);
////  pTimeSyncState->difference = now - pTimeSyncState->timeTimestamp;
  TimeDuration_in_TimeDuration(&(pTimeSyncState->difference), now->time_point_value - pTimeSyncState->timeTimestamp.time_point_value);
  pTimeSyncState->valid = false;

  return true;
}

TimeDuration GetDifference_in_TimeSyncState(TimeSyncState *pTimeSyncState)
{
  return pTimeSyncState->difference;
}
