
#include <QApplication>
#include <QtWidgets>

#include <stdlib.h>

#include "MainWindow.h"
#include "key_filter.h"

#include "header.h"

#include "APDUHelpers.h"
#include "APDUHeader.h"
#include "SerializationTemplates.h"
#include "Group60.h"

DWORD get_fattime (void);

void* pPointerGlobal1;
void* pPointerGlobal2;
void* pPointerGlobal3;

#define UNUSED(x) (void)(x)

key_filter *pkf;

MainWindow *mainWindow;

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);


/*
TEST_CASE(SUITE("AllObjectsAndRollback"))
{
    APDURequest request(APDUHelpers::Request(FunctionCode::READ));
    auto writer = request.GetWriter();
    writer.WriteHeader(Group60Var1::ID(), QualifierCode::ALL_OBJECTS);
    writer.WriteHeader(Group60Var2::ID(), QualifierCode::ALL_OBJECTS);
    writer.Mark();
    writer.WriteHeader(Group60Var3::ID(), QualifierCode::ALL_OBJECTS);
    writer.WriteHeader(Group60Var4::ID(), QualifierCode::ALL_OBJECTS);

    REQUIRE("C0 01 3C 01 06 3C 02 06 3C 03 06 3C 04 06" == HexConversions::to_hex(request.ToRSeq()));

    writer.Rollback();

    REQUIRE("C0 01 3C 01 06 3C 02 06" == HexConversions::to_hex(request.ToRSeq()));
}
*/
//    APDURequest request(APDUHelpers::Request(FunctionCode::READ));
     APDURequest request = 
                Request_in_APDUHelpers_static(FunctionCode_READ, SIZE_in_APDUHelpers);// = SIZE);
//    auto writer = request.GetWriter();
//  HeaderWriter GetWriter_in_APDUWrapper(APDUWrapper *pAPDUWrapper);
     HeaderWriter writer = GetWriter_in_APDUWrapper(&(request.aAPDUWrapper));
//    writer.WriteHeader(Group60Var1::ID(), QualifierCode::ALL_OBJECTS);
//    boolean WriteHeader_in_HeaderWriter(HeaderWriter *pHeaderWriter, GroupVariationID id, QualifierCode qc);
     WriteHeader_in_HeaderWriter(&writer, ID_in_Group60Var1_static(), QualifierCode_ALL_OBJECTS);
//    writer.WriteHeader(Group60Var2::ID(), QualifierCode::ALL_OBJECTS);
     WriteHeader_in_HeaderWriter(&writer, ID_in_Group60Var2_static(), QualifierCode_ALL_OBJECTS);
//    writer.Mark();
//    void Mark_in_HeaderWriter(HeaderWriter *pHeaderWriter);
     Mark_in_HeaderWriter(&writer);
//    writer.WriteHeader(Group60Var3::ID(), QualifierCode::ALL_OBJECTS);
     WriteHeader_in_HeaderWriter(&writer, ID_in_Group60Var3_static(), QualifierCode_ALL_OBJECTS);
//    writer.WriteHeader(Group60Var4::ID(), QualifierCode::ALL_OBJECTS);
     WriteHeader_in_HeaderWriter(&writer, ID_in_Group60Var4_static(), QualifierCode_ALL_OBJECTS);

//    REQUIRE("C0 01 3C 01 06 3C 02 06 3C 03 06 3C 04 06" == HexConversions::to_hex(request.ToRSeq()));
     RSeq_for_Uint16_t rseq = ToRSeq_in_APDUWrapper(&(request.aAPDUWrapper));
     qDebug()<<"REQUIRE('C0 01 3C 01 06 3C 02 06 3C 03 06 3C 04 06' == HexConversions::to_hex(request.ToRSeq()))";
     qDebug()<<"rseq.buffer_[0]= "<<hex<<rseq.buffer_[0];
     qDebug()<<"rseq.buffer_[1]= "<<hex<<rseq.buffer_[1];
     qDebug()<<"rseq.buffer_[2]= "<<hex<<rseq.buffer_[2];
     qDebug()<<"rseq.buffer_[3]= "<<hex<<rseq.buffer_[3];
     qDebug()<<"rseq.buffer_[4]= "<<hex<<rseq.buffer_[4];
     qDebug()<<"rseq.buffer_[5]= "<<hex<<rseq.buffer_[5];
     qDebug()<<"rseq.buffer_[6]= "<<hex<<rseq.buffer_[6];
     qDebug()<<"rseq.buffer_[7]= "<<hex<<rseq.buffer_[7];
     qDebug()<<"rseq.buffer_[8]= "<<hex<<rseq.buffer_[8];
     qDebug()<<"rseq.buffer_[9]= "<<hex<<rseq.buffer_[9];
     qDebug()<<"rseq.buffer_[10]= "<<hex<<rseq.buffer_[10];
     qDebug()<<"rseq.buffer_[11]= "<<hex<<rseq.buffer_[11];
     qDebug()<<"rseq.buffer_[12]= "<<hex<<rseq.buffer_[12];
     qDebug()<<"rseq.buffer_[13]= "<<hex<<rseq.buffer_[13];

//    writer.Rollback();
//    boolean Rollback_in_HeaderWriter(HeaderWriter *pHeaderWriter);
    Rollback_in_HeaderWriter(&writer);
//    REQUIRE("C0 01 3C 01 06 3C 02 06" == HexConversions::to_hex(request.ToRSeq()));
     rseq = ToRSeq_in_APDUWrapper(&(request.aAPDUWrapper));
     qDebug()<<"REQUIRE('C0 01 3C 01 06 3C 02 06' == HexConversions::to_hex(request.ToRSeq()))";
     qDebug()<<"rseq.buffer_[0]= "<<hex<<rseq.buffer_[0];
     qDebug()<<"rseq.buffer_[1]= "<<hex<<rseq.buffer_[1];
     qDebug()<<"rseq.buffer_[2]= "<<hex<<rseq.buffer_[2];
     qDebug()<<"rseq.buffer_[3]= "<<hex<<rseq.buffer_[3];
     qDebug()<<"rseq.buffer_[4]= "<<hex<<rseq.buffer_[4];
     qDebug()<<"rseq.buffer_[5]= "<<hex<<rseq.buffer_[5];
     qDebug()<<"rseq.buffer_[6]= "<<hex<<rseq.buffer_[6];
     qDebug()<<"rseq.buffer_[7]= "<<hex<<rseq.buffer_[7];

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

