
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

qDebug()<<"********SUITE('6AcceptsMultipleAssignsmentPerMessage')********";
    const uint16_t NUM_BINARY = 5;
    const uint16_t NUM_ANALOG = 10;

    OutstationConfig config;
    OutstationConfig_in_OutstationConfig(&config);

//DatabaseConfig database_by_sizes_in_DatabaseHelpers(uint16_t num_binary,
//    uint16_t num_double_binary,
//    uint16_t num_analog,
//    uint16_t num_counter,
//    uint16_t num_frozen_counter,
//    uint16_t num_binary_output_status,
//    uint16_t num_analog_output_status,
//    uint16_t num_time_and_interval,
//    uint16_t num_octet_string)
////    OutstationTestObject t(config, configure::database_by_sizes(NUM_BINARY, 0, NUM_ANALOG, 0, 0, 0, 0, 0, 0));

DatabaseConfig tmp = database_by_sizes_in_DatabaseHelpers(
    NUM_BINARY,
    0,
    NUM_ANALOG,
    0,
    0,
    0,
    0,
    0,
    0);

    OutstationTestObject t;
    OutstationTestObject_in_OutstationTestObject(&t, &config, &tmp);

    t.application.supportsAssignClass = true;

    LowerLayerUp_in_OutstationTestObject(&t);

    // assign binaries 2 - 3 to class 2 - assign all analogs to class 3
////    t.SendToOutstation("C0 16 3C 03 06 01 00 01 02 00 03 00 3C 04 06 1E 00 06");
    std::string name("C0 16 3C 03 06 01 00 01 02 00 03 00 3C 04 06 1E 00 06");       
    SendToOutstation_in_OutstationTestObject(&t, name);  

    std::string temp = PopWriteAsHex_in_MockLowerLayer(&(t.lower));

qDebug()<<"REQUIRE(t.lower->PopWriteAsHex() == 'C0 81 80 00')";
std::cout << "temp= " << temp<<'\n';

////    REQUIRE(t.application->classAssignments.size() == 2);
qDebug()<<"REQUIRE(t.application->classAssignments.size() == 2)";
std::cout << "temp= " << t.application.classAssignments.size()<<'\n';

////    auto assignment = t.application->classAssignments.front();
////    REQUIRE(assignment == std::make_tuple(AssignClassType::BinaryInput, PointClass::Class2, 0, 4));

/*
TEST_CASE(SUITE("6AcceptsMultipleAssignsmentPerMessage"))
{
    const uint16_t NUM_BINARY = 5;
    const uint16_t NUM_ANALOG = 10;

    OutstationConfig config;
    OutstationTestObject t(config, configure::database_by_sizes(NUM_BINARY, 0, NUM_ANALOG, 0, 0, 0, 0, 0, 0));
    t.application->supportsAssignClass = true;
    t.LowerLayerUp();

    // assign binaries 2 - 3 to class 2 - assign all analogs to class 3
    t.SendToOutstation("C0 16 3C 03 06 01 00 01 02 00 03 00 3C 04 06 1E 00 06");
    REQUIRE(t.lower->PopWriteAsHex() == "C0 81 80 00");

    REQUIRE(t.application->classAssignments.size() == 2);
    auto assignment = t.application->classAssignments.front();
    REQUIRE(assignment == std::make_tuple(AssignClassType::BinaryInput, PointClass::Class2, 2, 3));
    t.application->classAssignments.pop_front();
    assignment = t.application->classAssignments.front();
    REQUIRE(assignment == std::make_tuple(AssignClassType::AnalogInput, PointClass::Class3, 0, 9));
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

