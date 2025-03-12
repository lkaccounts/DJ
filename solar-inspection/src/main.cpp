#include <iostream>
#include <memory>
#include "core/system.hpp"
#include "video/video_manager.hpp"
#include "ai/detector.hpp"
#include "utils/logger.hpp"

int main(int argc, char* argv[]) {
    try {
        // 初始化日志系统
        utils::Logger::init();
        LOG_INFO("Solar Inspection System Starting...");

        // 初始化系统
        auto system = std::make_unique<core::System>();
        if (!system->initialize()) {
            LOG_ERROR("Failed to initialize system");
            return -1;
        }

        // 初始化视频管理器
        auto videoManager = std::make_unique<video::VideoManager>();
        if (!videoManager->initialize()) {
            LOG_ERROR("Failed to initialize video manager");
            return -1;
        }

        // 初始化AI检测器
        auto detector = std::make_unique<ai::Detector>();
        if (!detector->initialize()) {
            LOG_ERROR("Failed to initialize AI detector");
            return -1;
        }

        // 运行主循环
        system->run();

        LOG_INFO("Solar Inspection System Shutting down...");
        return 0;
    } catch (const std::exception& e) {
        LOG_ERROR("Unhandled exception: {}", e.what());
        return -1;
    }
}