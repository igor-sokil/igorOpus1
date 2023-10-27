#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
//#include <QtWidgets>
#include <QApplication>
#include "header.h"
#include "StaticDataMap_for_Analog.h"

////template<class Spec> StaticDataMap<Spec>::StaticDataMap(const std::map<uint16_t, typename Spec::config_t>& config)
void StaticDataMap_for_AnalogSpec_in_StaticDataMap_for_AnalogSpec(StaticDataMap_for_AnalogSpec *pStaticDataMap, std::map<uint16_t, AnalogConfig>& config)
{
  for (const auto& item : config)
  {
//void StaticDataCell_for_Analog_in_StaticDataCell_for_AnalogOver1(StaticDataCell_for_Analog *pStaticDataCell_for_Analog,
//    AnalogConfig* config);
////        pStaticDataMap->map[item.first] = StaticDataCell<Spec>{item.second};
    AnalogConfig temp = item.second;
    StaticDataCell_for_Analog sStaticDataCell_for_Analog;
    StaticDataCell_for_Analog_in_StaticDataCell_for_AnalogOver1(&sStaticDataCell_for_Analog, &temp);
    pStaticDataMap->map[item.first] = sStaticDataCell_for_Analog;
  }
}

Range get_selected_range_in_StaticDataMap_for_AnalogSpec(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec)
{
  return pStaticDataMap_for_AnalogSpec->selected;
}

typename StaticDataMap_for_AnalogSpec::iterator StaticDataMap_for_AnalogSpec::begin()
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
void clear_selection_in_StaticDataMap_for_AnalogSpec(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec)
{
  // the act of iterating clears the selection
  for (auto iter = pStaticDataMap_for_AnalogSpec->begin(); iter != pStaticDataMap_for_AnalogSpec->end(); ++iter)
  {
  }
}

////template<class Spec> typename StaticDataMap<Spec>::iterator StaticDataMap<Spec>::end()
typename StaticDataMap_for_AnalogSpec::iterator StaticDataMap_for_AnalogSpec::end()
{
  return iterator(this->map.end(), this->map.end(), this->selected);
}

////template<class Spec>
////typename Spec::static_variation_t check_for_promotion(const typename Spec::meas_t& value,
////                                                      typename Spec::static_variation_t variation)
StaticAnalogVariation_uint8_t check_for_promotion_for_AnalogSpec_static(Analog* value, StaticAnalogVariation_uint8_t variation)
{
  UNUSED(value);
  return variation;
}

uint16_t select_all_in_StaticDataMap_for_AnalogSpecOver1(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec)
{
  return select_all_in_StaticDataMap_for_AnalogSpecOver3(pStaticDataMap_for_AnalogSpec, [](auto var) {
    return var;
  }); // use the default
}

uint16_t select_all_in_StaticDataMap_for_AnalogSpecOver2(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec, StaticAnalogVariation_uint8_t variation)
{
  return select_all_in_StaticDataMap_for_AnalogSpecOver3(pStaticDataMap_for_AnalogSpec, [variation](auto var) {
    return variation;
  }); // override default
}

////    size_t select(Range range)
uint16_t select_in_StaticDataMap_for_AnalogSpecOver1(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec, Range range)
{
////        return this->select(range, [](auto var) { return var; }); // use the default
  return select_in_StaticDataMap_for_AnalogSpecOver5(pStaticDataMap_for_AnalogSpec, range, [](auto var) {
    return var;
  }); // use the default
}

////    bool select(uint16_t index, typename Spec::static_variation_t variation)
boolean select_in_StaticDataMap_for_AnalogSpecOver2(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec, uint16_t index, StaticAnalogVariation_uint8_t variation)
{
//Range From_in_Range_static(uint16_t start, uint16_t stop);
//uint16_t select_in_StaticDataMap_for_AnalogSpecOver4(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec, Range range, StaticAnalogVariation_uint8_t variation)
////        return this->select(Range::From(index, index), variation);
  return select_in_StaticDataMap_for_AnalogSpecOver4(pStaticDataMap_for_AnalogSpec, From_in_Range_static(index, index), variation) == 1;
}

////    bool select(uint16_t index)
boolean select_in_StaticDataMap_for_AnalogSpecOver3(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec, uint16_t index)
{
//uint16_t select_in_StaticDataMap_for_AnalogSpecOver1(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec, Range range)
////        return this->select(Range::From(index, index)) == 1;
  return select_in_StaticDataMap_for_AnalogSpecOver1(pStaticDataMap_for_AnalogSpec, From_in_Range_static(index, index)) == 1;
}

