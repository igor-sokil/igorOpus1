#include "header.h"
#include "ICollection_for_Group50Var3.h"

//--------------------------------ICollection_for_Group50Var3--------------------------------
/**
 * Abstract way of visiting elements of a collection
 *
 */

void* getParentPointer_in_IVisitor_for_Group50Var3(IVisitor__for__Group50Var3* pIVisitor__for__Group50Var3)
{
  return pIVisitor__for__Group50Var3->pParentPointer_in_IVisitor__for__Group50Var3;
}
void  setParentPointer_in_IVisitor_for_Group50Var3(IVisitor__for__Group50Var3* pIVisitor__for__Group50Var3, void* pParentPointer)
{
  pIVisitor__for__Group50Var3->pParentPointer_in_IVisitor__for__Group50Var3 = pParentPointer;
}

void OnValue_in_IVisitor__for__Group50Var3(IVisitor__for__Group50Var3 *pIVisitor__for__Group50Var3, Group50Var3* pGroup50Var3)
{
  (pIVisitor__for__Group50Var3->pOnValue_in_IVisitor__for__Group50Var3)(pIVisitor__for__Group50Var3, pGroup50Var3);
}

/**
 * An interface representing an abstract immutable collection of things of type T.
 *
 * The user can only read these values via callback to receive each element.
 */
uint16_t Count_in_ICollection_for_Group50Var3(ICollection_for_Group50Var3* pICollection_Group50Var3)
{
  return (pICollection_Group50Var3->pCount_in_ICollection_for_Group50Var3)
         (pICollection_Group50Var3);
}
void     Foreach_in_ICollection_for_Group50Var3(ICollection_for_Group50Var3* pICollection_Group50Var3, IVisitor__for__Group50Var3* visitor)
{
  (pICollection_Group50Var3->pForeach_in_ICollection_for_Group50Var3)
  (pICollection_Group50Var3, visitor);
}

void* getParentPointer_in_ICollection_for_Group50Var3(ICollection_for_Group50Var3* pICollection_Group50Var3)
{
  return pICollection_Group50Var3->pParentPointer_in_ICollection_for_Group50Var3;
}

void  setParentPointer_in_ICollection_for_Group50Var3(ICollection_for_Group50Var3* pICollection_Group50Var3, void* pParentPointer)
{
  pICollection_Group50Var3->pParentPointer_in_ICollection_for_Group50Var3 = pParentPointer;
}

void assignValue_in_ICollection_Group50Var3(Group50Var3* item);

void assignValue_in_ICollection_Group50Var3(Group50Var3* item)
{
  *((Group50Var3*)pPointerGlobal1) = *item;
}

boolean ReadOnlyValue_in_ICollection_for_Group50Var3(
  ICollection_for_Group50Var3 *pICollection_Group50Var3, Group50Var3* pValue)
{
  pPointerGlobal1 = pValue;

////        if (this->Count() == 1)
  if (Count_in_ICollection_for_Group50Var3(pICollection_Group50Var3) == 1)
  {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
//void ForeachItem_in_ICollection_Group50Var3(ICollection_Group50Var3 *pICollection_Group50Var3,
//                  void (*fun)(Group50Var3* item));
    ForeachItem_in_ICollection_for_Group50Var3(pICollection_Group50Var3, assignValue_in_ICollection_Group50Var3);
    return true;
  }
  else
  {
    return false;
  }
}

void ForeachItem_in_ICollection_for_Group50Var3(
  ICollection_for_Group50Var3 *pICollection_Group50Var3,
  void (*fun)(Group50Var3* item))
{
  FunctorVisitor__for__Group50Var3 visitor;
//void FunctorVisitor__for__Group50Var3_in_FunctorVisitor__for__Group50Var3(__FunctorVisitor__for__Group50Var3 *pFunctorVisitor__for__Group50Var3,
//    void (*fun)(Group50Var3* item));
  FunctorVisitor__for__Group50Var3_in_FunctorVisitor__for__Group50Var3(&visitor, fun);
//  (pICollection_Group50Var3->pForeach_in_ICollection_Group50Var3)
//       (pICollection_Group50Var3, &(visitor.iIVisitor__for__Group50Var3));
  Foreach_in_ICollection_for_Group50Var3(pICollection_Group50Var3, &(visitor.iIVisitor__for__Group50Var3));
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

void FunctorVisitor__for__Group50Var3_in_FunctorVisitor__for__Group50Var3(FunctorVisitor__for__Group50Var3 *pFunctorVisitor__for__Group50Var3,
    void (*fun)(Group50Var3* item))
{
  pFunctorVisitor__for__Group50Var3->Fun = fun;

  pFunctorVisitor__for__Group50Var3->iIVisitor__for__Group50Var3.pOnValue_in_IVisitor__for__Group50Var3 =
    OnValue_in_FunctorVisitor__for__Group50Var3_override;

  setParentPointer_in_IVisitor_for_Group50Var3(&(pFunctorVisitor__for__Group50Var3->iIVisitor__for__Group50Var3), pFunctorVisitor__for__Group50Var3);
}

void OnValue_in_FunctorVisitor__for__Group50Var3_override(void *pFunctorVisitor__for__Group50Var3,
    Group50Var3 *value)
{
  ((FunctorVisitor__for__Group50Var3*)pFunctorVisitor__for__Group50Var3)->
  Fun(value);
}
//--------------------------------ICollection_for_Group50Var3--------------------------------


