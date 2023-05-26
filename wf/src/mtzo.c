#include <string.h> 
#include "const_global.h"
#include "mtzo.h"
void mtzo_handler(unsigned int *p_active_functions, unsigned int number_group_stp );
void mtzo2_handler(unsigned int *p_active_functions, unsigned int number_group_stp );
void mtzo134_handler(unsigned int *p_active_functions, unsigned int number_group_stp );
#ifdef DEBUG_CONFIGURATION
    #ifndef DEBUG_MODE_23_07_19 
        #error "VALUES DZ HAVE UNREAL NUMBER"
    #endif
#endif
char glb_ch_id_mtzo = ID_MTZO1;

void mtzo_handler(unsigned int *p_active_functions, unsigned int number_group_stp ){
    glb_ch_id_mtzo = ID_MTZO1;
    mtzo134_handler(p_active_functions,number_group_stp);
    mtzo2_handler(p_active_functions,number_group_stp);
    glb_ch_id_mtzo = ID_MTZO3;
    mtzo134_handler(p_active_functions,number_group_stp);
    glb_ch_id_mtzo = ID_MTZO4;
    mtzo134_handler(p_active_functions,number_group_stp);
    
}

U8_state_wrp mtzo1_stp,mtzo2_stp,mtzo3_stp,mtzo4_stp;
U8_state_wrp stt_MTZO_And01__2_1;
void mtzo134_handler(unsigned int *p_active_functions, unsigned int number_group_stp );
//=====================================================================================================
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//                  
//....................................................................................................
//=====================================================================================================
void mtzo134_handler(unsigned int *p_active_functions, unsigned int number_group_stp )//{UNUSED(number_group_stp);UNUSED(p_active_functions);
{
  long lV;unsigned long rU;
   
  register union { 
  struct {
      unsigned int in1_mtzo_normal_selector :1;//0
      unsigned int select_mtzo134_directed  :1;//1
      unsigned int in1_mtzo_stp_u_selector  :1;//2
      unsigned int m_mtzo134                :1;//3in_mtzo_on_menu
      unsigned int dv_block_mtzo134         :1;//4in_mtzo_rng_big_block
      unsigned int m_mtzo134_dir            :1;//5in_mtzo_dir_on_menu
      unsigned int m_mtzo134_sector_dir     :1;//6in_mtzo_sector_dir
      unsigned int m_mtzo134_sector_inv     :1;//7in_mtzo_sector_inv
      unsigned int in1_mtzo_stp_dir         :1;//8
      unsigned int m_mtzo134_inv            :1;//9in_mtzo_inv_on_menu
      unsigned int in1_mtzo_stp_inv         :1;//10
      unsigned int in1_mtzo_rng_big_po_blk_u                :1;//11
      unsigned int in1_mtzo_stp_po_blk_u_osn_less_u_porog   :1;//12
      unsigned int in1_mtzo_stp_u           :1;//13
      unsigned int in1_mtzo_stp_simple      :1;//14
      unsigned int reser4                  :1;//15
      unsigned int not10_1_b7              :1;//16
      unsigned int cmd_nkn_mtzo134         :1;//17
      unsigned int not8_1_b7               :1;//18
      unsigned int not5_1_b7               :1;//19
      unsigned int and6_2_1_b7             :1;//20
      unsigned int or07_2_1_b7             :1;//21
      unsigned int and9_2_1_b7             :1;//22
      unsigned int po_mtzo134_u_pn         :1;//23
      unsigned int po_mtzo134_i_pn         :1;//24
      unsigned int po_mtzo134_sector_inv   :1;//25
      unsigned int po_mtzo134_sector_dir   :1;//26
      unsigned int po_mtzo134_inv          :1;//27
      unsigned int po_mtzo134_dir          :1;//28
      unsigned int po_mtzo134_simple       :1;//29
      unsigned int reser2 :1;//30
      unsigned int reser3 :1;//31
      
   } bool_vars;
  long lVl;
 }wrp_mtzo;
  
  
  struct{
      unsigned long po_mtzo_smpl_spt,     po_mtzon_vpered_spt,  po_mtzon_nazad_spt,
       po_u_mtzopn_spt,     po_mtzopn_spt;
  __SETTINGS *p_current_settings_prt;
  }sLV;    
    wrp_mtzo.lVl = 0;
    U8_state_wrp //..stt_MTZO_And01__2_1,
                 stt_MTZO_Or_02__3_1,
                 stt_MTZO_Not03__1_1,  
                 stt_MTZO_And04__2_1,
                 //stt_MTZO_Not05__1_1,
                 //stt_MTZO_And06__2_1,
                 stt_MTZO_Or_07__2_1, 
                 //stt_MTZO_Not08__1_1,
                 stt_MTZO_And09__2_1,
                 //stt_MTZO_Not10__1_1,
                 stt_MTZO_And11__2_1,
                 stt_MTZO_Or_12__4_1,
                 stt_MTZO_And13__3_1,
                 stt_MTZO_And14__6_1, 
                 stt_MTZO_And15__6_1, 
                 stt_MTZO_And16__4_1; 
                // stt_MTZO_Or_17__4_1;
    lV = 0;         
     stt_MTZO_And01__2_1.U8V = lV;
     stt_MTZO_Or_02__3_1.U8V = lV;
     stt_MTZO_Not03__1_1.U8V = lV;
     stt_MTZO_And04__2_1.U8V = lV;
     //stt_MTZO_Not05__1_1.U8V = 0;
     //stt_MTZO_And06__2_1.U8V = lV;
     stt_MTZO_Or_07__2_1.U8V = lV;
     //stt_MTZO_Not08__1_1.U8V = 0;
     stt_MTZO_And09__2_1.U8V = lV;
     //stt_MTZO_Not10__1_1.U8V = 0;
     stt_MTZO_And11__2_1.U8V = lV;
     stt_MTZO_Or_12__4_1.U8V = lV;
     stt_MTZO_And13__3_1.U8V = lV;
     stt_MTZO_And14__6_1.U8V = lV;
     stt_MTZO_And15__6_1.U8V = lV;
     stt_MTZO_And16__4_1.U8V = lV;
    // stt_MTZO_Or_17__4_1.U8V = 0;
     
    sLV.p_current_settings_prt = &current_settings_prt ;
    //wrp_mtzo1.bool_vars. = 
    //(sLV.p_current_settings_prt->control_ozt & CTR_OZT_1) ;  
//.    wrp_mtzo.bool_vars.in_mtzo_on_menu =  
//.    (sLV.p_current_settings_prt->control_mtzo & CTR_MTZO_1) ;  
//.    wrp_mtzo.bool_vars.in_mtzo_dir_on_menu = 
//.    (sLV.p_current_settings_prt->control_mtzo & CTR_MTZO_1_VPERED) ;  
//.    wrp_mtzo.bool_vars.in_mtzo_inv_on_menu = 
//.    (sLV.p_current_settings_prt->control_mtzo & CTR_MTZO_1_NAZAD) ;  
    //lV = (sLV.p_current_settings_prt->control_mtzo & CTR_OZT_1) ;  
    //lV = (sLV.p_current_settings_prt->control_mtzo & CTR_OZT_1) ;
    
    //Po mtz simple
    if(glb_ch_id_mtzo == ID_MTZO1){
        wrp_mtzo.bool_vars.m_mtzo134 =  
    (sLV.p_current_settings_prt->control_mtzo & CTR_MTZO_1)!=0 ;  
        wrp_mtzo.bool_vars.m_mtzo134_dir = 
    (sLV.p_current_settings_prt->control_mtzo & CTR_MTZO_1_VPERED)!=0 ;  
        wrp_mtzo.bool_vars.m_mtzo134_inv = 
    (sLV.p_current_settings_prt->control_mtzo & CTR_MTZO_1_NAZAD)!=0 ;  
        //?register U8_mtzo_po_wrp R_mtzo_po;
        //?R_mtzo_po.U8V = mtzo1_stp.U8V;
        rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZO1);
        //if(R_mtzo_po.bool_val.po_mtz_simple == 1 ) {
        if( rU!= 0) {
            sLV.po_mtzo_smpl_spt = sLV.p_current_settings_prt->setpoint_mtzo_1[number_group_stp]
         * KOEF_POVERNENNJA_MTZ_I_UP / 100;
        }else{
           sLV.po_mtzo_smpl_spt = sLV.p_current_settings_prt->setpoint_mtzo_1[number_group_stp]; 
        }
        //
        if(measurement[IM_Imn] >= sLV.po_mtzo_smpl_spt)
            wrp_mtzo.bool_vars.po_mtzo134_simple = 1;//?R_mtzo_po.bool_val.po_mtz_simple = 1;
        //.else    
        //.    wrp_mtzo.bool_vars.po_mtzo134_simple = 0;//?R_mtzo_po.bool_val.po_mtz_simple = 0;
        
        rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZON1_VPERED);
        //if(R_mtzo_po.bool_val.po_mtz_simple == 1 ) {
        if( rU!= 0) {
            sLV.po_mtzon_vpered_spt = sLV.p_current_settings_prt->setpoint_mtzo_1_n_vpered[number_group_stp]
         * KOEF_POVERNENNJA_MTZ_I_UP / 100;
        }else{
           sLV.po_mtzon_vpered_spt = sLV.p_current_settings_prt->setpoint_mtzo_1_n_vpered[number_group_stp]; 
        }
        //
        if(measurement[IM_Imn] >= sLV.po_mtzon_vpered_spt)
            wrp_mtzo.bool_vars.po_mtzo134_dir = 1;//?R_mtzo_po.bool_val.po_mtz_dir
        //.else    
        //.    wrp_mtzo.bool_vars.po_mtzo134_dir = 0;//?R_mtzo_po.bool_val.po_mtz_dir
        //
        rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZON1_NAZAD);
        
        if( rU!= 0) {
            sLV.po_mtzon_nazad_spt = sLV.p_current_settings_prt->setpoint_mtzo_1_n_nazad[number_group_stp]
         * KOEF_POVERNENNJA_MTZ_I_UP / 100;
        }else{
           sLV.po_mtzon_nazad_spt = sLV.p_current_settings_prt->setpoint_mtzo_1_n_nazad[number_group_stp]; 
        }
        //
        if(measurement[IM_Imn] >= sLV.po_mtzon_nazad_spt)
            wrp_mtzo.bool_vars.po_mtzo134_inv = 1;//?R_mtzo_po.bool_val.po_mtz_inv
        //.else    
        //.    wrp_mtzo.bool_vars.po_mtzo134_inv = 0;//?R_mtzo_po.bool_val.po_mtz_inv
        
        if((sector_directional_mtz[MTZ_LEVEL1][PHASE_MN_INDEX] == MTZ_VPERED)){
            wrp_mtzo.bool_vars.po_mtzo134_sector_dir = 1;//?R_mtzo_po.bool_val.po_mtz_sector_dir
            _SET_BIT(p_active_functions, RNG_BIG_SECTOR_VPERED_MCZON1);
        }else{ 
            //.wrp_mtzo.bool_vars.po_mtzo134_sector_dir = 0;//?R_mtzo_po.bool_val.po_mtz_sector_dir
            _CLEAR_BIT(p_active_functions, RNG_BIG_SECTOR_VPERED_MCZON1);
        }   
        if(sector_directional_mtz[MTZ_LEVEL1][PHASE_MN_INDEX] == MTZ_NAZAD){
           wrp_mtzo.bool_vars.po_mtzo134_sector_inv = 1;//?R_mtzo_po.bool_val.po_mtz_sector_inv 
            _SET_BIT(p_active_functions, RNG_BIG_SECTOR_NAZAD_MCZON1);
        }else{
            //.wrp_mtzo.bool_vars.po_mtzo134_sector_inv = 0;//?R_mtzo_po.bool_val.po_mtz_sector_inv
            _CLEAR_BIT(p_active_functions, RNG_BIG_SECTOR_NAZAD_MCZON1);
        }
        rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZOPN1);
        if( rU!= 0 ) {
            sLV.po_u_mtzopn_spt = sLV.p_current_settings_prt->setpoint_mtzo_1_U[number_group_stp] * U_DOWN / 100;
            sLV.po_mtzopn_spt = sLV.p_current_settings_prt->setpoint_mtzo_1_po_napruzi[number_group_stp] * KOEF_POVERNENNJA_MTZ_I_UP / 100;
        }else{
           sLV.po_u_mtzopn_spt = sLV.p_current_settings_prt->setpoint_mtzo_1_U[number_group_stp]; 
           sLV.po_mtzopn_spt = sLV.p_current_settings_prt->setpoint_mtzo_1_po_napruzi[number_group_stp]; 
        }
        if(measurement[IM_Umn] <= sLV.po_u_mtzopn_spt){
            wrp_mtzo.bool_vars.po_mtzo134_u_pn = 1;//?R_mtzo_po.bool_val.po_mtz_u_ust_pn
            _SET_BIT(p_active_functions, RNG_BIG_PO_BLK_U_OSN_LESS_UST_MCZO1);
        }else{
            //.wrp_mtzo.bool_vars.po_mtzo134_u_pn = 0;//?R_mtzo_po.bool_val.po_mtz_u_ust_pn
            _CLEAR_BIT(p_active_functions, RNG_BIG_PO_BLK_U_OSN_LESS_UST_MCZO1);
        }
        if(measurement[IM_Imn] >= sLV.po_mtzopn_spt)
            wrp_mtzo.bool_vars.po_mtzo134_i_pn = 1;//?R_mtzo_po.bool_val.po_mtz_pn
        //else    
        //    wrp_mtzo.bool_vars.po_mtzo134_i_pn = 0;//?R_mtzo_po.bool_val.po_mtz_pn
        
        //?mtzo1_stp.U8V = R_mtzo_po.U8V;
        
    }
    else if(glb_ch_id_mtzo == ID_MTZO3){
        wrp_mtzo.bool_vars.m_mtzo134 =  
        (sLV.p_current_settings_prt->control_mtzo & CTR_MTZO_3)!=0 ;  
        wrp_mtzo.bool_vars.m_mtzo134_dir = 
        (sLV.p_current_settings_prt->control_mtzo & CTR_MTZO_3_VPERED)!=0 ;  
        wrp_mtzo.bool_vars.m_mtzo134_inv = 
        (sLV.p_current_settings_prt->control_mtzo & CTR_MTZO_3_NAZAD)!=0 ;  
        //?register U8_mtzo_po_wrp R_mtzo_po;
        //?R_mtzo_po.U8V = mtzo3_stp.U8V;
        rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZO3);
        //if(R_mtzo_po.bool_val.po_mtz_simple == 1 ) {
        if( rU!= 0 ) {
            sLV.po_mtzo_smpl_spt = sLV.p_current_settings_prt->setpoint_mtzo_3[number_group_stp]
         * KOEF_POVERNENNJA_MTZ_I_UP / 100;
        }else{
           sLV.po_mtzo_smpl_spt = sLV.p_current_settings_prt->setpoint_mtzo_3[number_group_stp]; 
        }
        
        if(measurement[IM_Imn] >= sLV.po_mtzo_smpl_spt)
            wrp_mtzo.bool_vars.po_mtzo134_simple = 1;//?R_mtzo_po.bool_val.po_mtz_simple = 1;
