#include <QApplication>
#include "header.h"
#include "StaticWriters_for_Binary.h"

#include "Group1.h"
#include "Group10.h"
#include "Group20.h"
#include "Group21.h"
#include "Group3.h"
#include "Group40.h"
#include "Group50.h"
//#include "OctetStringSerializer.h"
#include "HeaderWriter_for_Binary.h"

boolean WriteSingleBitfield_BinarySpec_for_Group1Var1_in_StaticWriters_static(StaticDataMap_for_BinarySpec& map, HeaderWriter* writer);
boolean WriteSingleBitfield_BinarySpec_for_Group1Var2_in_StaticWriters_static(StaticDataMap_for_BinarySpec& map, HeaderWriter* writer);

//----------------------------------------LoadWithRangeIterator_BinarySpec_for_UInt8---------------------------------------------------------
////template<class Spec, class IndexType>
////bool LoadWithRangeIterator(StaticDataMap<Spec>& map,
////                           RangeWriteIterator<IndexType, typename Spec::meas_t>& writer,
////                           typename Spec::static_variation_t variation)
boolean LoadWithRangeIterator_BinarySpec_for_UInt8_in_StaticWriters(StaticDataMap_for_BinarySpec& map,
    RangeWriteIterator_for_UInt8_Binary *writer, StaticBinaryVariation_uint8_t variation)
{
////    auto next_index = map.get_selected_range().start;
  uint16_t  next_index = get_selected_range_in_StaticDataMap_for_BinarySpec(&map).start;

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

//boolean Write_in_RangeWriteIterator_for_UInt8_Binary(RangeWriteIterator_for_UInt8_Binary *pRangeWriteIterator_for_UInt8_Binary,
//    Binary* value);
////        if (!writer.Write(elem.second.value))
    if (!Write_in_RangeWriteIterator_for_UInt8_Binary(writer, &elem.second.value))//.tTypedMeasurement_for_Double64.value))
    {
      return false;
    }

    ++next_index;
  }

  return true;
}
//----------------------------------------LoadWithRangeIterator_BinarySpec_for_UInt8---------------------------------------------------------
//----------------------------------------LoadWithRangeIterator_BinarySpec_for_UInt16---------------------------------------------------------
////template<class Spec, class IndexType>
////bool LoadWithRangeIterator(StaticDataMap<Spec>& map,
////                           RangeWriteIterator<IndexType, typename Spec::meas_t>& writer,
////                           typename Spec::static_variation_t variation)
boolean LoadWithRangeIterator_BinarySpec_for_UInt16_in_StaticWriters(StaticDataMap_for_BinarySpec& map,
    RangeWriteIterator_for_UInt16_Binary *writer, StaticBinaryVariation_uint8_t variation)
{
////    auto next_index = map.get_selected_range().start;
  uint16_t  next_index = get_selected_range_in_StaticDataMap_for_BinarySpec(&map).start;

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

//boolean Write_in_RangeWriteIterator_for_UInt16_Binary(RangeWriteIterator_for_UInt16_Binary *pRangeWriteIterator_for_UInt16_Binary,
//    Binary* value);
////        if (!writer.Write(elem.second.value))
    if (!Write_in_RangeWriteIterator_for_UInt16_Binary(writer, &elem.second.value))//.tTypedMeasurement_for_Double64.value))
    {
      return false;
    }

    ++next_index;
  }

  return true;
}
//----------------------------------------LoadWithRangeIterator_BinarySpec_for_UInt16---------------------------------------------------------
//-------------------------------------LoadWithBitfieldIterator_BinarySpec_for_UInt8---------------------------------------------------
////template<class Spec, class IndexType>
////bool LoadWithBitfieldIterator(StaticDataMap<Spec>& map,
////                              BitfieldRangeWriteIterator<IndexType>& iter,
////                              typename Spec::static_variation_t variation)
boolean LoadWithBitfieldIterator_BinarySpec_for_UInt8_in_StaticWriters(StaticDataMap_for_BinarySpec& map,
    BitfieldRangeWriteIterator_for_UInt8 *iter, StaticBinaryVariation_uint8_t variation)
{
//Range get_selected_range_in_StaticDataMap_for_BinarySpec(StaticDataMap_for_BinarySpec *pStaticDataMap_for_BinarySpec)
////    auto next_index = map.get_selected_range().start;
  uint16_t  next_index = get_selected_range_in_StaticDataMap_for_BinarySpec(&map).start;

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

//boolean Write_in_BitfieldRangeWriteIterator_for_UInt8(BitfieldRangeWriteIterator_for_UInt8 *pBitfieldRangeWriteIterator_for_UInt8, boolean value);
////        if (!iter.Write(elem.second.value.value))
    if (!Write_in_BitfieldRangeWriteIterator_for_UInt8(iter, elem.second.value.tTypedMeasurement_for_Boolean.value))
    {
      return false;
    }

    ++next_index;
  }

  return true;
}
//-------------------------------------LoadWithBitfieldIterator_BinarySpec_for_UInt8---------------------------------------------------
//-------------------------------------LoadWithBitfieldIterator_BinarySpec_for_UInt16---------------------------------------------------
////template<class Spec, class IndexType>
////bool LoadWithBitfieldIterator(StaticDataMap<Spec>& map,
////                              BitfieldRangeWriteIterator<IndexType>& iter,
////                              typename Spec::static_variation_t variation)
boolean LoadWithBitfieldIterator_BinarySpec_for_UInt16_in_StaticWriters(StaticDataMap_for_BinarySpec& map,
    BitfieldRangeWriteIterator_for_UInt16 *iter, StaticBinaryVariation_uint8_t variation)
{
//Range get_selected_range_in_StaticDataMap_for_BinarySpec(StaticDataMap_for_BinarySpec *pStaticDataMap_for_BinarySpec)
////    auto next_index = map.get_selected_range().start;
  uint16_t  next_index = get_selected_range_in_StaticDataMap_for_BinarySpec(&map).start;

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

//boolean Write_in_BitfieldRangeWriteIterator_for_UInt8(BitfieldRangeWriteIterator_for_UInt8 *pBitfieldRangeWriteIterator_for_UInt8, boolean value);
////        if (!iter.Write(elem.second.value.value))
    if (!Write_in_BitfieldRangeWriteIterator_for_UInt16(iter, elem.second.value.tTypedMeasurement_for_Boolean.value))
    {
      return false;
    }

    ++next_index;
  }

  return true;
}
//-------------------------------------LoadWithBitfieldIterator_BinarySpec_for_UInt16---------------------------------------------------

