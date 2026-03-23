#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include <QApplication>
#include "header.h"
#include "StaticDataMap_for_Analog.h"

void StaticDataMap_for_AnalogSpec_in_StaticDataMap_for_AnalogSpecOver1(StaticDataMap_for_AnalogSpec *pStaticDataMap)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{StaticDataMap_for_AnalogSpec_in_StaticDataMap_for_AnalogSpecOver1"<<'\n';
#endif
  Range_in_RangeOver1(&(pStaticDataMap->selected_in_StaticDataMap_for_AnalogSpec));
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}StaticDataMap_for_AnalogSpec_in_StaticDataMap_for_AnalogSpecOver_"<<'\n';
  decrement_stack_info();
#endif
}

////template<class Spec> StaticDataMap<Spec>::StaticDataMap(const std::map<uint16_t, typename Spec::config_t>& config)
void StaticDataMap_for_AnalogSpec_in_StaticDataMap_for_AnalogSpecOver2(StaticDataMap_for_AnalogSpec *pStaticDataMap, std::map<uint16_t, AnalogConfig>& config)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"StaticDataMap_for_AnalogSpec_in_StaticDataMap_for_AnalogSpecOver2_1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*config.size()= "<<config.size()<<'\n';
#endif

  StaticDataMap_for_AnalogSpec_in_StaticDataMap_for_AnalogSpecOver1(pStaticDataMap);
  for (const auto& item : config)
  {
//void StaticDataCell_for_Analog_in_StaticDataCell_for_AnalogOver1(StaticDataCell_for_Analog *pStaticDataCell_for_Analog,
//    AnalogConfig* config);
////        pStaticDataMap->map[item.first] = StaticDataCell<Spec>{item.second};
    AnalogConfig temp = item.second;
    StaticDataCell_for_Analog sStaticDataCell_for_Analog;
    StaticDataCell_for_Analog_in_StaticDataCell_for_AnalogOver2(&sStaticDataCell_for_Analog, &temp);
    pStaticDataMap->map[item.first] = sStaticDataCell_for_Analog;
  }
/*
////!
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"StaticDataMap_for_AnalogMrzs_in_StaticDataMap_for_AnalogMrzsOver2_1"<<'\n';
#endif
  StaticDataMap_for_AnalogMrzs_in_StaticDataMap_for_AnalogMrzsOver1(pStaticDataMap_for_AnalogMrzs, getDatabaseConfigMrzs()->sizeConfig_for_AnalogMrzs);
  if(pStaticDataMap_for_AnalogMrzs->sizeMap_for_AnalogMrzs > SIZE_map_StaticDataMap_for_AnalogMrzs) pStaticDataMap_for_AnalogMrzs->sizeMap_for_AnalogMrzs = SIZE_map_StaticDataMap_for_AnalogMrzs;

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"*StaticDataMap_for_AnalogMrzs_in_StaticDataMap_for_AnalogMrzsOver2_2"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*pStaticDataMap_for_AnalogMrzs->sizeMap_for_AnalogMrzs= "<<pStaticDataMap_for_AnalogMrzs->sizeMap_for_AnalogMrzs<<'\n';
#endif

// Increment_in_Iterator_StaticDataMap_for_AnalogMrzs(&(pStaticDataMap_for_AnalogMrzs->iIterator_StaticDataMap_for_AnalogMrzs));

  for(uint16_t index=0; index<pStaticDataMap_for_AnalogMrzs->sizeMap_for_AnalogMrzs; index++)
  {
    StaticDataRecord_for_Analog sStaticDataRecord_for_Analog;
    AnalogConfig temp = getDatabaseConfigMrzs()->analog_input[index];
    StaticDataRecord_for_Analog_in_StaticDataRecord_for_Analog(&sStaticDataRecord_for_Analog, index);
    StaticDataCell_for_Analog_in_StaticDataCell_for_AnalogOver2(&sStaticDataRecord_for_Analog.sStaticDataCell_for_Analog, &temp);
    pStaticDataMap_for_AnalogMrzs->map_StaticDataMap_for_AnalogMrzs[index] = sStaticDataRecord_for_Analog;
  }//for
*/
////!

