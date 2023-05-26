#include <string.h> 
#include "const_global.h"
//#define CHANGE_MEAS 1
//#define DEBUG_CONFIGURATION 1
extern unsigned int corupted_phases;

#ifdef DEBUG_CONFIGURATION
    #ifndef DEBUG_MODE_23_07_19 
        #error "VALUES DZ HAVE UNREAL NUMBER"
    #endif
#endif
 
void dz_handler(unsigned int *p_active_functions, unsigned int number_group_stp);
void fault_U_handler(unsigned int *p_active_functions, unsigned int number_group_stp);
void dz1_handler(unsigned int *p_active_functions, unsigned int number_group_stp);
void mf_of_handler(unsigned int *p_active_functions, unsigned int number_group_stp);
//https://en.wikipedia.org/wiki/Alternating_current
//Three-phase electrical single phase and neutral so use single Both, 
enum WRP_PHS_BIT_POS { 
    IA_M0_P9,//0
    IB_M0_P9,//1
    IC_M0_P9,//2
    IA_L0_P9,//3
    IB_L0_P9,//4
    IC_L0_P9,//5

TOTAL_WRP_PHS
//
};
typedef union dstLp_stp_state_Unn{ 
   struct {
      unsigned int po_1phs : 1;   //
      unsigned int po_2phs : 1;   //1
      unsigned int po_3phs : 1;   //2
      unsigned int po_Mphs : 1;   //3
      unsigned int po_IA_max : 1; //4 
      unsigned int po_IB_max : 1; //5 
      unsigned int po_IC_max : 1; //6 
      unsigned int IaM0p9:1;      //7    
      unsigned int IbM0p9:1;      //8 
      unsigned int IcM0p9:1;      //9 
      unsigned int IaL0p9:1;      //10
      unsigned int IbL0p9:1;      //11
      unsigned int IcL0p9:1;      //12
                                  //13
    } bool_val;
    long lVl;
} Mphs_sphs_stp_state; //multi phase
Mphs_sphs_stp_state m_s_phs_stp_state;//multi single
long dstLImax = 0;char ch_IdxMaxphs = 0;

const long Meast_TST[] = {
  10    ,// - IM_3I0_i = 0,
  20    ,// - IM_3I0,
  11    ,// - IM_3I0_other_g,
  12    ,// - IM_3I0_r,
  400  ,// - IM_IA,
  548  ,// - IM_IB,
  775  ,// - IM_IC,
  700   ,// - IM_I2,
  800   ,// - IM_I1,
  101000,// - IM_UA,
  101000,// - IM_UB,
  101000,// - IM_UC,
  90000 ,// - IM_3U0,
  118000,// - IM_UAB,
  119000,// - IM_UBC,
  116000,// - IM_UCA,
  101,// - IM_U2, 101000
  102 // - IM_U1, 102000
};
long Test_Values[9];
enum CORUPTED_PHASE_SEL_BIT_POS { 

FAIL_PHASE_A_BIT,
FAIL_PHASE_B_BIT,
FAIL_PHASE_C_BIT,

TOTAL_CORUPTED_PHASE_BITS
//
};
//=====================================================================================================
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//                  
//....................................................................................................
//=====================================================================================================
void mf_of_handler(unsigned int *p_active_functions, unsigned int number_group_stp){UNUSED(number_group_stp);UNUSED(p_active_functions);
//// ----------------  inner_outer_short_circuit It`s my name -------------------------
//register long rL,rU;
//  UNUSED(number_group_stp);
//  //void *memcpy (void *destination, const void *source, size_t n);
//
//#ifdef DEBUG_CONFIGURATION 
//
//  memcpy(measurement,Meast_TST,_NUMBER_IM*sizeof(long));
//  #warning The variable measurement HAVE DEBUG UNREAL VALUES
//  
//#endif    
//
////Detect Multi Pfase or Single Pfase
//    rL = measurement[IM_IA];
//    //m_s_phs_stp_state.lVl &= 0x1f8f;//Clr Phase selector
//    m_s_phs_stp_state.lVl = 0;//0x1f8f;//Clr Phase selector
//    rU = IM_IA;
////Select Imax
//    if(rL < (long) measurement[IM_IB]){
//        rL = measurement[IM_IB];
//        rU = IM_IB;
//    }   
//    if(rL < (long) measurement[IM_IC]){
//        rL = measurement[IM_IC];
//        rU = IM_IC;
//    }   
//    //Now Have Max
//     dstLImax = rL ;//measurement[rU]
//    ch_IdxMaxphs = rU; 
//    if(rU == IM_IA){
//        m_s_phs_stp_state.bool_val.po_IA_max = 1;
//    }else if(rU == IM_IB){
//        m_s_phs_stp_state.bool_val.po_IB_max = 1;
//    }else if(rU == IM_IC){
//        m_s_phs_stp_state.bool_val.po_IC_max = 1;
//    }
//    rL *=9;rL/=10;
//register union { 
//   struct {
//      unsigned int IaM0p9:1;//0
//      unsigned int IbM0p9:1;//1
//      unsigned int IcM0p9:1;//2
//      unsigned int IaL0p9:1;//3
//      unsigned int IbL0p9:1;//4
//      unsigned int IcL0p9:1;//5
//      unsigned int stp_DST_LP_1:1;      //
//      unsigned int stp_DST_LP_2_INV:1; //7
//      unsigned int stp_DST_LP_2_DIR:1; //8
//      unsigned int stp_DST_LP_3_INV:1; //9
//      unsigned int stp_DST_LP_3_DIR:1; //10
//      unsigned int stp_DST_LP_4_INV:1; //11
//      unsigned int stp_DST_LP_4_DIR:1; //12
//   } bool_vars;
//  long lVl;
//}wrp;   
//    wrp.lVl = 0;
//    wrp.bool_vars.IaM0p9 = (long)(measurement[IM_IA]> (unsigned long)rL);
//    wrp.bool_vars.IbM0p9 = (long)(measurement[IM_IB]> (unsigned long)rL);
//    wrp.bool_vars.IcM0p9 = (long)(measurement[IM_IC]> (unsigned long)rL);
//    wrp.bool_vars.IaL0p9 = (long)(measurement[IM_IA]< (unsigned long)rL);
//    wrp.bool_vars.IbL0p9 = (long)(measurement[IM_IB]< (unsigned long)rL);
//    wrp.bool_vars.IcL0p9 = (long)(measurement[IM_IC]< (unsigned long)rL);
//register long lV,i;
//    
//            lV  = wrp.lVl&( (1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)  );
//        if(lV == 7){
//            m_s_phs_stp_state.bool_val.po_3phs = 1;
//            m_s_phs_stp_state.bool_val.po_Mphs = 1;
//            //Select 3Pfase
//        }else   if(lV  == ( (1<< IA_M0_P9) | (1<<IB_M0_P9) | (1<<IC_L0_P9 )) 
//                    || ( lV == ((1<< IB_M0_P9) | (1<<IC_M0_P9) | (1<<IA_L0_P9)) ) 
//                    || ( lV == ((1<< IA_M0_P9) | (1<<IC_M0_P9) | (1<<IB_L0_P9))) ){
//                        m_s_phs_stp_state.bool_val.po_2phs = 1;
//                        m_s_phs_stp_state.bool_val.po_Mphs = 1;
//                        //Select 2Pfase
//        }
//        else    if( lV == ( (1<< IA_L0_P9) | (1<<IB_L0_P9) | (1<<IC_M0_P9) ) 
//                    || (lV == ((1<<IB_L0_P9) | (1<<IC_L0_P9) | (1<<IA_M0_P9)) ) 
//                    || (lV == ((1<<IA_L0_P9) | (1<<IC_L0_P9) | (1<<IB_M0_P9))  ) ){
//                    m_s_phs_stp_state.bool_val.po_1phs = 1;
//                //Select 1Pfase
//                }
//                
//    if(_CHECK_SET_BIT(p_active_functions, RANG_PO_DZ1) != 0)
//        wrp.bool_vars.stp_DST_LP_1 = 1;
//    if(_CHECK_SET_BIT(p_active_functions, RANG_PO_INV_DZ2) != 0)
//        wrp.bool_vars.stp_DST_LP_2_INV = 1;
//    if(_CHECK_SET_BIT(p_active_functions, RANG_PO_DIR_DZ2) != 0)
//        wrp.bool_vars.stp_DST_LP_2_DIR = 1;
//    if(_CHECK_SET_BIT(p_active_functions, RANG_PO_INV_DZ3) != 0)        
//        wrp.bool_vars.stp_DST_LP_3_INV = 1;
//    if(_CHECK_SET_BIT(p_active_functions, RANG_PO_DIR_DZ3) != 0)
//        wrp.bool_vars.stp_DST_LP_3_DIR = 1;
//    if(_CHECK_SET_BIT(p_active_functions, RANG_PO_INV_DZ4) != 0)        
//        wrp.bool_vars.stp_DST_LP_4_INV = 1;
//    if(_CHECK_SET_BIT(p_active_functions, RANG_PO_DIR_DZ4) != 0)
//        wrp.bool_vars.stp_DST_LP_4_DIR = 1;
//     if( (wrp.lVl&((1<<6)|(1<<7)|(1<<8)|(1<<9)|(1<<10)|(1<<11)|(1<<12)) ) > 0 ){
//        i = 1;
//
//            
//        
//    }else{
//        i = 0;
//    }   
//    
//    //Select MPfase
//        lV  = m_s_phs_stp_state.bool_val.po_1phs;
//          if ( (lV>0) && (i == 1) )
//            _SET_BIT(p_active_functions, RANG_1KZ);
//          else
//            _CLEAR_BIT(p_active_functions, RANG_1KZ);
//        lV  = m_s_phs_stp_state.bool_val.po_2phs;
//          if ( (lV >0) && (i == 1))
//            _SET_BIT(p_active_functions, RANG_2KZ);
//          else
//            _CLEAR_BIT(p_active_functions, RANG_2KZ);
//        lV  = m_s_phs_stp_state.bool_val.po_3phs;
//          if ((lV>0) && (i == 1))
//            _SET_BIT(p_active_functions, RANG_3KZ);
//          else
//            _CLEAR_BIT(p_active_functions, RANG_3KZ);
//            
//    lV  = wrp.lVl&((1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5));//&0x1f8
//// m_s_phs_stp_state.lVl &= ~   
// m_s_phs_stp_state.lVl |= (lV)<<7;//Save Stp
// corupted_phases = 0;
// //wrp.bool_vars.IaM0p9 
// //wrp.bool_vars.IbM0p9 
// //wrp.bool_vars.IcM0p9 
// 
// corupted_phases |= (wrp.bool_vars.IaM0p9)<< FAIL_PHASE_A_BIT;
// corupted_phases |= (wrp.bool_vars.IbM0p9)<< FAIL_PHASE_B_BIT;
// corupted_phases |= (wrp.bool_vars.IcM0p9)<< FAIL_PHASE_C_BIT;
// 
// 
  
}
//
//--------------------------------------------------------------------------------------------------------
enum FAULT_U_BIT_POS { 

//FAULT_U_MENU_STATE_BIT,
//FAULT_U_DV_FAULT_DST__L_CMD_BIT  = 1, 
FAULT_U_U2_STP_STATE_BIT,
FAULT_U_0DOT5_T_STATE_BIT,
FAULT_U_4IN_OR_EL_STATE_BIT,
FAULT_U_DSTL_TMR_STATE_BIT,
TOTAL_FAULT_U_BITS
};
#define UN_PHS   57000
//?static char chStpfault_U = 0; 
//=====================================================================================================
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//                  
//....................................................................................................
//=====================================================================================================
void fault_U_handler(unsigned int *p_active_functions, unsigned int number_group_stp){UNUSED(number_group_stp);UNUSED(p_active_functions);
//// ----------------  inner_outer_short_circuit It`s my name -------------------------
////First 
//  unsigned long u32_bit_holder = 0;
//  long i;
//  
//register union { 
//   struct {
//      unsigned int OR_1:1;//0
//      unsigned int OR_2:1;//1
//      unsigned int OR_3:1;//2
//      unsigned int OR_4:1;//3
//      unsigned int AND1_1:1;//4
//      unsigned int AND1_2:1;//5
//      unsigned int AND1_3:1;//6
//      unsigned int AND2_1:1;//7
//      unsigned int AND2_2:1;//8
//      unsigned int AND2_3:1;//9
//      unsigned int AND3_1:1;//10
//      unsigned int AND3_2:1;//11
//      unsigned int AND3_3:1;//12
//      unsigned int ItoLow:1;//13
//      unsigned int UtoLow:1;//14
//
//   } bool_vars;
//  long lVl;
//}wrp;  
//   wrp.lVl = 0;
//   if((_CHECK_SET_BIT(p_active_functions, RANG_EXT_NKN_DZ) != 0))
//    wrp.bool_vars.OR_4 = 1;
//   if(chStpfault_U&1)
//        i = (12*I_NOM*KOEF_POVERNENNJA_MTZ_I_DOWN)/1000;
//    else
//        i = (12*I_NOM)/10;  
//   
//   if( (measurement[IM_IA] < (unsigned long) i)
//       &&  (measurement[IM_IB] < (unsigned long)i)
//       &&  (measurement[IM_IC] < (unsigned long)i)
//      ){
//      wrp.bool_vars.AND1_2 = 1; chStpfault_U |= 1;
//     }
//     else{
//     chStpfault_U &= 0xfe;
//     
//     }
//     
//    
//    if(chStpfault_U&2)
//        i = (U_LINEAR_NOM*2*U_DOWN)/1000;
//    else
//        i = (U_LINEAR_NOM*2)/10;    
//    
//  if( (measurement[IM_UAB] < (unsigned long)i)
//       &&  (measurement[IM_UBC] < (unsigned long)i)
//       &&  (measurement[IM_UCA] < (unsigned long)i)
//      ){
//      wrp.bool_vars.AND1_3 = 1; chStpfault_U |= 2;
//    }else
//        chStpfault_U &= 0xfd;
//    
//   i = current_settings_prt.control_dz&MASKA_FOR_BIT(INDEX_CTR_NKN_DZ);
//   if (i > 0){
//    wrp.bool_vars.AND1_1 = 1;
//    wrp.bool_vars.AND2_1 = 1;
//    wrp.bool_vars.AND3_1 = 1;
//    
//   }
//   if( (wrp.lVl & ( (1<<4)| (1<<5)| (1<<6) ))  == ( (1<<4)| (1<<5)| (1<<6) ) )
//    wrp.bool_vars.OR_1 = 1;
//    
//    if(chStpfault_U&4)
//        i = (2*UN_PHS*U_UP)/100;
//    else
//        i = (2*UN_PHS);
//        
//   if (10*measurement[IM_U2] > (unsigned)i){
//        u32_bit_holder |= 1<<FAULT_U_U2_STP_STATE_BIT;
//        chStpfault_U |= 4;
//    }else{
//        chStpfault_U &= 0xfb;
//    }
//    
//     _TIMER_T_0(INDEX_TIMER_0DOT5_DZ, 500,
//  u32_bit_holder, FAULT_U_U2_STP_STATE_BIT, u32_bit_holder, FAULT_U_0DOT5_T_STATE_BIT);
//  if( (u32_bit_holder & (1<<FAULT_U_0DOT5_T_STATE_BIT)) != 0 )
//    wrp.bool_vars.AND3_3 = 1;
//    if(measurement[IM_I2]< 50)
//        wrp.bool_vars.ItoLow = 1;
//    if(measurement[IM_U2]< 50)
//        wrp.bool_vars.UtoLow = 1;
//    long j = 200;   
//    if(wrp.lVl & ((1<<13)| (1<<14)) ){
//        i = 0;
//    }else{
//            i = (measurement[IM_U2]*(1000*5))/(measurement[IM_I2]*57);//  i = (10*measurement[IM_U2]*I_NOM)/(measurement[IM_I2]*UN_PHS);
//            
//            if (chStpfault_U & 8){
//                j = 190;//j = 2*95/100;i*=100;
//            }
//    }
//   if (i > (j)){
//        wrp.bool_vars.AND3_2 = 1;
//        wrp.bool_vars.AND2_3 = 1;chStpfault_U |= 8;
//    }
//    else
//        chStpfault_U &= 0xf7;
//        
//    if( (wrp.lVl & ( (1<<10)| (1<<11)| (1<<12) )) == ( (1<<10)| (1<<11)| (1<<12) ) )
//        wrp.bool_vars.OR_3 = 1;
//    
//    i =_CHECK_SET_BIT(p_active_functions, RANG_PO_DZ1);
//    i |=_CHECK_SET_BIT(p_active_functions, RANG_PO_DIR_DZ2);
//    i |=_CHECK_SET_BIT(p_active_functions, RANG_PO_INV_DZ2);
//    i |=_CHECK_SET_BIT(p_active_functions, RANG_PO_DIR_DZ3);
//    i |=_CHECK_SET_BIT(p_active_functions, RANG_PO_INV_DZ3);  
//    i |=_CHECK_SET_BIT(p_active_functions, RANG_PO_DIR_DZ4);
//    i |=_CHECK_SET_BIT(p_active_functions, RANG_PO_INV_DZ4);  
//   if (i != 0){
//    wrp.bool_vars.AND2_2 = 1;
//    }
//    if( (wrp.lVl & ( (1<<7)| (1<<8)| (1<<9) )) == ( (1<<7)| (1<<8)| (1<<9) ) )
//        wrp.bool_vars.OR_2 = 1;
//#ifdef DEBUG_CONFIGURATION11
//  i =_CHECK_SET_BIT(p_active_functions, RANG_EXT_NKN_DZ);i|=1;
//#else
//  i =_CHECK_SET_BIT(p_active_functions, RANG_EXT_NKN_DZ);
//#endif
//
//   if (i > 0){
//    wrp.bool_vars.OR_4 = 1;
//    }
//    if(wrp.lVl &0xf)
//    u32_bit_holder |= 1<<FAULT_U_4IN_OR_EL_STATE_BIT;
//    
//  _TIMER_0_T(INDEX_TIMER_NKN_DZ, current_settings_prt.timeout_nkn_dz[number_group_stp],
//  u32_bit_holder, FAULT_U_4IN_OR_EL_STATE_BIT, u32_bit_holder, FAULT_U_DSTL_TMR_STATE_BIT);
//
//  //Сраб. 
//  if ( (u32_bit_holder&(1<<FAULT_U_DSTL_TMR_STATE_BIT )) != 0 )
//    _SET_BIT(p_active_functions, RANG_NKN_DZ);
//  else
//    _CLEAR_BIT(p_active_functions, RANG_NKN_DZ);
//
// 
}
//
//--------------------------------------------------------------------------------------------------------

