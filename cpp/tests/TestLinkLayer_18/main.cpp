
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

#define UNUSED(x) (void)(x)

key_filter *pkf;

MainWindow *mainWindow;

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);

qDebug()<<"********SUITE('18SendUnconfirmed')********";
////    LinkLayerTest t;
////    t.link.OnLowerLayerUp();
////    MockTransportSegment segment(250, HexConversions::increment_hex(0, 250), Addresses());
////    t.link.Send(segment);
////    REQUIRE(t.NumTotalWrites() == 1);
////    t.link.OnTxReady();

////    LinkLayerTest t;
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
// std::cout << "hex = " << hex;

   Addresses aAddresses;
   Addresses_in_AddressesOver1(&aAddresses);
   MockTransportSegment segments;
   MockTransportSegment_in_MockTransportSegment(&segments, SIZE_CopyableBuffer_in_TestLinkLayer_CloseBehavior, hex, &aAddresses);

//   boolean Send_in_LinkLayer(LinkLayer *pLinkLayer, ITransportSegment* segments);
////    t.link.Send(segments);
   Send_in_LinkLayer(&(t.link), &(segments.iITransportSegment));

////    REQUIRE(t.NumTotalWrites() == 1);
uint32_t temp1 = NumTotalWrites_in_LinkLayerTest(&t);
qDebug()<<"REQUIRE(t.NumTotalWrites() == 1)";
qDebug()<<"temp1= "<<temp1;

//   boolean OnTxReady_in_LinkLayer(LinkLayer *pLinkLayer);
////    t.link.OnTxReady();
   OnTxReady_in_LinkLayer(&(t.link));

////    REQUIRE(t.exe->run_many() > 0);
////    REQUIRE(t.upper->GetCounters().numTxReady == 1);
////    REQUIRE(t.NumTotalWrites() == 1);

////    REQUIRE(t.exe->run_many() > 0);
uint16_t tmp = run_many_in_MockExecutor(&(t.exe), 100);
qDebug()<<"REQUIRE(t.exe->run_many() > 0)";
qDebug()<<"tmp= "<<tmp;

////    REQUIRE(t.upper->GetCounters().numTxReady == 1);
Counters_in_MockTransportLayer cnttemp = GetCounters_in_MockTransportLayer(&(t.upper));
qDebug()<<"REQUIRE(t.upper->GetCounters().numTxReady == 1)";
qDebug()<<"cnttemp.numTxReady= "<<(uint16_t)cnttemp.numTxReady;

////    REQUIRE(t.NumTotalWrites() == 1);
uint32_t num = NumTotalWrites_in_LinkLayerTest(&t);

qDebug()<<"REQUIRE(t.NumTotalWrites() == 1)";
qDebug()<<"num= "<<num;

/*
TEST_CASE(SUITE("18SendUnconfirmed"))
{
    LinkLayerTest t;
    t.link.OnLowerLayerUp();

    MockTransportSegment segment(250, HexConversions::increment_hex(0, 250), Addresses());
    t.link.Send(segment);
    REQUIRE(t.NumTotalWrites() == 1);
    t.link.OnTxReady();

    REQUIRE(t.exe->run_many() > 0);

    REQUIRE(t.upper->GetCounters().numTxReady == 1);
    REQUIRE(t.NumTotalWrites() == 1);
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

