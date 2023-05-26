#include <string.h> 
#include "const_global.h"
#include "mtzr.h"
void mtzr_handler(unsigned int *p_active_functions, unsigned int number_group_stp );
void mtzr2_handler(unsigned int *p_active_functions, unsigned int number_group_stp );
void mtzr134_handler(unsigned int *p_active_functions, unsigned int number_group_stp );
#ifdef DEBUG_CONFIGURATION
    #ifndef DEBUG_MODE_23_07_19 
        #error "VALUES DZ HAVE UNREAL NUMBER"
    #endif
#endif
char glb_ch_id_mtzr = ID_MTZR1;

void mtzr_handler(unsigned int *p_active_functions, unsigned int number_group_stp ){
    glb_ch_id_mtzr = ID_MTZR1;
    mtzr134_handler(p_active_functions,number_group_stp);
//?    mtzr2_handler(p_active_functions,number_group_stp);
//?    glb_ch_id_mtzr = ID_MTZR3;
//?    mtzr134_handler(p_active_functions,number_group_stp);
    glb_ch_id_mtzr = ID_MTZR2;
    mtzr134_handler(p_active_functions,number_group_stp);
    
}

//?U8_state_wrp mtzr1_stp,mtzr2_stp,mtzr3_stp,mtzr4_stp;
U8_state_wrp stt_MTZR_And01__2_1;
void mtzr134_handler(unsigned int *p_active_functions, unsigned int number_group_stp );
//=====================================================================================================
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//                  
//....................................................................................................
//=====================================================================================================
void mtzr134_handler(unsigned int *p_active_functions, unsigned int number_group_stp )//{UNUSED(number_group_stp);UNUSED(p_active_functions);
{
  long lV;unsigned long rU;
   
  register union { 
  struct {
      unsigned int b0                       :1;//0
      unsigned int select_mtzr134_directed  :1;//1
      unsigned int b1                       :1;//2
      unsigned int m_mtzr134                :1;//3
      unsigned int dv_block_mtzr134         :1;//4
      unsigned int m_mtzr134_dir            :1;//5
      unsigned int m_mtzr134_sector_dir     :1;//6
      unsigned int m_mtzr134_sector_inv     :1;//7
      unsigned int b8                       :1;//8
      unsigned int m_mtzr134_inv            :1;//9
      unsigned int b10                      :1;//10
      unsigned int b11                      :1;//11
      unsigned int b12                      :1;//12
      unsigned int b13                      :1;//13
      unsigned int b14                      :1;//14
      unsigned int b15                      :1;//15
      unsigned int not10_1_b7              :1;//16
      unsigned int cmd_nkn_mtzr134         :1;//17
      unsigned int not8_1_b7               :1;//18
      unsigned int not5_1_b7               :1;//19
      unsigned int and6_2_1_b7             :1;//20
      unsigned int or07_2_1_b7             :1;//21
      unsigned int and9_2_1_b7             :1;//22
      unsigned int po_mtzr134_u_pn         :1;//23
      unsigned int po_mtzr134_i_pn         :1;//24
      unsigned int po_mtzr134_sector_inv   :1;//25
      unsigned int po_mtzr134_sector_dir   :1;//26
      unsigned int po_mtzr134_inv          :1;//27
      unsigned int po_mtzr134_dir          :1;//28
      unsigned int po_mtzr134_simple       :1;//29
      unsigned int reser2 :1;//30
      unsigned int reser3 :1;//31
      
   } bool_vars;
  long lVl;
 }wrp_mtzr;
  
  
  struct{
      unsigned long po_mtzr_smpl_spt,     po_mtzrn_vpered_spt,  po_mtzrn_nazad_spt,
       po_u_mtzrpn_spt,     po_mtzrpn_spt;
  __SETTINGS *p_current_settings_prt;
  }sLV;    
    wrp_mtzr.lVl = 0;
    U8_state_wrp 
                 stt_MTZR_Or_02__3_1,
                 stt_MTZR_Not03__1_1,  
                 stt_MTZR_And04__2_1,
                 
                 
                 stt_MTZR_OrN_07__2_1, 
                 
                 stt_MTZR_And09__2_1,
                 
                 stt_MTZR_And11__2_1,
                 stt_MTZR_Or_12__4_1,
                 stt_MTZR_And13__3_1,
                 stt_MTZR_And14__6_1, 
                 stt_MTZR_And15__6_1, 
                 stt_MTZR_And16__4_1; 
                
    lV = 0;         
     stt_MTZR_And01__2_1.U8V = lV;
     stt_MTZR_Or_02__3_1.U8V = lV;
     stt_MTZR_Not03__1_1.U8V = lV;
     stt_MTZR_And04__2_1.U8V = lV;


     stt_MTZR_OrN_07__2_1.U8V = lV;

     stt_MTZR_And09__2_1.U8V = lV;

     stt_MTZR_And11__2_1.U8V = lV;
     stt_MTZR_Or_12__4_1.U8V = lV;
     stt_MTZR_And13__3_1.U8V = lV;
     stt_MTZR_And14__6_1.U8V = lV;
     stt_MTZR_And15__6_1.U8V = lV;
     stt_MTZR_And16__4_1.U8V = lV;

     
    sLV.p_current_settings_prt = &current_settings_prt ;

    
    //Po mtz simple
    if(glb_ch_id_mtzr == ID_MTZR1){
        wrp_mtzr.bool_vars.m_mtzr134 =  
    (sLV.p_current_settings_prt->control_mtzr & CTR_MTZR_1)!=0 ;  
        wrp_mtzr.bool_vars.m_mtzr134_dir = 
    (sLV.p_current_settings_prt->control_mtzr & CTR_MTZR_1_VPERED)!=0 ;  
        wrp_mtzr.bool_vars.m_mtzr134_inv = 
    (sLV.p_current_settings_prt->control_mtzr & CTR_MTZR_1_NAZAD)!=0 ;  
       
        rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZR1);
      
        if( rU!= 0) {
            sLV.po_mtzr_smpl_spt = sLV.p_current_settings_prt->setpoint_mtzr_1[number_group_stp]
         * KOEF_POVERNENNJA_MTZ_I_UP / 100;
        }else{
           sLV.po_mtzr_smpl_spt = sLV.p_current_settings_prt->setpoint_mtzr_1[number_group_stp]; 
        }
        //
        if(measurement[IM_Ibp] >= sLV.po_mtzr_smpl_spt)
            wrp_mtzr.bool_vars.po_mtzr134_simple = 1;
        
        
        rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZRN1_VPERED);
        //
        if( rU!= 0) {
            sLV.po_mtzrn_vpered_spt = sLV.p_current_settings_prt->setpoint_mtzr_1_n_vpered[number_group_stp]
         * KOEF_POVERNENNJA_MTZ_I_UP / 100;
        }else{
           sLV.po_mtzrn_vpered_spt = sLV.p_current_settings_prt->setpoint_mtzr_1_n_vpered[number_group_stp]; 
        }
        //
        if(measurement[IM_Ibp] >= sLV.po_mtzrn_vpered_spt)
            wrp_mtzr.bool_vars.po_mtzr134_dir = 1;//
        
        
        //
        rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZRN1_NAZAD);
        
        if( rU!= 0) {
            sLV.po_mtzrn_nazad_spt = sLV.p_current_settings_prt->setpoint_mtzr_1_n_nazad[number_group_stp]
         * KOEF_POVERNENNJA_MTZ_I_UP / 100;
        }else{
           sLV.po_mtzrn_nazad_spt = sLV.p_current_settings_prt->setpoint_mtzr_1_n_nazad[number_group_stp]; 
        }
        //
        if(measurement[IM_Ibp] >= sLV.po_mtzrn_nazad_spt)
            wrp_mtzr.bool_vars.po_mtzr134_inv = 1;//
        
        
        if((sector_directional_mtz[MTZ_LEVEL1][PHASE_BP_INDEX] == MTZ_VPERED)){
            wrp_mtzr.bool_vars.po_mtzr134_sector_dir = 1;//
            _SET_BIT(p_active_functions, RNG_BIG_SECTOR_VPERED_MCZRN1);
        }else{ 
            
            _CLEAR_BIT(p_active_functions, RNG_BIG_SECTOR_VPERED_MCZRN1);
        }   
        if(sector_directional_mtz[MTZ_LEVEL1][PHASE_BP_INDEX] == MTZ_NAZAD){
           wrp_mtzr.bool_vars.po_mtzr134_sector_inv = 1; 
            _SET_BIT(p_active_functions, RNG_BIG_SECTOR_NAZAD_MCZRN1);
        }else{
            
            _CLEAR_BIT(p_active_functions, RNG_BIG_SECTOR_NAZAD_MCZRN1);
        }
        rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZRPN1);
        if( rU!= 0 ) {
            sLV.po_u_mtzrpn_spt = sLV.p_current_settings_prt->setpoint_mtzr_1_U[number_group_stp] * U_DOWN / 100;
            sLV.po_mtzrpn_spt = sLV.p_current_settings_prt->setpoint_mtzr_1_po_napruzi[number_group_stp] * KOEF_POVERNENNJA_MTZ_I_UP / 100;
        }else{
           sLV.po_u_mtzrpn_spt = sLV.p_current_settings_prt->setpoint_mtzr_1_U[number_group_stp]; 
           sLV.po_mtzrpn_spt = sLV.p_current_settings_prt->setpoint_mtzr_1_po_napruzi[number_group_stp]; 
        }
        if(measurement[IM_Ubp] <= sLV.po_u_mtzrpn_spt){
            wrp_mtzr.bool_vars.po_mtzr134_u_pn = 1;//
            _SET_BIT(p_active_functions, RNG_BIG_PO_BLK_U_RSV_LESS_UST_MCZR2);
        }else{
           
            _CLEAR_BIT(p_active_functions, RNG_BIG_PO_BLK_U_RSV_LESS_UST_MCZR2);
        }
        if(measurement[IM_Ibp] >= sLV.po_mtzrpn_spt)
            wrp_mtzr.bool_vars.po_mtzr134_i_pn = 1;//
        
        
    }
    else if(glb_ch_id_mtzr == ID_MTZR2){
        wrp_mtzr.bool_vars.m_mtzr134 =  
        (sLV.p_current_settings_prt->control_mtzr & CTR_MTZR_2)!=0 ;  
        wrp_mtzr.bool_vars.m_mtzr134_dir = 
        (sLV.p_current_settings_prt->control_mtzr & CTR_MTZR_2_VPERED)!=0 ;  
        wrp_mtzr.bool_vars.m_mtzr134_inv = 
        (sLV.p_current_settings_prt->control_mtzr & CTR_MTZR_2_NAZAD)!=0 ;  
       
        rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZR2);
        
        if( rU!= 0 ) {
            sLV.po_mtzr_smpl_spt = sLV.p_current_settings_prt->setpoint_mtzr_2[number_group_stp]
         * KOEF_POVERNENNJA_MTZ_I_UP / 100;
        }else{
           sLV.po_mtzr_smpl_spt = sLV.p_current_settings_prt->setpoint_mtzr_2[number_group_stp]; 
        }
        
        if(measurement[IM_Ibp] >= sLV.po_mtzr_smpl_spt)
            wrp_mtzr.bool_vars.po_mtzr134_simple = 1;

        rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZRN2_VPERED);
        //
        if( rU!= 0) {
            sLV.po_mtzrn_vpered_spt = sLV.p_current_settings_prt->setpoint_mtzr_2_n_vpered[number_group_stp]
         * KOEF_POVERNENNJA_MTZ_I_UP / 100;
        }else{
           sLV.po_mtzrn_vpered_spt = sLV.p_current_settings_prt->setpoint_mtzr_2_n_vpered[number_group_stp]; 
        }
        //
        if(measurement[IM_Ibp] >= sLV.po_mtzrn_vpered_spt)
            wrp_mtzr.bool_vars.po_mtzr134_dir = 1;//

        //
        rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZRN2_NAZAD);
        //
        if( rU!= 0) {
            sLV.po_mtzrn_nazad_spt = sLV.p_current_settings_prt->setpoint_mtzr_2_n_vpered[number_group_stp]
         * KOEF_POVERNENNJA_MTZ_I_UP / 100;
        }else{
           sLV.po_mtzrn_nazad_spt = sLV.p_current_settings_prt->setpoint_mtzr_2_n_vpered[number_group_stp]; 
        }
        //
        if(measurement[IM_Ibp] >= sLV.po_mtzrn_nazad_spt)
            wrp_mtzr.bool_vars.po_mtzr134_inv = 1;

        if((sector_directional_mtz[MTZ_LEVEL2][PHASE_BP_INDEX] == MTZ_VPERED)){
            wrp_mtzr.bool_vars.po_mtzr134_sector_dir = 1;//
            _SET_BIT(p_active_functions, RNG_BIG_SECTOR_VPERED_MCZRN2);
        }else{ 
            //.R_mtzr_po.bool_val.po_mtz_sector_dir = 0;
            _CLEAR_BIT(p_active_functions, RNG_BIG_SECTOR_VPERED_MCZRN2);
        }   
        if(sector_directional_mtz[MTZ_LEVEL2][PHASE_BP_INDEX] == MTZ_NAZAD){
            wrp_mtzr.bool_vars.po_mtzr134_sector_inv = 1;//
            _SET_BIT(p_active_functions, RNG_BIG_SECTOR_NAZAD_MCZRN2);
        }else{
            //>R_mtzr_po.bool_val.po_mtz_sector_inv = 0;
            _CLEAR_BIT(p_active_functions, RNG_BIG_SECTOR_NAZAD_MCZRN2);
        }
        rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZRPN2);
        if( rU!= 0 ) {
            sLV.po_u_mtzrpn_spt = sLV.p_current_settings_prt->setpoint_mtzr_2_U[number_group_stp] * U_DOWN / 100;
            sLV.po_mtzrpn_spt = sLV.p_current_settings_prt->setpoint_mtzr_2_po_napruzi[number_group_stp] * KOEF_POVERNENNJA_MTZ_I_UP / 100;
        }else{
           sLV.po_u_mtzrpn_spt = sLV.p_current_settings_prt->setpoint_mtzr_2_U[number_group_stp]; 
           sLV.po_mtzrpn_spt = sLV.p_current_settings_prt->setpoint_mtzr_2_po_napruzi[number_group_stp]; 
        }
        if(measurement[IM_Ubp] <= sLV.po_u_mtzrpn_spt){
             wrp_mtzr.bool_vars.po_mtzr134_u_pn = 1;//
            _SET_BIT(p_active_functions, RNG_BIG_PO_BLK_U_RSV_LESS_UST_MCZR2);
        }else{
            
            _CLEAR_BIT(p_active_functions, RNG_BIG_PO_BLK_U_RSV_LESS_UST_MCZR2);
        }
        if(measurement[IM_Ibp] >= sLV.po_mtzrpn_spt)
            wrp_mtzr.bool_vars.po_mtzr134_i_pn = 1;//

    
    }
  
    //RNG_BIG_PO_BLK_U_OSN_LESS_0_05UN_MCZO,
     //ДВ
    //lV = _CHECK_SET_BIT(p_active_functions, );  
    
    if(glb_ch_id_mtzr == ID_MTZR1){
        
        
        if ( (sLV.p_current_settings_prt->control_mtzr & CTR_MTZR_NESPR_KIL_NAPR) != 0) 
            stt_MTZR_And01__2_1.bool_val.bt0 = 1;
        //stt_MTZR_And01__2_1.bool_val.bt0 = lV;
        lV = _CHECK_SET_BIT(p_active_functions, RNG_BIG_NKNR);
        stt_MTZR_And01__2_1.bool_val.bt1 = lV!=0;
    //eval
        if ((stt_MTZR_And01__2_1.U8V &3) == 3){
            _SET_BIT(p_active_functions, RNG_BIG_NCN_MCZR);
            stt_MTZR_And01__2_1.bool_val.bt7 = 1;
        }else{
            _CLEAR_BIT(p_active_functions, RNG_BIG_NCN_MCZR);
            stt_MTZR_And01__2_1.bool_val.bt7 = 0;
        }
        
        if(measurement[IM_Ubp] <= 5000){
            
            _SET_BIT(p_active_functions, RNG_BIG_PO_BLK_U_RSV_LESS_UN);//RNG_BIG_PO_BLK_U_OSN_LESS_0_05UN_MCZO
        }else{
            //
            _CLEAR_BIT(p_active_functions, RNG_BIG_PO_BLK_U_RSV_LESS_UN);//RNG_BIG_PO_BLK_U_OSN_LESS_0_05UN_MCZO
        }
    }
    if(glb_ch_id_mtzr == ID_MTZR1){
        
         
        stt_MTZR_Or_02__3_1.bool_val.bt0 =
        (_CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZRN1_VPERED))!=0;
        stt_MTZR_Or_02__3_1.bool_val.bt1 = 
        (_CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZRN1_NAZAD))!=0;
        stt_MTZR_Or_02__3_1.bool_val.bt2 = 
        (_CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZRPN1))!=0;
        
        
        
        if((stt_MTZR_Or_02__3_1.U8V &7) != 0)
        stt_MTZR_Not03__1_1.bool_val.bt0 = 1;
        //else  stt_MTZR_Not03__1_1.bool_val.bt0 = 0;
        stt_MTZR_Not03__1_1.bool_val.bt7 = !stt_MTZR_Not03__1_1.bool_val.bt0;
        
        stt_MTZR_And04__2_1.bool_val.bt0 = stt_MTZR_Not03__1_1.bool_val.bt7;
        stt_MTZR_And04__2_1.bool_val.bt1 = stt_MTZR_And01__2_1.bool_val.bt7;
    
        if ((stt_MTZR_And04__2_1.U8V &3) == 3){
//        _SET_BIT(p_active_functions, RNG_BIG_NCN_MCZO1);
           stt_MTZR_And04__2_1.bool_val.bt7 = 1;
           wrp_mtzr.bool_vars.cmd_nkn_mtzr134 = 1;
        }else{
//        _CLEAR_BIT(p_active_functions, RNG_BIG_NCN_MCZO1);
        
        }
        lV = (sLV.p_current_settings_prt->type_mtzr1) ;
        if(lV == TYPE_MTZ_SIMPLE){
            stt_MTZR_Or_12__4_1.bool_val.bt2 = 1;//in_mtzr_normal_selector
        }
        else if(lV == TYPE_MTZ_DIRECTIONAL){
            wrp_mtzr.bool_vars.select_mtzr134_directed = 1;
        }else{
            stt_MTZR_And16__4_1.bool_val.bt0 = 1;
        }           
        wrp_mtzr.bool_vars.dv_block_mtzr134 = (_CHECK_SET_BIT(p_active_functions, RNG_BIG_BLOCK_MCZR1))!=0;
    }
    else if(glb_ch_id_mtzr == ID_MTZR2){
        stt_MTZR_Or_02__3_1.bool_val.bt0 =
        (_CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZRN2_VPERED))!=0;
        stt_MTZR_Or_02__3_1.bool_val.bt1 = 
        (_CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZRN2_NAZAD))!=0;
        stt_MTZR_Or_02__3_1.bool_val.bt2 = 
        (_CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZRPN2))!=0;
        
        
        
        if((stt_MTZR_Or_02__3_1.U8V &7) != 0)
        stt_MTZR_Not03__1_1.bool_val.bt0 = 1;
        //else  stt_MTZR_Not03__1_1.bool_val.bt0 = 0;
        stt_MTZR_Not03__1_1.bool_val.bt7 = !stt_MTZR_Not03__1_1.bool_val.bt0;
        
        stt_MTZR_And04__2_1.bool_val.bt0 = stt_MTZR_And01__2_1.bool_val.bt7;
        lV = _CHECK_SET_BIT(p_active_functions, RNG_BIG_NCN_MCZR);
        stt_MTZR_And04__2_1.bool_val.bt1 = lV!=0;//stt_MTZR_Not03__1_1.bool_val.bt7;
    
        if ((stt_MTZR_And04__2_1.U8V &3) == 3){
//        _SET_BIT(p_active_functions, RNG_BIG_NCN_MCZO3);
        stt_MTZR_And04__2_1.bool_val.bt7 = 1;
        wrp_mtzr.bool_vars.cmd_nkn_mtzr134 = 1;
        }else{
//        _CLEAR_BIT(p_active_functions, RNG_BIG_NCN_MCZO3);
        
        }
        lV = (sLV.p_current_settings_prt->type_mtzr2) ;
        if(lV == TYPE_MTZ_SIMPLE){
            stt_MTZR_Or_12__4_1.bool_val.bt2 = 1;//in_mtzr_normal_selector
        }
        else if(lV == TYPE_MTZ_DIRECTIONAL){
            wrp_mtzr.bool_vars.select_mtzr134_directed = 1;
        }else{
            stt_MTZR_And16__4_1.bool_val.bt0 = 1;
        }           
        wrp_mtzr.bool_vars.dv_block_mtzr134 = (_CHECK_SET_BIT(p_active_functions, RNG_BIG_BLOCK_MCZR2))!=0;
    }


    
    rU = wrp_mtzr.bool_vars.dv_block_mtzr134;
    

    lV = (~rU)&1;
    if(lV != 0 && wrp_mtzr.bool_vars.m_mtzr134 !=0 )
        wrp_mtzr.bool_vars.and6_2_1_b7 = 1;
    
    
    stt_MTZR_OrN_07__2_1.bool_val.bt0 = (_CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_BLK_U_RSV_LESS_UN))!=0;
    
    rU = wrp_mtzr.bool_vars.cmd_nkn_mtzr134;
    
    stt_MTZR_OrN_07__2_1.bool_val.bt1 = rU;
    if((stt_MTZR_OrN_07__2_1.U8V &3) != 0){
       
        
        wrp_mtzr.bool_vars.or07_2_1_b7 = 0;
    }
    else{
        
        wrp_mtzr.bool_vars.or07_2_1_b7 = 1;
    }
    
    //
    lV = (~rU)&1;
    //
    
    stt_MTZR_And09__2_1.bool_val.bt0 = wrp_mtzr.bool_vars.po_mtzr134_u_pn;
    stt_MTZR_And09__2_1.bool_val.bt1 = lV;//not8
    if((stt_MTZR_And09__2_1.U8V &3) == 3){
        
        stt_MTZR_And16__4_1.bool_val.bt2 = 1;
    }
    

   rU = wrp_mtzr.bool_vars.or07_2_1_b7;
   lV = (~rU)&1;
   wrp_mtzr.bool_vars.not10_1_b7 = lV;
   
   
   
   
    stt_MTZR_And11__2_1.bool_val.bt0 = 
    wrp_mtzr.bool_vars.select_mtzr134_directed;
    stt_MTZR_And11__2_1.bool_val.bt1 =  lV;//
    lV = 0;
    if((stt_MTZR_And11__2_1.U8V &3) == 3)
        lV = 1;
    stt_MTZR_And11__2_1.bool_val.bt7 =  lV;
   
    
    stt_MTZR_Or_12__4_1.bool_val.bt0 =  lV;
    
    if(glb_ch_id_mtzr == ID_MTZR1){
    stt_MTZR_Or_12__4_1.bool_val.bt1 = 
     (_CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZR1))!=0;
    }
    else if(glb_ch_id_mtzr == ID_MTZR2){ 
        stt_MTZR_Or_12__4_1.bool_val.bt1 = 
     (_CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZR2))!=0;
    }
