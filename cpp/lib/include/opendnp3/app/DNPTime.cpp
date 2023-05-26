#include "header.h"
#include "DNPTime.h"

  void DNPTime_in_DNPTimeOver1(DNPTime *pDNPTime)
{
  pDNPTime->value = 0;
  pDNPTime->quality = TimestampQuality_INVALID;
}

  void DNPTime_in_DNPTimeOver2(DNPTime *pDNPTime, uint64_t value)
{
  pDNPTime->value = value;
  pDNPTime->quality = TimestampQuality_SYNCHRONIZED;
}

  void DNPTime_in_DNPTimeOver3(DNPTime *pDNPTime, uint64_t value, TimestampQuality_uint8_t quality)
{
  pDNPTime->value = value; 
  pDNPTime->quality = quality;
}

  boolean operatorEQ_in_DNPTime(DNPTime *pDNPTime, DNPTime *rhs)
{
    return pDNPTime->value == rhs->value && pDNPTime->quality == rhs->quality;
}
