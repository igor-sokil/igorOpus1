#include "header.h"
#include "ICollection_Indexed_for_AnalogOutputInt16.h"

//--------------------------------ICollection_Indexed_for_AnalogOutputInt16--------------------------------
/**
 * Abstract way of visiting elements of a collection
 *
 */

void* getParentPointer_in_IVisitor__for__Indexed_for_AnalogOutputInt16(IVisitor__for__Indexed_for_AnalogOutputInt16* pIVisitor__for__Indexed_for_AnalogOutputInt16)
{
  return pIVisitor__for__Indexed_for_AnalogOutputInt16->pParentPointer_in_IVisitor__for__Indexed_for_AnalogOutputInt16;
}
void  setParentPointer_in_IVisitor__for__Indexed_for_AnalogOutputInt16(IVisitor__for__Indexed_for_AnalogOutputInt16* pIVisitor__for__Indexed_for_AnalogOutputInt16, void* pParentPointer)
{
  pIVisitor__for__Indexed_for_AnalogOutputInt16->pParentPointer_in_IVisitor__for__Indexed_for_AnalogOutputInt16 = pParentPointer;
}

void OnValue_in_IVisitor__for__Indexed_for_AnalogOutputInt16(IVisitor__for__Indexed_for_AnalogOutputInt16 *pIVisitor__for__Indexed_for_AnalogOutputInt16, Indexed_for_AnalogOutputInt16* pIndexed_for_AnalogOutputInt16)
{
  (pIVisitor__for__Indexed_for_AnalogOutputInt16->pOnValue_in_IVisitor__for__Indexed_for_AnalogOutputInt16)(pIVisitor__for__Indexed_for_AnalogOutputInt16, pIndexed_for_AnalogOutputInt16);
}

/**
 * An interface representing an abstract immutable collection of things of type T.
 *
 * The user can only read these values via callback to receive each element.
 */
uint16_t Count_in_ICollection_Indexed_for_AnalogOutputInt16(ICollection_Indexed_for_AnalogOutputInt16* pICollection_Indexed_for_AnalogOutputInt16)
{
  return (pICollection_Indexed_for_AnalogOutputInt16->pCount_in_ICollection_Indexed_for_AnalogOutputInt16)
         (pICollection_Indexed_for_AnalogOutputInt16);
}
void     Foreach_in_ICollection_Indexed_for_AnalogOutputInt16(ICollection_Indexed_for_AnalogOutputInt16* pICollection_Indexed_for_AnalogOutputInt16, IVisitor__for__Indexed_for_AnalogOutputInt16* visitor)
{
  (pICollection_Indexed_for_AnalogOutputInt16->pForeach_in_ICollection_Indexed_for_AnalogOutputInt16)
  (pICollection_Indexed_for_AnalogOutputInt16, visitor);
}

void* getParentPointer_in_ICollection_Indexed_for_AnalogOutputInt16(ICollection_Indexed_for_AnalogOutputInt16* pICollection_Indexed_for_AnalogOutputInt16)
{
  return pICollection_Indexed_for_AnalogOutputInt16->pParentPointer_in_ICollection_Indexed_for_AnalogOutputInt16;
}

void  setParentPointer_in_ICollection_Indexed_for_AnalogOutputInt16(ICollection_Indexed_for_AnalogOutputInt16* pICollection_Indexed_for_AnalogOutputInt16, void* pParentPointer)
{
  pICollection_Indexed_for_AnalogOutputInt16->pParentPointer_in_ICollection_Indexed_for_AnalogOutputInt16 = pParentPointer;
}

void assignValue_in_ICollection_Indexed_for_AnalogOutputInt16(Indexed_for_AnalogOutputInt16* item);

void assignValue_in_ICollection_Indexed_for_AnalogOutputInt16(Indexed_for_AnalogOutputInt16* item)
{
  *((Indexed_for_AnalogOutputInt16*)pPointerGlobal1) = *item;
}