//?        else    
//?            R_mtzo_po.bool_val.po_mtz_simple = 0;
        //mtzo3_stp.bool_val.po_mtz_simple = R_mtzo_po.bool_val.po_mtz_simple;
        rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZON3_VPERED);
        //if(R_mtzo_po.bool_val.po_mtz_simple == 1 ) {
        if( rU!= 0) {
            sLV.po_mtzon_vpered_spt = sLV.p_current_settings_prt->setpoint_mtzo_3_n_vpered[number_group_stp]
         * KOEF_POVERNENNJA_MTZ_I_UP / 100;
        }else{
           sLV.po_mtzon_vpered_spt = sLV.p_current_settings_prt->setpoint_mtzo_3_n_vpered[number_group_stp]; 
        }
        //
        if(measurement[IM_Imn] >= sLV.po_mtzon_vpered_spt)
            wrp_mtzo.bool_vars.po_mtzo134_dir = 1;//?R_mtzo_po.bool_val.po_mtz_dir = 1;
//?        else    
//?            R_mtzo_po.bool_val.po_mtz_dir = 0;
        //
        rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZON3_NAZAD);
        //if(R_mtzo_po.bool_val.po_mtz_simple == 1 ) {
        if( rU!= 0) {
            sLV.po_mtzon_nazad_spt = sLV.p_current_settings_prt->setpoint_mtzo_3_n_vpered[number_group_stp]
         * KOEF_POVERNENNJA_MTZ_I_UP / 100;
        }else{
           sLV.po_mtzon_nazad_spt = sLV.p_current_settings_prt->setpoint_mtzo_3_n_vpered[number_group_stp]; 
        }
        //
        if(measurement[IM_Imn] >= sLV.po_mtzon_nazad_spt)
            wrp_mtzo.bool_vars.po_mtzo134_inv = 1;//?R_mtzo_po.bool_val.po_mtz_inv = 1;
//?        else    
//?            R_mtzo_po.bool_val.po_mtz_inv = 0;
        //mtzo1_stp.bool_val. = R_mtzo_po.bool_val.;
        if((sector_directional_mtz[MTZ_LEVEL3][PHASE_MN_INDEX] == MTZ_VPERED)){
            wrp_mtzo.bool_vars.po_mtzo134_sector_dir = 1;//?R_mtzo_po.bool_val.po_mtz_sector_dir = 1;
            _SET_BIT(p_active_functions, RNG_BIG_SECTOR_VPERED_MCZON3);
        }else{ 
            //.R_mtzo_po.bool_val.po_mtz_sector_dir = 0;
            _CLEAR_BIT(p_active_functions, RNG_BIG_SECTOR_VPERED_MCZON3);
        }   
        if(sector_directional_mtz[MTZ_LEVEL3][PHASE_MN_INDEX] == MTZ_NAZAD){
            wrp_mtzo.bool_vars.po_mtzo134_sector_inv = 1;//?R_mtzo_po.bool_val.po_mtz_sector_inv = 1;
            _SET_BIT(p_active_functions, RNG_BIG_SECTOR_NAZAD_MCZON3);
        }else{
            //>R_mtzo_po.bool_val.po_mtz_sector_inv = 0;
            _CLEAR_BIT(p_active_functions, RNG_BIG_SECTOR_NAZAD_MCZON3);
        }
        rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZOPN3);
        if( rU!= 0 ) {
            sLV.po_u_mtzopn_spt = sLV.p_current_settings_prt->setpoint_mtzo_3_U[number_group_stp] * U_DOWN / 100;
            sLV.po_mtzopn_spt = sLV.p_current_settings_prt->setpoint_mtzo_3_po_napruzi[number_group_stp] * KOEF_POVERNENNJA_MTZ_I_UP / 100;
        }else{
           sLV.po_u_mtzopn_spt = sLV.p_current_settings_prt->setpoint_mtzo_3_U[number_group_stp]; 
           sLV.po_mtzopn_spt = sLV.p_current_settings_prt->setpoint_mtzo_3_po_napruzi[number_group_stp]; 
        }
        if(measurement[IM_Umn] <= sLV.po_u_mtzopn_spt){
             wrp_mtzo.bool_vars.po_mtzo134_u_pn = 1;//?R_mtzo_po.bool_val.po_mtz_u_ust_pn = 1;
            _SET_BIT(p_active_functions, RNG_BIG_PO_BLK_U_OSN_LESS_UST_MCZO3);
        }else{
            //?R_mtzo_po.bool_val.po_mtz_u_ust_pn = 0;
            _CLEAR_BIT(p_active_functions, RNG_BIG_PO_BLK_U_OSN_LESS_UST_MCZO3);
        }
        if(measurement[IM_Imn] >= sLV.po_mtzopn_spt)
            wrp_mtzo.bool_vars.po_mtzo134_i_pn = 1;//?R_mtzo_po.bool_val.po_mtz_pn = 1;
//?        else    
//?            R_mtzo_po.bool_val.po_mtz_pn = 0;
//?        mtzo3_stp.U8V = R_mtzo_po.U8V;
    
    }
    else if(glb_ch_id_mtzo == ID_MTZO4){
            wrp_mtzo.bool_vars.m_mtzo134 =  
        (sLV.p_current_settings_prt->control_mtzo & CTR_MTZO_4)!=0 ;  
        wrp_mtzo.bool_vars.m_mtzo134_dir = 
        (sLV.p_current_settings_prt->control_mtzo & CTR_MTZO_4_VPERED)!=0 ;  
        wrp_mtzo.bool_vars.m_mtzo134_inv = 
        (sLV.p_current_settings_prt->control_mtzo & CTR_MTZO_4_NAZAD)!=0 ;  
        //?register U8_mtzo_po_wrp R_mtzo_po;
        //?R_mtzo_po.U8V = mtzo4_stp.U8V;
        rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZO4);
        //if(R_mtzo_po.bool_val.po_mtz_simple == 1 ) {
        if( rU!= 0 ) {
            sLV.po_mtzo_smpl_spt = sLV.p_current_settings_prt->setpoint_mtzo_4[number_group_stp]
         * KOEF_POVERNENNJA_MTZ_I_UP / 100;
        }else{
           sLV.po_mtzo_smpl_spt = sLV.p_current_settings_prt->setpoint_mtzo_4[number_group_stp]; 
        }
        //
        if(measurement[IM_Imn] >= sLV.po_mtzo_smpl_spt)
            wrp_mtzo.bool_vars.po_mtzo134_simple = 1;//?R_mtzo_po.bool_val.po_mtz_simple = 1;
//?        else    
//?            R_mtzo_po.bool_val.po_mtz_simple = 0;
        //mtzo4_stp.bool_val.po_mtz_simple = R_mtzo_po.bool_val.po_mtz_simple;
        rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZON4_VPERED);
        //if(R_mtzo_po.bool_val.po_mtz_simple == 1 ) {
        if( rU!= 0) {
            sLV.po_mtzon_vpered_spt = sLV.p_current_settings_prt->setpoint_mtzo_4_n_vpered[number_group_stp]
         * KOEF_POVERNENNJA_MTZ_I_UP / 100;
        }else{
           sLV.po_mtzon_vpered_spt = sLV.p_current_settings_prt->setpoint_mtzo_4_n_vpered[number_group_stp]; 
        }
        //
        if(measurement[IM_Imn] >= sLV.po_mtzon_vpered_spt)
            wrp_mtzo.bool_vars.po_mtzo134_dir = 1;//?R_mtzo_po.bool_val.po_mtz_dir = 1;
//?        else    
//?            R_mtzo_po.bool_val.po_mtz_dir = 0;
        //
        rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZON4_NAZAD);
        //if(R_mtzo_po.bool_val.po_mtz_simple == 1 ) {
        if( rU!= 0) {
            sLV.po_mtzon_nazad_spt = sLV.p_current_settings_prt->setpoint_mtzo_4_n_vpered[number_group_stp]
         * KOEF_POVERNENNJA_MTZ_I_UP / 100;
        }else{
           sLV.po_mtzon_nazad_spt = sLV.p_current_settings_prt->setpoint_mtzo_4_n_vpered[number_group_stp]; 
        }
        //
        if(measurement[IM_Imn] >= sLV.po_mtzon_nazad_spt)
            wrp_mtzo.bool_vars.po_mtzo134_inv = 1;//?R_mtzo_po.bool_val.po_mtz_inv = 1;
//?        else    
//?            R_mtzo_po.bool_val.po_mtz_inv = 0;
        //mtzo1_stp.bool_val. = R_mtzo_po.bool_val.;
        if((sector_directional_mtz[MTZ_LEVEL4][PHASE_MN_INDEX] == MTZ_VPERED)){
            wrp_mtzo.bool_vars.po_mtzo134_sector_dir = 1;//?R_mtzo_po.bool_val.po_mtz_sector_dir = 1;
            _SET_BIT(p_active_functions, RNG_BIG_SECTOR_VPERED_MCZON4);
        }else{ 
            //.R_mtzo_po.bool_val.po_mtz_sector_dir = 0;
            _CLEAR_BIT(p_active_functions, RNG_BIG_SECTOR_VPERED_MCZON4);
        }   
        if(sector_directional_mtz[MTZ_LEVEL4][PHASE_MN_INDEX] == MTZ_NAZAD){
            wrp_mtzo.bool_vars.po_mtzo134_sector_inv = 1;//?R_mtzo_po.bool_val.po_mtz_sector_inv = 1;
            _SET_BIT(p_active_functions, RNG_BIG_SECTOR_NAZAD_MCZON4);
        }else{
            //?R_mtzo_po.bool_val.po_mtz_sector_inv = 0;
            _CLEAR_BIT(p_active_functions, RNG_BIG_SECTOR_NAZAD_MCZON4);
        }
        rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZOPN4);
        if( rU!= 0 ) {
            sLV.po_u_mtzopn_spt = sLV.p_current_settings_prt->setpoint_mtzo_4_U[number_group_stp] * U_DOWN / 100;
            sLV.po_mtzopn_spt = sLV.p_current_settings_prt->setpoint_mtzo_4_po_napruzi[number_group_stp] * KOEF_POVERNENNJA_MTZ_I_UP / 100;
        }else{
           sLV.po_u_mtzopn_spt = sLV.p_current_settings_prt->setpoint_mtzo_4_U[number_group_stp]; 
           sLV.po_mtzopn_spt = sLV.p_current_settings_prt->setpoint_mtzo_4_po_napruzi[number_group_stp]; 
        }
        if(measurement[IM_Umn] <= sLV.po_u_mtzopn_spt){
            wrp_mtzo.bool_vars.po_mtzo134_u_pn = 1;//?R_mtzo_po.bool_val.po_mtz_u_ust_pn = 1;
            _SET_BIT(p_active_functions, RNG_BIG_PO_BLK_U_OSN_LESS_UST_MCZO4);
        }else{
            //?R_mtzo_po.bool_val.po_mtz_u_ust_pn = 0;
            _CLEAR_BIT(p_active_functions, RNG_BIG_PO_BLK_U_OSN_LESS_UST_MCZO4);
        }
        if(measurement[IM_Imn] >= sLV.po_mtzopn_spt)
            wrp_mtzo.bool_vars.po_mtzo134_i_pn = 1;
