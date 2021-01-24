#
# Lofty lib and source
#

# recursively get source files in the src directory
file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS "src/*.h" "src/*.cpp") # if you dont like it you can glob off!

set(SHARED_OPT STATIC)

if(LOFTY_BUILD_SHARED)
	set(SHARED_OPT SHARED)
endif()

message(STATUS "Lofty build version: ${CMAKE_PROJECT_VERSION}")
message(STATUS "Lofty lib type: ${SHARED_OPT}")
message(STATUS "Lofty build type: ${CMAKE_BUILD_TYPE}")

# add Lofty as a library with the given source files
add_library("${CMAKE_PROJECT_NAME}" ${SHARED_OPT} ${SOURCE_FILES})

# create source group (filters in Visual Studio) so we can organise files in IDE
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/src" FILES ${SOURCE_FILES})

# so we can include headers with the folder name as a prefix
# (makes more sense as an engine so you know roughly the purpose of the include e.g. Core/App.h | Physics/Collision.h)
target_include_directories("${CMAKE_PROJECT_NAME}" PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>/src")


#
# Compile definitions and flags for platforms and configurations
#

if(LOFTY_BUILD_SHARED)
	target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC LOFTY_SHARED)
endif()

if(CMAKE_SYSTEM_NAME MATCHES "Windows")
	target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC WINDOWS)
	# in future this will set a preprocessor definition for DirectX 11 (USE_DX11)
endif()

if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
	target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC OSX)
	# in future this will set a preprocessor definition for Metal (USE_METAL)
endif()

if(CMAKE_SYSTEM_NAME MATCHES "Linux")
	target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC LINUX)
	# in future this will set a preprocessor definition for just OpenGL or vulkan (perhaps this can be chosen) (USE_VULKAN)
endif()

# this will be defined in all cases for now
target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC USE_OPENGL)

# flags and definitions for debug and release (will we need a DIST in the future?)
target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC "$<$<CONFIG:DEBUG>:_DEBUG>")
# may not need this in future (all release stuff just doesnt have debug stuff)
target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC "$<$<CONFIG:RELEASE>:_RELEASE>")


#
# External libs
#

# make sure we load our external cmake projects first
add_subdirectory("external")

# link external projects (annoyingly they have to be in the same place we defined our target lib)
target_link_libraries("${CMAKE_PROJECT_NAME}" spdlog glfw glad)