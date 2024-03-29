/*
 * Copyright 2013-2022 Step Function I/O, LLC
 *
 * Licensed to Green Energy Corp (www.greenenergycorp.com) and Step Function I/O
 * LLC (https://stepfunc.io) under one or more contributor license agreements.
 * See the NOTICE file distributed with this work for additional information
 * regarding copyright ownership. Green Energy Corp and Step Function I/O LLC license
 * this file to you under the Apache License, Version 2.0 (the "License"); you
 * may not use this file except in compliance with the License. You may obtain
 * a copy of the License at:
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
//#include <QtWidgets>
#include "header.h"
#include "HeaderWriter.h"

#include "SerializationTemplates.h"
////#include <ser4cpp/serialization/LittleEndian.h>

////#include <cassert>

////namespace opendnp3
////{

void HeaderWriter_in_HeaderWriter(HeaderWriter *pHeaderWriter, WSeq_for_Uint16_t* position_)
{
//// : position(position_) {}
  pHeaderWriter->position = position_;
}

uint16_t Remaining_in_HeaderWriter(HeaderWriter *pHeaderWriter)
{
//    return position->length();
  return  length_in_HasLength_for_Uint16_t(&(pHeaderWriter->position->hHasLength));
}

void Mark_in_HeaderWriter(HeaderWriter *pHeaderWriter)
{
////    mark.set(*position);
//    void set_in_Settable_for_WSeq_t(Settable_for_WSeq_t *pSettable_for_WSeq_t, WSeq_for_Uint16_t *value_);
  set_in_Settable_for_WSeq_t(&(pHeaderWriter->mark), pHeaderWriter->position);
}

boolean Rollback_in_HeaderWriter(HeaderWriter *pHeaderWriter)
{
//    boolean is_set_in_Settable_for_WSeq_t(Settable_for_WSeq_t *pSettable_for_WSeq_t);
////    if (mark.is_set())
  if(is_set_in_Settable_for_WSeq_t(&(pHeaderWriter->mark)))
  {
////        *position = mark.get();
//    WSeq_for_Uint16_t get_in_Settable_for_WSeq_t(Settable_for_WSeq_t *pSettable_for_WSeq_t);
    WSeq_for_Uint16_t temp1 = get_in_Settable_for_WSeq_t(&(pHeaderWriter->mark));
    *(pHeaderWriter->position)  = temp1;

////        mark.clear();
//    void clear_in_Settable_for_WSeq_t(Settable_for_WSeq_t *pSettable_for_WSeq_t);
    clear_in_Settable_for_WSeq_t(&(pHeaderWriter->mark));
    return true;
  }

  return false;
}

boolean WriteHeader_in_HeaderWriter(HeaderWriter *pHeaderWriter, GroupVariationID id, QualifierCode_uint8_t qc)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"WriteHeader_in_HeaderWriter1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*id.group= "<<(uint16_t)id.group<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*id.variation= "<<(uint16_t)id.variation<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*qc= "<<(uint16_t)qc<<'\n';
#endif
////    if (position->length() < 3)
  if(length_in_HasLength_for_Uint16_t(&(pHeaderWriter->position->hHasLength)) < 3)
  {
#ifdef  LOG_INFO
    decrement_stack_info();
#endif
    return false;
  }

////    ser4cpp::UInt8::write_to(*position, id.group);
  write_to_in_UInt8_static((pHeaderWriter->position), id.group);

////    ser4cpp::UInt8::write_to(*position, id.variation);
  write_to_in_UInt8_static((pHeaderWriter->position), id.variation);

////    ser4cpp::UInt8::write_to(*position, QualifierCodeSpec::to_type(qc));
  write_to_in_UInt8_static((pHeaderWriter->position), qc);

#ifdef  LOG_INFO
  decrement_stack_info();
#endif
  return true;
}

boolean WriteHeaderWithReserve_in_HeaderWriter(HeaderWriter *pHeaderWriter, GroupVariationID id, QualifierCode_uint8_t qc, uint16_t reserve)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"WriteHeaderWithReserve_in_HeaderWriter1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*qc= "<<(uint16_t)qc<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*reserve= "<<(uint16_t)reserve<<'\n';
  decrement_stack_info();
#endif
////    return (position->length() < (3 + reserve)) ? false : WriteHeader(id, qc);
  return (length_in_HasLength_for_Uint16_t(&(pHeaderWriter->position->hHasLength)) <
          (3 + reserve)) ? false : WriteHeader_in_HeaderWriter(pHeaderWriter, id, qc);
}
/*
////template<class IndexType>
////BitfieldRangeWriteIterator<IndexType> HeaderWriter::IterateOverSingleBitfield(GroupVariationID id,
////                                                                              QualifierCode qc,
////                                                                              typename IndexType::type_t start)
BitfieldRangeWriteIterator_for_UInt8 IterateOverSingleBitfield_for_UInt8_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    GroupVariationID id,
    QualifierCode_uint8_t qc,
    uint8_t start)
{
////    const auto reserve_size = 2 * IndexType::size + 1; // need at least 1 byte
  uint16_t reserve_size = 2 * size_in_UInt8 + 1; // need at least 1 byte
//    boolean WriteHeaderWithReserve_in_HeaderWriter(HeaderWriter *pHeaderWriter,
//                                       GroupVariationID id, QualifierCode_uint8_t qc, uint16_t reserve);
////    if (this->WriteHeaderWithReserve(id, qc, reserve_size))
  if (WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter,
      id, qc, reserve_size))
  {
//  void  BitfieldRangeWriteIterator_for_UInt8_in_BitfieldRangeWriteIterator_for_UInt8(BitfieldRangeWriteIterator_for_UInt8 *pBitfieldRangeWriteIterator_for_UInt8,
//                                                   uint8_t start_, WSeq_for_Uint16_t* position_)
////        return BitfieldRangeWriteIterator<IndexType>(start, *position);
    BitfieldRangeWriteIterator_for_UInt8 bBitfieldRangeWriteIterator_for_UInt8;
    BitfieldRangeWriteIterator_for_UInt8_in_BitfieldRangeWriteIterator_for_UInt8(&bBitfieldRangeWriteIterator_for_UInt8,
        start, pHeaderWriter->position);
    return bBitfieldRangeWriteIterator_for_UInt8;
  }
  else
//    BitfieldRangeWriteIterator_for_UInt8 Null_in_BitfieldRangeWriteIterator_for_UInt8_static(void)
////        return BitfieldRangeWriteIterator<IndexType>::Null();
    return  Null_in_BitfieldRangeWriteIterator_for_UInt8_static();
}
*/
//================================================WriteSingleValue=================================================================
//--------------------------------WriteSingleValue_for_UInt8_Group51Var1--------------------------------------------------------
boolean WriteSingleValue_for_UInt8_Group51Var1_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc, Group51Var1* cto)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"WriteSingleValue_for_UInt8_Group51Var1_in_HeaderWriter1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*QualifierCode_uint8_t qc= "<<(uint16_t)qc<<'\n';
#endif

