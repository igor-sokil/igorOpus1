#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include <QApplication>
#include "header.h"
#include "StaticWriters_for_FrozenCounter.h"

#include "Group1.h"
#include "Group10.h"
#include "Group20.h"
#include "Group21.h"
#include "Group3.h"
#include "Group30.h"
#include "Group40.h"
#include "Group50.h"
//#include "OctetStringSerializer.h"
#include "HeaderWriter_for_FrozenCounter.h"

//----------------------------------------LoadWithRangeIterator_FrozenCounterSpec_for_UInt8---------------------------------------------------------
////template<class Spec, class IndexType>
////bool LoadWithRangeIterator(StaticDataMap<Spec>& map,
////                           RangeWriteIterator<IndexType, typename Spec::meas_t>& writer,
////                           typename Spec::static_variation_t variation)
boolean LoadWithRangeIterator_FrozenCounterSpec_for_UInt8_in_StaticWriters(StaticDataMap_for_FrozenCounterSpec& map,
    RangeWriteIterator_for_UInt8_FrozenCounter *writer, StaticFrozenCounterVariation_uint8_t variation)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{LoadWithRangeIterator_FrozenCounterSpec_for_UInt8_in_StaticWriters1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*StaticFrozenCounterVariation_uint8_t variation= "<<(uint16_t)variation<<'\n';
#endif
////    auto next_index = map.get_selected_range().start;
  uint16_t  next_index = get_selected_range_in_StaticDataMap_for_FrozenCounterSpec(&map).start;

  for (const auto& elem : map)
  {
    if (elem.second.variation != variation)
    {
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}LoadWithRangeIterator_FrozenCounterSpec_for_UInt8_in_StaticWriters1_"<<'\n';
  decrement_stack_info();
#endif
      // the variation has changed
      return true;
    }

    if (elem.first != next_index)
    {
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}LoadWithRangeIterator_FrozenCounterSpec_for_UInt8_in_StaticWriters2_"<<'\n';
  decrement_stack_info();
#endif
      // we've loaded all we can with a contiguous range
// мы загрузили все, что могли, в непрерывном диапазоне
      return true;
    }

//boolean Write_in_RangeWriteIterator_for_UInt8_FrozenCounter(RangeWriteIterator_for_UInt8_FrozenCounter *pRangeWriteIterator_for_UInt8_FrozenCounter,
//    FrozenCounter* value);
////        if (!writer.Write(elem.second.value))
    if (!Write_in_RangeWriteIterator_for_UInt8_FrozenCounter(writer, &elem.second.value))
    {
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}LoadWithRangeIterator_FrozenCounterSpec_for_UInt8_in_StaticWriters3_"<<'\n';
  decrement_stack_info();
#endif
      return false;
    }

    ++next_index;
  }

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}LoadWithRangeIterator_FrozenCounterSpec_for_UInt8_in_StaticWriters4_"<<'\n';
  decrement_stack_info();
#endif
  return true;
}
//----------------------------------------LoadWithRangeIterator_FrozenCounterSpec_for_UInt8---------------------------------------------------------
//----------------------------------------LoadWithRangeIterator_FrozenCounterSpec_for_UInt16---------------------------------------------------------
////template<class Spec, class IndexType>
////bool LoadWithRangeIterator(StaticDataMap<Spec>& map,
////                           RangeWriteIterator<IndexType, typename Spec::meas_t>& writer,
////                           typename Spec::static_variation_t variation)
boolean LoadWithRangeIterator_FrozenCounterSpec_for_UInt16_in_StaticWriters(StaticDataMap_for_FrozenCounterSpec& map,
    RangeWriteIterator_for_UInt16_FrozenCounter *writer, StaticFrozenCounterVariation_uint8_t variation)
{
////    auto next_index = map.get_selected_range().start;
  uint16_t  next_index = get_selected_range_in_StaticDataMap_for_FrozenCounterSpec(&map).start;

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

//boolean Write_in_RangeWriteIterator_for_UInt16_FrozenCounter(RangeWriteIterator_for_UInt16_FrozenCounter *pRangeWriteIterator_for_UInt16_FrozenCounter,
//    FrozenCounter* value);
////        if (!writer.Write(elem.second.value))
    if (!Write_in_RangeWriteIterator_for_UInt16_FrozenCounter(writer, &elem.second.value))//.tTypedMeasurement_for_Double64.value))
    {
      return false;
    }

    ++next_index;
  }

  return true;
}
//----------------------------------------LoadWithRangeIterator_FrozenCounterSpec_for_UInt16---------------------------------------------------------

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
//----------------------------------------------Group21Var1------------------------------------------

