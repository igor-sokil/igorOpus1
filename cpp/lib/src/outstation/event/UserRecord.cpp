#include "header.h"
#include "UserRecord.h"

void UserData_in_UserData(UserData *pUserData)
{
 pUserData -> data1 = 0;
 pUserData -> data2 = 0;
}

void UserRecord_in_UserRecord(UserRecord *pUserRecord)
{
 pUserRecord->index = 0;
 UserData_in_UserData(&(pUserRecord->uUserData));
}
