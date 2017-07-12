cmake_minimum_required(VERSION 3.8)
project(linuxServer)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        main.cpp
        socketCombined.cpp
        socketCombined.h
        mainServer.cpp
        mainServer.h
        )

add_executable(linuxServer ${SOURCE_FILES})