////template<class CountType, class WriteType> bool HeaderWriter::WriteSingleValue(QualifierCode qc, const WriteType& value)
  {
//    const auto reserve_size = CountType::size + WriteType::Size();
//  uint16_t Size_in_Group51Var1_static(void);
    uint16_t reserve_size = size_in_UInt8 + Size_in_Group51Var1_static();
//  GroupVariationID ID_in_Group51Var1_static(void);
////    if (this->WriteHeaderWithReserve(WriteType::ID(), qc, reserve_size))
    if(WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter,
        ID_in_Group51Var1_static(), qc, reserve_size))
    {
////        CountType::write_to(*position, 1); // write the count
      write_to_in_UInt8_static(pHeaderWriter->position, 1);
//        WriteType::Write(value, *position);
      Write_in_Group51Var1_static(cto, pHeaderWriter->position);
#ifdef  LOG_INFO
      decrement_stack_info();
#endif
      return true;
    }
    else
    {
#ifdef  LOG_INFO
      decrement_stack_info();
#endif
      return false;
    }
  }
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
}
//--------------------------------WriteSingleValue_for_UInt8_Group51Var1--------------------------------------------------------
//--------------------------------WriteSingleValue_for_UInt8_Group51Var2--------------------------------------------------------
boolean WriteSingleValue_for_UInt8_Group51Var2_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc, Group51Var2* cto)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"WriteSingleValue_for_UInt8_Group51Var2_in_HeaderWriter1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*QualifierCode_uint8_t qc= "<<(uint16_t)qc<<'\n';
#endif
////template<class CountType, class WriteType> bool HeaderWriter::WriteSingleValue(QualifierCode qc, const WriteType& value)
  {
//    const auto reserve_size = CountType::size + WriteType::Size();
//  uint16_t Size_in_Group51Var2_static(void);
    uint16_t reserve_size = size_in_UInt8 + Size_in_Group51Var2_static();
//  GroupVariationID ID_in_Group51Var2_static(void);
////    if (this->WriteHeaderWithReserve(WriteType::ID(), qc, reserve_size))
    if(WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter,
        ID_in_Group51Var2_static(), qc, reserve_size))
    {
////        CountType::write_to(*position, 1); // write the count
      write_to_in_UInt8_static(pHeaderWriter->position, 1);
//        WriteType::Write(value, *position);
      Write_in_Group51Var2_static(cto, pHeaderWriter->position);
#ifdef  LOG_INFO
      decrement_stack_info();
#endif
      return true;
    }
    else
    {
#ifdef  LOG_INFO
      decrement_stack_info();
#endif
      return false;
    }
  }
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
}
//--------------------------------WriteSingleValue_for_UInt8_Group51Var2--------------------------------------------------------

