#include <catch2/catch_test_macros.hpp>
#include "core/system.hpp"

TEST_CASE("System initialization", "[core]") {
    core::System system;
    
    SECTION("Initialize system") {
        REQUIRE(system.initialize() == true);
    }
}

TEST_CASE("System configuration", "[core]") {
    core::System system;
    
    SECTION("Load configuration") {
        REQUIRE(system.initialize() == true);
        // TODO: Add more specific configuration tests
    }
}