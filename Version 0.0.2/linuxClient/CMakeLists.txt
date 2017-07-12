cmake_minimum_required(VERSION 3.8)
project(linuxClient)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        main.cpp
        socketCombined.cpp
        socketCombined.h
        mainClient.cpp
        mainClient.h
        executioner.cpp
        executioner.h
        )

add_executable(linuxClient ${SOURCE_FILES})