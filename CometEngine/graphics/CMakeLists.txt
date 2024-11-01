cmake_minimum_required(VERSION 3.0.0)
project(CometEngine-graphics VERSION 0.1.0 LANGUAGES C CXX)

set (CMAKE_CXX_STANDARD 20)

add_library("${PROJECT_NAME}")

file(GLOB_RECURSE graphics-src
    "${PROJECT_SOURCE_DIR}/*.cpp"
    "${PROJECT_SOURCE_DIR}/*.c"
    "${PROJECT_SOURCE_DIR}/*.h"
)

target_sources("${PROJECT_NAME}" PRIVATE ${graphics-src})

target_include_directories("${PROJECT_NAME}" PUBLIC "${CMAKE_SOURCE_DIR}/CometEngine/vendor/glad/include")
target_include_directories("${PROJECT_NAME}" PUBLIC "${CMAKE_SOURCE_DIR}/CometEngine/vendor/glm/include")
target_include_directories("${PROJECT_NAME}" PUBLIC "${CMAKE_SOURCE_DIR}/CometEngine/vendor/stb/include")