#include "logger_manager.hpp"
#include <iostream>
#include <cstdarg>
#include <filesystem>
#include <cstring>
#include "utils.h"


const char* log_level_strings[] = { "OFF", "ERR", "WAR", "INF", "DBG", "VER", "MAX" };




LoggerManager& LoggerManager::get_instance() {
    static LoggerManager instance;
    return instance;
}

void LoggerManager::global_init(void) {
    std::lock_guard<std::mutex> lock(log_mutex_);

    // Extract directory path
    std::filesystem::path log_path(log_file_path_);
    std::filesystem::path log_dir = log_path.parent_path();

    // Check and create directory if needed
    if (!std::filesystem::exists(log_dir)) {
        try {
            std::filesystem::create_directories(log_dir);
            std::cout << "Created log directory: " << log_dir << std::endl;
        } catch (const std::filesystem::filesystem_error& e) {
            std::cout << "Failed to create log directory: " << e.what() << std::endl;
            return;
        }
    }

    // Open log file
    log_stream_.open(log_file_path_, std::ios::app);
    if (!log_stream_.is_open()) {
        std::cout << "Failed to open log file: " << log_file_path_ << std::endl;
        return;
    }

    std::cout << "Logging started at: " << log_file_path_ << std::endl;
}

void LoggerManager::global_deinit() {
    std::lock_guard<std::mutex> lock(log_mutex_);
    if (log_stream_.is_open()) {
        log_stream_.close();
    }
}

void LoggerManager::module_init(const std::string& module_name, int level) {
    std::lock_guard<std::mutex> lock(log_mutex_);
    module_log_levels_[module_name] = level;
}

void LoggerManager::module_deinit(const std::string& module_name) {
    std::lock_guard<std::mutex> lock(log_mutex_);
    module_log_levels_.erase(module_name);
}

void LoggerManager::set_module_log_level(const std::string& module_name, int level) {
    std::lock_guard<std::mutex> lock(log_mutex_);
    module_log_levels_[module_name] = level;
}

int LoggerManager::get_module_log_level(const std::string& module_name) {
    std::lock_guard<std::mutex> lock(log_mutex_);
    if (module_log_levels_.count(module_name)) {
        return module_log_levels_[module_name];
    }
    return DEBUG_OFF;
}

void LoggerManager::log_message(const std::string& module_name, LogLevel level, 
                                const char* file, int line, const char* func, 
                                const char* format, ...) {
    UNUSED(file);

    std::lock_guard<std::mutex> lock(log_mutex_);

    if (module_log_levels_.count(module_name) == 0 || level > module_log_levels_[module_name]) {
        return; // Skip logging for this level
    }

    // Format timestamp
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;

    std::tm buf;
    localtime_r(&in_time_t, &buf);  // Thread-safe

    char time_buffer[32];
    strftime(time_buffer, sizeof(time_buffer), "%d/%m/%Y %H:%M:%S", &buf);

    // Format log message
    char log_buffer[1024];
    va_list args;
    va_start(args, format);
    vsnprintf(log_buffer, sizeof(log_buffer), format, args);
    va_end(args);

    // Prepare formatted log string
    char formatted_log[2048];
    snprintf(formatted_log, sizeof(formatted_log), "[%-8s][%s][%s.%06ld][%-10s : %5d] %s",
                module_name.c_str(), 
                get_log_level_string(level),
                time_buffer,
                ms.count(),
                func, line,
                log_buffer);

    // Write and manage log
    write_log(formatted_log);
    rotate_logs_if_needed();
}


void LoggerManager::write_log(const std::string& message) {
    if (log_stream_.is_open()) {
        log_stream_ << message << std::endl;
        log_stream_.flush();
    }
}

void LoggerManager::rotate_logs_if_needed() {
    if (!log_stream_.is_open())
        return;

    log_stream_.flush();
    size_t file_size = std::filesystem::file_size(log_file_path_);

    if (file_size < max_file_size_)
        return;

    log_stream_.close();

    // Shift old log files
    for (int i = max_files_ - 1; i >= 1; --i) {
        std::string old_name = log_file_path_ + "." + std::to_string(i);
        std::string new_name = log_file_path_ + "." + std::to_string(i + 1);
        if (std::filesystem::exists(old_name)) {
            std::filesystem::rename(old_name, new_name);
        }
    }
    std::string first_backup = log_file_path_ + ".1";
    std::filesystem::rename(log_file_path_, first_backup);

    // Start new log
    log_stream_.open(log_file_path_, std::ios::trunc);
}

const char* LoggerManager::get_log_level_string(int level) {
    if (level < 0 || level >= DEBUG_MAX) {
        return "UNK"; // Unknown log level
    }
    return log_level_strings[level];
}