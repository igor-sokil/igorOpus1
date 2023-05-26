#include <string.h> 
#include "const_global.h"
#include "dzo.h"
#include "mtzo.h"

void dzo_handler(unsigned int *p_active_functions, unsigned int number_group_stp );
void dzo1_handler(unsigned int *p_active_functions, unsigned int number_group_stp );
void dzo23_handler(unsigned int *p_active_functions, unsigned int number_group_stp );
void dzo4_handler(unsigned int *p_active_functions, unsigned int number_group_stp );
 char glb_ch_id_dzo = ID_DZO2;
//=====================================================================================================
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//                
//....................................................................................................
//=====================================================================================================

void dzo_handler(unsigned int *p_active_functions, unsigned int number_group_stp ){
    dzo1_handler(p_active_functions,number_group_stp);
    glb_ch_id_dzo = ID_DZO2;
    dzo23_handler(p_active_functions,number_group_stp);
    glb_ch_id_dzo = ID_DZO3;
    dzo23_handler(p_active_functions,number_group_stp);
    dzo4_handler(p_active_functions,number_group_stp);
}
//
//--------------------------------------------------------------------------------------------------------
U8_state_wrp   stt_DZO2_And29__3_1, stt_DZO2_And30__3_1,
               stt_DZO2_And33__3_1,stt_DZO2_And34__3_1,
               stt_DZO2_And37__3_1,stt_DZO2_And38__3_1;
U8_state_wrp   stt_DZO3_And29__3_1,stt_DZO3_And30__3_1,
               stt_DZO3_And33__3_1,stt_DZO3_And34__3_1,
               stt_DZO3_And37__3_1,stt_DZO3_And38__3_1;
    
