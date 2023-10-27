#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include <QApplication>
#include "header.h"
#include "StaticWriters_for_Analog.h"

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
boolean LoadWithRangeIterator_AnalogSpec_for_UInt8_in_StaticWriters(StaticDataMap_for_AnalogSpec& map,
    RangeWriteIterator_for_UInt8_Analog *writer, StaticAnalogVariation_uint8_t variation)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"LoadWithRangeIterator_AnalogSpec_for_UInt8_in_StaticWriters1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*map.size()= "<<map.map.size()<<'\n';
  decrement_stack_info();
#endif
////    auto next_index = map.get_selected_range().start;
  uint16_t  next_index = get_selected_range_in_StaticDataMap_for_AnalogSpec(&map).start;

  for (const auto& elem : map)
  {
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*for_in_8"<<'\n';
  decrement_stack_info();
#endif
    if (elem.second.variation != variation)
    {
      // the variation has changed
      return true;
    }

    if (elem.first != next_index)
    {
      // we've loaded all we can with a contiguous range
// мы загрузили все, что могли, в непрерывном диапазоне
      return true;
    }

//boolean Write_in_RangeWriteIterator_for_UInt8_Analog(RangeWriteIterator_for_UInt8_Analog *pRangeWriteIterator_for_UInt8_Analog,
//    Analog* value);
////        if (!writer.Write(elem.second.value))
    if (!Write_in_RangeWriteIterator_for_UInt8_Analog(writer, &elem.second.value))//.tTypedMeasurement_for_Double64.value))
    {
      return false;
    }

    ++next_index;
  }

  return true;
}
//----------------------------------------LoadWithRangeIterator_AnalogSpec_for_UInt8---------------------------------------------------------
//----------------------------------------LoadWithRangeIterator_AnalogSpec_for_UInt16---------------------------------------------------------
////template<class Spec, class IndexType>
////bool LoadWithRangeIterator(StaticDataMap<Spec>& map,
////                           RangeWriteIterator<IndexType, typename Spec::meas_t>& writer,
////                           typename Spec::static_variation_t variation)
boolean LoadWithRangeIterator_AnalogSpec_for_UInt16_in_StaticWriters(StaticDataMap_for_AnalogSpec& map,
    RangeWriteIterator_for_UInt16_Analog *writer, StaticAnalogVariation_uint8_t variation)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"LoadWithRangeIterator_AnalogSpec_for_UInt16_in_StaticWriters1"<<'\n';
  decrement_stack_info();
#endif
////    auto next_index = map.get_selected_range().start;
  uint16_t  next_index = get_selected_range_in_StaticDataMap_for_AnalogSpec(&map).start;

  for (const auto& elem : map)
  {
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*for_in_16"<<'\n';
  decrement_stack_info();
#endif

    if (elem.second.variation != variation)
    {
      // the variation has changed
      return true;
    }

    if (elem.first != next_index)
    {
      // we've loaded all we can with a contiguous range
      return true;
    }

//boolean Write_in_RangeWriteIterator_for_UInt16_Analog(RangeWriteIterator_for_UInt16_Analog *pRangeWriteIterator_for_UInt16_Analog,
//    Analog* value);
////        if (!writer.Write(elem.second.value))
    if (!Write_in_RangeWriteIterator_for_UInt16_Analog(writer, &elem.second.value))//.tTypedMeasurement_for_Double64.value))
    {
      return false;
    }

    ++next_index;
  }

  return true;
}
//----------------------------------------LoadWithRangeIterator_AnalogSpec_for_UInt16---------------------------------------------------------

////template<class Spec, class Serializer> bool WriteWithSerializer(StaticDataMap<Spec>& map, HeaderWriter& writer)
////{
////    const auto range = map.get_selected_range();
////
////    if (range.IsOneByte())
////    {
////        auto iter = writer.IterateOverRange<ser4cpp::UInt8, typename Serializer::Target>(
////            QualifierCode::UINT8_START_STOP, Serializer::Inst(), static_cast<uint8_t>(range.start));
////        return LoadWithRangeIterator<Spec, ser4cpp::UInt8>(map, iter, Serializer::svariation);
////    }
////
////    auto iter = writer.IterateOverRange<ser4cpp::UInt16, typename Serializer::Target>(QualifierCode::UINT16_START_STOP,
////                                                                                      Serializer::Inst(), range.start);
////    return LoadWithRangeIterator<Spec, ser4cpp::UInt16>(map, iter, Serializer::svariation);
////}
//----------------------------------------------Group30Var1------------------------------------------