//?    else if(glb_ch_id_mtzr == ID_MTZR4){
//?        stt_MTZR_Or_12__4_1.bool_val.bt1 = 
//?     (_CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZO4))!=0;
//?    }       
 
    stt_MTZR_Or_12__4_1.bool_val.bt3 = stt_MTZR_And04__2_1.bool_val.bt7;
    if((stt_MTZR_Or_12__4_1.U8V &15) != 0){
        stt_MTZR_Or_12__4_1.bool_val.bt7 = lV = 1;
        //
    }

    stt_MTZR_And13__3_1.bool_val.bt0 = stt_MTZR_Or_12__4_1.bool_val.bt7;
    stt_MTZR_And13__3_1.bool_val.bt1 = wrp_mtzr.bool_vars.po_mtzr134_simple;
    stt_MTZR_And13__3_1.bool_val.bt2 = wrp_mtzr.bool_vars.and6_2_1_b7;
    if((stt_MTZR_And13__3_1.U8V &7) == 7){
        
        stt_MTZR_And13__3_1.bool_val.bt7 = 1;
    } 

    do { 
        register U8_state_wrp R_wrp; 
        R_wrp.U8V = stt_MTZR_And14__6_1.U8V;//.Load Elem State
        rU = 0;lV = 0;
        R_wrp.bool_val.bt0 = wrp_mtzr.bool_vars.select_mtzr134_directed;
        R_wrp.bool_val.bt1 = wrp_mtzr.bool_vars.and6_2_1_b7;
        R_wrp.bool_val.bt2 = wrp_mtzr.bool_vars.m_mtzr134_dir;
        R_wrp.bool_val.bt3 = wrp_mtzr.bool_vars.m_mtzr134_sector_dir;
        R_wrp.bool_val.bt4 = wrp_mtzr.bool_vars.po_mtzr134_dir;
        R_wrp.bool_val.bt5 = wrp_mtzr.bool_vars.or07_2_1_b7;
        if ((R_wrp.U8V &63) == 63) { 
            
            R_wrp.bool_val.bt7 = 1;
        } 
     

        rU = R_wrp.U8V;//

       } while (lV != 0);
         
    
    
     stt_MTZR_And14__6_1.U8V = rU;// 
     U8_state_wrp R_And15__6_1;
     R_And15__6_1.U8V = stt_MTZR_And15__6_1.U8V ;rU =0;
     R_And15__6_1.bool_val.bt0 = wrp_mtzr.bool_vars.select_mtzr134_directed;
     R_And15__6_1.bool_val.bt1 = wrp_mtzr.bool_vars.and6_2_1_b7;
     R_And15__6_1.bool_val.bt2 = wrp_mtzr.bool_vars.m_mtzr134_sector_inv;
     R_And15__6_1.bool_val.bt3 = wrp_mtzr.bool_vars.m_mtzr134_inv;
     R_And15__6_1.bool_val.bt4 = wrp_mtzr.bool_vars.or07_2_1_b7;
     R_And15__6_1.bool_val.bt5 = wrp_mtzr.bool_vars.po_mtzr134_inv;
    if((R_And15__6_1.U8V &63) == 63){
        
        R_And15__6_1.bool_val.bt7 = 1;
    }
     
    stt_MTZR_And15__6_1.U8V = R_And15__6_1.U8V;
    
    
     U8_state_wrp R_And16__4_1;
    R_And16__4_1.U8V = stt_MTZR_And16__4_1.U8V;
    
    R_And16__4_1.bool_val.bt1 = wrp_mtzr.bool_vars.and6_2_1_b7;//
    
    R_And16__4_1.bool_val.bt3 = wrp_mtzr.bool_vars.po_mtzr134_i_pn;
    if((R_And16__4_1.U8V &15) == 15){
        
        R_And16__4_1.bool_val.bt7 = 1;
    }
    
    // 
    stt_MTZR_And16__4_1.U8V = R_And16__4_1.U8V;
    //return;
    if(glb_ch_id_mtzr == ID_MTZR1){
        unsigned long u32_bit_holder = 0;
        rU = stt_MTZR_And13__3_1.bool_val.bt7;
        if(rU == 0) 
            _CLEAR_BIT(p_active_functions, RNG_BIG_PO_MCZR1);
        else{
            _SET_BIT(p_active_functions, RNG_BIG_PO_MCZR1);
            u32_bit_holder |= 1<< IDX_TMR_MTZR_IN;
        }
        if(stt_MTZR_And14__6_1.bool_val.bt7 != 0){
            _SET_BIT(p_active_functions, RNG_BIG_PO_MCZRN1_VPERED);
            u32_bit_holder |= 1<< IDX_TMR_MTZR_IN_N_VPERED;
        }else
            _CLEAR_BIT(p_active_functions, RNG_BIG_PO_MCZRN1_VPERED);
        
        if(stt_MTZR_And15__6_1.bool_val.bt7 != 0){
             _SET_BIT(p_active_functions, RNG_BIG_PO_MCZRN1_NAZAD);
            u32_bit_holder |= 1<< IDX_TMR_MTZR_IN_N_NAZAD;
        }
        else
            _CLEAR_BIT(p_active_functions, RNG_BIG_PO_MCZRN1_NAZAD);
        if(stt_MTZR_And16__4_1.bool_val.bt7 != 0){
            _SET_BIT(p_active_functions, RNG_BIG_PO_MCZRPN1);
            u32_bit_holder |= 1<< IDX_TMR_MTZR_IN_PO_NAPRUZI;
        }
        else
            _CLEAR_BIT(p_active_functions, RNG_BIG_PO_MCZRPN1);
        
        
        //
        _TIMER_T_0(INDEX_TIMER_MTZR1,sLV.p_current_settings_prt->timeout_mtzr_1[number_group_stp],
        u32_bit_holder,IDX_TMR_MTZR_IN, u32_bit_holder, IDX_TMR_MTZR_OUT);
        
        _TIMER_T_0(INDEX_TIMER_MTZR1_N_VPERED,sLV.p_current_settings_prt->timeout_mtzr_1_n_vpered[number_group_stp],
        u32_bit_holder,IDX_TMR_MTZR_IN_N_VPERED, u32_bit_holder, IDX_TMR_MTZR_OUT_N_VPERED);
        //u32_bit_holder = (stt_MTZR_And15__6_1.bool_val.bt7)<< IDX_TMR_MTZR_IN_N_NAZAD;
        _TIMER_T_0(INDEX_TIMER_MTZR1_N_NAZAD,sLV.p_current_settings_prt->timeout_mtzr_1_n_nazad[number_group_stp],
        u32_bit_holder,IDX_TMR_MTZR_IN_N_NAZAD, u32_bit_holder, IDX_TMR_MTZR_OUT_N_NAZAD);
        //u32_bit_holder = (stt_MTZR_And16__4_1.bool_val.bt7)<< IDX_TMR_MTZR_IN_PO_NAPRUZI;
        _TIMER_T_0(INDEX_TIMER_MTZR1_PO_NAPRUZI,sLV.p_current_settings_prt->timeout_mtzr_1_po_napruzi[number_group_stp],
        u32_bit_holder,IDX_TMR_MTZR_IN_PO_NAPRUZI, u32_bit_holder, IDX_TMR_MTZR_OUT_PO_NAPRUZI);
            
            
        if(u32_bit_holder&( (1<<IDX_TMR_MTZR_OUT)|(1<<IDX_TMR_MTZR_OUT_N_VPERED)
        |(1<<IDX_TMR_MTZR_OUT_N_NAZAD)|(1<<IDX_TMR_MTZR_OUT_PO_NAPRUZI) )){
            _SET_BIT(p_active_functions, RNG_BIG_MCZR1);
        }else{
            _CLEAR_BIT(p_active_functions, RNG_BIG_MCZR1);
            }               
         
    }
    else if(glb_ch_id_mtzr == ID_MTZR2){
        unsigned long u32_bit_holder = 0;
        rU = stt_MTZR_And13__3_1.bool_val.bt7;
        if(rU == 0)
            _CLEAR_BIT(p_active_functions, RNG_BIG_PO_MCZR2);
        else{
            _SET_BIT(p_active_functions, RNG_BIG_PO_MCZR2);
            u32_bit_holder |= 1<< IDX_TMR_MTZR_IN;
        }
        if(stt_MTZR_And14__6_1.bool_val.bt7 != 0){
            _SET_BIT(p_active_functions, RNG_BIG_PO_MCZRN2_VPERED);
            u32_bit_holder |= 1<< IDX_TMR_MTZR_IN_N_VPERED;
        }else
            _CLEAR_BIT(p_active_functions, RNG_BIG_PO_MCZRN2_VPERED);
        
        if(stt_MTZR_And15__6_1.bool_val.bt7 != 0){
             _SET_BIT(p_active_functions, RNG_BIG_PO_MCZRN2_NAZAD);
            u32_bit_holder |= 1<< IDX_TMR_MTZR_IN_N_NAZAD;
        }
        else
            _CLEAR_BIT(p_active_functions, RNG_BIG_PO_MCZRN2_NAZAD);
        if(stt_MTZR_And16__4_1.bool_val.bt7 != 0){
            _SET_BIT(p_active_functions, RNG_BIG_PO_MCZRPN2);
            u32_bit_holder |= 1<< IDX_TMR_MTZR_IN_PO_NAPRUZI;
        }
        else
            _CLEAR_BIT(p_active_functions, RNG_BIG_PO_MCZRPN2); 
        //u32_bit_holder = (stt_MTZR_And13__3_1.bool_val.bt7)<< IDX_TMR_MTZR_IN;
        _TIMER_T_0(INDEX_TIMER_MTZR2,sLV.p_current_settings_prt->timeout_mtzr_2[number_group_stp],
        u32_bit_holder,IDX_TMR_MTZR_IN, u32_bit_holder, IDX_TMR_MTZR_OUT);
        //u32_bit_holder = (stt_MTZR_And14__6_1.bool_val.bt7)<< IDX_TMR_MTZR_IN_N_VPERED;
        _TIMER_T_0(INDEX_TIMER_MTZR2_N_VPERED,sLV.p_current_settings_prt->timeout_mtzr_2_n_vpered[number_group_stp],
        u32_bit_holder,IDX_TMR_MTZR_IN_N_VPERED, u32_bit_holder, IDX_TMR_MTZR_OUT_N_VPERED);
        //u32_bit_holder = (stt_MTZR_And15__6_1.bool_val.bt7)<< IDX_TMR_MTZR_IN_N_NAZAD;
        _TIMER_T_0(INDEX_TIMER_MTZR2_N_NAZAD,sLV.p_current_settings_prt->timeout_mtzr_2_n_nazad[number_group_stp],
        u32_bit_holder,IDX_TMR_MTZR_IN_N_NAZAD, u32_bit_holder, IDX_TMR_MTZR_OUT_N_NAZAD);
        //u32_bit_holder = (stt_MTZR_And16__4_1.bool_val.bt7)<< IDX_TMR_MTZR_IN_PO_NAPRUZI;
        _TIMER_T_0(INDEX_TIMER_MTZR2_PO_NAPRUZI,sLV.p_current_settings_prt->timeout_mtzr_2_po_napruzi[number_group_stp],
        u32_bit_holder,IDX_TMR_MTZR_IN_PO_NAPRUZI, u32_bit_holder, IDX_TMR_MTZR_OUT_PO_NAPRUZI);
            
            
        if(u32_bit_holder&( (1<<IDX_TMR_MTZR_OUT)|(1<<IDX_TMR_MTZR_OUT_N_VPERED)
        |(1<<IDX_TMR_MTZR_OUT_N_NAZAD)|(1<<IDX_TMR_MTZR_OUT_PO_NAPRUZI) )){
            _SET_BIT(p_active_functions, RNG_BIG_MCZR2);
        }else{
            _CLEAR_BIT(p_active_functions, RNG_BIG_MCZR2);
            }               
   

    }
    
  

    
}
//
//--------------------------------------------------------------------------------------------------------

