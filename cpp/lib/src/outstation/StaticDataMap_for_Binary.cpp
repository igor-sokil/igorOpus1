#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include <QApplication>
#include "header.h"
#include "StaticDataMap_for_Binary.h"

void StaticDataMap_for_BinarySpec_in_StaticDataMap_for_BinarySpecOver1(StaticDataMap_for_BinarySpec *pStaticDataMap)
{
  Range_in_RangeOver1(&(pStaticDataMap->selected));
}
////template<class Spec> StaticDataMap<Spec>::StaticDataMap(const std::map<uint16_t, typename Spec::config_t>& config)
void StaticDataMap_for_BinarySpec_in_StaticDataMap_for_BinarySpecOver2(StaticDataMap_for_BinarySpec *pStaticDataMap, std::map<uint16_t, BinaryConfig>& config)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"StaticDataMap_for_BinarySpec_in_StaticDataMap_for_BinarySpecOver2_1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*config.size()= "<<config.size()<<'\n';
#endif

  StaticDataMap_for_BinarySpec_in_StaticDataMap_for_BinarySpecOver1(pStaticDataMap);
  for (const auto& item : config)
  {
//void StaticDataCell_for_Binary_in_StaticDataCell_for_BinaryOver1(StaticDataCell_for_Binary *pStaticDataCell_for_Binary,
//    BinaryConfig* config);
////        pStaticDataMap->map[item.first] = StaticDataCell<Spec>{item.second};
    BinaryConfig temp = item.second;
    StaticDataCell_for_Binary sStaticDataCell_for_Binary;
    StaticDataCell_for_Binary_in_StaticDataCell_for_BinaryOver2(&sStaticDataCell_for_Binary, &temp);
    pStaticDataMap->map[item.first] = sStaticDataCell_for_Binary;
  }
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
}

Range get_selected_range_in_StaticDataMap_for_BinarySpec(StaticDataMap_for_BinarySpec *pStaticDataMap_for_BinarySpec)
{
  return pStaticDataMap_for_BinarySpec->selected;
}

////template<class Spec> void StaticDataMap<Spec>::clear_selection()
void clear_selection_in_StaticDataMap_for_BinarySpec(StaticDataMap_for_BinarySpec *pStaticDataMap_for_BinarySpec)
{
  // the act of iterating clears the selection
  for (auto iter = pStaticDataMap_for_BinarySpec->begin(); iter != pStaticDataMap_for_BinarySpec->end(); ++iter)
  {
  }
}

typename StaticDataMap_for_BinarySpec::iterator StaticDataMap_for_BinarySpec::begin()
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

////template<class Spec> typename StaticDataMap<Spec>::iterator StaticDataMap<Spec>::end()
typename StaticDataMap_for_BinarySpec::iterator StaticDataMap_for_BinarySpec::end()
{
  return iterator(this->map.end(), this->map.end(), this->selected);
}

uint16_t select_all_in_StaticDataMap_for_BinarySpecOver1(StaticDataMap_for_BinarySpec *pStaticDataMap_for_BinarySpec)
{
  return select_all_in_StaticDataMap_for_BinarySpecOver3(pStaticDataMap_for_BinarySpec, [](auto var) {
    return var;
  }); // use the default
}

uint16_t select_all_in_StaticDataMap_for_BinarySpecOver2(StaticDataMap_for_BinarySpec *pStaticDataMap_for_BinarySpec, StaticBinaryVariation_uint8_t variation)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"select_all_in_StaticDataMap_for_BinarySpecOver2_1"<<'\n';
  decrement_stack_info();
#endif

  return select_all_in_StaticDataMap_for_BinarySpecOver3(pStaticDataMap_for_BinarySpec, [variation](auto var) {
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*variation= "<<(uint16_t)variation<<'\n';
    return variation;
  }); // override default
}

////    size_t select(Range range)
uint16_t select_in_StaticDataMap_for_BinarySpecOver1(StaticDataMap_for_BinarySpec *pStaticDataMap_for_BinarySpec, Range range)
{
////        return this->select(range, [](auto var) { return var; }); // use the default
  return select_in_StaticDataMap_for_BinarySpecOver5(pStaticDataMap_for_BinarySpec, range, [](auto var) {
    return var;
  }); // use the default
}

////    bool select(uint16_t index, typename Spec::static_variation_t variation)
boolean select_in_StaticDataMap_for_BinarySpecOver2(StaticDataMap_for_BinarySpec *pStaticDataMap_for_BinarySpec, uint16_t index, StaticBinaryVariation_uint8_t variation)
{
////        return this->select(Range::From(index, index), variation);
  return select_in_StaticDataMap_for_BinarySpecOver4(pStaticDataMap_for_BinarySpec, From_in_Range_static(index, index), variation) == 1;
}

////    bool select(uint16_t index)
boolean select_in_StaticDataMap_for_BinarySpecOver3(StaticDataMap_for_BinarySpec *pStaticDataMap_for_BinarySpec, uint16_t index)
{
////        return this->select(Range::From(index, index)) == 1;
  return select_in_StaticDataMap_for_BinarySpecOver1(pStaticDataMap_for_BinarySpec, From_in_Range_static(index, index)) == 1;
}

