
#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include <QApplication>
#include "header.h"
#include "TypedCommandHeader.h"
#include "Group41.h"

//------------------------AnalogOutputInt16----------------------------
void Record_in_TypedCommandHeader_for_AnalogOutputInt16_in_Record_in_TypedCommandHeader_for_AnalogOutputInt16(Record_in_TypedCommandHeader_for_AnalogOutputInt16 *pRecord_in_TypedCommandHeader_for_AnalogOutputInt16,
    Indexed_for_AnalogOutputInt16* pair);
void Record_in_TypedCommandHeader_for_AnalogOutputInt16_in_Record_in_TypedCommandHeader_for_AnalogOutputInt16(Record_in_TypedCommandHeader_for_AnalogOutputInt16 *pRecord_in_TypedCommandHeader_for_AnalogOutputInt16,
    Indexed_for_AnalogOutputInt16* pair)
{
  CommandState_in_CommandState(&(pRecord_in_TypedCommandHeader_for_AnalogOutputInt16->cCommandState), pair->index);
  pRecord_in_TypedCommandHeader_for_AnalogOutputInt16->command = pair->value;
}

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

  pTypedCommandHeader_for_AnalogOutputInt16->iICommandHeader.iICollection_for_CommandState.pCount_in_ICollection_for_CommandState = Count_in_TypedCommandHeader_for_AnalogOutputInt16_override;
  pTypedCommandHeader_for_AnalogOutputInt16->iICommandHeader.iICollection_for_CommandState.pForeach_in_ICollection_for_CommandState = Foreach_in_TypedCommandHeader_for_AnalogOutputInt16_override;

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

//void Record_in_TypedCommandHeader_for_AnalogOutputInt16_in_Record_in_TypedCommandHeader_for_AnalogOutputInt16(Record_in_TypedCommandHeader_for_AnalogOutputInt16 *pRecord_in_TypedCommandHeader_for_AnalogOutputInt16,
//                      Indexed_for_AnalogOutputInt16* pair);
//Indexed_for_AnalogOutputInt16 WithIndex_in_Indexed_for_AnalogOutputInt16(AnalogOutputInt16* value, uint16_t index);
////    this->records.push_back(WithIndex(command, index));
  Indexed_for_AnalogOutputInt16 tmp = WithIndex_in_Indexed_for_AnalogOutputInt16(command, index);
  Record_in_TypedCommandHeader_for_AnalogOutputInt16 rRecord_in_TypedCommandHeader_for_AnalogOutputInt16;
  Record_in_TypedCommandHeader_for_AnalogOutputInt16_in_Record_in_TypedCommandHeader_for_AnalogOutputInt16(&rRecord_in_TypedCommandHeader_for_AnalogOutputInt16,
      &tmp);
  (pTypedCommandHeader_for_AnalogOutputInt16->records).push_back(rRecord_in_TypedCommandHeader_for_AnalogOutputInt16);

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

