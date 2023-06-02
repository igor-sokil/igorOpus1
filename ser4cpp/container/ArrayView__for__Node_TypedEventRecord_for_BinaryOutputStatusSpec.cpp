#include <string.h>
#include "header.h"
#include "ArrayView__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec.h"

ArrayView__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec Empty_in_ArrayView__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec_static(void)
{
  ArrayView__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec aArrayView__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec;
////        return ArrayView(nullptr, 0);
  ArrayView__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec_in_ArrayView__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec(&aArrayView__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec,
      NULL, 0);
  return aArrayView__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec;
}

////    ArrayView(T* start, W size) : HasLength<W>(size), m_buffer(start) {}
void ArrayView__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec_in_ArrayView__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec(ArrayView__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec *pArrayView__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec,
    Node_TypedEventRecord_for_BinaryOutputStatusSpec* start, uint32_t size)
{
//    void HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(HasLength_for_Uint32_t *pHasLength, uint32_t length);
  HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(&(pArrayView__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec->hHasLength_for_Uint32_t), size);
  pArrayView__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec->m_buffer = start;
}


boolean contains_in_ArrayView__for__Node_TypedEventRecord_for_BinaryOutputStatusSpecOver1(ArrayView__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec *pArrayView__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec, uint32_t index)
{
////       return index < this->m_length;
  return index <  (pArrayView__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec->hHasLength_for_Uint32_t).m_length;
}

////    inline bool contains(W start, W stop) const
boolean contains_in_ArrayView__for__Node_TypedEventRecord_for_BinaryOutputStatusSpecOver2(ArrayView__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec *pArrayView__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec, uint32_t start, uint32_t stop)
{
////        return (start < stop) && Contains(stop);
  return (start < stop);
}
