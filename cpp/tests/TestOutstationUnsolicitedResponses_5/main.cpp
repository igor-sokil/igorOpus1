
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


qDebug()<<"********SUITE('2Non-read during null unsol without workaround')********";
qDebug()<<"------------1";
////    OutstationConfig cfg;
////    cfg.params.allowUnsolicited = true;
////    cfg.params.unsolConfirmTimeout = TimeDuration::Seconds(5);
////    cfg.params.noDefferedReadDuringUnsolicitedNullResponse = false;
//////нет отложенного чтения во время незапрошенного нулевого ответа
////    OutstationTestObject t(cfg);
////    t.LowerLayerUp();
////    REQUIRE(t.lower->PopWriteAsHex() == hex::NullUnsolicited(0, IINField(IINBit::DEVICE_RESTART)));
////    t.OnTxReady();
////    REQUIRE(t.lower->NumWrites() == 0);

    OutstationConfig cfg;
    OutstationConfig_in_OutstationConfig(&cfg);

////    cfg.params.allowUnsolicited = true;
    cfg.params.allowUnsolicited = true;

////    config.params.unsolConfirmTimeout = TimeDuration::Seconds(5);
    cfg.params.unsolConfirmTimeout = Seconds_in_TimeDuration_static(5);

////    cfg.params.noDefferedReadDuringUnsolicitedNullResponse = false;
//////нет отложенного чтения во время незапрошенного нулевого ответа
    cfg.params.noDefferedReadDuringUnsolicitedNullResponse = false;

//   void OutstationTestObject_in_OutstationTestObject(OutstationConfig* config,
//                                                     DatabaseConfig* db_config);// = opendnp3::DatabaseConfig());
    DatabaseConfig database;
    DatabaseConfig_in_DatabaseConfig_default(&database);

    OutstationTestObject t;
    OutstationTestObject_in_OutstationTestObject(&t, &cfg, &database);

////    t.LowerLayerUp();
    LowerLayerUp_in_OutstationTestObject(&t);

////    REQUIRE(t.lower->PopWriteAsHex() == hex::NullUnsolicited(0, IINField(IINBit::DEVICE_RESTART)));
 IINField iIINField;
 IINField_in_IINFieldOver2(&iIINField, IINBit_DEVICE_RESTART);
 std::string respond = NullUnsolicited_in_APDUHexBuilders(0, &iIINField);// = opendnp3::IINField(opendnp3::IINBit::DEVICE_RESTART));

    std::string temp1 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));

std::cout << "respond= " << respond<<'\n';
qDebug()<<"REQUIRE(t.lower->PopWriteAsHex() == hex::NullUnsolicited(0, IINField(IINBit::DEVICE_RESTART)))";
std::cout << "temp1= " << temp1<<'\n';

////    t.OnTxReady();
    OnTxReady_in_OutstationTestObject(&t);

////    REQUIRE(t.lower->NumWrites() == 0);
uint16_t num = NumWrites_in_MockLowerLayer(&(t.lower));
qDebug()<<"REQUIRE(t.lower->NumWrites() == 0)";
std::cout << "num= " << (uint16_t)num<<'\n';

qDebug()<<"------------2";
////    // send any non-read message
////    t.SendToOutstation(hex::ClearRestartIIN(0));
////    REQUIRE(t.lower->PopWriteAsHex() == hex::EmptyResponse(0));
////    t.OnTxReady();

////    t.SendToOutstation(hex::ClearRestartIIN(0));
std::string clrStr = ClearRestartIIN_in_APDUHexBuilders(0);
std::cout << "clrStr= " << clrStr<<'\n';
    SendToOutstation_in_OutstationTestObject(&t, clrStr);  

///*
uint16_t num2 = NumWrites_in_MockLowerLayer(&(t.lower));
qDebug()<<"REQUIRE(t.lower->NumWrites() == 1)";
std::cout << "num2= " << (uint16_t)num2<<'\n';
//*/

////    REQUIRE(t.lower->PopWriteAsHex() == hex::EmptyResponse(0));
  IINField iIINField2 = Empty_in_IINField_static();
std::string emptyStr = EmptyResponse_in_APDUHexBuilders(0, &iIINField2);// = opendnp3::IINField::Empty());
    std::string temp2 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));
qDebug()<<"REQUIRE(t.lower->PopWriteAsHex() == hex::EmptyResponse(0))";
std::cout << "emptyStr= " << emptyStr<<'\n';
std::cout << "temp2= " << temp2<<'\n';

////    t.OnTxReady();
    OnTxReady_in_OutstationTestObject(&t);
/*
qDebug()<<"------------3";
////    // Continue sending unsolicited NULL responses
////    t.AdvanceTime(TimeDuration::Seconds(5));
////    REQUIRE(t.lower->PopWriteAsHex() == hex::NullUnsolicited(1, IINField()));
////    REQUIRE(t.NumPendingTimers() == 1);

////    // Continue sending unsolicited NULL responses
////    t.AdvanceTime(TimeDuration::Seconds(5));
    TimeDuration ttmp3 = Seconds_in_TimeDuration_static(5);
    AdvanceTime_in_OutstationTestObject(&t, &ttmp3);

////    REQUIRE(t.lower->PopWriteAsHex() == hex::NullUnsolicited(1, IINField()));
 IINField iIINField3;
 IINField_in_IINFieldOver1(&iIINField3);
 std::string respond3 = NullUnsolicited_in_APDUHexBuilders(1, &iIINField3);
    std::string temp3 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));
qDebug()<<"REQUIRE(t.lower->PopWriteAsHex() == hex::NullUnsolicited(1, IINField()))";
std::cout << "respond3= " << respond3<<'\n';
std::cout << "temp3= " << temp3<<'\n';

////    REQUIRE(t.NumPendingTimers() == 1);
uint16_t num3 = NumWrites_in_MockLowerLayer(&(t.lower));
qDebug()<<"REQUIRE(t.lower->NumWrites() == 1)";
std::cout << "num3= " << (uint16_t)num3<<'\n';
*/
/*
TEST_CASE(SUITE("2Non-read during null unsol without workaround"))
2Не читается во время нулевой отмены без обходного пути.
{
    OutstationConfig cfg;
    cfg.params.allowUnsolicited = true;
    cfg.params.unsolConfirmTimeout = TimeDuration::Seconds(5);
    cfg.params.noDefferedReadDuringUnsolicitedNullResponse = false;
//нет отложенного чтения во время незапрошенного нулевого ответа
    OutstationTestObject t(cfg);
    t.LowerLayerUp();

    REQUIRE(t.lower->PopWriteAsHex() == hex::NullUnsolicited(0, IINField(IINBit::DEVICE_RESTART)));
    t.OnTxReady();
    REQUIRE(t.lower->NumWrites() == 0);

    // send any non-read message
    t.SendToOutstation(hex::ClearRestartIIN(0));
    REQUIRE(t.lower->PopWriteAsHex() == hex::EmptyResponse(0));
    t.OnTxReady();

    // Continue sending unsolicited NULL responses
    t.AdvanceTime(TimeDuration::Seconds(5));
    REQUIRE(t.lower->PopWriteAsHex() == hex::NullUnsolicited(1, IINField()));
    REQUIRE(t.NumPendingTimers() == 1);
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

