#include "header.h"
#include "ICollection_Indexed_for_AnalogOutputStatus.h"

//--------------------------------ICollection_Indexed_for_AnalogOutputStatus--------------------------------
/**
 * Abstract way of visiting elements of a collection
 *
 */

void* getParentPointer_in_IVisitor__for__Indexed_for_AnalogOutputStatus(IVisitor__for__Indexed_for_AnalogOutputStatus* pIVisitor__for__Indexed_for_AnalogOutputStatus)
{
  return pIVisitor__for__Indexed_for_AnalogOutputStatus->pParentPointer_in_IVisitor__for__Indexed_for_AnalogOutputStatus;
}
void  setParentPointer_in_IVisitor__for__Indexed_for_AnalogOutputStatus(IVisitor__for__Indexed_for_AnalogOutputStatus* pIVisitor__for__Indexed_for_AnalogOutputStatus, void* pParentPointer)
{
  pIVisitor__for__Indexed_for_AnalogOutputStatus->pParentPointer_in_IVisitor__for__Indexed_for_AnalogOutputStatus = pParentPointer;
}

void OnValue_in_IVisitor__for__Indexed_for_AnalogOutputStatus(IVisitor__for__Indexed_for_AnalogOutputStatus *pIVisitor__for__Indexed_for_AnalogOutputStatus, Indexed_for_AnalogOutputStatus* pIndexed_for_AnalogOutputStatus)
{
  (pIVisitor__for__Indexed_for_AnalogOutputStatus->pOnValue_in_IVisitor__for__Indexed_for_AnalogOutputStatus)(pIVisitor__for__Indexed_for_AnalogOutputStatus, pIndexed_for_AnalogOutputStatus);
}

/**
 * An interface representing an abstract immutable collection of things of type T.
 *
 * The user can only read these values via callback to receive each element.
 */
uint16_t Count_in_ICollection_Indexed_for_AnalogOutputStatus(ICollection_Indexed_for_AnalogOutputStatus* pICollection_Indexed_for_AnalogOutputStatus)
{
  return (pICollection_Indexed_for_AnalogOutputStatus->pCount_in_ICollection_Indexed_for_AnalogOutputStatus)
         (pICollection_Indexed_for_AnalogOutputStatus);
}
void     Foreach_in_ICollection_Indexed_for_AnalogOutputStatus(ICollection_Indexed_for_AnalogOutputStatus* pICollection_Indexed_for_AnalogOutputStatus, IVisitor__for__Indexed_for_AnalogOutputStatus* visitor)
{
  (pICollection_Indexed_for_AnalogOutputStatus->pForeach_in_ICollection_Indexed_for_AnalogOutputStatus)
  (pICollection_Indexed_for_AnalogOutputStatus, visitor);
}

void* getParentPointer_in_ICollection_Indexed_for_AnalogOutputStatus(ICollection_Indexed_for_AnalogOutputStatus* pICollection_Indexed_for_AnalogOutputStatus)
{
  return pICollection_Indexed_for_AnalogOutputStatus->pParentPointer_in_ICollection_Indexed_for_AnalogOutputStatus;
}

void  setParentPointer_in_ICollection_Indexed_for_AnalogOutputStatus(ICollection_Indexed_for_AnalogOutputStatus* pICollection_Indexed_for_AnalogOutputStatus, void* pParentPointer)
{
  pICollection_Indexed_for_AnalogOutputStatus->pParentPointer_in_ICollection_Indexed_for_AnalogOutputStatus = pParentPointer;
}

void assignValue_in_ICollection_Indexed_for_AnalogOutputStatus(Indexed_for_AnalogOutputStatus* item);

void assignValue_in_ICollection_Indexed_for_AnalogOutputStatus(Indexed_for_AnalogOutputStatus* item)
{
  *((Indexed_for_AnalogOutputStatus*)pPointerGlobal1) = *item;
}

