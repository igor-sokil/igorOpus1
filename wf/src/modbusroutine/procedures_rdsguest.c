#include "header.h"

int dataRegistratorRDS(int recordNumber, int registerNumber, int recordLen);
int activeFunctionRDS(int offsetActiveFunc, int recordNumber);
void loadACMDSmallActualDataBit(int cmdSwitch, int beginOffset, int endOffset);

//int openRegistratorRDS(void)
//{
//��������� ����������� ���������� ��������
//  return 0;//���� ���������
//}//openRegistratorRDS

int dataRegistratorRDS(int recordNumber, int registerNumber, int recordLen)
{
//������ ����������� ���������� ��������
      if(recordLen>47) return MARKER_ERRORPERIMETR;
      short cntRecord = 0;//GetAmountFixElem();
      if(recordNumber >= cntRecord) return MARKER_ERRORPERIMETR;

//  time_t time_dat_tmp = 0;
//  int32_t time_ms_tmp = 0;
  if(recordNumber_old != recordNumber)
  {
    long err = GetDateTimeLogElemPlWnum((unsigned int *)&time_dat_rds, recordNumber, ulWorkNumber_rds);//0xffffffff);
    if(err) return MARKER_ERRORPERIMETR;
    uint32_t* tmp;
    tmp = &((uint32_t*)&time_dat_rds)[2];
    ulWorkNumber_rds = (unsigned long)(*tmp);
  
    err = GetMsLogElemPlWnum      ((unsigned int *)&time_ms_rds , recordNumber, ulWorkNumber_rds);//0xffffffff);
    if(err) return MARKER_ERRORPERIMETR;
    tmp = &((uint32_t*)&time_ms_rds)[1];
    ulWorkNumber_rds = (unsigned long)(*tmp);
  }//if
      
  switch(registerNumber)
    {
     case 0://�����, Unix-�����
     case 1:
     case 2:
     case 3:
       {
       uint16_t* tmp[4];
       tmp[0] = &((uint16_t*)&time_dat_rds)[0];
       tmp[1] = &((uint16_t*)&time_dat_rds)[1];
       tmp[2] = &((uint16_t*)&time_dat_rds)[2];
       tmp[3] = &((uint16_t*)&time_dat_rds)[3];
       return (*(tmp[registerNumber]));
       }
     case 4:
     case 5:
       {
       uint16_t* tmp[2];
       tmp[0] = &((uint16_t*)&time_ms_rds)[0];
       tmp[1] = &((uint16_t*)&time_ms_rds)[1];
       return *(tmp[registerNumber-4]);
       }
    }//switch

  return activeFunctionRDS(registerNumber-6, recordNumber);//�������� ������� RDS
}//dataRegistratorRDS

int activeFunctionRDS(int offsetActiveFunc, int recordNumber)
{
//�������� ������� RDS
  if(offsetActiveFunc>41) return MARKER_ERRORPERIMETR;

  if(recordNumber_old != recordNumber)
  {
   long err = GetCmdPlusTimeLogElemPlWnum(rds_functions, recordNumber, ulWorkNumber_rds);//0xffffffff);
   if(err) return MARKER_ERRORPERIMETR;
   uint32_t tmp;
   tmp = rds_functions[N_BIG];
   ulWorkNumber_rds = (unsigned long)tmp;

   recordNumber_old = recordNumber;
  }//if

  int cntReg = 1;
  int beginOffset = offsetActiveFunc*16;
  int endOffset   = beginOffset +cntReg*16;

  loadACMDSmallActualDataBit(2, beginOffset, endOffset); //RDSData

  return tempReadArray[offsetActiveFunc];
}//activeFunctionRDS(int offsetActiveFunc, int recordNumber)

