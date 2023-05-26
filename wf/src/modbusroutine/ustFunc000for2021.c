
#include "header.h"

/**************************************/
//База данных уставок
/**************************************/

int postUstRegister000for21(int fileRecordNumber, int registerNumber, unsigned int value)
{
  extern int upravlSetting;//флаг Setting
  int  multer = 1;
  uint32_t *editValue = NULL;
  ustFunc000for2021(fileRecordNumber, registerNumber, &multer, 0, &editValue);
  if(editValue == NULL) return 1;

  (*editValue) = value*multer;

  //ustFunc000for2021(-fileRecordNumber, registerNumber, &multer, 0, &editValue);//actControl=1

  upravlSetting = 1;//флаг Setting
  return 0;
}//postUstRegister21

int getUstRegister000for20(int fileRecordNumber, int registerNumber)
{
  int  multer = 1;
  uint32_t *editValue = NULL;
  ustFunc000for2021(fileRecordNumber, registerNumber, &multer, 0, &editValue);
  if(editValue == NULL) return 0;

  return ((*editValue)/multer) &0xFFFF;
}//getUstRegister20
int setUstRegister000for21(int fileRecordNumber, int registerNumber, unsigned int value)
{
  int  multer = 1;
  uint32_t *editValue = NULL;
  if(!ustFunc000for2021(fileRecordNumber, registerNumber, &multer, value, &editValue)) return MARKER_ERRORDIAPAZON;
  return 0;
}//setUstRegister21

