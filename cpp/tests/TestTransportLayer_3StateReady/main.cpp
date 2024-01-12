
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

qDebug()<<"********SUITE('3StateReady')********";
////    TransportTestObject test(true); // makes an implicit call to 'test.link.ThisLayerUp()'
//делает не€вный вызов
    // check that that the transport layer is correctly forwarding up/down
// провер€ем, что транспортный уровень правильно пересылает вверх/вниз
////    REQUIRE(test.upper.IsOnline());
////    test.transport.OnLowerLayerDown();
////    REQUIRE_FALSE(test.upper.IsOnline());
////    test.transport.OnLowerLayerUp();
////    REQUIRE(test.upper.IsOnline());
////    REQUIRE_FALSE(test.transport.OnLowerLayerUp());
////    REQUIRE_FALSE(test.transport.OnTxReady());

////void TransportTestObject_in_TransportTestObject(TransportTestObject *pTransportTestObject, boolean openOnStart,/* = false,*/ uint32_t maxRxFragmentSize);// = opendnp3::DEFAULT_MAX_APDU_SIZE);
 TransportTestObject test;
 TransportTestObject_in_TransportTestObject(&test, true, DEFAULT_MAX_APDU_SIZE);

//boolean IsOnline_in_MockUpperLayer(MockUpperLayer *pMockUpperLayer);
////    REQUIRE(test.upper.IsOnline());
Addresses aAddresses;
Addresses_in_AddressesOver1(&aAddresses);
boolean btmp = IsOnline_in_MockUpperLayer(&(test.upper));//// = opendnp3::Addresses());
  qDebug()<<"REQUIRE(test.upper.IsOnline())";
  std::cout<<"boolean btmp= "<<btmp<<std::endl;

//boolean OnLowerLayerDown_in_TransportLayer(TransportLayer *pTransportLayer);
////    test.transport.OnLowerLayerDown();
 OnLowerLayerDown_in_TransportLayer(&test.transport);

////    REQUIRE_FALSE(test.upper.IsOnline());
 btmp = IsOnline_in_MockUpperLayer(&(test.upper));//// = opendnp3::Addresses());
  qDebug()<<"REQUIRE_FALSE(test.upper.IsOnline())";
  std::cout<<"boolean btmp= "<<btmp<<std::endl;

////    test.transport.OnLowerLayerUp();
 OnLowerLayerUp_in_TransportLayer(&test.transport);

////    REQUIRE(test.upper.IsOnline());
 btmp = IsOnline_in_MockUpperLayer(&(test.upper));//// = opendnp3::Addresses());
  qDebug()<<"REQUIRE(test.upper.IsOnline())";
  std::cout<<"boolean btmp= "<<btmp<<std::endl;

////    REQUIRE_FALSE(test.transport.OnLowerLayerUp());
 btmp = OnLowerLayerUp_in_TransportLayer(&test.transport);
  qDebug()<<"REQUIRE_FALSE(test.transport.OnLowerLayerUp())";
  std::cout<<"boolean btmp= "<<btmp<<std::endl;

////    REQUIRE_FALSE(test.transport.OnTxReady());
 btmp = OnTxReady_in_TransportLayer(&test.transport);
  qDebug()<<"REQUIRE_FALSE(test.transport.OnTxReady())";
  std::cout<<"boolean btmp= "<<btmp<<std::endl;

/*
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
*/
/*
TEST_CASE(SUITE("3StateReady"))
{
    TransportTestObject test(true); // makes an implicit call to 'test.link.ThisLayerUp()'
//делает не€вный вызов

    // check that that the transport layer is correctly forwarding up/down
// провер€ем, что транспортный уровень правильно пересылает вверх/вниз
    REQUIRE(test.upper.IsOnline());
    test.transport.OnLowerLayerDown();
    REQUIRE_FALSE(test.upper.IsOnline());
    test.transport.OnLowerLayerUp();
    REQUIRE(test.upper.IsOnline());

    REQUIRE_FALSE(test.transport.OnLowerLayerUp());
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

