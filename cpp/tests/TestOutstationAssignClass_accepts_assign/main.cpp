
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
#include "loghandler.h"


#define UNUSED(x) (void)(x)

void* pPointerGlobal1;
void* pPointerGlobal2;
void* pPointerGlobal3;

key_filter *pkf;

MainWindow *mainWindow;

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);

qDebug()<<"********SUITE('accepts assign class via all objects header')********";

//    DatabaseConfig binary_input_in_DatabaseHelpers(uint16_t num);
//   void OutstationTestObject_in_OutstationTestObject(OutstationTestObject *pOutstationTestObject, OutstationConfig* config);
////    OutstationTestObject t(OutstationConfig(), configure::by_count_of::binary_input(5));
    DatabaseConfig tmp = binary_input_in_DatabaseHelpers(5);

    OutstationConfig oOutstationConfig;
    OutstationConfig_in_OutstationConfig(&oOutstationConfig);

    OutstationTestObject t;
    OutstationTestObject_in_OutstationTestObject(&t, &oOutstationConfig, &tmp);

    t.application.supportsAssignClass = true;

////    t.LowerLayerUp();
    LowerLayerUp_in_OutstationTestObject(&t);

    // assign binaries to class 2
////    t.SendToOutstation("C0 16 3C 03 06 01 00 06");
          std::string name("C0 16 3C 03 06 01 00 06");       
    SendToOutstation_in_OutstationTestObject(&t, name);  

////    REQUIRE(t.lower->PopWriteAsHex() == "C0 81 80 00");
    std::string temp = PopWriteAsHex_in_MockLowerLayer(&(t.lower));
qDebug()<<"REQUIRE(t.lower->PopWriteAsHex() == 'C0 81 80 00')";
std::cout << "temp= " << temp;

/*
////    OutstationConfig config;
////    OutstationTestObject t(config);
////    t.LowerLayerUp();
    OutstationConfig config;
    OutstationConfig_in_OutstationConfig(&config);
    OutstationTestObject t;
    OutstationTestObject_in_OutstationTestObject(&t, &config);

    LowerLayerUp_in_OutstationTestObject(&t);

    // assign binaries to class 2
////    t.SendToOutstation("C0 16 3C 03 06 01 00 06");
    std::string name("C0 16 3C 03 06 01 00 06");       
    SendToOutstation_in_OutstationTestObject(&t, name);  

    std::string temp = PopWriteAsHex_in_MockLowerLayer(&(t.lower));
qDebug()<<"REQUIRE(t.lower->PopWriteAsHex() == 'C0 81 80 01')";
std::cout << "temp= " << temp;

qDebug()<<"";

////    REQUIRE(t.application->classAssignments.empty());
 boolean tmp = t.application.classAssignments.empty();
qDebug()<<"REQUIRE(t.application->classAssignments.empty())";
std::cout << "tmp= " << tmp;
*/
/*
TEST_CASE(SUITE("accepts assign class via all objects header"))
//��������� ����������� ����� ����� ��������� ���� ��������
{
    OutstationTestObject t(OutstationConfig(), configure::by_count_of::binary_input(5));
    t.application->supportsAssignClass = true;
    t.LowerLayerUp();

    // assign binaries to class 2
    t.SendToOutstation("C0 16 3C 03 06 01 00 06");
    REQUIRE(t.lower->PopWriteAsHex() == "C0 81 80 00");

    REQUIRE(t.application->classAssignments.size() == 1);
    auto assignment = t.application->classAssignments.front();
    REQUIRE(assignment == std::make_tuple(AssignClassType::BinaryInput, PointClass::Class2, 0, 4));
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
