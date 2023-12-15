
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
//#include "TestOutstationEventResponses.h"
#include "TestOutstationFrozenCounters.h"

#define UNUSED(x) (void)(x)


key_filter *pkf;

MainWindow *mainWindow;

////    const uint16_t num_counters = 10;
    uint16_t num_counters = 10;

void loadFun_in_6Range1(IUpdateHandler*);
void loadFun_in_6Range1(IUpdateHandler* db)
{
std::cout << "{loadFun_in_6Range1_1"<<'\n';
//boolean Modify_in_IUpdateHandler(IUpdateHandler*, FlagsType_uint8_t type, uint16_t start, uint16_t stop, uint8_t flags);// = 0;
////    t.Transaction([=](IUpdateHandler& db) {
////        db.Modify(FlagsType::Counter, 0, num_counters - 1, 0x01);
////        db.Modify(FlagsType::FrozenCounter, 0, num_counters - 1, 0x01);
////    });
 Modify_in_IUpdateHandler(db, FlagsType_Counter, 0, num_counters - 1, 0x01);
 Modify_in_IUpdateHandler(db, FlagsType_FrozenCounter, 0, num_counters - 1, 0x01);
std::cout << "}loadFun_in_6Range1__"<<'\n';
}

void loadFun_in_6Range2(IUpdateHandler*);
void loadFun_in_6Range2(IUpdateHandler* db)
{
std::cout << "{loadFun_in_6Range2_1"<<'\n';
//void Counter_in_CounterOver2(Counter *pCounter, uint32_t value);
//// int counterValue = 41;
////    t.Transaction([=](IUpdateHandler& db) {
////        for (uint16_t i = 0; i < num_counters; ++i)
////        {
////            db.Update(Counter(counterValue), i);
////        }
////    });
  Counter cCounter;
  Counter_in_CounterOver2(&cCounter, 41);
        for (uint16_t i = 0; i < num_counters; ++i)
        {
  Update_Counter_in_IUpdateHandler(db, &cCounter, i, EventMode_Detect);// = EventMode::Detect) = 0;
        }
std::cout << "}loadFun_in_6Range2__"<<'\n';
}


int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);


qDebug()<<"********SUITE('6Range freeze')********";
std::cout << "{---------1"<<'\n';
////    const uint16_t num_counters = 10;
////    OutstationConfig config;
////    auto database = configure::by_count_of::counter(num_counters, true);
////    OutstationTestObject t(config, database);
////    t.Transaction([=](IUpdateHandler& db) {
////        db.Modify(FlagsType::Counter, 0, num_counters - 1, 0x01);
////        db.Modify(FlagsType::FrozenCounter, 0, num_counters - 1, 0x01);
////    });
////    t.LowerLayerUp();
/////        // Read all frozen counters
////    t.SendToOutstation("C0 01 15 00 06");
////    REQUIRE(t.lower->PopWriteAsHex()
////            == "C0 81 80 00 15 01 00 00 09 "
////               "01 00 00 00 00 01 00 00 00 00 "
////               "01 00 00 00 00 01 00 00 00 00 01 00 00 00 00 01 00 00 00 00 01 00 00 00 00 "
////               "01 00 00 00 00 01 00 00 00 00 01 00 00 00 00"); // Frozen value at 0
////    t.OnTxReady();


////    OutstationConfig config;
    OutstationConfig config;
    OutstationConfig_in_OutstationConfig(&config);

//DatabaseConfig counter_in_DatabaseHelpers(uint16_t num, boolean with_frozen);// = false);
////    auto database = configure::by_count_of::counter(num_counters, true);
    DatabaseConfig database = counter_in_DatabaseHelpers(num_counters, true);

////    OutstationTestObject t(config, database);
    OutstationTestObject t;
    OutstationTestObject_in_OutstationTestObject(&t, &config, &database);

////    t.Transaction([=](IUpdateHandler& db) {
////        db.Modify(FlagsType::Counter, 0, num_counters - 1, 0x01);
////        db.Modify(FlagsType::FrozenCounter, 0, num_counters - 1, 0x01);
////    });

    Transaction_in_OutstationTestObject(&t, loadFun_in_6Range1);//void (*apply)(IUpdateHandler*));

