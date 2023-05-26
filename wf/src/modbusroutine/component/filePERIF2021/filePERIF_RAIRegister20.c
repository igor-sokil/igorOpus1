
#include "header.h"

#define MDR_OFFSET_LABEL_TIME_LSW              1
#define MDR_OFFSET_LABEL_TIME_MSW              2
#define MDR_OFFSET_LABEL_PROTECT               3

#define MDR_OFFSET_FREQUENCY_F                 16
#define MDR_OFFSET_MEASUREMENT_UAB_TN1         17
#define MDR_OFFSET_MEASUREMENT_UBC_TN1         18
#define MDR_OFFSET_MEASUREMENT_UCA_TN1         19
#define MDR_OFFSET_MEASUREMENT_3U0_TN1         20

#define MDR_OFFSET_MEASUREMENT_U1_TN1          34
#define MDR_OFFSET_MEASUREMENT_U2_TN1          35

#define MBLOCK_PROTECTION_MAX_CURRENT_PHASE_O  1
#define MBLOCK_PROTECTION_MAX_CURRENT_PHASE_R  2
#define MBLOCK_PROTECTION_MIN_VOLTAGE          3
#define MBLOCK_PROTECTION_MAX_VOLTAGE          4
#define MBLOCK_PROTECTION_MIN_R_O              5
#define MBLOCK_PROTECTION_MIN_R_R              6
#define MBLOCK_PROTECTION_MIN_FREQUENCY_ACHR   7
#define MBLOCK_PROTECTION_FREQUENCY_CHAPV      8

int getFileRAIRegister20(int recordNumber, int registerNumber, int recordLen);

////-GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET-