int ustFunc000for2021(int fileRecordNumber, int registerNumber, int *multer, int regUst, uint32_t **editValue)
{
  int diapazon = 1;

  (*multer) = 10;

  int fileNumber       = fileRecordNumber&0xFFFF0000;//номер файла
  int recordNumber     = fileRecordNumber&0x0000FFFF;//номер запису

  int grupa_ustavok = registerNumber - 1;

  switch(fileNumber)
  {

  case (FILENUMBER(FILEUVV_DVREGISTER2021)):
  {
    int item = recordNumber-1;
    (*editValue) = (uint32_t*)&edition_settings.dopusk_dv[item];
    (*multer) = 1;
  }//case (FILENUMBER(FILEUVV_DVREGISTER2021))
  break;
////UP+UP+UP+UP+UP+UP+UP+UP+UP+UP+UP+UP+UP+UP+UP+UP+UP+UP+UP+UP+
  case (FILENUMBER(FILEPROT_UPREGISTER2021)):
  {
    int item = recordNumber/100;
    switch(recordNumber%100)
    {
    case 6://6 106 206 306 406 506 606 706
      (*editValue) = (uint32_t*)&edition_settings.timeout_UP[item][grupa_ustavok];
      if(regUst<TIMEOUT_UP_MIN/10 || regUst>TIMEOUT_UP_MAX/10) diapazon=0;
      break;
    case 7://7 107 207 307 407 507 607 707
      (*multer) = 1;
      (*editValue) = (uint32_t*)&edition_settings.setpoint_UP_KP[item][grupa_ustavok];

      if(edition_settings.control_UP& (1<<(2+3*item)))//more_less_control
      {
        if(regUst<SETPOINT_UP_KP_LESS_MIN || regUst>SETPOINT_UP_KP_LESS_MAX) diapazon=0;
      }//if(edition_settings.control_UP& (1<<(2+3*item)))//more_less_control
      else  if(regUst<SETPOINT_UP_KP_MORE_MIN || regUst>SETPOINT_UP_KP_MORE_MAX) diapazon=0;
      break;
    }//switch(recordNumber%100)
  }//FILENUMBER(FILEPROT_UPREGISTER2021
  break;
////UP-UP-UP-UP-UP-UP-UP-UP-UP-UP-UP-UP-UP-UP-UP-UP-UP-UP-UP-UP-
////OMP+OMP+OMP+OMP+OMP+OMP+OMP+OMP+OMP+OMP+OMP+OMP+OMP+OMP+OMP+OMP+OMP+
  case (FILENUMBER(FILEPERIF_OMPREGISTER2021)):
  {
    int direct = -1;
    int item = -1;
    (*multer) = 1;
    if((recordNumber >= 6) && (recordNumber <= 21)) {
      direct = 0;
      item = (recordNumber-6)/2;
    }
    if((recordNumber >= 23) && (recordNumber <= 38)) {
      direct = 1;
      item = (recordNumber-23)/2;
    }
    if(direct >= 0)
      switch(recordNumber&1)
      {
      case 0://6 8 10 12 14 16 18 20 //24 26 28 30 32 34 36 38
        (*editValue) = (uint32_t*)&edition_settings.dovgyna[direct][item];
        if(regUst<SETPOINT_DOVGYNA_VMP_MIN || regUst>SETPOINT_DOVGYNA_VMP_MAX) diapazon=0;
        break;
      case 1://7 9 11 13 15 17 19 21 //23 25 27 29 31 33 35 37
        (*editValue) = (uint32_t*)&edition_settings.opir[direct][item];
        if(regUst<SETPOINT_OPIR_VMP_MIN || regUst>SETPOINT_OPIR_VMP_MAX) diapazon=0;
      }//switch(recordNumber&1)
  }//FILENUMBER(FILEPERIF_OMPREGISTER2021
  break;
////OMP-OMP-OMP-OMP-OMP-OMP-OMP-OMP-OMP-OMP-OMP-OMP-OMP-OMP-OMP-OMP-OMP-
////MFT+MFT+MFT+MFT+MFT+MFT+MFT+MFT+MFT+MFT+MFT+MFT+MFT+MFT+MFT+MFT+MFT+MFT+MFT+MFT+
  case (FILENUMBER(FILEPERIF_ELMFTREGISTER2021)):
  {
    int item = (recordNumber/5);
    switch(registerNumber)
    {
    case 2:
      (*editValue) = (uint32_t*)&edition_settings.timeout_pause_df[item];
      if(regUst<TIMEOUT_DF_PAUSE_MIN/10 || regUst>TIMEOUT_DF_PAUSE_MAX/10) diapazon=0;
      break;
    case 3:
      (*editValue) = (uint32_t*)&edition_settings.timeout_work_df[item];
      if(regUst<TIMEOUT_DF_WORK_MIN/10 || regUst>TIMEOUT_DF_WORK_MAX/10) diapazon=0;
      break;
    }//switch
  }//FILENUMBER(FILEPERIF_MFTREGISTER2021
  break;
////MFT-MFT-MFT-MFT-MFT-MFT-MFT-MFT-MFT-MFT-MFT-MFT-MFT-MFT-MFT-MFT-MFT-MFT-MFT-MFT-
  }//switch

  if((*editValue) == NULL)
    switch(fileRecordNumber)
    {
    case (FILENUMBER(FILEPROT_COMMREGISTER2021)+RECORDNUMBER(1)):
      (*editValue) = (uint32_t*)&edition_settings.grupa_ustavok;
      (*multer) = 1;
      if(regUst<1 || regUst>4) diapazon=0;
      break;

////MTZO+MTZO+MTZO+MTZO+MTZO+MTZO+MTZO+MTZO+MTZO+MTZO+MTZO+MTZO+
    case (FILENUMBER(FILEPROT_MTZOREGISTER2021)+RECORDNUMBER(2)):
      (*multer) = 1;
      (*editValue) = (uint32_t*)&edition_settings.type_mtzo1;
      if(regUst<0 || regUst>2) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZOREGISTER2021)+RECORDNUMBER(5)):
      (*editValue) = (uint32_t*)&edition_settings.setpoint_mtzo_1[grupa_ustavok];
      if(regUst<SETPOINT_MTZO1_MIN/10 || regUst>SETPOINT_MTZO1_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZOREGISTER2021)+RECORDNUMBER(6)):
      (*editValue) = (uint32_t*)&edition_settings.setpoint_mtzo_1_n_vpered[grupa_ustavok];
      if(regUst<SETPOINT_MTZO1_N_VPERED_MIN/10 || regUst>SETPOINT_MTZO1_N_VPERED_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZOREGISTER2021)+RECORDNUMBER(7)):
      (*editValue) = (uint32_t*)&edition_settings.setpoint_mtzo_1_n_nazad[grupa_ustavok];
      if(regUst<SETPOINT_MTZO1_N_NAZAD_MIN/10 || regUst>SETPOINT_MTZO1_N_NAZAD_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZOREGISTER2021)+RECORDNUMBER(8)):
      (*editValue) = (uint32_t*)&edition_settings.setpoint_mtzo_1_po_napruzi[grupa_ustavok];
      if(regUst<SETPOINT_MTZO1_PO_NAPRUZI_MIN/10 || regUst>SETPOINT_MTZO1_PO_NAPRUZI_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZOREGISTER2021)+RECORDNUMBER(9)):
      (*editValue) = (uint32_t*)&edition_settings.setpoint_mtzo_1_U[grupa_ustavok];
      if(regUst<SETPOINT_MTZO1_U_MIN/10 || regUst>SETPOINT_MTZO1_U_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZOREGISTER2021)+RECORDNUMBER(10)):
      (*multer) = 1;
      (*editValue) = (uint32_t*)&edition_settings.setpoint_mtzo_1_angle[grupa_ustavok];
      if(regUst<SETPOINT_MTZO1_ANGLE_MIN || regUst>SETPOINT_MTZO1_ANGLE_MAX) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZOREGISTER2021)+RECORDNUMBER(11)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_mtzo_1[grupa_ustavok];
      if(regUst<TIMEOUT_MTZO1_MIN/10 || regUst>TIMEOUT_MTZO1_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZOREGISTER2021)+RECORDNUMBER(12)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_mtzo_1_n_vpered[grupa_ustavok];
      if(regUst<TIMEOUT_MTZO1_N_VPERED_MIN/10 || regUst>TIMEOUT_MTZO1_N_VPERED_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZOREGISTER2021)+RECORDNUMBER(13)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_mtzo_1_n_nazad[grupa_ustavok];
      if(regUst<TIMEOUT_MTZO1_N_NAZAD_MIN/10 || regUst>TIMEOUT_MTZO1_N_NAZAD_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZOREGISTER2021)+RECORDNUMBER(14)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_mtzo_1_po_napruzi[grupa_ustavok];
      if(regUst<TIMEOUT_MTZO1_PO_NAPRUZI_MIN/10 || regUst>TIMEOUT_MTZO1_PO_NAPRUZI_MAX/10) diapazon=0;
      break;

    case (FILENUMBER(FILEPROT_MTZOREGISTER2021)+RECORDNUMBER(105)):
      (*editValue) = (uint32_t*)&edition_settings.setpoint_mtzo_2[grupa_ustavok];
      if(regUst<SETPOINT_MTZO2_MIN/10 || regUst>SETPOINT_MTZO2_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZOREGISTER2021)+RECORDNUMBER(106)):
      (*editValue) = (uint32_t*)&edition_settings.setpoint_mtzo_2_n_vpered[grupa_ustavok];
      if(regUst<SETPOINT_MTZO2_N_VPERED_MIN/10 || regUst>SETPOINT_MTZO2_N_VPERED_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZOREGISTER2021)+RECORDNUMBER(107)):
      (*editValue) = (uint32_t*)&edition_settings.setpoint_mtzo_2_n_nazad[grupa_ustavok];
      if(regUst<SETPOINT_MTZO2_N_NAZAD_MIN/10 || regUst>SETPOINT_MTZO2_N_NAZAD_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZOREGISTER2021)+RECORDNUMBER(108)):
      (*editValue) = (uint32_t*)&edition_settings.setpoint_mtzo_2_po_napruzi[grupa_ustavok];
      if(regUst<SETPOINT_MTZO2_PO_NAPRUZI_MIN/10 || regUst>SETPOINT_MTZO2_PO_NAPRUZI_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZOREGISTER2021)+RECORDNUMBER(109)):
      (*editValue) = (uint32_t*)&edition_settings.setpoint_mtzo_2_U[grupa_ustavok];
      if(regUst<SETPOINT_MTZO2_U_MIN/10 || regUst>SETPOINT_MTZO2_U_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZOREGISTER2021)+RECORDNUMBER(110)):
      (*multer) = 1;
      (*editValue) = (uint32_t*)&edition_settings.setpoint_mtzo_2_angle[grupa_ustavok];
      if(regUst<SETPOINT_MTZO2_ANGLE_MIN || regUst>SETPOINT_MTZO2_ANGLE_MAX) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZOREGISTER2021)+RECORDNUMBER(111)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_mtzo_2[grupa_ustavok];
      if(regUst<TIMEOUT_MTZO2_MIN/10 || regUst>TIMEOUT_MTZO2_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZOREGISTER2021)+RECORDNUMBER(112)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_mtzo_2_n_vpered[grupa_ustavok];
      if(regUst<TIMEOUT_MTZO2_N_VPERED_MIN/10 || regUst>TIMEOUT_MTZO2_N_VPERED_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZOREGISTER2021)+RECORDNUMBER(113)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_mtzo_2_n_nazad[grupa_ustavok];
      if(regUst<TIMEOUT_MTZO2_N_NAZAD_MIN/10 || regUst>TIMEOUT_MTZO2_N_NAZAD_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZOREGISTER2021)+RECORDNUMBER(114)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_mtzo_2_po_napruzi[grupa_ustavok];
      if(regUst<TIMEOUT_MTZO2_PO_NAPRUZI_MIN/10 || regUst>TIMEOUT_MTZO2_PO_NAPRUZI_MAX/10) diapazon=0;
      break;

    case (FILENUMBER(FILEPROT_MTZOREGISTER2021)+RECORDNUMBER(115)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_mtzo_2_vvid_pr[grupa_ustavok];
      if(regUst<TIMEOUT_MTZO2_VVID_PR_MIN/10 || regUst>TIMEOUT_MTZO2_VVID_PR_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZOREGISTER2021)+RECORDNUMBER(116)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_mtzo_2_pr[grupa_ustavok];
      if(regUst<TIMEOUT_MTZO2_PR_MIN/10 || regUst>TIMEOUT_MTZO2_PR_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZOREGISTER2021)+RECORDNUMBER(117)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_mtzo_2_n_vpered_pr[grupa_ustavok];
      if(regUst<TIMEOUT_MTZO2_N_VPERED_PR_MIN/10 || regUst>TIMEOUT_MTZO2_N_VPERED_PR_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZOREGISTER2021)+RECORDNUMBER(118)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_mtzo_2_n_nazad_pr[grupa_ustavok];
      if(regUst<TIMEOUT_MTZO2_N_NAZAD_PR_MIN/10 || regUst>TIMEOUT_MTZO2_N_NAZAD_PR_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZOREGISTER2021)+RECORDNUMBER(119)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_mtzo_2_po_napruzi_pr[grupa_ustavok];
      if(regUst<TIMEOUT_MTZO2_PO_NAPRUZI_PR_MIN/10 || regUst>TIMEOUT_MTZO2_PO_NAPRUZI_PR_MAX/10) diapazon=0;
      break;

    case (FILENUMBER(FILEPROT_MTZOREGISTER2021)+RECORDNUMBER(205)):
      (*editValue) = (uint32_t*)&edition_settings.setpoint_mtzo_3[grupa_ustavok];
      if(regUst<SETPOINT_MTZO3_MIN/10 || regUst>SETPOINT_MTZO3_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZOREGISTER2021)+RECORDNUMBER(206)):
      (*editValue) = (uint32_t*)&edition_settings.setpoint_mtzo_3_n_vpered[grupa_ustavok];
      if(regUst<SETPOINT_MTZO3_N_VPERED_MIN/10 || regUst>SETPOINT_MTZO3_N_VPERED_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZOREGISTER2021)+RECORDNUMBER(207)):
      (*editValue) = (uint32_t*)&edition_settings.setpoint_mtzo_3_n_nazad[grupa_ustavok];
      if(regUst<SETPOINT_MTZO3_N_NAZAD_MIN/10 || regUst>SETPOINT_MTZO3_N_NAZAD_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZOREGISTER2021)+RECORDNUMBER(208)):
      (*editValue) = (uint32_t*)&edition_settings.setpoint_mtzo_3_po_napruzi[grupa_ustavok];
      if(regUst<SETPOINT_MTZO3_PO_NAPRUZI_MIN/10 || regUst>SETPOINT_MTZO3_PO_NAPRUZI_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZOREGISTER2021)+RECORDNUMBER(209)):
      (*editValue) = (uint32_t*)&edition_settings.setpoint_mtzo_3_U[grupa_ustavok];
      if(regUst<SETPOINT_MTZO3_U_MIN/10 || regUst>SETPOINT_MTZO3_U_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZOREGISTER2021)+RECORDNUMBER(210)):
      (*multer) = 1;
      (*editValue) = (uint32_t*)&edition_settings.setpoint_mtzo_3_angle[grupa_ustavok];
      if(regUst<SETPOINT_MTZO3_ANGLE_MIN || regUst>SETPOINT_MTZO3_ANGLE_MAX) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZOREGISTER2021)+RECORDNUMBER(211)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_mtzo_3[grupa_ustavok];
      if(regUst<TIMEOUT_MTZO3_MIN/10 || regUst>TIMEOUT_MTZO3_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZOREGISTER2021)+RECORDNUMBER(212)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_mtzo_3_n_vpered[grupa_ustavok];
      if(regUst<TIMEOUT_MTZO3_N_VPERED_MIN/10 || regUst>TIMEOUT_MTZO3_N_VPERED_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZOREGISTER2021)+RECORDNUMBER(213)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_mtzo_3_n_nazad[grupa_ustavok];
      if(regUst<TIMEOUT_MTZO3_N_NAZAD_MIN/10 || regUst>TIMEOUT_MTZO3_N_NAZAD_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZOREGISTER2021)+RECORDNUMBER(214)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_mtzo_3_po_napruzi[grupa_ustavok];
      if(regUst<TIMEOUT_MTZO3_PO_NAPRUZI_MIN/10 || regUst>TIMEOUT_MTZO3_PO_NAPRUZI_MAX/10) diapazon=0;
      break;

    case (FILENUMBER(FILEPROT_MTZOREGISTER2021)+RECORDNUMBER(305)):
      (*editValue) = (uint32_t*)&edition_settings.setpoint_mtzo_4[grupa_ustavok];
      if(regUst<SETPOINT_MTZO4_MIN/10 || regUst>SETPOINT_MTZO4_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZOREGISTER2021)+RECORDNUMBER(306)):
      (*editValue) = (uint32_t*)&edition_settings.setpoint_mtzo_4_n_vpered[grupa_ustavok];
      if(regUst<SETPOINT_MTZO4_N_VPERED_MIN/10 || regUst>SETPOINT_MTZO4_N_VPERED_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZOREGISTER2021)+RECORDNUMBER(307)):
      (*editValue) = (uint32_t*)&edition_settings.setpoint_mtzo_4_n_nazad[grupa_ustavok];
      if(regUst<SETPOINT_MTZO4_N_NAZAD_MIN/10 || regUst>SETPOINT_MTZO4_N_NAZAD_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZOREGISTER2021)+RECORDNUMBER(308)):
      (*editValue) = (uint32_t*)&edition_settings.setpoint_mtzo_4_po_napruzi[grupa_ustavok];
      if(regUst<SETPOINT_MTZO4_PO_NAPRUZI_MIN/10 || regUst>SETPOINT_MTZO4_PO_NAPRUZI_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZOREGISTER2021)+RECORDNUMBER(309)):
      (*editValue) = (uint32_t*)&edition_settings.setpoint_mtzo_4_U[grupa_ustavok];
      if(regUst<SETPOINT_MTZO4_U_MIN/10 || regUst>SETPOINT_MTZO4_U_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZOREGISTER2021)+RECORDNUMBER(310)):
      (*multer) = 1;
      (*editValue) = (uint32_t*)&edition_settings.setpoint_mtzo_4_angle[grupa_ustavok];
      if(regUst<SETPOINT_MTZO4_ANGLE_MIN || regUst>SETPOINT_MTZO4_ANGLE_MAX) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZOREGISTER2021)+RECORDNUMBER(311)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_mtzo_4[grupa_ustavok];
      if(regUst<TIMEOUT_MTZO4_MIN/10 || regUst>TIMEOUT_MTZO4_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZOREGISTER2021)+RECORDNUMBER(312)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_mtzo_4_n_vpered[grupa_ustavok];
      if(regUst<TIMEOUT_MTZO4_N_VPERED_MIN/10 || regUst>TIMEOUT_MTZO4_N_VPERED_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZOREGISTER2021)+RECORDNUMBER(313)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_mtzo_4_n_nazad[grupa_ustavok];
      if(regUst<TIMEOUT_MTZO4_N_NAZAD_MIN/10 || regUst>TIMEOUT_MTZO4_N_NAZAD_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZOREGISTER2021)+RECORDNUMBER(314)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_mtzo_4_po_napruzi[grupa_ustavok];
      if(regUst<TIMEOUT_MTZO4_PO_NAPRUZI_MIN/10 || regUst>TIMEOUT_MTZO4_PO_NAPRUZI_MAX/10) diapazon=0;
      break;
