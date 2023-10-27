#include <QApplication>
#include "header.h"
#include "StaticDataMap_for_AnalogOutputStatus.h"

////template<class Spec> StaticDataMap<Spec>::StaticDataMap(const std::map<uint16_t, typename Spec::config_t>& config)
void StaticDataMap_for_AnalogOutputStatusSpec_in_StaticDataMap_for_AnalogOutputStatusSpec(StaticDataMap_for_AnalogOutputStatusSpec *pStaticDataMap, std::map<uint16_t, AOStatusConfig>& config)
{
  for (const auto& item : config)
  {
//void StaticDataCell_for_AnalogOutputStatus_in_StaticDataCell_for_AnalogOutputStatusOver1(StaticDataCell_for_AnalogOutputStatus *pStaticDataCell_for_AnalogOutputStatus,
//    AnalogOutputStatusConfig* config);
////        pStaticDataMap->map[item.first] = StaticDataCell<Spec>{item.second};
    AOStatusConfig temp = item.second;
    StaticDataCell_for_AnalogOutputStatus sStaticDataCell_for_AnalogOutputStatus;
    StaticDataCell_for_AnalogOutputStatus_in_StaticDataCell_for_AnalogOutputStatusOver1(&sStaticDataCell_for_AnalogOutputStatus, &temp);
    pStaticDataMap->map[item.first] = sStaticDataCell_for_AnalogOutputStatus;
  }
}

Range get_selected_range_in_StaticDataMap_for_AnalogOutputStatusSpec(StaticDataMap_for_AnalogOutputStatusSpec *pStaticDataMap_for_AnalogOutputStatusSpec)
{
  return pStaticDataMap_for_AnalogOutputStatusSpec->selected;
}

typename StaticDataMap_for_AnalogOutputStatusSpec::iterator StaticDataMap_for_AnalogOutputStatusSpec::begin()
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
void clear_selection_in_StaticDataMap_for_AnalogOutputStatusSpec(StaticDataMap_for_AnalogOutputStatusSpec *pStaticDataMap_for_AnalogOutputStatusSpec)
{
  // the act of iterating clears the selection
  for (auto iter = pStaticDataMap_for_AnalogOutputStatusSpec->begin(); iter != pStaticDataMap_for_AnalogOutputStatusSpec->end(); ++iter)
  {
  }
}

////template<class Spec> typename StaticDataMap<Spec>::iterator StaticDataMap<Spec>::end()
typename StaticDataMap_for_AnalogOutputStatusSpec::iterator StaticDataMap_for_AnalogOutputStatusSpec::end()
{
  return iterator(this->map.end(), this->map.end(), this->selected);
}

////template<class Spec>
////typename Spec::static_variation_t check_for_promotion(const typename Spec::meas_t& value,
////                                                      typename Spec::static_variation_t variation)
StaticAnalogOutputStatusVariation_uint8_t check_for_promotion_for_AnalogOutputStatusSpec_static(AnalogOutputStatus* value, StaticAnalogOutputStatusVariation_uint8_t variation)
{
  UNUSED(value);
  return variation;
}

uint16_t select_all_in_StaticDataMap_for_AnalogOutputStatusSpecOver1(StaticDataMap_for_AnalogOutputStatusSpec *pStaticDataMap_for_AnalogOutputStatusSpec)
{
  return select_all_in_StaticDataMap_for_AnalogOutputStatusSpecOver3(pStaticDataMap_for_AnalogOutputStatusSpec, [](auto var) {
    return var;
  }); // use the default
}

uint16_t select_all_in_StaticDataMap_for_AnalogOutputStatusSpecOver2(StaticDataMap_for_AnalogOutputStatusSpec *pStaticDataMap_for_AnalogOutputStatusSpec, StaticAnalogOutputStatusVariation_uint8_t variation)
{
  return select_all_in_StaticDataMap_for_AnalogOutputStatusSpecOver3(pStaticDataMap_for_AnalogOutputStatusSpec, [variation](auto var) {
    return variation;
  }); // override default
}

