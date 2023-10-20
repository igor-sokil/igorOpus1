#include <QApplication>
#include "header.h"
#include "StaticDataMap_for_FrozenCounter.h"

////template<class Spec> StaticDataMap<Spec>::StaticDataMap(const std::map<uint16_t, typename Spec::config_t>& config)
void StaticDataMap_for_FrozenCounterSpec_in_StaticDataMap_for_FrozenCounterSpec(StaticDataMap_for_FrozenCounterSpec *pStaticDataMap, std::map<uint16_t, FrozenCounterConfig>& config)
{
  for (const auto& item : config)
  {
//void StaticDataCell_for_FrozenCounter_in_StaticDataCell_for_FrozenCounterOver1(StaticDataCell_for_FrozenCounter *pStaticDataCell_for_FrozenCounter,
//    FrozenCounterConfig* config);
////        pStaticDataMap->map[item.first] = StaticDataCell<Spec>{item.second};
    FrozenCounterConfig temp = item.second;
    StaticDataCell_for_FrozenCounter sStaticDataCell_for_FrozenCounter;
    StaticDataCell_for_FrozenCounter_in_StaticDataCell_for_FrozenCounterOver1(&sStaticDataCell_for_FrozenCounter, &temp);
    pStaticDataMap->map[item.first] = sStaticDataCell_for_FrozenCounter;
  }
}

Range get_selected_range_in_StaticDataMap_for_FrozenCounterSpec(StaticDataMap_for_FrozenCounterSpec *pStaticDataMap_for_FrozenCounterSpec)
{
  return pStaticDataMap_for_FrozenCounterSpec->selected;
}

typename StaticDataMap_for_FrozenCounterSpec::iterator StaticDataMap_for_FrozenCounterSpec::begin()
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
void clear_selection_in_StaticDataMap_for_FrozenCounterSpec(StaticDataMap_for_FrozenCounterSpec *pStaticDataMap_for_FrozenCounterSpec)
{
  // the act of iterating clears the selection
  for (auto iter = pStaticDataMap_for_FrozenCounterSpec->begin(); iter != pStaticDataMap_for_FrozenCounterSpec->end(); ++iter)
  {
  }
}

////template<class Spec> typename StaticDataMap<Spec>::iterator StaticDataMap<Spec>::end()
typename StaticDataMap_for_FrozenCounterSpec::iterator StaticDataMap_for_FrozenCounterSpec::end()
{
  return iterator(this->map.end(), this->map.end(), this->selected);
}

////template<class Spec>
////typename Spec::static_variation_t check_for_promotion(const typename Spec::meas_t& value,
////                                                      typename Spec::static_variation_t variation)
StaticFrozenCounterVariation_uint8_t check_for_promotion_for_FrozenCounterSpec_static(FrozenCounter* value, StaticFrozenCounterVariation_uint8_t variation)
{
  UNUSED(value);
  return variation;
}

uint16_t select_all_in_StaticDataMap_for_FrozenCounterSpecOver1(StaticDataMap_for_FrozenCounterSpec *pStaticDataMap_for_FrozenCounterSpec)
{
  return select_all_in_StaticDataMap_for_FrozenCounterSpecOver3(pStaticDataMap_for_FrozenCounterSpec, [](auto var) {
    return var;
  }); // use the default
}

uint16_t select_all_in_StaticDataMap_for_FrozenCounterSpecOver2(StaticDataMap_for_FrozenCounterSpec *pStaticDataMap_for_FrozenCounterSpec, StaticFrozenCounterVariation_uint8_t variation)
{
  return select_all_in_StaticDataMap_for_FrozenCounterSpecOver3(pStaticDataMap_for_FrozenCounterSpec, [variation](auto var) {
    return variation;
  }); // override default
}

boolean update_in_StaticDataMap_for_FrozenCounterSpecOver1(StaticDataMap_for_FrozenCounterSpec *pStaticDataMap_for_FrozenCounterSpec,
    FrozenCounter* value,
    uint16_t index,
    EventMode_uint8_t mode,
    IEventReceiver* receiver)
{
//boolean update_in_StaticDataMap_for_FrozenCounterSpecOver2(StaticDataMap_for_FrozenCounterSpec *pStaticDataMap_for_FrozenCounterSpec,
//    map_iter_t_StaticDataMap_for_FrozenCounterSpec & iter,
//    FrozenCounter* new_value,
//    EventMode_uint8_t mode,
//    IEventReceiver* receiver);
////    return update(this->map.find(index), value, mode, receiver);
  map_iter_t_StaticDataMap_for_FrozenCounterSpec  iter = pStaticDataMap_for_FrozenCounterSpec->map.find(index);
  return update_in_StaticDataMap_for_FrozenCounterSpecOver2(pStaticDataMap_for_FrozenCounterSpec,
         iter, value, mode, receiver);
}

boolean update_in_StaticDataMap_for_FrozenCounterSpecOver2(StaticDataMap_for_FrozenCounterSpec *pStaticDataMap_for_FrozenCounterSpec,
    map_iter_t_StaticDataMap_for_FrozenCounterSpec & iter,
    FrozenCounter* new_value,
    EventMode_uint8_t mode,
    IEventReceiver* receiver)
{
  if (iter == pStaticDataMap_for_FrozenCounterSpec->map.end())
  {
    return false;
  }

  if (mode != EventMode_EventOnly)
  {
    iter->second.value = *new_value;
  }

  FrozenCounter old_value = iter->second.event.eEventCellBase_for_FrozenCounter.lastEvent;
  if (mode == EventMode_Force || mode == EventMode_EventOnly ||
//boolean IsEvent_in_FrozenCounterSpec_static(FrozenCounter *old_value, FrozenCounter *new_value, FrozenCounterConfig *config);
////        Spec::IsEvent(iter->second.event.lastEvent, new_value, iter->second.config))
      IsEvent_in_FrozenCounterSpec_static(&old_value, new_value, &(iter->second.config)))
  {
    iter->second.event.eEventCellBase_for_FrozenCounter.lastEvent = *new_value;
    if (mode != EventMode_Suppress)
    {
      EventClass_uint8_t ec;
//boolean convert_to_event_class_in_StaticDataMap_static(PointClass_uint8_t pc, EventClass_uint8_t* ec);
////            if (convert_to_event_class(iter->second.config.clazz, ec))
      if (convert_to_event_class_in_StaticDataMap_static(iter->second.config.dDeadbandConfig_for_FrozenCounterInfo.eEventConfig.clazz, &ec))
      {
//void Event_for_FrozenCounterSpec_in_Event_for_FrozenCounterSpecOver2(Event_for_FrozenCounterSpec *pEvent_for_FrozenCounterSpec,
//    FrozenCounter* value, uint16_t index,
//    EventClass_uint8_t clazz,
//    event_variation_t_in_FrozenCounterInfo variation);
//void Update_FrozenCounterSpec_in_IEventReceiver(IEventReceiver *, Event_for_FrozenCounterSpec* evt);
////                receiver.Update(Event<Spec>(new_value, iter->first, ec, iter->second.config.evariation));
        Event_for_FrozenCounterSpec eEvent_for_FrozenCounterSpec;
        Event_for_FrozenCounterSpec_in_Event_for_FrozenCounterSpecOver2(&eEvent_for_FrozenCounterSpec,
            new_value, iter->first,
            ec,
            iter->second.config.dDeadbandConfig_for_FrozenCounterInfo.eEventConfig.evariation);
        Update_FrozenCounterSpec_in_IEventReceiver(receiver, &eEvent_for_FrozenCounterSpec);

      }
    }
  }

  return true;
}
