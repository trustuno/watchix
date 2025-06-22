#include "logger.h"
#include "logger_manager.hpp"
#include <cstdarg>

extern "C" {

void logger_global_init(void) {
    LoggerManager::get_instance().global_init();
}

void logger_global_deinit(void) {
    LoggerManager::get_instance().global_deinit();
}

void logger_module_init(const char* module_name, int default_log_level) {
    LoggerManager::get_instance().module_init(module_name, default_log_level);
}

void logger_module_deinit(const char* module_name) {
    LoggerManager::get_instance().module_deinit(module_name);
}

void logger_set_module_log_level(const char* module_name, int log_level) {
    LoggerManager::get_instance().set_module_log_level(module_name, log_level);
}

int logger_get_module_log_level(const char* module_name) {
    return LoggerManager::get_instance().get_module_log_level(module_name);
}

void log_message(const char* module_name, LogLevel log_level, const char* file, int line,
                         const char* func, const char* format, ...) {
    va_list args;
    va_start(args, format);
    LoggerManager::get_instance().log_message(module_name, log_level, file, line, func, format, args);
    va_end(args);
}

} // extern "C"
