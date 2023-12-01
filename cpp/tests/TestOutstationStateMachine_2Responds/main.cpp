
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
#include "DatabaseHelpers.h"

#define UNUSED(x) (void)(x)


key_filter *pkf;

MainWindow *mainWindow;

void update_in_1Responds(IUpdateHandler*);
void update_in_1Responds(IUpdateHandler* db)
{
    std::cout << "update_in_1Responds" <<'\n';
////    t.Transaction([](IUpdateHandler& db) { db.Update(Analog(1, Flags(0x01)), 0); });

 Flags fFlags;
 Flags_In_FlagsOver2(&fFlags, 1);

 Analog aAnalog;
 Analog_in_AnalogOver3(&aAnalog, 1.0, fFlags);

 Update_Analog_in_IUpdateHandler(db, &aAnalog, 0, EventMode_Detect);// = EventMode::Detect) = 0;
}

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);


qDebug()<<"********SUITE('2Responds to non-READ request while waiting for unsolicited confirm')********";
////    OutstationConfig config;
////    config.params.allowUnsolicited = true;
////    OutstationTestObject t(config, configure::by_count_of::analog_input(1));
////    t.LowerLayerUp();
////    REQUIRE(t.lower->PopWriteAsHex() == "F0 82 80 00");
////    t.OnTxReady();

    OutstationConfig config;
    OutstationConfig_in_OutstationConfig(&config);

////    config.params.allowUnsolicited = true;
    config.params.allowUnsolicited = true;

//DatabaseConfig octet_string_in_DatabaseHelpers(uint16_t num);
////    OutstationTestObject t(config, configure::by_count_of::analog_input(1));
DatabaseConfig tmp = analog_input_in_DatabaseHelpers(1);

    OutstationTestObject t;
    OutstationTestObject_in_OutstationTestObject(&t, &config, &tmp);

    LowerLayerUp_in_OutstationTestObject(&t);

    std::string temp = PopWriteAsHex_in_MockLowerLayer(&(t.lower));

qDebug()<<"REQUIRE(t.lower->PopWriteAsHex() == 'F0 82 80 00')";
std::cout << "temp= " << temp<<'\n';

////    t.OnTxReady();
    OnTxReady_in_OutstationTestObject(&t);

////    t.SendToOutstation("C0 02");                        // empty write
////    REQUIRE(t.lower->PopWriteAsHex() == "C0 81 80 00"); // null response
////    t.OnTxReady();

    std::string name2("C0 02");       
    SendToOutstation_in_OutstationTestObject(&t, name2);  

    std::string temp2 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));

qDebug()<<"REQUIRE(t.lower->PopWriteAsHex() == 'C0 81 80 00')";
std::cout << "temp2= " << temp2<<'\n';

////    t.OnTxReady();
    OnTxReady_in_OutstationTestObject(&t);

////    REQUIRE(t.lower->PopWriteAsHex().empty()); // shouldn't send anything else
    std::string temp3 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));
qDebug()<<"REQUIRE(t.lower->PopWriteAsHex().empty())";
std::cout << "temp3= " << temp3<<'\n';

/*
TEST_CASE(SUITE("2Responds to non-READ request while waiting for unsolicited confirm"))
{
    OutstationConfig config;
    config.params.allowUnsolicited = true;
    OutstationTestObject t(config, configure::by_count_of::analog_input(1));
    t.LowerLayerUp();

    REQUIRE(t.lower->PopWriteAsHex() == "F0 82 80 00");
    t.OnTxReady();

    t.SendToOutstation("C0 02");                        // empty write
    REQUIRE(t.lower->PopWriteAsHex() == "C0 81 80 00"); // null response
    t.OnTxReady();

    REQUIRE(t.lower->PopWriteAsHex().empty()); // shouldn't send anything else
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