static unsigned long u32_bit_dzo2_ext = 0, u32_bit_dzo3_ext = 0;
//=====================================================================================================
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//                  
//....................................................................................................
//=====================================================================================================
void dzo23_handler(unsigned int *p_active_functions, unsigned int number_group_stp )
{
 unsigned long rU;
 register U32_dzo23_wrp R_m_dv_po_dzo2;
 U32_dzo23_wrp1 simple_elem_dzo2;
 struct{
    unsigned long po_dzo2_dir_spt,po_dzo2_inv_spt,
    po_dzo2_amcz_spt;
    __SETTINGS *p_current_settings_prt;
    char ch_id_dzo;
  }sLV;    
    R_m_dv_po_dzo2.U32V = 0;
    simple_elem_dzo2.U32V = 0;
    U8_state_wrp //stt_DZO2_
    stt_DZO2_And20__2_1,
    stt_DZO2_And21__2_1,
    stt_DZO2_OrN22__3_1,
    stt_DZO2_OrN23__3_1,
    stt_DZO2_OrN24__2_1,
    stt_DZO2_OrN44__2_1,
    stt_DZO2_And25__5_1,
    stt_DZO2_And45__5_1,
    stt_DZO2_And26__6_1,
    stt_DZO2_Or27__2_1 ,
    
    stt_DZO2_Or28__2_1 ,
    
    stt_DZO2_Or31__2_1 ,
    
    stt_DZO2_Or32__2_1 ,
    
    stt_DZO2_Or35__2_1 ,
    stt_DZO2_Or36__2_1     ;
    rU = 0;
    stt_DZO2_And20__2_1.U8V = rU;
    stt_DZO2_And21__2_1.U8V = rU;
    stt_DZO2_OrN22__3_1.U8V = rU;
    stt_DZO2_OrN23__3_1.U8V = rU;
    stt_DZO2_OrN24__2_1.U8V = rU;
    stt_DZO2_OrN44__2_1.U8V = rU;
    stt_DZO2_And25__5_1.U8V = rU;
    stt_DZO2_And45__5_1.U8V = rU;
    stt_DZO2_And26__6_1.U8V = rU;
    stt_DZO2_Or27__2_1 .U8V = rU;
    //stt_DZO2_And29__3_1.U8V = rU;
    stt_DZO2_Or28__2_1 .U8V = rU;
    //stt_DZO2_And30__3_1.U8V = rU;
    stt_DZO2_Or31__2_1 .U8V = rU;
    //stt_DZO2_And33__3_1.U8V = rU;
    stt_DZO2_Or32__2_1 .U8V = rU;
    //stt_DZO2_And34__3_1.U8V = rU;
    stt_DZO2_Or35__2_1 .U8V = rU;
    //stt_DZO2_And37__3_1.U8V = rU;
    stt_DZO2_Or36__2_1 .U8V = rU;
    //stt_DZO2_And38__3_1.U8V = rU;
    simple_elem_dzo2.U32V =  rU;
    sLV.p_current_settings_prt = &current_settings_prt ;
    sLV.ch_id_dzo = glb_ch_id_dzo;
    do{ 
        //...........................................................................
        //```````````````````````````````````````````````````````````````````````````
        if(sLV.ch_id_dzo == ID_DZO2){
            long lV = (sLV.p_current_settings_prt->control_dzo & (1<<INDEX_CTR_DZO2_CONST_PR));
            R_m_dv_po_dzo2.bool_val.m_dzo2_const_pr = lV!=0;
            
            lV = _CHECK_SET_BIT(p_active_functions, RNG_BIG_BLOCK_PR_DZO2); 
            R_m_dv_po_dzo2.bool_val.dv_blk_usk_dzo2 = lV!=0;
            rU = R_m_dv_po_dzo2.bool_val.dv_blk_usk_dzo2;
            R_m_dv_po_dzo2.bool_val.not01_o_0 = (~rU)&1;
            
            lV = _CHECK_SET_BIT(p_active_functions, RNG_BIG_OP_PR_DZO2); 
            R_m_dv_po_dzo2.bool_val.dv_op_usk_dzo2 = lV!=0;    
            
            lV = (sLV.p_current_settings_prt->control_dzo & (1<<INDEX_CTR_DZO2_PR_VID_VVO));
            R_m_dv_po_dzo2.bool_val.m_dzo2_pr_vid_vvo = lV!=0;
            //or02_o_0
            rU = R_m_dv_po_dzo2.U32V &( (1<<0)|(1<<8));//m_dzo2_const_pr dv_op_usk_dzo2
            if( rU!= 0) 
                R_m_dv_po_dzo2.bool_val.or02_o_0 = 1;
            
        }else{
            //ID_DZO3
            long lV = (sLV.p_current_settings_prt->control_dzo & (1<<INDEX_CTR_DZO3_CONST_PR));
            R_m_dv_po_dzo2.bool_val.m_dzo2_const_pr = lV!=0;
            
            lV = _CHECK_SET_BIT(p_active_functions, RNG_BIG_BLOCK_PR_DZO3); 
            R_m_dv_po_dzo2.bool_val.dv_blk_usk_dzo2 = lV!=0;
            rU = R_m_dv_po_dzo2.bool_val.dv_blk_usk_dzo2;
            R_m_dv_po_dzo2.bool_val.not01_o_0 = (~rU)&1;
            
            lV = _CHECK_SET_BIT(p_active_functions, RNG_BIG_OP_PR_DZO3); 
            R_m_dv_po_dzo2.bool_val.dv_op_usk_dzo2 = lV!=0;    
            
            lV = (sLV.p_current_settings_prt->control_dzo & (1<<INDEX_CTR_DZO3_PR_VID_VVO));
            R_m_dv_po_dzo2.bool_val.m_dzo2_pr_vid_vvo = lV!=0;
            //or02_o_0
            rU = R_m_dv_po_dzo2.U32V &( (1<<0)|(1<<8));//m_dzo2_const_pr dv_op_usk_dzo2
            if( rU!= 0) 
                R_m_dv_po_dzo2.bool_val.or02_o_0 = 1;
            
        }
        //...........................................................................
        //```````````````````````````````````````````````````````````````````````````
        register long lV = _CHECK_SET_BIT(p_active_functions, RNG_BIG_STATE_VVO);
        //```````````````````````````````````````````````````````````
        unsigned long u32_bit_holder = 0;rU = 0;
        if(sLV.ch_id_dzo == ID_DZO2){
             
            if(lV!=0 && R_m_dv_po_dzo2.bool_val.m_dzo2_pr_vid_vvo==1)
                u32_bit_holder |= (1<< IDX_TIMER_IN_DZO23_VVID_PR )|(1<<IDX_TIMER_IN_DZO23_AMTZ_VVID_PR);

            _TIMER_IMPULSE(INDEX_TIMER_DZO2_VVID_PR,
            sLV.p_current_settings_prt->timeout_dzo2_vvid_pr[number_group_stp],
            u32_bit_dzo2_ext, IDX_TIMER_IN_DZO23_VVID_PR ,u32_bit_holder, 
            IDX_TIMER_IN_DZO23_VVID_PR , u32_bit_holder, IDX_TIMER_OUT_DZO23_VVID_PR);
            _TIMER_IMPULSE(INDEX_TIMER_DZO2_AMTZ_VVID_PR,
            sLV.p_current_settings_prt->timeout_dzo2_amtz_vvid_pr[number_group_stp],
            u32_bit_dzo2_ext,IDX_TIMER_IN_DZO23_AMTZ_VVID_PR ,u32_bit_holder,
            IDX_TIMER_IN_DZO23_AMTZ_VVID_PR, u32_bit_holder, IDX_TIMER_OUT_DZO23_AMTZ_VVID_PR);
            
            
        }else{
            //ID_DZO3
            if(lV!=0 && R_m_dv_po_dzo2.bool_val.m_dzo2_pr_vid_vvo==1)
                u32_bit_holder |= (1<< IDX_TIMER_IN_DZO23_VVID_PR )|(1<<IDX_TIMER_IN_DZO23_AMTZ_VVID_PR);

            _TIMER_IMPULSE(INDEX_TIMER_DZO3_VVID_PR,
            sLV.p_current_settings_prt->timeout_dzo3_vvid_pr[number_group_stp],
            u32_bit_dzo3_ext, IDX_TIMER_IN_DZO23_VVID_PR ,u32_bit_holder, 
            IDX_TIMER_IN_DZO23_VVID_PR , u32_bit_holder, IDX_TIMER_OUT_DZO23_VVID_PR);
            _TIMER_IMPULSE(INDEX_TIMER_DZO3_AMTZ_VVID_PR,
            sLV.p_current_settings_prt->timeout_dzo3_amtz_vvid_pr[number_group_stp],
            u32_bit_dzo3_ext,IDX_TIMER_IN_DZO23_AMTZ_VVID_PR ,u32_bit_holder,
            IDX_TIMER_IN_DZO23_AMTZ_VVID_PR, u32_bit_holder, IDX_TIMER_OUT_DZO23_AMTZ_VVID_PR);
            
        }
        //and6
            if ( u32_bit_holder&(1<<IDX_TIMER_OUT_DZO23_VVID_PR ) )
                R_m_dv_po_dzo2.bool_val.T_vv_usk_dzo23 = 1;
            //and5
            if ( u32_bit_holder&(1<<IDX_TIMER_OUT_DZO23_AMTZ_VVID_PR ) )
                R_m_dv_po_dzo2.bool_val.T_vv_usk_amtzo23 = 1;
        
        
    
    }while (rU != 0);    
    
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    //and13
    rU = R_m_dv_po_dzo2.U32V &( (1<<16)|(1<<17));// not01_o_0 or02_o_0
    if(rU == ( (1<<16)|(1<<17)) )
        R_m_dv_po_dzo2.bool_val.and13_o_0 = 1;
    //and14
    rU = R_m_dv_po_dzo2.U32V &( (1<<16)|(1<<22));//not01_o_0 T_vv_usk_dzo23
    if(rU == ( (1<<16)|(1<<22 )) )
        R_m_dv_po_dzo2.bool_val.and14_o_0 = 1; 
    //and15
    rU = R_m_dv_po_dzo2.U32V &( (1<<16)|(1<<23));//not01_o_0 T_vv_usk_amtzo23 
    if(rU == ( (1<<16 )|(1<<23 )))
        R_m_dv_po_dzo2.bool_val.and15_o_0 = 1; 
    //or16
    rU = R_m_dv_po_dzo2.U32V &( (1<<24)|(1<<25));
    if( rU!= 0) 
        R_m_dv_po_dzo2.bool_val.or16_o_0 = 1;
    //not4
    rU = R_m_dv_po_dzo2.bool_val.or16_o_0;
    R_m_dv_po_dzo2.bool_val.not04_o_0 = (~rU)&1;
    //or17
    rU = R_m_dv_po_dzo2.U32V &( (1<<25)|(1<<26));
    if( rU!= 0) 
        R_m_dv_po_dzo2.bool_val.or17_o_0 = 1;
    //not5
    rU = R_m_dv_po_dzo2.bool_val.or17_o_0;
    R_m_dv_po_dzo2.bool_val.not05_o_0 = (~rU)&1;
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_I_O3G_DIV_I_O1G_DZO);
    simple_elem_dzo2.bool_val.cmd_i_o3g_div_i_o1g_dzo = rU!=0;
    if(sLV.ch_id_dzo == ID_DZO2){
        long lV =  (sLV.p_current_settings_prt->control_dzo & (1<< INDEX_CTR_BLOCK_DZO2_I_OSN_3G));
        simple_elem_dzo2.bool_val.m_block_dzo2_i_osn_3g = lV!=0;
        lV = _CHECK_SET_BIT(p_active_functions,RNG_BIG_ZBR_BLOCK_DZO2_I_O_3G);
        simple_elem_dzo2.bool_val.dv_zbr_blk_dzo2_i_o_3g = lV!=0;
        rU = simple_elem_dzo2.bool_val.dv_zbr_blk_dzo2_i_o_3g;
        simple_elem_dzo2.bool_val.not08_o_0 = (~rU)&1;
    }else{
        //ID_DZO3
        long lV =  (sLV.p_current_settings_prt->control_dzo & (1<< INDEX_CTR_BLOCK_DZO3_I_OSN_3G));
        simple_elem_dzo2.bool_val.m_block_dzo2_i_osn_3g = lV!=0;
        lV = _CHECK_SET_BIT(p_active_functions,RNG_BIG_ZBR_BLOCK_DZO3_I_O_3G);
        simple_elem_dzo2.bool_val.dv_zbr_blk_dzo2_i_o_3g = lV!=0;
        rU = simple_elem_dzo2.bool_val.dv_zbr_blk_dzo2_i_o_3g;
        simple_elem_dzo2.bool_val.not08_o_0 = (~rU)&1;
    }
     //and46
    rU = simple_elem_dzo2.U32V &( (1<<17)|(1<<16)|(1<<8) );//cmd_i_o3g_div_i_o1g_dzo  m_block_dzo2_i_osn_3g not08_o_0
    if( rU == ( (1<<17)|(1<<16)|(1<<8) )  ){
        simple_elem_dzo2.bool_val.and46_o_0 = 1;
        if(sLV.ch_id_dzo == ID_DZO2){
            _SET_BIT(p_active_functions,RNG_BIG_BLK_DZO2_I_OSN_3G_DIV_1G);
        }else{
            //ID_DZO3
            _SET_BIT(p_active_functions,RNG_BIG_BLK_DZO3_I_OSN_3G_DIV_1G);
        }
         
    }else{
        if(sLV.ch_id_dzo == ID_DZO2){
            _CLEAR_BIT(p_active_functions,RNG_BIG_BLK_DZO2_I_OSN_3G_DIV_1G);
        }else{
            //ID_DZO3
            _CLEAR_BIT(p_active_functions,RNG_BIG_BLK_DZO3_I_OSN_3G_DIV_1G);
        }
        
    }
    
    
    rU = _CHECK_SET_BIT(p_active_functions,RNG_BIG_I_BLK_DZO_I_LESS_IP_0_P_5 );//RNG_BIG_PO2_I_BLK_DZO
    simple_elem_dzo2.bool_val.cmd_po2_i_blk_dzo = rU!=0;
    if(sLV.ch_id_dzo == ID_DZO2){
        rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_BLOCK_DZO2);
        simple_elem_dzo2.bool_val.dv_blk_dzo2 = rU!=0;
    }else{
            //ID_DZO3
        rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_BLOCK_DZO3);
        simple_elem_dzo2.bool_val.dv_blk_dzo2 = rU!=0;     
        }
    
    
    //and47
    rU = simple_elem_dzo2.U32V &( (1<<12)|(1<<14)|(1<<13) );//and46_o_0 po2_i_blk_dzo dv_blk_dzo2 
    if( rU != 0  ){
        simple_elem_dzo2.bool_val.or47_o_0 = 1;
        if(sLV.ch_id_dzo == ID_DZO2){
            _SET_BIT(p_active_functions,RNG_BIG_BLK_DZO2);
        }else{
            //ID_DZO3
            _SET_BIT(p_active_functions,RNG_BIG_BLK_DZO3);
        }
         
    }else{
        if(sLV.ch_id_dzo == ID_DZO2){
            _CLEAR_BIT(p_active_functions,RNG_BIG_BLK_DZO2);
        }else{
            //ID_DZO3
            _CLEAR_BIT(p_active_functions,RNG_BIG_BLK_DZO3);
        }
        
    }
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    if(sLV.ch_id_dzo == ID_DZO2){
        rU = (sLV.p_current_settings_prt->control_dzo & (1<<INDEX_CTR_DZO2_AMTZ ));
        R_m_dv_po_dzo2.bool_val.m_dzo2_amtz = rU!=0;
        //...........................................
        //```````````````````````````````````````````
        rU = _CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_AMCZ_DZO2);
        if( rU!= 0) {
                sLV.po_dzo2_amcz_spt = sLV.p_current_settings_prt->pickup_dzo2_amtz[number_group_stp]
         * KOEF_POVERNENNJA_MTZ_I_UP / 100;
        }else{
            sLV.po_dzo2_amcz_spt = sLV.p_current_settings_prt->pickup_dzo2_amtz[number_group_stp];
        }
        R_m_dv_po_dzo2.bool_val.po_amcz_dzo2 = rU!=0;
        //...........................................
        //```````````````````````````````````````````
    }else{
        //ID_DZO3
        rU = (sLV.p_current_settings_prt->control_dzo & (1<< INDEX_CTR_DZO3_AMTZ));
        R_m_dv_po_dzo2.bool_val.m_dzo2_amtz = rU!=0;   
        //...........................................
        //```````````````````````````````````````````
        rU = _CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_AMCZ_DZO3);
        if( rU!= 0) {
                sLV.po_dzo2_amcz_spt = sLV.p_current_settings_prt->pickup_dzo3_amtz[number_group_stp]
         * KOEF_POVERNENNJA_MTZ_I_UP / 100;
        }else{
            sLV.po_dzo2_amcz_spt = sLV.p_current_settings_prt->pickup_dzo3_amtz[number_group_stp];
        }
        R_m_dv_po_dzo2.bool_val.po_amcz_dzo2 = rU!=0;//=DZO3_OrN44 ~~
        //...........................................
        //```````````````````````````````````````````
    }
    //-- AMCZ
    if(measurement[IM_Imn] >= sLV.po_dzo2_amcz_spt){
        simple_elem_dzo2.bool_val.po_amcz_dzo23_now = 1;
    }else{    
        simple_elem_dzo2.bool_val.po_amcz_dzo23_now = 0;
    }
    //--
    rU = _CHECK_SET_BIT(p_active_functions,RNG_BIG_CNKN_DZO);
    simple_elem_dzo2.bool_val.cmd_snkn_dzo = rU!=0;
    //--
    rU = R_m_dv_po_dzo2.bool_val.m_dzo2_amtz;
    simple_elem_dzo2.bool_val.m_dzo2_amtz = rU;
    simple_elem_dzo2.bool_val.not09_o_0 = (~rU)&1; 
    //and10
    rU = simple_elem_dzo2.U32V &( (1<<18)|(1<<20) );// cmd_snkn_dzo m_dzo2_amtz
    if(rU == ( (1<<18 )| (1<<20 )))
        R_m_dv_po_dzo2.bool_val.and10_o_0 = 1;
    //and6
    rU = simple_elem_dzo2.U32V &( (1<<18)|(1<<19));//  cmd_snkn_dzo not09_o_0
    if(rU == ( (1<<18 )| (1<<19 )))
    R_m_dv_po_dzo2.bool_val.and06_o_0 = 1;
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
    if(sLV.ch_id_dzo == ID_DZO2){
        if((sector_directional_dz[ID_DZO2][PHASE_MN_INDEX] == SECTOR_DZ_FORWARD)){
            R_m_dv_po_dzo2.bool_val.sector_dir_dzo2 = 1;
            _SET_BIT(p_active_functions, RNG_BIG_SECTOR_DIR_DZO2);
        }else{ 
            R_m_dv_po_dzo2.bool_val.sector_dir_dzo2 = 0;
            _CLEAR_BIT(p_active_functions, RNG_BIG_SECTOR_DIR_DZO2);
        }   
        if(sector_directional_dz[ID_DZO2][PHASE_MN_INDEX] == SECTOR_DZ_BACKWARD){
            R_m_dv_po_dzo2.bool_val.sector_inv_dzo2 = 1;
            _SET_BIT(p_active_functions, RNG_BIG_SECTOR_INV_DZO2);
        }else{
            R_m_dv_po_dzo2.bool_val.sector_inv_dzo2 = 0;
            _CLEAR_BIT(p_active_functions, RNG_BIG_SECTOR_INV_DZO2);
        }   
    }else{
        //ID_DZO3
        if((sector_directional_dz[ID_DZO3][PHASE_MN_INDEX] == SECTOR_DZ_FORWARD)){
            R_m_dv_po_dzo2.bool_val.sector_dir_dzo2 = 1;
            _SET_BIT(p_active_functions, RNG_BIG_SECTOR_DIR_DZO3);
        }else{ 
            R_m_dv_po_dzo2.bool_val.sector_dir_dzo2 = 0;
            _CLEAR_BIT(p_active_functions, RNG_BIG_SECTOR_DIR_DZO3);
        }   
        if(sector_directional_dz[ID_DZO3][PHASE_MN_INDEX] == SECTOR_DZ_BACKWARD){
            R_m_dv_po_dzo2.bool_val.sector_inv_dzo2 = 1;
            _SET_BIT(p_active_functions, RNG_BIG_SECTOR_INV_DZO3);
        }else{
            R_m_dv_po_dzo2.bool_val.sector_inv_dzo2 = 0;
            _CLEAR_BIT(p_active_functions, RNG_BIG_SECTOR_INV_DZO3);
        }   
    }
    if(sLV.ch_id_dzo == ID_DZO2){
        R_m_dv_po_dzo2.bool_val.m_dzo2 = (sLV.p_current_settings_prt->control_dzo & (1<<INDEX_CTR_DZO2 ))!=0;    
    }else{
        //ID_DZO3
        R_m_dv_po_dzo2.bool_val.m_dzo2 = (sLV.p_current_settings_prt->control_dzo & (1<<INDEX_CTR_DZO3 ))!=0;    
    }
    //or12
    rU = R_m_dv_po_dzo2.U32V &( (1<<19)|(1<<11));//and06_o_0 sector_dir_dzo2
    if( rU!= 0) 
        simple_elem_dzo2.bool_val.or12_o_0 = 1;//R_m_dv_po_dzo2.bool_val.or16_o_0 = 1;
    //or11
    rU = R_m_dv_po_dzo2.U32V &( (1<<19)|(1<<12));//and06_o_0 sector_inv_dzo2
    if( rU!= 0) 
        simple_elem_dzo2.bool_val.or11_o_0 = 1;//R_m_dv_po_dzo2.bool_val.or16_o_0 = 1;
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    //not18
    if(sLV.ch_id_dzo == ID_DZO2){
        rU = (_CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_DIR_DZO2))!=0; 
        simple_elem_dzo2.bool_val.not18_o_0 =  (~rU)&1;
    }else{
        //ID_DZO3
        rU = (_CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_DIR_DZO3))!=0; 
        simple_elem_dzo2.bool_val.not18_o_0 =  (~rU)&1;
    }
    //not19
    if(sLV.ch_id_dzo == ID_DZO2){
        rU = (_CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_INV_DZO2))!=0; 
        simple_elem_dzo2.bool_val.not19_o_0 =  (~rU)&1;    
    }else{
        //ID_DZO3
        rU = (_CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_INV_DZO3))!=0; 
        simple_elem_dzo2.bool_val.not19_o_0 =  (~rU)&1;    
    }
    rU = R_m_dv_po_dzo2.bool_val.and10_o_0;
    
    //and20
    stt_DZO2_And20__2_1.bool_val.bt0 = rU;//R_m_dv_po_dzo2.bool_val.and10_o_0;
    stt_DZO2_And20__2_1.bool_val.bt1 = simple_elem_dzo2.bool_val.not18_o_0;
    if ((stt_DZO2_And20__2_1.U8V &3) == 3){
        stt_DZO2_OrN22__3_1.bool_val.bt1 = 1;//stt_DZO2_And20__2_1.bool_val.bt7 = 1;
    }   
    //and21
    stt_DZO2_And21__2_1.bool_val.bt0 = rU;//R_m_dv_po_dzo2.bool_val.and10_o_0;
    stt_DZO2_And21__2_1.bool_val.bt1 = simple_elem_dzo2.bool_val.not19_o_0;
    if ((stt_DZO2_And21__2_1.U8V &3) == 3){
        stt_DZO2_OrN23__3_1.bool_val.bt1 = 1;//stt_DZO2_And20__2_1.bool_val.bt7 = 1;
    }
    //nor44
    stt_DZO2_OrN44__2_1.bool_val.bt0 = rU;//R_m_dv_po_dzo2.bool_val.and10_o_0;
    rU = R_m_dv_po_dzo2.bool_val.po_amcz_dzo2; 
    stt_DZO2_OrN44__2_1.bool_val.bt1 = rU;
    if((stt_DZO2_OrN44__2_1.U8V &3) == 0){
        stt_DZO2_OrN24__2_1.bool_val.bt1 = 1;
    }
    stt_DZO2_OrN23__3_1.bool_val.bt2 = rU;
    stt_DZO2_OrN22__3_1.bool_val.bt2 = rU;
    rU = simple_elem_dzo2.bool_val.or47_o_0;
    stt_DZO2_OrN23__3_1.bool_val.bt0 = rU;
    stt_DZO2_OrN22__3_1.bool_val.bt0 = rU;
    stt_DZO2_OrN24__2_1.bool_val.bt0 = rU;
    //nor22
    if((stt_DZO2_OrN22__3_1.U8V &7) == 0)
        stt_DZO2_And25__5_1.bool_val.bt4 = 1;
    //nor23
    if((stt_DZO2_OrN23__3_1.U8V &7) == 0)
        stt_DZO2_And45__5_1.bool_val.bt4 = 1;
    //nor24
    if((stt_DZO2_OrN24__2_1.U8V &3) == 0)
        stt_DZO2_And26__6_1.bool_val.bt3 = 1;
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    rU = R_m_dv_po_dzo2.bool_val.m_dzo2;
    stt_DZO2_And25__5_1.bool_val.bt0 = rU;
    stt_DZO2_And45__5_1.bool_val.bt0 = rU;
    stt_DZO2_And26__6_1.bool_val.bt0 = rU;
    //and25
    
    if(sLV.ch_id_dzo == ID_DZO2){
        rU = (sLV.p_current_settings_prt->control_dzo & (1<< INDEX_CTR_DZO2_DIR));    
    }else{
        //ID_DZO3
        rU = (sLV.p_current_settings_prt->control_dzo & (1<< INDEX_CTR_DZO3_DIR));    
    }
    stt_DZO2_And25__5_1.bool_val.bt1 = rU!=0;
    
    if(sLV.ch_id_dzo == ID_DZO2){
        rU = _CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_DIR_DZO2);
        if( rU!= 0) {
                sLV.po_dzo2_dir_spt = sLV.p_current_settings_prt->pickup_dzo2_dir[number_group_stp]
            * KOEF_POVERNENNJA_MTZ_I_UP / 100;
        }else{
            sLV.po_dzo2_dir_spt = sLV.p_current_settings_prt->pickup_dzo2_dir[number_group_stp]; 
        }
    }else{
        //ID_DZO3
        rU = _CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_DIR_DZO3);
        if( rU!= 0) {
                sLV.po_dzo2_dir_spt = sLV.p_current_settings_prt->pickup_dzo3_dir[number_group_stp]
            * KOEF_POVERNENNJA_MTZ_I_UP / 100;
        }else{
            sLV.po_dzo2_dir_spt = sLV.p_current_settings_prt->pickup_dzo3_dir[number_group_stp]; 
        }    
    }
    if(R_m_dv_po_dzo2.bool_val.and06_o_0 == 0){
        rU = 0; 
        if(resistance[Z_mn]>0 ) 
             rU = resistance[Z_mn];//
    }else{
        rU = 0; 
        if(resistance[Za_mn]>0 ) 
             rU = resistance[Za_mn];
    }
