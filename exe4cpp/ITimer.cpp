#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "ITimer.h"

void cancel_in_ITimer(ITimer* pITimer)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{cancel_in_ITimer1"<<'\n';

  std::cout<<getString_stack_info();
  std::cout<<"*pITimer->psource_in_ITimer= "<<(uint32_t)pITimer->psource_in_ITimer<<'\n';

//  std::cout<<"*(pITimer)= "<<(uint32_t)(pITimer)<<'\n';
//  if(!pITimer) return;

//  std::cout<<"*(pITimer->pcancel_in_ITimer)= "<<(uint32_t)(pITimer->pcancel_in_ITimer)<<'\n';
#endif
  (pITimer->pcancel_in_ITimer)(pITimer);
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}cancel_in_ITimer1"<<'\n';
  decrement_stack_info();
#endif
}
uint32_t expires_at_in_ITimer(ITimer* pITimer)
{
  return (pITimer->pexpires_at_in_ITimer)(pITimer);
}

void* getParentPointer_in_ITimer(ITimer* pITimer)
{
  return pITimer->pParentPointer_in_ITimer;
}
void  setParentPointer_in_ITimer(ITimer* pITimer, void* pParentPointer)
{
  pITimer->pParentPointer_in_ITimer = pParentPointer;
}