int getFileRAIRegister20(int recordNumber, int registerNumber, int recordLen)
{
  if((recordNumber == 0)  || (recordNumber > 10)) return MARKER_ERRORPERIMETR;
  if(recordLen > 35) return MARKER_ERRORPERIMETR;
  if(registerNumber == 0) return 0;

  if (
    //Не подано попередньокоманди вичитування відповідного запису дискретного реєстратора
    //pointInterface=0 метка интерфейса 0-USB 1-RS485 2-LAN
    ((pointInterface == USB_RECUEST  ) && (number_record_of_dr_for_USB == 0xffff)) 
    ||
    ((pointInterface == RS485_RECUEST) && (number_record_of_dr_for_RS485 == 0xffff))
  ) return MARKER_ERRORPERIMETR;
  if (
    //Зараз іде зчитування для інтерфейсу запису дискретного реєстратора, або очистка його, тому ця операція є тимчасово недоступною
    ((clean_rejestrators & CLEAN_DR) != 0) ||
    (
      ((pointInterface == USB_RECUEST  ) && ((control_tasks_dataflash & TASK_MAMORY_READ_DATAFLASH_FOR_DR_USB  ) != 0)) 
      ||
      ((pointInterface == RS485_RECUEST) && ((control_tasks_dataflash & TASK_MAMORY_READ_DATAFLASH_FOR_DR_RS485) != 0))
    )
  ) return MARKER_ERRORPERIMETR; //Не подано попередньокоманди вичитування відповідного запису дискретного реєстратора

  //Можна читати дані

  unsigned char *point_to_buffer = NULL;
  int number_block = recordNumber - 1;
  int offset = registerNumber;

  if (pointInterface == USB_RECUEST) point_to_buffer = buffer_for_USB_read_record_dr;
  else if (pointInterface == RS485_RECUEST) point_to_buffer = buffer_for_RS485_read_record_dr;
  else
  {
    //Теоретично цього ніколи не мало б бути
    total_error_sw_fixed();
  }

  if (!(
        number_block < (
          (*(point_to_buffer + FIRST_INDEX_NUMBER_MAX_PHASE_O_DR  )) +
          (*(point_to_buffer + FIRST_INDEX_NUMBER_MAX_PHASE_R_DR  )) +
          (*(point_to_buffer + FIRST_INDEX_NUMBER_MIN_U_DR      )) +
          (*(point_to_buffer + FIRST_INDEX_NUMBER_MAX_U_DR      )) +
          (*(point_to_buffer + FIRST_INDEX_NUMBER_MIN_R_O_DR    )) +
          (*(point_to_buffer + FIRST_INDEX_NUMBER_MIN_R_R_DR    )) +
          (*(point_to_buffer + FIRST_INDEX_NUMBER_MIN_F_ACHR_DR )) +
          (*(point_to_buffer + FIRST_INDEX_NUMBER_F_CHAPV_DR    )) 
        )
      )) return 0;//Блок пустой
  unsigned int value, index;
//  unsigned int control_extra_settings_1_tmp = *((unsigned int *)(point_to_buffer + FIRST_INDEX_EXTRA_SETTINGS_DR));

  switch (offset)
  {
  case MDR_OFFSET_FREQUENCY_F:
  {
    index = FIRST_INDEX_FIRST_BLOCK_DR + (number_block*SIZE_ARRAY_FIX_MAX_MEASUREMENTS + IDM_F)*sizeof(unsigned int);
    value = *((unsigned int *)(point_to_buffer + index));

    return (value) &0xFFFF;
  }
  case MDR_OFFSET_MEASUREMENT_UAB_TN1:
  {
   // index = FIRST_INDEX_FIRST_BLOCK_DR + (number_block*SIZE_ARRAY_FIX_MAX_MEASUREMENTS + IDM_UAB_TN1)*sizeof(unsigned int);
    value = *((unsigned int *)(point_to_buffer + index));

    return (value >> 3) &0xFFFF;
  }
  case MDR_OFFSET_MEASUREMENT_UBC_TN1:
  {
   // index = FIRST_INDEX_FIRST_BLOCK_DR + (number_block*SIZE_ARRAY_FIX_MAX_MEASUREMENTS + IDM_UBC_TN1)*sizeof(unsigned int);
    value = *((unsigned int *)(point_to_buffer + index));

    return (value >> 3) &0xFFFF;
  }
  case MDR_OFFSET_MEASUREMENT_UCA_TN1:
  {
  //  index = FIRST_INDEX_FIRST_BLOCK_DR + (number_block*SIZE_ARRAY_FIX_MAX_MEASUREMENTS + IDM_UCA_TN1)*sizeof(unsigned int);
    value = *((unsigned int *)(point_to_buffer + index));

    return (value >> 3) &0xFFFF;
  }
  case MDR_OFFSET_MEASUREMENT_3U0_TN1:
  {
   // index = FIRST_INDEX_FIRST_BLOCK_DR + (number_block*SIZE_ARRAY_FIX_MAX_MEASUREMENTS + IDM_3U0_TN1)*sizeof(unsigned int);
    value = *((unsigned int *)(point_to_buffer + index));

    return (value >> 3) &0xFFFF;
  }
  case MDR_OFFSET_MEASUREMENT_U1_TN1:
  {
    //  index = FIRST_INDEX_FIRST_BLOCK_DR + (number_block*SIZE_ARRAY_FIX_MAX_MEASUREMENTS + IDM_U1_TN1)*sizeof(unsigned int);
      value = *((unsigned int *)(point_to_buffer + index));

    return (value >> 3) &0xFFFF;
  }
  case MDR_OFFSET_MEASUREMENT_U2_TN1:
  {
   // index = FIRST_INDEX_FIRST_BLOCK_DR + (number_block*SIZE_ARRAY_FIX_MAX_MEASUREMENTS + IDM_U2_TN1)*sizeof(unsigned int);
    value = *((unsigned int *)(point_to_buffer + index));

    return (value >> 3) &0xFFFF;
  }
  case MDR_OFFSET_LABEL_TIME_LSW:
  case MDR_OFFSET_LABEL_TIME_MSW:
  case MDR_OFFSET_LABEL_PROTECT:
  {
    index = FIRST_INDEX_FIRST_BLOCK_DR + (number_block*SIZE_ARRAY_FIX_MAX_MEASUREMENTS + IDM_TM_STAMPE)*sizeof(unsigned int);

    if (offset == MDR_OFFSET_LABEL_TIME_LSW)
    {
      return ((*(point_to_buffer + index + 0)) | ((*(point_to_buffer + index + 1)) << 8 )) &0xFFFF;
    }
    else if (offset ==MDR_OFFSET_LABEL_TIME_MSW)
    {
      return  (*(point_to_buffer + index + 2)) &0xFF;
    }
    else
    {
      value = *(point_to_buffer + index + 3);
      switch (value)
      {
        case IDENTIFIER_BIT_ARRAY_MAX_CURRENT_PHASE_O:
          return MBLOCK_PROTECTION_MAX_CURRENT_PHASE_O;
        case IDENTIFIER_BIT_ARRAY_MAX_CURRENT_PHASE_R:
          return MBLOCK_PROTECTION_MAX_CURRENT_PHASE_R;
        case IDENTIFIER_BIT_ARRAY_MIN_VOLTAGE:
          return MBLOCK_PROTECTION_MIN_VOLTAGE;
        case IDENTIFIER_BIT_ARRAY_MAX_VOLTAGE:
          return MBLOCK_PROTECTION_MAX_VOLTAGE;
        case IDENTIFIER_BIT_ARRAY_MIN_R_O:
          return MBLOCK_PROTECTION_MIN_R_O;
        case IDENTIFIER_BIT_ARRAY_MIN_R_R:
          return MBLOCK_PROTECTION_MIN_R_R;
        case IDENTIFIER_BIT_ARRAY_MIN_FREQUENCY_ACHR:
          return MBLOCK_PROTECTION_MIN_FREQUENCY_ACHR;
        case IDENTIFIER_BIT_ARRAY_FREQUENCY_CHAPV:
          return MBLOCK_PROTECTION_FREQUENCY_CHAPV;

      default:
      {
        //Якщо немає помилок, то сюди б програма не мала заходити
        return 0;
      }

      }//switch
    }//else

    break;
  }//case

  }//switch
  return 0;
}//getFileRAIRegister20


