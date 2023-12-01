
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

void apply_in_6Unsolicited(IUpdateHandler*);
void apply_in_6Unsolicited(IUpdateHandler* db)
{
    std::cout << "apply_in_6Unsolicited" <<'\n';
////    t.Transaction([](IUpdateHandler& handler) { handler.Update(Binary(true), 0); });
//void Binary_in_BinaryOver2(Binary *pBinary, boolean value);
 Binary bBinary;
 Binary_in_BinaryOver2(&bBinary, true);

//boolean Update_Binary_in_IUpdateHandler(IUpdateHandler*, Binary* meas, uint16_t index, EventMode_uint8_t mode);// = EventMode::Detect) = 0;
 Update_Binary_in_IUpdateHandler(db, &bBinary, 0, EventMode_Detect);// = EventMode::Detect) = 0;
}
void apply_in_6Unsolicited2(IUpdateHandler*);
void apply_in_6Unsolicited2(IUpdateHandler* db)
{
    std::cout << "apply_in_6Unsolicited2" <<'\n';
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


qDebug()<<"********SUITE('6Unsolicited responses should advertise BROADCAST IIN')********";
qDebug()<<"{+++++++++++6Unsolicited1";
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
std::string response = NullUnsolicited_in_APDUHexBuilders(0,
    &iIINField);// = opendnp3::IINField(opendnp3::IINBit::DEVICE_RESTART));

qDebug()<<"}----------6Unsolicited1";

    std::string temp1 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));

qDebug()<<" REQUIRE(t.lower->PopWriteAsHex() == hex::NullUnsolicited(0))";
std::cout << "response= " << response<<'\n';
std::cout << "temp1= " << temp1<<'\n';

    // Confirm unsolicited NULL response
qDebug()<<"{+++++++++6Unsolicited2";
////    t.SendToOutstation(hex::UnsolConfirm(0));
std::string unconstr = UnsolConfirm_in_APDUHexBuilders(0);
qDebug()<<"}----------6Unsolicited2";

qDebug()<<"{+++++++++6Unsolicited3";
    SendToOutstation_in_OutstationTestObject(&t, unconstr);  
qDebug()<<"}----------6Unsolicited3";

    // Send a broadcast message
qDebug()<<"{+++++++++6Unsolicited4";
////    t.BroadcastToOutstation(LinkBroadcastAddress::DontConfirm, hex::ClearRestartIIN(1));
std::string clrStr = ClearRestartIIN_in_APDUHexBuilders(1);
qDebug()<<"}----------6Unsolicited4";

qDebug()<<"{+++++++++6Unsolicited5";
     BroadcastToOutstation_in_OutstationTestObject(&t, LinkBroadcastAddress_DontConfirm, clrStr);
qDebug()<<"}----------6Unsolicited5";

    // Outstation should not respond to broadcast request
qDebug()<<"{+++++++++6Unsolicited6";
////    REQUIRE(t.lower->HasNoData());
boolean btemp = HasNoData_in_MockLowerLayer(&(t.lower));
qDebug()<<"}----------6Unsolicited6";

qDebug()<<"REQUIRE(t.lower->HasNoData())";
std::cout << "clrStr= " << clrStr<<'\n';
std::cout << "btemp= " << btemp<<'\n';

    // Generate an event
qDebug()<<"{+++++++++6Unsolicited7";
////    t.Transaction([](IUpdateHandler& handler) { handler.Update(Binary(true), 0); });
    Transaction_in_OutstationTestObject(&t, apply_in_6Unsolicited);//void (*apply)(IUpdateHandler*));
qDebug()<<"}----------6Unsolicited7";

    // Should send unsolicited with BROADCAST IIN set
qDebug()<<"{+++++++++6Unsolicited8";
////    REQUIRE(t.lower->PopWriteAsHex().substr(0, 11) == "F1 82 01 00");
    std::string temp2 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));
qDebug()<<"}----------6Unsolicited8";

qDebug()<<" REQUIRE(t.lower->PopWriteAsHex().substr(0, 11) == 'F1 82 01 00')";
std::cout << "temp2= " << temp2<<'\n';


qDebug()<<"{+++++++++6Unsolicited9";
////    t.context.OnTxReady();
    OnTxReady_in_OutstationTestObject(&t);
qDebug()<<"}----------6Unsolicited9";

qDebug()<<"{+++++++++6Unsolicited10";
    // Timeout and generate another unsolicited
////    t.AdvanceToNextTimer();
        AdvanceToNextTimer_in_OutstationTestObject(&t);
