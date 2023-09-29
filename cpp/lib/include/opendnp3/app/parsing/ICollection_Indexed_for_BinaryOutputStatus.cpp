#include "header.h"
#include "ICollection_Indexed_for_BinaryOutputStatus.h"

//--------------------------------ICollection_Indexed_for_BinaryOutputStatus--------------------------------
/**
 * Abstract way of visiting elements of a collection
 *
 */

void* getParentPointer_in_IVisitor__for__Indexed_for_BinaryOutputStatus(IVisitor__for__Indexed_for_BinaryOutputStatus* pIVisitor__for__Indexed_for_BinaryOutputStatus)
{
  return pIVisitor__for__Indexed_for_BinaryOutputStatus->pParentPointer_in_IVisitor__for__Indexed_for_BinaryOutputStatus;
}
void  setParentPointer_in_IVisitor__for__Indexed_for_BinaryOutputStatus(IVisitor__for__Indexed_for_BinaryOutputStatus* pIVisitor__for__Indexed_for_BinaryOutputStatus, void* pParentPointer)
{
  pIVisitor__for__Indexed_for_BinaryOutputStatus->pParentPointer_in_IVisitor__for__Indexed_for_BinaryOutputStatus = pParentPointer;
}

void OnValue_in_IVisitor__for__Indexed_for_BinaryOutputStatus(IVisitor__for__Indexed_for_BinaryOutputStatus *pIVisitor__for__Indexed_for_BinaryOutputStatus, Indexed_for_BinaryOutputStatus* pIndexed_for_BinaryOutputStatus)
{
  (pIVisitor__for__Indexed_for_BinaryOutputStatus->pOnValue_in_IVisitor__for__Indexed_for_BinaryOutputStatus)(pIVisitor__for__Indexed_for_BinaryOutputStatus, pIndexed_for_BinaryOutputStatus);
}

/**
 * An interface representing an abstract immutable collection of things of type T.
 *
 * The user can only read these values via callback to receive each element.
 */
uint16_t Count_in_ICollection_Indexed_for_BinaryOutputStatus(ICollection_Indexed_for_BinaryOutputStatus* pICollection_Indexed_for_BinaryOutputStatus)
{
  return (pICollection_Indexed_for_BinaryOutputStatus->pCount_in_ICollection_Indexed_for_BinaryOutputStatus)
         (pICollection_Indexed_for_BinaryOutputStatus);
}
void     Foreach_in_ICollection_Indexed_for_BinaryOutputStatus(ICollection_Indexed_for_BinaryOutputStatus* pICollection_Indexed_for_BinaryOutputStatus, IVisitor__for__Indexed_for_BinaryOutputStatus* visitor)
{
  (pICollection_Indexed_for_BinaryOutputStatus->pForeach_in_ICollection_Indexed_for_BinaryOutputStatus)
  (pICollection_Indexed_for_BinaryOutputStatus, visitor);
}

void* getParentPointer_in_ICollection_Indexed_for_BinaryOutputStatus(ICollection_Indexed_for_BinaryOutputStatus* pICollection_Indexed_for_BinaryOutputStatus)
{
  return pICollection_Indexed_for_BinaryOutputStatus->pParentPointer_in_ICollection_Indexed_for_BinaryOutputStatus;
}

void  setParentPointer_in_ICollection_Indexed_for_BinaryOutputStatus(ICollection_Indexed_for_BinaryOutputStatus* pICollection_Indexed_for_BinaryOutputStatus, void* pParentPointer)
{
  pICollection_Indexed_for_BinaryOutputStatus->pParentPointer_in_ICollection_Indexed_for_BinaryOutputStatus = pParentPointer;
}

void assignValue_in_ICollection_Indexed_for_BinaryOutputStatus(Indexed_for_BinaryOutputStatus* item);

void assignValue_in_ICollection_Indexed_for_BinaryOutputStatus(Indexed_for_BinaryOutputStatus* item)
{
  *((Indexed_for_BinaryOutputStatus*)pPointerGlobal1) = *item;
}

