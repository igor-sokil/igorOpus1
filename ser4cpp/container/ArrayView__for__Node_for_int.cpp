#include <string.h>
#include "header.h"
#include "ArrayView__for__Node_for_int.h"

ArrayView__for__Node_for_int Empty_in_ArrayView__for__Node_for_int_static(void)
{
  ArrayView__for__Node_for_int aArrayView__for__Node_for_int;
////        return ArrayView(nullptr, 0);
  ArrayView__for__Node_for_int_in_ArrayView__for__Node_for_int(&aArrayView__for__Node_for_int,
      NULL, 0);
  return aArrayView__for__Node_for_int;
}

////    ArrayView(T* start, W size) : HasLength<W>(size), m_buffer(start) {}
void ArrayView__for__Node_for_int_in_ArrayView__for__Node_for_int(ArrayView__for__Node_for_int *pArrayView__for__Node_for_int,
    Node_for_int* start, uint32_t size)
{
//    void HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(HasLength_for_Uint32_t *pHasLength, uint32_t length);
  HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(&(pArrayView__for__Node_for_int->hHasLength_for_Uint32_t), size);
  pArrayView__for__Node_for_int->m_buffer = start;
}


boolean contains_in_ArrayView__for__Node_for_intOver1(ArrayView__for__Node_for_int *pArrayView__for__Node_for_int, uint32_t index)
{
////       return index < this->m_length;
  return index <  (pArrayView__for__Node_for_int->hHasLength_for_Uint32_t).m_length;
}

////    inline bool contains(W start, W stop) const
boolean contains_in_ArrayView__for__Node_for_intOver2(ArrayView__for__Node_for_int *pArrayView__for__Node_for_int, uint32_t start, uint32_t stop)
{
  UNUSED(pArrayView__for__Node_for_int);
////        return (start < stop) && Contains(stop);
  return (start < stop);
}
