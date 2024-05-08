#include "header.h"
#include "DatabaseHelpersMrzs.h"

DatabaseConfigMrzs* binary_input_in_DatabaseHelpersMrzs(uint16_t num)
{
  return database_by_sizes_in_DatabaseHelpersMrzs(num, 0, 0, 0, 0, 0, 0, 0, 0);
}

DatabaseConfigMrzs* counter_in_DatabaseHelpersMrzs(uint16_t num, boolean with_frozen)
{
  uint16_t num_frozen = with_frozen ? num : 0;
  return database_by_sizes_in_DatabaseHelpersMrzs(0, 0, 0, num, num_frozen, 0, 0, 0, 0);
}

DatabaseConfigMrzs* binary_output_status_in_DatabaseHelpersMrzs(uint16_t num)
{
  return database_by_sizes_in_DatabaseHelpersMrzs(0, 0, 0, 0, 0, num, 0, 0, 0);
}

DatabaseConfigMrzs* analog_input_in_DatabaseHelpersMrzs(uint16_t num)
{
  return database_by_sizes_in_DatabaseHelpersMrzs(0, 0, num, 0, 0, 0, 0, 0, 0);
}

DatabaseConfigMrzs* analog_output_status_in_DatabaseHelpersMrzs(uint16_t num)
{
  return database_by_sizes_in_DatabaseHelpersMrzs(0, 0, 0, 0, 0, 0, num, 0, 0);
}

DatabaseConfigMrzs* time_and_interval_in_DatabaseHelpersMrzs(uint16_t num)
{
  return database_by_sizes_in_DatabaseHelpersMrzs(0, 0, 0, 0, 0, 0, 0, num, 0);
}

DatabaseConfigMrzs* database_by_sizes_in_DatabaseHelpersMrzs(
    uint16_t num_binary,
    uint16_t num_double_binary,
    uint16_t num_analog,
    uint16_t num_counter,
    uint16_t num_frozen_counter,
    uint16_t num_binary_output_status,
    uint16_t num_analog_output_status,
    uint16_t num_time_and_interval,
    uint16_t num_octet_string)
{
 UNUSED(num_octet_string);
 initialize_TimeAndIntervalConfig_in_DatabaseConfigMrzs(num_time_and_interval);
 initialize_AOStatusConfig_in_DatabaseConfigMrzs(num_analog_output_status);
 initialize_BOStatusConfig_in_DatabaseConfigMrzs(num_binary_output_status);
 initialize_FrozenCounterConfig_in_DatabaseConfigMrzs(num_frozen_counter);
 initialize_CounterConfig_in_DatabaseConfigMrzs(num_counter);
 initialize_AnalogConfig_in_DatabaseConfigMrzs(num_analog);
 initialize_DoubleBitBinaryConfig_in_DatabaseConfigMrzs(num_double_binary);
 initialize_BinaryConfig_in_DatabaseConfigMrzs(num_binary);
 return getDatabaseConfigMrzs();
}

