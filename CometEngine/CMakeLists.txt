cmake_minimum_required(VERSION 3.0.0)
project(CometEngine VERSION 0.1.0 LANGUAGES C CXX)

set (CMAKE_CXX_STANDARD 20)

add_library("${PROJECT_NAME}")

file(GLOB engine-src
    "${PROJECT_SOURCE_DIR}/*.cpp"
    "${PROJECT_SOURCE_DIR}/*.c"
    "${PROJECT_SOURCE_DIR}/*.h"
)

target_sources("${PROJECT_NAME}" PRIVATE ${engine-src})




add_subdirectory(vendor/glfw-3.4)
add_subdirectory(graphics)
add_subdirectory(ecs)
add_subdirectory(app)

target_link_libraries("${PROJECT_NAME}" PRIVATE glfw) 
target_link_libraries("${PROJECT_NAME}" PRIVATE CometEngine-app) 
target_link_libraries("${PROJECT_NAME}" PRIVATE CometEngine-graphics) 
target_link_libraries("${PROJECT_NAME}" PRIVATE CometEngine-ecs) 
