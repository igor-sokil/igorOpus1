#ifndef __LOGINFO__
#define __LOGINFO__
#include <string>

#define LOG_INFO

int16_t get_stack_info(void);
void increment_stack_info(void);
void decrement_stack_info(void);
std::string getString_stack_info(void);

#endif