////    size_t select(Range range, typename Spec::static_variation_t variation)
uint16_t select_in_StaticDataMap_for_AnalogSpecOver4(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec, Range range, StaticAnalogVariation_uint8_t variation)
{
////        return this->select(range, [variation](auto var) { return variation; }); // override default
  return select_in_StaticDataMap_for_AnalogSpecOver5(pStaticDataMap_for_AnalogSpec, range, [variation](auto var) {
    return variation;
  }); // override default
}


boolean update_in_StaticDataMap_for_AnalogSpecOver1(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec,
    Analog* value,
    uint16_t index,
    EventMode_uint8_t mode,
    IEventReceiver* receiver)
{
//boolean update_in_StaticDataMap_for_AnalogSpecOver2(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec,
//    map_iter_t_StaticDataMap_for_AnalogSpec & iter,
//    Analog* new_value,
//    EventMode_uint8_t mode,
//    IEventReceiver* receiver);
////    return update(this->map.find(index), value, mode, receiver);
  map_iter_t_StaticDataMap_for_AnalogSpec  iter = pStaticDataMap_for_AnalogSpec->map.find(index);
  return update_in_StaticDataMap_for_AnalogSpecOver2(pStaticDataMap_for_AnalogSpec, iter, value, mode, receiver);
}

boolean update_in_StaticDataMap_for_AnalogSpecOver2(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec,
    map_iter_t_StaticDataMap_for_AnalogSpec & iter,
    Analog* new_value,
    EventMode_uint8_t mode,
    IEventReceiver* receiver)
{
  if (iter == pStaticDataMap_for_AnalogSpec->map.end())
  {
    return false;
  }

  if (mode != EventMode_EventOnly)
  {
    iter->second.value = *new_value;
  }

  Analog old_value = iter->second.event.eEventCellBase_for_Analog.lastEvent;
  if (mode == EventMode_Force || mode == EventMode_EventOnly ||
//boolean IsEvent_in_AnalogSpec_static(Analog *old_value, Analog *new_value, AnalogConfig *config);
////        Spec::IsEvent(iter->second.event.lastEvent, new_value, iter->second.config))
      IsEvent_in_AnalogSpec_static(&old_value, new_value, &(iter->second.config)))
  {
    iter->second.event.eEventCellBase_for_Analog.lastEvent = *new_value;
    if (mode != EventMode_Suppress)
    {
      EventClass_uint8_t ec;
//boolean convert_to_event_class_in_StaticDataMap_static(PointClass_uint8_t pc, EventClass_uint8_t* ec);
////            if (convert_to_event_class(iter->second.config.clazz, ec))
      if (convert_to_event_class_in_StaticDataMap_static(iter->second.config.dDeadbandConfig_for_AnalogInfo.eEventConfig.clazz, &ec))
      {
//void Event_for_AnalogSpec_in_Event_for_AnalogSpecOver2(Event_for_AnalogSpec *pEvent_for_AnalogSpec,
//    Analog* value, uint16_t index,
//    EventClass_uint8_t clazz,
//    event_variation_t_in_AnalogInfo variation);
//void Update_AnalogSpec_in_IEventReceiver(IEventReceiver *, Event_for_AnalogSpec* evt);
////                receiver.Update(Event<Spec>(new_value, iter->first, ec, iter->second.config.evariation));
        Event_for_AnalogSpec eEvent_for_AnalogSpec;
        Event_for_AnalogSpec_in_Event_for_AnalogSpecOver2(&eEvent_for_AnalogSpec,
            new_value, iter->first,
            ec,
            iter->second.config.dDeadbandConfig_for_AnalogInfo.eEventConfig.evariation);
        Update_AnalogSpec_in_IEventReceiver(receiver, &eEvent_for_AnalogSpec);

      }
    }
  }

  return true;
}

////    bool has_any_selection() const
boolean has_any_selection_in_StaticDataMap_for_AnalogSpec(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec)
{
//boolean IsValid_in_Range(Range *pRange);
////        return this->selected.IsValid();
  return IsValid_in_Range(&(pStaticDataMap_for_AnalogSpec->selected));
}

boolean add_in_StaticDataMap_for_AnalogSpec(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec, Analog *value, uint16_t index, AnalogConfig *config)
{
  if (pStaticDataMap_for_AnalogSpec->map.find(index) != pStaticDataMap_for_AnalogSpec->map.end())
  {
    return false;
  }

//void  StaticDataCell_for_Analog_in_StaticDataCell_for_AnalogOver2(StaticDataCell_for_Analog *pStaticDataCell_for_Analog,
//    Analog* value,
//    AnalogConfig* config);
  StaticDataCell_for_Analog sStaticDataCell;
  StaticDataCell_for_Analog_in_StaticDataCell_for_AnalogOver2(&sStaticDataCell, value, config);

  pStaticDataMap_for_AnalogSpec->map[index] = sStaticDataCell;////StaticDataCell_for_AnalogSpec{value, config};

  return true;
}
