
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

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);

qDebug()<<"********SUITE('8CanIterateOverValues')********";
////    List<int> list(3);
////    list.Add(1);
////    list.Add(2);
////    list.Add(3);
////    auto iter = list.Iterate();
////    for (int i = 1; i < 4; ++i)
////    {
////        REQUIRE(iter.HasNext());
////        REQUIRE(i == iter.Next()->value);
////    }
////    REQUIRE(!iter.HasNext());

////    List<int> list(10);
 List_for_int list;
 List_for_int_in_List_for_intOver2(&list, 10);

////    list.Add(1);
int int1 = 1;
Node_for_int*  ptmp = Add_in_List_for_int(&list, &int1);
  std::cout<<"ptmp= "<<ptmp<<std::endl;

////    list.Add(2);
int int2 = 2;
  ptmp = Add_in_List_for_int(&list, &int2);
  std::cout<<"ptmp= "<<ptmp<<std::endl;

////    REQUIRE(list.Add(3));
int int3 = 3;
  ptmp = Add_in_List_for_int(&list, &int3);
  std::cout<<"ptmp= "<<ptmp<<std::endl;

//Iterator_in_List_for_int Iterate_in_List_for_int(List_for_int *pList_for_int);
////    auto iter = list.Iterate();
Iterator_in_List_for_int iter = Iterate_in_List_for_int(&list);

    for (int i = 1; i < 4; ++i)
    {
//boolean HasNext__in__Iterator_in_List_for_int(Iterator_in_List_for_int *pIterator_in_List_for_int);
////        REQUIRE(iter.HasNext());
boolean btmp = HasNext__in__Iterator_in_List_for_int(&iter);
  qDebug()<<"REQUIRE(iter.HasNext())";
  std::cout<<"btmp= "<<btmp<<std::endl;

//Node_for_int* Next__in__Iterator_in_List_for_int(Iterator_in_List_for_int *pIterator_in_List_for_int);
////        REQUIRE(i == iter.Next()->value);
Node_for_int* ntmp = Next__in__Iterator_in_List_for_int(&iter);
  qDebug()<<"REQUIRE(i == iter.Next()->value)";
  std::cout<<"iter.Next()->value= "<<ntmp->value<<std::endl;
    }

/*
TEST_CASE(SUITE("8CanIterateOverValues"))
{
    List<int> list(3);

    list.Add(1);
    list.Add(2);
    list.Add(3);

    auto iter = list.Iterate();

    for (int i = 1; i < 4; ++i)
    {
        REQUIRE(iter.HasNext());
        REQUIRE(i == iter.Next()->value);
    }

    REQUIRE(!iter.HasNext());
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

