#include <QApplication>
#include <QtWidgets>

#include <stdlib.h>
#include <iostream>

#include "MainWindow.h"
#include "key_filter.h"

#include "header.h"

#include "BufferSer4.h"
#include "LinkFrame.h"

#include "RSeq.h"
#include "WSeq.h"
#include "HexConversions.h"

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

qDebug()<<"********SUITE('4ACK')********";
    BufferSer4 buffer;
    BufferSer4_in_BufferSer4Over2(&buffer, MAX_BufferSer4);
{
        // ACK - Outstation (DFC = false)
////        auto writeTo = buffer.as_wslice();
    WSeq_for_Uint16_t writeTo = as_wslice_in_BufferSer4(&buffer);

//RSeq_for_Uint16_t FormatAck_in_LinkFrame_static(
//  WSeq_for_Uint16_t* buffer, boolean aIsMaster, boolean aIsRcvBuffFull, uint16_t aDest, uint16_t aSrc);//, Logger* pLogger);
////        auto wrapper = LinkFrame::FormatAck(writeTo, false, false, 1024, 1, nullptr);
////        REQUIRE(HexConversions::to_hex(wrapper) == "05 64 05 00 00 04 01 00 19 A6"); // ACK - Outstation
RSeq_for_Uint16_t wrapper = FormatAck_in_LinkFrame_static(
  &writeTo, false, false, 1024, 1);//, Logger* pLogger);

  std::cout<<"REQUIRE(HexConversions::to_hex(wrapper) == '05 64 05 00 00 04 01 00 19 A6'); // ACK - Outstation"<<std::endl;
  std::string  str = to_hex_in_HexConversionsOver2(&wrapper, true);
  std::cout<<"str= "<<str<<std::endl;
}
{
        // ACK - Outstation (DFC = true)
////        auto writeTo = buffer.as_wslice();
    WSeq_for_Uint16_t writeTo = as_wslice_in_BufferSer4(&buffer);

//RSeq_for_Uint16_t FormatAck_in_LinkFrame_static(
//  WSeq_for_Uint16_t* buffer, boolean aIsMaster, boolean aIsRcvBuffFull, uint16_t aDest, uint16_t aSrc);//, Logger* pLogger);
////        auto wrapper = LinkFrame::FormatAck(writeTo, false, true, 1024, 1, nullptr);
////        REQUIRE(HexConversions::to_hex(wrapper) == "05 64 05 10 00 04 01 00 8B 0C"); // ACK - Outstation (with DFC set)
RSeq_for_Uint16_t wrapper = FormatAck_in_LinkFrame_static(
  &writeTo, false, true, 1024, 1);//, Logger* pLogger);

  std::cout<<"REQUIRE(HexConversions::to_hex(wrapper) == '05 64 05 10 00 04 01 00 8B 0C'); // ACK - Outstation (with DFC set)"<<std::endl;
  std::string  str = to_hex_in_HexConversionsOver2(&wrapper, true);
  std::cout<<"str= "<<str<<std::endl;
}
{
        // ACK - Master (DFC = false)
////        auto writeTo = buffer.as_wslice();
    WSeq_for_Uint16_t writeTo = as_wslice_in_BufferSer4(&buffer);

//RSeq_for_Uint16_t FormatAck_in_LinkFrame_static(
//  WSeq_for_Uint16_t* buffer, boolean aIsMaster, boolean aIsRcvBuffFull, uint16_t aDest, uint16_t aSrc);//, Logger* pLogger);
////        auto wrapper = LinkFrame::FormatAck(writeTo, true, false, 1, 1024, nullptr);
////        REQUIRE(HexConversions::to_hex(wrapper) == "05 64 05 80 01 00 00 04 53 11");
RSeq_for_Uint16_t wrapper = FormatAck_in_LinkFrame_static(
  &writeTo, true, false, 1, 1024);//, Logger* pLogger);

  std::cout<<"REQUIRE(HexConversions::to_hex(wrapper) == '05 64 05 80 01 00 00 04 53 11')"<<std::endl;
  std::string  str = to_hex_in_HexConversionsOver2(&wrapper, true);
  std::cout<<"str= "<<str<<std::endl;
}
{
        // ACK - Master (DFC = true)
////        auto writeTo = buffer.as_wslice();
    WSeq_for_Uint16_t writeTo = as_wslice_in_BufferSer4(&buffer);

//RSeq_for_Uint16_t FormatAck_in_LinkFrame_static(
//  WSeq_for_Uint16_t* buffer, boolean aIsMaster, boolean aIsRcvBuffFull, uint16_t aDest, uint16_t aSrc);//, Logger* pLogger);
////        auto wrapper = LinkFrame::FormatAck(writeTo, true, true, 1, 1024, nullptr);
////        REQUIRE(HexConversions::to_hex(wrapper) == "05 64 05 90 01 00 00 04 C1 BB");
RSeq_for_Uint16_t wrapper = FormatAck_in_LinkFrame_static(
  &writeTo, true, true, 1, 1024);//, Logger* pLogger);

  std::cout<<"REQUIRE(HexConversions::to_hex(wrapper) == '05 64 05 90 01 00 00 04 C1 BB')"<<std::endl;
  std::string  str = to_hex_in_HexConversionsOver2(&wrapper, true);
  std::cout<<"str= "<<str<<std::endl;
}

  /*
TEST_CASE(SUITE("4ACK"))
{
    Buffer buffer(292);

    {
        // ACK - Outstation (DFC = false)
        auto writeTo = buffer.as_wslice();
        auto wrapper = LinkFrame::FormatAck(writeTo, false, false, 1024, 1, nullptr);
        REQUIRE(HexConversions::to_hex(wrapper) == "05 64 05 00 00 04 01 00 19 A6"); // ACK - Outstation
    }

    {
        // ACK - Outstation (DFC = true)
        auto writeTo = buffer.as_wslice();
        auto wrapper = LinkFrame::FormatAck(writeTo, false, true, 1024, 1, nullptr);
        REQUIRE(HexConversions::to_hex(wrapper) == "05 64 05 10 00 04 01 00 8B 0C"); // ACK - Outstation (with DFC set)
    }

    {
        // ACK - Master (DFC = false)
        auto writeTo = buffer.as_wslice();
        auto wrapper = LinkFrame::FormatAck(writeTo, true, false, 1, 1024, nullptr);
        REQUIRE(HexConversions::to_hex(wrapper) == "05 64 05 80 01 00 00 04 53 11");
    }

    {
        // ACK - Master (DFC = true)
        auto writeTo = buffer.as_wslice();
        auto wrapper = LinkFrame::FormatAck(writeTo, true, true, 1, 1024, nullptr);
        REQUIRE(HexConversions::to_hex(wrapper) == "05 64 05 90 01 00 00 04 C1 BB");
    }
}
  */

