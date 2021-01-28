# logging with spdlog
add_subdirectory("spdlog")
set_target_properties("spdlog" PROPERTIES FOLDER "spdlog")

# openGL (this may end up being a section that links only the platform specific libraries,
#         but for now, just openGL)
#

# glfw
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory("glfw")

# glad
add_subdirectory("glad")
set_target_properties("glad" PROPERTIES FOLDER "GLAD")
set_target_properties("glad-generate-files" PROPERTIES FOLDER "GLAD")


# math
add_subdirectory("glm")

