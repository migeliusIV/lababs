cmake_minimum_required(VERSION 3.8)

set(project "Documents")
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCES
        Documents.cpp)

set(${project}_HEADERS
        Documents.h)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES}
        ${${project}_HEADERS})
        
add_library(${project}
        STATIC
        ${${project}_SOURCE_LIST})