#ifndef __COMPONENTDEF_H
#define __COMPONENTDEF_H

#include "CommandStatus.h"
#include "AnalogOutput.h"


typedef struct
{
  int  operativMarker[2];//����������� ������
  int  isActiveActualData;

  int (*getModbusRegister)(int);//�������� ���������� ��������
  int (*getModbusBit)(int);//�������� ���������� ����
  int (*setModbusRegister)(int, int);//�������� �������
  int (*setModbusBit)(int, int);//�������� ���

  int (*postWriteAction)(void);//action ����� ������

} COMPONENT_OBJ;

typedef struct
{
  int (*getModbusRegister20func)(int, int, int, int);//�������� ���������� ��������
  int (*setModbusRegister21func)(int, int, int, unsigned short *);//�������� �������

  int (*postWriteAction21func)(int, int, int, unsigned short *);//action ����� ������

} COMPONENT2021_OBJ;

#endif



