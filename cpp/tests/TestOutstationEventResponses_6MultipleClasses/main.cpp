
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

void apply_in_6MultipleClasses(IUpdateHandler*);
void apply_in_6MultipleClasses(IUpdateHandler* db)
{
    std::cout << "apply_in_6MultipleClasses1" <<'\n';
////    t.Transaction([](IUpdateHandler& db) {
////        db.Update(Binary(true), 0);
////        db.Update(Analog(3), 0);
////        db.Update(Counter(7), 0);
////    });

//void Binary_in_BinaryOver5(Binary *pBinary, boolean value, Flags flags);
 Binary bBinary;
 Binary_in_BinaryOver2(&bBinary, true);

 Analog aAnalog;
 Analog_in_AnalogOver2(&aAnalog, 3.0);

 Counter cCounter;
 Counter_in_CounterOver2(&cCounter, 7);

//boolean Update_Binary_in_IUpdateHandler(IUpdateHandler*, Binary* meas, uint16_t index, EventMode_uint8_t mode);// = EventMode::Detect) = 0;
////            db.Update(Binary(true, Flags(0x01)), 0); 
 Update_Binary_in_IUpdateHandler(db, &bBinary, 0, EventMode_Detect);// = EventMode::Detect) = 0;
 Update_Analog_in_IUpdateHandler(db, &aAnalog, 0, EventMode_Detect);// = EventMode::Detect) = 0;
 Update_Counter_in_IUpdateHandler(db, &cCounter, 0, EventMode_Detect);// = EventMode::Detect) = 0;
}

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);


qDebug()<<"********SUITE('6MultipleClasses')********";
    OutstationConfig config;
    OutstationConfig_in_OutstationConfig(&config);

////    OutstationConfig config;
////    config.eventBufferConfig = EventBufferConfig::AllTypes(10);


////    OutstationTestObject t(config, std::move(database));
////    t.LowerLayerUp();


   EventBufferConfig etemp = AllTypes_in_EventBufferConfig_static(MAX_EventRecord);
   config.eventBufferConfig = etemp;


////    OutstationTestObject t(config, configure::by_count_of::all_types(100));
//    DatabaseConfig tmp = binary_input_in_DatabaseHelpers(1);
  DatabaseConfig database = all_types_in_DatabaseHelpers(100);

////    auto database = configure::by_count_of::all_types(100);
////    database.binary_input[0].clazz = PointClass::Class1;
  database.binary_input[0].eEventConfig.clazz = PointClass_Class1;
////    database.analog_input[0].clazz = PointClass::Class2;
  database.analog_input[0].dDeadbandConfig_for_AnalogInfo.eEventConfig.clazz = PointClass_Class2;
////    database.counter[0].clazz = PointClass::Class3;
  database.counter[0].dDeadbandConfig_for_CounterInfo.eEventConfig.clazz = PointClass_Class3;

    OutstationTestObject t;
    OutstationTestObject_in_OutstationTestObject(&t, &config, &database);

    LowerLayerUp_in_OutstationTestObject(&t);

////    t.Transaction([](IUpdateHandler& db) {
////        db.Update(Binary(true), 0);
////        db.Update(Analog(3), 0);
////        db.Update(Counter(7), 0);
////    });

    Transaction_in_OutstationTestObject(&t, apply_in_6MultipleClasses);//void (*apply)(IUpdateHandler*));

//StaticDataCell_for_Binary ttt = t.context.database.binary_input[0];
////    t.SendToOutstation("C0 01");                        // empty READ
////    REQUIRE(t.lower->PopWriteAsHex() == "C0 81 8E 00"); // all event bits set + restart

    std::string n1("C0 01");       

    SendToOutstation_in_OutstationTestObject(&t, n1);  

    std::string temp = PopWriteAsHex_in_MockLowerLayer(&(t.lower));

    std::cout << "n1= " << n1<<'\n';
qDebug()<<"REQUIRE('C0 81 8E 00' == t.lower->PopWriteAsHex())";
std::cout << "temp= " << temp<<'\n';

////    t.OnTxReady();
    OnTxReady_in_OutstationTestObject(&t);

    // ------ read 1 event at a time by class, until all events are gone ----
////    t.SendToOutstation(hex::ClassPoll(1, PointClass::Class2));                              // Class 2
////    REQUIRE(t.lower->PopWriteAsHex() == "E1 81 8A 00 20 01 28 01 00 00 00 01 03 00 00 00"); // restart + Class 1/3
    std::string name1 = ClassPoll_in_APDUHexBuilders(1, PointClass_Class2);
    SendToOutstation_in_OutstationTestObject(&t, name1);  

    std::string temp1 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));

    std::cout << "name1= " << name1<<'\n';
qDebug()<<"REQUIRE('E1 81 8A 00 20 01 28 01 00 00 00 01 03 00 00 00' == t.lower->PopWriteAsHex())";
std::cout << "temp1= " << temp1<<'\n';

