#include <QApplication>
#include "header.h"
#include "StaticDataMap_for_Counter.h"

////template<class Spec> StaticDataMap<Spec>::StaticDataMap(const std::map<uint16_t, typename Spec::config_t>& config)
void StaticDataMap_for_CounterSpec_in_StaticDataMap_for_CounterSpec(StaticDataMap_for_CounterSpec *pStaticDataMap, std::map<uint16_t, CounterConfig>& config)
{
  for (const auto& item : config)
  {
//void StaticDataCell_for_Counter_in_StaticDataCell_for_CounterOver1(StaticDataCell_for_Counter *pStaticDataCell_for_Counter,
//    CounterConfig* config);
////        pStaticDataMap->map[item.first] = StaticDataCell<Spec>{item.second};
    CounterConfig temp = item.second;
    StaticDataCell_for_Counter sStaticDataCell_for_Counter;
    StaticDataCell_for_Counter_in_StaticDataCell_for_CounterOver1(&sStaticDataCell_for_Counter, &temp);
    pStaticDataMap->map[item.first] = sStaticDataCell_for_Counter;
  }
}

Range get_selected_range_in_StaticDataMap_for_CounterSpec(StaticDataMap_for_CounterSpec *pStaticDataMap_for_CounterSpec)
{
  return pStaticDataMap_for_CounterSpec->selected;
}
