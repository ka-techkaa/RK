cmake_minimum_required(VERSION 3.14)
project(StatePatternVendingMachine)
set(CMAKE_CXX_STANDARD 17)

add_library(state_pattern
    src/NoMoneyState.cpp
    src/HasMoneyState.cpp
    src/SoldState.cpp
    src/VendingMachine.cpp
    src/State.hpp
    src/NoMoneyState.hpp
    src/HasMoneyState.hpp
    src/SoldState.hpp
    src/VendingMachine.hpp
)
target_include_directories(state_pattern PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(state_demo src/main.cpp)
target_link_libraries(state_demo PRIVATE state_pattern)

# --- GTest section ---
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()
include(GoogleTest)

add_executable(tests tests/test_state.cpp)
target_link_libraries(tests PRIVATE state_pattern gtest gtest_main)
target_include_directories(tests PRIVATE src)
gtest_discover_tests(tests)

install(TARGETS state_demo RUNTIME DESTINATION bin)
include(InstallRequiredSystemLibraries)
set(CPACK_PACKAGE_NAME "state_pattern_vm")
set(CPACK_PACKAGE_VENDOR "Your Name")
set(CPACK_PACKAGE_CONTACT "your@email.com")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "State pattern: vending machine example")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Your Name")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6 (>= 2.27)")
set(CPACK_RPM_PACKAGE_LICENSE "MIT")
set(CPACK_GENERATOR "DEB")
include(CPack)
