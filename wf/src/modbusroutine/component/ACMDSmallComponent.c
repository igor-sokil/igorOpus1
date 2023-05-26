
#include "header.h"

//начальный регистр в карте памяти
#define BEGIN_ADR_REGISTER 500
//начальный bit в карте памяти
#define BEGIN_ADR_BIT 25000

//конечный регистр в карте памяти
#define END_ADR_REGISTER 598
//конечный bit в карте памяти
#define END_ADR_BIT 26583

int privateACMDSmallGetReg2(int adrReg);
int privateACMDSmallGetBit2(int adrBit);

int getACMDSmallModbusRegister(int);//получить содержимое регистра
int getACMDSmallModbusBit(int);//получить содержимое бита
int setACMDSmallModbusRegister(int, int);//записать регистр
int setACMDSmallModbusBit(int, int);//записать бит

int  postACMDSmallWriteAction(void);//action после записи

int  cmdFunc000(int inOffset, int *outMaska, int *dvMaska, int actControl);
void loadACMDSmallActualDataBit(int cmdSwitch, int beginOffset, int endOffset);
unsigned int encoderValidN_BIGACMD(int offsetCMD, int *validCMD, int actControl);
unsigned int encoderValidN_SMALLACMD(int offsetCMD, int *validCMD);
int validBazaN_BIGACMD(unsigned short dataReg, int actControl);
int writeACMDSmallActualDataBit(int offset, int dataBit);
int passwordImunitetBitACMDSmallComponent(int adrReg);
int start_ar_function(int actControl, int dataBit);
int clean_rejestrators_function(int actControl, int dataBit);
int activationFunction(int small_cmd, int actControl, int dataBit);
int clear_ar_function(void);
int clear_dr_function(void);
int restartCounter(int actControl, int dataBit);

void decoderN_BIGACMDArrayLoader(void);
void decoderN_SMALLACMDArrayLoader(void);

SRAM1 unsigned short decoderN_BIGACMDArray[N_BIG*32];//массив декодирования битов N_BIG
SRAM1 unsigned short decoderN_SMALLACMDArray[N_SMALL*32];//массив декодирования битов N_SMALL

#define CLRACT_CONTROL  0

