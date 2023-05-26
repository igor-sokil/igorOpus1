#include <string.h> 
#include "const_global.h"
#include "dzr.h"
#include "mtzo.h"

void dzr_handler(unsigned int *p_active_functions, unsigned int number_group_stp );
void dzr1_handler(unsigned int *p_active_functions, unsigned int number_group_stp );
void dzr23_handler(unsigned int *p_active_functions, unsigned int number_group_stp );
void dzr4_handler(unsigned int *p_active_functions, unsigned int number_group_stp );
 char glb_ch_id_dzr = ID_DZR2;
//=====================================================================================================
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//                
//....................................................................................................
//=====================================================================================================

void dzr_handler(unsigned int *p_active_functions, unsigned int number_group_stp ){
    dzr1_handler(p_active_functions,number_group_stp);
    glb_ch_id_dzr = ID_DZR2;
    dzr23_handler(p_active_functions,number_group_stp);
    glb_ch_id_dzr = ID_DZR3;
    dzr23_handler(p_active_functions,number_group_stp);

}
//
//--------------------------------------------------------------------------------------------------------
U8_state_wrp   stt_DZR2_And29__3_1, stt_DZR2_And30__3_1,
               stt_DZR2_And33__3_1,stt_DZR2_And34__3_1,
               stt_DZR2_And37__3_1,stt_DZR2_And38__3_1;
U8_state_wrp   stt_DZR3_And29__3_1,stt_DZR3_And30__3_1,
               stt_DZR3_And33__3_1,stt_DZR3_And34__3_1,
               stt_DZR3_And37__3_1,stt_DZR3_And38__3_1;
    
