
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

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);


qDebug()<<"********SUITE('19UnsolEnableDisableFailure')********";
////    OutstationConfig cfg;
////    cfg.eventBufferConfig = EventBufferConfig(5);
////    OutstationTestObject t(cfg, configure::by_count_of::binary_input(5));
////    t.LowerLayerUp();
////    t.SendToOutstation("C0 14 3C 02 06");
////    REQUIRE(t.lower->PopWriteAsHex() == "C0 81 80 01"); // FUNC_NOT_SUPPORTED

    OutstationConfig cfg;
    OutstationConfig_in_OutstationConfig(&cfg);

////    cfg.eventBufferConfig = EventBufferConfig(5);
    EventBufferConfig eEventBufferConfig;
    EventBufferConfig_in_EventBufferConfigOver2(&eEventBufferConfig, 5, 0, 0, 0, 0, 0, 0, 0);
    cfg.eventBufferConfig = eEventBufferConfig;

    DatabaseConfig database = binary_input_in_DatabaseHelpers(5);

    OutstationTestObject t;
    OutstationTestObject_in_OutstationTestObject(&t, &cfg, &database);

////    t.LowerLayerUp();
    LowerLayerUp_in_OutstationTestObject(&t);

////    t.SendToOutstation("C0 14 3C 02 06");
    std::string request = "C0 14 3C 02 06";
    SendToOutstation_in_OutstationTestObject(&t, request);  

////    REQUIRE(t.lower->PopWriteAsHex() == "C0 81 80 01"); // FUNC_NOT_SUPPORTED
    std::string temp1 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));

qDebug()<<"REQUIRE(t.lower->PopWriteAsHex() == 'C0 81 80 01')";
std::cout << "temp1= " << temp1<<'\n';

/*
////    OutstationConfig config;
////    config.eventBufferConfig = EventBufferConfig::AllTypes(10);

   EventBufferConfig etemp = AllTypes_in_EventBufferConfig_static(MAX_EventRecord);
   config.eventBufferConfig = etemp;

////    config.params.solConfirmTimeout = TimeDuration::Seconds(5);
    config.params.solConfirmTimeout = Seconds_in_TimeDuration_static(5);

////    config.params.unsolConfirmTimeout = TimeDuration::Seconds(10);
    config.params.unsolConfirmTimeout = Seconds_in_TimeDuration_static(10);

////    OutstationTestObject t(config, configure::by_count_of::all_types(100));
//    DatabaseConfig tmp = binary_input_in_DatabaseHelpers(1);
  DatabaseConfig database = all_types_in_DatabaseHelpers(100);

    OutstationTestObject t;
    OutstationTestObject_in_OutstationTestObject(&t, &config, &database);

////    t.LowerLayerUp();
    LowerLayerUp_in_OutstationTestObject(&t);

    // Generate event
////    t.Transaction([](IUpdateHandler& db) { db.Update(Binary(true), 0); });
    Transaction_in_OutstationTestObject(&t, apply_in_4ReadClass1WithSOEWithTimeoutInBetween);//void (*apply)(IUpdateHandler*));

    // Read and expect the event
////    t.SendToOutstation(hex::ClassPoll(0, PointClass::Class1));
 std::string request = ClassPoll_in_APDUHexBuilders(0, PointClass_Class1);
 std::cout << "request= " << request<<'\n';
    SendToOutstation_in_OutstationTestObject(&t, request);  
////    REQUIRE(t.lower->PopWriteAsHex() == "E0 81 80 00 02 01 28 01 00 00 00 81");
    std::string temp1 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));

qDebug()<<"REQUIRE('E0 81 80 00 02 01 28 01 00 00 00 81' == t.lower->PopWriteAsHex())";
std::cout << "temp1= " << temp1<<'\n';

////    t.OnTxReady();
    OnTxReady_in_OutstationTestObject(&t);

    // Wait for timeout
////    t.AdvanceTime(TimeDuration::Seconds(5));
    TimeDuration ttmp = Seconds_in_TimeDuration_static(5);
    AdvanceTime_in_OutstationTestObject(&t, &ttmp);

    // Send confirmation too late
// ���������� ������������� ������� ������
////    t.SendToOutstation(hex::SolicitedConfirm(0));
std::string name1 = SolicitedConfirm_in_APDUHexBuilders(0);
 std::cout << "name1= " << name1<<'\n';
    SendToOutstation_in_OutstationTestObject(&t, name1);  

    // Generate another event
////    t.Transaction([](IUpdateHandler& db) { db.Update(Binary(false), 0); });
    Transaction_in_OutstationTestObject(&t, apply_in_4ReadClass1WithSOEWithTimeoutInBetween2);//void (*apply)(IUpdateHandler*));

    // Read again and expect two events
////    t.SendToOutstation(hex::ClassPoll(1, PointClass::Class1));
////    REQUIRE(t.lower->PopWriteAsHex() == "E1 81 80 00 02 01 28 02 00 00 00 81 00 00 01");

 std::string request2 = ClassPoll_in_APDUHexBuilders(1, PointClass_Class1);
 std::cout << "request2= " << request2<<'\n';
    SendToOutstation_in_OutstationTestObject(&t, request2);  
////    REQUIRE(t.lower->PopWriteAsHex() == "E1 81 80 00 02 01 28 02 00 00 00 81 00 00 01");
    std::string temp2 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));

qDebug()<<"REQUIRE('E1 81 80 00 02 01 28 02 00 00 00 81 00 00 01' == t.lower->PopWriteAsHex())";
std::cout << "temp2= " << temp2<<'\n';
*/
/*
TEST_CASE(SUITE("19UnsolEnableDisableFailure"))
{
    OutstationConfig cfg;
    cfg.eventBufferConfig = EventBufferConfig(5);
    OutstationTestObject t(cfg, configure::by_count_of::binary_input(5));

    t.LowerLayerUp();
    t.SendToOutstation("C0 14 3C 02 06");
    REQUIRE(t.lower->PopWriteAsHex() == "C0 81 80 01"); // FUNC_NOT_SUPPORTED
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