////    size_t select(Range range, typename Spec::static_variation_t variation)
uint16_t select_in_StaticDataMap_for_BinarySpecOver4(StaticDataMap_for_BinarySpec *pStaticDataMap_for_BinarySpec, Range range, StaticBinaryVariation_uint8_t variation)
{
////        return this->select(range, [variation](auto var) { return variation; }); // override default
  return select_in_StaticDataMap_for_BinarySpecOver5(pStaticDataMap_for_BinarySpec, range, [variation](auto var) {
    return variation;
  }); // override default
}

boolean update_in_StaticDataMap_for_BinarySpecOver1(StaticDataMap_for_BinarySpec *pStaticDataMap_for_BinarySpec,
    Binary* value,
    uint16_t index,
    EventMode_uint8_t mode,
    IEventReceiver* receiver)
{
//boolean update_in_StaticDataMap_for_BinarySpecOver2(StaticDataMap_for_BinarySpec *pStaticDataMap_for_BinarySpec,
//    map_iter_t_StaticDataMap_for_BinarySpec & iter,
//    Binary* new_value,
//    EventMode_uint8_t mode,
//    IEventReceiver* receiver);
////    return update(this->map.find(index), value, mode, receiver);
  map_iter_t_StaticDataMap_for_BinarySpec  iter = pStaticDataMap_for_BinarySpec->map.find(index);
  return update_in_StaticDataMap_for_BinarySpecOver2(pStaticDataMap_for_BinarySpec,
         iter, value, mode, receiver);
}

boolean update_in_StaticDataMap_for_BinarySpecOver2(StaticDataMap_for_BinarySpec *pStaticDataMap_for_BinarySpec,
    map_iter_t_StaticDataMap_for_BinarySpec & iter,
    Binary* new_value,
    EventMode_uint8_t mode,
    IEventReceiver* receiver)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{update_in_StaticDataMap_for_BinarySpecOver2_1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*iter->second.config.eEventConfig.clazz= "<<(uint16_t)iter->second.config_in_StaticDataCell.eEventConfig.clazz<<'\n';
  std::cout<<"+"<<getString_stack_info();
  std::cout<<"++++++int16_t nnn = iter->first="<<(uint16_t)iter->first<<'\n';
  inspect_Binary(new_value);
#endif
  if (iter == pStaticDataMap_for_BinarySpec->map.end())
  {
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}update_in_StaticDataMap_for_BinarySpecOver2__"<<'\n';
  decrement_stack_info();
#endif
    return false;
  }

  if (mode != EventMode_EventOnly)
  {
    iter->second.value_in_StaticDataCell = *new_value;
  }

  Binary old_value = iter->second.event_in_StaticDataCell.eEventCellBase_for_Binary.lastEvent;
  if (mode == EventMode_Force || mode == EventMode_EventOnly ||
//boolean IsEvent_in_BinarySpec_static(Binary *old_value, Binary *new_value, BinaryConfig *config);
////        Spec::IsEvent(iter->second.event.lastEvent, new_value, iter->second.config))
      IsEvent_in_BinarySpec_static(&old_value, new_value, &(iter->second.config_in_StaticDataCell)))
  {
    iter->second.event_in_StaticDataCell.eEventCellBase_for_Binary.lastEvent = *new_value;
    if (mode != EventMode_Suppress)
    {
      EventClass_uint8_t ec;
//boolean convert_to_event_class_in_StaticDataMap_static(PointClass_uint8_t pc, EventClass_uint8_t* ec);
////            if (convert_to_event_class(iter->second.config.clazz, ec))
      if (convert_to_event_class_in_StaticDataMap_static(iter->second.config_in_StaticDataCell.eEventConfig.clazz, &ec))
      {
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"update_in_StaticDataMap_for_BinarySpecOver2_2"<<'\n';
#endif
//void Event_for_BinarySpec_in_Event_for_BinarySpecOver2(Event_for_BinarySpec *pEvent_for_BinarySpec,
//    Binary* value, uint16_t index,
//    EventClass_uint8_t clazz,
//    event_variation_t_in_BinaryInfo variation);
//void Update_BinarySpec_in_IEventReceiver(IEventReceiver *, Event_for_BinarySpec* evt);
////                receiver.Update(Event<Spec>(new_value, iter->first, ec, iter->second.config.evariation));
        Event_for_BinarySpec eEvent_for_BinarySpec;
        Event_for_BinarySpec_in_Event_for_BinarySpecOver2(&eEvent_for_BinarySpec,
            new_value, iter->first,
            ec,
            iter->second.config_in_StaticDataCell.eEventConfig.evariation);
        Update_BinarySpec_in_IEventReceiver(receiver, &eEvent_for_BinarySpec);

      }
    }
  }

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}update_in_StaticDataMap_for_BinarySpecOver2__"<<'\n';
  decrement_stack_info();
#endif
  return true;
}

