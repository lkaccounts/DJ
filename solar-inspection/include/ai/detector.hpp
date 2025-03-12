#pragma once

#include <memory>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>

namespace ai {

struct Detection {
    cv::Rect bbox;
    float confidence;
    int class_id;
    std::string class_name;
};

class Detector {
public:
    Detector() = default;
    ~Detector() = default;

    bool initialize();
    std::vector<Detection> detect(const cv::Mat& frame);

private:
    struct ModelConfig {
        std::string model_path;
        std::string config_path;
        float confidence_threshold;
        float nms_threshold;
    };

    bool loadModel();
    bool loadModelConfig();

    ModelConfig model_config_;
    std::unique_ptr<cv::dnn::Net> net_;
    std::vector<std::string> class_names_;
    bool is_initialized_ = false;
};

} // namespace ai