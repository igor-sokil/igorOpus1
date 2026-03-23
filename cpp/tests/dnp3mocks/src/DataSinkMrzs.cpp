
#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
//#include <QApplication>
#include "header.h"
#include "DataSinkMrzs.h"

void Write_in_DataSinkMrzs(DataSinkMrzs *pDataSinkMrzs, RSeq_for_Uint16_t* data)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  std::cout<<"{Write_in_DataSinkMrzs1"<<'\n';
  inspect_RSeq(data);
#endif
  pDataSinkMrzs->size_in_DataSinkMrzs = 0;
//    uint16_t length_in_HasLength_for_Uint16_t(HasLength_for_Uint16_t *pHasLength);
////    for (uint16_t i = 0; i < data.length(); ++i)
  for (uint16_t i = 0; i < length_in_HasLength_for_Uint16_t(&(data->hHasLength)); ++i)
  {
    pDataSinkMrzs->buffer_in_DataSinkMrzs[i] = data->buffer_[i];
//.push_back(data->buffer_[i]);////data[i]);
    pDataSinkMrzs->size_in_DataSinkMrzs ++;
  }
#ifdef  LOG_INFO
  std::cout<<"}Write_in_DataSinkMrzs_"<<'\n';
#endif
}

void Clear_in_DataSinkMrzs(DataSinkMrzs *pDataSinkMrzs)
{
//  pDataSinkMrzs->buffer_in_DataSink.clear();
  pDataSinkMrzs->size_in_DataSinkMrzs = 0;
}
