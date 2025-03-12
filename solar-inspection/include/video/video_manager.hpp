#pragma once

#include <memory>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>

namespace video {

class VideoManager {
public:
    VideoManager() = default;
    ~VideoManager() = default;

    bool initialize();
    bool startCapture();
    void stopCapture();
    cv::Mat getFrame();

private:
    struct CameraConfig {
        std::string camera_type;
        int resolution_width;
        int resolution_height;
        int fps;
    };

    bool initializeCamera();
    bool loadCameraConfig();

    CameraConfig camera_config_;
    std::unique_ptr<cv::VideoCapture> capture_;
    bool is_capturing_ = false;
};

} // namespace video