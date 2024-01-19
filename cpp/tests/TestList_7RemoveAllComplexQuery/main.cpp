
#include <QApplication>
#include <QtWidgets>

#include <stdlib.h>
#include <iostream>
#include <string>

#include "MainWindow.h"
#include "key_filter.h"

#include "header.h"
#include "List_for_int.h"
//#include "ProtocolUtil.h"

#define UNUSED(x) (void)(x)

key_filter *pkf;

MainWindow *mainWindow;

boolean match_in_7RemoveAllComplexQuery (int num);
boolean match_in_7RemoveAllComplexQuery (int num)
{
////    auto isEven = [](int num) { return (num % 2) == 0; };
 return (num % 2) == 0;
}
void *pointerGlobal_in_7RemoveAllComplexQuery;
void action_in_7RemoveAllComplexQuery(int *num);
void action_in_7RemoveAllComplexQuery(int *num)
{
  std::vector<int>* remaining = (std::vector<int> *)pointerGlobal_in_7RemoveAllComplexQuery;
  remaining->push_back(*num);
}

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);

qDebug()<<"********SUITE('7RemoveAllComplexQuery')********";
////    List<int> list(10);
////    list.Add(2);
////    list.Add(3);
////    list.Add(4);
////    list.Add(7);
////    list.Add(20);
////    list.Add(8);
////    auto isEven = [](int num) { return (num % 2) == 0; };
////    auto count = list.RemoveAll(isEven);
////    REQUIRE(count == 4);
////    REQUIRE(list.length() == 2);

////    List<int> list(10);
 List_for_int list;
 List_for_int_in_List_for_intOver2(&list, 10);

////    list.Add(2);
int int2 = 2;
Node_for_int*  ptmp = Add_in_List_for_int(&list, &int2);
  std::cout<<"ptmp= "<<ptmp<<std::endl;

////    REQUIRE(list.Add(3));
int int3 = 3;
  ptmp = Add_in_List_for_int(&list, &int3);
  std::cout<<"ptmp= "<<ptmp<<std::endl;

////    auto four = list.Add(4);
int int4 = 4;
  ptmp = Add_in_List_for_int(&list, &int4);
  std::cout<<"ptmp= "<<ptmp<<std::endl;

int int7 = 7;
  ptmp = Add_in_List_for_int(&list, &int7);
  std::cout<<"ptmp= "<<ptmp<<std::endl;

int int20 = 20;
  ptmp = Add_in_List_for_int(&list, &int20);
  std::cout<<"ptmp= "<<ptmp<<std::endl;

int int8 = 8;
  ptmp = Add_in_List_for_int(&list, &int8);
  std::cout<<"ptmp= "<<ptmp<<std::endl;

////    auto isEven = [](int num) { return (num % 2) == 0; };
//uint16_t RemoveAll_in_List_for_int(List_for_int *pList_for_int, boolean (*match)(int));
////    auto count = list.RemoveAll(isEven);
uint16_t count = RemoveAll_in_List_for_int(&list, match_in_7RemoveAllComplexQuery);

////    REQUIRE(count == 4);
  qDebug()<<"REQUIRE(count == 4)";
  std::cout<<"count= "<<count<<std::endl;

////    REQUIRE(list.length() == 2);
boolean btmp = length_in_HasLength_for_Uint32_t(&(list.hHasLength_for_Uint32_t));
  qDebug()<<"REQUIRE(list.length() == 2)";
  std::cout<<"btmp= "<<btmp<<std::endl;

////    std::vector<int> remaining;
////    auto pushToVector = [&](int num) { remaining.push_back(num); };
////    list.Foreach(pushToVector);
////    REQUIRE(remaining.size() == 2);
////    REQUIRE(remaining[0] == 3);
////    REQUIRE(remaining[1] == 7);

    std::vector<int> remaining;
    pointerGlobal_in_7RemoveAllComplexQuery = &remaining;
////    auto pushToVector = [&](int num) { remaining.push_back(num); };
//void    Foreach_in_List_for_int(List_for_int *pList_for_int, void (*action)(int* record));
////    list.Foreach(pushToVector);
    Foreach_in_List_for_int(&list, action_in_7RemoveAllComplexQuery);

////    REQUIRE(remaining.size() == 2);
  qDebug()<<"REQUIRE(remaining.size() == 2)";
  std::cout<<"remaining.size()= "<<remaining.size()<<std::endl;

////    REQUIRE(remaining[0] == 3);
  qDebug()<<"REQUIRE(remaining[0] == 3)";
  std::cout<<"remaining[0]= "<<remaining[0]<<std::endl;
////    REQUIRE(remaining[1] == 7);
  qDebug()<<"REQUIRE(remaining[1] == 7)";
  std::cout<<"remaining[1]= "<<remaining[1]<<std::endl;

/*
TEST_CASE(SUITE("7RemoveAllComplexQuery"))
{
    List<int> list(10);

    list.Add(2);
    list.Add(3);
    list.Add(4);
    list.Add(7);
    list.Add(20);
    list.Add(8);

    auto isEven = [](int num) { return (num % 2) == 0; };
    auto count = list.RemoveAll(isEven);

    REQUIRE(count == 4);
    REQUIRE(list.length() == 2);

    std::vector<int> remaining;
    auto pushToVector = [&](int num) { remaining.push_back(num); };
    list.Foreach(pushToVector);

    REQUIRE(remaining.size() == 2);
    REQUIRE(remaining[0] == 3);
    REQUIRE(remaining[1] == 7);
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

