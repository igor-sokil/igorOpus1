#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "ICollection_Indexed_for_AnalogOutputInt16.h"

//--------------------------------ICollection_Indexed_for_AnalogOutputInt16--------------------------------
////    template<class Fun> void ForeachItem(const Fun& fun) const
void ForeachItem_in_ICollection_Indexed_for_AnalogOutputInt16(ICollection_Indexed_for_AnalogOutputInt16 *pICollection_Indexed_for_AnalogOutputInt16, void (*fun)(Indexed_for_AnalogOutputInt16 item))
   {
//void FunctorVisitor__for__uint32_in_FunctorVisitor__for__uint32(FunctorVisitor__for__uint32 *pFunctorVisitor__for__uint32,
//    void (*fun)(uint32_t* item));
////        FunctorVisitor<T, Fun> visitor(fun);
 FunctorVisitor_Indexed_for_AnalogOutputInt16 visitor;
 FunctorVisitor_Indexed_for_AnalogOutputInt16_in_FunctorVisitor_Indexed_for_AnalogOutputInt16(&visitor, fun);

//void     Foreach_in_ICollection_Indexed_for_AnalogOutputInt16(ICollection_Indexed_for_AnalogOutputInt16*, IVisitor_Indexed_for_AnalogOutputInt16* visitor);
////        this->Foreach(visitor);
  Foreach_in_ICollection_Indexed_for_AnalogOutputInt16(pICollection_Indexed_for_AnalogOutputInt16, &(visitor.iIVisitor_Indexed_for_AnalogOutputInt16));
   }

void* getParentPointer_in_ICollection_Indexed_for_AnalogOutputInt16(ICollection_Indexed_for_AnalogOutputInt16* pICollection_Indexed_for_AnalogOutputInt16)
{
  return pICollection_Indexed_for_AnalogOutputInt16->pParentPointer_in_ICollection_Indexed_for_AnalogOutputInt16;
}
void  setParentPointer_in_ICollection_Indexed_for_AnalogOutputInt16(ICollection_Indexed_for_AnalogOutputInt16* pICollection_Indexed_for_AnalogOutputInt16, void* pParentPointer)
{
  pICollection_Indexed_for_AnalogOutputInt16->pParentPointer_in_ICollection_Indexed_for_AnalogOutputInt16 = pParentPointer;
}
uint16_t Count_in_ICollection_Indexed_for_AnalogOutputInt16(ICollection_Indexed_for_AnalogOutputInt16 *pICollection_Indexed_for_AnalogOutputInt16)
{
 return (pICollection_Indexed_for_AnalogOutputInt16->pCount_in_ICollection_Indexed_for_AnalogOutputInt16)(pICollection_Indexed_for_AnalogOutputInt16);
}

