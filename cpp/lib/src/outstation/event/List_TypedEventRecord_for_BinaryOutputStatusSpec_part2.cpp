#include "header.h"
#include "EventLists.h"
#include "List_TypedEventRecord_for_BinaryOutputStatusSpec.h"

void  ForeachWhile_in_List_TypedEventRecord_for_BinaryOutputStatusSpec(List_TypedEventRecord_for_BinaryOutputStatusSpec *pList_TypedEventRecord_for_BinaryOutputStatusSpec,
    EventLists* lists,
    uint32_t num_selected, uint32_t maxEv,
    event_variation_t_in_BinaryInfo variation,
    boolean useDefaultVariation,
//    boolean (*select_match)(EventLists* lists, TypedEventRecord_for_BinaryOutputStatusSpec* node, uint32_t num_selected, uint32_t maxEv, event_variation_t_in_BinaryInfo variation))
    boolean (*select_match)(EventLists* lists,
                            TypedEventRecord_for_BinaryOutputStatusSpec* node,
                            uint32_t num_selected, uint32_t maxEv,
                            event_variation_t_in_BinaryOutputStatusInfo variation,
                            boolean useDefaultVariation))
{
////    auto iter = this->Iterate();
  Iterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec iter = Iterate_in_List_TypedEventRecord_for_BinaryOutputStatusSpec(pList_TypedEventRecord_for_BinaryOutputStatusSpec);
  boolean result = true;
////    while (result && iter.HasNext())
//boolean HasNext__in__Iterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec(Iterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec *pIterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec);
  while (result &&
         HasNext__in__Iterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec(&iter)
        )
  {
//Node_TypedEventRecord_for_BinaryOutputStatusSpec* Next__in__Iterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec(Iterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec *pIterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec);
    Node_TypedEventRecord_for_BinaryOutputStatusSpec* node = Next__in__Iterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec(&iter);
////        result = select(iter.Next()->value);
    result = select_match(lists,
                          &(node->value),
                          num_selected, maxEv, variation,
                          useDefaultVariation
                         );
  }
}
