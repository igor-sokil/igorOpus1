#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
//#include <QApplication>
#include "header.h"
#include "StaticWriters_for_AnalogMrzs.h"

#include "Group1.h"
#include "Group10.h"
#include "Group20.h"
#include "Group21.h"
#include "Group3.h"
#include "Group30.h"
#include "Group40.h"
#include "Group50.h"
//#include "OctetStringSerializer.h"
#include "HeaderWriter_for_Analog.h"

//----------------------------------------LoadWithRangeIterator_AnalogSpec_for_UInt8---------------------------------------------------------
////template<class Spec, class IndexType>
////bool LoadWithRangeIterator(StaticDataMap<Spec>& map,
////                           RangeWriteIterator<IndexType, typename Spec::meas_t>& writer,
////                           typename Spec::static_variation_t variation)
boolean LoadWithRangeIterator_AnalogMrzs_for_UInt8_in_StaticWriters(StaticDataMap_for_AnalogMrzs* map,
    RangeWriteIterator_for_UInt8_Analog *writer, StaticAnalogVariation_uint8_t variation)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{LoadWithRangeIterator_AnalogMrzs_for_UInt8_in_StaticWriters1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*map.size()= "<<map->sizeMap_for_AnalogMrzs<<'\n';
#endif
////    auto next_index = map.get_selected_range().start;
  uint16_t  next_index = get_selected_range_in_StaticDataMap_for_AnalogMrzs(map).start;
///*
//StaticDataRecord_for_Analog* Increment_in_Iterator_StaticDataMap_for_AnalogMrzs(Iterator_StaticDataMap_for_AnalogMrzs *pIterator_StaticDataMap_for_AnalogMrzs)
//StaticDataRecord_for_Analog *begin = mapBegin_in_StaticDataMap_for_AnalogMrzs(map);
  StaticDataRecord_for_Analog *endIter   = mapEnd_in_StaticDataMap_for_AnalogMrzs(map);
//StaticDataRecord_for_Analog* current = begin;
  StaticDataRecord_for_Analog* beginIter = NULL;
////  for (const auto& elem : map)
//  do
//  {
  setIteratorBegin_StaticDataMap_for_AnalogMrzs(map);
//for(int idx=0; idx<5; idx++)
do
{
//SelectedValue_for_AnalogSpec ttt = elem.second;////!
  //StaticDataRecord_for_Analog* 
  beginIter = getIteratorBegin_StaticDataMap_for_AnalogMrzs(map);
///*
if(beginIter >= endIter)
{
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"*LoadWithRangeIterator_AnalogMrzs_for_UInt8_in_StaticWriters5"<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*StaticDataRecord_for_Analog* beginIter= "<<(uint32_t)beginIter<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*StaticDataRecord_for_Analog* endIter= "<<(uint32_t)endIter<<'\n';
#endif
  break;
}//if
//*/
/*
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"*LoadWithRangeIterator_AnalogMrzs_for_UInt8_in_StaticWriters2"<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*beginIter->index_in_StaticDataRecord_for_Analog= "<<beginIter->index_in_StaticDataRecord_for_Analog<<'\n';
#endif
*/
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"*LoadWithRangeIterator_AnalogMrzs_for_UInt8_in_StaticWriters7"<<'\n';
//  uint16_t valueIndex = beginIter->index_in_StaticDataRecord_for_Analog;
  std::cout<<getString_stack_info();
  std::cout<<"*Cell.variation= "<<(uint16_t)beginIter->sStaticDataCell_for_Analog.selection_in_StaticDataCell.variation<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*variation= "<<(uint16_t)variation<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*selection_in_StaticDataCell.selected= "<<(uint16_t)beginIter->sStaticDataCell_for_Analog.selection_in_StaticDataCell.selected_in_SelectedValue_for_AnalogSpec<<'\n';
#endif
/*
    if (elem.second.variation != variation)
    {
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}LoadWithRangeIterator_AnalogSpec_for_UInt8_in_StaticWriters1_"<<'\n';
  decrement_stack_info();
#endif
      // the variation has changed
      return true;
    }

    if (elem.first != next_index)
    {
      // we've loaded all we can with a contiguous range
// мы загрузили все, что могли, в непрерывном диапазоне
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}LoadWithRangeIterator_AnalogSpec_for_UInt8_in_StaticWriters2_"<<'\n';
  decrement_stack_info();
#endif
      return true;
    }
*/
//boolean Write_in_RangeWriteIterator_for_UInt8_Analog(RangeWriteIterator_for_UInt8_Analog *pRangeWriteIterator_for_UInt8_Analog,
//    Analog* value);
////        if (!writer.Write(elem.second.value))
//beginIter->
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"*LoadWithRangeIterator_AnalogMrzs_for_UInt8_in_StaticWriters6"<<'\n';
  uint16_t valueIndex = beginIter->index_in_StaticDataRecord_for_Analog;
  std::cout<<getString_stack_info();
  std::cout<<"*valueIndex= "<<valueIndex<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*next_index= "<<next_index<<'\n';
//map_StaticDataMap_for_AnalogMrzs[beginIter->index_in_StaticDataRecord_for_Analog]
  inspect_Analog(&(beginIter->sStaticDataCell_for_Analog.selection_in_StaticDataCell.value));
#endif
///*
    if (!Write_in_RangeWriteIterator_for_UInt8_Analog(writer,
     &(beginIter->sStaticDataCell_for_Analog.selection_in_StaticDataCell.value)))//&elem.second.value))
    {
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}LoadWithRangeIterator_AnalogMrzs_for_UInt8_in_StaticWriters3_"<<'\n';
  decrement_stack_info();
#endif
      return false;
    }
//*/
    ++next_index;
//void operatorPLUS_in_StaticDataMap_for_AnalogMrzs(StaticDataMap_for_AnalogMrzs *pStaticDataMap_for_AnalogMrzs)
////    beginIter++;

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"*LoadWithRangeIterator_AnalogMrzs_for_UInt8_in_StaticWriters3"<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*StaticDataRecord_for_AnalogMrzs *beginIter= "<<(uint32_t)getIteratorBegin_StaticDataMap_for_AnalogMrzs(map)<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*begin->index_in_StaticDataRecord_for_Analog= "<<beginIter->index_in_StaticDataRecord_for_Analog<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*StaticDataRecord_for_AnalogMrzs *endIter= "<<(uint32_t)endIter<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*StaticDataRecord_for_Analog* beginIter->index_in_StaticDataRecord_for_Analog= "<<beginIter->index_in_StaticDataRecord_for_Analog<<'\n';
#endif

 operatorPLUS_in_StaticDataMap_for_AnalogMrzs(map);
// beginIter = getIteratorBegin_StaticDataMap_for_AnalogMrzs(map);
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"*LoadWithRangeIterator_AnalogMrzs_for_UInt8_in_StaticWriters3a"<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*StaticDataRecord_for_AnalogMrzs *beginIter= "<<(uint32_t)getIteratorBegin_StaticDataMap_for_AnalogMrzs(map)<<'\n';
#endif

//  } while(begin < end);
/*
if(beginIter >= endIter)
{
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"*LoadWithRangeIterator_AnalogMrzs_for_UInt8_in_StaticWriters5"<<'\n';
#endif
  break;
}//if
*/
/*
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"*LoadWithRangeIterator_AnalogMrzs_for_UInt8_in_StaticWriters5"<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*StaticDataRecord_for_Analog* beginIter= "<<(uint32_t)beginIter<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*StaticDataRecord_for_Analog* endIter= "<<(uint32_t)endIter<<'\n';
#endif
*/
} while(beginIter < endIter);//for
//*/
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}LoadWithRangeIterator_AnalogMrzs_for_UInt8_in_StaticWriters4_"<<'\n';
  decrement_stack_info();