static unsigned long u32_bit_dzr2_ext = 0, u32_bit_dzr3_ext = 0;
//=====================================================================================================
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//                  
//....................................................................................................
//=====================================================================================================
void dzr23_handler(unsigned int *p_active_functions, unsigned int number_group_stp )
{
 unsigned long rU;
 register U32_dzr23_wrp R_m_dv_po_dzr2;
 U32_dzr23_wrp1 simple_elem_dzr2;
 struct{
    unsigned long po_dzr2_dir_spt,po_dzr2_inv_spt,
    po_dzr2_amcz_spt;
    __SETTINGS *p_current_settings_prt;
    char ch_id_dzr;
  }sLV;    
    R_m_dv_po_dzr2.U32V = 0;
    simple_elem_dzr2.U32V = 0;
    U8_state_wrp //stt_DZR2_
    stt_DZR2_And20__2_1,
    stt_DZR2_And21__2_1,
    stt_DZR2_OrN22__3_1,
    stt_DZR2_OrN23__3_1,
    stt_DZR2_OrN24__2_1,
    stt_DZR2_OrN44__2_1,
    stt_DZR2_And25__5_1,
    stt_DZR2_And45__5_1,
    stt_DZR2_And26__6_1,
    stt_DZR2_Or27__2_1 ,
    
    stt_DZR2_Or28__2_1 ,
    
    stt_DZR2_Or31__2_1 ,
    
    stt_DZR2_Or32__2_1 ,
    
    stt_DZR2_Or35__2_1 ,
    stt_DZR2_Or36__2_1     ;
    rU = 0;
    stt_DZR2_And20__2_1.U8V = rU;
    stt_DZR2_And21__2_1.U8V = rU;
    stt_DZR2_OrN22__3_1.U8V = rU;
    stt_DZR2_OrN23__3_1.U8V = rU;
    stt_DZR2_OrN24__2_1.U8V = rU;
    stt_DZR2_OrN44__2_1.U8V = rU;
    stt_DZR2_And25__5_1.U8V = rU;
    stt_DZR2_And45__5_1.U8V = rU;
    stt_DZR2_And26__6_1.U8V = rU;
    stt_DZR2_Or27__2_1 .U8V = rU;
    //stt_DZR2_And29__3_1.U8V = rU;
    stt_DZR2_Or28__2_1 .U8V = rU;
    //stt_DZR2_And30__3_1.U8V = rU;
    stt_DZR2_Or31__2_1 .U8V = rU;
    //stt_DZR2_And33__3_1.U8V = rU;
    stt_DZR2_Or32__2_1 .U8V = rU;
    //stt_DZR2_And34__3_1.U8V = rU;
    stt_DZR2_Or35__2_1 .U8V = rU;
    //stt_DZR2_And37__3_1.U8V = rU;
    stt_DZR2_Or36__2_1 .U8V = rU;
    //stt_DZR2_And38__3_1.U8V = rU;
    simple_elem_dzr2.U32V =  rU;
    sLV.p_current_settings_prt = &current_settings_prt ;
    sLV.ch_id_dzr = glb_ch_id_dzr;
    do{ 
        //...........................................................................
        //```````````````````````````````````````````````````````````````````````````
        if(sLV.ch_id_dzr == ID_DZR2){
            long lV = (sLV.p_current_settings_prt->control_dzr & (1<<INDEX_CTR_DZR2_CONST_PR));
            R_m_dv_po_dzr2.bool_val.m_dzr2_const_pr = lV!=0;
            
            lV = _CHECK_SET_BIT(p_active_functions, RNG_BIG_BLOCK_PR_DZR2); 
            R_m_dv_po_dzr2.bool_val.dv_blk_usk_dzr2 = lV!=0;
            rU = R_m_dv_po_dzr2.bool_val.dv_blk_usk_dzr2;
            R_m_dv_po_dzr2.bool_val.not01_o_0 = (~rU)&1;
            
            lV = _CHECK_SET_BIT(p_active_functions, RNG_BIG_OP_PR_DZR2); 
            R_m_dv_po_dzr2.bool_val.dv_op_usk_dzr2 = lV!=0;    
            
            lV = (sLV.p_current_settings_prt->control_dzr & (1<<INDEX_CTR_DZR2_PR_VID_VVR));
            R_m_dv_po_dzr2.bool_val.m_dzr2_pr_vid_vvo = lV!=0;
            //or02_o_0
            rU = R_m_dv_po_dzr2.U32V &( (1<<0)|(1<<8));//m_dzr2_const_pr dv_op_usk_dzr2
            if( rU!= 0) 
                R_m_dv_po_dzr2.bool_val.or02_o_0 = 1;
            
        }else{
            //ID_DZR3
            long lV = (sLV.p_current_settings_prt->control_dzr & (1<<INDEX_CTR_DZR3_CONST_PR));
            R_m_dv_po_dzr2.bool_val.m_dzr2_const_pr = lV!=0;
            
            lV = _CHECK_SET_BIT(p_active_functions, RNG_BIG_BLOCK_PR_DZR3); 
            R_m_dv_po_dzr2.bool_val.dv_blk_usk_dzr2 = lV!=0;
            rU = R_m_dv_po_dzr2.bool_val.dv_blk_usk_dzr2;
            R_m_dv_po_dzr2.bool_val.not01_o_0 = (~rU)&1;
            
            lV = _CHECK_SET_BIT(p_active_functions, RNG_BIG_OP_PR_DZR3); 
            R_m_dv_po_dzr2.bool_val.dv_op_usk_dzr2 = lV!=0;    
            
            lV = (sLV.p_current_settings_prt->control_dzr & (1<<INDEX_CTR_DZR3_PR_VID_VVR));
            R_m_dv_po_dzr2.bool_val.m_dzr2_pr_vid_vvo = lV!=0;
            //or02_o_0
            rU = R_m_dv_po_dzr2.U32V &( (1<<0)|(1<<8));//m_dzr2_const_pr dv_op_usk_dzr2
            if( rU!= 0) 
                R_m_dv_po_dzr2.bool_val.or02_o_0 = 1;
            
        }
        //...........................................................................
        //```````````````````````````````````````````````````````````````````````````
        register long lV = _CHECK_SET_BIT(p_active_functions, RNG_BIG_STATE_VVR);
        //```````````````````````````````````````````````````````````
        unsigned long u32_bit_holder = 0;rU = 0;
        if(sLV.ch_id_dzr == ID_DZR2){
             
            if(lV!=0 && R_m_dv_po_dzr2.bool_val.m_dzr2_pr_vid_vvo==1)
                u32_bit_holder |= (1<< IDX_TIMER_IN_DZR23_VVID_PR )|(1<<IDX_TIMER_IN_DZR23_AMTZ_VVID_PR);

            _TIMER_IMPULSE(INDEX_TIMER_DZR2_VVID_PR,
            sLV.p_current_settings_prt->timeout_dzr2_vvid_pr[number_group_stp],
            u32_bit_dzr2_ext, IDX_TIMER_IN_DZR23_VVID_PR ,u32_bit_holder, 
            IDX_TIMER_IN_DZR23_VVID_PR , u32_bit_holder, IDX_TIMER_OUT_DZR23_VVID_PR);
            _TIMER_IMPULSE(INDEX_TIMER_DZR2_AMTZ_VVID_PR,
            sLV.p_current_settings_prt->timeout_dzr2_amtz_vvid_pr[number_group_stp],
            u32_bit_dzr2_ext,IDX_TIMER_IN_DZR23_AMTZ_VVID_PR ,u32_bit_holder,
            IDX_TIMER_IN_DZR23_AMTZ_VVID_PR, u32_bit_holder, IDX_TIMER_OUT_DZR23_AMTZ_VVID_PR);
            
            
        }else{
            //ID_DZR3
            if(lV!=0 && R_m_dv_po_dzr2.bool_val.m_dzr2_pr_vid_vvo==1)
                u32_bit_holder |= (1<< IDX_TIMER_IN_DZR23_VVID_PR )|(1<<IDX_TIMER_IN_DZR23_AMTZ_VVID_PR);

            _TIMER_IMPULSE(INDEX_TIMER_DZR3_VVID_PR,
            sLV.p_current_settings_prt->timeout_dzr3_vvid_pr[number_group_stp],
            u32_bit_dzr3_ext, IDX_TIMER_IN_DZR23_VVID_PR ,u32_bit_holder, 
            IDX_TIMER_IN_DZR23_VVID_PR , u32_bit_holder, IDX_TIMER_OUT_DZR23_VVID_PR);
            _TIMER_IMPULSE(INDEX_TIMER_DZR3_AMTZ_VVID_PR,
            sLV.p_current_settings_prt->timeout_dzr3_amtz_vvid_pr[number_group_stp],
            u32_bit_dzr3_ext,IDX_TIMER_IN_DZR23_AMTZ_VVID_PR ,u32_bit_holder,
            IDX_TIMER_IN_DZR23_AMTZ_VVID_PR, u32_bit_holder, IDX_TIMER_OUT_DZR23_AMTZ_VVID_PR);
            
        }
        //and6
            if ( u32_bit_holder&(1<<IDX_TIMER_OUT_DZR23_VVID_PR ) )
                R_m_dv_po_dzr2.bool_val.T_vv_usk_dzr23 = 1;
            //and5
            if ( u32_bit_holder&(1<<IDX_TIMER_OUT_DZR23_AMTZ_VVID_PR ) )
                R_m_dv_po_dzr2.bool_val.T_vv_usk_amtzr23 = 1;
        
        
    
    }while (rU != 0);    
    
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    //and13
    rU = R_m_dv_po_dzr2.U32V &( (1<<16)|(1<<17));// not01_o_0 or02_o_0
    if(rU == ( (1<<16)|(1<<17)) )
        R_m_dv_po_dzr2.bool_val.and13_o_0 = 1;
    //and14
    rU = R_m_dv_po_dzr2.U32V &( (1<<16)|(1<<22));//not01_o_0 T_vv_usk_dzr23
    if(rU == ( (1<<16)|(1<<22 )) )
        R_m_dv_po_dzr2.bool_val.and14_o_0 = 1; 
    //and15
    rU = R_m_dv_po_dzr2.U32V &( (1<<16)|(1<<23));//not01_o_0 T_vv_usk_amtzo23 
    if(rU == ( (1<<16 )|(1<<23 )))
        R_m_dv_po_dzr2.bool_val.and15_o_0 = 1; 
    //or16
    rU = R_m_dv_po_dzr2.U32V &( (1<<24)|(1<<25));
    if( rU!= 0) 
        R_m_dv_po_dzr2.bool_val.or16_o_0 = 1;
    //not4
    rU = R_m_dv_po_dzr2.bool_val.or16_o_0;
    R_m_dv_po_dzr2.bool_val.not04_o_0 = (~rU)&1;
    //or17
    rU = R_m_dv_po_dzr2.U32V &( (1<<25)|(1<<26));
    if( rU!= 0) 
        R_m_dv_po_dzr2.bool_val.or17_o_0 = 1;
    //not5
    rU = R_m_dv_po_dzr2.bool_val.or17_o_0;
    R_m_dv_po_dzr2.bool_val.not05_o_0 = (~rU)&1;
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_I_RSV_3G_DIV_1G_DZR);
    simple_elem_dzr2.bool_val.cmd_i_r3g_div_i_r1g_dzr = rU!=0;
    if(sLV.ch_id_dzr == ID_DZR2){
        long lV =  (sLV.p_current_settings_prt->control_dzr & (1<< INDEX_CTR_BLOCK_DZR2_I_RSV_3G));
        simple_elem_dzr2.bool_val.m_block_dzr2_i_rsv_3g = lV!=0;
        lV = _CHECK_SET_BIT(p_active_functions,RNG_BIG_ZBR_BLOCK_DZR2_I_R_3G);
        simple_elem_dzr2.bool_val.dv_zbr_blk_dzr2_i_r_3g = lV!=0;
        rU = simple_elem_dzr2.bool_val.dv_zbr_blk_dzr2_i_r_3g;
        simple_elem_dzr2.bool_val.not08_o_0 = (~rU)&1;
    }else{
        //ID_DZR3
        long lV =  (sLV.p_current_settings_prt->control_dzr & (1<< INDEX_CTR_BLOCK_DZR3_I_RSV_3G));
        simple_elem_dzr2.bool_val.m_block_dzr2_i_rsv_3g = lV!=0;
        lV = _CHECK_SET_BIT(p_active_functions,RNG_BIG_ZBR_BLOCK_DZR3_I_R_3G);
        simple_elem_dzr2.bool_val.dv_zbr_blk_dzr2_i_r_3g = lV!=0;
        rU = simple_elem_dzr2.bool_val.dv_zbr_blk_dzr2_i_r_3g;
        simple_elem_dzr2.bool_val.not08_o_0 = (~rU)&1;
    }
     //and46
    rU = simple_elem_dzr2.U32V &( (1<<17)|(1<<16)|(1<<8) );//cmd_i_o3g_div_i_o1g_dzr  m_block_dzr2_i_osn_3g not08_o_0
    if( rU == ( (1<<17)|(1<<16)|(1<<8) )  ){
        simple_elem_dzr2.bool_val.and46_o_0 = 1;
        if(sLV.ch_id_dzr == ID_DZR2){
            _SET_BIT(p_active_functions,RNG_BIG_BLK_DZR2_I_RSV_3G_DIV_1G);
        }else{
            //ID_DZR3
            _SET_BIT(p_active_functions,RNG_BIG_BLK_DZR3_I_RSV_3G_DIV_1G);
        }
         
    }else{
        if(sLV.ch_id_dzr == ID_DZR2){
            _CLEAR_BIT(p_active_functions,RNG_BIG_BLK_DZR2_I_RSV_3G_DIV_1G);
        }else{
            //ID_DZR3
            _CLEAR_BIT(p_active_functions,RNG_BIG_BLK_DZR3_I_RSV_3G_DIV_1G);
        }
        
    }
    
    
    rU = _CHECK_SET_BIT(p_active_functions,RNG_BIG_I_BLK_DZR_I_LESS_0_P_5A );//RNG_BIG_PO2_I_BLK_DZR
    simple_elem_dzr2.bool_val.cmd_po2_i_blk_dzr = rU!=0;
    if(sLV.ch_id_dzr == ID_DZR2){
        rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_BLOCK_DZR2);
        simple_elem_dzr2.bool_val.dv_blk_dzr2 = rU!=0;
    }else{
            //ID_DZR3
        rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_BLOCK_DZR3);
        simple_elem_dzr2.bool_val.dv_blk_dzr2 = rU!=0;     
        }
    
    
    //and47
    rU = simple_elem_dzr2.U32V &( (1<<12)|(1<<14)|(1<<13) );//and46_o_0 po2_i_blk_dzr dv_blk_dzr2 
    if( rU != 0  ){
        simple_elem_dzr2.bool_val.or47_o_0 = 1;
        if(sLV.ch_id_dzr == ID_DZR2){
            _SET_BIT(p_active_functions,RNG_BIG_BLK_DZR2);
        }else{
            //ID_DZR3
            _SET_BIT(p_active_functions,RNG_BIG_BLK_DZR3);
        }
         
    }else{
        if(sLV.ch_id_dzr == ID_DZR2){
            _CLEAR_BIT(p_active_functions,RNG_BIG_BLK_DZR2);
        }else{
            //ID_DZR3
            _CLEAR_BIT(p_active_functions,RNG_BIG_BLK_DZR3);
        }
        
    }
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    if(sLV.ch_id_dzr == ID_DZR2){
        rU = (sLV.p_current_settings_prt->control_dzr & (1<<INDEX_CTR_DZR2_AMTZ ));
        R_m_dv_po_dzr2.bool_val.m_dzr2_amtz = rU!=0;
        //...........................................
        //```````````````````````````````````````````
        rU = _CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_AMCZ_DZR2);
        if( rU!= 0) {
                sLV.po_dzr2_amcz_spt = sLV.p_current_settings_prt->pickup_dzr2_amtz[number_group_stp]
         * KOEF_POVERNENNJA_MTZ_I_UP / 100;
        }else{
            sLV.po_dzr2_amcz_spt = sLV.p_current_settings_prt->pickup_dzr2_amtz[number_group_stp];
        }
        R_m_dv_po_dzr2.bool_val.po_amcz_dzr2 = rU!=0;
        //...........................................
        //```````````````````````````````````````````
    }else{
        //ID_DZR3
        rU = (sLV.p_current_settings_prt->control_dzr & (1<< INDEX_CTR_DZR3_AMTZ));
        R_m_dv_po_dzr2.bool_val.m_dzr2_amtz = rU!=0;   
        //...........................................
        //```````````````````````````````````````````
        rU = _CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_AMCZ_DZR3);
        if( rU!= 0) {
                sLV.po_dzr2_amcz_spt = sLV.p_current_settings_prt->pickup_dzr3_amtz[number_group_stp]
         * KOEF_POVERNENNJA_MTZ_I_UP / 100;
        }else{
            sLV.po_dzr2_amcz_spt = sLV.p_current_settings_prt->pickup_dzr3_amtz[number_group_stp];
        }
        R_m_dv_po_dzr2.bool_val.po_amcz_dzr2 = rU!=0;//=DZR3_OrN44 ~~
        //...........................................
        //```````````````````````````````````````````
    }
    //-- AMCZ
    if(measurement[IM_Ibp] >= sLV.po_dzr2_amcz_spt){
        simple_elem_dzr2.bool_val.po_amcz_dzr23_now = 1;
    }else{    
        simple_elem_dzr2.bool_val.po_amcz_dzr23_now = 0;
    }
    //--
    rU = _CHECK_SET_BIT(p_active_functions,RNG_BIG_CNKN_DZR);
    simple_elem_dzr2.bool_val.cmd_snkn_dzr = rU!=0;
    //--
    rU = R_m_dv_po_dzr2.bool_val.m_dzr2_amtz;
    simple_elem_dzr2.bool_val.m_dzr2_amtz = rU;
    simple_elem_dzr2.bool_val.not09_o_0 = (~rU)&1; 
    //and10
    rU = simple_elem_dzr2.U32V &( (1<<18)|(1<<20) );// cmd_snkn_dzr m_dzr2_amtz
    if(rU == ( (1<<18 )| (1<<20 )))
        R_m_dv_po_dzr2.bool_val.and10_o_0 = 1;
    //and6
    rU = simple_elem_dzr2.U32V &( (1<<18)|(1<<19));//  cmd_snkn_dzr not09_o_0
    if(rU == ( (1<<18 )| (1<<19 )))
    R_m_dv_po_dzr2.bool_val.and06_o_0 = 1;
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    //==============================================================
    //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
    //! sector_directional_dz[4 - 2][2]
    //! 
    //! Перший індекс [4 - 2] - ступінь: 0 - ДЗ2; 1 - ДЗ3
    //!  (ДЗ1 і ДЗ4, я так пригадую не працюють з сектором)
    //!  
    //! Другий індекс [2] - 0 - основна лінія; 1 - резарвна лінія
    //typedef enum _sector_dz
    //                      {
    //                      SECTOR_DZ_NONE = 0,
    //                      SECTOR_DZ_FORWARD,
    //                      SECTOR_DZ_BACKWARD
    //                      
    //                      } __sector_dz;
    //..............................................................
    //==============================================================
    if(sLV.ch_id_dzr == ID_DZR2){
        if((sector_directional_dz[ID_DZR2][PHASE_BP_INDEX] == SECTOR_DZ_FORWARD)){
            R_m_dv_po_dzr2.bool_val.sector_dir_dzr2 = 1;
            _SET_BIT(p_active_functions, RNG_BIG_SECTOR_DIR_DZR2);
        }else{ 
            R_m_dv_po_dzr2.bool_val.sector_dir_dzr2 = 0;
            _CLEAR_BIT(p_active_functions, RNG_BIG_SECTOR_DIR_DZR2);
        }   
        if(sector_directional_dz[ID_DZR2][PHASE_BP_INDEX] == SECTOR_DZ_BACKWARD){
            R_m_dv_po_dzr2.bool_val.sector_inv_dzr2 = 1;
            _SET_BIT(p_active_functions, RNG_BIG_SECTOR_INV_DZR2);
        }else{
            R_m_dv_po_dzr2.bool_val.sector_inv_dzr2 = 0;
            _CLEAR_BIT(p_active_functions, RNG_BIG_SECTOR_INV_DZR2);
        }   
    }else{
        //ID_DZR3
        if((sector_directional_dz[ID_DZR3][PHASE_BP_INDEX] == SECTOR_DZ_FORWARD)){
            R_m_dv_po_dzr2.bool_val.sector_dir_dzr2 = 1;
            _SET_BIT(p_active_functions, RNG_BIG_SECTOR_DIR_DZR3);
        }else{ 
            R_m_dv_po_dzr2.bool_val.sector_dir_dzr2 = 0;
            _CLEAR_BIT(p_active_functions, RNG_BIG_SECTOR_DIR_DZR3);
        }   
        if(sector_directional_dz[ID_DZR3][PHASE_BP_INDEX] == SECTOR_DZ_BACKWARD){
            R_m_dv_po_dzr2.bool_val.sector_inv_dzr2 = 1;
            _SET_BIT(p_active_functions, RNG_BIG_SECTOR_INV_DZR3);
        }else{
            R_m_dv_po_dzr2.bool_val.sector_inv_dzr2 = 0;
            _CLEAR_BIT(p_active_functions, RNG_BIG_SECTOR_INV_DZR3);
        }   
    }
    if(sLV.ch_id_dzr == ID_DZR2){
        R_m_dv_po_dzr2.bool_val.m_dzr2 = (sLV.p_current_settings_prt->control_dzr & (1<<INDEX_CTR_DZR2 ))!=0;    
    }else{
        //ID_DZR3
        R_m_dv_po_dzr2.bool_val.m_dzr2 = (sLV.p_current_settings_prt->control_dzr & (1<<INDEX_CTR_DZR3 ))!=0;    
    }
    //or12
    rU = R_m_dv_po_dzr2.U32V &( (1<<19)|(1<<11));//and06_o_0 sector_dir_dzr2
    if( rU!= 0) 
        simple_elem_dzr2.bool_val.or12_o_0 = 1;//R_m_dv_po_dzr2.bool_val.or16_o_0 = 1;
    //or11
    rU = R_m_dv_po_dzr2.U32V &( (1<<19)|(1<<12));//and06_o_0 sector_inv_dzr2
    if( rU!= 0) 
        simple_elem_dzr2.bool_val.or11_o_0 = 1;//R_m_dv_po_dzr2.bool_val.or16_o_0 = 1;
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    //not18
    if(sLV.ch_id_dzr == ID_DZR2){
        rU = (_CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_DIR_DZR2))!=0; 
        simple_elem_dzr2.bool_val.not18_o_0 =  (~rU)&1;
    }else{
        //ID_DZR3
        rU = (_CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_DIR_DZR3))!=0; 
        simple_elem_dzr2.bool_val.not18_o_0 =  (~rU)&1;
    }
    //not19
    if(sLV.ch_id_dzr == ID_DZR2){
        rU = (_CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_INV_DZR2))!=0; 
        simple_elem_dzr2.bool_val.not19_o_0 =  (~rU)&1;    
    }else{
        //ID_DZR3
        rU = (_CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_INV_DZR3))!=0; 
        simple_elem_dzr2.bool_val.not19_o_0 =  (~rU)&1;    
    }
    rU = R_m_dv_po_dzr2.bool_val.and10_o_0;
    
    //and20
    stt_DZR2_And20__2_1.bool_val.bt0 = rU;//R_m_dv_po_dzr2.bool_val.and10_o_0;
    stt_DZR2_And20__2_1.bool_val.bt1 = simple_elem_dzr2.bool_val.not18_o_0;
    if ((stt_DZR2_And20__2_1.U8V &3) == 3){
        stt_DZR2_OrN22__3_1.bool_val.bt1 = 1;//stt_DZR2_And20__2_1.bool_val.bt7 = 1;
    }   
    //and21
    stt_DZR2_And21__2_1.bool_val.bt0 = rU;//R_m_dv_po_dzr2.bool_val.and10_o_0;
    stt_DZR2_And21__2_1.bool_val.bt1 = simple_elem_dzr2.bool_val.not19_o_0;
    if ((stt_DZR2_And21__2_1.U8V &3) == 3){
        stt_DZR2_OrN23__3_1.bool_val.bt1 = 1;//stt_DZR2_And20__2_1.bool_val.bt7 = 1;
    }
    //nor44
    stt_DZR2_OrN44__2_1.bool_val.bt0 = rU;//R_m_dv_po_dzr2.bool_val.and10_o_0;
    rU = R_m_dv_po_dzr2.bool_val.po_amcz_dzr2; 
    stt_DZR2_OrN44__2_1.bool_val.bt1 = rU;
    if((stt_DZR2_OrN44__2_1.U8V &3) == 0){
        stt_DZR2_OrN24__2_1.bool_val.bt1 = 1;
    }
    stt_DZR2_OrN23__3_1.bool_val.bt2 = rU;
    stt_DZR2_OrN22__3_1.bool_val.bt2 = rU;
    rU = simple_elem_dzr2.bool_val.or47_o_0;
    stt_DZR2_OrN23__3_1.bool_val.bt0 = rU;
    stt_DZR2_OrN22__3_1.bool_val.bt0 = rU;
    stt_DZR2_OrN24__2_1.bool_val.bt0 = rU;
    //nor22
    if((stt_DZR2_OrN22__3_1.U8V &7) == 0)
        stt_DZR2_And25__5_1.bool_val.bt4 = 1;
    //nor23
    if((stt_DZR2_OrN23__3_1.U8V &7) == 0)
        stt_DZR2_And45__5_1.bool_val.bt4 = 1;
    //nor24
    if((stt_DZR2_OrN24__2_1.U8V &3) == 0)
        stt_DZR2_And26__6_1.bool_val.bt3 = 1;
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    rU = R_m_dv_po_dzr2.bool_val.m_dzr2;
    stt_DZR2_And25__5_1.bool_val.bt0 = rU;
    stt_DZR2_And45__5_1.bool_val.bt0 = rU;
    stt_DZR2_And26__6_1.bool_val.bt0 = rU;
    //and25
    
    if(sLV.ch_id_dzr == ID_DZR2){
        rU = (sLV.p_current_settings_prt->control_dzr & (1<< INDEX_CTR_DZR2_DIR));    
    }else{
        //ID_DZR3
        rU = (sLV.p_current_settings_prt->control_dzr & (1<< INDEX_CTR_DZR3_DIR));    
    }
    stt_DZR2_And25__5_1.bool_val.bt1 = rU!=0;
    
    if(sLV.ch_id_dzr == ID_DZR2){
        rU = _CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_DIR_DZR2);
        if( rU!= 0) {
                sLV.po_dzr2_dir_spt = sLV.p_current_settings_prt->pickup_dzr2_dir[number_group_stp]
            * KOEF_POVERNENNJA_MTZ_I_UP / 100;
        }else{
            sLV.po_dzr2_dir_spt = sLV.p_current_settings_prt->pickup_dzr2_dir[number_group_stp]; 
        }
    }else{
        //ID_DZR3
        rU = _CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_DIR_DZR3);
        if( rU!= 0) {
                sLV.po_dzr2_dir_spt = sLV.p_current_settings_prt->pickup_dzr3_dir[number_group_stp]
            * KOEF_POVERNENNJA_MTZ_I_UP / 100;
        }else{
            sLV.po_dzr2_dir_spt = sLV.p_current_settings_prt->pickup_dzr3_dir[number_group_stp]; 
        }    
    }
    if(R_m_dv_po_dzr2.bool_val.and06_o_0 == 0){
        rU = 0; 
        if(resistance[Z_bp]>0 ) 
             rU = resistance[Z_bp];//
    }else{
        rU = 0; 
        if(resistance[Za_bp]>0 ) 
             rU = resistance[Za_bp];
    }