SRAM1 COMPONENT_OBJ *acmdsmallcomponent;
int cmdFunc000(int inOffset, int *outMaska, int *dvMaska, int actControl)
{
  int isValid = 1;
  (*outMaska) = -1;
  switch(inOffset)//адр команд карты памяти modbus
  {
  case 0:
    (*outMaska) = RNG_BIG_1_GRUPA_USTAVOK;
    (*dvMaska)  = RANGE_SMALL_A01_1_GRUPA_USTAVOK;
    break;
  case 1:
    (*outMaska) = RNG_BIG_2_GRUPA_USTAVOK;
    (*dvMaska)  = RANGE_SMALL_A01_2_GRUPA_USTAVOK;
    break;
  case 2:
    (*outMaska) = RNG_BIG_3_GRUPA_USTAVOK;
    (*dvMaska)  = RANGE_SMALL_A01_3_GRUPA_USTAVOK;
    break;
  case 3:
    (*outMaska) = RNG_BIG_4_GRUPA_USTAVOK;
    (*dvMaska)  = RANGE_SMALL_A01_4_GRUPA_USTAVOK;
    break;

//  int count_bit = 3;
#define MTZO_CONFIGURATION_BEGIN 16
  case MTZO_CONFIGURATION_BEGIN:
    (*outMaska) = RNG_BIG_BLOCK_MCZO1;
    (*dvMaska) = RANGE_SMALL_A01_BLK_MCZO1;
    break;
  case 17:
    (*outMaska) = RNG_BIG_MCZO1;
//        (*dvMaska) =
    break;
  case 18:
    (*outMaska) = RNG_BIG_PO_MCZO1;
//        (*dvMaska) =
    break;
  case 19:
    (*outMaska) = RNG_BIG_PO_MCZOPN1;
//        (*dvMaska) =
    break;
  case 20:
    (*outMaska) = RNG_BIG_PO_MCZON1_VPERED;
//        (*dvMaska) =
    break;
  case 21:
    (*outMaska) = RNG_BIG_PO_MCZON1_NAZAD;
//        (*dvMaska) =
    break;
  case 22:
    (*outMaska) = RNG_BIG_SECTOR_VPERED_MCZON1;
//        (*dvMaska) =
    break;
  case 23:
    (*outMaska) = RNG_BIG_SECTOR_NAZAD_MCZON1;
//        (*dvMaska) =
    break;
  case 24:
    (*outMaska) = RNG_BIG_PO_BLK_U_OSN_LESS_UST_MCZO1;
//        (*dvMaska) =
    break;

//  count_bit = 3;
  case 32:
    (*outMaska) = RNG_BIG_BLOCK_MCZO2;
    (*dvMaska) = RANGE_SMALL_A01_BLK_MCZO2;
    break;
  case 33:
    (*outMaska) = RNG_BIG_MCZO2;
//        (*dvMaska) =
    break;
  case 34:
    (*outMaska) = RNG_BIG_PO_MCZO2;
//        (*dvMaska) =
    break;
  case 35:
    (*outMaska) = RNG_BIG_PO_MCZOPN2;
//        (*dvMaska) =
    break;
  case 36:
    (*outMaska) = RNG_BIG_PO_MCZON2_VPERED;
//        (*dvMaska) =
    break;
  case 37:
    (*outMaska) = RNG_BIG_PO_MCZON2_NAZAD;
//        (*dvMaska) =
    break;
  case 38:
    (*outMaska) = RNG_BIG_SECTOR_VPERED_MCZON2;
//        (*dvMaska) =
    break;
  case 39:
    (*outMaska) = RNG_BIG_SECTOR_NAZAD_MCZON2;
//        (*dvMaska) =
    break;
  case 40:
    (*outMaska) = RNG_BIG_PO_BLK_U_OSN_LESS_UST_MCZO2;
//        (*dvMaska) =
    break;
  case 41:
    (*outMaska) = RNG_BIG_BLOCK_PR_MCZO2;
    (*dvMaska) = RANGE_SMALL_A01_BLK_USK_MCZO2;
    break;

//  count_bit = 3;
  case 48:
    (*outMaska) = RNG_BIG_BLOCK_MCZO3;
    (*dvMaska) = RANGE_SMALL_A01_BLK_MCZO3;
    break;
  case 49:
    (*outMaska) = RNG_BIG_MCZO3;
//        (*dvMaska) =
    break;
  case 50:
    (*outMaska) = RNG_BIG_PO_MCZO3;
//        (*dvMaska) =
    break;
  case 51:
    (*outMaska) = RNG_BIG_PO_MCZOPN3;
//        (*dvMaska) =
    break;
  case 52:
    (*outMaska) = RNG_BIG_PO_MCZON3_VPERED;
//        (*dvMaska) =
    break;
  case 53:
    (*outMaska) = RNG_BIG_PO_MCZON3_NAZAD;
//        (*dvMaska) =
    break;
  case 54:
    (*outMaska) = RNG_BIG_SECTOR_VPERED_MCZON3;
//        (*dvMaska) =
    break;
  case 55:
    (*outMaska) = RNG_BIG_SECTOR_NAZAD_MCZON3;
//        (*dvMaska) =
    break;
  case 56:
    (*outMaska) = RNG_BIG_PO_BLK_U_OSN_LESS_UST_MCZO3;
//        (*dvMaska) =
    break;

//  count_bit = 3;
  case 64:
    (*outMaska) = RNG_BIG_BLOCK_MCZO4;
    (*dvMaska) = RANGE_SMALL_A01_BLK_MCZO4;
    break;
  case 65:
    (*outMaska) = RNG_BIG_MCZO4;
//        (*dvMaska) =
    break;
  case 66:
    (*outMaska) = RNG_BIG_PO_MCZO4;
//        (*dvMaska) =
    break;
  case 67:
    (*outMaska) = RNG_BIG_PO_MCZOPN4;
//        (*dvMaska) =
    break;
  case 68:
    (*outMaska) = RNG_BIG_PO_MCZON4_VPERED;
//        (*dvMaska) =
    break;
  case 69:
    (*outMaska) = RNG_BIG_PO_MCZON4_NAZAD;
//        (*dvMaska) =
    break;
  case 70:
    (*outMaska) = RNG_BIG_SECTOR_VPERED_MCZON4;
//        (*dvMaska) =
    break;
  case 71:
    (*outMaska) = RNG_BIG_SECTOR_NAZAD_MCZON4;
//        (*dvMaska) =
    break;
  case 72:
    (*outMaska) = RNG_BIG_PO_BLK_U_OSN_LESS_UST_MCZO4;
//        (*dvMaska) =
    break;

//  count_bit = 3;
  case 96:
    (*outMaska) = RNG_BIG_NCN_MCZO;
//        (*dvMaska) =
    if(!(edition_settings.configuration&(1<<MCZO_BIT_CONFIGURATION))) isValid = 0;
    break;
#define MTZO_CONFIGURATION_END 97
  case MTZO_CONFIGURATION_END:
    (*outMaska) = RNG_BIG_PO_BLK_U_OSN_LESS_0_05UN_MCZO;
//        (*dvMaska) =
    if(!(edition_settings.configuration&(1<<MCZO_BIT_CONFIGURATION))) isValid = 0;
    break;

//  count_bit = 3;
#define MTZR_CONFIGURATION_BEGIN 112
  case MTZR_CONFIGURATION_BEGIN:
    (*outMaska) = RNG_BIG_BLOCK_MCZR1;
    (*dvMaska) = RANGE_SMALL_A01_BLK_MCZR1;
    break;
  case 113:
    (*outMaska) = RNG_BIG_MCZR1;
//        (*dvMaska) =
    break;
  case 114:
    (*outMaska) = RNG_BIG_PO_MCZR1;
//        (*dvMaska) =
    break;
  case 115:
    (*outMaska) = RNG_BIG_PO_MCZRPN1;
//        (*dvMaska) =
    break;
  case 116:
    (*outMaska) = RNG_BIG_PO_MCZRN1_VPERED;
//        (*dvMaska) =
    break;
  case 117:
    (*outMaska) = RNG_BIG_PO_MCZRN1_NAZAD;
//        (*dvMaska) =
    break;
  case 118:
    (*outMaska) = RNG_BIG_SECTOR_VPERED_MCZRN1;
//        (*dvMaska) =
    break;
  case 119:
    (*outMaska) = RNG_BIG_SECTOR_NAZAD_MCZRN1;
//        (*dvMaska) =
    break;
  case 120:
    (*outMaska) = RNG_BIG_PO_BLK_U_RSV_LESS_UST_MCZR1;
//        (*dvMaska) =
    break;

//  count_bit = 3;
  case 128:
    (*outMaska) = RNG_BIG_BLOCK_MCZR2;
    (*dvMaska) = RANGE_SMALL_A01_BLK_MCZR2;
    break;
  case 129:
    (*outMaska) = RNG_BIG_MCZR2;
//        (*dvMaska) =
    break;
  case 130:
    (*outMaska) = RNG_BIG_PO_MCZR2;
//        (*dvMaska) =
    break;
  case 131:
    (*outMaska) = RNG_BIG_PO_MCZRPN2;
//        (*dvMaska) =
    break;
  case 132:
    (*outMaska) = RNG_BIG_PO_MCZRN2_VPERED;
//        (*dvMaska) =
    break;
  case 133:
    (*outMaska) = RNG_BIG_PO_MCZRN2_NAZAD;
//        (*dvMaska) =
    break;
  case 134:
    (*outMaska) = RNG_BIG_SECTOR_VPERED_MCZRN2;
//        (*dvMaska) =
    break;
  case 135:
    (*outMaska) = RNG_BIG_SECTOR_NAZAD_MCZRN2;
//        (*dvMaska) =
    break;
  case 136:
    (*outMaska) = RNG_BIG_PO_BLK_U_RSV_LESS_UST_MCZR2;
//        (*dvMaska) =
    break;

//  count_bit = 3;
  case 144:
    (*outMaska) = RNG_BIG_NCN_MCZR;
//        (*dvMaska) =
    if(!(edition_settings.configuration&(1<<MCZR_BIT_CONFIGURATION))) isValid = 0;
    break;
#define MTZR_CONFIGURATION_END 145
  case MTZR_CONFIGURATION_END:
    (*outMaska) = RNG_BIG_PO_BLK_U_RSV_LESS_UN;
//        (*dvMaska) =
    if(!(edition_settings.configuration&(1<<MCZR_BIT_CONFIGURATION))) isValid = 0;
    break;

//  count_bit = 3;
#define ZDZ_CONFIGURATION_BEGIN 176
  case ZDZ_CONFIGURATION_BEGIN:
    (*outMaska) = RNG_BIG_BLOCK_ZDZ;
    (*dvMaska)  = RANGE_SMALL_A01_BLOCK_ZDZ;
    break;
  case 177:
    (*outMaska) = RNG_BIG_PUSK_ZDZ_VID_DV;
    (*dvMaska)  = RANGE_SMALL_A01_PUSK_ZDZ_VID_DV;
    break;
  case 178:
    (*outMaska) = RNG_BIG_PO_ZDZ;
//        (*dvMaska) =
    break;
  case 179:
    (*outMaska) = RNG_BIG_ZDZ;
//        (*dvMaska) =
    break;
  case 180:
    (*outMaska) = RNG_BIG_LIGHT_ZDZ_FROM_DV;
//        (*dvMaska) =
    break;

  case 181:
    (*outMaska) = RNG_BIG_LIGHT_ZDZ_FROM_OVD1;
//        (*dvMaska) =
    break;
  case 182:
    (*outMaska) = RNG_BIG_LIGHT_ZDZ_FROM_OVD2;
//        (*dvMaska) =
    break;
#define ZDZ_CONFIGURATION_END 183
  case ZDZ_CONFIGURATION_END:
    (*outMaska) = RNG_BIG_LIGHT_ZDZ_FROM_OVD3;
//        (*dvMaska) =
    break;

#define  CMD_ITEM_HOLES183 if(item>183 && item<368) continue;

//  count_bit = 8;
#define UMIN_CONFIGURATION_BEGIN 368
  case UMIN_CONFIGURATION_BEGIN:
    (*outMaska) = RNG_BIG_BLOCK_UMIN1;
    (*dvMaska) = RANGE_SMALL_A01_BLOCK_UMIN1;
    break;
  case 369:
    (*outMaska) = RNG_BIG_PO_UBLK_UMIN1;
//      (*dvMaska) =
    break;

  case 370:
    (*outMaska) = RNG_BIG_PO_IBLK_UMIN1;
//      (*dvMaska) =
    break;
  case 371:
    (*outMaska) = RNG_BIG_UMIN1;
//      (*dvMaska) =
    break;
  case 372:
    (*outMaska) = RNG_BIG_PO_UMIN1;
//      (*dvMaska) =
    break;
  case 373:
    (*outMaska) = RNG_BIG_START_UMIN1;
    (*dvMaska) = RANGE_SMALL_A01_START_UMIN1;
    break;

//  count_bit = 8;
  case 384:
    (*outMaska) = RNG_BIG_BLOCK_UMIN2;
    (*dvMaska) = RANGE_SMALL_A01_BLOCK_UMIN2;
    break;
  case 385:
    (*outMaska) = RNG_BIG_PO_UBLK_UMIN2;
//      (*dvMaska) =
    break;

  case 386:
    (*outMaska) = RNG_BIG_PO_IBLK_UMIN2;
//      (*dvMaska) =
    break;
  case 387:
    (*outMaska) = RNG_BIG_UMIN2;
//      (*dvMaska) =
    break;
  case 388:
    (*outMaska) = RNG_BIG_PO_UMIN2;
//      (*dvMaska) =
    break;
#define UMIN_CONFIGURATION_END 389
  case UMIN_CONFIGURATION_END:
    (*outMaska) = RNG_BIG_START_UMIN2;
    (*dvMaska) = RANGE_SMALL_A01_START_UMIN2;
    break;

//  count_bit = 8;
#define UMAX_CONFIGURATION_BEGIN 432
  case UMAX_CONFIGURATION_BEGIN:
    (*outMaska) = RNG_BIG_BLOCK_UMAX1;
    (*dvMaska) = RANGE_SMALL_A01_BLOCK_UMAX1;
    break;
  case 433:
    (*outMaska) = RNG_BIG_PO_UMAX1;
//      (*dvMaska) =
    break;
  case 434:
    (*outMaska) = RNG_BIG_UMAX1;
//      (*dvMaska) =
    break;

//  count_bit = 8;
  case 448:
    (*outMaska) = RNG_BIG_BLOCK_UMAX2;
    (*dvMaska) = RANGE_SMALL_A01_BLOCK_UMAX2;
    break;
  case 449:
    (*outMaska) = RNG_BIG_PO_UMAX2;
//      (*dvMaska) =
    break;
#define UMAX_CONFIGURATION_END 450
  case UMAX_CONFIGURATION_END:
    (*outMaska) = RNG_BIG_UMAX2;
//      (*dvMaska) =
    break;

#define  CMD_ITEM_HOLES450 if(item>450 && item<560) continue;

//  count_bit = 3;
#define APV_CONFIGURATION_BEGIN 560
  case APV_CONFIGURATION_BEGIN:
    (*outMaska) = RNG_BIG_STAT_BLK_APV;
    (*dvMaska) = RANGE_SMALL_A01_STAT_BLK_APV;
    break;

//  count_bit = 3;
  case 562:
    (*outMaska) = RNG_BIG_APV1;
//        (*dvMaska) =
    break;
  case 563:
    (*outMaska) = RNG_BIG_APV2;
//        (*dvMaska) =
    break;
  case 564:
    (*outMaska) = RNG_BIG_APV3;
//        (*dvMaska) =
    break;
  case 565:
    (*outMaska) = RNG_BIG_APV4;
//        (*dvMaska) =
    break;
#define APV_CONFIGURATION_END 566
  case APV_CONFIGURATION_END:
    (*outMaska) = RNG_BIG_APV_WORK;
//        (*dvMaska) =
    break;

//  count_bit = 5;
#define UROV_CONFIGURATION_BEGIN 592
  case UROV_CONFIGURATION_BEGIN:
    (*outMaska) = RNG_BIG_PUSK_UROV_VID_DV;
    (*dvMaska) = RANGE_SMALL_A01_PUSK_UROV_VID_DV;
    break;
  case 593:
    (*outMaska) = RNG_BIG_UROV1;
//        (*dvMaska) =
    break;
  case 594:
    (*outMaska) = RNG_BIG_UROV2;
//        (*dvMaska) =
    break;
#define UROV_CONFIGURATION_END 595
  case UROV_CONFIGURATION_END:
    (*outMaska) = RNG_BIG_PO_UROV;
//        (*dvMaska) =
    break;

#define  CMD_ITEM_HOLES595 if(item>595 && item<768) continue;

//  count_bit = 1;
#define ACHR_CHAPV_CONFIGURATION_BEGIN 768
  case ACHR_CHAPV_CONFIGURATION_BEGIN:
    (*outMaska) = RNG_BIG_ACHR_CHAPV_VID_DV;
    (*dvMaska) = RANGE_SMALL_A01_ACHR_CHAPV_VID_DV;
    break;
  case 769:
    (*outMaska) = RNG_BIG_BLOCK_ACHR1;
    (*dvMaska) = RANGE_SMALL_A01_BLOCK_ACHR1;
    break;
  case 770:
    (*outMaska) = RNG_BIG_BLOCK_ACHR2;
    (*dvMaska) = RANGE_SMALL_A01_BLOCK_ACHR2;
    break;
  case 771:
    (*outMaska) = RNG_BIG_VN_BLOCK_CHAPV;
//        (*dvMaska) =
    break;
  case 772:
    (*outMaska) = RNG_BIG_PO_ACHR1;
//        (*dvMaska) =
    break;
  case 773:
    (*outMaska) = RNG_BIG_PO_ACHR2;
//        (*dvMaska) =
    break;
  case 774:
    (*outMaska) = RNG_BIG_ACHR_CHAPV1;
//        (*dvMaska) =
    break;
  case 775:
    (*outMaska) = RNG_BIG_ACHR_CHAPV2;
//        (*dvMaska) =
    break;
  case 776:
    (*outMaska) = RNG_BIG_RAZR_CHAPV;
//        (*dvMaska) =
    break;
  case 777:
    (*outMaska) = RNG_BIG_PO_CHAPV1;
//        (*dvMaska) =
    break;
#define ACHR_CHAPV_CONFIGURATION_END 778
  case ACHR_CHAPV_CONFIGURATION_END:
    (*outMaska) = RNG_BIG_PO_CHAPV2;
//        (*dvMaska) =
    break;

//IF ВСТАВКА 896-919

//  count_bit = 1;
#define DZO_CONFIGURATION_BEGIN 944
  case DZO_CONFIGURATION_BEGIN:
    (*outMaska) = RNG_BIG_BLK_DZO1;
//        (*dvMaska) =
    break;
  case 945:
    (*outMaska) = RNG_BIG_BLOCK_DZO1;
    (*dvMaska) = RANGE_SMALL_A01_BLK_DZO1;
    break;
  case 946:
    (*outMaska) = RNG_BIG_I_BLK_DZO_I_LESS_IP_0_P_5;
//        (*dvMaska) =
    break;
  case 947:
    (*outMaska) = RNG_BIG_BLK_DZO1_I_OSN;
//        (*dvMaska) =
    break;
  case 948:
    (*outMaska) = RNG_BIG_ZBR_BLOCK_DZO1_I_O;
    (*dvMaska) = RANGE_SMALL_A01_ZBR_BLK_DZO1_I_O;
    break;
  case 949:
    (*outMaska) = RNG_BIG_PO2_I_BLK_DZO;
//        (*dvMaska) =
    break;
  case 950:
    (*outMaska) = RNG_BIG_BLK_DZO1_I_O3G_DIV_I_O1G_DZO;
//        (*dvMaska) =
    break;
  case 951:
    (*outMaska) = RNG_BIG_ZBR_BLOCK_DZO1_I_O_3G;
    (*dvMaska) = RANGE_SMALL_A01_ZBR_BLK_DZO1_I_O_3G;
    break;
  case 952:
    (*outMaska) = RNG_BIG_I_O3G_DIV_I_O1G_DZO;
//        (*dvMaska) =
    break;
  case 953:
    (*outMaska) = RNG_BIG_PO_DZO1;
//        (*dvMaska) =
    break;
  case 954:
    (*outMaska) = RNG_BIG_DZO1;
//        (*dvMaska) =
    break;
  case 955:
    (*outMaska) = RNG_BIG_PO_AMCZ_DZO1;
//        (*dvMaska) =
    break;
  case 956:
    (*outMaska) = RNG_BIG_AMCZ_DZO1;
//        (*dvMaska) =
    break;

//  count_bit = 1;
  case 960:
    (*outMaska) = RNG_BIG_BLK_DZO2;
//        (*dvMaska) =
    break;
  case 961:
    (*outMaska) = RNG_BIG_BLOCK_DZO2;
    (*dvMaska) = RANGE_SMALL_A01_BLK_DZO2;
    break;
  case 962:
    (*outMaska) = RNG_BIG_BLK_DZO2_I_OSN_3G_DIV_1G;
//        (*dvMaska) =
    break;
  case 963:
    (*outMaska) = RNG_BIG_ZBR_BLOCK_DZO2_I_O_3G;
    (*dvMaska) = RANGE_SMALL_A01_ZBR_BLK_DZO2_I_O_3G;
    break;
  case 964:
    (*outMaska) = RNG_BIG_BLOCK_PR_DZO2;
    (*dvMaska) = RANGE_SMALL_A01_BLK_USK_DZO2;
    break;
  case 965:
    (*outMaska) = RNG_BIG_OP_PR_DZO2;
    (*dvMaska) = RANGE_SMALL_A01_OP_USK_DZO2;
    break;
  case 966:
    (*outMaska) = RNG_BIG_SECTOR_DIR_DZO2;
//        (*dvMaska) =
    break;
  case 967:
    (*outMaska) = RNG_BIG_SECTOR_INV_DZO2;
//        (*dvMaska) =
    break;
  case 968:
    (*outMaska) = RNG_BIG_PO_DIR_DZO2;
//        (*dvMaska) =
    break;
  case 969:
    (*outMaska) = RNG_BIG_PO_INV_DZO2;
//        (*dvMaska) =
    break;
  case 970:
    (*outMaska) = RNG_BIG_DZO2;
//        (*dvMaska) =
    break;
  case 971:
    (*outMaska) = RNG_BIG_PO_AMCZ_DZO2;
//        (*dvMaska) =
    break;
  case 972:
    (*outMaska) = RNG_BIG_AMCZ_DZO2;
//        (*dvMaska) =
    break;

//  count_bit = 1;
  case 976:
    (*outMaska) = RNG_BIG_BLK_DZO3;
//        (*dvMaska) =
    break;
  case 977:
    (*outMaska) = RNG_BIG_BLOCK_DZO3;
    (*dvMaska) = RANGE_SMALL_A01_BLK_DZO3;
    break;
  case 978:
    (*outMaska) = RNG_BIG_BLK_DZO3_I_OSN_3G_DIV_1G;
//        (*dvMaska) =
    break;
  case 979:
    (*outMaska) = RNG_BIG_ZBR_BLOCK_DZO3_I_O_3G;
    (*dvMaska) = RANGE_SMALL_A01_ZBR_BLK_DZO3_I_O_3G;
    break;
  case 980:
    (*outMaska) = RNG_BIG_BLOCK_PR_DZO3;
    (*dvMaska) = RANGE_SMALL_A01_BLK_USK_DZO3;
    break;
  case 981:
    (*outMaska) = RNG_BIG_OP_PR_DZO3;
    (*dvMaska) = RANGE_SMALL_A01_OP_USK_DZO3;
    break;
  case 982:
    (*outMaska) = RNG_BIG_SECTOR_DIR_DZO3;
//        (*dvMaska) =
    break;
  case 983:
    (*outMaska) = RNG_BIG_SECTOR_INV_DZO3;
//        (*dvMaska) =
    break;
  case 984:
    (*outMaska) = RNG_BIG_PO_DIR_DZO3;
//        (*dvMaska) =
    break;
  case 985:
    (*outMaska) = RNG_BIG_PO_INV_DZO3;
//        (*dvMaska) =
    break;
  case 986:
    (*outMaska) = RNG_BIG_DZO3;
//        (*dvMaska) =
    break;
  case 987:
    (*outMaska) = RNG_BIG_PO_AMCZ_DZO3;
//        (*dvMaska) =
    break;
  case 988:
    (*outMaska) = RNG_BIG_AMCZ_DZO3;
//        (*dvMaska) =
    break;

//  count_bit = 1;
  case 992:
    (*outMaska) = RNG_BIG_BLK_DZO4;
//        (*dvMaska) =
    break;
  case 993:
    (*outMaska) = RNG_BIG_BLOCK_DZO4;
    (*dvMaska) = RANGE_SMALL_A01_BLK_DZO4;
    break;
  case 994:
    (*outMaska) = RNG_BIG_BLK_DZO4_I_OSN_3G_DIV_1G;
//        (*dvMaska) =
    break;
  case 995:
    (*outMaska) = RNG_BIG_ZBR_BLOCK_DZO4_I_O_3G;
    (*dvMaska) = RANGE_SMALL_A01_ZBR_BLK_DZO4_I_O_3G;
    break;

//  count_bit = 1;
  case 998:
    (*outMaska) = RNG_BIG_NAPRYM_DIR_DZO4;
//        (*dvMaska) =
    break;
  case 999:
    (*outMaska) = RNG_BIG_NAPRYM_INV_DZO4;
//        (*dvMaska) =
    break;
  case 1000:
    (*outMaska) = RNG_BIG_PO_DIR_DZO4;
//        (*dvMaska) =
    break;
  case 1001:
    (*outMaska) = RNG_BIG_PO_INV_DZO4;
//        (*dvMaska) =
    break;
  case 1002:
    (*outMaska) = RNG_BIG_DZO4;
//        (*dvMaska) =
    break;
  case 1003:
    (*outMaska) = RNG_BIG_PO_AMCZ_DZO4;
//        (*dvMaska) =
    break;
  case 1004:
    (*outMaska) = RNG_BIG_AMCZ_DZO4;
//        (*dvMaska) =
    break;

//  count_bit = 1;
  case 1008:
    (*outMaska) = RNG_BIG_ZVN_NESPR_DZO;
    (*dvMaska) = RANGE_SMALL_A01_NKN_DZO;
    break;
  case 1009:
    (*outMaska) = RNG_BIG_NKN_DZO;
//    (*dvMaska) =;
    break;
  case 1010:
    (*outMaska) = RNG_BIG_U_DZO_U_O_LESS_UP_0_25P_UN;
//        (*dvMaska) =
    break;
  case 1011:
    (*outMaska) = RNG_BIG_CNKN_DZO;
//        (*dvMaska) =
    break;

//  count_bit = 1;
  case 1040:
    (*outMaska) = RNG_BIG_BLK_DZR1;
//    (*dvMaska) = 
    break;
  case 1041:
    (*outMaska) = RNG_BIG_BLOCK_DZR1;
    (*dvMaska) = RANGE_SMALL_A01_BLK_DZR1;
    break;
  case 1042:
    (*outMaska) = RNG_BIG_I_BLK_DZR_I_LESS_0_P_5A;
//        (*dvMaska) =
    break;
  case 1043:
    (*outMaska) = RNG_BIG_BLK_DZR1_I_RSV;
//        (*dvMaska) =
    break;
  case 1044:
    (*outMaska) = RNG_BIG_ZBR_BLOCK_DZR1_I_R;
//        (*dvMaska) =
    break;
  case 1045:
    (*outMaska) = RNG_BIG_PO2_I_BLK_DZR1;
//        (*dvMaska) =
    break;
  case 1046:
    (*outMaska) = RNG_BIG_BLK_DZR1_I_RSV_3G_DIV_1G_DZR;
//        (*dvMaska) =
    break;
  case 1047:
    (*outMaska) = RNG_BIG_ZBR_BLOCK_DZR1_I_R_3G;
    (*dvMaska) = RANGE_SMALL_A01_ZBR_BLK_DZR1_I_O_3G;
    break;
  case 1048:
    (*outMaska) = RNG_BIG_I_RSV_3G_DIV_1G_DZR;
//        (*dvMaska) =
    break;
  case 1049:
    (*outMaska) = RNG_BIG_PO_DZR1;
//        (*dvMaska) =
    break;
  case 1050:
    (*outMaska) = RNG_BIG_DZR1;
//        (*dvMaska) =
    break;
  case 1051:
    (*outMaska) = RNG_BIG_PO_AMCZ_DZR1;
//        (*dvMaska) =
    break;
  case 1052:
    (*outMaska) = RNG_BIG_AMCZ_DZR1;
//        (*dvMaska) =
    break;

//  count_bit = 1;
  case 1056:
    (*outMaska) = RNG_BIG_BLK_DZR2;
//        (*dvMaska) =
    break;
  case 1057:
    (*outMaska) = RNG_BIG_BLOCK_DZR2;
    (*dvMaska) = RANGE_SMALL_A01_BLK_DZR2;
    break;
  case 1058:
    (*outMaska) = RNG_BIG_BLK_DZR2_I_RSV_3G_DIV_1G;
//        (*dvMaska) =
    break;
  case 1059:
    (*outMaska) = RNG_BIG_ZBR_BLOCK_DZR2_I_R_3G;
    (*dvMaska) = RANGE_SMALL_A01_ZBR_BLK_DZR2_I_O_3G;
    break;
  case 1060:
    (*outMaska) = RNG_BIG_BLOCK_PR_DZR2;
    (*dvMaska) = RANGE_SMALL_A01_BLK_USK_DZR2;
    break;
  case 1061:
    (*outMaska) = RNG_BIG_OP_PR_DZR2;
    (*dvMaska) = RANGE_SMALL_A01_OP_USK_DZR2;
    break;
  case 1062:
    (*outMaska) = RNG_BIG_SECTOR_DIR_DZR2;
//        (*dvMaska) =
    break;
  case 1063:
    (*outMaska) = RNG_BIG_SECTOR_INV_DZR2;
//        (*dvMaska) =
    break;
  case 1064:
    (*outMaska) = RNG_BIG_PO_DIR_DZR2;
//        (*dvMaska) =
    break;
  case 1065:
    (*outMaska) = RNG_BIG_PO_INV_DZR2;
//        (*dvMaska) =
    break;
  case 1066:
    (*outMaska) = RNG_BIG_DZR2;
//        (*dvMaska) =
    break;
  case 1067:
    (*outMaska) = RNG_BIG_PO_AMCZ_DZR2;
//        (*dvMaska) =
    break;
  case 1068:
    (*outMaska) = RNG_BIG_AMCZ_DZR2;
//        (*dvMaska) =
    break;

//  count_bit = 1;
  case 1072:
    (*outMaska) = RNG_BIG_BLK_DZR3;
//        (*dvMaska) =
    break;
  case 1073:
    (*outMaska) = RNG_BIG_BLOCK_DZR3;
    (*dvMaska) = RANGE_SMALL_A01_BLK_DZR3;
    break;
  case 1074:
    (*outMaska) = RNG_BIG_BLK_DZR3_I_RSV_3G_DIV_1G;
//        (*dvMaska) =
    break;
  case 1075:
    (*outMaska) = RNG_BIG_ZBR_BLOCK_DZR3_I_R_3G;
    (*dvMaska) = RANGE_SMALL_A01_ZBR_BLK_DZR3_I_O_3G;
    break;
  case 1076:
    (*outMaska) = RNG_BIG_BLOCK_PR_DZR3;
    (*dvMaska) = RANGE_SMALL_A01_BLK_USK_DZR3;
    break;
  case 1077:
    (*outMaska) = RNG_BIG_OP_PR_DZR3;
    (*dvMaska) = RANGE_SMALL_A01_OP_USK_DZR3;
    break;
  case 1078:
    (*outMaska) = RNG_BIG_SECTOR_DIR_DZR3;
//        (*dvMaska) =
    break;
  case 1079:
    (*outMaska) = RNG_BIG_SECTOR_INV_DZR3;
//        (*dvMaska) =
    break;
  case 1080:
    (*outMaska) = RNG_BIG_PO_DIR_DZR3;
//        (*dvMaska) =
    break;
  case 1081:
    (*outMaska) = RNG_BIG_PO_INV_DZR3;
//        (*dvMaska) =
    break;
  case 1082:
    (*outMaska) = RNG_BIG_DZR3;
//        (*dvMaska) =
    break;
  case 1083:
    (*outMaska) = RNG_BIG_PO_AMCZ_DZR3;
//        (*dvMaska) =
    break;
  case 1084:
    (*outMaska) = RNG_BIG_AMCZ_DZR3;
//        (*dvMaska) =
    break;

//  count_bit = 1;
  case 1088:
    (*outMaska) = RNG_BIG_ZVN_NESPR_DZR;
    (*dvMaska) = RANGE_SMALL_A01_ZOVN_NESPRN_DZR;
    break;
  case 1089:
    (*outMaska) = RNG_BIG_NKN_DZR;
//        (*dvMaska) =
    break;
  case 1090:
    (*outMaska) = RNG_BIG_U_DZR_U_RSV_LESS_0_25P_UN;
//        (*dvMaska) =
    break;
  case 1091:
    (*outMaska) = RNG_BIG_CNKN_DZR;
//        (*dvMaska) =
    break;

//  count_bit = 3;
#define  IMUNITET_BITACMD896 1200
  case IMUNITET_BITACMD896:
    (*outMaska) = RNG_BIG_VKL_VVO;
    (*dvMaska) = RANGE_SMALL_A01_VKL_VVO;
    break;
#define  IMUNITET_BITACMD897 1201
  case IMUNITET_BITACMD897:
    (*outMaska) = RNG_BIG_OTKL_VV_VVO;
    (*dvMaska) = RANGE_SMALL_A01_OTKL_VVO;
    break;
  case 1202:
    (*outMaska) = RNG_BIG_BLOCK_VKL_VVO;
    (*dvMaska) = RANGE_SMALL_A01_BLOCK_VKL_VVO;
    break;

//  count_bit = 15;
  case 1204:
    (*outMaska) = RNG_BIG_WORK_BO_VVO;
//        (*dvMaska) =
    break;
  case 1205:
    (*outMaska) = RNG_BIG_WORK_BV_VVO;
//        (*dvMaska) =
    break;
  case 1206:
    (*outMaska) = RNG_BIG_STATE_VVO;
    (*dvMaska) = RANGE_SMALL_A01_STATE_VVO;
    break;
  case 1207:
    (*outMaska) = RNG_BIG_PRYVID_VVO;
//        (*dvMaska) =
    break;
  case 1208:
    (*outMaska) = RNG_BIG_CTRL_VKL_VVO;
    (*dvMaska) = RANGE_SMALL_A01_CTRL_VKL_VVO;
    break;
  case 1209:
    (*outMaska) = RNG_BIG_CTRL_OTKL_VVO;
    (*dvMaska) = RANGE_SMALL_A01_CTRL_OTKL_VVO;
    break;
  case 1210:
    (*outMaska) = RNG_BIG_PEREVYSHCHENNJA_I_NOM_VYMK;
//        (*dvMaska) =
    break;
  case 1211:
    (*outMaska) = RNG_BIG_KRYTYCHNYJ_RESURS_VVO;
//        (*dvMaska) =
    break;
  case 1212:
    (*outMaska) = RNG_BIG_VYCHERPANYJ_RESURS_VVO;
//        (*dvMaska) =
    break;

#define  IMUNITET_BITACMD909 1213

//  count_bit = 12;
  case 1221:
    (*outMaska) = RNG_BIG_VIDKL_VID_ZAKHYSTIV_VVO;
//        (*dvMaska) =
    break;

//  count_bit = 12;
#define  IMUNITET_BITACMD928 1232
  case IMUNITET_BITACMD928:
    (*outMaska) = RNG_BIG_VKL_VVR;//Включение ВВ2
    (*dvMaska) = RANGE_SMALL_A01_VKL_VVP;
    break;
#define  IMUNITET_BITACMD929 1233
  case IMUNITET_BITACMD929:
    (*outMaska) = RNG_BIG_OTKL_VV_VVR;//Otключение ВВ2
    (*dvMaska) = RANGE_SMALL_A01_OTKL_VVP;
    break;
  case 1234:
    (*outMaska) = RNG_BIG_BLOCK_VKL_VVP;//block Включение ВВ2
    (*dvMaska) = RANGE_SMALL_A01_BLOCK_VKL_VVP;
    break;

//  count_bit = 12;
  case 1236:
    (*outMaska) = RNG_BIG_WORK_BO_VVR;
//        (*dvMaska) =
    break;
  case 1237:
    (*outMaska) = RNG_BIG_WORK_BV_VVR;
//        (*dvMaska) =
    break;
  case 1238:
    (*outMaska) = RNG_BIG_STATE_VVR;
    (*dvMaska) = RANGE_SMALL_A01_STATE_VVP;
    break;
  case 1239:
    (*outMaska) = RNG_BIG_PRYVID_VVR;
//        (*dvMaska) =
    break;
  case 1240:
    (*outMaska) = RNG_BIG_CTRL_VKL_VVR;
    (*dvMaska) = RANGE_SMALL_A01_CTRL_VKL_VVP;
    break;
  case 1241:
    (*outMaska) = RNG_BIG_CTRL_OTKL_VVR;
    (*dvMaska) = RANGE_SMALL_A01_CTRL_OTKL_VVP;
    break;

//  count_bit = 12;
  case 1251:
    (*outMaska) = RNG_BIG_VIDKL_VID_ZAKHYSTIV_VVR;
//        (*dvMaska) =
    break;

//  count_bit = 12;
  case 1296:
    (*outMaska) = RNG_BIG_DEFECT;
//        (*dvMaska) =
    break;
  case 1297:
    (*outMaska) = RNG_BIG_AVAR_DEFECT;
//        (*dvMaska) =
    break;
#define  IMUNITET_BITACMD978 1298
  case IMUNITET_BITACMD978:
    (*outMaska) = RNG_BIG_RESET_LEDS;
    (*dvMaska) = RANGE_SMALL_A01_RESET_LEDS;
    break;
#define  IMUNITET_BITACMD979 1299
  case IMUNITET_BITACMD979:
    (*outMaska) = RNG_BIG_RESET_RELES;
    (*dvMaska) = RANGE_SMALL_A01_RESET_RELES;
    break;

#define  IMUNITET_BITACMD980 1300

  case 1301:
    (*outMaska) = RNG_BIG_SETTINGS_CHANGED;
//        (*dvMaska) =
    break;

#define  BITACMD1302 1302

#define PASSWORD_SETCMD 1303

  case 1304:
    (*outMaska) = RNG_BIG_MISCEVE_DYSTANCIJNE;
    (*dvMaska) = RANGE_SMALL_A01_MISCEVE_DYSTANCIJNE;
    break;
  case 1305:
    (*outMaska) = RNG_BIG_WORK_A_REJESTRATOR;
//        (*dvMaska) =
    break;
  case 1306:
    (*outMaska) = RNG_BIG_WORK_D_REJESTRATOR;
//        (*dvMaska) =
    break;

//  count_bit = 1;
  case 1317:
    (*outMaska) = RNG_BIG_ERROR_CONF_EL;
//        (*dvMaska) =
    break;


//  count_bit = 5;
  case 1327:
    (*outMaska) = RNG_BIG_BLK_GRUP_USTAVOK_VID_ZACHYSTIV;
//        (*dvMaska) =
    break;

  case 1328:
    (*outMaska) = RNG_BIG_INVERS_DV_GRUPA_USTAVOK;
//        (*dvMaska) =
    break;
  case 1329:
    (*outMaska) = RNG_BIG_READY_TU;
//        (*dvMaska) =
    break;
#define  IMUNITET_BITACMD1006 1330
  case IMUNITET_BITACMD1006:
    (*outMaska) = RNG_BIG_RESET_BLOCK_READY_TU_VID_ZAHYSTIV;
    (*dvMaska) = RANGE_SMALL_A01_RESET_BLOCK_READY_TU_VID_ZAHYSTIV;
    break;

  case 1331:
    (*outMaska) = RNG_BIG_NKNO;
//        (*dvMaska) =
    break;
  case 1332:
    (*outMaska) = RNG_BIG_NKNR;
//        (*dvMaska) =
    break;

//  count_bit = 40;
#define EL_CONFIGURATION_BEGIN 1360
  case EL_CONFIGURATION_BEGIN:
    (*outMaska) = RNG_BIG_DF1_IN;
    (*dvMaska) = RANGE_SMALL_A01_DF1_IN;
    if(actControl==(1+SOURCEMARKER_MFT)) isValid = 0;
    break;
  case 1361:
    (*outMaska) = RNG_BIG_DF2_IN;
    (*dvMaska) = RANGE_SMALL_A01_DF2_IN;
    if(actControl==(2+SOURCEMARKER_MFT)) isValid = 0;
    break;
  case 1362:
    (*outMaska) = RNG_BIG_DF3_IN;
    (*dvMaska) = RANGE_SMALL_A01_DF3_IN;
    if(actControl==(3+SOURCEMARKER_MFT)) isValid = 0;
    break;
  case 1363:
    (*outMaska) = RNG_BIG_DF4_IN;
    (*dvMaska) = RANGE_SMALL_A01_DF4_IN;
    if(actControl==(4+SOURCEMARKER_MFT)) isValid = 0;
    break;
  case 1364:
    (*outMaska) = RNG_BIG_DF5_IN;
    (*dvMaska) = RANGE_SMALL_A01_DF5_IN;
    if(actControl==(5+SOURCEMARKER_MFT)) isValid = 0;
    break;
  case 1365:
    (*outMaska) = RNG_BIG_DF6_IN;
    (*dvMaska) = RANGE_SMALL_A01_DF6_IN;
    if(actControl==(6+SOURCEMARKER_MFT)) isValid = 0;
    break;
  case 1366:
    (*outMaska) = RNG_BIG_DF7_IN;
    (*dvMaska) = RANGE_SMALL_A01_DF7_IN;
    if(actControl==(7+SOURCEMARKER_MFT)) isValid = 0;
    break;
  case 1367:
    (*outMaska) = RNG_BIG_DF8_IN;
    (*dvMaska) = RANGE_SMALL_A01_DF8_IN;
    if(actControl==(8+SOURCEMARKER_MFT)) isValid = 0;
    break;
  case 1368:
    (*outMaska) = RNG_BIG_DF9_IN;
    (*dvMaska) = RANGE_SMALL_A01_DF9_IN;
    if(actControl==(9+SOURCEMARKER_MFT)) isValid = 0;
    break;
  case 1369:
    (*outMaska) = RNG_BIG_DF10_IN;
    (*dvMaska) = RANGE_SMALL_A01_DF10_IN;
    if(actControl==(10+SOURCEMARKER_MFT)) isValid = 0;
    break;
  case 1370:
    (*outMaska) = RNG_BIG_DF11_IN;
    (*dvMaska) = RANGE_SMALL_A01_DF11_IN;
    if(actControl==(11+SOURCEMARKER_MFT)) isValid = 0;
    break;
  case 1371:
    (*outMaska) = RNG_BIG_DF12_IN;
    (*dvMaska) = RANGE_SMALL_A01_DF12_IN;
    if(actControl==(12+SOURCEMARKER_MFT)) isValid = 0;
    break;
  case 1372:
    (*outMaska) = RNG_BIG_DF13_IN;
    (*dvMaska) = RANGE_SMALL_A01_DF13_IN;
    if(actControl==(13+SOURCEMARKER_MFT)) isValid = 0;
    break;
  case 1373:
    (*outMaska) = RNG_BIG_DF14_IN;
    (*dvMaska) = RANGE_SMALL_A01_DF14_IN;
    if(actControl==(14+SOURCEMARKER_MFT)) isValid = 0;
    break;
  case 1374:
    (*outMaska) = RNG_BIG_DF15_IN;
    (*dvMaska) = RANGE_SMALL_A01_DF15_IN;
    if(actControl==(15+SOURCEMARKER_MFT)) isValid = 0;
    break;
  case 1375:
    (*outMaska) = RNG_BIG_DF16_IN;
    (*dvMaska) = RANGE_SMALL_A01_DF16_IN;
    if(actControl==(16+SOURCEMARKER_MFT)) isValid = 0;
    break;

  case 1376:
    (*outMaska) = RNG_BIG_DF1_RST;
    (*dvMaska) = RANGE_SMALL_A01_DF1_RST;
    if(actControl==(1+SOURCEMARKER_MFT)) isValid = 0;
    break;
  case 1377:
    (*outMaska) = RNG_BIG_DF2_RST;
    (*dvMaska) = RANGE_SMALL_A01_DF2_RST;
    if(actControl==(2+SOURCEMARKER_MFT)) isValid = 0;
    break;
  case 1378:
    (*outMaska) = RNG_BIG_DF3_RST;
    (*dvMaska) = RANGE_SMALL_A01_DF3_RST;
    if(actControl==(3+SOURCEMARKER_MFT)) isValid = 0;
    break;
  case 1379:
    (*outMaska) = RNG_BIG_DF4_RST;
    (*dvMaska) = RANGE_SMALL_A01_DF4_RST;
    if(actControl==(4+SOURCEMARKER_MFT)) isValid = 0;
    break;
  case 1380:
    (*outMaska) = RNG_BIG_DF5_RST;
    (*dvMaska) = RANGE_SMALL_A01_DF5_RST;
    if(actControl==(5+SOURCEMARKER_MFT)) isValid = 0;
    break;
  case 1381:
    (*outMaska) = RNG_BIG_DF6_RST;
    (*dvMaska) = RANGE_SMALL_A01_DF6_RST;
    if(actControl==(6+SOURCEMARKER_MFT)) isValid = 0;
    break;
  case 1382:
    (*outMaska) = RNG_BIG_DF7_RST;
    (*dvMaska) = RANGE_SMALL_A01_DF7_RST;
    if(actControl==(7+SOURCEMARKER_MFT)) isValid = 0;
    break;
  case 1383:
    (*outMaska) = RNG_BIG_DF8_RST;
    (*dvMaska) = RANGE_SMALL_A01_DF8_RST;
    if(actControl==(8+SOURCEMARKER_MFT)) isValid = 0;
    break;
  case 1384:
    (*outMaska) = RNG_BIG_DF9_RST;
    (*dvMaska) = RANGE_SMALL_A01_DF9_RST;
    if(actControl==(9+SOURCEMARKER_MFT)) isValid = 0;
    break;
  case 1385:
    (*outMaska) = RNG_BIG_DF10_RST;
    (*dvMaska) = RANGE_SMALL_A01_DF10_RST;
    if(actControl==(10+SOURCEMARKER_MFT)) isValid = 0;
    break;
  case 1386:
    (*outMaska) = RNG_BIG_DF11_RST;
    (*dvMaska) = RANGE_SMALL_A01_DF11_RST;
    if(actControl==(11+SOURCEMARKER_MFT)) isValid = 0;
    break;
  case 1387:
    (*outMaska) = RNG_BIG_DF12_RST;
    (*dvMaska) = RANGE_SMALL_A01_DF12_RST;
    if(actControl==(12+SOURCEMARKER_MFT)) isValid = 0;
    break;
  case 1388:
    (*outMaska) = RNG_BIG_DF13_RST;
    (*dvMaska) = RANGE_SMALL_A01_DF13_RST;
    if(actControl==(13+SOURCEMARKER_MFT)) isValid = 0;
    break;
  case 1389:
    (*outMaska) = RNG_BIG_DF14_RST;
    (*dvMaska) = RANGE_SMALL_A01_DF14_RST;
    if(actControl==(14+SOURCEMARKER_MFT)) isValid = 0;
    break;
  case 1390:
    (*outMaska) = RNG_BIG_DF15_RST;
    (*dvMaska) = RANGE_SMALL_A01_DF15_RST;
    if(actControl==(15+SOURCEMARKER_MFT)) isValid = 0;
    break;
  case 1391:
    (*outMaska) = RNG_BIG_DF16_RST;
    (*dvMaska) = RANGE_SMALL_A01_DF16_RST;
    if(actControl==(16+SOURCEMARKER_MFT)) isValid = 0;
    break;

  case 1392:
    (*outMaska) = RNG_BIG_DF1_OUT;
//        (*dvMaska) =
    if(actControl==(1+SOURCEMARKER_MFT)) isValid = 0;
    break;
  case 1393:
    (*outMaska) = RNG_BIG_DF2_OUT;
//        (*dvMaska) =
    if(actControl==(2+SOURCEMARKER_MFT)) isValid = 0;
    break;
  case 1394:
    (*outMaska) = RNG_BIG_DF3_OUT;
//        (*dvMaska) =
    if(actControl==(3+SOURCEMARKER_MFT)) isValid = 0;
    break;
  case 1395:
    (*outMaska) = RNG_BIG_DF4_OUT;
//        (*dvMaska) =
    if(actControl==(4+SOURCEMARKER_MFT)) isValid = 0;
    break;
  case 1396:
    (*outMaska) = RNG_BIG_DF5_OUT;
//        (*dvMaska) =
    if(actControl==(5+SOURCEMARKER_MFT)) isValid = 0;
    break;
  case 1397:
    (*outMaska) = RNG_BIG_DF6_OUT;
//        (*dvMaska) =
    if(actControl==(6+SOURCEMARKER_MFT)) isValid = 0;
    break;
  case 1398:
    (*outMaska) = RNG_BIG_DF7_OUT;
//        (*dvMaska) =
    if(actControl==(7+SOURCEMARKER_MFT)) isValid = 0;
    break;
  case 1399:
    (*outMaska) = RNG_BIG_DF8_OUT;
//        (*dvMaska) =
    if(actControl==(8+SOURCEMARKER_MFT)) isValid = 0;
    break;
  case 1400:
    (*outMaska) = RNG_BIG_DF9_OUT;
//        (*dvMaska) =
    if(actControl==(9+SOURCEMARKER_MFT)) isValid = 0;
    break;
  case 1401:
    (*outMaska) = RNG_BIG_DF10_OUT;
//        (*dvMaska) =
    if(actControl==(10+SOURCEMARKER_MFT)) isValid = 0;
    break;
  case 1402:
    (*outMaska) = RNG_BIG_DF11_OUT;
//        (*dvMaska) =
    if(actControl==(11+SOURCEMARKER_MFT)) isValid = 0;
    break;
  case 1403:
    (*outMaska) = RNG_BIG_DF12_OUT;
//        (*dvMaska) =
    if(actControl==(12+SOURCEMARKER_MFT)) isValid = 0;
    break;
  case 1404:
    (*outMaska) = RNG_BIG_DF13_OUT;
//        (*dvMaska) =
    if(actControl==(13+SOURCEMARKER_MFT)) isValid = 0;
    break;
  case 1405:
    (*outMaska) = RNG_BIG_DF14_OUT;
//        (*dvMaska) =
    if(actControl==(14+SOURCEMARKER_MFT)) isValid = 0;
    break;
  case 1406:
    (*outMaska) = RNG_BIG_DF15_OUT;
//        (*dvMaska) =
    if(actControl==(15+SOURCEMARKER_MFT)) isValid = 0;
    break;
  case 1407:
    (*outMaska) = RNG_BIG_DF16_OUT;
//        (*dvMaska) =
    if(actControl==(16+SOURCEMARKER_MFT)) isValid = 0;
    break;

  case 1408:
    (*outMaska) = RNG_BIG_DT1_SET;
    (*dvMaska) = RANGE_SMALL_A01_DT1_SET;
    if(actControl==(1+SOURCEMARKER_DTR)) isValid = 0;
    break;
  case 1409:
    (*outMaska) = RNG_BIG_DT2_SET;
    (*dvMaska) = RANGE_SMALL_A01_DT2_SET;
    if(actControl==(2+SOURCEMARKER_DTR)) isValid = 0;
    break;
  case 1410:
    (*outMaska) = RNG_BIG_DT3_SET;
    (*dvMaska) = RANGE_SMALL_A01_DT3_SET;
    if(actControl==(3+SOURCEMARKER_DTR)) isValid = 0;
    break;
  case 1411:
    (*outMaska) = RNG_BIG_DT4_SET;
    (*dvMaska) = RANGE_SMALL_A01_DT4_SET;
    if(actControl==(4+SOURCEMARKER_DTR)) isValid = 0;
    break;

//  count_bit = 40;
  case 1424:
    (*outMaska) = RNG_BIG_DT1_RESET;
    (*dvMaska) = RANGE_SMALL_A01_DT1_RESET;
    if(actControl==(1+SOURCEMARKER_DTR)) isValid = 0;
    break;
  case 1425:
    (*outMaska) = RNG_BIG_DT2_RESET;
    (*dvMaska) = RANGE_SMALL_A01_DT2_RESET;
    if(actControl==(2+SOURCEMARKER_DTR)) isValid = 0;
    break;
  case 1426:
    (*outMaska) = RNG_BIG_DT3_RESET;
    (*dvMaska) = RANGE_SMALL_A01_DT3_RESET;
    if(actControl==(3+SOURCEMARKER_DTR)) isValid = 0;
    break;
  case 1427:
    (*outMaska) = RNG_BIG_DT4_RESET;
    (*dvMaska) = RANGE_SMALL_A01_DT4_RESET;
    if(actControl==(4+SOURCEMARKER_DTR)) isValid = 0;
    break;

//  count_bit = 40;
  case 1440:
    (*outMaska) = RNG_BIG_DT1_OUT;
//        (*dvMaska) =
    if(actControl==(1+SOURCEMARKER_DTR)) isValid = 0;
    break;
  case 1441:
    (*outMaska) = RNG_BIG_DT2_OUT;
//        (*dvMaska) =
    if(actControl==(2+SOURCEMARKER_DTR)) isValid = 0;
    break;
  case 1442:
    (*outMaska) = RNG_BIG_DT3_OUT;
//        (*dvMaska) =
    if(actControl==(3+SOURCEMARKER_DTR)) isValid = 0;
    break;
  case 1443:
    (*outMaska) = RNG_BIG_DT4_OUT;
//        (*dvMaska) =
    if(actControl==(4+SOURCEMARKER_DTR)) isValid = 0;
    break;

//  count_bit = 40;
  case 1456:
    (*outMaska) = RNG_BIG_D_AND1;
//        (*dvMaska) =
    break;
  case 1457:
    (*outMaska) = RNG_BIG_D_AND2;
//        (*dvMaska) =
    break;
  case 1458:
    (*outMaska) = RNG_BIG_D_AND3;
//        (*dvMaska) =
    break;
  case 1459:
    (*outMaska) = RNG_BIG_D_AND4;
//        (*dvMaska) =
    break;
  case 1460:
    (*outMaska) = RNG_BIG_D_AND5;
//        (*dvMaska) =
    break;
  case 1461:
    (*outMaska) = RNG_BIG_D_AND6;
//        (*dvMaska) =
    break;
  case 1462:
    (*outMaska) = RNG_BIG_D_AND7;
//        (*dvMaska) =
    break;
  case 1463:
    (*outMaska) = RNG_BIG_D_AND8;
//        (*dvMaska) =
    break;

//  count_bit = 40;
  case 1472:
    (*outMaska) = RNG_BIG_D_OR1;
//        (*dvMaska) =
    break;
  case 1473:
    (*outMaska) = RNG_BIG_D_OR2;
//        (*dvMaska) =
    break;
  case 1474:
    (*outMaska) = RNG_BIG_D_OR3;
//        (*dvMaska) =
    break;
  case 1475:
    (*outMaska) = RNG_BIG_D_OR4;
//        (*dvMaska) =
    break;
  case 1476:
    (*outMaska) = RNG_BIG_D_OR5;
//        (*dvMaska) =
    break;
  case 1477:
    (*outMaska) = RNG_BIG_D_OR6;
//        (*dvMaska) =
    break;
  case 1478:
    (*outMaska) = RNG_BIG_D_OR7;
//        (*dvMaska) =
    break;
  case 1479:
    (*outMaska) = RNG_BIG_D_OR8;
//        (*dvMaska) =
    break;

//  count_bit = 40;
  case 1488:
    (*outMaska) = RNG_BIG_D_NOT1;
//        (*dvMaska) =
    break;
  case 1489:
    (*outMaska) = RNG_BIG_D_NOT2;
//        (*dvMaska) =
    break;
  case 1490:
    (*outMaska) = RNG_BIG_D_NOT3;
//        (*dvMaska) =
    break;
  case 1491:
    (*outMaska) = RNG_BIG_D_NOT4;
//        (*dvMaska) =
    break;
  case 1492:
    (*outMaska) = RNG_BIG_D_NOT5;
//        (*dvMaska) =
    break;
  case 1493:
    (*outMaska) = RNG_BIG_D_NOT6;
//        (*dvMaska) =
    break;
  case 1494:
    (*outMaska) = RNG_BIG_D_NOT7;
//        (*dvMaska) =
    break;
  case 1495:
    (*outMaska) = RNG_BIG_D_NOT8;
//        (*dvMaska) =
    break;
  case 1496:
    (*outMaska) = RNG_BIG_D_NOT9;
//        (*dvMaska) =
    break;
  case 1497:
    (*outMaska) = RNG_BIG_D_NOT10;
//        (*dvMaska) =
    break;
  case 1498:
    (*outMaska) = RNG_BIG_D_NOT11;
//        (*dvMaska) =
    break;
  case 1499:
    (*outMaska) = RNG_BIG_D_NOT12;
//        (*dvMaska) =
    break;
  case 1500:
    (*outMaska) = RNG_BIG_D_NOT13;
//        (*dvMaska) =
    break;
  case 1501:
    (*outMaska) = RNG_BIG_D_NOT14;
//        (*dvMaska) =
    break;
  case 1502:
    (*outMaska) = RNG_BIG_D_NOT15;
//        (*dvMaska) =
    break;
  case 1503:
    (*outMaska) = RNG_BIG_D_NOT16;
//        (*dvMaska) =
    break;
  case 1504:
    (*outMaska) = RNG_BIG_D_XOR1;
//        (*dvMaska) =
    break;
  case 1505:
    (*outMaska) = RNG_BIG_D_XOR2;
//        (*dvMaska) =
    break;
  case 1506:
    (*outMaska) = RNG_BIG_D_XOR3;
//        (*dvMaska) =
    break;
  case 1507:
    (*outMaska) = RNG_BIG_D_XOR4;
//        (*dvMaska) =
    break;
  case 1508:
    (*outMaska) = RNG_BIG_D_XOR5;
//        (*dvMaska) =
    break;
  case 1509:
    (*outMaska) = RNG_BIG_D_XOR6;
//        (*dvMaska) =
    break;
  case 1510:
    (*outMaska) = RNG_BIG_D_XOR7;
//        (*dvMaska) =
    break;
  case 1511:
    (*outMaska) = RNG_BIG_D_XOR8;
//        (*dvMaska) =
    break;

//  count_bit = 3;
  case 1568:
    (*outMaska) = RNG_BIG_LF1;
    (*dvMaska) = RANG_SMALL_A01_LF1;
    break;
  case 1569:
    (*outMaska) = RNG_BIG_LF2;
    (*dvMaska) = RANG_SMALL_A01_LF2;
    break;
  case 1570:
    (*outMaska) = RNG_BIG_LF3;
    (*dvMaska) = RANG_SMALL_A01_LF3;
    break;
  case 1571:
    (*outMaska) = RNG_BIG_LF4;
    (*dvMaska) = RANG_SMALL_A01_LF4;
    break;
  case 1572:
    (*outMaska) = RNG_BIG_LF5;
    (*dvMaska) = RANG_SMALL_A01_LF5;
    break;
  case 1573:
    (*outMaska) = RNG_BIG_LF6;
    (*dvMaska) = RANG_SMALL_A01_LF6;
    break;
  case 1574:
    (*outMaska) = RNG_BIG_LF7;
    (*dvMaska) = RANG_SMALL_A01_LF7;
    break;
  case 1575:
    (*outMaska) = RNG_BIG_LF8;
    (*dvMaska) = RANG_SMALL_A01_LF8;
    break;
  case 1576:
    (*outMaska) = RNG_BIG_LF9;
    (*dvMaska) = RANG_SMALL_A01_LF9;
    break;
  case 1577:
    (*outMaska) = RNG_BIG_LF10;
    (*dvMaska) = RANG_SMALL_A01_LF10;
    break;
  case 1578:
    (*outMaska) = RNG_BIG_LF11;
    (*dvMaska) = RANG_SMALL_A01_LF11;
    break;
  case 1579:
    (*outMaska) = RNG_BIG_LF12;
    (*dvMaska) = RANG_SMALL_A01_LF12;
    break;
  case 1580:
    (*outMaska) = RNG_BIG_LF13;
    (*dvMaska) = RANG_SMALL_A01_LF13;
    break;
  case 1581:
    (*outMaska) = RNG_BIG_LF14;
    (*dvMaska) = RANG_SMALL_A01_LF14;
    break;
  case 1582:
    (*outMaska) = RNG_BIG_LF15;
    (*dvMaska) = RANG_SMALL_A01_LF15;
    break;
#define EL_CONFIGURATION_END 1583
  case EL_CONFIGURATION_END:
    (*outMaska) = RNG_BIG_LF16;
    (*dvMaska) = RANG_SMALL_A01_LF16;
    break;

  }//switch
  if((*outMaska)!=-1)
  {
    if(inOffset>=MTZO_CONFIGURATION_BEGIN && inOffset<=MTZO_CONFIGURATION_END)
      if(!(edition_settings.configuration&(1<<MCZO_BIT_CONFIGURATION))) isValid = 0;

    if(inOffset>=MTZR_CONFIGURATION_BEGIN && inOffset<=MTZR_CONFIGURATION_END)
      if(!(edition_settings.configuration&(1<<MCZR_BIT_CONFIGURATION))) isValid = 0;

    if(inOffset>=ZDZ_CONFIGURATION_BEGIN && inOffset<=ZDZ_CONFIGURATION_END)
      if(!(edition_settings.configuration&(1<<ZDZ_VOD_BIT_CONFIGURATION))) isValid = 0;

    if(inOffset>=APV_CONFIGURATION_BEGIN && inOffset<=APV_CONFIGURATION_END)
      if(!(edition_settings.configuration&(1<<APV_BIT_CONFIGURATION))) isValid = 0;

    if(inOffset>=UROV_CONFIGURATION_BEGIN && inOffset<=UROV_CONFIGURATION_END)
      if(!(edition_settings.configuration&(1<<UROV_BIT_CONFIGURATION))) isValid = 0;

    if(inOffset>=ACHR_CHAPV_CONFIGURATION_BEGIN && inOffset<=ACHR_CHAPV_CONFIGURATION_END)
      if(!(edition_settings.configuration&(1<<ACHR_CHAPV_BIT_CONFIGURATION))) isValid = 0;

    if(inOffset>=UMIN_CONFIGURATION_BEGIN && inOffset<=UMIN_CONFIGURATION_END)
      if(!(edition_settings.configuration&(1<<UMIN_BIT_CONFIGURATION))) isValid = 0;

    if(inOffset>=UMAX_CONFIGURATION_BEGIN && inOffset<=UMAX_CONFIGURATION_END)
      if(!(edition_settings.configuration&(1<<UMAX_BIT_CONFIGURATION))) isValid = 0;

    if(inOffset>=EL_CONFIGURATION_BEGIN && inOffset<=EL_CONFIGURATION_END)
      if(!(edition_settings.configuration&(1<<EL_BIT_CONFIGURATION))) isValid = 0;

  }//if((*outMaska)!=-1)

//IF ВСТАВКА 896-919
  if(inOffset>=896 && inOffset<920)
  {
    if(!(edition_settings.configuration&(1<<UP_BIT_CONFIGURATION))) isValid = 0;
    int inupOffset = inOffset-896;
    int subObj = inupOffset/3;
    int offsetObj = inupOffset%3;
    
    switch(offsetObj)
    {
    case 0:
      (*outMaska) = RNG_BIG_BLOCK_UP1 + 3*subObj;
      (*dvMaska)  = RANGE_SMALL_A01_BLOCK_UP1 + 1*subObj;
      break;
    case 1:
      (*outMaska) = RNG_BIG_PO_UP1 + 3*subObj;
//        (*dvMaska) =
      break;
    case 2:
      (*outMaska) = RNG_BIG_UP1 + 3*subObj;
//        (*dvMaska) =
      break;
    }//switch
  }//if

  return isValid;
}//cmdFunc000(int inOffset, int *outMaska, int *dvMaska)

