
#include <QApplication>
#include <QtWidgets>

#include <stdlib.h>

#include "MainWindow.h"
#include "key_filter.h"

#include "header.h"

#include "LinkParserTest.h"
//#include "OutstationTestObject.h"
#include "loghandler.h"

QString FormatUserData(
    boolean aIsMaster, boolean aIsConfirmed, int aDest, int aSrc, /*const std::string& data,*/uint8_t* data, uint16_t size_data, boolean aFcb);/// = false)

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

    LinkParserTest t;
  LinkParserTest_in_LinkParserTest(&t, false);// = false)

//void WriteData_in_LinkParserTestOver2(LinkParserTest *pLinkParserTest, uint8_t *hex, uint16_t size_hex);////const std::string& hex)
////    t.WriteData("05 64 05 64 05 C0 01 00 00 04 E9 21");
uint8_t hex[] = {0x05, 0x64, 0x05, 0x64, 0x05, 0xC0, 0x01, 0x00, 0x00, 0x04, 0xE9, 0x21};
 WriteData_in_LinkParserTestOver2(&t, hex, 12);////const std::string& hex)

qDebug()<<"REQUIRE(t.sink.m_num_frames == 1)";
qDebug()<<"t.sink.m_num_frames= "<<t.sink.m_num_frames;
qDebug()<<"";

qDebug()<<"REQUIRE(t.parser.Statistics().numHeaderCrcError == 1)";
Parser_in_LinkStatistics* temp = Statistics_in_LinkLayerParser(&t.parser);
qDebug()<<"t.parser.Statistics().numHeaderCrcError= "<<temp->numHeaderCrcError;
qDebug()<<"";

qDebug()<<"REQUIRE(t.sink.CheckLast(LinkFunction::PRI_RESET_LINK_STATES, true, 1, 1024))";
    boolean btest = CheckLast_in_MockFrameSink(&(t.sink), LinkFunction_PRI_RESET_LINK_STATES, true, 1, 1024);
qDebug()<<"t.sink.CheckLast(LinkFunction::PRI_RESET_LINK_STATES, true, 1, 1024)= "<<btest;
qDebug()<<"";

/*
// Test that the parser is able to resync without discarding
// Проверяем, может ли парсер выполнить повторную синхронизацию без отбрасывания
TEST_CASE(SUITE("Resync0564"))
{
    LinkParserTest t;
    t.WriteData("05 64 05 64 05 C0 01 00 00 04 E9 21");
    REQUIRE(t.parser.Statistics().numHeaderCrcError == 1);
    REQUIRE(t.sink.m_num_frames == 1);
    REQUIRE(t.sink.CheckLast(LinkFunction::PRI_RESET_LINK_STATES, true, 1, 1024));
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

