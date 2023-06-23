#include "header.h"
#include "MeasurementFactory.h"

   Binary From_in_BinaryFactory_staticOver1(uint8_t flags)
{
    Binary bBinary;
    Binary_in_BinaryOver1(&bBinary);
    Flags fFlags;
    Flags_In_FlagsOver2(&fFlags, flags);
    Binary_in_BinaryOver3(&bBinary, fFlags);
//    return Binary(Flags(flags));
    return bBinary;
}

   Binary From_in_BinaryFactory_staticOver2(uint8_t flags, uint16_t timeDNPTime)
{
    DNPTime dDNPTime;
    DNPTime_in_DNPTimeOver2(&dDNPTime, (uint64_t)timeDNPTime);
    return From_in_BinaryFactory_staticOver3(flags, dDNPTime);//DNPTime(timeDNPTime));
}

   Binary From_in_BinaryFactory_staticOver3(uint8_t flags, DNPTime timeDNPTime)
{
    Binary bBinary;
    Binary_in_BinaryOver1(&bBinary);
    Flags fFlags;
    Flags_In_FlagsOver2(&fFlags, flags);
    Binary_in_BinaryOver4(&bBinary, fFlags, timeDNPTime);
//    return Binary(Flags(flags), timeDNPTime);
    return bBinary;
}

    DoubleBitBinary From_in_DoubleBitBinaryFactory_staticOver1(uint8_t flags)
{
    DoubleBitBinary dDoubleBitBinary;
    Flags fFlags;
    Flags_In_FlagsOver2(&fFlags, flags);
    DoubleBitBinary_in_DoubleBitBinaryOver3(&dDoubleBitBinary, fFlags);
//    return DoubleBitBinary(Flags(flags));
    return dDoubleBitBinary;
}

   DoubleBitBinary From_in_DoubleBitBinaryFactory_staticOver2(uint8_t flags, uint16_t timeDNPTime)
{
    DNPTime dDNPTime;
    DNPTime_in_DNPTimeOver2(&dDNPTime, (uint64_t)timeDNPTime);
    return From_in_DoubleBitBinaryFactory_staticOver3(flags, dDNPTime);//DNPTime(time));
}

   DoubleBitBinary From_in_DoubleBitBinaryFactory_staticOver3(uint8_t flags, DNPTime timeDNPTime)
{
    DoubleBitBinary dDoubleBitBinary;
    Flags fFlags;
    Flags_In_FlagsOver2(&fFlags, flags);
    DoubleBitBinary_in_DoubleBitBinaryOver4(&dDoubleBitBinary, fFlags, timeDNPTime);
//    return DoubleBitBinary(Flags(flags), time);
    return dDoubleBitBinary;
}

    Analog From_in_AnalogFactory_staticOver1(int32_t count)
    {
       Analog aAnalog;
       Analog_in_AnalogOver2(&aAnalog, (double)count);
//        return Analog((double)count);
       return aAnalog;
    }

    Analog From_in_AnalogFactory_staticOver2(uint8_t flags, double value)
    {
       Analog aAnalog;
       Flags fFlags;
       Flags_In_FlagsOver2(&fFlags, flags);
       Analog_in_AnalogOver3(&aAnalog, value, fFlags );
//        return Analog(value, Flags(flags));
       return aAnalog;
    }

    Analog From_in_AnalogFactory_staticOver3(uint8_t flags, double value, DNPTime timeDNPTime)
    {
       Analog aAnalog;
       Flags fFlags;
       Flags_In_FlagsOver2(&fFlags, flags);
       Analog_in_AnalogOver4(&aAnalog, value, fFlags, timeDNPTime);
//        return Analog(value, Flags(flags), time);
       return aAnalog;
    }

    Counter From_in_CounterFactory_staticOver1(uint32_t count)
{
    Counter cCounter;
    Counter_in_CounterOver2(&cCounter, count);
//    return Counter(count);
    return cCounter;
}

    Counter From_in_CounterFactory_staticOver2(uint8_t flags, uint32_t count)
{
    Counter cCounter;
    Flags fFlags;
    Flags_In_FlagsOver2(&fFlags, flags);
    Counter_in_CounterOver3(&cCounter, count, fFlags);
//    return Counter(count, Flags(flags));
    return cCounter;
}
   Counter From_in_CounterFactory_staticOver3(uint8_t flags, uint32_t count, DNPTime timeDNPTime)
{
    Counter cCounter;
    Flags fFlags;
    Flags_In_FlagsOver2(&fFlags, flags);
    Counter_in_CounterOver4(&cCounter, count, fFlags, timeDNPTime);
//    return Counter(count, Flags(flags), time);
    return cCounter;
}

     FrozenCounter From_in_FrozenCounterFactory_staticOver1(uint32_t count)
{
    FrozenCounter fFrozenCounter;
    FrozenCounter_in_FrozenCounterOver2(&fFrozenCounter, count);
//    return FrozenCounter(count);
    return fFrozenCounter;
}
    FrozenCounter From_in_FrozenCounterFactory_staticOver2(uint8_t flags, uint32_t count)
{
    FrozenCounter fFrozenCounter;
    Flags fFlags;
    Flags_In_FlagsOver2(&fFlags, flags);
    FrozenCounter_in_FrozenCounterOver3(&fFrozenCounter, count, fFlags);
//    return FrozenCounter(count, Flags(flags));
    return fFrozenCounter;
}
    FrozenCounter From_in_FrozenCounterFactory_staticOver3(uint8_t flags, uint32_t count, DNPTime timeDNPTime)
{
    FrozenCounter fFrozenCounter;
    Flags fFlags;
    Flags_In_FlagsOver2(&fFlags, flags);
    FrozenCounter_in_FrozenCounterOver4(&fFrozenCounter, count, fFlags, timeDNPTime);
//    return FrozenCounter(count, Flags(flags), time);
    return fFrozenCounter;
}

  TimeAndInterval From_in_TimeAndIntervalFactory_static(DNPTime timeDNPTime, uint32_t interval, uint8_t units)
{
    TimeAndInterval tTimeAndInterval;
    TimeAndInterval_in_TimeAndIntervalOver2(&tTimeAndInterval, timeDNPTime, interval, units);
//    return TimeAndInterval(time, interval, units);
    return tTimeAndInterval;
}

   ControlRelayOutputBlock From_in_ControlRelayOutputBlock_static(
        uint8_t code, uint8_t count, uint32_t onTime, uint32_t offTime, uint8_t status)
{
    ControlRelayOutputBlock cControlRelayOutputBlock;
    ControlRelayOutputBlock_in_ControlRelayOutputBlockOver2(&cControlRelayOutputBlock, 
                            code,
                            count,//// = 1,
                            onTime,//// = 100,
                            offTime,//// = 100,
                            from_type_in_CommandStatusSpec(status));//// = CommandStatus::SUCCESS);
    return cControlRelayOutputBlock;
//    return ControlRelayOutputBlock(code, count, onTime, offTime, CommandStatusSpec::from_type(status));
}

   BinaryOutputStatus From_in_BinaryOutputStatusFactory_staticOver1(uint8_t flags)
{
    BinaryOutputStatus bBinaryOutputStatus;
    Flags fFlags;
    Flags_In_FlagsOver2(&fFlags, flags);
    BinaryOutputStatus_in_BinaryOutputStatusOver3(&bBinaryOutputStatus, fFlags);
//    return BinaryOutputStatus(Flags(flags));
    return bBinaryOutputStatus;
}

    BinaryOutputStatus From_in_BinaryOutputStatusFactory_staticOver2(uint8_t flags, DNPTime timeDNPTime)
{
    BinaryOutputStatus bBinaryOutputStatus;
    Flags fFlags;
    Flags_In_FlagsOver2(&fFlags, flags);
    BinaryOutputStatus_in_BinaryOutputStatusOver4(&bBinaryOutputStatus, fFlags, timeDNPTime);
//    return BinaryOutputStatus(Flags(flags), time);
    return bBinaryOutputStatus;
}

   BinaryCommandEvent From_in_BinaryCommandEventFactory_staticOver1(uint8_t flags)
{
    BinaryCommandEvent bBinaryCommandEvent;
    Flags fFlags;
    Flags_In_FlagsOver2(&fFlags, flags);
    BinaryCommandEvent_In_BinaryCommandEventOver2(&bBinaryCommandEvent, fFlags);
//    return BinaryCommandEvent(Flags(flags));
    return bBinaryCommandEvent;
}

   BinaryCommandEvent From_in_BinaryCommandEventFactory_staticOver2(uint8_t flags, DNPTime timeDNPTime)
{
    BinaryCommandEvent bBinaryCommandEvent;
    Flags fFlags;
    Flags_In_FlagsOver2(&fFlags, flags);
    BinaryCommandEvent_In_BinaryCommandEventOver3(&bBinaryCommandEvent, fFlags, timeDNPTime);
//    return BinaryCommandEvent(Flags(flags), time);
    return bBinaryCommandEvent;
}

    AnalogOutputStatus From_in_AnalogOutputStatusFactory_staticOver1(uint8_t flags, double value)
{
    AnalogOutputStatus aAnalogOutputStatus;
    Flags fFlags;
    Flags_In_FlagsOver2(&fFlags, flags);
    AnalogOutputStatus_in_AnalogOutputStatusOver3(&aAnalogOutputStatus, value, fFlags);
//    return AnalogOutputStatus(value, Flags(flags));
    return aAnalogOutputStatus;
}

    AnalogOutputStatus From_in_AnalogOutputStatusFactory_staticOver2(uint8_t flags, double value, DNPTime timeDNPTime)
{
    AnalogOutputStatus aAnalogOutputStatus;
    Flags fFlags;
    Flags_In_FlagsOver2(&fFlags, flags);
    AnalogOutputStatus_in_AnalogOutputStatusOver4(&aAnalogOutputStatus, value, fFlags, timeDNPTime);
//    return AnalogOutputStatus(value, Flags(flags), time);
    return aAnalogOutputStatus;
}


    AnalogCommandEvent From_in_AnalogCommandEventFactory_staticOver1(uint8_t status, double value)
{
    AnalogCommandEvent aAnalogCommandEvent;
    AnalogCommandEvent_in_AnalogCommandEventOver2(&aAnalogCommandEvent, value, from_type_in_CommandStatusSpec(status));
//    return AnalogCommandEvent(value, CommandStatusSpec::from_type(status));
    return aAnalogCommandEvent;
}

    AnalogCommandEvent From_in_AnalogCommandEventFactory_staticOver2(uint8_t status, double value, DNPTime timeDNPTime)
{
    AnalogCommandEvent aAnalogCommandEvent;
    AnalogCommandEvent_in_AnalogCommandEventOver3(&aAnalogCommandEvent, value, from_type_in_CommandStatusSpec(status), timeDNPTime);
//    return AnalogCommandEvent(value, CommandStatusSpec::from_type(status), time);
    return aAnalogCommandEvent;
}

   AnalogOutputInt32 From_in_AnalogOutputFactory_for_Int32_t_static(int32_t value, uint8_t status)
{
   AnalogOutputInt32 aAnalogOutputInt32;
   AnalogOutputInt32_in_AnalogOutputInt32Over3(&aAnalogOutputInt32, value, from_type_in_CommandStatusSpec(status));
//    return Target(value, CommandStatusSpec::from_type(status));
   return aAnalogOutputInt32;
}

   AnalogOutputInt16 From_in_AnalogOutputFactory_for_Int16_t_static(int16_t value, uint8_t status)
{
   AnalogOutputInt16 aAnalogOutputInt16;
   AnalogOutputInt16_in_AnalogOutputInt16Over3(&aAnalogOutputInt16, value, from_type_in_CommandStatusSpec(status));
//    return Target(value, CommandStatusSpec::from_type(status));
   return aAnalogOutputInt16;
}

   AnalogOutputFloat32 From_in_AnalogOutputFactory_for_Float32_static(float value, uint8_t status)
{
   AnalogOutputFloat32 aAnalogOutputFloat32;
   AnalogOutputFloat32_in_AnalogOutputFloat32Over3(&aAnalogOutputFloat32, value, from_type_in_CommandStatusSpec(status));
//    return Target(value, CommandStatusSpec::from_type(status));
   return aAnalogOutputFloat32;
}

   AnalogOutputDouble64 From_in_AnalogOutputFactory_for_Double64_static(double value, uint8_t status)
{
   AnalogOutputDouble64 aAnalogOutputDouble64;
   AnalogOutputDouble64_in_AnalogOutputDouble64Over3(&aAnalogOutputDouble64, value, from_type_in_CommandStatusSpec(status));
//    return Target(value, CommandStatusSpec::from_type(status));
   return aAnalogOutputDouble64;
}
