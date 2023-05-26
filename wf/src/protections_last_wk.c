#include "header.h"

/*****************************************************/
//Діагностика АЦП
/*****************************************************/
inline void diagnostyca_adc_execution(void)
{
  if ((vref_adc <0x709) || (vref_adc > 0x8f5)) _SET_BIT(set_diagnostyka, ERROR_VREF_ADC_TEST_BIT);
  else _SET_BIT(clear_diagnostyka,ERROR_VREF_ADC_TEST_BIT);
}
/*****************************************************/

/*****************************************************/
//Пошук розрядності числа
/*****************************************************/
inline unsigned int norma_value(unsigned long long y)
{
  unsigned long long temp=y;
  unsigned int rezultat =0;
  if (temp == 0) return 0;

  while(temp !=0)
  {
    temp = temp>>1;
    rezultat++;
  }
  return rezultat-1;
}
/*****************************************************/

/*****************************************************/
//Пошук розрядності числа типу int
/*****************************************************/
inline unsigned int get_order(int value)
{
  unsigned int i = 0;

  if (value == 0) return 1;  
  if (value < 0) value =-value;

  while ((value >> (++i)) != 0); 

  return i;    
}
/*****************************************************/

/*****************************************************/
//Розрахунок кореня квадратного методом половинного ділення  з прогнозуванням розрядності числа
/*****************************************************/
unsigned int sqrt_64(unsigned long long y)
{
   unsigned int b;
   unsigned int a;
   unsigned int c;
   unsigned int norma_rez;
   unsigned long long temp;
   
   norma_rez = norma_value(y)>>1;
   
   a = (1<<norma_rez) - 1;
   b = (1<<(norma_rez+1));
 
   do 
    {
     c = (a + b)>>1;
     temp = (unsigned long long)c*(unsigned long long)c; 
     if (temp != y)
       {
        if ( temp > y) b= c; else a= c;
       } 
     else return c;
    }
   while ((b-a)>1);

   c = (a + b)>>1;

   return c ;
}
/*****************************************************/

/*****************************************************/
//Розрахунок кореня квадратного методом половинного ділення  з прогнозуванням розрядності числа
/*****************************************************/
inline unsigned int sqrt_32(unsigned int y)
{
   unsigned int b;
   unsigned int a;
   unsigned int c;
   unsigned int norma_rez;
   unsigned int temp;
   
   norma_rez = norma_value(y)>>1;
   
   a = (1<<norma_rez) - 1;
   b = (1<<(norma_rez+1));
 
   do 
    {
     c = (a + b)>>1;
     temp = c*c; 
     if (temp != y)
       {
        if ( temp > y) b= c; else a= c;
       } 
     else return c;
    }
   while ((b-a)>1);

   c = (a + b)>>1;

   return c ;
}
/*****************************************************/

#include "dz.c"

/*****************************************************/
//Направленість МТЗ з визначенням секторів
/*****************************************************/
inline void directional_mtz(int ortogonal_local_calc[], unsigned int number_group_stp) 
{
  for (unsigned int i = 0; i < 2; ++i)
  {
    static unsigned int const bit_configuration[2] = {MCZO_BIT_CONFIGURATION, MCZR_BIT_CONFIGURATION};
    static unsigned int Uxy_bilshe_porogu[2];
    static unsigned int Ix_bilshe_porogu[2];
    
    if ((current_settings_prt.configuration & (1u << bit_configuration[i])) != 0)
    {
      static unsigned int const index_I[2] = {IM_Imn, IM_Ibp};
      static unsigned int const index_U[2] = {IM_Umn, IM_Ubp};
      
      unsigned int porig_Uxy;
      if (Uxy_bilshe_porogu[i] == 0) porig_Uxy = PORIG_CHUTLYVOSTI_VOLTAGE_ANGLE*KOEF_POVERNENNJA_SECTOR_BLK/100;
      else porig_Uxy = PORIG_CHUTLYVOSTI_VOLTAGE_ANGLE;
      Uxy_bilshe_porogu[i] = (measurement[index_U[i]] >= porig_Uxy);
      
      unsigned int porig_Ix;
      if (Ix_bilshe_porogu[i] == 0) porig_Ix = PORIG_CHUTLYVOSTI_CURRENT*KOEF_POVERNENNJA_SECTOR_BLK/100;
      else porig_Ix = PORIG_CHUTLYVOSTI_CURRENT;
      Ix_bilshe_porogu[i]  = (measurement[index_I[i]] >= porig_Ix );
      
      if (
          (Uxy_bilshe_porogu[i] != 0) &&
          (Ix_bilshe_porogu[i]  != 0)
         )
      {
        /***/
        for (unsigned int msz = 0; msz < 4; ++msz)
        {
          static int (* const mtz_angle_cos[4][2])[NUMBER_GROUP_USTAVOK] = {
                                                                            {&current_settings_prt.setpoint_mtz_1_angle_cos,  &current_settings_prt.setpoint_mtz_1_angle_cos},
                                                                            {&current_settings_prt.setpoint_mtz_2_angle_cos,  &current_settings_prt.setpoint_mtz_2_angle_cos},
                                                                            {&current_settings_prt.setpoint_mtz_3_angle_cos,  &current_settings_prt.setpoint_mtz_3_angle_cos},
                                                                            {&current_settings_prt.setpoint_mtz_4_angle_cos,  &current_settings_prt.setpoint_mtz_4_angle_cos}
                                                                           };
          static int (* const mtz_angle_sin[4][2])[NUMBER_GROUP_USTAVOK] = {
                                                                            {&current_settings_prt.setpoint_mtz_1_angle_sin,  &current_settings_prt.setpoint_mtz_1_angle_sin},
                                                                            {&current_settings_prt.setpoint_mtz_2_angle_sin,  &current_settings_prt.setpoint_mtz_2_angle_sin},
                                                                            {&current_settings_prt.setpoint_mtz_3_angle_sin,  &current_settings_prt.setpoint_mtz_3_angle_sin},
                                                                            {&current_settings_prt.setpoint_mtz_4_angle_sin,  &current_settings_prt.setpoint_mtz_4_angle_sin}
                                                                           };
        
          int a_cos_fi = (*mtz_angle_cos[msz][i])[number_group_stp];
          int a_sin_fi = (*mtz_angle_sin[msz][i])[number_group_stp];
          a_sin_fi = -a_sin_fi; //З розділу: "Неймовірно, але факт", тобто що я не можу пояснити

          //Робимо доповорот на встановлений кут
          /*
          За розрахунком описаним при розрахунку діючих значень наші ортогональні є у ворматі (15 біт + знак) = 16-розряжне число
          */
          int amp_cos_U_fi;
          int amp_sin_U_fi;
  
          static unsigned int const index_I_ort[2] = {FULL_ORT_Imn, FULL_ORT_Ibp};
          static unsigned int const index_U_ort[2] = {FULL_ORT_Umn, FULL_ORT_Ubp};

#define SIN_I   ortogonal_local_calc[2*index_I_ort[i]    ]
#define COS_I   ortogonal_local_calc[2*index_I_ort[i] + 1]
#define SIN_U   ortogonal_local_calc[2*index_U_ort[i]    ]
#define COS_U   ortogonal_local_calc[2*index_U_ort[i] + 1]

          amp_cos_U_fi = (COS_U*a_cos_fi - SIN_U*a_sin_fi) >> AMPLITUDA_FI_VAGA; //З поверненням до початкової розрядності ортогональних
          amp_sin_U_fi = (SIN_U*a_cos_fi + COS_U*a_sin_fi) >> AMPLITUDA_FI_VAGA; //З поверненням до початкової розрядності ортогональних

          //Вираховуємо COS і SIN кута різниці між (U[i]+fi) і I[i]
          int cos_fi, sin_fi;
          /*
          З наведених теоретичних роззрахунків у функції обрахунку діючих значень (calc_measurement())
          випливає, що максимальне значення ортогональних для струму може бути 0x6E51, для лінійної напруги 
          0x120FC, то добуток їх має дати 0x7C87B7BC  - 31 бітне число (плюс знак біту)
          Тобто ми акладаємося у тип int.
          */
          cos_fi = amp_cos_U_fi*COS_I + amp_sin_U_fi*SIN_I;
          sin_fi = -(amp_sin_U_fi*COS_I - amp_cos_U_fi*SIN_I);//З розділу: "Неймовірно, але факт", тобто що я не можу пояснити

#undef SIN_I
#undef COS_I
#undef SIN_U
#undef COS_U

          /*
          З вище наведених розрахункыв виходить, що COS і SIN різниці струму і напруги може бути 31-бітне число
          Векторні координати границь секторів задано 7-бінтими числами + знак
          Тоді щоб не отримати переповнення треба гарантувати, що розрядність різниці векторів
          COS і SIN буде = 31 - (7 + 1) = 23
          7 - це розрядність координат векторів границь секторів
          1 - це врахування що ми використовіємо формулу (ab+cd)
          */
          unsigned int order_cos, order_sin, max_order, shift = 0;
          order_cos = get_order(cos_fi);
          order_sin = get_order(sin_fi);
          if (order_cos > order_sin) max_order = order_cos; else max_order = order_sin;
          if (max_order > 23) shift = max_order - 23;
  
          /*
          Сам зсув я роблю після визначення квадранта - це хоч і втрата на розмірі програмного коду,
          але мало б підвищити точність визначення квадранту.
          Хоч може тут я перемудровую?..
          */

          //Визначення сектору
          int sin_fi1_minus_fi2;
          int *sector;
          if ((sin_fi >= 0) && (cos_fi >= 0))
          {
            //1-ий квадрант
            cos_fi = cos_fi >> shift;
            sin_fi = sin_fi >> shift;
          
            if (sector_directional_mtz[msz][i] != 1)
              sector = sector_1_mtz_tznp;
            else
              sector = sector_2_mtz_tznp;
          
#define COS_SECTOR sector[0]    
#define SIN_SECTOR sector[1]    

            sin_fi1_minus_fi2 = sin_fi*COS_SECTOR - cos_fi*SIN_SECTOR;
            sector_directional_mtz[msz][i] = (sin_fi1_minus_fi2 <= 0) ?  1 : 0;
    
#undef COS_SECTOR    
#undef SIN_SECTOR   
          }
          else if ((sin_fi >= 0) && (cos_fi < 0))
          {
            //2-ий квадрант
            cos_fi = cos_fi >> shift;
            sin_fi = sin_fi >> shift;

            if (sector_directional_mtz[msz][i] != 2)
              sector = sector_1_mtz_tznp;
            else
              sector = sector_2_mtz_tznp;

#define COS_SECTOR sector[2]    
#define SIN_SECTOR sector[3]    

            sin_fi1_minus_fi2 = sin_fi*COS_SECTOR - cos_fi*SIN_SECTOR;
            sector_directional_mtz[msz][i] = (sin_fi1_minus_fi2 >= 0) ?  2 : 0;
    
#undef COS_SECTOR    
#undef SIN_SECTOR    
          }
          else if ((sin_fi < 0) && (cos_fi < 0))
          {
            //3-ий квадрант
            cos_fi = cos_fi >> shift;
            sin_fi = sin_fi >> shift;

            if (sector_directional_mtz[msz][i] != 2)
              sector = sector_1_mtz_tznp;
            else
              sector = sector_2_mtz_tznp;

#define COS_SECTOR sector[4]    
#define SIN_SECTOR sector[5]    

            sin_fi1_minus_fi2 = sin_fi*COS_SECTOR - cos_fi*SIN_SECTOR;
            sector_directional_mtz[msz][i] = (sin_fi1_minus_fi2 <= 0) ?  2 : 0;
    
#undef COS_SECTOR    
#undef SIN_SECTOR    
          }
          else
          {
            //4-ий квадрант
            cos_fi = cos_fi >> shift;
            sin_fi = sin_fi >> shift;

            if (sector_directional_mtz[msz][i] != 1)
              sector = sector_1_mtz_tznp;
            else
              sector = sector_2_mtz_tznp;

#define COS_SECTOR sector[6]    
#define SIN_SECTOR sector[7]    

            sin_fi1_minus_fi2 = sin_fi*COS_SECTOR - cos_fi*SIN_SECTOR;
            sector_directional_mtz[msz][i] = (sin_fi1_minus_fi2 >= 0) ?  1 : 0;
    
#undef COS_SECTOR    
#undef SIN_SECTOR    
          }
        }
      }
      else
      {
        for (unsigned int msz = 0; msz < 4; ++msz) sector_directional_mtz[msz][i] = 0;
      }
      /***/
    }
    else
    {
      Uxy_bilshe_porogu[i] = 0;
      Ix_bilshe_porogu[i] = 0;
      for (size_t msz = 0; msz < 4; ++msz) sector_directional_mtz[msz][i] = 0;
    }
  }
      
}
/*****************************************************/

/*****************************************************/
//Визначенням опорів
/*****************************************************/
inline void calc_resistance(int ortogonal_local_calc[], int resistance_output[]) 
{
  const unsigned int index_line_voltage[2] = {FULL_ORT_Umn, FULL_ORT_Ubp};
  const unsigned int index_current[2]= {FULL_ORT_Imn , FULL_ORT_Ibp};
  
  static unsigned int Ix_bilshe_porogu_R[2];

  //Міжфазний опір
  for (unsigned int i = 0; i < 2; i++)
  {
#define _A1     ortogonal_local_calc[2*index_line_voltage[i] + 0]
#define _B1     ortogonal_local_calc[2*index_line_voltage[i] + 1]

#define _A2     ortogonal_local_calc[2*index_current[i] + 0]
#define _B2     ortogonal_local_calc[2*index_current[i] + 1]
    
    long long mod = (long long)_A2*(long long)_A2 + (long long)_B2*(long long)_B2;
    

    //Розраховуємо діюче значення струму Ix
    unsigned int Ix = ( MNOGNYK_I_DIJUCHE*(sqrt_64(mod)) ) >> (VAGA_DILENNJA_I_DIJUCHE + 4);
    unsigned int porig_Ix = (Ix_bilshe_porogu_R[i] == 0) ? (PORIG_Ix_FOR_R*U_DOWN/100) : PORIG_Ix_FOR_R;
    Ix_bilshe_porogu_R[i]  = (Ix >= porig_Ix );
    if (Ix_bilshe_porogu_R[i])
    {
      //Можна розраховувати міжфазний опір
      /*
       .
      Uxy   Re(Uxy) + iIm(Uxy)   a1 + ib1    (a1 + ib1)(a2 - ib2)    (a1a2 + b1b2) + i(a2b1 - a1b2)    a1a2 + b1b2      a2b1 - a1b2
      --- = ------------------ = --------- = --------------------- = ------------------------------ =  ------------ + i--------------
       .                                                                     2      2                     2      2         2      2
      Ix     Re(Ix) + iIm(Ix)    a2 + ib2    (a2 + ib2)(a2 - ib2)          a2   + b2                    a2   + b2        a2   + b2
      */
      
      float R = MNOGNYK_R_FLOAT*((float)((long long)_A1*(long long)_A2 + (long long)_B1*(long long)_B2))/((float)mod);
      float X = MNOGNYK_R_FLOAT*((float)((long long)_A2*(long long)_B1 - (long long)_A1*(long long)_B2))/((float)mod);
      resistance_output[R_mn + 3*i    ] = (int)R;
      resistance_output[R_mn + 3*i + 1] = (int)X;
      
      float Z;
      arm_status res = arm_sqrt_f32((R*R + X*X), &Z);
      resistance_output[R_mn + 3*i + 2] = (res == ARM_MATH_SUCCESS) ? (int)Z : UNDEF_RESISTANCE;

      resistance_output[Za_mn + i] = 1000*U_LINEAR_NOM/Ix; /*Ixy_max треба проініціалізувати нулем. бо може бути випадок, що три лінійні струми менші за поріг чутливості і це треба якось зафіксуватим*/
    }
    else
    {
      //Не можна розраховувати міжфазний опір
      resistance_output[R_mn + 3*i    ] = UNDEF_RESISTANCE;
      resistance_output[R_mn + 3*i + 1] = UNDEF_RESISTANCE;
      resistance_output[R_mn + 3*i + 2] = UNDEF_RESISTANCE;
      
      resistance_output[Za_mn + i] =  UNDEF_RESISTANCE;
    }
    
#undef _A2
#undef _B2
    
#undef _A1
#undef _B1
  }
}
/*****************************************************/

/*****************************************************/
//Фазочутливий елемент  для опорів
/*****************************************************/
inline void directional_dz(int ortogonal_local_calc[], unsigned int number_group_stp) 
{
  for (size_t i = 0; i < 2; ++i)
  {
    static unsigned int const bit_configuration[2] = {DZO_BIT_CONFIGURATION, DZR_BIT_CONFIGURATION};
    static unsigned int Uxy_bilshe_porogu_dz[2];
    static unsigned int Ix_bilshe_porogu_dz[2];
    
    if ((current_settings_prt.configuration & (1u << bit_configuration[i])) != 0)
    {
      static unsigned int const index_I[2] = {IM_Imn, IM_Ibp};
      static unsigned int const index_U[2] = {IM_Umn, IM_Ubp};

      unsigned int porig_Uxy;
      if (Uxy_bilshe_porogu_dz[i] == 0) porig_Uxy = PORIG_CHUTLYVOSTI_VOLTAGE_ANGLE_DZ*KOEF_POVERNENNJA_SECTOR_BLK/100;
      else porig_Uxy = PORIG_CHUTLYVOSTI_VOLTAGE_ANGLE_DZ;
      Uxy_bilshe_porogu_dz[i] = (measurement[index_U[i]] >= porig_Uxy);
      
      unsigned int porig_Ix;
      if (Ix_bilshe_porogu_dz[i] == 0) porig_Ix = PORIG_CHUTLYVOSTI_CURRENT_ANGLE_DZ*KOEF_POVERNENNJA_SECTOR_BLK/100;
      else porig_Ix = PORIG_CHUTLYVOSTI_CURRENT_ANGLE_DZ;
      Ix_bilshe_porogu_dz[i]  = (measurement[index_I[i]] >= porig_Ix );

      if (
          (Uxy_bilshe_porogu_dz[i] != 0) &&
          (Ix_bilshe_porogu_dz[i]  != 0)
         )
      {
        static unsigned int const index_I_ort[2] = {FULL_ORT_Imn, FULL_ORT_Ibp};
        static unsigned int const index_U_ort[2] = {FULL_ORT_Umn, FULL_ORT_Ubp};

#define SIN_I   ortogonal_local_calc[2*index_I_ort[i]    ]
#define COS_I   ortogonal_local_calc[2*index_I_ort[i] + 1]
#define SIN_U   ortogonal_local_calc[2*index_U_ort[i]    ]
#define COS_U   ortogonal_local_calc[2*index_U_ort[i] + 1]

        //Вираховуємо COS і SIN кута різниці між U[i] і I[i]
        /*
        З наведених теоретичних роззрахунків у функції обрахунку діючих значень (calc_measurement())
        випливає, що максимальне значення ортогональних для струму може бути 0x6E51, для лінійної напруги 
        0x120FC, то добуток їх має дати 0x7C87B7BC  - 31 бітне число (плюс знак біту)
        Тобто ми вкладаємося у тип int.
        */
        int32_t sin_fi = -(SIN_I*COS_U - COS_I*SIN_U);//З розділу: "Неймовірно, але факт", тобто що я не можу пояснити
        int32_t cos_fi = COS_I*COS_U + SIN_I*SIN_U;

#undef SIN_I
#undef COS_I
#undef SIN_U
#undef COS_U

        /*
        З вище наведених розрахункыв виходить, що COS і SIN різниці струму і напруги може бути 31-бітне число
        Векторні координати границь секторів задано 7-бінтими числами + знак
        Тоді щоб не отримати переповнення треба гарантувати, що розрядність різниці векторів
        COS і SIN буде = 31 - (7 + 1) = 23
        7 - це розрядність координат векторів границь секторів
        1 - це врахування що ми використовіємо формулу (ab+cd)
        */
        uint32_t order_cos, order_sin, max_order, shift = 0;
        order_cos = get_order(cos_fi);
        order_sin = get_order(sin_fi);
        if (order_cos > order_sin) max_order = order_cos; else max_order = order_sin;
        if (max_order > 23) shift = max_order - 23;
        cos_fi = cos_fi >> shift;
        sin_fi = sin_fi >> shift;
  
        for (size_t dz = 0; dz < (4 - 2); ++dz)
        {
          /*
          За розрахунком описаним при розрахунку діючих значень наші ортогональні є у ворматі (15 біт + знак) = 16-розряжне число
          */
          /*
          const sector_LOW[A][B][C]
          A -> 0 - (4-2)
            [0] -> DZ2
            [1] -> DZ3

          B -> 0 - 2
            [0] -> Основна лінія
            [1] -> Резервна лінія

          C -> 0 - 2
            [0] -> сектор спрацювання
            [1] -> сектор відпускання

          D -> 0 - 2
            [0] -> SIN
            [1] -> COS
          */
          static int32_t (* const sector_LOW[4-2][2][2][2])[NUMBER_GROUP_USTAVOK] = {
                                                                                     {
                                                                                      {
                                                                                       {&current_settings_prt.pickup_dzo2_angle_sin1,  &current_settings_prt.pickup_dzo2_angle_cos1},
                                                                                       {&current_settings_prt.pickup_dzo2_angle_sin2,  &current_settings_prt.pickup_dzo2_angle_cos2}
                                                                                      },
                                                                                      {
                                                                                       {&current_settings_prt.pickup_dzr2_angle_sin1,  &current_settings_prt.pickup_dzr2_angle_cos1},
                                                                                       {&current_settings_prt.pickup_dzr2_angle_sin2,  &current_settings_prt.pickup_dzr2_angle_cos2}
                                                                                      },
                                                                                     },
                                                                                     {
                                                                                      {
                                                                                       {&current_settings_prt.pickup_dzo3_angle_sin1_l,  &current_settings_prt.pickup_dzo3_angle_cos1_l},
                                                                                       {&current_settings_prt.pickup_dzo3_angle_sin2_l,  &current_settings_prt.pickup_dzo3_angle_cos2_l}
                                                                                      }, 
                                                                                      {
                                                                                       {&current_settings_prt.pickup_dzr3_angle_sin1_l,  &current_settings_prt.pickup_dzr3_angle_cos1_l},
                                                                                       {&current_settings_prt.pickup_dzr3_angle_sin2_l,  &current_settings_prt.pickup_dzr3_angle_cos2_l}
                                                                                      }
                                                                                     }
                                                                                    };
          
          //Визначення сектору
          unsigned int v_zoni = (sector_directional_dz[dz][i] != SECTOR_DZ_NONE);
          
          int32_t const sector_L[2] = {
                                       (*sector_LOW[dz][i][v_zoni][0])[number_group_stp],
                                       (*sector_LOW[dz][i][v_zoni][1])[number_group_stp]
                                      };
          
          int32_t sector_H[2];
          if (dz == 0)
          {
            static const int32_t sector_HIGH[2][2] = {
                                                      {120, -44}, 
                                                      {115, -56}
                                                     };

            sector_H[0] = sector_HIGH[v_zoni][0];
            sector_H[1] = sector_HIGH[v_zoni][1];
          }
          else
          {
            static int32_t (* const sector_HIGH[2][2][2])[NUMBER_GROUP_USTAVOK] = {
                                                                                   { 
                                                                                    {&current_settings_prt.pickup_dzo3_angle_sin1_h,  &current_settings_prt.pickup_dzo3_angle_cos1_h},
                                                                                    {&current_settings_prt.pickup_dzo3_angle_sin2_h,  &current_settings_prt.pickup_dzo3_angle_cos2_h}
                                                                                   }, 
                                                                                   { 
                                                                                    {&current_settings_prt.pickup_dzr3_angle_sin1_h,  &current_settings_prt.pickup_dzr3_angle_cos1_h},
                                                                                    {&current_settings_prt.pickup_dzr3_angle_sin2_h,  &current_settings_prt.pickup_dzr3_angle_cos2_h}
                                                                                   }, 
                                                                                 };
            sector_H[0] = (*sector_HIGH[i][v_zoni][0])[number_group_stp];
            sector_H[1] = (*sector_HIGH[i][v_zoni][1])[number_group_stp];
          }
          
          int sin_fiH_minus_fi = sector_H[0]*cos_fi - sector_H[1]*sin_fi;
          int sin_fiL_minus_fi = sector_L[0]*cos_fi - sector_L[1]*sin_fi;
          
          if (sin_fiH_minus_fi >=0)
          {
            sector_directional_dz[dz][i] = (sin_fiL_minus_fi <=0) ? SECTOR_DZ_FORWARD : SECTOR_DZ_NONE;
          }
          else
          {
            sector_directional_dz[dz][i] = (sin_fiL_minus_fi >=0) ? SECTOR_DZ_BACKWARD : SECTOR_DZ_NONE;
          }
        }
      }
      else
      {
        for (size_t dz = 0; dz < (4 - 2); ++dz) sector_directional_dz[dz][i] = SECTOR_DZ_NONE;
      }
    }
    else
    {
      Uxy_bilshe_porogu_dz[i] = 0;
      Ix_bilshe_porogu_dz[i] = 0;
      for (size_t dz = 0; dz < (4 - 2); ++dz) sector_directional_dz[dz][i] = SECTOR_DZ_NONE;
    }
  }
}
/*****************************************************/

/*****************************************************/
//Визначенням миттєвої потужності
/*****************************************************/
inline void calc_power(int ortogonal_local_calc[]) 
{
  /*
  Розраховуємо дійсну і уявну частину потужності у компдексній площині
  
  .    . . 
  S = UaIa*
  */
  const unsigned int index_line_voltage[2] = {FULL_ORT_Umn, FULL_ORT_Ubp};
  const unsigned int index_current[2]= {FULL_ORT_Imn , FULL_ORT_Ibp};
  const unsigned int index_meas_current[2] = {IM_Imn, IM_Ibp};
  
  unsigned int bank_for_enegry_tmp = bank_for_enegry;  
  for (size_t line = 0; line < 2; ++line)
  {
#define I_SIN          ortogonal_local_calc[2*index_current[line] + 1]
#define I_COS          ortogonal_local_calc[2*index_current[line] + 0]
#define U_SIN          ortogonal_local_calc[2*index_line_voltage[line] + 1]
#define U_COS          ortogonal_local_calc[2*index_line_voltage[line] + 0]
  
    long long P_adc_x16, Q_adc_x16; /*активнаф реактивна  потужності у поділках АЦП і з вхідними сигналами, які є підсилені у 16 разів*/
    if (measurement[index_meas_current[line]] >= PORIG_I_ENERGY)
    {
      P_adc_x16 = U_COS*I_COS + U_SIN*I_SIN;
      Q_adc_x16 = U_SIN*I_COS - U_COS*I_SIN;
    }
    else
    {
      P_adc_x16 = 0;
      Q_adc_x16 = 0;
    }

#undef I_SIN
#undef I_COS
#undef U_SIN
#undef U_COS
  
    /*
    Коли перемножимо на коефіцієнти MNOGNYK_I_DIJUCHE_FLOAT і MNOGNYK_U_DIJUCHE_FLOAT,
    а потім поділемо на 16x16 - то отримаємо мАхмВ = мкВт/мкВАр/мкВА
  
    Ми хочемо тримати число у мВт/мВАр/мВА. 
  
    Тоді треба поділити ще на 1000
    */
  
    //Активна потужність
    double P_float = ((double)P_adc_x16) * ((double)(MNOGNYK_I_DIJUCHE_DOUBLE*MNOGNYK_U_DIJUCHE_DOUBLE/(1000.0*16.0*16.0)));
    int P_tmp = (int)(P_float); // з точністю до мВт

    //Реактивна потужність
    double Q_float = ((double)Q_adc_x16) * ((double)(MNOGNYK_I_DIJUCHE_DOUBLE*MNOGNYK_U_DIJUCHE_DOUBLE/(1000.0*16.0*16.0)));
    int Q_tmp  = (int)(Q_float); // з точністю до мВАр

    int (*energy_array)[2];
  
    //Активна потужність
    if (P_tmp >= 0) energy_array = P_plus;
    else energy_array = P_minus;
    *(energy_array + bank_for_enegry_tmp)[line] += abs(P_tmp);
  
    //Реактивна потужність
    if     ((Q_tmp >= 0) && (P_tmp >= 0)) energy_array = Q_1q;
    else if((Q_tmp >= 0) && (P_tmp <  0)) energy_array = Q_2q;
    else if((Q_tmp <  0) && (P_tmp <  0)) energy_array = Q_3q;
    else                                  energy_array = Q_4q;
    *(energy_array + bank_for_enegry_tmp)[line] += abs(Q_tmp);
  }
  
  if (++lichylnyk_1s_po_20ms >= MAIN_FREQUENCY)
  {
    if (lichylnyk_1s_po_20ms > MAIN_FREQUENCY)
    {
      //Теоретично цього ніколи не мало б бути
      total_error_sw_fixed(64);
    }

    //Переключаємо банк для збереження нових даних s обнулюємо значення у новому банку
    bank_for_enegry = bank_for_enegry_tmp = (bank_for_enegry_tmp + 1) & 0x1;
    for (size_t line = 0; line < 2; ++line)
    {
      P_plus[bank_for_enegry_tmp][line] = 0;
      P_minus[bank_for_enegry_tmp][line] = 0;
      Q_1q[bank_for_enegry_tmp][line] = 0;
      Q_2q[bank_for_enegry_tmp][line] = 0;
      Q_3q[bank_for_enegry_tmp][line] = 0;
      Q_4q[bank_for_enegry_tmp][line] = 0;
    }
    
    lichylnyk_1s_po_20ms = 0;
    if (periodical_tasks_CALC_ENERGY_DATA == 0)
    {
      //Скидаємо повідомлення у слові діагностики
      _SET_BIT(clear_diagnostyka, LOSE_ENERGY_DATA);
    }
    else
    {
      //Виствляємо повідомлення у слові діагностики
      _SET_BIT(set_diagnostyka, LOSE_ENERGY_DATA);
    }
    periodical_tasks_CALC_ENERGY_DATA = true;
  }
  
}
/*****************************************************/

/*****************************************************/
//Розрахунки віимірювань
/*****************************************************/
inline void calc_measurement(unsigned int number_group_stp)
{
  int ortogonal_local[2*(NUMBER_ANALOG_CANALES + 2)];

  //Виставляємо семафор заборони обновлення значень з вимірювальної системи
//  semaphore_measure_values = 1;

  //Копіюємо вхідні велечини у локальні змінні
  /*
  оскільки для дискретного перетворення Фурє коефіцієнти діляться на число виборок і множиться на 2 (еквівалент 2/Т),
  то це ми можемо зробити зміщенням
  */
  /*
  Проведені мною розрахунки показують, що якщо просумувати добуток миттєвих значень на синус/косинус за період,
  а потім результат поділити на 2/Т (зробити це відповідним зсуваом, про який я писав вище),
  то максимана розрядність резутьтату буде рівна макисальній розрядності вхідного сигналу
  Тобто для 3I0            - це 19 біт + знак = ((11 біт + знак)*16*16)
        для фазних струмів - це 15 біт + знак = ((11 біт + знак)*16   )
  оскільки нам ще треба це число піднімати до квадрату а аж потім добувати корінь квадратний з суми квадратів, то
  фазний струм можна підносити до кваррату - переповнення не буде, бо (15 біт *2) = 30 біт Бо 32 біт unsigned int
  А аж потім забрати множенння на 16, щоб збільшити точність вимірювання
  
  Для 3I0 можливе переповнення - тому треба або:
  1.  
  Перше 16-кратне підсилення забрати прямо з ортогональних для 3I0,
  тоді ортогоанльні стануть не більше 15-розрядного числа + знак.
  Друге 16-кратне підсилення забрати вже в остаточному результаті
    
  2.Використати 64-бітну арифметику.
    
  До 17 листопада 2014 року використовуввся перший метод.
  Але виникала похибка при розрахунку стуму вищих гармонік. Припускаю, що могло бути
  зв'язане з тим, що коли відкидадися молодші розряди - то струм першої гармоніки ставав
  трохи меншим за ремальне значення - а тоді виростав струм вищих гармонік
    
  Тому пробую використати другий метод з 17 листопада 2014 року  
  
  Для покращення точності з 18 листопада 2014 року я забираю амплітуду sin/cos вже
  перед самими розрахунками
  */
  
  unsigned int bank_ortogonal_tmp = (bank_ortogonal + 1) & 0x1;
  for(unsigned int i=0; i<(2*(NUMBER_ANALOG_CANALES + 2)); i++ )
  {
    ortogonal_local[i] = ortogonal[i][bank_ortogonal_tmp];
  }
  bank_ortogonal = bank_ortogonal_tmp;
  
  //Знімаємо семафор заборони обновлення значень з вимірювальної системи
//  semaphore_measure_values = 0;
  
  /*******************************************************/
  //Перевіряємо, чи відбувалися зміни юстування
  /*******************************************************/
  if (changed_ustuvannja == CHANGED_ETAP_ENDED_EXTRA_ETAP) /*Це є умова, що нові дані підготовлені для передачі їх у роботу системою захистів(і при цьому зараз дані не змінюються)*/
  {
    //Копіюємо масив юстування у копію цього масиву але з яким працює (читає і змінює) тільки вимірювальна захистема
    for(unsigned int i = 0; i < NUMBER_ANALOG_CANALES; i++) 
    {
      phi_ustuvannja_meas[i] = phi_ustuvannja[i];
      phi_ustuvannja_sin_cos_meas[2*i    ] = phi_ustuvannja_sin_cos[2*i    ];
      phi_ustuvannja_sin_cos_meas[2*i + 1] = phi_ustuvannja_sin_cos[2*i + 1];
    }
      
    //Помічаємо, що зміни прийняті системою захистів
    changed_ustuvannja = CHANGED_ETAP_NONE;
  }
  /*****************************************************/

  /***
  Довертаємо кути і копіюємо ортогональні для низькопріоритетних задач
  ***/
  const unsigned int index_input_arr[NUMBER_ANALOG_CANALES]  = {I_Imn, I_Ibp + 1, FULL_ORT_Umn  + 2, FULL_ORT_Ubp + 2};
  for (unsigned int i = 0; i < NUMBER_ANALOG_CANALES; i++)
  {
    size_t index_input = index_input_arr[i];
    float sin_alpha = ((float)ortogonal_local[2*index_input    ])/((float)((1 << (VAGA_NUMBER_POINT - 1))));
    float cos_alpha = ((float)ortogonal_local[2*index_input + 1])/((float)((1 << (VAGA_NUMBER_POINT - 1))));
    
    float sin_beta =  phi_ustuvannja_sin_cos_meas[2*i    ];
    float cos_beta =  phi_ustuvannja_sin_cos_meas[2*i + 1];
    
    unsigned int new_index = index_converter[i];
    ortogonal_calc[2*new_index    ] = (int)(sin_alpha*cos_beta + cos_alpha*sin_beta);
    ortogonal_calc[2*new_index + 1] = (int)(cos_alpha*cos_beta - sin_alpha*sin_beta);
  }
  
  const unsigned int index_input_other_arr[2] = {I_Imn + 1, I_Ibp + 2};
  for (size_t i = NUMBER_ANALOG_CANALES; i < (NUMBER_ANALOG_CANALES + 2); i++)
  {
    size_t index_input = index_input_other_arr[i - NUMBER_ANALOG_CANALES];
    size_t new_index = index_converter[i];
    ortogonal_calc[2*new_index    ] = ortogonal_local[2*index_input    ] >> (VAGA_NUMBER_POINT - 1);
    ortogonal_calc[2*new_index + 1] = ortogonal_local[2*index_input + 1] >> (VAGA_NUMBER_POINT - 1);
  }


  /***
  Копіюємо ортогональні для низькопріоритетних задач
  ***/
  if (semaphore_measure_values_low == 0)
  {
    for (size_t i = 0; i < (2*FULL_ORT_MAX_TOTAL); i++) ortogonal_calc_low[i] = ortogonal_calc[i];
  }   
/***/
  
  
  /*
  ---------------------------------------------------------------------------------------------------------
  150А (150 000мА) - максимальний фазний струм
  Коефіцієнст переведення в мА  - Koef_1 = 84,978173543997808495193432804655 для фазних струмів (5439/64 = 84,984375)
  
  Тоді для 150А максимально можливе значення ортогональних може бути
  150000/Koef_1 = 1765,0303364589078874793160507446
  Якщо врахувати, що сигнал є підсиленим у 16 раз, то максимальне значення ортогональних може бути
  16*150000/Koef_1 = 28240,485383342526199669056811914 < 28241(0x6E51) це є 15 бітне число (+ можливий знак)
  ---------------------------------------------------------------------------------------------------------

  ---------------------------------------------------------------------------------------------------------
  150В (150 000мВ) - максимальна фазна напруга
  Коефіцієнст переведення в мВ  - Koef_1 = 64,883134509545420915167731259667 для фазних напруг (4152/64 = 64,875)
  
  Тоді для 150В максимально можливе значення ортогональних може бути
  150000/Koef_1 = 2311,848851536795430557291797995
  Якщо врахувати, що сигнал є підсиленим у 16 раз, то максимальне значення ортогональних може бути
  16*150000/Koef_1 = 36989,581624588726888916668767919 < 36990(0x907E) це є 16 бітне число (+ можливий знак) - тобто число виходить 17-бітне
  
  Якщо з фазної напруги розраховується лінійна напруга, то, якзо припустити що вектори розврнуті у різні сторони, то  максимальне
  значення ортогональних може бути
  2*16*150000/Koef_1 = 73979,163249177453777833337535838 < 73980(0x120FC) це є 17 бітне число (+ можливий знак) - тобто число виходить 18-бітне
  ---------------------------------------------------------------------------------------------------------
  */
  
  /***/
  //Розраховуємо діюче значення через перетворення Фур'є
  /***/
  for(size_t i = 0; i < _NUMBER_IM; i++)
  {
    if ((i <= IM_Ibp) || (i >= IM_3Imn))
    {
      unsigned int index_ort;
      switch (i)
      {
      case IM_Imn:
        {
          index_ort = FULL_ORT_Imn;
          break;
        }
      case IM_Ibp:
        {
          index_ort = FULL_ORT_Ibp;
          break;
        }
      case IM_3Imn:
        {
          index_ort = FULL_ORT_3Imn;
          break;
        }
      case IM_3Ibp:
        {
          index_ort = FULL_ORT_3Ibp;
          break;
        }
      default:
        {
          //Теоретично цього ніколи не мало б бути
          total_error_sw_fixed(66);
        }
      }
      
      measurement[i] = ( MNOGNYK_I_DIJUCHE*(sqrt_32((unsigned int)(ortogonal_calc[2*index_ort]*ortogonal_calc[2*index_ort]) + (unsigned int)(ortogonal_calc[2*index_ort+1]*ortogonal_calc[2*index_ort+1]))) ) >> (VAGA_DILENNJA_I_DIJUCHE + 4);
    }
    else
    {
      unsigned int index_ort;
      switch (i)
      {
      case IM_Umn:
        {
          index_ort = FULL_ORT_Umn;
          break;
        }
      case IM_Ubp:
        {
          index_ort = FULL_ORT_Ubp;
          break;
        }
      default:
        {
          //Теоретично цього ніколи не мало б бути
          total_error_sw_fixed(67);
        }
      }
      
      measurement[i] = ( MNOGNYK_U_DIJUCHE*(sqrt_32((unsigned int)(ortogonal_calc[2*index_ort]*ortogonal_calc[2*index_ort]) + (unsigned int)(ortogonal_calc[2*index_ort+1]*ortogonal_calc[2*index_ort+1]))) ) >> (VAGA_DILENNJA_U_DIJUCHE + 4);
    }
    
  }
  /***/

  /***/
  //Фазочутливий елемент для ДЗ (всіх ступенів)
  /***/
  directional_dz(ortogonal_calc, number_group_stp);
  /***/

  /***/
  //Фазочутливий елемент для МТЗ (всіх ступенів)
  /***/
  directional_mtz(ortogonal_calc, number_group_stp);
  /***/

  /***/
  //Розраховуємо опори
  /***/
  calc_resistance(ortogonal_calc, resistance);
  /***/

  if(++number_inputs_for_fix_one_period >= 20)
  {
    /***/
    //Розрахунок миттєвих потужностей (раз на 20мс)
    /***/
    calc_power(ortogonal_calc);
    /***/
    
    number_inputs_for_fix_one_period = 0;
  }
}
/*****************************************************/

/*****************************************************/
//Модуль обробки дискретних входів
/*****************************************************/
inline void input_scan(void)
{
  unsigned int state_inputs_into_pin = 0; //Змінні у якій формуємо значення входів отримані із входів процесора (пінів)
  static unsigned int state_inputs_into_pin_trigger; //У цій змінній зберігається попередній стан піна, у випадку коли ми перевіряємо .чи утримається цей стан до кінця тактування таймера допуску

  /***************************/
  //У цій частині знімаємо стани входів процесора (пінів), які відповідають за дискретні входи
  /*
  -----------------------------
  значення поміщається у відпорвідні біти змінної state_inputs_into_pin
    "є     сигнал " - відповідає встановленому біту (1)
    "немає сигналу" - відповідає скинутому     біту (0)
  -----------------------------
  */
  state_inputs_into_pin |=  ( _DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD33_DD36)       & 0xffff)
#if (MODYFIKACIA_VERSII_PZ == 0)
                         | (((_DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD26_DD29) >> 8) &    0xf) << 16)
#endif
                        ;
  /***************************/
  
  /***************************/
  //Обробка таймерів допуску дискретних входів
  /***************************/
  for(unsigned int i = 0; i < NUMBER_INPUTS; i++)
  {
    unsigned int maska = 1<<i;
    int max_value_timer = current_settings_prt.dopusk_dv[i];

    if (global_timers[INDEX_TIMER_INPUT_START + i] < 0)
    {
      //Провірка на зміну стану дискретного входу здійснюється тільки тоді, коли величина таймере є від'ємною
      //Що означає що таймер не запущений у попередній момент
      
      //Перевіряємо чи таеперішній стан входу відповідає попердньомук стану
      if ((state_inputs_into_pin & maska) != (state_inputs & maska))
      {
        //Якщо стан входу змінився, то виконуємо дії по зміні стану

        //1-дія: Запям'ятовуємо текучий стан входу
        state_inputs_into_pin_trigger &= ~maska;
        state_inputs_into_pin_trigger |= (state_inputs_into_pin & maska);

        //2-дія: Запускаємо таймер допуску дискретного входу
        global_timers[INDEX_TIMER_INPUT_START + i] = 0;
      }
    }
    else
    {
      //Якщо таймер запущений виконуємо дії з таймером
      if (global_timers[INDEX_TIMER_INPUT_START + i] < max_value_timer)
      {
        //Якщо таймер ще не дійшов до свого макисмуму, то просто збільшуємо його величину
        global_timers[INDEX_TIMER_INPUT_START + i] += DELTA_TIME_FOR_TIMERS;
        
        //У випадку, якщо тип сигналу на вхід подається змінний
        //і ми перевіряємо чи не відбувся перехід "є сигнал"->"немає сигналу"
        //то поява сигналу під час тактування таймера допуску означає, що сигнал на вході є - 
        //а це означає, що треба зупинити nаймер, бо переходу "є сигнал"->"немає сигналу" на протязі тактування таймеру не зафіксовано 
        if ((current_settings_prt.type_of_input_signal & maska) != 0)
        {
           if ((state_inputs_into_pin_trigger & maska) == 0)
           {
             if ((state_inputs_into_pin & maska) != 0)
               global_timers[INDEX_TIMER_INPUT_START + i] = -1;
           }
        }
      }
    }
    
    //Якщо величина таймера допуска знаходиться у свому максимальному значенні, то перевіряємо, чи фактично змінився стано входу
    if (global_timers[INDEX_TIMER_INPUT_START + i] >= max_value_timer)
    {
      //Перевіряємо, чи стан піна змінився у порівнянні із станом, який був на момент запуску таймера допуску дискретного входу
      unsigned int state_1, state_2;
        
      state_1 = state_inputs_into_pin_trigger & maska;
      state_2 = state_inputs_into_pin  & maska;
        
      if (state_1 == state_2)
      {
        //Якщо два стани співпадають, то ми вважаємо, що відбулася зіна стану дискретного входу і формуємо новий стан входу
        //При цьому враховуємо що для прявого    входу 1 - це активний вхід, а 0 - це пасивний вхід
        //                        для інверсного входу 0 - це активний вхід, а 1 - це пасивний вхід
          state_inputs &=  ~maska;
          state_inputs |=   state_2;
      }
        
      //У будь-якому випадк, чи змінився стан входу, чи ні, а оскілька таймер допуску дотактував до кінця, то скидаємотаймер у висхідне від'ємне занчення
      global_timers[INDEX_TIMER_INPUT_START + i] = -1;
    }
  }
  /***************************/
  
  /***************************/
  //Визначаємо, який сигнал є зараз активним
  /***************************/
  active_inputs = (state_inputs ^ current_settings_prt.type_of_input);
  /***************************/
  
}
/*****************************************************/

/*****************************************************/
//Функція обробки таймерів
/*****************************************************/
inline void clocking_global_timers(void)
{
  //Опрацьовуємо дискретні входи
  input_scan();
  
  //опрацьовуємо всі решта таймери логіки
  for (unsigned int i = (INDEX_TIMER_INPUT_START + NUMBER_INPUTS); i < MAX_NUMBER_GLOBAL_TIMERS; i++)
  {
    if (global_timers[i] >= 0)
    {
      //Першою умовою того, що таймер треба тактувати є той факт, що величина таймеру не від'ємна

      //Перевіряємо чи треба збільшувати величину таймеру, якщо він ще не досягнув свого максимуму
      if (global_timers[i] <= (0x7fffffff - DELTA_TIME_FOR_TIMERS)) global_timers[i] += DELTA_TIME_FOR_TIMERS;
    }
  }
  
  if (++timer_prt_signal_output_mode_2 >= PERIOD_SIGNAL_OUTPUT_MODE_2)
  {
    timer_prt_signal_output_mode_2 = 0;
    output_timer_prt_signal_output_mode_2 ^= true;
  }
}
/*****************************************************/

/*****************************************************/
//Опрацювання Ориділювальних функцій - має запускатися після відкрпацювання блоків всіх захистів
/*****************************************************/
inline void df_handler(unsigned int *p_active_functions)
{
  unsigned int logic_df[NUMBER_DEFINED_FUNCTIONS];
  
  //Визначаємо, чи активовуються опреділювані функції через свої ранжовані функції-джерела
  for (unsigned int i = 0; i < NUMBER_DEFINED_FUNCTIONS; i++)
  {
    unsigned int *p_logic_df = (logic_df + i);
    *p_logic_df = 0;
    
    unsigned int number_byte_in, number_bit_in;
    switch (i)
    {
    case 0:
      {
        number_byte_in = RNG_BIG_DF1_IN >> 5;
        number_bit_in = RNG_BIG_DF1_IN & 0x1f;

        break;
      }
    case 1:
      {
        number_byte_in = RNG_BIG_DF2_IN >> 5;
        number_bit_in = RNG_BIG_DF2_IN & 0x1f;

        break;
      }
    case 2:
      {
        number_byte_in = RNG_BIG_DF3_IN >> 5;
        number_bit_in = RNG_BIG_DF3_IN & 0x1f;
        
        break;
      }
    case 3:
      {
        number_byte_in = RNG_BIG_DF4_IN >> 5;
        number_bit_in = RNG_BIG_DF4_IN & 0x1f;

        break;
      }
    case 4:
      {
        number_byte_in = RNG_BIG_DF5_IN >> 5;
        number_bit_in = RNG_BIG_DF5_IN & 0x1f;

        break;
      }
    case 5:
      {
        number_byte_in = RNG_BIG_DF6_IN >> 5;
        number_bit_in = RNG_BIG_DF6_IN & 0x1f;

        break;
      }
    case 6:
      {
        number_byte_in = RNG_BIG_DF7_IN >> 5;
        number_bit_in = RNG_BIG_DF7_IN & 0x1f;

        break;
      }
    case 7:
      {
        number_byte_in = RNG_BIG_DF8_IN >> 5;
        number_bit_in = RNG_BIG_DF8_IN & 0x1f;

        break;
      }
    case 8:
      {
        number_byte_in = RNG_BIG_DF9_IN >> 5;
        number_bit_in = RNG_BIG_DF9_IN & 0x1f;

        break;
      }
    case 9:
      {
        number_byte_in = RNG_BIG_DF10_IN >> 5;
        number_bit_in = RNG_BIG_DF10_IN & 0x1f;

        break;
      }
    case 10:
      {
        number_byte_in = RNG_BIG_DF11_IN >> 5;
        number_bit_in = RNG_BIG_DF11_IN & 0x1f;

        break;
      }
    case 11:
      {
        number_byte_in = RNG_BIG_DF12_IN >> 5;
        number_bit_in = RNG_BIG_DF12_IN & 0x1f;

        break;
      }
    case 12:
      {
        number_byte_in = RNG_BIG_DF13_IN >> 5;
        number_bit_in = RNG_BIG_DF13_IN & 0x1f;

        break;
      }
    case 13:
      {
        number_byte_in = RNG_BIG_DF14_IN >> 5;
        number_bit_in = RNG_BIG_DF14_IN & 0x1f;

        break;
      }
    case 14:
      {
        number_byte_in = RNG_BIG_DF15_IN >> 5;
        number_bit_in = RNG_BIG_DF15_IN & 0x1f;

        break;
      }
    case 15:
      {
        number_byte_in = RNG_BIG_DF16_IN >> 5;
        number_bit_in = RNG_BIG_DF16_IN & 0x1f;

        break;
      }
    default:
      {
        //Теоретично цього ніколи не мало б бути
        total_error_sw_fixed(43);
        break;
      }
    }

    /***
    Джерело активації ОФ-ії
    ***/
    *p_logic_df |= ((p_active_functions[number_byte_in] & (1 << number_bit_in) ) >> number_bit_in ) << 0;
    //Перевіряємо ще, чи не іде утимування активним джерела ОФ через таймер-утримування (для активації через кнопки або інтерфейс)
    if (global_timers[INDEX_TIMER_DF_PROLONG_SET_FOR_BUTTON_INTERFACE_START + i] >= 0)
    {
      //Таймер запущений, або вже зупинився
      //Факт запуску цього таймеру означає, що активація відбувалася через кнопку, або інтерфейс
      //Тому для забеспечення роботи логічної схеми до кінця роботи цього таймеру виставляємо, що джерело активації активне
      *p_logic_df |= (1 << 0);
      
      //Відмічаємо, джерело активації утримуємться у активному стані у масиві активуючих функцій
      p_active_functions[number_byte_in] |= (1 << number_bit_in);
      
      //У випадку, якщо таймер дійшов до свого макисального значення, то скидаємо роботу цього таймеру
      if (global_timers[INDEX_TIMER_DF_PROLONG_SET_FOR_BUTTON_INTERFACE_START + i] >= ((int)current_settings_prt.timeout_pause_df[i]))
        global_timers[INDEX_TIMER_DF_PROLONG_SET_FOR_BUTTON_INTERFACE_START + i] = -1;
    }
    /***/

    if(
       ( ( current_settings_prt.ranguvannja_df_source_plus[N_BIG*i     ] & p_active_functions[0] ) != 0) ||
       ( ( current_settings_prt.ranguvannja_df_source_plus[N_BIG*i +  1] & p_active_functions[1] ) != 0) ||
       ( ( current_settings_prt.ranguvannja_df_source_plus[N_BIG*i +  2] & p_active_functions[2] ) != 0) ||
       ( ( current_settings_prt.ranguvannja_df_source_plus[N_BIG*i +  3] & p_active_functions[3] ) != 0) ||
       ( ( current_settings_prt.ranguvannja_df_source_plus[N_BIG*i +  4] & p_active_functions[4] ) != 0) ||
       ( ( current_settings_prt.ranguvannja_df_source_plus[N_BIG*i +  5] & p_active_functions[5] ) != 0) ||
       ( ( current_settings_prt.ranguvannja_df_source_plus[N_BIG*i +  6] & p_active_functions[6] ) != 0) ||
       ( ( current_settings_prt.ranguvannja_df_source_plus[N_BIG*i +  7] & p_active_functions[7] ) != 0) ||
       ( ( current_settings_prt.ranguvannja_df_source_plus[N_BIG*i +  8] & p_active_functions[8] ) != 0) ||
       ( ( current_settings_prt.ranguvannja_df_source_plus[N_BIG*i +  9] & p_active_functions[9] ) != 0) ||
       ( ( current_settings_prt.ranguvannja_df_source_plus[N_BIG*i + 10] & p_active_functions[10]) != 0) ||
       ( ( current_settings_prt.ranguvannja_df_source_plus[N_BIG*i + 11] & p_active_functions[11]) != 0) ||
       ( ( current_settings_prt.ranguvannja_df_source_plus[N_BIG*i + 12] & p_active_functions[12]) != 0) 
      )
    {
      *p_logic_df |= (1 << 0);
    }

    if(
       ( ( current_settings_prt.ranguvannja_df_source_minus[N_BIG*i     ] & ((unsigned int)(~p_active_functions[0] )) ) != 0 )||
       ( ( current_settings_prt.ranguvannja_df_source_minus[N_BIG*i +  1] & ((unsigned int)(~p_active_functions[1] )) ) != 0 )||
       ( ( current_settings_prt.ranguvannja_df_source_minus[N_BIG*i +  2] & ((unsigned int)(~p_active_functions[2] )) ) != 0 )||
       ( ( current_settings_prt.ranguvannja_df_source_minus[N_BIG*i +  3] & ((unsigned int)(~p_active_functions[3] )) ) != 0 )||
       ( ( current_settings_prt.ranguvannja_df_source_minus[N_BIG*i +  4] & ((unsigned int)(~p_active_functions[4] )) ) != 0 )||
       ( ( current_settings_prt.ranguvannja_df_source_minus[N_BIG*i +  5] & ((unsigned int)(~p_active_functions[5] )) ) != 0 )||
       ( ( current_settings_prt.ranguvannja_df_source_minus[N_BIG*i +  6] & ((unsigned int)(~p_active_functions[6] )) ) != 0 )||
       ( ( current_settings_prt.ranguvannja_df_source_minus[N_BIG*i +  7] & ((unsigned int)(~p_active_functions[7] )) ) != 0 )||
       ( ( current_settings_prt.ranguvannja_df_source_minus[N_BIG*i +  8] & ((unsigned int)(~p_active_functions[8] )) ) != 0 )||
       ( ( current_settings_prt.ranguvannja_df_source_minus[N_BIG*i +  9] & ((unsigned int)(~p_active_functions[9] )) ) != 0 )||
       ( ( current_settings_prt.ranguvannja_df_source_minus[N_BIG*i + 10] & ((unsigned int)(~p_active_functions[10])) ) != 0 )||
       ( ( current_settings_prt.ranguvannja_df_source_minus[N_BIG*i + 11] & ((unsigned int)(~p_active_functions[11])) ) != 0 )||
       ( ( current_settings_prt.ranguvannja_df_source_minus[N_BIG*i + 12] & ((unsigned int)(~p_active_functions[12])) ) != 0 )
      )
    {
      *p_logic_df |= (1 << 0);
    }

    if(
       ( ( current_settings_prt.ranguvannja_df_source_blk[N_BIG*i     ] & p_active_functions[0 ] ) == 0 ) &&
       ( ( current_settings_prt.ranguvannja_df_source_blk[N_BIG*i + 1 ] & p_active_functions[1 ] ) == 0 ) &&
       ( ( current_settings_prt.ranguvannja_df_source_blk[N_BIG*i + 2 ] & p_active_functions[2 ] ) == 0 ) &&
       ( ( current_settings_prt.ranguvannja_df_source_blk[N_BIG*i + 3 ] & p_active_functions[3 ] ) == 0 ) &&
       ( ( current_settings_prt.ranguvannja_df_source_blk[N_BIG*i + 4 ] & p_active_functions[4 ] ) == 0 ) &&
       ( ( current_settings_prt.ranguvannja_df_source_blk[N_BIG*i + 5 ] & p_active_functions[5 ] ) == 0 ) &&
       ( ( current_settings_prt.ranguvannja_df_source_blk[N_BIG*i + 6 ] & p_active_functions[6 ] ) == 0 ) &&
       ( ( current_settings_prt.ranguvannja_df_source_blk[N_BIG*i + 7 ] & p_active_functions[7 ] ) == 0 ) &&
       ( ( current_settings_prt.ranguvannja_df_source_blk[N_BIG*i + 8 ] & p_active_functions[8 ] ) == 0 ) &&
       ( ( current_settings_prt.ranguvannja_df_source_blk[N_BIG*i + 9 ] & p_active_functions[9 ] ) == 0 ) &&
       ( ( current_settings_prt.ranguvannja_df_source_blk[N_BIG*i + 10] & p_active_functions[10] ) == 0 ) &&
       ( ( current_settings_prt.ranguvannja_df_source_blk[N_BIG*i + 11] & p_active_functions[11] ) == 0 ) &&
       ( ( current_settings_prt.ranguvannja_df_source_blk[N_BIG*i + 12] & p_active_functions[12] ) == 0 )
      )
    {
      *p_logic_df |= (1 << 1);
    }
    
    /***
    Виконуємо у цьому місці обробку логіки без встанвлення/скидання бітів про стан Визначуваної функції
    Щоб новий стан попередньої функції не був включений у стан наступної
    ***/
    _TIMER_T_0(INDEX_TIMER_DF_PAUSE_START + i, current_settings_prt.timeout_pause_df[i], (*p_logic_df), 0, (*p_logic_df), 2);
    
    if ((current_settings_prt.type_df & (1 << i)) == 0)
    {
      _TIMER_IMPULSE(INDEX_TIMER_DF_WORK_START + i, current_settings_prt.timeout_work_df[i], static_logic_df, i, (*p_logic_df), 2, (*p_logic_df), 3);
    }
    else
    {
      _TIMER_0_T    (INDEX_TIMER_DF_WORK_START + i, current_settings_prt.timeout_work_df[i],                     (*p_logic_df), 2, (*p_logic_df), 3);
      static_logic_df &= ~(1u << i);
    }
      
    _AND2((*p_logic_df), 3, (*p_logic_df), 1, (*p_logic_df), 4);
    /***/

    
  }
  
  //Установлюємо, або скидаємо ОФ у масиві функцій, які зараз будуть активовуватися
  /*
  Цей цикл і попередній не об'єднаі в один, а навпаки розєднані, бо у першому ми використовуємо
  масив p_active_functions у якому ще не встановлені виходи ОФ-ій, тому що інші ОФ-ії
  можуть бути джерелом активації, але джерелом активації може буте попереднє значення ОФ, а не те,
  що зараз встановлюється. А оскілдьки у другому масиві ми встановлюємо значення у масиві
  p_active_functions, які набувають зараз тільки ваги, то щоб не вийшло об'єднання попереднього значення
  і теперішнього то цикли роз'єднані (цикл аналізу джерел і логіки з циклом активації/деактивації)
  */
  for (unsigned int i = 0; i < NUMBER_DEFINED_FUNCTIONS; i++)
  {
    //Установлюємо, або скидаємо ОФ
    unsigned int index_df;
    switch (i)
    {
    case 0:
      {
       index_df = RNG_BIG_DF1_OUT;
        break;
      }
    case 1:
      {
        index_df = RNG_BIG_DF2_OUT;
        break;
      }
    case 2:
      {
        index_df = RNG_BIG_DF3_OUT;
        break;
      }
    case 3:
      {
        index_df = RNG_BIG_DF4_OUT;
        break;
      }
    case 4:
      {
        index_df = RNG_BIG_DF5_OUT;
        break;
      }
    case 5:
      {
        index_df = RNG_BIG_DF6_OUT;
        break;
      }
    case 6:
      {
        index_df = RNG_BIG_DF7_OUT;
        break;
      }
    case 7:
      {
        index_df = RNG_BIG_DF8_OUT;
        break;
      }
    case 8:
      {
        index_df = RNG_BIG_DF9_OUT;
        break;
      }
    case 9:
      {
        index_df = RNG_BIG_DF10_OUT;
        break;
      }
    case 10:
      {
        index_df = RNG_BIG_DF11_OUT;
        break;
      }
    case 11:
      {
        index_df = RNG_BIG_DF12_OUT;
        break;
      }
    case 12:
      {
        index_df = RNG_BIG_DF13_OUT;
        break;
      }
    case 13:
      {
        index_df = RNG_BIG_DF14_OUT;
        break;
      }
    case 14:
      {
        index_df = RNG_BIG_DF15_OUT;
        break;
      }
    case 15:
      {
        index_df = RNG_BIG_DF16_OUT;
        break;
      }
    default:
      {
        //Теоретично цього ніколи не мало б бути
        total_error_sw_fixed(44);
        break;
      }
    }
      
    if ((logic_df[i] & (1 << 4)) != 0 ) _SET_BIT(p_active_functions, index_df);
    else _CLEAR_BIT(p_active_functions, index_df);
  }
}
/*****************************************************/

/*****************************************************/
//Опрацювання Ориділювальних триґерів - має запускатися після відкрпацювання опреділювальних функцій
/*****************************************************/
inline void dt_handler(unsigned int *p_active_functions)
{
  /*
  Попередній стан визначуваних триґерів формуємо у state_defined_triggers
  Джерела встановлення формуємо в source_set_dt
  Джерела скидання формуємо в source_reset_dt
  */
  unsigned int state_defined_triggers = 0, source_set_dt = 0, source_reset_dt = 0;
  for (unsigned int i = 0; i < NUMBER_DEFINED_TRIGGERS/*current_settings_prt.number_defined_dt*/; i++)
  {
    unsigned int number_byte_set, number_bit_set, number_byte_reset, number_bit_reset;
    unsigned int index_dt;
    switch (i)
    {
    case 0:
      {
        number_byte_set = RNG_BIG_DT1_SET >> 5;
        number_bit_set = RNG_BIG_DT1_SET & 0x1f;

        number_byte_reset = RNG_BIG_DT1_RESET >> 5;
        number_bit_reset = RNG_BIG_DT1_RESET & 0x1f;
        
        index_dt = RNG_BIG_DT1_OUT;
        
        break;
      }
    case 1:
      {
        number_byte_set = RNG_BIG_DT2_SET >> 5;
        number_bit_set = RNG_BIG_DT2_SET & 0x1f;

        number_byte_reset = RNG_BIG_DT2_RESET >> 5;
        number_bit_reset = RNG_BIG_DT2_RESET & 0x1f;
        
        index_dt = RNG_BIG_DT2_OUT;
        
        break;
      }
    case 2:
      {
        number_byte_set = RNG_BIG_DT3_SET >> 5;
        number_bit_set = RNG_BIG_DT3_SET & 0x1f;

        number_byte_reset = RNG_BIG_DT3_RESET >> 5;
        number_bit_reset = RNG_BIG_DT3_RESET & 0x1f;
        
        index_dt = RNG_BIG_DT3_OUT;
        
        break;
      }
    case 3:
      {
        number_byte_set = RNG_BIG_DT4_SET >> 5;
        number_bit_set = RNG_BIG_DT4_SET & 0x1f;

        number_byte_reset = RNG_BIG_DT4_RESET >> 5;
        number_bit_reset = RNG_BIG_DT4_RESET & 0x1f;
        
        index_dt = RNG_BIG_DT4_OUT;
        
        break;
      }
    default:
      {
        //Теоретично цього ніколи не мало б бути
        total_error_sw_fixed(55);
        break;
      }
    }

    state_defined_triggers |= ( (p_active_functions[index_dt >> 5] & ( 1 << (index_dt & 0x1f) ) ) >> (index_dt & 0x1f) ) << i;
    /***
    Джерела встановлення і скидання ОТ
    ***/
    source_set_dt   |= ((p_active_functions[number_byte_set  ] & (1 << number_bit_set  ) ) >> number_bit_set   ) << i;
    source_reset_dt |= ((p_active_functions[number_byte_reset] & (1 << number_bit_reset) ) >> number_bit_reset ) << i;
    /***/
  }
  
  //Визначаємо, чи встановлюються/скидаються опреділювані триґери через свої ранжовані функції-джерела
  for (unsigned int i = 0; i < NUMBER_DEFINED_TRIGGERS/*current_settings_prt.number_defined_dt*/; i++)
  {
    if (
        (current_settings_prt.ranguvannja_set_dt_source_plus[N_BIG*i     ] !=0) || 
        (current_settings_prt.ranguvannja_set_dt_source_plus[N_BIG*i + 1 ] !=0) ||
        (current_settings_prt.ranguvannja_set_dt_source_plus[N_BIG*i + 2 ] !=0) ||
        (current_settings_prt.ranguvannja_set_dt_source_plus[N_BIG*i + 3 ] !=0) ||
        (current_settings_prt.ranguvannja_set_dt_source_plus[N_BIG*i + 4 ] !=0) ||
        (current_settings_prt.ranguvannja_set_dt_source_plus[N_BIG*i + 5 ] !=0) ||
        (current_settings_prt.ranguvannja_set_dt_source_plus[N_BIG*i + 6 ] !=0) ||
        (current_settings_prt.ranguvannja_set_dt_source_plus[N_BIG*i + 7 ] !=0) ||
        (current_settings_prt.ranguvannja_set_dt_source_plus[N_BIG*i + 8 ] !=0) ||
        (current_settings_prt.ranguvannja_set_dt_source_plus[N_BIG*i + 9 ] !=0) ||
        (current_settings_prt.ranguvannja_set_dt_source_plus[N_BIG*i + 10] !=0) ||
        (current_settings_prt.ranguvannja_set_dt_source_plus[N_BIG*i + 11] !=0) ||
        (current_settings_prt.ranguvannja_set_dt_source_plus[N_BIG*i + 12] !=0)
       )
    {
      //Випадок, якщо функції зранжовані на джерело прямих функцій
      if(
         (( current_settings_prt.ranguvannja_set_dt_source_plus[N_BIG*i     ] & p_active_functions[0 ]) != 0) ||
         (( current_settings_prt.ranguvannja_set_dt_source_plus[N_BIG*i + 1 ] & p_active_functions[1 ]) != 0) ||
         (( current_settings_prt.ranguvannja_set_dt_source_plus[N_BIG*i + 2 ] & p_active_functions[2 ]) != 0) ||
         (( current_settings_prt.ranguvannja_set_dt_source_plus[N_BIG*i + 3 ] & p_active_functions[3 ]) != 0) ||
         (( current_settings_prt.ranguvannja_set_dt_source_plus[N_BIG*i + 4 ] & p_active_functions[4 ]) != 0) ||
         (( current_settings_prt.ranguvannja_set_dt_source_plus[N_BIG*i + 5 ] & p_active_functions[5 ]) != 0) ||
         (( current_settings_prt.ranguvannja_set_dt_source_plus[N_BIG*i + 6 ] & p_active_functions[6 ]) != 0) ||
         (( current_settings_prt.ranguvannja_set_dt_source_plus[N_BIG*i + 7 ] & p_active_functions[7 ]) != 0) ||
         (( current_settings_prt.ranguvannja_set_dt_source_plus[N_BIG*i + 8 ] & p_active_functions[8 ]) != 0) ||
         (( current_settings_prt.ranguvannja_set_dt_source_plus[N_BIG*i + 9 ] & p_active_functions[9 ]) != 0) ||
         (( current_settings_prt.ranguvannja_set_dt_source_plus[N_BIG*i + 10] & p_active_functions[10]) != 0) ||
         (( current_settings_prt.ranguvannja_set_dt_source_plus[N_BIG*i + 11] & p_active_functions[11]) != 0) ||
         (( current_settings_prt.ranguvannja_set_dt_source_plus[N_BIG*i + 12] & p_active_functions[12]) != 0)
        )
      {
        source_set_dt |= (1 << i);
      }
    }

    if (
        (current_settings_prt.ranguvannja_set_dt_source_minus[N_BIG*i     ] !=0) || 
        (current_settings_prt.ranguvannja_set_dt_source_minus[N_BIG*i + 1 ] !=0) ||
        (current_settings_prt.ranguvannja_set_dt_source_minus[N_BIG*i + 2 ] !=0) ||
        (current_settings_prt.ranguvannja_set_dt_source_minus[N_BIG*i + 3 ] !=0) ||
        (current_settings_prt.ranguvannja_set_dt_source_minus[N_BIG*i + 4 ] !=0) ||
        (current_settings_prt.ranguvannja_set_dt_source_minus[N_BIG*i + 5 ] !=0) ||
        (current_settings_prt.ranguvannja_set_dt_source_minus[N_BIG*i + 6 ] !=0) ||
        (current_settings_prt.ranguvannja_set_dt_source_minus[N_BIG*i + 7 ] !=0) ||
        (current_settings_prt.ranguvannja_set_dt_source_minus[N_BIG*i + 8 ] !=0) ||
        (current_settings_prt.ranguvannja_set_dt_source_minus[N_BIG*i + 9 ] !=0) ||
        (current_settings_prt.ranguvannja_set_dt_source_minus[N_BIG*i + 10] !=0) ||
        (current_settings_prt.ranguvannja_set_dt_source_minus[N_BIG*i + 11] !=0) ||
        (current_settings_prt.ranguvannja_set_dt_source_minus[N_BIG*i + 12] !=0)
       )
    {
      //Випадок, якщо функції зранжовані на джерело інверсних функцій
      if(
         ( ( current_settings_prt.ranguvannja_set_dt_source_minus[N_BIG*i     ] & ((unsigned int)(~p_active_functions[0 ])) ) != 0 ) ||
         ( ( current_settings_prt.ranguvannja_set_dt_source_minus[N_BIG*i + 1 ] & ((unsigned int)(~p_active_functions[1 ])) ) != 0 ) ||
         ( ( current_settings_prt.ranguvannja_set_dt_source_minus[N_BIG*i + 2 ] & ((unsigned int)(~p_active_functions[2 ])) ) != 0 ) ||
         ( ( current_settings_prt.ranguvannja_set_dt_source_minus[N_BIG*i + 3 ] & ((unsigned int)(~p_active_functions[3 ])) ) != 0 ) ||
         ( ( current_settings_prt.ranguvannja_set_dt_source_minus[N_BIG*i + 4 ] & ((unsigned int)(~p_active_functions[4 ])) ) != 0 ) ||
         ( ( current_settings_prt.ranguvannja_set_dt_source_minus[N_BIG*i + 5 ] & ((unsigned int)(~p_active_functions[5 ])) ) != 0 ) ||
         ( ( current_settings_prt.ranguvannja_set_dt_source_minus[N_BIG*i + 6 ] & ((unsigned int)(~p_active_functions[6 ])) ) != 0 ) ||
         ( ( current_settings_prt.ranguvannja_set_dt_source_minus[N_BIG*i + 7 ] & ((unsigned int)(~p_active_functions[7 ])) ) != 0 ) ||
         ( ( current_settings_prt.ranguvannja_set_dt_source_minus[N_BIG*i + 8 ] & ((unsigned int)(~p_active_functions[8 ])) ) != 0 ) ||
         ( ( current_settings_prt.ranguvannja_set_dt_source_minus[N_BIG*i + 9 ] & ((unsigned int)(~p_active_functions[9 ])) ) != 0 ) ||
         ( ( current_settings_prt.ranguvannja_set_dt_source_minus[N_BIG*i + 10] & ((unsigned int)(~p_active_functions[10])) ) != 0 ) ||
         ( ( current_settings_prt.ranguvannja_set_dt_source_minus[N_BIG*i + 11] & ((unsigned int)(~p_active_functions[11])) ) != 0 ) ||
         ( ( current_settings_prt.ranguvannja_set_dt_source_minus[N_BIG*i + 12] & ((unsigned int)(~p_active_functions[12])) ) != 0 )
        )
      {
        source_set_dt |= (1<< i);
      }
    }

    if (
        (current_settings_prt.ranguvannja_reset_dt_source_plus[N_BIG*i     ] !=0) || 
        (current_settings_prt.ranguvannja_reset_dt_source_plus[N_BIG*i + 1 ] !=0) ||
        (current_settings_prt.ranguvannja_reset_dt_source_plus[N_BIG*i + 2 ] !=0) ||
        (current_settings_prt.ranguvannja_reset_dt_source_plus[N_BIG*i + 3 ] !=0) ||
        (current_settings_prt.ranguvannja_reset_dt_source_plus[N_BIG*i + 4 ] !=0) ||
        (current_settings_prt.ranguvannja_reset_dt_source_plus[N_BIG*i + 5 ] !=0) ||
        (current_settings_prt.ranguvannja_reset_dt_source_plus[N_BIG*i + 6 ] !=0) ||
        (current_settings_prt.ranguvannja_reset_dt_source_plus[N_BIG*i + 7 ] !=0) ||
        (current_settings_prt.ranguvannja_reset_dt_source_plus[N_BIG*i + 8 ] !=0) ||
        (current_settings_prt.ranguvannja_reset_dt_source_plus[N_BIG*i + 9 ] !=0) ||
        (current_settings_prt.ranguvannja_reset_dt_source_plus[N_BIG*i + 10] !=0) ||
        (current_settings_prt.ranguvannja_reset_dt_source_plus[N_BIG*i + 11] !=0) ||
        (current_settings_prt.ranguvannja_reset_dt_source_plus[N_BIG*i + 12] !=0)
       )
    {
      //Випадок, якщо функції зранжовані на джерело прямих функцій
      if(
         (( current_settings_prt.ranguvannja_reset_dt_source_plus[N_BIG*i     ] & p_active_functions[0 ]) != 0) ||
         (( current_settings_prt.ranguvannja_reset_dt_source_plus[N_BIG*i + 1 ] & p_active_functions[1 ]) != 0) ||
         (( current_settings_prt.ranguvannja_reset_dt_source_plus[N_BIG*i + 2 ] & p_active_functions[2 ]) != 0) ||
         (( current_settings_prt.ranguvannja_reset_dt_source_plus[N_BIG*i + 3 ] & p_active_functions[3 ]) != 0) ||
         (( current_settings_prt.ranguvannja_reset_dt_source_plus[N_BIG*i + 4 ] & p_active_functions[4 ]) != 0) ||
         (( current_settings_prt.ranguvannja_reset_dt_source_plus[N_BIG*i + 5 ] & p_active_functions[5 ]) != 0) ||
         (( current_settings_prt.ranguvannja_reset_dt_source_plus[N_BIG*i + 6 ] & p_active_functions[6 ]) != 0) ||
         (( current_settings_prt.ranguvannja_reset_dt_source_plus[N_BIG*i + 7 ] & p_active_functions[7 ]) != 0) ||
         (( current_settings_prt.ranguvannja_reset_dt_source_plus[N_BIG*i + 8 ] & p_active_functions[8 ]) != 0) ||
         (( current_settings_prt.ranguvannja_reset_dt_source_plus[N_BIG*i + 9 ] & p_active_functions[9 ]) != 0) ||
         (( current_settings_prt.ranguvannja_reset_dt_source_plus[N_BIG*i + 10] & p_active_functions[10]) != 0) ||
         (( current_settings_prt.ranguvannja_reset_dt_source_plus[N_BIG*i + 11] & p_active_functions[11]) != 0) ||
         (( current_settings_prt.ranguvannja_reset_dt_source_plus[N_BIG*i + 12] & p_active_functions[12]) != 0)
        )
      {
        source_reset_dt |= (1 << i);
      }
    }

    if (
        (current_settings_prt.ranguvannja_reset_dt_source_minus[N_BIG*i     ] !=0) || 
        (current_settings_prt.ranguvannja_reset_dt_source_minus[N_BIG*i + 1 ] !=0) ||
        (current_settings_prt.ranguvannja_reset_dt_source_minus[N_BIG*i + 2 ] !=0) ||
        (current_settings_prt.ranguvannja_reset_dt_source_minus[N_BIG*i + 3 ] !=0) ||
        (current_settings_prt.ranguvannja_reset_dt_source_minus[N_BIG*i + 4 ] !=0) ||
        (current_settings_prt.ranguvannja_reset_dt_source_minus[N_BIG*i + 5 ] !=0) ||
        (current_settings_prt.ranguvannja_reset_dt_source_minus[N_BIG*i + 6 ] !=0) ||
        (current_settings_prt.ranguvannja_reset_dt_source_minus[N_BIG*i + 7 ] !=0) ||
        (current_settings_prt.ranguvannja_reset_dt_source_minus[N_BIG*i + 8 ] !=0) ||
        (current_settings_prt.ranguvannja_reset_dt_source_minus[N_BIG*i + 9 ] !=0) ||
        (current_settings_prt.ranguvannja_reset_dt_source_minus[N_BIG*i + 10] !=0) ||
        (current_settings_prt.ranguvannja_reset_dt_source_minus[N_BIG*i + 11] !=0) ||
        (current_settings_prt.ranguvannja_reset_dt_source_minus[N_BIG*i + 12] !=0)
       )
    {
      //Випадок, якщо функції зранжовані на джерело інверсних функцій
      if(
         ( ( current_settings_prt.ranguvannja_reset_dt_source_minus[N_BIG*i     ] & ((unsigned int)(~p_active_functions[0 ])) ) != 0 ) ||
         ( ( current_settings_prt.ranguvannja_reset_dt_source_minus[N_BIG*i + 1 ] & ((unsigned int)(~p_active_functions[1 ])) ) != 0 ) ||
         ( ( current_settings_prt.ranguvannja_reset_dt_source_minus[N_BIG*i + 2 ] & ((unsigned int)(~p_active_functions[2 ])) ) != 0 ) ||
         ( ( current_settings_prt.ranguvannja_reset_dt_source_minus[N_BIG*i + 3 ] & ((unsigned int)(~p_active_functions[3 ])) ) != 0 ) ||
         ( ( current_settings_prt.ranguvannja_reset_dt_source_minus[N_BIG*i + 4 ] & ((unsigned int)(~p_active_functions[4 ])) ) != 0 ) ||
         ( ( current_settings_prt.ranguvannja_reset_dt_source_minus[N_BIG*i + 5 ] & ((unsigned int)(~p_active_functions[5 ])) ) != 0 ) ||
         ( ( current_settings_prt.ranguvannja_reset_dt_source_minus[N_BIG*i + 6 ] & ((unsigned int)(~p_active_functions[6 ])) ) != 0 ) ||
         ( ( current_settings_prt.ranguvannja_reset_dt_source_minus[N_BIG*i + 7 ] & ((unsigned int)(~p_active_functions[7 ])) ) != 0 ) ||
         ( ( current_settings_prt.ranguvannja_reset_dt_source_minus[N_BIG*i + 8 ] & ((unsigned int)(~p_active_functions[8 ])) ) != 0 ) ||
         ( ( current_settings_prt.ranguvannja_reset_dt_source_minus[N_BIG*i + 9 ] & ((unsigned int)(~p_active_functions[9 ])) ) != 0 ) ||
         ( ( current_settings_prt.ranguvannja_reset_dt_source_minus[N_BIG*i + 10] & ((unsigned int)(~p_active_functions[10])) ) != 0 ) ||
         ( ( current_settings_prt.ranguvannja_reset_dt_source_minus[N_BIG*i + 11] & ((unsigned int)(~p_active_functions[11])) ) != 0 ) ||
         ( ( current_settings_prt.ranguvannja_reset_dt_source_minus[N_BIG*i + 12] & ((unsigned int)(~p_active_functions[12])) ) != 0 )
        )
      {
        source_reset_dt |= (1<< i);
      }
    }

    //Запускаємо у роботу лоргічну схему роботи опреділюваного триґера (встановлення має пріоритет)
    if ((source_set_dt   & (1 << i)) != 0) state_defined_triggers |= (1 << i);
    if ((source_reset_dt & (1 << i)) != 0) state_defined_triggers &= (unsigned int)(~(1 << i));
  }

  //Установлюємо, або скидаємо ОТ у масиві функцій, які зараз будуть активовуватися
  /*
  Цей цикл і попередній не об'єднаі в один, а навпаки розєднані, бо у першому ми використовуємо
  масив p_active_functions у якому ще не встановлені нові значення виходыв ОТ-ів, тому що інші ОТ-и
  можуть бути джерелом встановлення/скидання, але джерелом встановлення/скидання може буте попереднє значення ОТ, а не те,
  що зараз встановлюється. А оскілдьки у ми встановлюємо значення у масиві
  p_active_functions, які набувають зараз тільки ваги, то щоб не вийшло об'єднання попереднього значення
  і теперішнього то цикли роз'єднані (цикл аналізу джерел і логіки з циклом встановлення/скидання)
  */
  for (unsigned int i = 0; i < NUMBER_DEFINED_TRIGGERS; i++)
  {
    //Установлюємо, або скидаємо ОТ
    unsigned int index_dt;
    switch (i)
    {
    case 0:
      {
       index_dt = RNG_BIG_DT1_OUT;
        break;
      }
    case 1:
      {
       index_dt = RNG_BIG_DT2_OUT;
        break;
      }
    case 2:
      {
       index_dt = RNG_BIG_DT3_OUT;
        break;
      }
    case 3:
      {
       index_dt = RNG_BIG_DT4_OUT;
        break;
      }
    default:
      {
        //Теоретично цього ніколи не мало б бути
        total_error_sw_fixed(56);
        break;
      }
    }
      
    if ((state_defined_triggers & (1 << i)) != 0 ) _SET_BIT(p_active_functions, index_dt);
    else _CLEAR_BIT(p_active_functions, index_dt);
  }
}
/*****************************************************/

/*****************************************************/
//Опрацювання визначуваних "І"
/*****************************************************/
inline void d_and_handler(unsigned int *p_active_functions)
{
  unsigned int state_defined_and = 0;

  //Визначаємо стан всіх визначуваних "І" (не виставляючи поки що їх у робочому масиві)
  for (unsigned int i = 0; i < NUMBER_DEFINED_AND/*current_settings_prt.number_defined_and*/; i++)
  {
    if (
        ((current_settings_prt.ranguvannja_d_and[N_BIG*i + 0 ] & p_active_functions[0 ]) == current_settings_prt.ranguvannja_d_and[N_BIG*i + 0 ]) && 
        ((current_settings_prt.ranguvannja_d_and[N_BIG*i + 1 ] & p_active_functions[1 ]) == current_settings_prt.ranguvannja_d_and[N_BIG*i + 1 ]) &&
        ((current_settings_prt.ranguvannja_d_and[N_BIG*i + 2 ] & p_active_functions[2 ]) == current_settings_prt.ranguvannja_d_and[N_BIG*i + 2 ]) &&
        ((current_settings_prt.ranguvannja_d_and[N_BIG*i + 3 ] & p_active_functions[3 ]) == current_settings_prt.ranguvannja_d_and[N_BIG*i + 3 ]) &&
        ((current_settings_prt.ranguvannja_d_and[N_BIG*i + 4 ] & p_active_functions[4 ]) == current_settings_prt.ranguvannja_d_and[N_BIG*i + 4 ]) &&
        ((current_settings_prt.ranguvannja_d_and[N_BIG*i + 5 ] & p_active_functions[5 ]) == current_settings_prt.ranguvannja_d_and[N_BIG*i + 5 ]) &&
        ((current_settings_prt.ranguvannja_d_and[N_BIG*i + 6 ] & p_active_functions[6 ]) == current_settings_prt.ranguvannja_d_and[N_BIG*i + 6 ]) &&
        ((current_settings_prt.ranguvannja_d_and[N_BIG*i + 7 ] & p_active_functions[7 ]) == current_settings_prt.ranguvannja_d_and[N_BIG*i + 7 ]) &&
        ((current_settings_prt.ranguvannja_d_and[N_BIG*i + 8 ] & p_active_functions[8 ]) == current_settings_prt.ranguvannja_d_and[N_BIG*i + 8 ]) &&
        ((current_settings_prt.ranguvannja_d_and[N_BIG*i + 9 ] & p_active_functions[9 ]) == current_settings_prt.ranguvannja_d_and[N_BIG*i + 9 ]) &&
        ((current_settings_prt.ranguvannja_d_and[N_BIG*i + 10] & p_active_functions[10]) == current_settings_prt.ranguvannja_d_and[N_BIG*i + 10]) &&
        ((current_settings_prt.ranguvannja_d_and[N_BIG*i + 11] & p_active_functions[11]) == current_settings_prt.ranguvannja_d_and[N_BIG*i + 11]) &&
        ((current_settings_prt.ranguvannja_d_and[N_BIG*i + 12] & p_active_functions[12]) == current_settings_prt.ranguvannja_d_and[N_BIG*i + 12])
       )
    {
      state_defined_and |= (1 << i);
    }
  }

  //Установлюємо, або скидаємо визначувані "І" у масиві функцій, які зараз будуть активовуватися
  /*
  Цей цикл і попередній не об'єднаі в один, а навпаки розєднані, бо у першому ми використовуємо
  масив p_active_functions у якому ще не встановлені нові значення виходів В-"І", тому що інші В-"І"
  можуть бути джерелом , але джерелом може буте попереднє значення В-"І", а не те,
  що зараз встановлюється. А оскілдьки ми встановлюємо значення у масиві
  p_active_functions, які набувають зараз тільки ваги, то щоб не вийшло об'єднання попереднього значення
  і теперішнього то цикли роз'єднані (цикл аналізу джерел і логіки з циклом встановлення/скидання)
  */
  for (unsigned int i = 0; i < NUMBER_DEFINED_AND; i++)
  {
    //Установлюємо, або скидаємо В-"І"
//!@    unsigned int index_d_and = @RANG_D_AND1 + i;
    unsigned int index_d_and = RNG_BIG_D_AND1 + i;
      
    if ((state_defined_and & (1 << i)) != 0 ) _SET_BIT(p_active_functions, index_d_and);
    else _CLEAR_BIT(p_active_functions, index_d_and);
  }
}
/*****************************************************/

/*****************************************************/
//Опрацювання визначуваних "АБО"
/*****************************************************/
inline void d_or_handler(unsigned int *p_active_functions)
{
  unsigned int state_defined_or = 0;

  //Визначаємо стан всіх визначуваних "АБО" (не виставляючи поки що їх у робочому масиві)
  for (unsigned int i = 0; i < NUMBER_DEFINED_OR/*current_settings_prt.number_defined_or*/; i++)
  {
    if (
        ((current_settings_prt.ranguvannja_d_or[N_BIG*i + 0 ] & p_active_functions[0 ]) != 0) || 
        ((current_settings_prt.ranguvannja_d_or[N_BIG*i + 1 ] & p_active_functions[1 ]) != 0) ||
        ((current_settings_prt.ranguvannja_d_or[N_BIG*i + 2 ] & p_active_functions[2 ]) != 0) ||
        ((current_settings_prt.ranguvannja_d_or[N_BIG*i + 3 ] & p_active_functions[3 ]) != 0) ||
        ((current_settings_prt.ranguvannja_d_or[N_BIG*i + 4 ] & p_active_functions[4 ]) != 0) ||
        ((current_settings_prt.ranguvannja_d_or[N_BIG*i + 5 ] & p_active_functions[5 ]) != 0) ||
        ((current_settings_prt.ranguvannja_d_or[N_BIG*i + 6 ] & p_active_functions[6 ]) != 0) ||
        ((current_settings_prt.ranguvannja_d_or[N_BIG*i + 7 ] & p_active_functions[7 ]) != 0) ||
        ((current_settings_prt.ranguvannja_d_or[N_BIG*i + 8 ] & p_active_functions[8 ]) != 0) ||
        ((current_settings_prt.ranguvannja_d_or[N_BIG*i + 9 ] & p_active_functions[9 ]) != 0) ||
        ((current_settings_prt.ranguvannja_d_or[N_BIG*i + 10] & p_active_functions[10]) != 0) ||
        ((current_settings_prt.ranguvannja_d_or[N_BIG*i + 11] & p_active_functions[11]) != 0) ||
        ((current_settings_prt.ranguvannja_d_or[N_BIG*i + 12] & p_active_functions[12]) != 0)
       )
    {
      state_defined_or |= (1 << i);
    }
  }

  //Установлюємо, або скидаємо визначувані "АБО" у масиві функцій, які зараз будуть активовуватися
  /*
  Цей цикл і попередній не об'єднаі в один, а навпаки розєднані, бо у першому ми використовуємо
  масив p_active_functions у якому ще не встановлені нові значення виходів В-"АБО", тому що інші В-"АБО"
  можуть бути джерелом , але джерелом може буте попереднє значення В-"АБО", а не те,
  що зараз встановлюється. А оскілдьки ми встановлюємо значення у масиві
  p_active_functions, які набувають зараз тільки ваги, то щоб не вийшло об'єднання попереднього значення
  і теперішнього то цикли роз'єднані (цикл аналізу джерел і логіки з циклом встановлення/скидання)
  */
  for (unsigned int i = 0; i < NUMBER_DEFINED_OR; i++)
  {
    //Установлюємо, або скидаємо В-"АБО"
//!@    unsigned int index_d_or = @RANG_D_OR1 + i;
    unsigned int index_d_or = RNG_BIG_D_OR1 + i;
      
    if ((state_defined_or & (1 << i)) != 0 ) _SET_BIT(p_active_functions, index_d_or);
    else _CLEAR_BIT(p_active_functions, index_d_or);
  }
}
/*****************************************************/

/*****************************************************/
//Опрацювання визначуваних "Викл.АБО"
/*****************************************************/
inline void d_xor_handler(unsigned int *p_active_functions)
{
  unsigned int state_defined_xor = 0;

  //Визначаємо стан всіх визначуваних "Викл.АБО" (не виставляючи поки що їх у робочому масиві)
  for (unsigned int i = 0; i < NUMBER_DEFINED_XOR/*current_settings_prt.number_defined_xor*/; i++)
  {
    unsigned int temp_array[N_BIG] = 
    {
      current_settings_prt.ranguvannja_d_xor[N_BIG*i + 0 ] & p_active_functions[0 ],
      current_settings_prt.ranguvannja_d_xor[N_BIG*i + 1 ] & p_active_functions[1 ],
      current_settings_prt.ranguvannja_d_xor[N_BIG*i + 2 ] & p_active_functions[2 ],
      current_settings_prt.ranguvannja_d_xor[N_BIG*i + 3 ] & p_active_functions[3 ],
      current_settings_prt.ranguvannja_d_xor[N_BIG*i + 4 ] & p_active_functions[4 ],
      current_settings_prt.ranguvannja_d_xor[N_BIG*i + 5 ] & p_active_functions[5 ],
      current_settings_prt.ranguvannja_d_xor[N_BIG*i + 6 ] & p_active_functions[6 ],
      current_settings_prt.ranguvannja_d_xor[N_BIG*i + 7 ] & p_active_functions[7 ],
      current_settings_prt.ranguvannja_d_xor[N_BIG*i + 8 ] & p_active_functions[8 ],
      current_settings_prt.ranguvannja_d_xor[N_BIG*i + 9 ] & p_active_functions[9 ],
      current_settings_prt.ranguvannja_d_xor[N_BIG*i + 10] & p_active_functions[10],
      current_settings_prt.ranguvannja_d_xor[N_BIG*i + 11] & p_active_functions[11],
      current_settings_prt.ranguvannja_d_xor[N_BIG*i + 12] & p_active_functions[12]
    };
    
    if (
        (temp_array[0 ] != 0) || 
        (temp_array[1 ] != 0) ||
        (temp_array[2 ] != 0) ||
        (temp_array[3 ] != 0) ||
        (temp_array[4 ] != 0) ||
        (temp_array[5 ] != 0) ||
        (temp_array[6 ] != 0) ||
        (temp_array[7 ] != 0) ||
        (temp_array[8 ] != 0) ||
        (temp_array[9 ] != 0) ||
        (temp_array[10] != 0) ||
        (temp_array[11] != 0) ||
        (temp_array[12] != 0)
       )
    {
      unsigned int signals = 0;
      for (unsigned int j = 0; j < N_BIG; j++)
      {
        if (temp_array[j] == 0) continue; 
        else
        {
          for (unsigned int k = 0; k < 32; k++)
          {
            if ((temp_array[j] & (1 << k)) != 0) 
            {
              signals++;
              if (signals > 1) break;
            }
          }
          if (signals > 1) break;
        }
      }
      if (signals == 1) state_defined_xor |= (1 << i);
    }
  }

  //Установлюємо, або скидаємо визначувані "Викл.АБО" у масиві функцій, які зараз будуть активовуватися
  /*
  Цей цикл і попередній не об'єднаі в один, а навпаки розєднані, бо у першому ми використовуємо
  масив p_active_functions у якому ще не встановлені нові значення виходів В-"Викл.АБО", тому що інші В-"Викл.АБО"
  можуть бути джерелом , але джерелом може буте попереднє значення В-"Викл.АБО", а не те,
  що зараз встановлюється. А оскілдьки ми встановлюємо значення у масиві
  p_active_functions, які набувають зараз тільки ваги, то щоб не вийшло об'єднання попереднього значення
  і теперішнього то цикли роз'єднані (цикл аналізу джерел і логіки з циклом встановлення/скидання)
  */
  for (unsigned int i = 0; i < NUMBER_DEFINED_XOR; i++)
  {
    //Установлюємо, або скидаємо В-"Викл.АБО"
    unsigned int index_d_xor = RNG_BIG_D_XOR1 + i;
      
    if ((state_defined_xor & (1 << i)) != 0 ) _SET_BIT(p_active_functions, index_d_xor);
    else _CLEAR_BIT(p_active_functions, index_d_xor);
  }
}
/*****************************************************/

/*****************************************************/
//Опрацювання визначуваних "НЕ"
/*****************************************************/
inline void d_not_handler(unsigned int *p_active_functions)
{
  unsigned int state_defined_not = 0;

  //Визначаємо стан всіх визначуваних "НЕ" (не виставляючи поки що їх у робочому масиві)
  for (unsigned int i = 0; i < NUMBER_DEFINED_NOT/*current_settings_prt.number_defined_not*/; i++)
  {
    if (
        ((current_settings_prt.ranguvannja_d_not[N_BIG*i + 0 ] & p_active_functions[0 ]) == 0) &&
        ((current_settings_prt.ranguvannja_d_not[N_BIG*i + 1 ] & p_active_functions[1 ]) == 0) &&
        ((current_settings_prt.ranguvannja_d_not[N_BIG*i + 2 ] & p_active_functions[2 ]) == 0) &&
        ((current_settings_prt.ranguvannja_d_not[N_BIG*i + 3 ] & p_active_functions[3 ]) == 0) &&
        ((current_settings_prt.ranguvannja_d_not[N_BIG*i + 4 ] & p_active_functions[4 ]) == 0) &&
        ((current_settings_prt.ranguvannja_d_not[N_BIG*i + 5 ] & p_active_functions[5 ]) == 0) &&
        ((current_settings_prt.ranguvannja_d_not[N_BIG*i + 6 ] & p_active_functions[6 ]) == 0) &&
        ((current_settings_prt.ranguvannja_d_not[N_BIG*i + 7 ] & p_active_functions[7 ]) == 0) &&
        ((current_settings_prt.ranguvannja_d_not[N_BIG*i + 8 ] & p_active_functions[8 ]) == 0) &&
        ((current_settings_prt.ranguvannja_d_not[N_BIG*i + 9 ] & p_active_functions[9 ]) == 0) &&
        ((current_settings_prt.ranguvannja_d_not[N_BIG*i + 10] & p_active_functions[10]) == 0) &&
        ((current_settings_prt.ranguvannja_d_not[N_BIG*i + 11] & p_active_functions[11]) == 0) &&
        ((current_settings_prt.ranguvannja_d_not[N_BIG*i + 12] & p_active_functions[12]) == 0)
       )
    {
      state_defined_not |= (1 << i);
    }
  }

  //Установлюємо, або скидаємо визначувані "НЕ" у масиві функцій, які зараз будуть активовуватися
  /*
  Цей цикл і попередній не об'єднаі в один, а навпаки розєднані, бо у першому ми використовуємо
  масив p_active_functions у якому ще не встановлені нові значення виходів В-"НЕ", тому що інші В-"НЕ"
  можуть бути джерелом , але джерелом може буте попереднє значення В-"НЕ", а не те,
  що зараз встановлюється. А оскілдьки ми встановлюємо значення у масиві
  p_active_functions, які набувають зараз тільки ваги, то щоб не вийшло об'єднання попереднього значення
  і теперішнього то цикли роз'єднані (цикл аналізу джерел і логіки з циклом встановлення/скидання)
  */
  for (unsigned int i = 0; i < NUMBER_DEFINED_NOT; i++)
  {
    //Установлюємо, або скидаємо В-"НЕ"
    unsigned int index_d_not = RNG_BIG_D_NOT1 + i;
      
    if ((state_defined_not & (1 << i)) != 0 ) _SET_BIT(p_active_functions, index_d_not);
    else _CLEAR_BIT(p_active_functions, index_d_not);
  }
}
/*****************************************************/

/*****************************************************/
//Опрацювання Передавальних функцій
/*****************************************************/
inline void tf_handler(unsigned int *p_previous_active_functions, unsigned int *p_active_functions)
{
  for (size_t i = 0; i < NUMBER_TRANSFER_FUNCTIONS; i++)
  {
    uint32_t value = current_settings_prt.ranguvannja_tf[i];
    uint32_t value_input = value & 0xffff;
    if (value_input > 0)
    {
      value_input--;
      if (value_input < NUMBER_TOTAL_SIGNAL_FOR_RANG)
      {
        if (_CHECK_SET_BIT(p_previous_active_functions, value_input) != 0)
        {
          uint32_t value_output = (value >> 16) & 0xffff;
          if (value_output > 0)
          {
            value_output--;
            if (value_output < TOTAL_SIGNAL_FOR_RANG_SMALL_A01)
            {
              _SET_BIT(p_active_functions, small_big_rang[value_output]);//!@_SET_BIT(p_active_functions, @small_big_rang[value_output]);
            }
            else
            {
              //Відбулася невизначена помилка, тому треба піти на перезавантаження
              total_error_sw_fixed(102);
            }
          }
        }
      }
      else
      {
        //Відбулася невизначена помилка, тому треба піти на перезавантаження
        total_error_sw_fixed(101);
      }
    }
  }
}
/*****************************************************/

/*****************************************************/
//Вираховування часової витримки  для залежної МТЗ2 (універсальна формула)
/*
-------------------------------------------------
Т(c) = K*Tу/( ((I/Iу)^alpha) - 1 )
-------------------------------------------------
*/
/*****************************************************/
inline int timeout_dependent_general(unsigned int i, unsigned int setpoint_mtz_2, int timeout_mtz_2, int type_mtz2_tmp)
{
  int timeout_result = 0;
  
  if (
      (type_mtz2_tmp >= TYPE_MTZ_DEPENDENT_A) &&
      (type_mtz2_tmp <= TYPE_MTZ_DEPENDENT_RTV_I)
     )   
  {
    unsigned int Iust = setpoint_mtz_2;
    if (i > Iust)
    {
      register float timeout = (((float)timeout_mtz_2)/1000.0f);
      register float timeout_dependent = 0;
      
      if (
          (type_mtz2_tmp >= TYPE_MTZ_DEPENDENT_A) &&
          (type_mtz2_tmp <= TYPE_MTZ_DEPENDENT_C)
         )   
      {
        register float K;
        register float alpha;

        switch (type_mtz2_tmp)
        {
          case TYPE_MTZ_DEPENDENT_A:
          {
            K = 0.14f;
            alpha = 0.02f;
            break;
          }
        case TYPE_MTZ_DEPENDENT_B:
          {
            K = 13.5f;
            alpha = 1.0f;
            break;
          }
        case TYPE_MTZ_DEPENDENT_C:
          {
            K = 80.0f;
            alpha = 2.0f;
            break;
          }
        default:
          {
            //Теоретично цього ніколи не мало б бути
            total_error_sw_fixed(42);
          }
        }
    
        register float I_div_Iusy = ((float)i)/((float)Iust);
        register float rising_to_power = powf(I_div_Iusy, alpha);
        if (
            (isnan(rising_to_power) != 0) || 
            (isinf(rising_to_power) != 0) ||
            (rising_to_power <= 1)
          )
        {
          //Теоретично цього ніколи не мало б бути
          total_error_sw_fixed(57);
        }
  
        timeout_dependent = K*timeout/(rising_to_power - 1);
      }
      else if (
               (type_mtz2_tmp >= TYPE_MTZ_DEPENDENT_RT_80) &&
               (type_mtz2_tmp <= TYPE_MTZ_DEPENDENT_RTV_I)
              )   
      {
        register float I_div_Iusy = ((float)i)/((float)Iust);
        I_div_Iusy = I_div_Iusy - 1.0f;

        register float K;
        register float alpha;

        switch (type_mtz2_tmp)
        {
        case TYPE_MTZ_DEPENDENT_RT_80:
          {
            K = 20.0f;
            alpha = 1.8f;
          
            I_div_Iusy /= 6.0f;
            break;
          }
        case TYPE_MTZ_DEPENDENT_RTV_I:
          {
            K = 30.0f;
            alpha = 3.0f;
            break;
          } 
        default:
          {
            //Теоретично цього ніколи не мало б бути
            total_error_sw_fixed(87);
          }
        }
      
        register float rising_to_power = powf(I_div_Iusy, alpha);
        if (
            (isnan(rising_to_power) != 0) || 
            (isinf(rising_to_power) != 0) ||
            (rising_to_power <= 0)
           )
        {
          //Теоретично цього ніколи не мало б бути
          total_error_sw_fixed(86);
        }
      
        timeout_dependent = 1.0f/(K*rising_to_power)+ timeout;
      }

      int timeout_dependent_int = (int)timeout_dependent;
      if (timeout_dependent_int > (TIMEOUT_MTZ2_MAX/1000)) timeout_dependent = (TIMEOUT_MTZ2_MAX/1000);
      else if (timeout_dependent_int < 0) timeout_dependent = 0;
    
      timeout_result = (int)(timeout_dependent*1000.0f);
    }
    else timeout_result = TIMEOUT_MTZ2_MAX;
  }
  
  return timeout_result;
}
/*****************************************************/

/*****************************************************/
// МТЗ
/*****************************************************/
inline void mtz_handler(unsigned int *p_active_functions, unsigned int number_group_stp)
{
  //!unsigned int tmp_value;
  (void)p_active_functions,(void)number_group_stp;
  //!unsigned int po_mtz_x;
  //!unsigned int direction_ABC_tmp;
  //!unsigned int po_mtzn_x_vpered_setpoint;
  //!unsigned int po_mtzn_x_nazad_setpoint;
//  unsigned int po_block_u_mtzn_x_setpoint;
  //!unsigned int po_i_ncn_setpoint;
  //!unsigned int po_u_ncn_setpoint;
  //!unsigned int po_u_mtzpn_x_setpoint;
  //!unsigned int po_mtzpn_x_setpoint;
  #ifdef MTZ  
  /******Неисправность цепей напряжения для 4-х ступеней*******/
  _Bool ctr_mtz_nespr_kil_napr = (current_settings_prt.control_mtz & CTR_MTZ_NESPR_KIL_NAPR) != 0; //Неиспр. Напр. Вкл. (М)
  
  //ПО Iнцн
  po_i_ncn_setpoint = previous_state_mtz_po_incn ?
            i_nom_const * KOEF_POVERNENNJA_MTZ_I_DOWN / 100 :
            i_nom_const;
  
  previous_state_mtz_po_incn = ((measurement[IM_Imn] <= po_i_ncn_setpoint) &&
                                (measurement[IM_Ibp] <= po_i_ncn_setpoint));
  
  //ПО Uнцн
  po_u_ncn_setpoint = previous_state_mtz_po_uncn ?
            u_f_nom_const * U_DOWN / 100 :
            u_f_nom_const;
  
  previous_state_mtz_po_uncn = ((measurement[IM_Umn] <= po_u_ncn_setpoint) ||
                                (measurement[IM_Ubp] <= po_u_ncn_setpoint));
  
  ctr_mtz_nespr_kil_napr = ctr_mtz_nespr_kil_napr && previous_state_mtz_po_incn && previous_state_mtz_po_uncn; //Неисправность цепей напряжения (_AND3)

  //Неисправность цепей напряжения
  if (ctr_mtz_nespr_kil_napr)
    _SET_BIT(p_active_functions, RANG_NCN_MTZ);
  else
    _CLEAR_BIT(p_active_functions, RANG_NCN_MTZ);
  /******Неисправность цепей напряжения для 4-х ступеней*******/
  
  /******ПО U блок. МТЗНх***********************/
  //Уставка ПО U блок. МТЗНх з врахуванням гістерезису
  unsigned int po_block_u_mtzn_x_setpoint = (_CHECK_SET_BIT(p_active_functions, RANG_PO_BLOCK_U_MTZN) == 0) ? PORIG_CHUTLYVOSTI_VOLTAGE : PORIG_CHUTLYVOSTI_VOLTAGE * U_DOWN / 100;
  
  //ПО U блок. МТЗНх
  if (
      (measurement[IM_Umn] <= po_block_u_mtzn_x_setpoint) ||
      (measurement[IM_Ubp] <= po_block_u_mtzn_x_setpoint)
     )
  {
    _SET_BIT(p_active_functions, RANG_PO_BLOCK_U_MTZN);
  }
  else
  {
    _CLEAR_BIT(p_active_functions, RANG_PO_BLOCK_U_MTZN);
  }
  /******ПО U блок. МТЗНх***********************/

  for (int mtz_level = 0; mtz_level < NUMBER_LEVEL_MTZ; mtz_level++) {
    //Для отладки
//    if (mtz_level == 0) {
//      mtz_level = 0;
//    } else if (mtz_level == 1) {
//      mtz_level = 1;
//    } else if (mtz_level == 2) {
//      mtz_level = 2;
//    } else if (mtz_level == 3) {
//      mtz_level = 3;
//    }
    
    //М
    /*Проверяем тип МТЗ*/
    tmp_value = (*type_mtz_arr[mtz_level] == 1)                                  << 0; //Направленная
    tmp_value |= (*type_mtz_arr[mtz_level] == 2)                                 << 1; //С пуском
    tmp_value |= (*type_mtz_arr[mtz_level] == 0)                                 << 2; //Простая
    tmp_value |= (
                  (mtz_level == 1)
                  && (*type_mtz_arr[mtz_level] >= TYPE_MTZ_DEPENDENT_A) //A, B, C (3-5)
                  && (*type_mtz_arr[mtz_level] <= TYPE_MTZ_DEPENDENT_RTV_I)
                 )                                                               << 3; //Зависимая (если mtz_level == 1 (2-я ступень МТЗ))
    
    /******ПО МТЗх***********************/
    //Уставка ПО МТЗх с учетом гистерезиса
    po_mtz_x = (_CHECK_SET_BIT(p_active_functions, mtz_settings_prt[mtz_level][RANG_PO_MTZ]) != 0) ?
            *(setpoint_mtz[mtz_level] + number_group_stp) * KOEF_POVERNENNJA_MTZ_I_UP / 100 :
            *(setpoint_mtz[mtz_level] + number_group_stp);
    
    tmp_value |= ((measurement[IM_Imn] >= po_mtz_x) ||
          (measurement[IM_Ibp] >= po_mtz_x)) << 4; //ПО МТЗх
    /******ПО МТЗх***********************/
    
    //М
    tmp_value |= ((current_settings_prt.control_mtz & mtz_const_menu_settings_prt[mtz_level][CTR_MTZ]) != 0) << 5; //МТЗх Вкл.
    //ДВ
    tmp_value |= (_CHECK_SET_BIT(p_active_functions, mtz_settings_prt[mtz_level][RANG_BLOCK_MTZ]) == 0) << 6; //Блокировка МТЗх
    //М
    tmp_value |= ((current_settings_prt.control_mtz & mtz_const_menu_settings_prt[mtz_level][CTR_MTZ_VPERED]) != 0) << 7; //МТЗНх: Вкл. прям
    tmp_value |= ((current_settings_prt.control_mtz & mtz_const_menu_settings_prt[mtz_level][CTR_MTZ_NAZAD]) != 0) << 8; //МТЗНх: Вкл. обр
    
    /******Сектор МТЗНх Вперед/Назад**********/
    //Проверка направленности фаз А,В,С
    direction_ABC_tmp = (sector_directional_mtz[mtz_level][PHASE_MN_INDEX] == MTZ_VPERED) << 0; //Проверка направленности фазы А вперед
    direction_ABC_tmp |= (sector_directional_mtz[mtz_level][PHASE_BP_INDEX] == MTZ_VPERED) << 1; //Проверка направленности фазы B вперед
    
    _OR2(direction_ABC_tmp, 0, direction_ABC_tmp, 1, direction_ABC_tmp, 3);
    
    //Сектор МТЗНх Вперед
    if (_GET_OUTPUT_STATE(direction_ABC_tmp, 3))
      _SET_BIT(p_active_functions, mtz_settings_prt[mtz_level][RANG_SECTOR_VPERED_MTZN]);
    else
      _CLEAR_BIT(p_active_functions, mtz_settings_prt[mtz_level][RANG_SECTOR_VPERED_MTZN]);
    
    direction_ABC_tmp |= (sector_directional_mtz[mtz_level][PHASE_MN_INDEX] == MTZ_NAZAD) << 4; //Проверка направленности фазы А назад
    direction_ABC_tmp |= (sector_directional_mtz[mtz_level][PHASE_BP_INDEX] == MTZ_NAZAD) << 5; //Проверка направленности фазы B назад
    
    _OR2(direction_ABC_tmp, 4, direction_ABC_tmp, 5, direction_ABC_tmp, 7);
    
    //Сектор МТЗНх Назад
    if (_GET_OUTPUT_STATE(direction_ABC_tmp, 7))
      _SET_BIT(p_active_functions, mtz_settings_prt[mtz_level][RANG_SECTOR_NAZAD_MTZN]);
    else
      _CLEAR_BIT(p_active_functions, mtz_settings_prt[mtz_level][RANG_SECTOR_NAZAD_MTZN]);
    
    //Уставка ПО МТЗН1 прям. с учетом гистерезиса
    po_mtzn_x_vpered_setpoint = (_CHECK_SET_BIT(p_active_functions, mtz_settings_prt[mtz_level][RANG_PO_MTZN_VPERED]) != 0) ?
            *(setpoint_mtz_n_vpered[mtz_level] + number_group_stp) * KOEF_POVERNENNJA_MTZ_I_UP / 100 :
            *(setpoint_mtz_n_vpered[mtz_level] + number_group_stp);
    
    direction_ABC_tmp |= (measurement[IM_Imn] >= po_mtzn_x_vpered_setpoint) << 8; //Сравниваем с уставкой тока по фазе А (вперед)
    direction_ABC_tmp |= (measurement[IM_Ibp] >= po_mtzn_x_vpered_setpoint) << 9; //Сравниваем с уставкой тока по фазе B (вперед)
    //direction_ABC_tmp |= (measurement[IM_IC] >= po_mtzn_x_vpered_setpoint) << 10; //Сравниваем с уставкой тока по фазе C (вперед)
    
    //Уставка ПО МТЗН1 прям. с учетом гистерезиса
    po_mtzn_x_nazad_setpoint = (_CHECK_SET_BIT(p_active_functions, mtz_settings_prt[mtz_level][RANG_PO_MTZN_NAZAD]) != 0) ?
            *(setpoint_mtz_n_nazad[mtz_level] + number_group_stp) * KOEF_POVERNENNJA_MTZ_I_UP / 100 :
            *(setpoint_mtz_n_nazad[mtz_level] + number_group_stp);
    
    direction_ABC_tmp |= (measurement[IM_Imn] >= po_mtzn_x_nazad_setpoint) << 11; //Сравниваем с уставкой тока по фазе А (назад)
    direction_ABC_tmp |= (measurement[IM_Ibp] >= po_mtzn_x_nazad_setpoint) << 12; //Сравниваем с уставкой тока по фазе B (назад)
    //direction_ABC_tmp |= (measurement[IM_IC] >= po_mtzn_x_nazad_setpoint) << 13; //Сравниваем с уставкой тока по фазе C (назад)
    
    _AND2(direction_ABC_tmp, 8, direction_ABC_tmp, 0, direction_ABC_tmp, 14);
    _AND2(direction_ABC_tmp, 9, direction_ABC_tmp, 1, direction_ABC_tmp, 15);
    //_AND2(direction_ABC_tmp, 10, direction_ABC_tmp, 2, direction_ABC_tmp, 16);
    
    _AND2(direction_ABC_tmp, 11, direction_ABC_tmp, 4, direction_ABC_tmp, 17);
    _AND2(direction_ABC_tmp, 12, direction_ABC_tmp, 5, direction_ABC_tmp, 18);
    //_AND2(direction_ABC_tmp, 13, direction_ABC_tmp, 6, direction_ABC_tmp, 19);
    
    _OR2(direction_ABC_tmp, 14, direction_ABC_tmp, 15, /*direction_ABC_tmp, 16,*/ tmp_value, 12);
    _OR2(direction_ABC_tmp, 17, direction_ABC_tmp, 18, /*direction_ABC_tmp, 19,*/ tmp_value, 13);
    /******Сектор МТЗНх Вперед/Назад**********/
    
//    /******ПО U блок. МТЗНх***********************/
//    //Уставка ПО U блок. МТЗНх с учетом гистерезиса
//    po_block_u_mtzn_x_setpoint = (_CHECK_SET_BIT(p_active_functions, RANG_PO_BLOCK_U_MTZN) != 0) ?
//           PORIG_CHUTLYVOSTI_VOLTAGE :
//           PORIG_CHUTLYVOSTI_VOLTAGE * U_DOWN / 100;
//    
//    tmp_value |= ((measurement[IM_UAB] <= po_block_u_mtzn_x_setpoint) ||
//                  (measurement[IM_UBC] <= po_block_u_mtzn_x_setpoint) ||
//                  (measurement[IM_UCA] <= po_block_u_mtzn_x_setpoint)) << 14; //ПО U блок. МТЗНх
//    
//    //ПО U блок. МТЗНх
//    if (_GET_OUTPUT_STATE(tmp_value, 14))
//      _SET_BIT(p_active_functions, RANG_PO_BLOCK_U_MTZN);
//    else
//      _CLEAR_BIT(p_active_functions, RANG_PO_BLOCK_U_MTZN);
//    /******ПО U блок. МТЗНх***********************/
    tmp_value |= (_CHECK_SET_BIT(p_active_functions, RANG_PO_BLOCK_U_MTZN) != 0) << 14;
    
    //Неисправность цепей напряжения для ступени МТЗх
    tmp_value |= (
                   !(_CHECK_SET_BIT(p_active_functions, mtz_settings_prt[mtz_level][RANG_PO_MTZN_VPERED]) != 0 ||
                     _CHECK_SET_BIT(p_active_functions, mtz_settings_prt[mtz_level][RANG_PO_MTZN_NAZAD])  != 0 ||
                     _CHECK_SET_BIT(p_active_functions, mtz_settings_prt[mtz_level][RANG_PO_MTZPN])     != 0)
                   &&
                   ctr_mtz_nespr_kil_napr
                 ) << 15;
    
    /******ПО U МТЗПНх***********************/
    po_u_mtzpn_x_setpoint = (_CHECK_SET_BIT(p_active_functions, mtz_settings_prt[mtz_level][RANG_PO_U_MTZPN]) != 0) ?
            *(setpoint_mtz_U[mtz_level] + number_group_stp) * U_DOWN / 100:
            *(setpoint_mtz_U[mtz_level] + number_group_stp) ;
    
    tmp_value |= ((measurement[IM_Umn] <= po_u_mtzpn_x_setpoint) ||
                  (measurement[IM_Ubp] <= po_u_mtzpn_x_setpoint)) << 16; //ПО U МТЗПНх
    
    //ПО U МТЗПНх
    if (_GET_OUTPUT_STATE(tmp_value, 16))
      _SET_BIT(p_active_functions, mtz_settings_prt[mtz_level][RANG_PO_U_MTZPN]);
    else
      _CLEAR_BIT(p_active_functions, mtz_settings_prt[mtz_level][RANG_PO_U_MTZPN]);
    /******ПО U МТЗПНх***********************/
    
    /******ПО МТЗПНх***********************/
    po_mtzpn_x_setpoint = (_CHECK_SET_BIT(p_active_functions, mtz_settings_prt[mtz_level][RANG_PO_MTZPN]) != 0) ?
            *(setpoint_mtz_po_napruzi[mtz_level] + number_group_stp) * KOEF_POVERNENNJA_MTZ_I_UP / 100:
            *(setpoint_mtz_po_napruzi[mtz_level] + number_group_stp);
    
    tmp_value |= ((measurement[IM_Imn] >= po_mtzpn_x_setpoint)   ||
                  (measurement[IM_Ibp] >= po_mtzpn_x_setpoint)) << 17; //ПО МТЗПНх
    /******ПО МТЗПНх***********************/
    
    if (mtz_level == 1) { //только для 2-ой ступени
      //ДВ
      tmp_value |= (_CHECK_SET_BIT(p_active_functions, mtz_settings_prt[mtz_level][RANG_BLOCK_USK_MTZ]) == 0) << 9; //Блокировка ускорения МТЗ 2
      //М
      tmp_value |= ((current_settings_prt.control_mtz & CTR_MTZ_2_PRYSKORENA) != 0) << 10; //МТЗ2 Ускоренная
      //ДВ
      tmp_value |= (_CHECK_SET_BIT(p_active_functions, RANG_STATE_VV) != 0) << 18; //Положение ВВ
      //M
      tmp_value |= ((current_settings_prt.control_mtz & CTR_MTZ_2_PRYSKORENNJA) != 0) << 11; //Ускорение МТЗ2 вкл.
    }
    
    if (_GET_OUTPUT_STATE(tmp_value, 15)) { //Если зафиксирована неисправность цепей напряжения для ступени МТЗх
      _CLEAR_STATE(tmp_value, 16); //Очистка ПО U МТЗПНх
    }
    
    _OR2_INVERTOR(tmp_value, 14, tmp_value, 15, tmp_value, 14);
    
    if (_CHECK_SET_BIT(p_active_functions, mtz_settings_prt[mtz_level][RANG_PO_MTZ]) != 0) 
    {
      _SET_STATE(tmp_value, 19);
    } 
    else 
    {
      if (mtz_level == 1)
      {
        //только для 2-ой ступени при формировании 19-го сигнала будет учитываться
        //сигнал "Зависимая" (tmp_value 3)
        if (_GET_OUTPUT_STATE(tmp_value, 14)) 
        {
          _OR3(tmp_value, 2, tmp_value, 3, tmp_value, 15, tmp_value, 19);
        }
        else 
        {
          _OR4(tmp_value, 0, tmp_value, 2, tmp_value, 3, tmp_value, 15, tmp_value, 19);
        }
      }
      else 
      {
        if (_GET_OUTPUT_STATE(tmp_value, 14))
        {
          _OR2(tmp_value, 2, tmp_value, 15, tmp_value, 19);
        } 
        else
        {
          _OR3(tmp_value, 0, tmp_value, 2, tmp_value, 15, tmp_value, 19);
        }
      }
    }
    
    _AND2(tmp_value, 5, tmp_value, 6, tmp_value, 20);
    
    //ПО МТЗх
    _AND3(tmp_value, 19, tmp_value, 4, tmp_value, 20, tmp_value, 21);
    if (_GET_OUTPUT_STATE(tmp_value, 21))
      _SET_BIT(p_active_functions, mtz_settings_prt[mtz_level][RANG_PO_MTZ]);
    else
      _CLEAR_BIT(p_active_functions, mtz_settings_prt[mtz_level][RANG_PO_MTZ]);
    
    //ПО МТЗНх вперед
    _AND5(tmp_value, 0, tmp_value, 20, tmp_value, 7, tmp_value, 12, tmp_value, 14, tmp_value, 22);
    if (_GET_OUTPUT_STATE(tmp_value, 22))
      _SET_BIT(p_active_functions, mtz_settings_prt[mtz_level][RANG_PO_MTZN_VPERED]);
    else
      _CLEAR_BIT(p_active_functions, mtz_settings_prt[mtz_level][RANG_PO_MTZN_VPERED]);
    
    //ПО МТЗНх назад
    _AND5(tmp_value, 0, tmp_value, 20, tmp_value, 8, tmp_value, 13, tmp_value, 14, tmp_value, 23);
    if (_GET_OUTPUT_STATE(tmp_value, 23)) 
      _SET_BIT(p_active_functions, mtz_settings_prt[mtz_level][RANG_PO_MTZN_NAZAD]);
    else
      _CLEAR_BIT(p_active_functions, mtz_settings_prt[mtz_level][RANG_PO_MTZN_NAZAD]);
    
    //ПО МТЗПНх
    _AND4(tmp_value, 1, tmp_value, 20, tmp_value, 16, tmp_value, 17, tmp_value, 24);
    if (_GET_OUTPUT_STATE(tmp_value, 24))
      _SET_BIT(p_active_functions, mtz_settings_prt[mtz_level][RANG_PO_MTZPN]);
    else
      _CLEAR_BIT(p_active_functions, mtz_settings_prt[mtz_level][RANG_PO_MTZPN]);
    
    if (mtz_level != 1) { //для всех ступеней кроме 2-ой
      //-_TIMER_T_0(mtz_tmr_const[mtz_level][INDEX_TIMER_MTZ], *(timeout_mtz[mtz_level] + number_group_stp), tmp_value, 21, tmp_value, 25);
      //-_TIMER_T_0(mtz_tmr_const[mtz_level][INDEX_TIMER_MTZ_N_VPERED], *(timeout_mtz_n_vpered[mtz_level] + number_group_stp), tmp_value, 22, tmp_value, 26);
      //-_TIMER_T_0(mtz_tmr_const[mtz_level][INDEX_TIMER_MTZ_N_NAZAD], *(timeout_mtz_n_nazad[mtz_level] + number_group_stp), tmp_value, 23, tmp_value, 27);
      //-_TIMER_T_0(mtz_tmr_const[mtz_level][INDEX_TIMER_MTZ_PO_NAPRUZI], *(timeout_mtz_po_napruzi[mtz_level] + number_group_stp), tmp_value, 24, tmp_value, 28);
      _OR4(tmp_value, 25, tmp_value, 26, tmp_value, 27, tmp_value, 28, tmp_value, 31);
    } else {
      unsigned int tmp = 0;
      _AND2(tmp_value, 18, tmp_value, 11, tmp, 0);
      //-_TIMER_IMPULSE(INDEX_TIMER_MTZ2_VVID_PR, current_settings_prt.timeout_mtz_2_vvid_pr[number_group_stp], temp_states_for_mtz, 0, tmp, 0, tmp, 1);
      _OR2(tmp, 1, tmp_value, 10, tmp, 2);
      _AND2(tmp_value, 9, tmp, 2, tmp, 3);
      _INVERTOR(tmp, 3, tmp, 4);
      _INVERTOR(tmp_value, 3, tmp, 23); /*Добавлено Тарасом у Богданову програму*/
      _AND3(tmp, 4, tmp_value, 3, tmp_value, 21, tmp, 5);
      _AND2(tmp, 3, tmp_value, 21, tmp, 6);
      _AND3(tmp, 4, tmp_value, 21, tmp, 23, tmp, 7); /*Модифіковано Тарасом у Богдановій програмі*/
      _AND2(tmp, 4, tmp_value, 22, tmp, 8);
      _AND2(tmp, 3, tmp_value, 22, tmp, 9);
      _AND2(tmp, 4, tmp_value, 23, tmp, 10);
      _AND2(tmp, 3, tmp_value, 23, tmp, 11);
      _AND2(tmp, 4, tmp_value, 24, tmp, 12);
      _AND2(tmp, 3, tmp_value, 24, tmp, 13);
      
      unsigned int i_max = measurement[IM_Imn];
      if (i_max < measurement[IM_Ibp]) i_max = measurement[IM_Ibp];
      //-_TIMER_T_0_LOCK(INDEX_TIMER_MTZ2_DEPENDENT, timeout_dependent_general(i_max, current_settings_prt.setpoint_mtz_2[number_group_stp], current_settings_prt.timeout_mtz_2[number_group_stp], current_settings_prt.type_mtz2), tmp, 5, p_global_trigger_state_mtz2, 0);
      //-_TIMER_T_0(INDEX_TIMER_MTZ2_PR, current_settings_prt.timeout_mtz_2_pr[number_group_stp], tmp, 6, tmp, 15);
      //-_TIMER_T_0(INDEX_TIMER_MTZ2, current_settings_prt.timeout_mtz_2[number_group_stp], tmp, 7, tmp, 16);
      //-_TIMER_T_0(INDEX_TIMER_MTZ2_N_VPERED, current_settings_prt.timeout_mtz_2_n_vpered[number_group_stp], tmp, 8, tmp, 17);
      //-_TIMER_T_0(INDEX_TIMER_MTZ2_N_VPERED_PR, current_settings_prt.timeout_mtz_2_n_vpered_pr[number_group_stp], tmp, 9, tmp, 18);
      //-_TIMER_T_0(INDEX_TIMER_MTZ2_N_NAZAD, current_settings_prt.timeout_mtz_2_n_nazad[number_group_stp], tmp, 10, tmp, 19);
      //-_TIMER_T_0(INDEX_TIMER_MTZ2_N_NAZAD_PR, current_settings_prt.timeout_mtz_2_n_nazad_pr[number_group_stp], tmp, 11, tmp, 20);
      //-_TIMER_T_0(INDEX_TIMER_MTZ2_PO_NAPRUZI, current_settings_prt.timeout_mtz_2_po_napruzi[number_group_stp], tmp, 12, tmp, 21);
      //-_TIMER_T_0(INDEX_TIMER_MTZ2_PO_NAPRUZI_PR, current_settings_prt.timeout_mtz_2_po_napruzi_pr[number_group_stp], tmp, 13, tmp, 22);
      
      _OR6(p_global_trigger_state_mtz2, 0, tmp, 15, tmp, 16, tmp, 17, tmp, 18, tmp, 19, tmp_value, 29);
      _OR3(tmp, 20, tmp, 21, tmp, 22, tmp_value, 30);
      _OR2(tmp_value, 29, tmp_value, 30, tmp_value, 31);
    }
    
    //Сраб.МТЗх
    if (_GET_OUTPUT_STATE(tmp_value, 31))
      _SET_BIT(p_active_functions, mtz_settings_prt[mtz_level][RANG_MTZ]);
    else
      _CLEAR_BIT(p_active_functions, mtz_settings_prt[mtz_level][RANG_MTZ]);
  }
  #endif
}
/*****************************************************/

/*****************************************************/
// ЗДЗ
/*****************************************************/
inline void zdz_handler(unsigned int *p_active_functions, unsigned int number_group_stp)
{
  
  uint32_t control_zdz_tmp = current_settings_prt.control_zdz;

#if (                                   \
     (MODYFIKACIA_VERSII_PZ == 0) ||    \
     (MODYFIKACIA_VERSII_PZ == 3)       \
    )   

  static uint32_t test;
  static uint32_t swiched_on_OVD;
  static uint32_t new_OVD;

  uint32_t swiched_on_OVD_tmp = (control_zdz_tmp & ((1 << CTR_ZDZ_OVD1_STATE_BIT) | (1 << CTR_ZDZ_OVD2_STATE_BIT) | (1 << CTR_ZDZ_OVD3_STATE_BIT))) >> CTR_ZDZ_OVD1_STATE_BIT;

  new_OVD |= (swiched_on_OVD ^ swiched_on_OVD_tmp) & swiched_on_OVD_tmp;
  swiched_on_OVD = swiched_on_OVD_tmp;

  /***
  Перевірка, чи не вимкнутий зараз є канал по якому не проходи тест ОВД
  ***/
  {
    uint32_t temp_value = zdz_ovd_diagnostyka & (uint32_t)(~swiched_on_OVD);
    if (temp_value)
    {
      if (temp_value & (1 << 0))
      {
        zdz_ovd_diagnostyka &= (uint32_t)(~(1 << 0));
      
        _SET_BIT(clear_diagnostyka, TEST_OVD1);
      }
    
      if (temp_value & (1 << 1))
      {
        zdz_ovd_diagnostyka &= (uint32_t)(~(1 << 1));
      
        _SET_BIT(clear_diagnostyka, TEST_OVD2);
      }

      if (temp_value & (1 << 2))
      {
        zdz_ovd_diagnostyka &= (uint32_t)(~(1 << 2));
      
        _SET_BIT(clear_diagnostyka, TEST_OVD3);
      }
    }
  }
  /***/
   
  //Знімаємо стан з оптоприймача
  uint32_t light = (_DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD26_DD29) >> 12) & 0x7;

  /***
  Код програми, який відповідає за діагностику оптичної системи
  ***/
  if (test != 0)
  {
    //Стан діагностики
    zdz_ovd_diagnostyka = (light ^ test) & test;
    
    if (zdz_ovd_diagnostyka & (1 << 0)) _SET_BIT(set_diagnostyka, TEST_OVD1);
    else _SET_BIT(clear_diagnostyka, TEST_OVD1);
      
    if (zdz_ovd_diagnostyka & (1 << 1)) _SET_BIT(set_diagnostyka, TEST_OVD2);
    else _SET_BIT(clear_diagnostyka, TEST_OVD2);
      
    if (zdz_ovd_diagnostyka & (1 << 2)) _SET_BIT(set_diagnostyka, TEST_OVD3);
    else _SET_BIT(clear_diagnostyka, TEST_OVD3);
      
    //Так, як світло випромінювали ми своїм випромінювачем, то для логіки ми  його не приймаємо
    light &= (uint32_t)(~test);
    
    //Скидаємо тест
    test = 0;
  }
  
  //Відлік часу між послідовними запусками тестів ОВД
  delta_time_test += DELTA_TIME_FOR_TIMERS;
  
  //Фіксація початку нового тесту всіх ОВД
  if (
      (light == 0)
      &&  
      (
       (new_OVD) ||
       ( delta_time_test >= PERIOD_ZDZ_TEST)
      )   
     )   
  {
    new_OVD = 0; /*скидаємо фіксацію введення в роботу нового каналу*/
    delta_time_test = 0;
    
    //Починаємо тест
    test = swiched_on_OVD & 0x7;
  }

  if (test != 0) _DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD28) = (1 << 8) | ((test & 0xf) << 12);
  else _DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD28) = (((current_settings_prt.zdz_ovd_porig + 1) & 0xf) << 8);
  /***/

#endif  

  uint32_t logic_zdz_0 = 0;

  //!logic_zdz_0 |= (_CHECK_SET_BIT(p_active_functions, RANG_PUSK_ZDZ_VID_DV) != 0) << 0; //Пуск ЗДЗ от ДВ
  logic_zdz_0 |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_PUSK_ZDZ_VID_DV) != 0) << 0; //Пуск ЗДЗ от ДВ

  //!logic_zdz_0 |= (_CHECK_SET_BIT(p_active_functions, RANG_BLOCK_ZDZ) == 0) << 1; //Блок. ЗДЗ
  logic_zdz_0 |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_BLOCK_ZDZ) == 0) << 1; //Блок. ЗДЗ
  
  _AND2(control_zdz_tmp, CTR_ZDZ_STATE_BIT, logic_zdz_0, 1, logic_zdz_0, 2);
  _AND2(logic_zdz_0, 2, logic_zdz_0, 0, logic_zdz_0, 3);
  //"Св.ЗДЗ від ДВ"
  if (_GET_OUTPUT_STATE(logic_zdz_0, 3))
    //!_SET_BIT(p_active_functions, RANG_LIGHT_ZDZ_FROM_DV);
    _SET_BIT(p_active_functions, RNG_BIG_LIGHT_ZDZ_FROM_DV);
  else
    //!_CLEAR_BIT(p_active_functions, RANG_LIGHT_ZDZ_FROM_DV);
    _CLEAR_BIT(p_active_functions, RNG_BIG_LIGHT_ZDZ_FROM_DV);

#if (                                   \
     (MODYFIKACIA_VERSII_PZ == 0) ||    \
     (MODYFIKACIA_VERSII_PZ == 3)       \
    )   
  uint32_t zdz_ovd_diagnostyka_inv = (uint32_t)(~zdz_ovd_diagnostyka);
  _AND4(logic_zdz_0, 2, light, 0, zdz_ovd_diagnostyka_inv, 0, control_zdz_tmp, CTR_ZDZ_OVD1_STATE_BIT, logic_zdz_0, 4);
  //"Св.ЗДЗ від ОВД1"
  if (_GET_OUTPUT_STATE(logic_zdz_0, 4))
    //_SET_BIT(p_active_functions, RANG_LIGHT_ZDZ_FROM_OVD1);
    _SET_BIT(p_active_functions, RNG_BIG_LIGHT_ZDZ_FROM_OVD1);
  else
    //_CLEAR_BIT(p_active_functions, RANG_LIGHT_ZDZ_FROM_OVD1);
    _CLEAR_BIT(p_active_functions, RNG_BIG_LIGHT_ZDZ_FROM_OVD1);

  _AND4(logic_zdz_0, 2, light, 1, zdz_ovd_diagnostyka_inv, 1, control_zdz_tmp, CTR_ZDZ_OVD2_STATE_BIT, logic_zdz_0, 5);
  //"Св.ЗДЗ від ОВД2"
  if (_GET_OUTPUT_STATE(logic_zdz_0, 5))
    //_SET_BIT(p_active_functions, RANG_LIGHT_ZDZ_FROM_OVD2);
    _SET_BIT(p_active_functions, RNG_BIG_LIGHT_ZDZ_FROM_OVD2);
  else
    //_CLEAR_BIT(p_active_functions, RANG_LIGHT_ZDZ_FROM_OVD2);
    _CLEAR_BIT(p_active_functions, RNG_BIG_LIGHT_ZDZ_FROM_OVD2);

  _AND4(logic_zdz_0, 2, light, 2, zdz_ovd_diagnostyka_inv, 2, control_zdz_tmp, CTR_ZDZ_OVD3_STATE_BIT, logic_zdz_0, 6);
  //"Св.ЗДЗ від ОВД3"
  if (_GET_OUTPUT_STATE(logic_zdz_0, 6))
   // _SET_BIT(p_active_functions, RANG_LIGHT_ZDZ_FROM_OVD3);
    _SET_BIT(p_active_functions, RNG_BIG_LIGHT_ZDZ_FROM_OVD3);
  else
    //_CLEAR_BIT(p_active_functions, RANG_LIGHT_ZDZ_FROM_OVD3);
    _CLEAR_BIT(p_active_functions, RNG_BIG_LIGHT_ZDZ_FROM_OVD3);

  _OR4(logic_zdz_0, 3, logic_zdz_0, 4, logic_zdz_0, 5, logic_zdz_0, 6, logic_zdz_0, 7);
#else
  if (_GET_OUTPUT_STATE(logic_zdz_0, 3)) _SET_STATE(logic_zdz_0, 7);
#endif
  
  uint32_t logic_zdz_rez = 0;
  if (current_settings_prt.ctrl_zdz_type == ZDZ_CTRL_NONE)
  {
    logic_zdz_rez |= _GET_OUTPUT_STATE(logic_zdz_0, 7) << 0;
  }
  else if (current_settings_prt.ctrl_zdz_type < _ZDZ_CTRL_NUMBER)
  {
    if (
        (current_settings_prt.ctrl_zdz_type == ZDZ_CTRL_I) ||
        (current_settings_prt.ctrl_zdz_type == ZDZ_CTRL_I_OR_U) ||
        (current_settings_prt.ctrl_zdz_type == ZDZ_CTRL_I_AND_U)
       )   
    {
      if(
         (_GET_OUTPUT_STATE(control_zdz_tmp, (CTR_ZDZ_STARTED_FROM_MTZ1_BIT - (_CTR_ZDZ_PART_III - _CTR_ZDZ_PART_II))))
         &&
         (
          (_CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_MCZO1        ) != 0) ||//!(_CHECK_SET_BIT(p_active_functions, RANG_PO_MTZ1) != 0) ||
          (_CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_MCZON1_VPERED) != 0) ||//!(_CHECK_SET_BIT(p_active_functions, RANG_PO_MTZN1_VPERED) != 0) ||
          (_CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_MCZON1_NAZAD ) != 0) ||//!(_CHECK_SET_BIT(p_active_functions, RANG_PO_MTZN1_NAZAD) != 0) ||
          (_CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_MCZOPN1      ) != 0)   //!(_CHECK_SET_BIT(p_active_functions, RANG_PO_MTZPN1) != 0)
         ) 
        )   
      {
        _SET_STATE(logic_zdz_0, 8);
      }

      if(
         (_GET_OUTPUT_STATE(control_zdz_tmp, (CTR_ZDZ_STARTED_FROM_MTZ2_BIT - (_CTR_ZDZ_PART_III - _CTR_ZDZ_PART_II))))
         &&
         (
          (_CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_MCZO2        ) != 0) ||//!(_CHECK_SET_BIT(p_active_functions, RANG_PO_MTZ2) != 0) ||
          (_CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_MCZON2_VPERED) != 0) ||//!(_CHECK_SET_BIT(p_active_functions, RANG_PO_MTZN2_VPERED) != 0) ||
          (_CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_MCZON2_NAZAD ) != 0) ||//!(_CHECK_SET_BIT(p_active_functions, RANG_PO_MTZN2_NAZAD) != 0) ||
          (_CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_MCZOPN2      ) != 0)    //!(_CHECK_SET_BIT(p_active_functions, RANG_PO_MTZPN2) != 0)
         ) 
        )   
      {
        _SET_STATE(logic_zdz_0, 9);
      }

      if(
         (_GET_OUTPUT_STATE(control_zdz_tmp, (CTR_ZDZ_STARTED_FROM_MTZ3_BIT - (_CTR_ZDZ_PART_III - _CTR_ZDZ_PART_II))))
         &&
         (
          (_CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_MCZO3        ) != 0) ||//!(_CHECK_SET_BIT(p_active_functions, RANG_PO_MTZ3) != 0) ||
          (_CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_MCZON3_VPERED) != 0) ||//!(_CHECK_SET_BIT(p_active_functions, RANG_PO_MTZN3_VPERED) != 0) ||
          (_CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_MCZON3_NAZAD ) != 0) ||//!(_CHECK_SET_BIT(p_active_functions, RANG_PO_MTZN3_NAZAD) != 0) ||
          (_CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_MCZOPN3      ) != 0)   //!(_CHECK_SET_BIT(p_active_functions, RANG_PO_MTZPN3) != 0)
         ) 
        )   
      {
        _SET_STATE(logic_zdz_0, 10);
      }

      if(
         (_GET_OUTPUT_STATE(control_zdz_tmp, (CTR_ZDZ_STARTED_FROM_MTZ4_BIT - (_CTR_ZDZ_PART_III - _CTR_ZDZ_PART_II))))
         &&
         (
          (_CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_MCZO4           ) != 0) ||//!(_CHECK_SET_BIT(p_active_functions, RANG_PO_MTZ4) != 0) ||
          (_CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_MCZON4_VPERED   ) != 0) ||//!(_CHECK_SET_BIT(p_active_functions, RANG_PO_MTZN4_VPERED) != 0) ||
          (_CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_MCZON4_NAZAD    ) != 0) ||//!(_CHECK_SET_BIT(p_active_functions, RANG_PO_MTZN4_NAZAD) != 0) ||
          (_CHECK_SET_BIT(p_active_functions,RNG_BIG_PO_MCZOPN4         ) != 0)   //!(_CHECK_SET_BIT(p_active_functions, RANG_PO_MTZPN4) != 0)
         ) 
        )   
      {
        _SET_STATE(logic_zdz_0, 11);
      }
      
      _OR4(logic_zdz_0, 8, logic_zdz_0, 9, logic_zdz_0, 10, logic_zdz_0, 11, logic_zdz_0, 12);
    }

    if (
        (current_settings_prt.ctrl_zdz_type == ZDZ_CTRL_U) ||
        (current_settings_prt.ctrl_zdz_type == ZDZ_CTRL_I_OR_U) ||
        (current_settings_prt.ctrl_zdz_type == ZDZ_CTRL_I_AND_U)
       )   
    {
      if(
         (_GET_OUTPUT_STATE(control_zdz_tmp, (CTR_ZDZ_STARTED_FROM_UMIN1_BIT - (_CTR_ZDZ_PART_III - _CTR_ZDZ_PART_II)))) &&
         //!(_CHECK_SET_BIT(p_active_functions, RANG_PO_UMIN1) != 0)
         (_CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_UMIN1) != 0)
        )   
      {
        _SET_STATE(logic_zdz_0, 13);
      }
      
      if(
         (_GET_OUTPUT_STATE(control_zdz_tmp, (CTR_ZDZ_STARTED_FROM_UMIN2_BIT - (_CTR_ZDZ_PART_III - _CTR_ZDZ_PART_II)))) &&
         //!(_CHECK_SET_BIT(p_active_functions, RANG_PO_UMIN2) != 0)
         (_CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_UMIN2) != 0)
        )   
      {
        _SET_STATE(logic_zdz_0, 14);
      }
      
      _OR2(logic_zdz_0, 13, logic_zdz_0, 14, logic_zdz_0, 15);
    }

    if (current_settings_prt.ctrl_zdz_type == ZDZ_CTRL_I)
    {
      _AND2(logic_zdz_0, 7, logic_zdz_0, 12, logic_zdz_rez, 0);
    }
    else if (current_settings_prt.ctrl_zdz_type == ZDZ_CTRL_U)
    {
      _AND2(logic_zdz_0, 7, logic_zdz_0, 15, logic_zdz_rez, 0);
    }
    //!else if (current_settings_prt.ctrl_zdz_type == ZDZ_CTRL_3I0)
    //!{
    //!  if(
    //!     (_CHECK_SET_BIT(p_active_functions, RANG_PO_NZZ) != 0) ||
    //!     (_CHECK_SET_BIT(p_active_functions, RANG_PO_3I0) != 0)
    //!    )   
    //!  {
    //!    _SET_STATE(logic_zdz_0, 17);
    //!  }
    //!  _AND2(logic_zdz_0, 7, logic_zdz_0, 17, logic_zdz_rez, 0);
    //!}
    else
    {
      if (current_settings_prt.ctrl_zdz_type == ZDZ_CTRL_I_OR_U)
      {
        _OR2(logic_zdz_0, 12, logic_zdz_0, 15, logic_zdz_0, 16);
      }
      else if (current_settings_prt.ctrl_zdz_type == ZDZ_CTRL_I_AND_U)
      {
        _AND2(logic_zdz_0, 12, logic_zdz_0, 15, logic_zdz_0, 16);
      }
      else
      {
        //Якщо сюди дійшла програма, значить відбулася недопустива помилка, тому треба зациклити програму, щоб вона пішла на перезагрузку
        total_error_sw_fixed(88);
      }

      _AND2(logic_zdz_0, 7, logic_zdz_0, 16, logic_zdz_rez, 0);
    }
  }
  else
  {
    //Якщо сюди дійшла програма, значить відбулася недопустива помилка, тому треба зациклити програму, щоб вона пішла на перезагрузку
    total_error_sw_fixed(45);
  }
  
  //"ПО ЗДЗ"
  if (_GET_OUTPUT_STATE(logic_zdz_rez, 0))
    _SET_BIT(p_active_functions,RNG_BIG_PO_ZDZ);//_SET_BIT(p_active_functions, RANG_PO_ZDZ);
  else
    _CLEAR_BIT(p_active_functions,RNG_BIG_PO_ZDZ); //_CLEAR_BIT(p_active_functions, RANG_PO_ZDZ);
  
  _TIMER_T_0(INDEX_TIMER_ZDZ, current_settings_prt.timeout_zdz[number_group_stp], logic_zdz_rez, 0, logic_zdz_rez, 1);
  //"ЗДЗ"
  if (_GET_OUTPUT_STATE(logic_zdz_rez, 1))
    _SET_BIT(p_active_functions,RNG_BIG_ZDZ); //_SET_BIT(p_active_functions, RANG_ZDZ);
  else
    _CLEAR_BIT(p_active_functions,RNG_BIG_ZDZ);//_CLEAR_BIT(p_active_functions, RANG_ZDZ);
}
/*****************************************************/

/*****************************************************/
// ЗНМИН1
/*****************************************************/
void umin1_handler(unsigned int *p_active_functions, unsigned int number_group_stp)
{
  _Bool previous_state_po_umin1 = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_UMIN1) > 0;
  _Bool previous_state_po_ublk_umin1 = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_UBLK_UMIN1) > 0;
  _Bool previous_state_po_iblk_umin1 = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_IBLK_UMIN1) > 0;
  
  unsigned int setpoint1 = previous_state_po_umin1 ?
          current_settings_prt.setpoint_Umin1[number_group_stp] * U_DOWN / 100 :
          current_settings_prt.setpoint_Umin1[number_group_stp];
  
  _Bool Umn_is_smaller_than_Umin1 = measurement[IM_Umn] <= setpoint1;
  //!_Bool Ubp_is_smaller_than_Umin1 = measurement[IM_Ubp] <= setpoint1;
  
  unsigned int setpoint2 = previous_state_po_ublk_umin1 ?
          KOEF_MIN_UMIN * U_DOWN_1 / 100 : KOEF_MIN_UMIN;
          
  _Bool Umn_or_Ubp_is_smaller_than_250mV = (measurement[IM_Umn] <= setpoint2) ;//!|| (measurement[IM_Ubp] <= setpoint2)
  
  unsigned int setpoint3 = previous_state_po_iblk_umin1 ?
          current_settings_prt.setpoint_Umin1_Iblk[number_group_stp] * KOEF_POVERNENNJA_GENERAL_DOWN / 100 :
          current_settings_prt.setpoint_Umin1_Iblk[number_group_stp];
  
  _Bool Imn_and_Ibp_is_smaller_than_Iust = (measurement[IM_Imn] <= setpoint3); 
                                        //! &&(measurement[IM_Ibp] <= setpoint3);
  //М
  unsigned int tmp_value = ((current_settings_prt.control_transformator & MASKA_FOR_BIT(INDEX_ML_CTR_TRANSFORMATOR_PHASE_LINE)) == 0) << 0;
//  tmp_value |= ((current_settings_prt.control_Umin & CTR_EXTRA_SETTINGS_1_CTRL_PHASE_LINE) != 0)                                 << 1;
//  _INVERTOR(tmp_value, 1, tmp_value, 1);
  tmp_value |= ((current_settings_prt.control_Umin & CTR_UMIN1) != 0)                     << 2;
  tmp_value |= ((current_settings_prt.control_Umin & CTR_PO_UMIN1_OR_AND) != 0)           << 3;
  tmp_value |= ((current_settings_prt.control_Umin & CTR_UMIN1_UBLK) != 0)                << 4;
  tmp_value |= ((current_settings_prt.control_Umin & CTR_UMIN1_IBLK) != 0)                << 5;
  
  //ДВ
  tmp_value |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_BLOCK_UMIN1) != 0)             << 6;
  _INVERTOR(tmp_value, 6, tmp_value, 6);
  tmp_value |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_START_UMIN1) != 0)             << 7;
  
//  _AND2(tmp_value, 0, tmp_value, 1, tmp_value, 8);
  
 //!_AND2(Umn_is_smaller_than_Umin1, 0, Umn_is_smaller_than_Umin1, 0, tmp_value, 9);
  tmp_value |= (_GET_OUTPUT_STATE(Umn_is_smaller_than_Umin1, 0))<<9;
 //ПО Uблк. Umin1
    if (Umn_or_Ubp_is_smaller_than_250mV)
      _SET_BIT(p_active_functions, RNG_BIG_PO_UBLK_UMIN1);
    else
      _CLEAR_BIT(p_active_functions, RNG_BIG_PO_UBLK_UMIN1); 

  //ПО Iблк. Umin1
  if (Imn_and_Ibp_is_smaller_than_Iust)
    _SET_BIT(p_active_functions, RNG_BIG_PO_IBLK_UMIN1);
  else
    _CLEAR_BIT(p_active_functions, RNG_BIG_PO_IBLK_UMIN1);

  _AND2(tmp_value, 5, Imn_and_Ibp_is_smaller_than_Iust, 0, tmp_value, 12);
  _INVERTOR(tmp_value, 5, tmp_value, 5);
  _AND3(Umn_or_Ubp_is_smaller_than_250mV, 0, tmp_value, 4, tmp_value, 5, tmp_value, 13);

  _INVERTOR(tmp_value, 12, tmp_value, 12);
  _INVERTOR(tmp_value, 13, tmp_value, 13);
  _OR2(tmp_value, 7, tmp_value, 9,  tmp_value, 14);
  
  _AND5(tmp_value, 6, tmp_value, 2, tmp_value, 14, tmp_value, 13, tmp_value, 12, tmp_value, 15);
  

  
  //ПО Umin1
  if (_GET_OUTPUT_STATE(tmp_value, 15))
    _SET_BIT(p_active_functions, RNG_BIG_PO_UMIN1);
  else
    _CLEAR_BIT(p_active_functions, RNG_BIG_PO_UMIN1);
  
  _TIMER_T_0(INDEX_TIMER_UMIN1, current_settings_prt.timeout_Umin1[number_group_stp], tmp_value, 15, tmp_value, 16);
  
  //Сраб. Umin1
  if (_GET_OUTPUT_STATE(tmp_value, 16))
    _SET_BIT(p_active_functions, RNG_BIG_UMIN1);
  else
    _CLEAR_BIT(p_active_functions, RNG_BIG_UMIN1);
}
/*****************************************************/

/*****************************************************/
// ЗНМИН2
/*****************************************************/
void umin2_handler(unsigned int *p_active_functions, unsigned int number_group_stp)
{
  _Bool previous_state_po_umin2 = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_UMIN2) > 0;
  _Bool previous_state_po_ublk_umin2 = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_UBLK_UMIN2) > 0;
  _Bool previous_state_po_iblk_umin2 = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_IBLK_UMIN2) > 0;
  
  unsigned int setpoint1 = previous_state_po_umin2 ?
          current_settings_prt.setpoint_Umin2[number_group_stp] * U_DOWN / 100 :
          current_settings_prt.setpoint_Umin2[number_group_stp];
  
  _Bool Umn_is_smaller_than_Umin2 = measurement[IM_Umn] <= setpoint1;
//  _Bool Ubp_is_smaller_than_Umin2 = measurement[IM_Ubp] <= setpoint1;
  
  unsigned int setpoint2 = previous_state_po_ublk_umin2 ?
          KOEF_MIN_UMIN * U_DOWN_1 / 100 : KOEF_MIN_UMIN;
          
  _Bool Umn_or_Ubp_is_smaller_than_250mV = (measurement[IM_Umn] <= setpoint2);//! || (measurement[IM_Ubp] <= setpoint2);
  
  unsigned int setpoint3 = previous_state_po_iblk_umin2 ?
          current_settings_prt.setpoint_Umin2_Iblk[number_group_stp] * KOEF_POVERNENNJA_GENERAL_DOWN / 100 :
          current_settings_prt.setpoint_Umin2_Iblk[number_group_stp];
  
  _Bool Imn_and_Ibp_is_smaller_than_Iust = (measurement[IM_Imn] <= setpoint3) ;
                                         //&&(measurement[IM_Ibp] <= setpoint3);
  //М
  unsigned int tmp_value = ((current_settings_prt.control_transformator & MASKA_FOR_BIT(INDEX_ML_CTR_TRANSFORMATOR_PHASE_LINE)) == 0) << 0;
//  tmp_value |= ((current_settings_prt.control_Umin & CTR_EXTRA_SETTINGS_1_CTRL_PHASE_LINE) != 0)                                 << 1;
//  _INVERTOR(tmp_value, 1, tmp_value, 1);
  tmp_value |= ((current_settings_prt.control_Umin & CTR_UMIN2) != 0)                   << 2;
  tmp_value |= ((current_settings_prt.control_Umin & CTR_PO_UMIN2_OR_AND) != 0)         << 3;
  tmp_value |= ((current_settings_prt.control_Umin & CTR_UMIN2_UBLK) != 0)              << 4;
  tmp_value |= ((current_settings_prt.control_Umin & CTR_UMIN2_IBLK) != 0)              << 5;
  
  //ДВ
  tmp_value |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_BLOCK_UMIN2) != 0)           << 6;
  _INVERTOR(tmp_value, 6, tmp_value, 6);
  tmp_value |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_START_UMIN2) != 0)           << 7;
  
//  _AND2(tmp_value, 0, tmp_value, 1, tmp_value, 8);
/*  
  if (_GET_OUTPUT_STATE(tmp_value, 0))
  {
    //Фазные
    _AND3(Umn_is_smaller_than_Umin2, 0, Ubp_is_smaller_than_Umin2, 0, tmp_value, 3, tmp_value, 9);
    _OR2(Umn_is_smaller_than_Umin2, 0, Ubp_is_smaller_than_Umin2, 0, tmp_value, 10);
    _INVERTOR(tmp_value, 3, tmp_value, 3);
    _AND2(tmp_value, 10, tmp_value, 3, tmp_value, 11);
    _AND2(tmp_value, 5, Imn_and_Ibp_is_smaller_than_Iust, 0, tmp_value, 12);
    _INVERTOR(tmp_value, 5, tmp_value, 5);
    _AND3(Umn_or_Ubp_is_smaller_than_250mV, 0, tmp_value, 4, tmp_value, 5, tmp_value, 13);
    
    //ПО Uблк. Umin2
    if (Umn_or_Ubp_is_smaller_than_250mV)
      _SET_BIT(p_active_functions, RNG_BIG_PO_UBLK_UMIN2);
    else
      _CLEAR_BIT(p_active_functions, RNG_BIG_PO_UBLK_UMIN2);
    
  } 
  else 
  {
    //Линейные
    _AND3(Umn_is_smaller_than_Umin2, 0, Ubp_is_smaller_than_Umin2, 0, tmp_value, 3, tmp_value, 9);
    _OR2(Umn_is_smaller_than_Umin2, 0, Ubp_is_smaller_than_Umin2, 0, tmp_value, 10);
    _INVERTOR(tmp_value, 3, tmp_value, 3);
    _AND2(tmp_value, 10, tmp_value, 3, tmp_value, 11);
    _AND2(tmp_value, 5, Imn_and_Ibp_is_smaller_than_Iust, 0, tmp_value, 12);
    _INVERTOR(tmp_value, 5, tmp_value, 5);
    _AND3(Umn_or_Ubp_is_smaller_than_250mV, 0, tmp_value, 4, tmp_value, 5, tmp_value, 13);
    
    //ПО Uблк. Umin2
    if (Umn_or_Ubp_is_smaller_than_250mV)
      _SET_BIT(p_active_functions, RNG_BIG_PO_UBLK_UMIN2);
    else
      _CLEAR_BIT(p_active_functions, RNG_BIG_PO_UBLK_UMIN2);
  }*/

     tmp_value |= (_GET_OUTPUT_STATE(Umn_is_smaller_than_Umin2, 0))<<9;
    //ПО Uблк. Umin2
    if (Umn_or_Ubp_is_smaller_than_250mV)
      _SET_BIT(p_active_functions, RNG_BIG_PO_UBLK_UMIN2);
    else
      _CLEAR_BIT(p_active_functions, RNG_BIG_PO_UBLK_UMIN2);
  
  //ПО Iблк. Umin2
  if (Imn_and_Ibp_is_smaller_than_Iust)
    _SET_BIT(p_active_functions, RNG_BIG_PO_IBLK_UMIN2);
  else
    _CLEAR_BIT(p_active_functions, RNG_BIG_PO_IBLK_UMIN2);

  _AND2(tmp_value, 5, Imn_and_Ibp_is_smaller_than_Iust, 0, tmp_value, 12);
  _INVERTOR(tmp_value, 5, tmp_value, 5);
  _AND3(Umn_or_Ubp_is_smaller_than_250mV, 0, tmp_value, 4, tmp_value, 5, tmp_value, 13);
  


  _INVERTOR(tmp_value, 12, tmp_value, 12);
  _INVERTOR(tmp_value, 13, tmp_value, 13);
  _OR2(tmp_value, 7, tmp_value, 9, tmp_value, 14);
  
  _AND5(tmp_value, 6, tmp_value, 2, tmp_value, 14, tmp_value, 13, tmp_value, 12, tmp_value, 15);

  //ПО Umin2
  if (_GET_OUTPUT_STATE(tmp_value, 15))
    _SET_BIT(p_active_functions, RNG_BIG_PO_UMIN2);
  else
    _CLEAR_BIT(p_active_functions, RNG_BIG_PO_UMIN2);
  
  _TIMER_T_0(INDEX_TIMER_UMIN2, current_settings_prt.timeout_Umin2[number_group_stp], tmp_value, 15, tmp_value, 16);
  
  //Сраб. Umin2
  if (_GET_OUTPUT_STATE(tmp_value, 16))
    _SET_BIT(p_active_functions, RNG_BIG_UMIN2);
  else
    _CLEAR_BIT(p_active_functions, RNG_BIG_UMIN2);
}
/*****************************************************/

/*****************************************************/
// МТЗ04
/*****************************************************/
void dz_handler(unsigned int *p_active_functions, unsigned int number_group_stp)
{
	mf_of_handler(p_active_functions,number_group_stp);
	fault_U_handler(p_active_functions,number_group_stp);
	dz1_handler(p_active_functions,number_group_stp);
	dz2_handler(p_active_functions,number_group_stp);
	dz3_handler(p_active_functions,number_group_stp);
	dz4_handler(p_active_functions,number_group_stp);
}

/*****************************************************/
// ЗНМАКС1
/*****************************************************/
void umax1_handler(unsigned int *p_active_functions, unsigned int number_group_stp)
{
  _Bool previous_state_po_umax1 = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_UMAX1) > 0;
  
  unsigned int setpoint1 = previous_state_po_umax1 ?
          current_settings_prt.setpoint_Umax1[number_group_stp] * current_settings_prt.setpoint_kp_Umax[number_group_stp] / 100 :
          current_settings_prt.setpoint_Umax1[number_group_stp];
  
  _Bool Umn_is_larger_than_Umax1 = measurement[IM_Umn] >= setpoint1;
//  _Bool Ubp_is_larger_than_Umax1 = measurement[IM_Ubp] >= setpoint1;
  
  //М
  unsigned int tmp_value = ((current_settings_prt.control_transformator & MASKA_FOR_BIT(INDEX_ML_CTR_TRANSFORMATOR_PHASE_LINE)) == 0) << 0;
//  tmp_value |= ((current_settings_prt.control_Umax & CTR_EXTRA_SETTINGS_1_CTRL_PHASE_LINE) != 0)                                 << 1;
//  _INVERTOR(tmp_value, 1, tmp_value, 1);
  tmp_value |= ((current_settings_prt.control_Umax & CTR_PO_UMAX1_OR_AND) != 0)                             << 2;
  tmp_value |= ((current_settings_prt.control_Umax & CTR_UMAX1) != 0)                                       << 3;
  
  //ДВ
  tmp_value |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_BLOCK_UMAX1) != 0)                               << 4;
  
//  if (_GET_OUTPUT_STATE(tmp_value, 0)) {
//    _AND3(Umn_is_larger_than_Umax1, 0, Ubp_is_larger_than_Umax1, 0, tmp_value, 2, tmp_value, 5);
//    _OR2(Umn_is_larger_than_Umax1, 0, Ubp_is_larger_than_Umax1, 0, tmp_value, 6);
//  } else {
//    _AND3(Umn_is_larger_than_Umax1, 0, Ubp_is_larger_than_Umax1, 0, tmp_value, 2, tmp_value, 5);
//    _OR2(Umn_is_larger_than_Umax1, 0, Ubp_is_larger_than_Umax1, 0, tmp_value, 6);
//  }
  
  _INVERTOR(tmp_value, 2, tmp_value, 2);
//  _AND2(tmp_value, 6, tmp_value, 2, tmp_value, 7);
//  _OR2(tmp_value, 5, tmp_value, 7, tmp_value, 8);

   tmp_value |= (_GET_OUTPUT_STATE(Umn_is_larger_than_Umax1, 0))<<8;//_AND2(Umn_is_larger_than_Umax1, 0,Umn_is_larger_than_Umax1, 0, tmp_value, 8);
  _INVERTOR(tmp_value, 4, tmp_value, 4);  
  _AND3(tmp_value, 8, tmp_value, 4, tmp_value, 3, tmp_value, 9);
  
  //ПО Umax1
  if (_GET_OUTPUT_STATE(tmp_value, 9))
    _SET_BIT(p_active_functions, RNG_BIG_PO_UMAX1);
  else
    _CLEAR_BIT(p_active_functions, RNG_BIG_PO_UMAX1);
  
  _TIMER_T_0(INDEX_TIMER_UMAX1, current_settings_prt.timeout_Umax1[number_group_stp], tmp_value, 9, tmp_value, 10);
  
  //Сраб. Umax1
  if (_GET_OUTPUT_STATE(tmp_value, 10))
    _SET_BIT(p_active_functions, RNG_BIG_UMAX1);
  else
    _CLEAR_BIT(p_active_functions, RNG_BIG_UMAX1);
}
/*****************************************************/

/*****************************************************/
// ЗНМАКС2
/*****************************************************/
void umax2_handler(unsigned int *p_active_functions, unsigned int number_group_stp)
{
//  _Bool previous_state_po_umax2 = _CHECK_SET_BIT(p_active_functions, RANG_PO_UMAX2) > 0;
  _Bool previous_state_po_umax2 = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_UMAX2) > 0;
  
  unsigned int setpoint1 = previous_state_po_umax2 ?
          current_settings_prt.setpoint_Umax2[number_group_stp] * current_settings_prt.setpoint_kp_Umax[number_group_stp] / 100 :
          current_settings_prt.setpoint_Umax2[number_group_stp];
  
  _Bool Umn_is_larger_than_Umax2 = measurement[IM_Umn] >= setpoint1;
//  _Bool Ubp_is_larger_than_Umax2 = measurement[IM_Ubp] >= setpoint1;
  
  //М
  unsigned int tmp_value = ((current_settings_prt.control_transformator & MASKA_FOR_BIT(INDEX_ML_CTR_TRANSFORMATOR_PHASE_LINE)) == 0) << 0;
//  tmp_value |= ((current_settings_prt.control_Umax & CTR_EXTRA_SETTINGS_1_CTRL_PHASE_LINE) != 0)                                 << 1;
//  _INVERTOR(tmp_value, 1, tmp_value, 1);
  tmp_value |= ((current_settings_prt.control_Umax & CTR_PO_UMAX2_OR_AND) != 0)                               << 2;
  tmp_value |= ((current_settings_prt.control_Umax & CTR_UMAX2) != 0)                                         << 3;
  
  //ДВ
  //tmp_value |= (_CHECK_SET_BIT(p_active_functions, RANG_BLOCK_UMAX2) != 0)                                    << 4;
  tmp_value |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_BLOCK_UMAX2) != 0)                                    << 4;
  
//  if (_GET_OUTPUT_STATE(tmp_value, 0)) {
//    _AND3(Umn_is_larger_than_Umax2, 0, Ubp_is_larger_than_Umax2, 0, tmp_value, 2, tmp_value, 5);
//    _OR2(Umn_is_larger_than_Umax2, 0, Ubp_is_larger_than_Umax2, 0, tmp_value, 6);
//  } else {
//    _AND3(Umn_is_larger_than_Umax2, 0, Ubp_is_larger_than_Umax2, 0, tmp_value, 2, tmp_value, 5);
//    _OR2(Umn_is_larger_than_Umax2, 0, Ubp_is_larger_than_Umax2, 0, tmp_value, 6);
//  }
  
  _INVERTOR(tmp_value, 2, tmp_value, 2);
//  _AND2(tmp_value, 6, tmp_value, 2, tmp_value, 7);
//  _OR2(tmp_value, 5, tmp_value, 7, tmp_value, 8);
  tmp_value |= (_GET_OUTPUT_STATE(Umn_is_larger_than_Umax2, 0))<<8;//_AND2(Umn_is_larger_than_Umax2, 0,Umn_is_larger_than_Umax2, 0, tmp_value, 8);
  _INVERTOR(tmp_value, 4, tmp_value, 4);
  _AND3(tmp_value, 8, tmp_value, 4, tmp_value, 3, tmp_value, 9);
  
  //ПО Umax1
  if (_GET_OUTPUT_STATE(tmp_value, 9))
    _SET_BIT(p_active_functions, RNG_BIG_PO_UMAX2);
  else
    _CLEAR_BIT(p_active_functions, RNG_BIG_PO_UMAX2);
  
  _TIMER_T_0(INDEX_TIMER_UMAX2, current_settings_prt.timeout_Umax2[number_group_stp], tmp_value, 9, tmp_value, 10);
  
  //Сраб. Umax2
  if (_GET_OUTPUT_STATE(tmp_value, 10))
    _SET_BIT(p_active_functions, RNG_BIG_UMAX2);
  else
    _CLEAR_BIT(p_active_functions, RNG_BIG_UMAX2);
}
/*****************************************************/

/*****************************************************/
// АЧР ЧАПВ
/*****************************************************/
void achr_chapv_handler(unsigned int *p_active_functions, unsigned int number_group_stp)
{
//RANG_ACHR_CHAPV_VID_DV,
/*
  //пред сост ПО АЧР
  _Bool previous_state_po_f1_achr = _CHECK_SET_BIT(p_active_functions, RANG_PO_ACHR1);
  //пред сост ПО ЧАПВ
  _Bool previous_state_po_f1_chapv = _CHECK_SET_BIT(p_active_functions, RANG_PO_CHAPV1);
 // 
раздвоение
*/
  //пред сост ПО АЧР1
//!@  _Bool previous_state_po_f1_achr1  = _CHECK_SET_BIT(p_active_functions, @RANG_PO_ACHR1);
  _Bool previous_state_po_f1_achr1  = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_ACHR1);
  //пред сост ПО ЧАПВ1
//!@  _Bool previous_state_po_f1_chapv1 = _CHECK_SET_BIT(p_active_functions, @RANG_PO_CHAPV1);
  _Bool previous_state_po_f1_chapv1 = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_CHAPV1);
  //пред сост ПО АЧР2
//!@  _Bool previous_state_po_f1_achr2  = _CHECK_SET_BIT(p_active_functions, @RANG_PO_ACHR2);
  _Bool previous_state_po_f1_achr2  = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_ACHR2);
  //пред сост ПО ЧАПВ2
//!@  _Bool previous_state_po_f1_chapv2 = _CHECK_SET_BIT(p_active_functions, @RANG_PO_CHAPV2);
  _Bool previous_state_po_f1_chapv2 = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_CHAPV2);
//----------
/*
неизменно
*/

  unsigned int setpoint1 = previous_state_po_achr_chapv_umnf1 ?
          current_settings_prt.setpoint_achr_chapv_uf[number_group_stp] * U_UP / 100 :
          current_settings_prt.setpoint_achr_chapv_uf[number_group_stp];
          
  unsigned int setpoint2 = previous_state_po_achr_chapv_ubpf1 ?
          current_settings_prt.setpoint_achr_chapv_uf[number_group_stp] * U_UP / 100 :
          current_settings_prt.setpoint_achr_chapv_uf[number_group_stp];
  
  //Линейные
//  _Bool Uab_is_larger_than_UF1 = measurement[IM_UAB] >= setpoint1;
//  _Bool Ubc_is_larger_than_UF1 = measurement[IM_UBC] >= setpoint2;
//  _Bool Uca_is_larger_than_UF1 = measurement[IM_UCA] >= setpoint3;
  
  //Фазные
  _Bool Umn_is_larger_than_UF1 = measurement[IM_Umn] >= setpoint1;
  _Bool Ubp_is_larger_than_UF1 = measurement[IM_Ubp] >= setpoint2;
  
//  /*----------------Выбор фазные/линейные-------------------------------------*/
//  _Bool UF1_phase = ((current_settings_prt.control_extra_settings_1 & CTR_EXTRA_SETTINGS_1_CTRL_PHASE_LINE) == 0);
//  /*--------------------------------------------------------------------------*/
  
  _Bool timer1 = 0;
  _Bool UF1_is_larger_than_U_setpoint_F1 = 0;
//  _Bool UF1_is_smaller_than_U_setpoint_F1 = 0;
  //ПО ФАЗНЫЕ-ЛИНЕЙНЫЕ
//  if (UF1_phase)
//  {
    //ПО UAF1
    previous_state_po_achr_chapv_umnf1 = Umn_is_larger_than_UF1;
    //ПО UBF1
    previous_state_po_achr_chapv_ubpf1 = Ubp_is_larger_than_UF1;
    _AND2(Umn_is_larger_than_UF1, 0, Ubp_is_larger_than_UF1, 0, timer1, 0);
//  }
//  else 
//  {
//    //ПО UAF1
//    previous_state_po_achr_chapv_uaf1 = Uab_is_larger_than_UF1;
//    //ПО UBF1
//    previous_state_po_achr_chapv_ubf1 = Ubc_is_larger_than_UF1;
//    //ПО UCF1
//    previous_state_po_achr_chapv_ucf1 = Uca_is_larger_than_UF1;
//    _AND3(Uab_is_larger_than_UF1, 0, Ubc_is_larger_than_UF1, 0, Uca_is_larger_than_UF1, 0, timer1, 0);
//  }
  _TIMER_T_0(INDEX_TIMER_ACHR_CHAPV_100MS_1, TIMEOUT_ACHR_CHAPV_100MS, timer1, 0, UF1_is_larger_than_U_setpoint_F1, 0);
  //L1
//  UF1_is_smaller_than_U_setpoint_F1 = !UF1_is_larger_than_U_setpoint_F1;
 //L2, 3 
  int F1 = (int) (frequency * 100);
/*
  _Bool po_f1_achr_rab = F1 <= ((int)current_settings_prt.setpoint_achr1_f_rab[number_group_stp]);
  _Bool po_f1_chapv_rab = F1 >= ((int)current_settings_prt.setpoint_chapv1_f_rab[number_group_stp]);
  _Bool po_f1_achr = 0;
раздвоение
*/
  _Bool po_f1_achr1_rab = F1 <= ((int)current_settings_prt.setpoint_achr1_f_rab[number_group_stp]);
  _Bool po_f1_chapv1_rab = F1 >= ((int)current_settings_prt.setpoint_chapv1_f_rab[number_group_stp]);
  _Bool po_f1_achr1 = 0;
  _Bool po_f1_achr2_rab = F1 <= ((int)current_settings_prt.setpoint_achr2_f_rab[number_group_stp]);
  _Bool po_f1_chapv2_rab = F1 >= ((int)current_settings_prt.setpoint_chapv2_f_rab[number_group_stp]);
  _Bool po_f1_achr2 = 0;
//----------

/*  
  //ДВ
  unsigned int tmp_value = (_CHECK_SET_BIT(p_active_functions, RANG_BLOCK_ACHR1) != 0) << 0;
  //L5
  _INVERTOR(tmp_value, 0, tmp_value, 0);
раздвоение
*/
  //ДВ
  //!@unsigned int tmp_value1 = (_CHECK_SET_BIT(p_active_functions, @RANG_BLOCK_ACHR1) != 0) << 0;
  unsigned int tmp_value1 = (_CHECK_SET_BIT(p_active_functions, RNG_BIG_BLOCK_ACHR1) != 0) << 0;
  //L5.1
  _INVERTOR(tmp_value1, 0, tmp_value1, 0);
  //ДВ
  //!@unsigned int tmp_value2 = (_CHECK_SET_BIT(p_active_functions, @RANG_BLOCK_ACHR2) != 0) << 0;
  unsigned int tmp_value2 = (_CHECK_SET_BIT(p_active_functions, RNG_BIG_BLOCK_ACHR2) != 0) << 0;
  //L5
  _INVERTOR(tmp_value2, 0, tmp_value2, 0);
//----------

/*  
  //М
  tmp_value |= ((current_settings_prt.control_achr_chapv & CTR_ACHR1) != 0) << 1;
  //L4
  _AND3_INVERTOR(tmp_value, 0, tmp_value, 1, UF1_is_larger_than_U_setpoint_F1, 0, tmp_value, 3);
раздвоение
*/
  //М
  tmp_value1 |= ((current_settings_prt.control_achr_chapv & CTR_ACHR1) != 0) << 1;
  //L4.1
  _AND3_INVERTOR(tmp_value1, 0, tmp_value1, 1, UF1_is_larger_than_U_setpoint_F1, 0, tmp_value1, 3);
  //М
  tmp_value2 |= ((current_settings_prt.control_achr_chapv & CTR_ACHR2) != 0) << 1;
  //L4.2
  _AND3_INVERTOR(tmp_value2, 0, tmp_value2, 1, UF1_is_larger_than_U_setpoint_F1, 0, tmp_value2, 3);
//----------
/*
  //Reset канал L2
  if (!_GET_OUTPUT_STATE(tmp_value, 3))
  {
    //ПО АЧР1
    if (previous_state_po_f1_achr) 
    {
      //отпускание АЧР
//  _Bool po_f1_chapv_rab = F1 >= ((int)current_settings_prt.setpoint_chapv1_f_rab[number_group_stp]);
      if (!po_f1_chapv_rab) 
      {
        //после сработки 1 будет держаться до тех пор пока не сработает po_f1_chapv_rab (условие отпускания)
        _SET_BIT(p_active_functions, RANG_PO_ACHR1);
        po_f1_achr = 1;
      }
    }
    else
    {
      //сработка
//  _Bool po_f1_achr_rab = F1 <= ((int)current_settings_prt.setpoint_achr1_f_rab[number_group_stp]);
      
      if (po_f1_achr_rab)
      {
        _SET_BIT(p_active_functions, RANG_PO_ACHR1);
        po_f1_achr = 1;
      }
    }
  }//if
раздвоение
*/
//---1----
  //Reset канал L2
  if (!_GET_OUTPUT_STATE(tmp_value1, 3))
  {
    //ПО АЧР1
    if (previous_state_po_f1_achr1) 
    {
      //отпускание АЧР
//  _Bool po_f1_chapv_rab = F1 >= ((int)current_settings_prt.setpoint_chapv1_f_rab[number_group_stp]);
      if (!po_f1_chapv1_rab) 
      {
        //после сработки 1 будет держаться до тех пор пока не сработает po_f1_chapv_rab (условие отпускания)
        _SET_BIT(p_active_functions, RNG_BIG_PO_ACHR1);//!@_SET_BIT(p_active_functions, @RANG_PO_ACHR1);
        po_f1_achr1 = 1;
      }
      else _CLEAR_BIT(p_active_functions, RNG_BIG_PO_ACHR1);//!@_CLEAR_BIT(p_active_functions, @RANG_PO_ACHR1);
    }
    else
    {
      //сработка
//  _Bool po_f1_achr_rab = F1 <= ((int)current_settings_prt.setpoint_achr1_f_rab[number_group_stp]);
      
      if (po_f1_achr1_rab)
      {
        _SET_BIT(p_active_functions, RNG_BIG_PO_ACHR1);//!@_SET_BIT(p_active_functions, @RANG_PO_ACHR1);
        po_f1_achr1 = 1;
      }
      else _CLEAR_BIT(p_active_functions, RNG_BIG_PO_ACHR1);//!@_CLEAR_BIT(p_active_functions, @RANG_PO_ACHR1);
    }
  }//if
  else
  {
    _CLEAR_BIT(p_active_functions, RNG_BIG_PO_ACHR1);//!@_CLEAR_BIT(p_active_functions, @RANG_PO_ACHR1);
  }
//----2----
  //Reset канал L2
  if (!_GET_OUTPUT_STATE(tmp_value2, 3))
  {
    //ПО АЧР1
    if (previous_state_po_f1_achr2) 
    {
      //отпускание АЧР
//  _Bool po_f1_chapv_rab = F1 >= ((int)current_settings_prt.setpoint_chapv1_f_rab[number_group_stp]);
      if (!po_f1_chapv2_rab) 
      {
        //после сработки 1 будет держаться до тех пор пока не сработает po_f1_chapv_rab (условие отпускания)
        _SET_BIT(p_active_functions, RNG_BIG_PO_ACHR2);//!@_SET_BIT(p_active_functions, @RANG_PO_ACHR2);
        po_f1_achr2 = 1;
      }
      else _CLEAR_BIT(p_active_functions, RNG_BIG_PO_ACHR2);//!@_CLEAR_BIT(p_active_functions, @RANG_PO_ACHR2);
    }
    else
    {
      //сработка
//  _Bool po_f1_achr_rab = F1 <= ((int)current_settings_prt.setpoint_achr1_f_rab[number_group_stp]);
      
      if (po_f1_achr2_rab)
      {
        _SET_BIT(p_active_functions, RNG_BIG_PO_ACHR2);//!@_SET_BIT(p_active_functions, @RANG_PO_ACHR2);
        po_f1_achr2 = 1;
      }
      else _CLEAR_BIT(p_active_functions, RNG_BIG_PO_ACHR2);//!@_CLEAR_BIT(p_active_functions, @RANG_PO_ACHR2);
    }
  }//if
  else
  {
    _CLEAR_BIT(p_active_functions, RNG_BIG_PO_ACHR2);//!@_CLEAR_BIT(p_active_functions, @RANG_PO_ACHR2);
  }
//--------------  
/*
  _TIMER_T_0(INDEX_TIMER_ACHR1, current_settings_prt.timeout_achr_1[number_group_stp], po_f1_achr, 0, tmp_value, 5);
раздвоение
*/
//---1---
  _TIMER_T_0(INDEX_TIMER_ACHR1, current_settings_prt.timeout_achr_1[number_group_stp], po_f1_achr1, 0, tmp_value1, 5);
//---2---
  _TIMER_T_0(INDEX_TIMER_ACHR2, current_settings_prt.timeout_achr_2[number_group_stp], po_f1_achr2, 0, tmp_value2, 5);
//-------
  
  //Разр ЧАПВ
  if (UF1_is_larger_than_U_setpoint_F1)
    _SET_BIT(p_active_functions, RNG_BIG_RAZR_CHAPV);//!@_SET_BIT(p_active_functions, @RANG_RAZR_CHAPV);
  else
    _CLEAR_BIT(p_active_functions, RNG_BIG_RAZR_CHAPV);//!@_CLEAR_BIT(p_active_functions, @RANG_RAZR_CHAPV);

/*  
  _Bool tmp1 = 0;
  do 
  {
    //L7
    _OR2(tmp_value, 3, !trigger_CHAPV1, 0, tmp_value, 30);
    
    //ПО ЧАПВ1
    _Bool po_f1_chapv = 0;
    if (previous_state_po_f1_chapv) 
    {
      po_f1_chapv = !po_f1_achr_rab;
    }
    else 
    {
      po_f1_chapv = po_f1_chapv_rab;
    }
    //L3
    _Bool po_f1_chapv_tmp = (!_GET_OUTPUT_STATE(tmp_value, 30) && po_f1_chapv);
    if (po_f1_chapv_tmp) 
    {
      _SET_BIT(p_active_functions, RANG_PO_CHAPV1);
    }
    
    _TIMER_T_0(INDEX_TIMER_CHAPV1, current_settings_prt.timeout_chapv_1[number_group_stp], po_f1_chapv_tmp, 0, tmp_value, 6);
    //L8
    _AND2(po_f1_achr, 0, !po_f1_chapv_tmp, 0, tmp_value, 12);
    //L9
    _OR2(tmp_value, 5, tmp_value, 6, tmp_value, 13);

    _D_TRIGGER(_GET_OUTPUT_STATE(tmp_value, 12), 0, _GET_OUTPUT_STATE(UF1_is_smaller_than_U_setpoint_F1, 0), previous_states_CHAPV1, 0, tmp_value, 13, trigger_CHAPV1, 0);
    if (tmp1 == trigger_CHAPV1) break;
    
    tmp1 = trigger_CHAPV1;
  } 
  while(1);
раздвоение
*/
//----1----
  _Bool tmp1_1 = 0;
  do 
  {
    //L7_1
    _OR2(tmp_value1, 3, !trigger_CHAPV1, 0, tmp_value1, 30);
    
    //ПО ЧАПВ1
    _Bool po_f1_chapv1 = 0;
    if (previous_state_po_f1_chapv1) 
    {
      po_f1_chapv1 = !po_f1_achr1_rab;
    }
    else 
    {
      po_f1_chapv1 = po_f1_chapv1_rab;
    }
    //L3
    _Bool po_f1_chapv1_tmp = (!_GET_OUTPUT_STATE(tmp_value1, 30) && po_f1_chapv1);
    if (po_f1_chapv1_tmp) 
      _SET_BIT(p_active_functions, RNG_BIG_PO_CHAPV1);//!@_SET_BIT(p_active_functions, @RANG_PO_CHAPV1);
    else
      _CLEAR_BIT(p_active_functions, RNG_BIG_PO_CHAPV1);//!@_CLEAR_BIT(p_active_functions, @RANG_PO_CHAPV1);
    
    _TIMER_T_0(INDEX_TIMER_CHAPV1, current_settings_prt.timeout_chapv_1[number_group_stp], po_f1_chapv1_tmp, 0, tmp_value1, 6);
    //L8
    _AND2(po_f1_achr1, 0, !po_f1_chapv1_tmp, 0, tmp_value1, 12);
    //L9
    _OR2(tmp_value1, 5, tmp_value1, 6, tmp_value1, 13);

    _D_TRIGGER(_GET_OUTPUT_STATE(tmp_value1, 12), 0, _GET_OUTPUT_STATE(tmp_value1, 3), previous_states_CHAPV1, 0, tmp_value1, 13, trigger_CHAPV1, 0);
    if (tmp1_1 == trigger_CHAPV1) break;
    
    tmp1_1 = trigger_CHAPV1;
  } 
  while(1);
//----2----
  _Bool tmp1_2 = 0;
  do 
  {
    //L7_2
    _OR2(tmp_value2, 3, !trigger_CHAPV2, 0, tmp_value2, 30);
    
    //ПО ЧАПВ2
    _Bool po_f1_chapv2 = 0;
    if (previous_state_po_f1_chapv2) 
    {
      po_f1_chapv2 = !po_f1_achr2_rab;
    }
    else 
    {
      po_f1_chapv2 = po_f1_chapv2_rab;
    }
    //L3_2
    _Bool po_f1_chapv2_tmp = (!_GET_OUTPUT_STATE(tmp_value2, 30) && po_f1_chapv2);
    if (po_f1_chapv2_tmp) 
      _SET_BIT(p_active_functions, RNG_BIG_PO_CHAPV2);//!@_SET_BIT(p_active_functions, @RANG_PO_CHAPV2);
    else
      _CLEAR_BIT(p_active_functions, RNG_BIG_PO_CHAPV2);//!@_CLEAR_BIT(p_active_functions, @RANG_PO_CHAPV2);
    
    _TIMER_T_0(INDEX_TIMER_CHAPV2, current_settings_prt.timeout_chapv_2[number_group_stp], po_f1_chapv2_tmp, 0, tmp_value2, 6);
    //L8_2
    _AND2(po_f1_achr2, 0, !po_f1_chapv2_tmp, 0, tmp_value2, 12);
    //L9_2
    _OR2(tmp_value2, 5, tmp_value2, 6, tmp_value2, 13);

    _D_TRIGGER(_GET_OUTPUT_STATE(tmp_value2, 12), 0, _GET_OUTPUT_STATE(tmp_value2, 3), previous_states_CHAPV2, 0, tmp_value2, 13, trigger_CHAPV2, 0);
    if (tmp1_2 == trigger_CHAPV2) break;
    
    tmp1_2 = trigger_CHAPV2;
  } 
  while(1);
//---------
/*  
  //АЧР/ЧАПВ
  if (_GET_OUTPUT_STATE(trigger_CHAPV1, 0)) 
  {
    _SET_BIT(p_active_functions, RANG_ACHR_CHAPV1);
  }
  
  _Bool chapv_timer_1ms = 0;
  _Bool razr_chapv_inv = 0;
  _TIMER_0_T(INDEX_TIMER_CHAPV_1MS, TIMEOUT_CHAPV_1MS, trigger_CHAPV1, 0, chapv_timer_1ms, 0);
  _INVERTOR(UF1_is_larger_than_U_setpoint_F1, 0, razr_chapv_inv, 0);
  _AND2(chapv_timer_1ms, 0, razr_chapv_inv, 0, tmp_value, 24);
  _TIMER_0_T(INDEX_TIMER_BLOCK_CHAPV_5MS, TIMEOUT_BLOCK_CHAPV_5MS, tmp_value, 24, tmp_value, 25);
раздвоение
*/
//----1----
  //АЧР/ЧАПВ
  if (_GET_OUTPUT_STATE(trigger_CHAPV1, 0)) 
    _SET_BIT(p_active_functions, RNG_BIG_ACHR_CHAPV1);//!@_SET_BIT(p_active_functions, @RANG_ACHR_CHAPV1);
  else
    _CLEAR_BIT(p_active_functions, RNG_BIG_ACHR_CHAPV1);//!@_CLEAR_BIT(p_active_functions, @RANG_ACHR_CHAPV1);

//----2----
  //АЧР/ЧАПВ
  if (_GET_OUTPUT_STATE(trigger_CHAPV2, 0)) 
    _SET_BIT(p_active_functions, RNG_BIG_ACHR_CHAPV2);//!@_SET_BIT(p_active_functions, @RANG_ACHR_CHAPV2);
  else
    _CLEAR_BIT(p_active_functions, RNG_BIG_ACHR_CHAPV2);//!@_CLEAR_BIT(p_active_functions, @RANG_ACHR_CHAPV2);

  //Блокування ЧАПВ
  unsigned int tmp_value_g = 0;
  _TIMER_0_T(INDEX_TIMER_CHAPV1_1MS, TIMEOUT_CHAPV_1MS, trigger_CHAPV1, 0, tmp_value_g, 0);
  _TIMER_0_T(INDEX_TIMER_CHAPV2_1MS, TIMEOUT_CHAPV_1MS, trigger_CHAPV2, 0, tmp_value_g, 1);
  
  _AND2(tmp_value_g, 0, tmp_value1, 3, tmp_value_g, 2);
  _AND2(tmp_value_g, 1, tmp_value2, 3, tmp_value_g, 3);
  
  _TIMER_0_T(INDEX_TIMER_BLOCK_CHAPV1_5MS, TIMEOUT_BLOCK_CHAPV_5MS, tmp_value_g, 2, tmp_value_g, 4);
  _TIMER_0_T(INDEX_TIMER_BLOCK_CHAPV2_5MS, TIMEOUT_BLOCK_CHAPV_5MS, tmp_value_g, 3, tmp_value_g, 5);
  
  _OR2(tmp_value_g, 4, tmp_value_g, 5, tmp_value_g, 6);

  if (_GET_OUTPUT_STATE(tmp_value_g, 6))
      _SET_BIT(p_active_functions, RNG_BIG_VN_BLOCK_CHAPV);//!@_SET_BIT(p_active_functions, @RANG_VN_BLOCK_CHAPV);
  else
      _CLEAR_BIT(p_active_functions, RNG_BIG_VN_BLOCK_CHAPV);//!@_CLEAR_BIT(p_active_functions, @RANG_VN_BLOCK_CHAPV);
}

/*****************************************************/

/*****************************************************/
// Готовность к ТУ
/*****************************************************/
void ready_tu(unsigned int *p_active_functions)
{
//!  @unsigned int tmp_value = (_CHECK_SET_BIT(p_active_functions, @RANG_PRYVID_VV) == 0)                  << 0;
//!  @tmp_value |= (_CHECK_SET_BIT(p_active_functions, @RANG_VIDKL_VID_ZAKHYSTIV) != 0)                    << 1;
//!  @tmp_value |= (_CHECK_SET_BIT(p_active_functions, @RANG_RESET_BLOCK_READY_TU_VID_ZAHYSTIV) != 0)      << 2;
//!  @tmp_value |= (_CHECK_SET_BIT(p_active_functions, @RANG_AVAR_DEFECT) == 0)                            << 3;
//!  @tmp_value |= (_CHECK_SET_BIT(p_active_functions, @RANG_MISCEVE_DYSTANCIJNE) == 0)                    << 6;
  
  unsigned int tmp_value = (_CHECK_SET_BIT(p_active_functions, RNG_BIG_PRYVID_VVO) == 0)                  << 0;
  tmp_value |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_VIDKL_VID_ZAKHYSTIV_VVO) != 0)                 << 1;
  tmp_value |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_RESET_BLOCK_READY_TU_VID_ZAHYSTIV) != 0)      << 2;
  tmp_value |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_AVAR_DEFECT) == 0)                            << 3;
  tmp_value |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_MISCEVE_DYSTANCIJNE) == 0)                    << 6;
  
  _Bool ctrl_ready_tu = ((current_settings_prt.control_extra_settings_1 & CTR_EXTRA_SETTINGS_1_CTRL_READY_TU) == 0);
  
  if (!previous_states_ready_tu && _GET_OUTPUT_STATE(tmp_value, 1)) {
    previous_states_ready_tu = 0;
  }
  
  _OR2(tmp_value, 2, ctrl_ready_tu, 0, tmp_value, 7);
  _D_TRIGGER(1, 0, _GET_OUTPUT_STATE(tmp_value, 7), previous_states_ready_tu, 0, tmp_value, 1, trigger_ready_tu, 0);
  
  _AND4(tmp_value, 0, tmp_value, 3, !trigger_ready_tu, 0, tmp_value, 6, tmp_value, 5);
  
  //Готовность к ТУ
  if (_GET_OUTPUT_STATE(tmp_value, 5))
    _SET_BIT(p_active_functions, RNG_BIG_READY_TU);//!@_SET_BIT(p_active_functions, @RANG_READY_TU);
  else
    _CLEAR_BIT(p_active_functions, RNG_BIG_READY_TU);//!@_CLEAR_BIT(p_active_functions, @RANG_READY_TU);
}
/*****************************************************/

/*****************************************************/
// УРОВ
/*****************************************************/
inline void urov_handler(unsigned int *p_active_functions, unsigned int number_group_stp)
{
  /*******************************/
  //Визначаємо максимальний фазовий струм для УРОВ
  /*******************************/
  unsigned int max_faze_current = measurement[IM_Imn];
  //if (max_faze_current < measurement[IM_Ibp]) max_faze_current = measurement[IM_Ibp];
  /*******************************/
  
  /*******************************/
  uint32_t state_UROV = (( current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STATE)) != 0);
  uint32_t start_from_UP = false;
  if (
      (state_UROV != 0) &&
      ((current_settings_prt.control_urov & (((uint64_t)(MASKA_FOR_BIT(NUMBER_UP) - 1)) << INDEX_ML_CTRUROV_STARTED_FROM_UP1)) != 0)
     )   
  {
    //Налаштовано запуск ПРЗЗ від УЗ
    for (size_t n_UP = 0; n_UP < NUMBER_UP; n_UP++)
    {
      if ( 
          ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_UP1 + n_UP)) != 0) && 
          //(_CHECK_SET_BIT(p_active_functions, (RANG_UP1 + 3*n_UP)      ) != 0)
          (_CHECK_SET_BIT(p_active_functions, (RNG_BIG_UP1 + 3*n_UP)      ) != 0)
         )
      {
        start_from_UP = true;
      }
    }
  }
  
  if(
     (state_UROV != 0) &&
     (
      (start_from_UP == true) ||
      //(_CHECK_SET_BIT(p_active_functions, RANG_PUSK_UROV_VID_DV) != 0) ||
      (_CHECK_SET_BIT(p_active_functions, RNG_BIG_PUSK_UROV_VID_DV) != 0) ||
        
//      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_DZ1)    ) != 0) && (_CHECK_SET_BIT(p_active_functions, RANG_DZ1              ) != 0)) ||
//      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_AMTDZ1) ) != 0) && (_CHECK_SET_BIT(p_active_functions, RANG_AMTZ_DZ1         ) != 0)) ||
//      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_DZ2)    ) != 0) && (_CHECK_SET_BIT(p_active_functions, RANG_DZ2              ) != 0)) ||
//      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_AMTDZ2) ) != 0) && (_CHECK_SET_BIT(p_active_functions, RANG_AMTZ_DZ2         ) != 0)) ||
//      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_DZ3)    ) != 0) && (_CHECK_SET_BIT(p_active_functions, RANG_DZ3              ) != 0)) ||
//      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_AMTDZ3) ) != 0) && (_CHECK_SET_BIT(p_active_functions, RANG_AMTZ_DZ3         ) != 0)) ||
//      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_DZ4)    ) != 0) && (_CHECK_SET_BIT(p_active_functions, RANG_DZ4              ) != 0)) ||
//      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_AMTDZ4) ) != 0) && (_CHECK_SET_BIT(p_active_functions, RANG_AMTZ_DZ4         ) != 0)) ||
        
      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_DZ1)    ) != 0) && (_CHECK_SET_BIT(p_active_functions, RNG_BIG_DZO1              ) != 0)) ||
      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_AMTDZ1) ) != 0) && (_CHECK_SET_BIT(p_active_functions, RNG_BIG_AMCZ_DZO1         ) != 0)) ||
      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_DZ2)    ) != 0) && (_CHECK_SET_BIT(p_active_functions, RNG_BIG_DZO2              ) != 0)) ||
      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_AMTDZ2) ) != 0) && (_CHECK_SET_BIT(p_active_functions, RNG_BIG_AMCZ_DZO2         ) != 0)) ||
      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_DZ3)    ) != 0) && (_CHECK_SET_BIT(p_active_functions, RNG_BIG_DZO3              ) != 0)) ||
      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_AMTDZ3) ) != 0) && (_CHECK_SET_BIT(p_active_functions, RNG_BIG_AMCZ_DZO3         ) != 0)) ||
      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_DZ4)    ) != 0) && (_CHECK_SET_BIT(p_active_functions, RNG_BIG_DZO4              ) != 0)) ||
      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_AMTDZ4) ) != 0) && (_CHECK_SET_BIT(p_active_functions, RNG_BIG_AMCZ_DZO4         ) != 0)) ||
        
      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_MTZ1)   ) != 0) && (_CHECK_SET_BIT(p_active_functions, RNG_BIG_MCZO1             ) != 0)) ||
      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_MTZ2)   ) != 0) && (_CHECK_SET_BIT(p_active_functions, RNG_BIG_MCZO2             ) != 0)) ||
      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_MTZ3)   ) != 0) && (_CHECK_SET_BIT(p_active_functions, RNG_BIG_MCZO3             ) != 0)) ||
      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_MTZ4)   ) != 0) && (_CHECK_SET_BIT(p_active_functions, RNG_BIG_MCZO4             ) != 0)) ||
        
      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_ZDZ)    ) != 0) && (_CHECK_SET_BIT(p_active_functions, RNG_BIG_ZDZ              ) != 0)) ||
        
//      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_3I0)    ) != 0) && (_CHECK_SET_BIT(p_active_functions, RANG_3I0              ) != 0)) ||
//      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_3U0)    ) != 0) && (_CHECK_SET_BIT(p_active_functions, RANG_3U0              ) != 0)) ||
//      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_NZZ)    ) != 0) && (_CHECK_SET_BIT(p_active_functions, RANG_NZZ              ) != 0)) ||
        
//      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_TZNP1)  ) != 0) && (_CHECK_SET_BIT(p_active_functions, RANG_TZNP1            ) != 0)) ||
//      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_TZNP2)  ) != 0) && (_CHECK_SET_BIT(p_active_functions, RANG_TZNP2            ) != 0)) ||
//      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_TZNP3)  ) != 0) && (_CHECK_SET_BIT(p_active_functions, RANG_TZNP3            ) != 0)) ||
        
//      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_ZOP1)   ) != 0) && (_CHECK_SET_BIT(p_active_functions, RANG_ZOP              ) != 0)) ||
        
      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_UMIN1)  ) != 0) && (_CHECK_SET_BIT(p_active_functions, RNG_BIG_UMIN1            ) != 0)) ||
      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_UMIN2)  ) != 0) && (_CHECK_SET_BIT(p_active_functions, RNG_BIG_UMIN2            ) != 0)) ||
        
      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_UMAX1)  ) != 0) && (_CHECK_SET_BIT(p_active_functions, RNG_BIG_UMAX1            ) != 0)) ||
      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_UMAX2)  ) != 0) && (_CHECK_SET_BIT(p_active_functions, RNG_BIG_UMAX2            ) != 0)) ||
        
      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_ACHR1)  ) != 0) && (_CHECK_SET_BIT(p_active_functions, RNG_BIG_ACHR_CHAPV1      ) != 0)) ||
      ( ((current_settings_prt.control_urov & MASKA64_FOR_BIT(INDEX_ML_CTRUROV_STARTED_FROM_ACHR2)  ) != 0) && (_CHECK_SET_BIT(p_active_functions, RNG_BIG_ACHR_CHAPV2      ) != 0))
     )     
    )
  {
    //Є умова запуску УРОВ
    
    unsigned int setpoint; //уставка - з якою зрівнюється вимірювальна величина
    unsigned int previous_state_po_urov;
    
    //Якщо ПО УРОВ ще не активне, то треба працювати по устаці спацювання - уставці, яка вводиться як основна з системи меню чи верхнього рівня
    //Якщо ПО УРОВ вже спрацювало, то треба працювати по уставці відпускання - береться процент від основної утанки по коефіцієнту повернення
    //if(( previous_state_po_urov = _CHECK_SET_BIT(p_active_functions, RANG_PO_UROV) ) ==0 )
    if(( previous_state_po_urov = _CHECK_SET_BIT(p_active_functions, RNG_BIG_PO_UROV) ) ==0 )
    {
      //Працюємо по утавці спрацювання
      setpoint = current_settings_prt.setpoint_urov[number_group_stp];
    }
    else
    {
      //Працюємо по утавці відпускання
      setpoint = current_settings_prt.setpoint_urov[number_group_stp]*KOEF_POVERNENNJA_GENERAL_UP/100;
    }
    
    //Виставляємо, або скидаємо сигнал "ПО УРОВ"
    if (max_faze_current >= setpoint)
    {
      //Максимальний фазний стум перевищує свою уставку
      if(previous_state_po_urov == 0)
      {
        //Встановлюємо сигнал "ПО УРОВ"
        //_SET_BIT(p_active_functions, RANG_PO_UROV);
        _SET_BIT(p_active_functions, RNG_BIG_PO_UROV);
      
        //Запускаємо таймери УРОВ1 і УРОВ2, якщо вони ще не запущені
        global_timers[INDEX_TIMER_UROV1] = 0;
        global_timers[INDEX_TIMER_UROV2] = 0;
      }
    }
    else 
    {
      //Максимальний фазний стум нижче уставки
      if(previous_state_po_urov != 0)
      {
        //Скидаємо сигнал "ПО УРОВ"
        _CLEAR_BIT(p_active_functions, RNG_BIG_PO_UROV);//_CLEAR_BIT(p_active_functions, RANG_PO_UROV);
        //Це є умовою також скидання сигналів "Сраб. УРОВ1" і "Сраб. УРОВ2"
        _CLEAR_BIT(p_active_functions, RNG_BIG_UROV1);  //_CLEAR_BIT(p_active_functions, RANG_UROV1);
        _CLEAR_BIT(p_active_functions, RNG_BIG_UROV2);  //_CLEAR_BIT(p_active_functions, RANG_UROV2);
        //Якщо таймери ще не скинуті, то скидаємо їх
        if ( global_timers[INDEX_TIMER_UROV1] >=0) global_timers[INDEX_TIMER_UROV1] = -1;
        if ( global_timers[INDEX_TIMER_UROV2] >=0) global_timers[INDEX_TIMER_UROV2] = -1;
      }
    }
    
    //Перевіряємо чи таймер УРОВ1 досягнув значення своєї витримки
    if(global_timers[INDEX_TIMER_UROV1] >= current_settings_prt.timeout_urov_1[number_group_stp])
    {
      //Якщо витримана Витримка УРОВ1 то встановлюємо сигнал "Сраб. УРОВ1"
      _SET_BIT(p_active_functions, RNG_BIG_UROV1);//_SET_BIT(p_active_functions, RANG_UROV1);

      //Скидаємо таймер УРОВ1
      global_timers[INDEX_TIMER_UROV1] = -1;
    }

    //Перевіряємо чи таймер УРОВ2 досягнув значення своєї витримки
    if(global_timers[INDEX_TIMER_UROV2] >= current_settings_prt.timeout_urov_2[number_group_stp])
    {
      //Якщо витримана Витримка УРОВ2 то встановлюємо сигнал "Сраб. УРОВ2"
      _SET_BIT(p_active_functions, RNG_BIG_UROV2);//_SET_BIT(p_active_functions, RANG_UROV2);

      //Скидаємо таймер УРОВ2
      global_timers[INDEX_TIMER_UROV2] = -1;
    }
  }
  else
  {
    //Треба скинути всі таймери і сигнали, які за УРОВ відповідають
    _CLEAR_BIT(p_active_functions, RNG_BIG_PO_UROV);//_CLEAR_BIT(p_active_functions, RANG_PO_UROV);
    _CLEAR_BIT(p_active_functions, RNG_BIG_UROV1);  //_CLEAR_BIT(p_active_functions, RANG_UROV1);
    _CLEAR_BIT(p_active_functions, RNG_BIG_UROV2);  //_CLEAR_BIT(p_active_functions, RANG_UROV2);
    global_timers[INDEX_TIMER_UROV1] = -1;
    global_timers[INDEX_TIMER_UROV2] = -1;
  }  
}
  /*******************************/
/*****************************************************/

/*****************************************************/
//АПВ
/*****************************************************/
inline void apv_handler(unsigned int *p_active_functions, unsigned int number_group_stp)
{
  unsigned int logic_APV_0 = 0;
  unsigned int logic_APV_1 = 0;
  unsigned int logic_APV_2 = 0;
  unsigned int logic_APV_3 = 0;

  //Рестарт пристрою
  logic_APV_1 |= (start_restart != 0) << 19;
  //Очищаємо повідомлення про рестрат пристрою
  start_restart = 0;

  //"Стан вимикача"
  //logic_APV_0 |= (_CHECK_SET_BIT(p_active_functions, RANG_STATE_VV) != 0) << 21;
  logic_APV_0 |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_STATE_VVO) != 0) << 21;
  _TIMER_IMPULSE(INDEX_TIMER_APV_BLOCK_VID_VV, current_settings_prt.timeout_apv_block_vid_VV[number_group_stp], previous_states_APV_0, 0, logic_APV_0, 21, logic_APV_0, 22);

  //"Статичне блокування"
  //logic_APV_0 |= (_CHECK_SET_BIT(p_active_functions, RANG_STAT_BLK_APV) != 0) << 0;
  logic_APV_0 |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_STAT_BLK_APV) != 0) << 0;
  _INVERTOR(logic_APV_0, 0, logic_APV_0, 1);

  //М:"Пуск від МТЗ1"
  logic_APV_0 |= ((current_settings_prt.control_apv & CTR_APV_STARTED_FROM_MTZ1) != 0) << 2;
  //"МТЗ1"
  //logic_APV_0 |= (_CHECK_SET_BIT(p_active_functions, RANG_MTZ1) != 0) << 3;
  logic_APV_0 |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_MCZO1) != 0) << 3;
  _AND2(logic_APV_0, 2, logic_APV_0, 3, logic_APV_0, 4);

  //М:"Пуск від МТЗ2"
  logic_APV_0 |= ((current_settings_prt.control_apv & CTR_APV_STARTED_FROM_MTZ2) != 0) << 5;
  //"МТЗ2"
  //logic_APV_0 |= (_CHECK_SET_BIT(p_active_functions, RANG_MTZ2) != 0) << 6;
  logic_APV_0 |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_MCZO2) != 0) << 6;
  _AND2(logic_APV_0, 5, logic_APV_0, 6, logic_APV_0, 7);

  //М:"Пуск від МТЗ3"
  logic_APV_0 |= ((current_settings_prt.control_apv & CTR_APV_STARTED_FROM_MTZ3) != 0) << 8;
  //"МТЗ3"
  //logic_APV_0 |= (_CHECK_SET_BIT(p_active_functions, RANG_MTZ3) != 0) << 9;
  logic_APV_0 |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_MCZO3) != 0) << 9;
  _AND2(logic_APV_0, 8, logic_APV_0, 9, logic_APV_0, 10);

  //М:"Пуск від МТЗ4"
  logic_APV_0 |= ((current_settings_prt.control_apv & CTR_APV_STARTED_FROM_MTZ4) != 0) << 11;
  //"МТЗ4"
  //logic_APV_0 |= (_CHECK_SET_BIT(p_active_functions, RANG_MTZ4) != 0) << 12;
  logic_APV_0 |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_MCZO4) != 0) << 12;
  _AND2(logic_APV_0, 11, logic_APV_0, 12, logic_APV_0, 13);
  
  /***/

  //М:"Пуск від ДЗ1"
  logic_APV_1 |= ((current_settings_prt.control_apv & CTR_APV_STARTED_FROM_DZ1) != 0) << 30;
  //"ДЗ1"
  //logic_APV_1 |= (_CHECK_SET_BIT(p_active_functions, RANG_DZ1) != 0) << 31;
  logic_APV_1 |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_DZO1) != 0) << 31;
  _AND2(logic_APV_1, 30, logic_APV_1, 31, logic_APV_2, 20);

  //М:"Пуск від ДЗ2"
  logic_APV_2 |= ((current_settings_prt.control_apv & CTR_APV_STARTED_FROM_DZ2) != 0) << 0;
  //"ДЗ2"
  //logic_APV_2 |= (_CHECK_SET_BIT(p_active_functions, RANG_DZ2) != 0) << 1;
  logic_APV_2 |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_DZO2) != 0) << 1;
  _AND2(logic_APV_2, 0, logic_APV_2, 1, logic_APV_2, 21);

  //М:"Пуск від ДЗ3"
  logic_APV_2 |= ((current_settings_prt.control_apv & CTR_APV_STARTED_FROM_DZ3) != 0) << 2;
  //"ДЗ3"
  //logic_APV_2 |= (_CHECK_SET_BIT(p_active_functions, RANG_DZ3) != 0) << 3;
  logic_APV_2 |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_DZO3) != 0) << 3;
  _AND2(logic_APV_2, 2, logic_APV_2, 3, logic_APV_2, 22);

  //М:"Пуск від ДЗ4"
  logic_APV_2 |= ((current_settings_prt.control_apv & CTR_APV_STARTED_FROM_DZ4) != 0) << 4;
  //"ДЗ4"
  //logic_APV_2 |= (_CHECK_SET_BIT(p_active_functions, RANG_DZ4) != 0) << 5;
  logic_APV_2 |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_DZO4) != 0) << 5;
  _AND2(logic_APV_2, 4, logic_APV_2, 5, logic_APV_2, 23);

  _OR4(logic_APV_2, 20, logic_APV_2, 21, logic_APV_2, 22, logic_APV_2, 23, logic_APV_2, 31);

  //М:"Пуск від АМСЗ1"
  logic_APV_2 |= ((current_settings_prt.control_apv & CTR_APV_STARTED_FROM_AMTDZ1) != 0) << 6;
  //"АМСЗ1"
  //logic_APV_2 |= (_CHECK_SET_BIT(p_active_functions, RANG_AMTZ_DZ1) != 0) << 7;
  logic_APV_2 |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_AMCZ_DZO1) != 0) << 7;
  _AND2(logic_APV_2, 6, logic_APV_2, 7, logic_APV_2, 24);

  //М:"Пуск від АМСЗ2"
  logic_APV_2 |= ((current_settings_prt.control_apv & CTR_APV_STARTED_FROM_AMTDZ2) != 0) << 8;
  //"АМСЗ2"
  //logic_APV_2 |= (_CHECK_SET_BIT(p_active_functions, RANG_AMTZ_DZ2) != 0) << 9;
  logic_APV_2 |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_AMCZ_DZO2) != 0) << 9;
  _AND2(logic_APV_2, 8, logic_APV_2, 9, logic_APV_2, 25);

  //М:"Пуск від АМСЗ3"
  logic_APV_2 |= ((current_settings_prt.control_apv & CTR_APV_STARTED_FROM_AMTDZ3) != 0) << 10;
  //"АМСЗ3"
  //logic_APV_2 |= (_CHECK_SET_BIT(p_active_functions, RANG_AMTZ_DZ3) != 0) << 11;
  logic_APV_2 |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_AMCZ_DZO3) != 0) << 11;
  _AND2(logic_APV_2, 10, logic_APV_2, 11, logic_APV_2, 26);

  //М:"Пуск від АМСЗ4"
  logic_APV_2 |= ((current_settings_prt.control_apv & CTR_APV_STARTED_FROM_AMTDZ4) != 0) << 12;
  //"АМСЗ4"
  //logic_APV_2 |= (_CHECK_SET_BIT(p_active_functions, RANG_AMTZ_DZ4) != 0) << 13;
  logic_APV_2 |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_AMCZ_DZO4) != 0) << 13;
  _AND2(logic_APV_2, 12, logic_APV_2, 13, logic_APV_2, 27);

  _OR4(logic_APV_2, 24, logic_APV_2, 25, logic_APV_2, 26, logic_APV_2, 27, logic_APV_3, 0);

  //М:"Пуск від СЗНП1"
//  logic_APV_2 |= ((current_settings_prt.control_apv & CTR_APV_STARTED_FROM_TZNP1) != 0) << 14;
//  //"СЗНП1"
//  //logic_APV_2 |= (_CHECK_SET_BIT(p_active_functions, RANG_TZNP1) != 0) << 15;
//  logic_APV_2 |= (_CHECK_SET_BIT(p_active_functions, RANG_TZNP1) != 0) << 15;
//  _AND2(logic_APV_2, 14, logic_APV_2, 15, logic_APV_2, 28);

  //М:"Пуск від СЗНП2"
//  logic_APV_2 |= ((current_settings_prt.control_apv & CTR_APV_STARTED_FROM_TZNP2) != 0) << 16;
//  //"СЗНП2"
//  //logic_APV_2 |= (_CHECK_SET_BIT(p_active_functions, RANG_TZNP2) != 0) << 17;
//  logic_APV_2 |= (_CHECK_SET_BIT(p_active_functions, RANG_TZNP2) != 0) << 17;
//  _AND2(logic_APV_2, 16, logic_APV_2, 17, logic_APV_2, 29);

  //М:"Пуск від СЗНП3"
//  logic_APV_2 |= ((current_settings_prt.control_apv & CTR_APV_STARTED_FROM_TZNP3) != 0) << 18;
//  //"СЗНП3"
//  //logic_APV_2 |= (_CHECK_SET_BIT(p_active_functions, RANG_TZNP3) != 0) << 19;
//  logic_APV_2 |= (_CHECK_SET_BIT(p_active_functions, RANG_TZNP3) != 0) << 19;
//  _AND2(logic_APV_2, 18, logic_APV_2, 19, logic_APV_2, 30);
  
  _OR3(logic_APV_2, 28, logic_APV_2, 29, logic_APV_2, 30, logic_APV_3, 1);
  /***/
  
  _OR4(logic_APV_0,  4, logic_APV_0,  7, logic_APV_0, 10, logic_APV_0, 13, logic_APV_0, 14);
  _OR4(logic_APV_0, 14, logic_APV_2, 31, logic_APV_3,  0, logic_APV_3,  1, logic_APV_3,  2);

  //М:"Блок.контр.ст.ВВ"
  logic_APV_3 |= ((current_settings_prt.control_apv & CTR_APV_CTRAPV_BLK_CTRL_VV) != 0) << 11;
  _INVERTOR(logic_APV_3, 11, logic_APV_3, 12);
  _AND2(logic_APV_0, 21, logic_APV_3, 11, logic_APV_3, 13);
  _OR3(logic_APV_3, 13, logic_APV_3, 12, previous_states_APV_0, 9, logic_APV_3, 3);
  _AND2(logic_APV_3, 2, logic_APV_3, 3, previous_states_APV_0, 9);

  _TIMER_0_T(INDEX_TIMER_APV_TMP1, 1, previous_states_APV_0, 9, logic_APV_0, 15);

  //М:"ЧАПВ 1"
  logic_APV_0 |= ((current_settings_prt.control_achr_chapv & CTR_CHAPV1) != 0) << 16;
  //"АЧР/ЧАПВ 1"
  //logic_APV_1 |= (_CHECK_SET_BIT(p_active_functions, RANG_ACHR_CHAPV1) != 0) << 21;
  logic_APV_1 |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_ACHR_CHAPV1) != 0) << 21;
  //М:"ЧАПВ 2"
  logic_APV_1 |= ((current_settings_prt.control_achr_chapv & CTR_CHAPV2) != 0) << 27;
  //"АЧР/ЧАПВ 2"
  //logic_APV_1 |= (_CHECK_SET_BIT(p_active_functions, RANG_ACHR_CHAPV2) != 0) << 28;
  logic_APV_1 |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_ACHR_CHAPV2) != 0) << 28;
  //"Разр ЧАПВ"
  //logic_APV_1 |= (_CHECK_SET_BIT(p_active_functions, RANG_RAZR_CHAPV) != 0) << 20;
  logic_APV_1 |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_RAZR_CHAPV) != 0) << 20;

  //"АЧР/ЧАПВ від ДВ"
  //logic_APV_0 |= (_CHECK_SET_BIT(p_active_functions, RANG_ACHR_CHAPV_VID_DV) != 0) << 17;
  logic_APV_0 |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_ACHR_CHAPV_VID_DV) != 0) << 17;
  //М:"ЧАПВ від ДВ"
  logic_APV_1 |= ((current_settings_prt.control_achr_chapv & CTR_CHAPV_VID_DV) != 0) << 22;
  
  _AND3(logic_APV_0, 16, logic_APV_1, 21, logic_APV_1, 20, logic_APV_1, 23);
  _AND3(logic_APV_1, 27, logic_APV_1, 28, logic_APV_1, 20, logic_APV_1, 29);
  _AND2(logic_APV_0, 17, logic_APV_1, 22, logic_APV_1, 24);
  _OR3(logic_APV_1, 23, logic_APV_1, 29, logic_APV_1, 24, logic_APV_0, 18)

  //"Блок.ЧАПВ"
  //logic_APV_1 |= (_CHECK_SET_BIT(p_active_functions, RANG_VN_BLOCK_CHAPV) != 0) << 25;
  logic_APV_1 |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_VN_BLOCK_CHAPV) != 0) << 25;
  _OR2(logic_APV_0, 18, logic_APV_1, 25, logic_APV_1, 26);
    
  _TIMER_0_T(INDEX_TIMER_ACHR_CHAPV, MAX_VALUE_TIMER_FOR_COUNT_SIGNAL_ACHR_CHAPV, logic_APV_0, 18, logic_APV_0, 19);

  _OR2_INVERTOR(logic_APV_0, 15, logic_APV_0, 19, logic_APV_0, 20);

  //М:"АПВ"
  logic_APV_0 |= ((current_settings_prt.control_apv & CTR_APV_STAGE_1) != 0) << 23;
  _INVERTOR(logic_APV_0, 23, logic_APV_0, 24);

  //М:"АПВ2"
  logic_APV_0 |= ((current_settings_prt.control_apv & CTR_APV_STAGE_2) != 0) << 25;
  _INVERTOR(logic_APV_0, 25, logic_APV_0, 26);

  //М:"АПВ3"
  logic_APV_0 |= ((current_settings_prt.control_apv & CTR_APV_STAGE_3) != 0) << 27;
  _INVERTOR(logic_APV_0, 27, logic_APV_0, 28);

  //М:"АПВ4"
  logic_APV_0 |= ((current_settings_prt.control_apv & CTR_APV_STAGE_4) != 0) << 29;
  _INVERTOR(logic_APV_0, 29, logic_APV_0, 30);

  //Наступні операції виконуються ітераційно поки всі сигнали не встановляться у фіксований стан
  logic_APV_0 |= _GET_OUTPUT_STATE(previous_states_APV_0, 1) << 31;
  logic_APV_1 |= _GET_OUTPUT_STATE(previous_states_APV_0, 2) <<  0;
  logic_APV_1 |= _GET_OUTPUT_STATE(previous_states_APV_0, 3) <<  1;
  logic_APV_1 |= _GET_OUTPUT_STATE(previous_states_APV_0, 4) <<  2;
  
  //logic_APV_3 |= (_CHECK_SET_BIT(p_active_functions, RANG_UROV2) != 0) << 4;
  logic_APV_3 |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_UROV2) != 0) << 4;
  logic_APV_3 |= ((current_settings_prt.control_apv & CTR_APV_CTRAPV_BLK_CTRL_PRVV2) != 0) << 6;
  _AND2(logic_APV_3, 4, logic_APV_3, 6, logic_APV_3, 14);
  _TIMER_0_T(INDEX_TIMER_APV_TMP2, 40, logic_APV_3, 14, logic_APV_3, 5);

  unsigned int previous_trigger_APV_0;
  
  /*
  Скидаємо спочатку ці сигнали, бо у циклі do-while будемо їх виставляти,
  але після виставлення їх піде сигнал на очищення триґера, який і, фактично, буде
  означати очищення цих сигналів.
  Щоб зафіксувати спрацювання цих сигналів, ми їх очищуємо всіх перед циклом, а
  у циклі будемо тільки виставляти
  */
  _CLEAR_BIT(p_active_functions, RNG_BIG_APV1);//_CLEAR_BIT(p_active_functions, RANG_APV1);
  _CLEAR_BIT(p_active_functions, RNG_BIG_APV2);//_CLEAR_BIT(p_active_functions, RANG_APV2);
  _CLEAR_BIT(p_active_functions, RNG_BIG_APV3);//_CLEAR_BIT(p_active_functions, RANG_APV3);
  _CLEAR_BIT(p_active_functions, RNG_BIG_APV4);//_CLEAR_BIT(p_active_functions, RANG_APV4);
  do
  {
    /***
    Фіксуємо теперішній стан сигналів, які потім, можливо, зміняться і від зміни
    стану яких залежить завершення ітераційного процесу
    ***/
    _CLEAR_STATE(previous_states_APV_0, 1);
    previous_states_APV_0 |= _GET_OUTPUT_STATE(logic_APV_0, 31) << 1;
    _CLEAR_STATE(previous_states_APV_0, 2);
    previous_states_APV_0 |= _GET_OUTPUT_STATE(logic_APV_1,  0) << 2;
    _CLEAR_STATE(previous_states_APV_0, 3);
    previous_states_APV_0 |= _GET_OUTPUT_STATE(logic_APV_1,  1) << 3;
    _CLEAR_STATE(previous_states_APV_0, 4);
    previous_states_APV_0 |= _GET_OUTPUT_STATE(logic_APV_1,  2) << 4;
    
    previous_trigger_APV_0 = trigger_APV_0;
    /***/
    
    _OR2(logic_APV_1, 2, logic_APV_1, 1, logic_APV_1, 3);
    
    
    //АПВ1
    _OR6(logic_APV_1, 19, previous_states_APV_0, 9, trigger_APV_0, 1, trigger_APV_0, 2, trigger_APV_0, 3, logic_APV_0, 31, logic_APV_1, 4);
    _OR6(logic_APV_1, 26, logic_APV_0, 22, logic_APV_0, 24, logic_APV_1, 3, logic_APV_1, 0, logic_APV_1, 4, logic_APV_1, 8);
    _OR2(logic_APV_1, 8, logic_APV_3, 5, logic_APV_3, 7);
    _D_TRIGGER(_GET_OUTPUT_STATE(logic_APV_0, 1),  0, _GET_OUTPUT_STATE(logic_APV_3, 7), previous_states_APV_0, 5, logic_APV_0, 20, trigger_APV_0, 0);                 
    _TIMER_T_0(INDEX_TIMER_APV_1, current_settings_prt.timeout_apv_1[number_group_stp], trigger_APV_0, 0, logic_APV_1, 9);
    /*
    Цей сигнал встановлюмо в масив p_active_functions в циклі з післяумовою
    do-while, бо нас цікавить зафіксувати цей сигнал, а коли він виставиться, то
    піде сигнал на очистку триґера і цей сигнал очиститься. Але встановлення по АБО "0"
    після встановлення "1" не мало б зняти цей сигнал і ми його маємо зафіксувати до 
    наступної роботи системи захистів (скидання цих сигналів здійснюється перед
    циклом do-while).
    */
    if (_GET_OUTPUT_STATE(logic_APV_1, 9)) _SET_BIT(p_active_functions, RNG_BIG_APV1);//_SET_BIT(p_active_functions, RANG_APV1);
    _TIMER_0_T(INDEX_TIMER_APV_BLOCK_VID_APV1, current_settings_prt.timeout_apv_block_vid_apv1[number_group_stp], logic_APV_1, 9, logic_APV_0, 31);

    //АПВ2
    _AND2_INVERTOR(logic_APV_0, 31, logic_APV_0, 15, logic_APV_1, 10);
    _OR6(logic_APV_1, 19, previous_states_APV_0, 9, trigger_APV_0, 0, trigger_APV_0, 2, trigger_APV_0, 3, logic_APV_1,  0, logic_APV_1, 5);
    _OR6(logic_APV_1, 26, logic_APV_0, 24, logic_APV_0, 26, logic_APV_1, 2, logic_APV_1, 1, logic_APV_1, 5, logic_APV_1, 11);
    _OR2(logic_APV_1, 11, logic_APV_3, 5, logic_APV_3, 8);
    _D_TRIGGER(1,  0, _GET_OUTPUT_STATE(logic_APV_3, 8), previous_states_APV_0, 6, logic_APV_1, 10, trigger_APV_0, 1);    
    _TIMER_T_0(INDEX_TIMER_APV_2, current_settings_prt.timeout_apv_2[number_group_stp], trigger_APV_0, 1, logic_APV_1, 12);
    /*
    Цей сигнал встановлюмо в масив p_active_functions в циклі з післяумовою
    do-while, бо нас цікавить зафіксувати цей сигнал, а коли він виставиться, то
    піде сигнал на очистку триґера і цей сигнал очиститься. Але встановлення по АБО "0"
    після встановлення "1" не мало б зняти цей сигнал і ми його маємо зафіксувати до 
    наступної роботи системи захистів (скидання цих сигналів здійснюється перед
    циклом do-while).
    */
    if (_GET_OUTPUT_STATE(logic_APV_1, 12)) _SET_BIT(p_active_functions, RNG_BIG_APV2);//_SET_BIT(p_active_functions, RANG_APV2);
    _TIMER_0_T(INDEX_TIMER_APV_BLOCK_VID_APV2, current_settings_prt.timeout_apv_block_vid_apv2[number_group_stp], logic_APV_1, 12, logic_APV_1, 0);

    //АПВ3
    _AND2_INVERTOR(logic_APV_1, 0, logic_APV_0, 15, logic_APV_1, 13);
    _OR6(logic_APV_1, 19, previous_states_APV_0, 9, trigger_APV_0, 0, trigger_APV_0, 1, trigger_APV_0, 3, logic_APV_1,  1, logic_APV_1, 6);
    _OR5(logic_APV_1, 26, logic_APV_0, 24, logic_APV_0, 28, logic_APV_1, 2, logic_APV_1, 6, logic_APV_1, 14);
    _OR2(logic_APV_1, 14, logic_APV_3, 5, logic_APV_3, 9);
    _D_TRIGGER(1,  0, _GET_OUTPUT_STATE(logic_APV_3, 9), previous_states_APV_0, 7, logic_APV_1, 13, trigger_APV_0, 2);                 
    _TIMER_T_0(INDEX_TIMER_APV_3, current_settings_prt.timeout_apv_3[number_group_stp], trigger_APV_0, 2, logic_APV_1, 15);
    /*
    Цей сигнал встановлюмо в масив p_active_functions в циклі з післяумовою
    do-while, бо нас цікавить зафіксувати цей сигнал, а коли він виставиться, то
    піде сигнал на очистку триґера і цей сигнал очиститься. Але встановлення по АБО "0"
    після встановлення "1" не мало б зняти цей сигнал і ми його маємо зафіксувати до 
    наступної роботи системи захистів (скидання цих сигналів здійснюється перед
    циклом do-while).
    */
    if (_GET_OUTPUT_STATE(logic_APV_1, 15)) _SET_BIT(p_active_functions, RNG_BIG_APV3);//_SET_BIT(p_active_functions, RANG_APV3);
    _TIMER_0_T(INDEX_TIMER_APV_BLOCK_VID_APV3, current_settings_prt.timeout_apv_block_vid_apv3[number_group_stp], logic_APV_1, 15, logic_APV_1, 1);

    //АПВ4
    _AND2_INVERTOR(logic_APV_1, 1, logic_APV_0, 15, logic_APV_1, 16);
    _OR6(logic_APV_1, 19, previous_states_APV_0, 9, trigger_APV_0, 0, trigger_APV_0, 1, trigger_APV_0, 2, logic_APV_1,  2, logic_APV_1, 7);
    _OR4(logic_APV_1, 26, logic_APV_0, 24, logic_APV_0, 30, logic_APV_1, 7, logic_APV_1, 17);
    _OR2(logic_APV_1, 17, logic_APV_3, 5, logic_APV_3, 10);
    _D_TRIGGER(1,  0, _GET_OUTPUT_STATE(logic_APV_3, 10), previous_states_APV_0, 8, logic_APV_1, 16, trigger_APV_0, 3);                 
    _TIMER_T_0(INDEX_TIMER_APV_4, current_settings_prt.timeout_apv_4[number_group_stp], trigger_APV_0, 3, logic_APV_1, 18);
    /*
    Цей сигнал встановлюмо в масив p_active_functions в циклі з післяумовою
    do-while, бо нас цікавить зафіксувати цей сигнал, а коли він виставиться, то
    піде сигнал на очистку триґера і цей сигнал очиститься. Але встановлення по АБО "0"
    після встановлення "1" не мало б зняти цей сигнал і ми його маємо зафіксувати до 
    наступної роботи системи захистів (скидання цих сигналів здійснюється перед
    циклом do-while).
    */
    if (_GET_OUTPUT_STATE(logic_APV_1, 18)) _SET_BIT(p_active_functions, RNG_BIG_APV4);//_SET_BIT(p_active_functions, RANG_APV4);
    _TIMER_0_T(INDEX_TIMER_APV_BLOCK_VID_APV4, current_settings_prt.timeout_apv_block_vid_apv4[number_group_stp], logic_APV_1, 18, logic_APV_1, 2);
  }
  while (
         (_GET_OUTPUT_STATE(logic_APV_0, 31) != _GET_OUTPUT_STATE(previous_states_APV_0, 1)) ||
         (_GET_OUTPUT_STATE(logic_APV_1,  0) != _GET_OUTPUT_STATE(previous_states_APV_0, 2)) ||
         (_GET_OUTPUT_STATE(logic_APV_1,  1) != _GET_OUTPUT_STATE(previous_states_APV_0, 3)) ||
         (_GET_OUTPUT_STATE(logic_APV_1,  2) != _GET_OUTPUT_STATE(previous_states_APV_0, 4)) ||
         ( trigger_APV_0                     !=  previous_trigger_APV_0                    )  
        );
  
  _Bool work_apv = 0;
  _OR4(trigger_APV_0, 0, trigger_APV_0, 1, trigger_APV_0, 2, trigger_APV_0, 3, work_apv, 0);
  
  //Работа АПВ
  if (work_apv) _SET_BIT(p_active_functions, RNG_BIG_APV_WORK);//!@_SET_BIT(p_active_functions, @RANG_APV_WORK);
  else  _CLEAR_BIT(p_active_functions, RNG_BIG_APV_WORK);//!@_CLEAR_BIT(p_active_functions, @RANG_APV_WORK);
  
}
/*****************************************************/

/*****************************************************/
// Універсальний Захист
/*****************************************************/
inline void up_handler(unsigned int *p_active_functions, unsigned int number_group_stp)
{
  for (size_t n_UP = 0; n_UP < NUMBER_UP; n_UP++)
  {
    uint32_t logic_UP_0 = 0;
    
    logic_UP_0 |= (
                   ((current_settings_prt.control_UP & MASKA_FOR_BIT(n_UP*(_CTR_UP_NEXT_BIT - (_CTR_UP_PART_II - _CTR_UP_PART_I) - _CTR_UP_PART_I) + CTR_UP_STATE_BIT - (_CTR_UP_PART_II - _CTR_UP_PART_I))) != 0)
                   &&
                   (_CHECK_SET_BIT(p_active_functions, (RNG_BIG_BLOCK_UP1 + 3*n_UP)) == 0)//!@(_CHECK_SET_BIT(p_active_functions, ( @RANG_BLOCK_UP1 + 3*n_UP)) == 0)
                  ) << 0;

    int32_t pickup = current_settings_prt.setpoint_UP[n_UP][0][number_group_stp];
    if (
        (current_settings_prt.ctrl_UP_input[n_UP] == UP_CTRL_3I0) ||
        (current_settings_prt.ctrl_UP_input[n_UP] == UP_CTRL_3I0_others)
       ) 
    {
      if (_CHECK_SET_BIT(p_active_functions, (RNG_BIG_PO_UP1 + 3*n_UP)) != 0)//!@if (_CHECK_SET_BIT(p_active_functions, ( @RANG_PO_UP1 + 3*n_UP)) != 0)
      {
        /*
        Алгебраїчне спрощення виразу
        setpoint = (pickup*koef_povernennja/100)*10 =  pickup*koef_povernennja/10
        */
        pickup = (pickup * (int32_t)current_settings_prt.setpoint_UP_KP[n_UP][0][number_group_stp])/10;
      }
      else
      {
        pickup *= 10;
      }
        
    }
    else
    {
      //!@if (_CHECK_SET_BIT(p_active_functions, ( @RANG_PO_UP1 + 3*n_UP)) != 0) pickup = (pickup * (int32_t)current_settings_prt.setpoint_UP_KP[n_UP][0][number_group_stp])/100;
      if (_CHECK_SET_BIT(p_active_functions, (RNG_BIG_PO_UP1 + 3*n_UP)) != 0) pickup = (pickup * (int32_t)current_settings_prt.setpoint_UP_KP[n_UP][0][number_group_stp])/100;
    }

    unsigned int more_less = ((current_settings_prt.control_UP & MASKA_FOR_BIT(n_UP*(_CTR_UP_NEXT_BIT - (_CTR_UP_PART_II - _CTR_UP_PART_I) - _CTR_UP_PART_I) + CTR_UP_MORE_LESS_BIT - (_CTR_UP_PART_II - _CTR_UP_PART_I))) != 0);
    
    int32_t analog_value;
    uint32_t PQ = false;
    uint32_t bank_for_calc_power_tmp = (state_calc_power == false ) ? bank_for_calc_power : ((bank_for_calc_power ^ 0x1) & 0x1);

    switch (current_settings_prt.ctrl_UP_input[n_UP])
    {
    case UP_CTRL_Ia_Ib_Ic:
      {
        analog_value = measurement[IM_Imn];

        unsigned int or_and = ((current_settings_prt.control_UP & MASKA_FOR_BIT(n_UP*(_CTR_UP_NEXT_BIT - (_CTR_UP_PART_II - _CTR_UP_PART_I) - _CTR_UP_PART_I) + CTR_UP_OR_AND_BIT - (_CTR_UP_PART_II - _CTR_UP_PART_I))) != 0);
        if (
            ((more_less == 0) && (or_and == 0)) ||
            ((more_less != 0) && (or_and != 0))
           )   
        {
         if ((uint32_t)analog_value < measurement[IM_Ibp]) analog_value = measurement[IM_Ibp];
        }
        else
        {
         if ((uint32_t)analog_value > measurement[IM_Ibp]) analog_value = measurement[IM_Ibp];
        }
        
        break;
      }
    case UP_CTRL_Ia:
      {
        analog_value = measurement[IM_Imn];
        
        break;
      }
    case UP_CTRL_Ib:
      {
        analog_value = measurement[IM_Ibp];
        
        break;
      }
    case UP_CTRL_Ic:
      {
        analog_value = 0/*measurement[IM_IC]*/;
        
        break;
      }
    case UP_CTRL_I1:
      {
        analog_value = 0/*measurement[IM_I1]*/;
        
        break;
      }
    case UP_CTRL_I2:
      {
        analog_value = 0/*measurement[IM_I2]*/;
        
        break;
      }
    case UP_CTRL_3I0_r:
      {
        analog_value = 0/*measurement[IM_3I0_r]*/;
        
        break;
      }
    case UP_CTRL_3I0:
      {
        analog_value = 0/*measurement[IM_3I0]*/;
        
        break;
      }
    case UP_CTRL_3I0_others:
      {
        analog_value = 0/*measurement[IM_3I0_other_g]*/;
        
        break;
      }
    case UP_CTRL_Ua_Ub_Uc:
      {
        analog_value = 0/*measurement[IM_Umn]*/;
        
        break;
      }
    case UP_CTRL_Ua:
      {
        analog_value = 0/*measurement[IM_Umn]*/;
        
        break;
      }
    case UP_CTRL_Ub:
      {
        analog_value = 0/*measurement[IM_Ubp]*/;
        
        break;
      }
    case UP_CTRL_Uc:
      {
        analog_value = 0/*measurement[IM_UC]*/;
        
        break;
      }
    case UP_CTRL_Uab_Ubc_Uca:
      {
        analog_value = measurement[IM_Umn];
        
        unsigned int or_and = ((current_settings_prt.control_UP & MASKA_FOR_BIT(n_UP*(_CTR_UP_NEXT_BIT - (_CTR_UP_PART_II - _CTR_UP_PART_I) - _CTR_UP_PART_I) + CTR_UP_OR_AND_BIT - (_CTR_UP_PART_II - _CTR_UP_PART_I))) != 0);
        uint32_t analog_value_tmp = measurement[IM_Ubp];
        if (
            ((more_less == 0) && (or_and == 0)) ||
            ((more_less != 0) && (or_and != 0))
           )   
        {
          if ((uint32_t)analog_value < analog_value_tmp) analog_value = analog_value_tmp;
        }
        else
        {
          if ((uint32_t)analog_value > analog_value_tmp) analog_value = analog_value_tmp;
        }
        
        break;
      }
    case UP_CTRL_Uab:
      {
        analog_value = measurement[IM_Umn];
        
        break;
      }
    case UP_CTRL_Ubc:
      {
        analog_value = measurement[IM_Ubp];
        
        break;
      }
    case UP_CTRL_Uca:
      {
        analog_value = 0/*measurement[IM_UCA]*/;
        
        break;
      }
    case UP_CTRL_U1:
      {
        analog_value = 0/*measurement[IM_U1]*/;
        
        break;
      }
    case UP_CTRL_U2:
      {
        analog_value = 0/*measurement[IM_U2]*/;
        
        break;
      }
    case UP_CTRL_3U0:
      {
        analog_value = 0/*measurement[IM_3U0]*/;
        
        break;
      }
    case UP_CTRL_P:
      {
        PQ = true;
        analog_value = P[bank_for_calc_power_tmp][0];
        
        break;
      }
    case UP_CTRL_Q:
      {
        PQ = true;
        analog_value = Q[bank_for_calc_power_tmp][0];
        
        break;
      }
    case UP_CTRL_S:
      {
        analog_value = S[bank_for_calc_power_tmp][0];
        
        break;
      }
    default:
      {
        //Теоретично цього ніколи не мало б бути
        total_error_sw_fixed(100);
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
//!@    if (_GET_OUTPUT_STATE(logic_UP_0, 2)) _SET_BIT(p_active_functions, ( @RANG_PO_UP1 + 3*n_UP));
//!@    else _CLEAR_BIT(p_active_functions, ( @RANG_PO_UP1 + 3*n_UP));
//!@    
//!@    _TIMER_T_0(INDEX_TIMER_UP1 + n_UP, current_settings_prt.timeout_UP[n_UP][0][number_group_stp], logic_UP_0, 2, logic_UP_0, 3);
//!@    if (_GET_OUTPUT_STATE(logic_UP_0, 3)) _SET_BIT(p_active_functions, ( @RANG_UP1 + 3*n_UP));
//!@    else _CLEAR_BIT(p_active_functions, ( @RANG_UP1 + 3*n_UP));
    if (_GET_OUTPUT_STATE(logic_UP_0, 2)) _SET_BIT(p_active_functions, (RNG_BIG_PO_UP1 + 3*n_UP));
    else _CLEAR_BIT(p_active_functions, (RNG_BIG_PO_UP1 + 3*n_UP));
    
    _TIMER_T_0(INDEX_TIMER_UP1 + n_UP, current_settings_prt.timeout_UP[n_UP][0][number_group_stp], logic_UP_0, 2, logic_UP_0, 3);
    if (_GET_OUTPUT_STATE(logic_UP_0, 3)) _SET_BIT(p_active_functions, (RNG_BIG_UP1 + 3*n_UP));
    else _CLEAR_BIT(p_active_functions, (RNG_BIG_UP1 + 3*n_UP));
  }
}
/*****************************************************/

/*****************************************************/
//Функція управління блоками включення і відключення
/*****************************************************/
inline void on_off_handler(unsigned int *p_active_functions)
{
  static unsigned int previous_active_functions[N_BIG];
  unsigned int maska[N_BIG] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  /*********************/
  //Спочатку опрацьовуємо таймери
  /*********************/
  //Таймер  відключення
  if (global_timers[INDEX_TIMER_VIDKL_VV] >= 0)
  {
    //Таймер БО зараз активний і як мінімум тільки зараз завершить свою роботу
    if (global_timers[INDEX_TIMER_VIDKL_VV] >= current_settings_prt.timeout_swch_off)
    {
      //Таймер досягнув свого максимального значення
      global_timers[INDEX_TIMER_VIDKL_VV] = -1;
      //Відмічаємо у масиві функцій, які зараз активуються, що блок БО має бути деативованим
      _CLEAR_BIT(p_active_functions, RNG_BIG_WORK_BO_VVO);//!@_CLEAR_BIT(p_active_functions, @RANG_WORK_BO);
    }
    //Незавершена робота блоку БО означає, що таймер блокування БВ має бути запущений і знаходитися у свому початковому значенні,
    //щоб як тільки блок БО відпрацює, щоб блокування включення почалося на весь час з моменту закінчення роботи блоку БО
    global_timers[INDEX_TIMER_BLK_VKL_VV] = 0;
  }
    
  //Таймер  блокування включення
  if (global_timers[INDEX_TIMER_BLK_VKL_VV] >= 0)
  {
    //Таймер блокування включення БВ зараз активний і як мінімум тільки зараз завершить свою роботу
    if (global_timers[INDEX_TIMER_BLK_VKL_VV] >= current_settings_prt.timeout_swch_udl_blk_on)
    {
      //Таймер досягнув свого максимального значення
      global_timers[INDEX_TIMER_BLK_VKL_VV] = -1;
    }
  }

  //Таймер  включення
  if (global_timers[INDEX_TIMER_VKL_VV] >= 0)
  {
    //Таймер БВ зараз активний і як мінімум тільки зараз завершить свою роботу

    //Якщо по якійсь причині таймер включення працює, при умові, що таймери БО і блокування включення ще не скинуті, то таймер включення треба скинути
    if ((global_timers[INDEX_TIMER_VIDKL_VV] >= 0) || (global_timers[INDEX_TIMER_BLK_VKL_VV] >=0))
    {
      global_timers[INDEX_TIMER_VKL_VV] = -1;
      //Відмічаємо у масиві функцій, які зараз активуються, що блок БB має бути деативованим
      _CLEAR_BIT(p_active_functions, RNG_BIG_WORK_BV_VVO);//!@_CLEAR_BIT(p_active_functions, @RANG_WORK_BV);
    }
    else
    {
      //Перевіряємо, чи таймер включення не досягнув свого масимального значення
      if (global_timers[INDEX_TIMER_VKL_VV] >= current_settings_prt.timeout_swch_on)
      {
        //Таймер досягнув свого максимального значення
        global_timers[INDEX_TIMER_VKL_VV] = -1;
        //Відмічаємо у масиві функцій, які зараз активуються, що блок БB має бути деативованим
        _CLEAR_BIT(p_active_functions, RNG_BIG_WORK_BV_VVO);//!@_CLEAR_BIT(p_active_functions, @RANG_WORK_BV);
      }
    }
  }
  /*********************/

  /*********************/
  //Першим розглядається блок відключення, бо він може блокувати включення вимикача
  /*********************/
  /*
  Цей сигнал встановлюється тільки у певних випадках, тому по замовчуванню його треба скинута,
  а коли буде потрібно - він встановиться
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
    global_timers[INDEX_TIMER_VIDKL_VV  ] = 0;
    global_timers[INDEX_TIMER_BLK_VKL_VV] = 0;
    
    //Скидаємо активацію блоку ввімкнення
    _CLEAR_BIT(p_active_functions, RNG_BIG_WORK_BV_VVO);//!@_CLEAR_BIT(p_active_functions, @RANG_WORK_BV);
    //Скидаємо таймер блку вимкнення
    global_timers[INDEX_TIMER_VKL_VV] = -1;  

    /*
    Формуємо сигнал "Відключення від захистів" (він рівний наявності умови команди
    активації команди "Робота БО" будь-якою командою за виключенняв "Вимкн. ВВ")
    */
    //Формуємо інвертовану маску для виключення команди "Вимк.ВВ"
    for (unsigned int i = 0; i < N_BIG; i++ )  maska[i] = (unsigned int)(~0);
    _CLEAR_BIT(maska, RNG_BIG_OTKL_VV_VVO);//!@_CLEAR_BIT(maska, @RANG_OTKL_VV);
    _CLEAR_BIT(maska, RNG_BIG_WORK_BO_VVO);//!@_CLEAR_BIT(maska, @RANG_WORK_BO);
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
          
      /*****************************************************
      Формуванні інформації про причину відключення для меню
      *****************************************************/
      __info_vymk info_vymk_tmp = {time_dat, time_ms};
#ifdef DZ_ACTIVE          
      //ДЗ1
//!@      if(
//!@         (_CHECK_SET_BIT(temp_array_of_outputs, RANG_DZ1) != 0) &&
//!@         (_CHECK_SET_BIT(previous_active_functions, RANG_DZ1) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
//!@        )   
//!@      {
//!@        _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_DZ_1);
//!@        info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_DZ_1] = info_vymk_tmp;
//!@
//!@        _CLEAR_BIT(temp_array_of_outputs, RANG_DZ1);
//!@      }
//!@          
//!@      //AMСЗ ДЗ1
//!@      if(
//!@         (_CHECK_SET_BIT(temp_array_of_outputs, RANG_AMTZ_DZ1) != 0) &&
//!@         (_CHECK_SET_BIT(previous_active_functions, RANG_AMTZ_DZ1) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
//!@        )   
//!@      {
//!@        _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_AMTZ_DZ_1);
//!@        info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_AMTZ_DZ_1] = info_vymk_tmp;
//!@
//!@        _CLEAR_BIT(temp_array_of_outputs, RANG_AMTZ_DZ1);
//!@      }
//!@          
//!@      //ДЗ2
//!@      if(
//!@         (_CHECK_SET_BIT(temp_array_of_outputs, RANG_DZ2) != 0) &&
//!@         (_CHECK_SET_BIT(previous_active_functions, RANG_DZ2) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
//!@        )   
//!@      {
//!@        _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_DZ_2);
//!@        info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_DZ_2] = info_vymk_tmp;
//!@
//!@        _CLEAR_BIT(temp_array_of_outputs, RANG_DZ2);
//!@      }
//!@          
//!@      //AMСЗ ДЗ2
//!@      if(
//!@         (_CHECK_SET_BIT(temp_array_of_outputs, RANG_AMTZ_DZ2) != 0) &&
//!@         (_CHECK_SET_BIT(previous_active_functions, RANG_AMTZ_DZ2) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
//!@        )   
//!@      {
//!@        _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_AMTZ_DZ_2);
//!@        info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_AMTZ_DZ_2] = info_vymk_tmp;
//!@
//!@        _CLEAR_BIT(temp_array_of_outputs, RANG_AMTZ_DZ2);
//!@      }
//!@          
//!@      //ДЗ3
//!@      if(
//!@         (_CHECK_SET_BIT(temp_array_of_outputs, RANG_DZ3) != 0) &&
//!@         (_CHECK_SET_BIT(previous_active_functions, RANG_DZ3) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
//!@        )   
//!@      {
//!@        _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_DZ_3);
//!@        info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_DZ_3] = info_vymk_tmp;
//!@
//!@        _CLEAR_BIT(temp_array_of_outputs, RANG_DZ3);
//!@      }
//!@          
//!@          
//!@      //AMСЗ ДЗ3
//!@      if(
//!@         (_CHECK_SET_BIT(temp_array_of_outputs, RANG_AMTZ_DZ3) != 0) &&
//!@         (_CHECK_SET_BIT(previous_active_functions, RANG_AMTZ_DZ3) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
//!@        )   
//!@      {
//!@        _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_AMTZ_DZ_3);
//!@        info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_AMTZ_DZ_3] = info_vymk_tmp;
//!@
//!@        _CLEAR_BIT(temp_array_of_outputs, RANG_AMTZ_DZ3);
//!@      }
//!@
//!@      //ДЗ4
//!@      if(
//!@         (_CHECK_SET_BIT(temp_array_of_outputs, RANG_DZ4) != 0) &&
//!@         (_CHECK_SET_BIT(previous_active_functions, RANG_DZ4) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
//!@        )   
//!@      {
//!@        _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_DZ_4);
//!@        info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_DZ_4] = info_vymk_tmp;
//!@
//!@        _CLEAR_BIT(temp_array_of_outputs, RANG_DZ4);
//!@      }
//!@          
//!@      //AMСЗ ДЗ4
//!@      if(
//!@         (_CHECK_SET_BIT(temp_array_of_outputs, RANG_AMTZ_DZ4) != 0) &&
//!@         (_CHECK_SET_BIT(previous_active_functions, RANG_AMTZ_DZ4) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
//!@        )   
//!@      {
//!@        _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_AMTZ_DZ_4);
//!@        info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_AMTZ_DZ_4] = info_vymk_tmp;
//!@
//!@        _CLEAR_BIT(temp_array_of_outputs, RANG_AMTZ_DZ4);
//!@      }
//!@
//!@      //МТЗ1
//!@      if(
//!@         (_CHECK_SET_BIT(temp_array_of_outputs, RANG_MTZ1) != 0) &&
//!@         (_CHECK_SET_BIT(previous_active_functions, RANG_MTZ1) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
//!@        )   
//!@      {
//!@        _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_MTZ1);
//!@        info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_MTZ1] = info_vymk_tmp;
//!@
//!@        _CLEAR_BIT(temp_array_of_outputs, RANG_MTZ1);
//!@      }
//!@      
//!@      //МТЗ2
//!@      if(
//!@         (_CHECK_SET_BIT(temp_array_of_outputs, RANG_MTZ2) != 0) &&
//!@         (_CHECK_SET_BIT(previous_active_functions, RANG_MTZ2) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
//!@        )   
//!@      {
//!@        _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_MTZ2);
//!@        info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_MTZ2] = info_vymk_tmp;
//!@
//!@        _CLEAR_BIT(temp_array_of_outputs, RANG_MTZ2);
//!@      }
//!@      
//!@      //МТЗ3
//!@      if(
//!@         (_CHECK_SET_BIT(temp_array_of_outputs, RANG_MTZ3) != 0) &&
//!@         (_CHECK_SET_BIT(previous_active_functions, RANG_MTZ3) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
//!@        )   
//!@      {
//!@        _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_MTZ3);
//!@        info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_MTZ3] = info_vymk_tmp;
//!@
//!@        _CLEAR_BIT(temp_array_of_outputs, RANG_MTZ3);
//!@      }
//!@      
//!@      //МТЗ4
//!@      if(
//!@         (_CHECK_SET_BIT(temp_array_of_outputs, RANG_MTZ4) != 0) &&
//!@         (_CHECK_SET_BIT(previous_active_functions, RANG_MTZ4) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
//!@        )   
//!@      {
//!@        _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_MTZ4);
//!@        info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_MTZ4] = info_vymk_tmp;
//!@
//!@        _CLEAR_BIT(temp_array_of_outputs, RANG_MTZ4);
//!@      }
#endif          
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
      
//!@      //ЗЗ/3I0
//!@      if(
//!@         (_CHECK_SET_BIT(temp_array_of_outputs, RANG_3I0) != 0) &&
//!@         (_CHECK_SET_BIT(previous_active_functions, RANG_3I0) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
//!@        )   
//!@      {
//!@        _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_3I0);
//!@        info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_3I0] = info_vymk_tmp;
//!@
//!@        _CLEAR_BIT(temp_array_of_outputs, RANG_3I0);
//!@      }
//!@          
//!@      //ЗЗ/3U0
//!@      if(
//!@         (_CHECK_SET_BIT(temp_array_of_outputs, RANG_3U0) != 0) &&
//!@         (_CHECK_SET_BIT(previous_active_functions, RANG_3U0) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
//!@        )   
//!@      {
//!@        _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_3U0);
//!@        info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_3U0] = info_vymk_tmp;
//!@
//!@        _CLEAR_BIT(temp_array_of_outputs, RANG_3U0);
//!@      }
//!@          
//!@      //НЗЗ
//!@      if(
//!@         (_CHECK_SET_BIT(temp_array_of_outputs, RANG_NZZ) != 0) &&
//!@         (_CHECK_SET_BIT(previous_active_functions, RANG_NZZ) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
//!@        )   
//!@      {
//!@        _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_NZZ);
//!@        info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_NZZ] = info_vymk_tmp;
//!@
//!@        _CLEAR_BIT(temp_array_of_outputs, RANG_NZZ);
//!@      }
//!@          
//!@      //ТЗНП1
//!@      if(
//!@         (_CHECK_SET_BIT(temp_array_of_outputs, RANG_TZNP1) != 0) &&
//!@         (_CHECK_SET_BIT(previous_active_functions, RANG_TZNP1) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
//!@        )   
//!@      {
//!@        _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_TZNP1);
//!@        info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_TZNP1] = info_vymk_tmp;
//!@
//!@        _CLEAR_BIT(temp_array_of_outputs, RANG_TZNP1);
//!@      }
//!@
//!@      //ТЗНП2
//!@      if(
//!@         (_CHECK_SET_BIT(temp_array_of_outputs, RANG_TZNP2) != 0) &&
//!@         (_CHECK_SET_BIT(previous_active_functions, RANG_TZNP2) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
//!@        )   
//!@      {
//!@        _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_TZNP2);
//!@        info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_TZNP2] = info_vymk_tmp;
//!@
//!@        _CLEAR_BIT(temp_array_of_outputs, RANG_TZNP2);
//!@      }
//!@
//!@      //ТЗНП3
//!@      if(
//!@         (_CHECK_SET_BIT(temp_array_of_outputs, RANG_TZNP3) != 0) &&
//!@         (_CHECK_SET_BIT(previous_active_functions, RANG_TZNP3) == 0) /*умова, що сигнал тільки активується (щоб зафіксувати час старту)*/
//!@        )   
//!@      {
//!@        _SET_BIT(info_vidkluchennja_vymykacha, VYMKNENNJA_VID_TZNP3);
//!@        info_vidkluchennja_vymykachatime[VYMKNENNJA_VID_TZNP3] = info_vymk_tmp;
//!@
//!@        _CLEAR_BIT(temp_array_of_outputs, RANG_TZNP3);
//!@      }

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
      /*****************************************************/
    }
  }

  /*********************/
  //Потім розглядається блок включення
  /*********************/
  if (
      (global_timers[INDEX_TIMER_VIDKL_VV  ] < 0) && 
      (global_timers[INDEX_TIMER_BLK_VKL_VV] < 0) &&
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
      global_timers[INDEX_TIMER_VKL_VV] = 0;
    }
  }
  else
  {
    //На даний момент існує одна або більше умов блокування БВ
    global_timers[INDEX_TIMER_VKL_VV] = -1;
    _CLEAR_BIT(p_active_functions, RNG_BIG_WORK_BV_VVO);//!@RANG_WORK_BV
  }
  /*********************/

  /*********************/
  //Формуємо попереденій стан сигналів для функції ввімкнення/вимкнення
  /*********************/
  for (unsigned int i = 0; i < N_BIG; i++) previous_active_functions[i] = p_active_functions[i];
  /*********************/
}
/*****************************************************/

/*****************************************************/
//Визначення місця до пошкодження
/*****************************************************/
inline void vmp_handler(unsigned int p_active_functions[])
{
  //Перевіряємо чи стоїть фіксуються спрацювання від КЗ на фазних лініях
  if(
     ((p_active_functions[0 ] & MASKA_MONITOTYNG_PHASE_SIGNALES_KZ_0) != 0) ||
     ((p_active_functions[1 ] & MASKA_MONITOTYNG_PHASE_SIGNALES_KZ_1) != 0) ||
     ((p_active_functions[2 ] & MASKA_MONITOTYNG_PHASE_SIGNALES_KZ_2) != 0) ||
     ((p_active_functions[3 ] & MASKA_MONITOTYNG_PHASE_SIGNALES_KZ_3) != 0) ||
     ((p_active_functions[4 ] & MASKA_MONITOTYNG_PHASE_SIGNALES_KZ_4) != 0) ||
     ((p_active_functions[5 ] & MASKA_MONITOTYNG_PHASE_SIGNALES_KZ_5) != 0) ||
     ((p_active_functions[6 ] & MASKA_MONITOTYNG_PHASE_SIGNALES_KZ_6) != 0) ||
     ((p_active_functions[7 ] & MASKA_MONITOTYNG_PHASE_SIGNALES_KZ_7) != 0) ||
     ((p_active_functions[8 ] & MASKA_MONITOTYNG_PHASE_SIGNALES_KZ_8) != 0) ||
     ((p_active_functions[9 ] & MASKA_MONITOTYNG_PHASE_SIGNALES_KZ_9) != 0) ||
     ((p_active_functions[10] & MASKA_MONITOTYNG_PHASE_SIGNALES_KZ_10) != 0)||
     ((p_active_functions[11] & MASKA_MONITOTYNG_PHASE_SIGNALES_KZ_10) != 0)||
     ((p_active_functions[12] & MASKA_MONITOTYNG_PHASE_SIGNALES_KZ_10) != 0)
    )
  {
    //Є фазне КЗ
    VMP_last_KZ = UNDEF_VMP; /*Помічаємо, що визначення місця до пошкодження ще не визначене*/
    
    //Перевіряємо чи подається команда на вимкнення ВВ ("Робота БО")
//!    @vymknennja_vid_KZ_prt |= (_CHECK_SET_BIT(p_active_functions, RANG_WORK_BO) != 0);
//!    @unsigned int MF_KZ_tmp = ((_CHECK_SET_BIT(p_active_functions, RANG_2KZ) != 0) << 0) | ((_CHECK_SET_BIT(p_active_functions, RANG_3KZ) != 0) << 1);
    vymknennja_vid_KZ_prt |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_WORK_BO_VVO) != 0);
    unsigned int MF_KZ_tmp = ((_CHECK_SET_BIT(p_active_functions, RNG_BIG_ERROR_CONF_EL) != 0) << 0) | ((_CHECK_SET_BIT(p_active_functions, RNG_BIG_ERROR_CONF_EL) != 0) << 1);

    if ((MF_KZ_tmp != 0) && (MF_KZ_tmp >= MF_KZ))
    {
      int X_resistance[2];
      X_resistance[0] = ((corupted_phases & ((1 << 0) | (1 << 1))) == ((1 << 0) | (1 << 1))) ? resistance[X_mn] : ((unsigned int)UNDEF_RESISTANCE); //AB
      X_resistance[1] = ((corupted_phases & ((1 << 1) | (1 << 2))) == ((1 << 1) | (1 << 2))) ? resistance[X_bp] : ((unsigned int)UNDEF_RESISTANCE); //BC
      if (
          (((unsigned int)X_resistance[0]) != ((unsigned int)UNDEF_RESISTANCE)) ||
          (((unsigned int)X_resistance[1]) != ((unsigned int)UNDEF_RESISTANCE))
         )
      {
        //Є реально розраховані міжфазні опори

        //Фіксуємо мінімальний міжфазний реактивний опір при КЗ
        //Етап 1: Знаходим перший визначений фіжфазний опір і помічаємо його значення як найменше
        unsigned int min_interphase_X = (unsigned int)UNDEF_RESISTANCE;
        int R_KZ_tmp;
        if (((unsigned int)X_resistance[0]) != ((unsigned int)UNDEF_RESISTANCE))
        {
          min_interphase_X = abs(X_resistance[0]);
          R_KZ_tmp = resistance[R_mn];
        }
        else if (((unsigned int)X_resistance[1]) != ((unsigned int)UNDEF_RESISTANCE))
        {
          min_interphase_X = abs(X_resistance[1]);
          R_KZ_tmp = resistance[R_bp];
        }
        else
        {
          //Теоретично цього ніколи не мало б бути
          total_error_sw_fixed(68);
        }
      
        //Етап 2: Серед всіх визначених міжфазних опорів знаходимо найменше
        unsigned int X_mod;
        if ((((unsigned int)X_resistance[0]) != ((unsigned int)UNDEF_RESISTANCE)) && (min_interphase_X > (X_mod = abs(X_resistance[0])))) 
        {
          min_interphase_X = X_mod;
          R_KZ_tmp = resistance[R_mn];
        }
        if ((((unsigned int)X_resistance[1]) != ((unsigned int)UNDEF_RESISTANCE)) && (min_interphase_X > (X_mod = abs(X_resistance[1]))))
        {
          min_interphase_X = X_mod;
          R_KZ_tmp = resistance[R_bp];
        }
      
        //Етап 3: Перевіряємо чи мінімальний опір на цей момент не є мінімальним з початку виникнення КЗ
        if (
            (min_interphase_X != ((unsigned int)UNDEF_RESISTANCE))
            &&
            (
             (X_min_KZ_prt == ((unsigned int)UNDEF_RESISTANCE)) || /*Це є ознакою, що для даного КЗ ми перший раз фіксуємо мінімальний опір, тому і його значення помічаємо як мінімальне*/
             (MF_KZ_tmp > MF_KZ) ||  
             (X_min_KZ_prt > min_interphase_X)
            )   
           )
        {
          //Зафіксовано нове значення мінімального міжфазного опору при КЗ
          X_min_KZ_prt = min_interphase_X;
          R_KZ_prt = R_KZ_tmp; //Поки що це число потрібно тільки для визначення знаку (щоб визначити у якому напямку відбулося КЗ)
          MF_KZ = MF_KZ_tmp;
        }
      }
      else
      {
        X_min_KZ_prt = (unsigned int)UNDEF_RESISTANCE;
      }
    }
  }
  else
  {
    //На даний момент немає фазного КЗ
    if(
       (vymknennja_vid_KZ_prt != 0) &&  /*Умова, що відбувалося вимкнення під час останнього КЗ*/
       (MF_KZ != 0) && /*Умова, що КЗ є міжфазним*/
       ((current_settings_prt.control_vmp & CTR_VMP_STATE) != 0) && /*ВМП ввімкнено*/ 
       (X_min_KZ_prt != ((unsigned int)UNDEF_RESISTANCE)) /*Умова, що хоча б один міжфазний опір був визначений, а тому і є зафіксований мінімальний реактивний міжфазний опір*/
      )
    {
      if  (MF_KZ & (1 << 0))
      {
        //Двофазне КЗ, тому опір треба поділити на 2
        X_min_KZ_prt >>=1;
      }
      
      //Визначаємо віддаль до місця пошкодження поки що без напрямку 
      unsigned int X_tmp = X_min_KZ_prt*current_settings_prt.TVoltage/current_settings_prt.TCurrent; /*Перерозраховуємо опір на первинну обмотку. Значення залишаємо у мОм*/
      
      unsigned int forward_backward = (R_KZ_prt < 0);
      unsigned int lines_tmp = current_settings_prt.lines[forward_backward];
      unsigned int defined_VMP = false;
      unsigned int i = 0;
      int VMP_tmp = 0;
      while ((defined_VMP == false) && (i < lines_tmp))
      {
        unsigned int dovgyna_tmp = current_settings_prt.dovgyna[forward_backward][i];
        unsigned int opir_tmp = current_settings_prt.opir[forward_backward][i];
        unsigned int X_current_line = dovgyna_tmp*opir_tmp/1000; /*розмірності*[м]x[мОм/км] =  [м]x[мОм/1000м] =[мОм]/1000 */
        if (X_tmp <= X_current_line)
        {
          //На даній ділянці зафіксовано пошкодження
//          VMP_tmp += (int)(((unsigned long long)dovgyna_tmp)*((unsigned long long)X_tmp)/((unsigned long long)X_current_line));
          VMP_tmp += X_tmp*1000/opir_tmp;
          defined_VMP = true;
        }
        else
        {
          //На даній ділянці ще не зафіксовано пошкодження
          VMP_tmp += dovgyna_tmp;
          X_tmp -= X_current_line;
        }
          
        i++;
      }
      
      //Остаточно визначаємо ВМП
      equal_more_KZ = defined_VMP;
      if(forward_backward == 0) VMP_last_KZ = VMP_tmp;
      else VMP_last_KZ = -VMP_tmp;
    }

    /*
    Повертаємо пограмне забезпечення у стан очікування нового КЗ
    
    Цю операцію може б треба було виконувати тільки раз після попереднрього КЗ,
    але оскільки  я не фіксую наявнясть КЗ, а тільки вимкнення при КЗ (короткочасне КЗ
    може не привести до вимкнення, або якщо сигнали працювали на сигналізацію, а не
    на вимкнення) - то щоб не ускладнювати програму, я зробив ці операції постійними коли немає КЗ
    Я думаю, що їх не так багато і вони б не мали сильно знизити ресурс процесора
    */
    vymknennja_vid_KZ_prt = 0;
    MF_KZ = 0;
    X_min_KZ_prt = (unsigned int)UNDEF_RESISTANCE;
    R_KZ_prt = 0;
    corupted_phases = 0;
  }
      
}
/*****************************************************/

/*****************************************************/
//Контроль приводу вимикача
/*****************************************************/
void control_VV(unsigned int *p_active_functions)
{
  unsigned int logic_control_VV_0 = 0;

  //"Контроль Вкл."
//!  @logic_control_VV_0 |= (_CHECK_SET_BIT(p_active_functions, @RANG_CTRL_VKL ) != 0) << 0;
  logic_control_VV_0 |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_CTRL_VKL_VVO ) != 0) << 0;
  //"Контроль Откл."
//!  @logic_control_VV_0 |= (_CHECK_SET_BIT(p_active_functions, @RANG_CTRL_OTKL) != 0) << 1;
  logic_control_VV_0 |= (_CHECK_SET_BIT(p_active_functions, RNG_BIG_CTRL_OTKL_VVO) != 0) << 1;
  
  _XOR_INVERTOR(logic_control_VV_0, 0, logic_control_VV_0, 1, logic_control_VV_0, 2);

  _TIMER_T_0(INDEX_TIMER_PRYVOD_VV, current_settings_prt.timeout_pryvoda_VV, logic_control_VV_0, 2, logic_control_VV_0, 3);

  //М:"Контроль ВВ"
  logic_control_VV_0 |= ((current_settings_prt.control_switch & CTR_PRYVOD_VV) != 0) << 4;
  
  _AND2(logic_control_VV_0, 3, logic_control_VV_0, 4, logic_control_VV_0, 5);
  
  if (_GET_OUTPUT_STATE(logic_control_VV_0, 5))
    _SET_BIT(p_active_functions, RNG_BIG_PRYVID_VVO);//!@RANG_PRYVID_VV
  else
    _CLEAR_BIT(p_active_functions, RNG_BIG_PRYVID_VVO);//!@RANG_PRYVID_VV
}
/*****************************************************/

/*****************************************************/
//Розрахунок коефіцієнтрів для підрахунку ресурсу вимикача
/*****************************************************/
void make_koef_for_resurs(void)
{
  float tmp_1, tmp_2;
  
  tmp_1 = (float)current_settings.setpoint_r_kom_st_Inom/(float)current_settings.setpoint_r_kom_st_Inom_vymk;
  tmp_1  = log10f(tmp_1);

  tmp_2 = (float)current_settings.setpoint_Inom_vymk/(float)current_settings.setpoint_Inom;
  tmp_2  = log10f(tmp_2);
  
  //Помічаємо, що коефіцієнти для розрахунку ресурсу вимикача зараз будуть змінені
  koef_resurs_changed = CHANGED_ETAP_EXECUTION;

  K_resurs = tmp_1/tmp_2;
  
  //Помічаємо, що коефіцієнти для розрахунку ресурсу вимикача змінені і чекають на прийом системою захистів
  koef_resurs_changed = CHANGED_ETAP_ENDED;
}
/*****************************************************/

/*****************************************************/
//Лічильник ресурсу
/*****************************************************/
inline void resurs_vymykacha_handler(unsigned int *p_active_functions)
{
  static unsigned int previous_active_functions[N_BIG];
  
  if (restart_counter != 0)
  {
    //Треба подати команду очистки ресурсу вимикача
    resurs_vymykacha = current_settings_prt.setpoint_pochatkovyj_resurs;
    resurs_vidkljuchennja = current_settings_prt.setpoint_pochatkova_k_vymk;
    
     restart_counter = 0;

    //Запускаємо запис у EEPROM
    _SET_BIT(control_spi1_taskes, TASK_START_WRITE_RESURS_EEPROM_BIT);

    //Помічаємо, що відбулася очистка ресурсу вимикача
    information_about_restart_counter |= ((1 << USB_RECUEST)|(1 << RS485_RECUEST));
  }
  
  /*******************************/
  //Визначаємо максимальний фазовий струм під час роботи Блоку Вимкнення (БО)
  /*******************************/
  static unsigned int max_faze_current_vv;
//!  @if (_CHECK_SET_BIT(p_active_functions, @RANG_WORK_BO) != 0)
  if (_CHECK_SET_BIT(p_active_functions, RNG_BIG_WORK_BO_VVO) != 0)
  {
    unsigned int max_faze_current_tmp = measurement[IM_Imn];
    if (max_faze_current_tmp < measurement[IM_Ibp]) max_faze_current_tmp = measurement[IM_Ibp];
    max_faze_current_tmp = max_faze_current_tmp*current_settings_prt.TCurrent/1000;
  
//!    @if (_CHECK_SET_BIT(previous_active_functions, @RANG_WORK_BO) == 0)
    if (_CHECK_SET_BIT(previous_active_functions, RNG_BIG_WORK_BO_VVO) == 0)
    {
      //Зафіксовано старт роботи БО
      max_faze_current_vv = max_faze_current_tmp;
    }
    else if (_CHECK_SET_BIT(previous_active_functions, RNG_BIG_WORK_BO_VVO) != 0)//!@RANG_WORK_BO
    {
      //БО продовжує свою роботу
      if (max_faze_current_vv < max_faze_current_tmp) max_faze_current_vv = max_faze_current_tmp;
    }
    
    if (max_faze_current_vv > current_settings_prt.setpoint_Inom_vymk) 
    {
      _SET_BIT(p_active_functions, RNG_BIG_PEREVYSHCHENNJA_I_NOM_VYMK);//!@RANG_PEREVYSHCHENNJA_Inom_VYMK
    }
    else
    {
      _CLEAR_BIT(p_active_functions, RNG_BIG_PEREVYSHCHENNJA_I_NOM_VYMK);//!@RANG_PEREVYSHCHENNJA_Inom_VYMK
    }
  }
  /*******************************/
  
  if (
      ((current_settings_prt.control_switch & CTR_RESURS_VV) != 0) &&
      (_CHECK_SET_BIT(previous_active_functions, RNG_BIG_WORK_BO_VVO) != 0) &&  //!@(_CHECK_SET_BIT(previous_active_functions, @RANG_WORK_BO) != 0)
      (_CHECK_SET_BIT(p_active_functions , RNG_BIG_WORK_BO_VVO) == 0)           //!@(_CHECK_SET_BIT(p_active_functions , @RANG_WORK_BO) == 0)      
     ) 
  {
    //Зафіксовано завершення "Робота БО"
    
    /*******************************/
    //Обчислюється ресурс вимикачa
    /*******************************/
    unsigned int N = 0;
    if (max_faze_current_vv >= current_settings_prt.setpoint_Inom_vymk) {
      N = (unsigned int) ceilf((float)current_settings_prt.setpoint_r_kom_st_Inom/(float)current_settings_prt.setpoint_r_kom_st_Inom_vymk);
    } else if (max_faze_current_vv <= current_settings_prt.setpoint_Inom) {
      N = 1;
    } else {
      float I_div_Inom = (float)max_faze_current_vv / (float)current_settings_prt.setpoint_Inom;
      float lg_I_div_Inom = log10f(I_div_Inom);
      float lg_N = K_resurs_prt * lg_I_div_Inom;
      float N_ = powf(10, lg_N);
      N = (unsigned int) ceilf(N_);
      if ((((float)N) - N_) >= 0.5f)
      {
        N--;
      }
      
    }
    
    if (resurs_vymykacha <= N) {
      resurs_vymykacha = 0;
    } else {
      resurs_vymykacha -= N;
    }
    
    //Загальне число переключень
    if ((0xffffffff - resurs_vidkljuchennja) >= 1)
    {
      //Додавання одиниці не викличе переповнення
      resurs_vidkljuchennja++;
    }

    //Запускаємо запис у EEPROM
    _SET_BIT(control_spi1_taskes, TASK_START_WRITE_RESURS_EEPROM_BIT);
  }
  
  if (resurs_vymykacha <= current_settings_prt.setpoint_krytychnyj_resurs) 
  {
    _SET_BIT(p_active_functions, RNG_BIG_KRYTYCHNYJ_RESURS_VVO);//!@RANG_KRYTYCHNYJ_RESURS_VYMYKACHA
  }
  else
  {
    _CLEAR_BIT(p_active_functions, RNG_BIG_KRYTYCHNYJ_RESURS_VVO);//!@RANG_KRYTYCHNYJ_RESURS_VYMYKACHA
  }

  if (resurs_vymykacha == 0) 
  {
    _SET_BIT(p_active_functions, RNG_BIG_VYCHERPANYJ_RESURS_VVO);//!@RANG_VYCHERPANYJ_RESURS_VYMYKACHA
  }
  else
  {
    _CLEAR_BIT(p_active_functions, RNG_BIG_VYCHERPANYJ_RESURS_VVO);//!@RANG_VYCHERPANYJ_RESURS_VYMYKACHA
  }
 

  /*********************/
  //Формуємо попереденій стан сигналів для функції ввімкнення/вимкнення
  /*********************/
  for (unsigned int i = 0; i < N_BIG; i++) previous_active_functions[i] = p_active_functions[i];
  /*********************/
}
/*****************************************************/

/*****************************************************/
//Перевірка на необхідність завершення роботи аналогового/дискретного реєстраторів
/*****************************************************/
inline unsigned int stop_regisrator(unsigned int* carrent_active_functions, unsigned int* ranguvannja_registrator)
{
  unsigned int stop = 0;

  {
    if (
        ((carrent_active_functions[0 ]  & ranguvannja_registrator[0 ] ) == 0) &&
        ((carrent_active_functions[1 ]  & ranguvannja_registrator[1 ] ) == 0) &&
        ((carrent_active_functions[2 ]  & ranguvannja_registrator[2 ] ) == 0) &&
        ((carrent_active_functions[3 ]  & ranguvannja_registrator[3 ] ) == 0) &&
        ((carrent_active_functions[4 ]  & ranguvannja_registrator[4 ] ) == 0) &&
        ((carrent_active_functions[5 ]  & ranguvannja_registrator[5 ] ) == 0) &&
        ((carrent_active_functions[6 ]  & ranguvannja_registrator[6 ] ) == 0) &&
        ((carrent_active_functions[7 ]  & ranguvannja_registrator[7 ] ) == 0) &&
        ((carrent_active_functions[8 ]  & ranguvannja_registrator[8 ] ) == 0) &&
        ((carrent_active_functions[9 ]  & ranguvannja_registrator[9 ] ) == 0) &&
        ((carrent_active_functions[10]  & ranguvannja_registrator[10]) == 0) &&
        ((carrent_active_functions[11]  & ranguvannja_registrator[11]) == 0) &&
        ((carrent_active_functions[12]  & ranguvannja_registrator[12]) == 0)
      )
    {
      //Зафіксовано, що ні одне джерело активації реєстратора зараз не активне
      
//      if (
//          ((carrent_active_functions[0]  & MASKA_FOR_CONTINUE_GET_DR_ACTINE_WORD_0)   == 0) &&
//          ((carrent_active_functions[1]  & MASKA_FOR_CONTINUE_GET_DR_ACTINE_WORD_1)   == 0) &&
//          ((carrent_active_functions[2]  & MASKA_FOR_CONTINUE_GET_DR_ACTINE_WORD_2)   == 0) &&
//          ((carrent_active_functions[3]  & MASKA_FOR_CONTINUE_GET_DR_ACTINE_WORD_3)   == 0) &&
//          ((carrent_active_functions[4]  & MASKA_FOR_CONTINUE_GET_DR_ACTINE_WORD_4)   == 0) &&
//          ((carrent_active_functions[5]  & MASKA_FOR_CONTINUE_GET_DR_ACTINE_WORD_5)   == 0) &&
//          ((carrent_active_functions[6]  & MASKA_FOR_CONTINUE_GET_DR_ACTINE_WORD_6)   == 0) &&
//          ((carrent_active_functions[7]  & MASKA_FOR_CONTINUE_GET_DR_ACTINE_WORD_7)   == 0) &&
//          ((carrent_active_functions[8]  & MASKA_FOR_CONTINUE_GET_DR_ACTINE_WORD_8)   == 0) &&
//          ((carrent_active_functions[9]  & MASKA_FOR_CONTINUE_GET_DR_ACTINE_WORD_9)   == 0) &&
//          ((carrent_active_functions[10] & MASKA_FOR_CONTINUE_GET_DR_ACTINE_WORD_10 ) == 0) &&
//          ((carrent_active_functions[11] & MASKA_FOR_CONTINUE_GET_DR_ACTINE_WORD_11 ) == 0) &&
//          ((carrent_active_functions[12] & MASKA_FOR_CONTINUE_GET_DR_ACTINE_WORD_12) == 0)
//        )
      if (
          ((carrent_active_functions[0]  & (unsigned int)CDRACTV_CMD_00 ) == 0) &&
          ((carrent_active_functions[1]  & (unsigned int)CDRACTV_CMD_01 ) == 0) &&
          ((carrent_active_functions[2]  & (unsigned int)CDRACTV_CMD_02 ) == 0) &&
          ((carrent_active_functions[3]  & (unsigned int)CDRACTV_CMD_03 ) == 0) &&
          ((carrent_active_functions[4]  & (unsigned int)CDRACTV_CMD_04 ) == 0) &&
          ((carrent_active_functions[5]  & (unsigned int)CDRACTV_CMD_05 ) == 0) &&
          ((carrent_active_functions[6]  & (unsigned int)CDRACTV_CMD_06 ) == 0) &&
          ((carrent_active_functions[7]  & (unsigned int)CDRACTV_CMD_07 ) == 0) &&
          ((carrent_active_functions[8]  & (unsigned int)CDRACTV_CMD_08 ) == 0) &&
          ((carrent_active_functions[9]  & (unsigned int)CDRACTV_CMD_09 ) == 0) &&
          ((carrent_active_functions[10] & (unsigned int)CDRACTV_CMD_10 ) == 0) &&
          ((carrent_active_functions[11] & (unsigned int)CDRACTV_CMD_11 ) == 0) &&
          ((carrent_active_functions[12] & (unsigned int)CDRACTV_CMD_12 ) == 0)
        )
      {
        //Зафіксовано, що всі функції, які можуть утримувати реєстратор активним зараз скинуті
          
        //Перевіряємо, чи всі таймери, які працють у логіці схеми виключені
        unsigned int global_timers_work = 0, i = INDEX_TIMER_DF_PAUSE_START;
        while ((i < NEXT_TIMER) && (global_timers_work == 0))
        {
          if (global_timers[i] >= 0) 
          {
            if (
                (
                 (i != INDEX_TIMER_PRYVOD_VV) ||
                 (  
                  ((current_settings_prt.control_switch & CTR_PRYVOD_VV) != 0) &&
                  (global_timers[i] < current_settings_prt.timeout_pryvoda_VV) 
                 )   
                ) 
                &&
                (i != INDEX_TIMER_ACHR_CHAPV_100MS_1)
                //&&
                //(i != INDEX_TIMER_NKN_DZ)
                &&
                (i != INDEX_TIMER_POSTFAULT)
                &&
                (i != INDEX_TIMER_FULL_AR_RECORD)
               )
            global_timers_work = 1;
          }
          i++;
        }
          
        if (global_timers_work == 0)
        {
          //Зафіксовано, що всі таймери, які працюють у лозіці неактивні
        
          //Помічаємо, що реєстратор може бути зупиненим
          stop = 0xff;
        }
      }
    }
  }
  
  return stop;
}
/*****************************************************/

/*****************************************************/
//Зафіксована невизначена помилка роботи дискретного реєстратора
/*****************************************************/
void fix_undefined_error_dr(unsigned int* carrent_active_functions)
{
  //Виставляємо помилку з записом в дисретний реєстратор
  _SET_BIT(set_diagnostyka, ERROR_DR_UNDEFINED_BIT);
  _SET_BIT(carrent_active_functions, RNG_BIG_DEFECT);//!@RANG_DEFECT
  //Переводимо режим роботи з реєстратором у сатн "На даний момент ніких дій з дискретним реєстратором не виконується" 
  state_dr_record = STATE_DR_NO_RECORD;
  //Скидаєсо сигнал роботи дискретного реєстратора
  _CLEAR_BIT(carrent_active_functions, RNG_BIG_WORK_D_REJESTRATOR);//!@RANG_WORK_D_REJESTRATOR
}
/*****************************************************/

/*****************************************************/
//Подача команди почати запис у DataFalsh
/*****************************************************/
inline void command_start_saving_record_dr_into_dataflash(void)
{
  //У структурі по інформації стану реєстраторів виставляємо повідомлення, що почався запис і ще не закінчився
  _SET_BIT(control_spi1_taskes, TASK_START_WRITE_INFO_REJESTRATOR_DR_EEPROM_BIT);
  info_rejestrator_dr.saving_execution = 1;
        
  //Виставляємо першу частину запису
  part_writing_dr_into_dataflash = 0;
  //Виставляємо команду запису у мікросхему DataFlash
  control_tasks_dataflash |= TASK_MAMORY_PAGE_PROGRAM_THROUGH_BUFFER_DATAFLASH_FOR_DR;
}
/*****************************************************/

/*****************************************************/
//Функція обробки черги зформованих записів дискретного реєстратора
/*****************************************************/
inline void routine_for_queue_dr(void)
{
  if(
     (state_dr_record == STATE_DR_MAKE_RECORD)            || /*Стоїть умова сформовані дані передати на запис у DataFlsh без повторного початку  нового запису, бо умова завершення запиу    досягнкта, а не стояла умова примусового завершення даного сформованого запису*/
     (state_dr_record == STATE_DR_CUT_RECORD)             || /*Стоїть умова сформовані дані передати на запис у DataFlsh   з повторним  початком нового запису, бо умова завершення запиу не досягнкта, а    стояла умова примусового завершення даного сформованого запису*/
     (number_records_dr_waiting_for_saving_operation != 0)  
    )
  {
    if ((control_tasks_dataflash & TASK_MAMORY_PAGE_PROGRAM_THROUGH_BUFFER_DATAFLASH_FOR_DR) == 0)
    {
      //На даний момент запису у Datafalsh не проводиться
      unsigned char *buffer_source, *buffer_target;
        
      if (number_records_dr_waiting_for_saving_operation == 0)
      {
        buffer_target = buffer_for_save_dr_record_level_2;
        buffer_source = buffer_for_save_dr_record;
        for(unsigned int i = 0; i < SIZE_BUFFER_FOR_DR_RECORD; i++)
        {
          *(buffer_target + i) = *(buffer_source + i);
          *(buffer_source + i) = 0xff;
        }
        number_records_dr_waiting_for_saving_operation = 0;
      }
      else if (number_records_dr_waiting_for_saving_operation == 1)
      {
        buffer_target = buffer_for_save_dr_record_level_2;
        buffer_source = buffer_for_save_dr_record_level_1;
        for(unsigned int i = 0; i < SIZE_BUFFER_FOR_DR_RECORD; i++) *(buffer_target +i ) = *(buffer_source + i);
        
        if((state_dr_record == STATE_DR_MAKE_RECORD) || (state_dr_record == STATE_DR_CUT_RECORD))
        {
          buffer_target = buffer_for_save_dr_record_level_1;
          buffer_source = buffer_for_save_dr_record;
          for(unsigned int i = 0; i < SIZE_BUFFER_FOR_DR_RECORD; i++) 
          {
            *(buffer_target + i) = *(buffer_source + i);
            *(buffer_source + i) = 0xff;
          }
          number_records_dr_waiting_for_saving_operation = 1;
        }
        else number_records_dr_waiting_for_saving_operation = 0;
      }
      else
      {
        buffer_target = buffer_for_save_dr_record_level_2;
        buffer_source = buffer_for_save_dr_record_level_1;
        for(unsigned int i = 0; i < SIZE_BUFFER_FOR_DR_RECORD; i++) *(buffer_target + i) = *(buffer_source + i);
        buffer_target = buffer_for_save_dr_record_level_1;
        buffer_source = buffer_for_save_dr_record;
        for(unsigned int i = 0; i < SIZE_BUFFER_FOR_DR_RECORD; i++) 
        {
          *(buffer_target + i) = *(buffer_source + i);
          *(buffer_source + i) = 0xff;
        }
        number_records_dr_waiting_for_saving_operation = 1;
      }
        
      //Подаємо команду почати запис у DataFalsh
      command_start_saving_record_dr_into_dataflash();
    }
    else
    {
      //На даний момент запису у Datafalsh проводиться
      //Треба наш теперішній запис поставити у чергу
      if (number_records_dr_waiting_for_saving_operation == 0)
      {
        //На даний момент крім того, буфера - з якого іде безпосередній запис у DataFalsh, більше ніяких записів у черзі немає
        //Переміщаємо текучий запис у буфер buffer_for_save_dr_record_level_1
        for(unsigned int i = 0; i < SIZE_BUFFER_FOR_DR_RECORD; i++) 
        {
          buffer_for_save_dr_record_level_1[i] = buffer_for_save_dr_record[i];
          buffer_for_save_dr_record[i] = 0xff;
        }
    
        //Помічаємо, що один запис очікує передау його на безпосередній запис у dataFalsh
        number_records_dr_waiting_for_saving_operation = 1;
      }
      else if (number_records_dr_waiting_for_saving_operation >= 1)
      {
         if((state_dr_record == STATE_DR_MAKE_RECORD) || (state_dr_record == STATE_DR_CUT_RECORD))
         {
          //На даний момент крім того, буфера - з якого іде безпосередній запис у DataFalsh, ще один сформований запис стоїть у буфері buffer_for_save_dr_record_level_1
          /*
          Тому даний запис залишаємо у цьому самому буфері buffer_for_save_dr_record, але збільшуємо кількість записів. які стоять у черзі
          і якщо буде спроба почати новий запис, то будемо фіксувати помилку втрати даних
          */
          number_records_dr_waiting_for_saving_operation = 2;
         }
      }
    }
    
    if (state_dr_record == STATE_DR_MAKE_RECORD)
    {
      //Помічаємо, що ми готові приймати наступний запис
      state_dr_record = STATE_DR_NO_RECORD;
    }
    else if (state_dr_record == STATE_DR_CUT_RECORD)
    {
      //Помічаємо, що треба примусово запустити новий запис
      state_dr_record = STATE_DR_FORCE_START_NEW_RECORD;
    }
      
  }
}
/*****************************************************/

/*****************************************************/
//Функція обробки логіки дискретного реєстратора
/*****************************************************/
inline void digital_registrator(unsigned int* carrent_active_functions)
{
  static unsigned int previous_active_functions[N_BIG];
  
  static unsigned int number_items_dr;
  static unsigned int number_changes_into_dr_record;
  static unsigned int time_from_start_record_dr;

  static uint8_t VMP_fix;
  static int32_t VMP_value;
  static uint8_t VMP_equal_more;
  
  switch (state_dr_record)
  {
  case STATE_DR_NO_RECORD:
  case STATE_DR_FORCE_START_NEW_RECORD:
    {
      //Попередньо скидаємо невизначену помилку  роботи дискретного реєстратора
      _SET_BIT(clear_diagnostyka, ERROR_DR_UNDEFINED_BIT);
      if(number_records_dr_waiting_for_saving_operation < (WIGHT_OF_DR_WAITING - 1))
      {
        //Ця ситуація означає, що як мінімум на один новий запис у нас є вільне місц, тому скидаємо сигналізацію про втрату даних
        _SET_BIT(clear_diagnostyka, ERROR_DR_TEMPORARY_BUSY_BIT);
      }
      
      //На початок аналізу покищо ще дискретний реєстратор не запущений
      
      //Аналізуємо, чи стоїть умова запуску дискретного реєстратора
       unsigned int cur_active_sources[N_BIG] =
       {
         (carrent_active_functions[0 ] & current_settings_prt.ranguvannja_digital_registrator[0 ]),
         (carrent_active_functions[1 ] & current_settings_prt.ranguvannja_digital_registrator[1 ]),
         (carrent_active_functions[2 ] & current_settings_prt.ranguvannja_digital_registrator[2 ]),
         (carrent_active_functions[3 ] & current_settings_prt.ranguvannja_digital_registrator[3 ]),
         (carrent_active_functions[4 ] & current_settings_prt.ranguvannja_digital_registrator[4 ]),
         (carrent_active_functions[5 ] & current_settings_prt.ranguvannja_digital_registrator[5 ]),
         (carrent_active_functions[6 ] & current_settings_prt.ranguvannja_digital_registrator[6 ]),
         (carrent_active_functions[7 ] & current_settings_prt.ranguvannja_digital_registrator[7 ]),
         (carrent_active_functions[8 ] & current_settings_prt.ranguvannja_digital_registrator[8 ]),
         (carrent_active_functions[9 ] & current_settings_prt.ranguvannja_digital_registrator[9 ]),
         (carrent_active_functions[10] & current_settings_prt.ranguvannja_digital_registrator[10]),
         (carrent_active_functions[11] & current_settings_prt.ranguvannja_digital_registrator[11]),
         (carrent_active_functions[12] & current_settings_prt.ranguvannja_digital_registrator[12])
       };
      if (
          (
           ((cur_active_sources[0 ]) != 0) ||
           ((cur_active_sources[1 ]) != 0) ||
           ((cur_active_sources[2 ]) != 0) ||
           ((cur_active_sources[3 ]) != 0) ||
           ((cur_active_sources[4 ]) != 0) ||
           ((cur_active_sources[5 ]) != 0) ||
           ((cur_active_sources[6 ]) != 0) ||
           ((cur_active_sources[7 ]) != 0) ||
           ((cur_active_sources[8 ]) != 0) ||
           ((cur_active_sources[9 ]) != 0) ||
           ((cur_active_sources[10]) != 0) ||
           ((cur_active_sources[11]) != 0) ||
           ((cur_active_sources[12]) != 0) ||
           (state_dr_record == STATE_DR_FORCE_START_NEW_RECORD)
          )   
         )
      {
        //Є умова запуску дискретного реєстратора
        
        if (state_dr_record != STATE_DR_FORCE_START_NEW_RECORD)
        {
          /*мітку по ВМП роблю до перевірки чи можна запустити новий запис, щоб у випадку якщо зараз не можна запустити новий запис то вже коли його можна буде розпочати, то теоретично ВМП може бути вже розрахованим*/
          VMP_fix = false;
          VMP_equal_more = 0;
          VMP_value = VMP_last_KZ = UNDEF_VMP; /*Помічаємо, що визначення місця до пошкодження ще не визначене  з початку роботи дискретного реєстратора*/
        }
          
        //Перевіряємо, чи при початку нового запису ми не втратимо попередню інформацію
        if(number_records_dr_waiting_for_saving_operation < WIGHT_OF_DR_WAITING)
        {
          //Можна починати новий запис
          
          //Переводимо режим роботи із дискретним реєстратором у стан "Іде процес запису реєстратора"
          state_dr_record = STATE_DR_EXECUTING_RECORD;
          //Виставляємо активну функцію
          _SET_BIT(carrent_active_functions, RNG_BIG_WORK_D_REJESTRATOR);//!@RANG_WORK_D_REJESTRATOR
        
          //Записуємо мітку початку запису
          buffer_for_save_dr_record[FIRST_INDEX_START_START_RECORD_DR] = LABEL_START_RECORD_DR;
         
          //Записуємо час початку запису
          for(size_t i = 0; i < sizeof(time_t); i++)  buffer_for_save_dr_record[FIRST_INDEX_DATA_TIME_DR + i] = *((unsigned char*)(&time_dat) + i);
          for(size_t i = 0; i < sizeof(int32_t); i++)  buffer_for_save_dr_record[FIRST_INDEX_DATA_TIME_DR + sizeof(time_t) + i] = *((unsigned char*)(&time_ms) + i);
          
           //І'мя комірки
          for(unsigned int i=0; i< MAX_CHAR_IN_NAME_OF_CELL; i++) 
            buffer_for_save_dr_record[FIRST_INDEX_NAME_OF_CELL_DR + i] = current_settings_prt.name_of_cell[i] & 0xff;

           //Джерела запуску
          for(unsigned int i = 0; i < NUMBER_BYTES_SAMPLE_DR; i++) 
            buffer_for_save_dr_record[FIRST_INDEX_SOURCE_DR + i] = *(((unsigned char*)cur_active_sources) + i);

          //Записуємо попередній cтан сигналів перед аварією
          //Мітка часу попереднього стану сигналів до моменту початку запису
          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR +  0] = 0xff;
          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR +  1] = 0xff;
          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR +  2] = 0xff;

          //Помічаємо скільки часу пройшло з початку запуску запису
          time_from_start_record_dr = 0;
          
          //Помічаємо кількість нових зрізів
          number_items_dr = 1;
      
          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR +  0] =  time_from_start_record_dr        & 0xff;
          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR +  1] = (time_from_start_record_dr >> 8 ) & 0xff;
          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR +  2] = (time_from_start_record_dr >> 16) & 0xff;
          
          for (size_t i = 0; i < NUMBER_BYTES_SAMPLE_DR; ++i)
          {
            size_t offset = i >> 2;
            size_t shift = 8*(i & ((1u << 2) - 1));
            
            buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR                        + 3 + i] = (previous_active_functions[offset] >> shift) & 0xff;

           buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 3 + i] = (carrent_active_functions[offset] >> shift) & 0xff;;
          }
          //Нулем позначаємо у цій позиції кількість змін
          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + 3 + NUMBER_BYTES_SAMPLE_DR + 0] = 0;
          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + 3 + NUMBER_BYTES_SAMPLE_DR + 1] = 0;

          //Вираховуємо кількість змін сигналів
          number_changes_into_dr_record = 0;
          unsigned int number_changes_into_current_item;
          _NUMBER_CHANGES_INTO_UNSIGNED_INT_ARRAY(previous_active_functions, carrent_active_functions, N_BIG, number_changes_into_current_item);
          number_changes_into_dr_record += number_changes_into_current_item;
      
          //Кількість змін сигналів у порівнянні із попереднім станом
          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 3 + NUMBER_BYTES_SAMPLE_DR + 0] = number_changes_into_current_item & 0xff;
          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 3 + NUMBER_BYTES_SAMPLE_DR + 1] = (number_changes_into_current_item >> 8) & 0xff;
          
//          //Попередній стан
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR +  3] =  previous_active_functions[0]        & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR +  4] = (previous_active_functions[0] >> 8 ) & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR +  5] = (previous_active_functions[0] >> 16) & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR +  6] = (previous_active_functions[0] >> 24) & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR +  7] =  previous_active_functions[1]        & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR +  8] = (previous_active_functions[1] >> 8)  & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR +  9] = (previous_active_functions[1] >> 16) & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + 10] = (previous_active_functions[1] >> 24) & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + 11] =  previous_active_functions[2]        & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + 12] = (previous_active_functions[2] >> 8)  & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + 13] = (previous_active_functions[2] >> 16) & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + 14] = (previous_active_functions[2] >> 24) & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + 15] =  previous_active_functions[3]        & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + 16] = (previous_active_functions[3] >> 8)  & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + 17] = (previous_active_functions[3] >> 16) & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + 18] = (previous_active_functions[3] >> 24) & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + 19] =  previous_active_functions[4]        & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + 20] = (previous_active_functions[4] >> 8)  & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + 21] = (previous_active_functions[4] >> 16) & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + 22] = (previous_active_functions[4] >> 24) & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + 23] =  previous_active_functions[5]        & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + 24] = (previous_active_functions[5] >> 8)  & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + 25] = (previous_active_functions[5] >> 16) & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + 26] = (previous_active_functions[5] >> 24) & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + 27] =  previous_active_functions[6]        & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + 28] = (previous_active_functions[6] >> 8)  & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + 29] = (previous_active_functions[6] >> 16) & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + 30] = (previous_active_functions[6] >> 24) & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + 31] =  previous_active_functions[7]        & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + 32] = (previous_active_functions[7] >> 8)  & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + 33] = (previous_active_functions[7] >> 16) & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + 34] = (previous_active_functions[7] >> 24) & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + 35] =  previous_active_functions[8]        & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + 36] = (previous_active_functions[8] >> 8)  & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + 37] = (previous_active_functions[8] >> 16) & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + 38] = (previous_active_functions[8] >> 24) & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + 39] =  previous_active_functions[9]        & 0xff;
//          //Нулем позначаємо у цій позиції кількість змін
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + 40] = 0;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + 41] = 0;
//
//          //Помічаємо кількість нових зрізів
//          number_items_dr = 1;
//      
//          //Вираховуємо кількість змін сигналів
//          number_changes_into_dr_record = 0;
//          unsigned int number_changes_into_current_item;
//          _NUMBER_CHANGES_INTO_UNSIGNED_INT_ARRAY(previous_active_functions, carrent_active_functions, N_BIG, number_changes_into_current_item);
//          number_changes_into_dr_record += number_changes_into_current_item;
//      
//          //Записуємо текучий cтан сигналів
//          //Мітка часу
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR +  0] =  time_from_start_record_dr        & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR +  1] = (time_from_start_record_dr >> 8 ) & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR +  2] = (time_from_start_record_dr >> 16) & 0xff;
//          //Текучий стан сигналів
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR +  3] =  carrent_active_functions[0]        & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR +  4] = (carrent_active_functions[0] >> 8 ) & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR +  5] = (carrent_active_functions[0] >> 16) & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR +  6] = (carrent_active_functions[0] >> 24) & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR +  7] =  carrent_active_functions[1]        & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR +  8] = (carrent_active_functions[1] >> 8 ) & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR +  9] = (carrent_active_functions[1] >> 16) & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 10] = (carrent_active_functions[1] >> 24) & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 11] =  carrent_active_functions[2]        & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 12] = (carrent_active_functions[2] >> 8 ) & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 13] = (carrent_active_functions[2] >> 16) & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 14] = (carrent_active_functions[2] >> 24) & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 15] =  carrent_active_functions[3]        & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 16] = (carrent_active_functions[3] >> 8 ) & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 17] = (carrent_active_functions[3] >> 16) & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 18] = (carrent_active_functions[3] >> 24) & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 19] =  carrent_active_functions[4]        & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 20] = (carrent_active_functions[4] >> 8 ) & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 21] = (carrent_active_functions[4] >> 16) & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 22] = (carrent_active_functions[4] >> 24) & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 23] =  carrent_active_functions[5]        & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 24] = (carrent_active_functions[5] >> 8 ) & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 25] = (carrent_active_functions[5] >> 16) & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 26] = (carrent_active_functions[5] >> 24) & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 27] =  carrent_active_functions[6]        & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 28] = (carrent_active_functions[6] >> 8 ) & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 29] = (carrent_active_functions[6] >> 16) & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 30] = (carrent_active_functions[6] >> 24) & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 31] =  carrent_active_functions[7]        & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 32] = (carrent_active_functions[7] >> 8 ) & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 33] = (carrent_active_functions[7] >> 16) & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 34] = (carrent_active_functions[7] >> 24) & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 35] =  carrent_active_functions[8]        & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 36] = (carrent_active_functions[8] >> 8 ) & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 37] = (carrent_active_functions[8] >> 16) & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 38] = (carrent_active_functions[8] >> 24) & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 39] =  carrent_active_functions[9]        & 0xff;
//          
//          //Кількість змін сигналів у порівнянні із попереднім станом
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 40] = number_changes_into_current_item & 0xff;
//          buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 41] = (number_changes_into_current_item >> 8) & 0xff;
      
//          //Решту масиву очищаємо, щоб у запис не пішла інформація із попередніх записів
//          for(unsigned int i = FIRST_INDEX_FIRST_BLOCK_DR; i < FIRST_INDEX_FIRST_DATA_DR; i++)
//            buffer_for_save_dr_record[i] = 0xff;
//          for(unsigned int i = (FIRST_INDEX_FIRST_DATA_DR + (number_items_dr + 1)*SD_DR); i < SIZE_BUFFER_FOR_DR_RECORD; i++)
//            buffer_for_save_dr_record[i] = 0xff;
          
          /*Якщо дискретний реєстратор мав почати формувати запис раніше але через неможливість тоді його розпочати, то може бути ситуація. що вже є визначене місце до пошкодження тут*/
          if(VMP_last_KZ != UNDEF_VMP)
          {
            VMP_fix = true;
            VMP_value = VMP_last_KZ;
            VMP_equal_more = equal_more_KZ;
          }
        }
        else
        {
          //Виставляємо помилку, що є умова на роботу дискретного реєстратора тоді, як всі вільні буфери зайняті
          _SET_BIT(set_diagnostyka, ERROR_DR_TEMPORARY_BUSY_BIT);
          _SET_BIT(carrent_active_functions, RNG_BIG_DEFECT);//!@RANG_DEFECT
        }
      }
      else state_dr_record = STATE_DR_NO_RECORD;
      
      break;
    }
  case STATE_DR_EXECUTING_RECORD:
    {
      //Збільшуємо час з початку запуску запису
      time_from_start_record_dr++;
      //Включно до цього часу іде процес запису

      if(
         (VMP_last_KZ != UNDEF_VMP) &&
         (
          (VMP_fix == false) ||
          (abs(VMP_value) > abs(VMP_last_KZ)) ||
          (
           (equal_more_KZ != VMP_equal_more) &&
           (equal_more_KZ == true)
          )
         )   
        )   
      {
         VMP_fix = true;
         VMP_value = VMP_last_KZ;
         VMP_equal_more = equal_more_KZ;
       }
      
      //Перевіряємо, чи ще існує умова продовження запису
      //Якщо такої умови немає - то скидаємо сигнал запущеного дискретного реєстратора, що це зафіксувати у змінених сигналах
      if (stop_regisrator(carrent_active_functions, current_settings_prt.ranguvannja_digital_registrator) != 0)
      {
        //Скидаємо сигнал роботи дискретного реєстратора
        _CLEAR_BIT(carrent_active_functions, RNG_BIG_WORK_D_REJESTRATOR);//!@RANG_WORK_D_REJESTRATOR

        //Переводимо режим роботи із дискретним реєстратором у стан "Виконується безпосередній запис у послідовну DataFlash"
        state_dr_record = STATE_DR_MAKE_RECORD;
      }
      
      //Перевіряємо чи відбуласа зміна сигналів у порівнянні із попереднім станом. Якщо така зміна є, то формуєм новий зріз сигналів у записі
      if (
          ((carrent_active_functions[0 ] != previous_active_functions[0 ])) ||
          ((carrent_active_functions[1 ] != previous_active_functions[1 ])) ||
          ((carrent_active_functions[2 ] != previous_active_functions[2 ])) ||
          ((carrent_active_functions[3 ] != previous_active_functions[3 ])) ||
          ((carrent_active_functions[4 ] != previous_active_functions[4 ])) ||
          ((carrent_active_functions[5 ] != previous_active_functions[5 ])) ||
          ((carrent_active_functions[6 ] != previous_active_functions[6 ])) ||
          ((carrent_active_functions[7 ] != previous_active_functions[7 ])) ||
          ((carrent_active_functions[8 ] != previous_active_functions[8 ])) ||
          ((carrent_active_functions[9 ] != previous_active_functions[9 ])) ||
          ((carrent_active_functions[10] != previous_active_functions[10])) || 
          ((carrent_active_functions[11] != previous_active_functions[11])) || 
          ((carrent_active_functions[12] != previous_active_functions[12])) 
         )
      {
        //Теперішній стан сигналів не співпадає з попереднім станом сигналів

        //Збільшуємо на один кількість нових зрізів
        number_items_dr++;

        //Вираховуємо кількість змін сигналів
        unsigned int number_changes_into_current_item;
        _NUMBER_CHANGES_INTO_UNSIGNED_INT_ARRAY(previous_active_functions, carrent_active_functions, N_BIG, number_changes_into_current_item);
        number_changes_into_dr_record += number_changes_into_current_item;
      
        //Записуємо поточний cтан сигналів
        buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR +  0] =  time_from_start_record_dr        & 0xff;
        buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR +  1] = (time_from_start_record_dr >> 8 ) & 0xff;
        buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR +  2] = (time_from_start_record_dr >> 16) & 0xff;

        for (size_t i = 0; i < NUMBER_BYTES_SAMPLE_DR; ++i)
        {
          size_t offset = i >> 2;
          size_t shift = 8*(i & ((1u << 2) - 1));
             
         buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 3 + i] = (carrent_active_functions[offset] >> shift) & 0xff;;
        }
        //Кількість змін сигналів у порівнянні із попереднім станом
        buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 3 + NUMBER_BYTES_SAMPLE_DR + 0] = number_changes_into_current_item & 0xff;
        buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 3 + NUMBER_BYTES_SAMPLE_DR + 1] = (number_changes_into_current_item >> 8) & 0xff;
        
//        //Вираховуємо кількість змін сигналів
//        unsigned int number_changes_into_current_item;
//        _NUMBER_CHANGES_INTO_UNSIGNED_INT_ARRAY(previous_active_functions, carrent_active_functions, N_BIG, number_changes_into_current_item);
//        number_changes_into_dr_record += number_changes_into_current_item;
//
//        //Записуємо текучий cтан сигналів
//        //Мітка часу
//        buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR +  0] =  time_from_start_record_dr        & 0xff;
//        buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR +  1] = (time_from_start_record_dr >> 8 ) & 0xff;
//        buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR +  2] = (time_from_start_record_dr >> 16) & 0xff;
//        //Текучий стан сигналів
//        buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR +  3] =  carrent_active_functions[0]        & 0xff;
//        buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR +  4] = (carrent_active_functions[0] >> 8 ) & 0xff;
//        buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR +  5] = (carrent_active_functions[0] >> 16) & 0xff;
//        buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR +  6] = (carrent_active_functions[0] >> 24) & 0xff;
//        buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR +  7] =  carrent_active_functions[1]        & 0xff;
//        buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR +  8] = (carrent_active_functions[1] >> 8 ) & 0xff;
//        buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR +  9] = (carrent_active_functions[1] >> 16) & 0xff;
//        buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 10] = (carrent_active_functions[1] >> 24) & 0xff;
//        buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 11] =  carrent_active_functions[2]        & 0xff;
//        buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 12] = (carrent_active_functions[2] >> 8 ) & 0xff;
//        buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 13] = (carrent_active_functions[2] >> 16) & 0xff;
//        buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 14] = (carrent_active_functions[2] >> 24) & 0xff;
//        buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 15] =  carrent_active_functions[3]        & 0xff;
//        buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 16] = (carrent_active_functions[3] >> 8 ) & 0xff;
//        buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 17] = (carrent_active_functions[3] >> 16) & 0xff;
//        buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 18] = (carrent_active_functions[3] >> 24) & 0xff;
//        buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 19] =  carrent_active_functions[4]        & 0xff;
//        buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 20] = (carrent_active_functions[4] >> 8 ) & 0xff;
//        buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 21] = (carrent_active_functions[4] >> 16) & 0xff;
//        buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 22] = (carrent_active_functions[4] >> 24) & 0xff;
//        buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 23] =  carrent_active_functions[5]        & 0xff;
//        buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 24] = (carrent_active_functions[5] >> 8 ) & 0xff;
//        buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 25] = (carrent_active_functions[5] >> 16) & 0xff;
//        buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 26] = (carrent_active_functions[5] >> 24) & 0xff;
//        buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 27] =  carrent_active_functions[6]        & 0xff;
//        buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 28] = (carrent_active_functions[6] >> 8 ) & 0xff;
//        buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 29] = (carrent_active_functions[6] >> 16) & 0xff;
//        buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 30] = (carrent_active_functions[6] >> 24) & 0xff;
//        buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 31] =  carrent_active_functions[7]        & 0xff;
//        buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 32] = (carrent_active_functions[7] >> 8 ) & 0xff;
//        buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 33] = (carrent_active_functions[7] >> 16) & 0xff;
//        buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 34] = (carrent_active_functions[7] >> 24) & 0xff;
//        buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 35] =  carrent_active_functions[8]        & 0xff;
//        buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 36] = (carrent_active_functions[8] >> 8 ) & 0xff;
//        buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 37] = (carrent_active_functions[8] >> 16) & 0xff;
//        buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 38] = (carrent_active_functions[8] >> 24) & 0xff;
//        buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 39] =  carrent_active_functions[9]        & 0xff;
//        //Кількість змін сигналів у порівнянні із попереднім станом
//        buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 40] = number_changes_into_current_item & 0xff;
//        buffer_for_save_dr_record[FIRST_INDEX_FIRST_DATA_DR + number_items_dr*SD_DR + 41] = (number_changes_into_current_item >> 8) & 0xff;
      }
        
      //Перевіряємо, чи стоїть умова завершення запису
      if (
          (state_dr_record == STATE_DR_MAKE_RECORD)                  ||
          (time_from_start_record_dr >= MAX_TIME_OFFSET_FROM_START)  ||  
          ((number_items_dr + 1)     >= MAX_EVENTS_IN_ONE_RECORD  )  
         )
      {
        //Немає умови продовження запису, або є умова завершення запису - завершуємо формування запису і подаємо команду на запис
        buffer_for_save_dr_record[FIRST_INDEX_NUMBER_ITEMS_DR      ] = number_items_dr;
        buffer_for_save_dr_record[FIRST_INDEX_NUMBER_CHANGES_DR    ] =  number_changes_into_dr_record       & 0xff;
        buffer_for_save_dr_record[FIRST_INDEX_NUMBER_CHANGES_DR + 1] = (number_changes_into_dr_record >> 8) & 0xff;

        buffer_for_save_dr_record[FIRST_INDEX_VMP_VALUE    ] =  VMP_value        & 0xff;
        buffer_for_save_dr_record[FIRST_INDEX_VMP_VALUE + 1] = (VMP_value >>  8) & 0xff;
        buffer_for_save_dr_record[FIRST_INDEX_VMP_VALUE + 2] = (VMP_value >> 16) & 0xff;
        buffer_for_save_dr_record[FIRST_INDEX_VMP_VALUE + 3] = (VMP_value >> 24) & 0xff;
        buffer_for_save_dr_record[FIRST_INDEX_VMP_EQUAL_MORE] = VMP_equal_more;
        
        //Переводимо режим роботи із дискретним реєстратором у стан "Виконується безпосередній запис у DataFlash"
        if (state_dr_record != STATE_DR_MAKE_RECORD)
        {
          if (time_from_start_record_dr >= MAX_TIME_OFFSET_FROM_START)
          {
            //Якщо відбулося перевищення по часу запису, то подаємо команду завершити запис без продовження потім цього запису у наступному записі
            state_dr_record = STATE_DR_MAKE_RECORD;
          }
          else
          {
            //Якщо відбулося перевищення по досягнкнні максимальної кількості зрізів (або іншої причини, яка покищо не оговорена, але може з'явитися у майбутньому), то подаємо команду завершити запис але на наступному проході почати новий запис
            state_dr_record = STATE_DR_CUT_RECORD;
          }
        }
        
        //Скидаємо сигнал роботи дискретного реєстратора
        _CLEAR_BIT(carrent_active_functions, RNG_BIG_WORK_D_REJESTRATOR);//!@RANG_WORK_D_REJESTRATOR
      }

      break;
    }
  default:
    {
      //По ідеї сюди програма ніколи не мала б зайти
      fix_undefined_error_dr(carrent_active_functions);
      break;
    }
  }
  
  //Перевіряємо, чи стоїть умова сформований запис передати на запис у DataFlash
  routine_for_queue_dr();

  /*********************/
  //Формуємо попереденій стан сигналів для функції ввімкнення/вимкнення
  /*********************/
  for (unsigned int i = 0; i < N_BIG; i++) previous_active_functions[i] = carrent_active_functions[i];
  /*********************/
}
/*****************************************************/

/*****************************************************/
//Функція обробки логіки дискретного реєстратора
/*****************************************************/
inline void analog_registrator(unsigned int* carrent_active_functions)
{
  static unsigned int prev_active_sources[N_BIG];
  unsigned int cur_active_sources[N_BIG] = 
  {
    carrent_active_functions[0 ] & current_settings_prt.ranguvannja_analog_registrator[0 ],
    carrent_active_functions[1 ] & current_settings_prt.ranguvannja_analog_registrator[1 ],
    carrent_active_functions[2 ] & current_settings_prt.ranguvannja_analog_registrator[2 ],
    carrent_active_functions[3 ] & current_settings_prt.ranguvannja_analog_registrator[3 ],
    carrent_active_functions[4 ] & current_settings_prt.ranguvannja_analog_registrator[4 ],
    carrent_active_functions[5 ] & current_settings_prt.ranguvannja_analog_registrator[5 ],
    carrent_active_functions[6 ] & current_settings_prt.ranguvannja_analog_registrator[6 ],
    carrent_active_functions[7 ] & current_settings_prt.ranguvannja_analog_registrator[7 ],
    carrent_active_functions[8 ] & current_settings_prt.ranguvannja_analog_registrator[8 ],
    carrent_active_functions[9 ] & current_settings_prt.ranguvannja_analog_registrator[9 ],
    carrent_active_functions[10] & current_settings_prt.ranguvannja_analog_registrator[10],
    carrent_active_functions[11] & current_settings_prt.ranguvannja_analog_registrator[11],
    carrent_active_functions[12] & current_settings_prt.ranguvannja_analog_registrator[12]
  };

  if (forbidden_new_record_ar_mode_0 != 0)
  {
    /*
    Ця ситуація означає, що були активними джерела аналогового реєстратора, які запустили
    в роботу аналоговий реєстратор, і тепер для розблокування можливості запускати новий запис ми 
    чекаємо ситуації, що
    - всі джерела активації деактивуються 
    - появитьс новий сигнал запуску, якого не було раніше
    */
    if(
       (cur_active_sources[0 ] == 0) &&
       (cur_active_sources[1 ] == 0) &&
       (cur_active_sources[2 ] == 0) &&
       (cur_active_sources[3 ] == 0) &&
       (cur_active_sources[4 ] == 0) &&
       (cur_active_sources[5 ] == 0) &&
       (cur_active_sources[6 ] == 0) &&
       (cur_active_sources[7 ] == 0) &&
       (cur_active_sources[8 ] == 0) &&
       (cur_active_sources[9 ] == 0) &&
       (cur_active_sources[10] == 0) && 
       (cur_active_sources[11] == 0) && 
       (cur_active_sources[12] == 0) 
      ) 
    {
      //Перша умова розблокування можливості початку нового запису виконана
      forbidden_new_record_ar_mode_0 = 0;
    }
    else if ((current_settings_prt.control_ar & CTR_AR_AVAR_STATE) == 0)
    {
      //Попередній запис повністю записаний у DataFlash, але ще деякі джерела активації не деакттивувалися
      unsigned int diff_active_sources[N_BIG];
      diff_active_sources[0 ] = prev_active_sources[0 ] ^ cur_active_sources[0 ];
      diff_active_sources[1 ] = prev_active_sources[1 ] ^ cur_active_sources[1 ];
      diff_active_sources[2 ] = prev_active_sources[2 ] ^ cur_active_sources[2 ];
      diff_active_sources[3 ] = prev_active_sources[3 ] ^ cur_active_sources[3 ];
      diff_active_sources[4 ] = prev_active_sources[4 ] ^ cur_active_sources[4 ];
      diff_active_sources[5 ] = prev_active_sources[5 ] ^ cur_active_sources[5 ];
      diff_active_sources[6 ] = prev_active_sources[6 ] ^ cur_active_sources[6 ];
      diff_active_sources[7 ] = prev_active_sources[7 ] ^ cur_active_sources[7 ];
      diff_active_sources[8 ] = prev_active_sources[8 ] ^ cur_active_sources[8 ];
      diff_active_sources[9 ] = prev_active_sources[9 ] ^ cur_active_sources[9 ];
      diff_active_sources[10] = prev_active_sources[10] ^ cur_active_sources[10];
      diff_active_sources[11] = prev_active_sources[11] ^ cur_active_sources[11];
      diff_active_sources[12] = prev_active_sources[12] ^ cur_active_sources[12];

      if(
         ((diff_active_sources[0 ] & cur_active_sources[0 ]) != 0) ||
         ((diff_active_sources[1 ] & cur_active_sources[1 ]) != 0) ||
         ((diff_active_sources[2 ] & cur_active_sources[2 ]) != 0) ||
         ((diff_active_sources[3 ] & cur_active_sources[3 ]) != 0) ||
         ((diff_active_sources[4 ] & cur_active_sources[4 ]) != 0) ||
         ((diff_active_sources[5 ] & cur_active_sources[5 ]) != 0) ||
         ((diff_active_sources[6 ] & cur_active_sources[6 ]) != 0) ||
         ((diff_active_sources[7 ] & cur_active_sources[7 ]) != 0) ||
         ((diff_active_sources[8 ] & cur_active_sources[8 ]) != 0) ||
         ((diff_active_sources[9 ] & cur_active_sources[9 ]) != 0) ||
         ((diff_active_sources[10] & cur_active_sources[10]) != 0) || 
         ((diff_active_sources[11] & cur_active_sources[11]) != 0) || 
         ((diff_active_sources[12] & cur_active_sources[12]) != 0) 
        ) 
      {
        //Друга умова розблокування можливості початку нового запису виконана
        forbidden_new_record_ar_mode_0 = 0;
      }
    }
  }

  if (
      (global_timers[INDEX_TIMER_FULL_AR_RECORD] >= MAX_TIME_FULL_AR_RECORD) ||
      (state_ar_record_m == STATE_AR_BLOCK_M) ||
      (state_ar_record_fatfs == STATE_AR_MEMORY_FULL_FATFS) ||
      (state_ar_record_fatfs == STATE_AR_BLOCK_FATFS)
     )   
  {
    if (global_timers[INDEX_TIMER_FULL_AR_RECORD] >= MAX_TIME_FULL_AR_RECORD) _SET_BIT(set_diagnostyka, ERROR_AR_TEMPORARY_BUSY_BIT);

    state_ar_record_prt = STATE_AR_BLOCK_PRT;
    global_timers[INDEX_TIMER_POSTFAULT] = -1;
    global_timers[INDEX_TIMER_FULL_AR_RECORD] = -1;
  }
  
  switch (state_ar_record_prt)
  {
  case STATE_AR_NONE_PRT:
    {
      if (state_ar_record_fatfs == STATE_AR_NONE_FATFS)
      {
        global_timers[INDEX_TIMER_FULL_AR_RECORD] = -1;
        _SET_BIT(clear_diagnostyka, ERROR_AR_TEMPORARY_BUSY_BIT);
      }

      //Аналізуємо, чи стоїть умова запуску аналогового реєстратора
      if (
          (
           (cur_active_sources[0 ] != 0) ||
           (cur_active_sources[1 ] != 0) ||
           (cur_active_sources[2 ] != 0) ||
           (cur_active_sources[3 ] != 0) ||
           (cur_active_sources[4 ] != 0) ||
           (cur_active_sources[5 ] != 0) ||
           (cur_active_sources[6 ] != 0) ||
           (cur_active_sources[7 ] != 0) ||
           (cur_active_sources[8 ] != 0) ||
           (cur_active_sources[9 ] != 0) ||
           (cur_active_sources[10] != 0) ||
           (cur_active_sources[11] != 0) ||
           (cur_active_sources[12] != 0)
          )
          &&  
          (forbidden_new_record_ar_mode_0 == 0) /*при попередній роботі ан.реєстротора (якщо така була) вже всі джерела активації були зняті і зароз вони знову виникли*/ 
         )
      {
        //Є умова запуску аналогового реєстратора

        if (state_ar_record_fatfs != STATE_AR_STOP_WRITE_FATFS)
        {
          //Переводимо режим роботи із аналоговим реєстратором у стан "Запус нового запису"
          if (current_settings_prt.control_ar & CTR_AR_AVAR_STATE)
          {
            state_ar_record_prt = STATE_AR_AVAR_PRT;
          }
          else
          {
            state_ar_record_prt = STATE_AR_POSTAVAR_PRT;
            global_timers[INDEX_TIMER_POSTFAULT] = 0; //Запускаємо таймер післяаварійного процесу
          }
        
          if (state_ar_record_fatfs == STATE_AR_NONE_FATFS)
          {
            //запис на рівні FATFs зараз не проводиться, тому треба підготувати інформацію про умову старту нового запису
          
             global_timers[INDEX_TIMER_FULL_AR_RECORD] = 20*current_settings_prt.prefault_number_periods; //Запускаємо таймер цілого запису  з врахуванням щбуде доданий доаварійний масив
          
            //Записуємо мітку початку запису
            header_ar.label_start_record = LABEL_START_RECORD_AR;
            //Записуємо час початку запису
            header_ar.time_dat = time_dat;
            header_ar.time_ms = time_ms;
            //Коефіцієнт трансформації T0
            header_ar.T0 = current_settings_prt.T0;
            //Коефіцієнт трансформації TT
            header_ar.TCurrent = current_settings_prt.TCurrent;
            //Коефіцієнт трансформації TН
            header_ar.TVoltage = current_settings_prt.TVoltage;
            //Час доаварійного масиву
            header_ar.prefault_number_periods = current_settings_prt.prefault_number_periods;
            //І'мя комірки
            for(unsigned int i=0; i<MAX_CHAR_IN_NAME_OF_CELL; i++)
              header_ar.name_of_cell[i] = current_settings_prt.name_of_cell[i] & 0xff;
            //Сигнали, які запустили в роботу Аналоговий реєстратор
            for (size_t i = 0; i < N_BIG; i++)
              header_ar.cur_active_sources[i] = (prev_active_sources[i] ^ cur_active_sources[i]) & cur_active_sources[i];
          }
        }
        else
        {
          _SET_BIT(set_diagnostyka, ERROR_AR_TEMPORARY_BUSY_BIT);
        }
      }

      break;
    }
  case STATE_AR_AVAR_PRT:
    {
      if (
          (
           (cur_active_sources[0 ] == 0) &&
           (cur_active_sources[1 ] == 0) &&
           (cur_active_sources[2 ] == 0) &&
           (cur_active_sources[3 ] == 0) &&
           (cur_active_sources[4 ] == 0) &&
           (cur_active_sources[5 ] == 0) &&
           (cur_active_sources[6 ] == 0) &&
           (cur_active_sources[7 ] == 0) &&
           (cur_active_sources[8 ] == 0) &&
           (cur_active_sources[9 ] == 0) &&
           (cur_active_sources[10] == 0) &&
           (cur_active_sources[11] == 0) &&
           (cur_active_sources[12] == 0)
          )
          || 
          ((current_settings_prt.control_ar & CTR_AR_AVAR_STATE) == 0) /*може статися хіба, коли під час роботи ан.реєстратора змінено це налаштування*/
         )
      {
        state_ar_record_prt = STATE_AR_POSTAVAR_PRT;
        global_timers[INDEX_TIMER_POSTFAULT] = 0; //Запускаємо таймер післяаварійного процесу
      }
      
      break;
    }
  case STATE_AR_POSTAVAR_PRT:
    {
      if (
          ((current_settings_prt.control_ar & CTR_AR_AVAR_STATE) != 0) &&
          (
           (cur_active_sources[0 ] != 0) ||
           (cur_active_sources[1 ] != 0) ||
           (cur_active_sources[2 ] != 0) ||
           (cur_active_sources[3 ] != 0) ||
           (cur_active_sources[4 ] != 0) ||
           (cur_active_sources[5 ] != 0) ||
           (cur_active_sources[6 ] != 0) ||
           (cur_active_sources[7 ] != 0) ||
           (cur_active_sources[8 ] != 0) ||
           (cur_active_sources[9 ] != 0) ||
           (cur_active_sources[10] != 0) ||
           (cur_active_sources[11] != 0) ||
           (cur_active_sources[12] != 0)
          )
         )
      {
        //Повертаємося до аварійного процесу
        state_ar_record_prt = STATE_AR_AVAR_PRT;
        global_timers[INDEX_TIMER_POSTFAULT] = -1; //Зупиняємо таймер післяаварійного процесу
      }
      else if (global_timers[INDEX_TIMER_POSTFAULT] >= (int)(20*current_settings_prt.postfault_number_periods))
      {
        //Завершився післяаварійний процес
        global_timers[INDEX_TIMER_POSTFAULT] = -1; //Зупиняємо таймер післяаварійного процесу
        state_ar_record_prt = STATE_AR_NONE_PRT;
        
        if (
            /*перевірку на те, що режим "Власнеаварійний процес" ввімкнутий не треба, бо при умові активних джерел ми б попали у попередню умову де з післяаваріного процесу йде поворот до аварійного процесу*/
            (cur_active_sources[0 ] != 0) ||
            (cur_active_sources[1 ] != 0) ||
            (cur_active_sources[2 ] != 0) ||
            (cur_active_sources[3 ] != 0) ||
            (cur_active_sources[4 ] != 0) ||
            (cur_active_sources[5 ] != 0) ||
            (cur_active_sources[6 ] != 0) ||
            (cur_active_sources[7 ] != 0) ||
            (cur_active_sources[8 ] != 0) ||
            (cur_active_sources[9 ] != 0) ||
            (cur_active_sources[10] != 0) ||
            (cur_active_sources[11] != 0) ||
            (cur_active_sources[12] != 0)
           )
        {
          forbidden_new_record_ar_mode_0 = 0xff; /*помічаємо будь-яким числом, що є активними деякі сигнали від попереднього записту*/
        }
      }
      
      break;
    }
  case STATE_AR_BLOCK_PRT:
    {
      //Аналізуємо чи немає умови почати новий запис поки ми не вийшли з блокованого стану
      if (
          (state_ar_record_fatfs == STATE_AR_NONE_FATFS) &&
          (state_ar_record_m == STATE_AR_NONE_M)
         )
      {
        state_ar_record_prt = STATE_AR_NONE_PRT;
        
        if(
           (cur_active_sources[0 ] != 0) ||
           (cur_active_sources[1 ] != 0) ||
           (cur_active_sources[2 ] != 0) ||
           (cur_active_sources[3 ] != 0) ||
           (cur_active_sources[4 ] != 0) ||
           (cur_active_sources[5 ] != 0) ||
           (cur_active_sources[6 ] != 0) ||
           (cur_active_sources[7 ] != 0) ||
           (cur_active_sources[8 ] != 0) ||
           (cur_active_sources[9 ] != 0) ||
           (cur_active_sources[10] != 0) ||
           (cur_active_sources[11] != 0) ||
           (cur_active_sources[12] != 0)
          )   
        {
          forbidden_new_record_ar_mode_0 = 0xff; /*помічаємо будь-яким числом, що є активними деякі сигнали від попереднього записту*/
        }
      }
      
      break;
    }
  default:
    {
      //Теоретично цього ніколи не мало б бути
      total_error_sw_fixed(32);
      break;
    }
  }
  
  //Виставляння/скидання функції Роботи Аналогового реєстратора
  if (
      (state_ar_record_prt == STATE_AR_AVAR_PRT) ||
      (state_ar_record_prt == STATE_AR_POSTAVAR_PRT)
     )
  {
    _SET_BIT(carrent_active_functions, RNG_BIG_WORK_A_REJESTRATOR);//!@RANG_WORK_A_REJESTRATOR
  }
  else
  {
    _CLEAR_BIT(carrent_active_functions, RNG_BIG_WORK_A_REJESTRATOR);//!@RANG_WORK_A_REJESTRATOR
  }

  prev_active_sources[0 ] = cur_active_sources[0 ];
  prev_active_sources[1 ] = cur_active_sources[1 ];
  prev_active_sources[2 ] = cur_active_sources[2 ];
  prev_active_sources[3 ] = cur_active_sources[3 ];
  prev_active_sources[4 ] = cur_active_sources[4 ];
  prev_active_sources[5 ] = cur_active_sources[5 ];
  prev_active_sources[6 ] = cur_active_sources[6 ];
  prev_active_sources[7 ] = cur_active_sources[7 ];
  prev_active_sources[8 ] = cur_active_sources[8 ];
  prev_active_sources[9 ] = cur_active_sources[9 ];
  prev_active_sources[10] = cur_active_sources[10];
  prev_active_sources[11] = cur_active_sources[11];
  prev_active_sources[12] = cur_active_sources[12];
}
/*****************************************************/


/*****************************************************/
//Функція захистів з якої здійснюються всі інші операції
/*****************************************************/
inline void main_protection(void)
{
  copying_active_functions = 1; //Помічаємо, що зараз обновляємо значення активних функцій
  
  //Скижаємо ті сигнали, які відповідають за входи, кнопки і активацію з інтерфейсу
  const unsigned int maska_input_signals[N_BIG] = 
  {
    (unsigned long) INPUT_SIGNALS_MASK_CMD_00, //MASKA_FOR_INPUT_SIGNALS_0, 
    (unsigned long) INPUT_SIGNALS_MASK_CMD_01, //MASKA_FOR_INPUT_SIGNALS_1, 
    (unsigned long) INPUT_SIGNALS_MASK_CMD_02, //MASKA_FOR_INPUT_SIGNALS_2, 
    (unsigned long) INPUT_SIGNALS_MASK_CMD_03, //MASKA_FOR_INPUT_SIGNALS_3, 
    (unsigned long) INPUT_SIGNALS_MASK_CMD_04, //MASKA_FOR_INPUT_SIGNALS_4, 
    (unsigned long) INPUT_SIGNALS_MASK_CMD_05, //MASKA_FOR_INPUT_SIGNALS_5, 
    (unsigned long) INPUT_SIGNALS_MASK_CMD_06, //MASKA_FOR_INPUT_SIGNALS_6, 
    (unsigned long) INPUT_SIGNALS_MASK_CMD_07, //MASKA_FOR_INPUT_SIGNALS_7, 
    (unsigned long) INPUT_SIGNALS_MASK_CMD_08, //MASKA_FOR_INPUT_SIGNALS_8, 
    (unsigned long) INPUT_SIGNALS_MASK_CMD_09, //MASKA_FOR_INPUT_SIGNALS_9,
    (unsigned long) INPUT_SIGNALS_MASK_CMD_10,  //MASKA_FOR_INPUT_SIGNALS_10
	(unsigned long) INPUT_SIGNALS_MASK_CMD_11,  
	(unsigned long) INPUT_SIGNALS_MASK_CMD_12  
  };
  for (unsigned int i = 0; i < N_BIG; i++) active_functions[i] &= (unsigned int)(~maska_input_signals[i]);
  
  /**************************/
  //Перевірка, чи треба очистити трігерні функції
  /**************************/
  if (reset_trigger_function_from_interface !=0)
  {
    if ((reset_trigger_function_from_interface & (1 << USB_RECUEST)) != 0)
    {
      for (unsigned int i = 0; i < N_BIG; i++) trigger_functions_USB[i] = 0;
      
      information_about_restart_counter  &= (unsigned int)(~(1 << USB_RECUEST));
      information_about_clean_energy     &= (unsigned int)(~(1 << USB_RECUEST));
    }
    if ((reset_trigger_function_from_interface & (1 << RS485_RECUEST)) != 0)
    {
      for (unsigned int i = 0; i < N_BIG; i++) trigger_functions_RS485[i] = 0;
      
      information_about_restart_counter  &= (unsigned int)(~(1 << RS485_RECUEST));
      information_about_clean_energy     &= (unsigned int)(~(1 << RS485_RECUEST));
    }
    
    //Помічаємо що ми виконали очистку по ВСІХ інтерфейсах
    reset_trigger_function_from_interface = 0;
  }
  /**************************/

  unsigned int blocking_commands_from_DI = 0;
  unsigned int active_inputs_grupa_ustavok = 0;
  /**************************/
  //Опрацьовуємо ФК, дискретні входи і верхній рівень
  /**************************/
  //Опрцьовуємо логіку натиснутих кнопок
  uint32_t pressed_buttons_tmp = 0;
  uint32_t buttons_mode_tmp = current_settings_prt.buttons_mode;
  if (
      (mutex_buttons == false) &&
      (pressed_buttons != 0)
     )   
  {
    pressed_buttons_tmp = pressed_buttons;
    //Очищаємо натиснуті кнопкb, інформацію про яких ми вже забрали у роботу (аде ще не опрацювали)
    pressed_buttons = 0;
  }
      
  uint32_t pressed_buttons_switcher = pressed_buttons_tmp & buttons_mode_tmp; /*натиснуті в даний момент кнопки-ключі*/
  pressed_buttons_tmp &= (uint32_t)(~buttons_mode_tmp); /*натиснуті в даний момент всі інші типи кнопок*/
      
  //Опрацьвуємо спочатку кнопки-ключі
  uint32_t fix_active_buttons_tmp = (fix_active_buttons ^ pressed_buttons_switcher) & buttons_mode_tmp;
  if (fix_active_buttons_tmp != fix_active_buttons) 
  {
    fix_active_buttons = fix_active_buttons_tmp;
    /*
    Змінилися стани кнопок-ключів
    */
    _SET_BIT(control_spi1_taskes, TASK_START_WRITE_TRG_FUNC_EEPROM_BIT);
  }
    
  //Формуємо стан натиснутих кнопок з урахуванням нового стану копок клічів і інших кнопок
  uint32_t pressed_buttons_united = pressed_buttons_tmp | fix_active_buttons_tmp;

  //Світлова індикація натиснутих кнопок-ключів
  for (size_t i = 0; i < NUMBER_DEFINED_BUTTONS; i++)
  {
    uint32_t maska_yellow = ((1 << (i*NUMBER_LED_COLOR + LED_COLOR_RED_BIT)) | (1 << (i*NUMBER_LED_COLOR + LED_COLOR_GREEN_BIT)));
    if (((buttons_mode_tmp >> i) & 0x1) == BUTTON_MODE_SWITCHER)
    {
      if (((fix_active_buttons_tmp >> i) & 0x1) != 0) 
      {
#ifndef KEYBOARD_VER_2_1
        state_leds_Fx[0] &= (uint32_t)(~maska_yellow);
        state_leds_Fx[1] |= maska_yellow;
#else
        if (i != (4 - 1))
        {
          state_leds_Fx[0] &= (uint32_t)(~maska_yellow);
          state_leds_Fx[1] |= maska_yellow;
        }
        else
        {
          state_leds_Fx[1] &= (uint32_t)(~maska_yellow);
          state_leds_Fx[0] |= maska_yellow;
        }
#endif
      }    
      else
      {
#ifndef KEYBOARD_VER_2_1
        state_leds_Fx[1] &= (uint32_t)(~maska_yellow);
        state_leds_Fx[0] |= maska_yellow;
#else
        if (i != (4 - 1))
        {
          state_leds_Fx[1] &= (uint32_t)(~maska_yellow);
          state_leds_Fx[0] |= maska_yellow;
        }
        else
        {
          state_leds_Fx[0] &= (uint32_t)(~maska_yellow);
          state_leds_Fx[1] |= maska_yellow;
        }
#endif
      }    
    }
    else
    {
      state_leds_Fx[0] &= (uint32_t)(~maska_yellow);
      state_leds_Fx[1] &= (uint32_t)(~maska_yellow);
    }
  }

  //Перевіряємо чи є зараз активні входи
  if (
      (pressed_buttons_united !=0)
      ||  
      (  
       (mutex_interface == false) &&
       (
        (activation_function_from_interface[0] != 0) ||
        (activation_function_from_interface[1] != 0) ||
        (activation_function_from_interface[2] != 0) ||
        (activation_function_from_interface[3] != 0)
       )
      )
      ||  
      (active_inputs !=0)
     )   
  {
    unsigned int temp_value_for_activated_function_button_interface[N_SMALL] = {0, 0, 0, 0, 0};
    unsigned int temp_value_for_activated_function[N_SMALL] = {0, 0, 0, 0, 0};

    //Активація з кнопуки
    if (pressed_buttons_united != 0)
    {
      for (unsigned int i = 0; i < NUMBER_DEFINED_BUTTONS; i++)
      {
        if ((pressed_buttons_united & (1 << i)) != 0)
        {
          unsigned int *point_temp_value_for_activated_function = ((pressed_buttons_tmp & (1 << i)) != 0) ? temp_value_for_activated_function_button_interface : temp_value_for_activated_function;
          point_temp_value_for_activated_function[0] |= current_settings_prt.ranguvannja_buttons[N_SMALL*i  ];
          point_temp_value_for_activated_function[1] |= current_settings_prt.ranguvannja_buttons[N_SMALL*i+1];
          point_temp_value_for_activated_function[2] |= current_settings_prt.ranguvannja_buttons[N_SMALL*i+2];
          point_temp_value_for_activated_function[3] |= current_settings_prt.ranguvannja_buttons[N_SMALL*i+3];
          point_temp_value_for_activated_function[4] |= current_settings_prt.ranguvannja_buttons[N_SMALL*i+4];
        }
      }
      if ((pressed_buttons_united & (1 << (BIT_KEY_C - BIT_KEY_1))) != 0)
      {
        //_SET_BIT(temp_value_for_activated_function, RANG_SMALL_RESET_LEDS);
        //_SET_BIT(temp_value_for_activated_function, RANG_SMALL_RESET_RELES);
        _SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_RESET_LEDS );
        _SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_RESET_RELES);
      }
      //if ((pressed_buttons_united & (1 << (BIT_KEY_I - BIT_KEY_1))) != 0) _SET_BIT(temp_value_for_activated_function, RANG_SMALL_VKL_VV);
      //if ((pressed_buttons_united & (1 << (BIT_KEY_O - BIT_KEY_1))) != 0) _SET_BIT(temp_value_for_activated_function, RANG_SMALL_OTKL_VV);
      if ((pressed_buttons_united & (1 << (BIT_KEY_I - BIT_KEY_1))) != 0) _SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_VKL_VVO );
      if ((pressed_buttons_united & (1 << (BIT_KEY_O - BIT_KEY_1))) != 0) _SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_OTKL_VVO);
    }
    
    //Активація з інтерфейсу
    if (mutex_interface == false)
    {
      temp_value_for_activated_function_button_interface[0] |= activation_function_from_interface[0];
      activation_function_from_interface[0] = 0;
      temp_value_for_activated_function_button_interface[1] |= activation_function_from_interface[1];
      activation_function_from_interface[1] = 0;
      temp_value_for_activated_function_button_interface[2] |= activation_function_from_interface[2];
      activation_function_from_interface[2] = 0;
      temp_value_for_activated_function_button_interface[3] |= activation_function_from_interface[3];
      activation_function_from_interface[3] = 0;
    temp_value_for_activated_function_button_interface[3] |= activation_function_from_interface[4];
      activation_function_from_interface[4] = 0;
    }
    
    //Обєднуємо активації з кнопок (режим кнопка) + активації з інтерфейсу і кнопок (режим ключ) + кнопки фіксованого функціоналу
    temp_value_for_activated_function[0] |= temp_value_for_activated_function_button_interface[0];
    temp_value_for_activated_function[1] |= temp_value_for_activated_function_button_interface[1];
    temp_value_for_activated_function[2] |= temp_value_for_activated_function_button_interface[2];
    temp_value_for_activated_function[3] |= temp_value_for_activated_function_button_interface[3];
    temp_value_for_activated_function[4] |= temp_value_for_activated_function_button_interface[4];

    //Активація з Д.Входу
    unsigned int vvimk_VV_vid_DV = false;
    unsigned int vymk_VV_vid_DV = false;
    if (active_inputs != 0)
    {
      for (unsigned int i = 0; i < NUMBER_INPUTS; i++)
      {
        if ((active_inputs & (1 << i)) != 0)
        {
          if (
              (_CHECK_SET_BIT((current_settings_prt.ranguvannja_inputs + N_SMALL*i), RANGE_SMALL_A01_VKL_VVO)) ||//RANG_SMALL_VKL_VV 
              (_CHECK_SET_BIT((current_settings_prt.ranguvannja_inputs + N_SMALL*i), RANGE_SMALL_A01_OTKL_VVO))   //RANG_SMALL_OTKL_VV
             )   
          {
            unsigned int ranguvannja_inputs_tmp[N_SMALL] = {
                                                            current_settings_prt.ranguvannja_inputs[N_SMALL*i  ],
                                                            current_settings_prt.ranguvannja_inputs[N_SMALL*i+1],
                                                            current_settings_prt.ranguvannja_inputs[N_SMALL*i+2],
                                                            current_settings_prt.ranguvannja_inputs[N_SMALL*i+3],
                                                            current_settings_prt.ranguvannja_inputs[N_SMALL*i+4]
                                                           };

            if (_CHECK_SET_BIT((current_settings_prt.ranguvannja_inputs + N_SMALL*i), RANGE_SMALL_A01_VKL_VVO ))//RANG_SMALL_VKL_VV
            {
              vvimk_VV_vid_DV = true;
              _CLEAR_BIT(ranguvannja_inputs_tmp, RANGE_SMALL_A01_VKL_VVO);//RANG_SMALL_VKL_VV
            }

            if (_CHECK_SET_BIT((current_settings_prt.ranguvannja_inputs + N_SMALL*i), RANGE_SMALL_A01_OTKL_VVO ))//RANG_SMALL_OTKL_VV
            {
              vymk_VV_vid_DV = true;
              _CLEAR_BIT(ranguvannja_inputs_tmp, RANGE_SMALL_A01_OTKL_VVO);//RANG_SMALL_OTKL_VV
            }

            temp_value_for_activated_function[0] |= ranguvannja_inputs_tmp[0];
            temp_value_for_activated_function[1] |= ranguvannja_inputs_tmp[1];
            temp_value_for_activated_function[2] |= ranguvannja_inputs_tmp[2];
            temp_value_for_activated_function[3] |= ranguvannja_inputs_tmp[3];
            temp_value_for_activated_function[4] |= ranguvannja_inputs_tmp[4];
          }
          else
          {
            temp_value_for_activated_function[0] |= current_settings_prt.ranguvannja_inputs[N_SMALL*i  ];
            temp_value_for_activated_function[1] |= current_settings_prt.ranguvannja_inputs[N_SMALL*i+1];
            temp_value_for_activated_function[2] |= current_settings_prt.ranguvannja_inputs[N_SMALL*i+2];
            temp_value_for_activated_function[3] |= current_settings_prt.ranguvannja_inputs[N_SMALL*i+3];
            temp_value_for_activated_function[4] |= current_settings_prt.ranguvannja_inputs[N_SMALL*i+4];
          }
        }
      }
    }
    
    //Опреділювані функції
    for (unsigned int i = 0; i < NUMBER_DEFINED_FUNCTIONS; i++)
    {
      switch (i)
      {
      case 0:
        {
          //active_functions[RANG_DF1_IN >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_DF1_IN) != 0) << (RANG_DF1_IN & 0x1f);//
          active_functions[RNG_BIG_DF1_IN >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_DF1_IN) != 0) << (RNG_BIG_DF1_IN & 0x1f);//
          break;
        }
      case 1:
        {
          //active_functions[RANG_DF2_IN >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_DF2_IN) != 0) << (RANG_DF2_IN & 0x1f);//
          active_functions[RNG_BIG_DF2_IN >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_DF2_IN) != 0) << (RNG_BIG_DF2_IN & 0x1f);//
          break;
        }
      case 2:
        {
          //active_functions[RANG_DF3_IN >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_DF3_IN) != 0) << (RANG_DF3_IN & 0x1f);//
          active_functions[RNG_BIG_DF3_IN >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_DF3_IN) != 0) << (RNG_BIG_DF3_IN & 0x1f);//
          break;
        }
      case 3:
        {
          //active_functions[RANG_DF4_IN >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_DF4_IN) != 0) << (RANG_DF4_IN & 0x1f);//
          active_functions[RNG_BIG_DF4_IN >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_DF4_IN) != 0) << (RNG_BIG_DF4_IN & 0x1f);//
          break;
        }
      case 4:
        {
          //active_functions[RANG_DF5_IN >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_DF5_IN) != 0) << (RANG_DF5_IN & 0x1f);//
          active_functions[RNG_BIG_DF5_IN >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_DF5_IN) != 0) << (RNG_BIG_DF5_IN & 0x1f);//
          break;
        }
      case 5:
        {
          //active_functions[RANG_DF6_IN >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_DF6_IN) != 0) << (RANG_DF6_IN & 0x1f);//
          active_functions[RNG_BIG_DF6_IN >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_DF6_IN) != 0) << (RNG_BIG_DF6_IN & 0x1f);//
          break;
        }
      case 6:
        {
          //active_functions[RANG_DF7_IN >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_DF7_IN) != 0) << (RANG_DF7_IN & 0x1f);//
          active_functions[RNG_BIG_DF7_IN >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_DF7_IN) != 0) << (RNG_BIG_DF7_IN & 0x1f);//
          break;
        }
      case 7:
        {
          //active_functions[RANG_DF8_IN >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_DF8_IN) != 0) << (RANG_DF8_IN & 0x1f);//
          active_functions[RNG_BIG_DF8_IN >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_DF8_IN) != 0) << (RNG_BIG_DF8_IN & 0x1f);//
          break;
        }
      case 8:
        {
          //active_functions[RANG_DF9_IN >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_DF9_IN) != 0) << (RANG_DF9_IN & 0x1f);//
          active_functions[RNG_BIG_DF9_IN >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_DF9_IN) != 0) << (RNG_BIG_DF9_IN & 0x1f);//
          break;
        }
      case 9:
        {
          //active_functions[RANG_DF10_IN >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_DF10_IN) != 0) << (RANG_DF10_IN & 0x1f);//
          active_functions[RNG_BIG_DF10_IN >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_DF10_IN) != 0) << (RNG_BIG_DF10_IN & 0x1f);//
          break;
        }
      case 10:
        {
          //active_functions[RANG_DF11_IN >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_DF11_IN) != 0) << (RANG_DF11_IN & 0x1f);//
          active_functions[RNG_BIG_DF11_IN >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_DF11_IN) != 0) << (RNG_BIG_DF11_IN & 0x1f);//
          break;
        }
      case 11:
        {
          //active_functions[RANG_DF12_IN >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_DF12_IN) != 0) << (RANG_DF12_IN & 0x1f);//
          active_functions[RNG_BIG_DF12_IN >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_DF12_IN) != 0) << (RNG_BIG_DF12_IN & 0x1f);//
          break;
        }
      case 12:
        {
          //active_functions[RANG_DF13_IN >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_DF13_IN) != 0) << (RANG_DF13_IN & 0x1f);//
          active_functions[RNG_BIG_DF13_IN >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_DF13_IN) != 0) << (RNG_BIG_DF13_IN & 0x1f);//
          break;
        }
      case 13:
        {
          //active_functions[RANG_DF14_IN >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_DF14_IN) != 0) << (RANG_DF14_IN & 0x1f);//
          active_functions[RNG_BIG_DF14_IN >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_DF14_IN) != 0) << (RNG_BIG_DF14_IN & 0x1f);//
          break;
        }
      case 14:
        {
          //active_functions[RANG_DF15_IN >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_DF15_IN) != 0) << (RANG_DF15_IN & 0x1f);//
          active_functions[RNG_BIG_DF15_IN >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_DF15_IN) != 0) << (RNG_BIG_DF15_IN & 0x1f);//
          break;
        }
      case 15:
        {
          //active_functions[RANG_DF16_IN >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_DF16_IN) != 0) << (RANG_DF16_IN & 0x1f);//
          active_functions[RNG_BIG_DF16_IN >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_DF16_IN) != 0) << (RNG_BIG_DF16_IN & 0x1f);//
          break;
        }
      default: break;
      }
    
      //Перевірка на необхідність пролонгації активації В-функції на час  таймеру павзи
      if (_CHECK_SET_BIT(temp_value_for_activated_function_button_interface, (RNG_BIG_DF1_IN + i)) != 0)//RANG_SMALL_DF1_IN
      {
        //Зараз має активуватися В-ФункціяХ, тому треба запустити таймер її утримування,
        //для того, щоб потім час цей можна було зрівняти з часом таймера павзи
        if (global_timers[INDEX_TIMER_DF_PROLONG_SET_FOR_BUTTON_INTERFACE_START + i] < 0)
        {
          //Запускаємо таймер таймер утримування цієї функції в активному стані (емітація активного входу)
          //Запуск робимо тільки ту тому випадкук, якщо він ще не почався
          global_timers[INDEX_TIMER_DF_PROLONG_SET_FOR_BUTTON_INTERFACE_START + i] = 0;
        }
      }
    }

    //Опреділювані триґери
    for (unsigned int i = 0; i < NUMBER_DEFINED_TRIGGERS; i++)
    {
      switch (i)
      {
      case 0:
        {
          //active_functions[RANG_DT1_SET   >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_DT1_SET  ) != 0) << (RANG_DT1_SET   & 0x1f);
          //active_functions[RANG_DT1_RESET >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_DT1_RESET) != 0) << (RANG_DT1_RESET & 0x1f);
          active_functions[RNG_BIG_DT1_SET   >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_DT1_SET  ) != 0) << (RNG_BIG_DT1_SET   & 0x1f);
          active_functions[RNG_BIG_DT1_RESET >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_DT1_RESET) != 0) << (RNG_BIG_DT1_RESET & 0x1f);
          break;
        }
      case 1:
        {
          //active_functions[RANG_DT2_SET   >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_DT2_SET  ) != 0) << (RANG_DT2_SET   & 0x1f);
          //active_functions[RANG_DT2_RESET >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_DT2_RESET) != 0) << (RANG_DT2_RESET & 0x1f);
          active_functions[RNG_BIG_DT2_SET   >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_DT2_SET  ) != 0) << (RNG_BIG_DT2_SET   & 0x1f);
          active_functions[RNG_BIG_DT2_RESET >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_DT2_RESET) != 0) << (RNG_BIG_DT2_RESET & 0x1f);
          break;
        }
      case 2:
        {
          //active_functions[RANG_DT3_SET   >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_DT3_SET  ) != 0) << (RANG_DT3_SET   & 0x1f);
          //active_functions[RANG_DT3_RESET >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_DT3_RESET) != 0) << (RANG_DT3_RESET & 0x1f);
          active_functions[RNG_BIG_DT3_SET   >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_DT3_SET  ) != 0) << ( RNG_BIG_DT3_SET  & 0x1f);
          active_functions[RNG_BIG_DT3_RESET >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_DT3_RESET) != 0) << (RNG_BIG_DT3_RESET & 0x1f);
          break;
        }
      case 3:
        {
          //active_functions[RANG_DT4_SET   >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_DT4_SET  ) != 0) << (RANG_DT4_SET   & 0x1f);
          //active_functions[RANG_DT4_RESET >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_DT4_RESET) != 0) << (RANG_DT4_RESET & 0x1f);
          active_functions[RNG_BIG_DT4_SET   >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_DT4_SET  ) != 0) << (RNG_BIG_DT4_SET   & 0x1f);
          active_functions[RNG_BIG_DT4_RESET >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_DT4_RESET) != 0) << (RNG_BIG_DT4_RESET & 0x1f);
          break;
        }
      default: break;
      }
    }

    //Функції зв'язку
    for (size_t i = 0; i < NUMBER_LINK_FUNCTIONS; ++i)
    {
      //!@active_functions[RANG_LF1 >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, @RANG_SMALL_LF1) != 0) << (RANG_LF1 & 0x1f); ??
      active_functions[(RNG_BIG_LF1 + i) >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, (RANG_SMALL_A01_LF1+i)) != 0) << ((RNG_BIG_LF1 + i)& 0x1f);
    }
      
    //Загальні функції (без ОФ-ій і функцій, які можуть блокуватися у місцевому управлінні)
    //!@active_functions[RANG_BLOCK_VKL_VV                      >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_BLOCK_VKL_VV                     ) != 0) << (RANG_BLOCK_VKL_VV                      & 0x1f);
    //!@active_functions[RANG_RESET_LEDS                        >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_RESET_LEDS                       ) != 0) << (RANG_RESET_LEDS                        & 0x1f);
    //!@active_functions[RANG_RESET_RELES                       >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_RESET_RELES                      ) != 0) << (RANG_RESET_RELES                       & 0x1f);
    //!@active_functions[RANG_MISCEVE_DYSTANCIJNE               >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_MISCEVE_DYSTANCIJNE              ) != 0) << (RANG_MISCEVE_DYSTANCIJNE               & 0x1f);
    //!@active_functions[RANG_STATE_VV                          >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_STATE_VV                         ) != 0) << (RANG_STATE_VV                          & 0x1f);
    //!@active_functions[RANG_CTRL_VKL                          >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_CTRL_VKL                         ) != 0) << (RANG_CTRL_VKL                          & 0x1f);
    //!@active_functions[RANG_CTRL_OTKL                         >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_CTRL_OTKL                        ) != 0) << (RANG_CTRL_OTKL                         & 0x1f);
    //!@active_functions[RANG_RESET_BLOCK_READY_TU_VID_ZAHYSTIV >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_RESET_BLOCK_READY_TU_VID_ZAHYSTIV) != 0) << (RANG_RESET_BLOCK_READY_TU_VID_ZAHYSTIV & 0x1f);
    //!@active_functions[RANG_OTKL_VID_ZOVN_ZAHYSTIV            >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_OTKL_VID_ZOVN_ZAHYSTIV     ) != 0) << (RANG_OTKL_VID_ZOVN_ZAHYSTIV            & 0x1f);

    active_functions[RNG_BIG_BLOCK_VKL_VVO                     >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLOCK_VKL_VVO                    ) != 0) << (RNG_BIG_BLOCK_VKL_VVO                     & 0x1f);
    active_functions[RNG_BIG_RESET_LEDS                        >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_RESET_LEDS                       ) != 0) << (RNG_BIG_RESET_LEDS                        & 0x1f);
    active_functions[RNG_BIG_RESET_RELES                       >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_RESET_RELES                      ) != 0) << (RNG_BIG_RESET_RELES                       & 0x1f);
    active_functions[RNG_BIG_MISCEVE_DYSTANCIJNE               >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_MISCEVE_DYSTANCIJNE              ) != 0) << (RNG_BIG_MISCEVE_DYSTANCIJNE               & 0x1f);
    active_functions[RNG_BIG_STATE_VVO                         >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_STATE_VVO                        ) != 0) << (RNG_BIG_STATE_VVO                         & 0x1f);
    active_functions[RNG_BIG_CTRL_VKL_VVO                      >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_CTRL_VKL_VVO                     ) != 0) << (RNG_BIG_CTRL_VKL_VVO                      & 0x1f);
    active_functions[RNG_BIG_CTRL_OTKL_VVO                     >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_CTRL_OTKL_VVO                    ) != 0) << (RNG_BIG_CTRL_OTKL_VVO                     & 0x1f);
    active_functions[RNG_BIG_RESET_BLOCK_READY_TU_VID_ZAHYSTIV >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_RESET_BLOCK_READY_TU_VID_ZAHYSTIV) != 0) << (RNG_BIG_RESET_BLOCK_READY_TU_VID_ZAHYSTIV & 0x1f);
    //active_functions[RANG_OTKL_VID_ZOVN_ZAHYSTIV            >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_OTKL_VID_ZOVN_ZAHYSTIV     ) != 0) << (RANG_OTKL_VID_ZOVN_ZAHYSTIV            & 0x1f);

    //!2active_inputs_grupa_ustavok |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_1_GRUPA_USTAVOK    ) != 0) << (RANG_SMALL_1_GRUPA_USTAVOK - RANG_SMALL_1_GRUPA_USTAVOK);
    //!2active_inputs_grupa_ustavok |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_2_GRUPA_USTAVOK    ) != 0) << (RANG_SMALL_2_GRUPA_USTAVOK - RANG_SMALL_1_GRUPA_USTAVOK);
    //!2active_inputs_grupa_ustavok |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_3_GRUPA_USTAVOK    ) != 0) << (RANG_SMALL_3_GRUPA_USTAVOK - RANG_SMALL_1_GRUPA_USTAVOK);
    //!2active_inputs_grupa_ustavok |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_4_GRUPA_USTAVOK    ) != 0) << (RANG_SMALL_4_GRUPA_USTAVOK - RANG_SMALL_1_GRUPA_USTAVOK);
    active_inputs_grupa_ustavok |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_1_GRUPA_USTAVOK) != 0) << (RANGE_SMALL_A01_1_GRUPA_USTAVOK - RANGE_SMALL_A01_1_GRUPA_USTAVOK);
    active_inputs_grupa_ustavok |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_2_GRUPA_USTAVOK) != 0) << (RANGE_SMALL_A01_2_GRUPA_USTAVOK - RANGE_SMALL_A01_1_GRUPA_USTAVOK);
    active_inputs_grupa_ustavok |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_3_GRUPA_USTAVOK) != 0) << (RANGE_SMALL_A01_3_GRUPA_USTAVOK - RANGE_SMALL_A01_1_GRUPA_USTAVOK);
    active_inputs_grupa_ustavok |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_4_GRUPA_USTAVOK) != 0) << (RANGE_SMALL_A01_4_GRUPA_USTAVOK - RANGE_SMALL_A01_1_GRUPA_USTAVOK);
      
    //Загальні функції (які блокувються у місцевому управлінні)
    //Ввімкнення ВВ
    //!@active_functions[RANG_VKL_VV >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, @RANG_SMALL_VKL_VV) != 0) << (RANG_VKL_VV & 0x1f);
    active_functions[RNG_BIG_VKL_VVO >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_VKL_VVO) != 0) << (RNG_BIG_VKL_VVO & 0x1f);
    if (vvimk_VV_vid_DV)
    {
      if (
          //!@(_CHECK_SET_BIT(active_functions, @RANG_MISCEVE_DYSTANCIJNE )) &&
          (_CHECK_SET_BIT(active_functions, RNG_BIG_MISCEVE_DYSTANCIJNE )) &&
          (current_settings_prt.control_extra_settings_1 & CTR_EXTRA_SETTINGS_1_BLK_ON_CB_MISCEVE)
         ) 
      {
        //Умова блокування командви "Ввімкнення ВВ" від ДВх.
        blocking_commands_from_DI |= CTR_EXTRA_SETTINGS_1_BLK_ON_CB_MISCEVE;
      }
      else _SET_BIT(active_functions, RNG_BIG_VKL_VVO);//!_SET_BIT(active_functions, @RANG_VKL_VV);
    }

    //Вимкнення ВВ
    //!@active_functions[ @RANG_OTKL_VV >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, @RANG_SMALL_OTKL_VV) != 0) << ( @RANG_OTKL_VV & 0x1f);
    active_functions[RNG_BIG_OTKL_VV_VVO >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_CTRL_OTKL_VVO) != 0) << (RNG_BIG_OTKL_VV_VVO & 0x1f);
    if (vymk_VV_vid_DV)
    {
      if (
          //!@(_CHECK_SET_BIT(active_functions, @RANG_MISCEVE_DYSTANCIJNE )) &&
          (_CHECK_SET_BIT(active_functions, RNG_BIG_MISCEVE_DYSTANCIJNE )) &&
          (current_settings_prt.control_extra_settings_1 & CTR_EXTRA_SETTINGS_1_BLK_OFF_CB_MISCEVE)
         ) 
      {
        //Умова блокування командви "Вимкнення ВВ" від ДВх.
        blocking_commands_from_DI |= CTR_EXTRA_SETTINGS_1_BLK_OFF_CB_MISCEVE;
      }
      else _SET_BIT(active_functions, RNG_BIG_OTKL_VV_VVO);//!@_SET_BIT(active_functions, @RANG_OTKL_VV);
    }

    //Блок для ДЗ
    // active_functions[RANG_EXT_NKN_DZ   >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_EXT_NKN_DZ    ) != 0) << (RANG_EXT_NKN_DZ   & 0x1f);
    // active_functions[RANG_BLOCK_DZ1    >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_BLOCK_DZ1     ) != 0) << (RANG_BLOCK_DZ1    & 0x1f);
    // active_functions[RANG_BLOCK_DZ2    >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_BLOCK_DZ2     ) != 0) << (RANG_BLOCK_DZ2    & 0x1f);
    // active_functions[RANG_BLOCK_PR_DZ2 >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_BLOCK_PR_DZ2  ) != 0) << (RANG_BLOCK_PR_DZ2 & 0x1f);
    // active_functions[RANG_OP_PR_DZ2    >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_OP_PR_DZ2     ) != 0) << (RANG_OP_PR_DZ2    & 0x1f);
    // active_functions[RANG_BLOCK_DZ3    >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_BLOCK_DZ3     ) != 0) << (RANG_BLOCK_DZ3    & 0x1f);
    // active_functions[RANG_BLOCK_PR_DZ3 >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_BLOCK_PR_DZ3  ) != 0) << (RANG_BLOCK_PR_DZ3 & 0x1f);
    // active_functions[RANG_OP_PR_DZ3    >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_OP_PR_DZ3     ) != 0) << (RANG_OP_PR_DZ3    & 0x1f);
    // active_functions[RANG_BLOCK_DZ4    >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_BLOCK_DZ4     ) != 0) << (RANG_BLOCK_DZ4    & 0x1f);
    // active_functions[RANG_BLOCK_PR_DZ4 >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_BLOCK_PR_DZ4  ) != 0) << (RANG_BLOCK_PR_DZ4 & 0x1f);
    // active_functions[RANG_OP_PR_DZ4    >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_OP_PR_DZ4     ) != 0) << (RANG_OP_PR_DZ4    & 0x1f);
     active_functions[RNG_BIG_NKN_DZO               >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_NKN_DZO             ) != 0) << (RNG_BIG_NKN_DZO               & 0x1f);
     active_functions[RNG_BIG_ZBR_BLOCK_DZO1_I_O_3G >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_ZBR_BLK_DZO1_I_O_3G ) != 0) << (RNG_BIG_ZBR_BLOCK_DZO1_I_O_3G & 0x1f);
     active_functions[RNG_BIG_ZBR_BLOCK_DZO1_I_O    >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_ZBR_BLK_DZO1_I_O    ) != 0) << (RNG_BIG_ZBR_BLOCK_DZO1_I_O    & 0x1f);
     active_functions[RNG_BIG_BLOCK_DZO1            >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLK_DZO1            ) != 0) << (RNG_BIG_BLOCK_DZO1            & 0x1f);
     active_functions[RNG_BIG_BLOCK_PR_DZO2         >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLK_USK_DZO2        ) != 0) << (RNG_BIG_BLOCK_PR_DZO2         & 0x1f);
     active_functions[RNG_BIG_OP_PR_DZO2            >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_OP_USK_DZO2         ) != 0) << (RNG_BIG_OP_PR_DZO2            & 0x1f);
     active_functions[RNG_BIG_ZBR_BLOCK_DZO2_I_O_3G >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_ZBR_BLK_DZO2_I_O_3G ) != 0) << (RNG_BIG_ZBR_BLOCK_DZO2_I_O_3G & 0x1f);
     active_functions[RNG_BIG_BLOCK_DZO2            >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLK_DZO2            ) != 0) << (RNG_BIG_BLOCK_DZO2            & 0x1f);
     active_functions[RNG_BIG_BLOCK_PR_DZO3         >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLK_USK_DZO3        ) != 0) << (RNG_BIG_BLOCK_PR_DZO3         & 0x1f);
     active_functions[RNG_BIG_OP_PR_DZO3            >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_OP_USK_DZO3         ) != 0) << (RNG_BIG_OP_PR_DZO3            & 0x1f);
     active_functions[RNG_BIG_ZBR_BLOCK_DZO3_I_O_3G >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_ZBR_BLK_DZO3_I_O_3G ) != 0) << (RNG_BIG_ZBR_BLOCK_DZO3_I_O_3G & 0x1f);
     active_functions[RNG_BIG_BLOCK_DZO3            >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLK_DZO3            ) != 0) << (RNG_BIG_BLOCK_DZO3            & 0x1f);
     active_functions[RNG_BIG_ZBR_BLOCK_DZO4_I_O_3G >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_ZBR_BLK_DZO4_I_O_3G ) != 0) << (RNG_BIG_ZBR_BLOCK_DZO4_I_O_3G & 0x1f);
     active_functions[RNG_BIG_BLOCK_DZO4            >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLK_DZO4            ) != 0) << (RNG_BIG_BLOCK_DZO4            & 0x1f);

    //МТЗ
    //active_functions[RANG_BLOCK_MTZ1     >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_BLOCK_MTZ1    ) != 0) << (RANG_BLOCK_MTZ1     & 0x1f);
    //active_functions[RANG_BLOCK_MTZ2     >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_BLOCK_MTZ2    ) != 0) << (RANG_BLOCK_MTZ2     & 0x1f);
    //active_functions[RANG_BLOCK_USK_MTZ2 >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_BLOCK_USK_MTZ2) != 0) << (RANG_BLOCK_USK_MTZ2 & 0x1f);
    //active_functions[RANG_BLOCK_MTZ3     >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_BLOCK_MTZ3    ) != 0) << (RANG_BLOCK_MTZ3     & 0x1f);
    //active_functions[RANG_BLOCK_MTZ4     >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_BLOCK_MTZ4    ) != 0) << (RANG_BLOCK_MTZ4     & 0x1f);


    active_functions[RNG_BIG_BLOCK_MCZO1    >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLK_MCZO1    ) != 0) << (RNG_BIG_BLOCK_MCZO1    & 0x1f);
    active_functions[RNG_BIG_BLOCK_MCZO2    >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLK_MCZO2    ) != 0) << (RNG_BIG_BLOCK_MCZO2    & 0x1f);
    active_functions[RNG_BIG_BLOCK_PR_MCZO2 >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLK_USK_MCZO2) != 0) << (RNG_BIG_BLOCK_PR_MCZO2 & 0x1f);
    active_functions[RNG_BIG_BLOCK_MCZO3    >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLK_MCZO3    ) != 0) << (RNG_BIG_BLOCK_MCZO3    & 0x1f);
    active_functions[RNG_BIG_BLOCK_MCZO4    >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLK_MCZO4    ) != 0) << (RNG_BIG_BLOCK_MCZO4    & 0x1f);

    //Блок для ЗДЗ
    //active_functions[RANG_BLOCK_ZDZ       >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_BLOCK_ZDZ      ) != 0) << (RANG_BLOCK_ZDZ       & 0x1f);
    //active_functions[RANG_PUSK_ZDZ_VID_DV >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_PUSK_ZDZ_VID_DV) != 0) << (RANG_PUSK_ZDZ_VID_DV & 0x1f);

    active_functions[RNG_BIG_BLOCK_ZDZ       >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLOCK_ZDZ      ) != 0) << (RNG_BIG_BLOCK_ZDZ        & 0x1f);
    active_functions[RNG_BIG_PUSK_ZDZ_VID_DV >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_PUSK_ZDZ_VID_DV) != 0) << (RNG_BIG_PUSK_ZDZ_VID_DV  & 0x1f);

    //НЗЗ      MCZO_BIT_CONFIGURATION = ZZ_BIT_CONFIGURATION,
    //active_functions[RANG_BLOCK_NZZ >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_BLOCK_NZZ) != 0) << (RANG_BLOCK_NZZ & 0x1f);

    


    //Блок ТЗНП  MCZR_BIT_CONFIGURATION = TZNP_BIT_CONFIGURATION
    //active_functions[RANG_BLOCK_TZNP1 >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_BLOCK_TZNP1) != 0) << (RANG_BLOCK_TZNP1 & 0x1f);
    //active_functions[RANG_BLOCK_TZNP2 >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_BLOCK_TZNP2) != 0) << (RANG_BLOCK_TZNP2 & 0x1f);
    //active_functions[RANG_BLOCK_TZNP3 >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_BLOCK_TZNP3) != 0) << (RANG_BLOCK_TZNP3 & 0x1f);

    
    active_functions[RNG_BIG_BLOCK_MCZR1 >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLK_MCZR1) != 0) << (RNG_BIG_BLOCK_MCZR1 & 0x1f);
    active_functions[RNG_BIG_BLOCK_MCZR2 >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLK_MCZR2) != 0) << (RNG_BIG_BLOCK_MCZR2 & 0x1f);

    //АПВ
    //active_functions[RANG_STAT_BLK_APV >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_STAT_BLK_APV) != 0) << (RANG_STAT_BLK_APV & 0x1f);
    active_functions[RNG_BIG_STAT_BLK_APV >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_STAT_BLK_APV) != 0) << (RNG_BIG_STAT_BLK_APV & 0x1f);
      
    //ЧАПВ
    //active_functions[RANG_ACHR_CHAPV_VID_DV  >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_ACHR_CHAPV_VID_DV ) != 0) << (RANG_ACHR_CHAPV_VID_DV & 0x1f);
    //active_functions[RANG_BLOCK_ACHR1        >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_BLOCK_ACHR1      ) != 0) << (RANG_BLOCK_ACHR1       & 0x1f);
    //active_functions[RANG_BLOCK_ACHR2        >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_BLOCK_ACHR2      ) != 0) << (RANG_BLOCK_ACHR2       & 0x1f);
    //
    active_functions[RNG_BIG_ACHR_CHAPV_VID_DV  >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_ACHR_CHAPV_VID_DV ) != 0) << (RNG_BIG_ACHR_CHAPV_VID_DV  & 0x1f);
    active_functions[RNG_BIG_BLOCK_ACHR1        >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLOCK_ACHR1       ) != 0) << (RNG_BIG_BLOCK_ACHR1        & 0x1f);
    active_functions[RNG_BIG_BLOCK_ACHR2        >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLOCK_ACHR2       ) != 0) << (RNG_BIG_BLOCK_ACHR2        & 0x1f);

    //УРОВ
    //active_functions[RANG_PUSK_UROV_VID_DV >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_PUSK_UROV_VID_DV) != 0) << (RANG_PUSK_UROV_VID_DV & 0x1f);
    active_functions[RNG_BIG_PUSK_UROV_VID_DV >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_PUSK_UROV_VID_DV) != 0) << (RNG_BIG_PUSK_UROV_VID_DV & 0x1f);

    //Блок ЗОП(КОФ) DZR_BIT_CONFIGURATION = ZOP_BIT_CONFIGURATION,
    //active_functions[RANG_BLOCK_ZOP >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_BLOCK_ZOP) != 0) << (RANG_BLOCK_ZOP & 0x1f);
    active_functions[RNG_BIG_ZVN_NESPR_DZR         >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_ZOVN_NESPRN_DZR    ) != 0) << (RNG_BIG_ZVN_NESPR_DZR         & 0x1f);
    active_functions[RNG_BIG_ZBR_BLOCK_DZR1_I_R_3G >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_ZBR_BLK_DZR1_I_O_3G) != 0) << (RNG_BIG_ZBR_BLOCK_DZR1_I_R_3G & 0x1f);
    active_functions[RNG_BIG_ZBR_BLOCK_DZR1_I_R    >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_ZBR_BLK_DZR1_I_O   ) != 0) << (RNG_BIG_ZBR_BLOCK_DZR1_I_R    & 0x1f);
    active_functions[RNG_BIG_BLOCK_DZR1            >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLK_DZR1           ) != 0) << (RNG_BIG_BLOCK_DZR1            & 0x1f);
    active_functions[RNG_BIG_BLOCK_PR_DZR2         >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLK_USK_DZR2       ) != 0) << (RNG_BIG_BLOCK_PR_DZR2         & 0x1f);
    active_functions[RNG_BIG_OP_PR_DZR2            >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_OP_USK_DZR2        ) != 0) << (RNG_BIG_OP_PR_DZR2            & 0x1f);
    active_functions[RNG_BIG_ZBR_BLOCK_DZR2_I_R_3G >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_ZBR_BLK_DZR2_I_O_3G) != 0) << (RNG_BIG_ZBR_BLOCK_DZR2_I_R_3G & 0x1f);
    active_functions[RNG_BIG_BLOCK_DZR2            >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLK_DZR2           ) != 0) << (RNG_BIG_BLOCK_DZR2            & 0x1f);
    active_functions[RNG_BIG_BLOCK_PR_DZR3         >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLK_USK_DZR3       ) != 0) << (RNG_BIG_BLOCK_PR_DZR3         & 0x1f);
    active_functions[RNG_BIG_OP_PR_DZR3            >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_OP_USK_DZR3        ) != 0) << (RNG_BIG_OP_PR_DZR3            & 0x1f);
    active_functions[RNG_BIG_ZBR_BLOCK_DZR3_I_R_3G >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_ZBR_BLK_DZR3_I_O_3G) != 0) << (RNG_BIG_ZBR_BLOCK_DZR3_I_R_3G & 0x1f);
    active_functions[RNG_BIG_BLOCK_DZR3            >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLK_DZR3           ) != 0) << (RNG_BIG_BLOCK_DZR3            & 0x1f);

    //Блок для Umin
    //active_functions[RANG_BLOCK_UMIN1 >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_BLOCK_UMIN1) != 0) << (RANG_BLOCK_UMIN1 & 0x1f);
    //active_functions[RANG_START_UMIN1 >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_START_UMIN1) != 0) << (RANG_START_UMIN1 & 0x1f);
    //active_functions[RANG_BLOCK_UMIN2 >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_BLOCK_UMIN2) != 0) << (RANG_BLOCK_UMIN2 & 0x1f);
    //active_functions[RANG_START_UMIN2 >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_START_UMIN2) != 0) << (RANG_START_UMIN2 & 0x1f);
      
    active_functions[RNG_BIG_BLOCK_UMIN1 >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLOCK_UMIN1) != 0) << (RNG_BIG_BLOCK_UMIN1 & 0x1f);
    active_functions[RNG_BIG_START_UMIN1 >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_START_UMIN1) != 0) << (RNG_BIG_START_UMIN1 & 0x1f);
    active_functions[RNG_BIG_BLOCK_UMIN2 >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLOCK_UMIN2) != 0) << (RNG_BIG_BLOCK_UMIN2 & 0x1f);
    active_functions[RNG_BIG_START_UMIN2 >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_START_UMIN2) != 0) << (RNG_BIG_START_UMIN2 & 0x1f);
      
    //Блок для Umax
    //active_functions[RANG_BLOCK_UMAX1 >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_BLOCK_UMAX1) != 0) << (RANG_BLOCK_UMAX1 & 0x1f);
    //active_functions[RANG_BLOCK_UMAX2 >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANG_SMALL_BLOCK_UMAX2) != 0) << (RANG_BLOCK_UMAX2 & 0x1f);

    active_functions[RNG_BIG_BLOCK_UMAX1 >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLOCK_UMAX1) != 0) << (RNG_BIG_BLOCK_UMAX1 & 0x1f);
    active_functions[RNG_BIG_BLOCK_UMAX2 >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, RANGE_SMALL_A01_BLOCK_UMAX2) != 0) << (RNG_BIG_BLOCK_UMAX2 & 0x1f);

    //Блокування для УЗ
    for (size_t i = 0; i < NUMBER_UP; i++)
    {
      uint32_t rang_small_block_up = RANGE_SMALL_A01_BLOCK_UP1 + i;//uint32_t rang_small_block_up = RANG_SMALL_BLOCK_UP1 + i;
      uint32_t rang_block_up = RNG_BIG_BLOCK_UP1 + 3*i;//uint32_t rang_block_up = RANG_BLOCK_UP1 + 3*i;
      active_functions[rang_block_up >> 5] |= (_CHECK_SET_BIT(temp_value_for_activated_function, rang_small_block_up) != 0) << (rang_block_up & 0x1f);
    }
  }
  /**************************/

  /**************************/
  //Виконуємо фільтрацію переднього фронту для тих сигналів, які мають активуватися тільки по передньому фронтові
  /**************************/
  {
    static unsigned int previous_activating_functions[N_BIG];
    //Формуємо маску сигналів, які треба позначити, як активні тільки в момент переходу з "0" в "1"
    unsigned int temp_maska_filter_function[N_BIG] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 , 0,0};
    unsigned int temp_activating_functions[N_BIG] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0};
  
    //Сигнал "Сблос индикации"
    _SET_BIT(temp_maska_filter_function, RNG_BIG_RESET_LEDS);//!@RANG_RESET_LEDS
  
    //Сигнал "Сблос реле"
    _SET_BIT(temp_maska_filter_function, RNG_BIG_RESET_RELES);//!@RANG_RESET_RELES

    //Сигнал "Включить ВВ"
    _SET_BIT(temp_maska_filter_function, RNG_BIG_VKL_VVO);//!@RANG_VKL_VV
    
    //Сигнал "Отключить ВВ"
    _SET_BIT(temp_maska_filter_function, RNG_BIG_OTKL_VV_VVO);//!@RANG_OTKL_VV

    //Сигнал "Скидання блокування готовності до ТУ"
    _SET_BIT(temp_maska_filter_function, RNG_BIG_RESET_BLOCK_READY_TU_VID_ZAHYSTIV);//!@RANG_RESET_BLOCK_READY_TU_VID_ZAHYSTIV
  
    for (unsigned int i = 0; i < N_BIG; i++)
    {
      //З масиву попередніх станів виділяємо тільки ті функції, якиї нас цікавить фронт змін і поміщаємо їх у тимчасовий масив
      temp_activating_functions[i] = previous_activating_functions[i] & temp_maska_filter_function[i];
  
      //У тимчасовому масиві виділяємо тільки ті функції, у яких зафіксовано або передній, або задній фронти
      temp_activating_functions[i] ^= (active_functions[i] & temp_maska_filter_function[i]);
  
      //Тепер виділяємо у тимчасовому масиві тільки ті функції у яких зараз значення стоять рівні "1" (тобто відбувся перехід з "0" в "1")
      temp_activating_functions[i] &= active_functions[i];

      /*
      Перед тим, як виділити ті функції, які у цьому циклі будуть відмічені як активні 
      з урахуванням того, що деякі функції активоються по передньому фронті
      копіюємо статичний стан функцій (без врахування фронтів) у тимчасовий масив
      щоб при наступному аналізі мати попередній статичний стан активних функцій
      */ 
      previous_activating_functions[i] = active_functions[i];

      //Обновляємо масив функцій, які зараз активуються з врахуванням того, що серед виділених функцій маскою активними мають юути тільки ті, у яких перехід був з "0" в "1"
      active_functions[i] = (active_functions[i] & (~temp_maska_filter_function[i])) | temp_activating_functions[i];
    }
  }
  /**************************/
  
  /**************************
  Світлова індикація стану вимикача
  **************************/
  {
    uint32_t state_vv_dv = false;
    for (size_t i = 0; i < NUMBER_INPUTS; i++)
    {
      if (_CHECK_SET_BIT ((current_settings_prt.ranguvannja_inputs + N_SMALL*i), RANGE_SMALL_A01_STATE_VVO) != 0)//!@RANG_SMALL_STATE_VV
      {
        state_vv_dv = true;
        break;
      }
    }
    
    if (state_vv_dv)
    {
      if (_CHECK_SET_BIT(active_functions, RNG_BIG_STATE_VVO) !=0)//!@RANG_STATE_VV 
      {
        state_leds_ctrl &=  (uint32_t)(~((1 << LED_COLOR_GREEN_BIT) << ((uint32_t)NUMBER_LED_COLOR*(uint32_t)LED_CTRL_O)));
        state_leds_ctrl |=  (uint32_t)(  (1 << LED_COLOR_RED_BIT  ) << ((uint32_t)NUMBER_LED_COLOR*(uint32_t)LED_CTRL_I) );
      }
      else
      {
        state_leds_ctrl &=  (uint32_t)(~((1 << LED_COLOR_RED_BIT  ) << ((uint32_t)NUMBER_LED_COLOR*(uint32_t)LED_CTRL_I)));
        state_leds_ctrl |=  (uint32_t)(  (1 << LED_COLOR_GREEN_BIT) << ((uint32_t)NUMBER_LED_COLOR*(uint32_t)LED_CTRL_O) );
      }
    }
    else
    {
      state_leds_ctrl &=  (uint32_t)(~(((1 << LED_COLOR_GREEN_BIT) << ((uint32_t)NUMBER_LED_COLOR*(uint32_t)LED_CTRL_O)) | ((1 << LED_COLOR_RED_BIT) << ((uint32_t)NUMBER_LED_COLOR*(uint32_t)LED_CTRL_I))));
    }
  }
  /**************************/

  /**************************/
  //Вибір групи уставок
  /**************************/
  for (size_t i = 0; i < NUMBER_GROUP_USTAVOK; i++)
  {
    if (active_inputs_grupa_ustavok & (1 << i)) 
    {
      _CLEAR_BIT(active_functions, RNG_BIG_INVERS_DV_GRUPA_USTAVOK);//!@RANG_INVERS_DV_GRUPA_USTAVOK
      break;
    }
    else
    {
      if (i == (NUMBER_GROUP_USTAVOK - 1)) _SET_BIT(active_functions, RNG_BIG_INVERS_DV_GRUPA_USTAVOK);//!@RANG_INVERS_DV_GRUPA_USTAVOK
    }
  }
  
  if (count_number_set_bit(&active_inputs_grupa_ustavok, NUMBER_GROUP_USTAVOK) > 1)
    _SET_BIT(set_diagnostyka, ERROR_SELECT_GRUPY_USRAVOK);
  else
    _SET_BIT(clear_diagnostyka, ERROR_SELECT_GRUPY_USRAVOK);
   
  if (
//      ((active_functions[0] & MASKA_SIGNALES_FOR_LOCK_GROUP_PICKUP_0) != 0) ||
//      ((active_functions[1] & MASKA_SIGNALES_FOR_LOCK_GROUP_PICKUP_1) != 0) ||
//      ((active_functions[2] & MASKA_SIGNALES_FOR_LOCK_GROUP_PICKUP_2) != 0) ||
//      ((active_functions[3] & MASKA_SIGNALES_FOR_LOCK_GROUP_PICKUP_3) != 0) ||
//      ((active_functions[4] & MASKA_SIGNALES_FOR_LOCK_GROUP_PICKUP_4) != 0) ||
//      ((active_functions[5] & MASKA_SIGNALES_FOR_LOCK_GROUP_PICKUP_5) != 0) ||
//      ((active_functions[6] & MASKA_SIGNALES_FOR_LOCK_GROUP_PICKUP_6) != 0) ||
//      ((active_functions[7] & MASKA_SIGNALES_FOR_LOCK_GROUP_PICKUP_7) != 0) ||
//      ((active_functions[8] & MASKA_SIGNALES_FOR_LOCK_GROUP_PICKUP_8) != 0) 
//   ||   ((active_functions[9] & MASKA_SIGNALES_FOR_LOCK_GROUP_PICKUP_9) != 0) ||
//      ((active_functions[10] & MASKA_SIGNALES_FOR_LOCK_GROUP_PICKUP_10) != 0)
      ((active_functions[0] & (unsigned long)LOCK_GRUP_PKP_CMD_00) != 0) ||
      ((active_functions[1] & (unsigned long)LOCK_GRUP_PKP_CMD_01) != 0) ||
      ((active_functions[2] & (unsigned long)LOCK_GRUP_PKP_CMD_02) != 0) ||
      ((active_functions[3] & (unsigned long)LOCK_GRUP_PKP_CMD_03) != 0) ||
      ((active_functions[4] & (unsigned long)LOCK_GRUP_PKP_CMD_04) != 0) ||
      ((active_functions[5] & (unsigned long)LOCK_GRUP_PKP_CMD_05) != 0) ||
      ((active_functions[6] & (unsigned long)LOCK_GRUP_PKP_CMD_06) != 0) ||
      ((active_functions[7] & (unsigned long)LOCK_GRUP_PKP_CMD_07) != 0) ||
      ((active_functions[8] & (unsigned long)LOCK_GRUP_PKP_CMD_08) != 0) //||
      //((active_functions[9] & LOCK_GRUP_PKP_CMD_09) != 0) ||
      //((active_functions[10] & LOCK_GRUP_PKP_CMD_10) != 0) ||
      //((active_functions[11] & LOCK_GRUP_PKP_CMD_11) != 0) ||
      //((active_functions[12] & LOCK_GRUP_PKP_CMD_12) != 0) 

    )
  {
    //Іде блокування груп уставок - група уставок залишається тою, яка вибрана попередньо
    _SET_BIT(active_functions, RNG_BIG_BLK_GRUP_USTAVOK_VID_ZACHYSTIV);//!@RANG_BLK_GRUP_USTAVOK_VID_ZACHYSTIV

    unsigned int number_group_stp_tmp = 0;
    //!if(( _CHECK_SET_BIT(active_functions, @RANG_1_GRUPA_USTAVOK) ) !=0 ) number_group_stp_tmp++;
    //!if(( _CHECK_SET_BIT(active_functions, @RANG_2_GRUPA_USTAVOK) ) !=0 ) number_group_stp_tmp++;
    //!if(( _CHECK_SET_BIT(active_functions, @RANG_3_GRUPA_USTAVOK) ) !=0 ) number_group_stp_tmp++;
    //!if(( _CHECK_SET_BIT(active_functions, @RANG_4_GRUPA_USTAVOK) ) !=0 ) number_group_stp_tmp++;
    if(( _CHECK_SET_BIT(active_functions, RNG_BIG_1_GRUPA_USTAVOK) ) !=0 ) number_group_stp_tmp++;
    if(( _CHECK_SET_BIT(active_functions, RNG_BIG_2_GRUPA_USTAVOK) ) !=0 ) number_group_stp_tmp++;
    if(( _CHECK_SET_BIT(active_functions, RNG_BIG_3_GRUPA_USTAVOK) ) !=0 ) number_group_stp_tmp++;
    if(( _CHECK_SET_BIT(active_functions, RNG_BIG_4_GRUPA_USTAVOK) ) !=0 ) number_group_stp_tmp++;
    
    if (number_group_stp_tmp != 1)
    {
      //Теоретично цього ніколи не мало б бути
      total_error_sw_fixed(52);
    }
  }
  else
  {
    //Можна вибирати групу уставок - захисти цю операцію не блокують
    _CLEAR_BIT(active_functions, RNG_BIG_BLK_GRUP_USTAVOK_VID_ZACHYSTIV);//RANG_BLK_GRUP_USTAVOK_VID_ZACHYSTIV
    setpoints_selecting(active_functions, active_inputs_grupa_ustavok);
  }

  unsigned int number_group_stp;
  if     (( _CHECK_SET_BIT(active_functions, RNG_BIG_1_GRUPA_USTAVOK) ) !=0 ) number_group_stp = 0;//!@RANG_1_GRUPA_USTAVOK
  else if(( _CHECK_SET_BIT(active_functions, RNG_BIG_2_GRUPA_USTAVOK) ) !=0 ) number_group_stp = 1;//!@RANG_2_GRUPA_USTAVOK
  else if(( _CHECK_SET_BIT(active_functions, RNG_BIG_3_GRUPA_USTAVOK) ) !=0 ) number_group_stp = 2;//!@RANG_3_GRUPA_USTAVOK
  else if(( _CHECK_SET_BIT(active_functions, RNG_BIG_4_GRUPA_USTAVOK) ) !=0 ) number_group_stp = 3;//!@RANG_4_GRUPA_USTAVOK
  else
  {
    //Теоретично цього ніколи не мало б бути
    total_error_sw_fixed(51);
  }
  /**************************/

  /***********************************************************/
  //Розрахунок вимірювань
  /***********************************************************/
  calc_measurement(number_group_stp);

      
  //Діагностика справності раз на період
  diagnostyca_adc_execution();
  
  //Копіюємо вимірювання для низькопріоритетних і високопріоритетних завдань
  unsigned int bank_measurement_high_tmp = (bank_measurement_high ^ 0x1) & 0x1;
  if(semaphore_measure_values_low1 == 0)
  {
    for (unsigned int i = 0; i < _NUMBER_IM; i++) 
    {
      measurement_high[bank_measurement_high_tmp][i] = measurement_middle[i] = measurement[i];
    }
    for (unsigned int i = 0; i < MAX_NUMBER_INDEXES_RESISTANCE; i++) resistance_middle[i] = resistance[i];
  }
  else
  {
    for (unsigned int i = 0; i < _NUMBER_IM; i++) 
    {
      measurement_high[bank_measurement_high_tmp][i] = measurement[i];
    }
  }
  bank_measurement_high = bank_measurement_high_tmp;
  /***********************************************************/
  
  
  /**************************/
  //Сигнал "Несправность Общая"
  /**************************/
  unsigned int diagnostyka_tmp[N_DIAGN];
  for (size_t i = 0; i < N_DIAGN; i ++)
  {
    diagnostyka_tmp[i] = diagnostyka[i];

    diagnostyka_tmp[i] &= (unsigned int)(~clear_diagnostyka[i]); 
    diagnostyka_tmp[i] |= set_diagnostyka[i]; 
  }

  _CLEAR_BIT(diagnostyka_tmp, EVENT_START_SYSTEM_BIT);
  _CLEAR_BIT(diagnostyka_tmp, EVENT_SOFT_RESTART_SYSTEM_BIT);
  _CLEAR_BIT(diagnostyka_tmp, EVENT_DROP_POWER_BIT);
  unsigned int not_null = false;
  for (size_t i = 0; i < N_DIAGN; i++) 
  {
    not_null |= (diagnostyka_tmp[i] != 0);
    if (not_null) break;
  }
              
  if (not_null)
  {
    _SET_BIT(active_functions, RNG_BIG_DEFECT);//!@RANG_DEFECT
    /**************************/
    //Сигнал "Несправность Аварийная"
    /**************************/
    const unsigned int maska_avar_error[N_DIAGN] = {MASKA_AVAR_ERROR_0, MASKA_AVAR_ERROR_1, MASKA_AVAR_ERROR_2, MASKA_AVAR_ERROR_3};

    not_null = false;
    for (size_t i = 0; i < N_DIAGN; i++) 
    {
      not_null |= ((diagnostyka_tmp[i] & maska_avar_error[i])  != 0);
      if (not_null) break;
    }
    if (not_null)
    {
      _SET_BIT(active_functions, RNG_BIG_AVAR_DEFECT);//!@RANG_AVAR_DEFECT
    }
    else
    {
      _CLEAR_BIT(active_functions, RNG_BIG_AVAR_DEFECT);//!@RANG_AVAR_DEFECT
    }
    /**************************/
  }
  else
  {
    _CLEAR_BIT(active_functions, RNG_BIG_DEFECT);//!@RANG_DEFECT
    _CLEAR_BIT(active_functions, RNG_BIG_AVAR_DEFECT);//!@RANG_AVAR_DEFECT
  }
  /**************************/

  
  static unsigned int previous_active_functions[N_BIG];
  
  //Логічні схеми мають працювати тільки у тому випадку, якщо немє сигналу "Аварийная неисправность"
  if (_CHECK_SET_BIT(active_functions, RNG_BIG_AVAR_DEFECT) == 0)//!@RANG_AVAR_DEFECT
  {
    //Аварійна ситуація не зафіксована
    
    /**************************/
    //Обробка передавальних функцій
    /**************************/
    tf_handler(previous_active_functions, active_functions);
    /**************************/

    /**************************/
    //Контроль привода ВВ
    /**************************/
    control_VV(active_functions);
    /**************************/

    /**************************/
    //ДЗO
    /**************************/
    if ((current_settings_prt.configuration & (1 << DZO_BIT_CONFIGURATION)) != 0)
    {
      dzo_handler(active_functions, number_group_stp);
    }
    else
    {
      //Очищуємо сигнали, які не можуть бути у даній конфігурації
      const unsigned int maska_dzo_signals[N_BIG] = 
      {
        (unsigned int)DZO_CMD_00,//MASKA_DZO_SIGNALS_0, 
        (unsigned int)DZO_CMD_01,//MASKA_DZO_SIGNALS_1, 
        (unsigned int)DZO_CMD_02,//MASKA_DZO_SIGNALS_2,
        (unsigned int)DZO_CMD_03,//MASKA_DZO_SIGNALS_3, 
        (unsigned int)DZO_CMD_04,//MASKA_DZO_SIGNALS_4, 
        (unsigned int)DZO_CMD_05,//MASKA_DZO_SIGNALS_5, 
        (unsigned int)DZO_CMD_06,//MASKA_DZO_SIGNALS_6, 
        (unsigned int)DZO_CMD_07,//MASKA_DZO_SIGNALS_7, 
        (unsigned int)DZO_CMD_08,//MASKA_DZO_SIGNALS_8, 
        (unsigned int)DZO_CMD_09,//MASKA_DZO_SIGNALS_9,
        (unsigned int)DZO_CMD_10,//MASKA_DZO_SIGNALS_10
        (unsigned int)DZO_CMD_11,//MASKA_DZO_SIGNALS_11
        (unsigned int)DZO_CMD_11,//MASKA_DZO_SIGNALS_12
      };
      for (unsigned int i = 0; i < N_BIG; i++) active_functions[i] &= (unsigned int)(~maska_dzo_signals[i]);
      
      global_timers[INDEX_TIMER_DZO1] = -1;
      global_timers[INDEX_TIMER_DZO1_AMTZ] = -1;
      global_timers[INDEX_TIMER_DZO2_DIR] = -1;
      global_timers[INDEX_TIMER_DZO2_DIR_PR] = -1;
      global_timers[INDEX_TIMER_DZO2_INV] = -1;
      global_timers[INDEX_TIMER_DZO2_INV_PR] = -1;
      global_timers[INDEX_TIMER_DZO2_AMTZ] = -1;
      global_timers[INDEX_TIMER_DZO2_AMTZ_PR] = -1;
      global_timers[INDEX_TIMER_DZO2_VVID_PR] = -1;
      global_timers[INDEX_TIMER_DZO2_AMTZ_VVID_PR] = -1;
      global_timers[INDEX_TIMER_DZO3_DIR] = -1;
      global_timers[INDEX_TIMER_DZO3_DIR_PR] = -1;
      global_timers[INDEX_TIMER_DZO3_INV] = -1;
      global_timers[INDEX_TIMER_DZO3_INV_PR] = -1;
      global_timers[INDEX_TIMER_DZO3_AMTZ] = -1;
      global_timers[INDEX_TIMER_DZO3_AMTZ_PR] = -1;
      global_timers[INDEX_TIMER_DZO3_VVID_PR] = -1;
      global_timers[INDEX_TIMER_DZO3_AMTZ_VVID_PR] = -1;
      global_timers[INDEX_TIMER_DZO4_DIR] = -1;
      //global_timers[INDEX_TIMER_DZO4_DIR_PR] = -1;
      global_timers[INDEX_TIMER_DZO4_INV] = -1;
      //global_timers[INDEX_TIMER_DZO4_INV_PR] = -1;
      global_timers[INDEX_TIMER_DZO4_AMTZ] = -1;
      //global_timers[INDEX_TIMER_DZO4_AMTZ_PR] = -1;
      //global_timers[INDEX_TIMER_DZO4_VVID_PR] = -1;
      //global_timers[INDEX_TIMER_DZO4_AMTZ_VVID_PR] = -1;
      global_timers[INDEX_TIMER_NKN_DZO] = -1;
    }
    /**************************/

    /**************************/
    //МТЗ
    /**************************/
    if ((current_settings_prt.configuration & (1 << MTZ1_BIT_CONFIGURATION)) != 0)
    {
      //mtz_handler(active_functions, number_group_stp);
    }
    else
    {
      //Очищуємо сигнали, які не можуть бути у даній конфігурації
      const unsigned int maska_mtz_signals[N_BIG] = 
      {
        0,//MASKA_MTZ_SIGNALS_0,
        0,//MASKA_MTZ_SIGNALS_1,
        0,//MASKA_MTZ_SIGNALS_2, 
        0,//MASKA_MTZ_SIGNALS_3, 
        0,//MASKA_MTZ_SIGNALS_4, 
        0,//MASKA_MTZ_SIGNALS_5,
        0,//MASKA_MTZ_SIGNALS_6, 
        0,//MASKA_MTZ_SIGNALS_7, 
        0,//MASKA_MTZ_SIGNALS_8, 
        0,//MASKA_MTZ_SIGNALS_9,
        0,//MASKA_MTZ_SIGNALS_10
        0,//MASKA_MTZ_SIGNALS_11
        0,//MASKA_MTZ_SIGNALS_12
      };
      for (unsigned int i = 0; i < N_BIG; i++) active_functions[i] &= (unsigned int)(~maska_mtz_signals[i]);
      
      //global_timers[INDEX_TIMER_MTZ1] = -1;
      //global_timers[INDEX_TIMER_MTZ1_N_VPERED] = -1;
      //global_timers[INDEX_TIMER_MTZ1_N_NAZAD] = -1;
      //global_timers[INDEX_TIMER_MTZ1_PO_NAPRUZI] = -1;
      //global_timers[INDEX_TIMER_MTZ2] = -1;
      //global_timers[INDEX_TIMER_MTZ2_DEPENDENT] = -1;
      //global_timers[INDEX_TIMER_MTZ2_PR] = -1;
      //global_timers[INDEX_TIMER_MTZ2_N_VPERED] = -1;
      //global_timers[INDEX_TIMER_MTZ2_N_VPERED_PR] = -1;
      //global_timers[INDEX_TIMER_MTZ2_N_NAZAD] = -1;
      //global_timers[INDEX_TIMER_MTZ2_N_NAZAD_PR] = -1;
      //global_timers[INDEX_TIMER_MTZ2_PO_NAPRUZI] = -1;
      //global_timers[INDEX_TIMER_MTZ2_PO_NAPRUZI_PR] = -1;
      //global_timers[INDEX_TIMER_MTZ2_VVID_PR] = -1;
      //global_timers[INDEX_TIMER_MTZ3] = -1;
      //global_timers[INDEX_TIMER_MTZ3_N_VPERED] = -1;
      //global_timers[INDEX_TIMER_MTZ3_N_NAZAD] = -1;
      //global_timers[INDEX_TIMER_MTZ3_PO_NAPRUZI] = -1;
      //global_timers[INDEX_TIMER_MTZ4] = -1;
      //global_timers[INDEX_TIMER_MTZ4_N_VPERED] = -1;
      //global_timers[INDEX_TIMER_MTZ4_N_NAZAD] = -1;
      //global_timers[INDEX_TIMER_MTZ4_PO_NAPRUZI] = -1;
    }
    /**************************/
     /**************************/
    //МТЗO
    /**************************/
    if ((current_settings_prt.configuration & (1 << MCZO_BIT_CONFIGURATION)) != 0)
    {
	  mtzo_handler(active_functions, number_group_stp);//
    }
    else
    {
      //Очищуємо сигнали, які не можуть бути у даній конфігурації
      const unsigned int maska_mtzo_signals[N_BIG] = 
      {
        (unsigned int)MCZO_CMD_00,//MASKA_MTZO_SIGNALS_0,
        (unsigned int)MCZO_CMD_01,//MASKA_MTZO_SIGNALS_1,
        (unsigned int)MCZO_CMD_02,//MASKA_MTZO_SIGNALS_2, 
        (unsigned int)MCZO_CMD_03,//MASKA_MTZO_SIGNALS_3, 
        (unsigned int)MCZO_CMD_04,//MASKA_MTZO_SIGNALS_4, 
        (unsigned int)MCZO_CMD_05,//MASKA_MTZO_SIGNALS_5,
        (unsigned int)MCZO_CMD_06,//MASKA_MTZO_SIGNALS_6, 
        (unsigned int)MCZO_CMD_07,//MASKA_MTZO_SIGNALS_7, 
        (unsigned int)MCZO_CMD_08,//MASKA_MTZO_SIGNALS_8, 
        (unsigned int)MCZO_CMD_09,//MASKA_MTZO_SIGNALS_9
        (unsigned int)MCZO_CMD_10,//MASKA_MTZO_SIGNALS_10
        (unsigned int)MCZO_CMD_11,//MASKA_MTZO_SIGNALS_11
        (unsigned int)MCZO_CMD_12,//MASKA_MTZO_SIGNALS_12
      };
      for (unsigned int i = 0; i < N_BIG; i++) active_functions[i] &= (unsigned int)(~maska_mtzo_signals[i]);
      
      global_timers[INDEX_TIMER_MTZO1] = -1;
      global_timers[INDEX_TIMER_MTZO1_N_VPERED] = -1;
      global_timers[INDEX_TIMER_MTZO1_N_NAZAD] = -1;
      global_timers[INDEX_TIMER_MTZO1_PO_NAPRUZI] = -1;
      global_timers[INDEX_TIMER_MTZO2] = -1;
      global_timers[INDEX_TIMER_MTZO2_DEPENDENT] = -1;
      global_timers[INDEX_TIMER_MTZO2_PR] = -1;
      global_timers[INDEX_TIMER_MTZO2_N_VPERED] = -1;
      global_timers[INDEX_TIMER_MTZO2_N_VPERED_PR] = -1;
      global_timers[INDEX_TIMER_MTZO2_N_NAZAD] = -1;
      global_timers[INDEX_TIMER_MTZO2_N_NAZAD_PR] = -1;
      global_timers[INDEX_TIMER_MTZO2_PO_NAPRUZI] = -1;
      global_timers[INDEX_TIMER_MTZO2_PO_NAPRUZI_PR] = -1;
      global_timers[INDEX_TIMER_MTZO2_VVID_PR] = -1;
      global_timers[INDEX_TIMER_MTZO3] = -1;
      global_timers[INDEX_TIMER_MTZO3_N_VPERED] = -1;
      global_timers[INDEX_TIMER_MTZO3_N_NAZAD] = -1;
      global_timers[INDEX_TIMER_MTZO3_PO_NAPRUZI] = -1;
      global_timers[INDEX_TIMER_MTZO4] = -1;
      global_timers[INDEX_TIMER_MTZO4_N_VPERED] = -1;
      global_timers[INDEX_TIMER_MTZO4_N_NAZAD] = -1;
      global_timers[INDEX_TIMER_MTZO4_PO_NAPRUZI] = -1;
    }
    /**************************/
    /**************************/
    //МТЗP
    /**************************/
    if ((current_settings_prt.configuration & (1 << MCZR_BIT_CONFIGURATION)) != 0)
    {
      //mtzr_handler(active_functions, number_group_stp);
    }
    else
    {
      //Очищуємо сигнали, які не можуть бути у даній конфігурації
      const unsigned int maska_mtzr_signals[N_BIG] = 
      {
        (unsigned int)MCZR_CMD_00,//MASKA_MTZR_SIGNALS_0,
        (unsigned int)MCZR_CMD_01,//MASKA_MTZR_SIGNALS_1,
        (unsigned int)MCZR_CMD_02,//MASKA_MTZR_SIGNALS_2, 
        (unsigned int)MCZR_CMD_03,//MASKA_MTZR_SIGNALS_3, 
        (unsigned int)MCZR_CMD_04,//MASKA_MTZR_SIGNALS_4, 
        (unsigned int)MCZR_CMD_05,//MASKA_MTZR_SIGNALS_5,
        (unsigned int)MCZR_CMD_06,//MASKA_MTZR_SIGNALS_6, 
        (unsigned int)MCZR_CMD_07,//MASKA_MTZR_SIGNALS_7, 
        (unsigned int)MCZR_CMD_08,//MASKA_MTZR_SIGNALS_8, 
        (unsigned int)MCZR_CMD_09,//MASKA_MTZR_SIGNALS_9
        (unsigned int)MCZR_CMD_10,//MASKA_MTZR_SIGNALS_10
        (unsigned int)MCZR_CMD_11,//MASKA_MTZR_SIGNALS_11
        (unsigned int)MCZR_CMD_12,//MASKA_MTZR_SIGNALS_12
      };
      for (unsigned int i = 0; i < N_BIG; i++) active_functions[i] &= (unsigned int)(~maska_mtzr_signals[i]);
      
      global_timers[INDEX_TIMER_MTZR1] = -1;
      global_timers[INDEX_TIMER_MTZR1_N_VPERED] = -1;
      global_timers[INDEX_TIMER_MTZR1_N_NAZAD] = -1;
      global_timers[INDEX_TIMER_MTZR1_PO_NAPRUZI] = -1;
      
      global_timers[INDEX_TIMER_MTZR2] = -1;
      global_timers[INDEX_TIMER_MTZR2_N_VPERED] = -1;
      global_timers[INDEX_TIMER_MTZR2_N_NAZAD] = -1;
      global_timers[INDEX_TIMER_MTZR2_PO_NAPRUZI] = -1;
      
    }
    /**************************/
	/**************************/
    //ДЗP
    /**************************/
    if ((current_settings_prt.configuration & (1 << DZR_BIT_CONFIGURATION)) != 0)
    {
      //dzr_handler(active_functions, number_group_stp);
    }
    else
    {
      //Очищуємо сигнали, які не можуть бути у даній конфігурації
      const unsigned int maska_dzr_signals[N_BIG] = 
      {
        (unsigned int)DZR_CMD_00,//MASKA_DZR_SIGNALS_0, 
        (unsigned int)DZR_CMD_01,//MASKA_DZR_SIGNALS_1, 
        (unsigned int)DZR_CMD_02,//MASKA_DZR_SIGNALS_2,
        (unsigned int)DZR_CMD_03,//MASKA_DZR_SIGNALS_3, 
        (unsigned int)DZR_CMD_04,//MASKA_DZR_SIGNALS_4, 
        (unsigned int)DZR_CMD_05,//MASKA_DZR_SIGNALS_5, 
        (unsigned int)DZR_CMD_06,//MASKA_DZR_SIGNALS_6, 
        (unsigned int)DZR_CMD_07,//MASKA_DZR_SIGNALS_7, 
        (unsigned int)DZR_CMD_08,//MASKA_DZR_SIGNALS_8, 
        (unsigned int)DZR_CMD_09,//MASKA_DZR_SIGNALS_9
        (unsigned int)DZR_CMD_10,//MASKA_DZR_SIGNALS_10
        (unsigned int)DZR_CMD_11,//MASKA_DZR_SIGNALS_11
        (unsigned int)DZR_CMD_12,//MASKA_DZR_SIGNALS_12
      };
      for (unsigned int i = 0; i < N_BIG; i++) active_functions[i] &= (unsigned int)(~maska_dzr_signals[i]);
      
      global_timers[INDEX_TIMER_DZR1] = -1;
      global_timers[INDEX_TIMER_DZR1_AMTZ] = -1;
      global_timers[INDEX_TIMER_DZR2_DIR] = -1;
      global_timers[INDEX_TIMER_DZR2_DIR_PR] = -1;
      global_timers[INDEX_TIMER_DZR2_INV] = -1;
      global_timers[INDEX_TIMER_DZR2_INV_PR] = -1;
      global_timers[INDEX_TIMER_DZR2_AMTZ] = -1;
      global_timers[INDEX_TIMER_DZR2_AMTZ_PR] = -1;
      global_timers[INDEX_TIMER_DZR2_VVID_PR] = -1;
      global_timers[INDEX_TIMER_DZR2_AMTZ_VVID_PR] = -1;
      global_timers[INDEX_TIMER_DZR3_DIR] = -1;
      global_timers[INDEX_TIMER_DZR3_DIR_PR] = -1;
      global_timers[INDEX_TIMER_DZR3_INV] = -1;
      global_timers[INDEX_TIMER_DZR3_INV_PR] = -1;
      global_timers[INDEX_TIMER_DZR3_AMTZ] = -1;
      global_timers[INDEX_TIMER_DZR3_AMTZ_PR] = -1;
      global_timers[INDEX_TIMER_DZR3_VVID_PR] = -1;
      global_timers[INDEX_TIMER_DZR3_AMTZ_VVID_PR] = -1;
      //global_timers[INDEX_TIMER_DZ4_DIR] = -1;
      //global_timers[INDEX_TIMER_DZ4_DIR_PR] = -1;
      //global_timers[INDEX_TIMER_DZ4_INV] = -1;
      //global_timers[INDEX_TIMER_DZ4_INV_PR] = -1;
      //global_timers[INDEX_TIMER_DZ4_AMTZ] = -1;
      //global_timers[INDEX_TIMER_DZ4_AMTZ_PR] = -1;
      //global_timers[INDEX_TIMER_DZ4_VVID_PR] = -1;
      //global_timers[INDEX_TIMER_DZ4_AMTZ_VVID_PR] = -1;
      global_timers[INDEX_TIMER_NKN_DZR] = -1;
    }
    /**************************/
    if ((current_settings_prt.configuration & (1 << UMIN_BIT_CONFIGURATION)) != 0) 
    {
      /**************************/
      //ЗНМИН1
      /**************************/
      //umin1_handler(active_functions, number_group_stp);
      /**************************/
      
      /**************************/
      //ЗНМИН2
      /**************************/
     // umin2_handler(active_functions, number_group_stp);
      /**************************/
    } 
    else 
    {
      //Очищуємо сигнали, які не можуть бути у даній конфігурації
      const unsigned int maska_umin_signals[N_BIG] = 
      {
        (unsigned int)UMIN_CMD_00,//MASKA_UMIN_SIGNALS_0, 
        (unsigned int)UMIN_CMD_01,//MASKA_UMIN_SIGNALS_1, 
        (unsigned int)UMIN_CMD_02,//MASKA_UMIN_SIGNALS_2,
        (unsigned int)UMIN_CMD_03,//MASKA_UMIN_SIGNALS_3, 
        (unsigned int)UMIN_CMD_04,//MASKA_UMIN_SIGNALS_4, 
        (unsigned int)UMIN_CMD_05,//MASKA_UMIN_SIGNALS_5, 
        (unsigned int)UMIN_CMD_06,//MASKA_UMIN_SIGNALS_6, 
        (unsigned int)UMIN_CMD_07,//MASKA_UMIN_SIGNALS_7, 
        (unsigned int)UMIN_CMD_08,//MASKA_UMIN_SIGNALS_8, 
        (unsigned int)UMIN_CMD_09,//MASKA_UMIN_SIGNALS_9,
        (unsigned int)UMIN_CMD_10,//MASKA_UMIN_SIGNALS_10
        (unsigned int)UMIN_CMD_11,//MASKA_UMIN_SIGNALS_11
        (unsigned int)UMIN_CMD_12//MASKA_UMIN_SIGNALS_12
      };
      for (unsigned int i = 0; i < N_BIG; i++) active_functions[i] &= (unsigned int)(~maska_umin_signals[i]);

      global_timers[INDEX_TIMER_UMIN1] = -1;
      global_timers[INDEX_TIMER_UMIN2] = -1;
    }
    
    if ((current_settings_prt.configuration & (1 << UMAX_BIT_CONFIGURATION)) != 0) 
    {
      /**************************/
      //ЗНМАКС1
      /**************************/
      //umax1_handler(active_functions, number_group_stp);
      /**************************/
      
      /**************************/
      //ЗНМАКС2
      /**************************/
      //umax2_handler(active_functions, number_group_stp);
      /**************************/
    } 
    else 
    {
      //Очищуємо сигнали, які не можуть бути у даній конфігурації
      const unsigned int maska_umax_signals[N_BIG] = 
      {
        (unsigned int)UMAX_CMD_00,//MASKA_UMAX_SIGNALS_0, 
        (unsigned int)UMAX_CMD_01,//MASKA_UMAX_SIGNALS_1, 
        (unsigned int)UMAX_CMD_02,//MASKA_UMAX_SIGNALS_2,
        (unsigned int)UMAX_CMD_03,//MASKA_UMAX_SIGNALS_3, 
        (unsigned int)UMAX_CMD_04,//MASKA_UMAX_SIGNALS_4, 
        (unsigned int)UMAX_CMD_05,//MASKA_UMAX_SIGNALS_5, 
        (unsigned int)UMAX_CMD_06,//MASKA_UMAX_SIGNALS_6, 
        (unsigned int)UMAX_CMD_07,//MASKA_UMAX_SIGNALS_7, 
        (unsigned int)UMAX_CMD_08,//MASKA_UMAX_SIGNALS_8, 
        (unsigned int)UMAX_CMD_09,//MASKA_UMAX_SIGNALS_9,
        (unsigned int)UMAX_CMD_10,//MASKA_UMAX_SIGNALS_10
        (unsigned int)UMAX_CMD_11,//MASKA_UMAX_SIGNALS_11
        (unsigned int)UMAX_CMD_12//MASKA_UMAX_SIGNALS_12
      };
      for (unsigned int i = 0; i < N_BIG; i++) active_functions[i] &= (unsigned int)(~maska_umax_signals[i]);

      global_timers[INDEX_TIMER_UMAX1] = -1;
      global_timers[INDEX_TIMER_UMAX2] = -1;
    }
    
    if ((current_settings_prt.configuration & (1 << ACHR_CHAPV_BIT_CONFIGURATION)) != 0)
    {
      /**************************/
      //АЧР ЧАПВ
      /**************************/
      //achr_chapv_handler(active_functions, number_group_stp);
      /**************************/
    } 
    else 
    {
      //Очищуємо сигнали, які не можуть бути у даній конфігурації
      const unsigned int maska_achr_chapv_signals[N_BIG] = 
      {
        (unsigned int)ACHR_CHAPV_CMD_00,//MASKA_ACHR_CHAPV_SIGNALS_0, 
        (unsigned int)ACHR_CHAPV_CMD_01,//MASKA_ACHR_CHAPV_SIGNALS_1, 
        (unsigned int)ACHR_CHAPV_CMD_02,//MASKA_ACHR_CHAPV_SIGNALS_2,
        (unsigned int)ACHR_CHAPV_CMD_03,//MASKA_ACHR_CHAPV_SIGNALS_3, 
        (unsigned int)ACHR_CHAPV_CMD_04,//MASKA_ACHR_CHAPV_SIGNALS_4, 
        (unsigned int)ACHR_CHAPV_CMD_05,//MASKA_ACHR_CHAPV_SIGNALS_5, 
        (unsigned int)ACHR_CHAPV_CMD_06,//MASKA_ACHR_CHAPV_SIGNALS_6, 
        (unsigned int)ACHR_CHAPV_CMD_07,//MASKA_ACHR_CHAPV_SIGNALS_7, 
        (unsigned int)ACHR_CHAPV_CMD_08,//MASKA_ACHR_CHAPV_SIGNALS_8, 
        (unsigned int)ACHR_CHAPV_CMD_09,//MASKA_ACHR_CHAPV_SIGNALS_9,
        (unsigned int)ACHR_CHAPV_CMD_10,//MASKA_ACHR_CHAPV_SIGNALS_10
        (unsigned int)ACHR_CHAPV_CMD_11,//MASKA_ACHR_CHAPV_SIGNALS_11
        (unsigned int)ACHR_CHAPV_CMD_12 //MASKA_ACHR_CHAPV_SIGNALS_12
      };
      for (unsigned int i = 0; i < N_BIG; i++) active_functions[i] &= (unsigned int)(~maska_achr_chapv_signals[i]);

      global_timers[INDEX_TIMER_ACHR_CHAPV_100MS_1] = -1;
      global_timers[INDEX_TIMER_CHAPV1_1MS] = -1;
      global_timers[INDEX_TIMER_CHAPV2_1MS] = -1;
      global_timers[INDEX_TIMER_BLOCK_CHAPV1_5MS] = -1;
      global_timers[INDEX_TIMER_BLOCK_CHAPV2_5MS] = -1;
      global_timers[INDEX_TIMER_ACHR1] = -1;
      global_timers[INDEX_TIMER_CHAPV1] = -1;
      global_timers[INDEX_TIMER_ACHR2] = -1;
      global_timers[INDEX_TIMER_CHAPV2] = -1;

      previous_state_po_achr_chapv_umnf1 = 0;
      previous_state_po_achr_chapv_ubpf1 = 0;
      previous_states_CHAPV1 = 0;
      trigger_CHAPV1 = 0;
      previous_states_CHAPV2= 0;
      trigger_CHAPV2= 0;
    }
    
    /**************************/
    //ЗДЗ
    /**************************/
    if ((current_settings_prt.configuration & (1 << ZDZ_BIT_CONFIGURATION)) != 0)
    {
      zdz_handler(active_functions, number_group_stp);
    }
    else
    {
#if (                                   \
     (MODYFIKACIA_VERSII_PZ == 0) ||    \
     (MODYFIKACIA_VERSII_PZ == 3)       \
    )   
      //Вимикаємо можливий режим тестування оптоканалу
      _DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD28) = (((current_settings_prt.zdz_ovd_porig + 1) & 0xf) << 8) | (0 << 12);
      if (zdz_ovd_diagnostyka)
      {
        if (zdz_ovd_diagnostyka & (1 << 0)) _SET_BIT(clear_diagnostyka, TEST_OVD1);
        if (zdz_ovd_diagnostyka & (1 << 1)) _SET_BIT(clear_diagnostyka, TEST_OVD2);
        if (zdz_ovd_diagnostyka & (1 << 2)) _SET_BIT(clear_diagnostyka, TEST_OVD3);
        
        zdz_ovd_diagnostyka = 0;
      }
      delta_time_test = PERIOD_ZDZ_TEST;
#endif
      
      //Очищуємо сигнали, які не можуть бути у даній конфігурації
      const unsigned int maska_zdz_signals[N_BIG] = 
      {
        (unsigned int) ZDZS_CMD_00,//MASKA_ZDZ_SIGNALS_0, 
        (unsigned int) ZDZS_CMD_01,//MASKA_ZDZ_SIGNALS_1, 
        (unsigned int) ZDZS_CMD_02,//MASKA_ZDZ_SIGNALS_2,
        (unsigned int) ZDZS_CMD_03,//MASKA_ZDZ_SIGNALS_3, 
        (unsigned int) ZDZS_CMD_04,//MASKA_ZDZ_SIGNALS_4, 
        (unsigned int) ZDZS_CMD_05,//MASKA_ZDZ_SIGNALS_5, 
        (unsigned int) ZDZS_CMD_06,//MASKA_ZDZ_SIGNALS_6, 
        (unsigned int) ZDZS_CMD_07,//MASKA_ZDZ_SIGNALS_7, 
        (unsigned int) ZDZS_CMD_08,//MASKA_ZDZ_SIGNALS_8, 
        (unsigned int) ZDZS_CMD_09,//MASKA_ZDZ_SIGNALS_9,
        (unsigned int) ZDZS_CMD_10,//MASKA_ZDZ_SIGNALS_10
        (unsigned int) ZDZS_CMD_11,//MASKA_ZDZ_SIGNALS_11
        (unsigned int) ZDZS_CMD_12 //MASKA_ZDZ_SIGNALS_12
      };
      for (unsigned int i = 0; i < N_BIG; i++) active_functions[i] &= (unsigned int)(~maska_zdz_signals[i]);

      global_timers[INDEX_TIMER_ZDZ] = -1;
    }
    /**************************/

    /**************************/
    //УРОВ
    /**************************/
    if ((current_settings_prt.configuration & (1 << UROV_BIT_CONFIGURATION)) != 0)
    {
      //urov_handler(active_functions, number_group_stp);
    }
    else
    {
      //Очищуємо сигнали, які не можуть бути у даній конфігурації
      const unsigned int maska_urov_signals[N_BIG] = 
      {
        UROV_CMD_00,//MASKA_UROV_SIGNALS_0, 
        UROV_CMD_01,//MASKA_UROV_SIGNALS_1, 
        UROV_CMD_02,//MASKA_UROV_SIGNALS_2,
        UROV_CMD_03,//MASKA_UROV_SIGNALS_3, 
        UROV_CMD_04,//MASKA_UROV_SIGNALS_4, 
        UROV_CMD_05,//MASKA_UROV_SIGNALS_5, 
        UROV_CMD_06,//MASKA_UROV_SIGNALS_6, 
        UROV_CMD_07,//MASKA_UROV_SIGNALS_7, 
        UROV_CMD_08,//MASKA_UROV_SIGNALS_8, 
        UROV_CMD_09,//MASKA_UROV_SIGNALS_9,
        UROV_CMD_10,//MASKA_UROV_SIGNALS_10
        UROV_CMD_11,//MASKA_UROV_SIGNALS_11
        UROV_CMD_12 //MASKA_UROV_SIGNALS_12
      };
      for (unsigned int i = 0; i < N_BIG; i++) active_functions[i] &= (unsigned int)(~maska_urov_signals[i]);

      global_timers[INDEX_TIMER_UROV1] = -1;
      global_timers[INDEX_TIMER_UROV2] = -1;
    }
    /**************************/

    /**************************/
    //АПВ
    /**************************/
    if ((current_settings_prt.configuration & (1 << APV_BIT_CONFIGURATION)) != 0)
    {
      //apv_handler(active_functions, number_group_stp);
    }
    else
    {
      //Очищуємо сигнали, які не можуть бути у даній конфігурації
      const unsigned int maska_apv_signals[N_BIG] = 
      {
        APV_CMD_00,//MASKA_APV_SIGNALS_0, 
        APV_CMD_01,//MASKA_APV_SIGNALS_1, 
        APV_CMD_02,//MASKA_APV_SIGNALS_2,
        APV_CMD_03,//MASKA_APV_SIGNALS_3, 
        APV_CMD_04,//MASKA_APV_SIGNALS_4, 
        APV_CMD_05,//MASKA_APV_SIGNALS_5, 
        APV_CMD_06,//MASKA_APV_SIGNALS_6, 
        APV_CMD_07,//MASKA_APV_SIGNALS_7, 
        APV_CMD_08,//MASKA_APV_SIGNALS_8, 
        APV_CMD_09,//MASKA_APV_SIGNALS_9,
        APV_CMD_10,//MASKA_APV_SIGNALS_10
        APV_CMD_11,//MASKA_APV_SIGNALS_11
        APV_CMD_12 //MASKA_APV_SIGNALS_12
      };
      for (unsigned int i = 0; i < N_BIG; i++) active_functions[i] &= (unsigned int)(~maska_apv_signals[i]);

      global_timers[INDEX_TIMER_APV_1] = -1;
      global_timers[INDEX_TIMER_APV_2] = -1;
      global_timers[INDEX_TIMER_APV_3] = -1;
      global_timers[INDEX_TIMER_APV_4] = -1;
      global_timers[INDEX_TIMER_APV_BLOCK_VID_APV1] = -1;
      global_timers[INDEX_TIMER_APV_BLOCK_VID_APV2] = -1;
      global_timers[INDEX_TIMER_APV_BLOCK_VID_APV3] = -1;
      global_timers[INDEX_TIMER_APV_BLOCK_VID_APV4] = -1;
      global_timers[INDEX_TIMER_APV_BLOCK_VID_VV] = -1;
      global_timers[INDEX_TIMER_APV_TMP1] = -1;
      global_timers[INDEX_TIMER_ACHR_CHAPV] = -1;
      global_timers[INDEX_TIMER_APV_TMP2] = -1;

      previous_states_APV_0 = 0;
      trigger_APV_0 = 0;
    }
    /**************************/

    if ((current_settings_prt.configuration & (1 << UP_BIT_CONFIGURATION)) != 0) 
    {
      up_handler(active_functions, number_group_stp);
    } 
    else 
    {
      //Очищуємо сигнали, які не можуть бути у даній конфігурації
      const unsigned int maska_up_signals[N_BIG] = 
      {
        (unsigned int) UP_CMD_00,//MASKA_UP_SIGNALS_0, 
        (unsigned int) UP_CMD_01,//MASKA_UP_SIGNALS_1, 
        (unsigned int) UP_CMD_02,//MASKA_UP_SIGNALS_2,
        (unsigned int) UP_CMD_03,//MASKA_UP_SIGNALS_3, 
        (unsigned int) UP_CMD_04,//MASKA_UP_SIGNALS_4, 
        (unsigned int) UP_CMD_05,//MASKA_UP_SIGNALS_5, 
        (unsigned int) UP_CMD_06,//MASKA_UP_SIGNALS_6, 
        (unsigned int) UP_CMD_07,//MASKA_UP_SIGNALS_7, 
        (unsigned int) UP_CMD_08,//MASKA_UP_SIGNALS_8, 
        (unsigned int) UP_CMD_09,//MASKA_UP_SIGNALS_9,
        (unsigned int) UP_CMD_10,//MASKA_UP_SIGNALS_10
        (unsigned int) UP_CMD_11,//MASKA_UP_SIGNALS_11
        (unsigned int) UP_CMD_12,//MASKA_UP_SIGNALS_12
      };
      for (unsigned int i = 0; i < N_BIG; i++) active_functions[i] &= (unsigned int)(~maska_up_signals[i]);

      for (size_t i = 0; i < NUMBER_UP; i++) global_timers[INDEX_TIMER_UP1 + i] = -1;
    }
    
    /**************************/
    //Розширена логіка
    /**************************/
    if ((current_settings_prt.configuration & (1 << EL_BIT_CONFIGURATION)) != 0)
    {
      unsigned int active_functions_tmp[NUMBER_ITERATION_EL_MAX][N_BIG];
      unsigned int iteration = 0;
      unsigned int repeat_state = false;
      do
      {
        for (unsigned int i = 0; i < iteration; i++)
        {
          if (
              (active_functions_tmp[i][0 ] == active_functions[0 ]) &&
              (active_functions_tmp[i][1 ] == active_functions[1 ]) &&
              (active_functions_tmp[i][2 ] == active_functions[2 ]) &&
              (active_functions_tmp[i][3 ] == active_functions[3 ]) &&
              (active_functions_tmp[i][4 ] == active_functions[4 ]) &&
              (active_functions_tmp[i][5 ] == active_functions[5 ]) &&
              (active_functions_tmp[i][6 ] == active_functions[6 ]) &&
              (active_functions_tmp[i][7 ] == active_functions[7 ]) &&
              (active_functions_tmp[i][8 ] == active_functions[8 ]) &&
              (active_functions_tmp[i][9 ] == active_functions[9 ]) &&
              (active_functions_tmp[i][10] == active_functions[10]) &&
              (active_functions_tmp[i][11] == active_functions[11]) &&
              (active_functions_tmp[i][12] == active_functions[12])
             )
          {
            repeat_state = true;
            break;
          }
        }
        if (repeat_state != false ) break;
        
        active_functions_tmp[iteration][0 ] = active_functions[0 ];
        active_functions_tmp[iteration][1 ] = active_functions[1 ];
        active_functions_tmp[iteration][2 ] = active_functions[2 ];
        active_functions_tmp[iteration][3 ] = active_functions[3 ];
        active_functions_tmp[iteration][4 ] = active_functions[4 ];
        active_functions_tmp[iteration][5 ] = active_functions[5 ];
        active_functions_tmp[iteration][6 ] = active_functions[6 ];
        active_functions_tmp[iteration][7 ] = active_functions[7 ];
        active_functions_tmp[iteration][8 ] = active_functions[8 ];
        active_functions_tmp[iteration][9 ] = active_functions[9 ];
        active_functions_tmp[iteration][10] = active_functions[10];
        active_functions_tmp[iteration][11] = active_functions[11];
        active_functions_tmp[iteration][12] = active_functions[12];

        d_and_handler(active_functions);
        d_or_handler(active_functions);
        d_xor_handler(active_functions);
        d_not_handler(active_functions);
        df_handler(active_functions);
        dt_handler(active_functions);
        
        iteration++;
      }
      while (
             (iteration < current_settings_prt.number_iteration_el)
             &&
             (
              (active_functions_tmp[iteration - 1][0 ] != active_functions[0 ]) ||
              (active_functions_tmp[iteration - 1][1 ] != active_functions[1 ]) ||
              (active_functions_tmp[iteration - 1][2 ] != active_functions[2 ]) ||
              (active_functions_tmp[iteration - 1][3 ] != active_functions[3 ]) ||
              (active_functions_tmp[iteration - 1][4 ] != active_functions[4 ]) ||
              (active_functions_tmp[iteration - 1][5 ] != active_functions[5 ]) ||
              (active_functions_tmp[iteration - 1][6 ] != active_functions[6 ]) ||
              (active_functions_tmp[iteration - 1][7 ] != active_functions[7 ]) ||
              (active_functions_tmp[iteration - 1][8 ] != active_functions[8 ]) ||
              (active_functions_tmp[iteration - 1][9 ] != active_functions[9 ]) ||
              (active_functions_tmp[iteration - 1][10] != active_functions[10]) ||
              (active_functions_tmp[iteration - 1][11] != active_functions[11]) ||
              (active_functions_tmp[iteration - 1][12] != active_functions[12])
             ) 
            );
      
      if (
          (repeat_state != false ) ||
          (iteration >= current_settings_prt.number_iteration_el)
         )
      {
        _SET_BIT(active_functions, RNG_BIG_ERROR_CONF_EL);//!@RANG_ERROR_CONF_EL
      }
      else
      {
        _CLEAR_BIT(active_functions, RNG_BIG_ERROR_CONF_EL);//!@RANG_ERROR_CONF_EL
      }
    }
    else
    {
      //Очищуємо сигнали, які не можуть бути у даній конфігурації
      const unsigned int maska_el_signals[N_BIG] = 
      {
        (unsigned int)EL_CMD_00,//MASKA_EL_SIGNALS_0, 
        (unsigned int)EL_CMD_01,//MASKA_EL_SIGNALS_1, 
        (unsigned int)EL_CMD_02,//MASKA_EL_SIGNALS_2,
        (unsigned int)EL_CMD_03,//MASKA_EL_SIGNALS_3, 
        (unsigned int)EL_CMD_04,//MASKA_EL_SIGNALS_4, 
        (unsigned int)EL_CMD_05,//MASKA_EL_SIGNALS_5, 
        (unsigned int)EL_CMD_06,//MASKA_EL_SIGNALS_6, 
        (unsigned int)EL_CMD_07,//MASKA_EL_SIGNALS_7, 
        (unsigned int)EL_CMD_08,//MASKA_EL_SIGNALS_8, 
        (unsigned int)EL_CMD_09,//MASKA_EL_SIGNALS_9, 
        (unsigned int)EL_CMD_10,//MASKA_EL_SIGNALS_10
        (unsigned int)EL_CMD_11,//MASKA_EL_SIGNALS_11
        (unsigned int)EL_CMD_12 //MASKA_EL_SIGNALS_12
      };
      for (unsigned int i = 0; i < N_BIG; i++) active_functions[i] &= (unsigned int)(~maska_el_signals[i]);
      
      //Скидаємо всі таймери, які відповідають за розширену логіку
      for(unsigned int i = INDEX_TIMER_DF_PROLONG_SET_FOR_BUTTON_INTERFACE_START; i < (INDEX_TIMER_DF_WORK_START + NUMBER_DEFINED_FUNCTIONS); i++)
        global_timers[i] = -1;
      
      static_logic_df = 0;
    }
    /**************************/

    /**************************/
    //Включення-Відключення
    /**************************/
    on_off_handler(active_functions);
    /**************************/
    
    /**************************/
    //ВМП (завжди пісяля логіки Блоку вимикання)
    /**************************/
    vmp_handler(active_functions);
    /**************************/

    /**************************/
    //Готовность к ТУ
    /**************************/
    ready_tu(active_functions);
    /**************************/

    /**************************/
    //Ресурс вимикача (завжди пісяля логіки Блоку вимикання)
    /**************************/
    resurs_vymykacha_handler(active_functions);
    /**************************/
  }
  else
  {
    //Аварійна ситуація зафіксована
    
    //Скидаємо всі активні функції, крім інформативних
    active_functions[0]  &= INFO_CMD_00;//MASKA_INFO_SIGNALES_0;
    active_functions[1]  &= INFO_CMD_01;//MASKA_INFO_SIGNALES_1;
    active_functions[2]  &= INFO_CMD_02;//MASKA_INFO_SIGNALES_2;
    active_functions[3]  &= INFO_CMD_03;//MASKA_INFO_SIGNALES_3;
    active_functions[4]  &= INFO_CMD_04;//MASKA_INFO_SIGNALES_4;
    active_functions[5]  &= INFO_CMD_05;//MASKA_INFO_SIGNALES_5;
    active_functions[6]  &= INFO_CMD_06;//MASKA_INFO_SIGNALES_6;
    active_functions[7]  &= INFO_CMD_07;//MASKA_INFO_SIGNALES_7;
    active_functions[8]  &= INFO_CMD_08;//MASKA_INFO_SIGNALES_8;
    active_functions[9]  &= INFO_CMD_09;//MASKA_INFO_SIGNALES_9;
    active_functions[10] &= INFO_CMD_10;//MASKA_INFO_SIGNALES_10;
    active_functions[11] &= INFO_CMD_11;//MASKA_INFO_SIGNALES_10;
    active_functions[12] &= INFO_CMD_12;//MASKA_INFO_SIGNALES_10;
    
    //Деактивовуємо всі реле
    state_outputs = 0;
    
    //Переводимо у початковий стан деякі глобальні змінні
    previous_states_APV_0 = 0;
    trigger_APV_0 = 0;
    previous_state_po_achr_chapv_umnf1 = 0;
    previous_state_po_achr_chapv_ubpf1 = 0;
    previous_states_CHAPV1 = 0;
    trigger_CHAPV1 = 0;
    previous_states_ready_tu = 0;
    trigger_ready_tu = 0;
    
    //Скидаємо всі таймери, які присутні у лозіці
    for(unsigned int i = INDEX_TIMER_DF_PROLONG_SET_FOR_BUTTON_INTERFACE_START; i < MAX_NUMBER_GLOBAL_TIMERS; i++)
      global_timers[i] = -1;

    static_logic_df = 0;
  }

  /**************************/
  //Обробка аналогового реєстратора
  /**************************/
  analog_registrator(active_functions);
  /**************************/

  /**************************/
  //Обробка дискретного реєстратора
  /**************************/
  digital_registrator(active_functions);
  /**************************/

  /**************************/
  //Робота з функціями, які мають записуватися у енергонезалежну пам'ять
  /**************************/
  const unsigned int maska_trg_func_array[N_BIG] = {
                                                    (unsigned int)TRGO_CMD_00,//MASKA_TRIGGER_SIGNALES_0,
                                                    (unsigned int)TRGO_CMD_01,//MASKA_TRIGGER_SIGNALES_1,
                                                    (unsigned int)TRGO_CMD_02,//MASKA_TRIGGER_SIGNALES_2,
                                                    (unsigned int)TRGO_CMD_03,//MASKA_TRIGGER_SIGNALES_3,
                                                    (unsigned int)TRGO_CMD_04,//MASKA_TRIGGER_SIGNALES_4,
                                                    (unsigned int)TRGO_CMD_05,//MASKA_TRIGGER_SIGNALES_5,
                                                    (unsigned int)TRGO_CMD_06,//MASKA_TRIGGER_SIGNALES_6,
                                                    (unsigned int)TRGO_CMD_07,//MASKA_TRIGGER_SIGNALES_7,
                                                    (unsigned int)TRGO_CMD_08,//MASKA_TRIGGER_SIGNALES_8,
                                                    (unsigned int)TRGO_CMD_09,//MASKA_TRIGGER_SIGNALES_9,
                                                    (unsigned int)TRGO_CMD_10,//MASKA_TRIGGER_SIGNALES_10
                                                    (unsigned int)TRGO_CMD_11,//MASKA_TRIGGER_SIGNALES_11
                                                    (unsigned int)TRGO_CMD_12 //MASKA_TRIGGER_SIGNALES_12
                                                  };
  unsigned int comparison_true = true;
  for (unsigned int i = 0; i < N_BIG; i++)
  {
    unsigned int tmp_data;
    if (trigger_active_functions[i] != (tmp_data = (active_functions[i] & maska_trg_func_array[i])))
    {
      comparison_true = false;
      trigger_active_functions[i] = tmp_data;
    }
  }
  if (comparison_true != true)
  {
    /*
    Сигнали, значення яких записується у енергонезалежну пам'1ять змінилися.
    Подаємо команду на їх запис у енергонезалежну пам'ять
    */
    _SET_BIT(control_spi1_taskes, TASK_START_WRITE_TRG_FUNC_EEPROM_BIT);
  }
  /**************************/

  /**************************/
  //Перекидання інфомації у масиви активних і тригерних функцій
  /**************************/
  for (unsigned int i = 0; i < N_BIG; i++)
  {
    unsigned int temp_data = active_functions[i];
    trigger_functions_USB[i]   |= temp_data;
    trigger_functions_RS485[i] |= temp_data;
  }

  copying_active_functions = 0; //Помічаємо, що обновлення значення активних функцій завершене
  
  /*
  Робимо копію значення активних функцій для того, щоб коли ці знаення будуть
  обновлятися, то можна було б іншим модулям  (запис у об'єднаний аналоговий
  реєстратор) взяти попереднє, але достовірне значення
  */
  for (unsigned int i = 0; i < N_BIG; i++) 
  {
    unsigned int temp_data = active_functions[i];
    active_functions_copy[i] = temp_data;
    previous_active_functions[i] = temp_data;
  }
  /**************************/

  /**************************/
  //Вивід інформації на виходи
  /**************************/
  //Спочатку перевіряємо, чи не активовувалвся команда "Сблос реле" - і якщо так, то попередньо скидаємо всі реле
  if (_CHECK_SET_BIT(active_functions, RNG_BIG_RESET_RELES) !=0)//!@RANG_RESET_RELES
  {
    state_outputs = 0;
  }
  
  if (_CHECK_SET_BIT(active_functions, RNG_BIG_AVAR_DEFECT) == 0)//!@RANG_AVAR_DEFECT
  {
    //Не зафіксовано аварійної ситуації, тому встановлювати реле можна
    
    //Визначаємо, які реле зараз мають бути замкнутими
    for (unsigned int i = 0; i < NUMBER_OUTPUTS; i++)
    {
      //У тимчасовий масив поміщаємо ЛОГІЧНЕ І ранжування виходу, який індексується інедексом "i" і функцій, які зараз є активними
      unsigned int temp_array_of_outputs[N_BIG];
    
      for (unsigned int j = 0; j < N_BIG; j++) temp_array_of_outputs[j] = current_settings_prt.ranguvannja_outputs[N_BIG*i + j] & active_functions[j];

      //Сигнал "Аварійна несправність" працює у інверсному режимі: замикає реле на якому зранжована у випадку, коли даний сигнал не активинй
      if(_CHECK_SET_BIT((current_settings_prt.ranguvannja_outputs + N_BIG*i), RNG_BIG_AVAR_DEFECT) !=0)//!@RANG_AVAR_DEFECT
      {
        //Сигнал "Aварийная неисправность"  справді зранжовано на даний вихід
        if (_CHECK_SET_BIT(temp_array_of_outputs, RNG_BIG_AVAR_DEFECT) == 0)//!@RANG_AVAR_DEFECT
        {
          //Сигнал "Aварийная неисправность" не є активним
          //Приимусово встановлюємо його у активний стан у масиві, який є  ЛОГІЧНИМ І анжування виходу, який індексується інедексом "i" і функцій, які зараз є активними
          _SET_BIT(temp_array_of_outputs, RNG_BIG_AVAR_DEFECT);//!@RANG_AVAR_DEFECT
        }
        else
        {
          //Сигнал "Aварийная неисправность" є активним
          //Приимусово переводимо його у пасивний стан у масиві, який є  ЛОГІЧНИМ І анжування виходу, який індексується інедексом "i" і функцій, які зараз є активними
          _CLEAR_BIT(temp_array_of_outputs,RNG_BIG_AVAR_DEFECT );//!@RANG_AVAR_DEFECT
        }
      }
      
      //Сигнал "Загальна несправність" працює у інверсному режимі: замикає реле на якому зранжована у випадку, коли даний сигнал не активинй
      if(_CHECK_SET_BIT((current_settings_prt.ranguvannja_outputs + N_BIG*i), RNG_BIG_DEFECT) !=0)//!@RANG_DEFECT
      {
        //Сигнал "Загальна несправність"  справді зранжовано на даний вихід
        if (_CHECK_SET_BIT(temp_array_of_outputs, RNG_BIG_DEFECT) ==0)//!@RANG_DEFECT
        {
          //Сигнал "Загальна несправність" не є активним
          //Приимусово встановлюємо його у активний стан у масиві, який є  ЛОГІЧНИМ І анжування виходу, який індексується інедексом "i" і функцій, які зараз є активними
          _SET_BIT(temp_array_of_outputs, RNG_BIG_DEFECT);//!@RANG_DEFECT
        }
        else
        {
          //Сигнал "Загальна несправність" є активним
          //Приимусово переводимо його у пасивний стан у масиві, який є  ЛОГІЧНИМ І анжування виходу, який індексується інедексом "i" і функцій, які зараз є активними
          _CLEAR_BIT(temp_array_of_outputs, RNG_BIG_DEFECT);//!@RANG_DEFECT
        }
      }

      //Перевіряємо, чи є співпадіння між ранжованими функціями на цьому виході і функціями, які зараз є активними - умова активації виходу
      if (
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
      {
        //Для сигнального реле виконуємо його замикання, а для командного перевіряємо чи нема спроби активувати реле при умові що на нього заведено блок включення, причому він блокований
        if ((current_settings_prt.type_of_output & (1 << i)) != 0)
        {
          //Вихід сигнальний, тому у буль якому разі замикаємо реле
          //Відмічаємо, що даний вихід - ЗАМКНУТИЙ
          state_outputs |= (1 << i);
        }
        else
        {
          //Вихід командний, тому перевіряємо чи не йде спроба активувати реле, на яке заведено БВ, причому блок БВ з пеквних причин блокований (неактивний)
          //!@if (_CHECK_SET_BIT((current_settings_prt.ranguvannja_outputs + N_BIG*i), @RANG_WORK_BV) ==0)
          if (_CHECK_SET_BIT((current_settings_prt.ranguvannja_outputs + N_BIG*i), RNG_BIG_WORK_BV_VVO) ==0)
          {
            //На дане реле не заводиться сигнал БВ (блок включення)
          
            //Відмічаємо, що даний вихід - ЗАМКНУТИЙ
            state_outputs |= (1 << i);
          }
          else
          {
            //На дане реле заводиться сигнал БВ (блок включення)
          
            //Відмічаємо, що даний вихід - ЗАМКНУТИЙ тільки тоді, коли функція БВ активна зараз
            //!@if (_CHECK_SET_BIT(active_functions, @RANG_WORK_BV) !=0)
            if (_CHECK_SET_BIT(active_functions, RNG_BIG_WORK_BV_VVO) !=0)
              state_outputs |= (1 << i);
            else
              state_outputs &= ~(1 << i);
          }
        }
      }
      else
      {
        //Перевіряємо, чи вихід командний, чи сигнальний
        if ((current_settings_prt.type_of_output & (1 << i)) == 0)
        {
          //Вихід командний
        
          //Відмічаємо, що даний вихід - РОЗІМКНУТИЙ
          state_outputs &= ~(1 << i);
        }
      }
    }
  }
  else
  {
    //Зафіксовано аварійнe ситуацію, тому деактивуємо всі реле!!!

    //Деактивовуємо всі реле
    state_outputs = 0;
  }
  
  //Перевіряємо чи треба записувати стан сигнальних виходів у EEPROM
  if((state_outputs  & current_settings_prt.type_of_output) != state_signal_outputs)
  {
    state_signal_outputs = state_outputs  & current_settings_prt.type_of_output;
    //Виставляємо повідомлення про те, що в EEPROM треба записати нові значення сигнальних виходів і тригерних світлоіндикаторів
    _SET_BIT(control_spi1_taskes, TASK_START_WRITE_STATE_LEDS_OUTPUTS_EEPROM_BIT);
  }
  
  //Стан виходу з уразуванням імпульсного режиму роботи сигнальних виходів
  unsigned int output_signal_modif = (current_settings_prt.type_of_output_modif & current_settings_prt.type_of_output);
  state_outputs_raw = ( state_outputs & ((unsigned int)(~output_signal_modif)) ) | ((state_outputs & output_signal_modif)*output_timer_prt_signal_output_mode_2);
  
  _DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD31_DD34_DD35_DD37) = state_outputs_raw;
  TIM_PRT_write_tick = TIM2->CNT;
  /**************************/

  /**************************/
  //Вивід інформації на світлодіоди
  /**************************/
  //Спочатку перевіряємо, чи не активовувалвся команда "Сблос индикации" - і якщо так, то попередньо скидаємо всю індикацію
  if (_CHECK_SET_BIT(active_functions, RNG_BIG_RESET_LEDS) !=0)//!@RANG_RESET_LEDS
  {
    state_leds = 0;
  }
  
  //Визначаємо, які світлоіндикатори зараз мають бути активними
  for (unsigned int i = 0; i < NUMBER_LEDS; i++)
  {
    //У тимчасовий масив копіюємо ранжування світлоіндикатора, який індексується інедексом "i"
    unsigned int temp_array_of_leds[N_BIG];
    
    //Перевіряємо, чи є співпадіння між ранжованими функціями на цьому світлоіндикаторі і функціями, які зараз є активними - умова активації виходу
    for (unsigned int j = 0; j < N_BIG; j++ ) temp_array_of_leds[j] = current_settings_prt.ranguvannja_leds[N_BIG*i + j] & active_functions[j];

    if (
        (temp_array_of_leds[0 ] != 0) ||
        (temp_array_of_leds[1 ] != 0) ||
        (temp_array_of_leds[2 ] != 0) ||
        (temp_array_of_leds[3 ] != 0) ||
        (temp_array_of_leds[4 ] != 0) ||
        (temp_array_of_leds[5 ] != 0) ||
        (temp_array_of_leds[6 ] != 0) ||
        (temp_array_of_leds[7 ] != 0) ||
        (temp_array_of_leds[8 ] != 0) ||
        (temp_array_of_leds[9 ] != 0) ||
        (temp_array_of_leds[10] != 0) ||
        (temp_array_of_leds[11] != 0) ||
        (temp_array_of_leds[12] != 0)
       )
    {
      //Відмічаємо, що даний світлоіндикатор - ГОРИТЬ
      state_leds |= (1 << i);
    }
    else
    {
      //Перевіряємо, чи даний світлоіндикатор нормальний, чи тригерний
      if ((current_settings_prt.type_of_led & (1 << i)) == 0)
      {
        //Світлоіндикатор нормальний

        //Відмічаємо, що даний світлоіндикатор - ПОГАШЕНИЙ
        state_leds &= ~(1 << i);
      }
    }
  }
  //Перевіряємо чи треба записувати стан тригерних світлоіндикаторів у EEPROM
  if((state_leds  & current_settings_prt.type_of_led) != state_trigger_leds)
  {
    state_trigger_leds = state_leds  & current_settings_prt.type_of_led;
    //Виставляємо повідомлення про те, що в EEPROM треба записати нові значення сигнальних виходів і тригерних світлоіндикаторів
    _SET_BIT(control_spi1_taskes, TASK_START_WRITE_STATE_LEDS_OUTPUTS_EEPROM_BIT);
  }
  
  //Сервісні світлоіндикатори
  /*Run_Error*/
  //!@if (_CHECK_SET_BIT(active_functions, @RANG_AVAR_DEFECT) == 0) state_leds_ctrl |=  (1 << LED_COLOR_GREEN_BIT) << ((uint32_t)NUMBER_LED_COLOR*(uint32_t)LED_CTRL_R_E);
  if (_CHECK_SET_BIT(active_functions, RNG_BIG_AVAR_DEFECT) == 0) state_leds_ctrl |=  (1 << LED_COLOR_GREEN_BIT) << ((uint32_t)NUMBER_LED_COLOR*(uint32_t)LED_CTRL_R_E);
  else state_leds_ctrl &=  (uint32_t)(~((1 << LED_COLOR_GREEN_BIT) << ((uint32_t)NUMBER_LED_COLOR*(uint32_t)LED_CTRL_R_E)));
  if (
      (_CHECK_SET_BIT(active_functions, RNG_BIG_DEFECT     ) != 0) ||//!@(_CHECK_SET_BIT(active_functions, @RANG_DEFECT     ) != 0) ||
      (_CHECK_SET_BIT(active_functions, RNG_BIG_AVAR_DEFECT) != 0)//!@RANG_AVAR_DEFECT
     ) state_leds_ctrl |=  (1 << LED_COLOR_RED_BIT) << ((uint32_t)NUMBER_LED_COLOR*(uint32_t)LED_CTRL_R_E);
  else state_leds_ctrl &=  (uint32_t)(~((1 << LED_COLOR_RED_BIT) << ((uint32_t)NUMBER_LED_COLOR*(uint32_t)LED_CTRL_R_E)));
  
  static uint32_t current_LED_N_COL;
  
  //Очищаємо попередню інформацію
  _DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD32_DD38) = ((1 << current_LED_N_COL) << LED_N_ROW) | ((uint32_t)(~0) & ((1 << LED_N_ROW) - 1));
  //Переходимо на наступний стовбець
  if (++current_LED_N_COL >= LED_N_COL) current_LED_N_COL = 0;
  
  uint32_t state_leds_tmp;
  
  switch (current_LED_N_COL)
  {
  case 0:
    {
      state_leds_tmp = (((state_leds >>  0) & 0x1) << 0) |
                       (((state_leds >>  2) & 0x1) << 1) |
                       (((state_leds >>  4) & 0x1) << 2) |
                       (((state_leds >>  6) & 0x1) << 3) |
                       (((state_leds >>  8) & 0x1) << 4) |
                       (((state_leds >> 10) & 0x1) << 5) |
                       (((state_leds >> 12) & 0x1) << 6) |
                       (((state_leds >> 14) & 0x1) << 7);

//      state_leds_tmp = (((state_leds >> (2*0)) & ((1 << 2) - 1)) << 0) |
//                       (((state_leds_ctrl >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)LED_CTRL_R_E)) & ((1 << NUMBER_LED_COLOR) - 1)) << 2) |
//                       (((state_leds_Fx[0] >> (NUMBER_LED_COLOR*(6 - 1))) & ((1 << NUMBER_LED_COLOR) - 1)) << 4);
      break;
    }
  case 1:
    {
      uint32_t temp_state = state_leds;
      state_leds_tmp = (((temp_state >>  1) & 0x1) << 0) |
                       (((temp_state >>  3) & 0x1) << 1) |
                       (((temp_state >>  5) & 0x1) << 2) |
                       (((temp_state >>  7) & 0x1) << 3) |
                       (((temp_state >>  9) & 0x1) << 4) |
                       (((temp_state >> 11) & 0x1) << 5) |
                       (((temp_state >> 13) & 0x1) << 6) |
                       ((((state_leds_ctrl >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)LED_CTRL_O)) & (1 << LED_COLOR_RED_BIT)) != 0) << 7);

//      state_leds_tmp = (((state_leds >> (2*1)) & ((1 << 2) - 1)) << 0) |
//                       (((state_leds_ctrl >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)LED_CTRL_START)) & ((1 << NUMBER_LED_COLOR) - 1)) << 2) |
//                       (((state_leds_Fx[1] >> (NUMBER_LED_COLOR*(1 - 1))) & ((1 << NUMBER_LED_COLOR) - 1)) << 4);
      break;
    }
  case 2:
    {
      state_leds_tmp = ((((state_leds_ctrl >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)LED_CTRL_R_E  )) & (1 << LED_COLOR_RED_BIT)) != 0) << 0) |
                      /*
                       ((((state_leds_ctrl >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)LED_CTRL_START)) & (1 << LED_COLOR_RED_BIT)) != 0) << 1) |
                       ((((state_leds_ctrl >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)LED_CTRL_TRIP )) & (1 << LED_COLOR_RED_BIT)) != 0) << 2) |
                      */
                       (((state_leds >> 15) & 0x1) << 1) |
                       (((state_leds >> 16) & 0x1) << 2) |
      
                       ((((state_leds_Fx[0] >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)(1 - 1))) & (1 << LED_COLOR_RED_BIT)) != 0) << 3) | 
                       ((((state_leds_Fx[0] >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)(2 - 1))) & (1 << LED_COLOR_RED_BIT)) != 0) << 4) | 
                       ((((state_leds_Fx[0] >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)(3 - 1))) & (1 << LED_COLOR_RED_BIT)) != 0) << 5) | 
                       ((((state_leds_Fx[0] >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)(4 - 1))) & (1 << LED_COLOR_RED_BIT)) != 0) << 6) | 
                       ((((state_leds_Fx[0] >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)(5 - 1))) & (1 << LED_COLOR_RED_BIT)) != 0) << 7);
      
//      state_leds_tmp = (((state_leds >> (2*2)) & ((1 << 2) - 1)) << 0) |
//                       (((state_leds_ctrl >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)LED_CTRL_TRIP)) & ((1 << NUMBER_LED_COLOR) - 1)) << 2) |
//                       (((state_leds_Fx[1] >> (NUMBER_LED_COLOR*(2 - 1))) & ((1 << NUMBER_LED_COLOR) - 1)) << 4);
      break;
    }
  case 3:
    {
      state_leds_tmp = ((((state_leds_ctrl >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)LED_CTRL_R_E  )) & (1 << LED_COLOR_GREEN_BIT)) != 0) << 0) |
                      /*
                       ((((state_leds_ctrl >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)LED_CTRL_START)) & (1 << LED_COLOR_GREEN_BIT)) != 0) << 1) |
                       ((((state_leds_ctrl >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)LED_CTRL_TRIP )) & (1 << LED_COLOR_GREEN_BIT)) != 0) << 2) |
                      */
                       ((((state_leds_Fx[0] >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)(1 - 1))) & (1 << LED_COLOR_GREEN_BIT)) != 0) << 3) | 
                       ((((state_leds_Fx[0] >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)(2 - 1))) & (1 << LED_COLOR_GREEN_BIT)) != 0) << 4) | 
                       ((((state_leds_Fx[0] >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)(3 - 1))) & (1 << LED_COLOR_GREEN_BIT)) != 0) << 5) | 
                       ((((state_leds_Fx[0] >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)(4 - 1))) & (1 << LED_COLOR_GREEN_BIT)) != 0) << 6) | 
                       ((((state_leds_Fx[0] >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)(5 - 1))) & (1 << LED_COLOR_GREEN_BIT)) != 0) << 7);
      
//      state_leds_tmp = (((state_leds >> (2*3)) & ((1 << 2) - 1)) << 0) |
//                       (((state_leds_Fx[0] >> (NUMBER_LED_COLOR*(1 - 1))) & ((1 << NUMBER_LED_COLOR) - 1)) << 2) |
//                       (((state_leds_Fx[1] >> (NUMBER_LED_COLOR*(3 - 1))) & ((1 << NUMBER_LED_COLOR) - 1)) << 4);
      break;
    }
  case 4:
    {
      state_leds_tmp = ((((state_leds_Fx[0] >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)(6 - 1))) & (1 << LED_COLOR_RED_BIT)) != 0) << 0) |
                       ((((state_leds_Fx[1] >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)(1 - 1))) & (1 << LED_COLOR_RED_BIT)) != 0) << 1) |
                       ((((state_leds_Fx[1] >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)(2 - 1))) & (1 << LED_COLOR_RED_BIT)) != 0) << 2) |
                       ((((state_leds_Fx[1] >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)(3 - 1))) & (1 << LED_COLOR_RED_BIT)) != 0) << 3) |
                       ((((state_leds_Fx[1] >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)(4 - 1))) & (1 << LED_COLOR_RED_BIT)) != 0) << 4) |
                       ((((state_leds_Fx[1] >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)(5 - 1))) & (1 << LED_COLOR_RED_BIT)) != 0) << 5) |
                       ((((state_leds_Fx[1] >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)(6 - 1))) & (1 << LED_COLOR_RED_BIT)) != 0) << 6) |
                       ((((state_leds_ctrl >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)LED_CTRL_I)) & (1 << LED_COLOR_RED_BIT)) != 0) << 7);

//      state_leds_tmp = (((state_leds >> (2*4)) & ((1 << 2) - 1)) << 0) |
//                       (((state_leds_Fx[0] >> (NUMBER_LED_COLOR*(2 - 1))) & ((1 << NUMBER_LED_COLOR) - 1)) << 2) |
//                       (((state_leds_Fx[1] >> (NUMBER_LED_COLOR*(4 - 1))) & ((1 << NUMBER_LED_COLOR) - 1)) << 4);
      break;
    }
  case 5:
    {
      state_leds_tmp = ((((state_leds_Fx[0] >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)(6 - 1))) & (1 << LED_COLOR_GREEN_BIT)) != 0) << 0) |
                       ((((state_leds_Fx[1] >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)(1 - 1))) & (1 << LED_COLOR_GREEN_BIT)) != 0) << 1) |
                       ((((state_leds_Fx[1] >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)(2 - 1))) & (1 << LED_COLOR_GREEN_BIT)) != 0) << 2) |
                       ((((state_leds_Fx[1] >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)(3 - 1))) & (1 << LED_COLOR_GREEN_BIT)) != 0) << 3) |
                       ((((state_leds_Fx[1] >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)(4 - 1))) & (1 << LED_COLOR_GREEN_BIT)) != 0) << 4) |
                       ((((state_leds_Fx[1] >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)(5 - 1))) & (1 << LED_COLOR_GREEN_BIT)) != 0) << 5) |
                       ((((state_leds_Fx[1] >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)(6 - 1))) & (1 << LED_COLOR_GREEN_BIT)) != 0) << 6) |
                       ((((state_leds_ctrl >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)LED_CTRL_I)) & (1 << LED_COLOR_GREEN_BIT)) != 0) << 7);

//      state_leds_tmp = (((state_leds >> (2*5)) & ((1 << 2) - 1)) << 0) |
//                       (((state_leds_Fx[0] >> (NUMBER_LED_COLOR*(3 - 1))) & ((1 << NUMBER_LED_COLOR) - 1)) << 2) |
//                       (((state_leds_Fx[1] >> (NUMBER_LED_COLOR*(5 - 1))) & ((1 << NUMBER_LED_COLOR) - 1)) << 4);
      break;
    }
  case 6:
    {
      state_leds_tmp = ((((state_leds_ctrl >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)LED_CTRL_O)) & (1 << LED_COLOR_GREEN_BIT)) != 0) << 7);

//      state_leds_tmp = (((state_leds >> (2*6)) & ((1 << 2) - 1)) << 0) |
//                       (((state_leds_Fx[0] >> (NUMBER_LED_COLOR*(4 - 1))) & ((1 << NUMBER_LED_COLOR) - 1)) << 2) |
//                       (((state_leds_Fx[1] >> (NUMBER_LED_COLOR*(6 - 1))) & ((1 << NUMBER_LED_COLOR) - 1)) << 4);
      break;
    }
//  case 7:
//    {
//      state_leds_tmp = (((state_leds >> (2*7)) & ((1 << 1) - 1)) << 0) |
//                       ((((state_leds_ctrl >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)LED_CTRL_O)) & (1 << LED_COLOR_RED_BIT)) != 0) << 1) |
//                       (((state_leds_Fx[0] >> (NUMBER_LED_COLOR*(5 - 1))) & ((1 << NUMBER_LED_COLOR) - 1)) << 2) |
//                       (((state_leds_ctrl >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)LED_CTRL_I)) & ((1 << NUMBER_LED_COLOR) - 1)) << 4) |
//                       ((((state_leds_ctrl >> ((uint32_t)NUMBER_LED_COLOR*(uint32_t)LED_CTRL_O)) & (1 << LED_COLOR_GREEN_BIT)) != 0) << 6);
//      break;
//    }
  default:
    {
      //Теоретично цього ніколи не мало б бути
      total_error_sw_fixed(22);
    }
  }

  //Виводимо інформацію по світлоіндикаторах на світлодіоди
  _DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD32_DD38) = ((1 << current_LED_N_COL) << LED_N_ROW) | ((uint32_t)(~state_leds_tmp) & ((1 << LED_N_ROW) - 1));
  /**************************/

  /**************************/
  //
  /**************************/
  /**************************/
}
/*****************************************************/

/*****************************************************/
//Переривання від таймеру TIM2, який обслуговує систему захистів
/*****************************************************/
void TIM2_IRQHandler(void)
{
#ifdef SYSTEM_VIEWER_ENABLE
  SEGGER_SYSVIEW_RecordEnterISR();
#endif
  
  if (TIM_GetITStatus(TIM2, TIM_IT_CC1) != RESET)
  {
    /***********************************************************************************************/
    //Переривання відбулося вік каналу 1, який генерує переривання кожні 1 мс, для опраціьовування таймерів і систем захистів
    /***********************************************************************************************/
    TIM2->SR = (uint16_t)((~(uint32_t)TIM_IT_CC1) & 0xffff);
    uint32_t current_tick = TIM2->CCR1;
    
    /*************************************
    Управління чсом у UNIX-форматі
    *************************************/
    ++clk_count;

    if ( ++time_ms >= 1000) 
    {
      time_ms = 0;
      time_dat++;
    }
      
    if ((save_time_dat_h == 3) || (save_time_dat_l == 3))
    {
      //Процес запису нового часу
      if (save_time_dat_l == 3)
      {
        time_ms = time_ms_save_l;
        time_dat = time_dat_save_l;
        
        save_time_dat_l = 2;
      }
      if (save_time_dat_h == 3)
      {
        time_ms = time_ms_save_h;
        time_dat = time_dat_save_h;
        
        save_time_dat_h = 2;
      }
      
      if (copying_time_to_RTC == 1) copying_time_to_RTC = 0;
    }
    else 
    {
      //Перевірка чи не потрібно забрати час з RTC
      if (copying_time_to_RTC == 1)
      {
        int32_t diff_ms = time_ms - time_ms_RTC;
        time_t diff_s = time_dat - time_dat_RTC;
        if (diff_ms < 0) 
        {
          diff_ms += 1000;
          --diff_s;
        }
        if (llabs(diff_s*1000 + diff_ms) > 2000)
        {
          time_ms = time_ms_RTC;
          time_dat = time_dat_RTC;
        }
        copying_time_to_RTC = 0;
      }
    }
    
    
    if (!copying_time_dat)
    {
      time_ms_copy = time_ms;
      time_dat_copy = time_dat;
    }
    /*************************************/

    /***********************************************************/
    //Перевіряємо, чи відбувалися зміни настройок
    /***********************************************************/
    if (changed_settings == CHANGED_ETAP_ENDED) /*Це є умова, що нові дані підготовлені для передачі їх у роботу системою захистів (і при цьому зараз дані не змінюються)*/
    {
      //Копіюємо таблицю настройок у копію цієї таблиці але з якою працює (читає і змінює) тільки система захистів
      current_settings_prt = current_settings;
      
      //Помічаємо, що зміни прийняті системою захистів
      changed_settings = CHANGED_ETAP_NONE;
    }

    if (koef_resurs_changed == CHANGED_ETAP_ENDED)
    {
      //Коефіцієнти для підрахунку ресурсу вимикача
      K_resurs_prt = K_resurs;

      //Помічаємо, що зміни прийняті системою захистів
      koef_resurs_changed = CHANGED_ETAP_NONE;
    }
    /***********************************************************/

    /***********************************************************/
    //Перевіряємо необхідність очистки дискретного реєстраторів
    /***********************************************************/
    if (
        ((clean_rejestrators & CLEAN_DR) != 0)
        &&  
        (
         (control_tasks_dataflash & (
                                     TASK_MAMORY_PAGE_PROGRAM_THROUGH_BUFFER_DATAFLASH_FOR_DR | 
                                     TASK_MAMORY_READ_DATAFLASH_FOR_DR_USB                    |
                                     TASK_MAMORY_READ_DATAFLASH_FOR_DR_RS485                  |
                                     TASK_MAMORY_READ_DATAFLASH_FOR_DR_MENU
                                    )
         ) == 0
        )
       )   
    {
      //Виставлено каманда очистити дискретного реєстратор

      //Виставляємо команду запису цієї структури у EEPROM
      _SET_BIT(control_spi1_taskes, TASK_START_WRITE_INFO_REJESTRATOR_DR_EEPROM_BIT);

      //Очищаємо структуру інформації по дискретному реєстраторі
      info_rejestrator_dr.next_address = MIN_ADDRESS_DR_AREA;
      info_rejestrator_dr.saving_execution = 0;
      info_rejestrator_dr.number_records = 0;

      //Помічаємо, що номер запису не вибраний
      number_record_of_dr_for_menu  = 0xffff;
      number_record_of_dr_for_USB   = 0xffff;
      number_record_of_dr_for_RS485 = 0xffff;

      //Знімаємо команду очистки дискретного реєстратора
      clean_rejestrators &= (unsigned int)(~CLEAN_DR);
    }
    /***********************************************************/

    /***********************************************************/
    //Опрцювання логічних тайменрів і дискретних входів тільки коли настройки успішно прочитані
    /***********************************************************/
    clocking_global_timers();
    /***********************************************************/
    
    /***********************************************************/
    //Опрцювання функцій захистів
    /***********************************************************/
    //Діагностика вузлів, яку треба проводити кожен раз перед початком опрацьовуванням логіки пристрою
    uint32_t TIM_PRT_read_tick = TIM2->CNT;

    uint64_t TIM_PRT_delta_write_read;
    if (TIM_PRT_read_tick < TIM_PRT_write_tick)
      TIM_PRT_delta_write_read = TIM_PRT_read_tick + 0x100000000 - TIM_PRT_write_tick;
    else TIM_PRT_delta_write_read = TIM_PRT_read_tick - TIM_PRT_write_tick;
    if (TIM_PRT_delta_write_read > (TIM2_MIN_PERIOD_WRITE_READ + 1))
    {
      unsigned int control_state_outputs = ((~((unsigned int)(_DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD31_DD34_DD35_DD37)))) & 0xffff);

      static uint32_t error_rele[NUMBER_OUTPUTS];
      if (control_state_outputs != state_outputs_raw) 
      {
        for (unsigned int index = 0; index < NUMBER_OUTPUTS; index++)
        {
          uint32_t maska = 1 << index;
        
          if ((control_state_outputs & maska) != (state_outputs_raw & maska))
          {
            if (error_rele[index] < 3) error_rele[index]++;
            if (error_rele[index] >= 3 ) _SET_BIT(set_diagnostyka, (ERROR_DIGITAL_OUTPUT_1_BIT + index));
          }
          else error_rele[index] = 0;
        }
      }
      else
      {
        for (unsigned int index = 0; index < NUMBER_OUTPUTS; index++) error_rele[index] = 0;
      }
    }
    
    //Діагностика необхідно-приєднаних плат
    {
      uint32_t board_register_tmp = _DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD39_DD40_DD47);
      uint32_t board_register_diff = board_register_tmp ^ board_register;
      board_register = board_register_tmp;

      if ((board_register_tmp & 0x01) !=  0x1) _SET_BIT(set_diagnostyka, ERROR_BA_1_FIX);
      else if (board_register_diff & 0x01)
      {
        _SET_BIT(clear_diagnostyka, ERROR_BA_1_FIX);
        _DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD39_DD40_DD47) = 0x1;
        if ((_DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD39_DD40_DD47) >> 8) != 0x11)  _SET_BIT(set_diagnostyka, ERROR_BA_1_CTLR);
        _DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD39_DD40_DD47) = 0x0;
      }
      
      if ((board_register_tmp & 0x02) !=  0x2) _SET_BIT(set_diagnostyka, ERROR_BDVV5_1_FIX);
      else if (board_register_diff & 0x02)
      {
        _SET_BIT(clear_diagnostyka, ERROR_BDVV5_1_FIX);
        _DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD39_DD40_DD47) = 0x2;
        if ((_DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD33_DD36) & 0xff) != 0x25)  _SET_BIT(set_diagnostyka, ERROR_BDVV5_1_CTLR);
        _DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD39_DD40_DD47) = 0x0;
      }

#if (                                   \
     (MODYFIKACIA_VERSII_PZ == 0) ||    \
     (MODYFIKACIA_VERSII_PZ == 1) ||    \
     (MODYFIKACIA_VERSII_PZ == 3)       \
    )
      if ((board_register_tmp & 0x04) !=  0x4) _SET_BIT(set_diagnostyka, ERROR_BDVV5_2_FIX);
      else if (board_register_diff & 0x04)
      {
        _SET_BIT(clear_diagnostyka, ERROR_BDVV5_2_FIX);
        _DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD39_DD40_DD47) = 0x4;
        if ((_DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD33_DD36) >> 8) != 0x37)  _SET_BIT(set_diagnostyka, ERROR_BDVV5_2_CTLR);
        _DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD39_DD40_DD47) = 0x0;
      }
#endif

#if (                                   \
     (MODYFIKACIA_VERSII_PZ == 0) ||    \
     (MODYFIKACIA_VERSII_PZ == 3)       \
    )
    if ((board_register_tmp & 0x010) != 0x10) 
#if (MODYFIKACIA_VERSII_PZ == 0)
      _SET_BIT(set_diagnostyka, ERROR_BDV_DZ_FIX);
#else
      _SET_BIT(set_diagnostyka, ERROR_BDZ_FIX);
#endif
      else if (board_register_diff & 0x10)
      {
#if (MODYFIKACIA_VERSII_PZ == 0)
        _SET_BIT(clear_diagnostyka, ERROR_BDV_DZ_FIX);
#else
        _SET_BIT(clear_diagnostyka, ERROR_BDZ_FIX);
#endif

      _DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD39_DD40_DD47) = 0x10;

#if (MODYFIKACIA_VERSII_PZ == 0)
        if ((_DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD26_DD29) >> 8) != 0x14)  _SET_BIT(set_diagnostyka, ERROR_BDV_DZ_CTLR);
#else
        if ((_DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD26_DD29) >> 8) != 0x18)  _SET_BIT(set_diagnostyka, ERROR_BDZ_CTLR);
#endif

        _DEVICE_REGISTER_V2(Bank1_SRAM2_ADDR, OFFSET_DD39_DD40_DD47) = 0x0;
      }
#endif
    }
    
    //Перевіряємо достовірність значень для аналогового реєстратора
//    //Перевіряємо достовірність значень для аналогового реєстратора
//    if ((number_word_digital_part_ar*8*sizeof(short int)) < NUMBER_TOTAL_SIGNAL_FOR_RANG)
//    {
//      //Теоретично ця помилка ніколи не малаб реєструватися
//      /*Якщо виникла така ситуація то треба зациклити ропаграму, щоб вона пішла на перезапуск - 
//      бо відбулася недопустима незрозуміла помилка у розраховуваних параметрах аналогового реєстратора.
//      Не зрозумілу чого вона виникла, коли і де, коректність роботи пригоамного забезпечення під питанням!*/
//      total_error_sw_fixed(5);
//    }

    //Функції захистів
    main_protection();
    /***********************************************************/

    /***********************************************************/
    //Перевірка на необхідність зроботи резервні копії даних для самоконтролю
    /***********************************************************/
    //Триґерна інформація
    if (periodical_tasks_TEST_TRG_FUNC != 0)
    {
      //Стоїть у черзі активна задача зроботи резервні копії даних
      if ((state_spi1_task & STATE_TRG_FUNC_EEPROM_GOOD) != 0)
      {
        //Робимо копію тільки тоді, коли триґерна інформація успішно зчитана і сформована контрольна сума
        if (
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_WRITE_TRG_FUNC_EEPROM_BIT) == 0) &&
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_TRG_FUNC_EEPROM_BIT    ) == 0) &&
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_TRG_FUNC_EEPROM_BIT ) == 0) &&
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_TRG_FUNC_EEPROM_BIT    ) == 0)
           ) 
        {
          //На даний моммент не іде читання-запис триґерної інформації, тому можна здійснити копіювання
          fix_active_buttons_ctrl = fix_active_buttons;
          for (unsigned int i = 0; i < N_BIG; i++) trigger_active_functions_ctrl[i] = trigger_active_functions[i];
          crc_trg_func_ctrl = crc_trg_func;

          //Скидаємо активну задачу формування резервної копії 
          periodical_tasks_TEST_TRG_FUNC = false;
          //Виставляємо активну задачу контролю достовірності по резервній копії 
          periodical_tasks_TEST_TRG_FUNC_LOCK = true;
        }
      }
      else
      {
        //Скидаємо активну задачу формування резервної копії 
        periodical_tasks_TEST_TRG_FUNC = false;
      }
    }

    //Аналоговий реєстратор
    if (periodical_tasks_TEST_INFO_REJESTRATOR_AR != 0)
    {
      //Стоїть у черзі активна задача зроботи резервні копії даних
      if ((state_spi1_task & STATE_INFO_REJESTRATOR_AR_EEPROM_GOOD) != 0)
      {
        //Робимо копію тільки тоді, коли структура інформації реєстратора успішно зчитана і сформована контрольна сума
        if (
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_WRITE_INFO_REJESTRATOR_AR_EEPROM_BIT) == 0) &&
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_INFO_REJESTRATOR_AR_EEPROM_BIT    ) == 0) &&
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_INFO_REJESTRATOR_AR_EEPROM_BIT ) == 0) &&
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_INFO_REJESTRATOR_AR_EEPROM_BIT    ) == 0)
           ) 
        {
          //На даний моммент не іде читання-запис структури інформації реєстратора, тому можна здійснити копіювання
          info_rejestrator_ar_ctrl = info_rejestrator_ar;
          crc_info_rejestrator_ar_ctrl = crc_info_rejestrator_ar;

          //Скидаємо активну задачу формування резервної копії 
          periodical_tasks_TEST_INFO_REJESTRATOR_AR = false;
          //Виставляємо активну задачу контролю достовірності по резервній копії 
          periodical_tasks_TEST_INFO_REJESTRATOR_AR_LOCK = true;
        }
      }
      else
      {
        //Скидаємо активну задачу формування резервної копії 
        periodical_tasks_TEST_INFO_REJESTRATOR_AR = false;
      }
    }

    //Дискретний реєстратор
    if (periodical_tasks_TEST_INFO_REJESTRATOR_DR != 0)
    {
      //Стоїть у черзі активна задача зроботи резервні копії даних
      if ((state_spi1_task & STATE_INFO_REJESTRATOR_DR_EEPROM_GOOD) != 0)
      {
        //Робимо копію тільки тоді, коли структура інформації реєстратора успішно зчитана і сформована контрольна сума
        if (
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_WRITE_INFO_REJESTRATOR_DR_EEPROM_BIT) == 0) &&
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_INFO_REJESTRATOR_DR_EEPROM_BIT    ) == 0) &&
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_INFO_REJESTRATOR_DR_EEPROM_BIT ) == 0) &&
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_INFO_REJESTRATOR_DR_EEPROM_BIT    ) == 0)
           ) 
        {
          //На даний моммент не іде читання-запис структури інформації реєстратора, тому можна здійснити копіювання
          info_rejestrator_dr_ctrl = info_rejestrator_dr;
          crc_info_rejestrator_dr_ctrl = crc_info_rejestrator_dr;

          //Скидаємо активну задачу формування резервної копії 
          periodical_tasks_TEST_INFO_REJESTRATOR_DR = false;
          //Виставляємо активну задачу контролю достовірності по резервній копії 
          periodical_tasks_TEST_INFO_REJESTRATOR_DR_LOCK = true;
        }
      }
      else
      {
        //Скидаємо активну задачу формування резервної копії 
        periodical_tasks_TEST_INFO_REJESTRATOR_DR = false;
      }
    }
    /***********************************************************/

    //Лічильник ресурсу
    if (periodical_tasks_TEST_RESURS != 0)
    {
      //Стоїть у черзі активна задача зроботи резервні копії даних
      if ((state_spi1_task & STATE_RESURS_EEPROM_GOOD) != 0)
      {
        //Робимо копію тільки тоді, коли інформаціz успішно зчитана і сформована контрольна сума
        if (
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_WRITE_RESURS_EEPROM_BIT) == 0) &&
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_RESURS_EEPROM_BIT    ) == 0) &&
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_RESURS_EEPROM_BIT ) == 0) &&
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_RESURS_EEPROM_BIT    ) == 0)
           ) 
        {
          //На даний моммент не іде читання-запис ресурсу вимикача, тому можна здійснити копіювання
          resurs_vymykacha_ctrl = resurs_vymykacha;          
          resurs_vidkljuchennja_ctrl = resurs_vidkljuchennja;
          crc_resurs_ctrl = crc_resurs;

          //Скидаємо активну задачу формування резервної копії 
          periodical_tasks_TEST_RESURS = false;
          //Виставляємо активну задачу контролю достовірності по резервній копії 
          periodical_tasks_TEST_RESURS_LOCK = true;
        }
      }
      else
      {
        //Скидаємо активну задачу формування резервної копії 
        periodical_tasks_TEST_RESURS = false;
      }
    }

    /***********************************************************/
    //Встановлюємо "значення лічильника для наступного переривання"
    /***********************************************************/
    uint32_t capture_new;
    unsigned int delta;
    TIM2->CCR1 = (capture_new = (current_tick + (delta = TIM2_CCR1_VAL)));
    
    unsigned int repeat;
    unsigned int previous_tick;
    do
    {
      repeat = 0;
      current_tick = TIM2->CNT;

      uint64_t delta_time = 0;
      if (capture_new < current_tick)
        delta_time = capture_new + 0x100000000 - current_tick;
      else delta_time = capture_new - current_tick;

      if ((delta_time > delta) || (delta_time == 0))
      {
        if (TIM_GetITStatus(TIM2, TIM_IT_CC1) == RESET)
        {
          if (delta < TIM2_CCR1_VAL)
          {
            uint64_t delta_tick;
            if (current_tick < previous_tick)
              delta_tick = current_tick + 0x100000000 - previous_tick;
            else delta_tick = current_tick - previous_tick;
              
            delta = delta_tick + 1;
          }
          else if (delta == TIM2_CCR1_VAL)
            delta = 1; /*Намагаємося, щоб нове переивання запустилося як омога скоріше*/
          else
          {
            //Теоретично цього ніколи не мало б бути
            total_error_sw_fixed(83);
          }
          TIM2->CCR1 = (capture_new = (TIM2->CNT +  delta));
          previous_tick = current_tick;
          repeat = 0xff;
        }
      }
    }
    while (repeat != 0);
    /***********************************************************/
    
    /***********************************************************/
    //Виставляємо повідомлення про те, система захисів праціює
    /***********************************************************/
    control_word_of_watchdog |= WATCHDOG_PROTECTION;
    /***********************************************************/
    /***********************************************************************************************/
  }
  else
  {
    total_error_sw_fixed(23);
  }
  
#ifdef SYSTEM_VIEWER_ENABLE
  SEGGER_SYSVIEW_RecordExitISR();
#endif
}
/*****************************************************/

/*****************************************************/
//Вибір групи уставок
/*****************************************************/
void setpoints_selecting(unsigned int *p_active_functions, unsigned int act_inp_gr_ustavok) {
  unsigned int grupa_ustavok = 0;
  act_inp_gr_ustavok &= 0xf;
  if (current_settings_prt.grupa_ustavok < SETPOINT_GRUPA_USTAVOK_MIN ||
      current_settings_prt.grupa_ustavok > SETPOINT_GRUPA_USTAVOK_MAX) {
    //Неопределенная ошибка
    while (1);
  } else {
    grupa_ustavok = 1 << (current_settings_prt.grupa_ustavok - 1);
  }
  
//!@  if (_CHECK_SET_BIT(p_active_functions, @RANG_INVERS_DV_GRUPA_USTAVOK)) _SET_STATE(act_inp_gr_ustavok, 4);
  if (_CHECK_SET_BIT(p_active_functions, RNG_BIG_INVERS_DV_GRUPA_USTAVOK)) _SET_STATE(act_inp_gr_ustavok, 4);
  
  _AND2(grupa_ustavok, 0, act_inp_gr_ustavok, 4, grupa_ustavok, 4);
  _AND2(grupa_ustavok, 1, act_inp_gr_ustavok, 4, grupa_ustavok, 5);
  _AND2(grupa_ustavok, 2, act_inp_gr_ustavok, 4, grupa_ustavok, 6);
  _AND2(grupa_ustavok, 3, act_inp_gr_ustavok, 4, grupa_ustavok, 7);
  
  unsigned int tmp = gr_ustavok_tmp;
  do {
    _AND4(act_inp_gr_ustavok, 0, gr_ustavok_tmp, 1, gr_ustavok_tmp, 2, gr_ustavok_tmp, 3, act_inp_gr_ustavok, 5);
    _INVERTOR(act_inp_gr_ustavok, 5, tmp, 0);
    
    _AND4(tmp, 0, act_inp_gr_ustavok, 1, tmp, 2, tmp, 3, act_inp_gr_ustavok, 6);
    _INVERTOR(act_inp_gr_ustavok, 6, tmp, 1);
    
    _AND4(tmp, 0, tmp, 1, act_inp_gr_ustavok, 2, tmp, 3, act_inp_gr_ustavok, 7);
    _INVERTOR(act_inp_gr_ustavok, 7, tmp, 2);
    
    _AND4(tmp, 0, tmp, 1, tmp, 2, act_inp_gr_ustavok, 3, act_inp_gr_ustavok, 8);
    _INVERTOR(act_inp_gr_ustavok, 8, tmp, 3);
    if (tmp == gr_ustavok_tmp) {
      break;
    }
    gr_ustavok_tmp = tmp;
  } while (1);
  
  _OR2(grupa_ustavok, 4, act_inp_gr_ustavok, 5, grupa_ustavok, 8);
  _OR2(grupa_ustavok, 5, act_inp_gr_ustavok, 6, grupa_ustavok, 9);
  _OR2(grupa_ustavok, 6, act_inp_gr_ustavok, 7, grupa_ustavok, 10);
  _OR2(grupa_ustavok, 7, act_inp_gr_ustavok, 8, grupa_ustavok, 11);
  
//!  if (_GET_OUTPUT_STATE(grupa_ustavok, 8)) 
//!    _SET_BIT(p_active_functions, @RANG_1_GRUPA_USTAVOK);
//!  else
//!    _CLEAR_BIT(p_active_functions, @RANG_1_GRUPA_USTAVOK);
//!
//!  if (_GET_OUTPUT_STATE(grupa_ustavok, 9))
//!    _SET_BIT(p_active_functions, @RANG_2_GRUPA_USTAVOK);
//!  else
//!    _CLEAR_BIT(p_active_functions, @RANG_2_GRUPA_USTAVOK);
//!
//!  if (_GET_OUTPUT_STATE(grupa_ustavok, 10))
//!      _SET_BIT(p_active_functions, @RANG_3_GRUPA_USTAVOK);
//!  else
//!    _CLEAR_BIT(p_active_functions, @RANG_3_GRUPA_USTAVOK);
//!
//!  if (_GET_OUTPUT_STATE(grupa_ustavok, 11))
//!      _SET_BIT(p_active_functions, @RANG_4_GRUPA_USTAVOK);
//!  else
//!    _CLEAR_BIT(p_active_functions, @RANG_4_GRUPA_USTAVOK);
  
  if (_GET_OUTPUT_STATE(grupa_ustavok, 8)) 
    _SET_BIT(p_active_functions, RNG_BIG_1_GRUPA_USTAVOK);
  else
    _CLEAR_BIT(p_active_functions, RNG_BIG_1_GRUPA_USTAVOK);

  if (_GET_OUTPUT_STATE(grupa_ustavok, 9))
    _SET_BIT(p_active_functions, RNG_BIG_2_GRUPA_USTAVOK);
  else
    _CLEAR_BIT(p_active_functions, RNG_BIG_2_GRUPA_USTAVOK);

  if (_GET_OUTPUT_STATE(grupa_ustavok, 10))
      _SET_BIT(p_active_functions, RNG_BIG_3_GRUPA_USTAVOK);
  else
    _CLEAR_BIT(p_active_functions, RNG_BIG_3_GRUPA_USTAVOK);

  if (_GET_OUTPUT_STATE(grupa_ustavok, 11))
      _SET_BIT(p_active_functions, RNG_BIG_4_GRUPA_USTAVOK);
  else
    _CLEAR_BIT(p_active_functions, RNG_BIG_4_GRUPA_USTAVOK);
}
/*****************************************************/
#include "mtzo.c"
#include "dzo.c"
/*****************************************************/
