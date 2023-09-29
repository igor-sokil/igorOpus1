
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
#include "BufferHelpers.h"
//#include "loghandler.h"
#include "MockAPDUHeaderHandler.h"
#include "HexConversions.h"
#include "APDUParser.h"

#include "TestAPDUParsing.h"

#define UNUSED(x) (void)(x)

void* pPointerGlobal1;
void* pPointerGlobal2;
void* pPointerGlobal3;

key_filter *pkf;

MainWindow *mainWindow;

void validate(MockApduHeaderHandler*);
void validate(MockApduHeaderHandler* mock)
{
qDebug()<<"REQUIRE(3 == mock.staticBinaries.size())";
 uint16_t size = mock->staticBinaries.size();
qDebug()<<"uint16_t size ="<<size;
  if(size!=3) return;
{
qDebug()<<"";
qDebug()<<"Indexed<Binary> value(Binary(true), 1)";
qDebug()<<"REQUIRE((value == mock.staticBinaries[0]))";
Indexed_for_Binary value = mock->staticBinaries[0];
qDebug()<<"value.index= "<<value.index;
boolean src = value.value.tTypedMeasurement_for_Boolean.value;
qDebug()<<"boolean src= "<<src;
}
{
qDebug()<<"";
qDebug()<<"Indexed<Binary> value(Binary(false), 2)";
qDebug()<<"REQUIRE((value == mock.staticBinaries[1]))";
Indexed_for_Binary value = mock->staticBinaries[1];
qDebug()<<"value.index= "<<value.index;
boolean src = value.value.tTypedMeasurement_for_Boolean.value;
qDebug()<<"boolean src= "<<src;
}
{
qDebug()<<"";
qDebug()<<"Indexed<Binary> value(Binary(true), 3)";
qDebug()<<"REQUIRE((value == mock.staticBinaries[2]))";
Indexed_for_Binary value = mock->staticBinaries[2];
qDebug()<<"value.index= "<<value.index;
boolean src = value.value.tTypedMeasurement_for_Boolean.value;
qDebug()<<"boolean src= "<<src;
}
}

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);

expectsContents_in_RangeParser = true;

qDebug()<<"********SUITE('14Group1Var2Range1to3')********";
void validate(MockApduHeaderHandler*);

  std::string name("01 02 00 01 03 81 01 81");       
ParseResult_uint8_t temp = TestComplex(name, validate);
qDebug()<<"TestComplex('01 02 00 01 03 81 01 81', ParseResult::OK, 1, [](MockApduHeaderHandler& mock)";
qDebug()<<"ParseResult_uint8_t result= "<<temp;
/*
TEST_CASE(SUITE("14Group1Var2Range1to3"))
{
    // 1 byte start / stop, 1 -> 3, 3 octets data
    TestComplex("01 02 00 01 03 81 01 81", ParseResult::OK, 1, [](MockApduHeaderHandler& mock) {
        REQUIRE(3 == mock.staticBinaries.size());
        {
            Indexed<Binary> value(Binary(true), 1);
            REQUIRE((value == mock.staticBinaries[0]));
        }
        {
            Indexed<Binary> value(Binary(false), 2);
            REQUIRE((value == mock.staticBinaries[1]));
        }
        {
            Indexed<Binary> value(Binary(true), 3);
            REQUIRE((value == mock.staticBinaries[2]));
        }
    });
}
*/
/*
void validate(MockApduHeaderHandler*);

  std::string name("02 02 06 02 00 06");       
ParseResult_uint8_t temp = TestComplex(name, validate);
qDebug()<<"TestComplex('02 02 06 02 00 06', ParseResult::OK, 2, [](MockApduHeaderHandler& mock)";
qDebug()<<"ParseResult_uint8_t result= "<<temp;
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

