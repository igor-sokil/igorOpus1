#include "header.h"
#include "ICollection_Indexed_for_AnalogCommandEvent.h"

//--------------------------------ICollection_Indexed_for_AnalogCommandEvent--------------------------------
/**
 * Abstract way of visiting elements of a collection
 *
 */

void* getParentPointer_in_IVisitor__for__Indexed_for_AnalogCommandEvent(IVisitor__for__Indexed_for_AnalogCommandEvent* pIVisitor__for__Indexed_for_AnalogCommandEvent)
{
  return pIVisitor__for__Indexed_for_AnalogCommandEvent->pParentPointer_in_IVisitor__for__Indexed_for_AnalogCommandEvent;
}
void  setParentPointer_in_IVisitor__for__Indexed_for_AnalogCommandEvent(IVisitor__for__Indexed_for_AnalogCommandEvent* pIVisitor__for__Indexed_for_AnalogCommandEvent, void* pParentPointer)
{
  pIVisitor__for__Indexed_for_AnalogCommandEvent->pParentPointer_in_IVisitor__for__Indexed_for_AnalogCommandEvent = pParentPointer;
}

void OnValue_in_IVisitor__for__Indexed_for_AnalogCommandEvent(IVisitor__for__Indexed_for_AnalogCommandEvent *pIVisitor__for__Indexed_for_AnalogCommandEvent, Indexed_for_AnalogCommandEvent* pIndexed_for_AnalogCommandEvent)
{
  (pIVisitor__for__Indexed_for_AnalogCommandEvent->pOnValue_in_IVisitor__for__Indexed_for_AnalogCommandEvent)(pIVisitor__for__Indexed_for_AnalogCommandEvent, pIndexed_for_AnalogCommandEvent);
}

/**
 * An interface representing an abstract immutable collection of things of type T.
 *
 * The user can only read these values via callback to receive each element.
 */
uint16_t Count_in_ICollection_Indexed_for_AnalogCommandEvent(ICollection_Indexed_for_AnalogCommandEvent* pICollection_Indexed_for_AnalogCommandEvent)
{
  return (pICollection_Indexed_for_AnalogCommandEvent->pCount_in_ICollection_Indexed_for_AnalogCommandEvent)
         (pICollection_Indexed_for_AnalogCommandEvent);
}
void     Foreach_in_ICollection_Indexed_for_AnalogCommandEvent(ICollection_Indexed_for_AnalogCommandEvent* pICollection_Indexed_for_AnalogCommandEvent, IVisitor__for__Indexed_for_AnalogCommandEvent* visitor)
{
  (pICollection_Indexed_for_AnalogCommandEvent->pForeach_in_ICollection_Indexed_for_AnalogCommandEvent)
  (pICollection_Indexed_for_AnalogCommandEvent, visitor);
}

void* getParentPointer_in_ICollection_Indexed_for_AnalogCommandEvent(ICollection_Indexed_for_AnalogCommandEvent* pICollection_Indexed_for_AnalogCommandEvent)
{
  return pICollection_Indexed_for_AnalogCommandEvent->pParentPointer_in_ICollection_Indexed_for_AnalogCommandEvent;
}

void  setParentPointer_in_ICollection_Indexed_for_AnalogCommandEvent(ICollection_Indexed_for_AnalogCommandEvent* pICollection_Indexed_for_AnalogCommandEvent, void* pParentPointer)
{
  pICollection_Indexed_for_AnalogCommandEvent->pParentPointer_in_ICollection_Indexed_for_AnalogCommandEvent = pParentPointer;
}

void assignValue_in_ICollection_Indexed_for_AnalogCommandEvent(Indexed_for_AnalogCommandEvent* item);

void assignValue_in_ICollection_Indexed_for_AnalogCommandEvent(Indexed_for_AnalogCommandEvent* item)
{
  *((Indexed_for_AnalogCommandEvent*)pPointerGlobal1) = *item;
}

