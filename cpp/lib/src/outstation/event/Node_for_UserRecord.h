#ifndef OPENDNP3_NODE_for_UserRecord_H
#define OPENDNP3_NODE_for_UserRecord_H

//#include "HasLength.h"
//#include "int.h"
#include "UserRecord.h"

typedef struct
{
////public:
////    Node() = default;

////    T value;
  UserRecord value;

////private:
////    Node* prev = nullptr;
////    Node_for_int * prev;
  void * prev;
////    Node_for_int * next;
  void * next;
////    Node* next = nullptr;

////    template<class U> friend class List;
} Node_for_UserRecord;

void Node_for_UserRecord_in_Node_for_UserRecord(Node_for_UserRecord *pNode_for_UserRecord);
#endif
