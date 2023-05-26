
#include "header.h"

int inputPacketParser(void);
void inputPacketParserUSB(void);
void inputPacketParserRS485(void);
unsigned short int  AddCRC(unsigned char inpbyte, unsigned short int oldCRC);
int Error_modbus_m(unsigned int address, unsigned int function, unsigned int error, unsigned char *output_data);

int outputFunc20PacketEncoder(int *fileNumber, int *recordNumber, int *recordLen, int cntitem);
int superWriter21func(int fileNumber, int recordNumber, int recordLen, unsigned short *dataPacket);
int superReader20func(int fileNumber, int recordNumber, int registerNumber, int recordLen);
int outputFunc16PacketEncoder(int adrUnit, int adrReg, int cntReg);
int outputFunc15PacketEncoder(int adrUnit, int adrBit, int cntBit);
int outputFunc6PacketEncoder(int adrUnit, int adrReg, int dataReg);
int outputFunc5PacketEncoder(int adrUnit, int adrBit, int dataBit);
int outputFunc3PacketEncoder(int adrUnit, int adrReg, int cntReg);
int outputFunc1PacketEncoder(int adrUnit, int adrReg, int cntReg);
int passwordImunitetReg(int adrReg);
int passwordImunitetBit(int adrBit);

SRAM1 unsigned char  *outputPacket;
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
SRAM1 unsigned char  outputPacket_TCP[300];
#endif
SRAM1 unsigned char  outputPacket_USB[300];
SRAM1 unsigned char  outputPacket_RS485[300];

SRAM1 int sizeOutputPacket;
SRAM1 unsigned char *inputPacket;
SRAM1 int *received_count;
SRAM1 int globalcntBit;//�-�� ���
SRAM1 int globalcntReg;//�-�� ���������
SRAM1 int globalbeginAdrReg;//����� ��� ��������
SRAM1 int globalbeginAdrBit;//����� ��� ���
SRAM1 int upravlSetting;//���� Setting
SRAM1 int upravlSchematic;//���� Shematic

