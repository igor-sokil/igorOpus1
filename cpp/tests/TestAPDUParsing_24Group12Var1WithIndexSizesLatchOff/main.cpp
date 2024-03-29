
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


key_filter *pkf;

MainWindow *mainWindow;

void validate(MockApduHeaderHandler*);
void validate(MockApduHeaderHandler* mock)
{
////    auto validator = [&](MockApduHeaderHandler& mock) {
////        REQUIRE(1 == mock.crobRequests.size());
////        ControlRelayOutputBlock crob(OperationType::LATCH_OFF, TripCloseCode::NUL, false, 1, 100, 200);
////        Indexed<ControlRelayOutputBlock> value(crob, 9);
////        REQUIRE((value == mock.crobRequests[0]));
////        REQUIRE(1 == mock.records.size());
////    };


qDebug()<<"REQUIRE(1 == mock.crobRequests.size())";
 uint16_t size = mock->crobRequests.size();
qDebug()<<"uint16_t size ="<<size;
  if(size!=1) return;
{

qDebug()<<"";
qDebug()<<"ControlRelayOutputBlock crob(OperationType::LATCH_OFF, TripCloseCode::NUL, false, 1, 100, 200)";

qDebug()<<"REQUIRE((value == mock.crobRequests[0]))";

Indexed_for_ControlRelayOutputBlock value = mock->crobRequests[0];
qDebug()<<"value.index= "<<value.index;

//void ControlRelayOutputBlock_in_ControlRelayOutputBlockOver1(ControlRelayOutputBlock *pControlRelayOutputBlock,
//    OperationType_uint8_t opType,//// = OperationType::LATCH_ON,
//    TripCloseCode_uint8_t tcc,//// = TripCloseCode::NUL,
//    boolean clear,//// = false,
//    uint8_t count,//// = 1,
//    uint32_t onTime,//// = 100,
//    uint32_t offTime,//// = 100,
//    CommandStatus_uint8_t status);//// = CommandStatus::SUCCESS);
ControlRelayOutputBlock crob;
ControlRelayOutputBlock_in_ControlRelayOutputBlockOver1(&crob,
    OperationType_LATCH_OFF,
    TripCloseCode_NUL,
    false,
    1,
    100,
    200,
    CommandStatus_SUCCESS);

qDebug()<<"value.opType== crob.opType ->"<<(value.value.opType== crob.opType);
qDebug()<<"value.tcc== crob.tcc ->"<<(value.value.tcc== crob.tcc);
qDebug()<<"value.clear== crob.clear ->"<<(value.value.clear== crob.clear);
qDebug()<<"value.count== crob.count ->"<<(value.value.count== crob.count);
qDebug()<<"value.onTime== crob.onTime ->"<<(value.value.onTimeMS== crob.onTimeMS);
qDebug()<<"value.offTime== crob.offTime ->"<<(value.value.offTimeMS== crob.offTimeMS);

}
}

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);


qDebug()<<"********SUITE('24Group12Var1WithIndexSizesLatchOff')********";
////    auto hex = "0C 01 17 01 09 04 01 64 00 00 00 C8 00 00 00 00";
////    auto validator = [&](MockApduHeaderHandler& mock) {
////        REQUIRE(1 == mock.crobRequests.size());
////        ControlRelayOutputBlock crob(OperationType::LATCH_OFF, TripCloseCode::NUL, false, 1, 100, 200);
////        Indexed<ControlRelayOutputBlock> value(crob, 9);
////        REQUIRE((value == mock.crobRequests[0]));
////        REQUIRE(1 == mock.records.size());
////    };
////    TestComplex(hex, ParseResult::OK, 1, validator);

void validate(MockApduHeaderHandler*);
{
  std::string name("0C 01 17 01 09 04 01 64 00 00 00 C8 00 00 00 00");       
ParseResult_uint8_t temp = TestComplex(name, validate);
qDebug()<<"TestComplex('0C 01 17 01 09 03 01 64 00 00 00 C8 00 00 00 00', ParseResult::OK, 1, [](MockApduHeaderHandler& mock)";
qDebug()<<"ParseResult_uint8_t result= "<<temp;
}

/*
TEST_CASE(SUITE("24Group12Var1WithIndexSizesLatchOff"))
{
    auto hex = "0C 01 17 01 09 04 01 64 00 00 00 C8 00 00 00 00";

    auto validator = [&](MockApduHeaderHandler& mock) {
        REQUIRE(1 == mock.crobRequests.size());
        ControlRelayOutputBlock crob(OperationType::LATCH_OFF, TripCloseCode::NUL, false, 1, 100, 200);
        Indexed<ControlRelayOutputBlock> value(crob, 9);
        REQUIRE((value == mock.crobRequests[0]));

        REQUIRE(1 == mock.records.size());
    };

    TestComplex(hex, ParseResult::OK, 1, validator);
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