////    t.OnTxReady();
    OnTxReady_in_OutstationTestObject(&t);

////    t.SendToOutstation("C1 00");
    std::string n2("C1 00");       
    SendToOutstation_in_OutstationTestObject(&t, n2);  
//----------------------------------------------------
////    t.SendToOutstation("C2 01 3C 04 06");                                                   // Class 3
    std::string name2("C2 01 3C 04 06");       
    SendToOutstation_in_OutstationTestObject(&t, name2);  

////    REQUIRE(t.lower->PopWriteAsHex() == "E2 81 82 00 16 01 28 01 00 00 00 01 07 00 00 00"); // restart + Class 1/3
////    t.OnTxReady();
    std::string temp2 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));

    std::cout << "name2= " << name2<<'\n';
qDebug()<<"REQUIRE('E2 81 82 00 16 01 28 01 00 00 00 01 07 00 00 00' == t.lower->PopWriteAsHex())";
std::cout << "temp2= " << temp2<<'\n';

////    t.OnTxReady();
    OnTxReady_in_OutstationTestObject(&t);

///    t.SendToOutstation("C2 00");
    std::string n3("C2 00");       
    SendToOutstation_in_OutstationTestObject(&t, n3);  
//----------------------------------------------------

////    t.SendToOutstation("C3 01 3C 02 06");                                       // Class 1
    std::string name3("C3 01 3C 02 06");       
    SendToOutstation_in_OutstationTestObject(&t, name3);  

////    REQUIRE(t.lower->PopWriteAsHex() == "E3 81 80 00 02 01 28 01 00 00 00 81"); // restart only
    std::string temp3 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));

    std::cout << "name3= " << name3<<'\n';
qDebug()<<"REQUIRE('E3 81 80 00 02 01 28 01 00 00 00 81' == t.lower->PopWriteAsHex())";
std::cout << "temp3= " << temp3<<'\n';

////    t.OnTxReady();
    OnTxReady_in_OutstationTestObject(&t);

////    t.SendToOutstation("C3 00");
    std::string n4("C3 00");       
    SendToOutstation_in_OutstationTestObject(&t, n4);  

//----------------------------------------------------
////    t.SendToOutstation("C4 01");                        // empty READ
    std::string n5("C4 01");       
    SendToOutstation_in_OutstationTestObject(&t, n5);  

////    REQUIRE(t.lower->PopWriteAsHex() == "C4 81 80 00"); // restart only
    std::string temp4 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));

    std::cout << "n5= " << n5<<'\n';
qDebug()<<"REQUIRE('C4 81 80 00' == t.lower->PopWriteAsHex())";
std::cout << "temp4= " << temp4<<'\n';

/*
TEST_CASE(SUITE("6MultipleClasses"))
{
    OutstationConfig config;
    config.eventBufferConfig = EventBufferConfig::AllTypes(10);

    auto database = configure::by_count_of::all_types(100);
    database.binary_input[0].clazz = PointClass::Class1;
    database.analog_input[0].clazz = PointClass::Class2;
    database.counter[0].clazz = PointClass::Class3;

    OutstationTestObject t(config, std::move(database));
    t.LowerLayerUp();

    t.Transaction([](IUpdateHandler& db) {
        db.Update(Binary(true), 0);
        db.Update(Analog(3), 0);
        db.Update(Counter(7), 0);
    });

    t.SendToOutstation("C0 01");                        // empty READ
    REQUIRE(t.lower->PopWriteAsHex() == "C0 81 8E 00"); // all event bits set + restart
    t.OnTxReady();

    // ------ read 1 event at a time by class, until all events are gone ----

    t.SendToOutstation(hex::ClassPoll(1, PointClass::Class2));                              // Class 2
    REQUIRE(t.lower->PopWriteAsHex() == "E1 81 8A 00 20 01 28 01 00 00 00 01 03 00 00 00"); // restart + Class 1/3
    t.OnTxReady();
    t.SendToOutstation("C1 00");

    t.SendToOutstation("C2 01 3C 04 06");                                                   // Class 3
    REQUIRE(t.lower->PopWriteAsHex() == "E2 81 82 00 16 01 28 01 00 00 00 01 07 00 00 00"); // restart + Class 1/3
    t.OnTxReady();
    t.SendToOutstation("C2 00");

    t.SendToOutstation("C3 01 3C 02 06");                                       // Class 1
    REQUIRE(t.lower->PopWriteAsHex() == "E3 81 80 00 02 01 28 01 00 00 00 81"); // restart only
    t.OnTxReady();
    t.SendToOutstation("C3 00");

    t.SendToOutstation("C4 01");                        // empty READ
    REQUIRE(t.lower->PopWriteAsHex() == "C4 81 80 00"); // restart only
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

