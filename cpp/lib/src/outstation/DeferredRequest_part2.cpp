
#include <QApplication>
#include "header.h"
#include "OutstationContext.h"
#include "DeferredRequest.h"

boolean  Process_for_handlerBooleanParsedRequest_in_DeferredRequest(DeferredRequest *pDeferredRequest, void* pOContext, boolean (*pHandlerBooleanParsedRequest)(void*, ParsedRequest*))
{
  if (pDeferredRequest->isSet)
  {
////        bool processed = handler(ParsedRequest(this->addresses, this->header, this->objects));
//  void  ParsedRequest_in_ParsedRequest(ParsedRequest *pParsedRequest, Addresses* addresses, APDUHeader* header, RSeq_for_Uint16_t* objects);
    ParsedRequest pParsedRequest;
    ParsedRequest_in_ParsedRequest(&(pParsedRequest), &(pDeferredRequest->addresses), &(pDeferredRequest->header), &(pDeferredRequest->objects));
    boolean processed = pHandlerBooleanParsedRequest((OContext*)pOContext, &pParsedRequest);
    pDeferredRequest->isSet = !processed;
    return processed;
  }
  else
  {
    return false;
  }
}
