#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "ICollection_Indexed_for_AnalogOutputDouble64.h"

//--------------------------------ICollection_Indexed_for_AnalogOutputDouble64--------------------------------
////    template<class Fun> void ForeachItem(const Fun& fun) const
void ForeachItem_in_ICollection_Indexed_for_AnalogOutputDouble64(ICollection_Indexed_for_AnalogOutputDouble64 *pICollection_Indexed_for_AnalogOutputDouble64, void (*fun)(Indexed_for_AnalogOutputDouble64 item))
   {
//void FunctorVisitor__for__uint32_in_FunctorVisitor__for__uint32(FunctorVisitor__for__uint32 *pFunctorVisitor__for__uint32,
//    void (*fun)(uint32_t* item));
////        FunctorVisitor<T, Fun> visitor(fun);
 FunctorVisitor_Indexed_for_AnalogOutputDouble64 visitor;
 FunctorVisitor_Indexed_for_AnalogOutputDouble64_in_FunctorVisitor_Indexed_for_AnalogOutputDouble64(&visitor, fun);

//void     Foreach_in_ICollection_Indexed_for_AnalogOutputDouble64(ICollection_Indexed_for_AnalogOutputDouble64*, IVisitor_Indexed_for_AnalogOutputDouble64* visitor);
////        this->Foreach(visitor);
  Foreach_in_ICollection_Indexed_for_AnalogOutputDouble64(pICollection_Indexed_for_AnalogOutputDouble64, &(visitor.iIVisitor_Indexed_for_AnalogOutputDouble64));
   }

void* getParentPointer_in_ICollection_Indexed_for_AnalogOutputDouble64(ICollection_Indexed_for_AnalogOutputDouble64* pICollection_Indexed_for_AnalogOutputDouble64)
{
  return pICollection_Indexed_for_AnalogOutputDouble64->pParentPointer_in_ICollection_Indexed_for_AnalogOutputDouble64;
}
void  setParentPointer_in_ICollection_Indexed_for_AnalogOutputDouble64(ICollection_Indexed_for_AnalogOutputDouble64* pICollection_Indexed_for_AnalogOutputDouble64, void* pParentPointer)
{
  pICollection_Indexed_for_AnalogOutputDouble64->pParentPointer_in_ICollection_Indexed_for_AnalogOutputDouble64 = pParentPointer;
}
uint16_t Count_in_ICollection_Indexed_for_AnalogOutputDouble64(ICollection_Indexed_for_AnalogOutputDouble64 *pICollection_Indexed_for_AnalogOutputDouble64)
{
 return (pICollection_Indexed_for_AnalogOutputDouble64->pCount_in_ICollection_Indexed_for_AnalogOutputDouble64)(pICollection_Indexed_for_AnalogOutputDouble64);
}