////MTZO-MTZO-MTZO-MTZO-MTZO-MTZO-MTZO-MTZO-MTZO-MTZO-MTZO-MTZO-
////MTZR+MTZR+MTZR+MTZR+MTZR+MTZR+MTZR+MTZR+MTZR+MTZR+MTZR+MTZR+MTZR+
    case (FILENUMBER(FILEPROT_MTZRREGISTER2021)+RECORDNUMBER(2)):
      (*multer) = 1;
      (*editValue) = (uint32_t*)&edition_settings.type_mtzr1;
      if(regUst<0 || regUst>2) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZRREGISTER2021)+RECORDNUMBER(5)):
      (*editValue) = (uint32_t*)&edition_settings.setpoint_mtzr_1[grupa_ustavok];
      if(regUst<SETPOINT_MTZR1_MIN/10 || regUst>SETPOINT_MTZR1_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZRREGISTER2021)+RECORDNUMBER(6)):
      (*editValue) = (uint32_t*)&edition_settings.setpoint_mtzr_1_n_vpered[grupa_ustavok];
      if(regUst<SETPOINT_MTZR1_N_VPERED_MIN/10 || regUst>SETPOINT_MTZR1_N_VPERED_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZRREGISTER2021)+RECORDNUMBER(7)):
      (*editValue) = (uint32_t*)&edition_settings.setpoint_mtzr_1_n_nazad[grupa_ustavok];
      if(regUst<SETPOINT_MTZR1_N_NAZAD_MIN/10 || regUst>SETPOINT_MTZR1_N_NAZAD_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZRREGISTER2021)+RECORDNUMBER(8)):
      (*editValue) = (uint32_t*)&edition_settings.setpoint_mtzr_1_po_napruzi[grupa_ustavok];
      if(regUst<SETPOINT_MTZR1_PO_NAPRUZI_MIN/10 || regUst>SETPOINT_MTZR1_PO_NAPRUZI_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZRREGISTER2021)+RECORDNUMBER(9)):
      (*editValue) = (uint32_t*)&edition_settings.setpoint_mtzr_1_U[grupa_ustavok];
      if(regUst<SETPOINT_MTZR1_U_MIN/10 || regUst>SETPOINT_MTZR1_U_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZRREGISTER2021)+RECORDNUMBER(10)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_mtzr_1[grupa_ustavok];
      if(regUst<TIMEOUT_MTZR1_MIN/10 || regUst>TIMEOUT_MTZR1_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZRREGISTER2021)+RECORDNUMBER(11)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_mtzr_1_n_vpered[grupa_ustavok];
      if(regUst<TIMEOUT_MTZR1_N_VPERED_MIN/10 || regUst>TIMEOUT_MTZR1_N_VPERED_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZRREGISTER2021)+RECORDNUMBER(12)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_mtzr_1_n_nazad[grupa_ustavok];
      if(regUst<TIMEOUT_MTZR1_N_NAZAD_MIN/10 || regUst>TIMEOUT_MTZR1_N_NAZAD_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZRREGISTER2021)+RECORDNUMBER(13)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_mtzr_1_po_napruzi[grupa_ustavok];
      if(regUst<TIMEOUT_MTZR1_PO_NAPRUZI_MIN/10 || regUst>TIMEOUT_MTZR1_PO_NAPRUZI_MAX/10) diapazon=0;
      break;

    case (FILENUMBER(FILEPROT_MTZRREGISTER2021)+RECORDNUMBER(102)):
      (*multer) = 1;
      (*editValue) = (uint32_t*)&edition_settings.type_mtzr2;
      if(regUst<0 || regUst>2) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZRREGISTER2021)+RECORDNUMBER(105)):
      (*editValue) = (uint32_t*)&edition_settings.setpoint_mtzr_2[grupa_ustavok];
      if(regUst<SETPOINT_MTZR2_MIN/10 || regUst>SETPOINT_MTZR2_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZRREGISTER2021)+RECORDNUMBER(106)):
      (*editValue) = (uint32_t*)&edition_settings.setpoint_mtzr_2_n_vpered[grupa_ustavok];
      if(regUst<SETPOINT_MTZR2_N_VPERED_MIN/10 || regUst>SETPOINT_MTZR2_N_VPERED_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZRREGISTER2021)+RECORDNUMBER(107)):
      (*editValue) = (uint32_t*)&edition_settings.setpoint_mtzr_2_n_nazad[grupa_ustavok];
      if(regUst<SETPOINT_MTZR2_N_NAZAD_MIN/10 || regUst>SETPOINT_MTZR2_N_NAZAD_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZRREGISTER2021)+RECORDNUMBER(108)):
      (*editValue) = (uint32_t*)&edition_settings.setpoint_mtzr_2_po_napruzi[grupa_ustavok];
      if(regUst<SETPOINT_MTZR2_PO_NAPRUZI_MIN/10 || regUst>SETPOINT_MTZR2_PO_NAPRUZI_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZRREGISTER2021)+RECORDNUMBER(109)):
      (*editValue) = (uint32_t*)&edition_settings.setpoint_mtzr_2_U[grupa_ustavok];
      if(regUst<SETPOINT_MTZR2_U_MIN/10 || regUst>SETPOINT_MTZR2_U_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZRREGISTER2021)+RECORDNUMBER(110)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_mtzr_2[grupa_ustavok];
      if(regUst<TIMEOUT_MTZR2_MIN/10 || regUst>TIMEOUT_MTZR2_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZRREGISTER2021)+RECORDNUMBER(111)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_mtzr_2_n_vpered[grupa_ustavok];
      if(regUst<TIMEOUT_MTZR2_N_VPERED_MIN/10 || regUst>TIMEOUT_MTZR2_N_VPERED_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZRREGISTER2021)+RECORDNUMBER(112)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_mtzr_2_n_nazad[grupa_ustavok];
      if(regUst<TIMEOUT_MTZR2_N_NAZAD_MIN/10 || regUst>TIMEOUT_MTZR2_N_NAZAD_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_MTZRREGISTER2021)+RECORDNUMBER(113)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_mtzr_2_po_napruzi[grupa_ustavok];
      if(regUst<TIMEOUT_MTZR2_PO_NAPRUZI_MIN/10 || regUst>TIMEOUT_MTZR2_PO_NAPRUZI_MAX/10) diapazon=0;
      break;