boolean ReadOnlyValue_in_ICollection_Indexed_for_AnalogOutputInt16(
  ICollection_Indexed_for_AnalogOutputInt16 *pICollection_Indexed_for_AnalogOutputInt16, Indexed_for_AnalogOutputInt16* pValue)
{
  pPointerGlobal1 = pValue;

////        if (this->Count() == 1)
  if (Count_in_ICollection_Indexed_for_AnalogOutputInt16(pICollection_Indexed_for_AnalogOutputInt16) == 1)
  {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
//void ForeachItem_in_ICollection_Indexed_for_AnalogOutputInt16(ICollection_Indexed_for_AnalogOutputInt16 *pICollection_Indexed_for_AnalogOutputInt16,
//                  void (*fun)(Indexed_for_AnalogOutputInt16* item));
    ForeachItem_in_ICollection_Indexed_for_AnalogOutputInt16(pICollection_Indexed_for_AnalogOutputInt16, assignValue_in_ICollection_Indexed_for_AnalogOutputInt16);
    return true;
  }
  else
  {
    return false;
  }
}

void ForeachItem_in_ICollection_Indexed_for_AnalogOutputInt16(
  ICollection_Indexed_for_AnalogOutputInt16 *pICollection_Indexed_for_AnalogOutputInt16,
  void (*fun)(Indexed_for_AnalogOutputInt16* item))
{
  FunctorVisitor__for__Indexed_for_AnalogOutputInt16 visitor;
//void FunctorVisitor__for__Indexed_for_AnalogOutputInt16_in_FunctorVisitor__for__Indexed_for_AnalogOutputInt16(__FunctorVisitor__for__Indexed_for_AnalogOutputInt16 *pFunctorVisitor__for__Indexed_for_AnalogOutputInt16,
//    void (*fun)(Indexed_for_AnalogOutputInt16* item));
  FunctorVisitor__for__Indexed_for_AnalogOutputInt16_in_FunctorVisitor__for__Indexed_for_AnalogOutputInt16(&visitor, fun);
//  (pICollection_Indexed_for_AnalogOutputInt16->pForeach_in_ICollection_Indexed_for_AnalogOutputInt16)
//       (pICollection_Indexed_for_AnalogOutputInt16, &(visitor.iIVisitor__for__Indexed_for_AnalogOutputInt16));
  Foreach_in_ICollection_Indexed_for_AnalogOutputInt16(pICollection_Indexed_for_AnalogOutputInt16, &(visitor.iIVisitor__for__Indexed_for_AnalogOutputInt16));
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

void FunctorVisitor__for__Indexed_for_AnalogOutputInt16_in_FunctorVisitor__for__Indexed_for_AnalogOutputInt16(FunctorVisitor__for__Indexed_for_AnalogOutputInt16 *pFunctorVisitor__for__Indexed_for_AnalogOutputInt16,
    void (*fun)(Indexed_for_AnalogOutputInt16* item))
{
  pFunctorVisitor__for__Indexed_for_AnalogOutputInt16->Fun = fun;

  pFunctorVisitor__for__Indexed_for_AnalogOutputInt16->iIVisitor__for__Indexed_for_AnalogOutputInt16.pOnValue_in_IVisitor__for__Indexed_for_AnalogOutputInt16 =
    OnValue_in_FunctorVisitor__for__Indexed_for_AnalogOutputInt16_override;

  setParentPointer_in_IVisitor__for__Indexed_for_AnalogOutputInt16(&(pFunctorVisitor__for__Indexed_for_AnalogOutputInt16->iIVisitor__for__Indexed_for_AnalogOutputInt16), pFunctorVisitor__for__Indexed_for_AnalogOutputInt16);
}

void OnValue_in_FunctorVisitor__for__Indexed_for_AnalogOutputInt16_override(void *pFunctorVisitor__for__Indexed_for_AnalogOutputInt16,
    Indexed_for_AnalogOutputInt16 *value)
{
  ((FunctorVisitor__for__Indexed_for_AnalogOutputInt16*)pFunctorVisitor__for__Indexed_for_AnalogOutputInt16)->
  Fun(value);
}
//--------------------------------ICollection_Indexed_for_AnalogOutputInt16--------------------------------