#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*Write_in_TypedCommandHeader_for_AnalogOutputInt16_2"<<'\n';
#endif
////        for (auto& rec : this->records)
    for (auto& rec : pTypedCommandHeader_for_AnalogOutputInt16->records)
    {
#ifdef  LOG_INFO
      std::cout<<"*"<<getString_stack_info();
      std::cout<<"*Write_in_TypedCommandHeader_for_AnalogOutputInt16_3"<<'\n';
#endif
//boolean Write_in_PrefixedWriteIterator_for_UInt8_AnalogOutputInt16(PrefixedWriteIterator_for_UInt8_AnalogOutputInt16 *pPrefixedWriteIterator_for_UInt8_AnalogOutputInt16,
//    AnalogOutputInt16* value, uint16_t index);
////            if (!iter.Write(rec.command, static_cast<uint8_t>(rec.index)))
//      if (!Write_in_PrefixedWriteIterator_for_UInt8_AnalogOutputInt16(&iter, &rec.value, (uint8_t)rec.index))
      if (!Write_in_PrefixedWriteIterator_for_UInt8_AnalogOutputInt16(&iter, &rec.command, (uint8_t)rec.cCommandState.index))
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

#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*Write_in_TypedCommandHeader_for_AnalogOutputInt16_3"<<'\n';
#endif
////        for (auto& rec : this->records)
    for (auto& rec : pTypedCommandHeader_for_AnalogOutputInt16->records)
    {
#ifdef  LOG_INFO
      std::cout<<"*"<<getString_stack_info();
      std::cout<<"*Write_in_TypedCommandHeader_for_AnalogOutputInt16_4"<<'\n';
#endif
////            if (!iter.Write(rec.command, rec.index))
      if (!Write_in_PrefixedWriteIterator_for_UInt16_AnalogOutputInt16(&iter, &rec.command, rec.cCommandState.index))
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

////template<class T> size_t TypedCommandHeader<T>::Count() const
uint16_t Count_in_TypedCommandHeader_for_AnalogOutputInt16(TypedCommandHeader_for_AnalogOutputInt16 *pTypedCommandHeader_for_AnalogOutputInt16)
{
  return pTypedCommandHeader_for_AnalogOutputInt16->records.size();
}
uint16_t Count_in_TypedCommandHeader_for_AnalogOutputInt16_override(void *pICollection_for_CommandState)
{
  TypedCommandHeader_for_AnalogOutputInt16 *parent = (TypedCommandHeader_for_AnalogOutputInt16*)getParentPointer_in_ICollection_for_CommandState((ICollection_for_CommandState*) pICollection_for_CommandState);
  return Count_in_TypedCommandHeader_for_AnalogOutputInt16(parent);
}

////template<class T> void TypedCommandHeader<T>::Foreach(IVisitor<CommandState>& visitor) const
void Foreach_in_TypedCommandHeader_for_AnalogOutputInt16(TypedCommandHeader_for_AnalogOutputInt16 *pTypedCommandHeader_for_AnalogOutputInt16,
    IVisitor__for__CommandState* visitor)
{
  for (auto& rec : pTypedCommandHeader_for_AnalogOutputInt16->records)
  {
//void OnValue_in_IVisitor__for__CommandState(IVisitor__for__CommandState *, CommandState* );
////        visitor.OnValue(rec);
    OnValue_in_IVisitor__for__CommandState(visitor, &rec.cCommandState);
  }
}
void Foreach_in_TypedCommandHeader_for_AnalogOutputInt16_override(void *pICollection_for_CommandState, IVisitor__for__CommandState* visitor)
{
  TypedCommandHeader_for_AnalogOutputInt16 *parent = (TypedCommandHeader_for_AnalogOutputInt16*)getParentPointer_in_ICollection_for_CommandState((ICollection_for_CommandState*) pICollection_for_CommandState);
  return Foreach_in_TypedCommandHeader_for_AnalogOutputInt16(parent, visitor);
}
//------------------------AnalogOutputInt16----------------------------
//------------------------AnalogOutputInt32----------------------------
void Record_in_TypedCommandHeader_for_AnalogOutputInt32_in_Record_in_TypedCommandHeader_for_AnalogOutputInt32(Record_in_TypedCommandHeader_for_AnalogOutputInt32 *pRecord_in_TypedCommandHeader_for_AnalogOutputInt32,
    Indexed_for_AnalogOutputInt32* pair)
{
  CommandState_in_CommandState(&(pRecord_in_TypedCommandHeader_for_AnalogOutputInt32->cCommandState), pair->index);
  pRecord_in_TypedCommandHeader_for_AnalogOutputInt32->command = pair->value;
}

void TypedCommandHeader_for_AnalogOutputInt32_in_TypedCommandHeader_for_AnalogOutputInt32(TypedCommandHeader_for_AnalogOutputInt32 *pTypedCommandHeader_for_AnalogOutputInt32,
    DNP3Serializer_for_AnalogOutputInt32* serializer)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{TypedCommandHeader_for_AnalogOutputInt32_in_TypedCommandHeader_for_AnalogOutputInt32_1"<<'\n';
#endif
//// : serializer(serializer) {}
  pTypedCommandHeader_for_AnalogOutputInt32->use_single_byte_index = true;
  pTypedCommandHeader_for_AnalogOutputInt32->serializer = *serializer;

  pTypedCommandHeader_for_AnalogOutputInt32->iICommandCollection_for_AnalogOutputInt32.pAdd_in_ICommandCollection_for_AnalogOutputInt32 = Add_in_TypedCommandHeader_for_AnalogOutputInt32_override;
  pTypedCommandHeader_for_AnalogOutputInt32->iICommandHeader.pWrite_in_ICommandHeader = Write_in_TypedCommandHeader_for_AnalogOutputInt32_override;

  pTypedCommandHeader_for_AnalogOutputInt32->iICommandHeader.iICollection_for_CommandState.pCount_in_ICollection_for_CommandState = Count_in_TypedCommandHeader_for_AnalogOutputInt32_override;
  pTypedCommandHeader_for_AnalogOutputInt32->iICommandHeader.iICollection_for_CommandState.pForeach_in_ICollection_for_CommandState = Foreach_in_TypedCommandHeader_for_AnalogOutputInt32_override;

  setParentPointer_in_ICommandCollection_for_AnalogOutputInt32(&(pTypedCommandHeader_for_AnalogOutputInt32->iICommandCollection_for_AnalogOutputInt32), pTypedCommandHeader_for_AnalogOutputInt32);
  setParentPointer_in_ICommandHeader(&(pTypedCommandHeader_for_AnalogOutputInt32->iICommandHeader), pTypedCommandHeader_for_AnalogOutputInt32);
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}TypedCommandHeader_for_AnalogOutputInt32_in_TypedCommandHeader_for_AnalogOutputInt32__"<<'\n';
  decrement_stack_info();
#endif
}

void* Add_in_TypedCommandHeader_for_AnalogOutputInt32_override(void* pICommandCollection_for_AnalogOutputInt32,
    AnalogOutputInt32* command, uint16_t index)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{Add_in_TypedCommandHeader_for_AnalogOutputInt32_override1"<<'\n';
#endif
  TypedCommandHeader_for_AnalogOutputInt32 *parent =
    (TypedCommandHeader_for_AnalogOutputInt32 *)getParentPointer_in_ICommandCollection_for_AnalogOutputInt32((ICommandCollection_for_AnalogOutputInt32*)pICommandCollection_for_AnalogOutputInt32);
  void* tmp = Add_in_TypedCommandHeader_for_AnalogOutputInt32(parent, command, index);

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}Add_in_TypedCommandHeader_for_AnalogOutputInt32_override_"<<'\n';
  decrement_stack_info();
#endif
  return tmp;
}

