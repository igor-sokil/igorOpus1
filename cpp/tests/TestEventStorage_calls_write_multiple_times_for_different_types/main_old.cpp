
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
//#include "MockEventWriteHandler.h"

#include <EventType.h>
#include <MeasurementInfo.h>

#include <IEventWriteHandler.h>

#include <deque>

#include "loghandler.h"

#define UNUSED(x) (void)(x)

key_filter *pkf;

MainWindow *mainWindow;

EventBufferConfig __AllTypes_in_EventBufferConfig_static(uint16_t sizes);
uint32_t __NumUnwritten_in_EventStorage(EventStorage *pEventStorage, EventClass_uint8_t clazz);
void __EventStorage_in_EventStorage(EventStorage *pEventStorage, EventBufferConfig* config);

//class MockEventWriteHandler
//typedef struct
//{
//public:

//struct Record
typedef struct
{
  EventType_uint16_t type;
  uint8_t variation;
  uint16_t count;
} Record;
std::deque<Record> expected;
//} MockEventWriteHandler;
////    template<class T> class EventWriterImpl : public opendnp3::IEventWriter<T>
     typedef struct
{
////    public:
        boolean success;// = true;
       std::vector<uint16_t> written_indices;

////        virtual bool Write(const T& meas, uint16_t index) override
////        {
////            if (success)
////            {
////                written_indices.push_back(index);
////            }
////            return success;
////        }
} EventWriterImpl;

void AssertEmpty_in_MockEventWriteHandler();
void ExpectType_for_BinaryInfo_in_MockEventWriteHandler(EventBinaryVariation_uint8_t variation, uint16_t count);
void ExpectType_for_AnalogInfo_in_MockEventWriteHandler(EventAnalogVariation_uint8_t variation, uint16_t count);
void Expect_for_BinaryInfo_in_MockEventWriteHandler(EventBinaryVariation_uint8_t variation, uint16_t count);
void Expect_for_AnalogInfo_in_MockEventWriteHandler(EventAnalogVariation_uint8_t variation, uint16_t count);
uint16_t Write_for_BinaryInfo_in_MockEventWriteHandler(EventBinaryVariation_uint8_t variation, Binary* first, IEventCollection_for_Binary* items);
uint16_t Write_for_AnalogInfo_in_MockEventWriteHandler(EventAnalogVariation_uint8_t variation, Analog* first, IEventCollection_for_Analog* items);
uint16_t WriteAny_for_BinaryInfo_in_MockEventWriteHandler(EventBinaryVariation_uint8_t variation, IEventCollection_for_Binary* items);
uint16_t WriteAny_for_AnalogInfo_in_MockEventWriteHandler(EventAnalogVariation_uint8_t variation, IEventCollection_for_Analog* items);
void EventWriterImpl_in_EventWriterImpl(EventWriterImpl* pEventWriterImpl);
boolean Write_in_EventWriterImpl_for_Analog(Analog* meas, uint16_t index);
boolean Write_in_EventWriterImpl_for_Binary(Binary* meas, uint16_t index);

void ExpectType_for_BinaryInfo_in_MockEventWriteHandler(EventBinaryVariation_uint8_t variation, uint16_t count)
{
  expected.push_back(Record{EventType_Binary, (uint8_t)(variation), count});
}
void ExpectType_for_AnalogInfo_in_MockEventWriteHandler(EventAnalogVariation_uint8_t variation, uint16_t count)
{
  expected.push_back(Record{EventType_Analog, (uint8_t)(variation), count});
}

void Expect_for_BinaryInfo_in_MockEventWriteHandler(EventBinaryVariation_uint8_t variation, uint16_t count)
{
  ExpectType_for_BinaryInfo_in_MockEventWriteHandler(variation, count);
}
void Expect_for_AnalogInfo_in_MockEventWriteHandler(EventAnalogVariation_uint8_t variation, uint16_t count)
{
  ExpectType_for_AnalogInfo_in_MockEventWriteHandler(variation, count);
}

