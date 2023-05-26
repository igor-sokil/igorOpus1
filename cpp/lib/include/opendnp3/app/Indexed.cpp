#include "header.h"
#include "Indexed.h"
   void Indexed_for_AnalogOutputInt16_in_Indexed_for_AnalogOutputInt16Over1(Indexed_for_AnalogOutputInt16 *pIndexed_for_AnalogOutputInt16)
{
   AnalogOutputInt16_in_AnalogOutputInt16Over1(&(pIndexed_for_AnalogOutputInt16->value));
   pIndexed_for_AnalogOutputInt16->index = 0;
}

   void Indexed_for_AnalogOutputInt16_in_Indexed_for_AnalogOutputInt16Over2(Indexed_for_AnalogOutputInt16 *pIndexed_for_AnalogOutputInt16,
                                   AnalogOutputInt16* value_, uint16_t index_)
{
  AnalogOutputInt16_in_AnalogOutputInt16Over2(value_, index_);

//// : value(value_), index(index_) {}
  pIndexed_for_AnalogOutputInt16->index = index_;
}

//------------------------------------Indexed_for_AnalogOutputInt16---------------------------------------------------------
/*
   void Indexed_for_AnalogOutputInt16_in_Indexed_for_AnalogOutputInt16Over1(Indexed_for_AnalogOutputInt16 *pIndexed_for_AnalogOutputInt16)
{
////    Indexed() : value(), index(0) {}
   AnalogOutput_for_Int16_in_AnalogOutput_for_Int16Over1(&(pIndexed_for_AnalogOutputInt16->value));
   pIndexed_for_AnalogOutputInt16->index = 0;
}
*/
/*
   void Indexed_for_AnalogOutputInt16_in_Indexed_for_AnalogOutputInt16Over2(Indexed_for_AnalogOutputInt16 *pIndexed_for_AnalogOutputInt16,
                                   AnalogOutputInt16* value_, uint16_t index_)
{
  AnalogOutputInt16 aAnalogOutputInt16;
  AnalogOutputInt16_in_AnalogOutputInt16Over2(&aAnalogOutputInt16, value_);

//// : value(value_), index(index_) {}
  pIndexed_for_AnalogOutputInt16->index = index_;
}
*/

////template<class T> Indexed<T> WithIndex(const T& value, uint16_t index)
   Indexed_for_AnalogOutputInt16 WithIndex_in_Indexed_for_AnalogOutputInt16(//Indexed_for_AnalogOutputInt16 *pIndexed_for_AnalogOutputInt16, 
                                                        AnalogOutputInt16* value, uint16_t index)
{
   Indexed_for_AnalogOutputInt16 iIndexed_for_AnalogOutputInt16;
   Indexed_for_AnalogOutputInt16_in_Indexed_for_AnalogOutputInt16Over2(&iIndexed_for_AnalogOutputInt16,
                                   value, index);
////    return Indexed<T>(value, index);
   return iIndexed_for_AnalogOutputInt16;
}


//------------------------------------Indexed_for_AnalogOutputInt16---------------------------------------------------------
