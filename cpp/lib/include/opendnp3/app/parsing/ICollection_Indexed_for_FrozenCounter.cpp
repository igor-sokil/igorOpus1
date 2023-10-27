#include "header.h"
#include "ICollection_Indexed_for_FrozenCounter.h"

//--------------------------------ICollection_Indexed_for_FrozenCounter--------------------------------
/**
 * Abstract way of visiting elements of a collection
 *
 */

void* getParentPointer_in_IVisitor__for__Indexed_for_FrozenCounter(IVisitor__for__Indexed_for_FrozenCounter* pIVisitor__for__Indexed_for_FrozenCounter)
{
  return pIVisitor__for__Indexed_for_FrozenCounter->pParentPointer_in_IVisitor__for__Indexed_for_FrozenCounter;
}
void  setParentPointer_in_IVisitor__for__Indexed_for_FrozenCounter(IVisitor__for__Indexed_for_FrozenCounter* pIVisitor__for__Indexed_for_FrozenCounter, void* pParentPointer)
{
  pIVisitor__for__Indexed_for_FrozenCounter->pParentPointer_in_IVisitor__for__Indexed_for_FrozenCounter = pParentPointer;
}

void OnValue_in_IVisitor__for__Indexed_for_FrozenCounter(IVisitor__for__Indexed_for_FrozenCounter *pIVisitor__for__Indexed_for_FrozenCounter, Indexed_for_FrozenCounter* pIndexed_for_FrozenCounter)
{
  (pIVisitor__for__Indexed_for_FrozenCounter->pOnValue_in_IVisitor__for__Indexed_for_FrozenCounter)(pIVisitor__for__Indexed_for_FrozenCounter, pIndexed_for_FrozenCounter);
}

/**
 * An interface representing an abstract immutable collection of things of type T.
 *
 * The user can only read these values via callback to receive each element.
 */
uint16_t Count_in_ICollection_Indexed_for_FrozenCounter(ICollection_Indexed_for_FrozenCounter* pICollection_Indexed_for_FrozenCounter)
{
  return (pICollection_Indexed_for_FrozenCounter->pCount_in_ICollection_Indexed_for_FrozenCounter)
         (pICollection_Indexed_for_FrozenCounter);
}
void     Foreach_in_ICollection_Indexed_for_FrozenCounter(ICollection_Indexed_for_FrozenCounter* pICollection_Indexed_for_FrozenCounter, IVisitor__for__Indexed_for_FrozenCounter* visitor)
{
  (pICollection_Indexed_for_FrozenCounter->pForeach_in_ICollection_Indexed_for_FrozenCounter)
  (pICollection_Indexed_for_FrozenCounter, visitor);
}

void* getParentPointer_in_ICollection_Indexed_for_FrozenCounter(ICollection_Indexed_for_FrozenCounter* pICollection_Indexed_for_FrozenCounter)
{
  return pICollection_Indexed_for_FrozenCounter->pParentPointer_in_ICollection_Indexed_for_FrozenCounter;
}

void  setParentPointer_in_ICollection_Indexed_for_FrozenCounter(ICollection_Indexed_for_FrozenCounter* pICollection_Indexed_for_FrozenCounter, void* pParentPointer)
{
  pICollection_Indexed_for_FrozenCounter->pParentPointer_in_ICollection_Indexed_for_FrozenCounter = pParentPointer;
}

void assignValue_in_ICollection_Indexed_for_FrozenCounter(Indexed_for_FrozenCounter* item);

void assignValue_in_ICollection_Indexed_for_FrozenCounter(Indexed_for_FrozenCounter* item)
{
  *((Indexed_for_FrozenCounter*)pPointerGlobal1) = *item;
}

boolean ReadOnlyValue_in_ICollection_Indexed_for_FrozenCounter(
  ICollection_Indexed_for_FrozenCounter *pICollection_Indexed_for_FrozenCounter, Indexed_for_FrozenCounter* pValue)
{
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

void ForeachItem_in_ICollection_Indexed_for_FrozenCounter(
  ICollection_Indexed_for_FrozenCounter *pICollection_Indexed_for_FrozenCounter,
  void (*fun)(Indexed_for_FrozenCounter* item))
{
  FunctorVisitor__for__Indexed_for_FrozenCounter visitor;
//void FunctorVisitor__for__Indexed_for_FrozenCounter_in_FunctorVisitor__for__Indexed_for_FrozenCounter(__FunctorVisitor__for__Indexed_for_FrozenCounter *pFunctorVisitor__for__Indexed_for_FrozenCounter,
//    void (*fun)(Indexed_for_FrozenCounter* item));
  FunctorVisitor__for__Indexed_for_FrozenCounter_in_FunctorVisitor__for__Indexed_for_FrozenCounter(&visitor, fun);
//  (pICollection_Indexed_for_FrozenCounter->pForeach_in_ICollection_Indexed_for_FrozenCounter)
//       (pICollection_Indexed_for_FrozenCounter, &(visitor.iIVisitor__for__Indexed_for_FrozenCounter));
  Foreach_in_ICollection_Indexed_for_FrozenCounter(pICollection_Indexed_for_FrozenCounter, &(visitor.iIVisitor__for__Indexed_for_FrozenCounter));
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

void FunctorVisitor__for__Indexed_for_FrozenCounter_in_FunctorVisitor__for__Indexed_for_FrozenCounter(FunctorVisitor__for__Indexed_for_FrozenCounter *pFunctorVisitor__for__Indexed_for_FrozenCounter,
    void (*fun)(Indexed_for_FrozenCounter* item))
{
  pFunctorVisitor__for__Indexed_for_FrozenCounter->Fun = fun;

  pFunctorVisitor__for__Indexed_for_FrozenCounter->iIVisitor__for__Indexed_for_FrozenCounter.pOnValue_in_IVisitor__for__Indexed_for_FrozenCounter =
    OnValue_in_FunctorVisitor__for__Indexed_for_FrozenCounter_override;

  setParentPointer_in_IVisitor__for__Indexed_for_FrozenCounter(&(pFunctorVisitor__for__Indexed_for_FrozenCounter->iIVisitor__for__Indexed_for_FrozenCounter), pFunctorVisitor__for__Indexed_for_FrozenCounter);
}

void OnValue_in_FunctorVisitor__for__Indexed_for_FrozenCounter_override(void *pFunctorVisitor__for__Indexed_for_FrozenCounter,
    Indexed_for_FrozenCounter *value)
{
  ((FunctorVisitor__for__Indexed_for_FrozenCounter*)pFunctorVisitor__for__Indexed_for_FrozenCounter)->
  Fun(value);
}
//--------------------------------ICollection_Indexed_for_FrozenCounter--------------------------------


