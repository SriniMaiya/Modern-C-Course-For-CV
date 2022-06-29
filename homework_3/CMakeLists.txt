cmake_minimum_required(VERSION 3.3)
project(hw_3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "-Wall")

add_executable(main src/main.cpp)
include_directories(include api)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_library(image_browser SHARED src/image_browser.cpp)
add_library(html_writer SHARED src/html_writer.cpp)

target_link_libraries(main PRIVATE image_browser)
target_link_libraries(main PRIVATE html_writer)
