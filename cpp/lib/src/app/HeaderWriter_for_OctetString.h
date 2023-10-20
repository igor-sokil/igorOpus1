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
#ifndef OPENDNP3_HEADERWRITER_for_OctetString_H
#define OPENDNP3_HEADERWRITER_for_OctetString_H

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
//#include "PrefixedWriteIterator_for_UInt16_Counter.h"
//#include "PrefixedWriteIterator_for_UInt16_DoubleBitBinary.h"
//#include "PrefixedWriteIterator_for_UInt16_FrozenCounter.h"
#include "PrefixedWriteIterator_for_OctetString.h"
//#include "PrefixedWriteIterator.h"

//#include "RangeWriteIterator_for_UInt8_Binary.h"
//#include "RangeWriteIterator_for_UInt8_Counter.h"
#include "RangeWriteIterator_for_OctetString.h"

PrefixedWriteIterator_for_UInt16_OctetString IterateOverCountWithPrefix_for_UInt16_OctetString_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc, DNP3Serializer_for_OctetString* serializer);

//--------------------------------IterateOverRange_for_UInt8_OctetString_in_HeaderWriter--------------------------------------------------------
////    template<class IndexType, class WriteType>
////    RangeWriteIterator<IndexType, WriteType> IterateOverRange(QualifierCode qc,
////                                                              const DNP3Serializer<WriteType>& serializer,
////                                                              typename IndexType::type_t start);
    RangeWriteIterator_for_UInt8_OctetString IterateOverRange_for_UInt8_OctetString_in_HeaderWriter(HeaderWriter *pHeaderWriter,
                                                   QualifierCode_uint8_t qc,
                                                   DNP3Serializer_for_OctetString *serializer,
                                                   uint8_t start
                                                  );

//--------------------------------IterateOverRange_for_UInt8_OctetString_in_HeaderWriter--------------------------------------------------------
//--------------------------------IterateOverRange_for_UInt16_OctetString_in_HeaderWriter--------------------------------------------------------
////    template<class IndexType, class WriteType>
////    RangeWriteIterator<IndexType, WriteType> IterateOverRange(QualifierCode qc,
////                                                              const DNP3Serializer<WriteType>& serializer,
////                                                              typename IndexType::type_t start);
    RangeWriteIterator_for_UInt16_OctetString IterateOverRange_for_UInt16_OctetString_in_HeaderWriter(HeaderWriter *pHeaderWriter,
                                                   QualifierCode_uint8_t qc,
                                                   DNP3Serializer_for_OctetString *serializer,
                                                   uint16_t start
                                                  );

//--------------------------------IterateOverRange_for_UInt16_OctetString_in_HeaderWriter--------------------------------------------------------


#endif
