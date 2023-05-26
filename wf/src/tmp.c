ДЗО 1 

Постійне прискорення ДЗО 2
Прискорення ДЗО 2 при ввімкн. ВВ
Блк ДЗО 2 від Iосн 3Г:
АМСЗ ДЗО 2. :
ДЗО 2 :
ДЗО 2 : Ввімкн прям
ДЗО 2 : Ввімкн звор

Постійне прискорення ДЗО 3
Прискорення ДЗО 3 при ввімкн. ВВ
Блк ДЗО 3 від Iосн 3Г:
АМСЗ ДЗО 3. :
ДЗО 3 :
ДЗО 3 : Ввімкн прям
ДЗО 3: Ввімкн звор

ДЗО 4 : Ввімкн
ДЗО 4 : Ввімкн прям
ДЗО 4 : Ввімкн звор
АМСЗ ДЗО 4 : 
Блк ДЗО 4 від Iосн 3Г:
Ввімкн; Вимкн

Неспр. Напр. ДЗР
ввімкн
Блк ДЗР 1 від IРЕЗ 3Г:
Ввімкн; Вимкн
Блк ДЗР 1 від IРЕЗ:
Ввімкн; Вимкн
АМСЗ ДЗР 1 : 
Ввімкн
ДЗР 1 : Ввімк

Постійне 
прискорення ДЗР 2
Прискорення ДЗР 2 
при ввімкн. ВВР
Блк ДЗР 2 від IРЕЗ 3Г:
Ввімкн; Вимкн
АМСЗ ДЗР 2. : 
Ввімкн
ДЗР 2 : Ввімкн
ДЗР 2 : Ввімкн прям
ДЗР 2 : Ввімкн звор

Постійне 
прискорення ДЗР 3
Прискорення ДЗР 3 при ввімкн. ВВР
Блк ДЗР 3 від IРЕЗ 3Г:
Ввімкн; Вимк
АМСЗ ДЗР 3 : 
Ввімкн
ДЗР 3 : Ввімкн
ДЗР 3 : Ввімкн прям
ДЗР 3 : Ввімкн звор
mtzo,mtzr,dzo,dzr,umin,umax,achrchapv, zdz,urov,apv,up,MASKA_EL_SIGNALS_0,MASKA_INFO_SIGNALES_0
MASKA_TRIGGER_SIGNALES_0
	_CMD_00 = ((		 ==  0)<< 		),
	_CMD_01 = ((		 ==  1)<< 		),
	_CMD_02 = ((		 ==  2)<< 		),
	_CMD_03 = ((		 ==  3)<< 		),
	_CMD_04 = ((		 ==  4)<< 		),
	_CMD_05 = ((		 ==  5)<< 		),
	_CMD_06 = ((		 ==  6)<< 		),
	_CMD_07 = ((		 ==  7)<< 		),
	_CMD_08 = ((		 ==  8)<< 		),
	_CMD_09 = ((		 ==  9)<< 		),
	_CMD_10 = ((		 == 10)<< 		),
	_CMD_11 = ((		 == 11)<< 		),
	_CMD_12 = ((		 == 12)<< 		),

EKRAN_CHOOSE_SETTINGS_SWITCHER_H
_CMD_00 = (( ==  0)<< ),
_CMD_01 = (( ==  1)<< ),
_CMD_02 = (( ==  2)<< ),
_CMD_03 = (( ==  3)<< ),
_CMD_04 = (( ==  4)<< ),
_CMD_05 = (( ==  5)<< ),
_CMD_06 = (( ==  6)<< ),
_CMD_07 = (( ==  7)<< ),
_CMD_08 = (( ==  8)<< ),
_CMD_09 = (( ==  9)<< ),
_CMD_10 = (( == 10)<< ),
_CMD_11 = (( == 11)<< ),

_CMD_00 = ((_IDX_U32 ==  0)<< _U32_MSK), _CMD_00 = ((  ==  0)<<  ),
_CMD_01 = ((_IDX_U32 ==  1)<< _U32_MSK), _CMD_01 = ((  ==  1)<<  ),
_CMD_02 = ((_IDX_U32 ==  2)<< _U32_MSK), _CMD_02 = ((  ==  2)<<  ),
_CMD_03 = ((_IDX_U32 ==  3)<< _U32_MSK), _CMD_03 = ((  ==  3)<<  ),
_CMD_04 = ((_IDX_U32 ==  4)<< _U32_MSK), _CMD_04 = ((  ==  4)<<  ),
_CMD_05 = ((_IDX_U32 ==  5)<< _U32_MSK), _CMD_05 = ((  ==  5)<<  ),
_CMD_06 = ((_IDX_U32 ==  6)<< _U32_MSK), _CMD_06 = ((  ==  6)<<  ),
_CMD_07 = ((_IDX_U32 ==  7)<< _U32_MSK), _CMD_07 = ((  ==  7)<<  ),
_CMD_08 = ((_IDX_U32 ==  8)<< _U32_MSK), _CMD_08 = ((  ==  8)<<  ),
_CMD_09 = ((_IDX_U32 ==  9)<< _U32_MSK), _CMD_09 = ((  ==  9)<<  ),
_CMD_10 = ((_IDX_U32 == 10)<< _U32_MSK), _CMD_10 = ((  == 10)<<  ),
_CMD_11 = ((_IDX_U32 == 11)<< _U32_MSK), _CMD_11 = ((  == 11)<<  ),


          APV_CMD_00 = ZVN_NESPR_DZO_CMD_00|  
          APV_CMD_01 =                            
          APV_CMD_02 =          
          APV_CMD_03 =                                    
          APV_CMD_04 =                                                  
          APV_CMD_05 =                                                    
          APV_CMD_06 =                                                          
          APV_CMD_07 =  
          APV_CMD_08 =  
          APV_CMD_09 =  
          APV_CMD_10 =  
          APV_CMD_11 =  

             




    rU = (sLV.p_current_settings_prt->control_dzo & (1<<INDEX_CTR_DZO4_AMTZ)); 
    R_m_dv_po_dzo4.bool_val.m_dzo4_amtz = rU;