if(rU >=  sLV.po_dzo2_dir_spt){
        stt_DZO2_And25__5_1.bool_val.bt2 = 1;
    }   
    stt_DZO2_And25__5_1.bool_val.bt3 = simple_elem_dzo2.bool_val.or12_o_0;
    if ((stt_DZO2_And25__5_1.U8V &31) == 31){ 
        stt_DZO2_And25__5_1.bool_val.bt7 = 1;
        if(sLV.ch_id_dzo == ID_DZO2){
            _SET_BIT(p_active_functions,RNG_BIG_PO_DIR_DZO2);
        }else{
        //ID_DZO3
            _SET_BIT(p_active_functions,RNG_BIG_PO_DIR_DZO3);    
        }
        
    }else{
        if(sLV.ch_id_dzo == ID_DZO2){
            _CLEAR_BIT(p_active_functions,RNG_BIG_PO_DIR_DZO2); 
        }else{
        //ID_DZO3
            _CLEAR_BIT(p_active_functions,RNG_BIG_PO_DIR_DZO3); 
        }
    }       
    //and45
    if(sLV.ch_id_dzo == ID_DZO2){
        rU = (sLV.p_current_settings_prt->control_dzo & (1<< INDEX_CTR_DZO2_INV));    
    }else{
        //ID_DZO3
        rU = (sLV.p_current_settings_prt->control_dzo & (1<< INDEX_CTR_DZO3_INV));    
    }
    stt_DZO2_And45__5_1.bool_val.bt1 = rU!=0;
        
    if(sLV.ch_id_dzo == ID_DZO2){
        rU = _CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_INV_DZO2);
        if( rU!= 0) {
                sLV.po_dzo2_inv_spt = sLV.p_current_settings_prt->pickup_dzo2_inv[number_group_stp]
            * KOEF_POVERNENNJA_MTZ_I_UP / 100;
        }else{
            sLV.po_dzo2_inv_spt = sLV.p_current_settings_prt->pickup_dzo2_inv[number_group_stp]; 
        }
    }else{
        //ID_DZO3
        rU = _CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_INV_DZO3);
        if( rU!= 0) {
                sLV.po_dzo2_inv_spt = sLV.p_current_settings_prt->pickup_dzo3_inv[number_group_stp]
            * KOEF_POVERNENNJA_MTZ_I_UP / 100;
        }else{
            sLV.po_dzo2_inv_spt = sLV.p_current_settings_prt->pickup_dzo3_inv[number_group_stp]; 
        }    
    }
    if(R_m_dv_po_dzo2.bool_val.and06_o_0 == 0){
        rU = 0; 
        if(resistance[Z_mn]>0 ) 
             rU = resistance[Z_mn];//
    }else{
        rU = 0; 
        if(resistance[Za_mn]>0 ) 
             rU = resistance[Za_mn];
    }

    if(rU >= sLV.po_dzo2_dir_spt){
        stt_DZO2_And45__5_1.bool_val.bt2 = 1;
    }
    stt_DZO2_And45__5_1.bool_val.bt3 = simple_elem_dzo2.bool_val.or11_o_0;
    if ((stt_DZO2_And45__5_1.U8V &31) == 31){ 
        stt_DZO2_And45__5_1.bool_val.bt7 = 1;
        if(sLV.ch_id_dzo == ID_DZO2){
            _SET_BIT(p_active_functions,RNG_BIG_PO_DIR_DZO2);
        }else{
        //ID_DZO3
            _SET_BIT(p_active_functions,RNG_BIG_PO_DIR_DZO3);    
        }
    }
    else{
        if(sLV.ch_id_dzo == ID_DZO2){
            _CLEAR_BIT(p_active_functions,RNG_BIG_PO_DIR_DZO2); 
        }else{
        //ID_DZO3
            _CLEAR_BIT(p_active_functions,RNG_BIG_PO_DIR_DZO3); 
        }
    }
    //and26
    //stt_DZO2_And26__6_1.bool_val.bt0 == init  R_m_dv_po_dzo2.bool_val.m_dzo2
    stt_DZO2_And26__6_1.bool_val.bt1 = simple_elem_dzo2.bool_val.not18_o_0;
    stt_DZO2_And26__6_1.bool_val.bt2 = simple_elem_dzo2.bool_val.not19_o_0;
    //stt_DZO2_And26__6_1.bool_val.bt3 = init nor24
    stt_DZO2_And26__6_1.bool_val.bt4 = simple_elem_dzo2.bool_val.po_amcz_dzo23_now;
    stt_DZO2_And26__6_1.bool_val.bt5 = simple_elem_dzo2.bool_val.m_dzo2_amtz; 
    if ((stt_DZO2_And26__6_1.U8V &63) == 63){ 
        stt_DZO2_And26__6_1.bool_val.bt7 = 1;
        if(sLV.ch_id_dzo == ID_DZO2){
            _SET_BIT(p_active_functions,RNG_BIG_PO_AMCZ_DZO2);
        }else{
        //ID_DZO3
            _SET_BIT(p_active_functions,RNG_BIG_PO_AMCZ_DZO3);    
        }
    }
    else{
        if(sLV.ch_id_dzo == ID_DZO2){
            _CLEAR_BIT(p_active_functions,RNG_BIG_PO_AMCZ_DZO2); 
        }else{
        //ID_DZO3
            _CLEAR_BIT(p_active_functions,RNG_BIG_PO_AMCZ_DZO3); 
        }
    }
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
 if(sLV.ch_id_dzo == ID_DZO2){
            //Or27
    stt_DZO2_Or27__2_1.bool_val.bt0 = R_m_dv_po_dzo2.bool_val.or16_o_0;
    rU = stt_DZO2_And29__3_1.bool_val.bt7;
    stt_DZO2_Or27__2_1.bool_val.bt1 = rU;
    if((stt_DZO2_Or27__2_1.U8V &3) != 0)
        stt_DZO2_Or27__2_1.bool_val.bt7 = 1;
    //Not44     
    simple_elem_dzo2.bool_val.not44_o_0 = (~rU)&1;
    //Or28
    stt_DZO2_Or28__2_1.bool_val.bt0 = R_m_dv_po_dzo2.bool_val.not04_o_0;
    rU = stt_DZO2_And30__3_1.bool_val.bt7;
    stt_DZO2_Or28__2_1.bool_val.bt1 = rU; 
    if((stt_DZO2_Or28__2_1.U8V &3) != 0)
        stt_DZO2_Or28__2_1.bool_val.bt7 = 1;
    //Not43 
    simple_elem_dzo2.bool_val.not43_o_0 = (~rU)&1;
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    //Or31
    stt_DZO2_Or31__2_1.bool_val.bt0 = R_m_dv_po_dzo2.bool_val.or16_o_0;
    rU = stt_DZO2_And33__3_1.bool_val.bt7;
    stt_DZO2_Or31__2_1.bool_val.bt1 = rU;
    if((stt_DZO2_Or31__2_1.U8V &3) != 0)
        stt_DZO2_Or31__2_1.bool_val.bt7 = 1;
    //Not42     
    simple_elem_dzo2.bool_val.not42_o_0 = (~rU)&1;
    //Or32
    stt_DZO2_Or32__2_1.bool_val.bt0 = R_m_dv_po_dzo2.bool_val.not04_o_0;
    rU = stt_DZO2_And34__3_1.bool_val.bt7;
    stt_DZO2_Or32__2_1.bool_val.bt1 = rU; 
    if((stt_DZO2_Or32__2_1.U8V &3) != 0)
        stt_DZO2_Or32__2_1.bool_val.bt7 = 1;
    //Not41 
    simple_elem_dzo2.bool_val.not41_o_0 = (~rU)&1;
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    //And29 
    stt_DZO2_And29__3_1.bool_val.bt0 = simple_elem_dzo2.bool_val.not43_o_0;
    stt_DZO2_And29__3_1.bool_val.bt1 = stt_DZO2_Or27__2_1.bool_val.bt7;
    stt_DZO2_And29__3_1.bool_val.bt2 = stt_DZO2_And25__5_1.bool_val.bt7;
    if((stt_DZO2_And29__3_1.U8V &7) == 7)
        stt_DZO2_And29__3_1.bool_val.bt7 = 1;
    else
        stt_DZO2_And29__3_1.bool_val.bt7 = 0;
    //And30 
    stt_DZO2_And30__3_1.bool_val.bt0 = stt_DZO2_And25__5_1.bool_val.bt7;
    stt_DZO2_And30__3_1.bool_val.bt1 = simple_elem_dzo2.bool_val.not44_o_0;
    stt_DZO2_And30__3_1.bool_val.bt2 = stt_DZO2_Or28__2_1.bool_val.bt7;
    if((stt_DZO2_And30__3_1.U8V &7) == 7)
        stt_DZO2_And30__3_1.bool_val.bt7 = 1;
    else
        stt_DZO2_And30__3_1.bool_val.bt7 = 0;
    //And33 
    stt_DZO2_And33__3_1.bool_val.bt0 = stt_DZO2_Or31__2_1.bool_val.bt7;
    stt_DZO2_And33__3_1.bool_val.bt1 = simple_elem_dzo2.bool_val.not41_o_0;
    stt_DZO2_And33__3_1.bool_val.bt2 = stt_DZO2_And45__5_1.bool_val.bt7;
    if((stt_DZO2_And33__3_1.U8V &7) == 7)
        stt_DZO2_And33__3_1.bool_val.bt7 = 1;
    else
        stt_DZO2_And33__3_1.bool_val.bt7 = 0;
    //And34
    stt_DZO2_And34__3_1.bool_val.bt0 = stt_DZO2_And45__5_1.bool_val.bt7;
    stt_DZO2_And34__3_1.bool_val.bt1 = simple_elem_dzo2.bool_val.not42_o_0;
    stt_DZO2_And34__3_1.bool_val.bt2 = stt_DZO2_Or32__2_1.bool_val.bt7;
    if((stt_DZO2_And34__3_1.U8V &7) == 7)
        stt_DZO2_And34__3_1.bool_val.bt7 = 1;
    else
        stt_DZO2_And34__3_1.bool_val.bt7 = 0;
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    //Or35
    stt_DZO2_Or35__2_1.bool_val.bt0 = R_m_dv_po_dzo2.bool_val.or17_o_0;
    rU = stt_DZO2_And37__3_1.bool_val.bt7;
    stt_DZO2_Or35__2_1.bool_val.bt1 = rU;
    if((stt_DZO2_Or35__2_1.U8V &3) != 0)
        stt_DZO2_Or35__2_1.bool_val.bt7 = 1;
    //Not40     
    simple_elem_dzo2.bool_val.not40_o_0 = (~rU)&1;
    //Or36
    stt_DZO2_Or36__2_1.bool_val.bt0 = R_m_dv_po_dzo2.bool_val.not05_o_0;
    rU = stt_DZO2_And38__3_1.bool_val.bt7;
    stt_DZO2_Or36__2_1.bool_val.bt1 = rU;
    if((stt_DZO2_Or36__2_1.U8V &3) != 0)
        stt_DZO2_Or36__2_1.bool_val.bt7 = 1;
    //Not39     
    simple_elem_dzo2.bool_val.not39_o_0 = (~rU)&1;
    //And37
    stt_DZO2_And37__3_1.bool_val.bt0 = stt_DZO2_Or35__2_1.bool_val.bt7;
    stt_DZO2_And37__3_1.bool_val.bt1 = simple_elem_dzo2.bool_val.not39_o_0;
    stt_DZO2_And37__3_1.bool_val.bt2 = stt_DZO2_And26__6_1.bool_val.bt7;
    if((stt_DZO2_And37__3_1.U8V &7) == 7)
        stt_DZO2_And37__3_1.bool_val.bt7 = 1;
    else
        stt_DZO2_And37__3_1.bool_val.bt7 = 0;
    //And38
    stt_DZO2_And38__3_1.bool_val.bt0 = stt_DZO2_And26__6_1.bool_val.bt7;
    stt_DZO2_And38__3_1.bool_val.bt1 = simple_elem_dzo2.bool_val.not40_o_0;
    stt_DZO2_And38__3_1.bool_val.bt2 = stt_DZO2_Or36__2_1.bool_val.bt7;
    if((stt_DZO2_And38__3_1.U8V &7) == 7)
        stt_DZO2_And38__3_1.bool_val.bt7 = 1;
    else
        stt_DZO2_And38__3_1.bool_val.bt7 = 0;

    
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
        
        unsigned long u32_bit_holder = 0;
        if(stt_DZO2_And29__3_1.bool_val.bt7 == 1)
            u32_bit_holder |= 1<< IDX_TIMER_IN_DZO23_DIR;
        _TIMER_T_0(INDEX_TIMER_DZO2_DIR,sLV.p_current_settings_prt->timeout_dzo2_dir[number_group_stp],
            u32_bit_holder,IDX_TIMER_IN_DZO23_DIR, u32_bit_holder, IDX_TIMER_OUT_DZO23_DIR);
        if(stt_DZO2_And30__3_1.bool_val.bt7 == 1)
            u32_bit_holder |= 1<< IDX_TIMER_IN_DZO23_DIR_PR;
        _TIMER_T_0(INDEX_TIMER_DZO2_DIR_PR,sLV.p_current_settings_prt->timeout_dzo2_dir_pr[number_group_stp],
            u32_bit_holder,IDX_TIMER_IN_DZO23_DIR_PR, u32_bit_holder, IDX_TIMER_OUT_DZO23_DIR_PR);
        if(stt_DZO2_And33__3_1.bool_val.bt7 == 1)
            u32_bit_holder |= 1<< IDX_TIMER_IN_DZO23_INV;
        _TIMER_T_0(INDEX_TIMER_DZO2_INV,sLV.p_current_settings_prt->timeout_dzo2_inv[number_group_stp],
            u32_bit_holder,IDX_TIMER_IN_DZO23_INV, u32_bit_holder, IDX_TIMER_OUT_DZO23_INV);
        if(stt_DZO2_And34__3_1.bool_val.bt7 == 1)
            u32_bit_holder |= 1<< IDX_TIMER_IN_DZO23_INV_PR;
        _TIMER_T_0(INDEX_TIMER_DZO2_INV_PR,sLV.p_current_settings_prt->timeout_dzo2_inv_pr[number_group_stp],
            u32_bit_holder,IDX_TIMER_IN_DZO23_INV_PR, u32_bit_holder, IDX_TIMER_OUT_DZO23_INV_PR);
        if(stt_DZO2_And37__3_1.bool_val.bt7 == 1)
            u32_bit_holder |= 1<< IDX_TIMER_IN_DZO23_AMTZ;
        _TIMER_T_0(INDEX_TIMER_DZO2_AMTZ,sLV.p_current_settings_prt->timeout_dzo2_amtz[number_group_stp],
            u32_bit_holder,IDX_TIMER_IN_DZO23_AMTZ, u32_bit_holder, IDX_TIMER_OUT_DZO23_AMTZ);
        if(stt_DZO2_And38__3_1.bool_val.bt7 == 1)
            u32_bit_holder |= 1<< IDX_TIMER_IN_DZO23_AMTZ_PR;
        _TIMER_T_0(INDEX_TIMER_DZO2_AMTZ_PR,sLV.p_current_settings_prt->timeout_dzo2_amtz_pr[number_group_stp],   
            u32_bit_holder,IDX_TIMER_IN_DZO23_AMTZ_PR, u32_bit_holder, IDX_TIMER_OUT_DZO23_AMTZ_PR);
        
        if(u32_bit_holder&( (1<<IDX_TIMER_OUT_DZO23_DIR)|(1<<IDX_TIMER_OUT_DZO23_DIR_PR)
        |(1<<IDX_TIMER_OUT_DZO23_INV)|(1<<IDX_TIMER_OUT_DZO23_INV_PR)
        |(1<<IDX_TIMER_OUT_DZO23_AMTZ)|(1<<IDX_TIMER_OUT_DZO23_AMTZ_PR) )){
            _SET_BIT(p_active_functions, RNG_BIG_DZO2);
        }else{
            _CLEAR_BIT(p_active_functions, RNG_BIG_DZO2);
            } 
    
    }
    else{
        
    
        //Or27
    stt_DZO2_Or27__2_1.bool_val.bt0 = R_m_dv_po_dzo2.bool_val.or16_o_0;
    rU = stt_DZO3_And29__3_1.bool_val.bt7;
    stt_DZO2_Or27__2_1.bool_val.bt1 = rU;
    if((stt_DZO2_Or27__2_1.U8V &3) != 0)
        stt_DZO2_Or27__2_1.bool_val.bt7 = 1;
    //Not44     
    simple_elem_dzo2.bool_val.not44_o_0 = (~rU)&1;
    //Or28
    stt_DZO2_Or28__2_1.bool_val.bt0 = R_m_dv_po_dzo2.bool_val.not04_o_0;
    rU = stt_DZO3_And30__3_1.bool_val.bt7;
    stt_DZO2_Or28__2_1.bool_val.bt1 = rU; 
    if((stt_DZO2_Or28__2_1.U8V &3) != 0)
        stt_DZO2_Or28__2_1.bool_val.bt7 = 1;
    //Not43 
    simple_elem_dzo2.bool_val.not43_o_0 = (~rU)&1;
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    //Or31
    stt_DZO2_Or31__2_1.bool_val.bt0 = R_m_dv_po_dzo2.bool_val.or16_o_0;
    rU = stt_DZO3_And33__3_1.bool_val.bt7;
    stt_DZO2_Or31__2_1.bool_val.bt1 = rU;
    if((stt_DZO2_Or31__2_1.U8V &3) != 0)
        stt_DZO2_Or31__2_1.bool_val.bt7 = 1;
    //Not42     
    simple_elem_dzo2.bool_val.not42_o_0 = (~rU)&1;
    //Or32
    stt_DZO2_Or32__2_1.bool_val.bt0 = R_m_dv_po_dzo2.bool_val.not04_o_0;
    rU = stt_DZO3_And34__3_1.bool_val.bt7;
    stt_DZO2_Or32__2_1.bool_val.bt1 = rU; 
    if((stt_DZO2_Or32__2_1.U8V &3) != 0)
        stt_DZO2_Or32__2_1.bool_val.bt7 = 1;
    //Not41 
    simple_elem_dzo2.bool_val.not41_o_0 = (~rU)&1;
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    //And29 
    stt_DZO3_And29__3_1.bool_val.bt0 = simple_elem_dzo2.bool_val.not43_o_0;
    stt_DZO3_And29__3_1.bool_val.bt1 = stt_DZO2_Or27__2_1.bool_val.bt7;
    stt_DZO3_And29__3_1.bool_val.bt2 = stt_DZO2_And25__5_1.bool_val.bt7;
    if((stt_DZO3_And29__3_1.U8V &7) == 7)
        stt_DZO3_And29__3_1.bool_val.bt7 = 1;
    else
        stt_DZO3_And29__3_1.bool_val.bt7 = 0;
    //And30 
    stt_DZO3_And30__3_1.bool_val.bt0 = stt_DZO2_And25__5_1.bool_val.bt7;
    stt_DZO3_And30__3_1.bool_val.bt1 = simple_elem_dzo2.bool_val.not44_o_0;
    stt_DZO3_And30__3_1.bool_val.bt2 = stt_DZO2_Or28__2_1.bool_val.bt7;
    if((stt_DZO3_And30__3_1.U8V &7) == 7)
        stt_DZO3_And30__3_1.bool_val.bt7 = 1;
    else
        stt_DZO3_And30__3_1.bool_val.bt7 = 0;
    //And33 
    stt_DZO3_And33__3_1.bool_val.bt0 = stt_DZO2_Or31__2_1.bool_val.bt7;
    stt_DZO3_And33__3_1.bool_val.bt1 = simple_elem_dzo2.bool_val.not41_o_0;
    stt_DZO3_And33__3_1.bool_val.bt2 = stt_DZO2_And45__5_1.bool_val.bt7;
    if((stt_DZO3_And33__3_1.U8V &7) == 7)
        stt_DZO3_And33__3_1.bool_val.bt7 = 1;
    else
        stt_DZO3_And33__3_1.bool_val.bt7 = 0;
    //And34
    stt_DZO3_And34__3_1.bool_val.bt0 = stt_DZO2_And45__5_1.bool_val.bt7;
    stt_DZO3_And34__3_1.bool_val.bt1 = simple_elem_dzo2.bool_val.not42_o_0;
    stt_DZO3_And34__3_1.bool_val.bt2 = stt_DZO2_Or32__2_1.bool_val.bt7;
    if((stt_DZO3_And34__3_1.U8V &7) == 7)
        stt_DZO3_And34__3_1.bool_val.bt7 = 1;
    else
        stt_DZO3_And34__3_1.bool_val.bt7 = 0;
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    //Or35
    stt_DZO2_Or35__2_1.bool_val.bt0 = R_m_dv_po_dzo2.bool_val.or17_o_0;
    rU = stt_DZO3_And37__3_1.bool_val.bt7;
    stt_DZO2_Or35__2_1.bool_val.bt1 = rU;
    if((stt_DZO2_Or35__2_1.U8V &3) != 0)
        stt_DZO2_Or35__2_1.bool_val.bt7 = 1;
    //Not40     
    simple_elem_dzo2.bool_val.not40_o_0 = (~rU)&1;
    //Or36
    stt_DZO2_Or36__2_1.bool_val.bt0 = R_m_dv_po_dzo2.bool_val.not05_o_0;
    rU = stt_DZO3_And38__3_1.bool_val.bt7;
    stt_DZO2_Or36__2_1.bool_val.bt1 = rU;
    if((stt_DZO2_Or36__2_1.U8V &3) != 0)
        stt_DZO2_Or36__2_1.bool_val.bt7 = 1;
    //Not39     
    simple_elem_dzo2.bool_val.not39_o_0 = (~rU)&1;
    //And37
    stt_DZO3_And37__3_1.bool_val.bt0 = stt_DZO2_Or35__2_1.bool_val.bt7;
    stt_DZO3_And37__3_1.bool_val.bt1 = simple_elem_dzo2.bool_val.not39_o_0;
    stt_DZO3_And37__3_1.bool_val.bt2 = stt_DZO2_And26__6_1.bool_val.bt7;
    if((stt_DZO3_And37__3_1.U8V &7) == 7)
        stt_DZO3_And37__3_1.bool_val.bt7 = 1;
    else
        stt_DZO3_And37__3_1.bool_val.bt7 = 0;
    //And38
    stt_DZO3_And38__3_1.bool_val.bt0 = stt_DZO2_And26__6_1.bool_val.bt7;
    stt_DZO3_And38__3_1.bool_val.bt1 = simple_elem_dzo2.bool_val.not40_o_0;
    stt_DZO3_And38__3_1.bool_val.bt2 = stt_DZO2_Or36__2_1.bool_val.bt7;
    if((stt_DZO3_And38__3_1.U8V &7) == 7)
        stt_DZO3_And38__3_1.bool_val.bt7 = 1;
    else
        stt_DZO3_And38__3_1.bool_val.bt7 = 0;

    
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
   
        unsigned long u32_bit_holder = 0;
        //ID_DZO3
        if(stt_DZO3_And29__3_1.bool_val.bt7 == 1)
            u32_bit_holder |= 1<< IDX_TIMER_IN_DZO23_DIR;
        _TIMER_T_0(INDEX_TIMER_DZO3_DIR,sLV.p_current_settings_prt->timeout_dzo3_dir[number_group_stp],
            u32_bit_holder,IDX_TIMER_IN_DZO23_DIR, u32_bit_holder, IDX_TIMER_OUT_DZO23_DIR);
        if(stt_DZO3_And30__3_1.bool_val.bt7 == 1)
            u32_bit_holder |= 1<< IDX_TIMER_IN_DZO23_DIR_PR;
        _TIMER_T_0(INDEX_TIMER_DZO3_DIR_PR,sLV.p_current_settings_prt->timeout_dzo3_dir_pr[number_group_stp],
            u32_bit_holder,IDX_TIMER_IN_DZO23_DIR_PR, u32_bit_holder, IDX_TIMER_OUT_DZO23_DIR_PR);
        if(stt_DZO3_And33__3_1.bool_val.bt7 == 1)
            u32_bit_holder |= 1<< IDX_TIMER_IN_DZO23_INV;
        _TIMER_T_0(INDEX_TIMER_DZO3_INV,sLV.p_current_settings_prt->timeout_dzo3_inv[number_group_stp],
            u32_bit_holder,IDX_TIMER_IN_DZO23_INV, u32_bit_holder, IDX_TIMER_OUT_DZO23_INV);
        if(stt_DZO3_And34__3_1.bool_val.bt7 == 1)
            u32_bit_holder |= 1<< IDX_TIMER_IN_DZO23_INV_PR;
        _TIMER_T_0(INDEX_TIMER_DZO3_INV_PR,sLV.p_current_settings_prt->timeout_dzo3_inv_pr[number_group_stp],
            u32_bit_holder,IDX_TIMER_IN_DZO23_INV_PR, u32_bit_holder, IDX_TIMER_OUT_DZO23_INV_PR);
        if(stt_DZO3_And37__3_1.bool_val.bt7 == 1)
            u32_bit_holder |= 1<< IDX_TIMER_IN_DZO23_AMTZ;
        _TIMER_T_0(INDEX_TIMER_DZO3_AMTZ,sLV.p_current_settings_prt->timeout_dzo3_amtz[number_group_stp],
            u32_bit_holder,IDX_TIMER_IN_DZO23_AMTZ, u32_bit_holder, IDX_TIMER_OUT_DZO23_AMTZ);
        if(stt_DZO3_And38__3_1.bool_val.bt7 == 1)
            u32_bit_holder |= 1<< IDX_TIMER_IN_DZO23_AMTZ_PR;
        _TIMER_T_0(INDEX_TIMER_DZO3_AMTZ_PR,sLV.p_current_settings_prt->timeout_dzo3_amtz_pr[number_group_stp],   
            u32_bit_holder,IDX_TIMER_IN_DZO23_AMTZ_PR, u32_bit_holder, IDX_TIMER_OUT_DZO23_AMTZ_PR);    
                
        if(u32_bit_holder&( (1<<IDX_TIMER_OUT_DZO23_DIR)|(1<<IDX_TIMER_OUT_DZO23_DIR_PR)
        |(1<<IDX_TIMER_OUT_DZO23_INV)|(1<<IDX_TIMER_OUT_DZO23_INV_PR)
        |(1<<IDX_TIMER_OUT_DZO23_AMTZ)|(1<<IDX_TIMER_OUT_DZO23_AMTZ_PR) )){
            _SET_BIT(p_active_functions, RNG_BIG_DZO3);
        }else{
            _CLEAR_BIT(p_active_functions, RNG_BIG_DZO3);
        }   
    }
    
    
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    //(sLV.p_current_settings_prt->control_dzo & (1<< ));simple_elem_dzo2.bool_val.
    

}
//
//--------------------------------------------------------------------------------------------------------