/**************************************/
//������ �������� ������
/**************************************/
int inputPacketParser(void)
{
  upravlSetting=0;//���� Setting
  upravlSchematic=0;//���� Shematic
  unsigned short CRC_sum = 0xffff;

  int adrUnit = inputPacket[0];
  int numFunc = inputPacket[1];//����� �-���

  sizeOutputPacket = 0;
  indexTW = 0;//������ ������ ������

  outputPacket[0] = (unsigned char)adrUnit;
  outputPacket[1] = (unsigned char)numFunc;
  switch(numFunc)
  {
  case 2:
  case 1:
  {
    globalbeginAdrBit  = (unsigned int)inputPacket[3] +256*(unsigned int)inputPacket[2];
    globalcntBit      = (unsigned int)inputPacket[5] +256*(unsigned int)inputPacket[4];
    if(globalcntBit>1000) return 0;//������� ������� �����
    if((*received_count)!=8) return 0;//�������� �-��

    sizeOutputPacket = outputFunc1PacketEncoder(adrUnit, globalbeginAdrBit, globalcntBit);
  }
  break;
  case 4:
  case 3:
  {
    globalbeginAdrReg  = (unsigned int)inputPacket[3] +256*(unsigned int)inputPacket[2];
    globalcntReg      = (unsigned int)inputPacket[5] +256*(unsigned int)inputPacket[4];
    if(globalcntReg>125) return 0;//������� ������� �����
    if((*received_count)!=8) return 0;//�������� �-��

    sizeOutputPacket = outputFunc3PacketEncoder(adrUnit, globalbeginAdrReg, globalcntReg);
  }
  break;
  case 5:
  {
    globalbeginAdrBit  = (unsigned int)inputPacket[3] +256*(unsigned int)inputPacket[2];
    int dataBit = (unsigned int)inputPacket[5] +256*(unsigned int)inputPacket[4];
    if((*received_count)!=8) return 0;//�������� �-��
    globalcntBit      = 1;
    switch(dataBit)
    {
    case 0xFF00:
      dataBit = 1;
      break;
    case 0x0000:
      dataBit = 0;
      break;
    default:
    {
      sizeOutputPacket = Error_modbus_m(adrUnit, // address,
                                        numFunc,//function,
                                        ERROR_ILLEGAL_DATA_VALUE,//error,
                                        outputPacket);//output_data
      dataBit = -1;
    }
    }//switch
    if(dataBit<0) break;
    sizeOutputPacket = outputFunc5PacketEncoder(adrUnit, globalbeginAdrBit, dataBit);
  }
  break;
  case 6:
  {
    globalbeginAdrReg  = (unsigned int)inputPacket[3] +256*(unsigned int)inputPacket[2];
    int dataReg = (unsigned int)inputPacket[5] +256*(unsigned int)inputPacket[4];
    if((*received_count)!=8) return 0;//�������� �-��
    globalcntReg      = 1;
    sizeOutputPacket = outputFunc6PacketEncoder(adrUnit, globalbeginAdrReg, dataReg);
  }
  break;
  case 15:
  {
    globalbeginAdrBit  = (unsigned int)inputPacket[3] +256*(unsigned int)inputPacket[2];
    globalcntBit  = (unsigned int)inputPacket[5] +256*(unsigned int)inputPacket[4];
    int cntByte = (unsigned int)inputPacket[6];
    if(globalcntBit>125) return 0;//������� ������� �����

    for(int i=0; i<cntByte; i++)
      tempReadArray[i] = (unsigned short)(inputPacket[7+i]);
    sizeOutputPacket = outputFunc15PacketEncoder(adrUnit, globalbeginAdrBit, globalcntBit);
  }//case 15:
  break;
  case 16:
  {
    globalbeginAdrReg  = (unsigned int)inputPacket[3] +256*(unsigned int)inputPacket[2];
    globalcntReg  = (unsigned int)inputPacket[5] +256*(unsigned int)inputPacket[4];
    if(globalcntReg>125) return 0;//������� ������� �����

    for(int i=0; i<globalcntReg; i++)
      tempReadArray[i] = (unsigned short)(inputPacket[7+1+(i*2)]) +256*(unsigned short)(inputPacket[7+(i*2)]);
    sizeOutputPacket = outputFunc16PacketEncoder(adrUnit, globalbeginAdrReg, globalcntReg);
  }//case 16:
  break;
  case 20:
  {
    int fileNumber[40];
    int recordNumber[40];
    int recordLen[40];
    int item=0;
    int recordLenSum=0;//�-�� ����������� ���������

    isActiveActualData2021 = 1;//action before

    for(item=0; item<40; item++)
    {
      if(*received_count<(5+(item+1)*7)) break;//������� ���������� item
      fileNumber[item]   = (unsigned int)inputPacket[5+item*7] +256*(unsigned int)inputPacket[4+item*7];
      recordNumber[item] = (unsigned int)inputPacket[7+item*7] +256*(unsigned int)inputPacket[6+item*7];
      recordLen[item]    = (unsigned int)inputPacket[9+item*7] +256*(unsigned int)inputPacket[8+item*7];
      if(recordLen[item]==0) return 0;//���� 0 - �� ��������
      recordLenSum += recordLen[item];
      if((inputPacket[3+item*7])!=6 ||//��� �������==6
          ((recordLenSum*2+5+2*item)>250))//������� ����� ��������� �������
      {
        return 0;//������������ �� ����� - �� ��������
      }//if
    }//for

    if(item<1) return 0;//������������ �� ����� - �� ��������
    if(inputPacket[2]!=7*item) return 0;//������������ �� ����� - �� ��������
    if(*received_count!=(5+item*7)) return 0;//������������ �� ����� - �� ��������

    sizeOutputPacket = outputFunc20PacketEncoder(fileNumber, recordNumber, recordLen, item);

    if(sizeOutputPacket==-1)
    {
      sizeOutputPacket = Error_modbus_m(adrUnit, // address,
                                        inputPacket[1],//function,
                                        ERROR_ILLEGAL_DATA_ADDRESS,//error,
                                        outputPacket);//output_data
    }//if
  }//case 20:
  break;

  case 21:
  {
    int fileNumber;
    int recordNumber;
    int recordLen;
    int item=0;
    int recordLenSum=0;//�-�� ����������� ���������
    int dataLen_old=0;

    isActiveActualData2021 = 1;//action before

    for(item=0; item<40; item++)
    {
      if(*received_count<(5+(item+1)*7 +dataLen_old*2)) break;//������� ���������� item
      recordLen    = (unsigned int)inputPacket[9+item*7 +dataLen_old*2] +256*(unsigned int)inputPacket[8+item*7 +dataLen_old*2];
      recordLenSum += recordLen;
      if((inputPacket[3+item*7+dataLen_old*2])!=6 ||//��� �������==6
          ((recordLenSum*2+5+2*item+dataLen_old*2)>250))//������� ����� ��������� �������
      {
        return 0;//������������ �� ����� - �� ��������
      }//if
      dataLen_old += recordLen;
    }//for

    if(*received_count!=(5+item*7 +dataLen_old*2)) return 0;//������������ �� ����� - �� ��������
    if(item<1) return 0;//������������ �� ����� - �� ��������
    if(inputPacket[2]!=7*item+dataLen_old*2) return 0;//������������ �� ����� - �� ��������

    dataLen_old=0;

    for(int i=0; i<item; i++)
    {
      fileNumber   = (unsigned int)inputPacket[5+i*7 +dataLen_old*2] +256*(unsigned int)inputPacket[4+i*7 +dataLen_old*2];
      recordNumber = (unsigned int)inputPacket[7+i*7 +dataLen_old*2] +256*(unsigned int)inputPacket[6+i*7 +dataLen_old*2];
      recordLen    = (unsigned int)inputPacket[9+i*7 +dataLen_old*2] +256*(unsigned int)inputPacket[8+i*7 +dataLen_old*2];
      unsigned short *dataPacket = (unsigned short *)&inputPacket[10+i*7 +dataLen_old*2];

      int result = superWriter21func(fileNumber, recordNumber, recordLen, dataPacket);
      dataLen_old += recordLen;

      switch(result)
      {
      case MARKER_ERRORDIAPAZON:
        sizeOutputPacket = Error_modbus_m(adrUnit, // address,
                                          inputPacket[1],//function,
                                          ERROR_ILLEGAL_DATA_VALUE,//error,
                                          outputPacket);//output_data
        goto m1;
      case MARKER_ERRORPERIMETR:
      case MARKER_OUTPERIMETR://���� ���� �� ����������
        sizeOutputPacket = Error_modbus_m(adrUnit, // address,
                                          inputPacket[1],//function,
                                          ERROR_ILLEGAL_DATA_ADDRESS,//error,
                                          outputPacket);//output_data
        goto m1;

      case MARKER_ERRORPAROL:
        sizeOutputPacket = Error_modbus_m(adrUnit, // address,
                                          outputPacket[1],//function,
                                          ERROR_ACKNOWLEDGE,//error,
                                          outputPacket);//output_data
        goto m1;

      }//switch

    }//for

    sizeOutputPacket = (*received_count)-2;
    for(int i=0; i<sizeOutputPacket; i++) outputPacket[i] = inputPacket[i];//����������� �����

    //������� ������� 12000 ����� ��������� ������ ����� �������
    restart_timeout_interface |= (1 << pointInterface);//����� ���������� 0-USB 1-RS485
    if(upravlSetting>0 || upravlSchematic>0)
    {
      _SET_BIT(active_functions, RNG_BIG_SETTINGS_CHANGED);
      restart_timeout_idle_new_settings = true;
      current_settings_interfaces = edition_settings;//��������� ���������
      if(upravlSetting==1) type_of_settings_changed |= (1 << SETTINGS_DATA_CHANGED_BIT);
      if(upravlSchematic==1) type_of_settings_changed |= (1 << RANGUVANNJA_DATA_CHANGED_BIT);
    }//if(upravlSetting>0 || upravlSchematic>0)
  }//case 21:
  break;

  default:
  {
    sizeOutputPacket = Error_modbus_m(adrUnit, // address,
                                      numFunc,//function,
                                      ERROR_ILLEGAL_FUNCTION,//error,
                                      outputPacket);//output_data
  }
  }//switch
m1:
  CRC_sum = 0xffff;
  for (int index = 0; index < sizeOutputPacket; index++) CRC_sum = AddCRC((*(outputPacket + index)),CRC_sum);
  *(outputPacket + sizeOutputPacket)  = CRC_sum & 0xff;
  *(outputPacket + sizeOutputPacket+1)  = CRC_sum >> 8;
  sizeOutputPacket += 2;
  return 1;
}//inputPacketParser