boolean ReadOnlyValue_in_ICollection_Indexed_for_AnalogCommandEvent(
  ICollection_Indexed_for_AnalogCommandEvent *pICollection_Indexed_for_AnalogCommandEvent, Indexed_for_AnalogCommandEvent* pValue)
{
  pPointerGlobal1 = pValue;

////        if (this->Count() == 1)
  if (Count_in_ICollection_Indexed_for_AnalogCommandEvent(pICollection_Indexed_for_AnalogCommandEvent) == 1)
  {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
//void ForeachItem_in_ICollection_Indexed_for_AnalogCommandEvent(ICollection_Indexed_for_AnalogCommandEvent *pICollection_Indexed_for_AnalogCommandEvent,
//                  void (*fun)(Indexed_for_AnalogCommandEvent* item));
    ForeachItem_in_ICollection_Indexed_for_AnalogCommandEvent(pICollection_Indexed_for_AnalogCommandEvent, assignValue_in_ICollection_Indexed_for_AnalogCommandEvent);
    return true;
  }
  else
  {
    return false;
  }
}

void ForeachItem_in_ICollection_Indexed_for_AnalogCommandEvent(
  ICollection_Indexed_for_AnalogCommandEvent *pICollection_Indexed_for_AnalogCommandEvent,
  void (*fun)(Indexed_for_AnalogCommandEvent* item))
{
  FunctorVisitor__for__Indexed_for_AnalogCommandEvent visitor;
//void FunctorVisitor__for__Indexed_for_AnalogCommandEvent_in_FunctorVisitor__for__Indexed_for_AnalogCommandEvent(__FunctorVisitor__for__Indexed_for_AnalogCommandEvent *pFunctorVisitor__for__Indexed_for_AnalogCommandEvent,
//    void (*fun)(Indexed_for_AnalogCommandEvent* item));
  FunctorVisitor__for__Indexed_for_AnalogCommandEvent_in_FunctorVisitor__for__Indexed_for_AnalogCommandEvent(&visitor, fun);
//  (pICollection_Indexed_for_AnalogCommandEvent->pForeach_in_ICollection_Indexed_for_AnalogCommandEvent)
//       (pICollection_Indexed_for_AnalogCommandEvent, &(visitor.iIVisitor__for__Indexed_for_AnalogCommandEvent));
  Foreach_in_ICollection_Indexed_for_AnalogCommandEvent(pICollection_Indexed_for_AnalogCommandEvent, &(visitor.iIVisitor__for__Indexed_for_AnalogCommandEvent));
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

void FunctorVisitor__for__Indexed_for_AnalogCommandEvent_in_FunctorVisitor__for__Indexed_for_AnalogCommandEvent(FunctorVisitor__for__Indexed_for_AnalogCommandEvent *pFunctorVisitor__for__Indexed_for_AnalogCommandEvent,
    void (*fun)(Indexed_for_AnalogCommandEvent* item))
{
  pFunctorVisitor__for__Indexed_for_AnalogCommandEvent->Fun = fun;

  pFunctorVisitor__for__Indexed_for_AnalogCommandEvent->iIVisitor__for__Indexed_for_AnalogCommandEvent.pOnValue_in_IVisitor__for__Indexed_for_AnalogCommandEvent =
    OnValue_in_FunctorVisitor__for__Indexed_for_AnalogCommandEvent_override;

  setParentPointer_in_IVisitor__for__Indexed_for_AnalogCommandEvent(&(pFunctorVisitor__for__Indexed_for_AnalogCommandEvent->iIVisitor__for__Indexed_for_AnalogCommandEvent), pFunctorVisitor__for__Indexed_for_AnalogCommandEvent);
}

void OnValue_in_FunctorVisitor__for__Indexed_for_AnalogCommandEvent_override(void *pFunctorVisitor__for__Indexed_for_AnalogCommandEvent,
    Indexed_for_AnalogCommandEvent *value)
{
  ((FunctorVisitor__for__Indexed_for_AnalogCommandEvent*)pFunctorVisitor__for__Indexed_for_AnalogCommandEvent)->
  Fun(value);
}
//--------------------------------ICollection_Indexed_for_AnalogCommandEvent--------------------------------