boolean Write_in_TypedCommandHeader_for_AnalogOutputInt32_override(void* pICommandHeader,
    HeaderWriter* writer, IndexQualifierMode_uint8_t mode)
{
  TypedCommandHeader_for_AnalogOutputInt32 *parent =
    (TypedCommandHeader_for_AnalogOutputInt32 *)getParentPointer_in_ICommandHeader((ICommandHeader*)pICommandHeader);
  return Write_in_TypedCommandHeader_for_AnalogOutputInt32(parent, writer, mode);
}

////template<class T> ICommandCollection<T>& TypedCommandHeader<T>::Add(const T& command, uint16_t index)
void* Add_in_TypedCommandHeader_for_AnalogOutputInt32(TypedCommandHeader_for_AnalogOutputInt32* pTypedCommandHeader_for_AnalogOutputInt32,
    AnalogOutputInt32* command, uint16_t index)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{Add_in_TypedCommandHeader_for_AnalogOutputInt32_1"<<'\n';
#endif
  if (index > 255)////std::numeric_limits<uint8_t>::max())
  {
////        this->use_single_byte_index = false;
    pTypedCommandHeader_for_AnalogOutputInt32->use_single_byte_index = false;
  }

//Indexed_for_AnalogOutputInt32 WithIndex_in_Indexed_for_AnalogOutputInt32(AnalogOutputInt32* value, uint16_t index);
////    this->records.push_back(WithIndex(command, index));
//  (pTypedCommandHeader_for_AnalogOutputInt32->records).push_back(WithIndex_in_Indexed_for_AnalogOutputInt32(command, index));
  Indexed_for_AnalogOutputInt32 tmp = WithIndex_in_Indexed_for_AnalogOutputInt32(command, index);
  Record_in_TypedCommandHeader_for_AnalogOutputInt32 rRecord_in_TypedCommandHeader_for_AnalogOutputInt32;
  Record_in_TypedCommandHeader_for_AnalogOutputInt32_in_Record_in_TypedCommandHeader_for_AnalogOutputInt32(&rRecord_in_TypedCommandHeader_for_AnalogOutputInt32,
      &tmp);
  (pTypedCommandHeader_for_AnalogOutputInt32->records).push_back(rRecord_in_TypedCommandHeader_for_AnalogOutputInt32);

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}Add_in_TypedCommandHeader_for_AnalogOutputInt32__"<<'\n';
  decrement_stack_info();
