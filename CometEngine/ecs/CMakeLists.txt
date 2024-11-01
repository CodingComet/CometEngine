cmake_minimum_required(VERSION 3.0.0)
project(CometEngine-ecs VERSION 0.1.0 LANGUAGES C CXX)

set (CMAKE_CXX_STANDARD 20)

add_library("${PROJECT_NAME}")

file(GLOB_RECURSE ecs-src
    "${PROJECT_SOURCE_DIR}/*.cpp"
    "${PROJECT_SOURCE_DIR}/*.c"
    "${PROJECT_SOURCE_DIR}/*.h"
)

target_sources("${PROJECT_NAME}" PRIVATE ${ecs-src})