enum DZ1_BIT_POS { 

AMTZ1_PICKUP_STATE_BIT,
AMTZ1_TMR_STATE_BIT,
DZ1_PICKUP_STATE_BIT,
DZ1_TMR_STATE_BIT,
TOTAL_DZ1_BITS
//
};
char chGbl_3Phs_Dz;
//=====================================================================================================
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//                  
//....................................................................................................
//=====================================================================================================
void dz1_handler(unsigned int *p_active_functions, unsigned int number_group_stp){UNUSED(number_group_stp);UNUSED(p_active_functions);
//// ----------------  inner_outer_short_circuit It`s my name -------------------------
//long lV;unsigned long rU;
//unsigned long u32_bit_holder = 0; 
//register union { 
//   struct {
//      unsigned int and4_1:1;//0
//      unsigned int and4_2:1;//1
//      unsigned int and4_3:1;//2
//      unsigned int and5_1:1;//3
//      unsigned int and5_2:1;//4
//      unsigned int and5_3:1;//5
//      unsigned int and4__:1;//6
//      unsigned int and5__:1;//7
//      unsigned int or6_1:1;//8
//      unsigned int or6_2:1;//9
//      unsigned int not2_1:1;//10
//      unsigned int not7_1:1;//11
//      unsigned int or6_O1:1;//11-  O1 - means out 1
//   } bool_vars;
//  long lVl;
//}wrp_sncn;
//    wrp_sncn.lVl = 0;
//    
////Meast_TST
//    if(_CHECK_SET_BIT(p_active_functions, RANG_PO_I_BLK_DZ) != 0){
//        lV = 550;
//    }else{
//        lV = 500;
//    }
//    //Po Iblk
//    //rU = UN_PHS*25/10000;//142,5
//    //lV = 500;
//    if(   (measurement[IM_IA]< (unsigned long)lV) 
//        &&(measurement[IM_IB]< (unsigned long)lV)
//        &&(measurement[IM_IC]< (unsigned long)lV)){
//        //wrp_sncn.bool_vars.and4_3 = 0;
//        //wrp_sncn.bool_vars.and5_3 = 0;
//        _SET_BIT(p_active_functions, RANG_PO_I_BLK_DZ);
//    }   
//    else{
//        wrp_sncn.bool_vars.and4_3 = 1;
//        wrp_sncn.bool_vars.and5_3 = 1;
//        _CLEAR_BIT(p_active_functions, RANG_PO_I_BLK_DZ);
//    }
//    if(_CHECK_SET_BIT(p_active_functions, RANG_PO_U_DZ) != 0)
//        rU = (KOEF_POVERNENNJA_GENERAL_DOWN*UN_PHS*25)/(10000*100);//142,5 
//    else 
//        rU = UN_PHS*25/10000;//142,5 
//    
//    if(   (measurement[IM_UA]< rU) 
//        &&(measurement[IM_UB]< rU)
//        &&(measurement[IM_UC]< rU)){
//        _SET_BIT(p_active_functions, RANG_PO_U_DZ);
//        wrp_sncn.bool_vars.and4_2 = 1;
//        wrp_sncn.bool_vars.and5_1 = 1;
//    }   
//    else{
//        //wrp_sncn.bool_vars.and4_2 = 1;
//        //wrp_sncn.bool_vars.and5_1 = 1;
//    _CLEAR_BIT(p_active_functions, RANG_PO_U_DZ);
//    }
////    wrp_sncn.bool_vars.not7_1 = !wrp_sncn.bool_vars.and5_1;//Inv 3phs
//    
//    if(m_s_phs_stp_state.bool_val.po_3phs)
//        wrp_sncn.bool_vars.and5_2 = 1;
//        
//    if(m_s_phs_stp_state.lVl&3)//Or1 analog
//        wrp_sncn.bool_vars.and4_1 = 1;
//    rU = wrp_sncn.lVl &( (1<<0)| (1<<1)| (1<<2));
//    if(rU == ( (1<<0)| (1<<1)| (1<<2))){
//        //wrp_sncn.bool_vars.and4__ = 1;
//        wrp_sncn.bool_vars.or6_2 = 1;
//    }
//    rU = wrp_sncn.lVl &( (1<<3)| (1<<4)| (1<<5));
//    if(rU == ( (1<<3)| (1<<4)| (1<<5))){
//        wrp_sncn.bool_vars.and5__ = 1;
//        _SET_BIT(p_active_functions, RANG_3F_DZ_DIR_INV);
//    }
//    else
//        _CLEAR_BIT(p_active_functions, RANG_3F_DZ_DIR_INV);
//    wrp_sncn.bool_vars.not7_1 = !wrp_sncn.bool_vars.and5__;
//    chGbl_3Phs_Dz = wrp_sncn.bool_vars.and5__;
//    if( _CHECK_SET_BIT(p_active_functions, RANG_NKN_DZ)
//        && (wrp_sncn.bool_vars.not7_1))
//        wrp_sncn.bool_vars.or6_1 = 1;
//    rU =  wrp_sncn.lVl & ( (1<<8)| (1<<9)); 
//    if ( rU != 0 ){
//        _SET_BIT(p_active_functions, RANG_SNKN_DZ);
//        wrp_sncn.bool_vars.or6_O1 = 1;
//    }
//  else
//    _CLEAR_BIT(p_active_functions, RANG_SNKN_DZ);   
//        
////First Check Menu & Dv ON or OFF
//register union { 
//   struct {
//      unsigned int and8_1:1;//0
//      unsigned int and8_2:1;//1
//      unsigned int and8_3:1;//2
//      unsigned int and8_4:1;//3
//      unsigned int and9_1:1;//4
//      unsigned int and9_2:1;//5
//      unsigned int and9_3:1;//6
//      unsigned int and9_4:1;//7
//      unsigned int and9_5:1;//8
//      unsigned int nor7_1 :1;//9
//      unsigned int nor7_2 :1;//10
//      unsigned int nor7_3 :1;//11
//      unsigned int nor6_1 :1;//12
//      unsigned int nor6_2 :1;//13
//      unsigned int nor6_3 :1;//14
//      unsigned int nor6_4 :1;//15
//      unsigned int reserv :1;//16
//      unsigned int or4_1 :1;//17
//      unsigned int or4_2 :1;//18
//      unsigned int and5_1:1;//19
//      unsigned int reser1:1;//20
//      unsigned int and5_2:1;//21
//      unsigned int and4_1:1;//22
//      unsigned int and4_2:1;//23
//      unsigned int and2_1:1;//24
//      unsigned int and2_2:1;//25
//      unsigned int not3_1 :1;//26
//      unsigned int not10_1:1;//27
//      unsigned int nor5_1 :1;//28
//      unsigned int nor5_2 :1;//29
//      unsigned int reser2 :1;//30
//      unsigned int reser3 :1;//31
//      
//   } bool_vars;
//  long lVl;
//}wrp_dz1;
////Calc  for 1 stages 7-9 elem
//    wrp_dz1.lVl = 0;wrp_dz1.bool_vars.and8_3 = 1;
//    if(current_settings_prt.control_dz&MASKA_FOR_BIT(INDEX_CTR_DZ1))
//    {
//        wrp_dz1.bool_vars.and8_1 = 1;
//        wrp_dz1.bool_vars.and9_1 = 1;
//    }
//    
//    if(_CHECK_SET_BIT(p_active_functions, RANG_PO_DZ1) != 0){
//        wrp_dz1.bool_vars.not10_1 = 1;
//        
//    }else{
//        wrp_dz1.bool_vars.and9_2  = 1;
//        wrp_dz1.bool_vars.and4_2  = 1;
//    
//    }
//        
//    if(_CHECK_SET_BIT(p_active_functions, RANG_PO_AMTZ_DZ1) != 0){
//        wrp_dz1.bool_vars.nor6_4 = 1;
//        wrp_dz1.bool_vars.nor5_2 = 1;
//    }
//    
//    //amtz
//    if(current_settings_prt.control_dz&MASKA_FOR_BIT(INDEX_CTR_DZ1_AMTZ)){
//        wrp_dz1.bool_vars.and9_5 = 1;//CTR_DZ1_AMTZ
//        wrp_dz1.bool_vars.and2_2 = 1;//CTR_DZ1_AMTZ
//    }   
//    else
//        wrp_dz1.bool_vars.not3_1 = 1;
//    //sncn&amtz 
//    lV = wrp_sncn.bool_vars.or6_O1;//sncn
//    rU = lV& wrp_dz1.bool_vars.and2_2;
//    if(rU == 1){
//        wrp_dz1.bool_vars.and4_1 = 1;
//        wrp_dz1.bool_vars.nor5_1 = 1;
//    }else{
//
//    }
//    if(_CHECK_SET_BIT(p_active_functions, RANG_BLOCK_DZ1) != 0){
//        wrp_dz1.bool_vars.nor7_1 = 1;
//        wrp_dz1.bool_vars.nor6_1 = 1;
//    }   
//    if(_CHECK_SET_BIT(p_active_functions, RANG_PO_I_BLK_DZ) != 0){
//        wrp_dz1.bool_vars.nor7_2 = 1;
//        wrp_dz1.bool_vars.nor6_3 = 1;
//    }
//
//    //nor5_2
//    rU = wrp_dz1.lVl &( (1<<28)| (1<<29));
//    if(rU ==  0){
//        wrp_dz1.bool_vars.nor7_3 = 1;
//    }
//    //rU-nor7
//    rU = wrp_dz1.lVl &( (1<<9)|(1<<10)| (1<<11));
//    if(rU ==  0)                        
//        lV = 1;//wrp_dz1.bool_vars.nor7_3 = 0;     
//    else
//        lV = 0;
//    wrp_dz1.bool_vars.and9_3 = lV;  
//    // long pick_up_AMcp_dstLp1 = 0;
//    if(_CHECK_SET_BIT(p_active_functions, RANG_PO_AMTZ_DZ1) != 0)
//        rU = (current_settings_prt.pickup_dz1_amtz[number_group_stp]* KOEF_POVERNENNJA_MTZ_I_UP)/100 ;
//    else 
//        rU = current_settings_prt.pickup_dz1_amtz[number_group_stp];
//        
//    // pick_up_AMcp_dstLp1 = (long)current_settings_prt.pickup_dz1_amtz[number_group_stp];
//    //and9_4
//    if(    (measurement[IM_IA] > (unsigned long)rU)
//        || (measurement[IM_IB] > (unsigned long)rU)
//        || (measurement[IM_IC] > (unsigned long)rU)
//        )
//             wrp_dz1.bool_vars.and9_4 = 1;//rU = 1;
//        else
//             wrp_dz1.bool_vars.and9_4 = 0;//rU = 0;
//    
//    //and9
//    rU = wrp_dz1.lVl &( (1<<4)| (1<<5)| (1<<6)| (1<<7)| (1<<8));
//    if(rU == ( (1<<4 )| (1<<5 )| (1<<6 )| (1<<7 )| (1<< 8))){
//        wrp_dz1.bool_vars.nor5_2 = 1;//?
//        wrp_dz1.bool_vars.nor6_4 = 1;
//        _SET_BIT(p_active_functions, RANG_PO_AMTZ_DZ1);
//        u32_bit_holder |= 1<< AMTZ1_PICKUP_STATE_BIT;
//         _TIMER_T_0(INDEX_TIMER_DZ1_AMTZ, current_settings_prt.timeout_dz1_amtz[number_group_stp],
//  u32_bit_holder, AMTZ1_PICKUP_STATE_BIT, u32_bit_holder, AMTZ1_TMR_STATE_BIT);
//
//    }
//    else{
//            wrp_dz1.bool_vars.nor5_2 = 0;//?
//            wrp_dz1.bool_vars.nor6_4 = 0;
//            _CLEAR_BIT(p_active_functions, RANG_PO_AMTZ_DZ1);
//            //u32_bit_holder ~= 1<< AMTZ1_PICKUP_STATE_BIT;
//             _TIMER_T_0(INDEX_TIMER_DZ1_AMTZ, current_settings_prt.timeout_dz1_amtz[number_group_stp],
//  u32_bit_holder, AMTZ1_PICKUP_STATE_BIT, u32_bit_holder, AMTZ1_TMR_STATE_BIT);
//  
//    }   
//     //Сраб. 
//     if ( u32_bit_holder&(1<<AMTZ1_TMR_STATE_BIT ) )
//       _SET_BIT(p_active_functions, RANG_AMTZ_DZ1);
//     else
//       _CLEAR_BIT(p_active_functions, RANG_AMTZ_DZ1);
//    
//    rU = wrp_dz1.bool_vars.and4_1;
//    rU &= (~wrp_dz1.bool_vars.not10_1)&1;
//    if(rU==1)
//        wrp_dz1.bool_vars.nor6_2 = 1;
//    //else
//        //wrp_dz1.bool_vars.nor6_2 = 0;
//    
//    ;//pickup_dz1_amtz
//    //Po Dz
//    rU = wrp_dz1.bool_vars.not10_1;
//     long pick_up_Resistance_dstLp1 = 0;
//    if(rU == 1)
//        pick_up_Resistance_dstLp1 = (long)current_settings_prt.pickup_dz1[number_group_stp] * KOEF_POVERNENNJA_GENERAL_DOWN  / 100;
//    else
//        pick_up_Resistance_dstLp1 = (long)current_settings_prt.pickup_dz1[number_group_stp];
//
//    lV = m_s_phs_stp_state.lVl; rU = Za_3;
//    if(lV&(1<<0)){//One
//        if(wrp_sncn.bool_vars.or6_O1&&wrp_dz1.bool_vars.not3_1){//Check Fault and2
//            rU = Za_A;
//            if(lV&(1<<5))
//                rU = Za_B;
//            else if(lV&(1<<6))
//                    rU = Za_C;
//            
//        }
//        else{
//            rU = Z_A;
//            if(lV&(1<<5))
//                rU = Z_B;
//            else if(lV&(1<<6))
//                    rU = Z_C;       
//        }
//        //current_settings_prt.pickup_dz1
//    }else if(lV&(1<<1)){ //2
//        lV &= ((1<<(IB_M0_P9+7)) | (1<<(IC_M0_P9+7)) | (1<<(IA_M0_P9+7))
//                |(1<<(IA_L0_P9+7))|(1<<(IB_L0_P9+7))| (1<<IC_L0_P9+7 ));
//        if(wrp_sncn.bool_vars.or6_O1&&wrp_dz1.bool_vars.not3_1){//Check Fault
//            rU = Za_AB;//( (1<< IA_M0_P9) | (1<<IB_M0_P9) | (1<<IC_L0_P9 ))
//            if( lV == ((1<<(IB_M0_P9+7)) | (1<<(IC_M0_P9+7)) | (1<<(IA_L0_P9+7))) )//lV&((1<<(IB_M0_P9+7)) | (1<<(IC_M0_P9+7)) | (1<<(IA_L0_P9+7)))) )
//                rU = Za_BC;
//            else if( lV == ((1<<(IA_M0_P9+7)) | (1<<(IC_M0_P9+7)) | (1<<(IB_L0_P9+7))) )//(lV&((1<<(IA_M0_P9+7)) | (1<<(IC_M0_P9+7)) | (1<<(IB_L0_P9+7)))) )
//                    rU = Za_CA; 
//        }
//        else{
//            rU = Z_AB;
//            if( lV == ((1<<(IB_M0_P9+7)) | (1<<(IC_M0_P9+7)) | (1<<(IA_L0_P9+7))) )//(lV&((1<<(IB_M0_P9+7)) | (1<<(IC_M0_P9+7)) | (1<<(IA_L0_P9+7)))))
//                rU = Z_BC;
//            else if( lV == ((1<<(IA_M0_P9+7)) | (1<<(IC_M0_P9+7)) | (1<<(IB_L0_P9+7))) )//(lV&((1<<(IA_M0_P9+7)) | (1<<(IC_M0_P9+7)) | (1<<(IB_L0_P9+7)))) )
//                    rU = Z_CA;  
//        }
//    }
//    else{//M
//        if(wrp_sncn.bool_vars.or6_O1&&wrp_dz1.bool_vars.not3_1){//Check Fault
//            rU = Za_3;//lV&(1<<2) Select Avar
//        }
//        else{
//            rU = Z_3;
//        }
//        
//
//    }
//Test_Values[8] = resistance[rU]; Test_Values[7] = rU;        
//if( (resistance[rU] < pick_up_Resistance_dstLp1)
//        //|| (resistance[rU] > pick_up_Resistance_dstLp1)
//        //|| (resistance[rU] > pick_up_Resistance_dstLp1)
//        )
//             wrp_dz1.bool_vars.and8_2 = 1;//rU = 1;
//        else
//             wrp_dz1.bool_vars.and8_2 = 0;//rU = 0;
//
////nor6  
//    rU = wrp_dz1.lVl &( (1<<12)|(1<<13)| (1<<14)| (1<<15));
//    if(rU ==  0)                        
//        lV = 1;//wrp_dz1.bool_vars.nor7_3 = 0;     
//    else
//        lV = 0;
//    wrp_dz1.bool_vars.and8_4 = lV;  
//    //and8
//    rU = wrp_dz1.lVl &(  (1<<0)| (1<<1)| (1<<2)| (1<<3));
//    if(rU == (  (1<<0 )| (1<<1 )| (1<<2 )| (1<< 3))){
//        //wrp_sncn.bool_vars.nor5_2 = 1;
//        //wrp_dz1.bool_vars.nor6_4 = 1;
//        u32_bit_holder |= 1<< DZ1_PICKUP_STATE_BIT;
//        _SET_BIT(p_active_functions, RANG_PO_DZ1);
//        _TIMER_T_0(INDEX_TIMER_DZ1, current_settings_prt.timeout_dz1[number_group_stp],
//  u32_bit_holder, DZ1_PICKUP_STATE_BIT, u32_bit_holder, DZ1_TMR_STATE_BIT);
//
//    }
//    else{
//        _CLEAR_BIT(p_active_functions, RANG_PO_DZ1);
//        _TIMER_T_0(INDEX_TIMER_DZ1, current_settings_prt.timeout_dz1[number_group_stp],
//  u32_bit_holder, DZ1_PICKUP_STATE_BIT, u32_bit_holder, DZ1_TMR_STATE_BIT);
//
//    }   
//      //Сраб. 
//  if ( u32_bit_holder&(1<<DZ1_TMR_STATE_BIT ) )
//    _SET_BIT(p_active_functions, RANG_DZ1);
//  else
//    _CLEAR_BIT(p_active_functions, RANG_DZ1);
//    
//    
}   
//
//--------------------------------------------------------------------------------------------------------
//````````````````````````````````````````````````````````````````````````````````````````````````````````
enum DZ2_BIT_POS { 

ACC_AMTZ2_TMR_IN_BIT,
ACC_DZ2__TMR_IN_BIT,
ACC_AMTZ2_TMR_BIT,
ACC_DZ2__TMR_BIT,

//AMTZ2_PICKUP_STATE_BIT,
AMTZ2_TMR_IN_BIT,
AMTZ2_TMR_BIT,
AMTZ2_ACC_TMR_IN_BIT,
AMTZ2_ACC_TMR_BIT,

//DZ2_PICKUP_STATE_BIT,
DZ2_DIR_TMR_IN_BIT,
DZ2_DIR_TMR_STATE_BIT,
DZ2_INV_TMR_IN_BIT,
DZ2_INV_TMR_STATE_BIT,
DZ2_DIR_ACC_TMR_IN_BIT,
DZ2_DIR_ACC_TMR_STATE_BIT,
DZ2_INV_ACC_TMR_IN_BIT,
DZ2_INV_ACC_TMR_STATE_BIT,

TOTAL_DZ2_BITS,

ACC_AMTZ3_TMR_IN_BIT        =          ACC_AMTZ2_TMR_IN_BIT,
ACC_DZ3__TMR_IN_BIT         =          ACC_DZ2__TMR_IN_BIT,
ACC_AMTZ3_TMR_BIT           =          ACC_AMTZ2_TMR_BIT,
ACC_DZ3__TMR_BIT            =          ACC_DZ2__TMR_BIT,
                                      
//AMTZ2_PICKUP_STATE_BIT,  =           //AMTZ2_PICKUP_STATE_BIT,
AMTZ3_TMR_IN_BIT           =           AMTZ2_TMR_IN_BIT,
AMTZ3_TMR_BIT              =           AMTZ2_TMR_BIT,
AMTZ3_ACC_TMR_IN_BIT       =           AMTZ2_ACC_TMR_IN_BIT,
AMTZ3_ACC_TMR_BIT          =           AMTZ2_ACC_TMR_BIT,
                                      
//DZ2_PICKUP_STATE_BIT,   =            //DZ2_PICKUP_STATE_BIT,
DZ3_DIR_TMR_IN_BIT        =            DZ2_DIR_TMR_IN_BIT,
DZ3_DIR_TMR_STATE_BIT     =            DZ2_DIR_TMR_STATE_BIT,
DZ3_INV_TMR_IN_BIT        =            DZ2_INV_TMR_IN_BIT,
DZ3_INV_TMR_STATE_BIT     =            DZ2_INV_TMR_STATE_BIT,
DZ3_DIR_ACC_TMR_IN_BIT    =            DZ2_DIR_ACC_TMR_IN_BIT,
DZ3_DIR_ACC_TMR_STATE_BIT =            DZ2_DIR_ACC_TMR_STATE_BIT,
DZ3_INV_ACC_TMR_IN_BIT    =            DZ2_INV_ACC_TMR_IN_BIT,
DZ3_INV_ACC_TMR_STATE_BIT =            DZ2_INV_ACC_TMR_STATE_BIT,
ACC_AMTZ4_TMR_IN_BIT        =          ACC_AMTZ2_TMR_IN_BIT,
ACC_DZ4__TMR_IN_BIT         =          ACC_DZ2__TMR_IN_BIT,
ACC_AMTZ4_TMR_BIT           =          ACC_AMTZ2_TMR_BIT,
ACC_DZ4__TMR_BIT            =          ACC_DZ2__TMR_BIT,
                                      
//AMTZ2_PICKUP_STATE_BIT,  =           //AMTZ2_PICKUP_STATE_BIT,
AMTZ4_TMR_IN_BIT           =           AMTZ2_TMR_IN_BIT,
AMTZ4_TMR_BIT              =           AMTZ2_TMR_BIT,
AMTZ4_ACC_TMR_IN_BIT       =           AMTZ2_ACC_TMR_IN_BIT,
AMTZ4_ACC_TMR_BIT          =           AMTZ2_ACC_TMR_BIT,
                                      
//DZ2_PICKUP_STATE_BIT,   =            //DZ2_PICKUP_STATE_BIT,
DZ4_DIR_TMR_IN_BIT        =            DZ2_DIR_TMR_IN_BIT,
DZ4_DIR_TMR_STATE_BIT     =            DZ2_DIR_TMR_STATE_BIT,
DZ4_INV_TMR_IN_BIT        =            DZ2_INV_TMR_IN_BIT,
DZ4_INV_TMR_STATE_BIT     =            DZ2_INV_TMR_STATE_BIT,
DZ4_DIR_ACC_TMR_IN_BIT    =            DZ2_DIR_ACC_TMR_IN_BIT,
DZ4_DIR_ACC_TMR_STATE_BIT =            DZ2_DIR_ACC_TMR_STATE_BIT,
DZ4_INV_ACC_TMR_IN_BIT    =            DZ2_INV_ACC_TMR_IN_BIT,
DZ4_INV_ACC_TMR_STATE_BIT =            DZ2_INV_ACC_TMR_STATE_BIT,

//
};
enum DZ_SEL_BIT_POS { 


DZ2_STAGE_BIT,
DZ3_STAGE_BIT,
DZ4_STAGE_BIT,
//STP_I_A_MCP_DST_LP_STAGE2_BIT,
//STP_I_A_MCP_DST_LP_STAGE3_BIT,
//STP_I_A_MCP_DST_LP_STAGE4_BIT,


TOTAL_DZ_STAGES_BITS
//
};
enum DZ_TMR_SEL_BIT_POS { 
STP_I_AMCP_DST_LP_STAGE_BIT,
STP_DIR_DST_LP_STAGE_BIT,
STP_INV_DST_LP_STAGE_BIT,

ACC_AMCP_TMR_IN_BIT,
ACC_DST_LP_TMR_IN_BIT,
ACC_AMCP_O_TMR_BIT,
ACC_DST_LP_O_TMR_BIT,

T_AMCP_IN_BIT,
T_ACC_AMCP_IN_BIT,
T_AMCP_OUT_BIT,
T_ACC_AMCP_OUT_BIT,

T_DIR_IN_BIT,
T_ACC_DIR_IN_BIT,
T_DIR_OUT_BIT,
T_ACC_DIR_OUT_BIT,

T_INV_IN_BIT,
T_ACC_INV_IN_BIT,
T_INV_OUT_BIT,
T_ACC_INV_OUT_BIT,


TOTAL_TMR_SEL_BITS
//
};
enum DZ_State_p1234_Modified_Const{
P1_MODIFIED_BIT,
P2_MODIFIED_BIT,
P3_MODIFIED_BIT,
P4_MODIFIED_BIT,

TOTAL_P_MODIFY_BITS

};
typedef union mcp_stp_state_Unn1{ 
   struct {
      unsigned int or2__i_0 :1; //0
      unsigned int or2__i_1 :1; //1
      unsigned int and3_i_0 :1; //2
      unsigned int and3_i_1 :1; //3
      unsigned int and4_i_0 :1; //4
      unsigned int and4_i_1 :1; //5
      unsigned int and5_i_0 :1; //6
      unsigned int and5_i_1 :1; //7
      unsigned int and6_i_0 :1; //8
      unsigned int and6_i_1 :1; //9
      unsigned int and4_o_0 :1; //10
      unsigned int and5_o_0 :1; //11
      unsigned int and6_o_0 :1; //12
      unsigned int or7__i_0 :1; //13
      unsigned int or7__i_1 :1; //14
      unsigned int or8__i_0 :1; //15
      unsigned int or8__i_1 :1; //16
      unsigned int not9_o_0 :1; //17
      unsigned int not10_o_0 :1;//18
      unsigned int and17_i_0 :1;//19 
      unsigned int and17_i_1 :1;//20 
      unsigned int or12__i_1 :1;//21
      unsigned int or12__i_0 :1;//22 external sig
      unsigned int or13__i_1 :1;//23 external sig
      unsigned int or13__i_0 :1;//24
      unsigned int nor18__i_1 :1;//25
      unsigned int nor18__i_0 :1;//26
      unsigned int not15_o_0 :1;//27
      unsigned int and16_i_0 :1;//28
      unsigned int and16_i_1 :1;//29
//      unsigned int  :1;//30
//      unsigned int  :1;//31
//      unsigned int ; :1//
//      unsigned int ; :1//
   
    } bool_vars;
    long lVl;
} Dz2_stp_p1_state; //ex- extended
typedef union mcp_stp_state_Unn2{ 
   struct {
      unsigned int and22_i_0 :1; //0
      unsigned int and22_i_1 :1; //1
      unsigned int and22_i_2 :1; //2
//      unsigned int and22_i_3 :1; //2
      unsigned int and22_i_4 :1; //3
      unsigned int and24_i_0 :1; //4
      unsigned int and24_i_1 :1; //5
      unsigned int and24_i_2 :1; //6
      unsigned int and24_i_3 :1; //7
      unsigned int and24_i_4 :1; //8
      unsigned int and26_i_0 :1; //9
      unsigned int and26_i_1 :1;//10
      unsigned int and26_i_2 :1;//11
      unsigned int and26_i_3 :1;//12
      unsigned int and26_i_4 :1;//13
      unsigned int and26_i_5 :1;//14
      unsigned int nor19_i_0 :1;//15
      unsigned int nor19_i_1 :1;//16
      unsigned int nor19_i_2 :1;//17
      unsigned int nor19_i_3 :1;//18
      unsigned int nor20_i_0 :1;//19
      unsigned int nor20_i_1 :1;//20
      unsigned int nor20_i_2 :1;//21
      unsigned int nor20_i_3 :1;//22
      unsigned int nor21_i_0 :1;//23
      unsigned int nor21_i_1 :1;//24
      unsigned int nor21_i_2 :1;//25
      unsigned int not23_o_0 :1;//26
      unsigned int not25_o_0 :1;//27
      unsigned int ror18__i_1 :1;//28
      unsigned int ror18__i_0 :1;//29
      unsigned int and22_i_3 :1;//30
      unsigned int b31 :1;//31    
    } bool_vars;
    long lVl;
} Dz2_stp_p2_state; //ex- extended
typedef union mcp_stp_state_Unn3{ 
   struct {
      unsigned int or27_i_0 :1; //0
      unsigned int or27_i_1 :1; //1
      unsigned int not28_o_0:1; //2         2
      unsigned int or29_i_0 :1; //3
      unsigned int or29_i_1 :1; //4
      unsigned int not30_o_0:1; //5
      unsigned int and31_i_0:1; //6
      unsigned int and31_i_1:1; //7
      unsigned int and31_i_2:1; //8
      unsigned int and32_i_0:1; //9
      unsigned int and32_i_1:1; //10
      unsigned int and32_i_2:1; //11
      unsigned int and31_o_0:1; //12
      unsigned int and32_o_0:1; //13
      unsigned int or33_i_0 :1; //14
      unsigned int or33_i_1 :1; //15
      unsigned int or34_i_0 :1; //16
      unsigned int or34_i_1 :1; //17
      unsigned int not35_o_0:1; //18
      unsigned int or36_i_0 :1; //19
      unsigned int or36_i_1 :1; //20
      unsigned int not37_o_0:1; //21
      unsigned int or38_i_0 :1; //22
      unsigned int or38_i_1 :1; //23
      unsigned int not39_o_0:1; //24
      unsigned int or40_i_0 :1; //25
      unsigned int or40_i_1 :1; //26
      unsigned int not41_o_0:1; //
      unsigned int b27 :1;//27
      unsigned int b28 :1;//28
      unsigned int b29 :1;//29
      unsigned int b30 :1;//30
      unsigned int b31 :1;//31    
    } bool_vars;
    long lVl;
} Dz2_stp_p3_state; //ex- extended
typedef union mcp_stp_state_Unn4{ 
   struct {
      unsigned int and42_i_0 :1; //0
      unsigned int and42_i_1 :1; //1
      unsigned int and42_i_2 :1; //2
      unsigned int and43_i_0 :1; //3
      unsigned int and43_i_1 :1; //4
      unsigned int and43_i_2 :1; //5
      unsigned int and44_i_0 :1; //6
      unsigned int and44_i_1 :1; //7
      unsigned int and44_i_2 :1; //8
      unsigned int and45_i_0 :1; //9
      unsigned int and45_i_1 :1;//10
      unsigned int and45_i_2 :1;//11
      unsigned int and42_o_0 :1;//12
      unsigned int and43_o_0 :1;//13
      unsigned int and44_o_0 :1;//14
      unsigned int and45_o_0 :1;//15
      unsigned int or46_i_0  :1;//16
      unsigned int or46_i_1  :1;//17
      unsigned int or46_i_2  :1;//18
      unsigned int or46_i_3  :1;//19
      unsigned int and11_i_0 :1;//20
      unsigned int and11_i_1 :1;//21
      unsigned int and14_i_0 :1;//22
      unsigned int and14_i_1 :1;//23
      unsigned int and11_o_0 :1;//24
      unsigned int b25 :1;//25
      unsigned int b26 :1;//26
      unsigned int b27 :1;//27
      unsigned int b28 :1;//28
      unsigned int b29 :1;//29
      unsigned int b30 :1;//30
      unsigned int b31 :1;//31    
    } bool_vars;
    long lVl;
} Dz2_stp_p4_state; //ex- extended
typedef struct tag_HdrBoolWord{
    char chIdxstage;
    char ch_p1234_modified;
}HdrBoolWordDsc;
typedef struct tag_BoolWord{
    struct BW{
    Dz2_stp_p1_state p1;
    Dz2_stp_p2_state p2;
    Dz2_stp_p3_state p3;
    Dz2_stp_p4_state p4;
    } ar_bw[TOTAL_DZ_STAGES_BITS];
    unsigned long ulStpDzfield;       //05
    HdrBoolWordDsc hdrBW;
    //May be insert Aux Information about State of Using this Object
}BoolWordsHldrDsc;
BoolWordsHldrDsc bw_dstLp_dt;
/*
Stp Dz must 1)Select phase
2)look Tz
3)use Dz1
*/

