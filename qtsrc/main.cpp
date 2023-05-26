
#include <QApplication>
#include <QtWidgets>

#include <stdlib.h>

#include "MainWindow.h"
#include "key_filter.h"

#include "header.h"

#include "AnalogOutput.h"
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


//AnalogOutputInt16 analogOutputInt16;
//AnalogOutputInt16_in_AnalogOutputInt16Over1(&analogOutputInt16);//constructor
//analogOutputInt16.analogOutput_templateInt16.pValuesEqual_In_AnalogOutput_templateInt16(&analogOutputInt16, 0);

APDUHeader header;
header.function = 22;
qDebug()<<"header.function= "<<header.function;
qDebug()<<"&header= "<<(&header);
APDUHeader *pAPDUHeader = &header;
qDebug()<<"pAPDUHeader->function"<< pAPDUHeader->function;

APDUHeader_in_APDUHeaderOver1(&header);

qDebug()<<"header.function= "<<header.function;

//----------------uint8----------------------------------
    uint8_t bufferR8[10];
    RSeq_for_Uint16_t rseq8;
    RSeq_for_Uint16_t_in_RSeq_for_Uint16_tOver2(&rseq8, bufferR8, 1);
bufferR8[0] = 12;
bufferR8[1] = 13;
uint8_t outR8 = 25;
    boolean resR8 = read_from_in_UInt8_static(&rseq8, &outR8);
qDebug()<<"resR8="<<resR8;
qDebug()<<"outR8="<<outR8;

    uint8_t bufferW8[10];
    WSeq_for_Uint16_t wseq8;
    WSeq_for_Uint16_t_in_WSeq_for_Uint16_tOver2(&wseq8, bufferW8, 1);
bufferW8[0] = 12;
bufferW8[1] = 13;
    boolean resW8 = write_to_in_UInt8_static(&wseq8, 55);
qDebug()<<"resW8="<<resW8;
qDebug()<<"bufferW8[0]="<<bufferW8[0];
qDebug()<<"bufferW8[1]="<<bufferW8[1];

    resW8 = write_to_in_UInt8_static(&wseq8, 56);
qDebug()<<"resW8="<<resW8;
qDebug()<<"bufferW8[0]="<<bufferW8[0];
qDebug()<<"bufferW8[1]="<<bufferW8[1];
//----------------uint8----------------------------------
//----------------uint16----------------------------------
    uint8_t bufferR16[10];
    RSeq_for_Uint16_t rseq16;
    RSeq_for_Uint16_t_in_RSeq_for_Uint16_tOver2(&rseq16, bufferR16, 2);
bufferR16[0] = 12;
bufferR16[1] = 1;
uint16_t outR16 = 25;
    boolean resR16 = read_from_in_UInt16_static(&rseq16, &outR16);
qDebug()<<"resR16="<<resR16;
qDebug()<<"outR16="<<outR16;

    uint8_t bufferW16[10];
    WSeq_for_Uint16_t wseq16;
    WSeq_for_Uint16_t_in_WSeq_for_Uint16_tOver2(&wseq16, bufferW16, 2);
bufferW16[0] = 12;
bufferW16[1] = 1;
    boolean resW16 = write_to_in_UInt16_static(&wseq16, 555);
qDebug()<<"resW16="<<resW16;
qDebug()<<"bufferW16[0]="<<bufferW16[0];
qDebug()<<"bufferW16[1]="<<bufferW16[1];
//----------------uint16----------------------------------
//----------------uint32----------------------------------
    uint8_t bufferR32[10];
    RSeq_for_Uint16_t rseq32;
    RSeq_for_Uint16_t_in_RSeq_for_Uint16_tOver2(&rseq32, bufferR32, 4);
bufferR32[0] = 12;
bufferR32[1] = 1;
bufferR32[2] = 2;
bufferR32[3] = 3;
uint32_t outR32 = 250;
    boolean resR32 = read_from_in_UInt32_static(&rseq32, &outR32);
qDebug()<<"resR32="<<resR32;
qDebug()<<"outR32="<<outR32;

    uint8_t bufferW32[10];
    WSeq_for_Uint16_t wseq32;
    WSeq_for_Uint16_t_in_WSeq_for_Uint16_tOver2(&wseq32, bufferW32, 4);
bufferW32[0] = 12;
bufferW32[1] = 1;
bufferR32[2] = 2;
bufferR32[3] = 3;
    boolean resW32 = write_to_in_UInt32_static(&wseq32, 77777);
qDebug()<<"resW32="<<resW32;
qDebug()<<"bufferW32[0]="<<bufferW32[0];
qDebug()<<"bufferW32[1]="<<bufferW32[1];
qDebug()<<"bufferW32[2]="<<bufferW32[2];
qDebug()<<"bufferW32[3]="<<bufferW32[3];
//----------------uint16----------------------------------

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

