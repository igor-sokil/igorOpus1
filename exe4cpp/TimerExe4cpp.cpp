#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "TimerExe4cpp.h"
#include <string.h>

void TimerExe4cpp_in_TimerExe4cppOver1(TimerExe4cpp *pTimerExe4cpp)
{
  pTimerExe4cpp->timerExe4cpp.pcancel_in_ITimer = NULL;
  pTimerExe4cpp->timerExe4cpp.pexpires_at_in_ITimer = NULL;
}

void TimerExe4cpp_in_TimerExe4cppOver2(TimerExe4cpp *pTimerExe4cpp, ITimer* tim)
{
  pTimerExe4cpp->timerExe4cpp = *tim;
}

boolean cancel_in_TimerExe4cpp(TimerExe4cpp *pTimerExe4cpp)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{cancel_in_TimerExe4cpp1"<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*TimerExe4cpp *pTimerExe4cpp= "<<(uint32_t)pTimerExe4cpp<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*pTimerExe4cpp->timerExe4cpp.psource_in_ITimer= "<<(uint32_t)pTimerExe4cpp->timerExe4cpp.psource_in_ITimer<<'\n';
#endif
  if((pTimerExe4cpp->timerExe4cpp.pcancel_in_ITimer) == NULL)
  {
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"}cancel_in_TimerExe4cpp1_"<<'\n';
    decrement_stack_info();
#endif
    return false;
  }
//  qDebug()<<"cancel_in_TimerExe4cpp1";
//  qDebug()<<"pTimerExe4cpp= "<<(uint32_t)pTimerExe4cpp;
  cancel_in_ITimer(&(pTimerExe4cpp->timerExe4cpp));
//  qDebug()<<"cancel_in_TimerExe4cpp2";
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}cancel_in_TimerExe4cpp2_"<<'\n';
  decrement_stack_info();
#endif
  return true;
}

uint32_t expires_at_in_TimerExe4cpp(TimerExe4cpp *pTimerExe4cpp)
{
  return expires_at_in_ITimer(&(pTimerExe4cpp->timerExe4cpp));
}
