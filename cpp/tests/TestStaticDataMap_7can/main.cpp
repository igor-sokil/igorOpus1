
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

qDebug()<<"********SUITE('7can select all points using default variation and iterate')********";
    StaticDataMap_for_BinarySpec map{{
        {0, {}},
        {3, {}},
        {7, {}},
    }};

StaticDataMap_for_BinarySpec_in_StaticDataMap_for_BinarySpecOver1(&map);
StaticDataCell_for_Binary sdc;
   StaticDataCell_for_Binary_in_StaticDataCell_for_BinaryOver1(&sdc);
   map.map[0] = sdc;
   map.map[3] = sdc;
   map.map[7] = sdc;

std::cout << "map.size()= " << map.map.size()<<'\n';

//uint32_t Count_in_Range(Range *pRange);
//Range get_selected_range_in_StaticDataMap_for_BinarySpec(StaticDataMap_for_BinarySpec *pStaticDataMap_for_BinarySpec);
////    REQUIRE(map.get_selected_range().Count() == 0);
Range rtmp = get_selected_range_in_StaticDataMap_for_BinarySpec(&map);
uint32_t ctmp = Count_in_Range(&rtmp);

std::cout << "REQUIRE(map.get_selected_range().Count() == 0)"<<'\n';
std::cout << "ctmp= " << ctmp<<'\n';
std::cout << "rtmp.start= " << (uint16_t)rtmp.start<<'\n';
std::cout << "rtmp.stop= " << (uint16_t)rtmp.stop<<'\n';

//uint16_t select_all_in_StaticDataMap_for_BinarySpecOver1(StaticDataMap_for_BinarySpec *pStaticDataMap_for_BinarySpec);
////    REQUIRE(map.select_all() == 3);
ctmp = select_all_in_StaticDataMap_for_BinarySpecOver1(&map);
std::cout << "REQUIRE(map.select_all() == 3)"<<'\n';
std::cout << "ctmp= " << ctmp<<'\n';

////    std::vector<StaticDataMap<BinarySpec>::iterator::value_type> items;
    std::vector<std::pair<uint16_t, SelectedValue_for_BinarySpec>> items;
    for (const auto& item : map)
    {
        items.push_back(item);
    }

////    REQUIRE(items.size() == 3);
std::cout << "REQUIRE(items.size() == 3)"<<'\n';
std::cout << "items.size()= " << items.size()<<'\n';

    for (const auto& item : items)
    {
////        REQUIRE(item.second.variation == BinarySpec::DefaultStaticVariation);
std::cout << "REQUIRE(item.second.variation == BinarySpec::DefaultStaticVariation)"<<'\n';
std::cout << "item.second.variation= " << (uint16_t)item.second.variation<<'\n';
    }

/*
TEST_CASE(SUITE("7can select all points using default variation and iterate"))
{
    StaticDataMap<BinarySpec> map{{
        {0, {}},
        {3, {}},
        {7, {}},
    }};

    REQUIRE(map.get_selected_range().Count() == 0);
    REQUIRE(map.select_all() == 3);

    std::vector<StaticDataMap<BinarySpec>::iterator::value_type> items;
    for (const auto& item : map)
    {
        items.push_back(item);
    }

    REQUIRE(items.size() == 3);
    for (const auto& item : map)
    {
        REQUIRE(item.second.variation == BinarySpec::DefaultStaticVariation);
    }
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