//?        else    
//?            R_mtzo_po.bool_val.po_mtz_pn = 0;
//?        mtzo4_stp.U8V = R_mtzo_po.U8V;
    
    }
    
    //RNG_BIG_PO_BLK_U_OSN_LESS_0_05UN_MCZO,
     //ДВ
    //lV = _CHECK_SET_BIT(p_active_functions, );  
    
    if(glb_ch_id_mtzo == ID_MTZO1){
        
        
        if ( (sLV.p_current_settings_prt->control_mtzo & CTR_MTZO_NESPR_KIL_NAPR) != 0) 
            stt_MTZO_And01__2_1.bool_val.bt0 = 1;
        //stt_MTZO_And01__2_1.bool_val.bt0 = lV;
        lV = _CHECK_SET_BIT(p_active_functions, RNG_BIG_NKNO);
        stt_MTZO_And01__2_1.bool_val.bt1 = lV!=0;
    //eval
        if ((stt_MTZO_And01__2_1.U8V &3) == 3){
            _SET_BIT(p_active_functions, RNG_BIG_NCN_MCZO);
            stt_MTZO_And01__2_1.bool_val.bt7 = 1;
        }else{
            _CLEAR_BIT(p_active_functions, RNG_BIG_NCN_MCZO);
            stt_MTZO_And01__2_1.bool_val.bt7 = 0;
        }
        
        if(measurement[IM_Umn] <= 5000){
            
            _SET_BIT(p_active_functions, RNG_BIG_PO_BLK_U_OSN_LESS_0_05UN_MCZO);
        }else{
            //?R_mtzo_po.bool_val.po_mtz_u_ust_pn = 0;
            _CLEAR_BIT(p_active_functions, RNG_BIG_PO_BLK_U_OSN_LESS_0_05UN_MCZO);
        }
    }
    if(glb_ch_id_mtzo == ID_MTZO1){
        
         
        stt_MTZO_Or_02__3_1.bool_val.bt0 =
        (_CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZON1_VPERED))!=0;
        stt_MTZO_Or_02__3_1.bool_val.bt1 = 
        (_CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZON1_NAZAD))!=0;
        stt_MTZO_Or_02__3_1.bool_val.bt2 = 
        (_CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZOPN1))!=0;
        
        
        
        if((stt_MTZO_Or_02__3_1.U8V &7) != 0)
        stt_MTZO_Not03__1_1.bool_val.bt0 = 1;
        //else  stt_MTZO_Not03__1_1.bool_val.bt0 = 0;
        stt_MTZO_Not03__1_1.bool_val.bt7 = !stt_MTZO_Not03__1_1.bool_val.bt0;
        
        stt_MTZO_And04__2_1.bool_val.bt0 = stt_MTZO_Not03__1_1.bool_val.bt7;
        stt_MTZO_And04__2_1.bool_val.bt1 = stt_MTZO_And01__2_1.bool_val.bt7;
    
        if ((stt_MTZO_And04__2_1.U8V &3) == 3){
//        _SET_BIT(p_active_functions, RNG_BIG_NCN_MCZO1);
           stt_MTZO_And04__2_1.bool_val.bt7 = 1;
           wrp_mtzo.bool_vars.cmd_nkn_mtzo134 = 1;
        }else{
//        _CLEAR_BIT(p_active_functions, RNG_BIG_NCN_MCZO1);
        
        }
        lV = (sLV.p_current_settings_prt->type_mtzo1) ;
        if(lV == TYPE_MTZ_SIMPLE){
            stt_MTZO_Or_12__4_1.bool_val.bt2 = 1;//in_mtzo_normal_selector
        }
        else if(lV == TYPE_MTZ_DIRECTIONAL){
            wrp_mtzo.bool_vars.select_mtzo134_directed = 1;
        }else{
            stt_MTZO_And16__4_1.bool_val.bt0 = 1;
        }           
        wrp_mtzo.bool_vars.dv_block_mtzo134 = (_CHECK_SET_BIT(p_active_functions, RNG_BIG_BLOCK_MCZO1))!=0;
    }
    else if(glb_ch_id_mtzo == ID_MTZO3){
        stt_MTZO_Or_02__3_1.bool_val.bt0 =
        (_CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZON3_VPERED))!=0;
        stt_MTZO_Or_02__3_1.bool_val.bt1 = 
        (_CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZON3_NAZAD))!=0;
        stt_MTZO_Or_02__3_1.bool_val.bt2 = 
        (_CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZOPN3))!=0;
        
        
        
        if((stt_MTZO_Or_02__3_1.U8V &7) != 0)
        stt_MTZO_Not03__1_1.bool_val.bt0 = 1;
        //else  stt_MTZO_Not03__1_1.bool_val.bt0 = 0;
        stt_MTZO_Not03__1_1.bool_val.bt7 = !stt_MTZO_Not03__1_1.bool_val.bt0;
        
        stt_MTZO_And04__2_1.bool_val.bt0 = stt_MTZO_And01__2_1.bool_val.bt7;
        lV = _CHECK_SET_BIT(p_active_functions, RNG_BIG_NCN_MCZO);
        stt_MTZO_And04__2_1.bool_val.bt1 = lV!=0;//stt_MTZO_Not03__1_1.bool_val.bt7;
    
        if ((stt_MTZO_And04__2_1.U8V &3) == 3){
//        _SET_BIT(p_active_functions, RNG_BIG_NCN_MCZO3);
        stt_MTZO_And04__2_1.bool_val.bt7 = 1;
        wrp_mtzo.bool_vars.cmd_nkn_mtzo134 = 1;
        }else{
//        _CLEAR_BIT(p_active_functions, RNG_BIG_NCN_MCZO3);
        
        }
        lV = (sLV.p_current_settings_prt->type_mtzo3) ;
        if(lV == 0){
            stt_MTZO_Or_12__4_1.bool_val.bt2 = 1;//in_mtzo_normal_selector
        }
        else if(lV == 1){
            wrp_mtzo.bool_vars.select_mtzo134_directed = 1;
        }else{
            stt_MTZO_And16__4_1.bool_val.bt0 = 1;
        }           
        wrp_mtzo.bool_vars.dv_block_mtzo134 = (_CHECK_SET_BIT(p_active_functions, RNG_BIG_BLOCK_MCZO3))!=0;
    }
    else if(glb_ch_id_mtzo == ID_MTZO4){
        stt_MTZO_Or_02__3_1.bool_val.bt0 =
        (_CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZON4_VPERED))!=0;
        stt_MTZO_Or_02__3_1.bool_val.bt1 = 
        (_CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZON4_NAZAD))!=0;
        stt_MTZO_Or_02__3_1.bool_val.bt2 = 
        (_CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZOPN4))!=0;
        
        
        
        if((stt_MTZO_Or_02__3_1.U8V &7) != 0)
        stt_MTZO_Not03__1_1.bool_val.bt0 = 1;
        //else  stt_MTZO_Not03__1_1.bool_val.bt0 = 0;
        stt_MTZO_Not03__1_1.bool_val.bt7 = !stt_MTZO_Not03__1_1.bool_val.bt0;
        lV = _CHECK_SET_BIT(p_active_functions, RNG_BIG_NCN_MCZO);
        stt_MTZO_And04__2_1.bool_val.bt0 = lV!=0;//stt_MTZO_And01__2_1.bool_val.bt7;
        stt_MTZO_And04__2_1.bool_val.bt1 = stt_MTZO_Not03__1_1.bool_val.bt7;
    
        if ((stt_MTZO_And04__2_1.U8V &3) == 3){
//        _SET_BIT(p_active_functions, RNG_BIG_NCN_MCZO4);
        stt_MTZO_And04__2_1.bool_val.bt7 = 1;
        wrp_mtzo.bool_vars.cmd_nkn_mtzo134 = 1;
        }else{
//        _CLEAR_BIT(p_active_functions, RNG_BIG_NCN_MCZO4);
        
        }
        lV = (sLV.p_current_settings_prt->type_mtzo4) ;
        if(lV == 0){
            stt_MTZO_Or_12__4_1.bool_val.bt2 = 1;//in_mtzo_normal_selector
        }
        else if(lV == 1){
            wrp_mtzo.bool_vars.select_mtzo134_directed = 1;
        }else{
            stt_MTZO_And16__4_1.bool_val.bt0 = 1;
        }           
        wrp_mtzo.bool_vars.dv_block_mtzo134 = (_CHECK_SET_BIT(p_active_functions, RNG_BIG_BLOCK_MCZO4))!=0;
    }
    
    //?rU = wrp_mtzo.bool_vars.dv_block_mtzo134;
    //?wrp_mtzo.bool_vars.dv_block_mtzo134 = 
    //?     (_CHECK_SET_BIT(p_active_functions, RNG_BIG_BLOCK_MCZO1))!=0;
    //?wrp_mtzo.bool_vars.not5_1_b7 = (~rU)&1;
    
    rU = wrp_mtzo.bool_vars.dv_block_mtzo134;
    
    //?stt_MTZO_And06__2_1.bool_val.bt0 = wrp_mtzo.bool_vars.m_mtzo134;
    //?stt_MTZO_And06__2_1.bool_val.bt1 = (~rU)&1;
    
//?    if ((stt_MTZO_And06__2_1.U8V &3) == 3){
//?        stt_MTZO_And06__2_1.bool_val.bt7 = 1;
//?        
//?    }
    lV = (~rU)&1;
    if(lV != 0 && wrp_mtzo.bool_vars.m_mtzo134 !=0 )
        wrp_mtzo.bool_vars.and6_2_1_b7 = 1;
    
    
    stt_MTZO_Or_07__2_1.bool_val.bt0 = (_CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_BLK_U_OSN_LESS_0_05UN_MCZO))!=0;
    //?wrp_mtzo.bool_vars.po_mtzo134_u_pn;
    rU = wrp_mtzo.bool_vars.cmd_nkn_mtzo134;//.stt_MTZO_And04__2_1.bool_val.bt7;
    //?stt_MTZO_Or_07__2_1.bool_val.bt1 = stt_MTZO_And04__2_1.bool_val.bt7;
    stt_MTZO_Or_07__2_1.bool_val.bt1 = rU;
    if((stt_MTZO_Or_07__2_1.U8V &3) != 0){
       
        //stt_MTZO_Or_07__2_1.bool_val.bt7 = 0;//bool_val.bt7 = 1;
        wrp_mtzo.bool_vars.or07_2_1_b7 = 0;
    }
    else{
        //stt_MTZO_Or_07__2_1.bool_val.bt7 = 1;//Inverse state now
        wrp_mtzo.bool_vars.or07_2_1_b7 = 1;
    }
    
    //wrp_mtzo.bool_vars.not8_1_b0 = rU;//
    lV = (~rU)&1;
    //wrp_mtzo.bool_vars.not8_1_b7 = lV;//
    
    stt_MTZO_And09__2_1.bool_val.bt0 = wrp_mtzo.bool_vars.po_mtzo134_u_pn;
    stt_MTZO_And09__2_1.bool_val.bt1 = lV;//not8
    if((stt_MTZO_And09__2_1.U8V &3) == 3){
        //stt_MTZO_And09__2_1.bool_val.bt7 = 1;
        //wrp_mtzo.bool_vars.and9_2_1_b7 = 1;
        stt_MTZO_And16__4_1.bool_val.bt2 = 1;
    }
    
