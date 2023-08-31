#include <QApplication>
#include "header.h"
#include "StaticDataMap_for_OctetString.h"

////template<class Spec> StaticDataMap<Spec>::StaticDataMap(const std::map<uint16_t, typename Spec::config_t>& config)
void StaticDataMap_for_OctetStringSpec_in_StaticDataMap_for_OctetStringSpec(StaticDataMap_for_OctetStringSpec *pStaticDataMap, std::map<uint16_t, OctetStringConfig>& config)
{
  for (const auto& item : config)
  {
//void StaticDataCell_for_OctetString_in_StaticDataCell_for_OctetStringOver1(StaticDataCell_for_OctetString *pStaticDataCell_for_OctetString,
//    OctetStringConfig* config);
////        pStaticDataMap->map[item.first] = StaticDataCell<Spec>{item.second};
    OctetStringConfig temp = item.second;
    StaticDataCell_for_OctetString sStaticDataCell_for_OctetString;
    StaticDataCell_for_OctetString_in_StaticDataCell_for_OctetStringOver1(&sStaticDataCell_for_OctetString, &temp);
    pStaticDataMap->map[item.first] = sStaticDataCell_for_OctetString;
  }
}

Range get_selected_range_in_StaticDataMap_for_OctetStringSpec(StaticDataMap_for_OctetStringSpec *pStaticDataMap_for_OctetStringSpec)
{
  return pStaticDataMap_for_OctetStringSpec->selected;
}
