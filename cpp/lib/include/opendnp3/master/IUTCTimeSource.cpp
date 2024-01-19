#include  "header.h"
#include  "IUTCTimeSource.h"

UTCTimestamp Now_in_IUTCTimeSource(IUTCTimeSource* pIUTCTimeSource)
{
  return (pIUTCTimeSource->pNow_in_IUTCTimeSource)(pIUTCTimeSource);
}

void* getParentPointer_in_IUTCTimeSource(IUTCTimeSource* pIUTCTimeSource)
{
  return pIUTCTimeSource->pParentPointer_in_IUTCTimeSource;
}
void  setParentPointer_in_IUTCTimeSource(IUTCTimeSource* pIUTCTimeSource, void* pParentPointer)
{
  pIUTCTimeSource->pParentPointer_in_IUTCTimeSource = pParentPointer;
}
