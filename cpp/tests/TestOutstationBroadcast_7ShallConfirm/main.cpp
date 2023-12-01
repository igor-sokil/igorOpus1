
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

void apply_in_7ShallConfirm(IUpdateHandler*);
void apply_in_7ShallConfirm(IUpdateHandler* db)
{
    std::cout << "apply_in_7ShallConfirm" <<'\n';
////    t.Transaction([](IUpdateHandler& handler) { handler.Update(Binary(true), 0); });
//void Binary_in_BinaryOver2(Binary *pBinary, boolean value);
 Binary bBinary;
 Binary_in_BinaryOver2(&bBinary, true);

//boolean Update_Binary_in_IUpdateHandler(IUpdateHandler*, Binary* meas, uint16_t index, EventMode_uint8_t mode);// = EventMode::Detect) = 0;
 Update_Binary_in_IUpdateHandler(db, &bBinary, 0, EventMode_Detect);// = EventMode::Detect) = 0;
}
void apply_in_7ShallConfirm2(IUpdateHandler*);
void apply_in_7ShallConfirm2(IUpdateHandler* db)
{
    std::cout << "apply_in_7ShallConfirm2" <<'\n';
////    t.Transaction([](IUpdateHandler& handler) { handler.Update(Binary(false), 0); });
//void Binary_in_BinaryOver2(Binary *pBinary, boolean value);
 Binary bBinary;
 Binary_in_BinaryOver2(&bBinary, false);

//boolean Update_Binary_in_IUpdateHandler(IUpdateHandler*, Binary* meas, uint16_t index, EventMode_uint8_t mode);// = EventMode::Detect) = 0;
 Update_Binary_in_IUpdateHandler(db, &bBinary, 0, EventMode_Detect);// = EventMode::Detect) = 0;
}

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);


qDebug()<<"********SUITE('7ShallConfirm: Unsolicited responses should clear BROADCAST when confirm is received')********";
////    OutstationConfig config;
////    config.params.unsolClassMask = ClassField::AllClasses();
////    config.eventBufferConfig = EventBufferConfig::AllTypes(10);
////    config.params.allowUnsolicited = true;
////    config.params.numUnsolRetries = NumRetries::Fixed(0);
////    OutstationTestObject t(config, configure::by_count_of::binary_input(1));
////    t.LowerLayerUp();
////    t.context.OnTxReady();
////    REQUIRE(t.lower->PopWriteAsHex() == hex::NullUnsolicited(0));

qDebug()<<"{+++++++++++7ShallConfirm1";
////    OutstationConfig config;
    OutstationConfig config;
    OutstationConfig_in_OutstationConfig(&config);

////    config.params.unsolClassMask = ClassField::AllClasses();
    config.params.unsolClassMask = AllClasses_in_ClassField_static();

////    config.eventBufferConfig = EventBufferConfig::AllTypes(10);
   EventBufferConfig etemp = AllTypes_in_EventBufferConfig_static(MAX_EventRecord);
   config.eventBufferConfig = etemp;

////    config.params.allowUnsolicited = true;
   config.params.allowUnsolicited = true;

//NumRetries Fixed_in_NumRetries_static(uint16_t maxNumRetries);
////    config.params.numUnsolRetries = NumRetries::Fixed(0);
    config.params.numUnsolRetries = Fixed_in_NumRetries_static(0);

////    OutstationTestObject t(config, configure::by_count_of::binary_input(1));
    DatabaseConfig tmp = binary_input_in_DatabaseHelpers(1);

    OutstationTestObject t;
    OutstationTestObject_in_OutstationTestObject(&t, &config, &tmp);

////    t.LowerLayerUp();
    LowerLayerUp_in_OutstationTestObject(&t);

//boolean OnTxReady_in_OContext(OContext*);
////    t.context.OnTxReady();
//   OnTxReady_in_OContext(&(t));//.context));
    OnTxReady_in_OutstationTestObject(&t);

