#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "Array__for__Node_for_int.h"

////    Array(W size) : HasLength<W>(size), buffer(new T[size]()) {}
void Array__for__Node_for_int_in_Array__for__Node_for_intOver2(Array__for__Node_for_int *pArray__for__Node_for_int, uint32_t size)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"Array__for__Node_for_int_in_Array__for__Node_for_intOver2_1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Node_for_int buffer[SIZE_for_int]="<<(uint32_t)pArray__for__Node_for_int->buffer<<'\n';
  decrement_stack_info();
#endif
//    void HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(HasLength_for_Uint32_t *pHasLength, uint32_t length);
  HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(&(pArray__for__Node_for_int->hHasLength_for_Uint32_t), size);
}

////    Array() : HasLength<W>(0), buffer(nullptr) {}
void Array__for__Node_for_int_in_Array__for__Node_for_intOver1(Array__for__Node_for_int *pArray__for__Node_for_int)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"Array__for__Node_for_int_in_Array__for__Node_for_intOver1_1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Node_for_int buffer[SIZE_for_int]="<<(uint32_t)pArray__for__Node_for_int->buffer<<'\n';
  decrement_stack_info();
#endif
  for(int i=0; i<SIZE_for_int; i++)
  {
   Node_for_int_in_Node_for_int(&(pArray__for__Node_for_int->buffer[i]));
  }//for
//    void HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(HasLength_for_Uint32_t *pHasLength, uint32_t length);
  HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(&(pArray__for__Node_for_int->hHasLength_for_Uint32_t), 0);
}

/////    Array(const Array& copy) : HasLength<W>(copy.length()), buffer(new T[copy.length()])
void Array__for__Node_for_int_in_Array__for__Node_for_intOver3(Array__for__Node_for_int *pArray__for__Node_for_int,
    Array__for__Node_for_int* copyEv)
{
//    uint32_t length_in_HasLength_for_Uint32_t(HasLength_for_Uint32_t *pHasLength);
  HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(&(pArray__for__Node_for_int->hHasLength_for_Uint32_t),
      length_in_HasLength_for_Uint32_t(&(pArray__for__Node_for_int->hHasLength_for_Uint32_t)));
////        for (W i = 0; i < copy.length(); ++i)
  for(uint32_t i = 0; i<length_in_HasLength_for_Uint32_t(&(copyEv->hHasLength_for_Uint32_t)); ++i)
////            buffer[i] = copy.buffer[i];
    (pArray__for__Node_for_int->buffer)[i] = (copyEv->buffer)[i];
}

////    virtual ~Array()
////    {
////        delete[] buffer;
////    }
////
////    ArrayView<T, W> to_view() const
ArrayView__for__Node_for_int to_view_in_Array__for__Node_for_int(Array__for__Node_for_int *pArray__for__Node_for_int)
{
////        return ArrayView<T, W>(buffer, this->m_length);
  ArrayView__for__Node_for_int aArrayView__for__Node_for_int;
  ArrayView__for__Node_for_int_in_ArrayView__for__Node_for_int(&aArrayView__for__Node_for_int, pArray__for__Node_for_int->buffer,
      (pArray__for__Node_for_int->hHasLength_for_Uint32_t).m_length
                                                                              );
  return aArrayView__for__Node_for_int;
}

boolean contains_in_Array__for__Node_for_int(Array__for__Node_for_int *pArray__for__Node_for_int, uint32_t index)
{
  return index < (pArray__for__Node_for_int->hHasLength_for_Uint32_t).m_length;
}