void AssertEmpty_in_MockEventWriteHandler()
{
  if (!expected.empty())
  {
////            throw std::logic_error("more events expected");
    printf("std::logic_error( more events expected )");
  }
}

//     uint16_t (*pWrite_in_IEventWriteHandlerOver1)(EventBinaryVariation_uint8_t variation, Binary* first, IEventCollection_for_Binary* items);//// = 0;
uint16_t Write_for_BinaryInfo_in_MockEventWriteHandler(EventBinaryVariation_uint8_t variation, Binary* first, IEventCollection_for_Binary* items)
{
  UNUSED(first);
//        return this->WriteAny<opendnp3::BinaryInfo>(variation, items);
  return WriteAny_for_BinaryInfo_in_MockEventWriteHandler(variation, items);
}
uint16_t Write_for_AnalogInfo_in_MockEventWriteHandler(EventAnalogVariation_uint8_t variation, Analog* first, IEventCollection_for_Analog* items)
{
  UNUSED(first);
//        return this->WriteAny<opendnp3::BinaryInfo>(variation, items);
  return WriteAny_for_AnalogInfo_in_MockEventWriteHandler(variation, items);
}

////uint16_t MockEventWriteHandler::WriteAny(typename T::event_variation_t variation,
////                                         opendnp3::IEventCollection<typename T::meas_t>& items)
 EventWriterImpl writer_for_Analog;
 uint16_t   WriteAny_for_AnalogInfo_in_MockEventWriteHandler(EventAnalogVariation_uint8_t variation, IEventCollection_for_Analog* items)
{
////    if (this->expected.empty())
  if (expected.empty())
    {
////        throw std::logic_error("no more write events expected");
    printf("std::logic_error( no more events expected )");
    return 666;
    }
////
////    const auto record = this->expected.front();
    Record record = expected.front();
////    this->expected.pop_front();
    expected.pop_front();

////    if (record.type != T::EventTypeEnum)
    if(record.type != EventType_Analog)
    {
////        std::ostringstream oss;
////        oss << "Unexpected event type: " << static_cast<int>(record.type);
////        throw std::logic_error(oss.str());
    printf("std::logic_error( Unexpected event type:  )");
    return 667;
    }

////    if (record.variation != static_cast<uint8_t>(variation))
        if (record.variation != (uint8_t)(variation))
   {
////        std::ostringstream oss;
////        oss << "Unexpected variation: " << static_cast<int>(variation);
////        throw std::logic_error(oss.str());
    printf("std::logic_error( Unexpected variation:  )");
    return 668;
    }

////    EventWriterImpl<typename T::meas_t> writer;
//        EventWriterImpl_in_EventWriterImpl(&writer_for_Analog);
//        IEventWriter_for_Analog iIEventWriter_for_Analog;
//        iIEventWriter_for_Analog.pWrite_in_IEventWriter_for_Analog = Write_in_EventWriterImpl_for_Analog;
////    const uint16_t count = items.WriteSome(writer);
//  uint16_t (*pWriteSome_in_IEventCollection_for_Analog)(/*EventCollection_for_Analog*/void *pEventCollection_for_Analog, IEventWriter_for_Analog* handler);//// = 0;
//        uint16_t count = writer_for_Analog.iIEventWriter_for_Analog.pWriteSome_in_IEventCollection_for_Analog(items, &iIEventWriter_for_Analog);
        EventWriterImpl_in_EventWriterImpl(&writer_for_Analog);
        IEventWriter_for_Analog iIEventWriter_for_Analog;
        iIEventWriter_for_Analog.pWrite_in_IEventWriter_for_Analog = Write_in_EventWriterImpl_for_Analog;

////    const uint16_t count = items.WriteSome(writer);
//  uint16_t (*pWriteSome_in_IEventCollection_for_Analog)(/*EventCollection_for_Analog*/void *pEventCollection_for_Analog, IEventWriter_for_Analog* handler);//// = 0;
        uint16_t count = items->pWriteSome_in_IEventCollection_for_Analog(items, &iIEventWriter_for_Analog);

    if (record.count != count)
    {
////        std::ostringstream oss;
////        oss << "Unexpected count: " << static_cast<int>(variation);
////        throw std::logic_error(oss.str());
    printf("std::logic_error( Unexpected count:  )");
    return 669;
    }

    return count;
}//WriteAny_for_AnalogInfo_in_MockEventWriteHandler

  boolean Write_in_EventWriterImpl_for_Analog(Analog* meas, uint16_t index)
{
    if (writer_for_Analog.success)
    {
        writer_for_Analog.written_indices.push_back(index);
    }
    return writer_for_Analog.success;
}

