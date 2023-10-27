#include "header.h"
#include "ICollection_Indexed_for_Analog.h"

//--------------------------------ICollection_Indexed_for_Analog--------------------------------
/**
 * Abstract way of visiting elements of a collection
 *
 */

void* getParentPointer_in_IVisitor__for__Indexed_for_Analog(IVisitor__for__Indexed_for_Analog* pIVisitor__for__Indexed_for_Analog)
{
  return pIVisitor__for__Indexed_for_Analog->pParentPointer_in_IVisitor__for__Indexed_for_Analog;
}
void  setParentPointer_in_IVisitor__for__Indexed_for_Analog(IVisitor__for__Indexed_for_Analog* pIVisitor__for__Indexed_for_Analog, void* pParentPointer)
{
  pIVisitor__for__Indexed_for_Analog->pParentPointer_in_IVisitor__for__Indexed_for_Analog = pParentPointer;
}

void OnValue_in_IVisitor__for__Indexed_for_Analog(IVisitor__for__Indexed_for_Analog *pIVisitor__for__Indexed_for_Analog, Indexed_for_Analog* pIndexed_for_Analog)
{
  (pIVisitor__for__Indexed_for_Analog->pOnValue_in_IVisitor__for__Indexed_for_Analog)(pIVisitor__for__Indexed_for_Analog, pIndexed_for_Analog);
}

/**
 * An interface representing an abstract immutable collection of things of type T.
 *
 * The user can only read these values via callback to receive each element.
 */
uint16_t Count_in_ICollection_Indexed_for_Analog(ICollection_Indexed_for_Analog* pICollection_Indexed_for_Analog)
{
  return (pICollection_Indexed_for_Analog->pCount_in_ICollection_Indexed_for_Analog)
         (pICollection_Indexed_for_Analog);
}
void     Foreach_in_ICollection_Indexed_for_Analog(ICollection_Indexed_for_Analog* pICollection_Indexed_for_Analog, IVisitor__for__Indexed_for_Analog* visitor)
{
  (pICollection_Indexed_for_Analog->pForeach_in_ICollection_Indexed_for_Analog)
  (pICollection_Indexed_for_Analog, visitor);
}

void* getParentPointer_in_ICollection_Indexed_for_Analog(ICollection_Indexed_for_Analog* pICollection_Indexed_for_Analog)
{
  return pICollection_Indexed_for_Analog->pParentPointer_in_ICollection_Indexed_for_Analog;
}

void  setParentPointer_in_ICollection_Indexed_for_Analog(ICollection_Indexed_for_Analog* pICollection_Indexed_for_Analog, void* pParentPointer)
{
  pICollection_Indexed_for_Analog->pParentPointer_in_ICollection_Indexed_for_Analog = pParentPointer;
}

void assignValue_in_ICollection_Indexed_for_Analog(Indexed_for_Analog* item);

void assignValue_in_ICollection_Indexed_for_Analog(Indexed_for_Analog* item)
{
  *((Indexed_for_Analog*)pPointerGlobal1) = *item;
}

boolean ReadOnlyValue_in_ICollection_Indexed_for_Analog(
  ICollection_Indexed_for_Analog *pICollection_Indexed_for_Analog, Indexed_for_Analog* pValue)
{
  pPointerGlobal1 = pValue;

////        if (this->Count() == 1)
  if (Count_in_ICollection_Indexed_for_Analog(pICollection_Indexed_for_Analog) == 1)
  {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
//void ForeachItem_in_ICollection_Indexed_for_Analog(ICollection_Indexed_for_Analog *pICollection_Indexed_for_Analog,
//                  void (*fun)(Indexed_for_Analog* item));
    ForeachItem_in_ICollection_Indexed_for_Analog(pICollection_Indexed_for_Analog, assignValue_in_ICollection_Indexed_for_Analog);
    return true;
  }
  else
  {
    return false;
  }
}

void ForeachItem_in_ICollection_Indexed_for_Analog(
  ICollection_Indexed_for_Analog *pICollection_Indexed_for_Analog,
  void (*fun)(Indexed_for_Analog* item))
{
  FunctorVisitor__for__Indexed_for_Analog visitor;
//void FunctorVisitor__for__Indexed_for_Analog_in_FunctorVisitor__for__Indexed_for_Analog(__FunctorVisitor__for__Indexed_for_Analog *pFunctorVisitor__for__Indexed_for_Analog,
//    void (*fun)(Indexed_for_Analog* item));
  FunctorVisitor__for__Indexed_for_Analog_in_FunctorVisitor__for__Indexed_for_Analog(&visitor, fun);
//  (pICollection_Indexed_for_Analog->pForeach_in_ICollection_Indexed_for_Analog)
//       (pICollection_Indexed_for_Analog, &(visitor.iIVisitor__for__Indexed_for_Analog));
  Foreach_in_ICollection_Indexed_for_Analog(pICollection_Indexed_for_Analog, &(visitor.iIVisitor__for__Indexed_for_Analog));
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

void FunctorVisitor__for__Indexed_for_Analog_in_FunctorVisitor__for__Indexed_for_Analog(FunctorVisitor__for__Indexed_for_Analog *pFunctorVisitor__for__Indexed_for_Analog,
    void (*fun)(Indexed_for_Analog* item))
{
  pFunctorVisitor__for__Indexed_for_Analog->Fun = fun;

  pFunctorVisitor__for__Indexed_for_Analog->iIVisitor__for__Indexed_for_Analog.pOnValue_in_IVisitor__for__Indexed_for_Analog =
    OnValue_in_FunctorVisitor__for__Indexed_for_Analog_override;

  setParentPointer_in_IVisitor__for__Indexed_for_Analog(&(pFunctorVisitor__for__Indexed_for_Analog->iIVisitor__for__Indexed_for_Analog), pFunctorVisitor__for__Indexed_for_Analog);
}

void OnValue_in_FunctorVisitor__for__Indexed_for_Analog_override(void *pFunctorVisitor__for__Indexed_for_Analog,
    Indexed_for_Analog *value)
{
  ((FunctorVisitor__for__Indexed_for_Analog*)pFunctorVisitor__for__Indexed_for_Analog)->
  Fun(value);
}
//--------------------------------ICollection_Indexed_for_Analog--------------------------------


