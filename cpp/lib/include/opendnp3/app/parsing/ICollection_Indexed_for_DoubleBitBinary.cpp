#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "ICollection_Indexed_for_DoubleBitBinary.h"

//--------------------------------ICollection_Indexed_for_DoubleBitBinary--------------------------------
////    template<class Fun> void ForeachItem(const Fun& fun) const
void ForeachItem_in_ICollection_Indexed_for_DoubleBitBinary(ICollection_Indexed_for_DoubleBitBinary *pICollection_Indexed_for_DoubleBitBinary, void (*fun)(Indexed_for_DoubleBitBinary item))
   {
//void FunctorVisitor__for__uint32_in_FunctorVisitor__for__uint32(FunctorVisitor__for__uint32 *pFunctorVisitor__for__uint32,
//    void (*fun)(uint32_t* item));
////        FunctorVisitor<T, Fun> visitor(fun);
 FunctorVisitor_Indexed_for_DoubleBitBinary visitor;
 FunctorVisitor_Indexed_for_DoubleBitBinary_in_FunctorVisitor_Indexed_for_DoubleBitBinary(&visitor, fun);

//void     Foreach_in_ICollection_Indexed_for_DoubleBitBinary(ICollection_Indexed_for_DoubleBitBinary*, IVisitor_Indexed_for_DoubleBitBinary* visitor);
////        this->Foreach(visitor);
  Foreach_in_ICollection_Indexed_for_DoubleBitBinary(pICollection_Indexed_for_DoubleBitBinary, &(visitor.iIVisitor_Indexed_for_DoubleBitBinary));
   }

void* getParentPointer_in_ICollection_Indexed_for_DoubleBitBinary(ICollection_Indexed_for_DoubleBitBinary* pICollection_Indexed_for_DoubleBitBinary)
{
  return pICollection_Indexed_for_DoubleBitBinary->pParentPointer_in_ICollection_Indexed_for_DoubleBitBinary;
}
void  setParentPointer_in_ICollection_Indexed_for_DoubleBitBinary(ICollection_Indexed_for_DoubleBitBinary* pICollection_Indexed_for_DoubleBitBinary, void* pParentPointer)
{
  pICollection_Indexed_for_DoubleBitBinary->pParentPointer_in_ICollection_Indexed_for_DoubleBitBinary = pParentPointer;
}
uint16_t Count_in_ICollection_Indexed_for_DoubleBitBinary(ICollection_Indexed_for_DoubleBitBinary *pICollection_Indexed_for_DoubleBitBinary)
{
 return (pICollection_Indexed_for_DoubleBitBinary->pCount_in_ICollection_Indexed_for_DoubleBitBinary)(pICollection_Indexed_for_DoubleBitBinary);
}