//--------------------------------WriteSingleValue_for_UInt8_Group52Var1--------------------------------------------------------
boolean WriteSingleValue_for_UInt8_Group52Var1_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc, Group52Var1* cto)
{
////template<class CountType, class WriteType> bool HeaderWriter::WriteSingleValue(QualifierCode qc, const WriteType& value)
  {
#ifdef  LOG_INFO
    std::cout<<'\n';
    increment_stack_info();
    std::cout<<getString_stack_info();
    std::cout<<"WriteSingleValue_for_UInt8_Group52Var1_in_HeaderWriter1"<<'\n';
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*QualifierCode_uint8_t qc= "<<(uint16_t)qc<<'\n';
#endif
//    const auto reserve_size = CountType::size + WriteType::Size();
//  uint16_t Size_in_Group52Var1_static(void);
    uint16_t reserve_size = size_in_UInt8 + Size_in_Group52Var1_static();
//  GroupVariationID ID_in_Group52Var1_static(void);
////    if (this->WriteHeaderWithReserve(WriteType::ID(), qc, reserve_size))
    if(WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter,
        ID_in_Group52Var1_static(), qc, reserve_size))
    {
////        CountType::write_to(*position, 1); // write the count
      write_to_in_UInt8_static(pHeaderWriter->position, 1);
//        WriteType::Write(value, *position);
      Write_in_Group52Var1_static(cto, pHeaderWriter->position);
#ifdef  LOG_INFO
      decrement_stack_info();
#endif
      return true;
    }
    else
    {
#ifdef  LOG_INFO
      decrement_stack_info();
#endif
      return false;
    }
  }
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
}
//--------------------------------WriteSingleValue_for_UInt8_Group52Var1--------------------------------------------------------
//--------------------------------WriteSingleValue_for_UInt8_Group52Var2--------------------------------------------------------
boolean WriteSingleValue_for_UInt8_Group52Var2_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc, Group52Var2* cto)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"WriteSingleValue_for_UInt8_Group52Var2_in_HeaderWriter1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*QualifierCode_uint8_t qc= "<<(uint16_t)qc<<'\n';
#endif
////template<class CountType, class WriteType> bool HeaderWriter::WriteSingleValue(QualifierCode qc, const WriteType& value)
  {
//    const auto reserve_size = CountType::size + WriteType::Size();
//  uint16_t Size_in_Group52Var2_static(void);
    uint16_t reserve_size = size_in_UInt8 + Size_in_Group52Var2_static();
//  GroupVariationID ID_in_Group52Var2_static(void);
////    if (this->WriteHeaderWithReserve(WriteType::ID(), qc, reserve_size))
    if(WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter,
        ID_in_Group52Var2_static(), qc, reserve_size))
    {
////        CountType::write_to(*position, 1); // write the count
      write_to_in_UInt8_static(pHeaderWriter->position, 1);
//        WriteType::Write(value, *position);
      Write_in_Group52Var2_static(cto, pHeaderWriter->position);
#ifdef  LOG_INFO
      decrement_stack_info();
#endif
      return true;
    }
    else
    {
#ifdef  LOG_INFO
      decrement_stack_info();
#endif
      return false;
    }
  }
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
}
//--------------------------------WriteSingleValue_for_UInt8_Group52Var2--------------------------------------------------------