////MTZR-MTZR-MTZR-MTZR-MTZR-MTZR-MTZR-MTZR-MTZR-MTZR-MTZR-MTZR-MTZR-MTZR-MTZR-
////ZNMIN+ZNMIN+ZNMIN+ZNMIN+ZNMIN+ZNMIN+ZNMIN+ZNMIN+ZNMIN+ZNMIN+
    case (FILENUMBER(FILEPROT_ZNMINREGISTER2021)+RECORDNUMBER(5)):
      (*multer) = 100;
      (*editValue) = (uint32_t*)&edition_settings.setpoint_Umin1[grupa_ustavok];
      if(regUst<SETPOINT_UMIN1_MIN/100 || regUst>SETPOINT_UMIN1_MAX/100) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_ZNMINREGISTER2021)+RECORDNUMBER(6)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_Umin1[grupa_ustavok];
      if(regUst<TIMEOUT_UMIN1_MIN/10 || regUst>TIMEOUT_UMIN1_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_ZNMINREGISTER2021)+RECORDNUMBER(7)):
      (*editValue) = (uint32_t*)&edition_settings.setpoint_Umin1_Iblk[grupa_ustavok];
      if(regUst<SETPOINT_UMIN1_IBLK_MIN/10 || regUst>SETPOINT_UMIN1_IBLK_MAX/10) diapazon=0;
      break;

    case (FILENUMBER(FILEPROT_ZNMINREGISTER2021)+RECORDNUMBER(105)):
      (*multer) = 100;
      (*editValue) = (uint32_t*)&edition_settings.setpoint_Umin2[grupa_ustavok];
      if(regUst<SETPOINT_UMIN2_MIN/100 || regUst>SETPOINT_UMIN2_MAX/100) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_ZNMINREGISTER2021)+RECORDNUMBER(106)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_Umin2[grupa_ustavok];
      if(regUst<TIMEOUT_UMIN2_MIN/10 || regUst>TIMEOUT_UMIN2_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_ZNMINREGISTER2021)+RECORDNUMBER(107)):
      (*editValue) = (uint32_t*)&edition_settings.setpoint_Umin2_Iblk[grupa_ustavok];
      if(regUst<SETPOINT_UMIN2_IBLK_MIN/10 || regUst>SETPOINT_UMIN2_IBLK_MAX/10) diapazon=0;
      break;
////ZNMIN-ZNMIN-ZNMIN-ZNMIN-ZNMIN-ZNMIN-ZNMIN-ZNMIN-ZNMIN-ZNMIN-
////ZNMAX+ZNMAX+ZNMAX+ZNMAX+ZNMAX+ZNMAX+ZNMAX+ZNMAX+ZNMAX+ZNMAX+
    case (FILENUMBER(FILEPROT_ZNMAXREGISTER2021)+RECORDNUMBER(5)):
      (*multer) = 100;
      (*editValue) = (uint32_t*)&edition_settings.setpoint_Umax1[grupa_ustavok];
      if(regUst<SETPOINT_UMAX1_MIN/100 || regUst>SETPOINT_UMAX1_MAX/100) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_ZNMAXREGISTER2021)+RECORDNUMBER(6)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_Umax1[grupa_ustavok];
      if(regUst<TIMEOUT_UMIN1_MIN/10 || regUst>TIMEOUT_UMIN1_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_ZNMAXREGISTER2021)+RECORDNUMBER(105)):
      (*multer) = 100;
      (*editValue) = (uint32_t*)&edition_settings.setpoint_Umax2[grupa_ustavok];
      if(regUst<SETPOINT_UMAX2_MIN/100 || regUst>SETPOINT_UMAX2_MAX/100) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_ZNMAXREGISTER2021)+RECORDNUMBER(106)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_Umax2[grupa_ustavok];
      if(regUst<TIMEOUT_UMIN2_MIN/10 || regUst>TIMEOUT_UMIN2_MAX/10) diapazon=0;
      break;
////ZNMAX-ZNMAX-ZNMAX-ZNMAX-ZNMAX-ZNMAX-ZNMAX-ZNMAX-ZNMAX-ZNMAX-
////APV+APV+APV+APV+APV+APV+APV+APV+APV+APV+APV+APV+APV+APV+APV+APV+APV+
    case (FILENUMBER(FILEPROT_APVREGISTER2021)+RECORDNUMBER(5)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_apv_block_vid_VV[grupa_ustavok];
      if(regUst<TIMEOUT_APV_BLOCK_VID_VV_MIN/10 || regUst>TIMEOUT_APV_BLOCK_VID_VV_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_APVREGISTER2021)+RECORDNUMBER(6)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_apv_1[grupa_ustavok];
      if(regUst<TIMEOUT_APV1_MIN/10 || regUst>TIMEOUT_APV1_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_APVREGISTER2021)+RECORDNUMBER(7)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_apv_2[grupa_ustavok];
      if(regUst<TIMEOUT_APV2_MIN/10 || regUst>TIMEOUT_APV2_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_APVREGISTER2021)+RECORDNUMBER(8)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_apv_3[grupa_ustavok];
      if(regUst<TIMEOUT_APV3_MIN/10 || regUst>TIMEOUT_APV3_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_APVREGISTER2021)+RECORDNUMBER(9)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_apv_4[grupa_ustavok];
      if(regUst<TIMEOUT_APV4_MIN/10 || regUst>TIMEOUT_APV4_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_APVREGISTER2021)+RECORDNUMBER(10)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_apv_block_vid_apv1[grupa_ustavok];
      if(regUst<TIMEOUT_APV_BLOCK_VID_APV1_MIN/10 || regUst>TIMEOUT_APV_BLOCK_VID_APV1_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_APVREGISTER2021)+RECORDNUMBER(11)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_apv_block_vid_apv2[grupa_ustavok];
      if(regUst<TIMEOUT_APV_BLOCK_VID_APV2_MIN/10 || regUst>TIMEOUT_APV_BLOCK_VID_APV2_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_APVREGISTER2021)+RECORDNUMBER(12)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_apv_block_vid_apv3[grupa_ustavok];
      if(regUst<TIMEOUT_APV_BLOCK_VID_APV3_MIN/10 || regUst>TIMEOUT_APV_BLOCK_VID_APV3_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_APVREGISTER2021)+RECORDNUMBER(13)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_apv_block_vid_apv4[grupa_ustavok];
      if(regUst<TIMEOUT_APV_BLOCK_VID_APV4_MIN/10 || regUst>TIMEOUT_APV_BLOCK_VID_APV4_MAX/10) diapazon=0;
      break;
////APV-APV-APV-APV-APV-APV-APV-APV-APV-APV-APV-APV-APV-APV-APV-APV-APV-APV-
////UROV+UROV+UROV+UROV+UROV+UROV+UROV+UROV+UROV+UROV+UROV+UROV+
    case (FILENUMBER(FILEPROT_UROVREGISTER2021)+RECORDNUMBER(5)):
      (*editValue) = &edition_settings.setpoint_urov[grupa_ustavok];
      if(regUst<SETPOINT_UROV_MIN/10 || regUst>SETPOINT_UROV_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_UROVREGISTER2021)+RECORDNUMBER(6)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_urov_1[grupa_ustavok];
      if(regUst<TIMEOUT_UROV1_MIN/10 || regUst>TIMEOUT_UROV1_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_UROVREGISTER2021)+RECORDNUMBER(7)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_urov_2[grupa_ustavok];
      if(regUst<TIMEOUT_UROV2_MIN/10 || regUst>TIMEOUT_UROV2_MAX/10) diapazon=0;
      break;
////UROV-UROV-UROV-UROV-UROV-UROV-UROV-UROV-UROV-UROV-UROV-UROV-
////AJR+AJR+AJR+AJR+AJR+AJR+AJR+AJR+AJR+AJR+AJR+AJR+AJR+AJR+AJR+
    case (FILENUMBER(FILEPROT_AJRREGISTER2021)+RECORDNUMBER(5)):
      (*multer) = 1;
      (*editValue) = (uint32_t*)&edition_settings.setpoint_achr1_f_rab[grupa_ustavok];
      if(regUst<SETPOINT_ACHR1_F_RAB_MIN || regUst>SETPOINT_ACHR1_F_RAB_MAX) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_AJRREGISTER2021)+RECORDNUMBER(6)):
      (*multer) = 1;
      (*editValue) = (uint32_t*)&edition_settings.setpoint_chapv1_f_rab[grupa_ustavok];
      if(regUst<SETPOINT_CHAPV1_F_RAB_MIN || regUst>SETPOINT_CHAPV1_F_RAB_MAX) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_AJRREGISTER2021)+RECORDNUMBER(7)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_achr_1[grupa_ustavok];
      if(regUst<TIMEOUT_ACHR1_MIN/10 || regUst>TIMEOUT_ACHR1_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_AJRREGISTER2021)+RECORDNUMBER(8)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_chapv_1[grupa_ustavok];
      if(regUst<TIMEOUT_CHAPV1_MIN/10 || regUst>TIMEOUT_CHAPV1_MAX/10) diapazon=0;
      break;

    case (FILENUMBER(FILEPROT_AJRREGISTER2021)+RECORDNUMBER(105)):
      (*multer) = 1;
      (*editValue) = (uint32_t*)&edition_settings.setpoint_achr2_f_rab[grupa_ustavok];
      if(regUst<SETPOINT_ACHR2_F_RAB_MIN || regUst>SETPOINT_ACHR2_F_RAB_MAX) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_AJRREGISTER2021)+RECORDNUMBER(106)):
      (*multer) = 1;
      (*editValue) = (uint32_t*)&edition_settings.setpoint_chapv2_f_rab[grupa_ustavok];
      if(regUst<SETPOINT_CHAPV2_F_RAB_MIN || regUst>SETPOINT_CHAPV2_F_RAB_MAX) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_AJRREGISTER2021)+RECORDNUMBER(107)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_achr_2[grupa_ustavok];
      if(regUst<TIMEOUT_ACHR2_MIN/10 || regUst>TIMEOUT_ACHR2_MIN/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_AJRREGISTER2021)+RECORDNUMBER(108)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_chapv_2[grupa_ustavok];
      if(regUst<TIMEOUT_CHAPV2_MIN/10 || regUst>TIMEOUT_CHAPV2_MAX/10) diapazon=0;
      break;
