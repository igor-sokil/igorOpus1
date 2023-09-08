
#include <QApplication>
#include <QtWidgets>

#include <stdlib.h>
#include <iostream>
#include <string>

#include "MainWindow.h"
#include "key_filter.h"

#include "header.h"

#include "ControlRelayOutputBlock.h"

#include "HexConversions.h"

DWORD get_fattime (void);

#define UNUSED(x) (void)(x)

key_filter *pkf;

MainWindow *mainWindow;

void* pPointerGlobal1;
void* pPointerGlobal2;
void* pPointerGlobal3;

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);

qDebug()<<"********SUITE('4From raw code properly parses the enums')********";
    ControlRelayOutputBlock crob;
//void ControlRelayOutputBlock_in_ControlRelayOutputBlockOver2(ControlRelayOutputBlock *pControlRelayOutputBlock,
//    uint8_t rawCode,
//    uint8_t count,//// = 1,
//    uint32_t onTime,//// = 100,
//    uint32_t offTime,//// = 100,
//    CommandStatus_uint8_t status);//// = CommandStatus::SUCCESS);
////    ControlRelayOutputBlock crob(0xA2, 10, 100, 100, CommandStatus::SUCCESS);
 ControlRelayOutputBlock_in_ControlRelayOutputBlockOver2(&crob,
    0xA2,
    10,//uint8_t count,//// = 1,
    100,//uint32_t onTime,//// = 100,
    100,//uint32_t offTime,//// = 100,
    CommandStatus_SUCCESS);

////    REQUIRE(crob.opType == OperationType::PULSE_OFF);
////    REQUIRE(crob.tcc == TripCloseCode::TRIP);
////    REQUIRE(crob.clear == true);

qDebug()<<"REQUIRE(crob.opType == OperationType::PULSE_OFF)";
qDebug()<<"crob.opType ="<<crob.opType;
qDebug()<<"OperationType::PULSE_OFF ="<<OperationType_PULSE_OFF;

qDebug()<<"REQUIRE(crob.tcc == TripCloseCode::TRIP)";
qDebug()<<"crob.tcc ="<<crob.tcc;
qDebug()<<"TripCloseCode::TRIP ="<<TripCloseCode_TRIP;

qDebug()<<"REQUIRE(crob.clear == true)";
qDebug()<<"crob.clear ="<<crob.clear;

  /*
TEST_CASE(SUITE("4From raw code properly parses the enums"))
{
    ControlRelayOutputBlock crob(0xA2, 10, 100, 100, CommandStatus::SUCCESS);

    REQUIRE(crob.opType == OperationType::PULSE_OFF);
    REQUIRE(crob.tcc == TripCloseCode::TRIP);
    REQUIRE(crob.clear == true);
}
  */
/*
    ControlRelayOutputBlock crob;
//void ControlRelayOutputBlock_in_ControlRelayOutputBlockOver2(ControlRelayOutputBlock *pControlRelayOutputBlock,
//    uint8_t rawCode,
//    uint8_t count,//// = 1,
//    uint32_t onTime,//// = 100,
//    uint32_t offTime,//// = 100,
//    CommandStatus_uint8_t status);//// = CommandStatus::SUCCESS);
////    ControlRelayOutputBlock crob(0xAA, 10, 100, 100, CommandStatus::SUCCESS);
 ControlRelayOutputBlock_in_ControlRelayOutputBlockOver2(&crob,
    0xAA,
    10,//uint8_t count,//// = 1,
    100,//uint32_t onTime,//// = 100,
    100,//uint32_t offTime,//// = 100,
    CommandStatus_SUCCESS);

////    REQUIRE(crob.rawCode == 0xAA);

qDebug()<<"REQUIRE(crob.rawCode == 0xAA)";
qDebug()<<"crob.rawCode ="<<hex<<crob.rawCode;

qDebug()<<"REQUIRE(crob.opType == OperationType::Undefined)";
qDebug()<<"crob.opType ="<<crob.opType;
qDebug()<<"OperationType::Undefined ="<<OperationType_Undefined;
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

