#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "ICollection_Indexed_for_Analog.h"

//--------------------------------ICollection_Indexed_for_Analog--------------------------------
////    template<class Fun> void ForeachItem(const Fun& fun) const
void ForeachItem_in_ICollection_Indexed_for_Analog(ICollection_Indexed_for_Analog *pICollection_Indexed_for_Analog, void (*fun)(Indexed_for_Analog item))
   {
//void FunctorVisitor__for__uint32_in_FunctorVisitor__for__uint32(FunctorVisitor__for__uint32 *pFunctorVisitor__for__uint32,
//    void (*fun)(uint32_t* item));
////        FunctorVisitor<T, Fun> visitor(fun);
 FunctorVisitor_Indexed_for_Analog visitor;
 FunctorVisitor_Indexed_for_Analog_in_FunctorVisitor_Indexed_for_Analog(&visitor, fun);

//void     Foreach_in_ICollection_Indexed_for_Analog(ICollection_Indexed_for_Analog*, IVisitor_Indexed_for_Analog* visitor);
////        this->Foreach(visitor);
  Foreach_in_ICollection_Indexed_for_Analog(pICollection_Indexed_for_Analog, &(visitor.iIVisitor_Indexed_for_Analog));
   }

void* getParentPointer_in_ICollection_Indexed_for_Analog(ICollection_Indexed_for_Analog* pICollection_Indexed_for_Analog)
{
  return pICollection_Indexed_for_Analog->pParentPointer_in_ICollection_Indexed_for_Analog;
}
void  setParentPointer_in_ICollection_Indexed_for_Analog(ICollection_Indexed_for_Analog* pICollection_Indexed_for_Analog, void* pParentPointer)
{
  pICollection_Indexed_for_Analog->pParentPointer_in_ICollection_Indexed_for_Analog = pParentPointer;
}
uint16_t Count_in_ICollection_Indexed_for_Analog(ICollection_Indexed_for_Analog *pICollection_Indexed_for_Analog)
{
 return (pICollection_Indexed_for_Analog->pCount_in_ICollection_Indexed_for_Analog)(pICollection_Indexed_for_Analog);
}

void  Foreach_in_ICollection_Indexed_for_Analog(ICollection_Indexed_for_Analog *pICollection_Indexed_for_Analog, IVisitor_Indexed_for_Analog *pIVisitor_Indexed_for_Analog)
{
  (pICollection_Indexed_for_Analog->pForeach_in_ICollection_Indexed_for_Analog)(pICollection_Indexed_for_Analog, pIVisitor_Indexed_for_Analog);
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

void* getParentPointer_in_IVisitor_Indexed_for_Analog(IVisitor_Indexed_for_Analog* pIVisitor_Indexed_for_Analog)
{
  return pIVisitor_Indexed_for_Analog->pParentPointer_in_IVisitor_Indexed_for_Analog;
}
void  setParentPointer_in_IVisitor_Indexed_for_Analog(IVisitor_Indexed_for_Analog* pIVisitor_Indexed_for_Analog, void* pParentPointer)
{
  pIVisitor_Indexed_for_Analog->pParentPointer_in_IVisitor_Indexed_for_Analog = pParentPointer;
}
void OnValue_in_IVisitor_Indexed_for_Analog(IVisitor_Indexed_for_Analog *pIVisitor_Indexed_for_Analog, Indexed_for_Analog pIndexed_for_Analog)
{
  (pIVisitor_Indexed_for_Analog->pOnValue_in_IVisitor_Indexed_for_Analog)(pIVisitor_Indexed_for_Analog, pIndexed_for_Analog);
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

void FunctorVisitor_Indexed_for_Analog_in_FunctorVisitor_Indexed_for_Analog(FunctorVisitor_Indexed_for_Analog *pFunctorVisitor_Indexed_for_Analog,
    void (*fun)(Indexed_for_Analog item))
{
  pFunctorVisitor_Indexed_for_Analog->Fun = fun;

  pFunctorVisitor_Indexed_for_Analog->iIVisitor_Indexed_for_Analog.pOnValue_in_IVisitor_Indexed_for_Analog =
    OnValue_in_FunctorVisitor_Indexed_for_Analog_override;

  setParentPointer_in_IVisitor_Indexed_for_Analog(&(pFunctorVisitor_Indexed_for_Analog->iIVisitor_Indexed_for_Analog), pFunctorVisitor_Indexed_for_Analog);
}

void OnValue_in_FunctorVisitor_Indexed_for_Analog_override(void *pIVisitor_Indexed_for_Analog, Indexed_for_Analog value)
{
  FunctorVisitor_Indexed_for_Analog *parent = (FunctorVisitor_Indexed_for_Analog *)
           getParentPointer_in_IVisitor_Indexed_for_Analog((IVisitor_Indexed_for_Analog *) pIVisitor_Indexed_for_Analog);
///  parent -> Fun(value);
  OnValue_in_FunctorVisitor_Indexed_for_Analog(parent, value);
}

void OnValue_in_FunctorVisitor_Indexed_for_Analog(FunctorVisitor_Indexed_for_Analog *pFunctorVisitor_Indexed_for_Analog, Indexed_for_Analog value)
{
  pFunctorVisitor_Indexed_for_Analog -> Fun(value);
}

//static void *pPointerGlobal1_in_ReadOnlyValue1;
void assignValue_in_ICollection_Indexed_for_Analog(Indexed_for_Analog item);
void assignValue_in_ICollection_Indexed_for_Analog(Indexed_for_Analog item)
{
  Indexed_for_Analog *pValue = (Indexed_for_Analog *)pPointerGlobal1;
//  *((Indexed_for_Analog*)pPointerGlobal1) = *item;
  *pValue = item;
}

boolean ReadOnlyValue_in_ICollection_Indexed_for_Analog(
  ICollection_Indexed_for_Analog *pICollection_Indexed_for_Analog, Indexed_for_Analog *pValue)
{
//  pPointerGlobal1 = pValue;
  pPointerGlobal1 = pValue;

////        if (this->Count() == 1)
  if (Count_in_ICollection_Indexed_for_Analog(pICollection_Indexed_for_Analog) == 1)
  {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
//void ForeachItem_in_ICollection_Indexed_for_Analog(ICollection_Indexed_for_Analog *pICollection_Indexed_for_Analog,
//                  void (*fun)(Indexed_for_Analog* item));
    ForeachItem_in_ICollection_Indexed_for_Analog(pICollection_Indexed_for_Analog, assignValue_in_ICollection_Indexed_for_Analog);
    return true;
  }
  else
  {
    return false;
  }
}

//--------------------------------ICollection_Indexed_for_Analog--------------------------------
