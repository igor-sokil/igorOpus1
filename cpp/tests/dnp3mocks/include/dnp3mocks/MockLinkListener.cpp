#include <QApplication>
#include "header.h"
#include "MockLinkListener.h"

void MockLinkListener_in_MockLinkListener(MockLinkListener *pMockLinkListener)
{
  pMockLinkListener->iILinkListener.pOnStateChange_in_ILinkListener = OnStateChange_in_MockLinkListener_override;
  pMockLinkListener->iILinkListener.pOnKeepAliveInitiated_in_ILinkListener = OnKeepAliveInitiated_in_MockLinkListener_override;
  pMockLinkListener->iILinkListener.pOnKeepAliveFailure_in_ILinkListener = OnKeepAliveFailure_in_MockLinkListener_override;
  pMockLinkListener->iILinkListener.pOnKeepAliveSuccess_in_ILinkListener = OnKeepAliveSuccess_in_MockLinkListener_override;

  setParentPointer_in_ILinkListener(&(pMockLinkListener->iILinkListener), pMockLinkListener);

  pMockLinkListener->numKeepAliveTransmissions = 0;
  pMockLinkListener->numKeepAliveFailure = 0;
  pMockLinkListener->numKeepAliveReplys = 0;
}

void OnStateChange_in_MockLinkListener_override(void* pILinkListener, LinkStatus_uint8_t value)
{
  MockLinkListener* parent = (MockLinkListener*) getParentPointer_in_ILinkListener((ILinkListener*)pILinkListener);
  OnStateChange_in_MockLinkListener(parent, value);
}
void OnKeepAliveInitiated_in_MockLinkListener_override(void* pILinkListener)
{
  MockLinkListener* parent = (MockLinkListener*) getParentPointer_in_ILinkListener((ILinkListener*)pILinkListener);
  OnKeepAliveInitiated_in_MockLinkListener(parent);
}
void OnKeepAliveFailure_in_MockLinkListener_override(void* pILinkListener)
{
  MockLinkListener* parent = (MockLinkListener*) getParentPointer_in_ILinkListener((ILinkListener*)pILinkListener);
  OnKeepAliveFailure_in_MockLinkListener(parent);
}
void OnKeepAliveSuccess_in_MockLinkListener_override(void* pILinkListener)
{
  MockLinkListener* parent = (MockLinkListener*) getParentPointer_in_ILinkListener((ILinkListener*)pILinkListener);
  OnKeepAliveSuccess_in_MockLinkListener(parent);
}

void OnStateChange_in_MockLinkListener(MockLinkListener* pMockLinkListener, LinkStatus_uint8_t value)
{
  pMockLinkListener->statusValues.push_back(value);
}

void OnKeepAliveInitiated_in_MockLinkListener(MockLinkListener* pMockLinkListener)
{
  ++(pMockLinkListener->numKeepAliveTransmissions);
}

void OnKeepAliveFailure_in_MockLinkListener(MockLinkListener* pMockLinkListener)
{
  ++(pMockLinkListener->numKeepAliveFailure);
}

void OnKeepAliveSuccess_in_MockLinkListener(MockLinkListener* pMockLinkListener)
{
  ++(pMockLinkListener->numKeepAliveReplys);
}