int getACMDSmallBeginAdr(void)
{
  return BEGIN_ADR_BIT;
}//getACMDSmallBeginAdr(void)
/**************************************/
//компонент Текущие активные и сработавшие функции
/**************************************/
void constructorACMDSmallComponent(COMPONENT_OBJ *acmdcomp)
{
  acmdsmallcomponent = acmdcomp;

  acmdsmallcomponent->getModbusRegister = getACMDSmallModbusRegister;//получить содержимое регистра
  acmdsmallcomponent->getModbusBit      = getACMDSmallModbusBit;//получить содержимое бита
  acmdsmallcomponent->setModbusRegister = setACMDSmallModbusRegister;// регистра
  acmdsmallcomponent->setModbusBit      = setACMDSmallModbusBit;// бита

  acmdsmallcomponent->postWriteAction = postACMDSmallWriteAction;//action после записи

}//constructorDOUTSmallComponent(COMPONENT_OBJ *doutcomp)

void decoderN_BIGACMDArrayLoader(void)
{
//декодировщик индекса бита в адрес modbus  для реле
  static int idxBit_decoderN_BIGACMDArrayLoader;
//  int ttt = N_BIG;
  if(idxBit_decoderN_BIGACMDArrayLoader>=N_BIG*32)
          return;

  int outMaska = -1;
  int dvMaska = -1;
  decoderN_BIGACMDArray[idxBit_decoderN_BIGACMDArrayLoader] = 0xFFFF;
 
  for(int item=0; item<(END_ADR_BIT-BEGIN_ADR_BIT+1); item++)
  {

  CMD_ITEM_HOLES183 
  CMD_ITEM_HOLES450 
  CMD_ITEM_HOLES595 

    cmdFunc000(item, &outMaska, &dvMaska, CLRACT_CONTROL);

    if(outMaska==idxBit_decoderN_BIGACMDArrayLoader)
    {
      decoderN_BIGACMDArray[idxBit_decoderN_BIGACMDArrayLoader] = (unsigned short) item;
      break;
    }//if
  }//for

  idxBit_decoderN_BIGACMDArrayLoader++;
}//decoderN_BIGACMDArrayLoader()