#endif
////    return *this;
  return &(pTypedCommandHeader_for_AnalogOutputInt32->iICommandCollection_for_AnalogOutputInt32);
}

////template<class T> bool TypedCommandHeader<T>::Write(HeaderWriter& writer, IndexQualifierMode mode)
boolean Write_in_TypedCommandHeader_for_AnalogOutputInt32(TypedCommandHeader_for_AnalogOutputInt32* pTypedCommandHeader_for_AnalogOutputInt32,
    HeaderWriter* writer, IndexQualifierMode_uint8_t mode)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{Write_in_TypedCommandHeader_for_AnalogOutputInt32_1"<<'\n';
#endif
  if (pTypedCommandHeader_for_AnalogOutputInt32->records.empty())
  {
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"}Write_in_TypedCommandHeader_for_AnalogOutputInt32_1_"<<'\n';
    decrement_stack_info();
#endif
    return false;
  }

  // allow single byte indices if they're all <= 255 and the optimization is allowed
////    this->use_single_byte_index &= (mode == IndexQualifierMode::allow_one_byte);
  pTypedCommandHeader_for_AnalogOutputInt32->use_single_byte_index &= (mode == IndexQualifierMode_allow_one_byte);

  if (pTypedCommandHeader_for_AnalogOutputInt32->use_single_byte_index)
  {
//  PrefixedWriteIterator_for_UInt8_AnalogOutputInt32 IterateOverCountWithPrefix_for_UInt16_AnalogOutputInt32_in_HeaderWriter(HeaderWriter *pHeaderWriter,
//    QualifierCode_uint8_t qc, DNP3Serializer_for_AnalogOutputInt32* serializer);
////        auto iter = writer.IterateOverCountWithPrefix<ser4cpp::UInt8, T>(QualifierCode::UINT8_CNT_UINT8_INDEX,
////                                                                         this->serializer);
    PrefixedWriteIterator_for_UInt8_AnalogOutputInt32 iter = IterateOverCountWithPrefix_for_UInt8_AnalogOutputInt32_in_HeaderWriter(
          writer,
          QualifierCode_UINT8_CNT_UINT8_INDEX, &(pTypedCommandHeader_for_AnalogOutputInt32->serializer));

#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*Write_in_TypedCommandHeader_for_AnalogOutputInt32_2"<<'\n';
#endif
////        for (auto& rec : this->records)
    for (auto& rec : pTypedCommandHeader_for_AnalogOutputInt32->records)
    {
#ifdef  LOG_INFO
      std::cout<<"*"<<getString_stack_info();
      std::cout<<"*Write_in_TypedCommandHeader_for_AnalogOutputInt32_3"<<'\n';
#endif
//boolean Write_in_PrefixedWriteIterator_for_UInt8_AnalogOutputInt32(PrefixedWriteIterator_for_UInt8_AnalogOutputInt32 *pPrefixedWriteIterator_for_UInt8_AnalogOutputInt32,
//    AnalogOutputInt32* value, uint16_t index);
////            if (!iter.Write(rec.command, static_cast<uint8_t>(rec.index)))
      if (!Write_in_PrefixedWriteIterator_for_UInt8_AnalogOutputInt32(&iter, &rec.command, (uint8_t)rec.cCommandState.index))
      {
#ifdef  LOG_INFO
        std::cout<<getString_stack_info();
        std::cout<<"}Write_in_TypedCommandHeader_for_AnalogOutputInt32_2_"<<'\n';
        decrement_stack_info();
#endif
        return false;
      }
    }

////        return iter.IsValid();
    boolean tmp = IsValid_in_PrefixedWriteIterator_for_UInt8_AnalogOutputInt32(&iter);
    PrefixedWriteIterator_for_UInt8_AnalogOutputInt32_destr_PrefixedWriteIterator_for_UInt8_AnalogOutputInt32(&iter);

#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"}Write_in_TypedCommandHeader_for_AnalogOutputInt32_3_"<<'\n';
    decrement_stack_info();
#endif
    return tmp;
  }
  else
  {
////        auto iter = writer.IterateOverCountWithPrefix<ser4cpp::UInt16, T>(QualifierCode::UINT16_CNT_UINT16_INDEX,
////                                                                          this->serializer);
    PrefixedWriteIterator_for_UInt16_AnalogOutputInt32 iter = IterateOverCountWithPrefix_for_UInt16_AnalogOutputInt32_in_HeaderWriter(
          writer,
          QualifierCode_UINT16_CNT_UINT16_INDEX, &(pTypedCommandHeader_for_AnalogOutputInt32->serializer));

#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*Write_in_TypedCommandHeader_for_AnalogOutputInt32_3"<<'\n';
#endif
////        for (auto& rec : this->records)
    for (auto& rec : pTypedCommandHeader_for_AnalogOutputInt32->records)
    {
#ifdef  LOG_INFO
      std::cout<<"*"<<getString_stack_info();
      std::cout<<"*Write_in_TypedCommandHeader_for_AnalogOutputInt32_4"<<'\n';
#endif
////            if (!iter.Write(rec.command, rec.index))
      if (!Write_in_PrefixedWriteIterator_for_UInt16_AnalogOutputInt32(&iter, &rec.command, rec.cCommandState.index))
      {
#ifdef  LOG_INFO
        std::cout<<getString_stack_info();
        std::cout<<"}Write_in_TypedCommandHeader_for_AnalogOutputInt32_4_"<<'\n';
        decrement_stack_info();
#endif
        return false;
      }
    }

////        return iter.IsValid();
    boolean tmp = IsValid_in_PrefixedWriteIterator_for_UInt16_AnalogOutputInt32(&iter);
    PrefixedWriteIterator_for_UInt16_AnalogOutputInt32_destr_PrefixedWriteIterator_for_UInt16_AnalogOutputInt32(&iter);

#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"}Write_in_TypedCommandHeader_for_AnalogOutputInt32_5_"<<'\n';
    decrement_stack_info();
#endif
    return tmp;
  }
}