////template<class Spec, class Serializer> bool WriteWithSerializer(StaticDataMap<Spec>& map, HeaderWriter& writer)
boolean WriteWithSerializer_FrozenCounterSpec_for_Group21Var1_in_StaticWriters_static(StaticDataMap_for_FrozenCounterSpec& map, HeaderWriter* writer)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{WriteWithSerializer_FrozenCounterSpec_for_Group21Var1_in_StaticWriters_static1"<<'\n';
#endif

////    const auto range = map.get_selected_range();
  Range  range = get_selected_range_in_StaticDataMap_for_FrozenCounterSpec(&map);

////    if (range.IsOneByte())
  if (IsOneByte_in_Range(&range))
  {
//RangeWriteIterator_for_UInt8_FrozenCounter IterateOverRange_for_UInt8_FrozenCounter_in_HeaderWriter(HeaderWriter *pHeaderWriter,
//    QualifierCode_uint8_t qc,
//    DNP3Serializer_for_FrozenCounter *serializer,
//    uint8_t start );
//DNP3Serializer_for_FrozenCounter  Inst_in_Group21Var1_static(void);
////        auto iter = writer.IterateOverRange<ser4cpp::UInt8, typename Serializer::Target>(
////            QualifierCode::UINT8_START_STOP, Serializer::Inst(), static_cast<uint8_t>(range.start));
    DNP3Serializer_for_FrozenCounter tmp = Inst_in_Group21Var1_static();
    RangeWriteIterator_for_UInt8_FrozenCounter iter = IterateOverRange_for_UInt8_FrozenCounter_in_HeaderWriter(writer,
        QualifierCode_UINT8_START_STOP,
        &tmp,
        (uint8_t) range.start );

//boolean LoadWithRangeIterator_FrozenCounterSpec_for_UInt8_in_StaticWriters(StaticDataMap_for_FrozenCounterSpec& map,
//    RangeWriteIterator_for_UInt8_FrozenCounter *writer, StaticFrozenCounterVariation_uint8_t variation)
////        return LoadWithRangeIterator<Spec, ser4cpp::UInt8>(map, iter, Serializer::svariation);
    boolean btmp = LoadWithRangeIterator_FrozenCounterSpec_for_UInt8_in_StaticWriters(map, &iter, StaticFrozenCounterVariation_Group21Var1);
    RangeWriteIterator_for_UInt8_FrozenCounter_destr_RangeWriteIterator_for_UInt8_FrozenCounter(&iter);

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}WriteWithSerializer_FrozenCounterSpec_for_Group21Var1_in_StaticWriters_static1_"<<'\n';
  decrement_stack_info();
#endif
    return btmp;
  }

////    auto iter = writer.IterateOverRange<ser4cpp::UInt16, typename Serializer::Target>(QualifierCode::UINT16_START_STOP,
////                                                                                      Serializer::Inst(), range.start);
  DNP3Serializer_for_FrozenCounter tmp = Inst_in_Group21Var1_static();
  RangeWriteIterator_for_UInt16_FrozenCounter iter = IterateOverRange_for_UInt16_FrozenCounter_in_HeaderWriter(writer,
      QualifierCode_UINT16_START_STOP,
      &tmp,
      (uint16_t) range.start );

////    return LoadWithRangeIterator<Spec, ser4cpp::UInt16>(map, iter, Serializer::svariation);
  boolean btmp = LoadWithRangeIterator_FrozenCounterSpec_for_UInt16_in_StaticWriters(map, &iter, StaticFrozenCounterVariation_Group21Var1);
  RangeWriteIterator_for_UInt16_FrozenCounter_destr_RangeWriteIterator_for_UInt16_FrozenCounter(&iter);

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}WriteWithSerializer_FrozenCounterSpec_for_Group21Var1_in_StaticWriters_static2_"<<'\n';
  decrement_stack_info();
