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
////    if (position->length() < 3)
//    uint16_t temp1 = length_in_HasLength_for_Uint16_t(&((pHeaderWriter->position).hHasLength));
    uint16_t temp1 = length_in_HasLength_for_Uint16_t(&(pHeaderWriter->position->hHasLength));
    if(temp1 < 3)
    {
        return false;
    }

////    ser4cpp::UInt8::write_to(*position, id.group);
    write_to_in_UInt8_static((pHeaderWriter->position), id.group);
////    ser4cpp::UInt8::write_to(*position, id.variation);
    write_to_in_UInt8_static((pHeaderWriter->position), id.variation);
////    ser4cpp::UInt8::write_to(*position, QualifierCodeSpec::to_type(qc));
    write_to_in_UInt8_static((pHeaderWriter->position), qc);
    return true;
}

boolean WriteHeaderWithReserve_in_HeaderWriter(HeaderWriter *pHeaderWriter, GroupVariationID id, QualifierCode_uint8_t qc, uint16_t reserve)
{
////    return (position->length() < (3 + reserve)) ? false : WriteHeader(id, qc);
//    uint16_t temp1 = length_in_HasLength_for_Uint16_t(&((pHeaderWriter->position).hHasLength));
    uint16_t temp1 = length_in_HasLength_for_Uint16_t(&(pHeaderWriter->position->hHasLength));
    return (temp1 < (3 + reserve)) ? false : WriteHeader_in_HeaderWriter(pHeaderWriter, id, qc);
}

