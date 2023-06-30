#include "header.h"
#include "ILinkListener.h"

    void OnStateChange_in_ILinkListener(ILinkListener* pILinkListener, LinkStatus_uint8_t value)
{
 (pILinkListener->pOnStateChange_in_ILinkListener)(pILinkListener, value);
}
    void OnUnknownDestinationAddress_in_ILinkListener(ILinkListener* pILinkListener, uint16_t destination)
{
 (pILinkListener->pOnUnknownDestinationAddress_in_ILinkListener)(pILinkListener, destination);
}
    void OnUnknownSourceAddress_in_ILinkListener(ILinkListener* pILinkListener, uint16_t source)
{
 (pILinkListener->pOnUnknownSourceAddress_in_ILinkListener)(pILinkListener, source);
}
    void OnKeepAliveInitiated_in_ILinkListener(ILinkListener* pILinkListener)
{
 (pILinkListener->pOnKeepAliveInitiated_in_ILinkListener)(pILinkListener);
}
    void OnKeepAliveFailure_in_ILinkListener(ILinkListener* pILinkListener)
{
 (pILinkListener->pOnKeepAliveFailure_in_ILinkListener)(pILinkListener);
}
    void OnKeepAliveSuccess_in_ILinkListener(ILinkListener* pILinkListener)
{
 (pILinkListener->pOnKeepAliveSuccess_in_ILinkListener)(pILinkListener);
}

    void OnStateChange_in_ILinkListener_default(void* v, LinkStatus_uint8_t value){UNUSED(v); UNUSED(value);}
    void OnUnknownDestinationAddress_in_ILinkListener_default(void* v, uint16_t destination){UNUSED(v); UNUSED(destination);}
    void OnUnknownSourceAddress_in_ILinkListener_default(void* v, uint16_t source){UNUSED(v); UNUSED(source);}
    void OnKeepAliveInitiated_in_ILinkListener_default(void* v){UNUSED(v);}
    void OnKeepAliveFailure_in_ILinkListener_default(void* v){UNUSED(v);}
    void OnKeepAliveSuccess_in_ILinkListener_default(void* v){UNUSED(v);}

void ILinkListener_in_ILinkListener(ILinkListener *pILinkListener)
{
 pILinkListener->pOnStateChange_in_ILinkListener = OnStateChange_in_ILinkListener_default;
 pILinkListener->pOnUnknownDestinationAddress_in_ILinkListener = OnUnknownDestinationAddress_in_ILinkListener_default;
 pILinkListener->pOnUnknownSourceAddress_in_ILinkListener = OnUnknownSourceAddress_in_ILinkListener_default;
 pILinkListener->pOnKeepAliveInitiated_in_ILinkListener = OnKeepAliveInitiated_in_ILinkListener_default;
 pILinkListener->pOnKeepAliveFailure_in_ILinkListener = OnKeepAliveFailure_in_ILinkListener_default;
 pILinkListener->pOnKeepAliveSuccess_in_ILinkListener = OnKeepAliveSuccess_in_ILinkListener_default;
}

void* getParentPointer_in_ILinkListener(ILinkListener* pILinkListener)
{
  return pILinkListener->pParentPointer_in_ILinkListener;
}

void  setParentPointer_in_ILinkListener(ILinkListener* pILinkListener, void* pParentPointer)
{
  pILinkListener->pParentPointer_in_ILinkListener = pParentPointer;
}