void  Foreach_in_ICollection_Indexed_for_DoubleBitBinary(ICollection_Indexed_for_DoubleBitBinary *pICollection_Indexed_for_DoubleBitBinary, IVisitor_Indexed_for_DoubleBitBinary *pIVisitor_Indexed_for_DoubleBitBinary)
{
  (pICollection_Indexed_for_DoubleBitBinary->pForeach_in_ICollection_Indexed_for_DoubleBitBinary)(pICollection_Indexed_for_DoubleBitBinary, pIVisitor_Indexed_for_DoubleBitBinary);
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

void* getParentPointer_in_IVisitor_Indexed_for_DoubleBitBinary(IVisitor_Indexed_for_DoubleBitBinary* pIVisitor_Indexed_for_DoubleBitBinary)
{
  return pIVisitor_Indexed_for_DoubleBitBinary->pParentPointer_in_IVisitor_Indexed_for_DoubleBitBinary;
}
void  setParentPointer_in_IVisitor_Indexed_for_DoubleBitBinary(IVisitor_Indexed_for_DoubleBitBinary* pIVisitor_Indexed_for_DoubleBitBinary, void* pParentPointer)
{
  pIVisitor_Indexed_for_DoubleBitBinary->pParentPointer_in_IVisitor_Indexed_for_DoubleBitBinary = pParentPointer;
}
void OnValue_in_IVisitor_Indexed_for_DoubleBitBinary(IVisitor_Indexed_for_DoubleBitBinary *pIVisitor_Indexed_for_DoubleBitBinary, Indexed_for_DoubleBitBinary pIndexed_for_DoubleBitBinary)
{
  (pIVisitor_Indexed_for_DoubleBitBinary->pOnValue_in_IVisitor_Indexed_for_DoubleBitBinary)(pIVisitor_Indexed_for_DoubleBitBinary, pIndexed_for_DoubleBitBinary);
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

void FunctorVisitor_Indexed_for_DoubleBitBinary_in_FunctorVisitor_Indexed_for_DoubleBitBinary(FunctorVisitor_Indexed_for_DoubleBitBinary *pFunctorVisitor_Indexed_for_DoubleBitBinary,
    void (*fun)(Indexed_for_DoubleBitBinary item))
{
  pFunctorVisitor_Indexed_for_DoubleBitBinary->Fun = fun;

  pFunctorVisitor_Indexed_for_DoubleBitBinary->iIVisitor_Indexed_for_DoubleBitBinary.pOnValue_in_IVisitor_Indexed_for_DoubleBitBinary =
    OnValue_in_FunctorVisitor_Indexed_for_DoubleBitBinary_override;

  setParentPointer_in_IVisitor_Indexed_for_DoubleBitBinary(&(pFunctorVisitor_Indexed_for_DoubleBitBinary->iIVisitor_Indexed_for_DoubleBitBinary), pFunctorVisitor_Indexed_for_DoubleBitBinary);
}

void OnValue_in_FunctorVisitor_Indexed_for_DoubleBitBinary_override(void *pIVisitor_Indexed_for_DoubleBitBinary, Indexed_for_DoubleBitBinary value)
{
  FunctorVisitor_Indexed_for_DoubleBitBinary *parent = (FunctorVisitor_Indexed_for_DoubleBitBinary *)
           getParentPointer_in_IVisitor_Indexed_for_DoubleBitBinary((IVisitor_Indexed_for_DoubleBitBinary *) pIVisitor_Indexed_for_DoubleBitBinary);
///  parent -> Fun(value);
  OnValue_in_FunctorVisitor_Indexed_for_DoubleBitBinary(parent, value);
}

void OnValue_in_FunctorVisitor_Indexed_for_DoubleBitBinary(FunctorVisitor_Indexed_for_DoubleBitBinary *pFunctorVisitor_Indexed_for_DoubleBitBinary, Indexed_for_DoubleBitBinary value)
{
  pFunctorVisitor_Indexed_for_DoubleBitBinary -> Fun(value);
}

//static void *pPointerGlobal1_in_ReadOnlyValue1;
void assignValue_in_ICollection_Indexed_for_DoubleBitBinary(Indexed_for_DoubleBitBinary item);
void assignValue_in_ICollection_Indexed_for_DoubleBitBinary(Indexed_for_DoubleBitBinary item)
{
  Indexed_for_DoubleBitBinary *pValue = (Indexed_for_DoubleBitBinary *)pPointerGlobal1;
//  *((Indexed_for_DoubleBitBinary*)pPointerGlobal1) = *item;
  *pValue = item;
}

boolean ReadOnlyValue_in_ICollection_Indexed_for_DoubleBitBinary(
  ICollection_Indexed_for_DoubleBitBinary *pICollection_Indexed_for_DoubleBitBinary, Indexed_for_DoubleBitBinary *pValue)
{
//  pPointerGlobal1 = pValue;
  pPointerGlobal1 = pValue;

////        if (this->Count() == 1)
  if (Count_in_ICollection_Indexed_for_DoubleBitBinary(pICollection_Indexed_for_DoubleBitBinary) == 1)
  {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
//void ForeachItem_in_ICollection_Indexed_for_DoubleBitBinary(ICollection_Indexed_for_DoubleBitBinary *pICollection_Indexed_for_DoubleBitBinary,
//                  void (*fun)(Indexed_for_DoubleBitBinary* item));
    ForeachItem_in_ICollection_Indexed_for_DoubleBitBinary(pICollection_Indexed_for_DoubleBitBinary, assignValue_in_ICollection_Indexed_for_DoubleBitBinary);
    return true;
  }
  else
  {
    return false;
  }
}

//--------------------------------ICollection_Indexed_for_DoubleBitBinary--------------------------------
