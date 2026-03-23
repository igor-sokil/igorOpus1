#include "log_info.h"
#ifndef  LOG_INFO_INC
#include <iostream>
#endif
#include <QApplication>
#include "header.h"
#include "MockLinkLayer.h"

void MockLinkLayer_in_MockLinkLayer(MockLinkLayer *pMockLinkLayer)
{
  pMockLinkLayer->iILinkLayer.pSend_in_ILinkLayer = Send_in_MockLinkLayer_override;

  setParentPointer_in_ILinkLayer(&(pMockLinkLayer->iILinkLayer), pMockLinkLayer);
}

////    virtual bool Send(opendnp3::ITransportSegment& segments) override final
boolean Send_in_MockLinkLayer(MockLinkLayer *pMockLinkLayer, ITransportSegment* segments)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  std::cout<<"{Send_in_MockLinkLayer1"<<'\n';
#endif
//boolean HasValue_in_ITransportSegment(ITransportSegment*);
////        while (segments.HasValue())
  while (HasValue_in_ITransportSegment(segments))
  {
//RSeq_for_Uint16_t GetSegment_in_ITransportSegment(ITransportSegment*);
//std::string to_hex_in_HexConversionsOver2(RSeq_for_Uint16_t* buffer, bool spaced = true);
////            sends.push_back(ser4cpp::HexConversions::to_hex(segments.GetSegment()));
    RSeq_for_Uint16_t tmp = GetSegment_in_ITransportSegment(segments);
    pMockLinkLayer->sends_in_MockLinkLayer.push_back(to_hex_in_HexConversionsOver2(&tmp));
////            segments.Advance();
    Advance_in_ITransportSegment(segments);
  }

#ifdef  LOG_INFO
  std::cout<<"}Send_in_MockLinkLayer_"<<'\n';
#endif
  return true;
}
boolean Send_in_MockLinkLayer_override(void *pILinkLayer, ITransportSegment* segments)
{
  MockLinkLayer *parent = (MockLinkLayer*) getParentPointer_in_ILinkLayer((ILinkLayer*)pILinkLayer);
  return Send_in_MockLinkLayer(parent, segments);
}

////    std::string PopWriteAsHex()
std::string PopWriteAsHex_in_MockLinkLayer(MockLinkLayer *pMockLinkLayer)
{
////        assert(!sends.empty());
////        auto ret = sends.front();
  std::string ret = pMockLinkLayer->sends_in_MockLinkLayer.front();
  pMockLinkLayer->sends_in_MockLinkLayer.erase(pMockLinkLayer->sends_in_MockLinkLayer.begin());
  return ret;
}

////    bool SendUp(const std::string& hex, const opendnp3::Addresses& addresses = opendnp3::Addresses())
boolean SendUp_in_MockLinkLayer(MockLinkLayer *pMockLinkLayer, std::string& hex, Addresses* addresses)// = opendnp3::Addresses())
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  std::cout<<"{SendUp_in_MockLinkLayer1"<<'\n';
#endif
  if (pMockLinkLayer->hHasUpperLayer.pUpperLayer)
  {
////            HexSequence hs(hex);
    HexSequence hs;
    HexSequence_in_HexSequence(&hs, hex);

//RSeq_for_Uint16_t ToRSeq_in_CopyableBuffer(CopyableBuffer *pCopyableBuffer);
//void  Message_in_Message(Message *pMessage, Addresses *addresses, RSeq_for_Uint16_t* payload);
//boolean OnReceive_in_IUpperLayer(IUpperLayer *, Message* message);
////            return pUpperLayer->OnReceive(opendnp3::Message(addresses, hs.ToRSeq()));
    RSeq_for_Uint16_t payload = ToRSeq_in_CopyableBuffer(&(hs.bByteStr.cCopyableBuffer));
#ifdef  LOG_INFO
  std::cout<<"*SendUp_in_MockLinkLayer2"<<'\n';
  inspect_RSeq(&payload);
#endif

    Message mMessage;
    Message_in_Message(&mMessage, addresses, &payload);
    boolean tmp = OnReceive_in_IUpperLayer(pMockLinkLayer->hHasUpperLayer.pUpperLayer, &mMessage);
#ifdef  LOG_INFO
  std::cout<<"}SendUp_in_MockLinkLayer1_"<<'\n';
#endif
    return tmp;
  }
#ifdef  LOG_INFO
  std::cout<<"}SendUp_in_MockLinkLayer2_"<<'\n';
#endif
  return false;
}
