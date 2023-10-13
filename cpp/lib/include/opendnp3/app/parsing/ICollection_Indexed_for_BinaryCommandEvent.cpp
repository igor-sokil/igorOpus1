#include "header.h"
#include "ICollection_Indexed_for_BinaryCommandEvent.h"

//--------------------------------ICollection_Indexed_for_BinaryCommandEvent--------------------------------
/**
 * Abstract way of visiting elements of a collection
 *
 */

void* getParentPointer_in_IVisitor__for__Indexed_for_BinaryCommandEvent(IVisitor__for__Indexed_for_BinaryCommandEvent* pIVisitor__for__Indexed_for_BinaryCommandEvent)
{
  return pIVisitor__for__Indexed_for_BinaryCommandEvent->pParentPointer_in_IVisitor__for__Indexed_for_BinaryCommandEvent;
}
void  setParentPointer_in_IVisitor__for__Indexed_for_BinaryCommandEvent(IVisitor__for__Indexed_for_BinaryCommandEvent* pIVisitor__for__Indexed_for_BinaryCommandEvent, void* pParentPointer)
{
  pIVisitor__for__Indexed_for_BinaryCommandEvent->pParentPointer_in_IVisitor__for__Indexed_for_BinaryCommandEvent = pParentPointer;
}

void OnValue_in_IVisitor__for__Indexed_for_BinaryCommandEvent(IVisitor__for__Indexed_for_BinaryCommandEvent *pIVisitor__for__Indexed_for_BinaryCommandEvent, Indexed_for_BinaryCommandEvent* pIndexed_for_BinaryCommandEvent)
{
  (pIVisitor__for__Indexed_for_BinaryCommandEvent->pOnValue_in_IVisitor__for__Indexed_for_BinaryCommandEvent)(pIVisitor__for__Indexed_for_BinaryCommandEvent, pIndexed_for_BinaryCommandEvent);
}

/**
 * An interface representing an abstract immutable collection of things of type T.
 *
 * The user can only read these values via callback to receive each element.
 */
uint16_t Count_in_ICollection_Indexed_for_BinaryCommandEvent(ICollection_Indexed_for_BinaryCommandEvent* pICollection_Indexed_for_BinaryCommandEvent)
{
  return (pICollection_Indexed_for_BinaryCommandEvent->pCount_in_ICollection_Indexed_for_BinaryCommandEvent)
         (pICollection_Indexed_for_BinaryCommandEvent);
}
void     Foreach_in_ICollection_Indexed_for_BinaryCommandEvent(ICollection_Indexed_for_BinaryCommandEvent* pICollection_Indexed_for_BinaryCommandEvent, IVisitor__for__Indexed_for_BinaryCommandEvent* visitor)
{
  (pICollection_Indexed_for_BinaryCommandEvent->pForeach_in_ICollection_Indexed_for_BinaryCommandEvent)
  (pICollection_Indexed_for_BinaryCommandEvent, visitor);
}

void* getParentPointer_in_ICollection_Indexed_for_BinaryCommandEvent(ICollection_Indexed_for_BinaryCommandEvent* pICollection_Indexed_for_BinaryCommandEvent)
{
  return pICollection_Indexed_for_BinaryCommandEvent->pParentPointer_in_ICollection_Indexed_for_BinaryCommandEvent;
}

void  setParentPointer_in_ICollection_Indexed_for_BinaryCommandEvent(ICollection_Indexed_for_BinaryCommandEvent* pICollection_Indexed_for_BinaryCommandEvent, void* pParentPointer)
{
  pICollection_Indexed_for_BinaryCommandEvent->pParentPointer_in_ICollection_Indexed_for_BinaryCommandEvent = pParentPointer;
}

void assignValue_in_ICollection_Indexed_for_BinaryCommandEvent(Indexed_for_BinaryCommandEvent* item);

void assignValue_in_ICollection_Indexed_for_BinaryCommandEvent(Indexed_for_BinaryCommandEvent* item)
{
  *((Indexed_for_BinaryCommandEvent*)pPointerGlobal1) = *item;
}

