
#include <QApplication>
#include <QtWidgets>

#include <stdlib.h>
#include <iostream>

#include "MainWindow.h"
#include "key_filter.h"

#include "header.h"

#include "LinkHex.h"
#include "LinkLayerTest.h"
#include "HexConversions.h"
#include "MockTransportSegment.h"

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

qDebug()<<"********SUITE('8UnconfirmedBroadcastDataPassedUpFromIdleUnreset')********";
    LinkLayerTest t;
  LinkLayerConfig temp = DefaultConfig_in_LinkLayerTest(&t);
  LinkLayerTest_in_LinkLayerTest(&t, &temp);

////    t.link.OnLowerLayerUp();
   OnLowerLayerUp_in_LinkLayer(&(t.link));

//void ByteStr_in_ByteStrOver1(ByteStr *pByteStr, uint16_t length, uint8_t seed);// = 0);
////    ByteStr bs(250, 0);
 ByteStr bs;
 ByteStr_in_ByteStrOver1(&bs, 250, 0);// = 0);

//  boolean OnFrame_in_LinkLayerTest(LinkLayerTest *pLinkLayerTest,
//                 LinkFunction_uint8_t func,
//                 boolean isMaster,
//                 boolean fcb,
//                 boolean fcvdfc,
//                 uint16_t dest,
//                 uint16_t source,
//                 RSeq_for_Uint16_t* userdata);//// = ser4cpp::rseq_t::empty());
////    t.OnFrame(LinkFunction::SEC_ACK, false, false, false, 2, 1024);

//     RSeq_for_Uint16_t temp2 = empty_in_RSeq_for_Uint16_t_static();
//RSeq_for_Uint16_t ToRSeq_in_CopyableBuffer(CopyableBuffer *pCopyableBuffer);
////bs.ToRSeq()
RSeq_for_Uint16_t temp2 = ToRSeq_in_CopyableBuffer(&(bs.cCopyableBuffer));

     OnFrame_in_LinkLayerTest(&t,
                 LinkFunction_PRI_UNCONFIRMED_USER_DATA,
                 false,
                 false,
                 false,
                 LinkBroadcastAddress_ShallConfirm,
                 1024,
                 &temp2);//// = ser4cpp::rseq_t::empty());

////    REQUIRE(t.upper->receivedQueue.size() == 1);
  uint16_t tmp16 =  t.upper.receivedQueue.size();// == 1);
qDebug()<<"REQUIRE(t.upper->receivedQueue.size() == 1)";
qDebug()<<"uint16_t tmp16 = "<<tmp16;

qDebug()<<"REQUIRE(t.upper->receivedQueue.front()";
 std::string tmpStr = t.upper.receivedQueue.front();
std::cout<<"std::string tmpStr ="<<tmpStr;

qDebug()<<"";
qDebug()<<"";
//std::string ToHex_in_ByteStr(ByteStr *pByteStr);
tmpStr = ToHex_in_ByteStr(&bs);
std::cout<<"std::string tmpStr ="<<tmpStr;
/*
// Show that the base state of idle forwards unconfirmed user data with broadcast address
// Показать, что базовое состояние простоя пересылает неподтвержденные пользовательские данные с широковещательным адресом
TEST_CASE(SUITE("8UnconfirmedBroadcastDataPassedUpFromIdleUnreset"))
{
    LinkLayerTest t;
    t.link.OnLowerLayerUp();
    ByteStr bs(250, 0);
    t.OnFrame(LinkFunction::PRI_UNCONFIRMED_USER_DATA, false, false, false, LinkBroadcastAddress::ShallConfirm, 1024,
              bs.ToRSeq());
    REQUIRE(t.upper->receivedQueue.size() == 1);
    REQUIRE(t.upper->receivedQueue.front() == bs.ToHex());
}
*/
/*
    LinkLayerTest t;
  LinkLayerConfig temp = DefaultConfig_in_LinkLayerTest(&t);
  LinkLayerTest_in_LinkLayerTest(&t, &temp);

////    t.link.OnLowerLayerUp();
   OnLowerLayerUp_in_LinkLayer(&(t.link));

//void ByteStr_in_ByteStrOver1(ByteStr *pByteStr, uint16_t length, uint8_t seed);// = 0);
////    ByteStr bs(250, 0);
 ByteStr bs;
 ByteStr_in_ByteStrOver1(&bs, 250, 0);// = 0);

//  boolean OnFrame_in_LinkLayerTest(LinkLayerTest *pLinkLayerTest,
//                 LinkFunction_uint8_t func,
//                 boolean isMaster,
//                 boolean fcb,
//                 boolean fcvdfc,
//                 uint16_t dest,
//                 uint16_t source,
//                 RSeq_for_Uint16_t* userdata);//// = ser4cpp::rseq_t::empty());
////    t.OnFrame(LinkFunction::SEC_ACK, false, false, false, 2, 1024);

//     RSeq_for_Uint16_t temp2 = empty_in_RSeq_for_Uint16_t_static();
//RSeq_for_Uint16_t ToRSeq_in_CopyableBuffer(CopyableBuffer *pCopyableBuffer);
////bs.ToRSeq()
RSeq_for_Uint16_t temp2 = ToRSeq_in_CopyableBuffer(&(bs.cCopyableBuffer));

     OnFrame_in_LinkLayerTest(&t,
                 LinkFunction_PRI_UNCONFIRMED_USER_DATA,
                 false,
                 false,
                 false,
                 1,
                 1024,
                 &temp2);//// = ser4cpp::rseq_t::empty());

////    REQUIRE(t.upper->receivedQueue.size() == 1);
  uint16_t tmp16 =  t.upper.receivedQueue.size();// == 1);
qDebug()<<"REQUIRE(t.upper->receivedQueue.size() == 1)";
qDebug()<<"uint16_t tmp16 = "<<tmp16;

qDebug()<<"REQUIRE(t.upper->receivedQueue.front()";
 std::string tmpStr = t.upper.receivedQueue.front();
std::cout<<"std::string tmpStr ="<<tmpStr;

qDebug()<<"";
qDebug()<<"";
//std::string ToHex_in_ByteStr(ByteStr *pByteStr);
tmpStr = ToHex_in_ByteStr(&bs);
std::cout<<"std::string tmpStr ="<<tmpStr;
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

