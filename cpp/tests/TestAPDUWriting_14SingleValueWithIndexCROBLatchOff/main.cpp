
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
#include "HeaderWriter_for_ControlRelayOutputBlock.h"
#include "Group12.h"

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

qDebug()<<"********SUITE('14SingleValueWithIndexCROBLatchOff')********";
     APDURequest request = 
                Request_in_APDUHelpers_static(FunctionCode_SELECT, SIZE_in_APDUHelpers);// = SIZE);
//    auto writer = response.GetWriter();
     HeaderWriter writer = GetWriter_in_APDUWrapper(&(request.aAPDUWrapper));

//void ControlRelayOutputBlock_in_ControlRelayOutputBlockOver1(ControlRelayOutputBlock *pControlRelayOutputBlock,
//    OperationType_uint8_t opType,//// = OperationType::LATCH_ON,
//    TripCloseCode_uint8_t tcc,//// = TripCloseCode::NUL,
//    boolean clear,//// = false,
//    uint8_t count,//// = 1,
//    uint32_t onTime,//// = 100,
//    uint32_t offTime,//// = 100,
//    CommandStatus_uint8_t status);//// = CommandStatus::SUCCESS);
////    ControlRelayOutputBlock crob(OperationType::LATCH_OFF, TripCloseCode::NUL, false, 0x1F, 0x10, 0xAA,
////                                 CommandStatus::LOCAL);
 ControlRelayOutputBlock crob;
 ControlRelayOutputBlock_in_ControlRelayOutputBlockOver1(&crob,
    OperationType_LATCH_OFF,
    TripCloseCode_NUL,
    false,
    0x1F,
    0x10,//uint32_t onTime,//// = 100,
    0xAA,//uint32_t offTime,//// = 100,
    CommandStatus_LOCAL);//// = CommandStatus::SUCCESS);

//boolean WriteSingleIndexedValue_for_UInt16_ControlRelayOutputBlock_in_HeaderWriter(HeaderWriter *pHeaderWriter,
//    QualifierCode_uint8_t qc,
//    DNP3Serializer_for_ControlRelayOutputBlock* serializer,
//    ControlRelayOutputBlock* value,
//    uint16_t index);
//DNP3Serializer_for_ControlRelayOutputBlock  Inst_in_Group12Var1_static(void);
////    REQUIRE(writer.WriteSingleIndexedValue<UInt16>(QualifierCode::UINT16_CNT, Group12Var1::Inst(), crob, 0x21));

DNP3Serializer_for_ControlRelayOutputBlock  temp = Inst_in_Group12Var1_static();
boolean bln = WriteSingleIndexedValue_for_UInt16_ControlRelayOutputBlock_in_HeaderWriter(&writer,
    QualifierCode_UINT16_CNT,
    &temp,
    &crob,
    0x21);
qDebug()<<"REQUIRE(writer.WriteSingleIndexedValue<UInt16>(QualifierCode::UINT16_CNT, Group12Var1::Inst(), crob, 0x21))";
qDebug()<<"boolean bln ="<<bln;

////    REQUIRE("C0 03 0C 01 08 01 00 21 00 04 1F 10 00 00 00 AA 00 00 00 07" == HexConversions::to_hex(request.ToRSeq()));
  RSeq_for_Uint16_t rseq = ToRSeq_in_APDUWrapper(&(request.aAPDUWrapper));
  std::string  str = to_hex_in_HexConversionsOver2(&rseq, true);
  std::cout<<"str= "<<str<<std::endl;
  qDebug()<<"REQUIRE('C0 03 0C 01 08 01 00 21 00 04 1F 10 00 00 00 AA 00 00 00 07' == HexConversions::to_hex(request.ToRSeq()))";

  /*
TEST_CASE(SUITE("14SingleValueWithIndexCROBLatchOff"))
{
    APDURequest request(APDUHelpers::Request(FunctionCode::SELECT));
    auto writer = request.GetWriter();

    ControlRelayOutputBlock crob(OperationType::LATCH_OFF, TripCloseCode::NUL, false, 0x1F, 0x10, 0xAA,
                                 CommandStatus::LOCAL);

    REQUIRE(writer.WriteSingleIndexedValue<UInt16>(QualifierCode::UINT16_CNT, Group12Var1::Inst(), crob, 0x21));

    REQUIRE("C0 03 0C 01 08 01 00 21 00 04 1F 10 00 00 00 AA 00 00 00 07" == HexConversions::to_hex(request.ToRSeq()));
}
  */

