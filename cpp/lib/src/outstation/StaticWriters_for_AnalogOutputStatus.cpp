#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include <QApplication>
#include "header.h"
#include "StaticWriters_for_AnalogOutputStatus.h"

#include "Group1.h"
#include "Group10.h"
#include "Group20.h"
#include "Group21.h"
#include "Group3.h"
#include "Group30.h"
#include "Group40.h"
#include "Group50.h"
//#include "OctetStringSerializer.h"
#include "HeaderWriter_for_AnalogOutputStatus.h"

//----------------------------------------LoadWithRangeIterator_AnalogOutputStatusSpec_for_UInt8---------------------------------------------------------
////template<class Spec, class IndexType>
////bool LoadWithRangeIterator(StaticDataMap<Spec>& map,
////                           RangeWriteIterator<IndexType, typename Spec::meas_t>& writer,
////                           typename Spec::static_variation_t variation)
boolean LoadWithRangeIterator_AnalogOutputStatusSpec_for_UInt8_in_StaticWriters(StaticDataMap_for_AnalogOutputStatusSpec& map,
    RangeWriteIterator_for_UInt8_AnalogOutputStatus *writer, StaticAnalogOutputStatusVariation_uint8_t variation)
{
////    auto next_index = map.get_selected_range().start;
  uint16_t  next_index = get_selected_range_in_StaticDataMap_for_AnalogOutputStatusSpec(&map).start;

  for (const auto& elem : map)
  {
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

//boolean Write_in_RangeWriteIterator_for_UInt8_AnalogOutputStatus(RangeWriteIterator_for_UInt8_AnalogOutputStatus *pRangeWriteIterator_for_UInt8_AnalogOutputStatus,
//    AnalogOutputStatus* value);
////        if (!writer.Write(elem.second.value))
    if (!Write_in_RangeWriteIterator_for_UInt8_AnalogOutputStatus(writer, &elem.second.value))//.tTypedMeasurement_for_Double64.value))
    {
      return false;
    }

    ++next_index;
  }

  return true;
}
//----------------------------------------LoadWithRangeIterator_AnalogOutputStatusSpec_for_UInt8---------------------------------------------------------
//----------------------------------------LoadWithRangeIterator_AnalogOutputStatusSpec_for_UInt16---------------------------------------------------------
////template<class Spec, class IndexType>
////bool LoadWithRangeIterator(StaticDataMap<Spec>& map,
////                           RangeWriteIterator<IndexType, typename Spec::meas_t>& writer,
////                           typename Spec::static_variation_t variation)
boolean LoadWithRangeIterator_AnalogOutputStatusSpec_for_UInt16_in_StaticWriters(StaticDataMap_for_AnalogOutputStatusSpec& map,
    RangeWriteIterator_for_UInt16_AnalogOutputStatus *writer, StaticAnalogOutputStatusVariation_uint8_t variation)
{
////    auto next_index = map.get_selected_range().start;
  uint16_t  next_index = get_selected_range_in_StaticDataMap_for_AnalogOutputStatusSpec(&map).start;

  for (const auto& elem : map)
  {
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

//boolean Write_in_RangeWriteIterator_for_UInt16_AnalogOutputStatus(RangeWriteIterator_for_UInt16_AnalogOutputStatus *pRangeWriteIterator_for_UInt16_AnalogOutputStatus,
//    AnalogOutputStatus* value);
////        if (!writer.Write(elem.second.value))
    if (!Write_in_RangeWriteIterator_for_UInt16_AnalogOutputStatus(writer, &elem.second.value))//.tTypedMeasurement_for_Double64.value))
    {
      return false;
    }

    ++next_index;
  }

  return true;
}
//----------------------------------------LoadWithRangeIterator_AnalogOutputStatusSpec_for_UInt16---------------------------------------------------------

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
//----------------------------------------------Group40Var1------------------------------------------

