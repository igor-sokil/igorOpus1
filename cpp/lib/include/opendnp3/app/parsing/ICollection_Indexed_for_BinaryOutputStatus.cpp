#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "ICollection_Indexed_for_BinaryOutputStatus.h"

//--------------------------------ICollection_Indexed_for_BinaryOutputStatus--------------------------------
////    template<class Fun> void ForeachItem(const Fun& fun) const
void ForeachItem_in_ICollection_Indexed_for_BinaryOutputStatus(ICollection_Indexed_for_BinaryOutputStatus *pICollection_Indexed_for_BinaryOutputStatus, void (*fun)(Indexed_for_BinaryOutputStatus item))
   {
//void FunctorVisitor__for__uint32_in_FunctorVisitor__for__uint32(FunctorVisitor__for__uint32 *pFunctorVisitor__for__uint32,
//    void (*fun)(uint32_t* item));
////        FunctorVisitor<T, Fun> visitor(fun);
 FunctorVisitor_Indexed_for_BinaryOutputStatus visitor;
 FunctorVisitor_Indexed_for_BinaryOutputStatus_in_FunctorVisitor_Indexed_for_BinaryOutputStatus(&visitor, fun);

//void     Foreach_in_ICollection_Indexed_for_BinaryOutputStatus(ICollection_Indexed_for_BinaryOutputStatus*, IVisitor_Indexed_for_BinaryOutputStatus* visitor);
////        this->Foreach(visitor);
  Foreach_in_ICollection_Indexed_for_BinaryOutputStatus(pICollection_Indexed_for_BinaryOutputStatus, &(visitor.iIVisitor_Indexed_for_BinaryOutputStatus));
   }

void* getParentPointer_in_ICollection_Indexed_for_BinaryOutputStatus(ICollection_Indexed_for_BinaryOutputStatus* pICollection_Indexed_for_BinaryOutputStatus)
{
  return pICollection_Indexed_for_BinaryOutputStatus->pParentPointer_in_ICollection_Indexed_for_BinaryOutputStatus;
}
void  setParentPointer_in_ICollection_Indexed_for_BinaryOutputStatus(ICollection_Indexed_for_BinaryOutputStatus* pICollection_Indexed_for_BinaryOutputStatus, void* pParentPointer)
{
  pICollection_Indexed_for_BinaryOutputStatus->pParentPointer_in_ICollection_Indexed_for_BinaryOutputStatus = pParentPointer;
}
uint16_t Count_in_ICollection_Indexed_for_BinaryOutputStatus(ICollection_Indexed_for_BinaryOutputStatus *pICollection_Indexed_for_BinaryOutputStatus)
{
 return (pICollection_Indexed_for_BinaryOutputStatus->pCount_in_ICollection_Indexed_for_BinaryOutputStatus)(pICollection_Indexed_for_BinaryOutputStatus);
}

