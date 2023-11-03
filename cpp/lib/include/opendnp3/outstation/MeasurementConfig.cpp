#include "header.h"
#include "MeasurementConfig.h"

void TimeAndIntervalConfig_in_TimeAndIntervalConfig(TimeAndIntervalConfig *pTimeAndIntervalConfig)
{
 pTimeAndIntervalConfig->svariation = StaticTimeAndIntervalVariation_Group50Var4;
}
void OctetStringConfig_in_OctetStringConfig(OctetStringConfig *pOctetStringConfig)
{
 EventConfig_in_EventConfig(&(pOctetStringConfig->eEventConfig),
             StaticOctetStringVariation_Group110Var0, EventOctetStringVariation_Group111Var0);
}
void AOStatusConfig_in_AOStatusConfig(AOStatusConfig *pAOStatusConfig)
{
 DeadbandConfig_for_AnalogOutputStatusInfo_in_DeadbandConfig_for_AnalogOutputStatusInfo(&(pAOStatusConfig->dDeadbandConfig_for_AnalogOutputStatusInfo));
}
void BOStatusConfig_in_BOStatusConfig(BOStatusConfig *pBOStatusConfig)
{
 EventConfig_in_EventConfig(&(pBOStatusConfig->eEventConfig), 
                          StaticBinaryOutputStatusVariation_Group10Var2, EventBinaryOutputStatusVariation_Group11Var1);
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
 EventConfig_in_EventConfig(&(pDoubleBitBinaryConfig->eEventConfig),
       StaticDoubleBinaryVariation_Group3Var2, EventDoubleBinaryVariation_Group4Var1);
}
void BinaryConfig_in_BinaryConfig(BinaryConfig *pBinaryConfig)
{
 EventConfig_in_EventConfig(&(pBinaryConfig->eEventConfig),
          StaticBinaryVariation_Group1Var2, EventBinaryVariation_Group2Var1);
}
void DeadbandConfig_for_AnalogOutputStatusInfo_in_DeadbandConfig_for_AnalogOutputStatusInfo(DeadbandConfig_for_AnalogOutputStatusInfo *pDeadbandConfig_for_AnalogOutputStatusInfo)
{
 EventConfig_in_EventConfig(&(pDeadbandConfig_for_AnalogOutputStatusInfo->eEventConfig), 
                                StaticAnalogOutputStatusVariation_Group40Var1, EventAnalogOutputStatusVariation_Group42Var1);
 pDeadbandConfig_for_AnalogOutputStatusInfo->deadband = 0;
}
void DeadbandConfig_for_FrozenCounterInfo_in_DeadbandConfig_for_FrozenCounterInfo(DeadbandConfig_for_FrozenCounterInfo *pDeadbandConfig_for_FrozenCounterInfo)
{
 EventConfig_in_EventConfig(&(pDeadbandConfig_for_FrozenCounterInfo->eEventConfig), 
                       StaticFrozenCounterVariation_Group21Var1, EventFrozenCounterVariation_Group23Var1);
 pDeadbandConfig_for_FrozenCounterInfo->deadband = 0;
}
void DeadbandConfig_for_CounterInfo_in_DeadbandConfig_for_CounterInfo(DeadbandConfig_for_CounterInfo *pDeadbandConfig_for_CounterInfo)
{
 EventConfig_in_EventConfig(&(pDeadbandConfig_for_CounterInfo->eEventConfig), 
                 StaticCounterVariation_Group20Var1, EventCounterVariation_Group22Var1);
 pDeadbandConfig_for_CounterInfo->deadband = 0;
}
void DeadbandConfig_for_AnalogInfo_in_DeadbandConfig_for_AnalogInfo(DeadbandConfig_for_AnalogInfo *pDeadbandConfig_for_AnalogInfo)
{
 EventConfig_in_EventConfig(&(pDeadbandConfig_for_AnalogInfo->eEventConfig), 
                StaticAnalogVariation_Group30Var1, EventAnalogVariation_Group32Var1);
 pDeadbandConfig_for_AnalogInfo->deadband = 0;
}
void EventConfig_in_EventConfig(EventConfig *pEventConfig, uint8_t svariation, uint8_t evariation)
{
 pEventConfig->svariation = svariation;
 pEventConfig->clazz = PointClass_Class1;
 pEventConfig->evariation = evariation;
}
