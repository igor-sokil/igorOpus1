#include "header.h"
#include "ICollection_Indexed_for_AnalogOutputFloat32.h"

//--------------------------------ICollection_Indexed_for_AnalogOutputFloat32--------------------------------
/**
 * Abstract way of visiting elements of a collection
 *
 */

void* getParentPointer_in_IVisitor__for__Indexed_for_AnalogOutputFloat32(IVisitor__for__Indexed_for_AnalogOutputFloat32* pIVisitor__for__Indexed_for_AnalogOutputFloat32)
{
  return pIVisitor__for__Indexed_for_AnalogOutputFloat32->pParentPointer_in_IVisitor__for__Indexed_for_AnalogOutputFloat32;
}
void  setParentPointer_in_IVisitor__for__Indexed_for_AnalogOutputFloat32(IVisitor__for__Indexed_for_AnalogOutputFloat32* pIVisitor__for__Indexed_for_AnalogOutputFloat32, void* pParentPointer)
{
  pIVisitor__for__Indexed_for_AnalogOutputFloat32->pParentPointer_in_IVisitor__for__Indexed_for_AnalogOutputFloat32 = pParentPointer;
}

void OnValue_in_IVisitor__for__Indexed_for_AnalogOutputFloat32(IVisitor__for__Indexed_for_AnalogOutputFloat32 *pIVisitor__for__Indexed_for_AnalogOutputFloat32, Indexed_for_AnalogOutputFloat32* pIndexed_for_AnalogOutputFloat32)
{
  (pIVisitor__for__Indexed_for_AnalogOutputFloat32->pOnValue_in_IVisitor__for__Indexed_for_AnalogOutputFloat32)(pIVisitor__for__Indexed_for_AnalogOutputFloat32, pIndexed_for_AnalogOutputFloat32);
}

/**
 * An interface representing an abstract immutable collection of things of type T.
 *
 * The user can only read these values via callback to receive each element.
 */
uint16_t Count_in_ICollection_Indexed_for_AnalogOutputFloat32(ICollection_Indexed_for_AnalogOutputFloat32* pICollection_Indexed_for_AnalogOutputFloat32)
{
  return (pICollection_Indexed_for_AnalogOutputFloat32->pCount_in_ICollection_Indexed_for_AnalogOutputFloat32)
         (pICollection_Indexed_for_AnalogOutputFloat32);
}
void     Foreach_in_ICollection_Indexed_for_AnalogOutputFloat32(ICollection_Indexed_for_AnalogOutputFloat32* pICollection_Indexed_for_AnalogOutputFloat32, IVisitor__for__Indexed_for_AnalogOutputFloat32* visitor)
{
  (pICollection_Indexed_for_AnalogOutputFloat32->pForeach_in_ICollection_Indexed_for_AnalogOutputFloat32)
  (pICollection_Indexed_for_AnalogOutputFloat32, visitor);
}

void* getParentPointer_in_ICollection_Indexed_for_AnalogOutputFloat32(ICollection_Indexed_for_AnalogOutputFloat32* pICollection_Indexed_for_AnalogOutputFloat32)
{
  return pICollection_Indexed_for_AnalogOutputFloat32->pParentPointer_in_ICollection_Indexed_for_AnalogOutputFloat32;
}

void  setParentPointer_in_ICollection_Indexed_for_AnalogOutputFloat32(ICollection_Indexed_for_AnalogOutputFloat32* pICollection_Indexed_for_AnalogOutputFloat32, void* pParentPointer)
{
  pICollection_Indexed_for_AnalogOutputFloat32->pParentPointer_in_ICollection_Indexed_for_AnalogOutputFloat32 = pParentPointer;
}

void assignValue_in_ICollection_Indexed_for_AnalogOutputFloat32(Indexed_for_AnalogOutputFloat32* item);

void assignValue_in_ICollection_Indexed_for_AnalogOutputFloat32(Indexed_for_AnalogOutputFloat32* item)
{
  *((Indexed_for_AnalogOutputFloat32*)pPointerGlobal1) = *item;
}

