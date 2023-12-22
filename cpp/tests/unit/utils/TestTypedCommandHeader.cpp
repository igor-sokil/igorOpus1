#include <iostream>
//#endif
#include <QApplication>
#include "header.h"
#include "TestTypedCommandHeader.h"

std::string WriteToHex_in_TestTypedCommandHeader(CommandSet* commands, IndexQualifierMode mode)
{
////    StaticBuffer<100> buffer;
////    auto dest = buffer.as_wseq();
////    APDURequest request(dest);
////    auto writer = request.GetWriter();
////    REQUIRE(CommandSetOps::Write(commands, writer, mode));
////    return HexConversions::to_hex(request.ToRSeq().skip(2));

////    StaticBuffer<100> buffer;
 StaticBuffer_for_LPDU_MAX_FRAME_SIZE buffer;
////    auto dest = buffer.as_wseq();
WSeq_for_Uint16_t dest = as_wseq_in_StaticBuffer_for_LPDU_MAX_FRAME_SIZEOver1(&buffer);

////    APDURequest request(dest);
 APDURequest request;
 APDURequest_in_APDURequestOver2(&request, &dest);

//HeaderWriter GetWriter_in_APDUWrapper(APDUWrapper *pAPDUWrapper);
////    auto writer = request.GetWriter();
HeaderWriter writer = GetWriter_in_APDUWrapper(&(request.aAPDUWrapper));

//  boolean Write_in_CommandSetOps_static(CommandSet* set, HeaderWriter* writer, IndexQualifierMode_uint8_t mode);
////    REQUIRE(CommandSetOps::Write(commands, writer, mode));
  boolean temp = Write_in_CommandSetOps_static(commands, &writer, mode);

std::cout<<"REQUIRE(CommandSetOps::Write(commands, writer, mode))"<<'\n';
std::cout<<"boolean temp= "<<temp<<'\n';

////    return HexConversions::to_hex(request.ToRSeq().skip(2));
  RSeq_for_Uint16_t rseq = ToRSeq_in_APDUWrapper(&(request.aAPDUWrapper));
  std::string  str = to_hex_in_HexConversionsOver2(&rseq, true);
  std::cout<<"str= "<<str<<std::endl;
 return str;
}