////template<class Spec, class Serializer> bool WriteWithSerializer(StaticDataMap<Spec>& map, HeaderWriter& writer)
boolean WriteWithSerializer_AnalogOutputStatusSpec_for_Group40Var1_in_StaticWriters_static(StaticDataMap_for_AnalogOutputStatusSpec& map, HeaderWriter* writer)
{
////    const auto range = map.get_selected_range();
  Range  range = get_selected_range_in_StaticDataMap_for_AnalogOutputStatusSpec(&map);

////    if (range.IsOneByte())
  if (IsOneByte_in_Range(&range))
  {
//RangeWriteIterator_for_UInt8_AnalogOutputStatus IterateOverRange_for_UInt8_AnalogOutputStatus_in_HeaderWriter(HeaderWriter *pHeaderWriter,
//    QualifierCode_uint8_t qc,
//    DNP3Serializer_for_AnalogOutputStatus *serializer,
//    uint8_t start );
//DNP3Serializer_for_AnalogOutputStatus  Inst_in_Group40Var1_static(void);
////        auto iter = writer.IterateOverRange<ser4cpp::UInt8, typename Serializer::Target>(
////            QualifierCode::UINT8_START_STOP, Serializer::Inst(), static_cast<uint8_t>(range.start));
    DNP3Serializer_for_AnalogOutputStatus tmp = Inst_in_Group40Var1_static();
    RangeWriteIterator_for_UInt8_AnalogOutputStatus iter = IterateOverRange_for_UInt8_AnalogOutputStatus_in_HeaderWriter(writer,
        QualifierCode_UINT8_START_STOP,
        &tmp,
        (uint8_t) range.start );

//boolean LoadWithRangeIterator_AnalogOutputStatusSpec_for_UInt8_in_StaticWriters(StaticDataMap_for_AnalogOutputStatusSpec& map,
//    RangeWriteIterator_for_UInt8_AnalogOutputStatus *writer, StaticAnalogOutputStatusVariation_uint8_t variation)
////        return LoadWithRangeIterator<Spec, ser4cpp::UInt8>(map, iter, Serializer::svariation);
    boolean btmp = LoadWithRangeIterator_AnalogOutputStatusSpec_for_UInt8_in_StaticWriters(map, &iter, StaticAnalogOutputStatusVariation_Group40Var1);
    RangeWriteIterator_for_UInt8_AnalogOutputStatus_destr_RangeWriteIterator_for_UInt8_AnalogOutputStatus(&iter);
    return btmp;
  }

////    auto iter = writer.IterateOverRange<ser4cpp::UInt16, typename Serializer::Target>(QualifierCode::UINT16_START_STOP,
////                                                                                      Serializer::Inst(), range.start);
  DNP3Serializer_for_AnalogOutputStatus tmp = Inst_in_Group40Var1_static();
  RangeWriteIterator_for_UInt16_AnalogOutputStatus iter = IterateOverRange_for_UInt16_AnalogOutputStatus_in_HeaderWriter(writer,
      QualifierCode_UINT16_START_STOP,
      &tmp,
      (uint16_t) range.start );

////    return LoadWithRangeIterator<Spec, ser4cpp::UInt16>(map, iter, Serializer::svariation);
  boolean btmp = LoadWithRangeIterator_AnalogOutputStatusSpec_for_UInt16_in_StaticWriters(map, &iter, StaticAnalogOutputStatusVariation_Group40Var1);
  RangeWriteIterator_for_UInt16_AnalogOutputStatus_destr_RangeWriteIterator_for_UInt16_AnalogOutputStatus(&iter);
  return btmp;
}
//----------------------------------------------Group40Var1------------------------------------------
//----------------------------------------------Group40Var2------------------------------------------

