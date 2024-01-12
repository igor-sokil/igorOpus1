
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

qDebug()<<"********SUITE('12StateSending')********";
////    TransportTestObject test(true);
    // this puts the layer into the Sending state
// это переводит слой в состо€ние отправки
////    REQUIRE(test.upper.SendDown("11"));
////    REQUIRE("C0 11" == test.link.PopWriteAsHex()); // FIR/FIN SEQ=0

////void TransportTestObject_in_TransportTestObject(TransportTestObject *pTransportTestObject, boolean openOnStart,/* = false,*/ uint32_t maxRxFragmentSize);// = opendnp3::DEFAULT_MAX_APDU_SIZE);
 TransportTestObject test;
 TransportTestObject_in_TransportTestObject(&test, true, DEFAULT_MAX_APDU_SIZE);

////    REQUIRE(test.upper.SendDown("11"));
std::string name = "11";
Addresses aAddresses;
Addresses_in_AddressesOver1(&aAddresses);
boolean btmp = SendDown_in_MockUpperLayerOver1(&(test.upper), name, &aAddresses);//// = opendnp3::Addresses());
  qDebug()<<"REQUIRE(test.upper.SendDown('11')";
  std::cout<<"boolean btmp= "<<btmp<<std::endl;

//   std::string PopWriteAsHex_in_MockLinkLayer(MockLinkLayer *pMockLinkLayer);
////    REQUIRE("C0 11" == test.link.PopWriteAsHex()); // FIR/FIN SEQ=0
   std::string stmp = PopWriteAsHex_in_MockLinkLayer(&test.link);
  qDebug()<<"REQUIRE('C0 11' == test.link.PopWriteAsHex())";
  std::cout<<"stmp= "<<stmp<<std::endl;

    // Check that while we're sending, all other send requests are rejected
// ѕровер€ем, что во врем€ отправки все остальные запросы на отправку отклон€ютс€
////    REQUIRE_FALSE(test.upper.SendDown("00"));
////    REQUIRE_FALSE(test.transport.OnLowerLayerUp());

////    REQUIRE_FALSE(test.upper.SendDown("00"));
 btmp = SendDown_in_MockUpperLayerOver1(&(test.upper), name, &aAddresses);//// = opendnp3::Addresses());
  qDebug()<<"REQUIRE_FALSE(test.upper.SendDown('00'))";
  std::cout<<"boolean btmp= "<<btmp<<std::endl;

//boolean OnLowerLayerUp_in_TransportLayer(TransportLayer *pTransportLayer);
////    REQUIRE_FALSE(test.transport.OnLowerLayerUp());
 btmp = OnLowerLayerUp_in_TransportLayer(&(test.transport));
  qDebug()<<"REQUIRE_FALSE(test.transport.OnLowerLayerUp())";
  std::cout<<"boolean btmp= "<<btmp<<std::endl;

    // while we are sending, we should still be able to receive data as normal
// пока мы отправл€ем, мы все равно должны иметь возможность получать данные в обычном режиме
////    test.link.SendUp("C0 77");
////    REQUIRE(test.upper.received.AsHex() == "77");

////    test.link.SendUp("C0 77");
   std::string name1 = "C0 77";
   SendUp_in_MockLinkLayer(&(test.link), name1, &aAddresses);// = opendnp3::Addresses())

////    REQUIRE(test.upper.received.AsHex() == "77");
 stmp = AsHex_in_DataSink(&(test.upper.received), true);
  qDebug()<<"REQUIRE(test.upper.received.AsHex() == '77')";
  std::cout<<"stmp= "<<stmp<<std::endl;

    // this should put us back in the Ready state since it was a single tpdu send
// это должно вернуть нас в состо€ние готовности, поскольку это была одна отправка tpdu
////    test.transport.OnTxReady();
////    REQUIRE(test.upper.GetCounters().numTxReady == 1);
////    REQUIRE_FALSE(test.transport.OnTxReady());

//boolean OnTxReady_in_TransportLayer(TransportLayer *pTransportLayer);
////    test.transport.OnTxReady();
  btmp = OnTxReady_in_TransportLayer(&(test.transport));
  std::cout<<"boolean btmp= "<<btmp<<std::endl;