void decoderN_SMALLACMDArrayLoader(void)
{
//декодировщик индекса бита в адрес modbus  для ДВ
  static int idxBit_decoderN_SMALLACMDArrayLoader;
  if(idxBit_decoderN_SMALLACMDArrayLoader>=N_SMALL*32) return;

  int outMaska=-1;
  int dvMaska=-1;

  decoderN_SMALLACMDArray[idxBit_decoderN_SMALLACMDArrayLoader] = 0xFFFF;

  for(int item=0; item<(END_ADR_BIT-BEGIN_ADR_BIT+1); item++)
  {
  CMD_ITEM_HOLES183 
  CMD_ITEM_HOLES450 
  CMD_ITEM_HOLES595 

    cmdFunc000(item, &outMaska, &dvMaska, CLRACT_CONTROL);
    if(dvMaska==idxBit_decoderN_SMALLACMDArrayLoader)
    {
      decoderN_SMALLACMDArray[idxBit_decoderN_SMALLACMDArrayLoader] = (unsigned short) item;
      break;
    }//if
  }//for
  idxBit_decoderN_SMALLACMDArrayLoader++;
}//decoderN_SMALLACMDArrayLoader()

int getRangN_BIGModbusRegister2021(unsigned int *ranguvannja_d, int offset )
{
//поиск активного бита
  int bit = getSequenceN_BIGIndexActiveBit(offset, ranguvannja_d);//индекс активного бита
  if(bit!=-1)
  {
    int adr = decoderN_BIGACMD(bit);
    return adr<0? 0: adr+getACMDSmallBeginAdr();//декодировщик индекса бита в адрес modbus
  }//if(bit!=-1)
  return 0;
}//getRangN_BIGModbusRegister2021(unsigned int *ranguvannja_d, int offset )

