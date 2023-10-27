#include <QApplication>
#include "header.h"
#include "StaticDataMap.h"
#include "StaticDataMap_for_TimeAndInterval.h"

////template<class Spec> StaticDataMap<Spec>::StaticDataMap(const std::map<uint16_t, typename Spec::config_t>& config)
void StaticDataMap_for_TimeAndIntervalSpec_in_StaticDataMap_for_TimeAndIntervalSpec(StaticDataMap_for_TimeAndIntervalSpec *pStaticDataMap, std::map<uint16_t, TimeAndIntervalConfig>& config)
{
  for (const auto& item : config)
  {
//void StaticDataCell_for_TimeAndInterval_in_StaticDataCell_for_TimeAndIntervalOver1(StaticDataCell_for_TimeAndInterval *pStaticDataCell_for_TimeAndInterval,
//    TimeAndIntervalConfig* config);
////        pStaticDataMap->map[item.first] = StaticDataCell<Spec>{item.second};
    TimeAndIntervalConfig temp = item.second;
    StaticDataCell_for_TimeAndInterval sStaticDataCell_for_TimeAndInterval;
    StaticDataCell_for_TimeAndInterval_in_StaticDataCell_for_TimeAndIntervalOver1(&sStaticDataCell_for_TimeAndInterval, &temp);
    pStaticDataMap->map[item.first] = sStaticDataCell_for_TimeAndInterval;
  }
}

Range get_selected_range_in_StaticDataMap_for_TimeAndIntervalSpec(StaticDataMap_for_TimeAndIntervalSpec *pStaticDataMap_for_TimeAndIntervalSpec)
{
  return pStaticDataMap_for_TimeAndIntervalSpec->selected;
}

typename StaticDataMap_for_TimeAndIntervalSpec::iterator StaticDataMap_for_TimeAndIntervalSpec::begin()
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
void clear_selection_in_StaticDataMap_for_TimeAndIntervalSpec(StaticDataMap_for_TimeAndIntervalSpec *pStaticDataMap_for_TimeAndIntervalSpec)
{
  // the act of iterating clears the selection
  for (auto iter = pStaticDataMap_for_TimeAndIntervalSpec->begin(); iter != pStaticDataMap_for_TimeAndIntervalSpec->end(); ++iter)
  {
  }
}

////template<class Spec> typename StaticDataMap<Spec>::iterator StaticDataMap<Spec>::end()
typename StaticDataMap_for_TimeAndIntervalSpec::iterator StaticDataMap_for_TimeAndIntervalSpec::end()
{
  return iterator(this->map.end(), this->map.end(), this->selected);
}

////template<class Spec>
////typename Spec::static_variation_t check_for_promotion(const typename Spec::meas_t& value,
////                                                      typename Spec::static_variation_t variation)
StaticTimeAndIntervalVariation_uint8_t check_for_promotion_for_TimeAndIntervalSpec_static(TimeAndInterval* value, StaticTimeAndIntervalVariation_uint8_t variation)
{
  UNUSED(value);
  return variation;
}

uint16_t select_all_in_StaticDataMap_for_TimeAndIntervalSpecOver1(StaticDataMap_for_TimeAndIntervalSpec *pStaticDataMap_for_TimeAndIntervalSpec)
{
  return select_all_in_StaticDataMap_for_TimeAndIntervalSpecOver3(pStaticDataMap_for_TimeAndIntervalSpec, [](auto var) {
    return var;
  }); // use the default
}

uint16_t select_all_in_StaticDataMap_for_TimeAndIntervalSpecOver2(StaticDataMap_for_TimeAndIntervalSpec *pStaticDataMap_for_TimeAndIntervalSpec, StaticTimeAndIntervalVariation_uint8_t variation)
{
  return select_all_in_StaticDataMap_for_TimeAndIntervalSpecOver3(pStaticDataMap_for_TimeAndIntervalSpec, [variation](auto var) {
    return variation;
  }); // override default
}

