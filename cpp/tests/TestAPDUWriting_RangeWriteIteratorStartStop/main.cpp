
#include <QApplication>
#include <QtWidgets>

#include <stdlib.h>

#include "MainWindow.h"
#include "key_filter.h"

#include "header.h"

#include "APDUHelpers.h"
#include "APDUHeader.h"
#include "SerializationTemplates.h"
#include "Group20.h"

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
TEST_CASE(SUITE("RangeWriteIteratorStartStop"))
{
    APDUResponse response(APDUHelpers::Response());
    auto writer = response.GetWriter();

    {
        auto iterator
            = writer.IterateOverRange<UInt8, Counter>(QualifierCode::UINT8_START_STOP, Group20Var6::Inst(), 2);
        REQUIRE(iterator.Write(Counter(9)));
        REQUIRE(iterator.Write(Counter(7)));
    }

    REQUIRE("C0 81 00 00 14 06 00 02 03 09 00 07 00" == HexConversions::to_hex(response.ToRSeq()));
}
*/
//    APDUResponse response(APDUHelpers::Response());
     APDUResponse response = Response_in_APDUHelpers_static(SIZE_in_APDUHelpers);
//    auto writer = response.GetWriter();
     HeaderWriter writer = GetWriter_in_APDUWrapper(&(response.aAPDUWrapper));

DNP3Serializer_for_Counter temp = Inst_in_Group20Var6_static();

     RangeWriteIterator_for_UInt8_Counter iterator = IterateOverRange_for_UInt8_Counter_in_HeaderWriter(&writer,
                                                        QualifierCode_UINT8_START_STOP,
                                                        &temp,//Inst_in_Group1Var2_static(),
                                                        2
                                                        );
          Counter cCounter;
          Counter_in_CounterOver2(&cCounter, 9);
          boolean flg = Write_in_RangeWriteIterator_for_UInt8_Counter(&iterator, &cCounter);
               qDebug()<<"REQUIRE(iterator.Write(Counter(9)))";
               qDebug()<<"boolean flg= "<<flg;
          Counter_in_CounterOver2(&cCounter, 7);
                  flg = Write_in_RangeWriteIterator_for_UInt8_Counter(&iterator, &cCounter);
               qDebug()<<"REQUIRE(iterator.Write(Counter(7)))";
               qDebug()<<"boolean flg= "<<flg;

       RangeWriteIterator_for_UInt8_Counter_destr_RangeWriteIterator_for_UInt8_Counter(&iterator);//destructor

     RSeq_for_Uint16_t rseq = ToRSeq_in_APDUWrapper(&(response.aAPDUWrapper));
    qDebug()<<"REQUIRE('C0 81 00 00 14 06 00 02 03 09 00 07 00' == HexConversions::to_hex(response.ToRSeq()))";
     qDebug()<<"rseq.buffer_[0]= "<<hex<<rseq.buffer_[0] <<hex<<rseq.buffer_[1] <<hex<<rseq.buffer_[2] <<hex<<rseq.buffer_[3]
                                  <<hex<<rseq.buffer_[4] <<hex<<rseq.buffer_[5] <<hex<<rseq.buffer_[6] <<hex<<rseq.buffer_[7]
                                  <<hex<<rseq.buffer_[8] <<hex<<rseq.buffer_[9] <<hex<<rseq.buffer_[10]<<hex<<rseq.buffer_[11]
                                  <<hex<<rseq.buffer_[12];

/*
//    APDUResponse response(APDUHelpers::Response());
     APDUResponse response = Response_in_APDUHelpers_static(SIZE_in_APDUHelpers);
//    auto writer = response.GetWriter();
     HeaderWriter writer = GetWriter_in_APDUWrapper(&(response.aAPDUWrapper));

//    {
//        auto iterator = writer.IterateOverRange<UInt8, Binary>(QualifierCode::UINT8_START_STOP, Group1Var2::Inst(), 0);
//    RangeWriteIterator_for_UInt8_Binary IterateOverRange_for_UInt8_Binary_in_HeaderWriter(HeaderWriter *pHeaderWriter, 
//                                                   QualifierCode_uint8_t qc,
//                                                   DNP3Serializer_for_Binary *serializer,
//                                                   uint8_t start
//                                                  );
//  DNP3Serializer_for_Binary Inst_in_Group1Var2_static(void);
DNP3Serializer_for_Binary temp = Inst_in_Group1Var2_static();

     RangeWriteIterator_for_UInt8_Binary iterator = IterateOverRange_for_UInt8_Binary_in_HeaderWriter(&writer,
                                                        QualifierCode_UINT8_START_STOP,
                                                        &temp,//Inst_in_Group1Var2_static(),
                                                        0
                                                        );
//   void Binary_in_BinaryOver2(Binary *pBinary, boolean value);

          Binary bBinary;
          Binary_in_BinaryOver2(&bBinary, true);
        for (int i = 0; i < 256; ++i)
       {
////            REQUIRE(iterator.Write(Binary(true)));
//    boolean Write_in_RangeWriteIterator_for_UInt8_Binary(RangeWriteIterator_for_UInt8_Binary *pRangeWriteIterator_for_UInt8_Binary,
//                                                         Binary* value);
               boolean flg = Write_in_RangeWriteIterator_for_UInt8_Binary(&iterator, &bBinary);
               qDebug()<<"REQUIRE(iterator.Write(Binary(true)))";
               qDebug()<<"boolean flg= "<<flg;

        }

//        REQUIRE_FALSE(iterator.Write(Binary(true)));
               boolean flg1 = Write_in_RangeWriteIterator_for_UInt8_Binary(&iterator, &bBinary);
               qDebug()<<"REQUIRE_FALSE(iterator.Write(Binary(true)))";
               qDebug()<<"boolean flg1= "<<flg1;

//    void RangeWriteIterator_for_UInt8_Binary_destr_RangeWriteIterator_for_UInt8_Binary(RangeWriteIterator_for_UInt8_Binary *pRangeWriteIterator_for_UInt8_Binary);
       RangeWriteIterator_for_UInt8_Binary_destr_RangeWriteIterator_for_UInt8_Binary(&iterator);//destructor

     RSeq_for_Uint16_t rseq = ToRSeq_in_APDUWrapper(&(response.aAPDUWrapper));
    qDebug()<<"std::string beginsWith('C0 81 00 00 01 02 00 00 FF')";
     qDebug()<<"rseq.buffer_[0]= "<<hex<<rseq.buffer_[0] <<hex<<rseq.buffer_[1] <<hex<<rseq.buffer_[2] <<hex<<rseq.buffer_[3]
                                  <<hex<<rseq.buffer_[4] <<hex<<rseq.buffer_[5] <<hex<<rseq.buffer_[6] <<hex<<rseq.buffer_[7]
                                  <<hex<<rseq.buffer_[8];

     qDebug()<<"rseq.buffer_[0]= "<<hex<<rseq.buffer_[247] <<hex<<rseq.buffer_[248] <<hex<<rseq.buffer_[249] <<hex<<rseq.buffer_[250]
                                  <<hex<<rseq.buffer_[251] <<hex<<rseq.buffer_[252] <<hex<<rseq.buffer_[253] <<hex<<rseq.buffer_[254]
                                  <<hex<<rseq.buffer_[255];

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

