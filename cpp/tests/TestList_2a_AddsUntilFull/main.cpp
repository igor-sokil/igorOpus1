
#include <QApplication>
#include <QtWidgets>

#include <stdlib.h>
#include <iostream>
#include <string>

#include "MainWindow.h"
#include "key_filter.h"

#include "header.h"
#include "List_for_CellAnalogRecord.h"
//#include "ProtocolUtil.h"

#define UNUSED(x) (void)(x)

key_filter *pkf;

MainWindow *mainWindow;

#define SFIFT_PARAM_INTERNAL_BITS       31
#define SFIFT_PARAM_ID                  24
#define SFIFT_PARAM_N                   16
#define SFIFT_PARAM_OUT                 0

#define MASKA_PARAM_ID                  ((1 << (SFIFT_PARAM_INTERNAL_BITS - SFIFT_PARAM_ID            )) - 1)

#define ID_FB_EVENT_LOG  18

uint32_t insideOutherID(uint16_t outher);
uint32_t outherInsideID(uint16_t inside);
uint32_t insideOutherID(uint16_t outher)
{
 switch(outher)
 {
  case 21: return ID_FB_EVENT_LOG;
 }
 return outher;
}
uint32_t outherInsideID(uint16_t inside)
{
 switch(inside)
 {
  case ID_FB_EVENT_LOG: return 21;
 }
 return inside;
}

uint32_t readIDConverter(uint32_t inParam);
uint32_t readIDConverter(uint32_t inParam)
{
  uint32_t inID = (inParam >> SFIFT_PARAM_ID) & MASKA_PARAM_ID;
  uint32_t outherID = outherInsideID(inID);
  //замінити ID
  inParam &= (uint32_t)~(MASKA_PARAM_ID << SFIFT_PARAM_ID );
  inParam |= (outherID << SFIFT_PARAM_ID);
  return inParam;
}

void writeIDConverter(uint32_t *pInParam);
void writeIDConverter(uint32_t *pInParam)
{
  uint32_t inParam = *pInParam;
  uint32_t inID = (inParam >> SFIFT_PARAM_ID) & MASKA_PARAM_ID;
  uint32_t insideID = insideOutherID(inID);
  //замінити ID
  inParam &= (uint32_t)~(MASKA_PARAM_ID << SFIFT_PARAM_ID );
  inParam |= (insideID << SFIFT_PARAM_ID);
  *pInParam = inParam;
}

boolean findIndex_for_iter2(CellAnalogRecord* pCellAnalogRecord, uint16_t index);
boolean findIndex_for_iter2(CellAnalogRecord* pCellAnalogRecord, uint16_t index)
{
 if(pCellAnalogRecord->index == index) return true;
 return false;
}
int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);

//  uint32_t id_EVENT_LOG18 = (ID_FB_EVENT_LOG << SFIFT_PARAM_ID );// & MASKA_PARAM_ID ;
//  std::cout<<"id_EVENT_LOG18= "<<(uint32_t)id_EVENT_LOG18<<std::endl;
//  std::cout<<"MASKA_PARAM_ID= "<<(uint32_t)MASKA_PARAM_ID<<std::endl;

  uint32_t id_EVENT_LOG18 = (/*ID_FB_EVENT_LOG*/21 << SFIFT_PARAM_ID ) & (MASKA_PARAM_ID << SFIFT_PARAM_ID ) ;
  id_EVENT_LOG18 |= 0x80000000;
  std::cout<<"id_EVENT_LOG18= "<<(uint32_t)id_EVENT_LOG18<<std::endl;
  std::cout<<"MASKA_PARAM_ID= "<<(uint32_t)MASKA_PARAM_ID<<std::endl;

  uint32_t inParam = id_EVENT_LOG18 | 0x00FFFFFF;

//uint32_t ttt = 
  writeIDConverter(&inParam);
  std::cout<<"ttt= "<<(uint32_t)inParam<<std::endl;

qDebug()<<"********SUITE('2a_AddsUntilFull')********";
////    List<int> list(3);
////    REQUIRE(list.Add(1));
////    REQUIRE(list.Add(2));
////    REQUIRE(list.Add(3));
////    REQUIRE(list.IsFullAndCapacityNotZero());
    // adding to a full list returns a nullptr
////    REQUIRE_FALSE(list.Add(4));

////    List<int> list(3);
 List_for_CellAnalogRecord list;
 List_for_CellAnalogRecord_in_List_for_CellAnalogRecordOver2(&list, 3);