#endif
  return btmp;
}
//----------------------------------------------Group21Var1------------------------------------------
//----------------------------------------------Group21Var2------------------------------------------
////template<class Spec, class Serializer> bool WriteWithSerializer(StaticDataMap<Spec>& map, HeaderWriter& writer)
boolean WriteWithSerializer_FrozenCounterSpec_for_Group21Var2_in_StaticWriters_static(StaticDataMap_for_FrozenCounterSpec& map, HeaderWriter* writer)
{
////    const auto range = map.get_selected_range();
  Range  range = get_selected_range_in_StaticDataMap_for_FrozenCounterSpec(&map);

////    if (range.IsOneByte())
  if (IsOneByte_in_Range(&range))
  {
//RangeWriteIterator_for_UInt8_FrozenCounter IterateOverRange_for_UInt8_FrozenCounter_in_HeaderWriter(HeaderWriter *pHeaderWriter,
//    QualifierCode_uint8_t qc,
//    DNP3Serializer_for_FrozenCounter *serializer,
//    uint8_t start );
//DNP3Serializer_for_FrozenCounter  Inst_in_Group21Var2_static(void);
////        auto iter = writer.IterateOverRange<ser4cpp::UInt8, typename Serializer::Target>(
////            QualifierCode::UINT8_START_STOP, Serializer::Inst(), static_cast<uint8_t>(range.start));
    DNP3Serializer_for_FrozenCounter tmp = Inst_in_Group21Var2_static();
    RangeWriteIterator_for_UInt8_FrozenCounter iter = IterateOverRange_for_UInt8_FrozenCounter_in_HeaderWriter(writer,
        QualifierCode_UINT8_START_STOP,
        &tmp,
        (uint8_t) range.start );

//boolean LoadWithRangeIterator_FrozenCounterSpec_for_UInt8_in_StaticWriters(StaticDataMap_for_FrozenCounterSpec& map,
//    RangeWriteIterator_for_UInt8_FrozenCounter *writer, StaticFrozenCounterVariation_uint8_t variation)
////        return LoadWithRangeIterator<Spec, ser4cpp::UInt8>(map, iter, Serializer::svariation);
    boolean btmp = LoadWithRangeIterator_FrozenCounterSpec_for_UInt8_in_StaticWriters(map, &iter, StaticFrozenCounterVariation_Group21Var2);
    RangeWriteIterator_for_UInt8_FrozenCounter_destr_RangeWriteIterator_for_UInt8_FrozenCounter(&iter);
    return btmp;
  }

////    auto iter = writer.IterateOverRange<ser4cpp::UInt16, typename Serializer::Target>(QualifierCode::UINT16_START_STOP,
////                                                                                      Serializer::Inst(), range.start);
  DNP3Serializer_for_FrozenCounter tmp = Inst_in_Group21Var2_static();
  RangeWriteIterator_for_UInt16_FrozenCounter iter = IterateOverRange_for_UInt16_FrozenCounter_in_HeaderWriter(writer,
      QualifierCode_UINT16_START_STOP,
      &tmp,
      (uint16_t) range.start );

////    return LoadWithRangeIterator<Spec, ser4cpp::UInt16>(map, iter, Serializer::svariation);
  boolean btmp = LoadWithRangeIterator_FrozenCounterSpec_for_UInt16_in_StaticWriters(map, &iter, StaticFrozenCounterVariation_Group21Var2);
  RangeWriteIterator_for_UInt16_FrozenCounter_destr_RangeWriteIterator_for_UInt16_FrozenCounter(&iter);
  return btmp;
}
//----------------------------------------------Group21Var2------------------------------------------
//----------------------------------------------Group21Var5------------------------------------------
////template<class Spec, class Serializer> bool WriteWithSerializer(StaticDataMap<Spec>& map, HeaderWriter& writer)
boolean WriteWithSerializer_FrozenCounterSpec_for_Group21Var5_in_StaticWriters_static(StaticDataMap_for_FrozenCounterSpec& map, HeaderWriter* writer)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{WriteWithSerializer_FrozenCounterSpec_for_Group21Var5_in_StaticWriters_static1"<<'\n';
#endif
////    const auto range = map.get_selected_range();
  Range  range = get_selected_range_in_StaticDataMap_for_FrozenCounterSpec(&map);

////    if (range.IsOneByte())
  if (IsOneByte_in_Range(&range))
  {
//RangeWriteIterator_for_UInt8_FrozenCounter IterateOverRange_for_UInt8_FrozenCounter_in_HeaderWriter(HeaderWriter *pHeaderWriter,
//    QualifierCode_uint8_t qc,
//    DNP3Serializer_for_FrozenCounter *serializer,
//    uint8_t start );
//DNP3Serializer_for_FrozenCounter  Inst_in_Group21Var5_static(void);
////        auto iter = writer.IterateOverRange<ser4cpp::UInt8, typename Serializer::Target>(
////            QualifierCode::UINT8_START_STOP, Serializer::Inst(), static_cast<uint8_t>(range.start));
    DNP3Serializer_for_FrozenCounter tmp = Inst_in_Group21Var5_static();
    RangeWriteIterator_for_UInt8_FrozenCounter iter = IterateOverRange_for_UInt8_FrozenCounter_in_HeaderWriter(writer,
        QualifierCode_UINT8_START_STOP,
        &tmp,
        (uint8_t) range.start );

//boolean LoadWithRangeIterator_FrozenCounterSpec_for_UInt8_in_StaticWriters(StaticDataMap_for_FrozenCounterSpec& map,
//    RangeWriteIterator_for_UInt8_FrozenCounter *writer, StaticFrozenCounterVariation_uint8_t variation)
////        return LoadWithRangeIterator<Spec, ser4cpp::UInt8>(map, iter, Serializer::svariation);
    boolean btmp = LoadWithRangeIterator_FrozenCounterSpec_for_UInt8_in_StaticWriters(map, &iter, StaticFrozenCounterVariation_Group21Var5);
    RangeWriteIterator_for_UInt8_FrozenCounter_destr_RangeWriteIterator_for_UInt8_FrozenCounter(&iter);

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}WriteWithSerializer_FrozenCounterSpec_for_Group21Var5_in_StaticWriters_static1_"<<'\n';
  decrement_stack_info();
#endif
    return btmp;
  }