boolean ReadOnlyValue_in_ICollection_Indexed_for_BinaryCommandEvent(
  ICollection_Indexed_for_BinaryCommandEvent *pICollection_Indexed_for_BinaryCommandEvent, Indexed_for_BinaryCommandEvent* pValue)
{
  pPointerGlobal1 = pValue;

////        if (this->Count() == 1)
  if (Count_in_ICollection_Indexed_for_BinaryCommandEvent(pICollection_Indexed_for_BinaryCommandEvent) == 1)
  {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
//void ForeachItem_in_ICollection_Indexed_for_BinaryCommandEvent(ICollection_Indexed_for_BinaryCommandEvent *pICollection_Indexed_for_BinaryCommandEvent,
//                  void (*fun)(Indexed_for_BinaryCommandEvent* item));
    ForeachItem_in_ICollection_Indexed_for_BinaryCommandEvent(pICollection_Indexed_for_BinaryCommandEvent, assignValue_in_ICollection_Indexed_for_BinaryCommandEvent);
    return true;
  }
  else
  {
    return false;
  }
}

void ForeachItem_in_ICollection_Indexed_for_BinaryCommandEvent(
  ICollection_Indexed_for_BinaryCommandEvent *pICollection_Indexed_for_BinaryCommandEvent,
  void (*fun)(Indexed_for_BinaryCommandEvent* item))
{
  FunctorVisitor__for__Indexed_for_BinaryCommandEvent visitor;
//void FunctorVisitor__for__Indexed_for_BinaryCommandEvent_in_FunctorVisitor__for__Indexed_for_BinaryCommandEvent(__FunctorVisitor__for__Indexed_for_BinaryCommandEvent *pFunctorVisitor__for__Indexed_for_BinaryCommandEvent,
//    void (*fun)(Indexed_for_BinaryCommandEvent* item));
  FunctorVisitor__for__Indexed_for_BinaryCommandEvent_in_FunctorVisitor__for__Indexed_for_BinaryCommandEvent(&visitor, fun);
//  (pICollection_Indexed_for_BinaryCommandEvent->pForeach_in_ICollection_Indexed_for_BinaryCommandEvent)
//       (pICollection_Indexed_for_BinaryCommandEvent, &(visitor.iIVisitor__for__Indexed_for_BinaryCommandEvent));
  Foreach_in_ICollection_Indexed_for_BinaryCommandEvent(pICollection_Indexed_for_BinaryCommandEvent, &(visitor.iIVisitor__for__Indexed_for_BinaryCommandEvent));
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

void FunctorVisitor__for__Indexed_for_BinaryCommandEvent_in_FunctorVisitor__for__Indexed_for_BinaryCommandEvent(FunctorVisitor__for__Indexed_for_BinaryCommandEvent *pFunctorVisitor__for__Indexed_for_BinaryCommandEvent,
    void (*fun)(Indexed_for_BinaryCommandEvent* item))
{
  pFunctorVisitor__for__Indexed_for_BinaryCommandEvent->Fun = fun;

  pFunctorVisitor__for__Indexed_for_BinaryCommandEvent->iIVisitor__for__Indexed_for_BinaryCommandEvent.pOnValue_in_IVisitor__for__Indexed_for_BinaryCommandEvent =
    OnValue_in_FunctorVisitor__for__Indexed_for_BinaryCommandEvent_override;

  setParentPointer_in_IVisitor__for__Indexed_for_BinaryCommandEvent(&(pFunctorVisitor__for__Indexed_for_BinaryCommandEvent->iIVisitor__for__Indexed_for_BinaryCommandEvent), pFunctorVisitor__for__Indexed_for_BinaryCommandEvent);
}

void OnValue_in_FunctorVisitor__for__Indexed_for_BinaryCommandEvent_override(void *pFunctorVisitor__for__Indexed_for_BinaryCommandEvent,
    Indexed_for_BinaryCommandEvent *value)
{
  ((FunctorVisitor__for__Indexed_for_BinaryCommandEvent*)pFunctorVisitor__for__Indexed_for_BinaryCommandEvent)->
  Fun(value);
}
//--------------------------------ICollection_Indexed_for_BinaryCommandEvent--------------------------------