////    size_t select(Range range)
uint16_t select_in_StaticDataMap_for_AnalogOutputStatusSpecOver1(StaticDataMap_for_AnalogOutputStatusSpec *pStaticDataMap_for_AnalogOutputStatusSpec, Range range)
{
////        return this->select(range, [](auto var) { return var; }); // use the default
  return select_in_StaticDataMap_for_AnalogOutputStatusSpecOver5(pStaticDataMap_for_AnalogOutputStatusSpec, range, [](auto var) {
    return var;
  }); // use the default
}

////    bool select(uint16_t index, typename Spec::static_variation_t variation)
boolean select_in_StaticDataMap_for_AnalogOutputStatusSpecOver2(StaticDataMap_for_AnalogOutputStatusSpec *pStaticDataMap_for_AnalogOutputStatusSpec, uint16_t index, StaticAnalogOutputStatusVariation_uint8_t variation)
{
////        return this->select(Range::From(index, index), variation);
  return select_in_StaticDataMap_for_AnalogOutputStatusSpecOver4(pStaticDataMap_for_AnalogOutputStatusSpec, From_in_Range_static(index, index), variation) == 1;
}

////    bool select(uint16_t index)
boolean select_in_StaticDataMap_for_AnalogOutputStatusSpecOver3(StaticDataMap_for_AnalogOutputStatusSpec *pStaticDataMap_for_AnalogOutputStatusSpec, uint16_t index)
{
////        return this->select(Range::From(index, index)) == 1;
  return select_in_StaticDataMap_for_AnalogOutputStatusSpecOver1(pStaticDataMap_for_AnalogOutputStatusSpec, From_in_Range_static(index, index)) == 1;
}

////    size_t select(Range range, typename Spec::static_variation_t variation)
uint16_t select_in_StaticDataMap_for_AnalogOutputStatusSpecOver4(StaticDataMap_for_AnalogOutputStatusSpec *pStaticDataMap_for_AnalogOutputStatusSpec, Range range, StaticAnalogOutputStatusVariation_uint8_t variation)
{
////        return this->select(range, [variation](auto var) { return variation; }); // override default
  return select_in_StaticDataMap_for_AnalogOutputStatusSpecOver5(pStaticDataMap_for_AnalogOutputStatusSpec, range, [variation](auto var) {
    return variation;
  }); // override default
}

boolean update_in_StaticDataMap_for_AnalogOutputStatusSpecOver1(StaticDataMap_for_AnalogOutputStatusSpec *pStaticDataMap_for_AnalogOutputStatusSpec,
    AnalogOutputStatus* value,
    uint16_t index,
    EventMode_uint8_t mode,
    IEventReceiver* receiver)
{
//boolean update_in_StaticDataMap_for_AnalogOutputStatusSpecOver2(StaticDataMap_for_AnalogOutputStatusSpec *pStaticDataMap_for_AnalogOutputStatusSpec,
//    map_iter_t_StaticDataMap_for_AnalogOutputStatusSpec & iter,
//    AnalogOutputStatus* new_value,
//    EventMode_uint8_t mode,
//    IEventReceiver* receiver);
////    return update(this->map.find(index), value, mode, receiver);
  map_iter_t_StaticDataMap_for_AnalogOutputStatusSpec  iter = pStaticDataMap_for_AnalogOutputStatusSpec->map.find(index);
  return update_in_StaticDataMap_for_AnalogOutputStatusSpecOver2(pStaticDataMap_for_AnalogOutputStatusSpec,
         iter, value, mode, receiver);
}

