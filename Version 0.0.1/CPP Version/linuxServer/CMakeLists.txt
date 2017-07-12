cmake_minimum_required(VERSION 3.8)
project(linuxServer)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp socketService.cpp socketService.h)
add_executable(linuxServer ${SOURCE_FILES})