void on_off_vvo(unsigned int *p_active_functions);
//=====================================================================================================
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//                                                                                      
//....................................................................................................
//=====================================================================================================
void on_off_vvo(unsigned int *p_active_functions){ 
//?#ifdef DZ_ACTIVE
//?    static unsigned int previous_active_functions[N_BIG];
    unsigned int maska[N_BIG] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    //''''''''''''''''''''''''''''''''
    //Спочатку опрацьовуємо таймери
    //,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
    //Таймер  відключення
    if (global_timers[INDEX_TIMER_VIDKL_VVO] >= 0)
    {
        //Таймер БО зараз активний і як мінімум тільки зараз завершить свою роботу
        if (global_timers[INDEX_TIMER_VIDKL_VVO] >= current_settings_prt.timeout_swch_off_[0])
        {
            //Таймер досягнув свого максимального значення
            global_timers[INDEX_TIMER_VIDKL_VVO] = -1;
            //Відмічаємо у масиві функцій, які зараз активуються, що блок БО має бути деативованим
            _CLEAR_BIT(p_active_functions, RNG_BIG_WORK_BO_VVO);//!@_CLEAR_BIT(p_active_functions, @RANG_WORK_BO);
        }
        //Незавершена робота блоку БО означає, що таймер блокування БВ має бути запущений і знаходитися у свому початковому значенні,
        //щоб як тільки блок БО відпрацює, щоб блокування включення почалося на весь час з моменту закінчення роботи блоку БО
        global_timers[INDEX_TIMER_BLK_VKL_VVO] = 0;
    }
    
    //Таймер  блокування включення
    if (global_timers[INDEX_TIMER_BLK_VKL_VVO] >= 0)
    {
        //Таймер блокування включення БВ зараз активний і як мінімум тільки зараз завершить свою роботу
        if (global_timers[INDEX_TIMER_BLK_VKL_VVO] >= current_settings_prt.timeout_swch_udl_blk_on_[0])
        {
            //Таймер досягнув свого максимального значення
            global_timers[INDEX_TIMER_BLK_VKL_VVO] = -1;
        }
    }
    
    //Таймер  включення
    if (global_timers[INDEX_TIMER_VKL_VVO] >= 0)
    {
        //Таймер БВ зараз активний і як мінімум тільки зараз завершить свою роботу
        
        //Якщо по якійсь причині таймер включення працює, при умові, що таймери БО і блокування включення ще не скинуті, то таймер включення треба скинути
        if ((global_timers[INDEX_TIMER_VIDKL_VVO] >= 0) || (global_timers[INDEX_TIMER_BLK_VKL_VVO] >=0))
        {
            global_timers[INDEX_TIMER_VKL_VVO] = -1;
            //Відмічаємо у масиві функцій, які зараз активуються, що блок БB має бути деативованим
            _CLEAR_BIT(p_active_functions, RNG_BIG_WORK_BV_VVO);//!@_CLEAR_BIT(p_active_functions, @RANG_WORK_BV);
        }
        else
        {
            //Перевіряємо, чи таймер включення не досягнув свого масимального значення
            if (global_timers[INDEX_TIMER_VKL_VVO] >= current_settings_prt.timeout_swch_on_[0])
            {
                //Таймер досягнув свого максимального значення
                global_timers[INDEX_TIMER_VKL_VVO] = -1;
                //Відмічаємо у масиві функцій, які зараз активуються, що блок БB має бути деативованим
                _CLEAR_BIT(p_active_functions, RNG_BIG_WORK_BV_VVO);//!@_CLEAR_BIT(p_active_functions, @RANG_WORK_BV);
            }
        }
    }
    //```````````````````````````````````````````````````````````````````````````````````````````````````````````````````

    //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
    //.  Першим розглядається блок відключення, бо він може блокувати включення вимикача
    //,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
    /*
    Цей сигнал встановлюється тільки у певних випадках, тому по замовчуванню його треба 
    скинута,а коли буде потрібно - він встановиться
    */
    _CLEAR_BIT(p_active_functions, RNG_BIG_VIDKL_VID_ZAKHYSTIV_VVO);//!@_CLEAR_BIT(p_active_functions, @RANG_VIDKL_VID_ZAKHYSTIV);
    if (
            ((p_active_functions[0 ] & current_settings_prt.ranguvannja_off_cb[0 ]) != 0) ||
            ((p_active_functions[1 ] & current_settings_prt.ranguvannja_off_cb[1 ]) != 0) ||
            ((p_active_functions[2 ] & current_settings_prt.ranguvannja_off_cb[2 ]) != 0) ||
            ((p_active_functions[3 ] & current_settings_prt.ranguvannja_off_cb[3 ]) != 0) ||
            ((p_active_functions[4 ] & current_settings_prt.ranguvannja_off_cb[4 ]) != 0) ||
            ((p_active_functions[5 ] & current_settings_prt.ranguvannja_off_cb[5 ]) != 0) ||
            ((p_active_functions[6 ] & current_settings_prt.ranguvannja_off_cb[6 ]) != 0) ||
            ((p_active_functions[7 ] & current_settings_prt.ranguvannja_off_cb[7 ]) != 0) ||
            ((p_active_functions[8 ] & current_settings_prt.ranguvannja_off_cb[8 ]) != 0) ||
            ((p_active_functions[9 ] & current_settings_prt.ranguvannja_off_cb[9 ]) != 0) ||
            ((p_active_functions[10] & current_settings_prt.ranguvannja_off_cb[10]) != 0) ||
            ((p_active_functions[11] & current_settings_prt.ranguvannja_off_cb[11]) != 0) ||
            ((p_active_functions[12] & current_settings_prt.ranguvannja_off_cb[12]) != 0)
            )
    {
        //Є умова активації блку вимкнення
        _SET_BIT(p_active_functions, RNG_BIG_WORK_BO_VVO);//!@_SET_BIT(p_active_functions, @RANG_WORK_BO);
        
        //Запускаємо (або продовжуємо утримувати у 0, поки не пропаде сигнал активації БО) таймери: блоку БО, блокуванння БВ.
        global_timers[INDEX_TIMER_VIDKL_VVO  ] = 0;
        global_timers[INDEX_TIMER_BLK_VKL_VVO] = 0;
        
        //Скидаємо активацію блоку ввімкнення
        _CLEAR_BIT(p_active_functions, RNG_BIG_WORK_BV_VVO);//!@_CLEAR_BIT(p_active_functions, @RANG_WORK_BV);
        //Скидаємо таймер блку вимкнення
        global_timers[INDEX_TIMER_VKL_VVO] = -1;  
        
        /*
      Формуємо сигнал "Відключення від захистів" (він рівний наявності умови команди
      активації команди "Робота БО" будь-якою командою за виключенняв "Вимкн. ВВ")
      */
        //Формуємо інвертовану маску для виключення команди "Вимк.ВВ"
        for (unsigned int i = 0; i < N_BIG; i++ )  maska[i] = (unsigned int)(~0);
        _CLEAR_BIT(maska, RNG_BIG_OTKL_VV_VVO);//!@_CLEAR_BIT(maska, @RANG_OTKL_VV);
        _CLEAR_BIT(maska, RNG_BIG_WORK_BO_VVO);//!@_CLEAR_BIT(maska, @RANG_WORK_BO);
#ifdef VYMK_INFO
        if (
                ((p_active_functions[0 ] & maska[0 ]) != 0) ||
                ((p_active_functions[1 ] & maska[1 ]) != 0) ||
                ((p_active_functions[2 ] & maska[2 ]) != 0) ||
                ((p_active_functions[3 ] & maska[3 ]) != 0) ||
                ((p_active_functions[4 ] & maska[4 ]) != 0) ||
                ((p_active_functions[5 ] & maska[5 ]) != 0) ||
                ((p_active_functions[6 ] & maska[6 ]) != 0) ||
                ((p_active_functions[7 ] & maska[7 ]) != 0) ||
                ((p_active_functions[8 ] & maska[8 ]) != 0) ||
                ((p_active_functions[9 ] & maska[9 ]) != 0) ||
                ((p_active_functions[10] & maska[10]) != 0) ||
                ((p_active_functions[11] & maska[11]) != 0) ||
                ((p_active_functions[12] & maska[12]) != 0)
                )
        {
            //Вимкнення від захистів
            _SET_BIT(p_active_functions, RNG_BIG_VIDKL_VID_ZAKHYSTIV_VVO);//!@_SET_BIT(p_active_functions, @RANG_VIDKL_VID_ZAKHYSTIV);
            
            unsigned int temp_array_of_outputs[N_BIG];
            for (unsigned int i = 0; i < N_BIG; i++ ) temp_array_of_outputs[i] = (p_active_functions[i] & maska[i]);
            _CLEAR_BIT(temp_array_of_outputs, RNG_BIG_VIDKL_VID_ZAKHYSTIV_VVO);//!_CLEAR_BIT(temp_array_of_outputs, @RANG_VIDKL_VID_ZAKHYSTIV);
            
        /*`````````````````````````````````````````````````````
        Формуванні інформації про причину відключення для меню
        .......................................................*/
            __info_vymk info_vymk_tmp = {time_dat, time_ms};

            
            
            if(
                    (_CHECK_SET_BIT(temp_array_of_outputs, RNG_BIG_ZDZ) != 0) &&
                    (_CHECK_SET_BIT(previous_active_functions, RNG_BIG_ZDZ) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
                    )   
            {
                _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_ZDZ);
                info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_ZDZ] = info_vymk_tmp;
                
                _CLEAR_BIT(temp_array_of_outputs, RNG_BIG_ZDZ);
            }
            

            
            if(
                    (_CHECK_SET_BIT(temp_array_of_outputs, RNG_BIG_ACHR_CHAPV_VID_DV) != 0) &&
                    (_CHECK_SET_BIT(previous_active_functions, RNG_BIG_ACHR_CHAPV_VID_DV) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
                    )   
            {
                _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_ACHR_CHAPV_VID_DV);
                info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_ACHR_CHAPV_VID_DV] = info_vymk_tmp;
                
                _CLEAR_BIT(temp_array_of_outputs, RNG_BIG_ACHR_CHAPV_VID_DV);
            }
            
            //АЧР/ЧАПВ1
            //!@      if(
            //!@         (_CHECK_SET_BIT(temp_array_of_outputs, RANG_ACHR_CHAPV1) != 0) &&
            //!@         (_CHECK_SET_BIT(previous_active_functions, RANG_ACHR_CHAPV1) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
            //!@        )   
            //!@      {
            //!@        _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_ACHR_CHAPV1);
            //!@        info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_ACHR_CHAPV1] = info_vymk_tmp;
            //!@
            //!@        _CLEAR_BIT(temp_array_of_outputs, RANG_ACHR_CHAPV1);
            //!@      }
            
            if(
                    (_CHECK_SET_BIT(temp_array_of_outputs, RNG_BIG_ACHR_CHAPV1) != 0) &&
                    (_CHECK_SET_BIT(previous_active_functions, RNG_BIG_ACHR_CHAPV1) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
                    )   
            {
                _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_ACHR_CHAPV1);
                info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_ACHR_CHAPV1] = info_vymk_tmp;
                
                _CLEAR_BIT(temp_array_of_outputs, RNG_BIG_ACHR_CHAPV1);
            }
            
            //АЧР/ЧАПВ2
            //!@      if(
            //!@         (_CHECK_SET_BIT(temp_array_of_outputs, RANG_ACHR_CHAPV2) != 0) &&
            //!@         (_CHECK_SET_BIT(previous_active_functions, RANG_ACHR_CHAPV2) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
            //!@        )   
            //!@      {
            //!@        _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_ACHR_CHAPV2);
            //!@        info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_ACHR_CHAPV2] = info_vymk_tmp;
            //!@
            //!@        _CLEAR_BIT(temp_array_of_outputs, RANG_ACHR_CHAPV2);
            //!@      }
            if(
                    (_CHECK_SET_BIT(temp_array_of_outputs, RNG_BIG_ACHR_CHAPV2) != 0) &&
                    (_CHECK_SET_BIT(previous_active_functions, RNG_BIG_ACHR_CHAPV2) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
                    )   
            {
                _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_ACHR_CHAPV2);
                info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_ACHR_CHAPV2] = info_vymk_tmp;
                
                _CLEAR_BIT(temp_array_of_outputs, RNG_BIG_ACHR_CHAPV2);
            }
            
            //УРОВ1
            //!@      if(
            //!@         (_CHECK_SET_BIT(temp_array_of_outputs, RANG_UROV1) != 0) &&
            //!@         (_CHECK_SET_BIT(previous_active_functions, RANG_UROV1) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
            //!@        )   
            //!@      {
            //!@        _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_UROV1);
            //!@        info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_UROV1] = info_vymk_tmp;
            //!@
            //!@        _CLEAR_BIT(temp_array_of_outputs, RANG_UROV1);
            //!@      }
            
            if(
                    (_CHECK_SET_BIT(temp_array_of_outputs, RNG_BIG_UROV1) != 0) &&
                    (_CHECK_SET_BIT(previous_active_functions, RNG_BIG_UROV1) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
                    )   
            {
                _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_UROV1);
                info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_UROV1] = info_vymk_tmp;
                
                _CLEAR_BIT(temp_array_of_outputs, RNG_BIG_UROV1);
            }
            
            //УРОВ2
            //!@      if(
            //!@         (_CHECK_SET_BIT(temp_array_of_outputs, RANG_UROV2) != 0) &&
            //!@         (_CHECK_SET_BIT(previous_active_functions, RANG_UROV2) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
            //!@        )   
            //!@      {
            //!@        _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_UROV2);
            //!@        info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_UROV2] = info_vymk_tmp;
            //!@
            //!@        _CLEAR_BIT(temp_array_of_outputs, RANG_UROV2);
            //!@      }
            
            if(
                    (_CHECK_SET_BIT(temp_array_of_outputs, RNG_BIG_UROV2) != 0) &&
                    (_CHECK_SET_BIT(previous_active_functions, RNG_BIG_UROV2) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
                    )   
            {
                _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_UROV2);
                info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_UROV2] = info_vymk_tmp;
                
                _CLEAR_BIT(temp_array_of_outputs, RNG_BIG_UROV2);
            }
            
            //ЗОП
            //!@      if(
            //!@         (_CHECK_SET_BIT(temp_array_of_outputs, RANG_ZOP) != 0) &&
            //!@         (_CHECK_SET_BIT(previous_active_functions, RANG_ZOP) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
            //!@        )   
            //!@      {
            //!@        _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_ZOP);
            //!@        info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_ZOP] = info_vymk_tmp;
            //!@
            //!@        _CLEAR_BIT(temp_array_of_outputs, RANG_ZOP);
            //!@      }
            
            //Umin1
            //!@      if(
            //!@         (_CHECK_SET_BIT(temp_array_of_outputs, RANG_UMIN1) != 0) &&
            //!@         (_CHECK_SET_BIT(previous_active_functions, RANG_UMIN1) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
            //!@        )   
            //!@      {
            //!@        _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_UMIN1);
            //!@        info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_UMIN1] = info_vymk_tmp;
            //!@
            //!@        _CLEAR_BIT(temp_array_of_outputs, RANG_UMIN1);
            //!@      }
            
            if(
                    (_CHECK_SET_BIT(temp_array_of_outputs, RNG_BIG_UMIN1) != 0) &&
                    (_CHECK_SET_BIT(previous_active_functions, RNG_BIG_UMIN1) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
                    )   
            {
                _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_UMIN1);
                info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_UMIN1] = info_vymk_tmp;
                
                _CLEAR_BIT(temp_array_of_outputs, RNG_BIG_UMIN1);
            }
            
            //Umin2
            //!@      if(
            //!@         (_CHECK_SET_BIT(temp_array_of_outputs, RANG_UMIN2) != 0) &&
            //!@         (_CHECK_SET_BIT(previous_active_functions, RANG_UMIN2) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
            //!@        )   
            //!@      {
            //!@        _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_UMIN2);
            //!@        info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_UMIN2] = info_vymk_tmp;
            //!@
            //!@        _CLEAR_BIT(temp_array_of_outputs, RANG_UMIN2);
            //!@      }
            
            if(
                    (_CHECK_SET_BIT(temp_array_of_outputs, RNG_BIG_UMIN2) != 0) &&
                    (_CHECK_SET_BIT(previous_active_functions, RNG_BIG_UMIN2) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
                    )   
            {
                _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_UMIN2);
                info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_UMIN2] = info_vymk_tmp;
                
                _CLEAR_BIT(temp_array_of_outputs, RNG_BIG_UMIN2);
            }
            
            //Umax1
            //!@      if(
            //!@         (_CHECK_SET_BIT(temp_array_of_outputs, RANG_UMAX1) != 0) &&
            //!@         (_CHECK_SET_BIT(previous_active_functions, RANG_UMAX1) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
            //!@        )   
            //!@      {
            //!@        _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_UMAX1);
            //!@        info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_UMAX1] = info_vymk_tmp;
            //!@
            //!@        _CLEAR_BIT(temp_array_of_outputs, RANG_UMAX1);
            //!@      }
            
            if(
                    (_CHECK_SET_BIT(temp_array_of_outputs, RNG_BIG_UMAX1) != 0) &&
                    (_CHECK_SET_BIT(previous_active_functions, RNG_BIG_UMAX1) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
                    )   
            {
                _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_UMAX1);
                info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_UMAX1] = info_vymk_tmp;
                
                _CLEAR_BIT(temp_array_of_outputs, RNG_BIG_UMAX1);
            }
            
            //Umax2
            //!@      if(
            //!@         (_CHECK_SET_BIT(temp_array_of_outputs, RANG_UMAX2) != 0) &&
            //!@         (_CHECK_SET_BIT(previous_active_functions, RANG_UMAX2) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
            //!@        )   
            //!@      {
            //!@        _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_UMAX2);
            //!@        info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_UMAX2] = info_vymk_tmp;
            //!@
            //!@        _CLEAR_BIT(temp_array_of_outputs, RANG_UMAX2);
            //!@      }
            if(
                    (_CHECK_SET_BIT(temp_array_of_outputs, RNG_BIG_UMAX2) != 0) &&
                    (_CHECK_SET_BIT(previous_active_functions, RNG_BIG_UMAX2) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
                    )   
            {
                _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_UMAX2);
                info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_UMAX2] = info_vymk_tmp;
                
                _CLEAR_BIT(temp_array_of_outputs, RNG_BIG_UMAX2);
            }
            
            //Універсальний захист
            //!@      for (size_t n_UP = 0; n_UP < NUMBER_UP; n_UP++)
            //!@      {
            //!@        if(
            //!@           (_CHECK_SET_BIT(temp_array_of_outputs, (RANG_UP1 + 3*n_UP)) != 0) &&
            //!@           (_CHECK_SET_BIT(previous_active_functions, (RANG_UP1 + 3*n_UP)) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
            //!@          )   
            //!@        {
            //!@          _SET_BIT(info_vidkluchennja_vymykacha, (VYMKNENNJA_VID_UP1 + n_UP));
            //!@          info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_UP1 + n_UP] = info_vymk_tmp;
            //!@
            //!@          _CLEAR_BIT(temp_array_of_outputs, (RANG_UP1 + 3*n_UP));
            //!@        }
            //!@      }
            for (size_t n_UP = 0; n_UP < NUMBER_UP; n_UP++)
            {
                if(
                        (_CHECK_SET_BIT(temp_array_of_outputs, (RNG_BIG_UP1 + 3*n_UP)) != 0) &&
                        (_CHECK_SET_BIT(previous_active_functions, (RNG_BIG_UP1 + 3*n_UP)) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
                        )   
                {
                    _SET_BIT(info_vidkluchennja_vymykacha, (VYMKNENNJA_VID_UP1 + n_UP));
                    info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_UP1 + n_UP] = info_vymk_tmp;
                    
                    _CLEAR_BIT(temp_array_of_outputs, (RNG_BIG_UP1 + 3*n_UP));
                }
            }
            
            //Відключення від зовнішніх захистів
            //!@      if(
            //!@         (_CHECK_SET_BIT(temp_array_of_outputs, RANG_OTKL_VID_ZOVN_ZAHYSTIV) != 0) &&
            //!@         (_CHECK_SET_BIT(previous_active_functions, RANG_OTKL_VID_ZOVN_ZAHYSTIV) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
            //!@        )   
            //!@      {
            //!@        _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_ZOVNISHNIKH_ZAKHYSTIV);
            //!@        info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_ZOVNISHNIKH_ZAKHYSTIV] = info_vymk_tmp;
            //!@
            //!@        _CLEAR_BIT(temp_array_of_outputs, RANG_OTKL_VID_ZOVN_ZAHYSTIV);
            //!@      }
            
            //Відключення від інших сигналів (крім відключення від сигналу "Вимк.ВВ")
            if(
                    (
                        (temp_array_of_outputs[0 ] != 0) ||
                        (temp_array_of_outputs[1 ] != 0) ||
                        (temp_array_of_outputs[2 ] != 0) ||
                        (temp_array_of_outputs[3 ] != 0) ||
                        (temp_array_of_outputs[4 ] != 0) ||
                        (temp_array_of_outputs[5 ] != 0) ||
                        (temp_array_of_outputs[6 ] != 0) ||
                        (temp_array_of_outputs[7 ] != 0) ||
                        (temp_array_of_outputs[8 ] != 0) ||
                        (temp_array_of_outputs[9 ] != 0) ||
                        (temp_array_of_outputs[10] != 0) ||
                        (temp_array_of_outputs[11] != 0) ||
                        (temp_array_of_outputs[12] != 0)
                        )
                    &&
                    (
                        ((previous_active_functions[0 ] & temp_array_of_outputs[0 ])!= temp_array_of_outputs[0 ]) ||
                        ((previous_active_functions[1 ] & temp_array_of_outputs[1 ])!= temp_array_of_outputs[1 ]) ||
                        ((previous_active_functions[2 ] & temp_array_of_outputs[2 ])!= temp_array_of_outputs[2 ]) ||
                        ((previous_active_functions[3 ] & temp_array_of_outputs[3 ])!= temp_array_of_outputs[3 ]) ||
                        ((previous_active_functions[4 ] & temp_array_of_outputs[4 ])!= temp_array_of_outputs[4 ]) ||
                        ((previous_active_functions[5 ] & temp_array_of_outputs[5 ])!= temp_array_of_outputs[5 ]) ||
                        ((previous_active_functions[6 ] & temp_array_of_outputs[6 ])!= temp_array_of_outputs[6 ]) ||
                        ((previous_active_functions[7 ] & temp_array_of_outputs[7 ])!= temp_array_of_outputs[7 ]) ||
                        ((previous_active_functions[8 ] & temp_array_of_outputs[8 ])!= temp_array_of_outputs[8 ]) ||
                        ((previous_active_functions[9 ] & temp_array_of_outputs[9 ])!= temp_array_of_outputs[9 ]) ||
                        ((previous_active_functions[10] & temp_array_of_outputs[10])!= temp_array_of_outputs[10]) ||
                        ((previous_active_functions[11] & temp_array_of_outputs[11])!= temp_array_of_outputs[11]) ||
                        ((previous_active_functions[12] & temp_array_of_outputs[12])!= temp_array_of_outputs[12])
                        ) 
                    )   
            {
                _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_INSHYKH_SYGNALIV);
                info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_INSHYKH_SYGNALIV] = info_vymk_tmp;
            }
            //............................................................................................................
		
        }
