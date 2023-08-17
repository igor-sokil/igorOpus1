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