void writeRangN_BIGModbusRegister2021(unsigned int *ranguvannja_d, unsigned short *dataPacket, int countAdr)
{
  unsigned int tmp[N_BIG];
  int idxObjOld = -1;
  //убрать старое
  for(int i=0; i<countAdr; i++)
  {
    if(idxObjOld != 0)
    {
      idxObjOld = 0;
      for(int dx=0; dx<N_BIG; dx++) tmp[dx]=ranguvannja_d[dx];
    }//if

    int bitOld = getSequenceN_BIGIndexActiveBit(i, tmp);
    if(bitOld != -1) {
      ranguvannja_d[bitOld/32] &= ~(1<<(bitOld%32));
    }//if
  }//for

  //добавить новое
  for(int i=0; i<countAdr; i++)
  {
    unsigned int adr = (unsigned short) swapByteInShort(dataPacket[i]);//новое значение
    if(adr == 0) continue;
    int bit = encoderN_BIGACMD(adr-getACMDSmallBeginAdr()); //кодировщик адреса modbus в индекс бита для реле
    if(bit != -1)
    {
      ranguvannja_d[bit/32] |= (1<<(bit%32));
    }//if
  }//for
}//writeRangN_BIGModbusRegister2021

int getRangN_SMALLModbusRegister2021(unsigned int *ranguvannja_d, int offset )
{
//поиск активного бита
  int bit = getSequenceN_SMALLIndexActiveBit(offset, ranguvannja_d);//индекс активного бита
  if(bit!=-1)
  {
    int adr = decoderN_SMALLACMD(bit);
    return adr<0? 0: adr+getACMDSmallBeginAdr();//декодировщик индекса бита в адрес modbus
  }//if(bit!=-1)
  return 0;
}//getRangN_SMALLModbusRegister2021(unsigned int *ranguvannja_d, int offset )

