
#include <QApplication>
#include <QtWidgets>

#include <stdlib.h>
#include <iostream>
#include <string>

#include "MainWindow.h"
#include "key_filter.h"

#include "header.h"
#include "List_for_UserRecord.h"
//#include "ProtocolUtil.h"

#define UNUSED(x) (void)(x)

key_filter *pkf;

MainWindow *mainWindow;

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);

qDebug()<<"********SUITE('2_AddsUntilFull')********";
////    List<int> list(3);
////    REQUIRE(list.Add(1));
////    REQUIRE(list.Add(2));
////    REQUIRE(list.Add(3));
////    REQUIRE(list.IsFullAndCapacityNotZero());
    // adding to a full list returns a nullptr
////    REQUIRE_FALSE(list.Add(4));

////    List<int> list(3);
 List_for_UserRecord list;
 List_for_UserRecord_in_List_for_UserRecordOver2(&list, 3);

//Node_for_int* Add_in_List_for_int(List_for_int *pList_for_int, int* value);
////    REQUIRE(list.Add(1));
UserRecord user1;// = 1;
user1.index = 5;
Node_for_UserRecord* ptmp = Add_in_List_for_UserRecord(&list, &user1);
  qDebug()<<"REQUIRE(list.Add(1))";
  std::cout<<"ptmp= "<<(uint32_t)ptmp<<std::endl;

////    REQUIRE(list.Add(2));
UserRecord user2;// = 2;
user2.index = 6;
  ptmp = Add_in_List_for_UserRecord(&list, &user2);
  qDebug()<<"REQUIRE(list.Add(2))";
  std::cout<<"ptmp= "<<(uint32_t)ptmp<<std::endl;

////    REQUIRE(list.Add(3));
UserRecord user3;// = 3;
user3.index = 7;
  ptmp = Add_in_List_for_UserRecord(&list, &user3);
  qDebug()<<"REQUIRE(list.Add(3))";
  std::cout<<"ptmp= "<<(uint32_t)ptmp<<std::endl;

//boolean IsFullAndCapacityNotZero_in_List_for_int(List_for_int *pList_for_int);
////    REQUIRE(list.IsFullAndCapacityNotZero());
boolean btmp = IsFullAndCapacityNotZero_in_List_for_UserRecord(&list);
  qDebug()<<"REQUIRE(list.IsFullAndCapacityNotZero())";
  std::cout<<"btmp= "<<(uint32_t)btmp<<std::endl;

////    REQUIRE_FALSE(list.Add(4));
UserRecord user4;// = 4;
user4.index = 8;
  ptmp = Add_in_List_for_UserRecord(&list, &user4);
  qDebug()<<"REQUIRE_FALSE(list.Add(4))";
  std::cout<<"ptmp= "<<(uint32_t)ptmp<<std::endl;

//UserRecord *Find__in__Iterator_in_List_for_UserRecord(Iterator_in_List_for_UserRecord *pIterator_in_List_for_UserRecord,
//    boolean (*matches)(UserRecord* pUserRecord))
//UserRecord *user5 = Find__in__Iterator_in_List_for_UserRecord(Iterator_in_List_for_UserRecord *pIterator_in_List_for_UserRecord,
//    boolean (*matches)(UserRecord* pUserRecord))
Iterator_in_List_for_UserRecord iter = Iterate_in_List_for_UserRecord(&list);

    for (int i = 1; i < 6; ++i)
    {
//boolean HasNext__in__Iterator_in_List_for_int(Iterator_in_List_for_int *pIterator_in_List_for_int);
////        REQUIRE(iter.HasNext());
boolean btmp = HasNext__in__Iterator_in_List_for_UserRecord(&iter);
  qDebug()<<"REQUIRE(iter.HasNext())";
  std::cout<<"btmp= "<<btmp<<std::endl;

  if(!btmp) break;

//Node_for_int* Next__in__Iterator_in_List_for_int(Iterator_in_List_for_int *pIterator_in_List_for_int);
////        REQUIRE(i == iter.Next()->value);
Node_for_UserRecord* ntmp = Next__in__Iterator_in_List_for_UserRecord(&iter);
  qDebug()<<"REQUIRE(i == iter.Next()->value)";
  std::cout<<"iter.Next()->value= "<<ntmp->value.index<<std::endl;
    }

boolean btmp2 = HasNext__in__Iterator_in_List_for_UserRecord(&iter);
  qDebug()<<"REQUIRE(iter.HasNext())";
  std::cout<<"btmp= "<<btmp2<<std::endl;

/*
TEST_CASE(SUITE("2AddsUntilFull"))
{
    List<int> list(3);

    REQUIRE(list.Add(1));
    REQUIRE(list.Add(2));
    REQUIRE(list.Add(3));

    REQUIRE(list.IsFullAndCapacityNotZero());

    // adding to a full list returns a nullptr
    REQUIRE_FALSE(list.Add(4));
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

