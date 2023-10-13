#include "header.h"
#include "ICollection_Indexed_for_DoubleBitBinary.h"

//--------------------------------ICollection_Indexed_for_DoubleBitBinary--------------------------------
/**
 * Abstract way of visiting elements of a collection
 *
 */

void* getParentPointer_in_IVisitor__for__Indexed_for_DoubleBitBinary(IVisitor__for__Indexed_for_DoubleBitBinary* pIVisitor__for__Indexed_for_DoubleBitBinary)
{
  return pIVisitor__for__Indexed_for_DoubleBitBinary->pParentPointer_in_IVisitor__for__Indexed_for_DoubleBitBinary;
}
void  setParentPointer_in_IVisitor__for__Indexed_for_DoubleBitBinary(IVisitor__for__Indexed_for_DoubleBitBinary* pIVisitor__for__Indexed_for_DoubleBitBinary, void* pParentPointer)
{
  pIVisitor__for__Indexed_for_DoubleBitBinary->pParentPointer_in_IVisitor__for__Indexed_for_DoubleBitBinary = pParentPointer;
}

void OnValue_in_IVisitor__for__Indexed_for_DoubleBitBinary(IVisitor__for__Indexed_for_DoubleBitBinary *pIVisitor__for__Indexed_for_DoubleBitBinary, Indexed_for_DoubleBitBinary* pIndexed_for_DoubleBitBinary)
{
  (pIVisitor__for__Indexed_for_DoubleBitBinary->pOnValue_in_IVisitor__for__Indexed_for_DoubleBitBinary)(pIVisitor__for__Indexed_for_DoubleBitBinary, pIndexed_for_DoubleBitBinary);
}

/**
 * An interface representing an abstract immutable collection of things of type T.
 *
 * The user can only read these values via callback to receive each element.
 */
uint16_t Count_in_ICollection_Indexed_for_DoubleBitBinary(ICollection_Indexed_for_DoubleBitBinary* pICollection_Indexed_for_DoubleBitBinary)
{
  return (pICollection_Indexed_for_DoubleBitBinary->pCount_in_ICollection_Indexed_for_DoubleBitBinary)
         (pICollection_Indexed_for_DoubleBitBinary);
}
void     Foreach_in_ICollection_Indexed_for_DoubleBitBinary(ICollection_Indexed_for_DoubleBitBinary* pICollection_Indexed_for_DoubleBitBinary, IVisitor__for__Indexed_for_DoubleBitBinary* visitor)
{
  (pICollection_Indexed_for_DoubleBitBinary->pForeach_in_ICollection_Indexed_for_DoubleBitBinary)
  (pICollection_Indexed_for_DoubleBitBinary, visitor);
}

void* getParentPointer_in_ICollection_Indexed_for_DoubleBitBinary(ICollection_Indexed_for_DoubleBitBinary* pICollection_Indexed_for_DoubleBitBinary)
{
  return pICollection_Indexed_for_DoubleBitBinary->pParentPointer_in_ICollection_Indexed_for_DoubleBitBinary;
}

void  setParentPointer_in_ICollection_Indexed_for_DoubleBitBinary(ICollection_Indexed_for_DoubleBitBinary* pICollection_Indexed_for_DoubleBitBinary, void* pParentPointer)
{
  pICollection_Indexed_for_DoubleBitBinary->pParentPointer_in_ICollection_Indexed_for_DoubleBitBinary = pParentPointer;
}

void assignValue_in_ICollection_Indexed_for_DoubleBitBinary(Indexed_for_DoubleBitBinary* item);

void assignValue_in_ICollection_Indexed_for_DoubleBitBinary(Indexed_for_DoubleBitBinary* item)
{
  *((Indexed_for_DoubleBitBinary*)pPointerGlobal1) = *item;
}

