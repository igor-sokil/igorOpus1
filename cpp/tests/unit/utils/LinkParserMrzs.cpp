
#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "LinkParserMrzs.h"
#include "BufferHelpers.h"

void  LinkParserMrzs_in_LinkParserMrzs(LinkParserMrzs *pLinkParserMrzs, boolean aImmediate)// = false)
{
  UNUSED(aImmediate);
//// : log(), sink(), parser(log.logger) {}
  MrzsFrameSink_in_MrzsFrameSink(&(pLinkParserMrzs->sink_in_LinkParserMrzs));
  LinkLayerParser_in_LinkLayerParser(&(pLinkParserMrzs->parser));//const Logger& logger);
}

void WriteData_in_LinkParserMrzsOver1(LinkParserMrzs *pLinkParserMrzs, RSeq_for_Uint16_t* input)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  std::cout<<"{WriteData_in_LinkParserMrzsOver1_1"<<'\n';
#endif
//WSeq_for_Uint16_t WriteBuff_in_LinkLayerParser(LinkLayerParser *pLinkLayerParser);
////        auto buff = parser.WriteBuff();
  WSeq_for_Uint16_t buff = WriteBuff_in_LinkLayerParser(&(pLinkParserMrzs->parser));
////        assert(input.length() <= buff.length());
//    RSeq_for_Uint16_t copy_from_in_WSeq_for_Uint16_t(WSeq_for_Uint16_t *pWSeq_for_Uint16_t, RSeq_for_Uint16_t *src);
////        buff.copy_from(input);
  copy_from_in_WSeq_for_Uint16_t(&buff, input);
//    void OnRead_in_LinkLayerParser(LinkLayerParser *pLinkLayerParser, uint16_t numBytes, IFrameSink* sink);
////        parser.OnRead(input.length(), sink);
  OnRead_in_LinkLayerParser(&(pLinkParserMrzs->parser),
                            length_in_HasLength_for_Uint16_t(&(input->hHasLength)), &(pLinkParserMrzs->sink_in_LinkParserMrzs.iILinkSession.iIFrameSink));
#ifdef  LOG_INFO
  std::cout<<"}WriteData_in_LinkParserMrzsOver1__"<<'\n';
#endif
}

void WriteData_in_LinkParserMrzsOver2(LinkParserMrzs *pLinkParserMrzs, uint8_t *hex, uint16_t size_hex)////const std::string& hex)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  std::cout<<"{WriteData_in_LinkParserMrzsOver2_1"<<'\n';
#endif
////        HexSequence hs(hex);
////        auto buff = parser.WriteBuff();
  WSeq_for_Uint16_t buff = WriteBuff_in_LinkLayerParser(&(pLinkParserMrzs->parser));
////        assert(hs.Size() <= buff.length());
////        memcpy(buff, hs, hs.Size());
  memcpy(buff.buffer_, hex, size_hex);
////        parser.OnRead(hs.Size(), sink);
  OnRead_in_LinkLayerParser(&(pLinkParserMrzs->parser),
                            size_hex, &(pLinkParserMrzs->sink_in_LinkParserMrzs.iILinkSession.iIFrameSink));
#ifdef  LOG_INFO
  std::cout<<"}WriteData_in_LinkParserMrzsOver2__"<<'\n';
#endif
}

void WriteData_in_LinkParserMrzsOver3(LinkParserMrzs *pLinkParserMrzs, std::string& hex)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  std::cout<<"{WriteData_in_LinkParserMrzsOver3_1"<<'\n';
#endif
////        HexSequence hs(hex);
  HexSequence hs;
  HexSequence_in_HexSequence(&hs, hex);

////        auto buff = parser.WriteBuff();
  WSeq_for_Uint16_t buff = WriteBuff_in_LinkLayerParser(&(pLinkParserMrzs->parser));
////        assert(hs.Size() <= buff.length());
////        memcpy(buff, hs, hs.Size());
//  memcpy(buff.buffer_, hex, size_hex);
//  RSeq_for_Uint16_t temp = ToRSeq_in_CopyableBuffer(&(hs.bByMrzsr.cCopyableBuffer));
  uint16_t sz = Size_in_CopyableBuffer(&(hs.bByteStr.cCopyableBuffer));

  memcpy(buff.buffer_, &(hs.bByteStr.cCopyableBuffer), sz);

////        parser.OnRead(hs.Size(), sink);
  OnRead_in_LinkLayerParser(&(pLinkParserMrzs->parser),
                            sz, &(pLinkParserMrzs->sink_in_LinkParserMrzs.iILinkSession.iIFrameSink));
#ifdef  LOG_INFO
  std::cout<<"}WriteData_in_LinkParserMrzsOver3__"<<'\n';
#endif
}

void Reset_in_LinkParserMrzs(LinkParserMrzs *pLinkParserMrzs)
{
  Reset_in_MrzsFrameSink(&(pLinkParserMrzs->sink_in_LinkParserMrzs));
}
