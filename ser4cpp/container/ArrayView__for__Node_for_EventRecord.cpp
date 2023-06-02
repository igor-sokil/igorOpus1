#include <string.h>
#include "header.h"
#include "ArrayView__for__Node_for_EventRecord.h"

ArrayView__for__Node_for_EventRecord Empty_in_ArrayView__for__Node_for_EventRecord_static(void)
{
  ArrayView__for__Node_for_EventRecord aArrayView__for__Node_for_EventRecord;
////        return ArrayView(nullptr, 0);
  ArrayView__for__Node_for_EventRecord_in_ArrayView__for__Node_for_EventRecord(&aArrayView__for__Node_for_EventRecord,
      NULL, 0);
  return aArrayView__for__Node_for_EventRecord;
}

////    ArrayView(T* start, W size) : HasLength<W>(size), m_buffer(start) {}
void ArrayView__for__Node_for_EventRecord_in_ArrayView__for__Node_for_EventRecord(ArrayView__for__Node_for_EventRecord *pArrayView__for__Node_for_EventRecord,
    Node_for_EventRecord* start, uint32_t size)
{
//    void HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(HasLength_for_Uint32_t *pHasLength, uint32_t length);
  HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(&(pArrayView__for__Node_for_EventRecord->hHasLength_for_Uint32_t), size);
  pArrayView__for__Node_for_EventRecord->m_buffer = start;
}


boolean contains_in_ArrayView__for__Node_for_EventRecordOver1(ArrayView__for__Node_for_EventRecord *pArrayView__for__Node_for_EventRecord, uint32_t index)
{
////       return index < this->m_length;
  return index <  (pArrayView__for__Node_for_EventRecord->hHasLength_for_Uint32_t).m_length;
}

////    inline bool contains(W start, W stop) const
boolean contains_in_ArrayView__for__Node_for_EventRecordOver2(ArrayView__for__Node_for_EventRecord *pArrayView__for__Node_for_EventRecord, uint32_t start, uint32_t stop)
{
////        return (start < stop) && Contains(stop);
  return (start < stop);
}
