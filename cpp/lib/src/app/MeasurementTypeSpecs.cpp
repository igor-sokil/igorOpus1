#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "MeasurementTypeSpecs.h"

boolean IsQualityOnlineOnly_in_BinarySpec_static(Binary *binary)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"IsQualityOnlineOnly_in_BinarySpec_static1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*(binary->tTypedMeasurement_for_Boolean).mMeasurement.flags.value= "<<(uint16_t)(binary->tTypedMeasurement_for_Boolean).mMeasurement.flags.value<<'\n';
  decrement_stack_info();
#endif
  return ((binary->tTypedMeasurement_for_Boolean).mMeasurement.flags.value & /*0b01111111*/0x7F) == (uint8_t)(BinaryQuality_ONLINE);
}

boolean IsEvent_in_BinarySpec_static(Binary *old_value,
                                     Binary *new_value,
                                     BinaryConfig *config)////const config_t& config)
{
  UNUSED(config);
  return (old_value->tTypedMeasurement_for_Boolean).mMeasurement.flags.value !=
         (new_value->tTypedMeasurement_for_Boolean).mMeasurement.flags.value;
}

boolean IsEvent_in_DoubleBitBinarySpec_static(DoubleBitBinary *old_value,
    DoubleBitBinary *new_value,
    DoubleBitBinaryConfig  *config)////const config_t& config)
{
  UNUSED(config);
  return (old_value->tTypedMeasurement_for_DoubleBit_uint8_t).mMeasurement.flags.value !=
         (new_value->tTypedMeasurement_for_DoubleBit_uint8_t).mMeasurement.flags.value;
}

boolean IsEvent_in_BinaryOutputStatusSpec_static(BinaryOutputStatus *old_value,
    BinaryOutputStatus *new_value,
    BOStatusConfig *config)////const config_t& config)
{
  UNUSED(config);
  return (old_value->tTypedMeasurement_for_Boolean).mMeasurement.flags.value !=
         (new_value->tTypedMeasurement_for_Boolean).mMeasurement.flags.value;
}

boolean IsEvent_in_AnalogSpec_static(
  Analog *old_value,
  Analog *new_value,
  AnalogConfig *config)////const config_t& config)
{
////    return measurements::IsEvent(new_value, old_value, config.deadband);
  return IsEvent_in_EventTriggers_for_TypedMeasurement_for_Double64(
           &(new_value->tTypedMeasurement_for_Double64),
           &(old_value->tTypedMeasurement_for_Double64),
           (config->dDeadbandConfig_for_AnalogInfo).deadband);
}


boolean IsEvent_in_CounterSpec_static(
  Counter *old_value,
  Counter *new_value,
  CounterConfig *config)////const config_t& config)
{
  if ((old_value->tTypedMeasurement_for_Uint32).mMeasurement.flags.value !=
      (new_value->tTypedMeasurement_for_Uint32).mMeasurement.flags.value)
  {
    return true;
  }
  else
  {
////        return measurements::IsEvent<uint32_t, uint64_t>(old_value.value, new_value.value, config.deadband);
    return IsEvent_in_EventTriggers_for_TypedMeasurement_for_Uint32(
             &(new_value->tTypedMeasurement_for_Uint32),
             &(old_value->tTypedMeasurement_for_Uint32),
             (config->dDeadbandConfig_for_CounterInfo).deadband);
  }
}

boolean IsEvent_in_FrozenCounterSpec_static(
  FrozenCounter *old_value,
  FrozenCounter *new_value,
  FrozenCounterConfig *config)////const config_t& config)
{
  if ((old_value->tTypedMeasurement_for_Uint32).mMeasurement.flags.value !=
      (new_value->tTypedMeasurement_for_Uint32).mMeasurement.flags.value)
  {
    return true;
  }
  else
  {
////        return measurements::IsEvent<uint32_t, uint64_t>(old_value.value, new_value.value, config.deadband);
    return IsEvent_in_EventTriggers_for_TypedMeasurement_for_Uint32(
             &(new_value->tTypedMeasurement_for_Uint32),
             &(old_value->tTypedMeasurement_for_Uint32),
             (config->dDeadbandConfig_for_FrozenCounterInfo).deadband);
  }
}

boolean IsEvent_in_AnalogOutputStatusSpec_static(
  AnalogOutputStatus *old_value,
  AnalogOutputStatus *new_value,
  AOStatusConfig *config)//const config_t& config)
{
////        return measurements::IsEvent(new_value, old_value, config.deadband);
  return IsEvent_in_EventTriggers_for_TypedMeasurement_for_Double64(
           &(new_value->tTypedMeasurement_for_Double64),
           &(old_value->tTypedMeasurement_for_Double64),
           (config->dDeadbandConfig_for_AnalogOutputStatusInfo).deadband);
}

boolean IsEvent_in_OctetStringSpec_static(
  OctetString *old_value,
  OctetString *new_value,
  void *config)//const config_t& config)
{
  UNUSED(config);
  Buffer old_value_buffer = ToBuffer_in_OctetData(&(old_value->oOctetData));//// ToBuffer();
////    const ser4cpp::rseq_t old_value_seq(old_value_buffer.data, old_value_buffer.length);
  RSeq_for_Uint16_t old_value_seq;
  RSeq_for_Uint16_t_in_RSeq_for_Uint16_tOver2(&old_value_seq, old_value_buffer.data, old_value_buffer.length);

////    const auto new_value_buffer = new_value.ToBuffer();
  Buffer new_value_buffer = ToBuffer_in_OctetData(&(new_value->oOctetData));//// ToBuffer();

////    const ser4cpp::rseq_t new_value_seq(new_value_buffer.data, new_value_buffer.length);
  RSeq_for_Uint16_t new_value_seq;
  RSeq_for_Uint16_t_in_RSeq_for_Uint16_tOver2(&new_value_seq, new_value_buffer.data, new_value_buffer.length);

////    return !old_value_seq.equals(new_value_seq);
  return !equals_in_RSeq_for_Uint16_t(&new_value_seq, &old_value_seq);
}
