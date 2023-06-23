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
#ifndef OPENDNP3_HEADERWRITER_for_Counter_H
#define OPENDNP3_HEADERWRITER_for_Counter_H

////#include "app/BitfieldRangeWriteIterator.h"
////#include "app/CountWriteIterator.h"
////#include "app/DNP3Serializer.h"
////#include "app/GroupVariationRecord.h"
////#include "app/IVariableLength.h"
////#include "app/PrefixedWriteIterator.h"
////#include "app/RangeWriteIterator.h"

////#include "opendnp3/app/GroupVariationID.h"
////#include "opendnp3/gen/QualifierCode.h"

#include "HeaderWriter.h"

//#include "BitfieldRangeWriteIterator.h"
//#include "CountWriteIterator.h"
//#include "DNP3Serializer.h"
//#include "GroupVariationRecord.h"
//#include "IVariableLength.h"
//#include "PrefixedWriteIterator_for_UInt16_Analog.h"
//#include "PrefixedWriteIterator_for_UInt16_AnalogOutputStatus.h"
//#include "PrefixedWriteIterator_for_UInt16_Binary.h"
//#include "PrefixedWriteIterator_for_UInt16_BinaryOutputStatus.h"
#include "PrefixedWriteIterator_for_Counter.h"
//#include "PrefixedWriteIterator_for_UInt16_DoubleBitBinary.h"
//#include "PrefixedWriteIterator_for_UInt16_FrozenCounter.h"
//#include "PrefixedWriteIterator_for_UInt16_OctetString.h"
//#include "PrefixedWriteIterator.h"

//#include "RangeWriteIterator_for_UInt8_Binary.h"
#include "RangeWriteIterator_for_Counter.h"
//#include "RangeWriteIterator_for_UInt16_OctetString.h"

//#include "CountWriteIterator_for_UInt8_Binary.h"
//#include "CountWriteIterator_for_UInt16_Analog.h"
//#include "CountWriteIterator_for_UInt8_Analog.h"

//#include "GroupVariationID.h"
//#include "QualifierCode.h"
//#include "Group50.h"
//#include "Group51.h"

//#include "WSeq.h"
//#include "Settable.h"
////#include <ser4cpp/container/Settable.h>
////#include <ser4cpp/serialization/LittleEndian.h>

