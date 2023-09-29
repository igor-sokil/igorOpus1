#include "header.h"
#include "ICollection_Indexed_for_OctetString.h"

//--------------------------------ICollection_Indexed_for_OctetString--------------------------------
/**
 * Abstract way of visiting elements of a collection
 *
 */

void* getParentPointer_in_IVisitor__for__Indexed_for_OctetString(IVisitor__for__Indexed_for_OctetString* pIVisitor__for__Indexed_for_OctetString)
{
  return pIVisitor__for__Indexed_for_OctetString->pParentPointer_in_IVisitor__for__Indexed_for_OctetString;
}
void  setParentPointer_in_IVisitor__for__Indexed_for_OctetString(IVisitor__for__Indexed_for_OctetString* pIVisitor__for__Indexed_for_OctetString, void* pParentPointer)
{
  pIVisitor__for__Indexed_for_OctetString->pParentPointer_in_IVisitor__for__Indexed_for_OctetString = pParentPointer;
}

void OnValue_in_IVisitor__for__Indexed_for_OctetString(IVisitor__for__Indexed_for_OctetString *pIVisitor__for__Indexed_for_OctetString, Indexed_for_OctetString* pIndexed_for_OctetString)
{
  (pIVisitor__for__Indexed_for_OctetString->pOnValue_in_IVisitor__for__Indexed_for_OctetString)(pIVisitor__for__Indexed_for_OctetString, pIndexed_for_OctetString);
}

/**
 * An interface representing an abstract immutable collection of things of type T.
 *
 * The user can only read these values via callback to receive each element.
 */
uint16_t Count_in_ICollection_Indexed_for_OctetString(ICollection_Indexed_for_OctetString* pICollection_Indexed_for_OctetString)
{
  return (pICollection_Indexed_for_OctetString->pCount_in_ICollection_Indexed_for_OctetString)
         (pICollection_Indexed_for_OctetString);
}
void     Foreach_in_ICollection_Indexed_for_OctetString(ICollection_Indexed_for_OctetString* pICollection_Indexed_for_OctetString, IVisitor__for__Indexed_for_OctetString* visitor)
{
  (pICollection_Indexed_for_OctetString->pForeach_in_ICollection_Indexed_for_OctetString)
  (pICollection_Indexed_for_OctetString, visitor);
}

void* getParentPointer_in_ICollection_Indexed_for_OctetString(ICollection_Indexed_for_OctetString* pICollection_Indexed_for_OctetString)
{
  return pICollection_Indexed_for_OctetString->pParentPointer_in_ICollection_Indexed_for_OctetString;
}

void  setParentPointer_in_ICollection_Indexed_for_OctetString(ICollection_Indexed_for_OctetString* pICollection_Indexed_for_OctetString, void* pParentPointer)
{
  pICollection_Indexed_for_OctetString->pParentPointer_in_ICollection_Indexed_for_OctetString = pParentPointer;
}

void assignValue_in_ICollection_Indexed_for_OctetString(Indexed_for_OctetString* item);

void assignValue_in_ICollection_Indexed_for_OctetString(Indexed_for_OctetString* item)
{
  *((Indexed_for_OctetString*)pPointerGlobal1) = *item;
}

boolean ReadOnlyValue_in_ICollection_Indexed_for_OctetString(
  ICollection_Indexed_for_OctetString *pICollection_Indexed_for_OctetString, Indexed_for_OctetString* pValue)
{
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

void ForeachItem_in_ICollection_Indexed_for_OctetString(
  ICollection_Indexed_for_OctetString *pICollection_Indexed_for_OctetString,
  void (*fun)(Indexed_for_OctetString* item))
{
  FunctorVisitor__for__Indexed_for_OctetString visitor;
//void FunctorVisitor__for__Indexed_for_OctetString_in_FunctorVisitor__for__Indexed_for_OctetString(__FunctorVisitor__for__Indexed_for_OctetString *pFunctorVisitor__for__Indexed_for_OctetString,
//    void (*fun)(Indexed_for_OctetString* item));
  FunctorVisitor__for__Indexed_for_OctetString_in_FunctorVisitor__for__Indexed_for_OctetString(&visitor, fun);
//  (pICollection_Indexed_for_OctetString->pForeach_in_ICollection_Indexed_for_OctetString)
//       (pICollection_Indexed_for_OctetString, &(visitor.iIVisitor__for__Indexed_for_OctetString));
  Foreach_in_ICollection_Indexed_for_OctetString(pICollection_Indexed_for_OctetString, &(visitor.iIVisitor__for__Indexed_for_OctetString));
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

void FunctorVisitor__for__Indexed_for_OctetString_in_FunctorVisitor__for__Indexed_for_OctetString(FunctorVisitor__for__Indexed_for_OctetString *pFunctorVisitor__for__Indexed_for_OctetString,
    void (*fun)(Indexed_for_OctetString* item))
{
  pFunctorVisitor__for__Indexed_for_OctetString->Fun = fun;

  pFunctorVisitor__for__Indexed_for_OctetString->iIVisitor__for__Indexed_for_OctetString.pOnValue_in_IVisitor__for__Indexed_for_OctetString =
    OnValue_in_FunctorVisitor__for__Indexed_for_OctetString_override;

  setParentPointer_in_IVisitor__for__Indexed_for_OctetString(&(pFunctorVisitor__for__Indexed_for_OctetString->iIVisitor__for__Indexed_for_OctetString), pFunctorVisitor__for__Indexed_for_OctetString);
}

void OnValue_in_FunctorVisitor__for__Indexed_for_OctetString_override(void *pFunctorVisitor__for__Indexed_for_OctetString,
    Indexed_for_OctetString *value)
{
  ((FunctorVisitor__for__Indexed_for_OctetString*)pFunctorVisitor__for__Indexed_for_OctetString)->
  Fun(value);
}
//--------------------------------ICollection_Indexed_for_OctetString--------------------------------