#endif
  return true;
}
//----------------------------------------LoadWithRangeIterator_AnalogSpec_for_UInt8---------------------------------------------------------
//----------------------------------------------Group30Var2------------------------------------------
////template<class Spec, class Serializer> bool WriteWithSerializer(StaticDataMap<Spec>& map, HeaderWriter& writer)
boolean WriteWithSerializer_AnalogMrzs_for_Group30Var2_in_StaticWriters_static(StaticDataMap_for_AnalogMrzs* map, HeaderWriter* writer)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{WriteWithSerializer_AnalogMrzs_for_Group30Var2_in_StaticWriters_static1"<<'\n';
#endif

////    const auto range = map.get_selected_range();
  Range  range = get_selected_range_in_StaticDataMap_for_AnalogMrzs(map);

#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*range.start= "<<(uint16_t)range.start<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*range.stop= "<<(uint16_t)range.stop<<'\n';
#endif

  boolean btmp = false;

////    if (range.IsOneByte())
  if (IsOneByte_in_Range(&range))
  {
/*
//RangeWriteIterator_for_UInt8_Analog IterateOverRange_for_UInt8_Analog_in_HeaderWriter(HeaderWriter *pHeaderWriter,
//    QualifierCode_uint8_t qc,
//    DNP3Serializer_for_Analog *serializer,
//    uint8_t start );
//DNP3Serializer_for_Analog  Inst_in_Group30Var2_static(void);
////        auto iter = writer.IterateOverRange<ser4cpp::UInt8, typename Serializer::Target>(
////            QualifierCode::UINT8_START_STOP, Serializer::Inst(), static_cast<uint8_t>(range.start));
*/
///*
    DNP3Serializer_for_Analog tmp = Inst_in_Group30Var2_static();
    RangeWriteIterator_for_UInt8_Analog iter = IterateOverRange_for_UInt8_Analog_in_HeaderWriter(writer,
        QualifierCode_UINT8_START_STOP,
        &tmp,
        (uint8_t) range.start );
//*/
/*
//boolean LoadWithRangeIterator_AnalogSpec_for_UInt8_in_StaticWriters(StaticDataMap_for_AnalogSpec& map,
//    RangeWriteIterator_for_UInt8_Analog *writer, StaticAnalogVariation_uint8_t variation)
////        return LoadWithRangeIterator<Spec, ser4cpp::UInt8>(map, iter, Serializer::svariation);
*/
    //boolean 
    btmp = LoadWithRangeIterator_AnalogMrzs_for_UInt8_in_StaticWriters(map, &iter, StaticAnalogVariation_Group30Var2);
///*
    RangeWriteIterator_for_UInt8_Analog_destr_RangeWriteIterator_for_UInt8_Analog(&iter);
//*/
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}WriteWithSerializer_AnalogMrzs_for_Group30Var2_in_StaticWriters_static1_"<<'\n';
  decrement_stack_info();
#endif
    return btmp;
  }
