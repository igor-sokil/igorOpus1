
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

//void* pPointerGlobal1;
//void* pPointerGlobal2;
//void* pPointerGlobal3;

key_filter *pkf;

MainWindow *mainWindow;
/*
void validate(MockApduHeaderHandler* mock)
{
//std::vector<HeaderRecord> records;
qDebug()<<"REQUIRE((GroupVariation::Group2Var2 == mock.records[0].enumeration))";
qDebug()<<"mock.records[0].enumeration= "<<hex<<mock->records[0].gGroupVariationRecord.enumeration;

qDebug()<<"REQUIRE((GroupVariation::Group2Var0 == mock.records[1].enumeration))";
qDebug()<<"mock.records[1].enumeration= "<<hex<<mock->records[1].gGroupVariationRecord.enumeration;
}
*/

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);

expectsContents_in_CountIndexParser = true;

qDebug()<<"********SUITE('20Group1Var2CountWithIndexUInt8')********";
void validate(MockApduHeaderHandler*);

  std::string name("01 02 17 01 09 81");       
ParseResult_uint8_t temp = TestComplex(name, NULL);
qDebug()<<"TestComplex('01 02 17 01 09 81', ParseResult::INVALID_OBJECT_QUALIFIER, 0, [](MockApduHeaderHandler& mock)";
qDebug()<<"ParseResult_uint8_t result= "<<temp;
qDebug()<<"ParseResult::INVALID_OBJECT_QUALIFIER= "<<ParseResult_INVALID_OBJECT_QUALIFIER;
/*
TEST_CASE(SUITE("20Group1Var2CountWithIndexUInt8"))
{
    // 1 byte count, 1 byte index, index == 09, value = 0x81
    TestSimple("01 02 17 01 09 81", ParseResult::INVALID_OBJECT_QUALIFIER, 0);
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

