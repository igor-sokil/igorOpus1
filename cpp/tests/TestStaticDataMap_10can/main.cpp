
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

qDebug()<<"********SUITE('10can select beyond the first entry')********";
//    StaticBinaryVariation_uint8_t other_variation = StaticBinaryVariation_Group1Var1;

    StaticDataMap_for_BinarySpec map{{
        {1, {}},
        {3, {}},
        {7, {}},
    }};

StaticDataMap_for_BinarySpec_in_StaticDataMap_for_BinarySpecOver1(&map);
StaticDataCell_for_Binary sdc;
   StaticDataCell_for_Binary_in_StaticDataCell_for_BinaryOver1(&sdc);
   map.map[1] = sdc;
   map.map[3] = sdc;
   map.map[7] = sdc;

std::cout << "map.size()= " << map.map.size()<<'\n';

//uint16_t select_in_StaticDataMap_for_BinarySpecOver1(StaticDataMap_for_BinarySpec *pStaticDataMap_for_BinarySpec, Range range);
//Range From_in_Range_static(uint16_t start, uint16_t stop);
////    REQUIRE(map.select(Range::From(3, 8)) == 2);
Range rng = From_in_Range_static(3, 8);

  StaticDataCell_for_Binary stmp = map.map[1];
  std::cout << "stmp.selection.selected= " << stmp.selection.selected<<'\n';
   stmp = map.map[3];
  std::cout << "stmp.selection.selected= " << stmp.selection.selected<<'\n';
   stmp = map.map[7];
  std::cout << "stmp.selection.selected= " << stmp.selection.selected<<'\n';

uint16_t ctmp = select_in_StaticDataMap_for_BinarySpecOver1(&map, rng);
std::cout << "REQUIRE(map.select(Range::From(3, 8)) == 2)"<<'\n';
std::cout << "ctmp= " << ctmp<<'\n';

  stmp = map.map[1];
  std::cout << "stmp.selection.selected= " << stmp.selection.selected<<'\n';
   stmp = map.map[3];
  std::cout << "stmp.selection.selected= " << stmp.selection.selected<<'\n';
   stmp = map.map[7];
  std::cout << "stmp.selection.selected= " << stmp.selection.selected<<'\n';


////    std::vector<StaticDataMap<BinarySpec>::iterator::value_type> items;
    std::vector<std::pair<uint16_t, SelectedValue_for_BinarySpec>> items;
    for (const auto& item : map)
    {
        items.push_back(item);
    }

////    REQUIRE(items.size() == 2);
std::cout << "REQUIRE(items.size() == 2)"<<'\n';
std::cout << "items.size()= " << items.size()<<'\n';


/*
TEST_CASE(SUITE("10can select beyond the first entry"))
{
    const auto other_variation = StaticBinaryVariation::Group1Var1;

    REQUIRE(BinarySpec::DefaultStaticVariation != other_variation);

    StaticDataMap<BinarySpec> map{{
        {1, {}},
        {3, {}},
        {7, {}},
    }};

    REQUIRE(map.select(Range::From(3, 8)) == 2);

    std::vector<StaticDataMap<BinarySpec>::iterator::value_type> items;
    for (const auto& item : map)
    {
        items.push_back(item);
    }

    REQUIRE(items.size() == 2);
    REQUIRE(items[0].first == 3);
    REQUIRE(items[1].first == 7);
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