void  Foreach_in_ICollection_Indexed_for_BinaryOutputStatus(ICollection_Indexed_for_BinaryOutputStatus *pICollection_Indexed_for_BinaryOutputStatus, IVisitor_Indexed_for_BinaryOutputStatus *pIVisitor_Indexed_for_BinaryOutputStatus)
{
  (pICollection_Indexed_for_BinaryOutputStatus->pForeach_in_ICollection_Indexed_for_BinaryOutputStatus)(pICollection_Indexed_for_BinaryOutputStatus, pIVisitor_Indexed_for_BinaryOutputStatus);
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

void* getParentPointer_in_IVisitor_Indexed_for_BinaryOutputStatus(IVisitor_Indexed_for_BinaryOutputStatus* pIVisitor_Indexed_for_BinaryOutputStatus)
{
  return pIVisitor_Indexed_for_BinaryOutputStatus->pParentPointer_in_IVisitor_Indexed_for_BinaryOutputStatus;
}
void  setParentPointer_in_IVisitor_Indexed_for_BinaryOutputStatus(IVisitor_Indexed_for_BinaryOutputStatus* pIVisitor_Indexed_for_BinaryOutputStatus, void* pParentPointer)
{
  pIVisitor_Indexed_for_BinaryOutputStatus->pParentPointer_in_IVisitor_Indexed_for_BinaryOutputStatus = pParentPointer;
}
void OnValue_in_IVisitor_Indexed_for_BinaryOutputStatus(IVisitor_Indexed_for_BinaryOutputStatus *pIVisitor_Indexed_for_BinaryOutputStatus, Indexed_for_BinaryOutputStatus pIndexed_for_BinaryOutputStatus)
{
  (pIVisitor_Indexed_for_BinaryOutputStatus->pOnValue_in_IVisitor_Indexed_for_BinaryOutputStatus)(pIVisitor_Indexed_for_BinaryOutputStatus, pIndexed_for_BinaryOutputStatus);
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

void FunctorVisitor_Indexed_for_BinaryOutputStatus_in_FunctorVisitor_Indexed_for_BinaryOutputStatus(FunctorVisitor_Indexed_for_BinaryOutputStatus *pFunctorVisitor_Indexed_for_BinaryOutputStatus,
    void (*fun)(Indexed_for_BinaryOutputStatus item))
{
  pFunctorVisitor_Indexed_for_BinaryOutputStatus->Fun = fun;

  pFunctorVisitor_Indexed_for_BinaryOutputStatus->iIVisitor_Indexed_for_BinaryOutputStatus.pOnValue_in_IVisitor_Indexed_for_BinaryOutputStatus =
    OnValue_in_FunctorVisitor_Indexed_for_BinaryOutputStatus_override;

  setParentPointer_in_IVisitor_Indexed_for_BinaryOutputStatus(&(pFunctorVisitor_Indexed_for_BinaryOutputStatus->iIVisitor_Indexed_for_BinaryOutputStatus), pFunctorVisitor_Indexed_for_BinaryOutputStatus);
}

void OnValue_in_FunctorVisitor_Indexed_for_BinaryOutputStatus_override(void *pIVisitor_Indexed_for_BinaryOutputStatus, Indexed_for_BinaryOutputStatus value)
{
  FunctorVisitor_Indexed_for_BinaryOutputStatus *parent = (FunctorVisitor_Indexed_for_BinaryOutputStatus *)
           getParentPointer_in_IVisitor_Indexed_for_BinaryOutputStatus((IVisitor_Indexed_for_BinaryOutputStatus *) pIVisitor_Indexed_for_BinaryOutputStatus);
///  parent -> Fun(value);
  OnValue_in_FunctorVisitor_Indexed_for_BinaryOutputStatus(parent, value);
}

void OnValue_in_FunctorVisitor_Indexed_for_BinaryOutputStatus(FunctorVisitor_Indexed_for_BinaryOutputStatus *pFunctorVisitor_Indexed_for_BinaryOutputStatus, Indexed_for_BinaryOutputStatus value)
{
  pFunctorVisitor_Indexed_for_BinaryOutputStatus -> Fun(value);
}

//static void *pPointerGlobal1_in_ReadOnlyValue1;
void assignValue_in_ICollection_Indexed_for_BinaryOutputStatus(Indexed_for_BinaryOutputStatus item);
void assignValue_in_ICollection_Indexed_for_BinaryOutputStatus(Indexed_for_BinaryOutputStatus item)
{
  Indexed_for_BinaryOutputStatus *pValue = (Indexed_for_BinaryOutputStatus *)pPointerGlobal1;
//  *((Indexed_for_BinaryOutputStatus*)pPointerGlobal1) = *item;
  *pValue = item;
}

boolean ReadOnlyValue_in_ICollection_Indexed_for_BinaryOutputStatus(
  ICollection_Indexed_for_BinaryOutputStatus *pICollection_Indexed_for_BinaryOutputStatus, Indexed_for_BinaryOutputStatus *pValue)
{
//  pPointerGlobal1 = pValue;
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

//--------------------------------ICollection_Indexed_for_BinaryOutputStatus--------------------------------