////template<class Spec, class Serializer> bool WriteWithSerializer(StaticDataMap<Spec>& map, HeaderWriter& writer)
boolean WriteWithSerializer_AnalogOutputStatusSpec_for_Group40Var2_in_StaticWriters_static(StaticDataMap_for_AnalogOutputStatusSpec& map, HeaderWriter* writer)
{
////    const auto range = map.get_selected_range();
  Range  range = get_selected_range_in_StaticDataMap_for_AnalogOutputStatusSpec(&map);

////    if (range.IsOneByte())
  if (IsOneByte_in_Range(&range))
  {
//RangeWriteIterator_for_UInt8_AnalogOutputStatus IterateOverRange_for_UInt8_AnalogOutputStatus_in_HeaderWriter(HeaderWriter *pHeaderWriter,
//    QualifierCode_uint8_t qc,
//    DNP3Serializer_for_AnalogOutputStatus *serializer,
//    uint8_t start );
//DNP3Serializer_for_AnalogOutputStatus  Inst_in_Group40Var2_static(void);
////        auto iter = writer.IterateOverRange<ser4cpp::UInt8, typename Serializer::Target>(
////            QualifierCode::UINT8_START_STOP, Serializer::Inst(), static_cast<uint8_t>(range.start));
    DNP3Serializer_for_AnalogOutputStatus tmp = Inst_in_Group40Var2_static();
    RangeWriteIterator_for_UInt8_AnalogOutputStatus iter = IterateOverRange_for_UInt8_AnalogOutputStatus_in_HeaderWriter(writer,
        QualifierCode_UINT8_START_STOP,
        &tmp,
        (uint8_t) range.start );

//boolean LoadWithRangeIterator_AnalogOutputStatusSpec_for_UInt8_in_StaticWriters(StaticDataMap_for_AnalogOutputStatusSpec& map,
//    RangeWriteIterator_for_UInt8_AnalogOutputStatus *writer, StaticAnalogOutputStatusVariation_uint8_t variation)
////        return LoadWithRangeIterator<Spec, ser4cpp::UInt8>(map, iter, Serializer::svariation);
    boolean btmp = LoadWithRangeIterator_AnalogOutputStatusSpec_for_UInt8_in_StaticWriters(map, &iter, StaticAnalogOutputStatusVariation_Group40Var2);
    RangeWriteIterator_for_UInt8_AnalogOutputStatus_destr_RangeWriteIterator_for_UInt8_AnalogOutputStatus(&iter);
    return btmp;
  }

////    auto iter = writer.IterateOverRange<ser4cpp::UInt16, typename Serializer::Target>(QualifierCode::UINT16_START_STOP,
////                                                                                      Serializer::Inst(), range.start);
  DNP3Serializer_for_AnalogOutputStatus tmp = Inst_in_Group40Var2_static();
  RangeWriteIterator_for_UInt16_AnalogOutputStatus iter = IterateOverRange_for_UInt16_AnalogOutputStatus_in_HeaderWriter(writer,
      QualifierCode_UINT16_START_STOP,
      &tmp,
      (uint16_t) range.start );

////    return LoadWithRangeIterator<Spec, ser4cpp::UInt16>(map, iter, Serializer::svariation);
  boolean btmp = LoadWithRangeIterator_AnalogOutputStatusSpec_for_UInt16_in_StaticWriters(map, &iter, StaticAnalogOutputStatusVariation_Group40Var2);
  RangeWriteIterator_for_UInt16_AnalogOutputStatus_destr_RangeWriteIterator_for_UInt16_AnalogOutputStatus(&iter);
  return btmp;
}
//----------------------------------------------Group40Var2------------------------------------------
//----------------------------------------------Group40Var3------------------------------------------