#ifdef  LOG_INFO
  decrement_stack_info();
#endif
}

Range get_selected_range_in_StaticDataMap_for_AnalogSpec(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec)
{
  return pStaticDataMap_for_AnalogSpec->selected_in_StaticDataMap_for_AnalogSpec;
}

typename StaticDataMap_for_AnalogSpec::iterator StaticDataMap_for_AnalogSpec::begin()
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{iterator StaticDataMap_for_AnalogSpec::begin()"<<'\n';
#endif
//boolean IsValid_in_Range(Range *pRange);
////    if (!this->selected.IsValid())
  if (!IsValid_in_Range(&(this->selected_in_StaticDataMap_for_AnalogSpec)))
  {
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}iterator StaticDataMap_for_AnalogSpec::begin()1_"<<'\n';
  decrement_stack_info();
#endif
    return iterator(this->map.end(), this->map.end(), this->selected_in_StaticDataMap_for_AnalogSpec);
  }

  const auto begin = this->map.lower_bound(this->selected_in_StaticDataMap_for_AnalogSpec.start);

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}iterator StaticDataMap_for_AnalogSpec::begin()2_"<<'\n';
  decrement_stack_info();
#endif
  return iterator(begin, this->map.end(), this->selected_in_StaticDataMap_for_AnalogSpec);
}

////template<class Spec> void StaticDataMap<Spec>::clear_selection()
void clear_selection_in_StaticDataMap_for_AnalogSpec(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{clear_selection_in_StaticDataMap_for_AnalogSpec1"<<'\n';
#endif
  // the act of iterating clears the selection
  for (auto iter = pStaticDataMap_for_AnalogSpec->begin(); iter != pStaticDataMap_for_AnalogSpec->end(); ++iter)
  {
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"*clear_selection_in_StaticDataMap_for_AnalogSpec2"<<'\n';
#endif

  }
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}clear_selection_in_StaticDataMap_for_AnalogSpec_"<<'\n';
  decrement_stack_info();
#endif
}

////template<class Spec> typename StaticDataMap<Spec>::iterator StaticDataMap<Spec>::end()
typename StaticDataMap_for_AnalogSpec::iterator StaticDataMap_for_AnalogSpec::end()
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{iterator StaticDataMap_for_AnalogSpec::end()1"<<'\n';
#endif
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}iterator StaticDataMap_for_AnalogSpec::end()_"<<'\n';
  decrement_stack_info();
#endif
  return iterator(this->map.end(), this->map.end(), this->selected_in_StaticDataMap_for_AnalogSpec);
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
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{update_in_StaticDataMap_for_AnalogSpecOver1_1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*uint16_t index= "<<index<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*pStaticDataMap_for_AnalogSpec->map.size()= "<<pStaticDataMap_for_AnalogSpec->map.size()<<'\n';
#endif
//boolean update_in_StaticDataMap_for_AnalogSpecOver2(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec,
//    map_iter_t_StaticDataMap_for_AnalogSpec & iter,
//    Analog* new_value,
//    EventMode_uint8_t mode,
//    IEventReceiver* receiver);
////    return update(this->map.find(index), value, mode, receiver);
  map_iter_t_StaticDataMap_for_AnalogSpec  iter = pStaticDataMap_for_AnalogSpec->map.find(index);
  boolean tmp = update_in_StaticDataMap_for_AnalogSpecOver2(pStaticDataMap_for_AnalogSpec, iter, value, mode, receiver);

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}update_in_StaticDataMap_for_AnalogSpecOver1__"<<'\n';
  decrement_stack_info();
#endif
  return tmp;
}

