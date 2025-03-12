add_library(core
    system.cpp
)

target_include_directories(core
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(core
    PUBLIC
    ${OpenCV_LIBS}
    spdlog::spdlog
    utils
)