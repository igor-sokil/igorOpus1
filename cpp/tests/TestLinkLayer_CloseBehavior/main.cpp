
#include <QApplication>
#include <QtWidgets>

#include <stdlib.h>
#include <string.h>

#include <iostream>

#include "MainWindow.h"
#include "key_filter.h"

#include "header.h"

#include "LinkHex.h"
#include "LinkLayerTest.h"
#include "HexConversions.h"
#include "MockTransportSegment.h"
//#include "OutstationTestObject.h"
#include "loghandler.h"
//QString FormatUserData(
//    boolean aIsMaster, boolean aIsConfirmed, int aDest, int aSrc, /*const std::string& data,*/uint8_t* data, uint16_t size_data, boolean aFcb);/// = false)

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

qDebug()<<"********SUITE('CloseBehavior')********";
    LinkLayerTest t;
  LinkLayerConfig temp = DefaultConfig_in_LinkLayerTest(&t);
  LinkLayerTest_in_LinkLayerTest(&t, &temp);

////    t.link.OnLowerLayerUp();
   OnLowerLayerUp_in_LinkLayer(&(t.link));

//  void Addresses_in_AddressesOver1(Addresses *pAddresses);
//    std::string increment_hex_in_HexConversions(uint8_t start, uint16_t count, bool spaced = true);
//  void MockTransportSegment_in_MockTransportSegment(MockTransportSegment *pMockTransportSegment, uint16_t segmentSize, std::string& hex, Addresses* addresses);
////    MockTransportSegment segments(250, HexConversions::increment_hex(0, 250), Addresses());
    std::string hex = increment_hex_in_HexConversions(0, SIZE_CopyableBuffer_in_TestLinkLayer_CloseBehavior, true);
 std::cout << "hex = " << hex;

   Addresses aAddresses;
   Addresses_in_AddressesOver1(&aAddresses);
   MockTransportSegment segments;
   MockTransportSegment_in_MockTransportSegment(&segments, SIZE_CopyableBuffer_in_TestLinkLayer_CloseBehavior, hex, &aAddresses);

//   boolean Send_in_LinkLayer(LinkLayer *pLinkLayer, ITransportSegment* segments);
////    t.link.Send(segments);
   Send_in_LinkLayer(&(t.link), &(segments.iITransportSegment));

//   boolean OnTxReady_in_LinkLayer(LinkLayer *pLinkLayer);
////    t.link.OnTxReady();
   OnTxReady_in_LinkLayer(&(t.link));

//uint16_t run_many_in_MockExecutor(MockExecutor *pMockExecutor, uint16_t maximum=100);
////    REQUIRE(t.exe->run_many() > 0);
uint16_t tmp = run_many_in_MockExecutor(&(t.exe), 100);
qDebug()<<"tmp= "<<tmp;

//   boolean OnLowerLayerDown_in_LinkLayer(LinkLayer *pLinkLayer);
////    t.link.OnLowerLayerDown(); // снять его в середине отправки take it down during the middle of a send
    OnLowerLayerDown_in_LinkLayer(&(t.link));

//    boolean IsOnline_in_MockTransportLayer(MockTransportLayer *pMockTransportLayer);
////    REQUIRE_FALSE(t.upper->IsOnline());
    boolean tt = IsOnline_in_MockTransportLayer(&(t.upper));
qDebug()<<"tt= "<<tt;

////    t.link.OnLowerLayerUp();
   OnLowerLayerUp_in_LinkLayer(&(t.link));

////    REQUIRE(t.upper->IsOnline());
    tt = IsOnline_in_MockTransportLayer(&(t.upper));
qDebug()<<"tt= "<<tt;

//  void Reset_in_MockTransportSegment(MockTransportSegment *pMockTransportSegment);
////    segments.Reset();
   Reset_in_MockTransportSegment(&segments);

//   boolean Send_in_LinkLayer(LinkLayer *pLinkLayer, ITransportSegment* segments);
////    t.link.Send(segments);
   Send_in_LinkLayer(&(t.link), &(segments.iITransportSegment));

////    REQUIRE(t.NumTotalWrites() == 2);
//uint32_t NumTotalWrites_in_LinkLayerTest(LinkLayerTest *pLinkLayerTest)
////    REQUIRE(t.NumTotalWrites() == 2);
uint32_t num = NumTotalWrites_in_LinkLayerTest(&t);

qDebug()<<"REQUIRE(t.NumTotalWrites() == 2)";
qDebug()<<"num= "<<num;

/*
TEST_CASE(SUITE("CloseBehavior"))
{
    LinkLayerTest t;
    t.link.OnLowerLayerUp();

    MockTransportSegment segments(250, HexConversions::increment_hex(0, 250), Addresses());
    t.link.Send(segments);
    t.link.OnTxReady();

    REQUIRE(t.exe->run_many() > 0);

    t.link.OnLowerLayerDown(); // снять его в середине отправки take it down during the middle of a send
    REQUIRE_FALSE(t.upper->IsOnline());

    t.link.OnLowerLayerUp();
    REQUIRE(t.upper->IsOnline());
    segments.Reset();
    t.link.Send(segments);
    REQUIRE(t.NumTotalWrites() == 2);
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