boolean update_in_StaticDataMap_for_AnalogSpecOver2(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec,
    map_iter_t_StaticDataMap_for_AnalogSpec & iter,
    Analog* new_value,
    EventMode_uint8_t mode,
    IEventReceiver* receiver)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{update_in_StaticDataMap_for_AnalogSpecOver2_1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*inspect_Analog(new_value)"<<'\n';
  inspect_Analog(new_value);
  std::cout<<"*"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*EventMode_uint8_t mode= "<<(uint16_t)mode<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*EventMode_Force= "<<(uint16_t)EventMode_Force<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*EventMode_EventOnly= "<<(uint16_t)EventMode_EventOnly<<'\n';
#endif

  if (iter == pStaticDataMap_for_AnalogSpec->map.end())
  {
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}update_in_StaticDataMap_for_AnalogSpecOver21_"<<'\n';
  decrement_stack_info();
#endif
    return false;
  }

StaticDataCell_for_Analog ttt = iter->second;////!

  if (mode != EventMode_EventOnly)
  {
    iter->second.value_in_StaticDataCell = *new_value;
  }

  Analog old_value = iter->second.event_in_StaticDataCell.eEventCellBase_for_Analog.lastEvent_in_EventCellBase;
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"update_in_StaticDataMap_for_AnalogSpecOver2_2"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*inspect_Analog(&old_value)"<<'\n';
  inspect_Analog(&old_value);
#endif

  if (mode == EventMode_Force || mode == EventMode_EventOnly ||
//boolean IsEvent_in_AnalogSpec_static(Analog *old_value, Analog *new_value, AnalogConfig *config);
////        Spec::IsEvent(iter->second.event.lastEvent, new_value, iter->second.config))
      IsEvent_in_AnalogSpec_static(&old_value, new_value, &(iter->second.config_in_StaticDataCell)))
  {
    iter->second.event_in_StaticDataCell.eEventCellBase_for_Analog.lastEvent_in_EventCellBase = *new_value;
    if (mode != EventMode_Suppress)
    {
      EventClass_uint8_t ec;
//boolean convert_to_event_class_in_StaticDataMap_static(PointClass_uint8_t pc, EventClass_uint8_t* ec);
////            if (convert_to_event_class(iter->second.config.clazz, ec))
      if (convert_to_event_class_in_StaticDataMap_static(iter->second.config_in_StaticDataCell.dDeadbandConfig_for_AnalogInfo.eEventConfig.clazz, &ec))
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
            iter->second.config_in_StaticDataCell.dDeadbandConfig_for_AnalogInfo.eEventConfig.evariation);
        Update_AnalogSpec_in_IEventReceiver(receiver, &eEvent_for_AnalogSpec);

      }
    }
  }

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}update_in_StaticDataMap_for_AnalogSpecOver22_"<<'\n';
  decrement_stack_info();
#endif
  return true;
}

////    bool has_any_selection() const
boolean has_any_selection_in_StaticDataMap_for_AnalogSpec(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec)
{
//boolean IsValid_in_Range(Range *pRange);
////        return this->selected.IsValid();
  return IsValid_in_Range(&(pStaticDataMap_for_AnalogSpec->selected_in_StaticDataMap_for_AnalogSpec));
}

boolean add_in_StaticDataMap_for_AnalogSpec(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec, Analog *value, uint16_t index, AnalogConfig *config)
{
  if (pStaticDataMap_for_AnalogSpec->map.find(index) != pStaticDataMap_for_AnalogSpec->map.end())
  {
    return false;
  }

//void  StaticDataCell_for_Analog_in_StaticDataCell_for_AnalogOver3(StaticDataCell_for_Analog *pStaticDataCell_for_Analog,
//    Analog* value,
//    AnalogConfig* config);
  StaticDataCell_for_Analog sStaticDataCell;
  StaticDataCell_for_Analog_in_StaticDataCell_for_AnalogOver3(&sStaticDataCell, value, config);

  pStaticDataMap_for_AnalogSpec->map[index] = sStaticDataCell;////StaticDataCell_for_AnalogSpec{value, config};

  return true;
}

