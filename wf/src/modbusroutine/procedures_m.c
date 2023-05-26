#include "header.h"

extern unsigned char  *outputPacket;
extern unsigned char  outputPacket_USB[300];
extern unsigned char  outputPacket_RS485[300];
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
extern unsigned char  outputPacket_TCP[300];
#endif

extern int sizeOutputPacket;
extern unsigned char *inputPacket;
extern int *received_count;
extern int globalcntBit;//�-�� ���
extern int globalcntReg;//�-�� ���������
extern int globalbeginAdrReg;//����� ��� ��������
extern int globalbeginAdrBit;//����� ��� ���

int  inputPacketParser(void);
void inputPacketParserUSB(void);
void inputPacketParserRS485(void);
unsigned short int  AddCRC(unsigned char inpbyte, unsigned short int oldCRC);
int  Error_modbus_m(unsigned int address, unsigned int function, unsigned int error, unsigned char *output_data);

#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
/**************************************/
//������ �������� ������ TCP
/**************************************/
void inputPacketParserLAN(void)
{
//������ �������� TCP  
//#define TCP_PREFIXSIZE 6  
  pointInterface=LAN_RECUEST;//����� ���������� 0-USB 1-RS485

  received_count = &LAN_received_count;

  outputPacket = outputPacket_TCP;
  inputPacket = LAN_received;
//                +TCP_PREFIXSIZE;//������ ������� TCP
//  *received_count -= TCP_PREFIXSIZE;//������ ������� TCP
  
  if((*received_count)<0)
  {
    LAN_received_count = 0;//�������� ����
    return;//���-�� ����� �� ���
  }//if
  
  *received_count += 2;//������������ CRC
  //�������� ���������� ����
//  unsigned short CRC_sum;
//  CRC_sum = 0xffff;
//  for (int index = 0; index < (*received_count-2); index++) CRC_sum = AddCRC(*(inputPacket + index),CRC_sum);
//  if((CRC_sum & 0xff)  != *(inputPacket+*received_count-2)) return;
//  if ((CRC_sum >> 8  ) != *(inputPacket+*received_count-1)) return;

//  if(inputPacket[0]!=current_settings.address) return;

  if(inputPacketParser()==0)
  {
   LAN_received_count = 0;//�������� ����
   return;
  }//if

  sizeOutputPacket -= 2;//������ CRC

  LAN_transmiting_count = sizeOutputPacket;
//  for (int i = 0; i < TCP_PREFIXSIZE; i++) LAN_transmiting[i] = 0;//�������� ������� TCP
//  LAN_transmiting[1] = 1;//������� TCP
//  LAN_transmiting[5] = sizeOutputPacket;//������� TCP
  for (int i = 0; i < LAN_transmiting_count; i++) LAN_transmiting[i/*+ TCP_PREFIXSIZE*/] = outputPacket[i];
//  LAN_transmiting_count += TCP_PREFIXSIZE;//�������� ������� TCP
  LAN_received_count = 0;//�������� ����
  _SET_STATE (queue_mo, STATE_QUEUE_MO_SEND_MODBUS_TCP_RESP);//��������� ���������
}//inputPacketParserLAN(void)
#endif  

/**************************************/
//������ �������� ������ USB
/**************************************/
void inputPacketParserUSB(void)
{
  pointInterface=USB_RECUEST;//����� ���������� 0-USB 1-RS485

  received_count = &usb_received_count;

  inputPacket = usb_received;
  outputPacket = outputPacket_USB;
  //�������� ���������� ����
  unsigned short CRC_sum;
  CRC_sum = 0xffff;
  for (int index = 0; index < (*received_count-2); index++) CRC_sum = AddCRC(*(inputPacket + index),CRC_sum);
  if((CRC_sum & 0xff)  != *(inputPacket+*received_count-2)) return;
  if ((CRC_sum >> 8  ) != *(inputPacket+*received_count-1)) return;

  if(inputPacket[0]!=current_settings.address) return;

  if(inputPacketParser()==0) return;

  usb_transmiting_count = sizeOutputPacket;
  for (int i = 0; i < usb_transmiting_count; i++) usb_transmiting[i] = outputPacket[i];
  data_usb_transmiting = true;
}//inputPacketParserUSB(void)

/**************************************/
//������ �������� ������ RS485
/**************************************/
void inputPacketParserRS485(void)
{
  pointInterface = RS485_RECUEST;//����� ���������� 0-USB 1-RS485

  inputPacket = RxBuffer_RS485;

  received_count = &RxBuffer_RS485_count;
  outputPacket = outputPacket_RS485;

  //�������� ���������� ����
  unsigned short CRC_sum;
  CRC_sum = 0xffff;
  for (int index = 0; index < (*received_count-2); index++) CRC_sum = AddCRC(*(inputPacket + index),CRC_sum);
  if((CRC_sum & 0xff)  != *(inputPacket+*received_count-2) ||//) return;
      (CRC_sum >> 8  ) != *(inputPacket+*received_count-1))
    {
      /***
      12345
      ������� �������� (�� ������� ���������� ����)
      ***/
      //reason_of_restart_RS485 |= (1 << 5);
      /***/

      restart_monitoring_RS485();
      return;
    }

  if(!(inputPacket[0]==current_settings.address))
    {
      /***
      12345
      ������� �������� (�� ������� ������ 2)
      ***/
      //reason_of_restart_RS485 |= (1 << 6);
      /***/

      restart_monitoring_RS485();
      return;
    }

  if(inputPacketParser()==0) 
    {
      /***
      12345
      ������� �������� (����� ������ ������ ���������� ������)
      ***/
      // reason_of_restart_RS485 |= (1 << 7);
      /***/

      restart_monitoring_RS485();
      return;
    }

  TxBuffer_RS485_count = sizeOutputPacket;
  for (int i = 0; i < TxBuffer_RS485_count; i++) TxBuffer_RS485[i] = outputPacket[i];
  start_transmint_data_via_RS_485(TxBuffer_RS485_count);
}//inputPacketParserRS485(void)

/***********************************************************************************/
//������� ������ �� ��������� Modbus-RTU �� �������
/***********************************************************************************/
int Error_modbus_m(unsigned int address, unsigned int function, unsigned int error, unsigned char *output_data)
{
  output_data[0] = address & 0xff;
  output_data[1] = 0x80 | (function & 0xff);
  output_data[2] = error & 0xff;
  return 3;
}

/***********************************************************************************/
//��������� ����� �� CRC ����
/***********************************************************************************/
unsigned short AddCRC(unsigned char inpbyte, unsigned short oldCRC)
{
  unsigned short v,temp;
  int i;
  unsigned char bt,m;

  bt = inpbyte;
  v  = oldCRC;

  for (i=0; i<8; i++)
    {
      temp = v;
      v = v >> 1;
      m = bt >> i;
      if (((temp ^m) & 1)== 1) v = v ^ 0xa001;
    }
  return v;
}

unsigned short swapByteInShort(unsigned short data)
{
  return data<<8 | data>>8;
}//swapByteInShort