////    t.LowerLayerUp();
    LowerLayerUp_in_OutstationTestObject(&t);

/////        // Read all frozen counters
////    t.SendToOutstation("C0 01 15 00 06");
     std::string freeze1 = "C0 01 15 00 06";
     SendToOutstation_in_OutstationTestObject(&t, freeze1);

////    REQUIRE(t.lower->PopWriteAsHex()
////            == "C0 81 80 00 15 01 00 00 09 "
////               "01 00 00 00 00 01 00 00 00 00 "
////               "01 00 00 00 00 01 00 00 00 00 01 00 00 00 00 01 00 00 00 00 01 00 00 00 00 "
////               "01 00 00 00 00 01 00 00 00 00 01 00 00 00 00"); // Frozen value at 0
    std::string temp1 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));
std::cout << "}---------1"<<'\n';

    std::cout << "freeze1= " << freeze1<<'\n';
    std::cout << "REQUIRE(t.lower->PopWriteAsHex() == 'C0 81 80 00 15 01 00 00 09 01 00 00 00 00 01 00 00 00 00 01 00 00 00 00 01 00 00 00 00 01 00 00 00 00 01 00 00 00 00 01 00 00 00 00 01 00 00 00 00 01 00 00 00 00 01 00 00 00 00'"<<'\n';
    std::cout << "temp1= " << temp1<<'\n';

////    t.OnTxReady();
    OnTxReady_in_OutstationTestObject(&t);

std::cout << "{---------2"<<'\n';
////    // Update the counters
////    t.Transaction([=](IUpdateHandler& db) {
////        for (uint16_t i = 0; i < num_counters; ++i)
////        {
////            db.Update(Counter(counterValue), i);
////        }
////    });
////    // Freeze subset of counters
////    t.SendToOutstation("C1 07 14 00 00 02 06");
////    REQUIRE(t.lower->PopWriteAsHex() == "C1 81 80 00");
////    t.OnTxReady();

    // Update the counters
////    t.Transaction([=](IUpdateHandler& db) {
////        for (uint16_t i = 0; i < num_counters; ++i)
////        {
////            db.Update(Counter(counterValue), i);
////        }
////    });
    Transaction_in_OutstationTestObject(&t, loadFun_in_6Range2);//void (*apply)(IUpdateHandler*));

////    // Freeze subset of counters
////    t.SendToOutstation("C1 07 14 00 00 02 06");
    std::string request2 = "C1 07 14 00 00 02 06";
    SendToOutstation_in_OutstationTestObject(&t, request2);  

////    REQUIRE(t.lower->PopWriteAsHex() == "C1 81 80 00");
    std::string temp2 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));
std::cout << "}---------2"<<'\n';

    std::cout << "request2= " << request2<<'\n';
    std::cout << "REQUIRE(t.lower->PopWriteAsHex() == 'C1 81 80 00')"<<'\n';
    std::cout << "temp2= " << temp2<<'\n';

////    t.OnTxReady();
    OnTxReady_in_OutstationTestObject(&t);

std::cout << "{---------3"<<'\n';
////    // Read all frozen counters
////    t.SendToOutstation("C2 01 15 00 06");
////    REQUIRE(t.lower->PopWriteAsHex()
////            == "C2 81 80 00 15 01 00 00 09 "
////               "01 00 00 00 00 01 00 00 00 00 "
////               "01 29 00 00 00 01 29 00 00 00 01 29 00 00 00 01 29 00 00 00 01 29 00 00 00 "
////               "01 00 00 00 00 01 00 00 00 00 01 00 00 00 00"); // Frozen values are updated
////    t.OnTxReady();

////    // Read all frozen counters
////    t.SendToOutstation("C2 01 15 00 06");
    std::string request3 = "C2 01 15 00 06";
    SendToOutstation_in_OutstationTestObject(&t, request3);  