////    bool has_any_selection() const
boolean has_any_selection_in_StaticDataMap_for_BinarySpec(StaticDataMap_for_BinarySpec *pStaticDataMap_for_BinarySpec)
{
//boolean IsValid_in_Range(Range *pRange);
////        return this->selected.IsValid();
  return IsValid_in_Range(&(pStaticDataMap_for_BinarySpec->selected));
}

boolean add_in_StaticDataMap_for_BinarySpec(StaticDataMap_for_BinarySpec *pStaticDataMap_for_BinarySpec, Binary *value, uint16_t index, BinaryConfig *config)
{
  if (pStaticDataMap_for_BinarySpec->map.find(index) != pStaticDataMap_for_BinarySpec->map.end())
  {
    return false;
  }

//void  StaticDataCell_for_Binary_in_StaticDataCell_for_BinaryOver3(StaticDataCell_for_Binary *pStaticDataCell_for_Binary,
//    Binary* value,
//    BinaryConfig* config);
  StaticDataCell_for_Binary sStaticDataCell;
  StaticDataCell_for_Binary_in_StaticDataCell_for_BinaryOver3(&sStaticDataCell, value, config);

  pStaticDataMap_for_BinarySpec->map[index] = sStaticDataCell;////StaticDataCell_for_BinarySpec{value, config};

  return true;
}

boolean modify_in_StaticDataMap_for_BinarySpec(StaticDataMap_for_BinarySpec *pStaticDataMap_for_BinarySpec,
    uint16_t start, uint16_t stop, uint8_t flags,
    IEventReceiver* receiver)
{
  if (stop < start)
  {
    return false;
  }

  for (auto iter = pStaticDataMap_for_BinarySpec->map.lower_bound(start); iter != pStaticDataMap_for_BinarySpec->map.end(); ++iter)
  {
    if (iter->first > stop)
    {
      return false;
    }

    Binary new_value = iter->second.value_in_StaticDataCell;
////        new_value.flags = Flags(flags);
    Flags fFlags;
    Flags_In_FlagsOver2(&fFlags, flags);
    new_value.tTypedMeasurement_for_Boolean.mMeasurement.flags = fFlags;
//boolean update_in_StaticDataMap_for_BinarySpecOver2(StaticDataMap_for_BinarySpec *pStaticDataMap_for_BinarySpec,
//    map_iter_t_StaticDataMap_for_BinarySpec & iter,
//    Binary* new_value,
//    EventMode_uint8_t mode,
//    IEventReceiver* receiver);
////        this->update(iter, new_value, EventMode::Detect, receiver);
    update_in_StaticDataMap_for_BinarySpecOver2(pStaticDataMap_for_BinarySpec,
        iter,
        &new_value,
        EventMode_Detect,
        receiver);
  }

  return true;
}

////template<class Spec> Range StaticDataMap<Spec>::get_full_range() const
Range get_full_range_in_StaticDataMap_for_BinarySpec(StaticDataMap_for_BinarySpec *pStaticDataMap_for_BinarySpec)
{
//Range From_in_Range_static(uint16_t start, uint16_t stop);
//Range Invalid_in_Range_static(void);
////    return this->map.empty() ? Range::Invalid() : Range::From(this->map.begin()->first, this->map.rbegin()->first);
  return pStaticDataMap_for_BinarySpec->map.empty() ? Invalid_in_Range_static() : 
         From_in_Range_static(pStaticDataMap_for_BinarySpec->map.begin()->first, pStaticDataMap_for_BinarySpec->map.rbegin()->first);
}

////template<class Spec> Range StaticDataMap<Spec>::assign_class(PointClass clazz)
Range assign_class_in_StaticDataMap_for_BinarySpecOver1(StaticDataMap_for_BinarySpec *pStaticDataMap_for_BinarySpec, PointClass_uint8_t clazz)
{
  for (auto& elem : pStaticDataMap_for_BinarySpec->map)
  {
    elem.second.config_in_StaticDataCell.eEventConfig.clazz = clazz;
  }

////    return this->get_full_range();
  return get_full_range_in_StaticDataMap_for_BinarySpec(pStaticDataMap_for_BinarySpec);
}

Range assign_class_in_StaticDataMap_for_BinarySpecOver2(StaticDataMap_for_BinarySpec *pStaticDataMap_for_BinarySpec, PointClass_uint8_t clazz, Range* range)
{
  for (auto iter = pStaticDataMap_for_BinarySpec->map.lower_bound(range->start); iter != pStaticDataMap_for_BinarySpec->map.end() &&
////             range.Contains(iter->first);
       Contains_in_Range(range, iter->first); iter++)
  {
    iter->second.config_in_StaticDataCell.eEventConfig.clazz = clazz;
  }

//Range get_full_range_in_StaticDataMap_for_BinarySpec(StaticDataMap_for_BinarySpec *pStaticDataMap_for_BinarySpec);
//Range Intersection_in_Range(Range *pRange, Range* other);
////    return range.Intersection(this->get_full_range());
  Range temp = get_full_range_in_StaticDataMap_for_BinarySpec(pStaticDataMap_for_BinarySpec);
  return Intersection_in_Range(range, &temp);
}