void  Foreach_in_ICollection_Indexed_for_AnalogOutputInt16(ICollection_Indexed_for_AnalogOutputInt16 *pICollection_Indexed_for_AnalogOutputInt16, IVisitor_Indexed_for_AnalogOutputInt16 *pIVisitor_Indexed_for_AnalogOutputInt16)
{
  (pICollection_Indexed_for_AnalogOutputInt16->pForeach_in_ICollection_Indexed_for_AnalogOutputInt16)(pICollection_Indexed_for_AnalogOutputInt16, pIVisitor_Indexed_for_AnalogOutputInt16);
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

void* getParentPointer_in_IVisitor_Indexed_for_AnalogOutputInt16(IVisitor_Indexed_for_AnalogOutputInt16* pIVisitor_Indexed_for_AnalogOutputInt16)
{
  return pIVisitor_Indexed_for_AnalogOutputInt16->pParentPointer_in_IVisitor_Indexed_for_AnalogOutputInt16;
}
void  setParentPointer_in_IVisitor_Indexed_for_AnalogOutputInt16(IVisitor_Indexed_for_AnalogOutputInt16* pIVisitor_Indexed_for_AnalogOutputInt16, void* pParentPointer)
{
  pIVisitor_Indexed_for_AnalogOutputInt16->pParentPointer_in_IVisitor_Indexed_for_AnalogOutputInt16 = pParentPointer;
}
void OnValue_in_IVisitor_Indexed_for_AnalogOutputInt16(IVisitor_Indexed_for_AnalogOutputInt16 *pIVisitor_Indexed_for_AnalogOutputInt16, Indexed_for_AnalogOutputInt16 pIndexed_for_AnalogOutputInt16)
{
  (pIVisitor_Indexed_for_AnalogOutputInt16->pOnValue_in_IVisitor_Indexed_for_AnalogOutputInt16)(pIVisitor_Indexed_for_AnalogOutputInt16, pIndexed_for_AnalogOutputInt16);
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

void FunctorVisitor_Indexed_for_AnalogOutputInt16_in_FunctorVisitor_Indexed_for_AnalogOutputInt16(FunctorVisitor_Indexed_for_AnalogOutputInt16 *pFunctorVisitor_Indexed_for_AnalogOutputInt16,
    void (*fun)(Indexed_for_AnalogOutputInt16 item))
{
  pFunctorVisitor_Indexed_for_AnalogOutputInt16->Fun = fun;

  pFunctorVisitor_Indexed_for_AnalogOutputInt16->iIVisitor_Indexed_for_AnalogOutputInt16.pOnValue_in_IVisitor_Indexed_for_AnalogOutputInt16 =
    OnValue_in_FunctorVisitor_Indexed_for_AnalogOutputInt16_override;

  setParentPointer_in_IVisitor_Indexed_for_AnalogOutputInt16(&(pFunctorVisitor_Indexed_for_AnalogOutputInt16->iIVisitor_Indexed_for_AnalogOutputInt16), pFunctorVisitor_Indexed_for_AnalogOutputInt16);
}

void OnValue_in_FunctorVisitor_Indexed_for_AnalogOutputInt16_override(void *pIVisitor_Indexed_for_AnalogOutputInt16, Indexed_for_AnalogOutputInt16 value)
{
  FunctorVisitor_Indexed_for_AnalogOutputInt16 *parent = (FunctorVisitor_Indexed_for_AnalogOutputInt16 *)
           getParentPointer_in_IVisitor_Indexed_for_AnalogOutputInt16((IVisitor_Indexed_for_AnalogOutputInt16 *) pIVisitor_Indexed_for_AnalogOutputInt16);
///  parent -> Fun(value);
  OnValue_in_FunctorVisitor_Indexed_for_AnalogOutputInt16(parent, value);
}

void OnValue_in_FunctorVisitor_Indexed_for_AnalogOutputInt16(FunctorVisitor_Indexed_for_AnalogOutputInt16 *pFunctorVisitor_Indexed_for_AnalogOutputInt16, Indexed_for_AnalogOutputInt16 value)
{
  pFunctorVisitor_Indexed_for_AnalogOutputInt16 -> Fun(value);
}

//static void *pPointerGlobal1_in_ReadOnlyValue1;
void assignValue_in_ICollection_Indexed_for_AnalogOutputInt16(Indexed_for_AnalogOutputInt16 item);
void assignValue_in_ICollection_Indexed_for_AnalogOutputInt16(Indexed_for_AnalogOutputInt16 item)
{
  Indexed_for_AnalogOutputInt16 *pValue = (Indexed_for_AnalogOutputInt16 *)pPointerGlobal1;
//  *((Indexed_for_AnalogOutputInt16*)pPointerGlobal1) = *item;
  *pValue = item;
}

boolean ReadOnlyValue_in_ICollection_Indexed_for_AnalogOutputInt16(
  ICollection_Indexed_for_AnalogOutputInt16 *pICollection_Indexed_for_AnalogOutputInt16, Indexed_for_AnalogOutputInt16 *pValue)
{
//  pPointerGlobal1 = pValue;
  pPointerGlobal1 = pValue;

////        if (this->Count() == 1)
  if (Count_in_ICollection_Indexed_for_AnalogOutputInt16(pICollection_Indexed_for_AnalogOutputInt16) == 1)
  {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
//void ForeachItem_in_ICollection_Indexed_for_AnalogOutputInt16(ICollection_Indexed_for_AnalogOutputInt16 *pICollection_Indexed_for_AnalogOutputInt16,
//                  void (*fun)(Indexed_for_AnalogOutputInt16* item));
    ForeachItem_in_ICollection_Indexed_for_AnalogOutputInt16(pICollection_Indexed_for_AnalogOutputInt16, assignValue_in_ICollection_Indexed_for_AnalogOutputInt16);
    return true;
  }
  else
  {
    return false;
  }
}

//--------------------------------ICollection_Indexed_for_AnalogOutputInt16--------------------------------
