
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

void apply_in_18UnsolEnable(IUpdateHandler*);
void apply_in_18UnsolEnable(IUpdateHandler* db)
{
    std::cout << "apply_in_18UnsolEnable" <<'\n';
////    t.Transaction([](IUpdateHandler& db) { db.Update(Binary(false, Flags(0x01)), 0); });
//void Binary_in_BinaryOver2(Binary *pBinary, boolean value);
 Flags fFlags;
 Flags_In_FlagsOver2(&fFlags, 1);

//void Binary_in_BinaryOver5(Binary *pBinary, boolean value, Flags flags);
 Binary bBinary1;
 Binary_in_BinaryOver5(&bBinary1, false, fFlags);

//boolean Update_Binary_in_IUpdateHandler(IUpdateHandler*, Binary* meas, uint16_t index, EventMode_uint8_t mode);// = EventMode::Detect) = 0;
 Update_Binary_in_IUpdateHandler(db, &bBinary1, 0, EventMode_Detect);// = EventMode::Detect) = 0;
}

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);


qDebug()<<"********SUITE('18UnsolEnable')********";
//------------1
////    OutstationConfig cfg;
////    cfg.params.allowUnsolicited = true;
////    cfg.eventBufferConfig = EventBufferConfig(5);
////    OutstationTestObject t(cfg, configure::by_count_of::binary_input(5));
////    t.LowerLayerUp();
////    REQUIRE(t.lower->PopWriteAsHex() == hex::NullUnsolicited(0));

    OutstationConfig cfg;
    OutstationConfig_in_OutstationConfig(&cfg);

////    cfg.params.allowUnsolicited = true;
    cfg.params.allowUnsolicited = true;

////    cfg.eventBufferConfig = EventBufferConfig(5);
    EventBufferConfig eEventBufferConfig;
    EventBufferConfig_in_EventBufferConfigOver2(&eEventBufferConfig, 5, 0, 0, 0, 0, 0, 0, 0);
    cfg.eventBufferConfig = eEventBufferConfig;

////    OutstationTestObject t(cfg, configure::by_count_of::binary_input(5));
    DatabaseConfig database = binary_input_in_DatabaseHelpers(5);

    OutstationTestObject t;
    OutstationTestObject_in_OutstationTestObject(&t, &cfg, &database);

////    t.LowerLayerUp();
    LowerLayerUp_in_OutstationTestObject(&t);

////    REQUIRE(t.lower->PopWriteAsHex() == hex::NullUnsolicited(0));
 IINField iIINField;
 IINField_in_IINFieldOver2(&iIINField, IINBit_DEVICE_RESTART);
 std::string respond = NullUnsolicited_in_APDUHexBuilders(0, &iIINField);// = opendnp3::IINField(opendnp3::IINBit::DEVICE_RESTART));

    std::string temp1 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));

std::cout << "respond= " << respond<<'\n';
qDebug()<<"REQUIRE(t.lower->PopWriteAsHex() == hex::NullUnsolicited(0))";
std::cout << "temp1= " << temp1<<'\n';

//------------2
////    t.OnTxReady();
////    t.SendToOutstation(hex::UnsolConfirm(0));
////    // do a transaction to show that unsol data is not being reported yet
//// // выполняем транзакцию, чтобы показать, что данные о несостоятельности еще не передаются
////    t.Transaction([](IUpdateHandler& db) { db.Update(Binary(false, Flags(0x01)), 0); });
////    REQUIRE(t.lower->PopWriteAsHex().empty());

////    t.OnTxReady();
    OnTxReady_in_OutstationTestObject(&t);

////    t.SendToOutstation(hex::UnsolConfirm(0));
    SendToOutstation_in_OutstationTestObject(&t, respond);  

////    // do a transaction to show that unsol data is not being reported yet
//// // выполняем транзакцию, чтобы показать, что данные о несостоятельности еще не передаются
////    t.Transaction([](IUpdateHandler& db) { db.Update(Binary(false, Flags(0x01)), 0); });
    Transaction_in_OutstationTestObject(&t, apply_in_18UnsolEnable);//void (*apply)(IUpdateHandler*));

////    REQUIRE(t.lower->PopWriteAsHex().empty());
    std::string temp2 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));
std::cout << "temp2= " << temp2<<'\n';

//------------3
////    // Enable unsol class 1
////    t.SendToOutstation("C0 14 3C 02 06");
////    REQUIRE(t.lower->PopWriteAsHex() == "C0 81 82 00");
////    t.OnTxReady();
////    // should automatically send the previous data as unsol
////    REQUIRE(t.lower->PopWriteAsHex() == "F1 82 80 00 02 01 28 01 00 00 00 01");

////    t.SendToOutstation("C0 14 3C 02 06");
    std::string name1 = "C0 14 3C 02 06";
    SendToOutstation_in_OutstationTestObject(&t, name1);  

////    REQUIRE(t.lower->PopWriteAsHex() == "C0 81 82 00");
    std::string temp3 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));
qDebug()<<"REQUIRE(t.lower->PopWriteAsHex() == 'C0 81 82 00')";
std::cout << "temp3= " << temp3<<'\n';

////    t.OnTxReady();
    OnTxReady_in_OutstationTestObject(&t);

////    // should automatically send the previous data as unsol
////    REQUIRE(t.lower->PopWriteAsHex() == "F1 82 80 00 02 01 28 01 00 00 00 01");
    std::string temp4 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));
qDebug()<<"REQUIRE(t.lower->PopWriteAsHex() == 'F1 82 80 00 02 01 28 01 00 00 00 01')";
std::cout << "temp4= " << temp4<<'\n';

/*
TEST_CASE(SUITE("18UnsolEnable"))
{
    OutstationConfig cfg;
    cfg.params.allowUnsolicited = true;
    cfg.eventBufferConfig = EventBufferConfig(5);
    OutstationTestObject t(cfg, configure::by_count_of::binary_input(5));

    t.LowerLayerUp();

    REQUIRE(t.lower->PopWriteAsHex() == hex::NullUnsolicited(0));
    t.OnTxReady();
    t.SendToOutstation(hex::UnsolConfirm(0));

    // do a transaction to show that unsol data is not being reported yet
    t.Transaction([](IUpdateHandler& db) { db.Update(Binary(false, Flags(0x01)), 0); });

    REQUIRE(t.lower->PopWriteAsHex().empty());

    // Enable unsol class 1
    t.SendToOutstation("C0 14 3C 02 06");
    REQUIRE(t.lower->PopWriteAsHex() == "C0 81 82 00");
    t.OnTxReady();

    // should automatically send the previous data as unsol
    REQUIRE(t.lower->PopWriteAsHex() == "F1 82 80 00 02 01 28 01 00 00 00 01");
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