int superWriter21func(int fileNumber, int recordNumber, int recordLen, unsigned short *dataPacket)
{
  int result = 0;

  if(pointInterface==USB_RECUEST)//����� ���������� 0-USB 1-RS485
  {
    if(password_set_USB) return MARKER_ERRORPAROL;
  }
  else if(pointInterface==RS485_RECUEST)
  {
    if(password_set_RS485) return MARKER_ERRORPAROL;
  }
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
  else if(pointInterface==LAN_RECUEST)
  {
    if(password_set_LAN) return MARKER_ERRORPAROL;
  }
#endif

  for(int i=0; i<TOTAL_COMPONENT2021; i++)
  {
    result = config_array2021func[i].setModbusRegister21func(fileNumber, recordNumber, recordLen, dataPacket);

    if(result==MARKER_ERRORDIAPAZON) return result;
    if(result==MARKER_ERRORPERIMETR) return result;
    if(result!=MARKER_OUTPERIMETR) break;
  }//for

  if(result==MARKER_OUTPERIMETR) return result;

  for(int i=0; i<TOTAL_COMPONENT2021; i++)
  {
    result = config_array2021func[i].postWriteAction21func(fileNumber, recordNumber, recordLen, dataPacket);

    if(result==MARKER_ERRORDIAPAZON) return result;
    if(result==MARKER_ERRORPERIMETR) return result;
    if(result!=MARKER_OUTPERIMETR) break;
  }//for
  return result;
}//superWriter21func