//Counters_in_MockUpperLayer GetCounters_in_MockUpperLayer(MockUpperLayer *pMockUpperLayer);
////    REQUIRE(test.upper.GetCounters().numTxReady == 1);
Counters_in_MockUpperLayer ctmp = GetCounters_in_MockUpperLayer(&(test.upper));
  qDebug()<<"REQUIRE(test.upper.GetCounters().numTxReady == 1)";
  std::cout<<"ctmp.numTxReady= "<<ctmp.numTxReady<<std::endl;

////    REQUIRE_FALSE(test.transport.OnTxReady());
  btmp = OnTxReady_in_TransportLayer(&(test.transport));
  qDebug()<<"REQUIRE_FALSE(test.transport.OnTxReady())";
  std::cout<<"boolean btmp= "<<btmp<<std::endl;

/*
//   boolean SendUp_in_MockLinkLayer(MockLinkLayer *pMockLinkLayer, std::string& hex, Addresses* addresses);// = opendnp3::Addresses())
////    test.link.SendUp(test.GetData("40")); // FIR/_/0
Addresses aAddresses;
Addresses_in_AddressesOver1(&aAddresses);
   std::string name1 = "40";
   std::string stmp1 = GetData_in_TransportTestObject(&test, name1, 0, MAX_TPDU_PAYLOAD);
   SendUp_in_MockLinkLayer(&(test.link), stmp1, &aAddresses);// = opendnp3::Addresses())

//boolean IsEmpty_in_DataSink(DataSink *pDataSink);
////    REQUIRE(test.upper.received.IsEmpty());
  qDebug()<<"REQUIRE(test.upper.received.IsEmpty())";
  std::cout<<"stmp= "<<IsEmpty_in_DataSink(&(test.upper.received))<<std::endl;

////    test.link.SendUp("C0 AB CD"); // FIR/FIN/0
////    REQUIRE(test.upper.received.AsHex() == "AB CD");
////    REQUIRE(test.transport.GetStatistics().rx.numTransportDiscard == 1);

////    test.link.SendUp("C0 AB CD"); // FIR/FIN/0
   std::string name2 = "C0 AB CD";
   SendUp_in_MockLinkLayer(&(test.link), name2, &aAddresses);// = opendnp3::Addresses())

////    REQUIRE(test.upper.received.AsHex() == "AB CD");
std::string stmp = AsHex_in_DataSink(&(test.upper.received), true);
  qDebug()<<"REQUIRE(test.upper.received.AsHex() == 'AB CD')";
  std::cout<<"stmp= "<<stmp<<std::endl;

////    REQUIRE(test.transport.GetStatistics().rx.numTransportDiscard == 1);
Transport_StackStatistics ttmp = GetStatistics_in_TransportLayer(&(test.transport));
Rx_Transport stats = ttmp.rx;

  qDebug()<<"REQUIRE(test.transport.GetStatistics().rx.numTransportDiscard == 1)";
  std::cout<<"stats.numTransportDiscard= "<<stats.numTransportDiscard<<std::endl;
*/
/*
TEST_CASE(SUITE("12StateSending"))
{
    TransportTestObject test(true);

    // this puts the layer into the Sending state
// это переводит слой в состо€ние отправки
    REQUIRE(test.upper.SendDown("11"));
    REQUIRE("C0 11" == test.link.PopWriteAsHex()); // FIR/FIN SEQ=0

    // Check that while we're sending, all other send requests are rejected
// ѕровер€ем, что во врем€ отправки все остальные запросы на отправку отклон€ютс€
    REQUIRE_FALSE(test.upper.SendDown("00"));

    REQUIRE_FALSE(test.transport.OnLowerLayerUp());

    // while we are sending, we should still be able to receive data as normal
// пока мы отправл€ем, мы все равно должны иметь возможность получать данные в обычном режиме
    test.link.SendUp("C0 77");
    REQUIRE(test.upper.received.AsHex() == "77");

    // this should put us back in the Ready state since it was a single tpdu send
// это должно вернуть нас в состо€ние готовности, поскольку это была одна отправка tpdu
    test.transport.OnTxReady();
    REQUIRE(test.upper.GetCounters().numTxReady == 1);

    REQUIRE_FALSE(test.transport.OnTxReady());
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

