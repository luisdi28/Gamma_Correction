cmake_minimum_required(VERSION 3.23)
project(Gamma_Correction)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/googletest)

enable_testing()

add_executable(servidor main.cpp)

target_link_libraries(servidor
        ${OpenCV_LIBS}
        gtest
        gtest_main
        gmock_main)