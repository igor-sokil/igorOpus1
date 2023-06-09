#ifndef __EXTERNAL_FUNCTIONS_H
#define __EXTERNAL_FUNCTIONS_H

extern USB_OTG_CORE_HANDLE           USB_OTG_dev;
extern uint32_t USBD_OTG_ISR_Handler (USB_OTG_CORE_HANDLE *pdev);

#ifdef USB_OTG_HS_DEDICATED_EP1_ENABLED 
extern uint32_t USBD_OTG_EP1IN_ISR_Handler (USB_OTG_CORE_HANDLE *pdev);
extern uint32_t USBD_OTG_EP1OUT_ISR_Handler (USB_OTG_CORE_HANDLE *pdev);
#endif

extern CDC_IF_Prop_TypeDef  APP_FOPS;

extern void MX_FATFS_Init(void);

extern void Configure_I2C(I2C_TypeDef*);
extern void FSMC_SRAM_Init(void);

extern int main(void);
extern void ar_routine_with_fatfs(unsigned int);
extern unsigned int ar_free_space(int*, int*);
extern void periodical_operations(unsigned int);
extern void periodical_operations_communication(unsigned int);
extern void global_vareiables_installation(void);
extern void start_settings_peripherals(void);
extern void start_tim4_canal2_for_interrupt_1mc(void);
extern void start_tim4_canal3_for_interrupt_10mkc(void);
extern void min_settings(__SETTINGS *);
extern void error_reading_with_eeprom(void);

extern void Interrupts_Config(void);

extern void lcd_init(void);
extern unsigned int wait_lcd_ready(void);
extern unsigned int clear_lcd(void);
extern unsigned int mode_viewing(unsigned int, unsigned int, unsigned int);
extern unsigned int hd44780_puts(unsigned char *, unsigned int);
extern unsigned int hd44780_test(unsigned char *, unsigned int);
extern unsigned int Win1251toHd44780 (unsigned int);
extern unsigned int read_data_from_lcd(unsigned char*);
extern unsigned int write_data_to_lcd(unsigned char);
extern unsigned int write_command_to_lcd(unsigned char);
extern unsigned int hd44780_gotoxy(unsigned char, unsigned char);
extern unsigned int hd44780_puts_xy (unsigned char, unsigned char, unsigned char *);
extern void view_whole_ekran(void);
extern void check_state_key(GPIO_TypeDef*, uint16_t, unsigned int);
extern int index_language_in_array(int);

extern void inc_or_dec_value(unsigned int *, unsigned int);
extern unsigned int bcd_to_int(unsigned char);