//-------------------------------------WriteSingleBitfield_BinarySpec_for_Group1Var1_in_StaticWriters_static---------------------------------------------------
////template<class Spec, class GV> bool WriteSingleBitfield(StaticDataMap<Spec>& map, HeaderWriter& writer)
boolean WriteSingleBitfield_BinarySpec_for_Group1Var1_in_StaticWriters_static(StaticDataMap_for_BinarySpec& map, HeaderWriter* writer)
{
//Range get_selected_range_in_StaticDataMap_for_BinarySpec(StaticDataMap_for_BinarySpec *pStaticDataMap_for_BinarySpec);
////    const auto range = map.get_selected_range();
  Range  range = get_selected_range_in_StaticDataMap_for_BinarySpec(&map);

//boolean IsOneByte_in_Range(Range *pRange);
////    if (range.IsOneByte())
  if (IsOneByte_in_Range(&range))
  {
//BitfieldRangeWriteIterator_for_UInt8 IterateOverSingleBitfield_for_uint8_in_HeaderWriter(HeaderWriter *pHeaderWriter,
//    GroupVariationID id,
//    QualifierCode_uint8_t qc,
//    uint8_t start);
//GroupVariationID ID_in_Group1Var1_static(void);
////        auto write_iter = writer.IterateOverSingleBitfield<ser4cpp::UInt8>(GV::ID(), QualifierCode::UINT8_START_STOP,
////                                                                           static_cast<uint8_t>(range.start));
    BitfieldRangeWriteIterator_for_UInt8  write_iter = IterateOverSingleBitfield_for_UInt8_in_HeaderWriter(writer,
        ID_in_Group1Var1_static(),
        QualifierCode_UINT8_START_STOP,
        (uint8_t)range.start);

////        return LoadWithBitfieldIterator<Spec, ser4cpp::UInt8>(map, write_iter, GV::svariation);
    boolean btmp = LoadWithBitfieldIterator_BinarySpec_for_UInt8_in_StaticWriters(map, &write_iter, svariation_in_Group1Var1);
    BitfieldRangeWriteIterator_for_UInt8_destr_BitfieldRangeWriteIterator_for_UInt8(&write_iter);
    return btmp;
  }

////    auto write_iter
////        = writer.IterateOverSingleBitfield<ser4cpp::UInt16>(GV::ID(), QualifierCode::UINT16_START_STOP, range.start);
  BitfieldRangeWriteIterator_for_UInt16  write_iter = IterateOverSingleBitfield_for_UInt16_in_HeaderWriter(writer,
      ID_in_Group1Var1_static(),
      QualifierCode_UINT16_START_STOP,
      range.start);
////    return LoadWithBitfieldIterator<Spec, ser4cpp::UInt16>(map, write_iter, GV::svariation);
  boolean btmp = LoadWithBitfieldIterator_BinarySpec_for_UInt16_in_StaticWriters(map, &write_iter, svariation_in_Group1Var1);
  BitfieldRangeWriteIterator_for_UInt16_destr_BitfieldRangeWriteIterator_for_UInt16(&write_iter);
  return btmp;
}
//-------------------------------------WriteSingleBitfield_BinarySpec_for_Group1Var1_in_StaticWriters_static---------------------------------------------------

