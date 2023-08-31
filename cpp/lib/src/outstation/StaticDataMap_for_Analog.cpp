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
