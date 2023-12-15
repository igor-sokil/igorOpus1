
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

qDebug()<<"{+++++++++++Update_Binary_in_IUpdateHandler1";
//boolean Update_Binary_in_IUpdateHandler(IUpdateHandler*, Binary* meas, uint16_t index, EventMode_uint8_t mode);// = EventMode::Detect) = 0;
 Update_Binary_in_IUpdateHandler(db, &bBinary, 0, EventMode_Detect);// = EventMode::Detect) = 0;
qDebug()<<"}----------Update_Binary_in_IUpdateHandler1_";
}
void apply_in_7ShallConfirm2(IUpdateHandler*);
void apply_in_7ShallConfirm2(IUpdateHandler* db)
{
    std::cout << "apply_in_7ShallConfirm2" <<'\n';
////    t.Transaction([](IUpdateHandler& handler) { handler.Update(Binary(false), 0); });
//void Binary_in_BinaryOver2(Binary *pBinary, boolean value);
 Binary bBinary;
 Binary_in_BinaryOver2(&bBinary, false);

qDebug()<<"{+++++++++++Update_Binary_in_IUpdateHandler2";
//boolean Update_Binary_in_IUpdateHandler(IUpdateHandler*, Binary* meas, uint16_t index, EventMode_uint8_t mode);// = EventMode::Detect) = 0;
 Update_Binary_in_IUpdateHandler(db, &bBinary, 0, EventMode_Detect);// = EventMode::Detect) = 0;
qDebug()<<"}----------Update_Binary_in_IUpdateHandler2_";
}

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);


qDebug()<<"********SUITE('7ShallConfirm: Unsolicited responses should clear BROADCAST when confirm is received')********";
qDebug()<<"{+++++++++++7ShallConfirm1";
//ClassField  AllClasses_in_ClassField_static(void);
////    OutstationConfig config;
////    config.params.unsolClassMask = ClassField::AllClasses();
////    config.eventBufferConfig = EventBufferConfig::AllTypes(10);
////    config.params.allowUnsolicited = true;
////    config.params.numUnsolRetries = NumRetries::Fixed(0);
////    OutstationTestObject t(config, configure::by_count_of::binary_input(1));
////    t.LowerLayerUp();
////    t.context.OnTxReady();
////    REQUIRE(t.lower->PopWriteAsHex() == hex::NullUnsolicited(0));

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

    // Confirm unsolicited NULL response
qDebug()<<"{+++++++++UnsolConfirm_in_APDUHexBuilders2";
////    t.SendToOutstation(hex::UnsolConfirm(0));
std::string unconstr = UnsolConfirm_in_APDUHexBuilders(0);
qDebug()<<"}----------UnsolConfirm_in_APDUHexBuilders2_";
std::cout << "unconstr= " << unconstr<<'\n';

qDebug()<<"{+++++++++SendToOutstation_in_OutstationTestObject3";
    SendToOutstation_in_OutstationTestObject(&t, unconstr);  
qDebug()<<"}----------SendToOutstation_in_OutstationTestObject3_";

    // Send a broadcast message
qDebug()<<"{+++++++++ClearRestartIIN_in_APDUHexBuilders4";
////    t.BroadcastToOutstation(LinkBroadcastAddress::ShallConfirm, hex::ClearRestartIIN(1));
std::string clrStr = ClearRestartIIN_in_APDUHexBuilders(1);
qDebug()<<"}----------ClearRestartIIN_in_APDUHexBuilders4_";
std::cout << "clrStr= " << clrStr<<'\n';

qDebug()<<"{+++++++++BroadcastToOutstation_in_OutstationTestObject5";
     BroadcastToOutstation_in_OutstationTestObject(&t, LinkBroadcastAddress_ShallConfirm, clrStr);
qDebug()<<"}----------BroadcastToOutstation_in_OutstationTestObject5_";

    // Outstation should not respond to broadcast request
qDebug()<<"{+++++++++HasNoData_in_MockLowerLayer6";
////    REQUIRE(t.lower->HasNoData());
boolean btemp = HasNoData_in_MockLowerLayer(&(t.lower));
qDebug()<<"}----------HasNoData_in_MockLowerLayer6_";

qDebug()<<"REQUIRE(t.lower->HasNoData())";
std::cout << "btemp= " << btemp<<'\n';

    // Generate an event
////    t.Transaction([](IUpdateHandler& handler) { handler.Update(Binary(true), 0); });
    // Should send unsolicited with BROADCAST IIN set
////    REQUIRE(t.lower->PopWriteAsHex().substr(0, 11) == "F1 82 01 00");
////    t.context.OnTxReady();

    // Generate an event
