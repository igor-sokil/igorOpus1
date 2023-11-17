
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

void configure_in_11reports(DatabaseConfig*);
void configure_in_11reports(DatabaseConfig* db)
{
////    auto configure = [](DatabaseConfig& db) { db.counter[0].evariation = EventCounterVariation::Group22Var5; };
        db->counter[0].dDeadbandConfig_for_CounterInfo.eEventConfig.evariation = EventCounterVariation_Group22Var5;
}

void update_in_11reports(IUpdateHandler*);
void update_in_11reports(IUpdateHandler* db)
{
    std::cout << "update_in_11reports" <<'\n';
////    auto update = [](IUpdateHandler& db) { db.Update(Counter(23, Flags(0x01), DNPTime(1512595515000)), 0); };

 Flags fFlags;
 Flags_In_FlagsOver2(&fFlags, 1);

 DNPTime dDNPTime;
 DNPTime_in_DNPTimeOver2(&dDNPTime, 1512595515000);

//void Counter_in_CounterOver4(Counter *pCounter, uint32_t value, Flags flags, DNPTime timeDNPTime);
 Counter cCounter;
 Counter_in_CounterOver4(&cCounter, 23, fFlags, dDNPTime);

 Update_Counter_in_IUpdateHandler(db, &cCounter, 0, EventMode_Detect);// = EventMode::Detect) = 0;
}

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);


qDebug()<<"********SUITE('11reports g22v5 correctly')********";
////    TestEventRead("C0 01 3C 02 06", "E0 81 80 00 16 05 28 01 00 00 00 01 17 00 00 00 78 E6 B7 2D 60 01", update,
////                  configure);

 std::string request("C0 01 3C 02 06");       
 std::string response("E0 81 80 00 16 05 28 01 00 00 00 01 17 00 00 00 78 E6 B7 2D 60 01");       
 TestEventRead(request, response,
                   ////const std::function<void(IUpdateHandler& db)>& loadFun,
                   update_in_11reports,
                   ////const std::function<void(DatabaseConfig& db)>& configure = [](DatabaseConfig& view) {})
                   configure_in_11reports);

/*
TEST_CASE(SUITE("11reports g22v5 correctly"))
{
    auto update = [](IUpdateHandler& db) { db.Update(Counter(23, Flags(0x01), DNPTime(1512595515000)), 0); };

    auto configure = [](DatabaseConfig& db) { db.counter[0].evariation = EventCounterVariation::Group22Var5; };

    TestEventRead("C0 01 3C 02 06", "E0 81 80 00 16 05 28 01 00 00 00 01 17 00 00 00 78 E6 B7 2D 60 01", update,
                  configure);
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

