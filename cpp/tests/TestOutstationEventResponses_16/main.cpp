
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
#include "TestOutstationEventResponses.h"

#define UNUSED(x) (void)(x)


key_filter *pkf;

MainWindow *mainWindow;

void configure_in_16ReadGrp32Var7(DatabaseConfig*);
void configure_in_16ReadGrp32Var7(DatabaseConfig* db)
{
}

void update_in_16ReadGrp32Var7(IUpdateHandler*);
void update_in_16ReadGrp32Var7(IUpdateHandler* db)
{
    std::cout << "update_in_16ReadGrp32Var7" <<'\n';
////    auto update = [](IUpdateHandler& db) { db.Update(Analog(0.0, Flags(0x01), DNPTime(0x010203040506)), 0); };

 Flags fFlags;
 Flags_In_FlagsOver2(&fFlags, 1);

 Analog aAnalog;
 Analog_in_AnalogOver3(&aAnalog, 0.0, fFlags);

 Update_Analog_in_IUpdateHandler(db, &aAnalog, 0, EventMode_Detect);// = EventMode::Detect) = 0;
}

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);


qDebug()<<"********SUITE('16ReadGrp32Var7')********";
////    const auto response = "E0 81 80 00 20 07 28 01 00 00 00 01 00 00 00 00 06 05 04 03 02 01";

 std::string request("C0 01 20 00 06");       
 std::string response("E0 81 80 00 20 01 28 01 00 00 00 01 00 00 00 00");       
 TestEventRead(request, response,
                   ////const std::function<void(IUpdateHandler& db)>& loadFun,
                   update_in_15ReadGrp32Var0,
                   ////const std::function<void(DatabaseConfig& db)>& configure = [](DatabaseConfig& view) {})
                   configure_in_15ReadGrp32Var0);

/*
TEST_CASE(SUITE("16ReadGrp32Var7"))
{
    auto update = [](IUpdateHandler& db) { db.Update(Analog(0.0, Flags(0x01), DNPTime(0x010203040506)), 0); };

    const auto response = "E0 81 80 00 20 07 28 01 00 00 00 01 00 00 00 00 06 05 04 03 02 01";

    // specifically read this variation, but let the default be something else
// специально читаем этот вариант, но пусть по умолчанию будет что-то другое
    TestEventRead("C0 01 20 07 06", response, update,
                  [](DatabaseConfig& db) { db.analog_input[0].evariation = EventAnalogVariation::Group32Var1; });

    // configure this as the default variation and ask for variation 0
// настраиваем это как вариант по умолчанию и запрашиваем вариант 0
    TestEventRead("C0 01 20 00 06", response, update,
                  [](DatabaseConfig& db) { db.analog_input[0].evariation = EventAnalogVariation::Group32Var7; });
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

