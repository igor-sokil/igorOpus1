#include <QApplication>
#include "header.h"
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