void writeRangN_SMALLModbusRegister2021(unsigned int *ranguvannja_d, unsigned short *dataPacket, int countAdr)
{
  unsigned int tmp[N_SMALL];
  int idxObjOld = -1;
  //убрать старое
  for(int i=0; i<countAdr; i++)
  {
    if(idxObjOld != 0)
    {
      idxObjOld = 0;
      for(int dx=0; dx<N_SMALL; dx++) tmp[dx]=ranguvannja_d[dx];
    }//if

    int bitOld = getSequenceN_SMALLIndexActiveBit(i, tmp);
    if(bitOld != -1) {
      ranguvannja_d[bitOld/32] &= ~(1<<(bitOld%32));
    }//if
  }//for

  //добавить новое
  for(int i=0; i<countAdr; i++)
  {
    unsigned int adr = (unsigned short) swapByteInShort(dataPacket[i]);//новое значение
    if(adr == 0) continue;
    int bit = encoderN_SMALLACMD(adr-getACMDSmallBeginAdr()); //кодировщик адреса modbus в индекс бита для реле
    if(bit != -1)
    {
      ranguvannja_d[bit/32] |= (1<<(bit%32));
    }//if
  }//for
}//writeRangN_SMALLModbusRegister2021

void loadACMDSmallActualDataBit(int cmdSwitch, int beginOffset, int endOffset)
{
  //ActualData
  for(int ii=0; ii<(1+(END_ADR_BIT-BEGIN_ADR_BIT+1)/16); ii++) tempReadArray[ii] = 0;
  for(int item=0; item<(END_ADR_BIT-BEGIN_ADR_BIT+1); item++)
  {
    int value =0;
    int tsdata = 0;
    if(item>=beginOffset && item<endOffset)
    {
      switch(item)
      {
      case PASSWORD_SETCMD://Пароль установлен
      {
        switch(pointInterface)//метка интерфейса 0-USB 1-RS485
        {
        case USB_RECUEST:
          if(cmdSwitch==0) //ACMD
            value = password_set_USB;//Пароль установлен
          break;
        case RS485_RECUEST:
          if(cmdSwitch==0) //ACMD
            value = password_set_RS485;//Пароль установлен
          break;
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
        case LAN_RECUEST:
          if(cmdSwitch==0) //ACMD
            value = password_set_LAN;//Пароль установлен
          break;
#endif
        }//switch(pointInterface)
        goto m1;
      }//case PASSWORD_SETCMD://Пароль установлен
      }//switch(item)
      value = encoderN_BIGACMD(item);//кодировщик адреса modbus в индекс бита для реле
      if(value==-1) value=0;
      else {
        //читать значение команд
        if(cmdSwitch==0) {
          //ACMD
          value = active_functions[value/32] & (1<<(value%32));
        }//if(cmdSwitch==0)
        else if(cmdSwitch==1) {
          //GCMD
          if(pointInterface==USB_RECUEST)//метка интерфейса 0-USB 1-RS485
          {
            value = trigger_functions_USB[value/32] & (1<<(value%32));
          }//if
          else if(pointInterface==RS485_RECUEST)
          {
            value = trigger_functions_RS485[value/32] & (1<<(value%32));
          }//else
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
          else if(pointInterface==LAN_RECUEST)
          {
            value = trigger_functions_LAN[value/32] & (1<<(value%32));
          }//else
#endif
          else
          {
            //Теоретично цього ніколи не мало б бути
            total_error_sw_fixed();
          }
        }//if(cmdSwitch==1)
        else if(cmdSwitch==2) {
          //RDS
          value = rds_functions[value/32] & (1<<(value%32));
        }//if(cmdSwitch==2)

      }
    }//if(item>=beginOffset && item<endOffset)
m1:
    if(value) tsdata=1;
    tempReadArray[item/16] |= tsdata<<(item%16);
  }//for(int item=0; item<568; item++)
}//loadACMDSmallActualDataBit(int cmdSwitch, int beginOffset, int endOffset)

int validN_BIGACMD(unsigned short dataReg)
{
  return validBazaN_BIGACMD(dataReg, CLRACT_CONTROL);
}//validN_BIGACMD(unsigned short dataReg)
int validBazaN_BIGACMD(unsigned short dataReg, int actControl)
{
//расширенная проверка адреса команды for rele
  if(dataReg!=0)
  {
    int validCMD=0;
    if(((int)encoderValidN_BIGACMD(dataReg-getACMDSmallBeginAdr(), &validCMD, actControl))<0) return MARKER_ERRORPERIMETR; //кодировщик адреса modbus в индекс бита для реле
    if(!validCMD) return MARKER_ERRORPERIMETR; //не прошла валидация
  }//if(dataReg!=0)

  return 0;
}//validBazaN_BIGACMD(unsigned short dataReg, int actControl)
int validN_SMALLACMD(unsigned short dataReg)
{
//расширенная проверка адреса команды for dv
  if(dataReg!=0)
  {
    int validCMD=0;
    if(((int)encoderValidN_SMALLACMD(dataReg-getACMDSmallBeginAdr(), &validCMD))<0) return MARKER_ERRORPERIMETR; //кодировщик адреса modbus в индекс бита для реле
    if(!validCMD) return MARKER_ERRORPERIMETR; //не прошла валидация
  }//if(dataReg!=0)

  return 0;
}//validN_SMALLACMD(int dataReg)
unsigned int encoderN_BIGACMD(int offsetCMD)
{
  int validCMD=0;
  return encoderValidN_BIGACMD(offsetCMD, &validCMD, CLRACT_CONTROL);
}//encoderN_BIGACMD(int adrCMD)
unsigned int encoderValidN_BIGACMD(int offsetCMD, int *validCMD, int actControl)
{
//кодировщик адреса modbus в индекс бита для реле
  int outMaska=-1;
  int dvMaska=-1;
  (*validCMD) = cmdFunc000(offsetCMD, &outMaska, &dvMaska, actControl);
  return outMaska;
}//encoderValidN_BIGACMD(int offsetCMD, int *validCMD)
unsigned int encoderN_SMALLACMD(int offsetCMD)
{
  int validCMD=0;
  return encoderValidN_SMALLACMD(offsetCMD, &validCMD);
}//encoderN_SMALLACMD(int adrCMD)
unsigned int encoderValidN_SMALLACMD(int offsetCMD, int *validCMD)
{
//кодировщик адреса modbus в индекс бита для ДВ
  int outMaska=-1;
  int dvMaska=-1;
  (*validCMD) = cmdFunc000(offsetCMD, &outMaska, &dvMaska, CLRACT_CONTROL);
  return dvMaska;
}//encoderValidN_SMALLACMD(int offsetCMD, int *validCMD)

int decoderN_BIGACMD(int idxBit)
{
//декодировщик индекса бита в адрес modbus  для реле
  unsigned short result = decoderN_BIGACMDArray[idxBit];
  if(result==0xFFFF) return -1;
  return result;
}//decoderN_BIGACMD(int idxBit)

int decoderN_SMALLACMD(int idxBit)
{
//декодировщик индекса бита в адрес modbus  для ДВ
  unsigned short result = decoderN_SMALLACMDArray[idxBit];
  if(result==0xFFFF) return -1;
  return result;
}//decoderN_SMALLACMD(int idxBit)

int getSequenceN_BIGIndexActiveBit(int pps, unsigned int *array)
{
//индекс активного бита N_BIG
  int bit=0;
  unsigned int arrayData = 0;
  int propusk = pps;
  for(; bit<N_BIG*32; bit++)
  {
    arrayData = array[bit/32];
    if(arrayData==0) {
      bit+=31;
      continue;
    }
    unsigned int data = arrayData&(1<<(bit%32));
    if(data!=0&&propusk==0) break;
    if(data!=0&&propusk!=0) propusk--;
  }//for
  if(bit!=N_BIG*32) return bit;
  return -1;
}//getSequenceN_BIGIndexActiveBit(int propusk, unsigned int *array)

int getSequenceN_SMALLIndexActiveBit(int pps, unsigned int *array)
{
//индекс активного бита N_SMALL
  int bit=0;
  unsigned int arrayData = 0;
  int propusk = pps;
  for(; bit<N_SMALL*32; bit++)
  {
    arrayData = array[bit/32];
    if(arrayData==0) {
      bit+=31;
      continue;
    }
    unsigned int data = arrayData&(1<<(bit%32));
    if(data!=0&&propusk==0) break;
    if(data!=0&&propusk!=0) propusk--;
  }//for
  if(bit!=N_SMALL*32) return bit;
  return -1;
}//getSequenceN_SMALLIndexActiveBit(int propusk, unsigned int *array)
int getRangN_BIGModbusRegister(unsigned int *ranguvannja, int countItem, int offset )
{
//поиск активного бита
  int subObj = offset/countItem;
  int bit = getSequenceN_BIGIndexActiveBit(offset%countItem, &ranguvannja[N_BIG*subObj]);//индекс активного бита
  if(bit!=-1)
  {
    int adr = decoderN_BIGACMD(bit);
    return adr<0? 0: adr+getACMDSmallBeginAdr();//декодировщик индекса бита в адрес modbus  для rele
  }//if(bit!=-1)
  return 0;
}//getRangN_BIGModbusRegister(unsigned int *ranguvannja, int countItem, int offset )

