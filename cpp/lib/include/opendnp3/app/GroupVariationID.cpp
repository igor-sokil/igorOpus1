#include "header.h"
#include "GroupVariationID.h"

void GroupVariationID_in_GroupVariationIDOver1(GroupVariationID *pGroupVariationID)
{
  pGroupVariationID->group = 0xFF;
  pGroupVariationID->variation = 0xFF;
}

////    GroupVariationID(uint8_t aGroup, uint8_t aVariation) : group(aGroup), variation(aVariation) {}
void GroupVariationID_in_GroupVariationIDOver2(GroupVariationID *pGroupVariationID, uint8_t aGroup, uint8_t aVariation)
{
  pGroupVariationID->group = aGroup;
  pGroupVariationID->variation = aVariation;
}
