#include "header.h"
#include "Array__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec.h"

////    Array(W size) : HasLength<W>(size), buffer(new T[size]()) {}
void Array__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec_in_Array__for__Node_TypedEventRecord_for_BinaryOutputStatusSpecOver2(Array__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec *pArray__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec, uint32_t size)
{
//    void HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(HasLength_for_Uint32_t *pHasLength, uint32_t length);
  HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(&(pArray__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec->hHasLength_for_Uint32_t), size);
}

////    Array() : HasLength<W>(0), buffer(nullptr) {}
void Array__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec_in_Array__for__Node_TypedEventRecord_for_BinaryOutputStatusSpecOver1(Array__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec *pArray__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec)
{
//    void HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(HasLength_for_Uint32_t *pHasLength, uint32_t length);
  HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(&(pArray__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec->hHasLength_for_Uint32_t), 0);
}

/////    Array(const Array& copy) : HasLength<W>(copy.length()), buffer(new T[copy.length()])
void Array__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec_in_Array__for__Node_TypedEventRecord_for_BinaryOutputStatusSpecOver3(Array__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec *pArray__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec,
    Array__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec* copyEv)
{
//    uint32_t length_in_HasLength_for_Uint32_t(HasLength_for_Uint32_t *pHasLength);
  HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(&(pArray__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec->hHasLength_for_Uint32_t),
      length_in_HasLength_for_Uint32_t(&(pArray__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec->hHasLength_for_Uint32_t)));
////        for (W i = 0; i < copy.length(); ++i)
  for(uint32_t i = 0; i<length_in_HasLength_for_Uint32_t(&(copyEv->hHasLength_for_Uint32_t)); ++i)
////            buffer[i] = copy.buffer[i];
    (pArray__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec->buffer)[i] = (copyEv->buffer)[i];
}

////    virtual ~Array()
////    {
////        delete[] buffer;
////    }
////
////    ArrayView<T, W> to_view() const
ArrayView__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec to_view_in_Array__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec(Array__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec *pArray__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec)
{
////        return ArrayView<T, W>(buffer, this->m_length);
  ArrayView__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec aArrayView__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec;
  ArrayView__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec_in_ArrayView__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec(&aArrayView__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec, pArray__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec->buffer,
      (pArray__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec->hHasLength_for_Uint32_t).m_length
                                                                                                                                      );
  return aArrayView__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec;
}

boolean contains_in_Array__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec(Array__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec *pArray__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec, uint32_t index)
{
  return index < (pArray__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec->hHasLength_for_Uint32_t).m_length;
}
