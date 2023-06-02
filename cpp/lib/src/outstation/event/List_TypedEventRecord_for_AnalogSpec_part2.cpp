#include "header.h"
#include "EventLists.h"
#include "List_TypedEventRecord_for_AnalogSpec.h"

void  ForeachWhile_in_List_TypedEventRecord_for_AnalogSpec(List_TypedEventRecord_for_AnalogSpec *pList_TypedEventRecord_for_AnalogSpec,
    EventLists* lists,
    uint32_t num_selected, uint32_t maxEv,
    event_variation_t_in_BinaryInfo variation,
    boolean useDefaultVariation,
//    boolean (*select_match)(EventLists* lists, TypedEventRecord_for_AnalogSpec* node, uint32_t num_selected, uint32_t maxEv, event_variation_t_in_BinaryInfo variation))
boolean (*select_match)(EventLists* lists,
    TypedEventRecord_for_AnalogSpec* node,
    uint32_t num_selected, uint32_t maxEv,
    event_variation_t_in_AnalogInfo variation,
    boolean useDefaultVariation))
{
////    auto iter = this->Iterate();
  Iterator_in_List_TypedEventRecord_for_AnalogSpec iter = Iterate_in_List_TypedEventRecord_for_AnalogSpec(pList_TypedEventRecord_for_AnalogSpec);
  boolean result = true;
////    while (result && iter.HasNext())
//boolean HasNext__in__Iterator_in_List_TypedEventRecord_for_AnalogSpec(Iterator_in_List_TypedEventRecord_for_AnalogSpec *pIterator_in_List_TypedEventRecord_for_AnalogSpec);
  while (result &&
         HasNext__in__Iterator_in_List_TypedEventRecord_for_AnalogSpec(&iter)
        )
  {
//Node_TypedEventRecord_for_AnalogSpec* Next__in__Iterator_in_List_TypedEventRecord_for_AnalogSpec(Iterator_in_List_TypedEventRecord_for_AnalogSpec *pIterator_in_List_TypedEventRecord_for_AnalogSpec);
    Node_TypedEventRecord_for_AnalogSpec* node = Next__in__Iterator_in_List_TypedEventRecord_for_AnalogSpec(&iter);
////        result = select(iter.Next()->value);
    result = select_match(lists,
                          &(node->value),
                          num_selected, maxEv, variation,
                          useDefaultVariation
                         );
  }
}
