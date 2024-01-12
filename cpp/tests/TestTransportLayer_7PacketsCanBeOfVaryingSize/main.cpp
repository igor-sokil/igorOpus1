
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

qDebug()<<"********SUITE('7PacketsCanBeOfVaryingSize')********";
////    TransportTestObject test(true);
////    test.link.SendUp("40 0A 0B 0C"); // FIR/_/0
////    test.link.SendUp("81 0D 0E 0F"); // _/FIN/1
////    REQUIRE(test.upper.received.AsHex() == "0A 0B 0C 0D 0E 0F");

////void TransportTestObject_in_TransportTestObject(TransportTestObject *pTransportTestObject, boolean openOnStart,/* = false,*/ uint32_t maxRxFragmentSize);// = opendnp3::DEFAULT_MAX_APDU_SIZE);
 TransportTestObject test;
 TransportTestObject_in_TransportTestObject(&test, true, DEFAULT_MAX_APDU_SIZE);

//   boolean SendUp_in_MockLinkLayer(MockLinkLayer *pMockLinkLayer, std::string& hex, Addresses* addresses);// = opendnp3::Addresses())
////    test.link.SendUp("40 0A 0B 0C"); // FIR/_/0
Addresses aAddresses;
Addresses_in_AddressesOver1(&aAddresses);
//   std::string name1 = "40 0A 0B 0C";
//   SendUp_in_MockLinkLayer(&(test.link), name1, &aAddresses);// = opendnp3::Addresses())
   std::string name1 = "40";
   std::string stmp1 = GetData_in_TransportTestObject(&test, name1, 2, MAX_TPDU_PAYLOAD);
   SendUp_in_MockLinkLayer(&(test.link), stmp1, &aAddresses);// = opendnp3::Addresses())

   std::string name2 = "01 10 11 12 13 14 15 16 17 18 19 1A 1B 1C 1D 1E 1F 1F 1E 1D 1C 1B 1A19 18 17 16 15 14 13 12 11 10";
   std::string name21 =  " 10 11 12 13 14 15 16 17";// 18";// 19 1A 1B 1C 1D 1E 1F 1F 1E 1D 1C 1B 1A19 18 17 16 15 14 13 12 11 10";
   std::string nameres = name2+name21;
   SendUp_in_MockLinkLayer(&(test.link), nameres, &aAddresses);// = opendnp3::Addresses())
/*
   std::string name2 = "01";
   std::string stmp2 = GetData_in_TransportTestObject(&test, name2, 5, MAX_TPDU_PAYLOAD);
   SendUp_in_MockLinkLayer(&(test.link), stmp2, &aAddresses);// = opendnp3::Addresses())
*/

////    test.link.SendUp("81 0D 0E 0F"); // _/FIN/1
   std::string name3 = "82 2D 2E 2F 2A";
   SendUp_in_MockLinkLayer(&(test.link), name3, &aAddresses);// = opendnp3::Addresses())

////    REQUIRE(test.upper.received.AsHex() == "0A 0B 0C 0D 0E 0F");
std::string stmp = AsHex_in_DataSink(&(test.upper.received), true);
  qDebug()<<"REQUIRE(test.upper.received.AsHex() == '0A 0B 0C 0D 0E 0F')";
  std::cout<<"stmp= "<<stmp<<std::endl;

/*
TEST_CASE(SUITE("7PacketsCanBeOfVaryingSize"))
{
    TransportTestObject test(true);
    test.link.SendUp("40 0A 0B 0C"); // FIR/_/0
    test.link.SendUp("81 0D 0E 0F"); // _/FIN/1
    REQUIRE(test.upper.received.AsHex() == "0A 0B 0C 0D 0E 0F");
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

