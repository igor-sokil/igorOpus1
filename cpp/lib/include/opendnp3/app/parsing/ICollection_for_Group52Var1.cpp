#include "header.h"
#include "ICollection_for_Group52Var1.h"

//--------------------------------ICollection_for_Group52Var1--------------------------------
/**
 * Abstract way of visiting elements of a collection
 *
 */

void* getParentPointer_in_IVisitor_for_Group52Var1(IVisitor__for__Group52Var1* pIVisitor__for__Group52Var1)
{
  return pIVisitor__for__Group52Var1->pParentPointer_in_IVisitor__for__Group52Var1;
}
void  setParentPointer_in_IVisitor_for_Group52Var1(IVisitor__for__Group52Var1* pIVisitor__for__Group52Var1, void* pParentPointer)
{
  pIVisitor__for__Group52Var1->pParentPointer_in_IVisitor__for__Group52Var1 = pParentPointer;
}

void OnValue_in_IVisitor__for__Group52Var1(IVisitor__for__Group52Var1 *pIVisitor__for__Group52Var1, Group52Var1* pGroup52Var1)
{
  (pIVisitor__for__Group52Var1->pOnValue_in_IVisitor__for__Group52Var1)(pIVisitor__for__Group52Var1, pGroup52Var1);
}

/**
 * An interface representing an abstract immutable collection of things of type T.
 *
 * The user can only read these values via callback to receive each element.
 */
uint16_t Count_in_ICollection_for_Group52Var1(ICollection_for_Group52Var1* pICollection_Group52Var1)
{
  return (pICollection_Group52Var1->pCount_in_ICollection_for_Group52Var1)
         (pICollection_Group52Var1);
}
void     Foreach_in_ICollection_for_Group52Var1(ICollection_for_Group52Var1* pICollection_Group52Var1, IVisitor__for__Group52Var1* visitor)
{
  (pICollection_Group52Var1->pForeach_in_ICollection_for_Group52Var1)
  (pICollection_Group52Var1, visitor);
}

void* getParentPointer_in_ICollection_for_Group52Var1(ICollection_for_Group52Var1* pICollection_Group52Var1)
{
  return pICollection_Group52Var1->pParentPointer_in_ICollection_for_Group52Var1;
}

void  setParentPointer_in_ICollection_for_Group52Var1(ICollection_for_Group52Var1* pICollection_Group52Var1, void* pParentPointer)
{
  pICollection_Group52Var1->pParentPointer_in_ICollection_for_Group52Var1 = pParentPointer;
}

void assignValue_in_ICollection_Group52Var1(Group52Var1* item);

void assignValue_in_ICollection_Group52Var1(Group52Var1* item)
{
  *((Group52Var1*)pPointerGlobal1) = *item;
}

boolean ReadOnlyValue_in_ICollection_for_Group52Var1(
  ICollection_for_Group52Var1 *pICollection_Group52Var1, Group52Var1* pValue)
{
  pPointerGlobal1 = pValue;

////        if (this->Count() == 1)
  if (Count_in_ICollection_for_Group52Var1(pICollection_Group52Var1) == 1)
  {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
//void ForeachItem_in_ICollection_Group52Var1(ICollection_Group52Var1 *pICollection_Group52Var1,
//                  void (*fun)(Group52Var1* item));
    ForeachItem_in_ICollection_for_Group52Var1(pICollection_Group52Var1, assignValue_in_ICollection_Group52Var1);
    return true;
  }
  else
  {
    return false;
  }
}

void ForeachItem_in_ICollection_for_Group52Var1(
  ICollection_for_Group52Var1 *pICollection_Group52Var1,
  void (*fun)(Group52Var1* item))
{
  FunctorVisitor__for__Group52Var1 visitor;
//void FunctorVisitor__for__Group52Var1_in_FunctorVisitor__for__Group52Var1(__FunctorVisitor__for__Group52Var1 *pFunctorVisitor__for__Group52Var1,
//    void (*fun)(Group52Var1* item));
  FunctorVisitor__for__Group52Var1_in_FunctorVisitor__for__Group52Var1(&visitor, fun);
//  (pICollection_Group52Var1->pForeach_in_ICollection_Group52Var1)
//       (pICollection_Group52Var1, &(visitor.iIVisitor__for__Group52Var1));
  Foreach_in_ICollection_for_Group52Var1(pICollection_Group52Var1, &(visitor.iIVisitor__for__Group52Var1));
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

void FunctorVisitor__for__Group52Var1_in_FunctorVisitor__for__Group52Var1(FunctorVisitor__for__Group52Var1 *pFunctorVisitor__for__Group52Var1,
    void (*fun)(Group52Var1* item))
{
  pFunctorVisitor__for__Group52Var1->Fun = fun;

  pFunctorVisitor__for__Group52Var1->iIVisitor__for__Group52Var1.pOnValue_in_IVisitor__for__Group52Var1 =
    OnValue_in_FunctorVisitor__for__Group52Var1_override;

  setParentPointer_in_IVisitor_for_Group52Var1(&(pFunctorVisitor__for__Group52Var1->iIVisitor__for__Group52Var1), pFunctorVisitor__for__Group52Var1);
}

void OnValue_in_FunctorVisitor__for__Group52Var1_override(void *pFunctorVisitor__for__Group52Var1,
    Group52Var1 *value)
{
  ((FunctorVisitor__for__Group52Var1*)pFunctorVisitor__for__Group52Var1)->
  Fun(value);
}
//--------------------------------ICollection_for_Group52Var1--------------------------------


