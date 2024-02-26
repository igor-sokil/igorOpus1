#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include <QApplication>
#include "header.h"
#include "StaticDataMap_for_Counter.h"

void StaticDataMap_for_CounterSpec_in_StaticDataMap_for_CounterSpecOver1(StaticDataMap_for_CounterSpec *pStaticDataMap)
{
  Range_in_RangeOver1(&(pStaticDataMap->selected));
}
////template<class Spec> StaticDataMap<Spec>::StaticDataMap(const std::map<uint16_t, typename Spec::config_t>& config)
void StaticDataMap_for_CounterSpec_in_StaticDataMap_for_CounterSpecOver2(StaticDataMap_for_CounterSpec *pStaticDataMap, std::map<uint16_t, CounterConfig>& config)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"StaticDataMap_for_CounterSpec_in_StaticDataMap_for_CounterSpecOver2_1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*config.size()= "<<config.size()<<'\n';
#endif

  StaticDataMap_for_CounterSpec_in_StaticDataMap_for_CounterSpecOver1(pStaticDataMap);
  for (const auto& item : config)
  {
//void StaticDataCell_for_Counter_in_StaticDataCell_for_CounterOver1(StaticDataCell_for_Counter *pStaticDataCell_for_Counter,
//    CounterConfig* config);
////        pStaticDataMap->map[item.first] = StaticDataCell<Spec>{item.second};
    CounterConfig temp = item.second;
    StaticDataCell_for_Counter sStaticDataCell_for_Counter;
    StaticDataCell_for_Counter_in_StaticDataCell_for_CounterOver2(&sStaticDataCell_for_Counter, &temp);
    pStaticDataMap->map[item.first] = sStaticDataCell_for_Counter;
  }
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
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

////    size_t select(Range range)
uint16_t select_in_StaticDataMap_for_CounterSpecOver1(StaticDataMap_for_CounterSpec *pStaticDataMap_for_CounterSpec, Range range)
{
////        return this->select(range, [](auto var) { return var; }); // use the default
  return select_in_StaticDataMap_for_CounterSpecOver5(pStaticDataMap_for_CounterSpec, range, [](auto var) {
    return var;
  }); // use the default
}

////    bool select(uint16_t index, typename Spec::static_variation_t variation)
boolean select_in_StaticDataMap_for_CounterSpecOver2(StaticDataMap_for_CounterSpec *pStaticDataMap_for_CounterSpec, uint16_t index, StaticCounterVariation_uint8_t variation)
{
////        return this->select(Range::From(index, index), variation);
  return select_in_StaticDataMap_for_CounterSpecOver4(pStaticDataMap_for_CounterSpec, From_in_Range_static(index, index), variation) == 1;
}

////    bool select(uint16_t index)
boolean select_in_StaticDataMap_for_CounterSpecOver3(StaticDataMap_for_CounterSpec *pStaticDataMap_for_CounterSpec, uint16_t index)
{
////        return this->select(Range::From(index, index)) == 1;
  return select_in_StaticDataMap_for_CounterSpecOver1(pStaticDataMap_for_CounterSpec, From_in_Range_static(index, index)) == 1;
}

