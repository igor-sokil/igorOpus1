
#include "header.h"

int dataRegistratorRDS(int recordNumber, int registerNumber, int recordLen);
int getFileDSREGRegister20(int recordNumber, int registerNumber, int recordLen);

////-GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET--GET-

int getFileDSREGRegister20(int recordNumber, int registerNumber, int recordLen)
{
  //������ ����������� ���������� ��������
 if(recordNumber > 9999) return MARKER_ERRORPERIMETR;
 if(registerNumber == 0) return 0;
 registerNumber--;
 recordLen--;
 return 0;//dataRegistratorRDS(recordNumber, registerNumber, recordLen);
}//getFileDSREGRegister20


