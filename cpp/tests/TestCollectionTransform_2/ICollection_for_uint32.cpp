#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "ICollection_for_uint32.h"

//--------------------------------ICollection_for_uint32--------------------------------
////    template<class Fun> void ForeachItem(const Fun& fun) const
void ForeachItem_in_ICollection_for_uint32(ICollection_for_uint32 *pICollection_for_uint32, void (*fun)(uint32_t item))
   {
//void FunctorVisitor__for__uint32_in_FunctorVisitor__for__uint32(FunctorVisitor__for__uint32 *pFunctorVisitor__for__uint32,
//    void (*fun)(uint32_t* item));
////        FunctorVisitor<T, Fun> visitor(fun);
 FunctorVisitor_for_uint32 visitor;
 FunctorVisitor_for_uint32_in_FunctorVisitor_for_uint32(&visitor, fun);

//void     Foreach_in_ICollection_for_uint32(ICollection_for_uint32*, IVisitor_for_uint32* visitor);
////        this->Foreach(visitor);
  Foreach_in_ICollection_for_uint32(pICollection_for_uint32, &(visitor.iIVisitor_for_uint32));
   }

void* getParentPointer_in_ICollection_for_uint32(ICollection_for_uint32* pICollection_for_uint32)
{
  return pICollection_for_uint32->pParentPointer_in_ICollection_for_uint32;
}
void  setParentPointer_in_ICollection_for_uint32(ICollection_for_uint32* pICollection_for_uint32, void* pParentPointer)
{
  pICollection_for_uint32->pParentPointer_in_ICollection_for_uint32 = pParentPointer;
}
uint16_t Count_in_ICollection_for_uint32(ICollection_for_uint32 *pICollection_for_uint32)
{
 return (pICollection_for_uint32->pCount_in_ICollection_for_uint32)(pICollection_for_uint32);
}

void  Foreach_in_ICollection_for_uint32(ICollection_for_uint32 *pICollection_for_uint32, IVisitor_for_uint32 *pIVisitor_for_uint32)
{
  (pICollection_for_uint32->pForeach_in_ICollection_for_uint32)(pICollection_for_uint32, pIVisitor_for_uint32);
}

/**
 * Abstract way of visiting elements of a collection
 *

template<class T> class IVisitor
{
public:
    virtual void OnValue(const T& value) = 0;
};
 */

void* getParentPointer_in_IVisitor_for_uint32(IVisitor_for_uint32* pIVisitor_for_uint32)
{
  return pIVisitor_for_uint32->pParentPointer_in_IVisitor_for_uint32;
}
void  setParentPointer_in_IVisitor_for_uint32(IVisitor_for_uint32* pIVisitor_for_uint32, void* pParentPointer)
{
  pIVisitor_for_uint32->pParentPointer_in_IVisitor_for_uint32 = pParentPointer;
}
void OnValue_in_IVisitor_for_uint32(IVisitor_for_uint32 *pIVisitor_for_uint32, uint32_t puint32)
{
  (pIVisitor_for_uint32->pOnValue_in_IVisitor_for_uint32)(pIVisitor_for_uint32, puint32);
}

/**
 * A visitor implemented as an abstract functor
 *
 */
////template<class T, class Fun> class FunctorVisitor : public IVisitor<T>
////{

////public:
////    FunctorVisitor(const Fun& fun_) : fun(fun_) {}

////    virtual void OnValue(const T& value) override final
////    {
////        fun(value);
////    }

////private:
////    Fun fun;
////};

void FunctorVisitor_for_uint32_in_FunctorVisitor_for_uint32(FunctorVisitor_for_uint32 *pFunctorVisitor_for_uint32,
    void (*fun)(uint32_t item))
{
  pFunctorVisitor_for_uint32->Fun = fun;

  pFunctorVisitor_for_uint32->iIVisitor_for_uint32.pOnValue_in_IVisitor_for_uint32 =
    OnValue_in_FunctorVisitor_for_uint32_override;

  setParentPointer_in_IVisitor_for_uint32(&(pFunctorVisitor_for_uint32->iIVisitor_for_uint32), pFunctorVisitor_for_uint32);
}

void OnValue_in_FunctorVisitor_for_uint32_override(void *pIVisitor_for_uint32, uint32_t value)
{
  FunctorVisitor_for_uint32 *parent = (FunctorVisitor_for_uint32 *)
           getParentPointer_in_IVisitor_for_uint32((IVisitor_for_uint32 *) pIVisitor_for_uint32);
///  parent -> Fun(value);
  OnValue_in_FunctorVisitor_for_uint32(parent, value);
}

void OnValue_in_FunctorVisitor_for_uint32(FunctorVisitor_for_uint32 *pFunctorVisitor_for_uint32, uint32_t value)
{
  pFunctorVisitor_for_uint32 -> Fun(value);
}
//--------------------------------ICollection_for_uint32--------------------------------
