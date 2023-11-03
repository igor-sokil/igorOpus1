#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include <QApplication>
#include "header.h"
#include "StaticDataMap_for_DoubleBitBinary.h"

void StaticDataMap_for_DoubleBitBinarySpec_in_StaticDataMap_for_DoubleBitBinarySpecOver1(StaticDataMap_for_DoubleBitBinarySpec *pStaticDataMap)
{
  Range_in_RangeOver1(&(pStaticDataMap->selected));
}
////template<class Spec> StaticDataMap<Spec>::StaticDataMap(const std::map<uint16_t, typename Spec::config_t>& config)
void StaticDataMap_for_DoubleBitBinarySpec_in_StaticDataMap_for_DoubleBitBinarySpecOver2(StaticDataMap_for_DoubleBitBinarySpec *pStaticDataMap, std::map<uint16_t, DoubleBitBinaryConfig>& config)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"StaticDataMap_for_DoubleBitBinarySpec_in_StaticDataMap_for_DoubleBitBinarySpecOver2_1"<<'\n';
  decrement_stack_info();
#endif

  StaticDataMap_for_DoubleBitBinarySpec_in_StaticDataMap_for_DoubleBitBinarySpecOver1(pStaticDataMap);
  for (const auto& item : config)
  {
//void StaticDataCell_for_DoubleBitBinary_in_StaticDataCell_for_DoubleBitBinaryOver1(StaticDataCell_for_DoubleBitBinary *pStaticDataCell_for_DoubleBitBinary,
//    DoubleBitBinaryConfig* config);
////        pStaticDataMap->map[item.first] = StaticDataCell<Spec>{item.second};
    DoubleBitBinaryConfig temp = item.second;
    StaticDataCell_for_DoubleBitBinary sStaticDataCell_for_DoubleBitBinary;
    StaticDataCell_for_DoubleBitBinary_in_StaticDataCell_for_DoubleBitBinaryOver2(&sStaticDataCell_for_DoubleBitBinary, &temp);
    pStaticDataMap->map[item.first] = sStaticDataCell_for_DoubleBitBinary;
  }
}

Range get_selected_range_in_StaticDataMap_for_DoubleBitBinarySpec(StaticDataMap_for_DoubleBitBinarySpec *pStaticDataMap_for_DoubleBitBinarySpec)
{
  return pStaticDataMap_for_DoubleBitBinarySpec->selected;
}

typename StaticDataMap_for_DoubleBitBinarySpec::iterator StaticDataMap_for_DoubleBitBinarySpec::begin()
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
void clear_selection_in_StaticDataMap_for_DoubleBitBinarySpec(StaticDataMap_for_DoubleBitBinarySpec *pStaticDataMap_for_DoubleBitBinarySpec)
{
  // the act of iterating clears the selection
  for (auto iter = pStaticDataMap_for_DoubleBitBinarySpec->begin(); iter != pStaticDataMap_for_DoubleBitBinarySpec->end(); ++iter)
  {
  }
}

////template<class Spec> typename StaticDataMap<Spec>::iterator StaticDataMap<Spec>::end()
typename StaticDataMap_for_DoubleBitBinarySpec::iterator StaticDataMap_for_DoubleBitBinarySpec::end()
{
  return iterator(this->map.end(), this->map.end(), this->selected);
}

////template<class Spec>
////typename Spec::static_variation_t check_for_promotion(const typename Spec::meas_t& value,
////                                                      typename Spec::static_variation_t variation)
StaticDoubleBinaryVariation_uint8_t check_for_promotion_for_DoubleBitBinarySpec_static(DoubleBitBinary* value, StaticDoubleBinaryVariation_uint8_t variation)
{
  UNUSED(value);
  return variation;
}

uint16_t select_all_in_StaticDataMap_for_DoubleBitBinarySpecOver1(StaticDataMap_for_DoubleBitBinarySpec *pStaticDataMap_for_DoubleBitBinarySpec)
{
  return select_all_in_StaticDataMap_for_DoubleBitBinarySpecOver3(pStaticDataMap_for_DoubleBitBinarySpec, [](auto var) {
    return var;
  }); // use the default
}

