cmake_minimum_required(VERSION 3.1)

project(PPM_viewer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(PPM_viewer main.cpp Ppm_file.cpp)

target_link_libraries(PPM_viewer sfml-graphics sfml-window sfml-system)
