
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

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);

expectsContents_in_CountParser = true;
//expectsContents_in_CountIndexParser = false;
//expectsContents_in_RangeParser = false;

qDebug()<<"********SUITE('20MixedVariationAssignments')********";
////    OutstationTestObject t(OutstationConfig(),
////                           configure::from({{0, configure::analog(StaticAnalogVariation::Group30Var1)},
////                                            {1, configure::analog(StaticAnalogVariation::Group30Var2)}}));

    OutstationConfig config;
    OutstationConfig_in_OutstationConfig(&config);

//DatabaseConfig from_AnalogConfig_in_DatabaseHelpers(std::map<uint16_t, AnalogConfig> map);
DatabaseConfig tmp = from_AnalogConfig_in_DatabaseHelpers(
                                           {{0, analog_in_DatabaseHelpers(StaticAnalogVariation_Group30Var1)},
                                            {1, analog_in_DatabaseHelpers(StaticAnalogVariation_Group30Var2)}}
                                                          );

//    DatabaseConfig tmp;
//    DatabaseConfig_in_DatabaseConfig(&tmp, 0);

    OutstationTestObject t;
    OutstationTestObject_in_OutstationTestObject(&t, &config, &tmp);

    LowerLayerUp_in_OutstationTestObject(&t);

    std::string name("C0 01 3C 01 06");       
    SendToOutstation_in_OutstationTestObject(&t, name);  

    std::string temp = PopWriteAsHex_in_MockLowerLayer(&(t.lower));

    // check that the response uses both g30v1 & g30v2
qDebug()<<"REQUIRE(t.lower->PopWriteAsHex() == 'C0 81 80 00 1E 01 00 00 00 02 00 00 00 00 1E 02 00 01 01 02 00 00')";
std::cout << "temp= " << temp<<'\n';

/*
TEST_CASE(SUITE("20MixedVariationAssignments"))
{
    OutstationTestObject t(OutstationConfig(),
                           configure::from({{0, configure::analog(StaticAnalogVariation::Group30Var1)},
                                            {1, configure::analog(StaticAnalogVariation::Group30Var2)}}));

    t.LowerLayerUp();

    t.SendToOutstation("C0 01 3C 01 06"); // Read class 0

    // check that the response uses both g30v1 & g30v2
    REQUIRE(t.lower->PopWriteAsHex() == "C0 81 80 00 1E 01 00 00 00 02 00 00 00 00 1E 02 00 01 01 02 00 00");
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

