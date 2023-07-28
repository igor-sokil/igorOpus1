#include "header.h"
#include "ICollection_Indexed_for_ControlRelayOutputBlock.h"

//--------------------------------ICollection_Indexed_for_ControlRelayOutputBlock--------------------------------
/**
 * Abstract way of visiting elements of a collection
 *
 */

void* getParentPointer_in_IVisitor__for__Indexed_for_ControlRelayOutputBlock(IVisitor__for__Indexed_for_ControlRelayOutputBlock* pIVisitor__for__Indexed_for_ControlRelayOutputBlock)
{
  return pIVisitor__for__Indexed_for_ControlRelayOutputBlock->pParentPointer_in_IVisitor__for__Indexed_for_ControlRelayOutputBlock;
}
void  setParentPointer_in_IVisitor__for__Indexed_for_ControlRelayOutputBlock(IVisitor__for__Indexed_for_ControlRelayOutputBlock* pIVisitor__for__Indexed_for_ControlRelayOutputBlock, void* pParentPointer)
{
  pIVisitor__for__Indexed_for_ControlRelayOutputBlock->pParentPointer_in_IVisitor__for__Indexed_for_ControlRelayOutputBlock = pParentPointer;
}

void OnValue_in_IVisitor__for__Indexed_for_ControlRelayOutputBlock(IVisitor__for__Indexed_for_ControlRelayOutputBlock *pIVisitor__for__Indexed_for_ControlRelayOutputBlock, Indexed_for_ControlRelayOutputBlock* pIndexed_for_ControlRelayOutputBlock)
{
  (pIVisitor__for__Indexed_for_ControlRelayOutputBlock->pOnValue_in_IVisitor__for__Indexed_for_ControlRelayOutputBlock)(pIVisitor__for__Indexed_for_ControlRelayOutputBlock, pIndexed_for_ControlRelayOutputBlock);
}

/**
 * An interface representing an abstract immutable collection of things of type T.
 *
 * The user can only read these values via callback to receive each element.
 */
uint16_t Count_in_ICollection_Indexed_for_ControlRelayOutputBlock(ICollection_Indexed_for_ControlRelayOutputBlock* pICollection_Indexed_for_ControlRelayOutputBlock)
{
  return (pICollection_Indexed_for_ControlRelayOutputBlock->pCount_in_ICollection_Indexed_for_ControlRelayOutputBlock)
         (pICollection_Indexed_for_ControlRelayOutputBlock);
}
void     Foreach_in_ICollection_Indexed_for_ControlRelayOutputBlock(ICollection_Indexed_for_ControlRelayOutputBlock* pICollection_Indexed_for_ControlRelayOutputBlock, IVisitor__for__Indexed_for_ControlRelayOutputBlock* visitor)
{
  (pICollection_Indexed_for_ControlRelayOutputBlock->pForeach_in_ICollection_Indexed_for_ControlRelayOutputBlock)
  (pICollection_Indexed_for_ControlRelayOutputBlock, visitor);
}

void* getParentPointer_in_ICollection_Indexed_for_ControlRelayOutputBlock(ICollection_Indexed_for_ControlRelayOutputBlock* pICollection_Indexed_for_ControlRelayOutputBlock)
{
  return pICollection_Indexed_for_ControlRelayOutputBlock->pParentPointer_in_ICollection_Indexed_for_ControlRelayOutputBlock;
}

void  setParentPointer_in_ICollection_Indexed_for_ControlRelayOutputBlock(ICollection_Indexed_for_ControlRelayOutputBlock* pICollection_Indexed_for_ControlRelayOutputBlock, void* pParentPointer)
{
  pICollection_Indexed_for_ControlRelayOutputBlock->pParentPointer_in_ICollection_Indexed_for_ControlRelayOutputBlock = pParentPointer;
}

void assignValue_in_ICollection_Indexed_for_ControlRelayOutputBlock(Indexed_for_ControlRelayOutputBlock* item);

void assignValue_in_ICollection_Indexed_for_ControlRelayOutputBlock(Indexed_for_ControlRelayOutputBlock* item)
{
  *((Indexed_for_ControlRelayOutputBlock*)pPointerGlobal1) = *item;
}