(~rU)&1;





                         //Eval FCHE
            rU = m_s_phs_stp_state.lVl;
            if(rU&(1<<0)){//One
                //Select Max
                lV = 0;//Za_A;
                if(rU&(1<<5))
                    lV = 1;//Za_B;
                else if(rU&(1<<6))
                    lV = 2;//Za_C;
                //Check Sector
                lV = sector_directional_dz[DZ4_STAGE_BIT][lV];
            }else if(rU&(1<<1)){ //2
                     register long rCtr = 0;lV = 0;     
                    do{
                        if(rCtr == 0){
                            if(rU&(1<<(IA_M0_P9+7)))
                                lV = sector_directional_dz[DZ4_STAGE_BIT][0];
                        }
                        if(rCtr == 1){
                            if(rU&(1<<(IB_M0_P9+7)))
                                lV = sector_directional_dz[DZ4_STAGE_BIT][1];
                        }
                        if(rCtr == 2){
                            if(rU&(1<<(IC_M0_P9+7)))
                                lV = sector_directional_dz[DZ4_STAGE_BIT][2];
                        }
                    }while( (lV <= 0)&& rCtr++ < 2  );

            }else{//M
                //Check Sector  
                register long  rCtr = 0;lV = 0;     
                do{
                    if(rCtr == 0){
                        if(rU&(1<<(IA_M0_P9+7)))
                            lV = sector_directional_dz[DZ4_STAGE_BIT][0];
                    }
                    if(rCtr == 1){
                        if(rU&(1<<(IB_M0_P9+7)))
                            lV = sector_directional_dz[DZ4_STAGE_BIT][1];
                    }
                    if(rCtr == 2){
                        if(rU&(1<<(IC_M0_P9+7)))
                            lV = sector_directional_dz[DZ4_STAGE_BIT][2];
                    }
                }while( (lV <= 0)&& rCtr++ < 2  );
            }
            _CLEAR_BIT(p_active_functions, RANG_SECTOR_DIR_DZ4);
            _CLEAR_BIT(p_active_functions, RANG_SECTOR_INV_DZ4);
            if(lV == 1){
                _SET_BIT(p_active_functions, RANG_SECTOR_DIR_DZ4);
                sLV.p_p1->bool_vars.or12__i_1 = 1;
            }else if(lV == 2){
                _SET_BIT(p_active_functions, RANG_SECTOR_INV_DZ4);
                 sLV.p_p1->bool_vars.or13__i_0 = 1;
            }
            //else if(lV == (-1)){
            //  ;
            //}
            if( (sLV.p_p1->lVl&((1<<22)|(1<<21))) > 0 )
                p2.bool_vars.and22_i_3 = 1;
            if( (sLV.p_p1->lVl&((1<<23)|(1<<24))) > 0 )
                p2.bool_vars.and24_i_3 = 1;
              
            if(_CHECK_SET_BIT(p_active_functions, RANG_BLOCK_DZ4) != 0){
                lV = 1;
                p2.bool_vars.nor19_i_0 = lV;
                p2.bool_vars.nor20_i_0 = lV;
                p2.bool_vars.nor21_i_0 = lV;
            }
            
            if(_CHECK_SET_BIT(p_active_functions, RANG_PO_I_BLK_DZ) != 0){
                lV = 1;
                p2.bool_vars.nor19_i_1 = lV;
                p2.bool_vars.nor20_i_1 = lV;
                p2.bool_vars.nor21_i_1 = lV;
            }   
            lV = (sLV.p_current_settings_prt->control_dz);
            rU = (MASKA_FOR_BIT(INDEX_CTR_DZ4_AMTZ)); rU &= lV;
            //not15
            if(rU == 0){
                sLV.p_p1->bool_vars.not15_o_0 = 1;
                sLV.p_p4->bool_vars.and14_i_1 = 0;//lVl |= (1<<23);//and14_i_1 :1;//23
                sLV.p_p4->bool_vars.and11_i_0 = 1;//and11
                p2.bool_vars.and26_i_5 = 0;//and26
            }else{
                sLV.p_p1->bool_vars.not15_o_0 = 0;//?
                sLV.p_p4->bool_vars.and14_i_1 = 1;
                sLV.p_p4->bool_vars.and11_i_0 = 0;
                p2.bool_vars.and26_i_5 = 1;
            }
            
            //lV = (sLV.p_current_settings_prt->control_dz);
            rU =(MASKA_FOR_BIT(INDEX_CTR_DZ4)); rU &= lV;
            if(rU != 0){
                rU = 1;
                p2.bool_vars.and22_i_0 = rU;
                p2.bool_vars.and24_i_0 = rU;
                p2.bool_vars.and26_i_0 = rU;
            }   
            //lV = (sLV.p_current_settings_prt->control_dz);
            rU = (MASKA_FOR_BIT(INDEX_CTR_DZ4_DIR));
            rU &= lV;
            if(rU != 0)
                p2.bool_vars.and22_i_1 = 1;
            //lV = (sLV.p_current_settings_prt->control_dz)
            rU =(MASKA_FOR_BIT(INDEX_CTR_DZ4_INV));rU &= lV;
            if(rU != 0)
                p2.bool_vars.and24_i_1 = 1;

                
            if(_CHECK_SET_BIT(p_active_functions, RANG_PO_AMTZ_DZ4) != 0){
                lV = 1;
                p2.bool_vars.nor19_i_3 = lV;
                p2.bool_vars.nor20_i_3 = lV;
                p2.bool_vars.or18__i_1 = lV;
            }   

            if(_CHECK_SET_BIT(p_active_functions, RANG_PO_DIR_DZ4) == 0){
                p2.bool_vars.not23_o_0 = 1;
                p2.bool_vars.and26_i_1 = 1;
            }
            if(_CHECK_SET_BIT(p_active_functions, RANG_PO_INV_DZ4) == 0){
                p2.bool_vars.not25_o_0 = 1;
                p2.bool_vars.and26_i_2 = 1;
            }   
