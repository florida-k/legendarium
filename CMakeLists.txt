cmake_minimum_required(VERSION 4.2)
project(legendarium)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(legendarium
        src/main.cpp)