int superReader20func(int fileNumber, int recordNumber, int registerNumber, int recordLen)
{
  int result = 0;
  for(int i=0; i<TOTAL_COMPONENT2021; i++)
  {
    result = config_array2021func[i].getModbusRegister20func(fileNumber, recordNumber, registerNumber, recordLen);
    if(result==MARKER_ERRORPERIMETR) return result;
    if(result!=MARKER_OUTPERIMETR) break;
  }//for
  return result;
}//superReader20func

int outputFunc20PacketEncoder(int *fileNumberArray, int *recordNumberArray, int *recordLenArray, int cntitem)
{
//�������� ���������� 20 �������
  short dataRegister[130];
  int   registerNumber = 0;
  int idxOutputPacket = 0;
  unsigned int respDataLength = 0;
//adrUnit
  idxOutputPacket++;
//numFunc
  idxOutputPacket++;
//Resp. Data length
  idxOutputPacket++;

  ulWorkNumber_rds = 0xffffffff;
  for(int item=0; item<cntitem; item++)  //����� fileNumber, recordNumber, recordLen
  {
//File resp. length
//    respDataLength += outputPacket[idxOutputPacket] = (unsigned char)((1+recordLenArray[item]*2)&0xFF);
 
//    outputPacket[idxOutputPacket] = (unsigned char)((1+recordLenArray[item]*2)&0xFF)+1;//experim2
//    respDataLength += outputPacket[idxOutputPacket]-1;//experim2

    outputPacket[idxOutputPacket] = (unsigned char)((1+recordLenArray[item]*2)&0xFF)-1;//experim2
    respDataLength += outputPacket[idxOutputPacket]+1;//experim2
    outputPacket[idxOutputPacket] = outputPacket[idxOutputPacket]/2;

    idxOutputPacket++;
//Ref. Type
    outputPacket[idxOutputPacket] = 6;
    idxOutputPacket++;

    recordNumber_old = -1;

    for(; registerNumber<recordLenArray[item]; registerNumber++)
    {
      int result = superReader20func(fileNumberArray[item], recordNumberArray[item], registerNumber, recordLenArray[item]);

      switch(result)
      {
      case MARKER_ERRORPERIMETR:
      case MARKER_OUTPERIMETR://���� ���� �� ����������
        return -1;

      default:
      {

        dataRegister[registerNumber] = (short) result;
      }
      }//switch
    }//for

    for(int i=0; i<registerNumber; i++)
    {
//Mdata
      outputPacket[idxOutputPacket] = (unsigned char)((dataRegister[i]>>8)&0xFF);
      idxOutputPacket++;
//Ldata
      outputPacket[idxOutputPacket] = (unsigned char)(dataRegister[i]&0xFF);
      idxOutputPacket++;
    }//for(int i=0; i<registerNumber; i++)
    registerNumber=0;
  }//for(int item=0; item<cntitem; item++)

//Resp. Data length
//  outputPacket[2] = respDataLength+cntitem;
//  outputPacket[2] = respDataLength+cntitem+1;//experim2
  outputPacket[2] = respDataLength+cntitem;//xoxo
  return idxOutputPacket;
}//outputFunc20PacketEncoder(int adrUnit, int *fileNumber, int *recordNumber, int *recordLen, int cntitem)

int outputFunc16PacketEncoder(int adrUnit, int adrReg, int cntReg)
{
//�������� ���������� 16 �������
  int   flag = 1;
  superPreAction();//action �� ������
  for(int i=0; i<cntReg; i++)
  {
    uint32_t dataReg = (unsigned short) tempReadArray[i];
    int result = superWriterRegister(adrReg+i, dataReg);
    switch(result)
    {
    case MARKER_OUTPERIMETR:
      break;
    case MARKER_ERRORPERIMETR:
      return Error_modbus_m(adrUnit, // address,
                            outputPacket[1],//function,
                            ERROR_ILLEGAL_DATA_ADDRESS,//error,
                            outputPacket);//output_data
    case MARKER_ERRORDIAPAZON:
      return Error_modbus_m(adrUnit, // address,
                            outputPacket[1],//function,
                            ERROR_ILLEGAL_DATA_VALUE,//error,
                            outputPacket);//output_data
    case MARKER_ERRORPAROL:
      return Error_modbus_m(adrUnit, // address,
                            outputPacket[1],//function,
                            ERROR_ACKNOWLEDGE,//error,
                            outputPacket);//output_data
    default:
    {
      flag = 0;
    }
    }//switch
  }//for
  if(flag)//���������� ������ �����������
    return Error_modbus_m(adrUnit, // address,
                          outputPacket[1],//function,
                          ERROR_ILLEGAL_DATA_ADDRESS,//error,
                          outputPacket);//output_data

  int upravlReturn = superPostWriteAction();//action ����� ������
  if(upravlReturn) return upravlReturn;//������������ ����� ������

  int idxOutputPacket = 0;
//adrUnit
  idxOutputPacket++;
//numFunc
  idxOutputPacket++;
//MadrReg
  outputPacket[idxOutputPacket] = (unsigned char)((adrReg>>8)&0xFF);
  idxOutputPacket++;
//LadrReg
  outputPacket[idxOutputPacket] = (unsigned char)(adrReg&0xFF);
  idxOutputPacket++;
//MdataReg
  outputPacket[idxOutputPacket] = (unsigned char)((cntReg>>8)&0xFF);
  idxOutputPacket++;
//LdataReg
  outputPacket[idxOutputPacket] = (unsigned char)(cntReg&0xFF);
  idxOutputPacket++;
  return idxOutputPacket;
}//outputFunc16PacketEncoder(int adrUnit, int adrReg, int cntReg)

