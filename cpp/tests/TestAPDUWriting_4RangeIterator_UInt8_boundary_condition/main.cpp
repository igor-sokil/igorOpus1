
#include <QApplication>
#include <QtWidgets>

#include <stdlib.h>
#include <iostream>
#include <string>

#include "MainWindow.h"
#include "key_filter.h"

#include "header.h"

#include "APDUHelpers.h"
#include "APDUHeader.h"
//#include "SerializationTemplates.h"
#include "RangeWriteIterator_for_Binary.h"
#include "HeaderWriter_for_Binary.h"
#include "Group1.h"

#include "HexConversions.h"

DWORD get_fattime (void);

#define UNUSED(x) (void)(x)

key_filter *pkf;

MainWindow *mainWindow;

void* pPointerGlobal1;
void* pPointerGlobal2;
void* pPointerGlobal3;

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);


  /*
  TEST_CASE(SUITE("RangeIterator UInt8 boundary condition"))
  {
      APDUResponse response(APDUHelpers::Response());
      auto writer = response.GetWriter();

      {
          auto iterator = writer.IterateOverRange<UInt8, Binary>(QualifierCode::UINT8_START_STOP, Group1Var2::Inst(), 0);

          for (int i = 0; i < 256; ++i)
          {
              REQUIRE(iterator.Write(Binary(true)));
          }

          REQUIRE_FALSE(iterator.Write(Binary(true)));
      }

      std::string beginsWith("C0 81 00 00 01 02 00 00 FF");
      auto truncated = HexConversions::to_hex(response.ToRSeq()).substr(0, beginsWith.size());

      REQUIRE(beginsWith == truncated);
  }
  */
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

  RangeWriteIterator_for_UInt8_Binary iter = IterateOverRange_for_UInt8_Binary_in_HeaderWriter(&writer,
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
    boolean flg = Write_in_RangeWriteIterator_for_UInt8_Binary(&iter, &bBinary);
    qDebug()<<"REQUIRE(iterator.Write(Binary(true)))";
    qDebug()<<"boolean flg= "<<flg;

  }

//        REQUIRE_FALSE(iterator.Write(Binary(true)));
  boolean flg1 = Write_in_RangeWriteIterator_for_UInt8_Binary(&iter, &bBinary);
  qDebug()<<"REQUIRE_FALSE(iterator.Write(Binary(true)))";
  qDebug()<<"boolean flg1= "<<flg1;

//    void RangeWriteIterator_for_UInt8_Binary_destr_RangeWriteIterator_for_UInt8_Binary(RangeWriteIterator_for_UInt8_Binary *pRangeWriteIterator_for_UInt8_Binary);
  RangeWriteIterator_for_UInt8_Binary_destr_RangeWriteIterator_for_UInt8_Binary(&iter);//destructor

  RSeq_for_Uint16_t rseq = ToRSeq_in_APDUWrapper(&(response.aAPDUWrapper));
  std::string  str = to_hex_in_HexConversionsOver2(&rseq, true);
  std::cout<<"str= "<<str<<std::endl;
  qDebug()<<"std::string beginsWith('C0 81 00 00 01 02 00 00 FF')";

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

