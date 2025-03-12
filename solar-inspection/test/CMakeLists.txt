enable_testing()

# 添加测试子目录
add_subdirectory(core)
add_subdirectory(video)
add_subdirectory(ai)
add_subdirectory(utils)

# 设置测试可执行文件输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/tests)