
#include <QApplication>
#include <QtWidgets>

#include <stdlib.h>

#include "MainWindow.h"
#include "key_filter.h"

#include "header.h"

#include "APDUHelpers.h"
#include "APDUHeader.h"
#include "SerializationTemplates.h"
#include "Group2.h"
#include "EventStorage.h"

#include <EventType.h>
#include <MeasurementInfo.h>

#include <IEventWriteHandler.h>

#include <deque>

DWORD get_fattime (void);

#define UNUSED(x) (void)(x)

key_filter *pkf;

MainWindow *mainWindow;

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);
/*
    struct Record
    {
        EventType type;
        uint8_t variation;
        uint16_t count;
    };
    std::deque<Record> expected;
*/
 EventStorage storage;
   EventBufferConfig temp = AllTypes_in_EventBufferConfig_static(MAX_EventRecord);
 EventStorage_in_EventStorage(&storage, &temp);
  qDebug()<<"1111";
//boolean Update_for_BinarySpec_in_EventStorage(EventStorage *pEventStorage, Event_for_BinarySpec* evt);
//   void Event_for_BinarySpec_in_Event_for_BinarySpecOver2(Event_for_BinarySpec *pEvent_for_BinarySpec,
//                                                  Binary* value, uint16_t index,
//                                                  EventClass_uint8_t clazz,
//                                                  event_variation_t_in_BinaryInfo variation);
//   void Binary_in_BinaryOver2(Binary *pBinary, boolean value);
 Binary bBinary;
 Binary_in_BinaryOver2(&bBinary, true);
 Event_for_BinarySpec eEvent_for_BinarySpec;
   Event_for_BinarySpec_in_Event_for_BinarySpecOver2(&eEvent_for_BinarySpec,
                                                  &bBinary, 0,//uint16_t index,
                                                  EventClass_EC1,//EventClass_uint8_t clazz,
                                                  EventBinaryVariation_Group2Var1);//event_variation_t_in_BinaryInfo variation);
  qDebug()<<"2222";

boolean Booltemp = Update_for_BinarySpec_in_EventStorage(&storage, &eEvent_for_BinarySpec);
  qDebug()<<"3333";
  qDebug()<<"REQUIRE_FALSE(storage.Update(Event<BinarySpec>(Binary(true), 0, EventClass::EC1, EventBinaryVariation::Group2Var1)))";
  qDebug()<<"Booltemp= "<<Booltemp;
  qDebug()<<"";

/*
TEST_CASE(SUITE("calls_write_multiple_times_for_different_variations"))
{
    EventStorage storage(EventBufferConfig::AllTypes(10));

    REQUIRE_FALSE(
        storage.Update(Event<BinarySpec>(Binary(true), 0, EventClass::EC1, EventBinaryVariation::Group2Var1)));
    REQUIRE_FALSE(
        storage.Update(Event<BinarySpec>(Binary(true), 0, EventClass::EC1, EventBinaryVariation::Group2Var2)));

    // select events by class
    REQUIRE(storage.SelectByClass(EventClass::EC1) == 2);

    REQUIRE(storage.NumSelected() == 2);

    // set up the expected order
    MockEventWriteHandler handler;
    handler.Expect(EventBinaryVariation::Group2Var1, 1);
    handler.Expect(EventBinaryVariation::Group2Var2, 1);

    REQUIRE(storage.Write(handler) == 2);

    REQUIRE(storage.NumSelected() == 0);
    REQUIRE(storage.NumUnwritten(EventClass::EC1) == 0);

    handler.AssertEmpty();
}
*/
/*
 EventStorage storage;
//   EventBufferConfig AllTypes_in_EventBufferConfig_static(uint16_t sizes);
   EventBufferConfig temp = AllTypes_in_EventBufferConfig_static(MAX_EventRecord);
 EventStorage_in_EventStorage(&storage, &temp);

  qDebug()<<"sizeof(storage)= "<<sizeof(storage);
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

