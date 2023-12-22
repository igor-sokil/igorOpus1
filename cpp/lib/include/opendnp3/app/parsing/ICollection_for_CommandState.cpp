#include "header.h"
#include "ICollection_for_CommandState.h"

//--------------------------------ICollection_for_CommandState--------------------------------
/**
 * Abstract way of visiting elements of a collection
 *
 */

void* getParentPointer_in_IVisitor_for_CommandState(IVisitor__for__CommandState* pIVisitor__for__CommandState)
{
  return pIVisitor__for__CommandState->pParentPointer_in_IVisitor__for__CommandState;
}
void  setParentPointer_in_IVisitor_for_CommandState(IVisitor__for__CommandState* pIVisitor__for__CommandState, void* pParentPointer)
{
  pIVisitor__for__CommandState->pParentPointer_in_IVisitor__for__CommandState = pParentPointer;
}

void OnValue_in_IVisitor__for__CommandState(IVisitor__for__CommandState *pIVisitor__for__CommandState, CommandState* pCommandState)
{
  (pIVisitor__for__CommandState->pOnValue_in_IVisitor__for__CommandState)(pIVisitor__for__CommandState, pCommandState);
}

/**
 * An interface representing an abstract immutable collection of things of type T.
 *
 * The user can only read these values via callback to receive each element.
 */
uint16_t Count_in_ICollection_for_CommandState(ICollection_for_CommandState* pICollection_CommandState)
{
  return (pICollection_CommandState->pCount_in_ICollection_for_CommandState)
         (pICollection_CommandState);
}
void     Foreach_in_ICollection_for_CommandState(ICollection_for_CommandState* pICollection_CommandState, IVisitor__for__CommandState* visitor)
{
  (pICollection_CommandState->pForeach_in_ICollection_for_CommandState)
  (pICollection_CommandState, visitor);
}

void* getParentPointer_in_ICollection_for_CommandState(ICollection_for_CommandState* pICollection_CommandState)
{
  return pICollection_CommandState->pParentPointer_in_ICollection_for_CommandState;
}

void  setParentPointer_in_ICollection_for_CommandState(ICollection_for_CommandState* pICollection_CommandState, void* pParentPointer)
{
  pICollection_CommandState->pParentPointer_in_ICollection_for_CommandState = pParentPointer;
}

void assignValue_in_ICollection_CommandState(CommandState* item);

void assignValue_in_ICollection_CommandState(CommandState* item)
{
  *((CommandState*)pPointerGlobal1) = *item;
}

boolean ReadOnlyValue_in_ICollection_for_CommandState(
  ICollection_for_CommandState *pICollection_CommandState, CommandState* pValue)
{
  pPointerGlobal1 = pValue;

////        if (this->Count() == 1)
  if (Count_in_ICollection_for_CommandState(pICollection_CommandState) == 1)
  {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
//void ForeachItem_in_ICollection_CommandState(ICollection_CommandState *pICollection_CommandState,
//                  void (*fun)(CommandState* item));
    ForeachItem_in_ICollection_for_CommandState(pICollection_CommandState, assignValue_in_ICollection_CommandState);
    return true;
  }
  else
  {
    return false;
  }
}

void ForeachItem_in_ICollection_for_CommandState(
  ICollection_for_CommandState *pICollection_CommandState,
  void (*fun)(CommandState* item))
{
  FunctorVisitor__for__CommandState visitor;
//void FunctorVisitor__for__CommandState_in_FunctorVisitor__for__CommandState(__FunctorVisitor__for__CommandState *pFunctorVisitor__for__CommandState,
//    void (*fun)(CommandState* item));
  FunctorVisitor__for__CommandState_in_FunctorVisitor__for__CommandState(&visitor, fun);
//  (pICollection_CommandState->pForeach_in_ICollection_CommandState)
//       (pICollection_CommandState, &(visitor.iIVisitor__for__CommandState));
  Foreach_in_ICollection_for_CommandState(pICollection_CommandState, &(visitor.iIVisitor__for__CommandState));
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

void FunctorVisitor__for__CommandState_in_FunctorVisitor__for__CommandState(FunctorVisitor__for__CommandState *pFunctorVisitor__for__CommandState,
    void (*fun)(CommandState* item))
{
  pFunctorVisitor__for__CommandState->Fun = fun;

  pFunctorVisitor__for__CommandState->iIVisitor__for__CommandState.pOnValue_in_IVisitor__for__CommandState =
    OnValue_in_FunctorVisitor__for__CommandState_override;

  setParentPointer_in_IVisitor_for_CommandState(&(pFunctorVisitor__for__CommandState->iIVisitor__for__CommandState), pFunctorVisitor__for__CommandState);
}

void OnValue_in_FunctorVisitor__for__CommandState_override(void *pFunctorVisitor__for__CommandState,
    CommandState *value)
{
  ((FunctorVisitor__for__CommandState*)pFunctorVisitor__for__CommandState)->
  Fun(value);
}
//--------------------------------ICollection_for_CommandState--------------------------------