////namespace opendnp3
////{
/*
// A facade for writing APDUs to an external buffer
////class HeaderWriter
typedef struct
{
////    friend class APDUWrapper;

////public:
////    bool WriteHeader(GroupVariationID id, QualifierCode qc);

////    template<class IndexType, class WriteType>
////    RangeWriteIterator<IndexType, WriteType> IterateOverRange(QualifierCode qc,
////                                                              const DNP3Serializer<WriteType>& serializer,
////                                                              typename IndexType::type_t start);

////    template<class IndexType>
////    bool WriteRangeHeader(QualifierCode qc,
////                          GroupVariationID gvId,
////                          typename IndexType::type_t start,
////                          typename IndexType::type_t stop);

////    template<class IndexType>
////    bool WriteCountHeader(QualifierCode qc, GroupVariationID gvId, typename IndexType::type_t count);

////    template<class CountType, class WriteType>
////    CountWriteIterator<CountType, WriteType> IterateOverCount(QualifierCode qc,
////                                                              const DNP3Serializer<WriteType>& serializer);

////    template<class IndexType>
////    BitfieldRangeWriteIterator<IndexType> IterateOverSingleBitfield(GroupVariationID id,
////                                                                    QualifierCode qc,
////                                                                    typename IndexType::type_t start);

////    template<class CountType, class ValueType>
////    bool WriteSingleValue(QualifierCode qc, const DNP3Serializer<ValueType>& serializer, const ValueType&);

////    template<class CountType, class WriteType> bool WriteSingleValue(QualifierCode qc, const WriteType&);

////    template<class CountType, class ValueType>
////    bool WriteSingleIndexedValue(QualifierCode qc,
////                                 const DNP3Serializer<ValueType>& serializer,
////                                 const ValueType&,
////                                 typename CountType::type_t index);

////    template<class PrefixType, class WriteType>
////    PrefixedWriteIterator<PrefixType, WriteType> IterateOverCountWithPrefix(
////        QualifierCode qc, const DNP3Serializer<WriteType>& serializer);

////    template<class PrefixType, class WriteType, class CTOType>
////    PrefixedWriteIterator<PrefixType, WriteType> IterateOverCountWithPrefixAndCTO(
////        QualifierCode qc, const DNP3Serializer<WriteType>& serializer, const CTOType& cto);

    // record the current position in case we need to rollback
////    void Mark();

    // roll back to the last mark
////    bool Rollback();

////    size_t Remaining() const;

////private:
////    explicit HeaderWriter(ser4cpp::wseq_t* position_);

////    bool WriteHeaderWithReserve(GroupVariationID id, QualifierCode qc, size_t reserve);

////    ser4cpp::wseq_t* position;
      WSeq_for_Uint16_t* position;

////    ser4cpp::Settable<ser4cpp::wseq_t> mark;
      Settable_for_WSeq_t mark;
} HeaderWriter;

    void Mark_in_HeaderWriter(HeaderWriter *pHeaderWriter);
    boolean Rollback_in_HeaderWriter(HeaderWriter *pHeaderWriter);
    uint16_t Remaining_in_HeaderWriter(HeaderWriter *pHeaderWriter);
    boolean WriteHeader_in_HeaderWriter(HeaderWriter *pHeaderWriter, GroupVariationID id, QualifierCode_uint8_t qc);
    void HeaderWriter_in_HeaderWriter(HeaderWriter *pHeaderWriter, WSeq_for_Uint16_t * position_);
    boolean WriteHeaderWithReserve_in_HeaderWriter(HeaderWriter *pHeaderWriter,
                                       GroupVariationID id, QualifierCode_uint8_t qc, uint16_t reserve);

//================================================WriteSingleValue=================================================================
//--------------------------------WriteSingleValue_for_UInt8_Group51Var1--------------------------------------------------------
    boolean WriteSingleValue_for_UInt8_Group51Var1_in_HeaderWriter(HeaderWriter *pHeaderWriter, 
                                                                    QualifierCode_uint8_t qc, Group51Var1*);

//--------------------------------WriteSingleValue_for_UInt8_Group51Var1--------------------------------------------------------
//--------------------------------WriteSingleValue_for_UInt8_Group51Var2--------------------------------------------------------
    boolean WriteSingleValue_for_UInt8_Group51Var2_in_HeaderWriter(HeaderWriter *pHeaderWriter, 
                                                                    QualifierCode_uint8_t qc, Group51Var2*);

//--------------------------------WriteSingleValue_for_UInt8_Group51Var2--------------------------------------------------------
//--------------------------------WriteSingleValue_for_UInt8_Group50Var1--------------------------------------------------------
    boolean WriteSingleValue_for_UInt8_Group50Var1_in_HeaderWriter(HeaderWriter *pHeaderWriter, 
                                                                    QualifierCode_uint8_t qc, Group50Var1*);

//--------------------------------WriteSingleValue_for_UInt8_Group50Var1--------------------------------------------------------
//================================================Analog=================================================================
//--------------------------------IterateOverCount_for_UInt16_Ananlog_in_HeaderWriter--------------------------------------------------------
////    template<class CountType, class WriteType>
////    CountWriteIterator<CountType, WriteType> IterateOverCount(QualifierCode qc,
////                                                              const DNP3Serializer<WriteType>& serializer);
    CountWriteIterator_for_UInt16_Analog IterateOverCount_for_UInt16_Analog_in_HeaderWriter(HeaderWriter *pHeaderWriter, 
                                                              QualifierCode_uint8_t qc,
                                                              DNP3Serializer_for_Analog* serializer);

//--------------------------------IterateOverCount_for_UInt16_Analog_in_HeaderWriter--------------------------------------------------------
//--------------------------------IterateOverCount_for_UInt8_Ananlog_in_HeaderWriter--------------------------------------------------------
////    template<class CountType, class WriteType>
////    CountWriteIterator<CountType, WriteType> IterateOverCount(QualifierCode qc,
////                                                              const DNP3Serializer<WriteType>& serializer);
    CountWriteIterator_for_UInt8_Analog IterateOverCount_for_UInt8_Analog_in_HeaderWriter(HeaderWriter *pHeaderWriter, 
                                                              QualifierCode_uint8_t qc,
                                                              DNP3Serializer_for_Analog* serializer);

//--------------------------------IterateOverCount_for_UInt8_Analog_in_HeaderWriter--------------------------------------------------------
//================================================Analog=================================================================
//================================================Binary=================================================================
//--------------------------------IterateOverRange_for_UInt8_Binary_in_HeaderWriter--------------------------------------------------------
////    template<class IndexType, class WriteType>
////    RangeWriteIterator<IndexType, WriteType> IterateOverRange(QualifierCode qc,
////                                                              const DNP3Serializer<WriteType>& serializer,
////                                                              typename IndexType::type_t start);
    RangeWriteIterator_for_UInt8_Binary IterateOverRange_for_UInt8_Binary_in_HeaderWriter(HeaderWriter *pHeaderWriter, 
                                                   QualifierCode_uint8_t qc,
                                                   DNP3Serializer_for_Binary *serializer,
                                                   uint8_t start
                                                  );

//--------------------------------IterateOverRange_for_UInt8_Binary_in_HeaderWriter--------------------------------------------------------
//--------------------------------IterateOverCount_for_UInt8_Binary_in_HeaderWriter--------------------------------------------------------
////    template<class CountType, class WriteType>
////    CountWriteIterator<CountType, WriteType> IterateOverCount(QualifierCode qc,
////                                                              const DNP3Serializer<WriteType>& serializer);
    CountWriteIterator_for_UInt8_Binary IterateOverCount_for_UInt8_Binary_in_HeaderWriter(HeaderWriter *pHeaderWriter,
                                                              QualifierCode_uint8_t qc,
                                                              DNP3Serializer_for_Binary* serializer);
//--------------------------------IterateOverCount_for_UInt8_Binary_in_HeaderWriter--------------------------------------------------------
//--------------------------------IterateOverCountWithPrefixAndCTO_for_UInt16_Binary_Group51Var1_in_HeaderWriter--------------------------------------------------------
////    template<class PrefixType, class WriteType, class CTOType>
////    PrefixedWriteIterator<PrefixType, WriteType> IterateOverCountWithPrefixAndCTO(
////        QualifierCode qc, const DNP3Serializer<WriteType>& serializer, const CTOType& cto);
    PrefixedWriteIterator_for_UInt16_Binary IterateOverCountWithPrefixAndCTO_for_UInt16_Binary_Group51Var1_in_HeaderWriter(HeaderWriter *pHeaderWriter,
                                                              QualifierCode_uint8_t qc,
                                                              DNP3Serializer_for_Binary* serializer,
                                                              Group51Var1* cto);
//--------------------------------IterateOverCountWithPrefixAndCTO_for_UInt16_Binary_Group51Var1_in_HeaderWriter--------------------------------------------------------
//--------------------------------IterateOverCountWithPrefixAndCTO_for_UInt16_Binary_Group51Var2_in_HeaderWriter--------------------------------------------------------
////    template<class PrefixType, class WriteType, class CTOType>
////    PrefixedWriteIterator<PrefixType, WriteType> IterateOverCountWithPrefixAndCTO(
////        QualifierCode qc, const DNP3Serializer<WriteType>& serializer, const CTOType& cto);
    PrefixedWriteIterator_for_UInt16_Binary IterateOverCountWithPrefixAndCTO_for_UInt16_Binary_Group51Var2_in_HeaderWriter(HeaderWriter *pHeaderWriter,
                                                              QualifierCode_uint8_t qc,
                                                              DNP3Serializer_for_Binary* serializer,
                                                              Group51Var2* cto);
//--------------------------------IterateOverCountWithPrefixAndCTO_for_UInt16_Binary_Group51Var2_in_HeaderWriter--------------------------------------------------------
//--------------------------------IterateOverCountWithPrefix_for_UInt16_Binary--------------------------------------------------------
////template<class PrefixType, class WriteType>
////PrefixedWriteIterator<PrefixType, WriteType> HeaderWriter::IterateOverCountWithPrefix(
////    QualifierCode qc, const DNP3Serializer<WriteType>& serializer)
  PrefixedWriteIterator_for_UInt16_Binary IterateOverCountWithPrefix_for_UInt16_Binary_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc, DNP3Serializer_for_Binary* serializer);

//--------------------------------IterateOverCountWithPrefix_for_UInt16_Binary--------------------------------------------------------
*/
//================================================Counter=================================================================
//--------------------------------IterateOverRange_for_UInt8_Counter_in_HeaderWriter--------------------------------------------------------
////    template<class IndexType, class WriteType>
////    RangeWriteIterator<IndexType, WriteType> IterateOverRange(QualifierCode qc,
////                                                              const DNP3Serializer<WriteType>& serializer,
////                                                              typename IndexType::type_t start);
    RangeWriteIterator_for_UInt8_Counter IterateOverRange_for_UInt8_Counter_in_HeaderWriter(HeaderWriter *pHeaderWriter, 
                                                   QualifierCode_uint8_t qc,
                                                   DNP3Serializer_for_Counter *serializer,
                                                   uint8_t start
                                                  );
