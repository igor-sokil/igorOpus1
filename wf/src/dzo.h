#ifndef LU_DZO_SCHM_DSC_h
#define LU_DZO_SCHM_DSC_h

enum DZO_ID_SELECTORS{

ID_DZO2,
ID_DZO3,

};


enum DZO1_ID_TMR_BIT{
  IDX_TIMER_IN_DZO1             ,IDX_TIMER_OUT_DZO1             ,
  IDX_TIMER_IN_DZO1_AMTZ        ,IDX_TIMER_OUT_DZO1_AMTZ        ,

  IDX_TIMER_IN_NKN_DZO          ,IDX_TIMER_OUT_NKN_DZO          ,
};
enum DZO23_ID_TMR_BIT{

  IDX_TIMER_IN_DZO23_DIR         ,IDX_TIMER_OUT_DZO23_DIR         ,
  IDX_TIMER_IN_DZO23_DIR_PR      ,IDX_TIMER_OUT_DZO23_DIR_PR      ,
  IDX_TIMER_IN_DZO23_INV         ,IDX_TIMER_OUT_DZO23_INV         ,
  IDX_TIMER_IN_DZO23_INV_PR      ,IDX_TIMER_OUT_DZO23_INV_PR      ,
  IDX_TIMER_IN_DZO23_AMTZ        ,IDX_TIMER_OUT_DZO23_AMTZ        ,
  IDX_TIMER_IN_DZO23_AMTZ_PR     ,IDX_TIMER_OUT_DZO23_AMTZ_PR     ,
  IDX_TIMER_IN_DZO23_VVID_PR     ,IDX_TIMER_OUT_DZO23_VVID_PR     ,
  IDX_TIMER_IN_DZO23_AMTZ_VVID_PR,IDX_TIMER_OUT_DZO23_AMTZ_VVID_PR,
//  IDX_TIMER_IN_DZO3_DIR         ,IDX_TIMER_OUT_DZO3_DIR         ,
//  IDX_TIMER_IN_DZO3_DIR_PR      ,IDX_TIMER_OUT_DZO3_DIR_PR      ,
//  IDX_TIMER_IN_DZO3_INV         ,IDX_TIMER_OUT_DZO3_INV         ,
//  IDX_TIMER_IN_DZO3_INV_PR      ,IDX_TIMER_OUT_DZO3_INV_PR      ,
//  IDX_TIMER_IN_DZO3_AMTZ        ,IDX_TIMER_OUT_DZO3_AMTZ        ,
//  IDX_TIMER_IN_DZO3_AMTZ_PR     ,IDX_TIMER_OUT_DZO3_AMTZ_PR     ,
//  IDX_TIMER_IN_DZO3_VVID_PR     ,IDX_TIMER_OUT_DZO3_VVID_PR     ,
//  IDX_TIMER_IN_DZO3_AMTZ_VVID_PR,IDX_TIMER_OUT_DZO3_AMTZ_VVID_PR,

};
enum DZO4_ID_TMR_BIT{

  IDX_TIMER_IN_DZO4_DIR         ,IDX_TIMER_OUT_DZO4_DIR         ,
  IDX_TIMER_IN_DZO4_INV         ,IDX_TIMER_OUT_DZO4_INV         ,
  IDX_TIMER_IN_DZO4_AMTZ        ,IDX_TIMER_OUT_DZO4_AMTZ        ,

};


 //typedef union U8_dzo_po_Unn{ 
 //   struct {
 //      unsigned int po_dzo_simple     : 1; //1
 //      unsigned int po_dzo_sector_dir : 1; //2
 //      unsigned int po_dzo_sector_inv : 1; //3
 //      unsigned int po_dzo_dir        : 1; //4
 //      unsigned int po_dzo_inv        : 1; //5
 //      unsigned int po_dzo_u_ust_pn   : 1; //6
 //      unsigned int po_dzo_pn         : 1; //7
 //      unsigned int po_res  : 1; //8
 //    } bool_val;
 //    unsigned char U8V;
 //} U8_dzo_po_wrp; 






