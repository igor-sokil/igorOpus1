#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "ICollection_Indexed_for_TimeAndInterval.h"

//--------------------------------ICollection_Indexed_for_TimeAndInterval--------------------------------
////    template<class Fun> void ForeachItem(const Fun& fun) const
void ForeachItem_in_ICollection_Indexed_for_TimeAndInterval(ICollection_Indexed_for_TimeAndInterval *pICollection_Indexed_for_TimeAndInterval, void (*fun)(Indexed_for_TimeAndInterval item))
   {
//void FunctorVisitor__for__uint32_in_FunctorVisitor__for__uint32(FunctorVisitor__for__uint32 *pFunctorVisitor__for__uint32,
//    void (*fun)(uint32_t* item));
////        FunctorVisitor<T, Fun> visitor(fun);
 FunctorVisitor_Indexed_for_TimeAndInterval visitor;
 FunctorVisitor_Indexed_for_TimeAndInterval_in_FunctorVisitor_Indexed_for_TimeAndInterval(&visitor, fun);

//void     Foreach_in_ICollection_Indexed_for_TimeAndInterval(ICollection_Indexed_for_TimeAndInterval*, IVisitor_Indexed_for_TimeAndInterval* visitor);
////        this->Foreach(visitor);
  Foreach_in_ICollection_Indexed_for_TimeAndInterval(pICollection_Indexed_for_TimeAndInterval, &(visitor.iIVisitor_Indexed_for_TimeAndInterval));
   }

void* getParentPointer_in_ICollection_Indexed_for_TimeAndInterval(ICollection_Indexed_for_TimeAndInterval* pICollection_Indexed_for_TimeAndInterval)
{
  return pICollection_Indexed_for_TimeAndInterval->pParentPointer_in_ICollection_Indexed_for_TimeAndInterval;
}
void  setParentPointer_in_ICollection_Indexed_for_TimeAndInterval(ICollection_Indexed_for_TimeAndInterval* pICollection_Indexed_for_TimeAndInterval, void* pParentPointer)
{
  pICollection_Indexed_for_TimeAndInterval->pParentPointer_in_ICollection_Indexed_for_TimeAndInterval = pParentPointer;
}
uint16_t Count_in_ICollection_Indexed_for_TimeAndInterval(ICollection_Indexed_for_TimeAndInterval *pICollection_Indexed_for_TimeAndInterval)
{
 return (pICollection_Indexed_for_TimeAndInterval->pCount_in_ICollection_Indexed_for_TimeAndInterval)(pICollection_Indexed_for_TimeAndInterval);
}