//Node_for_int* Add_in_List_for_int(List_for_int *pList_for_int, int* value);
////    REQUIRE(list.Add(1));
CellAnalogRecord user1;// = 1;
user1.index = 3;
Node_for_CellAnalogRecord* ptmp = Add_in_List_for_CellAnalogRecord(&list, &user1);
  qDebug()<<"REQUIRE(list.Add(1))";
  std::cout<<"ptmp= "<<(uint32_t)ptmp<<std::endl;

////    REQUIRE(list.Add(2));
CellAnalogRecord user2;// = 2;
user2.index = 5;
  ptmp = Add_in_List_for_CellAnalogRecord(&list, &user2);
  qDebug()<<"REQUIRE(list.Add(2))";
  std::cout<<"ptmp= "<<(uint32_t)ptmp<<std::endl;

////    REQUIRE(list.Add(3));
CellAnalogRecord user3;// = 3;
user3.index = 7;
  ptmp = Add_in_List_for_CellAnalogRecord(&list, &user3);
  qDebug()<<"REQUIRE(list.Add(3))";
  std::cout<<"ptmp= "<<(uint32_t)ptmp<<std::endl;

//boolean IsFullAndCapacityNotZero_in_List_for_int(List_for_int *pList_for_int);
////    REQUIRE(list.IsFullAndCapacityNotZero());
boolean btmp = IsFullAndCapacityNotZero_in_List_for_CellAnalogRecord(&list);
  qDebug()<<"REQUIRE(list.IsFullAndCapacityNotZero())";
  std::cout<<"btmp= "<<(uint32_t)btmp<<std::endl;

////    REQUIRE_FALSE(list.Add(4));
CellAnalogRecord user4;// = 4;
user4.index = 8;
  ptmp = Add_in_List_for_CellAnalogRecord(&list, &user4);
  qDebug()<<"REQUIRE_FALSE(list.Add(4))";
  std::cout<<"ptmp= "<<(uint32_t)ptmp<<std::endl;

//UserRecord *Find__in__Iterator_in_List_for_UserRecord(Iterator_in_List_for_UserRecord *pIterator_in_List_for_UserRecord,
//    boolean (*matches)(UserRecord* pUserRecord))
//UserRecord *user5 = Find__in__Iterator_in_List_for_UserRecord(Iterator_in_List_for_UserRecord *pIterator_in_List_for_UserRecord,
//    boolean (*matches)(UserRecord* pUserRecord))
Iterator_in_List_for_CellAnalogRecord iter1 = Iterate_in_List_for_CellAnalogRecord(&list);

    for (int i = 1; i < 6; ++i)
    {
//boolean HasNext__in__Iterator_in_List_for_int(Iterator_in_List_for_int *pIterator_in_List_for_int);
////        REQUIRE(iter.HasNext());
boolean btmp = HasNext__in__Iterator_in_List_for_CellAnalogRecord(&iter1);
  qDebug()<<"REQUIRE(iter.HasNext())";
  std::cout<<"btmp= "<<btmp<<std::endl;

  if(!btmp) break;

//Node_for_int* Next__in__Iterator_in_List_for_int(Iterator_in_List_for_int *pIterator_in_List_for_int);
////        REQUIRE(i == iter.Next()->value);
Node_for_CellAnalogRecord* ntmp = Next__in__Iterator_in_List_for_CellAnalogRecord(&iter1);
  qDebug()<<"REQUIRE(i == iter.Next()->value)";
  std::cout<<"ntmp->value.index= "<<ntmp->value.index<<std::endl;
    }

boolean btmp2 = HasNext__in__Iterator_in_List_for_CellAnalogRecord(&iter1);
  qDebug()<<"REQUIRE(iter.HasNext())";
  std::cout<<"btmp= "<<btmp2<<std::endl;

Iterator_in_List_for_CellAnalogRecord iter2 = Iterate_in_List_for_CellAnalogRecord(&list);

//CellAnalogRecord *Find__in__Iterator_in_List_for_CellAnalogRecord(Iterator_in_List_for_CellAnalogRecord *pIterator_in_List_for_CellAnalogRecord,
//    uint16_t index,
//    boolean (*matches)(CellAnalogRecord* pCellAnalogRecord))
CellAnalogRecord *fnd = Find__in__Iterator_in_List_for_CellAnalogRecord(&iter2, 5,
    findIndex_for_iter2);

  std::cout<<"CellAnalogRecord *fnd= "<<(uint32_t) fnd<<std::endl;
 if(fnd != NULL)
 {
  std::cout<<"CellAnalogRecord *fnd->index= "<<(uint32_t) fnd->index<<std::endl;
 }

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

