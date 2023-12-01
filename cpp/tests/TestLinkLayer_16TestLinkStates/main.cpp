
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

qDebug()<<"********SUITE('16TestLinkStates')********";
////    LinkLayerTest t;
////    t.link.OnLowerLayerUp();
////    t.OnFrame(LinkFunction::PRI_TEST_LINK_STATES, false, false, false, 1, 1024);
///    REQUIRE(t.NumTotalWrites() == 0);

//---------------1
////    LinkLayerTest t;
    LinkLayerTest t;
  LinkLayerConfig temp = DefaultConfig_in_LinkLayerTest(&t);
  LinkLayerTest_in_LinkLayerTest(&t, &temp);

////    t.link.OnLowerLayerUp();
   OnLowerLayerUp_in_LinkLayer(&(t.link));

////    t.OnFrame(LinkFunction::PRI_TEST_LINK_STATES, false, false, false, 1, 1024);
     RSeq_for_Uint16_t temp2 = empty_in_RSeq_for_Uint16_t_static();
     OnFrame_in_LinkLayerTest(&t,
                 LinkFunction_PRI_TEST_LINK_STATES,
                 false,
                 false,
                 false,
                 1,
                 1024,
                 &temp2);//// = ser4cpp::rseq_t::empty());

////    REQUIRE(t.NumTotalWrites() == 0);
uint32_t temp1 = NumTotalWrites_in_LinkLayerTest(&t);
qDebug()<<"REQUIRE(t.NumTotalWrites() == 0)";
qDebug()<<"temp1= "<<temp1;

//---------------2
////    t.OnFrame(LinkFunction::PRI_RESET_LINK_STATES, false, false, false, 1, 1024);
////    REQUIRE(t.NumTotalWrites() == 1);
////    t.link.OnTxReady();

////    t.OnFrame(LinkFunction::PRI_RESET_LINK_STATES, false, false, false, 1, 1024);
//     RSeq_for_Uint16_t temp2 = empty_in_RSeq_for_Uint16_t_static();
     OnFrame_in_LinkLayerTest(&t,
                 LinkFunction_PRI_RESET_LINK_STATES,
                 false,
                 false,
                 false,
                 1,
                 1024,
                 &temp2);//// = ser4cpp::rseq_t::empty());

////    REQUIRE(t.NumTotalWrites() == 1);
uint32_t temp3 = NumTotalWrites_in_LinkLayerTest(&t);
qDebug()<<"REQUIRE(t.NumTotalWrites() == 1)";
qDebug()<<"temp3= "<<temp3;

//   boolean OnTxReady_in_LinkLayer(LinkLayer *pLinkLayer);
////    t.link.OnTxReady();
   OnTxReady_in_LinkLayer(&(t.link));

//---------------3

////    t.OnFrame(LinkFunction::PRI_TEST_LINK_STATES, false, true, false, 1, 1024);
////    REQUIRE(t.NumTotalWrites() == 2);

////    t.OnFrame(LinkFunction::PRI_TEST_LINK_STATES, false, true, false, 1, 1024);
//     RSeq_for_Uint16_t temp2 = empty_in_RSeq_for_Uint16_t_static();
     OnFrame_in_LinkLayerTest(&t,
                 LinkFunction_PRI_TEST_LINK_STATES,
                 false,
                 true,
                 false,
                 1,
                 1024,
                 &temp2);//// = ser4cpp::rseq_t::empty());

////    REQUIRE(t.NumTotalWrites() == 2);
uint32_t temp4 = NumTotalWrites_in_LinkLayerTest(&t);
qDebug()<<"REQUIRE(t.NumTotalWrites() == 2)";
qDebug()<<"temp4= "<<temp4;

//---------------4
////    REQUIRE(t.PopLastWriteAsHex() == LinkHex::Ack(true, false, 1024, 1));

////    REQUIRE(t.PopLastWriteAsHex() == LinkHex::Ack(true, false, 1024, 1));
qDebug()<<"REQUIRE(t.PopLastWriteAsHex() == LinkHex::Ack(true, false, 1024, 1))";
std::string tmpStr = PopLastWriteAsHex_in_LinkLayerTest(&t);
std::cout<<"std::string tmpStr ="<<tmpStr;

//std::string Ack_in_LinkHex_static(boolean master, boolean isRxBuffFull, uint16_t dest, uint16_t src);
tmpStr = Ack_in_LinkHex_static(true, false, 1024, 1);
std::cout<<"std::string tmpStr ="<<tmpStr;


/*
TEST_CASE(SUITE("16TestLinkStates"))
{
    LinkLayerTest t;
    t.link.OnLowerLayerUp();
    t.OnFrame(LinkFunction::PRI_TEST_LINK_STATES, false, false, false, 1, 1024);
    REQUIRE(t.NumTotalWrites() == 0);

    t.OnFrame(LinkFunction::PRI_RESET_LINK_STATES, false, false, false, 1, 1024);
    REQUIRE(t.NumTotalWrites() == 1);
    t.link.OnTxReady();

    t.OnFrame(LinkFunction::PRI_TEST_LINK_STATES, false, true, false, 1, 1024);

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

