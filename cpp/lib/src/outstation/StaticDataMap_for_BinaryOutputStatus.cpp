#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include <QApplication>
#include "header.h"
#include "StaticDataMap_for_BinaryOutputStatus.h"

void StaticDataMap_for_BinaryOutputStatusSpec_in_StaticDataMap_for_BinaryOutputStatusSpecOver1(StaticDataMap_for_BinaryOutputStatusSpec *pStaticDataMap)
{
  Range_in_RangeOver1(&(pStaticDataMap->selected));
}
////template<class Spec> StaticDataMap<Spec>::StaticDataMap(const std::map<uint16_t, typename Spec::config_t>& config)
void StaticDataMap_for_BinaryOutputStatusSpec_in_StaticDataMap_for_BinaryOutputStatusSpecOver2(StaticDataMap_for_BinaryOutputStatusSpec *pStaticDataMap, std::map<uint16_t, BOStatusConfig>& config)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"StaticDataMap_for_BinaryOutputStatusSpec_in_StaticDataMap_for_BinaryOutputStatusSpecOver2_1"<<'\n';
  decrement_stack_info();
#endif

  StaticDataMap_for_BinaryOutputStatusSpec_in_StaticDataMap_for_BinaryOutputStatusSpecOver1(pStaticDataMap);
  for (const auto& item : config)
  {
//void StaticDataCell_for_BinaryOutputStatus_in_StaticDataCell_for_BinaryOutputStatusOver1(StaticDataCell_for_BinaryOutputStatus *pStaticDataCell_for_BinaryOutputStatus,
//    BinaryOutputStatusConfig* config);
////        pStaticDataMap->map[item.first] = StaticDataCell<Spec>{item.second};
    BOStatusConfig temp = item.second;
    StaticDataCell_for_BinaryOutputStatus sStaticDataCell_for_BinaryOutputStatus;
    StaticDataCell_for_BinaryOutputStatus_in_StaticDataCell_for_BinaryOutputStatusOver2(&sStaticDataCell_for_BinaryOutputStatus, &temp);
    pStaticDataMap->map[item.first] = sStaticDataCell_for_BinaryOutputStatus;
  }
}

Range get_selected_range_in_StaticDataMap_for_BinaryOutputStatusSpec(StaticDataMap_for_BinaryOutputStatusSpec *pStaticDataMap_for_BinaryOutputStatusSpec)
{
  return pStaticDataMap_for_BinaryOutputStatusSpec->selected;
}

typename StaticDataMap_for_BinaryOutputStatusSpec::iterator StaticDataMap_for_BinaryOutputStatusSpec::begin()
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
void clear_selection_in_StaticDataMap_for_BinaryOutputStatusSpec(StaticDataMap_for_BinaryOutputStatusSpec *pStaticDataMap_for_BinaryOutputStatusSpec)
{
  // the act of iterating clears the selection
  for (auto iter = pStaticDataMap_for_BinaryOutputStatusSpec->begin(); iter != pStaticDataMap_for_BinaryOutputStatusSpec->end(); ++iter)
  {
  }
}

////template<class Spec> typename StaticDataMap<Spec>::iterator StaticDataMap<Spec>::end()
typename StaticDataMap_for_BinaryOutputStatusSpec::iterator StaticDataMap_for_BinaryOutputStatusSpec::end()
{
  return iterator(this->map.end(), this->map.end(), this->selected);
}

////template<class Spec>
////typename Spec::static_variation_t check_for_promotion(const typename Spec::meas_t& value,
////                                                      typename Spec::static_variation_t variation)
StaticBinaryOutputStatusVariation_uint8_t check_for_promotion_for_BinaryOutputStatusSpec_static(BinaryOutputStatus* value, StaticBinaryOutputStatusVariation_uint8_t variation)
{
  UNUSED(value);
  return variation;
}

uint16_t select_all_in_StaticDataMap_for_BinaryOutputStatusSpecOver1(StaticDataMap_for_BinaryOutputStatusSpec *pStaticDataMap_for_BinaryOutputStatusSpec)
{
  return select_all_in_StaticDataMap_for_BinaryOutputStatusSpecOver3(pStaticDataMap_for_BinaryOutputStatusSpec, [](auto var) {
    return var;
  }); // use the default
}

