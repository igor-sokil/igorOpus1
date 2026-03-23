#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"

#include "Collections_for_uint32.h"

void ArrayCollection_for_uint32_in_ArrayCollection_for_uint32(ArrayCollection_for_uint32 *pArrayCollection_for_uint32,
                      uint32_t* pArray_, uint16_t  cnt)
{
 pArrayCollection_for_uint32->pArray = pArray_;
 pArrayCollection_for_uint32->COUNT = cnt;

 pArrayCollection_for_uint32->iICollection_for_uint32.pCount_in_ICollection_for_uint32 = Count_in_ArrayCollection_for_uint32_override;
 pArrayCollection_for_uint32->iICollection_for_uint32.pForeach_in_ICollection_for_uint32 = Foreach_in_ArrayCollection_for_uint32_override;
 setParentPointer_in_ICollection_for_uint32(&(pArrayCollection_for_uint32->iICollection_for_uint32), pArrayCollection_for_uint32);
}

uint16_t Count_in_ArrayCollection_for_uint32(ArrayCollection_for_uint32 *pArrayCollection_for_uint32)
{
////        return COUNT;
  return pArrayCollection_for_uint32->COUNT;
}

////    virtual void Foreach(IVisitor<T>& visitor) const override final
void Foreach_in_ArrayCollection_for_uint32(ArrayCollection_for_uint32 *pArrayCollection_for_uint32, IVisitor_for_uint32 *visitor)
{
////        for (uint32_t i = 0; i < COUNT; ++i)
////        {
////            visitor.OnValue(pArray[i]);
////        }
//  uint32_t i = 0;
       for (uint32_t i = 0; i < pArrayCollection_for_uint32->COUNT; ++i)
  {
//void OnValue_in_FunctorVisitor_for_uint32(FunctorVisitor_for_uint32 *pFunctorVisitor_for_uint32, uint32_t *value);
////            visitor.OnValue(pArray[i]);
    OnValue_in_IVisitor_for_uint32(visitor, (pArrayCollection_for_uint32->pArray[i]));
  }
}
uint16_t Count_in_ArrayCollection_for_uint32_override(void *pICollection_for_uint32)
{
  ArrayCollection_for_uint32 *parent = (ArrayCollection_for_uint32 *)
           getParentPointer_in_ICollection_for_uint32((ICollection_for_uint32 *) pICollection_for_uint32);
  return Count_in_ArrayCollection_for_uint32(parent);
}
void  Foreach_in_ArrayCollection_for_uint32_override(void *pICollection_for_uint32, IVisitor_for_uint32 *pIVisitor_for_uint32)
{
  ArrayCollection_for_uint32 *parent = (ArrayCollection_for_uint32 *)
           getParentPointer_in_ICollection_for_uint32((ICollection_for_uint32 *) pICollection_for_uint32);
  Foreach_in_ArrayCollection_for_uint32(parent, pIVisitor_for_uint32);
}