//In this typedef place signal 1 in out not have 2 or more customers
typedef union U32_dzo1_po_Unn{ 
   struct {
      unsigned int m_fault_u_dzo                  :1; //0
      unsigned int m_block_dzo1_i_osn_3g          :1; //1
      unsigned int m_block_dzo1_i_osn             :1; //2
      unsigned int m_dzo1_amtz                    :1; //3
      unsigned int dv_zvn_nespr_dzo               :1; //4
      unsigned int dv_zbr_block_dzo1_i_o_3g       :1; //5
      unsigned int dv_zbr_block_dzo1_i_o          :1; //6
      unsigned int dv_block_dzo1                  :1; //7
      unsigned int and04_o_0                      :1; //8
      unsigned int or05_o_0                       :1; //9
      unsigned int not01_o_0                      :1;//10
      unsigned int not02_o_0                      :1;//11
      unsigned int not03_o_0                      :1;//12
      unsigned int or06_o_0                       :1;//13
      unsigned int and07_o_0                      :1;//14
      unsigned int and08_o_0                      :1;//15
      unsigned int u_dzo_u_o_less_up_0_25p_un     :1;//16
      unsigned int i_less_ip_0_p_5                :1;//17
      unsigned int i_o3g_div_i_o1g_dzo            :1;//18
      unsigned int po2_i_blk_dzo                  :1;//19
      unsigned int po_amcz_dzo1                   :1;//20
      unsigned int po_dzo1                        :1;//21
      unsigned int not17_o_0                      :1;//22
      unsigned int nkno_rng_big                   :1;//23
      unsigned int nkn_dzo1                       :1;//24
      unsigned int and09_o_0                      :1;//25
      unsigned int and10_o_0                      :1;//26
      unsigned int or11_o_0                       :1;//27
      unsigned int and12_o_0                      :1;//28
      unsigned int nor13_o_0                      :1;//29
      unsigned int m_dzo1                         :1;//30
      unsigned int b31                            :1;//31    
  
    } bool_val;
    unsigned long U32V;
} U32_dzo1_wrp; 

typedef union U32_dzo23_po_Unn{ 
   struct {
      unsigned int m_dzo2_const_pr               :1; //0
      unsigned int m_dzo2_pr_vid_vvo             :1; //1
      unsigned int b02                           :1; //2   m_block_dzo2_i_osn_3g
      unsigned int m_dzo2_amtz                   :1; //3
      unsigned int m_dzo2                        :1; //4
      unsigned int m_dzo2_dir                    :1; //5
      unsigned int m_dzo2_inv                    :1; //6
      unsigned int dv_blk_usk_dzo2               :1; //7
      unsigned int dv_op_usk_dzo2                :1; //8
      unsigned int b09                           :1; //9    dv_zbr_blk_dzo2_i_o_3g
      unsigned int b10                           :1;//10    dv_blk_dzo2           
      unsigned int sector_dir_dzo2               :1;//11
      unsigned int sector_inv_dzo2               :1;//12
      unsigned int po_dir_dzo2                   :1;//13
      unsigned int po_inv_dzo2                   :1;//14
      unsigned int po_amcz_dzo2                  :1;//15
      unsigned int not01_o_0                     :1;//16
      unsigned int or02_o_0                      :1;//17
      unsigned int and03_o_0                     :1;//18
      unsigned int and06_o_0                     :1;//19
      unsigned int b20                           :1;//20
      unsigned int and10_o_0                     :1;//21
      unsigned int T_vv_usk_dzo23                :1;//22
      unsigned int T_vv_usk_amtzo23              :1;//23
      unsigned int and13_o_0                     :1;//24
      unsigned int and14_o_0                     :1;//25
      unsigned int and15_o_0                     :1;//26
      unsigned int or16_o_0                      :1;//27
      unsigned int or17_o_0                      :1;//28
      unsigned int not04_o_0                     :1;//29
      unsigned int not05_o_0                     :1;//30
      unsigned int b31                            :1;//31    
  
    } bool_val;
    unsigned long U32V;
} U32_dzo23_wrp; 