#endif
    }
    
    //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
    //Потім розглядається блок включення
    //,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
    if (
            (global_timers[INDEX_TIMER_VIDKL_VVO  ] < 0) && 
            (global_timers[INDEX_TIMER_BLK_VKL_VVO] < 0) &&
            //!@(_CHECK_SET_BIT(p_active_functions, @RANG_BLOCK_VKL_VV) == 0)
            (_CHECK_SET_BIT(p_active_functions, RNG_BIG_BLOCK_VKL_VVO) == 0)
            )
    {
        //Оскільки не працюють таймери БО і блокування включення БВ, а також немає сигналу блокування включення ВВ
        //тому перевіряємо, чи немає умови запуску БВ
        
        if (
                ((p_active_functions[0 ] & current_settings_prt.ranguvannja_on_cb[0 ]) != 0) ||
                ((p_active_functions[1 ] & current_settings_prt.ranguvannja_on_cb[1 ]) != 0) ||
                ((p_active_functions[2 ] & current_settings_prt.ranguvannja_on_cb[2 ]) != 0) ||
                ((p_active_functions[3 ] & current_settings_prt.ranguvannja_on_cb[3 ]) != 0) ||
                ((p_active_functions[4 ] & current_settings_prt.ranguvannja_on_cb[4 ]) != 0) ||
                ((p_active_functions[5 ] & current_settings_prt.ranguvannja_on_cb[5 ]) != 0) ||
                ((p_active_functions[6 ] & current_settings_prt.ranguvannja_on_cb[6 ]) != 0) ||
                ((p_active_functions[7 ] & current_settings_prt.ranguvannja_on_cb[7 ]) != 0) ||
                ((p_active_functions[8 ] & current_settings_prt.ranguvannja_on_cb[8 ]) != 0) ||
                ((p_active_functions[9 ] & current_settings_prt.ranguvannja_on_cb[9 ]) != 0) ||
                ((p_active_functions[10] & current_settings_prt.ranguvannja_on_cb[10]) != 0) ||
                ((p_active_functions[11] & current_settings_prt.ranguvannja_on_cb[11]) != 0) ||
                ((p_active_functions[12] & current_settings_prt.ranguvannja_on_cb[12]) != 0)
                )
        {
            //Відмічаємо у масиві функцій, які зараз активуються, що ще треба активувати блок БВ (якщо він ще не активний)
            _SET_BIT(p_active_functions, RNG_BIG_WORK_BV_VVO);//!@RANG_WORK_BV
            
            //Запускаємо (або продовжуємо утримувати у 0, поки не пропаде сигнал активації БВ) таймер роботи БВ
            global_timers[INDEX_TIMER_VKL_VVO] = 0;
        }
    }
    else
    {
        //На даний момент існує одна або більше умов блокування БВ
        global_timers[INDEX_TIMER_VKL_VVO] = -1;
        _CLEAR_BIT(p_active_functions, RNG_BIG_WORK_BV_VVO);//!@RANG_WORK_BV
    }
    //........................
    
    //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
    //Формуємо попереденій стан сигналів для функції ввімкнення/вимкнення
    //,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
    //?for (unsigned int i = 0; i < N_BIG; i++) previous_active_functions[i] = p_active_functions[i];
    //........................
