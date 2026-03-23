#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "TransformedCollection_for_uint32.h"

 void TransformedCollection_for_uint32_in_TransformedCollection_for_uint32(TransformedCollection_for_uint32 *pTransformedCollection_for_uint32,
                  ICollection_for_uint32* inpt, uint32_t (*transform)(uint32_t))
{
 pTransformedCollection_for_uint32->input1 = inpt;
 pTransformedCollection_for_uint32->transform = transform;

 pTransformedCollection_for_uint32->iICollection_for_uint32.pCount_in_ICollection_for_uint32 = Count_in_TransformedCollection_for_uint32_override;
 pTransformedCollection_for_uint32->iICollection_for_uint32.pForeach_in_ICollection_for_uint32 = Foreach_in_TransformedCollection_for_uint32_override;
 setParentPointer_in_ICollection_for_uint32(&(pTransformedCollection_for_uint32->iICollection_for_uint32), pTransformedCollection_for_uint32);
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{TransformedCollection_for_uint32_in_TransformedCollection_for_uint32_1"<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*pTransformedCollection_for_uint32= "<<(uint32_t)pTransformedCollection_for_uint32<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*pTransformedCollection_for_uint32->input1= "<<(uint32_t)pTransformedCollection_for_uint32->input1<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*pTransformedCollection_for_uint32->transform= "<<(uint32_t)pTransformedCollection_for_uint32->transform<<'\n';
#endif

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}TransformedCollection_for_uint32_in_TransformedCollection_for_uint32__"<<'\n';
  decrement_stack_info();
#endif
}

uint16_t  Count_in_TransformedCollection_for_uint32(TransformedCollection_for_uint32 *pTransformedCollection_for_uint32)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{Count_in_TransformedCollection_for_uint32"<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*pTransformedCollection_for_uint32->input1= "<<(uint32_t)pTransformedCollection_for_uint32->input1<<'\n';
#endif
//void  Count_in_ICollection_for_uint32(ICollection_for_uint32 *pICollection_for_uint32);
////        return input->Count();
//   ICollection_for_uint32* input = pTransformedCollection_for_uint32->input1;

  uint16_t tmp = Count_in_ICollection_for_uint32(pTransformedCollection_for_uint32->input1);

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}Count_in_TransformedCollection_for_uint32_"<<'\n';
  decrement_stack_info();
#endif
  return tmp;
}

static void * pPointerGlobal1_in_TransformedCollection;
static void * pPointerGlobal2_in_TransformedCollection;

void process_in_TransformedCollection_for_uint32(uint32_t elem);
void process_in_TransformedCollection_for_uint32(uint32_t elem)
{
  TransformedCollection_for_uint32 *pTransformedCollection_for_uint32 = (TransformedCollection_for_uint32*)pPointerGlobal1_in_TransformedCollection;
  IVisitor_for_uint32 *visitor = (IVisitor_for_uint32*) pPointerGlobal2_in_TransformedCollection;
//void OnValue_in_IVisitor_for_uint32(IVisitor_for_uint32 *, uint32_t* );
//   uint32_t (*transform)(uint32_t);
////        auto process = [this, &visitor](const T& elem) { visitor.OnValue(transform(elem)); };
  uint32_t out_elem = pTransformedCollection_for_uint32->transform(elem);
  OnValue_in_IVisitor_for_uint32(visitor, out_elem);
}
void  Foreach_in_TransformedCollection_for_uint32(TransformedCollection_for_uint32 *pTransformedCollection_for_uint32, IVisitor_for_uint32 *pIVisitor_for_uint32)
{
  pPointerGlobal1_in_TransformedCollection = pTransformedCollection_for_uint32;
  pPointerGlobal2_in_TransformedCollection = pIVisitor_for_uint32;
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{Foreach_in_TransformedCollection_for_uint32_1"<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*pTransformedCollection_for_uint32= "<<(uint32_t)pTransformedCollection_for_uint32<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*pIVisitor_for_uint32= "<<(uint32_t)pIVisitor_for_uint32<<'\n';
#endif

////        auto process = [this, &visitor](const T& elem) { visitor.OnValue(transform(elem)); };
//void ForeachItem_in_ICollection_for_uint32(ICollection_for_uint32 *pICollection_for_uint32, void (*fun)(uint32_t* item));
////        input->ForeachItem(process);
 ForeachItem_in_ICollection_for_uint32((pTransformedCollection_for_uint32->input1), process_in_TransformedCollection_for_uint32);//void (*fun)(uint32_t* item));
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}Foreach_in_TransformedCollection_for_uint32__"<<'\n';
  decrement_stack_info();
#endif
}
uint16_t  Count_in_TransformedCollection_for_uint32_override(void *pICollection_for_uint32)
{
  TransformedCollection_for_uint32 *parent = (TransformedCollection_for_uint32 *)
           getParentPointer_in_ICollection_for_uint32((ICollection_for_uint32 *) pICollection_for_uint32);
  return Count_in_TransformedCollection_for_uint32(parent);
}
void  Foreach_in_TransformedCollection_for_uint32_override(void *pICollection_for_uint32, IVisitor_for_uint32 *pIVisitor_for_uint32)
{
  TransformedCollection_for_uint32 *parent = (TransformedCollection_for_uint32 *)
           getParentPointer_in_ICollection_for_uint32((ICollection_for_uint32 *) pICollection_for_uint32);
  Foreach_in_TransformedCollection_for_uint32(parent, pIVisitor_for_uint32);
}

TransformedCollection_for_uint32 Map_for_uint32(ICollection_for_uint32 *input, uint32_t (*transform)(uint32_t))
{
// void TransformedCollection_for_uint32_in_TransformedCollection_for_uint32(TransformedCollection_for_uint32 *pTransformedCollection_for_uint32,
//                  ICollection_for_uint32* input, uint32_t (*transform)(uint32_t));
////    return TransformedCollection<T, U, Transform>(input, transform);
   TransformedCollection_for_uint32 tTransformedCollection_for_uint32;
   TransformedCollection_for_uint32_in_TransformedCollection_for_uint32(&tTransformedCollection_for_uint32,
                   input, transform);
   return tTransformedCollection_for_uint32;
}
