#include <QApplication>
#include "header.h"
#include "StaticDataMap_for_AnalogOutputStatus.h"

////template<class Spec> StaticDataMap<Spec>::StaticDataMap(const std::map<uint16_t, typename Spec::config_t>& config)
void StaticDataMap_for_AnalogOutputStatusSpec_in_StaticDataMap_for_AnalogOutputStatusSpec(StaticDataMap_for_AnalogOutputStatusSpec *pStaticDataMap, std::map<uint16_t, AOStatusConfig>& config)
{
  for (const auto& item : config)
  {
//void StaticDataCell_for_AnalogOutputStatus_in_StaticDataCell_for_AnalogOutputStatusOver1(StaticDataCell_for_AnalogOutputStatus *pStaticDataCell_for_AnalogOutputStatus,
//    AnalogOutputStatusConfig* config);
////        pStaticDataMap->map[item.first] = StaticDataCell<Spec>{item.second};
    AOStatusConfig temp = item.second;
    StaticDataCell_for_AnalogOutputStatus sStaticDataCell_for_AnalogOutputStatus;
    StaticDataCell_for_AnalogOutputStatus_in_StaticDataCell_for_AnalogOutputStatusOver1(&sStaticDataCell_for_AnalogOutputStatus, &temp);
    pStaticDataMap->map[item.first] = sStaticDataCell_for_AnalogOutputStatus;
  }
}
