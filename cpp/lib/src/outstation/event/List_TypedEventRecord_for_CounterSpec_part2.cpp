#include "header.h"
#include "EventLists.h"
#include "List_TypedEventRecord_for_CounterSpec.h"

void  ForeachWhile_in_List_TypedEventRecord_for_CounterSpec(List_TypedEventRecord_for_CounterSpec *pList_TypedEventRecord_for_CounterSpec,
    EventLists* lists,
    uint32_t num_selected, uint32_t maxEv,
    event_variation_t_in_BinaryInfo variation,
    boolean useDefaultVariation,
//    boolean (*select_match)(EventLists* lists, TypedEventRecord_for_CounterSpec* node, uint32_t num_selected, uint32_t maxEv, event_variation_t_in_BinaryInfo variation))
    boolean (*select_match)(EventLists* lists,
                            TypedEventRecord_for_CounterSpec* node,
                            uint32_t num_selected, uint32_t maxEv,
                            event_variation_t_in_CounterInfo variation,
                            boolean useDefaultVariation))
{
////    auto iter = this->Iterate();
  Iterator_in_List_TypedEventRecord_for_CounterSpec iter = Iterate_in_List_TypedEventRecord_for_CounterSpec(pList_TypedEventRecord_for_CounterSpec);
  boolean result = true;
////    while (result && iter.HasNext())
//boolean HasNext__in__Iterator_in_List_TypedEventRecord_for_CounterSpec(Iterator_in_List_TypedEventRecord_for_CounterSpec *pIterator_in_List_TypedEventRecord_for_CounterSpec);
  while (result &&
         HasNext__in__Iterator_in_List_TypedEventRecord_for_CounterSpec(&iter)
        )
  {
//Node_TypedEventRecord_for_CounterSpec* Next__in__Iterator_in_List_TypedEventRecord_for_CounterSpec(Iterator_in_List_TypedEventRecord_for_CounterSpec *pIterator_in_List_TypedEventRecord_for_CounterSpec);
    Node_TypedEventRecord_for_CounterSpec* node = Next__in__Iterator_in_List_TypedEventRecord_for_CounterSpec(&iter);
////        result = select(iter.Next()->value);
    result = select_match(lists,
                          &(node->value),
                          num_selected, maxEv, variation,
                          useDefaultVariation
                         );
  }
}
