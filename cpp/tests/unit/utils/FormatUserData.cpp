
#include <QtWidgets>
#include "header.h"
#include "FormatUserData.h"
#include "BufferHelpers.h"
#include "HexConversions.h"

QString FormatUserData(
  boolean aIsMaster, boolean aIsConfirmed, int aDest, int aSrc, /*const std::string& data,*/uint8_t* data, uint16_t size_data, boolean aFcb);/// = false)

////std::string FormatUserData(
////    bool aIsMaster, bool aIsConfirmed, int aDest, int aSrc, const std::string& data, bool aFcb = false)
QString FormatUserData(
  boolean aIsMaster, boolean aIsConfirmed, int aDest, int aSrc, /*const std::string& data,*/uint8_t* data, uint16_t size_data, boolean aFcb)/// = false)
{
  QString str_response = "";

  RSeq_for_Uint16_t user_data;
  RSeq_for_Uint16_t_in_RSeq_for_Uint16_tOver2(&user_data, data, size_data);
////    HexSequence hs(data);
////    REQUIRE(hs.Size() < 250);

  uint8_t buffer[292];
//    void WSeq_for_Uint16_t_in_WSeq_for_Uint16_tOver2(WSeq_for_Uint16_t *pWSeq_for_Uint16_t, uint8_t* buffer, uint16_t length);
////    wseq_t wrapper(buffer, 292);
  WSeq_for_Uint16_t wrapper;
  WSeq_for_Uint16_t_in_WSeq_for_Uint16_tOver2(&wrapper, buffer, 292);

  RSeq_for_Uint16_t rseq;

  if (aIsConfirmed)
  {
//    RSeq_for_Uint16_t FormatConfirmedUserData_in_LinkFrame_static(WSeq_for_Uint16_t* buffer,
//                                                   boolean aIsMaster,
//                                                   boolean aFcb,
//                                                   uint16_t aDest,
//                                                   uint16_t aSrc,
//                                                   RSeq_for_Uint16_t user_data);//,
////        return HexConversions::to_hex(
////            LinkFrame::FormatConfirmedUserData(wrapper, aIsMaster, aFcb, aDest, aSrc, hs, nullptr));
    rseq =
      FormatConfirmedUserData_in_LinkFrame_static(&wrapper,
          aIsMaster,
          aFcb,
          aDest,
          aSrc,
          user_data);//,
  }

  else
  {
//    RSeq_for_Uint16_t FormatUnconfirmedUserData_in_LinkFrame_static(WSeq_for_Uint16_t* buffer,
//                                                     boolean aIsMaster,
//                                                     uint16_t aDest,
//                                                     uint16_t aSrc,
//                                                     RSeq_for_Uint16_t user_data);//,
////    return HexConversions::to_hex(LinkFrame::FormatUnconfirmedUserData(wrapper, aIsMaster, aDest, aSrc, hs, nullptr));
    rseq =
      FormatUnconfirmedUserData_in_LinkFrame_static(&wrapper,
          aIsMaster,
          aDest,
          aSrc,
          user_data);//,
  }//else

//    uint16_t length_in_HasLength_for_Uint16_t(HasLength_for_Uint16_t *pHasLength);
  uint16_t size = length_in_HasLength_for_Uint16_t(&(rseq.hHasLength));

  for(int i=0; i<size; i++)
  {
    QString insertStr = ((QString("0%1").arg(QString::number(rseq.buffer_[i], 16))).right(2));
    str_response.append(insertStr.toUpper());
    str_response.append(" ");
  }//for

  return str_response;
}

////std::string FormatUserData(
////    bool aIsMaster, bool aIsConfirmed, int aDest, int aSrc, const std::string& data, bool aFcb = false)
std::string FormatUserDataStr(
  boolean aIsMaster, boolean aIsConfirmed, int aDest, int aSrc, std::string& data, boolean aFcb)/// = false)
{
////    HexSequence hs(data);
 HexSequence hs;
 HexSequence_in_HexSequence(&hs, data);

////    REQUIRE(hs.Size() < 250);

    uint8_t buffer[292];
////    wseq_t wrapper(buffer, 292);
  WSeq_for_Uint16_t wrapper;
  WSeq_for_Uint16_t_in_WSeq_for_Uint16_tOver2(&wrapper, buffer, 292);

//  RSeq_for_Uint16_t rseq;

    if (aIsConfirmed)
    {
//    RSeq_for_Uint16_t FormatConfirmedUserData_in_LinkFrame_static(WSeq_for_Uint16_t* buffer,
//                                                   boolean aIsMaster,
//                                                   boolean aFcb,
//                                                   uint16_t aDest,
//                                                   uint16_t aSrc,
//                                                   RSeq_for_Uint16_t user_data);//,
//std::string to_hex_in_HexConversionsOver2(RSeq_for_Uint16_t* buffer, bool spaced = true);
////        return HexConversions::to_hex(
////            LinkFrame::FormatConfirmedUserData(wrapper, aIsMaster, aFcb, aDest, aSrc, hs, nullptr));
  RSeq_for_Uint16_t user_data = ToRSeq_in_CopyableBuffer(&(hs.bByteStr.cCopyableBuffer));
  RSeq_for_Uint16_t rseq =
      FormatConfirmedUserData_in_LinkFrame_static(&wrapper,
          aIsMaster,
          aFcb,
          aDest,
          aSrc,
          user_data);

 return to_hex_in_HexConversionsOver2(&rseq, true);

    }

////    return HexConversions::to_hex(LinkFrame::FormatUnconfirmedUserData(wrapper, aIsMaster, aDest, aSrc, hs, nullptr));
  RSeq_for_Uint16_t user_data = ToRSeq_in_CopyableBuffer(&(hs.bByteStr.cCopyableBuffer));
   RSeq_for_Uint16_t rseq =
      FormatUnconfirmedUserData_in_LinkFrame_static(&wrapper,
          aIsMaster,
          aDest,
          aSrc,
          user_data);//,

 return to_hex_in_HexConversionsOver2(&rseq, true);
}