////AJR-AJR-AJR-AJR-AJR-AJR-AJR-AJR-AJR-AJR-AJR-AJR-AJR-AJR-AJR-
////DZO+DZO+DZO+DZO+DZO+DZO+DZO+DZO+DZO+DZO+DZO+DZO+DZO+DZO+DZO+DZO+DZO+
    case (FILENUMBER(FILEPROT_DZOREGISTER2021)+RECORDNUMBER(6)):
      (*editValue) = &edition_settings.pickup_dzo_Io3g_Io1g[grupa_ustavok];
      if(regUst<PICKUP_DZO_K_3G_DIV_1G_MIN/10 || regUst>PICKUP_DZO_K_3G_DIV_1G_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZOREGISTER2021)+RECORDNUMBER(7)):
      (*editValue) = &edition_settings.pickup_dzo1[grupa_ustavok];
      if(regUst<PICKUP_DZO1_MIN/10 || regUst>PICKUP_DZO1_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZOREGISTER2021)+RECORDNUMBER(8)):
      (*editValue) = &edition_settings.pickup_dzo1_amtz[grupa_ustavok];
      if(regUst<PICKUP_DZO1_AMTZ_MIN/10 || regUst>PICKUP_DZO1_AMTZ_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZOREGISTER2021)+RECORDNUMBER(9)):
      (*editValue) = &edition_settings.pickup_dzo1_blkI[grupa_ustavok];
      if(regUst<PICKUP_DZO1_BLKI_MIN/10 || regUst>PICKUP_DZO1_BLKI_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZOREGISTER2021)+RECORDNUMBER(10)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_dzo1[grupa_ustavok];
      if(regUst<TIMEOUT_DZO1_MIN/10 || regUst>TIMEOUT_DZO1_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZOREGISTER2021)+RECORDNUMBER(11)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_dzo1_amtz[grupa_ustavok];
      if(regUst<TIMEOUT_DZO1_AMTZ_MIN/10 || regUst>TIMEOUT_DZO1_AMTZ_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZOREGISTER2021)+RECORDNUMBER(12)):
      (*multer) = 1;
      (*editValue) = (uint32_t*)&edition_settings.timeout_nkn_dzo[grupa_ustavok];
      if(regUst<TIMEOUT_NKN_DZO_MIN || regUst>TIMEOUT_NKN_DZO_MAX) diapazon=0;
      break;

    case (FILENUMBER(FILEPROT_DZOREGISTER2021)+RECORDNUMBER(105)):
      (*multer) = 1;
      (*editValue) = (uint32_t*)&edition_settings.pickup_dzo2_angle[grupa_ustavok];
      if(regUst>65000 && regUst<65536+PICKUP_DZO2_ANGLE_MIN) diapazon=0;
      if(regUst<65000 && regUst>PICKUP_DZO2_ANGLE_MAX) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZOREGISTER2021)+RECORDNUMBER(106)):
      (*editValue) = (uint32_t*)&edition_settings.pickup_dzo2_dir[grupa_ustavok];
      if(regUst<PICKUP_DZO2_DIR_MIN/10 || regUst>PICKUP_DZO2_DIR_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZOREGISTER2021)+RECORDNUMBER(107)):
      (*editValue) = (uint32_t*)&edition_settings.pickup_dzo2_inv[grupa_ustavok];
      if(regUst<PICKUP_DZO2_INV_MIN/10 || regUst>PICKUP_DZO2_INV_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZOREGISTER2021)+RECORDNUMBER(108)):
      (*editValue) = (uint32_t*)&edition_settings.pickup_dzo2_amtz[grupa_ustavok];
      if(regUst<PICKUP_DZO2_AMTZ_MIN/10 || regUst>PICKUP_DZO2_AMTZ_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZOREGISTER2021)+RECORDNUMBER(109)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_dzo2_dir[grupa_ustavok];
      if(regUst<TIMEOUT_DZO2_DIR_MIN/10 || regUst>TIMEOUT_DZO2_DIR_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZOREGISTER2021)+RECORDNUMBER(110)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_dzo2_dir_pr[grupa_ustavok];
      if(regUst<TIMEOUT_DZO2_DIR_PR_MIN/10 || regUst>TIMEOUT_DZO2_DIR_PR_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZOREGISTER2021)+RECORDNUMBER(111)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_dzo2_inv[grupa_ustavok];
      if(regUst<TIMEOUT_DZO2_INV_MIN/10 || regUst>TIMEOUT_DZO2_INV_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZOREGISTER2021)+RECORDNUMBER(112)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_dzo2_inv_pr[grupa_ustavok];
      if(regUst<TIMEOUT_DZO2_INV_PR_MIN/10 || regUst>TIMEOUT_DZO2_INV_PR_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZOREGISTER2021)+RECORDNUMBER(113)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_dzo2_amtz[grupa_ustavok];
      if(regUst<TIMEOUT_DZO2_AMTZ_MIN/10 || regUst>TIMEOUT_DZO2_AMTZ_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZOREGISTER2021)+RECORDNUMBER(114)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_dzo2_amtz_pr[grupa_ustavok];
      if(regUst<TIMEOUT_DZO2_AMTZ_PR_MIN/10 || regUst>TIMEOUT_DZO2_AMTZ_PR_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZOREGISTER2021)+RECORDNUMBER(115)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_dzo2_vvid_pr[grupa_ustavok];
      if(regUst<TIMEOUT_DZO2_VVID_PR_MIN/10 || regUst>TIMEOUT_DZO2_VVID_PR_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZOREGISTER2021)+RECORDNUMBER(116)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_dzo2_amtz_vvid_pr[grupa_ustavok];
      if(regUst<TIMEOUT_DZO2_AMTZ_VVID_PR_MIN/10 || regUst>TIMEOUT_DZO2_AMTZ_VVID_PR_MAX/10) diapazon=0;
      break;

    case (FILENUMBER(FILEPROT_DZOREGISTER2021)+RECORDNUMBER(205)):
      (*multer) = 1;
      (*editValue) = (uint32_t*)&edition_settings.pickup_dzo3_angle_h[grupa_ustavok];
      if(regUst>65000 && regUst<65536+PICKUP_DZO3_ANGLE_H_MIN) diapazon=0;
      if(regUst<65000 && regUst>PICKUP_DZO3_ANGLE_H_MAX) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZOREGISTER2021)+RECORDNUMBER(206)):
      (*multer) = 1;
      (*editValue) = (uint32_t*)&edition_settings.pickup_dzo3_angle_l[grupa_ustavok];
      if(regUst>65000 && regUst<65536+PICKUP_DZO3_ANGLE_L_MIN) diapazon=0;
      if(regUst<65000 && regUst>PICKUP_DZO3_ANGLE_L_MAX) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZOREGISTER2021)+RECORDNUMBER(207)):
      (*editValue) = (uint32_t*)&edition_settings.pickup_dzo3_dir[grupa_ustavok];
      if(regUst<PICKUP_DZO3_DIR_MIN/10 || regUst>PICKUP_DZO3_DIR_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZOREGISTER2021)+RECORDNUMBER(208)):
      (*editValue) = (uint32_t*)&edition_settings.pickup_dzo3_inv[grupa_ustavok];
      if(regUst<PICKUP_DZO3_INV_MIN/10 || regUst>PICKUP_DZO3_INV_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZOREGISTER2021)+RECORDNUMBER(209)):
      (*editValue) = (uint32_t*)&edition_settings.pickup_dzo3_amtz[grupa_ustavok];
      if(regUst<PICKUP_DZO3_AMTZ_MIN/10 || regUst>PICKUP_DZO3_AMTZ_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZOREGISTER2021)+RECORDNUMBER(210)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_dzo3_dir[grupa_ustavok];
      if(regUst<TIMEOUT_DZO3_DIR_MIN/10 || regUst>TIMEOUT_DZO3_DIR_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZOREGISTER2021)+RECORDNUMBER(211)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_dzo3_dir_pr[grupa_ustavok];
      if(regUst<TIMEOUT_DZO3_DIR_PR_MIN/10 || regUst>TIMEOUT_DZO3_DIR_PR_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZOREGISTER2021)+RECORDNUMBER(212)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_dzo3_inv[grupa_ustavok];
      if(regUst<TIMEOUT_DZO3_INV_MIN/10 || regUst>TIMEOUT_DZO3_INV_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZOREGISTER2021)+RECORDNUMBER(213)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_dzo3_inv_pr[grupa_ustavok];
      if(regUst<TIMEOUT_DZO3_INV_PR_MIN/10 || regUst>TIMEOUT_DZO3_INV_PR_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZOREGISTER2021)+RECORDNUMBER(214)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_dzo3_amtz[grupa_ustavok];
      if(regUst<TIMEOUT_DZO3_AMTZ_MIN/10 || regUst>TIMEOUT_DZO3_AMTZ_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZOREGISTER2021)+RECORDNUMBER(215)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_dzo3_amtz_pr[grupa_ustavok];
      if(regUst<TIMEOUT_DZO3_AMTZ_PR_MIN/10 || regUst>TIMEOUT_DZO3_AMTZ_PR_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZOREGISTER2021)+RECORDNUMBER(216)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_dzo3_vvid_pr[grupa_ustavok];
      if(regUst<TIMEOUT_DZO3_VVID_PR_MIN/10 || regUst>TIMEOUT_DZO3_VVID_PR_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZOREGISTER2021)+RECORDNUMBER(217)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_dzo3_amtz_vvid_pr[grupa_ustavok];
      if(regUst<TIMEOUT_DZO3_AMTZ_VVID_PR_MIN/10 || regUst>TIMEOUT_DZO3_AMTZ_VVID_PR_MAX/10) diapazon=0;
      break;

    case (FILENUMBER(FILEPROT_DZOREGISTER2021)+RECORDNUMBER(306)):
      (*editValue) = (uint32_t*)&edition_settings.pickup_dzo4_Zo_dir[grupa_ustavok];
      if(regUst<PICKUP_DZO4_Z0_DIR_MIN/10 || regUst>PICKUP_DZO4_Z0_DIR_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZOREGISTER2021)+RECORDNUMBER(307)):
      (*editValue) = (uint32_t*)&edition_settings.pickup_dzo4_Zo_inv[grupa_ustavok];
      if(regUst<PICKUP_DZO4_Z0_INV_MIN/10 || regUst>PICKUP_DZO4_Z0_INV_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZOREGISTER2021)+RECORDNUMBER(308)):
      (*editValue) = (uint32_t*)&edition_settings.pickup_dzo4_Xo_dir[grupa_ustavok];
      if(regUst<PICKUP_DZO4_X0_DIR_MIN/10 || regUst>PICKUP_DZO4_X0_DIR_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZOREGISTER2021)+RECORDNUMBER(309)):
      (*editValue) = (uint32_t*)&edition_settings.pickup_dzo4_Xo_inv[grupa_ustavok];
      if(regUst<PICKUP_DZO4_X0_INV_MIN/10 || regUst>PICKUP_DZO4_X0_INV_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZOREGISTER2021)+RECORDNUMBER(310)):
      (*editValue) = (uint32_t*)&edition_settings.pickup_dzo4_amtz[grupa_ustavok];
      if(regUst<PICKUP_DZO4_AMTZ_MIN/10 || regUst>PICKUP_DZO4_AMTZ_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZOREGISTER2021)+RECORDNUMBER(311)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_dzo4_dir[grupa_ustavok];
      if(regUst<TIMEOUT_DZO4_DIR_MIN/10 || regUst>TIMEOUT_DZO4_DIR_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZOREGISTER2021)+RECORDNUMBER(313)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_dzo4_inv[grupa_ustavok];
      if(regUst<TIMEOUT_DZO4_INV_MIN/10 || regUst>TIMEOUT_DZO4_INV_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZOREGISTER2021)+RECORDNUMBER(315)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_dzo4_amtz[grupa_ustavok];
      if(regUst<TIMEOUT_DZO4_AMTZ_MIN/10 || regUst>TIMEOUT_DZO4_AMTZ_MAX/10) diapazon=0;
      break;
