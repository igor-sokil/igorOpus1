#include "header.h"
#include "IDnpTimeSource.h"

void IDnpTimeSource_in_IDnpTimeSource(IDnpTimeSource *pIDnpTimeSource)
{
  pIDnpTimeSource->pNow_in_IDnpTimeSource_static = Now_in_IDnpTimeSource_static;
}
DNPTime Now_in_IDnpTimeSource_static(void* v)
{
  UNUSED(v);
  DNPTime dDNPTime;
  DNPTime_in_DNPTimeOver3(&dDNPTime, 0, TimestampQuality_INVALID);
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
