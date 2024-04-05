#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "ICollection_Indexed_for_BinaryCommandEvent.h"

//--------------------------------ICollection_Indexed_for_BinaryCommandEvent--------------------------------
////    template<class Fun> void ForeachItem(const Fun& fun) const
void ForeachItem_in_ICollection_Indexed_for_BinaryCommandEvent(ICollection_Indexed_for_BinaryCommandEvent *pICollection_Indexed_for_BinaryCommandEvent, void (*fun)(Indexed_for_BinaryCommandEvent item))
   {
//void FunctorVisitor__for__uint32_in_FunctorVisitor__for__uint32(FunctorVisitor__for__uint32 *pFunctorVisitor__for__uint32,
//    void (*fun)(uint32_t* item));
////        FunctorVisitor<T, Fun> visitor(fun);
 FunctorVisitor_Indexed_for_BinaryCommandEvent visitor;
 FunctorVisitor_Indexed_for_BinaryCommandEvent_in_FunctorVisitor_Indexed_for_BinaryCommandEvent(&visitor, fun);

//void     Foreach_in_ICollection_Indexed_for_BinaryCommandEvent(ICollection_Indexed_for_BinaryCommandEvent*, IVisitor_Indexed_for_BinaryCommandEvent* visitor);
////        this->Foreach(visitor);
  Foreach_in_ICollection_Indexed_for_BinaryCommandEvent(pICollection_Indexed_for_BinaryCommandEvent, &(visitor.iIVisitor_Indexed_for_BinaryCommandEvent));
   }

void* getParentPointer_in_ICollection_Indexed_for_BinaryCommandEvent(ICollection_Indexed_for_BinaryCommandEvent* pICollection_Indexed_for_BinaryCommandEvent)
{
  return pICollection_Indexed_for_BinaryCommandEvent->pParentPointer_in_ICollection_Indexed_for_BinaryCommandEvent;
}
void  setParentPointer_in_ICollection_Indexed_for_BinaryCommandEvent(ICollection_Indexed_for_BinaryCommandEvent* pICollection_Indexed_for_BinaryCommandEvent, void* pParentPointer)
{
  pICollection_Indexed_for_BinaryCommandEvent->pParentPointer_in_ICollection_Indexed_for_BinaryCommandEvent = pParentPointer;
}
uint16_t Count_in_ICollection_Indexed_for_BinaryCommandEvent(ICollection_Indexed_for_BinaryCommandEvent *pICollection_Indexed_for_BinaryCommandEvent)
{
 return (pICollection_Indexed_for_BinaryCommandEvent->pCount_in_ICollection_Indexed_for_BinaryCommandEvent)(pICollection_Indexed_for_BinaryCommandEvent);
}

