#pragma once

#include <memory>
#include <string>

namespace core {

class System {
public:
    System() = default;
    ~System() = default;

    bool initialize();
    void run();
    void shutdown();

private:
    // 系统配置
    struct Config {
        std::string device_name;
        std::string version;
        // 添加其他配置项
    };

    bool loadConfig();
    bool initializeSubsystems();

    Config config_;
    bool is_initialized_ = false;
};

} // namespace core