//?#endif
}
//
//--------------------------------------------------------------------------------------------------------


void on_off_vvr(unsigned int *p_active_functions);
//=====================================================================================================
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//                  
//....................................................................................................
//=====================================================================================================
void on_off_vvr(unsigned int *p_active_functions){
	(void)p_active_functions;
//?	 static unsigned int previous_active_functions[N_BIG];
    unsigned int maska[N_BIG] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    //''''''''''''''''''''''''''''''''
    //Спочатку опрацьовуємо таймери
    //,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
    //Таймер  відключення
    if (global_timers[INDEX_TIMER_VIDKL_VVR] >= 0)
    {
        //Таймер БО зараз активний і як мінімум тільки зараз завершить свою роботу
        if (global_timers[INDEX_TIMER_VIDKL_VVR] >= current_settings_prt.timeout_swch_off_[1])
        {
            //Таймер досягнув свого максимального значення
            global_timers[INDEX_TIMER_VIDKL_VVR] = -1;
            //Відмічаємо у масиві функцій, які зараз активуються, що блок БО має бути деативованим
            _CLEAR_BIT(p_active_functions, RNG_BIG_WORK_BO_VVR);//!@_CLEAR_BIT(p_active_functions, @RANG_WORK_BO);
        }
        //Незавершена робота блоку БО означає, що таймер блокування БВ має бути запущений і знаходитися у свому початковому значенні,
        //щоб як тільки блок БО відпрацює, щоб блокування включення почалося на весь час з моменту закінчення роботи блоку БО
        global_timers[INDEX_TIMER_BLK_VKL_VVR] = 0;
    }
    
    //Таймер  блокування включення
    if (global_timers[INDEX_TIMER_BLK_VKL_VVR] >= 0)
    {
        //Таймер блокування включення БВ зараз активний і як мінімум тільки зараз завершить свою роботу
        if (global_timers[INDEX_TIMER_BLK_VKL_VVR] >= current_settings_prt.timeout_swch_udl_blk_on_[1])
        {
            //Таймер досягнув свого максимального значення
            global_timers[INDEX_TIMER_BLK_VKL_VVR] = -1;
        }
    }
    
    //Таймер  включення
    if (global_timers[INDEX_TIMER_VKL_VVR] >= 0)
    {
        //Таймер БВ зараз активний і як мінімум тільки зараз завершить свою роботу
        
        //Якщо по якійсь причині таймер включення працює, при умові, що таймери БО і блокування включення ще не скинуті, то таймер включення треба скинути
        if ((global_timers[INDEX_TIMER_VIDKL_VVR] >= 0) || (global_timers[INDEX_TIMER_BLK_VKL_VVR] >=0))
        {
            global_timers[INDEX_TIMER_VKL_VVR] = -1;
            //Відмічаємо у масиві функцій, які зараз активуються, що блок БB має бути деативованим
            _CLEAR_BIT(p_active_functions, RNG_BIG_WORK_BV_VVR);//!@_CLEAR_BIT(p_active_functions, @RANG_WORK_BV);
        }
        else
        {
            //Перевіряємо, чи таймер включення не досягнув свого масимального значення
            if (global_timers[INDEX_TIMER_VKL_VVR] >= current_settings_prt.timeout_swch_on_[1])
            {
                //Таймер досягнув свого максимального значення
                global_timers[INDEX_TIMER_VKL_VVR] = -1;
                //Відмічаємо у масиві функцій, які зараз активуються, що блок БB має бути деативованим
                _CLEAR_BIT(p_active_functions, RNG_BIG_WORK_BV_VVR);//!@_CLEAR_BIT(p_active_functions, @RANG_WORK_BV);
            }
        }
    }
    //```````````````````````````````````````````````````````````````````````````````````````````````````````````````````

    //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
    //.  Першим розглядається блок відключення, бо він може блокувати включення вимикача
    //,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
    /*
    Цей сигнал встановлюється тільки у певних випадках, тому по замовчуванню його треба 
    скинута,а коли буде потрібно - він встановиться
    */
    _CLEAR_BIT(p_active_functions, RNG_BIG_VIDKL_VID_ZAKHYSTIV_VVR);//!@_CLEAR_BIT(p_active_functions, @RANG_VIDKL_VID_ZAKHYSTIV);
    if (
            ((p_active_functions[0 ] & current_settings_prt.ranguvannja_off_cb[0 ]) != 0) ||
            ((p_active_functions[1 ] & current_settings_prt.ranguvannja_off_cb[1 ]) != 0) ||
            ((p_active_functions[2 ] & current_settings_prt.ranguvannja_off_cb[2 ]) != 0) ||
            ((p_active_functions[3 ] & current_settings_prt.ranguvannja_off_cb[3 ]) != 0) ||
            ((p_active_functions[4 ] & current_settings_prt.ranguvannja_off_cb[4 ]) != 0) ||
            ((p_active_functions[5 ] & current_settings_prt.ranguvannja_off_cb[5 ]) != 0) ||
            ((p_active_functions[6 ] & current_settings_prt.ranguvannja_off_cb[6 ]) != 0) ||
            ((p_active_functions[7 ] & current_settings_prt.ranguvannja_off_cb[7 ]) != 0) ||
            ((p_active_functions[8 ] & current_settings_prt.ranguvannja_off_cb[8 ]) != 0) ||
            ((p_active_functions[9 ] & current_settings_prt.ranguvannja_off_cb[9 ]) != 0) ||
            ((p_active_functions[10] & current_settings_prt.ranguvannja_off_cb[10]) != 0) ||
            ((p_active_functions[11] & current_settings_prt.ranguvannja_off_cb[11]) != 0) ||
            ((p_active_functions[12] & current_settings_prt.ranguvannja_off_cb[12]) != 0)
            )
    {
        //Є умова активації блку вимкнення
        _SET_BIT(p_active_functions, RNG_BIG_WORK_BO_VVR);//!@_SET_BIT(p_active_functions, @RANG_WORK_BO);
        
        //Запускаємо (або продовжуємо утримувати у 0, поки не пропаде сигнал активації БО) таймери: блоку БО, блокуванння БВ.
        global_timers[INDEX_TIMER_VIDKL_VVR  ] = 0;
        global_timers[INDEX_TIMER_BLK_VKL_VVR] = 0;
        
        //Скидаємо активацію блоку ввімкнення
        _CLEAR_BIT(p_active_functions, RNG_BIG_WORK_BV_VVR);//!@_CLEAR_BIT(p_active_functions, @RANG_WORK_BV);
        //Скидаємо таймер блку вимкнення
        global_timers[INDEX_TIMER_VKL_VVR] = -1;  
        
        /*
      Формуємо сигнал "Відключення від захистів" (він рівний наявності умови команди
      активації команди "Робота БО" будь-якою командою за виключенняв "Вимкн. ВВ")
      */
        //Формуємо інвертовану маску для виключення команди "Вимк.ВВ"
        for (unsigned int i = 0; i < N_BIG; i++ )  maska[i] = (unsigned int)(~0);
        _CLEAR_BIT(maska, RNG_BIG_OTKL_VV_VVR);//!@_CLEAR_BIT(maska, @RANG_OTKL_VV);
        _CLEAR_BIT(maska, RNG_BIG_WORK_BO_VVR);//!@_CLEAR_BIT(maska, @RANG_WORK_BO);
#ifdef VYMK_INFO
        if (
                ((p_active_functions[0 ] & maska[0 ]) != 0) ||
                ((p_active_functions[1 ] & maska[1 ]) != 0) ||
                ((p_active_functions[2 ] & maska[2 ]) != 0) ||
                ((p_active_functions[3 ] & maska[3 ]) != 0) ||
                ((p_active_functions[4 ] & maska[4 ]) != 0) ||
                ((p_active_functions[5 ] & maska[5 ]) != 0) ||
                ((p_active_functions[6 ] & maska[6 ]) != 0) ||
                ((p_active_functions[7 ] & maska[7 ]) != 0) ||
                ((p_active_functions[8 ] & maska[8 ]) != 0) ||
                ((p_active_functions[9 ] & maska[9 ]) != 0) ||
                ((p_active_functions[10] & maska[10]) != 0) ||
                ((p_active_functions[11] & maska[11]) != 0) ||
                ((p_active_functions[12] & maska[12]) != 0)
                )
        {
            //Вимкнення від захистів
            _SET_BIT(p_active_functions, RNG_BIG_VIDKL_VID_ZAKHYSTIV_VVR);//!@_SET_BIT(p_active_functions, @RANG_VIDKL_VID_ZAKHYSTIV);
            
            unsigned int temp_array_of_outputs[N_BIG];
            for (unsigned int i = 0; i < N_BIG; i++ ) temp_array_of_outputs[i] = (p_active_functions[i] & maska[i]);
            _CLEAR_BIT(temp_array_of_outputs, RNG_BIG_VIDKL_VID_ZAKHYSTIV_VVR);//!_CLEAR_BIT(temp_array_of_outputs, @RANG_VIDKL_VID_ZAKHYSTIV);
            
        /*`````````````````````````````````````````````````````
        Формуванні інформації про причину відключення для меню
        .......................................................*/
            __info_vymk info_vymk_tmp = {time_dat, time_ms};
    
            //ЗДЗ
            //!@      if(
            //!@         (_CHECK_SET_BIT(temp_array_of_outputs, RANG_ZDZ) != 0) &&
            //!@         (_CHECK_SET_BIT(previous_active_functions, RANG_ZDZ) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
            //!@        )   
            //!@      {
            //!@        _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_ZDZ);
            //!@        info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_ZDZ] = info_vymk_tmp;
            //!@
            //!@        _CLEAR_BIT(temp_array_of_outputs, RANG_ZDZ);
            //!@      }
            
            if(
                    (_CHECK_SET_BIT(temp_array_of_outputs, RNG_BIG_ZDZ) != 0) &&
                    (_CHECK_SET_BIT(previous_active_functions, RNG_BIG_ZDZ) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
                    )   
            {
                _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_ZDZ);
                info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_ZDZ] = info_vymk_tmp;
                
                _CLEAR_BIT(temp_array_of_outputs, RNG_BIG_ZDZ);
            }
            

            
            //АЧР/ЧАПВ від ДВ
            //!@      if(
            //!@         (_CHECK_SET_BIT(temp_array_of_outputs, RANG_ACHR_CHAPV_VID_DV) != 0) &&
            //!@         (_CHECK_SET_BIT(previous_active_functions, RANG_ACHR_CHAPV_VID_DV) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
            //!@        )   
            //!@      {
            //!@        _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_ACHR_CHAPV_VID_DV);
            //!@        info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_ACHR_CHAPV_VID_DV] = info_vymk_tmp;
            //!@
            //!@        _CLEAR_BIT(temp_array_of_outputs, RANG_ACHR_CHAPV_VID_DV);
            //!@      }
            
            if(
                    (_CHECK_SET_BIT(temp_array_of_outputs, RNG_BIG_ACHR_CHAPV_VID_DV) != 0) &&
                    (_CHECK_SET_BIT(previous_active_functions, RNG_BIG_ACHR_CHAPV_VID_DV) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
                    )   
            {
                _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_ACHR_CHAPV_VID_DV);
                info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_ACHR_CHAPV_VID_DV] = info_vymk_tmp;
                
                _CLEAR_BIT(temp_array_of_outputs, RNG_BIG_ACHR_CHAPV_VID_DV);
            }
            
            //АЧР/ЧАПВ1
            //!@      if(
            //!@         (_CHECK_SET_BIT(temp_array_of_outputs, RANG_ACHR_CHAPV1) != 0) &&
            //!@         (_CHECK_SET_BIT(previous_active_functions, RANG_ACHR_CHAPV1) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
            //!@        )   
            //!@      {
            //!@        _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_ACHR_CHAPV1);
            //!@        info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_ACHR_CHAPV1] = info_vymk_tmp;
            //!@
            //!@        _CLEAR_BIT(temp_array_of_outputs, RANG_ACHR_CHAPV1);
            //!@      }
            
            if(
                    (_CHECK_SET_BIT(temp_array_of_outputs, RNG_BIG_ACHR_CHAPV1) != 0) &&
                    (_CHECK_SET_BIT(previous_active_functions, RNG_BIG_ACHR_CHAPV1) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
                    )   
            {
                _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_ACHR_CHAPV1);
                info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_ACHR_CHAPV1] = info_vymk_tmp;
                
                _CLEAR_BIT(temp_array_of_outputs, RNG_BIG_ACHR_CHAPV1);
            }
            
            //АЧР/ЧАПВ2
            //!@      if(
            //!@         (_CHECK_SET_BIT(temp_array_of_outputs, RANG_ACHR_CHAPV2) != 0) &&
            //!@         (_CHECK_SET_BIT(previous_active_functions, RANG_ACHR_CHAPV2) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
            //!@        )   
            //!@      {
            //!@        _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_ACHR_CHAPV2);
            //!@        info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_ACHR_CHAPV2] = info_vymk_tmp;
            //!@
            //!@        _CLEAR_BIT(temp_array_of_outputs, RANG_ACHR_CHAPV2);
            //!@      }
            if(
                    (_CHECK_SET_BIT(temp_array_of_outputs, RNG_BIG_ACHR_CHAPV2) != 0) &&
                    (_CHECK_SET_BIT(previous_active_functions, RNG_BIG_ACHR_CHAPV2) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
                    )   
            {
                _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_ACHR_CHAPV2);
                info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_ACHR_CHAPV2] = info_vymk_tmp;
                
                _CLEAR_BIT(temp_array_of_outputs, RNG_BIG_ACHR_CHAPV2);
            }
            
            //УРОВ1
            //!@      if(
            //!@         (_CHECK_SET_BIT(temp_array_of_outputs, RANG_UROV1) != 0) &&
            //!@         (_CHECK_SET_BIT(previous_active_functions, RANG_UROV1) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
            //!@        )   
            //!@      {
            //!@        _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_UROV1);
            //!@        info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_UROV1] = info_vymk_tmp;
            //!@
            //!@        _CLEAR_BIT(temp_array_of_outputs, RANG_UROV1);
            //!@      }
            
            if(
                    (_CHECK_SET_BIT(temp_array_of_outputs, RNG_BIG_UROV1) != 0) &&
                    (_CHECK_SET_BIT(previous_active_functions, RNG_BIG_UROV1) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
                    )   
            {
                _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_UROV1);
                info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_UROV1] = info_vymk_tmp;
                
                _CLEAR_BIT(temp_array_of_outputs, RNG_BIG_UROV1);
            }
            
            //УРОВ2
            //!@      if(
            //!@         (_CHECK_SET_BIT(temp_array_of_outputs, RANG_UROV2) != 0) &&
            //!@         (_CHECK_SET_BIT(previous_active_functions, RANG_UROV2) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
            //!@        )   
            //!@      {
            //!@        _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_UROV2);
            //!@        info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_UROV2] = info_vymk_tmp;
            //!@
            //!@        _CLEAR_BIT(temp_array_of_outputs, RANG_UROV2);
            //!@      }
            
            if(
                    (_CHECK_SET_BIT(temp_array_of_outputs, RNG_BIG_UROV2) != 0) &&
                    (_CHECK_SET_BIT(previous_active_functions, RNG_BIG_UROV2) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
                    )   
            {
                _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_UROV2);
                info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_UROV2] = info_vymk_tmp;
                
                _CLEAR_BIT(temp_array_of_outputs, RNG_BIG_UROV2);
            }
            
            //ЗОП
            //!@      if(
            //!@         (_CHECK_SET_BIT(temp_array_of_outputs, RANG_ZOP) != 0) &&
            //!@         (_CHECK_SET_BIT(previous_active_functions, RANG_ZOP) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
            //!@        )   
            //!@      {
            //!@        _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_ZOP);
            //!@        info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_ZOP] = info_vymk_tmp;
            //!@
            //!@        _CLEAR_BIT(temp_array_of_outputs, RANG_ZOP);
            //!@      }
            
            //Umin1
            //!@      if(
            //!@         (_CHECK_SET_BIT(temp_array_of_outputs, RANG_UMIN1) != 0) &&
            //!@         (_CHECK_SET_BIT(previous_active_functions, RANG_UMIN1) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
            //!@        )   
            //!@      {
            //!@        _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_UMIN1);
            //!@        info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_UMIN1] = info_vymk_tmp;
            //!@
            //!@        _CLEAR_BIT(temp_array_of_outputs, RANG_UMIN1);
            //!@      }
            
            if(
                    (_CHECK_SET_BIT(temp_array_of_outputs, RNG_BIG_UMIN1) != 0) &&
                    (_CHECK_SET_BIT(previous_active_functions, RNG_BIG_UMIN1) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
                    )   
            {
                _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_UMIN1);
                info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_UMIN1] = info_vymk_tmp;
                
                _CLEAR_BIT(temp_array_of_outputs, RNG_BIG_UMIN1);
            }
            
            //Umin2
            //!@      if(
            //!@         (_CHECK_SET_BIT(temp_array_of_outputs, RANG_UMIN2) != 0) &&
            //!@         (_CHECK_SET_BIT(previous_active_functions, RANG_UMIN2) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
            //!@        )   
            //!@      {
            //!@        _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_UMIN2);
            //!@        info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_UMIN2] = info_vymk_tmp;
            //!@
            //!@        _CLEAR_BIT(temp_array_of_outputs, RANG_UMIN2);
            //!@      }
            
            if(
                    (_CHECK_SET_BIT(temp_array_of_outputs, RNG_BIG_UMIN2) != 0) &&
                    (_CHECK_SET_BIT(previous_active_functions, RNG_BIG_UMIN2) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
                    )   
            {
                _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_UMIN2);
                info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_UMIN2] = info_vymk_tmp;
                
                _CLEAR_BIT(temp_array_of_outputs, RNG_BIG_UMIN2);
            }
            
            //Umax1
            //!@      if(
            //!@         (_CHECK_SET_BIT(temp_array_of_outputs, RANG_UMAX1) != 0) &&
            //!@         (_CHECK_SET_BIT(previous_active_functions, RANG_UMAX1) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
            //!@        )   
            //!@      {
            //!@        _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_UMAX1);
            //!@        info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_UMAX1] = info_vymk_tmp;
            //!@
            //!@        _CLEAR_BIT(temp_array_of_outputs, RANG_UMAX1);
            //!@      }
            
            if(
                    (_CHECK_SET_BIT(temp_array_of_outputs, RNG_BIG_UMAX1) != 0) &&
                    (_CHECK_SET_BIT(previous_active_functions, RNG_BIG_UMAX1) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
                    )   
            {
                _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_UMAX1);
                info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_UMAX1] = info_vymk_tmp;
                
                _CLEAR_BIT(temp_array_of_outputs, RNG_BIG_UMAX1);
            }
            
            //Umax2
            //!@      if(
            //!@         (_CHECK_SET_BIT(temp_array_of_outputs, RANG_UMAX2) != 0) &&
            //!@         (_CHECK_SET_BIT(previous_active_functions, RANG_UMAX2) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
            //!@        )   
            //!@      {
            //!@        _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_UMAX2);
            //!@        info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_UMAX2] = info_vymk_tmp;
            //!@
            //!@        _CLEAR_BIT(temp_array_of_outputs, RANG_UMAX2);
            //!@      }
            if(
                    (_CHECK_SET_BIT(temp_array_of_outputs, RNG_BIG_UMAX2) != 0) &&
                    (_CHECK_SET_BIT(previous_active_functions, RNG_BIG_UMAX2) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
                    )   
            {
                _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_UMAX2);
                info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_UMAX2] = info_vymk_tmp;
                
                _CLEAR_BIT(temp_array_of_outputs, RNG_BIG_UMAX2);
            }
            
            //Універсальний захист
            //!@      for (size_t n_UP = 0; n_UP < NUMBER_UP; n_UP++)
            //!@      {
            //!@        if(
            //!@           (_CHECK_SET_BIT(temp_array_of_outputs, (RANG_UP1 + 3*n_UP)) != 0) &&
            //!@           (_CHECK_SET_BIT(previous_active_functions, (RANG_UP1 + 3*n_UP)) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
            //!@          )   
            //!@        {
            //!@          _SET_BIT(info_vidkluchennja_vymykacha, (VYMKNENNJA_VID_UP1 + n_UP));
            //!@          info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_UP1 + n_UP] = info_vymk_tmp;
            //!@
            //!@          _CLEAR_BIT(temp_array_of_outputs, (RANG_UP1 + 3*n_UP));
            //!@        }
            //!@      }
            for (size_t n_UP = 0; n_UP < NUMBER_UP; n_UP++)
            {
                if(
                        (_CHECK_SET_BIT(temp_array_of_outputs, (RNG_BIG_UP1 + 3*n_UP)) != 0) &&
                        (_CHECK_SET_BIT(previous_active_functions, (RNG_BIG_UP1 + 3*n_UP)) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
                        )   
                {
                    _SET_BIT(info_vidkluchennja_vymykacha, (VYMKNENNJA_VID_UP1 + n_UP));
                    info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_UP1 + n_UP] = info_vymk_tmp;
                    
                    _CLEAR_BIT(temp_array_of_outputs, (RNG_BIG_UP1 + 3*n_UP));
                }
            }
            
            //Відключення від зовнішніх захистів
            //!@      if(
            //!@         (_CHECK_SET_BIT(temp_array_of_outputs, RANG_OTKL_VID_ZOVN_ZAHYSTIV) != 0) &&
            //!@         (_CHECK_SET_BIT(previous_active_functions, RANG_OTKL_VID_ZOVN_ZAHYSTIV) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
            //!@        )   
            //!@      {
            //!@        _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_ZOVNISHNIKH_ZAKHYSTIV);
            //!@        info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_ZOVNISHNIKH_ZAKHYSTIV] = info_vymk_tmp;
            //!@
            //!@        _CLEAR_BIT(temp_array_of_outputs, RANG_OTKL_VID_ZOVN_ZAHYSTIV);
            //!@      }
            
            //Відключення від інших сигналів (крім відключення від сигналу "Вимк.ВВ")
            if(
                    (
                        (temp_array_of_outputs[0 ] != 0) ||
                        (temp_array_of_outputs[1 ] != 0) ||
                        (temp_array_of_outputs[2 ] != 0) ||
                        (temp_array_of_outputs[3 ] != 0) ||
                        (temp_array_of_outputs[4 ] != 0) ||
                        (temp_array_of_outputs[5 ] != 0) ||
                        (temp_array_of_outputs[6 ] != 0) ||
                        (temp_array_of_outputs[7 ] != 0) ||
                        (temp_array_of_outputs[8 ] != 0) ||
                        (temp_array_of_outputs[9 ] != 0) ||
                        (temp_array_of_outputs[10] != 0) ||
                        (temp_array_of_outputs[11] != 0) ||
                        (temp_array_of_outputs[12] != 0)
                        )
                    &&
                    (
                        ((previous_active_functions[0 ] & temp_array_of_outputs[0 ])!= temp_array_of_outputs[0 ]) ||
                        ((previous_active_functions[1 ] & temp_array_of_outputs[1 ])!= temp_array_of_outputs[1 ]) ||
                        ((previous_active_functions[2 ] & temp_array_of_outputs[2 ])!= temp_array_of_outputs[2 ]) ||
                        ((previous_active_functions[3 ] & temp_array_of_outputs[3 ])!= temp_array_of_outputs[3 ]) ||
                        ((previous_active_functions[4 ] & temp_array_of_outputs[4 ])!= temp_array_of_outputs[4 ]) ||
                        ((previous_active_functions[5 ] & temp_array_of_outputs[5 ])!= temp_array_of_outputs[5 ]) ||
                        ((previous_active_functions[6 ] & temp_array_of_outputs[6 ])!= temp_array_of_outputs[6 ]) ||
                        ((previous_active_functions[7 ] & temp_array_of_outputs[7 ])!= temp_array_of_outputs[7 ]) ||
                        ((previous_active_functions[8 ] & temp_array_of_outputs[8 ])!= temp_array_of_outputs[8 ]) ||
                        ((previous_active_functions[9 ] & temp_array_of_outputs[9 ])!= temp_array_of_outputs[9 ]) ||
                        ((previous_active_functions[10] & temp_array_of_outputs[10])!= temp_array_of_outputs[10]) ||
                        ((previous_active_functions[11] & temp_array_of_outputs[11])!= temp_array_of_outputs[11]) ||
                        ((previous_active_functions[12] & temp_array_of_outputs[12])!= temp_array_of_outputs[12])
                        ) 
                    )   
            {
                _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_INSHYKH_SYGNALIV);
                info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_INSHYKH_SYGNALIV] = info_vymk_tmp;
            }
            //............................................................................................................
        }
