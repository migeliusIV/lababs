# CMakeList.txt: ������ CMake ��� Lababa7; �������� �������� ��� � �����������,
# ������� ����� ������ ��� ����������� �������.
#
cmake_minimum_required (VERSION 3.8)

set(project "Lababa4")
project (${project})
set(MY_PROJECT_VERSION 1.0.0)
message("Version: ${MY_PROJECT_VERSION}")

set(CMAKE_CXX_STANDARD 11)

#set(${project}_HEADERS 
#			"Lababa4.h")
set(${project}_SOURCES 
			"main.cpp")
set(${project}_SOURCE_LIST
			${${project}_SOURCES})

add_subdirectory(Containers)

add_executable (${project} 
			${${project}_SOURCE_LIST})

target_link_libraries(${project} Containers)
# TODO: �������� ����� � ������� �������, ���� ��� ����������.