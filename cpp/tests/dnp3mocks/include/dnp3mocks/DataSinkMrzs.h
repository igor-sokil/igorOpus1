#ifndef OPENDNP3_UNITTESTS_DATASINKMRZS_H
#define OPENDNP3_UNITTESTS_DATASINKMRZS_H

#include "RSeq.h"

typedef struct
{

//  std::vector<uint8_t>
 uint8_t buffer_in_DataSinkMrzs[292];
 uint16_t size_in_DataSinkMrzs;
} DataSinkMrzs;

void Write_in_DataSinkMrzs(DataSinkMrzs *pDataSinkMrzs, RSeq_for_Uint16_t* data);

boolean IsEmpty_in_DataSinkMrzs(DataSinkMrzs *pDataSinkMrzs);
void Clear_in_DataSinkMrzs(DataSinkMrzs *pDataSinkMrzs);
uint16_t Size_in_DataSinkMrzs(DataSinkMrzs *pDataSinkMrzs);


#endif