
#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
//#include <QApplication>
#include "header.h"
#include "LinkParserTest.h"
#include "BufferHelpers.h"

void  LinkParserTest_in_LinkParserTest(LinkParserTest *pLinkParserTest, boolean aImmediate)// = false)
{
  UNUSED(aImmediate);
//// : log(), sink(), parser(log.logger) {}
  MockFrameSink_in_MockFrameSink(&(pLinkParserTest->sink));
  LinkLayerParser_in_LinkLayerParser(&(pLinkParserTest->parser));//const Logger& logger);
}

void WriteData_in_LinkParserTestOver1(LinkParserTest *pLinkParserTest, RSeq_for_Uint16_t* input)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  std::cout<<"{WriteData_in_LinkParserTestOver1_1"<<'\n';
#endif
//WSeq_for_Uint16_t WriteBuff_in_LinkLayerParser(LinkLayerParser *pLinkLayerParser);
////        auto buff = parser.WriteBuff();
  WSeq_for_Uint16_t buff = WriteBuff_in_LinkLayerParser(&(pLinkParserTest->parser));
////        assert(input.length() <= buff.length());
//    RSeq_for_Uint16_t copy_from_in_WSeq_for_Uint16_t(WSeq_for_Uint16_t *pWSeq_for_Uint16_t, RSeq_for_Uint16_t *src);
////        buff.copy_from(input);
  copy_from_in_WSeq_for_Uint16_t(&buff, input);
//    void OnRead_in_LinkLayerParser(LinkLayerParser *pLinkLayerParser, uint16_t numBytes, IFrameSink* sink);
////        parser.OnRead(input.length(), sink);
/*
#ifdef  LOG_INFO
  std::cout<<"size= "<<length_in_HasLength_for_Uint16_t(&(input->hHasLength))<<'\n';
  std::cout<<"buff.buffer_="<<std::hex<<(uint16_t)buff.buffer_[0]
                                      <<(uint16_t)buff.buffer_[1]
                                      <<(uint16_t)buff.buffer_[2]
                                      <<(uint16_t)buff.buffer_[3]
                                      <<(uint16_t)buff.buffer_[4]
                                      <<(uint16_t)buff.buffer_[5]
                                      <<(uint16_t)buff.buffer_[6]
                                      <<(uint16_t)buff.buffer_[7]
                                      <<(uint16_t)buff.buffer_[8]
                                      <<(uint16_t)buff.buffer_[9]<<std::dec<<'\n';
#endif
*/
  OnRead_in_LinkLayerParser(&(pLinkParserTest->parser),
                            length_in_HasLength_for_Uint16_t(&(input->hHasLength)), &(pLinkParserTest->sink.iILinkSession.iIFrameSink));
#ifdef  LOG_INFO
  std::cout<<"}WriteData_in_LinkParserTestOver1__"<<'\n';
#endif
}

void WriteData_in_LinkParserTestOver2(LinkParserTest *pLinkParserTest, uint8_t *hex, uint16_t size_hex)////const std::string& hex)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  std::cout<<"{WriteData_in_LinkParserTestOver2_1"<<'\n';
#endif
////        HexSequence hs(hex);
////        auto buff = parser.WriteBuff();
  WSeq_for_Uint16_t buff = WriteBuff_in_LinkLayerParser(&(pLinkParserTest->parser));
////        assert(hs.Size() <= buff.length());
////        memcpy(buff, hs, hs.Size());
  memcpy(buff.buffer_, hex, size_hex);
////        parser.OnRead(hs.Size(), sink);
  OnRead_in_LinkLayerParser(&(pLinkParserTest->parser),
                            size_hex, &(pLinkParserTest->sink.iILinkSession.iIFrameSink));
#ifdef  LOG_INFO
  std::cout<<"}WriteData_in_LinkParserTestOver2__"<<'\n';
#endif
}

void WriteData_in_LinkParserTestOver3(LinkParserTest *pLinkParserTest, std::string& hex)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  std::cout<<"{WriteData_in_LinkParserTestOver3_1"<<'\n';
#endif
////        HexSequence hs(hex);
  HexSequence hs;
  HexSequence_in_HexSequence(&hs, hex);

////        auto buff = parser.WriteBuff();
  WSeq_for_Uint16_t buff = WriteBuff_in_LinkLayerParser(&(pLinkParserTest->parser));
////        assert(hs.Size() <= buff.length());
////        memcpy(buff, hs, hs.Size());
//  memcpy(buff.buffer_, hex, size_hex);
//  RSeq_for_Uint16_t temp = ToRSeq_in_CopyableBuffer(&(hs.bByteStr.cCopyableBuffer));
  uint16_t sz = Size_in_CopyableBuffer(&(hs.bByteStr.cCopyableBuffer));

  memcpy(buff.buffer_, &(hs.bByteStr.cCopyableBuffer), sz);
/*
#ifdef  LOG_INFO
  std::cout<<"size= "<<sz<<'\n';
  std::cout<<"buff.buffer_="<<std::hex<<(uint16_t)buff.buffer_[0]
                                      <<(uint16_t)buff.buffer_[1]
                                      <<(uint16_t)buff.buffer_[2]
                                      <<(uint16_t)buff.buffer_[3]
                                      <<(uint16_t)buff.buffer_[4]
                                      <<(uint16_t)buff.buffer_[5]
                                      <<(uint16_t)buff.buffer_[6]
                                      <<(uint16_t)buff.buffer_[7]
                                      <<(uint16_t)buff.buffer_[8]
                                      <<(uint16_t)buff.buffer_[9]<<std::dec<<'\n';
#endif
*/

////        parser.OnRead(hs.Size(), sink);
  OnRead_in_LinkLayerParser(&(pLinkParserTest->parser),
                            sz, &(pLinkParserTest->sink.iILinkSession.iIFrameSink));
#ifdef  LOG_INFO
  std::cout<<"}WriteData_in_LinkParserTestOver3__"<<'\n';
#endif
}
/*
void WriteData_in_LinkParserTestOver1(LinkParserTest *pLinkParserTest, RSeq_for_Uint16_t* input)
{
//WSeq_for_Uint16_t WriteBuff_in_LinkLayerParser(LinkLayerParser *pLinkLayerParser);
////        auto buff = parser.WriteBuff();
  WSeq_for_Uint16_t buff = WriteBuff_in_LinkLayerParser(&(pLinkParserTest->parser));
////        assert(input.length() <= buff.length());
//    RSeq_for_Uint16_t copy_from_in_WSeq_for_Uint16_t(WSeq_for_Uint16_t *pWSeq_for_Uint16_t, RSeq_for_Uint16_t *src);
////        buff.copy_from(input);
  copy_from_in_WSeq_for_Uint16_t(&buff, input);
//    void OnRead_in_LinkLayerParser(LinkLayerParser *pLinkLayerParser, uint16_t numBytes, IFrameSink* sink);
////        parser.OnRead(input.length(), sink);

  OnRead_in_LinkLayerParser(&(pLinkParserTest->parser),
                            length_in_HasLength_for_Uint16_t(&(input->hHasLength)), &(pLinkParserTest->sink.iILinkSession.iIFrameSink));
}
*/
