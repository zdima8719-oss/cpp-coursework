cmake_minimum_required(VERSION 4.4)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp
        cl_base.h
        cl_base.cpp
        cl_1.h
        cl_application.h
        cl_application.cpp
        cl_1.cpp)
