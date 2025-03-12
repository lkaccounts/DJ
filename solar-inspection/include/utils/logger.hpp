#pragma once

#include <string>
#include <spdlog/spdlog.h>

namespace utils {

class Logger {
public:
    static void init();
    static void setLevel(spdlog::level::level_enum level);
    static std::shared_ptr<spdlog::logger> getLogger();

private:
    static std::shared_ptr<spdlog::logger> logger_;
};

#define LOG_TRACE(...) SPDLOG_LOGGER_TRACE(utils::Logger::getLogger(), __VA_ARGS__)
#define LOG_DEBUG(...) SPDLOG_LOGGER_DEBUG(utils::Logger::getLogger(), __VA_ARGS__)
#define LOG_INFO(...)  SPDLOG_LOGGER_INFO(utils::Logger::getLogger(), __VA_ARGS__)
#define LOG_WARN(...)  SPDLOG_LOGGER_WARN(utils::Logger::getLogger(), __VA_ARGS__)
#define LOG_ERROR(...) SPDLOG_LOGGER_ERROR(utils::Logger::getLogger(), __VA_ARGS__)
#define LOG_CRITICAL(...) SPDLOG_LOGGER_CRITICAL(utils::Logger::getLogger(), __VA_ARGS__)

} // namespace utils