boolean ReadOnlyValue_in_ICollection_Indexed_for_AnalogOutputStatus(
  ICollection_Indexed_for_AnalogOutputStatus *pICollection_Indexed_for_AnalogOutputStatus, Indexed_for_AnalogOutputStatus* pValue)
{
  pPointerGlobal1 = pValue;

////        if (this->Count() == 1)
  if (Count_in_ICollection_Indexed_for_AnalogOutputStatus(pICollection_Indexed_for_AnalogOutputStatus) == 1)
  {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
//void ForeachItem_in_ICollection_Indexed_for_AnalogOutputStatus(ICollection_Indexed_for_AnalogOutputStatus *pICollection_Indexed_for_AnalogOutputStatus,
//                  void (*fun)(Indexed_for_AnalogOutputStatus* item));
    ForeachItem_in_ICollection_Indexed_for_AnalogOutputStatus(pICollection_Indexed_for_AnalogOutputStatus, assignValue_in_ICollection_Indexed_for_AnalogOutputStatus);
    return true;
  }
  else
  {
    return false;
  }
}

void ForeachItem_in_ICollection_Indexed_for_AnalogOutputStatus(
  ICollection_Indexed_for_AnalogOutputStatus *pICollection_Indexed_for_AnalogOutputStatus,
  void (*fun)(Indexed_for_AnalogOutputStatus* item))
{
  FunctorVisitor__for__Indexed_for_AnalogOutputStatus visitor;
//void FunctorVisitor__for__Indexed_for_AnalogOutputStatus_in_FunctorVisitor__for__Indexed_for_AnalogOutputStatus(__FunctorVisitor__for__Indexed_for_AnalogOutputStatus *pFunctorVisitor__for__Indexed_for_AnalogOutputStatus,
//    void (*fun)(Indexed_for_AnalogOutputStatus* item));
  FunctorVisitor__for__Indexed_for_AnalogOutputStatus_in_FunctorVisitor__for__Indexed_for_AnalogOutputStatus(&visitor, fun);
//  (pICollection_Indexed_for_AnalogOutputStatus->pForeach_in_ICollection_Indexed_for_AnalogOutputStatus)
//       (pICollection_Indexed_for_AnalogOutputStatus, &(visitor.iIVisitor__for__Indexed_for_AnalogOutputStatus));
  Foreach_in_ICollection_Indexed_for_AnalogOutputStatus(pICollection_Indexed_for_AnalogOutputStatus, &(visitor.iIVisitor__for__Indexed_for_AnalogOutputStatus));
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

void FunctorVisitor__for__Indexed_for_AnalogOutputStatus_in_FunctorVisitor__for__Indexed_for_AnalogOutputStatus(FunctorVisitor__for__Indexed_for_AnalogOutputStatus *pFunctorVisitor__for__Indexed_for_AnalogOutputStatus,
    void (*fun)(Indexed_for_AnalogOutputStatus* item))
{
  pFunctorVisitor__for__Indexed_for_AnalogOutputStatus->Fun = fun;

  pFunctorVisitor__for__Indexed_for_AnalogOutputStatus->iIVisitor__for__Indexed_for_AnalogOutputStatus.pOnValue_in_IVisitor__for__Indexed_for_AnalogOutputStatus =
    OnValue_in_FunctorVisitor__for__Indexed_for_AnalogOutputStatus_override;

  setParentPointer_in_IVisitor__for__Indexed_for_AnalogOutputStatus(&(pFunctorVisitor__for__Indexed_for_AnalogOutputStatus->iIVisitor__for__Indexed_for_AnalogOutputStatus), pFunctorVisitor__for__Indexed_for_AnalogOutputStatus);
}

void OnValue_in_FunctorVisitor__for__Indexed_for_AnalogOutputStatus_override(void *pFunctorVisitor__for__Indexed_for_AnalogOutputStatus,
    Indexed_for_AnalogOutputStatus *value)
{
  ((FunctorVisitor__for__Indexed_for_AnalogOutputStatus*)pFunctorVisitor__for__Indexed_for_AnalogOutputStatus)->
  Fun(value);
}
//--------------------------------ICollection_Indexed_for_AnalogOutputStatus--------------------------------


