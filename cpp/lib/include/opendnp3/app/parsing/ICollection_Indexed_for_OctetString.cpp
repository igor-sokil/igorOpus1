#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "ICollection_Indexed_for_OctetString.h"

//--------------------------------ICollection_Indexed_for_OctetString--------------------------------
////    template<class Fun> void ForeachItem(const Fun& fun) const
void ForeachItem_in_ICollection_Indexed_for_OctetString(ICollection_Indexed_for_OctetString *pICollection_Indexed_for_OctetString, void (*fun)(Indexed_for_OctetString item))
   {
//void FunctorVisitor__for__uint32_in_FunctorVisitor__for__uint32(FunctorVisitor__for__uint32 *pFunctorVisitor__for__uint32,
//    void (*fun)(uint32_t* item));
////        FunctorVisitor<T, Fun> visitor(fun);
 FunctorVisitor_Indexed_for_OctetString visitor;
 FunctorVisitor_Indexed_for_OctetString_in_FunctorVisitor_Indexed_for_OctetString(&visitor, fun);

//void     Foreach_in_ICollection_Indexed_for_OctetString(ICollection_Indexed_for_OctetString*, IVisitor_Indexed_for_OctetString* visitor);
////        this->Foreach(visitor);
  Foreach_in_ICollection_Indexed_for_OctetString(pICollection_Indexed_for_OctetString, &(visitor.iIVisitor_Indexed_for_OctetString));
   }

void* getParentPointer_in_ICollection_Indexed_for_OctetString(ICollection_Indexed_for_OctetString* pICollection_Indexed_for_OctetString)
{
  return pICollection_Indexed_for_OctetString->pParentPointer_in_ICollection_Indexed_for_OctetString;
}
void  setParentPointer_in_ICollection_Indexed_for_OctetString(ICollection_Indexed_for_OctetString* pICollection_Indexed_for_OctetString, void* pParentPointer)
{
  pICollection_Indexed_for_OctetString->pParentPointer_in_ICollection_Indexed_for_OctetString = pParentPointer;
}
uint16_t Count_in_ICollection_Indexed_for_OctetString(ICollection_Indexed_for_OctetString *pICollection_Indexed_for_OctetString)
{
 return (pICollection_Indexed_for_OctetString->pCount_in_ICollection_Indexed_for_OctetString)(pICollection_Indexed_for_OctetString);
}

void  Foreach_in_ICollection_Indexed_for_OctetString(ICollection_Indexed_for_OctetString *pICollection_Indexed_for_OctetString, IVisitor_Indexed_for_OctetString *pIVisitor_Indexed_for_OctetString)
{
  (pICollection_Indexed_for_OctetString->pForeach_in_ICollection_Indexed_for_OctetString)(pICollection_Indexed_for_OctetString, pIVisitor_Indexed_for_OctetString);
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

void* getParentPointer_in_IVisitor_Indexed_for_OctetString(IVisitor_Indexed_for_OctetString* pIVisitor_Indexed_for_OctetString)
{
  return pIVisitor_Indexed_for_OctetString->pParentPointer_in_IVisitor_Indexed_for_OctetString;
}
void  setParentPointer_in_IVisitor_Indexed_for_OctetString(IVisitor_Indexed_for_OctetString* pIVisitor_Indexed_for_OctetString, void* pParentPointer)
{
  pIVisitor_Indexed_for_OctetString->pParentPointer_in_IVisitor_Indexed_for_OctetString = pParentPointer;
}
void OnValue_in_IVisitor_Indexed_for_OctetString(IVisitor_Indexed_for_OctetString *pIVisitor_Indexed_for_OctetString, Indexed_for_OctetString pIndexed_for_OctetString)
{
  (pIVisitor_Indexed_for_OctetString->pOnValue_in_IVisitor_Indexed_for_OctetString)(pIVisitor_Indexed_for_OctetString, pIndexed_for_OctetString);
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

void FunctorVisitor_Indexed_for_OctetString_in_FunctorVisitor_Indexed_for_OctetString(FunctorVisitor_Indexed_for_OctetString *pFunctorVisitor_Indexed_for_OctetString,
    void (*fun)(Indexed_for_OctetString item))
{
  pFunctorVisitor_Indexed_for_OctetString->Fun = fun;

  pFunctorVisitor_Indexed_for_OctetString->iIVisitor_Indexed_for_OctetString.pOnValue_in_IVisitor_Indexed_for_OctetString =
    OnValue_in_FunctorVisitor_Indexed_for_OctetString_override;

  setParentPointer_in_IVisitor_Indexed_for_OctetString(&(pFunctorVisitor_Indexed_for_OctetString->iIVisitor_Indexed_for_OctetString), pFunctorVisitor_Indexed_for_OctetString);
}

void OnValue_in_FunctorVisitor_Indexed_for_OctetString_override(void *pIVisitor_Indexed_for_OctetString, Indexed_for_OctetString value)
{
  FunctorVisitor_Indexed_for_OctetString *parent = (FunctorVisitor_Indexed_for_OctetString *)
           getParentPointer_in_IVisitor_Indexed_for_OctetString((IVisitor_Indexed_for_OctetString *) pIVisitor_Indexed_for_OctetString);
///  parent -> Fun(value);
  OnValue_in_FunctorVisitor_Indexed_for_OctetString(parent, value);
}

void OnValue_in_FunctorVisitor_Indexed_for_OctetString(FunctorVisitor_Indexed_for_OctetString *pFunctorVisitor_Indexed_for_OctetString, Indexed_for_OctetString value)
{
  pFunctorVisitor_Indexed_for_OctetString -> Fun(value);
}

//static void *pPointerGlobal1_in_ReadOnlyValue1;
void assignValue_in_ICollection_Indexed_for_OctetString(Indexed_for_OctetString item);
void assignValue_in_ICollection_Indexed_for_OctetString(Indexed_for_OctetString item)
{
  Indexed_for_OctetString *pValue = (Indexed_for_OctetString *)pPointerGlobal1;
//  *((Indexed_for_OctetString*)pPointerGlobal1) = *item;
  *pValue = item;
}

boolean ReadOnlyValue_in_ICollection_Indexed_for_OctetString(
  ICollection_Indexed_for_OctetString *pICollection_Indexed_for_OctetString, Indexed_for_OctetString *pValue)
{
//  pPointerGlobal1 = pValue;
  pPointerGlobal1 = pValue;

////        if (this->Count() == 1)
  if (Count_in_ICollection_Indexed_for_OctetString(pICollection_Indexed_for_OctetString) == 1)
  {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
//void ForeachItem_in_ICollection_Indexed_for_OctetString(ICollection_Indexed_for_OctetString *pICollection_Indexed_for_OctetString,
//                  void (*fun)(Indexed_for_OctetString* item));
    ForeachItem_in_ICollection_Indexed_for_OctetString(pICollection_Indexed_for_OctetString, assignValue_in_ICollection_Indexed_for_OctetString);
    return true;
  }
  else
  {
    return false;
  }
}

//--------------------------------ICollection_Indexed_for_OctetString--------------------------------
