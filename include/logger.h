#ifndef LOGGER_H
#define LOGGER_H

#ifdef __cplusplus
extern "C" {
#endif

// =========================
// Log Levels
// =========================
// #define DEBUG_OFF   0
// #define DEBUG_ERR   1
// #define DEBUG_WARN  2
// #define DEBUG_INFO  3
// #define DEBUG_DEBUG 4
enum LogLevel {
    DEBUG_OFF = 0,
    DEBUG_ERR,
    DEBUG_WARN,
    DEBUG_INFO,
    DEBUG_DEBUG,
    DEBUG_VERBOSE,

    DEBUG_MAX //This must be at the end
};

// =========================
// API Prototypes
// =========================

// Global logger initialization (called by main)
void logger_global_init(void);

// Global logger deinitialization (called at shutdown)
void logger_global_deinit(void);

// Module registration (each module must call this once)
void logger_module_init(const char* module_name, int default_log_level);

// Module deinitialization (optional, for cleanup)
void logger_module_deinit(const char* module_name);

// Set log level for a module at runtime
void logger_set_module_log_level(const char* module_name, int log_level);

// Get current log level of a module
int logger_get_module_log_level(const char* module_name);

// Internal log function (not to be called directly by modules)
void logger_log_internal(const char* module_name, int log_level, const char* file, int line, const char* func, const char* format, ...);


void log_message(const char* module_name, LogLevel log_level, const char* file, int line,
                 const char* func, const char* format, ...);

// =========================
// Logging Macro
// =========================
#define LOG(level, module, ...) \
    log_message(module, level, __FILE__, __LINE__, __func__, __VA_ARGS__)

#ifdef __cplusplus
}
#endif

#endif // LOGGER_H