uint16_t select_all_in_StaticDataMap_for_DoubleBitBinarySpecOver2(StaticDataMap_for_DoubleBitBinarySpec *pStaticDataMap_for_DoubleBitBinarySpec, StaticDoubleBinaryVariation_uint8_t variation)
{
  return select_all_in_StaticDataMap_for_DoubleBitBinarySpecOver3(pStaticDataMap_for_DoubleBitBinarySpec, [variation](auto var) {
    return variation;
  }); // override default
}

////    size_t select(Range range)
uint16_t select_in_StaticDataMap_for_DoubleBitBinarySpecOver1(StaticDataMap_for_DoubleBitBinarySpec *pStaticDataMap_for_DoubleBitBinarySpec, Range range)
{
////        return this->select(range, [](auto var) { return var; }); // use the default
  return select_in_StaticDataMap_for_DoubleBitBinarySpecOver5(pStaticDataMap_for_DoubleBitBinarySpec, range, [](auto var) {
    return var;
  }); // use the default
}

////    bool select(uint16_t index, typename Spec::static_variation_t variation)
boolean select_in_StaticDataMap_for_DoubleBitBinarySpecOver2(StaticDataMap_for_DoubleBitBinarySpec *pStaticDataMap_for_DoubleBitBinarySpec, uint16_t index, StaticDoubleBinaryVariation_uint8_t variation)
{
////        return this->select(Range::From(index, index), variation);
  return select_in_StaticDataMap_for_DoubleBitBinarySpecOver4(pStaticDataMap_for_DoubleBitBinarySpec, From_in_Range_static(index, index), variation) == 1;
}

////    bool select(uint16_t index)
boolean select_in_StaticDataMap_for_DoubleBitBinarySpecOver3(StaticDataMap_for_DoubleBitBinarySpec *pStaticDataMap_for_DoubleBitBinarySpec, uint16_t index)
{
////        return this->select(Range::From(index, index)) == 1;
  return select_in_StaticDataMap_for_DoubleBitBinarySpecOver1(pStaticDataMap_for_DoubleBitBinarySpec, From_in_Range_static(index, index)) == 1;
}

////    size_t select(Range range, typename Spec::static_variation_t variation)
uint16_t select_in_StaticDataMap_for_DoubleBitBinarySpecOver4(StaticDataMap_for_DoubleBitBinarySpec *pStaticDataMap_for_DoubleBitBinarySpec, Range range, StaticDoubleBinaryVariation_uint8_t variation)
{
////        return this->select(range, [variation](auto var) { return variation; }); // override default
  return select_in_StaticDataMap_for_DoubleBitBinarySpecOver5(pStaticDataMap_for_DoubleBitBinarySpec, range, [variation](auto var) {
    return variation;
  }); // override default
}

boolean update_in_StaticDataMap_for_DoubleBitBinarySpecOver1(StaticDataMap_for_DoubleBitBinarySpec *pStaticDataMap_for_DoubleBitBinarySpec,
    DoubleBitBinary* value,
    uint16_t index,
    EventMode_uint8_t mode,
    IEventReceiver* receiver)
{
//boolean update_in_StaticDataMap_for_DoubleBitBinarySpecOver2(StaticDataMap_for_DoubleBitBinarySpec *pStaticDataMap_for_DoubleBitBinarySpec,
//    map_iter_t_StaticDataMap_for_DoubleBitBinarySpec & iter,
//    DoubleBitBinary* new_value,
//    EventMode_uint8_t mode,
//    IEventReceiver* receiver);
////    return update(this->map.find(index), value, mode, receiver);
  map_iter_t_StaticDataMap_for_DoubleBitBinarySpec  iter = pStaticDataMap_for_DoubleBitBinarySpec->map.find(index);
  return update_in_StaticDataMap_for_DoubleBitBinarySpecOver2(pStaticDataMap_for_DoubleBitBinarySpec,
         iter, value, mode, receiver);
}