int getRangN_SMALLModbusRegister(unsigned int *ranguvannja, int countItem, int offset )
{
//поиск активного бита
  int subObj = offset/countItem;
  int bit = getSequenceN_SMALLIndexActiveBit(offset%countItem, &ranguvannja[N_SMALL*subObj]);//индекс активного бита
  if(bit!=-1)
  {
    int adr = decoderN_SMALLACMD(bit);
    return adr<0? 0: adr+getACMDSmallBeginAdr();//декодировщик индекса бита в адрес modbus  для rele
  }//if(bit!=-1)
  return 0;
}//getRangN_SMALLModbusRegister(unsigned int *ranguvannja, int countItem, int offset )
void writeRangN_BIGModbusRegister(unsigned int *ranguvannja, int countItem, int beginAdr,
                                  int countAdr, int begin_adr_register)
{
  int offsetTempWriteArray = superFindTempWriteArrayOffset(begin_adr_register);//найти смещение TempWriteArray
  unsigned int tmp[N_BIG];//для сохр ранжирования
  int idxObjOld=-1;//индекс суб обекта old
  //убрать старое
  for(int i=0; i<countAdr; i++)
  {
    int offset = beginAdr-begin_adr_register+i;

    int idxObj = offset/countItem;//индекс суб обекта
    unsigned int *ranguvannja_d = &ranguvannja[N_BIG*idxObj]; //Ранжування
    if(idxObj!=idxObjOld) {
      idxObjOld = idxObj;
      for(int dx=0; dx<N_BIG; dx++) tmp[dx]=ranguvannja_d[dx];//сохр старое ранж
    }//if

    int bitOld = getSequenceN_BIGIndexActiveBit(offset%countItem, tmp);//индекс активного бита
    if(bitOld!=-1) {
      ranguvannja_d[bitOld/32] &= ~(1<<(bitOld%32));
    }//if
  }//for
  //добавить новое
  for(int i=0; i<countAdr; i++)
  {
    unsigned int adr = (unsigned short)tempWriteArray[offsetTempWriteArray+i];//новое значение
    if(adr==0) continue;
    int offset = beginAdr-begin_adr_register+i;

    int idxObj = offset/countItem;//индекс суб обекта
    unsigned int *ranguvannja_d = &ranguvannja[N_BIG*idxObj]; //Ранжування
    int bit = encoderN_BIGACMD(adr-getACMDSmallBeginAdr()); //кодировщик адреса modbus в индекс бита для реле
    if(bit!=-1) {
      ranguvannja_d[bit/32] |= (1<<(bit%32));
    }//if
  }//for
}//writeRangN_BIGModbusRegister(unsigned int *ranguvannja, int countItem, int beginAdr, int countAdr,
void writeRangN_SMALLModbusRegister(unsigned int *ranguvannja, int countItem, int beginAdr,
                                    int countAdr, int begin_adr_register)
{
  int offsetTempWriteArray = superFindTempWriteArrayOffset(begin_adr_register);//найти смещение TempWriteArray
  unsigned int tmp[N_SMALL];//для сохр ранжирования
  int idxObjOld=-1;//индекс суб обекта old
  //убрать старое
  for(int i=0; i<countAdr; i++)
  {
    int offset = beginAdr-begin_adr_register+i;

    int idxObj = offset/countItem;//индекс суб обекта
    unsigned int *ranguvannja_d = &ranguvannja[N_SMALL*idxObj]; //Ранжування
    if(idxObj!=idxObjOld) {
      idxObjOld = idxObj;
      for(int dx=0; dx<N_SMALL; dx++) tmp[dx]=ranguvannja_d[dx];//сохр старое ранж
    }//if

    int bitOld = getSequenceN_SMALLIndexActiveBit(offset%countItem, tmp);//индекс активного бита
    if(bitOld!=-1) {
      ranguvannja_d[bitOld/32] &= ~(1<<(bitOld%32));
    }//if
  }//for
  //добавить новое
  for(int i=0; i<countAdr; i++)
  {
    unsigned int adr = (unsigned short)tempWriteArray[offsetTempWriteArray+i];//новое значение
    if(adr==0) continue;
    int offset = beginAdr-begin_adr_register+i;

    int idxObj = offset/countItem;//индекс суб обекта
    unsigned int *ranguvannja_d = &ranguvannja[N_SMALL*idxObj]; //Ранжування
    int bit = encoderN_SMALLACMD(adr-getACMDSmallBeginAdr()); //кодировщик адреса modbus в индекс бита для dv
    if(bit!=-1) {
      ranguvannja_d[bit/32] |= (1<<(bit%32));
    }//if
  }//for
}//writeRangN_SMALLModbusRegister(unsigned int *ranguvannja, int countItem, int beginAdr, int countAdr,

int getACMDSmallModbusRegister(int adrReg)
{
  extern int globalcntReg;//к-во reg для чтения
  extern int globalbeginAdrReg;//адрес нач reg
  //получить содержимое регистра
  if(privateACMDSmallGetReg2(adrReg)==MARKER_OUTPERIMETR) return MARKER_OUTPERIMETR;
  if(acmdsmallcomponent->isActiveActualData)
  {
    int begin = globalbeginAdrReg-BEGIN_ADR_REGISTER;
    if(begin<0) globalcntReg += begin;

    int beginOffset = (adrReg-BEGIN_ADR_REGISTER)*16;
    int endOffset   = beginOffset +globalcntReg*16;

    loadACMDSmallActualDataBit(0, beginOffset, endOffset); //ActualData
  }//if(acmdsmallcomponent->isActiveActualData)
  acmdsmallcomponent->isActiveActualData = 0;

  return tempReadArray[adrReg-BEGIN_ADR_REGISTER];
}//getDOUTModbusRegister(int adrReg)
int getACMDSmallModbusBit(int adrBit)
{
  extern int globalcntBit;//к-во бит для чтения
  extern int globalbeginAdrBit;//адрес нач бит
  //получить содержимое bit

  if(privateACMDSmallGetBit2(adrBit)==MARKER_OUTPERIMETR) return MARKER_OUTPERIMETR;

  int beginOffset = adrBit-BEGIN_ADR_BIT;
  if(acmdsmallcomponent->isActiveActualData)
  {
    int begin = globalbeginAdrBit-BEGIN_ADR_BIT;
    if(begin<0) globalcntBit += begin;

    int endOffset   = beginOffset +globalcntBit;

    loadACMDSmallActualDataBit(0, beginOffset, endOffset); //ActualData
  }//if(acmdsmallcomponent->isActiveActualData)
  acmdsmallcomponent->isActiveActualData = 0;

  short tmp   = tempReadArray[beginOffset/16];
  short maska = 1<<(beginOffset%16);
  if(tmp&maska) return 1;
  return 0;
}//getDOUTModbusBit(int adrReg)
int setACMDSmallModbusRegister(int adrReg, int dataReg)
{
  UNUSED(dataReg);
  if(privateACMDSmallGetReg2(adrReg)==MARKER_OUTPERIMETR) return MARKER_OUTPERIMETR;
  return MARKER_ERRORPERIMETR;
}//getDOUTModbusRegister(int adrReg)
int setACMDSmallModbusBit(int adrBit, int dataBit)
{
  //записать содержимое bit
  if(privateACMDSmallGetBit2(adrBit)==MARKER_OUTPERIMETR) return MARKER_OUTPERIMETR;

  superSetOperativMarker(acmdsmallcomponent, adrBit);
  superSetTempWriteArray(dataBit);//записать в буфер
  
  if(adrBit != BEGIN_ADR_BIT+ BITACMD1302)//Активация конфигурации
  {
    if(dataBit == 0) return MARKER_ERRORPERIMETR;
  }//if(adrBit!=50567)
  else return 0;
/*
  if(adrBit == BEGIN_ADR_BIT+BITACMD1333)//Очистить регистратор статистики
  {
    if(
      ((clean_rejestrators & CLEAN_SR_ERR) != 0)
    ) return ERROR_VALID2;//ошибка валидации
  }//if
*/
  if(writeACMDSmallActualDataBit(adrBit-BEGIN_ADR_BIT, 0) != 0) return MARKER_ERRORPERIMETR;
  else
  {//біти з enum _INTERFACE звідки прийшла команда ТУ
    mutex_interface = true;
    switch(pointInterface)//метка интерфейса 0-USB 1-RS485
    {
     case USB_RECUEST:
//      dostup_z_VR |= (1<<USB_RECUEST);
     break;
     case RS485_RECUEST:
//      dostup_z_VR |= (1<<RS485_RECUEST);
     break;
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
     case LAN_RECUEST:
      dostup_z_VR |= (1<<LAN_RECUEST);
     break;
#endif
    }//switch
    mutex_interface = false;
  }//else
  
  return 0;
}//setACMDSmallModbusBit(int adrBit, int dataBit)