int outputFunc15PacketEncoder(int adrUnit, int adrBit, int cntBit)
{
//�������� ���������� 15 �������
  short dataBit = 0;
  int   flag = 1;
  superPreAction();//action �� ������
  for(int i=0; i<cntBit; i++)
  {
    int idx = i/8;
    dataBit = tempReadArray[idx];
    short maska = 1<<(i%8);
    int result = superWriterBit(adrBit+i, dataBit&maska ? 1:0);
    switch(result)
    {
    case MARKER_OUTPERIMETR:
      break;
    case MARKER_ERRORPERIMETR:
      return Error_modbus_m(adrUnit, // address,
                            outputPacket[1],//function,
                            ERROR_ILLEGAL_DATA_ADDRESS,//error,
                            outputPacket);//output_data
    case MARKER_ERRORDIAPAZON:
      return Error_modbus_m(adrUnit, // address,
                            outputPacket[1],//function,
                            ERROR_ILLEGAL_DATA_VALUE,//error,
                            outputPacket);//output_data
    case MARKER_ERRORPAROL:
      return Error_modbus_m(adrUnit, // address,
                            outputPacket[1],//function,
                            ERROR_ACKNOWLEDGE,//error,
                            outputPacket);//output_data
    default:
    {
      flag = 0;
    }
    }//switch
  }//for
  if(flag)//���������� ������ �����������
    return Error_modbus_m(adrUnit, // address,
                          outputPacket[1],//function,
                          ERROR_ILLEGAL_DATA_ADDRESS,//error,
                          outputPacket);//output_data

  int upravlReturn = superPostWriteAction();//action ����� ������
  if(upravlReturn) return upravlReturn;//������������ ����� ������

  int idxOutputPacket = 0;
//adrUnit
  idxOutputPacket++;
//numFunc
  idxOutputPacket++;
//MadrBit
  outputPacket[idxOutputPacket] = (unsigned char)((adrBit>>8)&0xFF);
  idxOutputPacket++;
//LadrBit
  outputPacket[idxOutputPacket] = (unsigned char)(adrBit&0xFF);
  idxOutputPacket++;
//McntBit
  outputPacket[idxOutputPacket] = (unsigned char)((cntBit>>8)&0xFF);
  idxOutputPacket++;
//LcntBit
  outputPacket[idxOutputPacket] = (unsigned char)(cntBit&0xFF);
  idxOutputPacket++;
  return idxOutputPacket;
}//outputFunc15PacketEncoder(int adrUnit, int adrBit, int cntBit)

int outputFunc6PacketEncoder(int adrUnit, int adrReg, int dataReg)
{
//�������� ���������� 6 �������
  superPreAction();//action �� ������
  int result = superWriterRegister(adrReg, dataReg);
  switch(result)
  {
  case MARKER_OUTPERIMETR:
    return Error_modbus_m(adrUnit, // address,
                          outputPacket[1],//function,
                          ERROR_ILLEGAL_DATA_ADDRESS,//error,
                          outputPacket);//output_data
  case MARKER_ERRORPERIMETR:
    return Error_modbus_m(adrUnit, // address,
                          outputPacket[1],//function,
                          ERROR_ILLEGAL_DATA_ADDRESS,//error,
                          outputPacket);//output_data
  case MARKER_ERRORDIAPAZON:
    return Error_modbus_m(adrUnit, // address,
                          outputPacket[1],//function,
                          ERROR_ILLEGAL_DATA_VALUE,//error,
                          outputPacket);//output_data
  case MARKER_ERRORPAROL:
    return Error_modbus_m(adrUnit, // address,
                          outputPacket[1],//function,
                          ERROR_ACKNOWLEDGE,//error,
                          outputPacket);//output_data
  }//switch

  int upravlReturn = superPostWriteAction();//action ����� ������
  if(upravlReturn) return upravlReturn;//������������ ����� ������

  int idxOutputPacket = 0;
//adrUnit
  idxOutputPacket++;
//numFunc
  idxOutputPacket++;
//MadrReg
  outputPacket[idxOutputPacket] = (unsigned char)((adrReg>>8)&0xFF);
  idxOutputPacket++;
//LadrReg
  outputPacket[idxOutputPacket] = (unsigned char)(adrReg&0xFF);
  idxOutputPacket++;
//MdataReg
  outputPacket[idxOutputPacket] = (unsigned char)((dataReg>>8)&0xFF);
  idxOutputPacket++;
//LdataReg
  outputPacket[idxOutputPacket] = (unsigned char)(dataReg&0xFF);
  idxOutputPacket++;
  return idxOutputPacket;
}//outputFunc6PacketEncoder(int adrUnit, int adrReg, int dataReg)

