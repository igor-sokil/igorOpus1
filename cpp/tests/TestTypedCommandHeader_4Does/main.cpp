
#include <QApplication>
#include <QtWidgets>

#include <stdlib.h>
#include <iostream>
#include <string>

#include "MainWindow.h"
#include "key_filter.h"

#include "header.h"
#include "TypedCommandHeader.h"
#include "LinkContext.h"
#include "APDURequest.h"
#include "HexConversions.h"
#include "Group41.h"

#define UNUSED(x) (void)(x)

key_filter *pkf;

MainWindow *mainWindow;

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);

qDebug()<<"********SUITE('4Does not format if insufficient space')********";
////    TypedCommandHeader<AnalogOutputInt16> header(Group41Var2::Inst());
////    header.Add(AnalogOutputInt16(7), 10);
////    header.Add(AnalogOutputInt16(8), 11);
////    StaticBuffer<14> buffer;
////    auto dest = buffer.as_wseq();
////    APDURequest request(dest);
////    auto writer = request.GetWriter();
////    REQUIRE_FALSE(header.Write(writer, IndexQualifierMode::always_two_bytes));

//DNP3Serializer_for_AnalogOutputInt16  Inst_in_Group41Var2_static(void)
////    TypedCommandHeader<AnalogOutputInt16> header(Group41Var2::Inst());
 DNP3Serializer_for_AnalogOutputInt16 temp = Inst_in_Group41Var2_static();

 TypedCommandHeader_for_AnalogOutputInt16 header;
 TypedCommandHeader_for_AnalogOutputInt16_in_TypedCommandHeader_for_AnalogOutputInt16(&header, &temp);

//void AnalogOutputInt16_in_AnalogOutputInt16Over2(AnalogOutputInt16 *, int16_t value_);
//void* Add_in_TypedCommandHeader_for_AnalogOutputInt16(TypedCommandHeader_for_AnalogOutputInt16* pTypedCommandHeader_for_AnalogOutputInt16,
//    AnalogOutputInt16* command, uint16_t index);
////    header.Add(AnalogOutputInt16(7), 10);
 AnalogOutputInt16 aAnalogOutputInt16;
 AnalogOutputInt16_in_AnalogOutputInt16Over2(&aAnalogOutputInt16, 7);
 Add_in_TypedCommandHeader_for_AnalogOutputInt16(&header, &aAnalogOutputInt16, 10);

////    header.Add(AnalogOutputInt16(8), 11);
 AnalogOutputInt16_in_AnalogOutputInt16Over2(&aAnalogOutputInt16, 8);
 Add_in_TypedCommandHeader_for_AnalogOutputInt16(&header, &aAnalogOutputInt16, 11);

////    StaticBuffer<14> buffer;
 StaticBuffer_for_LPDU_MAX_FRAME_SIZE buffer;
////    auto dest = buffer.as_wseq();
//WSeq_for_Uint16_t dest = as_wseq_in_StaticBuffer_for_LPDU_MAX_FRAME_SIZEOver1(&buffer);
WSeq_for_Uint16_t dest = as_wseq_in_StaticBuffer_for_LPDU_MAX_FRAME_SIZEOver2(&buffer, 14);

////    APDURequest request(dest);
 APDURequest request;
 APDURequest_in_APDURequestOver2(&request, &dest);

//HeaderWriter GetWriter_in_APDUWrapper(APDUWrapper *pAPDUWrapper);
////    auto writer = request.GetWriter();
HeaderWriter writer = GetWriter_in_APDUWrapper(&(request.aAPDUWrapper));

//boolean Write_in_TypedCommandHeader_for_AnalogOutputInt16(TypedCommandHeader_for_AnalogOutputInt16* pTypedCommandHeader_for_AnalogOutputInt16,
//              HeaderWriter*, IndexQualifierMode_uint8_t mode);
////    REQUIRE_FALSE(header.Write(writer, IndexQualifierMode::always_two_bytes));
boolean btemp = Write_in_TypedCommandHeader_for_AnalogOutputInt16(&header,
              &writer, IndexQualifierMode_always_two_bytes);
std::cout<<"REQUIRE_FALSE(header.Write(writer, IndexQualifierMode::always_two_bytes))"<<'\n';
std::cout<<"boolean btemp ="<<btemp<<'\n';
/*
//std::string to_hex_in_HexConversionsOver2(RSeq_for_Uint16_t* buffer, bool spaced = true);
////    auto hex = HexConversions::to_hex(request.ToRSeq().skip(2));
///    REQUIRE(hex == "29 02 28 02 00 0A 00 07 00 00 0B 00 08 00 00");
  RSeq_for_Uint16_t rseq = ToRSeq_in_APDUWrapper(&(request.aAPDUWrapper));
  std::string  str = to_hex_in_HexConversionsOver2(&rseq, true);
  std::cout<<"str= "<<str<<std::endl;
  qDebug()<<"REQUIRE(hex == '29 02 28 02 00 0A 00 07 00 00 0B 00 08 00 00')";
*/
////    auto objects = "33 02 07 01 07 00 00 00 00 00 02 03 17 01 08 81 01 00";
// std::string objects = "33 02 07 01 07 00 00 00 00 00 02 03 17 01 08 81 01 00";
// TestObjectHeaders( objects, ParseResult_OK, verify);

/*
TEST_CASE(SUITE("4Does not format if insufficient space"))
{
    TypedCommandHeader<AnalogOutputInt16> header(Group41Var2::Inst());
    header.Add(AnalogOutputInt16(7), 10);
    header.Add(AnalogOutputInt16(8), 11);

    StaticBuffer<14> buffer;
    auto dest = buffer.as_wseq();
    APDURequest request(dest);
    auto writer = request.GetWriter();

    REQUIRE_FALSE(header.Write(writer, IndexQualifierMode::always_two_bytes));
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