typedef union U32_dzo23_Unn1{ 
   struct {
      unsigned int not39_o_0                :1;//0
      unsigned int not40_o_0                :1;//1
      unsigned int not18_o_0                :1;//2
      unsigned int not19_o_0                :1;//3
      unsigned int not41_o_0                :1;//4
      unsigned int not42_o_0                :1;//5
      unsigned int not43_o_0                :1;//6
      unsigned int not44_o_0                :1;//7
	  unsigned int not08_o_0                :1;//8
	  unsigned int or11_o_0                 :1;//9
	  unsigned int or12_o_0                 :1;//10
	  unsigned int or47_o_0                 :1;//11
	  unsigned int and46_o_0                :1;//12
	  unsigned int dv_blk_dzo2              :1;//13
	  unsigned int cmd_po2_i_blk_dzo        :1;//14
	  unsigned int dv_zbr_blk_dzo2_i_o_3g   :1;//15
	  unsigned int m_block_dzo2_i_osn_3g    :1;//16
      unsigned int cmd_i_o3g_div_i_o1g_dzo  :1;//17
      unsigned int cmd_snkn_dzo             :1;//18
      unsigned int not09_o_0                :1;//19
      unsigned int m_dzo2_amtz              :1;//20
      unsigned int po_amcz_dzo23_now        :1;//21
      unsigned int b22                      :1;//22
      unsigned int b23                      :1;//23
      unsigned int b24                      :1;//24
      unsigned int b25                      :1;//25
      unsigned int b26                      :1;//26
      unsigned int b27                      :1;//27
      unsigned int b28                      :1;//28
      unsigned int b29                      :1;//29
      unsigned int b30                      :1;//30
      unsigned int b31                      :1;//31

 
    } bool_val;
    unsigned long U32V;
} U32_dzo23_wrp1; 




typedef union U32_dzo4_po_Unn{ 
   struct {
      unsigned int m_dzo4                         :1; //0
      unsigned int m_dzo4_dir                     :1; //1
      unsigned int m_dzo4_inv                     :1; //2
      unsigned int m_dzo4_amtz                    :1; //3
      unsigned int m_block_dzo4_i_osn_3g          :1; //4
      unsigned int dv_zbr_blk_dzo4_i_o_3g         :1; //5
      unsigned int dv_blk_dzo4                    :1; //6
      unsigned int naprym_dir_dzo4                :1; //7
      unsigned int naprym_inv_dzo4                :1; //8
      unsigned int po_dir_dzo4                    :1; //9
      unsigned int po_inv_dzo4                    :1;//10
      unsigned int po_amcz_dzo4                   :1;//11
      unsigned int and01_o_0                      :1;//12
      unsigned int or02_o_0                       :1;//13
      unsigned int or03_o_0                       :1;//14
      unsigned int and04_o_0                      :1;//15
      unsigned int not05_o_0                      :1;//16
      unsigned int not06_o_0                      :1;//17
      unsigned int not07_o_0                      :1;//18
      unsigned int not08_o_0                      :1;//19
      unsigned int and19_o_0                      :1;//20
      unsigned int or20_o_0                       :1;//21
      unsigned int or21_o_0                       :1;//22
      unsigned int cmd_i_o3g_div_i_o1g_dzo        :1;//23
      unsigned int cmd_i_less_ip_0_p_5            :1;//24
      unsigned int cmd_snkn_dzo                   :1;//25
      unsigned int and12_o_0                      :1;//26
      unsigned int and11_o_0                      :1;//27
      unsigned int rv_ror18__i_1                  :1;//28
      unsigned int rv_ror18__i_0                  :1;//29
      unsigned int rv_and22_i_3                   :1;//30
      unsigned int b31                            :1;//31    
  
    } bool_val;
    unsigned long U32V;
} U32_dzo4_wrp; 




//
//enum DZO1_SCHEMATIC_LU_ORDER_NUMS{
//
//
//TOTAL_PROCESS_DZO1_LU
//};
//
//enum DZO23_SCHEMATIC_LU_ORDER_NUMS{
//
//
//
//
//TOTAL_PROCESS_DZO23_LU
//};
//
//enum DZO4_SCHEMATIC_LU_ORDER_NUMS{
//
//
//
//
//TOTAL_PROCESS_DZO4_LU
//};
//


//==============================================================
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//! sector_directional_dz[4 - 2][2]
//! 
//! Перший індекс [4 - 2] - ступінь: 0 - ДЗ2; 1 - ДЗ3
//!  (ДЗ1 і ДЗ4, я так пригадую не працюють з сектором)
//!  
//! Другий індекс [2] - 0 - основна лінія; 1 - резарвна лінія
//..............................................................
//==============================================================






extern char glb_ch_id_dzo;

#endif

