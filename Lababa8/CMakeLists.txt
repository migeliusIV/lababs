cmake_minimum_required(VERSION 3.8)

set(project "Lababa8")
project(${project})

set(cmake_cxx_standard 11)

set(${project}_SOURCES
		#Task1.cpp
		#Task2.cpp
		#Task3.cpp
		#Task4.cpp
		#Task5.cpp
		#Task6.cpp
		#Task7.cpp
		#Task8.cpp
		Task9.cpp
		)

#set(${project}_HEADERS)

set(${project}_SOURCE_LIST
		${${project}_SOURCES})

add_executable (${project} 
		${${project}_SOURCE_LIST})

#Для 3-ей задачи
#configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Source.txt
#       ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

#configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Result.txt
#		${CMAKE_CURRENT_BINARY_DIR})