////    size_t select(Range range, typename Spec::static_variation_t variation)
uint16_t select_in_StaticDataMap_for_CounterSpecOver4(StaticDataMap_for_CounterSpec *pStaticDataMap_for_CounterSpec, Range range, StaticCounterVariation_uint8_t variation)
{
////        return this->select(range, [variation](auto var) { return variation; }); // override default
  return select_in_StaticDataMap_for_CounterSpecOver5(pStaticDataMap_for_CounterSpec, range, [variation](auto var) {
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
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{update_in_StaticDataMap_for_CounterSpecOver2_1"<<'\n';
  inspect_Counter(new_value);
  std::cout<<"*"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*EventMode_uint8_t mode= "<<(uint16_t)mode<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*EventMode_Force= "<<(uint16_t)EventMode_Force<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*EventMode_EventOnly= "<<(uint16_t)EventMode_EventOnly<<'\n';
#endif

  if (iter == pStaticDataMap_for_CounterSpec->map.end())
  {
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}update_in_StaticDataMap_for_CounterSpecOver2_1_"<<'\n';
  decrement_stack_info();
#endif
    return false;
  }

  if (mode != EventMode_EventOnly)
  {
    iter->second.value_in_StaticDataCell = *new_value;
  }

  Counter old_value = iter->second.event_in_StaticDataCell.eEventCellBase_for_Counter.lastEvent;

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"update_in_StaticDataMap_for_CounterSpecOver2_2"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*inspect_Counter(&old_value)"<<'\n';
  inspect_Counter(&old_value);
#endif

  if (mode == EventMode_Force || mode == EventMode_EventOnly ||
//boolean IsEvent_in_CounterSpec_static(Counter *old_value, Counter *new_value, CounterConfig *config);
////        Spec::IsEvent(iter->second.event.lastEvent, new_value, iter->second.config))
      IsEvent_in_CounterSpec_static(&old_value, new_value, &(iter->second.config_in_StaticDataCell)))
  {
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"update_in_StaticDataMap_for_CounterSpecOver2_3"<<'\n';
#endif

    iter->second.event_in_StaticDataCell.eEventCellBase_for_Counter.lastEvent = *new_value;
    if (mode != EventMode_Suppress)
    {
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"update_in_StaticDataMap_for_CounterSpecOver2_4"<<'\n';
#endif

      EventClass_uint8_t ec;
//boolean convert_to_event_class_in_StaticDataMap_static(PointClass_uint8_t pc, EventClass_uint8_t* ec);
////            if (convert_to_event_class(iter->second.config.clazz, ec))
      if (convert_to_event_class_in_StaticDataMap_static(iter->second.config_in_StaticDataCell.dDeadbandConfig_for_CounterInfo.eEventConfig.clazz, &ec))
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
            iter->second.config_in_StaticDataCell.dDeadbandConfig_for_CounterInfo.eEventConfig.evariation);
        Update_CounterSpec_in_IEventReceiver(receiver, &eEvent_for_CounterSpec);

      }
    }
  }

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}update_in_StaticDataMap_for_CounterSpecOver2_2_"<<'\n';
  decrement_stack_info();
#endif
  return true;
}

////    bool has_any_selection() const
boolean has_any_selection_in_StaticDataMap_for_CounterSpec(StaticDataMap_for_CounterSpec *pStaticDataMap_for_CounterSpec)
{
//boolean IsValid_in_Range(Range *pRange);
////        return this->selected.IsValid();
 return IsValid_in_Range(&(pStaticDataMap_for_CounterSpec->selected));
}

boolean add_in_StaticDataMap_for_CounterSpec(StaticDataMap_for_CounterSpec *pStaticDataMap_for_CounterSpec, Counter *value, uint16_t index, CounterConfig *config)
{
  if (pStaticDataMap_for_CounterSpec->map.find(index) != pStaticDataMap_for_CounterSpec->map.end())
  {
    return false;
  }

//void  StaticDataCell_for_Counter_in_StaticDataCell_for_CounterOver3(StaticDataCell_for_Counter *pStaticDataCell_for_Counter,
//    Counter* value,
//    CounterConfig* config);
  StaticDataCell_for_Counter sStaticDataCell;
  StaticDataCell_for_Counter_in_StaticDataCell_for_CounterOver3(&sStaticDataCell, value, config);

  pStaticDataMap_for_CounterSpec->map[index] = sStaticDataCell;////StaticDataCell_for_CounterSpec{value, config};

  return true;
}