qDebug()<<"{+++++++++Transaction_in_OutstationTestObject7";
////    t.Transaction([](IUpdateHandler& handler) { handler.Update(Binary(true), 0); });
    Transaction_in_OutstationTestObject(&t, apply_in_7ShallConfirm);//void (*apply)(IUpdateHandler*));
qDebug()<<"}----------Transaction_in_OutstationTestObject7_";

    // Should send unsolicited with BROADCAST IIN set
qDebug()<<"{+++++++++PopWriteAsHex_in_MockLowerLayer8";
////    REQUIRE(t.lower->PopWriteAsHex().substr(0, 11) == "F1 82 01 00");
    std::string temp2 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));
qDebug()<<"}----------PopWriteAsHex_in_MockLowerLayer8_";

qDebug()<<" REQUIRE(t.lower->PopWriteAsHex().substr(0, 11) == 'F1 82 01 00')";
std::cout << "temp2= " << temp2<<'\n';

qDebug()<<"{+++++++++OnTxReady_in_OutstationTestObject9";
////    t.context.OnTxReady();
    OnTxReady_in_OutstationTestObject(&t);
qDebug()<<"}----------OnTxReady_in_OutstationTestObject9_";

    // Timeout and generate another unsolicited
////    t.AdvanceToNextTimer();
////    t.Transaction([](IUpdateHandler& handler) { handler.Update(Binary(false), 0); });
    // Next unsolicited should still have BROADCAST IIN set
////    REQUIRE(t.lower->PopWriteAsHex().substr(0, 11) == "F2 82 01 00");
///    t.context.OnTxReady();


qDebug()<<"{+++++++++AdvanceToNextTimer_in_OutstationTestObject10";
    // Timeout and generate another unsolicited
////    t.AdvanceToNextTimer();
        AdvanceToNextTimer_in_OutstationTestObject(&t);
qDebug()<<"}----------AdvanceToNextTimer_in_OutstationTestObject10_";
qDebug()<<"{+++++++++Transaction_in_OutstationTestObject11";
////    t.Transaction([](IUpdateHandler& handler) { handler.Update(Binary(false), 0); });
    Transaction_in_OutstationTestObject(&t, apply_in_7ShallConfirm2);//void (*apply)(IUpdateHandler*));
qDebug()<<"}----------Transaction_in_OutstationTestObject11_";

qDebug()<<"{+++++++++PopWriteAsHex_in_MockLowerLayer12";
    // Next unsolicited should still have BROADCAST IIN set
////    REQUIRE(t.lower->PopWriteAsHex().substr(0, 11) == "F2 82 01 00");
    std::string temp3 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));
qDebug()<<"}----------PopWriteAsHex_in_MockLowerLayer12_";

qDebug()<<" REQUIRE(t.lower->PopWriteAsHex().substr(0, 11) == 'F2 82 01 00')";
std::cout << "temp3= " << temp3<<'\n';

    // Confirm the unsolicited response
////    t.SendToOutstation(hex::UnsolConfirm(2));
    // Generate an event
////    t.Transaction([](IUpdateHandler& handler) { handler.Update(Binary(true), 0); });
////    REQUIRE(t.lower->PopWriteAsHex().substr(0, 11) == "F3 82 00 00");

qDebug()<<"{+++++++++OnTxReady_in_OutstationTestObject13";
///    t.context.OnTxReady();
    OnTxReady_in_OutstationTestObject(&t);
qDebug()<<"}----------OnTxReady_in_OutstationTestObject13_";

    // Confirm the unsolicited response
qDebug()<<"{+++++++++UnsolConfirm_in_APDUHexBuilders14";
////    t.SendToOutstation(hex::UnsolConfirm(2));
std::string unconstr2 = UnsolConfirm_in_APDUHexBuilders(2);
qDebug()<<"}----------UnsolConfirm_in_APDUHexBuilders14_";
std::cout << "unconstr2= " << unconstr2<<'\n';

qDebug()<<"{+++++++++SendToOutstation_in_OutstationTestObject15";
    SendToOutstation_in_OutstationTestObject(&t, unconstr2);  
qDebug()<<"}----------SendToOutstation_in_OutstationTestObject15_";

    // Generate an event
qDebug()<<"{+++++++++Transaction_in_OutstationTestObject16";
////    t.Transaction([](IUpdateHandler& handler) { handler.Update(Binary(true), 0); });
    Transaction_in_OutstationTestObject(&t, apply_in_7ShallConfirm);//void (*apply)(IUpdateHandler*));
qDebug()<<"}----------Transaction_in_OutstationTestObject16_";

qDebug()<<"{+++++++++PopWriteAsHex_in_MockLowerLayer17";
////    REQUIRE(t.lower->PopWriteAsHex().substr(0, 11) == "F3 82 00 00");
    std::string temp4 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));
qDebug()<<"}----------PopWriteAsHex_in_MockLowerLayer17_";

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

