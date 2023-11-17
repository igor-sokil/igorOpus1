
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

void apply_in_3ReadClass1WithSOE(IUpdateHandler*);
void apply_in_3ReadClass1WithSOE(IUpdateHandler* db)
{
    std::cout << "3ReadClass1WithSOE" <<'\n';
////    t.Transaction([](IUpdateHandler& db) {
////        db.Update(Analog(0x1234, Flags(0x01)), 0x17); // 0x 12 34 00 00 in little endian
////        db.Update(Binary(true, Flags(0x01)), 0x10);
////        db.Update(Analog(0x2222, Flags(0x01)), 0x17); // 0x 22 22 00 00 in little endian
////    });

 Flags fFlags;
 Flags_In_FlagsOver2(&fFlags, 1);

//void Binary_in_BinaryOver5(Binary *pBinary, boolean value, Flags flags);
 Binary bBinary;
 Binary_in_BinaryOver5(&bBinary, true, fFlags);

 Analog aAnalog1;
 Analog_in_AnalogOver3(&aAnalog1, 0x1234, fFlags);

 Analog aAnalog2;
 Analog_in_AnalogOver3(&aAnalog2, 0x2222, fFlags);

//boolean Update_Binary_in_IUpdateHandler(IUpdateHandler*, Binary* meas, uint16_t index, EventMode_uint8_t mode);// = EventMode::Detect) = 0;
////            db.Update(Binary(true, Flags(0x01)), 0); 
 Update_Analog_in_IUpdateHandler(db, &aAnalog1, 0x17, EventMode_Detect);// = EventMode::Detect) = 0;
 Update_Binary_in_IUpdateHandler(db, &bBinary, 0x10, EventMode_Detect);// = EventMode::Detect) = 0;
 Update_Analog_in_IUpdateHandler(db, &aAnalog2, 0x17, EventMode_Detect);// = EventMode::Detect) = 0;
}

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);


qDebug()<<"********SUITE('3ReadClass1WithSOE')********";
    OutstationConfig config;
    OutstationConfig_in_OutstationConfig(&config);

////    OutstationConfig config;
////    config.eventBufferConfig = EventBufferConfig::AllTypes(10);
////    OutstationTestObject t(config, configure::by_count_of::all_types(100));

   EventBufferConfig etemp = AllTypes_in_EventBufferConfig_static(MAX_EventRecord);
   config.eventBufferConfig = etemp;


////    OutstationTestObject t(config, configure::by_count_of::all_types(100));
//    DatabaseConfig tmp = binary_input_in_DatabaseHelpers(1);
  DatabaseConfig database = all_types_in_DatabaseHelpers(100);

    OutstationTestObject t;
    OutstationTestObject_in_OutstationTestObject(&t, &config, &database);

////    t.LowerLayerUp();
    LowerLayerUp_in_OutstationTestObject(&t);

////    t.Transaction([](IUpdateHandler& db) {
////        db.Update(Analog(0x1234, Flags(0x01)), 0x17); // 0x 12 34 00 00 in little endian
////        db.Update(Binary(true, Flags(0x01)), 0x10);
////        db.Update(Analog(0x2222, Flags(0x01)), 0x17); // 0x 22 22 00 00 in little endian
////    });

    Transaction_in_OutstationTestObject(&t, apply_in_3ReadClass1WithSOE);//void (*apply)(IUpdateHandler*));

////    t.SendToOutstation(hex::ClassPoll(0, PointClass::Class1));
 std::string request = ClassPoll_in_APDUHexBuilders(0, PointClass_Class1);
 std::cout << "request= " << request<<'\n';
    SendToOutstation_in_OutstationTestObject(&t, request);  


////    REQUIRE(t.lower->PopWriteAsHex()
////            == "E0 81 80 00 20 01 28 01 00 17 00 01 34 12 00 00 02 01 28 01 00 10 00 81 20 01 28 01 00 17 00 01 22 22 "
////               "00 00");
    std::string temp1 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));

qDebug()<<"REQUIRE('E0 81 80 00 20 01 28 01 00 17 00 01 34 12 00 00 02 01 28 01 00 10 00 81 20 01 28 01 00 17 00 01 22 22 00 00' == t.lower->PopWriteAsHex())";
std::cout << "temp1= " << temp1<<'\n';

////    t.OnTxReady();
    OnTxReady_in_OutstationTestObject(&t);

//std::string SolicitedConfirm_in_APDUHexBuilders(uint8_t seq);
////    t.SendToOutstation(hex::SolicitedConfirm(0));
std::string name1 = SolicitedConfirm_in_APDUHexBuilders(0);
 std::cout << "name1= " << name1<<'\n';
    SendToOutstation_in_OutstationTestObject(&t, name1);  

////    t.SendToOutstation(hex::ClassPoll(1, PointClass::Class1)); // Repeat read class 1
 std::string request2 = ClassPoll_in_APDUHexBuilders(1, PointClass_Class1);
 std::cout << "request2= " << request2<<'\n';
    SendToOutstation_in_OutstationTestObject(&t, request2);  

////    REQUIRE(t.lower->PopWriteAsHex() == "C1 81 80 00");        // Buffer should have been cleared
    std::string temp2 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));
qDebug()<<"REQUIRE(t.lower->PopWriteAsHex() == 'C1 81 80 00')";
std::cout << "temp2= " << temp2<<'\n';

/*
////    t.OnTxReady();
////    t.SendToOutstation(hex::SolicitedConfirm(0));

////    t.SendToOutstation(hex::ClassPoll(1, PointClass::Class1)); // Repeat read class 1
////    REQUIRE(t.lower->PopWriteAsHex() == "C1 81 80 00");        // Buffer should have been cleared

//    std::string n1("C0 01");       

    SendToOutstation_in_OutstationTestObject(&t, n1);  

    std::string temp = PopWriteAsHex_in_MockLowerLayer(&(t.lower));

    std::cout << "n1= " << n1<<'\n';
qDebug()<<"REQUIRE('C0 81 8E 00' == t.lower->PopWriteAsHex())";
std::cout << "temp= " << temp<<'\n';
*/
/*
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
*/
/*
TEST_CASE(SUITE("3ReadClass1WithSOE"))
{
    OutstationConfig config;
    config.eventBufferConfig = EventBufferConfig::AllTypes(10);
    OutstationTestObject t(config, configure::by_count_of::all_types(100));

    t.LowerLayerUp();

    t.Transaction([](IUpdateHandler& db) {
        db.Update(Analog(0x1234, Flags(0x01)), 0x17); // 0x 12 34 00 00 in little endian
        db.Update(Binary(true, Flags(0x01)), 0x10);
        db.Update(Analog(0x2222, Flags(0x01)), 0x17); // 0x 22 22 00 00 in little endian
    });

    t.SendToOutstation(hex::ClassPoll(0, PointClass::Class1));
    REQUIRE(t.lower->PopWriteAsHex()
            == "E0 81 80 00 20 01 28 01 00 17 00 01 34 12 00 00 02 01 28 01 00 10 00 81 20 01 28 01 00 17 00 01 22 22 "
               "00 00");
    t.OnTxReady();
    t.SendToOutstation(hex::SolicitedConfirm(0));

    t.SendToOutstation(hex::ClassPoll(1, PointClass::Class1)); // Repeat read class 1
    REQUIRE(t.lower->PopWriteAsHex() == "C1 81 80 00");        // Buffer should have been cleared
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

