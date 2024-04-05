#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "ICollection_Indexed_for_IINValue.h"

//--------------------------------ICollection_Indexed_for_IINValue--------------------------------
////    template<class Fun> void ForeachItem(const Fun& fun) const
void ForeachItem_in_ICollection_Indexed_for_IINValue(ICollection_Indexed_for_IINValue *pICollection_Indexed_for_IINValue, void (*fun)(Indexed_for_IINValue item))
   {
//void FunctorVisitor__for__uint32_in_FunctorVisitor__for__uint32(FunctorVisitor__for__uint32 *pFunctorVisitor__for__uint32,
//    void (*fun)(uint32_t* item));
////        FunctorVisitor<T, Fun> visitor(fun);
 FunctorVisitor_Indexed_for_IINValue visitor;
 FunctorVisitor_Indexed_for_IINValue_in_FunctorVisitor_Indexed_for_IINValue(&visitor, fun);

//void     Foreach_in_ICollection_Indexed_for_IINValue(ICollection_Indexed_for_IINValue*, IVisitor_Indexed_for_IINValue* visitor);
////        this->Foreach(visitor);
  Foreach_in_ICollection_Indexed_for_IINValue(pICollection_Indexed_for_IINValue, &(visitor.iIVisitor_Indexed_for_IINValue));
   }

void* getParentPointer_in_ICollection_Indexed_for_IINValue(ICollection_Indexed_for_IINValue* pICollection_Indexed_for_IINValue)
{
  return pICollection_Indexed_for_IINValue->pParentPointer_in_ICollection_Indexed_for_IINValue;
}
void  setParentPointer_in_ICollection_Indexed_for_IINValue(ICollection_Indexed_for_IINValue* pICollection_Indexed_for_IINValue, void* pParentPointer)
{
  pICollection_Indexed_for_IINValue->pParentPointer_in_ICollection_Indexed_for_IINValue = pParentPointer;
}
uint16_t Count_in_ICollection_Indexed_for_IINValue(ICollection_Indexed_for_IINValue *pICollection_Indexed_for_IINValue)
{
 return (pICollection_Indexed_for_IINValue->pCount_in_ICollection_Indexed_for_IINValue)(pICollection_Indexed_for_IINValue);
}

void  Foreach_in_ICollection_Indexed_for_IINValue(ICollection_Indexed_for_IINValue *pICollection_Indexed_for_IINValue, IVisitor_Indexed_for_IINValue *pIVisitor_Indexed_for_IINValue)
{
  (pICollection_Indexed_for_IINValue->pForeach_in_ICollection_Indexed_for_IINValue)(pICollection_Indexed_for_IINValue, pIVisitor_Indexed_for_IINValue);
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

void* getParentPointer_in_IVisitor_Indexed_for_IINValue(IVisitor_Indexed_for_IINValue* pIVisitor_Indexed_for_IINValue)
{
  return pIVisitor_Indexed_for_IINValue->pParentPointer_in_IVisitor_Indexed_for_IINValue;
}
void  setParentPointer_in_IVisitor_Indexed_for_IINValue(IVisitor_Indexed_for_IINValue* pIVisitor_Indexed_for_IINValue, void* pParentPointer)
{
  pIVisitor_Indexed_for_IINValue->pParentPointer_in_IVisitor_Indexed_for_IINValue = pParentPointer;
}
void OnValue_in_IVisitor_Indexed_for_IINValue(IVisitor_Indexed_for_IINValue *pIVisitor_Indexed_for_IINValue, Indexed_for_IINValue pIndexed_for_IINValue)
{
  (pIVisitor_Indexed_for_IINValue->pOnValue_in_IVisitor_Indexed_for_IINValue)(pIVisitor_Indexed_for_IINValue, pIndexed_for_IINValue);
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

void FunctorVisitor_Indexed_for_IINValue_in_FunctorVisitor_Indexed_for_IINValue(FunctorVisitor_Indexed_for_IINValue *pFunctorVisitor_Indexed_for_IINValue,
    void (*fun)(Indexed_for_IINValue item))
{
  pFunctorVisitor_Indexed_for_IINValue->Fun = fun;

  pFunctorVisitor_Indexed_for_IINValue->iIVisitor_Indexed_for_IINValue.pOnValue_in_IVisitor_Indexed_for_IINValue =
    OnValue_in_FunctorVisitor_Indexed_for_IINValue_override;

  setParentPointer_in_IVisitor_Indexed_for_IINValue(&(pFunctorVisitor_Indexed_for_IINValue->iIVisitor_Indexed_for_IINValue), pFunctorVisitor_Indexed_for_IINValue);
}

void OnValue_in_FunctorVisitor_Indexed_for_IINValue_override(void *pIVisitor_Indexed_for_IINValue, Indexed_for_IINValue value)
{
  FunctorVisitor_Indexed_for_IINValue *parent = (FunctorVisitor_Indexed_for_IINValue *)
           getParentPointer_in_IVisitor_Indexed_for_IINValue((IVisitor_Indexed_for_IINValue *) pIVisitor_Indexed_for_IINValue);
///  parent -> Fun(value);
  OnValue_in_FunctorVisitor_Indexed_for_IINValue(parent, value);
}

void OnValue_in_FunctorVisitor_Indexed_for_IINValue(FunctorVisitor_Indexed_for_IINValue *pFunctorVisitor_Indexed_for_IINValue, Indexed_for_IINValue value)
{
  pFunctorVisitor_Indexed_for_IINValue -> Fun(value);
}

//static void *pPointerGlobal1_in_ReadOnlyValue1;
void assignValue_in_ICollection_Indexed_for_IINValue(Indexed_for_IINValue item);
void assignValue_in_ICollection_Indexed_for_IINValue(Indexed_for_IINValue item)
{
  Indexed_for_IINValue *pValue = (Indexed_for_IINValue *)pPointerGlobal1;
//  *((Indexed_for_IINValue*)pPointerGlobal1) = *item;
  *pValue = item;
}

boolean ReadOnlyValue_in_ICollection_Indexed_for_IINValue(
  ICollection_Indexed_for_IINValue *pICollection_Indexed_for_IINValue, Indexed_for_IINValue *pValue)
{
//  pPointerGlobal1 = pValue;
  pPointerGlobal1 = pValue;

////        if (this->Count() == 1)
  if (Count_in_ICollection_Indexed_for_IINValue(pICollection_Indexed_for_IINValue) == 1)
  {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
//void ForeachItem_in_ICollection_Indexed_for_IINValue(ICollection_Indexed_for_IINValue *pICollection_Indexed_for_IINValue,
//                  void (*fun)(Indexed_for_IINValue* item));
    ForeachItem_in_ICollection_Indexed_for_IINValue(pICollection_Indexed_for_IINValue, assignValue_in_ICollection_Indexed_for_IINValue);
    return true;
  }
  else
  {
    return false;
  }
}

//--------------------------------ICollection_Indexed_for_IINValue--------------------------------