int outputFunc5PacketEncoder(int adrUnit, int adrBit, int dataBit)
{
//�������� ���������� 5 �������
  superPreAction();//action �� ������
  int result = superWriterBit(adrBit, dataBit);
  switch(result)
  {
  case MARKER_OUTPERIMETR:
    return Error_modbus_m(adrUnit, // address,
                          outputPacket[1],//function,
                          ERROR_ILLEGAL_DATA_ADDRESS,//error,
                          outputPacket);//output_data
  case MARKER_ERRORPERIMETR:
    return Error_modbus_m(adrUnit, // address,
                          outputPacket[1],//function,
                          ERROR_ILLEGAL_DATA_ADDRESS,//error,
                          outputPacket);//output_data
  case MARKER_ERRORDIAPAZON:
    return Error_modbus_m(adrUnit, // address,
                          outputPacket[1],//function,
                          ERROR_ILLEGAL_DATA_VALUE,//error,
                          outputPacket);//output_data
  case MARKER_ERRORPAROL:
    return Error_modbus_m(adrUnit, // address,
                          outputPacket[1],//function,
                          ERROR_ACKNOWLEDGE,//error,
                          outputPacket);//output_data
  }//switch

  int upravlReturn = superPostWriteAction();//action ����� ������
  if(upravlReturn) return upravlReturn;//������������ ����� ������

  int idxOutputPacket = 0;
//adrUnit
  idxOutputPacket++;
//numFunc
  idxOutputPacket++;
//MadrBit
  outputPacket[idxOutputPacket] = (unsigned char)((adrBit>>8)&0xFF);
  idxOutputPacket++;
//LadrBit
  outputPacket[idxOutputPacket] = (unsigned char)(adrBit&0xFF);
  idxOutputPacket++;
//MdataReg
  outputPacket[idxOutputPacket] = (unsigned char)(0xFF);
  if(dataBit==0) outputPacket[idxOutputPacket] = (unsigned char)(0x00);
  idxOutputPacket++;
//LdataReg
  outputPacket[idxOutputPacket] = (unsigned char)(0x0);
  idxOutputPacket++;
  return idxOutputPacket;
}//outputFunc5PacketEncoder(int adrUnit, int adrBit)

int outputFunc3PacketEncoder(int adrUnit, int adrReg, int cntReg)
{
//�������� ���������� 3 �������
  short dataRegister[130];
  int   idxDataRegister = 0;
  int   flag = 1;
  superPreAction();//action �� ������
  for(; idxDataRegister<cntReg; idxDataRegister++)
  {
    int result = superReaderRegister(adrReg+ idxDataRegister);
    switch(result)
    {
    case MARKER_OUTPERIMETR:
      break;
    case MARKER_ERRORPERIMETR://������ ���������
      return Error_modbus_m(adrUnit, // address,
                            outputPacket[1],//function,
                            ERROR_ILLEGAL_DATA_ADDRESS,//error,
                            outputPacket);//output_data
    default:
    {
      dataRegister[idxDataRegister] = (short) result;
      flag = 0;
    }
    }//switch
  }//for
  if(flag)//���������� ������ �����������
    return Error_modbus_m(adrUnit, // address,
                          outputPacket[1],//function,
                          ERROR_ILLEGAL_DATA_ADDRESS,//error,
                          outputPacket);//output_data

  int idxOutputPacket = 0;
//adrUnit
  idxOutputPacket++;
//numFunc
  idxOutputPacket++;
//cnt
  outputPacket[idxOutputPacket] = (unsigned char)cntReg*2;
  idxOutputPacket++;
//data
  for(int i=0; i<idxDataRegister; i++)
  {
//Mdata
    outputPacket[idxOutputPacket] = (unsigned char)((dataRegister[i]>>8)&0xFF);
    idxOutputPacket++;
//Ldata
    outputPacket[idxOutputPacket] = (unsigned char)(dataRegister[i]&0xFF);
    idxOutputPacket++;
  }//for
  return idxOutputPacket;
}//outputFunc3PacketEncoder(int adrUnit, int adrReg, int cntReg)