void  Foreach_in_ICollection_Indexed_for_BinaryCommandEvent(ICollection_Indexed_for_BinaryCommandEvent *pICollection_Indexed_for_BinaryCommandEvent, IVisitor_Indexed_for_BinaryCommandEvent *pIVisitor_Indexed_for_BinaryCommandEvent)
{
  (pICollection_Indexed_for_BinaryCommandEvent->pForeach_in_ICollection_Indexed_for_BinaryCommandEvent)(pICollection_Indexed_for_BinaryCommandEvent, pIVisitor_Indexed_for_BinaryCommandEvent);
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

void* getParentPointer_in_IVisitor_Indexed_for_BinaryCommandEvent(IVisitor_Indexed_for_BinaryCommandEvent* pIVisitor_Indexed_for_BinaryCommandEvent)
{
  return pIVisitor_Indexed_for_BinaryCommandEvent->pParentPointer_in_IVisitor_Indexed_for_BinaryCommandEvent;
}
void  setParentPointer_in_IVisitor_Indexed_for_BinaryCommandEvent(IVisitor_Indexed_for_BinaryCommandEvent* pIVisitor_Indexed_for_BinaryCommandEvent, void* pParentPointer)
{
  pIVisitor_Indexed_for_BinaryCommandEvent->pParentPointer_in_IVisitor_Indexed_for_BinaryCommandEvent = pParentPointer;
}
void OnValue_in_IVisitor_Indexed_for_BinaryCommandEvent(IVisitor_Indexed_for_BinaryCommandEvent *pIVisitor_Indexed_for_BinaryCommandEvent, Indexed_for_BinaryCommandEvent pIndexed_for_BinaryCommandEvent)
{
  (pIVisitor_Indexed_for_BinaryCommandEvent->pOnValue_in_IVisitor_Indexed_for_BinaryCommandEvent)(pIVisitor_Indexed_for_BinaryCommandEvent, pIndexed_for_BinaryCommandEvent);
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

void FunctorVisitor_Indexed_for_BinaryCommandEvent_in_FunctorVisitor_Indexed_for_BinaryCommandEvent(FunctorVisitor_Indexed_for_BinaryCommandEvent *pFunctorVisitor_Indexed_for_BinaryCommandEvent,
    void (*fun)(Indexed_for_BinaryCommandEvent item))
{
  pFunctorVisitor_Indexed_for_BinaryCommandEvent->Fun = fun;

  pFunctorVisitor_Indexed_for_BinaryCommandEvent->iIVisitor_Indexed_for_BinaryCommandEvent.pOnValue_in_IVisitor_Indexed_for_BinaryCommandEvent =
    OnValue_in_FunctorVisitor_Indexed_for_BinaryCommandEvent_override;

  setParentPointer_in_IVisitor_Indexed_for_BinaryCommandEvent(&(pFunctorVisitor_Indexed_for_BinaryCommandEvent->iIVisitor_Indexed_for_BinaryCommandEvent), pFunctorVisitor_Indexed_for_BinaryCommandEvent);
}

void OnValue_in_FunctorVisitor_Indexed_for_BinaryCommandEvent_override(void *pIVisitor_Indexed_for_BinaryCommandEvent, Indexed_for_BinaryCommandEvent value)
{
  FunctorVisitor_Indexed_for_BinaryCommandEvent *parent = (FunctorVisitor_Indexed_for_BinaryCommandEvent *)
           getParentPointer_in_IVisitor_Indexed_for_BinaryCommandEvent((IVisitor_Indexed_for_BinaryCommandEvent *) pIVisitor_Indexed_for_BinaryCommandEvent);
///  parent -> Fun(value);
  OnValue_in_FunctorVisitor_Indexed_for_BinaryCommandEvent(parent, value);
}

void OnValue_in_FunctorVisitor_Indexed_for_BinaryCommandEvent(FunctorVisitor_Indexed_for_BinaryCommandEvent *pFunctorVisitor_Indexed_for_BinaryCommandEvent, Indexed_for_BinaryCommandEvent value)
{
  pFunctorVisitor_Indexed_for_BinaryCommandEvent -> Fun(value);
}

//static void *pPointerGlobal1_in_ReadOnlyValue1;
void assignValue_in_ICollection_Indexed_for_BinaryCommandEvent(Indexed_for_BinaryCommandEvent item);
void assignValue_in_ICollection_Indexed_for_BinaryCommandEvent(Indexed_for_BinaryCommandEvent item)
{
  Indexed_for_BinaryCommandEvent *pValue = (Indexed_for_BinaryCommandEvent *)pPointerGlobal1;
//  *((Indexed_for_BinaryCommandEvent*)pPointerGlobal1) = *item;
  *pValue = item;
}

boolean ReadOnlyValue_in_ICollection_Indexed_for_BinaryCommandEvent(
  ICollection_Indexed_for_BinaryCommandEvent *pICollection_Indexed_for_BinaryCommandEvent, Indexed_for_BinaryCommandEvent *pValue)
{
//  pPointerGlobal1 = pValue;
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

//--------------------------------ICollection_Indexed_for_BinaryCommandEvent--------------------------------
