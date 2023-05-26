#ifndef __CONST_MENU_ZDZ__
#define __CONST_MENU_ZDZ__

#define EKRAN_TIMEOUT_ZDZ_GROUP1    (EKRAN_CONTROL_DZ + 1)
#define EKRAN_TIMEOUT_ZDZ_GROUP2    (EKRAN_TIMEOUT_ZDZ_GROUP1 + 1)
#define EKRAN_TIMEOUT_ZDZ_GROUP3    (EKRAN_TIMEOUT_ZDZ_GROUP2 + 1)
#define EKRAN_TIMEOUT_ZDZ_GROUP4    (EKRAN_TIMEOUT_ZDZ_GROUP3 + 1)
#define EKRAN_CONTROL_ZDZ           (EKRAN_TIMEOUT_ZDZ_GROUP4 + 1)

enum _index_ml_tmo_zdz
{
  INDEX_ML_TMOZDZ = 0,
  
  MAX_ROW_FOR_TIMEOUT_ZDZ
};

#define COL_TMO_ZDZ_BEGIN             5
#define COL_TMO_ZDZ_COMMA             6
#define COL_TMO_ZDZ_END               9

enum _control_type
{
  _ZDZ_CTRL_MIN = 0,
  
  ZDZ_CTRL_NONE = _ZDZ_CTRL_MIN,
  ZDZ_CTRL_I,
  ZDZ_CTRL_U,
  ZDZ_CTRL_I_OR_U,
  ZDZ_CTRL_I_AND_U,
//  ZDZ_CTRL_3I0,
  
  _ZDZ_CTRL_MAX = ZDZ_CTRL_I_AND_U,//  _ZDZ_CTRL_MAX = ZDZ_CTRL_3I0,
  
  _ZDZ_CTRL_NUMBER
};

#define ZDZ_CTRL_PORIG_N        12

enum _index_ml_ctrl_zdz
{
  _CTR_ZDZ_PART_I = 0, 
  CTR_ZDZ_STATE_BIT = _CTR_ZDZ_PART_I,

#if (                                   \
     (MODYFIKACIA_VERSII_PZ == 0) ||    \
     (MODYFIKACIA_VERSII_PZ == 3)       \
    )   
  CTR_ZDZ_OVD1_STATE_BIT,
  CTR_ZDZ_OVD2_STATE_BIT,
  CTR_ZDZ_OVD3_STATE_BIT,
  
  _CTR_ZDZ_PART_II,
  
  CTR_ZDZ_PORIG = _CTR_ZDZ_PART_II,
  CTR_ZDZ_CTRL_TYPE,
#else
  
  _CTR_ZDZ_PART_II,
  
  CTR_ZDZ_CTRL_TYPE = _CTR_ZDZ_PART_II,
#endif
  
  _CTR_ZDZ_PART_III,
  CTR_ZDZ_STARTED_FROM_MTZ1_BIT = _CTR_ZDZ_PART_III,
  CTR_ZDZ_STARTED_FROM_MTZ2_BIT,
  CTR_ZDZ_STARTED_FROM_MTZ3_BIT,
  CTR_ZDZ_STARTED_FROM_MTZ4_BIT,
  CTR_ZDZ_STARTED_FROM_UMIN1_BIT,
  CTR_ZDZ_STARTED_FROM_UMIN2_BIT,
  
  _CTR_ZDZ_NEXT_BIT,
  MAX_ROW_FOR_CONTROL_ZDZ = _CTR_ZDZ_NEXT_BIT
};

#if (                                   \
     (MODYFIKACIA_VERSII_PZ == 0) ||    \
     (MODYFIKACIA_VERSII_PZ == 3)       \
    )   

#define CTR_ZDZ_MASKA                 (                                                                                           \
                                       MASKA_FOR_BIT(CTR_ZDZ_STATE_BIT)                                                         | \
                                       MASKA_FOR_BIT(CTR_ZDZ_OVD1_STATE_BIT)                                                    | \
                                       MASKA_FOR_BIT(CTR_ZDZ_OVD2_STATE_BIT)                                                    | \
                                       MASKA_FOR_BIT(CTR_ZDZ_OVD3_STATE_BIT)                                                    | \
                                       MASKA_FOR_BIT(CTR_ZDZ_STARTED_FROM_MTZ1_BIT  - (_CTR_ZDZ_PART_III - _CTR_ZDZ_PART_II))   | \
                                       MASKA_FOR_BIT(CTR_ZDZ_STARTED_FROM_MTZ2_BIT  - (_CTR_ZDZ_PART_III - _CTR_ZDZ_PART_II))   | \
                                       MASKA_FOR_BIT(CTR_ZDZ_STARTED_FROM_MTZ3_BIT  - (_CTR_ZDZ_PART_III - _CTR_ZDZ_PART_II))   | \
                                       MASKA_FOR_BIT(CTR_ZDZ_STARTED_FROM_MTZ4_BIT  - (_CTR_ZDZ_PART_III - _CTR_ZDZ_PART_II))   | \
                                       MASKA_FOR_BIT(CTR_ZDZ_STARTED_FROM_UMIN1_BIT - (_CTR_ZDZ_PART_III - _CTR_ZDZ_PART_II))   | \
                                       MASKA_FOR_BIT(CTR_ZDZ_STARTED_FROM_UMIN2_BIT - (_CTR_ZDZ_PART_III - _CTR_ZDZ_PART_II))     \
                                      )
#else

#define CTR_ZDZ_MASKA                 (                                                                                           \
                                       MASKA_FOR_BIT(CTR_ZDZ_STATE_BIT)                                                         | \
                                       MASKA_FOR_BIT(CTR_ZDZ_STARTED_FROM_MTZ1_BIT  - (_CTR_ZDZ_PART_III - _CTR_ZDZ_PART_II))   | \
                                       MASKA_FOR_BIT(CTR_ZDZ_STARTED_FROM_MTZ2_BIT  - (_CTR_ZDZ_PART_III - _CTR_ZDZ_PART_II))   | \
                                       MASKA_FOR_BIT(CTR_ZDZ_STARTED_FROM_MTZ3_BIT  - (_CTR_ZDZ_PART_III - _CTR_ZDZ_PART_II))   | \
                                       MASKA_FOR_BIT(CTR_ZDZ_STARTED_FROM_MTZ4_BIT  - (_CTR_ZDZ_PART_III - _CTR_ZDZ_PART_II))   | \
                                       MASKA_FOR_BIT(CTR_ZDZ_STARTED_FROM_UMIN1_BIT - (_CTR_ZDZ_PART_III - _CTR_ZDZ_PART_II))   | \
                                       MASKA_FOR_BIT(CTR_ZDZ_STARTED_FROM_UMIN2_BIT - (_CTR_ZDZ_PART_III - _CTR_ZDZ_PART_II))     \
                                      )

#endif

#endif