boolean ReadOnlyValue_in_ICollection_Indexed_for_AnalogOutputFloat32(
  ICollection_Indexed_for_AnalogOutputFloat32 *pICollection_Indexed_for_AnalogOutputFloat32, Indexed_for_AnalogOutputFloat32* pValue)
{
  pPointerGlobal1 = pValue;

////        if (this->Count() == 1)
  if (Count_in_ICollection_Indexed_for_AnalogOutputFloat32(pICollection_Indexed_for_AnalogOutputFloat32) == 1)
  {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
//void ForeachItem_in_ICollection_Indexed_for_AnalogOutputFloat32(ICollection_Indexed_for_AnalogOutputFloat32 *pICollection_Indexed_for_AnalogOutputFloat32,
//                  void (*fun)(Indexed_for_AnalogOutputFloat32* item));
    ForeachItem_in_ICollection_Indexed_for_AnalogOutputFloat32(pICollection_Indexed_for_AnalogOutputFloat32, assignValue_in_ICollection_Indexed_for_AnalogOutputFloat32);
    return true;
  }
  else
  {
    return false;
  }
}

void ForeachItem_in_ICollection_Indexed_for_AnalogOutputFloat32(
  ICollection_Indexed_for_AnalogOutputFloat32 *pICollection_Indexed_for_AnalogOutputFloat32,
  void (*fun)(Indexed_for_AnalogOutputFloat32* item))
{
  FunctorVisitor__for__Indexed_for_AnalogOutputFloat32 visitor;
//void FunctorVisitor__for__Indexed_for_AnalogOutputFloat32_in_FunctorVisitor__for__Indexed_for_AnalogOutputFloat32(__FunctorVisitor__for__Indexed_for_AnalogOutputFloat32 *pFunctorVisitor__for__Indexed_for_AnalogOutputFloat32,
//    void (*fun)(Indexed_for_AnalogOutputFloat32* item));
  FunctorVisitor__for__Indexed_for_AnalogOutputFloat32_in_FunctorVisitor__for__Indexed_for_AnalogOutputFloat32(&visitor, fun);
//  (pICollection_Indexed_for_AnalogOutputFloat32->pForeach_in_ICollection_Indexed_for_AnalogOutputFloat32)
//       (pICollection_Indexed_for_AnalogOutputFloat32, &(visitor.iIVisitor__for__Indexed_for_AnalogOutputFloat32));
  Foreach_in_ICollection_Indexed_for_AnalogOutputFloat32(pICollection_Indexed_for_AnalogOutputFloat32, &(visitor.iIVisitor__for__Indexed_for_AnalogOutputFloat32));
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

void FunctorVisitor__for__Indexed_for_AnalogOutputFloat32_in_FunctorVisitor__for__Indexed_for_AnalogOutputFloat32(FunctorVisitor__for__Indexed_for_AnalogOutputFloat32 *pFunctorVisitor__for__Indexed_for_AnalogOutputFloat32,
    void (*fun)(Indexed_for_AnalogOutputFloat32* item))
{
  pFunctorVisitor__for__Indexed_for_AnalogOutputFloat32->Fun = fun;

  pFunctorVisitor__for__Indexed_for_AnalogOutputFloat32->iIVisitor__for__Indexed_for_AnalogOutputFloat32.pOnValue_in_IVisitor__for__Indexed_for_AnalogOutputFloat32 =
    OnValue_in_FunctorVisitor__for__Indexed_for_AnalogOutputFloat32_override;

  setParentPointer_in_IVisitor__for__Indexed_for_AnalogOutputFloat32(&(pFunctorVisitor__for__Indexed_for_AnalogOutputFloat32->iIVisitor__for__Indexed_for_AnalogOutputFloat32), pFunctorVisitor__for__Indexed_for_AnalogOutputFloat32);
}

void OnValue_in_FunctorVisitor__for__Indexed_for_AnalogOutputFloat32_override(void *pFunctorVisitor__for__Indexed_for_AnalogOutputFloat32,
    Indexed_for_AnalogOutputFloat32 *value)
{
  ((FunctorVisitor__for__Indexed_for_AnalogOutputFloat32*)pFunctorVisitor__for__Indexed_for_AnalogOutputFloat32)->
  Fun(value);
}
//--------------------------------ICollection_Indexed_for_AnalogOutputFloat32--------------------------------