//================================================WriteSingleValue=================================================================
//--------------------------------WriteSingleValue_for_UInt8_Group51Var1--------------------------------------------------------
    boolean WriteSingleValue_for_UInt8_Group51Var1_in_HeaderWriter(HeaderWriter *pHeaderWriter, 
                                                                    QualifierCode_uint8_t qc, Group51Var1* cto)
{
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
        return true;
    }
    else
    {
        return false;
    }
}
}
//--------------------------------WriteSingleValue_for_UInt8_Group51Var1--------------------------------------------------------
//--------------------------------WriteSingleValue_for_UInt8_Group50Var1--------------------------------------------------------
    boolean WriteSingleValue_for_UInt8_Group50Var1_in_HeaderWriter(HeaderWriter *pHeaderWriter, 
                                                                    QualifierCode_uint8_t qc, Group50Var1* cto)
{
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
        return true;
    }
    else
    {
        return false;
    }
}
}
//--------------------------------WriteSingleValue_for_UInt8_Group50Var1--------------------------------------------------------
//================================================WriteSingleValue=================================================================
//================================================IterateOverRange=================================================================
//---------------------------------------------IterateOverRange_for_UInt8_Binary_in_HeaderWriter--------------------------------------------
////template<class IndexType, class WriteType>
////RangeWriteIterator<IndexType, WriteType> HeaderWriter::IterateOverRange(QualifierCode qc,
////                                                                        const DNP3Serializer<WriteType>& serializer,
////                                                                        typename IndexType::type_t start)
    RangeWriteIterator_for_UInt8_Binary IterateOverRange_for_UInt8_Binary_in_HeaderWriter(HeaderWriter *pHeaderWriter, 
                                                   QualifierCode_uint8_t qc,
                                                   DNP3Serializer_for_Binary *serializer,
                                                   uint8_t start
                                                  )
{
//    const auto reserve_size = 2 * IndexType::size + serializer.get_size();
//     pRangeWriteIterator_for_UInt8_Binary->isValid = length_in_HasLength_for_Uint16_t(&(position->hHasLength)) >= 2 * size_in_UInt8;
       uint16_t reserve_size = 2 * size_in_UInt8 +
        get_size_in_Serializer_for_Binary(&(serializer->sSerializer_for_Binary));

//    if (this->WriteHeaderWithReserve(serializer.ID(), qc, reserve_size))
//boolean WriteHeaderWithReserve_in_HeaderWriter(HeaderWriter *pHeaderWriter, GroupVariationID id, QualifierCode_uint8_t qc, uint16_t reserve)
//    GroupVariationID ID_in_DNP3Serializer_for_Binary(DNP3Serializer_for_Binary *pDNP3Serializer_for_Binary) 
    if(WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter, ID_in_DNP3Serializer_for_Binary(serializer), qc, reserve_size))
    {
//        return RangeWriteIterator<IndexType, WriteType>(start, serializer, *position);
       RangeWriteIterator_for_UInt8_Binary rRangeWriteIterator_for_UInt8_Binary;
////    void RangeWriteIterator_for_UInt8_Binary_in_RangeWriteIterator_for_UInt8_BinaryOver2(RangeWriteIterator_for_UInt8_Binary *pRangeWriteIterator_for_UInt8_Binary,
//                   typename IndexType::type_t start_,
////                   uint8_t start_,
//                   const Serializer<WriteType>& serializer,
////                   Serializer_for_Binary*  serializer,
//                   ser4cpp::wseq_t& position)
////                   WSeq_for_Uint16_t* position);
       RangeWriteIterator_for_UInt8_Binary_in_RangeWriteIterator_for_UInt8_BinaryOver2(&rRangeWriteIterator_for_UInt8_Binary,
                                        start,
                                        &(serializer->sSerializer_for_Binary),
                                        pHeaderWriter->position
                                       );
       return rRangeWriteIterator_for_UInt8_Binary;
    }
    else
    {
//        return RangeWriteIterator<IndexType, WriteType>::Null();
       return Null_in_RangeWriteIterator_for_UInt8_Binary_static();
    }
}
//---------------------------------------------IterateOverRange_for_UInt8_Binary_in_HeaderWriter--------------------------------------------
//---------------------------------------------IterateOverRange_for_UInt8_Counter_in_HeaderWriter--------------------------------------------
    RangeWriteIterator_for_UInt8_Counter IterateOverRange_for_UInt8_Counter_in_HeaderWriter(HeaderWriter *pHeaderWriter, 
                                                   QualifierCode_uint8_t qc,
                                                   DNP3Serializer_for_Counter *serializer,
                                                   uint8_t start
                                                  )
{
//    const auto reserve_size = 2 * IndexType::size + serializer.get_size();
//     pRangeWriteIterator_for_UInt8_Binary->isValid = length_in_HasLength_for_Uint16_t(&(position->hHasLength)) >= 2 * size_in_UInt8;
       uint16_t reserve_size = 2 * size_in_UInt8 +
        get_size_in_Serializer_for_Counter(&(serializer->sSerializer_for_Counter));

//    if (this->WriteHeaderWithReserve(serializer.ID(), qc, reserve_size))
//boolean WriteHeaderWithReserve_in_HeaderWriter(HeaderWriter *pHeaderWriter, GroupVariationID id, QualifierCode_uint8_t qc, uint16_t reserve)
//    GroupVariationID ID_in_DNP3Serializer_for_Binary(DNP3Serializer_for_Binary *pDNP3Serializer_for_Binary) 
    if(WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter, ID_in_DNP3Serializer_for_Counter(serializer), qc, reserve_size))
    {
//        return RangeWriteIterator<IndexType, WriteType>(start, serializer, *position);
       RangeWriteIterator_for_UInt8_Counter rRangeWriteIterator_for_UInt8_Counter;
////    void RangeWriteIterator_for_UInt8_Binary_in_RangeWriteIterator_for_UInt8_BinaryOver2(RangeWriteIterator_for_UInt8_Binary *pRangeWriteIterator_for_UInt8_Binary,
//                   typename IndexType::type_t start_,
////                   uint8_t start_,
//                   const Serializer<WriteType>& serializer,
////                   Serializer_for_Binary*  serializer,
//                   ser4cpp::wseq_t& position)
////                   WSeq_for_Uint16_t* position);
       RangeWriteIterator_for_UInt8_Counter_in_RangeWriteIterator_for_UInt8_CounterOver2(&rRangeWriteIterator_for_UInt8_Counter,
                                        start,
                                        &(serializer->sSerializer_for_Counter),
                                        pHeaderWriter->position
                                       );
       return rRangeWriteIterator_for_UInt8_Counter;
    }
    else
    {
//        return RangeWriteIterator<IndexType, WriteType>::Null();
       return Null_in_RangeWriteIterator_for_UInt8_Counter_static();
    }
}
//---------------------------------------------IterateOverRange_for_UInt8_Counter_in_HeaderWriter--------------------------------------------
//================================================IterateOverRange=================================================================
//================================================IterateOverCount=================================================================
//---------------------------------------------IterateOverCount_for_UInt8_Binary_in_HeaderWriter--------------------------------------------

    CountWriteIterator_for_UInt8_Binary IterateOverCount_for_UInt8_Binary_in_HeaderWriter(HeaderWriter *pHeaderWriter,
                                                              QualifierCode_uint8_t qc,
                                                              DNP3Serializer_for_Binary* serializer)
{
////template<class CountType, class WriteType>
////CountWriteIterator<CountType, WriteType> HeaderWriter::IterateOverCount(QualifierCode qc,
////                                                                        const DNP3Serializer<WriteType>& serializer)
////{
////   uint16_t reserve_size = CountType::size + serializer.get_size();
   uint16_t reserve_size = size_in_UInt8 + 
        get_size_in_Serializer_for_Binary(&(serializer->sSerializer_for_Binary));
////    if (this->WriteHeaderWithReserve(serializer.ID(), qc, reserve_size))
    if(WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter, ID_in_DNP3Serializer_for_Binary(serializer), qc, reserve_size))
    {
////        return CountWriteIterator<CountType, WriteType>(serializer, *position);
      CountWriteIterator_for_UInt8_Binary cCountWriteIterator_for_UInt8_Binary;
      CountWriteIterator_for_UInt8_Binary_in_CountWriteIterator_for_UInt8_BinaryOver2(&cCountWriteIterator_for_UInt8_Binary,
                                        &(serializer->sSerializer_for_Binary),
                                        pHeaderWriter->position
                                       );
      return cCountWriteIterator_for_UInt8_Binary;
    }
    else
    {
////        return CountWriteIterator<CountType, WriteType>::Null();
       return Null_in_CountWriteIterator_for_UInt8_Binary_static();
    }