////    auto iter = writer.IterateOverRange<ser4cpp::UInt16, typename Serializer::Target>(QualifierCode::UINT16_START_STOP,
////                                                                                      Serializer::Inst(), range.start);
  DNP3Serializer_for_FrozenCounter tmp = Inst_in_Group21Var5_static();
  RangeWriteIterator_for_UInt16_FrozenCounter iter = IterateOverRange_for_UInt16_FrozenCounter_in_HeaderWriter(writer,
      QualifierCode_UINT16_START_STOP,
      &tmp,
      (uint16_t) range.start );

////    return LoadWithRangeIterator<Spec, ser4cpp::UInt16>(map, iter, Serializer::svariation);
  boolean btmp = LoadWithRangeIterator_FrozenCounterSpec_for_UInt16_in_StaticWriters(map, &iter, StaticFrozenCounterVariation_Group21Var5);
  RangeWriteIterator_for_UInt16_FrozenCounter_destr_RangeWriteIterator_for_UInt16_FrozenCounter(&iter);

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}WriteWithSerializer_FrozenCounterSpec_for_Group21Var5_in_StaticWriters_static2_"<<'\n';
  decrement_stack_info();
#endif
  return btmp;
}
//----------------------------------------------Group21Var5------------------------------------------
//----------------------------------------------Group21Var6------------------------------------------
////template<class Spec, class Serializer> bool WriteWithSerializer(StaticDataMap<Spec>& map, HeaderWriter& writer)
boolean WriteWithSerializer_FrozenCounterSpec_for_Group21Var6_in_StaticWriters_static(StaticDataMap_for_FrozenCounterSpec& map, HeaderWriter* writer)
{
////    const auto range = map.get_selected_range();
  Range  range = get_selected_range_in_StaticDataMap_for_FrozenCounterSpec(&map);

////    if (range.IsOneByte())
  if (IsOneByte_in_Range(&range))
  {
//RangeWriteIterator_for_UInt8_FrozenCounter IterateOverRange_for_UInt8_FrozenCounter_in_HeaderWriter(HeaderWriter *pHeaderWriter,
//    QualifierCode_uint8_t qc,
//    DNP3Serializer_for_FrozenCounter *serializer,
//    uint8_t start );
//DNP3Serializer_for_FrozenCounter  Inst_in_Group21Var6_static(void);
////        auto iter = writer.IterateOverRange<ser4cpp::UInt8, typename Serializer::Target>(
////            QualifierCode::UINT8_START_STOP, Serializer::Inst(), static_cast<uint8_t>(range.start));
    DNP3Serializer_for_FrozenCounter tmp = Inst_in_Group21Var6_static();
    RangeWriteIterator_for_UInt8_FrozenCounter iter = IterateOverRange_for_UInt8_FrozenCounter_in_HeaderWriter(writer,
        QualifierCode_UINT8_START_STOP,
        &tmp,
        (uint8_t) range.start );

//boolean LoadWithRangeIterator_FrozenCounterSpec_for_UInt8_in_StaticWriters(StaticDataMap_for_FrozenCounterSpec& map,
//    RangeWriteIterator_for_UInt8_FrozenCounter *writer, StaticFrozenCounterVariation_uint8_t variation)
////        return LoadWithRangeIterator<Spec, ser4cpp::UInt8>(map, iter, Serializer::svariation);
    boolean btmp = LoadWithRangeIterator_FrozenCounterSpec_for_UInt8_in_StaticWriters(map, &iter, StaticFrozenCounterVariation_Group21Var6);
    RangeWriteIterator_for_UInt8_FrozenCounter_destr_RangeWriteIterator_for_UInt8_FrozenCounter(&iter);
    return btmp;
  }

////    auto iter = writer.IterateOverRange<ser4cpp::UInt16, typename Serializer::Target>(QualifierCode::UINT16_START_STOP,
////                                                                                      Serializer::Inst(), range.start);
  DNP3Serializer_for_FrozenCounter tmp = Inst_in_Group21Var6_static();
  RangeWriteIterator_for_UInt16_FrozenCounter iter = IterateOverRange_for_UInt16_FrozenCounter_in_HeaderWriter(writer,
      QualifierCode_UINT16_START_STOP,
      &tmp,
      (uint16_t) range.start );

////    return LoadWithRangeIterator<Spec, ser4cpp::UInt16>(map, iter, Serializer::svariation);
  boolean btmp = LoadWithRangeIterator_FrozenCounterSpec_for_UInt16_in_StaticWriters(map, &iter, StaticFrozenCounterVariation_Group21Var6);
  RangeWriteIterator_for_UInt16_FrozenCounter_destr_RangeWriteIterator_for_UInt16_FrozenCounter(&iter);
  return btmp;
}
//----------------------------------------------Group21Var6------------------------------------------
//----------------------------------------------Group21Var9------------------------------------------
////template<class Spec, class Serializer> bool WriteWithSerializer(StaticDataMap<Spec>& map, HeaderWriter& writer)
boolean WriteWithSerializer_FrozenCounterSpec_for_Group21Var9_in_StaticWriters_static(StaticDataMap_for_FrozenCounterSpec& map, HeaderWriter* writer)
{
////    const auto range = map.get_selected_range();
  Range  range = get_selected_range_in_StaticDataMap_for_FrozenCounterSpec(&map);

////    if (range.IsOneByte())
  if (IsOneByte_in_Range(&range))
  {
//RangeWriteIterator_for_UInt8_FrozenCounter IterateOverRange_for_UInt8_FrozenCounter_in_HeaderWriter(HeaderWriter *pHeaderWriter,
//    QualifierCode_uint8_t qc,
//    DNP3Serializer_for_FrozenCounter *serializer,
//    uint8_t start );
//DNP3Serializer_for_FrozenCounter  Inst_in_Group21Var9_static(void);
////        auto iter = writer.IterateOverRange<ser4cpp::UInt8, typename Serializer::Target>(
////            QualifierCode::UINT8_START_STOP, Serializer::Inst(), static_cast<uint8_t>(range.start));
    DNP3Serializer_for_FrozenCounter tmp = Inst_in_Group21Var9_static();
    RangeWriteIterator_for_UInt8_FrozenCounter iter = IterateOverRange_for_UInt8_FrozenCounter_in_HeaderWriter(writer,
        QualifierCode_UINT8_START_STOP,
        &tmp,
        (uint8_t) range.start );

//boolean LoadWithRangeIterator_FrozenCounterSpec_for_UInt8_in_StaticWriters(StaticDataMap_for_FrozenCounterSpec& map,
//    RangeWriteIterator_for_UInt8_FrozenCounter *writer, StaticFrozenCounterVariation_uint8_t variation)
////        return LoadWithRangeIterator<Spec, ser4cpp::UInt8>(map, iter, Serializer::svariation);
    boolean btmp = LoadWithRangeIterator_FrozenCounterSpec_for_UInt8_in_StaticWriters(map, &iter, StaticFrozenCounterVariation_Group21Var9);
    RangeWriteIterator_for_UInt8_FrozenCounter_destr_RangeWriteIterator_for_UInt8_FrozenCounter(&iter);
    return btmp;
  }

////    auto iter = writer.IterateOverRange<ser4cpp::UInt16, typename Serializer::Target>(QualifierCode::UINT16_START_STOP,
////                                                                                      Serializer::Inst(), range.start);
  DNP3Serializer_for_FrozenCounter tmp = Inst_in_Group21Var9_static();
  RangeWriteIterator_for_UInt16_FrozenCounter iter = IterateOverRange_for_UInt16_FrozenCounter_in_HeaderWriter(writer,
      QualifierCode_UINT16_START_STOP,
      &tmp,
      (uint16_t) range.start );

////    return LoadWithRangeIterator<Spec, ser4cpp::UInt16>(map, iter, Serializer::svariation);
  boolean btmp = LoadWithRangeIterator_FrozenCounterSpec_for_UInt16_in_StaticWriters(map, &iter, StaticFrozenCounterVariation_Group21Var9);
  RangeWriteIterator_for_UInt16_FrozenCounter_destr_RangeWriteIterator_for_UInt16_FrozenCounter(&iter);
  return btmp;
}
//----------------------------------------------Group21Var9------------------------------------------
//----------------------------------------------Group21Var10------------------------------------------
////template<class Spec, class Serializer> bool WriteWithSerializer(StaticDataMap<Spec>& map, HeaderWriter& writer)
boolean WriteWithSerializer_FrozenCounterSpec_for_Group21Var10_in_StaticWriters_static(StaticDataMap_for_FrozenCounterSpec& map, HeaderWriter* writer)
{
////    const auto range = map.get_selected_range();
  Range  range = get_selected_range_in_StaticDataMap_for_FrozenCounterSpec(&map);

////    if (range.IsOneByte())
  if (IsOneByte_in_Range(&range))
  {
//RangeWriteIterator_for_UInt8_FrozenCounter IterateOverRange_for_UInt8_FrozenCounter_in_HeaderWriter(HeaderWriter *pHeaderWriter,
//    QualifierCode_uint8_t qc,
//    DNP3Serializer_for_FrozenCounter *serializer,
//    uint8_t start );
//DNP3Serializer_for_FrozenCounter  Inst_in_Group21Var10_static(void);
////        auto iter = writer.IterateOverRange<ser4cpp::UInt8, typename Serializer::Target>(
////            QualifierCode::UINT8_START_STOP, Serializer::Inst(), static_cast<uint8_t>(range.start));
    DNP3Serializer_for_FrozenCounter tmp = Inst_in_Group21Var10_static();
    RangeWriteIterator_for_UInt8_FrozenCounter iter = IterateOverRange_for_UInt8_FrozenCounter_in_HeaderWriter(writer,
        QualifierCode_UINT8_START_STOP,
        &tmp,
        (uint8_t) range.start );

//boolean LoadWithRangeIterator_FrozenCounterSpec_for_UInt8_in_StaticWriters(StaticDataMap_for_FrozenCounterSpec& map,
//    RangeWriteIterator_for_UInt8_FrozenCounter *writer, StaticFrozenCounterVariation_uint8_t variation)
////        return LoadWithRangeIterator<Spec, ser4cpp::UInt8>(map, iter, Serializer::svariation);
    boolean btmp = LoadWithRangeIterator_FrozenCounterSpec_for_UInt8_in_StaticWriters(map, &iter, StaticFrozenCounterVariation_Group21Var10);
    RangeWriteIterator_for_UInt8_FrozenCounter_destr_RangeWriteIterator_for_UInt8_FrozenCounter(&iter);
    return btmp;
  }

////    auto iter = writer.IterateOverRange<ser4cpp::UInt16, typename Serializer::Target>(QualifierCode::UINT16_START_STOP,
////                                                                                      Serializer::Inst(), range.start);
  DNP3Serializer_for_FrozenCounter tmp = Inst_in_Group21Var10_static();
  RangeWriteIterator_for_UInt16_FrozenCounter iter = IterateOverRange_for_UInt16_FrozenCounter_in_HeaderWriter(writer,
      QualifierCode_UINT16_START_STOP,
      &tmp,
      (uint16_t) range.start );

////    return LoadWithRangeIterator<Spec, ser4cpp::UInt16>(map, iter, Serializer::svariation);
  boolean btmp = LoadWithRangeIterator_FrozenCounterSpec_for_UInt16_in_StaticWriters(map, &iter, StaticFrozenCounterVariation_Group21Var10);
  RangeWriteIterator_for_UInt16_FrozenCounter_destr_RangeWriteIterator_for_UInt16_FrozenCounter(&iter);
  return btmp;
}
//----------------------------------------------Group21Var10------------------------------------------

