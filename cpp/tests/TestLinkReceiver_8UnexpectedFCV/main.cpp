
#include <QApplication>
#include <QtWidgets>

#include <stdlib.h>
#include <iostream>
#include <string>

#include "MainWindow.h"
#include "key_filter.h"

#include "header.h"

#include "LinkParserTest.h"
#include "DNPHelpers.h"

#define UNUSED(x) (void)(x)


key_filter *pkf;

MainWindow *mainWindow;

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);

qDebug()<<"********SUITE('8UnexpectedFCV')********";
////    LinkParserTest t;
///    t.WriteData(RepairCRC("05 64 05 D0 01 00 00 04 E9 21"));
////    REQUIRE(t.sink.m_num_frames == 0);
////    REQUIRE(t.parser.Statistics().numBadFCV == 1);

    LinkParserTest t;
  LinkParserTest_in_LinkParserTest(&t, false);// = false)

//void WriteData_in_LinkParserTestOver2(LinkParserTest *pLinkParserTest, uint8_t *hex, uint16_t size_hex);////const std::string& hex)
////    t.WriteData(RepairCRC("05 64 01 C0 01 00 00 04 E9 21"));
// uint8_t hex[] = {0x05, 0x64, 0x01, 0xC0, 0x01, 0x00, 0x00, 0x04, 0xE9, 0x21};
/*
std::string hex = "05 64 05 D0 01 00 00 04 E9 21";
std::string sss = RepairCRC_in_DNPHelpers(hex);
std::cout<<"sss= "<<sss;
*/
///*
//sss= 05 64 05 D0 01 00 00 04 7B 8B
uint8_t sss[] = {0x05, 0x64, 0x05, 0xD0, 0x01, 0x00, 0x00, 0x04, 0x7B, 0x8B};


 WriteData_in_LinkParserTestOver2(&t, sss, 10);////const std::string& hex)

qDebug()<<"REQUIRE(t.sink.m_num_frames == 0)";
qDebug()<<"t.sink.m_num_frames= "<<t.sink.m_num_frames;

qDebug()<<"REQUIRE(t.parser.Statistics().numBadFCV == 1)";
Parser_in_LinkStatistics* temp = Statistics_in_LinkLayerParser(&t.parser);

qDebug()<<"t.parser.Statistics().numBadFCV= "<<temp->numBadFCV;
//*/
/*
// Test that the parser can handle an unexpected FCV bit
// Reset Links w/ FCV toggled on
// Проверяем, что синтаксический анализатор может обработать неожиданный бит FCV
// Сброс ссылок с включенным FCV
TEST_CASE(SUITE("8UnexpectedFCV"))
{
    LinkParserTest t;
    t.WriteData(RepairCRC("05 64 05 D0 01 00 00 04 E9 21"));
    REQUIRE(t.sink.m_num_frames == 0);
    REQUIRE(t.parser.Statistics().numBadFCV == 1);
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