qDebug()<<"}----------6Unsolicited10";
qDebug()<<"{+++++++++6Unsolicited11";
////    t.Transaction([](IUpdateHandler& handler) { handler.Update(Binary(false), 0); });
    Transaction_in_OutstationTestObject(&t, apply_in_6Unsolicited2);//void (*apply)(IUpdateHandler*));
qDebug()<<"}----------6Unsolicited11";

qDebug()<<"{+++++++++6Unsolicited12";
    // Next unsolicited shouldn't have BROADCAST IIN set
////    REQUIRE(t.lower->PopWriteAsHex().substr(0, 11) == "F2 82 00 00");
    std::string temp3 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));
qDebug()<<"}----------6Unsolicited12";

qDebug()<<" REQUIRE(t.lower->PopWriteAsHex().substr(0, 11) == 'F2 82 00 00')";
std::cout << "temp3= " << temp3<<'\n';

///    t.context.OnTxReady();

/*
    // Generate an event
////    t.Transaction([](IUpdateHandler& handler) { handler.Update(Binary(true), 0); });
    Transaction_in_OutstationTestObject(&t, apply_in_4Receiving);//void (*apply)(IUpdateHandler*));

    // When reading, check that we receive a response with a confirmation
////    t.SendToOutstation(hex::ClassPoll(0, PointClass::Class1));
    std::string name1 = ClassPoll_in_APDUHexBuilders(0, PointClass_Class1);
    std::cout << "name1= " << name1<<'\n';
    SendToOutstation_in_OutstationTestObject(&t, name1);  

////    REQUIRE(t.lower->PopWriteAsHex().substr(0, 11) == "E0 81 80 00");
    std::string temp1 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));

qDebug()<<"REQUIRE(t.lower->PopWriteAsHex().substr(0, 11) == 'E0 81 80 00')";
std::cout << "temp1= " << temp1<<'\n';

////    t.OnTxReady();
    OnTxReady_in_OutstationTestObject(&t);

    // Send a broadcast message
////    t.BroadcastToOutstation(LinkBroadcastAddress::DontConfirm, hex::ClearRestartIIN(1));
std::string clrStr = ClearRestartIIN_in_APDUHexBuilders(1);
     BroadcastToOutstation_in_OutstationTestObject(&t, LinkBroadcastAddress_DontConfirm, clrStr);

    // Outstation should not respond to broadcast request
////    REQUIRE(t.lower->HasNoData());
boolean btemp = HasNoData_in_MockLowerLayer(&(t.lower));

qDebug()<<"REQUIRE(t.lower->HasNoData())";
std::cout << "clrStr= " << clrStr<<'\n';
std::cout << "btemp= " << btemp<<'\n';

    // Try confirming
////    t.SendToOutstation(hex::SolicitedConfirm(0));
std::string solstr = SolicitedConfirm_in_APDUHexBuilders(0);
    SendToOutstation_in_OutstationTestObject(&t, solstr);  
std::cout << "solstr= " << solstr<<'\n';

////    t.OnTxReady();
    OnTxReady_in_OutstationTestObject(&t);

    // When reading, check BROADCAST IIN, check that the events are still pending
// ѕри чтении провер€ем BROADCAST IIN, провер€ем, что событи€ еще ожидаютс€
////    t.SendToOutstation(hex::ClassPoll(2, PointClass::Class0));
    std::string name2 = ClassPoll_in_APDUHexBuilders(2, PointClass_Class0);
    std::cout << "name2= " << name2<<'\n';
    SendToOutstation_in_OutstationTestObject(&t, name2);  

////    REQUIRE(t.lower->PopWriteAsHex().substr(0, 11) == "C2 81 03 00");
    std::string temp2 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));

qDebug()<<"REQUIRE(t.lower->PopWriteAsHex().substr(0, 11) == 'C2 81 03 00')";
std::cout << "temp2= " << temp2<<'\n';

////    t.OnTxReady();
    OnTxReady_in_OutstationTestObject(&t);
*/
/*
TEST_CASE(SUITE("6Unsolicited responses should advertise BROADCAST IIN"))
¬ нежелательных ответах должен указыватьс€ BROADCAST IIN.
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
    t.BroadcastToOutstation(LinkBroadcastAddress::DontConfirm, hex::ClearRestartIIN(1));

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

    // Next unsolicited shouldn't have BROADCAST IIN set
    REQUIRE(t.lower->PopWriteAsHex().substr(0, 11) == "F2 82 00 00");
    t.context.OnTxReady();
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