boolean ReadOnlyValue_in_ICollection_Indexed_for_DoubleBitBinary(
  ICollection_Indexed_for_DoubleBitBinary *pICollection_Indexed_for_DoubleBitBinary, Indexed_for_DoubleBitBinary* pValue)
{
  pPointerGlobal1 = pValue;

////        if (this->Count() == 1)
  if (Count_in_ICollection_Indexed_for_DoubleBitBinary(pICollection_Indexed_for_DoubleBitBinary) == 1)
  {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
//void ForeachItem_in_ICollection_Indexed_for_DoubleBitBinary(ICollection_Indexed_for_DoubleBitBinary *pICollection_Indexed_for_DoubleBitBinary,
//                  void (*fun)(Indexed_for_DoubleBitBinary* item));
    ForeachItem_in_ICollection_Indexed_for_DoubleBitBinary(pICollection_Indexed_for_DoubleBitBinary, assignValue_in_ICollection_Indexed_for_DoubleBitBinary);
    return true;
  }
  else
  {
    return false;
  }
}

void ForeachItem_in_ICollection_Indexed_for_DoubleBitBinary(
  ICollection_Indexed_for_DoubleBitBinary *pICollection_Indexed_for_DoubleBitBinary,
  void (*fun)(Indexed_for_DoubleBitBinary* item))
{
  FunctorVisitor__for__Indexed_for_DoubleBitBinary visitor;
//void FunctorVisitor__for__Indexed_for_DoubleBitBinary_in_FunctorVisitor__for__Indexed_for_DoubleBitBinary(__FunctorVisitor__for__Indexed_for_DoubleBitBinary *pFunctorVisitor__for__Indexed_for_DoubleBitBinary,
//    void (*fun)(Indexed_for_DoubleBitBinary* item));
  FunctorVisitor__for__Indexed_for_DoubleBitBinary_in_FunctorVisitor__for__Indexed_for_DoubleBitBinary(&visitor, fun);
//  (pICollection_Indexed_for_DoubleBitBinary->pForeach_in_ICollection_Indexed_for_DoubleBitBinary)
//       (pICollection_Indexed_for_DoubleBitBinary, &(visitor.iIVisitor__for__Indexed_for_DoubleBitBinary));
  Foreach_in_ICollection_Indexed_for_DoubleBitBinary(pICollection_Indexed_for_DoubleBitBinary, &(visitor.iIVisitor__for__Indexed_for_DoubleBitBinary));
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

void FunctorVisitor__for__Indexed_for_DoubleBitBinary_in_FunctorVisitor__for__Indexed_for_DoubleBitBinary(FunctorVisitor__for__Indexed_for_DoubleBitBinary *pFunctorVisitor__for__Indexed_for_DoubleBitBinary,
    void (*fun)(Indexed_for_DoubleBitBinary* item))
{
  pFunctorVisitor__for__Indexed_for_DoubleBitBinary->Fun = fun;

  pFunctorVisitor__for__Indexed_for_DoubleBitBinary->iIVisitor__for__Indexed_for_DoubleBitBinary.pOnValue_in_IVisitor__for__Indexed_for_DoubleBitBinary =
    OnValue_in_FunctorVisitor__for__Indexed_for_DoubleBitBinary_override;

  setParentPointer_in_IVisitor__for__Indexed_for_DoubleBitBinary(&(pFunctorVisitor__for__Indexed_for_DoubleBitBinary->iIVisitor__for__Indexed_for_DoubleBitBinary), pFunctorVisitor__for__Indexed_for_DoubleBitBinary);
}

void OnValue_in_FunctorVisitor__for__Indexed_for_DoubleBitBinary_override(void *pFunctorVisitor__for__Indexed_for_DoubleBitBinary,
    Indexed_for_DoubleBitBinary *value)
{
  ((FunctorVisitor__for__Indexed_for_DoubleBitBinary*)pFunctorVisitor__for__Indexed_for_DoubleBitBinary)->
  Fun(value);
}
//--------------------------------ICollection_Indexed_for_DoubleBitBinary--------------------------------


