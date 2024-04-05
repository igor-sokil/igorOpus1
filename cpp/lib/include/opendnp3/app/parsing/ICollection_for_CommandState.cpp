#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "ICollection_for_CommandState.h"

//--------------------------------ICollection_for_CommandState--------------------------------
////    template<class Fun> void ForeachItem(const Fun& fun) const
void ForeachItem_in_ICollection_for_CommandState(ICollection_for_CommandState *pICollection_for_CommandState, void (*fun)(CommandState item))
   {
//void FunctorVisitor__for__uint32_in_FunctorVisitor__for__uint32(FunctorVisitor__for__uint32 *pFunctorVisitor__for__uint32,
//    void (*fun)(uint32_t* item));
////        FunctorVisitor<T, Fun> visitor(fun);
 FunctorVisitor_for_CommandState visitor;
 FunctorVisitor_for_CommandState_in_FunctorVisitor_for_CommandState(&visitor, fun);

//void     Foreach_in_ICollection_for_CommandState(ICollection_for_CommandState*, IVisitor_for_CommandState* visitor);
////        this->Foreach(visitor);
  Foreach_in_ICollection_for_CommandState(pICollection_for_CommandState, &(visitor.iIVisitor_for_CommandState));
   }

void* getParentPointer_in_ICollection_for_CommandState(ICollection_for_CommandState* pICollection_for_CommandState)
{
  return pICollection_for_CommandState->pParentPointer_in_ICollection_for_CommandState;
}
void  setParentPointer_in_ICollection_for_CommandState(ICollection_for_CommandState* pICollection_for_CommandState, void* pParentPointer)
{
  pICollection_for_CommandState->pParentPointer_in_ICollection_for_CommandState = pParentPointer;
}
uint16_t Count_in_ICollection_for_CommandState(ICollection_for_CommandState *pICollection_for_CommandState)
{
 return (pICollection_for_CommandState->pCount_in_ICollection_for_CommandState)(pICollection_for_CommandState);
}

void  Foreach_in_ICollection_for_CommandState(ICollection_for_CommandState *pICollection_for_CommandState, IVisitor_for_CommandState *pIVisitor_for_CommandState)
{
  (pICollection_for_CommandState->pForeach_in_ICollection_for_CommandState)(pICollection_for_CommandState, pIVisitor_for_CommandState);
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

void* getParentPointer_in_IVisitor_for_CommandState(IVisitor_for_CommandState* pIVisitor_for_CommandState)
{
  return pIVisitor_for_CommandState->pParentPointer_in_IVisitor_for_CommandState;
}
void  setParentPointer_in_IVisitor_for_CommandState(IVisitor_for_CommandState* pIVisitor_for_CommandState, void* pParentPointer)
{
  pIVisitor_for_CommandState->pParentPointer_in_IVisitor_for_CommandState = pParentPointer;
}
void OnValue_in_IVisitor_for_CommandState(IVisitor_for_CommandState *pIVisitor_for_CommandState, CommandState pCommandState)
{
  (pIVisitor_for_CommandState->pOnValue_in_IVisitor_for_CommandState)(pIVisitor_for_CommandState, pCommandState);
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

void FunctorVisitor_for_CommandState_in_FunctorVisitor_for_CommandState(FunctorVisitor_for_CommandState *pFunctorVisitor_for_CommandState,
    void (*fun)(CommandState item))
{
  pFunctorVisitor_for_CommandState->Fun = fun;

  pFunctorVisitor_for_CommandState->iIVisitor_for_CommandState.pOnValue_in_IVisitor_for_CommandState =
    OnValue_in_FunctorVisitor_for_CommandState_override;

  setParentPointer_in_IVisitor_for_CommandState(&(pFunctorVisitor_for_CommandState->iIVisitor_for_CommandState), pFunctorVisitor_for_CommandState);
}

void OnValue_in_FunctorVisitor_for_CommandState_override(void *pIVisitor_for_CommandState, CommandState value)
{
  FunctorVisitor_for_CommandState *parent = (FunctorVisitor_for_CommandState *)
           getParentPointer_in_IVisitor_for_CommandState((IVisitor_for_CommandState *) pIVisitor_for_CommandState);
///  parent -> Fun(value);
  OnValue_in_FunctorVisitor_for_CommandState(parent, value);
}

void OnValue_in_FunctorVisitor_for_CommandState(FunctorVisitor_for_CommandState *pFunctorVisitor_for_CommandState, CommandState value)
{
  pFunctorVisitor_for_CommandState -> Fun(value);
}

//static void *pPointerGlobal1_in_ReadOnlyValue1;
void assignValue_in_ICollection_for_CommandState(CommandState item);
void assignValue_in_ICollection_for_CommandState(CommandState item)
{
  CommandState *pValue = (CommandState *)pPointerGlobal1;
//  *((CommandState*)pPointerGlobal1) = *item;
  *pValue = item;
}

boolean ReadOnlyValue_in_ICollection_for_CommandState(
  ICollection_for_CommandState *pICollection_for_CommandState, CommandState *pValue)
{
//  pPointerGlobal1 = pValue;
  pPointerGlobal1 = pValue;

////        if (this->Count() == 1)
  if (Count_in_ICollection_for_CommandState(pICollection_for_CommandState) == 1)
  {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
//void ForeachItem_in_ICollection_for_CommandState(ICollection_for_CommandState *pICollection_for_CommandState,
//                  void (*fun)(CommandState* item));
    ForeachItem_in_ICollection_for_CommandState(pICollection_for_CommandState, assignValue_in_ICollection_for_CommandState);
    return true;
  }
  else
  {
    return false;
  }
}

//--------------------------------ICollection_for_CommandState--------------------------------
