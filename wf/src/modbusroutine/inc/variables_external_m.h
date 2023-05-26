#ifndef __GLOBAL_EXTERNAL_M_H
#define __GLOBAL_EXTERNAL_M_H

#include "constants.h"
#include "fatfs.h"
//#include "libraries.h"

#include "header_m.h"

extern  COMPONENT2021_OBJ config_array2021func[];
extern  int isActiveActualData2021;//action �� ������
extern  COMPONENT_OBJ config_array[];
extern  short tempReadArray[];
extern  short tempWriteArray[];
extern  int   indexTW;//������ ������ ������
extern  int   pointInterface;//����� ���������� 0-USB 1-RS485

extern  unsigned int rds_functions[];//��� ��� ����������
extern  int recordNumber_old;
//extern  time_t time_dat_rds;
extern  int32_t time_ms_rds;
extern  unsigned long ulWorkNumber_rds;


//��� ��������� ������ ���������� ������-������� ���������
#define SOURCEMARKER_DTR  10
//��� ��������� ������ ���������� ������ ��
#define SOURCEMARKER_MFT  20

//�������������� ��� ������� ����������
//#define TESTZBIRKA_VERSII_PZ



#endif
