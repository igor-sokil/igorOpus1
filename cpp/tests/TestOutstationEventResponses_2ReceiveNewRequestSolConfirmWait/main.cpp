
#include <QApplication>
#include <QtWidgets>

#include <stdlib.h>
#include <iostream>
#include <string>

#include "MainWindow.h"
#include "key_filter.h"

#include "header.h"

#include "OutstationConfig.h"
#include "OutstationTestObject.h"
#include "APDUHexBuilders.h"
#include "DatabaseHelpers.h"

#define UNUSED(x) (void)(x)


key_filter *pkf;

MainWindow *mainWindow;

void apply_in_2ReceiveNewRequestSolConfirmWait(IUpdateHandler*);
void apply_in_2ReceiveNewRequestSolConfirmWait(IUpdateHandler* db)
{
    std::cout << "apply_in_2ReceiveNewRequestSolConfirmWait1" <<'\n';
////    t.Transaction([](IUpdateHandler& db) { db.Update(Binary(true, Flags(0x01)), 0); });
 Flags fFlags;
 Flags_In_FlagsOver2(&fFlags, 1);

//void Binary_in_BinaryOver5(Binary *pBinary, boolean value, Flags flags);
 Binary bBinary;;
 Binary_in_BinaryOver5(&bBinary, true, fFlags);

//boolean Update_Binary_in_IUpdateHandler(IUpdateHandler*, Binary* meas, uint16_t index, EventMode_uint8_t mode);// = EventMode::Detect) = 0;
////            db.Update(Binary(true, Flags(0x01)), 0); 
         Update_Binary_in_IUpdateHandler(db, &bBinary, 0, EventMode_Detect);// = EventMode::Detect) = 0;
}

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);


qDebug()<<"********SUITE('2ReceiveNewRequestSolConfirmWait')********";
    OutstationConfig config;
    OutstationConfig_in_OutstationConfig(&config);

//    DatabaseConfig tmp;
//    DatabaseConfig_in_DatabaseConfig(&tmp, 0);
////    config.eventBufferConfig = EventBufferConfig::AllTypes(10);
   EventBufferConfig etemp = AllTypes_in_EventBufferConfig_static(MAX_EventRecord);
   config.eventBufferConfig = etemp;


////    OutstationTestObject t(config, configure::by_count_of::binary_input(1));
    DatabaseConfig tmp = binary_input_in_DatabaseHelpers(1);

    OutstationTestObject t;
    OutstationTestObject_in_OutstationTestObject(&t, &config, &tmp);

    LowerLayerUp_in_OutstationTestObject(&t);

//void Transaction_in_OutstationTestObject(OutstationTestObject *pOutstationTestObject, void (*apply)(IUpdateHandler*));//std::function<void(opendnp3::IUpdateHandler&)>& apply)
////    t.Transaction([](IUpdateHandler& db) { db.Update(Binary(true, Flags(0x01)), 0); });

    Transaction_in_OutstationTestObject(&t, apply_in_2ReceiveNewRequestSolConfirmWait);//void (*apply)(IUpdateHandler*));

//std::string ClassPoll_in_APDUHexBuilders(uint8_t seq, PointClass_uint8_t pc)
////    t.SendToOutstation(hex::ClassPoll(0, PointClass::Class1));
////    REQUIRE(t.lower->PopWriteAsHex() == "E0 81 80 00 02 01 28 01 00 00 00 81");
////    t.OnTxReady();

    std::string name = ClassPoll_in_APDUHexBuilders(0, PointClass_Class1);
    std::cout << "name= " << name<<'\n';

    SendToOutstation_in_OutstationTestObject(&t, name);  

    std::string temp = PopWriteAsHex_in_MockLowerLayer(&(t.lower));

qDebug()<<"REQUIRE(t.lower->PopWriteAsHex()== 'E0 81 80 00 02 01 28 01 00 00 00 81')";
std::cout << "temp= " << temp<<'\n';

////    t.OnTxReady();
    OnTxReady_in_OutstationTestObject(&t);

////    t.SendToOutstation(hex::ClassPoll(1, PointClass::Class1));
    std::string name2 = ClassPoll_in_APDUHexBuilders(1, PointClass_Class1);
    std::cout << "name2= " << name2<<'\n';

///    REQUIRE(t.lower->PopWriteAsHex() == "E1 81 80 00 02 01 28 01 00 00 00 81");
    SendToOutstation_in_OutstationTestObject(&t, name2);  

    std::string temp2 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));

qDebug()<<"REQUIRE(t.lower->PopWriteAsHex()== 'E1 81 80 00 02 01 28 01 00 00 00 81')";
std::cout << "temp2= " << temp2<<'\n';
/*
TEST_CASE(SUITE("2ReceiveNewRequestSolConfirmWait"))
{
    OutstationConfig config;
    config.eventBufferConfig = EventBufferConfig::AllTypes(10);
    OutstationTestObject t(config, configure::by_count_of::binary_input(1));
    t.LowerLayerUp();

    t.Transaction([](IUpdateHandler& db) { db.Update(Binary(true, Flags(0x01)), 0); });

    t.SendToOutstation(hex::ClassPoll(0, PointClass::Class1));
    REQUIRE(t.lower->PopWriteAsHex() == "E0 81 80 00 02 01 28 01 00 00 00 81");
    t.OnTxReady();

    t.SendToOutstation(hex::ClassPoll(1, PointClass::Class1));
    REQUIRE(t.lower->PopWriteAsHex() == "E1 81 80 00 02 01 28 01 00 00 00 81");
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

