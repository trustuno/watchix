#ifndef LOGGER_MANAGER_HPP
#define LOGGER_MANAGER_HPP

#include <string>
#include <unordered_map>
#include <mutex>
#include <fstream>

extern "C" {
    #include "logger.h"  // Import log level macros
}

class LoggerManager {
public:
    static LoggerManager& get_instance();

    void global_init(void);
    void global_deinit();

    void module_init(const std::string& module_name, int default_log_level);
    void module_deinit(const std::string& module_name);

    void set_module_log_level(const std::string& module_name, int level);
    int get_module_log_level(const std::string& module_name);

    void log_message(const std::string& module_name, LogLevel level, const char* file, int line, const char* func, const char* format, ...);

private:
    LoggerManager() = default;
    ~LoggerManager() = default;

    void rotate_logs_if_needed();
    const char*get_log_level_string(int level);
    void write_log(const std::string& message);

    std::unordered_map<std::string, int> module_log_levels_;
    std::mutex log_mutex_;

    std::string log_file_path_ = "/var/log/watchix/debug.log";
    size_t max_file_size_ = 50 * 1024 * 1024; // Default 50MB
    int max_files_ = 10;

    std::ofstream log_stream_;
};

#endif // LOGGER_MANAGER_HPP
