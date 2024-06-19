cmake_minimum_required(VERSION 3.8)

set(project "Containers")
project(${project})

set(CMAKE_CXX_STANDARD 11)

set(${project}_SOURCES
        MyStack.cpp)

set(${project}_HEADERS
        MyStack.h)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES}
        ${${project}_HEADERS})
        
add_library(${project}
        STATIC
        ${${project}_SOURCE_LIST})