int writeACMDSmallActualDataBit(int inOffset, int dataBit)
{
  int actControl = 0;
  if(inOffset<0)
  {
    inOffset = -inOffset;
    actControl = 1;
  }//if(offset<0)
  switch(inOffset)
  {
  case 1360://OF
   return activationFunction(RANGE_SMALL_A01_DF1_IN, actControl, dataBit);
  case 1361://OF
   return activationFunction(RANGE_SMALL_A01_DF2_IN, actControl, dataBit);
  case 1362://OF
   return activationFunction(RANGE_SMALL_A01_DF3_IN, actControl, dataBit);
  case 1363://OF
   return activationFunction(RANGE_SMALL_A01_DF4_IN, actControl, dataBit);
  case 1364://OF
   return activationFunction(RANGE_SMALL_A01_DF5_IN, actControl, dataBit);
  case 1365://OF
   return activationFunction(RANGE_SMALL_A01_DF6_IN, actControl, dataBit);
  case 1366://OF
   return activationFunction(RANGE_SMALL_A01_DF7_IN, actControl, dataBit);
  case 1367://OF
   return activationFunction(RANGE_SMALL_A01_DF8_IN, actControl, dataBit);
  case 1368://OF
   return activationFunction(RANGE_SMALL_A01_DF9_IN, actControl, dataBit);
  case 1369://OF
   return activationFunction(RANGE_SMALL_A01_DF10_IN, actControl, dataBit);
  case 1370://OF
   return activationFunction(RANGE_SMALL_A01_DF11_IN, actControl, dataBit);
  case 1371://OF
   return activationFunction(RANGE_SMALL_A01_DF12_IN, actControl, dataBit);
  case 1372://OF
   return activationFunction(RANGE_SMALL_A01_DF13_IN, actControl, dataBit);
  case 1373://OF
   return activationFunction(RANGE_SMALL_A01_DF14_IN, actControl, dataBit);
  case 1374://OF
   return activationFunction(RANGE_SMALL_A01_DF15_IN, actControl, dataBit);
  case 1375://OF
   return activationFunction(RANGE_SMALL_A01_DF16_IN, actControl, dataBit);

  case 1376://OF
   return activationFunction(RANGE_SMALL_A01_DF1_RST, actControl, dataBit);
  case 1377://OF
   return activationFunction(RANGE_SMALL_A01_DF2_RST, actControl, dataBit);
  case 1378://OF
   return activationFunction(RANGE_SMALL_A01_DF3_RST, actControl, dataBit);
  case 1379://OF
   return activationFunction(RANGE_SMALL_A01_DF4_RST, actControl, dataBit);
  case 1380://OF
   return activationFunction(RANGE_SMALL_A01_DF5_RST, actControl, dataBit);
  case 1381://OF
   return activationFunction(RANGE_SMALL_A01_DF6_RST, actControl, dataBit);
  case 1382://OF
   return activationFunction(RANGE_SMALL_A01_DF7_RST, actControl, dataBit);
  case 1383://OF
   return activationFunction(RANGE_SMALL_A01_DF8_RST, actControl, dataBit);
  case 1384://OF
   return activationFunction(RANGE_SMALL_A01_DF9_RST, actControl, dataBit);
  case 1385://OF
   return activationFunction(RANGE_SMALL_A01_DF10_RST, actControl, dataBit);
  case 1386://OF
   return activationFunction(RANGE_SMALL_A01_DF11_RST, actControl, dataBit);
  case 1387://OF
   return activationFunction(RANGE_SMALL_A01_DF12_RST, actControl, dataBit);
  case 1388://OF
   return activationFunction(RANGE_SMALL_A01_DF13_RST, actControl, dataBit);
  case 1389://OF
   return activationFunction(RANGE_SMALL_A01_DF14_RST, actControl, dataBit);
  case 1390://OF
   return activationFunction(RANGE_SMALL_A01_DF15_RST, actControl, dataBit);
  case 1391://OF
   return activationFunction(RANGE_SMALL_A01_DF16_RST, actControl, dataBit);

  case 1408://DTR
   return activationFunction(RANGE_SMALL_A01_DT1_SET, actControl, dataBit);
  case 1409://DTR
   return activationFunction(RANGE_SMALL_A01_DT2_SET, actControl, dataBit);
  case 1410://DTR
   return activationFunction(RANGE_SMALL_A01_DT3_SET, actControl, dataBit);
  case 1411://DTR
   return activationFunction(RANGE_SMALL_A01_DT4_SET, actControl, dataBit);

  case 1424://DTR
   return activationFunction(RANGE_SMALL_A01_DT1_RESET, actControl, dataBit);
  case 1425://DTR
   return activationFunction(RANGE_SMALL_A01_DT2_RESET, actControl, dataBit);
  case 1426://DTR
   return activationFunction(RANGE_SMALL_A01_DT3_RESET, actControl, dataBit);
  case 1427://DTR
   return activationFunction(RANGE_SMALL_A01_DT4_RESET, actControl, dataBit);

  case 1568://Выход ФС 1
   return activationFunction(RANG_SMALL_A01_LF1, actControl, dataBit);
  case 1569://Выход ФС 2
   return activationFunction(RANG_SMALL_A01_LF2, actControl, dataBit);
  case 1570://Выход ФС 3
   return activationFunction(RANG_SMALL_A01_LF3, actControl, dataBit);
  case 1571://Выход ФС 4
   return activationFunction(RANG_SMALL_A01_LF4, actControl, dataBit);
  case 1572://Выход ФС 5
   return activationFunction(RANG_SMALL_A01_LF5, actControl, dataBit);
  case 1573://Выход ФС 6
   return activationFunction(RANG_SMALL_A01_LF6, actControl, dataBit);
  case 1574://Выход ФС 7
   return activationFunction(RANG_SMALL_A01_LF7, actControl, dataBit);
  case 1575://Выход ФС 8
   return activationFunction(RANG_SMALL_A01_LF8, actControl, dataBit);
  case 1576://Выход ФС 9
   return activationFunction(RANG_SMALL_A01_LF9, actControl, dataBit);
  case 1577://Выход ФС 10
   return activationFunction(RANG_SMALL_A01_LF10, actControl, dataBit);
  case 1578://Выход ФС 11
   return activationFunction(RANG_SMALL_A01_LF11, actControl, dataBit);
  case 1579://Выход ФС 12
   return activationFunction(RANG_SMALL_A01_LF12, actControl, dataBit);
  case 1580://Выход ФС 13
   return activationFunction(RANG_SMALL_A01_LF13, actControl, dataBit);
  case 1581://Выход ФС 14
   return activationFunction(RANG_SMALL_A01_LF14, actControl, dataBit);
  case 1582://Выход ФС 15
   return activationFunction(RANG_SMALL_A01_LF15, actControl, dataBit);
  case 1583://Выход ФС 16
   return activationFunction(RANG_SMALL_A01_LF16, actControl, dataBit);

  case IMUNITET_BITACMD896://Вкл.  виключателя К1
   return activationFunction(RANGE_SMALL_A01_VKL_VVO, actControl, dataBit);
  case IMUNITET_BITACMD897://Викл. виключателя К1
   return activationFunction(RANGE_SMALL_A01_OTKL_VVO, actControl, dataBit);

  case IMUNITET_BITACMD909://Сигнал про очищення ресурсу лічильників K1
   return restartCounter(actControl, dataBit);

  case IMUNITET_BITACMD928://Вкл.  виключателя К2
   return activationFunction(RANGE_SMALL_A01_VKL_VVP, actControl, dataBit);
  case IMUNITET_BITACMD929://Викл. виключателя К2
   return activationFunction(RANGE_SMALL_A01_OTKL_VVP, actControl, dataBit);

  case IMUNITET_BITACMD978://Очищення індикації
   return activationFunction(RANGE_SMALL_A01_RESET_LEDS, actControl, dataBit);
  case IMUNITET_BITACMD979://Скидання реле
   return activationFunction(RANGE_SMALL_A01_RESET_RELES, actControl, dataBit);
  case IMUNITET_BITACMD980://
    if(actControl&&dataBit)
    {
      //Скидання загальних функцій
      if(pointInterface==USB_RECUEST)//метка интерфейса 0-USB 1-RS485
        reset_trigger_function_from_interface |= (1 << USB_RECUEST);
      else
        reset_trigger_function_from_interface |= (1 << RS485_RECUEST);
    }//if(action)
    return 0;

  case BITACMD1302://Активизация конфигурации
    if(actControl)
    {
      if(dataBit)
      {
        //Активація внесекних змін
        int typI = 2;
        if(pointInterface==RS485_RECUEST) typI = 3;//метка интерфейса 0-USB 1-RS485
        if(set_new_settings_from_interface(typI))//2-USB
        {
          type_of_settings_changed = 0;
          _CLEAR_BIT(active_functions, RNG_BIG_SETTINGS_CHANGED);
          return ERROR_VALID3;//ошибка
        }//if
      }//if
      else//деактивация
      {
        //Відміна внесекних змін
        current_settings_interfaces = current_settings;
      }
      type_of_settings_changed = 0;
      _CLEAR_BIT(active_functions, RNG_BIG_SETTINGS_CHANGED);
    }//if(action)
    return 0;

  case 1305://Запуск аналогового реєстратора
    if(_CHECK_SET_BIT(active_functions, RNG_BIG_MISCEVE_DYSTANCIJNE) != 0) return MARKER_ERRORPERIMETR;
    if (_CHECK_SET_BIT(active_functions, RNG_BIG_READY_TU) == 0)return MARKER_ERRORPERIMETR;
    if(actControl&&dataBit)
    {
      start_ar = 0xff; //Запуск аналогового реєстратора
    }//if(action)
    return 0;

  case IMUNITET_BITACMD1006://
    if(_CHECK_SET_BIT(active_functions, RNG_BIG_MISCEVE_DYSTANCIJNE) != 0) return MARKER_ERRORPERIMETR;
    if(actControl&&dataBit)
    {
      mutex_interface = true;
      _SET_BIT(activation_function_from_interface, RANGE_SMALL_A01_RESET_BLOCK_READY_TU_VID_ZAHYSTIV); //Скидання блокування готорності ТУ від захистів
      mutex_interface = false;
    }//if(action)
    return 0;
  }//switch
  return MARKER_ERRORPERIMETR;
}//writeACMDSmallActualDataBit(int offset)

int activationFunction(int small_cmd, int actControl, int dataBit)
{
    if(_CHECK_SET_BIT(active_functions, RNG_BIG_MISCEVE_DYSTANCIJNE) != 0) return MARKER_ERRORPERIMETR;
    //if (_CHECK_SET_BIT(active_functions, RANG_READY_TU) == 0)return MARKER_ERRORPERIMETR;
    if(actControl&&dataBit)
    {
      mutex_interface = true;
      _SET_BIT(activation_function_from_interface, small_cmd);
      mutex_interface = false;
    }//if(action)
    return 0;
}//activationFunction(int small_cmd, int actControl, int dataBit)

int start_ar_function(int actControl, int dataBit)
{
    if(_CHECK_SET_BIT(active_functions, RNG_BIG_MISCEVE_DYSTANCIJNE) != 0) return MARKER_ERRORPERIMETR;
    //if (_CHECK_SET_BIT(active_functions, RANG_READY_TU) == 0)return MARKER_ERRORPERIMETR;
    if(actControl&&dataBit)
    {
      start_ar = 0xff; //Запуск аналогового реєстратора
    }//if(action)
    return 0;
}//start_ar_function

int clear_ar_function(void)
{
//Очистить аналоговый регистратор
  if (
    (state_ar_record_m           != STATE_AR_NONE_M )
    ||  
    (state_ar_record_prt         != STATE_AR_NONE_PRT )
    ||  
    (
     (control_tasks_dataflash & (
                                 TASK_MAMORY_PART_PAGE_PROGRAM_THROUGH_BUFFER_DATAFLASH_FOR_FS |
                                 TASK_MAMORY_PAGE_PROGRAM_THROUGH_BUFFER_DATAFLASH_FOR_FS      |
                                 TASK_MAMORY_READ_DATAFLASH_FOR_FS 
                                )
     ) != 0
    )
    ||
    ((clean_rejestrators & CLEAN_AR) != 0)
  ) return ERROR_VALID2;//ошибка валидации

  clean_rejestrators |= CLEAN_AR;
  return 0;
}//clear_ar_function

int clear_dr_function(void)
{
//Очистить дискретный регистратор
  if (
    (current_ekran.current_level == EKRAN_TITLES_DIGITAL_REGISTRATOR)
    ||
    (current_ekran.current_level == EKRAN_CHANGES_SIGNALS_DR        )
    ||
    (current_ekran.current_level == EKRAN_TITLE_MAX_VALUES          )
    ||
    (current_ekran.current_level == EKRAN_MAX_VALUES                )
    ||
    (
      (control_tasks_dataflash & (
         TASK_MAMORY_PAGE_PROGRAM_THROUGH_BUFFER_DATAFLASH_FOR_DR       |
         TASK_MAMORY_READ_DATAFLASH_FOR_DR_USB                          |
         TASK_MAMORY_READ_DATAFLASH_FOR_DR_RS485                        |
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
         TASK_MAMORY_READ_DATAFLASH_FOR_DR_LAN                          |
#endif  
         TASK_MAMORY_READ_DATAFLASH_FOR_DR_MENU                         |
         TASK_MAMORY_READ_DATAFLASH_FOR_DR_MENU_SHORT
       )
      ) != 0
    )
    ||
    ((clean_rejestrators & CLEAN_DR) != 0)
  ) return ERROR_VALID2;//ошибка валидации

  //Помічаємо, що треба очистити дискретного реєстратора
  clean_rejestrators |= CLEAN_DR;
  return 0;
}//clear_dr_function

int clean_rejestrators_function(int actControl, int dataBit)
{
//Очистить регистратор статистики
    if(_CHECK_SET_BIT(active_functions, RNG_BIG_MISCEVE_DYSTANCIJNE) != 0) return MARKER_ERRORPERIMETR;
    //if (_CHECK_SET_BIT(active_functions, RANG_READY_TU) == 0)return MARKER_ERRORPERIMETR;
    if(actControl&&dataBit)
    {
      //clean_rejestrators |= CLEAN_SR_ERR;
    }//if(action)
    return 0;
}//clean_rejestrators_function
int restartCounter(int actControl, int dataBit)
{
    if(_CHECK_SET_BIT(active_functions, RNG_BIG_MISCEVE_DYSTANCIJNE) != 0) return MARKER_ERRORPERIMETR;
    if (_CHECK_SET_BIT(active_functions, RNG_BIG_READY_TU) == 0)return MARKER_ERRORPERIMETR;
    if(actControl&&dataBit)
    {
      restart_counter = 0xff;//(1<< value); //Сигнал про очищення ресурсу лічильників
    }//if(action)
    return 0;
}//restartCounter(int value, int actControl, int dataBit)

int postACMDSmallWriteAction(void)
{
//action после записи
  int beginAdr = acmdsmallcomponent->operativMarker[0];
  if(beginAdr<0) return 0;//не было записи
  int endAdr   = acmdsmallcomponent->operativMarker[1];
  int countAdr = endAdr-beginAdr+1;
  if(endAdr<0) countAdr = 1;

  if(beginAdr>=BEGIN_ADR_BIT)
  {
    //работа с битами
    int offsetTempWriteArray = superFindTempWriteArrayOffset(BEGIN_ADR_BIT);//найти смещение TempWriteArray

    for(int i=0; i<countAdr; i++) {
      int offset = i+beginAdr-BEGIN_ADR_BIT;
      uint32_t value = tempWriteArray[offsetTempWriteArray+i];
      writeACMDSmallActualDataBit(-offset, value);//action
    }//for
  }//if(beginAdr>=BEGIN_ADR_BIT)
  else
  {
    //работа с регистрами
    int offsetTempWriteArray = superFindTempWriteArrayOffset(BEGIN_ADR_REGISTER);//найти смещение TempWriteArray
    for(int i=0; i<countAdr; i++) {
      int offset = i+beginAdr-BEGIN_ADR_REGISTER;
      for(int bit=0; bit<16; bit++)
      {
        uint32_t value = tempWriteArray[offsetTempWriteArray+i];
        int temp = 0;
        if(value&(1<<bit)) temp = 1;
        writeACMDSmallActualDataBit(-(offset*16+bit), temp);//action
      }//for
    }//for
  }//else

  return 0;
}//

int privateACMDSmallGetReg2(int adrReg)
{
  //проверить внешний периметр
  return controlPerimetr(adrReg, BEGIN_ADR_REGISTER, END_ADR_REGISTER);
}//privateGetReg2(int adrReg)

int privateACMDSmallGetBit2(int adrBit)
{
  //проверить внешний периметр
  return controlPerimetr(adrBit, BEGIN_ADR_BIT, END_ADR_BIT);
}//privateGetReg2(int adrReg)

int passwordImunitetBitACMDSmallComponent(int adrBit)
{
  //имунитетные к паролю адреса bit 0 - есть имунитет
  if(privateACMDSmallGetBit2(adrBit)==MARKER_OUTPERIMETR) return MARKER_OUTPERIMETR;
  switch(adrBit)
  {
  case BEGIN_ADR_BIT+IMUNITET_BITACMD896://Включение ВВ K1
  case BEGIN_ADR_BIT+IMUNITET_BITACMD897://Отключение ВВ K1
  case BEGIN_ADR_BIT+IMUNITET_BITACMD928://Включение ВВ K2
  case BEGIN_ADR_BIT+IMUNITET_BITACMD929://Отключение ВВ K2
//  case BEGIN_ADR_BIT+IMUNITET_BITACMD960://Включение ВВ SC
//  case BEGIN_ADR_BIT+IMUNITET_BITACMD961://Отключение ВВ SC

  case BEGIN_ADR_BIT+IMUNITET_BITACMD978://Сброс индикации
  case BEGIN_ADR_BIT+IMUNITET_BITACMD979://Сброс реле
  case BEGIN_ADR_BIT+IMUNITET_BITACMD980://Сброс сработавших функций
  case BEGIN_ADR_BIT+IMUNITET_BITACMD909://Сброс счетчика ресурса выключателя K1
//  case BEGIN_ADR_BIT+IMUNITET_BITACMD941://Сброс счетчика ресурса выключателя K2
//  case BEGIN_ADR_BIT+IMUNITET_BITACMD968://Сброс счетчика ресурса выключателя SC

  case BEGIN_ADR_BIT+IMUNITET_BITACMD1006://Сброс блокировки готовности к ТУ от защит
    return 0;//есть имунитет
  }//switch
  return MARKER_OUTPERIMETR;
}//passwordImunitetBitACMDSmallComponent(int adrBit)
