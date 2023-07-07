#include "header.h"
#include "UTCTimestamp.h"

void UTCTimestamp_in_UTCTimestampOver1(UTCTimestamp *pUTCTimestamp)
{
  pUTCTimestamp->msSinceEpoch = 0;
}

void UTCTimestamp_in_UTCTimestampOver2(UTCTimestamp *pUTCTimestamp, uint64_t msSinceEpoch)
{
  pUTCTimestamp->msSinceEpoch = msSinceEpoch;
}
