#ifndef LU_MTZO_SCHM_DSC_h
#define LU_MTZO_SCHM_DSC_h

enum MTZO_ID_SELECTORS{
ID_MTZO1,
ID_MTZO2,
ID_MTZO3,
ID_MTZO4,
};
enum MTZO_ID_TMR_BIT{
    
    IDX_TMR_MTZO_IN,              IDX_TMR_MTZO_OUT, 
    IDX_TMR_MTZO_IN_DEPENDENT,    IDX_TMR_MTZO_OUT_DEPENDENT,
    IDX_TMR_MTZO_IN_PR,           IDX_TMR_MTZO_OUT_PR,
    IDX_TMR_MTZO_IN_N_VPERED,     IDX_TMR_MTZO_OUT_N_VPERED,
    IDX_TMR_MTZO_IN_N_VPERED_PR,  IDX_TMR_MTZO_OUT_N_VPERED_PR,
    IDX_TMR_MTZO_IN_N_NAZAD,      IDX_TMR_MTZO_OUT_N_NAZAD,
    IDX_TMR_MTZO_IN_N_NAZAD_PR,   IDX_TMR_MTZO_OUT_N_NAZAD_PR,
    IDX_TMR_MTZO_IN_PO_NAPRUZI,   IDX_TMR_MTZO_OUT_PO_NAPRUZI,
    IDX_TMR_MTZO_IN_PO_NAPRUZI_PR,IDX_TMR_MTZO_OUT_PO_NAPRUZI_PR,
    IDX_TMR_MTZO_IN_VVID_PR,      IDX_TMR_MTZO_OUT_VVID_PR,


};  

enum MTZO_SCHEMATIC_LU_ORDER_NUMS{

MTZO_And01__2_1,
MTZO_Or_02__3_1,
MTZO_Not03__1_1,  
MTZO_And04__2_1,
MTZO_Not05__1_1,
MTZO_And06__2_1,
MTZO_Or_07__2_1, 
MTZO_Not08__1_1,
MTZO_And09__2_1,
MTZO_Not10__1_1,
MTZO_And11__2_1,
MTZO_Or_12__4_1,
MTZO_And13__3_1,
MTZO_And14__6_1, 
MTZO_And15__6_1, 
MTZO_And16__4_1, 
MTZO_Or_17__4_1,
IN_MTZO_NORMAL_SELECTOR,
IN_MTZO_DIR_SELECTOR, 
IN_MTZO_STP_U_SELECTOR, 

TOTAL_PROCESS_MTZO_LU
};
enum RELE_SCH_ORDER_NUM_OFFSET_OUTS{

                    //MTZO_And01__2_1,
MTZO_AND_01_I0_ONB,
MTZO_AND_01_I1_ONB,

                    //MTZO_Or_02__3_1,
MTZO_OR_02_I0_ONB,
MTZO_OR_02_I1_ONB,
MTZO_OR_02_I2_ONB,
                    //MTZO_Not03__1_1,  
MTZO_NOT03_I0_ONB,
                    //MTZO_And04__2_1,
MTZO_AND04_I0_ONB,
MTZO_AND04_I1_ONB,
                    //MTZO_Not05__1_1,
MTZO_NOT05_I0_ONB,
                    //MTZO_And06__2_1,
MTZO_AND06_I0_ONB,
MTZO_AND06_I1_ONB,
                    //MTZO_Or_07__2_1, 
MTZO_OR_07_I0_ONB, 
MTZO_OR_07_I1_ONB, 
                     //MTZO_Not08__1_1,
MTZO_NOT08_I0_ONB,
                     //MTZO_And09__2_1,
MTZO_AND09_I0_ONB,
MTZO_AND09_I1_ONB,
                     //MTZO_Not10__1_1,
MTZO_NOT10_I0_ONB,
                     //MTZO_And11__2_1,
MTZO_AND11_I0_ONB,
MTZO_AND11_I1_ONB,
                     //MTZO_Or_12__4_1,
MTZO_OR_12_I0_ONB,
MTZO_OR_12_I1_ONB,
MTZO_OR_12_I2_ONB,
MTZO_OR_12_I3_ONB,
                     //MTZO_And13__3_1,
MTZO_AND13_I0_ONB,
MTZO_AND13_I1_ONB,
MTZO_AND13_I2_ONB,
                     //MTZO_And14__6_1, 
MTZO_AND14_I0_ONB, 
MTZO_AND14_I1_ONB, 
MTZO_AND14_I2_ONB, 
MTZO_AND14_I3_ONB, 
MTZO_AND14_I4_ONB, 
MTZO_AND14_I5_ONB, 
                     //MTZO_And15__6_1, 
MTZO_AND15_I0_ONB, 
MTZO_AND15_I1_ONB, 
MTZO_AND15_I2_ONB, 
MTZO_AND15_I3_ONB, 
MTZO_AND15_I4_ONB, 
MTZO_AND15_I5_ONB, 
                     //MTZO_And16__4_1, 
MTZO_AND16_I0_ONB, 
MTZO_AND16_I1_ONB, 
MTZO_AND16_I2_ONB, 
MTZO_AND16_I3_ONB, 
                     //MTZO_Or_17__4_1,
MTZO_OR_17_I0_ONB,
MTZO_OR_17_I1_ONB,
MTZO_OR_17_I2_ONB,
MTZO_OR_17_I3_ONB,

IN_MTZO_NORMAL_SELECTOR_ONB,
IN_MTZO_DIR_SELECTOR_ONB   , 
IN_MTZO_STP_U_SELECTOR_ONB , 
IN_MTZO_ON_MENU_ONB        ,
IN_MTZO_RNG_BIG_BLOCK_ONB  ,
IN_MTZO_DIR_ON_MENU_ONB    ,
IN_MTZO_SECTOR_DIR_ONB     ,
IN_MTZO_SECTOR_INV_ONB     ,
IN_MTZO_STP_DIR_ONB        ,
IN_MTZO_INV_ON_MENU_ONB    ,
IN_MTZO_STP_INV_ONB        ,
IN_MTZO_RNG_BIG_PO_BLK_U_OSN_LESS_0_05UN_MCZO_ONB,
IN_MTZO_STP_PO_BLK_U_OSN_LESS_U_P_ONB,
IN_MTZO_STP_U_ONB,
//IN_MTZO_

TOTAL_MTZO_LU_CMD  
};
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