boolean modify_in_StaticDataMap_for_CounterSpec(StaticDataMap_for_CounterSpec *pStaticDataMap_for_CounterSpec,
    uint16_t start, uint16_t stop, uint8_t flags,
    IEventReceiver* receiver)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{modify_in_StaticDataMap_for_CounterSpec1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*uint16_t start= "<<start<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*uint16_t stop= "<<stop<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*uint8_t flags= "<<(uint16_t)flags<<'\n';
#endif

  if (stop < start)
  {
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}modify_in_StaticDataMap_for_CounterSpec1_"<<'\n';
  decrement_stack_info();
#endif
    return false;
  }

  for (auto iter = pStaticDataMap_for_CounterSpec->map.lower_bound(start); iter != pStaticDataMap_for_CounterSpec->map.end(); ++iter)
  {
    if (iter->first > stop)
    {
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}modify_in_StaticDataMap_for_CounterSpec2_"<<'\n';
  decrement_stack_info();
#endif
      return false;
    }

    Counter new_value = iter->second.value_in_StaticDataCell;
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"*modify_in_StaticDataMap_for_CounterSpec2"<<'\n';
  inspect_Counter(&new_value);
#endif

////        new_value.flags = Flags(flags);
    Flags fFlags;
    Flags_In_FlagsOver2(&fFlags, flags);
    new_value.tTypedMeasurement_for_Uint32.mMeasurement.flags = fFlags;
//boolean update_in_StaticDataMap_for_CounterSpecOver2(StaticDataMap_for_CounterSpec *pStaticDataMap_for_CounterSpec,
//    map_iter_t_StaticDataMap_for_CounterSpec & iter,
//    Counter* new_value,
//    EventMode_uint8_t mode,
//    IEventReceiver* receiver);
////        this->update(iter, new_value, EventMode::Detect, receiver);
    update_in_StaticDataMap_for_CounterSpecOver2(pStaticDataMap_for_CounterSpec,
        iter,
        &new_value,
        EventMode_Detect,
        receiver);
  }

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}modify_in_StaticDataMap_for_CounterSpec3_"<<'\n';
  decrement_stack_info();
#endif
  return true;
}

////template<class Spec> Range StaticDataMap<Spec>::get_full_range() const
Range get_full_range_in_StaticDataMap_for_CounterSpec(StaticDataMap_for_CounterSpec *pStaticDataMap_for_CounterSpec)
{
//Range From_in_Range_static(uint16_t start, uint16_t stop);
//Range Invalid_in_Range_static(void);
////    return this->map.empty() ? Range::Invalid() : Range::From(this->map.begin()->first, this->map.rbegin()->first);
  return pStaticDataMap_for_CounterSpec->map.empty() ? Invalid_in_Range_static() : 
         From_in_Range_static(pStaticDataMap_for_CounterSpec->map.begin()->first, pStaticDataMap_for_CounterSpec->map.rbegin()->first);
}

////template<class Spec> Range StaticDataMap<Spec>::assign_class(PointClass clazz)
Range assign_class_in_StaticDataMap_for_CounterSpecOver1(StaticDataMap_for_CounterSpec *pStaticDataMap_for_CounterSpec, PointClass_uint8_t clazz)
{
  for (auto& elem : pStaticDataMap_for_CounterSpec->map)
  {
    elem.second.config_in_StaticDataCell.dDeadbandConfig_for_CounterInfo.eEventConfig.clazz = clazz;
  }

////    return this->get_full_range();
  return get_full_range_in_StaticDataMap_for_CounterSpec(pStaticDataMap_for_CounterSpec);
}

Range assign_class_in_StaticDataMap_for_CounterSpecOver2(StaticDataMap_for_CounterSpec *pStaticDataMap_for_CounterSpec, PointClass_uint8_t clazz, Range* range)
{
  for (auto iter = pStaticDataMap_for_CounterSpec->map.lower_bound(range->start); iter != pStaticDataMap_for_CounterSpec->map.end() &&
////             range.Contains(iter->first);
       Contains_in_Range(range, iter->first); iter++)
  {
    iter->second.config_in_StaticDataCell.dDeadbandConfig_for_CounterInfo.eEventConfig.clazz = clazz;
  }

//Range get_full_range_in_StaticDataMap_for_CounterSpec(StaticDataMap_for_CounterSpec *pStaticDataMap_for_CounterSpec);
//Range Intersection_in_Range(Range *pRange, Range* other);
////    return range.Intersection(this->get_full_range());
  Range temp = get_full_range_in_StaticDataMap_for_CounterSpec(pStaticDataMap_for_CounterSpec);
  return Intersection_in_Range(range, &temp);
}
