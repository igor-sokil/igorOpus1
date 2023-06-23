#include "header.h"
#include "DNP3Serializer.h"
//-----------------------------DNP3Serializer_for_FrozenCounter-------------------------------------------

    GroupVariationID ID_in_DNP3Serializer_for_FrozenCounter(DNP3Serializer_for_FrozenCounter *pDNP3Serializer_for_FrozenCounter) 
{
    return pDNP3Serializer_for_FrozenCounter->id;
}
    void DNP3Serializer_for_FrozenCounter_in_DNP3Serializer_for_FrozenCounter(DNP3Serializer_for_FrozenCounter *pDNP3Serializer_for_FrozenCounter,
                   GroupVariationID id,
                   uint16_t size,
////                   typename Serializer<T>::read_func_t read_func,
                   read_func_t_in_Serializer_for_FrozenCounter read_func, 
////                   typename Serializer<T>::write_func_t write_func)
                   write_func_t_in_Serializer_for_FrozenCounter write_func)
{
////        : Serializer<T>(size, read_func, write_func), id(id)
  pDNP3Serializer_for_FrozenCounter->id = id;
  Serializer_for_FrozenCounter_in_Serializer_for_FrozenCounter(&(pDNP3Serializer_for_FrozenCounter->sSerializer_for_FrozenCounter),
                                                  size,
                                               read_func,
                                               write_func);

}
//-----------------------------DNP3Serializer_for_FrozenCounter-------------------------------------------
//-----------------------------DNP3Serializer_for_BinaryOutputStatus-------------------------------------------

    GroupVariationID ID_in_DNP3Serializer_for_BinaryOutputStatus(DNP3Serializer_for_BinaryOutputStatus *pDNP3Serializer_for_BinaryOutputStatus) 
{
    return pDNP3Serializer_for_BinaryOutputStatus->id;
}
    void DNP3Serializer_for_BinaryOutputStatus_in_DNP3Serializer_for_BinaryOutputStatus(DNP3Serializer_for_BinaryOutputStatus *pDNP3Serializer_for_BinaryOutputStatus,
                   GroupVariationID id,
                   uint16_t size,
////                   typename Serializer<T>::read_func_t read_func,
                   read_func_t_in_Serializer_for_BinaryOutputStatus read_func, //read_func_t_in_Serializer_for_Binary rr,
////                   typename Serializer<T>::write_func_t write_func)
                   write_func_t_in_Serializer_for_BinaryOutputStatus write_func)//write_func_t_in_Serializer_for_Binary ww)
{
////        : Serializer<T>(size, read_func, write_func), id(id)
  pDNP3Serializer_for_BinaryOutputStatus->id = id;
  Serializer_for_BinaryOutputStatus_in_Serializer_for_BinaryOutputStatus(&(pDNP3Serializer_for_BinaryOutputStatus->sSerializer_for_BinaryOutputStatus),
                                                  size,
                                               read_func,//read_func_t_in_Serializer_for_Binary,
                                               write_func);//write_func_t_in_Serializer_for_Binary);

}
//-----------------------------DNP3Serializer_for_BinaryOutputStatus-------------------------------------------
//-----------------------------DNP3Serializer_for_DoubleBitBinary-------------------------------------------

    GroupVariationID ID_in_DNP3Serializer_for_DoubleBitBinary(DNP3Serializer_for_DoubleBitBinary *pDNP3Serializer_for_DoubleBitBinary) 
{
    return pDNP3Serializer_for_DoubleBitBinary->id;
}
    void DNP3Serializer_for_DoubleBitBinary_in_DNP3Serializer_for_DoubleBitBinary(DNP3Serializer_for_DoubleBitBinary *pDNP3Serializer_for_DoubleBitBinary,
                   GroupVariationID id,
                   uint16_t size,
////                   typename Serializer<T>::read_func_t read_func,
                   read_func_t_in_Serializer_for_DoubleBitBinary read_func, //read_func_t_in_Serializer_for_Binary rr,
////                   typename Serializer<T>::write_func_t write_func)
                   write_func_t_in_Serializer_for_DoubleBitBinary write_func)//write_func_t_in_Serializer_for_Binary ww)
{
////        : Serializer<T>(size, read_func, write_func), id(id)
  pDNP3Serializer_for_DoubleBitBinary->id = id;
  Serializer_for_DoubleBitBinary_in_Serializer_for_DoubleBitBinary(&(pDNP3Serializer_for_DoubleBitBinary->sSerializer_for_DoubleBitBinary),
                                                  size,
                                               read_func,//read_func_t_in_Serializer_for_Binary,
                                               write_func);//write_func_t_in_Serializer_for_Binary);

}
//-----------------------------DNP3Serializer_for_DoubleBitBinary-------------------------------------------
//-----------------------------DNP3Serializer_for_Binary-------------------------------------------

    GroupVariationID ID_in_DNP3Serializer_for_Binary(DNP3Serializer_for_Binary *pDNP3Serializer_for_Binary) 
{
    return pDNP3Serializer_for_Binary->id;
}
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
//-----------------------------DNP3Serializer_for_Binary-------------------------------------------
//-----------------------------DNP3Serializer_for_Counter-------------------------------------------

    GroupVariationID ID_in_DNP3Serializer_for_Counter(DNP3Serializer_for_Counter *pDNP3Serializer_for_Counter) 
{
    return pDNP3Serializer_for_Counter->id;
}
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
//-----------------------------DNP3Serializer_for_Counter-------------------------------------------
//-----------------------------DNP3Serializer_for_Analog-------------------------------------------

    GroupVariationID ID_in_DNP3Serializer_for_Analog(DNP3Serializer_for_Analog *pDNP3Serializer_for_Analog) 
{
    return pDNP3Serializer_for_Analog->id;
}
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
//-----------------------------DNP3Serializer_for_Analog-------------------------------------------
//-----------------------------DNP3Serializer_for_AnalogOutputStatus-------------------------------------------

    GroupVariationID ID_in_DNP3Serializer_for_AnalogOutputStatus(DNP3Serializer_for_AnalogOutputStatus *pDNP3Serializer_for_AnalogOutputStatus) 
{
    return pDNP3Serializer_for_AnalogOutputStatus->id;
}
    void DNP3Serializer_for_AnalogOutputStatus_in_DNP3Serializer_for_AnalogOutputStatus(DNP3Serializer_for_AnalogOutputStatus *pDNP3Serializer_for_AnalogOutputStatus,
                   GroupVariationID id,
                   uint16_t size,
////                   typename Serializer<T>::read_func_t read_func,
                   read_func_t_in_Serializer_for_AnalogOutputStatus read_func, 
////                   typename Serializer<T>::write_func_t write_func)
                   write_func_t_in_Serializer_for_AnalogOutputStatus write_func)
{
////        : Serializer<T>(size, read_func, write_func), id(id)
  pDNP3Serializer_for_AnalogOutputStatus->id = id;
  Serializer_for_AnalogOutputStatus_in_Serializer_for_AnalogOutputStatus(&(pDNP3Serializer_for_AnalogOutputStatus->sSerializer_for_AnalogOutputStatus),
                                                  size,
                                               read_func,
                                               write_func);

}
//-----------------------------DNP3Serializer_for_AnalogOutputStatus-------------------------------------------
//-----------------------------DNP3Serializer_for_TimeAndInterval-------------------------------------------

    GroupVariationID ID_in_DNP3Serializer_for_TimeAndInterval(DNP3Serializer_for_TimeAndInterval *pDNP3Serializer_for_TimeAndInterval) 
{
    return pDNP3Serializer_for_TimeAndInterval->id;
}
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
//-----------------------------DNP3Serializer_for_TimeAndInterval-------------------------------------------
