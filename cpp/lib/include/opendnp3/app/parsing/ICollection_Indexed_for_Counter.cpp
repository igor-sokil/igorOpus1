#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "ICollection_Indexed_for_Counter.h"

//--------------------------------ICollection_Indexed_for_Counter--------------------------------
////    template<class Fun> void ForeachItem(const Fun& fun) const
void ForeachItem_in_ICollection_Indexed_for_Counter(ICollection_Indexed_for_Counter *pICollection_Indexed_for_Counter, void (*fun)(Indexed_for_Counter item))
   {
//void FunctorVisitor__for__uint32_in_FunctorVisitor__for__uint32(FunctorVisitor__for__uint32 *pFunctorVisitor__for__uint32,
//    void (*fun)(uint32_t* item));
////        FunctorVisitor<T, Fun> visitor(fun);
 FunctorVisitor_Indexed_for_Counter visitor;
 FunctorVisitor_Indexed_for_Counter_in_FunctorVisitor_Indexed_for_Counter(&visitor, fun);

//void     Foreach_in_ICollection_Indexed_for_Counter(ICollection_Indexed_for_Counter*, IVisitor_Indexed_for_Counter* visitor);
////        this->Foreach(visitor);
  Foreach_in_ICollection_Indexed_for_Counter(pICollection_Indexed_for_Counter, &(visitor.iIVisitor_Indexed_for_Counter));
   }

void* getParentPointer_in_ICollection_Indexed_for_Counter(ICollection_Indexed_for_Counter* pICollection_Indexed_for_Counter)
{
  return pICollection_Indexed_for_Counter->pParentPointer_in_ICollection_Indexed_for_Counter;
}
void  setParentPointer_in_ICollection_Indexed_for_Counter(ICollection_Indexed_for_Counter* pICollection_Indexed_for_Counter, void* pParentPointer)
{
  pICollection_Indexed_for_Counter->pParentPointer_in_ICollection_Indexed_for_Counter = pParentPointer;
}
uint16_t Count_in_ICollection_Indexed_for_Counter(ICollection_Indexed_for_Counter *pICollection_Indexed_for_Counter)
{
 return (pICollection_Indexed_for_Counter->pCount_in_ICollection_Indexed_for_Counter)(pICollection_Indexed_for_Counter);
}

void  Foreach_in_ICollection_Indexed_for_Counter(ICollection_Indexed_for_Counter *pICollection_Indexed_for_Counter, IVisitor_Indexed_for_Counter *pIVisitor_Indexed_for_Counter)
{
  (pICollection_Indexed_for_Counter->pForeach_in_ICollection_Indexed_for_Counter)(pICollection_Indexed_for_Counter, pIVisitor_Indexed_for_Counter);
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

void* getParentPointer_in_IVisitor_Indexed_for_Counter(IVisitor_Indexed_for_Counter* pIVisitor_Indexed_for_Counter)
{
  return pIVisitor_Indexed_for_Counter->pParentPointer_in_IVisitor_Indexed_for_Counter;
}
void  setParentPointer_in_IVisitor_Indexed_for_Counter(IVisitor_Indexed_for_Counter* pIVisitor_Indexed_for_Counter, void* pParentPointer)
{
  pIVisitor_Indexed_for_Counter->pParentPointer_in_IVisitor_Indexed_for_Counter = pParentPointer;
}
void OnValue_in_IVisitor_Indexed_for_Counter(IVisitor_Indexed_for_Counter *pIVisitor_Indexed_for_Counter, Indexed_for_Counter pIndexed_for_Counter)
{
  (pIVisitor_Indexed_for_Counter->pOnValue_in_IVisitor_Indexed_for_Counter)(pIVisitor_Indexed_for_Counter, pIndexed_for_Counter);
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

void FunctorVisitor_Indexed_for_Counter_in_FunctorVisitor_Indexed_for_Counter(FunctorVisitor_Indexed_for_Counter *pFunctorVisitor_Indexed_for_Counter,
    void (*fun)(Indexed_for_Counter item))
{
  pFunctorVisitor_Indexed_for_Counter->Fun = fun;

  pFunctorVisitor_Indexed_for_Counter->iIVisitor_Indexed_for_Counter.pOnValue_in_IVisitor_Indexed_for_Counter =
    OnValue_in_FunctorVisitor_Indexed_for_Counter_override;

  setParentPointer_in_IVisitor_Indexed_for_Counter(&(pFunctorVisitor_Indexed_for_Counter->iIVisitor_Indexed_for_Counter), pFunctorVisitor_Indexed_for_Counter);
}

void OnValue_in_FunctorVisitor_Indexed_for_Counter_override(void *pIVisitor_Indexed_for_Counter, Indexed_for_Counter value)
{
  FunctorVisitor_Indexed_for_Counter *parent = (FunctorVisitor_Indexed_for_Counter *)
           getParentPointer_in_IVisitor_Indexed_for_Counter((IVisitor_Indexed_for_Counter *) pIVisitor_Indexed_for_Counter);
///  parent -> Fun(value);
  OnValue_in_FunctorVisitor_Indexed_for_Counter(parent, value);
}

void OnValue_in_FunctorVisitor_Indexed_for_Counter(FunctorVisitor_Indexed_for_Counter *pFunctorVisitor_Indexed_for_Counter, Indexed_for_Counter value)
{
  pFunctorVisitor_Indexed_for_Counter -> Fun(value);
}

//static void *pPointerGlobal1_in_ReadOnlyValue1;
void assignValue_in_ICollection_Indexed_for_Counter(Indexed_for_Counter item);
void assignValue_in_ICollection_Indexed_for_Counter(Indexed_for_Counter item)
{
  Indexed_for_Counter *pValue = (Indexed_for_Counter *)pPointerGlobal1;
//  *((Indexed_for_Counter*)pPointerGlobal1) = *item;
  *pValue = item;
}

boolean ReadOnlyValue_in_ICollection_Indexed_for_Counter(
  ICollection_Indexed_for_Counter *pICollection_Indexed_for_Counter, Indexed_for_Counter *pValue)
{
//  pPointerGlobal1 = pValue;
  pPointerGlobal1 = pValue;

////        if (this->Count() == 1)
  if (Count_in_ICollection_Indexed_for_Counter(pICollection_Indexed_for_Counter) == 1)
  {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
//void ForeachItem_in_ICollection_Indexed_for_Counter(ICollection_Indexed_for_Counter *pICollection_Indexed_for_Counter,
//                  void (*fun)(Indexed_for_Counter* item));
    ForeachItem_in_ICollection_Indexed_for_Counter(pICollection_Indexed_for_Counter, assignValue_in_ICollection_Indexed_for_Counter);
    return true;
  }
  else
  {
    return false;
  }
}

//--------------------------------ICollection_Indexed_for_Counter--------------------------------
