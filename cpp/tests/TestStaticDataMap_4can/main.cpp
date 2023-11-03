
#include <QApplication>
#include <QtWidgets>

#include <stdlib.h>
#include <iostream>
#include <string>

#include "MainWindow.h"
#include "key_filter.h"

#include "header.h"

//#include "StaticDataMap_for_Binary.h"
//#include "OutstationTestObject.h"
#include "EventReceiver.h"

#define UNUSED(x) (void)(x)


key_filter *pkf;

MainWindow *mainWindow;

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);

//expectsContents_in_CountParser = true;
//expectsContents_in_CountIndexParser = false;
//expectsContents_in_RangeParser = false;

qDebug()<<"********SUITE('4can force events on existing point')********";
    StaticDataMap_for_BinarySpec map{{{0, {}}}};
std::cout << "map.size()= " << map.map.size()<<'\n';
StaticDataCell_for_Binary sdc;// = map.map[0];
   StaticDataCell_for_Binary_in_StaticDataCell_for_BinaryOver1(&sdc);
   map.map[0] = sdc;

//uint16_t select_all_in_StaticDataMap_for_BinarySpecOver1(StaticDataMap_for_BinarySpec *pStaticDataMap_for_BinarySpec);
////    map.select_all();
// select_all_in_StaticDataMap_for_BinarySpecOver1(&map);


////    EventReceiver receiver;
    EventReceiver receiver;
    EventReceiver_in_EventReceiver(&receiver);

//boolean update_in_StaticDataMap_for_BinarySpecOver1(StaticDataMap_for_BinarySpec *pStaticDataMap_for_BinarySpec,
//    Binary* value,
//    uint16_t index,
//    EventMode_uint8_t mode,
//    IEventReceiver* receiver);
//void Binary_in_BinaryOver2(Binary *pBinary, boolean value);
////    REQUIRE_FALSE(map.update(Binary(true), 0, EventMode::Detect, receiver));
     Binary bBinary;
     Binary_in_BinaryOver2(&bBinary, true);

boolean btemp = update_in_StaticDataMap_for_BinarySpecOver1(&map,
    &bBinary,
    0,
    EventMode_Force,
    &receiver.iIEventReceiver);

std::cout << "REQUIRE(map.update(Binary(true), 0, EventMode::Force, receiver))"<<'\n';
std::cout << "btemp= " << btemp<<'\n';

//boolean select_in_StaticDataMap_for_BinarySpecOver2(StaticDataMap_for_BinarySpec *pStaticDataMap_for_BinarySpec, uint16_t index, StaticBinaryVariation_uint8_t variation);
////    map.select(0, StaticBinaryVariation::Group1Var1);
 select_in_StaticDataMap_for_BinarySpecOver2(&map, 0, StaticBinaryVariation_Group1Var1);

////    REQUIRE((*map.begin()).second.value.value == true);
std::cout << "REQUIRE((*map.begin()).second.value.value == true)"<<'\n';
std::cout << "temp= " << ((*map.begin()).second.value.tTypedMeasurement_for_Boolean.value == true)<<'\n';

////    REQUIRE(receiver.count == 1);
std::cout << "REQUIRE(receiver.count == 1)"<<'\n';
std::cout << "temp= " << (receiver.count == 1)<<'\n';

////    REQUIRE(receiver.latestBinaryEvent.value.value == true);
std::cout << "REQUIRE(receiver.latestBinaryEvent.value.value == true)"<<'\n';
std::cout << "temp= " << (receiver.latestBinaryEvent.value.tTypedMeasurement_for_Boolean.value == true)<<'\n';

////    REQUIRE(map.update(Binary(true), 0, EventMode::Detect, receiver));
btemp = update_in_StaticDataMap_for_BinarySpecOver1(&map,
    &bBinary,
    0,
    EventMode_Force,
    &receiver.iIEventReceiver);

std::cout << "REQUIRE(map.update(Binary(true), 0, EventMode::Force, receiver))"<<'\n';
std::cout << "btemp= " << btemp<<'\n';

////    REQUIRE(receiver.count == 2);
std::cout << "REQUIRE(receiver.count == 2)"<<'\n';
std::cout << "temp= " << (receiver.count == 2)<<'\n';

/*
TEST_CASE(SUITE("4can force events on existing point"))
может навязать события в существующей точке
{
    StaticDataMap<BinarySpec> map{{{0, {}}}};

    EventReceiver receiver;
    REQUIRE(map.update(Binary(true), 0, EventMode::Force, receiver));
    map.select(0, StaticBinaryVariation::Group1Var1);
    REQUIRE((*map.begin()).second.value.value == true);
    REQUIRE(receiver.count == 1);
    REQUIRE(receiver.latestBinaryEvent.value.value == true);

    REQUIRE(map.update(Binary(true), 0, EventMode::Force, receiver));
    REQUIRE(receiver.count == 2);
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

