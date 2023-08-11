#ifndef OPENDNP3_NODE_TypedEventRecord_for_BinarySpec_H
#define OPENDNP3_NODE_TypedEventRecord_for_BinarySpec_H

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
  TypedEventRecord_for_BinarySpec value;

////private:
////    Node* prev = nullptr;
////    Node_TypedEventRecord_for_BinarySpec * prev;
  void * prev;
////    Node_TypedEventRecord_for_BinarySpec * next;
  void * next;
////    Node* next = nullptr;

////    template<class U> friend class List;
} Node_TypedEventRecord_for_BinarySpec;

void Node_TypedEventRecord_for_BinarySpec_in_Node_TypedEventRecord_for_BinarySpec(
  Node_TypedEventRecord_for_BinarySpec *pNode_TypedEventRecord_for_BinarySpec);
#endif