////template<class Spec, class Serializer> bool WriteWithSerializer(StaticDataMap<Spec>& map, HeaderWriter& writer)
boolean WriteWithSerializer_AnalogSpec_for_Group30Var1_in_StaticWriters_static(StaticDataMap_for_AnalogSpec& map, HeaderWriter* writer)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"WriteWithSerializer_AnalogSpec_for_Group30Var1_in_StaticWriters_static1"<<'\n';
#endif

////    const auto range = map.get_selected_range();
  Range  range = get_selected_range_in_StaticDataMap_for_AnalogSpec(&map);

#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*range.start= "<<(uint16_t)range.start<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*range.stop= "<<(uint16_t)range.stop<<'\n';
  decrement_stack_info();
#endif

////    if (range.IsOneByte())
  if (IsOneByte_in_Range(&range))
  {
//RangeWriteIterator_for_UInt8_Analog IterateOverRange_for_UInt8_Analog_in_HeaderWriter(HeaderWriter *pHeaderWriter,
//    QualifierCode_uint8_t qc,
//    DNP3Serializer_for_Analog *serializer,
//    uint8_t start );
//DNP3Serializer_for_Analog  Inst_in_Group30Var1_static(void);
////        auto iter = writer.IterateOverRange<ser4cpp::UInt8, typename Serializer::Target>(
////            QualifierCode::UINT8_START_STOP, Serializer::Inst(), static_cast<uint8_t>(range.start));
    DNP3Serializer_for_Analog tmp = Inst_in_Group30Var1_static();
    RangeWriteIterator_for_UInt8_Analog iter = IterateOverRange_for_UInt8_Analog_in_HeaderWriter(writer,
        QualifierCode_UINT8_START_STOP,
        &tmp,
        (uint8_t) range.start );

//boolean LoadWithRangeIterator_AnalogSpec_for_UInt8_in_StaticWriters(StaticDataMap_for_AnalogSpec& map,
//    RangeWriteIterator_for_UInt8_Analog *writer, StaticAnalogVariation_uint8_t variation)
////        return LoadWithRangeIterator<Spec, ser4cpp::UInt8>(map, iter, Serializer::svariation);
    boolean btmp = LoadWithRangeIterator_AnalogSpec_for_UInt8_in_StaticWriters(map, &iter, StaticAnalogVariation_Group30Var1);
    RangeWriteIterator_for_UInt8_Analog_destr_RangeWriteIterator_for_UInt8_Analog(&iter);
    return btmp;
  }

////    auto iter = writer.IterateOverRange<ser4cpp::UInt16, typename Serializer::Target>(QualifierCode::UINT16_START_STOP,
////                                                                                      Serializer::Inst(), range.start);
  DNP3Serializer_for_Analog tmp = Inst_in_Group30Var1_static();
  RangeWriteIterator_for_UInt16_Analog iter = IterateOverRange_for_UInt16_Analog_in_HeaderWriter(writer,
      QualifierCode_UINT16_START_STOP,
      &tmp,
      (uint16_t) range.start );

////    return LoadWithRangeIterator<Spec, ser4cpp::UInt16>(map, iter, Serializer::svariation);
  boolean btmp = LoadWithRangeIterator_AnalogSpec_for_UInt16_in_StaticWriters(map, &iter, StaticAnalogVariation_Group30Var1);
  RangeWriteIterator_for_UInt16_Analog_destr_RangeWriteIterator_for_UInt16_Analog(&iter);

  return btmp;
}
//----------------------------------------------Group30Var1------------------------------------------
//----------------------------------------------Group30Var2------------------------------------------

