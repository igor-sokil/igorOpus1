#include <QApplication>
#include "header.h"
#include "StaticDataMap_for_Counter.h"

////template<class Spec> StaticDataMap<Spec>::StaticDataMap(const std::map<uint16_t, typename Spec::config_t>& config)
void StaticDataMap_for_CounterSpec_in_StaticDataMap_for_CounterSpec(StaticDataMap_for_CounterSpec *pStaticDataMap, std::map<uint16_t, CounterConfig>& config)
{
  for (const auto& item : config)
  {
//void StaticDataCell_for_Counter_in_StaticDataCell_for_CounterOver1(StaticDataCell_for_Counter *pStaticDataCell_for_Counter,
//    CounterConfig* config);
////        pStaticDataMap->map[item.first] = StaticDataCell<Spec>{item.second};
    CounterConfig temp = item.second;
    StaticDataCell_for_Counter sStaticDataCell_for_Counter;
    StaticDataCell_for_Counter_in_StaticDataCell_for_CounterOver1(&sStaticDataCell_for_Counter, &temp);
    pStaticDataMap->map[item.first] = sStaticDataCell_for_Counter;
  }
}

Range get_selected_range_in_StaticDataMap_for_CounterSpec(StaticDataMap_for_CounterSpec *pStaticDataMap_for_CounterSpec)
{
  return pStaticDataMap_for_CounterSpec->selected;
}

typename StaticDataMap_for_CounterSpec::iterator StaticDataMap_for_CounterSpec::begin()
{
//boolean IsValid_in_Range(Range *pRange);
////    if (!this->selected.IsValid())
  if (!IsValid_in_Range(&(this->selected)))
  {
    return iterator(this->map.end(), this->map.end(), this->selected);
  }

  const auto begin = this->map.lower_bound(this->selected.start);

  return iterator(begin, this->map.end(), this->selected);
}

////template<class Spec> void StaticDataMap<Spec>::clear_selection()
void clear_selection_in_StaticDataMap_for_CounterSpec(StaticDataMap_for_CounterSpec *pStaticDataMap_for_CounterSpec)
{
  // the act of iterating clears the selection
  for (auto iter = pStaticDataMap_for_CounterSpec->begin(); iter != pStaticDataMap_for_CounterSpec->end(); ++iter)
  {
  }
}

////template<class Spec> typename StaticDataMap<Spec>::iterator StaticDataMap<Spec>::end()
typename StaticDataMap_for_CounterSpec::iterator StaticDataMap_for_CounterSpec::end()
{
  return iterator(this->map.end(), this->map.end(), this->selected);
}

////template<class Spec>
////typename Spec::static_variation_t check_for_promotion(const typename Spec::meas_t& value,
////                                                      typename Spec::static_variation_t variation)
StaticCounterVariation_uint8_t check_for_promotion_for_CounterSpec_static(Counter* value, StaticCounterVariation_uint8_t variation)
{
  UNUSED(value);
  return variation;
}

uint16_t select_all_in_StaticDataMap_for_CounterSpecOver1(StaticDataMap_for_CounterSpec *pStaticDataMap_for_CounterSpec)
{
  return select_all_in_StaticDataMap_for_CounterSpecOver3(pStaticDataMap_for_CounterSpec, [](auto var) {
    return var;
  }); // use the default
}

uint16_t select_all_in_StaticDataMap_for_CounterSpecOver2(StaticDataMap_for_CounterSpec *pStaticDataMap_for_CounterSpec, StaticCounterVariation_uint8_t variation)
{
  return select_all_in_StaticDataMap_for_CounterSpecOver3(pStaticDataMap_for_CounterSpec, [variation](auto var) {
    return variation;
  }); // override default
}

boolean update_in_StaticDataMap_for_CounterSpecOver1(StaticDataMap_for_CounterSpec *pStaticDataMap_for_CounterSpec,
    Counter* value,
    uint16_t index,
    EventMode_uint8_t mode,
    IEventReceiver* receiver)
{
//boolean update_in_StaticDataMap_for_CounterSpecOver2(StaticDataMap_for_CounterSpec *pStaticDataMap_for_CounterSpec,
//    map_iter_t_StaticDataMap_for_CounterSpec & iter,
//    Counter* new_value,
//    EventMode_uint8_t mode,
//    IEventReceiver* receiver);
////    return update(this->map.find(index), value, mode, receiver);
  map_iter_t_StaticDataMap_for_CounterSpec  iter = pStaticDataMap_for_CounterSpec->map.find(index);
  return update_in_StaticDataMap_for_CounterSpecOver2(pStaticDataMap_for_CounterSpec,
         iter, value, mode, receiver);
}

boolean update_in_StaticDataMap_for_CounterSpecOver2(StaticDataMap_for_CounterSpec *pStaticDataMap_for_CounterSpec,
    map_iter_t_StaticDataMap_for_CounterSpec & iter,
    Counter* new_value,
    EventMode_uint8_t mode,
    IEventReceiver* receiver)
{
  if (iter == pStaticDataMap_for_CounterSpec->map.end())
  {
    return false;
  }

  if (mode != EventMode_EventOnly)
  {
    iter->second.value = *new_value;
  }

  Counter old_value = iter->second.event.eEventCellBase_for_Counter.lastEvent;
  if (mode == EventMode_Force || mode == EventMode_EventOnly ||
//boolean IsEvent_in_CounterSpec_static(Counter *old_value, Counter *new_value, CounterConfig *config);
////        Spec::IsEvent(iter->second.event.lastEvent, new_value, iter->second.config))
      IsEvent_in_CounterSpec_static(&old_value, new_value, &(iter->second.config)))
  {
    iter->second.event.eEventCellBase_for_Counter.lastEvent = *new_value;
    if (mode != EventMode_Suppress)
    {
      EventClass_uint8_t ec;
//boolean convert_to_event_class_in_StaticDataMap_static(PointClass_uint8_t pc, EventClass_uint8_t* ec);
////            if (convert_to_event_class(iter->second.config.clazz, ec))
      if (convert_to_event_class_in_StaticDataMap_static(iter->second.config.dDeadbandConfig_for_CounterInfo.eEventConfig.clazz, &ec))
      {
//void Event_for_CounterSpec_in_Event_for_CounterSpecOver2(Event_for_CounterSpec *pEvent_for_CounterSpec,
//    Counter* value, uint16_t index,
//    EventClass_uint8_t clazz,
//    event_variation_t_in_CounterInfo variation);
//void Update_CounterSpec_in_IEventReceiver(IEventReceiver *, Event_for_CounterSpec* evt);
////                receiver.Update(Event<Spec>(new_value, iter->first, ec, iter->second.config.evariation));
        Event_for_CounterSpec eEvent_for_CounterSpec;
        Event_for_CounterSpec_in_Event_for_CounterSpecOver2(&eEvent_for_CounterSpec,
            new_value, iter->first,
            ec,
            iter->second.config.dDeadbandConfig_for_CounterInfo.eEventConfig.evariation);
        Update_CounterSpec_in_IEventReceiver(receiver, &eEvent_for_CounterSpec);

      }
    }
  }

  return true;
}