//=====================================================================================================
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//setpoint ->  spt                 
//....................................................................................................
//=====================================================================================================
void dzo1_handler(unsigned int *p_active_functions, unsigned int number_group_stp )
{ 
 unsigned long rU;
 register U32_dzo1_wrp R_m_dv_po_dzo1;
  struct{
      unsigned long po_u_dzo_u_o_less_up_0_25p_un_spt,     po_i_less_ip_0_p_5_spt,
      po_i_o3g_div_i_o1g_dzo_spt,po2_i_blk_dzo_spt,po_amcz_dzo1_spt, po_dzo1_spt;
  __SETTINGS *p_current_settings_prt;
      char ch_and4;
  }sLV;    
    R_m_dv_po_dzo1.U32V = 0;
    U8_state_wrp 
    //stt_DZO1_And10__3_1,stt_DZO1_And09__3_1,stt_DZO1_Or11__4_1 ,
    
    stt_DZO1_And12__2_1,
    stt_DZO1_OrN13__2_1,
    stt_DZO1_OrN14__3_1,
    stt_DZO1_OrN18__2_1,
    stt_DZO1_And15__3_1,
    stt_DZO1_And16__5_1;
    rU = 0;
    
    //stt_DZO1_And10__3_1.U8V = rU;
    //stt_DZO1_Or11__4_1 .U8V = rU;
    stt_DZO1_And12__2_1.U8V = rU;
    stt_DZO1_OrN13__2_1.U8V = rU;
    stt_DZO1_OrN14__3_1.U8V = rU;
    stt_DZO1_OrN18__2_1.U8V = rU;
    stt_DZO1_And15__3_1.U8V = rU;
    stt_DZO1_And16__5_1.U8V = rU;
    
    sLV.p_current_settings_prt = &current_settings_prt ;
    do{
        //U8_state_wrp R_wrp;
        long lV = (sLV.p_current_settings_prt->control_dzo & (1<<INDEX_CTR_FAULT_U_DZO)); 
        R_m_dv_po_dzo1.bool_val.m_fault_u_dzo = lV!=0;
        
        lV = _CHECK_SET_BIT(p_active_functions, RNG_BIG_NKNO); 
        R_m_dv_po_dzo1.bool_val.nkno_rng_big = lV!=0;
        
        if(R_m_dv_po_dzo1.bool_val.m_fault_u_dzo!=0 && R_m_dv_po_dzo1.bool_val.nkno_rng_big!=0)
            R_m_dv_po_dzo1.bool_val.and04_o_0 = 1;
        
        
        lV = _CHECK_SET_BIT(p_active_functions, RNG_BIG_ZVN_NESPR_DZO);
        R_m_dv_po_dzo1.bool_val.dv_zvn_nespr_dzo = lV!=0;
        if(R_m_dv_po_dzo1.bool_val.dv_zvn_nespr_dzo!=0 || R_m_dv_po_dzo1.bool_val.and04_o_0!=0 )
             R_m_dv_po_dzo1.bool_val.or05_o_0 = 1;
        lV = R_m_dv_po_dzo1.bool_val.or05_o_0;
        _TIMER_0_T(INDEX_TIMER_NKN_DZO,sLV.p_current_settings_prt->timeout_nkn_dzo[number_group_stp],
        lV, 0, lV, 1);
            
        R_m_dv_po_dzo1.bool_val.nkn_dzo1 = (lV&0x2)>>1;
        
        
    }while (rU != 0);
    
    if(R_m_dv_po_dzo1.bool_val.nkn_dzo1 != 0)
        _SET_BIT(p_active_functions, RNG_BIG_NKN_DZO);
    else
        _CLEAR_BIT(p_active_functions, RNG_BIG_NKN_DZO);
    
    
    rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_U_DZO_U_O_LESS_UP_0_25P_UN);
    if( rU!= 0) {
            sLV.po_u_dzo_u_o_less_up_0_25p_un_spt = (U_LINEAR_NOM*25/10000)
           * U_DOWN / 100;
    }else{
           sLV.po_u_dzo_u_o_less_up_0_25p_un_spt = (U_LINEAR_NOM*25/10000); 
    }
        //
    if(measurement[IM_Umn] <= sLV.po_u_dzo_u_o_less_up_0_25p_un_spt){
            R_m_dv_po_dzo1.bool_val.u_dzo_u_o_less_up_0_25p_un = 1;
            _SET_BIT(p_active_functions, RNG_BIG_U_DZO_U_O_LESS_UP_0_25P_UN);
    }else{
            R_m_dv_po_dzo1.bool_val.u_dzo_u_o_less_up_0_25p_un = 0;
            _CLEAR_BIT(p_active_functions, RNG_BIG_U_DZO_U_O_LESS_UP_0_25P_UN);
    }
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_I_BLK_DZO_I_LESS_IP_0_P_5);
    if( rU!= 0) {
            sLV.po_i_less_ip_0_p_5_spt = 500
         * KOEF_POVERNENNJA_GENERAL_DOWN / 100;
    }else{
           sLV.po_i_less_ip_0_p_5_spt = 500; 
    }
    if(measurement[IM_Imn] <= sLV.po_i_less_ip_0_p_5_spt){
        R_m_dv_po_dzo1.bool_val.i_less_ip_0_p_5 = 1;
         _SET_BIT(p_active_functions, RNG_BIG_I_BLK_DZO_I_LESS_IP_0_P_5);
    }
    else{    
        R_m_dv_po_dzo1.bool_val.i_less_ip_0_p_5 = 0;
        _CLEAR_BIT(p_active_functions, RNG_BIG_I_BLK_DZO_I_LESS_IP_0_P_5);
    }
    
    if(R_m_dv_po_dzo1.bool_val.nkn_dzo1!=0 
    || R_m_dv_po_dzo1.bool_val.u_dzo_u_o_less_up_0_25p_un!=0){
        _SET_BIT(p_active_functions,RNG_BIG_CNKN_DZO);
        R_m_dv_po_dzo1.bool_val.or06_o_0 = 1;
    }
    else{
        _CLEAR_BIT(p_active_functions,RNG_BIG_CNKN_DZO);//or06_o_0 
    }       
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_I_O3G_DIV_I_O1G_DZO);
    if( rU!= 0) {
            sLV.po_i_o3g_div_i_o1g_dzo_spt = sLV.p_current_settings_prt->pickup_dzo_Io3g_Io1g[number_group_stp]
         * KOEF_POVERNENNJA_MTZ_I_UP / 100;
    }else{
           sLV.po_i_o3g_div_i_o1g_dzo_spt = sLV.p_current_settings_prt->pickup_dzo_Io3g_Io1g[number_group_stp]; 
    }
    if(measurement[IM_Imn] >= sLV.po_i_o3g_div_i_o1g_dzo_spt){
        R_m_dv_po_dzo1.bool_val.i_o3g_div_i_o1g_dzo = 1;
         _SET_BIT(p_active_functions, RNG_BIG_I_O3G_DIV_I_O1G_DZO);
    }
    else{    
        R_m_dv_po_dzo1.bool_val.i_o3g_div_i_o1g_dzo = 0;
        _CLEAR_BIT(p_active_functions, RNG_BIG_I_O3G_DIV_I_O1G_DZO);
    }
    //...........................................................................
    //``````````````````````````````````````````````````````````````````````````` 
    R_m_dv_po_dzo1.bool_val.m_block_dzo1_i_osn_3g = 
    (sLV.p_current_settings_prt->control_dzo & (1<<INDEX_CTR_BLOCK_DZO1_I_OSN_3G))!=0;
        
    
    rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_ZBR_BLOCK_DZO1_I_O_3G);
    R_m_dv_po_dzo1.bool_val.dv_zbr_block_dzo1_i_o_3g = rU!=0;
    
    R_m_dv_po_dzo1.bool_val.not02_o_0 = (~rU)&1;
    //and9
    rU = R_m_dv_po_dzo1.U32V &(  (1<<18)| (1<<1)| (1<<11));
    if(rU == (  (1<<18 )| (1<<1 )| (1<<11 ))){
        R_m_dv_po_dzo1.bool_val.and09_o_0 = 1;
        _SET_BIT(p_active_functions,RNG_BIG_BLK_DZO1_I_O3G_DIV_I_O1G_DZO); 
    }else{
        _CLEAR_BIT(p_active_functions,RNG_BIG_BLK_DZO1_I_O3G_DIV_I_O1G_DZO);
    }
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    //Za_mn,5.24.36 При виведеному з роботи ступені АМСЗ ДЗО
    //Za_bp,розрахунковий опір для цього ступеня повинен визначатись
    //  підстановкою в вираз для розрахунку опору ном напруги (100 В). 
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO2_I_BLK_DZO);
    if( rU!= 0) {
            sLV.po2_i_blk_dzo_spt = sLV.p_current_settings_prt->pickup_dzo1_blkI[number_group_stp]
         * KOEF_POVERNENNJA_MTZ_I_UP / 100;
    }else{
           sLV.po2_i_blk_dzo_spt = sLV.p_current_settings_prt->pickup_dzo1_blkI[number_group_stp]; 
    }
    if(measurement[IM_Imn] >= sLV.po2_i_blk_dzo_spt){
        R_m_dv_po_dzo1.bool_val.po2_i_blk_dzo = 1;
         _SET_BIT(p_active_functions, RNG_BIG_PO2_I_BLK_DZO);
    }
    else{    
        R_m_dv_po_dzo1.bool_val.po2_i_blk_dzo = 0;
        _CLEAR_BIT(p_active_functions, RNG_BIG_PO2_I_BLK_DZO);
    }
    R_m_dv_po_dzo1.bool_val.m_block_dzo1_i_osn = 
    (sLV.p_current_settings_prt->control_dzo & (1<<INDEX_CTR_BLOCK_DZO1_I_OSN))!=0;
        
    
    rU = (_CHECK_SET_BIT(p_active_functions, RNG_BIG_BLK_DZO1_I_OSN))!=0;
    R_m_dv_po_dzo1.bool_val.dv_zbr_block_dzo1_i_o = rU;
    
    R_m_dv_po_dzo1.bool_val.not03_o_0 = (~rU)&1;
    //and10
    rU = R_m_dv_po_dzo1.U32V &(  (1<<19)| (1<<2)| (1<<12));
    if(rU == (  (1<<19 )| (1<<2 )| (1<<12 ))){
        R_m_dv_po_dzo1.bool_val.and10_o_0 = 1;
        _SET_BIT(p_active_functions,RNG_BIG_BLK_DZO1_I_OSN); 
    
    }else{
        _CLEAR_BIT(p_active_functions,RNG_BIG_BLK_DZO1_I_OSN);
    }
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_BLOCK_DZO1);//11
    R_m_dv_po_dzo1.bool_val.dv_block_dzo1 = rU!=0;
    //or11
    rU = R_m_dv_po_dzo1.U32V &( (1<<25)|(1<<17)|(1<<26)|(1<<7));
    if( rU!= 0) {
        R_m_dv_po_dzo1.bool_val.or11_o_0 = 1;
        _SET_BIT(p_active_functions,RNG_BIG_BLK_DZO1);
    }else{
        _CLEAR_BIT(p_active_functions,RNG_BIG_BLK_DZO1);
    }       
    //...........................................................................
    
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_AMCZ_DZO1);
    if( rU!= 0) {
            sLV.po_amcz_dzo1_spt = sLV.p_current_settings_prt->pickup_dzo1_amtz[number_group_stp]
         * KOEF_POVERNENNJA_MTZ_I_UP / 100;
    }else{
           sLV.po_amcz_dzo1_spt = sLV.p_current_settings_prt->pickup_dzo1_amtz[number_group_stp]; 
    }
    if(measurement[IM_Imn] >= sLV.po_amcz_dzo1_spt){
        R_m_dv_po_dzo1.bool_val.po_amcz_dzo1 = 1;
        
    }
    else{    
        R_m_dv_po_dzo1.bool_val.po_amcz_dzo1 = 0;
        
    }
    rU = (sLV.p_current_settings_prt->control_dzo & (1<<INDEX_CTR_DZO1_AMTZ));
    if(rU != 0)
        rU = 1;
    R_m_dv_po_dzo1.bool_val.m_dzo1_amtz = rU;
    R_m_dv_po_dzo1.bool_val.not02_o_0 = (~rU)&1;
    
    
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    //and7
    rU = R_m_dv_po_dzo1.U32V &( (1<<13)|(1<<10));//or06_o_0 not01_o_0
    if(rU == (  (1<<13 )| (1<<10 ))){
        R_m_dv_po_dzo1.bool_val.and07_o_0 = 1;
        //_SET_BIT(p_active_functions,) 
    
    }else{
        //_CLEAR_BIT(p_active_functions,);
    }
    
    //and8
    rU = R_m_dv_po_dzo1.U32V &( (1<<13)|(1<<3));//or06_o_0 i m_dzo1_amtz
    if(rU == (  (1<<13 )| (1<<3 )))
        R_m_dv_po_dzo1.bool_val.and08_o_0 = 1;
    
    
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    
    rU = (_CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_DZO1))!=0;
    R_m_dv_po_dzo1.bool_val.not17_o_0 = (~rU)&1;
    //and12
    stt_DZO1_And12__2_1.bool_val.bt0 = R_m_dv_po_dzo1.bool_val.and08_o_0;
    stt_DZO1_And12__2_1.bool_val.bt1 = R_m_dv_po_dzo1.bool_val.not17_o_0;
    if ((stt_DZO1_And12__2_1.U8V &3) == 3){
        stt_DZO1_OrN14__3_1.bool_val.bt1 = 1;
        //stt_DZO1_And12__2_1.bool_val.bt7 = 1;//debug only
    }
    
    rU = (_CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_AMCZ_DZO1))!=0;
    stt_DZO1_OrN14__3_1.bool_val.bt2 = rU;
    //orN13
    stt_DZO1_OrN13__2_1.bool_val.bt1 = rU;
    stt_DZO1_OrN13__2_1.bool_val.bt0 = R_m_dv_po_dzo1.bool_val.and08_o_0;
    if((stt_DZO1_OrN13__2_1.U8V &3) != 0){
        //stt_DZO1_OrN18__2_1.bool_val.bt1 = 0;//debug only
    }
    else{
        //inv Or
        stt_DZO1_OrN18__2_1.bool_val.bt1 = 1;
        //stt_DZO1_OrN13__2_1.bool_val.bt7 = 1;//debug only
    }   
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    stt_DZO1_OrN14__3_1.bool_val.bt0 = R_m_dv_po_dzo1.bool_val.or11_o_0;
    //stt_DZO1_OrN14__3_1.bool_val.bt1 = stt_DZO1_And12__2_1.bool_val.bt7 
    stt_DZO1_OrN14__3_1.bool_val.bt2 = rU;
    if((stt_DZO1_OrN14__3_1.U8V &7) == 0){
        stt_DZO1_And15__3_1.bool_val.bt2 = 1;//stt_DZO1_OrN14__3_1.bool_val.bt7 = 1;//Debug Only
    }
    stt_DZO1_OrN18__2_1.bool_val.bt0 = R_m_dv_po_dzo1.bool_val.or11_o_0;
    //stt_DZO1_OrN18__2_1.bool_val.bt1 = stt_DZO1_OrN13__2_1.bool_val.bt7//debug only
    if((stt_DZO1_OrN18__2_1.U8V &3) == 0){
        stt_DZO1_And16__5_1.bool_val.bt2 = 1;
    }
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    //and16 
    rU = (sLV.p_current_settings_prt->control_dzo & (1<<INDEX_CTR_DZO1))!=0;//!Error DZO1_ ON!!
    stt_DZO1_And16__5_1.bool_val.bt0 = rU;
    R_m_dv_po_dzo1.bool_val.m_dzo1 = rU;
    stt_DZO1_And16__5_1.bool_val.bt1 = R_m_dv_po_dzo1.bool_val.not17_o_0;
    stt_DZO1_And16__5_1.bool_val.bt3 = R_m_dv_po_dzo1.bool_val.po_amcz_dzo1;
    stt_DZO1_And16__5_1.bool_val.bt4 = R_m_dv_po_dzo1.bool_val.m_dzo1_amtz;
    if((stt_DZO1_And16__5_1.U8V&31) == 31){
        stt_DZO1_And16__5_1.bool_val.bt7 = 1;
        _SET_BIT(p_active_functions,RNG_BIG_PO_AMCZ_DZO1);
    }else{
        _CLEAR_BIT(p_active_functions,RNG_BIG_PO_AMCZ_DZO1);
    }
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    //.bool_val.bt0 = R_m_dv_po_dzo1.bool_val.
    rU = _CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_DZO1);
    if( rU!= 0) {
            sLV.po_dzo1_spt = sLV.p_current_settings_prt->pickup_dzo1[number_group_stp]
         * KOEF_POVERNENNJA_MTZ_I_UP / 100;
    }else{
           sLV.po_dzo1_spt = sLV.p_current_settings_prt->pickup_dzo1[number_group_stp]; 
    }
    if(R_m_dv_po_dzo1.bool_val.and07_o_0 != 0){
        rU = 0; 
        if(resistance[Z_mn]>0 ) 
             rU = resistance[Z_mn];//
    }else{
        rU = 0; 
        if(resistance[Za_mn]>0 ) 
             rU = resistance[Za_mn];
    }
    //!else
    //!    rU = resistance[Z_mn];//!
    if(rU >= sLV.po_dzo1_spt)
        R_m_dv_po_dzo1.bool_val.po_dzo1 = 1;
    
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    stt_DZO1_And15__3_1.bool_val.bt0 = R_m_dv_po_dzo1.bool_val.m_dzo1;
    stt_DZO1_And15__3_1.bool_val.bt1 = R_m_dv_po_dzo1.bool_val.po_dzo1;
    //bt2 = Set Early
    if((stt_DZO1_And15__3_1.U8V&7) == 7){
        _SET_BIT(p_active_functions,RNG_BIG_PO_DZO1);
        stt_DZO1_And15__3_1.bool_val.bt7 = 1;
    }else{
        _CLEAR_BIT(p_active_functions,RNG_BIG_PO_DZO1);
    }
    unsigned long u32_bit_holder = 0;
    if(stt_DZO1_And15__3_1.bool_val.bt7 == 1)
        u32_bit_holder |= 1<< IDX_TIMER_IN_DZO1;
    _TIMER_T_0(INDEX_TIMER_DZO1,sLV.p_current_settings_prt->timeout_dzo1[number_group_stp],
        u32_bit_holder,IDX_TIMER_IN_DZO1, u32_bit_holder, IDX_TIMER_OUT_DZO1);
    if(stt_DZO1_And16__5_1.bool_val.bt7 == 1)
        u32_bit_holder |= 1<< IDX_TIMER_IN_DZO1_AMTZ;
    _TIMER_T_0(INDEX_TIMER_DZO1_AMTZ,sLV.p_current_settings_prt->timeout_dzo1_amtz[number_group_stp],
        u32_bit_holder,IDX_TIMER_IN_DZO1_AMTZ, u32_bit_holder, IDX_TIMER_OUT_DZO1_AMTZ);
        

    
    
}
//
//--------------------------------------------------------------------------------------------------------
//=====================================================================================================
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//                  
//....................................................................................................
//=====================================================================================================
void dzo4_handler(unsigned int *p_active_functions, unsigned int number_group_stp )

