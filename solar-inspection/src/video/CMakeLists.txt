add_library(video
    video_manager.cpp
)

target_include_directories(video
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(video
    PUBLIC
    ${OpenCV_LIBS}
    spdlog::spdlog
)