////}
}
//---------------------------------------------IterateOverCount_for_UInt8_Binary_in_HeaderWriter--------------------------------------------
//---------------------------------------------IterateOverCount_for_UInt16_Analog_in_HeaderWriter--------------------------------------------

    CountWriteIterator_for_UInt16_Analog IterateOverCount_for_UInt16_Analog_in_HeaderWriter(HeaderWriter *pHeaderWriter, 
                                                              QualifierCode_uint8_t qc,
                                                              DNP3Serializer_for_Analog* serializer)
{
////template<class CountType, class WriteType>
////CountWriteIterator<CountType, WriteType> HeaderWriter::IterateOverCount(QualifierCode qc,
////                                                                        const DNP3Serializer<WriteType>& serializer)
////{
////   uint16_t reserve_size = CountType::size + serializer.get_size();
   uint16_t reserve_size = size_in_UInt16 + 
        get_size_in_Serializer_for_Analog(&(serializer->sSerializer_for_Analog));
////    if (this->WriteHeaderWithReserve(serializer.ID(), qc, reserve_size))
    if(WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter, ID_in_DNP3Serializer_for_Analog(serializer), qc, reserve_size))
    {
////        return CountWriteIterator<CountType, WriteType>(serializer, *position);
      CountWriteIterator_for_UInt16_Analog cCountWriteIterator_for_UInt16_Analog;
      CountWriteIterator_for_UInt16_Analog_in_CountWriteIterator_for_UInt16_AnalogOver2(&cCountWriteIterator_for_UInt16_Analog,
                                        &(serializer->sSerializer_for_Analog),
                                        pHeaderWriter->position
                                       );
      return cCountWriteIterator_for_UInt16_Analog;
    }
    else
    {
////        return CountWriteIterator<CountType, WriteType>::Null();
       return Null_in_CountWriteIterator_for_UInt16_Analog_static();
    }
////}
}
//---------------------------------------------IterateOverCount_for_UInt16_Analog_in_HeaderWriter--------------------------------------------
//---------------------------------------------IterateOverCount_for_UInt8_Analog_in_HeaderWriter--------------------------------------------

    CountWriteIterator_for_UInt8_Analog IterateOverCount_for_UInt8_Analog_in_HeaderWriter(HeaderWriter *pHeaderWriter, 
                                                              QualifierCode_uint8_t qc,
                                                              DNP3Serializer_for_Analog* serializer)
{
////template<class CountType, class WriteType>
////CountWriteIterator<CountType, WriteType> HeaderWriter::IterateOverCount(QualifierCode qc,
////                                                                        const DNP3Serializer<WriteType>& serializer)
////{
////   uint16_t reserve_size = CountType::size + serializer.get_size();
   uint16_t reserve_size = size_in_UInt8 + 
        get_size_in_Serializer_for_Analog(&(serializer->sSerializer_for_Analog));
////    if (this->WriteHeaderWithReserve(serializer.ID(), qc, reserve_size))
    if(WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter, ID_in_DNP3Serializer_for_Analog(serializer), qc, reserve_size))
    {
////        return CountWriteIterator<CountType, WriteType>(serializer, *position);
      CountWriteIterator_for_UInt8_Analog cCountWriteIterator_for_UInt8_Analog;
      CountWriteIterator_for_UInt8_Analog_in_CountWriteIterator_for_UInt8_AnalogOver2(&cCountWriteIterator_for_UInt8_Analog,
                                        &(serializer->sSerializer_for_Analog),
                                        pHeaderWriter->position
                                       );
      return cCountWriteIterator_for_UInt8_Analog;
    }
    else
    {
////        return CountWriteIterator<CountType, WriteType>::Null();
       return Null_in_CountWriteIterator_for_UInt8_Analog_static();
    }
