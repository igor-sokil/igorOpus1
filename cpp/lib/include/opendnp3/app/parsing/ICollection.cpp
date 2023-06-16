#include "header.h"
#include "ICollection.h"
//--------------------------------ICollection_for_uint16--------------------------------

void FunctorVisitor_for_uint16_in_FunctorVisitor_for_uint16(FunctorVisitor_for_uint16 *pFunctorVisitor_for_uint16,
    ICollection_for_uint16 *pICollection_for_uint16,
    void (*fun)(ICollection_for_uint16 *pICollection_for_uint16, uint16_t* item))
{
  pFunctorVisitor_for_uint16->Fun = fun;
  pFunctorVisitor_for_uint16->pICollection_for_uint16 = pICollection_for_uint16;
  (pFunctorVisitor_for_uint16->iIVisitor_for_uint16).pOnValue_in_IVisitor_for_uint16 = OnValue_in_FunctorVisitor_for_uint16;
}

void OnValue_in_FunctorVisitor_for_uint16(void *pFunctorVisitor_for_uint16, uint16_t *value)
{
  ((FunctorVisitor_for_uint16*)pFunctorVisitor_for_uint16)->Fun(((FunctorVisitor_for_uint16*)pFunctorVisitor_for_uint16)->pICollection_for_uint16,
      value);
}

void ForeachItem_in_ICollection_for_uint16(ICollection_for_uint16 *pICollection_for_uint16, void (*fun)(ICollection_for_uint16 *pICollection_for_uint16, uint16_t* item))
{
  FunctorVisitor_for_uint16 visitor;
  FunctorVisitor_for_uint16_in_FunctorVisitor_for_uint16(&visitor, pICollection_for_uint16, fun);
  (pICollection_for_uint16->pForeach_in_ICollection_for_uint16)(pICollection_for_uint16, &(visitor.iIVisitor_for_uint16));
}

void assignValue_in_ICollection_for_uint16(ICollection_for_uint16 *pICollection_for_uint16, uint16_t* item);

void assignValue_in_ICollection_for_uint16(ICollection_for_uint16 *pICollection_for_uint16, uint16_t* item)
{
  *(pICollection_for_uint16->pValue_in_ICollection_for_uint16) = *item;
}

boolean ReadOnlyValue_in_ICollection_for_uint16(ICollection_for_uint16 *pICollection_for_uint16, uint16_t* pValue)
{
  pICollection_for_uint16->pValue_in_ICollection_for_uint16 = pValue;
////        if (this->Count() == 1)
  if ((pICollection_for_uint16->pCount_in_ICollection_for_uint16)(pICollection_for_uint16) == 1)
  {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
    ForeachItem_in_ICollection_for_uint16(pICollection_for_uint16, assignValue_in_ICollection_for_uint16);
    return true;
  }
  else
  {
    return false;
  }
}
//--------------------------------ICollection_for_uint16--------------------------------
