#include <QApplication>
#include "header.h"
#include "StaticDataMap_for_DoubleBitBinary.h"

////template<class Spec> StaticDataMap<Spec>::StaticDataMap(const std::map<uint16_t, typename Spec::config_t>& config)
void StaticDataMap_for_DoubleBitBinarySpec_in_StaticDataMap_for_DoubleBitBinarySpec(StaticDataMap_for_DoubleBitBinarySpec *pStaticDataMap, std::map<uint16_t, DoubleBitBinaryConfig>& config)
{
  for (const auto& item : config)
  {
//void StaticDataCell_for_DoubleBitBinary_in_StaticDataCell_for_DoubleBitBinaryOver1(StaticDataCell_for_DoubleBitBinary *pStaticDataCell_for_DoubleBitBinary,
//    DoubleBitBinaryConfig* config);
////        pStaticDataMap->map[item.first] = StaticDataCell<Spec>{item.second};
    DoubleBitBinaryConfig temp = item.second;
    StaticDataCell_for_DoubleBitBinary sStaticDataCell_for_DoubleBitBinary;
    StaticDataCell_for_DoubleBitBinary_in_StaticDataCell_for_DoubleBitBinaryOver1(&sStaticDataCell_for_DoubleBitBinary, &temp);
    pStaticDataMap->map[item.first] = sStaticDataCell_for_DoubleBitBinary;
  }
}