////template<class Spec, class Serializer> bool WriteWithSerializer(StaticDataMap<Spec>& map, HeaderWriter& writer)
boolean WriteWithSerializer_AnalogSpec_for_Group30Var2_in_StaticWriters_static(StaticDataMap_for_AnalogSpec& map, HeaderWriter* writer)
{
////    const auto range = map.get_selected_range();
  Range  range = get_selected_range_in_StaticDataMap_for_AnalogSpec(&map);

////    if (range.IsOneByte())
  if (IsOneByte_in_Range(&range))
  {
//RangeWriteIterator_for_UInt8_Analog IterateOverRange_for_UInt8_Analog_in_HeaderWriter(HeaderWriter *pHeaderWriter,
//    QualifierCode_uint8_t qc,
//    DNP3Serializer_for_Analog *serializer,
//    uint8_t start );
//DNP3Serializer_for_Analog  Inst_in_Group30Var2_static(void);
////        auto iter = writer.IterateOverRange<ser4cpp::UInt8, typename Serializer::Target>(
////            QualifierCode::UINT8_START_STOP, Serializer::Inst(), static_cast<uint8_t>(range.start));
    DNP3Serializer_for_Analog tmp = Inst_in_Group30Var2_static();
    RangeWriteIterator_for_UInt8_Analog iter = IterateOverRange_for_UInt8_Analog_in_HeaderWriter(writer,
        QualifierCode_UINT8_START_STOP,
        &tmp,
        (uint8_t) range.start );

//boolean LoadWithRangeIterator_AnalogSpec_for_UInt8_in_StaticWriters(StaticDataMap_for_AnalogSpec& map,
//    RangeWriteIterator_for_UInt8_Analog *writer, StaticAnalogVariation_uint8_t variation)
////        return LoadWithRangeIterator<Spec, ser4cpp::UInt8>(map, iter, Serializer::svariation);
    boolean btmp = LoadWithRangeIterator_AnalogSpec_for_UInt8_in_StaticWriters(map, &iter, StaticAnalogVariation_Group30Var2);
    RangeWriteIterator_for_UInt8_Analog_destr_RangeWriteIterator_for_UInt8_Analog(&iter);
    return btmp;
  }

////    auto iter = writer.IterateOverRange<ser4cpp::UInt16, typename Serializer::Target>(QualifierCode::UINT16_START_STOP,
////                                                                                      Serializer::Inst(), range.start);
  DNP3Serializer_for_Analog tmp = Inst_in_Group30Var2_static();
  RangeWriteIterator_for_UInt16_Analog iter = IterateOverRange_for_UInt16_Analog_in_HeaderWriter(writer,
      QualifierCode_UINT16_START_STOP,
      &tmp,
      (uint16_t) range.start );

////    return LoadWithRangeIterator<Spec, ser4cpp::UInt16>(map, iter, Serializer::svariation);
  boolean btmp = LoadWithRangeIterator_AnalogSpec_for_UInt16_in_StaticWriters(map, &iter, StaticAnalogVariation_Group30Var2);
  RangeWriteIterator_for_UInt16_Analog_destr_RangeWriteIterator_for_UInt16_Analog(&iter);
  return btmp;
}
//----------------------------------------------Group30Var2------------------------------------------

////static_write_func_t<AnalogSpec> StaticWriters::get(StaticAnalogVariation variation)
static_write_func_t_for_AnalogSpec get_for_AnalogSpec_in_StaticWriters_static(StaticAnalogVariation_uint8_t variation)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"get_for_AnalogSpec_in_StaticWriters_static1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*StaticAnalogVariation_uint8_t variation= "<<(uint16_t)variation<<'\n';
#endif
  switch (variation)
  {
  case (StaticAnalogVariation_Group30Var1):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*StaticAnalogVariation_Group30Var1"<<'\n';
    decrement_stack_info();
#endif
////        return &WriteWithSerializer<AnalogSpec, Group30Var1>;
    return WriteWithSerializer_AnalogSpec_for_Group30Var1_in_StaticWriters_static;

  case (StaticAnalogVariation_Group30Var2):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*StaticAnalogVariation_Group30Var2"<<'\n';
    decrement_stack_info();
#endif
////        return &WriteWithSerializer<AnalogSpec, Group30Var2>;
    return WriteWithSerializer_AnalogSpec_for_Group30Var2_in_StaticWriters_static;

////    case (StaticAnalogVariation::Group30Var3):
////        return &WriteWithSerializer<AnalogSpec, Group30Var3>;
////    case (StaticAnalogVariation::Group30Var4):
////        return &WriteWithSerializer<AnalogSpec, Group30Var4>;
////    case (StaticAnalogVariation::Group30Var5):
////        return &WriteWithSerializer<AnalogSpec, Group30Var5>;
////    case (StaticAnalogVariation::Group30Var6):
////        return &WriteWithSerializer<AnalogSpec, Group30Var6>;
  default:
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*WriteWithSerializer_AnalogSpec_for_Group30Var1_in_StaticWriters_static"<<'\n';
    decrement_stack_info();
#endif
////        return &WriteWithSerializer<AnalogSpec, Group30Var1>;
    return WriteWithSerializer_AnalogSpec_for_Group30Var1_in_StaticWriters_static;
  }
}