//          sLV.p_p4->bool_vars.and14_i_0 = 0;  
//          if(_CHECK_SET_BIT(p_active_functions, RANG_SNKN_DZ) != 0)
//              sLV.p_p4->bool_vars.and14_i_0 = 1;
            lV = _CHECK_SET_BIT(p_active_functions, RANG_SNKN_DZ);
            if (lV){//-!
                sLV.p_p4->lVl |= (1<<22)|(1<<21);//and11_i_1 and14_i_0
            }
            //Eval Stp    
            rU = p2.bool_vars.not23_o_0;
            long pick_up_Resistance_dstLp4 = 0;
            if(rU == 0)
                pick_up_Resistance_dstLp4 = (long)sLV.p_current_settings_prt->pickup_dz4_dir[number_group_stp] * KOEF_POVERNENNJA_GENERAL_DOWN  / 100;
            else
                pick_up_Resistance_dstLp4 = (long)sLV.p_current_settings_prt->pickup_dz4_dir[number_group_stp];

            lV = m_s_phs_stp_state.lVl;
            if(lV&(1<<0)){//One
                if((sLV.p_p4->lVl&((1<<20)|(1<<21))) == ((1<<20)|(1<<21))){//Check Fault and11
                    rU = Za_A;
                    if(lV&(1<<5))
                        rU = Za_B;
                    else if(lV&(1<<6))
                            rU = Za_C;
                    
                }
                else{
                    rU = Z_A;
                    if(lV&(1<<5))
                        rU = Z_B;
                    else if(lV&(1<<6))
                            rU = Z_C;       
                }
                //current_settings_prt.pickup_dz1
            }else if(lV&(1<<1)){ //2
    
                if((sLV.p_p4->lVl&((1<<20)|(1<<21))) == ((1<<20)|(1<<21))){//Check Fault and11
                    rU = Za_AB;//( (1<< IA_M0_P9) | (1<<IB_M0_P9) | (1<<IC_L0_P9 ))
                    if( (lV&((1<<(IB_M0_P9+7)) | (1<<(IC_M0_P9+7)) | (1<<(IA_L0_P9+7))))== ((1<<(IB_M0_P9+7)) | (1<<(IC_M0_P9+7)) | (1<<(IA_L0_P9+7))))
                        rU = Za_BC;
                    else if( (lV&((1<<(IA_M0_P9+7)) | (1<<(IC_M0_P9+7)) | (1<<(IB_L0_P9+7))))== ((1<<(IA_M0_P9+7)) | (1<<(IC_M0_P9+7)) | (1<<(IB_L0_P9+7))))
                            rU = Za_CA; 
                }
                else{
                    rU = Z_AB;
                    if( (lV&((1<<(IB_M0_P9+7)) | (1<<(IC_M0_P9+7)) | (1<<(IA_L0_P9+7))))== ((1<<(IB_M0_P9+7)) | (1<<(IC_M0_P9+7)) | (1<<(IA_L0_P9+7))) )
                        rU = Z_BC;
                    else if( (lV&((1<<(IA_M0_P9+7)) | (1<<(IC_M0_P9+7)) | (1<<(IB_L0_P9+7))))== ((1<<(IA_M0_P9+7)) | (1<<(IC_M0_P9+7)) | (1<<(IB_L0_P9+7))))
                            rU = Z_CA;  
                }
            }
            else{//M
                if((sLV.p_p4->lVl&((1<<20)|(1<<21))) == ((1<<20)|(1<<21))){//Check Fault
                    rU = Za_3;//lV&(1<<2) Select Avar
                }
                else{
                    rU = Z_3;
                }
            }
            lV = resistance[rU];    
            if(  (lV > 0) && (lV < pick_up_Resistance_dstLp4)  )
                p2.bool_vars.and22_i_2 = 1;
            else
                p2.bool_vars.and22_i_2 = 0;
                
            lV = p2.bool_vars.not25_o_0;
            //long pick_up_Resistance_dstLp2 = 0;
            if(lV == 0)
                pick_up_Resistance_dstLp4 = (long)sLV.p_current_settings_prt->pickup_dz4_inv[number_group_stp] * KOEF_POVERNENNJA_GENERAL_DOWN  / 100;
            else
                pick_up_Resistance_dstLp4 = (long)sLV.p_current_settings_prt->pickup_dz4_inv[number_group_stp];   
            lV = resistance[rU];
            if(  (lV > 0) && (lV < pick_up_Resistance_dstLp4)  )
                p2.bool_vars.and24_i_2 = 1;
            else
                p2.bool_vars.and24_i_2 = 0;
            
            //and14
            //sLV.p_p4->lVl |= (1<<22);//and14_i_0 :1;//22
            //sLV.p_p4->lVl |= (1<<23);//and14_i_1 :1;//23  
            rU = (sLV.p_p4->lVl)&((1<<22)|(1<<23)); //and14
            if(rU == ((1<<22)|(1<<23))){
                //sLV.p_p1->bool_vars.and4_o_0 = 1;
                //and16
                sLV.p_p1->bool_vars.and16_i_0 = 1;
                //and17
                sLV.p_p1->bool_vars.and17_i_0 = 1;
                //or18
                sLV.p_p1->bool_vars.nor18__i_0 = 1;
            }
            sLV.p_p1->bool_vars.and16_i_1 = p2.bool_vars.not23_o_0;  
            sLV.p_p1->bool_vars.and17_i_1 = p2.bool_vars.not25_o_0;
            lV = sLV.p_p1->lVl;
            lV &= ((1<<28)|(1<<29));
            if(lV == ((1<<28)|(1<<29)))//and16 
                p2.bool_vars.nor19_i_3 = 1;

            lV = sLV.p_p1->lVl;
            lV &= ((1<<20)|(1<<19));
            if(lV == ((1<<20)|(1<<19)))//and17 
                p2.bool_vars.nor20_i_3 = 1;
                
            if( (sLV.p_p1->lVl&((1<<25)|(1<<26))) != 0 ){//or18
                p2.bool_vars.nor21_i_2 = 0;
            }
            else{
                p2.bool_vars.nor21_i_2 = 1;
            }
            sLV.p2 = p2;
            //PO Calc
            lV = p2.bool_vars.nor20_i_3;//STP_I_A_MCP_DST_LP_STAGE2_BIT
            unsigned long pick_up_I_Amcp_dstLp4 = 0;
            if(lV){
                pick_up_I_Amcp_dstLp4 = sLV.p_current_settings_prt->pickup_dz4_amtz[number_group_stp] * KOEF_POVERNENNJA_MTZ_I_UP  / 100;
                }
            else{   
                pick_up_I_Amcp_dstLp4 = sLV.p_current_settings_prt->pickup_dz4_amtz[number_group_stp];
            }
            if( (measurement[IM_IA] > pick_up_I_Amcp_dstLp4)
                || (measurement[IM_IB] > pick_up_I_Amcp_dstLp4)
                || (measurement[IM_IC] > pick_up_I_Amcp_dstLp4)
            )
                p2.bool_vars.and26_i_4 = 1;//rU = 1;
            else
                p2.bool_vars.and26_i_4 = 0;//rU = 0;
            //nor19 
            if( (p2.lVl&((1<<15)|(1<<16)|(1<<17)|(1<<18)) ) != 0 ){//
                p2.bool_vars.and22_i_4 = 0;
            }
            else{
                p2.bool_vars.and22_i_4 = 1;
            }
            //nor20 
            if( (p2.lVl&((1<<19)|(1<<20)|(1<<21)|(1<<22)) ) != 0 ){//
                p2.bool_vars.and24_i_4 = 0;
            }
            else{
                p2.bool_vars.and24_i_4 = 1;
            }
            //nor21 
            if( (p2.lVl&((1<<23)|(1<<24)|(1<<25)) ) != 0 ){//
                p2.bool_vars.and26_i_3 = 0;
            }
            else{
                p2.bool_vars.and26_i_3 = 1;
            }
            //lV = sLV.p_p1->lVl;
            lV = p2.lVl&((1<<9)|(1<<10)|(1<<11)|(1<<12)|(1<<13)|(1<<14));
            if(lV == ((1<<9)|(1<<10)|(1<<11)|(1<<12)|(1<<13)|(1<<14))){//and26 9 10 11 12 13 14
                _SET_BIT(p_active_functions, RANG_PO_AMTZ_DZ4);
                u32_bit_holder |= 1<<STP_I_AMCP_DST_LP_STAGE_BIT;
            }   
            else
                _CLEAR_BIT(p_active_functions, RANG_PO_AMTZ_DZ4);
            
            rU = p2.lVl&((1<<4)|(1<<5)|(1<<6)|(1<<7)|(1<<8));
            if(rU == ((1<<4)|(1<<5)|(1<<6)|(1<<7)|(1<<8))){//and24 4 5 6 7 8
                _SET_BIT(p_active_functions, RANG_PO_INV_DZ4);
                u32_bit_holder |= 1<<STP_INV_DST_LP_STAGE_BIT;
            }   
            else
                _CLEAR_BIT(p_active_functions, RANG_PO_INV_DZ4);
            
            rU = p2.lVl&((1<<0)|(1<<30)|(1<<1)|(1<<2)|(1<<3));
            if(rU == ((1<<0)|(1<<30)|(1<<1)|(1<<2)|(1<<3))){//and22 0 1 2 3
                _SET_BIT(p_active_functions, RANG_PO_DIR_DZ4);
                u32_bit_holder |= 1<<STP_DIR_DST_LP_STAGE_BIT;
            }
            else
                _CLEAR_BIT(p_active_functions, RANG_PO_DIR_DZ4);

    
                ; 
  
            ;				
