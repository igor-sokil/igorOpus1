
#include <QApplication>
#include <QtWidgets>

#include <stdlib.h>

#include "MainWindow.h"
#include "key_filter.h"

#include "header.h"

#include "APDUHelpers.h"
#include "APDUHeader.h"
#include "SerializationTemplates.h"
#include "Group2.h"
#include "Group51.h"

DWORD get_fattime (void);

#define UNUSED(x) (void)(x)

key_filter *pkf;

MainWindow *mainWindow;

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);


/*
TEST_CASE(SUITE("PrefixWriteIteratorCTOSpaceForOnly1Value"))
{
    APDUResponse response(APDUHelpers::Response(26));
    auto writer = response.GetWriter();

    Group51Var1 cto;
    cto.time = DNPTime(0xAA);

    {
        auto iter = writer.IterateOverCountWithPrefixAndCTO<UInt16, Binary>(QualifierCode::UINT16_CNT_UINT16_INDEX,
                                                                            Group2Var3::Inst(), cto);
        REQUIRE(iter.IsValid());
        REQUIRE(iter.Write(Binary(true, Flags(0x01), DNPTime(0x0B, TimestampQuality::SYNCHRONIZED)), 6));
        REQUIRE(!iter.Write(Binary(true, Flags(0x01), DNPTime(0x0C, TimestampQuality::SYNCHRONIZED)), 7));
    }

    REQUIRE("C0 81 00 00 33 01 07 01 AA 00 00 00 00 00 02 03 28 01 00 06 00 81 0B 00"
            == HexConversions::to_hex(response.ToRSeq()));
}
*/
     APDUResponse response = Response_in_APDUHelpers_static(26);
//    auto writer = response.GetWriter();
     HeaderWriter writer = GetWriter_in_APDUWrapper(&(response.aAPDUWrapper));

    Group51Var1 cto;
////    cto.time = DNPTime(0xAA);
   DNPTime_in_DNPTimeOver2(&(cto.timeDNPTime), 0xAA);

  DNPTime_in_DNPTimeOver2(&(cto.timeDNPTime), 0xAA);

  DNP3Serializer_for_Binary serializer = Inst_in_Group2Var3_static();

  PrefixedWriteIterator_for_UInt16_Binary iter = IterateOverCountWithPrefixAndCTO_for_UInt16_Binary_Group51Var1_in_HeaderWriter(&writer,
      QualifierCode_UINT16_CNT_UINT16_INDEX,
      &serializer,
      &cto);

  boolean tmp = IsValid_in_PrefixedWriteIterator_for_UInt16_Binary(&iter);
  qDebug()<<"REQUIRE(iterator.IsValid())";
  qDebug()<<"boolean temp= "<<tmp;

  Flags fFlags;
  Flags_In_FlagsOver2(&fFlags, 0x01);
  DNPTime dDNPTime;
  DNPTime_in_DNPTimeOver3(&dDNPTime, 0x0B, TimestampQuality_SYNCHRONIZED);
  Binary bBinary;
  Binary_in_BinaryOver6(&bBinary, true, fFlags, dDNPTime);

  tmp = Write_in_PrefixedWriteIterator_for_UInt16_Binary(&iter, &bBinary, 6);
  qDebug()<<"REQUIRE(iter.Write(Binary(true, Flags(0x01), DNPTime(0x0B, TimestampQuality::SYNCHRONIZED)), 6))";
  qDebug()<<"boolean temp= "<<tmp;

  Flags_In_FlagsOver2(&fFlags, 0x01);
  DNPTime_in_DNPTimeOver3(&dDNPTime, 0x0C, TimestampQuality_SYNCHRONIZED);
  Binary_in_BinaryOver6(&bBinary, true, fFlags, dDNPTime);
  tmp = Write_in_PrefixedWriteIterator_for_UInt16_Binary(&iter, &bBinary, 7);
  qDebug()<<"REQUIRE(!iter.Write(Binary(true, Flags(0x01), DNPTime(0x0C, TimestampQuality::SYNCHRONIZED)), 7))";
  qDebug()<<"boolean temp= "<<tmp;

  PrefixedWriteIterator_for_UInt16_Binary_destr_PrefixedWriteIterator_for_UInt16_Binary(&iter);

  RSeq_for_Uint16_t rseq = ToRSeq_in_APDUWrapper(&(response.aAPDUWrapper));
  qDebug()<<"REQUIRE('C0 81 00 00 33 01 07 01 AA 00 00 00 00 00 02 03 28 01 00 06 00 81 0B 00'";
  qDebug()<<"rseq.buffer_[0]= "<<hex<<rseq.buffer_[0]  <<hex<<rseq.buffer_[1]  <<hex<<rseq.buffer_[2]  <<hex<<rseq.buffer_[3]
          <<hex<<rseq.buffer_[4]  <<hex<<rseq.buffer_[5]  <<hex<<rseq.buffer_[6]  <<hex<<rseq.buffer_[7]
          <<hex<<rseq.buffer_[8]  <<hex<<rseq.buffer_[9]  <<hex<<rseq.buffer_[10] <<hex<<rseq.buffer_[11]
          <<hex<<rseq.buffer_[12] <<hex<<rseq.buffer_[13] <<hex<<rseq.buffer_[14] <<hex<<rseq.buffer_[15]
          <<hex<<rseq.buffer_[16] <<hex<<rseq.buffer_[17] <<hex<<rseq.buffer_[18] <<hex<<rseq.buffer_[19]
          <<hex<<rseq.buffer_[20] <<hex<<rseq.buffer_[21] <<hex<<rseq.buffer_[22] <<hex<<rseq.buffer_[23];