////static_write_func_t<FrozenCounterSpec> StaticWriters::get(StaticFrozenCounterVariation variation)
static_write_func_t_for_FrozenCounterSpec get_for_FrozenCounterSpec_in_StaticWriters_static(StaticFrozenCounterVariation_uint8_t variation)
{
#ifdef  LOG_INFO
  std::cout<<""<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"get_for_FrozenCounterSpec_in_StaticWriters_static1"<<'\n';
#endif
  switch (variation)
  {
  case (StaticFrozenCounterVariation_Group21Var1):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*StaticFrozenCounterVariation_Group21Var1"<<'\n';
    decrement_stack_info();
#endif
////        return &WriteWithSerializer<FrozenCounterSpec, Group21Var1>;
    return WriteWithSerializer_FrozenCounterSpec_for_Group21Var1_in_StaticWriters_static;

  case (StaticFrozenCounterVariation_Group21Var2):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*StaticFrozenCounterVariation_Group21Var2"<<'\n';
    decrement_stack_info();
#endif
////        return &WriteWithSerializer<FrozenCounterSpec, Group21Var2>;
    return WriteWithSerializer_FrozenCounterSpec_for_Group21Var2_in_StaticWriters_static;

  case (StaticFrozenCounterVariation_Group21Var5):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*StaticFrozenCounterVariation_Group21Var5"<<'\n';
    decrement_stack_info();
#endif
////        return &WriteWithSerializer<FrozenCounterSpec, Group21Var5>;
    return WriteWithSerializer_FrozenCounterSpec_for_Group21Var5_in_StaticWriters_static;

  case (StaticFrozenCounterVariation_Group21Var6):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*StaticFrozenCounterVariation_Group21Var6"<<'\n';
    decrement_stack_info();
#endif
////        return &WriteWithSerializer<FrozenCounterSpec, Group21Var6>;
    return WriteWithSerializer_FrozenCounterSpec_for_Group21Var6_in_StaticWriters_static;

  case (StaticFrozenCounterVariation_Group21Var9):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*StaticFrozenCounterVariation_Group21Var9"<<'\n';
    decrement_stack_info();
#endif
////        return &WriteWithSerializer<FrozenCounterSpec, Group21Var9>;
    return WriteWithSerializer_FrozenCounterSpec_for_Group21Var9_in_StaticWriters_static;

  case (StaticFrozenCounterVariation_Group21Var10):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*StaticFrozenCounterVariation_Group21Var10"<<'\n';
    decrement_stack_info();
#endif
////        return &WriteWithSerializer<FrozenCounterSpec, Group21Var10>;
    return WriteWithSerializer_FrozenCounterSpec_for_Group21Var10_in_StaticWriters_static;

  default:
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*WriteWithSerializer_FrozenCounterSpec_for_Group21Var1_in_StaticWriters_static"<<'\n';
    decrement_stack_info();
#endif
////        return &WriteWithSerializer<FrozenCounterSpec, Group21Var1>;
    return WriteWithSerializer_FrozenCounterSpec_for_Group21Var1_in_StaticWriters_static;
  }
}