//=====================================================================================================
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//  Modules which I plan use in my std_periph Lib                
//....................................................................................................
//=====================================================================================================
//DMA
//DMA2D
//FSMC
//GPIO
//PWR
//RCC
//TIM
//USART?
//SPI?
//I2C?
//MISK?
//--------------------------------------------------------------------------------------------------------
//````````````````````````````````````````````````````````````````````````````````````````````````````````
Закономерный вопрос: где взять обозначения нужных регистров и битов? Ответ: в 3-ех документах (на примере 746).

1. Reference manual STM32F7.pdf
2. STM32F745xx.pdf
3. stm32f746xx.h

Этих 3 файлов полностью хватает для того, чтобы правильно обращаться ко всем регистрам микроконтроллера 

    

			
//=====================================================================================================
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//                  
//....................................................................................................
//=====================================================================================================
void p_3U0_handler(unsigned int *p_active_functions, unsigned int number_group_stp){
// ----------------    -------------------------
  UNUSED(p_active_functions);
  UNUSED(number_group_stp);
	
}
//
//--------------------------------------------------------------------------------------------------------
//````````````````````````````````````````````````````````````````````````````````````````````````````````
 ch_type_voltage = (current_settings_prt.control_transformator >> INDEX_ML_CTR_TRANSFORMATOR_VH_VL) & 0x1; 
