#include "ai/detector.hpp"
#include "utils/logger.hpp"
#include <fstream>

namespace ai {

bool Detector::initialize() {
    if (is_initialized_) {
        LOG_WARN("Detector already initialized");
        return true;
    }

    LOG_INFO("Initializing AI detector...");

    // 加载模型配置
    if (!loadModelConfig()) {
        LOG_ERROR("Failed to load model configuration");
        return false;
    }

    // 加载模型
    if (!loadModel()) {
        LOG_ERROR("Failed to load model");
        return false;
    }

    is_initialized_ = true;
    LOG_INFO("AI detector initialized successfully");
    return true;
}

std::vector<Detection> Detector::detect(const cv::Mat& frame) {
    if (!is_initialized_) {
        LOG_ERROR("Detector not initialized");
        return {};
    }

    std::vector<Detection> detections;

    try {
        // 预处理图像
        cv::Mat blob;
        cv::dnn::blobFromImage(frame, blob, 1.0/255.0, cv::Size(416, 416), cv::Scalar(), true, false);
        net_->setInput(blob);

        // 前向推理
        std::vector<cv::Mat> outputs;
        net_->forward(outputs, net_->getUnconnectedOutLayersNames());

        // 处理检测结果
        float conf_threshold = model_config_.confidence_threshold;
        float nms_threshold = model_config_.nms_threshold;

        std::vector<int> class_ids;
        std::vector<float> confidences;
        std::vector<cv::Rect> boxes;

        // TODO: 实现检测结果的后处理

    } catch (const cv::Exception& e) {
        LOG_ERROR("OpenCV error during detection: {}", e.what());
    } catch (const std::exception& e) {
        LOG_ERROR("Error during detection: {}", e.what());
    }

    return detections;
}

bool Detector::loadModel() {
    try {
        net_ = std::make_unique<cv::dnn::Net>(
            cv::dnn::readNetFromDarknet(
                model_config_.config_path,
                model_config_.model_path
            )
        );
        
        // 使用CPU进行推理
        net_->setPreferableBackend(cv::dnn::DNN_BACKEND_OPENCV);
        net_->setPreferableTarget(cv::dnn::DNN_TARGET_CPU);

        return true;
    } catch (const cv::Exception& e) {
        LOG_ERROR("Failed to load model: {}", e.what());
        return false;
    }
}

bool Detector::loadModelConfig() {
    // TODO: 从配置文件加载模型配置
    model_config_.model_path = "models/yolov8.weights";
    model_config_.config_path = "models/yolov8.cfg";
    model_config_.confidence_threshold = 0.5f;
    model_config_.nms_threshold = 0.4f;

    // 加载类别名称
    class_names_ = {"panel", "crack", "dirt", "shadow"};

    return true;
}

} // namespace ai