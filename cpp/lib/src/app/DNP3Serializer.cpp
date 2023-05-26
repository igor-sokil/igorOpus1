#include "header.h"
#include "DNP3Serializer.h"
//-----------------------------DNP3Serializer_for_Binary-------------------------------------------

    GroupVariationID ID_in_DNP3Serializer_for_Binary(DNP3Serializer_for_Binary *pDNP3Serializer_for_Binary) 
{
    return pDNP3Serializer_for_Binary->id;
}
///*
    void DNP3Serializer_for_Binary_in_DNP3Serializer_for_Binary(DNP3Serializer_for_Binary *pDNP3Serializer_for_Binary,
                   GroupVariationID id,
                   uint16_t size,
////                   typename Serializer<T>::read_func_t read_func,
                   read_func_t_in_Serializer_for_Binary read_func, //read_func_t_in_Serializer_for_Binary rr,
////                   typename Serializer<T>::write_func_t write_func)
                   write_func_t_in_Serializer_for_Binary write_func)//write_func_t_in_Serializer_for_Binary ww)
{
////        : Serializer<T>(size, read_func, write_func), id(id)
  pDNP3Serializer_for_Binary->id = id;
  Serializer_for_Binary_in_Serializer_for_Binary(&(pDNP3Serializer_for_Binary->sSerializer_for_Binary),
                                                  size,
                                               read_func,//read_func_t_in_Serializer_for_Binary,
                                               write_func);//write_func_t_in_Serializer_for_Binary);

}
//*/
//-----------------------------DNP3Serializer_for_Binary-------------------------------------------
//-----------------------------DNP3Serializer_for_Counter-------------------------------------------

    GroupVariationID ID_in_DNP3Serializer_for_Counter(DNP3Serializer_for_Counter *pDNP3Serializer_for_Counter) 
{
    return pDNP3Serializer_for_Counter->id;
}
///*
    void DNP3Serializer_for_Counter_in_DNP3Serializer_for_Counter(DNP3Serializer_for_Counter *pDNP3Serializer_for_Counter,
                   GroupVariationID id,
                   uint16_t size,
////                   typename Serializer<T>::read_func_t read_func,
                   read_func_t_in_Serializer_for_Counter read_func, //read_func_t_in_Serializer_for_Binary rr,
////                   typename Serializer<T>::write_func_t write_func)
                   write_func_t_in_Serializer_for_Counter write_func)//write_func_t_in_Serializer_for_Binary ww)
{
////        : Serializer<T>(size, read_func, write_func), id(id)
  pDNP3Serializer_for_Counter->id = id;
  Serializer_for_Counter_in_Serializer_for_Counter(&(pDNP3Serializer_for_Counter->sSerializer_for_Counter),
                                                  size,
                                               read_func,//read_func_t_in_Serializer_for_Binary,
                                               write_func);//write_func_t_in_Serializer_for_Binary);

}
//*/
//-----------------------------DNP3Serializer_for_Counter-------------------------------------------
//-----------------------------DNP3Serializer_for_Analog-------------------------------------------

    GroupVariationID ID_in_DNP3Serializer_for_Analog(DNP3Serializer_for_Analog *pDNP3Serializer_for_Analog) 
{
    return pDNP3Serializer_for_Analog->id;
}
///*
    void DNP3Serializer_for_Analog_in_DNP3Serializer_for_Analog(DNP3Serializer_for_Analog *pDNP3Serializer_for_Analog,
                   GroupVariationID id,
                   uint16_t size,
////                   typename Serializer<T>::read_func_t read_func,
                   read_func_t_in_Serializer_for_Analog read_func, //read_func_t_in_Serializer_for_Binary rr,
////                   typename Serializer<T>::write_func_t write_func)
                   write_func_t_in_Serializer_for_Analog write_func)//write_func_t_in_Serializer_for_Binary ww)
{
////        : Serializer<T>(size, read_func, write_func), id(id)
  pDNP3Serializer_for_Analog->id = id;
  Serializer_for_Analog_in_Serializer_for_Analog(&(pDNP3Serializer_for_Analog->sSerializer_for_Analog),
                                                  size,
                                               read_func,//read_func_t_in_Serializer_for_Binary,
                                               write_func);//write_func_t_in_Serializer_for_Binary);

}
//*/
//-----------------------------DNP3Serializer_for_Analog-------------------------------------------
//-----------------------------DNP3Serializer_for_TimeAndInterval-------------------------------------------

    GroupVariationID ID_in_DNP3Serializer_for_TimeAndInterval(DNP3Serializer_for_TimeAndInterval *pDNP3Serializer_for_TimeAndInterval) 
{
    return pDNP3Serializer_for_TimeAndInterval->id;
}
///*
    void DNP3Serializer_for_TimeAndInterval_in_DNP3Serializer_for_TimeAndInterval(DNP3Serializer_for_TimeAndInterval *pDNP3Serializer_for_TimeAndInterval,
                   GroupVariationID id,
                   uint16_t size,
////                   typename Serializer<T>::read_func_t read_func,
                   read_func_t_in_Serializer_for_TimeAndInterval read_func, //read_func_t_in_Serializer_for_Binary rr,
////                   typename Serializer<T>::write_func_t write_func)
                   write_func_t_in_Serializer_for_TimeAndInterval write_func)//write_func_t_in_Serializer_for_Binary ww)
{
////        : Serializer<T>(size, read_func, write_func), id(id)
  pDNP3Serializer_for_TimeAndInterval->id = id;
  Serializer_for_TimeAndInterval_in_Serializer_for_TimeAndInterval(&(pDNP3Serializer_for_TimeAndInterval->sSerializer_for_TimeAndInterval),
                                                  size,
                                               read_func,//read_func_t_in_Serializer_for_Binary,
                                               write_func);//write_func_t_in_Serializer_for_Binary);

}
//*/
//-----------------------------DNP3Serializer_for_TimeAndInterval-------------------------------------------
