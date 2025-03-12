#include "utils/logger.hpp"
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <iostream>

namespace utils {

std::shared_ptr<spdlog::logger> Logger::logger_;

void Logger::init() {
    try {
        // 创建控制台sink
        auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
        console_sink->set_level(spdlog::level::debug);
        console_sink->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%^%l%$] [%t] %v");

        // 创建文件sink
        auto file_sink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(
            "logs/solar_inspection.log",
            1024 * 1024 * 5,  // 5MB
            3                  // 保留3个文件
        );
        file_sink->set_level(spdlog::level::trace);
        file_sink->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%l] [%t] %v");

        // 创建多sink logger
        std::vector<spdlog::sink_ptr> sinks {console_sink, file_sink};
        logger_ = std::make_shared<spdlog::logger>("solar_inspection", sinks.begin(), sinks.end());
        logger_->set_level(spdlog::level::debug);

        // 设置为默认logger
        spdlog::set_default_logger(logger_);

        LOG_INFO("Logger initialized");
    } catch (const spdlog::spdlog_ex& ex) {
        std::cerr << "Logger initialization failed: " << ex.what() << std::endl;
        throw;
    }
}

void Logger::setLevel(spdlog::level::level_enum level) {
    if (logger_) {
        logger_->set_level(level);
    }
}

std::shared_ptr<spdlog::logger> Logger::getLogger() {
    if (!logger_) {
        init();
    }
    return logger_;
}

} // namespace utils