int outputFunc1PacketEncoder(int adrUnit, int adrBit, int cntBit)
{
//�������� ���������� 1 �������
  short dataRegister[130];
  for(int i=0; i<128; i++) dataRegister[i]=0;
  int   idxDataBit = 0;
  int   flag = 1;

  superPreAction();//action �� ������
  for(; idxDataBit<cntBit; idxDataBit++)
  {
    int result = superReaderBit(adrBit+ idxDataBit);

    switch(result)
    {
    case MARKER_OUTPERIMETR:
      break;
    case MARKER_ERRORPERIMETR:
      return Error_modbus_m(adrUnit, // address,
                            outputPacket[1],//function,
                            ERROR_ILLEGAL_DATA_ADDRESS,//error,
                            outputPacket);//output_data
    default:
    {
      dataRegister[idxDataBit/8] |= (result<<(idxDataBit%8));
      flag = 0;
    }
    }//switch
  }//for
  if(flag)//���������� ������ �����������
    return Error_modbus_m(adrUnit, // address,
                          outputPacket[1],//function,
                          ERROR_ILLEGAL_DATA_ADDRESS,//error,
                          outputPacket);//output_data

  int idxOutputPacket = 0;
//adrUnit
  idxOutputPacket++;
//numFunc
  idxOutputPacket++;

  int cntByte = cntBit/8;
  if(cntBit%8) cntByte++;
  outputPacket[idxOutputPacket] = cntByte;
  idxOutputPacket++;
//data
  for(int i=0; i<cntByte; i++)
  {
//data
    outputPacket[idxOutputPacket] = (unsigned char)(dataRegister[i]&0xFF);
    idxOutputPacket++;
  }//for

  return idxOutputPacket;
}//outputFunc1PacketEncoder(int adrUnit, int adrBit, int cntBit)

/**************************************/
//action �� ������ � ������
/**************************************/
void superPreAction(void)
{
  int i=0;
  for(; i<TOTAL_COMPONENT; i++)
  {
    config_array[i].operativMarker[0]=-1;
    config_array[i].operativMarker[1]=-1;
    config_array[i].isActiveActualData=1;
  }//for
}//superPreAction

/**************************************/
//action ����� ������
/**************************************/
int superPostWriteAction(void)
{
  int i=0;
  for(; i<TOTAL_COMPONENT; i++)
  {
    switch(config_array[i].postWriteAction())

    {
    case ERROR_VALID2:
      return Error_modbus_m(inputPacket[0], // address,
                            inputPacket[1],//function,
                            ERROR_ILLEGAL_DATA_VALUE,//error,
                            outputPacket);//output_data
    case ERROR_VALID3:
      return Error_modbus_m(inputPacket[0], // address,
                            inputPacket[1],//function,
                            ERROR_SLAVE_DEVICE_BUSY,//error,
                            outputPacket);//output_data
    }//switch

  }//for

  //������� ������� 12000 ����� ��������� ������ ����� �������
  restart_timeout_interface |= (1 << pointInterface);//����� ���������� 0-USB 1-RS485
  if(!(upravlSetting>0 || upravlSchematic>0)) return 0;
  _SET_BIT(active_functions, RNG_BIG_SETTINGS_CHANGED);
  restart_timeout_idle_new_settings = true;
  current_settings_interfaces = edition_settings;//��������� ���������
  if(upravlSetting==1) type_of_settings_changed |= (1 << SETTINGS_DATA_CHANGED_BIT);
  if(upravlSchematic==1) type_of_settings_changed |= (1 << RANGUVANNJA_DATA_CHANGED_BIT);

  return 0;
}//superPostWriteAction

/**************************************/
//����������� ��������
/**************************************/
int superReaderRegister(int adrReg)
{
  int result=0;
  int i=0;
  for(; i<TOTAL_COMPONENT; i++)
  {
    result = config_array[i].getModbusRegister(adrReg);
    if(!(result==MARKER_OUTPERIMETR)) break;
  }//for
  if(i==TOTAL_COMPONENT) result = MARKER_OUTPERIMETR;
  return result;
}//superReaderRegister()

/**************************************/
//����������� ��������
/**************************************/
int superWriterRegister(int adrReg, int dataReg)
{
  int result=0;
  int i=0;
  if(pointInterface==USB_RECUEST)//����� ���������� 0-USB 1-RS485
  {
    if(passwordImunitetReg(adrReg) && password_set_USB) return MARKER_ERRORPAROL;
  }
  else if(pointInterface==RS485_RECUEST)
  {
    if(passwordImunitetReg(adrReg) && password_set_RS485) return MARKER_ERRORPAROL;
  }
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
  else if(pointInterface==LAN_RECUEST)
  {
    if(passwordImunitetReg(adrReg) && password_set_LAN) return MARKER_ERRORPAROL;
  }
#endif

  for(; i<TOTAL_COMPONENT; i++)
  {
    result = config_array[i].setModbusRegister(adrReg, dataReg);
    if(!(result==MARKER_OUTPERIMETR)) break;
  }//for
  if(i==TOTAL_COMPONENT) result = MARKER_OUTPERIMETR;
  return result;
}//superWriterRegister(int adrReg, int dataReg)