uint16_t select_all_in_StaticDataMap_for_BinaryOutputStatusSpecOver2(StaticDataMap_for_BinaryOutputStatusSpec *pStaticDataMap_for_BinaryOutputStatusSpec, StaticBinaryOutputStatusVariation_uint8_t variation)
{
  return select_all_in_StaticDataMap_for_BinaryOutputStatusSpecOver3(pStaticDataMap_for_BinaryOutputStatusSpec, [variation](auto var) {
    return variation;
  }); // override default
}

////    size_t select(Range range)
uint16_t select_in_StaticDataMap_for_BinaryOutputStatusSpecOver1(StaticDataMap_for_BinaryOutputStatusSpec *pStaticDataMap_for_BinaryOutputStatusSpec, Range range)
{
////        return this->select(range, [](auto var) { return var; }); // use the default
  return select_in_StaticDataMap_for_BinaryOutputStatusSpecOver5(pStaticDataMap_for_BinaryOutputStatusSpec, range, [](auto var) {
    return var;
  }); // use the default
}

////    bool select(uint16_t index, typename Spec::static_variation_t variation)
boolean select_in_StaticDataMap_for_BinaryOutputStatusSpecOver2(StaticDataMap_for_BinaryOutputStatusSpec *pStaticDataMap_for_BinaryOutputStatusSpec, uint16_t index, StaticBinaryOutputStatusVariation_uint8_t variation)
{
////        return this->select(Range::From(index, index), variation);
  return select_in_StaticDataMap_for_BinaryOutputStatusSpecOver4(pStaticDataMap_for_BinaryOutputStatusSpec, From_in_Range_static(index, index), variation) == 1;
}

////    bool select(uint16_t index)
boolean select_in_StaticDataMap_for_BinaryOutputStatusSpecOver3(StaticDataMap_for_BinaryOutputStatusSpec *pStaticDataMap_for_BinaryOutputStatusSpec, uint16_t index)
{
////        return this->select(Range::From(index, index)) == 1;
  return select_in_StaticDataMap_for_BinaryOutputStatusSpecOver1(pStaticDataMap_for_BinaryOutputStatusSpec, From_in_Range_static(index, index)) == 1;
}

////    size_t select(Range range, typename Spec::static_variation_t variation)
uint16_t select_in_StaticDataMap_for_BinaryOutputStatusSpecOver4(StaticDataMap_for_BinaryOutputStatusSpec *pStaticDataMap_for_BinaryOutputStatusSpec, Range range, StaticBinaryOutputStatusVariation_uint8_t variation)
{
////        return this->select(range, [variation](auto var) { return variation; }); // override default
  return select_in_StaticDataMap_for_BinaryOutputStatusSpecOver5(pStaticDataMap_for_BinaryOutputStatusSpec, range, [variation](auto var) {
    return variation;
  }); // override default
}

boolean update_in_StaticDataMap_for_BinaryOutputStatusSpecOver1(StaticDataMap_for_BinaryOutputStatusSpec *pStaticDataMap_for_BinaryOutputStatusSpec,
    BinaryOutputStatus* value,
    uint16_t index,
    EventMode_uint8_t mode,
    IEventReceiver* receiver)
{
//boolean update_in_StaticDataMap_for_BinaryOutputStatusSpecOver2(StaticDataMap_for_BinaryOutputStatusSpec *pStaticDataMap_for_BinaryOutputStatusSpec,
//    map_iter_t_StaticDataMap_for_BinaryOutputStatusSpec & iter,
//    BinaryOutputStatus* new_value,
//    EventMode_uint8_t mode,
//    IEventReceiver* receiver);
////    return update(this->map.find(index), value, mode, receiver);
  map_iter_t_StaticDataMap_for_BinaryOutputStatusSpec  iter = pStaticDataMap_for_BinaryOutputStatusSpec->map.find(index);
  return update_in_StaticDataMap_for_BinaryOutputStatusSpecOver2(pStaticDataMap_for_BinaryOutputStatusSpec,
         iter, value, mode, receiver);
}

