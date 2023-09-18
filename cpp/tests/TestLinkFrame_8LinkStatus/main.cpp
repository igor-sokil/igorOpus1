
#include <QApplication>
#include <QtWidgets>

#include <stdlib.h>
#include <iostream>

#include "MainWindow.h"
#include "key_filter.h"

#include "header.h"

//#include "OutstationConfig.h"
#include "BufferSer4.h"
#include "LinkFrame.h"
//#include "loghandler.h"
#include "RSeq.h"
#include "WSeq.h"
#include "HexConversions.h"
#include "DNPHelpers.h"

QString FormatUserData(
    boolean aIsMaster, boolean aIsConfirmed, int aDest, int aSrc, /*const std::string& data,*/uint8_t* data, uint16_t size_data, boolean aFcb);/// = false)

#define UNUSED(x) (void)(x)

void* pPointerGlobal1;
void* pPointerGlobal2;
void* pPointerGlobal3;

key_filter *pkf;

MainWindow *mainWindow;

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);

qDebug()<<"********SUITE('8LinkStatus')********";
    BufferSer4 buffer;
    BufferSer4_in_BufferSer4Over2(&buffer, MAX_BufferSer4);

////    auto writeTo = buffer.as_wslice();
    WSeq_for_Uint16_t writeTo = as_wslice_in_BufferSer4(&buffer);

//RSeq_for_Uint16_t FormatLinkStatus_in_LinkFrame_static(
//  WSeq_for_Uint16_t* buffer, boolean aIsMaster, boolean aIsRcvBuffFull, uint16_t aDest, uint16_t aSrc);//, Logger* pLogger);
////    auto wrapper = LinkFrame::FormatLinkStatus(writeTo, true, true, 1, 1024, nullptr);
RSeq_for_Uint16_t wrapper = FormatLinkStatus_in_LinkFrame_static(
  &writeTo, true, true, 1, 1024);//, Logger* pLogger);

    // take a length 10 frame, set the control to 9B and repair the CRC
////    REQUIRE(HexConversions::to_hex(wrapper) == RepairCRC("05 64 05 9B 01 00 00 04 E9 21"));
  std::string  str = to_hex_in_HexConversionsOver2(&wrapper, true);
  std::cout<<"str= "<<str<<std::endl;

////    REQUIRE(HexConversions::to_hex(wrapper) == RepairCRC("05 64 05 9B 01 00 00 04 E9 21"));
  std::string name1("05 64 05 9B 01 00 00 04 E9 21");       
std::string sss = RepairCRC_in_DNPHelpers(name1);
//      qDebug()<<"sss= "<<sss;
  std::cout<<"sss= "<<sss;
//sss= 05 64 05 9B 01 00 00 04 82 8B

/*
TEST_CASE(SUITE("8LinkStatus"))
{
    Buffer buffer(292);

    // LinkStatus - Master (DFC = true)
    auto writeTo = buffer.as_wslice();
    auto wrapper = LinkFrame::FormatLinkStatus(writeTo, true, true, 1, 1024, nullptr);
    // take a length 10 frame, set the control to 9B and repair the CRC
    REQUIRE(HexConversions::to_hex(wrapper) == RepairCRC("05 64 05 9B 01 00 00 04 E9 21"));
}
*/
/*
    BufferSer4 buffer;
    BufferSer4_in_BufferSer4Over2(&buffer, MAX_BufferSer4);

////    auto writeTo = buffer.as_wslice();
    WSeq_for_Uint16_t writeTo = as_wslice_in_BufferSer4(&buffer);

//RSeq_for_Uint16_t FormatResetLinkStates_in_LinkFrame_static(
//  WSeq_for_Uint16_t* buffer, boolean aIsMaster, uint16_t aDest, uint16_t aSrc);//, Logger* pLogger);
////    auto wrapper = LinkFrame::FormatResetLinkStates(writeTo, false, 1024, 1, nullptr);
RSeq_for_Uint16_t wrapper = FormatResetLinkStates_in_LinkFrame_static(
  &writeTo, false, 1024, 1);//, Logger* pLogger);

  std::cout<<"REQUIRE(HexConversions::to_hex(wrapper) == '05 64 05 40 00 04 01 00 A3 96')"<<std::endl;
  std::string  str = to_hex_in_HexConversionsOver2(&wrapper, true);
  std::cout<<"str= "<<str<<std::endl;
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

