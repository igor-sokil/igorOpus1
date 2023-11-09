
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

#define UNUSED(x) (void)(x)


key_filter *pkf;

MainWindow *mainWindow;

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);


qDebug()<<"********SUITE('7SelectOperateTimeout')********";
    OutstationConfig config;
    OutstationConfig_in_OutstationConfig(&config);

//TimeDuration Seconds_in_TimeDuration_static(int64_t seconds);
    config.params.selectTimeout = Seconds_in_TimeDuration_static(5);////TimeDuration::Seconds(5);

    DatabaseConfig tmp;
    DatabaseConfig_in_DatabaseConfig(&tmp, 0);

    OutstationTestObject t;
    OutstationTestObject_in_OutstationTestObject(&t, &config, &tmp);

    LowerLayerUp_in_OutstationTestObject(&t);

    // Select group 12 Var 1, count = 1, index = 3
////    t.SendToOutstation("C0 03 0C 01 17 01 03 01 01 01 00 00 00 01 00 00 00 00");

    std::string name("C0 03 0C 01 17 01 03 01 01 01 00 00 00 01 00 00 00 00");       
    SendToOutstation_in_OutstationTestObject(&t, name);  

    std::string temp = PopWriteAsHex_in_MockLowerLayer(&(t.lower));

qDebug()<<"REQUIRE(t.lower->PopWriteAsHex() == 'C0 81 80 00 0C 01 17 01 03 01 01 01 00 00 00 01 00 00 00 00')";
std::cout << "temp= " << temp<<'\n';

qDebug()<<"";

std::cout << "t.cmdHandler->numStart= " << t.cmdHandler.sSimpleCommandHandler.numStart<<'\n';

qDebug()<<"";

std::cout << "t.cmdHandler->numEnd= " << t.cmdHandler.sSimpleCommandHandler.numEnd<<'\n';

std::cout << "t.cmdHandler->NumInvocations()= " << NumInvocations_in_MockCommandHandler(&(t.cmdHandler))<<'\n';

////    t.OnTxReady();
    OnTxReady_in_OutstationTestObject(&t);

//uint16_t AdvanceTime_in_OutstationTestObject(OutstationTestObject *pOutstationTestObject, TimeDuration* td);
////    t.AdvanceTime(TimeDuration::Milliseconds(5001));
    TimeDuration ttmp = Milliseconds_in_TimeDuration_static(5001);
    AdvanceTime_in_OutstationTestObject(&t, &ttmp);


    // operate
////    t.SendToOutstation("C1 04 0C 01 17 01 03 01 01 01 00 00 00 01 00 00 00 00");
////    REQUIRE(t.lower->PopWriteAsHex() == "C1 81 80 00 0C 01 17 01 03 01 01 01 00 00 00 01 00 00 00 00");
////    t.OnTxReady();
{
    std::string name("C1 04 0C 01 17 01 03 01 01 01 00 00 00 01 00 00 00 00");       
    SendToOutstation_in_OutstationTestObject(&t, name);  

    std::string temp = PopWriteAsHex_in_MockLowerLayer(&(t.lower));

qDebug()<<"REQUIRE(t.lower->PopWriteAsHex() == 'C1 81 80 00 0C 01 17 01 03 01 01 01 00 00 00 01 00 00 00 01')";
std::cout << "temp= " << temp<<'\n';

qDebug()<<"";

std::cout << "t.cmdHandler->numStart= " << t.cmdHandler.sSimpleCommandHandler.numStart<<'\n';

qDebug()<<"";

std::cout << "t.cmdHandler->numEnd= " << t.cmdHandler.sSimpleCommandHandler.numEnd<<'\n';

std::cout << "t.cmdHandler->NumInvocations()= " << NumInvocations_in_MockCommandHandler(&(t.cmdHandler))<<'\n';

////    t.OnTxReady();
    OnTxReady_in_OutstationTestObject(&t);

}


/*
TEST_CASE(SUITE("7SelectOperateTimeout"))
{
    OutstationConfig config;
    config.params.selectTimeout = TimeDuration::Seconds(5);
    OutstationTestObject t(config);
    t.LowerLayerUp();

    // Select group 12 Var 1, count = 1, index = 3
    t.SendToOutstation("C0 03 0C 01 17 01 03 01 01 01 00 00 00 01 00 00 00 00");
    REQUIRE(t.lower->PopWriteAsHex()
            == "C0 81 80 00 0C 01 17 01 03 01 01 01 00 00 00 01 00 00 00 00"); // 0x00 status == CommandStatus::SUCCESS
    t.OnTxReady();

    t.AdvanceTime(TimeDuration::Milliseconds(5001));

    // operate
    t.SendToOutstation("C1 04 0C 01 17 01 03 01 01 01 00 00 00 01 00 00 00 00");
    REQUIRE(t.lower->PopWriteAsHex() == "C1 81 80 00 0C 01 17 01 03 01 01 01 00 00 00 01 00 00 00 01"); // 0x01 timeout
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

