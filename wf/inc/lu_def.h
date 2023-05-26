
#ifndef PRT_INFO_DSC_h
#define PRT_INFO_DSC_h
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//==================================================================================
//--- 			     -----------
//==================================================================================
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~             ~~
//~~~             ~~ 
//~~~             ~~
//~~~             ~~
//~~~             ~~
//~~~             ~~
//~~~             ~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//long ddf(unsigned char *arr, long _number_bit);
typedef struct LOp2_1_tag{
//unsigned char  *arrBitMap; 
short num1;
short num2;
short num_out;
short res;
}LOp2_1Dsc;

typedef struct LOp3_1_tag{
//unsigned char  *arrBitMap; 
short num1;
short num2;
short num3;
short num_out;
}LOp3_1Dsc;

typedef struct LOp4_1_tag{
//unsigned char  *arrBitMap; 
short num1;
short num2;
short num3;
short num4;
short num_out;
short res;
}LOp4_1Dsc;
#define AND2_1_( arrBitMap,Lop2_1_dat,index_bit_x1,mask_bit_x1,index_bit_x2,mask_bit_x2,result) \
do{ \
    result = 0;\
    long lV = arrBitMap[index_bit_x1]&(1<<mask_bit_x1);\
    lV >>= mask_bit_x1;\
    result += lV;\
    lV = arrBitMap[index_bit_x2]&(1<<mask_bit_x2);\
    lV >>= mask_bit_x2;\
    result += lV;\
    \
}while(0)\

#define AND2_1( arrBitMap,index_bit_x1,mask_bit_x1,index_bit_x2,mask_bit_x2,result) \
do{ \
    result = 0;\
    long lV = arrBitMap[index_bit_x1]&(1<<mask_bit_x1);\
    lV >>= mask_bit_x1;\
    result += lV;\
    lV = arrBitMap[index_bit_x2]&(1<<mask_bit_x2);\
    lV >>= mask_bit_x2;\
    result += lV;\
    \
}while(0)\

#define AND3_1( arrBitMap,index_bit_x1,mask_bit_x1,index_bit_x2,mask_bit_x2,index_bit_x3,mask_bit_x3,result) \
do{ \
    result = 0;\
    long lV = arrBitMap[index_bit_x1]&(1<<mask_bit_x1);\
    lV >>= mask_bit_x1;\
    result += lV;\
    lV = arrBitMap[index_bit_x2]&(1<<mask_bit_x2);\
    lV >>= mask_bit_x2;\
    result += lV;\
    \
    lV = arrBitMap[index_bit_x3]&(1<<mask_bit_x3);\
    lV >>= mask_bit_x3;\
    result += lV;\
    \
}while(0)\



typedef union U8_state_Unn{ 
   struct {
      unsigned int bt0 : 1; //1
      unsigned int bt1 : 1; //2
      unsigned int bt2 : 1; //3
      unsigned int bt3 : 1; //4
      unsigned int bt4 : 1; //5
      unsigned int bt5 : 1; //6
      unsigned int bt6 : 1; //7
      unsigned int bt7 : 1; //8
    } bool_val;
    unsigned char U8V;
} U8_state_wrp; 

extern U8_state_wrp stt_AND4_1,stt_AND5_1,stt_AND6_1;

#define CREATE_LOP_DATA_GEN (\
    arrBit1,num1, \
    arrBit2,num2, \
    arrBit3,num3, \
    arrBit4,num4, \
    arrBit5,num5, \
    arrBit6,num6, \
    stt_val\
    )             \
    {             \
      register long lV;           \
      lV = arrBit1[num1>>3]&(1<<(num1&7));\
      lV >>= (num1&7);\
      stt_val.bool_val.bt0 = lV;\
      lV = arrBit2[num2>>3]&(1<<(num2&7));\
      lV >>= (num2&7);\
      stt_val.bool_val.bt1 = lV;\
      lV = arrBit3[num3>>3]&(1<<(num3&7));\
      lV >>=(num3&7);\
      stt_val.bool_val.bt2 = lV;\
      lV = arrBit4[num4>>3]&(1<<(num4&7));\
      lV >>=(num4&7);\
      stt_val.bool_val.bt3 = lV;\
      lV = arrBit5[num5>>3]&(1<<(num5&7));\
      lV >>=(num5&7);\
      stt_val.bool_val.bt4 = lV;\
      lV = arrBit6[num6>>3]&(1<<(num6&7));\
      lV >>=(num6&7);\
      stt_val.bool_val.bt5 = lV;\
    }             
#define CREATE_LOP_DATA (\
    arrBit ,num1, \
    num2,         \
    num3,         \
    num4,         \
    num5,         \
    num6,         \
    stt_val\
    )             \
    {             \
      register long lV;           \
      lV = arrBit[num1>>3]&(1<<(num1&7));\
      lV >>= (num1&7);\
      stt_val.bool_val.bt0 = lV;\
      lV = arrBit[num2>>3]&(1<<(num2&7));\
      lV >>= (num2&7);\
      stt_val.bool_val.bt1 = lV;\
      lV = arrBit[num3>>3]&(1<<(num3&7));\
      lV >>=(num3&7);\
      stt_val.bool_val.bt2 = lV;\
      lV = arrBit[num4>>3]&(1<<(num4&7));\
      lV >>=(num4&7);\
      stt_val.bool_val.bt3 = lV;\
      lV = arrBit[num5>>3]&(1<<(num5&7));\
      lV >>=(num5&7);\
      stt_val.bool_val.bt4 = lV;\
      lV = arrBit[num6>>3]&(1<<(num6&7));\
      lV >>=(num6&7);\
      stt_val.bool_val.bt5 = lV;\
    }             

#define ert 1

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//       Definitions for 
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~        ~~~
//~~~        ~~~
//~~~        ~~~
//~~~        ~~~
//~~~        ~~~
//``````````````````````````````````````````````````````````````````````````````````
//~~~       ~~
//~~~       ~~ 
//~~~       ~~
//~~~       ~~
//~~~       ~~
//~~~       ~~
//~~~       ~~
//~~~       ~~
//~~~       ~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""




#endif 
        