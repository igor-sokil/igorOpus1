#include <iostream>
//#endif
#include <QApplication>
#include "header.h"
#include "TransportObjectMrzs.h"

void TransportObjectMrzs_in_TransportObjectMrzs(TransportObjectMrzs *pTransportObjectMrzs, boolean openOnStart,/* = false,*/ uint32_t maxRxFragmentSize)// = opendnp3::DEFAULT_MAX_APDU_SIZE);
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  std::cout<<"{TransportObjectMrzs_in_TransportObjectMrzs1"<<'\n';
#endif
//  MockExecutor_in_MockExecutor(&(pTransportTestObject->exe));
//  MockLinkLayer_in_MockLinkLayer(&(pTransportTestObject->link));
  MockUpperLayer_in_MockUpperLayer(&(pTransportObjectMrzs->upper));

  TransportLayer_in_TransportLayer(&(pTransportObjectMrzs->transport), maxRxFragmentSize);

//void SetUpperLayer_in_HasUpperLayer(HasUpperLayer *pHasUpperLayer, IUpperLayer* upperLayer);
////    link.SetUpperLayer(transport);
//  SetUpperLayer_in_HasUpperLayer(&(pTransportTestObject->link.hHasUpperLayer), &(pTransportTestObject->transport.iIUpperLayer));

//void SetLinkLayer_in_TransportLayer(TransportLayer *pTransportLayer, ILinkLayer* linkLayer);
////    transport.SetLinkLayer(link);
//  SetLinkLayer_in_TransportLayer(&(pTransportObjectMrzs->transport), &(pTransportObjectMrzs->link.iILinkLayer));

//void SetLowerLayer_in_HasLowerLayer(HasLowerLayer *pHasLowerLayer, ILowerLayer* lowerLayer);
////    upper.SetLowerLayer(transport);
  SetLowerLayer_in_HasLowerLayer(&(pTransportObjectMrzs->upper.hHasLowerLayer), &(pTransportObjectMrzs->transport.iILowerLayer));

//void SetAppLayer_in_TransportLayer(TransportLayer *pTransportLayer, IUpperLayer* upperLayer);
////    transport.SetAppLayer(upper);
  SetAppLayer_in_TransportLayer(&(pTransportObjectMrzs->transport), &(pTransportObjectMrzs->upper.iIUpperLayer));

  if (openOnStart)
  {
//boolean OnLowerLayerUp_in_TransportLayer(TransportLayer *pTransportLayer);
////        transport.OnLowerLayerUp();
    OnLowerLayerUp_in_TransportLayer(&(pTransportObjectMrzs->transport));
  }

#ifdef  LOG_INFO
  std::cout<<"}TransportObjectMrzs_in_TransportObjectMrzs_"<<'\n';
#endif
}

