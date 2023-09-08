
#include <QApplication>
#include <QtWidgets>

#include <stdlib.h>
#include <iostream>
#include <string>

#include "MainWindow.h"
#include "key_filter.h"

#include "header.h"

#include "EventStorage.h"
//#include "MockEventWriteHandler.h"

#include "EventType.h"
#include "MeasurementInfo.h"

#include "IEventWriteHandler.h"
#include "MockEventWriteHandler.h"
//#include "ControlRelayOutputBlock.h"

//#include "HexConversions.h"

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

qDebug()<<"********SUITE('4calls write multiple times for different types')********";

 EventStorage storage;
//   EventBufferConfig AllTypes_in_EventBufferConfig_static(uint16_t sizes);
   EventBufferConfig temp = AllTypes_in_EventBufferConfig_static(MAX_EventRecord);
 EventStorage_in_EventStorage(&storage, &temp);

  qDebug()<<"sizeof(storage)= "<<sizeof(storage);

pMemory_EventLists_1 = MEMORY_EventLists_1(0, &(storage.state));

////    REQUIRE_FALSE(
////        storage.Update(Event<AnalogSpec>(Analog(1.0), 0, EventClass::EC1, EventAnalogVariation::Group32Var1)));
  Analog aAnalog;
  Analog_in_AnalogOver2(&aAnalog, 1.0);

  Event_for_AnalogSpec eEvent_for_AnalogSpec;
  Event_for_AnalogSpec_in_Event_for_AnalogSpecOver2(&eEvent_for_AnalogSpec,
      &aAnalog, 0,
      EventClass_EC1,
      EventAnalogVariation_Group32Var1);

//boolean Update_for_AnalogSpec_in_EventStorage(EventStorage *pEventStorage, Event_for_AnalogSpec* evt);
  boolean tempBool = Update_AnalogSpec_in_EventStorage(&storage, &eEvent_for_AnalogSpec);
  qDebug()<<"REQUIRE_FALSE(storage.Update(Event<AnalogSpec>(Analog(1.0), 0, EventClass::EC1, EventAnalogVariation::Group32Var1)))";
  qDebug()<<"tempBool= "<<tempBool;

////    REQUIRE_FALSE(
////        storage.Update(Event<BinarySpec>(Binary(true), 0, EventClass::EC1, EventBinaryVariation::Group2Var1)));

  Binary bBinary;
  Binary_in_BinaryOver2(&bBinary, true);
//   void Event_for_BinarySpec_in_Event_for_BinarySpecOver2(Event_for_BinarySpec *pEvent_for_BinarySpec,
//                                                  Binary* value, uint16_t index,
//                                                  EventClass_uint8_t clazz,
//                                                  event_variation_t_in_BinaryInfo variation);
  Event_for_BinarySpec eEvent_for_BinarySpec;
  Event_for_BinarySpec_in_Event_for_BinarySpecOver2(&eEvent_for_BinarySpec,
      &bBinary, 0,
      EventClass_EC1,
      EventBinaryVariation_Group2Var1);

//boolean Update_BinarySpec_in_EventStorage(EventStorage *pEventStorage, Event_for_BinarySpec* evt);
  tempBool = Update_BinarySpec_in_EventStorage(&storage, &eEvent_for_BinarySpec);
  qDebug()<<"REQUIRE_FALSE(storage.Update(Event<BinarySpec>(Binary(true), 0, EventClass::EC1, EventBinaryVariation::Group2Var1)))";
  qDebug()<<"tempBool= "<<tempBool;

////    REQUIRE_FALSE(
////        storage.Update(Event<AnalogSpec>(Analog(1.0), 0, EventClass::EC1, EventAnalogVariation::Group32Var1)));

  Analog aAnalog1;
  Analog_in_AnalogOver2(&aAnalog1, 1.0);
//   void Event_for_AnalogSpec_in_Event_for_AnalogSpecOver2(Event_for_AnalogSpec *pEvent_for_AnalogSpec,
//                                                  Analog* value, uint16_t index,
//                                                  EventClass_uint8_t clazz,
//                                                  event_variation_t_in_AnalogInfo variation);
  Event_for_AnalogSpec eEvent_for_AnalogSpec1;
  Event_for_AnalogSpec_in_Event_for_AnalogSpecOver2(&eEvent_for_AnalogSpec1,
      &aAnalog1, 0,
      EventClass_EC1,
      EventAnalogVariation_Group32Var1);