//std::string NullUnsolicited_in_APDUHexBuilders(uint8_t seq,
//    IINField* iin);// = opendnp3::IINField(opendnp3::IINBit::DEVICE_RESTART));
////    REQUIRE(t.lower->PopWriteAsHex() == hex::NullUnsolicited(0));
 IINField iIINField;
 IINField_in_IINFieldOver2(&iIINField, IINBit_DEVICE_RESTART);
 std::string response = NullUnsolicited_in_APDUHexBuilders(0, &iIINField);// = opendnp3::IINField(opendnp3::IINBit::DEVICE_RESTART));
qDebug()<<"}----------7ShallConfirm1";

std::string temp1 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));

qDebug()<<" REQUIRE(t.lower->PopWriteAsHex() == hex::NullUnsolicited(0))";
std::cout << "response= " << response<<'\n';
std::cout << "temp1= " << temp1<<'\n';

    // Confirm unsolicited NULL response
////    t.SendToOutstation(hex::UnsolConfirm(0));
    // Send a broadcast message
////    t.BroadcastToOutstation(LinkBroadcastAddress::ShallConfirm, hex::ClearRestartIIN(1));
    // Outstation should not respond to broadcast request
////    REQUIRE(t.lower->HasNoData());

qDebug()<<"{+++++++++++7ShallConfirm2";
qDebug()<<"{+++++++++++t.SendToOutstation(hex::UnsolConfirm(0))";
    // Confirm unsolicited NULL response
////    t.SendToOutstation(hex::UnsolConfirm(0));
std::string unconstr = UnsolConfirm_in_APDUHexBuilders(0);
std::cout << "unconstr= " << unconstr<<'\n';
        SendToOutstation_in_OutstationTestObject(&t, unconstr);  
qDebug()<<"}----------t.SendToOutstation(hex::UnsolConfirm(0))";

qDebug()<<"{+++++++++++t.BroadcastToOutstation(LinkBroadcastAddress::ShallConfirm, hex::ClearRestartIIN(1))";
    // Send a broadcast message
////    t.BroadcastToOutstation(LinkBroadcastAddress::ShallConfirm, hex::ClearRestartIIN(1));
std::string clrStr = ClearRestartIIN_in_APDUHexBuilders(1);
std::cout << "clrStr= " << clrStr<<'\n';
          BroadcastToOutstation_in_OutstationTestObject(&t, LinkBroadcastAddress_ShallConfirm, clrStr);
qDebug()<<"}----------t.BroadcastToOutstation(LinkBroadcastAddress::ShallConfirm, hex::ClearRestartIIN(1))";

    // Outstation should not respond to broadcast request
////    REQUIRE(t.lower->HasNoData());
boolean btemp = HasNoData_in_MockLowerLayer(&(t.lower));

qDebug()<<"}----------7ShallConfirm2";
qDebug()<<"REQUIRE(t.lower->HasNoData())";
std::cout << "btemp= " << btemp<<'\n';

qDebug()<<"{+++++++++++7ShallConfirm3";
    // Generate an event
////    t.Transaction([](IUpdateHandler& handler) { handler.Update(Binary(true), 0); });
    Transaction_in_OutstationTestObject(&t, apply_in_7ShallConfirm);//void (*apply)(IUpdateHandler*));

    // Should send unsolicited with BROADCAST IIN set
////    REQUIRE(t.lower->PopWriteAsHex().substr(0, 11) == "F1 82 01 00");
    std::string temp2 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));

////    t.context.OnTxReady();
    OnTxReady_in_OutstationTestObject(&t);
qDebug()<<"}----------7ShallConfirm3";
qDebug()<<" REQUIRE(t.lower->PopWriteAsHex().substr(0, 11) == 'F1 82 01 00')";
std::cout << "temp2= " << temp2<<'\n';

    // Timeout and generate another unsolicited
////    t.AdvanceToNextTimer();
////    t.Transaction([](IUpdateHandler& handler) { handler.Update(Binary(false), 0); });
    // Next unsolicited should still have BROADCAST IIN set
////    REQUIRE(t.lower->PopWriteAsHex().substr(0, 11) == "F2 82 01 00");
////    t.context.OnTxReady();

qDebug()<<"{+++++++++++7ShallConfirm4";
    // Timeout and generate another unsolicited
////    t.AdvanceToNextTimer();
        AdvanceToNextTimer_in_OutstationTestObject(&t);

