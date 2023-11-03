#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include <QApplication>
#include "header.h"
#include "StaticWriters_for_Counter.h"

#include "Group1.h"
#include "Group10.h"
#include "Group20.h"
#include "Group21.h"
#include "Group3.h"
#include "Group30.h"
#include "Group40.h"
#include "Group50.h"
//#include "OctetStringSerializer.h"
#include "HeaderWriter_for_Counter.h"

//----------------------------------------LoadWithRangeIterator_CounterSpec_for_UInt8---------------------------------------------------------
////template<class Spec, class IndexType>
////bool LoadWithRangeIterator(StaticDataMap<Spec>& map,
////                           RangeWriteIterator<IndexType, typename Spec::meas_t>& writer,
////                           typename Spec::static_variation_t variation)
boolean LoadWithRangeIterator_CounterSpec_for_UInt8_in_StaticWriters(StaticDataMap_for_CounterSpec& map,
    RangeWriteIterator_for_UInt8_Counter *writer, StaticCounterVariation_uint8_t variation)
{
////    auto next_index = map.get_selected_range().start;
  uint16_t  next_index = get_selected_range_in_StaticDataMap_for_CounterSpec(&map).start;

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

//boolean Write_in_RangeWriteIterator_for_UInt8_Counter(RangeWriteIterator_for_UInt8_Counter *pRangeWriteIterator_for_UInt8_Counter,
//    Counter* value);
////        if (!writer.Write(elem.second.value))
    if (!Write_in_RangeWriteIterator_for_UInt8_Counter(writer, &elem.second.value))//.tTypedMeasurement_for_Double64.value))
    {
      return false;
    }

    ++next_index;
  }

  return true;
}
//----------------------------------------LoadWithRangeIterator_CounterSpec_for_UInt8---------------------------------------------------------
//----------------------------------------LoadWithRangeIterator_CounterSpec_for_UInt16---------------------------------------------------------
////template<class Spec, class IndexType>
////bool LoadWithRangeIterator(StaticDataMap<Spec>& map,
////                           RangeWriteIterator<IndexType, typename Spec::meas_t>& writer,
////                           typename Spec::static_variation_t variation)
boolean LoadWithRangeIterator_CounterSpec_for_UInt16_in_StaticWriters(StaticDataMap_for_CounterSpec& map,
    RangeWriteIterator_for_UInt16_Counter *writer, StaticCounterVariation_uint8_t variation)
{
////    auto next_index = map.get_selected_range().start;
  uint16_t  next_index = get_selected_range_in_StaticDataMap_for_CounterSpec(&map).start;

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

//boolean Write_in_RangeWriteIterator_for_UInt16_Counter(RangeWriteIterator_for_UInt16_Counter *pRangeWriteIterator_for_UInt16_Counter,
//    Counter* value);
////        if (!writer.Write(elem.second.value))
    if (!Write_in_RangeWriteIterator_for_UInt16_Counter(writer, &elem.second.value))//.tTypedMeasurement_for_Double64.value))
    {
      return false;
    }

    ++next_index;
  }

  return true;
}
//----------------------------------------LoadWithRangeIterator_CounterSpec_for_UInt16---------------------------------------------------------

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
//----------------------------------------------Group20Var1------------------------------------------

