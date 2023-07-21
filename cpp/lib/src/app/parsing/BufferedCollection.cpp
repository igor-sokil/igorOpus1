#include "header.h"
#include "BufferedCollection.h"

//-----------------------------------Indexed_Group2Var1_in_CountIndexParser----------------------------------

//costructor BufferedCollection_for_Indexed_Group2Var1_in_CountIndexParser
void BufferedCollection_for_Indexed_Group2Var1_in_CountIndexParser_in_BufferedCollection_for_Indexed_Group2Var1_in_CountIndexParser(
           BufferedCollection_for_Indexed_Group2Var1_in_CountIndexParser *pBufferedCollection_for_Indexed_Group2Var1_in_CountIndexParser,
           /*NumParser* pNumParser,*/ RSeq_for_Uint16_t* buffer, uint16_t count,
           Indexed_for_Group2Var1 (*readFunc)(/*NumParser* numparser,*/ RSeq_for_Uint16_t* buffer, uint32_t c))
{
 pBufferedCollection_for_Indexed_Group2Var1_in_CountIndexParser->buffer = buffer;
 pBufferedCollection_for_Indexed_Group2Var1_in_CountIndexParser->COUNT = count;
 pBufferedCollection_for_Indexed_Group2Var1_in_CountIndexParser->readFunc = readFunc;

pBufferedCollection_for_Indexed_Group2Var1_in_CountIndexParser->iICollection_Indexed_Group2Var1.pForeach_in_ICollection_Indexed_for_Group2Var1 =
 Foreach_in_BufferedCollection_for_Indexed_Group2Var1_in_CountIndexParser_override;

pBufferedCollection_for_Indexed_Group2Var1_in_CountIndexParser->iICollection_Indexed_Group2Var1.pCount_in_ICollection_Indexed_for_Group2Var1 =
 Count_in_BufferedCollection_for_Indexed_Group2Var1_in_CountIndexParser_override;
}

//function CreateBufferedCollection_Indexed_Group2Var1
    BufferedCollection_for_Indexed_Group2Var1_in_CountIndexParser
 CreateBufferedCollection_Indexed_Group2Var1(
           /*NumParser* pNumParser,*/ RSeq_for_Uint16_t* buffer, uint16_t count,
           Indexed_for_Group2Var1 (*read)((/*NumParser* numparser,*/ RSeq_for_Uint16_t* buffer, uint32_t)))
{
 BufferedCollection_for_Indexed_Group2Var1_in_CountIndexParser bBufferedCollection_for_Indexed_Group2Var1_in_CountIndexParser;
BufferedCollection_for_Indexed_Group2Var1_in_CountIndexParser_in_BufferedCollection_for_Indexed_Group2Var1_in_CountIndexParser(
&bBufferedCollection_for_Indexed_Group2Var1_in_CountIndexParser, /*pNumParser,*/ buffer, count, read);
return bBufferedCollection_for_Indexed_Group2Var1_in_CountIndexParser;
}

    uint16_t Count_in_BufferedCollection_for_Indexed_Group2Var1_in_CountIndexParser_override(void* pICollection_Indexed_Group2Var1) 
    {
   BufferedCollection_for_Indexed_Group2Var1_in_CountIndexParser* parent =
        (BufferedCollection_for_Indexed_Group2Var1_in_CountIndexParser*)getParentPointer_in_ICollection_Indexed_Group2Var1(
            (ICollection_Indexed_Group2Var1*)pICollection_Indexed_Group2Var1);
        return parent->COUNT;
    }

   void Foreach_in_BufferedCollection_for_Indexed_Group2Var1_in_CountIndexParser_override(void* pICollection_Indexed_Group2Var1,
                                       IVisitor_Indexed_for_Group2Var1* visitor)
   {
   BufferedCollection_for_Indexed_Group2Var1_in_CountIndexParser* parent =
        (BufferedCollection_for_Indexed_Group2Var1_in_CountIndexParser*)getParentPointer_in_ICollection_Indexed_Group2Var1(
            (ICollection_Indexed_Group2Var1*)pICollection_Indexed_Group2Var1);
////        ser4cpp::rseq_t copy(buffer);
          RSeq_for_Uint16_t copy = parent->buffer;


        for (uint32_t pos = 0; pos < parent->COUNT; ++pos)
        {
//void OnValue_in_IVisitor_Indexed_for_Group2Var1(IVisitor_Indexed_for_Group2Var1 *pIVisitor_Indexed_for_Group2Var1, Indexed_for_Group2Var1* value);
//    typedef Indexed_for_Group2Var1 (*ReadFunc_in_BufferedCollection_for_Indexed_Group2Var1_in_CountIndexParser)
//                                                            (/*NumParser* numparser,*/ RSeq_for_Uint16_t* buffer, uint32_t c);
////            visitor.OnValue(readFunc(copy, pos));
 OnValue_in_IVisitor_Indexed_for_Group2Var1(visitor, readFunc(&copy, pos));
        }
   }
//-----------------------------------Indexed_Group2Var1_in_CountIndexParser----------------------------------