/*
     APDURequest request = 
                Request_in_APDUHelpers_static(FunctionCode_SELECT, SIZE_in_APDUHelpers);// = SIZE);
//    auto writer = response.GetWriter();
     HeaderWriter writer = GetWriter_in_APDUWrapper(&(request.aAPDUWrapper));

//void ControlRelayOutputBlock_in_ControlRelayOutputBlockOver1(ControlRelayOutputBlock *pControlRelayOutputBlock,
//    OperationType_uint8_t opType,//// = OperationType::LATCH_ON,
//    TripCloseCode_uint8_t tcc,//// = TripCloseCode::NUL,
//    boolean clear,//// = false,
//    uint8_t count,//// = 1,
//    uint32_t onTime,//// = 100,
//    uint32_t offTime,//// = 100,
//    CommandStatus_uint8_t status);//// = CommandStatus::SUCCESS);
////    ControlRelayOutputBlock crob(OperationType::LATCH_ON, TripCloseCode::NUL, false, 0x1F, 0x10, 0xAA,
////                                 CommandStatus::LOCAL);
 ControlRelayOutputBlock crob;
 ControlRelayOutputBlock_in_ControlRelayOutputBlockOver1(&crob,
    OperationType_LATCH_ON,
    TripCloseCode_NUL,
    false,
    0x1F,
    0x10,//uint32_t onTime,//// = 100,
    0xAA,//uint32_t offTime,//// = 100,
    CommandStatus_LOCAL);//// = CommandStatus::SUCCESS);

//boolean WriteSingleIndexedValue_for_UInt16_ControlRelayOutputBlock_in_HeaderWriter(HeaderWriter *pHeaderWriter,
//    QualifierCode_uint8_t qc,
//    DNP3Serializer_for_ControlRelayOutputBlock* serializer,
//    ControlRelayOutputBlock* value,
//    uint16_t index);
//DNP3Serializer_for_ControlRelayOutputBlock  Inst_in_Group12Var1_static(void);
////    REQUIRE(writer.WriteSingleIndexedValue<UInt16>(QualifierCode::UINT16_CNT, Group12Var1::Inst(), crob, 0x21));

DNP3Serializer_for_ControlRelayOutputBlock  temp = Inst_in_Group12Var1_static();
boolean bln = WriteSingleIndexedValue_for_UInt16_ControlRelayOutputBlock_in_HeaderWriter(&writer,
    QualifierCode_UINT16_CNT,
    &temp,
    &crob,
    0x21);
qDebug()<<"REQUIRE(writer.WriteSingleIndexedValue<UInt16>(QualifierCode::UINT16_CNT, Group12Var1::Inst(), crob, 0x21))";
qDebug()<<"boolean bln ="<<bln;

////    REQUIRE("C0 03 0C 01 08 01 00 21 00 03 1F 10 00 00 00 AA 00 00 00 07" == HexConversions::to_hex(request.ToRSeq()));
  RSeq_for_Uint16_t rseq = ToRSeq_in_APDUWrapper(&(request.aAPDUWrapper));
  std::string  str = to_hex_in_HexConversionsOver2(&rseq, true);
  std::cout<<"str= "<<str<<std::endl;
  qDebug()<<"REQUIRE('C0 03 0C 01 08 01 00 21 00 03 1F 10 00 00 00 AA 00 00 00 07' == HexConversions::to_hex(request.ToRSeq()))";
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

