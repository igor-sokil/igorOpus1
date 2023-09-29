#include "header.h"
#include "ICollection_Indexed_for_Binary.h"

//--------------------------------ICollection_Indexed_for_Binary--------------------------------
/**
 * Abstract way of visiting elements of a collection
 *
 */

void* getParentPointer_in_IVisitor__for__Indexed_for_Binary(IVisitor__for__Indexed_for_Binary* pIVisitor__for__Indexed_for_Binary)
{
  return pIVisitor__for__Indexed_for_Binary->pParentPointer_in_IVisitor__for__Indexed_for_Binary;
}
void  setParentPointer_in_IVisitor__for__Indexed_for_Binary(IVisitor__for__Indexed_for_Binary* pIVisitor__for__Indexed_for_Binary, void* pParentPointer)
{
  pIVisitor__for__Indexed_for_Binary->pParentPointer_in_IVisitor__for__Indexed_for_Binary = pParentPointer;
}

void OnValue_in_IVisitor__for__Indexed_for_Binary(IVisitor__for__Indexed_for_Binary *pIVisitor__for__Indexed_for_Binary, Indexed_for_Binary* pIndexed_for_Binary)
{
  (pIVisitor__for__Indexed_for_Binary->pOnValue_in_IVisitor__for__Indexed_for_Binary)(pIVisitor__for__Indexed_for_Binary, pIndexed_for_Binary);
}

/**
 * An interface representing an abstract immutable collection of things of type T.
 *
 * The user can only read these values via callback to receive each element.
 */
uint16_t Count_in_ICollection_Indexed_for_Binary(ICollection_Indexed_for_Binary* pICollection_Indexed_for_Binary)
{
  return (pICollection_Indexed_for_Binary->pCount_in_ICollection_Indexed_for_Binary)
         (pICollection_Indexed_for_Binary);
}
void     Foreach_in_ICollection_Indexed_for_Binary(ICollection_Indexed_for_Binary* pICollection_Indexed_for_Binary, IVisitor__for__Indexed_for_Binary* visitor)
{
  (pICollection_Indexed_for_Binary->pForeach_in_ICollection_Indexed_for_Binary)
  (pICollection_Indexed_for_Binary, visitor);
}

void* getParentPointer_in_ICollection_Indexed_for_Binary(ICollection_Indexed_for_Binary* pICollection_Indexed_for_Binary)
{
  return pICollection_Indexed_for_Binary->pParentPointer_in_ICollection_Indexed_for_Binary;
}

void  setParentPointer_in_ICollection_Indexed_for_Binary(ICollection_Indexed_for_Binary* pICollection_Indexed_for_Binary, void* pParentPointer)
{
  pICollection_Indexed_for_Binary->pParentPointer_in_ICollection_Indexed_for_Binary = pParentPointer;
}

void assignValue_in_ICollection_Indexed_for_Binary(Indexed_for_Binary* item);

void assignValue_in_ICollection_Indexed_for_Binary(Indexed_for_Binary* item)
{
  *((Indexed_for_Binary*)pPointerGlobal1) = *item;
}

boolean ReadOnlyValue_in_ICollection_Indexed_for_Binary(
  ICollection_Indexed_for_Binary *pICollection_Indexed_for_Binary, Indexed_for_Binary* pValue)
{
  pPointerGlobal1 = pValue;

////        if (this->Count() == 1)
  if (Count_in_ICollection_Indexed_for_Binary(pICollection_Indexed_for_Binary) == 1)
  {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
//void ForeachItem_in_ICollection_Indexed_for_Binary(ICollection_Indexed_for_Binary *pICollection_Indexed_for_Binary,
//                  void (*fun)(Indexed_for_Binary* item));
    ForeachItem_in_ICollection_Indexed_for_Binary(pICollection_Indexed_for_Binary, assignValue_in_ICollection_Indexed_for_Binary);
    return true;
  }
  else
  {
    return false;
  }
}

void ForeachItem_in_ICollection_Indexed_for_Binary(
  ICollection_Indexed_for_Binary *pICollection_Indexed_for_Binary,
  void (*fun)(Indexed_for_Binary* item))
{
  FunctorVisitor__for__Indexed_for_Binary visitor;
//void FunctorVisitor__for__Indexed_for_Binary_in_FunctorVisitor__for__Indexed_for_Binary(__FunctorVisitor__for__Indexed_for_Binary *pFunctorVisitor__for__Indexed_for_Binary,
//    void (*fun)(Indexed_for_Binary* item));
  FunctorVisitor__for__Indexed_for_Binary_in_FunctorVisitor__for__Indexed_for_Binary(&visitor, fun);
//  (pICollection_Indexed_for_Binary->pForeach_in_ICollection_Indexed_for_Binary)
//       (pICollection_Indexed_for_Binary, &(visitor.iIVisitor__for__Indexed_for_Binary));
  Foreach_in_ICollection_Indexed_for_Binary(pICollection_Indexed_for_Binary, &(visitor.iIVisitor__for__Indexed_for_Binary));
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

void FunctorVisitor__for__Indexed_for_Binary_in_FunctorVisitor__for__Indexed_for_Binary(FunctorVisitor__for__Indexed_for_Binary *pFunctorVisitor__for__Indexed_for_Binary,
    void (*fun)(Indexed_for_Binary* item))
{
  pFunctorVisitor__for__Indexed_for_Binary->Fun = fun;

  pFunctorVisitor__for__Indexed_for_Binary->iIVisitor__for__Indexed_for_Binary.pOnValue_in_IVisitor__for__Indexed_for_Binary =
    OnValue_in_FunctorVisitor__for__Indexed_for_Binary_override;

  setParentPointer_in_IVisitor__for__Indexed_for_Binary(&(pFunctorVisitor__for__Indexed_for_Binary->iIVisitor__for__Indexed_for_Binary), pFunctorVisitor__for__Indexed_for_Binary);
}

void OnValue_in_FunctorVisitor__for__Indexed_for_Binary_override(void *pFunctorVisitor__for__Indexed_for_Binary,
    Indexed_for_Binary *value)
{
  ((FunctorVisitor__for__Indexed_for_Binary*)pFunctorVisitor__for__Indexed_for_Binary)->
  Fun(value);
}
//--------------------------------ICollection_Indexed_for_Binary--------------------------------


