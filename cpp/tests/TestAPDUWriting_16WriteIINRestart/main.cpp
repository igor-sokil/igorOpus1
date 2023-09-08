
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
#include "HeaderWriter_for_Binary.h"

#include "Group1.h"

#include "HexConversions.h"

#define UNUSED(x) (void)(x)

void* pPointerGlobal1;
void* pPointerGlobal2;
void* pPointerGlobal3;

key_filter *pkf;

MainWindow *mainWindow;

extern uint8_t fixedBuffer_in_APDUHelpers[SIZE_in_APDUHelpers];

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);

qDebug()<<"********SUITE('16WriteIINRestart')********";

////    APDURequest request(APDUHelpers::Request(FunctionCode::WRITE));
     APDURequest request = 
                Request_in_APDUHelpers_static(FunctionCode_WRITE, SIZE_in_APDUHelpers);

//  HeaderWriter GetWriter_in_APDUWrapper(APDUWrapper *pAPDUWrapper);
////    auto writer = request.GetWriter();
     HeaderWriter writer = GetWriter_in_APDUWrapper(&(request.aAPDUWrapper));

//BitfieldRangeWriteIterator_for_UInt8 IterateOverSingleBitfield_for_UInt8_in_HeaderWriter(HeaderWriter *pHeaderWriter,
//    GroupVariationID id,
//    QualifierCode_uint8_t qc,
//    uint8_t start);
//void GroupVariationID_in_GroupVariationIDOver2(GroupVariationID *pGroupVariationID, uint8_t aGroup, uint8_t aVariation);
////        auto iter
////            = writer.IterateOverSingleBitfield<UInt8>(GroupVariationID(80, 1), QualifierCode::UINT8_START_STOP, 7);
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 80, 1);

BitfieldRangeWriteIterator_for_UInt8 iter = IterateOverSingleBitfield_for_UInt8_in_HeaderWriter(&writer,
    gGroupVariationID,
    QualifierCode_UINT8_START_STOP,
    7);

//boolean Write_in_BitfieldRangeWriteIterator_for_UInt8(BitfieldRangeWriteIterator_for_UInt8 *pBitfieldRangeWriteIterator_for_UInt8, boolean value);
////        iter.Write(true);
////        iter.Write(true);
 Write_in_BitfieldRangeWriteIterator_for_UInt8(&iter, true);

 Write_in_BitfieldRangeWriteIterator_for_UInt8(&iter, true);

//void BitfieldRangeWriteIterator_for_UInt8_destr_BitfieldRangeWriteIterator_for_UInt8(BitfieldRangeWriteIterator_for_UInt8 *pBitfieldRangeWriteIterator_for_UInt8);
 BitfieldRangeWriteIterator_for_UInt8_destr_BitfieldRangeWriteIterator_for_UInt8(&iter);

//std::string to_hex_in_HexConversionsOver2(RSeq_for_Uint16_t* buffer, bool spaced = true);
//RSeq_for_Uint16_t ToRSeq_in_APDUWrapper(APDUWrapper *pAPDUWrapper);
////    REQUIRE("C0 02 50 01 00 07 08 03" == HexConversions::to_hex(request.ToRSeq()));
RSeq_for_Uint16_t rseq = ToRSeq_in_APDUWrapper(&(request.aAPDUWrapper));
std::string  str = to_hex_in_HexConversionsOver2(&rseq, true);
std::cout<<"str= "<<str<<std::endl;


qDebug()<<"REQUIRE('C0 02 50 01 00 07 08 03' == HexConversions::to_hex(request.ToRSeq()))";

/*
TEST_CASE(SUITE("16WriteIINRestart"))
{
    APDURequest request(APDUHelpers::Request(FunctionCode::WRITE));
    auto writer = request.GetWriter();

    {
        auto iter
            = writer.IterateOverSingleBitfield<UInt8>(GroupVariationID(80, 1), QualifierCode::UINT8_START_STOP, 7);
        iter.Write(true);
        iter.Write(true);
    }

    REQUIRE("C0 02 50 01 00 07 08 03" == HexConversions::to_hex(request.ToRSeq()));
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