//?    rU = stt_MTZO_Or_07__2_1.bool_val.bt7;
//?    wrp_mtzo.bool_vars.not10_1_b0 = rU;//stt_MTZO_Not10__1_1.bool_val.bt0 = rU;
//?    lV = (~rU)&1;
//?    wrp_mtzo.bool_vars.not10_1_b7 = lV;//stt_MTZO_Not10__1_1.bool_val.bt7 = lV;
   rU = wrp_mtzo.bool_vars.or07_2_1_b7;
   lV = (~rU)&1;
   wrp_mtzo.bool_vars.not10_1_b7 = lV;
   
   
   
   
    stt_MTZO_And11__2_1.bool_val.bt0 = 
    wrp_mtzo.bool_vars.select_mtzo134_directed;
    stt_MTZO_And11__2_1.bool_val.bt1 =  lV;//stt_MTZO_Not10__1_1.bool_val.bt7;
    lV = 0;
    if((stt_MTZO_And11__2_1.U8V &3) == 3)
        lV = 1;
    stt_MTZO_And11__2_1.bool_val.bt7 =  lV;
    //?wrp_mtzo.bool_vars.and11_2_1_b7 =   lV;
    
    stt_MTZO_Or_12__4_1.bool_val.bt0 =  lV;
    
    if(glb_ch_id_mtzo == ID_MTZO1){
    stt_MTZO_Or_12__4_1.bool_val.bt1 = 
     (_CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZO1))!=0;
    }
    else if(glb_ch_id_mtzo == ID_MTZO3){ 
        stt_MTZO_Or_12__4_1.bool_val.bt1 = 
     (_CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZO3))!=0;
    }
    else if(glb_ch_id_mtzo == ID_MTZO4){
        stt_MTZO_Or_12__4_1.bool_val.bt1 = 
     (_CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZO4))!=0;
    }       
    //?stt_MTZO_Or_12__4_1.bool_val.bt2 = 
    //?wrp_mtzo.bool_vars.in_mtzo_normal_selector;
    stt_MTZO_Or_12__4_1.bool_val.bt3 = stt_MTZO_And04__2_1.bool_val.bt7;
    if((stt_MTZO_Or_12__4_1.U8V &15) != 0){
        stt_MTZO_Or_12__4_1.bool_val.bt7 = lV = 1;
        //
    }

    stt_MTZO_And13__3_1.bool_val.bt0 = stt_MTZO_Or_12__4_1.bool_val.bt7;
    stt_MTZO_And13__3_1.bool_val.bt1 = wrp_mtzo.bool_vars.po_mtzo134_simple;//?wrp_mtzo.bool_vars.in_mtzo_stp_simple;
    stt_MTZO_And13__3_1.bool_val.bt2 = wrp_mtzo.bool_vars.and6_2_1_b7;//?stt_MTZO_And06__2_1.bool_val.bt7; 
    if((stt_MTZO_And13__3_1.U8V &7) == 7){
        
        stt_MTZO_And13__3_1.bool_val.bt7 = 1;
    } 

    do { 
        register U8_state_wrp R_wrp; 
        R_wrp.U8V = stt_MTZO_And14__6_1.U8V;//.Load Elem State
        rU = 0;lV = 0;
        R_wrp.bool_val.bt0 = wrp_mtzo.bool_vars.select_mtzo134_directed;//?wrp_mtzo.bool_vars.in_mtzo_dir_selector;
        R_wrp.bool_val.bt1 = wrp_mtzo.bool_vars.and6_2_1_b7;//?stt_MTZO_And06__2_1.bool_val.bt7;//<= Ask in  reg var
        R_wrp.bool_val.bt2 = wrp_mtzo.bool_vars.m_mtzo134_dir;
        R_wrp.bool_val.bt3 = wrp_mtzo.bool_vars.m_mtzo134_sector_dir;
        R_wrp.bool_val.bt4 = wrp_mtzo.bool_vars.po_mtzo134_dir;//?wrp_mtzo.bool_vars.in_mtzo_stp_dir;
        R_wrp.bool_val.bt5 = wrp_mtzo.bool_vars.or07_2_1_b7;//?stt_MTZO_Or_07__2_1.bool_val.bt7;
        if ((R_wrp.U8V &63) == 63) { 
            
            R_wrp.bool_val.bt7 = 1;
        } 
     

        rU = R_wrp.U8V;//.R_wrp.bool_val.bt7;//

       } while (lV != 0);
         
    
    
     stt_MTZO_And14__6_1.U8V = rU;//R_wrp.U8V;Save Elem State 
     U8_state_wrp R_And15__6_1;
     R_And15__6_1.U8V = stt_MTZO_And15__6_1.U8V ;rU =0;
     R_And15__6_1.bool_val.bt0 = wrp_mtzo.bool_vars.select_mtzo134_directed;
     R_And15__6_1.bool_val.bt1 = wrp_mtzo.bool_vars.and6_2_1_b7;//?stt_MTZO_And06__2_1.bool_val.bt7;
     R_And15__6_1.bool_val.bt2 = wrp_mtzo.bool_vars.m_mtzo134_sector_inv;
     R_And15__6_1.bool_val.bt3 = wrp_mtzo.bool_vars.m_mtzo134_inv;
     R_And15__6_1.bool_val.bt4 = wrp_mtzo.bool_vars.or07_2_1_b7;//?stt_MTZO_Or_07__2_1.bool_val.bt7;//<= Ask in  reg var
     R_And15__6_1.bool_val.bt5 = wrp_mtzo.bool_vars.po_mtzo134_inv;
    if((R_And15__6_1.U8V &63) == 63){
        
        R_And15__6_1.bool_val.bt7 = 1;
    }
    //?rU = R_And15__6_1.bool_val.bt7; //?stt_MTZO_And15__6_1.bool_val.bt7 = rU;//  
    stt_MTZO_And15__6_1.U8V = R_And15__6_1.U8V;
    
    
     U8_state_wrp R_And16__4_1;
    R_And16__4_1.U8V = stt_MTZO_And16__4_1.U8V;
    //?R_And16__4_1.bool_val.bt0 = wrp_mtzo.bool_vars.in_mtzo_stp_u_selector;
    R_And16__4_1.bool_val.bt1 = wrp_mtzo.bool_vars.and6_2_1_b7;//?stt_MTZO_And06__2_1.bool_val.bt7;
    //?.bool_val.bt2 = stt_MTZO_And09__2_1.bool_val.bt7;
    R_And16__4_1.bool_val.bt3 = wrp_mtzo.bool_vars.po_mtzo134_i_pn;
    if((R_And16__4_1.U8V &15) == 15){
        
        R_And16__4_1.bool_val.bt7 = 1;
    }
    //stt_MTZO_And16__4_1.bool_val.bt0 = wrp_mtzo.bool_vars.in_mtzo_stp_u_selector;
    //stt_MTZO_And16__4_1.bool_val.bt1 = stt_MTZO_And06__2_1.bool_val.bt7;
    //stt_MTZO_And16__4_1.bool_val.bt2 = stt_MTZO_And09__2_1.bool_val.bt7;
    //stt_MTZO_And16__4_1.bool_val.bt3 = wrp_mtzo.bool_vars.in_mtzo_stp_u;
    //if((stt_MTZO_And16__4_1.U8V &15) == 15){
    //    
    //    stt_MTZO_And16__4_1.bool_val.bt7 = 1;
    // 
    // 
    // 
    stt_MTZO_And16__4_1.U8V = R_And16__4_1.U8V;
    //return;
    if(glb_ch_id_mtzo == ID_MTZO1){
        unsigned long u32_bit_holder = 0;
        rU = stt_MTZO_And13__3_1.bool_val.bt7;
        if(rU == 0) 
            _CLEAR_BIT(p_active_functions, RNG_BIG_PO_MCZO1);
        else{
            _SET_BIT(p_active_functions, RNG_BIG_PO_MCZO1);
            u32_bit_holder |= 1<< IDX_TMR_MTZO_IN;
        }
        if(stt_MTZO_And14__6_1.bool_val.bt7 != 0){
            _SET_BIT(p_active_functions, RNG_BIG_PO_MCZON1_VPERED);
            u32_bit_holder |= 1<< IDX_TMR_MTZO_IN_N_VPERED;
        }else
            _CLEAR_BIT(p_active_functions, RNG_BIG_PO_MCZON1_VPERED);
        
        if(stt_MTZO_And15__6_1.bool_val.bt7 != 0){
             _SET_BIT(p_active_functions, RNG_BIG_PO_MCZON1_NAZAD);
            u32_bit_holder |= 1<< IDX_TMR_MTZO_IN_N_NAZAD;
        }
        else
            _CLEAR_BIT(p_active_functions, RNG_BIG_PO_MCZON1_NAZAD);
        if(stt_MTZO_And16__4_1.bool_val.bt7 != 0){
            _SET_BIT(p_active_functions, RNG_BIG_PO_MCZOPN1);
            u32_bit_holder |= 1<< IDX_TMR_MTZO_IN_PO_NAPRUZI;
        }
        else
            _CLEAR_BIT(p_active_functions, RNG_BIG_PO_MCZOPN1);
        
        
        //u32_bit_holder = (stt_MTZO_And13__3_1.bool_val.bt7)<< IDX_TMR_MTZO_IN;
        _TIMER_T_0(INDEX_TIMER_MTZO1,sLV.p_current_settings_prt->timeout_mtzo_1[number_group_stp],
        u32_bit_holder,IDX_TMR_MTZO_IN, u32_bit_holder, IDX_TMR_MTZO_OUT);
        //u32_bit_holder = (stt_MTZO_And14__6_1.bool_val.bt7)<< IDX_TMR_MTZO_IN_N_VPERED;
        _TIMER_T_0(INDEX_TIMER_MTZO1_N_VPERED,sLV.p_current_settings_prt->timeout_mtzo_1_n_vpered[number_group_stp],
        u32_bit_holder,IDX_TMR_MTZO_IN_N_VPERED, u32_bit_holder, IDX_TMR_MTZO_OUT_N_VPERED);
        //u32_bit_holder = (stt_MTZO_And15__6_1.bool_val.bt7)<< IDX_TMR_MTZO_IN_N_NAZAD;
        _TIMER_T_0(INDEX_TIMER_MTZO1_N_NAZAD,sLV.p_current_settings_prt->timeout_mtzo_1_n_nazad[number_group_stp],
        u32_bit_holder,IDX_TMR_MTZO_IN_N_NAZAD, u32_bit_holder, IDX_TMR_MTZO_OUT_N_NAZAD);
        //u32_bit_holder = (stt_MTZO_And16__4_1.bool_val.bt7)<< IDX_TMR_MTZO_IN_PO_NAPRUZI;
        _TIMER_T_0(INDEX_TIMER_MTZO1_PO_NAPRUZI,sLV.p_current_settings_prt->timeout_mtzo_1_po_napruzi[number_group_stp],
        u32_bit_holder,IDX_TMR_MTZO_IN_PO_NAPRUZI, u32_bit_holder, IDX_TMR_MTZO_OUT_PO_NAPRUZI);
            
            
        if(u32_bit_holder&( (1<<IDX_TMR_MTZO_OUT)|(1<<IDX_TMR_MTZO_OUT_N_VPERED)
        |(1<<IDX_TMR_MTZO_OUT_N_NAZAD)|(1<<IDX_TMR_MTZO_OUT_PO_NAPRUZI) )){
            _SET_BIT(p_active_functions, RNG_BIG_MCZO1);
        }else{
            _CLEAR_BIT(p_active_functions, RNG_BIG_MCZO1);
            }               
         //!stt_MTZO_Or_17__4_1.bool_val.bt0 = 
         //!stt_MTZO_Or_17__4_1.bool_val.bt1 = 
         //!stt_MTZO_Or_17__4_1.bool_val.bt2 = 
         //!stt_MTZO_Or_17__4_1.bool_val.bt3 = 
    }
    else if(glb_ch_id_mtzo == ID_MTZO3){
        unsigned long u32_bit_holder = 0;
        rU = stt_MTZO_And13__3_1.bool_val.bt7;
        if(rU == 0)
            _CLEAR_BIT(p_active_functions, RNG_BIG_PO_MCZO3);
        else{
            _SET_BIT(p_active_functions, RNG_BIG_PO_MCZO3);
            u32_bit_holder |= 1<< IDX_TMR_MTZO_IN;
        }
        if(stt_MTZO_And14__6_1.bool_val.bt7 != 0){
            _SET_BIT(p_active_functions, RNG_BIG_PO_MCZON3_VPERED);
            u32_bit_holder |= 1<< IDX_TMR_MTZO_IN_N_VPERED;
        }else
            _CLEAR_BIT(p_active_functions, RNG_BIG_PO_MCZON3_VPERED);
        
        if(stt_MTZO_And15__6_1.bool_val.bt7 != 0){
             _SET_BIT(p_active_functions, RNG_BIG_PO_MCZON3_NAZAD);
            u32_bit_holder |= 1<< IDX_TMR_MTZO_IN_N_NAZAD;
        }
        else
            _CLEAR_BIT(p_active_functions, RNG_BIG_PO_MCZON3_NAZAD);
        if(stt_MTZO_And16__4_1.bool_val.bt7 != 0){
            _SET_BIT(p_active_functions, RNG_BIG_PO_MCZOPN3);
            u32_bit_holder |= 1<< IDX_TMR_MTZO_IN_PO_NAPRUZI;
        }
        else
            _CLEAR_BIT(p_active_functions, RNG_BIG_PO_MCZOPN3); 
        //u32_bit_holder = (stt_MTZO_And13__3_1.bool_val.bt7)<< IDX_TMR_MTZO_IN;
        _TIMER_T_0(INDEX_TIMER_MTZO3,sLV.p_current_settings_prt->timeout_mtzo_3[number_group_stp],
        u32_bit_holder,IDX_TMR_MTZO_IN, u32_bit_holder, IDX_TMR_MTZO_OUT);
        //u32_bit_holder = (stt_MTZO_And14__6_1.bool_val.bt7)<< IDX_TMR_MTZO_IN_N_VPERED;
        _TIMER_T_0(INDEX_TIMER_MTZO3_N_VPERED,sLV.p_current_settings_prt->timeout_mtzo_3_n_vpered[number_group_stp],
        u32_bit_holder,IDX_TMR_MTZO_IN_N_VPERED, u32_bit_holder, IDX_TMR_MTZO_OUT_N_VPERED);
        //u32_bit_holder = (stt_MTZO_And15__6_1.bool_val.bt7)<< IDX_TMR_MTZO_IN_N_NAZAD;
        _TIMER_T_0(INDEX_TIMER_MTZO3_N_NAZAD,sLV.p_current_settings_prt->timeout_mtzo_3_n_nazad[number_group_stp],
        u32_bit_holder,IDX_TMR_MTZO_IN_N_NAZAD, u32_bit_holder, IDX_TMR_MTZO_OUT_N_NAZAD);
        //u32_bit_holder = (stt_MTZO_And16__4_1.bool_val.bt7)<< IDX_TMR_MTZO_IN_PO_NAPRUZI;
        _TIMER_T_0(INDEX_TIMER_MTZO3_PO_NAPRUZI,sLV.p_current_settings_prt->timeout_mtzo_3_po_napruzi[number_group_stp],
        u32_bit_holder,IDX_TMR_MTZO_IN_PO_NAPRUZI, u32_bit_holder, IDX_TMR_MTZO_OUT_PO_NAPRUZI);
            
            
        if(u32_bit_holder&( (1<<IDX_TMR_MTZO_OUT)|(1<<IDX_TMR_MTZO_OUT_N_VPERED)
        |(1<<IDX_TMR_MTZO_OUT_N_NAZAD)|(1<<IDX_TMR_MTZO_OUT_PO_NAPRUZI) )){
            _SET_BIT(p_active_functions, RNG_BIG_MCZO3);
        }else{
            _CLEAR_BIT(p_active_functions, RNG_BIG_MCZO3);
            }               
   
            
            //!stt_MTZO_Or_17__4_1.bool_val.bt0 = 
            //!stt_MTZO_Or_17__4_1.bool_val.bt1 = 
            //!stt_MTZO_Or_17__4_1.bool_val.bt2 = 
            //!stt_MTZO_Or_17__4_1.bool_val.bt3 = 
    }
    else if(glb_ch_id_mtzo == ID_MTZO4){
        unsigned long u32_bit_holder = 0;
        rU = stt_MTZO_And13__3_1.bool_val.bt7;
        if(rU == 0)
            _CLEAR_BIT(p_active_functions, RNG_BIG_PO_MCZO4);
        else{
            _SET_BIT(p_active_functions, RNG_BIG_PO_MCZO4);
            u32_bit_holder |= 1<< IDX_TMR_MTZO_IN;
        }
        if(stt_MTZO_And14__6_1.bool_val.bt7 != 0){
            _SET_BIT(p_active_functions, RNG_BIG_PO_MCZON4_VPERED);
            u32_bit_holder |= 1<< IDX_TMR_MTZO_IN_N_VPERED;
        }else
            _CLEAR_BIT(p_active_functions, RNG_BIG_PO_MCZON4_VPERED);
        
        if(stt_MTZO_And15__6_1.bool_val.bt7 != 0){
             _SET_BIT(p_active_functions, RNG_BIG_PO_MCZON4_NAZAD);
            u32_bit_holder |= 1<< IDX_TMR_MTZO_IN_N_NAZAD;
        }
        else
            _CLEAR_BIT(p_active_functions, RNG_BIG_PO_MCZON4_NAZAD);
        if(stt_MTZO_And16__4_1.bool_val.bt7 != 0){
            _SET_BIT(p_active_functions, RNG_BIG_PO_MCZOPN4);
            u32_bit_holder |= 1<< IDX_TMR_MTZO_IN_PO_NAPRUZI;
        }
        else
            _CLEAR_BIT(p_active_functions, RNG_BIG_PO_MCZOPN4); 
        //u32_bit_holder = (stt_MTZO_And13__3_1.bool_val.bt7)<< IDX_TMR_MTZO_IN;
        _TIMER_T_0(INDEX_TIMER_MTZO4,sLV.p_current_settings_prt->timeout_mtzo_4[number_group_stp],
        u32_bit_holder,IDX_TMR_MTZO_IN, u32_bit_holder, IDX_TMR_MTZO_OUT);
        //u32_bit_holder = (stt_MTZO_And14__6_1.bool_val.bt7)<< IDX_TMR_MTZO_IN_N_VPERED;
        _TIMER_T_0(INDEX_TIMER_MTZO4_N_VPERED,sLV.p_current_settings_prt->timeout_mtzo_4_n_vpered[number_group_stp],
        u32_bit_holder,IDX_TMR_MTZO_IN_N_VPERED, u32_bit_holder, IDX_TMR_MTZO_OUT_N_VPERED);
        //u32_bit_holder = (stt_MTZO_And15__6_1.bool_val.bt7)<< IDX_TMR_MTZO_IN_N_NAZAD;
        _TIMER_T_0(INDEX_TIMER_MTZO4_N_NAZAD,sLV.p_current_settings_prt->timeout_mtzo_4_n_nazad[number_group_stp],
        u32_bit_holder,IDX_TMR_MTZO_IN_N_NAZAD, u32_bit_holder, IDX_TMR_MTZO_OUT_N_NAZAD);
       //u32_bit_holder = (stt_MTZO_And16__4_1.bool_val.bt7)<< IDX_TMR_MTZO_IN_PO_NAPRUZI;
        _TIMER_T_0(INDEX_TIMER_MTZO4_PO_NAPRUZI,sLV.p_current_settings_prt->timeout_mtzo_4_po_napruzi[number_group_stp],
        u32_bit_holder,IDX_TMR_MTZO_IN_PO_NAPRUZI, u32_bit_holder, IDX_TMR_MTZO_OUT_PO_NAPRUZI);
            
            
        if(u32_bit_holder&( (1<<IDX_TMR_MTZO_OUT)|(1<<IDX_TMR_MTZO_OUT_N_VPERED)
        |(1<<IDX_TMR_MTZO_OUT_N_NAZAD)|(1<<IDX_TMR_MTZO_OUT_PO_NAPRUZI) )){
            _SET_BIT(p_active_functions, RNG_BIG_MCZO4);
        }else{
            _CLEAR_BIT(p_active_functions, RNG_BIG_MCZO4);
            }               
   
            
            //!stt_MTZO_Or_17__4_1.bool_val.bt0 = 
            //!stt_MTZO_Or_17__4_1.bool_val.bt1 = 
            //!stt_MTZO_Or_17__4_1.bool_val.bt2 = 
            //!stt_MTZO_Or_17__4_1.bool_val.bt3 = 
    }
  

    
}
//
//--------------------------------------------------------------------------------------------------------
static unsigned long u32_bit_mtzo2_ext = 0;
static unsigned int i_max = 0;
U8_state_wrp   stt_MTZO2_And31__4_1, stt_MTZO2_And32__3_1,
               stt_MTZO2_And33__3_1, stt_MTZO2_And34__3_1,
               stt_MTZO2_And35__3_1, stt_MTZO2_And36__3_1,
               stt_MTZO2_And37__3_1, stt_MTZO2_And38__3_1,
               stt_MTZO2_And26__4_1,stt_MTZO2_And27__4_1,
               stt_MTZO2_And28__4_1,stt_MTZO2_And29__4_1,
               stt_MTZO2_And30__4_1;
               
