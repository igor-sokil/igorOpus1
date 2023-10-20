#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include <QApplication>
#include "header.h"
#include "StaticDataMap_for_OctetString.h"

////template<class Spec> StaticDataMap<Spec>::StaticDataMap(const std::map<uint16_t, typename Spec::config_t>& config)
void StaticDataMap_for_OctetStringSpec_in_StaticDataMap_for_OctetStringSpec(StaticDataMap_for_OctetStringSpec *pStaticDataMap, std::map<uint16_t, OctetStringConfig>& config)
{
  for (const auto& item : config)
  {
//void StaticDataCell_for_OctetString_in_StaticDataCell_for_OctetStringOver1(StaticDataCell_for_OctetString *pStaticDataCell_for_OctetString,
//    OctetStringConfig* config);
////        pStaticDataMap->map[item.first] = StaticDataCell<Spec>{item.second};
    OctetStringConfig temp = item.second;
    StaticDataCell_for_OctetString sStaticDataCell_for_OctetString;
    StaticDataCell_for_OctetString_in_StaticDataCell_for_OctetStringOver1(&sStaticDataCell_for_OctetString, &temp);
    pStaticDataMap->map[item.first] = sStaticDataCell_for_OctetString;
  }
}

Range get_selected_range_in_StaticDataMap_for_OctetStringSpec(StaticDataMap_for_OctetStringSpec *pStaticDataMap_for_OctetStringSpec)
{
  return pStaticDataMap_for_OctetStringSpec->selected;
}

typename StaticDataMap_for_OctetStringSpec::iterator StaticDataMap_for_OctetStringSpec::begin()
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
void clear_selection_in_StaticDataMap_for_OctetStringSpec(StaticDataMap_for_OctetStringSpec *pStaticDataMap_for_OctetStringSpec)
{
  // the act of iterating clears the selection
  for (auto iter = pStaticDataMap_for_OctetStringSpec->begin(); iter != pStaticDataMap_for_OctetStringSpec->end(); ++iter)
  {
  }
}

////template<class Spec> typename StaticDataMap<Spec>::iterator StaticDataMap<Spec>::end()
typename StaticDataMap_for_OctetStringSpec::iterator StaticDataMap_for_OctetStringSpec::end()
{
  return iterator(this->map.end(), this->map.end(), this->selected);
}

////template<class Spec>
////typename Spec::static_variation_t check_for_promotion(const typename Spec::meas_t& value,
////                                                      typename Spec::static_variation_t variation)
StaticOctetStringVariation_uint8_t check_for_promotion_for_OctetStringSpec_static(OctetString* value, StaticOctetStringVariation_uint8_t variation)
{
  UNUSED(value);
  return variation;
}

uint16_t select_all_in_StaticDataMap_for_OctetStringSpecOver1(StaticDataMap_for_OctetStringSpec *pStaticDataMap_for_OctetStringSpec)
{
  return select_all_in_StaticDataMap_for_OctetStringSpecOver3(pStaticDataMap_for_OctetStringSpec, [](auto var) {
    return var;
  }); // use the default
}

uint16_t select_all_in_StaticDataMap_for_OctetStringSpecOver2(StaticDataMap_for_OctetStringSpec *pStaticDataMap_for_OctetStringSpec, StaticOctetStringVariation_uint8_t variation)
{
  return select_all_in_StaticDataMap_for_OctetStringSpecOver3(pStaticDataMap_for_OctetStringSpec, [variation](auto var) {
    return variation;
  }); // override default
}

boolean update_in_StaticDataMap_for_OctetStringSpecOver1(StaticDataMap_for_OctetStringSpec *pStaticDataMap_for_OctetStringSpec,
    OctetString* value,
    uint16_t index,
    EventMode_uint8_t mode,
    IEventReceiver* receiver)
{
//boolean update_in_StaticDataMap_for_OctetStringSpecOver2(StaticDataMap_for_OctetStringSpec *pStaticDataMap_for_OctetStringSpec,
//    map_iter_t_StaticDataMap_for_OctetStringSpec & iter,
//    OctetString* new_value,
//    EventMode_uint8_t mode,
//    IEventReceiver* receiver);
////    return update(this->map.find(index), value, mode, receiver);
  map_iter_t_StaticDataMap_for_OctetStringSpec  iter = pStaticDataMap_for_OctetStringSpec->map.find(index);
  return update_in_StaticDataMap_for_OctetStringSpecOver2(pStaticDataMap_for_OctetStringSpec,
         iter, value, mode, receiver);
}

boolean update_in_StaticDataMap_for_OctetStringSpecOver2(StaticDataMap_for_OctetStringSpec *pStaticDataMap_for_OctetStringSpec,
    map_iter_t_StaticDataMap_for_OctetStringSpec & iter,
    OctetString* new_value,
    EventMode_uint8_t mode,
    IEventReceiver* receiver)
{
#ifdef  LOG_INFO
  std::cout<<""<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"update_in_StaticDataMap_for_OctetStringSpecOver2_1"<<'\n';
  decrement_stack_info();
#endif
  if (iter == pStaticDataMap_for_OctetStringSpec->map.end())
  {
    return false;
  }

  if (mode != EventMode_EventOnly)
  {
    iter->second.value = *new_value;
  }

  OctetString old_value = iter->second.event.eEventCellBase_for_OctetString.lastEvent;
  if (mode == EventMode_Force || mode == EventMode_EventOnly ||
//boolean IsEvent_in_OctetStringSpec_static(OctetString *old_value, OctetString *new_value, OctetStringConfig *config);
////        Spec::IsEvent(iter->second.event.lastEvent, new_value, iter->second.config))
      IsEvent_in_OctetStringSpec_static(&old_value, new_value, &(iter->second.config)))
  {
    iter->second.event.eEventCellBase_for_OctetString.lastEvent = *new_value;
    if (mode != EventMode_Suppress)
    {
      EventClass_uint8_t ec;
//boolean convert_to_event_class_in_StaticDataMap_static(PointClass_uint8_t pc, EventClass_uint8_t* ec);
////            if (convert_to_event_class(iter->second.config.clazz, ec))
      if (convert_to_event_class_in_StaticDataMap_static(iter->second.config.eEventConfig.clazz, &ec))
      {
//void Event_for_OctetStringSpec_in_Event_for_OctetStringSpecOver2(Event_for_OctetStringSpec *pEvent_for_OctetStringSpec,
//    OctetString* value, uint16_t index,
//    EventClass_uint8_t clazz,
//    event_variation_t_in_OctetStringInfo variation);
//void Update_OctetStringSpec_in_IEventReceiver(IEventReceiver *, Event_for_OctetStringSpec* evt);
////                receiver.Update(Event<Spec>(new_value, iter->first, ec, iter->second.config.evariation));
        Event_for_OctetStringSpec eEvent_for_OctetStringSpec;
        Event_for_OctetStringSpec_in_Event_for_OctetStringSpecOver2(&eEvent_for_OctetStringSpec,
            new_value, iter->first, ec, iter->second.config.eEventConfig.evariation);
        Update_OctetStringSpec_in_IEventReceiver(receiver, &eEvent_for_OctetStringSpec);

      }
    }
  }

  return true;
}