boolean update_in_StaticDataMap_for_BinaryOutputStatusSpecOver2(StaticDataMap_for_BinaryOutputStatusSpec *pStaticDataMap_for_BinaryOutputStatusSpec,
    map_iter_t_StaticDataMap_for_BinaryOutputStatusSpec & iter,
    BinaryOutputStatus* new_value,
    EventMode_uint8_t mode,
    IEventReceiver* receiver)
{
  if (iter == pStaticDataMap_for_BinaryOutputStatusSpec->map.end())
  {
    return false;
  }

  if (mode != EventMode_EventOnly)
  {
    iter->second.value = *new_value;
  }

  BinaryOutputStatus old_value = iter->second.event.eEventCellBase_for_BinaryOutputStatus.lastEvent;
  if (mode == EventMode_Force || mode == EventMode_EventOnly ||
//boolean IsEvent_in_BinaryOutputStatusSpec_static(BinaryOutputStatus *old_value, BinaryOutputStatus *new_value, BinaryOutputStatusConfig *config);
////        Spec::IsEvent(iter->second.event.lastEvent, new_value, iter->second.config))
      IsEvent_in_BinaryOutputStatusSpec_static(&old_value, new_value, &(iter->second.config)))
  {
    iter->second.event.eEventCellBase_for_BinaryOutputStatus.lastEvent = *new_value;
    if (mode != EventMode_Suppress)
    {
      EventClass_uint8_t ec;
//boolean convert_to_event_class_in_StaticDataMap_static(PointClass_uint8_t pc, EventClass_uint8_t* ec);
////            if (convert_to_event_class(iter->second.config.clazz, ec))
      if (convert_to_event_class_in_StaticDataMap_static(iter->second.config.eEventConfig.clazz, &ec))
      {
//void Event_for_BinaryOutputStatusSpec_in_Event_for_BinaryOutputStatusSpecOver2(Event_for_BinaryOutputStatusSpec *pEvent_for_BinaryOutputStatusSpec,
//    BinaryOutputStatus* value, uint16_t index,
//    EventClass_uint8_t clazz,
//    event_variation_t_in_BinaryOutputStatusInfo variation);
//void Update_BinaryOutputStatusSpec_in_IEventReceiver(IEventReceiver *, Event_for_BinaryOutputStatusSpec* evt);
////                receiver.Update(Event<Spec>(new_value, iter->first, ec, iter->second.config.evariation));
        Event_for_BinaryOutputStatusSpec eEvent_for_BinaryOutputStatusSpec;
        Event_for_BinaryOutputStatusSpec_in_Event_for_BinaryOutputStatusSpecOver2(&eEvent_for_BinaryOutputStatusSpec,
            new_value, iter->first,
            ec,
            iter->second.config.eEventConfig.evariation);
        Update_BinaryOutputStatusSpec_in_IEventReceiver(receiver, &eEvent_for_BinaryOutputStatusSpec);

      }
    }
  }

  return true;
}

////    bool has_any_selection() const
boolean has_any_selection_in_StaticDataMap_for_BinaryOutputStatusSpec(StaticDataMap_for_BinaryOutputStatusSpec *pStaticDataMap_for_BinaryOutputStatusSpec)
{
//boolean IsValid_in_Range(Range *pRange);
////        return this->selected.IsValid();
 return IsValid_in_Range(&(pStaticDataMap_for_BinaryOutputStatusSpec->selected));
}

boolean add_in_StaticDataMap_for_BinaryOutputStatusSpec(StaticDataMap_for_BinaryOutputStatusSpec *pStaticDataMap_for_BinaryOutputStatusSpec, BinaryOutputStatus *value, uint16_t index, BOStatusConfig *config)
{
  if (pStaticDataMap_for_BinaryOutputStatusSpec->map.find(index) != pStaticDataMap_for_BinaryOutputStatusSpec->map.end())
  {
    return false;
  }

//void  StaticDataCell_for_BinaryOutputStatus_in_StaticDataCell_for_BinaryOutputStatusOver3(StaticDataCell_for_BinaryOutputStatus *pStaticDataCell_for_BinaryOutputStatus,
//    BinaryOutputStatus* value,
//    BinaryOutputStatusConfig* config);
  StaticDataCell_for_BinaryOutputStatus sStaticDataCell;
  StaticDataCell_for_BinaryOutputStatus_in_StaticDataCell_for_BinaryOutputStatusOver3(&sStaticDataCell, value, config);

  pStaticDataMap_for_BinaryOutputStatusSpec->map[index] = sStaticDataCell;////StaticDataCell_for_BinaryOutputStatusSpec{value, config};

  return true;
}