if(ch_type_voltage){//0-VH 1 - VL 

 if(current_settings_prt.control_mtz &(arL_ctrl_mcp_sel[mtz_level])){

struct{
long Ii,Ip;

}sLV;  
_Bool ctrl_ready_tu = ((current_settings_prt.control_extra_settings_1 & CTR_EXTRA_SETTINGS_1_CTRL_READY_TU) == 0);
			lV = 1<<(STP_I_A_MCP_DST_LP_STAGE2_BIT+sLV.ch_stage_selector);
unsigned long pick_up_I_Amcp_dstLp2 = 0;			
			if(bw_dstLp_dt.ulStpDzfield &
            

register union { 
   struct {
    //  unsigned int previous_state_po_dfrp1 : 1;
      unsigned int state_po_dfrp1 : 1;
      unsigned int dfrp1_is_larger_than_dI:1;
   } bool_vars;
  long lVl;
}wrp;

//register unsigned long u32_bit_holder = 0;  
//register union { 
//   struct {
//      unsigned int previous_state_po_3U0_1 : 1;
//	  unsigned int KZZV_1r_is_larger_than_3U0_1:1;
//   } bool_vars;
//  long lVl;
//}wrp;wrp.lVl = 0;
struct{
unsigned long I1_lead_ls, I1_lead_hs, I2_lead_ls, I2_lead_hs;
unsigned long  meas_I1_lead_ls, meas_I1_lead_hs, meas_I2_lead_ls, meas_I2_lead_hs;
unsigned long setpoint_ls,setpoint_hs;
long lgI_hysteresis;
long conter_and;
__SETTINGS *p_current_settings_prt;
}sLV; 
   long lV; 
   unsigned long lCmpVl;
   Mcp_stp_state *p_bl;
 sLV.conter_and = 0;sLV.lgI_hysteresis = 0;
  sLV.p_current_settings_prt = &current_settings_prt;
     //ДВ
  lV = _CHECK_SET_BIT(p_active_functions, RANG_BLOCK_KZ_ZV);
  register long lAnd = 0;
  if(lV == 0)
    lAnd |= 1;
   lV = (sLV.p_current_settings_prt->control_kz_zv & (1<<INDEX_ML_CTR_KZ_ZV_STATE)) ;
  if(lV != 0)
  lAnd |= 2;
  if(lAnd == 3){
    sLV.conter_and++;
    }
	lCmpVl = MIN_LIMIT_I1_I2_P;
//					else{
//						//p3.bool_vars.or27_i_0 = rU;//Must be already setup
//						p3.bool_vars.or29_i_0 = lV;
//						lV = p3.bool_vars.and32_o_0;//Loop link
//						rU = p3.bool_vars.and31_o_0;//Loop link
//						p3.bool_vars.or29_i_1 = lV;
//						p3.bool_vars.or27_i_1 = rU;
//						p3.bool_vars.not30_o_0 = !lV;
//						p3.bool_vars.not28_o_0 = !rU;
//						p3.bool_vars.and31_i_1 = !lV;
//						p3.bool_vars.and32_i_1 = !rU;
//						if( (p3.lVl&((1<<0)|(1<<1))) != 0 )//or27 customer
//							p3.bool_vars.and31_i_0 = 1; 
//						else //-if(p3.lVl&((1<<0)|(1<<1))) == 0)
//							p3.bool_vars.and31_i_0 = 0; 
//                
//						 if( (p3.lVl&((1<<2)|(1<<3))) != 0 )//or29 customer
//							p3.bool_vars.and32_i_2 = 1;
//						else //-if( (p3.lVl&((1<<2)|(1<<3))) == 0 )
//							p3.bool_vars.and32_i_2 = 0;
//							
//						rU = p1.lVl&((1<<5)|(1<<6)|(1<<7));
//						if(rU == ((1<<5)|(1<<6)|(1<<7))){	
//							p3.bool_vars.and31_o_0 = 1;
//							u32_bit_holder |= 1<<T_ACC_AMCP_IN_BIT;
//						}else{
//							p3.bool_vars.and31_o_0 = 1;
//				
//						}						
//						rU = p1.lVl&((1<<8)|(1<<9)|(1<<10));
//						if(rU == ((1<<8)|(1<<9)|(1<<10)))}	
//							p3.bool_vars.and32_o_0 = 1;
//							u32_bit_holder |= 1<<T_AMCP_IN_BIT;
//							}
//						else{
//							p3.bool_vars.and32_o_0 = 0;
//						}
//						 _TIMER_T_0(INDEX_TIMER_DZ2_AMTZ,  sLV.p_current_settings_prt->timeout_dz2_amtz[number_group_stp],
//						u32_bit_holder, T_AMCP_IN_BIT, u32_bit_holder, T_AMCP_OUT_BIT);
//						_TIMER_T_0(INDEX_TIMER_DZ2_AMTZ_PR,  sLV.p_current_settings_prt->timeout_dz2_amtz_pr[number_group_stp],
//						u32_bit_holder, T_ACC_AMCP_IN_BIT, u32_bit_holder, T_ACC_AMCP_OUT_BIT);
//					}    
		
//    if (i1_bilshe_porogu == 0) setpoint_i1 = MIN_LIMIT_FOR_I1_AND_I2*KOEF_POVERNENNJA_ZOP_BLK/100;
//    else setpoint_i1 = MIN_LIMIT_FOR_I1_AND_I2;
//    unsigned int i1_bilshe_porogu_tmp = i1_bilshe_porogu = (i1_current >= setpoint_i1);
//    
//    if (i2_bilshe_porogu == 0) setpoint_i2 = MIN_LIMIT_FOR_I1_AND_I2*KOEF_POVERNENNJA_ZOP_BLK/100;
//    else setpoint_i2 = MIN_LIMIT_FOR_I1_AND_I2;
//    unsigned int i2_bilshe_porogu_tmp = i2_bilshe_porogu = (i2_current >= setpoint_i2);	
   sLV.meas_I1_lead_ls = measurement[IM_I1_P_L ];
   sLV.meas_I1_lead_hs = measurement[IM_I1_P_H ];
   sLV.meas_I2_lead_ls = measurement[IM_I2_P_L ];
   sLV.meas_I2_lead_hs = measurement[IM_I2_P_H ];
	p_bl = &mcp_stp_state;
	lV = p_bl->bool_val.po_I1_lead_low_side;
	if(lV) 
		sLV.I1_lead_ls = lCmpVl*KOEF_POVERNENNJA_ZOP_BLK/100;
	else 
		sLV.I1_lead_ls = lCmpVl;
	if(sLV.meas_I1_lead_ls >= sLV.I1_lead_ls)
		lV = 1;	
	else 
		lV = 0;
	p_bl->bool_val.po_I1_lead_low_side = lV;
	
	lV = p_bl->bool_val.po_I1_lead_high_side ;
	if (lV)
		sLV.I1_lead_hs = lCmpVl*KOEF_POVERNENNJA_ZOP_BLK/100;
	else 
		sLV.I1_lead_hs = lCmpVl;
	if(sLV.meas_I1_lead_hs >= sLV.I1_lead_hs)
		lV = 1;	
	else 
		lV = 0;	
	p_bl->bool_val.po_I1_lead_high_side = lV;
	
	lV = p_bl->bool_val.po_I2_lead_low_side;	
	if(lV) 
		sLV.I2_lead_ls = lCmpVl*KOEF_POVERNENNJA_ZOP_BLK/100;
	else 
		sLV.I2_lead_ls = lCmpVl;
	if(sLV.meas_I2_lead_ls >= sLV.I2_lead_ls)
		lV = 1;	
	else 
		lV = 0;	
	p_bl->bool_val.po_I2_lead_low_side = lV;	
	
	lV = p_bl->bool_val.po_I2_lead_high_side;	
	if ( lV)
		sLV.I2_lead_hs = lCmpVl*KOEF_POVERNENNJA_ZOP_BLK/100;
	else 
		sLV.I2_lead_hs = lCmpVl;
	if(sLV.meas_I2_lead_hs >= sLV.I2_lead_hs)
		lV = 1;	
	else 
		lV = 0;	
	p_bl->bool_val.po_I2_lead_high_side = lV;
	lV = p_bl->lVl;
	lV &= 0xf;
	if(lV == 0xf){
		lV =  p_bl->bool_val.po_I2_I1_ls_lead;
		if(lV){
			lV = sLV.p_current_settings_prt->pickup_kz_zv[number_group_stp];
			lV *= KOEF_POVERNENNJA_GENERAL_UP/100;
			sLV.setpoint_ls = lV;
			
		}
		else{
			sLV.setpoint_ls = sLV.p_current_settings_prt->pickup_kz_zv[number_group_stp];
			
		}
		lV =  p_bl->bool_val.po_I2_I1_hs_lead;
		if(lV){
			lV = sLV.p_current_settings_prt->pickup_kz_zv[number_group_stp];
			lV *= KOEF_POVERNENNJA_GENERAL_UP/100;
			sLV.setpoint_hs = lV;
			
		}
		else{
			sLV.setpoint_hs = sLV.p_current_settings_prt->pickup_kz_zv[number_group_stp];
			
		}
		//((i2_current*1000) >= (i1_current*setpoint)) 
		if(	(sLV.meas_I2_lead_ls*1000) >= (sLV.meas_I1_lead_ls*sLV.setpoint_ls) ){
			lV =  p_bl->bool_val.po_I2_I1_ls_lead;
			if(lV == 0)
				p_bl->bool_val.po_I2_I1_ls_lead = 1;
		}
		else{
			lV =  p_bl->bool_val.po_I2_I1_ls_lead;
			if(lV != 0)
				p_bl->bool_val.po_I2_I1_ls_lead = 0;
			
		}
		if(	(sLV.meas_I2_lead_hs*1000) >= (sLV.meas_I1_lead_hs*sLV.setpoint_hs) ){
			lV =  p_bl->bool_val.po_I2_I1_hs_lead;
			if(lV == 0)
				p_bl->bool_val.po_I2_I1_hs_lead = 1;
		}
		else{
			lV =  p_bl->bool_val.po_I2_I1_hs_lead;
			if(lV != 0)
				p_bl->bool_val.po_I2_I1_hs_lead = 0;
			
		}
		//---------------------------------------------
		//Phase sensetive element
		//0- Not
		//1-Internal
		//2-External
		//---------------------------------------------
		lV = sLV.lgI_hysteresis;//Temporarly emulate Phase Calculation
		if( lV == 2 ){
			//Put Cmd  Sector In\Ext
			lV = p_bl->lVl;
			lV &= 0x30;
			if(lV == 0x30)
			sLV.conter_and += 2;
		}else if( lV == 1 ){
			//Put Cmd  Sector In\Ext
			lV = p_bl->lVl;
			lV &= 0x30;
			if(lV == 0x30)
			sLV.conter_and += 1;
		}
		else{
			//Clear Cmd Sector In\Ext
		}
	}
	else{
		;//Clr Kz
	}
	if(sLV.conter_and == 5){
	
	}else if(sLV.conter_and == 4){
	
	}
	else{//Clr State

	}

Надо придумать макросы трансляторы, к-е заполняют 
1)битовые поля
2)логика or, and,not
3)

