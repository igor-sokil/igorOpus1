
#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include <QApplication>
#include "header.h"
#include "TypedCommandHeader.h"

//------------------------AnalogOutputInt16----------------------------
void TypedCommandHeader_for_AnalogOutputInt16_in_TypedCommandHeader_for_AnalogOutputInt16(TypedCommandHeader_for_AnalogOutputInt16 *pTypedCommandHeader_for_AnalogOutputInt16,
    DNP3Serializer_for_AnalogOutputInt16* serializer)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{TypedCommandHeader_for_AnalogOutputInt16_in_TypedCommandHeader_for_AnalogOutputInt16_1"<<'\n';
#endif
//// : serializer(serializer) {}
  pTypedCommandHeader_for_AnalogOutputInt16->use_single_byte_index = true;
  pTypedCommandHeader_for_AnalogOutputInt16->serializer = *serializer;

  pTypedCommandHeader_for_AnalogOutputInt16->iICommandCollection_for_AnalogOutputInt16.pAdd_in_ICommandCollection_for_AnalogOutputInt16 = Add_in_TypedCommandHeader_for_AnalogOutputInt16_override;
  pTypedCommandHeader_for_AnalogOutputInt16->iICommandHeader.pWrite_in_ICommandHeader = Write_in_TypedCommandHeader_for_AnalogOutputInt16_override;

  setParentPointer_in_ICommandCollection_for_AnalogOutputInt16(&(pTypedCommandHeader_for_AnalogOutputInt16->iICommandCollection_for_AnalogOutputInt16), pTypedCommandHeader_for_AnalogOutputInt16);
  setParentPointer_in_ICommandHeader(&(pTypedCommandHeader_for_AnalogOutputInt16->iICommandHeader), pTypedCommandHeader_for_AnalogOutputInt16);
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}TypedCommandHeader_for_AnalogOutputInt16_in_TypedCommandHeader_for_AnalogOutputInt16__"<<'\n';
  decrement_stack_info();
#endif
}

void* Add_in_TypedCommandHeader_for_AnalogOutputInt16_override(void* pICommandCollection_for_AnalogOutputInt16,
    AnalogOutputInt16* command, uint16_t index)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{Add_in_TypedCommandHeader_for_AnalogOutputInt16_override1"<<'\n';
#endif
  TypedCommandHeader_for_AnalogOutputInt16 *parent =
    (TypedCommandHeader_for_AnalogOutputInt16 *)getParentPointer_in_ICommandCollection_for_AnalogOutputInt16((ICommandCollection_for_AnalogOutputInt16*)pICommandCollection_for_AnalogOutputInt16);
  void* tmp = Add_in_TypedCommandHeader_for_AnalogOutputInt16(parent, command, index);

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}Add_in_TypedCommandHeader_for_AnalogOutputInt16_override_"<<'\n';
  decrement_stack_info();
#endif
  return tmp;
}

boolean Write_in_TypedCommandHeader_for_AnalogOutputInt16_override(void* pICommandHeader,
              HeaderWriter* writer, IndexQualifierMode_uint8_t mode)
{
  TypedCommandHeader_for_AnalogOutputInt16 *parent =
    (TypedCommandHeader_for_AnalogOutputInt16 *)getParentPointer_in_ICommandHeader((ICommandHeader*)pICommandHeader);
  return Write_in_TypedCommandHeader_for_AnalogOutputInt16(parent, writer, mode);
}

////template<class T> ICommandCollection<T>& TypedCommandHeader<T>::Add(const T& command, uint16_t index)
void* Add_in_TypedCommandHeader_for_AnalogOutputInt16(TypedCommandHeader_for_AnalogOutputInt16* pTypedCommandHeader_for_AnalogOutputInt16,
    AnalogOutputInt16* command, uint16_t index)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{Add_in_TypedCommandHeader_for_AnalogOutputInt16_1"<<'\n';
#endif
  if (index > 255)////std::numeric_limits<uint8_t>::max())
  {
////        this->use_single_byte_index = false;
    pTypedCommandHeader_for_AnalogOutputInt16->use_single_byte_index = false;
  }

//Indexed_for_AnalogOutputInt16 WithIndex_in_Indexed_for_AnalogOutputInt16(AnalogOutputInt16* value, uint16_t index);
////    this->records.push_back(WithIndex(command, index));
  (pTypedCommandHeader_for_AnalogOutputInt16->records).push_back(WithIndex_in_Indexed_for_AnalogOutputInt16(command, index));

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}Add_in_TypedCommandHeader_for_AnalogOutputInt16__"<<'\n';
  decrement_stack_info();
#endif
////    return *this;
  return &(pTypedCommandHeader_for_AnalogOutputInt16->iICommandCollection_for_AnalogOutputInt16);
}

