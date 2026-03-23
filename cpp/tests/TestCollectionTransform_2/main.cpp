
#include <QApplication>
#include <QtWidgets>

#include <stdlib.h>
#include <iostream>
#include <string>

#include "MainWindow.h"
#include "key_filter.h"

#include "header.h"

#include "log_info.h"
//#ifdef  LOG_INFO
//#include <iostream>
//#endif
//#include "OutstationConfig.h"
//#include "Collections.h"
#include "Collections_for_uint32.h"
#include "TransformedCollection_for_uint32.h"

#define UNUSED(x) (void)(x)

key_filter *pkf;

MainWindow *mainWindow;

////    auto greaterThanTwo = [](const int& x) -> bool 
   uint32_t greaterThanTwo(uint32_t x);
   uint32_t greaterThanTwo(uint32_t x)
    {
#ifdef  LOG_INFO
        std::cout<<'\n';
        increment_stack_info();
        std::cout<<getString_stack_info();
        std::cout<<"{greaterThanTwo1"<<'\n';
#endif
#ifdef  LOG_INFO
        std::cout<<getString_stack_info();
        std::cout<<"}greaterThanTwo_"<<'\n';
        decrement_stack_info();
#endif
////      return x > 2; 
        if(x > (uint32_t)2) return 1;
        return 0;
    };

////    std::vector<bool> items;
    std::vector<uint32_t> items;
    void fillVector(uint32_t item);

    void fillVector(uint32_t item)
     { 
#ifdef  LOG_INFO
        std::cout<<'\n';
        increment_stack_info();
        std::cout<<getString_stack_info();
        std::cout<<"{fillVector1"<<'\n';
#endif
//       qDebug()<<"item="<<item;
       std::cout<<getString_stack_info();
       std::cout<<"item= "<<item<<'\n';
       items.push_back(item);

#ifdef  LOG_INFO
        std::cout<<getString_stack_info();
        std::cout<<"}fillVector_"<<'\n';
        decrement_stack_info();
#endif
    };

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);

qDebug()<<"********SUITE('MapIntegers2Booleans')********";

    uint32_t values[4] = {1, 2, 3, 4};
//void ArrayCollection_for_uint32_in_ArrayCollection_for_uint32(ArrayCollection_for_uint32 *pArrayCollection_for_uint32, 
//                      uint32_t* pArray_, uint16_t  cnt);
////    ArrayCollection<int> collectionInt(values, 4);
    ArrayCollection_for_uint32 collectionInt;
    ArrayCollection_for_uint32_in_ArrayCollection_for_uint32(&collectionInt, 
                      values, 4);

//TransformedCollection_for_uint32 Map_for_uint32(ICollection_for_uint32 *input, uint32_t (*transform)(uint32_t));
////    auto collectionBool = Map<int, bool>(collectionInt, greaterThanTwo);
TransformedCollection_for_uint32 collectionBool = Map_for_uint32(&(collectionInt.iICollection_for_uint32), greaterThanTwo);//uint32_t (*transform)(uint32_t));

//static void * pPointerGlobal1_in_TestTransformedCollection;
////    auto fillVector = [&items](const bool& item) 
//void ForeachItem_in_ICollection_for_uint32(ICollection_for_uint32 *pICollection_for_uint32, void (*fun)(uint32_t* item));
////    collectionBool.ForeachItem(fillVector);
 ForeachItem_in_ICollection_for_uint32(&(collectionBool.iICollection_for_uint32), fillVector);//void (*fun)(uint32_t* item));
///*
qDebug()<<"REQUIRE(items.size() == 4)";
qDebug()<<"items.size() == 4  "<<items.size();

////    REQUIRE_FALSE(items[0]);
qDebug()<<"REQUIRE_FALSE(items[0])";
qDebug()<<"items[0]  "<<items[0];

////    REQUIRE_FALSE(items[1]);
qDebug()<<"REQUIRE_FALSE(items[1])";
qDebug()<<"items[1]  "<<items[1];

////    REQUIRE(items[2]);
qDebug()<<"REQUIRE(items[2])";
qDebug()<<"items[2]  "<<items[2];

////    REQUIRE(items[3]);
qDebug()<<"REQUIRE(items[3])";
qDebug()<<"items[3]  "<<items[3];
//*/
/*
TEST_CASE(SUITE("Map integers to booleans"))
{
    int values[4] = {1, 2, 3, 4};
    ArrayCollection<int> collectionInt(values, 4);
    auto greaterThanTwo = [](const int& x) -> bool { return x > 2; };
    auto collectionBool = Map<int, bool>(collectionInt, greaterThanTwo);

    std::vector<bool> items;
    auto fillVector = [&items](const bool& item) { items.push_back(item); };
    collectionBool.ForeachItem(fillVector);

    REQUIRE(items.size() == 4);
    REQUIRE_FALSE(items[0]);
    REQUIRE_FALSE(items[1]);
    REQUIRE(items[2]);
    REQUIRE(items[3]);
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

