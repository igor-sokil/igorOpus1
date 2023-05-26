
#include <QApplication>
#include <QtWidgets>

#include <stdlib.h>

#include "MainWindow.h"
#include "key_filter.h"

#include "header.h"

#include "APDUHelpers.h"
#include "APDUHeader.h"
#include "SerializationTemplates.h"
#include "Group30.h"

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
TEST_CASE(SUITE("CountWriteIteratorAllowsCountOfZero"))
{
    APDUResponse response(APDUHelpers::Response());
    auto writer = response.GetWriter();

    writer.IterateOverCount<UInt16, Analog>(QualifierCode::UINT16_CNT, Group30Var1::Inst());

    REQUIRE("C0 81 00 00 1E 01 08 00 00" == HexConversions::to_hex(response.ToRSeq()));
}
*/

//    APDUResponse response(APDUHelpers::Response());
     APDUResponse response = Response_in_APDUHelpers_static(SIZE_in_APDUHelpers);
//    auto writer = response.GetWriter();
     HeaderWriter writer = GetWriter_in_APDUWrapper(&(response.aAPDUWrapper));

DNP3Serializer_for_Analog temp = Inst_in_Group30Var1_static();

     //CountWriteIterator_for_UInt16_Analog iterator = 
     IterateOverCount_for_UInt16_Analog_in_HeaderWriter(&writer,
                                                        QualifierCode_UINT16_CNT,
                                                        &temp
                                                        );

     RSeq_for_Uint16_t rseq = ToRSeq_in_APDUWrapper(&(response.aAPDUWrapper));
    qDebug()<<"REQUIRE('C0 81 00 00 1E 01 08 00 00' == HexConversions::to_hex(response.ToRSeq()))";
     qDebug()<<"rseq.buffer_[0]= "<<hex<<rseq.buffer_[0] <<hex<<rseq.buffer_[1] <<hex<<rseq.buffer_[2] <<hex<<rseq.buffer_[3]
                                  <<hex<<rseq.buffer_[4] <<hex<<rseq.buffer_[5] <<hex<<rseq.buffer_[6] <<hex<<rseq.buffer_[7]
                                  <<hex<<rseq.buffer_[8];
/*
DNP3Serializer_for_Counter temp = Inst_in_Group20Var6_static();

     RangeWriteIterator_for_UInt8_Counter iterator = IterateOverRange_for_UInt8_Counter_in_HeaderWriter(&writer,
                                                        QualifierCode_UINT8_START_STOP,
                                                        &temp,//Inst_in_Group1Var2_static(),
                                                        2
                                                        );
////    REQUIRE(!iterator.IsValid());
//   boolean IsValid_in_RangeWriteIterator_for_UInt8_Counter(RangeWriteIterator_for_UInt8_Counter *pRangeWriteIterator_for_UInt8_Counter);
      boolean flg = IsValid_in_RangeWriteIterator_for_UInt8_Counter(&iterator);
               qDebug()<<"REQUIRE(!iterator.IsValid())";
               qDebug()<<"boolean temp= "<<flg;

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

