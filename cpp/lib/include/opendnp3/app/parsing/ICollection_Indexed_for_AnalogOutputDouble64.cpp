#include "header.h"
#include "ICollection_Indexed_for_AnalogOutputDouble64.h"

//--------------------------------ICollection_Indexed_for_AnalogOutputDouble64--------------------------------
/**
 * Abstract way of visiting elements of a collection
 *
 */

void* getParentPointer_in_IVisitor__for__Indexed_for_AnalogOutputDouble64(IVisitor__for__Indexed_for_AnalogOutputDouble64* pIVisitor__for__Indexed_for_AnalogOutputDouble64)
{
  return pIVisitor__for__Indexed_for_AnalogOutputDouble64->pParentPointer_in_IVisitor__for__Indexed_for_AnalogOutputDouble64;
}
void  setParentPointer_in_IVisitor__for__Indexed_for_AnalogOutputDouble64(IVisitor__for__Indexed_for_AnalogOutputDouble64* pIVisitor__for__Indexed_for_AnalogOutputDouble64, void* pParentPointer)
{
  pIVisitor__for__Indexed_for_AnalogOutputDouble64->pParentPointer_in_IVisitor__for__Indexed_for_AnalogOutputDouble64 = pParentPointer;
}

void OnValue_in_IVisitor__for__Indexed_for_AnalogOutputDouble64(IVisitor__for__Indexed_for_AnalogOutputDouble64 *pIVisitor__for__Indexed_for_AnalogOutputDouble64, Indexed_for_AnalogOutputDouble64* pIndexed_for_AnalogOutputDouble64)
{
  (pIVisitor__for__Indexed_for_AnalogOutputDouble64->pOnValue_in_IVisitor__for__Indexed_for_AnalogOutputDouble64)(pIVisitor__for__Indexed_for_AnalogOutputDouble64, pIndexed_for_AnalogOutputDouble64);
}

/**
 * An interface representing an abstract immutable collection of things of type T.
 *
 * The user can only read these values via callback to receive each element.
 */
uint16_t Count_in_ICollection_Indexed_for_AnalogOutputDouble64(ICollection_Indexed_for_AnalogOutputDouble64* pICollection_Indexed_for_AnalogOutputDouble64)
{
  return (pICollection_Indexed_for_AnalogOutputDouble64->pCount_in_ICollection_Indexed_for_AnalogOutputDouble64)
         (pICollection_Indexed_for_AnalogOutputDouble64);
}
void     Foreach_in_ICollection_Indexed_for_AnalogOutputDouble64(ICollection_Indexed_for_AnalogOutputDouble64* pICollection_Indexed_for_AnalogOutputDouble64, IVisitor__for__Indexed_for_AnalogOutputDouble64* visitor)
{
  (pICollection_Indexed_for_AnalogOutputDouble64->pForeach_in_ICollection_Indexed_for_AnalogOutputDouble64)
  (pICollection_Indexed_for_AnalogOutputDouble64, visitor);
}

void* getParentPointer_in_ICollection_Indexed_for_AnalogOutputDouble64(ICollection_Indexed_for_AnalogOutputDouble64* pICollection_Indexed_for_AnalogOutputDouble64)
{
  return pICollection_Indexed_for_AnalogOutputDouble64->pParentPointer_in_ICollection_Indexed_for_AnalogOutputDouble64;
}

void  setParentPointer_in_ICollection_Indexed_for_AnalogOutputDouble64(ICollection_Indexed_for_AnalogOutputDouble64* pICollection_Indexed_for_AnalogOutputDouble64, void* pParentPointer)
{
  pICollection_Indexed_for_AnalogOutputDouble64->pParentPointer_in_ICollection_Indexed_for_AnalogOutputDouble64 = pParentPointer;
}

void assignValue_in_ICollection_Indexed_for_AnalogOutputDouble64(Indexed_for_AnalogOutputDouble64* item);

void assignValue_in_ICollection_Indexed_for_AnalogOutputDouble64(Indexed_for_AnalogOutputDouble64* item)
{
  *((Indexed_for_AnalogOutputDouble64*)pPointerGlobal1) = *item;
}

