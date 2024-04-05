#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "ICollection_Indexed_for_FrozenCounter.h"

//--------------------------------ICollection_Indexed_for_FrozenCounter--------------------------------
////    template<class Fun> void ForeachItem(const Fun& fun) const
void ForeachItem_in_ICollection_Indexed_for_FrozenCounter(ICollection_Indexed_for_FrozenCounter *pICollection_Indexed_for_FrozenCounter, void (*fun)(Indexed_for_FrozenCounter item))
   {
//void FunctorVisitor__for__uint32_in_FunctorVisitor__for__uint32(FunctorVisitor__for__uint32 *pFunctorVisitor__for__uint32,
//    void (*fun)(uint32_t* item));
////        FunctorVisitor<T, Fun> visitor(fun);
 FunctorVisitor_Indexed_for_FrozenCounter visitor;
 FunctorVisitor_Indexed_for_FrozenCounter_in_FunctorVisitor_Indexed_for_FrozenCounter(&visitor, fun);

//void     Foreach_in_ICollection_Indexed_for_FrozenCounter(ICollection_Indexed_for_FrozenCounter*, IVisitor_Indexed_for_FrozenCounter* visitor);
////        this->Foreach(visitor);
  Foreach_in_ICollection_Indexed_for_FrozenCounter(pICollection_Indexed_for_FrozenCounter, &(visitor.iIVisitor_Indexed_for_FrozenCounter));
   }

void* getParentPointer_in_ICollection_Indexed_for_FrozenCounter(ICollection_Indexed_for_FrozenCounter* pICollection_Indexed_for_FrozenCounter)
{
  return pICollection_Indexed_for_FrozenCounter->pParentPointer_in_ICollection_Indexed_for_FrozenCounter;
}
void  setParentPointer_in_ICollection_Indexed_for_FrozenCounter(ICollection_Indexed_for_FrozenCounter* pICollection_Indexed_for_FrozenCounter, void* pParentPointer)
{
  pICollection_Indexed_for_FrozenCounter->pParentPointer_in_ICollection_Indexed_for_FrozenCounter = pParentPointer;
}
uint16_t Count_in_ICollection_Indexed_for_FrozenCounter(ICollection_Indexed_for_FrozenCounter *pICollection_Indexed_for_FrozenCounter)
{
 return (pICollection_Indexed_for_FrozenCounter->pCount_in_ICollection_Indexed_for_FrozenCounter)(pICollection_Indexed_for_FrozenCounter);
}

