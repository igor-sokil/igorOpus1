#ifndef OPENDNP3_NODE_TypedEventRecord_for_DoubleBitBinarySpec_H
#define OPENDNP3_NODE_TypedEventRecord_for_DoubleBitBinarySpec_H

//#include "HasLength.h"
#include "TypedEventRecord.h"
////#include <ser4cpp/container/Array.h>

////#include <cstdint>

//#include "EventStorage.h"
////namespace opendnp3
////{

////using list_size_type_t = uint32_t;

////template<class T> class Node
typedef struct
{
////public:
////    Node() = default;

////    T value;
  TypedEventRecord_for_DoubleBitBinarySpec value;

////private:
////    Node* prev = nullptr;
////    Node_TypedEventRecord_for_DoubleBitBinarySpec * prev;
  void * prev;
////    Node_TypedEventRecord_for_DoubleBitBinarySpec * next;
  void * next;
////    Node* next = nullptr;

////    template<class U> friend class List;
} Node_TypedEventRecord_for_DoubleBitBinarySpec;

void Node_TypedEventRecord_for_DoubleBitBinarySpec_in_Node_TypedEventRecord_for_DoubleBitBinarySpec(
                    Node_TypedEventRecord_for_DoubleBitBinarySpec *pNode_TypedEventRecord_for_DoubleBitBinarySpec);
#endif
