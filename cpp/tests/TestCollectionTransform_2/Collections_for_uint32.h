#ifndef OPENDNP3_COLLECTION_for_uint32_H
#define OPENDNP3_COLLECTION_for_uint32_H

#include "ICollection_for_uint32.h"

////template<class T> class ArrayCollection : public ICollection<T>
typedef struct
{
  ICollection_for_uint32 iICollection_for_uint32;

////public:
////    ArrayCollection(const T* pArray_, size_t count) : pArray(pArray_), COUNT(count) {}

////    virtual size_t Count() const override final
////    {
////        return COUNT;
////    }

////    virtual void Foreach(IVisitor<T>& visitor) const override final
////    {
////        for (uint32_t i = 0; i < COUNT; ++i)
////        {
////            visitor.OnValue(pArray[i]);
////        }
////    }

////private:
////    const T* pArray;
    uint32_t* pArray;
////    const size_t COUNT;
    uint16_t  COUNT;
} ArrayCollection_for_uint32;

void ArrayCollection_for_uint32_in_ArrayCollection_for_uint32(ArrayCollection_for_uint32 *pArrayCollection_for_uint32, 
                      uint32_t* pArray_, uint16_t  cnt);

uint16_t  Count_in_ArrayCollection_for_uint32(ArrayCollection_for_uint32 *pArrayCollection_for_uint32);
void  Foreach_in_ArrayCollection_for_uint32(ArrayCollection_for_uint32 *pArrayCollection_for_uint32, IVisitor_for_uint32 *pIVisitor_for_uint32);
uint16_t  Count_in_ArrayCollection_for_uint32_override(void *pICollection_for_uint32);
void  Foreach_in_ArrayCollection_for_uint32_override(void *pICollection_for_uint32, IVisitor_for_uint32 *pIVisitor_for_uint32);



#endif
