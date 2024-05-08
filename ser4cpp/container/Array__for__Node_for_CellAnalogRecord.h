#ifndef SER4CPP_Array__for__Node_for_CellAnalogRecord_H
#define SER4CPP_Array__for__Node_for_CellAnalogRecord_H

////#include "ser4cpp/container/ArrayView.h"
//#include "ArrayView__for__Node_for_int.h"
#include "HasLength.h"
#include "Node_for_CellAnalogRecord.h"

#define SIZE_for_CellAnalogRecord 100


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
  Node_for_CellAnalogRecord buffer[SIZE_for_CellAnalogRecord];

////private:
////    Array& operator=(const Array&) = delete;
} Array__for__Node_for_CellAnalogRecord;

boolean contains_in_Array__for__Node_for_CellAnalogRecord(Array__for__Node_for_CellAnalogRecord *pArray__for__Node_for_CellAnalogRecord, uint32_t index);
//ArrayView__for__Node_for_int to_view_in_Array__for__Node_for_int(Array__for__Node_for_int *pArray__for__Node_for_int);
void Array__for__Node_for_CellAnalogRecord_in_Array__for__Node_for_CellAnalogRecordOver3(Array__for__Node_for_CellAnalogRecord *pArray__for__Node_for_CellAnalogRecord,
    Array__for__Node_for_CellAnalogRecord* copyEv);
void Array__for__Node_for_CellAnalogRecord_in_Array__for__Node_for_CellAnalogRecordOver1(Array__for__Node_for_CellAnalogRecord *pArray__for__Node_for_CellAnalogRecord);
void Array__for__Node_for_CellAnalogRecord_in_Array__for__Node_for_CellAnalogRecordOver2(Array__for__Node_for_CellAnalogRecord *pArray__for__Node_for_CellAnalogRecord, uint32_t size);


////} // namespace ser4cpp

#endif
