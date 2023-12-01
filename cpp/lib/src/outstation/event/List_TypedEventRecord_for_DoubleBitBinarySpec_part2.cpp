#include "header.h"
#include "EventLists.h"
#include "List_TypedEventRecord_for_DoubleBitBinarySpec.h"

void  ForeachWhile_in_List_TypedEventRecord_for_DoubleBitBinarySpec(List_TypedEventRecord_for_DoubleBitBinarySpec *pList_TypedEventRecord_for_DoubleBitBinarySpec,
    EventLists* lists,
    /*uint32_t num_selected,*/ uint32_t maxEv,
    event_variation_t_in_BinaryInfo variation,
    boolean useDefaultVariation,
//    boolean (*select_match)(EventLists* lists, TypedEventRecord_for_DoubleBitBinarySpec* node, uint32_t num_selected, uint32_t maxEv, event_variation_t_in_BinaryInfo variation))
    boolean (*select_match)(EventLists* lists,
                            TypedEventRecord_for_DoubleBitBinarySpec* node,
                            /*uint32_t num_selected,*/ uint32_t maxEv,
                            event_variation_t_in_DoubleBitBinaryInfo variation,
                            boolean useDefaultVariation))
{
////    auto iter = this->Iterate();
  Iterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec iter = Iterate_in_List_TypedEventRecord_for_DoubleBitBinarySpec(pList_TypedEventRecord_for_DoubleBitBinarySpec);
  boolean result = true;
////    while (result && iter.HasNext())
//boolean HasNext__in__Iterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec(Iterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec *pIterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec);
  while (result &&
         HasNext__in__Iterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec(&iter)
        )
  {
//Node_TypedEventRecord_for_DoubleBitBinarySpec* Next__in__Iterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec(Iterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec *pIterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec);
    Node_TypedEventRecord_for_DoubleBitBinarySpec* node = Next__in__Iterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec(&iter);
////        result = select(iter.Next()->value);
    result = select_match(lists,
                          &(node->value),
                          /*num_selected,*/ maxEv, variation,
                          useDefaultVariation
                         );
  }
}