void dz2_handler(unsigned int *p_active_functions, unsigned int number_group_stp );
//=====================================================================================================
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//                  
//....................................................................................................
//=====================================================================================================
void dz2_handler(unsigned int *p_active_functions, unsigned int number_group_stp ){UNUSED(number_group_stp);UNUSED(p_active_functions);
//// ----------------  inner_outer_short_circuit It`s my name -------------------------
//struct{
//    char  ch_stage_selector;
//    __SETTINGS *p_current_settings_prt;
//    Dz2_stp_p1_state *p_p1;
//    Dz2_stp_p2_state *p_p2;
//    Dz2_stp_p3_state *p_p3;
//    Dz2_stp_p4_state *p_p4;
//    Dz2_stp_p2_state p2;
//    
//}sLV;
//static unsigned long u32_bit_dz2_ext = 0, u32_bit_dz3_ext = 0, u32_bit_dz4_ext = 0;
//unsigned long u32_bit_holder = 0; 
//{
//register long i;
//sLV.p_current_settings_prt = &current_settings_prt;
//sLV.ch_stage_selector = i = bw_dstLp_dt.hdrBW.chIdxstage;
//sLV.p_p1 = & bw_dstLp_dt.ar_bw[i].p1;
//sLV.p_p2 = & bw_dstLp_dt.ar_bw[i].p2;
//sLV.p_p3 = & bw_dstLp_dt.ar_bw[i].p3;
//sLV.p_p4 = & bw_dstLp_dt.ar_bw[i].p4;
////Clr untriggered command
//sLV.p_p1->lVl &= 0x0;
//sLV.p_p2->lVl &= 0x0;
//sLV.p_p3->lVl &= (1<<12) | (1<<13);//and31_o_0 and32_o_0
//sLV.p_p4->lVl &= (1<<12)|(1<<13)|(1<<14)|(1<<15);//and42_o_0 and43_o_0 and44_o_0 and45_o_0 
//sLV.p2.lVl = 0;                                      
//                                     
//                                     
//}
//    do{
//        //register void* pv;
//        register Dz2_stp_p1_state p1;
//        long lV,rU;
////        if(bw_dstLp_dt.hdrBW.ch_p1234_modified & (1<<P1_MODIFIED_BIT))
////            p1.lVl = sLV.p_p1->lVl;//Mask?
////        else
////            p1.lVl = 0;
////Now control that bits throw external variable
//        //p1.lVl = sLV.p_p1->lVl&((1<<22)|(1<<23));//# phase DZ dir/inv
//        p1.lVl = 0;
//        if(_CHECK_SET_BIT(p_active_functions, RANG_3F_DZ_DIR_INV) != 0){
//                p1.bool_vars.or12__i_0 = 1;
//                p1.bool_vars.or13__i_1 = 1;
//        }       
//        if (sLV.ch_stage_selector == DZ2_STAGE_BIT){
//            if(_CHECK_SET_BIT(p_active_functions, RANG_BLOCK_PR_DZ2) != 0){
//                lV = 0;
//
//            }
//            else{
//                lV = 1;
//                p1.bool_vars.and4_i_0 = lV;
//                p1.bool_vars.and5_i_0 = lV;
//                p1.bool_vars.and6_i_0 = lV;
//            }
//            rU = (long)(sLV.p_current_settings_prt->control_dz);
//            lV = (MASKA_FOR_BIT(INDEX_CTR_DZ2_CONST_PR));
//            lV &= rU;
//            if(lV != 0)
//                p1.bool_vars.or2__i_0 = 1;
//                
//            if(_CHECK_SET_BIT(p_active_functions, RANG_OP_PR_DZ2) != 0)
//                p1.bool_vars.or2__i_1 = 1;
//
//            //rU = (unsigned long)(sLV.p_current_settings_prt->control_dz);
//            lV =(MASKA_FOR_BIT(INDEX_CTR_DZ2_PR_VID_DV));lV &= rU;
//            if(lV != 0)
//                p1.bool_vars.and3_i_0 = 1;  
//            if(_CHECK_SET_BIT(p_active_functions, RANG_STATE_VV) != 0)
//                p1.bool_vars.and3_i_1 = 1;  
//            //or2
//            if( (p1.lVl&((1<<0)|(1<<1))) > 0 )
//                p1.bool_vars.and4_i_1 = 1;
//            //and3
//            rU = p1.lVl&((1<<2)|(1<<3)); 
//            if(rU == ((1<<2)|(1<<3)))
//            u32_bit_holder |= (1<< ACC_AMCP_TMR_IN_BIT)|(1<<ACC_DST_LP_TMR_IN_BIT);
//            _TIMER_IMPULSE(INDEX_TIMER_DZ2_AMTZ_VVID_PR, sLV.p_current_settings_prt->timeout_dz2_amtz_vvid_pr[number_group_stp],
//  u32_bit_dz2_ext, ACC_AMCP_TMR_IN_BIT,u32_bit_holder, ACC_AMCP_TMR_IN_BIT, u32_bit_holder, ACC_AMCP_O_TMR_BIT);
//            _TIMER_IMPULSE(INDEX_TIMER_DZ2_VVID_PR, sLV.p_current_settings_prt->timeout_dz2_vvid_pr[number_group_stp],
//  u32_bit_dz2_ext,ACC_DST_LP_TMR_IN_BIT ,u32_bit_holder, ACC_DST_LP_TMR_IN_BIT, u32_bit_holder, ACC_DST_LP_O_TMR_BIT);
//            //and6
//            if ( u32_bit_holder&(1<<ACC_AMCP_O_TMR_BIT ) )
//                p1.bool_vars.and6_i_1 = 1;
//            //and5
//            if ( u32_bit_holder&(1<<ACC_DST_LP_O_TMR_BIT ) )
//                p1.bool_vars.and5_i_1 = 1;
//    
//        }
//        else if(sLV.ch_stage_selector == DZ3_STAGE_BIT) {
//            if(_CHECK_SET_BIT(p_active_functions, RANG_BLOCK_PR_DZ3) != 0){
//                lV = 0;
//            } else{
//                lV = 1;
//                p1.bool_vars.and4_i_0 = lV;
//                p1.bool_vars.and5_i_0 = lV;
//                p1.bool_vars.and6_i_0 = lV;
//            }
//            lV = (sLV.p_current_settings_prt->control_dz);
//            rU = (MASKA_FOR_BIT(INDEX_CTR_DZ3_CONST_PR));
//            lV &= rU;
//            if(lV != 0)
//                p1.bool_vars.or2__i_0 = 1;
//            if(_CHECK_SET_BIT(p_active_functions, RANG_OP_PR_DZ3) != 0)
//                p1.bool_vars.or2__i_1 = 1;
//      
//            rU  = (sLV.p_current_settings_prt->control_dz);
//            lV =(MASKA_FOR_BIT(INDEX_CTR_DZ3_PR_VID_DV));lV &= rU;
//            if(lV != 0)
//                p1.bool_vars.and3_i_0 = 1;  
//            if(_CHECK_SET_BIT(p_active_functions, RANG_STATE_VV) != 0)
//                p1.bool_vars.and3_i_1 = 1;  
//            //or2
//            if( (p1.lVl&((1<<0)|(1<<1))) > 0 )
//                p1.bool_vars.and4_i_1 = 1;
//            //and3
//            rU = p1.lVl&((1<<2)|(1<<3)); 
//            if(rU == ((1<<2)|(1<<3)))
//            u32_bit_holder |= (1<< ACC_AMCP_TMR_IN_BIT)|(1<<ACC_DST_LP_TMR_IN_BIT);
//                    _TIMER_IMPULSE(INDEX_TIMER_DZ3_AMTZ_VVID_PR, sLV.p_current_settings_prt->timeout_dz3_amtz_vvid_pr[number_group_stp],
//  u32_bit_dz3_ext, ACC_AMCP_TMR_IN_BIT,u32_bit_holder, ACC_AMCP_TMR_IN_BIT, u32_bit_holder, ACC_AMCP_O_TMR_BIT);
//            _TIMER_IMPULSE(INDEX_TIMER_DZ3_VVID_PR, sLV.p_current_settings_prt->timeout_dz3_vvid_pr[number_group_stp],
//  u32_bit_dz3_ext, ACC_DST_LP_TMR_IN_BIT,u32_bit_holder, ACC_DST_LP_TMR_IN_BIT, u32_bit_holder, ACC_DST_LP_O_TMR_BIT);
//            //and6
//            if ( u32_bit_holder&(1<<ACC_AMCP_O_TMR_BIT ) )
//                p1.bool_vars.and6_i_1 = 1;
//            //and5
//            if ( u32_bit_holder&(1<<ACC_DST_LP_O_TMR_BIT ) )
//                p1.bool_vars.and5_i_1 = 1;
//
//        }
//        else if(sLV.ch_stage_selector == DZ4_STAGE_BIT){
//            if(_CHECK_SET_BIT(p_active_functions, RANG_BLOCK_PR_DZ4) != 0){
//                lV = 0;
//            }
//            else{
//                lV = 1;
//                p1.bool_vars.and4_i_0 = lV;
//                p1.bool_vars.and5_i_0 = lV;
//                p1.bool_vars.and6_i_0 = lV;
//            }
//            lV = (sLV.p_current_settings_prt->control_dz);
//            lV &=(MASKA_FOR_BIT(INDEX_CTR_DZ4_CONST_PR));
//            if(lV != 0)
//                p1.bool_vars.or2__i_0 = 1;
//            if(_CHECK_SET_BIT(p_active_functions, RANG_OP_PR_DZ4) != 0)
//                p1.bool_vars.or2__i_1 = 1;
//      
//            rU = (sLV.p_current_settings_prt->control_dz);
//            rU &= (MASKA_FOR_BIT(INDEX_CTR_DZ4_PR_VID_DV));
//            if(rU != 0)
//                p1.bool_vars.and3_i_0 = 1;  
//            if(_CHECK_SET_BIT(p_active_functions, RANG_STATE_VV) != 0)
//                p1.bool_vars.and3_i_1 = 1;  
//            //or2
//            if( (p1.lVl&((1<<0)|(1<<1))) > 0 )
//                p1.bool_vars.and4_i_1 = 1;
//            //and3
//            rU = p1.lVl&((1<<2)|(1<<3)); 
//            if(rU == ((1<<2)|(1<<3)))
//            u32_bit_holder |= (1<< ACC_AMCP_TMR_IN_BIT)|(1<<ACC_DST_LP_TMR_IN_BIT);
//                    _TIMER_IMPULSE(INDEX_TIMER_DZ4_AMTZ_VVID_PR, sLV.p_current_settings_prt->timeout_dz4_amtz_vvid_pr[number_group_stp],
//  u32_bit_dz4_ext, ACC_AMCP_TMR_IN_BIT,u32_bit_holder, ACC_AMCP_TMR_IN_BIT, u32_bit_holder, ACC_AMCP_O_TMR_BIT);
//            _TIMER_IMPULSE(INDEX_TIMER_DZ4_VVID_PR, sLV.p_current_settings_prt->timeout_dz4_vvid_pr[number_group_stp],
//  u32_bit_dz4_ext, ACC_DST_LP_TMR_IN_BIT,u32_bit_holder, ACC_DST_LP_TMR_IN_BIT, u32_bit_holder, ACC_DST_LP_O_TMR_BIT);
//            //and6
//            if ( u32_bit_holder&(1<<ACC_AMCP_O_TMR_BIT ) )
//                p1.bool_vars.and6_i_1 = 1;
//            //and5
//            if ( u32_bit_holder&(1<<ACC_DST_LP_O_TMR_BIT ) )
//                p1.bool_vars.and5_i_1 = 1;
//            
//        }
//    
//        rU = p1.lVl&((1<<4)|(1<<5)); //and4
//        if(rU == ((1<<4)|(1<<5))){    
//        p1.bool_vars.and4_o_0 = 1;//p1.bool_vars.or7__i_0 = 1;
//        }
//        rU = p1.lVl&((1<<6)|(1<<7)); 
//        if(rU == ((1<<6)|(1<<7))){    
//        p1.bool_vars.and5_o_0 = 1;  //p1.bool_vars.or8__i_0 = 1;
//        }
//        rU = p1.lVl&((1<<8)|(1<<9)); 
//        if(rU == ((1<<8)|(1<<9)))    
//        p1.bool_vars.and6_o_0 = 1;
//        
//        
//        
//        // if( (p1.lVl&((1<<13)|(1<<14))) != 0 ){//or7 2 customer
//         if( (p1.lVl&((1<<10)|(1<<11))) != 0 ){//or7 2 customer
//                sLV.p_p3->lVl |= ((1<<22) | (1<<16)) ;//Avt pry vkl VV uskorenye DZ
//                //or38_i_0 :1; //21 or34_i_0 :1; //15
//                bw_dstLp_dt.hdrBW.ch_p1234_modified |= (1<<P3_MODIFIED_BIT);
//        }else{
//            p1.bool_vars.not9_o_0 = 1;//Net uskoreniya
//             sLV.p_p3->lVl &= ~((1<<22) | (1<<16)) ;
//        }   
//        // if( (p1.lVl&((1<<15)|(1<<16))) != 0 ){//or8 2 customer DZ
//         if( (p1.lVl&((1<<10)|(1<<12))) != 0 ){//or8 2 customer DZ
//               //or27_i_0 :1; //0
//               sLV.p_p3->lVl |= (1<<0);//Avt pry vkl VV uskorenye AMTZ
//                bw_dstLp_dt.hdrBW.ch_p1234_modified |= (1<<P3_MODIFIED_BIT);
//        }else{
//                p1.bool_vars.not10_o_0  = 1;//Net uskoreniya AMTZ
//                sLV.p_p3->lVl &= ~(1<<0);
//        }
//        sLV.p_p1->lVl = p1.lVl;        
//    }while(sLV.ch_stage_selector > TOTAL_DZ_STAGES_BITS);
//    
//    do{
//        //register void* pv;
//        register Dz2_stp_p2_state p2;
//        long lV,rU;
//        
//        //rU = chGbl_3Phs_Dz;//?
////      if(_CHECK_SET_BIT(p_active_functions, RANG_3F_DZ_DIR_INV) != 0){
////          sLV.p_p1->bool_vars.or12__i_0 = 1;
////          sLV.p_p1->bool_vars.or13__i_1 = 1;
////        }
////      else{
////            sLV.p_p1->bool_vars.or12__i_0 = 0;
////            sLV.p_p1->bool_vars.or13__i_1 = 0;
////        }  
//        if(_CHECK_SET_BIT(p_active_functions, RANG_SNKN_DZ) != 0){
//            sLV.p_p4->bool_vars.and14_i_0 = 1;
//            sLV.p_p4->bool_vars.and11_i_1 = 1;
//        }else{
//            sLV.p_p4->bool_vars.and14_i_0 = 0;
//            sLV.p_p4->bool_vars.and11_i_1 = 0;
//        }   
////        if(bw_dstLp_dt.hdrBW.ch_p1234_modified & (1<<P2_MODIFIED_BIT))
////            p2.lVl = sLV.p_p2->lVl;//Mask?
////        else
//            p2.lVl = 0;
//            
//            //and 11//sLV.p_p4->lVl |= (1<<20);//and11_i_0 :1;//20
//            //sLV.p_p4->lVl |= (1<<21);//and11_i_1 :1;//21
//
//        if (sLV.ch_stage_selector == DZ2_STAGE_BIT){
//        
//            //Eval FCHE
//            rU = m_s_phs_stp_state.lVl;
//            if(rU&(1<<0)){//One
//                //Select Max
//                lV = 0;//Za_A;
//                if(rU&(1<<5))
//                    lV = 1;//Za_B;
//                else if(rU&(1<<6))
//                    lV = 2;//Za_C;
//                //Check Sector
//                lV = sector_directional_dz[DZ2_STAGE_BIT][lV];
//            }else if(rU&(1<<1)){ //2
//                     register long rCtr = 0;lV = 0;     
//                    do{
//                        if(rCtr == 0){
//                            if(rU&(1<<(IA_M0_P9+7)))
//                                lV = sector_directional_dz[DZ2_STAGE_BIT][0];
//                        }
//                        if(rCtr == 1){
//                            if(rU&(1<<(IB_M0_P9+7)))
//                                lV = sector_directional_dz[DZ2_STAGE_BIT][1];
//                        }
//                        if(rCtr == 2){
//                            if(rU&(1<<(IC_M0_P9+7)))
//                                lV = sector_directional_dz[DZ2_STAGE_BIT][2];
//                        }
//                    }while( (lV <= 0)&& rCtr++ < 2  );
//
//            }else{//M
//                //Check Sector  
//                register long  rCtr = 0;lV = 0;     
//                do{
//                    if(rCtr == 0){
//                        if(rU&(1<<(IA_M0_P9+7)))
//                            lV = sector_directional_dz[DZ2_STAGE_BIT][0];
//                    }
//                    if(rCtr == 1){
//                        if(rU&(1<<(IB_M0_P9+7)))
//                            lV = sector_directional_dz[DZ2_STAGE_BIT][1];
//                    }
//                    if(rCtr == 2){
//                        if(rU&(1<<(IC_M0_P9+7)))
//                            lV = sector_directional_dz[DZ2_STAGE_BIT][2];
//                    }
//                }while( (lV <= 0)&& rCtr++ < 2  );
//            }
//            _CLEAR_BIT(p_active_functions, RANG_SECTOR_DIR_DZ2);
//            _CLEAR_BIT(p_active_functions, RANG_SECTOR_INV_DZ2);
//            if(lV == 1){
//                _SET_BIT(p_active_functions, RANG_SECTOR_DIR_DZ2);
//                sLV.p_p1->bool_vars.or12__i_1 = 1;
//            }else if(lV == 2){
//                _SET_BIT(p_active_functions, RANG_SECTOR_INV_DZ2);
//                 sLV.p_p1->bool_vars.or13__i_0 = 1;
//            }
//                        #ifdef DEBUG_CONFIGURATION
//sLV.p_p1->bool_vars.or13__i_0 = 1; sLV.p_p1->bool_vars.or12__i_1 = 1;
//#else
//  
//#endif
//            //else if(lV == (-1)){
//            //  ;
//            //}
////            if( (sLV.p_p1->lVl&((1<<22)|(1<<21))) > 0 )
////                p2.bool_vars.and22_i_3 = 1;
////            if( (sLV.p_p1->lVl&((1<<23)|(1<<24))) > 0 )
////                p2.bool_vars.and24_i_3 = 1;
//                
//            if(_CHECK_SET_BIT(p_active_functions, RANG_BLOCK_DZ2) != 0){
//                lV = 1;
//                p2.bool_vars.nor19_i_0 = lV;
//                p2.bool_vars.nor20_i_0 = lV;
//                p2.bool_vars.nor21_i_0 = lV;
//            }
//            
//            if(_CHECK_SET_BIT(p_active_functions, RANG_PO_I_BLK_DZ) != 0){
//                lV = 1;
//                p2.bool_vars.nor19_i_1 = lV;
//                p2.bool_vars.nor20_i_1 = lV;
//                p2.bool_vars.nor21_i_1 = lV;
//            }   
//            lV = (sLV.p_current_settings_prt->control_dz);
//            rU =(MASKA_FOR_BIT(INDEX_CTR_DZ2_AMTZ)); rU &= lV;
//            //not15
//            if(rU == 0){
//                sLV.p_p1->bool_vars.not15_o_0 = 1;
//                sLV.p_p4->bool_vars.and14_i_1 = 0;//lVl |= (1<<23);//and14_i_1 :1;//23
//                sLV.p_p4->bool_vars.and11_i_0 = 1;//and11
//                p2.bool_vars.and26_i_5 = 0;//and26
//            }else{
//                sLV.p_p1->bool_vars.not15_o_0 = 0;//?
//                sLV.p_p4->bool_vars.and14_i_1 = 1;
//                sLV.p_p4->bool_vars.and11_i_0 = 0;
//                p2.bool_vars.and26_i_5 = 1;
//            }
//            //if(_CHECK_SET_BIT(p_active_functions, RANG_SNKN_DZ) != 0){
//            //  sLV.p_p4->bool_vars.and14_i_0 = 1;
//            //  sLV.p_p4->bool_vars.and11_i_1 = 0;
//            //}
//            //else{
//            //sLV.p_p4->bool_vars.and14_i_0 = 1;
//            // sLV.p_p4->bool_vars.and11_i_1 = 0;
//            //}    
//                
//            if((sLV.p_p4->lVl&((1<<20)|(1<<21))) == ((1<<20)|(1<<21)))
//                 sLV.p_p4->bool_vars.and11_o_0 = 1;
//            else 
//                sLV.p_p4->bool_vars.and11_o_0 = 0;
//            if( ((sLV.p_p1->lVl&((1<<22)|(1<<21))) > 0) || sLV.p_p4->bool_vars.and11_o_0 )
//                p2.bool_vars.and22_i_3 = 1;
//            if( ((sLV.p_p1->lVl&((1<<23)|(1<<24))) > 0) || sLV.p_p4->bool_vars.and11_o_0)
//                p2.bool_vars.and24_i_3 = 1; 
//            //lV = (sLV.p_current_settings_prt->control_dz); This Line for reading
//            rU =(MASKA_FOR_BIT(INDEX_CTR_DZ2)); rU &= lV;
//            if(rU != 0){
//                rU = 1;
//                p2.bool_vars.and22_i_0 = rU;
//                p2.bool_vars.and24_i_0 = rU;
//                p2.bool_vars.and26_i_0 = rU;
//            }   
//            //lV = (sLV.p_current_settings_prt->control_dz); This Line for reading
//            rU = (MASKA_FOR_BIT(INDEX_CTR_DZ2_DIR)); rU &= lV;
//            if(rU != 0)
//                p2.bool_vars.and22_i_1 = 1;
//            //lV = (sLV.p_current_settings_prt->control_dz); This Line for reading
//            rU = (MASKA_FOR_BIT(INDEX_CTR_DZ2_INV)); rU &= lV;
//            if(rU != 0)
//                p2.bool_vars.and24_i_1 = 1;
//
//                
//            if(_CHECK_SET_BIT(p_active_functions, RANG_PO_AMTZ_DZ2) != 0){
//                lV = 1;
//                p2.bool_vars.nor19_i_3 = lV;
//                p2.bool_vars.nor20_i_3 = lV;
//                sLV.p_p1->bool_vars.nor18__i_1 = lV;  //p2.bool_vars.or18__i_1 = lV;
//            }   
//
//            if(_CHECK_SET_BIT(p_active_functions, RANG_PO_DIR_DZ2) == 0){
//                p2.bool_vars.not23_o_0 = 1;
//                p2.bool_vars.and26_i_1 = 1;
//            }
//            if(_CHECK_SET_BIT(p_active_functions, RANG_PO_INV_DZ2) == 0){
//                p2.bool_vars.not25_o_0 = 1;
//                p2.bool_vars.and26_i_2 = 1;
//            }   
////          sLV.p_p4->bool_vars.and14_i_0 = 0;  
////          if(_CHECK_SET_BIT(p_active_functions, RANG_SNKN_DZ) != 0)
////              sLV.p_p4->bool_vars.and14_i_0 = 1;
////          lV = _CHECK_SET_BIT(p_active_functions, RANG_SNKN_DZ);
////          if (lV){//-!
////              sLV.p_p4->lVl |= (1<<22)|(1<<21);//and11_i_1 and14_i_0
////          }
//            //Eval Stp    
//            rU = p2.bool_vars.not23_o_0;
//            long pick_up_Resistance_dstLp2 = 0;
//            if(rU == 0)
//                pick_up_Resistance_dstLp2 = (long)sLV.p_current_settings_prt->pickup_dz2_dir[number_group_stp] * KOEF_POVERNENNJA_GENERAL_DOWN  / 100;
//            else
//                pick_up_Resistance_dstLp2 = (long)sLV.p_current_settings_prt->pickup_dz2_dir[number_group_stp];
//
//            lV = m_s_phs_stp_state.lVl;
//            
//            if(lV&(1<<0)){//One
//                if((sLV.p_p4->lVl&((1<<20)|(1<<21))) == ((1<<20)|(1<<21))){//Check Fault and11
//                    rU = Za_A;
//                    if(lV&(1<<5))
//                        rU = Za_B;
//                    else if(lV&(1<<6))
//                            rU = Za_C;
//                    
//                }
//                else{
//                    rU = Z_A;
//                    if(lV&(1<<5))
//                        rU = Z_B;
//                    else if(lV&(1<<6))
//                            rU = Z_C;       
//                }
//                //current_settings_prt.pickup_dz1
//            }else if(lV&(1<<1)){ //2
//    
//                if((sLV.p_p4->lVl&((1<<20)|(1<<21))) == ((1<<20)|(1<<21))){//Check Fault and11
//                    rU = Za_AB;//( (1<< IA_M0_P9) | (1<<IB_M0_P9) | (1<<IC_L0_P9 ))
//                    if( (lV&((1<<(IB_M0_P9+7)) | (1<<(IC_M0_P9+7)) | (1<<(IA_L0_P9+7))))== ((1<<(IB_M0_P9+7)) | (1<<(IC_M0_P9+7)) | (1<<(IA_L0_P9+7)))
//                    )// if( lV == (lV&((1<<(IB_M0_P9+7)) | (1<<(IC_M0_P9+7)) | (1<<(IA_L0_P9+7)))) )
//                        rU = Za_BC;
//                    else if( (lV&((1<<(IA_M0_P9+7)) | (1<<(IC_M0_P9+7)) | (1<<(IB_L0_P9+7)))) == ((1<<(IA_M0_P9+7)) | (1<<(IC_M0_P9+7)) | (1<<(IB_L0_P9+7)))   )  //if( lV == (lV&((1<<(IA_M0_P9+7)) | (1<<(IC_M0_P9+7)) | (1<<(IB_L0_P9+7)))) )
//                            rU = Za_CA; 
//                }
//                else{
//                    rU = Z_AB;
//                    if( (lV&((1<<(IB_M0_P9+7)) | (1<<(IC_M0_P9+7)) | (1<<(IA_L0_P9+7)))) == ((1<<(IB_M0_P9+7)) | (1<<(IC_M0_P9+7)) | (1<<(IA_L0_P9+7))) )//if( lV == (lV&((1<<(IB_M0_P9+7)) | (1<<(IC_M0_P9+7)) | (1<<(IA_L0_P9+7)))))
//                        rU = Z_BC;
//                    else if( (lV&((1<<(IA_M0_P9+7)) | (1<<(IC_M0_P9+7)) | (1<<(IB_L0_P9+7)))) == ((1<<(IA_M0_P9+7)) | (1<<(IC_M0_P9+7)) | (1<<(IB_L0_P9+7))) )//if( lV == (lV&((1<<(IA_M0_P9+7)) | (1<<(IC_M0_P9+7)) | (1<<(IB_L0_P9+7)))) )
//                            rU = Z_CA;  
//                }
//            }
//            else{//M
//                if((sLV.p_p4->lVl&((1<<20)|(1<<21))) == ((1<<20)|(1<<21))){//Check Fault
//                    rU = Za_3;//lV&(1<<2) Select Avar
//                }
//                else{
//                    rU = Z_3;
//                }
//            }
//            lV = resistance[rU];    
//            if(  (lV > 0) && (lV < pick_up_Resistance_dstLp2)  ){
//                p2.bool_vars.and22_i_2 = 1;Test_Values[0] = lV;}
//            else
//                p2.bool_vars.and22_i_2 = 0;
//            #ifdef DEBUG_CONFIGURATION
//p2.bool_vars.and22_i_2 = 1;  //? p2.bool_vars.and24_i_2 = 1; 
//#else
//  
//#endif
//    
//            lV = p2.bool_vars.not25_o_0;
//            //long pick_up_Resistance_dstLp2 = 0;
//            if(lV == 0)
//                pick_up_Resistance_dstLp2 = (long)sLV.p_current_settings_prt->pickup_dz2_inv[number_group_stp] * KOEF_POVERNENNJA_GENERAL_DOWN  / 100;
//            else
//                pick_up_Resistance_dstLp2 = (long)sLV.p_current_settings_prt->pickup_dz2_inv[number_group_stp];   
//            lV = resistance[rU];
//            if(  (lV > 0) && (lV < pick_up_Resistance_dstLp2)  ){
//                p2.bool_vars.and24_i_2 = 1;Test_Values[1] = lV;}
//            else
//                p2.bool_vars.and24_i_2 = 0;
//            #ifdef DEBUG_CONFIGURATION11
//p2.bool_vars.and24_i_2 = 1;  
//#else
//  
//#endif            
//            //and14
//            //sLV.p_p4->lVl |= (1<<22);//and14_i_0 :1;//22
//            //sLV.p_p4->lVl |= (1<<23);//and14_i_1 :1;//23  
//            rU = (sLV.p_p4->lVl)&((1<<22)|(1<<23)); //and14
//            if(rU == ((1<<22)|(1<<23))){
//                //-sLV.p_p1->bool_vars.and4_o_0 = 1;
//                //and16
//                sLV.p_p1->bool_vars.and16_i_0 = 1;
//                //and17
//                sLV.p_p1->bool_vars.and17_i_0 = 1;
//                //or18
//                sLV.p_p1->bool_vars.nor18__i_0 = 1;
//            }
//            sLV.p_p1->bool_vars.and16_i_1 = p2.bool_vars.not23_o_0;  
//            sLV.p_p1->bool_vars.and17_i_1 = p2.bool_vars.not25_o_0;
//            lV = sLV.p_p1->lVl;
//            lV &= ((1<<28)|(1<<29));
//            if(lV == ((1<<28)|(1<<29)))//and16 
//                p2.bool_vars.nor19_i_2 = 1;
//
//            lV = sLV.p_p1->lVl;
//            lV &= ((1<<20)|(1<<19));
//            if(lV == ((1<<20)|(1<<19)))//and17 
//                p2.bool_vars.nor20_i_2 = 1;
//                
//            if( (sLV.p_p1->lVl&((1<<25)|(1<<26))) != 0 ){//or18
//                p2.bool_vars.nor21_i_2 = 0;
//            }
//            else{
//                p2.bool_vars.nor21_i_2 = 1;
//            }
//            sLV.p2 = p2;
//            //PO Calc
//            lV = p2.bool_vars.nor20_i_3;//STP_I_A_MCP_DST_LP_STAGE2_BIT
//            unsigned long pick_up_I_Amcp_dstLp2 = 0;
//            if(lV){
//                pick_up_I_Amcp_dstLp2 = sLV.p_current_settings_prt->pickup_dz2_amtz[number_group_stp] * KOEF_POVERNENNJA_MTZ_I_UP  / 100;
//                }
//            else{   
//                pick_up_I_Amcp_dstLp2 = sLV.p_current_settings_prt->pickup_dz2_amtz[number_group_stp];
//            }
//            if( (measurement[IM_IA] > pick_up_I_Amcp_dstLp2)
//                || (measurement[IM_IB] > pick_up_I_Amcp_dstLp2)
//                || (measurement[IM_IC] > pick_up_I_Amcp_dstLp2)
//            )
//                p2.bool_vars.and26_i_4 = 1;//rU = 1;
//            else
//                p2.bool_vars.and26_i_4 = 0;//rU = 0;
//            //nor19 
//            if( (p2.lVl&((1<<15)|(1<<16)|(1<<17)|(1<<18)) ) != 0 ){//
//                p2.bool_vars.and22_i_4 = 0;
//            }
//            else{
//                p2.bool_vars.and22_i_4 = 1;
//            }
//            //nor20 
//            if( (p2.lVl&((1<<19)|(1<<20)|(1<<21)|(1<<22)) ) != 0 ){//
//                p2.bool_vars.and24_i_4 = 0;
//            }
//            else{
//                p2.bool_vars.and24_i_4 = 1;
//            }
//            //nor21 
//            if( (p2.lVl&((1<<23)|(1<<24)|(1<<25)) ) != 0 ){//
//                p2.bool_vars.and26_i_3 = 0;
//            }
//            else{
//                p2.bool_vars.and26_i_3 = 1;
//            }
//            //lV = sLV.p_p1->lVl;
//            lV = p2.lVl&((1<<9)|(1<<10)|(1<<11)|(1<<12)|(1<<13)|(1<<14));
//            if(lV == ((1<<9)|(1<<10)|(1<<11)|(1<<12)|(1<<13)|(1<<14))){//and26 9 10 11 12 13 14
//                _SET_BIT(p_active_functions, RANG_PO_AMTZ_DZ2);
//                u32_bit_holder |= 1<<STP_I_AMCP_DST_LP_STAGE_BIT;
//            }   
//            else
//                _CLEAR_BIT(p_active_functions, RANG_PO_AMTZ_DZ2);
//            
//            rU = p2.lVl&((1<<4)|(1<<5)|(1<<6)|(1<<7)|(1<<8));//rU = ((1<<4)|(1<<5)|(1<<6)|(1<<7)|(1<<8));
//            if(rU == ((1<<4)|(1<<5)|(1<<6)|(1<<7)|(1<<8))){//and24 4 5 6 7 8
//                _SET_BIT(p_active_functions, RANG_PO_INV_DZ2);
//                u32_bit_holder |= 1<<STP_INV_DST_LP_STAGE_BIT;
//            }   
//            else
//                _CLEAR_BIT(p_active_functions, RANG_PO_INV_DZ2);
//            
//            rU = p2.lVl&((1<<0)|(1<<30)|(1<<1)|(1<<2)|(1<<3));
//            if(rU == ((1<<0)|(1<<30)|(1<<1)|(1<<2)|(1<<3))){//and22 0 1 2 3
//                _SET_BIT(p_active_functions, RANG_PO_DIR_DZ2);
//                u32_bit_holder |= 1<<STP_DIR_DST_LP_STAGE_BIT;
//            }
//            else
//                _CLEAR_BIT(p_active_functions, RANG_PO_DIR_DZ2);
//
//
//        }
//        else if(sLV.ch_stage_selector == DZ3_STAGE_BIT){
//                        //Eval FCHE
//            rU = m_s_phs_stp_state.lVl;
//            if(rU&(1<<0)){//One
//                //Select Max
//                lV = 0;//Za_A;
//                if(rU&(1<<5))
//                    lV = 1;//Za_B;
//                else if(rU&(1<<6))
//                    lV = 2;//Za_C;
//                //Check Sector
//                lV = sector_directional_dz[DZ3_STAGE_BIT][lV];
//            }else if(rU&(1<<1)){ //2
//                     register long rCtr = 0;lV = 0;     
//                    do{
//                        if(rCtr == 0){
//                            if(rU&(1<<(IA_M0_P9+7)))
//                                lV = sector_directional_dz[DZ3_STAGE_BIT][0];
//                        }
//                        if(rCtr == 1){
//                            if(rU&(1<<(IB_M0_P9+7)))
//                                lV = sector_directional_dz[DZ3_STAGE_BIT][1];
//                        }
//                        if(rCtr == 2){
//                            if(rU&(1<<(IC_M0_P9+7)))
//                                lV = sector_directional_dz[DZ3_STAGE_BIT][2];
//                        }
//                    }while( (lV <= 0)&& rCtr++ < 2  );
//
//            }else{//M
//                //Check Sector  
//                register long  rCtr = 0;lV = 0;     
//                do{
//                    if(rCtr == 0){
//                        if(rU&(1<<(IA_M0_P9+7)))
//                            lV = sector_directional_dz[DZ3_STAGE_BIT][0];
//                    }
//                    if(rCtr == 1){
//                        if(rU&(1<<(IB_M0_P9+7)))
//                            lV = sector_directional_dz[DZ3_STAGE_BIT][1];
//                    }
//                    if(rCtr == 2){
//                        if(rU&(1<<(IC_M0_P9+7)))
//                            lV = sector_directional_dz[DZ3_STAGE_BIT][2];
//                    }
//                }while( (lV <= 0)&& rCtr++ < 2  );
//            }
//            _CLEAR_BIT(p_active_functions, RANG_SECTOR_DIR_DZ3);
//            _CLEAR_BIT(p_active_functions, RANG_SECTOR_INV_DZ3);
//            if(lV == 1){
//                _SET_BIT(p_active_functions, RANG_SECTOR_DIR_DZ3);
//                sLV.p_p1->bool_vars.or12__i_1 = 1;
//            }else if(lV == 2){
//                _SET_BIT(p_active_functions, RANG_SECTOR_INV_DZ3);
//                 sLV.p_p1->bool_vars.or13__i_0 = 1;
//            }
//            //else if(lV == (-1)){
//            //  ;
//            //}
////            if( (sLV.p_p1->lVl&((1<<22)|(1<<21))) > 0 )
////                p2.bool_vars.and22_i_3 = 1;
////            if( (sLV.p_p1->lVl&((1<<23)|(1<<24))) > 0 )
////                p2.bool_vars.and24_i_3 = 1;
//              
//            if(_CHECK_SET_BIT(p_active_functions, RANG_BLOCK_DZ3) != 0){
//                lV = 1;
//                p2.bool_vars.nor19_i_0 = lV;
//                p2.bool_vars.nor20_i_0 = lV;
//                p2.bool_vars.nor21_i_0 = lV;
//            }
//            
//            if(_CHECK_SET_BIT(p_active_functions, RANG_PO_I_BLK_DZ) != 0){
//                lV = 1;
//                p2.bool_vars.nor19_i_1 = lV;
//                p2.bool_vars.nor20_i_1 = lV;
//                p2.bool_vars.nor21_i_1 = lV;
//            }   
//            lV = (sLV.p_current_settings_prt->control_dz);
//            rU = (MASKA_FOR_BIT(INDEX_CTR_DZ3_AMTZ)); rU &= lV;
//            //not15
//            if(rU == 0){
//                sLV.p_p1->bool_vars.not15_o_0 = 1;
//                sLV.p_p4->bool_vars.and14_i_1 = 0;//lVl |= (1<<23);//and14_i_1 :1;//23
//                sLV.p_p4->bool_vars.and11_i_0 = 1;//and11
//                p2.bool_vars.and26_i_5 = 0;//and26
//            }else{
//                sLV.p_p1->bool_vars.not15_o_0 = 0;//?
//                sLV.p_p4->bool_vars.and14_i_1 = 1;
//                sLV.p_p4->bool_vars.and11_i_0 = 0;
//                p2.bool_vars.and26_i_5 = 1;
//            }
////-!            if(_CHECK_SET_BIT(p_active_functions, RANG_SNKN_DZ) != 0){
////-!              sLV.p_p4->bool_vars.and14_i_0 = 1;
////-!              sLV.p_p4->bool_vars.and11_i_1 = 0;
////-!            }
////-!            else{
////-!            sLV.p_p4->bool_vars.and14_i_0 = 1;
////-!             sLV.p_p4->bool_vars.and11_i_1 = 0;
////-!            }    
////-!                
//            if((sLV.p_p4->lVl&((1<<20)|(1<<21))) == ((1<<20)|(1<<21)))
//                 sLV.p_p4->bool_vars.and11_o_0 = 1;
//            else 
//                sLV.p_p4->bool_vars.and11_o_0 = 0;
//            if( ((sLV.p_p1->lVl&((1<<22)|(1<<21))) > 0) || sLV.p_p4->bool_vars.and11_o_0 )
//                p2.bool_vars.and22_i_3 = 1;
//            if( ((sLV.p_p1->lVl&((1<<23)|(1<<24))) > 0) || sLV.p_p4->bool_vars.and11_o_0)
//                p2.bool_vars.and24_i_3 = 1;
//            //lV = (sLV.p_current_settings_prt->control_dz);
//            rU =(MASKA_FOR_BIT(INDEX_CTR_DZ3)); rU &= lV;
//            if(rU != 0){
//                rU = 1;
//                p2.bool_vars.and22_i_0 = rU;
//                p2.bool_vars.and24_i_0 = rU;
//                p2.bool_vars.and26_i_0 = rU;
//            }   
//            //lV = (sLV.p_current_settings_prt->control_dz);
//            rU = (MASKA_FOR_BIT(INDEX_CTR_DZ3_DIR));
//            rU &= lV;
//            if(rU != 0)
//                p2.bool_vars.and22_i_1 = 1;
//            //lV = (sLV.p_current_settings_prt->control_dz)
//            rU =(MASKA_FOR_BIT(INDEX_CTR_DZ3_INV));rU &= lV;
//            if(rU != 0)
//                p2.bool_vars.and24_i_1 = 1;
//
//                
//            if(_CHECK_SET_BIT(p_active_functions, RANG_PO_AMTZ_DZ3) != 0){
//                lV = 1;
//                p2.bool_vars.nor19_i_3 = lV;
//                p2.bool_vars.nor20_i_3 = lV;
//                sLV.p_p1->bool_vars.nor18__i_1 = lV;  //p2.bool_vars.or18__i_1 = lV;
//            }   
//
//            if(_CHECK_SET_BIT(p_active_functions, RANG_PO_DIR_DZ3) == 0){
//                p2.bool_vars.not23_o_0 = 1;
//                p2.bool_vars.and26_i_1 = 1;
//            }
//            if(_CHECK_SET_BIT(p_active_functions, RANG_PO_INV_DZ3) == 0){
//                p2.bool_vars.not25_o_0 = 1;
//                p2.bool_vars.and26_i_2 = 1;
//            }   
////          sLV.p_p4->bool_vars.and14_i_0 = 0;  
////          if(_CHECK_SET_BIT(p_active_functions, RANG_SNKN_DZ) != 0)
////              sLV.p_p4->bool_vars.and14_i_0 = 1;
////            lV = _CHECK_SET_BIT(p_active_functions, RANG_SNKN_DZ);
////            if (lV){//-!
////                sLV.p_p4->lVl |= (1<<22)|(1<<21);//and11_i_1 and14_i_0
////            }
//            //Eval Stp    
//            rU = p2.bool_vars.not23_o_0;
//            long pick_up_Resistance_dstLp3 = 0;
//            if(rU == 0)
//                pick_up_Resistance_dstLp3 = (long)sLV.p_current_settings_prt->pickup_dz3_dir[number_group_stp] * KOEF_POVERNENNJA_GENERAL_DOWN  / 100;
//            else
//                pick_up_Resistance_dstLp3 = (long)sLV.p_current_settings_prt->pickup_dz3_dir[number_group_stp];
//
//            lV = m_s_phs_stp_state.lVl;
//            if(lV&(1<<0)){//One
//                if((sLV.p_p4->lVl&((1<<20)|(1<<21))) == ((1<<20)|(1<<21))){//Check Fault and11   sLV.p_p4->bool_vars.and11_o_0
//                    rU = Za_A;
//                    if(lV&(1<<5))
//                        rU = Za_B;
//                    else if(lV&(1<<6))
//                            rU = Za_C;
//                    
//                }
//                else{
//                    rU = Z_A;
//                    if(lV&(1<<5))
//                        rU = Z_B;
//                    else if(lV&(1<<6))
//                            rU = Z_C;       
//                }
//                //current_settings_prt.pickup_dz1
//            }else if(lV&(1<<1)){ //2
//    
//                if((sLV.p_p4->lVl&((1<<20)|(1<<21))) == ((1<<20)|(1<<21))){//Check Fault and11  sLV.p_p4->bool_vars.and11_o_0
//                    rU = Za_AB;//( (1<< IA_M0_P9) | (1<<IB_M0_P9) | (1<<IC_L0_P9 ))
//                    if( (lV&((1<<(IB_M0_P9+7)) | (1<<(IC_M0_P9+7)) | (1<<(IA_L0_P9+7)))) == ((1<<(IB_M0_P9+7)) | (1<<(IC_M0_P9+7)) | (1<<(IA_L0_P9+7))) )//if( lV == (lV&((1<<(IB_M0_P9+7)) | (1<<(IC_M0_P9+7)) | (1<<(IA_L0_P9+7)))) )
//                        rU = Za_BC;
//                    else if( (lV&((1<<(IA_M0_P9+7)) | (1<<(IC_M0_P9+7)) | (1<<(IB_L0_P9+7))))== ((1<<(IA_M0_P9+7)) | (1<<(IC_M0_P9+7)) | (1<<(IB_L0_P9+7))) )//if( lV == (lV&((1<<(IA_M0_P9+7)) | (1<<(IC_M0_P9+7)) | (1<<(IB_L0_P9+7)))) )
//                            rU = Za_CA; 
//                }
//                else{
//                    rU = Z_AB;
//                    if(  (lV&((1<<(IB_M0_P9+7)) | (1<<(IC_M0_P9+7)) | (1<<(IA_L0_P9+7))))== ((1<<(IB_M0_P9+7)) | (1<<(IC_M0_P9+7)) | (1<<(IA_L0_P9+7))) ) //if( lV == (lV&((1<<(IB_M0_P9+7)) | (1<<(IC_M0_P9+7)) | (1<<(IA_L0_P9+7)))))
//                        rU = Z_BC;
//                    else if( (lV&((1<<(IA_M0_P9+7)) | (1<<(IC_M0_P9+7)) | (1<<(IB_L0_P9+7))))== ((1<<(IA_M0_P9+7)) | (1<<(IC_M0_P9+7)) | (1<<(IB_L0_P9+7))) ) //if( lV == (lV&((1<<(IA_M0_P9+7)) | (1<<(IC_M0_P9+7)) | (1<<(IB_L0_P9+7)))) )
//                            rU = Z_CA;  
//                }
//            }
//            else{//M
//                if((sLV.p_p4->lVl&((1<<20)|(1<<21))) == ((1<<20)|(1<<21))){//Check Fault
//                    rU = Za_3;//lV&(1<<2) Select Avar
//                }
//                else{
//                    rU = Z_3;
//                }
//            }
//            lV = resistance[rU];    
//            if(  (lV > 0) && (lV < pick_up_Resistance_dstLp3)  )
//                p2.bool_vars.and22_i_2 = 1;
//            else
//                p2.bool_vars.and22_i_2 = 0;
//                
//            lV = p2.bool_vars.not25_o_0;
//            //long pick_up_Resistance_dstLp2 = 0;
//            if(lV == 0)
//                pick_up_Resistance_dstLp3 = (long)sLV.p_current_settings_prt->pickup_dz3_inv[number_group_stp] * KOEF_POVERNENNJA_GENERAL_DOWN  / 100;
//            else
//                pick_up_Resistance_dstLp3 = (long)sLV.p_current_settings_prt->pickup_dz3_inv[number_group_stp];   
//            lV = resistance[rU];
//            if(  (lV > 0) && (lV < pick_up_Resistance_dstLp3)  )
//                p2.bool_vars.and24_i_2 = 1;
//            else
//                p2.bool_vars.and24_i_2 = 0;
//            
//            //and14
//            //sLV.p_p4->lVl |= (1<<22);//and14_i_0 :1;//22
//            //sLV.p_p4->lVl |= (1<<23);//and14_i_1 :1;//23  
//            rU = (sLV.p_p4->lVl)&((1<<22)|(1<<23)); //and14
//            if(rU == ((1<<22)|(1<<23))){
//                //sLV.p_p1->bool_vars.and4_o_0 = 1;
//                //and16
//                sLV.p_p1->bool_vars.and16_i_0 = 1;
//                //and17
//                sLV.p_p1->bool_vars.and17_i_0 = 1;
//                //or18
//                sLV.p_p1->bool_vars.nor18__i_0 = 1;
//            }
//            sLV.p_p1->bool_vars.and16_i_1 = p2.bool_vars.not23_o_0;  
//            sLV.p_p1->bool_vars.and17_i_1 = p2.bool_vars.not25_o_0;
//            lV = sLV.p_p1->lVl;
//            lV &= ((1<<28)|(1<<29));
//            if(lV == ((1<<28)|(1<<29)))//and16 
//                p2.bool_vars.nor19_i_2 = 1;
//
//            lV = sLV.p_p1->lVl;
//            lV &= ((1<<20)|(1<<19));
//            if(lV == ((1<<20)|(1<<19)))//and17 
//                p2.bool_vars.nor20_i_2 = 1;
//                
//            if( (sLV.p_p1->lVl&((1<<25)|(1<<26))) != 0 ){//or18
//                p2.bool_vars.nor21_i_2 = 0;
//            }
//            else{
//                p2.bool_vars.nor21_i_2 = 1;
//            }
//            sLV.p2 = p2;
//            //PO Calc
//            lV = p2.bool_vars.nor20_i_3;//STP_I_A_MCP_DST_LP_STAGE2_BIT
//            unsigned long pick_up_I_Amcp_dstLp3 = 0;
//            if(lV){
//                pick_up_I_Amcp_dstLp3 = sLV.p_current_settings_prt->pickup_dz3_amtz[number_group_stp] * KOEF_POVERNENNJA_MTZ_I_UP  / 100;
//                }
//            else{   
//                pick_up_I_Amcp_dstLp3 = sLV.p_current_settings_prt->pickup_dz3_amtz[number_group_stp];
//            }
//            if( (measurement[IM_IA] > pick_up_I_Amcp_dstLp3)
//                || (measurement[IM_IB] > pick_up_I_Amcp_dstLp3)
//                || (measurement[IM_IC] > pick_up_I_Amcp_dstLp3)
//            )
//                p2.bool_vars.and26_i_4 = 1;//rU = 1;
//            else
//                p2.bool_vars.and26_i_4 = 0;//rU = 0;
//            //nor19 
//            if( (p2.lVl&((1<<15)|(1<<16)|(1<<17)|(1<<18)) ) != 0 ){//
//                p2.bool_vars.and22_i_4 = 0;
//            }
//            else{
//                p2.bool_vars.and22_i_4 = 1;
//            }
//            //nor20 
//            if( (p2.lVl&((1<<19)|(1<<20)|(1<<21)|(1<<22)) ) != 0 ){//
//                p2.bool_vars.and24_i_4 = 0;
//            }
//            else{
//                p2.bool_vars.and24_i_4 = 1;
//            }
//            //nor21 
//            if( (p2.lVl&((1<<23)|(1<<24)|(1<<25)) ) != 0 ){//
//                p2.bool_vars.and26_i_3 = 0;
//            }
//            else{
//                p2.bool_vars.and26_i_3 = 1;
//            }
//            //lV = sLV.p_p1->lVl;
//            lV = p2.lVl&((1<<9)|(1<<10)|(1<<11)|(1<<12)|(1<<13)|(1<<14));
//            if(lV == ((1<<9)|(1<<10)|(1<<11)|(1<<12)|(1<<13)|(1<<14))){//and26 9 10 11 12 13 14
//                _SET_BIT(p_active_functions, RANG_PO_AMTZ_DZ3);
//                u32_bit_holder |= 1<<STP_I_AMCP_DST_LP_STAGE_BIT;
//            }   
//            else
//                _CLEAR_BIT(p_active_functions, RANG_PO_AMTZ_DZ3);
//            
//            rU = p2.lVl&((1<<4)|(1<<5)|(1<<6)|(1<<7)|(1<<8));
//            if(rU == ((1<<4)|(1<<5)|(1<<6)|(1<<7)|(1<<8))){//and24 4 5 6 7 8
//                _SET_BIT(p_active_functions, RANG_PO_INV_DZ3);
//                u32_bit_holder |= 1<<STP_INV_DST_LP_STAGE_BIT;
//            }   
//            else
//                _CLEAR_BIT(p_active_functions, RANG_PO_INV_DZ3);
//            
//            rU = p2.lVl&((1<<0)|(1<<30)|(1<<1)|(1<<2)|(1<<3));
//            if(rU == ((1<<0)|(1<<30)|(1<<1)|(1<<2)|(1<<3))){//and22 0 1 2 3
//                _SET_BIT(p_active_functions, RANG_PO_DIR_DZ3);
//                u32_bit_holder |= 1<<STP_DIR_DST_LP_STAGE_BIT;
//            }
//            else
//                _CLEAR_BIT(p_active_functions, RANG_PO_DIR_DZ3);
//
//    
//                ;
//        }else if(sLV.ch_stage_selector == DZ4_STAGE_BIT){
//                    ;
//                                         //Eval FCHE
//            rU = m_s_phs_stp_state.lVl;
//            if(rU&(1<<0)){//One
//                //Select Max
//                lV = 0;//Za_A;
//                if(rU&(1<<5))
//                    lV = 1;//Za_B;
//                else if(rU&(1<<6))
//                    lV = 2;//Za_C;
//                //Check Sector
//                lV = sector_directional_dz[DZ4_STAGE_BIT][lV];
//            }else if(rU&(1<<1)){ //2
//                     register long rCtr = 0;lV = 0;     
//                    do{
//                        if(rCtr == 0){
//                            if(rU&(1<<(IA_M0_P9+7)))
//                                lV = sector_directional_dz[DZ4_STAGE_BIT][0];
//                        }
//                        if(rCtr == 1){
//                            if(rU&(1<<(IB_M0_P9+7)))
//                                lV = sector_directional_dz[DZ4_STAGE_BIT][1];
//                        }
//                        if(rCtr == 2){
//                            if(rU&(1<<(IC_M0_P9+7)))
//                                lV = sector_directional_dz[DZ4_STAGE_BIT][2];
//                        }
//                    }while( (lV <= 0)&& rCtr++ < 2  );
//
//            }else{//M
//                //Check Sector  
//                register long  rCtr = 0;lV = 0;     
//                do{
//                    if(rCtr == 0){
//                        if(rU&(1<<(IA_M0_P9+7)))
//                            lV = sector_directional_dz[DZ4_STAGE_BIT][0];
//                    }
//                    if(rCtr == 1){
//                        if(rU&(1<<(IB_M0_P9+7)))
//                            lV = sector_directional_dz[DZ4_STAGE_BIT][1];
//                    }
//                    if(rCtr == 2){
//                        if(rU&(1<<(IC_M0_P9+7)))
//                            lV = sector_directional_dz[DZ4_STAGE_BIT][2];
//                    }
//                }while( (lV <= 0)&& rCtr++ < 2  );
//            }
//            _CLEAR_BIT(p_active_functions, RANG_SECTOR_DIR_DZ4);
//            _CLEAR_BIT(p_active_functions, RANG_SECTOR_INV_DZ4);
//            if(lV == 1){
//                _SET_BIT(p_active_functions, RANG_SECTOR_DIR_DZ4);
//                sLV.p_p1->bool_vars.or12__i_1 = 1;
//            }else if(lV == 2){
//                _SET_BIT(p_active_functions, RANG_SECTOR_INV_DZ4);
//                 sLV.p_p1->bool_vars.or13__i_0 = 1;
//            }
//            
//                        #ifdef DEBUG_CONFIGURATION
//sLV.p_p1->bool_vars.or13__i_0 = 1; sLV.p_p1->bool_vars.or12__i_1 = 1;
//#else
//  
//#endif          
//            //else if(lV == (-1)){
//            //  ;
//            //}
////            if( (sLV.p_p1->lVl&((1<<22)|(1<<21))) > 0 )
////                p2.bool_vars.and22_i_3 = 1;
////            if( (sLV.p_p1->lVl&((1<<23)|(1<<24))) > 0 )
////                p2.bool_vars.and24_i_3 = 1;
//              
//            if(_CHECK_SET_BIT(p_active_functions, RANG_BLOCK_DZ4) != 0){
//                lV = 1;
//                p2.bool_vars.nor19_i_0 = lV;
//                p2.bool_vars.nor20_i_0 = lV;
//                p2.bool_vars.nor21_i_0 = lV;
//            }
//            
//            if(_CHECK_SET_BIT(p_active_functions, RANG_PO_I_BLK_DZ) != 0){
//                lV = 1;
//                p2.bool_vars.nor19_i_1 = lV;
//                p2.bool_vars.nor20_i_1 = lV;
//                p2.bool_vars.nor21_i_1 = lV;
//            }   
//            lV = (sLV.p_current_settings_prt->control_dz);
//            rU = (MASKA_FOR_BIT(INDEX_CTR_DZ4_AMTZ)); rU &= lV;
//            //not15
//            if(rU == 0){
//                sLV.p_p1->bool_vars.not15_o_0 = 1;
//                sLV.p_p4->bool_vars.and14_i_1 = 0;//lVl |= (1<<23);//and14_i_1 :1;//23
//                sLV.p_p4->bool_vars.and11_i_0 = 1;//and11
//                p2.bool_vars.and26_i_5 = 0;//and26
//            }else{
//                sLV.p_p1->bool_vars.not15_o_0 = 0;//?
//                sLV.p_p4->bool_vars.and14_i_1 = 1;
//                sLV.p_p4->bool_vars.and11_i_0 = 0;
//                p2.bool_vars.and26_i_5 = 1;
//            }
////-!            if(_CHECK_SET_BIT(p_active_functions, RANG_SNKN_DZ) != 0){
////-!              sLV.p_p4->bool_vars.and14_i_0 = 1;
////-!              sLV.p_p4->bool_vars.and11_i_1 = 0;
////-!            }
////-!            else{
////-!            sLV.p_p4->bool_vars.and14_i_0 = 1;
////-!             sLV.p_p4->bool_vars.and11_i_1 = 0;
////-!            }    
////-!                
//            if((sLV.p_p4->lVl&((1<<20)|(1<<21))) == ((1<<20)|(1<<21)))
//                 sLV.p_p4->bool_vars.and11_o_0 = 1;
//            else 
//                sLV.p_p4->bool_vars.and11_o_0 = 0;
//            if( ((sLV.p_p1->lVl&((1<<22)|(1<<21))) > 0) || sLV.p_p4->bool_vars.and11_o_0 )
//                p2.bool_vars.and22_i_3 = 1;
//            if( ((sLV.p_p1->lVl&((1<<23)|(1<<24))) > 0) || sLV.p_p4->bool_vars.and11_o_0)
//                p2.bool_vars.and24_i_3 = 1;
//            //lV = (sLV.p_current_settings_prt->control_dz);
//            rU =(MASKA_FOR_BIT(INDEX_CTR_DZ4)); rU &= lV;
//            if(rU != 0){
//                rU = 1;
//                p2.bool_vars.and22_i_0 = rU;
//                p2.bool_vars.and24_i_0 = rU;
//                p2.bool_vars.and26_i_0 = rU;
//            }   
//            //lV = (sLV.p_current_settings_prt->control_dz);
//            rU = (MASKA_FOR_BIT(INDEX_CTR_DZ4_DIR));
//            rU &= lV;
//            if(rU != 0)
//                p2.bool_vars.and22_i_1 = 1;
//            //lV = (sLV.p_current_settings_prt->control_dz)
//            rU =(MASKA_FOR_BIT(INDEX_CTR_DZ4_INV));rU &= lV;
//            if(rU != 0)
//                p2.bool_vars.and24_i_1 = 1;
//
//                
//            if(_CHECK_SET_BIT(p_active_functions, RANG_PO_AMTZ_DZ4) != 0){
//                lV = 1;
//                p2.bool_vars.nor19_i_3 = lV;
//                p2.bool_vars.nor20_i_3 = lV;
//                sLV.p_p1->bool_vars.nor18__i_1 = lV;  //p2.bool_vars.or18__i_1 = lV;
//            }   
//
//            if(_CHECK_SET_BIT(p_active_functions, RANG_PO_DIR_DZ4) == 0){
//                p2.bool_vars.not23_o_0 = 1;
//                p2.bool_vars.and26_i_1 = 1;
//            }
//            if(_CHECK_SET_BIT(p_active_functions, RANG_PO_INV_DZ4) == 0){
//                p2.bool_vars.not25_o_0 = 1;
//                p2.bool_vars.and26_i_2 = 1;
//            }   
////          sLV.p_p4->bool_vars.and14_i_0 = 0;  
////          if(_CHECK_SET_BIT(p_active_functions, RANG_SNKN_DZ) != 0)
////              sLV.p_p4->bool_vars.and14_i_0 = 1;
////            lV = _CHECK_SET_BIT(p_active_functions, RANG_SNKN_DZ);
////            if (lV){//-!
////                sLV.p_p4->lVl |= (1<<22)|(1<<21);//and11_i_1 and14_i_0
////            }
//            //Eval Stp    
//            rU = p2.bool_vars.not23_o_0;
//            long pick_up_Resistance_dstLp4 = 0;
//            if(rU == 0)
//                pick_up_Resistance_dstLp4 = (long)sLV.p_current_settings_prt->pickup_dz4_dir[number_group_stp] * KOEF_POVERNENNJA_GENERAL_DOWN  / 100;
//            else
//                pick_up_Resistance_dstLp4 = (long)sLV.p_current_settings_prt->pickup_dz4_dir[number_group_stp];
//
//            lV = m_s_phs_stp_state.lVl;
//            if(lV&(1<<0)){//One
//                if((sLV.p_p4->lVl&((1<<20)|(1<<21))) == ((1<<20)|(1<<21))){//Check Fault and11
//                    rU = Za_A;
//                    if(lV&(1<<5))
//                        rU = Za_B;
//                    else if(lV&(1<<6))
//                            rU = Za_C;
//                    
//                }
//                else{
//                    rU = Z_A;
//                    if(lV&(1<<5))
//                        rU = Z_B;
//                    else if(lV&(1<<6))
//                            rU = Z_C;       
//                }
//                //current_settings_prt.pickup_dz1
//            }else if(lV&(1<<1)){ //2
//    
//                if((sLV.p_p4->lVl&((1<<20)|(1<<21))) == ((1<<20)|(1<<21))){//Check Fault and11
//                    rU = Za_AB;//( (1<< IA_M0_P9) | (1<<IB_M0_P9) | (1<<IC_L0_P9 ))
//                    if( (lV&((1<<(IB_M0_P9+7)) | (1<<(IC_M0_P9+7)) | (1<<(IA_L0_P9+7))))== ((1<<(IB_M0_P9+7)) | (1<<(IC_M0_P9+7)) | (1<<(IA_L0_P9+7))))
//                        rU = Za_BC;
//                    else if( (lV&((1<<(IA_M0_P9+7)) | (1<<(IC_M0_P9+7)) | (1<<(IB_L0_P9+7))))== ((1<<(IA_M0_P9+7)) | (1<<(IC_M0_P9+7)) | (1<<(IB_L0_P9+7))))
//                            rU = Za_CA; 
//                }
//                else{
//                    rU = Z_AB;
//                    if( (lV&((1<<(IB_M0_P9+7)) | (1<<(IC_M0_P9+7)) | (1<<(IA_L0_P9+7))))== ((1<<(IB_M0_P9+7)) | (1<<(IC_M0_P9+7)) | (1<<(IA_L0_P9+7))) )
//                        rU = Z_BC;
//                    else if( (lV&((1<<(IA_M0_P9+7)) | (1<<(IC_M0_P9+7)) | (1<<(IB_L0_P9+7))))== ((1<<(IA_M0_P9+7)) | (1<<(IC_M0_P9+7)) | (1<<(IB_L0_P9+7))))
//                            rU = Z_CA;  
//                }
//            }
//            else{//M
//                if((sLV.p_p4->lVl&((1<<20)|(1<<21))) == ((1<<20)|(1<<21))){//Check Fault
//                    rU = Za_3;//lV&(1<<2) Select Avar
//                }
//                else{
//                    rU = Z_3;
//                }
//            }
//            lV = resistance[rU];    
//            if(  (lV > 0) && (lV < pick_up_Resistance_dstLp4)  )
//                p2.bool_vars.and22_i_2 = 1;
//            else
//                p2.bool_vars.and22_i_2 = 0;
//            #ifdef DEBUG_CONFIGURATION
//p2.bool_vars.and22_i_2 = 1;  //? p2.bool_vars.and24_i_2 = 1; 
//#else
//  
//#endif                
//            lV = p2.bool_vars.not25_o_0;
//            //long pick_up_Resistance_dstLp2 = 0;
//            if(lV == 0)
//                pick_up_Resistance_dstLp4 = (long)sLV.p_current_settings_prt->pickup_dz4_inv[number_group_stp] * KOEF_POVERNENNJA_GENERAL_DOWN  / 100;
//            else
//                pick_up_Resistance_dstLp4 = (long)sLV.p_current_settings_prt->pickup_dz4_inv[number_group_stp];   
//            lV = resistance[rU];
//            if(  (lV > 0) && (lV < pick_up_Resistance_dstLp4)  )
//                p2.bool_vars.and24_i_2 = 1;
//            else
//                p2.bool_vars.and24_i_2 = 0;
//            
//            //and14
//            //sLV.p_p4->lVl |= (1<<22);//and14_i_0 :1;//22
//            //sLV.p_p4->lVl |= (1<<23);//and14_i_1 :1;//23  
//            rU = (sLV.p_p4->lVl)&((1<<22)|(1<<23)); //and14
//            if(rU == ((1<<22)|(1<<23))){
//                //sLV.p_p1->bool_vars.and4_o_0 = 1;
//                //and16
//                sLV.p_p1->bool_vars.and16_i_0 = 1;
//                //and17
//                sLV.p_p1->bool_vars.and17_i_0 = 1;
//                //or18
//                sLV.p_p1->bool_vars.nor18__i_0 = 1;
//            }
//            sLV.p_p1->bool_vars.and16_i_1 = p2.bool_vars.not23_o_0;  
//            sLV.p_p1->bool_vars.and17_i_1 = p2.bool_vars.not25_o_0;
//            lV = sLV.p_p1->lVl;
//            lV &= ((1<<28)|(1<<29));
//            if(lV == ((1<<28)|(1<<29)))//and16 
//                p2.bool_vars.nor19_i_2 = 1;
//
//            lV = sLV.p_p1->lVl;
//            lV &= ((1<<20)|(1<<19));
//            if(lV == ((1<<20)|(1<<19)))//and17 
//                p2.bool_vars.nor20_i_2 = 1;
//                
//            if( (sLV.p_p1->lVl&((1<<25)|(1<<26))) != 0 ){//or18
//                p2.bool_vars.nor21_i_2 = 0;
//            }
//            else{
//                p2.bool_vars.nor21_i_2 = 1;
//            }
//            sLV.p2 = p2;
//            //PO Calc
//            lV = p2.bool_vars.nor20_i_3;//STP_I_A_MCP_DST_LP_STAGE2_BIT
//            unsigned long pick_up_I_Amcp_dstLp4 = 0;
//            if(lV){
//                pick_up_I_Amcp_dstLp4 = sLV.p_current_settings_prt->pickup_dz4_amtz[number_group_stp] * KOEF_POVERNENNJA_MTZ_I_UP  / 100;
//                }
//            else{   
//                pick_up_I_Amcp_dstLp4 = sLV.p_current_settings_prt->pickup_dz4_amtz[number_group_stp];
//            }
//            if( (measurement[IM_IA] > pick_up_I_Amcp_dstLp4)
//                || (measurement[IM_IB] > pick_up_I_Amcp_dstLp4)
//                || (measurement[IM_IC] > pick_up_I_Amcp_dstLp4)
//            )
//                p2.bool_vars.and26_i_4 = 1;//rU = 1;
//            else
//                p2.bool_vars.and26_i_4 = 0;//rU = 0;
//            //nor19 
//            if( (p2.lVl&((1<<15)|(1<<16)|(1<<17)|(1<<18)) ) != 0 ){//
//                p2.bool_vars.and22_i_4 = 0;
//            }
//            else{
//                p2.bool_vars.and22_i_4 = 1;
//            }
//            //nor20 
//            if( (p2.lVl&((1<<19)|(1<<20)|(1<<21)|(1<<22)) ) != 0 ){//
//                p2.bool_vars.and24_i_4 = 0;
//            }
//            else{
//                p2.bool_vars.and24_i_4 = 1;
//            }
//            //nor21 
//            if( (p2.lVl&((1<<23)|(1<<24)|(1<<25)) ) != 0 ){//
//                p2.bool_vars.and26_i_3 = 0;
//            }
//            else{
//                p2.bool_vars.and26_i_3 = 1;
//            }
//            //lV = sLV.p_p1->lVl;
//            lV = p2.lVl&((1<<9)|(1<<10)|(1<<11)|(1<<12)|(1<<13)|(1<<14));
//            if(lV == ((1<<9)|(1<<10)|(1<<11)|(1<<12)|(1<<13)|(1<<14))){//and26 9 10 11 12 13 14
//                _SET_BIT(p_active_functions, RANG_PO_AMTZ_DZ4);
//                u32_bit_holder |= 1<<STP_I_AMCP_DST_LP_STAGE_BIT;
//            }   
//            else
//                _CLEAR_BIT(p_active_functions, RANG_PO_AMTZ_DZ4);
//            
//            rU = p2.lVl&((1<<4)|(1<<5)|(1<<6)|(1<<7)|(1<<8));
//            if(rU == ((1<<4)|(1<<5)|(1<<6)|(1<<7)|(1<<8))){//and24 4 5 6 7 8
//                _SET_BIT(p_active_functions, RANG_PO_INV_DZ4);
//                u32_bit_holder |= 1<<STP_INV_DST_LP_STAGE_BIT;
//            }   
//            else
//                _CLEAR_BIT(p_active_functions, RANG_PO_INV_DZ4);
//            
//            rU = p2.lVl&((1<<0)|(1<<30)|(1<<1)|(1<<2)|(1<<3));
//            if(rU == ((1<<0)|(1<<30)|(1<<1)|(1<<2)|(1<<3))){//and22 0 1 2 3
//                _SET_BIT(p_active_functions, RANG_PO_DIR_DZ4);
//                u32_bit_holder |= 1<<STP_DIR_DST_LP_STAGE_BIT;
//            }
//            else
//                _CLEAR_BIT(p_active_functions, RANG_PO_DIR_DZ4);
//
//    
//        }
//        ;
//    sLV.p_p2->lVl = p2.lVl;
//    }while(sLV.ch_stage_selector > TOTAL_DZ_STAGES_BITS);
//    
//    do{
//        //register void* pv;
//        long lV,rU;
//        register Dz2_stp_p3_state p3;
//        
//        if(bw_dstLp_dt.hdrBW.ch_p1234_modified & (1<<P3_MODIFIED_BIT))
//            p3.lVl = sLV.p_p3->lVl;//Mask?
//        else
//            p3.lVl = sLV.p_p3->lVl;
//            
//            if( u32_bit_holder& (1<<STP_I_AMCP_DST_LP_STAGE_BIT)){
//                //Eval Pr Cmd
//                 p3.bool_vars.and31_i_2 = 1;
//                 p3.bool_vars.and32_i_0 = 1;
//                lV = sLV.p_p1->bool_vars.not10_o_0;
//                rU = p3.bool_vars.or27_i_0;
//                //Select Tmr
//                    //if(lV != 0){//No Acc
//                //p3.bool_vars.or27_i_0 = rU;//Must be already setup
//                p3.bool_vars.or29_i_0 = lV;
//                lV = p3.bool_vars.and32_o_0;//Loop link
//                rU = p3.bool_vars.and31_o_0;//Loop link
//                p3.bool_vars.or29_i_1 = lV;
//                p3.bool_vars.or27_i_1 = rU;
//                p3.bool_vars.not30_o_0 = !lV;
//                p3.bool_vars.not28_o_0 = !rU;
//                p3.bool_vars.and31_i_1 = !lV;
//                p3.bool_vars.and32_i_1 = !rU;
//                if( (p3.lVl&((1<<0)|(1<<1))) != 0 )//or27 customer
//                    p3.bool_vars.and31_i_0 = 1; 
//                else //-if(p3.lVl&((1<<0)|(1<<1))) == 0)
//                    p3.bool_vars.and31_i_0 = 0; 
//                
//                 if( (p3.lVl&((1<<3)|(1<<4))) != 0 )//or29 customer
//                    p3.bool_vars.and32_i_2 = 1;
//                else //-if( (p3.lVl&((1<<2)|(1<<3))) == 0 )
//                    p3.bool_vars.and32_i_2 = 0;
//                    
//                rU = p3.lVl&((1<<8)|(1<<6)|(1<<7));
//                if(rU == ((1<<8)|(1<<6)|(1<<7))){   
//                    p3.bool_vars.and31_o_0 = 1;
//                    u32_bit_holder |= 1<<T_ACC_AMCP_IN_BIT;
//                }else{
//                    p3.bool_vars.and31_o_0 = 0;
//                
//                }                       
//                rU = p3.lVl&((1<<11)|(1<<9)|(1<<10));
//                if(rU == ((1<<11)|(1<<9)|(1<<10))){  
//                    p3.bool_vars.and32_o_0 = 1;
//                    u32_bit_holder |= 1<<T_AMCP_IN_BIT;
//                    }
//                else{
//                    p3.bool_vars.and32_o_0 = 0;
//                }
//
//
//               
//            }else{
//                lV = 0;
//                //Reset and31 and32
//                 p3.bool_vars.and31_i_2 = lV;
//                 p3.bool_vars.and32_i_0 = lV;
//                //set or
//                p3.bool_vars.or27_i_1 = lV;
//                p3.bool_vars.or29_i_1 = lV;
//                //set not
//                p3.bool_vars.not28_o_0 = 1;
//                p3.bool_vars.not30_o_0 = 1;
//                
//                //reset timers
//                p3.bool_vars.and31_o_0 = lV;
//                p3.bool_vars.and32_o_0 = lV;
//
//                
//        }
//        ;sLV.p_p3->lVl &= ~((1<<12) | (1<<13));//and31_o_0 and32_o_0        
//        sLV.p_p3->lVl = p3.lVl;
//        if (sLV.ch_stage_selector == DZ2_STAGE_BIT){
//                        //AMtz block calc Fierst
//            if( u32_bit_holder& (1<<STP_I_AMCP_DST_LP_STAGE_BIT)){
//                //Eval Pr Cmd
//                 _TIMER_T_0(INDEX_TIMER_DZ2_AMTZ,  sLV.p_current_settings_prt->timeout_dz2_amtz[number_group_stp],
//                u32_bit_holder, T_AMCP_IN_BIT, u32_bit_holder, T_AMCP_OUT_BIT);
//                _TIMER_T_0(INDEX_TIMER_DZ2_AMTZ_PR,  sLV.p_current_settings_prt->timeout_dz2_amtz_pr[number_group_stp],
//                u32_bit_holder, T_ACC_AMCP_IN_BIT, u32_bit_holder, T_ACC_AMCP_OUT_BIT);
//
//            }else{
//
//                 _TIMER_T_0(INDEX_TIMER_DZ2_AMTZ,  sLV.p_current_settings_prt->timeout_dz2_amtz[number_group_stp],
//                u32_bit_holder, T_AMCP_IN_BIT, u32_bit_holder, T_AMCP_OUT_BIT);
//                 _TIMER_T_0(INDEX_TIMER_DZ2_AMTZ_PR,  sLV.p_current_settings_prt->timeout_dz2_amtz_pr[number_group_stp],
//                u32_bit_holder, T_ACC_AMCP_IN_BIT, u32_bit_holder, T_ACC_AMCP_OUT_BIT);
//  
//            }
//            //Сраб.
//            if ( u32_bit_holder&( (1<<T_ACC_AMCP_OUT_BIT)|(1<<T_AMCP_OUT_BIT) ) )
//            _SET_BIT(p_active_functions, RANG_AMTZ_DZ2);
//            else
//            _CLEAR_BIT(p_active_functions, RANG_AMTZ_DZ2);
//            
//        }else if(sLV.ch_stage_selector == DZ3_STAGE_BIT){
//                                   //AMtz block calc Fierst
//            if( u32_bit_holder& (1<<STP_I_AMCP_DST_LP_STAGE_BIT)){
//                //Eval Pr Cmd
//
//                         _TIMER_T_0(INDEX_TIMER_DZ3_AMTZ,  sLV.p_current_settings_prt->timeout_dz3_amtz[number_group_stp],
//                        u32_bit_holder, T_AMCP_IN_BIT, u32_bit_holder, T_AMCP_OUT_BIT);
//                        _TIMER_T_0(INDEX_TIMER_DZ3_AMTZ_PR,  sLV.p_current_settings_prt->timeout_dz3_amtz_pr[number_group_stp],
//                        u32_bit_holder, T_ACC_AMCP_IN_BIT, u32_bit_holder, T_ACC_AMCP_OUT_BIT);
//
//            }
//            else{
//
//                 _TIMER_T_0(INDEX_TIMER_DZ3_AMTZ,  sLV.p_current_settings_prt->timeout_dz3_amtz[number_group_stp],
//                u32_bit_holder, T_AMCP_IN_BIT, u32_bit_holder, T_AMCP_OUT_BIT);
//                 _TIMER_T_0(INDEX_TIMER_DZ3_AMTZ_PR,  sLV.p_current_settings_prt->timeout_dz3_amtz_pr[number_group_stp],
//                u32_bit_holder, T_ACC_AMCP_IN_BIT, u32_bit_holder, T_ACC_AMCP_OUT_BIT);
//  
//                
//            }
//            //Сраб.
//            if ( u32_bit_holder&( (1<<T_ACC_AMCP_OUT_BIT)|(1<<T_AMCP_OUT_BIT) ) )
//            _SET_BIT(p_active_functions, RANG_AMTZ_DZ3);
//            else
//            _CLEAR_BIT(p_active_functions, RANG_AMTZ_DZ3);
//     
//            ;
//        }else if(sLV.ch_stage_selector == DZ4_STAGE_BIT){
//                _TIMER_T_0(INDEX_TIMER_DZ4_AMTZ,  sLV.p_current_settings_prt->timeout_dz4_amtz[number_group_stp],
//                u32_bit_holder, T_AMCP_IN_BIT, u32_bit_holder, T_AMCP_OUT_BIT);
//                 _TIMER_T_0(INDEX_TIMER_DZ4_AMTZ_PR,  sLV.p_current_settings_prt->timeout_dz4_amtz_pr[number_group_stp],
//                u32_bit_holder, T_ACC_AMCP_IN_BIT, u32_bit_holder, T_ACC_AMCP_OUT_BIT);
//                //Сраб.
//            if ( u32_bit_holder&( (1<<T_ACC_AMCP_OUT_BIT)|(1<<T_AMCP_OUT_BIT) ) )
//            _SET_BIT(p_active_functions, RANG_AMTZ_DZ4);
//            else
//            _CLEAR_BIT(p_active_functions, RANG_AMTZ_DZ4);
//
//        }
////        ;sLV.p_p3->lVl &= ~((1<<12) | (1<<13));//and31_o_0 and32_o_0      
////    sLV.p_p3->lVl = p3.lVl;
//    }while(sLV.ch_stage_selector > TOTAL_DZ_STAGES_BITS);
//    
//    do{
//        //register void* pv;
//        register Dz2_stp_p4_state p4;
//        register Dz2_stp_p3_state p3; 
//        long lV,rU;
////        if(bw_dstLp_dt.hdrBW.ch_p1234_modified & (1<<P4_MODIFIED_BIT))
////            p4.lVl = sLV.p_p4->lVl;//Mask?
////        else
////            p4.lVl = 0;
//        p4.lVl = sLV.p_p4->lVl;    
//        p3.lVl = sLV.p_p3->lVl;    
//        if(u32_bit_holder&(1<<STP_DIR_DST_LP_STAGE_BIT)){
//            p4.bool_vars.and43_i_0 = 1;
//            p4.bool_vars.and42_i_2 = 1;
//            lV = sLV.p_p1->bool_vars.not9_o_0;//No Accl
//            p3.bool_vars.or36_i_0 = lV;
//            
//            //rU = ~lV;
//            //rU &= 1;//Accl Dz;
//            //p3.bool_vars.or34_i_0 = rU;   //rU1 |= lV<< 18;rU1 = ,rU1
//            lV = p4.bool_vars.and42_o_0;//Loop link
//            rU = p4.bool_vars.and43_o_0;//Loop link
//            p3.bool_vars.or34_i_1 = lV;
//            p3.bool_vars.or36_i_1 = rU;
//            p3.bool_vars.not35_o_0 = !lV;
//            p3.bool_vars.not37_o_0 = !rU;
//            p4.bool_vars.and43_i_1 = !lV;
//            p4.bool_vars.and42_i_1 = !rU;
//            if( (p3.lVl&((1<<17)|(1<<16))) != 0 )//or34 customer
//                p4.bool_vars.and42_i_0 = 1; 
//            else 
//                p4.bool_vars.and42_i_0 = 0; 
//            
//            if( (p3.lVl&((1<<20)|(1<<19))) != 0 )//or36 customer
//                p4.bool_vars.and43_i_2 = 1;
//            else 
//                p4.bool_vars.and43_i_2 = 0;
//                
//            rU = p4.lVl&((1<<0)|(1<<1)|(1<<2));
//            if(rU == ((1<<0)|(1<<1)|(1<<2))){   
//                p4.bool_vars.and42_o_0 = 1;//p3.bool_vars.and31_o_0 = 1;
//                u32_bit_holder |= 1<<T_ACC_DIR_IN_BIT;
//            }else{
//                //p3.bool_vars.and31_o_0 = 0;
//            
//            }   
//            rU = p4.lVl&((1<<3)|(1<<4)|(1<<5));
//            if(rU == ((1<<3)|(1<<4)|(1<<5))){  
//                p4.bool_vars.and43_o_0 = 1;//p3.bool_vars.and32_o_0 = 1;
//                u32_bit_holder |= 1<<T_DIR_IN_BIT;
//                }
//            else{
//                //p3.bool_vars.and32_o_0 = 0;
//            }
//     
//        
//        }else{
//            lV = 0; 
//            //Reset and42 and43
//            p4.bool_vars.and43_i_0 = lV;
//            p4.bool_vars.and42_i_2 = lV;
//            //set or
//            p3.bool_vars.or36_i_1 = lV;
//            p3.bool_vars.or34_i_1 = lV;
//            //set not
//            p3.bool_vars.not35_o_0 = 1;
//            p3.bool_vars.not37_o_0 = 1;
//            //reset timers
//            p4.bool_vars.and43_o_0 = lV;
//            p4.bool_vars.and42_o_0 = lV;
//            //
//        }       
////Inv
//        if(u32_bit_holder&(1<<STP_INV_DST_LP_STAGE_BIT)){
//            p4.bool_vars.and45_i_0 = 1;
//            p4.bool_vars.and44_i_2 = 1;
//            lV = sLV.p_p1->bool_vars.not9_o_0;//No Accl
//            p3.bool_vars.or40_i_0 = lV;
//            lV = p4.bool_vars.and44_o_0;//Loop link
//            rU = p4.bool_vars.and45_o_0;//Loop link
//            p3.bool_vars.or38_i_1 = lV;
//            p3.bool_vars.or40_i_1 = rU;
//            p3.bool_vars.not39_o_0 = !lV;
//            p3.bool_vars.not41_o_0 = !rU;
//            p4.bool_vars.and45_i_1 = !lV;
//            p4.bool_vars.and44_i_1 = !rU;
//            if( (p3.lVl&((1<<23)|(1<<22))) != 0 )//or38 customer
//                p4.bool_vars.and44_i_0 = 1; 
//            else 
//                p4.bool_vars.and44_i_0 = 0; 
//            
//            if( (p3.lVl&((1<<26)|(1<<25))) != 0 )//or40 customer
//                p4.bool_vars.and45_i_2 = 1;
//            else 
//                p4.bool_vars.and45_i_2 = 0;
//                
//            rU = p4.lVl&((1<<6)|(1<<7)|(1<<8));
//            if(rU == ((1<<6)|(1<<7)|(1<<8))){   
//                p4.bool_vars.and44_o_0 = 1;
//                u32_bit_holder |= 1<<T_ACC_INV_IN_BIT;
//            }else{
//                p4.bool_vars.and44_o_0 = 0;
//            
//            }   
//            rU = p4.lVl&((1<<9)|(1<<10)|(1<<11));
//            if(rU == ((1<<9)|(1<<10)|(1<<11))){  
//                p4.bool_vars.and45_o_0 = 1;
//                u32_bit_holder |= 1<<T_INV_IN_BIT;
//                }
//            else{
//                p4.bool_vars.and45_o_0 = 0;
//            }       
//        }
//        else{
//            lV = 0;
//            //Reset and44 and45
//            p4.bool_vars.and45_i_0 = lV;
//            p4.bool_vars.and44_i_2 = lV;
//            //set or
//            p3.bool_vars.or38_i_1 = lV;
//            p3.bool_vars.or40_i_1 = lV;
//            //set not
//            p3.bool_vars.not39_o_0 = 1;
//            p3.bool_vars.not41_o_0 = 1;
//            //reset timers
//            p4.bool_vars.and44_o_0 = lV;
//            p4.bool_vars.and45_o_0 = lV;
//            
//        }
//        //sLV.p_p3->lVl &= ~((1<<12) | (1<<13));//and31_o_0 and32_o_0
//        sLV.p_p4->lVl &= ~((1<<12)|(1<<13)|(1<<14)|(1<<15));//and42_o_0 and43_o_0 and44_o_0 and45_o_0 
//        sLV.p_p3->lVl |= p3.lVl;
//        sLV.p_p4->lVl |= p4.lVl;   
//        if (sLV.ch_stage_selector == DZ2_STAGE_BIT){
//            ;
//            //Dir
////            if(u32_bit_holder&(1<<STP_DIR_DST_LP_STAGE_BIT)){
////                //Eval Pr Cmd
////                _TIMER_T_0(INDEX_TIMER_DZ2_DIR_PR,  sLV.p_current_settings_prt->timeout_dz2_dir_pr[number_group_stp],
////                u32_bit_holder, T_ACC_DIR_IN_BIT, u32_bit_holder, T_ACC_DIR_OUT_BIT);
////                        _TIMER_T_0(INDEX_TIMER_DZ2_DIR,  sLV.p_current_settings_prt->timeout_dz2_dir[number_group_stp],
////                u32_bit_holder, T_DIR_IN_BIT, u32_bit_holder, T_DIR_OUT_BIT);
////                    
////            
////            }//else{
//
//                 _TIMER_T_0(INDEX_TIMER_DZ2_DIR_PR,  sLV.p_current_settings_prt->timeout_dz2_dir_pr[number_group_stp],
//                u32_bit_holder, T_ACC_DIR_IN_BIT, u32_bit_holder, T_ACC_DIR_OUT_BIT);
//                _TIMER_T_0(INDEX_TIMER_DZ2_DIR,  sLV.p_current_settings_prt->timeout_dz2_dir[number_group_stp],
//                u32_bit_holder, T_DIR_IN_BIT, u32_bit_holder, T_DIR_OUT_BIT);
//                
//            //}
//            //Inv
////            if(u32_bit_holder&(1<<STP_INV_DST_LP_STAGE_BIT)){
////                 _TIMER_T_0(INDEX_TIMER_DZ2_INV_PR,  sLV.p_current_settings_prt->timeout_dz2_inv_pr[number_group_stp],
////                u32_bit_holder, T_ACC_INV_IN_BIT, u32_bit_holder, T_ACC_INV_OUT_BIT);
////                _TIMER_T_0(INDEX_TIMER_DZ2_INV,  sLV.p_current_settings_prt->timeout_dz2_inv[number_group_stp],
////                u32_bit_holder, T_INV_IN_BIT, u32_bit_holder, T_INV_OUT_BIT);
////                    
////            }
//            //else{
//
//                _TIMER_T_0(INDEX_TIMER_DZ2_INV_PR,  sLV.p_current_settings_prt->timeout_dz2_inv_pr[number_group_stp],
//                u32_bit_holder, T_ACC_INV_IN_BIT, u32_bit_holder, T_ACC_INV_OUT_BIT);
//                _TIMER_T_0(INDEX_TIMER_DZ2_INV,  sLV.p_current_settings_prt->timeout_dz2_inv[number_group_stp],
//                u32_bit_holder, T_INV_IN_BIT, u32_bit_holder, T_INV_OUT_BIT);
//                    
////              }
//            if(u32_bit_holder&( (1<<T_ACC_DIR_OUT_BIT)|(1<<T_DIR_OUT_BIT)|(1<<T_ACC_INV_OUT_BIT)|(1<<T_INV_OUT_BIT) ))
//                _SET_BIT(p_active_functions,RANG_DZ2 );
//            else
//                _CLEAR_BIT(p_active_functions,RANG_DZ2 );
//        }
//        else if(sLV.ch_stage_selector == DZ3_STAGE_BIT){
//            //Dir
////            if(u32_bit_holder&(1<<STP_DIR_DST_LP_STAGE_BIT)){
////                //Eval Pr Cmd
////                _TIMER_T_0(INDEX_TIMER_DZ3_DIR_PR,  sLV.p_current_settings_prt->timeout_dz3_dir_pr[number_group_stp],
////                u32_bit_holder, T_ACC_DIR_IN_BIT, u32_bit_holder, T_ACC_DIR_OUT_BIT);
////                        _TIMER_T_0(INDEX_TIMER_DZ3_DIR,  sLV.p_current_settings_prt->timeout_dz3_dir[number_group_stp],
////                u32_bit_holder, T_DIR_IN_BIT, u32_bit_holder, T_DIR_OUT_BIT);
////                    
////                
////            }else{
//
//                 _TIMER_T_0(INDEX_TIMER_DZ3_DIR_PR,  sLV.p_current_settings_prt->timeout_dz3_dir_pr[number_group_stp],
//                u32_bit_holder, T_ACC_DIR_IN_BIT, u32_bit_holder, T_ACC_DIR_OUT_BIT);
//                _TIMER_T_0(INDEX_TIMER_DZ3_DIR,  sLV.p_current_settings_prt->timeout_dz3_dir[number_group_stp],
//                u32_bit_holder, T_DIR_IN_BIT, u32_bit_holder, T_DIR_OUT_BIT);
//                
////            }
//            //Inv
////            if(u32_bit_holder&(1<<STP_INV_DST_LP_STAGE_BIT)){
////                 _TIMER_T_0(INDEX_TIMER_DZ3_INV_PR,  sLV.p_current_settings_prt->timeout_dz3_inv_pr[number_group_stp],
////                u32_bit_holder, T_ACC_INV_IN_BIT, u32_bit_holder, T_ACC_INV_OUT_BIT);
////                _TIMER_T_0(INDEX_TIMER_DZ3_INV,  sLV.p_current_settings_prt->timeout_dz3_inv[number_group_stp],
////                u32_bit_holder, T_INV_IN_BIT, u32_bit_holder, T_INV_OUT_BIT);
////                    
////            }
////            else{
//
//                _TIMER_T_0(INDEX_TIMER_DZ3_INV_PR,  sLV.p_current_settings_prt->timeout_dz3_inv_pr[number_group_stp],
//                u32_bit_holder, T_ACC_INV_IN_BIT, u32_bit_holder, T_ACC_INV_OUT_BIT);
//                _TIMER_T_0(INDEX_TIMER_DZ3_INV,  sLV.p_current_settings_prt->timeout_dz3_inv[number_group_stp],
//                u32_bit_holder, T_INV_IN_BIT, u32_bit_holder, T_INV_OUT_BIT);
//                    
////            }   
//            if(u32_bit_holder&( (1<<T_ACC_DIR_OUT_BIT)|(1<<T_DIR_OUT_BIT)|(1<<T_ACC_INV_OUT_BIT)|(1<<T_INV_OUT_BIT) ))
//                _SET_BIT(p_active_functions, RANG_DZ3);
//            else
//                _CLEAR_BIT(p_active_functions,RANG_DZ3 );
//        }
//        else if(sLV.ch_stage_selector == DZ4_STAGE_BIT){
//                    ;
//                //Dir
////            if(u32_bit_holder&(1<<STP_DIR_DST_LP_STAGE_BIT)){
////                //Eval Pr Cmd
////                _TIMER_T_0(INDEX_TIMER_DZ4_DIR_PR,  sLV.p_current_settings_prt->timeout_dz4_dir_pr[number_group_stp],
////                u32_bit_holder, T_ACC_DIR_IN_BIT, u32_bit_holder, T_ACC_DIR_OUT_BIT);
////                        _TIMER_T_0(INDEX_TIMER_DZ4_DIR,  sLV.p_current_settings_prt->timeout_dz4_dir[number_group_stp],
////                u32_bit_holder, T_DIR_IN_BIT, u32_bit_holder, T_DIR_OUT_BIT);
////                    
////                
////            }else{
//
//                 _TIMER_T_0(INDEX_TIMER_DZ4_DIR_PR,  sLV.p_current_settings_prt->timeout_dz4_dir_pr[number_group_stp],
//                u32_bit_holder, T_ACC_DIR_IN_BIT, u32_bit_holder, T_ACC_DIR_OUT_BIT);
//                _TIMER_T_0(INDEX_TIMER_DZ4_DIR,  sLV.p_current_settings_prt->timeout_dz4_dir[number_group_stp],
//                u32_bit_holder, T_DIR_IN_BIT, u32_bit_holder, T_DIR_OUT_BIT);
//                
////            }
//            //Inv
////            if(u32_bit_holder&(1<<STP_INV_DST_LP_STAGE_BIT)){
////                 _TIMER_T_0(INDEX_TIMER_DZ4_INV_PR,  sLV.p_current_settings_prt->timeout_dz4_inv_pr[number_group_stp],
////                u32_bit_holder, T_ACC_INV_IN_BIT, u32_bit_holder, T_ACC_INV_OUT_BIT);
////                _TIMER_T_0(INDEX_TIMER_DZ4_INV,  sLV.p_current_settings_prt->timeout_dz4_inv[number_group_stp],
////                u32_bit_holder, T_INV_IN_BIT, u32_bit_holder, T_INV_OUT_BIT);
////                    
////            }
////            else{
//
//                _TIMER_T_0(INDEX_TIMER_DZ4_INV_PR,  sLV.p_current_settings_prt->timeout_dz4_inv_pr[number_group_stp],
//                u32_bit_holder, T_ACC_INV_IN_BIT, u32_bit_holder, T_ACC_INV_OUT_BIT);
//                _TIMER_T_0(INDEX_TIMER_DZ4_INV,  sLV.p_current_settings_prt->timeout_dz4_inv[number_group_stp],
//                u32_bit_holder, T_INV_IN_BIT, u32_bit_holder, T_INV_OUT_BIT);
//                    
////            }
//            if(u32_bit_holder&( (1<<T_ACC_DIR_OUT_BIT)|(1<<T_DIR_OUT_BIT)|(1<<T_ACC_INV_OUT_BIT)|(1<<T_INV_OUT_BIT) ))
//                _SET_BIT(p_active_functions, RANG_DZ4);
//            else
//                _CLEAR_BIT(p_active_functions, RANG_DZ4);
//        }
//        ;
//
////    sLV.p_p3->lVl |= p3.lVl;
////    sLV.p_p4->lVl |= p4.lVl;    
//    }while(sLV.ch_stage_selector > TOTAL_DZ_STAGES_BITS);
//    
// bw_dstLp_dt.hdrBW.ch_p1234_modified = 0;//(1<<P2_MODIFIED_BIT)
}
//
//--------------------------------------------------------------------------------------------------------