/*
     APDUResponse response = Response_in_APDUHelpers_static(SIZE_in_APDUHelpers);
//    auto writer = response.GetWriter();
     HeaderWriter writer = GetWriter_in_APDUWrapper(&(response.aAPDUWrapper));

    Group51Var1 cto;
////    cto.time = DNPTime(0xAA);
   DNPTime_in_DNPTimeOver2(&(cto.timeDNPTime), 0xAA);

  DNP3Serializer_for_Binary serializer = Inst_in_Group2Var3_static();

  PrefixedWriteIterator_for_UInt16_Binary iter = IterateOverCountWithPrefixAndCTO_for_UInt16_Binary_Group51Var1_in_HeaderWriter(&writer,
                                                              QualifierCode_UINT16_CNT_UINT16_INDEX,
                                                              &serializer,
                                                              &cto);

    boolean tmp = IsValid_in_PrefixedWriteIterator_for_UInt16_Binary(&iter);
               qDebug()<<"REQUIRE(iterator.IsValid())";
               qDebug()<<"boolean temp= "<<tmp;

    Flags fFlags;
    Flags_In_FlagsOver2(&fFlags, 0x01);
    DNPTime dDNPTime;
    DNPTime_in_DNPTimeOver3(&dDNPTime, 0x0B, TimestampQuality_SYNCHRONIZED);
    Binary bBinary;
    Binary_in_BinaryOver4(&bBinary, fFlags, dDNPTime);

    tmp = Write_in_PrefixedWriteIterator_for_UInt16_Binary(&iter, &bBinary, 6);
               qDebug()<<"REQUIRE(iter.Write(Binary(true, Flags(0x01), DNPTime(0x0B, TimestampQuality::SYNCHRONIZED)), 6))";
               qDebug()<<"boolean temp= "<<tmp;

    Flags_In_FlagsOver2(&fFlags, 0x01);
    DNPTime_in_DNPTimeOver3(&dDNPTime, 0x0C, TimestampQuality_SYNCHRONIZED);
    Binary_in_BinaryOver4(&bBinary, fFlags, dDNPTime);
    tmp = Write_in_PrefixedWriteIterator_for_UInt16_Binary(&iter, &bBinary, 7);
               qDebug()<<"REQUIRE(iter.Write(Binary(true, Flags(0x01), DNPTime(0x0C, TimestampQuality::SYNCHRONIZED)), 7))";
               qDebug()<<"boolean temp= "<<tmp;

   PrefixedWriteIterator_for_UInt16_Binary_destr_PrefixedWriteIterator_for_UInt16_Binary(&iter);

     RSeq_for_Uint16_t rseq = ToRSeq_in_APDUWrapper(&(response.aAPDUWrapper));
    qDebug()<<"REQUIRE('C0 81 00 00 33 01 07 01 AA 00 00 00 00 00 02 03 28 02 00 06 00 81 0B 00 07 00 81 0C 00'";
     qDebug()<<"rseq.buffer_[0]= "<<hex<<rseq.buffer_[0]  <<hex<<rseq.buffer_[1]  <<hex<<rseq.buffer_[2]  <<hex<<rseq.buffer_[3]
                                  <<hex<<rseq.buffer_[4]  <<hex<<rseq.buffer_[5]  <<hex<<rseq.buffer_[6]  <<hex<<rseq.buffer_[7]
                                  <<hex<<rseq.buffer_[8]  <<hex<<rseq.buffer_[9]  <<hex<<rseq.buffer_[10] <<hex<<rseq.buffer_[11]
                                  <<hex<<rseq.buffer_[12] <<hex<<rseq.buffer_[13] <<hex<<rseq.buffer_[14] <<hex<<rseq.buffer_[15]
                                  <<hex<<rseq.buffer_[16] <<hex<<rseq.buffer_[17] <<hex<<rseq.buffer_[18] <<hex<<rseq.buffer_[19]
                                  <<hex<<rseq.buffer_[20] <<hex<<rseq.buffer_[21] <<hex<<rseq.buffer_[22] <<hex<<rseq.buffer_[23]
                                  <<hex<<rseq.buffer_[24] <<hex<<rseq.buffer_[25] <<hex<<rseq.buffer_[26] <<hex<<rseq.buffer_[27]
                                  <<hex<<rseq.buffer_[28];
*/
  MainWindow mainWindowObj;
  mainWindow = &mainWindowObj;


  mainWindowObj.resize(600, 800);
  mainWindowObj.show();
  return app.exec();
}


