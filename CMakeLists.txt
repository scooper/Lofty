cmake_minimum_required(VERSION 3.12)

# project
project(Lofty VERSION 0.1 
			  LANGUAGES CXX)

# must be c++ 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

option(LOFTY_BUILD_SHARED "Build Lofty as a shared library/dll" False)
option(LOFTY_BUILD_EXAMPLE "Build the sample program for demonstrating Lofty" True)

add_subdirectory("Lofty")

if(LOFTY_BUILD_EXAMPLE)
	message(STATUS "Build Lofty sample program")
	add_subdirectory("Example")
endif()



