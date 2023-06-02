#include "header.h"
#include "EventLists.h"
#include "List_TypedEventRecord_for_AnalogOutputStatusSpec.h"

void  ForeachWhile_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(List_TypedEventRecord_for_AnalogOutputStatusSpec *pList_TypedEventRecord_for_AnalogOutputStatusSpec,
    EventLists* lists,
    uint32_t num_selected, uint32_t maxEv,
    event_variation_t_in_BinaryInfo variation,
    boolean useDefaultVariation,
//    boolean (*select_match)(EventLists* lists, TypedEventRecord_for_AnalogOutputStatusSpec* node, uint32_t num_selected, uint32_t maxEv, event_variation_t_in_BinaryInfo variation))
boolean (*select_match)(EventLists* lists,
    TypedEventRecord_for_AnalogOutputStatusSpec* node,
    uint32_t num_selected, uint32_t maxEv,
    event_variation_t_in_AnalogOutputStatusInfo variation,
    boolean useDefaultVariation))
{
////    auto iter = this->Iterate();
  Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec iter = Iterate_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(pList_TypedEventRecord_for_AnalogOutputStatusSpec);
  boolean result = true;
////    while (result && iter.HasNext())
//boolean HasNext__in__Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec *pIterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec);
  while (result &&
         HasNext__in__Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(&iter)
        )
  {
//Node_TypedEventRecord_for_AnalogOutputStatusSpec* Next__in__Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec *pIterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec);
    Node_TypedEventRecord_for_AnalogOutputStatusSpec* node = Next__in__Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(&iter);
////        result = select(iter.Next()->value);
    result = select_match(lists,
                          &(node->value),
                          num_selected, maxEv, variation,
                          useDefaultVariation
                         );
  }
}
