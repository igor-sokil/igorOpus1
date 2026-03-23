#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include <QApplication>
#include "header.h"
#include "StaticWriters_for_OctetString.h"

#include "Group1.h"
#include "Group10.h"
#include "Group20.h"
#include "Group21.h"
#include "Group3.h"
#include "Group30.h"
#include "Group40.h"
#include "Group50.h"
//#include "OctetStringSerializer.h"
#include "HeaderWriter_for_OctetString.h"

////static_write_func_t<OctetStringSpec> StaticWriters::get(StaticOctetStringVariation variation)
static_write_func_t_for_OctetStringSpec get_for_OctetStringSpec_in_StaticWriters_static(StaticOctetStringVariation_uint8_t variation)
{
  UNUSED(variation);

#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"get_for_OctetStringSpec_in_StaticWriters_static1"<<'\n';
  decrement_stack_info();
#endif
  return write_octet_strings_in_StaticWriters_static;

}

boolean write_octet_strings_in_StaticWriters_static(StaticDataMap_for_OctetStringSpec& map, HeaderWriter* writer)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{write_octet_strings_in_StaticWriters_static1"<<'\n';
#endif
  Range range = get_selected_range_in_StaticDataMap_for_OctetStringSpec(&map);////map.get_selected_range();

//uint16_t Size_in_OctetData(OctetData *pOctetData);
  uint8_t starting_size = Size_in_OctetData(&((*map.begin()).second.value.oOctetData));////(*map.begin()).second.value.ttt;////Size();
//void OctetStringSerializer_in_OctetStringSerializer(OctetStringSerializer *pOctetStringSerializer, boolean isEvent, uint8_t size);
////    const OctetStringSerializer serializer(false, starting_size);
  OctetStringSerializer serializer;
  OctetStringSerializer_in_OctetStringSerializer(&serializer, false, starting_size);

//boolean IsOneByte_in_Range(Range *pRange);
////    if (range.IsOneByte())
  if (IsOneByte_in_Range(&range))
  {
//    RangeWriteIterator_for_UInt8_OctetString IterateOverRange_for_UInt8_OctetString_in_HeaderWriter(HeaderWriter *pHeaderWriter,
//                                                   QualifierCode_uint8_t qc,
//                                                   DNP3Serializer_for_OctetString *serializer,
//                                                   uint8_t start
//                                                  );
////        auto iter = writer.IterateOverRange<ser4cpp::UInt8>(QualifierCode::UINT8_START_STOP, serializer,
////                                                            static_cast<uint8_t>(range.start));
    RangeWriteIterator_for_UInt8_OctetString iter = IterateOverRange_for_UInt8_OctetString_in_HeaderWriter(writer,
        QualifierCode_UINT8_START_STOP,
        &(serializer.dDNP3Serializer_for_OctetString),
        (uint8_t)(range.start)
                                                                                                          );

    boolean tmp = write_some_octet_strings_for_UInt8_in_StaticWriters_static(map, &iter);
    RangeWriteIterator_for_UInt8_OctetString_destr_RangeWriteIterator_for_UInt8_OctetString(&iter);
#ifdef  LOG_INFO
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"}write_octet_strings_in_StaticWriters_static1_"<<'\n';
  decrement_stack_info();
#endif
    return tmp;
  }

////    auto iter = writer.IterateOverRange<ser4cpp::UInt16>(QualifierCode::UINT16_START_STOP, serializer, range.start);
  RangeWriteIterator_for_UInt16_OctetString iter = IterateOverRange_for_UInt16_OctetString_in_HeaderWriter(writer,
      QualifierCode_UINT16_START_STOP,
      &(serializer.dDNP3Serializer_for_OctetString),
      (uint16_t)(range.start)
                                                                                                          );

  boolean tmp = write_some_octet_strings_for_UInt16_in_StaticWriters_static(map, &iter);
  RangeWriteIterator_for_UInt16_OctetString_destr_RangeWriteIterator_for_UInt16_OctetString(&iter);
#ifdef  LOG_INFO
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"}write_octet_strings_in_StaticWriters_static2_"<<'\n';
  decrement_stack_info();
#endif
  return tmp;
}

