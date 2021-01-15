#
# Example executable and source
#
project(Example LANGUAGES CXX)

# recursively get source files in the src directory
file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS "src/*.h" "src/*.cpp") # if you dont like it you can glob off!

add_executable("${PROJECT_NAME}" ${SOURCE_FILES})

target_include_directories("${PROJECT_NAME}" PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>/src")

# create source group (filters in Visual Studio) so we can organise files in IDE
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/src" FILES ${SOURCE_FILES})

target_link_libraries("${PROJECT_NAME}" "${CMAKE_PROJECT_NAME}")

# # flags and definitions for debug and release
target_compile_definitions("${PROJECT_NAME}" PUBLIC "$<$<CONFIG:DEBUG>:_DEBUG>")
target_compile_definitions("${PROJECT_NAME}" PUBLIC "$<$<CONFIG:RELEASE>:_RELEASE>")


