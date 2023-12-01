
#include <QApplication>
#include <QtWidgets>

#include <stdlib.h>
#include <iostream>
#include <string>

#include "MainWindow.h"
#include "key_filter.h"

#include "header.h"

#include "OutstationConfig.h"
#include "OutstationTestObject.h"
#include "APDUHexBuilders.h"
#include "DatabaseHelpers.h"
#include "TestOutstationEventResponses.h"

#define UNUSED(x) (void)(x)


key_filter *pkf;

MainWindow *mainWindow;

void configure_in_25ReadGrp2Var3TwoValuesWithDifferentTimeQuality(DatabaseConfig*);
void configure_in_25ReadGrp2Var3TwoValuesWithDifferentTimeQuality(DatabaseConfig* db)
{
}

void update_in_25ReadGrp2Var3TwoValuesWithDifferentTimeQuality(IUpdateHandler*);
void update_in_25ReadGrp2Var3TwoValuesWithDifferentTimeQuality(IUpdateHandler* db)
{
    std::cout << "update_in_25ReadGrp2Var3TwoValuesWithDifferentTimeQuality" <<'\n';
////    auto update = [](IUpdateHandler& db) {
////        db.Update(Binary(false, Flags(0x01), DNPTime(0x4571, TimestampQuality::SYNCHRONIZED)), 3);
////        db.Update(Binary(true, Flags(0x01), DNPTime(0x4579, TimestampQuality::UNSYNCHRONIZED)), 4);
////    };

 Flags fFlags;
 Flags_In_FlagsOver2(&fFlags, 1);

 DNPTime dDNPTime1;
 DNPTime_in_DNPTimeOver3(&dDNPTime1, 0x4571, TimestampQuality_SYNCHRONIZED);
 DNPTime dDNPTime2;
 DNPTime_in_DNPTimeOver3(&dDNPTime2, 0x4579, TimestampQuality_UNSYNCHRONIZED);

 Binary bBinary1;
 Binary_in_BinaryOver6(&bBinary1, false, fFlags, dDNPTime1);

 Binary bBinary2;
 Binary_in_BinaryOver6(&bBinary2, true, fFlags, dDNPTime2);

 Update_Binary_in_IUpdateHandler(db, &bBinary1, 3, EventMode_Detect);// = EventMode::Detect) = 0;
 Update_Binary_in_IUpdateHandler(db, &bBinary2, 4, EventMode_Detect);// = EventMode::Detect) = 0;
}

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);


qDebug()<<"********SUITE('25ReadGrp2Var3TwoValuesWithDifferentTimeQuality')********";
////    std::string header = "E0 81 80 00";
////    std::string cto1 = " 33 01 07 01 71 45 00 00 00 00 02 03 28 01 00 03 00 01 00 00";
////    std::string cto2 = " 33 02 07 01 79 45 00 00 00 00 02 03 28 01 00 04 00 81 00 00";
////    auto rsp = header + cto1 + cto2;
////    TestEventRead("C0 01 02 03 06", rsp, update);

 std::string response("E0 81 80 00 33 01 07 01 71 45 00 00 00 00 02 03 28 01 00 03 00 01 00 00 33 02 07 01 79 45 00 00 00 00 02 03 28 01 00 04 00 81 00 00");       

 std::string request("C0 01 02 03 06");       
 TestEventRead(request, response,
                   ////const std::function<void(IUpdateHandler& db)>& loadFun,
                   update_in_25ReadGrp2Var3TwoValuesWithDifferentTimeQuality,
                   ////const std::function<void(DatabaseConfig& db)>& configure = [](DatabaseConfig& view) {})
                   configure_in_25ReadGrp2Var3TwoValuesWithDifferentTimeQuality);

/*
TEST_CASE(SUITE("25ReadGrp2Var3TwoValuesWithDifferentTimeQuality"))
{
    auto update = [](IUpdateHandler& db) {
        db.Update(Binary(false, Flags(0x01), DNPTime(0x4571, TimestampQuality::SYNCHRONIZED)), 3);
        db.Update(Binary(true, Flags(0x01), DNPTime(0x4579, TimestampQuality::UNSYNCHRONIZED)), 4);
    };

    std::string header = "E0 81 80 00";
    std::string cto1 = " 33 01 07 01 71 45 00 00 00 00 02 03 28 01 00 03 00 01 00 00";
    std::string cto2 = " 33 02 07 01 79 45 00 00 00 00 02 03 28 01 00 04 00 81 00 00";

    auto rsp = header + cto1 + cto2;

    TestEventRead("C0 01 02 03 06", rsp, update);
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

