#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "ICollection_Indexed_for_Binary.h"

//--------------------------------ICollection_Indexed_for_Binary--------------------------------
////    template<class Fun> void ForeachItem(const Fun& fun) const
void ForeachItem_in_ICollection_Indexed_for_Binary(ICollection_Indexed_for_Binary *pICollection_Indexed_for_Binary, void (*fun)(Indexed_for_Binary item))
   {
//void FunctorVisitor__for__uint32_in_FunctorVisitor__for__uint32(FunctorVisitor__for__uint32 *pFunctorVisitor__for__uint32,
//    void (*fun)(uint32_t* item));
////        FunctorVisitor<T, Fun> visitor(fun);
 FunctorVisitor_Indexed_for_Binary visitor;
 FunctorVisitor_Indexed_for_Binary_in_FunctorVisitor_Indexed_for_Binary(&visitor, fun);

//void     Foreach_in_ICollection_Indexed_for_Binary(ICollection_Indexed_for_Binary*, IVisitor_Indexed_for_Binary* visitor);
////        this->Foreach(visitor);
  Foreach_in_ICollection_Indexed_for_Binary(pICollection_Indexed_for_Binary, &(visitor.iIVisitor_Indexed_for_Binary));
   }

void* getParentPointer_in_ICollection_Indexed_for_Binary(ICollection_Indexed_for_Binary* pICollection_Indexed_for_Binary)
{
  return pICollection_Indexed_for_Binary->pParentPointer_in_ICollection_Indexed_for_Binary;
}
void  setParentPointer_in_ICollection_Indexed_for_Binary(ICollection_Indexed_for_Binary* pICollection_Indexed_for_Binary, void* pParentPointer)
{
  pICollection_Indexed_for_Binary->pParentPointer_in_ICollection_Indexed_for_Binary = pParentPointer;
}
uint16_t Count_in_ICollection_Indexed_for_Binary(ICollection_Indexed_for_Binary *pICollection_Indexed_for_Binary)
{
 return (pICollection_Indexed_for_Binary->pCount_in_ICollection_Indexed_for_Binary)(pICollection_Indexed_for_Binary);
}

void  Foreach_in_ICollection_Indexed_for_Binary(ICollection_Indexed_for_Binary *pICollection_Indexed_for_Binary, IVisitor_Indexed_for_Binary *pIVisitor_Indexed_for_Binary)
{
  (pICollection_Indexed_for_Binary->pForeach_in_ICollection_Indexed_for_Binary)(pICollection_Indexed_for_Binary, pIVisitor_Indexed_for_Binary);
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

void* getParentPointer_in_IVisitor_Indexed_for_Binary(IVisitor_Indexed_for_Binary* pIVisitor_Indexed_for_Binary)
{
  return pIVisitor_Indexed_for_Binary->pParentPointer_in_IVisitor_Indexed_for_Binary;
}
void  setParentPointer_in_IVisitor_Indexed_for_Binary(IVisitor_Indexed_for_Binary* pIVisitor_Indexed_for_Binary, void* pParentPointer)
{
  pIVisitor_Indexed_for_Binary->pParentPointer_in_IVisitor_Indexed_for_Binary = pParentPointer;
}
void OnValue_in_IVisitor_Indexed_for_Binary(IVisitor_Indexed_for_Binary *pIVisitor_Indexed_for_Binary, Indexed_for_Binary pIndexed_for_Binary)
{
  (pIVisitor_Indexed_for_Binary->pOnValue_in_IVisitor_Indexed_for_Binary)(pIVisitor_Indexed_for_Binary, pIndexed_for_Binary);
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

void FunctorVisitor_Indexed_for_Binary_in_FunctorVisitor_Indexed_for_Binary(FunctorVisitor_Indexed_for_Binary *pFunctorVisitor_Indexed_for_Binary,
    void (*fun)(Indexed_for_Binary item))
{
  pFunctorVisitor_Indexed_for_Binary->Fun = fun;

  pFunctorVisitor_Indexed_for_Binary->iIVisitor_Indexed_for_Binary.pOnValue_in_IVisitor_Indexed_for_Binary =
    OnValue_in_FunctorVisitor_Indexed_for_Binary_override;

  setParentPointer_in_IVisitor_Indexed_for_Binary(&(pFunctorVisitor_Indexed_for_Binary->iIVisitor_Indexed_for_Binary), pFunctorVisitor_Indexed_for_Binary);
}

void OnValue_in_FunctorVisitor_Indexed_for_Binary_override(void *pIVisitor_Indexed_for_Binary, Indexed_for_Binary value)
{
  FunctorVisitor_Indexed_for_Binary *parent = (FunctorVisitor_Indexed_for_Binary *)
           getParentPointer_in_IVisitor_Indexed_for_Binary((IVisitor_Indexed_for_Binary *) pIVisitor_Indexed_for_Binary);
///  parent -> Fun(value);
  OnValue_in_FunctorVisitor_Indexed_for_Binary(parent, value);
}

void OnValue_in_FunctorVisitor_Indexed_for_Binary(FunctorVisitor_Indexed_for_Binary *pFunctorVisitor_Indexed_for_Binary, Indexed_for_Binary value)
{
  pFunctorVisitor_Indexed_for_Binary -> Fun(value);
}

//static void *pPointerGlobal1_in_ReadOnlyValue1;
void assignValue_in_ICollection_Indexed_for_Binary(Indexed_for_Binary item);
void assignValue_in_ICollection_Indexed_for_Binary(Indexed_for_Binary item)
{
  Indexed_for_Binary *pValue = (Indexed_for_Binary *)pPointerGlobal1;
//  *((Indexed_for_Binary*)pPointerGlobal1) = *item;
  *pValue = item;
}

boolean ReadOnlyValue_in_ICollection_Indexed_for_Binary(
  ICollection_Indexed_for_Binary *pICollection_Indexed_for_Binary, Indexed_for_Binary *pValue)
{
//  pPointerGlobal1 = pValue;
  pPointerGlobal1 = pValue;

////        if (this->Count() == 1)
  if (Count_in_ICollection_Indexed_for_Binary(pICollection_Indexed_for_Binary) == 1)
  {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
//void ForeachItem_in_ICollection_Indexed_for_Binary(ICollection_Indexed_for_Binary *pICollection_Indexed_for_Binary,
//                  void (*fun)(Indexed_for_Binary* item));
    ForeachItem_in_ICollection_Indexed_for_Binary(pICollection_Indexed_for_Binary, assignValue_in_ICollection_Indexed_for_Binary);
    return true;
  }
  else
  {
    return false;
  }
}

//--------------------------------ICollection_Indexed_for_Binary--------------------------------
