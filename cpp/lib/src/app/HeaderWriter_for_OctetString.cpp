#include "header.h"
#include "HeaderWriter_for_OctetString.h"

//#include "SerializationTemplates.h"

//#include "HeaderWriter_for_uint16_OctetString.h"

  PrefixedWriteIterator_for_UInt16_OctetString IterateOverCountWithPrefix_for_UInt16_OctetString_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc, DNP3Serializer_for_OctetString* serializer)
{
////    const auto reserve_size
      uint16_t reserve_size =
////        = 2 * PrefixType::size + serializer.get_size(); // enough space for the count, 1 prefix + object
            2*size_in_UInt16 +
              get_size_in_Serializer_for_OctetString(&(serializer->sSerializer_for_OctetString));
////    if (this->WriteHeaderWithReserve(serializer.ID(), qc, reserve_size))
 if(WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter,
                     ID_in_DNP3Serializer_for_OctetString(serializer), qc, reserve_size))
    {
         PrefixedWriteIterator_for_UInt16_OctetString pPrefixedWriteIterator_for_UInt16_OctetString;
         PrefixedWriteIterator_for_UInt16_OctetString_in_PrefixedWriteIterator_for_UInt16_OctetStringOver2(&pPrefixedWriteIterator_for_UInt16_OctetString,
                                                 &(serializer->sSerializer_for_OctetString), pHeaderWriter->position);
//        return PrefixedWriteIterator<PrefixType, WriteType>(serializer, *position);
         return pPrefixedWriteIterator_for_UInt16_OctetString;
    }
    else
    {
////        return PrefixedWriteIterator<PrefixType, WriteType>::Null();
         return Null_in_PrefixedWriteIterator_for_UInt16_OctetString_static();
    }
}
/*
  PrefixedWriteIterator_for_UInt16_OctetString IterateOverCountWithPrefix_for_UInt16_OctetString_in_HeaderWriter(HeaderWriter *pHeaderWriter,
    QualifierCode_uint8_t qc, DNP3Serializer_for_OctetString* serializer)
{
////    const auto reserve_size
////        = 2 * PrefixType::size + serializer.get_size(); // enough space for the count, 1 prefix + object
   uint16_t reserve_size = 2 * size_in_UInt16 + get_size_in_Serializer_for_OctetString(&(serializer->sSerializer_for_OctetString));
//    boolean WriteHeaderWithReserve_in_HeaderWriter(HeaderWriter *pHeaderWriter,
//                                       GroupVariationID id, QualifierCode_uint8_t qc, uint16_t reserve);
//GroupVariationID ID_in_DNP3Serializer_for_OctetString(DNP3Serializer_for_OctetString *pDNP3Serializer_for_OctetString);
////    if (this->WriteHeaderWithReserve(serializer.ID(), qc, reserve_size))
        if(WriteHeaderWithReserve_in_HeaderWriter(pHeaderWriter, ID_in_DNP3Serializer_for_OctetString(serializer), qc, reserve_size))
    {
//   void PrefixedWriteIterator_for_UInt16_OctetString_in_PrefixedWriteIterator_for_UInt16_OctetStringOver2(PrefixedWriteIterator_for_UInt16_OctetString *pPrefixedWriteIterator_for_UInt16_OctetString,
//                                                 Serializer_for_OctetString* serializer, WSeq_for_Uint16_t* position);
            PrefixedWriteIterator_for_UInt16_OctetString pPrefixedWriteIterator_for_UInt16_OctetString;
////        return PrefixedWriteIterator<PrefixType, WriteType>(serializer, *position);
    PrefixedWriteIterator_for_UInt16_OctetString_in_PrefixedWriteIterator_for_UInt16_OctetStringOver2(&pPrefixedWriteIterator_for_UInt16_OctetString,
                                                 &(serializer->sSerializer_for_OctetString), pHeaderWriter->position);
      return pPrefixedWriteIterator_for_UInt16_OctetString;
    }
    else
//   PrefixedWriteIterator_for_UInt16_OctetString Null_in_PrefixedWriteIterator_for_UInt16_OctetString_static(void);
////        return PrefixedWriteIterator<PrefixType, WriteType>::Null();
   return Null_in_PrefixedWriteIterator_for_UInt16_OctetString_static();
}
*/
