#include "header.h"
#include "ITransportSegment.h"

Addresses* GetAddresses_in_ITransportSegment(ITransportSegment* pITransportSegment)
{
  return (pITransportSegment->pGetAddresses_in_ITransportSegment)(pITransportSegment);
}
boolean HasValue_in_ITransportSegment(ITransportSegment* pITransportSegment)
{
  return (pITransportSegment->pHasValue_in_ITransportSegment)(pITransportSegment);
}
RSeq_for_Uint16_t GetSegment_in_ITransportSegment(ITransportSegment* pITransportSegment)
{
  return (pITransportSegment->pGetSegment_in_ITransportSegment)(pITransportSegment);
}
boolean Advance_in_ITransportSegment(ITransportSegment* pITransportSegment)
{
  return (pITransportSegment->pAdvance_in_ITransportSegment)(pITransportSegment);
}

void* getParentPointer_in_ITransportSegment(ITransportSegment* pITransportSegment)
{
  return pITransportSegment->pParentPointer_in_ITransportSegment;
}
void  setParentPointer_in_ITransportSegment(ITransportSegment* pITransportSegment, void* pParentPointer)
{
  pITransportSegment->pParentPointer_in_ITransportSegment = pParentPointer;
}
