
#include "header.h"

//начальный регистр в карте памяти
#define BEGIN_ADR_REGISTER 1000
//конечный регистр в карте памяти
#define END_ADR_REGISTER 1295

int getAISmallModbusRegister(int);//получить содержимое регистра
int getAISmallModbusBit(int);//получить содержимое бита
int setAISmallModbusRegister(int, int);//получить содержимое регистра
int setAISmallModbusBit(int, int);//получить содержимое бита

int  postAISmallWriteAction(void);//action после записи
void loadAISmallActualData(void);

int privateAISmallGetReg2(int adrReg);

SRAM1 COMPONENT_OBJ *aismallcomponent;

/**************************************/
//компонент измерений
/**************************************/
void constructorAISmallComponent(COMPONENT_OBJ *aismallcomp)
{
  aismallcomponent = aismallcomp;

  aismallcomponent->getModbusRegister = getAISmallModbusRegister;//получить содержимое регистра
  aismallcomponent->getModbusBit      = getAISmallModbusBit;//получить содержимое бита
  aismallcomponent->setModbusRegister = setAISmallModbusRegister;//получить содержимое регистра
  aismallcomponent->setModbusBit      = setAISmallModbusBit;//получить содержимое бита

  aismallcomponent->postWriteAction = postAISmallWriteAction;//action после записи
}//constructorIUSmallComponent(COMPONENT_OBJ *iucomp)

