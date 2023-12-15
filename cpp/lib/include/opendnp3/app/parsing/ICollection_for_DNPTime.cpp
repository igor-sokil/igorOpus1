#include "header.h"
#include "ICollection_for_DNPTime.h"

//--------------------------------ICollection_for_DNPTime--------------------------------
/**
 * Abstract way of visiting elements of a collection
 *
 */

void* getParentPointer_in_IVisitor_for_DNPTime(IVisitor__for__DNPTime* pIVisitor__for__DNPTime)
{
  return pIVisitor__for__DNPTime->pParentPointer_in_IVisitor__for__DNPTime;
}
void  setParentPointer_in_IVisitor_for_DNPTime(IVisitor__for__DNPTime* pIVisitor__for__DNPTime, void* pParentPointer)
{
  pIVisitor__for__DNPTime->pParentPointer_in_IVisitor__for__DNPTime = pParentPointer;
}

void OnValue_in_IVisitor__for__DNPTime(IVisitor__for__DNPTime *pIVisitor__for__DNPTime, DNPTime* pDNPTime)
{
  (pIVisitor__for__DNPTime->pOnValue_in_IVisitor__for__DNPTime)(pIVisitor__for__DNPTime, pDNPTime);
}

/**
 * An interface representing an abstract immutable collection of things of type T.
 *
 * The user can only read these values via callback to receive each element.
 */
uint16_t Count_in_ICollection_for_DNPTime(ICollection_for_DNPTime* pICollection_DNPTime)
{
  return (pICollection_DNPTime->pCount_in_ICollection_for_DNPTime)
         (pICollection_DNPTime);
}
void     Foreach_in_ICollection_for_DNPTime(ICollection_for_DNPTime* pICollection_DNPTime, IVisitor__for__DNPTime* visitor)
{
  (pICollection_DNPTime->pForeach_in_ICollection_for_DNPTime)
  (pICollection_DNPTime, visitor);
}

void* getParentPointer_in_ICollection_for_DNPTime(ICollection_for_DNPTime* pICollection_DNPTime)
{
  return pICollection_DNPTime->pParentPointer_in_ICollection_for_DNPTime;
}

void  setParentPointer_in_ICollection_for_DNPTime(ICollection_for_DNPTime* pICollection_DNPTime, void* pParentPointer)
{
  pICollection_DNPTime->pParentPointer_in_ICollection_for_DNPTime = pParentPointer;
}

void assignValue_in_ICollection_DNPTime(DNPTime* item);

void assignValue_in_ICollection_DNPTime(DNPTime* item)
{
  *((DNPTime*)pPointerGlobal1) = *item;
}

boolean ReadOnlyValue_in_ICollection_for_DNPTime(
  ICollection_for_DNPTime *pICollection_DNPTime, DNPTime* pValue)
{
  pPointerGlobal1 = pValue;

////        if (this->Count() == 1)
  if (Count_in_ICollection_for_DNPTime(pICollection_DNPTime) == 1)
  {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
//void ForeachItem_in_ICollection_DNPTime(ICollection_DNPTime *pICollection_DNPTime,
//                  void (*fun)(DNPTime* item));
    ForeachItem_in_ICollection_for_DNPTime(pICollection_DNPTime, assignValue_in_ICollection_DNPTime);
    return true;
  }
  else
  {
    return false;
  }
}

void ForeachItem_in_ICollection_for_DNPTime(
  ICollection_for_DNPTime *pICollection_DNPTime,
  void (*fun)(DNPTime* item))
{
  FunctorVisitor__for__DNPTime visitor;
//void FunctorVisitor__for__DNPTime_in_FunctorVisitor__for__DNPTime(__FunctorVisitor__for__DNPTime *pFunctorVisitor__for__DNPTime,
//    void (*fun)(DNPTime* item));
  FunctorVisitor__for__DNPTime_in_FunctorVisitor__for__DNPTime(&visitor, fun);
//  (pICollection_DNPTime->pForeach_in_ICollection_DNPTime)
//       (pICollection_DNPTime, &(visitor.iIVisitor__for__DNPTime));
  Foreach_in_ICollection_for_DNPTime(pICollection_DNPTime, &(visitor.iIVisitor__for__DNPTime));
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

void FunctorVisitor__for__DNPTime_in_FunctorVisitor__for__DNPTime(FunctorVisitor__for__DNPTime *pFunctorVisitor__for__DNPTime,
    void (*fun)(DNPTime* item))
{
  pFunctorVisitor__for__DNPTime->Fun = fun;

  pFunctorVisitor__for__DNPTime->iIVisitor__for__DNPTime.pOnValue_in_IVisitor__for__DNPTime =
    OnValue_in_FunctorVisitor__for__DNPTime_override;

  setParentPointer_in_IVisitor_for_DNPTime(&(pFunctorVisitor__for__DNPTime->iIVisitor__for__DNPTime), pFunctorVisitor__for__DNPTime);
}

void OnValue_in_FunctorVisitor__for__DNPTime_override(void *pFunctorVisitor__for__DNPTime,
    DNPTime *value)
{
  ((FunctorVisitor__for__DNPTime*)pFunctorVisitor__for__DNPTime)->
  Fun(value);
}
//--------------------------------ICollection_for_DNPTime--------------------------------


