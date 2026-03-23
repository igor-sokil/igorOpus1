#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
//#include "Map_for_AnalogMrzs.h"
//#include "DatabaseConfigMrzs.h"
#include "StaticDataMap_for_Analog.h"

void Iterator_Map_for_AnalogMrzs_in_Iterator_Map_for_AnalogMrzs(Iterator_Map_for_AnalogMrzs *pIterator_Map_for_AnalogMrzs,
     StaticDataRecord_for_Analog* begin, StaticDataRecord_for_Analog* end, Range *range)
{
  pIterator_Map_for_AnalogMrzs->begin = begin;
  pIterator_Map_for_AnalogMrzs->end = end;
  pIterator_Map_for_AnalogMrzs->range = *range;
}

StaticDataRecord_for_Analog *mapEnd_in_Map_for_AnalogMrzs(Map_for_AnalogMrzs *pMap_for_AnalogMrzs)
{
 return &(pMap_for_AnalogMrzs->map_for_AnalogMrzs[(pMap_for_AnalogMrzs->sizeMap_for_AnalogMrzs)]);
}

StaticDataRecord_for_Analog *mapBegin_in_Map_for_AnalogMrzs(Map_for_AnalogMrzs *pMap_for_AnalogMrzs)
{
 return &(pMap_for_AnalogMrzs->map_for_AnalogMrzs[0]);
}

StaticDataRecord_for_Analog* getIteratorBegin_Map_for_AnalogMrzs(Map_for_AnalogMrzs *pMap_for_AnalogMrzs)
{
  return pMap_for_AnalogMrzs->iIterator_Map_for_AnalogMrzs.begin;
}

StaticDataRecord_for_Analog* setIteratorBegin_Map_for_AnalogMrzs(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{setIteratorBegin_Map_for_AnalogMrzs1"<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*IteratorBegin_Map_for_AnalogMrzs::begin()1"<<'\n';
#endif

  if (!IsValid_in_Range(&(pStaticDataMap_for_AnalogSpec->selected_in_StaticDataMap_for_AnalogSpec)))
  {
////    return iterator(this->map.end(), this->map.end(), this->selected_in_StaticDataMap_for_AnalogSpec);
  Iterator_Map_for_AnalogMrzs_in_Iterator_Map_for_AnalogMrzs(&(pStaticDataMap_for_AnalogSpec->mMap_for_AnalogMrzs.iIterator_Map_for_AnalogMrzs),
      mapEnd_in_Map_for_AnalogMrzs(&(pStaticDataMap_for_AnalogSpec->mMap_for_AnalogMrzs)),
      mapEnd_in_Map_for_AnalogMrzs(&(pStaticDataMap_for_AnalogSpec->mMap_for_AnalogMrzs)),
     &(pStaticDataMap_for_AnalogSpec->selected_in_StaticDataMap_for_AnalogSpec));
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}IteratorBegin_Map_for_AnalogMrzs::begin()1_"<<'\n';
  decrement_stack_info();
#endif
   return mapEnd_in_Map_for_AnalogMrzs(&(pStaticDataMap_for_AnalogSpec->mMap_for_AnalogMrzs));
  }

////  const auto begin = this->map.lower_bound(this->selected_in_StaticDataMap_for_AnalogSpec.start);
 uint16_t start = pStaticDataMap_for_AnalogSpec->selected_in_StaticDataMap_for_AnalogSpec.start;
 StaticDataRecord_for_Analog* begin = &(pStaticDataMap_for_AnalogSpec->mMap_for_AnalogMrzs.map_for_AnalogMrzs[start]);

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"*IteratorBegin_StaticDataMap_for_AnalogMrzs2"<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*StaticDataRecord_for_Analog* begin= "<<(uint32_t)begin<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*uint16_t start = "<<start<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*StaticDataRecord_for_Analog* begin.index_in_StaticDataRecord_for_Analog= "<<begin->index_in_StaticDataRecord_for_Analog<<'\n';
#endif

////  return iterator(begin, this->map.end(), this->selected_in_StaticDataMap_for_AnalogSpec);
  Iterator_Map_for_AnalogMrzs_in_Iterator_Map_for_AnalogMrzs(&(pStaticDataMap_for_AnalogSpec->mMap_for_AnalogMrzs.iIterator_Map_for_AnalogMrzs),
      begin,
      mapEnd_in_Map_for_AnalogMrzs(&(pStaticDataMap_for_AnalogSpec->mMap_for_AnalogMrzs)),//pStaticDataMap_for_AnalogMrzs),
     &(pStaticDataMap_for_AnalogSpec->selected_in_StaticDataMap_for_AnalogSpec));

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"*IteratorBegin_StaticDataMap_for_AnalogMrzs::begin()2_"<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"}setIteratorBegin_StaticDataMap_for_AnalogMrzs2_"<<'\n';
  decrement_stack_info();
#endif
  return begin;
}

StaticDataRecord_for_Analog* setIteratorEnd_Map_for_AnalogMrzs(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{IteratorEnd_Map_for_AnalogMrzs::end()1"<<'\n';
#endif
////  return iterator(this->map.end(), this->map.end(), this->selected_in_StaticDataMap_for_AnalogSpec);
//  Iterator_StaticDataMap_for_AnalogMrzs iterEnd;
  Iterator_Map_for_AnalogMrzs_in_Iterator_Map_for_AnalogMrzs(&(pStaticDataMap_for_AnalogSpec->mMap_for_AnalogMrzs.iIterator_Map_for_AnalogMrzs),
      mapEnd_in_Map_for_AnalogMrzs(&(pStaticDataMap_for_AnalogSpec->mMap_for_AnalogMrzs)),
      mapEnd_in_Map_for_AnalogMrzs(&(pStaticDataMap_for_AnalogSpec->mMap_for_AnalogMrzs)),
     &(pStaticDataMap_for_AnalogSpec->selected_in_StaticDataMap_for_AnalogSpec));
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}IteratorEnd_StaticDataMap_for_AnalogSpec::end()_"<<'\n';
  decrement_stack_info();
#endif
//  return mapEnd_in_StaticDataMap_for_AnalogMrzs(pStaticDataMap_for_AnalogMrzs);
   return mapEnd_in_Map_for_AnalogMrzs(&(pStaticDataMap_for_AnalogSpec->mMap_for_AnalogMrzs));
}
