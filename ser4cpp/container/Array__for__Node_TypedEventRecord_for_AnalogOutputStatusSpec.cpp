#include "header.h"
#include "Array__for__Node_TypedEventRecord_for_AnalogOutputStatusSpec.h"

////    Array(W size) : HasLength<W>(size), buffer(new T[size]()) {}
void Array__for__Node_TypedEventRecord_for_AnalogOutputStatusSpec_in_Array__for__Node_TypedEventRecord_for_AnalogOutputStatusSpecOver2(Array__for__Node_TypedEventRecord_for_AnalogOutputStatusSpec *pArray__for__Node_TypedEventRecord_for_AnalogOutputStatusSpec, uint32_t size)
{
//    void HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(HasLength_for_Uint32_t *pHasLength, uint32_t length);
  HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(&(pArray__for__Node_TypedEventRecord_for_AnalogOutputStatusSpec->hHasLength_for_Uint32_t), size);
}

////    Array() : HasLength<W>(0), buffer(nullptr) {}
void Array__for__Node_TypedEventRecord_for_AnalogOutputStatusSpec_in_Array__for__Node_TypedEventRecord_for_AnalogOutputStatusSpecOver1(Array__for__Node_TypedEventRecord_for_AnalogOutputStatusSpec *pArray__for__Node_TypedEventRecord_for_AnalogOutputStatusSpec)
{
//    void HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(HasLength_for_Uint32_t *pHasLength, uint32_t length);
  HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(&(pArray__for__Node_TypedEventRecord_for_AnalogOutputStatusSpec->hHasLength_for_Uint32_t), 0);
}

/////    Array(const Array& copy) : HasLength<W>(copy.length()), buffer(new T[copy.length()])
void Array__for__Node_TypedEventRecord_for_AnalogOutputStatusSpec_in_Array__for__Node_TypedEventRecord_for_AnalogOutputStatusSpecOver3(Array__for__Node_TypedEventRecord_for_AnalogOutputStatusSpec *pArray__for__Node_TypedEventRecord_for_AnalogOutputStatusSpec,
    Array__for__Node_TypedEventRecord_for_AnalogOutputStatusSpec* copyEv)
{
//    uint32_t length_in_HasLength_for_Uint32_t(HasLength_for_Uint32_t *pHasLength);
  HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(&(pArray__for__Node_TypedEventRecord_for_AnalogOutputStatusSpec->hHasLength_for_Uint32_t),
      length_in_HasLength_for_Uint32_t(&(pArray__for__Node_TypedEventRecord_for_AnalogOutputStatusSpec->hHasLength_for_Uint32_t)));
////        for (W i = 0; i < copy.length(); ++i)
  for(uint32_t i = 0; i<length_in_HasLength_for_Uint32_t(&(copyEv->hHasLength_for_Uint32_t)); ++i)
////            buffer[i] = copy.buffer[i];
    (pArray__for__Node_TypedEventRecord_for_AnalogOutputStatusSpec->buffer)[i] = (copyEv->buffer)[i];
}

////    virtual ~Array()
////    {
////        delete[] buffer;
////    }
////
////    ArrayView<T, W> to_view() const
ArrayView__for__Node_TypedEventRecord_for_AnalogOutputStatusSpec to_view_in_Array__for__Node_TypedEventRecord_for_AnalogOutputStatusSpec(Array__for__Node_TypedEventRecord_for_AnalogOutputStatusSpec *pArray__for__Node_TypedEventRecord_for_AnalogOutputStatusSpec)
{
////        return ArrayView<T, W>(buffer, this->m_length);
  ArrayView__for__Node_TypedEventRecord_for_AnalogOutputStatusSpec aArrayView__for__Node_TypedEventRecord_for_AnalogOutputStatusSpec;
  ArrayView__for__Node_TypedEventRecord_for_AnalogOutputStatusSpec_in_ArrayView__for__Node_TypedEventRecord_for_AnalogOutputStatusSpec(&aArrayView__for__Node_TypedEventRecord_for_AnalogOutputStatusSpec, pArray__for__Node_TypedEventRecord_for_AnalogOutputStatusSpec->buffer,
      (pArray__for__Node_TypedEventRecord_for_AnalogOutputStatusSpec->hHasLength_for_Uint32_t).m_length
                                                                              );
  return aArrayView__for__Node_TypedEventRecord_for_AnalogOutputStatusSpec;
}

boolean contains_in_Array__for__Node_TypedEventRecord_for_AnalogOutputStatusSpec(Array__for__Node_TypedEventRecord_for_AnalogOutputStatusSpec *pArray__for__Node_TypedEventRecord_for_AnalogOutputStatusSpec, uint32_t index)
{
  return index < (pArray__for__Node_TypedEventRecord_for_AnalogOutputStatusSpec->hHasLength_for_Uint32_t).m_length;
}
