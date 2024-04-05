#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "ICollection_for_CommandPointResult.h"

//--------------------------------ICollection_for_CommandPointResult--------------------------------
////    template<class Fun> void ForeachItem(const Fun& fun) const
void ForeachItem_in_ICollection_for_CommandPointResult(ICollection_for_CommandPointResult *pICollection_for_CommandPointResult, void (*fun)(CommandPointResult item))
   {
//void FunctorVisitor__for__uint32_in_FunctorVisitor__for__uint32(FunctorVisitor__for__uint32 *pFunctorVisitor__for__uint32,
//    void (*fun)(uint32_t* item));
////        FunctorVisitor<T, Fun> visitor(fun);
 FunctorVisitor_for_CommandPointResult visitor;
 FunctorVisitor_for_CommandPointResult_in_FunctorVisitor_for_CommandPointResult(&visitor, fun);

//void     Foreach_in_ICollection_for_CommandPointResult(ICollection_for_CommandPointResult*, IVisitor_for_CommandPointResult* visitor);
////        this->Foreach(visitor);
  Foreach_in_ICollection_for_CommandPointResult(pICollection_for_CommandPointResult, &(visitor.iIVisitor_for_CommandPointResult));
   }

void* getParentPointer_in_ICollection_for_CommandPointResult(ICollection_for_CommandPointResult* pICollection_for_CommandPointResult)
{
  return pICollection_for_CommandPointResult->pParentPointer_in_ICollection_for_CommandPointResult;
}
void  setParentPointer_in_ICollection_for_CommandPointResult(ICollection_for_CommandPointResult* pICollection_for_CommandPointResult, void* pParentPointer)
{
  pICollection_for_CommandPointResult->pParentPointer_in_ICollection_for_CommandPointResult = pParentPointer;
}
uint16_t Count_in_ICollection_for_CommandPointResult(ICollection_for_CommandPointResult *pICollection_for_CommandPointResult)
{
 return (pICollection_for_CommandPointResult->pCount_in_ICollection_for_CommandPointResult)(pICollection_for_CommandPointResult);
}

void  Foreach_in_ICollection_for_CommandPointResult(ICollection_for_CommandPointResult *pICollection_for_CommandPointResult, IVisitor_for_CommandPointResult *pIVisitor_for_CommandPointResult)
{
  (pICollection_for_CommandPointResult->pForeach_in_ICollection_for_CommandPointResult)(pICollection_for_CommandPointResult, pIVisitor_for_CommandPointResult);
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

void* getParentPointer_in_IVisitor_for_CommandPointResult(IVisitor_for_CommandPointResult* pIVisitor_for_CommandPointResult)
{
  return pIVisitor_for_CommandPointResult->pParentPointer_in_IVisitor_for_CommandPointResult;
}
void  setParentPointer_in_IVisitor_for_CommandPointResult(IVisitor_for_CommandPointResult* pIVisitor_for_CommandPointResult, void* pParentPointer)
{
  pIVisitor_for_CommandPointResult->pParentPointer_in_IVisitor_for_CommandPointResult = pParentPointer;
}
void OnValue_in_IVisitor_for_CommandPointResult(IVisitor_for_CommandPointResult *pIVisitor_for_CommandPointResult, CommandPointResult pCommandPointResult)
{
  (pIVisitor_for_CommandPointResult->pOnValue_in_IVisitor_for_CommandPointResult)(pIVisitor_for_CommandPointResult, pCommandPointResult);
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

void FunctorVisitor_for_CommandPointResult_in_FunctorVisitor_for_CommandPointResult(FunctorVisitor_for_CommandPointResult *pFunctorVisitor_for_CommandPointResult,
    void (*fun)(CommandPointResult item))
{
  pFunctorVisitor_for_CommandPointResult->Fun = fun;

  pFunctorVisitor_for_CommandPointResult->iIVisitor_for_CommandPointResult.pOnValue_in_IVisitor_for_CommandPointResult =
    OnValue_in_FunctorVisitor_for_CommandPointResult_override;

  setParentPointer_in_IVisitor_for_CommandPointResult(&(pFunctorVisitor_for_CommandPointResult->iIVisitor_for_CommandPointResult), pFunctorVisitor_for_CommandPointResult);
}

void OnValue_in_FunctorVisitor_for_CommandPointResult_override(void *pIVisitor_for_CommandPointResult, CommandPointResult value)
{
  FunctorVisitor_for_CommandPointResult *parent = (FunctorVisitor_for_CommandPointResult *)
           getParentPointer_in_IVisitor_for_CommandPointResult((IVisitor_for_CommandPointResult *) pIVisitor_for_CommandPointResult);
///  parent -> Fun(value);
  OnValue_in_FunctorVisitor_for_CommandPointResult(parent, value);
}

void OnValue_in_FunctorVisitor_for_CommandPointResult(FunctorVisitor_for_CommandPointResult *pFunctorVisitor_for_CommandPointResult, CommandPointResult value)
{
  pFunctorVisitor_for_CommandPointResult -> Fun(value);
}

//static void *pPointerGlobal1_in_ReadOnlyValue1;
void assignValue_in_ICollection_for_CommandPointResult(CommandPointResult item);
void assignValue_in_ICollection_for_CommandPointResult(CommandPointResult item)
{
  CommandPointResult *pValue = (CommandPointResult *)pPointerGlobal1;
//  *((CommandPointResult*)pPointerGlobal1) = *item;
  *pValue = item;
}

boolean ReadOnlyValue_in_ICollection_for_CommandPointResult(
  ICollection_for_CommandPointResult *pICollection_for_CommandPointResult, CommandPointResult *pValue)
{
//  pPointerGlobal1 = pValue;
  pPointerGlobal1 = pValue;

////        if (this->Count() == 1)
  if (Count_in_ICollection_for_CommandPointResult(pICollection_for_CommandPointResult) == 1)
  {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
//void ForeachItem_in_ICollection_for_CommandPointResult(ICollection_for_CommandPointResult *pICollection_for_CommandPointResult,
//                  void (*fun)(CommandPointResult* item));
    ForeachItem_in_ICollection_for_CommandPointResult(pICollection_for_CommandPointResult, assignValue_in_ICollection_for_CommandPointResult);
    return true;
  }
  else
  {
    return false;
  }
}

//--------------------------------ICollection_for_CommandPointResult--------------------------------