boolean ReadOnlyValue_in_ICollection_Indexed_for_BinaryOutputStatus(
  ICollection_Indexed_for_BinaryOutputStatus *pICollection_Indexed_for_BinaryOutputStatus, Indexed_for_BinaryOutputStatus* pValue)
{
  pPointerGlobal1 = pValue;

////        if (this->Count() == 1)
  if (Count_in_ICollection_Indexed_for_BinaryOutputStatus(pICollection_Indexed_for_BinaryOutputStatus) == 1)
  {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
//void ForeachItem_in_ICollection_Indexed_for_BinaryOutputStatus(ICollection_Indexed_for_BinaryOutputStatus *pICollection_Indexed_for_BinaryOutputStatus,
//                  void (*fun)(Indexed_for_BinaryOutputStatus* item));
    ForeachItem_in_ICollection_Indexed_for_BinaryOutputStatus(pICollection_Indexed_for_BinaryOutputStatus, assignValue_in_ICollection_Indexed_for_BinaryOutputStatus);
    return true;
  }
  else
  {
    return false;
  }
}

void ForeachItem_in_ICollection_Indexed_for_BinaryOutputStatus(
  ICollection_Indexed_for_BinaryOutputStatus *pICollection_Indexed_for_BinaryOutputStatus,
  void (*fun)(Indexed_for_BinaryOutputStatus* item))
{
  FunctorVisitor__for__Indexed_for_BinaryOutputStatus visitor;
//void FunctorVisitor__for__Indexed_for_BinaryOutputStatus_in_FunctorVisitor__for__Indexed_for_BinaryOutputStatus(__FunctorVisitor__for__Indexed_for_BinaryOutputStatus *pFunctorVisitor__for__Indexed_for_BinaryOutputStatus,
//    void (*fun)(Indexed_for_BinaryOutputStatus* item));
  FunctorVisitor__for__Indexed_for_BinaryOutputStatus_in_FunctorVisitor__for__Indexed_for_BinaryOutputStatus(&visitor, fun);
//  (pICollection_Indexed_for_BinaryOutputStatus->pForeach_in_ICollection_Indexed_for_BinaryOutputStatus)
//       (pICollection_Indexed_for_BinaryOutputStatus, &(visitor.iIVisitor__for__Indexed_for_BinaryOutputStatus));
  Foreach_in_ICollection_Indexed_for_BinaryOutputStatus(pICollection_Indexed_for_BinaryOutputStatus, &(visitor.iIVisitor__for__Indexed_for_BinaryOutputStatus));
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

void FunctorVisitor__for__Indexed_for_BinaryOutputStatus_in_FunctorVisitor__for__Indexed_for_BinaryOutputStatus(FunctorVisitor__for__Indexed_for_BinaryOutputStatus *pFunctorVisitor__for__Indexed_for_BinaryOutputStatus,
    void (*fun)(Indexed_for_BinaryOutputStatus* item))
{
  pFunctorVisitor__for__Indexed_for_BinaryOutputStatus->Fun = fun;

  pFunctorVisitor__for__Indexed_for_BinaryOutputStatus->iIVisitor__for__Indexed_for_BinaryOutputStatus.pOnValue_in_IVisitor__for__Indexed_for_BinaryOutputStatus =
    OnValue_in_FunctorVisitor__for__Indexed_for_BinaryOutputStatus_override;

  setParentPointer_in_IVisitor__for__Indexed_for_BinaryOutputStatus(&(pFunctorVisitor__for__Indexed_for_BinaryOutputStatus->iIVisitor__for__Indexed_for_BinaryOutputStatus), pFunctorVisitor__for__Indexed_for_BinaryOutputStatus);
}

void OnValue_in_FunctorVisitor__for__Indexed_for_BinaryOutputStatus_override(void *pFunctorVisitor__for__Indexed_for_BinaryOutputStatus,
    Indexed_for_BinaryOutputStatus *value)
{
  ((FunctorVisitor__for__Indexed_for_BinaryOutputStatus*)pFunctorVisitor__for__Indexed_for_BinaryOutputStatus)->
  Fun(value);
}
//--------------------------------ICollection_Indexed_for_BinaryOutputStatus--------------------------------


