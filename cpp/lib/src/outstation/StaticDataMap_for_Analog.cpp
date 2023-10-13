#include <QtWidgets>
#include <QApplication>
#include "header.h"
#include "StaticDataMap_for_Analog.h"

////template<class Spec> StaticDataMap<Spec>::StaticDataMap(const std::map<uint16_t, typename Spec::config_t>& config)
void StaticDataMap_for_AnalogSpec_in_StaticDataMap_for_AnalogSpec(StaticDataMap_for_AnalogSpec *pStaticDataMap, std::map<uint16_t, AnalogConfig>& config)
{
  for (const auto& item : config)
  {
//void StaticDataCell_for_Analog_in_StaticDataCell_for_AnalogOver1(StaticDataCell_for_Analog *pStaticDataCell_for_Analog,
//    AnalogConfig* config);
////        pStaticDataMap->map[item.first] = StaticDataCell<Spec>{item.second};
    AnalogConfig temp = item.second;
    StaticDataCell_for_Analog sStaticDataCell_for_Analog;
    StaticDataCell_for_Analog_in_StaticDataCell_for_AnalogOver1(&sStaticDataCell_for_Analog, &temp);
    pStaticDataMap->map[item.first] = sStaticDataCell_for_Analog;
  }
}

Range get_selected_range_in_StaticDataMap_for_AnalogSpec(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec)
{
  return pStaticDataMap_for_AnalogSpec->selected;
}

typename StaticDataMap_for_AnalogSpec::iterator StaticDataMap_for_AnalogSpec::begin()
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
void clear_selection_in_StaticDataMap_for_AnalogSpec(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec)
{
   // the act of iterating clears the selection
    for (auto iter = pStaticDataMap_for_AnalogSpec->begin(); iter != pStaticDataMap_for_AnalogSpec->end(); ++iter)
    {
    }
}

////template<class Spec> typename StaticDataMap<Spec>::iterator StaticDataMap<Spec>::end()
typename StaticDataMap_for_AnalogSpec::iterator StaticDataMap_for_AnalogSpec::end()
{
  return iterator(this->map.end(), this->map.end(), this->selected);
}

////template<class Spec>
////typename Spec::static_variation_t check_for_promotion(const typename Spec::meas_t& value,
////                                                      typename Spec::static_variation_t variation)
 StaticAnalogVariation_uint8_t check_for_promotion_for_AnalogSpec(Analog* value, StaticAnalogVariation_uint8_t variation)
{
 UNUSED(value);
   return variation;
}

 uint16_t select_all_in_StaticDataMap_for_AnalogSpecOver1(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec)
    {
        return select_all_in_StaticDataMap_for_AnalogSpecOver3(pStaticDataMap_for_AnalogSpec, [](auto var) { return var; }); // use the default
    }

 uint16_t select_all_in_StaticDataMap_for_AnalogSpecOver2(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec, StaticAnalogVariation_uint8_t variation)
    {
        return select_all_in_StaticDataMap_for_AnalogSpecOver3(pStaticDataMap_for_AnalogSpec, [variation](auto var) { return variation; }); // override default
    }


// uint16_t select_all_in_StaticDataMap_for_AnalogSpec(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec, StaticAnalogVariation_uint8_t variation)