boolean modify_in_StaticDataMap_for_AnalogSpec(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec,
    uint16_t start, uint16_t stop, uint8_t flags,
    IEventReceiver* receiver)
{
  if (stop < start)
  {
    return false;
  }

  for (auto iter = pStaticDataMap_for_AnalogSpec->map.lower_bound(start); iter != pStaticDataMap_for_AnalogSpec->map.end(); ++iter)
  {
    if (iter->first > stop)
    {
      return false;
    }

    Analog new_value = iter->second.value_in_StaticDataCell;
////        new_value.flags = Flags(flags);
    Flags fFlags;
    Flags_In_FlagsOver2(&fFlags, flags);
    new_value.tTypedMeasurement_for_Double64.mMeasurement.flags = fFlags;
//boolean update_in_StaticDataMap_for_AnalogSpecOver2(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec,
//    map_iter_t_StaticDataMap_for_AnalogSpec & iter,
//    Analog* new_value,
//    EventMode_uint8_t mode,
//    IEventReceiver* receiver);
////        this->update(iter, new_value, EventMode::Detect, receiver);
    update_in_StaticDataMap_for_AnalogSpecOver2(pStaticDataMap_for_AnalogSpec,
        iter,
        &new_value,
        EventMode_Detect,
        receiver);
  }

  return true;
}

////template<class Spec> Range StaticDataMap<Spec>::get_full_range() const
Range get_full_range_in_StaticDataMap_for_AnalogSpec(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{get_full_range_in_StaticDataMap_for_AnalogSpec1"<<'\n';
#endif
//Range From_in_Range_static(uint16_t start, uint16_t stop);
//Range Invalid_in_Range_static(void);
////    return this->map.empty() ? Range::Invalid() : Range::From(this->map.begin()->first, this->map.rbegin()->first);
  Range tmp = pStaticDataMap_for_AnalogSpec->map.empty() ? Invalid_in_Range_static() :
         From_in_Range_static(pStaticDataMap_for_AnalogSpec->map.begin()->first, pStaticDataMap_for_AnalogSpec->map.rbegin()->first);
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}get_full_range_in_StaticDataMap_for_AnalogSpec_"<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*Range tmp.start= "<<tmp.start<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*Range tmp.stop= "<<tmp.stop<<'\n';
  decrement_stack_info();
#endif
  return tmp;
}

////template<class Spec> Range StaticDataMap<Spec>::assign_class(PointClass clazz)
Range assign_class_in_StaticDataMap_for_AnalogSpecOver1(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec, PointClass_uint8_t clazz)
{
  for (auto& elem : pStaticDataMap_for_AnalogSpec->map)
  {
    elem.second.config_in_StaticDataCell.dDeadbandConfig_for_AnalogInfo.eEventConfig.clazz = clazz;
  }

////    return this->get_full_range();
  return get_full_range_in_StaticDataMap_for_AnalogSpec(pStaticDataMap_for_AnalogSpec);
}

////template<class Spec> Range StaticDataMap<Spec>::assign_class(PointClass clazz, const Range& range)
Range assign_class_in_StaticDataMap_for_AnalogSpecOver2(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec, PointClass_uint8_t clazz, Range* range)
{
  for (auto iter = pStaticDataMap_for_AnalogSpec->map.lower_bound(range->start); iter != pStaticDataMap_for_AnalogSpec->map.end() &&
////             range.Contains(iter->first);
       Contains_in_Range(range, iter->first); iter++)
  {
    iter->second.config_in_StaticDataCell.dDeadbandConfig_for_AnalogInfo.eEventConfig.clazz = clazz;
  }

//Range get_full_range_in_StaticDataMap_for_AnalogSpec(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec);
//Range Intersection_in_Range(Range *pRange, Range* other);
////    return range.Intersection(this->get_full_range());
  Range temp = get_full_range_in_StaticDataMap_for_AnalogSpec(pStaticDataMap_for_AnalogSpec);
  return Intersection_in_Range(range, &temp);
}