void  Foreach_in_ICollection_Indexed_for_TimeAndInterval(ICollection_Indexed_for_TimeAndInterval *pICollection_Indexed_for_TimeAndInterval, IVisitor_Indexed_for_TimeAndInterval *pIVisitor_Indexed_for_TimeAndInterval)
{
  (pICollection_Indexed_for_TimeAndInterval->pForeach_in_ICollection_Indexed_for_TimeAndInterval)(pICollection_Indexed_for_TimeAndInterval, pIVisitor_Indexed_for_TimeAndInterval);
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

void* getParentPointer_in_IVisitor_Indexed_for_TimeAndInterval(IVisitor_Indexed_for_TimeAndInterval* pIVisitor_Indexed_for_TimeAndInterval)
{
  return pIVisitor_Indexed_for_TimeAndInterval->pParentPointer_in_IVisitor_Indexed_for_TimeAndInterval;
}
void  setParentPointer_in_IVisitor_Indexed_for_TimeAndInterval(IVisitor_Indexed_for_TimeAndInterval* pIVisitor_Indexed_for_TimeAndInterval, void* pParentPointer)
{
  pIVisitor_Indexed_for_TimeAndInterval->pParentPointer_in_IVisitor_Indexed_for_TimeAndInterval = pParentPointer;
}
void OnValue_in_IVisitor_Indexed_for_TimeAndInterval(IVisitor_Indexed_for_TimeAndInterval *pIVisitor_Indexed_for_TimeAndInterval, Indexed_for_TimeAndInterval pIndexed_for_TimeAndInterval)
{
  (pIVisitor_Indexed_for_TimeAndInterval->pOnValue_in_IVisitor_Indexed_for_TimeAndInterval)(pIVisitor_Indexed_for_TimeAndInterval, pIndexed_for_TimeAndInterval);
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

void FunctorVisitor_Indexed_for_TimeAndInterval_in_FunctorVisitor_Indexed_for_TimeAndInterval(FunctorVisitor_Indexed_for_TimeAndInterval *pFunctorVisitor_Indexed_for_TimeAndInterval,
    void (*fun)(Indexed_for_TimeAndInterval item))
{
  pFunctorVisitor_Indexed_for_TimeAndInterval->Fun = fun;

  pFunctorVisitor_Indexed_for_TimeAndInterval->iIVisitor_Indexed_for_TimeAndInterval.pOnValue_in_IVisitor_Indexed_for_TimeAndInterval =
    OnValue_in_FunctorVisitor_Indexed_for_TimeAndInterval_override;

  setParentPointer_in_IVisitor_Indexed_for_TimeAndInterval(&(pFunctorVisitor_Indexed_for_TimeAndInterval->iIVisitor_Indexed_for_TimeAndInterval), pFunctorVisitor_Indexed_for_TimeAndInterval);
}

void OnValue_in_FunctorVisitor_Indexed_for_TimeAndInterval_override(void *pIVisitor_Indexed_for_TimeAndInterval, Indexed_for_TimeAndInterval value)
{
  FunctorVisitor_Indexed_for_TimeAndInterval *parent = (FunctorVisitor_Indexed_for_TimeAndInterval *)
           getParentPointer_in_IVisitor_Indexed_for_TimeAndInterval((IVisitor_Indexed_for_TimeAndInterval *) pIVisitor_Indexed_for_TimeAndInterval);
///  parent -> Fun(value);
  OnValue_in_FunctorVisitor_Indexed_for_TimeAndInterval(parent, value);
}

void OnValue_in_FunctorVisitor_Indexed_for_TimeAndInterval(FunctorVisitor_Indexed_for_TimeAndInterval *pFunctorVisitor_Indexed_for_TimeAndInterval, Indexed_for_TimeAndInterval value)
{
  pFunctorVisitor_Indexed_for_TimeAndInterval -> Fun(value);
}

//static void *pPointerGlobal1_in_ReadOnlyValue1;
void assignValue_in_ICollection_Indexed_for_TimeAndInterval(Indexed_for_TimeAndInterval item);
void assignValue_in_ICollection_Indexed_for_TimeAndInterval(Indexed_for_TimeAndInterval item)
{
  Indexed_for_TimeAndInterval *pValue = (Indexed_for_TimeAndInterval *)pPointerGlobal1;
//  *((Indexed_for_TimeAndInterval*)pPointerGlobal1) = *item;
  *pValue = item;
}

boolean ReadOnlyValue_in_ICollection_Indexed_for_TimeAndInterval(
  ICollection_Indexed_for_TimeAndInterval *pICollection_Indexed_for_TimeAndInterval, Indexed_for_TimeAndInterval *pValue)
{
//  pPointerGlobal1 = pValue;
  pPointerGlobal1 = pValue;

////        if (this->Count() == 1)
  if (Count_in_ICollection_Indexed_for_TimeAndInterval(pICollection_Indexed_for_TimeAndInterval) == 1)
  {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
//void ForeachItem_in_ICollection_Indexed_for_TimeAndInterval(ICollection_Indexed_for_TimeAndInterval *pICollection_Indexed_for_TimeAndInterval,
//                  void (*fun)(Indexed_for_TimeAndInterval* item));
    ForeachItem_in_ICollection_Indexed_for_TimeAndInterval(pICollection_Indexed_for_TimeAndInterval, assignValue_in_ICollection_Indexed_for_TimeAndInterval);
    return true;
  }
  else
  {
    return false;
  }
}

//--------------------------------ICollection_Indexed_for_TimeAndInterval--------------------------------