boolean ReadOnlyValue_in_ICollection_Indexed_for_AnalogOutputDouble64(
  ICollection_Indexed_for_AnalogOutputDouble64 *pICollection_Indexed_for_AnalogOutputDouble64, Indexed_for_AnalogOutputDouble64* pValue)
{
  pPointerGlobal1 = pValue;

////        if (this->Count() == 1)
  if (Count_in_ICollection_Indexed_for_AnalogOutputDouble64(pICollection_Indexed_for_AnalogOutputDouble64) == 1)
  {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
//void ForeachItem_in_ICollection_Indexed_for_AnalogOutputDouble64(ICollection_Indexed_for_AnalogOutputDouble64 *pICollection_Indexed_for_AnalogOutputDouble64,
//                  void (*fun)(Indexed_for_AnalogOutputDouble64* item));
    ForeachItem_in_ICollection_Indexed_for_AnalogOutputDouble64(pICollection_Indexed_for_AnalogOutputDouble64, assignValue_in_ICollection_Indexed_for_AnalogOutputDouble64);
    return true;
  }
  else
  {
    return false;
  }
}

void ForeachItem_in_ICollection_Indexed_for_AnalogOutputDouble64(
  ICollection_Indexed_for_AnalogOutputDouble64 *pICollection_Indexed_for_AnalogOutputDouble64,
  void (*fun)(Indexed_for_AnalogOutputDouble64* item))
{
  FunctorVisitor__for__Indexed_for_AnalogOutputDouble64 visitor;
//void FunctorVisitor__for__Indexed_for_AnalogOutputDouble64_in_FunctorVisitor__for__Indexed_for_AnalogOutputDouble64(__FunctorVisitor__for__Indexed_for_AnalogOutputDouble64 *pFunctorVisitor__for__Indexed_for_AnalogOutputDouble64,
//    void (*fun)(Indexed_for_AnalogOutputDouble64* item));
  FunctorVisitor__for__Indexed_for_AnalogOutputDouble64_in_FunctorVisitor__for__Indexed_for_AnalogOutputDouble64(&visitor, fun);
//  (pICollection_Indexed_for_AnalogOutputDouble64->pForeach_in_ICollection_Indexed_for_AnalogOutputDouble64)
//       (pICollection_Indexed_for_AnalogOutputDouble64, &(visitor.iIVisitor__for__Indexed_for_AnalogOutputDouble64));
  Foreach_in_ICollection_Indexed_for_AnalogOutputDouble64(pICollection_Indexed_for_AnalogOutputDouble64, &(visitor.iIVisitor__for__Indexed_for_AnalogOutputDouble64));
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

void FunctorVisitor__for__Indexed_for_AnalogOutputDouble64_in_FunctorVisitor__for__Indexed_for_AnalogOutputDouble64(FunctorVisitor__for__Indexed_for_AnalogOutputDouble64 *pFunctorVisitor__for__Indexed_for_AnalogOutputDouble64,
    void (*fun)(Indexed_for_AnalogOutputDouble64* item))
{
  pFunctorVisitor__for__Indexed_for_AnalogOutputDouble64->Fun = fun;

  pFunctorVisitor__for__Indexed_for_AnalogOutputDouble64->iIVisitor__for__Indexed_for_AnalogOutputDouble64.pOnValue_in_IVisitor__for__Indexed_for_AnalogOutputDouble64 =
    OnValue_in_FunctorVisitor__for__Indexed_for_AnalogOutputDouble64_override;

  setParentPointer_in_IVisitor__for__Indexed_for_AnalogOutputDouble64(&(pFunctorVisitor__for__Indexed_for_AnalogOutputDouble64->iIVisitor__for__Indexed_for_AnalogOutputDouble64), pFunctorVisitor__for__Indexed_for_AnalogOutputDouble64);
}

void OnValue_in_FunctorVisitor__for__Indexed_for_AnalogOutputDouble64_override(void *pFunctorVisitor__for__Indexed_for_AnalogOutputDouble64,
    Indexed_for_AnalogOutputDouble64 *value)
{
  ((FunctorVisitor__for__Indexed_for_AnalogOutputDouble64*)pFunctorVisitor__for__Indexed_for_AnalogOutputDouble64)->
  Fun(value);
}
//--------------------------------ICollection_Indexed_for_AnalogOutputDouble64--------------------------------


