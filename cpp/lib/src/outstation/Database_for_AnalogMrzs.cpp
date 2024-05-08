#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
//#include <QApplication>
#include "header.h"
#include "Database_for_AnalogMrzs.h"

////template<class Spec> bool load_type(StaticDataMap<Spec>& map, HeaderWriter& writer)
boolean load_type_for_Analog_in_DatabaseMrzs_static(StaticDataMap_for_AnalogMrzs* map, HeaderWriter* writer)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{load_type_for_Analog_in_DatabaseMrzs_static1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*map->sizeMap_for_AnalogMrzs= "<<map->sizeMap_for_AnalogMrzs<<'\n';
#endif
  //  StaticDataRecord_for_Analog *iterBegin = 
  setIteratorBegin_StaticDataMap_for_AnalogMrzs(map);
///*
  while (true)
  {
//*/
#ifdef  LOG_INFO
  uint16_t start = map->selected_in_StaticDataMap_for_AnalogMrzs.start;
  uint16_t stop  = map->selected_in_StaticDataMap_for_AnalogMrzs.stop;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*uint16_t start= "<<start<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*uint16_t stop= "<<stop<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*load_type_for_Analog_in_DatabaseMrzs_static2"<<'\n';
#endif

//void IteratorBegin_StaticDataMap_for_AnalogMrzs(StaticDataMap_for_AnalogMrzs *pStaticDataMap_for_AnalogMrzs)
////    auto iter = map.begin();
   StaticDataRecord_for_Analog* iterBegin = getIteratorBegin_StaticDataMap_for_AnalogMrzs(map);
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*load_type_for_Analog_in_DatabaseMrzs_static2a"<<'\n';
#endif
//StaticDataCell_for_Analog sss = iter->second;
//#ifdef  LOG_INFO
//uint16_t index1 = iter.first;////!
//    std::cout<<"*"<<getString_stack_info();
//    std::cout<<"*uint16_t index=  "<<(uint16_t)index1<<'\n';
//#endif

//Iterator_StaticDataMap_for_AnalogMrzs getIterator_StaticDataMap_for_AnalogMrzs(StaticDataMap_for_AnalogMrzs *pStaticDataMap_for_AnalogMrzs);
//boolean operatorEQ_in_Iterator_StaticDataMap_for_AnalogMrzs(Iterator_StaticDataMap_for_AnalogMrzs* iter1, Iterator_StaticDataMap_for_AnalogMrzs* iter2)
////    if (iter == map.end())
//Iterator_StaticDataMap_for_AnalogMrzs cIter = getIterator_StaticDataMap_for_AnalogMrzs(map);
//Iterator_StaticDataMap_for_AnalogMrzs eIter = IteratorEnd_StaticDataMap_for_AnalogMrzs(map);
StaticDataRecord_for_Analog* iterEnd = IteratorEnd_StaticDataMap_for_AnalogMrzs(map);

//boolean ttt = operatorEQ_in_Iterator_StaticDataMap_for_AnalogMrzs(&cIter, &eIter);

//    if (operatorEQ_in_Iterator_StaticDataMap_for_AnalogMrzs(&cIter, &eIter))
    if(iterBegin == iterEnd)
    {
///*
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"}load_type_for_Analog_in_DatabaseMrzs_static1_"<<'\n';
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*if (iter == map.end())"<<'\n';
    decrement_stack_info();
#endif
      // there is no data left to write
      return true;
//*/
    }

#ifdef  LOG_INFO
  start = map->selected_in_StaticDataMap_for_AnalogMrzs.start;
  stop  = map->selected_in_StaticDataMap_for_AnalogMrzs.stop;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*uint16_t start= "<<start<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*uint16_t stop= "<<stop<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*load_type_for_Analog_in_DatabaseMrzs_static3"<<'\n';
#endif

////SelectedValue_for_AnalogSpec ttt = (*iter).second;////!
////uint16_t index = (*iter).first;////!

    StaticDataRecord_for_Analog *record = iterBegin;//cIter.begin;
    uint16_t index = record->index_in_StaticDataRecord_for_Analog;


////    StaticAnalogVariation_uint8_t variation = (*iter).second.variation;
    StaticAnalogVariation_uint8_t variation = record->sStaticDataCell_for_Analog.selection_in_StaticDataCell.variation;
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*StaticAnalogVariation_uint8_t variation= "<<(uint16_t)variation<<'\n';
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*uint16_t index=  "<<(uint16_t)index<<'\n';
#endif
///*
//typedef boolean  (* static_write_func_t_for_AnalogSpec)(StaticDataMap_for_AnalogSpec& map, HeaderWriter* writer);//указатель на ф-цию
//static_write_func_t_for_AnalogSpec                   get_for_AnalogSpec_static(StaticAnalogVariation_uint8_t variation);
////        if (!StaticWriters::get((*iter).second.variation)(map, writer))
    if (!get_for_AnalogMrzs_in_StaticWriters_static(variation)(map, writer))
    {
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"}load_type_for_Analog_in_DatabaseMrzs_static2_"<<'\n';
    decrement_stack_info();
#endif
#ifdef  LOG_INFO
  start = map->selected_in_StaticDataMap_for_AnalogMrzs.start;
  stop  = map->selected_in_StaticDataMap_for_AnalogMrzs.stop;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*uint16_t start= "<<start<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*uint16_t stop= "<<stop<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*load_type_for_Analog_in_DatabaseMrzs_static4"<<'\n';
#endif

      // the APDU is full
      return false;
    }
//*/
#ifdef  LOG_INFO
  start = map->selected_in_StaticDataMap_for_AnalogMrzs.start;
  stop  = map->selected_in_StaticDataMap_for_AnalogMrzs.stop;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*uint16_t start= "<<start<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*uint16_t stop= "<<stop<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*load_type_for_Analog_in_DatabaseMrzs_static5"<<'\n';
#endif
///*
  }//while
//*/
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"}load_type_for_Analog_in_DatabaseMrzs_static3_"<<'\n';
    decrement_stack_info();
#endif
  return false;
}
///*
IINField select_range_for_AnalogMrzs_in_Database_staticOver2(StaticDataMap_for_AnalogMrzs* map,
    Range* range, StaticAnalogVariation_uint8_t variation)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{select_range_for_AnalogMrzs_in_Database_staticOver2_1"<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*range->start= "<<range->start<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*range->stop= "<<range->stop<<'\n';
#endif
//uint16_t select_in_StaticDataMap_for_AnalogSpecOver4(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec, Range range, StaticAnalogVariation_uint8_t variation);
////    const auto count = map.select(range, variation);
uint16_t count = select_in_StaticDataMap_for_AnalogMrzsOver5(map, *range, variation);

////    return (count != range.Count()) ? IINField(IINBit::PARAM_ERROR) : IINField::Empty();
  IINField iIINField;
  IINField_in_IINFieldOver2(&iIINField, IINBit_PARAM_ERROR);

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"*uint16_t count= "<<count<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"}select_range_for_AnalogMrzs_in_Database_staticOver2__"<<'\n';
  decrement_stack_info();
#endif
  return (count != Count_in_Range(range)) ? iIINField : Empty_in_IINField_static();
}
//*/
IINField select_all_StaticDataMap_for_AnalogMrzs_in_Database_staticOver2(StaticDataMap_for_AnalogMrzs* map, StaticAnalogVariation_uint8_t variation)
{
////    map.select_all(variation);
  select_all_in_StaticDataMap_for_AnalogMrzsOver3(map, variation);
////    return IINField::Empty();
  return Empty_in_IINField_static();
}
