cmake_minimum_required(VERSION 3.3)

project(random)

add_library(random random.cpp)
add_executable(main main.cpp)
target_link_libraries(main random)