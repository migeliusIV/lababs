# CMakeList.txt: проект CMake для Lababa7; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

set(project "Lababa7")
project (${project})
#set(MY_PROJECT_VERSION 1.0.0)
#message("Version: ${MY_PROJECT_VERSION}")

set(CMAKE_CXX_STANDARD 11)

set(${project}_HEADERS 
			"Lababa7.h")
set(${project}_SOURCES 
			"Lababa7.cpp")
set(${project}_SOURCE_LIST
			${${project}_SOURCES}
			${${projecct}_HEADERS})

add_subdirectory(Documents)

add_executable (${project} 
			${${project}_SOURCE_LIST})

target_link_libraries(${project} Documents)
# TODO: Добавьте тесты и целевые объекты, если это необходимо.