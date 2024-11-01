cmake_minimum_required(VERSION 3.0.0)
project(CometEngine-components VERSION 0.1.0 LANGUAGES C CXX)

set (CMAKE_CXX_STANDARD 20)

add_library("${PROJECT_NAME}")

file(GLOB_RECURSE components-src
    "${PROJECT_SOURCE_DIR}/*.cpp"
    "${PROJECT_SOURCE_DIR}/*.c"
    "${PROJECT_SOURCE_DIR}/*.h"
)

target_sources("${PROJECT_NAME}" PRIVATE ${components-src})

target_include_directories("${PROJECT_NAME}" PUBLIC "${CMAKE_SOURCE_DIR}/CometEngine/vendor/glfw-3.4/include")
target_include_directories("${PROJECT_NAME}" PUBLIC "${CMAKE_SOURCE_DIR}/CometEngine/vendor/glm/include")
target_include_directories("${PROJECT_NAME}" PUBLIC "${CMAKE_SOURCE_DIR}/CometEngine/vendor/stb/include")
target_include_directories("${PROJECT_NAME}" PUBLIC "${CMAKE_SOURCE_DIR}/CometEngine/")