//--------------------------------WriteSingleValue_for_UInt8_Group50Var1--------------------------------------------------------
boolean WriteSingleValue_for_UInt8_Group50Var1_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc, Group50Var1* cto)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"WriteSingleValue_for_UInt8_Group50Var1_in_HeaderWriter1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*QualifierCode_uint8_t qc= "<<(uint16_t)qc<<'\n';
#endif
////template<class CountType, class WriteType> bool HeaderWriter::WriteSingleValue(QualifierCode qc, const WriteType& value)
  {
//    const auto reserve_size = CountType::size + WriteType::Size();
    uint16_t reserve_size = size_in_UInt8 + Size_in_Group50Var1_static();
////    if (this->WriteHeaderWithReserve(WriteType::ID(), qc, reserve_size))
    if(WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter,
        ID_in_Group50Var1_static(), qc, reserve_size))
    {
////        CountType::write_to(*position, 1); // write the count
      write_to_in_UInt8_static(pHeaderWriter->position, 1);
//        WriteType::Write(value, *position);
      Write_in_Group50Var1_static(cto, pHeaderWriter->position);
#ifdef  LOG_INFO
      decrement_stack_info();
#endif
      return true;
    }
    else
    {
#ifdef  LOG_INFO
      decrement_stack_info();
#endif
      return false;
    }
  }
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
}
//--------------------------------WriteSingleValue_for_UInt8_Group50Var1--------------------------------------------------------
//--------------------------------WriteSingleValue_for_UInt8_Group50Var3--------------------------------------------------------
boolean WriteSingleValue_for_UInt8_Group50Var3_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc, Group50Var3* cto)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"WriteSingleValue_for_UInt8_Group50Var3_in_HeaderWriter1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*QualifierCode_uint8_t qc= "<<(uint16_t)qc<<'\n';
#endif
////template<class CountType, class WriteType> bool HeaderWriter::WriteSingleValue(QualifierCode qc, const WriteType& value)
  {
//    const auto reserve_size = CountType::size + WriteType::Size();
    uint16_t reserve_size = size_in_UInt8 + Size_in_Group50Var3_static();
////    if (this->WriteHeaderWithReserve(WriteType::ID(), qc, reserve_size))
    if(WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter,
        ID_in_Group50Var3_static(), qc, reserve_size))
    {
////        CountType::write_to(*position, 1); // write the count
      write_to_in_UInt8_static(pHeaderWriter->position, 1);
//        WriteType::Write(value, *position);
      Write_in_Group50Var3_static(cto, pHeaderWriter->position);
#ifdef  LOG_INFO
      decrement_stack_info();
#endif
      return true;
    }
    else
    {
#ifdef  LOG_INFO
      decrement_stack_info();
#endif
      return false;
    }
  }
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
}
//--------------------------------WriteSingleValue_for_UInt8_Group50Var3--------------------------------------------------------

//--------------------------------IterateOverSingleBitfield_for_uint8--------------------------------------------------------

BitfieldRangeWriteIterator_for_UInt8 IterateOverSingleBitfield_for_UInt8_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    GroupVariationID id,
    QualifierCode_uint8_t qc,
    uint8_t start)
{
////    const auto reserve_size = 2 * IndexType::size + 1; // need at least 1 byte
  uint16_t reserve_size = 2* size_in_UInt8 + 1;
//boolean WriteHeaderWithReserve_in_HeaderWriter(HeaderWriter *pHeaderWriter,
//    GroupVariationID id, QualifierCode_uint8_t qc, uint16_t reserve);
////    if (this->WriteHeaderWithReserve(id, qc, reserve_size))
  if (WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter, id, qc, reserve_size))
  {
////        return BitfieldRangeWriteIterator<IndexType>(start, *position);
    BitfieldRangeWriteIterator_for_UInt8 bBitfieldRangeWriteIterator_for_UInt8;
    BitfieldRangeWriteIterator_for_UInt8_in_BitfieldRangeWriteIterator_for_UInt8(&bBitfieldRangeWriteIterator_for_UInt8,
        start, pHeaderWriter->position);
    return bBitfieldRangeWriteIterator_for_UInt8;
  }
  else
//    BitfieldRangeWriteIterator_for_UInt8 Null_in_BitfieldRangeWriteIterator_for_UInt8_static(void)
////        return BitfieldRangeWriteIterator<IndexType>::Null();
    return  Null_in_BitfieldRangeWriteIterator_for_UInt8_static();
}
//--------------------------------IterateOverSingleBitfield_for_uint8--------------------------------------------------------
//--------------------------------IterateOverSingleBitfield_for_uint16--------------------------------------------------------

