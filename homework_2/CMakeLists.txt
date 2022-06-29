cmake_minimum_required(VERSION 3.3)
project(homework_2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/task_1/bin)
add_executable(task_1 task_1/task_1.cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/task_2/bin)
add_executable(task_2 task_2/task_2.cpp)
