
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

#define UNUSED(x) (void)(x)


key_filter *pkf;

MainWindow *mainWindow;

void apply_in_5EventBufferOverflowAndClear(IUpdateHandler*);
void apply_in_5EventBufferOverflowAndClear(IUpdateHandler* db)
{
    std::cout << "apply_in_5EventBufferOverflowAndClear1" <<'\n';
////    t.Transaction([](IUpdateHandler& db) {
////        db.Update(Binary(true, Flags(0x01)), 0); // this event is lost in the overflow
////        db.Update(Binary(true, Flags(0x01)), 1);
////        db.Update(Binary(true, Flags(0x01)), 2);
////    });
 Flags fFlags;
 Flags_In_FlagsOver2(&fFlags, 1);

//void Binary_in_BinaryOver5(Binary *pBinary, boolean value, Flags flags);
 Binary bBinary;
 Binary_in_BinaryOver5(&bBinary, true, fFlags);

//boolean Update_Binary_in_IUpdateHandler(IUpdateHandler*, Binary* meas, uint16_t index, EventMode_uint8_t mode);// = EventMode::Detect) = 0;
////            db.Update(Binary(true, Flags(0x01)), 0); 
 Update_Binary_in_IUpdateHandler(db, &bBinary, 0, EventMode_Detect);// = EventMode::Detect) = 0;
 Update_Binary_in_IUpdateHandler(db, &bBinary, 1, EventMode_Detect);// = EventMode::Detect) = 0;
 Update_Binary_in_IUpdateHandler(db, &bBinary, 2, EventMode_Detect);// = EventMode::Detect) = 0;
}

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);


qDebug()<<"********SUITE('5EventBufferOverflowAndClear')********";
    OutstationConfig config;
    OutstationConfig_in_OutstationConfig(&config);

////    config.eventBufferConfig = EventBufferConfig::AllTypes(2);
   EventBufferConfig etemp = AllTypes_in_EventBufferConfig_static(MAX_EventRecord);
   config.eventBufferConfig = etemp;


////    OutstationTestObject t(config, configure::by_count_of::all_types(100));
//    DatabaseConfig tmp = binary_input_in_DatabaseHelpers(1);
  DatabaseConfig tmp = all_types_in_DatabaseHelpers(100);

    OutstationTestObject t;
    OutstationTestObject_in_OutstationTestObject(&t, &config, &tmp);

    LowerLayerUp_in_OutstationTestObject(&t);

////    t.Transaction([](IUpdateHandler& db) {
////        db.Update(Binary(true, Flags(0x01)), 0); // this event is lost in the overflow
////        db.Update(Binary(true, Flags(0x01)), 1);
////        db.Update(Binary(true, Flags(0x01)), 2);
////    });

    Transaction_in_OutstationTestObject(&t, apply_in_5EventBufferOverflowAndClear);//void (*apply)(IUpdateHandler*));

//StaticDataCell_for_Binary ttt = t.context.database.binary_input[0];
///    t.SendToOutstation("C0 01");
///    REQUIRE("C0 81 82 08" == t.lower->PopWriteAsHex());
///    t.OnTxReady();

    std::string name("C0 01");       

    SendToOutstation_in_OutstationTestObject(&t, name);  

    std::string temp = PopWriteAsHex_in_MockLowerLayer(&(t.lower));

    std::cout << "name= " << name<<'\n';
qDebug()<<"REQUIRE('C0 81 82 08' == t.lower->PopWriteAsHex())";
std::cout << "temp= " << temp<<'\n';

/*
TEST_CASE(SUITE("5EventBufferOverflowAndClear"))
{
    OutstationConfig config;
    config.eventBufferConfig = EventBufferConfig::AllTypes(2);
    OutstationTestObject t(config, configure::by_count_of::all_types(100));

    t.LowerLayerUp();

    t.Transaction([](IUpdateHandler& db) {
        db.Update(Binary(true, Flags(0x01)), 0); // this event is lost in the overflow
        db.Update(Binary(true, Flags(0x01)), 1);
        db.Update(Binary(true, Flags(0x01)), 2);
    });

    t.SendToOutstation("C0 01");
    REQUIRE("C0 81 82 08" == t.lower->PopWriteAsHex());
    t.OnTxReady();

    t.SendToOutstation("C1 01 3C 02 07 01"); // class 1, count of 1
    REQUIRE("E1 81 82 08 02 01 28 01 00 01 00 81" == t.lower->PopWriteAsHex());
    t.OnTxReady();
    t.SendToOutstation(hex::SolicitedConfirm(1));

    // Check that the confirm is reported to the IOutstationApplication
    REQUIRE(t.application->confirms.size() == 1);
    REQUIRE(t.application->confirms[0].is_unsolicited == false);
    REQUIRE(t.application->confirms[0].num_class1 == 1);
    REQUIRE(t.application->confirms[0].num_class2 == 0);
    REQUIRE(t.application->confirms[0].num_class3 == 0);

    t.SendToOutstation("C0 01");
    REQUIRE("C0 81 82 00" == t.lower->PopWriteAsHex());
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

