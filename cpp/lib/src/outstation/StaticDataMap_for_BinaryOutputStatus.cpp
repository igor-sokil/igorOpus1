#include <QApplication>
#include "header.h"
#include "StaticDataMap_for_BinaryOutputStatus.h"

////template<class Spec> StaticDataMap<Spec>::StaticDataMap(const std::map<uint16_t, typename Spec::config_t>& config)
void StaticDataMap_for_BinaryOutputStatusSpec_in_StaticDataMap_for_BinaryOutputStatusSpec(StaticDataMap_for_BinaryOutputStatusSpec *pStaticDataMap, std::map<uint16_t, BOStatusConfig>& config)
{
  for (const auto& item : config)
  {
//void StaticDataCell_for_BinaryOutputStatus_in_StaticDataCell_for_BinaryOutputStatusOver1(StaticDataCell_for_BinaryOutputStatus *pStaticDataCell_for_BinaryOutputStatus,
//    BinaryOutputStatusConfig* config);
////        pStaticDataMap->map[item.first] = StaticDataCell<Spec>{item.second};
    BOStatusConfig temp = item.second;
    StaticDataCell_for_BinaryOutputStatus sStaticDataCell_for_BinaryOutputStatus;
    StaticDataCell_for_BinaryOutputStatus_in_StaticDataCell_for_BinaryOutputStatusOver1(&sStaticDataCell_for_BinaryOutputStatus, &temp);
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