U8_state_wrp stt_AND2_1;
/* 
U8_state_wrp stt_MTZO_And01__2_1,
        stt_MTZO_Or_02__3_1,
        stt_MTZO_Not03__1_1,  
        stt_MTZO_And04__2_1,
        stt_MTZO_Not05__1_1,
        stt_MTZO_And06__2_1,
        stt_MTZO_Or_07__2_1, 
        stt_MTZO_Not08__1_1,
        stt_MTZO_And09__2_1,
        stt_MTZO_Not10__1_1,
        stt_MTZO_And11__2_1,
        stt_MTZO_Or_12__4_1,
        stt_MTZO_And13__3_1,
        stt_MTZO_And14__6_1, 
        stt_MTZO_And15__6_1, 
        stt_MTZO_And16__4_1, 
        stt_MTZO_Or_17__4_1;

   struct {
      unsigned int in_mtzo_normal_selector :1;//0
      unsigned int in_mtzo_dir_selector    :1;//1
      unsigned int in_mtzo_stp_u_selector  :1;//2
      unsigned int in_mtzo_on_menu         :1;//3
      unsigned int in_mtzo_rng_big_block   :1;//4
      unsigned int in_mtzo_dir_on_menu     :1;//5
      unsigned int in_mtzo_sector_dir      :1;//6
      unsigned int in_mtzo_sector_inv      :1;//7
      unsigned int in_mtzo_stp_dir         :1;//8
      unsigned int in_mtzo_inv_on_menu     :1;//9
      unsigned int in_mtzo_stp_inv         :1;//10
      unsigned int in_mtzo_rng_big_po_blk_u :1;//11
      unsigned int in_mtzo_stp_po_blk_u_osn_less_u_porog :1;//12
      unsigned int in_mtzo_stp_u, :1;//13
      unsigned int res14  :1;//14
      unsigned int nor6_4 :1;//15
      unsigned int reserv :1;//16
      unsigned int or4_1  :1;//17
      unsigned int or4_2  :1;//18
      unsigned int and5_1 :1;//19
      unsigned int reser1 :1;//20
      unsigned int and5_2 :1;//21
      unsigned int and4_1 :1;//22
      unsigned int and4_2 :1;//23
      unsigned int and2_1 :1;//24
      unsigned int and2_2 :1;//25
      unsigned int not3_1 :1;//26
      unsigned int not10_1:1;//27
      unsigned int nor5_1 :1;//28
      unsigned int nor5_2 :1;//29
      unsigned int reser2 :1;//30
      unsigned int reser3 :1;//31
      
   } bool_vars;
  long lVl;
}wrp_mtzo; 
*/
typedef union U8_mtzo_po_Unn{ 
   struct {
      unsigned int po_mtz_simple     : 1; //1
      unsigned int po_mtz_sector_dir : 1; //2
      unsigned int po_mtz_sector_inv : 1; //3
      unsigned int po_mtz_dir        : 1; //4
      unsigned int po_mtz_inv        : 1; //5
      unsigned int po_mtz_u_ust_pn   : 1; //6
      unsigned int po_mtz_pn         : 1; //7
      unsigned int po_res  : 1; //8
    } bool_val;
    unsigned char U8V;
} U8_mtzo_po_wrp; 
extern U8_state_wrp mtzo1_stp,mtzo2_stp,mtzo3_stp,mtzo4_stp;
extern char glb_ch_id_mtzo;