////    size_t select(Range range)
uint16_t select_in_StaticDataMap_for_TimeAndIntervalSpecOver1(StaticDataMap_for_TimeAndIntervalSpec *pStaticDataMap_for_TimeAndIntervalSpec, Range range)
{
////        return this->select(range, [](auto var) { return var; }); // use the default
  return select_in_StaticDataMap_for_TimeAndIntervalSpecOver5(pStaticDataMap_for_TimeAndIntervalSpec, range, [](auto var) {
    return var;
  }); // use the default
}

////    bool select(uint16_t index, typename Spec::static_variation_t variation)
boolean select_in_StaticDataMap_for_TimeAndIntervalSpecOver2(StaticDataMap_for_TimeAndIntervalSpec *pStaticDataMap_for_TimeAndIntervalSpec, uint16_t index, StaticTimeAndIntervalVariation_uint8_t variation)
{
////        return this->select(Range::From(index, index), variation);
  return select_in_StaticDataMap_for_TimeAndIntervalSpecOver4(pStaticDataMap_for_TimeAndIntervalSpec, From_in_Range_static(index, index), variation) == 1;
}

////    bool select(uint16_t index)
boolean select_in_StaticDataMap_for_TimeAndIntervalSpecOver3(StaticDataMap_for_TimeAndIntervalSpec *pStaticDataMap_for_TimeAndIntervalSpec, uint16_t index)
{
////        return this->select(Range::From(index, index)) == 1;
  return select_in_StaticDataMap_for_TimeAndIntervalSpecOver1(pStaticDataMap_for_TimeAndIntervalSpec, From_in_Range_static(index, index)) == 1;
}

////    size_t select(Range range, typename Spec::static_variation_t variation)
uint16_t select_in_StaticDataMap_for_TimeAndIntervalSpecOver4(StaticDataMap_for_TimeAndIntervalSpec *pStaticDataMap_for_TimeAndIntervalSpec, Range range, StaticTimeAndIntervalVariation_uint8_t variation)
{
////        return this->select(range, [variation](auto var) { return variation; }); // override default
  return select_in_StaticDataMap_for_TimeAndIntervalSpecOver5(pStaticDataMap_for_TimeAndIntervalSpec, range, [variation](auto var) {
    return variation;
  }); // override default
}

////    bool has_any_selection() const
boolean has_any_selection_in_StaticDataMap_for_TimeAndIntervalSpec(StaticDataMap_for_TimeAndIntervalSpec *pStaticDataMap_for_TimeAndIntervalSpec)
{
//boolean IsValid_in_Range(Range *pRange);
////        return this->selected.IsValid();
 return IsValid_in_Range(&(pStaticDataMap_for_TimeAndIntervalSpec->selected));
}

boolean add_in_StaticDataMap_for_TimeAndIntervalSpec(StaticDataMap_for_TimeAndIntervalSpec *pStaticDataMap_for_TimeAndIntervalSpec, TimeAndInterval *value, uint16_t index, TimeAndIntervalConfig *config)
{
  if (pStaticDataMap_for_TimeAndIntervalSpec->map.find(index) != pStaticDataMap_for_TimeAndIntervalSpec->map.end())
  {
    return false;
  }

//void  StaticDataCell_for_TimeAndInterval_in_StaticDataCell_for_TimeAndIntervalOver2(StaticDataCell_for_TimeAndInterval *pStaticDataCell_for_TimeAndInterval,
//    TimeAndInterval* value,
//    TimeAndIntervalConfig* config);
  StaticDataCell_for_TimeAndInterval sStaticDataCell;
  StaticDataCell_for_TimeAndInterval_in_StaticDataCell_for_TimeAndIntervalOver2(&sStaticDataCell, value, config);

  pStaticDataMap_for_TimeAndIntervalSpec->map[index] = sStaticDataCell;////StaticDataCell_for_TimeAndIntervalSpec{value, config};

  return true;
}
