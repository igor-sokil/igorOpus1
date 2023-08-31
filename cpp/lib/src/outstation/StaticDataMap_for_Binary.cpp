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

Range get_selected_range_in_StaticDataMap_for_BinarySpec(StaticDataMap_for_BinarySpec *pStaticDataMap_for_BinarySpec)
{
  return pStaticDataMap_for_BinarySpec->selected;
}

typename StaticDataMap_for_BinarySpec::iterator StaticDataMap_for_BinarySpec::begin()
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

////template<class Spec> typename StaticDataMap<Spec>::iterator StaticDataMap<Spec>::end()
typename StaticDataMap_for_BinarySpec::iterator StaticDataMap_for_BinarySpec::end()
{
  return iterator(this->map.end(), this->map.end(), this->selected);
}
