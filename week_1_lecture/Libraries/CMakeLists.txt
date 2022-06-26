cmake_minimum_required(VERSION 3.3)

project(random)

set(CMAKE_CXX_STANDARD 17) # -std=c++17
set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_library(random random.cpp)
add_executable(main main.cpp)
target_link_libraries(main random)