boolean modify_in_StaticDataMap_for_BinaryOutputStatusSpec(StaticDataMap_for_BinaryOutputStatusSpec *pStaticDataMap_for_BinaryOutputStatusSpec,
    uint16_t start, uint16_t stop, uint8_t flags,
    IEventReceiver* receiver)
{
  if (stop < start)
  {
    return false;
  }

  for (auto iter = pStaticDataMap_for_BinaryOutputStatusSpec->map.lower_bound(start); iter != pStaticDataMap_for_BinaryOutputStatusSpec->map.end(); ++iter)
  {
    if (iter->first > stop)
    {
      return false;
    }

    BinaryOutputStatus new_value = iter->second.value;
////        new_value.flags = Flags(flags);
    Flags fFlags;
    Flags_In_FlagsOver2(&fFlags, flags);
    new_value.tTypedMeasurement_for_Boolean.mMeasurement.flags = fFlags;
//boolean update_in_StaticDataMap_for_BinaryOutputStatusSpecOver2(StaticDataMap_for_BinaryOutputStatusSpec *pStaticDataMap_for_BinaryOutputStatusSpec,
//    map_iter_t_StaticDataMap_for_BinaryOutputStatusSpec & iter,
//    BinaryOutputStatus* new_value,
//    EventMode_uint8_t mode,
//    IEventReceiver* receiver);
////        this->update(iter, new_value, EventMode::Detect, receiver);
    update_in_StaticDataMap_for_BinaryOutputStatusSpecOver2(pStaticDataMap_for_BinaryOutputStatusSpec,
        iter,
        &new_value,
        EventMode_Detect,
        receiver);
  }

  return true;
}

////template<class Spec> Range StaticDataMap<Spec>::get_full_range() const
Range get_full_range_in_StaticDataMap_for_BinaryOutputStatusSpec(StaticDataMap_for_BinaryOutputStatusSpec *pStaticDataMap_for_BinaryOutputStatusSpec)
{
//Range From_in_Range_static(uint16_t start, uint16_t stop);
//Range Invalid_in_Range_static(void);
////    return this->map.empty() ? Range::Invalid() : Range::From(this->map.begin()->first, this->map.rbegin()->first);
  return pStaticDataMap_for_BinaryOutputStatusSpec->map.empty() ? Invalid_in_Range_static() : 
         From_in_Range_static(pStaticDataMap_for_BinaryOutputStatusSpec->map.begin()->first, pStaticDataMap_for_BinaryOutputStatusSpec->map.rbegin()->first);
}

////template<class Spec> Range StaticDataMap<Spec>::assign_class(PointClass clazz)
Range assign_class_in_StaticDataMap_for_BinaryOutputStatusSpecOver1(StaticDataMap_for_BinaryOutputStatusSpec *pStaticDataMap_for_BinaryOutputStatusSpec, PointClass_uint8_t clazz)
{
  for (auto& elem : pStaticDataMap_for_BinaryOutputStatusSpec->map)
  {
    elem.second.config.eEventConfig.clazz = clazz;
  }

////    return this->get_full_range();
  return get_full_range_in_StaticDataMap_for_BinaryOutputStatusSpec(pStaticDataMap_for_BinaryOutputStatusSpec);
}

Range assign_class_in_StaticDataMap_for_BinaryOutputStatusSpecOver2(StaticDataMap_for_BinaryOutputStatusSpec *pStaticDataMap_for_BinaryOutputStatusSpec, PointClass_uint8_t clazz, Range* range)
{
  for (auto iter = pStaticDataMap_for_BinaryOutputStatusSpec->map.lower_bound(range->start); iter != pStaticDataMap_for_BinaryOutputStatusSpec->map.end() &&
////             range.Contains(iter->first);
       Contains_in_Range(range, iter->first); iter++)
  {
    iter->second.config.eEventConfig.clazz = clazz;
  }

//Range get_full_range_in_StaticDataMap_for_BinaryOutputStatusSpec(StaticDataMap_for_BinaryOutputStatusSpec *pStaticDataMap_for_BinaryOutputStatusSpec);
//Range Intersection_in_Range(Range *pRange, Range* other);
////    return range.Intersection(this->get_full_range());
  Range temp = get_full_range_in_StaticDataMap_for_BinaryOutputStatusSpec(pStaticDataMap_for_BinaryOutputStatusSpec);
  return Intersection_in_Range(range, &temp);
}
