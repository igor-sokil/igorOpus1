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
    glb_ch_id_mtzo = ID_MTZO3;
    mtzo134_handler(p_active_functions,number_group_stp);
    glb_ch_id_mtzo = ID_MTZO4;
    mtzo134_handler(p_active_functions,number_group_stp);
}

U8_state_wrp mtzo1_stp,mtzo2_stp,mtzo3_stp,mtzo4_stp;

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
      unsigned int in_mtzo_rng_big_po_blk_u                :1;//11
      unsigned int in_mtzo_stp_po_blk_u_osn_less_u_porog   :1;//12
      unsigned int in_mtzo_stp_u       :1;//13
      unsigned int in_mtzo_stp_simple  :1;//14
      unsigned int not10_1_b0   :1;//15
      unsigned int not10_1_b7   :1;//16
      unsigned int not8_1_b0    :1;//17
      unsigned int not8_1_b7    :1;//18
      unsigned int not5_1_b7    :1;//19
      unsigned int and6_2_1_b7  :1;//20
      unsigned int or07_2_1_b7  :1;//21
      unsigned int and9_2_1_b7  :1;//22
      unsigned int and11_2_1_b7 :1;//23
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
  
  
  struct{
      unsigned long po_mtzo_smpl_spt,     po_mtzon_vpered_spt,  po_mtzon_nazad_spt,
       po_u_mtzopn_spt,     po_mtzopn_spt;
  __SETTINGS *p_current_settings_prt;
  }sLV;    
    wrp_mtzo.lVl = 0;
    U8_state_wrp stt_MTZO_And01__2_1,
                 stt_MTZO_Or_02__3_1,
                 stt_MTZO_Not03__1_1,  
                 stt_MTZO_And04__2_1,
                 //stt_MTZO_Not05__1_1,
                 stt_MTZO_And06__2_1,
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
     stt_MTZO_And06__2_1.U8V = lV;
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
     
    sLV.p_current_settings_prt = &current_settings ;
    //wrp_mtzo1.bool_vars. = 
    //(sLV.p_current_settings_prt->control_ozt & CTR_OZT_1) ;  
    wrp_mtzo.bool_vars.in_mtzo_on_menu =  
    (sLV.p_current_settings_prt->control_mtzo & CTR_MTZO_1) ;  
    wrp_mtzo.bool_vars.in_mtzo_dir_on_menu = 
    (sLV.p_current_settings_prt->control_mtzo & CTR_MTZO_1_VPERED) ;  
    wrp_mtzo.bool_vars.in_mtzo_inv_on_menu = 
    (sLV.p_current_settings_prt->control_mtzo & CTR_MTZO_1_NAZAD) ;  
    //lV = (sLV.p_current_settings_prt->control_mtzo & CTR_OZT_1) ;  
    //lV = (sLV.p_current_settings_prt->control_mtzo & CTR_OZT_1) ; 
    //Po mtz simple
    if(glb_ch_id_mtzo == ID_MTZO1){
        register U8_mtzo_po_wrp R_mtzo_po;
        R_mtzo_po.U8V = mtzo1_stp.U8V;
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
            R_mtzo_po.bool_val.po_mtz_simple = 1;
        else    
            R_mtzo_po.bool_val.po_mtz_simple = 0;
        //mtzo1_stp.bool_val.po_mtz_simple = R_mtzo_po.bool_val.po_mtz_simple;
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
            R_mtzo_po.bool_val.po_mtz_dir = 1;
        else    
            R_mtzo_po.bool_val.po_mtz_dir = 0;
        //
        rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZON1_NAZAD);
        //if(R_mtzo_po.bool_val.po_mtz_simple == 1 ) {
        if( rU!= 0) {
            sLV.po_mtzon_nazad_spt = sLV.p_current_settings_prt->setpoint_mtzo_1_n_nazad[number_group_stp]
         * KOEF_POVERNENNJA_MTZ_I_UP / 100;
        }else{
           sLV.po_mtzon_nazad_spt = sLV.p_current_settings_prt->setpoint_mtzo_1_n_nazad[number_group_stp]; 
        }
        //
        if(measurement[IM_Imn] >= sLV.po_mtzon_nazad_spt)
            R_mtzo_po.bool_val.po_mtz_inv = 1;
        else    
            R_mtzo_po.bool_val.po_mtz_inv = 0;
        //mtzo1_stp.bool_val. = R_mtzo_po.bool_val.;
        if((sector_directional_mtz[ID_MTZO1][PHASE_MN_INDEX] == MTZ_VPERED)){
            R_mtzo_po.bool_val.po_mtz_sector_dir = 1;
            _SET_BIT(p_active_functions, RNG_BIG_SECTOR_VPERED_MCZON1);
        }else{ 
            R_mtzo_po.bool_val.po_mtz_sector_dir = 0;
            _CLEAR_BIT(p_active_functions, RNG_BIG_SECTOR_VPERED_MCZON1);
        }   
        if(sector_directional_mtz[ID_MTZO1][PHASE_MN_INDEX] == MTZ_NAZAD){
            R_mtzo_po.bool_val.po_mtz_sector_inv = 1;
            _SET_BIT(p_active_functions, RNG_BIG_SECTOR_NAZAD_MCZON1);
        }else{
            R_mtzo_po.bool_val.po_mtz_sector_inv = 0;
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
            R_mtzo_po.bool_val.po_mtz_u_ust_pn = 1;
            _SET_BIT(p_active_functions, RNG_BIG_PO_BLK_U_OSN_LESS_UST_MCZO1);
        }else{
            R_mtzo_po.bool_val.po_mtz_u_ust_pn = 0;
            _CLEAR_BIT(p_active_functions, RNG_BIG_PO_BLK_U_OSN_LESS_UST_MCZO1);
        }
        if(measurement[IM_Imn] >= sLV.po_mtzopn_spt)
            R_mtzo_po.bool_val.po_mtz_pn = 1;
        else    
            R_mtzo_po.bool_val.po_mtz_pn = 0;
        //mtzo3_stp.bool_val.po_mtz_simple = R_mtzo_po.bool_val.po_mtz_simple;
        mtzo1_stp.U8V = R_mtzo_po.U8V;
        
    }
    else if(glb_ch_id_mtzo == ID_MTZO3){
        register U8_mtzo_po_wrp R_mtzo_po;
        R_mtzo_po.U8V = mtzo3_stp.U8V;
        rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZO3);
        //if(R_mtzo_po.bool_val.po_mtz_simple == 1 ) {
        if( rU!= 0 ) {
            sLV.po_mtzo_smpl_spt = sLV.p_current_settings_prt->setpoint_mtzo_3[number_group_stp]
         * KOEF_POVERNENNJA_MTZ_I_UP / 100;
        }else{
           sLV.po_mtzo_smpl_spt = sLV.p_current_settings_prt->setpoint_mtzo_3[number_group_stp]; 
        }
        
        if(measurement[IM_Imn] >= sLV.po_mtzo_smpl_spt)
            R_mtzo_po.bool_val.po_mtz_simple = 1;
        else    
            R_mtzo_po.bool_val.po_mtz_simple = 0;
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
            R_mtzo_po.bool_val.po_mtz_dir = 1;
        else    
            R_mtzo_po.bool_val.po_mtz_dir = 0;
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
            R_mtzo_po.bool_val.po_mtz_inv = 1;
        else    
            R_mtzo_po.bool_val.po_mtz_inv = 0;
        //mtzo1_stp.bool_val. = R_mtzo_po.bool_val.;
        if((sector_directional_mtz[ID_MTZO3][PHASE_MN_INDEX] == MTZ_VPERED)){
            R_mtzo_po.bool_val.po_mtz_sector_dir = 1;
            _SET_BIT(p_active_functions, RNG_BIG_SECTOR_VPERED_MCZON3);
        }else{ 
            R_mtzo_po.bool_val.po_mtz_sector_dir = 0;
            _CLEAR_BIT(p_active_functions, RNG_BIG_SECTOR_VPERED_MCZON3);
        }   
        if(sector_directional_mtz[ID_MTZO3][PHASE_MN_INDEX] == MTZ_NAZAD){
            R_mtzo_po.bool_val.po_mtz_sector_inv = 1;
            _SET_BIT(p_active_functions, RNG_BIG_SECTOR_NAZAD_MCZON3);
        }else{
            R_mtzo_po.bool_val.po_mtz_sector_inv = 0;
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
            R_mtzo_po.bool_val.po_mtz_u_ust_pn = 1;
            _SET_BIT(p_active_functions, RNG_BIG_PO_BLK_U_OSN_LESS_UST_MCZO3);
        }else{
            R_mtzo_po.bool_val.po_mtz_u_ust_pn = 0;
            _CLEAR_BIT(p_active_functions, RNG_BIG_PO_BLK_U_OSN_LESS_UST_MCZO3);
        }
        if(measurement[IM_Imn] >= sLV.po_mtzopn_spt)
            R_mtzo_po.bool_val.po_mtz_pn = 1;
        else    
            R_mtzo_po.bool_val.po_mtz_pn = 0;
        mtzo3_stp.U8V = R_mtzo_po.U8V;
    
    }
    else if(glb_ch_id_mtzo == ID_MTZO4){
        register U8_mtzo_po_wrp R_mtzo_po;
        R_mtzo_po.U8V = mtzo4_stp.U8V;
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
            R_mtzo_po.bool_val.po_mtz_simple = 1;
        else    
            R_mtzo_po.bool_val.po_mtz_simple = 0;
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
            R_mtzo_po.bool_val.po_mtz_dir = 1;
        else    
            R_mtzo_po.bool_val.po_mtz_dir = 0;
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
            R_mtzo_po.bool_val.po_mtz_inv = 1;
        else    
            R_mtzo_po.bool_val.po_mtz_inv = 0;
        //mtzo1_stp.bool_val. = R_mtzo_po.bool_val.;
        if((sector_directional_mtz[ID_MTZO4][PHASE_MN_INDEX] == MTZ_VPERED)){
            R_mtzo_po.bool_val.po_mtz_sector_dir = 1;
            _SET_BIT(p_active_functions, RNG_BIG_SECTOR_VPERED_MCZON4);
        }else{ 
            R_mtzo_po.bool_val.po_mtz_sector_dir = 0;
            _CLEAR_BIT(p_active_functions, RNG_BIG_SECTOR_VPERED_MCZON4);
        }   
        if(sector_directional_mtz[ID_MTZO4][PHASE_MN_INDEX] == MTZ_NAZAD){
            R_mtzo_po.bool_val.po_mtz_sector_inv = 1;
            _SET_BIT(p_active_functions, RNG_BIG_SECTOR_NAZAD_MCZON4);
        }else{
            R_mtzo_po.bool_val.po_mtz_sector_inv = 0;
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
            R_mtzo_po.bool_val.po_mtz_u_ust_pn = 1;
            _SET_BIT(p_active_functions, RNG_BIG_PO_BLK_U_OSN_LESS_UST_MCZO4);
        }else{
            R_mtzo_po.bool_val.po_mtz_u_ust_pn = 0;
            _CLEAR_BIT(p_active_functions, RNG_BIG_PO_BLK_U_OSN_LESS_UST_MCZO4);
        }
        if(measurement[IM_Imn] >= sLV.po_mtzopn_spt)
            R_mtzo_po.bool_val.po_mtz_pn = 1;
        else    
            R_mtzo_po.bool_val.po_mtz_pn = 0;
        mtzo4_stp.U8V = R_mtzo_po.U8V;
    
    }
    
    //RNG_BIG_PO_BLK_U_OSN_LESS_0_05UN_MCZO,
     //ДВ
    //lV = _CHECK_SET_BIT(p_active_functions, );  
    
    if(glb_ch_id_mtzo == ID_MTZO1){
        wrp_mtzo.bool_vars.in_mtzo_rng_big_block = 
         _CHECK_SET_BIT(p_active_functions, RNG_BIG_BLOCK_MCZO1);
        
        if (sLV.p_current_settings_prt->control_mtzo & CTR_MTZO_NESPR_KIL_NAPR) 
            stt_MTZO_And01__2_1.bool_val.bt0 = 1;
        //stt_MTZO_And01__2_1.bool_val.bt0 = lV;
        lV = _CHECK_SET_BIT(p_active_functions, RNG_BIG_NKNO);
        stt_MTZO_And01__2_1.bool_val.bt1 = lV;
    //eval
        if ((stt_MTZO_And01__2_1.U8V &3) == 3){
        _SET_BIT(p_active_functions, RNG_BIG_NCN_MCZO);
        stt_MTZO_And01__2_1.bool_val.bt7 = 1;
        }else{
        _CLEAR_BIT(p_active_functions, RNG_BIG_NCN_MCZO);
        }
    }
    if(glb_ch_id_mtzo == ID_MTZO1){
        stt_MTZO_Or_02__3_1.bool_val.bt0 =
        _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZON1_VPERED);
        stt_MTZO_Or_02__3_1.bool_val.bt1 = 
        _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZON1_NAZAD);
        stt_MTZO_Or_02__3_1.bool_val.bt2 = 
        _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZOPN1);
        
        
        
        if((stt_MTZO_Or_02__3_1.U8V &7) != 0)
        stt_MTZO_Not03__1_1.bool_val.bt0 = 1;
        //else  stt_MTZO_Not03__1_1.bool_val.bt0 = 0;
        stt_MTZO_Not03__1_1.bool_val.bt7 = !stt_MTZO_Not03__1_1.bool_val.bt0;
        
        stt_MTZO_And04__2_1.bool_val.bt0 = stt_MTZO_And01__2_1.bool_val.bt7;
        stt_MTZO_And04__2_1.bool_val.bt1 = stt_MTZO_Not03__1_1.bool_val.bt7;
    
        if ((stt_MTZO_And04__2_1.U8V &3) == 3){
        _SET_BIT(p_active_functions, RNG_BIG_NCN_MCZO1);
        stt_MTZO_And04__2_1.bool_val.bt7 = 1;
        
        }else{
        _CLEAR_BIT(p_active_functions, RNG_BIG_NCN_MCZO1);
        
        }
    }
    else if(glb_ch_id_mtzo == ID_MTZO3){
        stt_MTZO_Or_02__3_1.bool_val.bt0 =
        _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZON3_VPERED);
        stt_MTZO_Or_02__3_1.bool_val.bt1 = 
        _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZON3_NAZAD);
        stt_MTZO_Or_02__3_1.bool_val.bt2 = 
        _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZOPN3);
        
        
        
        if((stt_MTZO_Or_02__3_1.U8V &7) != 0)
        stt_MTZO_Not03__1_1.bool_val.bt0 = 1;
        //else  stt_MTZO_Not03__1_1.bool_val.bt0 = 0;
        stt_MTZO_Not03__1_1.bool_val.bt7 = !stt_MTZO_Not03__1_1.bool_val.bt0;
        
        stt_MTZO_And04__2_1.bool_val.bt0 = stt_MTZO_And01__2_1.bool_val.bt7;
        lV = _CHECK_SET_BIT(p_active_functions, RNG_BIG_NCN_MCZO);
        stt_MTZO_And04__2_1.bool_val.bt1 = lV;//stt_MTZO_Not03__1_1.bool_val.bt7;
    
        if ((stt_MTZO_And04__2_1.U8V &3) == 3){
        _SET_BIT(p_active_functions, RNG_BIG_NCN_MCZO3);
        stt_MTZO_And04__2_1.bool_val.bt7 = 1;
        
        }else{
        _CLEAR_BIT(p_active_functions, RNG_BIG_NCN_MCZO3);
        
        }
        
    }
    else if(glb_ch_id_mtzo == ID_MTZO4){
        stt_MTZO_Or_02__3_1.bool_val.bt0 =
        _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZON4_VPERED);
        stt_MTZO_Or_02__3_1.bool_val.bt1 = 
        _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZON4_NAZAD);
        stt_MTZO_Or_02__3_1.bool_val.bt2 = 
        _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZOPN4);
        
        
        
        if((stt_MTZO_Or_02__3_1.U8V &7) != 0)
        stt_MTZO_Not03__1_1.bool_val.bt0 = 1;
        //else  stt_MTZO_Not03__1_1.bool_val.bt0 = 0;
        stt_MTZO_Not03__1_1.bool_val.bt7 = !stt_MTZO_Not03__1_1.bool_val.bt0;
        lV = _CHECK_SET_BIT(p_active_functions, RNG_BIG_NCN_MCZO);
        stt_MTZO_And04__2_1.bool_val.bt0 = lV;//stt_MTZO_And01__2_1.bool_val.bt7;
        stt_MTZO_And04__2_1.bool_val.bt1 = stt_MTZO_Not03__1_1.bool_val.bt7;
    
        if ((stt_MTZO_And04__2_1.U8V &3) == 3){
        _SET_BIT(p_active_functions, RNG_BIG_NCN_MCZO4);
        stt_MTZO_And04__2_1.bool_val.bt7 = 1;
        
        }else{
        _CLEAR_BIT(p_active_functions, RNG_BIG_NCN_MCZO4);
        
        }
    }
    
    rU = wrp_mtzo.bool_vars.in_mtzo_rng_big_block;
    //stt_MTZO_Not05__1_1.bool_val.bt0 = rU;
    //wrp_mtzo1.bool_vars.in_mtzo_rng_big_block;
    wrp_mtzo.bool_vars.not5_1_b7 = (~rU)&1;
    //stt_MTZO_Not05__1_1.bool_val.bt7 = (~rU)&1;
    
    stt_MTZO_And06__2_1.bool_val.bt0 = wrp_mtzo.bool_vars.in_mtzo_on_menu;
    stt_MTZO_And06__2_1.bool_val.bt1 = wrp_mtzo.bool_vars.not5_1_b7;//stt_MTZO_Not05__1_1.bool_val.bt7;
    if ((stt_MTZO_And06__2_1.U8V &3) == 3){
        stt_MTZO_And06__2_1.bool_val.bt7 = 1;
        wrp_mtzo.bool_vars.and6_2_1_b7 = 1;
    }
    stt_MTZO_Or_07__2_1.bool_val.bt0 = 
    wrp_mtzo.bool_vars.in_mtzo_rng_big_po_blk_u;
    stt_MTZO_Or_07__2_1.bool_val.bt1 = stt_MTZO_And04__2_1.bool_val.bt7;
    if((stt_MTZO_Or_07__2_1.U8V &3) != 0){
       //stt_MTZO_Not10__1_1.bool_val.bt0 = 1;
        stt_MTZO_Or_07__2_1.bool_val.bt7 = 0;//bool_val.bt7 = 1;
        wrp_mtzo.bool_vars.or07_2_1_b7 = 0;
    }
    else{
        stt_MTZO_Or_07__2_1.bool_val.bt7 = 1;//Inverse state now
        wrp_mtzo.bool_vars.or07_2_1_b7 = 1;
    }
    rU = stt_MTZO_And04__2_1.bool_val.bt7;
    wrp_mtzo.bool_vars.not8_1_b0 = rU;//stt_MTZO_Not08__1_1.bool_val.bt0 = rU;
    lV = (~rU)&1;
    wrp_mtzo.bool_vars.not8_1_b7 = lV;//stt_MTZO_Not08__1_1.bool_val.bt7 = lV;
    
    stt_MTZO_And09__2_1.bool_val.bt0 = wrp_mtzo.bool_vars.in_mtzo_stp_u;
    stt_MTZO_And09__2_1.bool_val.bt1 = lV;
    if((stt_MTZO_And09__2_1.U8V &3) == 3){
        stt_MTZO_And09__2_1.bool_val.bt7 = 1;
        wrp_mtzo.bool_vars.and9_2_1_b7 = 1;
    }
    
    rU = stt_MTZO_Or_07__2_1.bool_val.bt7;
    wrp_mtzo.bool_vars.not10_1_b0 = rU;//stt_MTZO_Not10__1_1.bool_val.bt0 = rU;
    lV = (~rU)&1;
    wrp_mtzo.bool_vars.not10_1_b7 = lV;//stt_MTZO_Not10__1_1.bool_val.bt7 = lV;
    
    stt_MTZO_And11__2_1.bool_val.bt0 = 
    wrp_mtzo.bool_vars.in_mtzo_dir_selector;
    stt_MTZO_And11__2_1.bool_val.bt1 =  lV;//stt_MTZO_Not10__1_1.bool_val.bt7;
    lV = 0;
    if((stt_MTZO_And11__2_1.U8V &3) == 3)
        lV = 1;
    stt_MTZO_And11__2_1.bool_val.bt7 =  lV;
    wrp_mtzo.bool_vars.and11_2_1_b7 =   lV;
    
    stt_MTZO_Or_12__4_1.bool_val.bt0 =  lV;
    stt_MTZO_Or_12__4_1.bool_val.bt1 = 
     _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZO1);
    stt_MTZO_Or_12__4_1.bool_val.bt2 = 
    wrp_mtzo.bool_vars.in_mtzo_normal_selector;
    stt_MTZO_Or_12__4_1.bool_val.bt3 = stt_MTZO_And04__2_1.bool_val.bt7;
    if((stt_MTZO_Or_12__4_1.U8V &15) != 0){
        stt_MTZO_Or_12__4_1.bool_val.bt7 = lV = 1;
        //
    }
    //
    //
    //
    stt_MTZO_And13__3_1.bool_val.bt0 = lV;
    stt_MTZO_And13__3_1.bool_val.bt1 = wrp_mtzo.bool_vars.in_mtzo_stp_simple;
    stt_MTZO_And13__3_1.bool_val.bt2 = stt_MTZO_And06__2_1.bool_val.bt7; 
    if((stt_MTZO_And13__3_1.U8V &7) == 7){
        
        stt_MTZO_And13__3_1.bool_val.bt7 = 1;
    } 
     // 
     // 
     // 
     // 
        
     do { 
        register U8_state_wrp R_wrp; 
        R_wrp.U8V = 0;
        rU = 0;lV = 0;
        R_wrp.bool_val.bt0 = wrp_mtzo.bool_vars.in_mtzo_dir_selector;
        R_wrp.bool_val.bt1 = stt_MTZO_And06__2_1.bool_val.bt7;
        R_wrp.bool_val.bt2 = wrp_mtzo.bool_vars.in_mtzo_dir_on_menu;
        R_wrp.bool_val.bt3 = wrp_mtzo.bool_vars.in_mtzo_sector_dir;
        R_wrp.bool_val.bt4 = wrp_mtzo.bool_vars.in_mtzo_stp_dir;
        R_wrp.bool_val.bt5 = stt_MTZO_Or_07__2_1.bool_val.bt7;
        if ((R_wrp.U8V &63) == 63) { 
            
            R_wrp.bool_val.bt7 = 1;
        } 
     
        //stt_MTZO_And14__6_1.bool_val.bt0 = wrp_mtzo.bool_vars.in_mtzo_dir_selector;
        //stt_MTZO_And14__6_1.bool_val.bt1 = stt_MTZO_And06__2_1.bool_val.bt7;
        //stt_MTZO_And14__6_1.bool_val.bt2 = wrp_mtzo.bool_vars.in_mtzo_dir_on_menu;
        //stt_MTZO_And14__6_1.bool_val.bt3 = wrp_mtzo.bool_vars.in_mtzo_sector_dir;
        //stt_MTZO_And14__6_1.bool_val.bt4 = wrp_mtzo.bool_vars.in_mtzo_stp_dir;
        //stt_MTZO_And14__6_1.bool_val.bt5 = stt_MTZO_Or_07__2_1.bool_val.bt7;
        //if((stt_MTZO_And14__6_1.U8V &63) == 63){
        //    
        //    stt_MTZO_And14__6_1.bool_val.bt7 = 1;
        // } 
        rU = R_wrp.bool_val.bt7;//R_wrp.U8V;
       } while (lV != 0);
         
    
    
     stt_MTZO_And14__6_1.bool_val.bt7 = rU;//R_wrp.U8V;
     U8_state_wrp R_And15__6_1;
     R_And15__6_1.U8V =  rU =0;
     R_And15__6_1.bool_val.bt0 = wrp_mtzo.bool_vars.in_mtzo_dir_selector;
     R_And15__6_1.bool_val.bt1 = stt_MTZO_And06__2_1.bool_val.bt7;
     R_And15__6_1.bool_val.bt2 = wrp_mtzo.bool_vars.in_mtzo_sector_inv;
     R_And15__6_1.bool_val.bt3 = wrp_mtzo.bool_vars.in_mtzo_inv_on_menu;
     R_And15__6_1.bool_val.bt4 = stt_MTZO_Or_07__2_1.bool_val.bt7;
     R_And15__6_1.bool_val.bt5 = wrp_mtzo.bool_vars.in_mtzo_stp_inv;
    if((R_And15__6_1.U8V &63) == 63){
        
        R_And15__6_1.bool_val.bt7 = 1;
    }
    rU = R_And15__6_1.bool_val.bt7;
    //stt_MTZO_And15__6_1.bool_val.bt0 = wrp_mtzo.bool_vars.in_mtzo_dir_selector;
    //stt_MTZO_And15__6_1.bool_val.bt1 = stt_MTZO_And06__2_1.bool_val.bt7;
    //stt_MTZO_And15__6_1.bool_val.bt2 = wrp_mtzo.bool_vars.in_mtzo_sector_inv;
    //stt_MTZO_And15__6_1.bool_val.bt3 = wrp_mtzo.bool_vars.in_mtzo_inv_on_menu;
    //stt_MTZO_And15__6_1.bool_val.bt4 = stt_MTZO_Or_07__2_1.bool_val.bt7;
    //stt_MTZO_And15__6_1.bool_val.bt5 = wrp_mtzo.bool_vars.in_mtzo_stp_inv;
    //if((stt_MTZO_And15__6_1.U8V &63) == 63){
    //   
    //    stt_MTZO_And15__6_1.bool_val.bt7 = 1;
    //  
    // 
    // 
    //stt_MTZO_And15__6_1.U8V = rU;//R_And15__6_1.U8V;
    stt_MTZO_And15__6_1.bool_val.bt7 = rU;//
    
     U8_state_wrp R_And16__4_1;
    R_And16__4_1.U8V = 0;
    R_And16__4_1.bool_val.bt0 = wrp_mtzo.bool_vars.in_mtzo_stp_u_selector;
    R_And16__4_1.bool_val.bt1 = stt_MTZO_And06__2_1.bool_val.bt7;
    R_And16__4_1.bool_val.bt2 = stt_MTZO_And09__2_1.bool_val.bt7;
    R_And16__4_1.bool_val.bt3 = wrp_mtzo.bool_vars.in_mtzo_stp_u;
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
        
        if(stt_MTZO_And15__6_1.bool_val.bt7 != 1){
             _SET_BIT(p_active_functions, RNG_BIG_PO_MCZON1_NAZAD);
            u32_bit_holder |= 1<< IDX_TMR_MTZO_IN_N_NAZAD;
        }
        else
            _CLEAR_BIT(p_active_functions, RNG_BIG_PO_MCZON1_NAZAD);
        if(stt_MTZO_And16__4_1.bool_val.bt7 != 1){
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
        
        if(stt_MTZO_And15__6_1.bool_val.bt7 != 1){
             _SET_BIT(p_active_functions, RNG_BIG_PO_MCZON3_NAZAD);
            u32_bit_holder |= 1<< IDX_TMR_MTZO_IN_N_NAZAD;
        }
        else
            _CLEAR_BIT(p_active_functions, RNG_BIG_PO_MCZON3_NAZAD);
        if(stt_MTZO_And16__4_1.bool_val.bt7 != 1){
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
        
        if(stt_MTZO_And15__6_1.bool_val.bt7 != 1){
             _SET_BIT(p_active_functions, RNG_BIG_PO_MCZON4_NAZAD);
            u32_bit_holder |= 1<< IDX_TMR_MTZO_IN_N_NAZAD;
        }
        else
            _CLEAR_BIT(p_active_functions, RNG_BIG_PO_MCZON4_NAZAD);
        if(stt_MTZO_And16__4_1.bool_val.bt7 != 1){
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
  

  

   
    

    
    //lV = _CHECK_SET_BIT(p_active_functions, RNG_BIG_NCN_MCZO1,);  
    //lV = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_BLK_U_OSN_LESS_UST_MCZO1);  
    
    
    
    
}
//
//--------------------------------------------------------------------------------------------------------
static unsigned long u32_bit_mtzo2_ext = 0;    
void mtzo2_handler(unsigned int *p_active_functions, unsigned int number_group_stp );
//=====================================================================================================
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//                  
//....................................................................................................
//=====================================================================================================
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
    stt_MTZO_And14__4_1; 
    sLV.p_current_settings_prt = &current_settings ;
    rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZON2_VPERED);
    R_m_dv_po_mtzo2.bool_val.cmd_mtzo2_dir = rU;
    rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZON2_NAZAD);
    R_m_dv_po_mtzo2.bool_val.cmd_mtzo2_inv = rU;
    rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZOPN2);
    R_m_dv_po_mtzo2.bool_val.cmd_mtzo2_stp_u = rU;
    rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_NCN_MCZO);
    R_m_dv_po_mtzo2.bool_val.cmd_nkn_mtzo = rU;
    
    rU = sLV.p_current_settings_prt->type_mtzo2;
    if (rU == (TYPE_MTZ_DIRECTIONAL)){
        R_m_dv_po_mtzo2.bool_val.m_select_mtzo2_dir = 1;
    }
    else if(rU == (TYPE_MTZ_VOLTAGE)){
        R_m_dv_po_mtzo2.bool_val.m_select_mtzo2_stp_u = 1;
    }
    else if(rU == (TYPE_MTZ_SIMPLE)){
        R_m_dv_po_mtzo2.bool_val.m_select_mtzo2_simple = 1;
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
    R_m_dv_po_mtzo2.bool_val.m_mtzo2 = rU;
    rU = (sLV.p_current_settings_prt->control_mtzo & CTR_MTZO_2_VPERED) ;   
    R_m_dv_po_mtzo2.bool_val.m_mtzo2_dir = rU;
    rU = (sLV.p_current_settings_prt->control_mtzo & CTR_MTZO_2_NAZAD) ;
    R_m_dv_po_mtzo2.bool_val.m_mtzo2_inv = rU;
    rU = (sLV.p_current_settings_prt->control_mtzo & CTR_MTZO_2_PRYSKORENA) ;
    R_m_dv_po_mtzo2.bool_val.m_mtzo2_usk  = rU;
    rU = (sLV.p_current_settings_prt->control_mtzo & CTR_MTZO_2_PRYSKORENNJA) ;
    R_m_dv_po_mtzo2.bool_val.m_uskor_mtzo2 = rU;
    rU = _CHECK_SET_BIT(p_active_functions,RNG_BIG_BLOCK_MCZO2 );
    R_m_dv_po_mtzo2.bool_val.dv_block_mtzo2 = rU;
    rU = _CHECK_SET_BIT(p_active_functions,RNG_BIG_BLOCK_PR_MCZO2 );
    R_m_dv_po_mtzo2.bool_val.dv_block_usk_mtzo2 = rU;
    
    
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    if((sector_directional_mtz[ID_MTZO2][PHASE_MN_INDEX] == MTZ_VPERED)){
        //R_mtzo_po.bool_val.po_mtz_sector_dir = 1;
        stt_MTZO_And12__6_1.bool_val.bt3 = 1;
        _SET_BIT(p_active_functions, RNG_BIG_SECTOR_VPERED_MCZON2);
    }else{ 
        //R_mtzo_po.bool_val.po_mtz_sector_dir = 0;
        _CLEAR_BIT(p_active_functions, RNG_BIG_SECTOR_VPERED_MCZON2);
    }   
    if(sector_directional_mtz[ID_MTZO1][PHASE_MN_INDEX] == MTZ_NAZAD){
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
       //or1
    rU = R_m_dv_po_mtzo2.U32V &( (1<<22)|(1<<23)|(1<<24));
    if( rU!= 0) 
        R_ms_po_mtzo2.bool_val.or01_o_0 = rU = 1;
    
    R_ms_po_mtzo2.bool_val.not02_o_0 = (~rU)&1;
    rU <<=1;
    rU |= R_m_dv_po_mtzo2.bool_val.cmd_nkn_mtzo;
    if((rU&3) == 3)
        R_ms_po_mtzo2.bool_val.and03_o_0 = 1;
    
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    rU = R_m_dv_po_mtzo2.bool_val.dv_block_mtzo2;
    R_m_dv_po_mtzo2.bool_val.not04_o_0 = (~rU)&1;
    rU = R_m_dv_po_mtzo2.U32V &( (1<<0)|(1<<13));
    if(rU == (1<<0)|(1<<13))
        R_m_dv_po_mtzo2.bool_val.and06_o_0 = 1;
    
    rU = R_ms_po_mtzo2.bool_val.and03_o_0;
    R_ms_po_mtzo2.bool_val.not05_o_0 = (~rU)&1;
    rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_BLK_U_OSN_LESS_0_05UN_MCZO);
    rU <<=1;
    rU |=  R_ms_po_mtzo2.bool_val.and03_o_0;
    if(rU == 0)
        R_m_dv_po_mtzo2.bool_val.orN07_o_0 = 1; 
    //po_mtzo2_u not05_o_0
    rU = R_m_dv_po_mtzo2.bool_val.po_mtzo2_u;
    rU <<=1;
    rU |=  R_ms_po_mtzo2.bool_val.not05_o_0;
    if(rU&3 == 3){
        //R_ms_po_mtzo2.bool_val.and08_o_0 = 1;
        stt_MTZO_And14__4_1.bool_val.bt2 = 1;
    }
    
    rU = R_m_dv_po_mtzo2.bool_val.orN07_o_0;
    //R_ms_po_mtzo2.bool_val.not09_o_0 = (~rU)&1;
    rU =  (~rU)&1;
    rU <<=1;
    rU |=  R_m_dv_po_mtzo2.bool_val.m_select_mtzo2_dir;
    if(rU&3 == 3)
        R_ms_po_mtzo2.bool_val.and10_o_0 = 1;
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    //or15
    rU = R_ms_po_mtzo2.U32V &(unsigned long)( (1<<27)|(1<<28)|(1<<29)|(1<<30)|(1<<31));
    if(rU != 0){
        R_m_dv_po_mtzo2.bool_val.or15_o_0 = 1;
        
    }
    //or16
    U8_state_wrp R_wrp;
    R_wrp.U8V = 0;
    R_wrp.bool_val.bt0 = R_ms_po_mtzo2.bool_val.and10_o_0;
    rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_MCZO2);
    R_wrp.bool_val.bt1 = rU;
    R_wrp.bool_val.bt2 = R_m_dv_po_mtzo2.bool_val.m_select_mtzo2_simple;
    R_wrp.bool_val.bt3 = R_m_dv_po_mtzo2.bool_val.or15_o_0;
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
    stt_MTZO_And12__6_1.bool_val.bt2 = rU = R_m_dv_po_mtzo2.bool_val.m_mtzo2_dir;
    //stt_MTZO_And12__6_1..bt3 = must be setup were SECTOR_VPERED_MCZON2 sets
    //stt_MTZO_And12__6_1.bt4 = must be setup were (measurement[IM_Imn] >= sLV.po_mtzon_vpered_spt
    rU = R_m_dv_po_mtzo2.bool_val.orN07_o_0;
    stt_MTZO_And12__6_1.bool_val.bt5 = rU;
    stt_MTZO_And12__6_1.bool_val.bt5 = rU;
    stt_MTZO_And14__4_1.bool_val.bt1 = rU;
    if( (stt_MTZO_And12__6_1.U8V &63) == 63){
        stt_MTZO_And12__6_1.bool_val.bt7 = 1;
        _SET_BIT(p_active_functions,RNG_BIG_PO_MCZON2_VPERED );
    }else{
        _CLEAR_BIT(p_active_functions,RNG_BIG_PO_MCZON2_VPERED);
    }
    
    //and13
    stt_MTZO_And13__6_1.bool_val.bt5 = rU;
    //bt2 = must be setup were RNG_BIG_SECTOR_NAZAD_MCZON2
    stt_MTZO_And13__6_1.bool_val.bt3 = rU = R_m_dv_po_mtzo2.bool_val.m_mtzo2_inv;
    //bt4 = must be setup were measurement[IM_Imn] >= sLV.po_mtzon_nazad_spt
    
    if( (stt_MTZO_And13__6_1.U8V &63) == 63){
        stt_MTZO_And13__6_1.bool_val.bt7 = 1;
        _SET_BIT(p_active_functions, RNG_BIG_PO_MCZON2_NAZAD);
    }else{
        _CLEAR_BIT(p_active_functions,RNG_BIG_PO_MCZON2_NAZAD);
    }
    
    //and14
    stt_MTZO_And14__4_1.bool_val.bt0 = R_m_dv_po_mtzo2.bool_val.m_select_mtzo2_stp_u;
    stt_MTZO_And14__4_1.bool_val.bt2 = R_ms_po_mtzo2.bool_val.and08_o_0;
    //.bt3 = must be setup were measurement[IM_Imn] >= sLV.po_mtzopn_spt)
    if( (stt_MTZO_And14__4_1.U8V &63) == 63){
        stt_MTZO_And14__4_1.bool_val.bt7 = 1;
        _SET_BIT(p_active_functions,RNG_BIG_PO_MCZOPN2 );
    }else{
        _CLEAR_BIT(p_active_functions,RNG_BIG_PO_MCZOPN2);
    }
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    //rU = R_m_dv_po_mtzo2.bool_val
    unsigned long u32_bit_holder = 0;
    rU = R_m_dv_po_mtzo2.bool_val.dv_block_usk_mtzo2;
    R_m_dv_po_mtzo2.bool_val.not17_o_0 = (~rU)&1;
    rU = _CHECK_SET_BIT(p_active_functions, RNG_BIG_STATE_VVO);
    rU <<=1;
    rU |= R_m_dv_po_mtzo2.bool_val.m_uskor_mtzo2;
    if((rU&3) == 3){
        R_m_dv_po_mtzo2.bool_val.and19_o_0 = 1;
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
    if(rU == (1<<16)|(1<<17)){
        R_m_dv_po_mtzo2.bool_val.and20_o_0 = 1;
        R_ms_po_mtzo2.bool_val.and20_copy = 1;
        //not21_o_0 = 0;
    }
    else
        R_ms_po_mtzo2.bool_val.not21_o_0 = 1;
    
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
/*    _TIMER_T_0_LOCK(INDEX_TIMER_MTZ2_DEPENDENT, timeout_dependent_general(i_max, current_settings_prt.setpoint_mtz_2[number_group_stp],
    current_settings_prt.timeout_mtz_2[number_group_stp], current_settings_prt.type_mtz2), tmp, 5, p_global_trigger_state_mtz2, 0);
    _TIMER_T_0(INDEX_TIMER_MTZ2_PR, current_settings_prt.timeout_mtz_2_pr[number_group_stp], tmp, 6, tmp, 15);                      //1
    _TIMER_T_0(INDEX_TIMER_MTZ2, current_settings_prt.timeout_mtz_2[number_group_stp], tmp, 7, tmp, 16);                            //2
    _TIMER_T_0(INDEX_TIMER_MTZ2_N_VPERED, current_settings_prt.timeout_mtz_2_n_vpered[number_group_stp], tmp, 8, tmp, 17);          //3
    _TIMER_T_0(INDEX_TIMER_MTZ2_N_VPERED_PR, current_settings_prt.timeout_mtz_2_n_vpered_pr[number_group_stp], tmp, 9, tmp, 18);    //4
    _TIMER_T_0(INDEX_TIMER_MTZ2_N_NAZAD, current_settings_prt.timeout_mtz_2_n_nazad[number_group_stp], tmp, 10, tmp, 19);           //5
    _TIMER_T_0(INDEX_TIMER_MTZ2_N_NAZAD_PR, current_settings_prt.timeout_mtz_2_n_nazad_pr[number_group_stp], tmp, 11, tmp, 20);     //6
    _TIMER_T_0(INDEX_TIMER_MTZ2_PO_NAPRUZI, current_settings_prt.timeout_mtz_2_po_napruzi[number_group_stp], tmp, 12, tmp, 21);     //7
    _TIMER_T_0(INDEX_TIMER_MTZ2_PO_NAPRUZI_PR, current_settings_prt.timeout_mtz_2_po_napruzi_pr[number_group_stp], tmp, 13, tmp, 22);//8
      
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    
    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    
    Идея по ДЗО и МТЗО. Что делать с командами.
Создай извне контейнеры ₴ для команд ы всего что специфично для каждой защиты загоняй данные туда вначале и в процесе работы программы.
Опиши каждый контейнер и работай через указатель. Эта схема сработает если защиты 1 в 1. Если нет прийдется учитывать тип контейнера и по этой информации делать селект.
    
  */  



    //...........................................................................
    //```````````````````````````````````````````````````````````````````````````
    
    
    
    
}
//
//--------------------------------------------------------------------------------------------------------