////DZO-DZO-DZO-DZO-DZO-DZO-DZO-DZO-DZO-DZO-DZO-DZO-DZO-DZO-DZO-DZO-DZO-
////DZR+DZR+DZR+DZR+DZR+DZR+DZR+DZR+DZR+DZR+DZR+DZR+DZR+DZR+DZR+DZR+DZR+
    case (FILENUMBER(FILEPROT_DZRREGISTER2021)+RECORDNUMBER(5)):
    (*editValue) = (uint32_t*)&edition_settings.pickup_dzr_Io3g_Io1g[grupa_ustavok];
    if(regUst<PICKUP_DZR_K_3G_DIV_1G_MIN/10 || regUst>PICKUP_DZR_K_3G_DIV_1G_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZRREGISTER2021)+RECORDNUMBER(6)):
    (*editValue) = (uint32_t*)&edition_settings.pickup_dzr1[grupa_ustavok];
    if(regUst<PICKUP_DZR1_MIN/10 || regUst>PICKUP_DZR1_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZRREGISTER2021)+RECORDNUMBER(7)):
    (*editValue) = (uint32_t*)&edition_settings.pickup_dzr1_amtz[grupa_ustavok];
    if(regUst<PICKUP_DZR1_AMTZ_MIN/10 || regUst>PICKUP_DZR1_AMTZ_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZRREGISTER2021)+RECORDNUMBER(8)):
    (*editValue) = (uint32_t*)&edition_settings.pickup_dzr1_blkI[grupa_ustavok];
    if(regUst<PICKUP_DZR1_BLKI_MIN/10 || regUst>PICKUP_DZR1_BLKI_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZRREGISTER2021)+RECORDNUMBER(9)):
    (*editValue) = (uint32_t*)&edition_settings.timeout_dzr1[grupa_ustavok];
    if(regUst<TIMEOUT_DZR1_MIN/10 || regUst>TIMEOUT_DZR1_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZRREGISTER2021)+RECORDNUMBER(10)):
    (*editValue) = (uint32_t*)&edition_settings.timeout_dzr1_amtz[grupa_ustavok];
    if(regUst<TIMEOUT_DZR1_AMTZ_MIN/10 || regUst>TIMEOUT_DZR1_AMTZ_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZRREGISTER2021)+RECORDNUMBER(11)):
      (*multer) = 1;
      (*editValue) = (uint32_t*)&edition_settings.timeout_nkn_dzr[grupa_ustavok];
      if(regUst<TIMEOUT_NKN_DZR_MIN || regUst>TIMEOUT_NKN_DZR_MAX) diapazon=0;
      break;

    case (FILENUMBER(FILEPROT_DZRREGISTER2021)+RECORDNUMBER(105)):
    (*multer) = 1;
    (*editValue) = (uint32_t*)&edition_settings.pickup_dzr2_angle[grupa_ustavok];
    if(regUst>65000 && regUst<65536+PICKUP_DZR2_ANGLE_MIN) diapazon=0;
    if(regUst<65000 && regUst>PICKUP_DZR2_ANGLE_MAX) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZRREGISTER2021)+RECORDNUMBER(106)):
    (*editValue) = (uint32_t*)&edition_settings.pickup_dzr2_dir[grupa_ustavok];
    if(regUst<PICKUP_DZR2_DIR_MIN/10 || regUst>PICKUP_DZR2_DIR_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZRREGISTER2021)+RECORDNUMBER(107)):
    (*editValue) = (uint32_t*)&edition_settings.pickup_dzr2_inv[grupa_ustavok];
    if(regUst<PICKUP_DZR2_INV_MIN/10 || regUst>PICKUP_DZR2_INV_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZRREGISTER2021)+RECORDNUMBER(108)):
    (*editValue) = (uint32_t*)&edition_settings.pickup_dzr2_amtz[grupa_ustavok];
    if(regUst<PICKUP_DZR2_AMTZ_MIN/10 || regUst>PICKUP_DZR2_AMTZ_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZRREGISTER2021)+RECORDNUMBER(109)):
    (*editValue) = (uint32_t*)&edition_settings.timeout_dzr2_dir[grupa_ustavok];
    if(regUst<TIMEOUT_DZR2_DIR_MIN/10 || regUst>TIMEOUT_DZR2_DIR_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZRREGISTER2021)+RECORDNUMBER(110)):
    (*editValue) = (uint32_t*)&edition_settings.timeout_dzr2_dir_pr[grupa_ustavok];
    if(regUst<TIMEOUT_DZR2_DIR_PR_MIN/10 || regUst>TIMEOUT_DZR2_DIR_PR_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZRREGISTER2021)+RECORDNUMBER(111)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_dzr2_inv[grupa_ustavok];
      if(regUst<TIMEOUT_DZR2_INV_MIN/10 || regUst>TIMEOUT_DZR2_INV_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZRREGISTER2021)+RECORDNUMBER(112)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_dzr2_inv_pr[grupa_ustavok];
      if(regUst<TIMEOUT_DZR2_INV_PR_MIN/10 || regUst>TIMEOUT_DZR2_INV_PR_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZRREGISTER2021)+RECORDNUMBER(113)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_dzr2_amtz[grupa_ustavok];
      if(regUst<TIMEOUT_DZR2_AMTZ_MIN/10 || regUst>TIMEOUT_DZR2_AMTZ_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZRREGISTER2021)+RECORDNUMBER(114)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_dzr2_amtz_pr[grupa_ustavok];
      if(regUst<TIMEOUT_DZR2_AMTZ_PR_MIN/10 || regUst>TIMEOUT_DZR2_AMTZ_PR_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZRREGISTER2021)+RECORDNUMBER(115)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_dzr2_vvid_pr[grupa_ustavok];
      if(regUst<TIMEOUT_DZR2_VVID_PR_MIN/10 || regUst>TIMEOUT_DZR2_VVID_PR_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZRREGISTER2021)+RECORDNUMBER(116)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_dzr2_amtz_vvid_pr[grupa_ustavok];
      if(regUst<TIMEOUT_DZR2_AMTZ_VVID_PR_MIN/10 || regUst>TIMEOUT_DZR2_AMTZ_VVID_PR_MAX/10) diapazon=0;
      break;

    case (FILENUMBER(FILEPROT_DZRREGISTER2021)+RECORDNUMBER(205)):
      (*multer) = 1;
      (*editValue) = (uint32_t*)&edition_settings.pickup_dzr3_angle_h[grupa_ustavok];
      if(regUst>65000 && regUst<65536+PICKUP_DZR3_ANGLE_H_MIN) diapazon=0;
      if(regUst<65000 && regUst>PICKUP_DZR3_ANGLE_H_MAX) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZRREGISTER2021)+RECORDNUMBER(206)):
      (*multer) = 1;
      (*editValue) = (uint32_t*)&edition_settings.pickup_dzr3_angle_l[grupa_ustavok];
      if(regUst>65000 && regUst<65536+PICKUP_DZR3_ANGLE_L_MIN) diapazon=0;
      if(regUst<65000 && regUst>PICKUP_DZR3_ANGLE_L_MAX) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZRREGISTER2021)+RECORDNUMBER(207)):
      (*editValue) = (uint32_t*)&edition_settings.pickup_dzr3_dir[grupa_ustavok];
      if(regUst<PICKUP_DZR3_DIR_MIN/10 || regUst>PICKUP_DZR3_DIR_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZRREGISTER2021)+RECORDNUMBER(208)):
      (*editValue) = (uint32_t*)&edition_settings.pickup_dzr3_inv[grupa_ustavok];
      if(regUst<PICKUP_DZR3_INV_MIN/10 || regUst>PICKUP_DZR3_INV_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZRREGISTER2021)+RECORDNUMBER(209)):
      (*editValue) = (uint32_t*)&edition_settings.pickup_dzr3_amtz[grupa_ustavok];
      if(regUst<PICKUP_DZR3_AMTZ_MIN/10 || regUst>PICKUP_DZR3_AMTZ_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZRREGISTER2021)+RECORDNUMBER(210)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_dzr3_dir[grupa_ustavok];
      if(regUst<TIMEOUT_DZR3_DIR_MIN/10 || regUst>TIMEOUT_DZR3_DIR_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZRREGISTER2021)+RECORDNUMBER(211)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_dzr3_dir_pr[grupa_ustavok];
      if(regUst<TIMEOUT_DZR3_DIR_PR_MIN/10 || regUst>TIMEOUT_DZR3_DIR_PR_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZRREGISTER2021)+RECORDNUMBER(212)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_dzr3_inv[grupa_ustavok];
      if(regUst<TIMEOUT_DZR3_INV_MIN/10 || regUst>TIMEOUT_DZR3_INV_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZRREGISTER2021)+RECORDNUMBER(213)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_dzr3_inv_pr[grupa_ustavok];
      if(regUst<TIMEOUT_DZR3_INV_PR_MIN/10 || regUst>TIMEOUT_DZR3_INV_PR_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZRREGISTER2021)+RECORDNUMBER(214)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_dzr3_amtz[grupa_ustavok];
      if(regUst<TIMEOUT_DZR3_AMTZ_MIN/10 || regUst>TIMEOUT_DZR3_AMTZ_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZRREGISTER2021)+RECORDNUMBER(215)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_dzr3_amtz_pr[grupa_ustavok];
      if(regUst<TIMEOUT_DZR3_AMTZ_PR_MIN/10 || regUst>TIMEOUT_DZR3_AMTZ_PR_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZRREGISTER2021)+RECORDNUMBER(216)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_dzr3_vvid_pr[grupa_ustavok];
      if(regUst<TIMEOUT_DZR3_VVID_PR_MIN/10 || regUst>TIMEOUT_DZR3_VVID_PR_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPROT_DZRREGISTER2021)+RECORDNUMBER(217)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_dzr3_amtz_vvid_pr[grupa_ustavok];
      if(regUst<TIMEOUT_DZR3_AMTZ_VVID_PR_MIN/10 || regUst>TIMEOUT_DZR3_AMTZ_VVID_PR_MAX/10) diapazon=0;
      break;