boolean update_in_StaticDataMap_for_AnalogOutputStatusSpecOver2(StaticDataMap_for_AnalogOutputStatusSpec *pStaticDataMap_for_AnalogOutputStatusSpec,
    map_iter_t_StaticDataMap_for_AnalogOutputStatusSpec & iter,
    AnalogOutputStatus* new_value,
    EventMode_uint8_t mode,
    IEventReceiver* receiver)
{
  if (iter == pStaticDataMap_for_AnalogOutputStatusSpec->map.end())
  {
    return false;
  }

  if (mode != EventMode_EventOnly)
  {
    iter->second.value = *new_value;
  }

  AnalogOutputStatus old_value = iter->second.event.eEventCellBase_for_AnalogOutputStatus.lastEvent;
  if (mode == EventMode_Force || mode == EventMode_EventOnly ||
//boolean IsEvent_in_AnalogOutputStatusSpec_static(AnalogOutputStatus *old_value, AnalogOutputStatus *new_value, AnalogOutputStatusConfig *config);
////        Spec::IsEvent(iter->second.event.lastEvent, new_value, iter->second.config))
      IsEvent_in_AnalogOutputStatusSpec_static(&old_value, new_value, &(iter->second.config)))
  {
    iter->second.event.eEventCellBase_for_AnalogOutputStatus.lastEvent = *new_value;
    if (mode != EventMode_Suppress)
    {
      EventClass_uint8_t ec;
//boolean convert_to_event_class_in_StaticDataMap_static(PointClass_uint8_t pc, EventClass_uint8_t* ec);
////            if (convert_to_event_class(iter->second.config.clazz, ec))
      if (convert_to_event_class_in_StaticDataMap_static(iter->second.config.dDeadbandConfig_for_AnalogOutputStatusInfo.eEventConfig.clazz, &ec))
      {
//void Event_for_AnalogOutputStatusSpec_in_Event_for_AnalogOutputStatusSpecOver2(Event_for_AnalogOutputStatusSpec *pEvent_for_AnalogOutputStatusSpec,
//    AnalogOutputStatus* value, uint16_t index,
//    EventClass_uint8_t clazz,
//    event_variation_t_in_AnalogOutputStatusInfo variation);
//void Update_AnalogOutputStatusSpec_in_IEventReceiver(IEventReceiver *, Event_for_AnalogOutputStatusSpec* evt);
////                receiver.Update(Event<Spec>(new_value, iter->first, ec, iter->second.config.evariation));
        Event_for_AnalogOutputStatusSpec eEvent_for_AnalogOutputStatusSpec;
        Event_for_AnalogOutputStatusSpec_in_Event_for_AnalogOutputStatusSpecOver2(&eEvent_for_AnalogOutputStatusSpec,
            new_value, iter->first,
            ec,
            iter->second.config.dDeadbandConfig_for_AnalogOutputStatusInfo.eEventConfig.evariation);
        Update_AnalogOutputStatusSpec_in_IEventReceiver(receiver, &eEvent_for_AnalogOutputStatusSpec);

      }
    }
  }

  return true;
}

////    bool has_any_selection() const
boolean has_any_selection_in_StaticDataMap_for_AnalogOutputStatusSpec(StaticDataMap_for_AnalogOutputStatusSpec *pStaticDataMap_for_AnalogOutputStatusSpec)
{
//boolean IsValid_in_Range(Range *pRange);
////        return this->selected.IsValid();
  return IsValid_in_Range(&(pStaticDataMap_for_AnalogOutputStatusSpec->selected));
}

boolean add_in_StaticDataMap_for_AnalogOutputStatusSpec(StaticDataMap_for_AnalogOutputStatusSpec *pStaticDataMap_for_AnalogOutputStatusSpec, AnalogOutputStatus *value, uint16_t index, AOStatusConfig *config)
{
  if (pStaticDataMap_for_AnalogOutputStatusSpec->map.find(index) != pStaticDataMap_for_AnalogOutputStatusSpec->map.end())
  {
    return false;
  }

//void  StaticDataCell_for_AnalogOutputStatus_in_StaticDataCell_for_AnalogOutputStatusOver2(StaticDataCell_for_AnalogOutputStatus *pStaticDataCell_for_AnalogOutputStatus,
//    AnalogOutputStatus* value,
//    AnalogOutputStatusConfig* config);
  StaticDataCell_for_AnalogOutputStatus sStaticDataCell;
  StaticDataCell_for_AnalogOutputStatus_in_StaticDataCell_for_AnalogOutputStatusOver2(&sStaticDataCell, value, config);

  pStaticDataMap_for_AnalogOutputStatusSpec->map[index] = sStaticDataCell;////StaticDataCell_for_AnalogOutputStatusSpec{value, config};

  return true;
}