////template<class Spec, class Serializer> bool WriteWithSerializer(StaticDataMap<Spec>& map, HeaderWriter& writer)
boolean WriteWithSerializer_CounterSpec_for_Group20Var1_in_StaticWriters_static(StaticDataMap_for_CounterSpec& map, HeaderWriter* writer)
{
////    const auto range = map.get_selected_range();
  Range  range = get_selected_range_in_StaticDataMap_for_CounterSpec(&map);

////    if (range.IsOneByte())
  if (IsOneByte_in_Range(&range))
  {
//RangeWriteIterator_for_UInt8_Counter IterateOverRange_for_UInt8_Counter_in_HeaderWriter(HeaderWriter *pHeaderWriter,
//    QualifierCode_uint8_t qc,
//    DNP3Serializer_for_Counter *serializer,
//    uint8_t start );
//DNP3Serializer_for_Counter  Inst_in_Group20Var1_static(void);
////        auto iter = writer.IterateOverRange<ser4cpp::UInt8, typename Serializer::Target>(
////            QualifierCode::UINT8_START_STOP, Serializer::Inst(), static_cast<uint8_t>(range.start));
    DNP3Serializer_for_Counter tmp = Inst_in_Group20Var1_static();
    RangeWriteIterator_for_UInt8_Counter iter = IterateOverRange_for_UInt8_Counter_in_HeaderWriter(writer,
        QualifierCode_UINT8_START_STOP,
        &tmp,
        (uint8_t) range.start );

//boolean LoadWithRangeIterator_CounterSpec_for_UInt8_in_StaticWriters(StaticDataMap_for_CounterSpec& map,
//    RangeWriteIterator_for_UInt8_Counter *writer, StaticCounterVariation_uint8_t variation)
////        return LoadWithRangeIterator<Spec, ser4cpp::UInt8>(map, iter, Serializer::svariation);
    boolean btmp = LoadWithRangeIterator_CounterSpec_for_UInt8_in_StaticWriters(map, &iter, StaticCounterVariation_Group20Var1);
    RangeWriteIterator_for_UInt8_Counter_destr_RangeWriteIterator_for_UInt8_Counter(&iter);
    return btmp;
  }

////    auto iter = writer.IterateOverRange<ser4cpp::UInt16, typename Serializer::Target>(QualifierCode::UINT16_START_STOP,
////                                                                                      Serializer::Inst(), range.start);
  DNP3Serializer_for_Counter tmp = Inst_in_Group20Var1_static();
  RangeWriteIterator_for_UInt16_Counter iter = IterateOverRange_for_UInt16_Counter_in_HeaderWriter(writer,
      QualifierCode_UINT16_START_STOP,
      &tmp,
      (uint16_t) range.start );

////    return LoadWithRangeIterator<Spec, ser4cpp::UInt16>(map, iter, Serializer::svariation);
  boolean btmp = LoadWithRangeIterator_CounterSpec_for_UInt16_in_StaticWriters(map, &iter, StaticCounterVariation_Group20Var1);
  RangeWriteIterator_for_UInt16_Counter_destr_RangeWriteIterator_for_UInt16_Counter(&iter);
  return btmp;
}
//----------------------------------------------Group20Var1------------------------------------------
//----------------------------------------------Group20Var2------------------------------------------
////template<class Spec, class Serializer> bool WriteWithSerializer(StaticDataMap<Spec>& map, HeaderWriter& writer)
boolean WriteWithSerializer_CounterSpec_for_Group20Var2_in_StaticWriters_static(StaticDataMap_for_CounterSpec& map, HeaderWriter* writer)
{
////    const auto range = map.get_selected_range();
  Range  range = get_selected_range_in_StaticDataMap_for_CounterSpec(&map);

////    if (range.IsOneByte())
  if (IsOneByte_in_Range(&range))
  {
//RangeWriteIterator_for_UInt8_Counter IterateOverRange_for_UInt8_Counter_in_HeaderWriter(HeaderWriter *pHeaderWriter,
//    QualifierCode_uint8_t qc,
//    DNP3Serializer_for_Counter *serializer,
//    uint8_t start );
//DNP3Serializer_for_Counter  Inst_in_Group20Var2_static(void);
////        auto iter = writer.IterateOverRange<ser4cpp::UInt8, typename Serializer::Target>(
////            QualifierCode::UINT8_START_STOP, Serializer::Inst(), static_cast<uint8_t>(range.start));
    DNP3Serializer_for_Counter tmp = Inst_in_Group20Var2_static();
    RangeWriteIterator_for_UInt8_Counter iter = IterateOverRange_for_UInt8_Counter_in_HeaderWriter(writer,
        QualifierCode_UINT8_START_STOP,
        &tmp,
        (uint8_t) range.start );

//boolean LoadWithRangeIterator_CounterSpec_for_UInt8_in_StaticWriters(StaticDataMap_for_CounterSpec& map,
//    RangeWriteIterator_for_UInt8_Counter *writer, StaticCounterVariation_uint8_t variation)
////        return LoadWithRangeIterator<Spec, ser4cpp::UInt8>(map, iter, Serializer::svariation);
    boolean btmp = LoadWithRangeIterator_CounterSpec_for_UInt8_in_StaticWriters(map, &iter, StaticCounterVariation_Group20Var2);
    RangeWriteIterator_for_UInt8_Counter_destr_RangeWriteIterator_for_UInt8_Counter(&iter);
    return btmp;
  }

////    auto iter = writer.IterateOverRange<ser4cpp::UInt16, typename Serializer::Target>(QualifierCode::UINT16_START_STOP,
////                                                                                      Serializer::Inst(), range.start);
  DNP3Serializer_for_Counter tmp = Inst_in_Group20Var2_static();
  RangeWriteIterator_for_UInt16_Counter iter = IterateOverRange_for_UInt16_Counter_in_HeaderWriter(writer,
      QualifierCode_UINT16_START_STOP,
      &tmp,
      (uint16_t) range.start );

////    return LoadWithRangeIterator<Spec, ser4cpp::UInt16>(map, iter, Serializer::svariation);
  boolean btmp = LoadWithRangeIterator_CounterSpec_for_UInt16_in_StaticWriters(map, &iter, StaticCounterVariation_Group20Var2);
  RangeWriteIterator_for_UInt16_Counter_destr_RangeWriteIterator_for_UInt16_Counter(&iter);
  return btmp;
}
//----------------------------------------------Group20Var2------------------------------------------
//----------------------------------------------Group20Var5------------------------------------------
////template<class Spec, class Serializer> bool WriteWithSerializer(StaticDataMap<Spec>& map, HeaderWriter& writer)
boolean WriteWithSerializer_CounterSpec_for_Group20Var5_in_StaticWriters_static(StaticDataMap_for_CounterSpec& map, HeaderWriter* writer)
{
////    const auto range = map.get_selected_range();
  Range  range = get_selected_range_in_StaticDataMap_for_CounterSpec(&map);

////    if (range.IsOneByte())
  if (IsOneByte_in_Range(&range))
  {
//RangeWriteIterator_for_UInt8_Counter IterateOverRange_for_UInt8_Counter_in_HeaderWriter(HeaderWriter *pHeaderWriter,
//    QualifierCode_uint8_t qc,
//    DNP3Serializer_for_Counter *serializer,
//    uint8_t start );
//DNP3Serializer_for_Counter  Inst_in_Group20Var5_static(void);
////        auto iter = writer.IterateOverRange<ser4cpp::UInt8, typename Serializer::Target>(
////            QualifierCode::UINT8_START_STOP, Serializer::Inst(), static_cast<uint8_t>(range.start));
    DNP3Serializer_for_Counter tmp = Inst_in_Group20Var5_static();
    RangeWriteIterator_for_UInt8_Counter iter = IterateOverRange_for_UInt8_Counter_in_HeaderWriter(writer,
        QualifierCode_UINT8_START_STOP,
        &tmp,
        (uint8_t) range.start );

//boolean LoadWithRangeIterator_CounterSpec_for_UInt8_in_StaticWriters(StaticDataMap_for_CounterSpec& map,
//    RangeWriteIterator_for_UInt8_Counter *writer, StaticCounterVariation_uint8_t variation)
////        return LoadWithRangeIterator<Spec, ser4cpp::UInt8>(map, iter, Serializer::svariation);
    boolean btmp = LoadWithRangeIterator_CounterSpec_for_UInt8_in_StaticWriters(map, &iter, StaticCounterVariation_Group20Var5);
    RangeWriteIterator_for_UInt8_Counter_destr_RangeWriteIterator_for_UInt8_Counter(&iter);
    return btmp;
  }

////    auto iter = writer.IterateOverRange<ser4cpp::UInt16, typename Serializer::Target>(QualifierCode::UINT16_START_STOP,
////                                                                                      Serializer::Inst(), range.start);
  DNP3Serializer_for_Counter tmp = Inst_in_Group20Var5_static();
  RangeWriteIterator_for_UInt16_Counter iter = IterateOverRange_for_UInt16_Counter_in_HeaderWriter(writer,
      QualifierCode_UINT16_START_STOP,
      &tmp,
      (uint16_t) range.start );

////    return LoadWithRangeIterator<Spec, ser4cpp::UInt16>(map, iter, Serializer::svariation);
  boolean btmp = LoadWithRangeIterator_CounterSpec_for_UInt16_in_StaticWriters(map, &iter, StaticCounterVariation_Group20Var5);
  RangeWriteIterator_for_UInt16_Counter_destr_RangeWriteIterator_for_UInt16_Counter(&iter);
  return btmp;
}
//----------------------------------------------Group20Var5------------------------------------------
//----------------------------------------------Group20Var6------------------------------------------
////template<class Spec, class Serializer> bool WriteWithSerializer(StaticDataMap<Spec>& map, HeaderWriter& writer)
boolean WriteWithSerializer_CounterSpec_for_Group20Var6_in_StaticWriters_static(StaticDataMap_for_CounterSpec& map, HeaderWriter* writer)
{
////    const auto range = map.get_selected_range();
  Range  range = get_selected_range_in_StaticDataMap_for_CounterSpec(&map);

////    if (range.IsOneByte())
  if (IsOneByte_in_Range(&range))
  {
//RangeWriteIterator_for_UInt8_Counter IterateOverRange_for_UInt8_Counter_in_HeaderWriter(HeaderWriter *pHeaderWriter,
//    QualifierCode_uint8_t qc,
//    DNP3Serializer_for_Counter *serializer,
//    uint8_t start );
//DNP3Serializer_for_Counter  Inst_in_Group20Var6_static(void);
////        auto iter = writer.IterateOverRange<ser4cpp::UInt8, typename Serializer::Target>(
////            QualifierCode::UINT8_START_STOP, Serializer::Inst(), static_cast<uint8_t>(range.start));
    DNP3Serializer_for_Counter tmp = Inst_in_Group20Var6_static();
    RangeWriteIterator_for_UInt8_Counter iter = IterateOverRange_for_UInt8_Counter_in_HeaderWriter(writer,
        QualifierCode_UINT8_START_STOP,
        &tmp,
        (uint8_t) range.start );

//boolean LoadWithRangeIterator_CounterSpec_for_UInt8_in_StaticWriters(StaticDataMap_for_CounterSpec& map,
//    RangeWriteIterator_for_UInt8_Counter *writer, StaticCounterVariation_uint8_t variation)
////        return LoadWithRangeIterator<Spec, ser4cpp::UInt8>(map, iter, Serializer::svariation);
    boolean btmp = LoadWithRangeIterator_CounterSpec_for_UInt8_in_StaticWriters(map, &iter, StaticCounterVariation_Group20Var6);
    RangeWriteIterator_for_UInt8_Counter_destr_RangeWriteIterator_for_UInt8_Counter(&iter);
    return btmp;
  }

////    auto iter = writer.IterateOverRange<ser4cpp::UInt16, typename Serializer::Target>(QualifierCode::UINT16_START_STOP,
////                                                                                      Serializer::Inst(), range.start);
  DNP3Serializer_for_Counter tmp = Inst_in_Group20Var6_static();
  RangeWriteIterator_for_UInt16_Counter iter = IterateOverRange_for_UInt16_Counter_in_HeaderWriter(writer,
      QualifierCode_UINT16_START_STOP,
      &tmp,
      (uint16_t) range.start );

////    return LoadWithRangeIterator<Spec, ser4cpp::UInt16>(map, iter, Serializer::svariation);
  boolean btmp = LoadWithRangeIterator_CounterSpec_for_UInt16_in_StaticWriters(map, &iter, StaticCounterVariation_Group20Var6);
  RangeWriteIterator_for_UInt16_Counter_destr_RangeWriteIterator_for_UInt16_Counter(&iter);
  return btmp;
}
//----------------------------------------------Group20Var6------------------------------------------

