#ifndef __COMPONENTENUM_H
#define __COMPONENTENUM_H

enum {
 IUSMALLCOMPONENT        ,//0
 ACMDSMALLCOMPONENT      ,//2
 GCMDSMALLCOMPONENT      ,//10
 RPRSMALLCOMPONENT       ,//20
 DOUTSMALLCOMPONENT      ,//4
 DVSMALLCOMPONENT        ,//9
 KEYSMALLCOMPONENT       ,//9
 SDISMALLCOMPONENT       ,//22
 AISMALLCOMPONENT        ,//26
 PKVBIGCOMPONENT         ,//15
 REG1BIGCOMPONENT        ,//18
 REG2BIGCOMPONENT        ,//18
 YUSTBIGCOMPONENT        ,//25
 PREGBIGCOMPONENT        ,//17

 TOTAL_COMPONENT         ,//26

 MARKER_OUTPERIMETR   = 100000,
 MARKER_ERRORPERIMETR = 100001,
 MARKER_ERRORDIAPAZON = 100002,
 MARKER_ERRORPAROL    = 100003
};

enum {

#define FILEUVV_DOUTREGISTER2021 100
#define FILEUVV_DVREGISTER2021   103
#define FILEUVV_SDIREGISTER2021  104
#define FILEUVV_KEYREGISTER2021  105
#define FILEUVV_RPRREGISTER2021  110
#define FILEUVV_BEGCOMPONENT2021 FILEUVV_DOUTREGISTER2021
#define FILEUVV_ENDCOMPONENT2021 FILEUVV_RPRREGISTER2021
 UVVCOMPONENT2021,

#define FILEPROT_COMMREGISTER2021   111
#define FILEPROT_MTZOREGISTER2021   112
#define FILEPROT_MTZRREGISTER2021   114
#define FILEPROT_ZNMINREGISTER2021  122
#define FILEPROT_ZNMAXREGISTER2021  123
#define FILEPROT_APVREGISTER2021    128
#define FILEPROT_UROVREGISTER2021   129
#define FILEPROT_AJRREGISTER2021    133
#define FILEPROT_JAPVREGISTER2021   134
#define FILEPROT_UPREGISTER2021     136
#define FILEPROT_DZOREGISTER2021    138
#define FILEPROT_DZRREGISTER2021    139
#define FILEPROT_OMPREGISTER2021    144
#define FILEPROT_BEGCOMPONENT2021 FILEPROT_COMMREGISTER2021
#define FILEPROT_ENDCOMPONENT2021 FILEPROT_OMPREGISTER2021
 PROTCOMPONENT2021,

#define FILEPERIF_OMPREGISTER2021      141
#define FILEPERIF_CTRLVVREGISTER2021   145
#define FILEPERIF_TRANSREGISTER2021    146
#define FILEPERIF_ELMFTREGISTER2021    148
#define FILEPERIF_ELDTRREGISTER2021    149
#define FILEPERIF_ELANDREGISTER2021    150
#define FILEPERIF_ELORREGISTER2021     151
#define FILEPERIF_ELXORREGISTER2021    152
#define FILEPERIF_ELNOTREGISTER2021    153
#define FILEPERIF_ELPFREGISTER2021     157
#define FILEPERIF_PKV1REGISTER2021     200
#define FILEPERIF_PKV2REGISTER2021     201
#define FILEPERIF_PKV3REGISTER2021     202
#define FILEPERIF_PKV4REGISTER2021     203
#define FILEPERIF_PKV5REGISTER2021     205
#define FILEPERIF_PKV6REGISTER2021     206
#define FILEPERIF_REGANLREGISTER2021   300
#define FILEPERIF_ANLCONF1REGISTER20   301
#define FILEPERIF_ANLDATA1REGISTER20   302
#define FILEPERIF_ANLDATA2REGISTER20   303
#define FILEPERIF_ANLDATA3REGISTER20   304
#define FILEPERIF_ANLDATA4REGISTER20   305
#define FILEPERIF_ANLDATA5REGISTER20   306
#define FILEPERIF_ANLDATA6REGISTER20   307
#define FILEPERIF_ANLDATA7REGISTER20   308
#define FILEPERIF_ANLDATA8REGISTER20   309
#define FILEPERIF_REGDISREGISTER2021   310
#define FILEPERIF_DRCONF1REGISTER20    311
#define FILEPERIF_DRDATA1REGISTER20    312
#define FILEPERIF_DRDATA2REGISTER20    313
#define FILEPERIF_RAIREGISTER20        314
#define FILEPERIF_DSREGREGISTER20      400
#define FILEPERIF_BEGCOMPONENT2021 FILEPERIF_CTRLVVREGISTER2021
#define FILEPERIF_ENDCOMPONENT2021 FILEPERIF_DSREGREGISTER20
 PERIFCOMPONENT2021,

 TOTAL_COMPONENT2021
};

//���� ������ ������ ������
#define MAXIMUMTW 128
//������ ���������
#define ERROR_VALID2 2
#define ERROR_VALID3 3

#endif