void dz3_handler(unsigned int *p_active_functions, unsigned int number_group_stp);
//````````````````````````````````````````````````````````````````````````````````````````````````````````
//=====================================================================================================
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//                  
//....................................................................................................
//=====================================================================================================
void dz3_handler(unsigned int *p_active_functions, unsigned int number_group_stp){
// ----------------  inner_outer_short_circuit It`s my name -------------------------

//First Check Menu & Dv ON or OFF

//Calc  for 4 stages
//  UNUSED(p_active_functions);
//  UNUSED(number_group_stp);
// register long i;
 bw_dstLp_dt.hdrBW.chIdxstage = DZ3_STAGE_BIT;
 dz2_handler(p_active_functions,number_group_stp);
  bw_dstLp_dt.hdrBW.chIdxstage = DZ2_STAGE_BIT;
}
//
//--------------------------------------------------------------------------------------------------------
//````````````````````````````````````````````````````````````````````````````````````````````````````````
void dz4_handler(unsigned int *p_active_functions, unsigned int number_group_stp);
//````````````````````````````````````````````````````````````````````````````````````````````````````````
//=====================================================================================================
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//                  
//....................................................................................................
//=====================================================================================================
void dz4_handler(unsigned int *p_active_functions, unsigned int number_group_stp){
// ----------------  inner_outer_short_circuit It`s my name -------------------------

//First Check Menu & Dv ON or OFF

//Calc  for 4 stages
//  UNUSED(p_active_functions);
//  UNUSED(number_group_stp);
 
 bw_dstLp_dt.hdrBW.chIdxstage = DZ4_STAGE_BIT;
 dz2_handler(p_active_functions,number_group_stp); 
 bw_dstLp_dt.hdrBW.chIdxstage = DZ2_STAGE_BIT;
}
//
//--------------------------------------------------------------------------------------------------------
//````````````````````````````````````````````````````````````````````````````````````````````````````````