boolean update_in_StaticDataMap_for_DoubleBitBinarySpecOver2(StaticDataMap_for_DoubleBitBinarySpec *pStaticDataMap_for_DoubleBitBinarySpec,
    map_iter_t_StaticDataMap_for_DoubleBitBinarySpec & iter,
    DoubleBitBinary* new_value,
    EventMode_uint8_t mode,
    IEventReceiver* receiver)
{
  if (iter == pStaticDataMap_for_DoubleBitBinarySpec->map.end())
  {
    return false;
  }

  if (mode != EventMode_EventOnly)
  {
    iter->second.value = *new_value;
  }

  DoubleBitBinary old_value = iter->second.event.eEventCellBase_for_DoubleBitBinary.lastEvent;
  if (mode == EventMode_Force || mode == EventMode_EventOnly ||
//boolean IsEvent_in_DoubleBitBinarySpec_static(DoubleBitBinary *old_value, DoubleBitBinary *new_value, DoubleBitBinaryConfig *config);
////        Spec::IsEvent(iter->second.event.lastEvent, new_value, iter->second.config))
      IsEvent_in_DoubleBitBinarySpec_static(&old_value, new_value, &(iter->second.config)))
  {
    iter->second.event.eEventCellBase_for_DoubleBitBinary.lastEvent = *new_value;
    if (mode != EventMode_Suppress)
    {
      EventClass_uint8_t ec;
//boolean convert_to_event_class_in_StaticDataMap_static(PointClass_uint8_t pc, EventClass_uint8_t* ec);
////            if (convert_to_event_class(iter->second.config.clazz, ec))
      if (convert_to_event_class_in_StaticDataMap_static(iter->second.config.eEventConfig.clazz, &ec))
      {
//void Event_for_DoubleBitBinarySpec_in_Event_for_DoubleBitBinarySpecOver2(Event_for_DoubleBitBinarySpec *pEvent_for_DoubleBitBinarySpec,
//    DoubleBitBinary* value, uint16_t index,
//    EventClass_uint8_t clazz,
//    event_variation_t_in_DoubleBitBinaryInfo variation);
//void Update_DoubleBitBinarySpec_in_IEventReceiver(IEventReceiver *, Event_for_DoubleBitBinarySpec* evt);
////                receiver.Update(Event<Spec>(new_value, iter->first, ec, iter->second.config.evariation));
        Event_for_DoubleBitBinarySpec eEvent_for_DoubleBitBinarySpec;
        Event_for_DoubleBitBinarySpec_in_Event_for_DoubleBitBinarySpecOver2(&eEvent_for_DoubleBitBinarySpec,
            new_value, iter->first,
            ec,
            iter->second.config.eEventConfig.evariation);
        Update_DoubleBitBinarySpec_in_IEventReceiver(receiver, &eEvent_for_DoubleBitBinarySpec);

      }
    }
  }

  return true;
}

////    bool has_any_selection() const
boolean has_any_selection_in_StaticDataMap_for_DoubleBitBinarySpec(StaticDataMap_for_DoubleBitBinarySpec *pStaticDataMap_for_DoubleBitBinarySpec)
{
//boolean IsValid_in_Range(Range *pRange);
////        return this->selected.IsValid();
 return IsValid_in_Range(&(pStaticDataMap_for_DoubleBitBinarySpec->selected));
}