////uint16_t MockEventWriteHandler::WriteAny(typename T::event_variation_t variation,
////                                         opendnp3::IEventCollection<typename T::meas_t>& items)
 EventWriterImpl writer_for_Binary;
 uint16_t   WriteAny_for_BinaryInfo_in_MockEventWriteHandler(EventBinaryVariation_uint8_t variation, IEventCollection_for_Binary* items)
{
////    if (this->expected.empty())
  if (expected.empty())
    {
////        throw std::logic_error("no more write events expected");
    printf("std::logic_error( no more events expected )");
    return 666;
    }
////
////    const auto record = this->expected.front();
    Record record = expected.front();
////    this->expected.pop_front();
    expected.pop_front();

////    if (record.type != T::EventTypeEnum)
    if(record.type != EventType_Binary)
    {
////        std::ostringstream oss;
////        oss << "Unexpected event type: " << static_cast<int>(record.type);
////        throw std::logic_error(oss.str());
    printf("std::logic_error( Unexpected event type:  )");
    return 667;
    }

////    if (record.variation != static_cast<uint8_t>(variation))
        if (record.variation != (uint8_t)(variation))
   {
////        std::ostringstream oss;
////        oss << "Unexpected variation: " << static_cast<int>(variation);
////        throw std::logic_error(oss.str());
    printf("std::logic_error( Unexpected variation:  )");
    return 668;
    }

////    EventWriterImpl<typename T::meas_t> writer;
//        EventWriterImpl_for_Binary writer;
        EventWriterImpl_in_EventWriterImpl(&writer_for_Binary);
        IEventWriter_for_Binary iIEventWriter_for_Binary;
        iIEventWriter_for_Binary.pWrite_in_IEventWriter_for_Binary = Write_in_EventWriterImpl_for_Binary;

////    const uint16_t count = items.WriteSome(writer);
//  uint16_t (*pWriteSome_in_IEventCollection_for_Binary)(/*EventCollection_for_Binary*/void *pEventCollection_for_Binary, IEventWriter_for_Binary* handler);//// = 0;
        uint16_t count = items->pWriteSome_in_IEventCollection_for_Binary(items, &iIEventWriter_for_Binary);

    if (record.count != count)
    {
////        std::ostringstream oss;
////        oss << "Unexpected count: " << static_cast<int>(variation);
////        throw std::logic_error(oss.str());
    printf("std::logic_error( Unexpected count:  )");
    return 669;
    }

    return count;
}//WriteAny_for_BinaryInfo_in_MockEventWriteHandler

  void EventWriterImpl_in_EventWriterImpl(EventWriterImpl* pEventWriterImpl)
{
   pEventWriterImpl->success = true;
}

  boolean Write_in_EventWriterImpl_for_Binary(Binary* meas, uint16_t index)
{
    if (writer_for_Binary.success)
    {
        writer_for_Binary.written_indices.push_back(index);
    }
    return writer_for_Binary.success;
}