void mtzo2_handler(unsigned int *p_active_functions, unsigned int number_group_stp );
//=====================================================================================================
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//                  
//....................................................................................................
//=====================================================================================================
#pragma optimize=none
void mtzo2_handler(unsigned int *p_active_functions, unsigned int number_group_stp )//{UNUSED(number_group_stp);UNUSED(p_active_functions);
{
  unsigned long rU;
   register U32_mtzo2_wrp R_m_dv_po_mtzo2;
   U32_mtzo2_2wrp R_ms_po_mtzo2;
   
  struct{
      unsigned long po_mtzo_smpl_spt,     po_mtzon_vpered_spt,  po_mtzon_nazad_spt,
       po_u_mtzopn_spt,     po_mtzopn_spt;
  __SETTINGS *p_current_settings_prt;
  }sLV;    
    R_m_dv_po_mtzo2.U32V = 0;
    R_ms_po_mtzo2.U32V = 0;
    U8_state_wrp stt_MTZO_And11__3_1,
    stt_MTZO_And12__6_1,
    stt_MTZO_And13__6_1,
    stt_MTZO_And14__4_1, 
    //stt_MTZO_Or15__5_1,
    stt_MTZO_Or16__5_1,
    
    
    stt_MTZO_Or46__2_1,
    stt_MTZO_OrN52__6_1,
    stt_MTZO_Or51__2_1,
    stt_MTZO_Or44__2_1,
    stt_MTZO_Or53__2_1,
    stt_MTZO_Or55__2_1,
    stt_MTZO_Or42__2_1,
    stt_MTZO_Or57__2_1,
    stt_MTZO_Or39__2_1;
    
    stt_MTZO_And11__3_1.U8V = 0;
    stt_MTZO_And12__6_1.U8V = 0;
    stt_MTZO_And13__6_1.U8V = 0;
    stt_MTZO_And14__4_1.U8V = 0; 
    // stt_MTZO_Or15__5_1.U8V = 0;
     stt_MTZO_Or16__5_1.U8V = 0;
    
    
    stt_MTZO_Or46__2_1.U8V = 0;
    stt_MTZO_OrN52__6_1.U8V = 0;
    stt_MTZO_Or51__2_1.U8V = 0;
    stt_MTZO_Or44__2_1.U8V = 0;
    stt_MTZO_Or53__2_1.U8V = 0;
    stt_MTZO_Or55__2_1.U8V = 0;
    stt_MTZO_Or42__2_1.U8V = 0;
    stt_MTZO_Or57__2_1.U8V = 0;
    stt_MTZO_Or39__2_1.U8V = 0;
    
    
    sLV.p_current_settings_prt = &current_settings_prt ;

   
    rU = sLV.p_current_settings_prt->type_mtzo2;
    if (rU == (TYPE_MTZ_DIRECTIONAL)){
        R_m_dv_po_mtzo2.bool_val.m_select_mtzo2_dir = 1;
    }
    else if(rU == (TYPE_MTZ_VOLTAGE)){
        stt_MTZO_And14__4_1.bool_val.bt0 = 1;//R_m_dv_po_mtzo2.bool_val.m_select_mtzo2_stp_u = 1;
    }
    else if(rU == (TYPE_MTZ_SIMPLE)){
        stt_MTZO_Or16__5_1.bool_val.bt2 = 1;
        //R_m_dv_po_mtzo2.bool_val.m_select_mtzo2_simple = 1;
    }
    else{ 
        switch(rU){
            case TYPE_MTZ_DEPENDENT_A:
            {
                R_ms_po_mtzo2.bool_val.m_select_mtzo2_dep_a = 1;
                R_m_dv_po_mtzo2.bool_val.m_select_mtzo2_dep = 1;
            }
             break;
            case TYPE_MTZ_DEPENDENT_B:
            {
                R_ms_po_mtzo2.bool_val.m_select_mtzo2_dep_b = 1;
                R_m_dv_po_mtzo2.bool_val.m_select_mtzo2_dep = 1;
            }
             break;
            case TYPE_MTZ_DEPENDENT_C:
            {
                R_ms_po_mtzo2.bool_val.m_select_mtzo2_dep_c = 1;
                R_m_dv_po_mtzo2.bool_val.m_select_mtzo2_dep = 1;
            }
             break;
            case TYPE_MTZ_DEPENDENT_RT_80:
            {
                R_ms_po_mtzo2.bool_val.m_select_mtzo2_dep_80 = 1;
                R_m_dv_po_mtzo2.bool_val.m_select_mtzo2_dep  = 1;
            }
             break;
            case TYPE_MTZ_DEPENDENT_RTV_I:
            {
                R_ms_po_mtzo2.bool_val.m_select_mtzo2_dep_81 = 1;
                R_m_dv_po_mtzo2.bool_val.m_select_mtzo2_dep  = 1;
            }
             break;
             
            default:
            ;
        }
    } 
     
    rU = (sLV.p_current_settings_prt->control_mtzo & CTR_MTZO_2) ;
    R_m_dv_po_mtzo2.bool_val.m_mtzo2 = rU!=0;
    rU = (sLV.p_current_settings_prt->control_mtzo & CTR_MTZO_2_VPERED) ;   
    R_m_dv_po_mtzo2.bool_val.m_mtzo2_dir = rU!=0;
    rU = (sLV.p_current_settings_prt->control_mtzo & CTR_MTZO_2_NAZAD) ;
    R_m_dv_po_mtzo2.bool_val.m_mtzo2_inv = rU!=0;
    rU = (sLV.p_current_settings_prt->control_mtzo & CTR_MTZO_2_PRYSKORENA) ;
    R_m_dv_po_mtzo2.bool_val.m_mtzo2_usk  = rU!=0;
    rU = (sLV.p_current_settings_prt->control_mtzo & CTR_MTZO_2_PRYSKORENNJA) ;
    R_m_dv_po_mtzo2.bool_val.m_uskor_mtzo2 = rU!=0;
    
    rU = (_CHECK_SET_BIT(p_active_functions,RNG_BIG_BLOCK_MCZO2 ))!=0;
    //?R_m_dv_po_mtzo2.bool_val.dv_block_mtzo2 = rU!=0;
    R_m_dv_po_mtzo2.bool_val.not04_o_0 = (~rU)&1;
    rU = (_CHECK_SET_BIT(p_active_functions,RNG_BIG_BLOCK_PR_MCZO2 ))!=0;
    //?R_m_dv_po_mtzo2.bool_val.dv_block_usk_mtzo2 = rU!=0;
    R_m_dv_po_mtzo2.bool_val.not17_o_0 = (~rU)&1;
    
   
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    if((sector_directional_mtz[MTZ_LEVEL2][PHASE_MN_INDEX] == MTZ_VPERED)){
        //R_mtzo_po.bool_val.po_mtz_sector_dir = 1;
        stt_MTZO_And12__6_1.bool_val.bt3 = 1;
        _SET_BIT(p_active_functions, RNG_BIG_SECTOR_VPERED_MCZON2);
    }else{ 
        //R_mtzo_po.bool_val.po_mtz_sector_dir = 0;
        _CLEAR_BIT(p_active_functions, RNG_BIG_SECTOR_VPERED_MCZON2);
    }   
    if(sector_directional_mtz[MTZ_LEVEL2][PHASE_MN_INDEX] == MTZ_NAZAD){
        //R_mtzo_po.bool_val.po_mtz_sector_inv = 1;
        stt_MTZO_And13__6_1.bool_val.bt2 = 1;
        _SET_BIT(p_active_functions, RNG_BIG_SECTOR_NAZAD_MCZON2);
    }else{
        //R_mtzo_po.bool_val.po_mtz_sector_inv = 0;
        _CLEAR_BIT(p_active_functions, RNG_BIG_SECTOR_NAZAD_MCZON2);
    }
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZO2);
        //if(R_mtzo_po.bool_val.po_mtz_simple == 1 ) {
        if( rU!= 0) {
            sLV.po_mtzo_smpl_spt = sLV.p_current_settings_prt->setpoint_mtzo_2[number_group_stp]
         * KOEF_POVERNENNJA_MTZ_I_UP / 100;
        }else{
           sLV.po_mtzo_smpl_spt = sLV.p_current_settings_prt->setpoint_mtzo_2[number_group_stp]; 
        }
        //
        if(measurement[IM_Imn] >= sLV.po_mtzo_smpl_spt)
            stt_MTZO_And11__3_1.bool_val.bt1 = 1;

        //else    
        //    stt_MTZO_And11__3_1.bool_val.bt1 = 0;
        rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZON2_VPERED);
        if( rU!= 0) {
            sLV.po_mtzon_vpered_spt = sLV.p_current_settings_prt->setpoint_mtzo_2_n_vpered[number_group_stp]
         * KOEF_POVERNENNJA_MTZ_I_UP / 100;
        }else{
           sLV.po_mtzon_vpered_spt = sLV.p_current_settings_prt->setpoint_mtzo_2_n_vpered[number_group_stp]; 
        }
        //
        if(measurement[IM_Imn] >= sLV.po_mtzon_vpered_spt)
            stt_MTZO_And12__6_1.bool_val.bt4 = 1;
        //else    
        //    R_mtzo_po.bool_val.po_mtz_dir = 0;
        //
        rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZON1_NAZAD);
        if( rU!= 0) {
            sLV.po_mtzon_nazad_spt = sLV.p_current_settings_prt->setpoint_mtzo_2_n_nazad[number_group_stp]
         * KOEF_POVERNENNJA_MTZ_I_UP / 100;
        }else{
           sLV.po_mtzon_nazad_spt = sLV.p_current_settings_prt->setpoint_mtzo_2_n_nazad[number_group_stp]; 
        }
        if(measurement[IM_Imn] >= sLV.po_mtzon_nazad_spt)
            stt_MTZO_And13__6_1.bool_val.bt4 = 1;
