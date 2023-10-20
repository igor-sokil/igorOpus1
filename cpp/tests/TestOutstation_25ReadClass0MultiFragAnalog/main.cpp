
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

void apply_in_25ReadClass0MultiFragAnalog(IUpdateHandler*);
void apply_in_25ReadClass0MultiFragAnalog(IUpdateHandler* db)
{
 Flags fFlags;
 Flags_In_FlagsOver2(&fFlags, 1);

//void Analog_in_AnalogOver3(Analog *pAnalog, double value, Flags flags);
 Analog aAnalog;
 Analog_in_AnalogOver3(&aAnalog, 0.0, fFlags);

        for (uint16_t i = 0; i < 8; i++)
        {
//boolean Update_Analog_in_IUpdateHandler(IUpdateHandler*, Analog* meas, uint16_t index, EventMode_uint8_t mode);// = EventMode::Detect) = 0;
////            db.Update(Analog(0, Flags(0x01)), i);
         Update_Analog_in_IUpdateHandler(db, &aAnalog, i, EventMode_Detect);// = EventMode::Detect) = 0;
        }
}

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);

expectsContents_in_CountParser = true;
//expectsContents_in_CountIndexParser = false;
//expectsContents_in_RangeParser = false;

qDebug()<<"********SUITE('25ReadClass0MultiFragAnalog')********";
    OutstationConfig config;
    OutstationConfig_in_OutstationConfig(&config);
    config.params.maxTxFragSize = 20; // override to use a fragment length of 20


////    OutstationTestObject t(config, configure::by_count_of::analog_input(8));
DatabaseConfig tmp = analog_input_in_DatabaseHelpers(8);

    OutstationTestObject t;
    OutstationTestObject_in_OutstationTestObject(&t, &config, &tmp);

    LowerLayerUp_in_OutstationTestObject(&t);

//void Transaction_in_OutstationTestObject(OutstationTestObject *pOutstationTestObject, void (*apply)(IUpdateHandler*));//std::function<void(opendnp3::IUpdateHandler&)>& apply)
////    t.Transaction([](IUpdateHandler& db) {
////        for (uint16_t i = 0; i < 8; i++)
////        {
////            db.Update(Analog(0, Flags(0x01)), i);
////        }
////    });

    Transaction_in_OutstationTestObject(&t, apply_in_25ReadClass0MultiFragAnalog);//void (*apply)(IUpdateHandler*));

    std::string name("C0 01 3C 01 06");       
    SendToOutstation_in_OutstationTestObject(&t, name);  

    std::string temp = PopWriteAsHex_in_MockLowerLayer(&(t.lower));

qDebug()<<"REQUIRE(t.lower->PopWriteAsHex() == 'A0 81 80 00 1E 01 00 00 01 01 00 00 00 00 01 00 00 00 00')";
std::cout << "temp= " << temp<<'\n';

//uint16_t OnTxReady_in_OutstationTestObject(OutstationTestObject *pOutstationTestObject);
////    t.OnTxReady();
 OnTxReady_in_OutstationTestObject(&t);
/*
////    t.SendToOutstation("C0 00");
    std::string name1("C0 00");       
    SendToOutstation_in_OutstationTestObject(&t, name1);  

    std::string temp1 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));

qDebug()<<"REQUIRE(t.lower->PopWriteAsHex() == '21 81 80 00 1E 01 00 02 03 01 00 00 00 00 01 00 00 00 00')";
std::cout << "temp1= " << temp1<<'\n';
*/
/*
TEST_CASE(SUITE("25ReadClass0MultiFragAnalog"))
{
    OutstationConfig config;
    config.params.maxTxFragSize = 20; // override to use a fragment length of 20
    OutstationTestObject t(config, configure::by_count_of::analog_input(8));
    t.LowerLayerUp();

    t.Transaction([](IUpdateHandler& db) {
        for (uint16_t i = 0; i < 8; i++)
        {
            db.Update(Analog(0, Flags(0x01)), i);
        }
    });

    t.SendToOutstation("C0 01 3C 01 06"); // Read class 0

    // Response should be (30,1)x2 per fragment, quality ONLINE, value 0
    // 4 fragment response, first 3 fragments should be confirmed, last one shouldn't be
    REQUIRE(t.lower->PopWriteAsHex() == "A0 81 80 00 1E 01 00 00 01 01 00 00 00 00 01 00 00 00 00");
    t.OnTxReady();
    t.SendToOutstation("C0 00");
    REQUIRE(t.lower->PopWriteAsHex() == "21 81 80 00 1E 01 00 02 03 01 00 00 00 00 01 00 00 00 00");
    t.OnTxReady();
    t.SendToOutstation("C1 00");
    REQUIRE(t.lower->PopWriteAsHex() == "22 81 80 00 1E 01 00 04 05 01 00 00 00 00 01 00 00 00 00");
    t.OnTxReady();
    t.SendToOutstation("C2 00");
    REQUIRE(t.lower->PopWriteAsHex() == "43 81 80 00 1E 01 00 06 07 01 00 00 00 00 01 00 00 00 00");
    t.OnTxReady();
    t.SendToOutstation("C3 00");

    REQUIRE(t.lower->PopWriteAsHex().empty());
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

