
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
//#include "OutstationTestObject.h"
//#include "loghandler.h"
//QString FormatUserData(
//    boolean aIsMaster, boolean aIsConfirmed, int aDest, int aSrc, /*const std::string& data,*/uint8_t* data, uint16_t size_data, boolean aFcb);/// = false)

#define UNUSED(x) (void)(x)

key_filter *pkf;

MainWindow *mainWindow;

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);

qDebug()<<"********SUITE('12SecondaryResetResetLinkStates')********";

    LinkLayerTest t;
  LinkLayerConfig temp = DefaultConfig_in_LinkLayerTest(&t);
  LinkLayerTest_in_LinkLayerTest(&t, &temp);

////    t.link.OnLowerLayerUp();
   OnLowerLayerUp_in_LinkLayer(&(t.link));

//  boolean OnFrame_in_LinkLayerTest(LinkLayerTest *pLinkLayerTest,
//                 LinkFunction_uint8_t func,
//                 boolean isMaster,
//                 boolean fcb,
//                 boolean fcvdfc,
//                 uint16_t dest,
//                 uint16_t source,
//                 RSeq_for_Uint16_t* userdata);//// = ser4cpp::rseq_t::empty());

////    t.OnFrame(LinkFunction::PRI_RESET_LINK_STATES, false, false, false, 1, 1024);

     RSeq_for_Uint16_t temp2 = empty_in_RSeq_for_Uint16_t_static();
////    t.OnFrame(LinkFunction::PRI_RESET_LINK_STATES, false, false, false, 1, 1024);
   OnFrame_in_LinkLayerTest(&t,
                 LinkFunction_PRI_RESET_LINK_STATES,
                 false,//boolean isMaster,
                 false,//boolean fcb,
                 false,//boolean fcvdfc,
                 1,//uint16_t dest,
                 1024,//uint16_t source,
                 &temp2);//RSeq_for_Uint16_t* userdata);//// = ser4cpp::rseq_t::empty());

//uint32_t NumTotalWrites_in_LinkLayerTest(LinkLayerTest *pLinkLayerTest)
////    REQUIRE(t.NumTotalWrites() == 1);
uint32_t num = NumTotalWrites_in_LinkLayerTest(&t);

qDebug()<<"REQUIRE(t.NumTotalWrites() == 1)";
qDebug()<<"num= "<<num;

//   boolean OnTxReady_in_LinkLayer(LinkLayer *pLinkLayer);
////    t.link.OnTxReady();
   OnTxReady_in_LinkLayer(&(t.link));

////    t.OnFrame(LinkFunction::PRI_RESET_LINK_STATES, false, false, false, 1, 1024);
   OnFrame_in_LinkLayerTest(&t,
                 LinkFunction_PRI_RESET_LINK_STATES,
                 false,//boolean isMaster,
                 false,//boolean fcb,
                 false,//boolean fcvdfc,
                 1,//uint16_t dest,
                 1024,//uint16_t source,
                 &temp2);//RSeq_for_Uint16_t* userdata);//// = ser4cpp::rseq_t::empty());

////    REQUIRE(t.NumTotalWrites() == 2);
 num = NumTotalWrites_in_LinkLayerTest(&t);

qDebug()<<"REQUIRE(t.NumTotalWrites() == 2)";
qDebug()<<"num= "<<num;

////    t.link.OnTxReady();
   OnTxReady_in_LinkLayer(&(t.link));

////    REQUIRE(t.NumTotalWrites() == 2);
 num = NumTotalWrites_in_LinkLayerTest(&t);

qDebug()<<"REQUIRE(t.NumTotalWrites() == 2)";
qDebug()<<"num= "<<num;

////    REQUIRE(t.PopLastWriteAsHex() == LinkHex::Ack(true, false, 1024, 1));
    std::string str = PopLastWriteAsHex_in_LinkLayerTest(&t);

//   std::string Ack_in_LinkHex_static(boolean master, boolean isRxBuffFull, uint16_t dest, uint16_t src);
qDebug()<<"REQUIRE(t.PopLastWriteAsHex() == LinkHex::Ack(true, false, 1024, 1))";
//qDebug()<<"str= "<< str;
//printf("str %s", str);
 std::cout << "str = " << str;

qDebug()<<"";

   std::string str2 = Ack_in_LinkHex_static(true, false, 1024, 1);
 std::cout << "str2= " << str2;

/*
// When we get another reset links when we're already reset,
// ACK it and reset the link state
// ����� �� ������� ��� ���� ������ ������, ����� �� ��� ����������,
// ������������ ��� � ���������� ��������� ������
TEST_CASE(SUITE("SecondaryResetResetLinkStates"))
{
    LinkLayerTest t;
    t.link.OnLowerLayerUp();
    t.OnFrame(LinkFunction::PRI_RESET_LINK_STATES, false, false, false, 1, 1024);
    REQUIRE(t.NumTotalWrites() == 1);
    t.link.OnTxReady();

    t.OnFrame(LinkFunction::PRI_RESET_LINK_STATES, false, false, false, 1, 1024);
    REQUIRE(t.NumTotalWrites() == 2);
    t.link.OnTxReady();

    REQUIRE(t.NumTotalWrites() == 2);
    REQUIRE(t.PopLastWriteAsHex() == LinkHex::Ack(true, false, 1024, 1));
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