//        else    
//            R_mtzo_po.bool_val.po_mtz_inv = 0;
        rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZOPN2);
        if( rU!= 0 ) {
            sLV.po_u_mtzopn_spt = sLV.p_current_settings_prt->setpoint_mtzo_2_U[number_group_stp] * U_DOWN / 100;
            sLV.po_mtzopn_spt = sLV.p_current_settings_prt->setpoint_mtzo_2_po_napruzi[number_group_stp] * KOEF_POVERNENNJA_MTZ_I_UP / 100;
        }else{
           sLV.po_u_mtzopn_spt = sLV.p_current_settings_prt->setpoint_mtzo_2_U[number_group_stp]; 
           sLV.po_mtzopn_spt = sLV.p_current_settings_prt->setpoint_mtzo_2_po_napruzi[number_group_stp]; 
        }
        if(measurement[IM_Umn] <= sLV.po_u_mtzopn_spt){
            R_m_dv_po_mtzo2.bool_val.po_mtzo2_u  = 1;
            _SET_BIT(p_active_functions, RNG_BIG_PO_BLK_U_OSN_LESS_UST_MCZO2);
        }else{
            //R_m_dv_po_mtzo2.bool_val.po_mtzo2_u  = 0;
            _CLEAR_BIT(p_active_functions, RNG_BIG_PO_BLK_U_OSN_LESS_UST_MCZO2);
        }
        if(measurement[IM_Imn] >= sLV.po_mtzopn_spt)
            stt_MTZO_And14__4_1.bool_val.bt3 = 1;
        //else    
        //    R_mtzo_po.bool_val.po_mtz_pn = 0;
        
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    U8_state_wrp R_wrp;
    R_wrp.U8V = 0;
    rU = (_CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZON2_VPERED))!=0;
    R_wrp.bool_val.bt0 =  rU;//?R_m_dv_po_mtzo2.bool_val.cmd_mtzo2_dir = rU;
    rU = (_CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZON2_NAZAD))!=0;
    R_wrp.bool_val.bt1 =  rU;//?R_m_dv_po_mtzo2.bool_val.cmd_mtzo2_inv = rU;
    rU = (_CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZOPN2))!=0;
    R_wrp.bool_val.bt2 =  rU;//?R_m_dv_po_mtzo2.bool_val.cmd_mtzo2_stp_u = rU;
    //or1
    if ((R_wrp.U8V &7) != 0)
        R_ms_po_mtzo2.bool_val.or01_o_0 = rU = 1;
    //not2
    R_ms_po_mtzo2.bool_val.not02_o_0 = (~rU)&1;
    
    //and3
    rU = (_CHECK_SET_BIT(p_active_functions, RNG_BIG_NCN_MCZO))!=0;
    //?R_m_dv_po_mtzo2.bool_val.cmd_nkn_mtzo = rU;
    if(R_ms_po_mtzo2.bool_val.not02_o_0 &&rU!= 0)
        R_ms_po_mtzo2.bool_val.and03_o_0 = 1;//cmd_nkn_mtzo2

    //or1
    //.rU = R_m_dv_po_mtzo2.U32V &( (1<<22)|(1<<23)|(1<<24));
    //.if( rU!= 0) 
    //.    R_ms_po_mtzo2.bool_val.or01_o_0 = rU = 1;
    //.
    //.R_ms_po_mtzo2.bool_val.not02_o_0 = (~rU)&1;
    //.rU <<=1;
    //.rU |= R_m_dv_po_mtzo2.bool_val.cmd_nkn_mtzo;
    //.if((rU&3) == 3)
    //.    R_ms_po_mtzo2.bool_val.and03_o_0 = 1;
    
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    //?rU = R_m_dv_po_mtzo2.bool_val.dv_block_mtzo2;
    //?R_m_dv_po_mtzo2.bool_val.not04_o_0 = (~rU)&1;
    //And6
    rU = R_m_dv_po_mtzo2.U32V &( (1<<0)|(1<<13));//m_mtzo2 not04_o_0
    if(rU == ((1<<0)|(1<<13)))
        R_m_dv_po_mtzo2.bool_val.and06_o_0 = 1;
    //not5
    rU = R_ms_po_mtzo2.bool_val.and03_o_0;
    R_m_dv_po_mtzo2.bool_val.not05_o_0 = (~rU)&1;
    //orn7
    rU = (_CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_BLK_U_OSN_LESS_0_05UN_MCZO))!=0;
    rU <<=1;
    rU |=  R_ms_po_mtzo2.bool_val.and03_o_0;
    if(rU == 0)
        R_m_dv_po_mtzo2.bool_val.orN07_o_0 = 1;
    
    //and08_o_0 po_mtzo2_u not05_o_0
    //.rU = R_m_dv_po_mtzo2.bool_val.po_mtzo2_u;
    //.rU <<=1;
    //.rU |=  R_m_dv_po_mtzo2.bool_val.not05_o_0;
    //.if(rU&3 == 3){//!Errr in Evaluation
    rU = R_m_dv_po_mtzo2.U32V &( (1<<12)|(1<<26));//po_mtzo2_u not05_o_0;
    if(rU == ((1<<12)|(1<<26)))//and08_o_0 po_mtzo2_u not05_o_0
	{
        //R_ms_po_mtzo2.bool_val.and08_o_0 = 1;
        stt_MTZO_And14__4_1.bool_val.bt2 = 1;
    }
    //and10_o_
    rU = R_m_dv_po_mtzo2.bool_val.orN07_o_0;
    //R_ms_po_mtzo2.bool_val.not09_o_0 = (~rU)&1;
    //rU =  (~rU)&1;//not09_o_0
    R_m_dv_po_mtzo2.bool_val.b4 =  (~rU)&1;//not09_o_0
    //rU <<=1;
    //rU |=  R_m_dv_po_mtzo2.bool_val.m_select_mtzo2_dir;
    //if(rU&3 == 3)
	rU = R_m_dv_po_mtzo2.U32V &( (1<<4)|(1<<3));//b4 m_select_mtzo2_dir
    if(rU == ((1<<4)|(1<<3)))	
        stt_MTZO_Or16__5_1.bool_val.bt0 = 1;//R_ms_po_mtzo2.bool_val.and10_o_0 = 1;
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    //or15 R_m_dv_po_mtzo2.bool_val.m_select_mtzo2_dep 
//?    rU = R_ms_po_mtzo2.U32V &(unsigned long)( (1<<27)|(1<<28)|(1<<29)|(1<<30)|(1<<31));
//?    if(rU != 0){
//?        R_m_dv_po_mtzo2.bool_val.or15_o_0 = 1;
//?        
//?    }
    
    //or16
    //.U8_state_wrp R_wrp;
    R_wrp.U8V = stt_MTZO_Or16__5_1.U8V;
    //.R_wrp.bool_val.bt0 = R_ms_po_mtzo2.bool_val.and10_o_0;
    rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZO2);
    R_wrp.bool_val.bt1 = rU!=0;	
    //TYPE_MTZ_SIMPLE stt_MTZO_Or16__5_1.bool_val.bt2 = 1;
    R_wrp.bool_val.bt3 = R_m_dv_po_mtzo2.bool_val.m_select_mtzo2_dep;//R_m_dv_po_mtzo2.bool_val.or15_o_0;
    R_wrp.bool_val.bt4 = R_ms_po_mtzo2.bool_val.and03_o_0;
    if((R_wrp.U8V &31) != 0){
        stt_MTZO_And11__3_1.bool_val.bt0 = 1;
    }
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    //and 11 
    //stt_MTZO_And11__3_1.bool_val.bt1 = 1; set early;   <<bt0>>|^
    stt_MTZO_And11__3_1.bool_val.bt2 = R_m_dv_po_mtzo2.bool_val.and06_o_0;
    if((stt_MTZO_And11__3_1.U8V &7) == 7){
        _SET_BIT(p_active_functions, RNG_BIG_PO_MCZO2);
        stt_MTZO_And11__3_1.bool_val.bt7 = 1;
        R_m_dv_po_mtzo2.bool_val.po_mtzo2_simple = 1;
    }else{
        
        _CLEAR_BIT(p_active_functions, RNG_BIG_PO_MCZO2);
    }
    
    rU = R_m_dv_po_mtzo2.bool_val.m_select_mtzo2_dir;
    stt_MTZO_And12__6_1.bool_val.bt0 = rU;
    stt_MTZO_And13__6_1.bool_val.bt0 = rU;
    rU = R_m_dv_po_mtzo2.bool_val.and06_o_0;
    stt_MTZO_And12__6_1.bool_val.bt1 = rU;
    stt_MTZO_And13__6_1.bool_val.bt1 = rU;
    stt_MTZO_And14__4_1.bool_val.bt1 = rU;
    //and12
    stt_MTZO_And12__6_1.bool_val.bt2 = R_m_dv_po_mtzo2.bool_val.m_mtzo2_dir;
    //stt_MTZO_And12__6_1..bt3 = must be setup were SECTOR_VPERED_MCZON2 sets
    //stt_MTZO_And12__6_1.bt4 = must be setup were (measurement[IM_Imn] >= sLV.po_mtzon_vpered_spt
    rU = R_m_dv_po_mtzo2.bool_val.orN07_o_0;
    stt_MTZO_And12__6_1.bool_val.bt5 = rU;
    stt_MTZO_And13__6_1.bool_val.bt5 = rU;
//?    stt_MTZO_And14__4_1.bool_val.bt1 = rU;
    if( (stt_MTZO_And12__6_1.U8V &63) == 63){
        stt_MTZO_And12__6_1.bool_val.bt7 = 1;
        _SET_BIT(p_active_functions,RNG_BIG_PO_MCZON2_VPERED );
        R_m_dv_po_mtzo2.bool_val.po_dir_mtzo2 = 1;
    }else{
        _CLEAR_BIT(p_active_functions,RNG_BIG_PO_MCZON2_VPERED);
    }
    
    //and13
    //.stt_MTZO_And13__6_1.bool_val.bt5 = rU;
    //bt2 = must be setup were RNG_BIG_SECTOR_NAZAD_MCZON2
    stt_MTZO_And13__6_1.bool_val.bt3 = rU = R_m_dv_po_mtzo2.bool_val.m_mtzo2_inv;
    //bt4 = must be setup were measurement[IM_Imn] >= sLV.po_mtzon_nazad_spt
    
    if( (stt_MTZO_And13__6_1.U8V &63) == 63){
        stt_MTZO_And13__6_1.bool_val.bt7 = 1;
        _SET_BIT(p_active_functions, RNG_BIG_PO_MCZON2_NAZAD);
        R_m_dv_po_mtzo2.bool_val.po_inv_mtzo2 = 1;
    }else{
        _CLEAR_BIT(p_active_functions,RNG_BIG_PO_MCZON2_NAZAD);
    }
    
    //and14
    //.stt_MTZO_And14__4_1.bool_val.bt0 = .p_current_settings_prt->type_mtzo2==rU = sLV.p_current_settings_prt->type_mtzo2;;
    //?stt_MTZO_And14__4_1.bool_val.bt2 = R_m_dv_po_mtzo2.bool_val.and08_o_0; Ln 1136
    //.bt3 = must be setup were measurement[IM_Imn] >= sLV.po_mtzopn_spt) Ln1075
	//stt_MTZO_And14__4_1.bool_val.bt1 = rU; Ln 1136
    if( (stt_MTZO_And14__4_1.U8V &15) == 15){
        stt_MTZO_And14__4_1.bool_val.bt7 = 1;
        _SET_BIT(p_active_functions,RNG_BIG_PO_MCZOPN2 );
        R_m_dv_po_mtzo2.bool_val.po_mtzo2_i = 1;
    }else{
        _CLEAR_BIT(p_active_functions,RNG_BIG_PO_MCZOPN2);
    }
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    //rU = R_m_dv_po_mtzo2.bool_val
    unsigned long u32_bit_holder = 0;
    rU = (_CHECK_SET_BIT(p_active_functions, RNG_BIG_BLOCK_PR_MCZO2))!=0;
    R_m_dv_po_mtzo2.bool_val.not17_o_0 = (~rU)&1;
    
    rU = (_CHECK_SET_BIT(p_active_functions, RNG_BIG_STATE_VVO))!=0;
    rU <<=1;
    rU |= R_m_dv_po_mtzo2.bool_val.m_uskor_mtzo2;
	rU &= 3;
    if((rU) == 3){
        //?R_m_dv_po_mtzo2.bool_val.and19_o_0 = 1;
        u32_bit_holder |= 1<< IDX_TMR_MTZO_IN_VVID_PR;
    }else{
        
    }
    _TIMER_IMPULSE(INDEX_TIMER_MTZO2_VVID_PR, 
    current_settings_prt.timeout_mtzo_2_vvid_pr[number_group_stp], 
    u32_bit_mtzo2_ext, IDX_TMR_MTZO_IN_VVID_PR, u32_bit_holder, IDX_TMR_MTZO_IN_VVID_PR, u32_bit_holder, IDX_TMR_MTZO_OUT_VVID_PR);
    if( (u32_bit_holder&(1<<IDX_TMR_MTZO_OUT_VVID_PR)) != 0)
        R_m_dv_po_mtzo2.bool_val.out_t_vvoda_usk = 1;
    
    // m_mtzo2_usk  out_t_vvoda_usk 
    rU = R_m_dv_po_mtzo2.U32V &( (1<<29)|(1<<18));
    if(rU != 0)
        R_m_dv_po_mtzo2.bool_val.or18_o_0 = 1;
    //or18_o_0 not17_o_0
    
    rU = R_m_dv_po_mtzo2.U32V &( (1<<16)|(1<<17));
    if(rU == ((1<<16)|(1<<17))){
        R_m_dv_po_mtzo2.bool_val.and20_o_0 = 1;
        R_ms_po_mtzo2.bool_val.and20_copy = 1;
        
    }
    //not50
    rU = R_m_dv_po_mtzo2.bool_val.and20_o_0;
    R_m_dv_po_mtzo2.bool_val.not50_o_0 = (~rU)&1;
    
    