boolean ReadOnlyValue_in_ICollection_Indexed_for_ControlRelayOutputBlock(
  ICollection_Indexed_for_ControlRelayOutputBlock *pICollection_Indexed_for_ControlRelayOutputBlock, Indexed_for_ControlRelayOutputBlock* pValue)
{
  pPointerGlobal1 = pValue;

////        if (this->Count() == 1)
  if (Count_in_ICollection_Indexed_for_ControlRelayOutputBlock(pICollection_Indexed_for_ControlRelayOutputBlock) == 1)
  {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
//void ForeachItem_in_ICollection_Indexed_for_ControlRelayOutputBlock(ICollection_Indexed_for_ControlRelayOutputBlock *pICollection_Indexed_for_ControlRelayOutputBlock,
//                  void (*fun)(Indexed_for_ControlRelayOutputBlock* item));
    ForeachItem_in_ICollection_Indexed_for_ControlRelayOutputBlock(pICollection_Indexed_for_ControlRelayOutputBlock, assignValue_in_ICollection_Indexed_for_ControlRelayOutputBlock);
    return true;
  }
  else
  {
    return false;
  }
}

void ForeachItem_in_ICollection_Indexed_for_ControlRelayOutputBlock(
  ICollection_Indexed_for_ControlRelayOutputBlock *pICollection_Indexed_for_ControlRelayOutputBlock,
  void (*fun)(Indexed_for_ControlRelayOutputBlock* item))
{
  FunctorVisitor__for__Indexed_for_ControlRelayOutputBlock visitor;
//void FunctorVisitor__for__Indexed_for_ControlRelayOutputBlock_in_FunctorVisitor__for__Indexed_for_ControlRelayOutputBlock(__FunctorVisitor__for__Indexed_for_ControlRelayOutputBlock *pFunctorVisitor__for__Indexed_for_ControlRelayOutputBlock,
//    void (*fun)(Indexed_for_ControlRelayOutputBlock* item));
  FunctorVisitor__for__Indexed_for_ControlRelayOutputBlock_in_FunctorVisitor__for__Indexed_for_ControlRelayOutputBlock(&visitor, fun);
//  (pICollection_Indexed_for_ControlRelayOutputBlock->pForeach_in_ICollection_Indexed_for_ControlRelayOutputBlock)
//       (pICollection_Indexed_for_ControlRelayOutputBlock, &(visitor.iIVisitor__for__Indexed_for_ControlRelayOutputBlock));
  Foreach_in_ICollection_Indexed_for_ControlRelayOutputBlock(pICollection_Indexed_for_ControlRelayOutputBlock, &(visitor.iIVisitor__for__Indexed_for_ControlRelayOutputBlock));
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

void FunctorVisitor__for__Indexed_for_ControlRelayOutputBlock_in_FunctorVisitor__for__Indexed_for_ControlRelayOutputBlock(FunctorVisitor__for__Indexed_for_ControlRelayOutputBlock *pFunctorVisitor__for__Indexed_for_ControlRelayOutputBlock,
    void (*fun)(Indexed_for_ControlRelayOutputBlock* item))
{
  pFunctorVisitor__for__Indexed_for_ControlRelayOutputBlock->Fun = fun;

  pFunctorVisitor__for__Indexed_for_ControlRelayOutputBlock->iIVisitor__for__Indexed_for_ControlRelayOutputBlock.pOnValue_in_IVisitor__for__Indexed_for_ControlRelayOutputBlock =
    OnValue_in_FunctorVisitor__for__Indexed_for_ControlRelayOutputBlock_override;

  setParentPointer_in_IVisitor__for__Indexed_for_ControlRelayOutputBlock(&(pFunctorVisitor__for__Indexed_for_ControlRelayOutputBlock->iIVisitor__for__Indexed_for_ControlRelayOutputBlock), pFunctorVisitor__for__Indexed_for_ControlRelayOutputBlock);
}

void OnValue_in_FunctorVisitor__for__Indexed_for_ControlRelayOutputBlock_override(void *pFunctorVisitor__for__Indexed_for_ControlRelayOutputBlock,
    Indexed_for_ControlRelayOutputBlock *value)
{
  ((FunctorVisitor__for__Indexed_for_ControlRelayOutputBlock*)pFunctorVisitor__for__Indexed_for_ControlRelayOutputBlock)->
  Fun(value);
}
//--------------------------------ICollection_Indexed_for_ControlRelayOutputBlock--------------------------------


