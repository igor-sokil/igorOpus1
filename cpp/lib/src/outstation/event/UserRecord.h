#ifndef OPENDNP3_USERRECORD_H
#define OPENDNP3_USERRECORD_H

typedef struct
{
  uint16_t data1;
  uint16_t data2;
} UserData;

void UserData_in_UserData(UserData *pUserData);

typedef struct
{
  uint16_t index;
  UserData uUserData;
} UserRecord;

void UserRecord_in_UserRecord(UserRecord *pUserRecord);

#endif