int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);

  /*
  TEST_CASE(SUITE("calls write multiple times for different types"))
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
//    REQUIRE_FALSE(
//        storage.Update(Event<AnalogSpec>(Analog(1.0), 0, EventClass::EC1, EventAnalogVariation::Group32Var1)));

  EventStorage storage;
  qDebug()<<"sizeof(storage)="<<sizeof(storage);
// EventStorage storage;
  EventBufferConfig temp = AllTypes_in_EventBufferConfig_static(MAX_EventRecord);
  EventStorage_in_EventStorage(&storage, &temp);

  Analog aAnalog;
  Analog_in_AnalogOver2(&aAnalog, 1.0);
//   void Event_for_AnalogSpec_in_Event_for_AnalogSpecOver2(Event_for_AnalogSpec *pEvent_for_AnalogSpec,
//                                                  Analog* value, uint16_t index,
//                                                  EventClass_uint8_t clazz,
//                                                  event_variation_t_in_AnalogInfo variation);
  Event_for_AnalogSpec eEvent_for_AnalogSpec;
  Event_for_AnalogSpec_in_Event_for_AnalogSpecOver2(&eEvent_for_AnalogSpec,
      &aAnalog, 0,
      EventClass_EC1,
      EventAnalogVariation_Group32Var1);

//boolean Update_for_AnalogSpec_in_EventStorage(EventStorage *pEventStorage, Event_for_AnalogSpec* evt);
  boolean tempBool = Update_for_AnalogSpec_in_EventStorage(&storage, &eEvent_for_AnalogSpec);
  qDebug()<<"REQUIRE_FALSE(storage.Update(Event<AnalogSpec>(Analog(1.0), 0, EventClass::EC1, EventAnalogVariation::Group32Var1)))";
  qDebug()<<"tempBool= "<<tempBool;

//    REQUIRE_FALSE(
//        storage.Update(Event<BinarySpec>(Binary(true), 0, EventClass::EC1, EventBinaryVariation::Group2Var1)));

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

//    REQUIRE_FALSE(
//        storage.Update(Event<AnalogSpec>(Analog(1.0), 0, EventClass::EC1, EventAnalogVariation::Group32Var1)));

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
  tempBool = Update_for_AnalogSpec_in_EventStorage(&storage, &eEvent_for_AnalogSpec1);
  qDebug()<<"REQUIRE_FALSE(storage.Update(Event<AnalogSpec>(Analog(1.0), 0, EventClass::EC1, EventAnalogVariation::Group32Var1)))";
  qDebug()<<"tempBool= "<<tempBool;

  // select events by class
//    REQUIRE(storage.SelectByClass(EventClass::EC1) == 3);
//    uint32_t SelectByClass_in_EventStorageOver1(EventStorage *pEventStorage, EventClass_uint8_t clazz);
  uint32_t  tempUint32 = SelectByClass_in_EventStorageOver1(&storage, EventClass_EC1);
  qDebug()<<"REQUIRE(storage.SelectByClass(EventClass::EC1) == 3)";
  qDebug()<<"tempUint32= "<<tempUint32;

//  MockEventWriteHandler handler;
  IEventWriteHandler iIEventWriteHandler;

//     uint16_t (*pWrite_in_IEventWriteHandlerOver1)(EventBinaryVariation_uint8_t variation, Binary* first, IEventCollection_for_Binary* items);//// = 0;
//    uint16_t Write_in_MockEventWriteHandler(EventBinaryVariation_uint8_t variation, Binary* first, IEventCollection_for_Binary* items)
  iIEventWriteHandler.pWrite_in_IEventWriteHandlerOver1 = Write_for_BinaryInfo_in_MockEventWriteHandler;
  iIEventWriteHandler.pWrite_in_IEventWriteHandlerOver5 = Write_for_AnalogInfo_in_MockEventWriteHandler;

  ExpectType_for_AnalogInfo_in_MockEventWriteHandler(EventAnalogVariation_Group32Var1, 1);
  ExpectType_for_BinaryInfo_in_MockEventWriteHandler(EventBinaryVariation_Group2Var1, 1);
  ExpectType_for_AnalogInfo_in_MockEventWriteHandler(EventAnalogVariation_Group32Var1, 1);


//      REQUIRE(storage.Write(handler) == 3);
/*
  tempUint32 = Write_in_EventStorage(&storage, &iIEventWriteHandler);//IEventWriteHandler* handler);
  qDebug()<<"REQUIRE(storage.Write(handler) == 3)";
  qDebug()<<"tempUint32= "<<tempUint32;
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