//?    rU = stt_MTZO2_And31__3_1.bool_val.bt7;
//?    R_ms_po_mtzo2.bool_val.not21_o_0 = (~rU)&1;
//?    stt_MTZO_Or45__2_1.bool_val.bt1 = rU;
//?    
//?    rU = stt_MTZO2_And34__3_1.bool_val.bt7;
//?    R_ms_po_mtzo2.bool_val.not44_o_0 = (~rU)&1;
//?    stt_MTZO_Or43__2_1.bool_val.bt0 = rU;
//?    
//?    rU = stt_MTZO2_And36__3_1.bool_val.bt7;
//?    R_ms_po_mtzo2.bool_val.not42_o_0 = (~rU)&1;
//?    stt_MTZO_Or41__2_1.bool_val.bt0 = rU;
//?    
//?    rU = stt_MTZO2_And38__3_1.bool_val.bt7;
//?    R_ms_po_mtzo2.bool_val.not40_o_0 = (~rU)&1;
//?    stt_MTZO_Or39__2_1.bool_val.bt0 = rU;


    
//?    rU = R_ms_po_mtzo2.bool_val.and20_copy;
//?    stt_MTZO_Or45__2_1.bool_val.bt0 = rU;
//? stt_MTZO_Or43__2_1.bool_val.bt1 = rU;
//? stt_MTZO_Or41__2_1.bool_val.bt1 = rU;
//? stt_MTZO_Or39__2_1.bool_val.bt1 = rU;
//? if((stt_MTZO_Or45__2_1.U8V &3) != 0)
//?     stt_MTZO_Or45__2_1.bool_val.bt7 = 1;
//? if((stt_MTZO_Or43__2_1.U8V &3) != 0)
//?     stt_MTZO_Or43__2_1.bool_val.bt7 = 1;
//? if((stt_MTZO_Or41__2_1.U8V &3) != 0)
//?     stt_MTZO_Or41__2_1.bool_val.bt7 = 1;
//? if((stt_MTZO_Or39__2_1.U8V &3) != 0)
//?     stt_MTZO_Or39__2_1.bool_val.bt7 = 1;

    rU = stt_MTZO2_And26__4_1.bool_val.bt7;
    stt_MTZO_OrN52__6_1.bool_val.bt5 = rU;
    rU = stt_MTZO2_And27__4_1.bool_val.bt7;
    stt_MTZO_OrN52__6_1.bool_val.bt4 = rU;
    rU = stt_MTZO2_And28__4_1.bool_val.bt7;
    stt_MTZO_OrN52__6_1.bool_val.bt3 = rU;
    rU = stt_MTZO2_And29__4_1.bool_val.bt7;
    stt_MTZO_OrN52__6_1.bool_val.bt2 = rU;
    rU = stt_MTZO2_And30__4_1.bool_val.bt7;
    stt_MTZO_OrN52__6_1.bool_val.bt1 = rU;

    rU = stt_MTZO2_And31__4_1.bool_val.bt7; //..31
    stt_MTZO_Or51__2_1.bool_val.bt1 = rU;
    stt_MTZO_OrN52__6_1.bool_val.bt0 = rU;
    // Eval52
    if ((stt_MTZO_OrN52__6_1.U8V & 63) == 0)
        stt_MTZO_OrN52__6_1.bool_val.bt7 = 1;
    // Eval 51
    stt_MTZO_Or51__2_1.bool_val.bt0 = R_m_dv_po_mtzo2.bool_val.not50_o_0;
    if ((stt_MTZO_Or51__2_1.U8V & 3) != 0)
        stt_MTZO_Or51__2_1.bool_val.bt7 = 1;
    // Eval 48
    rU = R_m_dv_po_mtzo2.bool_val.m_select_mtzo2_dep;
    R_ms_po_mtzo2.bool_val.not48_o_0 = (~rU) & 1;

    rU = stt_MTZO2_And32__3_1.bool_val.bt7; //..32
    // Eval 47
    R_ms_po_mtzo2.bool_val.not47_o_0 = (~rU) & 1;
    stt_MTZO_Or46__2_1.bool_val.bt0 = rU;
    // Eval 46
    stt_MTZO_Or46__2_1.bool_val.bt1 = R_m_dv_po_mtzo2.bool_val.and20_o_0;
    if ((stt_MTZO_Or46__2_1.U8V & 3) != 0)
        stt_MTZO_Or46__2_1.bool_val.bt7 = 1;
    //EvalAnd26
    stt_MTZO2_And26__4_1.bool_val.bt0 = R_m_dv_po_mtzo2.bool_val.not50_o_0;
    stt_MTZO2_And26__4_1.bool_val.bt1 = R_ms_po_mtzo2.bool_val.not47_o_0;
    stt_MTZO2_And26__4_1.bool_val.bt2 = R_ms_po_mtzo2.bool_val.m_select_mtzo2_dep_a;
    stt_MTZO2_And26__4_1.bool_val.bt3 = R_m_dv_po_mtzo2.bool_val.po_mtzo2_simple;
    if ((stt_MTZO2_And26__4_1.U8V & 15) == 15)
        stt_MTZO2_And26__4_1.bool_val.bt7 = 1;

    //EvalAnd27
    stt_MTZO2_And27__4_1.bool_val.bt0 = R_m_dv_po_mtzo2.bool_val.not50_o_0;
    stt_MTZO2_And27__4_1.bool_val.bt1 = R_ms_po_mtzo2.bool_val.not47_o_0;
    stt_MTZO2_And27__4_1.bool_val.bt2 = R_ms_po_mtzo2.bool_val.m_select_mtzo2_dep_b;
    stt_MTZO2_And27__4_1.bool_val.bt3 = R_m_dv_po_mtzo2.bool_val.po_mtzo2_simple;
    if ((stt_MTZO2_And27__4_1.U8V & 15) == 15)
        stt_MTZO2_And27__4_1.bool_val.bt7 = 1;
    //EvalAnd28
    stt_MTZO2_And28__4_1.bool_val.bt0 = R_m_dv_po_mtzo2.bool_val.not50_o_0;
    stt_MTZO2_And28__4_1.bool_val.bt1 = R_ms_po_mtzo2.bool_val.not47_o_0;
    stt_MTZO2_And28__4_1.bool_val.bt2 = R_ms_po_mtzo2.bool_val.m_select_mtzo2_dep_c;
    stt_MTZO2_And28__4_1.bool_val.bt3 = R_m_dv_po_mtzo2.bool_val.po_mtzo2_simple;
    if ((stt_MTZO2_And28__4_1.U8V & 15) == 15)
        stt_MTZO2_And28__4_1.bool_val.bt7 = 1;
    //EvalAnd29
    stt_MTZO2_And29__4_1.bool_val.bt0 = R_m_dv_po_mtzo2.bool_val.not50_o_0;
    stt_MTZO2_And29__4_1.bool_val.bt1 = R_ms_po_mtzo2.bool_val.not47_o_0;
    stt_MTZO2_And29__4_1.bool_val.bt2 = R_ms_po_mtzo2.bool_val.m_select_mtzo2_dep_80;
    stt_MTZO2_And29__4_1.bool_val.bt3 = R_m_dv_po_mtzo2.bool_val.po_mtzo2_simple;
    if ((stt_MTZO2_And29__4_1.U8V & 15) == 15)
        stt_MTZO2_And29__4_1.bool_val.bt7 = 1;
    //EvalAnd30
    stt_MTZO2_And30__4_1.bool_val.bt0 = R_m_dv_po_mtzo2.bool_val.not50_o_0;
    stt_MTZO2_And30__4_1.bool_val.bt1 = R_ms_po_mtzo2.bool_val.not47_o_0;
    stt_MTZO2_And30__4_1.bool_val.bt2 = R_ms_po_mtzo2.bool_val.m_select_mtzo2_dep_81;
    stt_MTZO2_And30__4_1.bool_val.bt3 = R_m_dv_po_mtzo2.bool_val.po_mtzo2_simple;
    if ((stt_MTZO2_And30__4_1.U8V & 15) == 15)
        stt_MTZO2_And30__4_1.bool_val.bt7 = 1;

    //EvalAnd31
    stt_MTZO2_And31__4_1.bool_val.bt0 = R_ms_po_mtzo2.bool_val.not48_o_0;
    stt_MTZO2_And31__4_1.bool_val.bt1 = stt_MTZO_Or51__2_1.bool_val.bt7;
    stt_MTZO2_And31__4_1.bool_val.bt2 = R_ms_po_mtzo2.bool_val.not47_o_0;
    stt_MTZO2_And31__4_1.bool_val.bt3 = R_m_dv_po_mtzo2.bool_val.po_mtzo2_simple;
    if ((stt_MTZO2_And31__4_1.U8V & 15) == 15)
        stt_MTZO2_And31__4_1.bool_val.bt7 = 1;
    else
        stt_MTZO2_And31__4_1.bool_val.bt7 = 0;
	
	//EvalAnd32
    stt_MTZO2_And32__3_1.bool_val.bt0 = R_m_dv_po_mtzo2.bool_val.po_mtzo2_simple;
    stt_MTZO2_And32__3_1.bool_val.bt1 = stt_MTZO_Or46__2_1.bool_val.bt7;
    stt_MTZO2_And32__3_1.bool_val.bt2 = stt_MTZO_OrN52__6_1.bool_val.bt7;
    if ((stt_MTZO2_And32__3_1.U8V & 7) == 7)
        stt_MTZO2_And32__3_1.bool_val.bt7 = 1;
    else
        stt_MTZO2_And32__3_1.bool_val.bt7 = 0;

    // Take 33
    rU = stt_MTZO2_And33__3_1.bool_val.bt7; //..33
    stt_MTZO_Or53__2_1.bool_val.bt1 = rU;
    R_ms_po_mtzo2.bool_val.not54_o_0 = (~rU) & 1;
    // Take 34
    rU = stt_MTZO2_And34__3_1.bool_val.bt7; //..34
    stt_MTZO_Or44__2_1.bool_val.bt0 = rU;
    R_ms_po_mtzo2.bool_val.not45_o_0 = (~rU) & 1;
    // Eval 53
    stt_MTZO_Or53__2_1.bool_val.bt0 = R_m_dv_po_mtzo2.bool_val.not50_o_0;
    if ((stt_MTZO_Or53__2_1.U8V & 3) != 0)
        stt_MTZO_Or53__2_1.bool_val.bt7 = 1;
    // Eval 54
    // Eval 45
    // Eval 44
    stt_MTZO_Or44__2_1.bool_val.bt1 = R_m_dv_po_mtzo2.bool_val.and20_o_0;
    if ((stt_MTZO_Or44__2_1.U8V & 3) != 0)
        stt_MTZO_Or44__2_1.bool_val.bt7 = 1;

    // EvalAnd33
    stt_MTZO2_And33__3_1.bool_val.bt0 = stt_MTZO_Or53__2_1.bool_val.bt7;
    stt_MTZO2_And33__3_1.bool_val.bt1 = R_ms_po_mtzo2.bool_val.not45_o_0;
    stt_MTZO2_And33__3_1.bool_val.bt2 = R_m_dv_po_mtzo2.bool_val.po_dir_mtzo2;
    if ((stt_MTZO2_And33__3_1.U8V & 7) == 7)
        stt_MTZO2_And33__3_1.bool_val.bt7 = 1;
    else
        stt_MTZO2_And33__3_1.bool_val.bt7 = 0;

    //EvalAnd34
    stt_MTZO2_And34__3_1.bool_val.bt0 = R_m_dv_po_mtzo2.bool_val.po_dir_mtzo2;
    stt_MTZO2_And34__3_1.bool_val.bt1 = stt_MTZO_Or44__2_1.bool_val.bt7;
    stt_MTZO2_And34__3_1.bool_val.bt2 = R_ms_po_mtzo2.bool_val.not54_o_0;
    if ((stt_MTZO2_And34__3_1.U8V & 7) == 7)
        stt_MTZO2_And34__3_1.bool_val.bt7 = 1;
    else
        stt_MTZO2_And34__3_1.bool_val.bt7 = 0;

    //Take 35
	rU = stt_MTZO2_And35__3_1.bool_val.bt7;//..35
    stt_MTZO_Or55__2_1.bool_val.bt1 = rU;
    R_ms_po_mtzo2.bool_val.not56_o_0 = (~rU)&1;
    //Take 36 
	rU = stt_MTZO2_And36__3_1.bool_val.bt7;//..36
    stt_MTZO_Or42__2_1.bool_val.bt0 = rU;
    R_ms_po_mtzo2.bool_val.not43_o_0 = (~rU)&1;
	//Eval 55
    stt_MTZO_Or55__2_1.bool_val.bt0 = R_m_dv_po_mtzo2.bool_val.not50_o_0;
    if ((stt_MTZO_Or55__2_1.U8V & 3) != 0)
        stt_MTZO_Or55__2_1.bool_val.bt7 = 1;
    // Eval 56
    // Eval 43

    // Eval 42
    stt_MTZO_Or42__2_1.bool_val.bt1 = R_m_dv_po_mtzo2.bool_val.and20_o_0;
    if ((stt_MTZO_Or42__2_1.U8V & 3) != 0)
        stt_MTZO_Or42__2_1.bool_val.bt7 = 1;

    // Take 37
    rU = stt_MTZO2_And37__3_1.bool_val.bt7; //..37
    stt_MTZO_Or57__2_1.bool_val.bt1 = rU;
    R_ms_po_mtzo2.bool_val.not58_o_0 = (~rU) & 1;
    // Take 38
    rU = stt_MTZO2_And38__3_1.bool_val.bt7; //..38
    stt_MTZO_Or39__2_1.bool_val.bt0 = rU;
    R_ms_po_mtzo2.bool_val.not40_o_0 = (~rU) & 1;
    // Eval 57
    stt_MTZO_Or57__2_1.bool_val.bt0 = R_m_dv_po_mtzo2.bool_val.not50_o_0;
    if ((stt_MTZO_Or57__2_1.U8V & 3) != 0)
        stt_MTZO_Or57__2_1.bool_val.bt7 = 1;
    // Eval 58

    // Eval 40
    // Eval 39
    stt_MTZO_Or39__2_1.bool_val.bt0 = R_m_dv_po_mtzo2.bool_val.and20_o_0;
    if ((stt_MTZO_Or39__2_1.U8V & 3) != 0)
        stt_MTZO_Or39__2_1.bool_val.bt7 = 1;

    // EvalAnd35
    stt_MTZO2_And35__3_1.bool_val.bt0 = stt_MTZO_Or55__2_1.bool_val.bt7;
    stt_MTZO2_And35__3_1.bool_val.bt1 = R_ms_po_mtzo2.bool_val.not43_o_0;
    stt_MTZO2_And35__3_1.bool_val.bt2 = R_m_dv_po_mtzo2.bool_val.po_inv_mtzo2;
    if ((stt_MTZO2_And35__3_1.U8V & 7) == 7)
        stt_MTZO2_And35__3_1.bool_val.bt7 = 1;
    else
        stt_MTZO2_And35__3_1.bool_val.bt7 = 0;

    //EvalAnd36
    stt_MTZO2_And36__3_1.bool_val.bt0 = R_m_dv_po_mtzo2.bool_val.po_inv_mtzo2;
    stt_MTZO2_And36__3_1.bool_val.bt1 = stt_MTZO_Or42__2_1.bool_val.bt7;
    stt_MTZO2_And36__3_1.bool_val.bt2 = R_ms_po_mtzo2.bool_val.not56_o_0;
    if ((stt_MTZO2_And36__3_1.U8V & 7) == 7)
        stt_MTZO2_And36__3_1.bool_val.bt7 = 1;
    else
        stt_MTZO2_And36__3_1.bool_val.bt7 = 0;

    // EvalAnd37
    stt_MTZO2_And37__3_1.bool_val.bt0 = stt_MTZO_Or57__2_1.bool_val.bt7;
    stt_MTZO2_And37__3_1.bool_val.bt1 = R_ms_po_mtzo2.bool_val.not40_o_0;
    stt_MTZO2_And37__3_1.bool_val.bt2 = R_m_dv_po_mtzo2.bool_val.po_mtzo2_i;
    if ((stt_MTZO2_And37__3_1.U8V & 7) == 7)
        stt_MTZO2_And37__3_1.bool_val.bt7 = 1;
    else
        stt_MTZO2_And37__3_1.bool_val.bt7 = 0;

    // EvalAnd38
    stt_MTZO2_And38__3_1.bool_val.bt0 = R_m_dv_po_mtzo2.bool_val.po_mtzo2_i;
    stt_MTZO2_And38__3_1.bool_val.bt1 = stt_MTZO_Or39__2_1.bool_val.bt7;
    stt_MTZO2_And38__3_1.bool_val.bt2 = R_ms_po_mtzo2.bool_val.not58_o_0;
    if ((stt_MTZO2_And38__3_1.U8V & 7) == 7)
        stt_MTZO2_And38__3_1.bool_val.bt7 = 1;
    else
        stt_MTZO2_And38__3_1.bool_val.bt7 = 0;

    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
     u32_bit_holder = 0;
    if(stt_MTZO_And11__3_1.bool_val.bt7 == 1){    
        i_max = measurement[IM_Imn];
        if (i_max < measurement[IM_Imn]) i_max = measurement[IM_Imn];
//.        if(R_ms_po_mtzo2.bool_val.not21_o_0 != 0 )  
//.            u32_bit_holder |= IDX_TMR_MTZO_IN_DEPENDENT;
        rU |= stt_MTZO2_And26__4_1.bool_val.bt7 << 0;
        rU |= stt_MTZO2_And27__4_1.bool_val.bt7 << 1;
        rU |= stt_MTZO2_And28__4_1.bool_val.bt7 << 2;
        rU |= stt_MTZO2_And29__4_1.bool_val.bt7 << 3;
        rU |= stt_MTZO2_And30__4_1.bool_val.bt7 << 4;
        if (rU != 0)
                u32_bit_holder |= IDX_TMR_MTZO_IN_DEPENDENT;
    }   
    _TIMER_T_0_LOCK(INDEX_TIMER_MTZO2_DEPENDENT, timeout_dependent_general(i_max, sLV.p_current_settings_prt->setpoint_mtzo_2[number_group_stp],
    sLV.p_current_settings_prt->timeout_mtzo_2[number_group_stp], TIMEOUT_MTZ2_MAX, sLV.p_current_settings_prt->type_mtzo2), u32_bit_holder, IDX_TMR_MTZO_IN_DEPENDENT,u32_bit_holder, IDX_TMR_MTZO_OUT_DEPENDENT);//
    