////template<class Spec, class Serializer> bool WriteWithSerializer(StaticDataMap<Spec>& map, HeaderWriter& writer)
boolean WriteWithSerializer_AnalogOutputStatusSpec_for_Group40Var3_in_StaticWriters_static(StaticDataMap_for_AnalogOutputStatusSpec& map, HeaderWriter* writer)
{
////    const auto range = map.get_selected_range();
  Range  range = get_selected_range_in_StaticDataMap_for_AnalogOutputStatusSpec(&map);

////    if (range.IsOneByte())
  if (IsOneByte_in_Range(&range))
  {
//RangeWriteIterator_for_UInt8_AnalogOutputStatus IterateOverRange_for_UInt8_AnalogOutputStatus_in_HeaderWriter(HeaderWriter *pHeaderWriter,
//    QualifierCode_uint8_t qc,
//    DNP3Serializer_for_AnalogOutputStatus *serializer,
//    uint8_t start );
//DNP3Serializer_for_AnalogOutputStatus  Inst_in_Group40Var3_static(void);
////        auto iter = writer.IterateOverRange<ser4cpp::UInt8, typename Serializer::Target>(
////            QualifierCode::UINT8_START_STOP, Serializer::Inst(), static_cast<uint8_t>(range.start));
    DNP3Serializer_for_AnalogOutputStatus tmp = Inst_in_Group40Var3_static();
    RangeWriteIterator_for_UInt8_AnalogOutputStatus iter = IterateOverRange_for_UInt8_AnalogOutputStatus_in_HeaderWriter(writer,
        QualifierCode_UINT8_START_STOP,
        &tmp,
        (uint8_t) range.start );

//boolean LoadWithRangeIterator_AnalogOutputStatusSpec_for_UInt8_in_StaticWriters(StaticDataMap_for_AnalogOutputStatusSpec& map,
//    RangeWriteIterator_for_UInt8_AnalogOutputStatus *writer, StaticAnalogOutputStatusVariation_uint8_t variation)
////        return LoadWithRangeIterator<Spec, ser4cpp::UInt8>(map, iter, Serializer::svariation);
    boolean btmp = LoadWithRangeIterator_AnalogOutputStatusSpec_for_UInt8_in_StaticWriters(map, &iter, StaticAnalogOutputStatusVariation_Group40Var3);
    RangeWriteIterator_for_UInt8_AnalogOutputStatus_destr_RangeWriteIterator_for_UInt8_AnalogOutputStatus(&iter);
    return btmp;
  }

////    auto iter = writer.IterateOverRange<ser4cpp::UInt16, typename Serializer::Target>(QualifierCode::UINT16_START_STOP,
////                                                                                      Serializer::Inst(), range.start);
  DNP3Serializer_for_AnalogOutputStatus tmp = Inst_in_Group40Var3_static();
  RangeWriteIterator_for_UInt16_AnalogOutputStatus iter = IterateOverRange_for_UInt16_AnalogOutputStatus_in_HeaderWriter(writer,
      QualifierCode_UINT16_START_STOP,
      &tmp,
      (uint16_t) range.start );

////    return LoadWithRangeIterator<Spec, ser4cpp::UInt16>(map, iter, Serializer::svariation);
  boolean btmp = LoadWithRangeIterator_AnalogOutputStatusSpec_for_UInt16_in_StaticWriters(map, &iter, StaticAnalogOutputStatusVariation_Group40Var3);
  RangeWriteIterator_for_UInt16_AnalogOutputStatus_destr_RangeWriteIterator_for_UInt16_AnalogOutputStatus(&iter);
  return btmp;
}
//----------------------------------------------Group40Var3------------------------------------------

////static_write_func_t<AnalogOutputStatusSpec> StaticWriters::get(StaticAnalogOutputStatusVariation variation)
static_write_func_t_for_AnalogOutputStatusSpec get_for_AnalogOutputStatusSpec_in_StaticWriters_static(StaticAnalogOutputStatusVariation_uint8_t variation)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"get_for_AnalogOutputStatusSpec_in_StaticWriters_static1"<<'\n';
#endif
  switch (variation)
  {
  case (StaticAnalogOutputStatusVariation_Group40Var1):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*StaticAnalogOutputStatusVariation_Group40Var1"<<'\n';
    decrement_stack_info();
#endif
////        return &WriteWithSerializer<AnalogOutputStatusSpec, Group40Var1>;
    return WriteWithSerializer_AnalogOutputStatusSpec_for_Group40Var1_in_StaticWriters_static;

  case (StaticAnalogOutputStatusVariation_Group40Var2):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*StaticAnalogOutputStatusVariation_Group40Var2"<<'\n';
    decrement_stack_info();
#endif
////        return &WriteWithSerializer<AnalogOutputStatusSpec, Group40Var2>;
    return WriteWithSerializer_AnalogOutputStatusSpec_for_Group40Var2_in_StaticWriters_static;

  case (StaticAnalogOutputStatusVariation_Group40Var3):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*StaticAnalogOutputStatusVariation_Group40Var3"<<'\n';
    decrement_stack_info();
#endif
////        return &WriteWithSerializer<AnalogOutputStatusSpec, Group40Var3>;
    return WriteWithSerializer_AnalogOutputStatusSpec_for_Group40Var3_in_StaticWriters_static;

  default:
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*WriteWithSerializer_AnalogOutputStatusSpec_for_Group40Var1_in_StaticWriters_static"<<'\n';
    decrement_stack_info();
#endif
////        return &WriteWithSerializer<AnalogOutputStatusSpec, Group40Var1>;
    return WriteWithSerializer_AnalogOutputStatusSpec_for_Group40Var1_in_StaticWriters_static;
  }
}
