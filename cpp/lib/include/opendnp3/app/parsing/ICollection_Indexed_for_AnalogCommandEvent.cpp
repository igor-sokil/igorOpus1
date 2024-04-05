#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "ICollection_Indexed_for_AnalogCommandEvent.h"

//--------------------------------ICollection_Indexed_for_AnalogCommandEvent--------------------------------
////    template<class Fun> void ForeachItem(const Fun& fun) const
void ForeachItem_in_ICollection_Indexed_for_AnalogCommandEvent(ICollection_Indexed_for_AnalogCommandEvent *pICollection_Indexed_for_AnalogCommandEvent, void (*fun)(Indexed_for_AnalogCommandEvent item))
   {
//void FunctorVisitor__for__uint32_in_FunctorVisitor__for__uint32(FunctorVisitor__for__uint32 *pFunctorVisitor__for__uint32,
//    void (*fun)(uint32_t* item));
////        FunctorVisitor<T, Fun> visitor(fun);
 FunctorVisitor_Indexed_for_AnalogCommandEvent visitor;
 FunctorVisitor_Indexed_for_AnalogCommandEvent_in_FunctorVisitor_Indexed_for_AnalogCommandEvent(&visitor, fun);

//void     Foreach_in_ICollection_Indexed_for_AnalogCommandEvent(ICollection_Indexed_for_AnalogCommandEvent*, IVisitor_Indexed_for_AnalogCommandEvent* visitor);
////        this->Foreach(visitor);
  Foreach_in_ICollection_Indexed_for_AnalogCommandEvent(pICollection_Indexed_for_AnalogCommandEvent, &(visitor.iIVisitor_Indexed_for_AnalogCommandEvent));
   }

void* getParentPointer_in_ICollection_Indexed_for_AnalogCommandEvent(ICollection_Indexed_for_AnalogCommandEvent* pICollection_Indexed_for_AnalogCommandEvent)
{
  return pICollection_Indexed_for_AnalogCommandEvent->pParentPointer_in_ICollection_Indexed_for_AnalogCommandEvent;
}
void  setParentPointer_in_ICollection_Indexed_for_AnalogCommandEvent(ICollection_Indexed_for_AnalogCommandEvent* pICollection_Indexed_for_AnalogCommandEvent, void* pParentPointer)
{
  pICollection_Indexed_for_AnalogCommandEvent->pParentPointer_in_ICollection_Indexed_for_AnalogCommandEvent = pParentPointer;
}
uint16_t Count_in_ICollection_Indexed_for_AnalogCommandEvent(ICollection_Indexed_for_AnalogCommandEvent *pICollection_Indexed_for_AnalogCommandEvent)
{
 return (pICollection_Indexed_for_AnalogCommandEvent->pCount_in_ICollection_Indexed_for_AnalogCommandEvent)(pICollection_Indexed_for_AnalogCommandEvent);
}

void  Foreach_in_ICollection_Indexed_for_AnalogCommandEvent(ICollection_Indexed_for_AnalogCommandEvent *pICollection_Indexed_for_AnalogCommandEvent, IVisitor_Indexed_for_AnalogCommandEvent *pIVisitor_Indexed_for_AnalogCommandEvent)
{
  (pICollection_Indexed_for_AnalogCommandEvent->pForeach_in_ICollection_Indexed_for_AnalogCommandEvent)(pICollection_Indexed_for_AnalogCommandEvent, pIVisitor_Indexed_for_AnalogCommandEvent);
}

/**
 * Abstract way of visiting elements of a collection
 *

template<class T> class IVisitor
{
public:
    virtual void OnValue(const T& value) = 0;
};
 */