/*
//выбранные события отбрасываются при переполнении
////    EventStorage storage(EventBufferConfig::AllTypes(1));
 EventStorage storage;
//   EventBufferConfig AllTypes_in_EventBufferConfig_static(uint16_t sizes);
   EventBufferConfig temp = AllTypes_in_EventBufferConfig_static(MAX_EventRecord);
 EventStorage_in_EventStorage(&storage, &temp);

////    REQUIRE_FALSE(
////        storage.Update(Event<AnalogSpec>(Analog(1.0), 0, EventClass::EC1, EventAnalogVariation::Group32Var1)));
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
boolean tempBool = Update_AnalogSpec_in_EventStorage(&storage, &eEvent_for_AnalogSpec);
  qDebug()<<"REQUIRE_FALSE(storage.Update(Event<AnalogSpec>(Analog(1.0), 0, EventClass::EC1, EventAnalogVariation::Group32Var1)))";
  qDebug()<<"tempBool= "<<tempBool;

    // select events by class
////    REQUIRE(storage.SelectByClass(EventClass::EC1) == 1);
  uint32_t  tempUint32 = SelectByClass_in_EventStorageOver1(&storage, EventClass_EC1);
  qDebug()<<"REQUIRE(storage.SelectByClass(EventClass::EC1) == 1)";
  qDebug()<<"tempUint32= "<<tempUint32;

////    REQUIRE_FALSE(
////        storage.Update(Event<AnalogSpec>(Analog(1.0), 0, EventClass::EC1, EventAnalogVariation::Group32Var1)));
  Analog aAnalog2;
  Analog_in_AnalogOver2(&aAnalog2, 1.0);
//   void Event_for_AnalogSpec_in_Event_for_AnalogSpecOver2(Event_for_AnalogSpec *pEvent_for_AnalogSpec,
//                                                  Analog* value, uint16_t index,
//                                                  EventClass_uint8_t clazz,
//                                                  event_variation_t_in_AnalogInfo variation);
  Event_for_AnalogSpec eEvent_for_AnalogSpec2;
  Event_for_AnalogSpec_in_Event_for_AnalogSpecOver2(&eEvent_for_AnalogSpec2,
                                                  &aAnalog2, 0,
                                                  EventClass_EC1,
                                                  EventAnalogVariation_Group32Var1);

//boolean Update_for_AnalogSpec_in_EventStorage(EventStorage *pEventStorage, Event_for_AnalogSpec* evt);
 tempBool = Update_AnalogSpec_in_EventStorage(&storage, &eEvent_for_AnalogSpec2);
  qDebug()<<"REQUIRE(storage.Update(Event<AnalogSpec>(Analog(1.0), 0, EventClass::EC1, EventAnalogVariation::Group32Var1)))";
  qDebug()<<"tempBool= "<<tempBool;

////    MockEventWriteHandler handler;
    MockEventWriteHandler handler;
    MockEventWriteHandler_in_MockEventWriteHandler(&handler);

////    REQUIRE(storage.Write(handler) == 0);
uint32_t sss = Write_in_EventStorage(&storage, &(handler.iIEventWriteHandler));
//  qDebug()<<"Write_in_EventStorage(&storage, &(handler.iIEventWriteHandler))";
  qDebug()<<"REQUIRE(storage.Write(handler) == 0)";
  qDebug()<<"uint32_t sss ="<<sss;
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
