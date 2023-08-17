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