//boolean Update_for_AnalogSpec_in_EventStorage(EventStorage *pEventStorage, Event_for_AnalogSpec* evt);
  tempBool = Update_AnalogSpec_in_EventStorage(&storage, &eEvent_for_AnalogSpec1);
  qDebug()<<"REQUIRE_FALSE(storage.Update(Event<AnalogSpec>(Analog(1.0), 0, EventClass::EC1, EventAnalogVariation::Group32Var1)))";
  qDebug()<<"tempBool= "<<tempBool;

  // select events by class
//    REQUIRE(storage.SelectByClass(EventClass::EC1) == 3);
//    uint32_t SelectByClass_in_EventStorageOver1(EventStorage *pEventStorage, EventClass_uint8_t clazz);
  uint32_t  tempUint32 = SelectByClass_in_EventStorageOver1(&storage, EventClass_EC1);
  qDebug()<<"REQUIRE(storage.SelectByClass(EventClass::EC1) == 3)";
  qDebug()<<"tempUint32= "<<tempUint32;

    MockEventWriteHandler handler;
    MockEventWriteHandler_in_MockEventWriteHandler(&handler);

////    handler.Expect(EventAnalogVariation::Group32Var1, 1);
    Expect_for_Analog_in_MockEventWriteHandler(&handler, EventAnalogVariation_Group32Var1, 1);
  qDebug()<<"Expect_for_Analog_in_MockEventWriteHandler(&handler, EventAnalogVariation_Group32Var1, 1)";

////    handler.Expect(EventBinaryVariation::Group2Var1, 1);
    Expect_for_Binary_in_MockEventWriteHandler(&handler, EventBinaryVariation_Group2Var1, 1);
  qDebug()<<"Expect_for_Binary_in_MockEventWriteHandler(&handler, EventBinaryVariation_Group2Var1, 1)";

////    handler.Expect(EventAnalogVariation::Group32Var1, 1);
    Expect_for_Analog_in_MockEventWriteHandler(&handler, EventAnalogVariation_Group32Var1, 1);
  qDebug()<<"Expect_for_Analog_in_MockEventWriteHandler(&handler, EventAnalogVariation_Group32Var1, 1)";

//uint32_t Write_in_EventStorage(EventStorage *pEventStorage, IEventWriteHandler* handler);
////    REQUIRE(storage.Write(handler) == 3);
uint32_t sss = Write_in_EventStorage(&storage, &(handler.iIEventWriteHandler));
  qDebug()<<"Write_in_EventStorage(&storage, &(handler.iIEventWriteHandler))";
  qDebug()<<"uint32_t sss ="<<sss;

 AssertEmpty_in_MockEventWriteHandler(&handler);

  /*
TEST_CASE(SUITE("4calls write multiple times for different types"))
{
    EventStorage storage(EventBufferConfig::AllTypes(10));

    REQUIRE_FALSE(
        storage.Update(Event<AnalogSpec>(Analog(1.0), 0, EventClass::EC1, EventAnalogVariation::Group32Var1)));
    REQUIRE_FALSE(
        storage.Update(Event<BinarySpec>(Binary(true), 0, EventClass::EC1, EventBinaryVariation::Group2Var1)));
    REQUIRE_FALSE(
        storage.Update(Event<AnalogSpec>(Analog(1.0), 0, EventClass::EC1, EventAnalogVariation::Group32Var1)));

    // select events by class
    REQUIRE(storage.SelectByClass(EventClass::EC1) == 3);

    // set up the expected order
    MockEventWriteHandler handler;
    handler.Expect(EventAnalogVariation::Group32Var1, 1);
    handler.Expect(EventBinaryVariation::Group2Var1, 1);
    handler.Expect(EventAnalogVariation::Group32Var1, 1);

    REQUIRE(storage.Write(handler) == 3);

    handler.AssertEmpty();
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
////        ControlRelayOutputBlock crob(0x51, 10, 100, 100, CommandStatus::SUCCESS);
 ControlRelayOutputBlock_in_ControlRelayOutputBlockOver2(&crob,
    0x51,
    10,//uint8_t count,//// = 1,
    100,//uint32_t onTime,//// = 100,
    100,//uint32_t offTime,//// = 100,
    CommandStatus_SUCCESS);

//boolean IsQUFlagSet_in_ControlRelayOutputBlock(ControlRelayOutputBlock *pControlRelayOutputBlock);
////        REQUIRE(crob.IsQUFlagSet() == true);
boolean tmp = IsQUFlagSet_in_ControlRelayOutputBlock(&crob);

qDebug()<<"REQUIRE(crob.IsQUFlagSet() == true)";
qDebug()<<"tmp ="<<tmp;
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

