
#include <QApplication>
#include <QtWidgets>

#include <stdlib.h>

#include "MainWindow.h"
#include "key_filter.h"

#include "header.h"

#include "APDUHeaderParser.h"
#include "APDUHeader.h"
#include "SerializationTemplates.h"

DWORD get_fattime (void);

#define UNUSED(x) (void)(x)

key_filter *pkf;

MainWindow *mainWindow;

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);


/*
TEST_CASE(SUITE("HeaderParsesResponse"))
{
    HexSequence buffer("C0 02 01 02 BE EF");
    const auto result = APDUHeaderParser::ParseResponse(buffer.ToRSeq());
    REQUIRE(result.success);
    REQUIRE(result.header.control.ToByte() == AppControlField(true, true, false, false, 0).ToByte());
    REQUIRE(result.header.function == FunctionCode::WRITE);
    REQUIRE(result.header.IIN == IINField(01, 02));
    REQUIRE("BE EF" == HexConversions::to_hex(result.objects));
}
*/
    uint8_t bufferR8[10];
    RSeq_for_Uint16_t rseq8;
    RSeq_for_Uint16_t_in_RSeq_for_Uint16_tOver2(&rseq8, bufferR8, 6);
bufferR8[0] = 0xC0;
bufferR8[1] = 0x02;
bufferR8[2] = 0x01;
bufferR8[3] = 0x02;
bufferR8[4] = 0xBE;
bufferR8[5] = 0xEF;

    Result_for_APDUResponseHeader_in_APDUHeaderParser result = ParseResponse_in_APDUHeaderParser_static(&rseq8);
qDebug()<<"REQUIRE(result.success)";
qDebug()<<"result.success= "<<result.success;
qDebug()<<"";
qDebug()<<"REQUIRE(result.header.control.ToByte() == AppControlField(true, true, false, false, 0).ToByte())";
qDebug()<<"result.header.control.FIR= "<<result.header.aAPDUHeader.control.FIR;
qDebug()<<"result.header.control.FIN= "<<result.header.aAPDUHeader.control.FIN;
qDebug()<<"result.header.control.CON= "<<result.header.aAPDUHeader.control.CON;
qDebug()<<"result.header.control.UNS= "<<result.header.aAPDUHeader.control.UNS;
qDebug()<<"result.header.control.SEQ= "<<result.header.aAPDUHeader.control.SEQ;
qDebug()<<"";

qDebug()<<"REQUIRE(result.header.function == FunctionCode::WRITE)";
qDebug()<<"result.header.function= "<<result.header.aAPDUHeader.function;
qDebug()<<"";
qDebug()<<"REQUIRE(result.header.IIN == IINField(01, 02))";
         IINField iIINField;
         IINField_in_IINFieldOver3(&iIINField, 1, 2);
qDebug()<<"result.header.IIN.LSB= "<<result.header.IIN.LSB;
qDebug()<<"result.header.IIN.MSB= "<<result.header.IIN.MSB;
qDebug()<<"iIINField.LSB= "<<iIINField.LSB;
qDebug()<<"iIINField.MSB= "<<iIINField.MSB;
qDebug()<<"";
qDebug()<<"REQUIRE('BE EF' == HexConversions::to_hex(result.objects))";
qDebug()<<"result.objects.buffer_[0]= "<<hex<<result.objects.buffer_[0];
qDebug()<<"result.objects.buffer_[1]= "<<hex<<result.objects.buffer_[1];

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