//==============================================================
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//!      sector_directional_mtz[4][2]
//!      
//!      Перший індекс [4] - ступінь
//!      Другий індекс [2] - 0 - основна лінія; 1 - резарвна лінія   
//enum __mtz_abc_const {
//  PHASE_MN_INDEX = 0,
//  PHASE_BP_INDEX,
//};
//
//enum __mtz_abc_direction_const {
//  MTZ_NEVYZN = 0,
//  MTZ_VPERED,
//  MTZ_NAZAD
//};
//..............................................................
//==============================================================
typedef union U32_mtzo2_po_Unn{ 
   struct {
      unsigned int m_mtzo2                        :1; //0
      unsigned int m_mtzo2_dir                    :1; //1
      unsigned int m_mtzo2_inv                    :1; //2
      unsigned int m_select_mtzo2_dir             :1; //3
      unsigned int b4                             :1; //4
      unsigned int b5                             :1; //5
      unsigned int b6                             :1; //6
      unsigned int b7                             :1; //7
      unsigned int m_select_mtzo2_dep             :1; //8 or15_o_0
      unsigned int po_dir_mtzo2                   :1; //9
      unsigned int po_inv_mtzo2                   :1;//10
      unsigned int po_mtzo2_simple                :1;//11
      unsigned int po_mtzo2_u                     :1;//12
      unsigned int not04_o_0                      :1;//13
      unsigned int orN07_o_0                      :1;//14
      unsigned int and06_o_0                      :1;//15
      unsigned int or18_o_0                       :1;//16
      unsigned int not17_o_0                      :1;//17
      unsigned int out_t_vvoda_usk                :1;//18
      unsigned int b19                            :1;//19
      unsigned int b20                            :1;//20
      unsigned int and20_o_0                      :1;//21
      unsigned int b22                            :1;//22
      unsigned int b23                            :1;//23
      unsigned int b24                            :1;//24
      unsigned int b25                            :1;//25
      unsigned int not05_o_0                      :1;//26
      unsigned int po_mtzo2_i                     :1;//27
      unsigned int not50_o_0                      :1;//28
      unsigned int m_mtzo2_usk                    :1;//29
      unsigned int m_uskor_mtzo2                  :1;//30



      unsigned int b31                            :1;//31    
  
    } bool_val;
    unsigned long U32V;
} U32_mtzo2_wrp; 

typedef union U32_mtzo2_po_Unn2{ 
   struct {
      unsigned int or01_o_0                     :1; //0
      unsigned int not02_o_0                    :1; //1
      unsigned int and03_o_0                    :1; //2
      unsigned int not48_o_0                    :1; //3
      unsigned int not47_o_0                    :1; //4
      unsigned int not45_o_0                    :1; //5
      unsigned int not54_o_0                    :1; //6
      unsigned int and20_copy                   :1; //7
      unsigned int not43_o_0                    :1; //8
      unsigned int not56_o_0                    :1; //9
      unsigned int not40_o_0                    :1;//10
      unsigned int not58_o_0                    :1;//11
      unsigned int n1ot50_o_0                    :1;//12
      unsigned int b13                          :1;//13
      unsigned int b14                          :1;//14
      unsigned int b15                          :1;//15
      unsigned int b16                          :1;//16
      unsigned int b17                          :1;//17
      unsigned int b18                          :1;//18
      unsigned int b19                          :1;//19
      unsigned int b20                          :1;//20
      unsigned int b21                          :1;//21
      unsigned int b22                          :1;//22
      unsigned int b23                          :1;//23
      unsigned int b24                          :1;//24
      unsigned int b25                          :1;//25
      unsigned int b26                          :1;//26
      unsigned int m_select_mtzo2_dep_a         :1;//27
      unsigned int m_select_mtzo2_dep_b         :1;//28
      unsigned int m_select_mtzo2_dep_c         :1;//29
      unsigned int m_select_mtzo2_dep_80        :1;//30
      unsigned int m_select_mtzo2_dep_81        :1;//31    
  
    } bool_val;
    unsigned long U32V;
} U32_mtzo2_2wrp; 




#endif

