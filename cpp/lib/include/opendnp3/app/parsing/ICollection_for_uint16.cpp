#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "ICollection_for_uint16.h"

//--------------------------------ICollection_for_uint16--------------------------------
/**
 * Abstract way of visiting elements of a collection
 *
 */

void* getParentPointer_in_IVisitor_for_uint16(IVisitor__for__uint16* pIVisitor__for__uint16)
{
  return pIVisitor__for__uint16->pParentPointer_in_IVisitor__for__uint16;
}
void  setParentPointer_in_IVisitor_for_uint16(IVisitor__for__uint16* pIVisitor__for__uint16, void* pParentPointer)
{
  pIVisitor__for__uint16->pParentPointer_in_IVisitor__for__uint16 = pParentPointer;
}

void OnValue_in_IVisitor__for__uint16(IVisitor__for__uint16 *pIVisitor__for__uint16, uint16_t* puint16)
{
  (pIVisitor__for__uint16->pOnValue_in_IVisitor__for__uint16)(pIVisitor__for__uint16, puint16);
}

/**
 * An interface representing an abstract immutable collection of things of type T.
 *
 * The user can only read these values via callback to receive each element.
 */
uint16_t Count_in_ICollection_for_uint16(ICollection_for_uint16* pICollection_uint16)
{
  return (pICollection_uint16->pCount_in_ICollection_for_uint16)
         (pICollection_uint16);
}
void     Foreach_in_ICollection_for_uint16(ICollection_for_uint16* pICollection_uint16, IVisitor__for__uint16* visitor)
{
  (pICollection_uint16->pForeach_in_ICollection_for_uint16)
  (pICollection_uint16, visitor);
}

void* getParentPointer_in_ICollection_for_uint16(ICollection_for_uint16* pICollection_uint16)
{
  return pICollection_uint16->pParentPointer_in_ICollection_for_uint16;
}

void  setParentPointer_in_ICollection_for_uint16(ICollection_for_uint16* pICollection_uint16, void* pParentPointer)
{
  pICollection_uint16->pParentPointer_in_ICollection_for_uint16 = pParentPointer;
}

void assignValue_in_ICollection_uint16(uint16_t* item);

void assignValue_in_ICollection_uint16(uint16_t* item)
{
  *((uint16_t*)pPointerGlobal1) = *item;
}

boolean ReadOnlyValue_in_ICollection_for_uint16(
  ICollection_for_uint16 *pICollection_uint16, uint16_t* pValue)
{
  pPointerGlobal1 = pValue;

////        if (this->Count() == 1)
  if (Count_in_ICollection_for_uint16(pICollection_uint16) == 1)
  {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
//void ForeachItem_in_ICollection_uint16(ICollection_uint16 *pICollection_uint16,
//                  void (*fun)(uint16* item));
    ForeachItem_in_ICollection_for_uint16(pICollection_uint16, assignValue_in_ICollection_uint16);
    return true;
  }
  else
  {
    return false;
  }
}

void ForeachItem_in_ICollection_for_uint16(
  ICollection_for_uint16 *pICollection_uint16,
  void (*fun)(uint16_t* item))
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"ForeachItem_in_ICollection_for_uint16_1"<<'\n';
//  decrement_stack_info();
#endif
  FunctorVisitor__for__uint16 visitor;
//void FunctorVisitor__for__uint16_in_FunctorVisitor__for__uint16(__FunctorVisitor__for__uint16 *pFunctorVisitor__for__uint16,
//    void (*fun)(uint16* item));
  FunctorVisitor__for__uint16_in_FunctorVisitor__for__uint16(&visitor, fun);
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"ForeachItem_in_ICollection_for_uint16_2"<<'\n';
//  decrement_stack_info();
#endif
//  (pICollection_uint16->pForeach_in_ICollection_uint16)
//       (pICollection_uint16, &(visitor.iIVisitor__for__uint16));
  Foreach_in_ICollection_for_uint16(pICollection_uint16, &(visitor.iIVisitor__for__uint16));
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"ForeachItem_in_ICollection_for_uint16_3"<<'\n';
  decrement_stack_info();
#endif
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

void FunctorVisitor__for__uint16_in_FunctorVisitor__for__uint16(FunctorVisitor__for__uint16 *pFunctorVisitor__for__uint16,
    void (*fun)(uint16_t* item))
{
  pFunctorVisitor__for__uint16->Fun = fun;

  pFunctorVisitor__for__uint16->iIVisitor__for__uint16.pOnValue_in_IVisitor__for__uint16 =
    OnValue_in_FunctorVisitor__for__uint16_override;

  setParentPointer_in_IVisitor_for_uint16(&(pFunctorVisitor__for__uint16->iIVisitor__for__uint16), pFunctorVisitor__for__uint16);
}

void OnValue_in_FunctorVisitor__for__uint16_override(void *pFunctorVisitor__for__uint16,
    uint16_t *value)
{
  ((FunctorVisitor__for__uint16*)pFunctorVisitor__for__uint16)->
  Fun(value);
}
//--------------------------------ICollection_for_uint16--------------------------------