/**************************************/
//bit ��������
/**************************************/
int superReaderBit(int adrBit)
{
  int result=0;
  int i=0;
  for(; i<TOTAL_COMPONENT; i++)
  {
    result = config_array[i].getModbusBit(adrBit);
    if(!(result==MARKER_OUTPERIMETR)) break;
  }//for
  if(i==TOTAL_COMPONENT) result = MARKER_OUTPERIMETR;
  return result;
}//superReaderBit()

/**************************************/
//bit ��������
/**************************************/
int superWriterBit(int adrBit, int dataBit)
{
  int result=0;
  int i=0;
  if(pointInterface==USB_RECUEST)//����� ���������� 0-USB 1-RS485
  {
    if(passwordImunitetBit(adrBit) && password_set_USB) return MARKER_ERRORPAROL;
  }
  else if(pointInterface==RS485_RECUEST)
  {
    if(passwordImunitetBit(adrBit) && password_set_RS485) return MARKER_ERRORPAROL;
  }
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
  else if(pointInterface==LAN_RECUEST)
  {
    if(passwordImunitetBit(adrBit) && password_set_LAN) return MARKER_ERRORPAROL;
  }
#endif

  for(; i<TOTAL_COMPONENT; i++)
  {
    result = config_array[i].setModbusBit(adrBit, dataBit);
    if(!(result==MARKER_OUTPERIMETR)) break;
  }//for
  if(i==TOTAL_COMPONENT) result = MARKER_OUTPERIMETR;
  return result;
}//superReaderRegister()

/**************************************/
//��������� ����������� ��������
/**************************************/
void superSetOperativMarker(COMPONENT_OBJ *component, int adrReg)
{
  if(component->operativMarker[0]<0) component->operativMarker[0] = adrReg;
  else component->operativMarker[1] = adrReg;
}//superSetOperativMarker(COMPONENT_OBJ component, int adrReg)

void superSetTempWriteArray(int dataReg)
{
//�������� � �����
  if(indexTW>=MAXIMUMTW) return;
  tempWriteArray[indexTW] = dataReg;
  indexTW++;//������ ������ ������
}//superSetTempWriteArray(int dataReg)

int superFindTempWriteArrayOffset(int adr)
{
//����� �������� TempWriteArray
  int iComponentOffset=0;
  int i=0;
  for(; i<TOTAL_COMPONENT; i++)
  {
    if(config_array[i].operativMarker[0]<0) continue;
    if(config_array[i].operativMarker[0]<adr)
    {
      if(config_array[i].operativMarker[1]<0) iComponentOffset++;
      else iComponentOffset+=(config_array[i].operativMarker[1]-config_array[i].operativMarker[0]+1);
    }//if
  }//for
  return iComponentOffset;
}//superFindTempWriteArrayOffset(int adr)

int controlPerimetr(int adrReg, int begin_adr, int end_adr)
{
  //��������� ������� ��������
  int count_register = end_adr-begin_adr+1;
  if(adrReg>=begin_adr && adrReg<(begin_adr+count_register)) return 0;
  return MARKER_OUTPERIMETR;
}//controlPerimetr(int adrReg, int begin_adr, int end_adr)

void superClearActiveActualData(void)
{
  extern COMPONENT_OBJ *pkvbigcomponent;

  pkvbigcomponent->isActiveActualData = 0;
}//superClearActiveActualData()

int passwordImunitetRegYUSTBigComponent(int adrReg);
int passwordImunitetRegPKVBigComponent(int adrReg);
int passwordImunitetRegREG1BigComponent(int adrReg);
int passwordImunitetBitACMDSmallComponent(int adrBit);

int passwordImunitetBit(int adrBit)
{
  if(passwordImunitetBitACMDSmallComponent(adrBit)==MARKER_OUTPERIMETR) return 1;//��������� ���
  return 0;//�������� ����
}//passwordImunitetBit(int adrBit)

int passwordImunitetReg(int adrReg)
{
//  if(passwordImunitetRegPKVBigComponent(adrReg)==MARKER_OUTPERIMETR &&
//      passwordImunitetRegREG1BigComponent(adrReg)==MARKER_OUTPERIMETR &&
//      passwordImunitetRegYUSTBigComponent(adrReg)==MARKER_OUTPERIMETR) return 1;//��������� ���
  return 0;//�������� ����
}//passwordImunitetReg(int adrReg)