////template<class T> size_t TypedCommandHeader<T>::Count() const
uint16_t Count_in_TypedCommandHeader_for_AnalogOutputInt32(TypedCommandHeader_for_AnalogOutputInt32 *pTypedCommandHeader_for_AnalogOutputInt32)
{
  return pTypedCommandHeader_for_AnalogOutputInt32->records.size();
}
uint16_t Count_in_TypedCommandHeader_for_AnalogOutputInt32_override(void *pICollection_for_CommandState)
{
  TypedCommandHeader_for_AnalogOutputInt32 *parent = (TypedCommandHeader_for_AnalogOutputInt32*)getParentPointer_in_ICollection_for_CommandState((ICollection_for_CommandState*) pICollection_for_CommandState);
  return Count_in_TypedCommandHeader_for_AnalogOutputInt32(parent);
}

////template<class T> void TypedCommandHeader<T>::Foreach(IVisitor<CommandState>& visitor) const
void Foreach_in_TypedCommandHeader_for_AnalogOutputInt32(TypedCommandHeader_for_AnalogOutputInt32 *pTypedCommandHeader_for_AnalogOutputInt32,
    IVisitor__for__CommandState* visitor)
{
  for (auto& rec : pTypedCommandHeader_for_AnalogOutputInt32->records)
  {
//void OnValue_in_IVisitor__for__CommandState(IVisitor__for__CommandState *, CommandState* );
////        visitor.OnValue(rec);
    OnValue_in_IVisitor__for__CommandState(visitor, &rec.cCommandState );
  }
}
void Foreach_in_TypedCommandHeader_for_AnalogOutputInt32_override(void *pICollection_for_CommandState, IVisitor__for__CommandState* visitor)
{
  TypedCommandHeader_for_AnalogOutputInt32 *parent = (TypedCommandHeader_for_AnalogOutputInt32*)getParentPointer_in_ICollection_for_CommandState((ICollection_for_CommandState*) pICollection_for_CommandState);
  return Foreach_in_TypedCommandHeader_for_AnalogOutputInt32(parent, visitor);
}
//------------------------AnalogOutputInt32----------------------------
