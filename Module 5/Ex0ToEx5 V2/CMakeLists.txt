cmake_minimum_required(VERSION 3.12)

project(Module5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -g")

include_directories(Includes)

file(GLOB SOURCES "Sources/*.cpp" "main.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})