////}
}
//---------------------------------------------IterateOverCount_for_UInt8_Analog_in_HeaderWriter--------------------------------------------
//------------------------------IterateOverCountWithPrefixAndCTO_for_UInt16_Binary_Group51Var1_in_HeaderWriter--------------------------------------------------------
////template<class PrefixType, class WriteType, class CTOType>
////PrefixedWriteIterator<PrefixType, WriteType> HeaderWriter::IterateOverCountWithPrefixAndCTO(
////    QualifierCode qc, const DNP3Serializer<WriteType>& serializer, const CTOType& cto)
    PrefixedWriteIterator_for_UInt16_Binary IterateOverCountWithPrefixAndCTO_for_UInt16_Binary_Group51Var1_in_HeaderWriter(HeaderWriter *pHeaderWriter,
                                                              QualifierCode_uint8_t qc,
                                                              DNP3Serializer_for_Binary* serializer,
                                                              Group51Var1* cto)
{
////    this->Mark();
    Mark_in_HeaderWriter(pHeaderWriter);
////    if (this->WriteSingleValue<ser4cpp::UInt8, CTOType>(QualifierCode::UINT8_CNT, cto))
    if(WriteSingleValue_for_UInt8_Group51Var1_in_HeaderWriter(pHeaderWriter, QualifierCode_UINT8_CNT, cto))
    {
////        auto iter = IterateOverCountWithPrefix<PrefixType, WriteType>(qc, serializer);
        PrefixedWriteIterator_for_UInt16_Binary iter = 
                        IterateOverCountWithPrefix_for_UInt16_Binary_in_HeaderWriter(pHeaderWriter, qc, serializer);
////        if (!iter.IsValid())
        if (!IsValid_in_PrefixedWriteIterator_for_UInt16_Binary(&iter))
        {
            // remove the CTO header, if there's no space to write a value
////            this->Rollback();
          Rollback_in_HeaderWriter(pHeaderWriter);
        }
        return iter;
    }
    else
    {
////        return PrefixedWriteIterator<PrefixType, WriteType>::Null();
     return Null_in_PrefixedWriteIterator_for_UInt16_Binary_static();
    }
}
//--------------------------------IterateOverCountWithPrefixAndCTO_for_UInt16_Binary_Group51Var1_in_HeaderWriter--------------------------------------------------------
  PrefixedWriteIterator_for_UInt16_Binary IterateOverCountWithPrefix_for_UInt16_Binary_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc, DNP3Serializer_for_Binary* serializer)
{
////    const auto reserve_size
      uint16_t reserve_size =
////        = 2 * PrefixType::size + serializer.get_size(); // enough space for the count, 1 prefix + object
            2*size_in_UInt16 +
              get_size_in_Serializer_for_Binary(&(serializer->sSerializer_for_Binary));//Serializer_for_Binary *pSerializer_for_Binary);
////    if (this->WriteHeaderWithReserve(serializer.ID(), qc, reserve_size))
 if(WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter,
                     ID_in_DNP3Serializer_for_Binary(serializer), qc, reserve_size))
    {
         PrefixedWriteIterator_for_UInt16_Binary pPrefixedWriteIterator_for_UInt16_Binary;
         PrefixedWriteIterator_for_UInt16_Binary_in_PrefixedWriteIterator_for_UInt16_BinaryOver2(&pPrefixedWriteIterator_for_UInt16_Binary,
                                                 &(serializer->sSerializer_for_Binary), pHeaderWriter->position);
//        return PrefixedWriteIterator<PrefixType, WriteType>(serializer, *position);
         return pPrefixedWriteIterator_for_UInt16_Binary;
    }
    else
    {
////        return PrefixedWriteIterator<PrefixType, WriteType>::Null();
         return Null_in_PrefixedWriteIterator_for_UInt16_Binary_static();
    }
}

//================================================IterateOverCount=================================================================

////} // namespace opendnp3
