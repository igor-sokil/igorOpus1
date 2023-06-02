#include "header.h"
#include "EventLists.h"
#include "List_TypedEventRecord_for_BinarySpec.h"

void  ForeachWhile_in_List_TypedEventRecord_for_BinarySpec(List_TypedEventRecord_for_BinarySpec *pList_TypedEventRecord_for_BinarySpec,
    EventLists* lists,
    uint32_t num_selected, uint32_t maxEv,
    event_variation_t_in_BinaryInfo variation,
    boolean useDefaultVariation,
//    boolean (*select_match)(EventLists* lists, TypedEventRecord_for_BinarySpec* node, uint32_t num_selected, uint32_t maxEv, event_variation_t_in_BinaryInfo variation))
boolean (*select_match)(EventLists* lists,
    TypedEventRecord_for_BinarySpec* node,
    uint32_t num_selected, uint32_t maxEv,
    event_variation_t_in_BinaryInfo variation,
    boolean useDefaultVariation))
{
////    auto iter = this->Iterate();
  Iterator_in_List_TypedEventRecord_for_BinarySpec iter = Iterate_in_List_TypedEventRecord_for_BinarySpec(pList_TypedEventRecord_for_BinarySpec);
  boolean result = true;
////    while (result && iter.HasNext())
//boolean HasNext__in__Iterator_in_List_TypedEventRecord_for_BinarySpec(Iterator_in_List_TypedEventRecord_for_BinarySpec *pIterator_in_List_TypedEventRecord_for_BinarySpec);
  while (result &&
         HasNext__in__Iterator_in_List_TypedEventRecord_for_BinarySpec(&iter)
        )
  {
//Node_TypedEventRecord_for_BinarySpec* Next__in__Iterator_in_List_TypedEventRecord_for_BinarySpec(Iterator_in_List_TypedEventRecord_for_BinarySpec *pIterator_in_List_TypedEventRecord_for_BinarySpec);
    Node_TypedEventRecord_for_BinarySpec* node = Next__in__Iterator_in_List_TypedEventRecord_for_BinarySpec(&iter);
////        result = select(iter.Next()->value);
    result = select_match(lists,
                          &(node->value),
                          num_selected, maxEv, variation,
                          useDefaultVariation
                         );
  }
}
