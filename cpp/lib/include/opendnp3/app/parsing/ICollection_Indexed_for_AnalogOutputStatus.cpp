#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "ICollection_Indexed_for_AnalogOutputStatus.h"

//--------------------------------ICollection_Indexed_for_AnalogOutputStatus--------------------------------
////    template<class Fun> void ForeachItem(const Fun& fun) const
void ForeachItem_in_ICollection_Indexed_for_AnalogOutputStatus(ICollection_Indexed_for_AnalogOutputStatus *pICollection_Indexed_for_AnalogOutputStatus, void (*fun)(Indexed_for_AnalogOutputStatus item))
   {
//void FunctorVisitor__for__uint32_in_FunctorVisitor__for__uint32(FunctorVisitor__for__uint32 *pFunctorVisitor__for__uint32,
//    void (*fun)(uint32_t* item));
////        FunctorVisitor<T, Fun> visitor(fun);
 FunctorVisitor_Indexed_for_AnalogOutputStatus visitor;
 FunctorVisitor_Indexed_for_AnalogOutputStatus_in_FunctorVisitor_Indexed_for_AnalogOutputStatus(&visitor, fun);

//void     Foreach_in_ICollection_Indexed_for_AnalogOutputStatus(ICollection_Indexed_for_AnalogOutputStatus*, IVisitor_Indexed_for_AnalogOutputStatus* visitor);
////        this->Foreach(visitor);
  Foreach_in_ICollection_Indexed_for_AnalogOutputStatus(pICollection_Indexed_for_AnalogOutputStatus, &(visitor.iIVisitor_Indexed_for_AnalogOutputStatus));
   }

void* getParentPointer_in_ICollection_Indexed_for_AnalogOutputStatus(ICollection_Indexed_for_AnalogOutputStatus* pICollection_Indexed_for_AnalogOutputStatus)
{
  return pICollection_Indexed_for_AnalogOutputStatus->pParentPointer_in_ICollection_Indexed_for_AnalogOutputStatus;
}
void  setParentPointer_in_ICollection_Indexed_for_AnalogOutputStatus(ICollection_Indexed_for_AnalogOutputStatus* pICollection_Indexed_for_AnalogOutputStatus, void* pParentPointer)
{
  pICollection_Indexed_for_AnalogOutputStatus->pParentPointer_in_ICollection_Indexed_for_AnalogOutputStatus = pParentPointer;
}
uint16_t Count_in_ICollection_Indexed_for_AnalogOutputStatus(ICollection_Indexed_for_AnalogOutputStatus *pICollection_Indexed_for_AnalogOutputStatus)
{
 return (pICollection_Indexed_for_AnalogOutputStatus->pCount_in_ICollection_Indexed_for_AnalogOutputStatus)(pICollection_Indexed_for_AnalogOutputStatus);
}

