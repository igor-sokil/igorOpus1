#include "header.h"
#include "MeasurementConfig.h"

void TimeAndIntervalConfig_in_TimeAndIntervalConfig(TimeAndIntervalConfig *pTimeAndIntervalConfig)
{
 pTimeAndIntervalConfig->svariation = 0;
}
void OctetStringConfig_in_OctetStringConfig(OctetStringConfig *pOctetStringConfig)
{
 EventConfig_in_EventConfig(&(pOctetStringConfig->eEventConfig));
}
void AOStatusConfig_in_AOStatusConfig(AOStatusConfig *pAOStatusConfig)
{
 DeadbandConfig_for_AnalogOutputStatusInfo_in_DeadbandConfig_for_AnalogOutputStatusInfo(&(pAOStatusConfig->dDeadbandConfig_for_AnalogOutputStatusInfo));
}
void BOStatusConfig_in_BOStatusConfig(BOStatusConfig *pBOStatusConfig)
{
 EventConfig_in_EventConfig(&(pBOStatusConfig->eEventConfig));
}
void FrozenCounterConfig_in_FrozenCounterConfig(FrozenCounterConfig *pFrozenCounterConfig)
{
 DeadbandConfig_for_FrozenCounterInfo_in_DeadbandConfig_for_FrozenCounterInfo(&(pFrozenCounterConfig->dDeadbandConfig_for_FrozenCounterInfo));
}
void CounterConfig_in_CounterConfig(CounterConfig *pCounterConfig)
{
 DeadbandConfig_for_CounterInfo_in_DeadbandConfig_for_CounterInfo(&(pCounterConfig->dDeadbandConfig_for_CounterInfo));
}
void AnalogConfig_in_AnalogConfig(AnalogConfig *pAnalogConfig)
{
 DeadbandConfig_for_AnalogInfo_in_DeadbandConfig_for_AnalogInfo(&(pAnalogConfig->dDeadbandConfig_for_AnalogInfo));
}
void DoubleBitBinaryConfig_in_DoubleBitBinaryConfig(DoubleBitBinaryConfig *pDoubleBitBinaryConfig)
{
 EventConfig_in_EventConfig(&(pDoubleBitBinaryConfig->eEventConfig));
}
void BinaryConfig_in_BinaryConfig(BinaryConfig *pBinaryConfig)
{
 EventConfig_in_EventConfig(&(pBinaryConfig->eEventConfig));
}
void DeadbandConfig_for_AnalogOutputStatusInfo_in_DeadbandConfig_for_AnalogOutputStatusInfo(DeadbandConfig_for_AnalogOutputStatusInfo *pDeadbandConfig_for_AnalogOutputStatusInfo)
{
 EventConfig_in_EventConfig(&(pDeadbandConfig_for_AnalogOutputStatusInfo->eEventConfig));
 pDeadbandConfig_for_AnalogOutputStatusInfo->deadband = 0;
}
void DeadbandConfig_for_FrozenCounterInfo_in_DeadbandConfig_for_FrozenCounterInfo(DeadbandConfig_for_FrozenCounterInfo *pDeadbandConfig_for_FrozenCounterInfo)
{
 EventConfig_in_EventConfig(&(pDeadbandConfig_for_FrozenCounterInfo->eEventConfig));
 pDeadbandConfig_for_FrozenCounterInfo->deadband = 0;
}
void DeadbandConfig_for_CounterInfo_in_DeadbandConfig_for_CounterInfo(DeadbandConfig_for_CounterInfo *pDeadbandConfig_for_CounterInfo)
{
 EventConfig_in_EventConfig(&(pDeadbandConfig_for_CounterInfo->eEventConfig));
 pDeadbandConfig_for_CounterInfo->deadband = 0;
}
void DeadbandConfig_for_AnalogInfo_in_DeadbandConfig_for_AnalogInfo(DeadbandConfig_for_AnalogInfo *pDeadbandConfig_for_AnalogInfo)
{
 EventConfig_in_EventConfig(&(pDeadbandConfig_for_AnalogInfo->eEventConfig));
 pDeadbandConfig_for_AnalogInfo->deadband = 0;
}
void EventConfig_in_EventConfig(EventConfig *pEventConfig)
{
 pEventConfig->svariation = 0;
 pEventConfig->clazz = PointClass_Class1;
 pEventConfig->evariation = 0;
}
