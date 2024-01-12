
#include <QApplication>
#include <QtWidgets>

#include <stdlib.h>
#include <iostream>
#include <string>

#include "MainWindow.h"
#include "key_filter.h"

#include "header.h"
#include "TransportTestObject.h"

#define UNUSED(x) (void)(x)

key_filter *pkf;

MainWindow *mainWindow;

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);

qDebug()<<"********SUITE('2StateOffline')********";
////    TransportTestObject test;
////    REQUIRE_FALSE(test.upper.SendDown("00"));
////    REQUIRE_FALSE(test.link.SendUp(""));
////    REQUIRE_FALSE(test.transport.OnTxReady());
////    REQUIRE_FALSE(test.transport.OnLowerLayerDown());

////void TransportTestObject_in_TransportTestObject(TransportTestObject *pTransportTestObject, boolean openOnStart,/* = false,*/ uint32_t maxRxFragmentSize);// = opendnp3::DEFAULT_MAX_APDU_SIZE);
 TransportTestObject test;
 TransportTestObject_in_TransportTestObject(&test, false, DEFAULT_MAX_APDU_SIZE);

//boolean SendDown_in_MockUpperLayerOver1(MockUpperLayer *pMockUpperLayer, std::string& hex, Addresses* addresses);//// = opendnp3::Addresses());
////    REQUIRE_FALSE(test.upper.SendDown("00"));
std::string name = "00";
Addresses aAddresses;
Addresses_in_AddressesOver1(&aAddresses);
boolean btmp = SendDown_in_MockUpperLayerOver1(&(test.upper), name, &aAddresses);//// = opendnp3::Addresses());
  qDebug()<<"REQUIRE_FALSE(test.upper.SendDown('00'))";
  std::cout<<"boolean btmp= "<<btmp<<std::endl;

//   boolean SendUp_in_MockLinkLayer(MockLinkLayer *pMockLinkLayer, std::string& hex, Addresses* addresses);// = opendnp3::Addresses())
////    REQUIRE_FALSE(test.link.SendUp(""));
 name = "";
btmp = SendUp_in_MockLinkLayer(&(test.link), name, &aAddresses);// = opendnp3::Addresses())
  qDebug()<<"REQUIRE_FALSE(test.link.SendUp(''))";
  std::cout<<"boolean btmp= "<<btmp<<std::endl;

//boolean OnTxReady_in_TransportLayer(TransportLayer *pTransportLayer);
////    REQUIRE_FALSE(test.transport.OnTxReady());
btmp = OnTxReady_in_TransportLayer(&(test.transport));
  qDebug()<<"REQUIRE_FALSE(test.transport.OnTxReady())";
  std::cout<<"boolean btmp= "<<btmp<<std::endl;

////    REQUIRE_FALSE(test.transport.OnLowerLayerDown());
btmp = OnLowerLayerDown_in_TransportLayer(&(test.transport));
  qDebug()<<"REQUIRE_FALSE(test.transport.OnLowerLayerDown())";
  std::cout<<"boolean btmp= "<<btmp<<std::endl;

/*
////    TransportTx tx(log.logger);
 TransportTx tx;
 TransportTx_in_TransportTx(&tx);

////    HexSequence hs("12 34 56");
 std::string name = "12 34 56";
 HexSequence hs;
 HexSequence_in_HexSequence(&hs, name);

//void Configure_in_TransportTx(TransportTx *pTransportTx, Message* message);
////    tx.Configure(Message(Addresses(), hs.ToRSeq()));
RSeq_for_Uint16_t temp2 = ToRSeq_in_CopyableBuffer(&(hs.bByteStr.cCopyableBuffer));
Addresses aAddresses;
Addresses_in_AddressesOver1(&aAddresses);
Message mMessage;
Message_in_Message(&mMessage, &aAddresses, &temp2);
Configure_in_TransportTx(&tx, &mMessage);

//RSeq_for_Uint16_t GetSegment_in_TransportTx(TransportTx *pTransportTx);
////    auto segment1 = tx.GetSegment();
RSeq_for_Uint16_t segment1 = GetSegment_in_TransportTx(&tx);

////    REQUIRE("C0 12 34 56" == HexConversions::to_hex(segment1));
  std::string  str = to_hex_in_HexConversionsOver2(&segment1, true);
  std::cout<<"str= "<<str<<std::endl;
  qDebug()<<"REQUIRE('C0 12 34 56' == HexConversions::to_hex(segment1))";

//Tx_Transport* Statistics_in_TransportTx(TransportTx *pTransportTx);
////    REQUIRE(tx.Statistics().numTransportTx == 1);
  qDebug()<<"REQUIRE(tx.Statistics().numTransportTx == 1)";
Tx_Transport* tmp = Statistics_in_TransportTx(&tx);
  std::cout<<"tx.Statistics().numTransportTx= "<<(uint16_t)tmp->numTransportTx<<std::endl;

////    auto segment2 = tx.GetSegment();
////    REQUIRE("C0 12 34 56" == HexConversions::to_hex(segment2));
////    REQUIRE(tx.Statistics().numTransportTx == 1);

////    auto segment2 = tx.GetSegment();
RSeq_for_Uint16_t segment2 = GetSegment_in_TransportTx(&tx);

////    REQUIRE("C0 12 34 56" == HexConversions::to_hex(segment2));
  std::string  str2 = to_hex_in_HexConversionsOver2(&segment2, true);
  std::cout<<"str2= "<<str2<<std::endl;
  qDebug()<<"REQUIRE('C0 12 34 56' == HexConversions::to_hex(segment2))";

////    REQUIRE(tx.Statistics().numTransportTx == 1);
  qDebug()<<"REQUIRE(tx.Statistics().numTransportTx == 1)";
Tx_Transport* tmp2 = Statistics_in_TransportTx(&tx);
  std::cout<<"tx.Statistics().numTransportTx= "<<(uint16_t)tmp2->numTransportTx<<std::endl;
*/
/*
// make sure an invalid state exception gets thrown
// for every event other than LowerLayerUp() since
// the layer starts in the online state
// убедиться, что генерируется исключение недопустимого состояния
// для каждого события, кроме LowerLayerUp(), поскольку
// слой запускается в онлайн-состоянии
TEST_CASE(SUITE("2StateOffline"))
{
    TransportTestObject test;

    REQUIRE_FALSE(test.upper.SendDown("00"));
    REQUIRE_FALSE(test.link.SendUp(""));
    REQUIRE_FALSE(test.transport.OnTxReady());
    REQUIRE_FALSE(test.transport.OnLowerLayerDown());
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