Зробити розбивку кожного захисту на блоки
Зробити шаблони по яким можна швидко кодувати кожен блок 

Блок мусить мати 
1)перелік бітових полів які є вхідними
2)Перелік бітових полів які є вихідними
3)Перелік полів, що працюють з дискретними входами
4)Перелік полів, що працюють з дискретними виходами
5)Перелік полів, що працюють з таймерами.

Чим і як можна закодовати вхідні/вихідні біти
enum LU_X_BIT_POS { 

LU_X_AA_CMD_BIT  = 1,  
LU_X_BB_CMD_BIT  = 1,  

TOTAL_LU_X_BITS
//
};
typedef union LU_X_stp_state_Unn{ 
   struct {
      unsigned int po_I1_lead_low_side  : 1; //1
      unsigned int po_I1_lead_high_side : 1; //2
      unsigned int po_I2_lead_low_side  : 1; //3
      unsigned int po_I2_lead_high_side : 1; //4
      unsigned int po_I2_I1_ls_lead     : 1; //5
      unsigned int po_I2_I1_hs_lead     : 1; //6
//      unsigned int po_ : 1; //7
//      unsigned int po_ : 1; //8
//      unsigned int po_ : 1; //9
    } bool_val;
    long lVl;
} LU_X_stp_state; 
LU_X_stp_state lu_stp_state ;

