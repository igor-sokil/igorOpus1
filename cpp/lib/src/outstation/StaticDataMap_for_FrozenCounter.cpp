#include <QApplication>
#include "header.h"
#include "StaticDataMap_for_FrozenCounter.h"

////template<class Spec> StaticDataMap<Spec>::StaticDataMap(const std::map<uint16_t, typename Spec::config_t>& config)
void StaticDataMap_for_FrozenCounterSpec_in_StaticDataMap_for_FrozenCounterSpec(StaticDataMap_for_FrozenCounterSpec *pStaticDataMap, std::map<uint16_t, FrozenCounterConfig>& config)
{
  for (const auto& item : config)
  {
//void StaticDataCell_for_FrozenCounter_in_StaticDataCell_for_FrozenCounterOver1(StaticDataCell_for_FrozenCounter *pStaticDataCell_for_FrozenCounter,
//    FrozenCounterConfig* config);
////        pStaticDataMap->map[item.first] = StaticDataCell<Spec>{item.second};
    FrozenCounterConfig temp = item.second;
    StaticDataCell_for_FrozenCounter sStaticDataCell_for_FrozenCounter;
    StaticDataCell_for_FrozenCounter_in_StaticDataCell_for_FrozenCounterOver1(&sStaticDataCell_for_FrozenCounter, &temp);
    pStaticDataMap->map[item.first] = sStaticDataCell_for_FrozenCounter;
  }
}

Range get_selected_range_in_StaticDataMap_for_FrozenCounterSpec(StaticDataMap_for_FrozenCounterSpec *pStaticDataMap_for_FrozenCounterSpec)
{
  return pStaticDataMap_for_FrozenCounterSpec->selected;
}
