#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "ICollection_for_uint16.h"

//--------------------------------ICollection_for_uint16--------------------------------
////    template<class Fun> void ForeachItem(const Fun& fun) const
void ForeachItem_in_ICollection_for_uint16(ICollection_for_uint16 *pICollection_for_uint16, void (*fun)(uint16_t item))
   {
//void FunctorVisitor__for__uint32_in_FunctorVisitor__for__uint32(FunctorVisitor__for__uint32 *pFunctorVisitor__for__uint32,
//    void (*fun)(uint32_t* item));
////        FunctorVisitor<T, Fun> visitor(fun);
 FunctorVisitor_for_uint16 visitor;
 FunctorVisitor_for_uint16_in_FunctorVisitor_for_uint16(&visitor, fun);

//void     Foreach_in_ICollection_for_uint16(ICollection_for_uint16*, IVisitor_for_uint16* visitor);
////        this->Foreach(visitor);
  Foreach_in_ICollection_for_uint16(pICollection_for_uint16, &(visitor.iIVisitor_for_uint16));
   }

void* getParentPointer_in_ICollection_for_uint16(ICollection_for_uint16* pICollection_for_uint16)
{
  return pICollection_for_uint16->pParentPointer_in_ICollection_for_uint16;
}
void  setParentPointer_in_ICollection_for_uint16(ICollection_for_uint16* pICollection_for_uint16, void* pParentPointer)
{
  pICollection_for_uint16->pParentPointer_in_ICollection_for_uint16 = pParentPointer;
}
uint16_t Count_in_ICollection_for_uint16(ICollection_for_uint16 *pICollection_for_uint16)
{
 return (pICollection_for_uint16->pCount_in_ICollection_for_uint16)(pICollection_for_uint16);
}

void  Foreach_in_ICollection_for_uint16(ICollection_for_uint16 *pICollection_for_uint16, IVisitor_for_uint16 *pIVisitor_for_uint16)
{
  (pICollection_for_uint16->pForeach_in_ICollection_for_uint16)(pICollection_for_uint16, pIVisitor_for_uint16);
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

void* getParentPointer_in_IVisitor_for_uint16(IVisitor_for_uint16* pIVisitor_for_uint16)
{
  return pIVisitor_for_uint16->pParentPointer_in_IVisitor_for_uint16;
}
void  setParentPointer_in_IVisitor_for_uint16(IVisitor_for_uint16* pIVisitor_for_uint16, void* pParentPointer)
{
  pIVisitor_for_uint16->pParentPointer_in_IVisitor_for_uint16 = pParentPointer;
}
void OnValue_in_IVisitor_for_uint16(IVisitor_for_uint16 *pIVisitor_for_uint16, uint16_t puint16)
{
  (pIVisitor_for_uint16->pOnValue_in_IVisitor_for_uint16)(pIVisitor_for_uint16, puint16);
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

void FunctorVisitor_for_uint16_in_FunctorVisitor_for_uint16(FunctorVisitor_for_uint16 *pFunctorVisitor_for_uint16,
    void (*fun)(uint16_t item))
{
  pFunctorVisitor_for_uint16->Fun = fun;

  pFunctorVisitor_for_uint16->iIVisitor_for_uint16.pOnValue_in_IVisitor_for_uint16 =
    OnValue_in_FunctorVisitor_for_uint16_override;

  setParentPointer_in_IVisitor_for_uint16(&(pFunctorVisitor_for_uint16->iIVisitor_for_uint16), pFunctorVisitor_for_uint16);
}

void OnValue_in_FunctorVisitor_for_uint16_override(void *pIVisitor_for_uint16, uint16_t value)
{
  FunctorVisitor_for_uint16 *parent = (FunctorVisitor_for_uint16 *)
           getParentPointer_in_IVisitor_for_uint16((IVisitor_for_uint16 *) pIVisitor_for_uint16);
///  parent -> Fun(value);
  OnValue_in_FunctorVisitor_for_uint16(parent, value);
}

void OnValue_in_FunctorVisitor_for_uint16(FunctorVisitor_for_uint16 *pFunctorVisitor_for_uint16, uint16_t value)
{
  pFunctorVisitor_for_uint16 -> Fun(value);
}

//static void *pPointerGlobal1_in_ReadOnlyValue1;
void assignValue_in_ICollection_for_uint16(uint16_t item);
void assignValue_in_ICollection_for_uint16(uint16_t item)
{
  uint16_t *pValue = (uint16_t *)pPointerGlobal1;
//  *((uint16*)pPointerGlobal1) = *item;
  *pValue = item;
}

boolean ReadOnlyValue_in_ICollection_for_uint16(
  ICollection_for_uint16 *pICollection_for_uint16, uint16_t *pValue)
{
//  pPointerGlobal1 = pValue;
  pPointerGlobal1 = pValue;

////        if (this->Count() == 1)
  if (Count_in_ICollection_for_uint16(pICollection_for_uint16) == 1)
  {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
//void ForeachItem_in_ICollection_for_uint16(ICollection_for_uint16 *pICollection_for_uint16,
//                  void (*fun)(uint16* item));
    ForeachItem_in_ICollection_for_uint16(pICollection_for_uint16, assignValue_in_ICollection_for_uint16);
    return true;
  }
  else
  {
    return false;
  }
}

//--------------------------------ICollection_for_uint16--------------------------------
