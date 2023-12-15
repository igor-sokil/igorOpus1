
#include <QApplication>
#include <QtWidgets>

#include <stdlib.h>
#include <iostream>
#include <string>

#include "MainWindow.h"
#include "key_filter.h"

#include "header.h"

#include "LinkParserTest.h"
#include "DNPHelpers.h"
#include "BufferSer4.h"

#define UNUSED(x) (void)(x)


key_filter *pkf;

MainWindow *mainWindow;

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);

qDebug()<<"********SUITE('12ReadNACK')********";
////    Buffer buffer(292);
////    auto writeTo = buffer.as_wslice();
////    auto frame = LinkFrame::FormatNack(writeTo, false, true, 1, 2, nullptr);


 BufferSer4 buffer;
 BufferSer4_in_BufferSer4Over2(&buffer, 292);

////    auto writeTo = buffer.as_wslice();
WSeq_for_Uint16_t writeTo = as_wslice_in_BufferSer4(&buffer);

//RSeq_for_Uint16_t frame = FormatAck_in_LinkFrame_static(
//  WSeq_for_Uint16_t* buffer, boolean aIsMaster, boolean aIsRcvBuffFull, uint16_t aDest, uint16_t aSrc);//, Logger* pLogger);
////    auto frame = LinkFrame::FormatNack(writeTo, false, true, 1, 2, nullptr);
RSeq_for_Uint16_t frame = FormatNack_in_LinkFrame_static(
  &writeTo, false, true, 1, 2);//, Logger* pLogger);

inspect_RSeq(&frame);

////    LinkParserTest t;
////    t.WriteData(frame);
////    REQUIRE(t.sink.m_num_frames == 1);
////    REQUIRE(t.sink.CheckLastWithDFC(LinkFunction::SEC_NACK, false, true, 1, 2));

  LinkParserTest t;
  LinkParserTest_in_LinkParserTest(&t, false);// = false)

 WriteData_in_LinkParserTestOver1(&t, &frame);

qDebug()<<"REQUIRE(t.sink.m_num_frames == 1)";
qDebug()<<"t.sink.m_num_frames= "<<t.sink.m_num_frames;

////    REQUIRE(t.sink.CheckLastWithDFC(LinkFunction::SEC_NACK, false, true, 1, 2));
boolean tmp = CheckLastWithDFC_in_MockFrameSink(&(t.sink),
    LinkFunction_SEC_NACK, false, true, 1, 2);
qDebug()<<"REQUIRE(t.sink.CheckLastWithDFC(LinkFunction::SEC_NACK, false, true, 1, 2))";
qDebug()<<"tmp= "<<tmp;


/*
TEST_CASE(SUITE("12ReadNACK"))
{
    Buffer buffer(292);
    auto writeTo = buffer.as_wslice();
    auto frame = LinkFrame::FormatNack(writeTo, false, true, 1, 2, nullptr);

    LinkParserTest t;
    t.WriteData(frame);
    REQUIRE(t.sink.m_num_frames == 1);
    REQUIRE(t.sink.CheckLastWithDFC(LinkFunction::SEC_NACK, false, true, 1, 2));
}
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