////template<class Writer> bool write_some_octet_strings(StaticDataMap<OctetStringSpec>& map, Writer& writer)
boolean write_some_octet_strings_for_UInt8_in_StaticWriters_static(StaticDataMap_for_OctetStringSpec& map, RangeWriteIterator_for_UInt8_OctetString* writer)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{write_some_octet_strings_for_UInt8_in_StaticWriters_static1"<<'\n';
#endif
  boolean first = true;
  uint8_t last_length = 0;
  uint16_t next_index = 0;

  for (const auto& elem : map)
  {

#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*write_some_octet_strings_for_UInt8_in_StaticWriters_static2"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*boolean first= "<<first<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*uint16_t next_index= "<<next_index<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*elem.first= "<<elem.first<<'\n';
#endif
    if(!first) {

      if(next_index != elem.first) {
        // discontiguous indices
#ifdef  LOG_INFO
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"}write_some_octet_strings_for_UInt8_in_StaticWriters_static1_"<<'\n';
  decrement_stack_info();
#endif
        return true;
      }//if(!first)

//uint16_t Size_in_OctetData(OctetData *pOctetData);
      if(last_length != Size_in_OctetData(&elem.second.value.oOctetData)) {////elem.second.value.Size()) {
        // different lengths
#ifdef  LOG_INFO
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"}write_some_octet_strings_for_UInt8_in_StaticWriters_static2_"<<'\n';
  decrement_stack_info();
#endif
        return true;
      }
    }//if(!first)

    first = false;
    next_index = elem.first + 1;
    last_length = Size_in_OctetData(&elem.second.value.oOctetData);////elem.second.value.Size();

//boolean Write_in_RangeWriteIterator_for_UInt8_OctetString(RangeWriteIterator_for_UInt8_OctetString *pRangeWriteIterator_for_UInt8_OctetString,
//    OctetString* value);
////        if (!writer.Write(elem.second.value))
    if (!Write_in_RangeWriteIterator_for_UInt8_OctetString(writer, &elem.second.value))
    {
#ifdef  LOG_INFO
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"}write_some_octet_strings_for_UInt8_in_StaticWriters_static3_"<<'\n';
  decrement_stack_info();
#endif
      return false;
    }
  }

#ifdef  LOG_INFO
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"}write_some_octet_strings_for_UInt8_in_StaticWriters_static4_"<<'\n';
  decrement_stack_info();
#endif
  return true;
}

////template<class Writer> bool write_some_octet_strings(StaticDataMap<OctetStringSpec>& map, Writer& writer)
boolean write_some_octet_strings_for_UInt16_in_StaticWriters_static(StaticDataMap_for_OctetStringSpec& map, RangeWriteIterator_for_UInt16_OctetString* writer)
{
  boolean first = true;
  uint8_t last_length = 0;
  uint16_t next_index = 0;

  for (const auto& elem : map)
  {

    if(!first) {

      if(next_index != elem.first) {
        // discontiguous indices
        return true;
      }

//uint16_t Size_in_OctetData(OctetData *pOctetData);
      if(last_length != Size_in_OctetData(&elem.second.value.oOctetData)) {////elem.second.value.Size()) {
        // different lengths
        return true;
      }
    }

    first = false;
    next_index = elem.first + 1;
    last_length = Size_in_OctetData(&elem.second.value.oOctetData);////elem.second.value.Size();

//boolean Write_in_RangeWriteIterator_for_UInt16_OctetString(RangeWriteIterator_for_UInt16_OctetString *pRangeWriteIterator_for_UInt16_OctetString,
//    OctetString* value);
////        if (!writer.Write(elem.second.value))
    if (!Write_in_RangeWriteIterator_for_UInt16_OctetString(writer, &elem.second.value))
    {
      return false;
    }
  }

  return true;
}
