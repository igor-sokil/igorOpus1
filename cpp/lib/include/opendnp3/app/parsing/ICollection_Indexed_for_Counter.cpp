#include "header.h"
#include "ICollection_Indexed_for_Counter.h"

//--------------------------------ICollection_Indexed_for_Counter--------------------------------
/**
 * Abstract way of visiting elements of a collection
 *
 */

void* getParentPointer_in_IVisitor__for__Indexed_for_Counter(IVisitor__for__Indexed_for_Counter* pIVisitor__for__Indexed_for_Counter)
{
  return pIVisitor__for__Indexed_for_Counter->pParentPointer_in_IVisitor__for__Indexed_for_Counter;
}
void  setParentPointer_in_IVisitor__for__Indexed_for_Counter(IVisitor__for__Indexed_for_Counter* pIVisitor__for__Indexed_for_Counter, void* pParentPointer)
{
  pIVisitor__for__Indexed_for_Counter->pParentPointer_in_IVisitor__for__Indexed_for_Counter = pParentPointer;
}

void OnValue_in_IVisitor__for__Indexed_for_Counter(IVisitor__for__Indexed_for_Counter *pIVisitor__for__Indexed_for_Counter, Indexed_for_Counter* pIndexed_for_Counter)
{
  (pIVisitor__for__Indexed_for_Counter->pOnValue_in_IVisitor__for__Indexed_for_Counter)(pIVisitor__for__Indexed_for_Counter, pIndexed_for_Counter);
}

/**
 * An interface representing an abstract immutable collection of things of type T.
 *
 * The user can only read these values via callback to receive each element.
 */
uint16_t Count_in_ICollection_Indexed_for_Counter(ICollection_Indexed_for_Counter* pICollection_Indexed_for_Counter)
{
  return (pICollection_Indexed_for_Counter->pCount_in_ICollection_Indexed_for_Counter)
         (pICollection_Indexed_for_Counter);
}
void     Foreach_in_ICollection_Indexed_for_Counter(ICollection_Indexed_for_Counter* pICollection_Indexed_for_Counter, IVisitor__for__Indexed_for_Counter* visitor)
{
  (pICollection_Indexed_for_Counter->pForeach_in_ICollection_Indexed_for_Counter)
  (pICollection_Indexed_for_Counter, visitor);
}

void* getParentPointer_in_ICollection_Indexed_for_Counter(ICollection_Indexed_for_Counter* pICollection_Indexed_for_Counter)
{
  return pICollection_Indexed_for_Counter->pParentPointer_in_ICollection_Indexed_for_Counter;
}

void  setParentPointer_in_ICollection_Indexed_for_Counter(ICollection_Indexed_for_Counter* pICollection_Indexed_for_Counter, void* pParentPointer)
{
  pICollection_Indexed_for_Counter->pParentPointer_in_ICollection_Indexed_for_Counter = pParentPointer;
}

void assignValue_in_ICollection_Indexed_for_Counter(Indexed_for_Counter* item);

void assignValue_in_ICollection_Indexed_for_Counter(Indexed_for_Counter* item)
{
  *((Indexed_for_Counter*)pPointerGlobal1) = *item;
}

boolean ReadOnlyValue_in_ICollection_Indexed_for_Counter(
  ICollection_Indexed_for_Counter *pICollection_Indexed_for_Counter, Indexed_for_Counter* pValue)
{
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

void ForeachItem_in_ICollection_Indexed_for_Counter(
  ICollection_Indexed_for_Counter *pICollection_Indexed_for_Counter,
  void (*fun)(Indexed_for_Counter* item))
{
  FunctorVisitor__for__Indexed_for_Counter visitor;
//void FunctorVisitor__for__Indexed_for_Counter_in_FunctorVisitor__for__Indexed_for_Counter(__FunctorVisitor__for__Indexed_for_Counter *pFunctorVisitor__for__Indexed_for_Counter,
//    void (*fun)(Indexed_for_Counter* item));
  FunctorVisitor__for__Indexed_for_Counter_in_FunctorVisitor__for__Indexed_for_Counter(&visitor, fun);
//  (pICollection_Indexed_for_Counter->pForeach_in_ICollection_Indexed_for_Counter)
//       (pICollection_Indexed_for_Counter, &(visitor.iIVisitor__for__Indexed_for_Counter));
  Foreach_in_ICollection_Indexed_for_Counter(pICollection_Indexed_for_Counter, &(visitor.iIVisitor__for__Indexed_for_Counter));
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

void FunctorVisitor__for__Indexed_for_Counter_in_FunctorVisitor__for__Indexed_for_Counter(FunctorVisitor__for__Indexed_for_Counter *pFunctorVisitor__for__Indexed_for_Counter,
    void (*fun)(Indexed_for_Counter* item))
{
  pFunctorVisitor__for__Indexed_for_Counter->Fun = fun;

  pFunctorVisitor__for__Indexed_for_Counter->iIVisitor__for__Indexed_for_Counter.pOnValue_in_IVisitor__for__Indexed_for_Counter =
    OnValue_in_FunctorVisitor__for__Indexed_for_Counter_override;

  setParentPointer_in_IVisitor__for__Indexed_for_Counter(&(pFunctorVisitor__for__Indexed_for_Counter->iIVisitor__for__Indexed_for_Counter), pFunctorVisitor__for__Indexed_for_Counter);
}

void OnValue_in_FunctorVisitor__for__Indexed_for_Counter_override(void *pFunctorVisitor__for__Indexed_for_Counter,
    Indexed_for_Counter *value)
{
  ((FunctorVisitor__for__Indexed_for_Counter*)pFunctorVisitor__for__Indexed_for_Counter)->
  Fun(value);
}
//--------------------------------ICollection_Indexed_for_Counter--------------------------------


