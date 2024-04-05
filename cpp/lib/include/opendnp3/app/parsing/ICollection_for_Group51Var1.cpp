#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "ICollection_for_Group51Var1.h"

//--------------------------------ICollection_for_Group51Var1--------------------------------
////    template<class Fun> void ForeachItem(const Fun& fun) const
void ForeachItem_in_ICollection_for_Group51Var1(ICollection_for_Group51Var1 *pICollection_for_Group51Var1, void (*fun)(Group51Var1 item))
   {
//void FunctorVisitor__for__uint32_in_FunctorVisitor__for__uint32(FunctorVisitor__for__uint32 *pFunctorVisitor__for__uint32,
//    void (*fun)(uint32_t* item));
////        FunctorVisitor<T, Fun> visitor(fun);
 FunctorVisitor_for_Group51Var1 visitor;
 FunctorVisitor_for_Group51Var1_in_FunctorVisitor_for_Group51Var1(&visitor, fun);

//void     Foreach_in_ICollection_for_Group51Var1(ICollection_for_Group51Var1*, IVisitor_for_Group51Var1* visitor);
////        this->Foreach(visitor);
  Foreach_in_ICollection_for_Group51Var1(pICollection_for_Group51Var1, &(visitor.iIVisitor_for_Group51Var1));
   }

void* getParentPointer_in_ICollection_for_Group51Var1(ICollection_for_Group51Var1* pICollection_for_Group51Var1)
{
  return pICollection_for_Group51Var1->pParentPointer_in_ICollection_for_Group51Var1;
}
void  setParentPointer_in_ICollection_for_Group51Var1(ICollection_for_Group51Var1* pICollection_for_Group51Var1, void* pParentPointer)
{
  pICollection_for_Group51Var1->pParentPointer_in_ICollection_for_Group51Var1 = pParentPointer;
}
uint16_t Count_in_ICollection_for_Group51Var1(ICollection_for_Group51Var1 *pICollection_for_Group51Var1)
{
 return (pICollection_for_Group51Var1->pCount_in_ICollection_for_Group51Var1)(pICollection_for_Group51Var1);
}

void  Foreach_in_ICollection_for_Group51Var1(ICollection_for_Group51Var1 *pICollection_for_Group51Var1, IVisitor_for_Group51Var1 *pIVisitor_for_Group51Var1)
{
  (pICollection_for_Group51Var1->pForeach_in_ICollection_for_Group51Var1)(pICollection_for_Group51Var1, pIVisitor_for_Group51Var1);
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

void* getParentPointer_in_IVisitor_for_Group51Var1(IVisitor_for_Group51Var1* pIVisitor_for_Group51Var1)
{
  return pIVisitor_for_Group51Var1->pParentPointer_in_IVisitor_for_Group51Var1;
}
void  setParentPointer_in_IVisitor_for_Group51Var1(IVisitor_for_Group51Var1* pIVisitor_for_Group51Var1, void* pParentPointer)
{
  pIVisitor_for_Group51Var1->pParentPointer_in_IVisitor_for_Group51Var1 = pParentPointer;
}
void OnValue_in_IVisitor_for_Group51Var1(IVisitor_for_Group51Var1 *pIVisitor_for_Group51Var1, Group51Var1 pGroup51Var1)
{
  (pIVisitor_for_Group51Var1->pOnValue_in_IVisitor_for_Group51Var1)(pIVisitor_for_Group51Var1, pGroup51Var1);
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

void FunctorVisitor_for_Group51Var1_in_FunctorVisitor_for_Group51Var1(FunctorVisitor_for_Group51Var1 *pFunctorVisitor_for_Group51Var1,
    void (*fun)(Group51Var1 item))
{
  pFunctorVisitor_for_Group51Var1->Fun = fun;

  pFunctorVisitor_for_Group51Var1->iIVisitor_for_Group51Var1.pOnValue_in_IVisitor_for_Group51Var1 =
    OnValue_in_FunctorVisitor_for_Group51Var1_override;

  setParentPointer_in_IVisitor_for_Group51Var1(&(pFunctorVisitor_for_Group51Var1->iIVisitor_for_Group51Var1), pFunctorVisitor_for_Group51Var1);
}

void OnValue_in_FunctorVisitor_for_Group51Var1_override(void *pIVisitor_for_Group51Var1, Group51Var1 value)
{
  FunctorVisitor_for_Group51Var1 *parent = (FunctorVisitor_for_Group51Var1 *)
           getParentPointer_in_IVisitor_for_Group51Var1((IVisitor_for_Group51Var1 *) pIVisitor_for_Group51Var1);
///  parent -> Fun(value);
  OnValue_in_FunctorVisitor_for_Group51Var1(parent, value);
}

void OnValue_in_FunctorVisitor_for_Group51Var1(FunctorVisitor_for_Group51Var1 *pFunctorVisitor_for_Group51Var1, Group51Var1 value)
{
  pFunctorVisitor_for_Group51Var1 -> Fun(value);
}

//static void *pPointerGlobal1_in_ReadOnlyValue1;
void assignValue_in_ICollection_for_Group51Var1(Group51Var1 item);
void assignValue_in_ICollection_for_Group51Var1(Group51Var1 item)
{
  Group51Var1 *pValue = (Group51Var1 *)pPointerGlobal1;
//  *((Group51Var1*)pPointerGlobal1) = *item;
  *pValue = item;
}

boolean ReadOnlyValue_in_ICollection_for_Group51Var1(
  ICollection_for_Group51Var1 *pICollection_for_Group51Var1, Group51Var1 *pValue)
{
//  pPointerGlobal1 = pValue;
  pPointerGlobal1 = pValue;

////        if (this->Count() == 1)
  if (Count_in_ICollection_for_Group51Var1(pICollection_for_Group51Var1) == 1)
  {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
//void ForeachItem_in_ICollection_for_Group51Var1(ICollection_for_Group51Var1 *pICollection_for_Group51Var1,
//                  void (*fun)(Group51Var1* item));
    ForeachItem_in_ICollection_for_Group51Var1(pICollection_for_Group51Var1, assignValue_in_ICollection_for_Group51Var1);
    return true;
  }
  else
  {
    return false;
  }
}

//--------------------------------ICollection_for_Group51Var1--------------------------------