{
 
 unsigned long rU;
 register U32_dzo4_wrp R_m_dv_po_dzo4;
 struct{
      unsigned long po_dzo4_dir_z0_spt,po_dzo4_inv_z0_spt,
      po_dzo4_dir_x0_spt,po_dzo4_inv_x0_spt, po_dzo4_border_cnt, 
       po_dzo4_amcz_spt;
  __SETTINGS *p_current_settings_prt;
    
  }sLV; 
  
      R_m_dv_po_dzo4.U32V = 0;//stt_DZO4_And09__3_1,
    U8_state_wrp 
    //stt_DZO4_And11__2_1,
    //stt_DZO4_And12__2_1,
    stt_DZO4_OrN14__3_1,    
    stt_DZO4_OrN15__3_1,    
    stt_DZO4_OrN16__2_1,    
    stt_DZO4_OrN13__2_1,    
    stt_DZO4_And17__5_1,    
    stt_DZO4_And18__5_1,    
    stt_DZO4_And19__6_1;
    rU = 0;
    //stt_DZO4_And11__2_1.U8V = rU;
    //stt_DZO4_And12__2_1.U8V = rU;
    stt_DZO4_OrN14__3_1.U8V = rU;   
    stt_DZO4_OrN15__3_1.U8V = rU;   
    stt_DZO4_OrN16__2_1.U8V = rU;   
    stt_DZO4_OrN13__2_1.U8V = rU;   
    stt_DZO4_And17__5_1.U8V = rU;   
    stt_DZO4_And18__5_1.U8V = rU;   
    stt_DZO4_And19__6_1.U8V = rU;

    sLV.p_current_settings_prt = &current_settings_prt ;
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    rU = (sLV.p_current_settings_prt->control_dzo & (1<<INDEX_CTR_DZO4)); 
    R_m_dv_po_dzo4.bool_val.m_dzo4 = rU!=0;
    rU = (sLV.p_current_settings_prt->control_dzo & (1<<INDEX_CTR_DZO4_DIR)); 
    R_m_dv_po_dzo4.bool_val.m_dzo4_dir = rU!=0;
    rU = (sLV.p_current_settings_prt->control_dzo & (1<<INDEX_CTR_DZO4_INV)); 
    R_m_dv_po_dzo4.bool_val.m_dzo4_inv = rU!=0;
    rU = ((sLV.p_current_settings_prt->control_dzo & (1<<INDEX_CTR_DZO4_AMTZ)))!=0; 
    R_m_dv_po_dzo4.bool_val.m_dzo4_amtz = rU;
    //not5
    R_m_dv_po_dzo4.bool_val.not05_o_0 = (~rU)&1;

    rU = (sLV.p_current_settings_prt->control_dzo & (1<<INDEX_CTR_BLOCK_DZO4_I_OSN_3G)); 
    R_m_dv_po_dzo4.bool_val.m_block_dzo4_i_osn_3g = rU!=0;

    
    rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_ZBR_BLOCK_DZO4_I_O_3G); 
    R_m_dv_po_dzo4.bool_val.dv_zbr_blk_dzo4_i_o_3g = rU!=0;
    //not6
    R_m_dv_po_dzo4.bool_val.not06_o_0 = (~rU)&1;
    rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_BLOCK_DZO4); 
    R_m_dv_po_dzo4.bool_val.dv_blk_dzo4 = rU!=0;
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    //Or20
    rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_I_O3G_DIV_I_O1G_DZO);
    R_m_dv_po_dzo4.bool_val.cmd_i_o3g_div_i_o1g_dzo = rU!=0;
    rU = R_m_dv_po_dzo4.U32V &((1<<23)|(1<<4)|(1<<17));//cmd_i_o3g_div_i_o1g_dzo m_block_dzo4_i_osn_3g not06_o_0
    if( rU!= 0) {
         R_m_dv_po_dzo4.bool_val.or20_o_0 = 1;
        _SET_BIT(p_active_functions,RNG_BIG_BLK_DZO4_I_OSN_3G_DIV_1G);
    }else{
        _CLEAR_BIT(p_active_functions,RNG_BIG_BLK_DZO4_I_OSN_3G_DIV_1G);
    }   
    //Or21
    rU = _CHECK_SET_BIT(p_active_functions,RNG_BIG_I_BLK_DZO_I_LESS_IP_0_P_5);
    R_m_dv_po_dzo4.bool_val.cmd_i_less_ip_0_p_5 = rU!=0;
    rU = R_m_dv_po_dzo4.U32V &((1<<21)|(1<<24)|(1<<6));//or20_o_0 cmd_i_less_ip_0_p_5 dv_blk_dzo4
    if( rU!= 0) {
         R_m_dv_po_dzo4.bool_val.or21_o_0 = 1;
        _SET_BIT(p_active_functions,RNG_BIG_BLK_DZO4);
    }else{
        _CLEAR_BIT(p_active_functions,RNG_BIG_BLK_DZO4);
    } 
    
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
        //Phase element
        
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    //and1
    rU = _CHECK_SET_BIT(p_active_functions,RNG_BIG_CNKN_DZO);
    R_m_dv_po_dzo4.bool_val.cmd_snkn_dzo = rU!=0;
    rU = R_m_dv_po_dzo4.U32V &( (1<<16)|(1<<25));//not05_o_0 cmd_snkn_dzo
    if(rU == (  (1<<16 )| (1<<25 )))
        R_m_dv_po_dzo4.bool_val.and01_o_0 = 1;
    
    if(resistance[R_mn] != UNDEF_RESISTANCE){
        if(resistance[R_mn]>0) 
            R_m_dv_po_dzo4.bool_val.naprym_dir_dzo4 = 1;
        else
            R_m_dv_po_dzo4.bool_val.naprym_inv_dzo4 = 1;
    }
    //Or2
    rU = R_m_dv_po_dzo4.U32V &( (1<<12)|(1<<7));//and01_o_0 naprym_dir_dzo4
    if(rU != 0)
        R_m_dv_po_dzo4.bool_val.or02_o_0 = 1;
    //Or3
    rU = R_m_dv_po_dzo4.U32V &( (1<<12)|(1<<8));//and01_o_0 naprym_inv_dzo4
    if(rU != 0)
        R_m_dv_po_dzo4.bool_val.or03_o_0 = 1;
    
    //And4
    rU = R_m_dv_po_dzo4.U32V &( (1<<3)|(1<<25));// cmd_snkn_dzo m_dzo4_amtz
    if(rU == (  (1<<3 )| (1<<25 )))
        R_m_dv_po_dzo4.bool_val.and04_o_0 = 1;

    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    //PO dir
    sLV.po_dzo4_border_cnt = 0;
    if(resistance[R_mn]>0 && resistance[R_mn] != UNDEF_RESISTANCE)
        sLV.po_dzo4_border_cnt++;
    
    rU = _CHECK_SET_BIT(p_active_functions,RNG_BIG_NAPRYM_DIR_DZO4);
    if( rU!= 0) {
            sLV.po_dzo4_dir_z0_spt = sLV.p_current_settings_prt->pickup_dzo4_Zo_dir[number_group_stp]
         * KOEF_POVERNENNJA_MTZ_I_UP / 100;
          sLV.po_dzo4_dir_x0_spt = sLV.p_current_settings_prt->pickup_dzo4_Xo_dir[number_group_stp]
         * KOEF_POVERNENNJA_MTZ_I_UP / 100;
    }else{
           sLV.po_dzo4_dir_z0_spt = sLV.p_current_settings_prt->pickup_dzo4_Zo_dir[number_group_stp]; 
           sLV.po_dzo4_dir_x0_spt = sLV.p_current_settings_prt->pickup_dzo4_Xo_dir[number_group_stp]; 
    }
    
    if(R_m_dv_po_dzo4.bool_val.and01_o_0 != 0){
        if(resistance[Za_mn]>0)
            rU = resistance[Za_mn];
        else if(resistance[Za_mn] == UNDEF_RESISTANCE)
                rU = 0;
        else
            while(1);
            
    }else{
        if(resistance[Z_mn]>0 )
            rU = resistance[Z_mn];
        else if(resistance[Z_mn] == UNDEF_RESISTANCE)
                rU = 0;
        else 
            while(1);
            
    }
    if(rU >= sLV.po_dzo4_dir_z0_spt)
        sLV.po_dzo4_border_cnt++;//R_m_dv_po_dzo1.bool_val.po_dzo1 = 1;
    
    long lV;
    lV = resistance[X_mn];
    if(lV != UNDEF_RESISTANCE){
        
        if( lV < 0 )//pickup_dzo4_Xo_dir
            lV *=(-1); //resistance[X_mn]
    }
     else
        lV = 0;      
    if((unsigned long)lV >= sLV.po_dzo4_inv_x0_spt)
        sLV.po_dzo4_border_cnt++;//R_m_dv_po_dzo1.bool_val.po_dzo1 = 1;

    if(sLV.po_dzo4_border_cnt == 3)
        R_m_dv_po_dzo4.bool_val.po_dir_dzo4 = 1;
    
    //Po Inv
    sLV.po_dzo4_border_cnt = 0;
    if(resistance[R_mn]<0 && resistance[R_mn] != UNDEF_RESISTANCE)
        sLV.po_dzo4_border_cnt++;
    rU = _CHECK_SET_BIT(p_active_functions,RNG_BIG_NAPRYM_INV_DZO4);
    if( rU!= 0) {
            sLV.po_dzo4_dir_z0_spt = sLV.p_current_settings_prt->pickup_dzo4_Zo_dir[number_group_stp]
         * KOEF_POVERNENNJA_MTZ_I_UP / 100;
          sLV.po_dzo4_dir_x0_spt = sLV.p_current_settings_prt->pickup_dzo4_Xo_dir[number_group_stp]
         * KOEF_POVERNENNJA_MTZ_I_UP / 100;
    }else{
           sLV.po_dzo4_dir_z0_spt = sLV.p_current_settings_prt->pickup_dzo4_Zo_dir[number_group_stp]; 
           sLV.po_dzo4_dir_x0_spt = sLV.p_current_settings_prt->pickup_dzo4_Xo_dir[number_group_stp]; 
    }
    if(R_m_dv_po_dzo4.bool_val.and01_o_0 != 0){
        //rU = resistance[Za_mn];//!
        if(resistance[Za_mn]>0)
            rU = resistance[Za_mn];
        else if(resistance[Za_mn] == UNDEF_RESISTANCE)
                rU = 0;
        else
            while(1);
    }else{
        //rU = resistance[Z_mn];//!
        if(resistance[Z_mn]>0 )
            rU = resistance[Z_mn];
        else if(resistance[Z_mn] == UNDEF_RESISTANCE)
                rU = 0;
        else 
            while(1);
    }
    if(rU >= sLV.po_dzo4_inv_z0_spt)
        sLV.po_dzo4_border_cnt++;//R_m_dv_po_dzo1.bool_val.po_dzo1 = 1;
    
    //long lV;
    lV = resistance[X_mn];
    if(lV != UNDEF_RESISTANCE){
        
        if( lV < 0 )//pickup_dzo4_Xo_dir
            lV *=(-1); //resistance[X_mn]
    }
     else
        lV = 0; 
    if((unsigned long)lV >= sLV.po_dzo4_inv_x0_spt)
        sLV.po_dzo4_border_cnt++;//R_m_dv_po_dzo1.bool_val.po_dzo1 = 1;

    if(sLV.po_dzo4_border_cnt == 3)
        R_m_dv_po_dzo4.bool_val.po_inv_dzo4 = 1;



    //PO Amtz
    rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_AMCZ_DZO4);
    if( rU!= 0) {
            sLV.po_dzo4_amcz_spt = sLV.p_current_settings_prt->pickup_dzo4_amtz[number_group_stp]
         * KOEF_POVERNENNJA_MTZ_I_UP / 100;
    }else{
           sLV.po_dzo4_amcz_spt = sLV.p_current_settings_prt->pickup_dzo4_amtz[number_group_stp]; 
    }
    if(measurement[IM_Imn] >= sLV.po_dzo4_amcz_spt){
        R_m_dv_po_dzo4.bool_val.po_amcz_dzo4 = 1;
        
    }
    else{    
        R_m_dv_po_dzo4.bool_val.po_amcz_dzo4 = 0;
        
    }
    rU = (sLV.p_current_settings_prt->control_dzo & (1<<INDEX_CTR_DZO4_AMTZ));
    R_m_dv_po_dzo4.bool_val.m_dzo4_amtz = rU!=0;
    
     rU = (_CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_DIR_DZO4))!=0;
    R_m_dv_po_dzo4.bool_val.not07_o_0 = (~rU)&1;
     rU = (_CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_INV_DZO4))!=0;
    R_m_dv_po_dzo4.bool_val.not08_o_0 = (~rU)&1;
    
    //and11
    rU = R_m_dv_po_dzo4.U32V &( (1<<15)|(1<<18));//and04_o_0 i not07_o_0
    if(rU == ( (1<<15 )| (1<<18 )))
        R_m_dv_po_dzo4.bool_val.and11_o_0 = 1;
    //and12
    rU = R_m_dv_po_dzo4.U32V &( (1<<15)|(1<<19));//and04_o_0 i not08_o_0
    if(rU == (  (1<<15 )| (1<<19 )))
        R_m_dv_po_dzo4.bool_val.and12_o_0 = 1;
    

    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    rU = (_CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_AMCZ_DZO4))!=0;
    stt_DZO4_OrN13__2_1.bool_val.bt1 = rU;
    stt_DZO4_OrN15__3_1.bool_val.bt2 = rU;
    stt_DZO4_OrN14__3_1.bool_val.bt2 = rU;
    rU = R_m_dv_po_dzo4.bool_val.or21_o_0;//_CHECK_SET_BIT(p_active_functions, RNG_BIG_BLOCK_DZO4);
    stt_DZO4_OrN14__3_1.bool_val.bt0 = rU;
    stt_DZO4_OrN15__3_1.bool_val.bt0 = rU;
    stt_DZO4_OrN16__2_1.bool_val.bt0 = rU;
    //orN13
    rU = R_m_dv_po_dzo4.bool_val.and04_o_0;
    stt_DZO4_OrN13__2_1.bool_val.bt0 = rU;
    if((stt_DZO4_OrN13__2_1.U8V &3) == 0)
        stt_DZO4_OrN16__2_1.bool_val.bt1 = 1;//stt_DZO4_OrN13__2_1.bool_val.bt7 = 1; 
    //orN16
    if((stt_DZO4_OrN16__2_1.U8V &3) == 0)
        stt_DZO4_And19__6_1.bool_val.bt3 = 1;//stt_DZO4_OrN16__2_1.bool_val.
    //orN15
    stt_DZO4_OrN15__3_1.bool_val.bt1 = R_m_dv_po_dzo4.bool_val.and12_o_0;
    if((stt_DZO4_OrN15__3_1.U8V &7) == 0)
        stt_DZO4_And18__5_1.bool_val.bt4 = 1;
    //orN14
    stt_DZO4_OrN14__3_1.bool_val.bt1 = R_m_dv_po_dzo4.bool_val.and11_o_0;
    if((stt_DZO4_OrN14__3_1.U8V &7) == 0)
        stt_DZO4_And17__5_1.bool_val.bt4 = 1;
    
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    //and17
    rU = (sLV.p_current_settings_prt->control_dzo & (1<<INDEX_CTR_DZO4))!=0;
    stt_DZO4_And17__5_1.bool_val.bt0 = rU;
    stt_DZO4_And18__5_1.bool_val.bt0 = rU;
    stt_DZO4_And19__6_1.bool_val.bt0 = rU;
    rU = (sLV.p_current_settings_prt->control_dzo & (1<<INDEX_CTR_DZO4_DIR))!=0;
    stt_DZO4_And17__5_1.bool_val.bt1 = rU;
    stt_DZO4_And17__5_1.bool_val.bt2 = R_m_dv_po_dzo4.bool_val.po_dir_dzo4;
    stt_DZO4_And17__5_1.bool_val.bt3 = R_m_dv_po_dzo4.bool_val.or02_o_0;
    if((stt_DZO4_And17__5_1.U8V&31) == 31){
        stt_DZO4_And17__5_1.bool_val.bt7 = 1;
        _SET_BIT(p_active_functions,RNG_BIG_PO_DIR_DZO4);
    }else{
        _CLEAR_BIT(p_active_functions,RNG_BIG_PO_DIR_DZO4);
    }
    //and18
    rU = (sLV.p_current_settings_prt->control_dzo & (1<<INDEX_CTR_DZO4_INV))!=0;
    stt_DZO4_And18__5_1.bool_val.bt1 = rU;
    stt_DZO4_And18__5_1.bool_val.bt2 = R_m_dv_po_dzo4.bool_val.po_inv_dzo4;
    stt_DZO4_And18__5_1.bool_val.bt3 = R_m_dv_po_dzo4.bool_val.or03_o_0; 
    if((stt_DZO4_And18__5_1.U8V&31) == 31){
        stt_DZO4_And18__5_1.bool_val.bt7 = 1;
        _SET_BIT(p_active_functions,RNG_BIG_PO_INV_DZO4);
    }else{
        _CLEAR_BIT(p_active_functions,RNG_BIG_PO_INV_DZO4);
    }
    //and19
    stt_DZO4_And19__6_1.bool_val.bt1 = R_m_dv_po_dzo4.bool_val.not07_o_0;
    stt_DZO4_And19__6_1.bool_val.bt2 = R_m_dv_po_dzo4.bool_val.not08_o_0;
    stt_DZO4_And19__6_1.bool_val.bt4 = R_m_dv_po_dzo4.bool_val.po_amcz_dzo4;
    stt_DZO4_And19__6_1.bool_val.bt5 = R_m_dv_po_dzo4.bool_val.m_dzo4_amtz;
    if((stt_DZO4_And19__6_1.U8V&63) == 63){
        stt_DZO4_And19__6_1.bool_val.bt7 = 1;
        _SET_BIT(p_active_functions,RNG_BIG_PO_AMCZ_DZO4);
    }
    else{
        _CLEAR_BIT(p_active_functions,RNG_BIG_PO_AMCZ_DZO4);
    }
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    unsigned long u32_bit_holder = 0;
    if(stt_DZO4_And17__5_1.bool_val.bt7 == 1)
        u32_bit_holder |= 1<< IDX_TIMER_IN_DZO4_DIR;
    _TIMER_T_0(INDEX_TIMER_DZO4_DIR,sLV.p_current_settings_prt->timeout_dzo4_dir[number_group_stp],
        u32_bit_holder,IDX_TIMER_IN_DZO4_DIR, u32_bit_holder, IDX_TIMER_OUT_DZO4_DIR);
    
    if(stt_DZO4_And18__5_1.bool_val.bt7 == 1)
        u32_bit_holder |= 1<< IDX_TIMER_IN_DZO4_INV;
    _TIMER_T_0(INDEX_TIMER_DZO4_INV,sLV.p_current_settings_prt->timeout_dzo4_inv[number_group_stp],
        u32_bit_holder,IDX_TIMER_IN_DZO4_INV, u32_bit_holder, IDX_TIMER_OUT_DZO4_INV);
      
    if(stt_DZO4_And19__6_1.bool_val.bt7 == 1)
        u32_bit_holder |= 1<< IDX_TIMER_IN_DZO4_AMTZ;
    _TIMER_T_0(INDEX_TIMER_DZO4_AMTZ,sLV.p_current_settings_prt->timeout_dzo4_amtz[number_group_stp],
        u32_bit_holder,IDX_TIMER_IN_DZO4_AMTZ, u32_bit_holder, IDX_TIMER_OUT_DZO4_AMTZ);
      
    if(u32_bit_holder&( (1<<IDX_TIMER_OUT_DZO4_DIR)|(1<<IDX_TIMER_OUT_DZO4_INV)         )){
        _SET_BIT(p_active_functions, RNG_BIG_DZO4);
    }else{
        _CLEAR_BIT(p_active_functions, RNG_BIG_DZO4);
    }   
    if(u32_bit_holder&( 1<< IDX_TIMER_IN_DZO4_AMTZ)){
        _SET_BIT(p_active_functions, RNG_BIG_AMCZ_DZO4);
    }else{
        _CLEAR_BIT(p_active_functions, RNG_BIG_AMCZ_DZO4);
    }  
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    
    
    
}
//
//--------------------------------------------------------------------------------------------------------
