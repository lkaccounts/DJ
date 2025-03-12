add_executable(test_core
    test_system.cpp
)

target_link_libraries(test_core
    PRIVATE
    core
    Catch2::Catch2WithMain
)

add_test(NAME test_core COMMAND test_core)