
#include <QApplication>
#include <QtWidgets>

#include <stdlib.h>
#include <iostream>
#include <string>

#include "MainWindow.h"
#include "key_filter.h"

#include "header.h"
#include "TransportTestObject.h"
#include "ProtocolUtil.h"

#define UNUSED(x) (void)(x)

key_filter *pkf;

MainWindow *mainWindow;

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);

qDebug()<<"********SUITE('15SendFullAPDU')********";
////    TransportTestObject test(true);
////    uint32_t numPackets = CalcMaxPackets(opendnp3::DEFAULT_MAX_APDU_SIZE, MAX_TPDU_PAYLOAD);
////    uint32_t lastPacketLength = CalcLastPacketSize(opendnp3::DEFAULT_MAX_APDU_SIZE, MAX_TPDU_PAYLOAD);
////    std::vector<std::string> packets;
////    std::string apdu = test.GeneratePacketSequence(packets, numPackets, lastPacketLength);
////    test.upper.SendDown(apdu);
    // 9 total packets
////    REQUIRE(numPackets == test.link.sends.size());
////    REQUIRE(packets.size() == test.link.sends.size());

////void TransportTestObject_in_TransportTestObject(TransportTestObject *pTransportTestObject, boolean openOnStart,/* = false,*/ uint32_t maxRxFragmentSize);// = opendnp3::DEFAULT_MAX_APDU_SIZE);
 TransportTestObject test;
 TransportTestObject_in_TransportTestObject(&test, true, DEFAULT_MAX_APDU_SIZE);

////    uint32_t num_packets = CalcMaxPackets(opendnp3::DEFAULT_MAX_APDU_SIZE, MAX_TPDU_PAYLOAD);
    uint32_t num_packets = CalcMaxPackets(DEFAULT_MAX_APDU_SIZE, MAX_TPDU_PAYLOAD);

////    uint32_t last_packet_length = CalcLastPacketSize(opendnp3::DEFAULT_MAX_APDU_SIZE, MAX_TPDU_PAYLOAD);
    uint32_t last_packet_length = CalcLastPacketSize(DEFAULT_MAX_APDU_SIZE, MAX_TPDU_PAYLOAD);

    std::vector<std::string> packets;
//std::string GeneratePacketSequence_in_TransportTestObject(TransportTestObject *pTransportTestObject, std::vector<std::string>&, uint32_t aNumPackets, uint32_t aLastPacketLength);
////    const auto apdu = test.GeneratePacketSequence(packets, num_packets, last_packet_length);
std::string apdu = GeneratePacketSequence_in_TransportTestObject(&test, packets, num_packets, last_packet_length);
  std::cout<<"apdu= "<<apdu<<std::endl;
/*
  std::cout<<"stmp.size()= "<<stmp.size()<<std::endl;
  std::cout<<"packets.size()= "<<packets.size()<<std::endl;
  std::cout<<std::endl;
  std::cout<<std::endl;
  std::cout<<"packets[0]= "<<packets[0]<<std::endl;
  std::cout<<"packets[1]= "<<packets[1]<<std::endl;
  std::cout<<"packets[2]= "<<packets[2]<<std::endl;
  std::cout<<"packets[3]= "<<packets[3]<<std::endl;
  std::cout<<"packets[4]= "<<packets[4]<<std::endl;
  std::cout<<"packets[5]= "<<packets[5]<<std::endl;
  std::cout<<"packets[6]= "<<packets[6]<<std::endl;
  std::cout<<"packets[7]= "<<packets[7]<<std::endl;
  std::cout<<"packets[8]= "<<packets[8]<<std::endl;
*/

////    test.upper.SendDown(apdu);
Addresses aAddresses;
Addresses_in_AddressesOver1(&aAddresses);
 boolean btmp = SendDown_in_MockUpperLayerOver1(&(test.upper), apdu, &aAddresses);//// = opendnp3::Addresses());
  std::cout<<"boolean btmp= "<<btmp<<std::endl;

    // 9 total packets
////    REQUIRE(numPackets == test.link.sends.size());
  qDebug()<<"REQUIRE(numPackets == test.link.sends.size())";
  std::cout<<"numPackets= "<<num_packets<<std::endl;
  std::cout<<"test.link.sends.size()= "<<test.link.sends.size()<<std::endl;

////    REQUIRE(packets.size() == test.link.sends.size());
  qDebug()<<"REQUIRE(packets.size() == test.link.sends.size())";
  std::cout<<"packets.size()= "<<packets.size()<<std::endl;
  std::cout<<"test.link.sends.size()= "<<test.link.sends.size()<<std::endl;

    for (auto& packet : packets)
    {
////        REQUIRE(packet == test.link.PopWriteAsHex());
   std::string stmp = PopWriteAsHex_in_MockLinkLayer(&test.link);
  qDebug()<<"REQUIRE(packet == test.link.PopWriteAsHex())";
  std::cout<<"stmp= "<<stmp<<std::endl;
  std::cout<<"packet= "<<packet<<std::endl;
    }
////    test.transport.OnTxReady();

/*
////    for (const auto& s : packets)
////    {
////        test.link.SendUp(s);
////    }
////    REQUIRE(test.upper.received.AsHex() == apdu); // check that the correct data was written

Addresses aAddresses;
Addresses_in_AddressesOver1(&aAddresses);
    for (auto& s : packets)
    {
////        test.link.SendUp(s);
   SendUp_in_MockLinkLayer(&(test.link), s, &aAddresses);// = opendnp3::Addresses())
//   SendUp_in_MockLinkLayer(&(test.link), packets[0], &aAddresses);// = opendnp3::Addresses())
//   SendUp_in_MockLinkLayer(&(test.link), packets[8], &aAddresses);// = opendnp3::Addresses())
    }

////    REQUIRE(test.upper.received.AsHex() == apdu); // check that the correct data was written
std::string stmp2 = AsHex_in_DataSink(&(test.upper.received), true);
  qDebug()<<"REQUIRE(test.upper.received.AsHex() == apdu)";
  std::cout<<"stmp= "<<stmp2<<std::endl;
*/
/*
TEST_CASE(SUITE("15SendFullAPDU"))
{
    TransportTestObject test(true);

    uint32_t numPackets = CalcMaxPackets(opendnp3::DEFAULT_MAX_APDU_SIZE, MAX_TPDU_PAYLOAD);
    uint32_t lastPacketLength = CalcLastPacketSize(opendnp3::DEFAULT_MAX_APDU_SIZE, MAX_TPDU_PAYLOAD);

    std::vector<std::string> packets;
    std::string apdu = test.GeneratePacketSequence(packets, numPackets, lastPacketLength);

    test.upper.SendDown(apdu);

    // 9 total packets
    REQUIRE(numPackets == test.link.sends.size());
    REQUIRE(packets.size() == test.link.sends.size());

    for (const auto& packet : packets)
    {
        REQUIRE(packet == test.link.PopWriteAsHex());
    }

    test.transport.OnTxReady();
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

