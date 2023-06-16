
#include <QApplication>
#include <QtWidgets>

#include <stdlib.h>

#include "MainWindow.h"
#include "key_filter.h"

#include "header.h"
/*
#include "APDUHelpers.h"
#include "APDUHeader.h"
#include "SerializationTemplates.h"
#include "Group2.h"
#include "EventStorage.h"

#include <EventType.h>
#include <MeasurementInfo.h>

#include <IEventWriteHandler.h>

#include <deque>
*/
#include "BufferSer4.h"
#include "LinkFrame.h"
#include "loghandler.h"


#define UNUSED(x) (void)(x)


key_filter *pkf;

MainWindow *mainWindow;

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);
/*
TEST_CASE(SUITE("ResetLinks"))
{
    Buffer buffer(292);

    // ResetLinkStates - Master
    auto write = buffer.as_wslice();
    auto wrapper = LinkFrame::FormatResetLinkStates(write, true, 1, 1024, nullptr);
    REQUIRE(HexConversions::to_hex(wrapper) == "05 64 05 C0 01 00 00 04 E9 21");
}
*/
////    Buffer buffer(292);
//   void BufferSer4_in_BufferSer4Over2(BufferSer4 *pBufferSer4, uint16_t length);
    BufferSer4 buffer;
    BufferSer4_in_BufferSer4Over2(&buffer, MAX_BufferSer4);

    // ResetLinkStates - Master
//    WSeq_for_Uint16_t as_wslice_in_BufferSer4(BufferSer4 *pBufferSer4);
////    auto write = buffer.as_wslice();
    WSeq_for_Uint16_t write = as_wslice_in_BufferSer4(&buffer);

//    RSeq_for_Uint16_t FormatResetLinkStates_in_LinkFrame_static(
//        WSeq_for_Uint16_t* buffer, boolean aIsMaster, uint16_t aDest, uint16_t aSrc);//, Logger* pLogger);
////    auto wrapper = LinkFrame::FormatResetLinkStates(write, true, 1, 1024, nullptr);
    RSeq_for_Uint16_t rseq = FormatResetLinkStates_in_LinkFrame_static(
        &write, true, 1, 1024);//, Logger* pLogger);

////    REQUIRE(HexConversions::to_hex(wrapper) == "05 64 05 C0 01 00 00 04 E9 21");
    qDebug()<<"REQUIRE(HexConversions::to_hex(wrapper) == '05 64 05 C0 01 00 00 04 E9 21')";
     qDebug()<<"rseq.buffer_[0]= "<<hex<<rseq.buffer_[0] <<hex<<rseq.buffer_[1] <<hex<<rseq.buffer_[2] <<hex<<rseq.buffer_[3]
                                  <<hex<<rseq.buffer_[4] <<hex<<rseq.buffer_[5] <<hex<<rseq.buffer_[6] <<hex<<rseq.buffer_[7]
                                  <<hex<<rseq.buffer_[8] <<hex<<rseq.buffer_[9];

/*
//   void LinkHeader_in_LinkHeaderOver2(LinkHeader *pLinkHeader, uint8_t len, uint16_t src, uint16_t dest, boolean aFromMaster, boolean fcvdfc, boolean fcb, LinkFunction_uint8_t aCode);
////    LinkHeader hdr(5, 1, 1024, true, true, true, LinkFunction::PRI_CONFIRMED_USER_DATA);
   LinkHeader lLinkHeader;
   LinkHeader_in_LinkHeaderOver2(&lLinkHeader, 5, 1, 1024, true, true, true, LinkFunction_PRI_CONFIRMED_USER_DATA);

//    uint8_t ControlByte_in_LinkHeader_static(boolean isMaster, boolean fcb, boolean fcvdfc, LinkFunction_uint8_t func);
////    REQUIRE(hdr.ControlByte(true, true, true, LinkFunction::PRI_CONFIRMED_USER_DATA) == hdr.GetControl());
    uint8_t getctrb1 = ControlByte_in_LinkHeader_static(true, true, true, LinkFunction_PRI_CONFIRMED_USER_DATA);
   uint8_t getctrc1 = GetControl_in_LinkHeader(&lLinkHeader);
  qDebug()<<"REQUIRE(hdr.ControlByte(true, true, true, LinkFunction::PRI_CONFIRMED_USER_DATA) == hdr.GetControl())";
  qDebug()<<"getctrb1= "<<getctrb1;
  qDebug()<<"getctrc1= "<<getctrc1;
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

