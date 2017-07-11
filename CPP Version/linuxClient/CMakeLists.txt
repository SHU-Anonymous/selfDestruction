cmake_minimum_required(VERSION 3.8)
project(linuxClient)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        main.cpp
        socketConsume.cpp
        socketConsume.h
        )
add_executable(linuxClient ${SOURCE_FILES})