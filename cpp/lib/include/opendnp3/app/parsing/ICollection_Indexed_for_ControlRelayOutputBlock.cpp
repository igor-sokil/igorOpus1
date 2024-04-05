#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "ICollection_Indexed_for_ControlRelayOutputBlock.h"

//--------------------------------ICollection_Indexed_for_ControlRelayOutputBlock--------------------------------
////    template<class Fun> void ForeachItem(const Fun& fun) const
void ForeachItem_in_ICollection_Indexed_for_ControlRelayOutputBlock(ICollection_Indexed_for_ControlRelayOutputBlock *pICollection_Indexed_for_ControlRelayOutputBlock, void (*fun)(Indexed_for_ControlRelayOutputBlock item))
   {
//void FunctorVisitor__for__uint32_in_FunctorVisitor__for__uint32(FunctorVisitor__for__uint32 *pFunctorVisitor__for__uint32,
//    void (*fun)(uint32_t* item));
////        FunctorVisitor<T, Fun> visitor(fun);
 FunctorVisitor_Indexed_for_ControlRelayOutputBlock visitor;
 FunctorVisitor_Indexed_for_ControlRelayOutputBlock_in_FunctorVisitor_Indexed_for_ControlRelayOutputBlock(&visitor, fun);

//void     Foreach_in_ICollection_Indexed_for_ControlRelayOutputBlock(ICollection_Indexed_for_ControlRelayOutputBlock*, IVisitor_Indexed_for_ControlRelayOutputBlock* visitor);
////        this->Foreach(visitor);
  Foreach_in_ICollection_Indexed_for_ControlRelayOutputBlock(pICollection_Indexed_for_ControlRelayOutputBlock, &(visitor.iIVisitor_Indexed_for_ControlRelayOutputBlock));
   }

void* getParentPointer_in_ICollection_Indexed_for_ControlRelayOutputBlock(ICollection_Indexed_for_ControlRelayOutputBlock* pICollection_Indexed_for_ControlRelayOutputBlock)
{
  return pICollection_Indexed_for_ControlRelayOutputBlock->pParentPointer_in_ICollection_Indexed_for_ControlRelayOutputBlock;
}
void  setParentPointer_in_ICollection_Indexed_for_ControlRelayOutputBlock(ICollection_Indexed_for_ControlRelayOutputBlock* pICollection_Indexed_for_ControlRelayOutputBlock, void* pParentPointer)
{
  pICollection_Indexed_for_ControlRelayOutputBlock->pParentPointer_in_ICollection_Indexed_for_ControlRelayOutputBlock = pParentPointer;
}
uint16_t Count_in_ICollection_Indexed_for_ControlRelayOutputBlock(ICollection_Indexed_for_ControlRelayOutputBlock *pICollection_Indexed_for_ControlRelayOutputBlock)
{
 return (pICollection_Indexed_for_ControlRelayOutputBlock->pCount_in_ICollection_Indexed_for_ControlRelayOutputBlock)(pICollection_Indexed_for_ControlRelayOutputBlock);
}