////    REQUIRE(t.lower->PopWriteAsHex()
////            == "C2 81 80 00 15 01 00 00 09 "
////               "01 00 00 00 00 01 00 00 00 00 "
////               "01 29 00 00 00 01 29 00 00 00 01 29 00 00 00 01 29 00 00 00 01 29 00 00 00 "
////               "01 00 00 00 00 01 00 00 00 00 01 00 00 00 00"); // Frozen values are updated
    std::string temp3 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));
std::cout << "}---------3"<<'\n';
    std::cout << "request3= " << request2<<'\n';
    std::cout << "REQUIRE(t.lower->PopWriteAsHex() == 'C2 81 80 00 15 01 00 00 09 01 00 00 00 00 01 00 00 00 00 01 29 00 00 00 01 29 00 00 00 01 29 00 00 00 01 29 00 00 00 01 29 00 00 00 01 00 00 00 00 01 00 00 00 00 01 00 00 00 00')"<<'\n';
    std::cout << "temp3= " << temp3<<'\n';

/*
    // Update the counters
////    t.Transaction([=](IUpdateHandler& db) { db.Update(Counter(counterValue), 0); });
    Transaction_in_OutstationTestObject(&t, loadFun_in_5Broadcast2);//void (*apply)(IUpdateHandler*));

    // Read all frozen counters
////    t.SendToOutstation("C2 01 15 00 06");
    std::string request3 = "C2 01 15 00 06";
    SendToOutstation_in_OutstationTestObject(&t, request3);  

////    REQUIRE(t.lower->PopWriteAsHex()
////            == "C2 81 80 00 15 05 00 00 00 01 00 00 00 00 00 00 00 00 00 00"); // Frozen value still at 0
    std::string temp3 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));
std::cout << "}---------3"<<'\n';

    std::cout << "request3= " << request3<<'\n';
    std::cout << "REQUIRE(t.lower->PopWriteAsHex()== 'C2 81 80 00 15 05 00 00 00 01 00 00 00 00 00 00 00 00 00 00'"<<'\n';
    std::cout << "temp3= " << temp3<<'\n';

////    t.OnTxReady();
    OnTxReady_in_OutstationTestObject(&t);

std::cout << "{---------4"<<'\n';
////    // Change time of application
////    t.application->SetTime(freezeTimestamp);
////    // Freeze all counters
////    t.BroadcastToOutstation(LinkBroadcastAddress::DontConfirm, "C3 0A 14 00 06");
////    REQUIRE(t.lower->PopWriteAsHex() == ""); // No response
////    t.OnTxReady();

    // Change time of application
////const DNPTime freezeTimestamp(240607800000, TimestampQuality::SYNCHRONIZED);
        DNPTime freezeTimestamp;
        DNPTime_in_DNPTimeOver3(&freezeTimestamp, 240607800000, TimestampQuality_SYNCHRONIZED);
//void SetTime_in_MockOutstationApplication(MockOutstationApplication *pMockOutstationApplication, DNPTime timeDNPTime);
////    t.application->SetTime(freezeTimestamp);
        SetTime_in_MockOutstationApplication(&(t.application), freezeTimestamp);
////    // Freeze all counters
////    t.BroadcastToOutstation(LinkBroadcastAddress::DontConfirm, "C3 0A 14 00 06");
     std::string freeze4 = "C3 0A 14 00 06";
     BroadcastToOutstation_in_OutstationTestObject(&t, LinkBroadcastAddress_DontConfirm, freeze4);

////    REQUIRE(t.lower->PopWriteAsHex() == ""); // No response
    std::string temp4 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));
std::cout << "}---------4"<<'\n';

    std::cout << "freeze4= " << freeze4<<'\n';
    std::cout << "REQUIRE(t.lower->PopWriteAsHex() == '')"<<'\n';
    std::cout << "temp4= " << temp4<<'\n';

////    t.OnTxReady();
    OnTxReady_in_OutstationTestObject(&t);
std::cout << "{---------5"<<'\n';
////    // Read all frozen counters
////    t.SendToOutstation("C4 01 15 00 06");
////    REQUIRE(t.lower->PopWriteAsHex()
////            == "C4 81 81 00 15 05 00 00 00 01 29 00 00 00 " + freezeTimestampHex); // Frozen value now at 41
////    t.OnTxReady();

    // Read all frozen counters
////    t.SendToOutstation("C4 01 15 00 06");
    std::string request5 = "C4 01 15 00 06";
    SendToOutstation_in_OutstationTestObject(&t, request5);  

////    REQUIRE(t.lower->PopWriteAsHex()
////            == "C4 81 80 00 15 05 00 00 00 01 29 00 00 00 " + freezeTimestampHex); // Frozen value now at 41
    std::string temp5 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));
std::cout << "}---------5"<<'\n';

    std::cout << "request5= " << request5<<'\n';
    std::cout << "REQUIRE(t.lower->PopWriteAsHex()== 'C4 81 80 00 15 05 00 00 00 01 29 00 00 00 C0 AA 57 05 38 00'"<<'\n';
    std::cout << "temp5= " << temp5<<'\n';

////    t.OnTxReady();
    OnTxReady_in_OutstationTestObject(&t);
std::cout << "{---------6"<<'\n';
////    // Read all counters
////    t.SendToOutstation("C5 01 14 00 06");
////    REQUIRE(t.lower->PopWriteAsHex() == "C5 81 80 00 14 01 00 00 00 01 00 00 00 00"); // Counter is now reset
////    t.OnTxReady();

    // Read all counters
////    t.SendToOutstation("C5 01 14 00 06");
    std::string request6 = "C5 01 14 00 06";
    SendToOutstation_in_OutstationTestObject(&t, request6);  

////    REQUIRE(t.lower->PopWriteAsHex() == "C5 81 80 00 14 01 00 00 00 01 00 00 00 00"); // Counter is now reset
    std::string temp6 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));
std::cout << "}---------6"<<'\n';

    std::cout << "request6= " << request6<<'\n';
    std::cout << "REQUIRE(t.lower->PopWriteAsHex() == 'C5 81 80 00 14 01 00 00 00 01 00 00 00 00')"<<'\n';
    std::cout << "temp6= " << temp6<<'\n';
*/
/*
TEST_CASE(SUITE("6Range freeze"))
{
    const uint16_t num_counters = 10;

    OutstationConfig config;
    auto database = configure::by_count_of::counter(num_counters, true);
    OutstationTestObject t(config, database);
    t.Transaction([=](IUpdateHandler& db) {
        db.Modify(FlagsType::Counter, 0, num_counters - 1, 0x01);
        db.Modify(FlagsType::FrozenCounter, 0, num_counters - 1, 0x01);
    });
    t.LowerLayerUp();

    // Read all frozen counters
    t.SendToOutstation("C0 01 15 00 06");
    REQUIRE(t.lower->PopWriteAsHex()
            == "C0 81 80 00 15 01 00 00 09 "
               "01 00 00 00 00 01 00 00 00 00 "
               "01 00 00 00 00 01 00 00 00 00 01 00 00 00 00 01 00 00 00 00 01 00 00 00 00 "
               "01 00 00 00 00 01 00 00 00 00 01 00 00 00 00"); // Frozen value at 0
    t.OnTxReady();

    // Update the counters
    t.Transaction([=](IUpdateHandler& db) {
        for (uint16_t i = 0; i < num_counters; ++i)
        {
            db.Update(Counter(counterValue), i);
        }
    });

    // Freeze subset of counters
    t.SendToOutstation("C1 07 14 00 00 02 06");
    REQUIRE(t.lower->PopWriteAsHex() == "C1 81 80 00");
    t.OnTxReady();

    // Read all frozen counters
    t.SendToOutstation("C2 01 15 00 06");
    REQUIRE(t.lower->PopWriteAsHex()
            == "C2 81 80 00 15 01 00 00 09 "
               "01 00 00 00 00 01 00 00 00 00 "
               "01 29 00 00 00 01 29 00 00 00 01 29 00 00 00 01 29 00 00 00 01 29 00 00 00 "
               "01 00 00 00 00 01 00 00 00 00 01 00 00 00 00"); // Frozen values are updated
    t.OnTxReady();
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

