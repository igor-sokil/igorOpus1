/*****************************************************/
// Універсальний Захист
/*****************************************************/
 void up_a01_handler(unsigned int *p_active_functions, unsigned int number_group_stp)
{
  for (size_t n_UP = 0; n_UP < NUMBER_UP; n_UP++)
  {
    uint32_t logic_UP_0 = 0;
    
    logic_UP_0 |= (
                   ((current_settings_prt.control_UP & MASKA_FOR_BIT(n_UP*(_CTR_A01_UP_NEXT_BIT - (_CTR_A01_UP_PART_II - _CTR_A01_UP_PART_I) - _CTR_A01_UP_PART_I) + CTR_A01_UP_STATE_BIT - (_CTR_A01_UP_PART_II - _CTR_A01_UP_PART_I))) != 0)
                   &&
                   (_CHECK_SET_BIT(p_active_functions, (RNG_BIG_BLOCK_UP1 + 3*n_UP)) == 0)//!@(_CHECK_SET_BIT(p_active_functions, ( @RANG_BLOCK_UP1 + 3*n_UP)) == 0)
                  ) << 0;

    int32_t pickup = current_settings_prt.setpoint_UP[n_UP][0][number_group_stp];
    //!if (
    //!    (current_settings_prt.ctrl_UP_input[n_UP] == UP_CTRL_3I0) ||
    //!    (current_settings_prt.ctrl_UP_input[n_UP] == UP_CTRL_3I0_others)
    //!   ) 
    //!{
    //!  if (_CHECK_SET_BIT(p_active_functions, (RNG_BIG_PO_UP1 + 3*n_UP)) != 0)//!@if (_CHECK_SET_BIT(p_active_functions, ( @RANG_PO_UP1 + 3*n_UP)) != 0)
    //!  {
    //!    /*
    //!    Алгебраїчне спрощення виразу
    //!    setpoint = (pickup*koef_povernennja/100)*10 =  pickup*koef_povernennja/10
    //!    */
    //!    pickup = (pickup * (int32_t)current_settings_prt.setpoint_UP_KP[n_UP][0][number_group_stp])/10;
    //!  }
    //!  else
    //!  {
    //!    pickup *= 10;
    //!  }
    //!    
    //!}
    //!else
    {
      //!@if (_CHECK_SET_BIT(p_active_functions, ( @RANG_PO_UP1 + 3*n_UP)) != 0) pickup = (pickup * (int32_t)current_settings_prt.setpoint_UP_KP[n_UP][0][number_group_stp])/100;
      if (_CHECK_SET_BIT(p_active_functions, (RNG_BIG_PO_UP1 + 3*n_UP)) != 0) pickup = (pickup * (int32_t)current_settings_prt.setpoint_UP_KP[n_UP][0][number_group_stp])/100;
    }

    unsigned int more_less = ((current_settings_prt.control_UP & MASKA_FOR_BIT(n_UP*(_CTR_A01_UP_NEXT_BIT - (_CTR_A01_UP_PART_II - _CTR_A01_UP_PART_I) - _CTR_A01_UP_PART_I) + CTR_A01_UP_MORE_LESS_BIT - (_CTR_A01_UP_PART_II - _CTR_A01_UP_PART_I))) != 0);
    
    int32_t analog_value = 0;
    uint32_t PQ = false;
    uint32_t bank_for_calc_power_tmp = (state_calc_power == false ) ? bank_for_calc_power : ((bank_for_calc_power ^ 0x1) & 0x1);

    switch (current_settings_prt.ctrl_UP_input[n_UP])
    {
    case UP_CTRL_A01_Io:
      {
        analog_value = measurement[IM_Imn];
        
        break;
      }
    case UP_CTRL_A01_Uo:
      {
        analog_value = measurement[IM_Umn];
        
        break;
      }
    case UP_CTRL_A01_Ir:
      {
        analog_value = measurement[IM_Ibp];
        
        break;
      }
    case UP_CTRL_A01_Ur:
      {
        analog_value = measurement[IM_Ubp];
        
        break;
      }
    
    case UP_CTRL_A01_Po:
      {
        PQ = true;
        analog_value = P[bank_for_calc_power_tmp][0];
        
        break;
      }
    case UP_CTRL_A01_Qo:
      {
        PQ = true;
        analog_value = Q[bank_for_calc_power_tmp][0];
        
        break;
      }
    case UP_CTRL_A01_So:
      {
        analog_value = S[bank_for_calc_power_tmp][0];
        
        break;
      }
    
    case UP_CTRL_A01_Pr:
      {
        PQ = true;
        analog_value = P[bank_for_calc_power_tmp][1];
        
        break;
      }
    case UP_CTRL_A01_Qr:
      {
        PQ = true;
        analog_value = Q[bank_for_calc_power_tmp][1];
        
        break;
      }
    case UP_CTRL_A01_Sr:
      {
        analog_value = S[bank_for_calc_power_tmp][1];
        
        break;
      }
    
    default:
      {
        //Теоретично цього ніколи не мало б бути
        total_error_sw_fixed();
      }
    }
    
    if (more_less)
    {
      if (PQ)
      {
        if (
            (
             (analog_value >= 0) &&
             (pickup >= 0)  
            )
            ||
            (
             (analog_value < 0) &&
             (pickup < 0)  
            ) 
           ) 
        {
          logic_UP_0 |= (abs(analog_value) <= abs(pickup)) << 1;
        }
      }
      else
      {
        logic_UP_0 |= (analog_value <= pickup) << 1;
      }
    }
    else
    {
      if (PQ)
      {
        if (
            (
             (analog_value >= 0) &&
             (pickup >= 0)  
            )
            ||
            (
             (analog_value < 0) &&
             (pickup < 0)  
            ) 
           ) 
        {
          logic_UP_0 |= (abs(analog_value) >= abs(pickup)) << 1;
        }
      }
      else
      {
        logic_UP_0 |= (analog_value >= pickup) << 1;
      }
    }

    _AND2(logic_UP_0, 0, logic_UP_0, 1, logic_UP_0, 2);
//!@    if (_GET_STATE(logic_UP_0, 2)) _SET_BIT(p_active_functions, ( @RANG_PO_UP1 + 3*n_UP));
//!@    else _CLEAR_BIT(p_active_functions, ( @RANG_PO_UP1 + 3*n_UP));
//!@    
//!@    _TIMER_T_0(INDEX_TIMER_UP1 + n_UP, current_settings_prt.timeout_UP[n_UP][0][number_group_stp], logic_UP_0, 2, logic_UP_0, 3);
//!@    if (_GET_STATE(logic_UP_0, 3)) _SET_BIT(p_active_functions, ( @RANG_UP1 + 3*n_UP));
//!@    else _CLEAR_BIT(p_active_functions, ( @RANG_UP1 + 3*n_UP));
    if (_GET_STATE(logic_UP_0, 2)) _SET_BIT(p_active_functions, (RNG_BIG_PO_UP1 + 3*n_UP));
    else _CLEAR_BIT(p_active_functions, (RNG_BIG_PO_UP1 + 3*n_UP));
    
    _TIMER_T_0(INDEX_TIMER_UP1 + n_UP, current_settings_prt.timeout_UP[n_UP][0][number_group_stp], logic_UP_0, 2, logic_UP_0, 3);
    if (_GET_STATE(logic_UP_0, 3)) _SET_BIT(p_active_functions, (RNG_BIG_UP1 + 3*n_UP));
    else _CLEAR_BIT(p_active_functions, (RNG_BIG_UP1 + 3*n_UP));
  }
}
/*****************************************************/