void  Foreach_in_ICollection_Indexed_for_AnalogOutputStatus(ICollection_Indexed_for_AnalogOutputStatus *pICollection_Indexed_for_AnalogOutputStatus, IVisitor_Indexed_for_AnalogOutputStatus *pIVisitor_Indexed_for_AnalogOutputStatus)
{
  (pICollection_Indexed_for_AnalogOutputStatus->pForeach_in_ICollection_Indexed_for_AnalogOutputStatus)(pICollection_Indexed_for_AnalogOutputStatus, pIVisitor_Indexed_for_AnalogOutputStatus);
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

void* getParentPointer_in_IVisitor_Indexed_for_AnalogOutputStatus(IVisitor_Indexed_for_AnalogOutputStatus* pIVisitor_Indexed_for_AnalogOutputStatus)
{
  return pIVisitor_Indexed_for_AnalogOutputStatus->pParentPointer_in_IVisitor_Indexed_for_AnalogOutputStatus;
}
void  setParentPointer_in_IVisitor_Indexed_for_AnalogOutputStatus(IVisitor_Indexed_for_AnalogOutputStatus* pIVisitor_Indexed_for_AnalogOutputStatus, void* pParentPointer)
{
  pIVisitor_Indexed_for_AnalogOutputStatus->pParentPointer_in_IVisitor_Indexed_for_AnalogOutputStatus = pParentPointer;
}
void OnValue_in_IVisitor_Indexed_for_AnalogOutputStatus(IVisitor_Indexed_for_AnalogOutputStatus *pIVisitor_Indexed_for_AnalogOutputStatus, Indexed_for_AnalogOutputStatus pIndexed_for_AnalogOutputStatus)
{
  (pIVisitor_Indexed_for_AnalogOutputStatus->pOnValue_in_IVisitor_Indexed_for_AnalogOutputStatus)(pIVisitor_Indexed_for_AnalogOutputStatus, pIndexed_for_AnalogOutputStatus);
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

void FunctorVisitor_Indexed_for_AnalogOutputStatus_in_FunctorVisitor_Indexed_for_AnalogOutputStatus(FunctorVisitor_Indexed_for_AnalogOutputStatus *pFunctorVisitor_Indexed_for_AnalogOutputStatus,
    void (*fun)(Indexed_for_AnalogOutputStatus item))
{
  pFunctorVisitor_Indexed_for_AnalogOutputStatus->Fun = fun;

  pFunctorVisitor_Indexed_for_AnalogOutputStatus->iIVisitor_Indexed_for_AnalogOutputStatus.pOnValue_in_IVisitor_Indexed_for_AnalogOutputStatus =
    OnValue_in_FunctorVisitor_Indexed_for_AnalogOutputStatus_override;

  setParentPointer_in_IVisitor_Indexed_for_AnalogOutputStatus(&(pFunctorVisitor_Indexed_for_AnalogOutputStatus->iIVisitor_Indexed_for_AnalogOutputStatus), pFunctorVisitor_Indexed_for_AnalogOutputStatus);
}

void OnValue_in_FunctorVisitor_Indexed_for_AnalogOutputStatus_override(void *pIVisitor_Indexed_for_AnalogOutputStatus, Indexed_for_AnalogOutputStatus value)
{
  FunctorVisitor_Indexed_for_AnalogOutputStatus *parent = (FunctorVisitor_Indexed_for_AnalogOutputStatus *)
           getParentPointer_in_IVisitor_Indexed_for_AnalogOutputStatus((IVisitor_Indexed_for_AnalogOutputStatus *) pIVisitor_Indexed_for_AnalogOutputStatus);
///  parent -> Fun(value);
  OnValue_in_FunctorVisitor_Indexed_for_AnalogOutputStatus(parent, value);
}

void OnValue_in_FunctorVisitor_Indexed_for_AnalogOutputStatus(FunctorVisitor_Indexed_for_AnalogOutputStatus *pFunctorVisitor_Indexed_for_AnalogOutputStatus, Indexed_for_AnalogOutputStatus value)
{
  pFunctorVisitor_Indexed_for_AnalogOutputStatus -> Fun(value);
}

//static void *pPointerGlobal1_in_ReadOnlyValue1;
void assignValue_in_ICollection_Indexed_for_AnalogOutputStatus(Indexed_for_AnalogOutputStatus item);
void assignValue_in_ICollection_Indexed_for_AnalogOutputStatus(Indexed_for_AnalogOutputStatus item)
{
  Indexed_for_AnalogOutputStatus *pValue = (Indexed_for_AnalogOutputStatus *)pPointerGlobal1;
//  *((Indexed_for_AnalogOutputStatus*)pPointerGlobal1) = *item;
  *pValue = item;
}

boolean ReadOnlyValue_in_ICollection_Indexed_for_AnalogOutputStatus(
  ICollection_Indexed_for_AnalogOutputStatus *pICollection_Indexed_for_AnalogOutputStatus, Indexed_for_AnalogOutputStatus *pValue)
{
//  pPointerGlobal1 = pValue;
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

//--------------------------------ICollection_Indexed_for_AnalogOutputStatus--------------------------------