int getAISmallModbusRegister(int adrReg)
{
  //получить содержимое регистра
  if(privateAISmallGetReg2(adrReg)==MARKER_OUTPERIMETR) return MARKER_OUTPERIMETR;

  //Копіюємо вимірювання які потрібні для відображення
  semaphore_measure_values_low1 = 1;
  for (unsigned int i = 0; i < NUMBER_ANALOG_CANALES; i++ )
  {
    measurement_low[i] = measurement_middle[i];
  }
  for (unsigned int i = 0; i < MAX_NUMBER_INDEXES_RESISTANCE; i++ ) 
  {
    int temp_value = resistance_middle[i];
    if (temp_value==UNDEF_RESISTANCE) temp_value = 0;
    if (temp_value < 0) temp_value = -temp_value;
    resistance_low[i] =temp_value;
  }
  semaphore_measure_values_low1 = 0;

  int offset = adrReg-BEGIN_ADR_REGISTER;
  
  switch (offset)
  {

  case 0://Umain
  {
#ifdef TESTZBIRKA_VERSII_PZ
    return 700;
#else
    return (measurement_low[IM_Umn] >> 2) &0xFFFF;
#endif
  }

  case 3://Ток main (Ток канала 1)
  {
#ifdef TESTZBIRKA_VERSII_PZ
    return 703;
#else
    return (measurement_low[IM_Imn]) &0xFFFF;
#endif
  }

    case 7://P
      {
#ifdef TESTZBIRKA_VERSII_PZ
        return 707;
#else
        return (P[bank_for_calc_power][0]/50) &0xFFFF;
#endif
      }
    case 8://Q
      {
#ifdef TESTZBIRKA_VERSII_PZ
        return 708;
#else
        return (Q[bank_for_calc_power][0]/50) &0xFFFF;
#endif
      }
    case 9://S
      {
#ifdef TESTZBIRKA_VERSII_PZ
        return 709;
#else
        return (S[bank_for_calc_power][0]/50) &0xFFFF;
#endif
      }
    case 10://cos f
      {
#ifdef TESTZBIRKA_VERSII_PZ
        return 710;
#else
        if (S[bank_for_calc_power][0] != 0)
          return (cos_phi_x1000[bank_for_calc_power][0]) &0xFFFF;
          return 0x0;
#endif
      }

    case 12://freq
      {
#ifdef TESTZBIRKA_VERSII_PZ
        return 712;
#else
        semaphore_measure_values_low1 = 1;
        int int_frequency = (int)(frequency_middle*100);
        semaphore_measure_values_low1 = 0;
        
        if (int_frequency > 0 /*це число означає - частота не визначена*/)
          return (int_frequency) &0xFFFF;
        else
        {
          if (int_frequency == (-1*1000))
            return (-1)&0x0000FFFF;
          else if (int_frequency == (-2*1000))
            return (-2)&0x0000FFFF;
          else if (int_frequency == (-3*1000))
            return (-3)&0x0000FFFF;
          else
            return (-4)&0x0000FFFF;
        }
#endif
      } break;

    case 13://Ea+
    case 14://Ea+
    case 15://Ea-
    case 16://Ea-
    case 17://Eq1
    case 18://Eq1
    case 19://Eq2
    case 20://Eq2
    case 21://Eq3
    case 22://Eq3
    case 23://Eq4
    case 24://Eq4
      {
#ifdef TESTZBIRKA_VERSII_PZ
        return 713+(offset-13);
#else
        unsigned int enrg = (unsigned int)(energy[0][(offset-13) >> 1]*1000.0);
        if((offset-13)&1)
          //Передаємо старше слово
        return (enrg>> 16)& 0xffff;
          //Передаємо молодше слово
        return enrg& 0xffff;
#endif
      } break;

    case 45://R
#ifdef TESTZBIRKA_VERSII_PZ
        return 745;
#else
        return (resistance_low[R_mn] /100) &0xFFFF;
#endif
    case 46://X
#ifdef TESTZBIRKA_VERSII_PZ
        return 746;
#else
        return (resistance_low[X_mn] /100) &0xFFFF;
#endif
    case 47://Z
#ifdef TESTZBIRKA_VERSII_PZ
        return 747;
#else
        return (resistance_low[Z_mn] /100) &0xFFFF;
#endif

    case 71://OFFSET_ANGLE_IMN
      {
#ifdef TESTZBIRKA_VERSII_PZ
        return 771;
#else
        return ((unsigned int)phi_angle[bank_for_calc_phi_angle][FULL_ORT_Imn]) &0xFFFF;
#endif
      }

  case 100://Ubp
  {
#ifdef TESTZBIRKA_VERSII_PZ
    return 800;
#else
    return (measurement_low[IM_Ubp] >> 2) &0xFFFF;
#endif
  }

  case 103://Ток bp (Ток канала 2)
  {
#ifdef TESTZBIRKA_VERSII_PZ
    return 803;
#else
    return (measurement_low[IM_Ibp]) &0xFFFF;
#endif
  }

    case 107://P
      {
#ifdef TESTZBIRKA_VERSII_PZ
        return 807;
#else
        return (P[bank_for_calc_power][1]/50) &0xFFFF;
#endif
      }
    case 108://Q
      {
#ifdef TESTZBIRKA_VERSII_PZ
        return 808;
#else
        return (Q[bank_for_calc_power][1]/50) &0xFFFF;
#endif
      }
    case 109://S
      {
#ifdef TESTZBIRKA_VERSII_PZ
        return 809;
#else
        return (S[bank_for_calc_power][1]/50) &0xFFFF;
#endif
      }
    case 110://cos f
      {
#ifdef TESTZBIRKA_VERSII_PZ
        return 810;
#else
        if (S[bank_for_calc_power][1] != 0)
          return (cos_phi_x1000[bank_for_calc_power][1]) &0xFFFF;
          return 0x0;
#endif
      }

    case 145://R
#ifdef TESTZBIRKA_VERSII_PZ
        return 845;
#else
        return (resistance_low[R_bp] /100) &0xFFFF;
#endif
    case 146://X
#ifdef TESTZBIRKA_VERSII_PZ
        return 846;
#else
        return (resistance_low[X_bp] /100) &0xFFFF;
#endif
    case 147://Z
#ifdef TESTZBIRKA_VERSII_PZ
        return 847;
#else
        return (resistance_low[Z_bp] /100) &0xFFFF;
#endif

    case 174://OFFSET_ANGLE_IBP
      {
#ifdef TESTZBIRKA_VERSII_PZ
        return 874;
#else
        return ((unsigned int)phi_angle[bank_for_calc_phi_angle][FULL_ORT_Ibp]) &0xFFFF;
#endif
      }

    case 192://
      {
#ifdef TESTZBIRKA_VERSII_PZ
        return 892;
#else
        return resurs_vidkljuchennja & 0xffff;
#endif
      }
    case 193://
      {
#ifdef TESTZBIRKA_VERSII_PZ
        return 893;
#else
        return (resurs_vidkljuchennja >> 16) & 0xffff;
#endif
      }
    case 194://
      {
#ifdef TESTZBIRKA_VERSII_PZ
        return 894;
#else
        return resurs_vymykacha & 0xffff;
#endif
      }
    case 195://
      {
#ifdef TESTZBIRKA_VERSII_PZ
        return 895;
#else
        return (resurs_vymykacha >> 16) & 0xffff;
#endif
      }


  }//switch
  return 0;
}//getAISmallModbusRegister(int offset)

int getAISmallModbusBit(int x) {
  //получить содержимое bit
  UNUSED(x);
  return MARKER_OUTPERIMETR;
}//getIUModbusBit(int )
int setAISmallModbusRegister(int x, int y) {
  UNUSED(x);
  UNUSED(y);
  //записать содержимое регистра
  return MARKER_OUTPERIMETR;
}//setIUModbusRegister(int, int)
int setAISmallModbusBit(int x, int y) {
  UNUSED(x);
  UNUSED(y);
  //записать содержимое bit
  return MARKER_OUTPERIMETR;
}//setIUModbusBit(int, int )

int postAISmallWriteAction(void) {
//action после записи
 return 0;
}//

int privateAISmallGetReg2(int adrReg)
{
  //проверить внешний периметр
 return controlPerimetr(adrReg, BEGIN_ADR_REGISTER, END_ADR_REGISTER);
}//privateGetReg2(int adrReg)