//const unsigned long MIN_LIMIT_I1_I2_P = MIN_LIMIT_FOR_I1_AND_I2;
/*
Реалізував без відладки фазочутливий елемент для ДЗ
Викладено на Github i Google Disk

Опис:
int32_t sector_directional_dz[4 - 1][3];
1 індекс - ступені 2, 3 і 4
2 індекс - фаза А, В і С

Значення:
-1 струм або напруга за межами учтливості фазочутливого елементу
0 - сіра область
1 - зона "ПРЯМОГО" напрямку
2 - зона "ЗВОРОТНОГО" напрямку




 from google Sheets
enum _resistance_index          value
{           
R_A = 0,            0
X_A,            1
Z_A,            2
R_B,            3
X_B,            4
Z_B,            5
R_С,            6
X_С,            7
Z_C,            8
            
R_AB,           9
X_AB,           10
Z_AB,           11
R_BC,           12
X_BC,           13
Z_BC,           14
R_CA,           15
X_CA,           16
Z_CA,           17
            
MAX_NUMBER_INDEXES_RESISTANCE,          18
            
Z_3 = MAX_NUMBER_INDEXES_RESISTANCE,            18
            
Za_A,           19
Za_B,           20
Za_C,           21
            
Za_AB,          22
Za_BC,          23
Za_CA,          24
            
Za_3,           25
            
MAX_NUMBER_INDEXES_RESISTANCE_FULL          26
};          



*/