BitfieldRangeWriteIterator_for_UInt16 IterateOverSingleBitfield_for_UInt16_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    GroupVariationID id,
    QualifierCode_uint8_t qc,
    uint16_t start)
{
////    const auto reserve_size = 2 * IndexType::size + 1; // need at least 1 byte
  uint16_t reserve_size = 2* size_in_UInt16 + 1;
//boolean WriteHeaderWithReserve_in_HeaderWriter(HeaderWriter *pHeaderWriter,
//    GroupVariationID id, QualifierCode_uint8_t qc, uint16_t reserve);
////    if (this->WriteHeaderWithReserve(id, qc, reserve_size))
  if (WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter, id, qc, reserve_size))
  {
////        return BitfieldRangeWriteIterator<IndexType>(start, *position);
    BitfieldRangeWriteIterator_for_UInt16 bBitfieldRangeWriteIterator_for_UInt16;
    BitfieldRangeWriteIterator_for_UInt16_in_BitfieldRangeWriteIterator_for_UInt16(&bBitfieldRangeWriteIterator_for_UInt16,
        start, pHeaderWriter->position);
    return bBitfieldRangeWriteIterator_for_UInt16;
  }
  else
//    BitfieldRangeWriteIterator_for_UInt8 Null_in_BitfieldRangeWriteIterator_for_UInt8_static(void)
////        return BitfieldRangeWriteIterator<IndexType>::Null();
    return  Null_in_BitfieldRangeWriteIterator_for_UInt16_static();
}
//--------------------------------IterateOverSingleBitfield_for_uint16--------------------------------------------------------
boolean WriteRangeHeader_for_UInt8_in_HeaderWriter(HeaderWriter *pHeaderWriter, QualifierCode_uint8_t qc,
    GroupVariationID gvId,
    int8_t start,
    int8_t stop)
{
//boolean WriteHeaderWithReserve_in_HeaderWriter(HeaderWriter *pHeaderWriter,
//    GroupVariationID id, QualifierCode_uint8_t qc, uint16_t reserve);
////    if (WriteHeaderWithReserve(gvId, qc, 2 * IndexType::size))
  if (WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter, gvId, qc, 2 * size_in_UInt8))
  {
////        IndexType::write_to(*position, start);
    write_to_in_UInt8_static(pHeaderWriter->position, start);
////        IndexType::write_to(*position, stop);
    write_to_in_UInt8_static(pHeaderWriter->position, stop);
    return true;
  }
  else
  {
    return false;
  }
}
boolean WriteRangeHeader_for_UInt16_in_HeaderWriter(HeaderWriter *pHeaderWriter, QualifierCode_uint8_t qc,
    GroupVariationID gvId,
    int16_t start,
    int16_t stop)
{
//boolean WriteHeaderWithReserve_in_HeaderWriter(HeaderWriter *pHeaderWriter,
//    GroupVariationID id, QualifierCode_uint8_t qc, uint16_t reserve);
////    if (WriteHeaderWithReserve(gvId, qc, 2 * IndexType::size))
  if (WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter, gvId, qc, 2 * size_in_UInt16))
  {
////        IndexType::write_to(*position, start);
    write_to_in_UInt16_static(pHeaderWriter->position, start);
////        IndexType::write_to(*position, stop);
    write_to_in_UInt16_static(pHeaderWriter->position, stop);
    return true;
  }
  else
  {
    return false;
  }
}

boolean WriteCountHeader_for_UInt8_in_HeaderWriter(HeaderWriter *pHeaderWriter, QualifierCode_uint8_t qc,
    GroupVariationID gvId, uint8_t count)
{
////    if (WriteHeaderWithReserve(gvId, qc, IndexType::size))
  if (WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter, gvId, qc, size_in_UInt8))
  {
////        IndexType::write_to(*position, count);
    write_to_in_UInt8_static(pHeaderWriter->position, count);
    return true;
  }
  else
  {
    return false;
  }
}
boolean WriteCountHeader_for_UInt16_in_HeaderWriter(HeaderWriter *pHeaderWriter, QualifierCode_uint8_t qc,
    GroupVariationID gvId, uint16_t count)
{
////    if (WriteHeaderWithReserve(gvId, qc, IndexType::size))
  if (WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter, gvId, qc, size_in_UInt16))
  {
////        IndexType::write_to(*position, count);
    write_to_in_UInt16_static(pHeaderWriter->position, count);
    return true;
  }
  else
  {
    return false;
  }
}



////} // namespace opendnp3
