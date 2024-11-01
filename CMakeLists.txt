cmake_minimum_required(VERSION 3.0.0)
project(CometProject VERSION 0.1.0 LANGUAGES C CXX)

set (CMAKE_CXX_STANDARD 20)

add_executable("${PROJECT_NAME}" main.cpp)

add_subdirectory(CometEngine)


# Resource directory
set(RESOURCE_DIR "${CMAKE_SOURCE_DIR}/resources")

# Find shader files
file(GLOB_RECURSE RESOURCE_FILES "${RESOURCE_DIR}/*")

add_custom_target(copy_resources ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_SOURCE_DIR}/resources
        ${PROJECT_BINARY_DIR}/resources
        COMMENT "Copying resources into binary directory")

add_dependencies("${PROJECT_NAME}" copy_resources)



target_link_libraries("${PROJECT_NAME}" PRIVATE CometEngine)
#target_link_libraries("${PROJECT_NAME}" PRIVATE glfw) 
#target_link_libraries("${PROJECT_NAME}" PRIVATE CometEngine-graphics) 


target_include_directories("${PROJECT_NAME}" PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/CometEngine/vendor/glad/include")
target_include_directories("${PROJECT_NAME}" PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/CometEngine/vendor/glfw-3.4/include")
target_include_directories("${PROJECT_NAME}" PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/CometEngine/vendor/glm/include")
target_include_directories("${PROJECT_NAME}" PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/CometEngine/vendor/stb/include")