////template<class Spec, class Serializer> bool WriteWithSerializer(StaticDataMap<Spec>& map, HeaderWriter& writer)
boolean WriteWithSerializer_BinarySpec_for_Group1Var2_in_StaticWriters_static(StaticDataMap_for_BinarySpec& map, HeaderWriter* writer)
{
////    const auto range = map.get_selected_range();
  Range  range = get_selected_range_in_StaticDataMap_for_BinarySpec(&map);

////    if (range.IsOneByte())
  if (IsOneByte_in_Range(&range))
  {
//RangeWriteIterator_for_UInt8_Binary IterateOverRange_for_UInt8_Binary_in_HeaderWriter(HeaderWriter *pHeaderWriter,
//    QualifierCode_uint8_t qc,
//    DNP3Serializer_for_Binary *serializer,
//    uint8_t start );
////        auto iter = writer.IterateOverRange<ser4cpp::UInt8, typename Serializer::Target>(
////            QualifierCode::UINT8_START_STOP, Serializer::Inst(), static_cast<uint8_t>(range.start));
    DNP3Serializer_for_Binary tmp = Inst_in_Group1Var2_static();
    RangeWriteIterator_for_UInt8_Binary iter = IterateOverRange_for_UInt8_Binary_in_HeaderWriter(writer,
        QualifierCode_UINT8_START_STOP,
        &tmp,
        (uint8_t) range.start );

////        return LoadWithRangeIterator<Spec, ser4cpp::UInt8>(map, iter, Serializer::svariation);
    boolean btmp = LoadWithRangeIterator_BinarySpec_for_UInt8_in_StaticWriters(map, &iter, StaticBinaryVariation_Group1Var2);
    RangeWriteIterator_for_UInt8_Binary_destr_RangeWriteIterator_for_UInt8_Binary(&iter);
    return btmp;
  }

////    auto iter = writer.IterateOverRange<ser4cpp::UInt16, typename Serializer::Target>(QualifierCode::UINT16_START_STOP,
////                                                                                      Serializer::Inst(), range.start);
  DNP3Serializer_for_Binary tmp = Inst_in_Group1Var2_static();
  RangeWriteIterator_for_UInt16_Binary iter = IterateOverRange_for_UInt16_Binary_in_HeaderWriter(writer,
      QualifierCode_UINT16_START_STOP,
      &tmp,
      (uint16_t) range.start );

////    return LoadWithRangeIterator<Spec, ser4cpp::UInt16>(map, iter, Serializer::svariation);
  boolean btmp = LoadWithRangeIterator_BinarySpec_for_UInt16_in_StaticWriters(map, &iter, StaticBinaryVariation_Group1Var2);
  RangeWriteIterator_for_UInt16_Binary_destr_RangeWriteIterator_for_UInt16_Binary(&iter);
  return btmp;
}

////static_write_func_t<BinarySpec> StaticWriters::get(StaticBinaryVariation variation)
static_write_func_t_for_BinarySpec  get_for_BinarySpec_in_StaticWriters_static(StaticBinaryVariation_uint8_t variation)
{
  switch (variation)
  {
  case (StaticBinaryVariation_Group1Var1):
////        return &WriteSingleBitfield<BinarySpec, Group1Var1>;
    return &WriteSingleBitfield_BinarySpec_for_Group1Var1_in_StaticWriters_static;
  default:
////        return &WriteWithSerializer<BinarySpec, Group1Var2>;
    return &WriteWithSerializer_BinarySpec_for_Group1Var2_in_StaticWriters_static;
  }
}
