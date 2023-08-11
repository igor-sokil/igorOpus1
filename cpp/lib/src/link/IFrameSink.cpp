#include "header.h"
#include "IFrameSink.h"

void OnFrame_in_IFrameSink(IFrameSink* pIFrameSink, LinkHeaderFields* header, RSeq_for_Uint16_t* userdata)
{
  (pIFrameSink->pOnFrame_in_IFrameSink)(pIFrameSink, header, userdata);
}

void* getParentPointer_in_IFrameSink(IFrameSink* pIFrameSink)
{
  return pIFrameSink->pParentPointer_in_IFrameSink;
}

void  setParentPointer_in_IFrameSink(IFrameSink* pIFrameSink, void* pParentPointer)
{
  pIFrameSink->pParentPointer_in_IFrameSink = pParentPointer;
}