////DZR-DZR-DZR-DZR-DZR-DZR-DZR-DZR-DZR-DZR-DZR-DZR-DZR-DZR-DZR-DZR-DZR-DZR-DZR-
////OMP+OMP+OMP+OMP+OMP+OMP+OMP+OMP+OMP+OMP+OMP+OMP+OMP+OMP+OMP+OMP+OMP+
    case (FILENUMBER(FILEPERIF_OMPREGISTER2021)+RECORDNUMBER(5)):
      (*multer) = 1;
      (*editValue) = (uint32_t*)&edition_settings.lines[0];
      if(regUst<NUMBER_LINES_FORWARD_MIN || regUst>NUMBER_LINES_MAX) diapazon=0;
      break;
    case (FILENUMBER(FILEPERIF_OMPREGISTER2021)+RECORDNUMBER(22)):
      (*multer) = 1;
      (*editValue) = (uint32_t*)&edition_settings.lines[1];
      if(regUst<NUMBER_LINES_BACKWARD_MIN || regUst>NUMBER_LINES_MAX) diapazon=0;
      break;
////OMP-OMP-OMP-OMP-OMP-OMP-OMP-OMP-OMP-OMP-OMP-OMP-OMP-OMP-OMP-OMP-OMP-
////CTRLVV+CTRLVV+CTRLVV+CTRLVV+CTRLVV+CTRLVV+CTRLVV+CTRLVV+CTRLVV+CTRLVV+
    case (FILENUMBER(FILEPERIF_CTRLVVREGISTER2021)+RECORDNUMBER(5)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_swch_udl_blk_on;
      if(regUst<TIMEOUT_SWCH_UDL_BLK_ON_MIN/10 || regUst>TIMEOUT_SWCH_UDL_BLK_ON_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPERIF_CTRLVVREGISTER2021)+RECORDNUMBER(6)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_swch_on;
      if(regUst<TIMEOUT_SWCH_ON_MIN/10 || regUst>TIMEOUT_SWCH_ON_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPERIF_CTRLVVREGISTER2021)+RECORDNUMBER(7)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_swch_off;
      if(regUst<TIMEOUT_SWCH_OFF_MIN/10 || regUst>TIMEOUT_SWCH_OFF_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPERIF_CTRLVVREGISTER2021)+RECORDNUMBER(8)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_pryvoda_VV;
      if(regUst<TIMEOUT_PRYVODA_VV_MIN/10 || regUst>TIMEOUT_PRYVODA_VV_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPERIF_CTRLVVREGISTER2021)+RECORDNUMBER(15)):
      (*multer) = 1;
      (*editValue) = (uint32_t*)&edition_settings.setpoint_Inom;
      if(regUst<SETPOINT_Inom_MIN || regUst>SETPOINT_Inom_MAX) diapazon=0;
      break;
    case (FILENUMBER(FILEPERIF_CTRLVVREGISTER2021)+RECORDNUMBER(16)):
      (*editValue) = (uint32_t*)&edition_settings.setpoint_r_kom_st_Inom;
      if(regUst<SETPOINT_RKS_Inom_MIN/10 || regUst>SETPOINT_RKS_Inom_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPERIF_CTRLVVREGISTER2021)+RECORDNUMBER(17)):
      (*multer) = 1;
      (*editValue) = (uint32_t*)&edition_settings.setpoint_Inom_vymk;
      if(regUst<SETPOINT_Inom_vymk_MIN || regUst>SETPOINT_Inom_vymk_MAX) diapazon=0;
      break;
    case (FILENUMBER(FILEPERIF_CTRLVVREGISTER2021)+RECORDNUMBER(18)):
      (*multer) = 1;
      (*editValue) = (uint32_t*)&edition_settings.setpoint_r_kom_st_Inom_vymk;
      if(regUst<SETPOINT_RKS_Inom_vymk_MIN || regUst>SETPOINT_RKS_Inom_vymk_MAX) diapazon=0;
      break;
    case (FILENUMBER(FILEPERIF_CTRLVVREGISTER2021)+RECORDNUMBER(19)):
      (*multer) = 1;
      (*editValue) = (uint32_t*)&edition_settings.setpoint_pochatkovyj_resurs;
      break;
    case (FILENUMBER(FILEPERIF_CTRLVVREGISTER2021)+RECORDNUMBER(20)):
      (*multer) = 1;
      (*editValue) = (uint32_t*)&edition_settings.setpoint_krytychnyj_resurs;
      break;
    case (FILENUMBER(FILEPERIF_CTRLVVREGISTER2021)+RECORDNUMBER(21)):
      (*multer) = 1;
      (*editValue) = (uint32_t*)&edition_settings.setpoint_pochatkova_k_vymk;
      break;

    case (FILENUMBER(FILEPERIF_CTRLVVREGISTER2021)+RECORDNUMBER(105)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_swch_udl_blk_on_[0];
      if(regUst<TIMEOUT_SWCH_UDL_BLK_ON_MIN/10 || regUst>TIMEOUT_SWCH_UDL_BLK_ON_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPERIF_CTRLVVREGISTER2021)+RECORDNUMBER(106)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_swch_on_[0];
      if(regUst<TIMEOUT_SWCH_ON_MIN/10 || regUst>TIMEOUT_SWCH_ON_MAX/10) diapazon=0;
      break;
    case (FILENUMBER(FILEPERIF_CTRLVVREGISTER2021)+RECORDNUMBER(107)):
      (*editValue) = (uint32_t*)&edition_settings.timeout_swch_off_[0];
      if(regUst<TIMEOUT_SWCH_OFF_MIN/10 || regUst>TIMEOUT_SWCH_OFF_MAX/10) diapazon=0;
      break;
////CTRLVV-CTRLVV-CTRLVV-CTRLVV-CTRLVV-CTRLVV-CTRLVV-CTRLVV-CTRLVV-CTRLVV-CTRLVV-
////TRANS+TRANS+TRANS+TRANS+TRANS+TRANS+TRANS+TRANS+TRANS+TRANS+TRANS+TRANS+TRANS+
    case (FILENUMBER(FILEPERIF_TRANSREGISTER2021)+RECORDNUMBER(2)):
      (*multer) = 1;
      (*editValue) = (uint32_t*)&edition_settings.Tmn;
      if(regUst<KOEF_T_OSN_MIN || regUst>KOEF_T_OSN_MAX) diapazon=0;
      break;
    case (FILENUMBER(FILEPERIF_TRANSREGISTER2021)+RECORDNUMBER(5)):
      (*multer) = 1;
      (*editValue) = (uint32_t*)&edition_settings.Tbp;
      if(regUst<KOEF_T_RSV_MIN || regUst>KOEF_T_RSV_MAX) diapazon=0;
      break;
////TRANS-TRANS-TRANS-TRANS-TRANS-TRANS-TRANS-TRANS-TRANS-TRANS-TRANS-TRANS-TRANS-
////PKV1+PKV1+PKV1+PKV1+PKV1+PKV1+PKV1+PKV1+PKV1+PKV1+PKV1+PKV1+PKV1+PKV1+PKV1+
    case (FILENUMBER(FILEPERIF_PKV1REGISTER2021)+RECORDNUMBER(1)):
      (*multer) = 1;
      //Язык пользовательского интерфейса
      (*editValue) = (uint32_t *)&edition_settings.language;
      if(regUst<VALUE_SETTING_LANGUAGE_MIN || regUst>VALUE_SETTING_LANGUAGE_MAX) diapazon=0;
      break;
////PKV1-PKV1-PKV1-PKV1-PKV1-PKV1-PKV1-PKV1-PKV1-PKV1-PKV1-PKV1-PKV1-PKV1-PKV1-
////PKV2+PKV2+PKV2+PKV2+PKV2+PKV2+PKV2+PKV2+PKV2+PKV2+PKV2+PKV2+PKV2+PKV2+
    case (FILENUMBER(FILEPERIF_PKV2REGISTER2021)+RECORDNUMBER(2)):
      (*multer) = 1;
      switch(pointInterface)//Время активации пароля после простоя
      {
      case USB_RECUEST:
        (*editValue) = &edition_settings.timeout_deactivation_password_interface_USB;
        break;
      case RS485_RECUEST:
        (*editValue) = &edition_settings.timeout_deactivation_password_interface_RS485;
        break;
      }//switch
      break;
    case (FILENUMBER(FILEPERIF_PKV2REGISTER2021)+RECORDNUMBER(3)):
      (*multer) = 1;
      //Тайм-аут применения изменений
      (*editValue) = &edition_settings.timeout_idle_new_settings;
      if(regUst<TIMEOUT_NEW_SETTINGS_MIN || regUst>TIMEOUT_NEW_SETTINGS_MAX) diapazon=0;
      break;
////PKV2-PKV2-PKV2-PKV2-PKV2-PKV2-PKV2-PKV2-PKV2-PKV2-PKV2-PKV2-PKV2-PKV2-
////PKV4+PKV4+PKV4+PKV4+PKV4+PKV4+PKV4+PKV4+PKV4+PKV4+PKV4+PKV4+PKV4+PKV4+
    case (FILENUMBER(FILEPERIF_PKV4REGISTER2021)+RECORDNUMBER(2)):
      switch(registerNumber)
      {
      case 1:
        //Скорость порта связи
        (*multer) = 1;
        (*editValue) = (uint32_t *)&edition_settings.speed_RS485;
        if(regUst<VALUE_SPEED_INTERFACE_MIN || regUst>VALUE_SPEED_INTERFACE_MAX) diapazon=0;
        break;
      case 3://Паритет
        (*multer) = 1;
        (*editValue) = (uint32_t *)&edition_settings.pare_bit_RS485;
        if(regUst<VALUE_PARE_INTERFACE_MIN || regUst>VALUE_PARE_INTERFACE_MAX) diapazon=0;
        break;
      case 4://Количество стоп-бит
        (*multer) = 1;
        (*editValue) = (uint32_t *)&edition_settings.number_stop_bit_RS485;
        if(regUst<1 || regUst>MAX_NUMBER_STOP_BITS_INTERFACE) diapazon=0;
        break;
      }//switch
      break;
    case (FILENUMBER(FILEPERIF_PKV4REGISTER2021)+RECORDNUMBER(3)):
      //Задержка приёма
      (*multer) = 1;
      (*editValue) = &edition_settings.time_out_1_RS485;
      if(regUst<VALUE_TIME_OUT_1_INTERFACE_MIN || regUst>VALUE_TIME_OUT_1_INTERFACE_MAX) diapazon=0;
      break;
////PKV4-PKV4-PKV4-PKV4-PKV4-PKV4-PKV4-PKV4-PKV4-PKV4-PKV4-PKV4-PKV4-PKV4-PKV4-
////PKV6+PKV6+PKV6+PKV6+PKV6+PKV6+PKV6+PKV6+PKV6+PKV6+PKV6+PKV6+PKV6+PKV6+PKV6+
    case (FILENUMBER(FILEPERIF_PKV6REGISTER2021)+RECORDNUMBER(2)):
      //Адрес устройства в сети
      (*multer) = 1;
      (*editValue) = &edition_settings.address;
      if(regUst<KOEF_ADDRESS_MIN || regUst>KOEF_ADDRESS_MAX) diapazon=0;
      break;
////PKV6-PKV6-PKV6-PKV6-PKV6-PKV6-PKV6-PKV6-PKV6-PKV6-PKV6-PKV6-PKV6-PKV6-PKV6-
////REGANL+REGANL+REGANL+REGANL+REGANL+REGANL+REGANL+REGANL+REGANL+REGANL+REGANL+
    case (FILENUMBER(FILEPERIF_REGANLREGISTER2021)+RECORDNUMBER(1)):
      switch(registerNumber)
      {
      case 1:
        (*multer) = 1;
        //Время записи аналогового регистратора (доаварийный массив)
        //В таблицю настройок записуємо не мілісекунди, а кількість періодів
        (*editValue) = (uint32_t*)&edition_settings.prefault_number_periods;
        if(regUst<TIMEOUT_PREFAULT_MIN/20 || regUst>TIMEOUT_PREFAULT_MAX/20)  diapazon=0;
        break;
      case 2:
        (*multer) = 1;
        //Время записи аналогового регистратора (послеаварый массив)
        //В таблицю настройок записуємо не мілісекунди, а кількість періодів
        (*editValue) = (uint32_t*)&edition_settings.postfault_number_periods;
        if(regUst<TIMEOUT_POSTFAULT_MIN/20 || regUst>TIMEOUT_POSTFAULT_MAX/20)  diapazon=0;
        break;
      }//switch
      break;
////REGANL-REGANL-REGANL-REGANL-REGANL-REGANL-REGANL-REGANL-REGANL-REGANL-REGANL-
////REGDIS+REGDIS+REGDIS+REGDIS+REGDIS+REGDIS+REGDIS+REGDIS+REGDIS+REGDIS+REGDIS+
    case (FILENUMBER(FILEPERIF_REGDISREGISTER2021)+RECORDNUMBER(1)):
      //Выдержка доаварийного массива DR
      (*editValue) = (uint32_t*)&edition_settings.timeout_prolongation_work_digital_registrator;
      if(regUst<TIMEOUT_DR_ELONGATION_MIN/10 || regUst>TIMEOUT_DR_ELONGATION_MAX/10) diapazon=0;
      break;
////REGDIS-REGDIS-REGDIS-REGDIS-REGDIS-REGDIS-REGDIS-REGDIS-REGDIS-REGDIS-REGDIS-
    }//switch
  return diapazon;
}//ustFunc000for2021




