#include "header.h"
#include "ICollection_for_CommandPointResult.h"

//--------------------------------ICollection_for_CommandPointResult--------------------------------
/**
 * Abstract way of visiting elements of a collection
 *
 */

void* getParentPointer_in_IVisitor_for_CommandPointResult(IVisitor__for__CommandPointResult* pIVisitor__for__CommandPointResult)
{
  return pIVisitor__for__CommandPointResult->pParentPointer_in_IVisitor__for__CommandPointResult;
}
void  setParentPointer_in_IVisitor_for_CommandPointResult(IVisitor__for__CommandPointResult* pIVisitor__for__CommandPointResult, void* pParentPointer)
{
  pIVisitor__for__CommandPointResult->pParentPointer_in_IVisitor__for__CommandPointResult = pParentPointer;
}

void OnValue_in_IVisitor__for__CommandPointResult(IVisitor__for__CommandPointResult *pIVisitor__for__CommandPointResult, CommandPointResult* pCommandPointResult)
{
  (pIVisitor__for__CommandPointResult->pOnValue_in_IVisitor__for__CommandPointResult)(pIVisitor__for__CommandPointResult, pCommandPointResult);
}

/**
 * An interface representing an abstract immutable collection of things of type T.
 *
 * The user can only read these values via callback to receive each element.
 */
uint16_t Count_in_ICollection_for_CommandPointResult(ICollection_for_CommandPointResult* pICollection_CommandPointResult)
{
  return (pICollection_CommandPointResult->pCount_in_ICollection_for_CommandPointResult)
         (pICollection_CommandPointResult);
}
void     Foreach_in_ICollection_for_CommandPointResult(ICollection_for_CommandPointResult* pICollection_CommandPointResult, IVisitor__for__CommandPointResult* visitor)
{
  (pICollection_CommandPointResult->pForeach_in_ICollection_for_CommandPointResult)
  (pICollection_CommandPointResult, visitor);
}

void* getParentPointer_in_ICollection_for_CommandPointResult(ICollection_for_CommandPointResult* pICollection_CommandPointResult)
{
  return pICollection_CommandPointResult->pParentPointer_in_ICollection_for_CommandPointResult;
}

void  setParentPointer_in_ICollection_for_CommandPointResult(ICollection_for_CommandPointResult* pICollection_CommandPointResult, void* pParentPointer)
{
  pICollection_CommandPointResult->pParentPointer_in_ICollection_for_CommandPointResult = pParentPointer;
}

void assignValue_in_ICollection_CommandPointResult(CommandPointResult* item);

void assignValue_in_ICollection_CommandPointResult(CommandPointResult* item)
{
  *((CommandPointResult*)pPointerGlobal1) = *item;
}

boolean ReadOnlyValue_in_ICollection_for_CommandPointResult(
  ICollection_for_CommandPointResult *pICollection_CommandPointResult, CommandPointResult* pValue)
{
  pPointerGlobal1 = pValue;

////        if (this->Count() == 1)
  if (Count_in_ICollection_for_CommandPointResult(pICollection_CommandPointResult) == 1)
  {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
//void ForeachItem_in_ICollection_CommandPointResult(ICollection_CommandPointResult *pICollection_CommandPointResult,
//                  void (*fun)(CommandPointResult* item));
    ForeachItem_in_ICollection_for_CommandPointResult(pICollection_CommandPointResult, assignValue_in_ICollection_CommandPointResult);
    return true;
  }
  else
  {
    return false;
  }
}

void ForeachItem_in_ICollection_for_CommandPointResult(
  ICollection_for_CommandPointResult *pICollection_CommandPointResult,
  void (*fun)(CommandPointResult* item))
{
  FunctorVisitor__for__CommandPointResult visitor;
//void FunctorVisitor__for__CommandPointResult_in_FunctorVisitor__for__CommandPointResult(__FunctorVisitor__for__CommandPointResult *pFunctorVisitor__for__CommandPointResult,
//    void (*fun)(CommandPointResult* item));
  FunctorVisitor__for__CommandPointResult_in_FunctorVisitor__for__CommandPointResult(&visitor, fun);
//  (pICollection_CommandPointResult->pForeach_in_ICollection_CommandPointResult)
//       (pICollection_CommandPointResult, &(visitor.iIVisitor__for__CommandPointResult));
  Foreach_in_ICollection_for_CommandPointResult(pICollection_CommandPointResult, &(visitor.iIVisitor__for__CommandPointResult));
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

void FunctorVisitor__for__CommandPointResult_in_FunctorVisitor__for__CommandPointResult(FunctorVisitor__for__CommandPointResult *pFunctorVisitor__for__CommandPointResult,
    void (*fun)(CommandPointResult* item))
{
  pFunctorVisitor__for__CommandPointResult->Fun = fun;

  pFunctorVisitor__for__CommandPointResult->iIVisitor__for__CommandPointResult.pOnValue_in_IVisitor__for__CommandPointResult =
    OnValue_in_FunctorVisitor__for__CommandPointResult_override;

  setParentPointer_in_IVisitor_for_CommandPointResult(&(pFunctorVisitor__for__CommandPointResult->iIVisitor__for__CommandPointResult), pFunctorVisitor__for__CommandPointResult);
}

void OnValue_in_FunctorVisitor__for__CommandPointResult_override(void *pFunctorVisitor__for__CommandPointResult,
    CommandPointResult *value)
{
  ((FunctorVisitor__for__CommandPointResult*)pFunctorVisitor__for__CommandPointResult)->
  Fun(value);
}
//--------------------------------ICollection_for_CommandPointResult--------------------------------


