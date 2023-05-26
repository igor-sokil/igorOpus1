#ifndef __GLOBAL_VARIABLES_M_H
#define __GLOBAL_VARIABLES_M_H

#include "header_m.h"

SRAM1 COMPONENT2021_OBJ config_array2021func[TOTAL_COMPONENT2021];

SRAM1 int isActiveActualData2021;//action �� ������
SRAM1 COMPONENT_OBJ config_array[TOTAL_COMPONENT];
SRAM1 short tempReadArray[130];
SRAM1 short tempWriteArray[MAXIMUMTW];
SRAM1 int   indexTW;//������ ������ ������
SRAM1 int   pointInterface;//����� ���������� 0-USB 1-RS485

SRAM1 unsigned int rds_functions[N_BIG+1];//��� ��� ����������
SRAM1 int recordNumber_old;
SRAM1 time_t time_dat_rds[2];
SRAM1 int32_t time_ms_rds[2];
SRAM1 unsigned long ulWorkNumber_rds;

#endif
