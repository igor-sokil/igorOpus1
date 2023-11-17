
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

void configure_in_10MixedClassLimitedCount(DatabaseConfig*);
void configure_in_10MixedClassLimitedCount(DatabaseConfig* db)
{
////    auto configure = [](DatabaseConfig& db) {
////        db.binary_input[0].clazz = PointClass::Class1;
////        db.binary_input[1].clazz = PointClass::Class2;
////        db.binary_input[2].clazz = PointClass::Class3;
////    };
        db->binary_input[0].eEventConfig.clazz = PointClass_Class1;
        db->binary_input[1].eEventConfig.clazz = PointClass_Class2;
        db->binary_input[2].eEventConfig.clazz = PointClass_Class3;
}

void update_in_10MixedClassLimitedCount(IUpdateHandler*);
void update_in_10MixedClassLimitedCount(IUpdateHandler* db)
{
    std::cout << "update_in_10MixedClassLimitedCount" <<'\n';
////    auto update = [](IUpdateHandler& db) {
////        db.Update(Binary(false, Flags(0x01)), 0);

////        db.Update(Binary(true, Flags(0x01)), 1);
////        db.Update(Binary(false, Flags(0x01)), 1);

////        db.Update(Binary(true, Flags(0x01)), 2);
////        db.Update(Binary(false, Flags(0x01)), 2);
////    };

 Flags fFlags;
 Flags_In_FlagsOver2(&fFlags, 1);

//void Binary_in_BinaryOver5(Binary *pBinary, boolean value, Flags flags);
 Binary bBinary1;
 Binary_in_BinaryOver5(&bBinary1, false, fFlags);
 Binary bBinary2;
 Binary_in_BinaryOver5(&bBinary2, true, fFlags);

//boolean Update_Binary_in_IUpdateHandler(IUpdateHandler*, Binary* meas, uint16_t index, EventMode_uint8_t mode);// = EventMode::Detect) = 0;
         Update_Binary_in_IUpdateHandler(db, &bBinary1, 0, EventMode_Detect);// = EventMode::Detect) = 0;
         Update_Binary_in_IUpdateHandler(db, &bBinary2, 1, EventMode_Detect);// = EventMode::Detect) = 0;
         Update_Binary_in_IUpdateHandler(db, &bBinary1, 1, EventMode_Detect);// = EventMode::Detect) = 0;

         Update_Binary_in_IUpdateHandler(db, &bBinary2, 2, EventMode_Detect);// = EventMode::Detect) = 0;
         Update_Binary_in_IUpdateHandler(db, &bBinary1, 2, EventMode_Detect);// = EventMode::Detect) = 0;
}

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);


qDebug()<<"********SUITE('10MixedClassLimitedCount')********";
    // read 1 class 2 event and 1 class 3 event, 1 of each event type left in buffer
    // get back two g2v1 events in the same header for indices 1 & 2
// читаем 1 событие класса 2 и 1 событие класса 3, по одному события каждого типа осталось в буфере
     // возвращаем два события g2v1 в одном заголовке для индексов 1 и 2
////    TestEventRead("C0 01 3C 03 07 01 3C 04 07 01", "E0 81 8E 00 02 01 28 02 00 01 00 81 02 00 81", update, configure);

 std::string request("C0 01 3C 03 07 01 3C 04 07 01");       
 std::string response("E0 81 8E 00 02 01 28 02 00 01 00 81 02 00 81");       
 TestEventRead(request, response,
                   ////const std::function<void(IUpdateHandler& db)>& loadFun,
                   update_in_10MixedClassLimitedCount,
                   ////const std::function<void(DatabaseConfig& db)>& configure = [](DatabaseConfig& view) {})
                   configure_in_10MixedClassLimitedCount);

/*
TEST_CASE(SUITE("10MixedClassLimitedCount"))
{
    auto configure = [](DatabaseConfig& db) {
        db.binary_input[0].clazz = PointClass::Class1;
        db.binary_input[1].clazz = PointClass::Class2;
        db.binary_input[2].clazz = PointClass::Class3;
    };

    auto update = [](IUpdateHandler& db) {
        db.Update(Binary(false, Flags(0x01)), 0);

        db.Update(Binary(true, Flags(0x01)), 1);
        db.Update(Binary(false, Flags(0x01)), 1);

        db.Update(Binary(true, Flags(0x01)), 2);
        db.Update(Binary(false, Flags(0x01)), 2);
    };

    // read 1 class 2 event and 1 class 3 event, 1 of each event type left in buffer
    // get back two g2v1 events in the same header for indices 1 & 2
// читаем 1 событие класса 2 и 1 событие класса 3, по одному события каждого типа осталось в буфере
     // возвращаем два события g2v1 в одном заголовке для индексов 1 и 2
    TestEventRead("C0 01 3C 03 07 01 3C 04 07 01", "E0 81 8E 00 02 01 28 02 00 01 00 81 02 00 81", update, configure);
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