boolean add_in_StaticDataMap_for_DoubleBitBinarySpec(StaticDataMap_for_DoubleBitBinarySpec *pStaticDataMap_for_DoubleBitBinarySpec, DoubleBitBinary *value, uint16_t index, DoubleBitBinaryConfig *config)
{
  if (pStaticDataMap_for_DoubleBitBinarySpec->map.find(index) != pStaticDataMap_for_DoubleBitBinarySpec->map.end())
  {
    return false;
  }

//void  StaticDataCell_for_DoubleBitBinary_in_StaticDataCell_for_DoubleBitBinaryOver3(StaticDataCell_for_DoubleBitBinary *pStaticDataCell_for_DoubleBitBinary,
//    DoubleBitBinary* value,
//    DoubleBitBinaryConfig* config);
  StaticDataCell_for_DoubleBitBinary sStaticDataCell;
  StaticDataCell_for_DoubleBitBinary_in_StaticDataCell_for_DoubleBitBinaryOver3(&sStaticDataCell, value, config);

  pStaticDataMap_for_DoubleBitBinarySpec->map[index] = sStaticDataCell;////StaticDataCell_for_DoubleBitBinarySpec{value, config};

  return true;
}

boolean modify_in_StaticDataMap_for_DoubleBitBinarySpec(StaticDataMap_for_DoubleBitBinarySpec *pStaticDataMap_for_DoubleBitBinarySpec,
    uint16_t start, uint16_t stop, uint8_t flags,
    IEventReceiver* receiver)
{
  if (stop < start)
  {
    return false;
  }

  for (auto iter = pStaticDataMap_for_DoubleBitBinarySpec->map.lower_bound(start); iter != pStaticDataMap_for_DoubleBitBinarySpec->map.end(); ++iter)
  {
    if (iter->first > stop)
    {
      return false;
    }

    DoubleBitBinary new_value = iter->second.value;
////        new_value.flags = Flags(flags);
    Flags fFlags;
    Flags_In_FlagsOver2(&fFlags, flags);
    new_value.tTypedMeasurement_for_DoubleBit_uint8_t.mMeasurement.flags = fFlags;
//boolean update_in_StaticDataMap_for_DoubleBitBinarySpecOver2(StaticDataMap_for_DoubleBitBinarySpec *pStaticDataMap_for_DoubleBitBinarySpec,
//    map_iter_t_StaticDataMap_for_DoubleBitBinarySpec & iter,
//    DoubleBitBinary* new_value,
//    EventMode_uint8_t mode,
//    IEventReceiver* receiver);
////        this->update(iter, new_value, EventMode::Detect, receiver);
    update_in_StaticDataMap_for_DoubleBitBinarySpecOver2(pStaticDataMap_for_DoubleBitBinarySpec,
        iter,
        &new_value,
        EventMode_Detect,
        receiver);
  }

  return true;
}

////template<class Spec> Range StaticDataMap<Spec>::get_full_range() const
Range get_full_range_in_StaticDataMap_for_DoubleBitBinarySpec(StaticDataMap_for_DoubleBitBinarySpec *pStaticDataMap_for_DoubleBitBinarySpec)
{
//Range From_in_Range_static(uint16_t start, uint16_t stop);
//Range Invalid_in_Range_static(void);
////    return this->map.empty() ? Range::Invalid() : Range::From(this->map.begin()->first, this->map.rbegin()->first);
  return pStaticDataMap_for_DoubleBitBinarySpec->map.empty() ? Invalid_in_Range_static() : 
         From_in_Range_static(pStaticDataMap_for_DoubleBitBinarySpec->map.begin()->first, pStaticDataMap_for_DoubleBitBinarySpec->map.rbegin()->first);
}

////template<class Spec> Range StaticDataMap<Spec>::assign_class(PointClass clazz)
Range assign_class_in_StaticDataMap_for_DoubleBitBinarySpecOver1(StaticDataMap_for_DoubleBitBinarySpec *pStaticDataMap_for_DoubleBitBinarySpec, PointClass_uint8_t clazz)
{
  for (auto& elem : pStaticDataMap_for_DoubleBitBinarySpec->map)
  {
    elem.second.config.eEventConfig.clazz = clazz;
  }

////    return this->get_full_range();
  return get_full_range_in_StaticDataMap_for_DoubleBitBinarySpec(pStaticDataMap_for_DoubleBitBinarySpec);
}
