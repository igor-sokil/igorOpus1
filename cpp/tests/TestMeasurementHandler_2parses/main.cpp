
#include <QApplication>
#include <QtWidgets>

#include <stdlib.h>
#include <iostream>
#include <string>

#include "MainWindow.h"
#include "key_filter.h"

#include "header.h"

#include "TestMeasurementHandler.h"
//#include "DNPHelpers.h"
#include "MockSOEHandler.h"

#define UNUSED(x) (void)(x)


key_filter *pkf;

MainWindow *mainWindow;

void verify(MockSOEHandler*);
void verify(MockSOEHandler* soe)
{
////    auto verify = [](MockSOEHandler& soe) { REQUIRE(soe.TotalReceived() == 0); };
qDebug()<<"REQUIRE(soe.TotalReceived() == 2)";
qDebug()<<"tmp= "<<TotalReceived_in_MockSOEHandler(soe);
qDebug()<<"REQUIRE(soe.timeSOE.size() == 2)";
qDebug()<<"tmp= "<<soe->timeSOE.size();

////        REQUIRE(soe.timeSOE[0].value == 0xABABABABABAB);
qDebug()<<"REQUIRE(soe.timeSOE[0].value == 0xABABABABABAB)";
uint64_t dDNPTime = soe->timeSOE[0].value;
std::cout<<"uint64_t dDNPTime1= "<<std::hex<<dDNPTime<<std::dec<<'\n';
////        REQUIRE(soe.timeSOE[1].value == 0xBCBCBCBCBCBC);
qDebug()<<"REQUIRE(soe.timeSOE[1].value == 0xBCBCBCBCBCBC)";
 dDNPTime = soe->timeSOE[1].value;
std::cout<<"uint64_t dDNPTime2= "<<std::hex<<dDNPTime<<std::dec<<'\n';
}

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);

qDebug()<<"********SUITE('2parses g50v1 correctly')********";
////    auto verify = [](MockSOEHandler& soe) {
////        REQUIRE(soe.TotalReceived() == 2);
////        REQUIRE(soe.timeSOE.size() == 2);
////        REQUIRE(soe.timeSOE[0].value == 0xABABABABABAB);
////        REQUIRE(soe.timeSOE[1].value == 0xBCBCBCBCBCBC);
////    };
////    // g50v1 count of 2
////    auto objects = "32 01 07 02 AB AB AB AB AB AB BC BC BC BC BC BC";
////    TestObjectHeaders(objects, ParseResult::OK, verify);

////    auto objects = "32 01 07 02 AB AB AB AB AB AB BC BC BC BC BC BC";
 std::string objects = "32 01 07 02 AB AB AB AB AB AB BC BC BC BC BC BC";
 TestObjectHeaders( objects, ParseResult_OK, verify);

/*
TEST_CASE(SUITE("2parses g50v1 correctly"))
{
    auto verify = [](MockSOEHandler& soe) {
        REQUIRE(soe.TotalReceived() == 2);
        REQUIRE(soe.timeSOE.size() == 2);
        REQUIRE(soe.timeSOE[0].value == 0xABABABABABAB);
        REQUIRE(soe.timeSOE[1].value == 0xBCBCBCBCBCBC);
    };

    // g50v1 count of 2
    auto objects = "32 01 07 02 AB AB AB AB AB AB BC BC BC BC BC BC";

    TestObjectHeaders(objects, ParseResult::OK, verify);
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

