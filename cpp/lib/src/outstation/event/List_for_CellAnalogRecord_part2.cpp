#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "List_for_CellAnalogRecord.h"

//void clear_in_EventStorage(CellAnalogRecord* record)
//      Foreach_in_List_for_CellAnalogRecord(&((pEventStorage->state).events), clear_in_EventStorage);
////template<class T> template<class U> void List<T>::Foreach(const U& action)
void    Foreach_in_List_for_CellAnalogRecord(List_for_CellAnalogRecord *pList_for_CellAnalogRecord, void (*action)(CellAnalogRecord* record))
//&((pEventStorage->state).events), clear_in_EventStorage);
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"Foreach_in_List_for_CellAnalogRecord1"<<'\n';
#endif
////    auto iter = this->Iterate();
  Iterator_in_List_for_CellAnalogRecord iter = Iterate_in_List_for_CellAnalogRecord(pList_for_CellAnalogRecord);
////    while (iter.HasNext())
  while (HasNext__in__Iterator_in_List_for_CellAnalogRecord(&iter))
  {
////        action(iter.Next()->value);
    Node_for_CellAnalogRecord* current = Next__in__Iterator_in_List_for_CellAnalogRecord(&iter);
    action(&(current->value));
  }
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
}

/*
uint32_t RemoveAll_in_List_for_CellAnalogRecord(EventStorage *pEventStorage,
    List_for_CellAnalogRecord *pList_for_CellAnalogRecord,
    boolean (*match)(EventStorage *pEventStorage, CellAnalogRecord* record))
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"RemoveAll_in_List_for_CellAnalogRecord1"<<'\n';
#endif

  uint32_t count = 0;

////    auto iter = this->Iterate();
////    auto current = iter.Next();
  Iterator_in_List_for_CellAnalogRecord iter = Iterate_in_List_for_CellAnalogRecord(pList_for_CellAnalogRecord);
//        auto node = iter.Next();
  Node_for_CellAnalogRecord* current = Next__in__Iterator_in_List_for_CellAnalogRecord(&iter);

  while (current)
  {
////        if (match(current->value))
    if (match(pEventStorage, &(current->value)))
    {
////            auto removed = current;
      Node_for_CellAnalogRecord* removed = current;
////            current = iter.Next();
      current = Next__in__Iterator_in_List_for_CellAnalogRecord(&iter);
////            this->Remove(removed);
//   void Remove_in_List_for_CellAnalogRecord(List_for_CellAnalogRecord *pList_for_CellAnalogRecord, Node_for_CellAnalogRecord* node);
      Remove_in_List_for_CellAnalogRecord(pList_for_CellAnalogRecord, removed);
      ++count;
    }
    else
    {
////            current = iter.Next();
      current = Next__in__Iterator_in_List_for_CellAnalogRecord(&iter);
    }
  }

#ifdef  LOG_INFO
  decrement_stack_info();
#endif
  return count;
}
*/
