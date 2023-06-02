#include <string.h>
#include "header.h"
#include "ArrayView__for__Node_TypedEventRecord_for_BinarySpec.h"

ArrayView__for__Node_TypedEventRecord_for_BinarySpec Empty_in_ArrayView__for__Node_TypedEventRecord_for_BinarySpec_static(void)
{
  ArrayView__for__Node_TypedEventRecord_for_BinarySpec aArrayView__for__Node_TypedEventRecord_for_BinarySpec;
////        return ArrayView(nullptr, 0);
  ArrayView__for__Node_TypedEventRecord_for_BinarySpec_in_ArrayView__for__Node_TypedEventRecord_for_BinarySpec(&aArrayView__for__Node_TypedEventRecord_for_BinarySpec,
      NULL, 0);
  return aArrayView__for__Node_TypedEventRecord_for_BinarySpec;
}

////    ArrayView(T* start, W size) : HasLength<W>(size), m_buffer(start) {}
void ArrayView__for__Node_TypedEventRecord_for_BinarySpec_in_ArrayView__for__Node_TypedEventRecord_for_BinarySpec(ArrayView__for__Node_TypedEventRecord_for_BinarySpec *pArrayView__for__Node_TypedEventRecord_for_BinarySpec,
    Node_TypedEventRecord_for_BinarySpec* start, uint32_t size)
{
//    void HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(HasLength_for_Uint32_t *pHasLength, uint32_t length);
  HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(&(pArrayView__for__Node_TypedEventRecord_for_BinarySpec->hHasLength_for_Uint32_t), size);
  pArrayView__for__Node_TypedEventRecord_for_BinarySpec->m_buffer = start;
}


boolean contains_in_ArrayView__for__Node_TypedEventRecord_for_BinarySpecOver1(ArrayView__for__Node_TypedEventRecord_for_BinarySpec *pArrayView__for__Node_TypedEventRecord_for_BinarySpec, uint32_t index)
{
////       return index < this->m_length;
  return index <  (pArrayView__for__Node_TypedEventRecord_for_BinarySpec->hHasLength_for_Uint32_t).m_length;
}

////    inline bool contains(W start, W stop) const
boolean contains_in_ArrayView__for__Node_TypedEventRecord_for_BinarySpecOver2(ArrayView__for__Node_TypedEventRecord_for_BinarySpec *pArrayView__for__Node_TypedEventRecord_for_BinarySpec, uint32_t start, uint32_t stop)
{
////        return (start < stop) && Contains(stop);
  return (start < stop);
}
