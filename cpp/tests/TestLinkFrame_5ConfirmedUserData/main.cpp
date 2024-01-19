
#include <QApplication>
#include <QtWidgets>

#include <stdlib.h>
#include <iostream>

#include "MainWindow.h"
#include "key_filter.h"

#include "header.h"

#include "FormatUserData.h"

#define UNUSED(x) (void)(x)

key_filter *pkf;

MainWindow *mainWindow;

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);

qDebug()<<"********SUITE('5ConfirmedUserData')********";
////    Buffer buffer(292);
    // Confirmed User Data - Master (FCB = true)
////    auto hex = FormatUserData(true, true, 1, 1024, "C0 C3 01 3C 02 06 3C 03 06 3C 04 06 3C 01 06", true);
////    REQUIRE(hex == "05 64 14 F3 01 00 00 04 0A 3B C0 C3 01 3C 02 06 3C 03 06 3C 04 06 3C 01 06 9A 12");

//std::string FormatUserDataStr(
//  boolean aIsMaster, boolean aIsConfirmed, int aDest, int aSrc, std::string& data, boolean aFcb);/// = false)
////    auto hex = FormatUserData(true, true, 1, 1024, "C0 C3 01 3C 02 06 3C 03 06 3C 04 06 3C 01 06", true);
std::string name1 = "C0 C3 01 3C 02 06 3C 03 06 3C 04 06 3C 01 06";

//05 64 1C 44 03 00 04 00 64 BD 
std::string name2 = "C7 C6 83 90 00 78 01 5B 01 0C 00 03 00 00 00 00 92 87 00 04 01 73 74";// 65 76";// 80 5C";
/*
05 64 1E F3 01 00 00 04 61 87 C7 C6 83 90 00 78 01 5B 01 0C 00 03 00 00 00 00 92 87 92 87 00 04 01 73 74 65 76 7E C2
05 64 1C F3 01 00 00 04 D6 A1 C7 C6 83 90 00 78 01 5B 01 0C 00 03 00 00 00 00 92 87 92 87 00 04 01 73 74 FD 52
*/

std::string stemp = FormatUserDataStr(
  true, true, 1, 1024, name2, true);/// = false)
////    REQUIRE(hex == "05 64 14 F3 01 00 00 04 0A 3B C0 C3 01 3C 02 06 3C 03 06 3C 04 06 3C 01 06 9A 12");
qDebug()<<"REQUIRE(hex == '05 64 14 F3 01 00 00 04 0A 3B C0 C3 01 3C 02 06 3C 03 06 3C 04 06 3C 01 06 9A 12')";
std::cout<<"stemp= "<<stemp<<'\n';

/*
TEST_CASE(SUITE("5ConfirmedUserData"))
{
    Buffer buffer(292);

    // Confirmed User Data - Master (FCB = true)
    auto hex = FormatUserData(true, true, 1, 1024, "C0 C3 01 3C 02 06 3C 03 06 3C 04 06 3C 01 06", true);
    REQUIRE(hex == "05 64 14 F3 01 00 00 04 0A 3B C0 C3 01 3C 02 06 3C 03 06 3C 04 06 3C 01 06 9A 12");

    // Confirmed User Data - Outstation (FCB = true)
    auto hex2 = FormatUserData(false, true, 1024, 1,
                               "C1 E3 81 96 00 02 01 28 01 00 00 00 01 02 01 28 01 00 01 00 01 02 01 28 01 00 02 00 01 "
                               "02 01 28 01 00 03 00 01 20 02 28 01 00 00 00 01 00 00 20 02 28 01 00 01 00 01 00 00 01 "
                               "01 01 00 00 03 00 00 1E 02 01 00 00 01 00 01 00 00 01 00 00",
                               true);
    REQUIRE(hex2
            == "05 64 53 73 00 04 01 00 03 FC C1 E3 81 96 00 02 01 28 01 00 00 00 01 02 01 28 05 24 01 00 01 00 01 02 "
               "01 28 01 00 02 00 01 02 01 28 B4 77 01 00 03 00 01 20 02 28 01 00 00 00 01 00 00 20 A5 25 02 28 01 00 "
               "01 00 01 00 00 01 01 01 00 00 03 00 2F AC 00 1E 02 01 00 00 01 00 01 00 00 01 00 00 16 ED");
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

