#include "header.h"
#include "ILinkSession.h"

    void OnTxReady_in_ILinkSession(ILinkSession* pILinkSession)
{
 (pILinkSession->pOnTxReady_in_ILinkSession)(pILinkSession);
}
    void OnLowerLayerUp_in_ILinkSession(ILinkSession* pILinkSession)
{
 (pILinkSession->pOnLowerLayerUp_in_ILinkSession)(pILinkSession);
}
    void OnLowerLayerDown_in_ILinkSession(ILinkSession* pILinkSession)
{
 (pILinkSession->pOnLowerLayerDown_in_ILinkSession)(pILinkSession);
}

void* getParentPointer_in_ILinkSession(ILinkSession* pILinkSession)
{
  return pILinkSession->pParentPointer_in_ILinkSession;
}

void  setParentPointer_in_ILinkSession(ILinkSession* pILinkSession, void* pParentPointer)
{
  pILinkSession->pParentPointer_in_ILinkSession = pParentPointer;
}
