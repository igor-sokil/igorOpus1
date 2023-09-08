#include "header.h"
#include "ICollection_Indexed_for_Group1Var2.h"

//--------------------------------ICollection_Indexed_for_Group1Var2--------------------------------
/**
 * Abstract way of visiting elements of a collection
 *
 */

void* getParentPointer_in_IVisitor__for__Indexed_for_Group1Var2(IVisitor__for__Indexed_for_Group1Var2* pIVisitor__for__Indexed_for_Group1Var2)
{
  return pIVisitor__for__Indexed_for_Group1Var2->pParentPointer_in_IVisitor__for__Indexed_for_Group1Var2;
}
void  setParentPointer_in_IVisitor__for__Indexed_for_Group1Var2(IVisitor__for__Indexed_for_Group1Var2* pIVisitor__for__Indexed_for_Group1Var2, void* pParentPointer)
{
  pIVisitor__for__Indexed_for_Group1Var2->pParentPointer_in_IVisitor__for__Indexed_for_Group1Var2 = pParentPointer;
}

void OnValue_in_IVisitor__for__Indexed_for_Group1Var2(IVisitor__for__Indexed_for_Group1Var2 *pIVisitor__for__Indexed_for_Group1Var2, Indexed_for_Group1Var2* pIndexed_for_Group1Var2)
{
  (pIVisitor__for__Indexed_for_Group1Var2->pOnValue_in_IVisitor__for__Indexed_for_Group1Var2)(pIVisitor__for__Indexed_for_Group1Var2, pIndexed_for_Group1Var2);
}

/**
 * An interface representing an abstract immutable collection of things of type T.
 *
 * The user can only read these values via callback to receive each element.
 */
uint16_t Count_in_ICollection_Indexed_for_Group1Var2(ICollection_Indexed_for_Group1Var2* pICollection_Indexed_for_Group1Var2)
{
  return (pICollection_Indexed_for_Group1Var2->pCount_in_ICollection_Indexed_for_Group1Var2)
         (pICollection_Indexed_for_Group1Var2);
}
void     Foreach_in_ICollection_Indexed_for_Group1Var2(ICollection_Indexed_for_Group1Var2* pICollection_Indexed_for_Group1Var2, IVisitor__for__Indexed_for_Group1Var2* visitor)
{
  (pICollection_Indexed_for_Group1Var2->pForeach_in_ICollection_Indexed_for_Group1Var2)
  (pICollection_Indexed_for_Group1Var2, visitor);
}

void* getParentPointer_in_ICollection_Indexed_for_Group1Var2(ICollection_Indexed_for_Group1Var2* pICollection_Indexed_for_Group1Var2)
{
  return pICollection_Indexed_for_Group1Var2->pParentPointer_in_ICollection_Indexed_for_Group1Var2;
}

void  setParentPointer_in_ICollection_Indexed_for_Group1Var2(ICollection_Indexed_for_Group1Var2* pICollection_Indexed_for_Group1Var2, void* pParentPointer)
{
  pICollection_Indexed_for_Group1Var2->pParentPointer_in_ICollection_Indexed_for_Group1Var2 = pParentPointer;
}

void assignValue_in_ICollection_Indexed_for_Group1Var2(Indexed_for_Group1Var2* item);

void assignValue_in_ICollection_Indexed_for_Group1Var2(Indexed_for_Group1Var2* item)
{
  *((Indexed_for_Group1Var2*)pPointerGlobal1) = *item;
}

boolean ReadOnlyValue_in_ICollection_Indexed_for_Group1Var2(
  ICollection_Indexed_for_Group1Var2 *pICollection_Indexed_for_Group1Var2, Indexed_for_Group1Var2* pValue)
{
  pPointerGlobal1 = pValue;

////        if (this->Count() == 1)
  if (Count_in_ICollection_Indexed_for_Group1Var2(pICollection_Indexed_for_Group1Var2) == 1)
  {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
//void ForeachItem_in_ICollection_Indexed_for_Group1Var2(ICollection_Indexed_for_Group1Var2 *pICollection_Indexed_for_Group1Var2,
//                  void (*fun)(Indexed_for_Group1Var2* item));
    ForeachItem_in_ICollection_Indexed_for_Group1Var2(pICollection_Indexed_for_Group1Var2, assignValue_in_ICollection_Indexed_for_Group1Var2);
    return true;
  }
  else
  {
    return false;
  }
}

void ForeachItem_in_ICollection_Indexed_for_Group1Var2(
  ICollection_Indexed_for_Group1Var2 *pICollection_Indexed_for_Group1Var2,
  void (*fun)(Indexed_for_Group1Var2* item))
{
  FunctorVisitor__for__Indexed_for_Group1Var2 visitor;
//void FunctorVisitor__for__Indexed_for_Group1Var2_in_FunctorVisitor__for__Indexed_for_Group1Var2(__FunctorVisitor__for__Indexed_for_Group1Var2 *pFunctorVisitor__for__Indexed_for_Group1Var2,
//    void (*fun)(Indexed_for_Group1Var2* item));
  FunctorVisitor__for__Indexed_for_Group1Var2_in_FunctorVisitor__for__Indexed_for_Group1Var2(&visitor, fun);
//  (pICollection_Indexed_for_Group1Var2->pForeach_in_ICollection_Indexed_for_Group1Var2)
//       (pICollection_Indexed_for_Group1Var2, &(visitor.iIVisitor__for__Indexed_for_Group1Var2));
  Foreach_in_ICollection_Indexed_for_Group1Var2(pICollection_Indexed_for_Group1Var2, &(visitor.iIVisitor__for__Indexed_for_Group1Var2));
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

void FunctorVisitor__for__Indexed_for_Group1Var2_in_FunctorVisitor__for__Indexed_for_Group1Var2(FunctorVisitor__for__Indexed_for_Group1Var2 *pFunctorVisitor__for__Indexed_for_Group1Var2,
    void (*fun)(Indexed_for_Group1Var2* item))
{
  pFunctorVisitor__for__Indexed_for_Group1Var2->Fun = fun;

  pFunctorVisitor__for__Indexed_for_Group1Var2->iIVisitor__for__Indexed_for_Group1Var2.pOnValue_in_IVisitor__for__Indexed_for_Group1Var2 =
    OnValue_in_FunctorVisitor__for__Indexed_for_Group1Var2_override;

  setParentPointer_in_IVisitor__for__Indexed_for_Group1Var2(&(pFunctorVisitor__for__Indexed_for_Group1Var2->iIVisitor__for__Indexed_for_Group1Var2), pFunctorVisitor__for__Indexed_for_Group1Var2);
}

void OnValue_in_FunctorVisitor__for__Indexed_for_Group1Var2_override(void *pFunctorVisitor__for__Indexed_for_Group1Var2,
    Indexed_for_Group1Var2 *value)
{
  ((FunctorVisitor__for__Indexed_for_Group1Var2*)pFunctorVisitor__for__Indexed_for_Group1Var2)->
  Fun(value);
}
//--------------------------------ICollection_Indexed_for_Group1Var2--------------------------------


