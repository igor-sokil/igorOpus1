#include <QApplication>
#include "header.h"
#include "StaticDataMap_for_Binary.h"

////template<class Spec> StaticDataMap<Spec>::StaticDataMap(const std::map<uint16_t, typename Spec::config_t>& config)
void StaticDataMap_for_BinarySpec_in_StaticDataMap_for_BinarySpec(StaticDataMap_for_BinarySpec *pStaticDataMap, std::map<uint16_t, BinaryConfig>& config)
{
  for (const auto& item : config)
  {
//void StaticDataCell_for_Binary_in_StaticDataCell_for_BinaryOver1(StaticDataCell_for_Binary *pStaticDataCell_for_Binary,
//    BinaryConfig* config);
////        pStaticDataMap->map[item.first] = StaticDataCell<Spec>{item.second};
    BinaryConfig temp = item.second;
    StaticDataCell_for_Binary sStaticDataCell_for_Binary;
    StaticDataCell_for_Binary_in_StaticDataCell_for_BinaryOver1(&sStaticDataCell_for_Binary, &temp);
    pStaticDataMap->map[item.first] = sStaticDataCell_for_Binary;
  }
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
  return select_all_in_StaticDataMap_for_BinarySpecOver3(pStaticDataMap_for_BinarySpec, [variation](auto var) {
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
  if (iter == pStaticDataMap_for_BinarySpec->map.end())
  {
    return false;
  }

  if (mode != EventMode_EventOnly)
  {
    iter->second.value = *new_value;
  }

  Binary old_value = iter->second.event.eEventCellBase_for_Binary.lastEvent;
  if (mode == EventMode_Force || mode == EventMode_EventOnly ||
//boolean IsEvent_in_BinarySpec_static(Binary *old_value, Binary *new_value, BinaryConfig *config);
////        Spec::IsEvent(iter->second.event.lastEvent, new_value, iter->second.config))
      IsEvent_in_BinarySpec_static(&old_value, new_value, &(iter->second.config)))
  {
    iter->second.event.eEventCellBase_for_Binary.lastEvent = *new_value;
    if (mode != EventMode_Suppress)
    {
      EventClass_uint8_t ec;
//boolean convert_to_event_class_in_StaticDataMap_static(PointClass_uint8_t pc, EventClass_uint8_t* ec);
////            if (convert_to_event_class(iter->second.config.clazz, ec))
      if (convert_to_event_class_in_StaticDataMap_static(iter->second.config.eEventConfig.clazz, &ec))
      {
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
            iter->second.config.eEventConfig.evariation);
        Update_BinarySpec_in_IEventReceiver(receiver, &eEvent_for_BinarySpec);

      }
    }
  }

  return true;
}
