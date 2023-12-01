#include "header.h"
#include "EventLists.h"
#include "List_TypedEventRecord_for_OctetStringSpec.h"

void  ForeachWhile_in_List_TypedEventRecord_for_OctetStringSpec(List_TypedEventRecord_for_OctetStringSpec *pList_TypedEventRecord_for_OctetStringSpec,
    EventLists* lists,
    /*uint32_t num_selected,*/ uint32_t maxEv,
    event_variation_t_in_BinaryInfo variation,
    boolean useDefaultVariation,
//    boolean (*select_match)(EventLists* lists, TypedEventRecord_for_OctetStringSpec* node, uint32_t num_selected, uint32_t maxEv, event_variation_t_in_BinaryInfo variation))
    boolean (*select_match)(EventLists* lists,
                            TypedEventRecord_for_OctetStringSpec* node,
                            /*uint32_t num_selected,*/ uint32_t maxEv,
                            event_variation_t_in_OctetStringInfo variation,
                            boolean useDefaultVariation))
{
////    auto iter = this->Iterate();
  Iterator_in_List_TypedEventRecord_for_OctetStringSpec iter = Iterate_in_List_TypedEventRecord_for_OctetStringSpec(pList_TypedEventRecord_for_OctetStringSpec);
  boolean result = true;
////    while (result && iter.HasNext())
//boolean HasNext__in__Iterator_in_List_TypedEventRecord_for_OctetStringSpec(Iterator_in_List_TypedEventRecord_for_OctetStringSpec *pIterator_in_List_TypedEventRecord_for_OctetStringSpec);
  while (result &&
         HasNext__in__Iterator_in_List_TypedEventRecord_for_OctetStringSpec(&iter)
        )
  {
//Node_TypedEventRecord_for_OctetStringSpec* Next__in__Iterator_in_List_TypedEventRecord_for_OctetStringSpec(Iterator_in_List_TypedEventRecord_for_OctetStringSpec *pIterator_in_List_TypedEventRecord_for_OctetStringSpec);
    Node_TypedEventRecord_for_OctetStringSpec* node = Next__in__Iterator_in_List_TypedEventRecord_for_OctetStringSpec(&iter);
////        result = select(iter.Next()->value);
    result = select_match(lists,
                          &(node->value),
                          /*num_selected,*/ maxEv, variation,
                          useDefaultVariation
                         );
  }
}