/*
////    auto iter = writer.IterateOverRange<ser4cpp::UInt16, typename Serializer::Target>(QualifierCode::UINT16_START_STOP,
////                                                                                      Serializer::Inst(), range.start);
  DNP3Serializer_for_Analog tmp = Inst_in_Group30Var2_static();
  RangeWriteIterator_for_UInt16_Analog iter = IterateOverRange_for_UInt16_Analog_in_HeaderWriter(writer,
      QualifierCode_UINT16_START_STOP,
      &tmp,
      (uint16_t) range.start );

////    return LoadWithRangeIterator<Spec, ser4cpp::UInt16>(map, iter, Serializer::svariation);
  boolean btmp = LoadWithRangeIterator_AnalogMrzs_for_UInt16_in_StaticWriters(map, &iter, StaticAnalogVariation_Group30Var2);
  RangeWriteIterator_for_UInt16_Analog_destr_RangeWriteIterator_for_UInt16_Analog(&iter);

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}WriteWithSerializer_AnalogMrzs_for_Group30Var2_in_StaticWriters_static2_"<<'\n';
  decrement_stack_info();
#endif
*/
  return btmp;
}
//----------------------------------------------Group30Var2------------------------------------------
////static_write_func_t<AnalogSpec> StaticWriters::get(StaticAnalogVariation variation)
static_write_func_t_for_AnalogMrzs get_for_AnalogMrzs_in_StaticWriters_static(StaticAnalogVariation_uint8_t variation)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"get_for_AnalogMrzs_in_StaticWriters_static1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*StaticAnalogVariation_uint8_t variation= "<<(uint16_t)variation<<'\n';
#endif
  switch (variation)
  {
/*
  case (StaticAnalogVariation_Group30Var1):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*StaticAnalogVariation_Group30Var1"<<'\n';
    decrement_stack_info();
#endif
////        return &WriteWithSerializer<AnalogSpec, Group30Var1>;
    return WriteWithSerializer_AnalogSpec_for_Group30Var1_in_StaticWriters_static;
*/
  case (StaticAnalogVariation_Group30Var2):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*StaticAnalogVariation_Group30Var2"<<'\n';
    decrement_stack_info();
#endif
////        return &WriteWithSerializer<AnalogSpec, Group30Var2>;
    return WriteWithSerializer_AnalogMrzs_for_Group30Var2_in_StaticWriters_static;
//    return WriteWithSerializer_AnalogSpec_for_Group30Var2_in_StaticWriters_static;

/*
   case (StaticAnalogVariation_Group30Var3):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*StaticAnalogVariation_Group30Var3"<<'\n';
    decrement_stack_info();
#endif
////        return &WriteWithSerializer<AnalogSpec, Group30Var3>;
    return WriteWithSerializer_AnalogSpec_for_Group30Var3_in_StaticWriters_static;

   case (StaticAnalogVariation_Group30Var4):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*StaticAnalogVariation_Group30Var4"<<'\n';
    decrement_stack_info();
#endif
////        return &WriteWithSerializer<AnalogSpec, Group30Var4>;
    return WriteWithSerializer_AnalogSpec_for_Group30Var4_in_StaticWriters_static;

   case (StaticAnalogVariation_Group30Var5):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*StaticAnalogVariation_Group30Var5"<<'\n';
    decrement_stack_info();
#endif
////        return &WriteWithSerializer<AnalogSpec, Group30Var5>;
    return WriteWithSerializer_AnalogSpec_for_Group30Var5_in_StaticWriters_static;
*/
////   case (StaticAnalogVariation::Group30Var6):
////        return &WriteWithSerializer<AnalogSpec, Group30Var6>;
  default:

#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*WriteWithSerializer_AnalogSpec_for_Group30Var1_in_StaticWriters_static"<<'\n';
    decrement_stack_info();
#endif
////        return &WriteWithSerializer<AnalogSpec, Group30Var1>;
//    return WriteWithSerializer_AnalogSpec_for_Group30Var1_in_StaticWriters_static;
    return WriteWithSerializer_AnalogMrzs_for_Group30Var2_in_StaticWriters_static;
//*/
  }
}