void  Foreach_in_ICollection_Indexed_for_AnalogOutputDouble64(ICollection_Indexed_for_AnalogOutputDouble64 *pICollection_Indexed_for_AnalogOutputDouble64, IVisitor_Indexed_for_AnalogOutputDouble64 *pIVisitor_Indexed_for_AnalogOutputDouble64)
{
  (pICollection_Indexed_for_AnalogOutputDouble64->pForeach_in_ICollection_Indexed_for_AnalogOutputDouble64)(pICollection_Indexed_for_AnalogOutputDouble64, pIVisitor_Indexed_for_AnalogOutputDouble64);
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

void* getParentPointer_in_IVisitor_Indexed_for_AnalogOutputDouble64(IVisitor_Indexed_for_AnalogOutputDouble64* pIVisitor_Indexed_for_AnalogOutputDouble64)
{
  return pIVisitor_Indexed_for_AnalogOutputDouble64->pParentPointer_in_IVisitor_Indexed_for_AnalogOutputDouble64;
}
void  setParentPointer_in_IVisitor_Indexed_for_AnalogOutputDouble64(IVisitor_Indexed_for_AnalogOutputDouble64* pIVisitor_Indexed_for_AnalogOutputDouble64, void* pParentPointer)
{
  pIVisitor_Indexed_for_AnalogOutputDouble64->pParentPointer_in_IVisitor_Indexed_for_AnalogOutputDouble64 = pParentPointer;
}
void OnValue_in_IVisitor_Indexed_for_AnalogOutputDouble64(IVisitor_Indexed_for_AnalogOutputDouble64 *pIVisitor_Indexed_for_AnalogOutputDouble64, Indexed_for_AnalogOutputDouble64 pIndexed_for_AnalogOutputDouble64)
{
  (pIVisitor_Indexed_for_AnalogOutputDouble64->pOnValue_in_IVisitor_Indexed_for_AnalogOutputDouble64)(pIVisitor_Indexed_for_AnalogOutputDouble64, pIndexed_for_AnalogOutputDouble64);
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

void FunctorVisitor_Indexed_for_AnalogOutputDouble64_in_FunctorVisitor_Indexed_for_AnalogOutputDouble64(FunctorVisitor_Indexed_for_AnalogOutputDouble64 *pFunctorVisitor_Indexed_for_AnalogOutputDouble64,
    void (*fun)(Indexed_for_AnalogOutputDouble64 item))
{
  pFunctorVisitor_Indexed_for_AnalogOutputDouble64->Fun = fun;

  pFunctorVisitor_Indexed_for_AnalogOutputDouble64->iIVisitor_Indexed_for_AnalogOutputDouble64.pOnValue_in_IVisitor_Indexed_for_AnalogOutputDouble64 =
    OnValue_in_FunctorVisitor_Indexed_for_AnalogOutputDouble64_override;

  setParentPointer_in_IVisitor_Indexed_for_AnalogOutputDouble64(&(pFunctorVisitor_Indexed_for_AnalogOutputDouble64->iIVisitor_Indexed_for_AnalogOutputDouble64), pFunctorVisitor_Indexed_for_AnalogOutputDouble64);
}

void OnValue_in_FunctorVisitor_Indexed_for_AnalogOutputDouble64_override(void *pIVisitor_Indexed_for_AnalogOutputDouble64, Indexed_for_AnalogOutputDouble64 value)
{
  FunctorVisitor_Indexed_for_AnalogOutputDouble64 *parent = (FunctorVisitor_Indexed_for_AnalogOutputDouble64 *)
           getParentPointer_in_IVisitor_Indexed_for_AnalogOutputDouble64((IVisitor_Indexed_for_AnalogOutputDouble64 *) pIVisitor_Indexed_for_AnalogOutputDouble64);
///  parent -> Fun(value);
  OnValue_in_FunctorVisitor_Indexed_for_AnalogOutputDouble64(parent, value);
}

void OnValue_in_FunctorVisitor_Indexed_for_AnalogOutputDouble64(FunctorVisitor_Indexed_for_AnalogOutputDouble64 *pFunctorVisitor_Indexed_for_AnalogOutputDouble64, Indexed_for_AnalogOutputDouble64 value)
{
  pFunctorVisitor_Indexed_for_AnalogOutputDouble64 -> Fun(value);
}

//static void *pPointerGlobal1_in_ReadOnlyValue1;
void assignValue_in_ICollection_Indexed_for_AnalogOutputDouble64(Indexed_for_AnalogOutputDouble64 item);
void assignValue_in_ICollection_Indexed_for_AnalogOutputDouble64(Indexed_for_AnalogOutputDouble64 item)
{
  Indexed_for_AnalogOutputDouble64 *pValue = (Indexed_for_AnalogOutputDouble64 *)pPointerGlobal1;
//  *((Indexed_for_AnalogOutputDouble64*)pPointerGlobal1) = *item;
  *pValue = item;
}

boolean ReadOnlyValue_in_ICollection_Indexed_for_AnalogOutputDouble64(
  ICollection_Indexed_for_AnalogOutputDouble64 *pICollection_Indexed_for_AnalogOutputDouble64, Indexed_for_AnalogOutputDouble64 *pValue)
{
//  pPointerGlobal1 = pValue;
  pPointerGlobal1 = pValue;

////        if (this->Count() == 1)
  if (Count_in_ICollection_Indexed_for_AnalogOutputDouble64(pICollection_Indexed_for_AnalogOutputDouble64) == 1)
  {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
//void ForeachItem_in_ICollection_Indexed_for_AnalogOutputDouble64(ICollection_Indexed_for_AnalogOutputDouble64 *pICollection_Indexed_for_AnalogOutputDouble64,
//                  void (*fun)(Indexed_for_AnalogOutputDouble64* item));
    ForeachItem_in_ICollection_Indexed_for_AnalogOutputDouble64(pICollection_Indexed_for_AnalogOutputDouble64, assignValue_in_ICollection_Indexed_for_AnalogOutputDouble64);
    return true;
  }
  else
  {
    return false;
  }
}

//--------------------------------ICollection_Indexed_for_AnalogOutputDouble64--------------------------------