key_filter::key_filter(QObject *parent)
  : QObject(parent)
{
}

bool key_filter::eventFilter(QObject *obj, QEvent *event)
{
  UNUSED(obj);

  if(event->type() == QEvent::KeyPress)
  {
    QKeyEvent *ke = static_cast<QKeyEvent*>(event);
    int myKey = ke->key();

    switch(myKey)
    {
    case  Qt::Key_Asterisk:
      emit sig_key_asterisk();
      return true;
    }//switch

    if(ke->modifiers()==Qt::NoModifier)
    switch(myKey)
    {
    case  Qt::Key_1:
      emit sig_key_1();
      return true;
    case  Qt::Key_2:
      emit sig_key_2();
      return true;
    case  Qt::Key_3:
      emit sig_key_3();
      return true;
    case  Qt::Key_4:
      emit sig_key_4();
      return true;

    case  Qt::Key_5:
      emit sig_key_5();
      return true;
    case  Qt::Key_6:
      emit sig_key_6();
      return true;
    case  Qt::Key_7:
      emit sig_key_7();
      return true;
    case  Qt::Key_8:
      emit sig_key_8();
      return true;

    case  Qt::Key_Up:
      emit sig_key_up();
      return true;
    case  Qt::Key_Down:
      emit sig_key_down();
      return true;
    case  Qt::Key_PageDown:
      emit sig_key_pgDown();
      return true;
    case  Qt::Key_PageUp:
      emit sig_key_pgUp();
      return true;
    case  Qt::Key_Left:
      emit sig_key_left();
      return true;
    case  Qt::Key_Right:
      emit sig_key_right();
      return true;
    case  Qt::Key_Home:
      emit sig_key_home();
      return true;
    case  Qt::Key_End:
      emit sig_key_end();
      return true;
    case  Qt::Key_Insert:
      emit sig_key_enter();
      return true;
    case  Qt::Key_Delete:
      emit sig_key_esc();
      return true;
    case  Qt::Key_Escape:
      emit sig_key_esc();
      return true;

    case  Qt::Key_F1:
      emit sig_key_f1();
      return true;
    case  Qt::Key_F2:
      emit sig_key_f2();
      return true;
    case  Qt::Key_F3:
      emit sig_key_f3();
      return true;

    case  Qt::Key_F8:
      emit sig_key_f8();
      return true;
    }//switch

   if(ke->modifiers()!=Qt::ControlModifier) return false;
    switch(myKey)
    {
    case  Qt::Key_1:
      emit sig_ctrlkey(0);
      return true;
    case  Qt::Key_2:
      emit sig_ctrlkey(1);
      return true;
    case  Qt::Key_3:
      emit sig_ctrlkey(2);
      return true;
    case  Qt::Key_4:
      emit sig_ctrlkey(3);
      return true;
    case  Qt::Key_5:
      emit sig_ctrlkey(4);
      return true;
    case  Qt::Key_6:
      emit sig_ctrlkey(5);
      return true;
    case  Qt::Key_7:
      emit sig_ctrlkey(6);
      return true;
    case  Qt::Key_8:
      emit sig_ctrlkey(7);
      return true;
    }//switch

  }
  return false;
}