void* getParentPointer_in_IVisitor_Indexed_for_AnalogCommandEvent(IVisitor_Indexed_for_AnalogCommandEvent* pIVisitor_Indexed_for_AnalogCommandEvent)
{
  return pIVisitor_Indexed_for_AnalogCommandEvent->pParentPointer_in_IVisitor_Indexed_for_AnalogCommandEvent;
}
void  setParentPointer_in_IVisitor_Indexed_for_AnalogCommandEvent(IVisitor_Indexed_for_AnalogCommandEvent* pIVisitor_Indexed_for_AnalogCommandEvent, void* pParentPointer)
{
  pIVisitor_Indexed_for_AnalogCommandEvent->pParentPointer_in_IVisitor_Indexed_for_AnalogCommandEvent = pParentPointer;
}
void OnValue_in_IVisitor_Indexed_for_AnalogCommandEvent(IVisitor_Indexed_for_AnalogCommandEvent *pIVisitor_Indexed_for_AnalogCommandEvent, Indexed_for_AnalogCommandEvent pIndexed_for_AnalogCommandEvent)
{
  (pIVisitor_Indexed_for_AnalogCommandEvent->pOnValue_in_IVisitor_Indexed_for_AnalogCommandEvent)(pIVisitor_Indexed_for_AnalogCommandEvent, pIndexed_for_AnalogCommandEvent);
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

void FunctorVisitor_Indexed_for_AnalogCommandEvent_in_FunctorVisitor_Indexed_for_AnalogCommandEvent(FunctorVisitor_Indexed_for_AnalogCommandEvent *pFunctorVisitor_Indexed_for_AnalogCommandEvent,
    void (*fun)(Indexed_for_AnalogCommandEvent item))
{
  pFunctorVisitor_Indexed_for_AnalogCommandEvent->Fun = fun;

  pFunctorVisitor_Indexed_for_AnalogCommandEvent->iIVisitor_Indexed_for_AnalogCommandEvent.pOnValue_in_IVisitor_Indexed_for_AnalogCommandEvent =
    OnValue_in_FunctorVisitor_Indexed_for_AnalogCommandEvent_override;

  setParentPointer_in_IVisitor_Indexed_for_AnalogCommandEvent(&(pFunctorVisitor_Indexed_for_AnalogCommandEvent->iIVisitor_Indexed_for_AnalogCommandEvent), pFunctorVisitor_Indexed_for_AnalogCommandEvent);
}

void OnValue_in_FunctorVisitor_Indexed_for_AnalogCommandEvent_override(void *pIVisitor_Indexed_for_AnalogCommandEvent, Indexed_for_AnalogCommandEvent value)
{
  FunctorVisitor_Indexed_for_AnalogCommandEvent *parent = (FunctorVisitor_Indexed_for_AnalogCommandEvent *)
           getParentPointer_in_IVisitor_Indexed_for_AnalogCommandEvent((IVisitor_Indexed_for_AnalogCommandEvent *) pIVisitor_Indexed_for_AnalogCommandEvent);
///  parent -> Fun(value);
  OnValue_in_FunctorVisitor_Indexed_for_AnalogCommandEvent(parent, value);
}

void OnValue_in_FunctorVisitor_Indexed_for_AnalogCommandEvent(FunctorVisitor_Indexed_for_AnalogCommandEvent *pFunctorVisitor_Indexed_for_AnalogCommandEvent, Indexed_for_AnalogCommandEvent value)
{
  pFunctorVisitor_Indexed_for_AnalogCommandEvent -> Fun(value);
}

//static void *pPointerGlobal1_in_ReadOnlyValue1;
void assignValue_in_ICollection_Indexed_for_AnalogCommandEvent(Indexed_for_AnalogCommandEvent item);
void assignValue_in_ICollection_Indexed_for_AnalogCommandEvent(Indexed_for_AnalogCommandEvent item)
{
  Indexed_for_AnalogCommandEvent *pValue = (Indexed_for_AnalogCommandEvent *)pPointerGlobal1;
//  *((Indexed_for_AnalogCommandEvent*)pPointerGlobal1) = *item;
  *pValue = item;
}

boolean ReadOnlyValue_in_ICollection_Indexed_for_AnalogCommandEvent(
  ICollection_Indexed_for_AnalogCommandEvent *pICollection_Indexed_for_AnalogCommandEvent, Indexed_for_AnalogCommandEvent *pValue)
{
//  pPointerGlobal1 = pValue;
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

//--------------------------------ICollection_Indexed_for_AnalogCommandEvent--------------------------------
