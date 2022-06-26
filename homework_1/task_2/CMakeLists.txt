cmake_minimum_required(VERSION 3.3)
project(task_2)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/results/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/results/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/results/bin)

add_executable(main src/main.cpp)
target_link_libraries(main PRIVATE ${CMAKE_SOURCE_DIR}/build/libipb_arithmetic.a)
target_include_directories(main PUBLIC ./include)
