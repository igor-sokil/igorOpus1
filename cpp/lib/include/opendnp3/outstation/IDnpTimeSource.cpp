#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "IDnpTimeSource.h"

void IDnpTimeSource_in_IDnpTimeSource(IDnpTimeSource *pIDnpTimeSource)
{
  pIDnpTimeSource->pNow_in_IDnpTimeSource_static = Now_in_IDnpTimeSource_static_override;
  setParentPointer_in_IDnpTimeSource(pIDnpTimeSource, pIDnpTimeSource);
}
DNPTime Now_in_IDnpTimeSource_static(IDnpTimeSource* pIDnpTimeSource)
{
  return (pIDnpTimeSource->pNow_in_IDnpTimeSource_static)(pIDnpTimeSource);
}

DNPTime Now_in_IDnpTimeSource_static_override(void* v)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{Now_in_IDnpTimeSource_static_override1"<<'\n';
#endif
  UNUSED(v);
  DNPTime dDNPTime;
  DNPTime_in_DNPTimeOver3(&dDNPTime, 0, TimestampQuality_INVALID);

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}Now_in_IDnpTimeSource_static_override_"<<'\n';
  decrement_stack_info();
#endif
////        return DNPTime(0, TimestampQuality::INVALID);
  return dDNPTime;
}

void* getParentPointer_in_IDnpTimeSource(IDnpTimeSource* pIDnpTimeSource)
{
  return pIDnpTimeSource->pParentPointer_in_IDnpTimeSource;
}
void  setParentPointer_in_IDnpTimeSource(IDnpTimeSource* pIDnpTimeSource, void* pParentPointer)
{
  pIDnpTimeSource->pParentPointer_in_IDnpTimeSource = pParentPointer;
}
