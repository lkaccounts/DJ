add_library(ai
    detector.cpp
)

target_include_directories(ai
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(ai
    PUBLIC
    ${OpenCV_LIBS}
    spdlog::spdlog
)