//?    rU = R_m_dv_po_mtzo2.bool_val.or15_o_0;
//?//    R_ms_po_mtzo2.bool_val.not39_o_0 = (~rU)&1;<<== Old Code
//?    R_ms_po_mtzo2.bool_val.not46_o_0 = (~rU)&1;
//?
//?
//?    rU = stt_MTZO_And11__3_1.bool_val.bt7;//#BR PO MTZO
//?    rU <<=1;
//?    rU |= R_ms_po_mtzo2.bool_val.not21_o_0;
//?    rU <<=1;
//?    rU |= R_ms_po_mtzo2.bool_val.not46_o_0;
//?    //R_m_dv_po_mtzo2.bool_val.or15_o_0;
//?    if((rU&7) == 7){//not39_o_0 not21_o_0
//?        u32_bit_holder |= 1<< IDX_TMR_MTZO_IN               ;
//?        //R_ms_po_mtzo2.bool_val.and32_o_0 = 1;
//?    }
//?    
//?    rU = stt_MTZO_And11__3_1.bool_val.bt7;//#BR PO MTZO
//?    rU <<=1;
//?    rU |= stt_MTZO_Or45__2_1.bool_val.bt7;//
//?    if((rU&3) == 3){
//?        u32_bit_holder |= 1<< IDX_TMR_MTZO_IN_PR            ;
//?        stt_MTZO2_And31__3_1.bool_val.bt7 = 1;
//?    }
//?    
//?        rU = R_ms_po_mtzo2.bool_val.not44_o_0;//#mg
//?    rU <<=1;
//?    rU |= stt_MTZO_And12__6_1.bool_val.bt7;
//?    if((rU&3) == 3)
//?        u32_bit_holder |= 1<< IDX_TMR_MTZO_IN_N_VPERED      ;
//?    
//?        rU = stt_MTZO_Or43__2_1.bool_val.bt7;//#
//?    rU <<=1;
//?    rU |= stt_MTZO_And12__6_1.bool_val.bt7;
//?    if((rU&3) == 3){
//?        u32_bit_holder |= 1<< IDX_TMR_MTZO_IN_N_VPERED_PR   ;
//?        stt_MTZO2_And34__3_1.bool_val.bt7 = 1;
//?    }
//?    
//?    
//?        rU = R_ms_po_mtzo2.bool_val.not42_o_0;//#
//?    rU <<=1;
//?    rU |= stt_MTZO_And13__6_1.bool_val.bt7;
//?    if((rU&3) == 3)
//?        u32_bit_holder |= 1<< IDX_TMR_MTZO_IN_N_NAZAD       ;
//?    
//?        rU = stt_MTZO_Or41__2_1.bool_val.bt7;//#
//?    rU <<=1;
//?    rU |= stt_MTZO_And13__6_1.bool_val.bt7;
//?    if((rU&3) == 3){
//?        u32_bit_holder |= 1<< IDX_TMR_MTZO_IN_N_NAZAD_PR    ;
//?        stt_MTZO2_And36__3_1.bool_val.bt7 = 1;
//?    }
//?    
//?     rU = R_ms_po_mtzo2.bool_val.not40_o_0;//#
//?    rU <<=1;
//?    rU |= stt_MTZO_And14__4_1.bool_val.bt7;
//?    if((rU&3) == 3)
//?        u32_bit_holder |= 1<< IDX_TMR_MTZO_IN_PO_NAPRUZI    ;
//?    
//?        rU = stt_MTZO_Or39__2_1.bool_val.bt7;//#
//?    rU <<=1;
//?    rU |= stt_MTZO_And14__4_1.bool_val.bt7;
//?    if((rU&3) == 3){
//?        u32_bit_holder |= 1<< IDX_TMR_MTZO_IN_PO_NAPRUZI_PR ;
//?        stt_MTZO2_And38__3_1.bool_val.bt7 = 1;
//?    }
    if (stt_MTZO2_And31__4_1.bool_val.bt7 == 1)
        u32_bit_holder |= 1 << IDX_TMR_MTZO_IN;
    if (stt_MTZO2_And32__3_1.bool_val.bt7 == 1)
        u32_bit_holder |= 1 << IDX_TMR_MTZO_IN_PR;
    if (stt_MTZO2_And33__3_1.bool_val.bt7 == 1)
        u32_bit_holder |= 1 << IDX_TMR_MTZO_IN_N_VPERED;
    if (stt_MTZO2_And34__3_1.bool_val.bt7 == 1)
        u32_bit_holder |= 1 << IDX_TMR_MTZO_IN_N_VPERED_PR;
    if (stt_MTZO2_And35__3_1.bool_val.bt7 == 1)
        u32_bit_holder |= 1 << IDX_TMR_MTZO_IN_N_NAZAD;
    if (stt_MTZO2_And36__3_1.bool_val.bt7 == 1)
        u32_bit_holder |= 1 << IDX_TMR_MTZO_IN_N_NAZAD_PR;
    if (stt_MTZO2_And37__3_1.bool_val.bt7 == 1)
        u32_bit_holder |= 1 << IDX_TMR_MTZO_IN_PO_NAPRUZI;
    if (stt_MTZO2_And38__3_1.bool_val.bt7 == 1)
        u32_bit_holder |= 1 << IDX_TMR_MTZO_IN_PO_NAPRUZI_PR;

    _TIMER_T_0(INDEX_TIMER_MTZO2, sLV.p_current_settings_prt->timeout_mtzo_2[number_group_stp], u32_bit_holder, IDX_TMR_MTZO_IN, u32_bit_holder,IDX_TMR_MTZO_OUT );                                                      //1      
    _TIMER_T_0(INDEX_TIMER_MTZO2_PR, sLV.p_current_settings_prt->timeout_mtzo_2_pr[number_group_stp], u32_bit_holder,IDX_TMR_MTZO_IN_PR , u32_bit_holder,IDX_TMR_MTZO_OUT_PR );                                          //2
    _TIMER_T_0(INDEX_TIMER_MTZO2_N_VPERED, sLV.p_current_settings_prt->timeout_mtzo_2_n_vpered[number_group_stp], u32_bit_holder, IDX_TMR_MTZO_IN_N_VPERED, u32_bit_holder,IDX_TMR_MTZO_OUT_N_VPERED );                  //3
    _TIMER_T_0(INDEX_TIMER_MTZO2_N_VPERED_PR, sLV.p_current_settings_prt->timeout_mtzo_2_n_vpered_pr[number_group_stp], u32_bit_holder,IDX_TMR_MTZO_IN_N_VPERED_PR , u32_bit_holder,IDX_TMR_MTZO_OUT_N_VPERED_PR );      //4
    _TIMER_T_0(INDEX_TIMER_MTZO2_N_NAZAD, sLV.p_current_settings_prt->timeout_mtzo_2_n_nazad[number_group_stp], u32_bit_holder,IDX_TMR_MTZO_IN_N_NAZAD , u32_bit_holder,IDX_TMR_MTZO_OUT_N_NAZAD );                      //5
    _TIMER_T_0(INDEX_TIMER_MTZO2_N_NAZAD_PR, sLV.p_current_settings_prt->timeout_mtzo_2_n_nazad_pr[number_group_stp], u32_bit_holder,IDX_TMR_MTZO_IN_N_NAZAD_PR , u32_bit_holder,IDX_TMR_MTZO_OUT_N_NAZAD_PR );          //6
    _TIMER_T_0(INDEX_TIMER_MTZO2_PO_NAPRUZI, sLV.p_current_settings_prt->timeout_mtzo_2_po_napruzi[number_group_stp], u32_bit_holder,IDX_TMR_MTZO_IN_PO_NAPRUZI, u32_bit_holder,IDX_TMR_MTZO_OUT_PO_NAPRUZI );           //7
    _TIMER_T_0(INDEX_TIMER_MTZO2_PO_NAPRUZI_PR, sLV.p_current_settings_prt->timeout_mtzo_2_po_napruzi_pr[number_group_stp], u32_bit_holder,IDX_TMR_MTZO_IN_PO_NAPRUZI_PR , u32_bit_holder,IDX_TMR_MTZO_OUT_PO_NAPRUZI_PR );//8
      
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
	rU = (1<<IDX_TMR_MTZO_OUT               )
                        |(1<<IDX_TMR_MTZO_OUT_DEPENDENT    )
                        |(1<<IDX_TMR_MTZO_OUT_PR           )
                        |(1<<IDX_TMR_MTZO_OUT_N_VPERED     )
                        |(1<<IDX_TMR_MTZO_OUT_N_VPERED_PR  )
                        |(1<<IDX_TMR_MTZO_OUT_N_NAZAD      )
                        |(1<<IDX_TMR_MTZO_OUT_N_NAZAD_PR   )
                        |(1<<IDX_TMR_MTZO_OUT_PO_NAPRUZI   )
                        |(1<<IDX_TMR_MTZO_OUT_PO_NAPRUZI_PR);
     if( (u32_bit_holder&(  rU   )) != 0){
            _SET_BIT(p_active_functions, RNG_BIG_MCZO2);
        }else{
            _CLEAR_BIT(p_active_functions, RNG_BIG_MCZO2);
            }  
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    /*
    Идея по ДЗО и МТЗО. Что делать с командами.
Создай извне контейнеры ₴ для команд ы всего что специфично для каждой защиты загоняй данные туда вначале и в процесе работы программы.
Опиши каждый контейнер и работай через указатель. Эта схема сработает если защиты 1 в 1. Если нет прийдется учитывать тип контейнера и по этой информации делать селект.
    В реалізаціїї Бадзя добав в аналіз зовнішні змінні -- вони будуть замість тригерів
  */  



    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    
    
    
    
}
//
//--------------------------------------------------------------------------------------------------------
