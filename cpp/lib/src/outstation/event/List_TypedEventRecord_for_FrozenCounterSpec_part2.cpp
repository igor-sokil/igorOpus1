#include "header.h"
#include "EventLists.h"
#include "List_TypedEventRecord_for_FrozenCounterSpec.h"

void  ForeachWhile_in_List_TypedEventRecord_for_FrozenCounterSpec(List_TypedEventRecord_for_FrozenCounterSpec *pList_TypedEventRecord_for_FrozenCounterSpec,
    EventLists* lists,
    /*uint32_t num_selected,*/ uint32_t maxEv,
    event_variation_t_in_BinaryInfo variation,
    boolean useDefaultVariation,
//    boolean (*select_match)(EventLists* lists, TypedEventRecord_for_FrozenCounterSpec* node, uint32_t num_selected, uint32_t maxEv, event_variation_t_in_BinaryInfo variation))
    boolean (*select_match)(EventLists* lists,
                            TypedEventRecord_for_FrozenCounterSpec* node,
                            /*uint32_t num_selected,*/ uint32_t maxEv,
                            event_variation_t_in_FrozenCounterInfo variation,
                            boolean useDefaultVariation))
{
////    auto iter = this->Iterate();
  Iterator_in_List_TypedEventRecord_for_FrozenCounterSpec iter = Iterate_in_List_TypedEventRecord_for_FrozenCounterSpec(pList_TypedEventRecord_for_FrozenCounterSpec);
  boolean result = true;
////    while (result && iter.HasNext())
//boolean HasNext__in__Iterator_in_List_TypedEventRecord_for_FrozenCounterSpec(Iterator_in_List_TypedEventRecord_for_FrozenCounterSpec *pIterator_in_List_TypedEventRecord_for_FrozenCounterSpec);
  while (result &&
         HasNext__in__Iterator_in_List_TypedEventRecord_for_FrozenCounterSpec(&iter)
        )
  {
//Node_TypedEventRecord_for_FrozenCounterSpec* Next__in__Iterator_in_List_TypedEventRecord_for_FrozenCounterSpec(Iterator_in_List_TypedEventRecord_for_FrozenCounterSpec *pIterator_in_List_TypedEventRecord_for_FrozenCounterSpec);
    Node_TypedEventRecord_for_FrozenCounterSpec* node = Next__in__Iterator_in_List_TypedEventRecord_for_FrozenCounterSpec(&iter);
////        result = select(iter.Next()->value);
    result = select_match(lists,
                          &(node->value),
                          /*num_selected,*/ maxEv, variation,
                          useDefaultVariation
                         );
  }
}