void  Foreach_in_ICollection_Indexed_for_ControlRelayOutputBlock(ICollection_Indexed_for_ControlRelayOutputBlock *pICollection_Indexed_for_ControlRelayOutputBlock, IVisitor_Indexed_for_ControlRelayOutputBlock *pIVisitor_Indexed_for_ControlRelayOutputBlock)
{
  (pICollection_Indexed_for_ControlRelayOutputBlock->pForeach_in_ICollection_Indexed_for_ControlRelayOutputBlock)(pICollection_Indexed_for_ControlRelayOutputBlock, pIVisitor_Indexed_for_ControlRelayOutputBlock);
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

void* getParentPointer_in_IVisitor_Indexed_for_ControlRelayOutputBlock(IVisitor_Indexed_for_ControlRelayOutputBlock* pIVisitor_Indexed_for_ControlRelayOutputBlock)
{
  return pIVisitor_Indexed_for_ControlRelayOutputBlock->pParentPointer_in_IVisitor_Indexed_for_ControlRelayOutputBlock;
}
void  setParentPointer_in_IVisitor_Indexed_for_ControlRelayOutputBlock(IVisitor_Indexed_for_ControlRelayOutputBlock* pIVisitor_Indexed_for_ControlRelayOutputBlock, void* pParentPointer)
{
  pIVisitor_Indexed_for_ControlRelayOutputBlock->pParentPointer_in_IVisitor_Indexed_for_ControlRelayOutputBlock = pParentPointer;
}
void OnValue_in_IVisitor_Indexed_for_ControlRelayOutputBlock(IVisitor_Indexed_for_ControlRelayOutputBlock *pIVisitor_Indexed_for_ControlRelayOutputBlock, Indexed_for_ControlRelayOutputBlock pIndexed_for_ControlRelayOutputBlock)
{
  (pIVisitor_Indexed_for_ControlRelayOutputBlock->pOnValue_in_IVisitor_Indexed_for_ControlRelayOutputBlock)(pIVisitor_Indexed_for_ControlRelayOutputBlock, pIndexed_for_ControlRelayOutputBlock);
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

void FunctorVisitor_Indexed_for_ControlRelayOutputBlock_in_FunctorVisitor_Indexed_for_ControlRelayOutputBlock(FunctorVisitor_Indexed_for_ControlRelayOutputBlock *pFunctorVisitor_Indexed_for_ControlRelayOutputBlock,
    void (*fun)(Indexed_for_ControlRelayOutputBlock item))
{
  pFunctorVisitor_Indexed_for_ControlRelayOutputBlock->Fun = fun;

  pFunctorVisitor_Indexed_for_ControlRelayOutputBlock->iIVisitor_Indexed_for_ControlRelayOutputBlock.pOnValue_in_IVisitor_Indexed_for_ControlRelayOutputBlock =
    OnValue_in_FunctorVisitor_Indexed_for_ControlRelayOutputBlock_override;

  setParentPointer_in_IVisitor_Indexed_for_ControlRelayOutputBlock(&(pFunctorVisitor_Indexed_for_ControlRelayOutputBlock->iIVisitor_Indexed_for_ControlRelayOutputBlock), pFunctorVisitor_Indexed_for_ControlRelayOutputBlock);
}

void OnValue_in_FunctorVisitor_Indexed_for_ControlRelayOutputBlock_override(void *pIVisitor_Indexed_for_ControlRelayOutputBlock, Indexed_for_ControlRelayOutputBlock value)
{
  FunctorVisitor_Indexed_for_ControlRelayOutputBlock *parent = (FunctorVisitor_Indexed_for_ControlRelayOutputBlock *)
           getParentPointer_in_IVisitor_Indexed_for_ControlRelayOutputBlock((IVisitor_Indexed_for_ControlRelayOutputBlock *) pIVisitor_Indexed_for_ControlRelayOutputBlock);
///  parent -> Fun(value);
  OnValue_in_FunctorVisitor_Indexed_for_ControlRelayOutputBlock(parent, value);
}

void OnValue_in_FunctorVisitor_Indexed_for_ControlRelayOutputBlock(FunctorVisitor_Indexed_for_ControlRelayOutputBlock *pFunctorVisitor_Indexed_for_ControlRelayOutputBlock, Indexed_for_ControlRelayOutputBlock value)
{
  pFunctorVisitor_Indexed_for_ControlRelayOutputBlock -> Fun(value);
}

//static void *pPointerGlobal1_in_ReadOnlyValue1;
void assignValue_in_ICollection_Indexed_for_ControlRelayOutputBlock(Indexed_for_ControlRelayOutputBlock item);
void assignValue_in_ICollection_Indexed_for_ControlRelayOutputBlock(Indexed_for_ControlRelayOutputBlock item)
{
  Indexed_for_ControlRelayOutputBlock *pValue = (Indexed_for_ControlRelayOutputBlock *)pPointerGlobal1;
//  *((Indexed_for_ControlRelayOutputBlock*)pPointerGlobal1) = *item;
  *pValue = item;
}

boolean ReadOnlyValue_in_ICollection_Indexed_for_ControlRelayOutputBlock(
  ICollection_Indexed_for_ControlRelayOutputBlock *pICollection_Indexed_for_ControlRelayOutputBlock, Indexed_for_ControlRelayOutputBlock *pValue)
{
//  pPointerGlobal1 = pValue;
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

//--------------------------------ICollection_Indexed_for_ControlRelayOutputBlock--------------------------------
