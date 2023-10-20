#include <QApplication>
#include "header.h"
#include "StaticDataMap.h"
#include "StaticDataMap_for_TimeAndInterval.h"

////template<class Spec> StaticDataMap<Spec>::StaticDataMap(const std::map<uint16_t, typename Spec::config_t>& config)
void StaticDataMap_for_TimeAndIntervalSpec_in_StaticDataMap_for_TimeAndIntervalSpec(StaticDataMap_for_TimeAndIntervalSpec *pStaticDataMap, std::map<uint16_t, TimeAndIntervalConfig>& config)
{
  for (const auto& item : config)
  {
//void StaticDataCell_for_TimeAndInterval_in_StaticDataCell_for_TimeAndIntervalOver1(StaticDataCell_for_TimeAndInterval *pStaticDataCell_for_TimeAndInterval,
//    TimeAndIntervalConfig* config);
////        pStaticDataMap->map[item.first] = StaticDataCell<Spec>{item.second};
    TimeAndIntervalConfig temp = item.second;
    StaticDataCell_for_TimeAndInterval sStaticDataCell_for_TimeAndInterval;
    StaticDataCell_for_TimeAndInterval_in_StaticDataCell_for_TimeAndIntervalOver1(&sStaticDataCell_for_TimeAndInterval, &temp);
    pStaticDataMap->map[item.first] = sStaticDataCell_for_TimeAndInterval;
  }
}

Range get_selected_range_in_StaticDataMap_for_TimeAndIntervalSpec(StaticDataMap_for_TimeAndIntervalSpec *pStaticDataMap_for_TimeAndIntervalSpec)
{
  return pStaticDataMap_for_TimeAndIntervalSpec->selected;
}

typename StaticDataMap_for_TimeAndIntervalSpec::iterator StaticDataMap_for_TimeAndIntervalSpec::begin()
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
void clear_selection_in_StaticDataMap_for_TimeAndIntervalSpec(StaticDataMap_for_TimeAndIntervalSpec *pStaticDataMap_for_TimeAndIntervalSpec)
{
  // the act of iterating clears the selection
  for (auto iter = pStaticDataMap_for_TimeAndIntervalSpec->begin(); iter != pStaticDataMap_for_TimeAndIntervalSpec->end(); ++iter)
  {
  }
}

////template<class Spec> typename StaticDataMap<Spec>::iterator StaticDataMap<Spec>::end()
typename StaticDataMap_for_TimeAndIntervalSpec::iterator StaticDataMap_for_TimeAndIntervalSpec::end()
{
  return iterator(this->map.end(), this->map.end(), this->selected);
}

////template<class Spec>
////typename Spec::static_variation_t check_for_promotion(const typename Spec::meas_t& value,
////                                                      typename Spec::static_variation_t variation)
StaticTimeAndIntervalVariation_uint8_t check_for_promotion_for_TimeAndIntervalSpec_static(TimeAndInterval* value, StaticTimeAndIntervalVariation_uint8_t variation)
{
  UNUSED(value);
  return variation;
}

uint16_t select_all_in_StaticDataMap_for_TimeAndIntervalSpecOver1(StaticDataMap_for_TimeAndIntervalSpec *pStaticDataMap_for_TimeAndIntervalSpec)
{
  return select_all_in_StaticDataMap_for_TimeAndIntervalSpecOver3(pStaticDataMap_for_TimeAndIntervalSpec, [](auto var) {
    return var;
  }); // use the default
}

uint16_t select_all_in_StaticDataMap_for_TimeAndIntervalSpecOver2(StaticDataMap_for_TimeAndIntervalSpec *pStaticDataMap_for_TimeAndIntervalSpec, StaticTimeAndIntervalVariation_uint8_t variation)
{
  return select_all_in_StaticDataMap_for_TimeAndIntervalSpecOver3(pStaticDataMap_for_TimeAndIntervalSpec, [variation](auto var) {
    return variation;
  }); // override default
}
/*
boolean update_in_StaticDataMap_for_TimeAndIntervalSpecOver2(StaticDataMap_for_TimeAndIntervalSpec *pStaticDataMap_for_TimeAndIntervalSpec,
    map_iter_t_StaticDataMap_for_TimeAndIntervalSpec & iter,
    TimeAndInterval* new_value,
    EventMode_uint8_t mode,
    IEventReceiver* receiver)
{
  if (iter == pStaticDataMap_for_TimeAndIntervalSpec->map.end())
  {
    return false;
  }

  if (mode != EventMode_EventOnly)
  {
    iter->second.value = *new_value;
  }

  TimeAndInterval old_value = iter->second.event.eEventCellBase_for_TimeAndInterval.lastEvent;
  if (mode == EventMode_Force || mode == EventMode_EventOnly ||
//boolean IsEvent_in_TimeAndIntervalSpec_static(TimeAndInterval *old_value, TimeAndInterval *new_value, TimeAndIntervalConfig *config);
////        Spec::IsEvent(iter->second.event.lastEvent, new_value, iter->second.config))
      IsEvent_in_TimeAndIntervalSpec_static(&old_value, new_value, &(iter->second.config)))
  {
    iter->second.event.eEventCellBase_for_TimeAndInterval.lastEvent = *new_value;
    if (mode != EventMode_Suppress)
    {
      EventClass_uint8_t ec;
//boolean convert_to_event_class_in_StaticDataMap_static(PointClass_uint8_t pc, EventClass_uint8_t* ec);
////            if (convert_to_event_class(iter->second.config.clazz, ec))
      if (convert_to_event_class_in_StaticDataMap_static(iter->second.config.eEventConfig.clazz, &ec))
      {
//void Event_for_TimeAndIntervalSpec_in_Event_for_TimeAndIntervalSpecOver2(Event_for_TimeAndIntervalSpec *pEvent_for_TimeAndIntervalSpec,
//    TimeAndInterval* value, uint16_t index,
//    EventClass_uint8_t clazz,
//    event_variation_t_in_TimeAndIntervalInfo variation);
//void Update_TimeAndIntervalSpec_in_IEventReceiver(IEventReceiver *, Event_for_TimeAndIntervalSpec* evt);
////                receiver.Update(Event<Spec>(new_value, iter->first, ec, iter->second.config.evariation));
        Event_for_TimeAndIntervalSpec eEvent_for_TimeAndIntervalSpec;
        Event_for_TimeAndIntervalSpec_in_Event_for_TimeAndIntervalSpecOver2(&eEvent_for_TimeAndIntervalSpec,
            new_value, iter->first,
            ec,
            iter->second.config.dDeadbandConfig_for_TimeAndIntervalInfo.eEventConfig.evariation);
        Update_TimeAndIntervalSpec_in_IEventReceiver(receiver, &eEvent_for_TimeAndIntervalSpec);

      }
    }
  }

  return true;
}
*/
