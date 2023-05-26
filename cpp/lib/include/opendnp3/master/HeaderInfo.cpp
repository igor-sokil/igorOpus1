#include "header.h"
#include "HeaderInfo.h"

   void HeaderInfo_in_HeaderInfoOver1(HeaderInfo *pHeaderInfo)
{
     pHeaderInfo->gv = GroupVariation_UNKNOWN;
     pHeaderInfo->qualifier = QualifierCode_UNDEFINED;
     pHeaderInfo->tsquality = TimestampQuality_INVALID;
     pHeaderInfo->isEventVariation = false;
     pHeaderInfo->flagsValid = false;
     pHeaderInfo->headerIndex = 0;
}

   void HeaderInfo_in_HeaderInfoOver2(HeaderInfo *pHeaderInfo, GroupVariation_uint16_t gv_, QualifierCode_uint8_t qualifier_,
              TimestampQuality_uint8_t tsquality_, uint32_t headerIndex_)
{
    pHeaderInfo->gv = gv_;
    pHeaderInfo->qualifier = qualifier_;
    pHeaderInfo->tsquality = tsquality_;
    pHeaderInfo->isEventVariation = IsEvent(gv_);
    pHeaderInfo->flagsValid = HasFlags(gv_);
    pHeaderInfo->headerIndex = headerIndex_;
}