////template<class T> bool TypedCommandHeader<T>::Write(HeaderWriter& writer, IndexQualifierMode mode)
boolean Write_in_TypedCommandHeader_for_AnalogOutputInt16(TypedCommandHeader_for_AnalogOutputInt16* pTypedCommandHeader_for_AnalogOutputInt16,
    HeaderWriter* writer, IndexQualifierMode_uint8_t mode)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{Write_in_TypedCommandHeader_for_AnalogOutputInt16_1"<<'\n';
#endif
  if (pTypedCommandHeader_for_AnalogOutputInt16->records.empty())
  {
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}Write_in_TypedCommandHeader_for_AnalogOutputInt16_1_"<<'\n';
  decrement_stack_info();
#endif
    return false;
  }

  // allow single byte indices if they're all <= 255 and the optimization is allowed
////    this->use_single_byte_index &= (mode == IndexQualifierMode::allow_one_byte);
  pTypedCommandHeader_for_AnalogOutputInt16->use_single_byte_index &= (mode == IndexQualifierMode_allow_one_byte);

  if (pTypedCommandHeader_for_AnalogOutputInt16->use_single_byte_index)
  {
//  PrefixedWriteIterator_for_UInt8_AnalogOutputInt16 IterateOverCountWithPrefix_for_UInt16_AnalogOutputInt16_in_HeaderWriter(HeaderWriter *pHeaderWriter,
//    QualifierCode_uint8_t qc, DNP3Serializer_for_AnalogOutputInt16* serializer);
////        auto iter = writer.IterateOverCountWithPrefix<ser4cpp::UInt8, T>(QualifierCode::UINT8_CNT_UINT8_INDEX,
////                                                                         this->serializer);
    PrefixedWriteIterator_for_UInt8_AnalogOutputInt16 iter = IterateOverCountWithPrefix_for_UInt8_AnalogOutputInt16_in_HeaderWriter(
          writer,
          QualifierCode_UINT8_CNT_UINT8_INDEX, &(pTypedCommandHeader_for_AnalogOutputInt16->serializer));


////        for (auto& rec : this->records)
    for (auto& rec : pTypedCommandHeader_for_AnalogOutputInt16->records)
    {
//boolean Write_in_PrefixedWriteIterator_for_UInt8_AnalogOutputInt16(PrefixedWriteIterator_for_UInt8_AnalogOutputInt16 *pPrefixedWriteIterator_for_UInt8_AnalogOutputInt16,
//    AnalogOutputInt16* value, uint16_t index);
////            if (!iter.Write(rec.command, static_cast<uint8_t>(rec.index)))
      if (!Write_in_PrefixedWriteIterator_for_UInt8_AnalogOutputInt16(&iter, &rec.value, (uint8_t)rec.index))
      {
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}Write_in_TypedCommandHeader_for_AnalogOutputInt16_2_"<<'\n';
  decrement_stack_info();
#endif
        return false;
      }
    }

////        return iter.IsValid();
    boolean tmp = IsValid_in_PrefixedWriteIterator_for_UInt8_AnalogOutputInt16(&iter);
    PrefixedWriteIterator_for_UInt8_AnalogOutputInt16_destr_PrefixedWriteIterator_for_UInt8_AnalogOutputInt16(&iter);

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}Write_in_TypedCommandHeader_for_AnalogOutputInt16_3_"<<'\n';
  decrement_stack_info();
#endif
    return tmp;
  }
  else
  {
////        auto iter = writer.IterateOverCountWithPrefix<ser4cpp::UInt16, T>(QualifierCode::UINT16_CNT_UINT16_INDEX,
////                                                                          this->serializer);
    PrefixedWriteIterator_for_UInt16_AnalogOutputInt16 iter = IterateOverCountWithPrefix_for_UInt16_AnalogOutputInt16_in_HeaderWriter(
          writer,
          QualifierCode_UINT16_CNT_UINT16_INDEX, &(pTypedCommandHeader_for_AnalogOutputInt16->serializer));

////        for (auto& rec : this->records)
    for (auto& rec : pTypedCommandHeader_for_AnalogOutputInt16->records)
    {
////            if (!iter.Write(rec.command, rec.index))
      if (!Write_in_PrefixedWriteIterator_for_UInt16_AnalogOutputInt16(&iter, &rec.value, rec.index))
      {
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}Write_in_TypedCommandHeader_for_AnalogOutputInt16_4_"<<'\n';
  decrement_stack_info();
#endif
        return false;
      }
    }

////        return iter.IsValid();
    boolean tmp = IsValid_in_PrefixedWriteIterator_for_UInt16_AnalogOutputInt16(&iter);
    PrefixedWriteIterator_for_UInt16_AnalogOutputInt16_destr_PrefixedWriteIterator_for_UInt16_AnalogOutputInt16(&iter);

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}Write_in_TypedCommandHeader_for_AnalogOutputInt16_5_"<<'\n';
  decrement_stack_info();
#endif
    return tmp;
  }
}
//------------------------AnalogOutputInt16----------------------------