////    t.Transaction([](IUpdateHandler& handler) { handler.Update(Binary(false), 0); });
    Transaction_in_OutstationTestObject(&t, apply_in_7ShallConfirm2);//void (*apply)(IUpdateHandler*));

    // Next unsolicited should still have BROADCAST IIN set
////    REQUIRE(t.lower->PopWriteAsHex().substr(0, 11) == "F2 82 01 00");
    std::string temp3 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));

////    t.context.OnTxReady();
    OnTxReady_in_OutstationTestObject(&t);
qDebug()<<"}----------7ShallConfirm4";
qDebug()<<" REQUIRE(t.lower->PopWriteAsHex().substr(0, 11) == 'F2 82 01 00')";
std::cout << "temp3= " << temp3<<'\n';

    // Confirm the unsolicited response
////    t.SendToOutstation(hex::UnsolConfirm(2));
    // Generate an event
////    t.Transaction([](IUpdateHandler& handler) { handler.Update(Binary(true), 0); });
////    REQUIRE(t.lower->PopWriteAsHex().substr(0, 11) == "F3 82 00 00");

qDebug()<<"{+++++++++++7ShallConfirm5";
    // Confirm the unsolicited response
////    t.SendToOutstation(hex::UnsolConfirm(2));
std::string unconstr2 = UnsolConfirm_in_APDUHexBuilders(2);
std::cout << "unconstr2= " << unconstr2<<'\n';
    SendToOutstation_in_OutstationTestObject(&t, unconstr2);  

    // Generate an event
////    t.Transaction([](IUpdateHandler& handler) { handler.Update(Binary(true), 0); });
    Transaction_in_OutstationTestObject(&t, apply_in_7ShallConfirm);//void (*apply)(IUpdateHandler*));

////    REQUIRE(t.lower->PopWriteAsHex().substr(0, 11) == "F3 82 00 00");
    std::string temp4 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));
qDebug()<<"}----------7ShallConfirm5";
qDebug()<<" REQUIRE(t.lower->PopWriteAsHex().substr(0, 11) == 'F3 82 00 00')";
std::cout << "temp4= " << temp4<<'\n';

/*
TEST_CASE(SUITE("7ShallConfirm: Unsolicited responses should clear BROADCAST when confirm is received"))
7ShallConfirm: Незапрошенные ответы должны удаляться из BROADCAST при получении подтверждения.
{
    OutstationConfig config;
    config.params.unsolClassMask = ClassField::AllClasses();
    config.eventBufferConfig = EventBufferConfig::AllTypes(10);
    config.params.allowUnsolicited = true;
    config.params.numUnsolRetries = NumRetries::Fixed(0);
    OutstationTestObject t(config, configure::by_count_of::binary_input(1));
    t.LowerLayerUp();
    t.context.OnTxReady();

    REQUIRE(t.lower->PopWriteAsHex() == hex::NullUnsolicited(0));

    // Confirm unsolicited NULL response
    t.SendToOutstation(hex::UnsolConfirm(0));

    // Send a broadcast message
    t.BroadcastToOutstation(LinkBroadcastAddress::ShallConfirm, hex::ClearRestartIIN(1));

    // Outstation should not respond to broadcast request
    REQUIRE(t.lower->HasNoData());

    // Generate an event
    t.Transaction([](IUpdateHandler& handler) { handler.Update(Binary(true), 0); });

    // Should send unsolicited with BROADCAST IIN set
    REQUIRE(t.lower->PopWriteAsHex().substr(0, 11) == "F1 82 01 00");
    t.context.OnTxReady();

    // Timeout and generate another unsolicited
    t.AdvanceToNextTimer();
    t.Transaction([](IUpdateHandler& handler) { handler.Update(Binary(false), 0); });

    // Next unsolicited should still have BROADCAST IIN set
    REQUIRE(t.lower->PopWriteAsHex().substr(0, 11) == "F2 82 01 00");
    t.context.OnTxReady();

    // Confirm the unsolicited response
    t.SendToOutstation(hex::UnsolConfirm(2));

    // Generate an event
    t.Transaction([](IUpdateHandler& handler) { handler.Update(Binary(true), 0); });

    REQUIRE(t.lower->PopWriteAsHex().substr(0, 11) == "F3 82 00 00");
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

