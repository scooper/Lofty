# logging with spdlog
add_subdirectory("spdlog")

# openGL (this may end up being a section that links only the platform specific libraries,
#         but for now, just openGL)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory("glfw")
