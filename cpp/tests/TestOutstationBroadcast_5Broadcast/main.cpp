
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


qDebug()<<"********SUITE('5Broadcast with malformed request should still set the BROADCAST IIN')********";
    OutstationConfig config;
    OutstationConfig_in_OutstationConfig(&config);

////    OutstationConfig config;
////    OutstationTestObject t(config, DatabaseConfig());
  DatabaseConfig database;
  DatabaseConfig_in_DatabaseConfig_default(&database);

    OutstationTestObject t;
    OutstationTestObject_in_OutstationTestObject(&t, &config, &database);

////    t.LowerLayerUp();
    LowerLayerUp_in_OutstationTestObject(&t);

//std::string ClearRestartIIN_in_APDUHexBuilders(uint8_t seq);
//uint16_t BroadcastToOutstation_in_OutstationTestObject(OutstationTestObject *pOutstationTestObject, LinkBroadcastAddress_uint16_t broadcast_address, const std::string& hex);
////    t.BroadcastToOutstation(LinkBroadcastAddress::DontConfirm, "FF FF FF");
std::string clrStr = "FF FF FF";
     BroadcastToOutstation_in_OutstationTestObject(&t, LinkBroadcastAddress_DontConfirm, clrStr);

//boolean HasNoData_in_MockLowerLayer(MockLowerLayer *pMockLowerLayer)
    // Outstation should not respond to broadcast request
///    REQUIRE(t.lower->HasNoData());
boolean btemp = HasNoData_in_MockLowerLayer(&(t.lower));

qDebug()<<"REQUIRE(t.lower->HasNoData())";
std::cout << "clrStr= " << clrStr<<'\n';
std::cout << "btemp= " << btemp<<'\n';

    // The next response should have BROADCAST IIN
////    t.SendToOutstation(hex::ClassPoll(2, PointClass::Class0));
    std::string name1 = ClassPoll_in_APDUHexBuilders(2, PointClass_Class0);
    std::cout << "name1= " << name1<<'\n';
    SendToOutstation_in_OutstationTestObject(&t, name1);  

////    REQUIRE(t.lower->PopWriteAsHex() == "C2 81 81 00");
    std::string temp1 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));

qDebug()<<"REQUIRE(t.lower->PopWriteAsHex() == 'C2 81 81 00')";
std::cout << "temp1= " << temp1<<'\n';

////    t.OnTxReady();
    OnTxReady_in_OutstationTestObject(&t);

/*
    // The next response should have BROADCAST IIN set and restart IIN reset.
////    t.SendToOutstation(hex::ClassPoll(2, PointClass::Class0));
    std::string name1 = ClassPoll_in_APDUHexBuilders(2, PointClass_Class0);
    std::cout << "name1= " << name1<<'\n';
    SendToOutstation_in_OutstationTestObject(&t, name1);  

////    REQUIRE(t.lower->PopWriteAsHex() == "C2 81 01 00");
    std::string temp1 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));

qDebug()<<"REQUIRE(t.lower->PopWriteAsHex() == 'C2 81 01 00')";
std::cout << "temp1= " << temp1<<'\n';

///    t.OnTxReady();
    OnTxReady_in_OutstationTestObject(&t);

    // The next response should have BROADCAST IIN reset
////    t.SendToOutstation(hex::ClassPoll(3, PointClass::Class0));
    std::string name2 = ClassPoll_in_APDUHexBuilders(3, PointClass_Class0);
    std::cout << "name2= " << name2<<'\n';
    SendToOutstation_in_OutstationTestObject(&t, name2);  

///    REQUIRE(t.lower->PopWriteAsHex() == "C3 81 00 00");
    std::string temp2 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));

qDebug()<<"REQUIRE(t.lower->PopWriteAsHex() == 'C3 81 00 00')";
std::cout << "temp2= " << temp2<<'\n';
*/
/*
TEST_CASE(SUITE("5Broadcast with malformed request should still set the BROADCAST IIN"))
Трансляция с неверным запросом по-прежнему должна устанавливать BROADCAST IIN.
{
    OutstationConfig config;
    OutstationTestObject t(config, DatabaseConfig());
    t.LowerLayerUp();

    t.BroadcastToOutstation(LinkBroadcastAddress::DontConfirm, "FF FF FF");

    // Outstation should not respond to broadcast request
    REQUIRE(t.lower->HasNoData());

    // The next response should have BROADCAST IIN
    t.SendToOutstation(hex::ClassPoll(2, PointClass::Class0));
    REQUIRE(t.lower->PopWriteAsHex() == "C2 81 81 00");
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

