#ifndef SER4CPP_Array__for__Node_for_UserRecord_H
#define SER4CPP_Array__for__Node_for_UserRecord_H

////#include "ser4cpp/container/ArrayView.h"
//#include "ArrayView__for__Node_for_int.h"
#include "HasLength.h"
#include "Node_for_UserRecord.h"

#define SIZE_for_UserRecord 100


/**
 * Template type for a dynamically allocated array
 */
////template<class T, class W> class Array : public HasLength<W>
typedef struct
{

////public:
////    Array(W size) : HasLength<W>(size), buffer(new T[size]()) {}

////    Array() : HasLength<W>(0), buffer(nullptr) {}

////    Array(const Array& copy) : HasLength<W>(copy.length()), buffer(new T[copy.length()])
////    {
////        for (W i = 0; i < copy.length(); ++i)
////            buffer[i] = copy.buffer[i];
////    }
////
////    virtual ~Array()
////    {
////        delete[] buffer;
////    }
////
////    ArrayView<T, W> to_view() const
////    {
////        return ArrayView<T, W>(buffer, this->m_length);
////    }
////
////    inline bool contains(W index) const
////    {
////        return index < this->m_length;
////    }

////    inline T& operator[](W index)
////    {
////        assert(index < this->m_length);
////        return buffer[index];
////    }
////
////    const T& operator[](W index) const
////    {
////        assert(index < this->m_length);
////        return buffer[index];
////    }
////
  HasLength_for_Uint32_t hHasLength_for_Uint32_t;
////protected:
////    T* buffer;
  Node_for_UserRecord buffer[SIZE_for_UserRecord];

////private:
////    Array& operator=(const Array&) = delete;
} Array__for__Node_for_UserRecord;

boolean contains_in_Array__for__Node_for_UserRecord(Array__for__Node_for_UserRecord *pArray__for__Node_for_UserRecord, uint32_t index);
//ArrayView__for__Node_for_int to_view_in_Array__for__Node_for_int(Array__for__Node_for_int *pArray__for__Node_for_int);
void Array__for__Node_for_UserRecord_in_Array__for__Node_for_UserRecordOver3(Array__for__Node_for_UserRecord *pArray__for__Node_for_UserRecord,
    Array__for__Node_for_UserRecord* copyEv);
void Array__for__Node_for_UserRecord_in_Array__for__Node_for_UserRecordOver1(Array__for__Node_for_UserRecord *pArray__for__Node_for_UserRecord);
void Array__for__Node_for_UserRecord_in_Array__for__Node_for_UserRecordOver2(Array__for__Node_for_UserRecord *pArray__for__Node_for_UserRecord, uint32_t size);


////} // namespace ser4cpp

#endif
