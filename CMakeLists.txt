cmake_minimum_required(VERSION 3.24)
project(ESGI_OpenGL_Second)

set(CMAKE_CXX_STANDARD 14)

add_executable(${PROJECT_NAME} src/main.cpp)

add_subdirectory(dependencies/glfw)

include_directories(dependencies/glad/include)
add_library(glad dependencies/glad/src/glad.c)

target_link_libraries(${PROJECT_NAME} glfw opengl32 glad)

add_compile_definitions(SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")