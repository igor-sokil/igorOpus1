#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "ICollection_for_DNPTime.h"

//--------------------------------ICollection_for_DNPTime--------------------------------
////    template<class Fun> void ForeachItem(const Fun& fun) const
void ForeachItem_in_ICollection_for_DNPTime(ICollection_for_DNPTime *pICollection_for_DNPTime, void (*fun)(DNPTime item))
   {
//void FunctorVisitor__for__uint32_in_FunctorVisitor__for__uint32(FunctorVisitor__for__uint32 *pFunctorVisitor__for__uint32,
//    void (*fun)(uint32_t* item));
////        FunctorVisitor<T, Fun> visitor(fun);
 FunctorVisitor_for_DNPTime visitor;
 FunctorVisitor_for_DNPTime_in_FunctorVisitor_for_DNPTime(&visitor, fun);

//void     Foreach_in_ICollection_for_DNPTime(ICollection_for_DNPTime*, IVisitor_for_DNPTime* visitor);
////        this->Foreach(visitor);
  Foreach_in_ICollection_for_DNPTime(pICollection_for_DNPTime, &(visitor.iIVisitor_for_DNPTime));
   }

void* getParentPointer_in_ICollection_for_DNPTime(ICollection_for_DNPTime* pICollection_for_DNPTime)
{
  return pICollection_for_DNPTime->pParentPointer_in_ICollection_for_DNPTime;
}
void  setParentPointer_in_ICollection_for_DNPTime(ICollection_for_DNPTime* pICollection_for_DNPTime, void* pParentPointer)
{
  pICollection_for_DNPTime->pParentPointer_in_ICollection_for_DNPTime = pParentPointer;
}
uint16_t Count_in_ICollection_for_DNPTime(ICollection_for_DNPTime *pICollection_for_DNPTime)
{
 return (pICollection_for_DNPTime->pCount_in_ICollection_for_DNPTime)(pICollection_for_DNPTime);
}

void  Foreach_in_ICollection_for_DNPTime(ICollection_for_DNPTime *pICollection_for_DNPTime, IVisitor_for_DNPTime *pIVisitor_for_DNPTime)
{
  (pICollection_for_DNPTime->pForeach_in_ICollection_for_DNPTime)(pICollection_for_DNPTime, pIVisitor_for_DNPTime);
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

void* getParentPointer_in_IVisitor_for_DNPTime(IVisitor_for_DNPTime* pIVisitor_for_DNPTime)
{
  return pIVisitor_for_DNPTime->pParentPointer_in_IVisitor_for_DNPTime;
}
void  setParentPointer_in_IVisitor_for_DNPTime(IVisitor_for_DNPTime* pIVisitor_for_DNPTime, void* pParentPointer)
{
  pIVisitor_for_DNPTime->pParentPointer_in_IVisitor_for_DNPTime = pParentPointer;
}
void OnValue_in_IVisitor_for_DNPTime(IVisitor_for_DNPTime *pIVisitor_for_DNPTime, DNPTime pDNPTime)
{
  (pIVisitor_for_DNPTime->pOnValue_in_IVisitor_for_DNPTime)(pIVisitor_for_DNPTime, pDNPTime);
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

void FunctorVisitor_for_DNPTime_in_FunctorVisitor_for_DNPTime(FunctorVisitor_for_DNPTime *pFunctorVisitor_for_DNPTime,
    void (*fun)(DNPTime item))
{
  pFunctorVisitor_for_DNPTime->Fun = fun;

  pFunctorVisitor_for_DNPTime->iIVisitor_for_DNPTime.pOnValue_in_IVisitor_for_DNPTime =
    OnValue_in_FunctorVisitor_for_DNPTime_override;

  setParentPointer_in_IVisitor_for_DNPTime(&(pFunctorVisitor_for_DNPTime->iIVisitor_for_DNPTime), pFunctorVisitor_for_DNPTime);
}

void OnValue_in_FunctorVisitor_for_DNPTime_override(void *pIVisitor_for_DNPTime, DNPTime value)
{
  FunctorVisitor_for_DNPTime *parent = (FunctorVisitor_for_DNPTime *)
           getParentPointer_in_IVisitor_for_DNPTime((IVisitor_for_DNPTime *) pIVisitor_for_DNPTime);
///  parent -> Fun(value);
  OnValue_in_FunctorVisitor_for_DNPTime(parent, value);
}

void OnValue_in_FunctorVisitor_for_DNPTime(FunctorVisitor_for_DNPTime *pFunctorVisitor_for_DNPTime, DNPTime value)
{
  pFunctorVisitor_for_DNPTime -> Fun(value);
}

//static void *pPointerGlobal1_in_ReadOnlyValue1;
void assignValue_in_ICollection_for_DNPTime(DNPTime item);
void assignValue_in_ICollection_for_DNPTime(DNPTime item)
{
  DNPTime *pValue = (DNPTime *)pPointerGlobal1;
//  *((DNPTime*)pPointerGlobal1) = *item;
  *pValue = item;
}

boolean ReadOnlyValue_in_ICollection_for_DNPTime(
  ICollection_for_DNPTime *pICollection_for_DNPTime, DNPTime *pValue)
{
//  pPointerGlobal1 = pValue;
  pPointerGlobal1 = pValue;

////        if (this->Count() == 1)
  if (Count_in_ICollection_for_DNPTime(pICollection_for_DNPTime) == 1)
  {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
//void ForeachItem_in_ICollection_for_DNPTime(ICollection_for_DNPTime *pICollection_for_DNPTime,
//                  void (*fun)(DNPTime* item));
    ForeachItem_in_ICollection_for_DNPTime(pICollection_for_DNPTime, assignValue_in_ICollection_for_DNPTime);
    return true;
  }
  else
  {
    return false;
  }
}

//--------------------------------ICollection_for_DNPTime--------------------------------