#endif
    }
    
    //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
    //Потім розглядається блок включення
    //,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
    if (
            (global_timers[INDEX_TIMER_VIDKL_VVR  ] < 0) && 
            (global_timers[INDEX_TIMER_BLK_VKL_VVR] < 0) &&
            //!@(_CHECK_SET_BIT(p_active_functions, @RANG_BLOCK_VKL_VV) == 0)
            (_CHECK_SET_BIT(p_active_functions, RNG_BIG_BLOCK_VKL_VVP) == 0)
            )
    {
        //Оскільки не працюють таймери БО і блокування включення БВ, а також немає сигналу блокування включення ВВ
        //тому перевіряємо, чи немає умови запуску БВ
        
        if (
                ((p_active_functions[0 ] & current_settings_prt.ranguvannja_on_cb[0 ]) != 0) ||
                ((p_active_functions[1 ] & current_settings_prt.ranguvannja_on_cb[1 ]) != 0) ||
                ((p_active_functions[2 ] & current_settings_prt.ranguvannja_on_cb[2 ]) != 0) ||
                ((p_active_functions[3 ] & current_settings_prt.ranguvannja_on_cb[3 ]) != 0) ||
                ((p_active_functions[4 ] & current_settings_prt.ranguvannja_on_cb[4 ]) != 0) ||
                ((p_active_functions[5 ] & current_settings_prt.ranguvannja_on_cb[5 ]) != 0) ||
                ((p_active_functions[6 ] & current_settings_prt.ranguvannja_on_cb[6 ]) != 0) ||
                ((p_active_functions[7 ] & current_settings_prt.ranguvannja_on_cb[7 ]) != 0) ||
                ((p_active_functions[8 ] & current_settings_prt.ranguvannja_on_cb[8 ]) != 0) ||
                ((p_active_functions[9 ] & current_settings_prt.ranguvannja_on_cb[9 ]) != 0) ||
                ((p_active_functions[10] & current_settings_prt.ranguvannja_on_cb[10]) != 0) ||
                ((p_active_functions[11] & current_settings_prt.ranguvannja_on_cb[11]) != 0) ||
                ((p_active_functions[12] & current_settings_prt.ranguvannja_on_cb[12]) != 0)
                )
        {
            //Відмічаємо у масиві функцій, які зараз активуються, що ще треба активувати блок БВ (якщо він ще не активний)
            _SET_BIT(p_active_functions, RNG_BIG_WORK_BV_VVR);//!@RANG_WORK_BV
            
            //Запускаємо (або продовжуємо утримувати у 0, поки не пропаде сигнал активації БВ) таймер роботи БВ
            global_timers[INDEX_TIMER_VKL_VVR] = 0;
        }
    }
    else
    {
        //На даний момент існує одна або більше умов блокування БВ
        global_timers[INDEX_TIMER_VKL_VVR] = -1;
        _CLEAR_BIT(p_active_functions, RNG_BIG_WORK_BV_VVR);//!@RANG_WORK_BV
    }
    //........................
    
    //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
    //Формуємо попереденій стан сигналів для функції ввімкнення/вимкнення
    //,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
    //?for (unsigned int i = 0; i < N_BIG; i++) previous_active_functions[i] = p_active_functions[i];
    //........................
}
//
//--------------------------------------------------------------------------------------------------------