void  Foreach_in_ICollection_Indexed_for_FrozenCounter(ICollection_Indexed_for_FrozenCounter *pICollection_Indexed_for_FrozenCounter, IVisitor_Indexed_for_FrozenCounter *pIVisitor_Indexed_for_FrozenCounter)
{
  (pICollection_Indexed_for_FrozenCounter->pForeach_in_ICollection_Indexed_for_FrozenCounter)(pICollection_Indexed_for_FrozenCounter, pIVisitor_Indexed_for_FrozenCounter);
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

void* getParentPointer_in_IVisitor_Indexed_for_FrozenCounter(IVisitor_Indexed_for_FrozenCounter* pIVisitor_Indexed_for_FrozenCounter)
{
  return pIVisitor_Indexed_for_FrozenCounter->pParentPointer_in_IVisitor_Indexed_for_FrozenCounter;
}
void  setParentPointer_in_IVisitor_Indexed_for_FrozenCounter(IVisitor_Indexed_for_FrozenCounter* pIVisitor_Indexed_for_FrozenCounter, void* pParentPointer)
{
  pIVisitor_Indexed_for_FrozenCounter->pParentPointer_in_IVisitor_Indexed_for_FrozenCounter = pParentPointer;
}
void OnValue_in_IVisitor_Indexed_for_FrozenCounter(IVisitor_Indexed_for_FrozenCounter *pIVisitor_Indexed_for_FrozenCounter, Indexed_for_FrozenCounter pIndexed_for_FrozenCounter)
{
  (pIVisitor_Indexed_for_FrozenCounter->pOnValue_in_IVisitor_Indexed_for_FrozenCounter)(pIVisitor_Indexed_for_FrozenCounter, pIndexed_for_FrozenCounter);
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

void FunctorVisitor_Indexed_for_FrozenCounter_in_FunctorVisitor_Indexed_for_FrozenCounter(FunctorVisitor_Indexed_for_FrozenCounter *pFunctorVisitor_Indexed_for_FrozenCounter,
    void (*fun)(Indexed_for_FrozenCounter item))
{
  pFunctorVisitor_Indexed_for_FrozenCounter->Fun = fun;

  pFunctorVisitor_Indexed_for_FrozenCounter->iIVisitor_Indexed_for_FrozenCounter.pOnValue_in_IVisitor_Indexed_for_FrozenCounter =
    OnValue_in_FunctorVisitor_Indexed_for_FrozenCounter_override;

  setParentPointer_in_IVisitor_Indexed_for_FrozenCounter(&(pFunctorVisitor_Indexed_for_FrozenCounter->iIVisitor_Indexed_for_FrozenCounter), pFunctorVisitor_Indexed_for_FrozenCounter);
}

void OnValue_in_FunctorVisitor_Indexed_for_FrozenCounter_override(void *pIVisitor_Indexed_for_FrozenCounter, Indexed_for_FrozenCounter value)
{
  FunctorVisitor_Indexed_for_FrozenCounter *parent = (FunctorVisitor_Indexed_for_FrozenCounter *)
           getParentPointer_in_IVisitor_Indexed_for_FrozenCounter((IVisitor_Indexed_for_FrozenCounter *) pIVisitor_Indexed_for_FrozenCounter);
///  parent -> Fun(value);
  OnValue_in_FunctorVisitor_Indexed_for_FrozenCounter(parent, value);
}

void OnValue_in_FunctorVisitor_Indexed_for_FrozenCounter(FunctorVisitor_Indexed_for_FrozenCounter *pFunctorVisitor_Indexed_for_FrozenCounter, Indexed_for_FrozenCounter value)
{
  pFunctorVisitor_Indexed_for_FrozenCounter -> Fun(value);
}

//static void *pPointerGlobal1_in_ReadOnlyValue1;
void assignValue_in_ICollection_Indexed_for_FrozenCounter(Indexed_for_FrozenCounter item);
void assignValue_in_ICollection_Indexed_for_FrozenCounter(Indexed_for_FrozenCounter item)
{
  Indexed_for_FrozenCounter *pValue = (Indexed_for_FrozenCounter *)pPointerGlobal1;
//  *((Indexed_for_FrozenCounter*)pPointerGlobal1) = *item;
  *pValue = item;
}

boolean ReadOnlyValue_in_ICollection_Indexed_for_FrozenCounter(
  ICollection_Indexed_for_FrozenCounter *pICollection_Indexed_for_FrozenCounter, Indexed_for_FrozenCounter *pValue)
{
//  pPointerGlobal1 = pValue;
  pPointerGlobal1 = pValue;

////        if (this->Count() == 1)
  if (Count_in_ICollection_Indexed_for_FrozenCounter(pICollection_Indexed_for_FrozenCounter) == 1)
  {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
//void ForeachItem_in_ICollection_Indexed_for_FrozenCounter(ICollection_Indexed_for_FrozenCounter *pICollection_Indexed_for_FrozenCounter,
//                  void (*fun)(Indexed_for_FrozenCounter* item));
    ForeachItem_in_ICollection_Indexed_for_FrozenCounter(pICollection_Indexed_for_FrozenCounter, assignValue_in_ICollection_Indexed_for_FrozenCounter);
    return true;
  }
  else
  {
    return false;
  }
}

//--------------------------------ICollection_Indexed_for_FrozenCounter--------------------------------
