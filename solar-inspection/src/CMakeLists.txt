# 添加子目录
add_subdirectory(core)
add_subdirectory(ai)
add_subdirectory(video)
add_subdirectory(utils)

# 创建主程序可执行文件
add_executable(solar_inspection main.cpp)

# 链接所有子模块库
target_link_libraries(solar_inspection
    PRIVATE
    core
    ai
    video
    utils
    ${OpenCV_LIBS}
    ${CUDA_LIBRARIES}
)