//--------------------------------IterateOverRange_for_UInt8_Counter_in_HeaderWriter--------------------------------------------------------
//================================================Counter=================================================================

////template<class IndexType>
////bool HeaderWriter::WriteRangeHeader(QualifierCode qc,
////                                    GroupVariationID gvId,
////                                    typename IndexType::type_t start,
////                                    typename IndexType::type_t stop)
////{
////    if (WriteHeaderWithReserve(gvId, qc, 2 * IndexType::size))
////    {
////        IndexType::write_to(*position, start);
////        IndexType::write_to(*position, stop);
////        return true;
////    }
////    else
////    {
////        return false;
////    }
////}

////template<class IndexType>
////bool HeaderWriter::WriteCountHeader(QualifierCode qc, GroupVariationID gvId, typename IndexType::type_t count)
////{
////    if (WriteHeaderWithReserve(gvId, qc, IndexType::size))
////    {
////        IndexType::write_to(*position, count);
////        return true;
////    }
////    else
////    {
////        return false;
////    }
////}
////
////template<class CountType, class ValueType>
////bool HeaderWriter::WriteSingleValue(QualifierCode qc,
////                                    const DNP3Serializer<ValueType>& serializer,
////                                    const ValueType& value)
////{
////    const auto reserve_size = CountType::size + serializer.Size();
////    if (this->WriteHeaderWithReserve(ValueType::ID, qc, reserve_size))
////    {
////        CountType::WSlice(*position, 1); // write the count
////        serializer.Write(value, *position);
////        return true;
////    }
////    else
////        return false;
////}
////
////template<class CountType, class WriteType> bool HeaderWriter::WriteSingleValue(QualifierCode qc, const WriteType& value)
////{
////    const auto reserve_size = CountType::size + WriteType::Size();
////    if (this->WriteHeaderWithReserve(WriteType::ID(), qc, reserve_size))
////    {
////        CountType::write_to(*position, 1); // write the count
////        WriteType::Write(value, *position);
////        return true;
////    }
////    else
////    {
////        return false;
////    }
////}
////
////template<class CountType, class ValueType>
////bool HeaderWriter::WriteSingleIndexedValue(QualifierCode qc,
////                                           const DNP3Serializer<ValueType>& serializer,
////                                           const ValueType& value,
////                                           typename CountType::type_t index)
////{
////    const auto reserve_size = 2 * CountType::size + serializer.get_size();
////    if (this->WriteHeaderWithReserve(serializer.ID(), qc, reserve_size))
////    {
////        CountType::write_to(*position, 1);     // write the count
////        CountType::write_to(*position, index); // write the index
////        serializer.write(value, *position);
////        return true;
////    }
////    else
////        return false;
////}
////
////template<class IndexType, class WriteType>
////RangeWriteIterator<IndexType, WriteType> HeaderWriter::IterateOverRange(QualifierCode qc,
////                                                                        const DNP3Serializer<WriteType>& serializer,
////                                                                        typename IndexType::type_t start)
////{
////    const auto reserve_size = 2 * IndexType::size + serializer.get_size();
////    if (this->WriteHeaderWithReserve(serializer.ID(), qc, reserve_size))
////    {
////        return RangeWriteIterator<IndexType, WriteType>(start, serializer, *position);
////    }
////    else
////        return RangeWriteIterator<IndexType, WriteType>::Null();
////}
////
////template<class CountType, class WriteType>
////CountWriteIterator<CountType, WriteType> HeaderWriter::IterateOverCount(QualifierCode qc,
////                                                                        const DNP3Serializer<WriteType>& serializer)
////{
////    const auto reserve_size = CountType::size + serializer.get_size();
////    if (this->WriteHeaderWithReserve(serializer.ID(), qc, reserve_size))
////    {
////        return CountWriteIterator<CountType, WriteType>(serializer, *position);
////    }
////    else
////        return CountWriteIterator<CountType, WriteType>::Null();
////}
////
////template<class IndexType>
////BitfieldRangeWriteIterator<IndexType> HeaderWriter::IterateOverSingleBitfield(GroupVariationID id,
////                                                                              QualifierCode qc,
////                                                                              typename IndexType::type_t start)
////{
////    const auto reserve_size = 2 * IndexType::size + 1; // need at least 1 byte
////    if (this->WriteHeaderWithReserve(id, qc, reserve_size))
////    {
////        return BitfieldRangeWriteIterator<IndexType>(start, *position);
////    }
////    else
////        return BitfieldRangeWriteIterator<IndexType>::Null();
////}
////

////template<class PrefixType, class WriteType>
////PrefixedWriteIterator<PrefixType, WriteType> HeaderWriter::IterateOverCountWithPrefix(
////    QualifierCode qc, const DNP3Serializer<WriteType>& serializer)
////
////template<class PrefixType, class WriteType, class CTOType>
////PrefixedWriteIterator<PrefixType, WriteType> HeaderWriter::IterateOverCountWithPrefixAndCTO(
////    QualifierCode qc, const DNP3Serializer<WriteType>& serializer, const CTOType& cto)
////{
////    this->Mark();
////    if (this->WriteSingleValue<ser4cpp::UInt8, CTOType>(QualifierCode::UINT8_CNT, cto))
////    {
////        auto iter = IterateOverCountWithPrefix<PrefixType, WriteType>(qc, serializer);
////        if (!iter.IsValid())
////        {
////            // remove the CTO header, if there's no space to write a value
////            this->Rollback();
////        }
////        return iter;
////    }
////    else
////    {
////        return PrefixedWriteIterator<PrefixType, WriteType>::Null();
////    }
////}
////
////} // namespace opendnp3

#endif