void make_ekran_level_password(unsigned int password, unsigned int view);
extern void main_manu_function(void);
extern void make_ekran_main(void);
extern void make_ekran_time(void);
extern void edit_time(unsigned int);
extern void make_ekran_ask_rewrite(void);
extern unsigned int check_data_for_data_time_menu(void);
extern void make_ekran_about_error(const unsigned char [][MAX_COL_LCD]);
extern void make_ekran_about_activation_command(unsigned int, unsigned char [][MAX_NAMBER_LANGUAGE][MAX_COL_LCD]);
extern void make_ekran_configuration(unsigned int);
extern void make_ekran_measurement(void);
extern void make_ekran_current(unsigned int);
extern void make_ekran_voltage_line(unsigned int);
extern void make_ekran_frequency(void);
extern void make_ekran_angle(void);
extern void make_ekran_power(unsigned int);
extern void make_ekran_resistance(unsigned int);
extern void convert_and_insert_char_for_measurement(unsigned int, unsigned int, unsigned int, unsigned int, unsigned char *, unsigned int);
extern void convert_and_insert_char_for_frequency(int, unsigned char *);
extern void make_ekran_chose_settings_any_protection(void);
extern void make_ekran_chose_settings_protection_with_groups(void);
extern void make_ekran_chose_setpoint_and_timeout(void);
extern void make_ekran_chose_timeout_control(void);
extern void make_ekran_chose_setpoint_control_transformator(void);
extern void make_ekran_chose_setpoint_transformator(void);
extern void make_ekran_chose_settings_vmp(void);
extern void make_ekran_chose_timeout(void);
extern void make_ekran_chose_control(void);
extern void make_ekran_chose_settings_switcher(void);
extern void make_ekran_chose_settings_switcher_L(void);
extern void make_ekran_chose_settings(void);
extern void make_ekran_chose_passwords(void);
extern void make_ekran_chose_extra_settings(void);
extern void make_ekran_setpoint_mtz(unsigned int);
extern void make_ekran_timeout_mtz(unsigned int);
extern void make_ekran_control_mtz(void);
extern void make_ekran_setpoint_mtzr(unsigned int);
extern void make_ekran_timeout_mtzr(unsigned int);
extern void make_ekran_control_mtzr(void);
extern void make_ekran_setpoint_mtzo(unsigned int);
extern void make_ekran_timeout_mtzo(unsigned int);
extern void make_ekran_control_mtzo(void);
extern void make_ekran_setpoint_dz(unsigned int);
extern void make_ekran_setpoint_dzo(unsigned int);
extern void make_ekran_setpoint_dzr(unsigned int);
extern void make_ekran_timeout_dz(unsigned int);
extern void make_ekran_timeout_dzo(unsigned int);
extern void make_ekran_timeout_dzr(unsigned int);
extern void make_ekran_control_dz(void);
extern void make_ekran_control_dzo(void);
extern void make_ekran_control_dzr(void);
extern void make_ekran_timeout_zdz(unsigned int);
extern void make_ekran_control_zdz(void);
extern void calc_symbol_and_put_into_working_ekran(unsigned char*, void*, void*, unsigned int*, unsigned int, unsigned int, unsigned int, unsigned int);
extern void calc_int_symbol_and_put_into_working_ekran(unsigned char*, unsigned int*, unsigned int*, unsigned int*, unsigned int);
extern unsigned int edit_setpoint(unsigned int,  unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned int check_data_setpoint(unsigned int, unsigned int, unsigned int);
extern unsigned int check_data_setpoint_sign(int, int, int);
extern unsigned int edit_setpoint_signed(unsigned int, unsigned int, unsigned int, unsigned int);
extern void make_ekran_setpoint_zz(unsigned int);
extern void make_ekran_timeout_zz(unsigned int);
extern void make_ekran_control_zz(void);
extern void make_ekran_setpoint_tznp(unsigned int);
extern void make_ekran_timeout_tznp(unsigned int);
extern void make_ekran_control_tznp(void);
extern void make_ekran_timeout_apv(unsigned int);
extern void make_ekran_control_apv(void);
extern void make_ekran_setpoint_achr_chapv(unsigned int);
extern void make_ekran_timeout_achr_chapv(unsigned int);
extern void make_ekran_control_achr_chapv(void);
extern void make_ekran_setpoint_urov(unsigned int);
extern void make_ekran_timeout_urov(unsigned int);
extern void make_ekran_control_urov(void);
extern void make_ekran_setpoint_zop(unsigned int);
extern void make_ekran_timeout_zop(unsigned int);
extern void make_ekran_control_zop(void);
extern void make_ekran_setpoint_Umin(unsigned int);
extern void make_ekran_timeout_Umin(unsigned int);
extern void make_ekran_control_Umin(void);
extern void make_ekran_setpoint_Umax(unsigned int);
extern void make_ekran_timeout_Umax(unsigned int);
extern void make_ekran_control_Umax(void);
extern void make_ekran_setpoint_UP(unsigned int);
extern void make_ekran_setpoint_UP_A01(unsigned int);
extern void make_ekran_timeout_UP(unsigned int);
extern void make_ekran_control_UP(void);
extern void make_ekran_control_UP_A01(void);
extern void make_ekran_chose_of_inputs_outputs_leds_df_buttons_for_ranguvannja(__id_input_output);
extern void make_ekran_transformator(void);
extern void make_ekran_transformator_control(void);
extern void make_ekran_set_function_in_bi(unsigned int, unsigned int);
extern void make_ekran_set_function_in_output_led_df_dt_reg(unsigned int, unsigned int);
extern void check_current_index_is_presented_in_configuration_a01(unsigned int*, /*int*, *//*EL_FILTER_STRUCT[],*/ int, int, int, int, int, int, int, int, int, int, int, int, int, int, int,  int);
extern void make_ekran_choose_CBOn_CBOff(void);
extern void make_ekran_choose_CBOn_CBOff_(uint32_t on_off);
extern void make_ekran_setpoint_switch(void);
extern void make_ekran_timeout_switch(void);
extern void make_ekran_timeout_switch_(uint32_t on_off);
extern void make_ekran_control_switch(void);
extern void make_ekran_control_switch_(uint32_t on_off);
extern void make_ekran_setpoint_VMP(int);
extern void make_ekran_control_VMP(void);
extern void make_ekran_chose_settings_uvv(void);
extern void make_ekran_dopusk_dv(void);
extern void make_ekran_type_input_uvv(unsigned int);
extern void make_ekran_type_output_uvv(void);
extern void make_ekran_type_led_uvv(void);
extern void make_ekran_type_button_uvv(void);
extern void correct_dopusk_dv_when_type_of_input_signal_is_changed(void);
extern void make_ekran_chose_communication_parameters(void);
extern void make_ekran_name_of_cell(void);
extern void make_ekran_address(void);
extern void make_ekran_chose_setting_rs485(void);
extern void make_ekran_speed_interface(void);
extern void make_ekran_pare_interface(void);
extern void make_ekran_stopbits_interface(void);
extern void make_ekran_timeout_interface(void);
extern void make_ekran_chose_data_time_settings(void);
extern void make_ekran_timezone_dst(void);
extern void make_ekran_dst_rule(uint32_t);
extern void make_ekran_chose_registrators(void);
extern void make_ekran_settings_analog_registrators(void);
extern void make_ekran_timeout_analog_registrator(void);
extern void make_ekran_control_ar(void);
extern void make_ekran_extended_logic(void);
extern void make_ekran_general_pickups_el(void);
extern void make_ekran_chose_settings_df(void);
extern void make_ekran_type_df(void);
extern void make_ekran_timeout_df(unsigned int);
extern void make_ekran_list_type_source_df(void);
extern void make_ekran_set_reset_trigger(void);
extern void make_ekran_list_type_source_dt(void);
extern void make_ekran_list_source_tf(void);
extern void make_ekran_info(void);
extern void make_ekran_date_time_pz(void);
extern void make_ekran_chose_item_of_point_time_settings(void);
extern void make_ekran_time_settings(unsigned int);
extern void make_ekran_diagnostyka(unsigned int volatile*);
extern void make_ekran_list_inputs_outputs(void);
extern void make_ekran_state_inputs_or_outputs(unsigned int);
extern void make_ekran_list_registrators(void);
extern void make_ekran_list_records_registrator(unsigned int);
extern void make_ekran_list_records_registrator_ar(void);
extern void make_ekran_list_titles_for_record_of_digital_registrator(void);
extern void make_ekran_title_analog_value_records_digital_registrator(void);
extern void make_ekran_analog_value_records_digital_registrator(unsigned int);
extern void make_ekran_changing_signals_digital_registrator(void);
extern void make_ekran_changing_diagnostics_pr_err_registrator(void);
extern void make_ekran_setting_language(void);
extern void make_ekran_resurs(void);
extern void make_ekran_energy(unsigned int);
extern void make_ekran_grupa_ustavok(void);
extern void make_ekran_vidkluchenja(void);
extern void make_ekran_timeout_digital_registrator(void);
extern void make_ekran_settings_digital_registrators(void);

extern unsigned int action_after_changing_of_configuration(unsigned int, __SETTINGS *);
extern void action_during_changing_button_mode(__SETTINGS *, __SETTINGS *);
extern void def_pickup_timeout_UP(__SETTINGS *, uint32_t, uint32_t);
extern void action_after_changing_input_UP(__SETTINGS *, uint32_t, uint32_t);
extern void action_after_changing_ctrl_UP(__SETTINGS *, uint32_t);
//extern void action_after_changing_number_el(__SETTINGS *, unsigned int);
extern void calculate_namber_bit_waiting_for_rs_485(void);
extern void fix_change_settings(unsigned int, unsigned int);
extern unsigned int set_new_settings_from_interface(unsigned int);
extern void restore_trigger_functions(unsigned int*);
extern void changing_diagnostyka_state(void);
extern unsigned int count_number_set_bit(unsigned int*, unsigned int);

extern void set_bit(unsigned int*, unsigned int);
extern void clear_bit(unsigned int*, unsigned int);
extern void input_scan(void);
extern void clocking_global_timers(void);
extern void main_protection(void);
extern void df_handler(unsigned int*);
extern void dt_handler(unsigned int*);
extern void d_and_handler(unsigned int*);
extern void d_or_handler(unsigned int*);
extern void d_xor_handler(unsigned int*);
extern void d_not_handler(unsigned int*);
extern void tf_handler(unsigned int*, unsigned int*, unsigned int*);
extern void mtzr_handler(unsigned int*, unsigned int);
extern void mtzo_handler(unsigned int*, unsigned int);
extern void dz_handler(unsigned int*, unsigned int);
extern void dzr_handler(unsigned int*, unsigned int);
extern void dzo_handler(unsigned int*, unsigned int);
extern void zdz_handler(unsigned int*, unsigned int);
extern int timeout_dependent_general(const unsigned int i, const uint32_t, const int32_t, const int32_t, const int32_t);
extern void umin1_handler(unsigned int*, unsigned int);
extern void umin2_handler(unsigned int*, unsigned int);
extern void umax1_handler(unsigned int*, unsigned int);
extern void umax2_handler(unsigned int*, unsigned int);
extern void achr_chapv_handler(unsigned int*, unsigned int);
extern void ready_tu(unsigned int*);
extern void urov_handler(unsigned int*, unsigned int);
extern void apv_handler(unsigned int*, unsigned int);
extern void up_a01_handler(unsigned int *, unsigned int );
extern void on_off_vvr(unsigned int *p_active_functions);
extern void on_off_vvo(unsigned int *p_active_functions);
extern void vmp_handler(unsigned int*);
extern void control_VV(unsigned int*);
extern void control_VVR(unsigned int*);
extern void make_koef_for_resurs(void);
extern void resurs_vymykacha_handler(unsigned int*);
extern unsigned int stop_regisrator(unsigned int*, unsigned int*);
extern void fix_undefined_error_dr(unsigned int*);
extern void command_start_saving_record_dr_into_dataflash(void);
extern void routine_for_queue_dr(void);
extern void digital_registrator(unsigned int*);
extern void analog_registrator(unsigned int*);
extern void diagnostyca_adc_execution(void);

extern void Usb_routines_irq(void);
extern void Usb_routines(void);
extern void USART_RS485_Configure(void);
extern void restart_monitoring_RS485(void);
extern void start_transmint_data_via_RS_485(unsigned int);
extern unsigned short int  AddCRC(unsigned char, unsigned short int);

extern ErrorStatus check_errors_i2c(void);
extern unsigned int start_write_buffer_via_I2C(uint32_t, uint32_t, uint8_t*, uint32_t);
extern unsigned int start_read_buffer_via_I2C(uint32_t, uint32_t, uint8_t*, uint32_t);
extern void main_routines_for_i2c(void);
extern void error_start_i2c(void);

extern void find_new_ADC_canal_to_read(unsigned int, unsigned int*);
extern void control_reading_ADCs(void);
extern void operate_test_ADCs(void);
extern void Fourier(void);
extern void fapch(void);
extern void calc_measurement(unsigned int);
extern unsigned int norma_value(unsigned long long);
extern unsigned int sqrt_32(unsigned int);
extern unsigned int sqrt_64(unsigned long long);
extern unsigned int get_order(int);

extern void calc_angle(void);
extern void calc_power(int*);
extern void calc_power_and_energy(void);
extern void calc_resistance(int*, int*);

extern void directional_mtz(int*, unsigned int);
extern void directional_dz(int*, unsigned int);

extern void main_routines_for_spi1(void);
extern void main_function_for_dataflash_resp(int);
extern void main_function_for_dataflash_req(int);
extern void start_checking_dataflash(void);
extern void start_exchange_via_spi(int, unsigned int);
extern void dataflash_status_read(int);
extern void dataflash_set_pagesize_256(int);
extern void dataflash_erase(int);
extern void dataflash_mamory_page_program_through_buffer(int);
extern void dataflash_mamory_read(int);
extern void dataflash_mamory_page_into_buffer(int);
extern void dataflash_mamory_write_buffer(int);
extern void dataflash_mamory_buffer_into_memory(int);
extern void analize_received_data_dataflash(int);

extern void control_settings(void);
extern void control_ustuvannja(void);
extern void control_trg_func(void);
extern unsigned int control_info_rejestrator(__INFO_REJESTRATOR*, unsigned char);
extern unsigned int control_info_ar_rejestrator(__INFO_AR_REJESTRATOR*, unsigned char);
extern void control_resurs(void);

extern void test_external_SRAM(void);

extern void watchdog_routine(unsigned int);
extern void total_error_sw_fixed(void);

extern void NMI_Handler(void);
extern void HardFault_Handler(void);
extern void MemManage_Handler(void);
extern void BusFault_Handler(void);
extern void UsageFault_Handler(void);
extern void SVC_Handler(void);
extern void DebugMon_Handler(void);
extern void PendSV_Handler(void);
extern void SysTick_Handler(void);
extern void USB_LP_CAN1_RX0_IRQHandler(void);
extern void TIM2_IRQHandler(void);
extern void TIM4_IRQHandler(void);
extern void TIM5_IRQHandler(void);
extern void I2C_EV_IRQHandler(void);
extern void I2C_ER_IRQHandler(void);
extern void DMA_StreamI2C_Tx_IRQHandler(void);
extern void DMA_StreamI2C_Rx_IRQHandler(void);
extern void SPI_ADC_IRQHandler(void);
extern void DMA_StreamSPI_EDF_Rx_IRQHandler(void);
extern void SPI_EDF_IRQHandler(void);
extern void USARTRS485_IRQHandler(void);
extern void DMA_StreamRS485_Tx_IRQHandler(void);
extern void EXITI_POWER_IRQHandler(void);

extern void setpoints_selecting(unsigned int*, unsigned int);

extern int str_to_int_DATE_Mmm(void);

extern void inputPacketParserUSB(void);
extern void inputPacketParserRS485(void);

#if (__VER__ >= 8000000)
extern int _ForceReloadDstRules (void);
#endif

#endif
