cmake_minimum_required(VERSION 3.12)

include(cmake/UploadMethodConfig.cmake)

include(mbed-cmake/mbed-cmake.cmake)
project(mbed-cmake-test-project LANGUAGES NONE)

add_mbed_executable(hello_world ../code/HelloWorld.cpp)
add_mbed_executable(icecream ../code/icecream.cpp)
add_mbed_executable(blinky ../code/blinky.cpp)

mbed_cmake_print_build_report()
mbed_cmake_finalize()