/*

typedef union mcp_stp_state_Unn{ 
   struct {
      unsigned int or2__i_0 :1; //0
      unsigned int or2__i_1 :1; //1
      unsigned int and3_i_0 :1; //2
      unsigned int and3_i_1 :1; //2
      unsigned int and4_i_0 :1; //3
      unsigned int and4_i_1 :1; //3
      unsigned int and5_i_0 :1; //4
      unsigned int and5_i_1 :1; //4
      unsigned int and5_i_0 :1; //5
      unsigned int and5_i_1 :1; //5
      unsigned int and4_o_0 :1; //6
      unsigned int and5_o_0 :1; //6
      unsigned int and6_o_0 :1; //7
      unsigned int or7__i_0 :1; //7
      unsigned int or7__i_1 :1; //8
      unsigned int or8__i_0 :1; //8
      unsigned int or8__i_1 :1; //9
      unsigned int not9_o_0 :1; //9
      unsigned int not10_o_0 :1;//10
      unsigned int and11_i_0 :1;//11
      unsigned int and11_i_1 :1;//12
      unsigned int or12__i_1 :1;//13
      unsigned int or12__i_0 :1;//14
      unsigned int or13__i_1 :1;//15
      unsigned int or13__i_0 :1;//16
      unsigned int and14_i_0 :1;//17
      unsigned int and14_i_1 :1;//18
      unsigned int not15_o_0 :1;//19
      unsigned int and16_i_0 :1;//20
      unsigned int and16_i_1 :1;//21
      unsigned int and17_i_0 :1;//22
      unsigned int and17_i_1 :1;//23
      unsigned int or18__i_1 :1;//24
      unsigned int or18__i_0 :1;//25
      unsigned int b26 :1;//26
      unsigned int b27 :1;//27
      unsigned int b28 :1;//28
      unsigned int b29 :1;//29
      unsigned int b30 :1;//30
      unsigned int b31 :1;//31    
    } bool_vars;
    long lVl;
} Dz2_stp_p1_state; //ex- extended
typedef union mcp_stp_state_Unn{ 
   struct {
      unsigned int and22_i_0 :1; //0
      unsigned int and22_i_1 :1; //1
      unsigned int and22_i_2 :1; //2
      unsigned int and22_i_3 :1; //2
      unsigned int and22_i_4 :1; //3
      unsigned int and24_i_0 :1; //4
      unsigned int and24_i_1 :1; //5
      unsigned int and24_i_2 :1; //6
      unsigned int and24_i_3 :1; //7
      unsigned int and24_i_4 :1; //8
      unsigned int and26_i_0 :1; //9
      unsigned int and26_i_1 :1;//10
      unsigned int and26_i_2 :1;//11
      unsigned int and26_i_3 :1;//12
      unsigned int and26_i_4 :1;//13
      unsigned int and26_i_5 :1;//14
      unsigned int nor19_i_0 :1;//15
      unsigned int nor19_i_1 :1;//16
      unsigned int nor19_i_2 :1;//17
      unsigned int nor19_i_3 :1;//18
      unsigned int nor20_i_0 :1;//19
      unsigned int nor20_i_1 :1;//20
      unsigned int nor20_i_2 :1;//21
      unsigned int nor20_i_3 :1;//22
      unsigned int nor21_i_0 :1;//23
      unsigned int nor21_i_1 :1;//24
      unsigned int nor21_i_2 :1;//25
      unsigned int not23_o_0 :1;//26
      unsigned int not25_o_0 :1;//27
      unsigned int b28 :1;//28
      unsigned int b29 :1;//29
      unsigned int b30 :1;//30
      unsigned int b31 :1;//31    
    } bool_vars;
    long lVl;
} Dz2_stp_p2_state; //ex- extended
typedef union mcp_stp_state_Unn{ 
   struct {
      unsigned int or27_i_0 :1; //0
      unsigned int or27_i_1 :1; //1
      unsigned int not28_o_0:1; //2
      unsigned int or29_i_0 :1; //2
      unsigned int or29_i_1 :1; //3
      unsigned int not30_o_0:1; //4
      unsigned int and31_i_0:1; //5
      unsigned int and31_i_1:1; //6
      unsigned int and31_i_3:1; //7
      unsigned int and32_i_0:1; //8
      unsigned int and32_i_1:1; //9
      unsigned int and32_i_3:1;//10
      unsigned int and31_o_0 :1;//11
      unsigned int and32_o_0 :1;//12
      unsigned int or33_i_0 :1;//13
      unsigned int or33_i_1 :1;//14
      unsigned int or34_i_0  :1;//15
      unsigned int or34_i_1  :1;//16
      unsigned int not35_o_0 :1;//17
      unsigned int or36_i_0  :1;//18
      unsigned int or36_i_1  :1;//19
      unsigned int not37_o_0 :1;//20
      unsigned int or38_i_0  :1;//21
      unsigned int or38_i_1  :1;//22
      unsigned int not39_o_0 :1;//23
      unsigned int or40_i_0  :1;//24
      unsigned int or40_i_1  :1;//25
      unsigned int not41_o_0 :1;//26
      unsigned int b27 :1;//27
      unsigned int b28 :1;//28
      unsigned int b29 :1;//29
      unsigned int b30 :1;//30
      unsigned int b31 :1;//31    
    } bool_vars;
    long lVl;
} Dz2_stp_p3_state; //ex- extended
typedef union mcp_stp_state_Unn{ 
   struct {
      unsigned int and42_i_0 :1; //0
      unsigned int and42_i_1 :1; //1
      unsigned int and42_i_3 :1; //2
      unsigned int and43_i_0 :1; //3
      unsigned int and43_i_1 :1; //4
      unsigned int and43_i_3 :1; //5
      unsigned int and44_i_0 :1; //6
      unsigned int and44_i_1 :1; //7
      unsigned int and44_i_3 :1; //8
      unsigned int and45_i_0 :1; //9
      unsigned int and45_i_1 :1;//10
      unsigned int and45_i_3 :1;//11
      unsigned int and42_o_0 :1;//12
      unsigned int and43_o_0 :1;//13
      unsigned int and44_o_0 :1;//14
      unsigned int and45_o_0 :1;//15
      unsigned int or46_i_0  :1;//16
      unsigned int or46_i_1  :1;//17
      unsigned int or46_i_2  :1;//18
      unsigned int or46_i_3  :1;//19
      unsigned int b20 :1;//20
      unsigned int b21 :1;//21
      unsigned int b22 :1;//22
      unsigned int b23 :1;//23
      unsigned int b24 :1;//24
      unsigned int b25 :1;//25
      unsigned int b26 :1;//26
      unsigned int b27 :1;//27
      unsigned int b28 :1;//28
      unsigned int b29 :1;//29
      unsigned int b30 :1;//30
      unsigned int b31 :1;//31    
    } bool_vars;
    long lVl;
} Dz2_stp_p4_state; //ex- extended

//First Check Menu & Dv ON or OFF
register union { 
   struct {
      unsigned int SW:1;//0
      unsigned int SW:1;//1
      unsigned int SW:1;//2
      unsigned int SW:1;//3
      unsigned int SW:1;//4
      unsigned int SW:1;//5
      unsigned int SW:1;//6
      unsigned int SW:1;//7
      unsigned int SW:1;//8
      unsigned int SW:1;//9
      unsigned int SW:1;//10
      unsigned int SW:1;//11
      unsigned int SW:1;//12
      unsigned int SW:1;//13
      unsigned int SW:1;//14
      unsigned int SW:1;//15
      unsigned int SW:1;//17
      unsigned int SW:1;//18
      unsigned int SW:1;//19
      unsigned int SW:1;//21
      unsigned int SW:1;//22
      unsigned int SW:1;//23
      unsigned int SW:1;//24
      unsigned int SW:1;//25
      unsigned int SW:1;//26
      unsigned int SW1:1;//27
      unsigned int SW:1;//28
      unsigned int SW:1;//29
      //unsigned int not10_1 :1;//30
      //unsigned int not10_1 :1;//31
      
   } bool_vars;
  long lVl;
}wrp_dz2;

register union { 
   struct {
      unsigned int S4_1:1;//0
      unsigned int S4_2:1;//1
      unsigned int S4_3:1;//2
      unsigned int S5_1:1;//3
      unsigned int S5_2:1;//4
      unsigned int S5_3:1;//5
      unsigned int S4__:1;//6
      unsigned int S5__:1;//7
      unsigned int S_1:1;//8
      unsigned int S_2:1;//9
      unsigned int S2_1:1;//10
      unsigned int S7_1:1;//11
      unsigned int S_O1:1;//11-  O1 - means out 1
   } bool_vars;
  long lVl;
}wrp_sncn;
wrp_sncn.lVl = 0;

_TIMER_T_0_LOCK(  //    reset outs only if on input set 0   
_TIMER_T_0(// reset outs  if global_timers[_index_timer] >= _max_count 
clr global_timers[_index_timer] if if _input == 0
_TIMER_0_T(// reset outs as _TIMER_T_0 but 
clr global_timers[_index_timer] if _input >0 <==add T
_TIMER_IMPULSE(
have _input->_c, and _INPUT->_C. _input it`s a shadow for front selection
          if (_c ^ _C)                                                  
          {                                                             
            if (_C) _input |= (unsigned int)(1 << _input_bit);          
            else _input &= (unsigned int)(~(1 << _input_bit));  
        }
Detect change 0-1. Then
if(global_timers[_index_timer] >= 0 
&& global_timers[_index_timer] < _max_count)                          
            _OUTPUT |= (unsigned int)(1 << _OUTPUT_BIT);               
          else                                                         
            _OUTPUT &= (unsigned int)(~(1 << _OUTPUT_BIT));
//this forms pulse 0 to _max_count          
*/
