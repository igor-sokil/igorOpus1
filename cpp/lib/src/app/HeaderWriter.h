#ifndef OPENDNP3_HEADERWRITER_H
#define OPENDNP3_HEADERWRITER_H

#include "DNP3Serializer.h"
#include "GroupVariationRecord.h"
#include "GroupVariationID.h"
#include "QualifierCode.h"
#include "BitfieldRangeWriteIterator.h"
#include "Group50.h"
#include "Group51.h"
#include "Group52.h"

#include "WSeq.h"
#include "Settable_for_WSeq.h"

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

////    template<class IndexType>
/*
BitfieldRangeWriteIterator_for_UInt8 IterateOverSingleBitfield_for_UInt8_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    GroupVariationID id,
    QualifierCode_uint8_t qc,
    uint8_t start);
*/
//--------------------------------WriteSingleValue_for_UInt8_Group51Var1--------------------------------------------------------
boolean WriteSingleValue_for_UInt8_Group51Var1_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc, Group51Var1*);

//--------------------------------WriteSingleValue_for_UInt8_Group51Var1--------------------------------------------------------
//--------------------------------WriteSingleValue_for_UInt8_Group51Var2--------------------------------------------------------
boolean WriteSingleValue_for_UInt8_Group51Var2_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc, Group51Var2*);

//--------------------------------WriteSingleValue_for_UInt8_Group51Var2--------------------------------------------------------

//--------------------------------WriteSingleValue_for_UInt8_Group52Var1--------------------------------------------------------
boolean WriteSingleValue_for_UInt8_Group52Var1_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc, Group52Var1*);

//--------------------------------WriteSingleValue_for_UInt8_Group52Var1--------------------------------------------------------
//--------------------------------WriteSingleValue_for_UInt8_Group52Var2--------------------------------------------------------
boolean WriteSingleValue_for_UInt8_Group52Var2_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc, Group52Var2*);

//--------------------------------WriteSingleValue_for_UInt8_Group52Var2--------------------------------------------------------

//--------------------------------WriteSingleValue_for_UInt8_Group50Var1--------------------------------------------------------
boolean WriteSingleValue_for_UInt8_Group50Var1_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc, Group50Var1*);

//--------------------------------WriteSingleValue_for_UInt8_Group50Var1--------------------------------------------------------

////    template<class IndexType>
////    BitfieldRangeWriteIterator<IndexType> IterateOverSingleBitfield(GroupVariationID id,
////                                                                    QualifierCode qc,
////                                                                    typename IndexType::type_t start);
//--------------------------------IterateOverSingleBitfield_for_uint8--------------------------------------------------------

BitfieldRangeWriteIterator_for_UInt8 IterateOverSingleBitfield_for_UInt8_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    GroupVariationID id,
    QualifierCode_uint8_t qc,
    uint8_t start);
//--------------------------------IterateOverSingleBitfield_for_uint8--------------------------------------------------------
//--------------------------------IterateOverSingleBitfield_for_uint16--------------------------------------------------------

BitfieldRangeWriteIterator_for_UInt16 IterateOverSingleBitfield_for_UInt16_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    GroupVariationID id,
    QualifierCode_uint8_t qc,
    uint16_t start);
//--------------------------------IterateOverSingleBitfield_for_uint16--------------------------------------------------------

#endif