////static_write_func_t<CounterSpec> StaticWriters::get(StaticCounterVariation variation)
static_write_func_t_for_CounterSpec get_for_CounterSpec_in_StaticWriters_static(StaticCounterVariation_uint8_t variation)
{
#ifdef  LOG_INFO
  std::cout<<""<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"get_for_CounterSpec_in_StaticWriters_static1"<<'\n';
#endif

    switch (variation)
    {
    case (StaticCounterVariation_Group20Var1):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*StaticCounterVariation_Group20Var1"<<'\n';
    decrement_stack_info();
#endif
////        return &WriteWithSerializer<CounterSpec, Group20Var1>;
    return WriteWithSerializer_CounterSpec_for_Group20Var1_in_StaticWriters_static;

    case (StaticCounterVariation_Group20Var2):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*StaticCounterVariation_Group20Var2"<<'\n';
    decrement_stack_info();
#endif
////        return &WriteWithSerializer<CounterSpec, Group20Var2>;
    return WriteWithSerializer_CounterSpec_for_Group20Var2_in_StaticWriters_static;

    case (StaticCounterVariation_Group20Var5):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*StaticCounterVariation_Group20Var5"<<'\n';
    decrement_stack_info();
#endif
////        return &WriteWithSerializer<CounterSpec, Group20Var5>;
    return WriteWithSerializer_CounterSpec_for_Group20Var5_in_StaticWriters_static;

    case (StaticCounterVariation_Group20Var6):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*StaticCounterVariation_Group20Var6"<<'\n';
    decrement_stack_info();
#endif
////        return &WriteWithSerializer<CounterSpec, Group20Var6>;
    return WriteWithSerializer_CounterSpec_for_Group20Var6_in_StaticWriters_static;

    default:
#ifdef  LOG_INFO
    std::cout<<"*error"<<getString_stack_info();
    std::cout<<"*WriteWithSerializer_CounterSpec_for_Group20Var1_in_StaticWriters_static"<<'\n';
    decrement_stack_info();
#endif
////        return &WriteWithSerializer<CounterSpec, Group20Var1>;
    return WriteWithSerializer_CounterSpec_for_Group20Var1_in_StaticWriters_static;
    }
/*
#ifdef  LOG_INFO
  std::cout<<""<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"get_for_CounterSpec_in_StaticWriters_static1"<<'\n';
#endif
  switch (variation)
  {
  case (StaticCounterVariation_Group30Var1):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*StaticCounterVariation_Group30Var1"<<'\n';
    decrement_stack_info();
#endif
////        return &WriteWithSerializer<CounterSpec, Group30Var1>;
    return WriteWithSerializer_CounterSpec_for_Group30Var1_in_StaticWriters_static;

  case (StaticCounterVariation_Group30Var2):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*StaticCounterVariation_Group30Var2"<<'\n';
    decrement_stack_info();
#endif
////        return &WriteWithSerializer<CounterSpec, Group30Var2>;
    return WriteWithSerializer_CounterSpec_for_Group30Var2_in_StaticWriters_static;

////    case (StaticCounterVariation::Group30Var3):
////        return &WriteWithSerializer<CounterSpec, Group30Var3>;
////    case (StaticCounterVariation::Group30Var4):
////        return &WriteWithSerializer<CounterSpec, Group30Var4>;
////    case (StaticCounterVariation::Group30Var5):
////        return &WriteWithSerializer<CounterSpec, Group30Var5>;
////    case (StaticCounterVariation::Group30Var6):
////        return &WriteWithSerializer<CounterSpec, Group30Var6>;
  default:
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*WriteWithSerializer_CounterSpec_for_Group30Var1_in_StaticWriters_static"<<'\n';
    decrement_stack_info();
#endif
////        return &WriteWithSerializer<CounterSpec, Group30Var1>;
    return WriteWithSerializer_CounterSpec_for_Group30Var1_in_StaticWriters_static;
  }
*/
}
