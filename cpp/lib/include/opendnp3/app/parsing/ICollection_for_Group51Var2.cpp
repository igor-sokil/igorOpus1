#include "header.h"
#include "ICollection_for_Group51Var2.h"

//--------------------------------ICollection_for_Group51Var2--------------------------------
/**
 * Abstract way of visiting elements of a collection
 *
 */

void* getParentPointer_in_IVisitor_for_Group51Var2(IVisitor__for__Group51Var2* pIVisitor__for__Group51Var2)
{
  return pIVisitor__for__Group51Var2->pParentPointer_in_IVisitor__for__Group51Var2;
}
void  setParentPointer_in_IVisitor_for_Group51Var2(IVisitor__for__Group51Var2* pIVisitor__for__Group51Var2, void* pParentPointer)
{
  pIVisitor__for__Group51Var2->pParentPointer_in_IVisitor__for__Group51Var2 = pParentPointer;
}

void OnValue_in_IVisitor__for__Group51Var2(IVisitor__for__Group51Var2 *pIVisitor__for__Group51Var2, Group51Var2* pGroup51Var2)
{
  (pIVisitor__for__Group51Var2->pOnValue_in_IVisitor__for__Group51Var2)(pIVisitor__for__Group51Var2, pGroup51Var2);
}

/**
 * An interface representing an abstract immutable collection of things of type T.
 *
 * The user can only read these values via callback to receive each element.
 */
uint16_t Count_in_ICollection_for_Group51Var2(ICollection_for_Group51Var2* pICollection_Group51Var2)
{
  return (pICollection_Group51Var2->pCount_in_ICollection_for_Group51Var2)
         (pICollection_Group51Var2);
}
void     Foreach_in_ICollection_for_Group51Var2(ICollection_for_Group51Var2* pICollection_Group51Var2, IVisitor__for__Group51Var2* visitor)
{
  (pICollection_Group51Var2->pForeach_in_ICollection_for_Group51Var2)
  (pICollection_Group51Var2, visitor);
}

void* getParentPointer_in_ICollection_for_Group51Var2(ICollection_for_Group51Var2* pICollection_Group51Var2)
{
  return pICollection_Group51Var2->pParentPointer_in_ICollection_for_Group51Var2;
}

void  setParentPointer_in_ICollection_for_Group51Var2(ICollection_for_Group51Var2* pICollection_Group51Var2, void* pParentPointer)
{
  pICollection_Group51Var2->pParentPointer_in_ICollection_for_Group51Var2 = pParentPointer;
}

void assignValue_in_ICollection_Group51Var2(Group51Var2* item);

void assignValue_in_ICollection_Group51Var2(Group51Var2* item)
{
  *((Group51Var2*)pPointerGlobal1) = *item;
}

boolean ReadOnlyValue_in_ICollection_for_Group51Var2(
  ICollection_for_Group51Var2 *pICollection_Group51Var2, Group51Var2* pValue)
{
  pPointerGlobal1 = pValue;

////        if (this->Count() == 1)
  if (Count_in_ICollection_for_Group51Var2(pICollection_Group51Var2) == 1)
  {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
//void ForeachItem_in_ICollection_Group51Var2(ICollection_Group51Var2 *pICollection_Group51Var2,
//                  void (*fun)(Group51Var2* item));
    ForeachItem_in_ICollection_for_Group51Var2(pICollection_Group51Var2, assignValue_in_ICollection_Group51Var2);
    return true;
  }
  else
  {
    return false;
  }
}

void ForeachItem_in_ICollection_for_Group51Var2(
  ICollection_for_Group51Var2 *pICollection_Group51Var2,
  void (*fun)(Group51Var2* item))
{
  FunctorVisitor__for__Group51Var2 visitor;
//void FunctorVisitor__for__Group51Var2_in_FunctorVisitor__for__Group51Var2(__FunctorVisitor__for__Group51Var2 *pFunctorVisitor__for__Group51Var2,
//    void (*fun)(Group51Var2* item));
  FunctorVisitor__for__Group51Var2_in_FunctorVisitor__for__Group51Var2(&visitor, fun);
//  (pICollection_Group51Var2->pForeach_in_ICollection_Group51Var2)
//       (pICollection_Group51Var2, &(visitor.iIVisitor__for__Group51Var2));
  Foreach_in_ICollection_for_Group51Var2(pICollection_Group51Var2, &(visitor.iIVisitor__for__Group51Var2));
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

void FunctorVisitor__for__Group51Var2_in_FunctorVisitor__for__Group51Var2(FunctorVisitor__for__Group51Var2 *pFunctorVisitor__for__Group51Var2,
    void (*fun)(Group51Var2* item))
{
  pFunctorVisitor__for__Group51Var2->Fun = fun;

  pFunctorVisitor__for__Group51Var2->iIVisitor__for__Group51Var2.pOnValue_in_IVisitor__for__Group51Var2 =
    OnValue_in_FunctorVisitor__for__Group51Var2_override;

  setParentPointer_in_IVisitor_for_Group51Var2(&(pFunctorVisitor__for__Group51Var2->iIVisitor__for__Group51Var2), pFunctorVisitor__for__Group51Var2);
}

void OnValue_in_FunctorVisitor__for__Group51Var2_override(void *pFunctorVisitor__for__Group51Var2,
    Group51Var2 *value)
{
  ((FunctorVisitor__for__Group51Var2*)pFunctorVisitor__for__Group51Var2)->
  Fun(value);
}
//--------------------------------ICollection_for_Group51Var2--------------------------------


