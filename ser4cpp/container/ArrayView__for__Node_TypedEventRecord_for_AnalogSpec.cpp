#include <string.h>
#include "header.h"
#include "ArrayView__for__Node_TypedEventRecord_for_AnalogSpec.h"

ArrayView__for__Node_TypedEventRecord_for_AnalogSpec Empty_in_ArrayView__for__Node_TypedEventRecord_for_AnalogSpec_static(void)
{
  ArrayView__for__Node_TypedEventRecord_for_AnalogSpec aArrayView__for__Node_TypedEventRecord_for_AnalogSpec;
////        return ArrayView(nullptr, 0);
  ArrayView__for__Node_TypedEventRecord_for_AnalogSpec_in_ArrayView__for__Node_TypedEventRecord_for_AnalogSpec(&aArrayView__for__Node_TypedEventRecord_for_AnalogSpec,
      NULL, 0);
  return aArrayView__for__Node_TypedEventRecord_for_AnalogSpec;
}

////    ArrayView(T* start, W size) : HasLength<W>(size), m_buffer(start) {}
void ArrayView__for__Node_TypedEventRecord_for_AnalogSpec_in_ArrayView__for__Node_TypedEventRecord_for_AnalogSpec(ArrayView__for__Node_TypedEventRecord_for_AnalogSpec *pArrayView__for__Node_TypedEventRecord_for_AnalogSpec,
    Node_TypedEventRecord_for_AnalogSpec* start, uint32_t size)
{
//    void HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(HasLength_for_Uint32_t *pHasLength, uint32_t length);
  HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(&(pArrayView__for__Node_TypedEventRecord_for_AnalogSpec->hHasLength_for_Uint32_t), size);
  pArrayView__for__Node_TypedEventRecord_for_AnalogSpec->m_buffer = start;
}


boolean contains_in_ArrayView__for__Node_TypedEventRecord_for_AnalogSpecOver1(ArrayView__for__Node_TypedEventRecord_for_AnalogSpec *pArrayView__for__Node_TypedEventRecord_for_AnalogSpec, uint32_t index)
{
////       return index < this->m_length;
  return index <  (pArrayView__for__Node_TypedEventRecord_for_AnalogSpec->hHasLength_for_Uint32_t).m_length;
}

////    inline bool contains(W start, W stop) const
boolean contains_in_ArrayView__for__Node_TypedEventRecord_for_AnalogSpecOver2(ArrayView__for__Node_TypedEventRecord_for_AnalogSpec *pArrayView__for__Node_TypedEventRecord_for_AnalogSpec, uint32_t start, uint32_t stop)
{
  UNUSED(pArrayView__for__Node_TypedEventRecord_for_AnalogSpec);
////        return (start < stop) && Contains(stop);
  return (start < stop);
}