if(rU >=  sLV.po_dzr2_dir_spt){
        stt_DZR2_And25__5_1.bool_val.bt2 = 1;
    }   
    stt_DZR2_And25__5_1.bool_val.bt3 = simple_elem_dzr2.bool_val.or12_o_0;
    if ((stt_DZR2_And25__5_1.U8V &31) == 31){ 
        stt_DZR2_And25__5_1.bool_val.bt7 = 1;
        if(sLV.ch_id_dzr == ID_DZR2){
            _SET_BIT(p_active_functions,RNG_BIG_PO_DIR_DZR2);
        }else{
        //ID_DZR3
            _SET_BIT(p_active_functions,RNG_BIG_PO_DIR_DZR3);    
        }
        
    }else{
        if(sLV.ch_id_dzr == ID_DZR2){
            _CLEAR_BIT(p_active_functions,RNG_BIG_PO_DIR_DZR2); 
        }else{
        //ID_DZR3
            _CLEAR_BIT(p_active_functions,RNG_BIG_PO_DIR_DZR3); 
        }
    }       
    //and45
    if(sLV.ch_id_dzr == ID_DZR2){
        rU = (sLV.p_current_settings_prt->control_dzr & (1<< INDEX_CTR_DZR2_INV));    
    }else{
        //ID_DZR3
        rU = (sLV.p_current_settings_prt->control_dzr & (1<< INDEX_CTR_DZR3_INV));    
    }
    stt_DZR2_And45__5_1.bool_val.bt1 = rU!=0;
        
    if(sLV.ch_id_dzr == ID_DZR2){
        rU = _CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_INV_DZR2);
        if( rU!= 0) {
                sLV.po_dzr2_inv_spt = sLV.p_current_settings_prt->pickup_dzr2_inv[number_group_stp]
            * KOEF_POVERNENNJA_MTZ_I_UP / 100;
        }else{
            sLV.po_dzr2_inv_spt = sLV.p_current_settings_prt->pickup_dzr2_inv[number_group_stp]; 
        }
    }else{
        //ID_DZR3
        rU = _CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_INV_DZR3);
        if( rU!= 0) {
                sLV.po_dzr2_inv_spt = sLV.p_current_settings_prt->pickup_dzr3_inv[number_group_stp]
            * KOEF_POVERNENNJA_MTZ_I_UP / 100;
        }else{
            sLV.po_dzr2_inv_spt = sLV.p_current_settings_prt->pickup_dzr3_inv[number_group_stp]; 
        }    
    }
    if(R_m_dv_po_dzr2.bool_val.and06_o_0 == 0){
        rU = 0; 
        if(resistance[Z_bp]>0 ) 
             rU = resistance[Z_bp];//
    }else{
        rU = 0; 
        if(resistance[Za_bp]>0 ) 
             rU = resistance[Za_bp];
    }

    if(rU >= sLV.po_dzr2_dir_spt){
        stt_DZR2_And45__5_1.bool_val.bt2 = 1;
    }
    stt_DZR2_And45__5_1.bool_val.bt3 = simple_elem_dzr2.bool_val.or11_o_0;
    if ((stt_DZR2_And45__5_1.U8V &31) == 31){ 
        stt_DZR2_And45__5_1.bool_val.bt7 = 1;
        if(sLV.ch_id_dzr == ID_DZR2){
            _SET_BIT(p_active_functions,RNG_BIG_PO_INV_DZR2);
        }else{
        //ID_DZR3
            _SET_BIT(p_active_functions,RNG_BIG_PO_INV_DZR3);    
        }
    }
    else{
        if(sLV.ch_id_dzr == ID_DZR2){
            _CLEAR_BIT(p_active_functions,RNG_BIG_PO_INV_DZR2); 
        }else{
        //ID_DZR3
            _CLEAR_BIT(p_active_functions,RNG_BIG_PO_INV_DZR3); 
        }
    }
    //and26
    //stt_DZR2_And26__6_1.bool_val.bt0 == init  R_m_dv_po_dzr2.bool_val.m_dzr2
    stt_DZR2_And26__6_1.bool_val.bt1 = simple_elem_dzr2.bool_val.not18_o_0;
    stt_DZR2_And26__6_1.bool_val.bt2 = simple_elem_dzr2.bool_val.not19_o_0;
    //stt_DZR2_And26__6_1.bool_val.bt3 = init nor24
    stt_DZR2_And26__6_1.bool_val.bt4 = simple_elem_dzr2.bool_val.po_amcz_dzr23_now;
    stt_DZR2_And26__6_1.bool_val.bt5 = simple_elem_dzr2.bool_val.m_dzr2_amtz; 
    if ((stt_DZR2_And26__6_1.U8V &63) == 63){ 
        stt_DZR2_And26__6_1.bool_val.bt7 = 1;
        if(sLV.ch_id_dzr == ID_DZR2){
            _SET_BIT(p_active_functions,RNG_BIG_PO_AMCZ_DZR2);
        }else{
        //ID_DZR3
            _SET_BIT(p_active_functions,RNG_BIG_PO_AMCZ_DZR3);    
        }
    }
    else{
        if(sLV.ch_id_dzr == ID_DZR2){
            _CLEAR_BIT(p_active_functions,RNG_BIG_PO_AMCZ_DZR2); 
        }else{
        //ID_DZR3
            _CLEAR_BIT(p_active_functions,RNG_BIG_PO_AMCZ_DZR3); 
        }
    }
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
 if(sLV.ch_id_dzr == ID_DZR2){
            //Or27
    stt_DZR2_Or27__2_1.bool_val.bt0 = R_m_dv_po_dzr2.bool_val.or16_o_0;
    rU = stt_DZR2_And29__3_1.bool_val.bt7;
    stt_DZR2_Or27__2_1.bool_val.bt1 = rU;
    if((stt_DZR2_Or27__2_1.U8V &3) != 0)
        stt_DZR2_Or27__2_1.bool_val.bt7 = 1;
    //Not44     
    simple_elem_dzr2.bool_val.not44_o_0 = (~rU)&1;
    //Or28
    stt_DZR2_Or28__2_1.bool_val.bt0 = R_m_dv_po_dzr2.bool_val.not04_o_0;
    rU = stt_DZR2_And30__3_1.bool_val.bt7;
    stt_DZR2_Or28__2_1.bool_val.bt1 = rU; 
    if((stt_DZR2_Or28__2_1.U8V &3) != 0)
        stt_DZR2_Or28__2_1.bool_val.bt7 = 1;
    //Not43 
    simple_elem_dzr2.bool_val.not43_o_0 = (~rU)&1;
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    //Or31
    stt_DZR2_Or31__2_1.bool_val.bt0 = R_m_dv_po_dzr2.bool_val.or16_o_0;
    rU = stt_DZR2_And33__3_1.bool_val.bt7;
    stt_DZR2_Or31__2_1.bool_val.bt1 = rU;
    if((stt_DZR2_Or31__2_1.U8V &3) != 0)
        stt_DZR2_Or31__2_1.bool_val.bt7 = 1;
    //Not42     
    simple_elem_dzr2.bool_val.not42_o_0 = (~rU)&1;
    //Or32
    stt_DZR2_Or32__2_1.bool_val.bt0 = R_m_dv_po_dzr2.bool_val.not04_o_0;
    rU = stt_DZR2_And34__3_1.bool_val.bt7;
    stt_DZR2_Or32__2_1.bool_val.bt1 = rU; 
    if((stt_DZR2_Or32__2_1.U8V &3) != 0)
        stt_DZR2_Or32__2_1.bool_val.bt7 = 1;
    //Not41 
    simple_elem_dzr2.bool_val.not41_o_0 = (~rU)&1;
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    //And29 
    stt_DZR2_And29__3_1.bool_val.bt0 = simple_elem_dzr2.bool_val.not43_o_0;
    stt_DZR2_And29__3_1.bool_val.bt1 = stt_DZR2_Or27__2_1.bool_val.bt7;
    stt_DZR2_And29__3_1.bool_val.bt2 = stt_DZR2_And25__5_1.bool_val.bt7;
    if((stt_DZR2_And29__3_1.U8V &7) == 7)
        stt_DZR2_And29__3_1.bool_val.bt7 = 1;
    else
        stt_DZR2_And29__3_1.bool_val.bt7 = 0;
    //And30 
    stt_DZR2_And30__3_1.bool_val.bt0 = stt_DZR2_And25__5_1.bool_val.bt7;
    stt_DZR2_And30__3_1.bool_val.bt1 = simple_elem_dzr2.bool_val.not44_o_0;
    stt_DZR2_And30__3_1.bool_val.bt2 = stt_DZR2_Or28__2_1.bool_val.bt7;
    if((stt_DZR2_And30__3_1.U8V &7) == 7)
        stt_DZR2_And30__3_1.bool_val.bt7 = 1;
    else
        stt_DZR2_And30__3_1.bool_val.bt7 = 0;
    //And33 
    stt_DZR2_And33__3_1.bool_val.bt0 = stt_DZR2_Or31__2_1.bool_val.bt7;
    stt_DZR2_And33__3_1.bool_val.bt1 = simple_elem_dzr2.bool_val.not41_o_0;
    stt_DZR2_And33__3_1.bool_val.bt2 = stt_DZR2_And45__5_1.bool_val.bt7;
    if((stt_DZR2_And33__3_1.U8V &7) == 7)
        stt_DZR2_And33__3_1.bool_val.bt7 = 1;
    else
        stt_DZR2_And33__3_1.bool_val.bt7 = 0;
    //And34
    stt_DZR2_And34__3_1.bool_val.bt0 = stt_DZR2_And45__5_1.bool_val.bt7;
    stt_DZR2_And34__3_1.bool_val.bt1 = simple_elem_dzr2.bool_val.not42_o_0;
    stt_DZR2_And34__3_1.bool_val.bt2 = stt_DZR2_Or32__2_1.bool_val.bt7;
    if((stt_DZR2_And34__3_1.U8V &7) == 7)
        stt_DZR2_And34__3_1.bool_val.bt7 = 1;
    else
        stt_DZR2_And34__3_1.bool_val.bt7 = 0;
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    //Or35
    stt_DZR2_Or35__2_1.bool_val.bt0 = R_m_dv_po_dzr2.bool_val.or17_o_0;
    rU = stt_DZR2_And37__3_1.bool_val.bt7;
    stt_DZR2_Or35__2_1.bool_val.bt1 = rU;
    if((stt_DZR2_Or35__2_1.U8V &3) != 0)
        stt_DZR2_Or35__2_1.bool_val.bt7 = 1;
    //Not40     
    simple_elem_dzr2.bool_val.not40_o_0 = (~rU)&1;
    //Or36
    stt_DZR2_Or36__2_1.bool_val.bt0 = R_m_dv_po_dzr2.bool_val.not05_o_0;
    rU = stt_DZR2_And38__3_1.bool_val.bt7;
    stt_DZR2_Or36__2_1.bool_val.bt1 = rU;
    if((stt_DZR2_Or36__2_1.U8V &3) != 0)
        stt_DZR2_Or36__2_1.bool_val.bt7 = 1;
    //Not39     
    simple_elem_dzr2.bool_val.not39_o_0 = (~rU)&1;
    //And37
    stt_DZR2_And37__3_1.bool_val.bt0 = stt_DZR2_Or35__2_1.bool_val.bt7;
    stt_DZR2_And37__3_1.bool_val.bt1 = simple_elem_dzr2.bool_val.not39_o_0;
    stt_DZR2_And37__3_1.bool_val.bt2 = stt_DZR2_And26__6_1.bool_val.bt7;
    if((stt_DZR2_And37__3_1.U8V &7) == 7)
        stt_DZR2_And37__3_1.bool_val.bt7 = 1;
    else
        stt_DZR2_And37__3_1.bool_val.bt7 = 0;
    //And38
    stt_DZR2_And38__3_1.bool_val.bt0 = stt_DZR2_And26__6_1.bool_val.bt7;
    stt_DZR2_And38__3_1.bool_val.bt1 = simple_elem_dzr2.bool_val.not40_o_0;
    stt_DZR2_And38__3_1.bool_val.bt2 = stt_DZR2_Or36__2_1.bool_val.bt7;
    if((stt_DZR2_And38__3_1.U8V &7) == 7)
        stt_DZR2_And38__3_1.bool_val.bt7 = 1;
    else
        stt_DZR2_And38__3_1.bool_val.bt7 = 0;

    
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
        
        unsigned long u32_bit_holder = 0;
        if(stt_DZR2_And29__3_1.bool_val.bt7 == 1)
            u32_bit_holder |= 1<< IDX_TIMER_IN_DZR23_DIR;
        _TIMER_T_0(INDEX_TIMER_DZR2_DIR,sLV.p_current_settings_prt->timeout_dzr2_dir[number_group_stp],
            u32_bit_holder,IDX_TIMER_IN_DZR23_DIR, u32_bit_holder, IDX_TIMER_OUT_DZR23_DIR);
        if(stt_DZR2_And30__3_1.bool_val.bt7 == 1)
            u32_bit_holder |= 1<< IDX_TIMER_IN_DZR23_DIR_PR;
        _TIMER_T_0(INDEX_TIMER_DZR2_DIR_PR,sLV.p_current_settings_prt->timeout_dzr2_dir_pr[number_group_stp],
            u32_bit_holder,IDX_TIMER_IN_DZR23_DIR_PR, u32_bit_holder, IDX_TIMER_OUT_DZR23_DIR_PR);
        if(stt_DZR2_And33__3_1.bool_val.bt7 == 1)
            u32_bit_holder |= 1<< IDX_TIMER_IN_DZR23_INV;
        _TIMER_T_0(INDEX_TIMER_DZR2_INV,sLV.p_current_settings_prt->timeout_dzr2_inv[number_group_stp],
            u32_bit_holder,IDX_TIMER_IN_DZR23_INV, u32_bit_holder, IDX_TIMER_OUT_DZR23_INV);
        if(stt_DZR2_And34__3_1.bool_val.bt7 == 1)
            u32_bit_holder |= 1<< IDX_TIMER_IN_DZR23_INV_PR;
        _TIMER_T_0(INDEX_TIMER_DZR2_INV_PR,sLV.p_current_settings_prt->timeout_dzr2_inv_pr[number_group_stp],
            u32_bit_holder,IDX_TIMER_IN_DZR23_INV_PR, u32_bit_holder, IDX_TIMER_OUT_DZR23_INV_PR);
        if(stt_DZR2_And37__3_1.bool_val.bt7 == 1)
            u32_bit_holder |= 1<< IDX_TIMER_IN_DZR23_AMTZ;
        _TIMER_T_0(INDEX_TIMER_DZR2_AMTZ,sLV.p_current_settings_prt->timeout_dzr2_amtz[number_group_stp],
            u32_bit_holder,IDX_TIMER_IN_DZR23_AMTZ, u32_bit_holder, IDX_TIMER_OUT_DZR23_AMTZ);
        if(stt_DZR2_And38__3_1.bool_val.bt7 == 1)
            u32_bit_holder |= 1<< IDX_TIMER_IN_DZR23_AMTZ_PR;
        _TIMER_T_0(INDEX_TIMER_DZR2_AMTZ_PR,sLV.p_current_settings_prt->timeout_dzr2_amtz_pr[number_group_stp],   
            u32_bit_holder,IDX_TIMER_IN_DZR23_AMTZ_PR, u32_bit_holder, IDX_TIMER_OUT_DZR23_AMTZ_PR);
        
        if(u32_bit_holder&( (1<<IDX_TIMER_OUT_DZR23_DIR)|(1<<IDX_TIMER_OUT_DZR23_DIR_PR)
        |(1<<IDX_TIMER_OUT_DZR23_INV)|(1<<IDX_TIMER_OUT_DZR23_INV_PR)
        |(1<<IDX_TIMER_OUT_DZR23_AMTZ)|(1<<IDX_TIMER_OUT_DZR23_AMTZ_PR) )){
            _SET_BIT(p_active_functions, RNG_BIG_DZR2);
        }else{
            _CLEAR_BIT(p_active_functions, RNG_BIG_DZR2);
            } 
    
    }
    else{
        
    
        //Or27
    stt_DZR2_Or27__2_1.bool_val.bt0 = R_m_dv_po_dzr2.bool_val.or16_o_0;
    rU = stt_DZR3_And29__3_1.bool_val.bt7;
    stt_DZR2_Or27__2_1.bool_val.bt1 = rU;
    if((stt_DZR2_Or27__2_1.U8V &3) != 0)
        stt_DZR2_Or27__2_1.bool_val.bt7 = 1;
    //Not44     
    simple_elem_dzr2.bool_val.not44_o_0 = (~rU)&1;
    //Or28
    stt_DZR2_Or28__2_1.bool_val.bt0 = R_m_dv_po_dzr2.bool_val.not04_o_0;
    rU = stt_DZR3_And30__3_1.bool_val.bt7;
    stt_DZR2_Or28__2_1.bool_val.bt1 = rU; 
    if((stt_DZR2_Or28__2_1.U8V &3) != 0)
        stt_DZR2_Or28__2_1.bool_val.bt7 = 1;
    //Not43 
    simple_elem_dzr2.bool_val.not43_o_0 = (~rU)&1;
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    //Or31
    stt_DZR2_Or31__2_1.bool_val.bt0 = R_m_dv_po_dzr2.bool_val.or16_o_0;
    rU = stt_DZR3_And33__3_1.bool_val.bt7;
    stt_DZR2_Or31__2_1.bool_val.bt1 = rU;
    if((stt_DZR2_Or31__2_1.U8V &3) != 0)
        stt_DZR2_Or31__2_1.bool_val.bt7 = 1;
    //Not42     
    simple_elem_dzr2.bool_val.not42_o_0 = (~rU)&1;
    //Or32
    stt_DZR2_Or32__2_1.bool_val.bt0 = R_m_dv_po_dzr2.bool_val.not04_o_0;
    rU = stt_DZR3_And34__3_1.bool_val.bt7;
    stt_DZR2_Or32__2_1.bool_val.bt1 = rU; 
    if((stt_DZR2_Or32__2_1.U8V &3) != 0)
        stt_DZR2_Or32__2_1.bool_val.bt7 = 1;
    //Not41 
    simple_elem_dzr2.bool_val.not41_o_0 = (~rU)&1;
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    //And29 
    stt_DZR3_And29__3_1.bool_val.bt0 = simple_elem_dzr2.bool_val.not43_o_0;
    stt_DZR3_And29__3_1.bool_val.bt1 = stt_DZR2_Or27__2_1.bool_val.bt7;
    stt_DZR3_And29__3_1.bool_val.bt2 = stt_DZR2_And25__5_1.bool_val.bt7;
    if((stt_DZR3_And29__3_1.U8V &7) == 7)
        stt_DZR3_And29__3_1.bool_val.bt7 = 1;
    else
        stt_DZR3_And29__3_1.bool_val.bt7 = 0;
    //And30 
    stt_DZR3_And30__3_1.bool_val.bt0 = stt_DZR2_And25__5_1.bool_val.bt7;
    stt_DZR3_And30__3_1.bool_val.bt1 = simple_elem_dzr2.bool_val.not44_o_0;
    stt_DZR3_And30__3_1.bool_val.bt2 = stt_DZR2_Or28__2_1.bool_val.bt7;
    if((stt_DZR3_And30__3_1.U8V &7) == 7)
        stt_DZR3_And30__3_1.bool_val.bt7 = 1;
    else
        stt_DZR3_And30__3_1.bool_val.bt7 = 0;
    //And33 
    stt_DZR3_And33__3_1.bool_val.bt0 = stt_DZR2_Or31__2_1.bool_val.bt7;
    stt_DZR3_And33__3_1.bool_val.bt1 = simple_elem_dzr2.bool_val.not41_o_0;
    stt_DZR3_And33__3_1.bool_val.bt2 = stt_DZR2_And45__5_1.bool_val.bt7;
    if((stt_DZR3_And33__3_1.U8V &7) == 7)
        stt_DZR3_And33__3_1.bool_val.bt7 = 1;
    else
        stt_DZR3_And33__3_1.bool_val.bt7 = 0;
    //And34
    stt_DZR3_And34__3_1.bool_val.bt0 = stt_DZR2_And45__5_1.bool_val.bt7;
    stt_DZR3_And34__3_1.bool_val.bt1 = simple_elem_dzr2.bool_val.not42_o_0;
    stt_DZR3_And34__3_1.bool_val.bt2 = stt_DZR2_Or32__2_1.bool_val.bt7;
    if((stt_DZR3_And34__3_1.U8V &7) == 7)
        stt_DZR3_And34__3_1.bool_val.bt7 = 1;
    else
        stt_DZR3_And34__3_1.bool_val.bt7 = 0;
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    //Or35
    stt_DZR2_Or35__2_1.bool_val.bt0 = R_m_dv_po_dzr2.bool_val.or17_o_0;
    rU = stt_DZR3_And37__3_1.bool_val.bt7;
    stt_DZR2_Or35__2_1.bool_val.bt1 = rU;
    if((stt_DZR2_Or35__2_1.U8V &3) != 0)
        stt_DZR2_Or35__2_1.bool_val.bt7 = 1;
    //Not40     
    simple_elem_dzr2.bool_val.not40_o_0 = (~rU)&1;
    //Or36
    stt_DZR2_Or36__2_1.bool_val.bt0 = R_m_dv_po_dzr2.bool_val.not05_o_0;
    rU = stt_DZR3_And38__3_1.bool_val.bt7;
    stt_DZR2_Or36__2_1.bool_val.bt1 = rU;
    if((stt_DZR2_Or36__2_1.U8V &3) != 0)
        stt_DZR2_Or36__2_1.bool_val.bt7 = 1;
    //Not39     
    simple_elem_dzr2.bool_val.not39_o_0 = (~rU)&1;
    //And37
    stt_DZR3_And37__3_1.bool_val.bt0 = stt_DZR2_Or35__2_1.bool_val.bt7;
    stt_DZR3_And37__3_1.bool_val.bt1 = simple_elem_dzr2.bool_val.not39_o_0;
    stt_DZR3_And37__3_1.bool_val.bt2 = stt_DZR2_And26__6_1.bool_val.bt7;
    if((stt_DZR3_And37__3_1.U8V &7) == 7)
        stt_DZR3_And37__3_1.bool_val.bt7 = 1;
    else
        stt_DZR3_And37__3_1.bool_val.bt7 = 0;
    //And38
    stt_DZR3_And38__3_1.bool_val.bt0 = stt_DZR2_And26__6_1.bool_val.bt7;
    stt_DZR3_And38__3_1.bool_val.bt1 = simple_elem_dzr2.bool_val.not40_o_0;
    stt_DZR3_And38__3_1.bool_val.bt2 = stt_DZR2_Or36__2_1.bool_val.bt7;
    if((stt_DZR3_And38__3_1.U8V &7) == 7)
        stt_DZR3_And38__3_1.bool_val.bt7 = 1;
    else
        stt_DZR3_And38__3_1.bool_val.bt7 = 0;

    
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
   
        unsigned long u32_bit_holder = 0;
        //ID_DZR3
        if(stt_DZR3_And29__3_1.bool_val.bt7 == 1)
            u32_bit_holder |= 1<< IDX_TIMER_IN_DZR23_DIR;
        _TIMER_T_0(INDEX_TIMER_DZR3_DIR,sLV.p_current_settings_prt->timeout_dzr3_dir[number_group_stp],
            u32_bit_holder,IDX_TIMER_IN_DZR23_DIR, u32_bit_holder, IDX_TIMER_OUT_DZR23_DIR);
        if(stt_DZR3_And30__3_1.bool_val.bt7 == 1)
            u32_bit_holder |= 1<< IDX_TIMER_IN_DZR23_DIR_PR;
        _TIMER_T_0(INDEX_TIMER_DZR3_DIR_PR,sLV.p_current_settings_prt->timeout_dzr3_dir_pr[number_group_stp],
            u32_bit_holder,IDX_TIMER_IN_DZR23_DIR_PR, u32_bit_holder, IDX_TIMER_OUT_DZR23_DIR_PR);
        if(stt_DZR3_And33__3_1.bool_val.bt7 == 1)
            u32_bit_holder |= 1<< IDX_TIMER_IN_DZR23_INV;
        _TIMER_T_0(INDEX_TIMER_DZR3_INV,sLV.p_current_settings_prt->timeout_dzr3_inv[number_group_stp],
            u32_bit_holder,IDX_TIMER_IN_DZR23_INV, u32_bit_holder, IDX_TIMER_OUT_DZR23_INV);
        if(stt_DZR3_And34__3_1.bool_val.bt7 == 1)
            u32_bit_holder |= 1<< IDX_TIMER_IN_DZR23_INV_PR;
        _TIMER_T_0(INDEX_TIMER_DZR3_INV_PR,sLV.p_current_settings_prt->timeout_dzr3_inv_pr[number_group_stp],
            u32_bit_holder,IDX_TIMER_IN_DZR23_INV_PR, u32_bit_holder, IDX_TIMER_OUT_DZR23_INV_PR);
        if(stt_DZR3_And37__3_1.bool_val.bt7 == 1)
            u32_bit_holder |= 1<< IDX_TIMER_IN_DZR23_AMTZ;
        _TIMER_T_0(INDEX_TIMER_DZR3_AMTZ,sLV.p_current_settings_prt->timeout_dzr3_amtz[number_group_stp],
            u32_bit_holder,IDX_TIMER_IN_DZR23_AMTZ, u32_bit_holder, IDX_TIMER_OUT_DZR23_AMTZ);
        if(stt_DZR3_And38__3_1.bool_val.bt7 == 1)
            u32_bit_holder |= 1<< IDX_TIMER_IN_DZR23_AMTZ_PR;
        _TIMER_T_0(INDEX_TIMER_DZR3_AMTZ_PR,sLV.p_current_settings_prt->timeout_dzr3_amtz_pr[number_group_stp],   
            u32_bit_holder,IDX_TIMER_IN_DZR23_AMTZ_PR, u32_bit_holder, IDX_TIMER_OUT_DZR23_AMTZ_PR);    
                
        if(u32_bit_holder&( (1<<IDX_TIMER_OUT_DZR23_DIR)|(1<<IDX_TIMER_OUT_DZR23_DIR_PR)
        |(1<<IDX_TIMER_OUT_DZR23_INV)|(1<<IDX_TIMER_OUT_DZR23_INV_PR)
        |(1<<IDX_TIMER_OUT_DZR23_AMTZ)|(1<<IDX_TIMER_OUT_DZR23_AMTZ_PR) )){
            _SET_BIT(p_active_functions, RNG_BIG_DZR3);
        }else{
            _CLEAR_BIT(p_active_functions, RNG_BIG_DZR3);
        }   
    }
    
    
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    //(sLV.p_current_settings_prt->control_dzr & (1<< ));simple_elem_dzr2.bool_val.
    

}
//
//--------------------------------------------------------------------------------------------------------

