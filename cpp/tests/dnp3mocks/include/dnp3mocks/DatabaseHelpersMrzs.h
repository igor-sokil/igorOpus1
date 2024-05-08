#ifndef OPENDNP3_UNITTESTS_DATABASE_HELPERSMRZS_H
#define OPENDNP3_UNITTESTS_DATABASE_HELPERSMRZS_H

////#include <opendnp3/outstation/DatabaseConfig.h>
#include "DatabaseConfigMrzs.h"

DatabaseConfigMrzs* binary_input_in_DatabaseHelpersMrzs(uint16_t num);
DatabaseConfigMrzs* counter_in_DatabaseHelpersMrzs(uint16_t num, boolean with_frozen);
DatabaseConfigMrzs* binary_output_status_in_DatabaseHelpersMrzs(uint16_t num);
DatabaseConfigMrzs* analog_input_in_DatabaseHelpersMrzs(uint16_t num);
DatabaseConfigMrzs* analog_output_status_in_DatabaseHelpersMrzs(uint16_t num);
DatabaseConfigMrzs* time_and_interval_in_DatabaseHelpersMrzs(uint16_t num);
DatabaseConfigMrzs* database_by_sizes_in_DatabaseHelpersMrzs(
    uint16_t num_binary,
    uint16_t num_double_binary,
    uint16_t num_analog,
    uint16_t num_counter,
    uint16_t num_frozen_counter,
    uint16_t num_binary_output_status,
    uint16_t num_analog_output_status,
    uint16_t num_time_and_interval,
    uint16_t num_octet_string);


#endif
