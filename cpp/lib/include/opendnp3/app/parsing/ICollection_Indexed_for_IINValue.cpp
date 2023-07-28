#include "header.h"
#include "ICollection_Indexed_for_IINValue.h"

//--------------------------------ICollection_Indexed_for_IINValue--------------------------------
/**
 * Abstract way of visiting elements of a collection
 *
 */

void* getParentPointer_in_IVisitor__for__Indexed_for_IINValue(IVisitor__for__Indexed_for_IINValue* pIVisitor__for__Indexed_for_IINValue)
{
  return pIVisitor__for__Indexed_for_IINValue->pParentPointer_in_IVisitor__for__Indexed_for_IINValue;
}
void  setParentPointer_in_IVisitor__for__Indexed_for_IINValue(IVisitor__for__Indexed_for_IINValue* pIVisitor__for__Indexed_for_IINValue, void* pParentPointer)
{
  pIVisitor__for__Indexed_for_IINValue->pParentPointer_in_IVisitor__for__Indexed_for_IINValue = pParentPointer;
}

void OnValue_in_IVisitor__for__Indexed_for_IINValue(IVisitor__for__Indexed_for_IINValue *pIVisitor__for__Indexed_for_IINValue, Indexed_for_IINValue* pIndexed_for_IINValue)
{
  (pIVisitor__for__Indexed_for_IINValue->pOnValue_in_IVisitor__for__Indexed_for_IINValue)(pIVisitor__for__Indexed_for_IINValue, pIndexed_for_IINValue);
}

/**
 * An interface representing an abstract immutable collection of things of type T.
 *
 * The user can only read these values via callback to receive each element.
 */
uint16_t Count_in_ICollection_Indexed_for_IINValue(ICollection_Indexed_for_IINValue* pICollection_Indexed_for_IINValue)
{
  return (pICollection_Indexed_for_IINValue->pCount_in_ICollection_Indexed_for_IINValue)
         (pICollection_Indexed_for_IINValue);
}
void     Foreach_in_ICollection_Indexed_for_IINValue(ICollection_Indexed_for_IINValue* pICollection_Indexed_for_IINValue, IVisitor__for__Indexed_for_IINValue* visitor)
{
  (pICollection_Indexed_for_IINValue->pForeach_in_ICollection_Indexed_for_IINValue)
  (pICollection_Indexed_for_IINValue, visitor);
}

void* getParentPointer_in_ICollection_Indexed_for_IINValue(ICollection_Indexed_for_IINValue* pICollection_Indexed_for_IINValue)
{
  return pICollection_Indexed_for_IINValue->pParentPointer_in_ICollection_Indexed_for_IINValue;
}

void  setParentPointer_in_ICollection_Indexed_for_IINValue(ICollection_Indexed_for_IINValue* pICollection_Indexed_for_IINValue, void* pParentPointer)
{
  pICollection_Indexed_for_IINValue->pParentPointer_in_ICollection_Indexed_for_IINValue = pParentPointer;
}

void assignValue_in_ICollection_Indexed_for_IINValue(Indexed_for_IINValue* item);

void assignValue_in_ICollection_Indexed_for_IINValue(Indexed_for_IINValue* item)
{
  *((Indexed_for_IINValue*)pPointerGlobal1) = *item;
}

boolean ReadOnlyValue_in_ICollection_Indexed_for_IINValue(
  ICollection_Indexed_for_IINValue *pICollection_Indexed_for_IINValue, Indexed_for_IINValue* pValue)
{
  pPointerGlobal1 = pValue;

////        if (this->Count() == 1)
  if (Count_in_ICollection_Indexed_for_IINValue(pICollection_Indexed_for_IINValue) == 1)
  {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
//void ForeachItem_in_ICollection_Indexed_for_IINValue(ICollection_Indexed_for_IINValue *pICollection_Indexed_for_IINValue,
//                  void (*fun)(Indexed_for_IINValue* item));
    ForeachItem_in_ICollection_Indexed_for_IINValue(pICollection_Indexed_for_IINValue, assignValue_in_ICollection_Indexed_for_IINValue);
    return true;
  }
  else
  {
    return false;
  }
}

void ForeachItem_in_ICollection_Indexed_for_IINValue(
  ICollection_Indexed_for_IINValue *pICollection_Indexed_for_IINValue,
  void (*fun)(Indexed_for_IINValue* item))
{
  FunctorVisitor__for__Indexed_for_IINValue visitor;
//void FunctorVisitor__for__Indexed_for_IINValue_in_FunctorVisitor__for__Indexed_for_IINValue(__FunctorVisitor__for__Indexed_for_IINValue *pFunctorVisitor__for__Indexed_for_IINValue,
//    void (*fun)(Indexed_for_IINValue* item));
  FunctorVisitor__for__Indexed_for_IINValue_in_FunctorVisitor__for__Indexed_for_IINValue(&visitor, fun);
//  (pICollection_Indexed_for_IINValue->pForeach_in_ICollection_Indexed_for_IINValue)
//       (pICollection_Indexed_for_IINValue, &(visitor.iIVisitor__for__Indexed_for_IINValue));
  Foreach_in_ICollection_Indexed_for_IINValue(pICollection_Indexed_for_IINValue, &(visitor.iIVisitor__for__Indexed_for_IINValue));
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

void FunctorVisitor__for__Indexed_for_IINValue_in_FunctorVisitor__for__Indexed_for_IINValue(FunctorVisitor__for__Indexed_for_IINValue *pFunctorVisitor__for__Indexed_for_IINValue,
    void (*fun)(Indexed_for_IINValue* item))
{
  pFunctorVisitor__for__Indexed_for_IINValue->Fun = fun;

  pFunctorVisitor__for__Indexed_for_IINValue->iIVisitor__for__Indexed_for_IINValue.pOnValue_in_IVisitor__for__Indexed_for_IINValue =
    OnValue_in_FunctorVisitor__for__Indexed_for_IINValue_override;

  setParentPointer_in_IVisitor__for__Indexed_for_IINValue(&(pFunctorVisitor__for__Indexed_for_IINValue->iIVisitor__for__Indexed_for_IINValue), pFunctorVisitor__for__Indexed_for_IINValue);
}

void OnValue_in_FunctorVisitor__for__Indexed_for_IINValue_override(void *pFunctorVisitor__for__Indexed_for_IINValue,
    Indexed_for_IINValue *value)
{
  ((FunctorVisitor__for__Indexed_for_IINValue*)pFunctorVisitor__for__Indexed_for_IINValue)->
  Fun(value);
}
//--------------------------------ICollection_Indexed_for_IINValue--------------------------------


