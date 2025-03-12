#include "video/video_manager.hpp"
#include "utils/logger.hpp"

namespace video {

bool VideoManager::initialize() {
    if (capture_) {
        LOG_WARN("Video manager already initialized");
        return true;
    }

    LOG_INFO("Initializing video manager...");

    // 加载相机配置
    if (!loadCameraConfig()) {
        LOG_ERROR("Failed to load camera configuration");
        return false;
    }

    // 初始化相机
    if (!initializeCamera()) {
        LOG_ERROR("Failed to initialize camera");
        return false;
    }

    LOG_INFO("Video manager initialized successfully");
    return true;
}

bool VideoManager::startCapture() {
    if (!capture_) {
        LOG_ERROR("Camera not initialized");
        return false;
    }

    if (is_capturing_) {
        LOG_WARN("Already capturing");
        return true;
    }

    is_capturing_ = true;
    LOG_INFO("Started video capture");
    return true;
}

void VideoManager::stopCapture() {
    if (is_capturing_) {
        is_capturing_ = false;
        LOG_INFO("Stopped video capture");
    }
}

cv::Mat VideoManager::getFrame() {
    if (!is_capturing_ || !capture_) {
        return cv::Mat();
    }

    cv::Mat frame;
    if (!capture_->read(frame)) {
        LOG_ERROR("Failed to read frame");
        return cv::Mat();
    }

    return frame;
}

bool VideoManager::initializeCamera() {
    capture_ = std::make_unique<cv::VideoCapture>(0); // 使用默认相机
    if (!capture_->isOpened()) {
        LOG_ERROR("Failed to open camera");
        return false;
    }

    // 设置相机参数
    capture_->set(cv::CAP_PROP_FRAME_WIDTH, camera_config_.resolution_width);
    capture_->set(cv::CAP_PROP_FRAME_HEIGHT, camera_config_.resolution_height);
    capture_->set(cv::CAP_PROP_FPS, camera_config_.fps);

    return true;
}

bool VideoManager::loadCameraConfig() {
    // TODO: 从配置文件加载相机配置
    camera_config_.camera_type = "USB Camera";
    camera_config_.resolution_width = 1920;
    camera_config_.resolution_height = 1080;
    camera_config_.fps = 30;
    return true;
}

} // namespace video