enum LU_Y_BIT_POS { 

LU_X_AA_BIT  = 0,  
LU_Y_BB_CMD_BIT  = 1,  

TOTAL_LU_Y_BITS
//
};
const unsigned short WITH_LU = TOTAL_LU_Y_BITS;
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
U8_state_wrp_YY [WITH_LU] ;
//Bit selection
index_bit_x = LU_Y_BB_CMD_BIT>>3;
mask_bit_x  = (LU_Y_BB_CMD_BIT-( (LU_Y_BB_CMD_BIT>>3) << 3)));
unsigned long ulV = U8_state_wrp_YY[index_bit_x]&(1<<mask_bit_x);

Робота AND, OR,XOR,
Всі елементи 8-емні.
далі описую блоки AND2_1,AND3_1,AND4_1,AND5_1,AND6_1,
 
далі описую блоки OR2_1,OR3_1,OR4_1,OR5_1,OR6_1,

AND2_1
enum AND2_1_BIT_POS { 

AND2_0_BIT  = 0,  
AND2_1_BIT     ,  
//AND2_2_BIT     ,  
//AND2_3_BIT     ,  
//AND2_4_BIT     ,  
//AND2_5_BIT     ,  
//AND2_6_BIT     ,  
AND2_7_BIT  = 7,  
TOTAL_AND2_1_BITS
//
};
U8_state_wrp stt_AND2_1;
//Init Part 
unsigned long ulV1 = U8_state_wrp_YY[index_bit_x1]&(1<<mask_bit_x1);
unsigned long ulV2 = U8_state_wrp_YY[index_bit_x2]&(1<<mask_bit_x2);
stt_AND2_1.bool_val.bt0 = ulV1;
stt_AND2_1.bool_val.bt1 = ulV2;
stt_AND2_1.bt7 = 0;
U8_state_wrp_YY[index_bit_x3] &= ~(1<<mask_bit_x3);
if((stt_AND2_1.U8V &3) = 3){
stt_AND2_1.bool_val.bt7 = 1;

}
U8_state_wrp_YY[index_bit_x3]&(1<<mask_bit_x3) = stt_AND2_1.bool_val.bt7;