//=====================================================================================================
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//setpoint ->  spt                 
//....................................................................................................
//=====================================================================================================
void dzr1_handler(unsigned int *p_active_functions, unsigned int number_group_stp )
{ 
 unsigned long rU;
 register U32_dzr1_wrp R_m_dv_po_dzr1;
  struct{
      unsigned long po_u_dzr_u_o_less_up_0_25p_un_spt,     po_i_less_ip_0_p_5_spt,
      po_i_o3g_div_i_o1g_dzr_spt,po2_i_blk_dzr_spt,po_amcz_dzr1_spt, po_dzr1_spt;
  __SETTINGS *p_current_settings_prt;
      char ch_and4;
  }sLV;    
    R_m_dv_po_dzr1.U32V = 0;
    U8_state_wrp 
    //stt_DZR1_And10__3_1,stt_DZR1_And09__3_1,stt_DZR1_Or11__4_1 ,
    
    stt_DZR1_And12__2_1,
    stt_DZR1_OrN13__2_1,
    stt_DZR1_OrN14__3_1,
    stt_DZR1_OrN18__2_1,
    stt_DZR1_And15__3_1,
    stt_DZR1_And16__5_1;
    rU = 0;
    
    //stt_DZR1_And10__3_1.U8V = rU;
    //stt_DZR1_Or11__4_1 .U8V = rU;
    stt_DZR1_And12__2_1.U8V = rU;
    stt_DZR1_OrN13__2_1.U8V = rU;
    stt_DZR1_OrN14__3_1.U8V = rU;
    stt_DZR1_OrN18__2_1.U8V = rU;
    stt_DZR1_And15__3_1.U8V = rU;
    stt_DZR1_And16__5_1.U8V = rU;
    
    sLV.p_current_settings_prt = &current_settings_prt ;
    do{
        //U8_state_wrp R_wrp;
        long lV = (sLV.p_current_settings_prt->control_dzr & (1<<INDEX_CTR_FAULT_U_DZR)); 
        R_m_dv_po_dzr1.bool_val.m_fault_u_dzr = lV!=0;
        
        lV = _CHECK_SET_BIT(p_active_functions, RNG_BIG_NKNR); 
        R_m_dv_po_dzr1.bool_val.nknr_rng_big = lV!=0;
        
        if(R_m_dv_po_dzr1.bool_val.m_fault_u_dzr!=0 && R_m_dv_po_dzr1.bool_val.nknr_rng_big!=0)
            R_m_dv_po_dzr1.bool_val.and04_o_0 = 1;
        
        
        lV = _CHECK_SET_BIT(p_active_functions, RNG_BIG_ZVN_NESPR_DZR);
        R_m_dv_po_dzr1.bool_val.dv_zvn_nespr_dzr = lV!=0;
        if(R_m_dv_po_dzr1.bool_val.dv_zvn_nespr_dzr!=0 || R_m_dv_po_dzr1.bool_val.and04_o_0!=0 )
             R_m_dv_po_dzr1.bool_val.or05_o_0 = 1;
        lV = R_m_dv_po_dzr1.bool_val.or05_o_0;
        _TIMER_0_T(INDEX_TIMER_NKN_DZR,sLV.p_current_settings_prt->timeout_nkn_dzr[number_group_stp],
        lV, 0, lV, 1);
            
        R_m_dv_po_dzr1.bool_val.nkn_dzr1 = (lV&0x2)>>1;
        
        
    }while (rU != 0);
    
    if(R_m_dv_po_dzr1.bool_val.nkn_dzr1 != 0)
        _SET_BIT(p_active_functions, RNG_BIG_NKN_DZR);
    else
        _CLEAR_BIT(p_active_functions, RNG_BIG_NKN_DZR);
    
    
    rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_U_DZR_U_RSV_LESS_0_25P_UN);
    if( rU!= 0) {
            sLV.po_u_dzr_u_o_less_up_0_25p_un_spt = (U_LINEAR_NOM*25/10000)
           * U_DOWN / 100;
    }else{
           sLV.po_u_dzr_u_o_less_up_0_25p_un_spt = (U_LINEAR_NOM*25/10000); 
    }
        //
    if(measurement[IM_Ubp] <= sLV.po_u_dzr_u_o_less_up_0_25p_un_spt){
            R_m_dv_po_dzr1.bool_val.u_dzr_u_o_less_up_0_25p_un = 1;
            _SET_BIT(p_active_functions, RNG_BIG_U_DZR_U_RSV_LESS_0_25P_UN);
    }else{
            R_m_dv_po_dzr1.bool_val.u_dzr_u_o_less_up_0_25p_un = 0;
            _CLEAR_BIT(p_active_functions, RNG_BIG_U_DZR_U_RSV_LESS_0_25P_UN);
    }
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_I_BLK_DZR_I_LESS_0_P_5A);
    if( rU!= 0) {
            sLV.po_i_less_ip_0_p_5_spt = 500
         * KOEF_POVERNENNJA_GENERAL_DOWN / 100;
    }else{
           sLV.po_i_less_ip_0_p_5_spt = 500; 
    }
    if(measurement[IM_Ibp] <= sLV.po_i_less_ip_0_p_5_spt){
        R_m_dv_po_dzr1.bool_val.i_less_ip_0_p_5 = 1;
         _SET_BIT(p_active_functions, RNG_BIG_I_BLK_DZR_I_LESS_0_P_5A);
    }
    else{    
        R_m_dv_po_dzr1.bool_val.i_less_ip_0_p_5 = 0;
        _CLEAR_BIT(p_active_functions, RNG_BIG_I_BLK_DZR_I_LESS_0_P_5A);
    }
    
    if(R_m_dv_po_dzr1.bool_val.nkn_dzr1!=0 
    || R_m_dv_po_dzr1.bool_val.u_dzr_u_o_less_up_0_25p_un!=0){
        _SET_BIT(p_active_functions,RNG_BIG_CNKN_DZR);
        R_m_dv_po_dzr1.bool_val.or06_o_0 = 1;
    }
    else{
        _CLEAR_BIT(p_active_functions,RNG_BIG_CNKN_DZR);//or06_o_0 
    }       
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_I_RSV_3G_DIV_1G_DZR);
    if( rU!= 0) {
            sLV.po_i_o3g_div_i_o1g_dzr_spt = sLV.p_current_settings_prt->pickup_dzr_Io3g_Io1g[number_group_stp]
         * KOEF_POVERNENNJA_MTZ_I_UP / 100;
    }else{
           sLV.po_i_o3g_div_i_o1g_dzr_spt = sLV.p_current_settings_prt->pickup_dzr_Io3g_Io1g[number_group_stp]; 
    }
    if(measurement[IM_Ibp] >= sLV.po_i_o3g_div_i_o1g_dzr_spt){
        R_m_dv_po_dzr1.bool_val.i_r3g_div_i_r1g_dzr = 1;
         _SET_BIT(p_active_functions, RNG_BIG_I_RSV_3G_DIV_1G_DZR);
    }
    else{    
        R_m_dv_po_dzr1.bool_val.i_r3g_div_i_r1g_dzr = 0;
        _CLEAR_BIT(p_active_functions, RNG_BIG_I_RSV_3G_DIV_1G_DZR);
    }
    //...........................................................................
    //``````````````````````````````````````````````````````````````````````````` 
    R_m_dv_po_dzr1.bool_val.m_block_dzr1_i_rsv_3g = 
    (sLV.p_current_settings_prt->control_dzr & (1<<INDEX_CTR_BLOCK_DZR1_I_RSV_3G))!=0;
        
    
    rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_ZBR_BLOCK_DZR1_I_R_3G);//RNG_BIG_ZBR_BLOCK_DZR1_I_O_3G
    R_m_dv_po_dzr1.bool_val.dv_zbr_block_dzr1_i_r_3g = rU!=0;
    
    R_m_dv_po_dzr1.bool_val.not02_o_0 = (~rU)&1;
    //and9
    rU = R_m_dv_po_dzr1.U32V &(  (1<<18)| (1<<1)| (1<<11));
    if(rU == (  (1<<18 )| (1<<1 )| (1<<11 ))){
        R_m_dv_po_dzr1.bool_val.and09_o_0 = 1;
        _SET_BIT(p_active_functions,RNG_BIG_BLK_DZR1_I_RSV_3G_DIV_1G_DZR); //RNG_BIG_BLK_DZR1_I_O3G_DIV_I_O1G_DZR
    }else{
        _CLEAR_BIT(p_active_functions,RNG_BIG_BLK_DZR1_I_RSV_3G_DIV_1G_DZR);//RNG_BIG_BLK_DZR1_I_O3G_DIV_I_O1G_DZR
    }
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    //Za_mn,5.24.36 При виведеному з роботи ступені АМСЗ ДЗО
    //Za_bp,розрахунковий опір для цього ступеня повинен визначатись
    //  підстановкою в вираз для розрахунку опору ном напруги (100 В). 
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO2_I_BLK_DZR1);
    if( rU!= 0) {
            sLV.po2_i_blk_dzr_spt = sLV.p_current_settings_prt->pickup_dzr1_blkI[number_group_stp]
         * KOEF_POVERNENNJA_MTZ_I_UP / 100;
    }else{
           sLV.po2_i_blk_dzr_spt = sLV.p_current_settings_prt->pickup_dzr1_blkI[number_group_stp]; 
    }
    if(measurement[IM_Ibp] >= sLV.po2_i_blk_dzr_spt){
        R_m_dv_po_dzr1.bool_val.po2_i_blk_dzr = 1;
         _SET_BIT(p_active_functions, RNG_BIG_PO2_I_BLK_DZR1);
    }
    else{    
        R_m_dv_po_dzr1.bool_val.po2_i_blk_dzr = 0;
        _CLEAR_BIT(p_active_functions, RNG_BIG_PO2_I_BLK_DZR1);
    }
    R_m_dv_po_dzr1.bool_val.m_block_dzr1_i_rsv = 
    (sLV.p_current_settings_prt->control_dzr & (1<<INDEX_CTR_BLOCK_DZR1_I_RSV))!=0;
        
    
    rU = (_CHECK_SET_BIT(p_active_functions, RNG_BIG_BLK_DZR1_I_RSV))!=0;
    R_m_dv_po_dzr1.bool_val.dv_zbr_block_dzr1_i_r = rU;
    
    R_m_dv_po_dzr1.bool_val.not03_o_0 = (~rU)&1;
    //and10
    rU = R_m_dv_po_dzr1.U32V &(  (1<<19)| (1<<2)| (1<<12));
    if(rU == (  (1<<19 )| (1<<2 )| (1<<12 ))){
        R_m_dv_po_dzr1.bool_val.and10_o_0 = 1;
        _SET_BIT(p_active_functions,RNG_BIG_BLK_DZR1_I_RSV); 
    
    }else{
        _CLEAR_BIT(p_active_functions,RNG_BIG_BLK_DZR1_I_RSV);
    }
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_BLOCK_DZR1);//11
    R_m_dv_po_dzr1.bool_val.dv_block_dzr1 = rU!=0;
    //or11
    rU = R_m_dv_po_dzr1.U32V &( (1<<25)|(1<<17)|(1<<26)|(1<<7));
    if( rU!= 0) {
        R_m_dv_po_dzr1.bool_val.or11_o_0 = 1;
        _SET_BIT(p_active_functions,RNG_BIG_BLK_DZR1);
    }else{
        _CLEAR_BIT(p_active_functions,RNG_BIG_BLK_DZR1);
    }       
    //...........................................................................
    
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_AMCZ_DZR1);
    if( rU!= 0) {
            sLV.po_amcz_dzr1_spt = sLV.p_current_settings_prt->pickup_dzr1_amtz[number_group_stp]
         * KOEF_POVERNENNJA_MTZ_I_UP / 100;
    }else{
           sLV.po_amcz_dzr1_spt = sLV.p_current_settings_prt->pickup_dzr1_amtz[number_group_stp]; 
    }
    if(measurement[IM_Ibp] >= sLV.po_amcz_dzr1_spt){
        R_m_dv_po_dzr1.bool_val.po_amcz_dzr1 = 1;
        
    }
    else{    
        R_m_dv_po_dzr1.bool_val.po_amcz_dzr1 = 0;
        
    }
    rU = (sLV.p_current_settings_prt->control_dzr & (1<<INDEX_CTR_DZR1_AMTZ));
    if(rU != 0)
        rU = 1;
    R_m_dv_po_dzr1.bool_val.m_dzr1_amtz = rU;
    R_m_dv_po_dzr1.bool_val.not02_o_0 = (~rU)&1;
    
    
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    //and7
    rU = R_m_dv_po_dzr1.U32V &( (1<<13)|(1<<10));//or06_o_0 not01_o_0
    if(rU == (  (1<<13 )| (1<<10 ))){
        R_m_dv_po_dzr1.bool_val.and07_o_0 = 1;
        //_SET_BIT(p_active_functions,) 
    
    }else{
        //_CLEAR_BIT(p_active_functions,);
    }
    
    //and8
    rU = R_m_dv_po_dzr1.U32V &( (1<<13)|(1<<3));//or06_o_0 i m_dzr1_amtz
    if(rU == (  (1<<13 )| (1<<3 )))
        R_m_dv_po_dzr1.bool_val.and08_o_0 = 1;
    
    
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    
    rU = (_CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_DZR1))!=0;
    R_m_dv_po_dzr1.bool_val.not17_o_0 = (~rU)&1;
    //and12
    stt_DZR1_And12__2_1.bool_val.bt0 = R_m_dv_po_dzr1.bool_val.and08_o_0;
    stt_DZR1_And12__2_1.bool_val.bt1 = R_m_dv_po_dzr1.bool_val.not17_o_0;
    if ((stt_DZR1_And12__2_1.U8V &3) == 3){
        stt_DZR1_OrN14__3_1.bool_val.bt1 = 1;
        //stt_DZR1_And12__2_1.bool_val.bt7 = 1;//debug only
    }
    
    rU = (_CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_AMCZ_DZR1))!=0;
    stt_DZR1_OrN14__3_1.bool_val.bt2 = rU;
    //orN13
    stt_DZR1_OrN13__2_1.bool_val.bt1 = rU;
    stt_DZR1_OrN13__2_1.bool_val.bt0 = R_m_dv_po_dzr1.bool_val.and08_o_0;
    if((stt_DZR1_OrN13__2_1.U8V &3) != 0){
        //stt_DZR1_OrN18__2_1.bool_val.bt1 = 0;//debug only
    }
    else{
        //inv Or
        stt_DZR1_OrN18__2_1.bool_val.bt1 = 1;
        //stt_DZR1_OrN13__2_1.bool_val.bt7 = 1;//debug only
    }   
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    stt_DZR1_OrN14__3_1.bool_val.bt0 = R_m_dv_po_dzr1.bool_val.or11_o_0;
    //stt_DZR1_OrN14__3_1.bool_val.bt1 = stt_DZR1_And12__2_1.bool_val.bt7 
    stt_DZR1_OrN14__3_1.bool_val.bt2 = rU;
    if((stt_DZR1_OrN14__3_1.U8V &7) == 0){
        stt_DZR1_And15__3_1.bool_val.bt2 = 1;//stt_DZR1_OrN14__3_1.bool_val.bt7 = 1;//Debug Only
    }
    stt_DZR1_OrN18__2_1.bool_val.bt0 = R_m_dv_po_dzr1.bool_val.or11_o_0;
    //stt_DZR1_OrN18__2_1.bool_val.bt1 = stt_DZR1_OrN13__2_1.bool_val.bt7//debug only
    if((stt_DZR1_OrN18__2_1.U8V &3) == 0){
        stt_DZR1_And16__5_1.bool_val.bt2 = 1;
    }
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    //and16 
    rU = (sLV.p_current_settings_prt->control_dzr & (1<<INDEX_CTR_DZR1))!=0;//!Error DZR1_ ON!!
    stt_DZR1_And16__5_1.bool_val.bt0 = rU;
    R_m_dv_po_dzr1.bool_val.m_dzr1 = rU;
    stt_DZR1_And16__5_1.bool_val.bt1 = R_m_dv_po_dzr1.bool_val.not17_o_0;
    stt_DZR1_And16__5_1.bool_val.bt3 = R_m_dv_po_dzr1.bool_val.po_amcz_dzr1;
    stt_DZR1_And16__5_1.bool_val.bt4 = R_m_dv_po_dzr1.bool_val.m_dzr1_amtz;
    if((stt_DZR1_And16__5_1.U8V&31) == 31){
        stt_DZR1_And16__5_1.bool_val.bt7 = 1;
        _SET_BIT(p_active_functions,RNG_BIG_PO_AMCZ_DZR1);
    }else{
        _CLEAR_BIT(p_active_functions,RNG_BIG_PO_AMCZ_DZR1);
    }
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    //.bool_val.bt0 = R_m_dv_po_dzr1.bool_val.
    rU = _CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_DZR1);
    if( rU!= 0) {
            sLV.po_dzr1_spt = sLV.p_current_settings_prt->pickup_dzr1[number_group_stp]
         * KOEF_POVERNENNJA_MTZ_I_UP / 100;
    }else{
           sLV.po_dzr1_spt = sLV.p_current_settings_prt->pickup_dzr1[number_group_stp]; 
    }
    if(R_m_dv_po_dzr1.bool_val.and07_o_0 != 0){
        rU = 0; 
        if(resistance[Za_bp]>0 ) 
             rU = resistance[Za_bp];//
    }else{
        rU = 0; 
        if(resistance[Z_bp]>0 ) 
             rU = resistance[Z_bp];
    }
    //!else
    //!    rU = resistance[Z_mn];//!
    if(rU >= sLV.po_dzr1_spt)
        R_m_dv_po_dzr1.bool_val.po_dzr1 = 1;
    
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    stt_DZR1_And15__3_1.bool_val.bt0 = R_m_dv_po_dzr1.bool_val.m_dzr1;
    stt_DZR1_And15__3_1.bool_val.bt1 = R_m_dv_po_dzr1.bool_val.po_dzr1;
    //bt2 = Set Early
    if((stt_DZR1_And15__3_1.U8V&7) == 7){
        _SET_BIT(p_active_functions,RNG_BIG_PO_DZR1);
        stt_DZR1_And15__3_1.bool_val.bt7 = 1;
    }else{
        _CLEAR_BIT(p_active_functions,RNG_BIG_PO_DZR1);
    }
    unsigned long u32_bit_holder = 0;
    if(stt_DZR1_And15__3_1.bool_val.bt7 == 1)
        u32_bit_holder |= 1<< IDX_TIMER_IN_DZR1;
    _TIMER_T_0(INDEX_TIMER_DZR1,sLV.p_current_settings_prt->timeout_dzr1[number_group_stp],
        u32_bit_holder,IDX_TIMER_IN_DZR1, u32_bit_holder, IDX_TIMER_OUT_DZR1);
    if(stt_DZR1_And16__5_1.bool_val.bt7 == 1)
        u32_bit_holder |= 1<< IDX_TIMER_IN_DZR1_AMTZ;
    _TIMER_T_0(INDEX_TIMER_DZR1_AMTZ,sLV.p_current_settings_prt->timeout_dzr1_amtz[number_group_stp],
        u32_bit_holder,IDX_TIMER_IN_DZR1_AMTZ, u32_bit_holder, IDX_TIMER_OUT_DZR1_AMTZ);
        

    
    
}
//
//--------------------------------------------------------------------------------------------------------
