#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include <QApplication>
#include "header.h"
#include "StaticDataMap_for_FrozenCounter.h"

void StaticDataMap_for_FrozenCounterSpec_in_StaticDataMap_for_FrozenCounterSpecOver1(StaticDataMap_for_FrozenCounterSpec *pStaticDataMap)
{
  Range_in_RangeOver1(&(pStaticDataMap->selected));
}
////template<class Spec> StaticDataMap<Spec>::StaticDataMap(const std::map<uint16_t, typename Spec::config_t>& config)
void StaticDataMap_for_FrozenCounterSpec_in_StaticDataMap_for_FrozenCounterSpecOver2(StaticDataMap_for_FrozenCounterSpec *pStaticDataMap, std::map<uint16_t, FrozenCounterConfig>& config)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"StaticDataMap_for_FrozenCounterSpec_in_StaticDataMap_for_FrozenCounterSpecOver2_1"<<'\n';
  decrement_stack_info();
#endif

  StaticDataMap_for_FrozenCounterSpec_in_StaticDataMap_for_FrozenCounterSpecOver1(pStaticDataMap);
  for (const auto& item : config)
  {
//void StaticDataCell_for_FrozenCounter_in_StaticDataCell_for_FrozenCounterOver1(StaticDataCell_for_FrozenCounter *pStaticDataCell_for_FrozenCounter,
//    FrozenCounterConfig* config);
////        pStaticDataMap->map[item.first] = StaticDataCell<Spec>{item.second};
    FrozenCounterConfig temp = item.second;
    StaticDataCell_for_FrozenCounter sStaticDataCell_for_FrozenCounter;
    StaticDataCell_for_FrozenCounter_in_StaticDataCell_for_FrozenCounterOver2(&sStaticDataCell_for_FrozenCounter, &temp);
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

////    size_t select(Range range)
uint16_t select_in_StaticDataMap_for_FrozenCounterSpecOver1(StaticDataMap_for_FrozenCounterSpec *pStaticDataMap_for_FrozenCounterSpec, Range range)
{
////        return this->select(range, [](auto var) { return var; }); // use the default
  return select_in_StaticDataMap_for_FrozenCounterSpecOver5(pStaticDataMap_for_FrozenCounterSpec, range, [](auto var) {
    return var;
  }); // use the default
}

////    bool select(uint16_t index, typename Spec::static_variation_t variation)
boolean select_in_StaticDataMap_for_FrozenCounterSpecOver2(StaticDataMap_for_FrozenCounterSpec *pStaticDataMap_for_FrozenCounterSpec, uint16_t index, StaticFrozenCounterVariation_uint8_t variation)
{
////        return this->select(Range::From(index, index), variation);
  return select_in_StaticDataMap_for_FrozenCounterSpecOver4(pStaticDataMap_for_FrozenCounterSpec, From_in_Range_static(index, index), variation) == 1;
}

////    bool select(uint16_t index)
boolean select_in_StaticDataMap_for_FrozenCounterSpecOver3(StaticDataMap_for_FrozenCounterSpec *pStaticDataMap_for_FrozenCounterSpec, uint16_t index)
{
////        return this->select(Range::From(index, index)) == 1;
  return select_in_StaticDataMap_for_FrozenCounterSpecOver1(pStaticDataMap_for_FrozenCounterSpec, From_in_Range_static(index, index)) == 1;
}

////    size_t select(Range range, typename Spec::static_variation_t variation)
uint16_t select_in_StaticDataMap_for_FrozenCounterSpecOver4(StaticDataMap_for_FrozenCounterSpec *pStaticDataMap_for_FrozenCounterSpec, Range range, StaticFrozenCounterVariation_uint8_t variation)
{
////        return this->select(range, [variation](auto var) { return variation; }); // override default
  return select_in_StaticDataMap_for_FrozenCounterSpecOver5(pStaticDataMap_for_FrozenCounterSpec, range, [variation](auto var) {
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

////    bool has_any_selection() const
boolean has_any_selection_in_StaticDataMap_for_FrozenCounterSpec(StaticDataMap_for_FrozenCounterSpec *pStaticDataMap_for_FrozenCounterSpec)
{
//boolean IsValid_in_Range(Range *pRange);
////        return this->selected.IsValid();
 return IsValid_in_Range(&(pStaticDataMap_for_FrozenCounterSpec->selected));
}

boolean add_in_StaticDataMap_for_FrozenCounterSpec(StaticDataMap_for_FrozenCounterSpec *pStaticDataMap_for_FrozenCounterSpec, FrozenCounter *value, uint16_t index, FrozenCounterConfig *config)
{
  if (pStaticDataMap_for_FrozenCounterSpec->map.find(index) != pStaticDataMap_for_FrozenCounterSpec->map.end())
  {
    return false;
  }

//void  StaticDataCell_for_FrozenCounter_in_StaticDataCell_for_FrozenCounterOver3(StaticDataCell_for_FrozenCounter *pStaticDataCell_for_FrozenCounter,
//    FrozenCounter* value,
//    FrozenCounterConfig* config);
  StaticDataCell_for_FrozenCounter sStaticDataCell;
  StaticDataCell_for_FrozenCounter_in_StaticDataCell_for_FrozenCounterOver3(&sStaticDataCell, value, config);

  pStaticDataMap_for_FrozenCounterSpec->map[index] = sStaticDataCell;////StaticDataCell_for_FrozenCounterSpec{value, config};

  return true;
}

boolean modify_in_StaticDataMap_for_FrozenCounterSpec(StaticDataMap_for_FrozenCounterSpec *pStaticDataMap_for_FrozenCounterSpec,
    uint16_t start, uint16_t stop, uint8_t flags,
    IEventReceiver* receiver)
{
  if (stop < start)
  {
    return false;
  }

  for (auto iter = pStaticDataMap_for_FrozenCounterSpec->map.lower_bound(start); iter != pStaticDataMap_for_FrozenCounterSpec->map.end(); ++iter)
  {
    if (iter->first > stop)
    {
      return false;
    }

    FrozenCounter new_value = iter->second.value;
////        new_value.flags = Flags(flags);
    Flags fFlags;
    Flags_In_FlagsOver2(&fFlags, flags);
    new_value.tTypedMeasurement_for_Uint32.mMeasurement.flags = fFlags;
//boolean update_in_StaticDataMap_for_FrozenCounterSpecOver2(StaticDataMap_for_FrozenCounterSpec *pStaticDataMap_for_FrozenCounterSpec,
//    map_iter_t_StaticDataMap_for_FrozenCounterSpec & iter,
//    FrozenCounter* new_value,
//    EventMode_uint8_t mode,
//    IEventReceiver* receiver);
////        this->update(iter, new_value, EventMode::Detect, receiver);
    update_in_StaticDataMap_for_FrozenCounterSpecOver2(pStaticDataMap_for_FrozenCounterSpec,
        iter,
        &new_value,
        EventMode_Detect,
        receiver);
  }

  return true;
}

////template<class Spec> Range StaticDataMap<Spec>::get_full_range() const
Range get_full_range_in_StaticDataMap_for_FrozenCounterSpec(StaticDataMap_for_FrozenCounterSpec *pStaticDataMap_for_FrozenCounterSpec)
{
//Range From_in_Range_static(uint16_t start, uint16_t stop);
//Range Invalid_in_Range_static(void);
////    return this->map.empty() ? Range::Invalid() : Range::From(this->map.begin()->first, this->map.rbegin()->first);
  return pStaticDataMap_for_FrozenCounterSpec->map.empty() ? Invalid_in_Range_static() : 
         From_in_Range_static(pStaticDataMap_for_FrozenCounterSpec->map.begin()->first, pStaticDataMap_for_FrozenCounterSpec->map.rbegin()->first);
}

////template<class Spec> Range StaticDataMap<Spec>::assign_class(PointClass clazz)
Range assign_class_in_StaticDataMap_for_FrozenCounterSpecOver1(StaticDataMap_for_FrozenCounterSpec *pStaticDataMap_for_FrozenCounterSpec, PointClass_uint8_t clazz)
{
  for (auto& elem : pStaticDataMap_for_FrozenCounterSpec->map)
  {
    elem.second.config.dDeadbandConfig_for_FrozenCounterInfo.eEventConfig.clazz = clazz;
  }

////    return this->get_full_range();
  return get_full_range_in_StaticDataMap_for_FrozenCounterSpec(pStaticDataMap_for_FrozenCounterSpec);
}