Інший варіант роботи по AND

unsigned char stt_and2_1_xx  = 0;
long lV = U8_state_wrp_YY[index_bit_x1].U8V &(1<<mask_bit_x1);
lV >>= mask_bit_x1;//Convert to bool
and2_1_xx += lV;
     lV = U8_state_wrp_YY[index_bit_x2].U8V &(1<<mask_bit_x2);
lV >>= mask_bit_x2;//Convert to bool
and2_1_xx += lV;
//Clear Out 
	U8_state_wrp_YY[index_bit_x3] &= ~(1<<mask_bit_x3);
if(and2_1_xx == 2)
U8_state_wrp_YY[index_bit_x3] |= (1<<mask_bit_x3);
Щоб не заплутатись і оперативно редагувати для
кожної схеми 
1)Опиши кожен елемент 
2)Входи цього елемента
3)Виходи цього елемента
Так складеться повний перелік сигналів
Потім заповнюй бітові поля
Рухаючись в порядку обходу схеми

Реєстрація в Diaro
For AdnVsDr8954
Adrian Vlas
Vid25mab1@online.ua
8954 psw for protection bsfa3p6l52v


Introduction to Application Development with Qt Quick, Release 1.0
page 34
https://doc.qt.io/Qt-5/windows-deployment.html
https://books.google.com.ua/books?id=6F0dDAAAQBAJ&pg=PP9&lpg=PP9&dq=qt+book+pdf&source=bl&ots=ZRtEVMgxk6&sig=OweF-OleTdI3z7yINTcm1vkRWqI&hl=uk&sa=X&ved=2ahUKEwiPloeah47fAhUBDSwKHfugADc4HhDoATAAegQICRAB#v=onepage&q=qt%20book%20pdf&f=false
https://books.google.com.ua/books?id=9uhODwAAQBAJ&pg=PP4&lpg=PP4&dq=qt+book+pdf&source=bl&ots=A5CG0w3Uan&sig=aYI4oXkbewPD5G2ohH2_DqTIxqo&hl=uk&sa=X&ved=2ahUKEwiPloeah47fAhUBDSwKHfugADc4HhDoATABegQICBAB#v=onepage&q=qt%20book%20pdf&f=false
https://github.com/zakariakov/booksorg
http://pllug.org.ua/pllug-roadmaps/
Qt Training: Model/View (part 2/4): Showing Simple Data: Oliver Gutbrod, by e-GITS
Qt Training: Fundamentals of Qt - Objects in Qt, part 1/3 - Qt objects, UI elements
Qt Training: Model/View II (part 1/5): Editing item data, by e-GITS
Qt Training: Application Creation (part 1/3): MainWindows: Justin Noel by ICS
Qt Training: Widgets (part 1/3): Common Widgets: Torsten Rahn by basysKom
Qt Training: Graphics View (part 1/3): Using GraphicsView Classes: Tuukka Ahoniemi
Qt DevDays 2011, Advanced Qt - A Deep Dive 5/6 - ModelView Part 1: Volker Krause, Jesper Pedersen
Qt DevDays 2011, Advanced Qt -A Deep Dive 1/6 Graphics View Part 1: Volker Krause, Jesper Pedersen
QtWS15- Get to know the Qt Installer Framework, Kai Köhne, The Qt Company
QtDD12 - Effective QML: Best practices for Developing with Qt Quick - Adenilson Calvacanti
Introducing Qt Quick Controls in Qt 5.1
Qt DevDays 2011, Getting Started - a Qt fast track 1/4 - Overview: Oliver Gutbrod
Qt DevDays 2011, Programming with Qt Quick 3/6 - Visual Elements Part 1: Justin Noel
QtDD12 - OpenGL with Qt 5 - Dr. Sean Harmer
Qt DevDays 2011, Programming with Qt Quick 1/6 - Meet Qt Quick Part 1: Justin Noel
https://www.qcustomplot.com/
https://dou.ua/lenta/digests/plus-digest-7/

https://www.youtube.com/watch?v=Y4utTBcSjdM&list=PLB22HyVdO1GkLFrvRi5vIo5XcWS0EflxD

 
 


