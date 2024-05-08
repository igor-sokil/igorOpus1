#ifndef OPENDNP3_NODE_for_CellAnalogRecord_H
#define OPENDNP3_NODE_for_CellAnalogRecord_H

//#include "HasLength.h"
//#include "int.h"
#include "CellAnalogRecord.h"

typedef struct
{
////public:
////    Node() = default;

////    T value;
  CellAnalogRecord value;

////private:
////    Node* prev = nullptr;
////    Node_for_int * prev;
  void * prev;
////    Node_for_int * next;
  void * next;
////    Node* next = nullptr;

////    template<class U> friend class List;
} Node_for_CellAnalogRecord;

void Node_for_CellAnalogRecord_in_Node_for_CellAnalogRecord(Node_for_CellAnalogRecord *pNode_for_CellAnalogRecord);
#endif
