cmake_minimum_required(VERSION 3.10)

project(Server)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_options(-Wall -Wextra -Werror -g -IIncludes)

include_directories(${CMAKE_SOURCE_DIR}/Includes)

file(GLOB SOURCES "Sources/*.cpp" "main.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} ws2_32)